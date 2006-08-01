// $Id$

#include "cuts/EventHandler_T.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/EventHandler_T.inl"
#endif

#include "cuts/Async_Event_Handler_T.h"
#include "cuts/Sync_Event_Handler_T.h"

//=============================================================================
/*
 * CUTS_Event_Handler_Base_T
 */
//=============================================================================

//
// CUTS_Event_Handler_Base_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::
CUTS_Event_Handler_Base_T (CUTS_Port_Agent & agent)
: component_ (0),
  method_ (0),
  active_ (false),
  port_agent_ (agent)
{

}

//
// ~CUTS_Event_Handler_Base_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::
~CUTS_Event_Handler_Base_T (void)
{
  this->deactivate ();
}

//
// handle_event_i
//
template <typename COMPONENT, typename EVENTTYPE>
void CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::handle_event_i (
  EVENTTYPE * ev,
  const ACE_Time_Value & queue_time)
{
  // Create a new activation record.
  CUTS_Activation_Record * record =
    this->port_agent_.create_activation_record ();

  // Make an upcall to the callback and pass it a record for
  // logging its performance.
  record->activate (ev->sender ());
  (this->component_->*this->method_) (ev, record);
  record->close ();

  // Store the <queueing_time> for the event in the record.
  record->transit_time (queue_time);

  // Close the activation record.
  this->port_agent_.destroy_activation_record (record);
}

//=============================================================================
/*
 * CUTS_Event_Handler_T
 */
//=============================================================================

//
// CUTS_Event_Handler_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::CUTS_Event_Handler_T (
  CUTS_Event_Handler::Event_Mode mode)
: mode_ (CUTS_Event_Handler::UNDEFINED)
{
  this->mode (mode);
}

//
// ~CUTS_Event_Handler_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::~CUTS_Event_Handler_T (void)
{

}

//
// mode
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::mode (
  CUTS_Event_Handler::Event_Mode mode)
{
  if (this->mode_ == mode || mode == CUTS_Event_Handler::UNDEFINED)
    return;

  CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE> * impl = 0;

  switch (mode)
  {
  case CUTS_Event_Handler::SYNCHRONOUS:
    // Set the implemenation to synchronous mode.
    typedef CUTS_Sync_Event_Handler_T <
      COMPONENT, EVENTTYPE> CUTS_Sync_Event_Handler;

    ACE_NEW (impl, CUTS_Sync_Event_Handler (this->port_agent_));
    break;

  case CUTS_Event_Handler::ASYNCHRONOUS:
    // Set the implemenation to asynchronous mode.
    typedef CUTS_Async_Event_Handler_T <
      COMPONENT, EVENTTYPE> CUTS_Async_Event_Handler;

    ACE_NEW (impl, CUTS_Async_Event_Handler (this->port_agent_));
    break;
  }

  if (impl != 0)
  {
    // Copy over the information from the old event handler
    // to the new event handler.
    if (this->impl_.get () != 0)
    {
      impl->bind (this->impl_->name (),
                  this->impl_->owner (),
                  this->impl_->method ());
    }

    // Save the new event handler as the <impl_>.
    this->impl_.reset (impl);
    this->mode_ = mode;
  }
}
