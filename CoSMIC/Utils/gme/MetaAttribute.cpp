// $Id$

#include "MetaAttribute.h"

#if !defined (__GME_INLINE__)
#include "MetaAttribute.inl"
#endif

namespace GME
{
  //
  // impl
  //
  IMgaMetaAttribute * MetaAttribute::impl (void) const
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
  MetaBase MetaAttribute::defined_in (void) const
  {
    IMgaMetaBase * meta = 0;
    VERIFY_HRESULT (this->impl ()->get_DefinedIn (&meta));

    return MetaBase (meta);
  }

  //
  // viewable
  //
  bool MetaAttribute::viewable (void) const
  {
    VARIANT_BOOL value;
    VERIFY_HRESULT (this->impl ()->get_Viewable (&value));

    return value == VARIANT_TRUE ? true : false;
  }

  //
  // viewable
  //
  void MetaAttribute::viewable (bool value)
  {
    VERIFY_HRESULT (
      this->impl ()->put_Viewable (value ? VARIANT_TRUE : VARIANT_FALSE));
  }

  //
  // value_type
  //
  attval_enum MetaAttribute::value_type (void) const
  {
    attval_enum val;
    VERIFY_HRESULT (this->impl ()->get_ValueType (&val));

    return val;
  }

  //
  // value_type
  //
  void MetaAttribute::value_type (attval_enum val)
  {
    VERIFY_HRESULT (this->impl ()->put_ValueType (val));
  }
}
