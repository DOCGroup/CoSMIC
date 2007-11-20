// -*- C++ -*-

//=============================================================================
/**
 * @file        client.cpp
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#include "Client_Options.h"
#include "cuts/BDC/Benchmark_Data_CollectorC.h"
#include "ace/Get_Opt.h"
#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"
#include <sstream>

/// macro definition for the CUTS_BDC_Client_Options singleton
#define CLIENT_OPTIONS() \
  ACE_Singleton <CUTS_BDC_Client_Options, \
                 ACE_Null_Mutex>::instance ()

#define VERBOSE_MESSAGE(msg) \
  if (CLIENT_OPTIONS ()->verbose_) \
  { \
    ACE_DEBUG (msg); \
  }

//
// parse_args
//
int parse_args (int argc, char * argv [])
{
  // Create an options
  const char * optstr = "l";
  ACE_Get_Opt get_opt (argc, argv, optstr);

  get_opt.long_option ("list", 'l', ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "list") == 0)
        CLIENT_OPTIONS ()->list_svcs_ = true;
      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
        CLIENT_OPTIONS ()->verbose_ = true;
      break;

    case 'l':
        CLIENT_OPTIONS ()->list_svcs_ = true;
        break;

    case '?':
      ACE_DEBUG ((LM_DEBUG,
                  "-%c is an unknown option; ignoring\n",
                  get_opt.opt_opt ()));
      break;

    case ':':
      ACE_ERROR_RETURN ((LM_ERROR,
                         "%c is missing an argument\n",
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
// main
//
int main (int argc, char * argv [])
{
  try
  {
    // Initialize the CORBA ORB.
    ::CORBA::ORB_var the_ORB = ::CORBA::ORB_init (argc, argv);

    if (parse_args (argc, argv) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "failed to parse arguments\n"),
                         1);
    }

    // Get the initial reference to the CUTS_BDC.
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "resolving initial reference to CUTS_BDC\n"));

    ::CORBA::Object_var obj = the_ORB->resolve_initial_references ("CUTS_BDC");

    if (::CORBA::is_nil (obj.in ()))
    {
      ACE_ERROR_RETURN ((
        LM_ERROR,
        "failed to resolve initial reference to CUTS_BDC\n"),
        1);
    }

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "extracting Benchmark_Data_Collector from reference\n"));

    // Extract the BDC object from the generic object.
    ::CUTS::Benchmark_Data_Collector_var the_BDC =
      ::CUTS::Benchmark_Data_Collector::_narrow (obj.in ());

    if (::CORBA::is_nil (the_BDC.in ()))
    {
      ACE_ERROR_RETURN ((
        LM_ERROR,
        "reference is not a CUTS::Benchmark_Data_Collector object\n"),
        1);
    }

    // We need to handle the arguments as necessary here.
    if (CLIENT_OPTIONS ()->list_svcs_)
    {
      // Get a handle to the controller for the BDC.
      CUTS::BDC_Control_Handle_var control = the_BDC->provide_controls ();

      // Get a listing of all the service names.
      CUTS::BDC_Service_Names_var svc_names;
      control->list_services (svc_names);

      size_t length = svc_names->length ();

      if (length > 0)
      {
        std::ostringstream ostr;

        for (size_t i = 0; i < length; i ++)
          ostr << svc_names[i].in () << " |";

        ACE_DEBUG ((LM_DEBUG,
                    "listing of loaded services:\n%s",
                    ostr.str ().c_str ()));
      }
      else
      {
        ACE_DEBUG ((LM_DEBUG,
                    "there are no services currently loaded\n"));
      }
    }

    return 0;
  }
  catch (const CORBA::Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "caught CORBA exception: %s\n",
                ex._info ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "caught unknown exception\n"));
  }

  return 1;
}
