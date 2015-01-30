// $Id$

#include "StdAfx.h"
#include "dw_dursvc_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_dursvc_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/DurabilityServiceQosPolicy.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_dursvc_Connection_Impl::metaname ("dw_dursvc_Connection");

  //
  // _create (const DDSQoS_in, DataWriter_in src, DurabilityServiceQosPolicy_in dst)
  //
  dw_dursvc_Connection dw_dursvc_Connection_Impl::_create (const DDSQoS_in parent, DataWriter_in src, DurabilityServiceQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dw_dursvc_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dw_dursvc_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_dursvc_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_dursvc_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataWriter
  //
  DataWriter dw_dursvc_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // DurabilityServiceQosPolicy
  //
  DurabilityServiceQosPolicy dw_dursvc_Connection_Impl::dst_DurabilityServiceQosPolicy (void) const
  {
    return DurabilityServiceQosPolicy::_narrow (this->dst ());
  }
}

