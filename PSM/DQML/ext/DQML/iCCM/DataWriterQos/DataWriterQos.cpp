// $Id$

#include "StdAfx.h"
#include "DataWriterQos.h"

#if !defined (__GAME_INLINE__)
#include "DataWriterQos.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LatencyBudgetQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LivelinessQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReliabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DestinationOrderQosPolicy.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipStrengthQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TransportPriorityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LifespanQosPolicy.h"
#include "DQML/Standard/QoSPolicies/HistoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ResourceLimitsQosPolicy.h"
#include "DQML/Standard/QoSPolicies/WriterDataLifecycleQosPolicy.h"
#include "DQML/iCCM/TopicQos/TopicQosReference.h"
#include "DQML/iCCM/DomainQos/PublishesConnection.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "DQML/iCCM/DomainQos/PublisherConnection.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DataWriterQos_Impl::metaname ("DataWriterQos");

  //
  // _create (const Participant_in)
  //
  DataWriterQos DataWriterQos_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create_object < DataWriterQos > (parent, DataWriterQos_Impl::metaname);
  }

  //
  // accept
  //
  void DataWriterQos_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DataWriterQos (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // src_PublishesConnection
  //
  size_t DataWriterQos_Impl::src_PublishesConnection (std::vector <PublishesConnection> & items) const
  {
    return this->in_connections <PublishesConnection> (items);
  }

  //
  // src_PublisherConnection
  //
  size_t DataWriterQos_Impl::src_PublisherConnection (std::vector <PublisherConnection> & items) const
  {
    return this->in_connections <PublisherConnection> (items);
  }

  //
  // has_DurabilityQosPolicy
  //
  bool DataWriterQos_Impl::has_DurabilityQosPolicy (void) const
  {
    return this->children <DurabilityQosPolicy> ().count () == 1;
  }

  //
  // get_DurabilityQosPolicy
  //
  DurabilityQosPolicy DataWriterQos_Impl::get_DurabilityQosPolicy (void) const
  {
    return this->children <DurabilityQosPolicy> ().item ();
  }

  //
  // has_DeadlineQosPolicy
  //
  bool DataWriterQos_Impl::has_DeadlineQosPolicy (void) const
  {
    return this->children <DeadlineQosPolicy> ().count () == 1;
  }

  //
  // get_DeadlineQosPolicy
  //
  DeadlineQosPolicy DataWriterQos_Impl::get_DeadlineQosPolicy (void) const
  {
    return this->children <DeadlineQosPolicy> ().item ();
  }

  //
  // has_LatencyBudgetQosPolicy
  //
  bool DataWriterQos_Impl::has_LatencyBudgetQosPolicy (void) const
  {
    return this->children <LatencyBudgetQosPolicy> ().count () == 1;
  }

  //
  // get_LatencyBudgetQosPolicy
  //
  LatencyBudgetQosPolicy DataWriterQos_Impl::get_LatencyBudgetQosPolicy (void) const
  {
    return this->children <LatencyBudgetQosPolicy> ().item ();
  }

  //
  // has_OwnershipQosPolicy
  //
  bool DataWriterQos_Impl::has_OwnershipQosPolicy (void) const
  {
    return this->children <OwnershipQosPolicy> ().count () == 1;
  }

  //
  // get_OwnershipQosPolicy
  //
  OwnershipQosPolicy DataWriterQos_Impl::get_OwnershipQosPolicy (void) const
  {
    return this->children <OwnershipQosPolicy> ().item ();
  }

  //
  // has_LivelinessQosPolicy
  //
  bool DataWriterQos_Impl::has_LivelinessQosPolicy (void) const
  {
    return this->children <LivelinessQosPolicy> ().count () == 1;
  }

  //
  // get_LivelinessQosPolicy
  //
  LivelinessQosPolicy DataWriterQos_Impl::get_LivelinessQosPolicy (void) const
  {
    return this->children <LivelinessQosPolicy> ().item ();
  }

  //
  // has_ReliabilityQosPolicy
  //
  bool DataWriterQos_Impl::has_ReliabilityQosPolicy (void) const
  {
    return this->children <ReliabilityQosPolicy> ().count () == 1;
  }

  //
  // get_ReliabilityQosPolicy
  //
  ReliabilityQosPolicy DataWriterQos_Impl::get_ReliabilityQosPolicy (void) const
  {
    return this->children <ReliabilityQosPolicy> ().item ();
  }

  //
  // has_DestinationOrderQosPolicy
  //
  bool DataWriterQos_Impl::has_DestinationOrderQosPolicy (void) const
  {
    return this->children <DestinationOrderQosPolicy> ().count () == 1;
  }

  //
  // get_DestinationOrderQosPolicy
  //
  DestinationOrderQosPolicy DataWriterQos_Impl::get_DestinationOrderQosPolicy (void) const
  {
    return this->children <DestinationOrderQosPolicy> ().item ();
  }

  //
  // has_UserDataQosPolicy
  //
  bool DataWriterQos_Impl::has_UserDataQosPolicy (void) const
  {
    return this->children <UserDataQosPolicy> ().count () == 1;
  }

  //
  // get_UserDataQosPolicy
  //
  UserDataQosPolicy DataWriterQos_Impl::get_UserDataQosPolicy (void) const
  {
    return this->children <UserDataQosPolicy> ().item ();
  }

  //
  // has_OwnershipStrengthQosPolicy
  //
  bool DataWriterQos_Impl::has_OwnershipStrengthQosPolicy (void) const
  {
    return this->children <OwnershipStrengthQosPolicy> ().count () == 1;
  }

  //
  // get_OwnershipStrengthQosPolicy
  //
  OwnershipStrengthQosPolicy DataWriterQos_Impl::get_OwnershipStrengthQosPolicy (void) const
  {
    return this->children <OwnershipStrengthQosPolicy> ().item ();
  }

  //
  // has_TransportPriorityQosPolicy
  //
  bool DataWriterQos_Impl::has_TransportPriorityQosPolicy (void) const
  {
    return this->children <TransportPriorityQosPolicy> ().count () == 1;
  }

  //
  // get_TransportPriorityQosPolicy
  //
  TransportPriorityQosPolicy DataWriterQos_Impl::get_TransportPriorityQosPolicy (void) const
  {
    return this->children <TransportPriorityQosPolicy> ().item ();
  }

  //
  // has_LifespanQosPolicy
  //
  bool DataWriterQos_Impl::has_LifespanQosPolicy (void) const
  {
    return this->children <LifespanQosPolicy> ().count () == 1;
  }

  //
  // get_LifespanQosPolicy
  //
  LifespanQosPolicy DataWriterQos_Impl::get_LifespanQosPolicy (void) const
  {
    return this->children <LifespanQosPolicy> ().item ();
  }

  //
  // has_HistoryQosPolicy
  //
  bool DataWriterQos_Impl::has_HistoryQosPolicy (void) const
  {
    return this->children <HistoryQosPolicy> ().count () == 1;
  }

  //
  // get_HistoryQosPolicy
  //
  HistoryQosPolicy DataWriterQos_Impl::get_HistoryQosPolicy (void) const
  {
    return this->children <HistoryQosPolicy> ().item ();
  }

  //
  // has_ResourceLimitsQosPolicy
  //
  bool DataWriterQos_Impl::has_ResourceLimitsQosPolicy (void) const
  {
    return this->children <ResourceLimitsQosPolicy> ().count () == 1;
  }

  //
  // get_ResourceLimitsQosPolicy
  //
  ResourceLimitsQosPolicy DataWriterQos_Impl::get_ResourceLimitsQosPolicy (void) const
  {
    return this->children <ResourceLimitsQosPolicy> ().item ();
  }

  //
  // has_WriterDataLifecycleQosPolicy
  //
  bool DataWriterQos_Impl::has_WriterDataLifecycleQosPolicy (void) const
  {
    return this->children <WriterDataLifecycleQosPolicy> ().count () == 1;
  }

  //
  // get_WriterDataLifecycleQosPolicy
  //
  WriterDataLifecycleQosPolicy DataWriterQos_Impl::get_WriterDataLifecycleQosPolicy (void) const
  {
    return this->children <WriterDataLifecycleQosPolicy> ().item ();
  }

  //
  // has_TopicQosReference
  //
  bool DataWriterQos_Impl::has_TopicQosReference (void) const
  {
    return this->children <TopicQosReference> ().count () == 1;
  }

  //
  // get_TopicQosReference
  //
  TopicQosReference DataWriterQos_Impl::get_TopicQosReference (void) const
  {
    return this->children <TopicQosReference> ().item ();
  }
}

