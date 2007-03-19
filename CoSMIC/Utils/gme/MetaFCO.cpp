// $Id$

#include "MetaFCO.h"

#if !defined (__GME_INLINE__)
#include "MetaFCO.inl"
#endif

namespace GME
{
  //
  // impl
  //
  IMgaMetaFCO * MetaFCO::impl (void) const
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
  MetaBase MetaFCO::defined_in (void) const
  {
    CComPtr <IMgaMetaBase> meta;
    VERIFY_HRESULT (this->impl ()->get_DefinedIn (&meta));

    return meta.p;
  }
}
