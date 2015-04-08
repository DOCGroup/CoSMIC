// -*- C++ -*-
namespace PICML
{
  //
  // OutParameter_Impl
  //
  GAME_INLINE OutParameter_Impl::OutParameter_Impl (void)
  {
  }

  //
  // OutParameter_Impl
  //
  GAME_INLINE OutParameter_Impl::OutParameter_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutParameter_Impl
  //
  GAME_INLINE OutParameter_Impl::~OutParameter_Impl (void)
  {
  }
}

