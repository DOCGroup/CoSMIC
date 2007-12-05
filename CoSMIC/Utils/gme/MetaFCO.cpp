// $Id$

#include "stdafx.h"
#include "MetaFCO.h"

#if !defined (__GME_INLINE__)
#include "MetaFCO.inl"
#endif

namespace GME
{
namespace Meta
{
  //
  // impl
  //
  IMgaMetaFCO * FCO::impl (void) const
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
  Base FCO::defined_in (void) const
  {
    CComPtr <IMgaMetaBase> meta;
    VERIFY_HRESULT (this->impl ()->get_DefinedIn (&meta));

    return meta.p;
  }
}
}
