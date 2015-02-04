// $Id$

#include "StdAfx.h"
#include "sub_presqos_Connection.h"

#if !defined (__GAME_INLINE__)
#include "sub_presqos_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/PresentationQosPolicy.h"
#include "DQML/Standard/DDSEntities/Subscriber.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string sub_presqos_Connection_Impl::metaname ("sub_presqos_Connection");

  //
  // is_abstract
  //
  const bool sub_presqos_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, Subscriber_in src, PresentationQosPolicy_in dst)
  //
  sub_presqos_Connection sub_presqos_Connection_Impl::_create (const DDSQoS_in parent, Subscriber_in src, PresentationQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, sub_presqos_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void sub_presqos_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_sub_presqos_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS sub_presqos_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Subscriber
  //
  Subscriber sub_presqos_Connection_Impl::src_Subscriber (void) const
  {
    return Subscriber::_narrow (this->src ());
  }

  //
  // PresentationQosPolicy
  //
  PresentationQosPolicy sub_presqos_Connection_Impl::dst_PresentationQosPolicy (void) const
  {
    return PresentationQosPolicy::_narrow (this->dst ());
  }
}

