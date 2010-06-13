// $Id$

#if !defined (__GAME_INLINE__)
#include "Addon_T.inl"
#endif

#include "Event_Handler.h"
#include "game/Project.h"

namespace GAME
{
//
// Initialize
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::Initialize (IMgaProject * proj)
{
  try
  {
    // Create a new event handler for this add-on.
    Event_Handler * handler = new CComObject <Event_Handler> ();
    handler->attach (&this->impl_);
    this->sink_.Attach (handler);

    // Register the event handler with GME.
    VERIFY_HRESULT (proj->CreateAddOn (this->sink_, &this->addon_));
    VERIFY_HRESULT (this->addon_->put_EventMask (this->impl_.event_mask ()));

    return handler->initialize (Project (proj));
  }
  catch (...)
  {
    return S_FALSE;
  }
}

//
// Addon_T
//
template <typename T, const CLSID * pclsid>
Addon_T <T, pclsid>::~Addon_T (void)
{
  if (this->addon_)
  {
    HRESULT hr = this->addon_->Destroy ();

    if (hr == S_OK)
      this->sink_.Detach ();
  }
}



template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::
Invoke (IMgaProject * proj, IMgaFCOs * selected, long flags)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::
InvokeEx (IMgaProject * proj, IMgaFCO * current, IMgaFCOs * selected, long flags)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::
ObjectsInvokeEx (IMgaProject *, IMgaObject *, IMgaObjects *, long)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::Enable (VARIANT_BOOL enable)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::get_InteractiveMode (VARIANT_BOOL * mode)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::put_InteractiveMode (VARIANT_BOOL mode)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::get_ComponentName (BSTR * name)
{
  CComBSTR bstr ("Hello, World!");
  *name = bstr.Detach ();
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::get_ComponentType (componenttype_enum * type)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::get_Paradigm (BSTR * paradigm)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::get_ComponentProgID (BSTR *pVal)
{
  return S_OK;
}

template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::
put_ComponentParameter (BSTR name, VARIANT newVal)
{
  return S_OK;
}

//
// get_ComponentParameter
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::
get_ComponentParameter (BSTR name, VARIANT *pVal)
{
  return S_OK;
}

//
// get_version
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Addon_T <T, pclsid>::
get_version (MgaInterfaceVersion_enum *pVal)
{
  if (pVal == 0)
    return E_POINTER;

  *pVal = MgaInterfaceVersion_Current;
  return S_OK;
}

}
