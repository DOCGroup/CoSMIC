// -*- C++ -*-
namespace DQML
{
  //
  // Participant_Impl
  //
  GAME_INLINE Participant_Impl::Participant_Impl (void)
  {
  }

  //
  // Participant_Impl
  //
  GAME_INLINE Participant_Impl::Participant_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Participant_Impl
  //
  GAME_INLINE Participant_Impl::~Participant_Impl (void)
  {
  }
}

