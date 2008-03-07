// $Id$

#include "stdafx.h"
#include "Component.h"

namespace GME
{
  //
  // Component
  //
  Component::Component (void)
  {

  }

  //
  // ~Component
  //
  Component::~Component (void)
  {

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
  // load
  //
  void Component::load (const std::string & progid)
  {
    CComBSTR temp (progid.length (), progid.c_str ());
    VERIFY_HRESULT (this->component_.CoCreateInstance (temp));
  }

  //
  // release
  //
  void Component::release (void)
  {
    this->component_.Release ();
  }

  //
  // invoke
  //
  void Component::invoke (Project & project, std::vector <FCO> & selected, long param)
  {
    VERIFY_HRESULT (this->component_->Invoke (project.impl (), 0, param));
  }

  //
  // initialize
  //
  void Component::initialize (Project & project)
  {
    VERIFY_HRESULT (this->component_->Initialize (project.impl ()));
  }
}
