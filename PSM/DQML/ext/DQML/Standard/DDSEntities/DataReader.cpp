// $Id$

#include "StdAfx.h"
#include "DataReader.h"

#if !defined (__GAME_INLINE__)
#include "DataReader.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/ReliabilityQosPolicy/dr_reliability_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dr_liveliness_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/dr_ownership_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dr_deadline_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dr_latency_Connection.h"
#include "DQML/Standard/TimeBasedFilterQosPolicy/dr_timebased_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dr_durqos_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dr_dstOrder_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dr_userdata_Connection.h"
#include "DQML/Standard/Main/dr_sub_Connection.h"
#include "DQML/Standard/Main/dr_topic_Connection.h"
#include "DQML/Standard/ReaderDataLifecycleQosPolicy/dr_readerdatalifecycle_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dr_res_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dr_history_Connection.h"
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
  // is_abstract
  //
  const bool DataReader_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in)
  //
  DataReader DataReader_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < DataReader > (parent, DataReader_Impl::metaname);
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
  // src_of_dr_reliability_Connection
  //
  size_t DataReader_Impl::src_of_dr_reliability_Connection (std::vector <dr_reliability_Connection> & items) const
  {
    return this->in_connections <dr_reliability_Connection> (items);
  }

  //
  // src_of_dr_reliability_Connection
  //
  GAME::Mga::Collection_T <dr_reliability_Connection> DataReader_Impl::src_of_dr_reliability_Connection (void) const
  {
    return this->in_connections <dr_reliability_Connection> ("src");
  }

  //
  // src_of_dr_liveliness_Connection
  //
  size_t DataReader_Impl::src_of_dr_liveliness_Connection (std::vector <dr_liveliness_Connection> & items) const
  {
    return this->in_connections <dr_liveliness_Connection> (items);
  }

  //
  // src_of_dr_liveliness_Connection
  //
  GAME::Mga::Collection_T <dr_liveliness_Connection> DataReader_Impl::src_of_dr_liveliness_Connection (void) const
  {
    return this->in_connections <dr_liveliness_Connection> ("src");
  }

  //
  // src_of_dr_ownership_Connection
  //
  size_t DataReader_Impl::src_of_dr_ownership_Connection (std::vector <dr_ownership_Connection> & items) const
  {
    return this->in_connections <dr_ownership_Connection> (items);
  }

  //
  // src_of_dr_ownership_Connection
  //
  GAME::Mga::Collection_T <dr_ownership_Connection> DataReader_Impl::src_of_dr_ownership_Connection (void) const
  {
    return this->in_connections <dr_ownership_Connection> ("src");
  }

  //
  // src_of_dr_deadline_Connection
  //
  size_t DataReader_Impl::src_of_dr_deadline_Connection (std::vector <dr_deadline_Connection> & items) const
  {
    return this->in_connections <dr_deadline_Connection> (items);
  }

  //
  // src_of_dr_deadline_Connection
  //
  GAME::Mga::Collection_T <dr_deadline_Connection> DataReader_Impl::src_of_dr_deadline_Connection (void) const
  {
    return this->in_connections <dr_deadline_Connection> ("src");
  }

  //
  // src_of_dr_latency_Connection
  //
  size_t DataReader_Impl::src_of_dr_latency_Connection (std::vector <dr_latency_Connection> & items) const
  {
    return this->in_connections <dr_latency_Connection> (items);
  }

  //
  // src_of_dr_latency_Connection
  //
  GAME::Mga::Collection_T <dr_latency_Connection> DataReader_Impl::src_of_dr_latency_Connection (void) const
  {
    return this->in_connections <dr_latency_Connection> ("src");
  }

  //
  // src_of_dr_timebased_Connection
  //
  size_t DataReader_Impl::src_of_dr_timebased_Connection (std::vector <dr_timebased_Connection> & items) const
  {
    return this->in_connections <dr_timebased_Connection> (items);
  }

  //
  // src_of_dr_timebased_Connection
  //
  GAME::Mga::Collection_T <dr_timebased_Connection> DataReader_Impl::src_of_dr_timebased_Connection (void) const
  {
    return this->in_connections <dr_timebased_Connection> ("src");
  }

  //
  // src_of_dr_durqos_Connection
  //
  size_t DataReader_Impl::src_of_dr_durqos_Connection (std::vector <dr_durqos_Connection> & items) const
  {
    return this->in_connections <dr_durqos_Connection> (items);
  }

  //
  // src_of_dr_durqos_Connection
  //
  GAME::Mga::Collection_T <dr_durqos_Connection> DataReader_Impl::src_of_dr_durqos_Connection (void) const
  {
    return this->in_connections <dr_durqos_Connection> ("src");
  }

  //
  // src_of_dr_dstOrder_Connection
  //
  size_t DataReader_Impl::src_of_dr_dstOrder_Connection (std::vector <dr_dstOrder_Connection> & items) const
  {
    return this->in_connections <dr_dstOrder_Connection> (items);
  }

  //
  // src_of_dr_dstOrder_Connection
  //
  GAME::Mga::Collection_T <dr_dstOrder_Connection> DataReader_Impl::src_of_dr_dstOrder_Connection (void) const
  {
    return this->in_connections <dr_dstOrder_Connection> ("src");
  }

  //
  // src_of_dr_userdata_Connection
  //
  size_t DataReader_Impl::src_of_dr_userdata_Connection (std::vector <dr_userdata_Connection> & items) const
  {
    return this->in_connections <dr_userdata_Connection> (items);
  }

  //
  // src_of_dr_userdata_Connection
  //
  GAME::Mga::Collection_T <dr_userdata_Connection> DataReader_Impl::src_of_dr_userdata_Connection (void) const
  {
    return this->in_connections <dr_userdata_Connection> ("src");
  }

  //
  // src_of_dr_topic_Connection
  //
  size_t DataReader_Impl::src_of_dr_topic_Connection (std::vector <dr_topic_Connection> & items) const
  {
    return this->in_connections <dr_topic_Connection> (items);
  }

  //
  // src_of_dr_topic_Connection
  //
  GAME::Mga::Collection_T <dr_topic_Connection> DataReader_Impl::src_of_dr_topic_Connection (void) const
  {
    return this->in_connections <dr_topic_Connection> ("src");
  }

  //
  // src_of_dr_readerdatalifecycle_Connection
  //
  size_t DataReader_Impl::src_of_dr_readerdatalifecycle_Connection (std::vector <dr_readerdatalifecycle_Connection> & items) const
  {
    return this->in_connections <dr_readerdatalifecycle_Connection> (items);
  }

  //
  // src_of_dr_readerdatalifecycle_Connection
  //
  GAME::Mga::Collection_T <dr_readerdatalifecycle_Connection> DataReader_Impl::src_of_dr_readerdatalifecycle_Connection (void) const
  {
    return this->in_connections <dr_readerdatalifecycle_Connection> ("src");
  }

  //
  // src_of_dr_res_Connection
  //
  size_t DataReader_Impl::src_of_dr_res_Connection (std::vector <dr_res_Connection> & items) const
  {
    return this->in_connections <dr_res_Connection> (items);
  }

  //
  // src_of_dr_res_Connection
  //
  GAME::Mga::Collection_T <dr_res_Connection> DataReader_Impl::src_of_dr_res_Connection (void) const
  {
    return this->in_connections <dr_res_Connection> ("src");
  }

  //
  // src_of_dr_history_Connection
  //
  size_t DataReader_Impl::src_of_dr_history_Connection (std::vector <dr_history_Connection> & items) const
  {
    return this->in_connections <dr_history_Connection> (items);
  }

  //
  // src_of_dr_history_Connection
  //
  GAME::Mga::Collection_T <dr_history_Connection> DataReader_Impl::src_of_dr_history_Connection (void) const
  {
    return this->in_connections <dr_history_Connection> ("src");
  }

  //
  // dst_of_dr_sub_Connection
  //
  size_t DataReader_Impl::dst_of_dr_sub_Connection (std::vector <dr_sub_Connection> & items) const
  {
    return this->in_connections <dr_sub_Connection> (items);
  }

  //
  // dst_of_dr_sub_Connection
  //
  GAME::Mga::Collection_T <dr_sub_Connection> DataReader_Impl::dst_of_dr_sub_Connection (void) const
  {
    return this->in_connections <dr_sub_Connection> ("dst");
  }
}

