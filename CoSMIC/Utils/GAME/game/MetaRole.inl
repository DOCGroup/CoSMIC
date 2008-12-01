// -*- C++ -*-
// $Id$

namespace GME
{
namespace Meta
{
  //
  // Role
  //
  GME_INLINE
  Role::Role (void)
  {

  }

  //
  // Role
  //
  GME_INLINE
  Role::Role (IMgaMetaRole * meta)
  : Base (meta)
  {

  }

  //
  // Role
  //
  GME_INLINE
  Role::Role (const Role & role)
  : Base (role)
  {

  }

  //
  // ~Role
  //
  GME_INLINE
  Role::~Role (void)
  {

  }

  //
  // operator =
  //
  GME_INLINE
  const Role & Role::operator = (const Role & role)
  {
    Base::attach (role);
    return *this;
  }

  //
  // operater IMgaMetaRole *
  //
  GME_INLINE
  Role::operator IMgaMetaRole * (void) const
  {
    return this->impl ();
  }
}
}
