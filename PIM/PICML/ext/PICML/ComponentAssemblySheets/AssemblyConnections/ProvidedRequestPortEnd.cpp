#include "StdAfx.h"
#include "ProvidedRequestPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "ProvidedRequestPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPortEnd_Impl::metaname ("ProvidedRequestPortEnd");

  //
  // is_abstract
  //
  const bool ProvidedRequestPortEnd_Impl::is_abstract = true;

  //
  // dst_of_FacetDelegate
  //
  size_t ProvidedRequestPortEnd_Impl::dst_of_FacetDelegate (std::vector <FacetDelegate> & items) const
  {
    return this->in_connections <FacetDelegate> (items);
  }

  //
  // dst_of_FacetDelegate
  //
  GAME::Mga::Collection_T <FacetDelegate> ProvidedRequestPortEnd_Impl::dst_of_FacetDelegate (void) const
  {
    return this->in_connections <FacetDelegate> ("dst");
  }

  //
  // dst_of_Invoke
  //
  size_t ProvidedRequestPortEnd_Impl::dst_of_Invoke (std::vector <Invoke> & items) const
  {
    return this->in_connections <Invoke> (items);
  }

  //
  // dst_of_Invoke
  //
  GAME::Mga::Collection_T <Invoke> ProvidedRequestPortEnd_Impl::dst_of_Invoke (void) const
  {
    return this->in_connections <Invoke> ("dst");
  }

  //
  // dst_of_ConnectorToFacet
  //
  size_t ProvidedRequestPortEnd_Impl::dst_of_ConnectorToFacet (std::vector <ConnectorToFacet> & items) const
  {
    return this->in_connections <ConnectorToFacet> (items);
  }

  //
  // dst_of_ConnectorToFacet
  //
  GAME::Mga::Collection_T <ConnectorToFacet> ProvidedRequestPortEnd_Impl::dst_of_ConnectorToFacet (void) const
  {
    return this->in_connections <ConnectorToFacet> ("dst");
  }
}

