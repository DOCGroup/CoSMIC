// -*- C++ -*-

//==============================================================================
/**
 *  @file        Object_Event_Handler.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_MGA_OBJECT_EVENT_HANDLER_H_
#define _GAME_MGA_OBJECT_EVENT_HANDLER_H_

#include "Global_Event_Handler.h"
#include "game/mga/addons/Model_Intelligence/Boolean_Expr.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Object_Event_Handler
 *
 * Base class for event handlers that operate on a Mga Object.
 */
class GAME_MGA_COMPONENT_Export Object_Event_Handler :
  public Global_Event_Handler
{
protected:
  /// Default constructor.
  Object_Event_Handler (unsigned long mask, bool destroy_on_close = true);

public:
  /// Destructor.
  virtual ~Object_Event_Handler (void);

  virtual int handle_object_created (Object_in obj);
  virtual int handle_object_predestroyed (Object_in obj);
  virtual int handle_object_destroyed (Object_in obj);

  virtual int handle_object_attribute (Object_in obj);
  virtual int handle_object_properties (Object_in obj);
  virtual int handle_object_registry (Object_in obj);

  virtual int handle_object_relation (Object_in obj);
  virtual int handle_object_parent (Object_in obj);

  virtual int handle_instance_subtype (Object_in obj);

  virtual int handle_new_child (Object_in obj);
  virtual int handle_lost_child (Object_in obj);

  virtual int handle_referenced (Object_in obj);
  virtual int handle_referenced_release (Object_in obj);

  virtual int handle_object_connected (Object_in obj);
  virtual int handle_object_disconnected (Object_in obj);

  virtual int handle_set_included (Object_in obj);
  virtual int handle_set_excluded (Object_in obj);

  virtual int handle_marked_readonly (Object_in obj);
  virtual int handle_marked_readwrite (Object_in obj);

  virtual int handle_model_open (Object_in obj);
  virtual int handle_model_close (Object_in obj);

  virtual int handle_object_select (Object_in obj);
  virtual int handle_object_deselect (Object_in obj);

  virtual int handle_object_mouseover (Object_in obj);

  virtual int handle_object_copied (Object_in obj);
  virtual int handle_object_prestatus (Object_in obj);

protected:
  // Caching the constraints for model intelligence
  std::map <std::string,
            std::vector <Boolean_Expr *>> cache;
};

} // namespace GAME
} // namespace Mga

#if defined (__GAME_INLINE__)
#include "Object_Event_Handler.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_MGA_OBJECT_EVENT_HANDLER_H_
