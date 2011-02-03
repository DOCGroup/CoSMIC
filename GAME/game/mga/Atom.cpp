// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Atom.h"

#if !defined (__GAME_INLINE__)
#include "Atom.inl"
#endif

#include "Exception.h"
#include "Folder.h"

#include "Model.h"
#include "MetaFolder.h"
#include "MetaModel.h"
#include "MetaAtom.h"
#include "MetaRole.h"
#include "Visitor.h"

namespace GAME
{
namespace Mga
{

//
// attach
//
void Atom_Impl::attach (IMgaAtom * atom)
{
  VERIFY_HRESULT (atom->QueryInterface (&this->object_));
}

//
// impl
//
IMgaAtom * Atom_Impl::impl (void) const
{
  if (this->atom_.p == this->object_.p)
    return this->atom_.p;

  if (this->atom_.p != 0)
    this->atom_.Release ();

  VERIFY_HRESULT (this->object_.QueryInterface (&this->atom_));
  return this->atom_;
}

//
// _create
//
Atom Atom_Impl::_create (const Model_in parent, const std::string & type)
{
  Meta::Role role = parent->meta ()->role (type);
  return Atom_Impl::_create (parent, role);
}

//
// _create
//
Atom Atom_Impl::_create (const Model_in parent, const Meta::Role_in role)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateChildObject (role->impl (), &child));

  CComPtr <IMgaAtom> mga_atom;
  VERIFY_HRESULT (child.QueryInterface (&mga_atom));

  return new Atom_Impl (mga_atom);
}

//
// _create
//
Atom Atom_Impl::_create (const Folder_in parent, const std::string & type)
{
  Meta::FCO role = parent->meta ()->child (type);
  return Atom_Impl::_create (parent, role.get ());
}

//
// _create
//
Atom Atom_Impl::_create (const Folder_in parent, const Meta::FCO_in type)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateRootObject (type->impl (), &child));

  CComPtr <IMgaAtom> mga_atom;
  VERIFY_HRESULT (child.QueryInterface (&mga_atom));

  return new Atom_Impl (mga_atom.p);
}

//
// accept
//
void Atom_Impl::accept (Visitor * v)
{
  v->visit_Atom (this);
}

//
// meta
//
Meta::Atom Atom_Impl::meta (void) const
{
  return Meta::Atom::_narrow (FCO_Impl::meta ());
}

}
}
