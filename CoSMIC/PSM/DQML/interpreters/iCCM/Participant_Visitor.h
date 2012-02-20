// -*- C++ -*-

//=============================================================================
/**
 * @file       Participant_Visitor.h
 *
 * $Id$
 *
 * @author     James H. Hill
 */
//=============================================================================

#ifndef _DQML_ICCM_PARTICIPANT_VISITOR_H_
#define _DQML_ICCM_PARTICIPANT_VISITOR_H_

#include "DQML/Visitor.h"
#include "game/xml/Document.h"

namespace DQML_iCCM
{
/**
 * @class Participant_Visitor
 */
class Participant_Visitor : public DQML::Visitor
{
public:
  /// Initializing constructor.
  Participant_Visitor (GAME::Xml::Document & doc);

  /// Destructor.
  virtual ~Participant_Visitor (void);

  virtual void visit_Participant (DQML::Participant_in item);

  virtual void visit_EntityFactoryQosPolicy (DQML::EntityFactoryQosPolicy_in item);
  virtual void visit_TopicQos (DQML::TopicQos_in item);

  virtual void visit_DestinationOrderQosPolicy (DQML::DestinationOrderQosPolicy_in item);
  virtual void visit_DeadlineQosPolicy (DQML::DeadlineQosPolicy_in item);
  virtual void visit_DurabilityQosPolicy (DQML::DurabilityQosPolicy_in item);
  virtual void visit_DurabilityServiceQosPolicy (DQML::DurabilityServiceQosPolicy_in item);
  virtual void visit_GroupDataQosPolicy (DQML::GroupDataQosPolicy item);
  virtual void visit_HistoryQosPolicy (DQML::HistoryQosPolicy_in item);
  virtual void visit_LatencyBudgetQosPolicy (DQML::LatencyBudgetQosPolicy_in item);
  virtual void visit_LivelinessQosPolicy (DQML::LivelinessQosPolicy_in item);
  virtual void visit_ReliabilityQosPolicy (DQML::ReliabilityQosPolicy_in item);
  virtual void visit_TopicDataQosPolicy (DQML::TopicDataQosPolicy_in item);
  virtual void visit_UserDataQosPolicy (DQML::UserDataQosPolicy_in item);

  virtual void visit_PublisherQos (DQML::PublisherQos_in item);
  virtual void visit_SubscriberQos (DQML::SubscriberQos_in item);

  virtual void visit_ResourceLimitsQosPolicy (DQML::ResourceLimitsQosPolicy_in item);
  virtual void visit_TransportPriorityQosPolicy (DQML::TransportPriorityQosPolicy_in item);
  virtual void visit_LifespanQosPolicy (DQML::LifespanQosPolicy_in item);
  virtual void visit_OwnershipQosPolicy (DQML::OwnershipQosPolicy_in item);
  virtual void visit_OwnershipStrengthQosPolicy (DQML::OwnershipStrengthQosPolicy_in item);

  virtual void visit_PresentationQosPolicy (DQML::PresentationQosPolicy_in item);
  virtual void visit_PartitionQosPolicy (DQML::PartitionQosPolicy_in item);
  virtual void visit_WriterDataLifecycleQosPolicy (DQML::WriterDataLifecycleQosPolicy_in item);

  virtual void visit_DataWriterQos (DQML::DataWriterQos_in item);
  virtual void visit_DataReaderQos (DQML::DataReaderQos_in item);

  virtual void visit_TimeBasedFilterQosPolicy (DQML::TimeBasedFilterQosPolicy_in item);
  virtual void visit_ReaderDataLifecycleQosPolicy (DQML::ReaderDataLifecycleQosPolicy_in item);

private:
  GAME::Xml::Document & doc_;

  GAME::Xml::Fragment current_;
};

}

#endif  // !defined _DQML_ICCM_PARTICIPANT_VISITOR_H_
