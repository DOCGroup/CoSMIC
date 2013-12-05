// $Id$

#include "StdAfx.h"
#include "ComponentImplementation.h"

#if !defined (__GAME_INLINE__)
#include "ComponentImplementation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementation_Impl::metaname ("ComponentImplementation");

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ComponentImplementation_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // src_ImplementationDependsOn
  //
  size_t ComponentImplementation_Impl::src_ImplementationDependsOn (std::vector <ImplementationDependsOn> & items) const
  {
    return this->in_connections <ImplementationDependsOn> (items);
  }

  //
  // src_Implements
  //
  size_t ComponentImplementation_Impl::src_Implements (std::vector <Implements> & items) const
  {
    return this->in_connections <Implements> (items);
  }

  //
  // src_ImplementationCapability
  //
  size_t ComponentImplementation_Impl::src_ImplementationCapability (std::vector <ImplementationCapability> & items) const
  {
    return this->in_connections <ImplementationCapability> (items);
  }
}

