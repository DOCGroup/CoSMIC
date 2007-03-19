// $Id$

#include "ComponentEx.h"
#include "FCO.h"

namespace GME
{
  //
  // ComponentEx
  //
  ComponentEx::ComponentEx (void)
  {

  }

  //
  // ~ComponentEx
  //
  ComponentEx::~ComponentEx (void)
  {

  }

  //
  // parameter
  //
  void ComponentEx::parameter (const std::string & param,
                               const std::string & value)
  {
    CComBSTR bstr_param (param.length (), param.c_str ());
    CComVariant variant (value.c_str ());

    VERIFY_HRESULT (
      this->impl ()->put_ComponentParameter (bstr_param, variant));
  }

  //
  // invoke
  //
  void ComponentEx::invoke (Project & project,
                            FCO & current,
                            std::vector <FCO> & selected,
                            long param)
  {
    VERIFY_HRESULT (this->impl ()->InvokeEx (project, current, 0, param));
  }

  //
  // impl
  //
  IMgaComponentEx * ComponentEx::impl (void) const
  {
    if (this->component_ex_.p != this->component_.p)
      VERIFY_HRESULT (this->component_.QueryInterface (&this->component_ex_));

    return this->component_ex_;
  }
}
