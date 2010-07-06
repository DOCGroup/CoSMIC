// $Id$

#include "stdafx.h"
#include "ComponentEx.h"

#if !defined (__GAME_INLINE__)
#include "ComponentEx.inl"
#endif

#include "FCO.h"

namespace GAME
{
//
// _load
//
ComponentEx ComponentEx::_load (const std::string & progid)
{
  CComPtr <IMgaComponentEx> ptr;
  CA2W tempstr (progid.c_str ());

  VERIFY_HRESULT (ptr.CoCreateInstance (tempstr));
  return ptr.p;
}

//
// parameter
//
void ComponentEx::parameter (const std::string & param,
                             const std::string & value)
{
  CComBSTR bstr_param (param.length (), param.c_str ());
  CComVariant variant (value.c_str ());

  VERIFY_HRESULT (this->impl ()->put_ComponentParameter (bstr_param, variant));
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
// progid
//
std::string ComponentEx::progid (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->impl ()->get_ComponentProgID (&bstr));

  CW2A temp (bstr);
  return temp.m_psz;
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

//
// operator ->
//
IMgaComponentEx * ComponentEx::operator -> (void) const
{
  return this->impl ();
}

}
