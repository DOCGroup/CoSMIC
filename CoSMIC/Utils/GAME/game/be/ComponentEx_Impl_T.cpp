// $Id$

#if !defined (__GAME_INLINE__)
#include "ComponentEx_Impl_T.inl"
#endif

#include "game/Project.h"
#include "game/FCO.h"

namespace GAME
{
//
// Initialize
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::Initialize (IMgaProject * proj)
{
  return this->impl_.initialize (Project (proj));
}

//
// Invoke
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
Invoke (IMgaProject * proj, IMgaFCOs * fcos, long flags)
{
  std::vector <FCO> selected;
  GAME::get_children (fcos, selected);

  return this->impl_.invoke (Project (proj), selected, flags);
}

//
// InvokeEx
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
InvokeEx (IMgaProject * proj, IMgaFCO * current, IMgaFCOs * fcos, long flags)
{
  std::vector <FCO> selected;
  GAME::get_children (fcos, selected);

  return this->impl_.invoke_ex (Project (proj), FCO (current), selected, flags);
}

//
// Enable
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::Enable (VARIANT_BOOL enable)
{
  bool flag = enable == VARIANT_TRUE ? true : false;
  this->impl_.enable (flag);

  return S_OK;
}

//
// get_InteractiveMode
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::get_InteractiveMode (VARIANT_BOOL * mode)
{
  if (mode == 0)
    return E_POINTER;

  *mode = this->impl_.interactive () ? VARIANT_TRUE : VARIANT_FALSE;
  return S_OK;
}

//
// put_InteractiveMode
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::put_InteractiveMode (VARIANT_BOOL mode)
{
  bool value = mode == VARIANT_TRUE ? true : false;
  this->impl_.interactive (value);

  return S_OK;
}

//
// get_ComponentName
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::get_ComponentName (BSTR * name)
{
  if (name == 0)
    return E_POINTER;

  const std::string n (this->impl_.name ());
  ATL::CComBSTR bstr (n.length (), n.c_str ());
  *name = bstr.Detach ();

  return S_OK;
}

//
// get_ComponentType
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::get_ComponentType (componenttype_enum * type)
{
  if (type == 0)
    return E_POINTER;

  //*type = this->impl_.type ();
  return S_OK;
}

//
// get_Paradigm
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::get_Paradigm (BSTR * paradigm)
{
  if (paradigm == 0)
    return E_POINTER;

  const std::string n (this->impl_.paradigm ());
  ATL::CComBSTR bstr (n.length (), n.c_str ());
  *paradigm = bstr.Detach ();

  return S_OK;
}

//
// ObjectsInvokeEx
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
ObjectsInvokeEx (IMgaProject *, IMgaObject *, IMgaObjects *, long)
{
  return S_OK;
}

//
// get_ComponentProgID
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::get_ComponentProgID (BSTR * progid)
{
  if (progid == 0)
    return E_POINTER;

  const std::string n (this->impl_.progid ());
  ATL::CComBSTR bstr (n.length (), n.c_str ());
  *progid = bstr.Detach ();

  return S_OK;
}

//
// put_ComponentParameter
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
put_ComponentParameter (BSTR name, VARIANT newVal)
{
  return S_OK;
}

//
// get_ComponentParameter
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
get_ComponentParameter (BSTR name, VARIANT *pVal)
{
  return S_OK;
}

//
// get_version
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
get_version (MgaInterfaceVersion_enum *pVal)
{
  if (pVal == 0)
    return E_POINTER;

  *pVal = MgaInterfaceVersion_Current;
  return S_OK;
}

}
