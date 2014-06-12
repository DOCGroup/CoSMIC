// $Id$

#include "StdAfx.h"
#include "dw_transpri_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_transpri_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/TransportPriorityQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_transpri_Connection_Impl::metaname ("dw_transpri_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dw_transpri_Connection dw_transpri_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_transpri_Connection > (parent, dw_transpri_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_transpri_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_transpri_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_transpri_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataWriter
  //
  DataWriter dw_transpri_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // TransportPriorityQosPolicy
  //
  TransportPriorityQosPolicy dw_transpri_Connection_Impl::dst_TransportPriorityQosPolicy (void) const
  {
    return TransportPriorityQosPolicy::_narrow (this->dst ());
  }
}

