// $Id$

#include "StdAfx.h"
#include "ConnectorInstance.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorImplementationType.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Publish.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Consume.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"
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
  // is_abstract
  //
  const bool ConnectorInstance_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in)
  //
  ConnectorInstance ConnectorInstance_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < ConnectorInstance > (parent, ConnectorInstance_Impl::metaname);
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
  // parent_ComponentAssembly
  //
  ComponentAssembly ConnectorInstance_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // src_of_Consume
  //
  size_t ConnectorInstance_Impl::src_of_Consume (std::vector <Consume> & items) const
  {
    return this->in_connections <Consume> (items);
  }

  //
  // src_of_Consume
  //
  GAME::Mga::Collection_T <Consume> ConnectorInstance_Impl::src_of_Consume (void) const
  {
    return this->in_connections <Consume> ("src");
  }

  //
  // src_of_ConnectorToFacet
  //
  size_t ConnectorInstance_Impl::src_of_ConnectorToFacet (std::vector <ConnectorToFacet> & items) const
  {
    return this->in_connections <ConnectorToFacet> (items);
  }

  //
  // src_of_ConnectorToFacet
  //
  GAME::Mga::Collection_T <ConnectorToFacet> ConnectorInstance_Impl::src_of_ConnectorToFacet (void) const
  {
    return this->in_connections <ConnectorToFacet> ("src");
  }

  //
  // dst_of_ConnectorToReceptacle
  //
  size_t ConnectorInstance_Impl::dst_of_ConnectorToReceptacle (std::vector <ConnectorToReceptacle> & items) const
  {
    return this->in_connections <ConnectorToReceptacle> (items);
  }

  //
  // dst_of_ConnectorToReceptacle
  //
  GAME::Mga::Collection_T <ConnectorToReceptacle> ConnectorInstance_Impl::dst_of_ConnectorToReceptacle (void) const
  {
    return this->in_connections <ConnectorToReceptacle> ("dst");
  }

  //
  // dst_of_Publish
  //
  size_t ConnectorInstance_Impl::dst_of_Publish (std::vector <Publish> & items) const
  {
    return this->in_connections <Publish> (items);
  }

  //
  // dst_of_Publish
  //
  GAME::Mga::Collection_T <Publish> ConnectorInstance_Impl::dst_of_Publish (void) const
  {
    return this->in_connections <Publish> ("dst");
  }

  //
  // has_ConnectorImplementationType
  //
  bool ConnectorInstance_Impl::has_ConnectorImplementationType (void) const
  {
    return this->children <ConnectorImplementationType> ().count () == 1;
  }

  //
  // get_ConnectorImplementationType
  //
  ConnectorImplementationType ConnectorInstance_Impl::get_ConnectorImplementationType (void) const
  {
    return this->children <ConnectorImplementationType> ().first ();
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
  ::GAME::Mga::Collection_T <AttributeInstance> ConnectorInstance_Impl::get_AttributeInstances (void) const
  {
    return this->children <AttributeInstance> ();
  }
}

