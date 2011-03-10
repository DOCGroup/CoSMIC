// $Id$

#include "stdafx.h"
#include "ProvidedRequestPortEnd.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPortEnd_Impl::metaname = "ProvidedRequestPortEnd";

  //
  // ProvidedRequestPortEnd_Impl
  //
  ProvidedRequestPortEnd_Impl::ProvidedRequestPortEnd_Impl (void)
  {
  }

  //
  // ProvidedRequestPortEnd_Impl
  //
  ProvidedRequestPortEnd_Impl::ProvidedRequestPortEnd_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ProvidedRequestPortEnd_Impl
  //
  ProvidedRequestPortEnd_Impl::~ProvidedRequestPortEnd_Impl (void)
  {
  }

  //
  // in_FacetDelegate_connections
  //
  size_t ProvidedRequestPortEnd_Impl::in_FacetDelegate_connections (std::vector <FacetDelegate> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_Invoke_connections
  //
  size_t ProvidedRequestPortEnd_Impl::in_Invoke_connections (std::vector <Invoke> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ConnectorToFacet_connections
  //
  size_t ProvidedRequestPortEnd_Impl::in_ConnectorToFacet_connections (std::vector <ConnectorToFacet> & conns) const
  {
    return this->in_connections (conns);
  }
}

