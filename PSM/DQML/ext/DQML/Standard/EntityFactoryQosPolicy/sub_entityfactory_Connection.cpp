// $Id$

#include "StdAfx.h"
#include "sub_entityfactory_Connection.h"

#if !defined (__GAME_INLINE__)
#include "sub_entityfactory_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "DQML/Standard/DDSEntities/Subscriber.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string sub_entityfactory_Connection_Impl::metaname ("sub_entityfactory_Connection");

  //
  // _create (const DDSQoS_in, Subscriber_in src, EntityFactoryQosPolicy_in dst)
  //
  sub_entityfactory_Connection sub_entityfactory_Connection_Impl::_create (const DDSQoS_in parent, Subscriber_in src, EntityFactoryQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, sub_entityfactory_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void sub_entityfactory_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_sub_entityfactory_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS sub_entityfactory_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Subscriber
  //
  Subscriber sub_entityfactory_Connection_Impl::src_Subscriber (void) const
  {
    return Subscriber::_narrow (this->src ());
  }

  //
  // EntityFactoryQosPolicy
  //
  EntityFactoryQosPolicy sub_entityfactory_Connection_Impl::dst_EntityFactoryQosPolicy (void) const
  {
    return EntityFactoryQosPolicy::_narrow (this->dst ());
  }
}

