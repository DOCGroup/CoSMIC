// $Id$

#include "StdAfx.h"
#include "pub_groupdata_Connection.h"

#if !defined (__GAME_INLINE__)
#include "pub_groupdata_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/GroupDataQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string pub_groupdata_Connection_Impl::metaname ("pub_groupdata_Connection");

  //
  // _create (const DDSQoS_in)
  //
  pub_groupdata_Connection pub_groupdata_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < pub_groupdata_Connection > (parent, pub_groupdata_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void pub_groupdata_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_pub_groupdata_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS pub_groupdata_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Publisher
  //
  Publisher pub_groupdata_Connection_Impl::src_Publisher (void) const
  {
    return Publisher::_narrow (this->src ());
  }

  //
  // GroupDataQosPolicy
  //
  GroupDataQosPolicy pub_groupdata_Connection_Impl::dst_GroupDataQosPolicy (void) const
  {
    return GroupDataQosPolicy::_narrow (this->dst ());
  }
}

