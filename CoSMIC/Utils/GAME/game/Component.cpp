// $Id$

#include "stdafx.h"
#include "Component.h"

#if !defined (__GAME_INLINE__)
#include "Component.inl"
#endif

#include "FCO.h"
#include "Set.h"

namespace GAME
{
//
// load
//
Component Component::_load (const std::string & progid)
{
  CComBSTR temp (progid.length (), progid.c_str ());

  Component component;
  VERIFY_HRESULT (component.component_.CoCreateInstance (temp));

  return component;
}

//
// name
//
std::string Component::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->component_->get_ComponentName (&bstr));

  CW2CT tempstr (bstr);
  return tempstr.m_psz;
}

//
// type
//
componenttype_enum Component::type (void) const
{
  componenttype_enum type;
  VERIFY_HRESULT (this->component_->get_ComponentType (&type));

  return type;
}

//
// interative
//
bool Component::interative (void) const
{
  VARIANT_BOOL enabled;
  VERIFY_HRESULT (this->component_->get_InteractiveMode (&enabled));

  return enabled == VARIANT_TRUE ? true : false;
}

//
// interative
//
void Component::interative (bool flag)
{
  VARIANT_BOOL enabled = flag ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->component_->put_InteractiveMode (enabled));
}

//
// registered_paradigm
//
std::string Component::registered_paradigm (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->component_->get_Paradigm (&bstr));

  CW2CT tempstr (bstr);
  return tempstr.m_psz;
}

//
// invoke
//
void Component::invoke (Project & project,
                        std::vector <FCO> & selected,
                        long param)
{
  CComBSTR progid ("Mga.MgaFCOs");
  CComPtr <IMgaFCOs> selected_raw;
  VERIFY_HRESULT (selected_raw.CoCreateInstance (progid));

  std::vector <GAME::FCO>::const_iterator
    iter = selected.begin (), iter_end = selected.end ();

  for ( ; iter != iter_end; ++ iter)
    VERIFY_HRESULT (selected_raw->Insert (iter->impl (), 0));

  VERIFY_HRESULT (this->component_->Invoke (project.impl (), selected_raw, param));
}

//
// initialize
//
void Component::initialize (Project & project)
{
  VERIFY_HRESULT (this->component_->Initialize (project.impl ()));
}

}
