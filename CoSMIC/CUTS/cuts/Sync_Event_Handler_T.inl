// $Id$

//
// handle_event
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Sync_Event_Handler_T <COMPONENT, EVENTTYPE>::
handle_event (EVENTTYPE * ev)
{
  this->handle_event_i (ev, ACE_Time_Value::zero);
}
