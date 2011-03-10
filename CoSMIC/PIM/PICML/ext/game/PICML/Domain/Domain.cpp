// $Id$

#include "stdafx.h"
#include "Domain.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Domain/BridgeConnection.h"
#include "PICML/Domain/InterconnectConnection.h"
#include "PICML/Domain/Shares.h"
#include "PICML/Common/Property.h"
#include "PICML/TargetElements/SharedResource.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/Domain/Targets.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Domain_Impl::metaname = "Domain";

  //
  // Domain_Impl
  //
  Domain_Impl::Domain_Impl (void)
  {
  }

  //
  // Domain_Impl
  //
  Domain_Impl::Domain_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Domain_Impl
  //
  Domain_Impl::~Domain_Impl (void)
  {
  }

  //
  // accept
  //
  void Domain_Impl::accept (Visitor * v)
  {
    v->visit_Domain (this);
  }

  //
  // _create
  //
  Domain Domain_Impl::_create (const Targets_in parent)
  {
    return ::GAME::Mga::create_root_object <Domain> (parent, Domain_Impl::metaname);
  }

  //
  // get_BridgeConnections
  //
  size_t Domain_Impl::get_BridgeConnections (std::vector <BridgeConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_InterconnectConnections
  //
  size_t Domain_Impl::get_InterconnectConnections (std::vector <InterconnectConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_Sharess
  //
  size_t Domain_Impl::get_Sharess (std::vector <Shares> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t Domain_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_SharedResources
  //
  size_t Domain_Impl::get_SharedResources (std::vector <SharedResource> & items) const
  {
    return this->children (items);
  }

  //
  // get_Bridges
  //
  size_t Domain_Impl::get_Bridges (std::vector <Bridge> & items) const
  {
    return this->children (items);
  }

  //
  // get_Nodes
  //
  size_t Domain_Impl::get_Nodes (std::vector <Node> & items) const
  {
    return this->children (items);
  }

  //
  // get_Interconnects
  //
  size_t Domain_Impl::get_Interconnects (std::vector <Interconnect> & items) const
  {
    return this->children (items);
  }

  //
  // parent_Targets
  //
  Targets Domain_Impl::parent_Targets (void) const
  {
    return ::GAME::Mga::get_parent <Targets> (this->object_.p);
  }
}

