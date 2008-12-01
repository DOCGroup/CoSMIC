// $Id$

#include "game/Project.h"

//
// Interpreter_T
//
template <typename T, typename IMPL>
GME_INLINE
GME::Interpreter_T <T, IMPL>::Interpreter_T (void)
{

}

//
// ~Interpreter_T
//
template <typename T, typename IMPL>
GME_INLINE
GME::Interpreter_T <T, IMPL>::~Interpreter_T (void)
{

}

//
// Initialize
//
template <typename T, typename IMPL>
GME_INLINE
STDMETHODIMP GME::Interpreter_T <T, IMPL>::Initialize (IMgaProject * proj)
{
  GME::Project project (proj);
  return this->impl_.initialize (project) == 0 ? S_OK : S_FALSE;
}

//
// Enable
//
template <typename T, typename IMPL>
GME_INLINE
STDMETHODIMP GME::Interpreter_T <T, IMPL>::Enable (VARIANT_BOOL enable)
{
  this->impl_.enable ((enable == VARIANT_TRUE) ? true : false);
  return S_OK;
}

//
// put_InteractiveMode
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
put_InteractiveMode (VARIANT_BOOL  mode)
{
  this->impl_.interactive ((mode == VARIANT_TRUE) ? true : false);
  return S_OK;
}

//
// get_ComponentType
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
get_ComponentType (componenttype_enum * type)
{
  if (type != 0)
  {
    *type = COMPONENTTYPE_INTERPRETER;
    return S_OK;
  }

  return E_POINTER;
}

//
// put_ComponentParameter
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
put_ComponentParameter (BSTR name, VARIANT newVal)
{
  return S_OK;
}

//
// get_ComponentParameter
//
template <typename T, typename IMPL>
STDMETHODIMP GME::Interpreter_T <T, IMPL>::
get_ComponentParameter (BSTR name, VARIANT *pVal)
{
  return S_OK;
}
