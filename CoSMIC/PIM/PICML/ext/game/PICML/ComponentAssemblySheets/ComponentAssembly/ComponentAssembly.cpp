// $Id$

#include "stdafx.h"
#include "ComponentAssembly.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortDelegate.h"
#include "PICML/Common/Requirement.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyselectRequirement.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"
#include "PICML/Common/Property.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeValue.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigProperty.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssemblyReference.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ExternalPort.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Publish.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Consume.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssemblyReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentAssembly_Impl::metaname = "ComponentAssembly";

  //
  // ComponentAssembly_Impl
  //
  ComponentAssembly_Impl::ComponentAssembly_Impl (void)
  {
  }

  //
  // ComponentAssembly_Impl
  //
  ComponentAssembly_Impl::ComponentAssembly_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentAssembly_Impl
  //
  ComponentAssembly_Impl::~ComponentAssembly_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentAssembly_Impl::accept (Visitor * v)
  {
    v->visit_ComponentAssembly (this);
  }

  //
  // _create
  //
  ComponentAssembly ComponentAssembly_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object <ComponentAssembly> (parent, ComponentAssembly_Impl::metaname);
  }

  //
  // get_OutEventPortDelegates
  //
  size_t ComponentAssembly_Impl::get_OutEventPortDelegates (std::vector <OutEventPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_Requirements
  //
  size_t ComponentAssembly_Impl::get_Requirements (std::vector <Requirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_EventSinkDelegates
  //
  size_t ComponentAssembly_Impl::get_EventSinkDelegates (std::vector <EventSinkDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_AssemblyselectRequirements
  //
  size_t ComponentAssembly_Impl::get_AssemblyselectRequirements (std::vector <AssemblyselectRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_SendsTos
  //
  size_t ComponentAssembly_Impl::get_SendsTos (std::vector <SendsTo> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t ComponentAssembly_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeValues
  //
  size_t ComponentAssembly_Impl::get_AttributeValues (std::vector <AttributeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_AssemblyConfigPropertys
  //
  size_t ComponentAssembly_Impl::get_AssemblyConfigPropertys (std::vector <AssemblyConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentAssemblyReferences
  //
  size_t ComponentAssembly_Impl::get_ComponentAssemblyReferences (std::vector <ComponentAssemblyReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeDelegates
  //
  size_t ComponentAssembly_Impl::get_AttributeDelegates (std::vector <AttributeDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_EventSourceDelegates
  //
  size_t ComponentAssembly_Impl::get_EventSourceDelegates (std::vector <EventSourceDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_MirrorDelegates
  //
  size_t ComponentAssembly_Impl::get_MirrorDelegates (std::vector <MirrorDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorToFacets
  //
  size_t ComponentAssembly_Impl::get_ConnectorToFacets (std::vector <ConnectorToFacet> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedDelegates
  //
  size_t ComponentAssembly_Impl::get_ExtendedDelegates (std::vector <ExtendedDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorInstances
  //
  size_t ComponentAssembly_Impl::get_ConnectorInstances (std::vector <ConnectorInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReceptacleDelegates
  //
  size_t ComponentAssembly_Impl::get_ReceptacleDelegates (std::vector <ReceptacleDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_Invokes
  //
  size_t ComponentAssembly_Impl::get_Invokes (std::vector <Invoke> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExternalPorts
  //
  size_t ComponentAssembly_Impl::get_ExternalPorts (std::vector <ExternalPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_FacetDelegates
  //
  size_t ComponentAssembly_Impl::get_FacetDelegates (std::vector <FacetDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPortDelegates
  //
  size_t ComponentAssembly_Impl::get_ProvidedRequestPortDelegates (std::vector <ProvidedRequestPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_InEventPortDelegates
  //
  size_t ComponentAssembly_Impl::get_InEventPortDelegates (std::vector <InEventPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeMappings
  //
  size_t ComponentAssembly_Impl::get_AttributeMappings (std::vector <AttributeMapping> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPortDelegates
  //
  size_t ComponentAssembly_Impl::get_ExtendedPortDelegates (std::vector <ExtendedPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorToReceptacles
  //
  size_t ComponentAssembly_Impl::get_ConnectorToReceptacles (std::vector <ConnectorToReceptacle> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentAssemblys
  //
  size_t ComponentAssembly_Impl::get_ComponentAssemblys (std::vector <ComponentAssembly> & items) const
  {
    return this->children (items);
  }

  //
  // get_MirrorPortDelegates
  //
  size_t ComponentAssembly_Impl::get_MirrorPortDelegates (std::vector <MirrorPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPortDelegates
  //
  size_t ComponentAssembly_Impl::get_RequiredRequestPortDelegates (std::vector <RequiredRequestPortDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentInstances
  //
  size_t ComponentAssembly_Impl::get_ComponentInstances (std::vector <ComponentInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExternalDelegates
  //
  size_t ComponentAssembly_Impl::get_ExternalDelegates (std::vector <ExternalDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeMappingValues
  //
  size_t ComponentAssembly_Impl::get_AttributeMappingValues (std::vector <AttributeMappingValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPackages
  //
  size_t ComponentAssembly_Impl::get_ComponentPackages (std::vector <ComponentPackage> & items) const
  {
    return this->children (items);
  }

  //
  // get_Publishs
  //
  size_t ComponentAssembly_Impl::get_Publishs (std::vector <Publish> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPackageReferences
  //
  size_t ComponentAssembly_Impl::get_ComponentPackageReferences (std::vector <ComponentPackageReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeMappingDelegates
  //
  size_t ComponentAssembly_Impl::get_AttributeMappingDelegates (std::vector <AttributeMappingDelegate> & items) const
  {
    return this->children (items);
  }

  //
  // get_Consumes
  //
  size_t ComponentAssembly_Impl::get_Consumes (std::vector <Consume> & items) const
  {
    return this->children (items);
  }
}

