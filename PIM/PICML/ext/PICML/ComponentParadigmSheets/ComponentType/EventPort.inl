// -*- C++ -*-
namespace PICML
{
  //
  // EventPort_Impl
  //
  GAME_INLINE EventPort_Impl::EventPort_Impl (void)
  {
  }

  //
  // EventPort_Impl
  //
  GAME_INLINE EventPort_Impl::EventPort_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventPort_Impl
  //
  GAME_INLINE EventPort_Impl::~EventPort_Impl (void)
  {
  }
}

