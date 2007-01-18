// $Id$

//
// get_next
//
template <typename EVENTTYPE>
CUTS_INLINE
CUTS_Cached_Async_Event_Handler_Queue_Node_T <EVENTTYPE> *
CUTS_Cached_Async_Event_Handler_Queue_Node_T <EVENTTYPE>::get_next (void) const
{
  return this->next_;
}

//
// set_next
//
template <typename EVENTTYPE>
CUTS_INLINE
void CUTS_Cached_Async_Event_Handler_Queue_Node_T <EVENTTYPE>::
set_next (CUTS_Cached_Async_Event_Handler_Queue_Node_T <EVENTTYPE> * next)
{
  this->next_ = next;
}

//
// CUTS_Async_Event_Handler_Queue_T
//
template <typename EVENTTYPE>
CUTS_INLINE
size_t CUTS_Async_Event_Handler_Queue_T <EVENTTYPE>::
current_size (void) const
{
  return this->event_queue_.message_count ();
}

//
// is_empty
//
template <typename EVENTTYPE>
CUTS_INLINE
int CUTS_Async_Event_Handler_Queue_T <EVENTTYPE>::
is_empty (void)
{
  return this->event_queue_.is_empty ();
}
