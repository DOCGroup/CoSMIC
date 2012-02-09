// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaBase.h"
#include "MetaConstraint.h"

#if !defined (__GAME_INLINE__)
#include "MetaBase.inl"
#endif

#include "Collection_T.h"
#include "MetaProject.h"
#include "Exception.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// name
//
std::string Base_Impl::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->metabase_->get_Name (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// name
//
void Base_Impl::name (const std::string & name)
{
  CComBSTR bstr (name.length (), name.c_str ());
  VERIFY_HRESULT (this->metabase_->put_Name (bstr));
}

//
// display_name
//
std::string Base_Impl::display_name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->metabase_->get_DisplayedName (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// display_name
//
void Base_Impl::display_name (const std::string & name)
{
  CComBSTR bstr (name.length (), name.c_str ());
  VERIFY_HRESULT (this->metabase_->put_DisplayedName (bstr));
}

//
// refid
//
long Base_Impl::refid (void) const
{
  long refid;
  VERIFY_HRESULT (this->metabase_->get_MetaRef (&refid));

  return refid;
}

//
// refid
//
void Base_Impl::refid (long refid)
{
  VERIFY_HRESULT (this->metabase_->put_MetaRef (refid));
}

//
// type
//
objtype_enum Base_Impl::type (void) const
{
  objtype_enum type;
  VERIFY_HRESULT (this->metabase_->get_ObjType (&type));

  return type;
}

//
// constraints
//
size_t Base_Impl::constraints (std::vector <Constraint> & cons) const
{
  CComPtr <IMgaConstraints> temps;
  VERIFY_HRESULT (this->impl ()->get_Constraints (&temps));

  return iter_to_collection (temps.p, cons);
}

//
// destroy
//
void Base_Impl::destroy (void)
{
  VERIFY_HRESULT (this->metabase_->Delete ());
  this->metabase_.Release ();
}

//
// registry_value
//
std::string Base_Impl::
registry_value (const std::string & path) const
{
  CComBSTR bstrval;
  CComBSTR bstrpath (path.length (), path.c_str ());

  VERIFY_HRESULT (this->metabase_->get_RegistryValue (bstrpath, &bstrval));

  if (!bstrval)
    return "";

  CW2A tempstr (bstrval);
  return tempstr.m_psz;
}

//
// registry_value
//
void Base_Impl::registry_value (const std::string & path, const std::string & value)
{
  CComBSTR bstrpath (path.length (), path.c_str ());
  CComBSTR bstrval (value.length (), value.c_str ());

  VERIFY_HRESULT (this->metabase_->put_RegistryValue (bstrpath, bstrval));
}

//
// project
//
Project Base_Impl::project (void) const
{
  CComPtr <IMgaMetaProject> proj;
  VERIFY_HRESULT (this->metabase_->get_MetaProject (&proj));

  return proj.p;
}

}
}
}
