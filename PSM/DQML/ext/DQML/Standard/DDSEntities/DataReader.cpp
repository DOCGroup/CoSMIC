// $Id$

#include "StdAfx.h"
#include "DataReader.h"

#if !defined (__GAME_INLINE__)
#include "DataReader.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/TimeBasedFilterQosPolicy/dr_timebased_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dr_res_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dr_liveliness_Connection.h"
#include "DQML/Standard/ReaderDataLifecycleQosPolicy/dr_readerdatalifecycle_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dr_dstOrder_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/dr_ownership_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dr_durqos_Connection.h"
#include "DQML/Standard/Main/dr_topic_Connection.h"
#include "DQML/Standard/Main/dr_sub_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dr_deadline_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dr_history_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dr_latency_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dr_userdata_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/dr_reliability_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DataReader_Impl::metaname ("DataReader");

  //
  // _create (const DDSQoS_in)
  //
  DataReader DataReader_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < DataReader > (parent, DataReader_Impl::metaname);
  }

  //
  // accept
  //
  void DataReader_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DataReader (this);
    else
      v->visit_Model (this);
  }

  //
  // src_dr_timebased_Connection
  //
  size_t DataReader_Impl::src_dr_timebased_Connection (std::vector <dr_timebased_Connection> & items) const
  {
    return this->in_connections <dr_timebased_Connection> (items);
  }

  //
  // src_dr_res_Connection
  //
  size_t DataReader_Impl::src_dr_res_Connection (std::vector <dr_res_Connection> & items) const
  {
    return this->in_connections <dr_res_Connection> (items);
  }

  //
  // src_dr_liveliness_Connection
  //
  size_t DataReader_Impl::src_dr_liveliness_Connection (std::vector <dr_liveliness_Connection> & items) const
  {
    return this->in_connections <dr_liveliness_Connection> (items);
  }

  //
  // src_dr_readerdatalifecycle_Connection
  //
  size_t DataReader_Impl::src_dr_readerdatalifecycle_Connection (std::vector <dr_readerdatalifecycle_Connection> & items) const
  {
    return this->in_connections <dr_readerdatalifecycle_Connection> (items);
  }

  //
  // src_dr_dstOrder_Connection
  //
  size_t DataReader_Impl::src_dr_dstOrder_Connection (std::vector <dr_dstOrder_Connection> & items) const
  {
    return this->in_connections <dr_dstOrder_Connection> (items);
  }

  //
  // src_dr_ownership_Connection
  //
  size_t DataReader_Impl::src_dr_ownership_Connection (std::vector <dr_ownership_Connection> & items) const
  {
    return this->in_connections <dr_ownership_Connection> (items);
  }

  //
  // src_dr_durqos_Connection
  //
  size_t DataReader_Impl::src_dr_durqos_Connection (std::vector <dr_durqos_Connection> & items) const
  {
    return this->in_connections <dr_durqos_Connection> (items);
  }

  //
  // src_dr_topic_Connection
  //
  size_t DataReader_Impl::src_dr_topic_Connection (std::vector <dr_topic_Connection> & items) const
  {
    return this->in_connections <dr_topic_Connection> (items);
  }

  //
  // src_dr_deadline_Connection
  //
  size_t DataReader_Impl::src_dr_deadline_Connection (std::vector <dr_deadline_Connection> & items) const
  {
    return this->in_connections <dr_deadline_Connection> (items);
  }

  //
  // src_dr_history_Connection
  //
  size_t DataReader_Impl::src_dr_history_Connection (std::vector <dr_history_Connection> & items) const
  {
    return this->in_connections <dr_history_Connection> (items);
  }

  //
  // src_dr_latency_Connection
  //
  size_t DataReader_Impl::src_dr_latency_Connection (std::vector <dr_latency_Connection> & items) const
  {
    return this->in_connections <dr_latency_Connection> (items);
  }

  //
  // src_dr_userdata_Connection
  //
  size_t DataReader_Impl::src_dr_userdata_Connection (std::vector <dr_userdata_Connection> & items) const
  {
    return this->in_connections <dr_userdata_Connection> (items);
  }

  //
  // src_dr_reliability_Connection
  //
  size_t DataReader_Impl::src_dr_reliability_Connection (std::vector <dr_reliability_Connection> & items) const
  {
    return this->in_connections <dr_reliability_Connection> (items);
  }

  //
  // dst_dr_sub_Connection
  //
  size_t DataReader_Impl::dst_dr_sub_Connection (std::vector <dr_sub_Connection> & items) const
  {
    return this->in_connections <dr_sub_Connection> (items);
  }
}

