// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // DomainParticipantFactory_Impl
  //
  GAME_INLINE DomainParticipantFactory_Impl::DomainParticipantFactory_Impl (void)
  {
  }

  //
  // DomainParticipantFactory_Impl
  //
  GAME_INLINE DomainParticipantFactory_Impl::DomainParticipantFactory_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DomainParticipantFactory_Impl
  //
  GAME_INLINE DomainParticipantFactory_Impl::~DomainParticipantFactory_Impl (void)
  {
  }
}

