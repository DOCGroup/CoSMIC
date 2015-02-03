// $Id$

#include "StdAfx.h"
#include "topic_ownership_Connection.h"

#if !defined (__GAME_INLINE__)
#include "topic_ownership_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
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
  const std::string topic_ownership_Connection_Impl::metaname ("topic_ownership_Connection");

  //
  // is_abstract
  //
  const bool topic_ownership_Connection_Impl::is_abstract (0);

  //
  // _create (const DDSQoS_in, Topic_in src, OwnershipQosPolicy_in dst)
  //
  topic_ownership_Connection topic_ownership_Connection_Impl::_create (const DDSQoS_in parent, Topic_in src, OwnershipQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, topic_ownership_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void topic_ownership_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_topic_ownership_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS topic_ownership_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Topic
  //
  Topic topic_ownership_Connection_Impl::src_Topic (void) const
  {
    return Topic::_narrow (this->src ());
  }

  //
  // OwnershipQosPolicy
  //
  OwnershipQosPolicy topic_ownership_Connection_Impl::dst_OwnershipQosPolicy (void) const
  {
    return OwnershipQosPolicy::_narrow (this->dst ());
  }
}

