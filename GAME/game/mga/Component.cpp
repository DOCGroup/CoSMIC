// $Id$

#include "stdafx.h"
#include "mga.h"

#include "Component.h"

#if !defined (__GAME_INLINE__)
#include "Component.inl"
#endif

#include "FCO.h"
#include "Set.h"

namespace GAME
{
namespace Mga
{

//
// load
//
Component Component_Impl::_load (const std::string & progid)
{
  CComBSTR temp (progid.length (), progid.c_str ());
  CComPtr <IMgaComponent> component;

  VERIFY_HRESULT (component.CoCreateInstance (temp));

  return component.p;
}

//
// name
//
std::string Component_Impl::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->component_->get_ComponentName (&bstr));

  CW2CT tempstr (bstr);
  return tempstr.m_psz;
}

//
// type
//
componenttype_enum Component_Impl::type (void) const
{
  componenttype_enum type;
  VERIFY_HRESULT (this->component_->get_ComponentType (&type));

  return type;
}

//
// enable
//
void Component_Impl::enable (bool state)
{
  VARIANT_BOOL enabled = state ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->component_->Enable (enabled));
}

//
// interative
//
bool Component_Impl::interactive (void) const
{
  VARIANT_BOOL enabled;
  VERIFY_HRESULT (this->component_->get_InteractiveMode (&enabled));

  return enabled == VARIANT_TRUE ? true : false;
}

//
// interative
//
void Component_Impl::interactive (bool flag)
{
  VARIANT_BOOL enabled = flag ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->component_->put_InteractiveMode (enabled));
}

//
// registered_paradigm
//
std::string Component_Impl::registered_paradigm (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->component_->get_Paradigm (&bstr));

  CW2CT tempstr (bstr);
  return tempstr.m_psz;
}

//
// invoke
//
void Component_Impl::invoke (Project project,
                        const std::vector <FCO> & selected,
                        long param)
{
  // Allocate a collection of MgaFCOs.
  CComBSTR progid ("Mga.MgaFCOs");
  CComPtr <IMgaFCOs> selected_raw;
  VERIFY_HRESULT (selected_raw.CoCreateInstance (progid));

  // Insert the selected FCOs into the collection.
  std::vector <FCO>::const_iterator
    iter = selected.begin (), iter_end = selected.end ();

  for ( ; iter != iter_end; ++ iter)
    VERIFY_HRESULT (selected_raw->Insert ((*iter)->impl (), 0));

  VERIFY_HRESULT (this->component_->Invoke (project.impl (), selected_raw, param));
}

//
// initialize
//
void Component_Impl::initialize (Project project)
{
  VERIFY_HRESULT (this->component_->Initialize (project.impl ()));
}

}
}
