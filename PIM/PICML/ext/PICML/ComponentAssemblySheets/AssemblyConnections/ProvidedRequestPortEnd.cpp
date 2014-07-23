// $Id$

#include "StdAfx.h"
#include "ProvidedRequestPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "ProvidedRequestPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPortEnd_Impl::metaname ("ProvidedRequestPortEnd");

  //
  // dst_ConnectorToFacet
  //
  size_t ProvidedRequestPortEnd_Impl::dst_ConnectorToFacet (std::vector <ConnectorToFacet> & items) const
  {
    return this->in_connections <ConnectorToFacet> (items);
  }

  //
  // dst_Invoke
  //
  size_t ProvidedRequestPortEnd_Impl::dst_Invoke (std::vector <Invoke> & items) const
  {
    return this->in_connections <Invoke> (items);
  }

  //
  // dst_FacetDelegate
  //
  size_t ProvidedRequestPortEnd_Impl::dst_FacetDelegate (std::vector <FacetDelegate> & items) const
  {
    return this->in_connections <FacetDelegate> (items);
  }
}

