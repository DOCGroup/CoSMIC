// $Id$

#include "FCO.h"

namespace GME
{
  //
  // FCO
  //
  FCO::FCO (void)
  {

  }

  //
  // FCO
  //
  FCO::FCO (IMgaFCO * fco)
    : Object (fco)
  {

  }

  //
  // FCO
  //
  FCO::FCO (const FCO & fco)
    : Object (fco)
  {

  }

  //
  // ~FCO
  //
  FCO::~FCO (void)
  {

  }

  //
  // is_instance
  //
  bool FCO::is_instance (void) const
  {
    VARIANT_BOOL instance;
    VERIFY_HRESULT (this->impl ()->get_IsInstance (&instance));

    return instance == VARIANT_TRUE ? true : false;
  }

  //
  // is_primary_derived
  //
  bool FCO::is_primary_derived (void) const
  {
    VARIANT_BOOL primary;
    VERIFY_HRESULT (this->impl ()->get_IsPrimaryDerived (&primary));

    return primary == VARIANT_TRUE ? true : false;
  }

  //
  // operator =
  //
  const FCO & FCO::operator = (const FCO & fco)
  {
    if (this != &fco)
      this->object_ = fco.object_;

    return *this;
  }

  //
  // attach
  //
  void FCO::attach (IMgaFCO * fco)
  {
    VERIFY_HRESULT (fco->QueryInterface (&this->object_));
  }

  //
  // impl
  //
  IMgaFCO * FCO::impl (void) const
  {
    if (this->fco_.p != this->object_.p)
      VERIFY_HRESULT (this->object_.QueryInterface (&this->fco_));

    return this->fco_.p;
  }

  //
  // operator IMgaFCO *
  //
  FCO::operator IMgaFCO * (void) const
  {
    return this->impl ();
  }
}
