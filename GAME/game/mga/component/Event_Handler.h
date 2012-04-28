// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Handler.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_EVENT_HANDLER_H_
#define _GAME_MGA_EVENT_HANDLER_H_

#include "Component_export.h"
#include "game/mga/Project.h"

namespace GAME
{
namespace Mga
{
// Forward decl.
class Event_Sink;

/**
 * @class Event_Handler
 *
 * Base class for all event handlers.
 */
class GAME_MGA_COMPONENT_Export Event_Handler
{
protected:
  /**
   * Initializing constructor.
   *
   * @param[in]       mask                Event handler mask.
   * @param[in]       destroy_on_close    Destroy the event handler on close
   */
  Event_Handler (unsigned long mask, bool destroy_on_close = true);

public:
  /// Destructor.
  virtual ~Event_Handler (void);

  /**
   * Initialize the event handler.
   *
   * @param[in]       project         Project event handler is registered
   */
  virtual int initialize (Project project);

  /// Handle the close of the event handler.
  virtual void handle_close (void);

  /// Close the event handler. This method is invoked when
  /// the event handler is unregistered.
  void close (void);

  /// Set the event sink for the implementation.
  void set_event_sink (Event_Sink * eh);

  /// Get the event make for the event handler.
  long event_mask (void) const;

protected:
  /// The current project for the event handler.
  Project project_;

  /// The mask for the event handler.
  unsigned long mask_;

  /// Event handler assigned to this implementation.
  Event_Sink * sink_;

  /// Destroy the event handler when it is closed.
  bool destroy_on_close_;

private:
  // prevent the following operations
  Event_Handler (const Event_Handler &);
  const Event_Handler & operator = (const Event_Handler &);
};

/**
 * @class Top_Level_Event_Handler
 *
 * Top-level event handler for an add-on.
 */
class GAME_MGA_COMPONENT_Export Top_Level_Event_Handler :
  public Event_Handler
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]         mask          Event mask
   */
  Top_Level_Event_Handler (unsigned long mask);

  /// Destructor.
  virtual ~Top_Level_Event_Handler (void);
};

}
}

#if defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

#endif  // !defined _GAME_MGA_EVENT_HANDLER_H_
