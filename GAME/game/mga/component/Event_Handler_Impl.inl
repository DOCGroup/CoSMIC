// $Id$

namespace GAME
{
namespace Mga
{

//
// Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::Event_Handler_Impl (bool destroy_on_close)
: current_mask_ (0),
  is_importing_ (false),
  destroy_on_close_ (destroy_on_close)
{

}

//
// Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::Event_Handler_Impl (unsigned long mask, bool destroy_on_close)
: current_mask_ (mask),
  is_importing_ (false),
  destroy_on_close_ (destroy_on_close)
{

}

//
// ~Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::~Event_Handler_Impl (void)
{

}

//
// set_event_handler
//
GAME_INLINE
void Event_Handler_Impl::set_event_handler (Event_Sink * eh)
{
  this->event_handler_ = eh;
}

//
// initialize
//
GAME_INLINE
int Event_Handler_Impl::initialize (Project project)
{
  return 0;
}

//
// handle_global_event
//
GAME_INLINE
int Event_Handler_Impl::
handle_global_event (long global_event)
{
  return 0;
}

//
// handle_object_event
//
GAME_INLINE
int Event_Handler_Impl::
handle_object_event (Object_in, unsigned long mask)
{
  return 0;
}

//
// event_mask
//
GAME_INLINE
long Event_Handler_Impl::event_mask (void) const
{
  return this->current_mask_;
}

//
// handle_project_open
//
GAME_INLINE
int Event_Handler_Impl::handle_project_open (void)
{
  return 0;
}

//
// handel_project_close
//
GAME_INLINE
int Event_Handler_Impl::handle_project_close (void)
{
  return 0;
}

//
// handle_territory_create
//
GAME_INLINE
int Event_Handler_Impl::handle_territory_create (void)
{
  return 0;
}

//
// handle_territory_destroy
//
GAME_INLINE
int Event_Handler_Impl::handle_territory_destroy (void)
{
  return 0;
}

//
// handle_transaction_commit
//
GAME_INLINE
int Event_Handler_Impl::handle_transaction_commit (void)
{
  return 0;
}

//
// handle_transaction_abort
//
GAME_INLINE
int Event_Handler_Impl::handle_transaction_abort (void)
{
  return 0;
}

//
// handle_undo
//
GAME_INLINE
int Event_Handler_Impl::handle_undo (void)
{
  return 0;
}

//
// handle_redo
//
GAME_INLINE
int Event_Handler_Impl::handle_redo (void)
{
  return 0;
}

//
// handle_project_properties
//
GAME_INLINE
int Event_Handler_Impl::handle_project_properties (void)
{
  return 0;
}

//
// handle_notification_ready
//
GAME_INLINE
int Event_Handler_Impl::handle_notification_ready (void)
{
  return 0;
}

//
// handle_xml_import_begin
//
GAME_INLINE
int Event_Handler_Impl::handle_xml_import_begin (void)
{
  this->is_importing_ = true;
  return 0;
}

//
// handle_xml_import_end
//
GAME_INLINE
int Event_Handler_Impl::handle_xml_import_end (void)
{
  this->is_importing_ = false;
  return 0;
}

//
// handle_xml_import_fcos_begin
//
GAME_INLINE
int Event_Handler_Impl::handle_xml_import_fcos_begin (void)
{
  return 0;
}

//
// handle_xml_import_fcos_end
//
GAME_INLINE
int Event_Handler_Impl::handle_xml_import_fcos_end (void)
{
  return 0;
}

//
// handle_xml_import_special_begin
//
GAME_INLINE
int Event_Handler_Impl::handle_xml_import_special_begin (void)
{
  return 0;
}

//
// handle_xml_import_special_end
//
GAME_INLINE
int Event_Handler_Impl::handle_xml_import_special_end (void)
{
  return 0;
}

//
// handle_library_attach_begin
//
GAME_INLINE
int Event_Handler_Impl::handle_library_attach_begin (void)
{
  return 0;
}

//
// handle_library_attach_end
//
GAME_INLINE
int Event_Handler_Impl::handle_library_attach_end (void)
{
  return 0;
}

//
// handle_object_created
//
GAME_INLINE
int Event_Handler_Impl::handle_object_created (Object_in)
{
  return 0;
}

//
// handle_object_destroyed
//
GAME_INLINE
int Event_Handler_Impl::handle_object_destroyed (Object_in)
{
  return 0;
}

//
// handle_instance_subtype
//
GAME_INLINE
int Event_Handler_Impl::handle_instance_subtype (Object_in)
{
  return 0;
}

//
// handle_object_attribute
//
GAME_INLINE
int Event_Handler_Impl::handle_object_attribute (Object_in)
{
  return 0;
}

//
// handle_object_properties
//
GAME_INLINE
int Event_Handler_Impl::handle_object_properties (Object_in)
{
  return 0;
}

//
// handle_object_registry
//
GAME_INLINE
int Event_Handler_Impl::handle_object_registry (Object_in)
{
  return 0;
}

//
// handle_object_relation
//
GAME_INLINE
int Event_Handler_Impl::handle_object_relation (Object_in)
{
  return 0;
}

//
// handle_object_parent
//
GAME_INLINE
int Event_Handler_Impl::handle_object_parent (Object_in)
{
  return 0;
}

//
// handle_new_child
//
GAME_INLINE
int Event_Handler_Impl::handle_new_child (Object_in)
{
  return 0;
}

//
// handle_lost_child
//
GAME_INLINE
int Event_Handler_Impl::handle_lost_child (Object_in)
{
  return 0;
}

//
// handle_referenced
//
GAME_INLINE
int Event_Handler_Impl::handle_referenced (Object_in)
{
  return 0;
}

//
// handle_referenced_release
//
GAME_INLINE
int Event_Handler_Impl::handle_referenced_release (Object_in)
{
  return 0;
}

//
// handle_object_connected
//
GAME_INLINE
int Event_Handler_Impl::handle_object_connected (Object_in)
{
  return 0;
}

//
// handle_object_disconnected
//
GAME_INLINE
int Event_Handler_Impl::handle_object_disconnected (Object_in)
{
  return 0;
}

//
// handle_set_included
//
GAME_INLINE
int Event_Handler_Impl::handle_set_included (Object_in)
{
  return 0;
}

//
// handle_set_excluded
//
GAME_INLINE
int Event_Handler_Impl::handle_set_excluded (Object_in)
{
  return 0;
}

//
// handle_marked_readonly
//
GAME_INLINE
int Event_Handler_Impl::handle_marked_readonly (Object_in)
{
  return 0;
}

//
// handle_marked_readwrite
//
GAME_INLINE
int Event_Handler_Impl::handle_marked_readwrite (Object_in)
{
  return 0;
}

//
// handle_model_open
//
GAME_INLINE
int Event_Handler_Impl::handle_model_open (Object_in)
{
  return 0;
}

//
// handle_model_close
//
GAME_INLINE
int Event_Handler_Impl::handle_model_close (Object_in)
{
  return 0;
}

//
// handle_object_select
//
GAME_INLINE
int Event_Handler_Impl::handle_object_select (Object_in)
{
  return 0;
}

//
// handle_object_deselect
//
GAME_INLINE
int Event_Handler_Impl::handle_object_deselect (Object_in)
{
  return 0;
}

//
// handle_object_mouseover
//
GAME_INLINE
int Event_Handler_Impl::handle_object_mouseover (Object_in)
{
  return 0;
}

}
}
