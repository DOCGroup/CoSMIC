// -*- C++ -*-
namespace DQML
{
  //
  // PublishesConnection_Impl
  //
  GAME_INLINE PublishesConnection_Impl::PublishesConnection_Impl (void)
  {
  }

  //
  // PublishesConnection_Impl
  //
  GAME_INLINE PublishesConnection_Impl::PublishesConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PublishesConnection_Impl
  //
  GAME_INLINE PublishesConnection_Impl::~PublishesConnection_Impl (void)
  {
  }
}

