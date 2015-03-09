// $Id$

#include "StdAfx.h"
#include "Property.h"

#if !defined (__GAME_INLINE__)
#include "Property.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentConfigProperty.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/ImplementationCommon/InfoProperty.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeValue.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentInfoProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/Common/RequirementBase.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/Common/Requirement.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/Domain/Domain.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/CallAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/RequestAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/OutputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/ImplementationArtifact/ArtifactInfoProperty.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ComponentPackage/PackageInfoProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigProperty.h"
#include "PICML/ComponentPackage/PackageConfigProperty.h"
#include "PICML/ImplementationArtifact/ArtifactExecParameter.h"
#include "PICML/DeploymentPlan/PropertyMapping.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Property_Impl::metaname ("Property");

  //
  // is_abstract
  //
  const bool Property_Impl::is_abstract = true;

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer Property_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer Property_Impl::parent_ComponentContainer (void)
  {
    return ComponentContainer::_narrow (this->parent ());
  }

  //
  // parent_RequirementBase
  //
  RequirementBase Property_Impl::parent_RequirementBase (void)
  {
    return RequirementBase::_narrow (this->parent ());
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly Property_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // parent_Paths
  //
  Paths Property_Impl::parent_Paths (void)
  {
    return Paths::_narrow (this->parent ());
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan Property_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer Property_Impl::parent_ArtifactContainer (void)
  {
    return ArtifactContainer::_narrow (this->parent ());
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer Property_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // parent_PackageContainer
  //
  PackageContainer Property_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // parent_Domain
  //
  Domain Property_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
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
  // src_of_EdgeProperty
  //
  size_t Property_Impl::src_of_EdgeProperty (std::vector <EdgeProperty> & items) const
  {
    return this->in_connections <EdgeProperty> (items);
  }

  //
  // src_of_EdgeProperty
  //
  GAME::Mga::Collection_T <EdgeProperty> Property_Impl::src_of_EdgeProperty (void) const
  {
    return this->in_connections <EdgeProperty> ("src");
  }

  //
  // src_of_CollocationGroupProperty
  //
  size_t Property_Impl::src_of_CollocationGroupProperty (std::vector <CollocationGroupProperty> & items) const
  {
    return this->in_connections <CollocationGroupProperty> (items);
  }

  //
  // src_of_CollocationGroupProperty
  //
  GAME::Mga::Collection_T <CollocationGroupProperty> Property_Impl::src_of_CollocationGroupProperty (void) const
  {
    return this->in_connections <CollocationGroupProperty> ("src");
  }

  //
  // dst_of_ComponentConfigProperty
  //
  size_t Property_Impl::dst_of_ComponentConfigProperty (std::vector <ComponentConfigProperty> & items) const
  {
    return this->in_connections <ComponentConfigProperty> (items);
  }

  //
  // dst_of_ComponentConfigProperty
  //
  GAME::Mga::Collection_T <ComponentConfigProperty> Property_Impl::dst_of_ComponentConfigProperty (void) const
  {
    return this->in_connections <ComponentConfigProperty> ("dst");
  }

  //
  // dst_of_InfoProperty
  //
  size_t Property_Impl::dst_of_InfoProperty (std::vector <InfoProperty> & items) const
  {
    return this->in_connections <InfoProperty> (items);
  }

  //
  // dst_of_InfoProperty
  //
  GAME::Mga::Collection_T <InfoProperty> Property_Impl::dst_of_InfoProperty (void) const
  {
    return this->in_connections <InfoProperty> ("dst");
  }

  //
  // dst_of_PathProperty
  //
  size_t Property_Impl::dst_of_PathProperty (std::vector <PathProperty> & items) const
  {
    return this->in_connections <PathProperty> (items);
  }

  //
  // dst_of_PathProperty
  //
  GAME::Mga::Collection_T <PathProperty> Property_Impl::dst_of_PathProperty (void) const
  {
    return this->in_connections <PathProperty> ("dst");
  }

  //
  // dst_of_AttributeValue
  //
  size_t Property_Impl::dst_of_AttributeValue (std::vector <AttributeValue> & items) const
  {
    return this->in_connections <AttributeValue> (items);
  }

  //
  // has_dst_of_AttributeValue
  //
  bool Property_Impl::has_dst_of_AttributeValue (void) const
  {
    return this->in_connections <AttributeValue> ("dst").count () == 1;
  }

  //
  // dst_of_AttributeValue
  //
  AttributeValue Property_Impl::dst_of_AttributeValue (void) const
  {
    return this->in_connections <AttributeValue> ("dst").first ();
  }

  //
  // dst_of_ComponentInfoProperty
  //
  size_t Property_Impl::dst_of_ComponentInfoProperty (std::vector <ComponentInfoProperty> & items) const
  {
    return this->in_connections <ComponentInfoProperty> (items);
  }

  //
  // dst_of_ComponentInfoProperty
  //
  GAME::Mga::Collection_T <ComponentInfoProperty> Property_Impl::dst_of_ComponentInfoProperty (void) const
  {
    return this->in_connections <ComponentInfoProperty> ("dst");
  }

  //
  // dst_of_AttributeMappingValue
  //
  size_t Property_Impl::dst_of_AttributeMappingValue (std::vector <AttributeMappingValue> & items) const
  {
    return this->in_connections <AttributeMappingValue> (items);
  }

  //
  // has_dst_of_AttributeMappingValue
  //
  bool Property_Impl::has_dst_of_AttributeMappingValue (void) const
  {
    return this->in_connections <AttributeMappingValue> ("dst").count () == 1;
  }

  //
  // dst_of_AttributeMappingValue
  //
  AttributeMappingValue Property_Impl::dst_of_AttributeMappingValue (void) const
  {
    return this->in_connections <AttributeMappingValue> ("dst").first ();
  }

  //
  // dst_of_PackageConfConfigProperty
  //
  size_t Property_Impl::dst_of_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const
  {
    return this->in_connections <PackageConfConfigProperty> (items);
  }

  //
  // dst_of_PackageConfConfigProperty
  //
  GAME::Mga::Collection_T <PackageConfConfigProperty> Property_Impl::dst_of_PackageConfConfigProperty (void) const
  {
    return this->in_connections <PackageConfConfigProperty> ("dst");
  }

  //
  // dst_of_ArtifactInfoProperty
  //
  size_t Property_Impl::dst_of_ArtifactInfoProperty (std::vector <ArtifactInfoProperty> & items) const
  {
    return this->in_connections <ArtifactInfoProperty> (items);
  }

  //
  // dst_of_ArtifactInfoProperty
  //
  GAME::Mga::Collection_T <ArtifactInfoProperty> Property_Impl::dst_of_ArtifactInfoProperty (void) const
  {
    return this->in_connections <ArtifactInfoProperty> ("dst");
  }

  //
  // dst_of_ConfigProperty
  //
  size_t Property_Impl::dst_of_ConfigProperty (std::vector <ConfigProperty> & items) const
  {
    return this->in_connections <ConfigProperty> (items);
  }

  //
  // dst_of_ConfigProperty
  //
  GAME::Mga::Collection_T <ConfigProperty> Property_Impl::dst_of_ConfigProperty (void) const
  {
    return this->in_connections <ConfigProperty> ("dst");
  }

  //
  // dst_of_MonolithExecParameter
  //
  size_t Property_Impl::dst_of_MonolithExecParameter (std::vector <MonolithExecParameter> & items) const
  {
    return this->in_connections <MonolithExecParameter> (items);
  }

  //
  // dst_of_MonolithExecParameter
  //
  GAME::Mga::Collection_T <MonolithExecParameter> Property_Impl::dst_of_MonolithExecParameter (void) const
  {
    return this->in_connections <MonolithExecParameter> ("dst");
  }

  //
  // dst_of_PackageInfoProperty
  //
  size_t Property_Impl::dst_of_PackageInfoProperty (std::vector <PackageInfoProperty> & items) const
  {
    return this->in_connections <PackageInfoProperty> (items);
  }

  //
  // dst_of_PackageInfoProperty
  //
  GAME::Mga::Collection_T <PackageInfoProperty> Property_Impl::dst_of_PackageInfoProperty (void) const
  {
    return this->in_connections <PackageInfoProperty> ("dst");
  }

  //
  // dst_of_AssemblyConfigProperty
  //
  size_t Property_Impl::dst_of_AssemblyConfigProperty (std::vector <AssemblyConfigProperty> & items) const
  {
    return this->in_connections <AssemblyConfigProperty> (items);
  }

  //
  // has_dst_of_AssemblyConfigProperty
  //
  bool Property_Impl::has_dst_of_AssemblyConfigProperty (void) const
  {
    return this->in_connections <AssemblyConfigProperty> ("dst").count () == 1;
  }

  //
  // dst_of_AssemblyConfigProperty
  //
  AssemblyConfigProperty Property_Impl::dst_of_AssemblyConfigProperty (void) const
  {
    return this->in_connections <AssemblyConfigProperty> ("dst").first ();
  }

  //
  // dst_of_PackageConfigProperty
  //
  size_t Property_Impl::dst_of_PackageConfigProperty (std::vector <PackageConfigProperty> & items) const
  {
    return this->in_connections <PackageConfigProperty> (items);
  }

  //
  // dst_of_PackageConfigProperty
  //
  GAME::Mga::Collection_T <PackageConfigProperty> Property_Impl::dst_of_PackageConfigProperty (void) const
  {
    return this->in_connections <PackageConfigProperty> ("dst");
  }

  //
  // dst_of_ArtifactExecParameter
  //
  size_t Property_Impl::dst_of_ArtifactExecParameter (std::vector <ArtifactExecParameter> & items) const
  {
    return this->in_connections <ArtifactExecParameter> (items);
  }

  //
  // dst_of_ArtifactExecParameter
  //
  GAME::Mga::Collection_T <ArtifactExecParameter> Property_Impl::dst_of_ArtifactExecParameter (void) const
  {
    return this->in_connections <ArtifactExecParameter> ("dst");
  }

  //
  // dst_of_PropertyMapping
  //
  size_t Property_Impl::dst_of_PropertyMapping (std::vector <PropertyMapping> & items) const
  {
    return this->in_connections <PropertyMapping> (items);
  }

  //
  // dst_of_PropertyMapping
  //
  GAME::Mga::Collection_T <PropertyMapping> Property_Impl::dst_of_PropertyMapping (void) const
  {
    return this->in_connections <PropertyMapping> ("dst");
  }
}

