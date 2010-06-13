// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Handler_Impl.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_BE_EVENT_HANDLER_IMPL_H_
#define _GAME_BE_EVENT_HANDLER_IMPL_H_

#include "BE_Export.h"
#include "game/config.h"

namespace GAME
{
// Forward decl
class Object;

// Forward decl.
class Project;

/**
 * @class Event_Handler_Impl
 *
 * Base class implementation for the event sink.
 */
class GAME_BE_Export Event_Handler_Impl
{
public:
  /// Default constructor.
  Event_Handler_Impl (void);

  Event_Handler_Impl (long mask);

  /// Destructor.
  virtual ~Event_Handler_Impl (void);

  virtual int initialize (GAME::Project & project);

  virtual int handle_global_event (long global_event);

  virtual int handle_object_event (GAME::Object & obj, unsigned long mask);

  long event_mask (void) const;

protected:
  long current_mask_;
};

}

#if defined (__GAME_INLINE__)
#include "Event_Handler_Impl.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
