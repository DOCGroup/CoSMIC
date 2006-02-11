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
#include "ace/Message_Queue_T.h"
#include "ace/Auto_Ptr.h"
#include "ace/Reactor_Notification_Strategy.h"

class CUTS_Activation_Record;
class CUTS_Port_Agent;

template <typename COMPONENT>
class CUTS_Export CUTS_Event_Handler_T :
  public ACE_Task_Base
{
public:
  typedef COMPONENT Component_Type;

  typedef void (COMPONENT::*Event_Method) (CUTS_Activation_Record *);

  CUTS_Event_Handler_T (Component_Type * component);

  virtual ~CUTS_Event_Handler_T (void);

  void bind (CUTS_Port_Agent * agent, Event_Method method);

  void unbind (void);

  void handle_event (long dispatch_time);

  void activate (void);

  void deactivate (void);

private:
  int svc (void);

  int handle_input (ACE_HANDLE handle);

  Component_Type * component_;

  Event_Method method_;

  bool active_;

  CUTS_Port_Agent * port_agent_;

  /// Notification strategy for the <closed_list_>.
  ACE_Auto_Ptr <ACE_Reactor_Notification_Strategy> notify_strategy_;

  /// Collection of free activation records.
  ACE_Message_Queue_Ex <long, ACE_MT_SYNCH> event_queue_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/EventHandler_T.inl"
#endif

#include "cuts/EventHandler_T.cpp"

#endif  // !defined _CUTS_EVENT_HANDLER_T_H_
