// $Id$

#include "stdafx.h"
#include "AssemblyConfigPropertyEnd.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyselectRequirement.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AssemblyConfigPropertyEnd_Impl::metaname = "AssemblyConfigPropertyEnd";

  //
  // AssemblyConfigPropertyEnd_Impl
  //
  AssemblyConfigPropertyEnd_Impl::AssemblyConfigPropertyEnd_Impl (void)
  {
  }

  //
  // AssemblyConfigPropertyEnd_Impl
  //
  AssemblyConfigPropertyEnd_Impl::AssemblyConfigPropertyEnd_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AssemblyConfigPropertyEnd_Impl
  //
  AssemblyConfigPropertyEnd_Impl::~AssemblyConfigPropertyEnd_Impl (void)
  {
  }

  //
  // in_AssemblyselectRequirement_connections
  //
  size_t AssemblyConfigPropertyEnd_Impl::in_AssemblyselectRequirement_connections (std::vector <AssemblyselectRequirement> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_AssemblyConfigProperty_connections
  //
  size_t AssemblyConfigPropertyEnd_Impl::in_AssemblyConfigProperty_connections (std::vector <AssemblyConfigProperty> & conns) const
  {
    return this->in_connections (conns);
  }
}

