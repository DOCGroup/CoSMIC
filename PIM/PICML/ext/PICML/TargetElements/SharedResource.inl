// -*- C++ -*-
namespace PICML
{
  //
  // SharedResource_Impl
  //
  GAME_INLINE SharedResource_Impl::SharedResource_Impl (void)
  {
  }

  //
  // SharedResource_Impl
  //
  GAME_INLINE SharedResource_Impl::SharedResource_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SharedResource_Impl
  //
  GAME_INLINE SharedResource_Impl::~SharedResource_Impl (void)
  {
  }
}

