// $Id$

#include "StdAfx.h"
#include "LatencyBudgetQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "LatencyBudgetQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/top_latency_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dr_latency_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dw_latency_Connection.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string LatencyBudgetQosPolicy_Impl::metaname ("LatencyBudgetQosPolicy");

  //
  // _create (const TopicQos_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void LatencyBudgetQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_LatencyBudgetQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_top_latency_Connection
  //
  size_t LatencyBudgetQosPolicy_Impl::dst_top_latency_Connection (std::vector <top_latency_Connection> & items) const
  {
    return this->in_connections <top_latency_Connection> (items);
  }

  //
  // dst_dr_latency_Connection
  //
  size_t LatencyBudgetQosPolicy_Impl::dst_dr_latency_Connection (std::vector <dr_latency_Connection> & items) const
  {
    return this->in_connections <dr_latency_Connection> (items);
  }

  //
  // dst_dw_latency_Connection
  //
  size_t LatencyBudgetQosPolicy_Impl::dst_dw_latency_Connection (std::vector <dw_latency_Connection> & items) const
  {
    return this->in_connections <dw_latency_Connection> (items);
  }
}
