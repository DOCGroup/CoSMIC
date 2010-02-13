// $Id$

#include "stdafx.h"
#include "Reference.h"

#if !defined (__GME_INLINE__)
#include "Reference.inl"
#endif

#include "Model.h"
#include "MetaRole.h"
#include "MetaModel.h"
#include "Visitor.h"

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
    VERIFY_HRESULT (this->impl ()->put_Referred (fco.impl ()));
  }

  //
  // impl
  //
  IMgaReference * Reference::impl (void) const
  {
    if (this->ref_.p == this->object_.p)
      return this->ref_.p;

    if (this->ref_.p != 0)
      this->ref_.Release ();

    VERIFY_HRESULT (this->object_.QueryInterface (&this->ref_));
    return this->ref_.p;
  }

  //
  // _narrow
  //
  Reference Reference::_narrow (const GME::Object & object)
  {
    CComPtr <IMgaReference> ref;

    VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&ref),
                             GME::Invalid_Cast ());

    return ref.p;
  }

  //
  // _create
  //
  Reference Reference::_create (const std::string & type, Model & parent)
  {
    Meta::Role role = parent.meta ().role (type);
    return Reference::_create (role, parent);
  }

  //
  // _create
  //
  Reference Reference::_create (const Meta::Role & role, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    VERIFY_HRESULT (parent.impl ()->CreateChildObject (role, &child));

    return Reference::_narrow (FCO (child));
  }

  //
  // accept
  //
  void Reference::accept (GME::Visitor & visitor)
  {
    visitor.visit_Reference (*this);
  }
}
