// $Id$

#include "Model_Upgrade.h"
#include "game/XML.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_unistd.h"
#include "ace/streams.h"

static const char * __HELP__ =
"A utility for upgrading GME models to their latest paradigm\n"
"\n"
"Usage: gme-upgrade [OPTIONS]\n"
"\n"
"General Options:\n"
"  -f, --file=XMEFILE           XMLFILE to upgrade\n"
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
  ACE_OS::unlink (this->tempfile_);
}

//
// run_main
//
int GME_Model_Upgrade::run_main (int argc, char * argv [])
{
  // Parse the command-line options.
  if (this->parse_args (argc, argv) == -1)
    return 1;

  // Import the XME file.
  if (this->import_xme_file () == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%T (%t) - %M - failed to import %s\n",
                       this->xme_file_.c_str ()),
                       1);

  // Export the project to a XME file.
  this->export_project_file ();
  return 0;
}

//
// import_xme_file
//
int GME_Model_Upgrade::import_xme_file (void)
{
  // Get information about the XML file.
  GME::XML_Parser parser;
  GME::XML_Info info;

  parser.get_info (this->xme_file_.c_str (), info);

  if (ACE::get_temp_dir (this->tempfile_, MAX_PATH - 20) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                        "%T (%t) - %M - failed to get temp directory\n"),
                        -1);

  // Create a temporary filename for the project.
  ACE_OS::strcat (this->tempfile_, "gme-XXXXXX.mga");
  ACE_HANDLE fd = ACE_OS::mkstemp (this->tempfile_);

  if (fd == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                        "%T (%t) - %M - failed to create temp file %s\n",
                        this->tempfile_),
                        -1);

  // Delete the temporary file, which we aren't using.
  ACE_OS::close (fd);
  ACE_OS::unlink (this->tempfile_);

  // Create the full pathname.
  ACE_CString connstr ("MGA=");
  connstr += this->tempfile_;

  // Create a empty PICML project and import the XML file.
  this->project_.create (connstr.c_str (), info.paradigm_);
  parser.parse (this->xme_file_.c_str (), this->project_);

  return 0;
}

//
// export_project_file
//
int GME_Model_Upgrade::export_project_file (void)
{
  // Export the project to the source XML file.
  GME::XML_Dumper dumper;
  dumper.write (this->xme_file_.c_str (), this->project_);

  return 0;
}

//
// parse_args
//
int GME_Model_Upgrade::parse_args (int argc, char * argv [])
{
  static const char * optargs = "f:h";

  // Initialize the argument options for the application.
  ACE_Get_Opt get_opt (argc, argv, optargs);
  get_opt.long_option ("file", 'f', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("help", 'h');

  char opt;

  while ((opt = get_opt ()) != EOF)
  {
    switch (opt)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "file") == 0)
        this->xme_file_ = get_opt.opt_arg ();
      else if (ACE_OS::strcmp (get_opt.long_option (), "help") == 0)
        this->print_help ();
      break;

    case 'f':
      this->xme_file_ = get_opt.opt_arg ();
      break;

    case 'h':
      this->print_help ();
      break;
    }
  }

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
