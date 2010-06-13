// -*- C++ -*-

//=============================================================================
/**
 * @file        Addon_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_ADDON_T_H_
#define _GME_ADDON_T_H_

#include "StdAfx.h"
#include "game/config.h"

namespace GAME
{

/**
 * @class Addon_T
 *
 * Wrapper class for interfacing the add-on with GME/COM. The T
 * parameters the actual implementation.
 */
template <typename T, const CLSID * pclsid = &CLSID_NULL>
class ATL_NO_VTABLE Addon_T :
  public ATL::CComObjectRootEx <ATL::CComSingleThreadModel>,
  public ATL::CComCoClass < Addon_T <T, pclsid>, pclsid >,
  public IMgaComponentEx,
  public IMgaVersionInfo
{
public:
  /// Default constructor.
  Addon_T (void);

  /// Destructor.
  virtual ~Addon_T (void);

  /// Type definition of this class.
  typedef Addon_T <T, pclsid> addon_t;

  DECLARE_PROTECT_FINAL_CONSTRUCT ()
  DECLARE_NO_REGISTRY ()

  // COM MAP
  BEGIN_COM_MAP (addon_t)
    COM_INTERFACE_ENTRY (IMgaComponent)
    COM_INTERFACE_ENTRY (IMgaComponentEx)
    COM_INTERFACE_ENTRY (IMgaVersionInfo)
  END_COM_MAP ()

  // IMgaComponent interface
  STDMETHOD (Initialize) (IMgaProject * proj);
  STDMETHOD (Invoke) (IMgaProject * proj, IMgaFCOs * selected, long flags);
  STDMETHOD (InvokeEx) (IMgaProject * proj, IMgaFCO * current, IMgaFCOs * selected, long flags);
  STDMETHOD (ObjectsInvokeEx) (IMgaProject *, IMgaObject *, IMgaObjects *, long);
  STDMETHOD (Enable) (VARIANT_BOOL enable);

  STDMETHOD (get_InteractiveMode) (VARIANT_BOOL * mode);
  STDMETHOD (put_InteractiveMode) (VARIANT_BOOL mode);
  STDMETHOD (get_ComponentName) (BSTR * name);
  STDMETHOD (get_ComponentType) (componenttype_enum * type);
  STDMETHOD (get_Paradigm) (BSTR * paradigm);

  // IMgaComponentEx interface
  STDMETHOD (get_ComponentProgID) (BSTR *pVal);
  STDMETHOD (put_ComponentParameter) (BSTR name, VARIANT newVal);
  STDMETHOD (get_ComponentParameter) (BSTR name, VARIANT *pVal);

  // IMgaVersionInfo interface
  STDMETHOD (get_version) (MgaInterfaceVersion_enum *pVal);

private:
  /// The actual implementation for the add-on.
  T impl_;

  ::ATL::CComPtr <IMgaEventSink> sink_;

  ::ATL::CComPtr <IMgaAddOn> addon_;
};
}

#define DECLARE_ADDON(type, impl) \
  typedef GAME::Addon_T <impl, &CLSID_##type> impl##_AutoImpl; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_AutoImpl)

#if defined (__GAME_INLINE__)
#include "Addon_T.inl"
#endif

#include "Addon_T.cpp"

#endif  // !defined _GME_RAW_COMPONENT_I_H_
