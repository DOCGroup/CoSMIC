// $Id$

#include "StdAfx.h"
#include "RequiredRequestPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "RequiredRequestPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPortEnd_Impl::metaname ("RequiredRequestPortEnd");

  //
  // is_abstract
  //
  const bool RequiredRequestPortEnd_Impl::is_abstract (1);

  //
  // src_of_Invoke
  //
  size_t RequiredRequestPortEnd_Impl::src_of_Invoke (std::vector <Invoke> & items) const
  {
    return this->in_connections <Invoke> (items);
  }

  //
  // src_of_Invoke
  //
  GAME::Mga::Collection_T <Invoke> RequiredRequestPortEnd_Impl::src_of_Invoke (void) const
  {
    return this->in_connections <Invoke> ("src");
  }

  //
  // src_of_ConnectorToReceptacle
  //
  size_t RequiredRequestPortEnd_Impl::src_of_ConnectorToReceptacle (std::vector <ConnectorToReceptacle> & items) const
  {
    return this->in_connections <ConnectorToReceptacle> (items);
  }

  //
  // src_of_ConnectorToReceptacle
  //
  GAME::Mga::Collection_T <ConnectorToReceptacle> RequiredRequestPortEnd_Impl::src_of_ConnectorToReceptacle (void) const
  {
    return this->in_connections <ConnectorToReceptacle> ("src");
  }

  //
  // dst_of_ReceptacleDelegate
  //
  size_t RequiredRequestPortEnd_Impl::dst_of_ReceptacleDelegate (std::vector <ReceptacleDelegate> & items) const
  {
    return this->in_connections <ReceptacleDelegate> (items);
  }

  //
  // dst_of_ReceptacleDelegate
  //
  GAME::Mga::Collection_T <ReceptacleDelegate> RequiredRequestPortEnd_Impl::dst_of_ReceptacleDelegate (void) const
  {
    return this->in_connections <ReceptacleDelegate> ("dst");
  }
}

