// -*- C++ -*-

//=============================================================================
/**
 * @file        EventHandler.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_EVENT_HANDLER_H_
#define _CUTS_EVENT_HANDLER_H_

#include "cuts/config.h"
#include "ace/SStringfwd.h"

//=============================================================================
/**
 * @class CUTS_Event_Handler
 *
 * Base implementation for all event handlers.
 */
//=============================================================================

class CUTS_Export CUTS_Event_Handler
{
public:
  /// Event handling mode.
  enum Event_Mode
  {
    /// Undefined mode.
    UNDEFINED     = 0,

    /// Synchronous mode.
    SYNCHRONOUS   = 1,

    /// Asynchronous mode.
    ASYNCHRONOUS  = 2
  };
};

#if defined (__CUTS_INLINE__)
#include "cuts/EventHandler.inl"
#endif

#endif  // !defined _CUTS_EVENT_HANDLER_H_
