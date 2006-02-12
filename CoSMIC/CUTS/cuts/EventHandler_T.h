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
#include "ace/Task.h"
#include "ace/Auto_Ptr.h"
#include "ace/Unbounded_Queue.h"
#include "ace/Thread_Mutex.h"

class CUTS_Activation_Record;
class CUTS_Port_Agent;

//=============================================================================
/**
 * @class CUTS_Event_Handler_T
 */
//=============================================================================

template <typename COMPONENT>
class CUTS_Export CUTS_Event_Handler_T :
  public ACE_Task_Base
{
public:
  /// Type definition for the component owning the event handler.
  typedef COMPONENT Component_Type;

  /// Type definition for the callback method.
  typedef void (COMPONENT::*Event_Method) (CUTS_Activation_Record *);

  /// Constructor.
  CUTS_Event_Handler_T (Component_Type * component);

  /// Destructor.
  virtual ~CUTS_Event_Handler_T (void);

  /// Bind the event handler to the port agent and callback method.
  void bind (CUTS_Port_Agent * agent, Event_Method method);

  /// Unbind the event handler from the agent and method.
  void unbind (void);

  /// Handle the event. This will invoke the callback method.
  void handle_event (long dispatch_time);

  /// Activate the event handler.
  void activate (void);

  /// Deactivate the event handler.
  void deactivate (void);

private:
  /// Service handler for the event handler.
  int svc (void);

  /// Input callback method.
  int handle_input (ACE_HANDLE handle);

  /// Pointer to the component that owns the event handler.
  Component_Type * component_;

  /// Method invoked when an event is received.
  Event_Method method_;

  /// The active state of the event handler.
  bool active_;

  /// Port agent attached to this event handler.
  CUTS_Port_Agent * port_agent_;

  /// Locking mechanism for the <event_queue_>.
  ACE_Thread_Mutex event_queue_lock_;

  /// Collection of free activation records.
  ACE_Unbounded_Queue <long> event_queue_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/EventHandler_T.inl"
#endif

#include "cuts/EventHandler_T.cpp"

#endif  // !defined _CUTS_EVENT_HANDLER_T_H_
