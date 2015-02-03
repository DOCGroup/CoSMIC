// $Id$

#include "StdAfx.h"
#include "Consume.h"

#if !defined (__GAME_INLINE__)
#include "Consume.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortInstanceBase.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/MirrorPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortInstanceBase.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ExtendedPortInstance.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Consume_Impl::metaname ("Consume");

  //
  // is_abstract
  //
  const bool Consume_Impl::is_abstract (0);

  //
  // _create (const ComponentAssembly_in, ConnectorInstance_in src, ExtendPortEnd_in dst)
  //
  Consume Consume_Impl::_create (const ComponentAssembly_in parent, ConnectorInstance_in src, ExtendPortEnd_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, Consume_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void Consume_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Consume (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly Consume_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // ConnectorInstance
  //
  ConnectorInstance Consume_Impl::src_ConnectorInstance (void) const
  {
    return ConnectorInstance::_narrow (this->src ());
  }

  //
  // ExtendPortEnd
  //
  ExtendPortEnd Consume_Impl::dst_ExtendPortEnd (void) const
  {
    return ExtendPortEnd::_narrow (this->dst ());
  }
}

