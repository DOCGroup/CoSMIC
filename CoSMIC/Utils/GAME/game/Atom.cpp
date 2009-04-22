// $Id$

#include "stdafx.h"
#include "Atom.h"

#if !defined (__GME_INLINE__)
#include "Atom.inl"
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
  const Atom & Atom::operator = (const Atom & atom)
  {
    if (this != &atom)
      this->object_ = atom.object_;
    return *this;
  }

  //
  // attach
  //
  void Atom::attach (IMgaAtom * atom)
  {
    VERIFY_HRESULT (atom->QueryInterface (&this->object_));
  }

  //
  // impl
  //
  IMgaAtom * Atom::impl (void) const
  {
    if (this->atom_.p == this->object_.p)
      return this->atom_.p;

    if (this->atom_.p != 0)
      this->atom_.Release ();

    VERIFY_HRESULT (this->object_.QueryInterface (&this->atom_));
    return this->atom_;
  }

  //
  // _narrow
  //
  Atom Atom::_narrow (const GME::Object & object)
  {
    CComPtr <IMgaAtom> atom;

    VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&atom),
                             GME::Invalid_Cast ());

    return atom.p;
  }

  //
  // _create
  //
  Atom Atom::_create (const std::string & role, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    Meta::Role metarole = parent.meta ().role (role);

    VERIFY_HRESULT (
      parent.impl ()->CreateChildObject (metarole, &child));

    return Atom::_narrow (FCO (child));
  }

  //
  // accept
  //
  void Atom::accept (GME::Visitor & visitor)
  {
    visitor.visit_Atom (*this);
  }
}
