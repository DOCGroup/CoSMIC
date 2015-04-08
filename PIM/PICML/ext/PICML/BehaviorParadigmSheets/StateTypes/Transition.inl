// -*- C++ -*-
namespace PICML
{
  //
  // Transition_Impl
  //
  GAME_INLINE Transition_Impl::Transition_Impl (void)
  {
  }

  //
  // Transition_Impl
  //
  GAME_INLINE Transition_Impl::Transition_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Transition_Impl
  //
  GAME_INLINE Transition_Impl::~Transition_Impl (void)
  {
  }
}

