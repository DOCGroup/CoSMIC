// cpp source file PICML.cpp generated from diagram PICML
// generated on Fri Jun 11 16:41:39 2004

#include "PICML.h"
#include "UmlExt.h"

namespace PICML {

	Uml::Diagram umldiagram;

	Uml::Class Property::meta;
	Uml::Class ImplementationRequirement::meta;
	Uml::Class Requirement::meta;
	Uml::Class RequirementSatisfier::meta;
	Uml::Class RequirementBase::meta;
	Uml::Class SatisfierProperty::meta;
	Uml::Class DataType::meta;
	Uml::Class ImplementationDependency::meta;
	Uml::Class Capability::meta;
	Uml::Class AssemblyselectRequirement::meta;
	Uml::Class AssemblyConfigProperty::meta;
	Uml::Class PublishConnector::meta;
	Uml::Class publish::meta;
	Uml::Class deliverTo::meta;
	Uml::Class AssemblyDeployRequirement::meta;
	Uml::Class ComponentAssembly::meta;
	Uml::Class emit::meta;
	Uml::Class invoke::meta;
	Uml::Class package::meta;
	Uml::Class TopLevelPackageFolder::meta;
	Uml::Class TopLevelPackageContainer::meta;
	Uml::Class TopLevelPackage::meta;
	Uml::Class ComponentPackage::meta;
	Uml::Class ComponentPackages::meta;
	Uml::Class ComponentPackageReference::meta;
	Uml::Class Implementation::meta;
	Uml::Class PackageContainer::meta;
	Uml::Class PackageConfigProperty::meta;
	Uml::Class PackageInfoProperty::meta;
	Uml::Class PackageInterface::meta;
	Uml::Class InfoProperty::meta;
	Uml::Class MonolithprimaryArtifact::meta;
	Uml::Class MonolithDeployRequirement::meta;
	Uml::Class ComponentImplementation::meta;
	Uml::Class ComponentImplementationReference::meta;
	Uml::Class ConfigProperty::meta;
	Uml::Class ComponentImplementationContainer::meta;
	Uml::Class MonolithicImplementation::meta;
	Uml::Class MonolithExecParameter::meta;
	Uml::Class ImplementationDependsOn::meta;
	Uml::Class Implements::meta;
	Uml::Class ComponentImplementations::meta;
	Uml::Class ImplementationCapability::meta;
	Uml::Class ComponentContainer::meta;
	Uml::Class ComponentPropertyDescription::meta;
	Uml::Class ComponentInfoProperty::meta;
	Uml::Class ComponentProperty::meta;
	Uml::Class CommonPortAttrs::meta;
	Uml::Class ComponentTypes::meta;
	Uml::Class ComponentConfigProperty::meta;
	Uml::Class ComponentType::meta;
	Uml::Class Resource::meta;
	Uml::Class SharedResource::meta;
	Uml::Class NodeReference::meta;
	Uml::Class Bridge::meta;
	Uml::Class Node::meta;
	Uml::Class Interconnect::meta;
	Uml::Class Elements::meta;
	Uml::Class Domain::meta;
	Uml::Class Targets::meta;
	Uml::Class Node2Interconnect::meta;
	Uml::Class Bridge2Interconnect::meta;
	Uml::Class Shares::meta;
	Uml::Class Interconnect2Node::meta;
	Uml::Class Interconnect2Bridge::meta;
	Uml::Class InstanceMapping::meta;
	Uml::Class DeploymentPlan::meta;
	Uml::Class DeploymentPlans::meta;
	Uml::Class CollocationGroup::meta;
	Uml::Class PackageConfigurationReference::meta;
	Uml::Class PackageConfConfigProperty::meta;
	Uml::Class PackageConfigurations::meta;
	Uml::Class PackageConfigurationContainer::meta;
	Uml::Class PackageConfReference::meta;
	Uml::Class PackageConfiguration::meta;
	Uml::Class PackageConfSpecializedConfig::meta;
	Uml::Class PackageConfSelectRequirement::meta;
	Uml::Class PackageConfBasePackage::meta;
	Uml::Class ArtifactExecParameter::meta;
	Uml::Class ArtifactDeployRequirement::meta;
	Uml::Class ImplementationArtifacts::meta;
	Uml::Class ImplementationArtifact::meta;
	Uml::Class ArtifactInfoProperty::meta;
	Uml::Class ArtifactContainer::meta;
	Uml::Class ArtifactDependsOn::meta;
	Uml::Class ImplementationArtifactReference::meta;
	Uml::Class InParameter::meta;
	Uml::Class TwowayOperation::meta;
	Uml::Class OnewayOperation::meta;
	Uml::Class HasExceptions::meta;
	Uml::Class OperationBase::meta;
	Uml::Class FactoryOperation::meta;
	Uml::Class LookupOperation::meta;
	Uml::Class InoutParameter::meta;
	Uml::Class OutParameter::meta;
	Uml::Class ReturnType::meta;
	Uml::Class Exception::meta;
	Uml::Class Package::meta;
	Uml::Class ConstantType::meta;
	Uml::Class File::meta;
	Uml::Class Constant::meta;
	Uml::Class InterfaceDefinitions::meta;
	Uml::Class FileRef::meta;
	Uml::Class ExceptionRef::meta;
	Uml::Class SwitchedAggregate::meta;
	Uml::Class NoInheritable::meta;
	Uml::Class Member::meta;
	Uml::Class Boxed::meta;
	Uml::Class EnumValue::meta;
	Uml::Class Label::meta;
	Uml::Class MemberType::meta;
	Uml::Class Aggregate::meta;
	Uml::Class Alias::meta;
	Uml::Class Collection::meta;
	Uml::Class NamedType::meta;
	Uml::Class Discriminator::meta;
	Uml::Class Enum::meta;
	Uml::Class LabelConnection::meta;
	Uml::Class Prefixable::meta;
	Uml::Class Taggable::meta;
	Uml::Class PredefinedType::meta;
	Uml::Class Boolean::meta;
	Uml::Class GenericValue::meta;
	Uml::Class LongInteger::meta;
	Uml::Class Byte::meta;
	Uml::Class TypeKind::meta;
	Uml::Class GenericObject::meta;
	Uml::Class ShortInteger::meta;
	Uml::Class RealNumber::meta;
	Uml::Class PredefinedTypes::meta;
	Uml::Class String::meta;
	Uml::Class TypeEncoding::meta;
	Uml::Class GenericValueObject::meta;
	Uml::Class SetException::meta;
	Uml::Class LookupKey::meta;
	Uml::Class Attribute::meta;
	Uml::Class ReadonlyAttribute::meta;
	Uml::Class Supports::meta;
	Uml::Class SupportsInterfaces::meta;
	Uml::Class HasOperations::meta;
	Uml::Class Inheritable::meta;
	Uml::Class MakeMemberPrivate::meta;
	Uml::Class PrivateFlag::meta;
	Uml::Class GetException::meta;
	Uml::Class ObjectByValue::meta;
	Uml::Class Inherits::meta;
	Uml::Class Object::meta;
	Uml::Class ValueObject::meta;
	Uml::Class Event::meta;
	Uml::Class AttributeMember::meta;
	Uml::Class OutEventPort::meta;
	Uml::Class ProvidedRequestPort::meta;
	Uml::Class Component::meta;
	Uml::Class RequiredRequestPort::meta;
	Uml::Class ManagesComponent::meta;
	Uml::Class InEventPort::meta;
	Uml::Class Port::meta;
	Uml::Class ComponentRef::meta;
	Uml::Class ComponentFactory::meta;
	Uml::Class Manageable::meta;
	Uml::Class Provideable::meta;
	Uml::Class RootFolder::meta;
	Uml::Class MgaObject::meta;
	Uml::Attribute Property::meta_DataValue;
	Uml::Attribute ImplementationRequirement::meta_ResourceUsageKind;
	Uml::Attribute ImplementationRequirement::meta_componentPort;
	Uml::Attribute ImplementationRequirement::meta_resourcePort;
	Uml::Attribute RequirementSatisfier::meta_resourceType;
	Uml::Attribute RequirementBase::meta_resourceType;
	Uml::Attribute SatisfierProperty::meta_DataValue;
	Uml::Attribute SatisfierProperty::meta_SatisfierPropertyKind;
	Uml::Attribute ImplementationDependency::meta_requiredType;
	Uml::Attribute TopLevelPackageFolder::meta_name;
	Uml::Attribute ComponentPackage::meta_UUID;
	Uml::Attribute ComponentPackage::meta_label;
	Uml::Attribute ComponentPackages::meta_name;
	Uml::Attribute ComponentPackageReference::meta_requiredName;
	Uml::Attribute ComponentPackageReference::meta_requiredUUID;
	Uml::Attribute ComponentPackageReference::meta_requiredType;
	Uml::Attribute ComponentImplementation::meta_UUID;
	Uml::Attribute ComponentImplementation::meta_label;
	Uml::Attribute ComponentImplementations::meta_name;
	Uml::Attribute CommonPortAttrs::meta_exclusiveUser;
	Uml::Attribute CommonPortAttrs::meta_optional;
	Uml::Attribute CommonPortAttrs::meta_exclusiveProvider;
	Uml::Attribute ComponentTypes::meta_name;
	Uml::Attribute Resource::meta_resourceType;
	Uml::Attribute SharedResource::meta_resourceType;
	Uml::Attribute Bridge::meta_label;
	Uml::Attribute Node::meta_label;
	Uml::Attribute Interconnect::meta_label;
	Uml::Attribute Domain::meta_label;
	Uml::Attribute Domain::meta_UUID;
	Uml::Attribute Targets::meta_name;
	Uml::Attribute DeploymentPlan::meta_label;
	Uml::Attribute DeploymentPlans::meta_name;
	Uml::Attribute PackageConfigurations::meta_name;
	Uml::Attribute PackageConfiguration::meta_UUID;
	Uml::Attribute PackageConfiguration::meta_label;
	Uml::Attribute ImplementationArtifacts::meta_name;
	Uml::Attribute ImplementationArtifact::meta_UUID;
	Uml::Attribute ImplementationArtifact::meta_label;
	Uml::Attribute ImplementationArtifact::meta_location;
	Uml::Attribute Constant::meta_value;
	Uml::Attribute InterfaceDefinitions::meta_name;
	Uml::Attribute Prefixable::meta_PrefixTag;
	Uml::Attribute Taggable::meta_VersionTag;
	Uml::Attribute Taggable::meta_SpecifyIdTag;
	Uml::Attribute PredefinedTypes::meta_name;
	Uml::Attribute ObjectByValue::meta_abstract;
	Uml::Attribute Object::meta_abstract;
	Uml::Attribute Object::meta_local;
	Uml::Attribute OutEventPort::meta_single_destination;
	Uml::Attribute Component::meta_UUID;
	Uml::Attribute Component::meta_label;
	Uml::Attribute RequiredRequestPort::meta_multiple_connections;
	Uml::Attribute RootFolder::meta_name;
	Uml::Attribute MgaObject::meta_position;
	Uml::Attribute MgaObject::meta_name;
	Uml::AssociationRole Property::meta_srcPackageConfigProperty, Property::meta_srcPackageConfigProperty_rev;
	Uml::AssociationRole Property::meta_srcPackageInfoProperty, Property::meta_srcPackageInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcConfigProperty, Property::meta_srcConfigProperty_rev;
	Uml::AssociationRole Property::meta_srcInfoProperty, Property::meta_srcInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcMonolithExecParameter, Property::meta_srcMonolithExecParameter_rev;
	Uml::AssociationRole Property::meta_srcComponentConfigProperty, Property::meta_srcComponentConfigProperty_rev;
	Uml::AssociationRole Property::meta_srcComponentInfoProperty, Property::meta_srcComponentInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcPackageConfConfigProperty, Property::meta_srcPackageConfConfigProperty_rev;
	Uml::AssociationRole Property::meta_srcArtifactInfoProperty, Property::meta_srcArtifactInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcArtifactExecParameter, Property::meta_srcArtifactExecParameter_rev;
	Uml::AssociationRole Property::meta_srcAssemblyConfigProperty, Property::meta_srcAssemblyConfigProperty_rev;
	Uml::AssociationRole ImplementationRequirement::meta_srcMonolithDeployRequirement, ImplementationRequirement::meta_srcMonolithDeployRequirement_rev;
	Uml::AssociationRole Requirement::meta_srcPackageConfSelectRequirement, Requirement::meta_srcPackageConfSelectRequirement_rev;
	Uml::AssociationRole Requirement::meta_srcAssemblyDeployRequirement, Requirement::meta_srcAssemblyDeployRequirement_rev;
	Uml::AssociationRole Requirement::meta_srcArtifactDeployRequirement, Requirement::meta_srcArtifactDeployRequirement_rev;
	Uml::AssociationRole Requirement::meta_srcAssemblyselectRequirement, Requirement::meta_srcAssemblyselectRequirement_rev;
	Uml::AssociationRole DataType::meta_ref;
	Uml::AssociationRole ImplementationDependency::meta_srcImplementationDependsOn, ImplementationDependency::meta_srcImplementationDependsOn_rev;
	Uml::AssociationRole Capability::meta_srcImplementationCapability, Capability::meta_srcImplementationCapability_rev;
	Uml::AssociationRole AssemblyselectRequirement::meta_dstAssemblyselectRequirement_end_;
	Uml::AssociationRole AssemblyselectRequirement::meta_srcAssemblyselectRequirement_end_;
	Uml::AssociationRole AssemblyConfigProperty::meta_dstAssemblyConfigProperty_end_;
	Uml::AssociationRole AssemblyConfigProperty::meta_srcAssemblyConfigProperty_end_;
	Uml::AssociationRole PublishConnector::meta_dstAssemblyDeployRequirement, PublishConnector::meta_dstAssemblyDeployRequirement_rev;
	Uml::AssociationRole PublishConnector::meta_dstdeliverTo, PublishConnector::meta_dstdeliverTo_rev;
	Uml::AssociationRole PublishConnector::meta_srcpublish, PublishConnector::meta_srcpublish_rev;
	Uml::AssociationRole publish::meta_dstpublish_end_;
	Uml::AssociationRole publish::meta_srcpublish_end_;
	Uml::AssociationRole deliverTo::meta_srcdeliverTo_end_;
	Uml::AssociationRole deliverTo::meta_dstdeliverTo_end_;
	Uml::AssociationRole AssemblyDeployRequirement::meta_dstAssemblyDeployRequirement_end_;
	Uml::AssociationRole AssemblyDeployRequirement::meta_srcAssemblyDeployRequirement_end_;
	Uml::AssociationRole emit::meta_srcemit_end_;
	Uml::AssociationRole emit::meta_dstemit_end_;
	Uml::AssociationRole invoke::meta_dstinvoke_end_;
	Uml::AssociationRole invoke::meta_srcinvoke_end_;
	Uml::AssociationRole package::meta_dstpackage_end_;
	Uml::AssociationRole package::meta_srcpackage_end_;
	Uml::AssociationRole TopLevelPackage::meta_dstpackage, TopLevelPackage::meta_dstpackage_rev;
	Uml::AssociationRole ComponentPackage::meta_dstPackageConfigProperty, ComponentPackage::meta_dstPackageConfigProperty_rev;
	Uml::AssociationRole ComponentPackage::meta_dstPackageInfoProperty, ComponentPackage::meta_dstPackageInfoProperty_rev;
	Uml::AssociationRole ComponentPackage::meta_dstPackageInterface, ComponentPackage::meta_dstPackageInterface_rev;
	Uml::AssociationRole ComponentPackage::meta_dstImplementation, ComponentPackage::meta_dstImplementation_rev;
	Uml::AssociationRole ComponentPackage::meta_referedbyComponentPackageReference;
	Uml::AssociationRole ComponentPackage::meta_srcPackageConfBasePackage, ComponentPackage::meta_srcPackageConfBasePackage_rev;
	Uml::AssociationRole ComponentPackageReference::meta_ref;
	Uml::AssociationRole ComponentPackageReference::meta_srcPackageConfReference, ComponentPackageReference::meta_srcPackageConfReference_rev;
	Uml::AssociationRole Implementation::meta_srcImplementation_end_;
	Uml::AssociationRole Implementation::meta_dstImplementation_end_;
	Uml::AssociationRole PackageConfigProperty::meta_dstPackageConfigProperty_end_;
	Uml::AssociationRole PackageConfigProperty::meta_srcPackageConfigProperty_end_;
	Uml::AssociationRole PackageInfoProperty::meta_dstPackageInfoProperty_end_;
	Uml::AssociationRole PackageInfoProperty::meta_srcPackageInfoProperty_end_;
	Uml::AssociationRole PackageInterface::meta_srcPackageInterface_end_;
	Uml::AssociationRole PackageInterface::meta_dstPackageInterface_end_;
	Uml::AssociationRole InfoProperty::meta_dstInfoProperty_end_;
	Uml::AssociationRole InfoProperty::meta_srcInfoProperty_end_;
	Uml::AssociationRole MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_;
	Uml::AssociationRole MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_;
	Uml::AssociationRole MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_;
	Uml::AssociationRole MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_;
	Uml::AssociationRole ComponentImplementation::meta_dstConfigProperty, ComponentImplementation::meta_dstConfigProperty_rev;
	Uml::AssociationRole ComponentImplementation::meta_dstInfoProperty, ComponentImplementation::meta_dstInfoProperty_rev;
	Uml::AssociationRole ComponentImplementation::meta_dstImplementationDependsOn, ComponentImplementation::meta_dstImplementationDependsOn_rev;
	Uml::AssociationRole ComponentImplementation::meta_dstImplementationCapability, ComponentImplementation::meta_dstImplementationCapability_rev;
	Uml::AssociationRole ComponentImplementation::meta_dstImplements, ComponentImplementation::meta_dstImplements_rev;
	Uml::AssociationRole ComponentImplementation::meta_referedbyComponentImplementationReference;
	Uml::AssociationRole ComponentImplementationReference::meta_srcImplementation, ComponentImplementationReference::meta_srcImplementation_rev;
	Uml::AssociationRole ComponentImplementationReference::meta_ref;
	Uml::AssociationRole ConfigProperty::meta_dstConfigProperty_end_;
	Uml::AssociationRole ConfigProperty::meta_srcConfigProperty_end_;
	Uml::AssociationRole MonolithicImplementation::meta_dstMonolithExecParameter, MonolithicImplementation::meta_dstMonolithExecParameter_rev;
	Uml::AssociationRole MonolithicImplementation::meta_dstMonolithDeployRequirement, MonolithicImplementation::meta_dstMonolithDeployRequirement_rev;
	Uml::AssociationRole MonolithicImplementation::meta_dstMonolithprimaryArtifact, MonolithicImplementation::meta_dstMonolithprimaryArtifact_rev;
	Uml::AssociationRole MonolithExecParameter::meta_dstMonolithExecParameter_end_;
	Uml::AssociationRole MonolithExecParameter::meta_srcMonolithExecParameter_end_;
	Uml::AssociationRole ImplementationDependsOn::meta_dstImplementationDependsOn_end_;
	Uml::AssociationRole ImplementationDependsOn::meta_srcImplementationDependsOn_end_;
	Uml::AssociationRole Implements::meta_srcImplements_end_;
	Uml::AssociationRole Implements::meta_dstImplements_end_;
	Uml::AssociationRole ImplementationCapability::meta_dstImplementationCapability_end_;
	Uml::AssociationRole ImplementationCapability::meta_srcImplementationCapability_end_;
	Uml::AssociationRole ComponentPropertyDescription::meta_srcComponentProperty, ComponentPropertyDescription::meta_srcComponentProperty_rev;
	Uml::AssociationRole ComponentInfoProperty::meta_dstComponentInfoProperty_end_;
	Uml::AssociationRole ComponentInfoProperty::meta_srcComponentInfoProperty_end_;
	Uml::AssociationRole ComponentProperty::meta_dstComponentProperty_end_;
	Uml::AssociationRole ComponentProperty::meta_srcComponentProperty_end_;
	Uml::AssociationRole ComponentConfigProperty::meta_dstComponentConfigProperty_end_;
	Uml::AssociationRole ComponentConfigProperty::meta_srcComponentConfigProperty_end_;
	Uml::AssociationRole ComponentType::meta_dstComponentConfigProperty, ComponentType::meta_dstComponentConfigProperty_rev;
	Uml::AssociationRole ComponentType::meta_dstComponentInfoProperty, ComponentType::meta_dstComponentInfoProperty_rev;
	Uml::AssociationRole ComponentType::meta_srcPackageInterface, ComponentType::meta_srcPackageInterface_rev;
	Uml::AssociationRole ComponentType::meta_srcImplements, ComponentType::meta_srcImplements_rev;
	Uml::AssociationRole ComponentType::meta_dstComponentProperty, ComponentType::meta_dstComponentProperty_rev;
	Uml::AssociationRole ComponentType::meta_ref;
	Uml::AssociationRole ComponentType::meta_CollocationGroup;
	Uml::AssociationRole SharedResource::meta_srcShares, SharedResource::meta_srcShares_rev;
	Uml::AssociationRole NodeReference::meta_srcInstanceMapping, NodeReference::meta_srcInstanceMapping_rev;
	Uml::AssociationRole NodeReference::meta_ref;
	Uml::AssociationRole Bridge::meta_srcInterconnect2Bridge, Bridge::meta_srcInterconnect2Bridge_rev;
	Uml::AssociationRole Bridge::meta_dstBridge2Interconnect, Bridge::meta_dstBridge2Interconnect_rev;
	Uml::AssociationRole Node::meta_dstShares, Node::meta_dstShares_rev;
	Uml::AssociationRole Node::meta_referedbyNodeReference;
	Uml::AssociationRole Node::meta_dstNode2Interconnect, Node::meta_dstNode2Interconnect_rev;
	Uml::AssociationRole Node::meta_srcInterconnect2Node, Node::meta_srcInterconnect2Node_rev;
	Uml::AssociationRole Interconnect::meta_dstInterconnect2Bridge, Interconnect::meta_dstInterconnect2Bridge_rev;
	Uml::AssociationRole Interconnect::meta_srcBridge2Interconnect, Interconnect::meta_srcBridge2Interconnect_rev;
	Uml::AssociationRole Interconnect::meta_srcNode2Interconnect, Interconnect::meta_srcNode2Interconnect_rev;
	Uml::AssociationRole Interconnect::meta_dstInterconnect2Node, Interconnect::meta_dstInterconnect2Node_rev;
	Uml::AssociationRole Node2Interconnect::meta_srcNode2Interconnect_end_;
	Uml::AssociationRole Node2Interconnect::meta_dstNode2Interconnect_end_;
	Uml::AssociationRole Bridge2Interconnect::meta_srcBridge2Interconnect_end_;
	Uml::AssociationRole Bridge2Interconnect::meta_dstBridge2Interconnect_end_;
	Uml::AssociationRole Shares::meta_dstShares_end_;
	Uml::AssociationRole Shares::meta_srcShares_end_;
	Uml::AssociationRole Interconnect2Node::meta_dstInterconnect2Node_end_;
	Uml::AssociationRole Interconnect2Node::meta_srcInterconnect2Node_end_;
	Uml::AssociationRole Interconnect2Bridge::meta_dstInterconnect2Bridge_end_;
	Uml::AssociationRole Interconnect2Bridge::meta_srcInterconnect2Bridge_end_;
	Uml::AssociationRole InstanceMapping::meta_dstInstanceMapping_end_;
	Uml::AssociationRole InstanceMapping::meta_srcInstanceMapping_end_;
	Uml::AssociationRole CollocationGroup::meta_members;
	Uml::AssociationRole CollocationGroup::meta_dstInstanceMapping, CollocationGroup::meta_dstInstanceMapping_rev;
	Uml::AssociationRole PackageConfigurationReference::meta_srcpackage, PackageConfigurationReference::meta_srcpackage_rev;
	Uml::AssociationRole PackageConfigurationReference::meta_ref;
	Uml::AssociationRole PackageConfigurationReference::meta_srcPackageConfSpecializedConfig, PackageConfigurationReference::meta_srcPackageConfSpecializedConfig_rev;
	Uml::AssociationRole PackageConfConfigProperty::meta_dstPackageConfConfigProperty_end_;
	Uml::AssociationRole PackageConfConfigProperty::meta_srcPackageConfConfigProperty_end_;
	Uml::AssociationRole PackageConfReference::meta_dstPackageConfReference_end_;
	Uml::AssociationRole PackageConfReference::meta_srcPackageConfReference_end_;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageConfConfigProperty, PackageConfiguration::meta_dstPackageConfConfigProperty_rev;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageConfSelectRequirement, PackageConfiguration::meta_dstPackageConfSelectRequirement_rev;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageConfBasePackage, PackageConfiguration::meta_dstPackageConfBasePackage_rev;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageConfReference, PackageConfiguration::meta_dstPackageConfReference_rev;
	Uml::AssociationRole PackageConfiguration::meta_referedbyPackageConfigurationReference;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageConfSpecializedConfig, PackageConfiguration::meta_dstPackageConfSpecializedConfig_rev;
	Uml::AssociationRole PackageConfSpecializedConfig::meta_dstPackageConfSpecializedConfig_end_;
	Uml::AssociationRole PackageConfSpecializedConfig::meta_srcPackageConfSpecializedConfig_end_;
	Uml::AssociationRole PackageConfSelectRequirement::meta_dstPackageConfSelectRequirement_end_;
	Uml::AssociationRole PackageConfSelectRequirement::meta_srcPackageConfSelectRequirement_end_;
	Uml::AssociationRole PackageConfBasePackage::meta_dstPackageConfBasePackage_end_;
	Uml::AssociationRole PackageConfBasePackage::meta_srcPackageConfBasePackage_end_;
	Uml::AssociationRole ArtifactExecParameter::meta_dstArtifactExecParameter_end_;
	Uml::AssociationRole ArtifactExecParameter::meta_srcArtifactExecParameter_end_;
	Uml::AssociationRole ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_;
	Uml::AssociationRole ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactInfoProperty, ImplementationArtifact::meta_dstArtifactInfoProperty_rev;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactExecParameter, ImplementationArtifact::meta_dstArtifactExecParameter_rev;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDeployRequirement, ImplementationArtifact::meta_dstArtifactDeployRequirement_rev;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDependsOn, ImplementationArtifact::meta_dstArtifactDependsOn_rev;
	Uml::AssociationRole ImplementationArtifact::meta_referedbyImplementationArtifactReference;
	Uml::AssociationRole ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_;
	Uml::AssociationRole ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_;
	Uml::AssociationRole ArtifactDependsOn::meta_srcArtifactDependsOn_end_;
	Uml::AssociationRole ArtifactDependsOn::meta_dstArtifactDependsOn_end_;
	Uml::AssociationRole ImplementationArtifactReference::meta_srcMonolithprimaryArtifact, ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev;
	Uml::AssociationRole ImplementationArtifactReference::meta_srcArtifactDependsOn, ImplementationArtifactReference::meta_srcArtifactDependsOn_rev;
	Uml::AssociationRole ImplementationArtifactReference::meta_ref;
	Uml::AssociationRole InParameter::meta_ref;
	Uml::AssociationRole InoutParameter::meta_ref;
	Uml::AssociationRole OutParameter::meta_ref;
	Uml::AssociationRole ReturnType::meta_ref;
	Uml::AssociationRole Exception::meta_referedbySetException;
	Uml::AssociationRole Exception::meta_referedbyExceptionRef;
	Uml::AssociationRole Exception::meta_referedbyGetException;
	Uml::AssociationRole ConstantType::meta_referedbyDiscriminator;
	Uml::AssociationRole ConstantType::meta_referedbyConstant;
	Uml::AssociationRole File::meta_referedbyFileRef;
	Uml::AssociationRole Constant::meta_ref;
	Uml::AssociationRole FileRef::meta_ref;
	Uml::AssociationRole ExceptionRef::meta_ref;
	Uml::AssociationRole Member::meta_ref;
	Uml::AssociationRole Member::meta_dstLabelConnection, Member::meta_dstLabelConnection_rev;
	Uml::AssociationRole Member::meta_dstMakeMemberPrivate, Member::meta_dstMakeMemberPrivate_rev;
	Uml::AssociationRole Boxed::meta_ref;
	Uml::AssociationRole Label::meta_srcLabelConnection, Label::meta_srcLabelConnection_rev;
	Uml::AssociationRole MemberType::meta_referedbyInParameter;
	Uml::AssociationRole MemberType::meta_referedbyInoutParameter;
	Uml::AssociationRole MemberType::meta_referedbyOutParameter;
	Uml::AssociationRole MemberType::meta_referedbyReturnType;
	Uml::AssociationRole MemberType::meta_referedbyMember;
	Uml::AssociationRole MemberType::meta_referedbyBoxed;
	Uml::AssociationRole MemberType::meta_referedbyAlias;
	Uml::AssociationRole MemberType::meta_referedbyCollection;
	Uml::AssociationRole MemberType::meta_referedbyAttributeMember;
	Uml::AssociationRole Alias::meta_ref;
	Uml::AssociationRole Collection::meta_ref;
	Uml::AssociationRole Discriminator::meta_ref;
	Uml::AssociationRole LabelConnection::meta_srcLabelConnection_end_;
	Uml::AssociationRole LabelConnection::meta_dstLabelConnection_end_;
	Uml::AssociationRole PredefinedType::meta_referedbyDataType;
	Uml::AssociationRole SetException::meta_ref;
	Uml::AssociationRole LookupKey::meta_ref;
	Uml::AssociationRole Supports::meta_ref;
	Uml::AssociationRole Inheritable::meta_referedbyInherits;
	Uml::AssociationRole MakeMemberPrivate::meta_srcMakeMemberPrivate_end_;
	Uml::AssociationRole MakeMemberPrivate::meta_dstMakeMemberPrivate_end_;
	Uml::AssociationRole PrivateFlag::meta_srcMakeMemberPrivate, PrivateFlag::meta_srcMakeMemberPrivate_rev;
	Uml::AssociationRole GetException::meta_ref;
	Uml::AssociationRole Inherits::meta_ref;
	Uml::AssociationRole Object::meta_referedbySupports;
	Uml::AssociationRole ValueObject::meta_referedbyLookupKey;
	Uml::AssociationRole Event::meta_referedbyInEventPort;
	Uml::AssociationRole Event::meta_referedbyOutEventPort;
	Uml::AssociationRole AttributeMember::meta_ref;
	Uml::AssociationRole OutEventPort::meta_dstpublish, OutEventPort::meta_dstpublish_rev;
	Uml::AssociationRole OutEventPort::meta_ref;
	Uml::AssociationRole OutEventPort::meta_dstemit, OutEventPort::meta_dstemit_rev;
	Uml::AssociationRole ProvidedRequestPort::meta_srcinvoke, ProvidedRequestPort::meta_srcinvoke_rev;
	Uml::AssociationRole ProvidedRequestPort::meta_ref;
	Uml::AssociationRole Component::meta_dstAssemblyConfigProperty, Component::meta_dstAssemblyConfigProperty_rev;
	Uml::AssociationRole Component::meta_dstAssemblyselectRequirement, Component::meta_dstAssemblyselectRequirement_rev;
	Uml::AssociationRole Component::meta_referedbyComponentType;
	Uml::AssociationRole Component::meta_referedbyComponentRef;
	Uml::AssociationRole RequiredRequestPort::meta_dstinvoke, RequiredRequestPort::meta_dstinvoke_rev;
	Uml::AssociationRole RequiredRequestPort::meta_ref;
	Uml::AssociationRole ManagesComponent::meta_dstManagesComponent_end_;
	Uml::AssociationRole ManagesComponent::meta_srcManagesComponent_end_;
	Uml::AssociationRole InEventPort::meta_srcdeliverTo, InEventPort::meta_srcdeliverTo_rev;
	Uml::AssociationRole InEventPort::meta_ref;
	Uml::AssociationRole InEventPort::meta_srcemit, InEventPort::meta_srcemit_rev;
	Uml::AssociationRole ComponentRef::meta_ref;
	Uml::AssociationRole ComponentFactory::meta_dstManagesComponent, ComponentFactory::meta_dstManagesComponent_rev;
	Uml::AssociationRole Manageable::meta_srcManagesComponent, Manageable::meta_srcManagesComponent_rev;
	Uml::AssociationRole Provideable::meta_referedbyProvidedRequestPort;
	Uml::AssociationRole Provideable::meta_referedbyRequiredRequestPort;
	Uml::CompositionParentRole Property::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole Property::meta_RequirementBase_parent;
	Uml::CompositionParentRole Property::meta_PackageContainer_parent;
	Uml::CompositionParentRole Property::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Property::meta_ComponentContainer_parent;
	Uml::CompositionParentRole Property::meta_Domain_parent;
	Uml::CompositionParentRole Property::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole Property::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ImplementationRequirement::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Requirement::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole Requirement::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole Requirement::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole SatisfierProperty::meta_RequirementSatisfier_parent;
	Uml::CompositionParentRole SatisfierProperty::meta_Resource_parent;
	Uml::CompositionParentRole SatisfierProperty::meta_SharedResource_parent;
	Uml::CompositionParentRole DataType::meta_Property_parent;
	Uml::CompositionParentRole DataType::meta_SatisfierProperty_parent;
	Uml::CompositionParentRole DataType::meta_ComponentPropertyDescription_parent;
	Uml::CompositionParentRole ImplementationDependency::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Capability::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole AssemblyselectRequirement::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole AssemblyConfigProperty::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole PublishConnector::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole publish::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole deliverTo::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole AssemblyDeployRequirement::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole emit::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole invoke::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole package::meta_TopLevelPackageContainer_parent;
	Uml::CompositionParentRole TopLevelPackageFolder::meta_RootFolder_parent;
	Uml::CompositionParentRole TopLevelPackageContainer::meta_TopLevelPackageFolder_parent;
	Uml::CompositionParentRole TopLevelPackage::meta_TopLevelPackageContainer_parent;
	Uml::CompositionParentRole ComponentPackage::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole ComponentPackage::meta_PackageContainer_parent;
	Uml::CompositionParentRole ComponentPackage::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole ComponentPackages::meta_RootFolder_parent;
	Uml::CompositionParentRole ComponentPackageReference::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole ComponentPackageReference::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole Implementation::meta_PackageContainer_parent;
	Uml::CompositionParentRole PackageContainer::meta_ComponentPackages_parent;
	Uml::CompositionParentRole PackageConfigProperty::meta_PackageContainer_parent;
	Uml::CompositionParentRole PackageInfoProperty::meta_PackageContainer_parent;
	Uml::CompositionParentRole PackageInterface::meta_PackageContainer_parent;
	Uml::CompositionParentRole InfoProperty::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole MonolithDeployRequirement::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentImplementation::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentImplementationReference::meta_PackageContainer_parent;
	Uml::CompositionParentRole ConfigProperty::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentImplementationContainer::meta_ComponentImplementations_parent;
	Uml::CompositionParentRole MonolithExecParameter::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ImplementationDependsOn::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Implements::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentImplementations::meta_RootFolder_parent;
	Uml::CompositionParentRole ImplementationCapability::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentContainer::meta_ComponentTypes_parent;
	Uml::CompositionParentRole ComponentPropertyDescription::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentInfoProperty::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentProperty::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentTypes::meta_RootFolder_parent;
	Uml::CompositionParentRole ComponentConfigProperty::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentType::meta_PackageContainer_parent;
	Uml::CompositionParentRole ComponentType::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentType::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentType::meta_DeploymentPlan_parent;
	Uml::CompositionParentRole Resource::meta_Node_parent;
	Uml::CompositionParentRole Resource::meta_Bridge_parent;
	Uml::CompositionParentRole Resource::meta_Interconnect_parent;
	Uml::CompositionParentRole NodeReference::meta_DeploymentPlan_parent;
	Uml::CompositionParentRole Elements::meta_Domain_parent;
	Uml::CompositionParentRole Domain::meta_Targets_parent;
	Uml::CompositionParentRole Targets::meta_RootFolder_parent;
	Uml::CompositionParentRole Node2Interconnect::meta_Domain_parent;
	Uml::CompositionParentRole Bridge2Interconnect::meta_Domain_parent;
	Uml::CompositionParentRole Shares::meta_Domain_parent;
	Uml::CompositionParentRole Interconnect2Node::meta_Domain_parent;
	Uml::CompositionParentRole Interconnect2Bridge::meta_Domain_parent;
	Uml::CompositionParentRole InstanceMapping::meta_DeploymentPlan_parent;
	Uml::CompositionParentRole DeploymentPlan::meta_DeploymentPlans_parent;
	Uml::CompositionParentRole DeploymentPlans::meta_RootFolder_parent;
	Uml::CompositionParentRole CollocationGroup::meta_DeploymentPlan_parent;
	Uml::CompositionParentRole PackageConfigurationReference::meta_TopLevelPackageContainer_parent;
	Uml::CompositionParentRole PackageConfConfigProperty::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageConfigurations::meta_RootFolder_parent;
	Uml::CompositionParentRole PackageConfigurationContainer::meta_PackageConfigurations_parent;
	Uml::CompositionParentRole PackageConfReference::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageConfiguration::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageConfBasePackage::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole ArtifactExecParameter::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ArtifactDeployRequirement::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ImplementationArtifacts::meta_RootFolder_parent;
	Uml::CompositionParentRole ImplementationArtifact::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ArtifactInfoProperty::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ArtifactContainer::meta_ImplementationArtifacts_parent;
	Uml::CompositionParentRole ArtifactDependsOn::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ImplementationArtifactReference::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ImplementationArtifactReference::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole InParameter::meta_OperationBase_parent;
	Uml::CompositionParentRole TwowayOperation::meta_HasOperations_parent;
	Uml::CompositionParentRole OnewayOperation::meta_HasOperations_parent;
	Uml::CompositionParentRole FactoryOperation::meta_ComponentFactory_parent;
	Uml::CompositionParentRole FactoryOperation::meta_ObjectByValue_parent;
	Uml::CompositionParentRole LookupOperation::meta_ComponentFactory_parent;
	Uml::CompositionParentRole InoutParameter::meta_TwowayOperation_parent;
	Uml::CompositionParentRole OutParameter::meta_TwowayOperation_parent;
	Uml::CompositionParentRole ReturnType::meta_TwowayOperation_parent;
	Uml::CompositionParentRole Exception::meta_File_parent;
	Uml::CompositionParentRole Exception::meta_Package_parent;
	Uml::CompositionParentRole Exception::meta_HasOperations_parent;
	Uml::CompositionParentRole Package::meta_Package_parent;
	Uml::CompositionParentRole Package::meta_File_parent;
	Uml::CompositionParentRole File::meta_InterfaceDefinitions_parent;
	Uml::CompositionParentRole Constant::meta_Package_parent;
	Uml::CompositionParentRole Constant::meta_File_parent;
	Uml::CompositionParentRole Constant::meta_HasOperations_parent;
	Uml::CompositionParentRole InterfaceDefinitions::meta_RootFolder_parent;
	Uml::CompositionParentRole FileRef::meta_File_parent;
	Uml::CompositionParentRole ExceptionRef::meta_HasExceptions_parent;
	Uml::CompositionParentRole NoInheritable::meta_HasOperations_parent;
	Uml::CompositionParentRole Member::meta_Exception_parent;
	Uml::CompositionParentRole Member::meta_SwitchedAggregate_parent;
	Uml::CompositionParentRole Member::meta_Aggregate_parent;
	Uml::CompositionParentRole Member::meta_ObjectByValue_parent;
	Uml::CompositionParentRole EnumValue::meta_Enum_parent;
	Uml::CompositionParentRole Label::meta_SwitchedAggregate_parent;
	Uml::CompositionParentRole NamedType::meta_Package_parent;
	Uml::CompositionParentRole NamedType::meta_File_parent;
	Uml::CompositionParentRole Discriminator::meta_SwitchedAggregate_parent;
	Uml::CompositionParentRole LabelConnection::meta_SwitchedAggregate_parent;
	Uml::CompositionParentRole PredefinedType::meta_PredefinedTypes_parent;
	Uml::CompositionParentRole PredefinedTypes::meta_RootFolder_parent;
	Uml::CompositionParentRole SetException::meta_Attribute_parent;
	Uml::CompositionParentRole LookupKey::meta_ComponentFactory_parent;
	Uml::CompositionParentRole ReadonlyAttribute::meta_Inheritable_parent;
	Uml::CompositionParentRole Supports::meta_SupportsInterfaces_parent;
	Uml::CompositionParentRole MakeMemberPrivate::meta_ObjectByValue_parent;
	Uml::CompositionParentRole PrivateFlag::meta_ObjectByValue_parent;
	Uml::CompositionParentRole GetException::meta_ReadonlyAttribute_parent;
	Uml::CompositionParentRole Inherits::meta_Inheritable_parent;
	Uml::CompositionParentRole AttributeMember::meta_ReadonlyAttribute_parent;
	Uml::CompositionParentRole Component::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole ManagesComponent::meta_Package_parent;
	Uml::CompositionParentRole ManagesComponent::meta_File_parent;
	Uml::CompositionParentRole Port::meta_Component_parent;
	Uml::CompositionParentRole ComponentRef::meta_Package_parent;
	Uml::CompositionParentRole ComponentRef::meta_File_parent;
	Uml::CompositionParentRole RootFolder::meta_RootFolder_parent;
	Uml::CompositionChildRole Property::meta_DataType_child;
	Uml::CompositionChildRole RequirementSatisfier::meta_SatisfierProperty_children;
	Uml::CompositionChildRole RequirementBase::meta_Property_children;
	Uml::CompositionChildRole SatisfierProperty::meta_DataType_child;
	Uml::CompositionChildRole ComponentAssembly::meta_ComponentPackage_children;
	Uml::CompositionChildRole ComponentAssembly::meta_ComponentPackageReference_children;
	Uml::CompositionChildRole ComponentAssembly::meta_invoke_children;
	Uml::CompositionChildRole ComponentAssembly::meta_AssemblyConfigProperty_children;
	Uml::CompositionChildRole ComponentAssembly::meta_emit_children;
	Uml::CompositionChildRole ComponentAssembly::meta_Component_children;
	Uml::CompositionChildRole ComponentAssembly::meta_AssemblyDeployRequirement_children;
	Uml::CompositionChildRole ComponentAssembly::meta_Requirement_children;
	Uml::CompositionChildRole ComponentAssembly::meta_publish_children;
	Uml::CompositionChildRole ComponentAssembly::meta_PublishConnector_children;
	Uml::CompositionChildRole ComponentAssembly::meta_AssemblyselectRequirement_children;
	Uml::CompositionChildRole ComponentAssembly::meta_Property_children;
	Uml::CompositionChildRole ComponentAssembly::meta_deliverTo_children;
	Uml::CompositionChildRole TopLevelPackageFolder::meta_TopLevelPackageContainer_children;
	Uml::CompositionChildRole TopLevelPackageContainer::meta_PackageConfigurationReference_child;
	Uml::CompositionChildRole TopLevelPackageContainer::meta_package_child;
	Uml::CompositionChildRole TopLevelPackageContainer::meta_TopLevelPackage_child;
	Uml::CompositionChildRole ComponentPackages::meta_PackageContainer_children;
	Uml::CompositionChildRole PackageContainer::meta_PackageInfoProperty_children;
	Uml::CompositionChildRole PackageContainer::meta_Property_children;
	Uml::CompositionChildRole PackageContainer::meta_ComponentImplementationReference_children;
	Uml::CompositionChildRole PackageContainer::meta_PackageConfigProperty_children;
	Uml::CompositionChildRole PackageContainer::meta_ComponentPackage_child;
	Uml::CompositionChildRole PackageContainer::meta_ComponentType_children;
	Uml::CompositionChildRole PackageContainer::meta_PackageInterface_child;
	Uml::CompositionChildRole PackageContainer::meta_Implementation_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_Capability_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_InfoProperty_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ComponentType_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationDependency_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_MonolithDeployRequirement_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ConfigProperty_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_MonolithExecParameter_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ComponentImplementation_child;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationDependsOn_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_Implements_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_MonolithprimaryArtifact_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationCapability_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_Property_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationArtifactReference_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationRequirement_children;
	Uml::CompositionChildRole ComponentImplementations::meta_ComponentImplementationContainer_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentProperty_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentInfoProperty_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentPropertyDescription_children;
	Uml::CompositionChildRole ComponentContainer::meta_Property_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentConfigProperty_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentType_child;
	Uml::CompositionChildRole ComponentPropertyDescription::meta_DataType_child;
	Uml::CompositionChildRole ComponentTypes::meta_ComponentContainer_children;
	Uml::CompositionChildRole Resource::meta_SatisfierProperty_children;
	Uml::CompositionChildRole SharedResource::meta_SatisfierProperty_children;
	Uml::CompositionChildRole Bridge::meta_Resource_children;
	Uml::CompositionChildRole Node::meta_Resource_children;
	Uml::CompositionChildRole Interconnect::meta_Resource_children;
	Uml::CompositionChildRole Domain::meta_Property_children;
	Uml::CompositionChildRole Domain::meta_Elements_children;
	Uml::CompositionChildRole Domain::meta_Shares_children;
	Uml::CompositionChildRole Domain::meta_Interconnect2Node_children;
	Uml::CompositionChildRole Domain::meta_Node2Interconnect_children;
	Uml::CompositionChildRole Domain::meta_Interconnect2Bridge_children;
	Uml::CompositionChildRole Domain::meta_Bridge2Interconnect_children;
	Uml::CompositionChildRole Targets::meta_Domain_children;
	Uml::CompositionChildRole DeploymentPlan::meta_NodeReference_children;
	Uml::CompositionChildRole DeploymentPlan::meta_CollocationGroup_children;
	Uml::CompositionChildRole DeploymentPlan::meta_ComponentType_children;
	Uml::CompositionChildRole DeploymentPlan::meta_InstanceMapping_children;
	Uml::CompositionChildRole DeploymentPlans::meta_DeploymentPlan_children;
	Uml::CompositionChildRole PackageConfigurations::meta_PackageConfigurationContainer_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_ComponentPackageReference_child;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfiguration_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfConfigProperty_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfReference_child;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfBasePackage_child;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_Requirement_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_ComponentPackage_child;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_Property_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfSelectRequirement_children;
	Uml::CompositionChildRole ImplementationArtifacts::meta_ArtifactContainer_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ImplementationArtifactReference_children;
	Uml::CompositionChildRole ArtifactContainer::meta_Property_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactDeployRequirement_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactExecParameter_children;
	Uml::CompositionChildRole ArtifactContainer::meta_Requirement_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactInfoProperty_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactDependsOn_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ImplementationArtifact_children;
	Uml::CompositionChildRole TwowayOperation::meta_OutParameter_children;
	Uml::CompositionChildRole TwowayOperation::meta_ReturnType_child;
	Uml::CompositionChildRole TwowayOperation::meta_InoutParameter_children;
	Uml::CompositionChildRole HasExceptions::meta_ExceptionRef_children;
	Uml::CompositionChildRole OperationBase::meta_InParameter_children;
	Uml::CompositionChildRole Exception::meta_Member_children;
	Uml::CompositionChildRole Package::meta_Package_children;
	Uml::CompositionChildRole Package::meta_ComponentRef_children;
	Uml::CompositionChildRole Package::meta_ManagesComponent_children;
	Uml::CompositionChildRole Package::meta_NamedType_children;
	Uml::CompositionChildRole Package::meta_Constant_children;
	Uml::CompositionChildRole Package::meta_Exception_children;
	Uml::CompositionChildRole File::meta_ComponentRef_children;
	Uml::CompositionChildRole File::meta_ManagesComponent_children;
	Uml::CompositionChildRole File::meta_FileRef_children;
	Uml::CompositionChildRole File::meta_NamedType_children;
	Uml::CompositionChildRole File::meta_Constant_children;
	Uml::CompositionChildRole File::meta_Exception_children;
	Uml::CompositionChildRole File::meta_Package_children;
	Uml::CompositionChildRole InterfaceDefinitions::meta_File_children;
	Uml::CompositionChildRole SwitchedAggregate::meta_LabelConnection_children;
	Uml::CompositionChildRole SwitchedAggregate::meta_Label_children;
	Uml::CompositionChildRole SwitchedAggregate::meta_Member_children;
	Uml::CompositionChildRole SwitchedAggregate::meta_Discriminator_child;
	Uml::CompositionChildRole Aggregate::meta_Member_children;
	Uml::CompositionChildRole Enum::meta_EnumValue_children;
	Uml::CompositionChildRole PredefinedTypes::meta_PredefinedType_children;
	Uml::CompositionChildRole Attribute::meta_SetException_children;
	Uml::CompositionChildRole ReadonlyAttribute::meta_AttributeMember_child;
	Uml::CompositionChildRole ReadonlyAttribute::meta_GetException_children;
	Uml::CompositionChildRole SupportsInterfaces::meta_Supports_children;
	Uml::CompositionChildRole HasOperations::meta_OnewayOperation_children;
	Uml::CompositionChildRole HasOperations::meta_TwowayOperation_children;
	Uml::CompositionChildRole HasOperations::meta_NoInheritable_children;
	Uml::CompositionChildRole HasOperations::meta_Constant_children;
	Uml::CompositionChildRole HasOperations::meta_Exception_children;
	Uml::CompositionChildRole Inheritable::meta_Inherits_children;
	Uml::CompositionChildRole Inheritable::meta_ReadonlyAttribute_children;
	Uml::CompositionChildRole ObjectByValue::meta_PrivateFlag_children;
	Uml::CompositionChildRole ObjectByValue::meta_MakeMemberPrivate_children;
	Uml::CompositionChildRole ObjectByValue::meta_FactoryOperation_children;
	Uml::CompositionChildRole ObjectByValue::meta_Member_children;
	Uml::CompositionChildRole Component::meta_Port_children;
	Uml::CompositionChildRole ComponentFactory::meta_LookupOperation_children;
	Uml::CompositionChildRole ComponentFactory::meta_FactoryOperation_children;
	Uml::CompositionChildRole ComponentFactory::meta_LookupKey_child;
	Uml::CompositionChildRole RootFolder::meta_ComponentPackages_children;
	Uml::CompositionChildRole RootFolder::meta_TopLevelPackageFolder_children;
	Uml::CompositionChildRole RootFolder::meta_ComponentImplementations_children;
	Uml::CompositionChildRole RootFolder::meta_ComponentTypes_children;
	Uml::CompositionChildRole RootFolder::meta_Targets_children;
	Uml::CompositionChildRole RootFolder::meta_DeploymentPlans_children;
	Uml::CompositionChildRole RootFolder::meta_PackageConfigurations_children;
	Uml::CompositionChildRole RootFolder::meta_ImplementationArtifacts_children;
	Uml::CompositionChildRole RootFolder::meta_InterfaceDefinitions_children;
	Uml::CompositionChildRole RootFolder::meta_PredefinedTypes_children;
	Uml::CompositionChildRole RootFolder::meta_RootFolder_children;
	 void Initialize()
	{
		static bool first = true;
		if(!first) return;
		first = false;
		Uml::Initialize();

		ASSERT( umldiagram == Udm::null );
		umldiagram = Uml::CreateDiagram();

		Property::meta = Uml::CreateClass();
		ImplementationRequirement::meta = Uml::CreateClass();
		Requirement::meta = Uml::CreateClass();
		RequirementSatisfier::meta = Uml::CreateClass();
		RequirementBase::meta = Uml::CreateClass();
		SatisfierProperty::meta = Uml::CreateClass();
		DataType::meta = Uml::CreateClass();
		ImplementationDependency::meta = Uml::CreateClass();
		Capability::meta = Uml::CreateClass();
		AssemblyselectRequirement::meta = Uml::CreateClass();
		AssemblyConfigProperty::meta = Uml::CreateClass();
		PublishConnector::meta = Uml::CreateClass();
		publish::meta = Uml::CreateClass();
		deliverTo::meta = Uml::CreateClass();
		AssemblyDeployRequirement::meta = Uml::CreateClass();
		ComponentAssembly::meta = Uml::CreateClass();
		emit::meta = Uml::CreateClass();
		invoke::meta = Uml::CreateClass();
		package::meta = Uml::CreateClass();
		TopLevelPackageFolder::meta = Uml::CreateClass();
		TopLevelPackageContainer::meta = Uml::CreateClass();
		TopLevelPackage::meta = Uml::CreateClass();
		ComponentPackage::meta = Uml::CreateClass();
		ComponentPackages::meta = Uml::CreateClass();
		ComponentPackageReference::meta = Uml::CreateClass();
		Implementation::meta = Uml::CreateClass();
		PackageContainer::meta = Uml::CreateClass();
		PackageConfigProperty::meta = Uml::CreateClass();
		PackageInfoProperty::meta = Uml::CreateClass();
		PackageInterface::meta = Uml::CreateClass();
		InfoProperty::meta = Uml::CreateClass();
		MonolithprimaryArtifact::meta = Uml::CreateClass();
		MonolithDeployRequirement::meta = Uml::CreateClass();
		ComponentImplementation::meta = Uml::CreateClass();
		ComponentImplementationReference::meta = Uml::CreateClass();
		ConfigProperty::meta = Uml::CreateClass();
		ComponentImplementationContainer::meta = Uml::CreateClass();
		MonolithicImplementation::meta = Uml::CreateClass();
		MonolithExecParameter::meta = Uml::CreateClass();
		ImplementationDependsOn::meta = Uml::CreateClass();
		Implements::meta = Uml::CreateClass();
		ComponentImplementations::meta = Uml::CreateClass();
		ImplementationCapability::meta = Uml::CreateClass();
		ComponentContainer::meta = Uml::CreateClass();
		ComponentPropertyDescription::meta = Uml::CreateClass();
		ComponentInfoProperty::meta = Uml::CreateClass();
		ComponentProperty::meta = Uml::CreateClass();
		CommonPortAttrs::meta = Uml::CreateClass();
		ComponentTypes::meta = Uml::CreateClass();
		ComponentConfigProperty::meta = Uml::CreateClass();
		ComponentType::meta = Uml::CreateClass();
		Resource::meta = Uml::CreateClass();
		SharedResource::meta = Uml::CreateClass();
		NodeReference::meta = Uml::CreateClass();
		Bridge::meta = Uml::CreateClass();
		Node::meta = Uml::CreateClass();
		Interconnect::meta = Uml::CreateClass();
		Elements::meta = Uml::CreateClass();
		Domain::meta = Uml::CreateClass();
		Targets::meta = Uml::CreateClass();
		Node2Interconnect::meta = Uml::CreateClass();
		Bridge2Interconnect::meta = Uml::CreateClass();
		Shares::meta = Uml::CreateClass();
		Interconnect2Node::meta = Uml::CreateClass();
		Interconnect2Bridge::meta = Uml::CreateClass();
		InstanceMapping::meta = Uml::CreateClass();
		DeploymentPlan::meta = Uml::CreateClass();
		DeploymentPlans::meta = Uml::CreateClass();
		CollocationGroup::meta = Uml::CreateClass();
		PackageConfigurationReference::meta = Uml::CreateClass();
		PackageConfConfigProperty::meta = Uml::CreateClass();
		PackageConfigurations::meta = Uml::CreateClass();
		PackageConfigurationContainer::meta = Uml::CreateClass();
		PackageConfReference::meta = Uml::CreateClass();
		PackageConfiguration::meta = Uml::CreateClass();
		PackageConfSpecializedConfig::meta = Uml::CreateClass();
		PackageConfSelectRequirement::meta = Uml::CreateClass();
		PackageConfBasePackage::meta = Uml::CreateClass();
		ArtifactExecParameter::meta = Uml::CreateClass();
		ArtifactDeployRequirement::meta = Uml::CreateClass();
		ImplementationArtifacts::meta = Uml::CreateClass();
		ImplementationArtifact::meta = Uml::CreateClass();
		ArtifactInfoProperty::meta = Uml::CreateClass();
		ArtifactContainer::meta = Uml::CreateClass();
		ArtifactDependsOn::meta = Uml::CreateClass();
		ImplementationArtifactReference::meta = Uml::CreateClass();
		InParameter::meta = Uml::CreateClass();
		TwowayOperation::meta = Uml::CreateClass();
		OnewayOperation::meta = Uml::CreateClass();
		HasExceptions::meta = Uml::CreateClass();
		OperationBase::meta = Uml::CreateClass();
		FactoryOperation::meta = Uml::CreateClass();
		LookupOperation::meta = Uml::CreateClass();
		InoutParameter::meta = Uml::CreateClass();
		OutParameter::meta = Uml::CreateClass();
		ReturnType::meta = Uml::CreateClass();
		Exception::meta = Uml::CreateClass();
		Package::meta = Uml::CreateClass();
		ConstantType::meta = Uml::CreateClass();
		File::meta = Uml::CreateClass();
		Constant::meta = Uml::CreateClass();
		InterfaceDefinitions::meta = Uml::CreateClass();
		FileRef::meta = Uml::CreateClass();
		ExceptionRef::meta = Uml::CreateClass();
		SwitchedAggregate::meta = Uml::CreateClass();
		NoInheritable::meta = Uml::CreateClass();
		Member::meta = Uml::CreateClass();
		Boxed::meta = Uml::CreateClass();
		EnumValue::meta = Uml::CreateClass();
		Label::meta = Uml::CreateClass();
		MemberType::meta = Uml::CreateClass();
		Aggregate::meta = Uml::CreateClass();
		Alias::meta = Uml::CreateClass();
		Collection::meta = Uml::CreateClass();
		NamedType::meta = Uml::CreateClass();
		Discriminator::meta = Uml::CreateClass();
		Enum::meta = Uml::CreateClass();
		LabelConnection::meta = Uml::CreateClass();
		Prefixable::meta = Uml::CreateClass();
		Taggable::meta = Uml::CreateClass();
		PredefinedType::meta = Uml::CreateClass();
		Boolean::meta = Uml::CreateClass();
		GenericValue::meta = Uml::CreateClass();
		LongInteger::meta = Uml::CreateClass();
		Byte::meta = Uml::CreateClass();
		TypeKind::meta = Uml::CreateClass();
		GenericObject::meta = Uml::CreateClass();
		ShortInteger::meta = Uml::CreateClass();
		RealNumber::meta = Uml::CreateClass();
		PredefinedTypes::meta = Uml::CreateClass();
		String::meta = Uml::CreateClass();
		TypeEncoding::meta = Uml::CreateClass();
		GenericValueObject::meta = Uml::CreateClass();
		SetException::meta = Uml::CreateClass();
		LookupKey::meta = Uml::CreateClass();
		Attribute::meta = Uml::CreateClass();
		ReadonlyAttribute::meta = Uml::CreateClass();
		Supports::meta = Uml::CreateClass();
		SupportsInterfaces::meta = Uml::CreateClass();
		HasOperations::meta = Uml::CreateClass();
		Inheritable::meta = Uml::CreateClass();
		MakeMemberPrivate::meta = Uml::CreateClass();
		PrivateFlag::meta = Uml::CreateClass();
		GetException::meta = Uml::CreateClass();
		ObjectByValue::meta = Uml::CreateClass();
		Inherits::meta = Uml::CreateClass();
		Object::meta = Uml::CreateClass();
		ValueObject::meta = Uml::CreateClass();
		Event::meta = Uml::CreateClass();
		AttributeMember::meta = Uml::CreateClass();
		OutEventPort::meta = Uml::CreateClass();
		ProvidedRequestPort::meta = Uml::CreateClass();
		Component::meta = Uml::CreateClass();
		RequiredRequestPort::meta = Uml::CreateClass();
		ManagesComponent::meta = Uml::CreateClass();
		InEventPort::meta = Uml::CreateClass();
		Port::meta = Uml::CreateClass();
		ComponentRef::meta = Uml::CreateClass();
		ComponentFactory::meta = Uml::CreateClass();
		Manageable::meta = Uml::CreateClass();
		Provideable::meta = Uml::CreateClass();
		RootFolder::meta = Uml::CreateClass();
		MgaObject::meta = Uml::CreateClass();
		Property::meta_DataValue = Uml::CreateAttribute();
		ImplementationRequirement::meta_ResourceUsageKind = Uml::CreateAttribute();
		ImplementationRequirement::meta_componentPort = Uml::CreateAttribute();
		ImplementationRequirement::meta_resourcePort = Uml::CreateAttribute();
		RequirementSatisfier::meta_resourceType = Uml::CreateAttribute();
		RequirementBase::meta_resourceType = Uml::CreateAttribute();
		SatisfierProperty::meta_DataValue = Uml::CreateAttribute();
		SatisfierProperty::meta_SatisfierPropertyKind = Uml::CreateAttribute();
		ImplementationDependency::meta_requiredType = Uml::CreateAttribute();
		TopLevelPackageFolder::meta_name = Uml::CreateAttribute();
		ComponentPackage::meta_UUID = Uml::CreateAttribute();
		ComponentPackage::meta_label = Uml::CreateAttribute();
		ComponentPackages::meta_name = Uml::CreateAttribute();
		ComponentPackageReference::meta_requiredName = Uml::CreateAttribute();
		ComponentPackageReference::meta_requiredUUID = Uml::CreateAttribute();
		ComponentPackageReference::meta_requiredType = Uml::CreateAttribute();
		ComponentImplementation::meta_UUID = Uml::CreateAttribute();
		ComponentImplementation::meta_label = Uml::CreateAttribute();
		ComponentImplementations::meta_name = Uml::CreateAttribute();
		CommonPortAttrs::meta_exclusiveUser = Uml::CreateAttribute();
		CommonPortAttrs::meta_optional = Uml::CreateAttribute();
		CommonPortAttrs::meta_exclusiveProvider = Uml::CreateAttribute();
		ComponentTypes::meta_name = Uml::CreateAttribute();
		Resource::meta_resourceType = Uml::CreateAttribute();
		SharedResource::meta_resourceType = Uml::CreateAttribute();
		Bridge::meta_label = Uml::CreateAttribute();
		Node::meta_label = Uml::CreateAttribute();
		Interconnect::meta_label = Uml::CreateAttribute();
		Domain::meta_label = Uml::CreateAttribute();
		Domain::meta_UUID = Uml::CreateAttribute();
		Targets::meta_name = Uml::CreateAttribute();
		DeploymentPlan::meta_label = Uml::CreateAttribute();
		DeploymentPlans::meta_name = Uml::CreateAttribute();
		PackageConfigurations::meta_name = Uml::CreateAttribute();
		PackageConfiguration::meta_UUID = Uml::CreateAttribute();
		PackageConfiguration::meta_label = Uml::CreateAttribute();
		ImplementationArtifacts::meta_name = Uml::CreateAttribute();
		ImplementationArtifact::meta_UUID = Uml::CreateAttribute();
		ImplementationArtifact::meta_label = Uml::CreateAttribute();
		ImplementationArtifact::meta_location = Uml::CreateAttribute();
		Constant::meta_value = Uml::CreateAttribute();
		InterfaceDefinitions::meta_name = Uml::CreateAttribute();
		Prefixable::meta_PrefixTag = Uml::CreateAttribute();
		Taggable::meta_VersionTag = Uml::CreateAttribute();
		Taggable::meta_SpecifyIdTag = Uml::CreateAttribute();
		PredefinedTypes::meta_name = Uml::CreateAttribute();
		ObjectByValue::meta_abstract = Uml::CreateAttribute();
		Object::meta_abstract = Uml::CreateAttribute();
		Object::meta_local = Uml::CreateAttribute();
		OutEventPort::meta_single_destination = Uml::CreateAttribute();
		Component::meta_UUID = Uml::CreateAttribute();
		Component::meta_label = Uml::CreateAttribute();
		RequiredRequestPort::meta_multiple_connections = Uml::CreateAttribute();
		RootFolder::meta_name = Uml::CreateAttribute();
		MgaObject::meta_position = Uml::CreateAttribute();
		MgaObject::meta_name = Uml::CreateAttribute();
		Property::meta_srcPackageConfigProperty = Uml::CreateAssociationRole();
		Property::meta_srcPackageInfoProperty = Uml::CreateAssociationRole();
		Property::meta_srcConfigProperty = Uml::CreateAssociationRole();
		Property::meta_srcInfoProperty = Uml::CreateAssociationRole();
		Property::meta_srcMonolithExecParameter = Uml::CreateAssociationRole();
		Property::meta_srcComponentConfigProperty = Uml::CreateAssociationRole();
		Property::meta_srcComponentInfoProperty = Uml::CreateAssociationRole();
		Property::meta_srcPackageConfConfigProperty = Uml::CreateAssociationRole();
		Property::meta_srcArtifactInfoProperty = Uml::CreateAssociationRole();
		Property::meta_srcArtifactExecParameter = Uml::CreateAssociationRole();
		Property::meta_srcAssemblyConfigProperty = Uml::CreateAssociationRole();
		ImplementationRequirement::meta_srcMonolithDeployRequirement = Uml::CreateAssociationRole();
		Requirement::meta_srcPackageConfSelectRequirement = Uml::CreateAssociationRole();
		Requirement::meta_srcAssemblyDeployRequirement = Uml::CreateAssociationRole();
		Requirement::meta_srcArtifactDeployRequirement = Uml::CreateAssociationRole();
		Requirement::meta_srcAssemblyselectRequirement = Uml::CreateAssociationRole();
		DataType::meta_ref = Uml::CreateAssociationRole();
		ImplementationDependency::meta_srcImplementationDependsOn = Uml::CreateAssociationRole();
		Capability::meta_srcImplementationCapability = Uml::CreateAssociationRole();
		PublishConnector::meta_dstAssemblyDeployRequirement = Uml::CreateAssociationRole();
		PublishConnector::meta_dstdeliverTo = Uml::CreateAssociationRole();
		PublishConnector::meta_srcpublish = Uml::CreateAssociationRole();
		TopLevelPackage::meta_dstpackage = Uml::CreateAssociationRole();
		ComponentPackage::meta_dstPackageConfigProperty = Uml::CreateAssociationRole();
		ComponentPackage::meta_dstPackageInfoProperty = Uml::CreateAssociationRole();
		ComponentPackage::meta_dstPackageInterface = Uml::CreateAssociationRole();
		ComponentPackage::meta_dstImplementation = Uml::CreateAssociationRole();
		ComponentPackage::meta_referedbyComponentPackageReference = Uml::CreateAssociationRole();
		ComponentPackage::meta_srcPackageConfBasePackage = Uml::CreateAssociationRole();
		ComponentPackageReference::meta_ref = Uml::CreateAssociationRole();
		ComponentPackageReference::meta_srcPackageConfReference = Uml::CreateAssociationRole();
		ComponentImplementation::meta_dstConfigProperty = Uml::CreateAssociationRole();
		ComponentImplementation::meta_dstInfoProperty = Uml::CreateAssociationRole();
		ComponentImplementation::meta_dstImplementationDependsOn = Uml::CreateAssociationRole();
		ComponentImplementation::meta_dstImplementationCapability = Uml::CreateAssociationRole();
		ComponentImplementation::meta_dstImplements = Uml::CreateAssociationRole();
		ComponentImplementation::meta_referedbyComponentImplementationReference = Uml::CreateAssociationRole();
		ComponentImplementationReference::meta_srcImplementation = Uml::CreateAssociationRole();
		ComponentImplementationReference::meta_ref = Uml::CreateAssociationRole();
		MonolithicImplementation::meta_dstMonolithExecParameter = Uml::CreateAssociationRole();
		MonolithicImplementation::meta_dstMonolithDeployRequirement = Uml::CreateAssociationRole();
		MonolithicImplementation::meta_dstMonolithprimaryArtifact = Uml::CreateAssociationRole();
		ComponentPropertyDescription::meta_srcComponentProperty = Uml::CreateAssociationRole();
		ComponentType::meta_dstComponentConfigProperty = Uml::CreateAssociationRole();
		ComponentType::meta_dstComponentInfoProperty = Uml::CreateAssociationRole();
		ComponentType::meta_srcPackageInterface = Uml::CreateAssociationRole();
		ComponentType::meta_srcImplements = Uml::CreateAssociationRole();
		ComponentType::meta_dstComponentProperty = Uml::CreateAssociationRole();
		ComponentType::meta_ref = Uml::CreateAssociationRole();
		ComponentType::meta_CollocationGroup = Uml::CreateAssociationRole();
		SharedResource::meta_srcShares = Uml::CreateAssociationRole();
		NodeReference::meta_srcInstanceMapping = Uml::CreateAssociationRole();
		NodeReference::meta_ref = Uml::CreateAssociationRole();
		Bridge::meta_srcInterconnect2Bridge = Uml::CreateAssociationRole();
		Bridge::meta_dstBridge2Interconnect = Uml::CreateAssociationRole();
		Node::meta_dstShares = Uml::CreateAssociationRole();
		Node::meta_referedbyNodeReference = Uml::CreateAssociationRole();
		Node::meta_dstNode2Interconnect = Uml::CreateAssociationRole();
		Node::meta_srcInterconnect2Node = Uml::CreateAssociationRole();
		Interconnect::meta_dstInterconnect2Bridge = Uml::CreateAssociationRole();
		Interconnect::meta_srcBridge2Interconnect = Uml::CreateAssociationRole();
		Interconnect::meta_srcNode2Interconnect = Uml::CreateAssociationRole();
		Interconnect::meta_dstInterconnect2Node = Uml::CreateAssociationRole();
		CollocationGroup::meta_members = Uml::CreateAssociationRole();
		CollocationGroup::meta_dstInstanceMapping = Uml::CreateAssociationRole();
		PackageConfigurationReference::meta_srcpackage = Uml::CreateAssociationRole();
		PackageConfigurationReference::meta_ref = Uml::CreateAssociationRole();
		PackageConfigurationReference::meta_srcPackageConfSpecializedConfig = Uml::CreateAssociationRole();
		PackageConfiguration::meta_dstPackageConfConfigProperty = Uml::CreateAssociationRole();
		PackageConfiguration::meta_dstPackageConfSelectRequirement = Uml::CreateAssociationRole();
		PackageConfiguration::meta_dstPackageConfBasePackage = Uml::CreateAssociationRole();
		PackageConfiguration::meta_dstPackageConfReference = Uml::CreateAssociationRole();
		PackageConfiguration::meta_referedbyPackageConfigurationReference = Uml::CreateAssociationRole();
		PackageConfiguration::meta_dstPackageConfSpecializedConfig = Uml::CreateAssociationRole();
		ImplementationArtifact::meta_dstArtifactInfoProperty = Uml::CreateAssociationRole();
		ImplementationArtifact::meta_dstArtifactExecParameter = Uml::CreateAssociationRole();
		ImplementationArtifact::meta_dstArtifactDeployRequirement = Uml::CreateAssociationRole();
		ImplementationArtifact::meta_dstArtifactDependsOn = Uml::CreateAssociationRole();
		ImplementationArtifact::meta_referedbyImplementationArtifactReference = Uml::CreateAssociationRole();
		ImplementationArtifactReference::meta_srcMonolithprimaryArtifact = Uml::CreateAssociationRole();
		ImplementationArtifactReference::meta_srcArtifactDependsOn = Uml::CreateAssociationRole();
		ImplementationArtifactReference::meta_ref = Uml::CreateAssociationRole();
		InParameter::meta_ref = Uml::CreateAssociationRole();
		InoutParameter::meta_ref = Uml::CreateAssociationRole();
		OutParameter::meta_ref = Uml::CreateAssociationRole();
		ReturnType::meta_ref = Uml::CreateAssociationRole();
		Exception::meta_referedbySetException = Uml::CreateAssociationRole();
		Exception::meta_referedbyExceptionRef = Uml::CreateAssociationRole();
		Exception::meta_referedbyGetException = Uml::CreateAssociationRole();
		ConstantType::meta_referedbyDiscriminator = Uml::CreateAssociationRole();
		ConstantType::meta_referedbyConstant = Uml::CreateAssociationRole();
		File::meta_referedbyFileRef = Uml::CreateAssociationRole();
		Constant::meta_ref = Uml::CreateAssociationRole();
		FileRef::meta_ref = Uml::CreateAssociationRole();
		ExceptionRef::meta_ref = Uml::CreateAssociationRole();
		Member::meta_ref = Uml::CreateAssociationRole();
		Member::meta_dstLabelConnection = Uml::CreateAssociationRole();
		Member::meta_dstMakeMemberPrivate = Uml::CreateAssociationRole();
		Boxed::meta_ref = Uml::CreateAssociationRole();
		Label::meta_srcLabelConnection = Uml::CreateAssociationRole();
		MemberType::meta_referedbyInParameter = Uml::CreateAssociationRole();
		MemberType::meta_referedbyInoutParameter = Uml::CreateAssociationRole();
		MemberType::meta_referedbyOutParameter = Uml::CreateAssociationRole();
		MemberType::meta_referedbyReturnType = Uml::CreateAssociationRole();
		MemberType::meta_referedbyMember = Uml::CreateAssociationRole();
		MemberType::meta_referedbyBoxed = Uml::CreateAssociationRole();
		MemberType::meta_referedbyAlias = Uml::CreateAssociationRole();
		MemberType::meta_referedbyCollection = Uml::CreateAssociationRole();
		MemberType::meta_referedbyAttributeMember = Uml::CreateAssociationRole();
		Alias::meta_ref = Uml::CreateAssociationRole();
		Collection::meta_ref = Uml::CreateAssociationRole();
		Discriminator::meta_ref = Uml::CreateAssociationRole();
		PredefinedType::meta_referedbyDataType = Uml::CreateAssociationRole();
		SetException::meta_ref = Uml::CreateAssociationRole();
		LookupKey::meta_ref = Uml::CreateAssociationRole();
		Supports::meta_ref = Uml::CreateAssociationRole();
		Inheritable::meta_referedbyInherits = Uml::CreateAssociationRole();
		PrivateFlag::meta_srcMakeMemberPrivate = Uml::CreateAssociationRole();
		GetException::meta_ref = Uml::CreateAssociationRole();
		Inherits::meta_ref = Uml::CreateAssociationRole();
		Object::meta_referedbySupports = Uml::CreateAssociationRole();
		ValueObject::meta_referedbyLookupKey = Uml::CreateAssociationRole();
		Event::meta_referedbyInEventPort = Uml::CreateAssociationRole();
		Event::meta_referedbyOutEventPort = Uml::CreateAssociationRole();
		AttributeMember::meta_ref = Uml::CreateAssociationRole();
		OutEventPort::meta_dstpublish = Uml::CreateAssociationRole();
		OutEventPort::meta_ref = Uml::CreateAssociationRole();
		OutEventPort::meta_dstemit = Uml::CreateAssociationRole();
		ProvidedRequestPort::meta_srcinvoke = Uml::CreateAssociationRole();
		ProvidedRequestPort::meta_ref = Uml::CreateAssociationRole();
		Component::meta_dstAssemblyConfigProperty = Uml::CreateAssociationRole();
		Component::meta_dstAssemblyselectRequirement = Uml::CreateAssociationRole();
		Component::meta_referedbyComponentType = Uml::CreateAssociationRole();
		Component::meta_referedbyComponentRef = Uml::CreateAssociationRole();
		RequiredRequestPort::meta_dstinvoke = Uml::CreateAssociationRole();
		RequiredRequestPort::meta_ref = Uml::CreateAssociationRole();
		InEventPort::meta_srcdeliverTo = Uml::CreateAssociationRole();
		InEventPort::meta_ref = Uml::CreateAssociationRole();
		InEventPort::meta_srcemit = Uml::CreateAssociationRole();
		ComponentRef::meta_ref = Uml::CreateAssociationRole();
		ComponentFactory::meta_dstManagesComponent = Uml::CreateAssociationRole();
		Manageable::meta_srcManagesComponent = Uml::CreateAssociationRole();
		Provideable::meta_referedbyProvidedRequestPort = Uml::CreateAssociationRole();
		Provideable::meta_referedbyRequiredRequestPort = Uml::CreateAssociationRole();
		Property::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		Property::meta_RequirementBase_parent = Uml::CreateCompositionParentRole();
		Property::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		Property::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		Property::meta_ComponentContainer_parent = Uml::CreateCompositionParentRole();
		Property::meta_Domain_parent = Uml::CreateCompositionParentRole();
		Property::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		Property::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		ImplementationRequirement::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		Requirement::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		Requirement::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		Requirement::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		SatisfierProperty::meta_RequirementSatisfier_parent = Uml::CreateCompositionParentRole();
		SatisfierProperty::meta_Resource_parent = Uml::CreateCompositionParentRole();
		SatisfierProperty::meta_SharedResource_parent = Uml::CreateCompositionParentRole();
		DataType::meta_Property_parent = Uml::CreateCompositionParentRole();
		DataType::meta_SatisfierProperty_parent = Uml::CreateCompositionParentRole();
		DataType::meta_ComponentPropertyDescription_parent = Uml::CreateCompositionParentRole();
		ImplementationDependency::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		Capability::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		AssemblyselectRequirement::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		AssemblyConfigProperty::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		PublishConnector::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		publish::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		deliverTo::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		AssemblyDeployRequirement::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		emit::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		invoke::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		package::meta_TopLevelPackageContainer_parent = Uml::CreateCompositionParentRole();
		TopLevelPackageFolder::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		TopLevelPackageContainer::meta_TopLevelPackageFolder_parent = Uml::CreateCompositionParentRole();
		TopLevelPackage::meta_TopLevelPackageContainer_parent = Uml::CreateCompositionParentRole();
		ComponentPackage::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		ComponentPackage::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		ComponentPackage::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		ComponentPackages::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		ComponentPackageReference::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		ComponentPackageReference::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		Implementation::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		PackageContainer::meta_ComponentPackages_parent = Uml::CreateCompositionParentRole();
		PackageConfigProperty::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		PackageInfoProperty::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		PackageInterface::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		InfoProperty::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		MonolithDeployRequirement::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ComponentImplementation::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ComponentImplementationReference::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		ConfigProperty::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ComponentImplementationContainer::meta_ComponentImplementations_parent = Uml::CreateCompositionParentRole();
		MonolithExecParameter::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ImplementationDependsOn::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		Implements::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ComponentImplementations::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		ImplementationCapability::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ComponentContainer::meta_ComponentTypes_parent = Uml::CreateCompositionParentRole();
		ComponentPropertyDescription::meta_ComponentContainer_parent = Uml::CreateCompositionParentRole();
		ComponentInfoProperty::meta_ComponentContainer_parent = Uml::CreateCompositionParentRole();
		ComponentProperty::meta_ComponentContainer_parent = Uml::CreateCompositionParentRole();
		ComponentTypes::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		ComponentConfigProperty::meta_ComponentContainer_parent = Uml::CreateCompositionParentRole();
		ComponentType::meta_PackageContainer_parent = Uml::CreateCompositionParentRole();
		ComponentType::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ComponentType::meta_ComponentContainer_parent = Uml::CreateCompositionParentRole();
		ComponentType::meta_DeploymentPlan_parent = Uml::CreateCompositionParentRole();
		Resource::meta_Node_parent = Uml::CreateCompositionParentRole();
		Resource::meta_Bridge_parent = Uml::CreateCompositionParentRole();
		Resource::meta_Interconnect_parent = Uml::CreateCompositionParentRole();
		NodeReference::meta_DeploymentPlan_parent = Uml::CreateCompositionParentRole();
		Elements::meta_Domain_parent = Uml::CreateCompositionParentRole();
		Domain::meta_Targets_parent = Uml::CreateCompositionParentRole();
		Targets::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		Node2Interconnect::meta_Domain_parent = Uml::CreateCompositionParentRole();
		Bridge2Interconnect::meta_Domain_parent = Uml::CreateCompositionParentRole();
		Shares::meta_Domain_parent = Uml::CreateCompositionParentRole();
		Interconnect2Node::meta_Domain_parent = Uml::CreateCompositionParentRole();
		Interconnect2Bridge::meta_Domain_parent = Uml::CreateCompositionParentRole();
		InstanceMapping::meta_DeploymentPlan_parent = Uml::CreateCompositionParentRole();
		DeploymentPlan::meta_DeploymentPlans_parent = Uml::CreateCompositionParentRole();
		DeploymentPlans::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		CollocationGroup::meta_DeploymentPlan_parent = Uml::CreateCompositionParentRole();
		PackageConfigurationReference::meta_TopLevelPackageContainer_parent = Uml::CreateCompositionParentRole();
		PackageConfConfigProperty::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		PackageConfigurations::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		PackageConfigurationContainer::meta_PackageConfigurations_parent = Uml::CreateCompositionParentRole();
		PackageConfReference::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		PackageConfiguration::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		PackageConfBasePackage::meta_PackageConfigurationContainer_parent = Uml::CreateCompositionParentRole();
		ArtifactExecParameter::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		ArtifactDeployRequirement::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		ImplementationArtifacts::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		ImplementationArtifact::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		ArtifactInfoProperty::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		ArtifactContainer::meta_ImplementationArtifacts_parent = Uml::CreateCompositionParentRole();
		ArtifactDependsOn::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		ImplementationArtifactReference::meta_ComponentImplementationContainer_parent = Uml::CreateCompositionParentRole();
		ImplementationArtifactReference::meta_ArtifactContainer_parent = Uml::CreateCompositionParentRole();
		InParameter::meta_OperationBase_parent = Uml::CreateCompositionParentRole();
		TwowayOperation::meta_HasOperations_parent = Uml::CreateCompositionParentRole();
		OnewayOperation::meta_HasOperations_parent = Uml::CreateCompositionParentRole();
		FactoryOperation::meta_ComponentFactory_parent = Uml::CreateCompositionParentRole();
		FactoryOperation::meta_ObjectByValue_parent = Uml::CreateCompositionParentRole();
		LookupOperation::meta_ComponentFactory_parent = Uml::CreateCompositionParentRole();
		InoutParameter::meta_TwowayOperation_parent = Uml::CreateCompositionParentRole();
		OutParameter::meta_TwowayOperation_parent = Uml::CreateCompositionParentRole();
		ReturnType::meta_TwowayOperation_parent = Uml::CreateCompositionParentRole();
		Exception::meta_File_parent = Uml::CreateCompositionParentRole();
		Exception::meta_Package_parent = Uml::CreateCompositionParentRole();
		Exception::meta_HasOperations_parent = Uml::CreateCompositionParentRole();
		Package::meta_Package_parent = Uml::CreateCompositionParentRole();
		Package::meta_File_parent = Uml::CreateCompositionParentRole();
		File::meta_InterfaceDefinitions_parent = Uml::CreateCompositionParentRole();
		Constant::meta_Package_parent = Uml::CreateCompositionParentRole();
		Constant::meta_File_parent = Uml::CreateCompositionParentRole();
		Constant::meta_HasOperations_parent = Uml::CreateCompositionParentRole();
		InterfaceDefinitions::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		FileRef::meta_File_parent = Uml::CreateCompositionParentRole();
		ExceptionRef::meta_HasExceptions_parent = Uml::CreateCompositionParentRole();
		NoInheritable::meta_HasOperations_parent = Uml::CreateCompositionParentRole();
		Member::meta_Exception_parent = Uml::CreateCompositionParentRole();
		Member::meta_SwitchedAggregate_parent = Uml::CreateCompositionParentRole();
		Member::meta_Aggregate_parent = Uml::CreateCompositionParentRole();
		Member::meta_ObjectByValue_parent = Uml::CreateCompositionParentRole();
		EnumValue::meta_Enum_parent = Uml::CreateCompositionParentRole();
		Label::meta_SwitchedAggregate_parent = Uml::CreateCompositionParentRole();
		NamedType::meta_Package_parent = Uml::CreateCompositionParentRole();
		NamedType::meta_File_parent = Uml::CreateCompositionParentRole();
		Discriminator::meta_SwitchedAggregate_parent = Uml::CreateCompositionParentRole();
		LabelConnection::meta_SwitchedAggregate_parent = Uml::CreateCompositionParentRole();
		PredefinedType::meta_PredefinedTypes_parent = Uml::CreateCompositionParentRole();
		PredefinedTypes::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		SetException::meta_Attribute_parent = Uml::CreateCompositionParentRole();
		LookupKey::meta_ComponentFactory_parent = Uml::CreateCompositionParentRole();
		ReadonlyAttribute::meta_Inheritable_parent = Uml::CreateCompositionParentRole();
		Supports::meta_SupportsInterfaces_parent = Uml::CreateCompositionParentRole();
		MakeMemberPrivate::meta_ObjectByValue_parent = Uml::CreateCompositionParentRole();
		PrivateFlag::meta_ObjectByValue_parent = Uml::CreateCompositionParentRole();
		GetException::meta_ReadonlyAttribute_parent = Uml::CreateCompositionParentRole();
		Inherits::meta_Inheritable_parent = Uml::CreateCompositionParentRole();
		AttributeMember::meta_ReadonlyAttribute_parent = Uml::CreateCompositionParentRole();
		Component::meta_ComponentAssembly_parent = Uml::CreateCompositionParentRole();
		ManagesComponent::meta_Package_parent = Uml::CreateCompositionParentRole();
		ManagesComponent::meta_File_parent = Uml::CreateCompositionParentRole();
		Port::meta_Component_parent = Uml::CreateCompositionParentRole();
		ComponentRef::meta_Package_parent = Uml::CreateCompositionParentRole();
		ComponentRef::meta_File_parent = Uml::CreateCompositionParentRole();
		RootFolder::meta_RootFolder_parent = Uml::CreateCompositionParentRole();
		Property::meta_DataType_child = Uml::CreateCompositionChildRole();
		RequirementSatisfier::meta_SatisfierProperty_children = Uml::CreateCompositionChildRole();
		RequirementBase::meta_Property_children = Uml::CreateCompositionChildRole();
		SatisfierProperty::meta_DataType_child = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_ComponentPackage_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_ComponentPackageReference_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_invoke_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_AssemblyConfigProperty_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_emit_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_Component_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_AssemblyDeployRequirement_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_Requirement_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_publish_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_PublishConnector_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_AssemblyselectRequirement_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_Property_children = Uml::CreateCompositionChildRole();
		ComponentAssembly::meta_deliverTo_children = Uml::CreateCompositionChildRole();
		TopLevelPackageFolder::meta_TopLevelPackageContainer_children = Uml::CreateCompositionChildRole();
		TopLevelPackageContainer::meta_PackageConfigurationReference_child = Uml::CreateCompositionChildRole();
		TopLevelPackageContainer::meta_package_child = Uml::CreateCompositionChildRole();
		TopLevelPackageContainer::meta_TopLevelPackage_child = Uml::CreateCompositionChildRole();
		ComponentPackages::meta_PackageContainer_children = Uml::CreateCompositionChildRole();
		PackageContainer::meta_PackageInfoProperty_children = Uml::CreateCompositionChildRole();
		PackageContainer::meta_Property_children = Uml::CreateCompositionChildRole();
		PackageContainer::meta_ComponentImplementationReference_children = Uml::CreateCompositionChildRole();
		PackageContainer::meta_PackageConfigProperty_children = Uml::CreateCompositionChildRole();
		PackageContainer::meta_ComponentPackage_child = Uml::CreateCompositionChildRole();
		PackageContainer::meta_ComponentType_children = Uml::CreateCompositionChildRole();
		PackageContainer::meta_PackageInterface_child = Uml::CreateCompositionChildRole();
		PackageContainer::meta_Implementation_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_Capability_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_InfoProperty_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ComponentType_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ImplementationDependency_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_MonolithDeployRequirement_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ConfigProperty_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_MonolithExecParameter_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ComponentImplementation_child = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ImplementationDependsOn_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_Implements_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_MonolithprimaryArtifact_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ImplementationCapability_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_Property_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ImplementationArtifactReference_children = Uml::CreateCompositionChildRole();
		ComponentImplementationContainer::meta_ImplementationRequirement_children = Uml::CreateCompositionChildRole();
		ComponentImplementations::meta_ComponentImplementationContainer_children = Uml::CreateCompositionChildRole();
		ComponentContainer::meta_ComponentProperty_children = Uml::CreateCompositionChildRole();
		ComponentContainer::meta_ComponentInfoProperty_children = Uml::CreateCompositionChildRole();
		ComponentContainer::meta_ComponentPropertyDescription_children = Uml::CreateCompositionChildRole();
		ComponentContainer::meta_Property_children = Uml::CreateCompositionChildRole();
		ComponentContainer::meta_ComponentConfigProperty_children = Uml::CreateCompositionChildRole();
		ComponentContainer::meta_ComponentType_child = Uml::CreateCompositionChildRole();
		ComponentPropertyDescription::meta_DataType_child = Uml::CreateCompositionChildRole();
		ComponentTypes::meta_ComponentContainer_children = Uml::CreateCompositionChildRole();
		Resource::meta_SatisfierProperty_children = Uml::CreateCompositionChildRole();
		SharedResource::meta_SatisfierProperty_children = Uml::CreateCompositionChildRole();
		Bridge::meta_Resource_children = Uml::CreateCompositionChildRole();
		Node::meta_Resource_children = Uml::CreateCompositionChildRole();
		Interconnect::meta_Resource_children = Uml::CreateCompositionChildRole();
		Domain::meta_Property_children = Uml::CreateCompositionChildRole();
		Domain::meta_Elements_children = Uml::CreateCompositionChildRole();
		Domain::meta_Shares_children = Uml::CreateCompositionChildRole();
		Domain::meta_Interconnect2Node_children = Uml::CreateCompositionChildRole();
		Domain::meta_Node2Interconnect_children = Uml::CreateCompositionChildRole();
		Domain::meta_Interconnect2Bridge_children = Uml::CreateCompositionChildRole();
		Domain::meta_Bridge2Interconnect_children = Uml::CreateCompositionChildRole();
		Targets::meta_Domain_children = Uml::CreateCompositionChildRole();
		DeploymentPlan::meta_NodeReference_children = Uml::CreateCompositionChildRole();
		DeploymentPlan::meta_CollocationGroup_children = Uml::CreateCompositionChildRole();
		DeploymentPlan::meta_ComponentType_children = Uml::CreateCompositionChildRole();
		DeploymentPlan::meta_InstanceMapping_children = Uml::CreateCompositionChildRole();
		DeploymentPlans::meta_DeploymentPlan_children = Uml::CreateCompositionChildRole();
		PackageConfigurations::meta_PackageConfigurationContainer_children = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_ComponentPackageReference_child = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_PackageConfiguration_children = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_PackageConfConfigProperty_children = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_PackageConfReference_child = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_PackageConfBasePackage_child = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_Requirement_children = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_ComponentPackage_child = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_Property_children = Uml::CreateCompositionChildRole();
		PackageConfigurationContainer::meta_PackageConfSelectRequirement_children = Uml::CreateCompositionChildRole();
		ImplementationArtifacts::meta_ArtifactContainer_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_ImplementationArtifactReference_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_Property_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_ArtifactDeployRequirement_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_ArtifactExecParameter_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_Requirement_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_ArtifactInfoProperty_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_ArtifactDependsOn_children = Uml::CreateCompositionChildRole();
		ArtifactContainer::meta_ImplementationArtifact_children = Uml::CreateCompositionChildRole();
		TwowayOperation::meta_OutParameter_children = Uml::CreateCompositionChildRole();
		TwowayOperation::meta_ReturnType_child = Uml::CreateCompositionChildRole();
		TwowayOperation::meta_InoutParameter_children = Uml::CreateCompositionChildRole();
		HasExceptions::meta_ExceptionRef_children = Uml::CreateCompositionChildRole();
		OperationBase::meta_InParameter_children = Uml::CreateCompositionChildRole();
		Exception::meta_Member_children = Uml::CreateCompositionChildRole();
		Package::meta_Package_children = Uml::CreateCompositionChildRole();
		Package::meta_ComponentRef_children = Uml::CreateCompositionChildRole();
		Package::meta_ManagesComponent_children = Uml::CreateCompositionChildRole();
		Package::meta_NamedType_children = Uml::CreateCompositionChildRole();
		Package::meta_Constant_children = Uml::CreateCompositionChildRole();
		Package::meta_Exception_children = Uml::CreateCompositionChildRole();
		File::meta_ComponentRef_children = Uml::CreateCompositionChildRole();
		File::meta_ManagesComponent_children = Uml::CreateCompositionChildRole();
		File::meta_FileRef_children = Uml::CreateCompositionChildRole();
		File::meta_NamedType_children = Uml::CreateCompositionChildRole();
		File::meta_Constant_children = Uml::CreateCompositionChildRole();
		File::meta_Exception_children = Uml::CreateCompositionChildRole();
		File::meta_Package_children = Uml::CreateCompositionChildRole();
		InterfaceDefinitions::meta_File_children = Uml::CreateCompositionChildRole();
		SwitchedAggregate::meta_LabelConnection_children = Uml::CreateCompositionChildRole();
		SwitchedAggregate::meta_Label_children = Uml::CreateCompositionChildRole();
		SwitchedAggregate::meta_Member_children = Uml::CreateCompositionChildRole();
		SwitchedAggregate::meta_Discriminator_child = Uml::CreateCompositionChildRole();
		Aggregate::meta_Member_children = Uml::CreateCompositionChildRole();
		Enum::meta_EnumValue_children = Uml::CreateCompositionChildRole();
		PredefinedTypes::meta_PredefinedType_children = Uml::CreateCompositionChildRole();
		Attribute::meta_SetException_children = Uml::CreateCompositionChildRole();
		ReadonlyAttribute::meta_AttributeMember_child = Uml::CreateCompositionChildRole();
		ReadonlyAttribute::meta_GetException_children = Uml::CreateCompositionChildRole();
		SupportsInterfaces::meta_Supports_children = Uml::CreateCompositionChildRole();
		HasOperations::meta_OnewayOperation_children = Uml::CreateCompositionChildRole();
		HasOperations::meta_TwowayOperation_children = Uml::CreateCompositionChildRole();
		HasOperations::meta_NoInheritable_children = Uml::CreateCompositionChildRole();
		HasOperations::meta_Constant_children = Uml::CreateCompositionChildRole();
		HasOperations::meta_Exception_children = Uml::CreateCompositionChildRole();
		Inheritable::meta_Inherits_children = Uml::CreateCompositionChildRole();
		Inheritable::meta_ReadonlyAttribute_children = Uml::CreateCompositionChildRole();
		ObjectByValue::meta_PrivateFlag_children = Uml::CreateCompositionChildRole();
		ObjectByValue::meta_MakeMemberPrivate_children = Uml::CreateCompositionChildRole();
		ObjectByValue::meta_FactoryOperation_children = Uml::CreateCompositionChildRole();
		ObjectByValue::meta_Member_children = Uml::CreateCompositionChildRole();
		Component::meta_Port_children = Uml::CreateCompositionChildRole();
		ComponentFactory::meta_LookupOperation_children = Uml::CreateCompositionChildRole();
		ComponentFactory::meta_FactoryOperation_children = Uml::CreateCompositionChildRole();
		ComponentFactory::meta_LookupKey_child = Uml::CreateCompositionChildRole();
		RootFolder::meta_ComponentPackages_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_TopLevelPackageFolder_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_ComponentImplementations_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_ComponentTypes_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_Targets_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_DeploymentPlans_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_PackageConfigurations_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_ImplementationArtifacts_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_InterfaceDefinitions_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_PredefinedTypes_children = Uml::CreateCompositionChildRole();
		RootFolder::meta_RootFolder_children = Uml::CreateCompositionChildRole();
		Uml::InitDiagram(umldiagram, "PICML", "1.00");

		Uml::InitClass(Property::meta, umldiagram, "Property", false, "Model");
		Uml::InitClass(ImplementationRequirement::meta, umldiagram, "ImplementationRequirement", false, "Model");
		Uml::InitClass(Requirement::meta, umldiagram, "Requirement", false, "Model");
		Uml::InitClass(RequirementSatisfier::meta, umldiagram, "RequirementSatisfier", true, "Model");
		Uml::InitClass(RequirementBase::meta, umldiagram, "RequirementBase", true, "Model");
		Uml::InitClass(SatisfierProperty::meta, umldiagram, "SatisfierProperty", false, "Model");
		Uml::InitClass(DataType::meta, umldiagram, "DataType", false, "Reference");
		Uml::InitClass(ImplementationDependency::meta, umldiagram, "ImplementationDependency", false, "Atom");
		Uml::InitClass(Capability::meta, umldiagram, "Capability", false, "Model");
		Uml::InitClass(AssemblyselectRequirement::meta, umldiagram, "AssemblyselectRequirement", false, "Connection");
		Uml::InitClass(AssemblyConfigProperty::meta, umldiagram, "AssemblyConfigProperty", false, "Connection");
		Uml::InitClass(PublishConnector::meta, umldiagram, "PublishConnector", false, "Atom");
		Uml::InitClass(publish::meta, umldiagram, "publish", false, "Connection");
		Uml::InitClass(deliverTo::meta, umldiagram, "deliverTo", false, "Connection");
		Uml::InitClass(AssemblyDeployRequirement::meta, umldiagram, "AssemblyDeployRequirement", false, "Connection");
		Uml::InitClass(ComponentAssembly::meta, umldiagram, "ComponentAssembly", false, "Model");
		Uml::InitClass(emit::meta, umldiagram, "emit", false, "Connection");
		Uml::InitClass(invoke::meta, umldiagram, "invoke", false, "Connection");
		Uml::InitClass(package::meta, umldiagram, "package", false, "Connection");
		Uml::InitClass(TopLevelPackageFolder::meta, umldiagram, "TopLevelPackageFolder", false, "Folder");
		Uml::InitClass(TopLevelPackageContainer::meta, umldiagram, "TopLevelPackageContainer", false, "Model");
		Uml::InitClass(TopLevelPackage::meta, umldiagram, "TopLevelPackage", false, "Atom");
		Uml::InitClass(ComponentPackage::meta, umldiagram, "ComponentPackage", false, "Atom");
		Uml::InitClass(ComponentPackages::meta, umldiagram, "ComponentPackages", false, "Folder");
		Uml::InitClass(ComponentPackageReference::meta, umldiagram, "ComponentPackageReference", false, "Reference");
		Uml::InitClass(Implementation::meta, umldiagram, "Implementation", false, "Connection");
		Uml::InitClass(PackageContainer::meta, umldiagram, "PackageContainer", false, "Model");
		Uml::InitClass(PackageConfigProperty::meta, umldiagram, "PackageConfigProperty", false, "Connection");
		Uml::InitClass(PackageInfoProperty::meta, umldiagram, "PackageInfoProperty", false, "Connection");
		Uml::InitClass(PackageInterface::meta, umldiagram, "PackageInterface", false, "Connection");
		Uml::InitClass(InfoProperty::meta, umldiagram, "InfoProperty", false, "Connection");
		Uml::InitClass(MonolithprimaryArtifact::meta, umldiagram, "MonolithprimaryArtifact", false, "Connection");
		Uml::InitClass(MonolithDeployRequirement::meta, umldiagram, "MonolithDeployRequirement", false, "Connection");
		Uml::InitClass(ComponentImplementation::meta, umldiagram, "ComponentImplementation", true, "FCO");
		Uml::InitClass(ComponentImplementationReference::meta, umldiagram, "ComponentImplementationReference", false, "Reference");
		Uml::InitClass(ConfigProperty::meta, umldiagram, "ConfigProperty", false, "Connection");
		Uml::InitClass(ComponentImplementationContainer::meta, umldiagram, "ComponentImplementationContainer", false, "Model");
		Uml::InitClass(MonolithicImplementation::meta, umldiagram, "MonolithicImplementation", false, "Atom");
		Uml::InitClass(MonolithExecParameter::meta, umldiagram, "MonolithExecParameter", false, "Connection");
		Uml::InitClass(ImplementationDependsOn::meta, umldiagram, "ImplementationDependsOn", false, "Connection");
		Uml::InitClass(Implements::meta, umldiagram, "Implements", false, "Connection");
		Uml::InitClass(ComponentImplementations::meta, umldiagram, "ComponentImplementations", false, "Folder");
		Uml::InitClass(ImplementationCapability::meta, umldiagram, "ImplementationCapability", false, "Connection");
		Uml::InitClass(ComponentContainer::meta, umldiagram, "ComponentContainer", false, "Model");
		Uml::InitClass(ComponentPropertyDescription::meta, umldiagram, "ComponentPropertyDescription", false, "Model");
		Uml::InitClass(ComponentInfoProperty::meta, umldiagram, "ComponentInfoProperty", false, "Connection");
		Uml::InitClass(ComponentProperty::meta, umldiagram, "ComponentProperty", false, "Connection");
		Uml::InitClass(CommonPortAttrs::meta, umldiagram, "CommonPortAttrs", true, "FCO");
		Uml::InitClass(ComponentTypes::meta, umldiagram, "ComponentTypes", false, "Folder");
		Uml::InitClass(ComponentConfigProperty::meta, umldiagram, "ComponentConfigProperty", false, "Connection");
		Uml::InitClass(ComponentType::meta, umldiagram, "ComponentType", false, "Reference");
		Uml::InitClass(Resource::meta, umldiagram, "Resource", false, "Model");
		Uml::InitClass(SharedResource::meta, umldiagram, "SharedResource", false, "Model");
		Uml::InitClass(NodeReference::meta, umldiagram, "NodeReference", false, "Reference");
		Uml::InitClass(Bridge::meta, umldiagram, "Bridge", false, "Model");
		Uml::InitClass(Node::meta, umldiagram, "Node", false, "Model");
		Uml::InitClass(Interconnect::meta, umldiagram, "Interconnect", false, "Model");
		Uml::InitClass(Elements::meta, umldiagram, "Elements", true, "FCO");
		Uml::InitClass(Domain::meta, umldiagram, "Domain", false, "Model");
		Uml::InitClass(Targets::meta, umldiagram, "Targets", false, "Folder");
		Uml::InitClass(Node2Interconnect::meta, umldiagram, "Node2Interconnect", false, "Connection");
		Uml::InitClass(Bridge2Interconnect::meta, umldiagram, "Bridge2Interconnect", false, "Connection");
		Uml::InitClass(Shares::meta, umldiagram, "Shares", false, "Connection");
		Uml::InitClass(Interconnect2Node::meta, umldiagram, "Interconnect2Node", false, "Connection");
		Uml::InitClass(Interconnect2Bridge::meta, umldiagram, "Interconnect2Bridge", false, "Connection");
		Uml::InitClass(InstanceMapping::meta, umldiagram, "InstanceMapping", false, "Connection");
		Uml::InitClass(DeploymentPlan::meta, umldiagram, "DeploymentPlan", false, "Model");
		Uml::InitClass(DeploymentPlans::meta, umldiagram, "DeploymentPlans", false, "Folder");
		Uml::InitClass(CollocationGroup::meta, umldiagram, "CollocationGroup", false, "Set");
		Uml::InitClass(PackageConfigurationReference::meta, umldiagram, "PackageConfigurationReference", false, "Reference");
		Uml::InitClass(PackageConfConfigProperty::meta, umldiagram, "PackageConfConfigProperty", false, "Connection");
		Uml::InitClass(PackageConfigurations::meta, umldiagram, "PackageConfigurations", false, "Folder");
		Uml::InitClass(PackageConfigurationContainer::meta, umldiagram, "PackageConfigurationContainer", false, "Model");
		Uml::InitClass(PackageConfReference::meta, umldiagram, "PackageConfReference", false, "Connection");
		Uml::InitClass(PackageConfiguration::meta, umldiagram, "PackageConfiguration", false, "Atom");
		Uml::InitClass(PackageConfSpecializedConfig::meta, umldiagram, "PackageConfSpecializedConfig", false, "Connection");
		Uml::InitClass(PackageConfSelectRequirement::meta, umldiagram, "PackageConfSelectRequirement", false, "Connection");
		Uml::InitClass(PackageConfBasePackage::meta, umldiagram, "PackageConfBasePackage", false, "Connection");
		Uml::InitClass(ArtifactExecParameter::meta, umldiagram, "ArtifactExecParameter", false, "Connection");
		Uml::InitClass(ArtifactDeployRequirement::meta, umldiagram, "ArtifactDeployRequirement", false, "Connection");
		Uml::InitClass(ImplementationArtifacts::meta, umldiagram, "ImplementationArtifacts", false, "Folder");
		Uml::InitClass(ImplementationArtifact::meta, umldiagram, "ImplementationArtifact", false, "Atom");
		Uml::InitClass(ArtifactInfoProperty::meta, umldiagram, "ArtifactInfoProperty", false, "Connection");
		Uml::InitClass(ArtifactContainer::meta, umldiagram, "ArtifactContainer", false, "Model");
		Uml::InitClass(ArtifactDependsOn::meta, umldiagram, "ArtifactDependsOn", false, "Connection");
		Uml::InitClass(ImplementationArtifactReference::meta, umldiagram, "ImplementationArtifactReference", false, "Reference");
		Uml::InitClass(InParameter::meta, umldiagram, "InParameter", false, "Reference");
		Uml::InitClass(TwowayOperation::meta, umldiagram, "TwowayOperation", false, "Model");
		Uml::InitClass(OnewayOperation::meta, umldiagram, "OnewayOperation", false, "Model");
		Uml::InitClass(HasExceptions::meta, umldiagram, "HasExceptions", true, "Model");
		Uml::InitClass(OperationBase::meta, umldiagram, "OperationBase", true, "Model");
		Uml::InitClass(FactoryOperation::meta, umldiagram, "FactoryOperation", false, "Model");
		Uml::InitClass(LookupOperation::meta, umldiagram, "LookupOperation", false, "Model");
		Uml::InitClass(InoutParameter::meta, umldiagram, "InoutParameter", false, "Reference");
		Uml::InitClass(OutParameter::meta, umldiagram, "OutParameter", false, "Reference");
		Uml::InitClass(ReturnType::meta, umldiagram, "ReturnType", false, "Reference");
		Uml::InitClass(Exception::meta, umldiagram, "Exception", false, "Model");
		Uml::InitClass(Package::meta, umldiagram, "Package", false, "Model");
		Uml::InitClass(ConstantType::meta, umldiagram, "ConstantType", true, "FCO");
		Uml::InitClass(File::meta, umldiagram, "File", false, "Model");
		Uml::InitClass(Constant::meta, umldiagram, "Constant", false, "Reference");
		Uml::InitClass(InterfaceDefinitions::meta, umldiagram, "InterfaceDefinitions", false, "Folder");
		Uml::InitClass(FileRef::meta, umldiagram, "FileRef", false, "Reference");
		Uml::InitClass(ExceptionRef::meta, umldiagram, "ExceptionRef", false, "Reference");
		Uml::InitClass(SwitchedAggregate::meta, umldiagram, "SwitchedAggregate", false, "Model");
		Uml::InitClass(NoInheritable::meta, umldiagram, "NoInheritable", true, "FCO");
		Uml::InitClass(Member::meta, umldiagram, "Member", false, "Reference");
		Uml::InitClass(Boxed::meta, umldiagram, "Boxed", false, "Reference");
		Uml::InitClass(EnumValue::meta, umldiagram, "EnumValue", false, "Atom");
		Uml::InitClass(Label::meta, umldiagram, "Label", false, "Atom");
		Uml::InitClass(MemberType::meta, umldiagram, "MemberType", true, "FCO");
		Uml::InitClass(Aggregate::meta, umldiagram, "Aggregate", false, "Model");
		Uml::InitClass(Alias::meta, umldiagram, "Alias", false, "Reference");
		Uml::InitClass(Collection::meta, umldiagram, "Collection", false, "Reference");
		Uml::InitClass(NamedType::meta, umldiagram, "NamedType", true, "FCO");
		Uml::InitClass(Discriminator::meta, umldiagram, "Discriminator", false, "Reference");
		Uml::InitClass(Enum::meta, umldiagram, "Enum", false, "Model");
		Uml::InitClass(LabelConnection::meta, umldiagram, "LabelConnection", false, "Connection");
		Uml::InitClass(Prefixable::meta, umldiagram, "Prefixable", true, "Model");
		Uml::InitClass(Taggable::meta, umldiagram, "Taggable", true, "FCO");
		Uml::InitClass(PredefinedType::meta, umldiagram, "PredefinedType", true, "FCO");
		Uml::InitClass(Boolean::meta, umldiagram, "Boolean", false, "Atom");
		Uml::InitClass(GenericValue::meta, umldiagram, "GenericValue", false, "Atom");
		Uml::InitClass(LongInteger::meta, umldiagram, "LongInteger", false, "Atom");
		Uml::InitClass(Byte::meta, umldiagram, "Byte", false, "Atom");
		Uml::InitClass(TypeKind::meta, umldiagram, "TypeKind", false, "Atom");
		Uml::InitClass(GenericObject::meta, umldiagram, "GenericObject", false, "Atom");
		Uml::InitClass(ShortInteger::meta, umldiagram, "ShortInteger", false, "Atom");
		Uml::InitClass(RealNumber::meta, umldiagram, "RealNumber", false, "Atom");
		Uml::InitClass(PredefinedTypes::meta, umldiagram, "PredefinedTypes", false, "Folder");
		Uml::InitClass(String::meta, umldiagram, "String", false, "Atom");
		Uml::InitClass(TypeEncoding::meta, umldiagram, "TypeEncoding", false, "Atom");
		Uml::InitClass(GenericValueObject::meta, umldiagram, "GenericValueObject", false, "Atom");
		Uml::InitClass(SetException::meta, umldiagram, "SetException", false, "Reference");
		Uml::InitClass(LookupKey::meta, umldiagram, "LookupKey", false, "Reference");
		Uml::InitClass(Attribute::meta, umldiagram, "Attribute", false, "Model");
		Uml::InitClass(ReadonlyAttribute::meta, umldiagram, "ReadonlyAttribute", false, "Model");
		Uml::InitClass(Supports::meta, umldiagram, "Supports", false, "Reference");
		Uml::InitClass(SupportsInterfaces::meta, umldiagram, "SupportsInterfaces", true, "Model");
		Uml::InitClass(HasOperations::meta, umldiagram, "HasOperations", true, "Model");
		Uml::InitClass(Inheritable::meta, umldiagram, "Inheritable", true, "Model");
		Uml::InitClass(MakeMemberPrivate::meta, umldiagram, "MakeMemberPrivate", false, "Connection");
		Uml::InitClass(PrivateFlag::meta, umldiagram, "PrivateFlag", false, "Atom");
		Uml::InitClass(GetException::meta, umldiagram, "GetException", false, "Reference");
		Uml::InitClass(ObjectByValue::meta, umldiagram, "ObjectByValue", true, "Model");
		Uml::InitClass(Inherits::meta, umldiagram, "Inherits", false, "Reference");
		Uml::InitClass(Object::meta, umldiagram, "Object", false, "Model");
		Uml::InitClass(ValueObject::meta, umldiagram, "ValueObject", false, "Model");
		Uml::InitClass(Event::meta, umldiagram, "Event", false, "Model");
		Uml::InitClass(AttributeMember::meta, umldiagram, "AttributeMember", false, "Reference");
		Uml::InitClass(OutEventPort::meta, umldiagram, "OutEventPort", false, "Reference");
		Uml::InitClass(ProvidedRequestPort::meta, umldiagram, "ProvidedRequestPort", false, "Reference");
		Uml::InitClass(Component::meta, umldiagram, "Component", false, "Model");
		Uml::InitClass(RequiredRequestPort::meta, umldiagram, "RequiredRequestPort", false, "Reference");
		Uml::InitClass(ManagesComponent::meta, umldiagram, "ManagesComponent", false, "Connection");
		Uml::InitClass(InEventPort::meta, umldiagram, "InEventPort", false, "Reference");
		Uml::InitClass(Port::meta, umldiagram, "Port", true, "FCO");
		Uml::InitClass(ComponentRef::meta, umldiagram, "ComponentRef", false, "Reference");
		Uml::InitClass(ComponentFactory::meta, umldiagram, "ComponentFactory", false, "Model");
		Uml::InitClass(Manageable::meta, umldiagram, "Manageable", true, "FCO");
		Uml::InitClass(Provideable::meta, umldiagram, "Provideable", true, "FCO");
		Uml::InitClass(RootFolder::meta, umldiagram, "RootFolder", false, "Folder");
		Uml::InitClass(MgaObject::meta, umldiagram, "MgaObject", true);
		
		Uml::InitAttribute(Property::meta_DataValue, Property::meta, "DataValue", "String", false, false, 1, 1, false, "public");
		vector<string> ImplementationRequirement_ResourceUsageKind_dva;
		ImplementationRequirement_ResourceUsageKind_dva.push_back("None");
		Uml::InitAttribute(ImplementationRequirement::meta_ResourceUsageKind, ImplementationRequirement::meta, "ResourceUsageKind", "String", false, false, 1, 1, false, "public", ImplementationRequirement_ResourceUsageKind_dva);
		Uml::InitAttribute(ImplementationRequirement::meta_componentPort, ImplementationRequirement::meta, "componentPort", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ImplementationRequirement::meta_resourcePort, ImplementationRequirement::meta, "resourcePort", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(RequirementSatisfier::meta_resourceType, RequirementSatisfier::meta, "resourceType", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(RequirementBase::meta_resourceType, RequirementBase::meta, "resourceType", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(SatisfierProperty::meta_DataValue, SatisfierProperty::meta, "DataValue", "String", false, false, 1, 1, false, "public");
		vector<string> SatisfierProperty_SatisfierPropertyKind_dva;
		SatisfierProperty_SatisfierPropertyKind_dva.push_back("Quantity");
		Uml::InitAttribute(SatisfierProperty::meta_SatisfierPropertyKind, SatisfierProperty::meta, "SatisfierPropertyKind", "String", false, false, 1, 1, false, "public", SatisfierProperty_SatisfierPropertyKind_dva);
		Uml::InitAttribute(ImplementationDependency::meta_requiredType, ImplementationDependency::meta, "requiredType", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(TopLevelPackageFolder::meta_name, TopLevelPackageFolder::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(ComponentPackage::meta_UUID, ComponentPackage::meta, "UUID", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ComponentPackage::meta_label, ComponentPackage::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ComponentPackages::meta_name, ComponentPackages::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(ComponentPackageReference::meta_requiredName, ComponentPackageReference::meta, "requiredName", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ComponentPackageReference::meta_requiredUUID, ComponentPackageReference::meta, "requiredUUID", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ComponentPackageReference::meta_requiredType, ComponentPackageReference::meta, "requiredType", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ComponentImplementation::meta_UUID, ComponentImplementation::meta, "UUID", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ComponentImplementation::meta_label, ComponentImplementation::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ComponentImplementations::meta_name, ComponentImplementations::meta, "name", "String", false, false, 0, 1, false, "public");
		vector<string> CommonPortAttrs_exclusiveUser_dva;
		CommonPortAttrs_exclusiveUser_dva.push_back("false");
		Uml::InitAttribute(CommonPortAttrs::meta_exclusiveUser, CommonPortAttrs::meta, "exclusiveUser", "Boolean", false, false, 1, 1, false, "public", CommonPortAttrs_exclusiveUser_dva);
		vector<string> CommonPortAttrs_optional_dva;
		CommonPortAttrs_optional_dva.push_back("false");
		Uml::InitAttribute(CommonPortAttrs::meta_optional, CommonPortAttrs::meta, "optional", "Boolean", false, false, 1, 1, false, "public", CommonPortAttrs_optional_dva);
		vector<string> CommonPortAttrs_exclusiveProvider_dva;
		CommonPortAttrs_exclusiveProvider_dva.push_back("false");
		Uml::InitAttribute(CommonPortAttrs::meta_exclusiveProvider, CommonPortAttrs::meta, "exclusiveProvider", "Boolean", false, false, 1, 1, false, "public", CommonPortAttrs_exclusiveProvider_dva);
		Uml::InitAttribute(ComponentTypes::meta_name, ComponentTypes::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(Resource::meta_resourceType, Resource::meta, "resourceType", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(SharedResource::meta_resourceType, SharedResource::meta, "resourceType", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Bridge::meta_label, Bridge::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Node::meta_label, Node::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Interconnect::meta_label, Interconnect::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Domain::meta_label, Domain::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Domain::meta_UUID, Domain::meta, "UUID", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Targets::meta_name, Targets::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(DeploymentPlan::meta_label, DeploymentPlan::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(DeploymentPlans::meta_name, DeploymentPlans::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(PackageConfigurations::meta_name, PackageConfigurations::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(PackageConfiguration::meta_UUID, PackageConfiguration::meta, "UUID", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(PackageConfiguration::meta_label, PackageConfiguration::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ImplementationArtifacts::meta_name, ImplementationArtifacts::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(ImplementationArtifact::meta_UUID, ImplementationArtifact::meta, "UUID", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ImplementationArtifact::meta_label, ImplementationArtifact::meta, "label", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(ImplementationArtifact::meta_location, ImplementationArtifact::meta, "location", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Constant::meta_value, Constant::meta, "value", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(InterfaceDefinitions::meta_name, InterfaceDefinitions::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(Prefixable::meta_PrefixTag, Prefixable::meta, "PrefixTag", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Taggable::meta_VersionTag, Taggable::meta, "VersionTag", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Taggable::meta_SpecifyIdTag, Taggable::meta, "SpecifyIdTag", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(PredefinedTypes::meta_name, PredefinedTypes::meta, "name", "String", false, false, 0, 1, false, "public");
		vector<string> ObjectByValue_abstract_dva;
		ObjectByValue_abstract_dva.push_back("false");
		Uml::InitAttribute(ObjectByValue::meta_abstract, ObjectByValue::meta, "abstract", "Boolean", false, false, 1, 1, false, "public", ObjectByValue_abstract_dva);
		vector<string> Object_abstract_dva;
		Object_abstract_dva.push_back("false");
		Uml::InitAttribute(Object::meta_abstract, Object::meta, "abstract", "Boolean", false, false, 1, 1, false, "public", Object_abstract_dva);
		vector<string> Object_local_dva;
		Object_local_dva.push_back("false");
		Uml::InitAttribute(Object::meta_local, Object::meta, "local", "Boolean", false, false, 1, 1, false, "public", Object_local_dva);
		vector<string> OutEventPort_single_destination_dva;
		OutEventPort_single_destination_dva.push_back("false");
		Uml::InitAttribute(OutEventPort::meta_single_destination, OutEventPort::meta, "single_destination", "Boolean", false, false, 1, 1, false, "public", OutEventPort_single_destination_dva);
		Uml::InitAttribute(Component::meta_UUID, Component::meta, "UUID", "String", false, false, 1, 1, false, "public");
		Uml::InitAttribute(Component::meta_label, Component::meta, "label", "String", false, false, 1, 1, false, "public");
		vector<string> RequiredRequestPort_multiple_connections_dva;
		RequiredRequestPort_multiple_connections_dva.push_back("false");
		Uml::InitAttribute(RequiredRequestPort::meta_multiple_connections, RequiredRequestPort::meta, "multiple_connections", "Boolean", false, false, 1, 1, false, "public", RequiredRequestPort_multiple_connections_dva);
		Uml::InitAttribute(RootFolder::meta_name, RootFolder::meta, "name", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(MgaObject::meta_position, MgaObject::meta, "position", "String", false, false, 0, 1, false, "public");
		Uml::InitAttribute(MgaObject::meta_name, MgaObject::meta, "name", "String", false, false, 0, 1, false, "public");
		
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageConfigProperty");
			Uml::InitAssociationClass(ass, PackageConfigProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcPackageConfigProperty, ass, "srcPackageConfigProperty", true, false, 0, -1, ComponentPackage::meta);
			PackageConfigProperty::meta_srcPackageConfigProperty_end_ = ComponentPackage::meta_dstPackageConfigProperty_rev = Property::meta_srcPackageConfigProperty;
			Uml::InitAssociationRole(ComponentPackage::meta_dstPackageConfigProperty, ass, "dstPackageConfigProperty", true, false, 0, -1, Property::meta);
			PackageConfigProperty::meta_dstPackageConfigProperty_end_ = Property::meta_srcPackageConfigProperty_rev = ComponentPackage::meta_dstPackageConfigProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageInfoProperty");
			Uml::InitAssociationClass(ass, PackageInfoProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcPackageInfoProperty, ass, "srcPackageInfoProperty", true, false, 0, -1, ComponentPackage::meta);
			PackageInfoProperty::meta_srcPackageInfoProperty_end_ = ComponentPackage::meta_dstPackageInfoProperty_rev = Property::meta_srcPackageInfoProperty;
			Uml::InitAssociationRole(ComponentPackage::meta_dstPackageInfoProperty, ass, "dstPackageInfoProperty", true, false, 0, -1, Property::meta);
			PackageInfoProperty::meta_dstPackageInfoProperty_end_ = Property::meta_srcPackageInfoProperty_rev = ComponentPackage::meta_dstPackageInfoProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ConfigProperty");
			Uml::InitAssociationClass(ass, ConfigProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcConfigProperty, ass, "srcConfigProperty", true, false, 0, -1, ComponentImplementation::meta);
			ConfigProperty::meta_srcConfigProperty_end_ = ComponentImplementation::meta_dstConfigProperty_rev = Property::meta_srcConfigProperty;
			Uml::InitAssociationRole(ComponentImplementation::meta_dstConfigProperty, ass, "dstConfigProperty", true, false, 0, -1, Property::meta);
			ConfigProperty::meta_dstConfigProperty_end_ = Property::meta_srcConfigProperty_rev = ComponentImplementation::meta_dstConfigProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "InfoProperty");
			Uml::InitAssociationClass(ass, InfoProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcInfoProperty, ass, "srcInfoProperty", true, false, 0, -1, ComponentImplementation::meta);
			InfoProperty::meta_srcInfoProperty_end_ = ComponentImplementation::meta_dstInfoProperty_rev = Property::meta_srcInfoProperty;
			Uml::InitAssociationRole(ComponentImplementation::meta_dstInfoProperty, ass, "dstInfoProperty", true, false, 0, -1, Property::meta);
			InfoProperty::meta_dstInfoProperty_end_ = Property::meta_srcInfoProperty_rev = ComponentImplementation::meta_dstInfoProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "MonolithExecParameter");
			Uml::InitAssociationClass(ass, MonolithExecParameter::meta);
			Uml::InitAssociationRole(Property::meta_srcMonolithExecParameter, ass, "srcMonolithExecParameter", true, false, 0, -1, MonolithicImplementation::meta);
			MonolithExecParameter::meta_srcMonolithExecParameter_end_ = MonolithicImplementation::meta_dstMonolithExecParameter_rev = Property::meta_srcMonolithExecParameter;
			Uml::InitAssociationRole(MonolithicImplementation::meta_dstMonolithExecParameter, ass, "dstMonolithExecParameter", true, false, 0, -1, Property::meta);
			MonolithExecParameter::meta_dstMonolithExecParameter_end_ = Property::meta_srcMonolithExecParameter_rev = MonolithicImplementation::meta_dstMonolithExecParameter;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ComponentConfigProperty");
			Uml::InitAssociationClass(ass, ComponentConfigProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcComponentConfigProperty, ass, "srcComponentConfigProperty", true, false, 0, -1, ComponentType::meta);
			ComponentConfigProperty::meta_srcComponentConfigProperty_end_ = ComponentType::meta_dstComponentConfigProperty_rev = Property::meta_srcComponentConfigProperty;
			Uml::InitAssociationRole(ComponentType::meta_dstComponentConfigProperty, ass, "dstComponentConfigProperty", true, false, 0, -1, Property::meta);
			ComponentConfigProperty::meta_dstComponentConfigProperty_end_ = Property::meta_srcComponentConfigProperty_rev = ComponentType::meta_dstComponentConfigProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ComponentInfoProperty");
			Uml::InitAssociationClass(ass, ComponentInfoProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcComponentInfoProperty, ass, "srcComponentInfoProperty", true, false, 0, -1, ComponentType::meta);
			ComponentInfoProperty::meta_srcComponentInfoProperty_end_ = ComponentType::meta_dstComponentInfoProperty_rev = Property::meta_srcComponentInfoProperty;
			Uml::InitAssociationRole(ComponentType::meta_dstComponentInfoProperty, ass, "dstComponentInfoProperty", true, false, 0, -1, Property::meta);
			ComponentInfoProperty::meta_dstComponentInfoProperty_end_ = Property::meta_srcComponentInfoProperty_rev = ComponentType::meta_dstComponentInfoProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageConfConfigProperty");
			Uml::InitAssociationClass(ass, PackageConfConfigProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcPackageConfConfigProperty, ass, "srcPackageConfConfigProperty", true, false, 0, -1, PackageConfiguration::meta);
			PackageConfConfigProperty::meta_srcPackageConfConfigProperty_end_ = PackageConfiguration::meta_dstPackageConfConfigProperty_rev = Property::meta_srcPackageConfConfigProperty;
			Uml::InitAssociationRole(PackageConfiguration::meta_dstPackageConfConfigProperty, ass, "dstPackageConfConfigProperty", true, false, 0, -1, Property::meta);
			PackageConfConfigProperty::meta_dstPackageConfConfigProperty_end_ = Property::meta_srcPackageConfConfigProperty_rev = PackageConfiguration::meta_dstPackageConfConfigProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ArtifactInfoProperty");
			Uml::InitAssociationClass(ass, ArtifactInfoProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcArtifactInfoProperty, ass, "srcArtifactInfoProperty", true, false, 0, -1, ImplementationArtifact::meta);
			ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_ = ImplementationArtifact::meta_dstArtifactInfoProperty_rev = Property::meta_srcArtifactInfoProperty;
			Uml::InitAssociationRole(ImplementationArtifact::meta_dstArtifactInfoProperty, ass, "dstArtifactInfoProperty", true, false, 0, -1, Property::meta);
			ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_ = Property::meta_srcArtifactInfoProperty_rev = ImplementationArtifact::meta_dstArtifactInfoProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ArtifactExecParameter");
			Uml::InitAssociationClass(ass, ArtifactExecParameter::meta);
			Uml::InitAssociationRole(Property::meta_srcArtifactExecParameter, ass, "srcArtifactExecParameter", true, false, 0, -1, ImplementationArtifact::meta);
			ArtifactExecParameter::meta_srcArtifactExecParameter_end_ = ImplementationArtifact::meta_dstArtifactExecParameter_rev = Property::meta_srcArtifactExecParameter;
			Uml::InitAssociationRole(ImplementationArtifact::meta_dstArtifactExecParameter, ass, "dstArtifactExecParameter", true, false, 0, -1, Property::meta);
			ArtifactExecParameter::meta_dstArtifactExecParameter_end_ = Property::meta_srcArtifactExecParameter_rev = ImplementationArtifact::meta_dstArtifactExecParameter;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "AssemblyConfigProperty");
			Uml::InitAssociationClass(ass, AssemblyConfigProperty::meta);
			Uml::InitAssociationRole(Property::meta_srcAssemblyConfigProperty, ass, "srcAssemblyConfigProperty", true, false, 0, -1, Component::meta);
			AssemblyConfigProperty::meta_srcAssemblyConfigProperty_end_ = Component::meta_dstAssemblyConfigProperty_rev = Property::meta_srcAssemblyConfigProperty;
			Uml::InitAssociationRole(Component::meta_dstAssemblyConfigProperty, ass, "dstAssemblyConfigProperty", true, false, 0, -1, Property::meta);
			AssemblyConfigProperty::meta_dstAssemblyConfigProperty_end_ = Property::meta_srcAssemblyConfigProperty_rev = Component::meta_dstAssemblyConfigProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "MonolithDeployRequirement");
			Uml::InitAssociationClass(ass, MonolithDeployRequirement::meta);
			Uml::InitAssociationRole(ImplementationRequirement::meta_srcMonolithDeployRequirement, ass, "srcMonolithDeployRequirement", true, false, 0, -1, MonolithicImplementation::meta);
			MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_ = MonolithicImplementation::meta_dstMonolithDeployRequirement_rev = ImplementationRequirement::meta_srcMonolithDeployRequirement;
			Uml::InitAssociationRole(MonolithicImplementation::meta_dstMonolithDeployRequirement, ass, "dstMonolithDeployRequirement", true, false, 0, -1, ImplementationRequirement::meta);
			MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_ = ImplementationRequirement::meta_srcMonolithDeployRequirement_rev = MonolithicImplementation::meta_dstMonolithDeployRequirement;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageConfSelectRequirement");
			Uml::InitAssociationClass(ass, PackageConfSelectRequirement::meta);
			Uml::InitAssociationRole(Requirement::meta_srcPackageConfSelectRequirement, ass, "srcPackageConfSelectRequirement", true, false, 0, -1, PackageConfiguration::meta);
			PackageConfSelectRequirement::meta_srcPackageConfSelectRequirement_end_ = PackageConfiguration::meta_dstPackageConfSelectRequirement_rev = Requirement::meta_srcPackageConfSelectRequirement;
			Uml::InitAssociationRole(PackageConfiguration::meta_dstPackageConfSelectRequirement, ass, "dstPackageConfSelectRequirement", true, false, 0, -1, Requirement::meta);
			PackageConfSelectRequirement::meta_dstPackageConfSelectRequirement_end_ = Requirement::meta_srcPackageConfSelectRequirement_rev = PackageConfiguration::meta_dstPackageConfSelectRequirement;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "AssemblyDeployRequirement");
			Uml::InitAssociationClass(ass, AssemblyDeployRequirement::meta);
			Uml::InitAssociationRole(Requirement::meta_srcAssemblyDeployRequirement, ass, "srcAssemblyDeployRequirement", true, false, 0, -1, PublishConnector::meta);
			AssemblyDeployRequirement::meta_srcAssemblyDeployRequirement_end_ = PublishConnector::meta_dstAssemblyDeployRequirement_rev = Requirement::meta_srcAssemblyDeployRequirement;
			Uml::InitAssociationRole(PublishConnector::meta_dstAssemblyDeployRequirement, ass, "dstAssemblyDeployRequirement", true, false, 0, -1, Requirement::meta);
			AssemblyDeployRequirement::meta_dstAssemblyDeployRequirement_end_ = Requirement::meta_srcAssemblyDeployRequirement_rev = PublishConnector::meta_dstAssemblyDeployRequirement;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ArtifactDeployRequirement");
			Uml::InitAssociationClass(ass, ArtifactDeployRequirement::meta);
			Uml::InitAssociationRole(Requirement::meta_srcArtifactDeployRequirement, ass, "srcArtifactDeployRequirement", true, false, 0, -1, ImplementationArtifact::meta);
			ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_ = ImplementationArtifact::meta_dstArtifactDeployRequirement_rev = Requirement::meta_srcArtifactDeployRequirement;
			Uml::InitAssociationRole(ImplementationArtifact::meta_dstArtifactDeployRequirement, ass, "dstArtifactDeployRequirement", true, false, 0, -1, Requirement::meta);
			ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_ = Requirement::meta_srcArtifactDeployRequirement_rev = ImplementationArtifact::meta_dstArtifactDeployRequirement;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "AssemblyselectRequirement");
			Uml::InitAssociationClass(ass, AssemblyselectRequirement::meta);
			Uml::InitAssociationRole(Requirement::meta_srcAssemblyselectRequirement, ass, "srcAssemblyselectRequirement", true, false, 0, -1, Component::meta);
			AssemblyselectRequirement::meta_srcAssemblyselectRequirement_end_ = Component::meta_dstAssemblyselectRequirement_rev = Requirement::meta_srcAssemblyselectRequirement;
			Uml::InitAssociationRole(Component::meta_dstAssemblyselectRequirement, ass, "dstAssemblyselectRequirement", true, false, 0, -1, Requirement::meta);
			AssemblyselectRequirement::meta_dstAssemblyselectRequirement_end_ = Requirement::meta_srcAssemblyselectRequirement_rev = Component::meta_dstAssemblyselectRequirement;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(PredefinedType::meta_referedbyDataType, ass, "referedbyDataType", true, false, 0, -1, DataType::meta);
			Uml::InitAssociationRole(DataType::meta_ref, ass, "ref", true, false, 0, 1, PredefinedType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ImplementationDependsOn");
			Uml::InitAssociationClass(ass, ImplementationDependsOn::meta);
			Uml::InitAssociationRole(ImplementationDependency::meta_srcImplementationDependsOn, ass, "srcImplementationDependsOn", true, false, 0, -1, ComponentImplementation::meta);
			ImplementationDependsOn::meta_srcImplementationDependsOn_end_ = ComponentImplementation::meta_dstImplementationDependsOn_rev = ImplementationDependency::meta_srcImplementationDependsOn;
			Uml::InitAssociationRole(ComponentImplementation::meta_dstImplementationDependsOn, ass, "dstImplementationDependsOn", true, false, 0, -1, ImplementationDependency::meta);
			ImplementationDependsOn::meta_dstImplementationDependsOn_end_ = ImplementationDependency::meta_srcImplementationDependsOn_rev = ComponentImplementation::meta_dstImplementationDependsOn;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ImplementationCapability");
			Uml::InitAssociationClass(ass, ImplementationCapability::meta);
			Uml::InitAssociationRole(Capability::meta_srcImplementationCapability, ass, "srcImplementationCapability", true, false, 0, -1, ComponentImplementation::meta);
			ImplementationCapability::meta_srcImplementationCapability_end_ = ComponentImplementation::meta_dstImplementationCapability_rev = Capability::meta_srcImplementationCapability;
			Uml::InitAssociationRole(ComponentImplementation::meta_dstImplementationCapability, ass, "dstImplementationCapability", true, false, 0, -1, Capability::meta);
			ImplementationCapability::meta_dstImplementationCapability_end_ = Capability::meta_srcImplementationCapability_rev = ComponentImplementation::meta_dstImplementationCapability;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "deliverTo");
			Uml::InitAssociationClass(ass, deliverTo::meta);
			Uml::InitAssociationRole(PublishConnector::meta_dstdeliverTo, ass, "dstdeliverTo", true, false, 0, -1, InEventPort::meta);
			deliverTo::meta_dstdeliverTo_end_ = InEventPort::meta_srcdeliverTo_rev = PublishConnector::meta_dstdeliverTo;
			Uml::InitAssociationRole(InEventPort::meta_srcdeliverTo, ass, "srcdeliverTo", true, false, 0, -1, PublishConnector::meta);
			deliverTo::meta_srcdeliverTo_end_ = PublishConnector::meta_dstdeliverTo_rev = InEventPort::meta_srcdeliverTo;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "publish");
			Uml::InitAssociationClass(ass, publish::meta);
			Uml::InitAssociationRole(PublishConnector::meta_srcpublish, ass, "srcpublish", true, false, 0, -1, OutEventPort::meta);
			publish::meta_srcpublish_end_ = OutEventPort::meta_dstpublish_rev = PublishConnector::meta_srcpublish;
			Uml::InitAssociationRole(OutEventPort::meta_dstpublish, ass, "dstpublish", true, false, 0, -1, PublishConnector::meta);
			publish::meta_dstpublish_end_ = PublishConnector::meta_srcpublish_rev = OutEventPort::meta_dstpublish;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "package");
			Uml::InitAssociationClass(ass, package::meta);
			Uml::InitAssociationRole(PackageConfigurationReference::meta_srcpackage, ass, "srcpackage", true, false, 1, 1, TopLevelPackage::meta);
			package::meta_srcpackage_end_ = TopLevelPackage::meta_dstpackage_rev = PackageConfigurationReference::meta_srcpackage;
			Uml::InitAssociationRole(TopLevelPackage::meta_dstpackage, ass, "dstpackage", true, false, 1, 1, PackageConfigurationReference::meta);
			package::meta_dstpackage_end_ = PackageConfigurationReference::meta_srcpackage_rev = TopLevelPackage::meta_dstpackage;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageInterface");
			Uml::InitAssociationClass(ass, PackageInterface::meta);
			Uml::InitAssociationRole(ComponentPackage::meta_dstPackageInterface, ass, "dstPackageInterface", true, false, 0, 1, ComponentType::meta);
			PackageInterface::meta_dstPackageInterface_end_ = ComponentType::meta_srcPackageInterface_rev = ComponentPackage::meta_dstPackageInterface;
			Uml::InitAssociationRole(ComponentType::meta_srcPackageInterface, ass, "srcPackageInterface", true, false, 0, 1, ComponentPackage::meta);
			PackageInterface::meta_srcPackageInterface_end_ = ComponentPackage::meta_dstPackageInterface_rev = ComponentType::meta_srcPackageInterface;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "Implementation");
			Uml::InitAssociationClass(ass, Implementation::meta);
			Uml::InitAssociationRole(ComponentPackage::meta_dstImplementation, ass, "dstImplementation", true, false, 1, -1, ComponentImplementationReference::meta);
			Implementation::meta_dstImplementation_end_ = ComponentImplementationReference::meta_srcImplementation_rev = ComponentPackage::meta_dstImplementation;
			Uml::InitAssociationRole(ComponentImplementationReference::meta_srcImplementation, ass, "srcImplementation", true, false, 0, -1, ComponentPackage::meta);
			Implementation::meta_srcImplementation_end_ = ComponentPackage::meta_dstImplementation_rev = ComponentImplementationReference::meta_srcImplementation;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ComponentPackage::meta_referedbyComponentPackageReference, ass, "referedbyComponentPackageReference", true, false, 0, -1, ComponentPackageReference::meta);
			Uml::InitAssociationRole(ComponentPackageReference::meta_ref, ass, "ref", true, false, 0, 1, ComponentPackage::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageConfBasePackage");
			Uml::InitAssociationClass(ass, PackageConfBasePackage::meta);
			Uml::InitAssociationRole(ComponentPackage::meta_srcPackageConfBasePackage, ass, "srcPackageConfBasePackage", true, false, 0, -1, PackageConfiguration::meta);
			PackageConfBasePackage::meta_srcPackageConfBasePackage_end_ = PackageConfiguration::meta_dstPackageConfBasePackage_rev = ComponentPackage::meta_srcPackageConfBasePackage;
			Uml::InitAssociationRole(PackageConfiguration::meta_dstPackageConfBasePackage, ass, "dstPackageConfBasePackage", true, false, 0, 1, ComponentPackage::meta);
			PackageConfBasePackage::meta_dstPackageConfBasePackage_end_ = ComponentPackage::meta_srcPackageConfBasePackage_rev = PackageConfiguration::meta_dstPackageConfBasePackage;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageConfReference");
			Uml::InitAssociationClass(ass, PackageConfReference::meta);
			Uml::InitAssociationRole(ComponentPackageReference::meta_srcPackageConfReference, ass, "srcPackageConfReference", true, false, 0, -1, PackageConfiguration::meta);
			PackageConfReference::meta_srcPackageConfReference_end_ = PackageConfiguration::meta_dstPackageConfReference_rev = ComponentPackageReference::meta_srcPackageConfReference;
			Uml::InitAssociationRole(PackageConfiguration::meta_dstPackageConfReference, ass, "dstPackageConfReference", true, false, 0, 1, ComponentPackageReference::meta);
			PackageConfReference::meta_dstPackageConfReference_end_ = ComponentPackageReference::meta_srcPackageConfReference_rev = PackageConfiguration::meta_dstPackageConfReference;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "Implements");
			Uml::InitAssociationClass(ass, Implements::meta);
			Uml::InitAssociationRole(ComponentImplementation::meta_dstImplements, ass, "dstImplements", true, false, 0, -1, ComponentType::meta);
			Implements::meta_dstImplements_end_ = ComponentType::meta_srcImplements_rev = ComponentImplementation::meta_dstImplements;
			Uml::InitAssociationRole(ComponentType::meta_srcImplements, ass, "srcImplements", true, false, 0, -1, ComponentImplementation::meta);
			Implements::meta_srcImplements_end_ = ComponentImplementation::meta_dstImplements_rev = ComponentType::meta_srcImplements;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ComponentImplementation::meta_referedbyComponentImplementationReference, ass, "referedbyComponentImplementationReference", true, false, 0, -1, ComponentImplementationReference::meta);
			Uml::InitAssociationRole(ComponentImplementationReference::meta_ref, ass, "ref", true, false, 0, 1, ComponentImplementation::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "MonolithprimaryArtifact");
			Uml::InitAssociationClass(ass, MonolithprimaryArtifact::meta);
			Uml::InitAssociationRole(MonolithicImplementation::meta_dstMonolithprimaryArtifact, ass, "dstMonolithprimaryArtifact", true, false, 0, -1, ImplementationArtifactReference::meta);
			MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_ = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev = MonolithicImplementation::meta_dstMonolithprimaryArtifact;
			Uml::InitAssociationRole(ImplementationArtifactReference::meta_srcMonolithprimaryArtifact, ass, "srcMonolithprimaryArtifact", true, false, 0, -1, MonolithicImplementation::meta);
			MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_ = MonolithicImplementation::meta_dstMonolithprimaryArtifact_rev = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ComponentProperty");
			Uml::InitAssociationClass(ass, ComponentProperty::meta);
			Uml::InitAssociationRole(ComponentPropertyDescription::meta_srcComponentProperty, ass, "srcComponentProperty", true, false, 0, -1, ComponentType::meta);
			ComponentProperty::meta_srcComponentProperty_end_ = ComponentType::meta_dstComponentProperty_rev = ComponentPropertyDescription::meta_srcComponentProperty;
			Uml::InitAssociationRole(ComponentType::meta_dstComponentProperty, ass, "dstComponentProperty", true, false, 0, -1, ComponentPropertyDescription::meta);
			ComponentProperty::meta_dstComponentProperty_end_ = ComponentPropertyDescription::meta_srcComponentProperty_rev = ComponentType::meta_dstComponentProperty;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ComponentType::meta_ref, ass, "ref", true, false, 0, 1, Component::meta);
			Uml::InitAssociationRole(Component::meta_referedbyComponentType, ass, "referedbyComponentType", true, false, 0, -1, ComponentType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ComponentType::meta_CollocationGroup, ass, "CollocationGroup", true, false, 0, -1, CollocationGroup::meta);
			Uml::InitAssociationRole(CollocationGroup::meta_members, ass, "members", true, false, 0, -1, ComponentType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "Shares");
			Uml::InitAssociationClass(ass, Shares::meta);
			Uml::InitAssociationRole(SharedResource::meta_srcShares, ass, "srcShares", true, false, 1, -1, Node::meta);
			Shares::meta_srcShares_end_ = Node::meta_dstShares_rev = SharedResource::meta_srcShares;
			Uml::InitAssociationRole(Node::meta_dstShares, ass, "dstShares", true, false, 0, -1, SharedResource::meta);
			Shares::meta_dstShares_end_ = SharedResource::meta_srcShares_rev = Node::meta_dstShares;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "InstanceMapping");
			Uml::InitAssociationClass(ass, InstanceMapping::meta);
			Uml::InitAssociationRole(NodeReference::meta_srcInstanceMapping, ass, "srcInstanceMapping", true, false, 0, -1, CollocationGroup::meta);
			InstanceMapping::meta_srcInstanceMapping_end_ = CollocationGroup::meta_dstInstanceMapping_rev = NodeReference::meta_srcInstanceMapping;
			Uml::InitAssociationRole(CollocationGroup::meta_dstInstanceMapping, ass, "dstInstanceMapping", true, false, 0, -1, NodeReference::meta);
			InstanceMapping::meta_dstInstanceMapping_end_ = NodeReference::meta_srcInstanceMapping_rev = CollocationGroup::meta_dstInstanceMapping;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(NodeReference::meta_ref, ass, "ref", true, false, 0, 1, Node::meta);
			Uml::InitAssociationRole(Node::meta_referedbyNodeReference, ass, "referedbyNodeReference", true, false, 0, -1, NodeReference::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "Interconnect2Bridge");
			Uml::InitAssociationClass(ass, Interconnect2Bridge::meta);
			Uml::InitAssociationRole(Bridge::meta_srcInterconnect2Bridge, ass, "srcInterconnect2Bridge", true, false, 1, -1, Interconnect::meta);
			Interconnect2Bridge::meta_srcInterconnect2Bridge_end_ = Interconnect::meta_dstInterconnect2Bridge_rev = Bridge::meta_srcInterconnect2Bridge;
			Uml::InitAssociationRole(Interconnect::meta_dstInterconnect2Bridge, ass, "dstInterconnect2Bridge", true, false, 0, -1, Bridge::meta);
			Interconnect2Bridge::meta_dstInterconnect2Bridge_end_ = Bridge::meta_srcInterconnect2Bridge_rev = Interconnect::meta_dstInterconnect2Bridge;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "Bridge2Interconnect");
			Uml::InitAssociationClass(ass, Bridge2Interconnect::meta);
			Uml::InitAssociationRole(Bridge::meta_dstBridge2Interconnect, ass, "dstBridge2Interconnect", true, false, 1, -1, Interconnect::meta);
			Bridge2Interconnect::meta_dstBridge2Interconnect_end_ = Interconnect::meta_srcBridge2Interconnect_rev = Bridge::meta_dstBridge2Interconnect;
			Uml::InitAssociationRole(Interconnect::meta_srcBridge2Interconnect, ass, "srcBridge2Interconnect", true, false, 0, -1, Bridge::meta);
			Bridge2Interconnect::meta_srcBridge2Interconnect_end_ = Bridge::meta_dstBridge2Interconnect_rev = Interconnect::meta_srcBridge2Interconnect;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "Node2Interconnect");
			Uml::InitAssociationClass(ass, Node2Interconnect::meta);
			Uml::InitAssociationRole(Node::meta_dstNode2Interconnect, ass, "dstNode2Interconnect", true, false, 0, -1, Interconnect::meta);
			Node2Interconnect::meta_dstNode2Interconnect_end_ = Interconnect::meta_srcNode2Interconnect_rev = Node::meta_dstNode2Interconnect;
			Uml::InitAssociationRole(Interconnect::meta_srcNode2Interconnect, ass, "srcNode2Interconnect", true, false, 1, -1, Node::meta);
			Node2Interconnect::meta_srcNode2Interconnect_end_ = Node::meta_dstNode2Interconnect_rev = Interconnect::meta_srcNode2Interconnect;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "Interconnect2Node");
			Uml::InitAssociationClass(ass, Interconnect2Node::meta);
			Uml::InitAssociationRole(Node::meta_srcInterconnect2Node, ass, "srcInterconnect2Node", true, false, 0, -1, Interconnect::meta);
			Interconnect2Node::meta_srcInterconnect2Node_end_ = Interconnect::meta_dstInterconnect2Node_rev = Node::meta_srcInterconnect2Node;
			Uml::InitAssociationRole(Interconnect::meta_dstInterconnect2Node, ass, "dstInterconnect2Node", true, false, 1, -1, Node::meta);
			Interconnect2Node::meta_dstInterconnect2Node_end_ = Node::meta_srcInterconnect2Node_rev = Interconnect::meta_dstInterconnect2Node;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(PackageConfigurationReference::meta_ref, ass, "ref", true, false, 0, 1, PackageConfiguration::meta);
			Uml::InitAssociationRole(PackageConfiguration::meta_referedbyPackageConfigurationReference, ass, "referedbyPackageConfigurationReference", true, false, 0, -1, PackageConfigurationReference::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "PackageConfSpecializedConfig");
			Uml::InitAssociationClass(ass, PackageConfSpecializedConfig::meta);
			Uml::InitAssociationRole(PackageConfigurationReference::meta_srcPackageConfSpecializedConfig, ass, "srcPackageConfSpecializedConfig", true, false, 0, -1, PackageConfiguration::meta);
			PackageConfSpecializedConfig::meta_srcPackageConfSpecializedConfig_end_ = PackageConfiguration::meta_dstPackageConfSpecializedConfig_rev = PackageConfigurationReference::meta_srcPackageConfSpecializedConfig;
			Uml::InitAssociationRole(PackageConfiguration::meta_dstPackageConfSpecializedConfig, ass, "dstPackageConfSpecializedConfig", true, false, 0, 1, PackageConfigurationReference::meta);
			PackageConfSpecializedConfig::meta_dstPackageConfSpecializedConfig_end_ = PackageConfigurationReference::meta_srcPackageConfSpecializedConfig_rev = PackageConfiguration::meta_dstPackageConfSpecializedConfig;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ArtifactDependsOn");
			Uml::InitAssociationClass(ass, ArtifactDependsOn::meta);
			Uml::InitAssociationRole(ImplementationArtifact::meta_dstArtifactDependsOn, ass, "dstArtifactDependsOn", true, false, 0, -1, ImplementationArtifactReference::meta);
			ArtifactDependsOn::meta_dstArtifactDependsOn_end_ = ImplementationArtifactReference::meta_srcArtifactDependsOn_rev = ImplementationArtifact::meta_dstArtifactDependsOn;
			Uml::InitAssociationRole(ImplementationArtifactReference::meta_srcArtifactDependsOn, ass, "srcArtifactDependsOn", true, false, 0, -1, ImplementationArtifact::meta);
			ArtifactDependsOn::meta_srcArtifactDependsOn_end_ = ImplementationArtifact::meta_dstArtifactDependsOn_rev = ImplementationArtifactReference::meta_srcArtifactDependsOn;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ImplementationArtifact::meta_referedbyImplementationArtifactReference, ass, "referedbyImplementationArtifactReference", true, false, 0, -1, ImplementationArtifactReference::meta);
			Uml::InitAssociationRole(ImplementationArtifactReference::meta_ref, ass, "ref", true, false, 0, 1, ImplementationArtifact::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyInParameter, ass, "referedbyInParameter", true, false, 0, -1, InParameter::meta);
			Uml::InitAssociationRole(InParameter::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyInoutParameter, ass, "referedbyInoutParameter", true, false, 0, -1, InoutParameter::meta);
			Uml::InitAssociationRole(InoutParameter::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyOutParameter, ass, "referedbyOutParameter", true, false, 0, -1, OutParameter::meta);
			Uml::InitAssociationRole(OutParameter::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyReturnType, ass, "referedbyReturnType", true, false, 0, -1, ReturnType::meta);
			Uml::InitAssociationRole(ReturnType::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Exception::meta_referedbySetException, ass, "referedbySetException", true, false, 0, -1, SetException::meta);
			Uml::InitAssociationRole(SetException::meta_ref, ass, "ref", true, false, 0, 1, Exception::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Exception::meta_referedbyExceptionRef, ass, "referedbyExceptionRef", true, false, 0, -1, ExceptionRef::meta);
			Uml::InitAssociationRole(ExceptionRef::meta_ref, ass, "ref", true, false, 0, 1, Exception::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Exception::meta_referedbyGetException, ass, "referedbyGetException", true, false, 0, -1, GetException::meta);
			Uml::InitAssociationRole(GetException::meta_ref, ass, "ref", true, false, 0, 1, Exception::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ConstantType::meta_referedbyDiscriminator, ass, "referedbyDiscriminator", true, false, 0, -1, Discriminator::meta);
			Uml::InitAssociationRole(Discriminator::meta_ref, ass, "ref", true, false, 0, 1, ConstantType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ConstantType::meta_referedbyConstant, ass, "referedbyConstant", true, false, 0, -1, Constant::meta);
			Uml::InitAssociationRole(Constant::meta_ref, ass, "ref", true, false, 0, 1, ConstantType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(File::meta_referedbyFileRef, ass, "referedbyFileRef", true, false, 0, -1, FileRef::meta);
			Uml::InitAssociationRole(FileRef::meta_ref, ass, "ref", true, false, 0, 1, File::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Member::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
			Uml::InitAssociationRole(MemberType::meta_referedbyMember, ass, "referedbyMember", true, false, 0, -1, Member::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "LabelConnection");
			Uml::InitAssociationClass(ass, LabelConnection::meta);
			Uml::InitAssociationRole(Member::meta_dstLabelConnection, ass, "dstLabelConnection", true, false, 0, -1, Label::meta);
			LabelConnection::meta_dstLabelConnection_end_ = Label::meta_srcLabelConnection_rev = Member::meta_dstLabelConnection;
			Uml::InitAssociationRole(Label::meta_srcLabelConnection, ass, "srcLabelConnection", true, false, 1, 1, Member::meta);
			LabelConnection::meta_srcLabelConnection_end_ = Member::meta_dstLabelConnection_rev = Label::meta_srcLabelConnection;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "MakeMemberPrivate");
			Uml::InitAssociationClass(ass, MakeMemberPrivate::meta);
			Uml::InitAssociationRole(Member::meta_dstMakeMemberPrivate, ass, "dstMakeMemberPrivate", true, false, 0, 1, PrivateFlag::meta);
			MakeMemberPrivate::meta_dstMakeMemberPrivate_end_ = PrivateFlag::meta_srcMakeMemberPrivate_rev = Member::meta_dstMakeMemberPrivate;
			Uml::InitAssociationRole(PrivateFlag::meta_srcMakeMemberPrivate, ass, "srcMakeMemberPrivate", true, false, 1, 1, Member::meta);
			MakeMemberPrivate::meta_srcMakeMemberPrivate_end_ = Member::meta_dstMakeMemberPrivate_rev = PrivateFlag::meta_srcMakeMemberPrivate;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyBoxed, ass, "referedbyBoxed", true, false, 0, -1, Boxed::meta);
			Uml::InitAssociationRole(Boxed::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyAlias, ass, "referedbyAlias", true, false, 0, -1, Alias::meta);
			Uml::InitAssociationRole(Alias::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyCollection, ass, "referedbyCollection", true, false, 0, -1, Collection::meta);
			Uml::InitAssociationRole(Collection::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(MemberType::meta_referedbyAttributeMember, ass, "referedbyAttributeMember", true, false, 0, -1, AttributeMember::meta);
			Uml::InitAssociationRole(AttributeMember::meta_ref, ass, "ref", true, false, 0, 1, MemberType::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ValueObject::meta_referedbyLookupKey, ass, "referedbyLookupKey", true, false, 0, -1, LookupKey::meta);
			Uml::InitAssociationRole(LookupKey::meta_ref, ass, "ref", true, false, 0, 1, ValueObject::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Object::meta_referedbySupports, ass, "referedbySupports", true, false, 0, -1, Supports::meta);
			Uml::InitAssociationRole(Supports::meta_ref, ass, "ref", true, false, 0, 1, Object::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Inheritable::meta_referedbyInherits, ass, "referedbyInherits", true, false, 0, -1, Inherits::meta);
			Uml::InitAssociationRole(Inherits::meta_ref, ass, "ref", true, false, 0, 1, Inheritable::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Event::meta_referedbyInEventPort, ass, "referedbyInEventPort", true, false, 0, -1, InEventPort::meta);
			Uml::InitAssociationRole(InEventPort::meta_ref, ass, "ref", true, false, 0, 1, Event::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Event::meta_referedbyOutEventPort, ass, "referedbyOutEventPort", true, false, 0, -1, OutEventPort::meta);
			Uml::InitAssociationRole(OutEventPort::meta_ref, ass, "ref", true, false, 0, 1, Event::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "emit");
			Uml::InitAssociationClass(ass, emit::meta);
			Uml::InitAssociationRole(OutEventPort::meta_dstemit, ass, "dstemit", true, false, 0, 1, InEventPort::meta);
			emit::meta_dstemit_end_ = InEventPort::meta_srcemit_rev = OutEventPort::meta_dstemit;
			Uml::InitAssociationRole(InEventPort::meta_srcemit, ass, "srcemit", true, false, 0, 1, OutEventPort::meta);
			emit::meta_srcemit_end_ = OutEventPort::meta_dstemit_rev = InEventPort::meta_srcemit;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "invoke");
			Uml::InitAssociationClass(ass, invoke::meta);
			Uml::InitAssociationRole(ProvidedRequestPort::meta_srcinvoke, ass, "srcinvoke", true, false, 0, -1, RequiredRequestPort::meta);
			invoke::meta_srcinvoke_end_ = RequiredRequestPort::meta_dstinvoke_rev = ProvidedRequestPort::meta_srcinvoke;
			Uml::InitAssociationRole(RequiredRequestPort::meta_dstinvoke, ass, "dstinvoke", true, false, 0, -1, ProvidedRequestPort::meta);
			invoke::meta_dstinvoke_end_ = ProvidedRequestPort::meta_srcinvoke_rev = RequiredRequestPort::meta_dstinvoke;
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(ProvidedRequestPort::meta_ref, ass, "ref", true, false, 0, 1, Provideable::meta);
			Uml::InitAssociationRole(Provideable::meta_referedbyProvidedRequestPort, ass, "referedbyProvidedRequestPort", true, false, 0, -1, ProvidedRequestPort::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(Component::meta_referedbyComponentRef, ass, "referedbyComponentRef", true, false, 0, -1, ComponentRef::meta);
			Uml::InitAssociationRole(ComponentRef::meta_ref, ass, "ref", true, false, 0, 1, Component::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "");
			Uml::InitAssociationRole(RequiredRequestPort::meta_ref, ass, "ref", true, false, 0, 1, Provideable::meta);
			Uml::InitAssociationRole(Provideable::meta_referedbyRequiredRequestPort, ass, "referedbyRequiredRequestPort", true, false, 0, -1, RequiredRequestPort::meta);
		}
		{
			Uml::Association ass = Uml::CreateAssociation();
			Uml::InitAssociation(ass , umldiagram, "ManagesComponent");
			Uml::InitAssociationClass(ass, ManagesComponent::meta);
			Uml::InitAssociationRole(Manageable::meta_srcManagesComponent, ass, "srcManagesComponent", true, false, 0, -1, ComponentFactory::meta);
			ManagesComponent::meta_srcManagesComponent_end_ = ComponentFactory::meta_dstManagesComponent_rev = Manageable::meta_srcManagesComponent;
			Uml::InitAssociationRole(ComponentFactory::meta_dstManagesComponent, ass, "dstManagesComponent", true, false, 1, 1, Manageable::meta);
			ManagesComponent::meta_dstManagesComponent_end_ = Manageable::meta_srcManagesComponent_rev = ComponentFactory::meta_dstManagesComponent;
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(DataType::meta_Property_parent, comp, "Property_parent", true, Property::meta);
			Uml::InitCompositionChildRole(Property::meta_DataType_child, comp, "DataType", true, 1, 1, DataType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(SatisfierProperty::meta_RequirementSatisfier_parent, comp, "RequirementSatisfier_parent", true, RequirementSatisfier::meta);
			Uml::InitCompositionChildRole(RequirementSatisfier::meta_SatisfierProperty_children, comp, "SatisfierProperty", true, 0, -1, SatisfierProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_RequirementBase_parent, comp, "RequirementBase_parent", true, RequirementBase::meta);
			Uml::InitCompositionChildRole(RequirementBase::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(DataType::meta_SatisfierProperty_parent, comp, "SatisfierProperty_parent", true, SatisfierProperty::meta);
			Uml::InitCompositionChildRole(SatisfierProperty::meta_DataType_child, comp, "DataType", true, 1, 1, DataType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentPackage::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_ComponentPackage_children, comp, "ComponentPackage", true, 0, -1, ComponentPackage::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentPackageReference::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_ComponentPackageReference_children, comp, "ComponentPackageReference", true, 0, -1, ComponentPackageReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(invoke::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_invoke_children, comp, "invoke", true, 0, -1, invoke::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(AssemblyConfigProperty::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_AssemblyConfigProperty_children, comp, "AssemblyConfigProperty", true, 0, -1, AssemblyConfigProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(emit::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_emit_children, comp, "emit", true, 0, -1, emit::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Component::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_Component_children, comp, "Component", true, 1, -1, Component::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(AssemblyDeployRequirement::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_AssemblyDeployRequirement_children, comp, "AssemblyDeployRequirement", true, 0, -1, AssemblyDeployRequirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Requirement::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_Requirement_children, comp, "Requirement", true, 0, -1, Requirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(publish::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_publish_children, comp, "publish", true, 0, -1, publish::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PublishConnector::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_PublishConnector_children, comp, "PublishConnector", true, 0, -1, PublishConnector::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(AssemblyselectRequirement::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_AssemblyselectRequirement_children, comp, "AssemblyselectRequirement", true, 0, -1, AssemblyselectRequirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(deliverTo::meta_ComponentAssembly_parent, comp, "ComponentAssembly_parent", true, ComponentAssembly::meta);
			Uml::InitCompositionChildRole(ComponentAssembly::meta_deliverTo_children, comp, "deliverTo", true, 0, -1, deliverTo::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(TopLevelPackageContainer::meta_TopLevelPackageFolder_parent, comp, "TopLevelPackageFolder_parent", true, TopLevelPackageFolder::meta);
			Uml::InitCompositionChildRole(TopLevelPackageFolder::meta_TopLevelPackageContainer_children, comp, "TopLevelPackageContainer", true, 0, -1, TopLevelPackageContainer::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfigurationReference::meta_TopLevelPackageContainer_parent, comp, "TopLevelPackageContainer_parent", true, TopLevelPackageContainer::meta);
			Uml::InitCompositionChildRole(TopLevelPackageContainer::meta_PackageConfigurationReference_child, comp, "PackageConfigurationReference", true, 1, 1, PackageConfigurationReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(package::meta_TopLevelPackageContainer_parent, comp, "TopLevelPackageContainer_parent", true, TopLevelPackageContainer::meta);
			Uml::InitCompositionChildRole(TopLevelPackageContainer::meta_package_child, comp, "package", true, 0, 1, package::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(TopLevelPackage::meta_TopLevelPackageContainer_parent, comp, "TopLevelPackageContainer_parent", true, TopLevelPackageContainer::meta);
			Uml::InitCompositionChildRole(TopLevelPackageContainer::meta_TopLevelPackage_child, comp, "TopLevelPackage", true, 0, 1, TopLevelPackage::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageContainer::meta_ComponentPackages_parent, comp, "ComponentPackages_parent", true, ComponentPackages::meta);
			Uml::InitCompositionChildRole(ComponentPackages::meta_PackageContainer_children, comp, "PackageContainer", true, 0, -1, PackageContainer::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageInfoProperty::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_PackageInfoProperty_children, comp, "PackageInfoProperty", true, 0, -1, PackageInfoProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentImplementationReference::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_ComponentImplementationReference_children, comp, "ComponentImplementationReference", true, 0, -1, ComponentImplementationReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfigProperty::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_PackageConfigProperty_children, comp, "PackageConfigProperty", true, 0, -1, PackageConfigProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentPackage::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_ComponentPackage_child, comp, "ComponentPackage", true, 0, 1, ComponentPackage::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentType::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_ComponentType_children, comp, "ComponentType", true, 0, -1, ComponentType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageInterface::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_PackageInterface_child, comp, "PackageInterface", true, 0, 1, PackageInterface::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Implementation::meta_PackageContainer_parent, comp, "PackageContainer_parent", true, PackageContainer::meta);
			Uml::InitCompositionChildRole(PackageContainer::meta_Implementation_children, comp, "Implementation", true, 0, -1, Implementation::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Capability::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_Capability_children, comp, "Capability", true, 0, -1, Capability::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(InfoProperty::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_InfoProperty_children, comp, "InfoProperty", true, 0, -1, InfoProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentType::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ComponentType_children, comp, "ComponentType", true, 0, -1, ComponentType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationDependency::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ImplementationDependency_children, comp, "ImplementationDependency", true, 0, -1, ImplementationDependency::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(MonolithDeployRequirement::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_MonolithDeployRequirement_children, comp, "MonolithDeployRequirement", true, 0, -1, MonolithDeployRequirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ConfigProperty::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ConfigProperty_children, comp, "ConfigProperty", true, 0, -1, ConfigProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(MonolithExecParameter::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_MonolithExecParameter_children, comp, "MonolithExecParameter", true, 0, -1, MonolithExecParameter::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentImplementation::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ComponentImplementation_child, comp, "ComponentImplementation", true, 1, 1, ComponentImplementation::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationDependsOn::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ImplementationDependsOn_children, comp, "ImplementationDependsOn", true, 0, -1, ImplementationDependsOn::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Implements::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_Implements_children, comp, "Implements", true, 0, -1, Implements::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_MonolithprimaryArtifact_children, comp, "MonolithprimaryArtifact", true, 0, -1, MonolithprimaryArtifact::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationCapability::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ImplementationCapability_children, comp, "ImplementationCapability", true, 0, -1, ImplementationCapability::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationArtifactReference::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ImplementationArtifactReference_children, comp, "ImplementationArtifactReference", true, 0, -1, ImplementationArtifactReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationRequirement::meta_ComponentImplementationContainer_parent, comp, "ComponentImplementationContainer_parent", true, ComponentImplementationContainer::meta);
			Uml::InitCompositionChildRole(ComponentImplementationContainer::meta_ImplementationRequirement_children, comp, "ImplementationRequirement", true, 0, -1, ImplementationRequirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentImplementationContainer::meta_ComponentImplementations_parent, comp, "ComponentImplementations_parent", true, ComponentImplementations::meta);
			Uml::InitCompositionChildRole(ComponentImplementations::meta_ComponentImplementationContainer_children, comp, "ComponentImplementationContainer", true, 0, -1, ComponentImplementationContainer::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentProperty::meta_ComponentContainer_parent, comp, "ComponentContainer_parent", true, ComponentContainer::meta);
			Uml::InitCompositionChildRole(ComponentContainer::meta_ComponentProperty_children, comp, "ComponentProperty", true, 0, -1, ComponentProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentInfoProperty::meta_ComponentContainer_parent, comp, "ComponentContainer_parent", true, ComponentContainer::meta);
			Uml::InitCompositionChildRole(ComponentContainer::meta_ComponentInfoProperty_children, comp, "ComponentInfoProperty", true, 0, -1, ComponentInfoProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentPropertyDescription::meta_ComponentContainer_parent, comp, "ComponentContainer_parent", true, ComponentContainer::meta);
			Uml::InitCompositionChildRole(ComponentContainer::meta_ComponentPropertyDescription_children, comp, "ComponentPropertyDescription", true, 0, -1, ComponentPropertyDescription::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_ComponentContainer_parent, comp, "ComponentContainer_parent", true, ComponentContainer::meta);
			Uml::InitCompositionChildRole(ComponentContainer::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentConfigProperty::meta_ComponentContainer_parent, comp, "ComponentContainer_parent", true, ComponentContainer::meta);
			Uml::InitCompositionChildRole(ComponentContainer::meta_ComponentConfigProperty_children, comp, "ComponentConfigProperty", true, 0, -1, ComponentConfigProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentType::meta_ComponentContainer_parent, comp, "ComponentContainer_parent", true, ComponentContainer::meta);
			Uml::InitCompositionChildRole(ComponentContainer::meta_ComponentType_child, comp, "ComponentType", true, 0, 1, ComponentType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(DataType::meta_ComponentPropertyDescription_parent, comp, "ComponentPropertyDescription_parent", true, ComponentPropertyDescription::meta);
			Uml::InitCompositionChildRole(ComponentPropertyDescription::meta_DataType_child, comp, "DataType", true, 1, 1, DataType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentContainer::meta_ComponentTypes_parent, comp, "ComponentTypes_parent", true, ComponentTypes::meta);
			Uml::InitCompositionChildRole(ComponentTypes::meta_ComponentContainer_children, comp, "ComponentContainer", true, 0, -1, ComponentContainer::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(SatisfierProperty::meta_Resource_parent, comp, "Resource_parent", true, Resource::meta);
			Uml::InitCompositionChildRole(Resource::meta_SatisfierProperty_children, comp, "SatisfierProperty", true, 0, -1, SatisfierProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(SatisfierProperty::meta_SharedResource_parent, comp, "SharedResource_parent", true, SharedResource::meta);
			Uml::InitCompositionChildRole(SharedResource::meta_SatisfierProperty_children, comp, "SatisfierProperty", true, 0, -1, SatisfierProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Resource::meta_Bridge_parent, comp, "Bridge_parent", true, Bridge::meta);
			Uml::InitCompositionChildRole(Bridge::meta_Resource_children, comp, "Resource", true, 0, -1, Resource::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Resource::meta_Node_parent, comp, "Node_parent", true, Node::meta);
			Uml::InitCompositionChildRole(Node::meta_Resource_children, comp, "Resource", true, 0, -1, Resource::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Resource::meta_Interconnect_parent, comp, "Interconnect_parent", true, Interconnect::meta);
			Uml::InitCompositionChildRole(Interconnect::meta_Resource_children, comp, "Resource", true, 0, -1, Resource::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_Domain_parent, comp, "Domain_parent", true, Domain::meta);
			Uml::InitCompositionChildRole(Domain::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Elements::meta_Domain_parent, comp, "Domain_parent", true, Domain::meta);
			Uml::InitCompositionChildRole(Domain::meta_Elements_children, comp, "Elements", true, 0, -1, Elements::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Shares::meta_Domain_parent, comp, "Domain_parent", true, Domain::meta);
			Uml::InitCompositionChildRole(Domain::meta_Shares_children, comp, "Shares", true, 0, -1, Shares::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Interconnect2Node::meta_Domain_parent, comp, "Domain_parent", true, Domain::meta);
			Uml::InitCompositionChildRole(Domain::meta_Interconnect2Node_children, comp, "Interconnect2Node", true, 0, -1, Interconnect2Node::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Node2Interconnect::meta_Domain_parent, comp, "Domain_parent", true, Domain::meta);
			Uml::InitCompositionChildRole(Domain::meta_Node2Interconnect_children, comp, "Node2Interconnect", true, 0, -1, Node2Interconnect::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Interconnect2Bridge::meta_Domain_parent, comp, "Domain_parent", true, Domain::meta);
			Uml::InitCompositionChildRole(Domain::meta_Interconnect2Bridge_children, comp, "Interconnect2Bridge", true, 0, -1, Interconnect2Bridge::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Bridge2Interconnect::meta_Domain_parent, comp, "Domain_parent", true, Domain::meta);
			Uml::InitCompositionChildRole(Domain::meta_Bridge2Interconnect_children, comp, "Bridge2Interconnect", true, 0, -1, Bridge2Interconnect::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Domain::meta_Targets_parent, comp, "Targets_parent", true, Targets::meta);
			Uml::InitCompositionChildRole(Targets::meta_Domain_children, comp, "Domain", true, 0, -1, Domain::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(NodeReference::meta_DeploymentPlan_parent, comp, "DeploymentPlan_parent", true, DeploymentPlan::meta);
			Uml::InitCompositionChildRole(DeploymentPlan::meta_NodeReference_children, comp, "NodeReference", true, 0, -1, NodeReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(CollocationGroup::meta_DeploymentPlan_parent, comp, "DeploymentPlan_parent", true, DeploymentPlan::meta);
			Uml::InitCompositionChildRole(DeploymentPlan::meta_CollocationGroup_children, comp, "CollocationGroup", true, 0, -1, CollocationGroup::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentType::meta_DeploymentPlan_parent, comp, "DeploymentPlan_parent", true, DeploymentPlan::meta);
			Uml::InitCompositionChildRole(DeploymentPlan::meta_ComponentType_children, comp, "ComponentType", true, 0, -1, ComponentType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(InstanceMapping::meta_DeploymentPlan_parent, comp, "DeploymentPlan_parent", true, DeploymentPlan::meta);
			Uml::InitCompositionChildRole(DeploymentPlan::meta_InstanceMapping_children, comp, "InstanceMapping", true, 0, -1, InstanceMapping::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(DeploymentPlan::meta_DeploymentPlans_parent, comp, "DeploymentPlans_parent", true, DeploymentPlans::meta);
			Uml::InitCompositionChildRole(DeploymentPlans::meta_DeploymentPlan_children, comp, "DeploymentPlan", true, 0, -1, DeploymentPlan::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfigurationContainer::meta_PackageConfigurations_parent, comp, "PackageConfigurations_parent", true, PackageConfigurations::meta);
			Uml::InitCompositionChildRole(PackageConfigurations::meta_PackageConfigurationContainer_children, comp, "PackageConfigurationContainer", true, 0, -1, PackageConfigurationContainer::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentPackageReference::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_ComponentPackageReference_child, comp, "ComponentPackageReference", true, 0, 1, ComponentPackageReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfiguration::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_PackageConfiguration_children, comp, "PackageConfiguration", true, 0, -1, PackageConfiguration::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfConfigProperty::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_PackageConfConfigProperty_children, comp, "PackageConfConfigProperty", true, 0, -1, PackageConfConfigProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child, comp, "PackageConfSpecializedConfig", true, 0, 1, PackageConfSpecializedConfig::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfReference::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_PackageConfReference_child, comp, "PackageConfReference", true, 0, 1, PackageConfReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfBasePackage::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_PackageConfBasePackage_child, comp, "PackageConfBasePackage", true, 0, 1, PackageConfBasePackage::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Requirement::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_Requirement_children, comp, "Requirement", true, 0, -1, Requirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentPackage::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_ComponentPackage_child, comp, "ComponentPackage", true, 0, 1, ComponentPackage::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent, comp, "PackageConfigurationContainer_parent", true, PackageConfigurationContainer::meta);
			Uml::InitCompositionChildRole(PackageConfigurationContainer::meta_PackageConfSelectRequirement_children, comp, "PackageConfSelectRequirement", true, 0, -1, PackageConfSelectRequirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ArtifactContainer::meta_ImplementationArtifacts_parent, comp, "ImplementationArtifacts_parent", true, ImplementationArtifacts::meta);
			Uml::InitCompositionChildRole(ImplementationArtifacts::meta_ArtifactContainer_children, comp, "ArtifactContainer", true, 0, -1, ArtifactContainer::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationArtifactReference::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_ImplementationArtifactReference_children, comp, "ImplementationArtifactReference", true, 0, -1, ImplementationArtifactReference::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Property::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_Property_children, comp, "Property", true, 0, -1, Property::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ArtifactDeployRequirement::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_ArtifactDeployRequirement_children, comp, "ArtifactDeployRequirement", true, 0, -1, ArtifactDeployRequirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ArtifactExecParameter::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_ArtifactExecParameter_children, comp, "ArtifactExecParameter", true, 0, -1, ArtifactExecParameter::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Requirement::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_Requirement_children, comp, "Requirement", true, 0, -1, Requirement::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ArtifactInfoProperty::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_ArtifactInfoProperty_children, comp, "ArtifactInfoProperty", true, 0, -1, ArtifactInfoProperty::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ArtifactDependsOn::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_ArtifactDependsOn_children, comp, "ArtifactDependsOn", true, 0, -1, ArtifactDependsOn::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationArtifact::meta_ArtifactContainer_parent, comp, "ArtifactContainer_parent", true, ArtifactContainer::meta);
			Uml::InitCompositionChildRole(ArtifactContainer::meta_ImplementationArtifact_children, comp, "ImplementationArtifact", true, 1, -1, ImplementationArtifact::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(OutParameter::meta_TwowayOperation_parent, comp, "TwowayOperation_parent", true, TwowayOperation::meta);
			Uml::InitCompositionChildRole(TwowayOperation::meta_OutParameter_children, comp, "OutParameter", true, 0, -1, OutParameter::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ReturnType::meta_TwowayOperation_parent, comp, "TwowayOperation_parent", true, TwowayOperation::meta);
			Uml::InitCompositionChildRole(TwowayOperation::meta_ReturnType_child, comp, "ReturnType", true, 0, 1, ReturnType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(InoutParameter::meta_TwowayOperation_parent, comp, "TwowayOperation_parent", true, TwowayOperation::meta);
			Uml::InitCompositionChildRole(TwowayOperation::meta_InoutParameter_children, comp, "InoutParameter", true, 0, -1, InoutParameter::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ExceptionRef::meta_HasExceptions_parent, comp, "HasExceptions_parent", true, HasExceptions::meta);
			Uml::InitCompositionChildRole(HasExceptions::meta_ExceptionRef_children, comp, "ExceptionRef", true, 0, -1, ExceptionRef::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(InParameter::meta_OperationBase_parent, comp, "OperationBase_parent", true, OperationBase::meta);
			Uml::InitCompositionChildRole(OperationBase::meta_InParameter_children, comp, "InParameter", true, 0, -1, InParameter::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Member::meta_Exception_parent, comp, "Exception_parent", true, Exception::meta);
			Uml::InitCompositionChildRole(Exception::meta_Member_children, comp, "Member", true, 0, -1, Member::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Package::meta_Package_parent, comp, "Package_parent", true, Package::meta);
			Uml::InitCompositionChildRole(Package::meta_Package_children, comp, "Package", true, 0, -1, Package::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentRef::meta_Package_parent, comp, "Package_parent", true, Package::meta);
			Uml::InitCompositionChildRole(Package::meta_ComponentRef_children, comp, "ComponentRef", true, 0, -1, ComponentRef::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ManagesComponent::meta_Package_parent, comp, "Package_parent", true, Package::meta);
			Uml::InitCompositionChildRole(Package::meta_ManagesComponent_children, comp, "ManagesComponent", true, 0, -1, ManagesComponent::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(NamedType::meta_Package_parent, comp, "Package_parent", true, Package::meta);
			Uml::InitCompositionChildRole(Package::meta_NamedType_children, comp, "NamedType", true, 0, -1, NamedType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Constant::meta_Package_parent, comp, "Package_parent", true, Package::meta);
			Uml::InitCompositionChildRole(Package::meta_Constant_children, comp, "Constant", true, 0, -1, Constant::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Exception::meta_Package_parent, comp, "Package_parent", true, Package::meta);
			Uml::InitCompositionChildRole(Package::meta_Exception_children, comp, "Exception", true, 0, -1, Exception::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentRef::meta_File_parent, comp, "File_parent", true, File::meta);
			Uml::InitCompositionChildRole(File::meta_ComponentRef_children, comp, "ComponentRef", true, 0, -1, ComponentRef::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ManagesComponent::meta_File_parent, comp, "File_parent", true, File::meta);
			Uml::InitCompositionChildRole(File::meta_ManagesComponent_children, comp, "ManagesComponent", true, 0, -1, ManagesComponent::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(FileRef::meta_File_parent, comp, "File_parent", true, File::meta);
			Uml::InitCompositionChildRole(File::meta_FileRef_children, comp, "FileRef", true, 0, -1, FileRef::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(NamedType::meta_File_parent, comp, "File_parent", true, File::meta);
			Uml::InitCompositionChildRole(File::meta_NamedType_children, comp, "NamedType", true, 0, -1, NamedType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Constant::meta_File_parent, comp, "File_parent", true, File::meta);
			Uml::InitCompositionChildRole(File::meta_Constant_children, comp, "Constant", true, 0, -1, Constant::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Exception::meta_File_parent, comp, "File_parent", true, File::meta);
			Uml::InitCompositionChildRole(File::meta_Exception_children, comp, "Exception", true, 0, -1, Exception::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Package::meta_File_parent, comp, "File_parent", true, File::meta);
			Uml::InitCompositionChildRole(File::meta_Package_children, comp, "Package", true, 0, -1, Package::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(File::meta_InterfaceDefinitions_parent, comp, "InterfaceDefinitions_parent", true, InterfaceDefinitions::meta);
			Uml::InitCompositionChildRole(InterfaceDefinitions::meta_File_children, comp, "File", true, 1, -1, File::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(LabelConnection::meta_SwitchedAggregate_parent, comp, "SwitchedAggregate_parent", true, SwitchedAggregate::meta);
			Uml::InitCompositionChildRole(SwitchedAggregate::meta_LabelConnection_children, comp, "LabelConnection", true, 1, -1, LabelConnection::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Label::meta_SwitchedAggregate_parent, comp, "SwitchedAggregate_parent", true, SwitchedAggregate::meta);
			Uml::InitCompositionChildRole(SwitchedAggregate::meta_Label_children, comp, "Label", true, 1, -1, Label::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Member::meta_SwitchedAggregate_parent, comp, "SwitchedAggregate_parent", true, SwitchedAggregate::meta);
			Uml::InitCompositionChildRole(SwitchedAggregate::meta_Member_children, comp, "Member", true, 0, -1, Member::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Discriminator::meta_SwitchedAggregate_parent, comp, "SwitchedAggregate_parent", true, SwitchedAggregate::meta);
			Uml::InitCompositionChildRole(SwitchedAggregate::meta_Discriminator_child, comp, "Discriminator", true, 1, 1, Discriminator::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Member::meta_Aggregate_parent, comp, "Aggregate_parent", true, Aggregate::meta);
			Uml::InitCompositionChildRole(Aggregate::meta_Member_children, comp, "Member", true, 0, -1, Member::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(EnumValue::meta_Enum_parent, comp, "Enum_parent", true, Enum::meta);
			Uml::InitCompositionChildRole(Enum::meta_EnumValue_children, comp, "EnumValue", true, 1, -1, EnumValue::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PredefinedType::meta_PredefinedTypes_parent, comp, "PredefinedTypes_parent", true, PredefinedTypes::meta);
			Uml::InitCompositionChildRole(PredefinedTypes::meta_PredefinedType_children, comp, "PredefinedType", true, 0, -1, PredefinedType::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(SetException::meta_Attribute_parent, comp, "Attribute_parent", true, Attribute::meta);
			Uml::InitCompositionChildRole(Attribute::meta_SetException_children, comp, "SetException", true, 0, -1, SetException::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(AttributeMember::meta_ReadonlyAttribute_parent, comp, "ReadonlyAttribute_parent", true, ReadonlyAttribute::meta);
			Uml::InitCompositionChildRole(ReadonlyAttribute::meta_AttributeMember_child, comp, "AttributeMember", true, 1, 1, AttributeMember::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(GetException::meta_ReadonlyAttribute_parent, comp, "ReadonlyAttribute_parent", true, ReadonlyAttribute::meta);
			Uml::InitCompositionChildRole(ReadonlyAttribute::meta_GetException_children, comp, "GetException", true, 0, -1, GetException::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Supports::meta_SupportsInterfaces_parent, comp, "SupportsInterfaces_parent", true, SupportsInterfaces::meta);
			Uml::InitCompositionChildRole(SupportsInterfaces::meta_Supports_children, comp, "Supports", true, 0, -1, Supports::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(OnewayOperation::meta_HasOperations_parent, comp, "HasOperations_parent", true, HasOperations::meta);
			Uml::InitCompositionChildRole(HasOperations::meta_OnewayOperation_children, comp, "OnewayOperation", true, 0, -1, OnewayOperation::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(TwowayOperation::meta_HasOperations_parent, comp, "HasOperations_parent", true, HasOperations::meta);
			Uml::InitCompositionChildRole(HasOperations::meta_TwowayOperation_children, comp, "TwowayOperation", true, 0, -1, TwowayOperation::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(NoInheritable::meta_HasOperations_parent, comp, "HasOperations_parent", true, HasOperations::meta);
			Uml::InitCompositionChildRole(HasOperations::meta_NoInheritable_children, comp, "NoInheritable", true, 0, -1, NoInheritable::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Constant::meta_HasOperations_parent, comp, "HasOperations_parent", true, HasOperations::meta);
			Uml::InitCompositionChildRole(HasOperations::meta_Constant_children, comp, "Constant", true, 0, -1, Constant::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Exception::meta_HasOperations_parent, comp, "HasOperations_parent", true, HasOperations::meta);
			Uml::InitCompositionChildRole(HasOperations::meta_Exception_children, comp, "Exception", true, 0, -1, Exception::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Inherits::meta_Inheritable_parent, comp, "Inheritable_parent", true, Inheritable::meta);
			Uml::InitCompositionChildRole(Inheritable::meta_Inherits_children, comp, "Inherits", true, 0, -1, Inherits::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ReadonlyAttribute::meta_Inheritable_parent, comp, "Inheritable_parent", true, Inheritable::meta);
			Uml::InitCompositionChildRole(Inheritable::meta_ReadonlyAttribute_children, comp, "ReadonlyAttribute", true, 0, -1, ReadonlyAttribute::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PrivateFlag::meta_ObjectByValue_parent, comp, "ObjectByValue_parent", true, ObjectByValue::meta);
			Uml::InitCompositionChildRole(ObjectByValue::meta_PrivateFlag_children, comp, "PrivateFlag", true, 0, -1, PrivateFlag::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(MakeMemberPrivate::meta_ObjectByValue_parent, comp, "ObjectByValue_parent", true, ObjectByValue::meta);
			Uml::InitCompositionChildRole(ObjectByValue::meta_MakeMemberPrivate_children, comp, "MakeMemberPrivate", true, 0, -1, MakeMemberPrivate::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(FactoryOperation::meta_ObjectByValue_parent, comp, "ObjectByValue_parent", true, ObjectByValue::meta);
			Uml::InitCompositionChildRole(ObjectByValue::meta_FactoryOperation_children, comp, "FactoryOperation", true, 0, -1, FactoryOperation::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Member::meta_ObjectByValue_parent, comp, "ObjectByValue_parent", true, ObjectByValue::meta);
			Uml::InitCompositionChildRole(ObjectByValue::meta_Member_children, comp, "Member", true, 0, -1, Member::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Port::meta_Component_parent, comp, "Component_parent", true, Component::meta);
			Uml::InitCompositionChildRole(Component::meta_Port_children, comp, "Port", true, 0, -1, Port::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(LookupOperation::meta_ComponentFactory_parent, comp, "ComponentFactory_parent", true, ComponentFactory::meta);
			Uml::InitCompositionChildRole(ComponentFactory::meta_LookupOperation_children, comp, "LookupOperation", true, 0, -1, LookupOperation::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(FactoryOperation::meta_ComponentFactory_parent, comp, "ComponentFactory_parent", true, ComponentFactory::meta);
			Uml::InitCompositionChildRole(ComponentFactory::meta_FactoryOperation_children, comp, "FactoryOperation", true, 0, -1, FactoryOperation::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(LookupKey::meta_ComponentFactory_parent, comp, "ComponentFactory_parent", true, ComponentFactory::meta);
			Uml::InitCompositionChildRole(ComponentFactory::meta_LookupKey_child, comp, "LookupKey", true, 0, 1, LookupKey::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentPackages::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_ComponentPackages_children, comp, "ComponentPackages", true, 0, -1, ComponentPackages::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(TopLevelPackageFolder::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_TopLevelPackageFolder_children, comp, "TopLevelPackageFolder", true, 0, -1, TopLevelPackageFolder::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentImplementations::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_ComponentImplementations_children, comp, "ComponentImplementations", true, 0, -1, ComponentImplementations::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ComponentTypes::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_ComponentTypes_children, comp, "ComponentTypes", true, 0, -1, ComponentTypes::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(Targets::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_Targets_children, comp, "Targets", true, 0, -1, Targets::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(DeploymentPlans::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_DeploymentPlans_children, comp, "DeploymentPlans", true, 0, -1, DeploymentPlans::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PackageConfigurations::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_PackageConfigurations_children, comp, "PackageConfigurations", true, 0, -1, PackageConfigurations::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(ImplementationArtifacts::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_ImplementationArtifacts_children, comp, "ImplementationArtifacts", true, 0, -1, ImplementationArtifacts::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(InterfaceDefinitions::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_InterfaceDefinitions_children, comp, "InterfaceDefinitions", true, 0, -1, InterfaceDefinitions::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(PredefinedTypes::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_PredefinedTypes_children, comp, "PredefinedTypes", true, 0, -1, PredefinedTypes::meta);
		}
		{
			Uml::Composition comp = Uml::CreateComposition();
			Uml::InitComposition(comp , umldiagram, "");
		
			Uml::InitCompositionParentRole(RootFolder::meta_RootFolder_parent, comp, "RootFolder_parent", true, RootFolder::meta);
			Uml::InitCompositionChildRole(RootFolder::meta_RootFolder_children, comp, "RootFolder", true, 0, -1, RootFolder::meta);
		}
		Uml::AddInheritance(RequirementSatisfier::meta, Capability::meta);
		Uml::AddInheritance(RequirementBase::meta, ImplementationRequirement::meta);
		Uml::AddInheritance(RequirementBase::meta, Requirement::meta);
		Uml::AddInheritance(ComponentImplementation::meta, ComponentAssembly::meta);
		Uml::AddInheritance(ComponentImplementation::meta, MonolithicImplementation::meta);
		Uml::AddInheritance(CommonPortAttrs::meta, Port::meta);
		Uml::AddInheritance(Elements::meta, SharedResource::meta);
		Uml::AddInheritance(Elements::meta, Bridge::meta);
		Uml::AddInheritance(Elements::meta, Node::meta);
		Uml::AddInheritance(Elements::meta, Interconnect::meta);
		Uml::AddInheritance(HasExceptions::meta, TwowayOperation::meta);
		Uml::AddInheritance(HasExceptions::meta, FactoryOperation::meta);
		Uml::AddInheritance(HasExceptions::meta, LookupOperation::meta);
		Uml::AddInheritance(OperationBase::meta, OnewayOperation::meta);
		Uml::AddInheritance(OperationBase::meta, HasExceptions::meta);
		Uml::AddInheritance(ConstantType::meta, Enum::meta);
		Uml::AddInheritance(ConstantType::meta, PredefinedType::meta);
		Uml::AddInheritance(NoInheritable::meta, SwitchedAggregate::meta);
		Uml::AddInheritance(NoInheritable::meta, Aggregate::meta);
		Uml::AddInheritance(NoInheritable::meta, Alias::meta);
		Uml::AddInheritance(NoInheritable::meta, Collection::meta);
		Uml::AddInheritance(NoInheritable::meta, Enum::meta);
		Uml::AddInheritance(MemberType::meta, NamedType::meta);
		Uml::AddInheritance(MemberType::meta, PredefinedType::meta);
		Uml::AddInheritance(NamedType::meta, NoInheritable::meta);
		Uml::AddInheritance(NamedType::meta, Boxed::meta);
		Uml::AddInheritance(NamedType::meta, Inheritable::meta);
		Uml::AddInheritance(Prefixable::meta, Package::meta);
		Uml::AddInheritance(Prefixable::meta, File::meta);
		Uml::AddInheritance(Prefixable::meta, ObjectByValue::meta);
		Uml::AddInheritance(Prefixable::meta, Object::meta);
		Uml::AddInheritance(Taggable::meta, OperationBase::meta);
		Uml::AddInheritance(Taggable::meta, Exception::meta);
		Uml::AddInheritance(Taggable::meta, Package::meta);
		Uml::AddInheritance(Taggable::meta, Constant::meta);
		Uml::AddInheritance(Taggable::meta, NamedType::meta);
		Uml::AddInheritance(Taggable::meta, ReadonlyAttribute::meta);
		Uml::AddInheritance(Taggable::meta, Port::meta);
		Uml::AddInheritance(PredefinedType::meta, Boolean::meta);
		Uml::AddInheritance(PredefinedType::meta, GenericValue::meta);
		Uml::AddInheritance(PredefinedType::meta, LongInteger::meta);
		Uml::AddInheritance(PredefinedType::meta, Byte::meta);
		Uml::AddInheritance(PredefinedType::meta, TypeKind::meta);
		Uml::AddInheritance(PredefinedType::meta, GenericObject::meta);
		Uml::AddInheritance(PredefinedType::meta, ShortInteger::meta);
		Uml::AddInheritance(PredefinedType::meta, RealNumber::meta);
		Uml::AddInheritance(PredefinedType::meta, String::meta);
		Uml::AddInheritance(PredefinedType::meta, TypeEncoding::meta);
		Uml::AddInheritance(PredefinedType::meta, GenericValueObject::meta);
		Uml::AddInheritance(ReadonlyAttribute::meta, Attribute::meta);
		Uml::AddInheritance(SupportsInterfaces::meta, ObjectByValue::meta);
		Uml::AddInheritance(SupportsInterfaces::meta, Component::meta);
		Uml::AddInheritance(SupportsInterfaces::meta, ComponentFactory::meta);
		Uml::AddInheritance(HasOperations::meta, ObjectByValue::meta);
		Uml::AddInheritance(HasOperations::meta, Object::meta);
		Uml::AddInheritance(HasOperations::meta, ComponentFactory::meta);
		Uml::AddInheritance(Inheritable::meta, SupportsInterfaces::meta);
		Uml::AddInheritance(Inheritable::meta, HasOperations::meta);
		Uml::AddInheritance(ObjectByValue::meta, ValueObject::meta);
		Uml::AddInheritance(ObjectByValue::meta, Event::meta);
		Uml::AddInheritance(Port::meta, OutEventPort::meta);
		Uml::AddInheritance(Port::meta, ProvidedRequestPort::meta);
		Uml::AddInheritance(Port::meta, RequiredRequestPort::meta);
		Uml::AddInheritance(Port::meta, InEventPort::meta);
		Uml::AddInheritance(Manageable::meta, Component::meta);
		Uml::AddInheritance(Manageable::meta, ComponentRef::meta);
		Uml::AddInheritance(Provideable::meta, GenericObject::meta);
		Uml::AddInheritance(Provideable::meta, Object::meta);
		Uml::AddInheritance(MgaObject::meta, Property::meta);
		Uml::AddInheritance(MgaObject::meta, RequirementSatisfier::meta);
		Uml::AddInheritance(MgaObject::meta, RequirementBase::meta);
		Uml::AddInheritance(MgaObject::meta, SatisfierProperty::meta);
		Uml::AddInheritance(MgaObject::meta, DataType::meta);
		Uml::AddInheritance(MgaObject::meta, ImplementationDependency::meta);
		Uml::AddInheritance(MgaObject::meta, AssemblyselectRequirement::meta);
		Uml::AddInheritance(MgaObject::meta, AssemblyConfigProperty::meta);
		Uml::AddInheritance(MgaObject::meta, PublishConnector::meta);
		Uml::AddInheritance(MgaObject::meta, publish::meta);
		Uml::AddInheritance(MgaObject::meta, deliverTo::meta);
		Uml::AddInheritance(MgaObject::meta, AssemblyDeployRequirement::meta);
		Uml::AddInheritance(MgaObject::meta, emit::meta);
		Uml::AddInheritance(MgaObject::meta, invoke::meta);
		Uml::AddInheritance(MgaObject::meta, package::meta);
		Uml::AddInheritance(MgaObject::meta, TopLevelPackageContainer::meta);
		Uml::AddInheritance(MgaObject::meta, TopLevelPackage::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentPackage::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentPackageReference::meta);
		Uml::AddInheritance(MgaObject::meta, Implementation::meta);
		Uml::AddInheritance(MgaObject::meta, PackageContainer::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfigProperty::meta);
		Uml::AddInheritance(MgaObject::meta, PackageInfoProperty::meta);
		Uml::AddInheritance(MgaObject::meta, PackageInterface::meta);
		Uml::AddInheritance(MgaObject::meta, InfoProperty::meta);
		Uml::AddInheritance(MgaObject::meta, MonolithprimaryArtifact::meta);
		Uml::AddInheritance(MgaObject::meta, MonolithDeployRequirement::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentImplementation::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentImplementationReference::meta);
		Uml::AddInheritance(MgaObject::meta, ConfigProperty::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentImplementationContainer::meta);
		Uml::AddInheritance(MgaObject::meta, MonolithExecParameter::meta);
		Uml::AddInheritance(MgaObject::meta, ImplementationDependsOn::meta);
		Uml::AddInheritance(MgaObject::meta, Implements::meta);
		Uml::AddInheritance(MgaObject::meta, ImplementationCapability::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentContainer::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentPropertyDescription::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentInfoProperty::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentProperty::meta);
		Uml::AddInheritance(MgaObject::meta, CommonPortAttrs::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentConfigProperty::meta);
		Uml::AddInheritance(MgaObject::meta, ComponentType::meta);
		Uml::AddInheritance(MgaObject::meta, Resource::meta);
		Uml::AddInheritance(MgaObject::meta, NodeReference::meta);
		Uml::AddInheritance(MgaObject::meta, Elements::meta);
		Uml::AddInheritance(MgaObject::meta, Domain::meta);
		Uml::AddInheritance(MgaObject::meta, Node2Interconnect::meta);
		Uml::AddInheritance(MgaObject::meta, Bridge2Interconnect::meta);
		Uml::AddInheritance(MgaObject::meta, Shares::meta);
		Uml::AddInheritance(MgaObject::meta, Interconnect2Node::meta);
		Uml::AddInheritance(MgaObject::meta, Interconnect2Bridge::meta);
		Uml::AddInheritance(MgaObject::meta, InstanceMapping::meta);
		Uml::AddInheritance(MgaObject::meta, DeploymentPlan::meta);
		Uml::AddInheritance(MgaObject::meta, CollocationGroup::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfigurationReference::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfConfigProperty::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfigurationContainer::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfReference::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfiguration::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfSpecializedConfig::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfSelectRequirement::meta);
		Uml::AddInheritance(MgaObject::meta, PackageConfBasePackage::meta);
		Uml::AddInheritance(MgaObject::meta, ArtifactExecParameter::meta);
		Uml::AddInheritance(MgaObject::meta, ArtifactDeployRequirement::meta);
		Uml::AddInheritance(MgaObject::meta, ImplementationArtifact::meta);
		Uml::AddInheritance(MgaObject::meta, ArtifactInfoProperty::meta);
		Uml::AddInheritance(MgaObject::meta, ArtifactContainer::meta);
		Uml::AddInheritance(MgaObject::meta, ArtifactDependsOn::meta);
		Uml::AddInheritance(MgaObject::meta, ImplementationArtifactReference::meta);
		Uml::AddInheritance(MgaObject::meta, InParameter::meta);
		Uml::AddInheritance(MgaObject::meta, InoutParameter::meta);
		Uml::AddInheritance(MgaObject::meta, OutParameter::meta);
		Uml::AddInheritance(MgaObject::meta, ReturnType::meta);
		Uml::AddInheritance(MgaObject::meta, ConstantType::meta);
		Uml::AddInheritance(MgaObject::meta, FileRef::meta);
		Uml::AddInheritance(MgaObject::meta, ExceptionRef::meta);
		Uml::AddInheritance(MgaObject::meta, Member::meta);
		Uml::AddInheritance(MgaObject::meta, EnumValue::meta);
		Uml::AddInheritance(MgaObject::meta, Label::meta);
		Uml::AddInheritance(MgaObject::meta, MemberType::meta);
		Uml::AddInheritance(MgaObject::meta, Discriminator::meta);
		Uml::AddInheritance(MgaObject::meta, LabelConnection::meta);
		Uml::AddInheritance(MgaObject::meta, Prefixable::meta);
		Uml::AddInheritance(MgaObject::meta, Taggable::meta);
		Uml::AddInheritance(MgaObject::meta, SetException::meta);
		Uml::AddInheritance(MgaObject::meta, LookupKey::meta);
		Uml::AddInheritance(MgaObject::meta, Supports::meta);
		Uml::AddInheritance(MgaObject::meta, MakeMemberPrivate::meta);
		Uml::AddInheritance(MgaObject::meta, PrivateFlag::meta);
		Uml::AddInheritance(MgaObject::meta, GetException::meta);
		Uml::AddInheritance(MgaObject::meta, Inherits::meta);
		Uml::AddInheritance(MgaObject::meta, AttributeMember::meta);
		Uml::AddInheritance(MgaObject::meta, ManagesComponent::meta);
		Uml::AddInheritance(MgaObject::meta, Manageable::meta);
		Uml::AddInheritance(MgaObject::meta, Provideable::meta);
		
	}
	 Udm::UdmDiagram diagram = { &umldiagram, Initialize };
	static struct _regClass
	{
		_regClass()
		{
			Udm::MetaDepository::StoreDiagram("PICML", diagram);
		};
		~_regClass()
		{
			Udm::MetaDepository::RemoveDiagram("PICML");
		};
	} __regUnUsed;

}
// END PICML.cpp
