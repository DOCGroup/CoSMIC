// -*- C++ -*-

//=============================================================================
/**
 * @file        Node_Daemon_Client.cpp
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#include "Node_DaemonC.h"
#include "Client_Options.h"
#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_unistd.h"

//
// parse_args
//
int parse_args (int argc, char * argv[])
{
  // Setup the <ACE_Get_Opt> variable.
  const char * opts = "f:hln:p:v";
  ACE_Get_Opt get_opt (argc, argv, opts);

  // Setup the long options for the command-line
  get_opt.long_option ("help", 'h', ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("localhost", 'l', ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("port", 'p', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("spawn", 'n', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("shutdown", ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("verbose", 'v', ACE_Get_Opt::NO_ARG);

  int option;
  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case '0':
      break;

    case 'h':
      // we need to display the help then exit
      ACE_OS::exit (0);
      break;

    case 'v':
      CLIENT_OPTIONS ()->verbose_ = true ;
      break;

    case '?':
      // unknown option; do nothing
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
    // initalize the ORB
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

    if (parse_args (argc, argv) != 0)
      return 1;

    // Resolve the initiale reference to the Node_Daemon
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "resolving initial reference to Node_Daemon\n"));
    ::CORBA::Object_var obj =
      orb->resolve_initial_references ("Node_Daemon");

    if (::CORBA::is_nil (obj.in ()))
    {
      ACE_ERROR_RETURN ((
        LM_ERROR,
        "failed to resolved initial reference to Node_Daemon\n"),
        1);
    }

    // Narrow the generic object to a CUTS/Node_Daemon object.
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "extracting node daemon from object reference\n"));

    ::CUTS::Node_Daemon_var daemon =
      ::CUTS::Node_Daemon::_narrow (obj.in ());

    if (::CORBA::is_nil (daemon.in ()))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "object was not a Node_Daemon\n"),
                         1);
    }

    // Destroy the ORB.
    VERBOSE_MESSAGE ((LM_DEBUG, "destroying the ORB\n"));
    orb->destroy ();
    return 0;
  }
  catch (::CORBA::Exception & ex)
  {
    ACE_PRINT_TAO_EXCEPTION (ex, "caught exception");
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR, "caught unknown exception\n"));
  }

  return 1;
}
