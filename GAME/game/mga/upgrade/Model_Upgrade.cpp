// $Id$

#include "stdafx.h"
#include "Model_Upgrade.h"
#include "game/mga/XML.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_unistd.h"
#include "ace/streams.h"

static const char * __HELP__ =
"A utility for upgrading GME models to their latest paradigm\n"
"\n"
"Usage: gme_upgrade [OPTIONS] XMEFILE\n"
"\n"
"Options:\n"
"  -o MGAFILE                   target mga file\n"
"\n"
"Output Options:\n"
"  -h, --help                   print this help screen\n";

//
// GME_Model_Upgrade
//
GME_Model_Upgrade::GME_Model_Upgrade (void)
{

}

//
// ~GME_Model_Upgrade
//
GME_Model_Upgrade::~GME_Model_Upgrade (void)
{

}

//
// run_main
//
int GME_Model_Upgrade::run_main (int argc, char * argv [])
{
  try
  {
    // Parse the command-line options.
    if (this->parse_args (argc, argv) == -1)
      return 1;

    // Import the XME file.
    filelist_t::CONST_ITERATOR iter (this->xme_files_);

    for ( ; !iter.done (); iter.advance ())
    {
      if (this->import_xme_file (*iter) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                          "%T (%t) - %M - failed to import %s\n",
                          (*iter).c_str ()),
                          1);

      // Export the project to a XME file.
      this->export_project_file (*iter);

      // Close the project.
      this->project_.close ();
    }

    return 0;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T - %M - %s\n"),
                ex.message ().c_str ()));
  }

  return 1;
}

//
// import_xme_file
//
int GME_Model_Upgrade::import_xme_file (const ACE_CString & xmefile)
{
  // First, lets go ahead and construct the MGA filename.
  ACE_CString mgafile ("MGA=");

  if (this->outfile_.empty ())
  {
    size_t pos = xmefile.find (".xme");

    if (pos != ACE_CString::npos)
      mgafile += xmefile.substr (0, pos);
    else
      mgafile += xmefile;

    mgafile += ".mga";
  }
  else
  {
    mgafile += this->outfile_;
  }

  // Get information about the XML file.
  GAME::Mga::XML_Parser parser;
  GAME::Mga::XML_Info info;
  parser.get_info (xmefile.c_str (), info);

  // Create a empty PICML project and import the XML file.
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("%T (%t) - %M - importing %s to %s\n"),
              xmefile.c_str (),
              mgafile.c_str ()));

  this->project_ = GAME::Mga::Project::_create (mgafile.c_str (), info.paradigm_);
  parser.parse (xmefile.c_str (), this->project_);

  return 0;
}

//
// export_project_file
//
int GME_Model_Upgrade::export_project_file (const ACE_CString & file)
{
  // Export the project to the source XML file.
  GAME::Mga::XML_Dumper dumper;
  dumper.write (file.c_str (), this->project_);

  return 0;
}

//
// parse_args
//
int GME_Model_Upgrade::parse_args (int argc, char * argv [])
{
  static const char * optargs = "ho:";

  // Initialize the argument options for the application.
  ACE_Get_Opt get_opt (argc, argv, optargs);
  get_opt.long_option ("help", 'h');

  char opt;

  while ((opt = get_opt ()) != EOF)
  {
    switch (opt)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "help") == 0)
        this->print_help ();
      break;

    case 'o':
      break;

    case 'h':
      this->print_help ();
      break;
    }
  }

  // The remaining arguments are the filenames.
  for (int i = get_opt.opt_ind (); i < get_opt.argc (); ++ i)
    this->xme_files_.insert (get_opt.argv ()[i]);

  return 0;
}

//
// print_help
//
void GME_Model_Upgrade::print_help (void)
{
  std::cerr << ::__HELP__ << std::endl;
  ACE_OS::exit (1);
}
