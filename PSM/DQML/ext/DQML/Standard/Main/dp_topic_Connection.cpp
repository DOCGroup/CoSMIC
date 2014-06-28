// $Id$

#include "StdAfx.h"
#include "dp_topic_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dp_topic_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DDSEntities/DomainParticipant.h"
#include "DQML/Standard/DDSEntities/Topic.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dp_topic_Connection_Impl::metaname ("dp_topic_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dp_topic_Connection dp_topic_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dp_topic_Connection > (parent, dp_topic_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dp_topic_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dp_topic_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dp_topic_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DomainParticipant
  //
  DomainParticipant dp_topic_Connection_Impl::src_DomainParticipant (void) const
  {
    return DomainParticipant::_narrow (this->src ());
  }

  //
  // Topic
  //
  Topic dp_topic_Connection_Impl::dst_Topic (void) const
  {
    return Topic::_narrow (this->dst ());
  }
}

