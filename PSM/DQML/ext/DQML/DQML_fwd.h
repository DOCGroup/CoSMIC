// -*- C++ -*-
// $Id$

#ifndef _DQML_FWD_H_
#define _DQML_FWD_H_

#include "game/mga/Smart_Ptr.h"

namespace DQML
{
  // Forward declarations for RootFolder
  class RootFolder_Impl;
  typedef RootFolder_Impl * RootFolder_in;
  typedef ::GAME::Mga::Smart_Ptr <RootFolder_Impl> RootFolder;

  // Forward declarations for dp_userdata_Connection
  class dp_userdata_Connection_Impl;
  typedef dp_userdata_Connection_Impl * dp_userdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dp_userdata_Connection_Impl> dp_userdata_Connection;

  // Forward declarations for LifespanQosPolicy
  class LifespanQosPolicy_Impl;
  typedef LifespanQosPolicy_Impl * LifespanQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <LifespanQosPolicy_Impl> LifespanQosPolicy;

  // Forward declarations for QoSPolicy
  class QoSPolicy_Impl;
  typedef QoSPolicy_Impl * QoSPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <QoSPolicy_Impl> QoSPolicy;

  // Forward declarations for topic_transpri_Connection
  class topic_transpri_Connection_Impl;
  typedef topic_transpri_Connection_Impl * topic_transpri_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_transpri_Connection_Impl> topic_transpri_Connection;

  // Forward declarations for DomainParticipantFactory
  class DomainParticipantFactory_Impl;
  typedef DomainParticipantFactory_Impl * DomainParticipantFactory_in;
  typedef ::GAME::Mga::Smart_Ptr <DomainParticipantFactory_Impl> DomainParticipantFactory;

  // Forward declarations for sub_presqos_Connection
  class sub_presqos_Connection_Impl;
  typedef sub_presqos_Connection_Impl * sub_presqos_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <sub_presqos_Connection_Impl> sub_presqos_Connection;

  // Forward declarations for pub_presqos_Connection
  class pub_presqos_Connection_Impl;
  typedef pub_presqos_Connection_Impl * pub_presqos_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <pub_presqos_Connection_Impl> pub_presqos_Connection;

  // Forward declarations for dw_transpri_Connection
  class dw_transpri_Connection_Impl;
  typedef dw_transpri_Connection_Impl * dw_transpri_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_transpri_Connection_Impl> dw_transpri_Connection;

  // Forward declarations for DataWriterQos
  class DataWriterQos_Impl;
  typedef DataWriterQos_Impl * DataWriterQos_in;
  typedef ::GAME::Mga::Smart_Ptr <DataWriterQos_Impl> DataWriterQos;

  // Forward declarations for PartitionQosPolicy
  class PartitionQosPolicy_Impl;
  typedef PartitionQosPolicy_Impl * PartitionQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <PartitionQosPolicy_Impl> PartitionQosPolicy;

  // Forward declarations for dpfactory_entityfactory_Connection
  class dpfactory_entityfactory_Connection_Impl;
  typedef dpfactory_entityfactory_Connection_Impl * dpfactory_entityfactory_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dpfactory_entityfactory_Connection_Impl> dpfactory_entityfactory_Connection;

  // Forward declarations for ResourceLimitsQosPolicy
  class ResourceLimitsQosPolicy_Impl;
  typedef ResourceLimitsQosPolicy_Impl * ResourceLimitsQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <ResourceLimitsQosPolicy_Impl> ResourceLimitsQosPolicy;

  // Forward declarations for topic_durqos_Connection
  class topic_durqos_Connection_Impl;
  typedef topic_durqos_Connection_Impl * topic_durqos_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_durqos_Connection_Impl> topic_durqos_Connection;

  // Forward declarations for DomainQosFolder
  class DomainQosFolder_Impl;
  typedef DomainQosFolder_Impl * DomainQosFolder_in;
  typedef ::GAME::Mga::Smart_Ptr <DomainQosFolder_Impl> DomainQosFolder;

  // Forward declarations for OwnershipStrengthQosPolicy
  class OwnershipStrengthQosPolicy_Impl;
  typedef OwnershipStrengthQosPolicy_Impl * OwnershipStrengthQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <OwnershipStrengthQosPolicy_Impl> OwnershipStrengthQosPolicy;

  // Forward declarations for dw_userdata_Connection
  class dw_userdata_Connection_Impl;
  typedef dw_userdata_Connection_Impl * dw_userdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_userdata_Connection_Impl> dw_userdata_Connection;

