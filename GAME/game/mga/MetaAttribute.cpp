// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaAttribute.h"

#if !defined (__GAME_INLINE__)
#include "MetaAttribute.inl"
#endif

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
IMgaMetaAttribute * Attribute_Impl::impl (void) const
{
  // Optimize for the quick path.
  if (this->meta_attr_.p == this->metabase_.p)
    return this->meta_attr_;

  // So, we have to actually initalize the <meta_fco_>.
  if (this->meta_attr_)
    this->meta_attr_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->meta_attr_));
  return this->meta_attr_;
}

//
// defined_in
//
Base Attribute_Impl::defined_in (void) const
{
  CComPtr <IMgaMetaBase> meta;
  VERIFY_HRESULT (this->impl ()->get_DefinedIn (&meta));

  return meta.p;
}

//
// viewable
//
bool Attribute_Impl::viewable (void) const
{
  VARIANT_BOOL value;
  VERIFY_HRESULT (this->impl ()->get_Viewable (&value));

  return value == VARIANT_TRUE ? true : false;
}

//
// viewable
//
void Attribute_Impl::viewable (bool value)
{
  VARIANT_BOOL bval = value ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->impl ()->put_Viewable (bval));
}

//
// value_type
//
attval_enum Attribute_Impl::type (void) const
{
  attval_enum val;
  VERIFY_HRESULT (this->impl ()->get_ValueType (&val));

  return val;
}

//
// value_type
//
void Attribute_Impl::type (attval_enum val)
{
  VERIFY_HRESULT (this->impl ()->put_ValueType (val));
}

}
}
}
