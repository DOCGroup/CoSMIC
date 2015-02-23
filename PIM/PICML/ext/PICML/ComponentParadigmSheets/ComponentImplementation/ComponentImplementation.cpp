// $Id$

#include "StdAfx.h"
#include "ComponentImplementation.h"

#if !defined (__GAME_INLINE__)
#include "ComponentImplementation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementation_Impl::metaname ("ComponentImplementation");

  //
  // is_abstract
  //
  const bool ComponentImplementation_Impl::is_abstract = true;

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ComponentImplementation_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // src_of_Implements
  //
  size_t ComponentImplementation_Impl::src_of_Implements (std::vector <Implements> & items) const
  {
    return this->in_connections <Implements> (items);
  }

  //
  // has_src_of_Implements
  //
  bool ComponentImplementation_Impl::has_src_of_Implements (void) const
  {
    return this->in_connections <Implements> ("src").count () == 1;
  }

  //
  // src_of_Implements
  //
  Implements ComponentImplementation_Impl::src_of_Implements (void) const
  {
    return this->in_connections <Implements> ("src").first ();
  }

  //
  // src_of_ImplementationDependsOn
  //
  size_t ComponentImplementation_Impl::src_of_ImplementationDependsOn (std::vector <ImplementationDependsOn> & items) const
  {
    return this->in_connections <ImplementationDependsOn> (items);
  }

  //
  // src_of_ImplementationDependsOn
  //
  GAME::Mga::Collection_T <ImplementationDependsOn> ComponentImplementation_Impl::src_of_ImplementationDependsOn (void) const
  {
    return this->in_connections <ImplementationDependsOn> ("src");
  }

  //
  // src_of_ImplementationCapability
  //
  size_t ComponentImplementation_Impl::src_of_ImplementationCapability (std::vector <ImplementationCapability> & items) const
  {
    return this->in_connections <ImplementationCapability> (items);
  }

  //
  // has_src_of_ImplementationCapability
  //
  bool ComponentImplementation_Impl::has_src_of_ImplementationCapability (void) const
  {
    return this->in_connections <ImplementationCapability> ("src").count () == 1;
  }

  //
  // src_of_ImplementationCapability
  //
  ImplementationCapability ComponentImplementation_Impl::src_of_ImplementationCapability (void) const
  {
    return this->in_connections <ImplementationCapability> ("src").first ();
  }
}

