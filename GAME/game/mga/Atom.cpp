// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Atom.h"

#if !defined (__GAME_INLINE__)
#include "Atom.inl"
#endif

#include "Exception.h"
#include "Functional_T.h"
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
// _create
//
Atom Atom_Impl::_create (const Folder_in parent, const std::string & type)
{
  return create_root_object <Atom> (parent, type);
}

//
// _create
//
Atom Atom_Impl::_create (const Folder_in parent, const Meta::FCO_in metafco)
{
  return create_root_object <Atom> (parent, metafco);
}

//
// _create
//
Atom Atom_Impl::_create (const Model_in parent, const std::string & type)
{
  return create_object <Atom> (parent, type);
}

//
// _create
//
Atom Atom_Impl::_create (const Model_in parent, const Meta::Role_in role)
{
  return create_object <Atom> (parent, role);
}

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
