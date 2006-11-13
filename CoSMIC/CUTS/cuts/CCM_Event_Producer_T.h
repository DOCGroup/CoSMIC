// -*- C++ -*-

//=============================================================================
/**
 * @file      CCM_Event_Producer_T.h
 *
 * $Id$
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
 *
 * Generic implementation of an event producer for CCM components. This
 * object is parameterized with the context of the CCM component. Doing
 * so allows the component to send events using the components context.
 */
//=============================================================================

template <typename CONTEXT>
class CUTS_CCM_Event_Producer_T
{
public:
  /// The type definition for the context.
  typedef CONTEXT Context;

  //===========================================================================
  /**
   * @class Push_Event_Ex
   *
   * Functor for pushing an event over a context.
   */
  //===========================================================================

  template <typename OBV_EVENTTYPE>
  class Push_Event_Ex
  {
  public:
    /// Type definition of the event method.
    typedef typename OBV_EVENTTYPE::_ptr_type _ptr_type;

    typedef void (CONTEXT::*Event_Method) (_ptr_type);

    /**
     * Constructor.
     *
     * @param[in]     producer        Reference to an event producer.
     * @param[in]     event_method    Target method for the event.
     * @param[in]     event           Event to send via \a event_method.
     */
    inline
    Push_Event_Ex (CUTS_CCM_Event_Producer_T & producer,
                   Event_Method event_method,
                   _ptr_type event)
    : producer_ (producer),
      event_method_ (event_method),
      event_ (event)
    {

    }

    /**
     * Functor.
     *
     * @param[out]      toc     Time of completion.
     */
    inline
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
    _ptr_type event_;
 };

  //===========================================================================
  /**
   * @class Push_Event
   *
   * Functor for pushing an event over a context.
   */
  //===========================================================================

  template <typename OBV_EVENTTYPE>
  class Push_Event
  {
  public:
    /// Type definition for a pointer to a method.
    typedef typename OBV_EVENTTYPE::_ptr_type _ptr_type;

    typedef void (CONTEXT::*Event_Method) (_ptr_type);

    /**
     * Constructor.
     *
     * @param[in]   producer      Reference to the event producer.
     * @param[in]   push_method   Target method in the producer's context.
     */
    inline
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
    inline
    void operator () (ACE_Time_Value & toc) const
    {
      this->producer_.push_event <
        OBV_EVENTTYPE> (this->event_method_, toc);
    }

  protected:
    /// The producer responsible for pushing the event.
    mutable CUTS_CCM_Event_Producer_T & producer_;

    /// The method used to push the event.
    Event_Method event_method_;
  };

  /// Constructor.
  CUTS_CCM_Event_Producer_T (void);

  /// Destructor.
  ~CUTS_CCM_Event_Producer_T (void);

  /**
   * Set the contecxt for the producer.
   *
   * @param[in]       context     Pointer to the context.
   */
  void context (CONTEXT * context);

  /**
   * Push an event using the stored context.
   */
  template <typename OBV_EVENTTYPE>
  void push_event (void (CONTEXT::*event_type) (typename OBV_EVENTTYPE::_ptr_type),
                   ACE_Time_Value & toc);

  /**
   * Push an event using the stored context.
   */
  template <typename OBV_EVENTTYPE>
  void push_event_ex (void (CONTEXT::*event_type) (typename OBV_EVENTTYPE::_ptr_type),
                      typename OBV_EVENTTYPE::_ptr_type event,
                      ACE_Time_Value & toc);

  /**
   * Activate the event producer.
   *
   * @param[in]     owner       Owner of the event producer.
   */
  void activate (long owner);

private:
  /// The context used to produce the events.
  CONTEXT * context_;

  /// Owner of the event producer.
  long owner_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_Event_Producer_T.inl"
#endif

#include "cuts/CCM_Event_Producer_T.cpp"

#endif  // !defined _CUTS_CCM_EVENT_PRODUCER_T_H_
