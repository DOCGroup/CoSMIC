// $Id$

#if !defined (__GAME_INLINE__)
#include "Interpreter_T.inl"
#endif

#include "../Collection_T.h"

//
// Initialize
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::Initialize (IMgaProject * proj)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  GAME::Project project (proj);
  return this->impl_.initialize (project) == 0 ? S_OK : S_FALSE;
}

//
// get_InteractiveMode
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::
get_InteractiveMode (VARIANT_BOOL * mode)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  if (mode != 0)
  {
    *mode = this->impl_.interactive () ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
  }

  return E_POINTER;
}

//
// get_ComponentName
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::get_ComponentName (BSTR * name)
{
  // Get the name of the component.
  std::string temp = this->impl_.name ();
  ATL::CComBSTR bstr (temp.length (), temp.c_str ());
  return bstr.CopyTo (name);
}

//
// get_Paradigm
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::get_Paradigm (BSTR * paradigm)
{
  // Get the name of the component.
  std::string temp = this->impl_.paradigm ();
  ATL::CComBSTR bstr (temp.length (), temp.c_str ());
  return bstr.CopyTo (paradigm);
}

//
// Invoke
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::
Invoke (IMgaProject * proj, IMgaFCOs * fcos, long flags)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    GAME::Project project (proj);

    try
    {
      // Convert the iterator to a vector.
      std::vector <GAME::FCO> selected;
      GAME::get_children (fcos, selected);

      // Begin a new transaction.
      if (this->impl_.is_managed ())
        project.begin_transaction ();

      int retval = this->impl_.invoke (project, selected, flags);

      // Commit the transaction.
      if (retval == 0 && this->impl_.is_managed ())
        project.commit_transaction ();

      return retval == 0 ? S_OK : S_FALSE;
    }
    catch (const GAME::Exception &)
    {
      // Abort the transaction.
      if (this->impl_.is_managed ())
        project.abort_transaction ();
    }
  }
  catch (const GAME::Exception &)
  {

  }

  return S_FALSE;
}

//
// InvokeEx
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::
InvokeEx (IMgaProject * proj, IMgaFCO * fco, IMgaFCOs * select, long flags)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    GAME::Project project (proj);

    try
    {
      // Get the iterator to a collection of elements.
      std::vector <GAME::FCO> selected;
      GAME::get_children (select, selected);

      // Begin a new transaction for the process.
      if (this->impl_.is_managed ())
        project.begin_transaction ();

      // Pass control to the implemention.
      int retval = this->impl_.invoke_ex (project,
                                          GAME::FCO (fco),
                                          selected,
                                          flags);

      // Commit the transaction.
      if (retval == 0 && this->impl_.is_managed ())
        project.commit_transaction ();

      return retval == 0 ? S_OK : S_FALSE;
    }
    catch (const GAME::Exception &)
    {
      // Abort the tranaction.
      if (this->impl_.is_managed ())
        project.abort_transaction ();
    }
  }
  catch (const GAME::Exception &)
  {

  }

  return S_FALSE;
}

//
// ObjectsInvokeEx
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::
ObjectsInvokeEx (IMgaProject * proj, IMgaObject * obj, IMgaObjects * objs, long flags)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    GAME::Project project (proj);

    try
    {
      std::vector <GAME::Object> objects;
      GAME::get_children (objs, objects);

      // Start a new transaction.
      if (this->impl_.is_managed ())
        project.begin_transaction ();

      int retval = this->impl_.invoke_object_ex (project,
                                                 GAME::Object (obj),
                                                 objects,
                                                 flags);

      // Commit the transaction.
      if (retval == 0 && this->impl_.is_managed ())
        project.commit_transaction ();

      return retval == 0 ? S_OK : S_FALSE;
    }
    catch (const GAME::Exception &)
    {
      if (this->impl_.is_managed ())
        project.abort_transaction ();
    }
  }
  catch (const GAME::Exception &)
  {

  }

  return S_FALSE;
}

//
// get_ComponentProgID
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::get_ComponentProgID (BSTR * val)
{
  std::string temp = this->impl_.progid ();
  CComBSTR progid (temp.length (), temp.c_str ());
  return progid.CopyTo (val);
}

//
// Enable
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::Enable (VARIANT_BOOL enable)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  this->impl_.enable ((enable == VARIANT_TRUE) ? true : false);
  return S_OK;
}

//
// put_InteractiveMode
//
template <typename T, typename IMPL>
STDMETHODIMP GAME::Interpreter_T <T, IMPL>::
put_InteractiveMode (VARIANT_BOOL  mode)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  this->impl_.interactive ((mode == VARIANT_TRUE) ? true : false);
  return S_OK;
}
