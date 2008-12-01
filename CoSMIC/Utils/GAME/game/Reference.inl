// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // Reference
  //
  GME_INLINE
  Reference::Reference (void)
  {

  }

  //
  // Reference
  //
  GME_INLINE
  Reference::Reference (IMgaReference * ref)
    : FCO (ref)
  {

  }

  //
  // Reference
  //
  GME_INLINE
  Reference::Reference (const Reference & ref)
    : FCO (ref)
  {

  }

  //
  // ~Reference
  //
  GME_INLINE
  Reference::~Reference (void)
  {

  }

  //
  // operator IMgaReference *
  //
  GME_INLINE
  Reference::operator IMgaReference * (void) const
  {
    return this->impl ();
  }

  //
  // attach
  //
  GME_INLINE
  void Reference::attach (IMgaReference * ref)
  {
    FCO::attach (ref);
  }
}
