// $Id$

#include "StdAfx.h"
#include "ConnectorToReceptacle.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorToReceptacle.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/RequiredRequestPortInstance.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorToReceptacle_Impl::metaname ("ConnectorToReceptacle");

  //
  // is_abstract
  //
  const bool ConnectorToReceptacle_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, RequiredRequestPortEnd_in src, ConnectorInstance_in dst)
  //
  ConnectorToReceptacle ConnectorToReceptacle_Impl::_create (const ComponentAssembly_in parent, RequiredRequestPortEnd_in src, ConnectorInstance_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ConnectorToReceptacle_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void ConnectorToReceptacle_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorToReceptacle (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ConnectorToReceptacle_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // RequiredRequestPortEnd
  //
  RequiredRequestPortEnd ConnectorToReceptacle_Impl::src_RequiredRequestPortEnd (void) const
  {
    return RequiredRequestPortEnd::_narrow (this->src ());
  }

  //
  // ConnectorInstance
  //
  ConnectorInstance ConnectorToReceptacle_Impl::dst_ConnectorInstance (void) const
  {
    return ConnectorInstance::_narrow (this->dst ());
  }
}

