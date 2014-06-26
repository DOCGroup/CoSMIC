// $Id$

#include "StdAfx.h"
#include "topic_durqos_Connection.h"

#if !defined (__GAME_INLINE__)
#include "topic_durqos_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Topic.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
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
  // _create (const DDSQoS_in)
  //
  topic_durqos_Connection topic_durqos_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < topic_durqos_Connection > (parent, topic_durqos_Connection_Impl::metaname);
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

