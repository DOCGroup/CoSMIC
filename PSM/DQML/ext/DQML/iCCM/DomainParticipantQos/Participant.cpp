// $Id$

#include "StdAfx.h"
#include "Participant.h"

#if !defined (__GAME_INLINE__)
#include "Participant.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DomainQos/SubscriberConnection.h"
#include "DQML/iCCM/DomainQos/PublisherConnection.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "DQML/iCCM/DomainParticipantQos/WatchdogSchedulingQosPolicy.h"
#include "DQML/iCCM/DomainQos/Domain.h"
#include "DQML/iCCM/DomainParticipantQos/ListenerSchedulingQosPolicy.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/PublisherSubscriberQos/PublisherQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string Participant_Impl::metaname ("Participant");

  //
  // _create (const Domain_in)
  //
  Participant Participant_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < Participant > (parent, Participant_Impl::metaname);
  }

  //
  // accept
  //
  void Participant_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Participant (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Domain
  //
  Domain Participant_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // has_EntityFactoryQosPolicy
  //
  bool Participant_Impl::has_EntityFactoryQosPolicy (void) const
  {
    return this->children <EntityFactoryQosPolicy> ().count () == 1;
  }

  //
  // get_EntityFactoryQosPolicy
  //
  EntityFactoryQosPolicy Participant_Impl::get_EntityFactoryQosPolicy (void) const
  {
    return this->children <EntityFactoryQosPolicy> ().first ();
  }

  //
  // has_UserDataQosPolicy
  //
  bool Participant_Impl::has_UserDataQosPolicy (void) const
  {
    return this->children <UserDataQosPolicy> ().count () == 1;
  }

  //
  // get_UserDataQosPolicy
  //
  UserDataQosPolicy Participant_Impl::get_UserDataQosPolicy (void) const
  {
    return this->children <UserDataQosPolicy> ().first ();
  }

  //
  // has_WatchdogSchedulingQosPolicy
  //
  bool Participant_Impl::has_WatchdogSchedulingQosPolicy (void) const
  {
    return this->children <WatchdogSchedulingQosPolicy> ().count () == 1;
  }

  //
  // get_WatchdogSchedulingQosPolicy
  //
  WatchdogSchedulingQosPolicy Participant_Impl::get_WatchdogSchedulingQosPolicy (void) const
  {
    return this->children <WatchdogSchedulingQosPolicy> ().first ();
  }

  //
  // has_ListenerSchedulingQosPolicy
  //
  bool Participant_Impl::has_ListenerSchedulingQosPolicy (void) const
  {
    return this->children <ListenerSchedulingQosPolicy> ().count () == 1;
  }

  //
  // get_ListenerSchedulingQosPolicy
  //
  ListenerSchedulingQosPolicy Participant_Impl::get_ListenerSchedulingQosPolicy (void) const
  {
    return this->children <ListenerSchedulingQosPolicy> ().first ();
  }

  //
  // get_SubscriberConnections
  //
  size_t Participant_Impl::get_SubscriberConnections (std::vector <SubscriberConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_SubscriberConnections
  //
  ::GAME::Mga::Collection_T <SubscriberConnection> Participant_Impl::get_SubscriberConnections (void) const
  {
    return this->children <SubscriberConnection> ();
  }

  //
  // get_PublisherConnections
  //
  size_t Participant_Impl::get_PublisherConnections (std::vector <PublisherConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_PublisherConnections
  //
  ::GAME::Mga::Collection_T <PublisherConnection> Participant_Impl::get_PublisherConnections (void) const
  {
    return this->children <PublisherConnection> ();
  }

  //
  // get_DataWriterQoss
  //
  size_t Participant_Impl::get_DataWriterQoss (std::vector <DataWriterQos> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataWriterQoss
  //
  ::GAME::Mga::Collection_T <DataWriterQos> Participant_Impl::get_DataWriterQoss (void) const
  {
    return this->children <DataWriterQos> ();
  }

  //
  // get_SubscriberQoss
  //
  size_t Participant_Impl::get_SubscriberQoss (std::vector <SubscriberQos> & items) const
  {
    return this->children (items);
  }

  //
  // get_SubscriberQoss
  //
  ::GAME::Mga::Collection_T <SubscriberQos> Participant_Impl::get_SubscriberQoss (void) const
  {
    return this->children <SubscriberQos> ();
  }

  //
  // get_DataReaderQoss
  //
  size_t Participant_Impl::get_DataReaderQoss (std::vector <DataReaderQos> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataReaderQoss
  //
  ::GAME::Mga::Collection_T <DataReaderQos> Participant_Impl::get_DataReaderQoss (void) const
  {
    return this->children <DataReaderQos> ();
  }

  //
  // get_PublisherQoss
  //
  size_t Participant_Impl::get_PublisherQoss (std::vector <PublisherQos> & items) const
  {
    return this->children (items);
  }

  //
  // get_PublisherQoss
  //
  ::GAME::Mga::Collection_T <PublisherQos> Participant_Impl::get_PublisherQoss (void) const
  {
    return this->children <PublisherQos> ();
  }
}

