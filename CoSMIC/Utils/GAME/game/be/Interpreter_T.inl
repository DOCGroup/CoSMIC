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
