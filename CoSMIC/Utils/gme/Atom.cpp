// $Id$

#include "stdafx.h"
#include "Atom.h"
#include "Model.h"
#include "MetaRole.h"
#include "MetaModel.h"

namespace GME
{
  //
  // Atom
  //
  Atom::Atom (void)
  {

  }

  //
  // Atom
  //
  Atom::Atom (IMgaAtom * atom)
    : FCO (atom)
  {

  }

  //
  // Atom
  //
  Atom::Atom (const Atom & atom)
    : FCO (atom)
  {

  }

  //
  // ~Atom
  //
  Atom::~Atom (void)
  {

  }

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
    if (this->atom_.p != this->object_.p)
      VERIFY_HRESULT (this->object_.QueryInterface (&this->atom_));

    return this->atom_;
  }

  //
  // _narrow
  //
  Atom Atom::_narrow (const GME::Object & object)
  {
    CComPtr <IMgaAtom> atom;
    VERIFY_HRESULT (object.impl ()->QueryInterface (&atom));

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
}
