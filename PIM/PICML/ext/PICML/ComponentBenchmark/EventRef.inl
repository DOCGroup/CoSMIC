// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // EventRef_Impl
  //
  GAME_INLINE EventRef_Impl::EventRef_Impl (void)
  {
  }

  //
  // EventRef_Impl
  //
  GAME_INLINE EventRef_Impl::EventRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventRef_Impl
  //
  GAME_INLINE EventRef_Impl::~EventRef_Impl (void)
  {
  }
}

