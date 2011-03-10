// $Id$

#include "stdafx.h"
#include "ExternalPortEnd.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalPortEnd_Impl::metaname = "ExternalPortEnd";

  //
  // ExternalPortEnd_Impl
  //
  ExternalPortEnd_Impl::ExternalPortEnd_Impl (void)
  {
  }

  //
  // ExternalPortEnd_Impl
  //
  ExternalPortEnd_Impl::ExternalPortEnd_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExternalPortEnd_Impl
  //
  ExternalPortEnd_Impl::~ExternalPortEnd_Impl (void)
  {
  }

  //
  // in_ExternalDelegate_connections
  //
  size_t ExternalPortEnd_Impl::in_ExternalDelegate_connections (std::vector <ExternalDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

