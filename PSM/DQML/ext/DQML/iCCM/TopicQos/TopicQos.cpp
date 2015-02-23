// $Id$

#include "StdAfx.h"
#include "TopicQos.h"

#if !defined (__GAME_INLINE__)
#include "TopicQos.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/LivelinessQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ResourceLimitsQosPolicy.h"
#include "DQML/Standard/QoSPolicies/HistoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DestinationOrderQosPolicy.h"
#include "DQML/Standard/QoSPolicies/ReliabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LatencyBudgetQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DurabilityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/LifespanQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TransportPriorityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/DurabilityServiceQosPolicy.h"
#include "DQML/Standard/QoSPolicies/TopicDataQosPolicy.h"
#include "DQML/iCCM/TopicQos/TopicQosFolder.h"
#include "DQML/iCCM/TopicQos/TopicQosReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string TopicQos_Impl::metaname ("TopicQos");

  //
  // is_abstract
  //
  const bool TopicQos_Impl::is_abstract = false;

  //
  // _create (const TopicQosFolder_in)
  //
  TopicQos TopicQos_Impl::_create (const TopicQosFolder_in parent)
  {
    return ::GAME::Mga::create < TopicQos > (parent, TopicQos_Impl::metaname);
  }

  //
  // accept
  //
  void TopicQos_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TopicQos (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_TopicQosFolder
  //
  TopicQosFolder TopicQos_Impl::parent_TopicQosFolder (void)
  {
    return TopicQosFolder::_narrow (this->parent ());
  }

  //
  // has_LivelinessQosPolicy
  //
  bool TopicQos_Impl::has_LivelinessQosPolicy (void) const
  {
    return this->children <LivelinessQosPolicy> ().count () == 1;
  }

  //
  // get_LivelinessQosPolicy
  //
  LivelinessQosPolicy TopicQos_Impl::get_LivelinessQosPolicy (void) const
  {
    return this->children <LivelinessQosPolicy> ().first ();
  }

  //
  // has_ResourceLimitsQosPolicy
  //
  bool TopicQos_Impl::has_ResourceLimitsQosPolicy (void) const
  {
    return this->children <ResourceLimitsQosPolicy> ().count () == 1;
  }

  //
  // get_ResourceLimitsQosPolicy
  //
  ResourceLimitsQosPolicy TopicQos_Impl::get_ResourceLimitsQosPolicy (void) const
  {
    return this->children <ResourceLimitsQosPolicy> ().first ();
  }

  //
  // has_HistoryQosPolicy
  //
  bool TopicQos_Impl::has_HistoryQosPolicy (void) const
  {
    return this->children <HistoryQosPolicy> ().count () == 1;
  }

  //
  // get_HistoryQosPolicy
  //
  HistoryQosPolicy TopicQos_Impl::get_HistoryQosPolicy (void) const
  {
    return this->children <HistoryQosPolicy> ().first ();
  }

  //
  // has_DestinationOrderQosPolicy
  //
  bool TopicQos_Impl::has_DestinationOrderQosPolicy (void) const
  {
    return this->children <DestinationOrderQosPolicy> ().count () == 1;
  }

  //
  // get_DestinationOrderQosPolicy
  //
  DestinationOrderQosPolicy TopicQos_Impl::get_DestinationOrderQosPolicy (void) const
  {
    return this->children <DestinationOrderQosPolicy> ().first ();
  }

  //
  // has_ReliabilityQosPolicy
  //
  bool TopicQos_Impl::has_ReliabilityQosPolicy (void) const
  {
    return this->children <ReliabilityQosPolicy> ().count () == 1;
  }

  //
  // get_ReliabilityQosPolicy
  //
  ReliabilityQosPolicy TopicQos_Impl::get_ReliabilityQosPolicy (void) const
  {
    return this->children <ReliabilityQosPolicy> ().first ();
  }

  //
  // has_OwnershipQosPolicy
  //
  bool TopicQos_Impl::has_OwnershipQosPolicy (void) const
  {
    return this->children <OwnershipQosPolicy> ().count () == 1;
  }

  //
  // get_OwnershipQosPolicy
  //
  OwnershipQosPolicy TopicQos_Impl::get_OwnershipQosPolicy (void) const
  {
    return this->children <OwnershipQosPolicy> ().first ();
  }

  //
  // has_LatencyBudgetQosPolicy
  //
  bool TopicQos_Impl::has_LatencyBudgetQosPolicy (void) const
  {
    return this->children <LatencyBudgetQosPolicy> ().count () == 1;
  }

  //
  // get_LatencyBudgetQosPolicy
  //
  LatencyBudgetQosPolicy TopicQos_Impl::get_LatencyBudgetQosPolicy (void) const
  {
    return this->children <LatencyBudgetQosPolicy> ().first ();
  }

  //
  // has_DeadlineQosPolicy
  //
  bool TopicQos_Impl::has_DeadlineQosPolicy (void) const
  {
    return this->children <DeadlineQosPolicy> ().count () == 1;
  }

  //
  // get_DeadlineQosPolicy
  //
  DeadlineQosPolicy TopicQos_Impl::get_DeadlineQosPolicy (void) const
  {
    return this->children <DeadlineQosPolicy> ().first ();
  }

  //
  // has_DurabilityQosPolicy
  //
  bool TopicQos_Impl::has_DurabilityQosPolicy (void) const
  {
    return this->children <DurabilityQosPolicy> ().count () == 1;
  }

  //
  // get_DurabilityQosPolicy
  //
  DurabilityQosPolicy TopicQos_Impl::get_DurabilityQosPolicy (void) const
  {
    return this->children <DurabilityQosPolicy> ().first ();
  }

  //
  // has_LifespanQosPolicy
  //
  bool TopicQos_Impl::has_LifespanQosPolicy (void) const
  {
    return this->children <LifespanQosPolicy> ().count () == 1;
  }

  //
  // get_LifespanQosPolicy
  //
  LifespanQosPolicy TopicQos_Impl::get_LifespanQosPolicy (void) const
  {
    return this->children <LifespanQosPolicy> ().first ();
  }

  //
  // has_TransportPriorityQosPolicy
  //
  bool TopicQos_Impl::has_TransportPriorityQosPolicy (void) const
  {
    return this->children <TransportPriorityQosPolicy> ().count () == 1;
  }

  //
  // get_TransportPriorityQosPolicy
  //
  TransportPriorityQosPolicy TopicQos_Impl::get_TransportPriorityQosPolicy (void) const
  {
    return this->children <TransportPriorityQosPolicy> ().first ();
  }

  //
  // has_DurabilityServiceQosPolicy
  //
  bool TopicQos_Impl::has_DurabilityServiceQosPolicy (void) const
  {
    return this->children <DurabilityServiceQosPolicy> ().count () == 1;
  }

  //
  // get_DurabilityServiceQosPolicy
  //
  DurabilityServiceQosPolicy TopicQos_Impl::get_DurabilityServiceQosPolicy (void) const
  {
    return this->children <DurabilityServiceQosPolicy> ().first ();
  }

  //
  // has_TopicDataQosPolicy
  //
  bool TopicQos_Impl::has_TopicDataQosPolicy (void) const
  {
    return this->children <TopicDataQosPolicy> ().count () == 1;
  }

  //
  // get_TopicDataQosPolicy
  //
  TopicDataQosPolicy TopicQos_Impl::get_TopicDataQosPolicy (void) const
  {
    return this->children <TopicDataQosPolicy> ().first ();
  }
}

