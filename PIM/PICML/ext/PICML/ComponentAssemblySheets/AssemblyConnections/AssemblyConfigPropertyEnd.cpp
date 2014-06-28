// $Id$

#include "StdAfx.h"
#include "AssemblyConfigPropertyEnd.h"

#if !defined (__GAME_INLINE__)
#include "AssemblyConfigPropertyEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyselectRequirement.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AssemblyConfigPropertyEnd_Impl::metaname ("AssemblyConfigPropertyEnd");

  //
  // src_AssemblyConfigProperty
  //
  size_t AssemblyConfigPropertyEnd_Impl::src_AssemblyConfigProperty (std::vector <AssemblyConfigProperty> & items) const
  {
    return this->in_connections <AssemblyConfigProperty> (items);
  }

  //
  // src_AssemblyselectRequirement
  //
  size_t AssemblyConfigPropertyEnd_Impl::src_AssemblyselectRequirement (std::vector <AssemblyselectRequirement> & items) const
  {
    return this->in_connections <AssemblyselectRequirement> (items);
  }
}

