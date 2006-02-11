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

  // Create the notification strategy.
  this->notify_strategy_.reset (
    new ACE_Reactor_Notification_Strategy (
    reactor, this, ACE_Event_Handler::READ_MASK));

  // Attach the notification strategy to the event queue.
  this->event_queue_.notification_strategy (
    this->notify_strategy_.get ());
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

  // Get the next dispatch time from the queue.
  long * dispatch_time;
  this->event_queue_.dequeue (dispatch_time);

  //cerr
  //  << "[receiver]: dispatch time = " << *dispatch_time
  //  << "; current time = " << curr_time.msec () << endl;

  ACE_Time_Value tmp_tv;
  tmp_tv.msec (*dispatch_time);

  // Create a new activation record.
  CUTS_Activation_Record * record =
    this->port_agent_->create_activation_record ();
  record->transit_time (curr_time - tmp_tv);

  // Invoke the method and give it a new activation record.
  record->activate ();
  (this->component_->*this->method_) (record);

  // Close the activation record.
  this->port_agent_->close_activation_record (record);

  // Destroy the allocated memory.
  delete dispatch_time;
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
  ACE_Task_Base::activate (THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED, 1);
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
