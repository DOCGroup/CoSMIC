// $Id$

#include "StdAfx.h"
#include "ConnectorInstance.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorImplementationType.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Publish.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Consume.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorInstance_Impl::metaname ("ConnectorInstance");

  //
  // _create (const ComponentAssembly_in)
  //
  ConnectorInstance ConnectorInstance_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ConnectorInstance > (parent, ConnectorInstance_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorInstance (this);
    else
      v->visit_Model (this);
  }

  //
  // src_Consume
  //
  size_t ConnectorInstance_Impl::src_Consume (std::vector <Consume> & items) const
  {
    return this->in_connections <Consume> (items);
  }

  //
  // src_ConnectorToFacet
  //
  size_t ConnectorInstance_Impl::src_ConnectorToFacet (std::vector <ConnectorToFacet> & items) const
  {
    return this->in_connections <ConnectorToFacet> (items);
  }

  //
  // dst_Publish
  //
  size_t ConnectorInstance_Impl::dst_Publish (std::vector <Publish> & items) const
  {
    return this->in_connections <Publish> (items);
  }

  //
  // dst_ConnectorToReceptacle
  //
  size_t ConnectorInstance_Impl::dst_ConnectorToReceptacle (std::vector <ConnectorToReceptacle> & items) const
  {
    return this->in_connections <ConnectorToReceptacle> (items);
  }

  //
  // get_ConnectorImplementationType
  //
  ConnectorImplementationType ConnectorInstance_Impl::get_ConnectorImplementationType (void) const
  {
    return this->children <ConnectorImplementationType> ().item ();
  }

  //
  // get_AttributeInstances
  //
  size_t ConnectorInstance_Impl::get_AttributeInstances (std::vector <AttributeInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeInstances
  //
  ::GAME::Mga::Iterator <AttributeInstance> ConnectorInstance_Impl::get_AttributeInstances (void) const
  {
    return this->children <AttributeInstance> ();
  }
}

