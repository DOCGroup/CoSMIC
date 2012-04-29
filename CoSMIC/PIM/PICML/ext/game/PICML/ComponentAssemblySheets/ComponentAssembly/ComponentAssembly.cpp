// $Id$

#include "StdAfx.h"
#include "ComponentAssembly.h"

#if !defined (__GAME_INLINE__)
#include "ComponentAssembly.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/CriticalPath.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyselectRequirement.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeValue.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Publish.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Consume.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssemblyReference.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ExternalPort.h"
#include "PICML/Common/Requirement.h"
#include "PICML/Common/Property.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentAssembly_Impl::metaname ("ComponentAssembly");

  //
  // accept
  //
  void ComponentAssembly_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentAssembly (this);
    else
      v->visit_Model (this);
  }

  //
  // src_CriticalPath
  //
  size_t ComponentAssembly_Impl::src_CriticalPath (std::vector <CriticalPath> & items) const
  {
    return this->in_connections <CriticalPath> (items);
  }

  //
  // get_ConnectorInstances
  //
  size_t ComponentAssembly_Impl::get_ConnectorInstances (std::vector <ConnectorInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorInstances
  //
  ::GAME::Mga::Iterator <ConnectorInstance> ComponentAssembly_Impl::get_ConnectorInstances (void) const
  {
    return this->children <ConnectorInstance> ();
  }

  //
  // get_ComponentInstances
  //
  size_t ComponentAssembly_Impl::get_ComponentInstances (std::vector <ComponentInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentInstances
  //
  ::GAME::Mga::Iterator <ComponentInstance> ComponentAssembly_Impl::get_ComponentInstances (void) const
  {
    return this->children <ComponentInstance> ();
  }

  //
  // get_Invokes
  //
  size_t ComponentAssembly_Impl::get_Invokes (std::vector <Invoke> & items) const
  {
    return this->children (items);
  }

  //
  // get_Invokes
  //
  ::GAME::Mga::Iterator <Invoke> ComponentAssembly_Impl::get_Invokes (void) const
  {
    return this->children <Invoke> ();
  }

  //
  // get_AssemblyselectRequirements
  //
  size_t ComponentAssembly_Impl::get_AssemblyselectRequirements (std::vector <AssemblyselectRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_AssemblyselectRequirements
  //
  ::GAME::Mga::Iterator <AssemblyselectRequirement> ComponentAssembly_Impl::get_AssemblyselectRequirements (void) const
  {
    return this->children <AssemblyselectRequirement> ();
  }

  //
  // get_AssemblyConfigPropertys
  //
  size_t ComponentAssembly_Impl::get_AssemblyConfigPropertys (std::vector <AssemblyConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_AssemblyConfigPropertys
  //
  ::GAME::Mga::Iterator <AssemblyConfigProperty> ComponentAssembly_Impl::get_AssemblyConfigPropertys (void) const
  {
    return this->children <AssemblyConfigProperty> ();
  }

  //
  // get_SendsTos
  //
  size_t ComponentAssembly_Impl::get_SendsTos (std::vector <SendsTo> & items) const
  {
    return this->children (items);
  }

  //
  // get_SendsTos
  //
  ::GAME::Mga::Iterator <SendsTo> ComponentAssembly_Impl::get_SendsTos (void) const
  {
    return this->children <SendsTo> ();
  }

  //
  // get_ReceptacleDelegates
  //
  size_t ComponentAssembly_Impl::get_ReceptacleDelegates (std::vector <ReceptacleDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReceptacleDelegates
  //
  ::GAME::Mga::Iterator <ReceptacleDelegate> ComponentAssembly_Impl::get_ReceptacleDelegates (void) const
  {
    return this->children <ReceptacleDelegate> ();
  }

  //
  // get_FacetDelegates
  //
  size_t ComponentAssembly_Impl::get_FacetDelegates (std::vector <FacetDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_FacetDelegates
  //
  ::GAME::Mga::Iterator <FacetDelegate> ComponentAssembly_Impl::get_FacetDelegates (void) const
  {
    return this->children <FacetDelegate> ();
  }

  //
  // get_EventSourceDelegates
  //
  size_t ComponentAssembly_Impl::get_EventSourceDelegates (std::vector <EventSourceDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_EventSourceDelegates
  //
  ::GAME::Mga::Iterator <EventSourceDelegate> ComponentAssembly_Impl::get_EventSourceDelegates (void) const
  {
    return this->children <EventSourceDelegate> ();
  }

  //
  // get_EventSinkDelegates
  //
  size_t ComponentAssembly_Impl::get_EventSinkDelegates (std::vector <EventSinkDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_EventSinkDelegates
  //
  ::GAME::Mga::Iterator <EventSinkDelegate> ComponentAssembly_Impl::get_EventSinkDelegates (void) const
  {
    return this->children <EventSinkDelegate> ();
  }

  //
  // get_ExternalDelegates
  //
  size_t ComponentAssembly_Impl::get_ExternalDelegates (std::vector <ExternalDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExternalDelegates
  //
  ::GAME::Mga::Iterator <ExternalDelegate> ComponentAssembly_Impl::get_ExternalDelegates (void) const
  {
    return this->children <ExternalDelegate> ();
  }

  //
  // get_AttributeValues
  //
  size_t ComponentAssembly_Impl::get_AttributeValues (std::vector <AttributeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeValues
  //
  ::GAME::Mga::Iterator <AttributeValue> ComponentAssembly_Impl::get_AttributeValues (void) const
  {
    return this->children <AttributeValue> ();
  }

  //
  // get_AttributeDelegates
  //
  size_t ComponentAssembly_Impl::get_AttributeDelegates (std::vector <AttributeDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeDelegates
  //
  ::GAME::Mga::Iterator <AttributeDelegate> ComponentAssembly_Impl::get_AttributeDelegates (void) const
  {
    return this->children <AttributeDelegate> ();
  }

  //
  // get_AttributeMappings
  //
  size_t ComponentAssembly_Impl::get_AttributeMappings (std::vector <AttributeMapping> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeMappings
  //
  ::GAME::Mga::Iterator <AttributeMapping> ComponentAssembly_Impl::get_AttributeMappings (void) const
  {
    return this->children <AttributeMapping> ();
  }

  //
  // get_AttributeMappingValues
  //
  size_t ComponentAssembly_Impl::get_AttributeMappingValues (std::vector <AttributeMappingValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeMappingValues
  //
  ::GAME::Mga::Iterator <AttributeMappingValue> ComponentAssembly_Impl::get_AttributeMappingValues (void) const
  {
    return this->children <AttributeMappingValue> ();
  }

  //
  // get_AttributeMappingDelegates
  //
  size_t ComponentAssembly_Impl::get_AttributeMappingDelegates (std::vector <AttributeMappingDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeMappingDelegates
  //
  ::GAME::Mga::Iterator <AttributeMappingDelegate> ComponentAssembly_Impl::get_AttributeMappingDelegates (void) const
  {
    return this->children <AttributeMappingDelegate> ();
  }

  //
  // get_Publishs
  //
  size_t ComponentAssembly_Impl::get_Publishs (std::vector <Publish> & items) const
  {
    return this->children (items);
  }

  //
  // get_Publishs
  //
  ::GAME::Mga::Iterator <Publish> ComponentAssembly_Impl::get_Publishs (void) const
  {
    return this->children <Publish> ();
  }

  //
  // get_Consumes
  //
  size_t ComponentAssembly_Impl::get_Consumes (std::vector <Consume> & items) const
  {
    return this->children (items);
  }

  //
  // get_Consumes
  //
  ::GAME::Mga::Iterator <Consume> ComponentAssembly_Impl::get_Consumes (void) const
  {
    return this->children <Consume> ();
  }

  //
  // get_InEventPortDelegates
  //
  size_t ComponentAssembly_Impl::get_InEventPortDelegates (std::vector <InEventPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_InEventPortDelegates
  //
  ::GAME::Mga::Iterator <InEventPortDelegate> ComponentAssembly_Impl::get_InEventPortDelegates (void) const
  {
    return this->children <InEventPortDelegate> ();
  }

  //
  // get_OutEventPortDelegates
  //
  size_t ComponentAssembly_Impl::get_OutEventPortDelegates (std::vector <OutEventPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutEventPortDelegates
  //
  ::GAME::Mga::Iterator <OutEventPortDelegate> ComponentAssembly_Impl::get_OutEventPortDelegates (void) const
  {
    return this->children <OutEventPortDelegate> ();
  }

  //
  // get_RequiredRequestPortDelegates
  //
  size_t ComponentAssembly_Impl::get_RequiredRequestPortDelegates (std::vector <RequiredRequestPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPortDelegates
  //
  ::GAME::Mga::Iterator <RequiredRequestPortDelegate> ComponentAssembly_Impl::get_RequiredRequestPortDelegates (void) const
  {
    return this->children <RequiredRequestPortDelegate> ();
  }

  //
  // get_ProvidedRequestPortDelegates
  //
  size_t ComponentAssembly_Impl::get_ProvidedRequestPortDelegates (std::vector <ProvidedRequestPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPortDelegates
  //
  ::GAME::Mga::Iterator <ProvidedRequestPortDelegate> ComponentAssembly_Impl::get_ProvidedRequestPortDelegates (void) const
  {
    return this->children <ProvidedRequestPortDelegate> ();
  }

  //
  // get_ConnectorToReceptacles
  //
  size_t ComponentAssembly_Impl::get_ConnectorToReceptacles (std::vector <ConnectorToReceptacle> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorToReceptacles
  //
  ::GAME::Mga::Iterator <ConnectorToReceptacle> ComponentAssembly_Impl::get_ConnectorToReceptacles (void) const
  {
    return this->children <ConnectorToReceptacle> ();
  }

  //
  // get_ConnectorToFacets
  //
  size_t ComponentAssembly_Impl::get_ConnectorToFacets (std::vector <ConnectorToFacet> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorToFacets
  //
  ::GAME::Mga::Iterator <ConnectorToFacet> ComponentAssembly_Impl::get_ConnectorToFacets (void) const
  {
    return this->children <ConnectorToFacet> ();
  }

  //
  // get_MirrorPortDelegates
  //
  size_t ComponentAssembly_Impl::get_MirrorPortDelegates (std::vector <MirrorPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_MirrorPortDelegates
  //
  ::GAME::Mga::Iterator <MirrorPortDelegate> ComponentAssembly_Impl::get_MirrorPortDelegates (void) const
  {
    return this->children <MirrorPortDelegate> ();
  }

  //
  // get_MirrorDelegates
  //
  size_t ComponentAssembly_Impl::get_MirrorDelegates (std::vector <MirrorDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_MirrorDelegates
  //
  ::GAME::Mga::Iterator <MirrorDelegate> ComponentAssembly_Impl::get_MirrorDelegates (void) const
  {
    return this->children <MirrorDelegate> ();
  }

  //
  // get_ExtendedPortDelegates
  //
  size_t ComponentAssembly_Impl::get_ExtendedPortDelegates (std::vector <ExtendedPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPortDelegates
  //
  ::GAME::Mga::Iterator <ExtendedPortDelegate> ComponentAssembly_Impl::get_ExtendedPortDelegates (void) const
  {
    return this->children <ExtendedPortDelegate> ();
  }

  //
  // get_ExtendedDelegates
  //
  size_t ComponentAssembly_Impl::get_ExtendedDelegates (std::vector <ExtendedDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedDelegates
  //
  ::GAME::Mga::Iterator <ExtendedDelegate> ComponentAssembly_Impl::get_ExtendedDelegates (void) const
  {
    return this->children <ExtendedDelegate> ();
  }

  //
  // get_ComponentAssemblyReferences
  //
  size_t ComponentAssembly_Impl::get_ComponentAssemblyReferences (std::vector <ComponentAssemblyReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentAssemblyReferences
  //
  ::GAME::Mga::Iterator <ComponentAssemblyReference> ComponentAssembly_Impl::get_ComponentAssemblyReferences (void) const
  {
    return this->children <ComponentAssemblyReference> ();
  }

  //
  // get_ExternalPorts
  //
  size_t ComponentAssembly_Impl::get_ExternalPorts (std::vector <ExternalPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExternalPorts
  //
  ::GAME::Mga::Iterator <ExternalPort> ComponentAssembly_Impl::get_ExternalPorts (void) const
  {
    return this->children <ExternalPort> ();
  }

  //
  // get_Requirements
  //
  size_t ComponentAssembly_Impl::get_Requirements (std::vector <Requirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_Requirements
  //
  ::GAME::Mga::Iterator <Requirement> ComponentAssembly_Impl::get_Requirements (void) const
  {
    return this->children <Requirement> ();
  }

  //
  // get_Propertys
  //
  size_t ComponentAssembly_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> ComponentAssembly_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }

  //
  // get_ComponentPackages
  //
  size_t ComponentAssembly_Impl::get_ComponentPackages (std::vector <ComponentPackage> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPackages
  //
  ::GAME::Mga::Iterator <ComponentPackage> ComponentAssembly_Impl::get_ComponentPackages (void) const
  {
    return this->children <ComponentPackage> ();
  }

  //
  // get_ComponentPackageReferences
  //
  size_t ComponentAssembly_Impl::get_ComponentPackageReferences (std::vector <ComponentPackageReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPackageReferences
  //
  ::GAME::Mga::Iterator <ComponentPackageReference> ComponentAssembly_Impl::get_ComponentPackageReferences (void) const
  {
    return this->children <ComponentPackageReference> ();
  }
}

