// $Id$

#include "StdAfx.h"
#include "topic_liveliness_Connection.h"

#if !defined (__GAME_INLINE__)
#include "topic_liveliness_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/LivelinessQosPolicy.h"
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
  const std::string topic_liveliness_Connection_Impl::metaname ("topic_liveliness_Connection");

  //
  // is_abstract
  //
  const bool topic_liveliness_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, Topic_in src, LivelinessQosPolicy_in dst)
  //
  topic_liveliness_Connection topic_liveliness_Connection_Impl::_create (const DDSQoS_in parent, Topic_in src, LivelinessQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, topic_liveliness_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void topic_liveliness_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_topic_liveliness_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS topic_liveliness_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Topic
  //
  Topic topic_liveliness_Connection_Impl::src_Topic (void) const
  {
    return Topic::_narrow (this->src ());
  }

  //
  // LivelinessQosPolicy
  //
  LivelinessQosPolicy topic_liveliness_Connection_Impl::dst_LivelinessQosPolicy (void) const
  {
    return LivelinessQosPolicy::_narrow (this->dst ());
  }
}

