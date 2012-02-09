// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaFCO.h"
#include "MetaConnection.h"
#include "MetaRole.h"


#if !defined (__GAME_INLINE__)
#include "MetaFCO.inl"
#endif

#include "Collection_T.h"
#include "Exception.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// impl
//
IMgaMetaFCO * FCO_Impl::impl (void) const
{
  // Optimize for the quick path.
  if (this->meta_fco_.p == this->metabase_.p)
    return this->meta_fco_;

  // So, we have to actually initalize the <meta_fco_>.
  if (this->meta_fco_)
    this->meta_fco_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->meta_fco_));
  return this->meta_fco_;
}

//
// defined_in
//
Base FCO_Impl::defined_in (void) const
{
  CComPtr <IMgaMetaBase> meta;
  VERIFY_HRESULT (this->impl ()->get_DefinedIn (&meta));

  return meta.p;
}


//
// attribute
//
Attribute FCO_Impl::
attribute (const std::string & name, bool display_name) const
{
  CComBSTR bstr_name (name.length (), name.c_str ());

  CComPtr <IMgaMetaAttribute> attr;

  if (!display_name)
  {
    VERIFY_HRESULT (this->impl ()->get_AttributeByName (bstr_name, &attr));
  }
  else
  {
    VERIFY_HRESULT (this->impl ()->GetAttributeByNameDisp (bstr_name, &attr));
  }

  return attr.p;
}

//
// used_in_roles
//
size_t FCO_Impl::used_in_roles(std::vector <Role> & roles) const
{
  CComPtr <IMgaMetaRoles> temps;
  VERIFY_HRESULT (this->impl ()->get_UsedInRoles (&temps));

  return iter_to_collection (temps.p, roles);
}


}
}
}
