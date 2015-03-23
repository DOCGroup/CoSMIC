// $Id$

#include "StdAfx.h"
#include "PublisherConnection.h"

#if !defined (__GAME_INLINE__)
#include "PublisherConnection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/PublisherSubscriberQos/PublisherQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string PublisherConnection_Impl::metaname ("PublisherConnection");

  //
  // is_abstract
  //
  const bool PublisherConnection_Impl::is_abstract = false;

  //
  // _create (const Participant_in, DataWriterQos_in src, PublisherQos_in dst)
  //
  PublisherConnection PublisherConnection_Impl::_create (const Participant_in parent, DataWriterQos_in src, PublisherQos_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PublisherConnection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PublisherConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PublisherConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Participant
  //
  Participant PublisherConnection_Impl::parent_Participant (void)
  {
    return Participant::_narrow (this->parent ());
  }

  //
  // DataWriterQos
  //
  DataWriterQos PublisherConnection_Impl::src_DataWriterQos (void) const
  {
    return DataWriterQos::_narrow (this->src ());
  }

  //
  // PublisherQos
  //
  PublisherQos PublisherConnection_Impl::dst_PublisherQos (void) const
  {
    return PublisherQos::_narrow (this->dst ());
  }
}

