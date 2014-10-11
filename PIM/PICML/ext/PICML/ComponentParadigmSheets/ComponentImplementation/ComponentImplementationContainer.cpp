// $Id$

#include "StdAfx.h"
#include "ComponentImplementationContainer.h"

#if !defined (__GAME_INLINE__)
#include "ComponentImplementationContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementations.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/Common/ImplementationDependency.h"
#include "PICML/Common/Capability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/CriticalPath.h"
#include "PICML/PathDiagram/PathReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementationContainer_Impl::metaname ("ComponentImplementationContainer");

  //
  // _create (const ComponentImplementations_in)
  //
  ComponentImplementationContainer ComponentImplementationContainer_Impl::_create (const ComponentImplementations_in parent)
  {
    return ::GAME::Mga::create_root_object < ComponentImplementationContainer > (parent, ComponentImplementationContainer_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentImplementationContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentImplementationContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentImplementations
  //
  ComponentImplementations ComponentImplementationContainer_Impl::parent_ComponentImplementations (void)
  {
    return ComponentImplementations::_narrow (this->parent ());
  }

  //
  // has_ComponentRef
  //
  bool ComponentImplementationContainer_Impl::has_ComponentRef (void) const
  {
    return this->children <ComponentRef> ().count () == 1;
  }

  //
  // get_ComponentRef
  //
  ComponentRef ComponentImplementationContainer_Impl::get_ComponentRef (void) const
  {
    return this->children <ComponentRef> ().first ();
  }

  //
  // has_Implements
  //
  bool ComponentImplementationContainer_Impl::has_Implements (void) const
  {
    return this->children <Implements> ().count () == 1;
  }

  //
  // get_Implements
  //
  Implements ComponentImplementationContainer_Impl::get_Implements (void) const
  {
    return this->children <Implements> ().first ();
  }

  //
  // has_PathReference
  //
  bool ComponentImplementationContainer_Impl::has_PathReference (void) const
  {
    return this->children <PathReference> ().count () == 1;
  }

  //
  // get_PathReference
  //
  PathReference ComponentImplementationContainer_Impl::get_PathReference (void) const
  {
    return this->children <PathReference> ().first ();
  }

  //
  // get_ComponentAssemblys
  //
  size_t ComponentImplementationContainer_Impl::get_ComponentAssemblys (std::vector <ComponentAssembly> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentAssemblys
  //
  ::GAME::Mga::Collection_T <ComponentAssembly> ComponentImplementationContainer_Impl::get_ComponentAssemblys (void) const
  {
    return this->children <ComponentAssembly> ();
  }

  //
  // get_MonolithicImplementations
  //
  size_t ComponentImplementationContainer_Impl::get_MonolithicImplementations (std::vector <MonolithicImplementation> & items) const
  {
    return this->children (items);
  }

  //
  // get_MonolithicImplementations
  //
  ::GAME::Mga::Collection_T <MonolithicImplementation> ComponentImplementationContainer_Impl::get_MonolithicImplementations (void) const
  {
    return this->children <MonolithicImplementation> ();
  }

  //
  // get_ImplementationDependencys
  //
  size_t ComponentImplementationContainer_Impl::get_ImplementationDependencys (std::vector <ImplementationDependency> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationDependencys
  //
  ::GAME::Mga::Collection_T <ImplementationDependency> ComponentImplementationContainer_Impl::get_ImplementationDependencys (void) const
  {
    return this->children <ImplementationDependency> ();
  }

  //
  // get_Capabilitys
  //
  size_t ComponentImplementationContainer_Impl::get_Capabilitys (std::vector <Capability> & items) const
  {
    return this->children (items);
  }

  //
  // get_Capabilitys
  //
  ::GAME::Mga::Collection_T <Capability> ComponentImplementationContainer_Impl::get_Capabilitys (void) const
  {
    return this->children <Capability> ();
  }

  //
  // get_ImplementationDependsOns
  //
  size_t ComponentImplementationContainer_Impl::get_ImplementationDependsOns (std::vector <ImplementationDependsOn> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationDependsOns
  //
  ::GAME::Mga::Collection_T <ImplementationDependsOn> ComponentImplementationContainer_Impl::get_ImplementationDependsOns (void) const
  {
    return this->children <ImplementationDependsOn> ();
  }

  //
  // get_ImplementationCapabilitys
  //
  size_t ComponentImplementationContainer_Impl::get_ImplementationCapabilitys (std::vector <ImplementationCapability> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationCapabilitys
  //
  ::GAME::Mga::Collection_T <ImplementationCapability> ComponentImplementationContainer_Impl::get_ImplementationCapabilitys (void) const
  {
    return this->children <ImplementationCapability> ();
  }

  //
  // get_CriticalPaths
  //
  size_t ComponentImplementationContainer_Impl::get_CriticalPaths (std::vector <CriticalPath> & items) const
  {
    return this->children (items);
  }

  //
  // get_CriticalPaths
  //
  ::GAME::Mga::Collection_T <CriticalPath> ComponentImplementationContainer_Impl::get_CriticalPaths (void) const
  {
    return this->children <CriticalPath> ();
  }
}

