// $Id$

#include "StdAfx.h"
#include "Property.h"

#if !defined (__GAME_INLINE__)
#include "Property.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/RequirementBase.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/Common/Requirement.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/OutputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/CallAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/RequestAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryAction.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeValue.h"
#include "PICML/ComponentPackage/PackageConfigProperty.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"
#include "PICML/ImplementationCommon/InfoProperty.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ImplementationArtifact/ArtifactExecParameter.h"
#include "PICML/ImplementationArtifact/ArtifactInfoProperty.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/ComponentPackage/PackageInfoProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentInfoProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentConfigProperty.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/DeploymentPlan/PropertyMapping.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/Domain/Domain.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Property_Impl::metaname ("Property");

  //
  // parent_RequirementBase
  //
  RequirementBase Property_Impl::parent_RequirementBase (void)
  {
    return RequirementBase::_narrow (this->parent ());
  }

  //
  // parent_BehaviorInputAction
  //
  BehaviorInputAction Property_Impl::parent_BehaviorInputAction (void)
  {
    return BehaviorInputAction::_narrow (this->parent ());
  }

  //
  // parent_ActionBase
  //
  ActionBase Property_Impl::parent_ActionBase (void)
  {
    return ActionBase::_narrow (this->parent ());
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer Property_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // parent_QueryInputAction
  //
  QueryInputAction Property_Impl::parent_QueryInputAction (void)
  {
    return QueryInputAction::_narrow (this->parent ());
  }

  //
  // parent_Path
  //
  Path Property_Impl::parent_Path (void)
  {
    return Path::_narrow (this->parent ());
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly Property_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer Property_Impl::parent_ComponentContainer (void)
  {
    return ComponentContainer::_narrow (this->parent ());
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer Property_Impl::parent_ArtifactContainer (void)
  {
    return ArtifactContainer::_narrow (this->parent ());
  }

  //
  // parent_Domain
  //
  Domain Property_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan Property_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // parent_Paths
  //
  Paths Property_Impl::parent_Paths (void)
  {
    return Paths::_narrow (this->parent ());
  }

  //
  // parent_PackageContainer
  //
  PackageContainer Property_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer Property_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // src_EdgeProperty
  //
  size_t Property_Impl::src_EdgeProperty (std::vector <EdgeProperty> & items) const
  {
    return this->in_connections <EdgeProperty> (items);
  }

  //
  // src_CollocationGroupProperty
  //
  size_t Property_Impl::src_CollocationGroupProperty (std::vector <CollocationGroupProperty> & items) const
  {
    return this->in_connections <CollocationGroupProperty> (items);
  }

  //
  // dst_AttributeValue
  //
  size_t Property_Impl::dst_AttributeValue (std::vector <AttributeValue> & items) const
  {
    return this->in_connections <AttributeValue> (items);
  }

  //
  // dst_PackageConfigProperty
  //
  size_t Property_Impl::dst_PackageConfigProperty (std::vector <PackageConfigProperty> & items) const
  {
    return this->in_connections <PackageConfigProperty> (items);
  }

  //
  // dst_ConfigProperty
  //
  size_t Property_Impl::dst_ConfigProperty (std::vector <ConfigProperty> & items) const
  {
    return this->in_connections <ConfigProperty> (items);
  }

  //
  // dst_InfoProperty
  //
  size_t Property_Impl::dst_InfoProperty (std::vector <InfoProperty> & items) const
  {
    return this->in_connections <InfoProperty> (items);
  }

  //
  // dst_MonolithExecParameter
  //
  size_t Property_Impl::dst_MonolithExecParameter (std::vector <MonolithExecParameter> & items) const
  {
    return this->in_connections <MonolithExecParameter> (items);
  }

  //
  // dst_ArtifactExecParameter
  //
  size_t Property_Impl::dst_ArtifactExecParameter (std::vector <ArtifactExecParameter> & items) const
  {
    return this->in_connections <ArtifactExecParameter> (items);
  }

  //
  // dst_ArtifactInfoProperty
  //
  size_t Property_Impl::dst_ArtifactInfoProperty (std::vector <ArtifactInfoProperty> & items) const
  {
    return this->in_connections <ArtifactInfoProperty> (items);
  }

  //
  // dst_PackageConfConfigProperty
  //
  size_t Property_Impl::dst_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const
  {
    return this->in_connections <PackageConfConfigProperty> (items);
  }

  //
  // dst_PackageInfoProperty
  //
  size_t Property_Impl::dst_PackageInfoProperty (std::vector <PackageInfoProperty> & items) const
  {
    return this->in_connections <PackageInfoProperty> (items);
  }

  //
  // dst_AssemblyConfigProperty
  //
  size_t Property_Impl::dst_AssemblyConfigProperty (std::vector <AssemblyConfigProperty> & items) const
  {
    return this->in_connections <AssemblyConfigProperty> (items);
  }

  //
  // dst_ComponentInfoProperty
  //
  size_t Property_Impl::dst_ComponentInfoProperty (std::vector <ComponentInfoProperty> & items) const
  {
    return this->in_connections <ComponentInfoProperty> (items);
  }

  //
  // dst_ComponentConfigProperty
  //
  size_t Property_Impl::dst_ComponentConfigProperty (std::vector <ComponentConfigProperty> & items) const
  {
    return this->in_connections <ComponentConfigProperty> (items);
  }

  //
  // dst_PropertyMapping
  //
  size_t Property_Impl::dst_PropertyMapping (std::vector <PropertyMapping> & items) const
  {
    return this->in_connections <PropertyMapping> (items);
  }

  //
  // dst_PathProperty
  //
  size_t Property_Impl::dst_PathProperty (std::vector <PathProperty> & items) const
  {
    return this->in_connections <PathProperty> (items);
  }

  //
  // dst_AttributeMappingValue
  //
  size_t Property_Impl::dst_AttributeMappingValue (std::vector <AttributeMappingValue> & items) const
  {
    return this->in_connections <AttributeMappingValue> (items);
  }
}

