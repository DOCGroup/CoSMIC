// $Id$

#include "StdAfx.h"
#include "dw_userdata_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_userdata_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_userdata_Connection_Impl::metaname ("dw_userdata_Connection");

  //
  // is_abstract
  //
  const bool dw_userdata_Connection_Impl::is_abstract (0);

  //
  // _create (const DDSQoS_in, DataWriter_in src, UserDataQosPolicy_in dst)
  //
  dw_userdata_Connection dw_userdata_Connection_Impl::_create (const DDSQoS_in parent, DataWriter_in src, UserDataQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dw_userdata_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dw_userdata_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_userdata_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_userdata_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataWriter
  //
  DataWriter dw_userdata_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // UserDataQosPolicy
  //
  UserDataQosPolicy dw_userdata_Connection_Impl::dst_UserDataQosPolicy (void) const
  {
    return UserDataQosPolicy::_narrow (this->dst ());
  }
}

