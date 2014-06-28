// -*- C++ -*-

//============================================================================
/**
 * @file    Visitor.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_VISITOR_H_
#define _DQML_VISITOR_H_

#include "game/mga/Visitor.h"

#include "DQML_fwd.h"
#include "DQML_export.h"

namespace DQML
{
  class DQML_Export Visitor : public ::GAME::Mga::Visitor
  {
    protected:
    /// Default constructor.
    Visitor (void);

    public:
    /// Destructor.
    virtual ~Visitor (void);

    /**
     * @name Visit Methods
     */
    ///@{
    virtual void visit_RootFolder (RootFolder_in folder);
    virtual void visit_dp_userdata_Connection (dp_userdata_Connection_in item);
    virtual void visit_LifespanQosPolicy (LifespanQosPolicy_in item);
    virtual void visit_SchedulingClassQosPolicy (SchedulingClassQosPolicy_in item);
    virtual void visit_ListenerSchedulingQosPolicy (ListenerSchedulingQosPolicy_in item);
    virtual void visit_topic_transpri_Connection (topic_transpri_Connection_in item);
    virtual void visit_DomainParticipantFactory (DomainParticipantFactory_in item);
    virtual void visit_dw_transpri_Connection (dw_transpri_Connection_in item);
    virtual void visit_sub_presqos_Connection (sub_presqos_Connection_in item);
    virtual void visit_pub_presqos_Connection (pub_presqos_Connection_in item);
    virtual void visit_DataWriterQos (DataWriterQos_in item);
    virtual void visit_PartitionQosPolicy (PartitionQosPolicy_in item);
    virtual void visit_dpfactory_entityfactory_Connection (dpfactory_entityfactory_Connection_in item);
    virtual void visit_ResourceLimitsQosPolicy (ResourceLimitsQosPolicy_in item);
    virtual void visit_topic_durqos_Connection (topic_durqos_Connection_in item);
    virtual void visit_DomainQosFolder (DomainQosFolder_in item);
    virtual void visit_WatchdogSchedulingQosPolicy (WatchdogSchedulingQosPolicy_in item);
    virtual void visit_OwnershipStrengthQosPolicy (OwnershipStrengthQosPolicy_in item);
    virtual void visit_dw_userdata_Connection (dw_userdata_Connection_in item);
    virtual void visit_TransportPriorityQosPolicy (TransportPriorityQosPolicy_in item);
    virtual void visit_LivelinessQosPolicy (LivelinessQosPolicy_in item);
    virtual void visit_SubscriptionKeyQosPolicy (SubscriptionKeyQosPolicy_in item);
    virtual void visit_OwnershipQosPolicy (OwnershipQosPolicy_in item);
    virtual void visit_dr_deadline_Connection (dr_deadline_Connection_in item);
    virtual void visit_top_latency_Connection (top_latency_Connection_in item);
    virtual void visit_dp_sub_Connection (dp_sub_Connection_in item);
    virtual void visit_dr_sub_Connection (dr_sub_Connection_in item);
    virtual void visit_iCCM (iCCM_in item);
    virtual void visit_GroupDataQosPolicy (GroupDataQosPolicy_in item);
    virtual void visit_WriterDataLifecycleQosPolicy (WriterDataLifecycleQosPolicy_in item);
    virtual void visit_DurabilityServiceQosPolicy (DurabilityServiceQosPolicy_in item);
    virtual void visit_ReaderLifespanQosPolicy (ReaderLifespanQosPolicy_in item);
    virtual void visit_HistoryQosPolicy (HistoryQosPolicy_in item);
    virtual void visit_pub_part_Connection (pub_part_Connection_in item);
    virtual void visit_Participant (Participant_in item);
    virtual void visit_TopicDataQosPolicy (TopicDataQosPolicy_in item);
    virtual void visit_SchedulingPriorityQosPolicy (SchedulingPriorityQosPolicy_in item);
    virtual void visit_dw_durqos_Connection (dw_durqos_Connection_in item);
    virtual void visit_SubscriberQos (SubscriberQos_in item);
    virtual void visit_dw_lifespan_Connection (dw_lifespan_Connection_in item);
    virtual void visit_dw_res_Connection (dw_res_Connection_in item);
    virtual void visit_dr_res_Connection (dr_res_Connection_in item);
    virtual void visit_dr_dstOrder_Connection (dr_dstOrder_Connection_in item);
    virtual void visit_dr_latency_Connection (dr_latency_Connection_in item);
    virtual void visit_sub_groupdata_Connection (sub_groupdata_Connection_in item);
    virtual void visit_pub_groupdata_Connection (pub_groupdata_Connection_in item);
    virtual void visit_dr_userdata_Connection (dr_userdata_Connection_in item);
    virtual void visit_topic_ownership_Connection (topic_ownership_Connection_in item);
    virtual void visit_DomainParticipant (DomainParticipant_in item);
    virtual void visit_SchedulingQosPolicy (SchedulingQosPolicy_in item);
    virtual void visit_topic_dstOrder_Connection (topic_dstOrder_Connection_in item);
    virtual void visit_pub_entityfactory_Connection (pub_entityfactory_Connection_in item);
    virtual void visit_sub_entityfactory_Connection (sub_entityfactory_Connection_in item);
    virtual void visit_dw_ownerstrength_Connection (dw_ownerstrength_Connection_in item);
    virtual void visit_dw_deadline_Connection (dw_deadline_Connection_in item);
    virtual void visit_Topic (Topic_in item);
    virtual void visit_TopicQosFolder (TopicQosFolder_in item);
    virtual void visit_TopicQosReference (TopicQosReference_in item);
    virtual void visit_dw_ownership_Connection (dw_ownership_Connection_in item);
    virtual void visit_dr_ownership_Connection (dr_ownership_Connection_in item);
    virtual void visit_topic_reliability_Connection (topic_reliability_Connection_in item);
    virtual void visit_DataReaderQos (DataReaderQos_in item);
    virtual void visit_topic_topicdata_Connection (topic_topicdata_Connection_in item);
    virtual void visit_topic_history_Connection (topic_history_Connection_in item);
    virtual void visit_dr_timebased_Connection (dr_timebased_Connection_in item);
    virtual void visit_SubscriberConnection (SubscriberConnection_in item);
    virtual void visit_dp_pub_Connection (dp_pub_Connection_in item);
    virtual void visit_dw_pub_Connection (dw_pub_Connection_in item);
    virtual void visit_PublisherQos (PublisherQos_in item);
    virtual void visit_DeadlineQosPolicy (DeadlineQosPolicy_in item);
    virtual void visit_PublisherConnection (PublisherConnection_in item);
    virtual void visit_PublishesConnection (PublishesConnection_in item);
    virtual void visit_topic_dursvc_Connection (topic_dursvc_Connection_in item);
    virtual void visit_dw_dstOrder_Connection (dw_dstOrder_Connection_in item);
    virtual void visit_ReliabilityQosPolicy (ReliabilityQosPolicy_in item);
    virtual void visit_dr_history_Connection (dr_history_Connection_in item);
    virtual void visit_dw_topic_Connection (dw_topic_Connection_in item);
    virtual void visit_TimeBasedFilterQosPolicy (TimeBasedFilterQosPolicy_in item);
    virtual void visit_dw_history_Connection (dw_history_Connection_in item);
    virtual void visit_dr_readerdatalifecycle_Connection (dr_readerdatalifecycle_Connection_in item);
    virtual void visit_StringSeq_Item (StringSeq_Item_in item);
    virtual void visit_Subscriber (Subscriber_in item);
    virtual void visit_DurabilityQosPolicy (DurabilityQosPolicy_in item);
    virtual void visit_dw_writerdatalifecycle_Connection (dw_writerdatalifecycle_Connection_in item);
    virtual void visit_dp_topic_Connection (dp_topic_Connection_in item);
    virtual void visit_dr_topic_Connection (dr_topic_Connection_in item);
    virtual void visit_DestinationOrderQosPolicy (DestinationOrderQosPolicy_in item);
    virtual void visit_UserDataQosPolicy (UserDataQosPolicy_in item);
    virtual void visit_TopicQos (TopicQos_in item);
    virtual void visit_dp_entityfactory_Connection (dp_entityfactory_Connection_in item);
    virtual void visit_DDSQoS (DDSQoS_in item);
    virtual void visit_topic_liveliness_Connection (topic_liveliness_Connection_in item);
    virtual void visit_dpf_dp_Connection (dpf_dp_Connection_in item);
    virtual void visit_dr_durqos_Connection (dr_durqos_Connection_in item);
    virtual void visit_sub_part_Connection (sub_part_Connection_in item);
    virtual void visit_dr_reliability_Connection (dr_reliability_Connection_in item);
    virtual void visit_dw_liveliness_Connection (dw_liveliness_Connection_in item);
    virtual void visit_dr_liveliness_Connection (dr_liveliness_Connection_in item);
    virtual void visit_EntityFactoryQosPolicy (EntityFactoryQosPolicy_in item);
    virtual void visit_dw_reliability_Connection (dw_reliability_Connection_in item);
    virtual void visit_dw_latency_Connection (dw_latency_Connection_in item);
    virtual void visit_DataReader (DataReader_in item);
    virtual void visit_DataWriter (DataWriter_in item);
    virtual void visit_StringSeq (StringSeq_in item);
    virtual void visit_LatencyBudgetQosPolicy (LatencyBudgetQosPolicy_in item);
    virtual void visit_PresentationQosPolicy (PresentationQosPolicy_in item);
    virtual void visit_top_deadline_Connection (top_deadline_Connection_in item);
    virtual void visit_topic_res_Connection (topic_res_Connection_in item);
    virtual void visit_Publisher (Publisher_in item);
    virtual void visit_dw_dursvc_Connection (dw_dursvc_Connection_in item);
    virtual void visit_ShareQosPolicy (ShareQosPolicy_in item);
    virtual void visit_Domain (Domain_in item);
    virtual void visit_ReaderDataLifecycleQosPolicy (ReaderDataLifecycleQosPolicy_in item);
    virtual void visit_topic_lifespan_Connection (topic_lifespan_Connection_in item);
    ///@}
    private:
    // prevent the following operation(s)
    const Visitor & operator = (const Visitor &);
  };
}

#endif
