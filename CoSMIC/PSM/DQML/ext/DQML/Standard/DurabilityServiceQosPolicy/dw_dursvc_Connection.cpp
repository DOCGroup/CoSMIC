// $Id$

#include "StdAfx.h"
#include "dw_dursvc_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_dursvc_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/QoSPolicies/DurabilityServiceQosPolicy.h"
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
  // _create (const DDSQoS_in)
  //
  dw_dursvc_Connection dw_dursvc_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_dursvc_Connection > (parent, dw_dursvc_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_dursvc_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dw_dursvc_Connection (this);
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
