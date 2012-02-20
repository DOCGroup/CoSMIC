// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // SubscriberConnection_Impl
  //
  GAME_INLINE SubscriberConnection_Impl::SubscriberConnection_Impl (void)
  {
  }

  //
  // SubscriberConnection_Impl
  //
  GAME_INLINE SubscriberConnection_Impl::SubscriberConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SubscriberConnection_Impl
  //
  GAME_INLINE SubscriberConnection_Impl::~SubscriberConnection_Impl (void)
  {
  }
}

