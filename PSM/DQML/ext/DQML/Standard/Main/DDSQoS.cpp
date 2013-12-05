// $Id$

#include "StdAfx.h"
#include "DDSQoS.h"

#if !defined (__GAME_INLINE__)
#include "DDSQoS.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/dr_topic_Connection.h"
#include "DQML/Standard/Main/dw_topic_Connection.h"
#include "DQML/Standard/Main/dw_pub_Connection.h"
#include "DQML/Standard/Main/dr_sub_Connection.h"
#include "DQML/Standard/Main/dp_topic_Connection.h"
#include "DQML/Standard/Main/dp_pub_Connection.h"
#include "DQML/Standard/Main/dp_sub_Connection.h"
#include "DQML/Standard/Main/dpf_dp_Connection.h"
#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "DQML/Standard/DurabilityQosPolicy/dr_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/topic_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dw_durqos_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/pub_presqos_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/sub_presqos_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dr_deadline_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/top_deadline_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dw_deadline_Connection.h"
#include "DQML/Standard/TimeBasedFilterQosPolicy/dr_timebased_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/top_latency_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dr_latency_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dw_latency_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/dr_ownership_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/topic_ownership_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/dw_ownership_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dr_liveliness_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/topic_liveliness_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dw_liveliness_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/dr_reliability_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/topic_reliability_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/dw_reliability_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dr_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/topic_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dw_dstOrder_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dp_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dr_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dw_userdata_Connection.h"
#include "DQML/Standard/TopicDataQosPolicy/topic_topicdata_Connection.h"
#include "DQML/Standard/GroupDataQosPolicy/pub_groupdata_Connection.h"
#include "DQML/Standard/GroupDataQosPolicy/sub_groupdata_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/topic_dursvc_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/dw_dursvc_Connection.h"
#include "DQML/Standard/OwnershipStrengthQosPolicy/dw_ownerstrength_Connection.h"
#include "DQML/Standard/PartitionQosPolicy/pub_part_Connection.h"
#include "DQML/Standard/PartitionQosPolicy/sub_part_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/dw_transpri_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/topic_transpri_Connection.h"
#include "DQML/Standard/LifespanQosPolicy/topic_lifespan_Connection.h"
#include "DQML/Standard/LifespanQosPolicy/dw_lifespan_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dr_history_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/topic_history_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dw_history_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dr_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/topic_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dw_res_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dpfactory_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dp_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/pub_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/sub_entityfactory_Connection.h"
#include "DQML/Standard/WriterDataLifecycleQosPolicy/dw_writerdatalifecycle_Connection.h"
#include "DQML/Standard/ReaderDataLifecycleQosPolicy/dr_readerdatalifecycle_Connection.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DDSQoS_Impl::metaname ("DDSQoS");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  DDSQoS DDSQoS_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <DDSQoS> (parent, DDSQoS_Impl::metaname);
  }

  //
  // accept
  //
  void DDSQoS_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DDSQoS (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_dr_topic_Connections
  //
  size_t DDSQoS_Impl::get_dr_topic_Connections (std::vector <dr_topic_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_topic_Connections
  //
  ::GAME::Mga::Iterator <dr_topic_Connection> DDSQoS_Impl::get_dr_topic_Connections (void) const
  {
    return this->children <dr_topic_Connection> ();
  }

  //
  // get_dw_topic_Connections
  //
  size_t DDSQoS_Impl::get_dw_topic_Connections (std::vector <dw_topic_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_topic_Connections
  //
  ::GAME::Mga::Iterator <dw_topic_Connection> DDSQoS_Impl::get_dw_topic_Connections (void) const
  {
    return this->children <dw_topic_Connection> ();
  }

  //
  // get_dw_pub_Connections
  //
  size_t DDSQoS_Impl::get_dw_pub_Connections (std::vector <dw_pub_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_pub_Connections
  //
  ::GAME::Mga::Iterator <dw_pub_Connection> DDSQoS_Impl::get_dw_pub_Connections (void) const
  {
    return this->children <dw_pub_Connection> ();
  }

  //
  // get_dr_sub_Connections
  //
  size_t DDSQoS_Impl::get_dr_sub_Connections (std::vector <dr_sub_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_sub_Connections
  //
  ::GAME::Mga::Iterator <dr_sub_Connection> DDSQoS_Impl::get_dr_sub_Connections (void) const
  {
    return this->children <dr_sub_Connection> ();
  }

  //
  // get_dp_topic_Connections
  //
  size_t DDSQoS_Impl::get_dp_topic_Connections (std::vector <dp_topic_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dp_topic_Connections
  //
  ::GAME::Mga::Iterator <dp_topic_Connection> DDSQoS_Impl::get_dp_topic_Connections (void) const
  {
    return this->children <dp_topic_Connection> ();
  }

  //
  // get_dp_pub_Connections
  //
  size_t DDSQoS_Impl::get_dp_pub_Connections (std::vector <dp_pub_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dp_pub_Connections
  //
  ::GAME::Mga::Iterator <dp_pub_Connection> DDSQoS_Impl::get_dp_pub_Connections (void) const
  {
    return this->children <dp_pub_Connection> ();
  }

  //
  // get_dp_sub_Connections
  //
  size_t DDSQoS_Impl::get_dp_sub_Connections (std::vector <dp_sub_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dp_sub_Connections
  //
  ::GAME::Mga::Iterator <dp_sub_Connection> DDSQoS_Impl::get_dp_sub_Connections (void) const
  {
    return this->children <dp_sub_Connection> ();
  }

  //
  // get_dpf_dp_Connections
  //
  size_t DDSQoS_Impl::get_dpf_dp_Connections (std::vector <dpf_dp_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dpf_dp_Connections
  //
  ::GAME::Mga::Iterator <dpf_dp_Connection> DDSQoS_Impl::get_dpf_dp_Connections (void) const
  {
    return this->children <dpf_dp_Connection> ();
  }

  //
  // get_DomainEntitys
  //
  size_t DDSQoS_Impl::get_DomainEntitys (std::vector <DomainEntity> & items) const
  {
    return this->children (items);
  }

  //
  // get_DomainEntitys
  //
  ::GAME::Mga::Iterator <DomainEntity> DDSQoS_Impl::get_DomainEntitys (void) const
  {
    return this->children <DomainEntity> ();
  }

  //
  // get_QoSPolicys
  //
  size_t DDSQoS_Impl::get_QoSPolicys (std::vector <QoSPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_QoSPolicys
  //
  ::GAME::Mga::Iterator <QoSPolicy> DDSQoS_Impl::get_QoSPolicys (void) const
  {
    return this->children <QoSPolicy> ();
  }

  //
  // get_dr_durqos_Connections
  //
  size_t DDSQoS_Impl::get_dr_durqos_Connections (std::vector <dr_durqos_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_durqos_Connections
  //
  ::GAME::Mga::Iterator <dr_durqos_Connection> DDSQoS_Impl::get_dr_durqos_Connections (void) const
  {
    return this->children <dr_durqos_Connection> ();
  }

  //
  // get_topic_durqos_Connections
  //
  size_t DDSQoS_Impl::get_topic_durqos_Connections (std::vector <topic_durqos_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_durqos_Connections
  //
  ::GAME::Mga::Iterator <topic_durqos_Connection> DDSQoS_Impl::get_topic_durqos_Connections (void) const
  {
    return this->children <topic_durqos_Connection> ();
  }

  //
  // get_dw_durqos_Connections
  //
  size_t DDSQoS_Impl::get_dw_durqos_Connections (std::vector <dw_durqos_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_durqos_Connections
  //
  ::GAME::Mga::Iterator <dw_durqos_Connection> DDSQoS_Impl::get_dw_durqos_Connections (void) const
  {
    return this->children <dw_durqos_Connection> ();
  }

  //
  // get_pub_presqos_Connections
  //
  size_t DDSQoS_Impl::get_pub_presqos_Connections (std::vector <pub_presqos_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_pub_presqos_Connections
  //
  ::GAME::Mga::Iterator <pub_presqos_Connection> DDSQoS_Impl::get_pub_presqos_Connections (void) const
  {
    return this->children <pub_presqos_Connection> ();
  }

  //
  // get_sub_presqos_Connections
  //
  size_t DDSQoS_Impl::get_sub_presqos_Connections (std::vector <sub_presqos_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_sub_presqos_Connections
  //
  ::GAME::Mga::Iterator <sub_presqos_Connection> DDSQoS_Impl::get_sub_presqos_Connections (void) const
  {
    return this->children <sub_presqos_Connection> ();
  }

  //
  // get_dr_deadline_Connections
  //
  size_t DDSQoS_Impl::get_dr_deadline_Connections (std::vector <dr_deadline_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_deadline_Connections
  //
  ::GAME::Mga::Iterator <dr_deadline_Connection> DDSQoS_Impl::get_dr_deadline_Connections (void) const
  {
    return this->children <dr_deadline_Connection> ();
  }

  //
  // get_top_deadline_Connections
  //
  size_t DDSQoS_Impl::get_top_deadline_Connections (std::vector <top_deadline_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_top_deadline_Connections
  //
  ::GAME::Mga::Iterator <top_deadline_Connection> DDSQoS_Impl::get_top_deadline_Connections (void) const
  {
    return this->children <top_deadline_Connection> ();
  }

  //
  // get_dw_deadline_Connections
  //
  size_t DDSQoS_Impl::get_dw_deadline_Connections (std::vector <dw_deadline_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_deadline_Connections
  //
  ::GAME::Mga::Iterator <dw_deadline_Connection> DDSQoS_Impl::get_dw_deadline_Connections (void) const
  {
    return this->children <dw_deadline_Connection> ();
  }

  //
  // get_dr_timebased_Connections
  //
  size_t DDSQoS_Impl::get_dr_timebased_Connections (std::vector <dr_timebased_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_timebased_Connections
  //
  ::GAME::Mga::Iterator <dr_timebased_Connection> DDSQoS_Impl::get_dr_timebased_Connections (void) const
  {
    return this->children <dr_timebased_Connection> ();
  }

  //
  // get_top_latency_Connections
  //
  size_t DDSQoS_Impl::get_top_latency_Connections (std::vector <top_latency_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_top_latency_Connections
  //
  ::GAME::Mga::Iterator <top_latency_Connection> DDSQoS_Impl::get_top_latency_Connections (void) const
  {
    return this->children <top_latency_Connection> ();
  }

  //
  // get_dr_latency_Connections
  //
  size_t DDSQoS_Impl::get_dr_latency_Connections (std::vector <dr_latency_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_latency_Connections
  //
  ::GAME::Mga::Iterator <dr_latency_Connection> DDSQoS_Impl::get_dr_latency_Connections (void) const
  {
    return this->children <dr_latency_Connection> ();
  }

  //
  // get_dw_latency_Connections
  //
  size_t DDSQoS_Impl::get_dw_latency_Connections (std::vector <dw_latency_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_latency_Connections
  //
  ::GAME::Mga::Iterator <dw_latency_Connection> DDSQoS_Impl::get_dw_latency_Connections (void) const
  {
    return this->children <dw_latency_Connection> ();
  }

  //
  // get_dr_ownership_Connections
  //
  size_t DDSQoS_Impl::get_dr_ownership_Connections (std::vector <dr_ownership_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_ownership_Connections
  //
  ::GAME::Mga::Iterator <dr_ownership_Connection> DDSQoS_Impl::get_dr_ownership_Connections (void) const
  {
    return this->children <dr_ownership_Connection> ();
  }

  //
  // get_topic_ownership_Connections
  //
  size_t DDSQoS_Impl::get_topic_ownership_Connections (std::vector <topic_ownership_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_ownership_Connections
  //
  ::GAME::Mga::Iterator <topic_ownership_Connection> DDSQoS_Impl::get_topic_ownership_Connections (void) const
  {
    return this->children <topic_ownership_Connection> ();
  }

  //
  // get_dw_ownership_Connections
  //
  size_t DDSQoS_Impl::get_dw_ownership_Connections (std::vector <dw_ownership_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_ownership_Connections
  //
  ::GAME::Mga::Iterator <dw_ownership_Connection> DDSQoS_Impl::get_dw_ownership_Connections (void) const
  {
    return this->children <dw_ownership_Connection> ();
  }

  //
  // get_dr_liveliness_Connections
  //
  size_t DDSQoS_Impl::get_dr_liveliness_Connections (std::vector <dr_liveliness_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_liveliness_Connections
  //
  ::GAME::Mga::Iterator <dr_liveliness_Connection> DDSQoS_Impl::get_dr_liveliness_Connections (void) const
  {
    return this->children <dr_liveliness_Connection> ();
  }

  //
  // get_topic_liveliness_Connections
  //
  size_t DDSQoS_Impl::get_topic_liveliness_Connections (std::vector <topic_liveliness_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_liveliness_Connections
  //
  ::GAME::Mga::Iterator <topic_liveliness_Connection> DDSQoS_Impl::get_topic_liveliness_Connections (void) const
  {
    return this->children <topic_liveliness_Connection> ();
  }

  //
  // get_dw_liveliness_Connections
  //
  size_t DDSQoS_Impl::get_dw_liveliness_Connections (std::vector <dw_liveliness_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_liveliness_Connections
  //
  ::GAME::Mga::Iterator <dw_liveliness_Connection> DDSQoS_Impl::get_dw_liveliness_Connections (void) const
  {
    return this->children <dw_liveliness_Connection> ();
  }

  //
  // get_dr_reliability_Connections
  //
  size_t DDSQoS_Impl::get_dr_reliability_Connections (std::vector <dr_reliability_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_reliability_Connections
  //
  ::GAME::Mga::Iterator <dr_reliability_Connection> DDSQoS_Impl::get_dr_reliability_Connections (void) const
  {
    return this->children <dr_reliability_Connection> ();
  }

  //
  // get_topic_reliability_Connections
  //
  size_t DDSQoS_Impl::get_topic_reliability_Connections (std::vector <topic_reliability_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_reliability_Connections
  //
  ::GAME::Mga::Iterator <topic_reliability_Connection> DDSQoS_Impl::get_topic_reliability_Connections (void) const
  {
    return this->children <topic_reliability_Connection> ();
  }

  //
  // get_dw_reliability_Connections
  //
  size_t DDSQoS_Impl::get_dw_reliability_Connections (std::vector <dw_reliability_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_reliability_Connections
  //
  ::GAME::Mga::Iterator <dw_reliability_Connection> DDSQoS_Impl::get_dw_reliability_Connections (void) const
  {
    return this->children <dw_reliability_Connection> ();
  }

  //
  // get_dr_dstOrder_Connections
  //
  size_t DDSQoS_Impl::get_dr_dstOrder_Connections (std::vector <dr_dstOrder_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_dstOrder_Connections
  //
  ::GAME::Mga::Iterator <dr_dstOrder_Connection> DDSQoS_Impl::get_dr_dstOrder_Connections (void) const
  {
    return this->children <dr_dstOrder_Connection> ();
  }

  //
  // get_topic_dstOrder_Connections
  //
  size_t DDSQoS_Impl::get_topic_dstOrder_Connections (std::vector <topic_dstOrder_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_dstOrder_Connections
  //
  ::GAME::Mga::Iterator <topic_dstOrder_Connection> DDSQoS_Impl::get_topic_dstOrder_Connections (void) const
  {
    return this->children <topic_dstOrder_Connection> ();
  }

  //
  // get_dw_dstOrder_Connections
  //
  size_t DDSQoS_Impl::get_dw_dstOrder_Connections (std::vector <dw_dstOrder_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_dstOrder_Connections
  //
  ::GAME::Mga::Iterator <dw_dstOrder_Connection> DDSQoS_Impl::get_dw_dstOrder_Connections (void) const
  {
    return this->children <dw_dstOrder_Connection> ();
  }

  //
  // get_dp_userdata_Connections
  //
  size_t DDSQoS_Impl::get_dp_userdata_Connections (std::vector <dp_userdata_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dp_userdata_Connections
  //
  ::GAME::Mga::Iterator <dp_userdata_Connection> DDSQoS_Impl::get_dp_userdata_Connections (void) const
  {
    return this->children <dp_userdata_Connection> ();
  }

  //
  // get_dr_userdata_Connections
  //
  size_t DDSQoS_Impl::get_dr_userdata_Connections (std::vector <dr_userdata_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_userdata_Connections
  //
  ::GAME::Mga::Iterator <dr_userdata_Connection> DDSQoS_Impl::get_dr_userdata_Connections (void) const
  {
    return this->children <dr_userdata_Connection> ();
  }

  //
  // get_dw_userdata_Connections
  //
  size_t DDSQoS_Impl::get_dw_userdata_Connections (std::vector <dw_userdata_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_userdata_Connections
  //
  ::GAME::Mga::Iterator <dw_userdata_Connection> DDSQoS_Impl::get_dw_userdata_Connections (void) const
  {
    return this->children <dw_userdata_Connection> ();
  }

  //
  // get_topic_topicdata_Connections
  //
  size_t DDSQoS_Impl::get_topic_topicdata_Connections (std::vector <topic_topicdata_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_topicdata_Connections
  //
  ::GAME::Mga::Iterator <topic_topicdata_Connection> DDSQoS_Impl::get_topic_topicdata_Connections (void) const
  {
    return this->children <topic_topicdata_Connection> ();
  }

  //
  // get_pub_groupdata_Connections
  //
  size_t DDSQoS_Impl::get_pub_groupdata_Connections (std::vector <pub_groupdata_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_pub_groupdata_Connections
  //
  ::GAME::Mga::Iterator <pub_groupdata_Connection> DDSQoS_Impl::get_pub_groupdata_Connections (void) const
  {
    return this->children <pub_groupdata_Connection> ();
  }

  //
  // get_sub_groupdata_Connections
  //
  size_t DDSQoS_Impl::get_sub_groupdata_Connections (std::vector <sub_groupdata_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_sub_groupdata_Connections
  //
  ::GAME::Mga::Iterator <sub_groupdata_Connection> DDSQoS_Impl::get_sub_groupdata_Connections (void) const
  {
    return this->children <sub_groupdata_Connection> ();
  }

  //
  // get_topic_dursvc_Connections
  //
  size_t DDSQoS_Impl::get_topic_dursvc_Connections (std::vector <topic_dursvc_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_dursvc_Connections
  //
  ::GAME::Mga::Iterator <topic_dursvc_Connection> DDSQoS_Impl::get_topic_dursvc_Connections (void) const
  {
    return this->children <topic_dursvc_Connection> ();
  }

  //
  // get_dw_dursvc_Connections
  //
  size_t DDSQoS_Impl::get_dw_dursvc_Connections (std::vector <dw_dursvc_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_dursvc_Connections
  //
  ::GAME::Mga::Iterator <dw_dursvc_Connection> DDSQoS_Impl::get_dw_dursvc_Connections (void) const
  {
    return this->children <dw_dursvc_Connection> ();
  }

  //
  // get_dw_ownerstrength_Connections
  //
  size_t DDSQoS_Impl::get_dw_ownerstrength_Connections (std::vector <dw_ownerstrength_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_ownerstrength_Connections
  //
  ::GAME::Mga::Iterator <dw_ownerstrength_Connection> DDSQoS_Impl::get_dw_ownerstrength_Connections (void) const
  {
    return this->children <dw_ownerstrength_Connection> ();
  }

  //
  // get_pub_part_Connections
  //
  size_t DDSQoS_Impl::get_pub_part_Connections (std::vector <pub_part_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_pub_part_Connections
  //
  ::GAME::Mga::Iterator <pub_part_Connection> DDSQoS_Impl::get_pub_part_Connections (void) const
  {
    return this->children <pub_part_Connection> ();
  }

  //
  // get_sub_part_Connections
  //
  size_t DDSQoS_Impl::get_sub_part_Connections (std::vector <sub_part_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_sub_part_Connections
  //
  ::GAME::Mga::Iterator <sub_part_Connection> DDSQoS_Impl::get_sub_part_Connections (void) const
  {
    return this->children <sub_part_Connection> ();
  }

  //
  // get_dw_transpri_Connections
  //
  size_t DDSQoS_Impl::get_dw_transpri_Connections (std::vector <dw_transpri_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_transpri_Connections
  //
  ::GAME::Mga::Iterator <dw_transpri_Connection> DDSQoS_Impl::get_dw_transpri_Connections (void) const
  {
    return this->children <dw_transpri_Connection> ();
  }

  //
  // get_topic_transpri_Connections
  //
  size_t DDSQoS_Impl::get_topic_transpri_Connections (std::vector <topic_transpri_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_transpri_Connections
  //
  ::GAME::Mga::Iterator <topic_transpri_Connection> DDSQoS_Impl::get_topic_transpri_Connections (void) const
  {
    return this->children <topic_transpri_Connection> ();
  }

  //
  // get_topic_lifespan_Connections
  //
  size_t DDSQoS_Impl::get_topic_lifespan_Connections (std::vector <topic_lifespan_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_lifespan_Connections
  //
  ::GAME::Mga::Iterator <topic_lifespan_Connection> DDSQoS_Impl::get_topic_lifespan_Connections (void) const
  {
    return this->children <topic_lifespan_Connection> ();
  }

  //
  // get_dw_lifespan_Connections
  //
  size_t DDSQoS_Impl::get_dw_lifespan_Connections (std::vector <dw_lifespan_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_lifespan_Connections
  //
  ::GAME::Mga::Iterator <dw_lifespan_Connection> DDSQoS_Impl::get_dw_lifespan_Connections (void) const
  {
    return this->children <dw_lifespan_Connection> ();
  }

  //
  // get_dr_history_Connections
  //
  size_t DDSQoS_Impl::get_dr_history_Connections (std::vector <dr_history_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_history_Connections
  //
  ::GAME::Mga::Iterator <dr_history_Connection> DDSQoS_Impl::get_dr_history_Connections (void) const
  {
    return this->children <dr_history_Connection> ();
  }

  //
  // get_topic_history_Connections
  //
  size_t DDSQoS_Impl::get_topic_history_Connections (std::vector <topic_history_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_history_Connections
  //
  ::GAME::Mga::Iterator <topic_history_Connection> DDSQoS_Impl::get_topic_history_Connections (void) const
  {
    return this->children <topic_history_Connection> ();
  }

  //
  // get_dw_history_Connections
  //
  size_t DDSQoS_Impl::get_dw_history_Connections (std::vector <dw_history_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_history_Connections
  //
  ::GAME::Mga::Iterator <dw_history_Connection> DDSQoS_Impl::get_dw_history_Connections (void) const
  {
    return this->children <dw_history_Connection> ();
  }

  //
  // get_dr_res_Connections
  //
  size_t DDSQoS_Impl::get_dr_res_Connections (std::vector <dr_res_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_res_Connections
  //
  ::GAME::Mga::Iterator <dr_res_Connection> DDSQoS_Impl::get_dr_res_Connections (void) const
  {
    return this->children <dr_res_Connection> ();
  }

  //
  // get_topic_res_Connections
  //
  size_t DDSQoS_Impl::get_topic_res_Connections (std::vector <topic_res_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_topic_res_Connections
  //
  ::GAME::Mga::Iterator <topic_res_Connection> DDSQoS_Impl::get_topic_res_Connections (void) const
  {
    return this->children <topic_res_Connection> ();
  }

  //
  // get_dw_res_Connections
  //
  size_t DDSQoS_Impl::get_dw_res_Connections (std::vector <dw_res_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_res_Connections
  //
  ::GAME::Mga::Iterator <dw_res_Connection> DDSQoS_Impl::get_dw_res_Connections (void) const
  {
    return this->children <dw_res_Connection> ();
  }

  //
  // get_dpfactory_entityfactory_Connections
  //
  size_t DDSQoS_Impl::get_dpfactory_entityfactory_Connections (std::vector <dpfactory_entityfactory_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dpfactory_entityfactory_Connections
  //
  ::GAME::Mga::Iterator <dpfactory_entityfactory_Connection> DDSQoS_Impl::get_dpfactory_entityfactory_Connections (void) const
  {
    return this->children <dpfactory_entityfactory_Connection> ();
  }

  //
  // get_dp_entityfactory_Connections
  //
  size_t DDSQoS_Impl::get_dp_entityfactory_Connections (std::vector <dp_entityfactory_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dp_entityfactory_Connections
  //
  ::GAME::Mga::Iterator <dp_entityfactory_Connection> DDSQoS_Impl::get_dp_entityfactory_Connections (void) const
  {
    return this->children <dp_entityfactory_Connection> ();
  }

  //
  // get_pub_entityfactory_Connections
  //
  size_t DDSQoS_Impl::get_pub_entityfactory_Connections (std::vector <pub_entityfactory_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_pub_entityfactory_Connections
  //
  ::GAME::Mga::Iterator <pub_entityfactory_Connection> DDSQoS_Impl::get_pub_entityfactory_Connections (void) const
  {
    return this->children <pub_entityfactory_Connection> ();
  }

  //
  // get_sub_entityfactory_Connections
  //
  size_t DDSQoS_Impl::get_sub_entityfactory_Connections (std::vector <sub_entityfactory_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_sub_entityfactory_Connections
  //
  ::GAME::Mga::Iterator <sub_entityfactory_Connection> DDSQoS_Impl::get_sub_entityfactory_Connections (void) const
  {
    return this->children <sub_entityfactory_Connection> ();
  }

  //
  // get_dw_writerdatalifecycle_Connections
  //
  size_t DDSQoS_Impl::get_dw_writerdatalifecycle_Connections (std::vector <dw_writerdatalifecycle_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dw_writerdatalifecycle_Connections
  //
  ::GAME::Mga::Iterator <dw_writerdatalifecycle_Connection> DDSQoS_Impl::get_dw_writerdatalifecycle_Connections (void) const
  {
    return this->children <dw_writerdatalifecycle_Connection> ();
  }

  //
  // get_dr_readerdatalifecycle_Connections
  //
  size_t DDSQoS_Impl::get_dr_readerdatalifecycle_Connections (std::vector <dr_readerdatalifecycle_Connection> & items) const
  {
    return this->children (items);
  }

  //
  // get_dr_readerdatalifecycle_Connections
  //
  ::GAME::Mga::Iterator <dr_readerdatalifecycle_Connection> DDSQoS_Impl::get_dr_readerdatalifecycle_Connections (void) const
  {
    return this->children <dr_readerdatalifecycle_Connection> ();
  }
}

