// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Object_Event_Handler
//
GAME_INLINE
Object_Event_Handler::
Object_Event_Handler (unsigned long mask, bool destroy_on_close)
: Global_Event_Handler (mask, destroy_on_close)
{

}

//
// ~Object_Event_Handler
//
GAME_INLINE
Object_Event_Handler::~Object_Event_Handler (void)
{

}

//
// handle_object_created
//
GAME_INLINE
int Object_Event_Handler::handle_object_created (Object_in obj)
{
  return 0;
}

//
// handle_object_predestroyed
//
GAME_INLINE
int Object_Event_Handler::handle_object_predestroyed (Object_in obj)
{
  return 0;
}

//
// handle_object_destroyed
//
GAME_INLINE
int Object_Event_Handler::handle_object_destroyed (Object_in obj)
{
  return 0;
}

//
// handle_object_attribute
//
GAME_INLINE
int Object_Event_Handler::handle_object_attribute (Object_in obj)
{
  return 0;
}

//
// handle_object_properties
//
GAME_INLINE
int Object_Event_Handler::handle_object_properties (Object_in obj)
{
  return 0;
}

//
// handle_object_registry
//
GAME_INLINE
int Object_Event_Handler::handle_object_registry (Object_in obj)
{
  return 0;
}

//
// handle_object_relation
//
GAME_INLINE
int Object_Event_Handler::handle_object_relation (Object_in obj)
{
  return 0;
}

//
// handle_object_parent
//
GAME_INLINE
int Object_Event_Handler::handle_object_parent (Object_in obj)
{
  return 0;
}

//
// handle_instance_subtype
//
GAME_INLINE
int Object_Event_Handler::handle_instance_subtype (Object_in obj)
{
  return 0;
}

//
// handle_new_child
//
GAME_INLINE
int Object_Event_Handler::handle_new_child (Object_in obj)
{
  return 0;
}

//
// handle_lost_child
//
GAME_INLINE
int Object_Event_Handler::handle_lost_child (Object_in obj)
{
  return 0;
}

//
// handle_referenced
//
GAME_INLINE
int Object_Event_Handler::handle_referenced (Object_in obj)
{
  return 0;
}

//
// handle_referenced_release
//
GAME_INLINE
int Object_Event_Handler::handle_referenced_release (Object_in obj)
{
  return 0;
}

//
// handle_object_connected
//
GAME_INLINE
int Object_Event_Handler::handle_object_connected (Object_in obj)
{
  return 0;
}

//
// handle_object_disconnected
//
GAME_INLINE
int Object_Event_Handler::handle_object_disconnected (Object_in obj)
{
  return 0;
}

//
// handle_set_included
//
GAME_INLINE
int Object_Event_Handler::handle_set_included (Object_in obj)
{
  return 0;
}

//
// handle_set_excluded
//
GAME_INLINE
int Object_Event_Handler::handle_set_excluded (Object_in obj)
{
  return 0;
}

//
// handle_marked_readonly
//
GAME_INLINE
int Object_Event_Handler::handle_marked_readonly (Object_in obj)
{
  return 0;
}

//
// handle_marked_readwrite
//
GAME_INLINE
int Object_Event_Handler::handle_marked_readwrite (Object_in obj)
{
  return 0;
}

//
// handle_model_open
//
GAME_INLINE
int Object_Event_Handler::handle_model_open (Object_in obj)
{
  return 0;
}

//
// handle_model_close
//
GAME_INLINE
int Object_Event_Handler::handle_model_close (Object_in obj)
{
  return 0;
}

//
// handle_object_select
//
GAME_INLINE
int Object_Event_Handler::handle_object_select (Object_in obj)
{
  return 0;
}

//
// handle_object_prestatus
//
GAME_INLINE
int Object_Event_Handler::handle_object_prestatus (Object_in obj)
{
  return 0;
}

//
// handle_object_copied
//
GAME_INLINE
int Object_Event_Handler::handle_object_copied (Object_in obj)
{
  return 0;
}

//
// handle_object_deselect
//
GAME_INLINE
int Object_Event_Handler::handle_object_deselect (Object_in obj)
{
  return 0;
}

//
// handle_object_mouseover
//
GAME_INLINE
int Object_Event_Handler::handle_object_mouseover (Object_in obj)
{
  return 0;
}

} // namespace GAME
} // namespace Mga
