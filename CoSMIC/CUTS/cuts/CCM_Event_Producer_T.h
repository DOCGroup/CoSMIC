// -*- C++ -*-

//=============================================================================
/**
 * @file     CCM_Event_Producer_T.h
 *
 * $Id$
 *
 * [insert description here]
 *
 * @author    James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_CCM_EVENT_PRODUCER_T_H_
#define _CUTS_CCM_EVENT_PRODUCER_T_H_

#include "cuts/config.h"

//=============================================================================
/**
 * @class CUTS_CCM_Event_Producer_T
 */
//=============================================================================

template <typename CONTEXT>
class CUTS_CCM_Event_Producer_T
{
public:
  /// The type definition for the context.
  typedef CONTEXT Context;

  template <typename EVENTTYPE>
  struct Push_Event_Ex
  {
    typedef void (CONTEXT::*Event_Method) (EVENTTYPE *);

    Push_Event_Ex (CUTS_CCM_Event_Producer_T & producer,
                   Event_Method event_method,
                   EVENTTYPE * event)
    : producer_ (producer),
      event_method_ (event_method),
      event_ (event)
    {

    }

    void operator () (ACE_Time_Value & toc) const
    {
      this->producer_.push_event_ex (this->event_method_,
                                     this->event_,
                                     toc);
    }

  protected:
    /// The producer responsible for pushing the event.
    mutable CUTS_CCM_Event_Producer_T & producer_;

    /// The method used to push the event.
    Event_Method event_method_;

    /// Pointer the the contained event.
    EVENTTYPE * event_;
 };

  //===========================================================================
  /**
   * @struct Push_Event
   */
  //===========================================================================

  template <typename OBV_EVENTTYPE, typename EVENTTYPE>
  struct Push_Event
  {
    typedef void (CONTEXT::*Event_Method) (EVENTTYPE *);

    /**
     * @brief   Constructor.
     *
     * @param[in]   producer      Reference to the event producer.
     * @param[in]   push_method   Target method in the producer's context.
     */
    Push_Event (CUTS_CCM_Event_Producer_T & producer,
                Event_Method event_method)
    : producer_ (producer),
      event_method_ (event_method)
    {

    }

    /**
     * @brief   Functor operator.
     *
     * This method calls the appropriate member function for the
     * event producer passed into the constructor. More specifically,
     * this functor calls the CUTS_CCM_Event_Producer_T::push_event
     * method.
     */
    void operator () (ACE_Time_Value & toc) const
    {
      this->producer_.push_event <
        OBV_EVENTTYPE, EVENTTYPE> (this->event_method_, toc);
    }

  protected:
    /// The producer responsible for pushing the event.
    mutable CUTS_CCM_Event_Producer_T & producer_;

    /// The method used to push the event.
    Event_Method event_method_;
  };

  //===========================================================================
  /**
   * @struct Push_Data_Event
   */
  //===========================================================================

  template <typename OBV_EVENTTYPE, typename EVENTTYPE>
  struct Push_Data_Event :
    public Push_Event <OBV_EVENTTYPE, EVENTTYPE>
  {
    typedef void (CONTEXT::*Event_Method) (EVENTTYPE *);

    /// Constructor.
    Push_Data_Event (CUTS_CCM_Event_Producer_T & producer,
                     size_t size,
                     Event_Method event_method)
    : Push_Event <OBV_EVENTTYPE, EVENTTYPE> (producer, event_method),
      size_ (size)
    {

    }

    /// Functor.
    void operator () (ACE_Time_Value & toc) const
    {
      this->producer_.push_data_event <
        OBV_EVENTTYPE, EVENTTYPE>
        (this->size_, this->event_method_, toc);
    }

  private:
    /// The size of the event.
    size_t size_;
  };

  /// Constructor.
  CUTS_CCM_Event_Producer_T (void);

  /// Destructor.
  ~CUTS_CCM_Event_Producer_T (void);

  /// Set the contecxt for the producer.
  void context (CONTEXT * context);

  /// Push an event using the stored context.
  template <typename OBV_EVENTTYPE, typename EVENTTYPE>
  void push_event (void (CONTEXT::*event_type) (EVENTTYPE *),
                   ACE_Time_Value & toc);

  /// Push an event using the stored context.
  template <typename EVENTTYPE>
  void push_event_ex (void (CONTEXT::*event_type) (EVENTTYPE *),
                      EVENTTYPE * event,
                      ACE_Time_Value & toc);

  /// Push a data event using the stored context.
  template <typename OBV_EVENTTYPE, typename EVENTTYPE>
  void push_data_event (size_t size,
                        void (CONTEXT::*event_type) (EVENTTYPE *),
                        ACE_Time_Value & toc);

  void activate (long owner);

  void deactivate (void);

private:
  /// The context used to produce the events.
  CONTEXT * context_;

  /// Owner of the event producer.
  long owner_;

  /// Active state of the event producer.
  bool active_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_Event_Producer_T.inl"
#endif

#include "cuts/CCM_Event_Producer_T.cpp"

#endif  // !defined _CUTS_CCM_EVENT_PRODUCER_T_H_
