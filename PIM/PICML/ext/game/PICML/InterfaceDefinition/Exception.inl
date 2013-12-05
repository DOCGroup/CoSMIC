// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Exception_Impl
  //
  GAME_INLINE Exception_Impl::Exception_Impl (void)
  {
  }

  //
  // Exception_Impl
  //
  GAME_INLINE Exception_Impl::Exception_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Exception_Impl
  //
  GAME_INLINE Exception_Impl::~Exception_Impl (void)
  {
  }
}

