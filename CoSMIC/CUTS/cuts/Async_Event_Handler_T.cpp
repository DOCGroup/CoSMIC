// $Id$

#include "ace/Thread_Manager.h"

//
// CUTS_Event_Handler_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE>::
CUTS_Async_Event_Handler_T (void)
: grp_id_ (-1)
{

}

//
// ~CUTS_Event_Handler_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE>::
~CUTS_Async_Event_Handler_T (void)
{

}

//
// event_loop
//
template <typename COMPONENT, typename EVENTTYPE>
ACE_THR_FUNC_RETURN
CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE>::event_loop (void * param)
{
  THIS * _this = reinterpret_cast <THIS *> (param);

  while (_this->is_active ())
  {
    EVENTTYPE * event = 0;

    if (_this->event_queue_.dequeue_head (event) != -1)
    {
      // Calculate the amount of time the event was in the queue.
      ACE_Time_Value enqueue_time;
      enqueue_time.msec (event->dispatch_time ());

      ACE_Time_Value queue_time = ACE_OS::gettimeofday ();
      queue_time -= enqueue_time;

      // Pass control to the shared implementation. When the call
      // returns we need to release the <ev> object.
      _this->handle_event_i (event, queue_time);
      ::CORBA::remove_ref (event);
    }
  }
  return 0;
}

//
// activate
//
template <typename COMPONENT, typename EVENTTYPE>
void CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE>::activate (void)
{
  // Perform all the one-time operations that should be called
  // the first time the <activate> method is invoked.
  if (!this->is_active ())
  {
    Event_Handler_Base::activate ();
    this->event_queue_.activate ();
  }

  // Either we are creating the first thread of the event handler,
  // or we are spawning a new thread for the event handler.
  if (this->grp_id_ == -1)
  {
    this->grp_id_ =
      ACE_Thread_Manager::instance ()->spawn (&THIS::event_loop, this);
  }
  else
  {
    ACE_Thread_Manager::instance ()->spawn (
      &THIS::event_loop,
      this,
      THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED,
      0,
      0,
      ACE_DEFAULT_THREAD_PRIORITY,
      this->grp_id_);
  }
}

//
// deactivate
//
template <typename COMPONENT, typename EVENTTYPE>
void CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE>::deactivate (void)
{
  if (this->is_active ())
  {
    Event_Handler_Base::deactivate ();

    // Gracefully empty the <event_queue_> and releasing all the
    // references to the CORBA events.
    if (!this->event_queue_.is_empty ())
    {
      EVENTTYPE * ev = 0;

      while (this->event_queue_.dequeue_head (ev) > 0)
      {
        ::CORBA::remove_ref (ev);
      }
    }

    this->event_queue_.deactivate ();

    // Wait for the <grp_id> to exit all its threads.
    ACE_Thread_Manager::instance ()->wait_grp (this->grp_id_);
    this->grp_id_ = -1;
  }
}

//
// handle_event
//
template <typename COMPONENT, typename EVENTTYPE>
void CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE>::handle_event (
  EVENTTYPE * ev)
{
  if (this->is_active ())
  {
    /// @note We are discarding the transit time and using the queuing
    /// time as the transit time. Until we have a better solution for
    /// handling transit times, we are discarding it.
    ev->dispatch_time (ACE_OS::gettimeofday ().msec ());

    ::CORBA::add_ref (ev);
    this->event_queue_.enqueue_tail (ev);
  }
}
