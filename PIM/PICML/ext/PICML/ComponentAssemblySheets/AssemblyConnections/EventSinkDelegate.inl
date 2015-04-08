// -*- C++ -*-
namespace PICML
{
  //
  // EventSinkDelegate_Impl
  //
  GAME_INLINE EventSinkDelegate_Impl::EventSinkDelegate_Impl (void)
  {
  }

  //
  // EventSinkDelegate_Impl
  //
  GAME_INLINE EventSinkDelegate_Impl::EventSinkDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventSinkDelegate_Impl
  //
  GAME_INLINE EventSinkDelegate_Impl::~EventSinkDelegate_Impl (void)
  {
  }
}

