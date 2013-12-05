// $Id$

#include "stdafx.h"
#include "Impl_Factory.h"

#include "game/mga/Functional_T.h"
#include "game/mga/Exception.h"

#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/Main/dr_topic_Connection.h"
#include "DQML/Standard/Main/dw_topic_Connection.h"
#include "DQML/Standard/Main/dw_pub_Connection.h"
#include "DQML/Standard/Main/dr_sub_Connection.h"
#include "DQML/Standard/Main/dp_topic_Connection.h"
#include "DQML/Standard/Main/dp_pub_Connection.h"
#include "DQML/Standard/Main/dp_sub_Connection.h"
#include "DQML/Standard/Main/dpf_dp_Connection.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/DDSEntities/Topic.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "DQML/Standard/DDSEntities/Subscriber.h"
#include "DQML/Standard/DDSEntities/DomainParticipant.h"
#include "DQML/Standard/DDSEntities/DomainParticipantFactory.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/PresentationQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TimeBasedFilterQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LatencyBudgetQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LivelinessQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReliabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DestinationOrderQosPolicy.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TopicDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/GroupDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DurabilityServiceQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipStrengthQosPolicy.h"
#include "DQML/Standard/QoSPolicies/PartitionQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TransportPriorityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LifespanQosPolicy.h"
#include "DQML/Standard/QoSPolicies/HistoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ResourceLimitsQosPolicy.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/WriterDataLifecycleQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReaderDataLifecycleQosPolicy.h"
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
#include "DQML/iCCM/DomainQos/DomainQosFolder.h"
#include "DQML/iCCM/DomainQos/Domain.h"
#include "DQML/iCCM/PublisherSubscriberQos/PublisherQos.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/TopicQos/TopicQosReference.h"
#include "DQML/iCCM/DomainQos/SubscriberConnection.h"
#include "DQML/iCCM/DomainQos/PublishesConnection.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "DQML/iCCM/iCCM/iCCM.h"
#include "DQML/iCCM/TopicQos/TopicQosFolder.h"
#include "DQML/iCCM/DomainQos/PublisherConnection.h"

