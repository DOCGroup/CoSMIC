// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // Atom
  //
  GME_INLINE
  Atom::Atom (void)
  {

  }

  //
  // Atom
  //
  GME_INLINE
  Atom::Atom (IMgaAtom * atom)
    : FCO (atom)
  {

  }

  //
  // Atom
  //
  GME_INLINE
  Atom::Atom (const Atom & atom)
    : FCO (atom)
  {

  }

  //
  // ~Atom
  //
  GME_INLINE
  Atom::~Atom (void)
  {

  }

}
