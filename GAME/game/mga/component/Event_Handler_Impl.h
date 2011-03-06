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

#include "Event_Handler_Interface.h"

namespace GAME
{
namespace Mga
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
class GAME_MGA_COMPONENT_Export Event_Handler_Impl :
  public Event_Handler_Interface
{
public:
  /// Default constructor.
  Event_Handler_Impl (bool destroy_on_close = false);

  /**
   * Initializing constructor
   *
   * @param[in]       mask            Event handler's mask.
   */
  Event_Handler_Impl (unsigned long mask, bool destroy_on_close = false);

  /// Destructor.
  virtual ~Event_Handler_Impl (void);

  /// Set the event handler for the implementation. This allows
  /// the implementation to send message to the event handler.
  virtual void set_event_handler (Event_Handler * eh);

  /// Get the event make for the event handler.
  virtual long event_mask (void) const;

  /**
   * Initialize the event handler.
   *
   * @param[in]       project         Project event handler is registered
   */
  virtual int initialize (Project project);

  /// Close the event handler. This method is invoked when
  /// the event handler is unregistered.
  virtual void close (void);

  /**
   * General callback for all global events. This method is called
   * before the more specialized methods are called for the global
   * event.
   *
   * @param[in]       global_event    The global event.
   */
  virtual int handle_global_event (long global_event);

  virtual int handle_project_open (void);
  virtual int handle_project_close (void);

  virtual int handle_territory_create (void);
  virtual int handle_territory_destroy (void);

  virtual int handle_transaction_commit (void);
  virtual int handle_transaction_abort (void);

  virtual int handle_undo (void);
  virtual int handle_redo (void);

  virtual int handle_project_properties (void);
  virtual int handle_notification_ready (void);

  virtual int handle_xml_import_begin (void);
  virtual int handle_xml_import_end (void);

  virtual int handle_xml_import_fcos_begin (void);
  virtual int handle_xml_import_fcos_end (void);

  virtual int handle_xml_import_special_begin (void);
  virtual int handle_xml_import_special_end (void);

  virtual int handle_library_attach_begin (void);
  virtual int handle_library_attach_end (void);

  /**
   * General callback for all object events. This is called before
   * the specialized methods are called for the object event.
   *
   * @param[in]       obj             Target object
   * @param[in]       mask            Event mask
   * @retval          0               Success
   * @retval          -1              Failure
   */
  virtual int handle_object_event (Object_in, unsigned long mask);

  virtual int handle_object_created (Object_in);
  virtual int handle_object_destroyed (Object_in);

  virtual int handle_object_attribute (Object_in);
  virtual int handle_object_properties (Object_in);
  virtual int handle_object_registry (Object_in);

  virtual int handle_object_relation (Object_in);
  virtual int handle_object_parent (Object_in);

  virtual int handle_instance_subtype (Object_in);

  virtual int handle_new_child (Object_in);
  virtual int handle_lost_child (Object_in);

  virtual int handle_referenced (Object_in);
  virtual int handle_referenced_release (Object_in);

  virtual int handle_object_connected (Object_in);
  virtual int handle_object_disconnected (Object_in);

  virtual int handle_set_included (Object_in);
  virtual int handle_set_excluded (Object_in);

  virtual int handle_marked_readonly (Object_in);
  virtual int handle_marked_readwrite (Object_in);

  virtual int handle_model_open (Object_in);
  virtual int handle_model_close (Object_in);

  virtual int handle_object_select (Object_in);
  virtual int handle_object_deselect (Object_in);

  virtual int handle_object_mouseover (Object_in);

protected:
  /// The mask for the event handler.
  unsigned long current_mask_;

  /// The project is in import mode.
  bool is_importing_;

  /// Event handler assigned to this implementation.
  Event_Handler * event_handler_;

  /// Destroy the event handler when it is closed.
  bool destroy_on_close_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Event_Handler_Impl.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
