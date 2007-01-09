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
  // Get the activation record for the thread and open
  // it for logging metrics at the application level.
  CUTS_Activation_Record * record = CUTS_THR_ACTIVATION_RECORD ();
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
  this->port_agent ().update (record);
  record->reset ();
}
