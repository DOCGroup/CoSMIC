// -*- C++ -*-
// $Id$

namespace GAME
{
  //
  // Reference
  //
  GAME_INLINE
  Reference::Reference (void)
  {

  }

  //
  // Reference
  //
  GAME_INLINE
  Reference::Reference (IMgaReference * ref)
    : FCO (ref)
  {

  }

  //
  // Reference
  //
  GAME_INLINE
  Reference::Reference (const Reference & ref)
    : FCO (ref)
  {

  }

  //
  // ~Reference
  //
  GAME_INLINE
  Reference::~Reference (void)
  {

  }

  //
  // operator IMgaReference *
  //
  GAME_INLINE
  Reference::operator IMgaReference * (void) const
  {
    return this->impl ();
  }

  //
  // attach
  //
  GAME_INLINE
  void Reference::attach (IMgaReference * ref)
  {
    FCO::attach (ref);
  }
}
