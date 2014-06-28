// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // TimerConnection_Impl
  //
  GAME_INLINE TimerConnection_Impl::TimerConnection_Impl (void)
  {
  }

  //
  // TimerConnection_Impl
  //
  GAME_INLINE TimerConnection_Impl::TimerConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TimerConnection_Impl
  //
  GAME_INLINE TimerConnection_Impl::~TimerConnection_Impl (void)
  {
  }
}

