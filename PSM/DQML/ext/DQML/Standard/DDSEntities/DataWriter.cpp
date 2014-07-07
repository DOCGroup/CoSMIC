// $Id$

#include "StdAfx.h"
#include "DataWriter.h"

#if !defined (__GAME_INLINE__)
#include "DataWriter.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/OwnershipStrengthQosPolicy/dw_ownerstrength_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dw_dstOrder_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dw_durqos_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dw_latency_Connection.h"
#include "DQML/Standard/LifespanQosPolicy/dw_lifespan_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dw_deadline_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dw_history_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/dw_reliability_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dw_userdata_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dw_res_Connection.h"
#include "DQML/Standard/Main/dw_topic_Connection.h"
#include "DQML/Standard/Main/dw_pub_Connection.h"
#include "DQML/Standard/WriterDataLifecycleQosPolicy/dw_writerdatalifecycle_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dw_liveliness_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/dw_ownership_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/dw_transpri_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/dw_dursvc_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DataWriter_Impl::metaname ("DataWriter");

  //
  // _create (const DDSQoS_in)
  //
  DataWriter DataWriter_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < DataWriter > (parent, DataWriter_Impl::metaname);
  }

  //
  // accept
  //
  void DataWriter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DataWriter (this);
    else
      v->visit_Model (this);
  }

  //
  // src_dw_ownerstrength_Connection
  //
  size_t DataWriter_Impl::src_dw_ownerstrength_Connection (std::vector <dw_ownerstrength_Connection> & items) const
  {
    return this->in_connections <dw_ownerstrength_Connection> (items);
  }

  //
  // src_dw_dstOrder_Connection
  //
  size_t DataWriter_Impl::src_dw_dstOrder_Connection (std::vector <dw_dstOrder_Connection> & items) const
  {
    return this->in_connections <dw_dstOrder_Connection> (items);
  }

  //
  // src_dw_durqos_Connection
  //
  size_t DataWriter_Impl::src_dw_durqos_Connection (std::vector <dw_durqos_Connection> & items) const
  {
    return this->in_connections <dw_durqos_Connection> (items);
  }

  //
  // src_dw_latency_Connection
  //
  size_t DataWriter_Impl::src_dw_latency_Connection (std::vector <dw_latency_Connection> & items) const
  {
    return this->in_connections <dw_latency_Connection> (items);
  }

  //
  // src_dw_lifespan_Connection
  //
  size_t DataWriter_Impl::src_dw_lifespan_Connection (std::vector <dw_lifespan_Connection> & items) const
  {
    return this->in_connections <dw_lifespan_Connection> (items);
  }

  //
  // src_dw_deadline_Connection
  //
  size_t DataWriter_Impl::src_dw_deadline_Connection (std::vector <dw_deadline_Connection> & items) const
  {
    return this->in_connections <dw_deadline_Connection> (items);
  }

  //
  // src_dw_history_Connection
  //
  size_t DataWriter_Impl::src_dw_history_Connection (std::vector <dw_history_Connection> & items) const
  {
    return this->in_connections <dw_history_Connection> (items);
  }

  //
  // src_dw_reliability_Connection
  //
  size_t DataWriter_Impl::src_dw_reliability_Connection (std::vector <dw_reliability_Connection> & items) const
  {
    return this->in_connections <dw_reliability_Connection> (items);
  }

  //
  // src_dw_userdata_Connection
  //
  size_t DataWriter_Impl::src_dw_userdata_Connection (std::vector <dw_userdata_Connection> & items) const
  {
    return this->in_connections <dw_userdata_Connection> (items);
  }

  //
  // src_dw_res_Connection
  //
  size_t DataWriter_Impl::src_dw_res_Connection (std::vector <dw_res_Connection> & items) const
  {
    return this->in_connections <dw_res_Connection> (items);
  }

  //
  // src_dw_topic_Connection
  //
  size_t DataWriter_Impl::src_dw_topic_Connection (std::vector <dw_topic_Connection> & items) const
  {
    return this->in_connections <dw_topic_Connection> (items);
  }

  //
  // src_dw_writerdatalifecycle_Connection
  //
  size_t DataWriter_Impl::src_dw_writerdatalifecycle_Connection (std::vector <dw_writerdatalifecycle_Connection> & items) const
  {
    return this->in_connections <dw_writerdatalifecycle_Connection> (items);
  }

  //
  // src_dw_liveliness_Connection
  //
  size_t DataWriter_Impl::src_dw_liveliness_Connection (std::vector <dw_liveliness_Connection> & items) const
  {
    return this->in_connections <dw_liveliness_Connection> (items);
  }

  //
  // src_dw_ownership_Connection
  //
  size_t DataWriter_Impl::src_dw_ownership_Connection (std::vector <dw_ownership_Connection> & items) const
  {
    return this->in_connections <dw_ownership_Connection> (items);
  }

  //
  // src_dw_transpri_Connection
  //
  size_t DataWriter_Impl::src_dw_transpri_Connection (std::vector <dw_transpri_Connection> & items) const
  {
    return this->in_connections <dw_transpri_Connection> (items);
  }

  //
  // src_dw_dursvc_Connection
  //
  size_t DataWriter_Impl::src_dw_dursvc_Connection (std::vector <dw_dursvc_Connection> & items) const
  {
    return this->in_connections <dw_dursvc_Connection> (items);
  }

  //
  // dst_dw_pub_Connection
  //
  size_t DataWriter_Impl::dst_dw_pub_Connection (std::vector <dw_pub_Connection> & items) const
  {
    return this->in_connections <dw_pub_Connection> (items);
  }
}

