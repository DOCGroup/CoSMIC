#include "StdAfx.h"
#include "dp_userdata_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dp_userdata_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "DQML/Standard/DDSEntities/DomainParticipant.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dp_userdata_Connection_Impl::metaname ("dp_userdata_Connection");

  //
  // is_abstract
  //
  const bool dp_userdata_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, DomainParticipant_in src, UserDataQosPolicy_in dst)
  //
  dp_userdata_Connection dp_userdata_Connection_Impl::_create (const DDSQoS_in parent, DomainParticipant_in src, UserDataQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dp_userdata_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dp_userdata_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dp_userdata_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dp_userdata_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DomainParticipant
  //
  DomainParticipant dp_userdata_Connection_Impl::src_DomainParticipant (void) const
  {
    return DomainParticipant::_narrow (this->src ());
  }

  //
  // UserDataQosPolicy
  //
  UserDataQosPolicy dp_userdata_Connection_Impl::dst_UserDataQosPolicy (void) const
  {
    return UserDataQosPolicy::_narrow (this->dst ());
  }
}

