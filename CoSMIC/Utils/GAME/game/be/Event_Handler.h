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

private:
  /// Pointer to the actual implementation.
  Event_Handler_Impl * impl_;

  /// The enable state for the event handler.
  bool enable_;
};

}

#if defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
