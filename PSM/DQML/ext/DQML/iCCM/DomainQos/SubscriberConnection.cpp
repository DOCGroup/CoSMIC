// $Id$

#include "StdAfx.h"
#include "SubscriberConnection.h"

#if !defined (__GAME_INLINE__)
#include "SubscriberConnection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string SubscriberConnection_Impl::metaname ("SubscriberConnection");

  //
  // _create (const Participant_in)
  //
  SubscriberConnection SubscriberConnection_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create_object < SubscriberConnection > (parent, SubscriberConnection_Impl::metaname);
  }

  //
  // accept
  //
  void SubscriberConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SubscriberConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Participant
  //
  Participant SubscriberConnection_Impl::parent_Participant (void)
  {
    return Participant::_narrow (this->parent ());
  }

  //
  // DataReaderQos
  //
  DataReaderQos SubscriberConnection_Impl::src_DataReaderQos (void) const
  {
    return DataReaderQos::_narrow (this->src ());
  }

  //
  // SubscriberQos
  //
  SubscriberQos SubscriberConnection_Impl::dst_SubscriberQos (void) const
  {
    return SubscriberQos::_narrow (this->dst ());
  }
}

