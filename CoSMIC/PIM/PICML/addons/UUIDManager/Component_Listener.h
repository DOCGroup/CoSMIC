// -*- C++ -*-

//=============================================================================
/**
 * @file      Component_Listener
 *
 * $Id$
 *
 * [insert description here]
 *
 * @author    James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _PICML_ADDON_COMPONENT_LISTENER_H_
#define _PICML_ADDON_COMPONENT_LISTENER_H_

#include "ComponentLib.h"

//=============================================================================
/**
 * @class Component_Listener
 */
//=============================================================================

class Component_Listener :
  public CComObjectRoot,
  public IMgaEventSink
{
public:
  /// Constructor.
  Component_Listener (void);

  /// Destructor.
  virtual ~Component_Listener (void);

  IMgaTerritory * territory (IMgaTerritory * territory);

  bool listen_to_object (IMgaObject * object);

  /// Global event handler routine.
  STDMETHOD (GlobalEvent) (globalevent_enum event);

  /// Object event handler routine.
  STDMETHOD (ObjectEvent) (IMgaObject * obj,
                           unsigned long eventmask,
                           VARIANT v);

  DECLARE_PROTECT_FINAL_CONSTRUCT ();

  /// Interface map used by <QueuyInterface>.
  BEGIN_COM_MAP (Component_Listener)
    COM_INTERFACE_ENTRY (IMgaEventSink)
  END_COM_MAP ()

private:
  void manage_uuid (IMgaFCO * fco);

  CComPtr <IMgaTerritory> territory_;

  CInterfaceList <IMgaObject> objects_;
};

#endif  // !defined _PICML_ADDON_COMPONENT_LISTENER_H_
