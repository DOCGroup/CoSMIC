// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Sink_Impl.h
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
#include "game/Object.h"
#include "game/stlace.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Unbounded_Set.h"
#include "ace/Null_Mutex.h"
#include "BE_export.h"

namespace GAME
{
// Forward decl.
class Event_Handler_Impl;

// Forward decl.
class Project;

/**
 * @class Event_Handler
 *
 * The actual implementation of the event handler. This class
 * acts as a bridge between GME and the event sinks.
 */
class GAME_BE_Export Event_Handler :
  public ATL::CComObjectRootEx <ATL::CComSingleThreadModel>,
  public IMgaEventSink
{
public:
  /// Default constructor.
  Event_Handler (Event_Handler_Impl * impl = 0);

  /// Destructor.
  virtual ~Event_Handler (void);

  int initialize (GAME::Project & project);

  /**
   * Attach the event handler to an implementation.
   *
   * @param[in]       impl          The target implementation
   */
  void attach (Event_Handler_Impl * impl = 0);

  /**
   * Register event handler for the specified type. If an event
   * occurs for the specfied type and the event handler registers
   * for the event type, then the event handler is invoked.
   *
   * @param[in]       metaname      Type to register for
   * @param[in]       eh            Pointer to the event handler
   */
  int register_handler (const std::string & metaname, Event_Handler_Impl * eh);

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
  /// Type definition for a set of event handlers.
  typedef ACE_Unbounded_Set <Event_Handler_Impl *> handler_set;

  int dispatch_object_event (Object obj,
                             unsigned long mask,
                             const handler_set & handlers);

  static int dispatch_object_event (Object obj,
                                    unsigned long mask,
                                    Event_Handler_Impl * const eh);


  /// Pointer to the actual implementation.
  Event_Handler_Impl * impl_;

  /// The enable state for the event handler.
  bool enable_;

  /// Collection of event handlers registered by type.
  ACE_Hash_Map_Manager <std::string,
                        handler_set *,
                        ACE_Null_Mutex>
                        type_handlers_;
};

}

#if defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
