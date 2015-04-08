// -*- C++ -*-
namespace DQML
{
  //
  // Subscriber_Impl
  //
  GAME_INLINE Subscriber_Impl::Subscriber_Impl (void)
  {
  }

  //
  // Subscriber_Impl
  //
  GAME_INLINE Subscriber_Impl::Subscriber_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Subscriber_Impl
  //
  GAME_INLINE Subscriber_Impl::~Subscriber_Impl (void)
  {
  }
}

