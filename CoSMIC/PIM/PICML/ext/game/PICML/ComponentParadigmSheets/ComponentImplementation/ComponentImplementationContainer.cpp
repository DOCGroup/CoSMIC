// $Id$

#include "StdAfx.h"
#include "ComponentImplementationContainer.h"

#if !defined (__GAME_INLINE__)
#include "ComponentImplementationContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementations.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/CriticalPath.h"
#include "PICML/Common/ImplementationDependency.h"
#include "PICML/Common/Capability.h"
#include "PICML/PathDiagram/PathReference.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
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
  // _create (const ImplementationContainer_in)
  //
  ComponentImplementationContainer ComponentImplementationContainer_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentImplementationContainer > (parent, ComponentImplementationContainer_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentImplementationContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentImplementationContainer (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
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
    return this->children <ComponentRef> ().item ();
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
    return this->children <Implements> ().item ();
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
    return this->children <PathReference> ().item ();
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
  ::GAME::Mga::Iterator <ImplementationCapability> ComponentImplementationContainer_Impl::get_ImplementationCapabilitys (void) const
  {
    return this->children <ImplementationCapability> ();
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
  ::GAME::Mga::Iterator <ImplementationDependsOn> ComponentImplementationContainer_Impl::get_ImplementationDependsOns (void) const
  {
    return this->children <ImplementationDependsOn> ();
  }

  //
  // get_ComponentImplementations
  //
  size_t ComponentImplementationContainer_Impl::get_ComponentImplementations (std::vector <ComponentImplementation> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentImplementations
  //
  ::GAME::Mga::Iterator <ComponentImplementation> ComponentImplementationContainer_Impl::get_ComponentImplementations (void) const
  {
    return this->children <ComponentImplementation> ();
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
  ::GAME::Mga::Iterator <CriticalPath> ComponentImplementationContainer_Impl::get_CriticalPaths (void) const
  {
    return this->children <CriticalPath> ();
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
  ::GAME::Mga::Iterator <ImplementationDependency> ComponentImplementationContainer_Impl::get_ImplementationDependencys (void) const
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
  ::GAME::Mga::Iterator <Capability> ComponentImplementationContainer_Impl::get_Capabilitys (void) const
  {
    return this->children <Capability> ();
  }
}

