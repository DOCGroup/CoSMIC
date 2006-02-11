// -*- C++ -*-

//=============================================================================
/**
 * @file    EventHandler.h
 *
 * $Id$
 */
//=============================================================================

#ifndef _CUTS_EVENT_HANDLER_H_
#define _CUTS_EVENT_HANDLER_H_

#include "cuts/config.h"

//=============================================================================
/**
 * @class CUTS_Single_Event_Handler
 */
//=============================================================================

class CUTS_Export CUTS_Single_Event_Handler
{
public:
  /// Constructor.
  CUTS_Single_Event_Handler (void);

  /// Destructor.
  ~CUTS_Single_Event_Handler (void);

  /// Handle the event.
  void handle_event (void);

private:

};

#if defined (__CUTS_INLINE__)
# include "cuts/EventHandler.inl"
#endif

#endif  // !defined _CUTS_EVENT_HANDLER_H_
