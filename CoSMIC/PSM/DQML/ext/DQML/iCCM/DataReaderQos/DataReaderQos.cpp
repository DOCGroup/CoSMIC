// $Id$

#include "StdAfx.h"
#include "DataReaderQos.h"

#if !defined (__GAME_INLINE__)
#include "DataReaderQos.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TimeBasedFilterQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LatencyBudgetQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LivelinessQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReliabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DestinationOrderQosPolicy.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/HistoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ResourceLimitsQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReaderDataLifecycleQosPolicy.h"
#include "DQML/iCCM/TopicQos/TopicQosReference.h"
#include "DQML/iCCM/DomainQos/SubscriberConnection.h"
#include "DQML/iCCM/DomainQos/PublishesConnection.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DataReaderQos_Impl::metaname ("DataReaderQos");

  //
  // _create (const Participant_in)
  //
  DataReaderQos DataReaderQos_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create_object < DataReaderQos > (parent, DataReaderQos_Impl::metaname);
  }

  //
  // accept
  //
  void DataReaderQos_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DataReaderQos (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // src_SubscriberConnection
  //
  size_t DataReaderQos_Impl::src_SubscriberConnection (std::vector <SubscriberConnection> & items) const
  {
    return this->in_connections <SubscriberConnection> (items);
  }

  //
  // dst_PublishesConnection
  //
  size_t DataReaderQos_Impl::dst_PublishesConnection (std::vector <PublishesConnection> & items) const
  {
    return this->in_connections <PublishesConnection> (items);
  }

  //
  // has_DurabilityQosPolicy
  //
  bool DataReaderQos_Impl::has_DurabilityQosPolicy (void) const
  {
    return this->children <DurabilityQosPolicy> ().count () == 1;
  }

  //
  // get_DurabilityQosPolicy
  //
  DurabilityQosPolicy DataReaderQos_Impl::get_DurabilityQosPolicy (void) const
  {
    return this->children <DurabilityQosPolicy> ().item ();
  }

  //
  // has_DeadlineQosPolicy
  //
  bool DataReaderQos_Impl::has_DeadlineQosPolicy (void) const
  {
    return this->children <DeadlineQosPolicy> ().count () == 1;
  }

  //
  // get_DeadlineQosPolicy
  //
  DeadlineQosPolicy DataReaderQos_Impl::get_DeadlineQosPolicy (void) const
  {
    return this->children <DeadlineQosPolicy> ().item ();
  }

  //
  // has_TimeBasedFilterQosPolicy
  //
  bool DataReaderQos_Impl::has_TimeBasedFilterQosPolicy (void) const
  {
    return this->children <TimeBasedFilterQosPolicy> ().count () == 1;
  }

  //
  // get_TimeBasedFilterQosPolicy
  //
  TimeBasedFilterQosPolicy DataReaderQos_Impl::get_TimeBasedFilterQosPolicy (void) const
  {
    return this->children <TimeBasedFilterQosPolicy> ().item ();
  }

  //
  // has_LatencyBudgetQosPolicy
  //
  bool DataReaderQos_Impl::has_LatencyBudgetQosPolicy (void) const
  {
    return this->children <LatencyBudgetQosPolicy> ().count () == 1;
  }

  //
  // get_LatencyBudgetQosPolicy
  //
  LatencyBudgetQosPolicy DataReaderQos_Impl::get_LatencyBudgetQosPolicy (void) const
  {
    return this->children <LatencyBudgetQosPolicy> ().item ();
  }

  //
  // has_OwnershipQosPolicy
  //
  bool DataReaderQos_Impl::has_OwnershipQosPolicy (void) const
  {
    return this->children <OwnershipQosPolicy> ().count () == 1;
  }

  //
  // get_OwnershipQosPolicy
  //
  OwnershipQosPolicy DataReaderQos_Impl::get_OwnershipQosPolicy (void) const
  {
    return this->children <OwnershipQosPolicy> ().item ();
  }

  //
  // has_LivelinessQosPolicy
  //
  bool DataReaderQos_Impl::has_LivelinessQosPolicy (void) const
  {
    return this->children <LivelinessQosPolicy> ().count () == 1;
  }

  //
  // get_LivelinessQosPolicy
  //
  LivelinessQosPolicy DataReaderQos_Impl::get_LivelinessQosPolicy (void) const
  {
    return this->children <LivelinessQosPolicy> ().item ();
  }

  //
  // has_ReliabilityQosPolicy
  //
  bool DataReaderQos_Impl::has_ReliabilityQosPolicy (void) const
  {
    return this->children <ReliabilityQosPolicy> ().count () == 1;
  }

  //
  // get_ReliabilityQosPolicy
  //
  ReliabilityQosPolicy DataReaderQos_Impl::get_ReliabilityQosPolicy (void) const
  {
    return this->children <ReliabilityQosPolicy> ().item ();
  }

  //
  // has_DestinationOrderQosPolicy
  //
  bool DataReaderQos_Impl::has_DestinationOrderQosPolicy (void) const
  {
    return this->children <DestinationOrderQosPolicy> ().count () == 1;
  }

  //
  // get_DestinationOrderQosPolicy
  //
  DestinationOrderQosPolicy DataReaderQos_Impl::get_DestinationOrderQosPolicy (void) const
  {
    return this->children <DestinationOrderQosPolicy> ().item ();
  }

  //
  // has_UserDataQosPolicy
  //
  bool DataReaderQos_Impl::has_UserDataQosPolicy (void) const
  {
    return this->children <UserDataQosPolicy> ().count () == 1;
  }

  //
  // get_UserDataQosPolicy
  //
  UserDataQosPolicy DataReaderQos_Impl::get_UserDataQosPolicy (void) const
  {
    return this->children <UserDataQosPolicy> ().item ();
  }

  //
  // has_HistoryQosPolicy
  //
  bool DataReaderQos_Impl::has_HistoryQosPolicy (void) const
  {
    return this->children <HistoryQosPolicy> ().count () == 1;
  }

  //
  // get_HistoryQosPolicy
  //
  HistoryQosPolicy DataReaderQos_Impl::get_HistoryQosPolicy (void) const
  {
    return this->children <HistoryQosPolicy> ().item ();
  }

  //
  // has_ResourceLimitsQosPolicy
  //
  bool DataReaderQos_Impl::has_ResourceLimitsQosPolicy (void) const
  {
    return this->children <ResourceLimitsQosPolicy> ().count () == 1;
  }

  //
  // get_ResourceLimitsQosPolicy
  //
  ResourceLimitsQosPolicy DataReaderQos_Impl::get_ResourceLimitsQosPolicy (void) const
  {
    return this->children <ResourceLimitsQosPolicy> ().item ();
  }

  //
  // has_ReaderDataLifecycleQosPolicy
  //
  bool DataReaderQos_Impl::has_ReaderDataLifecycleQosPolicy (void) const
  {
    return this->children <ReaderDataLifecycleQosPolicy> ().count () == 1;
  }

  //
  // get_ReaderDataLifecycleQosPolicy
  //
  ReaderDataLifecycleQosPolicy DataReaderQos_Impl::get_ReaderDataLifecycleQosPolicy (void) const
  {
    return this->children <ReaderDataLifecycleQosPolicy> ().item ();
  }

  //
  // has_TopicQosReference
  //
  bool DataReaderQos_Impl::has_TopicQosReference (void) const
  {
    return this->children <TopicQosReference> ().count () == 1;
  }

  //
  // get_TopicQosReference
  //
  TopicQosReference DataReaderQos_Impl::get_TopicQosReference (void) const
  {
    return this->children <TopicQosReference> ().item ();
  }
}

