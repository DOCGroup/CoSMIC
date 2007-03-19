// $Id$

#include "MetaRole.h"

#if !defined (__GME_INLINE__)
#include "MetaRole.inl"
#endif

namespace GME
{
  //
  // impl
  //
  IMgaMetaRole * MetaRole::impl (void) const
  {
    // Optimize for the short path.
    if (this->metarole_.p == this->metabase_.p)
      return this->metarole_;

    // Ok, so we have to actually get the implementation first.
    if (this->metarole_.p)
      this->metarole_.Release ();

    VERIFY_HRESULT (this->metabase_.QueryInterface (&this->metarole_));
    return this->metarole_;
  }

  //
  // kind
  //
  MetaFCO MetaRole::kind (void) const
  {
    CComPtr <IMgaMetaFCO> metafco;
    VERIFY_HRESULT (this->impl ()->get_Kind (&metafco));

    return metafco.p;
  }
}
