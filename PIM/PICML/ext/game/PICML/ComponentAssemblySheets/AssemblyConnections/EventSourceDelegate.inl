// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // EventSourceDelegate_Impl
  //
  GAME_INLINE EventSourceDelegate_Impl::EventSourceDelegate_Impl (void)
  {
  }

  //
  // EventSourceDelegate_Impl
  //
  GAME_INLINE EventSourceDelegate_Impl::EventSourceDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventSourceDelegate_Impl
  //
  GAME_INLINE EventSourceDelegate_Impl::~EventSourceDelegate_Impl (void)
  {
  }
}

