// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Atom_Impl
//
GAME_INLINE
Atom_Impl::Atom_Impl (void)
{

}

//
// Atom_Impl
//
GAME_INLINE
Atom_Impl::Atom_Impl (IMgaAtom * atom)
//: FCO_Impl (atom)
{
  this->object_ = atom;
}

//
// ~Atom_Impl
//
GAME_INLINE
Atom_Impl::~Atom_Impl (void)
{

}

}
}
