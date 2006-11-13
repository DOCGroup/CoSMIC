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
: context_ (0),
  owner_ (-1)
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
template <typename OBV_EVENTTYPE>
void CUTS_CCM_Event_Producer_T <CONTEXT>::
push_event (void (CONTEXT::*event_method)(typename OBV_EVENTTYPE::_ptr_type),
            ACE_Time_Value & toc)
{
  typename OBV_EVENTTYPE::_var_type event = new OBV_EVENTTYPE ();
  this->push_event_ex <OBV_EVENTTYPE> (event_method, event.in (), toc);
}

//
// push_event_ex
//
template <typename CONTEXT>
template <typename OBV_EVENTTYPE>
void CUTS_CCM_Event_Producer_T <CONTEXT>::
push_event_ex (void (CONTEXT::*event_method)(typename OBV_EVENTTYPE::_ptr_type),
               typename OBV_EVENTTYPE::_ptr_type event,
               ACE_Time_Value & toc)
{
  // Set the sender of the event and set the time of completion
  // for the publication for client.
  //event->sender (this->owner_);
  toc = ACE_OS::gettimeofday ();

  try
  {
    // ?? Should we remove these checks?? In the real system,
    // there would not be checks like this!!
    if (this->context_ == 0)
      ACE_DEBUG ((LM_ERROR, "context is NIL\n"));
    if (event_method == 0)
      ACE_DEBUG ((LM_DEBUG, "event_method is NIL\n"));

    (this->context_->*event_method) (event);
  }
  catch (const CORBA::Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - exception %s has occurred\n",
                ex._name ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception has occurred\n"));
  }
}
