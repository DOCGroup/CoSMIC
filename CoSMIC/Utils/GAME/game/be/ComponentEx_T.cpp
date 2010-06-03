// $Id$

#if !defined (__GAME_INLINE__)
#include "ComponentEx_T.inl"
#endif

namespace GAME
{
//
// Initialize
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::Initialize (IMgaProject * proj)
{
  return S_OK;
}

//
// Invoke
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
Invoke (IMgaProject * proj, IMgaFCOs * selected, long flags)
{
  return S_OK;
}

//
// InvokeEx
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
InvokeEx (IMgaProject * proj, IMgaFCO * current, IMgaFCOs * selected, long flags)
{
  return S_OK;
}

//
// Enable
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::Enable (VARIANT_BOOL enable)
{
  return S_OK;
}

//
// get_InteractiveMode
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::get_InteractiveMode (VARIANT_BOOL * mode)
{
  return S_OK;
}

//
// put_InteractiveMode
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
put_InteractiveMode (VARIANT_BOOL mode)
{
  return S_OK;
}

//
// get_ComponentName
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
get_ComponentName (BSTR * name)
{
  return S_OK;
}

//
// get_ComponentType
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
get_ComponentType (componenttype_enum * type)
{
  *type = COMPONENTTYPE_NONE;
  return S_OK;
}

//
// get_Paradigm
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
get_Paradigm (BSTR * paradigm)
{
  return S_OK;
}

//
// ObjectsInvokeEx
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
ObjectsInvokeEx (IMgaProject *, IMgaObject *, IMgaObjects *, long)
{
  return S_OK;
}

//
// get_ComponentProgID
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
get_ComponentProgID (BSTR *pVal)
{
  return S_OK;
}

//
// put_ComponentParameter
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
put_ComponentParameter (BSTR name, VARIANT newVal)
{
  return S_OK;
}

//
// get_ComponentParameter
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
get_ComponentParameter (BSTR name, VARIANT *pVal)
{
  return S_OK;
}

//
// get_version
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP ComponentEx_T <T, pclsid>::
get_version (MgaInterfaceVersion_enum *pVal)
{
  if (pVal != 0)
  {
    *pVal = MgaInterfaceVersion_Current;
    return S_OK;
  }

  return E_POINTER;
}
}
