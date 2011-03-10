// $Id$

#include "stdafx.h"
#include "ComponentImplementation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementation_Impl::metaname = "ComponentImplementation";

  //
  // ComponentImplementation_Impl
  //
  ComponentImplementation_Impl::ComponentImplementation_Impl (void)
  {
  }

  //
  // ComponentImplementation_Impl
  //
  ComponentImplementation_Impl::ComponentImplementation_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentImplementation_Impl
  //
  ComponentImplementation_Impl::~ComponentImplementation_Impl (void)
  {
  }

  //
  // in_ImplementationDependsOn_connections
  //
  size_t ComponentImplementation_Impl::in_ImplementationDependsOn_connections (std::vector <ImplementationDependsOn> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_Implements_connections
  //
  size_t ComponentImplementation_Impl::in_Implements_connections (std::vector <Implements> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ImplementationCapability_connections
  //
  size_t ComponentImplementation_Impl::in_ImplementationCapability_connections (std::vector <ImplementationCapability> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ComponentImplementation_Impl::parent_ComponentImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentImplementationContainer> (this->object_.p);
  }
}

