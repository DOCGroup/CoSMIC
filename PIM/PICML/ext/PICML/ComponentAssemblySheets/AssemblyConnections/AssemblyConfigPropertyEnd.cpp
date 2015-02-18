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
  // is_abstract
  //
  const bool AssemblyConfigPropertyEnd_Impl::is_abstract = true;

  //
  // src_of_AssemblyConfigProperty
  //
  size_t AssemblyConfigPropertyEnd_Impl::src_of_AssemblyConfigProperty (std::vector <AssemblyConfigProperty> & items) const
  {
    return this->in_connections <AssemblyConfigProperty> (items);
  }

  //
  // src_of_AssemblyConfigProperty
  //
  GAME::Mga::Collection_T <AssemblyConfigProperty> AssemblyConfigPropertyEnd_Impl::src_of_AssemblyConfigProperty (void) const
  {
    return this->in_connections <AssemblyConfigProperty> ("src");
  }

  //
  // src_of_AssemblyselectRequirement
  //
  size_t AssemblyConfigPropertyEnd_Impl::src_of_AssemblyselectRequirement (std::vector <AssemblyselectRequirement> & items) const
  {
    return this->in_connections <AssemblyselectRequirement> (items);
  }

  //
  // src_of_AssemblyselectRequirement
  //
  GAME::Mga::Collection_T <AssemblyselectRequirement> AssemblyConfigPropertyEnd_Impl::src_of_AssemblyselectRequirement (void) const
  {
    return this->in_connections <AssemblyselectRequirement> ("src");
  }
}

