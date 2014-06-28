// $Id$

#include "StdAfx.h"
#include "File.h"

#if !defined (__GAME_INLINE__)
#include "File.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/InterfaceDefinition/InterfaceDefinitions.h"
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/FileRef.h"
#include "PICML/InterfaceDefinition/NativeValue.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string File_Impl::metaname ("File");

  //
  // _create (const InterfaceDefinitions_in)
  //
  File File_Impl::_create (const InterfaceDefinitions_in parent)
  {
    return ::GAME::Mga::create_root_object < File > (parent, File_Impl::metaname);
  }

  //
  // accept
  //
  void File_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_File (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_InterfaceDefinitions
  //
  InterfaceDefinitions File_Impl::parent_InterfaceDefinitions (void)
  {
    return InterfaceDefinitions::_narrow (this->parent ());
  }

  //
  // get_Exceptions
  //
  size_t File_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  ::GAME::Mga::Collection_T <Exception> File_Impl::get_Exceptions (void) const
  {
    return this->children <Exception> ();
  }

  //
  // get_ComponentRefs
  //
  size_t File_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  ::GAME::Mga::Collection_T <ComponentRef> File_Impl::get_ComponentRefs (void) const
  {
    return this->children <ComponentRef> ();
  }

  //
  // get_ManagesComponents
  //
  size_t File_Impl::get_ManagesComponents (std::vector <ManagesComponent> & items) const
  {
    return this->children (items);
  }

  //
  // get_ManagesComponents
  //
  ::GAME::Mga::Collection_T <ManagesComponent> File_Impl::get_ManagesComponents (void) const
  {
    return this->children <ManagesComponent> ();
  }

  //
  // get_Constants
  //
  size_t File_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_Constants
  //
  ::GAME::Mga::Collection_T <Constant> File_Impl::get_Constants (void) const
  {
    return this->children <Constant> ();
  }

  //
  // get_ComponentFactorys
  //
  size_t File_Impl::get_ComponentFactorys (std::vector <ComponentFactory> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentFactorys
  //
  ::GAME::Mga::Collection_T <ComponentFactory> File_Impl::get_ComponentFactorys (void) const
  {
    return this->children <ComponentFactory> ();
  }

  //
  // get_Objects
  //
  size_t File_Impl::get_Objects (std::vector <Object> & items) const
  {
    return this->children (items);
  }

  //
  // get_Objects
  //
  ::GAME::Mga::Collection_T <Object> File_Impl::get_Objects (void) const
  {
    return this->children <Object> ();
  }

  //
  // get_ValueObjects
  //
  size_t File_Impl::get_ValueObjects (std::vector <ValueObject> & items) const
  {
    return this->children (items);
  }

  //
  // get_ValueObjects
  //
  ::GAME::Mga::Collection_T <ValueObject> File_Impl::get_ValueObjects (void) const
  {
    return this->children <ValueObject> ();
  }

  //
  // get_Events
  //
  size_t File_Impl::get_Events (std::vector <Event> & items) const
  {
    return this->children (items);
  }

  //
  // get_Events
  //
  ::GAME::Mga::Collection_T <Event> File_Impl::get_Events (void) const
  {
    return this->children <Event> ();
  }

  //
  // get_Collections
  //
  size_t File_Impl::get_Collections (std::vector <Collection> & items) const
  {
    return this->children (items);
  }

  //
  // get_Collections
  //
  ::GAME::Mga::Collection_T <Collection> File_Impl::get_Collections (void) const
  {
    return this->children <Collection> ();
  }

  //
  // get_PortTypes
  //
  size_t File_Impl::get_PortTypes (std::vector <PortType> & items) const
  {
    return this->children (items);
  }

  //
  // get_PortTypes
  //
  ::GAME::Mga::Collection_T <PortType> File_Impl::get_PortTypes (void) const
  {
    return this->children <PortType> ();
  }

  //
  // get_Aggregates
  //
  size_t File_Impl::get_Aggregates (std::vector <Aggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aggregates
  //
  ::GAME::Mga::Collection_T <Aggregate> File_Impl::get_Aggregates (void) const
  {
    return this->children <Aggregate> ();
  }

  //
  // get_SwitchedAggregates
  //
  size_t File_Impl::get_SwitchedAggregates (std::vector <SwitchedAggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_SwitchedAggregates
  //
  ::GAME::Mga::Collection_T <SwitchedAggregate> File_Impl::get_SwitchedAggregates (void) const
  {
    return this->children <SwitchedAggregate> ();
  }

  //
  // get_Enums
  //
  size_t File_Impl::get_Enums (std::vector <Enum> & items) const
  {
    return this->children (items);
  }

  //
  // get_Enums
  //
  ::GAME::Mga::Collection_T <Enum> File_Impl::get_Enums (void) const
  {
    return this->children <Enum> ();
  }

  //
  // get_Aliass
  //
  size_t File_Impl::get_Aliass (std::vector <Alias> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aliass
  //
  ::GAME::Mga::Collection_T <Alias> File_Impl::get_Aliass (void) const
  {
    return this->children <Alias> ();
  }

  //
  // get_Components
  //
  size_t File_Impl::get_Components (std::vector <Component> & items) const
  {
    return this->children (items);
  }

  //
  // get_Components
  //
  ::GAME::Mga::Collection_T <Component> File_Impl::get_Components (void) const
  {
    return this->children <Component> ();
  }

  //
  // get_ConnectorObjects
  //
  size_t File_Impl::get_ConnectorObjects (std::vector <ConnectorObject> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorObjects
  //
  ::GAME::Mga::Collection_T <ConnectorObject> File_Impl::get_ConnectorObjects (void) const
  {
    return this->children <ConnectorObject> ();
  }

  //
  // get_Boxeds
  //
  size_t File_Impl::get_Boxeds (std::vector <Boxed> & items) const
  {
    return this->children (items);
  }

  //
  // get_Boxeds
  //
  ::GAME::Mga::Collection_T <Boxed> File_Impl::get_Boxeds (void) const
  {
    return this->children <Boxed> ();
  }

  //
  // get_Packages
  //
  size_t File_Impl::get_Packages (std::vector <Package> & items) const
  {
    return this->children (items);
  }

  //
  // get_Packages
  //
  ::GAME::Mga::Collection_T <Package> File_Impl::get_Packages (void) const
  {
    return this->children <Package> ();
  }

  //
  // get_TemplatePackageInstances
  //
  size_t File_Impl::get_TemplatePackageInstances (std::vector <TemplatePackageInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplatePackageInstances
  //
  ::GAME::Mga::Collection_T <TemplatePackageInstance> File_Impl::get_TemplatePackageInstances (void) const
  {
    return this->children <TemplatePackageInstance> ();
  }

  //
  // get_TemplatePackageAliass
  //
  size_t File_Impl::get_TemplatePackageAliass (std::vector <TemplatePackageAlias> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplatePackageAliass
  //
  ::GAME::Mga::Collection_T <TemplatePackageAlias> File_Impl::get_TemplatePackageAliass (void) const
  {
    return this->children <TemplatePackageAlias> ();
  }

  //
  // get_FileRefs
  //
  size_t File_Impl::get_FileRefs (std::vector <FileRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_FileRefs
  //
  ::GAME::Mga::Collection_T <FileRef> File_Impl::get_FileRefs (void) const
  {
    return this->children <FileRef> ();
  }

  //
  // get_NativeValues
  //
  size_t File_Impl::get_NativeValues (std::vector <NativeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_NativeValues
  //
  ::GAME::Mga::Collection_T <NativeValue> File_Impl::get_NativeValues (void) const
  {
    return this->children <NativeValue> ();
  }
}

