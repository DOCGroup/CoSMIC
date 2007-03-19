// -*- C++ -*
// $Id$

namespace GME
{
  //
  // MetaFCO
  //
  GME_INLINE
  MetaFCO::MetaFCO (void)
  {

  }

  //
  // MetaFCO
  //
  GME_INLINE
  MetaFCO::MetaFCO (const MetaFCO & meta)
  : MetaBase (meta)
  {

  }

  //
  // MetaFCO
  //
  GME_INLINE
  MetaFCO::MetaFCO (IMgaMetaFCO * meta)
  : MetaBase (meta)
  {

  }

  //
  // ~MetaFCO
  //
  GME_INLINE
  MetaFCO::~MetaFCO (void)
  {

  }

  //
  // operator IMgaMetaFCO *
  //
  GME_INLINE
  MetaFCO::operator IMgaMetaFCO * (void) const
  {
    return this->impl ();
  }

  //
  // operator =
  //
  GME_INLINE
  const MetaFCO & MetaFCO::operator = (const MetaFCO & meta)
  {
    MetaBase::attach (meta);
    return *this;
  }
}
