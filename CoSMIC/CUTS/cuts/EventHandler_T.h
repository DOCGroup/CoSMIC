// -*- C++ -*-

//=============================================================================
/**
 * @file    EventHandler_T.h
 *
 * $Id$
 */
//=============================================================================

#ifndef _CUTS_EVENT_HANDLER_T_H_
#define _CUTS_EVENT_HANDLER_T_H_

#include "cuts/config.h"
#include "cuts/PortAgent.h"
#include "ace/Auto_Ptr.h"

// forward declarations
class CUTS_Activation_Record;
class CUTS_Port_Agent;

//=============================================================================
/**
 * @class CUTS_Event_Handler
 */
//=============================================================================

class CUTS_Event_Handler
{
public:
  enum Event_Mode
  {
    UNDEFINED     = 0,
    SYNCHRONOUS   = 1,
    ASYNCHRONOUS  = 2
  };
};

//=============================================================================
/**
 * @class CUTS_Event_Handler_Strategy_T
 */
//=============================================================================

template <typename COMPONENT, typename EVENTTYPE>
class CUTS_Event_Handler_Strategy_T : public CUTS_Event_Handler
{
public:
  /// Type definition for the component owning the event handler.
  typedef COMPONENT Component_Type;

  /// Type definition for the event type.
  typedef EVENTTYPE Event_Type;

  /// Type definition for the callback method.
  typedef void (COMPONENT::*Event_Method) (EVENTTYPE *,
                                           CUTS_Activation_Record *);

  /// Activate the event handler.
  virtual void activate (void) = 0;

  /// Deactivate the event handler.
  virtual void deactivate (void) = 0;

  /**
   * Handle an event.
   *
   * @param[in]       ev      Pointer to the event.
   */
  virtual void handle_event (EVENTTYPE * ev) = 0;

  /**
   * Bind the event handler to the port agent and callback
   * method.
   *
   * @param[in]     name          Name of the event handler.
   * @param[in]     component     Pointer to the containing component.
   * @param[in]     method        Upcall method to handle the event.
   */
  virtual void bind (const char * name,
                     Component_Type * component,
                     Event_Method method) = 0;

  /// Unbind the event handler from the agent and method.
  virtual void unbind (void) = 0;

  /// Get the port agent for the event handler.
  virtual CUTS_Port_Agent & port_agent (void) = 0;
};

//=============================================================================
/**
 * @class CUTS_Event_Handler_Base_T
 */
//=============================================================================

template <typename COMPONENT, typename EVENTTYPE>
class CUTS_Event_Handler_Base_T :
  public CUTS_Event_Handler_Strategy_T <COMPONENT, EVENTTYPE>
{
public:
  /// Type definition for the strategy type.
  typedef CUTS_Event_Handler_Strategy_T <COMPONENT, EVENTTYPE> Strategy_Type;

  /// Type definition for the component owning the event handler.
  typedef typename Strategy_Type::Component_Type Component_Type;

  /// Type definition for the event type.
  typedef typename Strategy_Type::Event_Type Event_Type;

  /// Type definition for the callback method.
  typedef typename Strategy_Type::Event_Method Event_Method;

  /// Default destructor.
  virtual ~CUTS_Event_Handler_Base_T (void);

  /// Activate the event handler.
  virtual void activate (void);

  /// Deactivate the event handler.
  virtual void deactivate (void);

  /**
   * Handle an event.
   *
   * @param[in]       ev      Pointer to the event.
   */
  virtual void handle_event (EVENTTYPE * ev) = 0;

  /**
   * Bind the event handler to the port agent and callback
   * method.
   *
   * @param[in]     name          Name of the event handler.
   * @param[in]     component     Pointer to the containing component.
   * @param[in]     method        Upcall method to handle the event.
   */
  void bind (const char * name,
             Component_Type * component,
             Event_Method method);

  /// Unbind the event handler from the agent and method.
  void unbind (void);

  /// Get the port agent for the event handler.
  CUTS_Port_Agent & port_agent (void);

  /**
   * Return the active state of the event handler.
   *
   * @retval    true      The event handler is active.
   * @retval    false     The event handler is not active.
   */
  bool is_active (void) const;

protected:
  /// Default constructor.
  CUTS_Event_Handler_Base_T (void);

  /**
   * Shared implementation for handing an event. This method performs
   * the necessary operations to benchmark the event handling method.
   *
   * @param[in]     ev            Pointer to the event.
   * @param[in]     queue_time    Amount of time the event was queued.
   */
  void handle_event_i (EVENTTYPE *ev,
                       const ACE_Time_Value & queue_time);

  /// Pointer to the component that owns the event handler.
  Component_Type * component_;

  /// Method invoked when an event is received.
  Event_Method method_;

  /// Port agent attached to this event handler.
  CUTS_Port_Agent port_agent_;

private:
  /// Active state of the event handler.
  bool active_;
};

//=============================================================================
/**
 * @class CUTS_Event_Handler_T
 */
//=============================================================================

template <typename COMPONENT, typename EVENTTYPE>
class CUTS_Event_Handler_T :
  public CUTS_Event_Handler_Strategy_T <COMPONENT, EVENTTYPE>
{
public:
  /// Type definition for the strategy type.
  typedef CUTS_Event_Handler_Strategy_T <COMPONENT, EVENTTYPE> Strategy_Type;

  /// Type definition for the component owning the event handler.
  typedef typename Strategy_Type::Component_Type Component_Type;

  /// Type definition for the event type.
  typedef typename Strategy_Type::Event_Type Event_Type;

  /// Type definition for the callback method.
  typedef typename Strategy_Type::Event_Method Event_Method;

  /// Constructor.
  CUTS_Event_Handler_T (
    CUTS_Event_Handler::Event_Mode mode = CUTS_Event_Handler::ASYNCHRONOUS);

  /// Destructor.
  virtual ~CUTS_Event_Handler_T (void);

  /// Bind the event handler to the port agent and callback method.
  void bind (const char * name,
             Component_Type * component,
             Event_Method method);

  /// Unbind the event handler from the agent and method.
  void unbind (void);

  /// Handle the event. This will invoke the callback method.
  void handle_event (EVENTTYPE * ev);

  /// Activate the event handler.
  void activate (void);

  /// Deactivate the event handler.
  void deactivate (void);

  /// Get the port agent for the event handler.
  CUTS_Port_Agent & port_agent (void);

  /**
   * Set the implementation of the event handler. The caller does
   * not have to worry about managing the implemenatation.
   *
   * @param[in]     impl        Pointer to the implemenation.
   */
  void mode (CUTS_Event_Handler::Event_Mode mode);

  /**
   * Get the event handling mode.
   *
   * @return    The mode of the event handler, e.g, sync or async.
   */
  CUTS_Event_Handler::Event_Mode mode (void) const;

private:
  /// Type definition for the implementation type.
  typedef CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE> Event_Handler_Base;

  /// The implementation type for the event handler.
  ACE_Auto_Ptr <Event_Handler_Base> impl_;

  /// The current mode of the event handler.
  CUTS_Event_Handler::Event_Mode mode_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/EventHandler_T.inl"
#endif

#include "cuts/EventHandler_T.cpp"

#endif  // !defined _CUTS_EVENT_HANDLER_T_H_
