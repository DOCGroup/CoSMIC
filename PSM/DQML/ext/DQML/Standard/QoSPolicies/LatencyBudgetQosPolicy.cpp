#include "StdAfx.h"
#include "LatencyBudgetQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "LatencyBudgetQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/top_latency_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dr_latency_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dw_latency_Connection.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
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
  // is_abstract
  //
  const bool LatencyBudgetQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataReaderQos_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  LatencyBudgetQosPolicy LatencyBudgetQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < LatencyBudgetQosPolicy > (parent, LatencyBudgetQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void LatencyBudgetQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LatencyBudgetQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos LatencyBudgetQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos LatencyBudgetQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos LatencyBudgetQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_of_top_latency_Connection
  //
  size_t LatencyBudgetQosPolicy_Impl::dst_of_top_latency_Connection (std::vector <top_latency_Connection> & items) const
  {
    return this->in_connections <top_latency_Connection> (items);
  }

  //
  // dst_of_top_latency_Connection
  //
  GAME::Mga::Collection_T <top_latency_Connection> LatencyBudgetQosPolicy_Impl::dst_of_top_latency_Connection (void) const
  {
    return this->in_connections <top_latency_Connection> ("dst");
  }

  //
  // dst_of_dr_latency_Connection
  //
  size_t LatencyBudgetQosPolicy_Impl::dst_of_dr_latency_Connection (std::vector <dr_latency_Connection> & items) const
  {
    return this->in_connections <dr_latency_Connection> (items);
  }

  //
  // dst_of_dr_latency_Connection
  //
  GAME::Mga::Collection_T <dr_latency_Connection> LatencyBudgetQosPolicy_Impl::dst_of_dr_latency_Connection (void) const
  {
    return this->in_connections <dr_latency_Connection> ("dst");
  }

  //
  // dst_of_dw_latency_Connection
  //
  size_t LatencyBudgetQosPolicy_Impl::dst_of_dw_latency_Connection (std::vector <dw_latency_Connection> & items) const
  {
    return this->in_connections <dw_latency_Connection> (items);
  }

  //
  // dst_of_dw_latency_Connection
  //
  GAME::Mga::Collection_T <dw_latency_Connection> LatencyBudgetQosPolicy_Impl::dst_of_dw_latency_Connection (void) const
  {
    return this->in_connections <dw_latency_Connection> ("dst");
  }
}

