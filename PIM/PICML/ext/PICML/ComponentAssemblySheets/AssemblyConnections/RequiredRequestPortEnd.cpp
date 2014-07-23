// $Id$

#include "StdAfx.h"
#include "RequiredRequestPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "RequiredRequestPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPortEnd_Impl::metaname ("RequiredRequestPortEnd");

  //
  // src_ConnectorToReceptacle
  //
  size_t RequiredRequestPortEnd_Impl::src_ConnectorToReceptacle (std::vector <ConnectorToReceptacle> & items) const
  {
    return this->in_connections <ConnectorToReceptacle> (items);
  }

  //
  // src_Invoke
  //
  size_t RequiredRequestPortEnd_Impl::src_Invoke (std::vector <Invoke> & items) const
  {
    return this->in_connections <Invoke> (items);
  }

  //
  // dst_ReceptacleDelegate
  //
  size_t RequiredRequestPortEnd_Impl::dst_ReceptacleDelegate (std::vector <ReceptacleDelegate> & items) const
  {
    return this->in_connections <ReceptacleDelegate> (items);
  }
}