  // Forward declarations for LivelinessQosPolicy
  class LivelinessQosPolicy_Impl;
  typedef LivelinessQosPolicy_Impl * LivelinessQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <LivelinessQosPolicy_Impl> LivelinessQosPolicy;

  // Forward declarations for TransportPriorityQosPolicy
  class TransportPriorityQosPolicy_Impl;
  typedef TransportPriorityQosPolicy_Impl * TransportPriorityQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <TransportPriorityQosPolicy_Impl> TransportPriorityQosPolicy;

  // Forward declarations for SubscriptionKeyQosPolicy
  class SubscriptionKeyQosPolicy_Impl;
  typedef SubscriptionKeyQosPolicy_Impl * SubscriptionKeyQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <SubscriptionKeyQosPolicy_Impl> SubscriptionKeyQosPolicy;

  // Forward declarations for OwnershipQosPolicy
  class OwnershipQosPolicy_Impl;
  typedef OwnershipQosPolicy_Impl * OwnershipQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <OwnershipQosPolicy_Impl> OwnershipQosPolicy;

  // Forward declarations for dr_sub_Connection
  class dr_sub_Connection_Impl;
  typedef dr_sub_Connection_Impl * dr_sub_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_sub_Connection_Impl> dr_sub_Connection;

  // Forward declarations for dr_deadline_Connection
  class dr_deadline_Connection_Impl;
  typedef dr_deadline_Connection_Impl * dr_deadline_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_deadline_Connection_Impl> dr_deadline_Connection;

  // Forward declarations for top_latency_Connection
  class top_latency_Connection_Impl;
  typedef top_latency_Connection_Impl * top_latency_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <top_latency_Connection_Impl> top_latency_Connection;

  // Forward declarations for dp_sub_Connection
  class dp_sub_Connection_Impl;
  typedef dp_sub_Connection_Impl * dp_sub_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dp_sub_Connection_Impl> dp_sub_Connection;

  // Forward declarations for iCCM
  class iCCM_Impl;
  typedef iCCM_Impl * iCCM_in;
  typedef ::GAME::Mga::Smart_Ptr <iCCM_Impl> iCCM;

  // Forward declarations for GroupDataQosPolicy
  class GroupDataQosPolicy_Impl;
  typedef GroupDataQosPolicy_Impl * GroupDataQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <GroupDataQosPolicy_Impl> GroupDataQosPolicy;

  // Forward declarations for DomainEntity
  class DomainEntity_Impl;
  typedef DomainEntity_Impl * DomainEntity_in;
  typedef ::GAME::Mga::Smart_Ptr <DomainEntity_Impl> DomainEntity;

  // Forward declarations for WriterDataLifecycleQosPolicy
  class WriterDataLifecycleQosPolicy_Impl;
  typedef WriterDataLifecycleQosPolicy_Impl * WriterDataLifecycleQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <WriterDataLifecycleQosPolicy_Impl> WriterDataLifecycleQosPolicy;

  // Forward declarations for DurabilityServiceQosPolicy
  class DurabilityServiceQosPolicy_Impl;
  typedef DurabilityServiceQosPolicy_Impl * DurabilityServiceQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <DurabilityServiceQosPolicy_Impl> DurabilityServiceQosPolicy;

  // Forward declarations for ReaderLifespanQosPolicy
  class ReaderLifespanQosPolicy_Impl;
  typedef ReaderLifespanQosPolicy_Impl * ReaderLifespanQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <ReaderLifespanQosPolicy_Impl> ReaderLifespanQosPolicy;

  // Forward declarations for HistoryQosPolicy
  class HistoryQosPolicy_Impl;
  typedef HistoryQosPolicy_Impl * HistoryQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <HistoryQosPolicy_Impl> HistoryQosPolicy;

  // Forward declarations for pub_part_Connection
  class pub_part_Connection_Impl;
  typedef pub_part_Connection_Impl * pub_part_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <pub_part_Connection_Impl> pub_part_Connection;

  // Forward declarations for Participant
  class Participant_Impl;
  typedef Participant_Impl * Participant_in;
  typedef ::GAME::Mga::Smart_Ptr <Participant_Impl> Participant;

  // Forward declarations for TopicDataQosPolicy
  class TopicDataQosPolicy_Impl;
  typedef TopicDataQosPolicy_Impl * TopicDataQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <TopicDataQosPolicy_Impl> TopicDataQosPolicy;

