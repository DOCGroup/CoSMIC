// -*- C++ -*-
namespace PICML
{
  //
  // PropertyMapping_Impl
  //
  GAME_INLINE PropertyMapping_Impl::PropertyMapping_Impl (void)
  {
  }

  //
  // PropertyMapping_Impl
  //
  GAME_INLINE PropertyMapping_Impl::PropertyMapping_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PropertyMapping_Impl
  //
  GAME_INLINE PropertyMapping_Impl::~PropertyMapping_Impl (void)
  {
  }
}

