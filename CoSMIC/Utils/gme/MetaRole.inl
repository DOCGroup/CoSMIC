// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // MetaRole
  //
  GME_INLINE
  MetaRole::MetaRole (void)
  {

  }

  //
  // MetaRole
  //
  GME_INLINE
  MetaRole::MetaRole (IMgaMetaRole * meta)
  : MetaBase (meta)
  {

  }

  //
  // MetaRole
  //
  GME_INLINE
  MetaRole::MetaRole (const MetaRole & role)
  : MetaBase (role)
  {

  }

  //
  // ~MetaRole
  //
  GME_INLINE
  MetaRole::~MetaRole (void)
  {

  }

  //
  // operator =
  //
  GME_INLINE
  const MetaRole & MetaRole::operator = (const MetaRole & role)
  {
    MetaBase::attach (role);
    return *this;
  }

  //
  // operater IMgaMetaRole *
  //
  GME_INLINE
  MetaRole::operator IMgaMetaRole * (void) const
  {
    return this->impl ();
  }
}