  // Forward declarations for dw_durqos_Connection
  class dw_durqos_Connection_Impl;
  typedef dw_durqos_Connection_Impl * dw_durqos_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_durqos_Connection_Impl> dw_durqos_Connection;

  // Forward declarations for SubscriberQos
  class SubscriberQos_Impl;
  typedef SubscriberQos_Impl * SubscriberQos_in;
  typedef ::GAME::Mga::Smart_Ptr <SubscriberQos_Impl> SubscriberQos;

  // Forward declarations for dw_lifespan_Connection
  class dw_lifespan_Connection_Impl;
  typedef dw_lifespan_Connection_Impl * dw_lifespan_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_lifespan_Connection_Impl> dw_lifespan_Connection;

  // Forward declarations for dr_res_Connection
  class dr_res_Connection_Impl;
  typedef dr_res_Connection_Impl * dr_res_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_res_Connection_Impl> dr_res_Connection;

  // Forward declarations for dw_res_Connection
  class dw_res_Connection_Impl;
  typedef dw_res_Connection_Impl * dw_res_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_res_Connection_Impl> dw_res_Connection;

  // Forward declarations for dr_dstOrder_Connection
  class dr_dstOrder_Connection_Impl;
  typedef dr_dstOrder_Connection_Impl * dr_dstOrder_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_dstOrder_Connection_Impl> dr_dstOrder_Connection;

  // Forward declarations for dr_latency_Connection
  class dr_latency_Connection_Impl;
  typedef dr_latency_Connection_Impl * dr_latency_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_latency_Connection_Impl> dr_latency_Connection;

  // Forward declarations for pub_groupdata_Connection
  class pub_groupdata_Connection_Impl;
  typedef pub_groupdata_Connection_Impl * pub_groupdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <pub_groupdata_Connection_Impl> pub_groupdata_Connection;

  // Forward declarations for sub_groupdata_Connection
  class sub_groupdata_Connection_Impl;
  typedef sub_groupdata_Connection_Impl * sub_groupdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <sub_groupdata_Connection_Impl> sub_groupdata_Connection;

  // Forward declarations for dr_userdata_Connection
  class dr_userdata_Connection_Impl;
  typedef dr_userdata_Connection_Impl * dr_userdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_userdata_Connection_Impl> dr_userdata_Connection;

  // Forward declarations for topic_ownership_Connection
  class topic_ownership_Connection_Impl;
  typedef topic_ownership_Connection_Impl * topic_ownership_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_ownership_Connection_Impl> topic_ownership_Connection;

  // Forward declarations for DomainParticipant
  class DomainParticipant_Impl;
  typedef DomainParticipant_Impl * DomainParticipant_in;
  typedef ::GAME::Mga::Smart_Ptr <DomainParticipant_Impl> DomainParticipant;

  // Forward declarations for sub_entityfactory_Connection
  class sub_entityfactory_Connection_Impl;
  typedef sub_entityfactory_Connection_Impl * sub_entityfactory_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <sub_entityfactory_Connection_Impl> sub_entityfactory_Connection;

  // Forward declarations for pub_entityfactory_Connection
  class pub_entityfactory_Connection_Impl;
  typedef pub_entityfactory_Connection_Impl * pub_entityfactory_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <pub_entityfactory_Connection_Impl> pub_entityfactory_Connection;

  // Forward declarations for topic_dstOrder_Connection
  class topic_dstOrder_Connection_Impl;
  typedef topic_dstOrder_Connection_Impl * topic_dstOrder_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_dstOrder_Connection_Impl> topic_dstOrder_Connection;

  // Forward declarations for dw_ownerstrength_Connection
  class dw_ownerstrength_Connection_Impl;
  typedef dw_ownerstrength_Connection_Impl * dw_ownerstrength_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_ownerstrength_Connection_Impl> dw_ownerstrength_Connection;

  // Forward declarations for dw_deadline_Connection
  class dw_deadline_Connection_Impl;
  typedef dw_deadline_Connection_Impl * dw_deadline_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_deadline_Connection_Impl> dw_deadline_Connection;

  // Forward declarations for Topic
  class Topic_Impl;
  typedef Topic_Impl * Topic_in;
  typedef ::GAME::Mga::Smart_Ptr <Topic_Impl> Topic;

  // Forward declarations for TopicQosFolder
  class TopicQosFolder_Impl;
  typedef TopicQosFolder_Impl * TopicQosFolder_in;
  typedef ::GAME::Mga::Smart_Ptr <TopicQosFolder_Impl> TopicQosFolder;

