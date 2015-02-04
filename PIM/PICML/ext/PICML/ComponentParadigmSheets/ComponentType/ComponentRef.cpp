// $Id$

#include "StdAfx.h"
#include "ComponentRef.h"

#if !defined (__GAME_INLINE__)
#include "ComponentRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/ComponentPackage/PackageInterface.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentConfigProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentInfoProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentRef_Impl::metaname ("ComponentRef");

  //
  // is_abstract
  //
  const bool ComponentRef_Impl::is_abstract = false;

  //
  // _create (const Package_in)
  //
  ComponentRef ComponentRef_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  ComponentRef ComponentRef_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const PackageContainer_in)
  //
  ComponentRef ComponentRef_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const ComponentImplementationContainer_in)
  //
  ComponentRef ComponentRef_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const ComponentContainer_in)
  //
  ComponentRef ComponentRef_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  ComponentRef ComponentRef_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Package
  //
  Package ComponentRef_Impl::parent_Package (void)
  {
    return Package::_narrow (this->parent ());
  }

  //
  // parent_File
  //
  File ComponentRef_Impl::parent_File (void)
  {
    return File::_narrow (this->parent ());
  }

  //
  // parent_PackageContainer
  //
  PackageContainer ComponentRef_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ComponentRef_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentRef_Impl::parent_ComponentContainer (void)
  {
    return ComponentContainer::_narrow (this->parent ());
  }

  //
  // parent_Path
  //
  Path ComponentRef_Impl::parent_Path (void)
  {
    return Path::_narrow (this->parent ());
  }

  //
  // src_of_ComponentConfigProperty
  //
  size_t ComponentRef_Impl::src_of_ComponentConfigProperty (std::vector <ComponentConfigProperty> & items) const
  {
    return this->in_connections <ComponentConfigProperty> (items);
  }

  //
  // src_of_ComponentConfigProperty
  //
  GAME::Mga::Collection_T <ComponentConfigProperty> ComponentRef_Impl::src_of_ComponentConfigProperty (void) const
  {
    return this->in_connections <ComponentConfigProperty> ("src");
  }

  //
  // src_of_ComponentInfoProperty
  //
  size_t ComponentRef_Impl::src_of_ComponentInfoProperty (std::vector <ComponentInfoProperty> & items) const
  {
    return this->in_connections <ComponentInfoProperty> (items);
  }

  //
  // src_of_ComponentInfoProperty
  //
  GAME::Mga::Collection_T <ComponentInfoProperty> ComponentRef_Impl::src_of_ComponentInfoProperty (void) const
  {
    return this->in_connections <ComponentInfoProperty> ("src");
  }

  //
  // src_of_ComponentProperty
  //
  size_t ComponentRef_Impl::src_of_ComponentProperty (std::vector <ComponentProperty> & items) const
  {
    return this->in_connections <ComponentProperty> (items);
  }

  //
  // src_of_ComponentProperty
  //
  GAME::Mga::Collection_T <ComponentProperty> ComponentRef_Impl::src_of_ComponentProperty (void) const
  {
    return this->in_connections <ComponentProperty> ("src");
  }

  //
  // dst_of_PackageInterface
  //
  size_t ComponentRef_Impl::dst_of_PackageInterface (std::vector <PackageInterface> & items) const
  {
    return this->in_connections <PackageInterface> (items);
  }

  //
  // dst_of_PackageInterface
  //
  GAME::Mga::Collection_T <PackageInterface> ComponentRef_Impl::dst_of_PackageInterface (void) const
  {
    return this->in_connections <PackageInterface> ("dst");
  }

  //
  // dst_of_Implements
  //
  size_t ComponentRef_Impl::dst_of_Implements (std::vector <Implements> & items) const
  {
    return this->in_connections <Implements> (items);
  }

  //
  // dst_of_Implements
  //
  GAME::Mga::Collection_T <Implements> ComponentRef_Impl::dst_of_Implements (void) const
  {
    return this->in_connections <Implements> ("dst");
  }

  //
  // Component_is_nil
  //
  bool ComponentRef_Impl::Component_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_Component
  //
  void ComponentRef_Impl::refers_to_Component (Component_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Component
  //
  Component ComponentRef_Impl::refers_to_Component (void) const
  {
    return Component::_narrow (this->refers_to ());
  }
}

