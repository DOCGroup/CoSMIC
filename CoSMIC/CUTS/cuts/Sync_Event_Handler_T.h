// -*- C++ -*-

//=============================================================================
/**
 * @file        Sync_Event_Handler_T.h
 *
 * $Id: Sync_Event_Handler_T.h,v 1.1.2.1 2006/05/23 22:04:19 hillj Exp $
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_SYNC_EVENT_HANDLER_T_H_
#define _CUTS_SYNC_EVENT_HANDLER_T_H_

#include "cuts/EventHandler_T.h"

template <typename COMPONENT, typename EVENTTYPE>
class CUTS_Sync_Event_Handler_T :
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
  CUTS_Sync_Event_Handler_T (void);

  /// Default destructor.
  virtual ~CUTS_Sync_Event_Handler_T (void);

  /// Handle the event. This will invoke the callback method.
  void handle_event (EVENTTYPE * ev);

private:
  typedef CUTS_Async_Event_Handler_T <COMPONENT, EVENTTYPE> THIS;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Sync_Event_Handler_T.inl"
#endif

#include "cuts/Sync_Event_Handler_T.cpp"

#endif  // !defined _CUTS_SYNC_EVENT_HANDLER_T_H_
