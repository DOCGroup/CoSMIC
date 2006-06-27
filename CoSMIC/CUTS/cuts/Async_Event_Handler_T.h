// -*- C++ -*-

//=============================================================================
/**
 * @file        Async_Event_Hanlder_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ASYNC_EVENT_HANDLER_T_H_
#define _CUTS_ASYNC_EVENT_HANDLER_T_H_

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

#include "cuts/config.h"
#include "cuts/EventHandler_T.h"
#include "ace/Unbounded_Queue.h"
#include "ace/Condition_Thread_Mutex.h"

//=============================================================================
/**
 * @class CUTS_Async_Event_Handler_T
 */
//=============================================================================

template <typename COMPONENT, typename EVENTTYPE>
class CUTS_Async_Event_Handler_T :
  public CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>
{
public:
  /// Type definition for the super class.
  typedef CUTS_Event_Handler_Base_T <
    COMPONENT, EVENTTYPE> Event_Handler_Base;

  /// Type definition for the component owning the event handler.
  typedef typename Event_Handler_Base::Component_Type Component_Type;

  /// Type definition for the event type.
  typedef typename Event_Handler_Base::Event_Type Event_Type;

  /// Type definition for the callback method.
  typedef typename Event_Handler_Base::Event_Method Event_Method;

  /// Constructor.
  CUTS_Async_Event_Handler_T (void);

  /// Destructor.
  virtual ~CUTS_Async_Event_Handler_T (void);

  /// Activate the event handler.
  void activate (void);

  /// Deactivate the event handler.
  void deactivate (void);

  /// Handle the event. This will invoke the callback method.
  void handle_event (EVENTTYPE * ev);

private:
  typedef CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE> THIS;

  /// Service handler for the event handler.
  static ACE_THR_FUNC_RETURN event_loop (void * param);

  /// Group id of the spawned threads for the event handler.
  int grp_id_;

  /// Collection of free activation records.
  ACE_Message_Queue_Ex <EVENTTYPE, ACE_MT_SYNCH> event_queue_;
};

#include "cuts/Async_Event_Handler_T.cpp"

#endif  // !defined _CUTS_ASYNC_EVENT_HANDLER_T_H_
