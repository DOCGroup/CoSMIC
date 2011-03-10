// $Id$

#include "stdafx.h"
#include "ComponentImplementationContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/CriticalPath.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/PathDiagram/PathReference.h"
#include "PICML/Common/Capability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/Common/ImplementationDependency.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementations.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementationContainer_Impl::metaname = "ComponentImplementationContainer";

  //
  // ComponentImplementationContainer_Impl
  //
  ComponentImplementationContainer_Impl::ComponentImplementationContainer_Impl (void)
  {
  }

  //
  // ComponentImplementationContainer_Impl
  //
  ComponentImplementationContainer_Impl::ComponentImplementationContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentImplementationContainer_Impl
  //
  ComponentImplementationContainer_Impl::~ComponentImplementationContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentImplementationContainer_Impl::accept (Visitor * v)
  {
    v->visit_ComponentImplementationContainer (this);
  }

  //
  // _create
  //
  ComponentImplementationContainer ComponentImplementationContainer_Impl::_create (const ComponentImplementations_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentImplementationContainer> (parent, ComponentImplementationContainer_Impl::metaname);
  }

  //
  // get_CriticalPaths
  //
  size_t ComponentImplementationContainer_Impl::get_CriticalPaths (std::vector <CriticalPath> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentImplementations
  //
  size_t ComponentImplementationContainer_Impl::get_ComponentImplementations (std::vector <ComponentImplementation> & items) const
  {
    return this->children (items);
  }

  //
  // get_PathReference
  //
  PathReference ComponentImplementationContainer_Impl::get_PathReference (void) const
  {
    // Get the collection of children.
    std::vector <PathReference> items;
    this->children (items);

    return !items.empty () ? items.front () : PathReference ();
  }

  //
  // get_Capabilitys
  //
  size_t ComponentImplementationContainer_Impl::get_Capabilitys (std::vector <Capability> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationCapabilitys
  //
  size_t ComponentImplementationContainer_Impl::get_ImplementationCapabilitys (std::vector <ImplementationCapability> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationDependencys
  //
  size_t ComponentImplementationContainer_Impl::get_ImplementationDependencys (std::vector <ImplementationDependency> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRef
  //
  ComponentRef ComponentImplementationContainer_Impl::get_ComponentRef (void) const
  {
    // Get the collection of children.
    std::vector <ComponentRef> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentRef ();
  }

  //
  // get_Implements
  //
  Implements ComponentImplementationContainer_Impl::get_Implements (void) const
  {
    // Get the collection of children.
    std::vector <Implements> items;
    this->children (items);

    return !items.empty () ? items.front () : Implements ();
  }

  //
  // get_ImplementationDependsOns
  //
  size_t ComponentImplementationContainer_Impl::get_ImplementationDependsOns (std::vector <ImplementationDependsOn> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ComponentImplementations
  //
  ComponentImplementations ComponentImplementationContainer_Impl::parent_ComponentImplementations (void) const
  {
    return ::GAME::Mga::get_parent <ComponentImplementations> (this->object_.p);
  }
}

