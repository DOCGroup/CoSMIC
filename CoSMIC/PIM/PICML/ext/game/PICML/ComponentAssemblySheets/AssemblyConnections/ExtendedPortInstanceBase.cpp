// $Id$

#include "stdafx.h"
#include "ExtendedPortInstanceBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortInstanceBase_Impl::metaname = "ExtendedPortInstanceBase";

  //
  // ExtendedPortInstanceBase_Impl
  //
  ExtendedPortInstanceBase_Impl::ExtendedPortInstanceBase_Impl (void)
  {
  }

  //
  // ExtendedPortInstanceBase_Impl
  //
  ExtendedPortInstanceBase_Impl::ExtendedPortInstanceBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtendedPortInstanceBase_Impl
  //
  ExtendedPortInstanceBase_Impl::~ExtendedPortInstanceBase_Impl (void)
  {
  }

  //
  // in_ExtendedDelegate_connections
  //
  size_t ExtendedPortInstanceBase_Impl::in_ExtendedDelegate_connections (std::vector <ExtendedDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

