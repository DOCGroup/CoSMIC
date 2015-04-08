#include "StdAfx.h"
#include "topic_lifespan_Connection.h"

#if !defined (__GAME_INLINE__)
#include "topic_lifespan_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/LifespanQosPolicy.h"
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
  const std::string topic_lifespan_Connection_Impl::metaname ("topic_lifespan_Connection");

  //
  // is_abstract
  //
  const bool topic_lifespan_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, Topic_in src, LifespanQosPolicy_in dst)
  //
  topic_lifespan_Connection topic_lifespan_Connection_Impl::_create (const DDSQoS_in parent, Topic_in src, LifespanQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, topic_lifespan_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void topic_lifespan_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_topic_lifespan_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS topic_lifespan_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Topic
  //
  Topic topic_lifespan_Connection_Impl::src_Topic (void) const
  {
    return Topic::_narrow (this->src ());
  }

  //
  // LifespanQosPolicy
  //
  LifespanQosPolicy topic_lifespan_Connection_Impl::dst_LifespanQosPolicy (void) const
  {
    return LifespanQosPolicy::_narrow (this->dst ());
  }
}

