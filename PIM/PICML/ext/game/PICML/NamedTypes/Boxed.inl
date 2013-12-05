// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Boxed_Impl
  //
  GAME_INLINE Boxed_Impl::Boxed_Impl (void)
  {
  }

  //
  // Boxed_Impl
  //
  GAME_INLINE Boxed_Impl::Boxed_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Boxed_Impl
  //
  GAME_INLINE Boxed_Impl::~Boxed_Impl (void)
  {
  }
}

