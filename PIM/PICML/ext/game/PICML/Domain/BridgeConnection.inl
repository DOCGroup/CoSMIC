// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // BridgeConnection_Impl
  //
  GAME_INLINE BridgeConnection_Impl::BridgeConnection_Impl (void)
  {
  }

  //
  // BridgeConnection_Impl
  //
  GAME_INLINE BridgeConnection_Impl::BridgeConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BridgeConnection_Impl
  //
  GAME_INLINE BridgeConnection_Impl::~BridgeConnection_Impl (void)
  {
  }
}

