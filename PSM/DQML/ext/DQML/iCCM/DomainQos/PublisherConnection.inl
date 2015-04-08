// -*- C++ -*-
namespace DQML
{
  //
  // PublisherConnection_Impl
  //
  GAME_INLINE PublisherConnection_Impl::PublisherConnection_Impl (void)
  {
  }

  //
  // PublisherConnection_Impl
  //
  GAME_INLINE PublisherConnection_Impl::PublisherConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PublisherConnection_Impl
  //
  GAME_INLINE PublisherConnection_Impl::~PublisherConnection_Impl (void)
  {
  }
}