namespace DQML
{
  //
  // Impl_Factory
  //
  Impl_Factory::Impl_Factory (void)
  {
    this->map_.bind ("DDSQoS", &::GAME::Mga::allocate_impl <DDSQoS_Impl>);
    this->map_.bind ("dr_topic_Connection", &::GAME::Mga::allocate_impl <dr_topic_Connection_Impl>);
    this->map_.bind ("dw_topic_Connection", &::GAME::Mga::allocate_impl <dw_topic_Connection_Impl>);
    this->map_.bind ("dw_pub_Connection", &::GAME::Mga::allocate_impl <dw_pub_Connection_Impl>);
    this->map_.bind ("dr_sub_Connection", &::GAME::Mga::allocate_impl <dr_sub_Connection_Impl>);
    this->map_.bind ("dp_topic_Connection", &::GAME::Mga::allocate_impl <dp_topic_Connection_Impl>);
    this->map_.bind ("dp_pub_Connection", &::GAME::Mga::allocate_impl <dp_pub_Connection_Impl>);
    this->map_.bind ("dp_sub_Connection", &::GAME::Mga::allocate_impl <dp_sub_Connection_Impl>);
    this->map_.bind ("dpf_dp_Connection", &::GAME::Mga::allocate_impl <dpf_dp_Connection_Impl>);
    this->map_.bind ("Publisher", &::GAME::Mga::allocate_impl <Publisher_Impl>);
    this->map_.bind ("DataWriter", &::GAME::Mga::allocate_impl <DataWriter_Impl>);
    this->map_.bind ("Topic", &::GAME::Mga::allocate_impl <Topic_Impl>);
    this->map_.bind ("DataReader", &::GAME::Mga::allocate_impl <DataReader_Impl>);
    this->map_.bind ("Subscriber", &::GAME::Mga::allocate_impl <Subscriber_Impl>);
    this->map_.bind ("DomainParticipant", &::GAME::Mga::allocate_impl <DomainParticipant_Impl>);
    this->map_.bind ("DomainParticipantFactory", &::GAME::Mga::allocate_impl <DomainParticipantFactory_Impl>);
    this->map_.bind ("DurabilityQosPolicy", &::GAME::Mga::allocate_impl <DurabilityQosPolicy_Impl>);
    this->map_.bind ("PresentationQosPolicy", &::GAME::Mga::allocate_impl <PresentationQosPolicy_Impl>);
    this->map_.bind ("DeadlineQosPolicy", &::GAME::Mga::allocate_impl <DeadlineQosPolicy_Impl>);
    this->map_.bind ("TimeBasedFilterQosPolicy", &::GAME::Mga::allocate_impl <TimeBasedFilterQosPolicy_Impl>);
    this->map_.bind ("LatencyBudgetQosPolicy", &::GAME::Mga::allocate_impl <LatencyBudgetQosPolicy_Impl>);
    this->map_.bind ("OwnershipQosPolicy", &::GAME::Mga::allocate_impl <OwnershipQosPolicy_Impl>);
    this->map_.bind ("LivelinessQosPolicy", &::GAME::Mga::allocate_impl <LivelinessQosPolicy_Impl>);
    this->map_.bind ("ReliabilityQosPolicy", &::GAME::Mga::allocate_impl <ReliabilityQosPolicy_Impl>);
    this->map_.bind ("DestinationOrderQosPolicy", &::GAME::Mga::allocate_impl <DestinationOrderQosPolicy_Impl>);
    this->map_.bind ("UserDataQosPolicy", &::GAME::Mga::allocate_impl <UserDataQosPolicy_Impl>);
    this->map_.bind ("TopicDataQosPolicy", &::GAME::Mga::allocate_impl <TopicDataQosPolicy_Impl>);
    this->map_.bind ("GroupDataQosPolicy", &::GAME::Mga::allocate_impl <GroupDataQosPolicy_Impl>);
    this->map_.bind ("DurabilityServiceQosPolicy", &::GAME::Mga::allocate_impl <DurabilityServiceQosPolicy_Impl>);
    this->map_.bind ("OwnershipStrengthQosPolicy", &::GAME::Mga::allocate_impl <OwnershipStrengthQosPolicy_Impl>);
    this->map_.bind ("PartitionQosPolicy", &::GAME::Mga::allocate_impl <PartitionQosPolicy_Impl>);
    this->map_.bind ("TransportPriorityQosPolicy", &::GAME::Mga::allocate_impl <TransportPriorityQosPolicy_Impl>);
    this->map_.bind ("LifespanQosPolicy", &::GAME::Mga::allocate_impl <LifespanQosPolicy_Impl>);
    this->map_.bind ("HistoryQosPolicy", &::GAME::Mga::allocate_impl <HistoryQosPolicy_Impl>);
    this->map_.bind ("ResourceLimitsQosPolicy", &::GAME::Mga::allocate_impl <ResourceLimitsQosPolicy_Impl>);
    this->map_.bind ("EntityFactoryQosPolicy", &::GAME::Mga::allocate_impl <EntityFactoryQosPolicy_Impl>);
    this->map_.bind ("WriterDataLifecycleQosPolicy", &::GAME::Mga::allocate_impl <WriterDataLifecycleQosPolicy_Impl>);
    this->map_.bind ("ReaderDataLifecycleQosPolicy", &::GAME::Mga::allocate_impl <ReaderDataLifecycleQosPolicy_Impl>);
    this->map_.bind ("dr_durqos_Connection", &::GAME::Mga::allocate_impl <dr_durqos_Connection_Impl>);
    this->map_.bind ("topic_durqos_Connection", &::GAME::Mga::allocate_impl <topic_durqos_Connection_Impl>);
    this->map_.bind ("dw_durqos_Connection", &::GAME::Mga::allocate_impl <dw_durqos_Connection_Impl>);
    this->map_.bind ("pub_presqos_Connection", &::GAME::Mga::allocate_impl <pub_presqos_Connection_Impl>);
    this->map_.bind ("sub_presqos_Connection", &::GAME::Mga::allocate_impl <sub_presqos_Connection_Impl>);
    this->map_.bind ("dr_deadline_Connection", &::GAME::Mga::allocate_impl <dr_deadline_Connection_Impl>);
    this->map_.bind ("top_deadline_Connection", &::GAME::Mga::allocate_impl <top_deadline_Connection_Impl>);
    this->map_.bind ("dw_deadline_Connection", &::GAME::Mga::allocate_impl <dw_deadline_Connection_Impl>);
    this->map_.bind ("dr_timebased_Connection", &::GAME::Mga::allocate_impl <dr_timebased_Connection_Impl>);
    this->map_.bind ("top_latency_Connection", &::GAME::Mga::allocate_impl <top_latency_Connection_Impl>);
    this->map_.bind ("dr_latency_Connection", &::GAME::Mga::allocate_impl <dr_latency_Connection_Impl>);
    this->map_.bind ("dw_latency_Connection", &::GAME::Mga::allocate_impl <dw_latency_Connection_Impl>);
    this->map_.bind ("dr_ownership_Connection", &::GAME::Mga::allocate_impl <dr_ownership_Connection_Impl>);
    this->map_.bind ("topic_ownership_Connection", &::GAME::Mga::allocate_impl <topic_ownership_Connection_Impl>);
    this->map_.bind ("dw_ownership_Connection", &::GAME::Mga::allocate_impl <dw_ownership_Connection_Impl>);
    this->map_.bind ("dr_liveliness_Connection", &::GAME::Mga::allocate_impl <dr_liveliness_Connection_Impl>);
    this->map_.bind ("topic_liveliness_Connection", &::GAME::Mga::allocate_impl <topic_liveliness_Connection_Impl>);
    this->map_.bind ("dw_liveliness_Connection", &::GAME::Mga::allocate_impl <dw_liveliness_Connection_Impl>);
    this->map_.bind ("dr_reliability_Connection", &::GAME::Mga::allocate_impl <dr_reliability_Connection_Impl>);
    this->map_.bind ("topic_reliability_Connection", &::GAME::Mga::allocate_impl <topic_reliability_Connection_Impl>);
    this->map_.bind ("dw_reliability_Connection", &::GAME::Mga::allocate_impl <dw_reliability_Connection_Impl>);
    this->map_.bind ("dr_dstOrder_Connection", &::GAME::Mga::allocate_impl <dr_dstOrder_Connection_Impl>);
    this->map_.bind ("topic_dstOrder_Connection", &::GAME::Mga::allocate_impl <topic_dstOrder_Connection_Impl>);
    this->map_.bind ("dw_dstOrder_Connection", &::GAME::Mga::allocate_impl <dw_dstOrder_Connection_Impl>);
    this->map_.bind ("dp_userdata_Connection", &::GAME::Mga::allocate_impl <dp_userdata_Connection_Impl>);
    this->map_.bind ("dr_userdata_Connection", &::GAME::Mga::allocate_impl <dr_userdata_Connection_Impl>);
    this->map_.bind ("dw_userdata_Connection", &::GAME::Mga::allocate_impl <dw_userdata_Connection_Impl>);
    this->map_.bind ("topic_topicdata_Connection", &::GAME::Mga::allocate_impl <topic_topicdata_Connection_Impl>);
    this->map_.bind ("pub_groupdata_Connection", &::GAME::Mga::allocate_impl <pub_groupdata_Connection_Impl>);
    this->map_.bind ("sub_groupdata_Connection", &::GAME::Mga::allocate_impl <sub_groupdata_Connection_Impl>);
    this->map_.bind ("topic_dursvc_Connection", &::GAME::Mga::allocate_impl <topic_dursvc_Connection_Impl>);
    this->map_.bind ("dw_dursvc_Connection", &::GAME::Mga::allocate_impl <dw_dursvc_Connection_Impl>);
    this->map_.bind ("dw_ownerstrength_Connection", &::GAME::Mga::allocate_impl <dw_ownerstrength_Connection_Impl>);
    this->map_.bind ("pub_part_Connection", &::GAME::Mga::allocate_impl <pub_part_Connection_Impl>);
    this->map_.bind ("sub_part_Connection", &::GAME::Mga::allocate_impl <sub_part_Connection_Impl>);
    this->map_.bind ("dw_transpri_Connection", &::GAME::Mga::allocate_impl <dw_transpri_Connection_Impl>);
    this->map_.bind ("topic_transpri_Connection", &::GAME::Mga::allocate_impl <topic_transpri_Connection_Impl>);
    this->map_.bind ("topic_lifespan_Connection", &::GAME::Mga::allocate_impl <topic_lifespan_Connection_Impl>);
    this->map_.bind ("dw_lifespan_Connection", &::GAME::Mga::allocate_impl <dw_lifespan_Connection_Impl>);
    this->map_.bind ("dr_history_Connection", &::GAME::Mga::allocate_impl <dr_history_Connection_Impl>);
    this->map_.bind ("topic_history_Connection", &::GAME::Mga::allocate_impl <topic_history_Connection_Impl>);
    this->map_.bind ("dw_history_Connection", &::GAME::Mga::allocate_impl <dw_history_Connection_Impl>);
    this->map_.bind ("dr_res_Connection", &::GAME::Mga::allocate_impl <dr_res_Connection_Impl>);
    this->map_.bind ("topic_res_Connection", &::GAME::Mga::allocate_impl <topic_res_Connection_Impl>);
    this->map_.bind ("dw_res_Connection", &::GAME::Mga::allocate_impl <dw_res_Connection_Impl>);
    this->map_.bind ("dpfactory_entityfactory_Connection", &::GAME::Mga::allocate_impl <dpfactory_entityfactory_Connection_Impl>);
    this->map_.bind ("dp_entityfactory_Connection", &::GAME::Mga::allocate_impl <dp_entityfactory_Connection_Impl>);
    this->map_.bind ("pub_entityfactory_Connection", &::GAME::Mga::allocate_impl <pub_entityfactory_Connection_Impl>);
    this->map_.bind ("sub_entityfactory_Connection", &::GAME::Mga::allocate_impl <sub_entityfactory_Connection_Impl>);
    this->map_.bind ("dw_writerdatalifecycle_Connection", &::GAME::Mga::allocate_impl <dw_writerdatalifecycle_Connection_Impl>);
    this->map_.bind ("dr_readerdatalifecycle_Connection", &::GAME::Mga::allocate_impl <dr_readerdatalifecycle_Connection_Impl>);
    this->map_.bind ("DomainQosFolder", &::GAME::Mga::allocate_impl <DomainQosFolder_Impl>);
    this->map_.bind ("Domain", &::GAME::Mga::allocate_impl <Domain_Impl>);
    this->map_.bind ("PublisherQos", &::GAME::Mga::allocate_impl <PublisherQos_Impl>);
    this->map_.bind ("SubscriberQos", &::GAME::Mga::allocate_impl <SubscriberQos_Impl>);
    this->map_.bind ("TopicQos", &::GAME::Mga::allocate_impl <TopicQos_Impl>);
    this->map_.bind ("DataWriterQos", &::GAME::Mga::allocate_impl <DataWriterQos_Impl>);
    this->map_.bind ("DataReaderQos", &::GAME::Mga::allocate_impl <DataReaderQos_Impl>);
    this->map_.bind ("TopicQosReference", &::GAME::Mga::allocate_impl <TopicQosReference_Impl>);
    this->map_.bind ("SubscriberConnection", &::GAME::Mga::allocate_impl <SubscriberConnection_Impl>);
    this->map_.bind ("PublishesConnection", &::GAME::Mga::allocate_impl <PublishesConnection_Impl>);
    this->map_.bind ("Participant", &::GAME::Mga::allocate_impl <Participant_Impl>);
    this->map_.bind ("iCCM", &::GAME::Mga::allocate_impl <iCCM_Impl>);
    this->map_.bind ("TopicQosFolder", &::GAME::Mga::allocate_impl <TopicQosFolder_Impl>);
    this->map_.bind ("PublisherConnection", &::GAME::Mga::allocate_impl <PublisherConnection_Impl>);
  }

  //
  // ~Impl_Factory
  //
  Impl_Factory::~Impl_Factory (void)
  {
  }

  //
  // allocate
  //
  ::GAME::Mga::Object_Impl * Impl_Factory::allocate (IMgaObject * ptr)
  {
    CComPtr <IMgaMetaBase> metabase;
    VERIFY_HRESULT (ptr->get_MetaBase (&metabase));

    CComBSTR bstr;
    VERIFY_HRESULT (metabase->get_Name (&bstr));

    CW2A metaname (bstr);
    FACTORY_METHOD factory_method = 0;
    if (0 != this->map_.find (metaname.m_psz, factory_method))  return 0;

    return factory_method (ptr);
  }
}

