// $Id$

#include "StdAfx.h"
#include "PublisherQos.h"

#if !defined (__GAME_INLINE__)
#include "PublisherQos.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/PresentationQosPolicy.h"
#include "DQML/Standard/QoSPolicies/PartitionQosPolicy.h"
#include "DQML/Standard/QoSPolicies/GroupDataQosPolicy.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "DQML/iCCM/DomainQos/PublisherConnection.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string PublisherQos_Impl::metaname ("PublisherQos");

  //
  // is_abstract
  //
  const bool PublisherQos_Impl::is_abstract (0);

  //
  // _create (const Participant_in)
  //
  PublisherQos PublisherQos_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create < PublisherQos > (parent, PublisherQos_Impl::metaname);
  }

  //
  // accept
  //
  void PublisherQos_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PublisherQos (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Participant
  //
  Participant PublisherQos_Impl::parent_Participant (void)
  {
    return Participant::_narrow (this->parent ());
  }

  //
  // dst_of_PublisherConnection
  //
  size_t PublisherQos_Impl::dst_of_PublisherConnection (std::vector <PublisherConnection> & items) const
  {
    return this->in_connections <PublisherConnection> (items);
  }

  //
  // dst_of_PublisherConnection
  //
  GAME::Mga::Collection_T <PublisherConnection> PublisherQos_Impl::dst_of_PublisherConnection (void) const
  {
    return this->in_connections <PublisherConnection> ("dst");
  }

  //
  // has_PresentationQosPolicy
  //
  bool PublisherQos_Impl::has_PresentationQosPolicy (void) const
  {
    return this->children <PresentationQosPolicy> ().count () == 1;
  }

  //
  // get_PresentationQosPolicy
  //
  PresentationQosPolicy PublisherQos_Impl::get_PresentationQosPolicy (void) const
  {
    return this->children <PresentationQosPolicy> ().first ();
  }

  //
  // has_PartitionQosPolicy
  //
  bool PublisherQos_Impl::has_PartitionQosPolicy (void) const
  {
    return this->children <PartitionQosPolicy> ().count () == 1;
  }

  //
  // get_PartitionQosPolicy
  //
  PartitionQosPolicy PublisherQos_Impl::get_PartitionQosPolicy (void) const
  {
    return this->children <PartitionQosPolicy> ().first ();
  }

  //
  // has_GroupDataQosPolicy
  //
  bool PublisherQos_Impl::has_GroupDataQosPolicy (void) const
  {
    return this->children <GroupDataQosPolicy> ().count () == 1;
  }

  //
  // get_GroupDataQosPolicy
  //
  GroupDataQosPolicy PublisherQos_Impl::get_GroupDataQosPolicy (void) const
  {
    return this->children <GroupDataQosPolicy> ().first ();
  }

  //
  // has_EntityFactoryQosPolicy
  //
  bool PublisherQos_Impl::has_EntityFactoryQosPolicy (void) const
  {
    return this->children <EntityFactoryQosPolicy> ().count () == 1;
  }

  //
  // get_EntityFactoryQosPolicy
  //
  EntityFactoryQosPolicy PublisherQos_Impl::get_EntityFactoryQosPolicy (void) const
  {
    return this->children <EntityFactoryQosPolicy> ().first ();
  }
}

