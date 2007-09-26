// $Id$

#include "Reference.h"
#include "Model.h"

#if !defined (__GME_INLINE__)
#include "Reference.inl"
#endif

namespace GME
{
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
  // _narrow
  //
  Reference Reference::_narrow (const GME::Object & object)
  {
    CComPtr <IMgaReference> ref;
    VERIFY_HRESULT (object.impl ()->QueryInterface (&ref));

    return ref.p;
  }

  //
  // _create
  //
  Reference Reference::_create (const std::string & role, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    MetaRole metarole = parent.meta ().role (role);

    VERIFY_HRESULT (
      parent.impl ()->CreateChildObject (metarole, &child));

    return Reference::_narrow (FCO (child));
  }
}
