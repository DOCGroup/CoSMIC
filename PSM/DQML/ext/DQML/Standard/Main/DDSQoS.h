// -*- C++ -*-

//============================================================================
/**
 * @file    DDSQoS.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_MAIN_DDSQOS_H_
#define _DQML_STANDARD_MAIN_DDSQOS_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/RootFolder.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DDSQoS_Impl;
  typedef DDSQoS_Impl * DDSQoS_in;
  typedef ::GAME::Mga::Smart_Ptr < DDSQoS_Impl > DDSQoS;

  // Forward decl.
  class Visitor;

  /**
   * @class DDSQoS_Impl
   *
   * Implementation for the DDSQoS model element.
   */
  class DQML_Export DDSQoS_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static DDSQoS _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    DDSQoS_Impl (void);

    // Initializing constructor.
    DDSQoS_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DDSQoS_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_dw_ownership_Connections (std::vector <dw_ownership_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_ownership_Connection> get_dw_ownership_Connections (void) const;

    size_t get_dr_reliability_Connections (std::vector <dr_reliability_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_reliability_Connection> get_dr_reliability_Connections (void) const;

    size_t get_dr_topic_Connections (std::vector <dr_topic_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_topic_Connection> get_dr_topic_Connections (void) const;

    size_t get_topic_transpri_Connections (std::vector <topic_transpri_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_transpri_Connection> get_topic_transpri_Connections (void) const;

    size_t get_topic_reliability_Connections (std::vector <topic_reliability_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_reliability_Connection> get_topic_reliability_Connections (void) const;

    size_t get_dr_timebased_Connections (std::vector <dr_timebased_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_timebased_Connection> get_dr_timebased_Connections (void) const;

    size_t get_dr_readerdatalifecycle_Connections (std::vector <dr_readerdatalifecycle_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_readerdatalifecycle_Connection> get_dr_readerdatalifecycle_Connections (void) const;

    size_t get_topic_dursvc_Connections (std::vector <topic_dursvc_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_dursvc_Connection> get_topic_dursvc_Connections (void) const;

    size_t get_dw_reliability_Connections (std::vector <dw_reliability_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_reliability_Connection> get_dw_reliability_Connections (void) const;

    size_t get_dw_dursvc_Connections (std::vector <dw_dursvc_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_dursvc_Connection> get_dw_dursvc_Connections (void) const;

    size_t get_dr_ownership_Connections (std::vector <dr_ownership_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_ownership_Connection> get_dr_ownership_Connections (void) const;

    size_t get_topic_ownership_Connections (std::vector <topic_ownership_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_ownership_Connection> get_topic_ownership_Connections (void) const;

    size_t get_DeadlineQosPolicys (std::vector <DeadlineQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <DeadlineQosPolicy> get_DeadlineQosPolicys (void) const;

    size_t get_TopicDataQosPolicys (std::vector <TopicDataQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <TopicDataQosPolicy> get_TopicDataQosPolicys (void) const;

    size_t get_ResourceLimitsQosPolicys (std::vector <ResourceLimitsQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <ResourceLimitsQosPolicy> get_ResourceLimitsQosPolicys (void) const;

    size_t get_DurabilityQosPolicys (std::vector <DurabilityQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <DurabilityQosPolicy> get_DurabilityQosPolicys (void) const;

    size_t get_EntityFactoryQosPolicys (std::vector <EntityFactoryQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <EntityFactoryQosPolicy> get_EntityFactoryQosPolicys (void) const;

    size_t get_PartitionQosPolicys (std::vector <PartitionQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <PartitionQosPolicy> get_PartitionQosPolicys (void) const;

    size_t get_UserDataQosPolicys (std::vector <UserDataQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <UserDataQosPolicy> get_UserDataQosPolicys (void) const;

    size_t get_GroupDataQosPolicys (std::vector <GroupDataQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <GroupDataQosPolicy> get_GroupDataQosPolicys (void) const;

    size_t get_PresentationQosPolicys (std::vector <PresentationQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <PresentationQosPolicy> get_PresentationQosPolicys (void) const;

    size_t get_WriterDataLifecycleQosPolicys (std::vector <WriterDataLifecycleQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <WriterDataLifecycleQosPolicy> get_WriterDataLifecycleQosPolicys (void) const;

    size_t get_LifespanQosPolicys (std::vector <LifespanQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <LifespanQosPolicy> get_LifespanQosPolicys (void) const;

    size_t get_OwnershipStrengthQosPolicys (std::vector <OwnershipStrengthQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <OwnershipStrengthQosPolicy> get_OwnershipStrengthQosPolicys (void) const;

    size_t get_DestinationOrderQosPolicys (std::vector <DestinationOrderQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <DestinationOrderQosPolicy> get_DestinationOrderQosPolicys (void) const;

    size_t get_LatencyBudgetQosPolicys (std::vector <LatencyBudgetQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <LatencyBudgetQosPolicy> get_LatencyBudgetQosPolicys (void) const;

    size_t get_HistoryQosPolicys (std::vector <HistoryQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <HistoryQosPolicy> get_HistoryQosPolicys (void) const;

    size_t get_TransportPriorityQosPolicys (std::vector <TransportPriorityQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <TransportPriorityQosPolicy> get_TransportPriorityQosPolicys (void) const;

    size_t get_DurabilityServiceQosPolicys (std::vector <DurabilityServiceQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <DurabilityServiceQosPolicy> get_DurabilityServiceQosPolicys (void) const;

    size_t get_ReliabilityQosPolicys (std::vector <ReliabilityQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <ReliabilityQosPolicy> get_ReliabilityQosPolicys (void) const;

    size_t get_OwnershipQosPolicys (std::vector <OwnershipQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <OwnershipQosPolicy> get_OwnershipQosPolicys (void) const;

    size_t get_TimeBasedFilterQosPolicys (std::vector <TimeBasedFilterQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <TimeBasedFilterQosPolicy> get_TimeBasedFilterQosPolicys (void) const;

    size_t get_ReaderDataLifecycleQosPolicys (std::vector <ReaderDataLifecycleQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <ReaderDataLifecycleQosPolicy> get_ReaderDataLifecycleQosPolicys (void) const;

    size_t get_ShareQosPolicys (std::vector <ShareQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <ShareQosPolicy> get_ShareQosPolicys (void) const;

    size_t get_ReaderLifespanQosPolicys (std::vector <ReaderLifespanQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <ReaderLifespanQosPolicy> get_ReaderLifespanQosPolicys (void) const;

    size_t get_SubscriptionKeyQosPolicys (std::vector <SubscriptionKeyQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <SubscriptionKeyQosPolicy> get_SubscriptionKeyQosPolicys (void) const;

    size_t get_SchedulingPriorityQosPolicys (std::vector <SchedulingPriorityQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <SchedulingPriorityQosPolicy> get_SchedulingPriorityQosPolicys (void) const;

    size_t get_SchedulingClassQosPolicys (std::vector <SchedulingClassQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <SchedulingClassQosPolicy> get_SchedulingClassQosPolicys (void) const;

    size_t get_LivelinessQosPolicys (std::vector <LivelinessQosPolicy> & items) const;
    ::GAME::Mga::Collection_T <LivelinessQosPolicy> get_LivelinessQosPolicys (void) const;

    size_t get_pub_groupdata_Connections (std::vector <pub_groupdata_Connection> & items) const;
    ::GAME::Mga::Collection_T <pub_groupdata_Connection> get_pub_groupdata_Connections (void) const;

    size_t get_sub_presqos_Connections (std::vector <sub_presqos_Connection> & items) const;
    ::GAME::Mga::Collection_T <sub_presqos_Connection> get_sub_presqos_Connections (void) const;

    size_t get_pub_presqos_Connections (std::vector <pub_presqos_Connection> & items) const;
    ::GAME::Mga::Collection_T <pub_presqos_Connection> get_pub_presqos_Connections (void) const;

    size_t get_pub_part_Connections (std::vector <pub_part_Connection> & items) const;
    ::GAME::Mga::Collection_T <pub_part_Connection> get_pub_part_Connections (void) const;

    size_t get_dr_sub_Connections (std::vector <dr_sub_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_sub_Connection> get_dr_sub_Connections (void) const;

    size_t get_dp_sub_Connections (std::vector <dp_sub_Connection> & items) const;
    ::GAME::Mga::Collection_T <dp_sub_Connection> get_dp_sub_Connections (void) const;

    size_t get_sub_groupdata_Connections (std::vector <sub_groupdata_Connection> & items) const;
    ::GAME::Mga::Collection_T <sub_groupdata_Connection> get_sub_groupdata_Connections (void) const;

    size_t get_dr_userdata_Connections (std::vector <dr_userdata_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_userdata_Connection> get_dr_userdata_Connections (void) const;

    size_t get_dp_userdata_Connections (std::vector <dp_userdata_Connection> & items) const;
    ::GAME::Mga::Collection_T <dp_userdata_Connection> get_dp_userdata_Connections (void) const;

    size_t get_dw_userdata_Connections (std::vector <dw_userdata_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_userdata_Connection> get_dw_userdata_Connections (void) const;

    size_t get_dpf_dp_Connections (std::vector <dpf_dp_Connection> & items) const;
    ::GAME::Mga::Collection_T <dpf_dp_Connection> get_dpf_dp_Connections (void) const;

    size_t get_dpfactory_entityfactory_Connections (std::vector <dpfactory_entityfactory_Connection> & items) const;
    ::GAME::Mga::Collection_T <dpfactory_entityfactory_Connection> get_dpfactory_entityfactory_Connections (void) const;

    size_t get_dp_entityfactory_Connections (std::vector <dp_entityfactory_Connection> & items) const;
    ::GAME::Mga::Collection_T <dp_entityfactory_Connection> get_dp_entityfactory_Connections (void) const;

    size_t get_dw_writerdatalifecycle_Connections (std::vector <dw_writerdatalifecycle_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_writerdatalifecycle_Connection> get_dw_writerdatalifecycle_Connections (void) const;

    size_t get_dw_lifespan_Connections (std::vector <dw_lifespan_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_lifespan_Connection> get_dw_lifespan_Connections (void) const;

    size_t get_dp_pub_Connections (std::vector <dp_pub_Connection> & items) const;
    ::GAME::Mga::Collection_T <dp_pub_Connection> get_dp_pub_Connections (void) const;

    size_t get_dp_topic_Connections (std::vector <dp_topic_Connection> & items) const;
    ::GAME::Mga::Collection_T <dp_topic_Connection> get_dp_topic_Connections (void) const;

    size_t get_dw_dstOrder_Connections (std::vector <dw_dstOrder_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_dstOrder_Connection> get_dw_dstOrder_Connections (void) const;

    size_t get_topic_dstOrder_Connections (std::vector <topic_dstOrder_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_dstOrder_Connection> get_topic_dstOrder_Connections (void) const;

    size_t get_dr_dstOrder_Connections (std::vector <dr_dstOrder_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_dstOrder_Connection> get_dr_dstOrder_Connections (void) const;

    size_t get_dw_ownerstrength_Connections (std::vector <dw_ownerstrength_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_ownerstrength_Connection> get_dw_ownerstrength_Connections (void) const;

    size_t get_topic_lifespan_Connections (std::vector <topic_lifespan_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_lifespan_Connection> get_topic_lifespan_Connections (void) const;

    size_t get_dw_transpri_Connections (std::vector <dw_transpri_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_transpri_Connection> get_dw_transpri_Connections (void) const;

    size_t get_dr_history_Connections (std::vector <dr_history_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_history_Connection> get_dr_history_Connections (void) const;

    size_t get_dw_history_Connections (std::vector <dw_history_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_history_Connection> get_dw_history_Connections (void) const;

    size_t get_topic_history_Connections (std::vector <topic_history_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_history_Connection> get_topic_history_Connections (void) const;

    size_t get_top_latency_Connections (std::vector <top_latency_Connection> & items) const;
    ::GAME::Mga::Collection_T <top_latency_Connection> get_top_latency_Connections (void) const;

    size_t get_dr_latency_Connections (std::vector <dr_latency_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_latency_Connection> get_dr_latency_Connections (void) const;

    size_t get_dw_deadline_Connections (std::vector <dw_deadline_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_deadline_Connection> get_dw_deadline_Connections (void) const;

    size_t get_dw_liveliness_Connections (std::vector <dw_liveliness_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_liveliness_Connection> get_dw_liveliness_Connections (void) const;

    size_t get_dw_latency_Connections (std::vector <dw_latency_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_latency_Connection> get_dw_latency_Connections (void) const;

    size_t get_dr_liveliness_Connections (std::vector <dr_liveliness_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_liveliness_Connection> get_dr_liveliness_Connections (void) const;

    size_t get_dr_deadline_Connections (std::vector <dr_deadline_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_deadline_Connection> get_dr_deadline_Connections (void) const;

    size_t get_top_deadline_Connections (std::vector <top_deadline_Connection> & items) const;
    ::GAME::Mga::Collection_T <top_deadline_Connection> get_top_deadline_Connections (void) const;

    size_t get_topic_liveliness_Connections (std::vector <topic_liveliness_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_liveliness_Connection> get_topic_liveliness_Connections (void) const;

    size_t get_topic_topicdata_Connections (std::vector <topic_topicdata_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_topicdata_Connection> get_topic_topicdata_Connections (void) const;

    size_t get_topic_res_Connections (std::vector <topic_res_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_res_Connection> get_topic_res_Connections (void) const;

    size_t get_dr_res_Connections (std::vector <dr_res_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_res_Connection> get_dr_res_Connections (void) const;

    size_t get_dw_res_Connections (std::vector <dw_res_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_res_Connection> get_dw_res_Connections (void) const;

    size_t get_dw_durqos_Connections (std::vector <dw_durqos_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_durqos_Connection> get_dw_durqos_Connections (void) const;

    size_t get_topic_durqos_Connections (std::vector <topic_durqos_Connection> & items) const;
    ::GAME::Mga::Collection_T <topic_durqos_Connection> get_topic_durqos_Connections (void) const;

    size_t get_dr_durqos_Connections (std::vector <dr_durqos_Connection> & items) const;
    ::GAME::Mga::Collection_T <dr_durqos_Connection> get_dr_durqos_Connections (void) const;

    size_t get_dw_topic_Connections (std::vector <dw_topic_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_topic_Connection> get_dw_topic_Connections (void) const;

    size_t get_dw_pub_Connections (std::vector <dw_pub_Connection> & items) const;
    ::GAME::Mga::Collection_T <dw_pub_Connection> get_dw_pub_Connections (void) const;

    size_t get_pub_entityfactory_Connections (std::vector <pub_entityfactory_Connection> & items) const;
    ::GAME::Mga::Collection_T <pub_entityfactory_Connection> get_pub_entityfactory_Connections (void) const;

    size_t get_sub_entityfactory_Connections (std::vector <sub_entityfactory_Connection> & items) const;
    ::GAME::Mga::Collection_T <sub_entityfactory_Connection> get_sub_entityfactory_Connections (void) const;

    size_t get_sub_part_Connections (std::vector <sub_part_Connection> & items) const;
    ::GAME::Mga::Collection_T <sub_part_Connection> get_sub_part_Connections (void) const;

    size_t get_DomainParticipants (std::vector <DomainParticipant> & items) const;
    ::GAME::Mga::Collection_T <DomainParticipant> get_DomainParticipants (void) const;

    size_t get_DomainParticipantFactorys (std::vector <DomainParticipantFactory> & items) const;
    ::GAME::Mga::Collection_T <DomainParticipantFactory> get_DomainParticipantFactorys (void) const;

    size_t get_Topics (std::vector <Topic> & items) const;
    ::GAME::Mga::Collection_T <Topic> get_Topics (void) const;

    size_t get_DataReaders (std::vector <DataReader> & items) const;
    ::GAME::Mga::Collection_T <DataReader> get_DataReaders (void) const;

    size_t get_Subscribers (std::vector <Subscriber> & items) const;
    ::GAME::Mga::Collection_T <Subscriber> get_Subscribers (void) const;

    size_t get_DataWriters (std::vector <DataWriter> & items) const;
    ::GAME::Mga::Collection_T <DataWriter> get_DataWriters (void) const;

    size_t get_Publishers (std::vector <Publisher> & items) const;
    ::GAME::Mga::Collection_T <Publisher> get_Publishers (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DDSQoS.inl"
#endif

#endif  // !defined _DQML_STANDARD_MAIN_DDSQOS
