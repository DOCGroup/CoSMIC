// $Id$

#include "StdAfx.h"
#include "pub_part_Connection.h"

#if !defined (__GAME_INLINE__)
#include "pub_part_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/PartitionQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string pub_part_Connection_Impl::metaname ("pub_part_Connection");

  //
  // is_abstract
  //
  const bool pub_part_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, Publisher_in src, PartitionQosPolicy_in dst)
  //
  pub_part_Connection pub_part_Connection_Impl::_create (const DDSQoS_in parent, Publisher_in src, PartitionQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, pub_part_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void pub_part_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_pub_part_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS pub_part_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Publisher
  //
  Publisher pub_part_Connection_Impl::src_Publisher (void) const
  {
    return Publisher::_narrow (this->src ());
  }

  //
  // PartitionQosPolicy
  //
  PartitionQosPolicy pub_part_Connection_Impl::dst_PartitionQosPolicy (void) const
  {
    return PartitionQosPolicy::_narrow (this->dst ());
  }
}

