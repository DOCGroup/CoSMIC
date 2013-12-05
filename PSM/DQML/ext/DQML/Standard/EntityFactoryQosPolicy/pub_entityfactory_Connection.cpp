// $Id$

#include "StdAfx.h"
#include "pub_entityfactory_Connection.h"

#if !defined (__GAME_INLINE__)
#include "pub_entityfactory_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
#include "DQML/Standard/QoSPolicies/EntityFactoryQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string pub_entityfactory_Connection_Impl::metaname ("pub_entityfactory_Connection");

  //
  // _create (const DDSQoS_in)
  //
  pub_entityfactory_Connection pub_entityfactory_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < pub_entityfactory_Connection > (parent, pub_entityfactory_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void pub_entityfactory_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_pub_entityfactory_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // Publisher
  //
  Publisher pub_entityfactory_Connection_Impl::src_Publisher (void) const
  {
    return Publisher::_narrow (this->src ());
  }

  //
  // EntityFactoryQosPolicy
  //
  EntityFactoryQosPolicy pub_entityfactory_Connection_Impl::dst_EntityFactoryQosPolicy (void) const
  {
    return EntityFactoryQosPolicy::_narrow (this->dst ());
  }
}

