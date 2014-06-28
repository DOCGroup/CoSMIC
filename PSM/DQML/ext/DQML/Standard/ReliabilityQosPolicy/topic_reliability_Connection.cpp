// $Id$

#include "StdAfx.h"
#include "topic_reliability_Connection.h"

#if !defined (__GAME_INLINE__)
#include "topic_reliability_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/ReliabilityQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Topic.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string topic_reliability_Connection_Impl::metaname ("topic_reliability_Connection");

  //
  // _create (const DDSQoS_in)
  //
  topic_reliability_Connection topic_reliability_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < topic_reliability_Connection > (parent, topic_reliability_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void topic_reliability_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_topic_reliability_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS topic_reliability_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Topic
  //
  Topic topic_reliability_Connection_Impl::src_Topic (void) const
  {
    return Topic::_narrow (this->src ());
  }

  //
  // ReliabilityQosPolicy
  //
  ReliabilityQosPolicy topic_reliability_Connection_Impl::dst_ReliabilityQosPolicy (void) const
  {
    return ReliabilityQosPolicy::_narrow (this->dst ());
  }
}

