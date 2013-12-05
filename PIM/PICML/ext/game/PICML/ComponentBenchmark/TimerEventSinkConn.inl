// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // TimerEventSinkConn_Impl
  //
  GAME_INLINE TimerEventSinkConn_Impl::TimerEventSinkConn_Impl (void)
  {
  }

  //
  // TimerEventSinkConn_Impl
  //
  GAME_INLINE TimerEventSinkConn_Impl::TimerEventSinkConn_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TimerEventSinkConn_Impl
  //
  GAME_INLINE TimerEventSinkConn_Impl::~TimerEventSinkConn_Impl (void)
  {
  }
}

