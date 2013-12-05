// $Id$

#include "StdAfx.h"
#include "topic_lifespan_Connection.h"

#if !defined (__GAME_INLINE__)
#include "topic_lifespan_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Topic.h"
#include "DQML/Standard/QoSPolicies/LifespanQosPolicy.h"
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
  // _create (const DDSQoS_in)
  //
  topic_lifespan_Connection topic_lifespan_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < topic_lifespan_Connection > (parent, topic_lifespan_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void topic_lifespan_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_topic_lifespan_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

