// $Id$

#if !defined (__GAME_INLINE__)
#include "ComponentEx_Impl_T.inl"
#endif

#include "Console_Service.h"

#include "game/mga/Project.h"
#include "game/mga/FCO.h"
#include "game/mga/Collection_T.h"
#include "game/mga/Transaction.h"

namespace GAME
{
namespace Mga
{

//
// Initialize
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::Initialize (IMgaProject * proj)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    Project project (proj);

    try
    {
      // First, initialize the console service. This will allow this
      // component to send messages to the user via the GME console.
      GME_CONSOLE_SERVICE->initialize (project);
    }
    catch (const Failed_Result & ex)
    {
      // Re-throw the exception if it was not the name not found
      // exception, which happens only with add-ons.
      if (ex.value () != E_MGA_NAME_NOT_FOUND)
        throw;
    }

    // Now, we can pass control to the implementation.
    return this->impl_.initialize (project);
  }
  catch (const Exception & ex)
  {
    ::AfxMessageBox (ex.message ().c_str ());
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// Invoke
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
Invoke (IMgaProject * proj, IMgaFCOs * fcos, long flags)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    std::vector <FCO> selected;
    GAME::Mga::iter_to_collection (fcos, selected);

    return this->impl_.invoke (Project (proj), selected, flags);
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// InvokeEx
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
InvokeEx (IMgaProject * proj, IMgaFCO * current, IMgaFCOs * fcos, long flags)
{
  try
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    // This transaction is need so we can get the correct implementation
    // type on our end.
    Project project (proj);
    Transaction t_readonly (project);

    FCO curr (current);

    std::vector <FCO> selected;
    GAME::Mga::iter_to_collection (fcos, selected);

    // We need to commit this transaction so the implementation can
    // create its own transaction. In the future, the implementation
    // will be able to control the type of transaction to create, as
    // well as whether to commit it before making the upcall.
    t_readonly.commit ();

    return this->impl_.invoke_ex (project, curr, selected, flags);
  }
  catch (Exception & ex)
  {
    ::AfxMessageBox (ex.message ().c_str ());
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// Enable
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::Enable (VARIANT_BOOL enable)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    bool flag = enable == VARIANT_TRUE ? true : false;
    this->impl_.enable (flag);

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// get_InteractiveMode
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::get_InteractiveMode (VARIANT_BOOL * mode)
{
  if (mode == 0)
    return E_POINTER;

  try
  {
    *mode = this->impl_.interactive () ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// put_InteractiveMode
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::put_InteractiveMode (VARIANT_BOOL mode)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    bool value = mode == VARIANT_TRUE ? true : false;
    this->impl_.interactive (value);

    return S_OK;
  }
  catch (...)
  {

  }
  return S_FALSE;
}

//
// get_ComponentName
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::get_ComponentName (BSTR * name)
{
  if (name == 0)
    return E_POINTER;

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    const std::string n (this->impl_.name ());
    ATL::CComBSTR bstr (n.length (), n.c_str ());
    *name = bstr.Detach ();

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
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

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    const std::string n (this->impl_.paradigm ());
    ATL::CComBSTR bstr (n.length (), n.c_str ());
    *paradigm = bstr.Detach ();

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
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

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    const std::string n (this->impl_.progid ());
    ATL::CComBSTR bstr (n.length (), n.c_str ());
    *progid = bstr.Detach ();

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// put_ComponentParameter
//
template <typename T>
STDMETHODIMP ComponentEx_Impl_T <T>::
put_ComponentParameter (BSTR name, VARIANT value)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    CComVariant var (value);
    CW2A n (name);
    CW2A v (var.bstrVal);

    return this->impl_.set_parameter (n.m_psz, v.m_psz);
  }
  catch (...)
  {

  }

  return S_FALSE;
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
get_version (GMEInterfaceVersion_enum *pVal)
{
  if (pVal == 0)
    return E_POINTER;

  *pVal = GMEInterfaceVersion_Current;
  return S_OK;
}

}
}
