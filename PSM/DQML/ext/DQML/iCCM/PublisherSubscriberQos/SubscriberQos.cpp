// $Id$

#include "StdAfx.h"
#include "SubscriberQos.h"

#if !defined (__GAME_INLINE__)
#include "SubscriberQos.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/PresentationQosPolicy.h"
#include "DQML/Standard/QoSPolicies/GroupDataQosPolicy.h"
#include "DQML/Standard/QoSPolicies/PartitionQosPolicy.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "DQML/iCCM/DomainQos/SubscriberConnection.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string SubscriberQos_Impl::metaname ("SubscriberQos");

  //
  // _create (const Participant_in)
  //
  SubscriberQos SubscriberQos_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create_object < SubscriberQos > (parent, SubscriberQos_Impl::metaname);
  }

  //
  // accept
  //
  void SubscriberQos_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_SubscriberQos (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // dst_SubscriberConnection
  //
  size_t SubscriberQos_Impl::dst_SubscriberConnection (std::vector <SubscriberConnection> & items) const
  {
    return this->in_connections <SubscriberConnection> (items);
  }

  //
  // has_PresentationQosPolicy
  //
  bool SubscriberQos_Impl::has_PresentationQosPolicy (void) const
  {
    return this->children <PresentationQosPolicy> ().count () == 1;
  }

  //
  // get_PresentationQosPolicy
  //
  PresentationQosPolicy SubscriberQos_Impl::get_PresentationQosPolicy (void) const
  {
    return this->children <PresentationQosPolicy> ().item ();
  }

  //
  // has_GroupDataQosPolicy
  //
  bool SubscriberQos_Impl::has_GroupDataQosPolicy (void) const
  {
    return this->children <GroupDataQosPolicy> ().count () == 1;
  }

  //
  // get_GroupDataQosPolicy
  //
  GroupDataQosPolicy SubscriberQos_Impl::get_GroupDataQosPolicy (void) const
  {
    return this->children <GroupDataQosPolicy> ().item ();
  }

  //
  // has_PartitionQosPolicy
  //
  bool SubscriberQos_Impl::has_PartitionQosPolicy (void) const
  {
    return this->children <PartitionQosPolicy> ().count () == 1;
  }

  //
  // get_PartitionQosPolicy
  //
  PartitionQosPolicy SubscriberQos_Impl::get_PartitionQosPolicy (void) const
  {
    return this->children <PartitionQosPolicy> ().item ();
  }

  //
  // has_EntityFactoryQosPolicy
  //
  bool SubscriberQos_Impl::has_EntityFactoryQosPolicy (void) const
  {
    return this->children <EntityFactoryQosPolicy> ().count () == 1;
  }

  //
  // get_EntityFactoryQosPolicy
  //
  EntityFactoryQosPolicy SubscriberQos_Impl::get_EntityFactoryQosPolicy (void) const
  {
    return this->children <EntityFactoryQosPolicy> ().item ();
  }
}

