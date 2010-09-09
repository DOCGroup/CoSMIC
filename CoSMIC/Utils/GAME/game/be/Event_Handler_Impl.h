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
// Forward decl.
class Project;

// Forward decl.
class Event_Handler;

/**
 * @class Event_Handler_Impl
 *
 * Base class implementation for the event sink.
 */
class GAME_BE_Export Event_Handler_Impl :
  public Event_Handler_Interface
{
public:
  /// Default constructor.
  Event_Handler_Impl (void);

  /**
   * Initializing constructor
   *
   * @param[in]       mask            Event handler's mask.
   */
  Event_Handler_Impl (long mask);

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
  virtual int initialize (GAME::Project & project);

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
  virtual int handle_object_event (Object & obj, unsigned long mask);

  virtual int handle_object_created (GAME::Object obj);
  virtual int handle_object_destroyed (Object obj);

  virtual int handle_object_attribute (Object obj);
  virtual int handle_object_properties (Object obj);
  virtual int handle_object_registry (Object obj);

  virtual int handle_object_relation (Object obj);
  virtual int handle_object_parent (Object obj);

  virtual int handle_instance_subtype (Object obj);

  virtual int handle_new_child (Object obj);
  virtual int handle_lost_child (Object obj);

  virtual int handle_referenced (Object obj);
  virtual int handle_referenced_release (Object obj);

  virtual int handle_object_connected (Object obj);
  virtual int handle_object_disconnected (Object obj);

  virtual int handle_set_included (Object obj);
  virtual int handle_set_excluded (Object obj);

  virtual int handle_marked_readonly (Object obj);
  virtual int handle_marked_readwrite (Object obj);

  virtual int handle_model_open (Object obj);
  virtual int handle_model_close (Object obj);

  virtual int handle_object_select (Object obj);
  virtual int handle_object_deselect (Object obj);

  virtual int handle_object_mouseover (Object obj);

protected:
  /// The mask for the event handler.
  long current_mask_;

  /// The project is in import mode.
  bool is_importing_;

  /// Event handler assigned to this implementation.
  Event_Handler * event_handler_;
};

}

#if defined (__GAME_INLINE__)
#include "Event_Handler_Impl.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
