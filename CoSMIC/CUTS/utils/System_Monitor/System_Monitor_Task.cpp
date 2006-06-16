// $Id: System_Monitor_Task.cpp,v 1.1.4.1 2006/03/12 01:48:06 hillj Exp $

#include "System_Monitor_Task.h"
#include "ace/Reactor.h"

namespace CUTS
{
  namespace CIDL_System_Monitor_Impl
  {
    //
    // System_Monitor_Task
    //
    System_Monitor_Task::System_Monitor_Task (bool & active)
      : active_ (active)
    {
      try
      {
        ACE_Reactor * reactor = new ACE_Reactor ();
        this->reactor (reactor);
      }
      catch (std::bad_alloc &)
      {

      }
    }

    //
    // ~System_Monitor_Task
    //
    System_Monitor_Task::~System_Monitor_Task (void)
    {

    }

    //
    // svc
    //
    int System_Monitor_Task::svc (void)
    {
      this->reactor ()->owner (ACE_OS::thr_self ());

      while (this->active_)
      {
        this->reactor ()->handle_events ();
      }

      return 0;
    }
  }
}