  // Forward declarations for TopicQosReference
  class TopicQosReference_Impl;
  typedef TopicQosReference_Impl * TopicQosReference_in;
  typedef ::GAME::Mga::Smart_Ptr <TopicQosReference_Impl> TopicQosReference;

  // Forward declarations for dr_ownership_Connection
  class dr_ownership_Connection_Impl;
  typedef dr_ownership_Connection_Impl * dr_ownership_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_ownership_Connection_Impl> dr_ownership_Connection;

  // Forward declarations for dw_ownership_Connection
  class dw_ownership_Connection_Impl;
  typedef dw_ownership_Connection_Impl * dw_ownership_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_ownership_Connection_Impl> dw_ownership_Connection;

  // Forward declarations for topic_reliability_Connection
  class topic_reliability_Connection_Impl;
  typedef topic_reliability_Connection_Impl * topic_reliability_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_reliability_Connection_Impl> topic_reliability_Connection;

  // Forward declarations for DataReaderQos
  class DataReaderQos_Impl;
  typedef DataReaderQos_Impl * DataReaderQos_in;
  typedef ::GAME::Mga::Smart_Ptr <DataReaderQos_Impl> DataReaderQos;

  // Forward declarations for topic_topicdata_Connection
  class topic_topicdata_Connection_Impl;
  typedef topic_topicdata_Connection_Impl * topic_topicdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_topicdata_Connection_Impl> topic_topicdata_Connection;

  // Forward declarations for topic_history_Connection
  class topic_history_Connection_Impl;
  typedef topic_history_Connection_Impl * topic_history_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_history_Connection_Impl> topic_history_Connection;

  // Forward declarations for dr_timebased_Connection
  class dr_timebased_Connection_Impl;
  typedef dr_timebased_Connection_Impl * dr_timebased_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_timebased_Connection_Impl> dr_timebased_Connection;

  // Forward declarations for SubscriberConnection
  class SubscriberConnection_Impl;
  typedef SubscriberConnection_Impl * SubscriberConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <SubscriberConnection_Impl> SubscriberConnection;

  // Forward declarations for dp_pub_Connection
  class dp_pub_Connection_Impl;
  typedef dp_pub_Connection_Impl * dp_pub_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dp_pub_Connection_Impl> dp_pub_Connection;

  // Forward declarations for dw_pub_Connection
  class dw_pub_Connection_Impl;
  typedef dw_pub_Connection_Impl * dw_pub_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_pub_Connection_Impl> dw_pub_Connection;

  // Forward declarations for PublisherQos
  class PublisherQos_Impl;
  typedef PublisherQos_Impl * PublisherQos_in;
  typedef ::GAME::Mga::Smart_Ptr <PublisherQos_Impl> PublisherQos;

  // Forward declarations for DeadlineQosPolicy
  class DeadlineQosPolicy_Impl;
  typedef DeadlineQosPolicy_Impl * DeadlineQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <DeadlineQosPolicy_Impl> DeadlineQosPolicy;

  // Forward declarations for PublisherConnection
  class PublisherConnection_Impl;
  typedef PublisherConnection_Impl * PublisherConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <PublisherConnection_Impl> PublisherConnection;

  // Forward declarations for PublishesConnection
  class PublishesConnection_Impl;
  typedef PublishesConnection_Impl * PublishesConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <PublishesConnection_Impl> PublishesConnection;

  // Forward declarations for dw_dstOrder_Connection
  class dw_dstOrder_Connection_Impl;
  typedef dw_dstOrder_Connection_Impl * dw_dstOrder_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_dstOrder_Connection_Impl> dw_dstOrder_Connection;

  // Forward declarations for topic_dursvc_Connection
  class topic_dursvc_Connection_Impl;
  typedef topic_dursvc_Connection_Impl * topic_dursvc_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_dursvc_Connection_Impl> topic_dursvc_Connection;

  // Forward declarations for ReliabilityQosPolicy
  class ReliabilityQosPolicy_Impl;
  typedef ReliabilityQosPolicy_Impl * ReliabilityQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <ReliabilityQosPolicy_Impl> ReliabilityQosPolicy;

  // Forward declarations for dr_history_Connection
  class dr_history_Connection_Impl;
  typedef dr_history_Connection_Impl * dr_history_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_history_Connection_Impl> dr_history_Connection;

  // Forward declarations for dw_topic_Connection
  class dw_topic_Connection_Impl;
  typedef dw_topic_Connection_Impl * dw_topic_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_topic_Connection_Impl> dw_topic_Connection;

