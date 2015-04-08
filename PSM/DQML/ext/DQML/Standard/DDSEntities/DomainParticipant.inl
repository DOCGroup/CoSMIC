// -*- C++ -*-
namespace DQML
{
  //
  // DomainParticipant_Impl
  //
  GAME_INLINE DomainParticipant_Impl::DomainParticipant_Impl (void)
  {
  }

  //
  // DomainParticipant_Impl
  //
  GAME_INLINE DomainParticipant_Impl::DomainParticipant_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DomainParticipant_Impl
  //
  GAME_INLINE DomainParticipant_Impl::~DomainParticipant_Impl (void)
  {
  }
}

