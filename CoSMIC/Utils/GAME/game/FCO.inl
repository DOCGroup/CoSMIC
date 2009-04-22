// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // FCO
  //
  GME_INLINE
  FCO::FCO (void)
  {

  }

  //
  // FCO
  //
  GME_INLINE
  FCO::FCO (IMgaFCO * fco)
    : Object (fco)
  {

  }

  //
  // FCO
  //
  GME_INLINE
  FCO::FCO (const FCO & fco)
    : Object (fco)
  {

  }

  //
  // ~FCO
  //
  GME_INLINE
  FCO::~FCO (void)
  {

  }

  //
  // attach
  //
  GME_INLINE
  void FCO::attach (IMgaFCO * fco)
  {
    Object::attach (fco);
  }

  //
  // is_subtype
  //
  GME_INLINE
  bool FCO::is_subtype (void) const
  {
    return this->basetype ();
  }
}
