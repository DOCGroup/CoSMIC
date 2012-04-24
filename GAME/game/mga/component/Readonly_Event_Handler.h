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

#ifndef _GAME_MGA_READONLY_EVENT_HANDLER_H_
#define _GAME_MGA_READONLY_EVENT_HANDLER_H_

#include "Object_Event_Handler.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Readonly_Event_Handler
 *
 * Event handler that emulates read-only semantics. The client can
 * customize what is read-only by specifying what events are enabled.
 */
class GAME_MGA_COMPONENT_Export Readonly_Event_Handler :
  public Object_Event_Handler
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]         destroy_on_close          Destroy handler on close
   */
  Readonly_Event_Handler (bool destroy_on_close = true);

  /**
   * Initializing constructor.
   *
   * @param[in]         enabled                   Events that are enabled
   * @param[in]         destroy_on_close          Destroy handler on close
   */
  Readonly_Event_Handler (unsigned long enabled, bool destroy_on_close = true);

  /// Destructor.
  virtual ~Readonly_Event_Handler (void);

  int handle_object_created (Object_in obj);
  int handle_object_destroyed (Object_in obj);
  int handle_object_attribute (Object_in obj);
  int handle_object_properties (Object_in obj);
  int handle_object_registry (Object_in obj);
  int handle_object_relation (Object_in obj);
  int handle_object_parent (Object_in obj);
  int handle_instance_subtype (Object_in obj);
  int handle_new_child (Object_in obj);
  int handle_lost_child (Object_in obj);
  int handle_referenced (Object_in obj);
  int handle_referenced_release (Object_in obj);
  int handle_object_connected (Object_in obj);
  int handle_object_disconnected (Object_in obj);
  int handle_set_included (Object_in obj);
  int handle_set_excluded (Object_in obj);
  int handle_marked_readonly (Object_in obj);
  int handle_marked_readwrite (Object_in obj);
  int handle_model_open (Object_in obj);
  int handle_model_close (Object_in obj);
  int handle_object_select (Object_in obj);
  int handle_object_deselect (Object_in obj);
  int handle_object_mouseover (Object_in obj);

protected:
  /// Set the common configuration.
  void init (void);

  /// Helper method for checking the event mask.
  int check_object_event (unsigned long mask) const;

  /// Bitmask of enabled events.
  unsigned long enabled_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Readonly_Event_Handler.inl"
#endif

#endif  // !defined _GAME_BE_EMULATED_READONLY_EVENT_HANDLER_H_
