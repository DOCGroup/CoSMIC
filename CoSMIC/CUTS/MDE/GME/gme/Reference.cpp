// $Id$

#include "Reference.h"

namespace GME
{
  //
  // Reference
  //
  Reference::Reference (void)
  {

  }

  //
  // Reference
  //
  Reference::Reference (IMgaReference * ref)
    : FCO (ref)
  {

  }

  //
  // Reference
  //
  Reference::Reference (const Reference & ref)
    : FCO (ref)
  {

  }

  //
  // ~Reference
  //
  Reference::~Reference (void)
  {

  }

  //
  // operator =
  //
  const Reference & Reference::operator = (const Reference & ref)
  {
    if (this != &ref)
      this->object_ = ref.object_;

    return *this;
  }

  //
  // refers_to
  //
  FCO Reference::refers_to (void) const
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_Referred (&fco));

    return fco.p;
  }

  //
  // refers_to
  //
  void Reference::refers_to (const FCO & fco)
  {
    VERIFY_HRESULT (this->impl ()->put_Referred (fco));
  }

  //
  // impl
  //
  IMgaReference * Reference::impl (void) const
  {
    if (this->ref_.p != this->object_.p)
      VERIFY_HRESULT (this->object_.QueryInterface (&this->ref_));

    return this->ref_;
  }

  //
  // impl
  //
  void Reference::attach (IMgaReference * ref)
  {
    VERIFY_HRESULT (ref->QueryInterface (&this->object_));
  }

  //
  // operator IMgaReference *
  //
  Reference::operator IMgaReference * (void) const
  {
    return this->impl ();
  }
}
