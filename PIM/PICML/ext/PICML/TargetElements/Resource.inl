// -*- C++ -*-
namespace PICML
{
  //
  // Resource_Impl
  //
  GAME_INLINE Resource_Impl::Resource_Impl (void)
  {
  }

  //
  // Resource_Impl
  //
  GAME_INLINE Resource_Impl::Resource_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Resource_Impl
  //
  GAME_INLINE Resource_Impl::~Resource_Impl (void)
  {
  }
}

