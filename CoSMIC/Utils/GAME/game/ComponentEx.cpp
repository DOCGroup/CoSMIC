// $Id$

#include "stdafx.h"
#include "ComponentEx.h"
#include "FCO.h"

namespace GAME
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
  // ComponentEx
  //
  ComponentEx::ComponentEx (const std::string & progid)
    : Component (progid)
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
                            std::vector <GAME::FCO> & selected,
                            long param)
  {
    CComBSTR progid ("Mga.MgaFCOs");
    CComPtr <IMgaFCOs> selected_raw;
    VERIFY_HRESULT (selected_raw.CoCreateInstance (progid));

    std::vector <GAME::FCO>::const_iterator
      iter = selected.begin (), iter_end = selected.end ();

    for ( ; iter != iter_end; ++ iter)
      VERIFY_HRESULT (selected_raw->Insert (iter->impl (), 0));

    VERIFY_HRESULT (this->impl ()->InvokeEx (project.impl (),
                                             current.impl (),
                                             selected_raw,
                                             param));
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
