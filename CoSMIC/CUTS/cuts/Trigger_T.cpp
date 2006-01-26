// $Id$

#if !defined (__CUTS_INLINE__)
# include "cuts/Trigger_T.inl"
#endif

#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_time.h"

//=============================================================================
/*
 * CUTS_Trigger_T
 */
//=============================================================================

//
// CUTS_Trigger_T
//
template <typename COMPONENT>
CUTS_Trigger_T <COMPONENT>::CUTS_Trigger_T (COMPONENT * component,
                                            Method_Pointer method)
: active_ (false),
  component_ (component),
  method_ (method)
{
  // Create a new <ACE_Reactor> with a <ACE_TP_Reactor> implementation.
  ACE_TP_Reactor * tp_reactor = new ACE_TP_Reactor ();
  this->reactor (new ACE_Reactor (tp_reactor, 1));
}

//
// ~CUTS_Trigger_T
//
template <typename COMPONENT>
CUTS_Trigger_T <COMPONENT>::~CUTS_Trigger_T (void)
{
  delete this->reactor ();
  this->reactor (0);
}

//
// svc
//
template <typename COMPONENT>
int CUTS_Trigger_T <COMPONENT>::svc (void)
{
  // Set the owner thread to myself.
  this->reactor ()->owner (ACE_OS::thr_self ());

  // Handle all the events.
  while (this->active_)
    this->reactor ()->handle_events ();

  return 0;
}

//
// activate
//
template <typename COMPONENT>
bool CUTS_Trigger_T <COMPONENT>::activate (void)
{
  // Verify we have not already activated the trigger.
  if (!this->active_)
  {
    // Set the trigger to <active_> and start the task.
    this->active_ = true;

    if (ACE_Task_Base::activate () == -1)
      this->active_ = false;
  }

  return this->active_;
}

//
// deactivate
//
template <typename COMPONENT>
void CUTS_Trigger_T <COMPONENT>::deactivate (void)
{
  // Signal the task to stop processing events.
  this->active_ = false;
  this->reactor ()->notify (this);

  // Wait for all the threads to return.
  wait ();
}

//=============================================================================
/*
 * CUTS_Periodic_Trigger_T
 */
//=============================================================================

//
// CUTS_Periodic_Trigger_T
//
template <typename COMPONENT>
CUTS_Periodic_Trigger_T <COMPONENT>::CUTS_Periodic_Trigger_T (Component_Type * component,
                                                              Method_Pointer method,
                                                              long timeout,
                                                              double probability)
: Trigger_Type (component, method),
  timer_ (-1),
  timeout_ (timeout),
  probability_ (probability)
{
  ACE_OS::srand (ACE_OS::time (0));
}

//
// ~CUTS_Periodic_Trigger_T
//
template <typename COMPONENT>
CUTS_Periodic_Trigger_T <COMPONENT>::~CUTS_Periodic_Trigger_T (void)
{

}

//
// activate
//
template <typename COMPONENT>
bool CUTS_Periodic_Trigger_T <COMPONENT>::activate (void)
{
  if (this->timer_ == -1)
  {
    // Convert the timeout to a <ACE_Time_Value>
    ACE_Time_Value timeout;
    timeout.msec (this->timeout_);

    // Schedule the <timer_> with the <reactor_>.
    this->timer_ = this->reactor ()->schedule_timer (this, 0, timeout, timeout);
  }

  // Signal the <Trigger_Type> to activate itself.
  return this->timer_ != -1 ? Trigger_Type::activate () : false;
}

//
// deactivate
//
template <typename COMPONENT>
void CUTS_Periodic_Trigger_T <COMPONENT>::deactivate (void)
{
  // Remove the <timer_> if it exists.
  if (this->timer_ != -1)
  {
    this->reactor ()->cancel_timer (this->timer_);
    this->timer_ = -1;
  }

  // Pass control to the base class.
  Trigger_Type::deactivate ();
}

//
// handle_timeout
//
template <typename COMPONENT>
int CUTS_Periodic_Trigger_T <COMPONENT>::handle_timeout (const ACE_Time_Value &current_time, 
                                                         const void * act)
{
  // Calculate the score for this <timeout_> event.
  double score = (double) ACE_OS::rand () / (double) RAND_MAX;

  // invoke the method if the score is within the <probability_>
  if (score <= this->probability_)
  {
    return Trigger_Type::handle_timeout (current_time, act);
  }
  else
  {
    return 0;
  }
}
