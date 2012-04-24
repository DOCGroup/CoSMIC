// $Id$

#include "StdAfx.h"
#include "Readonly_Event_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Readonly_Event_Handler.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// check_object_event
//
int Readonly_Event_Handler::check_object_event (unsigned long mask) const
{
  // Determine if this is an event that we do allow.
  if (0 != (mask & this->enabled_))
    return 0;

  // Display an error message since we do not support this event.
  ::AfxMessageBox ("This operation is not allowed.", MB_ICONERROR);
  return E_MGA_MUST_ABORT;
}

//
// handle_object_created
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_created (Object_in obj)
{
  return this->check_object_event (OBJEVENT_CREATED);
}

//
// handle_object_destroyed
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_destroyed (Object_in obj)
{
  return this->check_object_event (OBJEVENT_DESTROYED);
}

//
// handle_object_attribute
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_attribute (Object_in obj)
{
  return this->check_object_event (OBJEVENT_ATTR);
}

//
// handle_object_properties
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_properties (Object_in obj)
{
  return this->check_object_event (OBJEVENT_PROPERTIES);
}

//
// handle_object_registry
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_registry (Object_in obj)
{
  return this->check_object_event (OBJEVENT_REGISTRY);
}

//
// handle_object_relation
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_relation (Object_in obj)
{
  return this->check_object_event (OBJEVENT_RELATION);
}

//
// handle_object_parent
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_parent (Object_in obj)
{
  return this->check_object_event (OBJEVENT_PARENT);
}

//
// handle_instance_subtype
//
GAME_INLINE
int Readonly_Event_Handler::handle_instance_subtype (Object_in obj)
{
  return this->check_object_event (OBJEVENT_SUBT_INST);
}

//
// handle_new_child
//
GAME_INLINE
int Readonly_Event_Handler::handle_new_child (Object_in obj)
{
  return this->check_object_event (OBJEVENT_NEWCHILD);
}

//
// handle_lost_child
//
GAME_INLINE
int Readonly_Event_Handler::handle_lost_child (Object_in obj)
{
  return this->check_object_event (OBJEVENT_LOSTCHILD);
}

//
// handle_referenced
//
GAME_INLINE
int Readonly_Event_Handler::handle_referenced (Object_in obj)
{
  return this->check_object_event (OBJEVENT_REFERENCED);
}

//
// handle_referenced_release
//
GAME_INLINE
int Readonly_Event_Handler::handle_referenced_release (Object_in obj)
{
  return this->check_object_event (OBJEVENT_REFRELEASED);
}

//
// handle_object_connected
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_connected (Object_in obj)
{
  return this->check_object_event (OBJEVENT_CONNECTED);
}

//
// handle_object_disconnected
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_disconnected (Object_in obj)
{
  return this->check_object_event (OBJEVENT_DISCONNECTED);
}

//
// handle_set_included
//
GAME_INLINE
int Readonly_Event_Handler::handle_set_included (Object_in obj)
{
  return this->check_object_event (OBJEVENT_SETINCLUDED);
}

//
// handle_set_excluded
//
GAME_INLINE
int Readonly_Event_Handler::handle_set_excluded (Object_in obj)
{
  return this->check_object_event (OBJEVENT_SETEXCLUDED);
}

//
// handle_marked_readonly
//
GAME_INLINE
int Readonly_Event_Handler::handle_marked_readonly (Object_in obj)
{
  return this->check_object_event (OBJEVENT_MARKEDRO);
}

//
// handle_marked_readwrite
//
GAME_INLINE
int Readonly_Event_Handler::handle_marked_readwrite (Object_in obj)
{
  return this->check_object_event (OBJEVENT_MARKEDRW);
}

//
// handle_model_open
//
GAME_INLINE
int Readonly_Event_Handler::handle_model_open (Object_in obj)
{
  return this->check_object_event (OBJEVENT_OPENMODEL);
}

//
// handle_model_close
//
GAME_INLINE
int Readonly_Event_Handler::handle_model_close (Object_in obj)
{
  return this->check_object_event (OBJEVENT_CLOSEMODEL);
}

//
// handle_object_select
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_select (Object_in obj)
{
  return this->check_object_event (OBJEVENT_SELECT);
}

//
// handle_object_deselect
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_deselect (Object_in obj)
{
  return this->check_object_event (OBJEVENT_DESELECT);
}

//
// handle_object_mouseover
//
GAME_INLINE
int Readonly_Event_Handler::handle_object_mouseover (Object_in obj)
{
  return this->check_object_event (OBJEVENT_MOUSEOVER);
}

}
}
