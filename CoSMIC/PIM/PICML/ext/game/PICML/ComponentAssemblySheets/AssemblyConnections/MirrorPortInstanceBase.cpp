// $Id$

#include "stdafx.h"
#include "MirrorPortInstanceBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortInstanceBase_Impl::metaname = "MirrorPortInstanceBase";

  //
  // MirrorPortInstanceBase_Impl
  //
  MirrorPortInstanceBase_Impl::MirrorPortInstanceBase_Impl (void)
  {
  }

  //
  // MirrorPortInstanceBase_Impl
  //
  MirrorPortInstanceBase_Impl::MirrorPortInstanceBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MirrorPortInstanceBase_Impl
  //
  MirrorPortInstanceBase_Impl::~MirrorPortInstanceBase_Impl (void)
  {
  }

  //
  // in_MirrorDelegate_connections
  //
  size_t MirrorPortInstanceBase_Impl::in_MirrorDelegate_connections (std::vector <MirrorDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

