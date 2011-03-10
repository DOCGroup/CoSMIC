// $Id$

#include "stdafx.h"
#include "ExtendPortEnd.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/Publish.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Consume.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendPortEnd_Impl::metaname = "ExtendPortEnd";

  //
  // ExtendPortEnd_Impl
  //
  ExtendPortEnd_Impl::ExtendPortEnd_Impl (void)
  {
  }

  //
  // ExtendPortEnd_Impl
  //
  ExtendPortEnd_Impl::ExtendPortEnd_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtendPortEnd_Impl
  //
  ExtendPortEnd_Impl::~ExtendPortEnd_Impl (void)
  {
  }

  //
  // in_Publish_connections
  //
  size_t ExtendPortEnd_Impl::in_Publish_connections (std::vector <Publish> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_Consume_connections
  //
  size_t ExtendPortEnd_Impl::in_Consume_connections (std::vector <Consume> & conns) const
  {
    return this->in_connections (conns);
  }
}

