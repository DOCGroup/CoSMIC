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

  void attach (Event_Handler_Impl * impl = 0);

  int initialize (GAME::Project & project);

  STDMETHOD (GlobalEvent) (globalevent_enum event);
	STDMETHOD (ObjectEvent) (IMgaObject * obj, unsigned long eventmask, VARIANT v);

  BEGIN_COM_MAP (Event_Handler)
    COM_INTERFACE_ENTRY (IMgaEventSink)
    COM_INTERFACE_ENTRY (IUnknown)
  END_COM_MAP ()

private:
  /// Pointer to the actual implementation.
  Event_Handler_Impl * impl_;
};

}

#if defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

#endif  // !defined _GME_EVENT_SINK_IMPL_H_
