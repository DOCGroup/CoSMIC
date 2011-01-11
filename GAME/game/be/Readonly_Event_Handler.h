// -*- C++ -*-

//=============================================================================
/**
 *  @file       Readonly_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_BE_READONLY_EVENT_HANDLER_H_
#define _GAME_BE_READONLY_EVENT_HANDLER_H_

#include "Event_Handler_Impl.h"

namespace GAME
{
/**
 * @class Readonly_Event_Handler
 *
 * Event handler that emulates read-only semantics. The client can
 * customize what is read-only by specifying what events are enabled.
 */
class GAME_BE_Export Readonly_Event_Handler :
  public Event_Handler_Impl
{
public :
  Readonly_Event_Handler (bool destroy_on_close = false);

  Readonly_Event_Handler (unsigned long enabled,
                          bool destroy_on_close = false);

  virtual ~Readonly_Event_Handler (void);

  virtual int handle_object_event (Object_in obj, unsigned long mask);

protected:
  /// Bitmask of enabled events.
  unsigned long enabled_;
};

}

#if defined (__GAME_INLINE__)
#include "Readonly_Event_Handler.inl"
#endif

#endif  // !defined _GAME_BE_EMULATED_READONLY_EVENT_HANDLER_H_
