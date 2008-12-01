// $Id$

#if !defined (__GME_INLINE__)
#include "Interpreter_T.inl"
#endif

#include "../Collection_T.h"

//
// get_InteractiveMode
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
get_InteractiveMode (VARIANT_BOOL * mode)
{
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
STDMETHODIMP GME::Interpreter_T <T, IMPL>::get_ComponentName (BSTR * name)
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
STDMETHODIMP GME::Interpreter_T <T, IMPL>::get_Paradigm (BSTR * paradigm)
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
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
Invoke (IMgaProject * proj, IMgaFCOs * fcos, long flags)
{
  try
  {
    GME::Project project (proj);

    try
    {
      GME::Collection_T <GME::FCO> selected (fcos);

      // Begin a new transaction.
      if (this->impl_.is_managed ())
        project.begin_transaction ();

      int retval = this->impl_.invoke (project, selected, flags);

      // Commit the transaction.
      if (retval == 0 && this->impl_.is_managed ())
        project.commit_transaction ();

      return retval == 0 ? S_OK : S_FALSE;
    }
    catch (const GME::Exception &)
    {
      // Abort the transaction.
      if (this->impl_.is_managed ())
        project.abort_transaction ();
    }
  }
  catch (const GME::Exception &)
  {

  }

  return S_FALSE;
}

//
// InvokeEx
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
InvokeEx (IMgaProject * proj, IMgaFCO * fco, IMgaFCOs * select, long flags)
{
  try
  {
    GME::Project project (proj);

    try
    {
      GME::FCO current (fco);
      GME::Collection_T <GME::FCO> selected (select);

      // Begin a new transaction for the process.
      if (this->impl_.is_managed ())
        project.begin_transaction ();

      // Pass control to the implemention.
      int retval = this->impl_.invoke_ex (project, current, selected, flags);

      // Commit the transaction.
      if (retval == 0 && this->impl_.is_managed ())
        project.commit_transaction ();

      return retval == 0 ? S_OK : S_FALSE;
    }
    catch (const GME::Exception &)
    {
      // Abort the tranaction.
      if (this->impl_.is_managed ())
        project.abort_transaction ();
    }
  }
  catch (const GME::Exception &)
  {

  }

  return S_FALSE;
}

//
// ObjectsInvokeEx
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
ObjectsInvokeEx (IMgaProject * proj, IMgaObject * obj, IMgaObjects * objs, long flags)
{
  try
  {
    GME::Project project (proj);

    try
    {
      GME::Object object (obj);
      GME::Collection_T <GME::Object> objects (objs);

      // Start a new transaction.
      if (this->impl_.is_managed ())
        project.begin_transaction ();

      int retval = this->impl_.invoke_object_ex (project, object, objects, flags);

      // Commit the transaction.
      if (retval == 0 && this->impl_.is_managed ())
        project.commit_transaction ();

      return retval == 0 ? S_OK : S_FALSE;
    }
    catch (const GME::Exception &)
    {
      if (this->impl_.is_managed ())
        project.abort_transaction ();
    }
  }
  catch (const GME::Exception &)
  {

  }

  return S_FALSE;
}

//
// get_ComponentProgID
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::get_ComponentProgID (BSTR * val)
{
  std::string temp = this->impl_.progid ();

  CComBSTR progid (temp.length (), temp.c_str ());
  return progid.CopyTo (val);
}
