// $Id$

#include "stdafx.h"
#include "Automation_App.h"

#if !defined (__GAME_INLINE__)
#include "Automation_App.inl"
#endif

#include "Parameter_Parser.h"

#include "game/mga/XML.h"
#include "game/mga/ComponentEx.h"

#include "ace/ACE.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/streams.h"

#include "boost/bind.hpp"

#include <sstream>

static const char * __HELP__ =
"GME's automation modeling engine (GAME) application\n"
"\n"
"USAGE: game-automation [OPTIONS]\n"
"\n"
"General Options:\n"
"  -p, --project=FILE              use FILE for input\n"
"  -x, --interpreter=PROGID        program id of interpreter\n"
"\n"
"  --param=NAME=VALUE              set the value of a parameter\n"
"\n"
"  --disable-addons                disable GAME auto add-ons\n"
"  ---interative                   enable interactive behavior\n"
"\n"
"Informative Options:\n"
"  -h, --help                      print this help message\n"
"  -v, --verbose                   print verbose output\n"
"  --debug                         print debugging output\n";

//
// run_main
//
int GAME_Automation_App::run_main (int argc, char * argv [])
{
  if (this->parse_args (argc, argv) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - failed to parse command-line arguments\n")),
                       -1);

  try
  {
    // Open the project for writing.
    if (this->open_gme_project () != 0)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - failed to open GAME project [file=%s]\n"),
                         this->opts_.project_.c_str ()),
                         -1);

    if (!this->opts_.interpreter_.empty ())
      this->run (this->opts_.interpreter_);

    // Close the GAME project.
    this->save_gme_project ();
  }
  catch (const GAME::Mga::Failed_Result & ex)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught GAME exception [0x%X]\n"),
                ex.value ()));
  }
  catch (const GAME::Mga::Exception &)
  {

  }

  // Close the GAME project.
  this->project_.close ();

  return 0;
}

//
// parse_args
//
int GAME_Automation_App::parse_args (int argc, char * argv [])
{
  const char * optargs = "hp:x:";

  ACE_Get_Opt get_opt (argc, argv, optargs);

  get_opt.long_option ("help", 'h');
  get_opt.long_option ("project", 'p', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("interepter", 'x', ACE_Get_Opt::ARG_REQUIRED);

  get_opt.long_option ("param", ACE_Get_Opt::ARG_REQUIRED);

  get_opt.long_option ("disable-addons");
  get_opt.long_option ("interactive");

  char opt;

  while ((opt = get_opt ()) != EOF)
  {
    switch (opt)
    {
    case 0:
      if (ACE_OS::strcmp ("project", get_opt.long_option ()) == 0)
      {
        this->opts_.project_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp ("interpreter", get_opt.long_option ()) == 0)
      {
        this->opts_.interpreter_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp ("disable-addons", get_opt.long_option ()) == 0)
      {
        this->opts_.enable_auto_addons_ = false;
      }
      else if (ACE_OS::strcmp ("interactive", get_opt.long_option ()) == 0)
      {
        this->opts_.interactive_ = true;
      }
      else if (ACE_OS::strcmp ("param", get_opt.long_option ()) == 0)
      {
        Parameter_Parser p;
        p.parse (get_opt.opt_arg (), this->opts_.params_);
      }
      else if (ACE_OS::strcmp ("help", get_opt.long_option ()) == 0)
      {
        this->print_help ();
      }
      break;

    case 'h':
      this->print_help ();
      break;

    case 'p':
      this->opts_.project_ = get_opt.opt_arg ();
      break;

    case 'x':
      this->opts_.interpreter_ = get_opt.opt_arg ();
      break;
    }
  }

  return 0;
}

//
// print_help
//
void GAME_Automation_App::print_help (void)
{
  std::cerr << ::__HELP__ << std::endl;
  ACE_OS::exit (0);
}

//
// open_gme_project
//
int GAME_Automation_App::open_gme_project (void)
{
  // Determine if the project is a MGA file, or an XME file.
  this->is_mga_file_ = this->opts_.project_.rfind (".mga") != std::string::npos;

  if (this->is_mga_file_)
  {
    std::ostringstream connstr;
    connstr << "MGA=" << this->opts_.project_;

    ACE_DEBUG ((LM_INFO,
                ACE_TEXT ("%T (%t) - %M - opening %s for processing\n"),
                this->opts_.project_.c_str ()));

    this->project_ = GAME::Mga::Project::_open (connstr.str ());
  }
  else
  {
    // Get information about the XML file.
    GAME::Mga::XML_Parser parser;
    GAME::Mga::XML_Info info;

    parser.get_info (this->opts_.project_, info);

    ACE_TCHAR pathname[MAX_PATH];

    if (ACE::get_temp_dir (pathname, MAX_PATH - 20) != -1)
    {
      // Create a temporary filename for the project.
      ACE_OS::strcat (pathname, "game-XXXXXX.mga");
      ACE_HANDLE fd = ACE_OS::mkstemp (pathname);

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - creating temporary file '%s'\n"),
                  pathname));

      if (fd == 0)
        return -1;

      // Delete the temporary file, which we aren't using.
      ACE_OS::close (fd);
      ACE_OS::unlink (pathname);

      // Create the full pathname.
      std::ostringstream connstr;
      connstr << "MGA=" << pathname;

      // Create a empty PICML project and import the XML file.
      ACE_DEBUG ((LM_INFO,
                  ACE_TEXT ("%T (%t) - %M - importing '%s' for processing\n"),
                  this->opts_.project_.c_str ()));

      this->project_ = GAME::Mga::Project::_create (connstr.str (), info.paradigm_);
      parser.parse (this->opts_.project_, this->project_);
    }
    else
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - failed to open temp file [%m]\n")),
                         -1);
  }

  // Make sure we have the add-ons enabled. Otherwise, the
  // project may enter an inconsistent state.
  this->project_.enable_auto_addons (this->opts_.enable_auto_addons_);

  return 0;
}

//
// save_gme_project
//
int GAME_Automation_App::save_gme_project (void)
{
  if (this->is_mga_file_)
  {
    this->project_.save ();
  }
  else
  {
    // Save the temporary filename for the .mga file.
    std::string tempfile = this->project_.connstr ().substr (4);

    ACE_DEBUG ((LM_INFO,
                ACE_TEXT ("%T (%t) - %M - exporting project as %s\n"),
                this->opts_.project_.c_str (),
                tempfile.c_str ()));

    // Export the project to the source XML file.
    GAME::Mga::XML_Dumper dumper;
    dumper.write (this->opts_.project_, this->project_);

    ACE_OS::unlink (tempfile.c_str ());
  }

  return 0;
}

//
// run
//
int GAME_Automation_App::run (const std::string & progid)
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("%T (%t) - %M - running the interpreter %s\n"),
              progid.c_str ()));

  // Load the specified interpreter.
  GAME::Mga::ComponentEx interpreter = GAME::Mga::ComponentEx_Impl::_load (progid);

  // Set the interactive state.
  interpreter->interactive (this->opts_.interactive_);

  // Pass the parameters to the interpreter.
  typedef GAME_Automation_App_Options::param_t param_t;

  param_t::const_iterator
    iter = this->opts_.params_.begin (),
    iter_end = this->opts_.params_.end ();

  for (; iter != iter_end; ++ iter)
    interpreter->parameter (iter->first, iter->second );

  GAME::Mga::FCO focus;
  std::vector <GAME::Mga::FCO> selected;

  // Initialize the interpreter and then invoke it.
  interpreter->initialize (this->project_);
  interpreter->invoke (this->project_,
                       focus.get (),
                       selected,
                       0);

  return 0;
}
