// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Meta
{
  //
  // Role
  //
  GAME_INLINE
  Role::Role (void)
  {

  }

  //
  // Role
  //
  GAME_INLINE
  Role::Role (IMgaMetaRole * meta)
  : Base (meta)
  {

  }

  //
  // Role
  //
  GAME_INLINE
  Role::Role (const Role & role)
  : Base (role)
  {

  }

  //
  // ~Role
  //
  GAME_INLINE
  Role::~Role (void)
  {

  }

  //
  // operator =
  //
  GAME_INLINE
  const Role & Role::operator = (const Role & role)
  {
    Base::attach (role);
    return *this;
  }

  //
  // operater IMgaMetaRole *
  //
  GAME_INLINE
  Role::operator IMgaMetaRole * (void) const
  {
    return this->impl ();
  }
}
}
