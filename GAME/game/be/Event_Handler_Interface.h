// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Handler_Interface.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_BE_EVENT_HANDLER_INTERFACE_H_
#define _GAME_BE_EVENT_HANDLER_INTERFACE_H_

#include "BE_Export.h"
#include "game/Project.h"

namespace GAME
{
// Forward decl.
class Project;

// Forward decl.
class Event_Handler;

/**
 * @class Event_Handler_Impl
 *
 * Base class implementation for the event sink.
 */
class GAME_BE_Export Event_Handler_Interface
{
public:
  virtual ~Event_Handler_Interface (void) = 0 { }

  /// Set the event handler for the implementation. This allows
  /// the implementation to send message to the event handler.
  virtual void set_event_handler (Event_Handler * eh) = 0;

  /// Get the event make for the event handler.
  virtual long event_mask (void) const = 0;

  /**
   * Initialize the event handler.
   *
   * @param[in]       project         Project event handler is registered
   */
  virtual int initialize (GAME::Project project) = 0;

  /// Close the event handler. This method is invoked when
  /// the event handler is unregistered.
  virtual void close (void) = 0;

  /**
   * General callback for all global events. This method is called
   * before the more specialized methods are called for the global
   * event.
   *
   * @param[in]       global_event    The global event.
   */
  virtual int handle_global_event (long global_event) = 0;

  virtual int handle_project_open (void) = 0;
  virtual int handle_project_close (void) = 0;

  virtual int handle_territory_create (void) = 0;
  virtual int handle_territory_destroy (void) = 0;

  virtual int handle_transaction_commit (void) = 0;
  virtual int handle_transaction_abort (void) = 0;

  virtual int handle_undo (void) = 0;
  virtual int handle_redo (void) = 0;

  virtual int handle_project_properties (void) = 0;
  virtual int handle_notification_ready (void) = 0;

  virtual int handle_xml_import_begin (void) = 0;
  virtual int handle_xml_import_end (void) = 0;

  virtual int handle_xml_import_fcos_begin (void) = 0;
  virtual int handle_xml_import_fcos_end (void) = 0;

  virtual int handle_xml_import_special_begin (void) = 0;
  virtual int handle_xml_import_special_end (void) = 0;

  virtual int handle_library_attach_begin (void) = 0;
  virtual int handle_library_attach_end (void) = 0;

  /**
   * General callback for all object events. This is called before
   * the specialized methods are called for the object event.
   *
   * @param[in]       obj             Target object
   * @param[in]       mask            Event mask
   * @retval          0               Success
   * @retval          -1              Failure
   */
  virtual int handle_object_event (Object obj, unsigned long mask) = 0;

  virtual int handle_object_created (GAME::Object obj) = 0;
  virtual int handle_object_destroyed (Object obj) = 0;

  virtual int handle_object_attribute (Object obj) = 0;
  virtual int handle_object_properties (Object obj) = 0;
  virtual int handle_object_registry (Object obj) = 0;

  virtual int handle_object_relation (Object obj) = 0;
  virtual int handle_object_parent (Object obj) = 0;

  virtual int handle_instance_subtype (Object obj) = 0;

  virtual int handle_new_child (Object obj) = 0;
  virtual int handle_lost_child (Object obj) = 0;

  virtual int handle_referenced (Object obj) = 0;
  virtual int handle_referenced_release (Object obj) = 0;

  virtual int handle_object_connected (Object obj) = 0;
  virtual int handle_object_disconnected (Object obj) = 0;

  virtual int handle_set_included (Object obj) = 0;
  virtual int handle_set_excluded (Object obj) = 0;

  virtual int handle_marked_readonly (Object obj) = 0;
  virtual int handle_marked_readwrite (Object obj) = 0;

  virtual int handle_model_open (Object obj) = 0;
  virtual int handle_model_close (Object obj) = 0;

  virtual int handle_object_select (Object obj) = 0;
  virtual int handle_object_deselect (Object obj) = 0;

  virtual int handle_object_mouseover (Object obj) = 0;
};

}

#endif  // !defined _GAME_BE_EVENT_HANDLER_INTERFACE_H_
