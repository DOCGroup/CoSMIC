// $Id$

#include "StdAfx.h"
#include "top_latency_Connection.h"

#if !defined (__GAME_INLINE__)
#include "top_latency_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Topic.h"
#include "DQML/Standard/QoSPolicies/LatencyBudgetQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string top_latency_Connection_Impl::metaname ("top_latency_Connection");

  //
  // _create (const DDSQoS_in)
  //
  top_latency_Connection top_latency_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < top_latency_Connection > (parent, top_latency_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void top_latency_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_top_latency_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS top_latency_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Topic
  //
  Topic top_latency_Connection_Impl::src_Topic (void) const
  {
    return Topic::_narrow (this->src ());
  }

  //
  // LatencyBudgetQosPolicy
  //
  LatencyBudgetQosPolicy top_latency_Connection_Impl::dst_LatencyBudgetQosPolicy (void) const
  {
    return LatencyBudgetQosPolicy::_narrow (this->dst ());
  }
}

