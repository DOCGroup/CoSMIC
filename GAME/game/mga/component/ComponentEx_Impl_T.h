// -*- C++ -*-

//=============================================================================
/**
 * @file        ComponentEx_Impl_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_COMPONENT_EX_IMPL_T_H_
#define _GAME_COMPONENT_EX_IMPL_T_H_

#include "game/config.h"

namespace GAME
{
namespace Mga
{

/**
 * @class ComponentEx_T
 *
 * Wrapper class that implements the interface for an extended component.
 * The calls on the interface are delegated to the element of type T,
 * which must derive from at least IMgaComponentEx and IMgaVersionInfo.
 */
template <typename T>
class ComponentEx_Impl_T :
  public ATL::CComObjectRootEx <ATL::CComSingleThreadModel>,
  public IMgaComponentEx,
  public IGMEVersionInfo
{
public:
  /// Type definition of the component type.
  typedef T type;

  /// Default constructor.
  ComponentEx_Impl_T (void);

  /// Destructor.
  virtual ~ComponentEx_Impl_T (void);

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
  STDMETHOD (get_version) (GMEInterfaceVersion_enum *pVal);

protected:
  /// The component's implementation.
  T impl_;

private:
  typedef ComponentEx_Impl_T <T> self_t;

  BEGIN_COM_MAP (self_t)
    COM_INTERFACE_ENTRY (IMgaComponent)
    COM_INTERFACE_ENTRY (IMgaComponentEx)
    COM_INTERFACE_ENTRY (IGMEVersionInfo)
  END_COM_MAP ()
};

}
}

#if defined (__GAME_INLINE__)
#include "ComponentEx_Impl_T.inl"
#endif

#include "ComponentEx_Impl_T.cpp"

#endif  // !defined _GME_RAW_COMPONENT_I_H_
