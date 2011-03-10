// $Id$

#include "stdafx.h"
#include "RequiredRequestPortEnd.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPortEnd_Impl::metaname = "RequiredRequestPortEnd";

  //
  // RequiredRequestPortEnd_Impl
  //
  RequiredRequestPortEnd_Impl::RequiredRequestPortEnd_Impl (void)
  {
  }

  //
  // RequiredRequestPortEnd_Impl
  //
  RequiredRequestPortEnd_Impl::RequiredRequestPortEnd_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequiredRequestPortEnd_Impl
  //
  RequiredRequestPortEnd_Impl::~RequiredRequestPortEnd_Impl (void)
  {
  }

  //
  // in_ConnectorToReceptacle_connections
  //
  size_t RequiredRequestPortEnd_Impl::in_ConnectorToReceptacle_connections (std::vector <ConnectorToReceptacle> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_Invoke_connections
  //
  size_t RequiredRequestPortEnd_Impl::in_Invoke_connections (std::vector <Invoke> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ReceptacleDelegate_connections
  //
  size_t RequiredRequestPortEnd_Impl::in_ReceptacleDelegate_connections (std::vector <ReceptacleDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

