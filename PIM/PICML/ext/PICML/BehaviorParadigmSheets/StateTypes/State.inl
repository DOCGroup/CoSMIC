// -*- C++ -*-
namespace PICML
{
  //
  // State_Impl
  //
  GAME_INLINE State_Impl::State_Impl (void)
  {
  }

  //
  // State_Impl
  //
  GAME_INLINE State_Impl::State_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~State_Impl
  //
  GAME_INLINE State_Impl::~State_Impl (void)
  {
  }
}

