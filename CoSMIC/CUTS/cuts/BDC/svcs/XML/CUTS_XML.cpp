// $Id$

#include "CUTS_XML.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "cuts/Testing_Service.h"
#include "cuts/Time.h"
#include "cuts/XML_Metrics_Writer.h"
#include "ace/Get_Opt.h"
#include <sstream>

CUTS_BDC_SERVICE_IMPL (CUTS_XML_Service);

// helper macro for verbose message
#define VERBOSE_MESSAGE(msg) \
  if (this->verbose_) \
  { \
    ACE_DEBUG (msg); \
  }

// helper macro for verbose message w/ return values
#define VERBOSE_MESSAGE_RETURN(msg, retval) \
  if (this->verbose_) \
  { \
    ACE_DEBUG_RETURN (msg, retval); \
  }

//
// CUTS_XML_Service
//
CUTS_XML_Service::CUTS_XML_Service (void)
: verbose_ (false)
{

}

//
// ~CUTS_XML_Service
//
CUTS_XML_Service::~CUTS_XML_Service (void)
{

}

//
// init
//
int CUTS_XML_Service::init (int argc, ACE_TCHAR * argv [])
{
  if (this->parse_args (argc, argv) == -1)
    return -1;

  if (!this->output_directory_.empty ())
  {
    // Make sure the output directory ends in a trailing slash.
    char lastchar =
      this->output_directory_[this->output_directory_.length () - 1];

    if (lastchar != '/' && lastchar != '\\')
      this->output_directory_ += '/';
  }

  return 0;
}

//
// fini
//
int CUTS_XML_Service::fini (void)
{
  return 0;
}

//
// parse_args
//
int CUTS_XML_Service::parse_args (int argc, ACE_TCHAR * argv [])
{
  const char * opts = "o:";

  ACE_Get_Opt get_opt (argc, argv, opts, 0);
  get_opt.long_option ("output-directory", 'o', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "output-directory") == 0)
      {
        this->output_directory_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
      {
        this->verbose_ = true;
      }
      else
      {
        ACE_DEBUG ((LM_DEBUG,
                    "--%s is an unknown option; ignoring\n",
                    get_opt.long_option ()));
      }
      break;

    case 'o':
      this->output_directory_ = get_opt.opt_arg ();
      break;

    case '?':
      ACE_DEBUG ((LM_DEBUG,
                  "-%c is an unknown option; ignoring\n",
                  get_opt.opt_opt ()));
      break;

    case ':':
      ACE_ERROR_RETURN ((LM_ERROR,
                         "-%c is missing an argument\n",
                         get_opt.opt_opt ()),
                         1);
      break;

    default:
      /* do nothing */;
    }
  }

  return 0;
}

//
// handle_component
//
int CUTS_XML_Service::
handle_metrics (const CUTS_System_Metric & metrics)
{
  std::ostringstream pathname;
  pathname
    << this->output_directory_.c_str ()
    << this->svc_mgr ()->get_uuid ().c_str () << '.'
    << CUTS_string_time (metrics.get_timestamp (), "%Y%m%d-%H%M%S")
    << ".xml";

  VERBOSE_MESSAGE ((LM_INFO,
                    "*** info (CUTS_XML_Service): writing metrics to %s\n",
                    pathname.str ().c_str ()));


  // Execute the XML generator on the metrics.
  CUTS_XML_Metrics_Writer
    writer (this->svc_mgr ()->testing_service ()->registry (),
    pathname.str ().c_str ());

  // Set the UUID of the writer then write the metrics to
  // an XML file.
  writer.set_uuid (this->svc_mgr ()->get_uuid ());
  metrics.accept (writer);

  return 0;
}
