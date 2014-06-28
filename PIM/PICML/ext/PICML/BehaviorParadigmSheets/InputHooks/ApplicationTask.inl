// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ApplicationTask_Impl
  //
  GAME_INLINE ApplicationTask_Impl::ApplicationTask_Impl (void)
  {
  }

  //
  // ApplicationTask_Impl
  //
  GAME_INLINE ApplicationTask_Impl::ApplicationTask_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ApplicationTask_Impl
  //
  GAME_INLINE ApplicationTask_Impl::~ApplicationTask_Impl (void)
  {
  }
}

