// -*- C++ -*-

//=============================================================================
/**
 * @file        ComponentEx_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_RAW_COMPONENT_I_H_
#define _GME_RAW_COMPONENT_I_H_

#include "StdAfx.h"
#include "game/config.h"

namespace GAME
{
/**
 * @class ComponentEx_T
 */
template <typename T, const CLSID * pclsid = &CLSID_NULL>
class ATL_NO_VTABLE ComponentEx_T :
  public ATL::CComObjectRootEx <ATL::CComSingleThreadModel>,
  public ATL::CComCoClass < T, pclsid>,
  public IMgaComponentEx,
  public IMgaVersionInfo
{
public:
  /// Default constructor.
  ComponentEx_T (void);

  /// Destructor.
  virtual ~ComponentEx_T (void);

  DECLARE_PROTECT_FINAL_CONSTRUCT ()
  DECLARE_NO_REGISTRY ()

  // IMgaComponent interface
  STDMETHOD (Initialize) (IMgaProject * proj);
  STDMETHOD (Invoke) (IMgaProject * proj, IMgaFCOs * selected, long flags);
  STDMETHOD (Enable) (VARIANT_BOOL enable);
  STDMETHOD (get_InteractiveMode) (VARIANT_BOOL * mode);
  STDMETHOD (put_InteractiveMode) (VARIANT_BOOL mode);
  STDMETHOD (get_ComponentName) (BSTR * name);
  STDMETHOD (get_ComponentType) (componenttype_enum * type);
  STDMETHOD (get_Paradigm) (BSTR * paradigm);

  // IMgaComponentEx interface
  STDMETHOD (InvokeEx) (IMgaProject * proj, IMgaFCO * current, IMgaFCOs * selected, long flags);
  STDMETHOD (ObjectsInvokeEx) (IMgaProject *, IMgaObject *, IMgaObjects *, long);
  STDMETHOD (get_ComponentProgID) (BSTR *pVal);
  STDMETHOD (put_ComponentParameter) (BSTR name, VARIANT newVal);
  STDMETHOD (get_ComponentParameter) (BSTR name, VARIANT *pVal);

  // IMgaVersionInfo interface
  STDMETHOD (get_version) (MgaInterfaceVersion_enum *pVal);

  BEGIN_COM_MAP (T)
    COM_INTERFACE_ENTRY (IMgaComponent)
    COM_INTERFACE_ENTRY (IMgaComponentEx)
    COM_INTERFACE_ENTRY (IMgaVersionInfo)
  END_COM_MAP ()
};
}

#if defined (__GAME_INLINE__)
#include "ComponentEx_T.inl"
#endif

#include "ComponentEx_T.cpp"

#endif  // !defined _GME_RAW_COMPONENT_I_H_
