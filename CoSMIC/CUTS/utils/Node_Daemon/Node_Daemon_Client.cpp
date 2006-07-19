// -*- C++ -*-

//=============================================================================
/**
 * @file        Node_Daemon_Client.cpp
 *
 * $Id*
 *
 * @author      James H. Hill
 */
//=============================================================================

#include "Node_DaemonC.h"
#include "ace/streams.h"
#include "ace/OS_NS_unistd.h"

//
// main
//
int main (int argc, char * argv [])
{
  try
  {
    // initalize the ORB
    cout << "initializing CORBA ORB..." << endl;
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

    // read and destringify the Time_Date object's IOR
    cout << "reading " << argv[1] << endl;
    ::CORBA::Object_var obj = orb->string_to_object (argv[1]);
    if (::CORBA::is_nil (obj.in ()))
    {
      cerr << "could not resolve node daemon IOR" << endl;
      return 1;
    }

    // narrow the IOR to a Game_Server object reference
    cout << "creating node daemon object..." << endl;
    ::CUTS::Node_Daemon_var daemon = ::CUTS::Node_Daemon::_narrow (obj.in ());

    if (::CORBA::is_nil (daemon.in ()))
    {
      cerr << "IOR was not a node daemon object reference" << endl;
      return 1;
    }

    ::CUTS::Node_Details nodes (2);
    nodes.length (2);

    nodes[0].params = ::CORBA::string_dup ("-s %CIAO_ROOT%/DAnCE/NodeApplication");
    nodes[0].binding.localhost = true;
    nodes[0].binding.port = 10000;

    nodes[1].params = ::CORBA::string_dup ("-s %CIAO_ROOT%/DAnCE/NodeApplication");
    nodes[1].binding.localhost = false;
    nodes[1].binding.port = 20000;

    long count = daemon->spawn (nodes);
    ACE_DEBUG ((LM_ERROR,
                "spawn %d node(s)\n",
                count));

    ACE_OS::sleep (5);

    CUTS::Node_Bindings bindings (1);
    bindings.length (1);
    bindings[0] = nodes[1].binding;

    count = daemon->kill (bindings);
    ACE_DEBUG ((LM_ERROR,
                "killed %d node(s)\n",
                count));

    // Destroy the ORB.
    cout << "destroying the ORB..." << endl;
    orb->destroy ();
    return 0;
  }
  catch (::CORBA::Exception & ex)
  {
    cerr << ex << std::endl;
    ACE_UNUSED_ARG (ex);
  }

  return 1;
}
