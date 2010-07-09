// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Reference.h"

#if !defined (__GAME_INLINE__)
#include "Reference.inl"
#endif

#include "Model.h"
#include "Visitor.h"
#include "MetaRole.h"
#include "MetaModel.h"
#include "MetaReference.h"

namespace GAME
{
//
// meta
//
GAME_INLINE
Meta::Reference Reference::meta (void) const
{
  return Meta::Reference::_narrow (FCO::meta ());
}

//
// operator =
//
const Reference & Reference::operator = (const Reference & ref)
{
  if (this == &ref)
    return *this;

  FCO::attach (ref.impl ());
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
Reference Reference::_narrow (const GAME::Object & object)
{
  CComPtr <IMgaReference> ref;

  VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&ref),
                           GAME::Invalid_Cast ());

  return ref.p;
}

//
// _create
//
Reference Reference::_create (Model & parent, const std::string & type)
{
  Meta::Role role = parent.meta ().role (type);
  return Reference::_create (parent, role);
}

//
// _create
//
Reference Reference::_create (Model & parent, const Meta::Role & role)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent.impl ()->CreateChildObject (role, &child));

  return Reference::_narrow (FCO (child));
}

//
// accept
//
void Reference::accept (GAME::Visitor & visitor)
{
  visitor.visit_Reference (*this);
}
}