  // Forward declarations for TimeBasedFilterQosPolicy
  class TimeBasedFilterQosPolicy_Impl;
  typedef TimeBasedFilterQosPolicy_Impl * TimeBasedFilterQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <TimeBasedFilterQosPolicy_Impl> TimeBasedFilterQosPolicy;

  // Forward declarations for dw_history_Connection
  class dw_history_Connection_Impl;
  typedef dw_history_Connection_Impl * dw_history_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_history_Connection_Impl> dw_history_Connection;

  // Forward declarations for dr_readerdatalifecycle_Connection
  class dr_readerdatalifecycle_Connection_Impl;
  typedef dr_readerdatalifecycle_Connection_Impl * dr_readerdatalifecycle_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_readerdatalifecycle_Connection_Impl> dr_readerdatalifecycle_Connection;

  // Forward declarations for StringSeq_Item
  class StringSeq_Item_Impl;
  typedef StringSeq_Item_Impl * StringSeq_Item_in;
  typedef ::GAME::Mga::Smart_Ptr <StringSeq_Item_Impl> StringSeq_Item;

  // Forward declarations for Subscriber
  class Subscriber_Impl;
  typedef Subscriber_Impl * Subscriber_in;
  typedef ::GAME::Mga::Smart_Ptr <Subscriber_Impl> Subscriber;

  // Forward declarations for DurabilityQosPolicy
  class DurabilityQosPolicy_Impl;
  typedef DurabilityQosPolicy_Impl * DurabilityQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <DurabilityQosPolicy_Impl> DurabilityQosPolicy;

  // Forward declarations for dw_writerdatalifecycle_Connection
  class dw_writerdatalifecycle_Connection_Impl;
  typedef dw_writerdatalifecycle_Connection_Impl * dw_writerdatalifecycle_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_writerdatalifecycle_Connection_Impl> dw_writerdatalifecycle_Connection;

  // Forward declarations for dp_topic_Connection
  class dp_topic_Connection_Impl;
  typedef dp_topic_Connection_Impl * dp_topic_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dp_topic_Connection_Impl> dp_topic_Connection;

  // Forward declarations for dr_topic_Connection
  class dr_topic_Connection_Impl;
  typedef dr_topic_Connection_Impl * dr_topic_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_topic_Connection_Impl> dr_topic_Connection;

  // Forward declarations for DestinationOrderQosPolicy
  class DestinationOrderQosPolicy_Impl;
  typedef DestinationOrderQosPolicy_Impl * DestinationOrderQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <DestinationOrderQosPolicy_Impl> DestinationOrderQosPolicy;

  // Forward declarations for UserDataQosPolicy
  class UserDataQosPolicy_Impl;
  typedef UserDataQosPolicy_Impl * UserDataQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <UserDataQosPolicy_Impl> UserDataQosPolicy;

  // Forward declarations for TopicQos
  class TopicQos_Impl;
  typedef TopicQos_Impl * TopicQos_in;
  typedef ::GAME::Mga::Smart_Ptr <TopicQos_Impl> TopicQos;

  // Forward declarations for dp_entityfactory_Connection
  class dp_entityfactory_Connection_Impl;
  typedef dp_entityfactory_Connection_Impl * dp_entityfactory_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dp_entityfactory_Connection_Impl> dp_entityfactory_Connection;

  // Forward declarations for DDSQoS
  class DDSQoS_Impl;
  typedef DDSQoS_Impl * DDSQoS_in;
  typedef ::GAME::Mga::Smart_Ptr <DDSQoS_Impl> DDSQoS;

  // Forward declarations for topic_liveliness_Connection
  class topic_liveliness_Connection_Impl;
  typedef topic_liveliness_Connection_Impl * topic_liveliness_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_liveliness_Connection_Impl> topic_liveliness_Connection;

  // Forward declarations for dpf_dp_Connection
  class dpf_dp_Connection_Impl;
  typedef dpf_dp_Connection_Impl * dpf_dp_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dpf_dp_Connection_Impl> dpf_dp_Connection;

  // Forward declarations for dr_durqos_Connection
  class dr_durqos_Connection_Impl;
  typedef dr_durqos_Connection_Impl * dr_durqos_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_durqos_Connection_Impl> dr_durqos_Connection;

  // Forward declarations for sub_part_Connection
  class sub_part_Connection_Impl;
  typedef sub_part_Connection_Impl * sub_part_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <sub_part_Connection_Impl> sub_part_Connection;

