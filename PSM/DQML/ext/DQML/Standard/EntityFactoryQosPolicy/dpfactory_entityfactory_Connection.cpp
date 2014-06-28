// $Id$

#include "StdAfx.h"
#include "dpfactory_entityfactory_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dpfactory_entityfactory_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DDSEntities/DomainParticipantFactory.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dpfactory_entityfactory_Connection_Impl::metaname ("dpfactory_entityfactory_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dpfactory_entityfactory_Connection dpfactory_entityfactory_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dpfactory_entityfactory_Connection > (parent, dpfactory_entityfactory_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dpfactory_entityfactory_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dpfactory_entityfactory_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dpfactory_entityfactory_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DomainParticipantFactory
  //
  DomainParticipantFactory dpfactory_entityfactory_Connection_Impl::src_DomainParticipantFactory (void) const
  {
    return DomainParticipantFactory::_narrow (this->src ());
  }

  //
  // EntityFactoryQosPolicy
  //
  EntityFactoryQosPolicy dpfactory_entityfactory_Connection_Impl::dst_EntityFactoryQosPolicy (void) const
  {
    return EntityFactoryQosPolicy::_narrow (this->dst ());
  }
}

