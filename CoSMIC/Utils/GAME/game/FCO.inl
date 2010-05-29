// -*- C++ -*-
// $Id$

namespace GAME
{
  //
  // FCO
  //
  GAME_INLINE
  FCO::FCO (void)
  {

  }

  //
  // FCO
  //
  GAME_INLINE
  FCO::FCO (IMgaFCO * fco)
    : Object (fco)
  {

  }

  //
  // FCO
  //
  GAME_INLINE
  FCO::FCO (const FCO & fco)
    : Object (fco)
  {

  }

  //
  // ~FCO
  //
  GAME_INLINE
  FCO::~FCO (void)
  {

  }

  //
  // attach
  //
  GAME_INLINE
  void FCO::attach (IMgaFCO * fco)
  {
    Object::attach (fco);
  }

  //
  // is_subtype
  //
  GAME_INLINE
  bool FCO::is_subtype (void) const
  {
    return this->basetype ();
  }
}
