// cpp(meta datanetwork format) source file PICML.cpp generated from diagram PICML
// generated on Tue May 11 01:41:14 2004

#include "PICML.h"
#include "UmlExt.h"

#include "UdmStatic.h"

// cross-package metainformation header file
#include "CadenaScenario2PICMLAssembly.h"

namespace PICML {

	Uml::Diagram umldiagram;

	Uml::Class ImplementationArtifactReference::meta;
	Uml::Class ImplementationArtifacts::meta;
	Uml::Class ArtifactDependsOn::meta;
	Uml::Class ArtifactDeployRequirement::meta;
	Uml::Class ArtifactContainer::meta;
	Uml::Class ArtifactExecParameter::meta;
	Uml::Class ArtifactInfoProperty::meta;
	Uml::Class ImplementationArtifact::meta;
	Uml::Class IDLFile::meta;
	Uml::Class IDLFiles::meta;
	Uml::Class ComponentType::meta;
	Uml::Class ComponentTypes::meta;
	Uml::Class ComponentConfigProperty::meta;
	Uml::Class ComponentInfoProperty::meta;
	Uml::Class CommonPortAttrs::meta;
	Uml::Class ComponentPropertyDescription::meta;
	Uml::Class ComponentProperty::meta;
	Uml::Class ComponentContainer::meta;
	Uml::Class ImplementationCapability::meta;
	Uml::Class ImplementationDependsOn::meta;
	Uml::Class Implements::meta;
	Uml::Class ComponentImplementations::meta;
	Uml::Class ComponentImplementationReference::meta;
	Uml::Class ConfigProperty::meta;
	Uml::Class InfoProperty::meta;
	Uml::Class MonolithprimaryArtifact::meta;
	Uml::Class MonolithDeployRequirement::meta;
	Uml::Class ComponentImplementation::meta;
	Uml::Class ComponentImplementationContainer::meta;
	Uml::Class MonolithExecParameter::meta;
	Uml::Class MonolithicImplementation::meta;
	Uml::Class RequirementBase::meta;
	Uml::Class ImplementationRequirement::meta;
	Uml::Class Requirement::meta;
	Uml::Class ImplementationDependency::meta;
	Uml::Class Any::meta;
	Uml::Class Property::meta;
	Uml::Class SatisfierProperty::meta;
	Uml::Class DataType::meta;
	Uml::Class RequirementSatisfier::meta;
	Uml::Class Capability::meta;
	Uml::Class PackageBaseConnection::meta;
	Uml::Class PackageReferenceConnection::meta;
	Uml::Class PackageConfigurationReference::meta;
	Uml::Class PackageConfiguration::meta;
	Uml::Class PackageConfigurations::meta;
	Uml::Class PackageConfigurationContainer::meta;
	Uml::Class PackageConfigurationProperty::meta;
	Uml::Class PackageSelectRequirement::meta;
	Uml::Class EmitConnector::meta;
	Uml::Class ComponentAssembly::meta;
	Uml::Class Invocation::meta;
	Uml::Class SubComponentSelectRequirement::meta;
	Uml::Class SubComponentConfigProperty::meta;
	Uml::Class PublishConnector::meta;
	Uml::Class OutEventPortPublish::meta;
	Uml::Class InEventPortConsume::meta;
	Uml::Class ConnectionRequirements::meta;
	Uml::Class ComponentPackages::meta;
	Uml::Class PackageInterface::meta;
	Uml::Class PackageImplementations::meta;
	Uml::Class PackageContainer::meta;
	Uml::Class PackageConfigProperty::meta;
	Uml::Class PackageInfoProperty::meta;
	Uml::Class ComponentPackage::meta;
	Uml::Class ComponentPackageReference::meta;
	Uml::Class TopLevelPackageContainer::meta;
	Uml::Class TopLevelPackageFolder::meta;
	Uml::Class TopLevelPackage::meta;
	Uml::Class TopLevelPackageConn::meta;
	Uml::Class EnumerationDef::meta;
	Uml::Class EnumValue::meta;
	Uml::Class AliasDef::meta;
	Uml::Class AggregateDef::meta;
	Uml::Class SwitchedAggregateDef::meta;
	Uml::Class Label::meta;
	Uml::Class Discriminator::meta;
	Uml::Class LabelConnection::meta;
	Uml::Class BoxedDef::meta;
	Uml::Class NamedTypeRef::meta;
	Uml::Class EnumRef::meta;
	Uml::Class NamedType::meta;
	Uml::Class Member::meta;
	Uml::Class NoInheritable::meta;
	Uml::Class IdTag::meta;
	Uml::Class PrefixTag::meta;
	Uml::Class GeneralTag::meta;
	Uml::Class SpecifyIdTag::meta;
	Uml::Class VersionTag::meta;
	Uml::Class Prefixable::meta;
	Uml::Class Taggable::meta;
	Uml::Class ReturnType::meta;
	Uml::Class InParameter::meta;
	Uml::Class InoutParameter::meta;
	Uml::Class OutParameter::meta;
	Uml::Class ParameterType::meta;
	Uml::Class OperationBase::meta;
	Uml::Class Parameter::meta;
	Uml::Class HasExceptions::meta;
	Uml::Class OnewayOperation::meta;
	Uml::Class LookupOperation::meta;
	Uml::Class FactoryOperation::meta;
	Uml::Class TwowayOperation::meta;
	Uml::Class Package::meta;
	Uml::Class Type::meta;
	Uml::Class ExceptionRef::meta;
	Uml::Class FileRef::meta;
	Uml::Class ConstantDef::meta;
	Uml::Class ExceptionDef::meta;
	Uml::Class RequestPort::meta;
	Uml::Class EventPort::meta;
	Uml::Class EventRef::meta;
	Uml::Class ObjectRef::meta;
	Uml::Class ProvidedRequestPort::meta;
	Uml::Class RequiredRequestPort::meta;
	Uml::Class OutEventPort::meta;
	Uml::Class InEventPort::meta;
	Uml::Class Port::meta;
	Uml::Class ComponentDef::meta;
	Uml::Class BoundedString::meta;
	Uml::Class FixedSizeCollection::meta;
	Uml::Class VariableSizeCollection::meta;
	Uml::Class AnonymousType::meta;
	Uml::Class CollectionType::meta;
	Uml::Class PredefinedType::meta;
	Uml::Class FixedPoint::meta;
	Uml::Class ObjectDef::meta;
	Uml::Class ComponentFactory::meta;
	Uml::Class Inherits::meta;
	Uml::Class EventDef::meta;
	Uml::Class ValueDef::meta;
	Uml::Class Inheritable::meta;
	Uml::Class HasOperations::meta;
	Uml::Class SupportsInterfaces::meta;
	Uml::Class Supports::meta;
	Uml::Class ReadonlyAttribute::meta;
	Uml::Class Attribute::meta;
	Uml::Class LookupKey::meta;
	Uml::Class Manages::meta;
	Uml::Class SetException::meta;
	Uml::Class ObjectByValue::meta;
	Uml::Class GetException::meta;
	Uml::Class PrivateFlag::meta;
	Uml::Class MakeMemberPrivate::meta;
	Uml::Class RootFolder::meta;
	Uml::Class MgaObject::meta;
	Uml::Attribute ImplementationArtifacts::meta_name;
	Uml::Attribute IDLFiles::meta_name;
	Uml::Attribute ComponentTypes::meta_name;
	Uml::Attribute ComponentImplementations::meta_name;
	Uml::Attribute PackageConfigurations::meta_name;
	Uml::Attribute ComponentPackages::meta_name;
	Uml::Attribute TopLevelPackageFolder::meta_name;
	Uml::Attribute ConstantDef::meta_value;
	Uml::Attribute RequiredRequestPort::meta_multiple_connections;
	Uml::Attribute OutEventPort::meta_single_destination;
	Uml::Attribute BoundedString::meta_wide;
	Uml::Attribute BoundedString::meta_bound;
	Uml::Attribute CollectionType::meta_bound;
	Uml::Attribute PredefinedType::meta_which_type;
	Uml::Attribute FixedPoint::meta_total_digits;
	Uml::Attribute FixedPoint::meta_decimal_digits;
	Uml::Attribute ObjectDef::meta_local;
	Uml::Attribute ObjectDef::meta_abstract;
	Uml::Attribute ObjectByValue::meta_custom;
	Uml::Attribute ObjectByValue::meta_abstract;
	Uml::Attribute ObjectByValue::meta_truncatable;
	Uml::Attribute RootFolder::meta_name;
	Uml::Attribute MgaObject::meta_position;
	Uml::Attribute MgaObject::meta_name;
	Uml::AssociationRole ImplementationArtifactReference::meta_srcArtifactDependsOn, ImplementationArtifactReference::meta_srcArtifactDependsOn_rev;
	Uml::AssociationRole ImplementationArtifactReference::meta_ref;
	Uml::AssociationRole ImplementationArtifactReference::meta_srcMonolithprimaryArtifact, ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev;
	Uml::AssociationRole ArtifactDependsOn::meta_dstArtifactDependsOn_end_;
	Uml::AssociationRole ArtifactDependsOn::meta_srcArtifactDependsOn_end_;
	Uml::AssociationRole ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_;
	Uml::AssociationRole ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_;
	Uml::AssociationRole ArtifactExecParameter::meta_dstArtifactExecParameter_end_;
	Uml::AssociationRole ArtifactExecParameter::meta_srcArtifactExecParameter_end_;
	Uml::AssociationRole ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_;
	Uml::AssociationRole ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDependsOn, ImplementationArtifact::meta_dstArtifactDependsOn_rev;
	Uml::AssociationRole ImplementationArtifact::meta_referedbyImplementationArtifactReference;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDeployRequirement, ImplementationArtifact::meta_dstArtifactDeployRequirement_rev;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactExecParameter, ImplementationArtifact::meta_dstArtifactExecParameter_rev;
	Uml::AssociationRole ImplementationArtifact::meta_dstArtifactInfoProperty, ImplementationArtifact::meta_dstArtifactInfoProperty_rev;
	Uml::AssociationRole IDLFile::meta_referedbyFileRef;
	Uml::AssociationRole ComponentType::meta_dstComponentConfigProperty, ComponentType::meta_dstComponentConfigProperty_rev;
	Uml::AssociationRole ComponentType::meta_dstComponentProperty, ComponentType::meta_dstComponentProperty_rev;
	Uml::AssociationRole ComponentType::meta_dstComponentInfoProperty, ComponentType::meta_dstComponentInfoProperty_rev;
	Uml::AssociationRole ComponentType::meta_ref;
	Uml::AssociationRole ComponentType::meta_srcImplements, ComponentType::meta_srcImplements_rev;
	Uml::AssociationRole ComponentType::meta_srcPackageInterface, ComponentType::meta_srcPackageInterface_rev;
	Uml::AssociationRole ComponentConfigProperty::meta_srcComponentConfigProperty_end_;
	Uml::AssociationRole ComponentConfigProperty::meta_dstComponentConfigProperty_end_;
	Uml::AssociationRole ComponentInfoProperty::meta_srcComponentInfoProperty_end_;
	Uml::AssociationRole ComponentInfoProperty::meta_dstComponentInfoProperty_end_;
	Uml::AssociationRole ComponentPropertyDescription::meta_srcComponentProperty, ComponentPropertyDescription::meta_srcComponentProperty_rev;
	Uml::AssociationRole ComponentProperty::meta_srcComponentProperty_end_;
	Uml::AssociationRole ComponentProperty::meta_dstComponentProperty_end_;
	Uml::AssociationRole ImplementationCapability::meta_dstImplementationCapability_end_;
	Uml::AssociationRole ImplementationCapability::meta_srcImplementationCapability_end_;
	Uml::AssociationRole ImplementationDependsOn::meta_dstImplementationDependsOn_end_;
	Uml::AssociationRole ImplementationDependsOn::meta_srcImplementationDependsOn_end_;
	Uml::AssociationRole Implements::meta_dstImplements_end_;
	Uml::AssociationRole Implements::meta_srcImplements_end_;
	Uml::AssociationRole ComponentImplementationReference::meta_srcPackageImplementations, ComponentImplementationReference::meta_srcPackageImplementations_rev;
	Uml::AssociationRole ComponentImplementationReference::meta_ref;
	Uml::AssociationRole ConfigProperty::meta_dstConfigProperty_end_;
	Uml::AssociationRole ConfigProperty::meta_srcConfigProperty_end_;
	Uml::AssociationRole InfoProperty::meta_dstInfoProperty_end_;
	Uml::AssociationRole InfoProperty::meta_srcInfoProperty_end_;
	Uml::AssociationRole MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_;
	Uml::AssociationRole MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_;
	Uml::AssociationRole MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_;
	Uml::AssociationRole MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_;
	Uml::AssociationRole ComponentImplementation::meta_dstImplements, ComponentImplementation::meta_dstImplements_rev;
	Uml::AssociationRole ComponentImplementation::meta_dstImplementationCapability, ComponentImplementation::meta_dstImplementationCapability_rev;
	Uml::AssociationRole ComponentImplementation::meta_dstImplementationDependsOn, ComponentImplementation::meta_dstImplementationDependsOn_rev;
	Uml::AssociationRole ComponentImplementation::meta_referedbyComponentImplementationReference;
	Uml::AssociationRole ComponentImplementation::meta_dstConfigProperty, ComponentImplementation::meta_dstConfigProperty_rev;
	Uml::AssociationRole ComponentImplementation::meta_dstInfoProperty, ComponentImplementation::meta_dstInfoProperty_rev;
	Uml::AssociationRole MonolithExecParameter::meta_dstMonolithExecParameter_end_;
	Uml::AssociationRole MonolithExecParameter::meta_srcMonolithExecParameter_end_;
	Uml::AssociationRole MonolithicImplementation::meta_dstMonolithprimaryArtifact, MonolithicImplementation::meta_dstMonolithprimaryArtifact_rev;
	Uml::AssociationRole MonolithicImplementation::meta_dstMonolithDeployRequirement, MonolithicImplementation::meta_dstMonolithDeployRequirement_rev;
	Uml::AssociationRole MonolithicImplementation::meta_dstMonolithExecParameter, MonolithicImplementation::meta_dstMonolithExecParameter_rev;
	Uml::AssociationRole ImplementationRequirement::meta_srcMonolithDeployRequirement, ImplementationRequirement::meta_srcMonolithDeployRequirement_rev;
	Uml::AssociationRole Requirement::meta_srcArtifactDeployRequirement, Requirement::meta_srcArtifactDeployRequirement_rev;
	Uml::AssociationRole Requirement::meta_srcPackageSelectRequirement, Requirement::meta_srcPackageSelectRequirement_rev;
	Uml::AssociationRole Requirement::meta_srcConnectionRequirements, Requirement::meta_srcConnectionRequirements_rev;
	Uml::AssociationRole Requirement::meta_srcSubComponentSelectRequirement, Requirement::meta_srcSubComponentSelectRequirement_rev;
	Uml::AssociationRole ImplementationDependency::meta_srcImplementationDependsOn, ImplementationDependency::meta_srcImplementationDependsOn_rev;
	Uml::AssociationRole Property::meta_srcArtifactExecParameter, Property::meta_srcArtifactExecParameter_rev;
	Uml::AssociationRole Property::meta_srcArtifactInfoProperty, Property::meta_srcArtifactInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcComponentConfigProperty, Property::meta_srcComponentConfigProperty_rev;
	Uml::AssociationRole Property::meta_srcComponentInfoProperty, Property::meta_srcComponentInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcConfigProperty, Property::meta_srcConfigProperty_rev;
	Uml::AssociationRole Property::meta_srcInfoProperty, Property::meta_srcInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcMonolithExecParameter, Property::meta_srcMonolithExecParameter_rev;
	Uml::AssociationRole Property::meta_srcPackageConfigurationProperty, Property::meta_srcPackageConfigurationProperty_rev;
	Uml::AssociationRole Property::meta_srcPackageConfigProperty, Property::meta_srcPackageConfigProperty_rev;
	Uml::AssociationRole Property::meta_srcPackageInfoProperty, Property::meta_srcPackageInfoProperty_rev;
	Uml::AssociationRole Property::meta_srcSubComponentConfigProperty, Property::meta_srcSubComponentConfigProperty_rev;
	Uml::AssociationRole Capability::meta_srcImplementationCapability, Capability::meta_srcImplementationCapability_rev;
	Uml::AssociationRole PackageBaseConnection::meta_dstPackageBaseConnection_end_;
	Uml::AssociationRole PackageBaseConnection::meta_srcPackageBaseConnection_end_;
	Uml::AssociationRole PackageReferenceConnection::meta_dstPackageReferenceConnection_end_;
	Uml::AssociationRole PackageReferenceConnection::meta_srcPackageReferenceConnection_end_;
	Uml::AssociationRole PackageConfigurationReference::meta_srcTopLevelPackageConn, PackageConfigurationReference::meta_srcTopLevelPackageConn_rev;
	Uml::AssociationRole PackageConfigurationReference::meta_ref;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageSelectRequirement, PackageConfiguration::meta_dstPackageSelectRequirement_rev;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageConfigurationProperty, PackageConfiguration::meta_dstPackageConfigurationProperty_rev;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageBaseConnection, PackageConfiguration::meta_dstPackageBaseConnection_rev;
	Uml::AssociationRole PackageConfiguration::meta_dstPackageReferenceConnection, PackageConfiguration::meta_dstPackageReferenceConnection_rev;
	Uml::AssociationRole PackageConfiguration::meta_referedbyPackageConfigurationReference;
	Uml::AssociationRole PackageConfigurationProperty::meta_dstPackageConfigurationProperty_end_;
	Uml::AssociationRole PackageConfigurationProperty::meta_srcPackageConfigurationProperty_end_;
	Uml::AssociationRole PackageSelectRequirement::meta_dstPackageSelectRequirement_end_;
	Uml::AssociationRole PackageSelectRequirement::meta_srcPackageSelectRequirement_end_;
	Uml::AssociationRole EmitConnector::meta_dstEmitConnector_end_;
	Uml::AssociationRole EmitConnector::meta_srcEmitConnector_end_;
	Uml::AssociationRole Invocation::meta_dstInvocation_end_;
	Uml::AssociationRole Invocation::meta_srcInvocation_end_;
	Uml::AssociationRole SubComponentSelectRequirement::meta_dstSubComponentSelectRequirement_end_;
	Uml::AssociationRole SubComponentSelectRequirement::meta_srcSubComponentSelectRequirement_end_;
	Uml::AssociationRole SubComponentConfigProperty::meta_dstSubComponentConfigProperty_end_;
	Uml::AssociationRole SubComponentConfigProperty::meta_srcSubComponentConfigProperty_end_;
	Uml::AssociationRole PublishConnector::meta_dstConnectionRequirements, PublishConnector::meta_dstConnectionRequirements_rev;
	Uml::AssociationRole PublishConnector::meta_dstInEventPortConsume, PublishConnector::meta_dstInEventPortConsume_rev;
	Uml::AssociationRole PublishConnector::meta_srcOutEventPortPublish, PublishConnector::meta_srcOutEventPortPublish_rev;
	Uml::AssociationRole OutEventPortPublish::meta_dstOutEventPortPublish_end_;
	Uml::AssociationRole OutEventPortPublish::meta_srcOutEventPortPublish_end_;
	Uml::AssociationRole InEventPortConsume::meta_srcInEventPortConsume_end_;
	Uml::AssociationRole InEventPortConsume::meta_dstInEventPortConsume_end_;
	Uml::AssociationRole ConnectionRequirements::meta_dstConnectionRequirements_end_;
	Uml::AssociationRole ConnectionRequirements::meta_srcConnectionRequirements_end_;
	Uml::AssociationRole PackageInterface::meta_dstPackageInterface_end_;
	Uml::AssociationRole PackageInterface::meta_srcPackageInterface_end_;
	Uml::AssociationRole PackageImplementations::meta_dstPackageImplementations_end_;
	Uml::AssociationRole PackageImplementations::meta_srcPackageImplementations_end_;
	Uml::AssociationRole PackageConfigProperty::meta_dstPackageConfigProperty_end_;
	Uml::AssociationRole PackageConfigProperty::meta_srcPackageConfigProperty_end_;
	Uml::AssociationRole PackageInfoProperty::meta_dstPackageInfoProperty_end_;
	Uml::AssociationRole PackageInfoProperty::meta_srcPackageInfoProperty_end_;
	Uml::AssociationRole ComponentPackage::meta_dstPackageInterface, ComponentPackage::meta_dstPackageInterface_rev;
	Uml::AssociationRole ComponentPackage::meta_dstPackageImplementations, ComponentPackage::meta_dstPackageImplementations_rev;
	Uml::AssociationRole ComponentPackage::meta_dstPackageConfigProperty, ComponentPackage::meta_dstPackageConfigProperty_rev;
	Uml::AssociationRole ComponentPackage::meta_dstPackageInfoProperty, ComponentPackage::meta_dstPackageInfoProperty_rev;
	Uml::AssociationRole ComponentPackage::meta_srcPackageBaseConnection, ComponentPackage::meta_srcPackageBaseConnection_rev;
	Uml::AssociationRole ComponentPackage::meta_referedbyComponentPackageReference;
	Uml::AssociationRole ComponentPackageReference::meta_srcPackageReferenceConnection, ComponentPackageReference::meta_srcPackageReferenceConnection_rev;
	Uml::AssociationRole ComponentPackageReference::meta_ref;
	Uml::AssociationRole TopLevelPackage::meta_dstTopLevelPackageConn, TopLevelPackage::meta_dstTopLevelPackageConn_rev;
	Uml::AssociationRole TopLevelPackageConn::meta_dstTopLevelPackageConn_end_;
	Uml::AssociationRole TopLevelPackageConn::meta_srcTopLevelPackageConn_end_;
	Uml::AssociationRole EnumerationDef::meta_referedbyEnumRef;
	Uml::AssociationRole Label::meta_srcLabelConnection, Label::meta_srcLabelConnection_rev;
	Uml::AssociationRole LabelConnection::meta_dstLabelConnection_end_;
	Uml::AssociationRole LabelConnection::meta_srcLabelConnection_end_;
	Uml::AssociationRole NamedTypeRef::meta_ref;
	Uml::AssociationRole EnumRef::meta_ref;
	Uml::AssociationRole NamedType::meta_referedbyNamedTypeRef;
	Uml::AssociationRole Member::meta_dstLabelConnection, Member::meta_dstLabelConnection_rev;
	Uml::AssociationRole Member::meta_dstMakeMemberPrivate, Member::meta_dstMakeMemberPrivate_rev;
	Uml::AssociationRole ExceptionRef::meta_ref;
	Uml::AssociationRole FileRef::meta_ref;
	Uml::AssociationRole ExceptionDef::meta_referedbyExceptionRef;
	Uml::AssociationRole ExceptionDef::meta_referedbySetException;
	Uml::AssociationRole ExceptionDef::meta_referedbyGetException;
	Uml::AssociationRole EventRef::meta_ref;
	Uml::AssociationRole ObjectRef::meta_ref;
	Uml::AssociationRole ProvidedRequestPort::meta_srcInvocation, ProvidedRequestPort::meta_srcInvocation_rev;
	Uml::AssociationRole RequiredRequestPort::meta_dstInvocation, RequiredRequestPort::meta_dstInvocation_rev;
	Uml::AssociationRole OutEventPort::meta_dstEmitConnector, OutEventPort::meta_dstEmitConnector_rev;
	Uml::AssociationRole OutEventPort::meta_dstOutEventPortPublish, OutEventPort::meta_dstOutEventPortPublish_rev;
	Uml::AssociationRole InEventPort::meta_srcEmitConnector, InEventPort::meta_srcEmitConnector_rev;
	Uml::AssociationRole InEventPort::meta_srcInEventPortConsume, InEventPort::meta_srcInEventPortConsume_rev;
	Uml::AssociationRole Port::meta_cadenaPort;
	Uml::AssociationRole ComponentDef::meta_referedbyComponentType;
	Uml::AssociationRole ComponentDef::meta_dstSubComponentSelectRequirement, ComponentDef::meta_dstSubComponentSelectRequirement_rev;
	Uml::AssociationRole ComponentDef::meta_dstSubComponentConfigProperty, ComponentDef::meta_dstSubComponentConfigProperty_rev;
	Uml::AssociationRole ComponentDef::meta_referedbyManages;
	Uml::AssociationRole ObjectDef::meta_referedbyObjectRef;
	Uml::AssociationRole ObjectDef::meta_referedbySupports;
	Uml::AssociationRole Inherits::meta_ref;
	Uml::AssociationRole EventDef::meta_referedbyEventRef;
	Uml::AssociationRole ValueDef::meta_referedbyLookupKey;
	Uml::AssociationRole Inheritable::meta_referedbyInherits;
	Uml::AssociationRole Supports::meta_ref;
	Uml::AssociationRole LookupKey::meta_ref;
	Uml::AssociationRole Manages::meta_ref;
	Uml::AssociationRole SetException::meta_ref;
	Uml::AssociationRole GetException::meta_ref;
	Uml::AssociationRole PrivateFlag::meta_srcMakeMemberPrivate, PrivateFlag::meta_srcMakeMemberPrivate_rev;
	Uml::AssociationRole MakeMemberPrivate::meta_srcMakeMemberPrivate_end_;
	Uml::AssociationRole MakeMemberPrivate::meta_dstMakeMemberPrivate_end_;
	Uml::CompositionParentRole ImplementationArtifactReference::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ImplementationArtifacts::meta_RootFolder_parent;
	Uml::CompositionParentRole ArtifactDependsOn::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ArtifactDeployRequirement::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ArtifactContainer::meta_ImplementationArtifacts_parent;
	Uml::CompositionParentRole ArtifactExecParameter::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ArtifactInfoProperty::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole ImplementationArtifact::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole IDLFile::meta_IDLFiles_parent;
	Uml::CompositionParentRole IDLFiles::meta_RootFolder_parent;
	Uml::CompositionParentRole ComponentType::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentType::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentType::meta_PackageContainer_parent;
	Uml::CompositionParentRole ComponentTypes::meta_RootFolder_parent;
	Uml::CompositionParentRole ComponentConfigProperty::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentInfoProperty::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentPropertyDescription::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentProperty::meta_ComponentContainer_parent;
	Uml::CompositionParentRole ComponentContainer::meta_ComponentTypes_parent;
	Uml::CompositionParentRole ImplementationCapability::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ImplementationDependsOn::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Implements::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentImplementations::meta_RootFolder_parent;
	Uml::CompositionParentRole ComponentImplementationReference::meta_PackageContainer_parent;
	Uml::CompositionParentRole ConfigProperty::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole InfoProperty::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole MonolithDeployRequirement::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentImplementation::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ComponentImplementationContainer::meta_ComponentImplementations_parent;
	Uml::CompositionParentRole MonolithExecParameter::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole ImplementationRequirement::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Requirement::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole Requirement::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole Requirement::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole ImplementationDependency::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Any::meta_SatisfierProperty_parent;
	Uml::CompositionParentRole Any::meta_Property_parent;
	Uml::CompositionParentRole Property::meta_ArtifactContainer_parent;
	Uml::CompositionParentRole Property::meta_ComponentContainer_parent;
	Uml::CompositionParentRole Property::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole Property::meta_RequirementBase_parent;
	Uml::CompositionParentRole Property::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole Property::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole Property::meta_PackageContainer_parent;
	Uml::CompositionParentRole SatisfierProperty::meta_RequirementSatisfier_parent;
	Uml::CompositionParentRole DataType::meta_Any_parent;
	Uml::CompositionParentRole DataType::meta_ComponentPropertyDescription_parent;
	Uml::CompositionParentRole Capability::meta_ComponentImplementationContainer_parent;
	Uml::CompositionParentRole PackageBaseConnection::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageReferenceConnection::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageConfigurationReference::meta_TopLevelPackageContainer_parent;
	Uml::CompositionParentRole PackageConfiguration::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageConfiguration::meta_specializedConfig_PackageConfiguration_parent;
	Uml::CompositionParentRole PackageConfigurations::meta_RootFolder_parent;
	Uml::CompositionParentRole PackageConfigurationContainer::meta_PackageConfigurations_parent;
	Uml::CompositionParentRole PackageConfigurationProperty::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole PackageSelectRequirement::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole EmitConnector::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole Invocation::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole SubComponentSelectRequirement::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole SubComponentConfigProperty::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole PublishConnector::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole OutEventPortPublish::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole InEventPortConsume::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole ConnectionRequirements::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole ComponentPackages::meta_RootFolder_parent;
	Uml::CompositionParentRole PackageInterface::meta_PackageContainer_parent;
	Uml::CompositionParentRole PackageImplementations::meta_PackageContainer_parent;
	Uml::CompositionParentRole PackageContainer::meta_ComponentPackages_parent;
	Uml::CompositionParentRole PackageConfigProperty::meta_PackageContainer_parent;
	Uml::CompositionParentRole PackageInfoProperty::meta_PackageContainer_parent;
	Uml::CompositionParentRole ComponentPackage::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole ComponentPackage::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole ComponentPackage::meta_PackageContainer_parent;
	Uml::CompositionParentRole ComponentPackageReference::meta_PackageConfigurationContainer_parent;
	Uml::CompositionParentRole ComponentPackageReference::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole TopLevelPackageContainer::meta_TopLevelPackageFolder_parent;
	Uml::CompositionParentRole TopLevelPackageFolder::meta_RootFolder_parent;
	Uml::CompositionParentRole TopLevelPackage::meta_TopLevelPackageContainer_parent;
	Uml::CompositionParentRole TopLevelPackageConn::meta_TopLevelPackageContainer_parent;
	Uml::CompositionParentRole EnumValue::meta_EnumerationDef_parent;
	Uml::CompositionParentRole Label::meta_SwitchedAggregateDef_parent;
	Uml::CompositionParentRole Discriminator::meta_SwitchedAggregateDef_parent;
	Uml::CompositionParentRole LabelConnection::meta_SwitchedAggregateDef_parent;
	Uml::CompositionParentRole EnumRef::meta_Discriminator_parent;
	Uml::CompositionParentRole EnumRef::meta_ConstantDef_parent;
	Uml::CompositionParentRole NamedType::meta_IDLFile_parent;
	Uml::CompositionParentRole NamedType::meta_Package_parent;
	Uml::CompositionParentRole Member::meta_AliasDef_parent;
	Uml::CompositionParentRole Member::meta_AggregateDef_parent;
	Uml::CompositionParentRole Member::meta_SwitchedAggregateDef_parent;
	Uml::CompositionParentRole Member::meta_BoxedDef_parent;
	Uml::CompositionParentRole Member::meta_ExceptionDef_parent;
	Uml::CompositionParentRole Member::meta_CollectionType_parent;
	Uml::CompositionParentRole Member::meta_ReadonlyAttribute_parent;
	Uml::CompositionParentRole Member::meta_ObjectByValue_parent;
	Uml::CompositionParentRole NoInheritable::meta_HasOperations_parent;
	Uml::CompositionParentRole PrefixTag::meta_Prefixable_parent;
	Uml::CompositionParentRole GeneralTag::meta_Taggable_parent;
	Uml::CompositionParentRole ReturnType::meta_TwowayOperation_parent;
	Uml::CompositionParentRole InParameter::meta_OperationBase_parent;
	Uml::CompositionParentRole InoutParameter::meta_TwowayOperation_parent;
	Uml::CompositionParentRole OutParameter::meta_TwowayOperation_parent;
	Uml::CompositionParentRole ParameterType::meta_Parameter_parent;
	Uml::CompositionParentRole OnewayOperation::meta_HasOperations_parent;
	Uml::CompositionParentRole LookupOperation::meta_ComponentFactory_parent;
	Uml::CompositionParentRole FactoryOperation::meta_ObjectByValue_parent;
	Uml::CompositionParentRole FactoryOperation::meta_ComponentFactory_parent;
	Uml::CompositionParentRole TwowayOperation::meta_HasOperations_parent;
	Uml::CompositionParentRole Package::meta_IDLFile_parent;
	Uml::CompositionParentRole Package::meta_Package_parent;
	Uml::CompositionParentRole ExceptionRef::meta_HasExceptions_parent;
	Uml::CompositionParentRole FileRef::meta_IDLFile_parent;
	Uml::CompositionParentRole ConstantDef::meta_IDLFile_parent;
	Uml::CompositionParentRole ConstantDef::meta_Package_parent;
	Uml::CompositionParentRole ConstantDef::meta_HasOperations_parent;
	Uml::CompositionParentRole ExceptionDef::meta_IDLFile_parent;
	Uml::CompositionParentRole ExceptionDef::meta_Package_parent;
	Uml::CompositionParentRole ExceptionDef::meta_HasOperations_parent;
	Uml::CompositionParentRole EventRef::meta_EventPort_parent;
	Uml::CompositionParentRole ObjectRef::meta_RequestPort_parent;
	Uml::CompositionParentRole Port::meta_ComponentDef_parent;
	Uml::CompositionParentRole ComponentDef::meta_ComponentAssembly_parent;
	Uml::CompositionParentRole BoundedString::meta_ConstantDef_parent;
	Uml::CompositionParentRole PredefinedType::meta_Discriminator_parent;
	Uml::CompositionParentRole PredefinedType::meta_ConstantDef_parent;
	Uml::CompositionParentRole PredefinedType::meta_DataType_parent;
	Uml::CompositionParentRole FixedPoint::meta_ConstantDef_parent;
	Uml::CompositionParentRole Inherits::meta_Inheritable_parent;
	Uml::CompositionParentRole Supports::meta_SupportsInterfaces_parent;
	Uml::CompositionParentRole ReadonlyAttribute::meta_Inheritable_parent;
	Uml::CompositionParentRole LookupKey::meta_ComponentFactory_parent;
	Uml::CompositionParentRole Manages::meta_ComponentFactory_parent;
	Uml::CompositionParentRole SetException::meta_Attribute_parent;
	Uml::CompositionParentRole GetException::meta_ReadonlyAttribute_parent;
	Uml::CompositionParentRole PrivateFlag::meta_ObjectByValue_parent;
	Uml::CompositionParentRole MakeMemberPrivate::meta_ObjectByValue_parent;
	Uml::CompositionParentRole RootFolder::meta_RootFolder_parent;
	Uml::CompositionChildRole ImplementationArtifacts::meta_ArtifactContainer_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ImplementationArtifactReference_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactDependsOn_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactDeployRequirement_children;
	Uml::CompositionChildRole ArtifactContainer::meta_Requirement_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactExecParameter_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ArtifactInfoProperty_children;
	Uml::CompositionChildRole ArtifactContainer::meta_Property_children;
	Uml::CompositionChildRole ArtifactContainer::meta_ImplementationArtifact_children;
	Uml::CompositionChildRole IDLFile::meta_Package_children;
	Uml::CompositionChildRole IDLFile::meta_ConstantDef_children;
	Uml::CompositionChildRole IDLFile::meta_ExceptionDef_children;
	Uml::CompositionChildRole IDLFile::meta_NamedType_children;
	Uml::CompositionChildRole IDLFile::meta_FileRef_children;
	Uml::CompositionChildRole IDLFiles::meta_IDLFile_children;
	Uml::CompositionChildRole ComponentTypes::meta_ComponentContainer_children;
	Uml::CompositionChildRole ComponentPropertyDescription::meta_DataType_child;
	Uml::CompositionChildRole ComponentContainer::meta_Property_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentType_child;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentConfigProperty_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentInfoProperty_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentProperty_children;
	Uml::CompositionChildRole ComponentContainer::meta_ComponentPropertyDescription_children;
	Uml::CompositionChildRole ComponentImplementations::meta_ComponentImplementationContainer_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ComponentImplementation_child;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationRequirement_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationDependsOn_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_Implements_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ComponentType_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_MonolithDeployRequirement_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_MonolithprimaryArtifact_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_MonolithExecParameter_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationDependency_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ConfigProperty_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationCapability_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_InfoProperty_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_Property_children;
	Uml::CompositionChildRole ComponentImplementationContainer::meta_Capability_children;
	Uml::CompositionChildRole RequirementBase::meta_Property_children;
	Uml::CompositionChildRole Any::meta_DataType_child;
	Uml::CompositionChildRole Property::meta_Any_child;
	Uml::CompositionChildRole SatisfierProperty::meta_Any_child;
	Uml::CompositionChildRole DataType::meta_PredefinedType_child;
	Uml::CompositionChildRole RequirementSatisfier::meta_SatisfierProperty_children;
	Uml::CompositionChildRole PackageConfiguration::meta_specializedConfig;
	Uml::CompositionChildRole PackageConfigurations::meta_PackageConfigurationContainer_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageReferenceConnection_child;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageBaseConnection_child;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_ComponentPackage_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_ComponentPackageReference_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfiguration_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfigurationProperty_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageSelectRequirement_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_Requirement_children;
	Uml::CompositionChildRole PackageConfigurationContainer::meta_Property_children;
	Uml::CompositionChildRole ComponentAssembly::meta_ComponentDef_children;
	Uml::CompositionChildRole ComponentAssembly::meta_EmitConnector_children;
	Uml::CompositionChildRole ComponentAssembly::meta_ComponentPackage_children;
	Uml::CompositionChildRole ComponentAssembly::meta_Invocation_children;
	Uml::CompositionChildRole ComponentAssembly::meta_SubComponentSelectRequirement_children;
	Uml::CompositionChildRole ComponentAssembly::meta_SubComponentConfigProperty_children;
	Uml::CompositionChildRole ComponentAssembly::meta_Property_children;
	Uml::CompositionChildRole ComponentAssembly::meta_ComponentPackageReference_children;
	Uml::CompositionChildRole ComponentAssembly::meta_InEventPortConsume_children;
	Uml::CompositionChildRole ComponentAssembly::meta_OutEventPortPublish_children;
	Uml::CompositionChildRole ComponentAssembly::meta_PublishConnector_children;
	Uml::CompositionChildRole ComponentAssembly::meta_ConnectionRequirements_children;
	Uml::CompositionChildRole ComponentAssembly::meta_Requirement_children;
	Uml::CompositionChildRole ComponentPackages::meta_PackageContainer_children;
	Uml::CompositionChildRole PackageContainer::meta_PackageImplementations_children;
	Uml::CompositionChildRole PackageContainer::meta_PackageInterface_child;
	Uml::CompositionChildRole PackageContainer::meta_ComponentImplementationReference_children;
	Uml::CompositionChildRole PackageContainer::meta_ComponentType_children;
	Uml::CompositionChildRole PackageContainer::meta_PackageConfigProperty_children;
	Uml::CompositionChildRole PackageContainer::meta_Property_children;
	Uml::CompositionChildRole PackageContainer::meta_PackageInfoProperty_children;
	Uml::CompositionChildRole PackageContainer::meta_ComponentPackage_child;
	Uml::CompositionChildRole TopLevelPackageContainer::meta_TopLevelPackage_children;
	Uml::CompositionChildRole TopLevelPackageContainer::meta_PackageConfigurationReference_children;
	Uml::CompositionChildRole TopLevelPackageContainer::meta_TopLevelPackageConn_children;
	Uml::CompositionChildRole TopLevelPackageFolder::meta_TopLevelPackageContainer_children;
	Uml::CompositionChildRole EnumerationDef::meta_EnumValue_children;
	Uml::CompositionChildRole AliasDef::meta_Member_child;
	Uml::CompositionChildRole AggregateDef::meta_Member_children;
	Uml::CompositionChildRole SwitchedAggregateDef::meta_LabelConnection_children;
	Uml::CompositionChildRole SwitchedAggregateDef::meta_Discriminator_child;
	Uml::CompositionChildRole SwitchedAggregateDef::meta_Label_children;
	Uml::CompositionChildRole SwitchedAggregateDef::meta_Member_children;
	Uml::CompositionChildRole Discriminator::meta_EnumRef_child;
	Uml::CompositionChildRole Discriminator::meta_PredefinedType_child;
	Uml::CompositionChildRole BoxedDef::meta_Member_child;
	Uml::CompositionChildRole Prefixable::meta_PrefixTag_child;
	Uml::CompositionChildRole Taggable::meta_GeneralTag_child;
	Uml::CompositionChildRole OperationBase::meta_InParameter_children;
	Uml::CompositionChildRole Parameter::meta_ParameterType_child;
	Uml::CompositionChildRole HasExceptions::meta_ExceptionRef_children;
	Uml::CompositionChildRole TwowayOperation::meta_OutParameter_children;
	Uml::CompositionChildRole TwowayOperation::meta_InoutParameter_children;
	Uml::CompositionChildRole TwowayOperation::meta_ReturnType_children;
	Uml::CompositionChildRole Package::meta_ConstantDef_children;
	Uml::CompositionChildRole Package::meta_Package_children;
	Uml::CompositionChildRole Package::meta_ExceptionDef_children;
	Uml::CompositionChildRole Package::meta_NamedType_children;
	Uml::CompositionChildRole ConstantDef::meta_BoundedString_child;
	Uml::CompositionChildRole ConstantDef::meta_PredefinedType_child;
	Uml::CompositionChildRole ConstantDef::meta_EnumRef_child;
	Uml::CompositionChildRole ConstantDef::meta_FixedPoint_child;
	Uml::CompositionChildRole ExceptionDef::meta_Member_children;
	Uml::CompositionChildRole RequestPort::meta_ObjectRef_child;
	Uml::CompositionChildRole EventPort::meta_EventRef_child;
	Uml::CompositionChildRole ComponentDef::meta_Port_children;
	Uml::CompositionChildRole CollectionType::meta_Member_child;
	Uml::CompositionChildRole ComponentFactory::meta_Manages_child;
	Uml::CompositionChildRole ComponentFactory::meta_LookupKey_child;
	Uml::CompositionChildRole ComponentFactory::meta_LookupOperation_children;
	Uml::CompositionChildRole ComponentFactory::meta_FactoryOperation_children;
	Uml::CompositionChildRole Inheritable::meta_ReadonlyAttribute_children;
	Uml::CompositionChildRole Inheritable::meta_Inherits_children;
	Uml::CompositionChildRole HasOperations::meta_TwowayOperation_children;
	Uml::CompositionChildRole HasOperations::meta_OnewayOperation_children;
	Uml::CompositionChildRole HasOperations::meta_NoInheritable_children;
	Uml::CompositionChildRole HasOperations::meta_ConstantDef_children;
	Uml::CompositionChildRole HasOperations::meta_ExceptionDef_children;
	Uml::CompositionChildRole SupportsInterfaces::meta_Supports_children;
	Uml::CompositionChildRole ReadonlyAttribute::meta_GetException_children;
	Uml::CompositionChildRole ReadonlyAttribute::meta_Member_child;
	Uml::CompositionChildRole Attribute::meta_SetException_children;
	Uml::CompositionChildRole ObjectByValue::meta_Member_children;
	Uml::CompositionChildRole ObjectByValue::meta_FactoryOperation_children;
	Uml::CompositionChildRole ObjectByValue::meta_PrivateFlag_children;
	Uml::CompositionChildRole ObjectByValue::meta_MakeMemberPrivate_children;
	Uml::CompositionChildRole RootFolder::meta_IDLFiles_children;
	Uml::CompositionChildRole RootFolder::meta_ImplementationArtifacts_children;
	Uml::CompositionChildRole RootFolder::meta_ComponentTypes_children;
	Uml::CompositionChildRole RootFolder::meta_ComponentImplementations_children;
	Uml::CompositionChildRole RootFolder::meta_PackageConfigurations_children;
	Uml::CompositionChildRole RootFolder::meta_ComponentPackages_children;
	Uml::CompositionChildRole RootFolder::meta_TopLevelPackageFolder_children;
	Uml::CompositionChildRole RootFolder::meta_RootFolder_children;
	void Creates()
	{
		ImplementationArtifactReference::meta = Uml::Class::Create(umldiagram);
		ImplementationArtifacts::meta = Uml::Class::Create(umldiagram);
		ArtifactDependsOn::meta = Uml::Class::Create(umldiagram);
		ArtifactDeployRequirement::meta = Uml::Class::Create(umldiagram);
		ArtifactContainer::meta = Uml::Class::Create(umldiagram);
		ArtifactExecParameter::meta = Uml::Class::Create(umldiagram);
		ArtifactInfoProperty::meta = Uml::Class::Create(umldiagram);
		ImplementationArtifact::meta = Uml::Class::Create(umldiagram);
		IDLFile::meta = Uml::Class::Create(umldiagram);
		IDLFiles::meta = Uml::Class::Create(umldiagram);
		ComponentType::meta = Uml::Class::Create(umldiagram);
		ComponentTypes::meta = Uml::Class::Create(umldiagram);
		ComponentConfigProperty::meta = Uml::Class::Create(umldiagram);
		ComponentInfoProperty::meta = Uml::Class::Create(umldiagram);
		CommonPortAttrs::meta = Uml::Class::Create(umldiagram);
		ComponentPropertyDescription::meta = Uml::Class::Create(umldiagram);
		ComponentProperty::meta = Uml::Class::Create(umldiagram);
		ComponentContainer::meta = Uml::Class::Create(umldiagram);
		ImplementationCapability::meta = Uml::Class::Create(umldiagram);
		ImplementationDependsOn::meta = Uml::Class::Create(umldiagram);
		Implements::meta = Uml::Class::Create(umldiagram);
		ComponentImplementations::meta = Uml::Class::Create(umldiagram);
		ComponentImplementationReference::meta = Uml::Class::Create(umldiagram);
		ConfigProperty::meta = Uml::Class::Create(umldiagram);
		InfoProperty::meta = Uml::Class::Create(umldiagram);
		MonolithprimaryArtifact::meta = Uml::Class::Create(umldiagram);
		MonolithDeployRequirement::meta = Uml::Class::Create(umldiagram);
		ComponentImplementation::meta = Uml::Class::Create(umldiagram);
		ComponentImplementationContainer::meta = Uml::Class::Create(umldiagram);
		MonolithExecParameter::meta = Uml::Class::Create(umldiagram);
		MonolithicImplementation::meta = Uml::Class::Create(umldiagram);
		RequirementBase::meta = Uml::Class::Create(umldiagram);
		ImplementationRequirement::meta = Uml::Class::Create(umldiagram);
		Requirement::meta = Uml::Class::Create(umldiagram);
		ImplementationDependency::meta = Uml::Class::Create(umldiagram);
		Any::meta = Uml::Class::Create(umldiagram);
		Property::meta = Uml::Class::Create(umldiagram);
		SatisfierProperty::meta = Uml::Class::Create(umldiagram);
		DataType::meta = Uml::Class::Create(umldiagram);
		RequirementSatisfier::meta = Uml::Class::Create(umldiagram);
		Capability::meta = Uml::Class::Create(umldiagram);
		PackageBaseConnection::meta = Uml::Class::Create(umldiagram);
		PackageReferenceConnection::meta = Uml::Class::Create(umldiagram);
		PackageConfigurationReference::meta = Uml::Class::Create(umldiagram);
		PackageConfiguration::meta = Uml::Class::Create(umldiagram);
		PackageConfigurations::meta = Uml::Class::Create(umldiagram);
		PackageConfigurationContainer::meta = Uml::Class::Create(umldiagram);
		PackageConfigurationProperty::meta = Uml::Class::Create(umldiagram);
		PackageSelectRequirement::meta = Uml::Class::Create(umldiagram);
		EmitConnector::meta = Uml::Class::Create(umldiagram);
		ComponentAssembly::meta = Uml::Class::Create(umldiagram);
		Invocation::meta = Uml::Class::Create(umldiagram);
		SubComponentSelectRequirement::meta = Uml::Class::Create(umldiagram);
		SubComponentConfigProperty::meta = Uml::Class::Create(umldiagram);
		PublishConnector::meta = Uml::Class::Create(umldiagram);
		OutEventPortPublish::meta = Uml::Class::Create(umldiagram);
		InEventPortConsume::meta = Uml::Class::Create(umldiagram);
		ConnectionRequirements::meta = Uml::Class::Create(umldiagram);
		ComponentPackages::meta = Uml::Class::Create(umldiagram);
		PackageInterface::meta = Uml::Class::Create(umldiagram);
		PackageImplementations::meta = Uml::Class::Create(umldiagram);
		PackageContainer::meta = Uml::Class::Create(umldiagram);
		PackageConfigProperty::meta = Uml::Class::Create(umldiagram);
		PackageInfoProperty::meta = Uml::Class::Create(umldiagram);
		ComponentPackage::meta = Uml::Class::Create(umldiagram);
		ComponentPackageReference::meta = Uml::Class::Create(umldiagram);
		TopLevelPackageContainer::meta = Uml::Class::Create(umldiagram);
		TopLevelPackageFolder::meta = Uml::Class::Create(umldiagram);
		TopLevelPackage::meta = Uml::Class::Create(umldiagram);
		TopLevelPackageConn::meta = Uml::Class::Create(umldiagram);
		EnumerationDef::meta = Uml::Class::Create(umldiagram);
		EnumValue::meta = Uml::Class::Create(umldiagram);
		AliasDef::meta = Uml::Class::Create(umldiagram);
		AggregateDef::meta = Uml::Class::Create(umldiagram);
		SwitchedAggregateDef::meta = Uml::Class::Create(umldiagram);
		Label::meta = Uml::Class::Create(umldiagram);
		Discriminator::meta = Uml::Class::Create(umldiagram);
		LabelConnection::meta = Uml::Class::Create(umldiagram);
		BoxedDef::meta = Uml::Class::Create(umldiagram);
		NamedTypeRef::meta = Uml::Class::Create(umldiagram);
		EnumRef::meta = Uml::Class::Create(umldiagram);
		NamedType::meta = Uml::Class::Create(umldiagram);
		Member::meta = Uml::Class::Create(umldiagram);
		NoInheritable::meta = Uml::Class::Create(umldiagram);
		IdTag::meta = Uml::Class::Create(umldiagram);
		PrefixTag::meta = Uml::Class::Create(umldiagram);
		GeneralTag::meta = Uml::Class::Create(umldiagram);
		SpecifyIdTag::meta = Uml::Class::Create(umldiagram);
		VersionTag::meta = Uml::Class::Create(umldiagram);
		Prefixable::meta = Uml::Class::Create(umldiagram);
		Taggable::meta = Uml::Class::Create(umldiagram);
		ReturnType::meta = Uml::Class::Create(umldiagram);
		InParameter::meta = Uml::Class::Create(umldiagram);
		InoutParameter::meta = Uml::Class::Create(umldiagram);
		OutParameter::meta = Uml::Class::Create(umldiagram);
		ParameterType::meta = Uml::Class::Create(umldiagram);
		OperationBase::meta = Uml::Class::Create(umldiagram);
		Parameter::meta = Uml::Class::Create(umldiagram);
		HasExceptions::meta = Uml::Class::Create(umldiagram);
		OnewayOperation::meta = Uml::Class::Create(umldiagram);
		LookupOperation::meta = Uml::Class::Create(umldiagram);
		FactoryOperation::meta = Uml::Class::Create(umldiagram);
		TwowayOperation::meta = Uml::Class::Create(umldiagram);
		Package::meta = Uml::Class::Create(umldiagram);
		Type::meta = Uml::Class::Create(umldiagram);
		ExceptionRef::meta = Uml::Class::Create(umldiagram);
		FileRef::meta = Uml::Class::Create(umldiagram);
		ConstantDef::meta = Uml::Class::Create(umldiagram);
		ExceptionDef::meta = Uml::Class::Create(umldiagram);
		RequestPort::meta = Uml::Class::Create(umldiagram);
		EventPort::meta = Uml::Class::Create(umldiagram);
		EventRef::meta = Uml::Class::Create(umldiagram);
		ObjectRef::meta = Uml::Class::Create(umldiagram);
		ProvidedRequestPort::meta = Uml::Class::Create(umldiagram);
		RequiredRequestPort::meta = Uml::Class::Create(umldiagram);
		OutEventPort::meta = Uml::Class::Create(umldiagram);
		InEventPort::meta = Uml::Class::Create(umldiagram);
		Port::meta = Uml::Class::Create(umldiagram);
		ComponentDef::meta = Uml::Class::Create(umldiagram);
		BoundedString::meta = Uml::Class::Create(umldiagram);
		FixedSizeCollection::meta = Uml::Class::Create(umldiagram);
		VariableSizeCollection::meta = Uml::Class::Create(umldiagram);
		AnonymousType::meta = Uml::Class::Create(umldiagram);
		CollectionType::meta = Uml::Class::Create(umldiagram);
		PredefinedType::meta = Uml::Class::Create(umldiagram);
		FixedPoint::meta = Uml::Class::Create(umldiagram);
		ObjectDef::meta = Uml::Class::Create(umldiagram);
		ComponentFactory::meta = Uml::Class::Create(umldiagram);
		Inherits::meta = Uml::Class::Create(umldiagram);
		EventDef::meta = Uml::Class::Create(umldiagram);
		ValueDef::meta = Uml::Class::Create(umldiagram);
		Inheritable::meta = Uml::Class::Create(umldiagram);
		HasOperations::meta = Uml::Class::Create(umldiagram);
		SupportsInterfaces::meta = Uml::Class::Create(umldiagram);
		Supports::meta = Uml::Class::Create(umldiagram);
		ReadonlyAttribute::meta = Uml::Class::Create(umldiagram);
		Attribute::meta = Uml::Class::Create(umldiagram);
		LookupKey::meta = Uml::Class::Create(umldiagram);
		Manages::meta = Uml::Class::Create(umldiagram);
		SetException::meta = Uml::Class::Create(umldiagram);
		ObjectByValue::meta = Uml::Class::Create(umldiagram);
		GetException::meta = Uml::Class::Create(umldiagram);
		PrivateFlag::meta = Uml::Class::Create(umldiagram);
		MakeMemberPrivate::meta = Uml::Class::Create(umldiagram);
		RootFolder::meta = Uml::Class::Create(umldiagram);
		MgaObject::meta = Uml::Class::Create(umldiagram);
		ImplementationArtifacts::meta_name = Uml::Attribute::Create(ImplementationArtifacts::meta);
		IDLFiles::meta_name = Uml::Attribute::Create(IDLFiles::meta);
		ComponentTypes::meta_name = Uml::Attribute::Create(ComponentTypes::meta);
		ComponentImplementations::meta_name = Uml::Attribute::Create(ComponentImplementations::meta);
		PackageConfigurations::meta_name = Uml::Attribute::Create(PackageConfigurations::meta);
		ComponentPackages::meta_name = Uml::Attribute::Create(ComponentPackages::meta);
		TopLevelPackageFolder::meta_name = Uml::Attribute::Create(TopLevelPackageFolder::meta);
		ConstantDef::meta_value = Uml::Attribute::Create(ConstantDef::meta);
		RequiredRequestPort::meta_multiple_connections = Uml::Attribute::Create(RequiredRequestPort::meta);
		OutEventPort::meta_single_destination = Uml::Attribute::Create(OutEventPort::meta);
		BoundedString::meta_wide = Uml::Attribute::Create(BoundedString::meta);
		BoundedString::meta_bound = Uml::Attribute::Create(BoundedString::meta);
		CollectionType::meta_bound = Uml::Attribute::Create(CollectionType::meta);
		PredefinedType::meta_which_type = Uml::Attribute::Create(PredefinedType::meta);
		FixedPoint::meta_total_digits = Uml::Attribute::Create(FixedPoint::meta);
		FixedPoint::meta_decimal_digits = Uml::Attribute::Create(FixedPoint::meta);
		ObjectDef::meta_local = Uml::Attribute::Create(ObjectDef::meta);
		ObjectDef::meta_abstract = Uml::Attribute::Create(ObjectDef::meta);
		ObjectByValue::meta_custom = Uml::Attribute::Create(ObjectByValue::meta);
		ObjectByValue::meta_abstract = Uml::Attribute::Create(ObjectByValue::meta);
		ObjectByValue::meta_truncatable = Uml::Attribute::Create(ObjectByValue::meta);
		RootFolder::meta_name = Uml::Attribute::Create(RootFolder::meta);
		MgaObject::meta_position = Uml::Attribute::Create(MgaObject::meta);
		MgaObject::meta_name = Uml::Attribute::Create(MgaObject::meta);
	}
	void InitClassesAttributes()
	{
		ImplementationArtifactReference::meta.name() = "ImplementationArtifactReference";
		ImplementationArtifactReference::meta.isAbstract() = false;
		ImplementationArtifactReference::meta.stereotype() = "Reference";
		ImplementationArtifacts::meta.name() = "ImplementationArtifacts";
		ImplementationArtifacts::meta.isAbstract() = false;
		ImplementationArtifacts::meta.stereotype() = "Folder";
		ArtifactDependsOn::meta.name() = "ArtifactDependsOn";
		ArtifactDependsOn::meta.isAbstract() = false;
		ArtifactDependsOn::meta.stereotype() = "Connection";
		ArtifactDeployRequirement::meta.name() = "ArtifactDeployRequirement";
		ArtifactDeployRequirement::meta.isAbstract() = false;
		ArtifactDeployRequirement::meta.stereotype() = "Connection";
		ArtifactContainer::meta.name() = "ArtifactContainer";
		ArtifactContainer::meta.isAbstract() = false;
		ArtifactContainer::meta.stereotype() = "Model";
		ArtifactExecParameter::meta.name() = "ArtifactExecParameter";
		ArtifactExecParameter::meta.isAbstract() = false;
		ArtifactExecParameter::meta.stereotype() = "Connection";
		ArtifactInfoProperty::meta.name() = "ArtifactInfoProperty";
		ArtifactInfoProperty::meta.isAbstract() = false;
		ArtifactInfoProperty::meta.stereotype() = "Connection";
		ImplementationArtifact::meta.name() = "ImplementationArtifact";
		ImplementationArtifact::meta.isAbstract() = false;
		ImplementationArtifact::meta.stereotype() = "Atom";
		IDLFile::meta.name() = "IDLFile";
		IDLFile::meta.isAbstract() = false;
		IDLFile::meta.stereotype() = "Model";
		IDLFiles::meta.name() = "IDLFiles";
		IDLFiles::meta.isAbstract() = false;
		IDLFiles::meta.stereotype() = "Folder";
		ComponentType::meta.name() = "ComponentType";
		ComponentType::meta.isAbstract() = false;
		ComponentType::meta.stereotype() = "Reference";
		ComponentTypes::meta.name() = "ComponentTypes";
		ComponentTypes::meta.isAbstract() = false;
		ComponentTypes::meta.stereotype() = "Folder";
		ComponentConfigProperty::meta.name() = "ComponentConfigProperty";
		ComponentConfigProperty::meta.isAbstract() = false;
		ComponentConfigProperty::meta.stereotype() = "Connection";
		ComponentInfoProperty::meta.name() = "ComponentInfoProperty";
		ComponentInfoProperty::meta.isAbstract() = false;
		ComponentInfoProperty::meta.stereotype() = "Connection";
		CommonPortAttrs::meta.name() = "CommonPortAttrs";
		CommonPortAttrs::meta.isAbstract() = true;
		CommonPortAttrs::meta.stereotype() = "FCO";
		ComponentPropertyDescription::meta.name() = "ComponentPropertyDescription";
		ComponentPropertyDescription::meta.isAbstract() = false;
		ComponentPropertyDescription::meta.stereotype() = "Model";
		ComponentProperty::meta.name() = "ComponentProperty";
		ComponentProperty::meta.isAbstract() = false;
		ComponentProperty::meta.stereotype() = "Connection";
		ComponentContainer::meta.name() = "ComponentContainer";
		ComponentContainer::meta.isAbstract() = false;
		ComponentContainer::meta.stereotype() = "Model";
		ImplementationCapability::meta.name() = "ImplementationCapability";
		ImplementationCapability::meta.isAbstract() = false;
		ImplementationCapability::meta.stereotype() = "Connection";
		ImplementationDependsOn::meta.name() = "ImplementationDependsOn";
		ImplementationDependsOn::meta.isAbstract() = false;
		ImplementationDependsOn::meta.stereotype() = "Connection";
		Implements::meta.name() = "Implements";
		Implements::meta.isAbstract() = false;
		Implements::meta.stereotype() = "Connection";
		ComponentImplementations::meta.name() = "ComponentImplementations";
		ComponentImplementations::meta.isAbstract() = false;
		ComponentImplementations::meta.stereotype() = "Folder";
		ComponentImplementationReference::meta.name() = "ComponentImplementationReference";
		ComponentImplementationReference::meta.isAbstract() = false;
		ComponentImplementationReference::meta.stereotype() = "Reference";
		ConfigProperty::meta.name() = "ConfigProperty";
		ConfigProperty::meta.isAbstract() = false;
		ConfigProperty::meta.stereotype() = "Connection";
		InfoProperty::meta.name() = "InfoProperty";
		InfoProperty::meta.isAbstract() = false;
		InfoProperty::meta.stereotype() = "Connection";
		MonolithprimaryArtifact::meta.name() = "MonolithprimaryArtifact";
		MonolithprimaryArtifact::meta.isAbstract() = false;
		MonolithprimaryArtifact::meta.stereotype() = "Connection";
		MonolithDeployRequirement::meta.name() = "MonolithDeployRequirement";
		MonolithDeployRequirement::meta.isAbstract() = false;
		MonolithDeployRequirement::meta.stereotype() = "Connection";
		ComponentImplementation::meta.name() = "ComponentImplementation";
		ComponentImplementation::meta.isAbstract() = true;
		ComponentImplementation::meta.stereotype() = "FCO";
		ComponentImplementationContainer::meta.name() = "ComponentImplementationContainer";
		ComponentImplementationContainer::meta.isAbstract() = false;
		ComponentImplementationContainer::meta.stereotype() = "Model";
		MonolithExecParameter::meta.name() = "MonolithExecParameter";
		MonolithExecParameter::meta.isAbstract() = false;
		MonolithExecParameter::meta.stereotype() = "Connection";
		MonolithicImplementation::meta.name() = "MonolithicImplementation";
		MonolithicImplementation::meta.isAbstract() = false;
		MonolithicImplementation::meta.stereotype() = "Atom";
		RequirementBase::meta.name() = "RequirementBase";
		RequirementBase::meta.isAbstract() = true;
		RequirementBase::meta.stereotype() = "Model";
		ImplementationRequirement::meta.name() = "ImplementationRequirement";
		ImplementationRequirement::meta.isAbstract() = false;
		ImplementationRequirement::meta.stereotype() = "Model";
		Requirement::meta.name() = "Requirement";
		Requirement::meta.isAbstract() = false;
		Requirement::meta.stereotype() = "Model";
		ImplementationDependency::meta.name() = "ImplementationDependency";
		ImplementationDependency::meta.isAbstract() = false;
		ImplementationDependency::meta.stereotype() = "Atom";
		Any::meta.name() = "Any";
		Any::meta.isAbstract() = false;
		Any::meta.stereotype() = "Model";
		Property::meta.name() = "Property";
		Property::meta.isAbstract() = false;
		Property::meta.stereotype() = "Model";
		SatisfierProperty::meta.name() = "SatisfierProperty";
		SatisfierProperty::meta.isAbstract() = false;
		SatisfierProperty::meta.stereotype() = "Model";
		DataType::meta.name() = "DataType";
		DataType::meta.isAbstract() = false;
		DataType::meta.stereotype() = "Model";
		RequirementSatisfier::meta.name() = "RequirementSatisfier";
		RequirementSatisfier::meta.isAbstract() = true;
		RequirementSatisfier::meta.stereotype() = "Model";
		Capability::meta.name() = "Capability";
		Capability::meta.isAbstract() = false;
		Capability::meta.stereotype() = "Model";
		PackageBaseConnection::meta.name() = "PackageBaseConnection";
		PackageBaseConnection::meta.isAbstract() = false;
		PackageBaseConnection::meta.stereotype() = "Connection";
		PackageReferenceConnection::meta.name() = "PackageReferenceConnection";
		PackageReferenceConnection::meta.isAbstract() = false;
		PackageReferenceConnection::meta.stereotype() = "Connection";
		PackageConfigurationReference::meta.name() = "PackageConfigurationReference";
		PackageConfigurationReference::meta.isAbstract() = false;
		PackageConfigurationReference::meta.stereotype() = "Reference";
		PackageConfiguration::meta.name() = "PackageConfiguration";
		PackageConfiguration::meta.isAbstract() = false;
		PackageConfiguration::meta.stereotype() = "Model";
		PackageConfigurations::meta.name() = "PackageConfigurations";
		PackageConfigurations::meta.isAbstract() = false;
		PackageConfigurations::meta.stereotype() = "Folder";
		PackageConfigurationContainer::meta.name() = "PackageConfigurationContainer";
		PackageConfigurationContainer::meta.isAbstract() = false;
		PackageConfigurationContainer::meta.stereotype() = "Model";
		PackageConfigurationProperty::meta.name() = "PackageConfigurationProperty";
		PackageConfigurationProperty::meta.isAbstract() = false;
		PackageConfigurationProperty::meta.stereotype() = "Connection";
		PackageSelectRequirement::meta.name() = "PackageSelectRequirement";
		PackageSelectRequirement::meta.isAbstract() = false;
		PackageSelectRequirement::meta.stereotype() = "Connection";
		EmitConnector::meta.name() = "EmitConnector";
		EmitConnector::meta.isAbstract() = false;
		EmitConnector::meta.stereotype() = "Connection";
		ComponentAssembly::meta.name() = "ComponentAssembly";
		ComponentAssembly::meta.isAbstract() = false;
		ComponentAssembly::meta.stereotype() = "Model";
		Invocation::meta.name() = "Invocation";
		Invocation::meta.isAbstract() = false;
		Invocation::meta.stereotype() = "Connection";
		SubComponentSelectRequirement::meta.name() = "SubComponentSelectRequirement";
		SubComponentSelectRequirement::meta.isAbstract() = false;
		SubComponentSelectRequirement::meta.stereotype() = "Connection";
		SubComponentConfigProperty::meta.name() = "SubComponentConfigProperty";
		SubComponentConfigProperty::meta.isAbstract() = false;
		SubComponentConfigProperty::meta.stereotype() = "Connection";
		PublishConnector::meta.name() = "PublishConnector";
		PublishConnector::meta.isAbstract() = false;
		PublishConnector::meta.stereotype() = "Atom";
		OutEventPortPublish::meta.name() = "OutEventPortPublish";
		OutEventPortPublish::meta.isAbstract() = false;
		OutEventPortPublish::meta.stereotype() = "Connection";
		InEventPortConsume::meta.name() = "InEventPortConsume";
		InEventPortConsume::meta.isAbstract() = false;
		InEventPortConsume::meta.stereotype() = "Connection";
		ConnectionRequirements::meta.name() = "ConnectionRequirements";
		ConnectionRequirements::meta.isAbstract() = false;
		ConnectionRequirements::meta.stereotype() = "Connection";
		ComponentPackages::meta.name() = "ComponentPackages";
		ComponentPackages::meta.isAbstract() = false;
		ComponentPackages::meta.stereotype() = "Folder";
		PackageInterface::meta.name() = "PackageInterface";
		PackageInterface::meta.isAbstract() = false;
		PackageInterface::meta.stereotype() = "Connection";
		PackageImplementations::meta.name() = "PackageImplementations";
		PackageImplementations::meta.isAbstract() = false;
		PackageImplementations::meta.stereotype() = "Connection";
		PackageContainer::meta.name() = "PackageContainer";
		PackageContainer::meta.isAbstract() = false;
		PackageContainer::meta.stereotype() = "Model";
		PackageConfigProperty::meta.name() = "PackageConfigProperty";
		PackageConfigProperty::meta.isAbstract() = false;
		PackageConfigProperty::meta.stereotype() = "Connection";
		PackageInfoProperty::meta.name() = "PackageInfoProperty";
		PackageInfoProperty::meta.isAbstract() = false;
		PackageInfoProperty::meta.stereotype() = "Connection";
		ComponentPackage::meta.name() = "ComponentPackage";
		ComponentPackage::meta.isAbstract() = false;
		ComponentPackage::meta.stereotype() = "Atom";
		ComponentPackageReference::meta.name() = "ComponentPackageReference";
		ComponentPackageReference::meta.isAbstract() = false;
		ComponentPackageReference::meta.stereotype() = "Reference";
		TopLevelPackageContainer::meta.name() = "TopLevelPackageContainer";
		TopLevelPackageContainer::meta.isAbstract() = false;
		TopLevelPackageContainer::meta.stereotype() = "Model";
		TopLevelPackageFolder::meta.name() = "TopLevelPackageFolder";
		TopLevelPackageFolder::meta.isAbstract() = false;
		TopLevelPackageFolder::meta.stereotype() = "Folder";
		TopLevelPackage::meta.name() = "TopLevelPackage";
		TopLevelPackage::meta.isAbstract() = false;
		TopLevelPackage::meta.stereotype() = "Atom";
		TopLevelPackageConn::meta.name() = "TopLevelPackageConn";
		TopLevelPackageConn::meta.isAbstract() = false;
		TopLevelPackageConn::meta.stereotype() = "Connection";
		EnumerationDef::meta.name() = "EnumerationDef";
		EnumerationDef::meta.isAbstract() = false;
		EnumerationDef::meta.stereotype() = "Model";
		EnumValue::meta.name() = "EnumValue";
		EnumValue::meta.isAbstract() = false;
		EnumValue::meta.stereotype() = "Atom";
		AliasDef::meta.name() = "AliasDef";
		AliasDef::meta.isAbstract() = false;
		AliasDef::meta.stereotype() = "Model";
		AggregateDef::meta.name() = "AggregateDef";
		AggregateDef::meta.isAbstract() = false;
		AggregateDef::meta.stereotype() = "Model";
		SwitchedAggregateDef::meta.name() = "SwitchedAggregateDef";
		SwitchedAggregateDef::meta.isAbstract() = false;
		SwitchedAggregateDef::meta.stereotype() = "Model";
		Label::meta.name() = "Label";
		Label::meta.isAbstract() = false;
		Label::meta.stereotype() = "Atom";
		Discriminator::meta.name() = "Discriminator";
		Discriminator::meta.isAbstract() = false;
		Discriminator::meta.stereotype() = "Model";
		LabelConnection::meta.name() = "LabelConnection";
		LabelConnection::meta.isAbstract() = false;
		LabelConnection::meta.stereotype() = "Connection";
		BoxedDef::meta.name() = "BoxedDef";
		BoxedDef::meta.isAbstract() = false;
		BoxedDef::meta.stereotype() = "Model";
		NamedTypeRef::meta.name() = "NamedTypeRef";
		NamedTypeRef::meta.isAbstract() = false;
		NamedTypeRef::meta.stereotype() = "Reference";
		EnumRef::meta.name() = "EnumRef";
		EnumRef::meta.isAbstract() = false;
		EnumRef::meta.stereotype() = "Reference";
		NamedType::meta.name() = "NamedType";
		NamedType::meta.isAbstract() = true;
		NamedType::meta.stereotype() = "Model";
		Member::meta.name() = "Member";
		Member::meta.isAbstract() = true;
		Member::meta.stereotype() = "FCO";
		NoInheritable::meta.name() = "NoInheritable";
		NoInheritable::meta.isAbstract() = true;
		NoInheritable::meta.stereotype() = "Model";
		IdTag::meta.name() = "IdTag";
		IdTag::meta.isAbstract() = true;
		IdTag::meta.stereotype() = "FCO";
		PrefixTag::meta.name() = "PrefixTag";
		PrefixTag::meta.isAbstract() = false;
		PrefixTag::meta.stereotype() = "Atom";
		GeneralTag::meta.name() = "GeneralTag";
		GeneralTag::meta.isAbstract() = true;
		GeneralTag::meta.stereotype() = "FCO";
		SpecifyIdTag::meta.name() = "SpecifyIdTag";
		SpecifyIdTag::meta.isAbstract() = false;
		SpecifyIdTag::meta.stereotype() = "Atom";
		VersionTag::meta.name() = "VersionTag";
		VersionTag::meta.isAbstract() = false;
		VersionTag::meta.stereotype() = "Atom";
		Prefixable::meta.name() = "Prefixable";
		Prefixable::meta.isAbstract() = true;
		Prefixable::meta.stereotype() = "Model";
		Taggable::meta.name() = "Taggable";
		Taggable::meta.isAbstract() = true;
		Taggable::meta.stereotype() = "Model";
		ReturnType::meta.name() = "ReturnType";
		ReturnType::meta.isAbstract() = false;
		ReturnType::meta.stereotype() = "Model";
		InParameter::meta.name() = "InParameter";
		InParameter::meta.isAbstract() = false;
		InParameter::meta.stereotype() = "Model";
		InoutParameter::meta.name() = "InoutParameter";
		InoutParameter::meta.isAbstract() = false;
		InoutParameter::meta.stereotype() = "Model";
		OutParameter::meta.name() = "OutParameter";
		OutParameter::meta.isAbstract() = false;
		OutParameter::meta.stereotype() = "Model";
		ParameterType::meta.name() = "ParameterType";
		ParameterType::meta.isAbstract() = true;
		ParameterType::meta.stereotype() = "FCO";
		OperationBase::meta.name() = "OperationBase";
		OperationBase::meta.isAbstract() = true;
		OperationBase::meta.stereotype() = "Model";
		Parameter::meta.name() = "Parameter";
		Parameter::meta.isAbstract() = true;
		Parameter::meta.stereotype() = "Model";
		HasExceptions::meta.name() = "HasExceptions";
		HasExceptions::meta.isAbstract() = true;
		HasExceptions::meta.stereotype() = "Model";
		OnewayOperation::meta.name() = "OnewayOperation";
		OnewayOperation::meta.isAbstract() = false;
		OnewayOperation::meta.stereotype() = "Model";
		LookupOperation::meta.name() = "LookupOperation";
		LookupOperation::meta.isAbstract() = false;
		LookupOperation::meta.stereotype() = "Model";
		FactoryOperation::meta.name() = "FactoryOperation";
		FactoryOperation::meta.isAbstract() = false;
		FactoryOperation::meta.stereotype() = "Model";
		TwowayOperation::meta.name() = "TwowayOperation";
		TwowayOperation::meta.isAbstract() = false;
		TwowayOperation::meta.stereotype() = "Model";
		Package::meta.name() = "Package";
		Package::meta.isAbstract() = false;
		Package::meta.stereotype() = "Model";
		Type::meta.name() = "Type";
		Type::meta.isAbstract() = true;
		Type::meta.stereotype() = "FCO";
		ExceptionRef::meta.name() = "ExceptionRef";
		ExceptionRef::meta.isAbstract() = false;
		ExceptionRef::meta.stereotype() = "Reference";
		FileRef::meta.name() = "FileRef";
		FileRef::meta.isAbstract() = false;
		FileRef::meta.stereotype() = "Reference";
		ConstantDef::meta.name() = "ConstantDef";
		ConstantDef::meta.isAbstract() = false;
		ConstantDef::meta.stereotype() = "Model";
		ExceptionDef::meta.name() = "ExceptionDef";
		ExceptionDef::meta.isAbstract() = false;
		ExceptionDef::meta.stereotype() = "Model";
		RequestPort::meta.name() = "RequestPort";
		RequestPort::meta.isAbstract() = true;
		RequestPort::meta.stereotype() = "Model";
		EventPort::meta.name() = "EventPort";
		EventPort::meta.isAbstract() = true;
		EventPort::meta.stereotype() = "Model";
		EventRef::meta.name() = "EventRef";
		EventRef::meta.isAbstract() = false;
		EventRef::meta.stereotype() = "Reference";
		ObjectRef::meta.name() = "ObjectRef";
		ObjectRef::meta.isAbstract() = false;
		ObjectRef::meta.stereotype() = "Reference";
		ProvidedRequestPort::meta.name() = "ProvidedRequestPort";
		ProvidedRequestPort::meta.isAbstract() = false;
		ProvidedRequestPort::meta.stereotype() = "Model";
		RequiredRequestPort::meta.name() = "RequiredRequestPort";
		RequiredRequestPort::meta.isAbstract() = false;
		RequiredRequestPort::meta.stereotype() = "Model";
		OutEventPort::meta.name() = "OutEventPort";
		OutEventPort::meta.isAbstract() = false;
		OutEventPort::meta.stereotype() = "Model";
		InEventPort::meta.name() = "InEventPort";
		InEventPort::meta.isAbstract() = false;
		InEventPort::meta.stereotype() = "Model";
		Port::meta.name() = "Port";
		Port::meta.isAbstract() = true;
		Port::meta.stereotype() = "Model";
		ComponentDef::meta.name() = "ComponentDef";
		ComponentDef::meta.isAbstract() = false;
		ComponentDef::meta.stereotype() = "Model";
		BoundedString::meta.name() = "BoundedString";
		BoundedString::meta.isAbstract() = false;
		BoundedString::meta.stereotype() = "Atom";
		FixedSizeCollection::meta.name() = "FixedSizeCollection";
		FixedSizeCollection::meta.isAbstract() = false;
		FixedSizeCollection::meta.stereotype() = "Model";
		VariableSizeCollection::meta.name() = "VariableSizeCollection";
		VariableSizeCollection::meta.isAbstract() = false;
		VariableSizeCollection::meta.stereotype() = "Model";
		AnonymousType::meta.name() = "AnonymousType";
		AnonymousType::meta.isAbstract() = true;
		AnonymousType::meta.stereotype() = "FCO";
		CollectionType::meta.name() = "CollectionType";
		CollectionType::meta.isAbstract() = true;
		CollectionType::meta.stereotype() = "Model";
		PredefinedType::meta.name() = "PredefinedType";
		PredefinedType::meta.isAbstract() = false;
		PredefinedType::meta.stereotype() = "Atom";
		FixedPoint::meta.name() = "FixedPoint";
		FixedPoint::meta.isAbstract() = false;
		FixedPoint::meta.stereotype() = "Atom";
		ObjectDef::meta.name() = "ObjectDef";
		ObjectDef::meta.isAbstract() = false;
		ObjectDef::meta.stereotype() = "Model";
		ComponentFactory::meta.name() = "ComponentFactory";
		ComponentFactory::meta.isAbstract() = false;
		ComponentFactory::meta.stereotype() = "Model";
		Inherits::meta.name() = "Inherits";
		Inherits::meta.isAbstract() = false;
		Inherits::meta.stereotype() = "Reference";
		EventDef::meta.name() = "EventDef";
		EventDef::meta.isAbstract() = false;
		EventDef::meta.stereotype() = "Model";
		ValueDef::meta.name() = "ValueDef";
		ValueDef::meta.isAbstract() = false;
		ValueDef::meta.stereotype() = "Model";
		Inheritable::meta.name() = "Inheritable";
		Inheritable::meta.isAbstract() = true;
		Inheritable::meta.stereotype() = "Model";
		HasOperations::meta.name() = "HasOperations";
		HasOperations::meta.isAbstract() = true;
		HasOperations::meta.stereotype() = "Model";
		SupportsInterfaces::meta.name() = "SupportsInterfaces";
		SupportsInterfaces::meta.isAbstract() = true;
		SupportsInterfaces::meta.stereotype() = "Model";
		Supports::meta.name() = "Supports";
		Supports::meta.isAbstract() = false;
		Supports::meta.stereotype() = "Reference";
		ReadonlyAttribute::meta.name() = "ReadonlyAttribute";
		ReadonlyAttribute::meta.isAbstract() = false;
		ReadonlyAttribute::meta.stereotype() = "Model";
		Attribute::meta.name() = "Attribute";
		Attribute::meta.isAbstract() = false;
		Attribute::meta.stereotype() = "Model";
		LookupKey::meta.name() = "LookupKey";
		LookupKey::meta.isAbstract() = false;
		LookupKey::meta.stereotype() = "Reference";
		Manages::meta.name() = "Manages";
		Manages::meta.isAbstract() = false;
		Manages::meta.stereotype() = "Reference";
		SetException::meta.name() = "SetException";
		SetException::meta.isAbstract() = false;
		SetException::meta.stereotype() = "Reference";
		ObjectByValue::meta.name() = "ObjectByValue";
		ObjectByValue::meta.isAbstract() = true;
		ObjectByValue::meta.stereotype() = "Model";
		GetException::meta.name() = "GetException";
		GetException::meta.isAbstract() = false;
		GetException::meta.stereotype() = "Reference";
		PrivateFlag::meta.name() = "PrivateFlag";
		PrivateFlag::meta.isAbstract() = false;
		PrivateFlag::meta.stereotype() = "Atom";
		MakeMemberPrivate::meta.name() = "MakeMemberPrivate";
		MakeMemberPrivate::meta.isAbstract() = false;
		MakeMemberPrivate::meta.stereotype() = "Connection";
		RootFolder::meta.name() = "RootFolder";
		RootFolder::meta.isAbstract() = false;
		RootFolder::meta.stereotype() = "Folder";
		MgaObject::meta.name() = "MgaObject";
		MgaObject::meta.isAbstract() = true;
		
		ImplementationArtifacts::meta_name.name() = "name";
		ImplementationArtifacts::meta_name.type() = "String";
		ImplementationArtifacts::meta_name.min() = 0;
		ImplementationArtifacts::meta_name.max() = 1;
		ImplementationArtifacts::meta_name.nonpersistent() = false;
		ImplementationArtifacts::meta_name.registry() = false;
		ImplementationArtifacts::meta_name.ordered() = false;
		ImplementationArtifacts::meta_name.visibility() = "public";
		ImplementationArtifacts::meta_name.defvalue() = vector<string>();
		IDLFiles::meta_name.name() = "name";
		IDLFiles::meta_name.type() = "String";
		IDLFiles::meta_name.min() = 0;
		IDLFiles::meta_name.max() = 1;
		IDLFiles::meta_name.nonpersistent() = false;
		IDLFiles::meta_name.registry() = false;
		IDLFiles::meta_name.ordered() = false;
		IDLFiles::meta_name.visibility() = "public";
		IDLFiles::meta_name.defvalue() = vector<string>();
		ComponentTypes::meta_name.name() = "name";
		ComponentTypes::meta_name.type() = "String";
		ComponentTypes::meta_name.min() = 0;
		ComponentTypes::meta_name.max() = 1;
		ComponentTypes::meta_name.nonpersistent() = false;
		ComponentTypes::meta_name.registry() = false;
		ComponentTypes::meta_name.ordered() = false;
		ComponentTypes::meta_name.visibility() = "public";
		ComponentTypes::meta_name.defvalue() = vector<string>();
		ComponentImplementations::meta_name.name() = "name";
		ComponentImplementations::meta_name.type() = "String";
		ComponentImplementations::meta_name.min() = 0;
		ComponentImplementations::meta_name.max() = 1;
		ComponentImplementations::meta_name.nonpersistent() = false;
		ComponentImplementations::meta_name.registry() = false;
		ComponentImplementations::meta_name.ordered() = false;
		ComponentImplementations::meta_name.visibility() = "public";
		ComponentImplementations::meta_name.defvalue() = vector<string>();
		PackageConfigurations::meta_name.name() = "name";
		PackageConfigurations::meta_name.type() = "String";
		PackageConfigurations::meta_name.min() = 0;
		PackageConfigurations::meta_name.max() = 1;
		PackageConfigurations::meta_name.nonpersistent() = false;
		PackageConfigurations::meta_name.registry() = false;
		PackageConfigurations::meta_name.ordered() = false;
		PackageConfigurations::meta_name.visibility() = "public";
		PackageConfigurations::meta_name.defvalue() = vector<string>();
		ComponentPackages::meta_name.name() = "name";
		ComponentPackages::meta_name.type() = "String";
		ComponentPackages::meta_name.min() = 0;
		ComponentPackages::meta_name.max() = 1;
		ComponentPackages::meta_name.nonpersistent() = false;
		ComponentPackages::meta_name.registry() = false;
		ComponentPackages::meta_name.ordered() = false;
		ComponentPackages::meta_name.visibility() = "public";
		ComponentPackages::meta_name.defvalue() = vector<string>();
		TopLevelPackageFolder::meta_name.name() = "name";
		TopLevelPackageFolder::meta_name.type() = "String";
		TopLevelPackageFolder::meta_name.min() = 0;
		TopLevelPackageFolder::meta_name.max() = 1;
		TopLevelPackageFolder::meta_name.nonpersistent() = false;
		TopLevelPackageFolder::meta_name.registry() = false;
		TopLevelPackageFolder::meta_name.ordered() = false;
		TopLevelPackageFolder::meta_name.visibility() = "public";
		TopLevelPackageFolder::meta_name.defvalue() = vector<string>();
		ConstantDef::meta_value.name() = "value";
		ConstantDef::meta_value.type() = "String";
		ConstantDef::meta_value.min() = 1;
		ConstantDef::meta_value.max() = 1;
		ConstantDef::meta_value.nonpersistent() = false;
		ConstantDef::meta_value.registry() = false;
		ConstantDef::meta_value.ordered() = false;
		ConstantDef::meta_value.visibility() = "public";
		ConstantDef::meta_value.defvalue() = vector<string>();
		vector<string> RequiredRequestPort_multiple_connections_dva;
		RequiredRequestPort_multiple_connections_dva.push_back("false");
		RequiredRequestPort::meta_multiple_connections.name() = "multiple_connections";
		RequiredRequestPort::meta_multiple_connections.type() = "Boolean";
		RequiredRequestPort::meta_multiple_connections.min() = 1;
		RequiredRequestPort::meta_multiple_connections.max() = 1;
		RequiredRequestPort::meta_multiple_connections.nonpersistent() = false;
		RequiredRequestPort::meta_multiple_connections.registry() = false;
		RequiredRequestPort::meta_multiple_connections.ordered() = false;
		RequiredRequestPort::meta_multiple_connections.visibility() = "public";
		RequiredRequestPort::meta_multiple_connections.defvalue() = RequiredRequestPort_multiple_connections_dva;
		vector<string> OutEventPort_single_destination_dva;
		OutEventPort_single_destination_dva.push_back("false");
		OutEventPort::meta_single_destination.name() = "single_destination";
		OutEventPort::meta_single_destination.type() = "Boolean";
		OutEventPort::meta_single_destination.min() = 1;
		OutEventPort::meta_single_destination.max() = 1;
		OutEventPort::meta_single_destination.nonpersistent() = false;
		OutEventPort::meta_single_destination.registry() = false;
		OutEventPort::meta_single_destination.ordered() = false;
		OutEventPort::meta_single_destination.visibility() = "public";
		OutEventPort::meta_single_destination.defvalue() = OutEventPort_single_destination_dva;
		vector<string> BoundedString_wide_dva;
		BoundedString_wide_dva.push_back("false");
		BoundedString::meta_wide.name() = "wide";
		BoundedString::meta_wide.type() = "Boolean";
		BoundedString::meta_wide.min() = 1;
		BoundedString::meta_wide.max() = 1;
		BoundedString::meta_wide.nonpersistent() = false;
		BoundedString::meta_wide.registry() = false;
		BoundedString::meta_wide.ordered() = false;
		BoundedString::meta_wide.visibility() = "public";
		BoundedString::meta_wide.defvalue() = BoundedString_wide_dva;
		vector<string> BoundedString_bound_dva;
		BoundedString_bound_dva.push_back("0");
		BoundedString::meta_bound.name() = "bound";
		BoundedString::meta_bound.type() = "Integer";
		BoundedString::meta_bound.min() = 1;
		BoundedString::meta_bound.max() = 1;
		BoundedString::meta_bound.nonpersistent() = false;
		BoundedString::meta_bound.registry() = false;
		BoundedString::meta_bound.ordered() = false;
		BoundedString::meta_bound.visibility() = "public";
		BoundedString::meta_bound.defvalue() = BoundedString_bound_dva;
		vector<string> CollectionType_bound_dva;
		CollectionType_bound_dva.push_back("0");
		CollectionType::meta_bound.name() = "bound";
		CollectionType::meta_bound.type() = "Integer";
		CollectionType::meta_bound.min() = 1;
		CollectionType::meta_bound.max() = 1;
		CollectionType::meta_bound.nonpersistent() = false;
		CollectionType::meta_bound.registry() = false;
		CollectionType::meta_bound.ordered() = false;
		CollectionType::meta_bound.visibility() = "public";
		CollectionType::meta_bound.defvalue() = CollectionType_bound_dva;
		vector<string> PredefinedType_which_type_dva;
		PredefinedType_which_type_dva.push_back("UNSIGNED_LONG");
		PredefinedType::meta_which_type.name() = "which_type";
		PredefinedType::meta_which_type.type() = "String";
		PredefinedType::meta_which_type.min() = 1;
		PredefinedType::meta_which_type.max() = 1;
		PredefinedType::meta_which_type.nonpersistent() = false;
		PredefinedType::meta_which_type.registry() = false;
		PredefinedType::meta_which_type.ordered() = false;
		PredefinedType::meta_which_type.visibility() = "public";
		PredefinedType::meta_which_type.defvalue() = PredefinedType_which_type_dva;
		FixedPoint::meta_total_digits.name() = "total_digits";
		FixedPoint::meta_total_digits.type() = "Integer";
		FixedPoint::meta_total_digits.min() = 1;
		FixedPoint::meta_total_digits.max() = 1;
		FixedPoint::meta_total_digits.nonpersistent() = false;
		FixedPoint::meta_total_digits.registry() = false;
		FixedPoint::meta_total_digits.ordered() = false;
		FixedPoint::meta_total_digits.visibility() = "public";
		FixedPoint::meta_total_digits.defvalue() = vector<string>();
		FixedPoint::meta_decimal_digits.name() = "decimal_digits";
		FixedPoint::meta_decimal_digits.type() = "Integer";
		FixedPoint::meta_decimal_digits.min() = 1;
		FixedPoint::meta_decimal_digits.max() = 1;
		FixedPoint::meta_decimal_digits.nonpersistent() = false;
		FixedPoint::meta_decimal_digits.registry() = false;
		FixedPoint::meta_decimal_digits.ordered() = false;
		FixedPoint::meta_decimal_digits.visibility() = "public";
		FixedPoint::meta_decimal_digits.defvalue() = vector<string>();
		vector<string> ObjectDef_local_dva;
		ObjectDef_local_dva.push_back("false");
		ObjectDef::meta_local.name() = "local";
		ObjectDef::meta_local.type() = "Boolean";
		ObjectDef::meta_local.min() = 1;
		ObjectDef::meta_local.max() = 1;
		ObjectDef::meta_local.nonpersistent() = false;
		ObjectDef::meta_local.registry() = false;
		ObjectDef::meta_local.ordered() = false;
		ObjectDef::meta_local.visibility() = "public";
		ObjectDef::meta_local.defvalue() = ObjectDef_local_dva;
		vector<string> ObjectDef_abstract_dva;
		ObjectDef_abstract_dva.push_back("false");
		ObjectDef::meta_abstract.name() = "abstract";
		ObjectDef::meta_abstract.type() = "Boolean";
		ObjectDef::meta_abstract.min() = 1;
		ObjectDef::meta_abstract.max() = 1;
		ObjectDef::meta_abstract.nonpersistent() = false;
		ObjectDef::meta_abstract.registry() = false;
		ObjectDef::meta_abstract.ordered() = false;
		ObjectDef::meta_abstract.visibility() = "public";
		ObjectDef::meta_abstract.defvalue() = ObjectDef_abstract_dva;
		vector<string> ObjectByValue_custom_dva;
		ObjectByValue_custom_dva.push_back("false");
		ObjectByValue::meta_custom.name() = "custom";
		ObjectByValue::meta_custom.type() = "Boolean";
		ObjectByValue::meta_custom.min() = 1;
		ObjectByValue::meta_custom.max() = 1;
		ObjectByValue::meta_custom.nonpersistent() = false;
		ObjectByValue::meta_custom.registry() = false;
		ObjectByValue::meta_custom.ordered() = false;
		ObjectByValue::meta_custom.visibility() = "public";
		ObjectByValue::meta_custom.defvalue() = ObjectByValue_custom_dva;
		vector<string> ObjectByValue_abstract_dva;
		ObjectByValue_abstract_dva.push_back("false");
		ObjectByValue::meta_abstract.name() = "abstract";
		ObjectByValue::meta_abstract.type() = "Boolean";
		ObjectByValue::meta_abstract.min() = 1;
		ObjectByValue::meta_abstract.max() = 1;
		ObjectByValue::meta_abstract.nonpersistent() = false;
		ObjectByValue::meta_abstract.registry() = false;
		ObjectByValue::meta_abstract.ordered() = false;
		ObjectByValue::meta_abstract.visibility() = "public";
		ObjectByValue::meta_abstract.defvalue() = ObjectByValue_abstract_dva;
		vector<string> ObjectByValue_truncatable_dva;
		ObjectByValue_truncatable_dva.push_back("false");
		ObjectByValue::meta_truncatable.name() = "truncatable";
		ObjectByValue::meta_truncatable.type() = "Boolean";
		ObjectByValue::meta_truncatable.min() = 1;
		ObjectByValue::meta_truncatable.max() = 1;
		ObjectByValue::meta_truncatable.nonpersistent() = false;
		ObjectByValue::meta_truncatable.registry() = false;
		ObjectByValue::meta_truncatable.ordered() = false;
		ObjectByValue::meta_truncatable.visibility() = "public";
		ObjectByValue::meta_truncatable.defvalue() = ObjectByValue_truncatable_dva;
		RootFolder::meta_name.name() = "name";
		RootFolder::meta_name.type() = "String";
		RootFolder::meta_name.min() = 0;
		RootFolder::meta_name.max() = 1;
		RootFolder::meta_name.nonpersistent() = false;
		RootFolder::meta_name.registry() = false;
		RootFolder::meta_name.ordered() = false;
		RootFolder::meta_name.visibility() = "public";
		RootFolder::meta_name.defvalue() = vector<string>();
		MgaObject::meta_position.name() = "position";
		MgaObject::meta_position.type() = "String";
		MgaObject::meta_position.min() = 0;
		MgaObject::meta_position.max() = 1;
		MgaObject::meta_position.nonpersistent() = false;
		MgaObject::meta_position.registry() = false;
		MgaObject::meta_position.ordered() = false;
		MgaObject::meta_position.visibility() = "public";
		MgaObject::meta_position.defvalue() = vector<string>();
		MgaObject::meta_name.name() = "name";
		MgaObject::meta_name.type() = "String";
		MgaObject::meta_name.min() = 0;
		MgaObject::meta_name.max() = 1;
		MgaObject::meta_name.nonpersistent() = false;
		MgaObject::meta_name.registry() = false;
		MgaObject::meta_name.ordered() = false;
		MgaObject::meta_name.visibility() = "public";
		MgaObject::meta_name.defvalue() = vector<string>();
		
	}
	void Initialize()
	{
		static bool first = true;
		if(!first) return;
		first = false;
		 Uml::Initialize();

		CadenaScenario2PICMLAssembly::Initialize();

		ASSERT( umldiagram == Udm::null );
		UdmStatic::StaticDataNetwork * meta_dn = new UdmStatic::StaticDataNetwork(Uml::diagram);
		meta_dn->CreateNew("PICML.mem", "", Uml::Diagram::meta, Udm::CHANGES_LOST_DEFAULT);
		umldiagram = Uml::Diagram::Cast(meta_dn->GetRootObject());
		umldiagram.name() ="PICML";
		umldiagram.version() ="1.00";
		Creates();
		InitClassesAttributes();
		Uml::InitDiagram(umldiagram, "PICML", "1.00");

		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ArtifactDependsOn";
			ass.assocClass() = ArtifactDependsOn::meta;
			ImplementationArtifactReference::meta_srcArtifactDependsOn = Uml::AssociationRole::Create(ass);
			ImplementationArtifactReference::meta_srcArtifactDependsOn.name() = "srcArtifactDependsOn";
			ImplementationArtifactReference::meta_srcArtifactDependsOn.min() = 0;
			ImplementationArtifactReference::meta_srcArtifactDependsOn.max() = -1;
			ImplementationArtifactReference::meta_srcArtifactDependsOn.isNavigable() = true;
			ImplementationArtifactReference::meta_srcArtifactDependsOn.isPrimary() = false;
			ImplementationArtifactReference::meta_srcArtifactDependsOn.target() = ImplementationArtifact::meta;
			ArtifactDependsOn::meta_srcArtifactDependsOn_end_ = ImplementationArtifact::meta_dstArtifactDependsOn_rev = ImplementationArtifactReference::meta_srcArtifactDependsOn;
			ImplementationArtifact::meta_dstArtifactDependsOn = Uml::AssociationRole::Create(ass);
			ImplementationArtifact::meta_dstArtifactDependsOn.name() = "dstArtifactDependsOn";
			ImplementationArtifact::meta_dstArtifactDependsOn.min() = 0;
			ImplementationArtifact::meta_dstArtifactDependsOn.max() = -1;
			ImplementationArtifact::meta_dstArtifactDependsOn.isNavigable() = true;
			ImplementationArtifact::meta_dstArtifactDependsOn.isPrimary() = false;
			ImplementationArtifact::meta_dstArtifactDependsOn.target() = ImplementationArtifactReference::meta;
			ArtifactDependsOn::meta_dstArtifactDependsOn_end_ = ImplementationArtifactReference::meta_srcArtifactDependsOn_rev = ImplementationArtifact::meta_dstArtifactDependsOn;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ImplementationArtifactReference::meta_ref = Uml::AssociationRole::Create(ass);
			ImplementationArtifactReference::meta_ref.name() = "ref";
			ImplementationArtifactReference::meta_ref.min() = 0;
			ImplementationArtifactReference::meta_ref.max() = 1;
			ImplementationArtifactReference::meta_ref.isNavigable() = true;
			ImplementationArtifactReference::meta_ref.isPrimary() = false;
			ImplementationArtifactReference::meta_ref.target() = ImplementationArtifact::meta;
			ImplementationArtifact::meta_referedbyImplementationArtifactReference = Uml::AssociationRole::Create(ass);
			ImplementationArtifact::meta_referedbyImplementationArtifactReference.name() = "referedbyImplementationArtifactReference";
			ImplementationArtifact::meta_referedbyImplementationArtifactReference.min() = 0;
			ImplementationArtifact::meta_referedbyImplementationArtifactReference.max() = -1;
			ImplementationArtifact::meta_referedbyImplementationArtifactReference.isNavigable() = true;
			ImplementationArtifact::meta_referedbyImplementationArtifactReference.isPrimary() = false;
			ImplementationArtifact::meta_referedbyImplementationArtifactReference.target() = ImplementationArtifactReference::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "MonolithprimaryArtifact";
			ass.assocClass() = MonolithprimaryArtifact::meta;
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact = Uml::AssociationRole::Create(ass);
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact.name() = "srcMonolithprimaryArtifact";
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact.min() = 0;
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact.max() = -1;
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact.isNavigable() = true;
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact.isPrimary() = false;
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact.target() = MonolithicImplementation::meta;
			MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_ = MonolithicImplementation::meta_dstMonolithprimaryArtifact_rev = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;
			MonolithicImplementation::meta_dstMonolithprimaryArtifact = Uml::AssociationRole::Create(ass);
			MonolithicImplementation::meta_dstMonolithprimaryArtifact.name() = "dstMonolithprimaryArtifact";
			MonolithicImplementation::meta_dstMonolithprimaryArtifact.min() = 0;
			MonolithicImplementation::meta_dstMonolithprimaryArtifact.max() = -1;
			MonolithicImplementation::meta_dstMonolithprimaryArtifact.isNavigable() = true;
			MonolithicImplementation::meta_dstMonolithprimaryArtifact.isPrimary() = false;
			MonolithicImplementation::meta_dstMonolithprimaryArtifact.target() = ImplementationArtifactReference::meta;
			MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_ = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev = MonolithicImplementation::meta_dstMonolithprimaryArtifact;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ArtifactDeployRequirement";
			ass.assocClass() = ArtifactDeployRequirement::meta;
			Requirement::meta_srcArtifactDeployRequirement = Uml::AssociationRole::Create(ass);
			Requirement::meta_srcArtifactDeployRequirement.name() = "srcArtifactDeployRequirement";
			Requirement::meta_srcArtifactDeployRequirement.min() = 0;
			Requirement::meta_srcArtifactDeployRequirement.max() = -1;
			Requirement::meta_srcArtifactDeployRequirement.isNavigable() = true;
			Requirement::meta_srcArtifactDeployRequirement.isPrimary() = false;
			Requirement::meta_srcArtifactDeployRequirement.target() = ImplementationArtifact::meta;
			ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_ = ImplementationArtifact::meta_dstArtifactDeployRequirement_rev = Requirement::meta_srcArtifactDeployRequirement;
			ImplementationArtifact::meta_dstArtifactDeployRequirement = Uml::AssociationRole::Create(ass);
			ImplementationArtifact::meta_dstArtifactDeployRequirement.name() = "dstArtifactDeployRequirement";
			ImplementationArtifact::meta_dstArtifactDeployRequirement.min() = 0;
			ImplementationArtifact::meta_dstArtifactDeployRequirement.max() = -1;
			ImplementationArtifact::meta_dstArtifactDeployRequirement.isNavigable() = true;
			ImplementationArtifact::meta_dstArtifactDeployRequirement.isPrimary() = false;
			ImplementationArtifact::meta_dstArtifactDeployRequirement.target() = Requirement::meta;
			ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_ = Requirement::meta_srcArtifactDeployRequirement_rev = ImplementationArtifact::meta_dstArtifactDeployRequirement;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ArtifactExecParameter";
			ass.assocClass() = ArtifactExecParameter::meta;
			Property::meta_srcArtifactExecParameter = Uml::AssociationRole::Create(ass);
			Property::meta_srcArtifactExecParameter.name() = "srcArtifactExecParameter";
			Property::meta_srcArtifactExecParameter.min() = 0;
			Property::meta_srcArtifactExecParameter.max() = -1;
			Property::meta_srcArtifactExecParameter.isNavigable() = true;
			Property::meta_srcArtifactExecParameter.isPrimary() = false;
			Property::meta_srcArtifactExecParameter.target() = ImplementationArtifact::meta;
			ArtifactExecParameter::meta_srcArtifactExecParameter_end_ = ImplementationArtifact::meta_dstArtifactExecParameter_rev = Property::meta_srcArtifactExecParameter;
			ImplementationArtifact::meta_dstArtifactExecParameter = Uml::AssociationRole::Create(ass);
			ImplementationArtifact::meta_dstArtifactExecParameter.name() = "dstArtifactExecParameter";
			ImplementationArtifact::meta_dstArtifactExecParameter.min() = 0;
			ImplementationArtifact::meta_dstArtifactExecParameter.max() = -1;
			ImplementationArtifact::meta_dstArtifactExecParameter.isNavigable() = true;
			ImplementationArtifact::meta_dstArtifactExecParameter.isPrimary() = false;
			ImplementationArtifact::meta_dstArtifactExecParameter.target() = Property::meta;
			ArtifactExecParameter::meta_dstArtifactExecParameter_end_ = Property::meta_srcArtifactExecParameter_rev = ImplementationArtifact::meta_dstArtifactExecParameter;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ArtifactInfoProperty";
			ass.assocClass() = ArtifactInfoProperty::meta;
			Property::meta_srcArtifactInfoProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcArtifactInfoProperty.name() = "srcArtifactInfoProperty";
			Property::meta_srcArtifactInfoProperty.min() = 0;
			Property::meta_srcArtifactInfoProperty.max() = -1;
			Property::meta_srcArtifactInfoProperty.isNavigable() = true;
			Property::meta_srcArtifactInfoProperty.isPrimary() = false;
			Property::meta_srcArtifactInfoProperty.target() = ImplementationArtifact::meta;
			ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_ = ImplementationArtifact::meta_dstArtifactInfoProperty_rev = Property::meta_srcArtifactInfoProperty;
			ImplementationArtifact::meta_dstArtifactInfoProperty = Uml::AssociationRole::Create(ass);
			ImplementationArtifact::meta_dstArtifactInfoProperty.name() = "dstArtifactInfoProperty";
			ImplementationArtifact::meta_dstArtifactInfoProperty.min() = 0;
			ImplementationArtifact::meta_dstArtifactInfoProperty.max() = -1;
			ImplementationArtifact::meta_dstArtifactInfoProperty.isNavigable() = true;
			ImplementationArtifact::meta_dstArtifactInfoProperty.isPrimary() = false;
			ImplementationArtifact::meta_dstArtifactInfoProperty.target() = Property::meta;
			ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_ = Property::meta_srcArtifactInfoProperty_rev = ImplementationArtifact::meta_dstArtifactInfoProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			IDLFile::meta_referedbyFileRef = Uml::AssociationRole::Create(ass);
			IDLFile::meta_referedbyFileRef.name() = "referedbyFileRef";
			IDLFile::meta_referedbyFileRef.min() = 0;
			IDLFile::meta_referedbyFileRef.max() = -1;
			IDLFile::meta_referedbyFileRef.isNavigable() = true;
			IDLFile::meta_referedbyFileRef.isPrimary() = false;
			IDLFile::meta_referedbyFileRef.target() = FileRef::meta;
			FileRef::meta_ref = Uml::AssociationRole::Create(ass);
			FileRef::meta_ref.name() = "ref";
			FileRef::meta_ref.min() = 0;
			FileRef::meta_ref.max() = 1;
			FileRef::meta_ref.isNavigable() = true;
			FileRef::meta_ref.isPrimary() = false;
			FileRef::meta_ref.target() = IDLFile::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ComponentConfigProperty";
			ass.assocClass() = ComponentConfigProperty::meta;
			ComponentType::meta_dstComponentConfigProperty = Uml::AssociationRole::Create(ass);
			ComponentType::meta_dstComponentConfigProperty.name() = "dstComponentConfigProperty";
			ComponentType::meta_dstComponentConfigProperty.min() = 0;
			ComponentType::meta_dstComponentConfigProperty.max() = -1;
			ComponentType::meta_dstComponentConfigProperty.isNavigable() = true;
			ComponentType::meta_dstComponentConfigProperty.isPrimary() = false;
			ComponentType::meta_dstComponentConfigProperty.target() = Property::meta;
			ComponentConfigProperty::meta_dstComponentConfigProperty_end_ = Property::meta_srcComponentConfigProperty_rev = ComponentType::meta_dstComponentConfigProperty;
			Property::meta_srcComponentConfigProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcComponentConfigProperty.name() = "srcComponentConfigProperty";
			Property::meta_srcComponentConfigProperty.min() = 0;
			Property::meta_srcComponentConfigProperty.max() = -1;
			Property::meta_srcComponentConfigProperty.isNavigable() = true;
			Property::meta_srcComponentConfigProperty.isPrimary() = false;
			Property::meta_srcComponentConfigProperty.target() = ComponentType::meta;
			ComponentConfigProperty::meta_srcComponentConfigProperty_end_ = ComponentType::meta_dstComponentConfigProperty_rev = Property::meta_srcComponentConfigProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ComponentProperty";
			ass.assocClass() = ComponentProperty::meta;
			ComponentType::meta_dstComponentProperty = Uml::AssociationRole::Create(ass);
			ComponentType::meta_dstComponentProperty.name() = "dstComponentProperty";
			ComponentType::meta_dstComponentProperty.min() = 0;
			ComponentType::meta_dstComponentProperty.max() = -1;
			ComponentType::meta_dstComponentProperty.isNavigable() = true;
			ComponentType::meta_dstComponentProperty.isPrimary() = false;
			ComponentType::meta_dstComponentProperty.target() = ComponentPropertyDescription::meta;
			ComponentProperty::meta_dstComponentProperty_end_ = ComponentPropertyDescription::meta_srcComponentProperty_rev = ComponentType::meta_dstComponentProperty;
			ComponentPropertyDescription::meta_srcComponentProperty = Uml::AssociationRole::Create(ass);
			ComponentPropertyDescription::meta_srcComponentProperty.name() = "srcComponentProperty";
			ComponentPropertyDescription::meta_srcComponentProperty.min() = 0;
			ComponentPropertyDescription::meta_srcComponentProperty.max() = -1;
			ComponentPropertyDescription::meta_srcComponentProperty.isNavigable() = true;
			ComponentPropertyDescription::meta_srcComponentProperty.isPrimary() = false;
			ComponentPropertyDescription::meta_srcComponentProperty.target() = ComponentType::meta;
			ComponentProperty::meta_srcComponentProperty_end_ = ComponentType::meta_dstComponentProperty_rev = ComponentPropertyDescription::meta_srcComponentProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ComponentInfoProperty";
			ass.assocClass() = ComponentInfoProperty::meta;
			ComponentType::meta_dstComponentInfoProperty = Uml::AssociationRole::Create(ass);
			ComponentType::meta_dstComponentInfoProperty.name() = "dstComponentInfoProperty";
			ComponentType::meta_dstComponentInfoProperty.min() = 0;
			ComponentType::meta_dstComponentInfoProperty.max() = -1;
			ComponentType::meta_dstComponentInfoProperty.isNavigable() = true;
			ComponentType::meta_dstComponentInfoProperty.isPrimary() = false;
			ComponentType::meta_dstComponentInfoProperty.target() = Property::meta;
			ComponentInfoProperty::meta_dstComponentInfoProperty_end_ = Property::meta_srcComponentInfoProperty_rev = ComponentType::meta_dstComponentInfoProperty;
			Property::meta_srcComponentInfoProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcComponentInfoProperty.name() = "srcComponentInfoProperty";
			Property::meta_srcComponentInfoProperty.min() = 0;
			Property::meta_srcComponentInfoProperty.max() = -1;
			Property::meta_srcComponentInfoProperty.isNavigable() = true;
			Property::meta_srcComponentInfoProperty.isPrimary() = false;
			Property::meta_srcComponentInfoProperty.target() = ComponentType::meta;
			ComponentInfoProperty::meta_srcComponentInfoProperty_end_ = ComponentType::meta_dstComponentInfoProperty_rev = Property::meta_srcComponentInfoProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ComponentType::meta_ref = Uml::AssociationRole::Create(ass);
			ComponentType::meta_ref.name() = "ref";
			ComponentType::meta_ref.min() = 0;
			ComponentType::meta_ref.max() = 1;
			ComponentType::meta_ref.isNavigable() = true;
			ComponentType::meta_ref.isPrimary() = false;
			ComponentType::meta_ref.target() = ComponentDef::meta;
			ComponentDef::meta_referedbyComponentType = Uml::AssociationRole::Create(ass);
			ComponentDef::meta_referedbyComponentType.name() = "referedbyComponentType";
			ComponentDef::meta_referedbyComponentType.min() = 0;
			ComponentDef::meta_referedbyComponentType.max() = -1;
			ComponentDef::meta_referedbyComponentType.isNavigable() = true;
			ComponentDef::meta_referedbyComponentType.isPrimary() = false;
			ComponentDef::meta_referedbyComponentType.target() = ComponentType::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "Implements";
			ass.assocClass() = Implements::meta;
			ComponentType::meta_srcImplements = Uml::AssociationRole::Create(ass);
			ComponentType::meta_srcImplements.name() = "srcImplements";
			ComponentType::meta_srcImplements.min() = 0;
			ComponentType::meta_srcImplements.max() = -1;
			ComponentType::meta_srcImplements.isNavigable() = true;
			ComponentType::meta_srcImplements.isPrimary() = false;
			ComponentType::meta_srcImplements.target() = ComponentImplementation::meta;
			Implements::meta_srcImplements_end_ = ComponentImplementation::meta_dstImplements_rev = ComponentType::meta_srcImplements;
			ComponentImplementation::meta_dstImplements = Uml::AssociationRole::Create(ass);
			ComponentImplementation::meta_dstImplements.name() = "dstImplements";
			ComponentImplementation::meta_dstImplements.min() = 0;
			ComponentImplementation::meta_dstImplements.max() = -1;
			ComponentImplementation::meta_dstImplements.isNavigable() = true;
			ComponentImplementation::meta_dstImplements.isPrimary() = false;
			ComponentImplementation::meta_dstImplements.target() = ComponentType::meta;
			Implements::meta_dstImplements_end_ = ComponentType::meta_srcImplements_rev = ComponentImplementation::meta_dstImplements;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageInterface";
			ass.assocClass() = PackageInterface::meta;
			ComponentType::meta_srcPackageInterface = Uml::AssociationRole::Create(ass);
			ComponentType::meta_srcPackageInterface.name() = "srcPackageInterface";
			ComponentType::meta_srcPackageInterface.min() = 1;
			ComponentType::meta_srcPackageInterface.max() = 1;
			ComponentType::meta_srcPackageInterface.isNavigable() = true;
			ComponentType::meta_srcPackageInterface.isPrimary() = false;
			ComponentType::meta_srcPackageInterface.target() = ComponentPackage::meta;
			PackageInterface::meta_srcPackageInterface_end_ = ComponentPackage::meta_dstPackageInterface_rev = ComponentType::meta_srcPackageInterface;
			ComponentPackage::meta_dstPackageInterface = Uml::AssociationRole::Create(ass);
			ComponentPackage::meta_dstPackageInterface.name() = "dstPackageInterface";
			ComponentPackage::meta_dstPackageInterface.min() = 1;
			ComponentPackage::meta_dstPackageInterface.max() = 1;
			ComponentPackage::meta_dstPackageInterface.isNavigable() = true;
			ComponentPackage::meta_dstPackageInterface.isPrimary() = false;
			ComponentPackage::meta_dstPackageInterface.target() = ComponentType::meta;
			PackageInterface::meta_dstPackageInterface_end_ = ComponentType::meta_srcPackageInterface_rev = ComponentPackage::meta_dstPackageInterface;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ImplementationCapability";
			ass.assocClass() = ImplementationCapability::meta;
			Capability::meta_srcImplementationCapability = Uml::AssociationRole::Create(ass);
			Capability::meta_srcImplementationCapability.name() = "srcImplementationCapability";
			Capability::meta_srcImplementationCapability.min() = 0;
			Capability::meta_srcImplementationCapability.max() = -1;
			Capability::meta_srcImplementationCapability.isNavigable() = true;
			Capability::meta_srcImplementationCapability.isPrimary() = false;
			Capability::meta_srcImplementationCapability.target() = ComponentImplementation::meta;
			ImplementationCapability::meta_srcImplementationCapability_end_ = ComponentImplementation::meta_dstImplementationCapability_rev = Capability::meta_srcImplementationCapability;
			ComponentImplementation::meta_dstImplementationCapability = Uml::AssociationRole::Create(ass);
			ComponentImplementation::meta_dstImplementationCapability.name() = "dstImplementationCapability";
			ComponentImplementation::meta_dstImplementationCapability.min() = 0;
			ComponentImplementation::meta_dstImplementationCapability.max() = -1;
			ComponentImplementation::meta_dstImplementationCapability.isNavigable() = true;
			ComponentImplementation::meta_dstImplementationCapability.isPrimary() = false;
			ComponentImplementation::meta_dstImplementationCapability.target() = Capability::meta;
			ImplementationCapability::meta_dstImplementationCapability_end_ = Capability::meta_srcImplementationCapability_rev = ComponentImplementation::meta_dstImplementationCapability;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ImplementationDependsOn";
			ass.assocClass() = ImplementationDependsOn::meta;
			ImplementationDependency::meta_srcImplementationDependsOn = Uml::AssociationRole::Create(ass);
			ImplementationDependency::meta_srcImplementationDependsOn.name() = "srcImplementationDependsOn";
			ImplementationDependency::meta_srcImplementationDependsOn.min() = 0;
			ImplementationDependency::meta_srcImplementationDependsOn.max() = -1;
			ImplementationDependency::meta_srcImplementationDependsOn.isNavigable() = true;
			ImplementationDependency::meta_srcImplementationDependsOn.isPrimary() = false;
			ImplementationDependency::meta_srcImplementationDependsOn.target() = ComponentImplementation::meta;
			ImplementationDependsOn::meta_srcImplementationDependsOn_end_ = ComponentImplementation::meta_dstImplementationDependsOn_rev = ImplementationDependency::meta_srcImplementationDependsOn;
			ComponentImplementation::meta_dstImplementationDependsOn = Uml::AssociationRole::Create(ass);
			ComponentImplementation::meta_dstImplementationDependsOn.name() = "dstImplementationDependsOn";
			ComponentImplementation::meta_dstImplementationDependsOn.min() = 0;
			ComponentImplementation::meta_dstImplementationDependsOn.max() = -1;
			ComponentImplementation::meta_dstImplementationDependsOn.isNavigable() = true;
			ComponentImplementation::meta_dstImplementationDependsOn.isPrimary() = false;
			ComponentImplementation::meta_dstImplementationDependsOn.target() = ImplementationDependency::meta;
			ImplementationDependsOn::meta_dstImplementationDependsOn_end_ = ImplementationDependency::meta_srcImplementationDependsOn_rev = ComponentImplementation::meta_dstImplementationDependsOn;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageImplementations";
			ass.assocClass() = PackageImplementations::meta;
			ComponentImplementationReference::meta_srcPackageImplementations = Uml::AssociationRole::Create(ass);
			ComponentImplementationReference::meta_srcPackageImplementations.name() = "srcPackageImplementations";
			ComponentImplementationReference::meta_srcPackageImplementations.min() = 0;
			ComponentImplementationReference::meta_srcPackageImplementations.max() = -1;
			ComponentImplementationReference::meta_srcPackageImplementations.isNavigable() = true;
			ComponentImplementationReference::meta_srcPackageImplementations.isPrimary() = false;
			ComponentImplementationReference::meta_srcPackageImplementations.target() = ComponentPackage::meta;
			PackageImplementations::meta_srcPackageImplementations_end_ = ComponentPackage::meta_dstPackageImplementations_rev = ComponentImplementationReference::meta_srcPackageImplementations;
			ComponentPackage::meta_dstPackageImplementations = Uml::AssociationRole::Create(ass);
			ComponentPackage::meta_dstPackageImplementations.name() = "dstPackageImplementations";
			ComponentPackage::meta_dstPackageImplementations.min() = 1;
			ComponentPackage::meta_dstPackageImplementations.max() = -1;
			ComponentPackage::meta_dstPackageImplementations.isNavigable() = true;
			ComponentPackage::meta_dstPackageImplementations.isPrimary() = false;
			ComponentPackage::meta_dstPackageImplementations.target() = ComponentImplementationReference::meta;
			PackageImplementations::meta_dstPackageImplementations_end_ = ComponentImplementationReference::meta_srcPackageImplementations_rev = ComponentPackage::meta_dstPackageImplementations;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ComponentImplementationReference::meta_ref = Uml::AssociationRole::Create(ass);
			ComponentImplementationReference::meta_ref.name() = "ref";
			ComponentImplementationReference::meta_ref.min() = 0;
			ComponentImplementationReference::meta_ref.max() = 1;
			ComponentImplementationReference::meta_ref.isNavigable() = true;
			ComponentImplementationReference::meta_ref.isPrimary() = false;
			ComponentImplementationReference::meta_ref.target() = ComponentImplementation::meta;
			ComponentImplementation::meta_referedbyComponentImplementationReference = Uml::AssociationRole::Create(ass);
			ComponentImplementation::meta_referedbyComponentImplementationReference.name() = "referedbyComponentImplementationReference";
			ComponentImplementation::meta_referedbyComponentImplementationReference.min() = 0;
			ComponentImplementation::meta_referedbyComponentImplementationReference.max() = -1;
			ComponentImplementation::meta_referedbyComponentImplementationReference.isNavigable() = true;
			ComponentImplementation::meta_referedbyComponentImplementationReference.isPrimary() = false;
			ComponentImplementation::meta_referedbyComponentImplementationReference.target() = ComponentImplementationReference::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ConfigProperty";
			ass.assocClass() = ConfigProperty::meta;
			Property::meta_srcConfigProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcConfigProperty.name() = "srcConfigProperty";
			Property::meta_srcConfigProperty.min() = 0;
			Property::meta_srcConfigProperty.max() = -1;
			Property::meta_srcConfigProperty.isNavigable() = true;
			Property::meta_srcConfigProperty.isPrimary() = false;
			Property::meta_srcConfigProperty.target() = ComponentImplementation::meta;
			ConfigProperty::meta_srcConfigProperty_end_ = ComponentImplementation::meta_dstConfigProperty_rev = Property::meta_srcConfigProperty;
			ComponentImplementation::meta_dstConfigProperty = Uml::AssociationRole::Create(ass);
			ComponentImplementation::meta_dstConfigProperty.name() = "dstConfigProperty";
			ComponentImplementation::meta_dstConfigProperty.min() = 0;
			ComponentImplementation::meta_dstConfigProperty.max() = -1;
			ComponentImplementation::meta_dstConfigProperty.isNavigable() = true;
			ComponentImplementation::meta_dstConfigProperty.isPrimary() = false;
			ComponentImplementation::meta_dstConfigProperty.target() = Property::meta;
			ConfigProperty::meta_dstConfigProperty_end_ = Property::meta_srcConfigProperty_rev = ComponentImplementation::meta_dstConfigProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "InfoProperty";
			ass.assocClass() = InfoProperty::meta;
			Property::meta_srcInfoProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcInfoProperty.name() = "srcInfoProperty";
			Property::meta_srcInfoProperty.min() = 0;
			Property::meta_srcInfoProperty.max() = -1;
			Property::meta_srcInfoProperty.isNavigable() = true;
			Property::meta_srcInfoProperty.isPrimary() = false;
			Property::meta_srcInfoProperty.target() = ComponentImplementation::meta;
			InfoProperty::meta_srcInfoProperty_end_ = ComponentImplementation::meta_dstInfoProperty_rev = Property::meta_srcInfoProperty;
			ComponentImplementation::meta_dstInfoProperty = Uml::AssociationRole::Create(ass);
			ComponentImplementation::meta_dstInfoProperty.name() = "dstInfoProperty";
			ComponentImplementation::meta_dstInfoProperty.min() = 0;
			ComponentImplementation::meta_dstInfoProperty.max() = -1;
			ComponentImplementation::meta_dstInfoProperty.isNavigable() = true;
			ComponentImplementation::meta_dstInfoProperty.isPrimary() = false;
			ComponentImplementation::meta_dstInfoProperty.target() = Property::meta;
			InfoProperty::meta_dstInfoProperty_end_ = Property::meta_srcInfoProperty_rev = ComponentImplementation::meta_dstInfoProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "MonolithDeployRequirement";
			ass.assocClass() = MonolithDeployRequirement::meta;
			ImplementationRequirement::meta_srcMonolithDeployRequirement = Uml::AssociationRole::Create(ass);
			ImplementationRequirement::meta_srcMonolithDeployRequirement.name() = "srcMonolithDeployRequirement";
			ImplementationRequirement::meta_srcMonolithDeployRequirement.min() = 0;
			ImplementationRequirement::meta_srcMonolithDeployRequirement.max() = -1;
			ImplementationRequirement::meta_srcMonolithDeployRequirement.isNavigable() = true;
			ImplementationRequirement::meta_srcMonolithDeployRequirement.isPrimary() = false;
			ImplementationRequirement::meta_srcMonolithDeployRequirement.target() = MonolithicImplementation::meta;
			MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_ = MonolithicImplementation::meta_dstMonolithDeployRequirement_rev = ImplementationRequirement::meta_srcMonolithDeployRequirement;
			MonolithicImplementation::meta_dstMonolithDeployRequirement = Uml::AssociationRole::Create(ass);
			MonolithicImplementation::meta_dstMonolithDeployRequirement.name() = "dstMonolithDeployRequirement";
			MonolithicImplementation::meta_dstMonolithDeployRequirement.min() = 0;
			MonolithicImplementation::meta_dstMonolithDeployRequirement.max() = -1;
			MonolithicImplementation::meta_dstMonolithDeployRequirement.isNavigable() = true;
			MonolithicImplementation::meta_dstMonolithDeployRequirement.isPrimary() = false;
			MonolithicImplementation::meta_dstMonolithDeployRequirement.target() = ImplementationRequirement::meta;
			MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_ = ImplementationRequirement::meta_srcMonolithDeployRequirement_rev = MonolithicImplementation::meta_dstMonolithDeployRequirement;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "MonolithExecParameter";
			ass.assocClass() = MonolithExecParameter::meta;
			Property::meta_srcMonolithExecParameter = Uml::AssociationRole::Create(ass);
			Property::meta_srcMonolithExecParameter.name() = "srcMonolithExecParameter";
			Property::meta_srcMonolithExecParameter.min() = 0;
			Property::meta_srcMonolithExecParameter.max() = -1;
			Property::meta_srcMonolithExecParameter.isNavigable() = true;
			Property::meta_srcMonolithExecParameter.isPrimary() = false;
			Property::meta_srcMonolithExecParameter.target() = MonolithicImplementation::meta;
			MonolithExecParameter::meta_srcMonolithExecParameter_end_ = MonolithicImplementation::meta_dstMonolithExecParameter_rev = Property::meta_srcMonolithExecParameter;
			MonolithicImplementation::meta_dstMonolithExecParameter = Uml::AssociationRole::Create(ass);
			MonolithicImplementation::meta_dstMonolithExecParameter.name() = "dstMonolithExecParameter";
			MonolithicImplementation::meta_dstMonolithExecParameter.min() = 0;
			MonolithicImplementation::meta_dstMonolithExecParameter.max() = -1;
			MonolithicImplementation::meta_dstMonolithExecParameter.isNavigable() = true;
			MonolithicImplementation::meta_dstMonolithExecParameter.isPrimary() = false;
			MonolithicImplementation::meta_dstMonolithExecParameter.target() = Property::meta;
			MonolithExecParameter::meta_dstMonolithExecParameter_end_ = Property::meta_srcMonolithExecParameter_rev = MonolithicImplementation::meta_dstMonolithExecParameter;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageSelectRequirement";
			ass.assocClass() = PackageSelectRequirement::meta;
			Requirement::meta_srcPackageSelectRequirement = Uml::AssociationRole::Create(ass);
			Requirement::meta_srcPackageSelectRequirement.name() = "srcPackageSelectRequirement";
			Requirement::meta_srcPackageSelectRequirement.min() = 0;
			Requirement::meta_srcPackageSelectRequirement.max() = -1;
			Requirement::meta_srcPackageSelectRequirement.isNavigable() = true;
			Requirement::meta_srcPackageSelectRequirement.isPrimary() = false;
			Requirement::meta_srcPackageSelectRequirement.target() = PackageConfiguration::meta;
			PackageSelectRequirement::meta_srcPackageSelectRequirement_end_ = PackageConfiguration::meta_dstPackageSelectRequirement_rev = Requirement::meta_srcPackageSelectRequirement;
			PackageConfiguration::meta_dstPackageSelectRequirement = Uml::AssociationRole::Create(ass);
			PackageConfiguration::meta_dstPackageSelectRequirement.name() = "dstPackageSelectRequirement";
			PackageConfiguration::meta_dstPackageSelectRequirement.min() = 0;
			PackageConfiguration::meta_dstPackageSelectRequirement.max() = -1;
			PackageConfiguration::meta_dstPackageSelectRequirement.isNavigable() = true;
			PackageConfiguration::meta_dstPackageSelectRequirement.isPrimary() = false;
			PackageConfiguration::meta_dstPackageSelectRequirement.target() = Requirement::meta;
			PackageSelectRequirement::meta_dstPackageSelectRequirement_end_ = Requirement::meta_srcPackageSelectRequirement_rev = PackageConfiguration::meta_dstPackageSelectRequirement;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "ConnectionRequirements";
			ass.assocClass() = ConnectionRequirements::meta;
			Requirement::meta_srcConnectionRequirements = Uml::AssociationRole::Create(ass);
			Requirement::meta_srcConnectionRequirements.name() = "srcConnectionRequirements";
			Requirement::meta_srcConnectionRequirements.min() = 0;
			Requirement::meta_srcConnectionRequirements.max() = -1;
			Requirement::meta_srcConnectionRequirements.isNavigable() = true;
			Requirement::meta_srcConnectionRequirements.isPrimary() = false;
			Requirement::meta_srcConnectionRequirements.target() = PublishConnector::meta;
			ConnectionRequirements::meta_srcConnectionRequirements_end_ = PublishConnector::meta_dstConnectionRequirements_rev = Requirement::meta_srcConnectionRequirements;
			PublishConnector::meta_dstConnectionRequirements = Uml::AssociationRole::Create(ass);
			PublishConnector::meta_dstConnectionRequirements.name() = "dstConnectionRequirements";
			PublishConnector::meta_dstConnectionRequirements.min() = 0;
			PublishConnector::meta_dstConnectionRequirements.max() = -1;
			PublishConnector::meta_dstConnectionRequirements.isNavigable() = true;
			PublishConnector::meta_dstConnectionRequirements.isPrimary() = false;
			PublishConnector::meta_dstConnectionRequirements.target() = Requirement::meta;
			ConnectionRequirements::meta_dstConnectionRequirements_end_ = Requirement::meta_srcConnectionRequirements_rev = PublishConnector::meta_dstConnectionRequirements;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "SubComponentSelectRequirement";
			ass.assocClass() = SubComponentSelectRequirement::meta;
			Requirement::meta_srcSubComponentSelectRequirement = Uml::AssociationRole::Create(ass);
			Requirement::meta_srcSubComponentSelectRequirement.name() = "srcSubComponentSelectRequirement";
			Requirement::meta_srcSubComponentSelectRequirement.min() = 0;
			Requirement::meta_srcSubComponentSelectRequirement.max() = -1;
			Requirement::meta_srcSubComponentSelectRequirement.isNavigable() = true;
			Requirement::meta_srcSubComponentSelectRequirement.isPrimary() = false;
			Requirement::meta_srcSubComponentSelectRequirement.target() = ComponentDef::meta;
			SubComponentSelectRequirement::meta_srcSubComponentSelectRequirement_end_ = ComponentDef::meta_dstSubComponentSelectRequirement_rev = Requirement::meta_srcSubComponentSelectRequirement;
			ComponentDef::meta_dstSubComponentSelectRequirement = Uml::AssociationRole::Create(ass);
			ComponentDef::meta_dstSubComponentSelectRequirement.name() = "dstSubComponentSelectRequirement";
			ComponentDef::meta_dstSubComponentSelectRequirement.min() = 0;
			ComponentDef::meta_dstSubComponentSelectRequirement.max() = -1;
			ComponentDef::meta_dstSubComponentSelectRequirement.isNavigable() = true;
			ComponentDef::meta_dstSubComponentSelectRequirement.isPrimary() = false;
			ComponentDef::meta_dstSubComponentSelectRequirement.target() = Requirement::meta;
			SubComponentSelectRequirement::meta_dstSubComponentSelectRequirement_end_ = Requirement::meta_srcSubComponentSelectRequirement_rev = ComponentDef::meta_dstSubComponentSelectRequirement;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageConfigurationProperty";
			ass.assocClass() = PackageConfigurationProperty::meta;
			Property::meta_srcPackageConfigurationProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcPackageConfigurationProperty.name() = "srcPackageConfigurationProperty";
			Property::meta_srcPackageConfigurationProperty.min() = 0;
			Property::meta_srcPackageConfigurationProperty.max() = -1;
			Property::meta_srcPackageConfigurationProperty.isNavigable() = true;
			Property::meta_srcPackageConfigurationProperty.isPrimary() = false;
			Property::meta_srcPackageConfigurationProperty.target() = PackageConfiguration::meta;
			PackageConfigurationProperty::meta_srcPackageConfigurationProperty_end_ = PackageConfiguration::meta_dstPackageConfigurationProperty_rev = Property::meta_srcPackageConfigurationProperty;
			PackageConfiguration::meta_dstPackageConfigurationProperty = Uml::AssociationRole::Create(ass);
			PackageConfiguration::meta_dstPackageConfigurationProperty.name() = "dstPackageConfigurationProperty";
			PackageConfiguration::meta_dstPackageConfigurationProperty.min() = 0;
			PackageConfiguration::meta_dstPackageConfigurationProperty.max() = -1;
			PackageConfiguration::meta_dstPackageConfigurationProperty.isNavigable() = true;
			PackageConfiguration::meta_dstPackageConfigurationProperty.isPrimary() = false;
			PackageConfiguration::meta_dstPackageConfigurationProperty.target() = Property::meta;
			PackageConfigurationProperty::meta_dstPackageConfigurationProperty_end_ = Property::meta_srcPackageConfigurationProperty_rev = PackageConfiguration::meta_dstPackageConfigurationProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageConfigProperty";
			ass.assocClass() = PackageConfigProperty::meta;
			Property::meta_srcPackageConfigProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcPackageConfigProperty.name() = "srcPackageConfigProperty";
			Property::meta_srcPackageConfigProperty.min() = 0;
			Property::meta_srcPackageConfigProperty.max() = -1;
			Property::meta_srcPackageConfigProperty.isNavigable() = true;
			Property::meta_srcPackageConfigProperty.isPrimary() = false;
			Property::meta_srcPackageConfigProperty.target() = ComponentPackage::meta;
			PackageConfigProperty::meta_srcPackageConfigProperty_end_ = ComponentPackage::meta_dstPackageConfigProperty_rev = Property::meta_srcPackageConfigProperty;
			ComponentPackage::meta_dstPackageConfigProperty = Uml::AssociationRole::Create(ass);
			ComponentPackage::meta_dstPackageConfigProperty.name() = "dstPackageConfigProperty";
			ComponentPackage::meta_dstPackageConfigProperty.min() = 0;
			ComponentPackage::meta_dstPackageConfigProperty.max() = -1;
			ComponentPackage::meta_dstPackageConfigProperty.isNavigable() = true;
			ComponentPackage::meta_dstPackageConfigProperty.isPrimary() = false;
			ComponentPackage::meta_dstPackageConfigProperty.target() = Property::meta;
			PackageConfigProperty::meta_dstPackageConfigProperty_end_ = Property::meta_srcPackageConfigProperty_rev = ComponentPackage::meta_dstPackageConfigProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageInfoProperty";
			ass.assocClass() = PackageInfoProperty::meta;
			Property::meta_srcPackageInfoProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcPackageInfoProperty.name() = "srcPackageInfoProperty";
			Property::meta_srcPackageInfoProperty.min() = 0;
			Property::meta_srcPackageInfoProperty.max() = -1;
			Property::meta_srcPackageInfoProperty.isNavigable() = true;
			Property::meta_srcPackageInfoProperty.isPrimary() = false;
			Property::meta_srcPackageInfoProperty.target() = ComponentPackage::meta;
			PackageInfoProperty::meta_srcPackageInfoProperty_end_ = ComponentPackage::meta_dstPackageInfoProperty_rev = Property::meta_srcPackageInfoProperty;
			ComponentPackage::meta_dstPackageInfoProperty = Uml::AssociationRole::Create(ass);
			ComponentPackage::meta_dstPackageInfoProperty.name() = "dstPackageInfoProperty";
			ComponentPackage::meta_dstPackageInfoProperty.min() = 0;
			ComponentPackage::meta_dstPackageInfoProperty.max() = -1;
			ComponentPackage::meta_dstPackageInfoProperty.isNavigable() = true;
			ComponentPackage::meta_dstPackageInfoProperty.isPrimary() = false;
			ComponentPackage::meta_dstPackageInfoProperty.target() = Property::meta;
			PackageInfoProperty::meta_dstPackageInfoProperty_end_ = Property::meta_srcPackageInfoProperty_rev = ComponentPackage::meta_dstPackageInfoProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "SubComponentConfigProperty";
			ass.assocClass() = SubComponentConfigProperty::meta;
			Property::meta_srcSubComponentConfigProperty = Uml::AssociationRole::Create(ass);
			Property::meta_srcSubComponentConfigProperty.name() = "srcSubComponentConfigProperty";
			Property::meta_srcSubComponentConfigProperty.min() = 0;
			Property::meta_srcSubComponentConfigProperty.max() = -1;
			Property::meta_srcSubComponentConfigProperty.isNavigable() = true;
			Property::meta_srcSubComponentConfigProperty.isPrimary() = false;
			Property::meta_srcSubComponentConfigProperty.target() = ComponentDef::meta;
			SubComponentConfigProperty::meta_srcSubComponentConfigProperty_end_ = ComponentDef::meta_dstSubComponentConfigProperty_rev = Property::meta_srcSubComponentConfigProperty;
			ComponentDef::meta_dstSubComponentConfigProperty = Uml::AssociationRole::Create(ass);
			ComponentDef::meta_dstSubComponentConfigProperty.name() = "dstSubComponentConfigProperty";
			ComponentDef::meta_dstSubComponentConfigProperty.min() = 0;
			ComponentDef::meta_dstSubComponentConfigProperty.max() = -1;
			ComponentDef::meta_dstSubComponentConfigProperty.isNavigable() = true;
			ComponentDef::meta_dstSubComponentConfigProperty.isPrimary() = false;
			ComponentDef::meta_dstSubComponentConfigProperty.target() = Property::meta;
			SubComponentConfigProperty::meta_dstSubComponentConfigProperty_end_ = Property::meta_srcSubComponentConfigProperty_rev = ComponentDef::meta_dstSubComponentConfigProperty;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageBaseConnection";
			ass.assocClass() = PackageBaseConnection::meta;
			ComponentPackage::meta_srcPackageBaseConnection = Uml::AssociationRole::Create(ass);
			ComponentPackage::meta_srcPackageBaseConnection.name() = "srcPackageBaseConnection";
			ComponentPackage::meta_srcPackageBaseConnection.min() = 0;
			ComponentPackage::meta_srcPackageBaseConnection.max() = -1;
			ComponentPackage::meta_srcPackageBaseConnection.isNavigable() = true;
			ComponentPackage::meta_srcPackageBaseConnection.isPrimary() = false;
			ComponentPackage::meta_srcPackageBaseConnection.target() = PackageConfiguration::meta;
			PackageBaseConnection::meta_srcPackageBaseConnection_end_ = PackageConfiguration::meta_dstPackageBaseConnection_rev = ComponentPackage::meta_srcPackageBaseConnection;
			PackageConfiguration::meta_dstPackageBaseConnection = Uml::AssociationRole::Create(ass);
			PackageConfiguration::meta_dstPackageBaseConnection.name() = "dstPackageBaseConnection";
			PackageConfiguration::meta_dstPackageBaseConnection.min() = 0;
			PackageConfiguration::meta_dstPackageBaseConnection.max() = -1;
			PackageConfiguration::meta_dstPackageBaseConnection.isNavigable() = true;
			PackageConfiguration::meta_dstPackageBaseConnection.isPrimary() = false;
			PackageConfiguration::meta_dstPackageBaseConnection.target() = ComponentPackage::meta;
			PackageBaseConnection::meta_dstPackageBaseConnection_end_ = ComponentPackage::meta_srcPackageBaseConnection_rev = PackageConfiguration::meta_dstPackageBaseConnection;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "PackageReferenceConnection";
			ass.assocClass() = PackageReferenceConnection::meta;
			ComponentPackageReference::meta_srcPackageReferenceConnection = Uml::AssociationRole::Create(ass);
			ComponentPackageReference::meta_srcPackageReferenceConnection.name() = "srcPackageReferenceConnection";
			ComponentPackageReference::meta_srcPackageReferenceConnection.min() = 0;
			ComponentPackageReference::meta_srcPackageReferenceConnection.max() = -1;
			ComponentPackageReference::meta_srcPackageReferenceConnection.isNavigable() = true;
			ComponentPackageReference::meta_srcPackageReferenceConnection.isPrimary() = false;
			ComponentPackageReference::meta_srcPackageReferenceConnection.target() = PackageConfiguration::meta;
			PackageReferenceConnection::meta_srcPackageReferenceConnection_end_ = PackageConfiguration::meta_dstPackageReferenceConnection_rev = ComponentPackageReference::meta_srcPackageReferenceConnection;
			PackageConfiguration::meta_dstPackageReferenceConnection = Uml::AssociationRole::Create(ass);
			PackageConfiguration::meta_dstPackageReferenceConnection.name() = "dstPackageReferenceConnection";
			PackageConfiguration::meta_dstPackageReferenceConnection.min() = 0;
			PackageConfiguration::meta_dstPackageReferenceConnection.max() = -1;
			PackageConfiguration::meta_dstPackageReferenceConnection.isNavigable() = true;
			PackageConfiguration::meta_dstPackageReferenceConnection.isPrimary() = false;
			PackageConfiguration::meta_dstPackageReferenceConnection.target() = ComponentPackageReference::meta;
			PackageReferenceConnection::meta_dstPackageReferenceConnection_end_ = ComponentPackageReference::meta_srcPackageReferenceConnection_rev = PackageConfiguration::meta_dstPackageReferenceConnection;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "TopLevelPackageConn";
			ass.assocClass() = TopLevelPackageConn::meta;
			PackageConfigurationReference::meta_srcTopLevelPackageConn = Uml::AssociationRole::Create(ass);
			PackageConfigurationReference::meta_srcTopLevelPackageConn.name() = "srcTopLevelPackageConn";
			PackageConfigurationReference::meta_srcTopLevelPackageConn.min() = 1;
			PackageConfigurationReference::meta_srcTopLevelPackageConn.max() = 1;
			PackageConfigurationReference::meta_srcTopLevelPackageConn.isNavigable() = true;
			PackageConfigurationReference::meta_srcTopLevelPackageConn.isPrimary() = false;
			PackageConfigurationReference::meta_srcTopLevelPackageConn.target() = TopLevelPackage::meta;
			TopLevelPackageConn::meta_srcTopLevelPackageConn_end_ = TopLevelPackage::meta_dstTopLevelPackageConn_rev = PackageConfigurationReference::meta_srcTopLevelPackageConn;
			TopLevelPackage::meta_dstTopLevelPackageConn = Uml::AssociationRole::Create(ass);
			TopLevelPackage::meta_dstTopLevelPackageConn.name() = "dstTopLevelPackageConn";
			TopLevelPackage::meta_dstTopLevelPackageConn.min() = 1;
			TopLevelPackage::meta_dstTopLevelPackageConn.max() = 1;
			TopLevelPackage::meta_dstTopLevelPackageConn.isNavigable() = true;
			TopLevelPackage::meta_dstTopLevelPackageConn.isPrimary() = false;
			TopLevelPackage::meta_dstTopLevelPackageConn.target() = PackageConfigurationReference::meta;
			TopLevelPackageConn::meta_dstTopLevelPackageConn_end_ = PackageConfigurationReference::meta_srcTopLevelPackageConn_rev = TopLevelPackage::meta_dstTopLevelPackageConn;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			PackageConfigurationReference::meta_ref = Uml::AssociationRole::Create(ass);
			PackageConfigurationReference::meta_ref.name() = "ref";
			PackageConfigurationReference::meta_ref.min() = 0;
			PackageConfigurationReference::meta_ref.max() = 1;
			PackageConfigurationReference::meta_ref.isNavigable() = true;
			PackageConfigurationReference::meta_ref.isPrimary() = false;
			PackageConfigurationReference::meta_ref.target() = PackageConfiguration::meta;
			PackageConfiguration::meta_referedbyPackageConfigurationReference = Uml::AssociationRole::Create(ass);
			PackageConfiguration::meta_referedbyPackageConfigurationReference.name() = "referedbyPackageConfigurationReference";
			PackageConfiguration::meta_referedbyPackageConfigurationReference.min() = 0;
			PackageConfiguration::meta_referedbyPackageConfigurationReference.max() = -1;
			PackageConfiguration::meta_referedbyPackageConfigurationReference.isNavigable() = true;
			PackageConfiguration::meta_referedbyPackageConfigurationReference.isPrimary() = false;
			PackageConfiguration::meta_referedbyPackageConfigurationReference.target() = PackageConfigurationReference::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "EmitConnector";
			ass.assocClass() = EmitConnector::meta;
			InEventPort::meta_srcEmitConnector = Uml::AssociationRole::Create(ass);
			InEventPort::meta_srcEmitConnector.name() = "srcEmitConnector";
			InEventPort::meta_srcEmitConnector.min() = 0;
			InEventPort::meta_srcEmitConnector.max() = 1;
			InEventPort::meta_srcEmitConnector.isNavigable() = true;
			InEventPort::meta_srcEmitConnector.isPrimary() = false;
			InEventPort::meta_srcEmitConnector.target() = OutEventPort::meta;
			EmitConnector::meta_srcEmitConnector_end_ = OutEventPort::meta_dstEmitConnector_rev = InEventPort::meta_srcEmitConnector;
			OutEventPort::meta_dstEmitConnector = Uml::AssociationRole::Create(ass);
			OutEventPort::meta_dstEmitConnector.name() = "dstEmitConnector";
			OutEventPort::meta_dstEmitConnector.min() = 0;
			OutEventPort::meta_dstEmitConnector.max() = 1;
			OutEventPort::meta_dstEmitConnector.isNavigable() = true;
			OutEventPort::meta_dstEmitConnector.isPrimary() = false;
			OutEventPort::meta_dstEmitConnector.target() = InEventPort::meta;
			EmitConnector::meta_dstEmitConnector_end_ = InEventPort::meta_srcEmitConnector_rev = OutEventPort::meta_dstEmitConnector;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "Invocation";
			ass.assocClass() = Invocation::meta;
			ProvidedRequestPort::meta_srcInvocation = Uml::AssociationRole::Create(ass);
			ProvidedRequestPort::meta_srcInvocation.name() = "srcInvocation";
			ProvidedRequestPort::meta_srcInvocation.min() = 0;
			ProvidedRequestPort::meta_srcInvocation.max() = -1;
			ProvidedRequestPort::meta_srcInvocation.isNavigable() = true;
			ProvidedRequestPort::meta_srcInvocation.isPrimary() = false;
			ProvidedRequestPort::meta_srcInvocation.target() = RequiredRequestPort::meta;
			Invocation::meta_srcInvocation_end_ = RequiredRequestPort::meta_dstInvocation_rev = ProvidedRequestPort::meta_srcInvocation;
			RequiredRequestPort::meta_dstInvocation = Uml::AssociationRole::Create(ass);
			RequiredRequestPort::meta_dstInvocation.name() = "dstInvocation";
			RequiredRequestPort::meta_dstInvocation.min() = 0;
			RequiredRequestPort::meta_dstInvocation.max() = -1;
			RequiredRequestPort::meta_dstInvocation.isNavigable() = true;
			RequiredRequestPort::meta_dstInvocation.isPrimary() = false;
			RequiredRequestPort::meta_dstInvocation.target() = ProvidedRequestPort::meta;
			Invocation::meta_dstInvocation_end_ = ProvidedRequestPort::meta_srcInvocation_rev = RequiredRequestPort::meta_dstInvocation;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "InEventPortConsume";
			ass.assocClass() = InEventPortConsume::meta;
			PublishConnector::meta_dstInEventPortConsume = Uml::AssociationRole::Create(ass);
			PublishConnector::meta_dstInEventPortConsume.name() = "dstInEventPortConsume";
			PublishConnector::meta_dstInEventPortConsume.min() = 0;
			PublishConnector::meta_dstInEventPortConsume.max() = -1;
			PublishConnector::meta_dstInEventPortConsume.isNavigable() = true;
			PublishConnector::meta_dstInEventPortConsume.isPrimary() = false;
			PublishConnector::meta_dstInEventPortConsume.target() = InEventPort::meta;
			InEventPortConsume::meta_dstInEventPortConsume_end_ = InEventPort::meta_srcInEventPortConsume_rev = PublishConnector::meta_dstInEventPortConsume;
			InEventPort::meta_srcInEventPortConsume = Uml::AssociationRole::Create(ass);
			InEventPort::meta_srcInEventPortConsume.name() = "srcInEventPortConsume";
			InEventPort::meta_srcInEventPortConsume.min() = 0;
			InEventPort::meta_srcInEventPortConsume.max() = -1;
			InEventPort::meta_srcInEventPortConsume.isNavigable() = true;
			InEventPort::meta_srcInEventPortConsume.isPrimary() = false;
			InEventPort::meta_srcInEventPortConsume.target() = PublishConnector::meta;
			InEventPortConsume::meta_srcInEventPortConsume_end_ = PublishConnector::meta_dstInEventPortConsume_rev = InEventPort::meta_srcInEventPortConsume;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "OutEventPortPublish";
			ass.assocClass() = OutEventPortPublish::meta;
			PublishConnector::meta_srcOutEventPortPublish = Uml::AssociationRole::Create(ass);
			PublishConnector::meta_srcOutEventPortPublish.name() = "srcOutEventPortPublish";
			PublishConnector::meta_srcOutEventPortPublish.min() = 0;
			PublishConnector::meta_srcOutEventPortPublish.max() = -1;
			PublishConnector::meta_srcOutEventPortPublish.isNavigable() = true;
			PublishConnector::meta_srcOutEventPortPublish.isPrimary() = false;
			PublishConnector::meta_srcOutEventPortPublish.target() = OutEventPort::meta;
			OutEventPortPublish::meta_srcOutEventPortPublish_end_ = OutEventPort::meta_dstOutEventPortPublish_rev = PublishConnector::meta_srcOutEventPortPublish;
			OutEventPort::meta_dstOutEventPortPublish = Uml::AssociationRole::Create(ass);
			OutEventPort::meta_dstOutEventPortPublish.name() = "dstOutEventPortPublish";
			OutEventPort::meta_dstOutEventPortPublish.min() = 0;
			OutEventPort::meta_dstOutEventPortPublish.max() = -1;
			OutEventPort::meta_dstOutEventPortPublish.isNavigable() = true;
			OutEventPort::meta_dstOutEventPortPublish.isPrimary() = false;
			OutEventPort::meta_dstOutEventPortPublish.target() = PublishConnector::meta;
			OutEventPortPublish::meta_dstOutEventPortPublish_end_ = PublishConnector::meta_srcOutEventPortPublish_rev = OutEventPort::meta_dstOutEventPortPublish;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ComponentPackage::meta_referedbyComponentPackageReference = Uml::AssociationRole::Create(ass);
			ComponentPackage::meta_referedbyComponentPackageReference.name() = "referedbyComponentPackageReference";
			ComponentPackage::meta_referedbyComponentPackageReference.min() = 0;
			ComponentPackage::meta_referedbyComponentPackageReference.max() = -1;
			ComponentPackage::meta_referedbyComponentPackageReference.isNavigable() = true;
			ComponentPackage::meta_referedbyComponentPackageReference.isPrimary() = false;
			ComponentPackage::meta_referedbyComponentPackageReference.target() = ComponentPackageReference::meta;
			ComponentPackageReference::meta_ref = Uml::AssociationRole::Create(ass);
			ComponentPackageReference::meta_ref.name() = "ref";
			ComponentPackageReference::meta_ref.min() = 0;
			ComponentPackageReference::meta_ref.max() = 1;
			ComponentPackageReference::meta_ref.isNavigable() = true;
			ComponentPackageReference::meta_ref.isPrimary() = false;
			ComponentPackageReference::meta_ref.target() = ComponentPackage::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			EnumerationDef::meta_referedbyEnumRef = Uml::AssociationRole::Create(ass);
			EnumerationDef::meta_referedbyEnumRef.name() = "referedbyEnumRef";
			EnumerationDef::meta_referedbyEnumRef.min() = 0;
			EnumerationDef::meta_referedbyEnumRef.max() = -1;
			EnumerationDef::meta_referedbyEnumRef.isNavigable() = true;
			EnumerationDef::meta_referedbyEnumRef.isPrimary() = false;
			EnumerationDef::meta_referedbyEnumRef.target() = EnumRef::meta;
			EnumRef::meta_ref = Uml::AssociationRole::Create(ass);
			EnumRef::meta_ref.name() = "ref";
			EnumRef::meta_ref.min() = 0;
			EnumRef::meta_ref.max() = 1;
			EnumRef::meta_ref.isNavigable() = true;
			EnumRef::meta_ref.isPrimary() = false;
			EnumRef::meta_ref.target() = EnumerationDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			NamedType::meta_referedbyNamedTypeRef = Uml::AssociationRole::Create(ass);
			NamedType::meta_referedbyNamedTypeRef.name() = "referedbyNamedTypeRef";
			NamedType::meta_referedbyNamedTypeRef.min() = 0;
			NamedType::meta_referedbyNamedTypeRef.max() = -1;
			NamedType::meta_referedbyNamedTypeRef.isNavigable() = true;
			NamedType::meta_referedbyNamedTypeRef.isPrimary() = false;
			NamedType::meta_referedbyNamedTypeRef.target() = NamedTypeRef::meta;
			NamedTypeRef::meta_ref = Uml::AssociationRole::Create(ass);
			NamedTypeRef::meta_ref.name() = "ref";
			NamedTypeRef::meta_ref.min() = 0;
			NamedTypeRef::meta_ref.max() = 1;
			NamedTypeRef::meta_ref.isNavigable() = true;
			NamedTypeRef::meta_ref.isPrimary() = false;
			NamedTypeRef::meta_ref.target() = NamedType::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "LabelConnection";
			ass.assocClass() = LabelConnection::meta;
			Label::meta_srcLabelConnection = Uml::AssociationRole::Create(ass);
			Label::meta_srcLabelConnection.name() = "srcLabelConnection";
			Label::meta_srcLabelConnection.min() = 1;
			Label::meta_srcLabelConnection.max() = 1;
			Label::meta_srcLabelConnection.isNavigable() = true;
			Label::meta_srcLabelConnection.isPrimary() = false;
			Label::meta_srcLabelConnection.target() = Member::meta;
			LabelConnection::meta_srcLabelConnection_end_ = Member::meta_dstLabelConnection_rev = Label::meta_srcLabelConnection;
			Member::meta_dstLabelConnection = Uml::AssociationRole::Create(ass);
			Member::meta_dstLabelConnection.name() = "dstLabelConnection";
			Member::meta_dstLabelConnection.min() = 0;
			Member::meta_dstLabelConnection.max() = -1;
			Member::meta_dstLabelConnection.isNavigable() = true;
			Member::meta_dstLabelConnection.isPrimary() = false;
			Member::meta_dstLabelConnection.target() = Label::meta;
			LabelConnection::meta_dstLabelConnection_end_ = Label::meta_srcLabelConnection_rev = Member::meta_dstLabelConnection;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "MakeMemberPrivate";
			ass.assocClass() = MakeMemberPrivate::meta;
			Member::meta_dstMakeMemberPrivate = Uml::AssociationRole::Create(ass);
			Member::meta_dstMakeMemberPrivate.name() = "dstMakeMemberPrivate";
			Member::meta_dstMakeMemberPrivate.min() = 0;
			Member::meta_dstMakeMemberPrivate.max() = 1;
			Member::meta_dstMakeMemberPrivate.isNavigable() = true;
			Member::meta_dstMakeMemberPrivate.isPrimary() = false;
			Member::meta_dstMakeMemberPrivate.target() = PrivateFlag::meta;
			MakeMemberPrivate::meta_dstMakeMemberPrivate_end_ = PrivateFlag::meta_srcMakeMemberPrivate_rev = Member::meta_dstMakeMemberPrivate;
			PrivateFlag::meta_srcMakeMemberPrivate = Uml::AssociationRole::Create(ass);
			PrivateFlag::meta_srcMakeMemberPrivate.name() = "srcMakeMemberPrivate";
			PrivateFlag::meta_srcMakeMemberPrivate.min() = 1;
			PrivateFlag::meta_srcMakeMemberPrivate.max() = 1;
			PrivateFlag::meta_srcMakeMemberPrivate.isNavigable() = true;
			PrivateFlag::meta_srcMakeMemberPrivate.isPrimary() = false;
			PrivateFlag::meta_srcMakeMemberPrivate.target() = Member::meta;
			MakeMemberPrivate::meta_srcMakeMemberPrivate_end_ = Member::meta_dstMakeMemberPrivate_rev = PrivateFlag::meta_srcMakeMemberPrivate;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ExceptionDef::meta_referedbyExceptionRef = Uml::AssociationRole::Create(ass);
			ExceptionDef::meta_referedbyExceptionRef.name() = "referedbyExceptionRef";
			ExceptionDef::meta_referedbyExceptionRef.min() = 0;
			ExceptionDef::meta_referedbyExceptionRef.max() = -1;
			ExceptionDef::meta_referedbyExceptionRef.isNavigable() = true;
			ExceptionDef::meta_referedbyExceptionRef.isPrimary() = false;
			ExceptionDef::meta_referedbyExceptionRef.target() = ExceptionRef::meta;
			ExceptionRef::meta_ref = Uml::AssociationRole::Create(ass);
			ExceptionRef::meta_ref.name() = "ref";
			ExceptionRef::meta_ref.min() = 0;
			ExceptionRef::meta_ref.max() = 1;
			ExceptionRef::meta_ref.isNavigable() = true;
			ExceptionRef::meta_ref.isPrimary() = false;
			ExceptionRef::meta_ref.target() = ExceptionDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ExceptionDef::meta_referedbySetException = Uml::AssociationRole::Create(ass);
			ExceptionDef::meta_referedbySetException.name() = "referedbySetException";
			ExceptionDef::meta_referedbySetException.min() = 0;
			ExceptionDef::meta_referedbySetException.max() = -1;
			ExceptionDef::meta_referedbySetException.isNavigable() = true;
			ExceptionDef::meta_referedbySetException.isPrimary() = false;
			ExceptionDef::meta_referedbySetException.target() = SetException::meta;
			SetException::meta_ref = Uml::AssociationRole::Create(ass);
			SetException::meta_ref.name() = "ref";
			SetException::meta_ref.min() = 0;
			SetException::meta_ref.max() = 1;
			SetException::meta_ref.isNavigable() = true;
			SetException::meta_ref.isPrimary() = false;
			SetException::meta_ref.target() = ExceptionDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ExceptionDef::meta_referedbyGetException = Uml::AssociationRole::Create(ass);
			ExceptionDef::meta_referedbyGetException.name() = "referedbyGetException";
			ExceptionDef::meta_referedbyGetException.min() = 0;
			ExceptionDef::meta_referedbyGetException.max() = -1;
			ExceptionDef::meta_referedbyGetException.isNavigable() = true;
			ExceptionDef::meta_referedbyGetException.isPrimary() = false;
			ExceptionDef::meta_referedbyGetException.target() = GetException::meta;
			GetException::meta_ref = Uml::AssociationRole::Create(ass);
			GetException::meta_ref.name() = "ref";
			GetException::meta_ref.min() = 0;
			GetException::meta_ref.max() = 1;
			GetException::meta_ref.isNavigable() = true;
			GetException::meta_ref.isPrimary() = false;
			GetException::meta_ref.target() = ExceptionDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			EventDef::meta_referedbyEventRef = Uml::AssociationRole::Create(ass);
			EventDef::meta_referedbyEventRef.name() = "referedbyEventRef";
			EventDef::meta_referedbyEventRef.min() = 0;
			EventDef::meta_referedbyEventRef.max() = -1;
			EventDef::meta_referedbyEventRef.isNavigable() = true;
			EventDef::meta_referedbyEventRef.isPrimary() = false;
			EventDef::meta_referedbyEventRef.target() = EventRef::meta;
			EventRef::meta_ref = Uml::AssociationRole::Create(ass);
			EventRef::meta_ref.name() = "ref";
			EventRef::meta_ref.min() = 0;
			EventRef::meta_ref.max() = 1;
			EventRef::meta_ref.isNavigable() = true;
			EventRef::meta_ref.isPrimary() = false;
			EventRef::meta_ref.target() = EventDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ObjectDef::meta_referedbyObjectRef = Uml::AssociationRole::Create(ass);
			ObjectDef::meta_referedbyObjectRef.name() = "referedbyObjectRef";
			ObjectDef::meta_referedbyObjectRef.min() = 0;
			ObjectDef::meta_referedbyObjectRef.max() = -1;
			ObjectDef::meta_referedbyObjectRef.isNavigable() = true;
			ObjectDef::meta_referedbyObjectRef.isPrimary() = false;
			ObjectDef::meta_referedbyObjectRef.target() = ObjectRef::meta;
			ObjectRef::meta_ref = Uml::AssociationRole::Create(ass);
			ObjectRef::meta_ref.name() = "ref";
			ObjectRef::meta_ref.min() = 0;
			ObjectRef::meta_ref.max() = 1;
			ObjectRef::meta_ref.isNavigable() = true;
			ObjectRef::meta_ref.isPrimary() = false;
			ObjectRef::meta_ref.target() = ObjectDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ComponentDef::meta_referedbyManages = Uml::AssociationRole::Create(ass);
			ComponentDef::meta_referedbyManages.name() = "referedbyManages";
			ComponentDef::meta_referedbyManages.min() = 0;
			ComponentDef::meta_referedbyManages.max() = -1;
			ComponentDef::meta_referedbyManages.isNavigable() = true;
			ComponentDef::meta_referedbyManages.isPrimary() = false;
			ComponentDef::meta_referedbyManages.target() = Manages::meta;
			Manages::meta_ref = Uml::AssociationRole::Create(ass);
			Manages::meta_ref.name() = "ref";
			Manages::meta_ref.min() = 0;
			Manages::meta_ref.max() = 1;
			Manages::meta_ref.isNavigable() = true;
			Manages::meta_ref.isPrimary() = false;
			Manages::meta_ref.target() = ComponentDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			Inheritable::meta_referedbyInherits = Uml::AssociationRole::Create(ass);
			Inheritable::meta_referedbyInherits.name() = "referedbyInherits";
			Inheritable::meta_referedbyInherits.min() = 0;
			Inheritable::meta_referedbyInherits.max() = -1;
			Inheritable::meta_referedbyInherits.isNavigable() = true;
			Inheritable::meta_referedbyInherits.isPrimary() = false;
			Inheritable::meta_referedbyInherits.target() = Inherits::meta;
			Inherits::meta_ref = Uml::AssociationRole::Create(ass);
			Inherits::meta_ref.name() = "ref";
			Inherits::meta_ref.min() = 0;
			Inherits::meta_ref.max() = 1;
			Inherits::meta_ref.isNavigable() = true;
			Inherits::meta_ref.isPrimary() = false;
			Inherits::meta_ref.target() = Inheritable::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ObjectDef::meta_referedbySupports = Uml::AssociationRole::Create(ass);
			ObjectDef::meta_referedbySupports.name() = "referedbySupports";
			ObjectDef::meta_referedbySupports.min() = 0;
			ObjectDef::meta_referedbySupports.max() = -1;
			ObjectDef::meta_referedbySupports.isNavigable() = true;
			ObjectDef::meta_referedbySupports.isPrimary() = false;
			ObjectDef::meta_referedbySupports.target() = Supports::meta;
			Supports::meta_ref = Uml::AssociationRole::Create(ass);
			Supports::meta_ref.name() = "ref";
			Supports::meta_ref.min() = 0;
			Supports::meta_ref.max() = 1;
			Supports::meta_ref.isNavigable() = true;
			Supports::meta_ref.isPrimary() = false;
			Supports::meta_ref.target() = ObjectDef::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ValueDef::meta_referedbyLookupKey = Uml::AssociationRole::Create(ass);
			ValueDef::meta_referedbyLookupKey.name() = "referedbyLookupKey";
			ValueDef::meta_referedbyLookupKey.min() = 0;
			ValueDef::meta_referedbyLookupKey.max() = -1;
			ValueDef::meta_referedbyLookupKey.isNavigable() = true;
			ValueDef::meta_referedbyLookupKey.isPrimary() = false;
			ValueDef::meta_referedbyLookupKey.target() = LookupKey::meta;
			LookupKey::meta_ref = Uml::AssociationRole::Create(ass);
			LookupKey::meta_ref.name() = "ref";
			LookupKey::meta_ref.min() = 0;
			LookupKey::meta_ref.max() = 1;
			LookupKey::meta_ref.isNavigable() = true;
			LookupKey::meta_ref.isPrimary() = false;
			LookupKey::meta_ref.target() = ValueDef::meta;
		}
		Port::meta_cadenaPort = CadenaScenario2PICMLAssembly::Port_cross_ph_PICML::meta_cadenaPort;
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ImplementationArtifactReference::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			ImplementationArtifactReference::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			ImplementationArtifactReference::meta_ArtifactContainer_parent.isNavigable() = true;
			ImplementationArtifactReference::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_ImplementationArtifactReference_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_ImplementationArtifactReference_children.name() = "ImplementationArtifactReference";
			ArtifactContainer::meta_ImplementationArtifactReference_children.min() = 0;
			ArtifactContainer::meta_ImplementationArtifactReference_children.max() = -1;
			ArtifactContainer::meta_ImplementationArtifactReference_children.isNavigable() = true;
			ArtifactContainer::meta_ImplementationArtifactReference_children.target() = ImplementationArtifactReference::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ArtifactContainer::meta_ImplementationArtifacts_parent = Uml::CompositionParentRole::Create(comp);
			ArtifactContainer::meta_ImplementationArtifacts_parent.name() = "ImplementationArtifacts_parent";
			ArtifactContainer::meta_ImplementationArtifacts_parent.isNavigable() = true;
			ArtifactContainer::meta_ImplementationArtifacts_parent.target() = ImplementationArtifacts::meta;
			ImplementationArtifacts::meta_ArtifactContainer_children = Uml::CompositionChildRole::Create(comp);
			ImplementationArtifacts::meta_ArtifactContainer_children.name() = "ArtifactContainer";
			ImplementationArtifacts::meta_ArtifactContainer_children.min() = 0;
			ImplementationArtifacts::meta_ArtifactContainer_children.max() = -1;
			ImplementationArtifacts::meta_ArtifactContainer_children.isNavigable() = true;
			ImplementationArtifacts::meta_ArtifactContainer_children.target() = ArtifactContainer::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ImplementationArtifacts::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			ImplementationArtifacts::meta_RootFolder_parent.name() = "RootFolder_parent";
			ImplementationArtifacts::meta_RootFolder_parent.isNavigable() = true;
			ImplementationArtifacts::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_ImplementationArtifacts_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_ImplementationArtifacts_children.name() = "ImplementationArtifacts";
			RootFolder::meta_ImplementationArtifacts_children.min() = 0;
			RootFolder::meta_ImplementationArtifacts_children.max() = -1;
			RootFolder::meta_ImplementationArtifacts_children.isNavigable() = true;
			RootFolder::meta_ImplementationArtifacts_children.target() = ImplementationArtifacts::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ArtifactDependsOn::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			ArtifactDependsOn::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			ArtifactDependsOn::meta_ArtifactContainer_parent.isNavigable() = true;
			ArtifactDependsOn::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_ArtifactDependsOn_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_ArtifactDependsOn_children.name() = "ArtifactDependsOn";
			ArtifactContainer::meta_ArtifactDependsOn_children.min() = 0;
			ArtifactContainer::meta_ArtifactDependsOn_children.max() = -1;
			ArtifactContainer::meta_ArtifactDependsOn_children.isNavigable() = true;
			ArtifactContainer::meta_ArtifactDependsOn_children.target() = ArtifactDependsOn::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ArtifactDeployRequirement::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			ArtifactDeployRequirement::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			ArtifactDeployRequirement::meta_ArtifactContainer_parent.isNavigable() = true;
			ArtifactDeployRequirement::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_ArtifactDeployRequirement_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_ArtifactDeployRequirement_children.name() = "ArtifactDeployRequirement";
			ArtifactContainer::meta_ArtifactDeployRequirement_children.min() = 0;
			ArtifactContainer::meta_ArtifactDeployRequirement_children.max() = -1;
			ArtifactContainer::meta_ArtifactDeployRequirement_children.isNavigable() = true;
			ArtifactContainer::meta_ArtifactDeployRequirement_children.target() = ArtifactDeployRequirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Requirement::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			Requirement::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			Requirement::meta_ArtifactContainer_parent.isNavigable() = true;
			Requirement::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_Requirement_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_Requirement_children.name() = "Requirement";
			ArtifactContainer::meta_Requirement_children.min() = 0;
			ArtifactContainer::meta_Requirement_children.max() = -1;
			ArtifactContainer::meta_Requirement_children.isNavigable() = true;
			ArtifactContainer::meta_Requirement_children.target() = Requirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ArtifactExecParameter::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			ArtifactExecParameter::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			ArtifactExecParameter::meta_ArtifactContainer_parent.isNavigable() = true;
			ArtifactExecParameter::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_ArtifactExecParameter_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_ArtifactExecParameter_children.name() = "ArtifactExecParameter";
			ArtifactContainer::meta_ArtifactExecParameter_children.min() = 0;
			ArtifactContainer::meta_ArtifactExecParameter_children.max() = -1;
			ArtifactContainer::meta_ArtifactExecParameter_children.isNavigable() = true;
			ArtifactContainer::meta_ArtifactExecParameter_children.target() = ArtifactExecParameter::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ArtifactInfoProperty::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			ArtifactInfoProperty::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			ArtifactInfoProperty::meta_ArtifactContainer_parent.isNavigable() = true;
			ArtifactInfoProperty::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_ArtifactInfoProperty_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_ArtifactInfoProperty_children.name() = "ArtifactInfoProperty";
			ArtifactContainer::meta_ArtifactInfoProperty_children.min() = 0;
			ArtifactContainer::meta_ArtifactInfoProperty_children.max() = -1;
			ArtifactContainer::meta_ArtifactInfoProperty_children.isNavigable() = true;
			ArtifactContainer::meta_ArtifactInfoProperty_children.target() = ArtifactInfoProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			Property::meta_ArtifactContainer_parent.isNavigable() = true;
			Property::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_Property_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_Property_children.name() = "Property";
			ArtifactContainer::meta_Property_children.min() = 0;
			ArtifactContainer::meta_Property_children.max() = -1;
			ArtifactContainer::meta_Property_children.isNavigable() = true;
			ArtifactContainer::meta_Property_children.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ImplementationArtifact::meta_ArtifactContainer_parent = Uml::CompositionParentRole::Create(comp);
			ImplementationArtifact::meta_ArtifactContainer_parent.name() = "ArtifactContainer_parent";
			ImplementationArtifact::meta_ArtifactContainer_parent.isNavigable() = true;
			ImplementationArtifact::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
			ArtifactContainer::meta_ImplementationArtifact_children = Uml::CompositionChildRole::Create(comp);
			ArtifactContainer::meta_ImplementationArtifact_children.name() = "ImplementationArtifact";
			ArtifactContainer::meta_ImplementationArtifact_children.min() = 1;
			ArtifactContainer::meta_ImplementationArtifact_children.max() = -1;
			ArtifactContainer::meta_ImplementationArtifact_children.isNavigable() = true;
			ArtifactContainer::meta_ImplementationArtifact_children.target() = ImplementationArtifact::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Package::meta_IDLFile_parent = Uml::CompositionParentRole::Create(comp);
			Package::meta_IDLFile_parent.name() = "IDLFile_parent";
			Package::meta_IDLFile_parent.isNavigable() = true;
			Package::meta_IDLFile_parent.target() = IDLFile::meta;
			IDLFile::meta_Package_children = Uml::CompositionChildRole::Create(comp);
			IDLFile::meta_Package_children.name() = "Package";
			IDLFile::meta_Package_children.min() = 0;
			IDLFile::meta_Package_children.max() = -1;
			IDLFile::meta_Package_children.isNavigable() = true;
			IDLFile::meta_Package_children.target() = Package::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ConstantDef::meta_IDLFile_parent = Uml::CompositionParentRole::Create(comp);
			ConstantDef::meta_IDLFile_parent.name() = "IDLFile_parent";
			ConstantDef::meta_IDLFile_parent.isNavigable() = true;
			ConstantDef::meta_IDLFile_parent.target() = IDLFile::meta;
			IDLFile::meta_ConstantDef_children = Uml::CompositionChildRole::Create(comp);
			IDLFile::meta_ConstantDef_children.name() = "ConstantDef";
			IDLFile::meta_ConstantDef_children.min() = 0;
			IDLFile::meta_ConstantDef_children.max() = -1;
			IDLFile::meta_ConstantDef_children.isNavigable() = true;
			IDLFile::meta_ConstantDef_children.target() = ConstantDef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ExceptionDef::meta_IDLFile_parent = Uml::CompositionParentRole::Create(comp);
			ExceptionDef::meta_IDLFile_parent.name() = "IDLFile_parent";
			ExceptionDef::meta_IDLFile_parent.isNavigable() = true;
			ExceptionDef::meta_IDLFile_parent.target() = IDLFile::meta;
			IDLFile::meta_ExceptionDef_children = Uml::CompositionChildRole::Create(comp);
			IDLFile::meta_ExceptionDef_children.name() = "ExceptionDef";
			IDLFile::meta_ExceptionDef_children.min() = 0;
			IDLFile::meta_ExceptionDef_children.max() = -1;
			IDLFile::meta_ExceptionDef_children.isNavigable() = true;
			IDLFile::meta_ExceptionDef_children.target() = ExceptionDef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			NamedType::meta_IDLFile_parent = Uml::CompositionParentRole::Create(comp);
			NamedType::meta_IDLFile_parent.name() = "IDLFile_parent";
			NamedType::meta_IDLFile_parent.isNavigable() = true;
			NamedType::meta_IDLFile_parent.target() = IDLFile::meta;
			IDLFile::meta_NamedType_children = Uml::CompositionChildRole::Create(comp);
			IDLFile::meta_NamedType_children.name() = "NamedType";
			IDLFile::meta_NamedType_children.min() = 0;
			IDLFile::meta_NamedType_children.max() = -1;
			IDLFile::meta_NamedType_children.isNavigable() = true;
			IDLFile::meta_NamedType_children.target() = NamedType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			FileRef::meta_IDLFile_parent = Uml::CompositionParentRole::Create(comp);
			FileRef::meta_IDLFile_parent.name() = "IDLFile_parent";
			FileRef::meta_IDLFile_parent.isNavigable() = true;
			FileRef::meta_IDLFile_parent.target() = IDLFile::meta;
			IDLFile::meta_FileRef_children = Uml::CompositionChildRole::Create(comp);
			IDLFile::meta_FileRef_children.name() = "FileRef";
			IDLFile::meta_FileRef_children.min() = 0;
			IDLFile::meta_FileRef_children.max() = -1;
			IDLFile::meta_FileRef_children.isNavigable() = true;
			IDLFile::meta_FileRef_children.target() = FileRef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PrefixTag::meta_Prefixable_parent = Uml::CompositionParentRole::Create(comp);
			PrefixTag::meta_Prefixable_parent.name() = "Prefixable_parent";
			PrefixTag::meta_Prefixable_parent.isNavigable() = true;
			PrefixTag::meta_Prefixable_parent.target() = Prefixable::meta;
			Prefixable::meta_PrefixTag_child = Uml::CompositionChildRole::Create(comp);
			Prefixable::meta_PrefixTag_child.name() = "PrefixTag";
			Prefixable::meta_PrefixTag_child.min() = 0;
			Prefixable::meta_PrefixTag_child.max() = 1;
			Prefixable::meta_PrefixTag_child.isNavigable() = true;
			Prefixable::meta_PrefixTag_child.target() = PrefixTag::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			IDLFile::meta_IDLFiles_parent = Uml::CompositionParentRole::Create(comp);
			IDLFile::meta_IDLFiles_parent.name() = "IDLFiles_parent";
			IDLFile::meta_IDLFiles_parent.isNavigable() = true;
			IDLFile::meta_IDLFiles_parent.target() = IDLFiles::meta;
			IDLFiles::meta_IDLFile_children = Uml::CompositionChildRole::Create(comp);
			IDLFiles::meta_IDLFile_children.name() = "IDLFile";
			IDLFiles::meta_IDLFile_children.min() = 0;
			IDLFiles::meta_IDLFile_children.max() = -1;
			IDLFiles::meta_IDLFile_children.isNavigable() = true;
			IDLFiles::meta_IDLFile_children.target() = IDLFile::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			IDLFiles::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			IDLFiles::meta_RootFolder_parent.name() = "RootFolder_parent";
			IDLFiles::meta_RootFolder_parent.isNavigable() = true;
			IDLFiles::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_IDLFiles_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_IDLFiles_children.name() = "IDLFiles";
			RootFolder::meta_IDLFiles_children.min() = 0;
			RootFolder::meta_IDLFiles_children.max() = -1;
			RootFolder::meta_IDLFiles_children.isNavigable() = true;
			RootFolder::meta_IDLFiles_children.target() = IDLFiles::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentType::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentType::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			ComponentType::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			ComponentType::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_ComponentType_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_ComponentType_children.name() = "ComponentType";
			ComponentImplementationContainer::meta_ComponentType_children.min() = 0;
			ComponentImplementationContainer::meta_ComponentType_children.max() = -1;
			ComponentImplementationContainer::meta_ComponentType_children.isNavigable() = true;
			ComponentImplementationContainer::meta_ComponentType_children.target() = ComponentType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentType::meta_ComponentContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentType::meta_ComponentContainer_parent.name() = "ComponentContainer_parent";
			ComponentType::meta_ComponentContainer_parent.isNavigable() = true;
			ComponentType::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
			ComponentContainer::meta_ComponentType_child = Uml::CompositionChildRole::Create(comp);
			ComponentContainer::meta_ComponentType_child.name() = "ComponentType";
			ComponentContainer::meta_ComponentType_child.min() = 1;
			ComponentContainer::meta_ComponentType_child.max() = 1;
			ComponentContainer::meta_ComponentType_child.isNavigable() = true;
			ComponentContainer::meta_ComponentType_child.target() = ComponentType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentType::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentType::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			ComponentType::meta_PackageContainer_parent.isNavigable() = true;
			ComponentType::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_ComponentType_children = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_ComponentType_children.name() = "ComponentType";
			PackageContainer::meta_ComponentType_children.min() = 0;
			PackageContainer::meta_ComponentType_children.max() = -1;
			PackageContainer::meta_ComponentType_children.isNavigable() = true;
			PackageContainer::meta_ComponentType_children.target() = ComponentType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentContainer::meta_ComponentTypes_parent = Uml::CompositionParentRole::Create(comp);
			ComponentContainer::meta_ComponentTypes_parent.name() = "ComponentTypes_parent";
			ComponentContainer::meta_ComponentTypes_parent.isNavigable() = true;
			ComponentContainer::meta_ComponentTypes_parent.target() = ComponentTypes::meta;
			ComponentTypes::meta_ComponentContainer_children = Uml::CompositionChildRole::Create(comp);
			ComponentTypes::meta_ComponentContainer_children.name() = "ComponentContainer";
			ComponentTypes::meta_ComponentContainer_children.min() = 0;
			ComponentTypes::meta_ComponentContainer_children.max() = -1;
			ComponentTypes::meta_ComponentContainer_children.isNavigable() = true;
			ComponentTypes::meta_ComponentContainer_children.target() = ComponentContainer::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentTypes::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			ComponentTypes::meta_RootFolder_parent.name() = "RootFolder_parent";
			ComponentTypes::meta_RootFolder_parent.isNavigable() = true;
			ComponentTypes::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_ComponentTypes_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_ComponentTypes_children.name() = "ComponentTypes";
			RootFolder::meta_ComponentTypes_children.min() = 0;
			RootFolder::meta_ComponentTypes_children.max() = -1;
			RootFolder::meta_ComponentTypes_children.isNavigable() = true;
			RootFolder::meta_ComponentTypes_children.target() = ComponentTypes::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentConfigProperty::meta_ComponentContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentConfigProperty::meta_ComponentContainer_parent.name() = "ComponentContainer_parent";
			ComponentConfigProperty::meta_ComponentContainer_parent.isNavigable() = true;
			ComponentConfigProperty::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
			ComponentContainer::meta_ComponentConfigProperty_children = Uml::CompositionChildRole::Create(comp);
			ComponentContainer::meta_ComponentConfigProperty_children.name() = "ComponentConfigProperty";
			ComponentContainer::meta_ComponentConfigProperty_children.min() = 0;
			ComponentContainer::meta_ComponentConfigProperty_children.max() = -1;
			ComponentContainer::meta_ComponentConfigProperty_children.isNavigable() = true;
			ComponentContainer::meta_ComponentConfigProperty_children.target() = ComponentConfigProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentInfoProperty::meta_ComponentContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentInfoProperty::meta_ComponentContainer_parent.name() = "ComponentContainer_parent";
			ComponentInfoProperty::meta_ComponentContainer_parent.isNavigable() = true;
			ComponentInfoProperty::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
			ComponentContainer::meta_ComponentInfoProperty_children = Uml::CompositionChildRole::Create(comp);
			ComponentContainer::meta_ComponentInfoProperty_children.name() = "ComponentInfoProperty";
			ComponentContainer::meta_ComponentInfoProperty_children.min() = 0;
			ComponentContainer::meta_ComponentInfoProperty_children.max() = -1;
			ComponentContainer::meta_ComponentInfoProperty_children.isNavigable() = true;
			ComponentContainer::meta_ComponentInfoProperty_children.target() = ComponentInfoProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			DataType::meta_ComponentPropertyDescription_parent = Uml::CompositionParentRole::Create(comp);
			DataType::meta_ComponentPropertyDescription_parent.name() = "ComponentPropertyDescription_parent";
			DataType::meta_ComponentPropertyDescription_parent.isNavigable() = true;
			DataType::meta_ComponentPropertyDescription_parent.target() = ComponentPropertyDescription::meta;
			ComponentPropertyDescription::meta_DataType_child = Uml::CompositionChildRole::Create(comp);
			ComponentPropertyDescription::meta_DataType_child.name() = "DataType";
			ComponentPropertyDescription::meta_DataType_child.min() = 1;
			ComponentPropertyDescription::meta_DataType_child.max() = 1;
			ComponentPropertyDescription::meta_DataType_child.isNavigable() = true;
			ComponentPropertyDescription::meta_DataType_child.target() = DataType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPropertyDescription::meta_ComponentContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPropertyDescription::meta_ComponentContainer_parent.name() = "ComponentContainer_parent";
			ComponentPropertyDescription::meta_ComponentContainer_parent.isNavigable() = true;
			ComponentPropertyDescription::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
			ComponentContainer::meta_ComponentPropertyDescription_children = Uml::CompositionChildRole::Create(comp);
			ComponentContainer::meta_ComponentPropertyDescription_children.name() = "ComponentPropertyDescription";
			ComponentContainer::meta_ComponentPropertyDescription_children.min() = 0;
			ComponentContainer::meta_ComponentPropertyDescription_children.max() = -1;
			ComponentContainer::meta_ComponentPropertyDescription_children.isNavigable() = true;
			ComponentContainer::meta_ComponentPropertyDescription_children.target() = ComponentPropertyDescription::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentProperty::meta_ComponentContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentProperty::meta_ComponentContainer_parent.name() = "ComponentContainer_parent";
			ComponentProperty::meta_ComponentContainer_parent.isNavigable() = true;
			ComponentProperty::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
			ComponentContainer::meta_ComponentProperty_children = Uml::CompositionChildRole::Create(comp);
			ComponentContainer::meta_ComponentProperty_children.name() = "ComponentProperty";
			ComponentContainer::meta_ComponentProperty_children.min() = 0;
			ComponentContainer::meta_ComponentProperty_children.max() = -1;
			ComponentContainer::meta_ComponentProperty_children.isNavigable() = true;
			ComponentContainer::meta_ComponentProperty_children.target() = ComponentProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_ComponentContainer_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_ComponentContainer_parent.name() = "ComponentContainer_parent";
			Property::meta_ComponentContainer_parent.isNavigable() = true;
			Property::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
			ComponentContainer::meta_Property_children = Uml::CompositionChildRole::Create(comp);
			ComponentContainer::meta_Property_children.name() = "Property";
			ComponentContainer::meta_Property_children.min() = 0;
			ComponentContainer::meta_Property_children.max() = -1;
			ComponentContainer::meta_Property_children.isNavigable() = true;
			ComponentContainer::meta_Property_children.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ImplementationCapability::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ImplementationCapability::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			ImplementationCapability::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			ImplementationCapability::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_ImplementationCapability_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_ImplementationCapability_children.name() = "ImplementationCapability";
			ComponentImplementationContainer::meta_ImplementationCapability_children.min() = 0;
			ComponentImplementationContainer::meta_ImplementationCapability_children.max() = -1;
			ComponentImplementationContainer::meta_ImplementationCapability_children.isNavigable() = true;
			ComponentImplementationContainer::meta_ImplementationCapability_children.target() = ImplementationCapability::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ImplementationDependsOn::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ImplementationDependsOn::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			ImplementationDependsOn::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			ImplementationDependsOn::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_ImplementationDependsOn_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_ImplementationDependsOn_children.name() = "ImplementationDependsOn";
			ComponentImplementationContainer::meta_ImplementationDependsOn_children.min() = 0;
			ComponentImplementationContainer::meta_ImplementationDependsOn_children.max() = -1;
			ComponentImplementationContainer::meta_ImplementationDependsOn_children.isNavigable() = true;
			ComponentImplementationContainer::meta_ImplementationDependsOn_children.target() = ImplementationDependsOn::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Implements::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			Implements::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			Implements::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			Implements::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_Implements_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_Implements_children.name() = "Implements";
			ComponentImplementationContainer::meta_Implements_children.min() = 0;
			ComponentImplementationContainer::meta_Implements_children.max() = -1;
			ComponentImplementationContainer::meta_Implements_children.isNavigable() = true;
			ComponentImplementationContainer::meta_Implements_children.target() = Implements::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentImplementationContainer::meta_ComponentImplementations_parent = Uml::CompositionParentRole::Create(comp);
			ComponentImplementationContainer::meta_ComponentImplementations_parent.name() = "ComponentImplementations_parent";
			ComponentImplementationContainer::meta_ComponentImplementations_parent.isNavigable() = true;
			ComponentImplementationContainer::meta_ComponentImplementations_parent.target() = ComponentImplementations::meta;
			ComponentImplementations::meta_ComponentImplementationContainer_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementations::meta_ComponentImplementationContainer_children.name() = "ComponentImplementationContainer";
			ComponentImplementations::meta_ComponentImplementationContainer_children.min() = 0;
			ComponentImplementations::meta_ComponentImplementationContainer_children.max() = -1;
			ComponentImplementations::meta_ComponentImplementationContainer_children.isNavigable() = true;
			ComponentImplementations::meta_ComponentImplementationContainer_children.target() = ComponentImplementationContainer::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentImplementations::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			ComponentImplementations::meta_RootFolder_parent.name() = "RootFolder_parent";
			ComponentImplementations::meta_RootFolder_parent.isNavigable() = true;
			ComponentImplementations::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_ComponentImplementations_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_ComponentImplementations_children.name() = "ComponentImplementations";
			RootFolder::meta_ComponentImplementations_children.min() = 0;
			RootFolder::meta_ComponentImplementations_children.max() = -1;
			RootFolder::meta_ComponentImplementations_children.isNavigable() = true;
			RootFolder::meta_ComponentImplementations_children.target() = ComponentImplementations::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentImplementationReference::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentImplementationReference::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			ComponentImplementationReference::meta_PackageContainer_parent.isNavigable() = true;
			ComponentImplementationReference::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_ComponentImplementationReference_children = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_ComponentImplementationReference_children.name() = "ComponentImplementationReference";
			PackageContainer::meta_ComponentImplementationReference_children.min() = 0;
			PackageContainer::meta_ComponentImplementationReference_children.max() = -1;
			PackageContainer::meta_ComponentImplementationReference_children.isNavigable() = true;
			PackageContainer::meta_ComponentImplementationReference_children.target() = ComponentImplementationReference::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ConfigProperty::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ConfigProperty::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			ConfigProperty::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			ConfigProperty::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_ConfigProperty_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_ConfigProperty_children.name() = "ConfigProperty";
			ComponentImplementationContainer::meta_ConfigProperty_children.min() = 0;
			ComponentImplementationContainer::meta_ConfigProperty_children.max() = -1;
			ComponentImplementationContainer::meta_ConfigProperty_children.isNavigable() = true;
			ComponentImplementationContainer::meta_ConfigProperty_children.target() = ConfigProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			InfoProperty::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			InfoProperty::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			InfoProperty::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			InfoProperty::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_InfoProperty_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_InfoProperty_children.name() = "InfoProperty";
			ComponentImplementationContainer::meta_InfoProperty_children.min() = 0;
			ComponentImplementationContainer::meta_InfoProperty_children.max() = -1;
			ComponentImplementationContainer::meta_InfoProperty_children.isNavigable() = true;
			ComponentImplementationContainer::meta_InfoProperty_children.target() = InfoProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_MonolithprimaryArtifact_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_MonolithprimaryArtifact_children.name() = "MonolithprimaryArtifact";
			ComponentImplementationContainer::meta_MonolithprimaryArtifact_children.min() = 0;
			ComponentImplementationContainer::meta_MonolithprimaryArtifact_children.max() = -1;
			ComponentImplementationContainer::meta_MonolithprimaryArtifact_children.isNavigable() = true;
			ComponentImplementationContainer::meta_MonolithprimaryArtifact_children.target() = MonolithprimaryArtifact::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			MonolithDeployRequirement::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			MonolithDeployRequirement::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			MonolithDeployRequirement::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			MonolithDeployRequirement::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_MonolithDeployRequirement_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_MonolithDeployRequirement_children.name() = "MonolithDeployRequirement";
			ComponentImplementationContainer::meta_MonolithDeployRequirement_children.min() = 0;
			ComponentImplementationContainer::meta_MonolithDeployRequirement_children.max() = -1;
			ComponentImplementationContainer::meta_MonolithDeployRequirement_children.isNavigable() = true;
			ComponentImplementationContainer::meta_MonolithDeployRequirement_children.target() = MonolithDeployRequirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentImplementation::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentImplementation::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			ComponentImplementation::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			ComponentImplementation::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_ComponentImplementation_child = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_ComponentImplementation_child.name() = "ComponentImplementation";
			ComponentImplementationContainer::meta_ComponentImplementation_child.min() = 0;
			ComponentImplementationContainer::meta_ComponentImplementation_child.max() = 1;
			ComponentImplementationContainer::meta_ComponentImplementation_child.isNavigable() = true;
			ComponentImplementationContainer::meta_ComponentImplementation_child.target() = ComponentImplementation::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ImplementationRequirement::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ImplementationRequirement::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			ImplementationRequirement::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			ImplementationRequirement::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_ImplementationRequirement_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_ImplementationRequirement_children.name() = "ImplementationRequirement";
			ComponentImplementationContainer::meta_ImplementationRequirement_children.min() = 0;
			ComponentImplementationContainer::meta_ImplementationRequirement_children.max() = -1;
			ComponentImplementationContainer::meta_ImplementationRequirement_children.isNavigable() = true;
			ComponentImplementationContainer::meta_ImplementationRequirement_children.target() = ImplementationRequirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			MonolithExecParameter::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			MonolithExecParameter::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			MonolithExecParameter::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			MonolithExecParameter::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_MonolithExecParameter_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_MonolithExecParameter_children.name() = "MonolithExecParameter";
			ComponentImplementationContainer::meta_MonolithExecParameter_children.min() = 0;
			ComponentImplementationContainer::meta_MonolithExecParameter_children.max() = -1;
			ComponentImplementationContainer::meta_MonolithExecParameter_children.isNavigable() = true;
			ComponentImplementationContainer::meta_MonolithExecParameter_children.target() = MonolithExecParameter::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ImplementationDependency::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ImplementationDependency::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			ImplementationDependency::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			ImplementationDependency::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_ImplementationDependency_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_ImplementationDependency_children.name() = "ImplementationDependency";
			ComponentImplementationContainer::meta_ImplementationDependency_children.min() = 0;
			ComponentImplementationContainer::meta_ImplementationDependency_children.max() = -1;
			ComponentImplementationContainer::meta_ImplementationDependency_children.isNavigable() = true;
			ComponentImplementationContainer::meta_ImplementationDependency_children.target() = ImplementationDependency::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			Property::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			Property::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_Property_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_Property_children.name() = "Property";
			ComponentImplementationContainer::meta_Property_children.min() = 0;
			ComponentImplementationContainer::meta_Property_children.max() = -1;
			ComponentImplementationContainer::meta_Property_children.isNavigable() = true;
			ComponentImplementationContainer::meta_Property_children.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Capability::meta_ComponentImplementationContainer_parent = Uml::CompositionParentRole::Create(comp);
			Capability::meta_ComponentImplementationContainer_parent.name() = "ComponentImplementationContainer_parent";
			Capability::meta_ComponentImplementationContainer_parent.isNavigable() = true;
			Capability::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
			ComponentImplementationContainer::meta_Capability_children = Uml::CompositionChildRole::Create(comp);
			ComponentImplementationContainer::meta_Capability_children.name() = "Capability";
			ComponentImplementationContainer::meta_Capability_children.min() = 0;
			ComponentImplementationContainer::meta_Capability_children.max() = -1;
			ComponentImplementationContainer::meta_Capability_children.isNavigable() = true;
			ComponentImplementationContainer::meta_Capability_children.target() = Capability::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_RequirementBase_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_RequirementBase_parent.name() = "RequirementBase_parent";
			Property::meta_RequirementBase_parent.isNavigable() = true;
			Property::meta_RequirementBase_parent.target() = RequirementBase::meta;
			RequirementBase::meta_Property_children = Uml::CompositionChildRole::Create(comp);
			RequirementBase::meta_Property_children.name() = "Property";
			RequirementBase::meta_Property_children.min() = 0;
			RequirementBase::meta_Property_children.max() = -1;
			RequirementBase::meta_Property_children.isNavigable() = true;
			RequirementBase::meta_Property_children.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Requirement::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			Requirement::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			Requirement::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			Requirement::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_Requirement_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_Requirement_children.name() = "Requirement";
			PackageConfigurationContainer::meta_Requirement_children.min() = 0;
			PackageConfigurationContainer::meta_Requirement_children.max() = -1;
			PackageConfigurationContainer::meta_Requirement_children.isNavigable() = true;
			PackageConfigurationContainer::meta_Requirement_children.target() = Requirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Requirement::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			Requirement::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			Requirement::meta_ComponentAssembly_parent.isNavigable() = true;
			Requirement::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_Requirement_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_Requirement_children.name() = "Requirement";
			ComponentAssembly::meta_Requirement_children.min() = 0;
			ComponentAssembly::meta_Requirement_children.max() = -1;
			ComponentAssembly::meta_Requirement_children.isNavigable() = true;
			ComponentAssembly::meta_Requirement_children.target() = Requirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			DataType::meta_Any_parent = Uml::CompositionParentRole::Create(comp);
			DataType::meta_Any_parent.name() = "Any_parent";
			DataType::meta_Any_parent.isNavigable() = true;
			DataType::meta_Any_parent.target() = Any::meta;
			Any::meta_DataType_child = Uml::CompositionChildRole::Create(comp);
			Any::meta_DataType_child.name() = "DataType";
			Any::meta_DataType_child.min() = 1;
			Any::meta_DataType_child.max() = 1;
			Any::meta_DataType_child.isNavigable() = true;
			Any::meta_DataType_child.target() = DataType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Any::meta_SatisfierProperty_parent = Uml::CompositionParentRole::Create(comp);
			Any::meta_SatisfierProperty_parent.name() = "SatisfierProperty_parent";
			Any::meta_SatisfierProperty_parent.isNavigable() = true;
			Any::meta_SatisfierProperty_parent.target() = SatisfierProperty::meta;
			SatisfierProperty::meta_Any_child = Uml::CompositionChildRole::Create(comp);
			SatisfierProperty::meta_Any_child.name() = "Any";
			SatisfierProperty::meta_Any_child.min() = 1;
			SatisfierProperty::meta_Any_child.max() = 1;
			SatisfierProperty::meta_Any_child.isNavigable() = true;
			SatisfierProperty::meta_Any_child.target() = Any::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Any::meta_Property_parent = Uml::CompositionParentRole::Create(comp);
			Any::meta_Property_parent.name() = "Property_parent";
			Any::meta_Property_parent.isNavigable() = true;
			Any::meta_Property_parent.target() = Property::meta;
			Property::meta_Any_child = Uml::CompositionChildRole::Create(comp);
			Property::meta_Any_child.name() = "Any";
			Property::meta_Any_child.min() = 1;
			Property::meta_Any_child.max() = 1;
			Property::meta_Any_child.isNavigable() = true;
			Property::meta_Any_child.target() = Any::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			Property::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			Property::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_Property_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_Property_children.name() = "Property";
			PackageConfigurationContainer::meta_Property_children.min() = 0;
			PackageConfigurationContainer::meta_Property_children.max() = -1;
			PackageConfigurationContainer::meta_Property_children.isNavigable() = true;
			PackageConfigurationContainer::meta_Property_children.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			Property::meta_ComponentAssembly_parent.isNavigable() = true;
			Property::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_Property_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_Property_children.name() = "Property";
			ComponentAssembly::meta_Property_children.min() = 0;
			ComponentAssembly::meta_Property_children.max() = -1;
			ComponentAssembly::meta_Property_children.isNavigable() = true;
			ComponentAssembly::meta_Property_children.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			Property::meta_PackageContainer_parent.isNavigable() = true;
			Property::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_Property_children = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_Property_children.name() = "Property";
			PackageContainer::meta_Property_children.min() = 0;
			PackageContainer::meta_Property_children.max() = -1;
			PackageContainer::meta_Property_children.isNavigable() = true;
			PackageContainer::meta_Property_children.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			SatisfierProperty::meta_RequirementSatisfier_parent = Uml::CompositionParentRole::Create(comp);
			SatisfierProperty::meta_RequirementSatisfier_parent.name() = "RequirementSatisfier_parent";
			SatisfierProperty::meta_RequirementSatisfier_parent.isNavigable() = true;
			SatisfierProperty::meta_RequirementSatisfier_parent.target() = RequirementSatisfier::meta;
			RequirementSatisfier::meta_SatisfierProperty_children = Uml::CompositionChildRole::Create(comp);
			RequirementSatisfier::meta_SatisfierProperty_children.name() = "SatisfierProperty";
			RequirementSatisfier::meta_SatisfierProperty_children.min() = 0;
			RequirementSatisfier::meta_SatisfierProperty_children.max() = -1;
			RequirementSatisfier::meta_SatisfierProperty_children.isNavigable() = true;
			RequirementSatisfier::meta_SatisfierProperty_children.target() = SatisfierProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PredefinedType::meta_DataType_parent = Uml::CompositionParentRole::Create(comp);
			PredefinedType::meta_DataType_parent.name() = "DataType_parent";
			PredefinedType::meta_DataType_parent.isNavigable() = true;
			PredefinedType::meta_DataType_parent.target() = DataType::meta;
			DataType::meta_PredefinedType_child = Uml::CompositionChildRole::Create(comp);
			DataType::meta_PredefinedType_child.name() = "PredefinedType";
			DataType::meta_PredefinedType_child.min() = 0;
			DataType::meta_PredefinedType_child.max() = 1;
			DataType::meta_PredefinedType_child.isNavigable() = true;
			DataType::meta_PredefinedType_child.target() = PredefinedType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageBaseConnection::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageBaseConnection::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			PackageBaseConnection::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			PackageBaseConnection::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_PackageBaseConnection_child = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_PackageBaseConnection_child.name() = "PackageBaseConnection";
			PackageConfigurationContainer::meta_PackageBaseConnection_child.min() = 0;
			PackageConfigurationContainer::meta_PackageBaseConnection_child.max() = 1;
			PackageConfigurationContainer::meta_PackageBaseConnection_child.isNavigable() = true;
			PackageConfigurationContainer::meta_PackageBaseConnection_child.target() = PackageBaseConnection::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageReferenceConnection::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageReferenceConnection::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			PackageReferenceConnection::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			PackageReferenceConnection::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_PackageReferenceConnection_child = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_PackageReferenceConnection_child.name() = "PackageReferenceConnection";
			PackageConfigurationContainer::meta_PackageReferenceConnection_child.min() = 0;
			PackageConfigurationContainer::meta_PackageReferenceConnection_child.max() = 1;
			PackageConfigurationContainer::meta_PackageReferenceConnection_child.isNavigable() = true;
			PackageConfigurationContainer::meta_PackageReferenceConnection_child.target() = PackageReferenceConnection::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageConfigurationReference::meta_TopLevelPackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageConfigurationReference::meta_TopLevelPackageContainer_parent.name() = "TopLevelPackageContainer_parent";
			PackageConfigurationReference::meta_TopLevelPackageContainer_parent.isNavigable() = true;
			PackageConfigurationReference::meta_TopLevelPackageContainer_parent.target() = TopLevelPackageContainer::meta;
			TopLevelPackageContainer::meta_PackageConfigurationReference_children = Uml::CompositionChildRole::Create(comp);
			TopLevelPackageContainer::meta_PackageConfigurationReference_children.name() = "PackageConfigurationReference";
			TopLevelPackageContainer::meta_PackageConfigurationReference_children.min() = 0;
			TopLevelPackageContainer::meta_PackageConfigurationReference_children.max() = -1;
			TopLevelPackageContainer::meta_PackageConfigurationReference_children.isNavigable() = true;
			TopLevelPackageContainer::meta_PackageConfigurationReference_children.target() = PackageConfigurationReference::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageConfiguration::meta_specializedConfig_PackageConfiguration_parent = Uml::CompositionParentRole::Create(comp);
			PackageConfiguration::meta_specializedConfig_PackageConfiguration_parent.name() = "specializedConfig_PackageConfiguration_parent";
			PackageConfiguration::meta_specializedConfig_PackageConfiguration_parent.isNavigable() = true;
			PackageConfiguration::meta_specializedConfig_PackageConfiguration_parent.target() = PackageConfiguration::meta;
			PackageConfiguration::meta_specializedConfig = Uml::CompositionChildRole::Create(comp);
			PackageConfiguration::meta_specializedConfig.name() = "specializedConfig";
			PackageConfiguration::meta_specializedConfig.min() = 0;
			PackageConfiguration::meta_specializedConfig.max() = 1;
			PackageConfiguration::meta_specializedConfig.isNavigable() = true;
			PackageConfiguration::meta_specializedConfig.target() = PackageConfiguration::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageConfiguration::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageConfiguration::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			PackageConfiguration::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			PackageConfiguration::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_PackageConfiguration_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_PackageConfiguration_children.name() = "PackageConfiguration";
			PackageConfigurationContainer::meta_PackageConfiguration_children.min() = 0;
			PackageConfigurationContainer::meta_PackageConfiguration_children.max() = -1;
			PackageConfigurationContainer::meta_PackageConfiguration_children.isNavigable() = true;
			PackageConfigurationContainer::meta_PackageConfiguration_children.target() = PackageConfiguration::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageConfigurationContainer::meta_PackageConfigurations_parent = Uml::CompositionParentRole::Create(comp);
			PackageConfigurationContainer::meta_PackageConfigurations_parent.name() = "PackageConfigurations_parent";
			PackageConfigurationContainer::meta_PackageConfigurations_parent.isNavigable() = true;
			PackageConfigurationContainer::meta_PackageConfigurations_parent.target() = PackageConfigurations::meta;
			PackageConfigurations::meta_PackageConfigurationContainer_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurations::meta_PackageConfigurationContainer_children.name() = "PackageConfigurationContainer";
			PackageConfigurations::meta_PackageConfigurationContainer_children.min() = 0;
			PackageConfigurations::meta_PackageConfigurationContainer_children.max() = -1;
			PackageConfigurations::meta_PackageConfigurationContainer_children.isNavigable() = true;
			PackageConfigurations::meta_PackageConfigurationContainer_children.target() = PackageConfigurationContainer::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageConfigurations::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			PackageConfigurations::meta_RootFolder_parent.name() = "RootFolder_parent";
			PackageConfigurations::meta_RootFolder_parent.isNavigable() = true;
			PackageConfigurations::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_PackageConfigurations_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_PackageConfigurations_children.name() = "PackageConfigurations";
			RootFolder::meta_PackageConfigurations_children.min() = 0;
			RootFolder::meta_PackageConfigurations_children.max() = -1;
			RootFolder::meta_PackageConfigurations_children.isNavigable() = true;
			RootFolder::meta_PackageConfigurations_children.target() = PackageConfigurations::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPackage::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPackage::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			ComponentPackage::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			ComponentPackage::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_ComponentPackage_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_ComponentPackage_children.name() = "ComponentPackage";
			PackageConfigurationContainer::meta_ComponentPackage_children.min() = 0;
			PackageConfigurationContainer::meta_ComponentPackage_children.max() = -1;
			PackageConfigurationContainer::meta_ComponentPackage_children.isNavigable() = true;
			PackageConfigurationContainer::meta_ComponentPackage_children.target() = ComponentPackage::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPackageReference::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPackageReference::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			ComponentPackageReference::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			ComponentPackageReference::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_ComponentPackageReference_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_ComponentPackageReference_children.name() = "ComponentPackageReference";
			PackageConfigurationContainer::meta_ComponentPackageReference_children.min() = 0;
			PackageConfigurationContainer::meta_ComponentPackageReference_children.max() = -1;
			PackageConfigurationContainer::meta_ComponentPackageReference_children.isNavigable() = true;
			PackageConfigurationContainer::meta_ComponentPackageReference_children.target() = ComponentPackageReference::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageConfigurationProperty::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageConfigurationProperty::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			PackageConfigurationProperty::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			PackageConfigurationProperty::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_PackageConfigurationProperty_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_PackageConfigurationProperty_children.name() = "PackageConfigurationProperty";
			PackageConfigurationContainer::meta_PackageConfigurationProperty_children.min() = 0;
			PackageConfigurationContainer::meta_PackageConfigurationProperty_children.max() = -1;
			PackageConfigurationContainer::meta_PackageConfigurationProperty_children.isNavigable() = true;
			PackageConfigurationContainer::meta_PackageConfigurationProperty_children.target() = PackageConfigurationProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageSelectRequirement::meta_PackageConfigurationContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageSelectRequirement::meta_PackageConfigurationContainer_parent.name() = "PackageConfigurationContainer_parent";
			PackageSelectRequirement::meta_PackageConfigurationContainer_parent.isNavigable() = true;
			PackageSelectRequirement::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
			PackageConfigurationContainer::meta_PackageSelectRequirement_children = Uml::CompositionChildRole::Create(comp);
			PackageConfigurationContainer::meta_PackageSelectRequirement_children.name() = "PackageSelectRequirement";
			PackageConfigurationContainer::meta_PackageSelectRequirement_children.min() = 0;
			PackageConfigurationContainer::meta_PackageSelectRequirement_children.max() = -1;
			PackageConfigurationContainer::meta_PackageSelectRequirement_children.isNavigable() = true;
			PackageConfigurationContainer::meta_PackageSelectRequirement_children.target() = PackageSelectRequirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			EmitConnector::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			EmitConnector::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			EmitConnector::meta_ComponentAssembly_parent.isNavigable() = true;
			EmitConnector::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_EmitConnector_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_EmitConnector_children.name() = "EmitConnector";
			ComponentAssembly::meta_EmitConnector_children.min() = 0;
			ComponentAssembly::meta_EmitConnector_children.max() = -1;
			ComponentAssembly::meta_EmitConnector_children.isNavigable() = true;
			ComponentAssembly::meta_EmitConnector_children.target() = EmitConnector::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentDef::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			ComponentDef::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			ComponentDef::meta_ComponentAssembly_parent.isNavigable() = true;
			ComponentDef::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_ComponentDef_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_ComponentDef_children.name() = "ComponentDef";
			ComponentAssembly::meta_ComponentDef_children.min() = 1;
			ComponentAssembly::meta_ComponentDef_children.max() = -1;
			ComponentAssembly::meta_ComponentDef_children.isNavigable() = true;
			ComponentAssembly::meta_ComponentDef_children.target() = ComponentDef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPackage::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPackage::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			ComponentPackage::meta_ComponentAssembly_parent.isNavigable() = true;
			ComponentPackage::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_ComponentPackage_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_ComponentPackage_children.name() = "ComponentPackage";
			ComponentAssembly::meta_ComponentPackage_children.min() = 0;
			ComponentAssembly::meta_ComponentPackage_children.max() = -1;
			ComponentAssembly::meta_ComponentPackage_children.isNavigable() = true;
			ComponentAssembly::meta_ComponentPackage_children.target() = ComponentPackage::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Invocation::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			Invocation::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			Invocation::meta_ComponentAssembly_parent.isNavigable() = true;
			Invocation::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_Invocation_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_Invocation_children.name() = "Invocation";
			ComponentAssembly::meta_Invocation_children.min() = 0;
			ComponentAssembly::meta_Invocation_children.max() = -1;
			ComponentAssembly::meta_Invocation_children.isNavigable() = true;
			ComponentAssembly::meta_Invocation_children.target() = Invocation::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			SubComponentSelectRequirement::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			SubComponentSelectRequirement::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			SubComponentSelectRequirement::meta_ComponentAssembly_parent.isNavigable() = true;
			SubComponentSelectRequirement::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_SubComponentSelectRequirement_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_SubComponentSelectRequirement_children.name() = "SubComponentSelectRequirement";
			ComponentAssembly::meta_SubComponentSelectRequirement_children.min() = 0;
			ComponentAssembly::meta_SubComponentSelectRequirement_children.max() = -1;
			ComponentAssembly::meta_SubComponentSelectRequirement_children.isNavigable() = true;
			ComponentAssembly::meta_SubComponentSelectRequirement_children.target() = SubComponentSelectRequirement::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			SubComponentConfigProperty::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			SubComponentConfigProperty::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			SubComponentConfigProperty::meta_ComponentAssembly_parent.isNavigable() = true;
			SubComponentConfigProperty::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_SubComponentConfigProperty_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_SubComponentConfigProperty_children.name() = "SubComponentConfigProperty";
			ComponentAssembly::meta_SubComponentConfigProperty_children.min() = 0;
			ComponentAssembly::meta_SubComponentConfigProperty_children.max() = -1;
			ComponentAssembly::meta_SubComponentConfigProperty_children.isNavigable() = true;
			ComponentAssembly::meta_SubComponentConfigProperty_children.target() = SubComponentConfigProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPackageReference::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPackageReference::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			ComponentPackageReference::meta_ComponentAssembly_parent.isNavigable() = true;
			ComponentPackageReference::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_ComponentPackageReference_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_ComponentPackageReference_children.name() = "ComponentPackageReference";
			ComponentAssembly::meta_ComponentPackageReference_children.min() = 0;
			ComponentAssembly::meta_ComponentPackageReference_children.max() = -1;
			ComponentAssembly::meta_ComponentPackageReference_children.isNavigable() = true;
			ComponentAssembly::meta_ComponentPackageReference_children.target() = ComponentPackageReference::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			InEventPortConsume::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			InEventPortConsume::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			InEventPortConsume::meta_ComponentAssembly_parent.isNavigable() = true;
			InEventPortConsume::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_InEventPortConsume_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_InEventPortConsume_children.name() = "InEventPortConsume";
			ComponentAssembly::meta_InEventPortConsume_children.min() = 0;
			ComponentAssembly::meta_InEventPortConsume_children.max() = -1;
			ComponentAssembly::meta_InEventPortConsume_children.isNavigable() = true;
			ComponentAssembly::meta_InEventPortConsume_children.target() = InEventPortConsume::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			OutEventPortPublish::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			OutEventPortPublish::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			OutEventPortPublish::meta_ComponentAssembly_parent.isNavigable() = true;
			OutEventPortPublish::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_OutEventPortPublish_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_OutEventPortPublish_children.name() = "OutEventPortPublish";
			ComponentAssembly::meta_OutEventPortPublish_children.min() = 0;
			ComponentAssembly::meta_OutEventPortPublish_children.max() = -1;
			ComponentAssembly::meta_OutEventPortPublish_children.isNavigable() = true;
			ComponentAssembly::meta_OutEventPortPublish_children.target() = OutEventPortPublish::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PublishConnector::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			PublishConnector::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			PublishConnector::meta_ComponentAssembly_parent.isNavigable() = true;
			PublishConnector::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_PublishConnector_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_PublishConnector_children.name() = "PublishConnector";
			ComponentAssembly::meta_PublishConnector_children.min() = 0;
			ComponentAssembly::meta_PublishConnector_children.max() = -1;
			ComponentAssembly::meta_PublishConnector_children.isNavigable() = true;
			ComponentAssembly::meta_PublishConnector_children.target() = PublishConnector::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ConnectionRequirements::meta_ComponentAssembly_parent = Uml::CompositionParentRole::Create(comp);
			ConnectionRequirements::meta_ComponentAssembly_parent.name() = "ComponentAssembly_parent";
			ConnectionRequirements::meta_ComponentAssembly_parent.isNavigable() = true;
			ConnectionRequirements::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
			ComponentAssembly::meta_ConnectionRequirements_children = Uml::CompositionChildRole::Create(comp);
			ComponentAssembly::meta_ConnectionRequirements_children.name() = "ConnectionRequirements";
			ComponentAssembly::meta_ConnectionRequirements_children.min() = 0;
			ComponentAssembly::meta_ConnectionRequirements_children.max() = -1;
			ComponentAssembly::meta_ConnectionRequirements_children.isNavigable() = true;
			ComponentAssembly::meta_ConnectionRequirements_children.target() = ConnectionRequirements::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageContainer::meta_ComponentPackages_parent = Uml::CompositionParentRole::Create(comp);
			PackageContainer::meta_ComponentPackages_parent.name() = "ComponentPackages_parent";
			PackageContainer::meta_ComponentPackages_parent.isNavigable() = true;
			PackageContainer::meta_ComponentPackages_parent.target() = ComponentPackages::meta;
			ComponentPackages::meta_PackageContainer_children = Uml::CompositionChildRole::Create(comp);
			ComponentPackages::meta_PackageContainer_children.name() = "PackageContainer";
			ComponentPackages::meta_PackageContainer_children.min() = 0;
			ComponentPackages::meta_PackageContainer_children.max() = -1;
			ComponentPackages::meta_PackageContainer_children.isNavigable() = true;
			ComponentPackages::meta_PackageContainer_children.target() = PackageContainer::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPackages::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPackages::meta_RootFolder_parent.name() = "RootFolder_parent";
			ComponentPackages::meta_RootFolder_parent.isNavigable() = true;
			ComponentPackages::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_ComponentPackages_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_ComponentPackages_children.name() = "ComponentPackages";
			RootFolder::meta_ComponentPackages_children.min() = 0;
			RootFolder::meta_ComponentPackages_children.max() = -1;
			RootFolder::meta_ComponentPackages_children.isNavigable() = true;
			RootFolder::meta_ComponentPackages_children.target() = ComponentPackages::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageInterface::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageInterface::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			PackageInterface::meta_PackageContainer_parent.isNavigable() = true;
			PackageInterface::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_PackageInterface_child = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_PackageInterface_child.name() = "PackageInterface";
			PackageContainer::meta_PackageInterface_child.min() = 1;
			PackageContainer::meta_PackageInterface_child.max() = 1;
			PackageContainer::meta_PackageInterface_child.isNavigable() = true;
			PackageContainer::meta_PackageInterface_child.target() = PackageInterface::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageImplementations::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageImplementations::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			PackageImplementations::meta_PackageContainer_parent.isNavigable() = true;
			PackageImplementations::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_PackageImplementations_children = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_PackageImplementations_children.name() = "PackageImplementations";
			PackageContainer::meta_PackageImplementations_children.min() = 0;
			PackageContainer::meta_PackageImplementations_children.max() = -1;
			PackageContainer::meta_PackageImplementations_children.isNavigable() = true;
			PackageContainer::meta_PackageImplementations_children.target() = PackageImplementations::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageConfigProperty::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageConfigProperty::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			PackageConfigProperty::meta_PackageContainer_parent.isNavigable() = true;
			PackageConfigProperty::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_PackageConfigProperty_children = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_PackageConfigProperty_children.name() = "PackageConfigProperty";
			PackageContainer::meta_PackageConfigProperty_children.min() = 0;
			PackageContainer::meta_PackageConfigProperty_children.max() = -1;
			PackageContainer::meta_PackageConfigProperty_children.isNavigable() = true;
			PackageContainer::meta_PackageConfigProperty_children.target() = PackageConfigProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PackageInfoProperty::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			PackageInfoProperty::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			PackageInfoProperty::meta_PackageContainer_parent.isNavigable() = true;
			PackageInfoProperty::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_PackageInfoProperty_children = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_PackageInfoProperty_children.name() = "PackageInfoProperty";
			PackageContainer::meta_PackageInfoProperty_children.min() = 0;
			PackageContainer::meta_PackageInfoProperty_children.max() = -1;
			PackageContainer::meta_PackageInfoProperty_children.isNavigable() = true;
			PackageContainer::meta_PackageInfoProperty_children.target() = PackageInfoProperty::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPackage::meta_PackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPackage::meta_PackageContainer_parent.name() = "PackageContainer_parent";
			ComponentPackage::meta_PackageContainer_parent.isNavigable() = true;
			ComponentPackage::meta_PackageContainer_parent.target() = PackageContainer::meta;
			PackageContainer::meta_ComponentPackage_child = Uml::CompositionChildRole::Create(comp);
			PackageContainer::meta_ComponentPackage_child.name() = "ComponentPackage";
			PackageContainer::meta_ComponentPackage_child.min() = 1;
			PackageContainer::meta_ComponentPackage_child.max() = 1;
			PackageContainer::meta_ComponentPackage_child.isNavigable() = true;
			PackageContainer::meta_ComponentPackage_child.target() = ComponentPackage::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			TopLevelPackage::meta_TopLevelPackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			TopLevelPackage::meta_TopLevelPackageContainer_parent.name() = "TopLevelPackageContainer_parent";
			TopLevelPackage::meta_TopLevelPackageContainer_parent.isNavigable() = true;
			TopLevelPackage::meta_TopLevelPackageContainer_parent.target() = TopLevelPackageContainer::meta;
			TopLevelPackageContainer::meta_TopLevelPackage_children = Uml::CompositionChildRole::Create(comp);
			TopLevelPackageContainer::meta_TopLevelPackage_children.name() = "TopLevelPackage";
			TopLevelPackageContainer::meta_TopLevelPackage_children.min() = 0;
			TopLevelPackageContainer::meta_TopLevelPackage_children.max() = -1;
			TopLevelPackageContainer::meta_TopLevelPackage_children.isNavigable() = true;
			TopLevelPackageContainer::meta_TopLevelPackage_children.target() = TopLevelPackage::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			TopLevelPackageConn::meta_TopLevelPackageContainer_parent = Uml::CompositionParentRole::Create(comp);
			TopLevelPackageConn::meta_TopLevelPackageContainer_parent.name() = "TopLevelPackageContainer_parent";
			TopLevelPackageConn::meta_TopLevelPackageContainer_parent.isNavigable() = true;
			TopLevelPackageConn::meta_TopLevelPackageContainer_parent.target() = TopLevelPackageContainer::meta;
			TopLevelPackageContainer::meta_TopLevelPackageConn_children = Uml::CompositionChildRole::Create(comp);
			TopLevelPackageContainer::meta_TopLevelPackageConn_children.name() = "TopLevelPackageConn";
			TopLevelPackageContainer::meta_TopLevelPackageConn_children.min() = 0;
			TopLevelPackageContainer::meta_TopLevelPackageConn_children.max() = -1;
			TopLevelPackageContainer::meta_TopLevelPackageConn_children.isNavigable() = true;
			TopLevelPackageContainer::meta_TopLevelPackageConn_children.target() = TopLevelPackageConn::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			TopLevelPackageContainer::meta_TopLevelPackageFolder_parent = Uml::CompositionParentRole::Create(comp);
			TopLevelPackageContainer::meta_TopLevelPackageFolder_parent.name() = "TopLevelPackageFolder_parent";
			TopLevelPackageContainer::meta_TopLevelPackageFolder_parent.isNavigable() = true;
			TopLevelPackageContainer::meta_TopLevelPackageFolder_parent.target() = TopLevelPackageFolder::meta;
			TopLevelPackageFolder::meta_TopLevelPackageContainer_children = Uml::CompositionChildRole::Create(comp);
			TopLevelPackageFolder::meta_TopLevelPackageContainer_children.name() = "TopLevelPackageContainer";
			TopLevelPackageFolder::meta_TopLevelPackageContainer_children.min() = 0;
			TopLevelPackageFolder::meta_TopLevelPackageContainer_children.max() = -1;
			TopLevelPackageFolder::meta_TopLevelPackageContainer_children.isNavigable() = true;
			TopLevelPackageFolder::meta_TopLevelPackageContainer_children.target() = TopLevelPackageContainer::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			TopLevelPackageFolder::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			TopLevelPackageFolder::meta_RootFolder_parent.name() = "RootFolder_parent";
			TopLevelPackageFolder::meta_RootFolder_parent.isNavigable() = true;
			TopLevelPackageFolder::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_TopLevelPackageFolder_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_TopLevelPackageFolder_children.name() = "TopLevelPackageFolder";
			RootFolder::meta_TopLevelPackageFolder_children.min() = 0;
			RootFolder::meta_TopLevelPackageFolder_children.max() = -1;
			RootFolder::meta_TopLevelPackageFolder_children.isNavigable() = true;
			RootFolder::meta_TopLevelPackageFolder_children.target() = TopLevelPackageFolder::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			EnumValue::meta_EnumerationDef_parent = Uml::CompositionParentRole::Create(comp);
			EnumValue::meta_EnumerationDef_parent.name() = "EnumerationDef_parent";
			EnumValue::meta_EnumerationDef_parent.isNavigable() = true;
			EnumValue::meta_EnumerationDef_parent.target() = EnumerationDef::meta;
			EnumerationDef::meta_EnumValue_children = Uml::CompositionChildRole::Create(comp);
			EnumerationDef::meta_EnumValue_children.name() = "EnumValue";
			EnumerationDef::meta_EnumValue_children.min() = 1;
			EnumerationDef::meta_EnumValue_children.max() = -1;
			EnumerationDef::meta_EnumValue_children.isNavigable() = true;
			EnumerationDef::meta_EnumValue_children.target() = EnumValue::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			GeneralTag::meta_Taggable_parent = Uml::CompositionParentRole::Create(comp);
			GeneralTag::meta_Taggable_parent.name() = "Taggable_parent";
			GeneralTag::meta_Taggable_parent.isNavigable() = true;
			GeneralTag::meta_Taggable_parent.target() = Taggable::meta;
			Taggable::meta_GeneralTag_child = Uml::CompositionChildRole::Create(comp);
			Taggable::meta_GeneralTag_child.name() = "GeneralTag";
			Taggable::meta_GeneralTag_child.min() = 0;
			Taggable::meta_GeneralTag_child.max() = 1;
			Taggable::meta_GeneralTag_child.isNavigable() = true;
			Taggable::meta_GeneralTag_child.target() = GeneralTag::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			NamedType::meta_Package_parent = Uml::CompositionParentRole::Create(comp);
			NamedType::meta_Package_parent.name() = "Package_parent";
			NamedType::meta_Package_parent.isNavigable() = true;
			NamedType::meta_Package_parent.target() = Package::meta;
			Package::meta_NamedType_children = Uml::CompositionChildRole::Create(comp);
			Package::meta_NamedType_children.name() = "NamedType";
			Package::meta_NamedType_children.min() = 0;
			Package::meta_NamedType_children.max() = -1;
			Package::meta_NamedType_children.isNavigable() = true;
			Package::meta_NamedType_children.target() = NamedType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			NoInheritable::meta_HasOperations_parent = Uml::CompositionParentRole::Create(comp);
			NoInheritable::meta_HasOperations_parent.name() = "HasOperations_parent";
			NoInheritable::meta_HasOperations_parent.isNavigable() = true;
			NoInheritable::meta_HasOperations_parent.target() = HasOperations::meta;
			HasOperations::meta_NoInheritable_children = Uml::CompositionChildRole::Create(comp);
			HasOperations::meta_NoInheritable_children.name() = "NoInheritable";
			HasOperations::meta_NoInheritable_children.min() = 0;
			HasOperations::meta_NoInheritable_children.max() = -1;
			HasOperations::meta_NoInheritable_children.isNavigable() = true;
			HasOperations::meta_NoInheritable_children.target() = NoInheritable::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_AliasDef_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_AliasDef_parent.name() = "AliasDef_parent";
			Member::meta_AliasDef_parent.isNavigable() = true;
			Member::meta_AliasDef_parent.target() = AliasDef::meta;
			AliasDef::meta_Member_child = Uml::CompositionChildRole::Create(comp);
			AliasDef::meta_Member_child.name() = "Member";
			AliasDef::meta_Member_child.min() = 1;
			AliasDef::meta_Member_child.max() = 1;
			AliasDef::meta_Member_child.isNavigable() = true;
			AliasDef::meta_Member_child.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_AggregateDef_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_AggregateDef_parent.name() = "AggregateDef_parent";
			Member::meta_AggregateDef_parent.isNavigable() = true;
			Member::meta_AggregateDef_parent.target() = AggregateDef::meta;
			AggregateDef::meta_Member_children = Uml::CompositionChildRole::Create(comp);
			AggregateDef::meta_Member_children.name() = "Member";
			AggregateDef::meta_Member_children.min() = 1;
			AggregateDef::meta_Member_children.max() = -1;
			AggregateDef::meta_Member_children.isNavigable() = true;
			AggregateDef::meta_Member_children.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			LabelConnection::meta_SwitchedAggregateDef_parent = Uml::CompositionParentRole::Create(comp);
			LabelConnection::meta_SwitchedAggregateDef_parent.name() = "SwitchedAggregateDef_parent";
			LabelConnection::meta_SwitchedAggregateDef_parent.isNavigable() = true;
			LabelConnection::meta_SwitchedAggregateDef_parent.target() = SwitchedAggregateDef::meta;
			SwitchedAggregateDef::meta_LabelConnection_children = Uml::CompositionChildRole::Create(comp);
			SwitchedAggregateDef::meta_LabelConnection_children.name() = "LabelConnection";
			SwitchedAggregateDef::meta_LabelConnection_children.min() = 1;
			SwitchedAggregateDef::meta_LabelConnection_children.max() = -1;
			SwitchedAggregateDef::meta_LabelConnection_children.isNavigable() = true;
			SwitchedAggregateDef::meta_LabelConnection_children.target() = LabelConnection::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Discriminator::meta_SwitchedAggregateDef_parent = Uml::CompositionParentRole::Create(comp);
			Discriminator::meta_SwitchedAggregateDef_parent.name() = "SwitchedAggregateDef_parent";
			Discriminator::meta_SwitchedAggregateDef_parent.isNavigable() = true;
			Discriminator::meta_SwitchedAggregateDef_parent.target() = SwitchedAggregateDef::meta;
			SwitchedAggregateDef::meta_Discriminator_child = Uml::CompositionChildRole::Create(comp);
			SwitchedAggregateDef::meta_Discriminator_child.name() = "Discriminator";
			SwitchedAggregateDef::meta_Discriminator_child.min() = 1;
			SwitchedAggregateDef::meta_Discriminator_child.max() = 1;
			SwitchedAggregateDef::meta_Discriminator_child.isNavigable() = true;
			SwitchedAggregateDef::meta_Discriminator_child.target() = Discriminator::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Label::meta_SwitchedAggregateDef_parent = Uml::CompositionParentRole::Create(comp);
			Label::meta_SwitchedAggregateDef_parent.name() = "SwitchedAggregateDef_parent";
			Label::meta_SwitchedAggregateDef_parent.isNavigable() = true;
			Label::meta_SwitchedAggregateDef_parent.target() = SwitchedAggregateDef::meta;
			SwitchedAggregateDef::meta_Label_children = Uml::CompositionChildRole::Create(comp);
			SwitchedAggregateDef::meta_Label_children.name() = "Label";
			SwitchedAggregateDef::meta_Label_children.min() = 1;
			SwitchedAggregateDef::meta_Label_children.max() = -1;
			SwitchedAggregateDef::meta_Label_children.isNavigable() = true;
			SwitchedAggregateDef::meta_Label_children.target() = Label::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_SwitchedAggregateDef_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_SwitchedAggregateDef_parent.name() = "SwitchedAggregateDef_parent";
			Member::meta_SwitchedAggregateDef_parent.isNavigable() = true;
			Member::meta_SwitchedAggregateDef_parent.target() = SwitchedAggregateDef::meta;
			SwitchedAggregateDef::meta_Member_children = Uml::CompositionChildRole::Create(comp);
			SwitchedAggregateDef::meta_Member_children.name() = "Member";
			SwitchedAggregateDef::meta_Member_children.min() = 1;
			SwitchedAggregateDef::meta_Member_children.max() = -1;
			SwitchedAggregateDef::meta_Member_children.isNavigable() = true;
			SwitchedAggregateDef::meta_Member_children.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			EnumRef::meta_Discriminator_parent = Uml::CompositionParentRole::Create(comp);
			EnumRef::meta_Discriminator_parent.name() = "Discriminator_parent";
			EnumRef::meta_Discriminator_parent.isNavigable() = true;
			EnumRef::meta_Discriminator_parent.target() = Discriminator::meta;
			Discriminator::meta_EnumRef_child = Uml::CompositionChildRole::Create(comp);
			Discriminator::meta_EnumRef_child.name() = "EnumRef";
			Discriminator::meta_EnumRef_child.min() = 0;
			Discriminator::meta_EnumRef_child.max() = 1;
			Discriminator::meta_EnumRef_child.isNavigable() = true;
			Discriminator::meta_EnumRef_child.target() = EnumRef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PredefinedType::meta_Discriminator_parent = Uml::CompositionParentRole::Create(comp);
			PredefinedType::meta_Discriminator_parent.name() = "Discriminator_parent";
			PredefinedType::meta_Discriminator_parent.isNavigable() = true;
			PredefinedType::meta_Discriminator_parent.target() = Discriminator::meta;
			Discriminator::meta_PredefinedType_child = Uml::CompositionChildRole::Create(comp);
			Discriminator::meta_PredefinedType_child.name() = "PredefinedType";
			Discriminator::meta_PredefinedType_child.min() = 0;
			Discriminator::meta_PredefinedType_child.max() = 1;
			Discriminator::meta_PredefinedType_child.isNavigable() = true;
			Discriminator::meta_PredefinedType_child.target() = PredefinedType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_BoxedDef_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_BoxedDef_parent.name() = "BoxedDef_parent";
			Member::meta_BoxedDef_parent.isNavigable() = true;
			Member::meta_BoxedDef_parent.target() = BoxedDef::meta;
			BoxedDef::meta_Member_child = Uml::CompositionChildRole::Create(comp);
			BoxedDef::meta_Member_child.name() = "Member";
			BoxedDef::meta_Member_child.min() = 1;
			BoxedDef::meta_Member_child.max() = 1;
			BoxedDef::meta_Member_child.isNavigable() = true;
			BoxedDef::meta_Member_child.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_ExceptionDef_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_ExceptionDef_parent.name() = "ExceptionDef_parent";
			Member::meta_ExceptionDef_parent.isNavigable() = true;
			Member::meta_ExceptionDef_parent.target() = ExceptionDef::meta;
			ExceptionDef::meta_Member_children = Uml::CompositionChildRole::Create(comp);
			ExceptionDef::meta_Member_children.name() = "Member";
			ExceptionDef::meta_Member_children.min() = 0;
			ExceptionDef::meta_Member_children.max() = -1;
			ExceptionDef::meta_Member_children.isNavigable() = true;
			ExceptionDef::meta_Member_children.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_CollectionType_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_CollectionType_parent.name() = "CollectionType_parent";
			Member::meta_CollectionType_parent.isNavigable() = true;
			Member::meta_CollectionType_parent.target() = CollectionType::meta;
			CollectionType::meta_Member_child = Uml::CompositionChildRole::Create(comp);
			CollectionType::meta_Member_child.name() = "Member";
			CollectionType::meta_Member_child.min() = 1;
			CollectionType::meta_Member_child.max() = 1;
			CollectionType::meta_Member_child.isNavigable() = true;
			CollectionType::meta_Member_child.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_ReadonlyAttribute_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_ReadonlyAttribute_parent.name() = "ReadonlyAttribute_parent";
			Member::meta_ReadonlyAttribute_parent.isNavigable() = true;
			Member::meta_ReadonlyAttribute_parent.target() = ReadonlyAttribute::meta;
			ReadonlyAttribute::meta_Member_child = Uml::CompositionChildRole::Create(comp);
			ReadonlyAttribute::meta_Member_child.name() = "Member";
			ReadonlyAttribute::meta_Member_child.min() = 1;
			ReadonlyAttribute::meta_Member_child.max() = 1;
			ReadonlyAttribute::meta_Member_child.isNavigable() = true;
			ReadonlyAttribute::meta_Member_child.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Member::meta_ObjectByValue_parent = Uml::CompositionParentRole::Create(comp);
			Member::meta_ObjectByValue_parent.name() = "ObjectByValue_parent";
			Member::meta_ObjectByValue_parent.isNavigable() = true;
			Member::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
			ObjectByValue::meta_Member_children = Uml::CompositionChildRole::Create(comp);
			ObjectByValue::meta_Member_children.name() = "Member";
			ObjectByValue::meta_Member_children.min() = 0;
			ObjectByValue::meta_Member_children.max() = -1;
			ObjectByValue::meta_Member_children.isNavigable() = true;
			ObjectByValue::meta_Member_children.target() = Member::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ParameterType::meta_Parameter_parent = Uml::CompositionParentRole::Create(comp);
			ParameterType::meta_Parameter_parent.name() = "Parameter_parent";
			ParameterType::meta_Parameter_parent.isNavigable() = true;
			ParameterType::meta_Parameter_parent.target() = Parameter::meta;
			Parameter::meta_ParameterType_child = Uml::CompositionChildRole::Create(comp);
			Parameter::meta_ParameterType_child.name() = "ParameterType";
			Parameter::meta_ParameterType_child.min() = 1;
			Parameter::meta_ParameterType_child.max() = 1;
			Parameter::meta_ParameterType_child.isNavigable() = true;
			Parameter::meta_ParameterType_child.target() = ParameterType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			EnumRef::meta_ConstantDef_parent = Uml::CompositionParentRole::Create(comp);
			EnumRef::meta_ConstantDef_parent.name() = "ConstantDef_parent";
			EnumRef::meta_ConstantDef_parent.isNavigable() = true;
			EnumRef::meta_ConstantDef_parent.target() = ConstantDef::meta;
			ConstantDef::meta_EnumRef_child = Uml::CompositionChildRole::Create(comp);
			ConstantDef::meta_EnumRef_child.name() = "EnumRef";
			ConstantDef::meta_EnumRef_child.min() = 0;
			ConstantDef::meta_EnumRef_child.max() = 1;
			ConstantDef::meta_EnumRef_child.isNavigable() = true;
			ConstantDef::meta_EnumRef_child.target() = EnumRef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ReturnType::meta_TwowayOperation_parent = Uml::CompositionParentRole::Create(comp);
			ReturnType::meta_TwowayOperation_parent.name() = "TwowayOperation_parent";
			ReturnType::meta_TwowayOperation_parent.isNavigable() = true;
			ReturnType::meta_TwowayOperation_parent.target() = TwowayOperation::meta;
			TwowayOperation::meta_ReturnType_children = Uml::CompositionChildRole::Create(comp);
			TwowayOperation::meta_ReturnType_children.name() = "ReturnType";
			TwowayOperation::meta_ReturnType_children.min() = 0;
			TwowayOperation::meta_ReturnType_children.max() = -1;
			TwowayOperation::meta_ReturnType_children.isNavigable() = true;
			TwowayOperation::meta_ReturnType_children.target() = ReturnType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			InParameter::meta_OperationBase_parent = Uml::CompositionParentRole::Create(comp);
			InParameter::meta_OperationBase_parent.name() = "OperationBase_parent";
			InParameter::meta_OperationBase_parent.isNavigable() = true;
			InParameter::meta_OperationBase_parent.target() = OperationBase::meta;
			OperationBase::meta_InParameter_children = Uml::CompositionChildRole::Create(comp);
			OperationBase::meta_InParameter_children.name() = "InParameter";
			OperationBase::meta_InParameter_children.min() = 0;
			OperationBase::meta_InParameter_children.max() = -1;
			OperationBase::meta_InParameter_children.isNavigable() = true;
			OperationBase::meta_InParameter_children.target() = InParameter::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			InoutParameter::meta_TwowayOperation_parent = Uml::CompositionParentRole::Create(comp);
			InoutParameter::meta_TwowayOperation_parent.name() = "TwowayOperation_parent";
			InoutParameter::meta_TwowayOperation_parent.isNavigable() = true;
			InoutParameter::meta_TwowayOperation_parent.target() = TwowayOperation::meta;
			TwowayOperation::meta_InoutParameter_children = Uml::CompositionChildRole::Create(comp);
			TwowayOperation::meta_InoutParameter_children.name() = "InoutParameter";
			TwowayOperation::meta_InoutParameter_children.min() = 0;
			TwowayOperation::meta_InoutParameter_children.max() = -1;
			TwowayOperation::meta_InoutParameter_children.isNavigable() = true;
			TwowayOperation::meta_InoutParameter_children.target() = InoutParameter::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			OutParameter::meta_TwowayOperation_parent = Uml::CompositionParentRole::Create(comp);
			OutParameter::meta_TwowayOperation_parent.name() = "TwowayOperation_parent";
			OutParameter::meta_TwowayOperation_parent.isNavigable() = true;
			OutParameter::meta_TwowayOperation_parent.target() = TwowayOperation::meta;
			TwowayOperation::meta_OutParameter_children = Uml::CompositionChildRole::Create(comp);
			TwowayOperation::meta_OutParameter_children.name() = "OutParameter";
			TwowayOperation::meta_OutParameter_children.min() = 0;
			TwowayOperation::meta_OutParameter_children.max() = -1;
			TwowayOperation::meta_OutParameter_children.isNavigable() = true;
			TwowayOperation::meta_OutParameter_children.target() = OutParameter::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			OnewayOperation::meta_HasOperations_parent = Uml::CompositionParentRole::Create(comp);
			OnewayOperation::meta_HasOperations_parent.name() = "HasOperations_parent";
			OnewayOperation::meta_HasOperations_parent.isNavigable() = true;
			OnewayOperation::meta_HasOperations_parent.target() = HasOperations::meta;
			HasOperations::meta_OnewayOperation_children = Uml::CompositionChildRole::Create(comp);
			HasOperations::meta_OnewayOperation_children.name() = "OnewayOperation";
			HasOperations::meta_OnewayOperation_children.min() = 0;
			HasOperations::meta_OnewayOperation_children.max() = -1;
			HasOperations::meta_OnewayOperation_children.isNavigable() = true;
			HasOperations::meta_OnewayOperation_children.target() = OnewayOperation::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ExceptionRef::meta_HasExceptions_parent = Uml::CompositionParentRole::Create(comp);
			ExceptionRef::meta_HasExceptions_parent.name() = "HasExceptions_parent";
			ExceptionRef::meta_HasExceptions_parent.isNavigable() = true;
			ExceptionRef::meta_HasExceptions_parent.target() = HasExceptions::meta;
			HasExceptions::meta_ExceptionRef_children = Uml::CompositionChildRole::Create(comp);
			HasExceptions::meta_ExceptionRef_children.name() = "ExceptionRef";
			HasExceptions::meta_ExceptionRef_children.min() = 0;
			HasExceptions::meta_ExceptionRef_children.max() = -1;
			HasExceptions::meta_ExceptionRef_children.isNavigable() = true;
			HasExceptions::meta_ExceptionRef_children.target() = ExceptionRef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			LookupOperation::meta_ComponentFactory_parent = Uml::CompositionParentRole::Create(comp);
			LookupOperation::meta_ComponentFactory_parent.name() = "ComponentFactory_parent";
			LookupOperation::meta_ComponentFactory_parent.isNavigable() = true;
			LookupOperation::meta_ComponentFactory_parent.target() = ComponentFactory::meta;
			ComponentFactory::meta_LookupOperation_children = Uml::CompositionChildRole::Create(comp);
			ComponentFactory::meta_LookupOperation_children.name() = "LookupOperation";
			ComponentFactory::meta_LookupOperation_children.min() = 0;
			ComponentFactory::meta_LookupOperation_children.max() = -1;
			ComponentFactory::meta_LookupOperation_children.isNavigable() = true;
			ComponentFactory::meta_LookupOperation_children.target() = LookupOperation::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			FactoryOperation::meta_ObjectByValue_parent = Uml::CompositionParentRole::Create(comp);
			FactoryOperation::meta_ObjectByValue_parent.name() = "ObjectByValue_parent";
			FactoryOperation::meta_ObjectByValue_parent.isNavigable() = true;
			FactoryOperation::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
			ObjectByValue::meta_FactoryOperation_children = Uml::CompositionChildRole::Create(comp);
			ObjectByValue::meta_FactoryOperation_children.name() = "FactoryOperation";
			ObjectByValue::meta_FactoryOperation_children.min() = 0;
			ObjectByValue::meta_FactoryOperation_children.max() = -1;
			ObjectByValue::meta_FactoryOperation_children.isNavigable() = true;
			ObjectByValue::meta_FactoryOperation_children.target() = FactoryOperation::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			FactoryOperation::meta_ComponentFactory_parent = Uml::CompositionParentRole::Create(comp);
			FactoryOperation::meta_ComponentFactory_parent.name() = "ComponentFactory_parent";
			FactoryOperation::meta_ComponentFactory_parent.isNavigable() = true;
			FactoryOperation::meta_ComponentFactory_parent.target() = ComponentFactory::meta;
			ComponentFactory::meta_FactoryOperation_children = Uml::CompositionChildRole::Create(comp);
			ComponentFactory::meta_FactoryOperation_children.name() = "FactoryOperation";
			ComponentFactory::meta_FactoryOperation_children.min() = 0;
			ComponentFactory::meta_FactoryOperation_children.max() = -1;
			ComponentFactory::meta_FactoryOperation_children.isNavigable() = true;
			ComponentFactory::meta_FactoryOperation_children.target() = FactoryOperation::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			TwowayOperation::meta_HasOperations_parent = Uml::CompositionParentRole::Create(comp);
			TwowayOperation::meta_HasOperations_parent.name() = "HasOperations_parent";
			TwowayOperation::meta_HasOperations_parent.isNavigable() = true;
			TwowayOperation::meta_HasOperations_parent.target() = HasOperations::meta;
			HasOperations::meta_TwowayOperation_children = Uml::CompositionChildRole::Create(comp);
			HasOperations::meta_TwowayOperation_children.name() = "TwowayOperation";
			HasOperations::meta_TwowayOperation_children.min() = 0;
			HasOperations::meta_TwowayOperation_children.max() = -1;
			HasOperations::meta_TwowayOperation_children.isNavigable() = true;
			HasOperations::meta_TwowayOperation_children.target() = TwowayOperation::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ConstantDef::meta_Package_parent = Uml::CompositionParentRole::Create(comp);
			ConstantDef::meta_Package_parent.name() = "Package_parent";
			ConstantDef::meta_Package_parent.isNavigable() = true;
			ConstantDef::meta_Package_parent.target() = Package::meta;
			Package::meta_ConstantDef_children = Uml::CompositionChildRole::Create(comp);
			Package::meta_ConstantDef_children.name() = "ConstantDef";
			Package::meta_ConstantDef_children.min() = 0;
			Package::meta_ConstantDef_children.max() = -1;
			Package::meta_ConstantDef_children.isNavigable() = true;
			Package::meta_ConstantDef_children.target() = ConstantDef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Package::meta_Package_parent = Uml::CompositionParentRole::Create(comp);
			Package::meta_Package_parent.name() = "Package_parent";
			Package::meta_Package_parent.isNavigable() = true;
			Package::meta_Package_parent.target() = Package::meta;
			Package::meta_Package_children = Uml::CompositionChildRole::Create(comp);
			Package::meta_Package_children.name() = "Package";
			Package::meta_Package_children.min() = 0;
			Package::meta_Package_children.max() = -1;
			Package::meta_Package_children.isNavigable() = true;
			Package::meta_Package_children.target() = Package::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ExceptionDef::meta_Package_parent = Uml::CompositionParentRole::Create(comp);
			ExceptionDef::meta_Package_parent.name() = "Package_parent";
			ExceptionDef::meta_Package_parent.isNavigable() = true;
			ExceptionDef::meta_Package_parent.target() = Package::meta;
			Package::meta_ExceptionDef_children = Uml::CompositionChildRole::Create(comp);
			Package::meta_ExceptionDef_children.name() = "ExceptionDef";
			Package::meta_ExceptionDef_children.min() = 0;
			Package::meta_ExceptionDef_children.max() = -1;
			Package::meta_ExceptionDef_children.isNavigable() = true;
			Package::meta_ExceptionDef_children.target() = ExceptionDef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			BoundedString::meta_ConstantDef_parent = Uml::CompositionParentRole::Create(comp);
			BoundedString::meta_ConstantDef_parent.name() = "ConstantDef_parent";
			BoundedString::meta_ConstantDef_parent.isNavigable() = true;
			BoundedString::meta_ConstantDef_parent.target() = ConstantDef::meta;
			ConstantDef::meta_BoundedString_child = Uml::CompositionChildRole::Create(comp);
			ConstantDef::meta_BoundedString_child.name() = "BoundedString";
			ConstantDef::meta_BoundedString_child.min() = 0;
			ConstantDef::meta_BoundedString_child.max() = 1;
			ConstantDef::meta_BoundedString_child.isNavigable() = true;
			ConstantDef::meta_BoundedString_child.target() = BoundedString::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PredefinedType::meta_ConstantDef_parent = Uml::CompositionParentRole::Create(comp);
			PredefinedType::meta_ConstantDef_parent.name() = "ConstantDef_parent";
			PredefinedType::meta_ConstantDef_parent.isNavigable() = true;
			PredefinedType::meta_ConstantDef_parent.target() = ConstantDef::meta;
			ConstantDef::meta_PredefinedType_child = Uml::CompositionChildRole::Create(comp);
			ConstantDef::meta_PredefinedType_child.name() = "PredefinedType";
			ConstantDef::meta_PredefinedType_child.min() = 0;
			ConstantDef::meta_PredefinedType_child.max() = 1;
			ConstantDef::meta_PredefinedType_child.isNavigable() = true;
			ConstantDef::meta_PredefinedType_child.target() = PredefinedType::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			FixedPoint::meta_ConstantDef_parent = Uml::CompositionParentRole::Create(comp);
			FixedPoint::meta_ConstantDef_parent.name() = "ConstantDef_parent";
			FixedPoint::meta_ConstantDef_parent.isNavigable() = true;
			FixedPoint::meta_ConstantDef_parent.target() = ConstantDef::meta;
			ConstantDef::meta_FixedPoint_child = Uml::CompositionChildRole::Create(comp);
			ConstantDef::meta_FixedPoint_child.name() = "FixedPoint";
			ConstantDef::meta_FixedPoint_child.min() = 0;
			ConstantDef::meta_FixedPoint_child.max() = 1;
			ConstantDef::meta_FixedPoint_child.isNavigable() = true;
			ConstantDef::meta_FixedPoint_child.target() = FixedPoint::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ConstantDef::meta_HasOperations_parent = Uml::CompositionParentRole::Create(comp);
			ConstantDef::meta_HasOperations_parent.name() = "HasOperations_parent";
			ConstantDef::meta_HasOperations_parent.isNavigable() = true;
			ConstantDef::meta_HasOperations_parent.target() = HasOperations::meta;
			HasOperations::meta_ConstantDef_children = Uml::CompositionChildRole::Create(comp);
			HasOperations::meta_ConstantDef_children.name() = "ConstantDef";
			HasOperations::meta_ConstantDef_children.min() = 0;
			HasOperations::meta_ConstantDef_children.max() = -1;
			HasOperations::meta_ConstantDef_children.isNavigable() = true;
			HasOperations::meta_ConstantDef_children.target() = ConstantDef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ExceptionDef::meta_HasOperations_parent = Uml::CompositionParentRole::Create(comp);
			ExceptionDef::meta_HasOperations_parent.name() = "HasOperations_parent";
			ExceptionDef::meta_HasOperations_parent.isNavigable() = true;
			ExceptionDef::meta_HasOperations_parent.target() = HasOperations::meta;
			HasOperations::meta_ExceptionDef_children = Uml::CompositionChildRole::Create(comp);
			HasOperations::meta_ExceptionDef_children.name() = "ExceptionDef";
			HasOperations::meta_ExceptionDef_children.min() = 0;
			HasOperations::meta_ExceptionDef_children.max() = -1;
			HasOperations::meta_ExceptionDef_children.isNavigable() = true;
			HasOperations::meta_ExceptionDef_children.target() = ExceptionDef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			EventRef::meta_EventPort_parent = Uml::CompositionParentRole::Create(comp);
			EventRef::meta_EventPort_parent.name() = "EventPort_parent";
			EventRef::meta_EventPort_parent.isNavigable() = true;
			EventRef::meta_EventPort_parent.target() = EventPort::meta;
			EventPort::meta_EventRef_child = Uml::CompositionChildRole::Create(comp);
			EventPort::meta_EventRef_child.name() = "EventRef";
			EventPort::meta_EventRef_child.min() = 1;
			EventPort::meta_EventRef_child.max() = 1;
			EventPort::meta_EventRef_child.isNavigable() = true;
			EventPort::meta_EventRef_child.target() = EventRef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ObjectRef::meta_RequestPort_parent = Uml::CompositionParentRole::Create(comp);
			ObjectRef::meta_RequestPort_parent.name() = "RequestPort_parent";
			ObjectRef::meta_RequestPort_parent.isNavigable() = true;
			ObjectRef::meta_RequestPort_parent.target() = RequestPort::meta;
			RequestPort::meta_ObjectRef_child = Uml::CompositionChildRole::Create(comp);
			RequestPort::meta_ObjectRef_child.name() = "ObjectRef";
			RequestPort::meta_ObjectRef_child.min() = 1;
			RequestPort::meta_ObjectRef_child.max() = 1;
			RequestPort::meta_ObjectRef_child.isNavigable() = true;
			RequestPort::meta_ObjectRef_child.target() = ObjectRef::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Port::meta_ComponentDef_parent = Uml::CompositionParentRole::Create(comp);
			Port::meta_ComponentDef_parent.name() = "ComponentDef_parent";
			Port::meta_ComponentDef_parent.isNavigable() = true;
			Port::meta_ComponentDef_parent.target() = ComponentDef::meta;
			ComponentDef::meta_Port_children = Uml::CompositionChildRole::Create(comp);
			ComponentDef::meta_Port_children.name() = "Port";
			ComponentDef::meta_Port_children.min() = 0;
			ComponentDef::meta_Port_children.max() = -1;
			ComponentDef::meta_Port_children.isNavigable() = true;
			ComponentDef::meta_Port_children.target() = Port::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ReadonlyAttribute::meta_Inheritable_parent = Uml::CompositionParentRole::Create(comp);
			ReadonlyAttribute::meta_Inheritable_parent.name() = "Inheritable_parent";
			ReadonlyAttribute::meta_Inheritable_parent.isNavigable() = true;
			ReadonlyAttribute::meta_Inheritable_parent.target() = Inheritable::meta;
			Inheritable::meta_ReadonlyAttribute_children = Uml::CompositionChildRole::Create(comp);
			Inheritable::meta_ReadonlyAttribute_children.name() = "ReadonlyAttribute";
			Inheritable::meta_ReadonlyAttribute_children.min() = 0;
			Inheritable::meta_ReadonlyAttribute_children.max() = -1;
			Inheritable::meta_ReadonlyAttribute_children.isNavigable() = true;
			Inheritable::meta_ReadonlyAttribute_children.target() = ReadonlyAttribute::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Inherits::meta_Inheritable_parent = Uml::CompositionParentRole::Create(comp);
			Inherits::meta_Inheritable_parent.name() = "Inheritable_parent";
			Inherits::meta_Inheritable_parent.isNavigable() = true;
			Inherits::meta_Inheritable_parent.target() = Inheritable::meta;
			Inheritable::meta_Inherits_children = Uml::CompositionChildRole::Create(comp);
			Inheritable::meta_Inherits_children.name() = "Inherits";
			Inheritable::meta_Inherits_children.min() = 0;
			Inheritable::meta_Inherits_children.max() = -1;
			Inheritable::meta_Inherits_children.isNavigable() = true;
			Inheritable::meta_Inherits_children.target() = Inherits::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Supports::meta_SupportsInterfaces_parent = Uml::CompositionParentRole::Create(comp);
			Supports::meta_SupportsInterfaces_parent.name() = "SupportsInterfaces_parent";
			Supports::meta_SupportsInterfaces_parent.isNavigable() = true;
			Supports::meta_SupportsInterfaces_parent.target() = SupportsInterfaces::meta;
			SupportsInterfaces::meta_Supports_children = Uml::CompositionChildRole::Create(comp);
			SupportsInterfaces::meta_Supports_children.name() = "Supports";
			SupportsInterfaces::meta_Supports_children.min() = 0;
			SupportsInterfaces::meta_Supports_children.max() = -1;
			SupportsInterfaces::meta_Supports_children.isNavigable() = true;
			SupportsInterfaces::meta_Supports_children.target() = Supports::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Manages::meta_ComponentFactory_parent = Uml::CompositionParentRole::Create(comp);
			Manages::meta_ComponentFactory_parent.name() = "ComponentFactory_parent";
			Manages::meta_ComponentFactory_parent.isNavigable() = true;
			Manages::meta_ComponentFactory_parent.target() = ComponentFactory::meta;
			ComponentFactory::meta_Manages_child = Uml::CompositionChildRole::Create(comp);
			ComponentFactory::meta_Manages_child.name() = "Manages";
			ComponentFactory::meta_Manages_child.min() = 1;
			ComponentFactory::meta_Manages_child.max() = 1;
			ComponentFactory::meta_Manages_child.isNavigable() = true;
			ComponentFactory::meta_Manages_child.target() = Manages::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			LookupKey::meta_ComponentFactory_parent = Uml::CompositionParentRole::Create(comp);
			LookupKey::meta_ComponentFactory_parent.name() = "ComponentFactory_parent";
			LookupKey::meta_ComponentFactory_parent.isNavigable() = true;
			LookupKey::meta_ComponentFactory_parent.target() = ComponentFactory::meta;
			ComponentFactory::meta_LookupKey_child = Uml::CompositionChildRole::Create(comp);
			ComponentFactory::meta_LookupKey_child.name() = "LookupKey";
			ComponentFactory::meta_LookupKey_child.min() = 0;
			ComponentFactory::meta_LookupKey_child.max() = 1;
			ComponentFactory::meta_LookupKey_child.isNavigable() = true;
			ComponentFactory::meta_LookupKey_child.target() = LookupKey::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PrivateFlag::meta_ObjectByValue_parent = Uml::CompositionParentRole::Create(comp);
			PrivateFlag::meta_ObjectByValue_parent.name() = "ObjectByValue_parent";
			PrivateFlag::meta_ObjectByValue_parent.isNavigable() = true;
			PrivateFlag::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
			ObjectByValue::meta_PrivateFlag_children = Uml::CompositionChildRole::Create(comp);
			ObjectByValue::meta_PrivateFlag_children.name() = "PrivateFlag";
			ObjectByValue::meta_PrivateFlag_children.min() = 0;
			ObjectByValue::meta_PrivateFlag_children.max() = -1;
			ObjectByValue::meta_PrivateFlag_children.isNavigable() = true;
			ObjectByValue::meta_PrivateFlag_children.target() = PrivateFlag::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			MakeMemberPrivate::meta_ObjectByValue_parent = Uml::CompositionParentRole::Create(comp);
			MakeMemberPrivate::meta_ObjectByValue_parent.name() = "ObjectByValue_parent";
			MakeMemberPrivate::meta_ObjectByValue_parent.isNavigable() = true;
			MakeMemberPrivate::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
			ObjectByValue::meta_MakeMemberPrivate_children = Uml::CompositionChildRole::Create(comp);
			ObjectByValue::meta_MakeMemberPrivate_children.name() = "MakeMemberPrivate";
			ObjectByValue::meta_MakeMemberPrivate_children.min() = 0;
			ObjectByValue::meta_MakeMemberPrivate_children.max() = -1;
			ObjectByValue::meta_MakeMemberPrivate_children.isNavigable() = true;
			ObjectByValue::meta_MakeMemberPrivate_children.target() = MakeMemberPrivate::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			GetException::meta_ReadonlyAttribute_parent = Uml::CompositionParentRole::Create(comp);
			GetException::meta_ReadonlyAttribute_parent.name() = "ReadonlyAttribute_parent";
			GetException::meta_ReadonlyAttribute_parent.isNavigable() = true;
			GetException::meta_ReadonlyAttribute_parent.target() = ReadonlyAttribute::meta;
			ReadonlyAttribute::meta_GetException_children = Uml::CompositionChildRole::Create(comp);
			ReadonlyAttribute::meta_GetException_children.name() = "GetException";
			ReadonlyAttribute::meta_GetException_children.min() = 0;
			ReadonlyAttribute::meta_GetException_children.max() = -1;
			ReadonlyAttribute::meta_GetException_children.isNavigable() = true;
			ReadonlyAttribute::meta_GetException_children.target() = GetException::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			SetException::meta_Attribute_parent = Uml::CompositionParentRole::Create(comp);
			SetException::meta_Attribute_parent.name() = "Attribute_parent";
			SetException::meta_Attribute_parent.isNavigable() = true;
			SetException::meta_Attribute_parent.target() = Attribute::meta;
			Attribute::meta_SetException_children = Uml::CompositionChildRole::Create(comp);
			Attribute::meta_SetException_children.name() = "SetException";
			Attribute::meta_SetException_children.min() = 0;
			Attribute::meta_SetException_children.max() = -1;
			Attribute::meta_SetException_children.isNavigable() = true;
			Attribute::meta_SetException_children.target() = SetException::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			RootFolder::meta_RootFolder_parent = Uml::CompositionParentRole::Create(comp);
			RootFolder::meta_RootFolder_parent.name() = "RootFolder_parent";
			RootFolder::meta_RootFolder_parent.isNavigable() = true;
			RootFolder::meta_RootFolder_parent.target() = RootFolder::meta;
			RootFolder::meta_RootFolder_children = Uml::CompositionChildRole::Create(comp);
			RootFolder::meta_RootFolder_children.name() = "RootFolder";
			RootFolder::meta_RootFolder_children.min() = 0;
			RootFolder::meta_RootFolder_children.max() = -1;
			RootFolder::meta_RootFolder_children.isNavigable() = true;
			RootFolder::meta_RootFolder_children.target() = RootFolder::meta;
		}
		CommonPortAttrs::meta.subTypes() +=  Port::meta;
		ComponentImplementation::meta.subTypes() +=  MonolithicImplementation::meta;
		ComponentImplementation::meta.subTypes() +=  ComponentAssembly::meta;
		RequirementBase::meta.subTypes() +=  ImplementationRequirement::meta;
		RequirementBase::meta.subTypes() +=  Requirement::meta;
		RequirementSatisfier::meta.subTypes() +=  Capability::meta;
		NamedType::meta.subTypes() +=  BoxedDef::meta;
		NamedType::meta.subTypes() +=  NoInheritable::meta;
		NamedType::meta.subTypes() +=  Inheritable::meta;
		Member::meta.subTypes() +=  NamedTypeRef::meta;
		Member::meta.subTypes() +=  AnonymousType::meta;
		NoInheritable::meta.subTypes() +=  EnumerationDef::meta;
		NoInheritable::meta.subTypes() +=  AliasDef::meta;
		NoInheritable::meta.subTypes() +=  AggregateDef::meta;
		NoInheritable::meta.subTypes() +=  SwitchedAggregateDef::meta;
		IdTag::meta.subTypes() +=  PrefixTag::meta;
		IdTag::meta.subTypes() +=  GeneralTag::meta;
		GeneralTag::meta.subTypes() +=  SpecifyIdTag::meta;
		GeneralTag::meta.subTypes() +=  VersionTag::meta;
		Prefixable::meta.subTypes() +=  IDLFile::meta;
		Prefixable::meta.subTypes() +=  Package::meta;
		Prefixable::meta.subTypes() +=  ObjectDef::meta;
		Prefixable::meta.subTypes() +=  ObjectByValue::meta;
		Taggable::meta.subTypes() +=  NamedType::meta;
		Taggable::meta.subTypes() +=  OperationBase::meta;
		Taggable::meta.subTypes() +=  Package::meta;
		Taggable::meta.subTypes() +=  ConstantDef::meta;
		Taggable::meta.subTypes() +=  ExceptionDef::meta;
		Taggable::meta.subTypes() +=  Port::meta;
		Taggable::meta.subTypes() +=  Attribute::meta;
		ParameterType::meta.subTypes() +=  NamedTypeRef::meta;
		ParameterType::meta.subTypes() +=  PredefinedType::meta;
		OperationBase::meta.subTypes() +=  HasExceptions::meta;
		OperationBase::meta.subTypes() +=  OnewayOperation::meta;
		Parameter::meta.subTypes() +=  ReturnType::meta;
		Parameter::meta.subTypes() +=  InParameter::meta;
		Parameter::meta.subTypes() +=  InoutParameter::meta;
		Parameter::meta.subTypes() +=  OutParameter::meta;
		HasExceptions::meta.subTypes() +=  LookupOperation::meta;
		HasExceptions::meta.subTypes() +=  FactoryOperation::meta;
		HasExceptions::meta.subTypes() +=  TwowayOperation::meta;
		Type::meta.subTypes() +=  NamedType::meta;
		Type::meta.subTypes() +=  AnonymousType::meta;
		RequestPort::meta.subTypes() +=  ProvidedRequestPort::meta;
		RequestPort::meta.subTypes() +=  RequiredRequestPort::meta;
		EventPort::meta.subTypes() +=  OutEventPort::meta;
		EventPort::meta.subTypes() +=  InEventPort::meta;
		Port::meta.subTypes() +=  RequestPort::meta;
		Port::meta.subTypes() +=  EventPort::meta;
		AnonymousType::meta.subTypes() +=  BoundedString::meta;
		AnonymousType::meta.subTypes() +=  CollectionType::meta;
		AnonymousType::meta.subTypes() +=  PredefinedType::meta;
		AnonymousType::meta.subTypes() +=  FixedPoint::meta;
		CollectionType::meta.subTypes() +=  FixedSizeCollection::meta;
		CollectionType::meta.subTypes() +=  VariableSizeCollection::meta;
		Inheritable::meta.subTypes() +=  HasOperations::meta;
		Inheritable::meta.subTypes() +=  SupportsInterfaces::meta;
		HasOperations::meta.subTypes() +=  ObjectDef::meta;
		HasOperations::meta.subTypes() +=  ComponentFactory::meta;
		HasOperations::meta.subTypes() +=  ObjectByValue::meta;
		SupportsInterfaces::meta.subTypes() +=  ComponentDef::meta;
		SupportsInterfaces::meta.subTypes() +=  ComponentFactory::meta;
		SupportsInterfaces::meta.subTypes() +=  ObjectByValue::meta;
		ReadonlyAttribute::meta.subTypes() +=  Attribute::meta;
		ObjectByValue::meta.subTypes() +=  EventDef::meta;
		ObjectByValue::meta.subTypes() +=  ValueDef::meta;
		MgaObject::meta.subTypes() +=  ImplementationArtifactReference::meta;
		MgaObject::meta.subTypes() +=  ArtifactDependsOn::meta;
		MgaObject::meta.subTypes() +=  ArtifactDeployRequirement::meta;
		MgaObject::meta.subTypes() +=  ArtifactContainer::meta;
		MgaObject::meta.subTypes() +=  ArtifactExecParameter::meta;
		MgaObject::meta.subTypes() +=  ArtifactInfoProperty::meta;
		MgaObject::meta.subTypes() +=  ImplementationArtifact::meta;
		MgaObject::meta.subTypes() +=  ComponentType::meta;
		MgaObject::meta.subTypes() +=  ComponentConfigProperty::meta;
		MgaObject::meta.subTypes() +=  ComponentInfoProperty::meta;
		MgaObject::meta.subTypes() +=  CommonPortAttrs::meta;
		MgaObject::meta.subTypes() +=  ComponentPropertyDescription::meta;
		MgaObject::meta.subTypes() +=  ComponentProperty::meta;
		MgaObject::meta.subTypes() +=  ComponentContainer::meta;
		MgaObject::meta.subTypes() +=  ImplementationCapability::meta;
		MgaObject::meta.subTypes() +=  ImplementationDependsOn::meta;
		MgaObject::meta.subTypes() +=  Implements::meta;
		MgaObject::meta.subTypes() +=  ComponentImplementationReference::meta;
		MgaObject::meta.subTypes() +=  ConfigProperty::meta;
		MgaObject::meta.subTypes() +=  InfoProperty::meta;
		MgaObject::meta.subTypes() +=  MonolithprimaryArtifact::meta;
		MgaObject::meta.subTypes() +=  MonolithDeployRequirement::meta;
		MgaObject::meta.subTypes() +=  ComponentImplementation::meta;
		MgaObject::meta.subTypes() +=  ComponentImplementationContainer::meta;
		MgaObject::meta.subTypes() +=  MonolithExecParameter::meta;
		MgaObject::meta.subTypes() +=  RequirementBase::meta;
		MgaObject::meta.subTypes() +=  ImplementationDependency::meta;
		MgaObject::meta.subTypes() +=  Any::meta;
		MgaObject::meta.subTypes() +=  Property::meta;
		MgaObject::meta.subTypes() +=  SatisfierProperty::meta;
		MgaObject::meta.subTypes() +=  DataType::meta;
		MgaObject::meta.subTypes() +=  RequirementSatisfier::meta;
		MgaObject::meta.subTypes() +=  PackageBaseConnection::meta;
		MgaObject::meta.subTypes() +=  PackageReferenceConnection::meta;
		MgaObject::meta.subTypes() +=  PackageConfigurationReference::meta;
		MgaObject::meta.subTypes() +=  PackageConfiguration::meta;
		MgaObject::meta.subTypes() +=  PackageConfigurationContainer::meta;
		MgaObject::meta.subTypes() +=  PackageConfigurationProperty::meta;
		MgaObject::meta.subTypes() +=  PackageSelectRequirement::meta;
		MgaObject::meta.subTypes() +=  EmitConnector::meta;
		MgaObject::meta.subTypes() +=  Invocation::meta;
		MgaObject::meta.subTypes() +=  SubComponentSelectRequirement::meta;
		MgaObject::meta.subTypes() +=  SubComponentConfigProperty::meta;
		MgaObject::meta.subTypes() +=  PublishConnector::meta;
		MgaObject::meta.subTypes() +=  OutEventPortPublish::meta;
		MgaObject::meta.subTypes() +=  InEventPortConsume::meta;
		MgaObject::meta.subTypes() +=  ConnectionRequirements::meta;
		MgaObject::meta.subTypes() +=  PackageInterface::meta;
		MgaObject::meta.subTypes() +=  PackageImplementations::meta;
		MgaObject::meta.subTypes() +=  PackageContainer::meta;
		MgaObject::meta.subTypes() +=  PackageConfigProperty::meta;
		MgaObject::meta.subTypes() +=  PackageInfoProperty::meta;
		MgaObject::meta.subTypes() +=  ComponentPackage::meta;
		MgaObject::meta.subTypes() +=  ComponentPackageReference::meta;
		MgaObject::meta.subTypes() +=  TopLevelPackageContainer::meta;
		MgaObject::meta.subTypes() +=  TopLevelPackage::meta;
		MgaObject::meta.subTypes() +=  TopLevelPackageConn::meta;
		MgaObject::meta.subTypes() +=  EnumValue::meta;
		MgaObject::meta.subTypes() +=  Label::meta;
		MgaObject::meta.subTypes() +=  Discriminator::meta;
		MgaObject::meta.subTypes() +=  LabelConnection::meta;
		MgaObject::meta.subTypes() +=  EnumRef::meta;
		MgaObject::meta.subTypes() +=  Member::meta;
		MgaObject::meta.subTypes() +=  IdTag::meta;
		MgaObject::meta.subTypes() +=  Prefixable::meta;
		MgaObject::meta.subTypes() +=  Taggable::meta;
		MgaObject::meta.subTypes() +=  ParameterType::meta;
		MgaObject::meta.subTypes() +=  Parameter::meta;
		MgaObject::meta.subTypes() +=  Type::meta;
		MgaObject::meta.subTypes() +=  ExceptionRef::meta;
		MgaObject::meta.subTypes() +=  FileRef::meta;
		MgaObject::meta.subTypes() +=  EventRef::meta;
		MgaObject::meta.subTypes() +=  ObjectRef::meta;
		MgaObject::meta.subTypes() +=  Inherits::meta;
		MgaObject::meta.subTypes() +=  Supports::meta;
		MgaObject::meta.subTypes() +=  ReadonlyAttribute::meta;
		MgaObject::meta.subTypes() +=  LookupKey::meta;
		MgaObject::meta.subTypes() +=  Manages::meta;
		MgaObject::meta.subTypes() +=  SetException::meta;
		MgaObject::meta.subTypes() +=  GetException::meta;
		MgaObject::meta.subTypes() +=  PrivateFlag::meta;
		MgaObject::meta.subTypes() +=  MakeMemberPrivate::meta;
		
	}
	void Initialize(const Uml::Diagram & dgr)
	{
		umldiagram = dgr;
		Uml::SetClass(ImplementationArtifactReference::meta, umldiagram, "ImplementationArtifactReference");
		Uml::SetGenericRole(ImplementationArtifactReference::meta_ArtifactContainer_parent,ImplementationArtifactReference::meta, "");
		Uml::SetGenericRole(ImplementationArtifactReference::meta_srcArtifactDependsOn,ImplementationArtifact::meta, "dstArtifactDependsOn");
		ImplementationArtifact::meta_dstArtifactDependsOn_rev = ImplementationArtifactReference::meta_srcArtifactDependsOn;
		Uml::SetGenericRole(ImplementationArtifactReference::meta_ref,ImplementationArtifact::meta, "referedbyImplementationArtifactReference");
		Uml::SetGenericRole(ImplementationArtifactReference::meta_srcMonolithprimaryArtifact,MonolithicImplementation::meta, "dstMonolithprimaryArtifact");
		MonolithicImplementation::meta_dstMonolithprimaryArtifact_rev = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;

		Uml::SetClass(ImplementationArtifacts::meta, umldiagram, "ImplementationArtifacts");
		Uml::SetAttribute(ImplementationArtifacts::meta_name,ImplementationArtifacts::meta, "name");
		Uml::SetGenericRole(ImplementationArtifacts::meta_RootFolder_parent,ImplementationArtifacts::meta, "");
		Uml::SetGenericRole(ImplementationArtifacts::meta_ArtifactContainer_children,ImplementationArtifacts::meta, "");

		Uml::SetClass(ArtifactDependsOn::meta, umldiagram, "ArtifactDependsOn");
		Uml::SetGenericRole(ArtifactDependsOn::meta_ArtifactContainer_parent,ArtifactDependsOn::meta, "");
		ArtifactDependsOn::meta_dstArtifactDependsOn_end_ = ImplementationArtifact::meta_dstArtifactDependsOn;
		ArtifactDependsOn::meta_srcArtifactDependsOn_end_ = ImplementationArtifactReference::meta_srcArtifactDependsOn;

		Uml::SetClass(ArtifactDeployRequirement::meta, umldiagram, "ArtifactDeployRequirement");
		Uml::SetGenericRole(ArtifactDeployRequirement::meta_ArtifactContainer_parent,ArtifactDeployRequirement::meta, "");
		ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_ = ImplementationArtifact::meta_dstArtifactDeployRequirement;
		ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_ = Requirement::meta_srcArtifactDeployRequirement;

		Uml::SetClass(ArtifactContainer::meta, umldiagram, "ArtifactContainer");
		Uml::SetGenericRole(ArtifactContainer::meta_ImplementationArtifacts_parent,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_ImplementationArtifactReference_children,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_ArtifactDependsOn_children,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_ArtifactDeployRequirement_children,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_Requirement_children,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_ArtifactExecParameter_children,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_ArtifactInfoProperty_children,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_Property_children,ArtifactContainer::meta, "");
		Uml::SetGenericRole(ArtifactContainer::meta_ImplementationArtifact_children,ArtifactContainer::meta, "");

		Uml::SetClass(ArtifactExecParameter::meta, umldiagram, "ArtifactExecParameter");
		Uml::SetGenericRole(ArtifactExecParameter::meta_ArtifactContainer_parent,ArtifactExecParameter::meta, "");
		ArtifactExecParameter::meta_dstArtifactExecParameter_end_ = ImplementationArtifact::meta_dstArtifactExecParameter;
		ArtifactExecParameter::meta_srcArtifactExecParameter_end_ = Property::meta_srcArtifactExecParameter;

		Uml::SetClass(ArtifactInfoProperty::meta, umldiagram, "ArtifactInfoProperty");
		Uml::SetGenericRole(ArtifactInfoProperty::meta_ArtifactContainer_parent,ArtifactInfoProperty::meta, "");
		ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_ = ImplementationArtifact::meta_dstArtifactInfoProperty;
		ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_ = Property::meta_srcArtifactInfoProperty;

		Uml::SetClass(ImplementationArtifact::meta, umldiagram, "ImplementationArtifact");
		Uml::SetGenericRole(ImplementationArtifact::meta_ArtifactContainer_parent,ImplementationArtifact::meta, "");
		Uml::SetGenericRole(ImplementationArtifact::meta_dstArtifactDependsOn,ImplementationArtifactReference::meta, "srcArtifactDependsOn");
		ImplementationArtifactReference::meta_srcArtifactDependsOn_rev = ImplementationArtifact::meta_dstArtifactDependsOn;
		Uml::SetGenericRole(ImplementationArtifact::meta_referedbyImplementationArtifactReference,ImplementationArtifactReference::meta, "ref");
		Uml::SetGenericRole(ImplementationArtifact::meta_dstArtifactDeployRequirement,Requirement::meta, "srcArtifactDeployRequirement");
		Requirement::meta_srcArtifactDeployRequirement_rev = ImplementationArtifact::meta_dstArtifactDeployRequirement;
		Uml::SetGenericRole(ImplementationArtifact::meta_dstArtifactExecParameter,Property::meta, "srcArtifactExecParameter");
		Property::meta_srcArtifactExecParameter_rev = ImplementationArtifact::meta_dstArtifactExecParameter;
		Uml::SetGenericRole(ImplementationArtifact::meta_dstArtifactInfoProperty,Property::meta, "srcArtifactInfoProperty");
		Property::meta_srcArtifactInfoProperty_rev = ImplementationArtifact::meta_dstArtifactInfoProperty;

		Uml::SetClass(IDLFile::meta, umldiagram, "IDLFile");
		Uml::SetGenericRole(IDLFile::meta_IDLFiles_parent,IDLFile::meta, "");
		Uml::SetGenericRole(IDLFile::meta_Package_children,IDLFile::meta, "");
		Uml::SetGenericRole(IDLFile::meta_ConstantDef_children,IDLFile::meta, "");
		Uml::SetGenericRole(IDLFile::meta_ExceptionDef_children,IDLFile::meta, "");
		Uml::SetGenericRole(IDLFile::meta_NamedType_children,IDLFile::meta, "");
		Uml::SetGenericRole(IDLFile::meta_FileRef_children,IDLFile::meta, "");
		Uml::SetGenericRole(IDLFile::meta_referedbyFileRef,FileRef::meta, "ref");

		Uml::SetClass(IDLFiles::meta, umldiagram, "IDLFiles");
		Uml::SetAttribute(IDLFiles::meta_name,IDLFiles::meta, "name");
		Uml::SetGenericRole(IDLFiles::meta_RootFolder_parent,IDLFiles::meta, "");
		Uml::SetGenericRole(IDLFiles::meta_IDLFile_children,IDLFiles::meta, "");

		Uml::SetClass(ComponentType::meta, umldiagram, "ComponentType");
		Uml::SetGenericRole(ComponentType::meta_ComponentImplementationContainer_parent,ComponentType::meta, "");
		Uml::SetGenericRole(ComponentType::meta_ComponentContainer_parent,ComponentType::meta, "");
		Uml::SetGenericRole(ComponentType::meta_PackageContainer_parent,ComponentType::meta, "");
		Uml::SetGenericRole(ComponentType::meta_dstComponentConfigProperty,Property::meta, "srcComponentConfigProperty");
		Property::meta_srcComponentConfigProperty_rev = ComponentType::meta_dstComponentConfigProperty;
		Uml::SetGenericRole(ComponentType::meta_dstComponentProperty,ComponentPropertyDescription::meta, "srcComponentProperty");
		ComponentPropertyDescription::meta_srcComponentProperty_rev = ComponentType::meta_dstComponentProperty;
		Uml::SetGenericRole(ComponentType::meta_dstComponentInfoProperty,Property::meta, "srcComponentInfoProperty");
		Property::meta_srcComponentInfoProperty_rev = ComponentType::meta_dstComponentInfoProperty;
		Uml::SetGenericRole(ComponentType::meta_ref,ComponentDef::meta, "referedbyComponentType");
		Uml::SetGenericRole(ComponentType::meta_srcImplements,ComponentImplementation::meta, "dstImplements");
		ComponentImplementation::meta_dstImplements_rev = ComponentType::meta_srcImplements;
		Uml::SetGenericRole(ComponentType::meta_srcPackageInterface,ComponentPackage::meta, "dstPackageInterface");
		ComponentPackage::meta_dstPackageInterface_rev = ComponentType::meta_srcPackageInterface;

		Uml::SetClass(ComponentTypes::meta, umldiagram, "ComponentTypes");
		Uml::SetAttribute(ComponentTypes::meta_name,ComponentTypes::meta, "name");
		Uml::SetGenericRole(ComponentTypes::meta_RootFolder_parent,ComponentTypes::meta, "");
		Uml::SetGenericRole(ComponentTypes::meta_ComponentContainer_children,ComponentTypes::meta, "");

		Uml::SetClass(ComponentConfigProperty::meta, umldiagram, "ComponentConfigProperty");
		Uml::SetGenericRole(ComponentConfigProperty::meta_ComponentContainer_parent,ComponentConfigProperty::meta, "");
		ComponentConfigProperty::meta_srcComponentConfigProperty_end_ = Property::meta_srcComponentConfigProperty;
		ComponentConfigProperty::meta_dstComponentConfigProperty_end_ = ComponentType::meta_dstComponentConfigProperty;

		Uml::SetClass(ComponentInfoProperty::meta, umldiagram, "ComponentInfoProperty");
		Uml::SetGenericRole(ComponentInfoProperty::meta_ComponentContainer_parent,ComponentInfoProperty::meta, "");
		ComponentInfoProperty::meta_srcComponentInfoProperty_end_ = Property::meta_srcComponentInfoProperty;
		ComponentInfoProperty::meta_dstComponentInfoProperty_end_ = ComponentType::meta_dstComponentInfoProperty;

		Uml::SetClass(CommonPortAttrs::meta, umldiagram, "CommonPortAttrs");

		Uml::SetClass(ComponentPropertyDescription::meta, umldiagram, "ComponentPropertyDescription");
		Uml::SetGenericRole(ComponentPropertyDescription::meta_ComponentContainer_parent,ComponentPropertyDescription::meta, "");
		Uml::SetGenericRole(ComponentPropertyDescription::meta_DataType_child,ComponentPropertyDescription::meta, "");
		Uml::SetGenericRole(ComponentPropertyDescription::meta_srcComponentProperty,ComponentType::meta, "dstComponentProperty");
		ComponentType::meta_dstComponentProperty_rev = ComponentPropertyDescription::meta_srcComponentProperty;

		Uml::SetClass(ComponentProperty::meta, umldiagram, "ComponentProperty");
		Uml::SetGenericRole(ComponentProperty::meta_ComponentContainer_parent,ComponentProperty::meta, "");
		ComponentProperty::meta_srcComponentProperty_end_ = ComponentPropertyDescription::meta_srcComponentProperty;
		ComponentProperty::meta_dstComponentProperty_end_ = ComponentType::meta_dstComponentProperty;

		Uml::SetClass(ComponentContainer::meta, umldiagram, "ComponentContainer");
		Uml::SetGenericRole(ComponentContainer::meta_ComponentTypes_parent,ComponentContainer::meta, "");
		Uml::SetGenericRole(ComponentContainer::meta_Property_children,ComponentContainer::meta, "");
		Uml::SetGenericRole(ComponentContainer::meta_ComponentType_child,ComponentContainer::meta, "");
		Uml::SetGenericRole(ComponentContainer::meta_ComponentConfigProperty_children,ComponentContainer::meta, "");
		Uml::SetGenericRole(ComponentContainer::meta_ComponentInfoProperty_children,ComponentContainer::meta, "");
		Uml::SetGenericRole(ComponentContainer::meta_ComponentProperty_children,ComponentContainer::meta, "");
		Uml::SetGenericRole(ComponentContainer::meta_ComponentPropertyDescription_children,ComponentContainer::meta, "");

		Uml::SetClass(ImplementationCapability::meta, umldiagram, "ImplementationCapability");
		Uml::SetGenericRole(ImplementationCapability::meta_ComponentImplementationContainer_parent,ImplementationCapability::meta, "");
		ImplementationCapability::meta_dstImplementationCapability_end_ = ComponentImplementation::meta_dstImplementationCapability;
		ImplementationCapability::meta_srcImplementationCapability_end_ = Capability::meta_srcImplementationCapability;

		Uml::SetClass(ImplementationDependsOn::meta, umldiagram, "ImplementationDependsOn");
		Uml::SetGenericRole(ImplementationDependsOn::meta_ComponentImplementationContainer_parent,ImplementationDependsOn::meta, "");
		ImplementationDependsOn::meta_dstImplementationDependsOn_end_ = ComponentImplementation::meta_dstImplementationDependsOn;
		ImplementationDependsOn::meta_srcImplementationDependsOn_end_ = ImplementationDependency::meta_srcImplementationDependsOn;

		Uml::SetClass(Implements::meta, umldiagram, "Implements");
		Uml::SetGenericRole(Implements::meta_ComponentImplementationContainer_parent,Implements::meta, "");
		Implements::meta_dstImplements_end_ = ComponentImplementation::meta_dstImplements;
		Implements::meta_srcImplements_end_ = ComponentType::meta_srcImplements;

		Uml::SetClass(ComponentImplementations::meta, umldiagram, "ComponentImplementations");
		Uml::SetAttribute(ComponentImplementations::meta_name,ComponentImplementations::meta, "name");
		Uml::SetGenericRole(ComponentImplementations::meta_RootFolder_parent,ComponentImplementations::meta, "");
		Uml::SetGenericRole(ComponentImplementations::meta_ComponentImplementationContainer_children,ComponentImplementations::meta, "");

		Uml::SetClass(ComponentImplementationReference::meta, umldiagram, "ComponentImplementationReference");
		Uml::SetGenericRole(ComponentImplementationReference::meta_PackageContainer_parent,ComponentImplementationReference::meta, "");
		Uml::SetGenericRole(ComponentImplementationReference::meta_srcPackageImplementations,ComponentPackage::meta, "dstPackageImplementations");
		ComponentPackage::meta_dstPackageImplementations_rev = ComponentImplementationReference::meta_srcPackageImplementations;
		Uml::SetGenericRole(ComponentImplementationReference::meta_ref,ComponentImplementation::meta, "referedbyComponentImplementationReference");

		Uml::SetClass(ConfigProperty::meta, umldiagram, "ConfigProperty");
		Uml::SetGenericRole(ConfigProperty::meta_ComponentImplementationContainer_parent,ConfigProperty::meta, "");
		ConfigProperty::meta_dstConfigProperty_end_ = ComponentImplementation::meta_dstConfigProperty;
		ConfigProperty::meta_srcConfigProperty_end_ = Property::meta_srcConfigProperty;

		Uml::SetClass(InfoProperty::meta, umldiagram, "InfoProperty");
		Uml::SetGenericRole(InfoProperty::meta_ComponentImplementationContainer_parent,InfoProperty::meta, "");
		InfoProperty::meta_dstInfoProperty_end_ = ComponentImplementation::meta_dstInfoProperty;
		InfoProperty::meta_srcInfoProperty_end_ = Property::meta_srcInfoProperty;

		Uml::SetClass(MonolithprimaryArtifact::meta, umldiagram, "MonolithprimaryArtifact");
		Uml::SetGenericRole(MonolithprimaryArtifact::meta_ComponentImplementationContainer_parent,MonolithprimaryArtifact::meta, "");
		MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_ = MonolithicImplementation::meta_dstMonolithprimaryArtifact;
		MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_ = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;

		Uml::SetClass(MonolithDeployRequirement::meta, umldiagram, "MonolithDeployRequirement");
		Uml::SetGenericRole(MonolithDeployRequirement::meta_ComponentImplementationContainer_parent,MonolithDeployRequirement::meta, "");
		MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_ = MonolithicImplementation::meta_dstMonolithDeployRequirement;
		MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_ = ImplementationRequirement::meta_srcMonolithDeployRequirement;

		Uml::SetClass(ComponentImplementation::meta, umldiagram, "ComponentImplementation");
		Uml::SetGenericRole(ComponentImplementation::meta_ComponentImplementationContainer_parent,ComponentImplementation::meta, "");
		Uml::SetGenericRole(ComponentImplementation::meta_dstImplements,ComponentType::meta, "srcImplements");
		ComponentType::meta_srcImplements_rev = ComponentImplementation::meta_dstImplements;
		Uml::SetGenericRole(ComponentImplementation::meta_dstImplementationCapability,Capability::meta, "srcImplementationCapability");
		Capability::meta_srcImplementationCapability_rev = ComponentImplementation::meta_dstImplementationCapability;
		Uml::SetGenericRole(ComponentImplementation::meta_dstImplementationDependsOn,ImplementationDependency::meta, "srcImplementationDependsOn");
		ImplementationDependency::meta_srcImplementationDependsOn_rev = ComponentImplementation::meta_dstImplementationDependsOn;
		Uml::SetGenericRole(ComponentImplementation::meta_referedbyComponentImplementationReference,ComponentImplementationReference::meta, "ref");
		Uml::SetGenericRole(ComponentImplementation::meta_dstConfigProperty,Property::meta, "srcConfigProperty");
		Property::meta_srcConfigProperty_rev = ComponentImplementation::meta_dstConfigProperty;
		Uml::SetGenericRole(ComponentImplementation::meta_dstInfoProperty,Property::meta, "srcInfoProperty");
		Property::meta_srcInfoProperty_rev = ComponentImplementation::meta_dstInfoProperty;

		Uml::SetClass(ComponentImplementationContainer::meta, umldiagram, "ComponentImplementationContainer");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ComponentImplementations_parent,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ComponentImplementation_child,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ImplementationRequirement_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ImplementationDependsOn_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_Implements_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ComponentType_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_MonolithDeployRequirement_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_MonolithprimaryArtifact_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_MonolithExecParameter_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ImplementationDependency_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ConfigProperty_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_ImplementationCapability_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_InfoProperty_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_Property_children,ComponentImplementationContainer::meta, "");
		Uml::SetGenericRole(ComponentImplementationContainer::meta_Capability_children,ComponentImplementationContainer::meta, "");

		Uml::SetClass(MonolithExecParameter::meta, umldiagram, "MonolithExecParameter");
		Uml::SetGenericRole(MonolithExecParameter::meta_ComponentImplementationContainer_parent,MonolithExecParameter::meta, "");
		MonolithExecParameter::meta_dstMonolithExecParameter_end_ = MonolithicImplementation::meta_dstMonolithExecParameter;
		MonolithExecParameter::meta_srcMonolithExecParameter_end_ = Property::meta_srcMonolithExecParameter;

		Uml::SetClass(MonolithicImplementation::meta, umldiagram, "MonolithicImplementation");
		Uml::SetGenericRole(MonolithicImplementation::meta_dstMonolithprimaryArtifact,ImplementationArtifactReference::meta, "srcMonolithprimaryArtifact");
		ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev = MonolithicImplementation::meta_dstMonolithprimaryArtifact;
		Uml::SetGenericRole(MonolithicImplementation::meta_dstMonolithDeployRequirement,ImplementationRequirement::meta, "srcMonolithDeployRequirement");
		ImplementationRequirement::meta_srcMonolithDeployRequirement_rev = MonolithicImplementation::meta_dstMonolithDeployRequirement;
		Uml::SetGenericRole(MonolithicImplementation::meta_dstMonolithExecParameter,Property::meta, "srcMonolithExecParameter");
		Property::meta_srcMonolithExecParameter_rev = MonolithicImplementation::meta_dstMonolithExecParameter;

		Uml::SetClass(RequirementBase::meta, umldiagram, "RequirementBase");
		Uml::SetGenericRole(RequirementBase::meta_Property_children,RequirementBase::meta, "");

		Uml::SetClass(ImplementationRequirement::meta, umldiagram, "ImplementationRequirement");
		Uml::SetGenericRole(ImplementationRequirement::meta_ComponentImplementationContainer_parent,ImplementationRequirement::meta, "");
		Uml::SetGenericRole(ImplementationRequirement::meta_srcMonolithDeployRequirement,MonolithicImplementation::meta, "dstMonolithDeployRequirement");
		MonolithicImplementation::meta_dstMonolithDeployRequirement_rev = ImplementationRequirement::meta_srcMonolithDeployRequirement;

		Uml::SetClass(Requirement::meta, umldiagram, "Requirement");
		Uml::SetGenericRole(Requirement::meta_ArtifactContainer_parent,Requirement::meta, "");
		Uml::SetGenericRole(Requirement::meta_PackageConfigurationContainer_parent,Requirement::meta, "");
		Uml::SetGenericRole(Requirement::meta_ComponentAssembly_parent,Requirement::meta, "");
		Uml::SetGenericRole(Requirement::meta_srcArtifactDeployRequirement,ImplementationArtifact::meta, "dstArtifactDeployRequirement");
		ImplementationArtifact::meta_dstArtifactDeployRequirement_rev = Requirement::meta_srcArtifactDeployRequirement;
		Uml::SetGenericRole(Requirement::meta_srcPackageSelectRequirement,PackageConfiguration::meta, "dstPackageSelectRequirement");
		PackageConfiguration::meta_dstPackageSelectRequirement_rev = Requirement::meta_srcPackageSelectRequirement;
		Uml::SetGenericRole(Requirement::meta_srcConnectionRequirements,PublishConnector::meta, "dstConnectionRequirements");
		PublishConnector::meta_dstConnectionRequirements_rev = Requirement::meta_srcConnectionRequirements;
		Uml::SetGenericRole(Requirement::meta_srcSubComponentSelectRequirement,ComponentDef::meta, "dstSubComponentSelectRequirement");
		ComponentDef::meta_dstSubComponentSelectRequirement_rev = Requirement::meta_srcSubComponentSelectRequirement;

		Uml::SetClass(ImplementationDependency::meta, umldiagram, "ImplementationDependency");
		Uml::SetGenericRole(ImplementationDependency::meta_ComponentImplementationContainer_parent,ImplementationDependency::meta, "");
		Uml::SetGenericRole(ImplementationDependency::meta_srcImplementationDependsOn,ComponentImplementation::meta, "dstImplementationDependsOn");
		ComponentImplementation::meta_dstImplementationDependsOn_rev = ImplementationDependency::meta_srcImplementationDependsOn;

		Uml::SetClass(Any::meta, umldiagram, "Any");
		Uml::SetGenericRole(Any::meta_SatisfierProperty_parent,Any::meta, "");
		Uml::SetGenericRole(Any::meta_Property_parent,Any::meta, "");
		Uml::SetGenericRole(Any::meta_DataType_child,Any::meta, "");

		Uml::SetClass(Property::meta, umldiagram, "Property");
		Uml::SetGenericRole(Property::meta_ArtifactContainer_parent,Property::meta, "");
		Uml::SetGenericRole(Property::meta_ComponentContainer_parent,Property::meta, "");
		Uml::SetGenericRole(Property::meta_ComponentImplementationContainer_parent,Property::meta, "");
		Uml::SetGenericRole(Property::meta_RequirementBase_parent,Property::meta, "");
		Uml::SetGenericRole(Property::meta_PackageConfigurationContainer_parent,Property::meta, "");
		Uml::SetGenericRole(Property::meta_ComponentAssembly_parent,Property::meta, "");
		Uml::SetGenericRole(Property::meta_PackageContainer_parent,Property::meta, "");
		Uml::SetGenericRole(Property::meta_Any_child,Property::meta, "");
		Uml::SetGenericRole(Property::meta_srcArtifactExecParameter,ImplementationArtifact::meta, "dstArtifactExecParameter");
		ImplementationArtifact::meta_dstArtifactExecParameter_rev = Property::meta_srcArtifactExecParameter;
		Uml::SetGenericRole(Property::meta_srcArtifactInfoProperty,ImplementationArtifact::meta, "dstArtifactInfoProperty");
		ImplementationArtifact::meta_dstArtifactInfoProperty_rev = Property::meta_srcArtifactInfoProperty;
		Uml::SetGenericRole(Property::meta_srcComponentConfigProperty,ComponentType::meta, "dstComponentConfigProperty");
		ComponentType::meta_dstComponentConfigProperty_rev = Property::meta_srcComponentConfigProperty;
		Uml::SetGenericRole(Property::meta_srcComponentInfoProperty,ComponentType::meta, "dstComponentInfoProperty");
		ComponentType::meta_dstComponentInfoProperty_rev = Property::meta_srcComponentInfoProperty;
		Uml::SetGenericRole(Property::meta_srcConfigProperty,ComponentImplementation::meta, "dstConfigProperty");
		ComponentImplementation::meta_dstConfigProperty_rev = Property::meta_srcConfigProperty;
		Uml::SetGenericRole(Property::meta_srcInfoProperty,ComponentImplementation::meta, "dstInfoProperty");
		ComponentImplementation::meta_dstInfoProperty_rev = Property::meta_srcInfoProperty;
		Uml::SetGenericRole(Property::meta_srcMonolithExecParameter,MonolithicImplementation::meta, "dstMonolithExecParameter");
		MonolithicImplementation::meta_dstMonolithExecParameter_rev = Property::meta_srcMonolithExecParameter;
		Uml::SetGenericRole(Property::meta_srcPackageConfigurationProperty,PackageConfiguration::meta, "dstPackageConfigurationProperty");
		PackageConfiguration::meta_dstPackageConfigurationProperty_rev = Property::meta_srcPackageConfigurationProperty;
		Uml::SetGenericRole(Property::meta_srcPackageConfigProperty,ComponentPackage::meta, "dstPackageConfigProperty");
		ComponentPackage::meta_dstPackageConfigProperty_rev = Property::meta_srcPackageConfigProperty;
		Uml::SetGenericRole(Property::meta_srcPackageInfoProperty,ComponentPackage::meta, "dstPackageInfoProperty");
		ComponentPackage::meta_dstPackageInfoProperty_rev = Property::meta_srcPackageInfoProperty;
		Uml::SetGenericRole(Property::meta_srcSubComponentConfigProperty,ComponentDef::meta, "dstSubComponentConfigProperty");
		ComponentDef::meta_dstSubComponentConfigProperty_rev = Property::meta_srcSubComponentConfigProperty;

		Uml::SetClass(SatisfierProperty::meta, umldiagram, "SatisfierProperty");
		Uml::SetGenericRole(SatisfierProperty::meta_RequirementSatisfier_parent,SatisfierProperty::meta, "");
		Uml::SetGenericRole(SatisfierProperty::meta_Any_child,SatisfierProperty::meta, "");

		Uml::SetClass(DataType::meta, umldiagram, "DataType");
		Uml::SetGenericRole(DataType::meta_Any_parent,DataType::meta, "");
		Uml::SetGenericRole(DataType::meta_ComponentPropertyDescription_parent,DataType::meta, "");
		Uml::SetGenericRole(DataType::meta_PredefinedType_child,DataType::meta, "");

		Uml::SetClass(RequirementSatisfier::meta, umldiagram, "RequirementSatisfier");
		Uml::SetGenericRole(RequirementSatisfier::meta_SatisfierProperty_children,RequirementSatisfier::meta, "");

		Uml::SetClass(Capability::meta, umldiagram, "Capability");
		Uml::SetGenericRole(Capability::meta_ComponentImplementationContainer_parent,Capability::meta, "");
		Uml::SetGenericRole(Capability::meta_srcImplementationCapability,ComponentImplementation::meta, "dstImplementationCapability");
		ComponentImplementation::meta_dstImplementationCapability_rev = Capability::meta_srcImplementationCapability;

		Uml::SetClass(PackageBaseConnection::meta, umldiagram, "PackageBaseConnection");
		Uml::SetGenericRole(PackageBaseConnection::meta_PackageConfigurationContainer_parent,PackageBaseConnection::meta, "");
		PackageBaseConnection::meta_dstPackageBaseConnection_end_ = PackageConfiguration::meta_dstPackageBaseConnection;
		PackageBaseConnection::meta_srcPackageBaseConnection_end_ = ComponentPackage::meta_srcPackageBaseConnection;

		Uml::SetClass(PackageReferenceConnection::meta, umldiagram, "PackageReferenceConnection");
		Uml::SetGenericRole(PackageReferenceConnection::meta_PackageConfigurationContainer_parent,PackageReferenceConnection::meta, "");
		PackageReferenceConnection::meta_dstPackageReferenceConnection_end_ = PackageConfiguration::meta_dstPackageReferenceConnection;
		PackageReferenceConnection::meta_srcPackageReferenceConnection_end_ = ComponentPackageReference::meta_srcPackageReferenceConnection;

		Uml::SetClass(PackageConfigurationReference::meta, umldiagram, "PackageConfigurationReference");
		Uml::SetGenericRole(PackageConfigurationReference::meta_TopLevelPackageContainer_parent,PackageConfigurationReference::meta, "");
		Uml::SetGenericRole(PackageConfigurationReference::meta_srcTopLevelPackageConn,TopLevelPackage::meta, "dstTopLevelPackageConn");
		TopLevelPackage::meta_dstTopLevelPackageConn_rev = PackageConfigurationReference::meta_srcTopLevelPackageConn;
		Uml::SetGenericRole(PackageConfigurationReference::meta_ref,PackageConfiguration::meta, "referedbyPackageConfigurationReference");

		Uml::SetClass(PackageConfiguration::meta, umldiagram, "PackageConfiguration");
		Uml::SetGenericRole(PackageConfiguration::meta_PackageConfigurationContainer_parent,PackageConfiguration::meta, "");
		Uml::SetGenericRole(PackageConfiguration::meta_specializedConfig_PackageConfiguration_parent,PackageConfiguration::meta, "specializedConfig");
		Uml::SetGenericRole(PackageConfiguration::meta_specializedConfig,PackageConfiguration::meta, "");
		Uml::SetGenericRole(PackageConfiguration::meta_dstPackageSelectRequirement,Requirement::meta, "srcPackageSelectRequirement");
		Requirement::meta_srcPackageSelectRequirement_rev = PackageConfiguration::meta_dstPackageSelectRequirement;
		Uml::SetGenericRole(PackageConfiguration::meta_dstPackageConfigurationProperty,Property::meta, "srcPackageConfigurationProperty");
		Property::meta_srcPackageConfigurationProperty_rev = PackageConfiguration::meta_dstPackageConfigurationProperty;
		Uml::SetGenericRole(PackageConfiguration::meta_dstPackageBaseConnection,ComponentPackage::meta, "srcPackageBaseConnection");
		ComponentPackage::meta_srcPackageBaseConnection_rev = PackageConfiguration::meta_dstPackageBaseConnection;
		Uml::SetGenericRole(PackageConfiguration::meta_dstPackageReferenceConnection,ComponentPackageReference::meta, "srcPackageReferenceConnection");
		ComponentPackageReference::meta_srcPackageReferenceConnection_rev = PackageConfiguration::meta_dstPackageReferenceConnection;
		Uml::SetGenericRole(PackageConfiguration::meta_referedbyPackageConfigurationReference,PackageConfigurationReference::meta, "ref");

		Uml::SetClass(PackageConfigurations::meta, umldiagram, "PackageConfigurations");
		Uml::SetAttribute(PackageConfigurations::meta_name,PackageConfigurations::meta, "name");
		Uml::SetGenericRole(PackageConfigurations::meta_RootFolder_parent,PackageConfigurations::meta, "");
		Uml::SetGenericRole(PackageConfigurations::meta_PackageConfigurationContainer_children,PackageConfigurations::meta, "");

		Uml::SetClass(PackageConfigurationContainer::meta, umldiagram, "PackageConfigurationContainer");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_PackageConfigurations_parent,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_PackageReferenceConnection_child,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_PackageBaseConnection_child,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_ComponentPackage_children,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_ComponentPackageReference_children,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_PackageConfiguration_children,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_PackageConfigurationProperty_children,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_PackageSelectRequirement_children,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_Requirement_children,PackageConfigurationContainer::meta, "");
		Uml::SetGenericRole(PackageConfigurationContainer::meta_Property_children,PackageConfigurationContainer::meta, "");

		Uml::SetClass(PackageConfigurationProperty::meta, umldiagram, "PackageConfigurationProperty");
		Uml::SetGenericRole(PackageConfigurationProperty::meta_PackageConfigurationContainer_parent,PackageConfigurationProperty::meta, "");
		PackageConfigurationProperty::meta_dstPackageConfigurationProperty_end_ = PackageConfiguration::meta_dstPackageConfigurationProperty;
		PackageConfigurationProperty::meta_srcPackageConfigurationProperty_end_ = Property::meta_srcPackageConfigurationProperty;

		Uml::SetClass(PackageSelectRequirement::meta, umldiagram, "PackageSelectRequirement");
		Uml::SetGenericRole(PackageSelectRequirement::meta_PackageConfigurationContainer_parent,PackageSelectRequirement::meta, "");
		PackageSelectRequirement::meta_dstPackageSelectRequirement_end_ = PackageConfiguration::meta_dstPackageSelectRequirement;
		PackageSelectRequirement::meta_srcPackageSelectRequirement_end_ = Requirement::meta_srcPackageSelectRequirement;

		Uml::SetClass(EmitConnector::meta, umldiagram, "EmitConnector");
		Uml::SetGenericRole(EmitConnector::meta_ComponentAssembly_parent,EmitConnector::meta, "");
		EmitConnector::meta_dstEmitConnector_end_ = OutEventPort::meta_dstEmitConnector;
		EmitConnector::meta_srcEmitConnector_end_ = InEventPort::meta_srcEmitConnector;

		Uml::SetClass(ComponentAssembly::meta, umldiagram, "ComponentAssembly");
		Uml::SetGenericRole(ComponentAssembly::meta_ComponentDef_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_EmitConnector_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_ComponentPackage_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_Invocation_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_SubComponentSelectRequirement_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_SubComponentConfigProperty_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_Property_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_ComponentPackageReference_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_InEventPortConsume_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_OutEventPortPublish_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_PublishConnector_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_ConnectionRequirements_children,ComponentAssembly::meta, "");
		Uml::SetGenericRole(ComponentAssembly::meta_Requirement_children,ComponentAssembly::meta, "");

		Uml::SetClass(Invocation::meta, umldiagram, "Invocation");
		Uml::SetGenericRole(Invocation::meta_ComponentAssembly_parent,Invocation::meta, "");
		Invocation::meta_dstInvocation_end_ = RequiredRequestPort::meta_dstInvocation;
		Invocation::meta_srcInvocation_end_ = ProvidedRequestPort::meta_srcInvocation;

		Uml::SetClass(SubComponentSelectRequirement::meta, umldiagram, "SubComponentSelectRequirement");
		Uml::SetGenericRole(SubComponentSelectRequirement::meta_ComponentAssembly_parent,SubComponentSelectRequirement::meta, "");
		SubComponentSelectRequirement::meta_dstSubComponentSelectRequirement_end_ = ComponentDef::meta_dstSubComponentSelectRequirement;
		SubComponentSelectRequirement::meta_srcSubComponentSelectRequirement_end_ = Requirement::meta_srcSubComponentSelectRequirement;

		Uml::SetClass(SubComponentConfigProperty::meta, umldiagram, "SubComponentConfigProperty");
		Uml::SetGenericRole(SubComponentConfigProperty::meta_ComponentAssembly_parent,SubComponentConfigProperty::meta, "");
		SubComponentConfigProperty::meta_dstSubComponentConfigProperty_end_ = ComponentDef::meta_dstSubComponentConfigProperty;
		SubComponentConfigProperty::meta_srcSubComponentConfigProperty_end_ = Property::meta_srcSubComponentConfigProperty;

		Uml::SetClass(PublishConnector::meta, umldiagram, "PublishConnector");
		Uml::SetGenericRole(PublishConnector::meta_ComponentAssembly_parent,PublishConnector::meta, "");
		Uml::SetGenericRole(PublishConnector::meta_dstConnectionRequirements,Requirement::meta, "srcConnectionRequirements");
		Requirement::meta_srcConnectionRequirements_rev = PublishConnector::meta_dstConnectionRequirements;
		Uml::SetGenericRole(PublishConnector::meta_dstInEventPortConsume,InEventPort::meta, "srcInEventPortConsume");
		InEventPort::meta_srcInEventPortConsume_rev = PublishConnector::meta_dstInEventPortConsume;
		Uml::SetGenericRole(PublishConnector::meta_srcOutEventPortPublish,OutEventPort::meta, "dstOutEventPortPublish");
		OutEventPort::meta_dstOutEventPortPublish_rev = PublishConnector::meta_srcOutEventPortPublish;

		Uml::SetClass(OutEventPortPublish::meta, umldiagram, "OutEventPortPublish");
		Uml::SetGenericRole(OutEventPortPublish::meta_ComponentAssembly_parent,OutEventPortPublish::meta, "");
		OutEventPortPublish::meta_dstOutEventPortPublish_end_ = OutEventPort::meta_dstOutEventPortPublish;
		OutEventPortPublish::meta_srcOutEventPortPublish_end_ = PublishConnector::meta_srcOutEventPortPublish;

		Uml::SetClass(InEventPortConsume::meta, umldiagram, "InEventPortConsume");
		Uml::SetGenericRole(InEventPortConsume::meta_ComponentAssembly_parent,InEventPortConsume::meta, "");
		InEventPortConsume::meta_srcInEventPortConsume_end_ = InEventPort::meta_srcInEventPortConsume;
		InEventPortConsume::meta_dstInEventPortConsume_end_ = PublishConnector::meta_dstInEventPortConsume;

		Uml::SetClass(ConnectionRequirements::meta, umldiagram, "ConnectionRequirements");
		Uml::SetGenericRole(ConnectionRequirements::meta_ComponentAssembly_parent,ConnectionRequirements::meta, "");
		ConnectionRequirements::meta_dstConnectionRequirements_end_ = PublishConnector::meta_dstConnectionRequirements;
		ConnectionRequirements::meta_srcConnectionRequirements_end_ = Requirement::meta_srcConnectionRequirements;

		Uml::SetClass(ComponentPackages::meta, umldiagram, "ComponentPackages");
		Uml::SetAttribute(ComponentPackages::meta_name,ComponentPackages::meta, "name");
		Uml::SetGenericRole(ComponentPackages::meta_RootFolder_parent,ComponentPackages::meta, "");
		Uml::SetGenericRole(ComponentPackages::meta_PackageContainer_children,ComponentPackages::meta, "");

		Uml::SetClass(PackageInterface::meta, umldiagram, "PackageInterface");
		Uml::SetGenericRole(PackageInterface::meta_PackageContainer_parent,PackageInterface::meta, "");
		PackageInterface::meta_dstPackageInterface_end_ = ComponentPackage::meta_dstPackageInterface;
		PackageInterface::meta_srcPackageInterface_end_ = ComponentType::meta_srcPackageInterface;

		Uml::SetClass(PackageImplementations::meta, umldiagram, "PackageImplementations");
		Uml::SetGenericRole(PackageImplementations::meta_PackageContainer_parent,PackageImplementations::meta, "");
		PackageImplementations::meta_dstPackageImplementations_end_ = ComponentPackage::meta_dstPackageImplementations;
		PackageImplementations::meta_srcPackageImplementations_end_ = ComponentImplementationReference::meta_srcPackageImplementations;

		Uml::SetClass(PackageContainer::meta, umldiagram, "PackageContainer");
		Uml::SetGenericRole(PackageContainer::meta_ComponentPackages_parent,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_PackageImplementations_children,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_PackageInterface_child,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_ComponentImplementationReference_children,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_ComponentType_children,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_PackageConfigProperty_children,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_Property_children,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_PackageInfoProperty_children,PackageContainer::meta, "");
		Uml::SetGenericRole(PackageContainer::meta_ComponentPackage_child,PackageContainer::meta, "");

		Uml::SetClass(PackageConfigProperty::meta, umldiagram, "PackageConfigProperty");
		Uml::SetGenericRole(PackageConfigProperty::meta_PackageContainer_parent,PackageConfigProperty::meta, "");
		PackageConfigProperty::meta_dstPackageConfigProperty_end_ = ComponentPackage::meta_dstPackageConfigProperty;
		PackageConfigProperty::meta_srcPackageConfigProperty_end_ = Property::meta_srcPackageConfigProperty;

		Uml::SetClass(PackageInfoProperty::meta, umldiagram, "PackageInfoProperty");
		Uml::SetGenericRole(PackageInfoProperty::meta_PackageContainer_parent,PackageInfoProperty::meta, "");
		PackageInfoProperty::meta_dstPackageInfoProperty_end_ = ComponentPackage::meta_dstPackageInfoProperty;
		PackageInfoProperty::meta_srcPackageInfoProperty_end_ = Property::meta_srcPackageInfoProperty;

		Uml::SetClass(ComponentPackage::meta, umldiagram, "ComponentPackage");
		Uml::SetGenericRole(ComponentPackage::meta_PackageConfigurationContainer_parent,ComponentPackage::meta, "");
		Uml::SetGenericRole(ComponentPackage::meta_ComponentAssembly_parent,ComponentPackage::meta, "");
		Uml::SetGenericRole(ComponentPackage::meta_PackageContainer_parent,ComponentPackage::meta, "");
		Uml::SetGenericRole(ComponentPackage::meta_dstPackageInterface,ComponentType::meta, "srcPackageInterface");
		ComponentType::meta_srcPackageInterface_rev = ComponentPackage::meta_dstPackageInterface;
		Uml::SetGenericRole(ComponentPackage::meta_dstPackageImplementations,ComponentImplementationReference::meta, "srcPackageImplementations");
		ComponentImplementationReference::meta_srcPackageImplementations_rev = ComponentPackage::meta_dstPackageImplementations;
		Uml::SetGenericRole(ComponentPackage::meta_dstPackageConfigProperty,Property::meta, "srcPackageConfigProperty");
		Property::meta_srcPackageConfigProperty_rev = ComponentPackage::meta_dstPackageConfigProperty;
		Uml::SetGenericRole(ComponentPackage::meta_dstPackageInfoProperty,Property::meta, "srcPackageInfoProperty");
		Property::meta_srcPackageInfoProperty_rev = ComponentPackage::meta_dstPackageInfoProperty;
		Uml::SetGenericRole(ComponentPackage::meta_srcPackageBaseConnection,PackageConfiguration::meta, "dstPackageBaseConnection");
		PackageConfiguration::meta_dstPackageBaseConnection_rev = ComponentPackage::meta_srcPackageBaseConnection;
		Uml::SetGenericRole(ComponentPackage::meta_referedbyComponentPackageReference,ComponentPackageReference::meta, "ref");

		Uml::SetClass(ComponentPackageReference::meta, umldiagram, "ComponentPackageReference");
		Uml::SetGenericRole(ComponentPackageReference::meta_PackageConfigurationContainer_parent,ComponentPackageReference::meta, "");
		Uml::SetGenericRole(ComponentPackageReference::meta_ComponentAssembly_parent,ComponentPackageReference::meta, "");
		Uml::SetGenericRole(ComponentPackageReference::meta_srcPackageReferenceConnection,PackageConfiguration::meta, "dstPackageReferenceConnection");
		PackageConfiguration::meta_dstPackageReferenceConnection_rev = ComponentPackageReference::meta_srcPackageReferenceConnection;
		Uml::SetGenericRole(ComponentPackageReference::meta_ref,ComponentPackage::meta, "referedbyComponentPackageReference");

		Uml::SetClass(TopLevelPackageContainer::meta, umldiagram, "TopLevelPackageContainer");
		Uml::SetGenericRole(TopLevelPackageContainer::meta_TopLevelPackageFolder_parent,TopLevelPackageContainer::meta, "");
		Uml::SetGenericRole(TopLevelPackageContainer::meta_TopLevelPackage_children,TopLevelPackageContainer::meta, "");
		Uml::SetGenericRole(TopLevelPackageContainer::meta_PackageConfigurationReference_children,TopLevelPackageContainer::meta, "");
		Uml::SetGenericRole(TopLevelPackageContainer::meta_TopLevelPackageConn_children,TopLevelPackageContainer::meta, "");

		Uml::SetClass(TopLevelPackageFolder::meta, umldiagram, "TopLevelPackageFolder");
		Uml::SetAttribute(TopLevelPackageFolder::meta_name,TopLevelPackageFolder::meta, "name");
		Uml::SetGenericRole(TopLevelPackageFolder::meta_RootFolder_parent,TopLevelPackageFolder::meta, "");
		Uml::SetGenericRole(TopLevelPackageFolder::meta_TopLevelPackageContainer_children,TopLevelPackageFolder::meta, "");

		Uml::SetClass(TopLevelPackage::meta, umldiagram, "TopLevelPackage");
		Uml::SetGenericRole(TopLevelPackage::meta_TopLevelPackageContainer_parent,TopLevelPackage::meta, "");
		Uml::SetGenericRole(TopLevelPackage::meta_dstTopLevelPackageConn,PackageConfigurationReference::meta, "srcTopLevelPackageConn");
		PackageConfigurationReference::meta_srcTopLevelPackageConn_rev = TopLevelPackage::meta_dstTopLevelPackageConn;

		Uml::SetClass(TopLevelPackageConn::meta, umldiagram, "TopLevelPackageConn");
		Uml::SetGenericRole(TopLevelPackageConn::meta_TopLevelPackageContainer_parent,TopLevelPackageConn::meta, "");
		TopLevelPackageConn::meta_dstTopLevelPackageConn_end_ = TopLevelPackage::meta_dstTopLevelPackageConn;
		TopLevelPackageConn::meta_srcTopLevelPackageConn_end_ = PackageConfigurationReference::meta_srcTopLevelPackageConn;

		Uml::SetClass(EnumerationDef::meta, umldiagram, "EnumerationDef");
		Uml::SetGenericRole(EnumerationDef::meta_EnumValue_children,EnumerationDef::meta, "");
		Uml::SetGenericRole(EnumerationDef::meta_referedbyEnumRef,EnumRef::meta, "ref");

		Uml::SetClass(EnumValue::meta, umldiagram, "EnumValue");
		Uml::SetGenericRole(EnumValue::meta_EnumerationDef_parent,EnumValue::meta, "");

		Uml::SetClass(AliasDef::meta, umldiagram, "AliasDef");
		Uml::SetGenericRole(AliasDef::meta_Member_child,AliasDef::meta, "");

		Uml::SetClass(AggregateDef::meta, umldiagram, "AggregateDef");
		Uml::SetGenericRole(AggregateDef::meta_Member_children,AggregateDef::meta, "");

		Uml::SetClass(SwitchedAggregateDef::meta, umldiagram, "SwitchedAggregateDef");
		Uml::SetGenericRole(SwitchedAggregateDef::meta_LabelConnection_children,SwitchedAggregateDef::meta, "");
		Uml::SetGenericRole(SwitchedAggregateDef::meta_Discriminator_child,SwitchedAggregateDef::meta, "");
		Uml::SetGenericRole(SwitchedAggregateDef::meta_Label_children,SwitchedAggregateDef::meta, "");
		Uml::SetGenericRole(SwitchedAggregateDef::meta_Member_children,SwitchedAggregateDef::meta, "");

		Uml::SetClass(Label::meta, umldiagram, "Label");
		Uml::SetGenericRole(Label::meta_SwitchedAggregateDef_parent,Label::meta, "");
		Uml::SetGenericRole(Label::meta_srcLabelConnection,Member::meta, "dstLabelConnection");
		Member::meta_dstLabelConnection_rev = Label::meta_srcLabelConnection;

		Uml::SetClass(Discriminator::meta, umldiagram, "Discriminator");
		Uml::SetGenericRole(Discriminator::meta_SwitchedAggregateDef_parent,Discriminator::meta, "");
		Uml::SetGenericRole(Discriminator::meta_EnumRef_child,Discriminator::meta, "");
		Uml::SetGenericRole(Discriminator::meta_PredefinedType_child,Discriminator::meta, "");

		Uml::SetClass(LabelConnection::meta, umldiagram, "LabelConnection");
		Uml::SetGenericRole(LabelConnection::meta_SwitchedAggregateDef_parent,LabelConnection::meta, "");
		LabelConnection::meta_dstLabelConnection_end_ = Member::meta_dstLabelConnection;
		LabelConnection::meta_srcLabelConnection_end_ = Label::meta_srcLabelConnection;

		Uml::SetClass(BoxedDef::meta, umldiagram, "BoxedDef");
		Uml::SetGenericRole(BoxedDef::meta_Member_child,BoxedDef::meta, "");

		Uml::SetClass(NamedTypeRef::meta, umldiagram, "NamedTypeRef");
		Uml::SetGenericRole(NamedTypeRef::meta_ref,NamedType::meta, "referedbyNamedTypeRef");

		Uml::SetClass(EnumRef::meta, umldiagram, "EnumRef");
		Uml::SetGenericRole(EnumRef::meta_Discriminator_parent,EnumRef::meta, "");
		Uml::SetGenericRole(EnumRef::meta_ConstantDef_parent,EnumRef::meta, "");
		Uml::SetGenericRole(EnumRef::meta_ref,EnumerationDef::meta, "referedbyEnumRef");

		Uml::SetClass(NamedType::meta, umldiagram, "NamedType");
		Uml::SetGenericRole(NamedType::meta_IDLFile_parent,NamedType::meta, "");
		Uml::SetGenericRole(NamedType::meta_Package_parent,NamedType::meta, "");
		Uml::SetGenericRole(NamedType::meta_referedbyNamedTypeRef,NamedTypeRef::meta, "ref");

		Uml::SetClass(Member::meta, umldiagram, "Member");
		Uml::SetGenericRole(Member::meta_AliasDef_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_AggregateDef_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_SwitchedAggregateDef_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_BoxedDef_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_ExceptionDef_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_CollectionType_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_ReadonlyAttribute_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_ObjectByValue_parent,Member::meta, "");
		Uml::SetGenericRole(Member::meta_dstLabelConnection,Label::meta, "srcLabelConnection");
		Label::meta_srcLabelConnection_rev = Member::meta_dstLabelConnection;
		Uml::SetGenericRole(Member::meta_dstMakeMemberPrivate,PrivateFlag::meta, "srcMakeMemberPrivate");
		PrivateFlag::meta_srcMakeMemberPrivate_rev = Member::meta_dstMakeMemberPrivate;

		Uml::SetClass(NoInheritable::meta, umldiagram, "NoInheritable");
		Uml::SetGenericRole(NoInheritable::meta_HasOperations_parent,NoInheritable::meta, "");

		Uml::SetClass(IdTag::meta, umldiagram, "IdTag");

		Uml::SetClass(PrefixTag::meta, umldiagram, "PrefixTag");
		Uml::SetGenericRole(PrefixTag::meta_Prefixable_parent,PrefixTag::meta, "");

		Uml::SetClass(GeneralTag::meta, umldiagram, "GeneralTag");
		Uml::SetGenericRole(GeneralTag::meta_Taggable_parent,GeneralTag::meta, "");

		Uml::SetClass(SpecifyIdTag::meta, umldiagram, "SpecifyIdTag");

		Uml::SetClass(VersionTag::meta, umldiagram, "VersionTag");

		Uml::SetClass(Prefixable::meta, umldiagram, "Prefixable");
		Uml::SetGenericRole(Prefixable::meta_PrefixTag_child,Prefixable::meta, "");

		Uml::SetClass(Taggable::meta, umldiagram, "Taggable");
		Uml::SetGenericRole(Taggable::meta_GeneralTag_child,Taggable::meta, "");

		Uml::SetClass(ReturnType::meta, umldiagram, "ReturnType");
		Uml::SetGenericRole(ReturnType::meta_TwowayOperation_parent,ReturnType::meta, "");

		Uml::SetClass(InParameter::meta, umldiagram, "InParameter");
		Uml::SetGenericRole(InParameter::meta_OperationBase_parent,InParameter::meta, "");

		Uml::SetClass(InoutParameter::meta, umldiagram, "InoutParameter");
		Uml::SetGenericRole(InoutParameter::meta_TwowayOperation_parent,InoutParameter::meta, "");

		Uml::SetClass(OutParameter::meta, umldiagram, "OutParameter");
		Uml::SetGenericRole(OutParameter::meta_TwowayOperation_parent,OutParameter::meta, "");

		Uml::SetClass(ParameterType::meta, umldiagram, "ParameterType");
		Uml::SetGenericRole(ParameterType::meta_Parameter_parent,ParameterType::meta, "");

		Uml::SetClass(OperationBase::meta, umldiagram, "OperationBase");
		Uml::SetGenericRole(OperationBase::meta_InParameter_children,OperationBase::meta, "");

		Uml::SetClass(Parameter::meta, umldiagram, "Parameter");
		Uml::SetGenericRole(Parameter::meta_ParameterType_child,Parameter::meta, "");

		Uml::SetClass(HasExceptions::meta, umldiagram, "HasExceptions");
		Uml::SetGenericRole(HasExceptions::meta_ExceptionRef_children,HasExceptions::meta, "");

		Uml::SetClass(OnewayOperation::meta, umldiagram, "OnewayOperation");
		Uml::SetGenericRole(OnewayOperation::meta_HasOperations_parent,OnewayOperation::meta, "");

		Uml::SetClass(LookupOperation::meta, umldiagram, "LookupOperation");
		Uml::SetGenericRole(LookupOperation::meta_ComponentFactory_parent,LookupOperation::meta, "");

		Uml::SetClass(FactoryOperation::meta, umldiagram, "FactoryOperation");
		Uml::SetGenericRole(FactoryOperation::meta_ObjectByValue_parent,FactoryOperation::meta, "");
		Uml::SetGenericRole(FactoryOperation::meta_ComponentFactory_parent,FactoryOperation::meta, "");

		Uml::SetClass(TwowayOperation::meta, umldiagram, "TwowayOperation");
		Uml::SetGenericRole(TwowayOperation::meta_HasOperations_parent,TwowayOperation::meta, "");
		Uml::SetGenericRole(TwowayOperation::meta_OutParameter_children,TwowayOperation::meta, "");
		Uml::SetGenericRole(TwowayOperation::meta_InoutParameter_children,TwowayOperation::meta, "");
		Uml::SetGenericRole(TwowayOperation::meta_ReturnType_children,TwowayOperation::meta, "");

		Uml::SetClass(Package::meta, umldiagram, "Package");
		Uml::SetGenericRole(Package::meta_IDLFile_parent,Package::meta, "");
		Uml::SetGenericRole(Package::meta_Package_parent,Package::meta, "");
		Uml::SetGenericRole(Package::meta_ConstantDef_children,Package::meta, "");
		Uml::SetGenericRole(Package::meta_Package_children,Package::meta, "");
		Uml::SetGenericRole(Package::meta_ExceptionDef_children,Package::meta, "");
		Uml::SetGenericRole(Package::meta_NamedType_children,Package::meta, "");

		Uml::SetClass(Type::meta, umldiagram, "Type");

		Uml::SetClass(ExceptionRef::meta, umldiagram, "ExceptionRef");
		Uml::SetGenericRole(ExceptionRef::meta_HasExceptions_parent,ExceptionRef::meta, "");
		Uml::SetGenericRole(ExceptionRef::meta_ref,ExceptionDef::meta, "referedbyExceptionRef");

		Uml::SetClass(FileRef::meta, umldiagram, "FileRef");
		Uml::SetGenericRole(FileRef::meta_IDLFile_parent,FileRef::meta, "");
		Uml::SetGenericRole(FileRef::meta_ref,IDLFile::meta, "referedbyFileRef");

		Uml::SetClass(ConstantDef::meta, umldiagram, "ConstantDef");
		Uml::SetAttribute(ConstantDef::meta_value,ConstantDef::meta, "value");
		Uml::SetGenericRole(ConstantDef::meta_IDLFile_parent,ConstantDef::meta, "");
		Uml::SetGenericRole(ConstantDef::meta_Package_parent,ConstantDef::meta, "");
		Uml::SetGenericRole(ConstantDef::meta_HasOperations_parent,ConstantDef::meta, "");
		Uml::SetGenericRole(ConstantDef::meta_BoundedString_child,ConstantDef::meta, "");
		Uml::SetGenericRole(ConstantDef::meta_PredefinedType_child,ConstantDef::meta, "");
		Uml::SetGenericRole(ConstantDef::meta_EnumRef_child,ConstantDef::meta, "");
		Uml::SetGenericRole(ConstantDef::meta_FixedPoint_child,ConstantDef::meta, "");

		Uml::SetClass(ExceptionDef::meta, umldiagram, "ExceptionDef");
		Uml::SetGenericRole(ExceptionDef::meta_IDLFile_parent,ExceptionDef::meta, "");
		Uml::SetGenericRole(ExceptionDef::meta_Package_parent,ExceptionDef::meta, "");
		Uml::SetGenericRole(ExceptionDef::meta_HasOperations_parent,ExceptionDef::meta, "");
		Uml::SetGenericRole(ExceptionDef::meta_Member_children,ExceptionDef::meta, "");
		Uml::SetGenericRole(ExceptionDef::meta_referedbyExceptionRef,ExceptionRef::meta, "ref");
		Uml::SetGenericRole(ExceptionDef::meta_referedbySetException,SetException::meta, "ref");
		Uml::SetGenericRole(ExceptionDef::meta_referedbyGetException,GetException::meta, "ref");

		Uml::SetClass(RequestPort::meta, umldiagram, "RequestPort");
		Uml::SetGenericRole(RequestPort::meta_ObjectRef_child,RequestPort::meta, "");

		Uml::SetClass(EventPort::meta, umldiagram, "EventPort");
		Uml::SetGenericRole(EventPort::meta_EventRef_child,EventPort::meta, "");

		Uml::SetClass(EventRef::meta, umldiagram, "EventRef");
		Uml::SetGenericRole(EventRef::meta_EventPort_parent,EventRef::meta, "");
		Uml::SetGenericRole(EventRef::meta_ref,EventDef::meta, "referedbyEventRef");

		Uml::SetClass(ObjectRef::meta, umldiagram, "ObjectRef");
		Uml::SetGenericRole(ObjectRef::meta_RequestPort_parent,ObjectRef::meta, "");
		Uml::SetGenericRole(ObjectRef::meta_ref,ObjectDef::meta, "referedbyObjectRef");

		Uml::SetClass(ProvidedRequestPort::meta, umldiagram, "ProvidedRequestPort");
		Uml::SetGenericRole(ProvidedRequestPort::meta_srcInvocation,RequiredRequestPort::meta, "dstInvocation");
		RequiredRequestPort::meta_dstInvocation_rev = ProvidedRequestPort::meta_srcInvocation;

		Uml::SetClass(RequiredRequestPort::meta, umldiagram, "RequiredRequestPort");
		Uml::SetAttribute(RequiredRequestPort::meta_multiple_connections,RequiredRequestPort::meta, "multiple_connections");
		Uml::SetGenericRole(RequiredRequestPort::meta_dstInvocation,ProvidedRequestPort::meta, "srcInvocation");
		ProvidedRequestPort::meta_srcInvocation_rev = RequiredRequestPort::meta_dstInvocation;

		Uml::SetClass(OutEventPort::meta, umldiagram, "OutEventPort");
		Uml::SetAttribute(OutEventPort::meta_single_destination,OutEventPort::meta, "single_destination");
		Uml::SetGenericRole(OutEventPort::meta_dstEmitConnector,InEventPort::meta, "srcEmitConnector");
		InEventPort::meta_srcEmitConnector_rev = OutEventPort::meta_dstEmitConnector;
		Uml::SetGenericRole(OutEventPort::meta_dstOutEventPortPublish,PublishConnector::meta, "srcOutEventPortPublish");
		PublishConnector::meta_srcOutEventPortPublish_rev = OutEventPort::meta_dstOutEventPortPublish;

		Uml::SetClass(InEventPort::meta, umldiagram, "InEventPort");
		Uml::SetGenericRole(InEventPort::meta_srcEmitConnector,OutEventPort::meta, "dstEmitConnector");
		OutEventPort::meta_dstEmitConnector_rev = InEventPort::meta_srcEmitConnector;
		Uml::SetGenericRole(InEventPort::meta_srcInEventPortConsume,PublishConnector::meta, "dstInEventPortConsume");
		PublishConnector::meta_dstInEventPortConsume_rev = InEventPort::meta_srcInEventPortConsume;

		Uml::SetClass(Port::meta, umldiagram, "Port");
		Uml::SetGenericRole(Port::meta_ComponentDef_parent,Port::meta, "");

		Uml::SetClass(ComponentDef::meta, umldiagram, "ComponentDef");
		Uml::SetGenericRole(ComponentDef::meta_ComponentAssembly_parent,ComponentDef::meta, "");
		Uml::SetGenericRole(ComponentDef::meta_Port_children,ComponentDef::meta, "");
		Uml::SetGenericRole(ComponentDef::meta_referedbyComponentType,ComponentType::meta, "ref");
		Uml::SetGenericRole(ComponentDef::meta_dstSubComponentSelectRequirement,Requirement::meta, "srcSubComponentSelectRequirement");
		Requirement::meta_srcSubComponentSelectRequirement_rev = ComponentDef::meta_dstSubComponentSelectRequirement;
		Uml::SetGenericRole(ComponentDef::meta_dstSubComponentConfigProperty,Property::meta, "srcSubComponentConfigProperty");
		Property::meta_srcSubComponentConfigProperty_rev = ComponentDef::meta_dstSubComponentConfigProperty;
		Uml::SetGenericRole(ComponentDef::meta_referedbyManages,Manages::meta, "ref");

		Uml::SetClass(BoundedString::meta, umldiagram, "BoundedString");
		Uml::SetAttribute(BoundedString::meta_wide,BoundedString::meta, "wide");
		Uml::SetAttribute(BoundedString::meta_bound,BoundedString::meta, "bound");
		Uml::SetGenericRole(BoundedString::meta_ConstantDef_parent,BoundedString::meta, "");

		Uml::SetClass(FixedSizeCollection::meta, umldiagram, "FixedSizeCollection");

		Uml::SetClass(VariableSizeCollection::meta, umldiagram, "VariableSizeCollection");

		Uml::SetClass(AnonymousType::meta, umldiagram, "AnonymousType");

		Uml::SetClass(CollectionType::meta, umldiagram, "CollectionType");
		Uml::SetAttribute(CollectionType::meta_bound,CollectionType::meta, "bound");
		Uml::SetGenericRole(CollectionType::meta_Member_child,CollectionType::meta, "");

		Uml::SetClass(PredefinedType::meta, umldiagram, "PredefinedType");
		Uml::SetAttribute(PredefinedType::meta_which_type,PredefinedType::meta, "which_type");
		Uml::SetGenericRole(PredefinedType::meta_Discriminator_parent,PredefinedType::meta, "");
		Uml::SetGenericRole(PredefinedType::meta_ConstantDef_parent,PredefinedType::meta, "");
		Uml::SetGenericRole(PredefinedType::meta_DataType_parent,PredefinedType::meta, "");

		Uml::SetClass(FixedPoint::meta, umldiagram, "FixedPoint");
		Uml::SetAttribute(FixedPoint::meta_total_digits,FixedPoint::meta, "total_digits");
		Uml::SetAttribute(FixedPoint::meta_decimal_digits,FixedPoint::meta, "decimal_digits");
		Uml::SetGenericRole(FixedPoint::meta_ConstantDef_parent,FixedPoint::meta, "");

		Uml::SetClass(ObjectDef::meta, umldiagram, "ObjectDef");
		Uml::SetAttribute(ObjectDef::meta_local,ObjectDef::meta, "local");
		Uml::SetAttribute(ObjectDef::meta_abstract,ObjectDef::meta, "abstract");
		Uml::SetGenericRole(ObjectDef::meta_referedbyObjectRef,ObjectRef::meta, "ref");
		Uml::SetGenericRole(ObjectDef::meta_referedbySupports,Supports::meta, "ref");

		Uml::SetClass(ComponentFactory::meta, umldiagram, "ComponentFactory");
		Uml::SetGenericRole(ComponentFactory::meta_Manages_child,ComponentFactory::meta, "");
		Uml::SetGenericRole(ComponentFactory::meta_LookupKey_child,ComponentFactory::meta, "");
		Uml::SetGenericRole(ComponentFactory::meta_LookupOperation_children,ComponentFactory::meta, "");
		Uml::SetGenericRole(ComponentFactory::meta_FactoryOperation_children,ComponentFactory::meta, "");

		Uml::SetClass(Inherits::meta, umldiagram, "Inherits");
		Uml::SetGenericRole(Inherits::meta_Inheritable_parent,Inherits::meta, "");
		Uml::SetGenericRole(Inherits::meta_ref,Inheritable::meta, "referedbyInherits");

		Uml::SetClass(EventDef::meta, umldiagram, "EventDef");
		Uml::SetGenericRole(EventDef::meta_referedbyEventRef,EventRef::meta, "ref");

		Uml::SetClass(ValueDef::meta, umldiagram, "ValueDef");
		Uml::SetGenericRole(ValueDef::meta_referedbyLookupKey,LookupKey::meta, "ref");

		Uml::SetClass(Inheritable::meta, umldiagram, "Inheritable");
		Uml::SetGenericRole(Inheritable::meta_ReadonlyAttribute_children,Inheritable::meta, "");
		Uml::SetGenericRole(Inheritable::meta_Inherits_children,Inheritable::meta, "");
		Uml::SetGenericRole(Inheritable::meta_referedbyInherits,Inherits::meta, "ref");

		Uml::SetClass(HasOperations::meta, umldiagram, "HasOperations");
		Uml::SetGenericRole(HasOperations::meta_TwowayOperation_children,HasOperations::meta, "");
		Uml::SetGenericRole(HasOperations::meta_OnewayOperation_children,HasOperations::meta, "");
		Uml::SetGenericRole(HasOperations::meta_NoInheritable_children,HasOperations::meta, "");
		Uml::SetGenericRole(HasOperations::meta_ConstantDef_children,HasOperations::meta, "");
		Uml::SetGenericRole(HasOperations::meta_ExceptionDef_children,HasOperations::meta, "");

		Uml::SetClass(SupportsInterfaces::meta, umldiagram, "SupportsInterfaces");
		Uml::SetGenericRole(SupportsInterfaces::meta_Supports_children,SupportsInterfaces::meta, "");

		Uml::SetClass(Supports::meta, umldiagram, "Supports");
		Uml::SetGenericRole(Supports::meta_SupportsInterfaces_parent,Supports::meta, "");
		Uml::SetGenericRole(Supports::meta_ref,ObjectDef::meta, "referedbySupports");

		Uml::SetClass(ReadonlyAttribute::meta, umldiagram, "ReadonlyAttribute");
		Uml::SetGenericRole(ReadonlyAttribute::meta_Inheritable_parent,ReadonlyAttribute::meta, "");
		Uml::SetGenericRole(ReadonlyAttribute::meta_GetException_children,ReadonlyAttribute::meta, "");
		Uml::SetGenericRole(ReadonlyAttribute::meta_Member_child,ReadonlyAttribute::meta, "");

		Uml::SetClass(Attribute::meta, umldiagram, "Attribute");
		Uml::SetGenericRole(Attribute::meta_SetException_children,Attribute::meta, "");

		Uml::SetClass(LookupKey::meta, umldiagram, "LookupKey");
		Uml::SetGenericRole(LookupKey::meta_ComponentFactory_parent,LookupKey::meta, "");
		Uml::SetGenericRole(LookupKey::meta_ref,ValueDef::meta, "referedbyLookupKey");

		Uml::SetClass(Manages::meta, umldiagram, "Manages");
		Uml::SetGenericRole(Manages::meta_ComponentFactory_parent,Manages::meta, "");
		Uml::SetGenericRole(Manages::meta_ref,ComponentDef::meta, "referedbyManages");

		Uml::SetClass(SetException::meta, umldiagram, "SetException");
		Uml::SetGenericRole(SetException::meta_Attribute_parent,SetException::meta, "");
		Uml::SetGenericRole(SetException::meta_ref,ExceptionDef::meta, "referedbySetException");

		Uml::SetClass(ObjectByValue::meta, umldiagram, "ObjectByValue");
		Uml::SetAttribute(ObjectByValue::meta_custom,ObjectByValue::meta, "custom");
		Uml::SetAttribute(ObjectByValue::meta_abstract,ObjectByValue::meta, "abstract");
		Uml::SetAttribute(ObjectByValue::meta_truncatable,ObjectByValue::meta, "truncatable");
		Uml::SetGenericRole(ObjectByValue::meta_Member_children,ObjectByValue::meta, "");
		Uml::SetGenericRole(ObjectByValue::meta_FactoryOperation_children,ObjectByValue::meta, "");
		Uml::SetGenericRole(ObjectByValue::meta_PrivateFlag_children,ObjectByValue::meta, "");
		Uml::SetGenericRole(ObjectByValue::meta_MakeMemberPrivate_children,ObjectByValue::meta, "");

		Uml::SetClass(GetException::meta, umldiagram, "GetException");
		Uml::SetGenericRole(GetException::meta_ReadonlyAttribute_parent,GetException::meta, "");
		Uml::SetGenericRole(GetException::meta_ref,ExceptionDef::meta, "referedbyGetException");

		Uml::SetClass(PrivateFlag::meta, umldiagram, "PrivateFlag");
		Uml::SetGenericRole(PrivateFlag::meta_ObjectByValue_parent,PrivateFlag::meta, "");
		Uml::SetGenericRole(PrivateFlag::meta_srcMakeMemberPrivate,Member::meta, "dstMakeMemberPrivate");
		Member::meta_dstMakeMemberPrivate_rev = PrivateFlag::meta_srcMakeMemberPrivate;

		Uml::SetClass(MakeMemberPrivate::meta, umldiagram, "MakeMemberPrivate");
		Uml::SetGenericRole(MakeMemberPrivate::meta_ObjectByValue_parent,MakeMemberPrivate::meta, "");
		MakeMemberPrivate::meta_srcMakeMemberPrivate_end_ = PrivateFlag::meta_srcMakeMemberPrivate;
		MakeMemberPrivate::meta_dstMakeMemberPrivate_end_ = Member::meta_dstMakeMemberPrivate;

		Uml::SetClass(RootFolder::meta, umldiagram, "RootFolder");
		Uml::SetAttribute(RootFolder::meta_name,RootFolder::meta, "name");
		Uml::SetGenericRole(RootFolder::meta_RootFolder_parent,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_IDLFiles_children,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_ImplementationArtifacts_children,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_ComponentTypes_children,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_ComponentImplementations_children,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_PackageConfigurations_children,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_ComponentPackages_children,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_TopLevelPackageFolder_children,RootFolder::meta, "");
		Uml::SetGenericRole(RootFolder::meta_RootFolder_children,RootFolder::meta, "");

		Uml::SetClass(MgaObject::meta, umldiagram, "MgaObject");
		Uml::SetAttribute(MgaObject::meta_position,MgaObject::meta, "position");
		Uml::SetAttribute(MgaObject::meta_name,MgaObject::meta, "name");

		
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
