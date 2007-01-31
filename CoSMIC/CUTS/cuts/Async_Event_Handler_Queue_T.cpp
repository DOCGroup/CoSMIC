// $Id$

#if !defined (__CUTS_INLINE__)
#include "Async_Event_Handler_Queue_T.inl"
#endif

//
// CUTS_Async_Event_Handler_Queue_T
//
template <typename EVENTTYPE>
CUTS_Async_Event_Handler_Queue_T <EVENTTYPE>::
CUTS_Async_Event_Handler_Queue_T (void)
: free_list_ (CUTS_DEFAULT_EVENT_COUNT)
{

}

//
// CUTS_Async_Event_Handler_Queue_T
//
template <typename EVENTTYPE>
CUTS_Async_Event_Handler_Queue_T <EVENTTYPE>::
~CUTS_Async_Event_Handler_Queue_T (void)
{

}

//
// enqueue
//
template <typename EVENTTYPE>
int CUTS_Async_Event_Handler_Queue_T <EVENTTYPE>::
enqueue (EVENTTYPE * event)
{
  // Get a node from the free list.
  _cache_type * node = this->free_list_.remove ();

  if (node != 0)
  {
    // Store the event into the node.
    node->event_ = event;
    node->toc_   = ACE_OS::gettimeofday ();

    // Insert the node the event queue.
    return this->event_queue_.enqueue (node);
  }
  else
    return -1;
}

//
// dequeue
//
template <typename EVENTTYPE>
int CUTS_Async_Event_Handler_Queue_T <EVENTTYPE>::
dequeue (EVENTTYPE * & event, ACE_Time_Value * toc)
{
  // Get a node from the free list.
  _node_type * node = 0;
  int retval = this->event_queue_.dequeue (node);

  if (retval != -1)
  {
    // Return the information to the client.
    event = node->event_;

    if (toc != 0)
      *toc = node->toc_;

    // Place the node back on the free list.
    this->free_list_.add (static_cast <_cache_type *> (node));
  }

  return retval;
}
