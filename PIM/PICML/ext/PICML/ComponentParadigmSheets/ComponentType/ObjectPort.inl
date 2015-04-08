// -*- C++ -*-
namespace PICML
{
  //
  // ObjectPort_Impl
  //
  GAME_INLINE ObjectPort_Impl::ObjectPort_Impl (void)
  {
  }

  //
  // ObjectPort_Impl
  //
  GAME_INLINE ObjectPort_Impl::ObjectPort_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ObjectPort_Impl
  //
  GAME_INLINE ObjectPort_Impl::~ObjectPort_Impl (void)
  {
  }
}

