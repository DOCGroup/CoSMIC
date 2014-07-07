// $Id$

#include "StdAfx.h"
#include "EntityFactoryQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "EntityFactoryQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dp_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dpfactory_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/sub_entityfactory_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/pub_entityfactory_Connection.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "DQML/iCCM/PublisherSubscriberQos/PublisherQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string EntityFactoryQosPolicy_Impl::metaname ("EntityFactoryQosPolicy");

  //
  // _create (const SubscriberQos_in)
  //
  EntityFactoryQosPolicy EntityFactoryQosPolicy_Impl::_create (const SubscriberQos_in parent)
  {
    return ::GAME::Mga::create_object < EntityFactoryQosPolicy > (parent, EntityFactoryQosPolicy_Impl::metaname);
  }

  //
  // _create (const Participant_in)
  //
  EntityFactoryQosPolicy EntityFactoryQosPolicy_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create_object < EntityFactoryQosPolicy > (parent, EntityFactoryQosPolicy_Impl::metaname);
  }

  //
  // _create (const PublisherQos_in)
  //
  EntityFactoryQosPolicy EntityFactoryQosPolicy_Impl::_create (const PublisherQos_in parent)
  {
    return ::GAME::Mga::create_object < EntityFactoryQosPolicy > (parent, EntityFactoryQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  EntityFactoryQosPolicy EntityFactoryQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < EntityFactoryQosPolicy > (parent, EntityFactoryQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void EntityFactoryQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_EntityFactoryQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_SubscriberQos
  //
  SubscriberQos EntityFactoryQosPolicy_Impl::parent_SubscriberQos (void)
  {
    return SubscriberQos::_narrow (this->parent ());
  }

  //
  // parent_Participant
  //
  Participant EntityFactoryQosPolicy_Impl::parent_Participant (void)
  {
    return Participant::_narrow (this->parent ());
  }

  //
  // parent_PublisherQos
  //
  PublisherQos EntityFactoryQosPolicy_Impl::parent_PublisherQos (void)
  {
    return PublisherQos::_narrow (this->parent ());
  }

  //
  // dst_dp_entityfactory_Connection
  //
  size_t EntityFactoryQosPolicy_Impl::dst_dp_entityfactory_Connection (std::vector <dp_entityfactory_Connection> & items) const
  {
    return this->in_connections <dp_entityfactory_Connection> (items);
  }

  //
  // dst_dpfactory_entityfactory_Connection
  //
  size_t EntityFactoryQosPolicy_Impl::dst_dpfactory_entityfactory_Connection (std::vector <dpfactory_entityfactory_Connection> & items) const
  {
    return this->in_connections <dpfactory_entityfactory_Connection> (items);
  }

  //
  // dst_sub_entityfactory_Connection
  //
  size_t EntityFactoryQosPolicy_Impl::dst_sub_entityfactory_Connection (std::vector <sub_entityfactory_Connection> & items) const
  {
    return this->in_connections <sub_entityfactory_Connection> (items);
  }

  //
  // dst_pub_entityfactory_Connection
  //
  size_t EntityFactoryQosPolicy_Impl::dst_pub_entityfactory_Connection (std::vector <pub_entityfactory_Connection> & items) const
  {
    return this->in_connections <pub_entityfactory_Connection> (items);
  }
}