  // Forward declarations for dr_liveliness_Connection
  class dr_liveliness_Connection_Impl;
  typedef dr_liveliness_Connection_Impl * dr_liveliness_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_liveliness_Connection_Impl> dr_liveliness_Connection;

  // Forward declarations for dw_liveliness_Connection
  class dw_liveliness_Connection_Impl;
  typedef dw_liveliness_Connection_Impl * dw_liveliness_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_liveliness_Connection_Impl> dw_liveliness_Connection;

  // Forward declarations for dr_reliability_Connection
  class dr_reliability_Connection_Impl;
  typedef dr_reliability_Connection_Impl * dr_reliability_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dr_reliability_Connection_Impl> dr_reliability_Connection;

  // Forward declarations for EntityFactoryQosPolicy
  class EntityFactoryQosPolicy_Impl;
  typedef EntityFactoryQosPolicy_Impl * EntityFactoryQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <EntityFactoryQosPolicy_Impl> EntityFactoryQosPolicy;

  // Forward declarations for dw_reliability_Connection
  class dw_reliability_Connection_Impl;
  typedef dw_reliability_Connection_Impl * dw_reliability_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_reliability_Connection_Impl> dw_reliability_Connection;

  // Forward declarations for dw_latency_Connection
  class dw_latency_Connection_Impl;
  typedef dw_latency_Connection_Impl * dw_latency_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_latency_Connection_Impl> dw_latency_Connection;

  // Forward declarations for DataWriter
  class DataWriter_Impl;
  typedef DataWriter_Impl * DataWriter_in;
  typedef ::GAME::Mga::Smart_Ptr <DataWriter_Impl> DataWriter;

  // Forward declarations for DataReader
  class DataReader_Impl;
  typedef DataReader_Impl * DataReader_in;
  typedef ::GAME::Mga::Smart_Ptr <DataReader_Impl> DataReader;

  // Forward declarations for StringSeq
  class StringSeq_Impl;
  typedef StringSeq_Impl * StringSeq_in;
  typedef ::GAME::Mga::Smart_Ptr <StringSeq_Impl> StringSeq;

  // Forward declarations for PresentationQosPolicy
  class PresentationQosPolicy_Impl;
  typedef PresentationQosPolicy_Impl * PresentationQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <PresentationQosPolicy_Impl> PresentationQosPolicy;

  // Forward declarations for LatencyBudgetQosPolicy
  class LatencyBudgetQosPolicy_Impl;
  typedef LatencyBudgetQosPolicy_Impl * LatencyBudgetQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <LatencyBudgetQosPolicy_Impl> LatencyBudgetQosPolicy;

  // Forward declarations for top_deadline_Connection
  class top_deadline_Connection_Impl;
  typedef top_deadline_Connection_Impl * top_deadline_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <top_deadline_Connection_Impl> top_deadline_Connection;

  // Forward declarations for topic_res_Connection
  class topic_res_Connection_Impl;
  typedef topic_res_Connection_Impl * topic_res_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_res_Connection_Impl> topic_res_Connection;

  // Forward declarations for Publisher
  class Publisher_Impl;
  typedef Publisher_Impl * Publisher_in;
  typedef ::GAME::Mga::Smart_Ptr <Publisher_Impl> Publisher;

  // Forward declarations for dw_dursvc_Connection
  class dw_dursvc_Connection_Impl;
  typedef dw_dursvc_Connection_Impl * dw_dursvc_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <dw_dursvc_Connection_Impl> dw_dursvc_Connection;

  // Forward declarations for ShareQosPolicy
  class ShareQosPolicy_Impl;
  typedef ShareQosPolicy_Impl * ShareQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <ShareQosPolicy_Impl> ShareQosPolicy;

  // Forward declarations for Domain
  class Domain_Impl;
  typedef Domain_Impl * Domain_in;
  typedef ::GAME::Mga::Smart_Ptr <Domain_Impl> Domain;

  // Forward declarations for ReaderDataLifecycleQosPolicy
  class ReaderDataLifecycleQosPolicy_Impl;
  typedef ReaderDataLifecycleQosPolicy_Impl * ReaderDataLifecycleQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr <ReaderDataLifecycleQosPolicy_Impl> ReaderDataLifecycleQosPolicy;

  // Forward declarations for topic_lifespan_Connection
  class topic_lifespan_Connection_Impl;
  typedef topic_lifespan_Connection_Impl * topic_lifespan_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr <topic_lifespan_Connection_Impl> topic_lifespan_Connection;
}

#endif
