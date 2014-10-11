// $Id$

#include "StdAfx.h"
#include "Domain.h"

#if !defined (__GAME_INLINE__)
#include "Domain.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/TargetElements/SharedResource.h"
#include "PICML/Domain/InterconnectConnection.h"
#include "PICML/Domain/BridgeConnection.h"
#include "PICML/Domain/Shares.h"
#include "PICML/Domain/Targets.h"
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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Domain (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Targets
  //
  Targets Domain_Impl::parent_Targets (void)
  {
    return Targets::_narrow (this->parent ());
  }

  //
  // get_ComplexPropertys
  //
  size_t Domain_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> Domain_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t Domain_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> Domain_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
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
  ::GAME::Mga::Collection_T <Node> Domain_Impl::get_Nodes (void) const
  {
    return this->children <Node> ();
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
  ::GAME::Mga::Collection_T <Interconnect> Domain_Impl::get_Interconnects (void) const
  {
    return this->children <Interconnect> ();
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
  ::GAME::Mga::Collection_T <Bridge> Domain_Impl::get_Bridges (void) const
  {
    return this->children <Bridge> ();
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
  ::GAME::Mga::Collection_T <SharedResource> Domain_Impl::get_SharedResources (void) const
  {
    return this->children <SharedResource> ();
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
  ::GAME::Mga::Collection_T <InterconnectConnection> Domain_Impl::get_InterconnectConnections (void) const
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
  ::GAME::Mga::Collection_T <BridgeConnection> Domain_Impl::get_BridgeConnections (void) const
  {
    return this->children <BridgeConnection> ();
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
  ::GAME::Mga::Collection_T <Shares> Domain_Impl::get_Sharess (void) const
  {
    return this->children <Shares> ();
  }
}

