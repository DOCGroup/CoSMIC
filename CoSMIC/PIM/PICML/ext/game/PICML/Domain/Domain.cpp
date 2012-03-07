// $Id$

#include "StdAfx.h"
#include "Domain.h"

#if !defined (__GAME_INLINE__)
#include "Domain.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Targets.h"
#include "PICML/Domain/Shares.h"
#include "PICML/Domain/InterconnectConnection.h"
#include "PICML/Domain/BridgeConnection.h"
#include "PICML/Common/Property.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/SharedResource.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Domain_Impl::metaname ("Domain");

  //
  // _create (const Targets_in)
  //
  Domain Domain_Impl::_create (const Targets_in parent)
  {
    return ::GAME::Mga::create_root_object < Domain > (parent, Domain_Impl::metaname);
  }

  //
  // accept
  //
  void Domain_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Domain (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_Sharess
  //
  size_t Domain_Impl::get_Sharess (std::vector <Shares> & items) const
  {
    return this->children (items);
  }

  //
  // get_Sharess
  //
  ::GAME::Mga::Iterator <Shares> Domain_Impl::get_Sharess (void) const
  {
    return this->children <Shares> ();
  }

  //
  // get_InterconnectConnections
  //
  size_t Domain_Impl::get_InterconnectConnections (std::vector <InterconnectConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_InterconnectConnections
  //
  ::GAME::Mga::Iterator <InterconnectConnection> Domain_Impl::get_InterconnectConnections (void) const
  {
    return this->children <InterconnectConnection> ();
  }

  //
  // get_BridgeConnections
  //
  size_t Domain_Impl::get_BridgeConnections (std::vector <BridgeConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_BridgeConnections
  //
  ::GAME::Mga::Iterator <BridgeConnection> Domain_Impl::get_BridgeConnections (void) const
  {
    return this->children <BridgeConnection> ();
  }

  //
  // get_Propertys
  //
  size_t Domain_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> Domain_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }

  //
  // get_Bridges
  //
  size_t Domain_Impl::get_Bridges (std::vector <Bridge> & items) const
  {
    return this->children (items);
  }

  //
  // get_Bridges
  //
  ::GAME::Mga::Iterator <Bridge> Domain_Impl::get_Bridges (void) const
  {
    return this->children <Bridge> ();
  }

  //
  // get_Interconnects
  //
  size_t Domain_Impl::get_Interconnects (std::vector <Interconnect> & items) const
  {
    return this->children (items);
  }

  //
  // get_Interconnects
  //
  ::GAME::Mga::Iterator <Interconnect> Domain_Impl::get_Interconnects (void) const
  {
    return this->children <Interconnect> ();
  }

  //
  // get_Nodes
  //
  size_t Domain_Impl::get_Nodes (std::vector <Node> & items) const
  {
    return this->children (items);
  }

  //
  // get_Nodes
  //
  ::GAME::Mga::Iterator <Node> Domain_Impl::get_Nodes (void) const
  {
    return this->children <Node> ();
  }

  //
  // get_SharedResources
  //
  size_t Domain_Impl::get_SharedResources (std::vector <SharedResource> & items) const
  {
    return this->children (items);
  }

  //
  // get_SharedResources
  //
  ::GAME::Mga::Iterator <SharedResource> Domain_Impl::get_SharedResources (void) const
  {
    return this->children <SharedResource> ();
  }
}

