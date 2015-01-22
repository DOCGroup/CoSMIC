// $Id$

#include "StdAfx.h"
#include "dw_durqos_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_durqos_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_durqos_Connection_Impl::metaname ("dw_durqos_Connection");

  //
  // _create (const DDSQoS_in, DataWriter_in src, DurabilityQosPolicy_in dst)
  //
  dw_durqos_Connection dw_durqos_Connection_Impl::_create (const DDSQoS_in parent, DataWriter_in src, DurabilityQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dw_durqos_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dw_durqos_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_durqos_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_durqos_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataWriter
  //
  DataWriter dw_durqos_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // DurabilityQosPolicy
  //
  DurabilityQosPolicy dw_durqos_Connection_Impl::dst_DurabilityQosPolicy (void) const
  {
    return DurabilityQosPolicy::_narrow (this->dst ());
  }
}

