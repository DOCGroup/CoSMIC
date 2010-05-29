// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Sink_Impl.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_EVENT_SINK_IMPL_H_
#define _GME_EVENT_SINK_IMPL_H_

#include "game/Object.h"

namespace GAME
{
/**
 * @class Event_Sink_Impl
 */
class Event_Sink_Impl
{
public:
  /// Default constructor.
  Event_Sink_Impl (void);

  /// Destructor.
  virtual ~Event_Sink_Impl (void);

  virtual int handle_global_event (globalevent_enum global_event);

  virtual int handle_object_event (GAME::Object & obj, unsigned long mask);
};

}

#if defined (__GAME_INLINE__)
#include "Event_Sink_Impl.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
