// $Id$

#include "StdAfx.h"
#include "Package.h"

#if !defined (__GAME_INLINE__)
#include "Package.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/PackageType.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/InterfaceDefinition/NativeValue.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Package_Impl::metaname ("Package");

  //
  // is_abstract
  //
  const bool Package_Impl::is_abstract = false;

  //
  // _create (const Package_in)
  //
  Package Package_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < Package > (parent, Package_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Package Package_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < Package > (parent, Package_Impl::metaname);
  }

  //
  // accept
  //
  void Package_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Package (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Package
  //
  Package Package_Impl::parent_Package (void)
  {
    return Package::_narrow (this->parent ());
  }

  //
  // parent_File
  //
  File Package_Impl::parent_File (void)
  {
    return File::_narrow (this->parent ());
  }

  //
  // get_ComponentRefs
  //
  size_t Package_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  ::GAME::Mga::Collection_T <ComponentRef> Package_Impl::get_ComponentRefs (void) const
  {
    return this->children <ComponentRef> ();
  }

  //
  // get_Constants
  //
  size_t Package_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_Constants
  //
  ::GAME::Mga::Collection_T <Constant> Package_Impl::get_Constants (void) const
  {
    return this->children <Constant> ();
  }

  //
  // get_ManagesComponents
  //
  size_t Package_Impl::get_ManagesComponents (std::vector <ManagesComponent> & items) const
  {
    return this->children (items);
  }

  //
  // get_ManagesComponents
  //
  ::GAME::Mga::Collection_T <ManagesComponent> Package_Impl::get_ManagesComponents (void) const
  {
    return this->children <ManagesComponent> ();
  }

  //
  // get_Collections
  //
  size_t Package_Impl::get_Collections (std::vector <Collection> & items) const
  {
    return this->children (items);
  }

  //
  // get_Collections
  //
  ::GAME::Mga::Collection_T <Collection> Package_Impl::get_Collections (void) const
  {
    return this->children <Collection> ();
  }

  //
  // get_PortTypes
  //
  size_t Package_Impl::get_PortTypes (std::vector <PortType> & items) const
  {
    return this->children (items);
  }

  //
  // get_PortTypes
  //
  ::GAME::Mga::Collection_T <PortType> Package_Impl::get_PortTypes (void) const
  {
    return this->children <PortType> ();
  }

  //
  // get_Aggregates
  //
  size_t Package_Impl::get_Aggregates (std::vector <Aggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aggregates
  //
  ::GAME::Mga::Collection_T <Aggregate> Package_Impl::get_Aggregates (void) const
  {
    return this->children <Aggregate> ();
  }

  //
  // get_Aliass
  //
  size_t Package_Impl::get_Aliass (std::vector <Alias> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aliass
  //
  ::GAME::Mga::Collection_T <Alias> Package_Impl::get_Aliass (void) const
  {
    return this->children <Alias> ();
  }

  //
  // get_SwitchedAggregates
  //
  size_t Package_Impl::get_SwitchedAggregates (std::vector <SwitchedAggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_SwitchedAggregates
  //
  ::GAME::Mga::Collection_T <SwitchedAggregate> Package_Impl::get_SwitchedAggregates (void) const
  {
    return this->children <SwitchedAggregate> ();
  }

  //
  // get_Enums
  //
  size_t Package_Impl::get_Enums (std::vector <Enum> & items) const
  {
    return this->children (items);
  }

  //
  // get_Enums
  //
  ::GAME::Mga::Collection_T <Enum> Package_Impl::get_Enums (void) const
  {
    return this->children <Enum> ();
  }

  //
  // get_Components
  //
  size_t Package_Impl::get_Components (std::vector <Component> & items) const
  {
    return this->children (items);
  }

  //
  // get_Components
  //
  ::GAME::Mga::Collection_T <Component> Package_Impl::get_Components (void) const
  {
    return this->children <Component> ();
  }

  //
  // get_Objects
  //
  size_t Package_Impl::get_Objects (std::vector <Object> & items) const
  {
    return this->children (items);
  }

  //
  // get_Objects
  //
  ::GAME::Mga::Collection_T <Object> Package_Impl::get_Objects (void) const
  {
    return this->children <Object> ();
  }

  //
  // get_ComponentFactorys
  //
  size_t Package_Impl::get_ComponentFactorys (std::vector <ComponentFactory> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentFactorys
  //
  ::GAME::Mga::Collection_T <ComponentFactory> Package_Impl::get_ComponentFactorys (void) const
  {
    return this->children <ComponentFactory> ();
  }

  //
  // get_Events
  //
  size_t Package_Impl::get_Events (std::vector <Event> & items) const
  {
    return this->children (items);
  }

  //
  // get_Events
  //
  ::GAME::Mga::Collection_T <Event> Package_Impl::get_Events (void) const
  {
    return this->children <Event> ();
  }

  //
  // get_ValueObjects
  //
  size_t Package_Impl::get_ValueObjects (std::vector <ValueObject> & items) const
  {
    return this->children (items);
  }

  //
  // get_ValueObjects
  //
  ::GAME::Mga::Collection_T <ValueObject> Package_Impl::get_ValueObjects (void) const
  {
    return this->children <ValueObject> ();
  }

  //
  // get_ConnectorObjects
  //
  size_t Package_Impl::get_ConnectorObjects (std::vector <ConnectorObject> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorObjects
  //
  ::GAME::Mga::Collection_T <ConnectorObject> Package_Impl::get_ConnectorObjects (void) const
  {
    return this->children <ConnectorObject> ();
  }

  //
  // get_Boxeds
  //
  size_t Package_Impl::get_Boxeds (std::vector <Boxed> & items) const
  {
    return this->children (items);
  }

  //
  // get_Boxeds
  //
  ::GAME::Mga::Collection_T <Boxed> Package_Impl::get_Boxeds (void) const
  {
    return this->children <Boxed> ();
  }

  //
  // get_Exceptions
  //
  size_t Package_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  ::GAME::Mga::Collection_T <Exception> Package_Impl::get_Exceptions (void) const
  {
    return this->children <Exception> ();
  }

  //
  // get_Packages
  //
  size_t Package_Impl::get_Packages (std::vector <Package> & items) const
  {
    return this->children (items);
  }

  //
  // get_Packages
  //
  ::GAME::Mga::Collection_T <Package> Package_Impl::get_Packages (void) const
  {
    return this->children <Package> ();
  }

  //
  // get_TemplatePackageAliass
  //
  size_t Package_Impl::get_TemplatePackageAliass (std::vector <TemplatePackageAlias> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplatePackageAliass
  //
  ::GAME::Mga::Collection_T <TemplatePackageAlias> Package_Impl::get_TemplatePackageAliass (void) const
  {
    return this->children <TemplatePackageAlias> ();
  }

  //
  // get_TemplatePackageInstances
  //
  size_t Package_Impl::get_TemplatePackageInstances (std::vector <TemplatePackageInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplatePackageInstances
  //
  ::GAME::Mga::Collection_T <TemplatePackageInstance> Package_Impl::get_TemplatePackageInstances (void) const
  {
    return this->children <TemplatePackageInstance> ();
  }

  //
  // get_CollectionParameters
  //
  size_t Package_Impl::get_CollectionParameters (std::vector <CollectionParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_CollectionParameters
  //
  ::GAME::Mga::Collection_T <CollectionParameter> Package_Impl::get_CollectionParameters (void) const
  {
    return this->children <CollectionParameter> ();
  }

  //
  // get_TypeParameters
  //
  size_t Package_Impl::get_TypeParameters (std::vector <TypeParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_TypeParameters
  //
  ::GAME::Mga::Collection_T <TypeParameter> Package_Impl::get_TypeParameters (void) const
  {
    return this->children <TypeParameter> ();
  }

  //
  // get_NameParameters
  //
  size_t Package_Impl::get_NameParameters (std::vector <NameParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_NameParameters
  //
  ::GAME::Mga::Collection_T <NameParameter> Package_Impl::get_NameParameters (void) const
  {
    return this->children <NameParameter> ();
  }

  //
  // get_NativeValues
  //
  size_t Package_Impl::get_NativeValues (std::vector <NativeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_NativeValues
  //
  ::GAME::Mga::Collection_T <NativeValue> Package_Impl::get_NativeValues (void) const
  {
    return this->children <NativeValue> ();
  }
}

