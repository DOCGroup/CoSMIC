// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Global_Event_Handler
//
GAME_INLINE
Global_Event_Handler::
Global_Event_Handler (unsigned long mask, bool destroy_on_close)
: Event_Handler (mask, destroy_on_close),
  is_importing_ (false)
{

}

//
// ~Global_Event_Handler
//
GAME_INLINE
Global_Event_Handler::~Global_Event_Handler (void)
{

}

//
// handle_project_open
//
GAME_INLINE
int Global_Event_Handler::handle_project_open (void)
{
  return 0;
}

//
// handle_project_close
//
GAME_INLINE
int Global_Event_Handler::handle_project_close (void)
{
  return 0;
}

//
// handle_project_save
//
GAME_INLINE
int Global_Event_Handler::handle_save_project (void)
{
  return 0;
}

//
// handle_project_open_finished
//
GAME_INLINE
int Global_Event_Handler::handle_project_open_finished (void)
{
  return 0;
}

//
// handle_territory_create
//
GAME_INLINE
int Global_Event_Handler::handle_territory_create (void)
{
  return 0;
}

//
// handle_territory_destroy
//
GAME_INLINE
int Global_Event_Handler::handle_territory_destroy (void)
{
  return 0;
}

//
// handle_transaction_commit
//
GAME_INLINE
int Global_Event_Handler::handle_transaction_commit (void)
{
  return 0;
}

//
// handle_transaction_abort
//
GAME_INLINE
int Global_Event_Handler::handle_transaction_abort (void)
{
  return 0;
}

//
// handle_undo
//
GAME_INLINE
int Global_Event_Handler::handle_undo (void)
{
  return 0;
}

//
// handle_redo
//
GAME_INLINE
int Global_Event_Handler::handle_redo (void)
{
  return 0;
}

//
// handle_project_properties
//
GAME_INLINE
int Global_Event_Handler::handle_project_properties (void)
{
  return 0;
}

//
// handle_notification_ready
//
GAME_INLINE
int Global_Event_Handler::handle_notification_ready (void)
{
  return 0;
}

//
// handle_xml_import_begin
//
GAME_INLINE
int Global_Event_Handler::handle_xml_import_begin (void)
{
  this->is_importing_ = true;
  return 0;
}

//
// handle_xml_import_end
//
GAME_INLINE
int Global_Event_Handler::handle_xml_import_end (void)
{
  this->is_importing_ = false;
  return 0;
}

//
// handle_xml_import_fcos_begin
//
GAME_INLINE
int Global_Event_Handler::handle_xml_import_fcos_begin (void)
{
  return 0;
}

//
// handle_xml_import_fcos_end
//
GAME_INLINE
int Global_Event_Handler::handle_xml_import_fcos_end (void)
{
  return 0;
}

//
// handle_xml_import_special_begin
//
GAME_INLINE
int Global_Event_Handler::handle_xml_import_special_begin (void)
{
  return 0;
}

//
// handle_xml_import_special_end
//
GAME_INLINE
int Global_Event_Handler::handle_xml_import_special_end (void)
{
  return 0;
}

//
// handle_library_attach_begin
//
GAME_INLINE
int Global_Event_Handler::handle_library_attach_begin (void)
{
  return 0;
}

//
// handle_library_attach_end
//
GAME_INLINE
int Global_Event_Handler::handle_library_attach_end (void)
{
  return 0;
}

} // namespace GAME
} // namespace Mga
