// -*- C++ -*-
namespace PICML
{
  //
  // GenericObject_Impl
  //
  GAME_INLINE GenericObject_Impl::GenericObject_Impl (void)
  {
  }

  //
  // GenericObject_Impl
  //
  GAME_INLINE GenericObject_Impl::GenericObject_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GenericObject_Impl
  //
  GAME_INLINE GenericObject_Impl::~GenericObject_Impl (void)
  {
  }
}

