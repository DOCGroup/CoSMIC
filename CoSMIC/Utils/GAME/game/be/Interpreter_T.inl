// $Id$

#include "game/Project.h"

//
// Interpreter_T
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
GAME::Interpreter_T <T, pclsid>::Interpreter_T (void)
{

}

//
// ~Interpreter_T
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
GAME::Interpreter_T <T, pclsid>::~Interpreter_T (void)
{

}

//
// get_ComponentType
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP GAME::Interpreter_T <T, pclsid>::
get_ComponentType (componenttype_enum * type)
{
  if (type == 0)
    return E_POINTER;

  *type = COMPONENTTYPE_INTERPRETER;
  return S_OK;
}

//
// put_ComponentParameter
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP GAME::Interpreter_T <T, pclsid>::
put_ComponentParameter (BSTR name, VARIANT newVal)
{
  return S_OK;
}

//
// get_ComponentParameter
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP GAME::Interpreter_T <T, pclsid>::
get_ComponentParameter (BSTR name, VARIANT *pVal)
{
  return S_OK;
}
