// -*- C++ -*-
namespace PICML
{
  //
  // InterconnectConnection_Impl
  //
  GAME_INLINE InterconnectConnection_Impl::InterconnectConnection_Impl (void)
  {
  }

  //
  // InterconnectConnection_Impl
  //
  GAME_INLINE InterconnectConnection_Impl::InterconnectConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InterconnectConnection_Impl
  //
  GAME_INLINE InterconnectConnection_Impl::~InterconnectConnection_Impl (void)
  {
  }
}

