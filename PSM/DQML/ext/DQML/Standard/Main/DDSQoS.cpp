// $Id$

#include "StdAfx.h"
#include "DDSQoS.h"

#if !defined (__GAME_INLINE__)
#include "DDSQoS.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/OwnershipQosPolicy/dw_ownership_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/dr_reliability_Connection.h"
#include "DQML/Standard/Main/dr_topic_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/topic_transpri_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/topic_reliability_Connection.h"
#include "DQML/Standard/TimeBasedFilterQosPolicy/dr_timebased_Connection.h"
#include "DQML/Standard/ReaderDataLifecycleQosPolicy/dr_readerdatalifecycle_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/topic_dursvc_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/dw_reliability_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/dw_dursvc_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/dr_ownership_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/topic_ownership_Connection.h"
#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TopicDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ResourceLimitsQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/PartitionQosPolicy.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/GroupDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/PresentationQosPolicy.h"
#include "DQML/Standard/QoSPolicies/WriterDataLifecycleQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LifespanQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipStrengthQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DestinationOrderQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LatencyBudgetQosPolicy.h"
#include "DQML/Standard/QoSPolicies/HistoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TransportPriorityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DurabilityServiceQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReliabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TimeBasedFilterQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReaderDataLifecycleQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ShareQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReaderLifespanQosPolicy.h"
#include "DQML/Standard/QoSPolicies/SubscriptionKeyQosPolicy.h"
#include "DQML/Standard/QoSPolicies/SchedulingPriorityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/SchedulingClassQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LivelinessQosPolicy.h"
#include "DQML/Standard/GroupDataQosPolicy/pub_groupdata_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/sub_presqos_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/pub_presqos_Connection.h"
#include "DQML/Standard/PartitionQosPolicy/pub_part_Connection.h"
#include "DQML/Standard/Main/dr_sub_Connection.h"
#include "DQML/Standard/Main/dp_sub_Connection.h"
#include "DQML/Standard/GroupDataQosPolicy/sub_groupdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dr_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dp_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dw_userdata_Connection.h"
#include "DQML/Standard/Main/dpf_dp_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dpfactory_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dp_entityfactory_Connection.h"
#include "DQML/Standard/WriterDataLifecycleQosPolicy/dw_writerdatalifecycle_Connection.h"
#include "DQML/Standard/LifespanQosPolicy/dw_lifespan_Connection.h"
#include "DQML/Standard/Main/dp_pub_Connection.h"
#include "DQML/Standard/Main/dp_topic_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dw_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/topic_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dr_dstOrder_Connection.h"
#include "DQML/Standard/OwnershipStrengthQosPolicy/dw_ownerstrength_Connection.h"
#include "DQML/Standard/LifespanQosPolicy/topic_lifespan_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/dw_transpri_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dr_history_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dw_history_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/topic_history_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/top_latency_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dr_latency_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dw_deadline_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dw_liveliness_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/dw_latency_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dr_liveliness_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dr_deadline_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/top_deadline_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/topic_liveliness_Connection.h"
#include "DQML/Standard/TopicDataQosPolicy/topic_topicdata_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/topic_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dr_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dw_res_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dw_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/topic_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dr_durqos_Connection.h"
#include "DQML/Standard/Main/dw_topic_Connection.h"
#include "DQML/Standard/Main/dw_pub_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/pub_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/sub_entityfactory_Connection.h"
#include "DQML/Standard/PartitionQosPolicy/sub_part_Connection.h"
#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "DQML/Standard/DDSEntities/DomainParticipant.h"
#include "DQML/Standard/DDSEntities/DomainParticipantFactory.h"
#include "DQML/Standard/DDSEntities/Topic.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "DQML/Standard/DDSEntities/Subscriber.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
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
  // is_abstract
  //
  const bool DDSQoS_Impl::is_abstract = false;

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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DDSQoS (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder DDSQoS_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
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
  ::GAME::Mga::Collection_T <dw_ownership_Connection> DDSQoS_Impl::get_dw_ownership_Connections (void) const
  {
    return this->children <dw_ownership_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_reliability_Connection> DDSQoS_Impl::get_dr_reliability_Connections (void) const
  {
    return this->children <dr_reliability_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_topic_Connection> DDSQoS_Impl::get_dr_topic_Connections (void) const
  {
    return this->children <dr_topic_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_transpri_Connection> DDSQoS_Impl::get_topic_transpri_Connections (void) const
  {
    return this->children <topic_transpri_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_reliability_Connection> DDSQoS_Impl::get_topic_reliability_Connections (void) const
  {
    return this->children <topic_reliability_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_timebased_Connection> DDSQoS_Impl::get_dr_timebased_Connections (void) const
  {
    return this->children <dr_timebased_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_readerdatalifecycle_Connection> DDSQoS_Impl::get_dr_readerdatalifecycle_Connections (void) const
  {
    return this->children <dr_readerdatalifecycle_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_dursvc_Connection> DDSQoS_Impl::get_topic_dursvc_Connections (void) const
  {
    return this->children <topic_dursvc_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_reliability_Connection> DDSQoS_Impl::get_dw_reliability_Connections (void) const
  {
    return this->children <dw_reliability_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_dursvc_Connection> DDSQoS_Impl::get_dw_dursvc_Connections (void) const
  {
    return this->children <dw_dursvc_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_ownership_Connection> DDSQoS_Impl::get_dr_ownership_Connections (void) const
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
  ::GAME::Mga::Collection_T <topic_ownership_Connection> DDSQoS_Impl::get_topic_ownership_Connections (void) const
  {
    return this->children <topic_ownership_Connection> ();
  }

  //
  // get_DeadlineQosPolicys
  //
  size_t DDSQoS_Impl::get_DeadlineQosPolicys (std::vector <DeadlineQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_DeadlineQosPolicys
  //
  ::GAME::Mga::Collection_T <DeadlineQosPolicy> DDSQoS_Impl::get_DeadlineQosPolicys (void) const
  {
    return this->children <DeadlineQosPolicy> ();
  }

  //
  // get_TopicDataQosPolicys
  //
  size_t DDSQoS_Impl::get_TopicDataQosPolicys (std::vector <TopicDataQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_TopicDataQosPolicys
  //
  ::GAME::Mga::Collection_T <TopicDataQosPolicy> DDSQoS_Impl::get_TopicDataQosPolicys (void) const
  {
    return this->children <TopicDataQosPolicy> ();
  }

  //
  // get_ResourceLimitsQosPolicys
  //
  size_t DDSQoS_Impl::get_ResourceLimitsQosPolicys (std::vector <ResourceLimitsQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_ResourceLimitsQosPolicys
  //
  ::GAME::Mga::Collection_T <ResourceLimitsQosPolicy> DDSQoS_Impl::get_ResourceLimitsQosPolicys (void) const
  {
    return this->children <ResourceLimitsQosPolicy> ();
  }

  //
  // get_DurabilityQosPolicys
  //
  size_t DDSQoS_Impl::get_DurabilityQosPolicys (std::vector <DurabilityQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_DurabilityQosPolicys
  //
  ::GAME::Mga::Collection_T <DurabilityQosPolicy> DDSQoS_Impl::get_DurabilityQosPolicys (void) const
  {
    return this->children <DurabilityQosPolicy> ();
  }

  //
  // get_EntityFactoryQosPolicys
  //
  size_t DDSQoS_Impl::get_EntityFactoryQosPolicys (std::vector <EntityFactoryQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_EntityFactoryQosPolicys
  //
  ::GAME::Mga::Collection_T <EntityFactoryQosPolicy> DDSQoS_Impl::get_EntityFactoryQosPolicys (void) const
  {
    return this->children <EntityFactoryQosPolicy> ();
  }

  //
  // get_PartitionQosPolicys
  //
  size_t DDSQoS_Impl::get_PartitionQosPolicys (std::vector <PartitionQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_PartitionQosPolicys
  //
  ::GAME::Mga::Collection_T <PartitionQosPolicy> DDSQoS_Impl::get_PartitionQosPolicys (void) const
  {
    return this->children <PartitionQosPolicy> ();
  }

  //
  // get_UserDataQosPolicys
  //
  size_t DDSQoS_Impl::get_UserDataQosPolicys (std::vector <UserDataQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_UserDataQosPolicys
  //
  ::GAME::Mga::Collection_T <UserDataQosPolicy> DDSQoS_Impl::get_UserDataQosPolicys (void) const
  {
    return this->children <UserDataQosPolicy> ();
  }

  //
  // get_GroupDataQosPolicys
  //
  size_t DDSQoS_Impl::get_GroupDataQosPolicys (std::vector <GroupDataQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_GroupDataQosPolicys
  //
  ::GAME::Mga::Collection_T <GroupDataQosPolicy> DDSQoS_Impl::get_GroupDataQosPolicys (void) const
  {
    return this->children <GroupDataQosPolicy> ();
  }

  //
  // get_PresentationQosPolicys
  //
  size_t DDSQoS_Impl::get_PresentationQosPolicys (std::vector <PresentationQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_PresentationQosPolicys
  //
  ::GAME::Mga::Collection_T <PresentationQosPolicy> DDSQoS_Impl::get_PresentationQosPolicys (void) const
  {
    return this->children <PresentationQosPolicy> ();
  }

  //
  // get_WriterDataLifecycleQosPolicys
  //
  size_t DDSQoS_Impl::get_WriterDataLifecycleQosPolicys (std::vector <WriterDataLifecycleQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_WriterDataLifecycleQosPolicys
  //
  ::GAME::Mga::Collection_T <WriterDataLifecycleQosPolicy> DDSQoS_Impl::get_WriterDataLifecycleQosPolicys (void) const
  {
    return this->children <WriterDataLifecycleQosPolicy> ();
  }

  //
  // get_LifespanQosPolicys
  //
  size_t DDSQoS_Impl::get_LifespanQosPolicys (std::vector <LifespanQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_LifespanQosPolicys
  //
  ::GAME::Mga::Collection_T <LifespanQosPolicy> DDSQoS_Impl::get_LifespanQosPolicys (void) const
  {
    return this->children <LifespanQosPolicy> ();
  }

  //
  // get_OwnershipStrengthQosPolicys
  //
  size_t DDSQoS_Impl::get_OwnershipStrengthQosPolicys (std::vector <OwnershipStrengthQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_OwnershipStrengthQosPolicys
  //
  ::GAME::Mga::Collection_T <OwnershipStrengthQosPolicy> DDSQoS_Impl::get_OwnershipStrengthQosPolicys (void) const
  {
    return this->children <OwnershipStrengthQosPolicy> ();
  }

  //
  // get_DestinationOrderQosPolicys
  //
  size_t DDSQoS_Impl::get_DestinationOrderQosPolicys (std::vector <DestinationOrderQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_DestinationOrderQosPolicys
  //
  ::GAME::Mga::Collection_T <DestinationOrderQosPolicy> DDSQoS_Impl::get_DestinationOrderQosPolicys (void) const
  {
    return this->children <DestinationOrderQosPolicy> ();
  }

  //
  // get_LatencyBudgetQosPolicys
  //
  size_t DDSQoS_Impl::get_LatencyBudgetQosPolicys (std::vector <LatencyBudgetQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_LatencyBudgetQosPolicys
  //
  ::GAME::Mga::Collection_T <LatencyBudgetQosPolicy> DDSQoS_Impl::get_LatencyBudgetQosPolicys (void) const
  {
    return this->children <LatencyBudgetQosPolicy> ();
  }

  //
  // get_HistoryQosPolicys
  //
  size_t DDSQoS_Impl::get_HistoryQosPolicys (std::vector <HistoryQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_HistoryQosPolicys
  //
  ::GAME::Mga::Collection_T <HistoryQosPolicy> DDSQoS_Impl::get_HistoryQosPolicys (void) const
  {
    return this->children <HistoryQosPolicy> ();
  }

  //
  // get_TransportPriorityQosPolicys
  //
  size_t DDSQoS_Impl::get_TransportPriorityQosPolicys (std::vector <TransportPriorityQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_TransportPriorityQosPolicys
  //
  ::GAME::Mga::Collection_T <TransportPriorityQosPolicy> DDSQoS_Impl::get_TransportPriorityQosPolicys (void) const
  {
    return this->children <TransportPriorityQosPolicy> ();
  }

  //
  // get_DurabilityServiceQosPolicys
  //
  size_t DDSQoS_Impl::get_DurabilityServiceQosPolicys (std::vector <DurabilityServiceQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_DurabilityServiceQosPolicys
  //
  ::GAME::Mga::Collection_T <DurabilityServiceQosPolicy> DDSQoS_Impl::get_DurabilityServiceQosPolicys (void) const
  {
    return this->children <DurabilityServiceQosPolicy> ();
  }

  //
  // get_ReliabilityQosPolicys
  //
  size_t DDSQoS_Impl::get_ReliabilityQosPolicys (std::vector <ReliabilityQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReliabilityQosPolicys
  //
  ::GAME::Mga::Collection_T <ReliabilityQosPolicy> DDSQoS_Impl::get_ReliabilityQosPolicys (void) const
  {
    return this->children <ReliabilityQosPolicy> ();
  }

  //
  // get_OwnershipQosPolicys
  //
  size_t DDSQoS_Impl::get_OwnershipQosPolicys (std::vector <OwnershipQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_OwnershipQosPolicys
  //
  ::GAME::Mga::Collection_T <OwnershipQosPolicy> DDSQoS_Impl::get_OwnershipQosPolicys (void) const
  {
    return this->children <OwnershipQosPolicy> ();
  }

  //
  // get_TimeBasedFilterQosPolicys
  //
  size_t DDSQoS_Impl::get_TimeBasedFilterQosPolicys (std::vector <TimeBasedFilterQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_TimeBasedFilterQosPolicys
  //
  ::GAME::Mga::Collection_T <TimeBasedFilterQosPolicy> DDSQoS_Impl::get_TimeBasedFilterQosPolicys (void) const
  {
    return this->children <TimeBasedFilterQosPolicy> ();
  }

  //
  // get_ReaderDataLifecycleQosPolicys
  //
  size_t DDSQoS_Impl::get_ReaderDataLifecycleQosPolicys (std::vector <ReaderDataLifecycleQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReaderDataLifecycleQosPolicys
  //
  ::GAME::Mga::Collection_T <ReaderDataLifecycleQosPolicy> DDSQoS_Impl::get_ReaderDataLifecycleQosPolicys (void) const
  {
    return this->children <ReaderDataLifecycleQosPolicy> ();
  }

  //
  // get_ShareQosPolicys
  //
  size_t DDSQoS_Impl::get_ShareQosPolicys (std::vector <ShareQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_ShareQosPolicys
  //
  ::GAME::Mga::Collection_T <ShareQosPolicy> DDSQoS_Impl::get_ShareQosPolicys (void) const
  {
    return this->children <ShareQosPolicy> ();
  }

  //
  // get_ReaderLifespanQosPolicys
  //
  size_t DDSQoS_Impl::get_ReaderLifespanQosPolicys (std::vector <ReaderLifespanQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReaderLifespanQosPolicys
  //
  ::GAME::Mga::Collection_T <ReaderLifespanQosPolicy> DDSQoS_Impl::get_ReaderLifespanQosPolicys (void) const
  {
    return this->children <ReaderLifespanQosPolicy> ();
  }

  //
  // get_SubscriptionKeyQosPolicys
  //
  size_t DDSQoS_Impl::get_SubscriptionKeyQosPolicys (std::vector <SubscriptionKeyQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_SubscriptionKeyQosPolicys
  //
  ::GAME::Mga::Collection_T <SubscriptionKeyQosPolicy> DDSQoS_Impl::get_SubscriptionKeyQosPolicys (void) const
  {
    return this->children <SubscriptionKeyQosPolicy> ();
  }

  //
  // get_SchedulingPriorityQosPolicys
  //
  size_t DDSQoS_Impl::get_SchedulingPriorityQosPolicys (std::vector <SchedulingPriorityQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_SchedulingPriorityQosPolicys
  //
  ::GAME::Mga::Collection_T <SchedulingPriorityQosPolicy> DDSQoS_Impl::get_SchedulingPriorityQosPolicys (void) const
  {
    return this->children <SchedulingPriorityQosPolicy> ();
  }

  //
  // get_SchedulingClassQosPolicys
  //
  size_t DDSQoS_Impl::get_SchedulingClassQosPolicys (std::vector <SchedulingClassQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_SchedulingClassQosPolicys
  //
  ::GAME::Mga::Collection_T <SchedulingClassQosPolicy> DDSQoS_Impl::get_SchedulingClassQosPolicys (void) const
  {
    return this->children <SchedulingClassQosPolicy> ();
  }

  //
  // get_LivelinessQosPolicys
  //
  size_t DDSQoS_Impl::get_LivelinessQosPolicys (std::vector <LivelinessQosPolicy> & items) const
  {
    return this->children (items);
  }

  //
  // get_LivelinessQosPolicys
  //
  ::GAME::Mga::Collection_T <LivelinessQosPolicy> DDSQoS_Impl::get_LivelinessQosPolicys (void) const
  {
    return this->children <LivelinessQosPolicy> ();
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
  ::GAME::Mga::Collection_T <pub_groupdata_Connection> DDSQoS_Impl::get_pub_groupdata_Connections (void) const
  {
    return this->children <pub_groupdata_Connection> ();
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
  ::GAME::Mga::Collection_T <sub_presqos_Connection> DDSQoS_Impl::get_sub_presqos_Connections (void) const
  {
    return this->children <sub_presqos_Connection> ();
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
  ::GAME::Mga::Collection_T <pub_presqos_Connection> DDSQoS_Impl::get_pub_presqos_Connections (void) const
  {
    return this->children <pub_presqos_Connection> ();
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
  ::GAME::Mga::Collection_T <pub_part_Connection> DDSQoS_Impl::get_pub_part_Connections (void) const
  {
    return this->children <pub_part_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_sub_Connection> DDSQoS_Impl::get_dr_sub_Connections (void) const
  {
    return this->children <dr_sub_Connection> ();
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
  ::GAME::Mga::Collection_T <dp_sub_Connection> DDSQoS_Impl::get_dp_sub_Connections (void) const
  {
    return this->children <dp_sub_Connection> ();
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
  ::GAME::Mga::Collection_T <sub_groupdata_Connection> DDSQoS_Impl::get_sub_groupdata_Connections (void) const
  {
    return this->children <sub_groupdata_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_userdata_Connection> DDSQoS_Impl::get_dr_userdata_Connections (void) const
  {
    return this->children <dr_userdata_Connection> ();
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
  ::GAME::Mga::Collection_T <dp_userdata_Connection> DDSQoS_Impl::get_dp_userdata_Connections (void) const
  {
    return this->children <dp_userdata_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_userdata_Connection> DDSQoS_Impl::get_dw_userdata_Connections (void) const
  {
    return this->children <dw_userdata_Connection> ();
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
  ::GAME::Mga::Collection_T <dpf_dp_Connection> DDSQoS_Impl::get_dpf_dp_Connections (void) const
  {
    return this->children <dpf_dp_Connection> ();
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
  ::GAME::Mga::Collection_T <dpfactory_entityfactory_Connection> DDSQoS_Impl::get_dpfactory_entityfactory_Connections (void) const
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
  ::GAME::Mga::Collection_T <dp_entityfactory_Connection> DDSQoS_Impl::get_dp_entityfactory_Connections (void) const
  {
    return this->children <dp_entityfactory_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_writerdatalifecycle_Connection> DDSQoS_Impl::get_dw_writerdatalifecycle_Connections (void) const
  {
    return this->children <dw_writerdatalifecycle_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_lifespan_Connection> DDSQoS_Impl::get_dw_lifespan_Connections (void) const
  {
    return this->children <dw_lifespan_Connection> ();
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
  ::GAME::Mga::Collection_T <dp_pub_Connection> DDSQoS_Impl::get_dp_pub_Connections (void) const
  {
    return this->children <dp_pub_Connection> ();
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
  ::GAME::Mga::Collection_T <dp_topic_Connection> DDSQoS_Impl::get_dp_topic_Connections (void) const
  {
    return this->children <dp_topic_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_dstOrder_Connection> DDSQoS_Impl::get_dw_dstOrder_Connections (void) const
  {
    return this->children <dw_dstOrder_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_dstOrder_Connection> DDSQoS_Impl::get_topic_dstOrder_Connections (void) const
  {
    return this->children <topic_dstOrder_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_dstOrder_Connection> DDSQoS_Impl::get_dr_dstOrder_Connections (void) const
  {
    return this->children <dr_dstOrder_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_ownerstrength_Connection> DDSQoS_Impl::get_dw_ownerstrength_Connections (void) const
  {
    return this->children <dw_ownerstrength_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_lifespan_Connection> DDSQoS_Impl::get_topic_lifespan_Connections (void) const
  {
    return this->children <topic_lifespan_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_transpri_Connection> DDSQoS_Impl::get_dw_transpri_Connections (void) const
  {
    return this->children <dw_transpri_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_history_Connection> DDSQoS_Impl::get_dr_history_Connections (void) const
  {
    return this->children <dr_history_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_history_Connection> DDSQoS_Impl::get_dw_history_Connections (void) const
  {
    return this->children <dw_history_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_history_Connection> DDSQoS_Impl::get_topic_history_Connections (void) const
  {
    return this->children <topic_history_Connection> ();
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
  ::GAME::Mga::Collection_T <top_latency_Connection> DDSQoS_Impl::get_top_latency_Connections (void) const
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
  ::GAME::Mga::Collection_T <dr_latency_Connection> DDSQoS_Impl::get_dr_latency_Connections (void) const
  {
    return this->children <dr_latency_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_deadline_Connection> DDSQoS_Impl::get_dw_deadline_Connections (void) const
  {
    return this->children <dw_deadline_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_liveliness_Connection> DDSQoS_Impl::get_dw_liveliness_Connections (void) const
  {
    return this->children <dw_liveliness_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_latency_Connection> DDSQoS_Impl::get_dw_latency_Connections (void) const
  {
    return this->children <dw_latency_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_liveliness_Connection> DDSQoS_Impl::get_dr_liveliness_Connections (void) const
  {
    return this->children <dr_liveliness_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_deadline_Connection> DDSQoS_Impl::get_dr_deadline_Connections (void) const
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
  ::GAME::Mga::Collection_T <top_deadline_Connection> DDSQoS_Impl::get_top_deadline_Connections (void) const
  {
    return this->children <top_deadline_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_liveliness_Connection> DDSQoS_Impl::get_topic_liveliness_Connections (void) const
  {
    return this->children <topic_liveliness_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_topicdata_Connection> DDSQoS_Impl::get_topic_topicdata_Connections (void) const
  {
    return this->children <topic_topicdata_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_res_Connection> DDSQoS_Impl::get_topic_res_Connections (void) const
  {
    return this->children <topic_res_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_res_Connection> DDSQoS_Impl::get_dr_res_Connections (void) const
  {
    return this->children <dr_res_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_res_Connection> DDSQoS_Impl::get_dw_res_Connections (void) const
  {
    return this->children <dw_res_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_durqos_Connection> DDSQoS_Impl::get_dw_durqos_Connections (void) const
  {
    return this->children <dw_durqos_Connection> ();
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
  ::GAME::Mga::Collection_T <topic_durqos_Connection> DDSQoS_Impl::get_topic_durqos_Connections (void) const
  {
    return this->children <topic_durqos_Connection> ();
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
  ::GAME::Mga::Collection_T <dr_durqos_Connection> DDSQoS_Impl::get_dr_durqos_Connections (void) const
  {
    return this->children <dr_durqos_Connection> ();
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
  ::GAME::Mga::Collection_T <dw_topic_Connection> DDSQoS_Impl::get_dw_topic_Connections (void) const
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
  ::GAME::Mga::Collection_T <dw_pub_Connection> DDSQoS_Impl::get_dw_pub_Connections (void) const
  {
    return this->children <dw_pub_Connection> ();
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
  ::GAME::Mga::Collection_T <pub_entityfactory_Connection> DDSQoS_Impl::get_pub_entityfactory_Connections (void) const
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
  ::GAME::Mga::Collection_T <sub_entityfactory_Connection> DDSQoS_Impl::get_sub_entityfactory_Connections (void) const
  {
    return this->children <sub_entityfactory_Connection> ();
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
  ::GAME::Mga::Collection_T <sub_part_Connection> DDSQoS_Impl::get_sub_part_Connections (void) const
  {
    return this->children <sub_part_Connection> ();
  }

  //
  // get_DomainParticipants
  //
  size_t DDSQoS_Impl::get_DomainParticipants (std::vector <DomainParticipant> & items) const
  {
    return this->children (items);
  }

  //
  // get_DomainParticipants
  //
  ::GAME::Mga::Collection_T <DomainParticipant> DDSQoS_Impl::get_DomainParticipants (void) const
  {
    return this->children <DomainParticipant> ();
  }

  //
  // get_DomainParticipantFactorys
  //
  size_t DDSQoS_Impl::get_DomainParticipantFactorys (std::vector <DomainParticipantFactory> & items) const
  {
    return this->children (items);
  }

  //
  // get_DomainParticipantFactorys
  //
  ::GAME::Mga::Collection_T <DomainParticipantFactory> DDSQoS_Impl::get_DomainParticipantFactorys (void) const
  {
    return this->children <DomainParticipantFactory> ();
  }

  //
  // get_Topics
  //
  size_t DDSQoS_Impl::get_Topics (std::vector <Topic> & items) const
  {
    return this->children (items);
  }

  //
  // get_Topics
  //
  ::GAME::Mga::Collection_T <Topic> DDSQoS_Impl::get_Topics (void) const
  {
    return this->children <Topic> ();
  }

  //
  // get_DataReaders
  //
  size_t DDSQoS_Impl::get_DataReaders (std::vector <DataReader> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataReaders
  //
  ::GAME::Mga::Collection_T <DataReader> DDSQoS_Impl::get_DataReaders (void) const
  {
    return this->children <DataReader> ();
  }

  //
  // get_Subscribers
  //
  size_t DDSQoS_Impl::get_Subscribers (std::vector <Subscriber> & items) const
  {
    return this->children (items);
  }

  //
  // get_Subscribers
  //
  ::GAME::Mga::Collection_T <Subscriber> DDSQoS_Impl::get_Subscribers (void) const
  {
    return this->children <Subscriber> ();
  }

  //
  // get_DataWriters
  //
  size_t DDSQoS_Impl::get_DataWriters (std::vector <DataWriter> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataWriters
  //
  ::GAME::Mga::Collection_T <DataWriter> DDSQoS_Impl::get_DataWriters (void) const
  {
    return this->children <DataWriter> ();
  }

  //
  // get_Publishers
  //
  size_t DDSQoS_Impl::get_Publishers (std::vector <Publisher> & items) const
  {
    return this->children (items);
  }

  //
  // get_Publishers
  //
  ::GAME::Mga::Collection_T <Publisher> DDSQoS_Impl::get_Publishers (void) const
  {
    return this->children <Publisher> ();
  }
}

