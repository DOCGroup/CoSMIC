// $Id$

#if !defined (__CUTS_INLINE__)
#include "cuts/Event_Handler_T.inl"
#endif

#include "cuts/Thread_Activation_Record.h"

//
// CUTS_Event_Handler_Config_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Event_Handler_Config_T <COMPONENT, EVENTTYPE>::
CUTS_Event_Handler_Config_T (void)
: component_ (0),
  method_ (0)
{

}

//
// CUTS_Event_Handler_Base_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::
CUTS_Event_Handler_Base_T (Config_Type & config)
: config_ (config)
{
  this->port_agent ().activate ();
}

//
// ~CUTS_Event_Handler_Base_T
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::
~CUTS_Event_Handler_Base_T (void)
{
  this->port_agent ().deactivate ();
}

//
// handle_event_i
//
template <typename COMPONENT, typename EVENTTYPE>
void
CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::
handle_event_i (EVENTTYPE * ev,
                const ACE_Time_Value & queue_time)
{
  // Get a new record and assign it to this thread.
  CUTS_Activation_Record * record = this->port_agent ().record_alloc ();

  CUTS_Activation_Record * old_record =
    CUTS_Thread_Activation_Record::set_record (record);

  // Open the record.
  record->open ();

  // Make an upcall to the callback
  if (!this->config_.dispatch_event (ev))
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - failed to dispatch an event\n"));
  }

  // Close the record and store it's queueing time as well.
  record->close ();
  record->queue_time (queue_time);

  // We should now update the port agent.
  CUTS_Thread_Activation_Record::set_record (old_record);
  this->port_agent ().record_free (record);
}

//=============================================================================
// @@ CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Empty_Event>

//
// CUTS_Event_Handler_Base_T
//
template <typename COMPONENT>
CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Empty_Event>::
CUTS_Event_Handler_Base_T (Config_Type & config)
: config_ (config)
{
  this->port_agent ().activate ();
}

//
// ~CUTS_Event_Handler_Base_T
//
template <typename COMPONENT>
CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Empty_Event>::
~CUTS_Event_Handler_Base_T (void)
{
  this->port_agent ().deactivate ();
}

//
// handle_event_i
//
template <typename COMPONENT>
void CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Empty_Event>::
handle_event_i (::CUTS::Empty_Event * ev, const ACE_Time_Value & queue_time)
{
  // Get a new record and assign it to this thread.
  CUTS_Activation_Record * record = this->port_agent ().record_alloc ();

  CUTS_Activation_Record * old_record =
    CUTS_Thread_Activation_Record::set_record (record);

  // Open the record.
  record->open (ev->sender ());

  // Make an upcall to the callback
  if (!this->config_.dispatch_event (ev))
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - failed to dispatch an event\n"));
  }

  // Close the record and store it's queueing time as well.
  record->close ();
  record->queue_time (queue_time);

  // We should now update the port agent.
  CUTS_Thread_Activation_Record::set_record (old_record);
  this->port_agent ().record_free (record);
}

//=============================================================================
// @@ CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Payload_Event>

//
// CUTS_Event_Handler_Base_T
//
template <typename COMPONENT>
CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Payload_Event>::
CUTS_Event_Handler_Base_T (Config_Type & config)
: config_ (config)
{
  this->port_agent ().activate ();
}

//
// ~CUTS_Event_Handler_Base_T
//
template <typename COMPONENT>
CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Payload_Event>::
~CUTS_Event_Handler_Base_T (void)
{
  this->port_agent ().deactivate ();
}

//
// handle_event_i
//
template <typename COMPONENT>
void CUTS_Event_Handler_Base_T <COMPONENT, ::CUTS::Payload_Event>::
handle_event_i (::CUTS::Payload_Event * ev, const ACE_Time_Value & queue_time)
{
  // Get a new record and assign it to this thread.
  CUTS_Activation_Record * record = this->port_agent ().record_alloc ();

  CUTS_Activation_Record * old_record =
    CUTS_Thread_Activation_Record::set_record (record);

  // Open the record.
  record->open (ev->sender ());

  // Make an upcall to the callback
  if (!this->config_.dispatch_event (ev))
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - failed to dispatch an event\n"));
  }

  // Close the record and store it's queueing time as well.
  record->close ();
  record->queue_time (queue_time);

  // We should now update the port agent.
  CUTS_Thread_Activation_Record::set_record (old_record);
  this->port_agent ().record_free (record);
}
