// -*- C++ -*-
namespace PICML
{
  //
  // GenericValue_Impl
  //
  GAME_INLINE GenericValue_Impl::GenericValue_Impl (void)
  {
  }

  //
  // GenericValue_Impl
  //
  GAME_INLINE GenericValue_Impl::GenericValue_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GenericValue_Impl
  //
  GAME_INLINE GenericValue_Impl::~GenericValue_Impl (void)
  {
  }
}

