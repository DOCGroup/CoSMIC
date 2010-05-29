// -*- C++ -*-
// $Id$

namespace GAME
{
  //
  // Atom
  //
  GAME_INLINE
  Atom::Atom (void)
  {

  }

  //
  // Atom
  //
  GAME_INLINE
  Atom::Atom (IMgaAtom * atom)
    : FCO (atom)
  {

  }

  //
  // Atom
  //
  GAME_INLINE
  Atom::Atom (const Atom & atom)
    : FCO (atom)
  {

  }

  //
  // ~Atom
  //
  GAME_INLINE
  Atom::~Atom (void)
  {

  }

}
