#include "StdAfx.h"
#include "ConnectorToFacet.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorToFacet.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ProvidedRequestPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorToFacet_Impl::metaname ("ConnectorToFacet");

  //
  // is_abstract
  //
  const bool ConnectorToFacet_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, ConnectorInstance_in src, ProvidedRequestPortEnd_in dst)
  //
  ConnectorToFacet ConnectorToFacet_Impl::_create (const ComponentAssembly_in parent, ConnectorInstance_in src, ProvidedRequestPortEnd_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ConnectorToFacet_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void ConnectorToFacet_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorToFacet (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ConnectorToFacet_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // ConnectorInstance
  //
  ConnectorInstance ConnectorToFacet_Impl::src_ConnectorInstance (void) const
  {
    return ConnectorInstance::_narrow (this->src ());
  }

  //
  // ProvidedRequestPortEnd
  //
  ProvidedRequestPortEnd ConnectorToFacet_Impl::dst_ProvidedRequestPortEnd (void) const
  {
    return ProvidedRequestPortEnd::_narrow (this->dst ());
  }
}

