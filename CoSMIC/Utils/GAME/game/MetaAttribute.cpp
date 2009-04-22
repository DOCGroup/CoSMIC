// $Id$

#include "stdafx.h"
#include "MetaAttribute.h"

#if !defined (__GME_INLINE__)
#include "MetaAttribute.inl"
#endif

namespace GME
{
namespace Meta
{
  //
  // _narrow
  //
  Attribute Attribute::_narrow (const Base & base)
  {
    CComPtr <IMgaMetaAttribute> attr;

    VERIFY_HRESULT_THROW_EX (base.impl ()->QueryInterface (&attr),
                             GME::Invalid_Cast ());

    return attr.p;
  }

  //
  // impl
  //
  IMgaMetaAttribute * Attribute::impl (void) const
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
  Base Attribute::defined_in (void) const
  {
    IMgaMetaBase * meta = 0;
    VERIFY_HRESULT (this->impl ()->get_DefinedIn (&meta));

    return Base (meta);
  }

  //
  // viewable
  //
  bool Attribute::viewable (void) const
  {
    VARIANT_BOOL value;
    VERIFY_HRESULT (this->impl ()->get_Viewable (&value));

    return value == VARIANT_TRUE ? true : false;
  }

  //
  // viewable
  //
  void Attribute::viewable (bool value)
  {
    VERIFY_HRESULT (
      this->impl ()->put_Viewable (value ? VARIANT_TRUE : VARIANT_FALSE));
  }

  //
  // value_type
  //
  attval_enum Attribute::type (void) const
  {
    attval_enum val;
    VERIFY_HRESULT (this->impl ()->get_ValueType (&val));

    return val;
  }

  //
  // value_type
  //
  void Attribute::type (attval_enum val)
  {
    VERIFY_HRESULT (this->impl ()->put_ValueType (val));
  }
}
}
