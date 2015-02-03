// $Id$

#include "StdAfx.h"
#include "topic_durqos_Connection.h"

#if !defined (__GAME_INLINE__)
#include "topic_durqos_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
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
  const std::string topic_durqos_Connection_Impl::metaname ("topic_durqos_Connection");

  //
  // is_abstract
  //
  const bool topic_durqos_Connection_Impl::is_abstract (0);

  //
  // _create (const DDSQoS_in, Topic_in src, DurabilityQosPolicy_in dst)
  //
  topic_durqos_Connection topic_durqos_Connection_Impl::_create (const DDSQoS_in parent, Topic_in src, DurabilityQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, topic_durqos_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void topic_durqos_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_topic_durqos_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS topic_durqos_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Topic
  //
  Topic topic_durqos_Connection_Impl::src_Topic (void) const
  {
    return Topic::_narrow (this->src ());
  }

  //
  // DurabilityQosPolicy
  //
  DurabilityQosPolicy topic_durqos_Connection_Impl::dst_DurabilityQosPolicy (void) const
  {
    return DurabilityQosPolicy::_narrow (this->dst ());
  }
}

