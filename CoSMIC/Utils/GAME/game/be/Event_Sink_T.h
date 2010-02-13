// -*- C++ -*-

//=============================================================================
/**
 * @file        Event_Sink_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_EVENT_SINK_H_
#define _GME_EVENT_SINK_H_

#include <atlbase.h>
#include <atlcom.h>

#if !defined (__ComponentLib_h__)
#include "game/Mga.h"
#endif

#include "game/Object.h"

namespace GME
{
// Forward decl.
class Event_Sink_Impl;

/**
 * @class Event_Sink
 */
template <typename T>
class ATL_NO_VTABLE Event_Sink_T :
  public CComObjectRoot,
  public IMgaEventSink
{
public:
  /// Default constructor.
  Event_Sink_T (void);

  /// Destructor.
  virtual ~Event_Sink_T (void);

  virtual int handle_global_event (globalevent_enum global_event);

  virtual int handle_object_event (GME::Object & obj, unsigned long mask);

private:
  // IMgaEventSink interface
  STDMETHOD (GlobalEvent) (globalevent_enum);
  STDMETHOD (ObjectEvent) (IMgaObject *, unsigned long, VARIANT v);

  // COM MAP
  BEGIN_COM_MAP (T)
    COM_INTERFACE_ENTRY (IMgaEventSink)
  END_COM_MAP ()

  DECLARE_PROTECT_FINAL_CONSTRUCT ();
  DECLARE_NO_REGISTRY ();
  DECLARE_NOT_AGGREGATABLE (T);
};

}

#if defined (__GME_INLINE__)
#include "Event_Sink_T.inl"
#endif

#include "Event_Sink_T.cpp"

#endif  // !defined _GME_EVENT_SINK_T_H_
