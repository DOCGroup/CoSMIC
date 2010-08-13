// $Id$

namespace GAME
{
//
// Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::Event_Handler_Impl (void)
: current_mask_ (0)
{

}

//
// Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::Event_Handler_Impl (long mask)
: current_mask_ (mask)
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
void Event_Handler_Impl::set_event_handler (Event_Handler * eh)
{
  this->event_handler_ = eh;
}

//
// initialize
//
GAME_INLINE
int Event_Handler_Impl::initialize (GAME::Project & project)
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
handle_object_event (Object & obj, unsigned long mask)
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
  return 0;
}

//
// handle_xml_import_end
//
GAME_INLINE
int Event_Handler_Impl::handle_xml_import_end (void)
{
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
int Event_Handler_Impl::handle_object_created (GAME::Object obj)
{
  return 0;
}

//
// handle_object_destroyed
//
GAME_INLINE
int Event_Handler_Impl::handle_object_destroyed (Object obj)
{
  return 0;
}

//
// handle_instance_subtype
//
GAME_INLINE
int Event_Handler_Impl::handle_instance_subtype (Object obj)
{
  return 0;
}

//
// handle_object_attribute
//
GAME_INLINE
int Event_Handler_Impl::handle_object_attribute (Object obj)
{
  return 0;
}

//
// handle_object_properties
//
GAME_INLINE
int Event_Handler_Impl::handle_object_properties (Object obj)
{
  return 0;
}

//
// handle_object_registry
//
GAME_INLINE
int Event_Handler_Impl::handle_object_registry (Object obj)
{
  return 0;
}

//
// handle_object_relation
//
GAME_INLINE
int Event_Handler_Impl::handle_object_relation (Object obj)
{
  return 0;
}

//
// handle_object_parent
//
GAME_INLINE
int Event_Handler_Impl::handle_object_parent (Object obj)
{
  return 0;
}

//
// handle_new_child
//
GAME_INLINE
int Event_Handler_Impl::handle_new_child (Object obj)
{
  return 0;
}

//
// handle_lost_child
//
GAME_INLINE
int Event_Handler_Impl::handle_lost_child (Object obj)
{
  return 0;
}

//
// handle_referenced
//
GAME_INLINE
int Event_Handler_Impl::handle_referenced (Object obj)
{
  return 0;
}

//
// handle_referenced_release
//
GAME_INLINE
int Event_Handler_Impl::handle_referenced_release (Object obj)
{
  return 0;
}

//
// handle_object_connected
//
GAME_INLINE
int Event_Handler_Impl::handle_object_connected (Object obj)
{
  return 0;
}

//
// handle_object_disconnected
//
GAME_INLINE
int Event_Handler_Impl::handle_object_disconnected (Object obj)
{
  return 0;
}

//
// handle_set_included
//
GAME_INLINE
int Event_Handler_Impl::handle_set_included (Object obj)
{
  return 0;
}

//
// handle_set_excluded
//
GAME_INLINE
int Event_Handler_Impl::handle_set_excluded (Object obj)
{
  return 0;
}

//
// handle_marked_readonly
//
GAME_INLINE
int Event_Handler_Impl::handle_marked_readonly (Object obj)
{
  return 0;
}

//
// handle_marked_readwrite
//
GAME_INLINE
int Event_Handler_Impl::handle_marked_readwrite (Object obj)
{
  return 0;
}

//
// handle_model_open
//
GAME_INLINE
int Event_Handler_Impl::handle_model_open (Object obj)
{
  return 0;
}

//
// handle_model_close
//
GAME_INLINE
int Event_Handler_Impl::handle_model_close (Object obj)
{
  return 0;
}

//
// handle_object_select
//
GAME_INLINE
int Event_Handler_Impl::handle_object_select (Object obj)
{
  return 0;
}

//
// handle_object_deselect
//
GAME_INLINE
int Event_Handler_Impl::handle_object_deselect (Object obj)
{
  return 0;
}

//
// handle_object_mouseover
//
GAME_INLINE
int Event_Handler_Impl::handle_object_mouseover (Object obj)
{
  return 0;
}

}
