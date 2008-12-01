// -*- C++ -*
// $Id$

namespace GME
{
namespace Meta
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
  FCO::FCO (const FCO & meta)
  : Base (meta)
  {

  }

  //
  // FCO
  //
  GME_INLINE
  FCO::FCO (IMgaMetaFCO * meta)
  : Base (meta)
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
  // operator =
  //
  GME_INLINE
  const FCO & FCO::operator = (const FCO & meta)
  {
    Base::attach (meta);
    return *this;
  }
}
}
