// $Id$

#include "StdAfx.h"
#include "dw_dstOrder_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_dstOrder_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/DestinationOrderQosPolicy.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_dstOrder_Connection_Impl::metaname ("dw_dstOrder_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dw_dstOrder_Connection dw_dstOrder_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_dstOrder_Connection > (parent, dw_dstOrder_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_dstOrder_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_dstOrder_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_dstOrder_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataWriter
  //
  DataWriter dw_dstOrder_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // DestinationOrderQosPolicy
  //
  DestinationOrderQosPolicy dw_dstOrder_Connection_Impl::dst_DestinationOrderQosPolicy (void) const
  {
    return DestinationOrderQosPolicy::_narrow (this->dst ());
  }
}

