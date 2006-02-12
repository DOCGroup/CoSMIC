// $Id$

#include "cuts/EventHandler_T.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/EventHandler_T.inl"
#endif

#include "ace/TP_Reactor.h"
#include <iostream>

static const int DEFAULT_THREAD_COUNT = 2;

template <typename COMPONENT>
CUTS_Event_Handler_T <COMPONENT>::CUTS_Event_Handler_T (
  Component_Type * component)
: component_ (component),
  method_ (0),
  port_agent_ (0)
{
  // Create a new <ACE_Reactor> for the <ACE_Task_Base>.
  ACE_Reactor * reactor = new ACE_Reactor (new ACE_TP_Reactor (), 1);
  this->reactor (reactor);
}

template <typename COMPONENT>
CUTS_Event_Handler_T <COMPONENT>::~CUTS_Event_Handler_T (void)
{

}

template <typename COMPONENT>
int CUTS_Event_Handler_T <COMPONENT>::handle_input (ACE_HANDLE handle)
{
  // Get the current time of day.
  ACE_Time_Value curr_time = ACE_OS::gettimeofday ();

  long dispatch_time;

  do
  {
    // Get the next dispatch time from the queue.
    ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->event_queue_lock_, 0)
    this->event_queue_.dequeue_head (dispatch_time);
  } while (false);

  ACE_Time_Value tmp_tv;
  tmp_tv.msec (dispatch_time);

  // Create a new activation record.
  CUTS_Activation_Record * record =
    this->port_agent_->create_activation_record ();

  // Set the transit time and activate the record.
  record->transit_time (curr_time - tmp_tv);
  record->activate ();

  // Invoke the method and give it a new activation record.
  (this->component_->*this->method_) (record);

  // Close the activation record.
  this->port_agent_->close_activation_record (record);

  return 0;
}

template <typename COMPONENT>
int CUTS_Event_Handler_T <COMPONENT>::svc (void)
{
  // If this is the <ACE_TP_Reactor> implemenation then the following
  // operation is a <no-op>. Otherwise, the owner of the <reactor_> is
  // set to the current thread.
  this->reactor ()->owner (ACE_OS::thr_self ());

  // Continue handling events while we are <active_>.
  while (this->active_)
  {
    this->reactor ()->handle_events ();
  }
  return 0;
}

//
// activate
//
template <typename COMPONENT>
void CUTS_Event_Handler_T <COMPONENT>::activate (void)
{
  // Set our state to active.
  this->active_ = true;

  // Right now we are only initializing the <reactor_> of the task
  // with one thread. In the future, you will be able to specify how
  // many threads of execution are available to the event handler.
  ACE_Task_Base::activate (
    THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED,
    DEFAULT_THREAD_COUNT);
}

//
// deactivate
//
template <typename COMPONENT>
void CUTS_Event_Handler_T <COMPONENT>::deactivate (void)
{
  // Set state to not <active_>.
  this->active_ = false;

  // Wait for all the threads of execution to return.
  this->wait ();
}

//
// handle_event
//
template <typename COMPONENT>
void CUTS_Event_Handler_T <COMPONENT>::handle_event (long dispatch_time)
{
  if (this->active_)
  {
    do
    {
      ACE_GUARD (ACE_Thread_Mutex, guard, this->event_queue_lock_);
      this->event_queue_.enqueue_tail (dispatch_time);
    } while (false);

    // Notify the reactor. This will call the handle_input () method
    // to be invoked. In the future, this notify will cause the
    // handle_timeout () method to be invoked. Doing so will allow
    // us to calculate the "queue" time for the event since
    // handle_timeout () passes along the time value when it was
    // signaled for execution, not invoked by the middleware!!
    this->reactor ()->notify (this, ACE_Event_Handler::READ_MASK);
  }
}
