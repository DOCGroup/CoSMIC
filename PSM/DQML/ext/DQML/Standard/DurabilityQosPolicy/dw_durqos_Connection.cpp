// $Id$

#include "StdAfx.h"
#include "dw_durqos_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_durqos_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
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
  // _create (const DDSQoS_in)
  //
  dw_durqos_Connection dw_durqos_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_durqos_Connection > (parent, dw_durqos_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_durqos_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dw_durqos_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

