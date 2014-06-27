// $Id$

#include "StdAfx.h"
#include "top_deadline_Connection.h"

#if !defined (__GAME_INLINE__)
#include "top_deadline_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
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
  const std::string top_deadline_Connection_Impl::metaname ("top_deadline_Connection");

  //
  // _create (const DDSQoS_in)
  //
  top_deadline_Connection top_deadline_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < top_deadline_Connection > (parent, top_deadline_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void top_deadline_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_top_deadline_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS top_deadline_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Topic
  //
  Topic top_deadline_Connection_Impl::src_Topic (void) const
  {
    return Topic::_narrow (this->src ());
  }

  //
  // DeadlineQosPolicy
  //
  DeadlineQosPolicy top_deadline_Connection_Impl::dst_DeadlineQosPolicy (void) const
  {
    return DeadlineQosPolicy::_narrow (this->dst ());
  }
}

