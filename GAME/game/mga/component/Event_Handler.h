// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Handler.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_BE_EVENT_HANDLER_H_
#define _GAME_BE_EVENT_HANDLER_H_

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
  class Event_Handler_Interface;
}
}

template <>
class ACE_Hash <GAME::Mga::Event_Handler_Interface *>
{
public:
  unsigned long operator () (const GAME::Mga::Event_Handler_Interface * t) const;
};

namespace GAME
{
namespace Mga
{

/**
 * @class Event_Handler
 *
 * The actual implementation of the event handler. This class
 * acts as a bridge between GME and the event sinks.
 */
class GAME_MGA_COMPONENT_Export Event_Handler :
  public ATL::CComObjectRootEx <ATL::CComSingleThreadModel>,
  public IMgaEventSink
{
public:
  /// Default constructor.
  Event_Handler (Event_Handler_Interface * impl = 0);

  /// Destructor.
  virtual ~Event_Handler (void);

  /**
   * Initialize the event handler.
   *
   * @param[in]       proj          The source project
   */
  int initialize (Project project);

  /**
   * Attach the event handler to an implementation.
   *
   * @param[in]       impl          The target implementation
   */
  void attach (Event_Handler_Interface * impl = 0);

  int register_global_handler (Event_Handler_Interface * eh);

  /**
   * Register event handler for the specified type. If an event
   * occurs for the specfied type and the event handler registers
   * for the event type, then the event handler is invoked.
   *
   * @param[in]       metaname      Type to register for
   * @param[in]       eh            Pointer to the event handler
   */
  int register_handler (const std::string & metaname,
                        Event_Handler_Interface * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int register_handler (const Meta::Base_in meta,
                        Event_Handler_Interface * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int register_handler (const Object_in obj, Event_Handler_Interface * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int unregister_handler (const Object_in obj, Event_Handler_Interface * eh);

  /**
   * @overload
   *
   * @param[in]       meta          The type's meta information
   * @param[in]       eh            Pointer to the event handler
   */
  int unregister_global_handler (Event_Handler_Interface * eh);

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

  BEGIN_COM_MAP (Event_Handler)
    COM_INTERFACE_ENTRY (IMgaEventSink)
    COM_INTERFACE_ENTRY (IUnknown)
  END_COM_MAP ()

  /// Close the event handler.
  void close (void);

private:
  static const unsigned long BITMASK_SIZE = 32;

  /// Type definition for a set of event handlers.
  typedef ACE_Unbounded_Set <Event_Handler_Interface *> handler_set;

  static int dispatch_global_event (long global_event,
                                    Event_Handler_Interface * eh);

  static int dispatch_object_event (Object_in obj,
                                    const std::bitset <BITMASK_SIZE> & mask,
                                    const handler_set & handlers);

  static int dispatch_object_event (Object_in obj,
                                    const std::bitset <BITMASK_SIZE> & mask,
                                    Event_Handler_Interface * eh);

  int insert_into_global_handlers (Event_Handler_Interface * eh);
  int remove_from_global_handlers (Event_Handler_Interface * eh);

  /// Pointer to the actual implementation.
  Event_Handler_Interface * impl_;

  /// The enable state for the event handler.
  bool enable_;

  // Global collection of registered handlers.
  typedef
    ACE_Hash_Map_Manager <Event_Handler_Interface *,
                          size_t,
                          ACE_Null_Mutex>
                          global_handler_map_t;

  global_handler_map_t global_handlers_;

  /// Collection of event handlers registered by type.
  ACE_Hash_Map_Manager <Meta::Base,
                        handler_set *,
                        ACE_Null_Mutex>
                        type_handlers_;

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
#include "Event_Handler.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
