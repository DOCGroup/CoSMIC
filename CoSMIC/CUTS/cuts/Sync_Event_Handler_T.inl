// $Id: Sync_Event_Handler_T.inl,v 1.1.2.1 2006/05/23 22:04:19 hillj Exp $

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
