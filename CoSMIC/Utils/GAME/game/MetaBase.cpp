// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaBase.h"

#if !defined (__GAME_INLINE__)
#include "MetaBase.inl"
#endif

#include "MetaProject.h"
#include "Exception.h"

namespace GAME
{
namespace Meta
{
//
// name
//
std::string Base::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->metabase_->get_Name (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// name
//
void Base::name (const std::string & name)
{
  CComBSTR bstr (name.length (), name.c_str ());
  VERIFY_HRESULT (this->metabase_->put_Name (bstr));
}

//
// display_name
//
std::string Base::display_name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->metabase_->get_DisplayedName (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// display_name
//
void Base::display_name (const std::string & name)
{
  CComBSTR bstr (name.length (), name.c_str ());
  VERIFY_HRESULT (this->metabase_->put_DisplayedName (bstr));
}

//
// operator =
//
const Base & Base::operator = (const Base & metabase)
{
  if (this != &metabase)
    this->metabase_ = metabase.metabase_;

  return *this;
}

//
// refid
//
long Base::refid (void) const
{
  long refid;
  VERIFY_HRESULT (this->metabase_->get_MetaRef (&refid));

  return refid;
}

//
// refid
//
void Base::refid (long refid)
{
  VERIFY_HRESULT (this->metabase_->put_MetaRef (refid));
}

//
// type
//
objtype_enum Base::type (void) const
{
  objtype_enum type;
  VERIFY_HRESULT (this->metabase_->get_ObjType (&type));

  return type;
}

//
// destroy
//
void Base::destroy (void)
{
  VERIFY_HRESULT (this->metabase_->Delete ());
  this->metabase_.Release ();
}

//
// registry_value
//
std::string Base::
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
void Base::registry_value (const std::string & path, const std::string & value)
{
  CComBSTR bstrpath (path.length (), path.c_str ());
  CComBSTR bstrval (value.length (), value.c_str ());

  VERIFY_HRESULT (this->metabase_->put_RegistryValue (bstrpath, bstrval));
}

//
// project
//
Project Base::project (void) const
{
  CComPtr <IMgaMetaProject> proj;
  VERIFY_HRESULT (this->metabase_->get_MetaProject (&proj));

  return proj.p;

}

}
}
