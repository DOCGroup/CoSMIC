// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Event_Impl
  //
  GAME_INLINE Event_Impl::Event_Impl (void)
  {
  }

  //
  // Event_Impl
  //
  GAME_INLINE Event_Impl::Event_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Event_Impl
  //
  GAME_INLINE Event_Impl::~Event_Impl (void)
  {
  }
}

