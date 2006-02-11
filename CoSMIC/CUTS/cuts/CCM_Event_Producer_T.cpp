// $Id$

#include "ace/OS_NS_time.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/CCM_Event_Producer_T.inl"
#endif

#include "ace/Reactor.h"
#include "ace/TP_Reactor.h"
#include "ace/streams.h"

//
// CUTS_CCM_Event_Producer_T
//
template <typename CONTEXT>
CUTS_CCM_Event_Producer_T <CONTEXT>::CUTS_CCM_Event_Producer_T (void)
: context_ (0)
{

}

//
// ~CUTS_CCM_Event_Producer_T
//
template <typename CONTEXT>
CUTS_CCM_Event_Producer_T <CONTEXT>::~CUTS_CCM_Event_Producer_T (void)
{

}

//
// push_event
//
template <typename CONTEXT>
template <typename OBV_EVENTTYPE, typename EVENTTYPE>
void CUTS_CCM_Event_Producer_T <CONTEXT>::push_event (
  void (CONTEXT::*event_method)(EVENTTYPE *))
{
  // Create a new event
  OBV_EVENTTYPE::_var_type event = new OBV_EVENTTYPE ();

  // Initialize the buffer with garbage data.
  event->dispatch_time (ACE_OS::gettimeofday ().msec ());
  (this->context_->*event_method) (event.in ());
}

//
// push_data_event
//
template <typename CONTEXT>
template <typename OBV_EVENTTYPE, typename EVENTTYPE>
void CUTS_CCM_Event_Producer_T <CONTEXT>::push_data_event (
  size_t size,
  void (CONTEXT::*event_method)(EVENTTYPE *))
{
  // Create a new event
  OBV_EVENTTYPE::_var_type event = new OBV_EVENTTYPE ();

  // Allocate a buffer of that size and fill it with garbage.
  char value = 'A';
  char * buffer = CORBA::string_alloc (size);
  std::fill (buffer, buffer + size - 1, value);
  buffer[size - 1] = '\0';

  // Initialize the buffer with garbage data.
  event->data (buffer);
  event->dispatch_time (ACE_OS::gettimeofday ().msec ());
  (this->context_->*event_method) (event.in ());
}
