// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // PathReference_Impl
  //
  GAME_INLINE PathReference_Impl::PathReference_Impl (void)
  {
  }

  //
  // PathReference_Impl
  //
  GAME_INLINE PathReference_Impl::PathReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PathReference_Impl
  //
  GAME_INLINE PathReference_Impl::~PathReference_Impl (void)
  {
  }
}

