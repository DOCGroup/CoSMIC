// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Sink.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_EVENT_SINK_H_
#define _GAME_MGA_EVENT_SINK_H_

#include <atlbase.h>
#include <atlcom.h>
#include <bitset>

#include "Component_export.h"
#include "game/mga/Project.h"
#include "game/mga/stlace.h"

#include "ace/Hash_Map_Manager.h"
#include "ace/Unbounded_Set.h"
#include "ace/Null_Mutex.h"

namespace GAME
{
namespace Mga
{

// Forward decl.
class Top_Level_Event_Handler;

// Forward decl.
class Global_Event_Handler;

// Forward decl.
class Object_Event_Handler;

/**
 * @class Event_Sink
 *
 * The actual implementation of the event handler. This class
 * acts as a bridge between GME and the event sinks.
 */
class GAME_MGA_COMPONENT_Export Event_Sink :
  public ATL::CComObjectRootEx <ATL::CComSingleThreadModel>,
  public IMgaEventSink
{
public:
  /// Default constructor.
  Event_Sink (void);

  /// Destructor.
  virtual ~Event_Sink (void);

  /**
   * Initialize the event handler.
   *
   * @param[in]       proj          The source project
   */
  int initialize (Project project);

  /// Close the event sink.
  void close (void);

  /**
   * Attach the event handler to an implementation.
   *
   * @param[in]       impl          The target implementation
   */
  void set_event_handler (Top_Level_Event_Handler * impl = 0);

  /**
   * Register a global event handler.
   *
   * @param[in]       handler         Pointer to event handler
   */
  int register_handler (Global_Event_Handler * handler);

  /**
   * Register event handler for the specified meta_metatype. If an event
   * occurs for the specfied meta_metatype and the event handler registers
   * for the event type, then the event handler is invoked.
   *
   * @param[in]      metatype      Type to register for
   * @param[in]      eh            Pointer to the event handler
   */
  int register_handler (size_t metatype,
                        Object_Event_Handler * eh);

  /**
   * Register event handler for the specified type. If an event
   * occurs for the specfied type and the event handler registers
   * for the event type, then the event handler is invoked.
   *
   * @param[in]       metaname      Type to register for
   * @param[in]       eh            Pointer to the event handler
   */
  int register_handler (const std::string & metaname,
                        Object_Event_Handler * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int register_handler (const Meta::Base_in meta,
                        Object_Event_Handler * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int register_handler (const Object_in obj, Object_Event_Handler * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int unregister_handler (const Object_in obj, Object_Event_Handler * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int unregister_handler (Global_Event_Handler * eh);

  /// Unregister all handlers for an instance.
  int unregister_all (const Object_in obj);

  /**
   * Set the enable state of the event handler. If \a enable is
   * true, then the event handler will process events. If \a enable
   * is false, then the event handler will not process events.
   *
   * @param[in]       state         The enable state
   */
  void enable (bool state);

  STDMETHOD (GlobalEvent) (globalevent_enum event);
  STDMETHOD (ObjectEvent) (IMgaObject * obj, unsigned long eventmask, VARIANT v);

  BEGIN_COM_MAP (Event_Sink)
    COM_INTERFACE_ENTRY (IMgaEventSink)
    COM_INTERFACE_ENTRY (IUnknown)
  END_COM_MAP ()

private:
  static const unsigned long BITMASK_SIZE = 32;

  /// Type definition for a set of event handlers.
  typedef ACE_Unbounded_Set <Object_Event_Handler *> handler_set;

  static int dispatch_global_event (long global_event,
                                    Global_Event_Handler * eh);

  static int dispatch_object_event (Object_in obj,
                                    unsigned long mask,
                                    const handler_set & handlers);

  static int dispatch_object_event (Object_in obj,
                                    unsigned long mask,
                                    Object_Event_Handler * eh);

  /// Insert a new global event handler.
  int insert_into_global_handlers (Global_Event_Handler * eh);

  /// Remove an existing global event handler.
  int remove_from_global_handlers (Global_Event_Handler * eh);

  /// Pointer to the actual implementation.
  Top_Level_Event_Handler * impl_;

  /// The enable state for the event handler.
  bool enable_;

  // Global collection of registered handlers.
  typedef
    ACE_Hash_Map_Manager_Ex <Global_Event_Handler *,
                             size_t,
                             ACE_Hash <void *>,
                             ACE_Equal_To <Global_Event_Handler *>,
                             ACE_Null_Mutex>
                             global_handler_map_t;

  global_handler_map_t global_handlers_;

  /// Collection of event handlers registered by type.
  ACE_Hash_Map_Manager <Meta::Base,
                        handler_set *,
                        ACE_Null_Mutex>
                        type_handlers_;

  /// Collection of event handlers registered by metatype.
  std::vector <handler_set> meta_handlers_;

  /// Collection of event handlers registered by instance.
  ACE_Hash_Map_Manager <Object,
                        handler_set *,
                        ACE_Null_Mutex>
                        inst_handlers_;

  /// The current project for the event handler.
  Project project_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Event_Sink.inl"
#endif

#endif  // !defined _GAME_MGA_EVENT_SINK_H_
