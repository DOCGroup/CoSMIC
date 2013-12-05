// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // PackageInterface_Impl
  //
  GAME_INLINE PackageInterface_Impl::PackageInterface_Impl (void)
  {
  }

  //
  // PackageInterface_Impl
  //
  GAME_INLINE PackageInterface_Impl::PackageInterface_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageInterface_Impl
  //
  GAME_INLINE PackageInterface_Impl::~PackageInterface_Impl (void)
  {
  }
}

