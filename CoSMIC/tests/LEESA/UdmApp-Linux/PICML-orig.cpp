// cpp (meta datanetwork format) source file PICML.cpp
// generated from diagram PICML
// generated on Wed Dec 09 21:45:55 2009

#include "PICML.h"
#include <UmlExt.h>
#include <UdmStatic.h>


namespace PICML {

	::Uml::Class InfoProperty::meta;
	::Uml::CompositionParentRole InfoProperty::meta_ImplementationContainer_parent;
	::Uml::AssociationRole InfoProperty::meta_srcInfoProperty_end_;
	::Uml::AssociationRole InfoProperty::meta_dstInfoProperty_end_;

	template <> const ::Uml::CompositionParentRole& InfoProperty::_type2CPRole< InfoProperty::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& InfoProperty::_type2ARole< InfoProperty::ACE_srcInfoProperty >() const { return meta_srcInfoProperty_end_; }
	template <> const ::Uml::AssociationRole& InfoProperty::_type2ARole< InfoProperty::ACE_dstInfoProperty >() const { return meta_dstInfoProperty_end_; }

	::Uml::Class ConfigProperty::meta;
	::Uml::CompositionParentRole ConfigProperty::meta_ImplementationContainer_parent;
	::Uml::AssociationRole ConfigProperty::meta_srcConfigProperty_end_;
	::Uml::AssociationRole ConfigProperty::meta_dstConfigProperty_end_;

	template <> const ::Uml::CompositionParentRole& ConfigProperty::_type2CPRole< ConfigProperty::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& ConfigProperty::_type2ARole< ConfigProperty::ACE_srcConfigProperty >() const { return meta_srcConfigProperty_end_; }
	template <> const ::Uml::AssociationRole& ConfigProperty::_type2ARole< ConfigProperty::ACE_dstConfigProperty >() const { return meta_dstConfigProperty_end_; }

	::Uml::Class MonolithprimaryArtifact::meta;
	::Uml::CompositionParentRole MonolithprimaryArtifact::meta_ImplementationContainer_parent;
	::Uml::AssociationRole MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_;
	::Uml::AssociationRole MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_;

	template <> const ::Uml::CompositionParentRole& MonolithprimaryArtifact::_type2CPRole< MonolithprimaryArtifact::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& MonolithprimaryArtifact::_type2ARole< MonolithprimaryArtifact::ACE_srcMonolithprimaryArtifact >() const { return meta_srcMonolithprimaryArtifact_end_; }
	template <> const ::Uml::AssociationRole& MonolithprimaryArtifact::_type2ARole< MonolithprimaryArtifact::ACE_dstMonolithprimaryArtifact >() const { return meta_dstMonolithprimaryArtifact_end_; }

	::Uml::Class MonolithDeployRequirement::meta;
	::Uml::CompositionParentRole MonolithDeployRequirement::meta_ImplementationContainer_parent;
	::Uml::AssociationRole MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_;
	::Uml::AssociationRole MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_;

	template <> const ::Uml::CompositionParentRole& MonolithDeployRequirement::_type2CPRole< MonolithDeployRequirement::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& MonolithDeployRequirement::_type2ARole< MonolithDeployRequirement::ACE_srcMonolithDeployRequirement >() const { return meta_srcMonolithDeployRequirement_end_; }
	template <> const ::Uml::AssociationRole& MonolithDeployRequirement::_type2ARole< MonolithDeployRequirement::ACE_dstMonolithDeployRequirement >() const { return meta_dstMonolithDeployRequirement_end_; }

	::Uml::Class MonolithExecParameter::meta;
	::Uml::CompositionParentRole MonolithExecParameter::meta_ImplementationContainer_parent;
	::Uml::AssociationRole MonolithExecParameter::meta_srcMonolithExecParameter_end_;
	::Uml::AssociationRole MonolithExecParameter::meta_dstMonolithExecParameter_end_;

	template <> const ::Uml::CompositionParentRole& MonolithExecParameter::_type2CPRole< MonolithExecParameter::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& MonolithExecParameter::_type2ARole< MonolithExecParameter::ACE_srcMonolithExecParameter >() const { return meta_srcMonolithExecParameter_end_; }
	template <> const ::Uml::AssociationRole& MonolithExecParameter::_type2ARole< MonolithExecParameter::ACE_dstMonolithExecParameter >() const { return meta_dstMonolithExecParameter_end_; }

	::Uml::Class ComponentServantArtifact::meta;
	::Uml::Attribute ComponentServantArtifact::meta_EntryPoint;
	::Uml::AssociationRole ComponentServantArtifact::meta_ref;

	template <> const ::Uml::AssociationRole& ComponentServantArtifact::_type2ARole< ComponentServantArtifact::AR_ref >() const { return meta_ref; }

	::Uml::Class ComponentImplementationArtifact::meta;
	::Uml::Attribute ComponentImplementationArtifact::meta_EntryPoint;
	::Uml::AssociationRole ComponentImplementationArtifact::meta_ref;

	template <> const ::Uml::AssociationRole& ComponentImplementationArtifact::_type2ARole< ComponentImplementationArtifact::AR_ref >() const { return meta_ref; }

	::Uml::Class ImplementationContainer::meta;
	::Uml::CompositionChildRole ImplementationContainer::meta_ConfigProperty_children;
	::Uml::CompositionChildRole ImplementationContainer::meta_InfoProperty_children;
	::Uml::CompositionChildRole ImplementationContainer::meta_Property_children;
	::Uml::CompositionChildRole ImplementationContainer::meta_MonolithprimaryArtifact_children;
	::Uml::CompositionChildRole ImplementationContainer::meta_MonolithDeployRequirement_children;
	::Uml::CompositionChildRole ImplementationContainer::meta_MonolithExecParameter_children;
	::Uml::CompositionChildRole ImplementationContainer::meta_ImplementationArtifactReference_children;
	::Uml::CompositionChildRole ImplementationContainer::meta_ImplementationRequirement_children;

	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_ConfigProperty_children >() const { return meta_ConfigProperty_children; }
	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_InfoProperty_children >() const { return meta_InfoProperty_children; }
	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_MonolithprimaryArtifact_children >() const { return meta_MonolithprimaryArtifact_children; }
	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_MonolithDeployRequirement_children >() const { return meta_MonolithDeployRequirement_children; }
	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_MonolithExecParameter_children >() const { return meta_MonolithExecParameter_children; }
	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_ImplementationArtifactReference_children >() const { return meta_ImplementationArtifactReference_children; }
	template <> const ::Uml::CompositionChildRole& ImplementationContainer::_type2CCRole< ImplementationContainer::CR_ImplementationRequirement_children >() const { return meta_ImplementationRequirement_children; }

	::Uml::Class MonolithicImplementationBase::meta;
	::Uml::AssociationRole MonolithicImplementationBase::meta_dstMonolithExecParameter;
	::Uml::AssociationRole MonolithicImplementationBase::meta_dstMonolithExecParameter_rev;
	::Uml::AssociationRole MonolithicImplementationBase::meta_dstMonolithDeployRequirement;
	::Uml::AssociationRole MonolithicImplementationBase::meta_dstMonolithDeployRequirement_rev;
	::Uml::AssociationRole MonolithicImplementationBase::meta_dstMonolithprimaryArtifact;
	::Uml::AssociationRole MonolithicImplementationBase::meta_dstMonolithprimaryArtifact_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MonolithicImplementationBase::_type2ACARole< MonolithicImplementationBase::AR_dstMonolithExecParameter >() const { return make_pair(&meta_dstMonolithExecParameter, &meta_dstMonolithExecParameter_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MonolithicImplementationBase::_type2ACARole< MonolithicImplementationBase::AR_dstMonolithDeployRequirement >() const { return make_pair(&meta_dstMonolithDeployRequirement, &meta_dstMonolithDeployRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MonolithicImplementationBase::_type2ACARole< MonolithicImplementationBase::AR_dstMonolithprimaryArtifact >() const { return make_pair(&meta_dstMonolithprimaryArtifact, &meta_dstMonolithprimaryArtifact_rev); }

	::Uml::Class Implemenation::meta;
	::Uml::Attribute Implemenation::meta_UUID;
	::Uml::Attribute Implemenation::meta_label;
	::Uml::AssociationRole Implemenation::meta_dstInfoProperty;
	::Uml::AssociationRole Implemenation::meta_dstInfoProperty_rev;
	::Uml::AssociationRole Implemenation::meta_dstConfigProperty;
	::Uml::AssociationRole Implemenation::meta_dstConfigProperty_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Implemenation::_type2ACARole< Implemenation::AR_dstInfoProperty >() const { return make_pair(&meta_dstInfoProperty, &meta_dstInfoProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Implemenation::_type2ACARole< Implemenation::AR_dstConfigProperty >() const { return make_pair(&meta_dstConfigProperty, &meta_dstConfigProperty_rev); }

	::Uml::Class ComponentFactoryImplementations::meta;
	::Uml::Attribute ComponentFactoryImplementations::meta_name;
	::Uml::CompositionChildRole ComponentFactoryImplementations::meta_ComponentFactoryImplementationContainer_children;
	::Uml::CompositionParentRole ComponentFactoryImplementations::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ComponentFactoryImplementations::_type2CCRole< ComponentFactoryImplementations::CR_ComponentFactoryImplementationContainer_children >() const { return meta_ComponentFactoryImplementationContainer_children; }
	template <> const ::Uml::CompositionParentRole& ComponentFactoryImplementations::_type2CPRole< ComponentFactoryImplementations::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class ComponentFactoryImplementationContainer::meta;
	::Uml::CompositionChildRole ComponentFactoryImplementationContainer::meta_ComponentFactoryInstance_children;
	::Uml::CompositionParentRole ComponentFactoryImplementationContainer::meta_ComponentFactoryImplementations_parent;

	template <> const ::Uml::CompositionChildRole& ComponentFactoryImplementationContainer::_type2CCRole< ComponentFactoryImplementationContainer::CR_ComponentFactoryInstance_children >() const { return meta_ComponentFactoryInstance_children; }
	template <> const ::Uml::CompositionParentRole& ComponentFactoryImplementationContainer::_type2CPRole< ComponentFactoryImplementationContainer::PR_ComponentFactoryImplementations_parent >() const { return meta_ComponentFactoryImplementations_parent; }

	::Uml::Class ComponentFactoryInstance::meta;
	::Uml::AssociationRole ComponentFactoryInstance::meta_referedbyComponentFactoryRef;
	::Uml::AssociationRole ComponentFactoryInstance::meta_ref;
	::Uml::CompositionParentRole ComponentFactoryInstance::meta_ComponentFactoryImplementationContainer_parent;

	template <> const ::Uml::AssociationRole& ComponentFactoryInstance::_type2ARole< ComponentFactoryInstance::AR_referedbyComponentFactoryRef >() const { return meta_referedbyComponentFactoryRef; }
	template <> const ::Uml::AssociationRole& ComponentFactoryInstance::_type2ARole< ComponentFactoryInstance::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& ComponentFactoryInstance::_type2CPRole< ComponentFactoryInstance::PR_ComponentFactoryImplementationContainer_parent >() const { return meta_ComponentFactoryImplementationContainer_parent; }

	::Uml::Class RTRequirements::meta;
	::Uml::CompositionChildRole RTRequirements::meta_ServiceProvider_child;
	::Uml::CompositionChildRole RTRequirements::meta_ServiceConsumer_child;

	template <> const ::Uml::CompositionChildRole& RTRequirements::_type2CCRole< RTRequirements::CR_ServiceProvider_child >() const { return meta_ServiceProvider_child; }
	template <> const ::Uml::CompositionChildRole& RTRequirements::_type2CCRole< RTRequirements::CR_ServiceConsumer_child >() const { return meta_ServiceConsumer_child; }

	::Uml::Class ServiceProvider::meta;
	::Uml::Attribute ServiceProvider::meta_fixed_prioirty_service_execution;
	::Uml::CompositionChildRole ServiceProvider::meta_ServiceLevels_child;
	::Uml::CompositionChildRole ServiceProvider::meta_MultipleServiceRequests_child;
	::Uml::CompositionParentRole ServiceProvider::meta_RTRequirements_parent;

	template <> const ::Uml::CompositionChildRole& ServiceProvider::_type2CCRole< ServiceProvider::CR_ServiceLevels_child >() const { return meta_ServiceLevels_child; }
	template <> const ::Uml::CompositionChildRole& ServiceProvider::_type2CCRole< ServiceProvider::CR_MultipleServiceRequests_child >() const { return meta_MultipleServiceRequests_child; }
	template <> const ::Uml::CompositionParentRole& ServiceProvider::_type2CPRole< ServiceProvider::PR_RTRequirements_parent >() const { return meta_RTRequirements_parent; }

	::Uml::Class MultipleServiceRequests::meta;
	::Uml::Attribute MultipleServiceRequests::meta_simultaneous_service_execution;
	::Uml::Attribute MultipleServiceRequests::meta_minimum_simultaneous_service_level;
	::Uml::Attribute MultipleServiceRequests::meta_buffer_service_requests;
	::Uml::Attribute MultipleServiceRequests::meta_maximum_simultaneous_service_level;
	::Uml::CompositionParentRole MultipleServiceRequests::meta_ServiceProvider_parent;

	template <> const ::Uml::CompositionParentRole& MultipleServiceRequests::_type2CPRole< MultipleServiceRequests::PR_ServiceProvider_parent >() const { return meta_ServiceProvider_parent; }

	::Uml::Class ServiceLevels::meta;
	::Uml::Attribute ServiceLevels::meta_varying_service_levels;
	::Uml::CompositionParentRole ServiceLevels::meta_ServiceProvider_parent;

	template <> const ::Uml::CompositionParentRole& ServiceLevels::_type2CPRole< ServiceLevels::PR_ServiceProvider_parent >() const { return meta_ServiceProvider_parent; }

	::Uml::Class ServiceConsumer::meta;
	::Uml::Attribute ServiceConsumer::meta_prioritize_service_invocations;
	::Uml::CompositionParentRole ServiceConsumer::meta_RTRequirements_parent;

	template <> const ::Uml::CompositionParentRole& ServiceConsumer::_type2CPRole< ServiceConsumer::PR_RTRequirements_parent >() const { return meta_RTRequirements_parent; }

	::Uml::Class ECBehavior::meta;
	::Uml::Attribute ECBehavior::meta_ConsumerBasedFiltering;
	::Uml::Attribute ECBehavior::meta_SupplierBasedFiltering;
	::Uml::Attribute ECBehavior::meta_DisconnectDanglingConnections;
	::Uml::Attribute ECBehavior::meta_MultithreadedConsumer;
	::Uml::Attribute ECBehavior::meta_DispatchingMultithreadingLevel;
	::Uml::Attribute ECBehavior::meta_MultithreadedSupplier;
	::Uml::CompositionParentRole ECBehavior::meta_ECRequirements_parent;

	template <> const ::Uml::CompositionParentRole& ECBehavior::_type2CPRole< ECBehavior::PR_ECRequirements_parent >() const { return meta_ECRequirements_parent; }

	::Uml::Class ECRequirements::meta;
	::Uml::Attribute ECRequirements::meta_ConfigureRTQoS;
	::Uml::CompositionChildRole ECRequirements::meta_ECRole_children;
	::Uml::CompositionChildRole ECRequirements::meta_ECBehavior_child;

	template <> const ::Uml::CompositionChildRole& ECRequirements::_type2CCRole< ECRequirements::CR_ECRole_children >() const { return meta_ECRole_children; }
	template <> const ::Uml::CompositionChildRole& ECRequirements::_type2CCRole< ECRequirements::CR_ECBehavior_child >() const { return meta_ECBehavior_child; }

	::Uml::Class ECRole::meta;
	::Uml::Attribute ECRole::meta_rolekind;
	::Uml::Attribute ECRole::meta_ECFilterType;
	::Uml::CompositionParentRole ECRole::meta_ECRequirements_parent;

	template <> const ::Uml::CompositionParentRole& ECRole::_type2CPRole< ECRole::PR_ECRequirements_parent >() const { return meta_ECRequirements_parent; }

	::Uml::Class ExternalPortReferenceType::meta;
	::Uml::AssociationRole ExternalPortReferenceType::meta_referedbyExternalPortReference;

	template <> const ::Uml::AssociationRole& ExternalPortReferenceType::_type2ARole< ExternalPortReferenceType::AR_referedbyExternalPortReference >() const { return meta_referedbyExternalPortReference; }

	::Uml::Class ComponentAssemblyReference::meta;
	::Uml::AssociationRole ComponentAssemblyReference::meta_ref;
	::Uml::CompositionParentRole ComponentAssemblyReference::meta_ComponentAssembly_parent;

	template <> const ::Uml::AssociationRole& ComponentAssemblyReference::_type2ARole< ComponentAssemblyReference::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& ComponentAssemblyReference::_type2CPRole< ComponentAssemblyReference::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class ComponentAssembly::meta;
	::Uml::AssociationRole ComponentAssembly::meta_referedbyComponentAssemblyReference;
	::Uml::AssociationRole ComponentAssembly::meta_dstCriticalPath;
	::Uml::AssociationRole ComponentAssembly::meta_dstCriticalPath_rev;
	::Uml::CompositionChildRole ComponentAssembly::meta_Property_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ComponentPackage_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ComponentPackageReference_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_Requirement_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_Component_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ComponentAssembly_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ProvidedRequestPort_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_RequiredRequestPort_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_InEventPort_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_OutEventPort_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_emit_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_EventSourceDelegate_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_EventSinkDelegate_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_deliverTo_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_publish_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AssemblyDeployRequirement_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ComponentAssemblyReference_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ComponentRef_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AssemblyselectRequirement_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AttributeValue_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AttributeDelegate_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AttributeMappingValue_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AssemblyConfigProperty_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_FacetDelegate_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_invoke_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ReceptacleDelegate_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AttributeMappingDelegate_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ExternalDelegate_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_AttributeMapping_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_PublishConnector_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_ExternalPortReference_children;
	::Uml::CompositionChildRole ComponentAssembly::meta_SupportsDelegate_children;
	::Uml::CompositionParentRole ComponentAssembly::meta_ComponentAssembly_parent;

	template <> const ::Uml::AssociationRole& ComponentAssembly::_type2ARole< ComponentAssembly::AR_referedbyComponentAssemblyReference >() const { return meta_referedbyComponentAssemblyReference; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentAssembly::_type2ACARole< ComponentAssembly::AR_dstCriticalPath >() const { return make_pair(&meta_dstCriticalPath, &meta_dstCriticalPath_rev); }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ComponentPackage_children >() const { return meta_ComponentPackage_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ComponentPackageReference_children >() const { return meta_ComponentPackageReference_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_Requirement_children >() const { return meta_Requirement_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_Component_children >() const { return meta_Component_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ComponentAssembly_children >() const { return meta_ComponentAssembly_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ProvidedRequestPort_children >() const { return meta_ProvidedRequestPort_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_RequiredRequestPort_children >() const { return meta_RequiredRequestPort_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_InEventPort_children >() const { return meta_InEventPort_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_OutEventPort_children >() const { return meta_OutEventPort_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_emit_children >() const { return meta_emit_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_EventSourceDelegate_children >() const { return meta_EventSourceDelegate_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_EventSinkDelegate_children >() const { return meta_EventSinkDelegate_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_deliverTo_children >() const { return meta_deliverTo_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_publish_children >() const { return meta_publish_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AssemblyDeployRequirement_children >() const { return meta_AssemblyDeployRequirement_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ComponentAssemblyReference_children >() const { return meta_ComponentAssemblyReference_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ComponentRef_children >() const { return meta_ComponentRef_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AssemblyselectRequirement_children >() const { return meta_AssemblyselectRequirement_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AttributeValue_children >() const { return meta_AttributeValue_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AttributeDelegate_children >() const { return meta_AttributeDelegate_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AttributeMappingValue_children >() const { return meta_AttributeMappingValue_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AssemblyConfigProperty_children >() const { return meta_AssemblyConfigProperty_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_FacetDelegate_children >() const { return meta_FacetDelegate_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_invoke_children >() const { return meta_invoke_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ReceptacleDelegate_children >() const { return meta_ReceptacleDelegate_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AttributeMappingDelegate_children >() const { return meta_AttributeMappingDelegate_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ExternalDelegate_children >() const { return meta_ExternalDelegate_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_AttributeMapping_children >() const { return meta_AttributeMapping_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_PublishConnector_children >() const { return meta_PublishConnector_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_ExternalPortReference_children >() const { return meta_ExternalPortReference_children; }
	template <> const ::Uml::CompositionChildRole& ComponentAssembly::_type2CCRole< ComponentAssembly::CR_SupportsDelegate_children >() const { return meta_SupportsDelegate_children; }
	template <> const ::Uml::CompositionParentRole& ComponentAssembly::_type2CPRole< ComponentAssembly::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class ExternalPortReference::meta;
	::Uml::Attribute ExternalPortReference::meta_label;
	::Uml::Attribute ExternalPortReference::meta_location;
	::Uml::AssociationRole ExternalPortReference::meta_ref;
	::Uml::AssociationRole ExternalPortReference::meta_dstExternalDelegate;
	::Uml::AssociationRole ExternalPortReference::meta_dstExternalDelegate_rev;
	::Uml::CompositionParentRole ExternalPortReference::meta_ComponentAssembly_parent;

	template <> const ::Uml::AssociationRole& ExternalPortReference::_type2ARole< ExternalPortReference::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ExternalPortReference::_type2ACARole< ExternalPortReference::AR_dstExternalDelegate >() const { return make_pair(&meta_dstExternalDelegate, &meta_dstExternalDelegate_rev); }
	template <> const ::Uml::CompositionParentRole& ExternalPortReference::_type2CPRole< ExternalPortReference::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class ConnectedComponent::meta;
	::Uml::CompositionChildRole ConnectedComponent::meta_Port_children;
	::Uml::CompositionChildRole ConnectedComponent::meta_DstEdge_children;

	template <> const ::Uml::CompositionChildRole& ConnectedComponent::_type2CCRole< ConnectedComponent::CR_Port_children >() const { return meta_Port_children; }
	template <> const ::Uml::CompositionChildRole& ConnectedComponent::_type2CCRole< ConnectedComponent::CR_DstEdge_children >() const { return meta_DstEdge_children; }

	::Uml::Class Path::meta;
	::Uml::AssociationRole Path::meta_referedbyPathReference;
	::Uml::AssociationRole Path::meta_dstPathProperty;
	::Uml::AssociationRole Path::meta_dstPathProperty_rev;
	::Uml::CompositionChildRole Path::meta_ComponentRef_children;
	::Uml::CompositionChildRole Path::meta_DstEdge_children;
	::Uml::CompositionChildRole Path::meta_SrcEdge_children;
	::Uml::CompositionChildRole Path::meta_EdgeProperty_children;
	::Uml::CompositionChildRole Path::meta_Edge_children;
	::Uml::CompositionChildRole Path::meta_Property_children;
	::Uml::CompositionChildRole Path::meta_GraphVertex_children;
	::Uml::CompositionParentRole Path::meta_Paths_parent;

	template <> const ::Uml::AssociationRole& Path::_type2ARole< Path::AR_referedbyPathReference >() const { return meta_referedbyPathReference; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Path::_type2ACARole< Path::AR_dstPathProperty >() const { return make_pair(&meta_dstPathProperty, &meta_dstPathProperty_rev); }
	template <> const ::Uml::CompositionChildRole& Path::_type2CCRole< Path::CR_ComponentRef_children >() const { return meta_ComponentRef_children; }
	template <> const ::Uml::CompositionChildRole& Path::_type2CCRole< Path::CR_DstEdge_children >() const { return meta_DstEdge_children; }
	template <> const ::Uml::CompositionChildRole& Path::_type2CCRole< Path::CR_SrcEdge_children >() const { return meta_SrcEdge_children; }
	template <> const ::Uml::CompositionChildRole& Path::_type2CCRole< Path::CR_EdgeProperty_children >() const { return meta_EdgeProperty_children; }
	template <> const ::Uml::CompositionChildRole& Path::_type2CCRole< Path::CR_Edge_children >() const { return meta_Edge_children; }
	template <> const ::Uml::CompositionChildRole& Path::_type2CCRole< Path::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& Path::_type2CCRole< Path::CR_GraphVertex_children >() const { return meta_GraphVertex_children; }
	template <> const ::Uml::CompositionParentRole& Path::_type2CPRole< Path::PR_Paths_parent >() const { return meta_Paths_parent; }

	::Uml::Class PathDiagrams::meta;
	::Uml::Attribute PathDiagrams::meta_name;
	::Uml::CompositionChildRole PathDiagrams::meta_Paths_children;
	::Uml::CompositionParentRole PathDiagrams::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& PathDiagrams::_type2CCRole< PathDiagrams::CR_Paths_children >() const { return meta_Paths_children; }
	template <> const ::Uml::CompositionParentRole& PathDiagrams::_type2CPRole< PathDiagrams::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class DstEdge::meta;
	::Uml::CompositionParentRole DstEdge::meta_ConnectedComponent_parent;
	::Uml::CompositionParentRole DstEdge::meta_Path_parent;
	::Uml::AssociationRole DstEdge::meta_srcDstEdge_end_;
	::Uml::AssociationRole DstEdge::meta_dstDstEdge_end_;

	template <> const ::Uml::CompositionParentRole& DstEdge::_type2CPRole< DstEdge::PR_ConnectedComponent_parent >() const { return meta_ConnectedComponent_parent; }
	template <> const ::Uml::CompositionParentRole& DstEdge::_type2CPRole< DstEdge::PR_Path_parent >() const { return meta_Path_parent; }
	template <> const ::Uml::AssociationRole& DstEdge::_type2ARole< DstEdge::ACE_srcDstEdge >() const { return meta_srcDstEdge_end_; }
	template <> const ::Uml::AssociationRole& DstEdge::_type2ARole< DstEdge::ACE_dstDstEdge >() const { return meta_dstDstEdge_end_; }

	::Uml::Class GraphVertex::meta;
	::Uml::AssociationRole GraphVertex::meta_srcSrcEdge;
	::Uml::AssociationRole GraphVertex::meta_srcSrcEdge_rev;
	::Uml::AssociationRole GraphVertex::meta_dstDstEdge;
	::Uml::AssociationRole GraphVertex::meta_dstDstEdge_rev;
	::Uml::CompositionParentRole GraphVertex::meta_Path_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> GraphVertex::_type2ACARole< GraphVertex::AR_srcSrcEdge >() const { return make_pair(&meta_srcSrcEdge, &meta_srcSrcEdge_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> GraphVertex::_type2ACARole< GraphVertex::AR_dstDstEdge >() const { return make_pair(&meta_dstDstEdge, &meta_dstDstEdge_rev); }
	template <> const ::Uml::CompositionParentRole& GraphVertex::_type2CPRole< GraphVertex::PR_Path_parent >() const { return meta_Path_parent; }

	::Uml::Class SrcEdge::meta;
	::Uml::CompositionParentRole SrcEdge::meta_Path_parent;
	::Uml::AssociationRole SrcEdge::meta_dstSrcEdge_end_;
	::Uml::AssociationRole SrcEdge::meta_srcSrcEdge_end_;

	template <> const ::Uml::CompositionParentRole& SrcEdge::_type2CPRole< SrcEdge::PR_Path_parent >() const { return meta_Path_parent; }
	template <> const ::Uml::AssociationRole& SrcEdge::_type2ARole< SrcEdge::ACE_dstSrcEdge >() const { return meta_dstSrcEdge_end_; }
	template <> const ::Uml::AssociationRole& SrcEdge::_type2ARole< SrcEdge::ACE_srcSrcEdge >() const { return meta_srcSrcEdge_end_; }

	::Uml::Class EdgeProperty::meta;
	::Uml::CompositionParentRole EdgeProperty::meta_Path_parent;
	::Uml::AssociationRole EdgeProperty::meta_dstPropertyConnector_end_;
	::Uml::AssociationRole EdgeProperty::meta_srcPropertyConnector_end_;

	template <> const ::Uml::CompositionParentRole& EdgeProperty::_type2CPRole< EdgeProperty::PR_Path_parent >() const { return meta_Path_parent; }
	template <> const ::Uml::AssociationRole& EdgeProperty::_type2ARole< EdgeProperty::ACE_dstPropertyConnector >() const { return meta_dstPropertyConnector_end_; }
	template <> const ::Uml::AssociationRole& EdgeProperty::_type2ARole< EdgeProperty::ACE_srcPropertyConnector >() const { return meta_srcPropertyConnector_end_; }

	::Uml::Class Edge::meta;
	::Uml::AssociationRole Edge::meta_dstSrcEdge;
	::Uml::AssociationRole Edge::meta_dstSrcEdge_rev;
	::Uml::AssociationRole Edge::meta_srcDstEdge;
	::Uml::AssociationRole Edge::meta_srcDstEdge_rev;
	::Uml::AssociationRole Edge::meta_srcPropertyConnector;
	::Uml::AssociationRole Edge::meta_srcPropertyConnector_rev;
	::Uml::CompositionParentRole Edge::meta_Path_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Edge::_type2ACARole< Edge::AR_dstSrcEdge >() const { return make_pair(&meta_dstSrcEdge, &meta_dstSrcEdge_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Edge::_type2ACARole< Edge::AR_srcDstEdge >() const { return make_pair(&meta_srcDstEdge, &meta_srcDstEdge_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Edge::_type2ACARole< Edge::AR_srcPropertyConnector >() const { return make_pair(&meta_srcPropertyConnector, &meta_srcPropertyConnector_rev); }
	template <> const ::Uml::CompositionParentRole& Edge::_type2CPRole< Edge::PR_Path_parent >() const { return meta_Path_parent; }

	::Uml::Class DisplayNode::meta;

	::Uml::Class Paths::meta;
	::Uml::CompositionChildRole Paths::meta_PathProperty_children;
	::Uml::CompositionChildRole Paths::meta_Path_children;
	::Uml::CompositionChildRole Paths::meta_Property_children;
	::Uml::CompositionParentRole Paths::meta_PathDiagrams_parent;

	template <> const ::Uml::CompositionChildRole& Paths::_type2CCRole< Paths::CR_PathProperty_children >() const { return meta_PathProperty_children; }
	template <> const ::Uml::CompositionChildRole& Paths::_type2CCRole< Paths::CR_Path_children >() const { return meta_Path_children; }
	template <> const ::Uml::CompositionChildRole& Paths::_type2CCRole< Paths::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionParentRole& Paths::_type2CPRole< Paths::PR_PathDiagrams_parent >() const { return meta_PathDiagrams_parent; }

	::Uml::Class PathProperty::meta;
	::Uml::CompositionParentRole PathProperty::meta_Paths_parent;
	::Uml::AssociationRole PathProperty::meta_srcPathProperty_end_;
	::Uml::AssociationRole PathProperty::meta_dstPathProperty_end_;

	template <> const ::Uml::CompositionParentRole& PathProperty::_type2CPRole< PathProperty::PR_Paths_parent >() const { return meta_Paths_parent; }
	template <> const ::Uml::AssociationRole& PathProperty::_type2ARole< PathProperty::ACE_srcPathProperty >() const { return meta_srcPathProperty_end_; }
	template <> const ::Uml::AssociationRole& PathProperty::_type2ARole< PathProperty::ACE_dstPathProperty >() const { return meta_dstPathProperty_end_; }

	::Uml::Class PathReference::meta;
	::Uml::AssociationRole PathReference::meta_srcCriticalPath;
	::Uml::AssociationRole PathReference::meta_srcCriticalPath_rev;
	::Uml::AssociationRole PathReference::meta_ref;
	::Uml::CompositionParentRole PathReference::meta_ComponentImplementationContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PathReference::_type2ACARole< PathReference::AR_srcCriticalPath >() const { return make_pair(&meta_srcCriticalPath, &meta_srcCriticalPath_rev); }
	template <> const ::Uml::AssociationRole& PathReference::_type2ARole< PathReference::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& PathReference::_type2CPRole< PathReference::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }

	::Uml::Class MetricConnection::meta;
	::Uml::CompositionParentRole MetricConnection::meta_BenchmarkAnalysis_parent;
	::Uml::AssociationRole MetricConnection::meta_dstMetricConnection_end_;
	::Uml::AssociationRole MetricConnection::meta_srcMetricConnection_end_;

	template <> const ::Uml::CompositionParentRole& MetricConnection::_type2CPRole< MetricConnection::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }
	template <> const ::Uml::AssociationRole& MetricConnection::_type2ARole< MetricConnection::ACE_dstMetricConnection >() const { return meta_dstMetricConnection_end_; }
	template <> const ::Uml::AssociationRole& MetricConnection::_type2ARole< MetricConnection::ACE_srcMetricConnection >() const { return meta_srcMetricConnection_end_; }

	::Uml::Class DataAnalysisBase::meta;
	::Uml::CompositionParentRole DataAnalysisBase::meta_MetricsBase_parent;
	::Uml::CompositionParentRole DataAnalysisBase::meta_BenchmarkAnalysis_parent;

	template <> const ::Uml::CompositionParentRole& DataAnalysisBase::_type2CPRole< DataAnalysisBase::PR_MetricsBase_parent >() const { return meta_MetricsBase_parent; }
	template <> const ::Uml::CompositionParentRole& DataAnalysisBase::_type2CPRole< DataAnalysisBase::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class Average::meta;

	::Uml::Class Minimum::meta;

	::Uml::Class Maximum::meta;

	::Uml::Class Jitter::meta;

	::Uml::Class TimeProbe::meta;
	::Uml::AssociationRole TimeProbe::meta_srcTimerEventSinkConn;
	::Uml::AssociationRole TimeProbe::meta_srcTimerEventSinkConn_rev;
	::Uml::AssociationRole TimeProbe::meta_srcTimerConnection;
	::Uml::AssociationRole TimeProbe::meta_srcTimerConnection_rev;
	::Uml::CompositionParentRole TimeProbe::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> TimeProbe::_type2ACARole< TimeProbe::AR_srcTimerEventSinkConn >() const { return make_pair(&meta_srcTimerEventSinkConn, &meta_srcTimerEventSinkConn_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> TimeProbe::_type2ACARole< TimeProbe::AR_srcTimerConnection >() const { return make_pair(&meta_srcTimerConnection, &meta_srcTimerConnection_rev); }
	template <> const ::Uml::CompositionParentRole& TimeProbe::_type2CPRole< TimeProbe::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class TimerConnection::meta;
	::Uml::CompositionParentRole TimerConnection::meta_BenchmarkAnalysis_parent;
	::Uml::AssociationRole TimerConnection::meta_dstTimerConnection_end_;
	::Uml::AssociationRole TimerConnection::meta_srcTimerConnection_end_;

	template <> const ::Uml::CompositionParentRole& TimerConnection::_type2CPRole< TimerConnection::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }
	template <> const ::Uml::AssociationRole& TimerConnection::_type2ARole< TimerConnection::ACE_dstTimerConnection >() const { return meta_dstTimerConnection_end_; }
	template <> const ::Uml::AssociationRole& TimerConnection::_type2ARole< TimerConnection::ACE_srcTimerConnection >() const { return meta_srcTimerConnection_end_; }

	::Uml::Class Latency::meta;

	::Uml::Class Throughput::meta;

	::Uml::Class ComponentAnalyses::meta;
	::Uml::Attribute ComponentAnalyses::meta_name;
	::Uml::CompositionChildRole ComponentAnalyses::meta_BenchmarkAnalysis_children;
	::Uml::CompositionParentRole ComponentAnalyses::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ComponentAnalyses::_type2CCRole< ComponentAnalyses::CR_BenchmarkAnalysis_children >() const { return meta_BenchmarkAnalysis_children; }
	template <> const ::Uml::CompositionParentRole& ComponentAnalyses::_type2CPRole< ComponentAnalyses::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class BenchmarkAnalysis::meta;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_TimerConnection_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_OperationBase_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_MetricConnection_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_DataAnalysisBase_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_MetricsBase_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_TimeProbe_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_OperationRef_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_EventRef_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_Event_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_TimerEventSinkConn_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_TaskSet_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_Task_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_WorkloadCharacteristics_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_ComponentOperation_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_CompRef_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_WorkLoadOperationConnection_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_BenchmarkType_children;
	::Uml::CompositionChildRole BenchmarkAnalysis::meta_BenchmarkCharacteristics_children;
	::Uml::CompositionParentRole BenchmarkAnalysis::meta_ComponentAnalyses_parent;

	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_TimerConnection_children >() const { return meta_TimerConnection_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_OperationBase_children >() const { return meta_OperationBase_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_MetricConnection_children >() const { return meta_MetricConnection_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_DataAnalysisBase_children >() const { return meta_DataAnalysisBase_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_MetricsBase_children >() const { return meta_MetricsBase_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_TimeProbe_children >() const { return meta_TimeProbe_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_OperationRef_children >() const { return meta_OperationRef_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_EventRef_children >() const { return meta_EventRef_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_Event_children >() const { return meta_Event_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_TimerEventSinkConn_children >() const { return meta_TimerEventSinkConn_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_TaskSet_children >() const { return meta_TaskSet_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_Task_children >() const { return meta_Task_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_WorkloadCharacteristics_children >() const { return meta_WorkloadCharacteristics_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_ComponentOperation_children >() const { return meta_ComponentOperation_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_CompRef_children >() const { return meta_CompRef_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_WorkLoadOperationConnection_children >() const { return meta_WorkLoadOperationConnection_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_BenchmarkType_children >() const { return meta_BenchmarkType_children; }
	template <> const ::Uml::CompositionChildRole& BenchmarkAnalysis::_type2CCRole< BenchmarkAnalysis::CR_BenchmarkCharacteristics_children >() const { return meta_BenchmarkCharacteristics_children; }
	template <> const ::Uml::CompositionParentRole& BenchmarkAnalysis::_type2CPRole< BenchmarkAnalysis::PR_ComponentAnalyses_parent >() const { return meta_ComponentAnalyses_parent; }

	::Uml::Class MetricsBase::meta;
	::Uml::Attribute MetricsBase::meta_warmup;
	::Uml::Attribute MetricsBase::meta_fileName;
	::Uml::Attribute MetricsBase::meta_iterations;
	::Uml::Attribute MetricsBase::meta_priority;
	::Uml::Attribute MetricsBase::meta_rate;
	::Uml::Attribute MetricsBase::meta_resolution;
	::Uml::AssociationRole MetricsBase::meta_srcMetricConnection;
	::Uml::AssociationRole MetricsBase::meta_srcMetricConnection_rev;
	::Uml::AssociationRole MetricsBase::meta_dstWorkloadCharacteristics;
	::Uml::AssociationRole MetricsBase::meta_dstWorkloadCharacteristics_rev;
	::Uml::AssociationRole MetricsBase::meta_srcBenchmarkCharacteristics;
	::Uml::AssociationRole MetricsBase::meta_srcBenchmarkCharacteristics_rev;
	::Uml::CompositionChildRole MetricsBase::meta_DataAnalysisBase_children;
	::Uml::CompositionParentRole MetricsBase::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MetricsBase::_type2ACARole< MetricsBase::AR_srcMetricConnection >() const { return make_pair(&meta_srcMetricConnection, &meta_srcMetricConnection_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MetricsBase::_type2ACARole< MetricsBase::AR_dstWorkloadCharacteristics >() const { return make_pair(&meta_dstWorkloadCharacteristics, &meta_dstWorkloadCharacteristics_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MetricsBase::_type2ACARole< MetricsBase::AR_srcBenchmarkCharacteristics >() const { return make_pair(&meta_srcBenchmarkCharacteristics, &meta_srcBenchmarkCharacteristics_rev); }
	template <> const ::Uml::CompositionChildRole& MetricsBase::_type2CCRole< MetricsBase::CR_DataAnalysisBase_children >() const { return meta_DataAnalysisBase_children; }
	template <> const ::Uml::CompositionParentRole& MetricsBase::_type2CPRole< MetricsBase::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class OperationRef::meta;
	::Uml::AssociationRole OperationRef::meta_dstTimerConnection;
	::Uml::AssociationRole OperationRef::meta_dstTimerConnection_rev;
	::Uml::AssociationRole OperationRef::meta_dstMetricConnection;
	::Uml::AssociationRole OperationRef::meta_dstMetricConnection_rev;
	::Uml::AssociationRole OperationRef::meta_dstComponentOperation;
	::Uml::AssociationRole OperationRef::meta_dstComponentOperation_rev;
	::Uml::AssociationRole OperationRef::meta_dstWorkLoadOperationConnection;
	::Uml::AssociationRole OperationRef::meta_dstWorkLoadOperationConnection_rev;
	::Uml::AssociationRole OperationRef::meta_ref;
	::Uml::CompositionParentRole OperationRef::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OperationRef::_type2ACARole< OperationRef::AR_dstTimerConnection >() const { return make_pair(&meta_dstTimerConnection, &meta_dstTimerConnection_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OperationRef::_type2ACARole< OperationRef::AR_dstMetricConnection >() const { return make_pair(&meta_dstMetricConnection, &meta_dstMetricConnection_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OperationRef::_type2ACARole< OperationRef::AR_dstComponentOperation >() const { return make_pair(&meta_dstComponentOperation, &meta_dstComponentOperation_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OperationRef::_type2ACARole< OperationRef::AR_dstWorkLoadOperationConnection >() const { return make_pair(&meta_dstWorkLoadOperationConnection, &meta_dstWorkLoadOperationConnection_rev); }
	template <> const ::Uml::AssociationRole& OperationRef::_type2ARole< OperationRef::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& OperationRef::_type2CPRole< OperationRef::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class EventRef::meta;
	::Uml::AssociationRole EventRef::meta_dstTimerEventSinkConn;
	::Uml::AssociationRole EventRef::meta_dstTimerEventSinkConn_rev;
	::Uml::AssociationRole EventRef::meta_ref;
	::Uml::CompositionParentRole EventRef::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> EventRef::_type2ACARole< EventRef::AR_dstTimerEventSinkConn >() const { return make_pair(&meta_dstTimerEventSinkConn, &meta_dstTimerEventSinkConn_rev); }
	template <> const ::Uml::AssociationRole& EventRef::_type2ARole< EventRef::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& EventRef::_type2CPRole< EventRef::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class TimerEventSinkConn::meta;
	::Uml::CompositionParentRole TimerEventSinkConn::meta_BenchmarkAnalysis_parent;
	::Uml::AssociationRole TimerEventSinkConn::meta_dstTimerEventSinkConn_end_;
	::Uml::AssociationRole TimerEventSinkConn::meta_srcTimerEventSinkConn_end_;

	template <> const ::Uml::CompositionParentRole& TimerEventSinkConn::_type2CPRole< TimerEventSinkConn::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }
	template <> const ::Uml::AssociationRole& TimerEventSinkConn::_type2ARole< TimerEventSinkConn::ACE_dstTimerEventSinkConn >() const { return meta_dstTimerEventSinkConn_end_; }
	template <> const ::Uml::AssociationRole& TimerEventSinkConn::_type2ARole< TimerEventSinkConn::ACE_srcTimerEventSinkConn >() const { return meta_srcTimerEventSinkConn_end_; }

	::Uml::Class TaskSet::meta;
	::Uml::Attribute TaskSet::meta_rate;
	::Uml::Attribute TaskSet::meta_priority;
	::Uml::AssociationRole TaskSet::meta_srcWorkloadCharacteristics;
	::Uml::AssociationRole TaskSet::meta_srcWorkloadCharacteristics_rev;
	::Uml::AssociationRole TaskSet::meta_members;
	::Uml::CompositionParentRole TaskSet::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> TaskSet::_type2ACARole< TaskSet::AR_srcWorkloadCharacteristics >() const { return make_pair(&meta_srcWorkloadCharacteristics, &meta_srcWorkloadCharacteristics_rev); }
	template <> const ::Uml::AssociationRole& TaskSet::_type2ARole< TaskSet::AR_members >() const { return meta_members; }
	template <> const ::Uml::CompositionParentRole& TaskSet::_type2CPRole< TaskSet::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class Task::meta;
	::Uml::AssociationRole Task::meta_srcWorkLoadOperationConnection;
	::Uml::AssociationRole Task::meta_srcWorkLoadOperationConnection_rev;
	::Uml::AssociationRole Task::meta_setTaskSet;
	::Uml::CompositionParentRole Task::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Task::_type2ACARole< Task::AR_srcWorkLoadOperationConnection >() const { return make_pair(&meta_srcWorkLoadOperationConnection, &meta_srcWorkLoadOperationConnection_rev); }
	template <> const ::Uml::AssociationRole& Task::_type2ARole< Task::AR_setTaskSet >() const { return meta_setTaskSet; }
	template <> const ::Uml::CompositionParentRole& Task::_type2CPRole< Task::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class WorkloadCharacteristics::meta;
	::Uml::CompositionParentRole WorkloadCharacteristics::meta_BenchmarkAnalysis_parent;
	::Uml::AssociationRole WorkloadCharacteristics::meta_srcWorkloadCharacteristics_end_;
	::Uml::AssociationRole WorkloadCharacteristics::meta_dstWorkloadCharacteristics_end_;

	template <> const ::Uml::CompositionParentRole& WorkloadCharacteristics::_type2CPRole< WorkloadCharacteristics::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }
	template <> const ::Uml::AssociationRole& WorkloadCharacteristics::_type2ARole< WorkloadCharacteristics::ACE_srcWorkloadCharacteristics >() const { return meta_srcWorkloadCharacteristics_end_; }
	template <> const ::Uml::AssociationRole& WorkloadCharacteristics::_type2ARole< WorkloadCharacteristics::ACE_dstWorkloadCharacteristics >() const { return meta_dstWorkloadCharacteristics_end_; }

	::Uml::Class ComponentOperation::meta;
	::Uml::CompositionParentRole ComponentOperation::meta_BenchmarkAnalysis_parent;
	::Uml::AssociationRole ComponentOperation::meta_srcComponentOperation_end_;
	::Uml::AssociationRole ComponentOperation::meta_dstComponentOperation_end_;

	template <> const ::Uml::CompositionParentRole& ComponentOperation::_type2CPRole< ComponentOperation::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }
	template <> const ::Uml::AssociationRole& ComponentOperation::_type2ARole< ComponentOperation::ACE_srcComponentOperation >() const { return meta_srcComponentOperation_end_; }
	template <> const ::Uml::AssociationRole& ComponentOperation::_type2ARole< ComponentOperation::ACE_dstComponentOperation >() const { return meta_dstComponentOperation_end_; }

	::Uml::Class CompRef::meta;
	::Uml::AssociationRole CompRef::meta_srcComponentOperation;
	::Uml::AssociationRole CompRef::meta_srcComponentOperation_rev;
	::Uml::AssociationRole CompRef::meta_ref;
	::Uml::CompositionParentRole CompRef::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> CompRef::_type2ACARole< CompRef::AR_srcComponentOperation >() const { return make_pair(&meta_srcComponentOperation, &meta_srcComponentOperation_rev); }
	template <> const ::Uml::AssociationRole& CompRef::_type2ARole< CompRef::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& CompRef::_type2CPRole< CompRef::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class WorkLoadOperationConnection::meta;
	::Uml::CompositionParentRole WorkLoadOperationConnection::meta_BenchmarkAnalysis_parent;
	::Uml::AssociationRole WorkLoadOperationConnection::meta_srcWorkLoadOperationConnection_end_;
	::Uml::AssociationRole WorkLoadOperationConnection::meta_dstWorkLoadOperationConnection_end_;

	template <> const ::Uml::CompositionParentRole& WorkLoadOperationConnection::_type2CPRole< WorkLoadOperationConnection::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }
	template <> const ::Uml::AssociationRole& WorkLoadOperationConnection::_type2ARole< WorkLoadOperationConnection::ACE_srcWorkLoadOperationConnection >() const { return meta_srcWorkLoadOperationConnection_end_; }
	template <> const ::Uml::AssociationRole& WorkLoadOperationConnection::_type2ARole< WorkLoadOperationConnection::ACE_dstWorkLoadOperationConnection >() const { return meta_dstWorkLoadOperationConnection_end_; }

	::Uml::Class BenchmarkType::meta;
	::Uml::AssociationRole BenchmarkType::meta_dstBenchmarkCharacteristics;
	::Uml::AssociationRole BenchmarkType::meta_dstBenchmarkCharacteristics_rev;
	::Uml::CompositionParentRole BenchmarkType::meta_BenchmarkAnalysis_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> BenchmarkType::_type2ACARole< BenchmarkType::AR_dstBenchmarkCharacteristics >() const { return make_pair(&meta_dstBenchmarkCharacteristics, &meta_dstBenchmarkCharacteristics_rev); }
	template <> const ::Uml::CompositionParentRole& BenchmarkType::_type2CPRole< BenchmarkType::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class TriggerBenchmarks::meta;

	::Uml::Class FixedIterationBenchmarks::meta;
	::Uml::Attribute FixedIterationBenchmarks::meta_benchmarkIterations;

	::Uml::Class PeriodicBenchmarks::meta;
	::Uml::Attribute PeriodicBenchmarks::meta_timeperiod;

	::Uml::Class BenchmarkCharacteristics::meta;
	::Uml::CompositionParentRole BenchmarkCharacteristics::meta_BenchmarkAnalysis_parent;
	::Uml::AssociationRole BenchmarkCharacteristics::meta_dstBenchmarkCharacteristics_end_;
	::Uml::AssociationRole BenchmarkCharacteristics::meta_srcBenchmarkCharacteristics_end_;

	template <> const ::Uml::CompositionParentRole& BenchmarkCharacteristics::_type2CPRole< BenchmarkCharacteristics::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }
	template <> const ::Uml::AssociationRole& BenchmarkCharacteristics::_type2ARole< BenchmarkCharacteristics::ACE_dstBenchmarkCharacteristics >() const { return meta_dstBenchmarkCharacteristics_end_; }
	template <> const ::Uml::AssociationRole& BenchmarkCharacteristics::_type2ARole< BenchmarkCharacteristics::ACE_srcBenchmarkCharacteristics >() const { return meta_srcBenchmarkCharacteristics_end_; }

	::Uml::Class NodeReference::meta;
	::Uml::AssociationRole NodeReference::meta_srcInstanceMapping;
	::Uml::AssociationRole NodeReference::meta_srcInstanceMapping_rev;
	::Uml::AssociationRole NodeReference::meta_ref;
	::Uml::CompositionParentRole NodeReference::meta_DeploymentPlan_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> NodeReference::_type2ACARole< NodeReference::AR_srcInstanceMapping >() const { return make_pair(&meta_srcInstanceMapping, &meta_srcInstanceMapping_rev); }
	template <> const ::Uml::AssociationRole& NodeReference::_type2ARole< NodeReference::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& NodeReference::_type2CPRole< NodeReference::PR_DeploymentPlan_parent >() const { return meta_DeploymentPlan_parent; }

	::Uml::Class Interconnect::meta;
	::Uml::Attribute Interconnect::meta_label;
	::Uml::AssociationRole Interconnect::meta_srcInterconnectConnection;
	::Uml::AssociationRole Interconnect::meta_srcInterconnectConnection_rev;
	::Uml::AssociationRole Interconnect::meta_dstBridgeConnection;
	::Uml::AssociationRole Interconnect::meta_dstBridgeConnection_rev;
	::Uml::CompositionChildRole Interconnect::meta_Resource_children;
	::Uml::CompositionParentRole Interconnect::meta_Domain_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Interconnect::_type2ACARole< Interconnect::AR_srcInterconnectConnection >() const { return make_pair(&meta_srcInterconnectConnection, &meta_srcInterconnectConnection_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Interconnect::_type2ACARole< Interconnect::AR_dstBridgeConnection >() const { return make_pair(&meta_dstBridgeConnection, &meta_dstBridgeConnection_rev); }
	template <> const ::Uml::CompositionChildRole& Interconnect::_type2CCRole< Interconnect::CR_Resource_children >() const { return meta_Resource_children; }
	template <> const ::Uml::CompositionParentRole& Interconnect::_type2CPRole< Interconnect::PR_Domain_parent >() const { return meta_Domain_parent; }

	::Uml::Class Node::meta;
	::Uml::Attribute Node::meta_operatingSystem;
	::Uml::Attribute Node::meta_label;
	::Uml::Attribute Node::meta_architecture;
	::Uml::AssociationRole Node::meta_referedbyNodeReference;
	::Uml::AssociationRole Node::meta_dstInterconnectConnection;
	::Uml::AssociationRole Node::meta_dstInterconnectConnection_rev;
	::Uml::AssociationRole Node::meta_dstShares;
	::Uml::AssociationRole Node::meta_dstShares_rev;
	::Uml::CompositionChildRole Node::meta_Resource_children;
	::Uml::CompositionParentRole Node::meta_Domain_parent;

	template <> const ::Uml::AssociationRole& Node::_type2ARole< Node::AR_referedbyNodeReference >() const { return meta_referedbyNodeReference; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Node::_type2ACARole< Node::AR_dstInterconnectConnection >() const { return make_pair(&meta_dstInterconnectConnection, &meta_dstInterconnectConnection_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Node::_type2ACARole< Node::AR_dstShares >() const { return make_pair(&meta_dstShares, &meta_dstShares_rev); }
	template <> const ::Uml::CompositionChildRole& Node::_type2CCRole< Node::CR_Resource_children >() const { return meta_Resource_children; }
	template <> const ::Uml::CompositionParentRole& Node::_type2CPRole< Node::PR_Domain_parent >() const { return meta_Domain_parent; }

	::Uml::Class Resource::meta;
	::Uml::CompositionParentRole Resource::meta_Interconnect_parent;
	::Uml::CompositionParentRole Resource::meta_Node_parent;
	::Uml::CompositionParentRole Resource::meta_Bridge_parent;

	template <> const ::Uml::CompositionParentRole& Resource::_type2CPRole< Resource::PR_Interconnect_parent >() const { return meta_Interconnect_parent; }
	template <> const ::Uml::CompositionParentRole& Resource::_type2CPRole< Resource::PR_Node_parent >() const { return meta_Node_parent; }
	template <> const ::Uml::CompositionParentRole& Resource::_type2CPRole< Resource::PR_Bridge_parent >() const { return meta_Bridge_parent; }

	::Uml::Class Bridge::meta;
	::Uml::Attribute Bridge::meta_label;
	::Uml::AssociationRole Bridge::meta_srcBridgeConnection;
	::Uml::AssociationRole Bridge::meta_srcBridgeConnection_rev;
	::Uml::CompositionChildRole Bridge::meta_Resource_children;
	::Uml::CompositionParentRole Bridge::meta_Domain_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Bridge::_type2ACARole< Bridge::AR_srcBridgeConnection >() const { return make_pair(&meta_srcBridgeConnection, &meta_srcBridgeConnection_rev); }
	template <> const ::Uml::CompositionChildRole& Bridge::_type2CCRole< Bridge::CR_Resource_children >() const { return meta_Resource_children; }
	template <> const ::Uml::CompositionParentRole& Bridge::_type2CPRole< Bridge::PR_Domain_parent >() const { return meta_Domain_parent; }

	::Uml::Class SharedResource::meta;
	::Uml::AssociationRole SharedResource::meta_srcShares;
	::Uml::AssociationRole SharedResource::meta_srcShares_rev;
	::Uml::CompositionParentRole SharedResource::meta_Domain_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> SharedResource::_type2ACARole< SharedResource::AR_srcShares >() const { return make_pair(&meta_srcShares, &meta_srcShares_rev); }
	template <> const ::Uml::CompositionParentRole& SharedResource::_type2CPRole< SharedResource::PR_Domain_parent >() const { return meta_Domain_parent; }

	::Uml::Class InstanceMapping::meta;
	::Uml::CompositionParentRole InstanceMapping::meta_DeploymentPlan_parent;
	::Uml::AssociationRole InstanceMapping::meta_dstInstanceMapping_end_;
	::Uml::AssociationRole InstanceMapping::meta_srcInstanceMapping_end_;

	template <> const ::Uml::CompositionParentRole& InstanceMapping::_type2CPRole< InstanceMapping::PR_DeploymentPlan_parent >() const { return meta_DeploymentPlan_parent; }
	template <> const ::Uml::AssociationRole& InstanceMapping::_type2ARole< InstanceMapping::ACE_dstInstanceMapping >() const { return meta_dstInstanceMapping_end_; }
	template <> const ::Uml::AssociationRole& InstanceMapping::_type2ARole< InstanceMapping::ACE_srcInstanceMapping >() const { return meta_srcInstanceMapping_end_; }

	::Uml::Class DeploymentPlans::meta;
	::Uml::Attribute DeploymentPlans::meta_name;
	::Uml::CompositionChildRole DeploymentPlans::meta_DeploymentPlan_children;
	::Uml::CompositionParentRole DeploymentPlans::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& DeploymentPlans::_type2CCRole< DeploymentPlans::CR_DeploymentPlan_children >() const { return meta_DeploymentPlan_children; }
	template <> const ::Uml::CompositionParentRole& DeploymentPlans::_type2CPRole< DeploymentPlans::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class CollocationGroup::meta;
	::Uml::AssociationRole CollocationGroup::meta_dstInstanceMapping;
	::Uml::AssociationRole CollocationGroup::meta_dstInstanceMapping_rev;
	::Uml::AssociationRole CollocationGroup::meta_members;
	::Uml::CompositionParentRole CollocationGroup::meta_DeploymentPlan_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> CollocationGroup::_type2ACARole< CollocationGroup::AR_dstInstanceMapping >() const { return make_pair(&meta_dstInstanceMapping, &meta_dstInstanceMapping_rev); }
	template <> const ::Uml::AssociationRole& CollocationGroup::_type2ARole< CollocationGroup::AR_members >() const { return meta_members; }
	template <> const ::Uml::CompositionParentRole& CollocationGroup::_type2CPRole< CollocationGroup::PR_DeploymentPlan_parent >() const { return meta_DeploymentPlan_parent; }

	::Uml::Class SharedComponentReference::meta;
	::Uml::AssociationRole SharedComponentReference::meta_ref;

	template <> const ::Uml::AssociationRole& SharedComponentReference::_type2ARole< SharedComponentReference::AR_ref >() const { return meta_ref; }

	::Uml::Class ComponentFactoryRef::meta;
	::Uml::AssociationRole ComponentFactoryRef::meta_ref;
	::Uml::AssociationRole ComponentFactoryRef::meta_dstDeploys;
	::Uml::AssociationRole ComponentFactoryRef::meta_dstDeploys_rev;

	template <> const ::Uml::AssociationRole& ComponentFactoryRef::_type2ARole< ComponentFactoryRef::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentFactoryRef::_type2ACARole< ComponentFactoryRef::AR_dstDeploys >() const { return make_pair(&meta_dstDeploys, &meta_dstDeploys_rev); }

	::Uml::Class Deploys::meta;
	::Uml::CompositionParentRole Deploys::meta_DeploymentPlan_parent;
	::Uml::AssociationRole Deploys::meta_srcDeploys_end_;
	::Uml::AssociationRole Deploys::meta_dstDeploys_end_;

	template <> const ::Uml::CompositionParentRole& Deploys::_type2CPRole< Deploys::PR_DeploymentPlan_parent >() const { return meta_DeploymentPlan_parent; }
	template <> const ::Uml::AssociationRole& Deploys::_type2ARole< Deploys::ACE_srcDeploys >() const { return meta_srcDeploys_end_; }
	template <> const ::Uml::AssociationRole& Deploys::_type2ARole< Deploys::ACE_dstDeploys >() const { return meta_dstDeploys_end_; }

	::Uml::Class CollocationGroupMember::meta;
	::Uml::AssociationRole CollocationGroupMember::meta_setCollocationGroup;
	::Uml::CompositionParentRole CollocationGroupMember::meta_DeploymentPlan_parent;

	template <> const ::Uml::AssociationRole& CollocationGroupMember::_type2ARole< CollocationGroupMember::AR_setCollocationGroup >() const { return meta_setCollocationGroup; }
	template <> const ::Uml::CompositionParentRole& CollocationGroupMember::_type2CPRole< CollocationGroupMember::PR_DeploymentPlan_parent >() const { return meta_DeploymentPlan_parent; }

	::Uml::Class DeploymentPlan::meta;
	::Uml::Attribute DeploymentPlan::meta_UUID;
	::Uml::Attribute DeploymentPlan::meta_label;
	::Uml::CompositionChildRole DeploymentPlan::meta_InstanceMapping_children;
	::Uml::CompositionChildRole DeploymentPlan::meta_NodeReference_children;
	::Uml::CompositionChildRole DeploymentPlan::meta_CollocationGroup_children;
	::Uml::CompositionChildRole DeploymentPlan::meta_Property_children;
	::Uml::CompositionChildRole DeploymentPlan::meta_Deploys_children;
	::Uml::CompositionChildRole DeploymentPlan::meta_CollocationGroupMember_children;
	::Uml::CompositionParentRole DeploymentPlan::meta_DeploymentPlans_parent;

	template <> const ::Uml::CompositionChildRole& DeploymentPlan::_type2CCRole< DeploymentPlan::CR_InstanceMapping_children >() const { return meta_InstanceMapping_children; }
	template <> const ::Uml::CompositionChildRole& DeploymentPlan::_type2CCRole< DeploymentPlan::CR_NodeReference_children >() const { return meta_NodeReference_children; }
	template <> const ::Uml::CompositionChildRole& DeploymentPlan::_type2CCRole< DeploymentPlan::CR_CollocationGroup_children >() const { return meta_CollocationGroup_children; }
	template <> const ::Uml::CompositionChildRole& DeploymentPlan::_type2CCRole< DeploymentPlan::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& DeploymentPlan::_type2CCRole< DeploymentPlan::CR_Deploys_children >() const { return meta_Deploys_children; }
	template <> const ::Uml::CompositionChildRole& DeploymentPlan::_type2CCRole< DeploymentPlan::CR_CollocationGroupMember_children >() const { return meta_CollocationGroupMember_children; }
	template <> const ::Uml::CompositionParentRole& DeploymentPlan::_type2CPRole< DeploymentPlan::PR_DeploymentPlans_parent >() const { return meta_DeploymentPlans_parent; }

	::Uml::Class invoke::meta;
	::Uml::CompositionParentRole invoke::meta_ComponentAssembly_parent;
	::Uml::AssociationRole invoke::meta_dstinvoke_end_;
	::Uml::AssociationRole invoke::meta_srcinvoke_end_;

	template <> const ::Uml::CompositionParentRole& invoke::_type2CPRole< invoke::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& invoke::_type2ARole< invoke::ACE_dstinvoke >() const { return meta_dstinvoke_end_; }
	template <> const ::Uml::AssociationRole& invoke::_type2ARole< invoke::ACE_srcinvoke >() const { return meta_srcinvoke_end_; }

	::Uml::Class AssemblyselectRequirement::meta;
	::Uml::CompositionParentRole AssemblyselectRequirement::meta_ComponentAssembly_parent;
	::Uml::AssociationRole AssemblyselectRequirement::meta_dstAssemblyselectRequirement_end_;
	::Uml::AssociationRole AssemblyselectRequirement::meta_srcAssemblyselectRequirement_end_;

	template <> const ::Uml::CompositionParentRole& AssemblyselectRequirement::_type2CPRole< AssemblyselectRequirement::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& AssemblyselectRequirement::_type2ARole< AssemblyselectRequirement::ACE_dstAssemblyselectRequirement >() const { return meta_dstAssemblyselectRequirement_end_; }
	template <> const ::Uml::AssociationRole& AssemblyselectRequirement::_type2ARole< AssemblyselectRequirement::ACE_srcAssemblyselectRequirement >() const { return meta_srcAssemblyselectRequirement_end_; }

	::Uml::Class AssemblyConfigProperty::meta;
	::Uml::CompositionParentRole AssemblyConfigProperty::meta_ComponentAssembly_parent;
	::Uml::AssociationRole AssemblyConfigProperty::meta_dstAssemblyConfigProperty_end_;
	::Uml::AssociationRole AssemblyConfigProperty::meta_srcAssemblyConfigProperty_end_;

	template <> const ::Uml::CompositionParentRole& AssemblyConfigProperty::_type2CPRole< AssemblyConfigProperty::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& AssemblyConfigProperty::_type2ARole< AssemblyConfigProperty::ACE_dstAssemblyConfigProperty >() const { return meta_dstAssemblyConfigProperty_end_; }
	template <> const ::Uml::AssociationRole& AssemblyConfigProperty::_type2ARole< AssemblyConfigProperty::ACE_srcAssemblyConfigProperty >() const { return meta_srcAssemblyConfigProperty_end_; }

	::Uml::Class PublishConnector::meta;
	::Uml::AssociationRole PublishConnector::meta_dstAssemblyDeployRequirement;
	::Uml::AssociationRole PublishConnector::meta_dstAssemblyDeployRequirement_rev;
	::Uml::AssociationRole PublishConnector::meta_dstdeliverTo;
	::Uml::AssociationRole PublishConnector::meta_dstdeliverTo_rev;
	::Uml::AssociationRole PublishConnector::meta_srcpublish;
	::Uml::AssociationRole PublishConnector::meta_srcpublish_rev;
	::Uml::CompositionParentRole PublishConnector::meta_ComponentAssembly_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PublishConnector::_type2ACARole< PublishConnector::AR_dstAssemblyDeployRequirement >() const { return make_pair(&meta_dstAssemblyDeployRequirement, &meta_dstAssemblyDeployRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PublishConnector::_type2ACARole< PublishConnector::AR_dstdeliverTo >() const { return make_pair(&meta_dstdeliverTo, &meta_dstdeliverTo_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PublishConnector::_type2ACARole< PublishConnector::AR_srcpublish >() const { return make_pair(&meta_srcpublish, &meta_srcpublish_rev); }
	template <> const ::Uml::CompositionParentRole& PublishConnector::_type2CPRole< PublishConnector::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class publish::meta;
	::Uml::CompositionParentRole publish::meta_ComponentAssembly_parent;
	::Uml::AssociationRole publish::meta_dstpublish_end_;
	::Uml::AssociationRole publish::meta_srcpublish_end_;

	template <> const ::Uml::CompositionParentRole& publish::_type2CPRole< publish::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& publish::_type2ARole< publish::ACE_dstpublish >() const { return meta_dstpublish_end_; }
	template <> const ::Uml::AssociationRole& publish::_type2ARole< publish::ACE_srcpublish >() const { return meta_srcpublish_end_; }

	::Uml::Class deliverTo::meta;
	::Uml::CompositionParentRole deliverTo::meta_ComponentAssembly_parent;
	::Uml::AssociationRole deliverTo::meta_srcdeliverTo_end_;
	::Uml::AssociationRole deliverTo::meta_dstdeliverTo_end_;

	template <> const ::Uml::CompositionParentRole& deliverTo::_type2CPRole< deliverTo::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& deliverTo::_type2ARole< deliverTo::ACE_srcdeliverTo >() const { return meta_srcdeliverTo_end_; }
	template <> const ::Uml::AssociationRole& deliverTo::_type2ARole< deliverTo::ACE_dstdeliverTo >() const { return meta_dstdeliverTo_end_; }

	::Uml::Class AssemblyDeployRequirement::meta;
	::Uml::CompositionParentRole AssemblyDeployRequirement::meta_ComponentAssembly_parent;
	::Uml::AssociationRole AssemblyDeployRequirement::meta_srcAssemblyDeployRequirement_end_;
	::Uml::AssociationRole AssemblyDeployRequirement::meta_dstAssemblyDeployRequirement_end_;

	template <> const ::Uml::CompositionParentRole& AssemblyDeployRequirement::_type2CPRole< AssemblyDeployRequirement::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& AssemblyDeployRequirement::_type2ARole< AssemblyDeployRequirement::ACE_srcAssemblyDeployRequirement >() const { return meta_srcAssemblyDeployRequirement_end_; }
	template <> const ::Uml::AssociationRole& AssemblyDeployRequirement::_type2ARole< AssemblyDeployRequirement::ACE_dstAssemblyDeployRequirement >() const { return meta_dstAssemblyDeployRequirement_end_; }

	::Uml::Class emit::meta;
	::Uml::CompositionParentRole emit::meta_ComponentAssembly_parent;
	::Uml::AssociationRole emit::meta_dstemit_end_;
	::Uml::AssociationRole emit::meta_srcemit_end_;

	template <> const ::Uml::CompositionParentRole& emit::_type2CPRole< emit::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& emit::_type2ARole< emit::ACE_dstemit >() const { return meta_dstemit_end_; }
	template <> const ::Uml::AssociationRole& emit::_type2ARole< emit::ACE_srcemit >() const { return meta_srcemit_end_; }

	::Uml::Class ReceptacleDelegate::meta;
	::Uml::CompositionParentRole ReceptacleDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole ReceptacleDelegate::meta_srcReceptacleDelegate_end_;
	::Uml::AssociationRole ReceptacleDelegate::meta_dstReceptacleDelegate_end_;

	template <> const ::Uml::CompositionParentRole& ReceptacleDelegate::_type2CPRole< ReceptacleDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& ReceptacleDelegate::_type2ARole< ReceptacleDelegate::ACE_srcReceptacleDelegate >() const { return meta_srcReceptacleDelegate_end_; }
	template <> const ::Uml::AssociationRole& ReceptacleDelegate::_type2ARole< ReceptacleDelegate::ACE_dstReceptacleDelegate >() const { return meta_dstReceptacleDelegate_end_; }

	::Uml::Class FacetDelegate::meta;
	::Uml::CompositionParentRole FacetDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole FacetDelegate::meta_srcFacetDelegate_end_;
	::Uml::AssociationRole FacetDelegate::meta_dstFacetDelegate_end_;

	template <> const ::Uml::CompositionParentRole& FacetDelegate::_type2CPRole< FacetDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& FacetDelegate::_type2ARole< FacetDelegate::ACE_srcFacetDelegate >() const { return meta_srcFacetDelegate_end_; }
	template <> const ::Uml::AssociationRole& FacetDelegate::_type2ARole< FacetDelegate::ACE_dstFacetDelegate >() const { return meta_dstFacetDelegate_end_; }

	::Uml::Class EventSourceDelegate::meta;
	::Uml::CompositionParentRole EventSourceDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole EventSourceDelegate::meta_srcEventSourceDelegate_end_;
	::Uml::AssociationRole EventSourceDelegate::meta_dstEventSourceDelegate_end_;

	template <> const ::Uml::CompositionParentRole& EventSourceDelegate::_type2CPRole< EventSourceDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& EventSourceDelegate::_type2ARole< EventSourceDelegate::ACE_srcEventSourceDelegate >() const { return meta_srcEventSourceDelegate_end_; }
	template <> const ::Uml::AssociationRole& EventSourceDelegate::_type2ARole< EventSourceDelegate::ACE_dstEventSourceDelegate >() const { return meta_dstEventSourceDelegate_end_; }

	::Uml::Class EventSinkDelegate::meta;
	::Uml::CompositionParentRole EventSinkDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole EventSinkDelegate::meta_srcEventSinkDelegate_end_;
	::Uml::AssociationRole EventSinkDelegate::meta_dstEventSinkDelegate_end_;

	template <> const ::Uml::CompositionParentRole& EventSinkDelegate::_type2CPRole< EventSinkDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& EventSinkDelegate::_type2ARole< EventSinkDelegate::ACE_srcEventSinkDelegate >() const { return meta_srcEventSinkDelegate_end_; }
	template <> const ::Uml::AssociationRole& EventSinkDelegate::_type2ARole< EventSinkDelegate::ACE_dstEventSinkDelegate >() const { return meta_dstEventSinkDelegate_end_; }

	::Uml::Class ExternalDelegate::meta;
	::Uml::CompositionParentRole ExternalDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole ExternalDelegate::meta_srcExternalDelegate_end_;
	::Uml::AssociationRole ExternalDelegate::meta_dstExternalDelegate_end_;

	template <> const ::Uml::CompositionParentRole& ExternalDelegate::_type2CPRole< ExternalDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& ExternalDelegate::_type2ARole< ExternalDelegate::ACE_srcExternalDelegate >() const { return meta_srcExternalDelegate_end_; }
	template <> const ::Uml::AssociationRole& ExternalDelegate::_type2ARole< ExternalDelegate::ACE_dstExternalDelegate >() const { return meta_dstExternalDelegate_end_; }

	::Uml::Class AttributeValue::meta;
	::Uml::CompositionParentRole AttributeValue::meta_ComponentAssembly_parent;
	::Uml::AssociationRole AttributeValue::meta_dstAttributeValue_end_;
	::Uml::AssociationRole AttributeValue::meta_srcAttributeValue_end_;

	template <> const ::Uml::CompositionParentRole& AttributeValue::_type2CPRole< AttributeValue::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& AttributeValue::_type2ARole< AttributeValue::ACE_dstAttributeValue >() const { return meta_dstAttributeValue_end_; }
	template <> const ::Uml::AssociationRole& AttributeValue::_type2ARole< AttributeValue::ACE_srcAttributeValue >() const { return meta_srcAttributeValue_end_; }

	::Uml::Class AttributeDelegate::meta;
	::Uml::CompositionParentRole AttributeDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole AttributeDelegate::meta_srcAttributeDelegate_end_;
	::Uml::AssociationRole AttributeDelegate::meta_dstAttributeDelegate_end_;

	template <> const ::Uml::CompositionParentRole& AttributeDelegate::_type2CPRole< AttributeDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& AttributeDelegate::_type2ARole< AttributeDelegate::ACE_srcAttributeDelegate >() const { return meta_srcAttributeDelegate_end_; }
	template <> const ::Uml::AssociationRole& AttributeDelegate::_type2ARole< AttributeDelegate::ACE_dstAttributeDelegate >() const { return meta_dstAttributeDelegate_end_; }

	::Uml::Class AttributeMapping::meta;
	::Uml::AssociationRole AttributeMapping::meta_dstAttributeMappingValue;
	::Uml::AssociationRole AttributeMapping::meta_dstAttributeMappingValue_rev;
	::Uml::AssociationRole AttributeMapping::meta_dstAttributeDelegate;
	::Uml::AssociationRole AttributeMapping::meta_dstAttributeDelegate_rev;
	::Uml::AssociationRole AttributeMapping::meta_dstAttributeMappingDelegate;
	::Uml::AssociationRole AttributeMapping::meta_dstAttributeMappingDelegate_rev;
	::Uml::AssociationRole AttributeMapping::meta_srcAttributeMappingDelegate;
	::Uml::AssociationRole AttributeMapping::meta_srcAttributeMappingDelegate_rev;
	::Uml::AssociationRole AttributeMapping::meta_ref;
	::Uml::CompositionParentRole AttributeMapping::meta_ComponentAssembly_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> AttributeMapping::_type2ACARole< AttributeMapping::AR_dstAttributeMappingValue >() const { return make_pair(&meta_dstAttributeMappingValue, &meta_dstAttributeMappingValue_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> AttributeMapping::_type2ACARole< AttributeMapping::AR_dstAttributeDelegate >() const { return make_pair(&meta_dstAttributeDelegate, &meta_dstAttributeDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> AttributeMapping::_type2ACARole< AttributeMapping::AR_dstAttributeMappingDelegate >() const { return make_pair(&meta_dstAttributeMappingDelegate, &meta_dstAttributeMappingDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> AttributeMapping::_type2ACARole< AttributeMapping::AR_srcAttributeMappingDelegate >() const { return make_pair(&meta_srcAttributeMappingDelegate, &meta_srcAttributeMappingDelegate_rev); }
	template <> const ::Uml::AssociationRole& AttributeMapping::_type2ARole< AttributeMapping::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& AttributeMapping::_type2CPRole< AttributeMapping::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class AttributeMappingValue::meta;
	::Uml::CompositionParentRole AttributeMappingValue::meta_ComponentAssembly_parent;
	::Uml::AssociationRole AttributeMappingValue::meta_srcAttributeMappingValue_end_;
	::Uml::AssociationRole AttributeMappingValue::meta_dstAttributeMappingValue_end_;

	template <> const ::Uml::CompositionParentRole& AttributeMappingValue::_type2CPRole< AttributeMappingValue::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& AttributeMappingValue::_type2ARole< AttributeMappingValue::ACE_srcAttributeMappingValue >() const { return meta_srcAttributeMappingValue_end_; }
	template <> const ::Uml::AssociationRole& AttributeMappingValue::_type2ARole< AttributeMappingValue::ACE_dstAttributeMappingValue >() const { return meta_dstAttributeMappingValue_end_; }

	::Uml::Class AttributeMappingDelegate::meta;
	::Uml::CompositionParentRole AttributeMappingDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole AttributeMappingDelegate::meta_srcAttributeMappingDelegate_end_;
	::Uml::AssociationRole AttributeMappingDelegate::meta_dstAttributeMappingDelegate_end_;

	template <> const ::Uml::CompositionParentRole& AttributeMappingDelegate::_type2CPRole< AttributeMappingDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& AttributeMappingDelegate::_type2ARole< AttributeMappingDelegate::ACE_srcAttributeMappingDelegate >() const { return meta_srcAttributeMappingDelegate_end_; }
	template <> const ::Uml::AssociationRole& AttributeMappingDelegate::_type2ARole< AttributeMappingDelegate::ACE_dstAttributeMappingDelegate >() const { return meta_dstAttributeMappingDelegate_end_; }

	::Uml::Class SupportsDelegate::meta;
	::Uml::CompositionParentRole SupportsDelegate::meta_ComponentAssembly_parent;
	::Uml::AssociationRole SupportsDelegate::meta_dstSupportsDelegate_end_;
	::Uml::AssociationRole SupportsDelegate::meta_srcSupportsDelegate_end_;

	template <> const ::Uml::CompositionParentRole& SupportsDelegate::_type2CPRole< SupportsDelegate::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::AssociationRole& SupportsDelegate::_type2ARole< SupportsDelegate::ACE_dstSupportsDelegate >() const { return meta_dstSupportsDelegate_end_; }
	template <> const ::Uml::AssociationRole& SupportsDelegate::_type2ARole< SupportsDelegate::ACE_srcSupportsDelegate >() const { return meta_srcSupportsDelegate_end_; }

	::Uml::Class InvokePortBase::meta;
	::Uml::AssociationRole InvokePortBase::meta_srcinvoke;
	::Uml::AssociationRole InvokePortBase::meta_srcinvoke_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> InvokePortBase::_type2ACARole< InvokePortBase::AR_srcinvoke >() const { return make_pair(&meta_srcinvoke, &meta_srcinvoke_rev); }

	::Uml::Class ImplementationCapability::meta;
	::Uml::CompositionParentRole ImplementationCapability::meta_ComponentImplementationContainer_parent;
	::Uml::AssociationRole ImplementationCapability::meta_srcImplementationCapability_end_;
	::Uml::AssociationRole ImplementationCapability::meta_dstImplementationCapability_end_;

	template <> const ::Uml::CompositionParentRole& ImplementationCapability::_type2CPRole< ImplementationCapability::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& ImplementationCapability::_type2ARole< ImplementationCapability::ACE_srcImplementationCapability >() const { return meta_srcImplementationCapability_end_; }
	template <> const ::Uml::AssociationRole& ImplementationCapability::_type2ARole< ImplementationCapability::ACE_dstImplementationCapability >() const { return meta_dstImplementationCapability_end_; }

	::Uml::Class ImplementationDependsOn::meta;
	::Uml::CompositionParentRole ImplementationDependsOn::meta_ComponentImplementationContainer_parent;
	::Uml::AssociationRole ImplementationDependsOn::meta_srcImplementationDependsOn_end_;
	::Uml::AssociationRole ImplementationDependsOn::meta_dstImplementationDependsOn_end_;

	template <> const ::Uml::CompositionParentRole& ImplementationDependsOn::_type2CPRole< ImplementationDependsOn::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& ImplementationDependsOn::_type2ARole< ImplementationDependsOn::ACE_srcImplementationDependsOn >() const { return meta_srcImplementationDependsOn_end_; }
	template <> const ::Uml::AssociationRole& ImplementationDependsOn::_type2ARole< ImplementationDependsOn::ACE_dstImplementationDependsOn >() const { return meta_dstImplementationDependsOn_end_; }

	::Uml::Class Implements::meta;
	::Uml::CompositionParentRole Implements::meta_ComponentImplementationContainer_parent;
	::Uml::AssociationRole Implements::meta_srcImplements_end_;
	::Uml::AssociationRole Implements::meta_dstImplements_end_;

	template <> const ::Uml::CompositionParentRole& Implements::_type2CPRole< Implements::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& Implements::_type2ARole< Implements::ACE_srcImplements >() const { return meta_srcImplements_end_; }
	template <> const ::Uml::AssociationRole& Implements::_type2ARole< Implements::ACE_dstImplements >() const { return meta_dstImplements_end_; }

	::Uml::Class ComponentImplementations::meta;
	::Uml::Attribute ComponentImplementations::meta_name;
	::Uml::CompositionChildRole ComponentImplementations::meta_ComponentImplementationContainer_children;
	::Uml::CompositionParentRole ComponentImplementations::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ComponentImplementations::_type2CCRole< ComponentImplementations::CR_ComponentImplementationContainer_children >() const { return meta_ComponentImplementationContainer_children; }
	template <> const ::Uml::CompositionParentRole& ComponentImplementations::_type2CPRole< ComponentImplementations::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class ComponentImplementation::meta;
	::Uml::AssociationRole ComponentImplementation::meta_dstImplementationDependsOn;
	::Uml::AssociationRole ComponentImplementation::meta_dstImplementationDependsOn_rev;
	::Uml::AssociationRole ComponentImplementation::meta_dstImplementationCapability;
	::Uml::AssociationRole ComponentImplementation::meta_dstImplementationCapability_rev;
	::Uml::AssociationRole ComponentImplementation::meta_dstImplements;
	::Uml::AssociationRole ComponentImplementation::meta_dstImplements_rev;
	::Uml::AssociationRole ComponentImplementation::meta_referedbyComponentImplementationReference;
	::Uml::CompositionParentRole ComponentImplementation::meta_ComponentImplementationContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentImplementation::_type2ACARole< ComponentImplementation::AR_dstImplementationDependsOn >() const { return make_pair(&meta_dstImplementationDependsOn, &meta_dstImplementationDependsOn_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentImplementation::_type2ACARole< ComponentImplementation::AR_dstImplementationCapability >() const { return make_pair(&meta_dstImplementationCapability, &meta_dstImplementationCapability_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentImplementation::_type2ACARole< ComponentImplementation::AR_dstImplements >() const { return make_pair(&meta_dstImplements, &meta_dstImplements_rev); }
	template <> const ::Uml::AssociationRole& ComponentImplementation::_type2ARole< ComponentImplementation::AR_referedbyComponentImplementationReference >() const { return meta_referedbyComponentImplementationReference; }
	template <> const ::Uml::CompositionParentRole& ComponentImplementation::_type2CPRole< ComponentImplementation::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }

	::Uml::Class ComponentImplementationContainer::meta;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_Implements_child;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationDependsOn_children;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_ComponentRef_child;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationDependency_children;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_ImplementationCapability_children;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_Capability_children;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_CriticalPath_children;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_PathReference_child;
	::Uml::CompositionChildRole ComponentImplementationContainer::meta_ComponentImplementation_children;
	::Uml::CompositionParentRole ComponentImplementationContainer::meta_ComponentImplementations_parent;

	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_Implements_child >() const { return meta_Implements_child; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_ImplementationDependsOn_children >() const { return meta_ImplementationDependsOn_children; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_ComponentRef_child >() const { return meta_ComponentRef_child; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_ImplementationDependency_children >() const { return meta_ImplementationDependency_children; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_ImplementationCapability_children >() const { return meta_ImplementationCapability_children; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_Capability_children >() const { return meta_Capability_children; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_CriticalPath_children >() const { return meta_CriticalPath_children; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_PathReference_child >() const { return meta_PathReference_child; }
	template <> const ::Uml::CompositionChildRole& ComponentImplementationContainer::_type2CCRole< ComponentImplementationContainer::CR_ComponentImplementation_children >() const { return meta_ComponentImplementation_children; }
	template <> const ::Uml::CompositionParentRole& ComponentImplementationContainer::_type2CPRole< ComponentImplementationContainer::PR_ComponentImplementations_parent >() const { return meta_ComponentImplementations_parent; }

	::Uml::Class CriticalPath::meta;
	::Uml::CompositionParentRole CriticalPath::meta_ComponentImplementationContainer_parent;
	::Uml::AssociationRole CriticalPath::meta_srcCriticalPath_end_;
	::Uml::AssociationRole CriticalPath::meta_dstCriticalPath_end_;

	template <> const ::Uml::CompositionParentRole& CriticalPath::_type2CPRole< CriticalPath::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }
	template <> const ::Uml::AssociationRole& CriticalPath::_type2ARole< CriticalPath::ACE_srcCriticalPath >() const { return meta_srcCriticalPath_end_; }
	template <> const ::Uml::AssociationRole& CriticalPath::_type2ARole< CriticalPath::ACE_dstCriticalPath >() const { return meta_dstCriticalPath_end_; }

	::Uml::Class ComponentImplementationReference::meta;
	::Uml::AssociationRole ComponentImplementationReference::meta_ref;
	::Uml::AssociationRole ComponentImplementationReference::meta_srcImplementation;
	::Uml::AssociationRole ComponentImplementationReference::meta_srcImplementation_rev;
	::Uml::CompositionParentRole ComponentImplementationReference::meta_PackageContainer_parent;

	template <> const ::Uml::AssociationRole& ComponentImplementationReference::_type2ARole< ComponentImplementationReference::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentImplementationReference::_type2ACARole< ComponentImplementationReference::AR_srcImplementation >() const { return make_pair(&meta_srcImplementation, &meta_srcImplementation_rev); }
	template <> const ::Uml::CompositionParentRole& ComponentImplementationReference::_type2CPRole< ComponentImplementationReference::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }

	::Uml::Class MonolithicImplementation::meta;
	::Uml::Attribute MonolithicImplementation::meta_defaultVersion;

	::Uml::Class PackageConfBasePackage::meta;
	::Uml::CompositionParentRole PackageConfBasePackage::meta_PackageConfigurationContainer_parent;
	::Uml::AssociationRole PackageConfBasePackage::meta_srcPackageConfBasePackage_end_;
	::Uml::AssociationRole PackageConfBasePackage::meta_dstPackageConfBasePackage_end_;

	template <> const ::Uml::CompositionParentRole& PackageConfBasePackage::_type2CPRole< PackageConfBasePackage::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageConfBasePackage::_type2ARole< PackageConfBasePackage::ACE_srcPackageConfBasePackage >() const { return meta_srcPackageConfBasePackage_end_; }
	template <> const ::Uml::AssociationRole& PackageConfBasePackage::_type2ARole< PackageConfBasePackage::ACE_dstPackageConfBasePackage >() const { return meta_dstPackageConfBasePackage_end_; }

	::Uml::Class PackageConfReference::meta;
	::Uml::CompositionParentRole PackageConfReference::meta_PackageConfigurationContainer_parent;
	::Uml::AssociationRole PackageConfReference::meta_srcPackageConfReference_end_;
	::Uml::AssociationRole PackageConfReference::meta_dstPackageConfReference_end_;

	template <> const ::Uml::CompositionParentRole& PackageConfReference::_type2CPRole< PackageConfReference::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageConfReference::_type2ARole< PackageConfReference::ACE_srcPackageConfReference >() const { return meta_srcPackageConfReference_end_; }
	template <> const ::Uml::AssociationRole& PackageConfReference::_type2ARole< PackageConfReference::ACE_dstPackageConfReference >() const { return meta_dstPackageConfReference_end_; }

	::Uml::Class PackageConfigurations::meta;
	::Uml::Attribute PackageConfigurations::meta_name;
	::Uml::CompositionChildRole PackageConfigurations::meta_PackageConfigurationContainer_children;
	::Uml::CompositionParentRole PackageConfigurations::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& PackageConfigurations::_type2CCRole< PackageConfigurations::CR_PackageConfigurationContainer_children >() const { return meta_PackageConfigurationContainer_children; }
	template <> const ::Uml::CompositionParentRole& PackageConfigurations::_type2CPRole< PackageConfigurations::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class PackageConfigurationContainer::meta;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfReference_child;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfBasePackage_child;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_ComponentPackage_child;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_ComponentPackageReference_child;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfConfigProperty_children;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfSelectRequirement_children;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_Requirement_children;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_Property_children;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child;
	::Uml::CompositionChildRole PackageConfigurationContainer::meta_PackageConfiguration_children;
	::Uml::CompositionParentRole PackageConfigurationContainer::meta_PackageConfigurations_parent;

	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_PackageConfReference_child >() const { return meta_PackageConfReference_child; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_PackageConfBasePackage_child >() const { return meta_PackageConfBasePackage_child; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_ComponentPackage_child >() const { return meta_ComponentPackage_child; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_ComponentPackageReference_child >() const { return meta_ComponentPackageReference_child; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_PackageConfConfigProperty_children >() const { return meta_PackageConfConfigProperty_children; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_PackageConfSelectRequirement_children >() const { return meta_PackageConfSelectRequirement_children; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_Requirement_children >() const { return meta_Requirement_children; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_PackageConfSpecializedConfig_child >() const { return meta_PackageConfSpecializedConfig_child; }
	template <> const ::Uml::CompositionChildRole& PackageConfigurationContainer::_type2CCRole< PackageConfigurationContainer::CR_PackageConfiguration_children >() const { return meta_PackageConfiguration_children; }
	template <> const ::Uml::CompositionParentRole& PackageConfigurationContainer::_type2CPRole< PackageConfigurationContainer::PR_PackageConfigurations_parent >() const { return meta_PackageConfigurations_parent; }

	::Uml::Class PackageConfConfigProperty::meta;
	::Uml::CompositionParentRole PackageConfConfigProperty::meta_PackageConfigurationContainer_parent;
	::Uml::AssociationRole PackageConfConfigProperty::meta_srcPackageConfConfigProperty_end_;
	::Uml::AssociationRole PackageConfConfigProperty::meta_dstPackageConfConfigProperty_end_;

	template <> const ::Uml::CompositionParentRole& PackageConfConfigProperty::_type2CPRole< PackageConfConfigProperty::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageConfConfigProperty::_type2ARole< PackageConfConfigProperty::ACE_srcPackageConfConfigProperty >() const { return meta_srcPackageConfConfigProperty_end_; }
	template <> const ::Uml::AssociationRole& PackageConfConfigProperty::_type2ARole< PackageConfConfigProperty::ACE_dstPackageConfConfigProperty >() const { return meta_dstPackageConfConfigProperty_end_; }

	::Uml::Class PackageConfSelectRequirement::meta;
	::Uml::CompositionParentRole PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent;
	::Uml::AssociationRole PackageConfSelectRequirement::meta_srcPackageConfSelectRequirement_end_;
	::Uml::AssociationRole PackageConfSelectRequirement::meta_dstPackageConfSelectRequirement_end_;

	template <> const ::Uml::CompositionParentRole& PackageConfSelectRequirement::_type2CPRole< PackageConfSelectRequirement::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageConfSelectRequirement::_type2ARole< PackageConfSelectRequirement::ACE_srcPackageConfSelectRequirement >() const { return meta_srcPackageConfSelectRequirement_end_; }
	template <> const ::Uml::AssociationRole& PackageConfSelectRequirement::_type2ARole< PackageConfSelectRequirement::ACE_dstPackageConfSelectRequirement >() const { return meta_dstPackageConfSelectRequirement_end_; }

	::Uml::Class PackageConfSpecializedConfig::meta;
	::Uml::CompositionParentRole PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent;
	::Uml::AssociationRole PackageConfSpecializedConfig::meta_dstPackageConfSpecializedConfig_end_;
	::Uml::AssociationRole PackageConfSpecializedConfig::meta_srcPackageConfSpecializedConfig_end_;

	template <> const ::Uml::CompositionParentRole& PackageConfSpecializedConfig::_type2CPRole< PackageConfSpecializedConfig::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageConfSpecializedConfig::_type2ARole< PackageConfSpecializedConfig::ACE_dstPackageConfSpecializedConfig >() const { return meta_dstPackageConfSpecializedConfig_end_; }
	template <> const ::Uml::AssociationRole& PackageConfSpecializedConfig::_type2ARole< PackageConfSpecializedConfig::ACE_srcPackageConfSpecializedConfig >() const { return meta_srcPackageConfSpecializedConfig_end_; }

	::Uml::Class PackageConfigurationReference::meta;
	::Uml::AssociationRole PackageConfigurationReference::meta_srcPackageConfSpecializedConfig;
	::Uml::AssociationRole PackageConfigurationReference::meta_srcPackageConfSpecializedConfig_rev;
	::Uml::AssociationRole PackageConfigurationReference::meta_ref;
	::Uml::AssociationRole PackageConfigurationReference::meta_srcpackage;
	::Uml::AssociationRole PackageConfigurationReference::meta_srcpackage_rev;
	::Uml::CompositionParentRole PackageConfigurationReference::meta_TopLevelPackageContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PackageConfigurationReference::_type2ACARole< PackageConfigurationReference::AR_srcPackageConfSpecializedConfig >() const { return make_pair(&meta_srcPackageConfSpecializedConfig, &meta_srcPackageConfSpecializedConfig_rev); }
	template <> const ::Uml::AssociationRole& PackageConfigurationReference::_type2ARole< PackageConfigurationReference::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PackageConfigurationReference::_type2ACARole< PackageConfigurationReference::AR_srcpackage >() const { return make_pair(&meta_srcpackage, &meta_srcpackage_rev); }
	template <> const ::Uml::CompositionParentRole& PackageConfigurationReference::_type2CPRole< PackageConfigurationReference::PR_TopLevelPackageContainer_parent >() const { return meta_TopLevelPackageContainer_parent; }

	::Uml::Class PackageConfiguration::meta;
	::Uml::Attribute PackageConfiguration::meta_UUID;
	::Uml::Attribute PackageConfiguration::meta_label;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfSpecializedConfig;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfSpecializedConfig_rev;
	::Uml::AssociationRole PackageConfiguration::meta_referedbyPackageConfigurationReference;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfBasePackage;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfBasePackage_rev;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfReference;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfReference_rev;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfSelectRequirement;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfSelectRequirement_rev;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfConfigProperty;
	::Uml::AssociationRole PackageConfiguration::meta_dstPackageConfConfigProperty_rev;
	::Uml::CompositionParentRole PackageConfiguration::meta_PackageConfigurationContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PackageConfiguration::_type2ACARole< PackageConfiguration::AR_dstPackageConfSpecializedConfig >() const { return make_pair(&meta_dstPackageConfSpecializedConfig, &meta_dstPackageConfSpecializedConfig_rev); }
	template <> const ::Uml::AssociationRole& PackageConfiguration::_type2ARole< PackageConfiguration::AR_referedbyPackageConfigurationReference >() const { return meta_referedbyPackageConfigurationReference; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PackageConfiguration::_type2ACARole< PackageConfiguration::AR_dstPackageConfBasePackage >() const { return make_pair(&meta_dstPackageConfBasePackage, &meta_dstPackageConfBasePackage_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PackageConfiguration::_type2ACARole< PackageConfiguration::AR_dstPackageConfReference >() const { return make_pair(&meta_dstPackageConfReference, &meta_dstPackageConfReference_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PackageConfiguration::_type2ACARole< PackageConfiguration::AR_dstPackageConfSelectRequirement >() const { return make_pair(&meta_dstPackageConfSelectRequirement, &meta_dstPackageConfSelectRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PackageConfiguration::_type2ACARole< PackageConfiguration::AR_dstPackageConfConfigProperty >() const { return make_pair(&meta_dstPackageConfConfigProperty, &meta_dstPackageConfConfigProperty_rev); }
	template <> const ::Uml::CompositionParentRole& PackageConfiguration::_type2CPRole< PackageConfiguration::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }

	::Uml::Class ImplementationArtifacts::meta;
	::Uml::Attribute ImplementationArtifacts::meta_name;
	::Uml::CompositionChildRole ImplementationArtifacts::meta_ArtifactContainer_children;
	::Uml::CompositionParentRole ImplementationArtifacts::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ImplementationArtifacts::_type2CCRole< ImplementationArtifacts::CR_ArtifactContainer_children >() const { return meta_ArtifactContainer_children; }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifacts::_type2CPRole< ImplementationArtifacts::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class ArtifactDependsOn::meta;
	::Uml::CompositionParentRole ArtifactDependsOn::meta_ArtifactContainer_parent;
	::Uml::AssociationRole ArtifactDependsOn::meta_dstArtifactDependsOn_end_;
	::Uml::AssociationRole ArtifactDependsOn::meta_srcArtifactDependsOn_end_;

	template <> const ::Uml::CompositionParentRole& ArtifactDependsOn::_type2CPRole< ArtifactDependsOn::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::AssociationRole& ArtifactDependsOn::_type2ARole< ArtifactDependsOn::ACE_dstArtifactDependsOn >() const { return meta_dstArtifactDependsOn_end_; }
	template <> const ::Uml::AssociationRole& ArtifactDependsOn::_type2ARole< ArtifactDependsOn::ACE_srcArtifactDependsOn >() const { return meta_srcArtifactDependsOn_end_; }

	::Uml::Class ArtifactDeployRequirement::meta;
	::Uml::CompositionParentRole ArtifactDeployRequirement::meta_ArtifactContainer_parent;
	::Uml::AssociationRole ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_;
	::Uml::AssociationRole ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_;

	template <> const ::Uml::CompositionParentRole& ArtifactDeployRequirement::_type2CPRole< ArtifactDeployRequirement::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::AssociationRole& ArtifactDeployRequirement::_type2ARole< ArtifactDeployRequirement::ACE_srcArtifactDeployRequirement >() const { return meta_srcArtifactDeployRequirement_end_; }
	template <> const ::Uml::AssociationRole& ArtifactDeployRequirement::_type2ARole< ArtifactDeployRequirement::ACE_dstArtifactDeployRequirement >() const { return meta_dstArtifactDeployRequirement_end_; }

	::Uml::Class ArtifactContainer::meta;
	::Uml::CompositionChildRole ArtifactContainer::meta_ImplementationArtifactReference_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_ArtifactDependsOn_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_ArtifactDeployRequirement_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_Requirement_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_ArtifactExecParameter_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_ArtifactInfoProperty_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_Property_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_ImplementationArtifact_children;
	::Uml::CompositionChildRole ArtifactContainer::meta_ArtifactDependency_children;
	::Uml::CompositionParentRole ArtifactContainer::meta_ImplementationArtifacts_parent;

	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_ImplementationArtifactReference_children >() const { return meta_ImplementationArtifactReference_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_ArtifactDependsOn_children >() const { return meta_ArtifactDependsOn_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_ArtifactDeployRequirement_children >() const { return meta_ArtifactDeployRequirement_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_Requirement_children >() const { return meta_Requirement_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_ArtifactExecParameter_children >() const { return meta_ArtifactExecParameter_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_ArtifactInfoProperty_children >() const { return meta_ArtifactInfoProperty_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_ImplementationArtifact_children >() const { return meta_ImplementationArtifact_children; }
	template <> const ::Uml::CompositionChildRole& ArtifactContainer::_type2CCRole< ArtifactContainer::CR_ArtifactDependency_children >() const { return meta_ArtifactDependency_children; }
	template <> const ::Uml::CompositionParentRole& ArtifactContainer::_type2CPRole< ArtifactContainer::PR_ImplementationArtifacts_parent >() const { return meta_ImplementationArtifacts_parent; }

	::Uml::Class ArtifactExecParameter::meta;
	::Uml::CompositionParentRole ArtifactExecParameter::meta_ArtifactContainer_parent;
	::Uml::AssociationRole ArtifactExecParameter::meta_srcArtifactExecParameter_end_;
	::Uml::AssociationRole ArtifactExecParameter::meta_dstArtifactExecParameter_end_;

	template <> const ::Uml::CompositionParentRole& ArtifactExecParameter::_type2CPRole< ArtifactExecParameter::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::AssociationRole& ArtifactExecParameter::_type2ARole< ArtifactExecParameter::ACE_srcArtifactExecParameter >() const { return meta_srcArtifactExecParameter_end_; }
	template <> const ::Uml::AssociationRole& ArtifactExecParameter::_type2ARole< ArtifactExecParameter::ACE_dstArtifactExecParameter >() const { return meta_dstArtifactExecParameter_end_; }

	::Uml::Class ArtifactInfoProperty::meta;
	::Uml::CompositionParentRole ArtifactInfoProperty::meta_ArtifactContainer_parent;
	::Uml::AssociationRole ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_;
	::Uml::AssociationRole ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_;

	template <> const ::Uml::CompositionParentRole& ArtifactInfoProperty::_type2CPRole< ArtifactInfoProperty::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::AssociationRole& ArtifactInfoProperty::_type2ARole< ArtifactInfoProperty::ACE_srcArtifactInfoProperty >() const { return meta_srcArtifactInfoProperty_end_; }
	template <> const ::Uml::AssociationRole& ArtifactInfoProperty::_type2ARole< ArtifactInfoProperty::ACE_dstArtifactInfoProperty >() const { return meta_dstArtifactInfoProperty_end_; }

	::Uml::Class ArtifactDependency::meta;
	::Uml::CompositionParentRole ArtifactDependency::meta_ArtifactContainer_parent;
	::Uml::AssociationRole ArtifactDependency::meta_srcArtifactDependency_end_;
	::Uml::AssociationRole ArtifactDependency::meta_dstArtifactDependency_end_;

	template <> const ::Uml::CompositionParentRole& ArtifactDependency::_type2CPRole< ArtifactDependency::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::AssociationRole& ArtifactDependency::_type2ARole< ArtifactDependency::ACE_srcArtifactDependency >() const { return meta_srcArtifactDependency_end_; }
	template <> const ::Uml::AssociationRole& ArtifactDependency::_type2ARole< ArtifactDependency::ACE_dstArtifactDependency >() const { return meta_dstArtifactDependency_end_; }

	::Uml::Class ImplementationArtifactReference::meta;
	::Uml::AssociationRole ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;
	::Uml::AssociationRole ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev;
	::Uml::AssociationRole ImplementationArtifactReference::meta_ref;
	::Uml::AssociationRole ImplementationArtifactReference::meta_srcArtifactDependsOn;
	::Uml::AssociationRole ImplementationArtifactReference::meta_srcArtifactDependsOn_rev;
	::Uml::CompositionParentRole ImplementationArtifactReference::meta_ImplementationContainer_parent;
	::Uml::CompositionParentRole ImplementationArtifactReference::meta_ArtifactContainer_parent;
	::Uml::CompositionParentRole ImplementationArtifactReference::meta_StubProject_parent;
	::Uml::CompositionParentRole ImplementationArtifactReference::meta_ServantProject_parent;
	::Uml::CompositionParentRole ImplementationArtifactReference::meta_ExecutorProject_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifactReference::_type2ACARole< ImplementationArtifactReference::AR_srcMonolithprimaryArtifact >() const { return make_pair(&meta_srcMonolithprimaryArtifact, &meta_srcMonolithprimaryArtifact_rev); }
	template <> const ::Uml::AssociationRole& ImplementationArtifactReference::_type2ARole< ImplementationArtifactReference::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifactReference::_type2ACARole< ImplementationArtifactReference::AR_srcArtifactDependsOn >() const { return make_pair(&meta_srcArtifactDependsOn, &meta_srcArtifactDependsOn_rev); }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifactReference::_type2CPRole< ImplementationArtifactReference::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifactReference::_type2CPRole< ImplementationArtifactReference::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifactReference::_type2CPRole< ImplementationArtifactReference::PR_StubProject_parent >() const { return meta_StubProject_parent; }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifactReference::_type2CPRole< ImplementationArtifactReference::PR_ServantProject_parent >() const { return meta_ServantProject_parent; }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifactReference::_type2CPRole< ImplementationArtifactReference::PR_ExecutorProject_parent >() const { return meta_ExecutorProject_parent; }

	::Uml::Class ImplementationArtifact::meta;
	::Uml::Attribute ImplementationArtifact::meta_configuration;
	::Uml::Attribute ImplementationArtifact::meta_operatingSystem;
	::Uml::Attribute ImplementationArtifact::meta_artifactVersion;
	::Uml::Attribute ImplementationArtifact::meta_architecture;
	::Uml::Attribute ImplementationArtifact::meta_label;
	::Uml::Attribute ImplementationArtifact::meta_UUID;
	::Uml::Attribute ImplementationArtifact::meta_location;
	::Uml::AssociationRole ImplementationArtifact::meta_referedbyComponentServantArtifact;
	::Uml::AssociationRole ImplementationArtifact::meta_referedbyComponentImplemenationArtifact;
	::Uml::AssociationRole ImplementationArtifact::meta_referedbyImplementationArtifactReference;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDependsOn;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDependsOn_rev;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDeployRequirement;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDeployRequirement_rev;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactExecParameter;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactExecParameter_rev;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactInfoProperty;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactInfoProperty_rev;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDependency;
	::Uml::AssociationRole ImplementationArtifact::meta_dstArtifactDependency_rev;
	::Uml::AssociationRole ImplementationArtifact::meta_srcArtifactDependency;
	::Uml::AssociationRole ImplementationArtifact::meta_srcArtifactDependency_rev;
	::Uml::AssociationRole ImplementationArtifact::meta_referedbyExternalResources;
	::Uml::CompositionParentRole ImplementationArtifact::meta_ArtifactContainer_parent;
	::Uml::CompositionParentRole ImplementationArtifact::meta_Project_parent;

	template <> const ::Uml::AssociationRole& ImplementationArtifact::_type2ARole< ImplementationArtifact::AR_referedbyComponentServantArtifact >() const { return meta_referedbyComponentServantArtifact; }
	template <> const ::Uml::AssociationRole& ImplementationArtifact::_type2ARole< ImplementationArtifact::AR_referedbyComponentImplemenationArtifact >() const { return meta_referedbyComponentImplemenationArtifact; }
	template <> const ::Uml::AssociationRole& ImplementationArtifact::_type2ARole< ImplementationArtifact::AR_referedbyImplementationArtifactReference >() const { return meta_referedbyImplementationArtifactReference; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifact::_type2ACARole< ImplementationArtifact::AR_dstArtifactDependsOn >() const { return make_pair(&meta_dstArtifactDependsOn, &meta_dstArtifactDependsOn_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifact::_type2ACARole< ImplementationArtifact::AR_dstArtifactDeployRequirement >() const { return make_pair(&meta_dstArtifactDeployRequirement, &meta_dstArtifactDeployRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifact::_type2ACARole< ImplementationArtifact::AR_dstArtifactExecParameter >() const { return make_pair(&meta_dstArtifactExecParameter, &meta_dstArtifactExecParameter_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifact::_type2ACARole< ImplementationArtifact::AR_dstArtifactInfoProperty >() const { return make_pair(&meta_dstArtifactInfoProperty, &meta_dstArtifactInfoProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifact::_type2ACARole< ImplementationArtifact::AR_dstArtifactDependency >() const { return make_pair(&meta_dstArtifactDependency, &meta_dstArtifactDependency_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationArtifact::_type2ACARole< ImplementationArtifact::AR_srcArtifactDependency >() const { return make_pair(&meta_srcArtifactDependency, &meta_srcArtifactDependency_rev); }
	template <> const ::Uml::AssociationRole& ImplementationArtifact::_type2ARole< ImplementationArtifact::AR_referedbyExternalResources >() const { return meta_referedbyExternalResources; }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifact::_type2CPRole< ImplementationArtifact::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::CompositionParentRole& ImplementationArtifact::_type2CPRole< ImplementationArtifact::PR_Project_parent >() const { return meta_Project_parent; }

	::Uml::Class ComponentTypes::meta;
	::Uml::Attribute ComponentTypes::meta_name;
	::Uml::CompositionChildRole ComponentTypes::meta_ComponentContainer_children;
	::Uml::CompositionParentRole ComponentTypes::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ComponentTypes::_type2CCRole< ComponentTypes::CR_ComponentContainer_children >() const { return meta_ComponentContainer_children; }
	template <> const ::Uml::CompositionParentRole& ComponentTypes::_type2CPRole< ComponentTypes::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class ComponentPropertyDescription::meta;
	::Uml::AssociationRole ComponentPropertyDescription::meta_srcComponentProperty;
	::Uml::AssociationRole ComponentPropertyDescription::meta_srcComponentProperty_rev;
	::Uml::CompositionChildRole ComponentPropertyDescription::meta_DataType_child;
	::Uml::CompositionParentRole ComponentPropertyDescription::meta_ComponentContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentPropertyDescription::_type2ACARole< ComponentPropertyDescription::AR_srcComponentProperty >() const { return make_pair(&meta_srcComponentProperty, &meta_srcComponentProperty_rev); }
	template <> const ::Uml::CompositionChildRole& ComponentPropertyDescription::_type2CCRole< ComponentPropertyDescription::CR_DataType_child >() const { return meta_DataType_child; }
	template <> const ::Uml::CompositionParentRole& ComponentPropertyDescription::_type2CPRole< ComponentPropertyDescription::PR_ComponentContainer_parent >() const { return meta_ComponentContainer_parent; }

	::Uml::Class ComponentProperty::meta;
	::Uml::CompositionParentRole ComponentProperty::meta_ComponentContainer_parent;
	::Uml::AssociationRole ComponentProperty::meta_dstComponentProperty_end_;
	::Uml::AssociationRole ComponentProperty::meta_srcComponentProperty_end_;

	template <> const ::Uml::CompositionParentRole& ComponentProperty::_type2CPRole< ComponentProperty::PR_ComponentContainer_parent >() const { return meta_ComponentContainer_parent; }
	template <> const ::Uml::AssociationRole& ComponentProperty::_type2ARole< ComponentProperty::ACE_dstComponentProperty >() const { return meta_dstComponentProperty_end_; }
	template <> const ::Uml::AssociationRole& ComponentProperty::_type2ARole< ComponentProperty::ACE_srcComponentProperty >() const { return meta_srcComponentProperty_end_; }

	::Uml::Class ComponentContainer::meta;
	::Uml::CompositionChildRole ComponentContainer::meta_ComponentConfigProperty_children;
	::Uml::CompositionChildRole ComponentContainer::meta_Property_children;
	::Uml::CompositionChildRole ComponentContainer::meta_ComponentInfoProperty_children;
	::Uml::CompositionChildRole ComponentContainer::meta_ComponentProperty_children;
	::Uml::CompositionChildRole ComponentContainer::meta_ComponentPropertyDescription_children;
	::Uml::CompositionChildRole ComponentContainer::meta_ComponentRef_child;
	::Uml::CompositionParentRole ComponentContainer::meta_ComponentTypes_parent;

	template <> const ::Uml::CompositionChildRole& ComponentContainer::_type2CCRole< ComponentContainer::CR_ComponentConfigProperty_children >() const { return meta_ComponentConfigProperty_children; }
	template <> const ::Uml::CompositionChildRole& ComponentContainer::_type2CCRole< ComponentContainer::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& ComponentContainer::_type2CCRole< ComponentContainer::CR_ComponentInfoProperty_children >() const { return meta_ComponentInfoProperty_children; }
	template <> const ::Uml::CompositionChildRole& ComponentContainer::_type2CCRole< ComponentContainer::CR_ComponentProperty_children >() const { return meta_ComponentProperty_children; }
	template <> const ::Uml::CompositionChildRole& ComponentContainer::_type2CCRole< ComponentContainer::CR_ComponentPropertyDescription_children >() const { return meta_ComponentPropertyDescription_children; }
	template <> const ::Uml::CompositionChildRole& ComponentContainer::_type2CCRole< ComponentContainer::CR_ComponentRef_child >() const { return meta_ComponentRef_child; }
	template <> const ::Uml::CompositionParentRole& ComponentContainer::_type2CPRole< ComponentContainer::PR_ComponentTypes_parent >() const { return meta_ComponentTypes_parent; }

	::Uml::Class ComponentConfigProperty::meta;
	::Uml::CompositionParentRole ComponentConfigProperty::meta_ComponentContainer_parent;
	::Uml::AssociationRole ComponentConfigProperty::meta_dstComponentConfigProperty_end_;
	::Uml::AssociationRole ComponentConfigProperty::meta_srcComponentConfigProperty_end_;

	template <> const ::Uml::CompositionParentRole& ComponentConfigProperty::_type2CPRole< ComponentConfigProperty::PR_ComponentContainer_parent >() const { return meta_ComponentContainer_parent; }
	template <> const ::Uml::AssociationRole& ComponentConfigProperty::_type2ARole< ComponentConfigProperty::ACE_dstComponentConfigProperty >() const { return meta_dstComponentConfigProperty_end_; }
	template <> const ::Uml::AssociationRole& ComponentConfigProperty::_type2ARole< ComponentConfigProperty::ACE_srcComponentConfigProperty >() const { return meta_srcComponentConfigProperty_end_; }

	::Uml::Class ComponentInfoProperty::meta;
	::Uml::CompositionParentRole ComponentInfoProperty::meta_ComponentContainer_parent;
	::Uml::AssociationRole ComponentInfoProperty::meta_dstComponentInfoProperty_end_;
	::Uml::AssociationRole ComponentInfoProperty::meta_srcComponentInfoProperty_end_;

	template <> const ::Uml::CompositionParentRole& ComponentInfoProperty::_type2CPRole< ComponentInfoProperty::PR_ComponentContainer_parent >() const { return meta_ComponentContainer_parent; }
	template <> const ::Uml::AssociationRole& ComponentInfoProperty::_type2ARole< ComponentInfoProperty::ACE_dstComponentInfoProperty >() const { return meta_dstComponentInfoProperty_end_; }
	template <> const ::Uml::AssociationRole& ComponentInfoProperty::_type2ARole< ComponentInfoProperty::ACE_srcComponentInfoProperty >() const { return meta_srcComponentInfoProperty_end_; }

	::Uml::Class CommonPortAttrs::meta;
	::Uml::Attribute CommonPortAttrs::meta_exclusiveUser;
	::Uml::Attribute CommonPortAttrs::meta_optional;
	::Uml::Attribute CommonPortAttrs::meta_exclusiveProvider;

	::Uml::Class TopLevelPackageContainer::meta;
	::Uml::CompositionChildRole TopLevelPackageContainer::meta_TopLevelPackage_child;
	::Uml::CompositionChildRole TopLevelPackageContainer::meta_PackageConfigurationReference_child;
	::Uml::CompositionChildRole TopLevelPackageContainer::meta_package_child;
	::Uml::CompositionParentRole TopLevelPackageContainer::meta_TopLevelPackages_parent;

	template <> const ::Uml::CompositionChildRole& TopLevelPackageContainer::_type2CCRole< TopLevelPackageContainer::CR_TopLevelPackage_child >() const { return meta_TopLevelPackage_child; }
	template <> const ::Uml::CompositionChildRole& TopLevelPackageContainer::_type2CCRole< TopLevelPackageContainer::CR_PackageConfigurationReference_child >() const { return meta_PackageConfigurationReference_child; }
	template <> const ::Uml::CompositionChildRole& TopLevelPackageContainer::_type2CCRole< TopLevelPackageContainer::CR_package_child >() const { return meta_package_child; }
	template <> const ::Uml::CompositionParentRole& TopLevelPackageContainer::_type2CPRole< TopLevelPackageContainer::PR_TopLevelPackages_parent >() const { return meta_TopLevelPackages_parent; }

	::Uml::Class TopLevelPackages::meta;
	::Uml::Attribute TopLevelPackages::meta_name;
	::Uml::CompositionChildRole TopLevelPackages::meta_TopLevelPackageContainer_children;
	::Uml::CompositionParentRole TopLevelPackages::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& TopLevelPackages::_type2CCRole< TopLevelPackages::CR_TopLevelPackageContainer_children >() const { return meta_TopLevelPackageContainer_children; }
	template <> const ::Uml::CompositionParentRole& TopLevelPackages::_type2CPRole< TopLevelPackages::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class TopLevelPackage::meta;
	::Uml::AssociationRole TopLevelPackage::meta_dstpackage;
	::Uml::AssociationRole TopLevelPackage::meta_dstpackage_rev;
	::Uml::CompositionParentRole TopLevelPackage::meta_TopLevelPackageContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> TopLevelPackage::_type2ACARole< TopLevelPackage::AR_dstpackage >() const { return make_pair(&meta_dstpackage, &meta_dstpackage_rev); }
	template <> const ::Uml::CompositionParentRole& TopLevelPackage::_type2CPRole< TopLevelPackage::PR_TopLevelPackageContainer_parent >() const { return meta_TopLevelPackageContainer_parent; }

	::Uml::Class package::meta;
	::Uml::CompositionParentRole package::meta_TopLevelPackageContainer_parent;
	::Uml::AssociationRole package::meta_dstpackage_end_;
	::Uml::AssociationRole package::meta_srcpackage_end_;

	template <> const ::Uml::CompositionParentRole& package::_type2CPRole< package::PR_TopLevelPackageContainer_parent >() const { return meta_TopLevelPackageContainer_parent; }
	template <> const ::Uml::AssociationRole& package::_type2ARole< package::ACE_dstpackage >() const { return meta_dstpackage_end_; }
	template <> const ::Uml::AssociationRole& package::_type2ARole< package::ACE_srcpackage >() const { return meta_srcpackage_end_; }

	::Uml::Class ComponentPackages::meta;
	::Uml::Attribute ComponentPackages::meta_name;
	::Uml::CompositionChildRole ComponentPackages::meta_PackageContainer_children;
	::Uml::CompositionParentRole ComponentPackages::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ComponentPackages::_type2CCRole< ComponentPackages::CR_PackageContainer_children >() const { return meta_PackageContainer_children; }
	template <> const ::Uml::CompositionParentRole& ComponentPackages::_type2CPRole< ComponentPackages::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class PackageInterface::meta;
	::Uml::CompositionParentRole PackageInterface::meta_PackageContainer_parent;
	::Uml::AssociationRole PackageInterface::meta_srcPackageInterface_end_;
	::Uml::AssociationRole PackageInterface::meta_dstPackageInterface_end_;

	template <> const ::Uml::CompositionParentRole& PackageInterface::_type2CPRole< PackageInterface::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageInterface::_type2ARole< PackageInterface::ACE_srcPackageInterface >() const { return meta_srcPackageInterface_end_; }
	template <> const ::Uml::AssociationRole& PackageInterface::_type2ARole< PackageInterface::ACE_dstPackageInterface >() const { return meta_dstPackageInterface_end_; }

	::Uml::Class Implementation::meta;
	::Uml::CompositionParentRole Implementation::meta_PackageContainer_parent;
	::Uml::AssociationRole Implementation::meta_dstImplementation_end_;
	::Uml::AssociationRole Implementation::meta_srcImplementation_end_;

	template <> const ::Uml::CompositionParentRole& Implementation::_type2CPRole< Implementation::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }
	template <> const ::Uml::AssociationRole& Implementation::_type2ARole< Implementation::ACE_dstImplementation >() const { return meta_dstImplementation_end_; }
	template <> const ::Uml::AssociationRole& Implementation::_type2ARole< Implementation::ACE_srcImplementation >() const { return meta_srcImplementation_end_; }

	::Uml::Class PackageContainer::meta;
	::Uml::CompositionChildRole PackageContainer::meta_Implementation_children;
	::Uml::CompositionChildRole PackageContainer::meta_PackageInterface_child;
	::Uml::CompositionChildRole PackageContainer::meta_ComponentImplementationReference_children;
	::Uml::CompositionChildRole PackageContainer::meta_ComponentRef_child;
	::Uml::CompositionChildRole PackageContainer::meta_PackageConfigProperty_children;
	::Uml::CompositionChildRole PackageContainer::meta_Property_children;
	::Uml::CompositionChildRole PackageContainer::meta_PackageInfoProperty_children;
	::Uml::CompositionChildRole PackageContainer::meta_ComponentPackage_child;
	::Uml::CompositionParentRole PackageContainer::meta_ComponentPackages_parent;

	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_Implementation_children >() const { return meta_Implementation_children; }
	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_PackageInterface_child >() const { return meta_PackageInterface_child; }
	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_ComponentImplementationReference_children >() const { return meta_ComponentImplementationReference_children; }
	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_ComponentRef_child >() const { return meta_ComponentRef_child; }
	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_PackageConfigProperty_children >() const { return meta_PackageConfigProperty_children; }
	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_PackageInfoProperty_children >() const { return meta_PackageInfoProperty_children; }
	template <> const ::Uml::CompositionChildRole& PackageContainer::_type2CCRole< PackageContainer::CR_ComponentPackage_child >() const { return meta_ComponentPackage_child; }
	template <> const ::Uml::CompositionParentRole& PackageContainer::_type2CPRole< PackageContainer::PR_ComponentPackages_parent >() const { return meta_ComponentPackages_parent; }

	::Uml::Class PackageConfigProperty::meta;
	::Uml::CompositionParentRole PackageConfigProperty::meta_PackageContainer_parent;
	::Uml::AssociationRole PackageConfigProperty::meta_srcPackageConfigProperty_end_;
	::Uml::AssociationRole PackageConfigProperty::meta_dstPackageConfigProperty_end_;

	template <> const ::Uml::CompositionParentRole& PackageConfigProperty::_type2CPRole< PackageConfigProperty::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageConfigProperty::_type2ARole< PackageConfigProperty::ACE_srcPackageConfigProperty >() const { return meta_srcPackageConfigProperty_end_; }
	template <> const ::Uml::AssociationRole& PackageConfigProperty::_type2ARole< PackageConfigProperty::ACE_dstPackageConfigProperty >() const { return meta_dstPackageConfigProperty_end_; }

	::Uml::Class PackageInfoProperty::meta;
	::Uml::CompositionParentRole PackageInfoProperty::meta_PackageContainer_parent;
	::Uml::AssociationRole PackageInfoProperty::meta_srcPackageInfoProperty_end_;
	::Uml::AssociationRole PackageInfoProperty::meta_dstPackageInfoProperty_end_;

	template <> const ::Uml::CompositionParentRole& PackageInfoProperty::_type2CPRole< PackageInfoProperty::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }
	template <> const ::Uml::AssociationRole& PackageInfoProperty::_type2ARole< PackageInfoProperty::ACE_srcPackageInfoProperty >() const { return meta_srcPackageInfoProperty_end_; }
	template <> const ::Uml::AssociationRole& PackageInfoProperty::_type2ARole< PackageInfoProperty::ACE_dstPackageInfoProperty >() const { return meta_dstPackageInfoProperty_end_; }

	::Uml::Class ComponentPackage::meta;
	::Uml::Attribute ComponentPackage::meta_UUID;
	::Uml::Attribute ComponentPackage::meta_label;
	::Uml::AssociationRole ComponentPackage::meta_dstImplementation;
	::Uml::AssociationRole ComponentPackage::meta_dstImplementation_rev;
	::Uml::AssociationRole ComponentPackage::meta_srcPackageConfBasePackage;
	::Uml::AssociationRole ComponentPackage::meta_srcPackageConfBasePackage_rev;
	::Uml::AssociationRole ComponentPackage::meta_dstPackageInterface;
	::Uml::AssociationRole ComponentPackage::meta_dstPackageInterface_rev;
	::Uml::AssociationRole ComponentPackage::meta_dstPackageConfigProperty;
	::Uml::AssociationRole ComponentPackage::meta_dstPackageConfigProperty_rev;
	::Uml::AssociationRole ComponentPackage::meta_dstPackageInfoProperty;
	::Uml::AssociationRole ComponentPackage::meta_dstPackageInfoProperty_rev;
	::Uml::AssociationRole ComponentPackage::meta_referedbyComponentPackageReference;
	::Uml::CompositionParentRole ComponentPackage::meta_ComponentAssembly_parent;
	::Uml::CompositionParentRole ComponentPackage::meta_PackageConfigurationContainer_parent;
	::Uml::CompositionParentRole ComponentPackage::meta_PackageContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentPackage::_type2ACARole< ComponentPackage::AR_dstImplementation >() const { return make_pair(&meta_dstImplementation, &meta_dstImplementation_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentPackage::_type2ACARole< ComponentPackage::AR_srcPackageConfBasePackage >() const { return make_pair(&meta_srcPackageConfBasePackage, &meta_srcPackageConfBasePackage_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentPackage::_type2ACARole< ComponentPackage::AR_dstPackageInterface >() const { return make_pair(&meta_dstPackageInterface, &meta_dstPackageInterface_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentPackage::_type2ACARole< ComponentPackage::AR_dstPackageConfigProperty >() const { return make_pair(&meta_dstPackageConfigProperty, &meta_dstPackageConfigProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentPackage::_type2ACARole< ComponentPackage::AR_dstPackageInfoProperty >() const { return make_pair(&meta_dstPackageInfoProperty, &meta_dstPackageInfoProperty_rev); }
	template <> const ::Uml::AssociationRole& ComponentPackage::_type2ARole< ComponentPackage::AR_referedbyComponentPackageReference >() const { return meta_referedbyComponentPackageReference; }
	template <> const ::Uml::CompositionParentRole& ComponentPackage::_type2CPRole< ComponentPackage::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentPackage::_type2CPRole< ComponentPackage::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentPackage::_type2CPRole< ComponentPackage::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }

	::Uml::Class ComponentPackageReference::meta;
	::Uml::Attribute ComponentPackageReference::meta_requiredName;
	::Uml::Attribute ComponentPackageReference::meta_requiredUUID;
	::Uml::Attribute ComponentPackageReference::meta_requiredType;
	::Uml::AssociationRole ComponentPackageReference::meta_srcPackageConfReference;
	::Uml::AssociationRole ComponentPackageReference::meta_srcPackageConfReference_rev;
	::Uml::AssociationRole ComponentPackageReference::meta_ref;
	::Uml::CompositionParentRole ComponentPackageReference::meta_ComponentAssembly_parent;
	::Uml::CompositionParentRole ComponentPackageReference::meta_PackageConfigurationContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentPackageReference::_type2ACARole< ComponentPackageReference::AR_srcPackageConfReference >() const { return make_pair(&meta_srcPackageConfReference, &meta_srcPackageConfReference_rev); }
	template <> const ::Uml::AssociationRole& ComponentPackageReference::_type2ARole< ComponentPackageReference::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& ComponentPackageReference::_type2CPRole< ComponentPackageReference::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentPackageReference::_type2CPRole< ComponentPackageReference::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }

	::Uml::Class Requirement::meta;
	::Uml::AssociationRole Requirement::meta_srcAssemblyDeployRequirement;
	::Uml::AssociationRole Requirement::meta_srcAssemblyDeployRequirement_rev;
	::Uml::AssociationRole Requirement::meta_srcPackageConfSelectRequirement;
	::Uml::AssociationRole Requirement::meta_srcPackageConfSelectRequirement_rev;
	::Uml::AssociationRole Requirement::meta_srcArtifactDeployRequirement;
	::Uml::AssociationRole Requirement::meta_srcArtifactDeployRequirement_rev;
	::Uml::AssociationRole Requirement::meta_srcAssemblyselectRequirement;
	::Uml::AssociationRole Requirement::meta_srcAssemblyselectRequirement_rev;
	::Uml::CompositionParentRole Requirement::meta_ComponentAssembly_parent;
	::Uml::CompositionParentRole Requirement::meta_PackageConfigurationContainer_parent;
	::Uml::CompositionParentRole Requirement::meta_ArtifactContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Requirement::_type2ACARole< Requirement::AR_srcAssemblyDeployRequirement >() const { return make_pair(&meta_srcAssemblyDeployRequirement, &meta_srcAssemblyDeployRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Requirement::_type2ACARole< Requirement::AR_srcPackageConfSelectRequirement >() const { return make_pair(&meta_srcPackageConfSelectRequirement, &meta_srcPackageConfSelectRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Requirement::_type2ACARole< Requirement::AR_srcArtifactDeployRequirement >() const { return make_pair(&meta_srcArtifactDeployRequirement, &meta_srcArtifactDeployRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Requirement::_type2ACARole< Requirement::AR_srcAssemblyselectRequirement >() const { return make_pair(&meta_srcAssemblyselectRequirement, &meta_srcAssemblyselectRequirement_rev); }
	template <> const ::Uml::CompositionParentRole& Requirement::_type2CPRole< Requirement::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::CompositionParentRole& Requirement::_type2CPRole< Requirement::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::CompositionParentRole& Requirement::_type2CPRole< Requirement::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }

	::Uml::Class Capability::meta;
	::Uml::AssociationRole Capability::meta_srcImplementationCapability;
	::Uml::AssociationRole Capability::meta_srcImplementationCapability_rev;
	::Uml::CompositionParentRole Capability::meta_ComponentImplementationContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Capability::_type2ACARole< Capability::AR_srcImplementationCapability >() const { return make_pair(&meta_srcImplementationCapability, &meta_srcImplementationCapability_rev); }
	template <> const ::Uml::CompositionParentRole& Capability::_type2CPRole< Capability::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }

	::Uml::Class DataType::meta;
	::Uml::AssociationRole DataType::meta_ref;
	::Uml::CompositionParentRole DataType::meta_ComponentPropertyDescription_parent;
	::Uml::CompositionParentRole DataType::meta_SatisfierProperty_parent;
	::Uml::CompositionParentRole DataType::meta_Property_parent;

	template <> const ::Uml::AssociationRole& DataType::_type2ARole< DataType::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& DataType::_type2CPRole< DataType::PR_ComponentPropertyDescription_parent >() const { return meta_ComponentPropertyDescription_parent; }
	template <> const ::Uml::CompositionParentRole& DataType::_type2CPRole< DataType::PR_SatisfierProperty_parent >() const { return meta_SatisfierProperty_parent; }
	template <> const ::Uml::CompositionParentRole& DataType::_type2CPRole< DataType::PR_Property_parent >() const { return meta_Property_parent; }

	::Uml::Class SatisfierProperty::meta;
	::Uml::Attribute SatisfierProperty::meta_DataValue;
	::Uml::Attribute SatisfierProperty::meta_SatisfierPropertyKind;
	::Uml::Attribute SatisfierProperty::meta_dynamic;
	::Uml::CompositionChildRole SatisfierProperty::meta_DataType_child;
	::Uml::CompositionParentRole SatisfierProperty::meta_RequirementSatisfier_parent;

	template <> const ::Uml::CompositionChildRole& SatisfierProperty::_type2CCRole< SatisfierProperty::CR_DataType_child >() const { return meta_DataType_child; }
	template <> const ::Uml::CompositionParentRole& SatisfierProperty::_type2CPRole< SatisfierProperty::PR_RequirementSatisfier_parent >() const { return meta_RequirementSatisfier_parent; }

	::Uml::Class ImplementationDependency::meta;
	::Uml::Attribute ImplementationDependency::meta_requiredType;
	::Uml::AssociationRole ImplementationDependency::meta_srcImplementationDependsOn;
	::Uml::AssociationRole ImplementationDependency::meta_srcImplementationDependsOn_rev;
	::Uml::CompositionParentRole ImplementationDependency::meta_ComponentImplementationContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationDependency::_type2ACARole< ImplementationDependency::AR_srcImplementationDependsOn >() const { return make_pair(&meta_srcImplementationDependsOn, &meta_srcImplementationDependsOn_rev); }
	template <> const ::Uml::CompositionParentRole& ImplementationDependency::_type2CPRole< ImplementationDependency::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }

	::Uml::Class RequirementSatisfier::meta;
	::Uml::Attribute RequirementSatisfier::meta_resourceType;
	::Uml::CompositionChildRole RequirementSatisfier::meta_SatisfierProperty_children;

	template <> const ::Uml::CompositionChildRole& RequirementSatisfier::_type2CCRole< RequirementSatisfier::CR_SatisfierProperty_children >() const { return meta_SatisfierProperty_children; }

	::Uml::Class RequirementBase::meta;
	::Uml::Attribute RequirementBase::meta_resourceType;
	::Uml::CompositionChildRole RequirementBase::meta_Property_children;

	template <> const ::Uml::CompositionChildRole& RequirementBase::_type2CCRole< RequirementBase::CR_Property_children >() const { return meta_Property_children; }

	::Uml::Class ImplementationRequirement::meta;
	::Uml::Attribute ImplementationRequirement::meta_ResourceUsageKind;
	::Uml::Attribute ImplementationRequirement::meta_componentPort;
	::Uml::Attribute ImplementationRequirement::meta_resourcePort;
	::Uml::AssociationRole ImplementationRequirement::meta_srcMonolithDeployRequirement;
	::Uml::AssociationRole ImplementationRequirement::meta_srcMonolithDeployRequirement_rev;
	::Uml::CompositionParentRole ImplementationRequirement::meta_ImplementationContainer_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ImplementationRequirement::_type2ACARole< ImplementationRequirement::AR_srcMonolithDeployRequirement >() const { return make_pair(&meta_srcMonolithDeployRequirement, &meta_srcMonolithDeployRequirement_rev); }
	template <> const ::Uml::CompositionParentRole& ImplementationRequirement::_type2CPRole< ImplementationRequirement::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }

	::Uml::Class Property::meta;
	::Uml::Attribute Property::meta_DataValue;
	::Uml::AssociationRole Property::meta_srcMonolithExecParameter;
	::Uml::AssociationRole Property::meta_srcMonolithExecParameter_rev;
	::Uml::AssociationRole Property::meta_srcInfoProperty;
	::Uml::AssociationRole Property::meta_srcInfoProperty_rev;
	::Uml::AssociationRole Property::meta_srcConfigProperty;
	::Uml::AssociationRole Property::meta_srcConfigProperty_rev;
	::Uml::AssociationRole Property::meta_srcPathProperty;
	::Uml::AssociationRole Property::meta_srcPathProperty_rev;
	::Uml::AssociationRole Property::meta_dstPropertyConnector;
	::Uml::AssociationRole Property::meta_dstPropertyConnector_rev;
	::Uml::AssociationRole Property::meta_srcAttributeMappingValue;
	::Uml::AssociationRole Property::meta_srcAttributeMappingValue_rev;
	::Uml::AssociationRole Property::meta_srcPackageConfConfigProperty;
	::Uml::AssociationRole Property::meta_srcPackageConfConfigProperty_rev;
	::Uml::AssociationRole Property::meta_srcArtifactExecParameter;
	::Uml::AssociationRole Property::meta_srcArtifactExecParameter_rev;
	::Uml::AssociationRole Property::meta_srcArtifactInfoProperty;
	::Uml::AssociationRole Property::meta_srcArtifactInfoProperty_rev;
	::Uml::AssociationRole Property::meta_srcPackageConfigProperty;
	::Uml::AssociationRole Property::meta_srcPackageConfigProperty_rev;
	::Uml::AssociationRole Property::meta_srcPackageInfoProperty;
	::Uml::AssociationRole Property::meta_srcPackageInfoProperty_rev;
	::Uml::AssociationRole Property::meta_srcComponentConfigProperty;
	::Uml::AssociationRole Property::meta_srcComponentConfigProperty_rev;
	::Uml::AssociationRole Property::meta_srcComponentInfoProperty;
	::Uml::AssociationRole Property::meta_srcComponentInfoProperty_rev;
	::Uml::AssociationRole Property::meta_srcAssemblyConfigProperty;
	::Uml::AssociationRole Property::meta_srcAssemblyConfigProperty_rev;
	::Uml::AssociationRole Property::meta_srcAttributeValue;
	::Uml::AssociationRole Property::meta_srcAttributeValue_rev;
	::Uml::CompositionChildRole Property::meta_DataType_child;
	::Uml::CompositionParentRole Property::meta_ImplementationContainer_parent;
	::Uml::CompositionParentRole Property::meta_ComponentAssembly_parent;
	::Uml::CompositionParentRole Property::meta_Path_parent;
	::Uml::CompositionParentRole Property::meta_Paths_parent;
	::Uml::CompositionParentRole Property::meta_DeploymentPlan_parent;
	::Uml::CompositionParentRole Property::meta_PackageConfigurationContainer_parent;
	::Uml::CompositionParentRole Property::meta_ArtifactContainer_parent;
	::Uml::CompositionParentRole Property::meta_ComponentContainer_parent;
	::Uml::CompositionParentRole Property::meta_PackageContainer_parent;
	::Uml::CompositionParentRole Property::meta_RequirementBase_parent;
	::Uml::CompositionParentRole Property::meta_Domain_parent;
	::Uml::CompositionParentRole Property::meta_BehaviorInputAction_parent;
	::Uml::CompositionParentRole Property::meta_QueryInputAction_parent;
	::Uml::CompositionParentRole Property::meta_ActionBase_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcMonolithExecParameter >() const { return make_pair(&meta_srcMonolithExecParameter, &meta_srcMonolithExecParameter_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcInfoProperty >() const { return make_pair(&meta_srcInfoProperty, &meta_srcInfoProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcConfigProperty >() const { return make_pair(&meta_srcConfigProperty, &meta_srcConfigProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcPathProperty >() const { return make_pair(&meta_srcPathProperty, &meta_srcPathProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_dstPropertyConnector >() const { return make_pair(&meta_dstPropertyConnector, &meta_dstPropertyConnector_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcAttributeMappingValue >() const { return make_pair(&meta_srcAttributeMappingValue, &meta_srcAttributeMappingValue_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcPackageConfConfigProperty >() const { return make_pair(&meta_srcPackageConfConfigProperty, &meta_srcPackageConfConfigProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcArtifactExecParameter >() const { return make_pair(&meta_srcArtifactExecParameter, &meta_srcArtifactExecParameter_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcArtifactInfoProperty >() const { return make_pair(&meta_srcArtifactInfoProperty, &meta_srcArtifactInfoProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcPackageConfigProperty >() const { return make_pair(&meta_srcPackageConfigProperty, &meta_srcPackageConfigProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcPackageInfoProperty >() const { return make_pair(&meta_srcPackageInfoProperty, &meta_srcPackageInfoProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcComponentConfigProperty >() const { return make_pair(&meta_srcComponentConfigProperty, &meta_srcComponentConfigProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcComponentInfoProperty >() const { return make_pair(&meta_srcComponentInfoProperty, &meta_srcComponentInfoProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcAssemblyConfigProperty >() const { return make_pair(&meta_srcAssemblyConfigProperty, &meta_srcAssemblyConfigProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Property::_type2ACARole< Property::AR_srcAttributeValue >() const { return make_pair(&meta_srcAttributeValue, &meta_srcAttributeValue_rev); }
	template <> const ::Uml::CompositionChildRole& Property::_type2CCRole< Property::CR_DataType_child >() const { return meta_DataType_child; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_ImplementationContainer_parent >() const { return meta_ImplementationContainer_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_Path_parent >() const { return meta_Path_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_Paths_parent >() const { return meta_Paths_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_DeploymentPlan_parent >() const { return meta_DeploymentPlan_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_PackageConfigurationContainer_parent >() const { return meta_PackageConfigurationContainer_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_ArtifactContainer_parent >() const { return meta_ArtifactContainer_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_ComponentContainer_parent >() const { return meta_ComponentContainer_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_RequirementBase_parent >() const { return meta_RequirementBase_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_Domain_parent >() const { return meta_Domain_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_BehaviorInputAction_parent >() const { return meta_BehaviorInputAction_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_QueryInputAction_parent >() const { return meta_QueryInputAction_parent; }
	template <> const ::Uml::CompositionParentRole& Property::_type2CPRole< Property::PR_ActionBase_parent >() const { return meta_ActionBase_parent; }

	::Uml::Class Targets::meta;
	::Uml::Attribute Targets::meta_name;
	::Uml::CompositionChildRole Targets::meta_Domain_children;
	::Uml::CompositionParentRole Targets::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& Targets::_type2CCRole< Targets::CR_Domain_children >() const { return meta_Domain_children; }
	template <> const ::Uml::CompositionParentRole& Targets::_type2CPRole< Targets::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class Shares::meta;
	::Uml::CompositionParentRole Shares::meta_Domain_parent;
	::Uml::AssociationRole Shares::meta_srcShares_end_;
	::Uml::AssociationRole Shares::meta_dstShares_end_;

	template <> const ::Uml::CompositionParentRole& Shares::_type2CPRole< Shares::PR_Domain_parent >() const { return meta_Domain_parent; }
	template <> const ::Uml::AssociationRole& Shares::_type2ARole< Shares::ACE_srcShares >() const { return meta_srcShares_end_; }
	template <> const ::Uml::AssociationRole& Shares::_type2ARole< Shares::ACE_dstShares >() const { return meta_dstShares_end_; }

	::Uml::Class InterconnectConnection::meta;
	::Uml::CompositionParentRole InterconnectConnection::meta_Domain_parent;
	::Uml::AssociationRole InterconnectConnection::meta_dstInterconnectConnection_end_;
	::Uml::AssociationRole InterconnectConnection::meta_srcInterconnectConnection_end_;

	template <> const ::Uml::CompositionParentRole& InterconnectConnection::_type2CPRole< InterconnectConnection::PR_Domain_parent >() const { return meta_Domain_parent; }
	template <> const ::Uml::AssociationRole& InterconnectConnection::_type2ARole< InterconnectConnection::ACE_dstInterconnectConnection >() const { return meta_dstInterconnectConnection_end_; }
	template <> const ::Uml::AssociationRole& InterconnectConnection::_type2ARole< InterconnectConnection::ACE_srcInterconnectConnection >() const { return meta_srcInterconnectConnection_end_; }

	::Uml::Class BridgeConnection::meta;
	::Uml::CompositionParentRole BridgeConnection::meta_Domain_parent;
	::Uml::AssociationRole BridgeConnection::meta_srcBridgeConnection_end_;
	::Uml::AssociationRole BridgeConnection::meta_dstBridgeConnection_end_;

	template <> const ::Uml::CompositionParentRole& BridgeConnection::_type2CPRole< BridgeConnection::PR_Domain_parent >() const { return meta_Domain_parent; }
	template <> const ::Uml::AssociationRole& BridgeConnection::_type2ARole< BridgeConnection::ACE_srcBridgeConnection >() const { return meta_srcBridgeConnection_end_; }
	template <> const ::Uml::AssociationRole& BridgeConnection::_type2ARole< BridgeConnection::ACE_dstBridgeConnection >() const { return meta_dstBridgeConnection_end_; }

	::Uml::Class Domain::meta;
	::Uml::Attribute Domain::meta_label;
	::Uml::Attribute Domain::meta_UUID;
	::Uml::CompositionChildRole Domain::meta_Interconnect_children;
	::Uml::CompositionChildRole Domain::meta_InterconnectConnection_children;
	::Uml::CompositionChildRole Domain::meta_Node_children;
	::Uml::CompositionChildRole Domain::meta_BridgeConnection_children;
	::Uml::CompositionChildRole Domain::meta_Bridge_children;
	::Uml::CompositionChildRole Domain::meta_SharedResource_children;
	::Uml::CompositionChildRole Domain::meta_Shares_children;
	::Uml::CompositionChildRole Domain::meta_Property_children;
	::Uml::CompositionParentRole Domain::meta_Targets_parent;

	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_Interconnect_children >() const { return meta_Interconnect_children; }
	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_InterconnectConnection_children >() const { return meta_InterconnectConnection_children; }
	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_Node_children >() const { return meta_Node_children; }
	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_BridgeConnection_children >() const { return meta_BridgeConnection_children; }
	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_Bridge_children >() const { return meta_Bridge_children; }
	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_SharedResource_children >() const { return meta_SharedResource_children; }
	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_Shares_children >() const { return meta_Shares_children; }
	template <> const ::Uml::CompositionChildRole& Domain::_type2CCRole< Domain::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionParentRole& Domain::_type2CPRole< Domain::PR_Targets_parent >() const { return meta_Targets_parent; }

	::Uml::Class Prefixable::meta;
	::Uml::Attribute Prefixable::meta_PrefixTag;

	::Uml::Class Taggable::meta;
	::Uml::Attribute Taggable::meta_SpecifyIdTag;
	::Uml::Attribute Taggable::meta_VersionTag;

	::Uml::Class Port::meta;
	::Uml::AssociationRole Port::meta_srcExternalDelegate;
	::Uml::AssociationRole Port::meta_srcExternalDelegate_rev;
	::Uml::CompositionParentRole Port::meta_ConnectedComponent_parent;
	::Uml::CompositionParentRole Port::meta_Component_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Port::_type2ACARole< Port::AR_srcExternalDelegate >() const { return make_pair(&meta_srcExternalDelegate, &meta_srcExternalDelegate_rev); }
	template <> const ::Uml::CompositionParentRole& Port::_type2CPRole< Port::PR_ConnectedComponent_parent >() const { return meta_ConnectedComponent_parent; }
	template <> const ::Uml::CompositionParentRole& Port::_type2CPRole< Port::PR_Component_parent >() const { return meta_Component_parent; }

	::Uml::Class Manageable::meta;
	::Uml::AssociationRole Manageable::meta_srcManagesComponent;
	::Uml::AssociationRole Manageable::meta_srcManagesComponent_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Manageable::_type2ACARole< Manageable::AR_srcManagesComponent >() const { return make_pair(&meta_srcManagesComponent, &meta_srcManagesComponent_rev); }

	::Uml::Class Provideable::meta;
	::Uml::AssociationRole Provideable::meta_referedbyRequiredRequestPort;
	::Uml::AssociationRole Provideable::meta_referedbyProvidedRequestPort;

	template <> const ::Uml::AssociationRole& Provideable::_type2ARole< Provideable::AR_referedbyRequiredRequestPort >() const { return meta_referedbyRequiredRequestPort; }
	template <> const ::Uml::AssociationRole& Provideable::_type2ARole< Provideable::AR_referedbyProvidedRequestPort >() const { return meta_referedbyProvidedRequestPort; }

	::Uml::Class ComponentFactory::meta;
	::Uml::AssociationRole ComponentFactory::meta_referedbyComponentFactoryInstance;
	::Uml::AssociationRole ComponentFactory::meta_dstManagesComponent;
	::Uml::AssociationRole ComponentFactory::meta_dstManagesComponent_rev;
	::Uml::CompositionChildRole ComponentFactory::meta_LookupKey_child;
	::Uml::CompositionChildRole ComponentFactory::meta_FactoryOperation_children;
	::Uml::CompositionChildRole ComponentFactory::meta_LookupOperation_children;

	template <> const ::Uml::AssociationRole& ComponentFactory::_type2ARole< ComponentFactory::AR_referedbyComponentFactoryInstance >() const { return meta_referedbyComponentFactoryInstance; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentFactory::_type2ACARole< ComponentFactory::AR_dstManagesComponent >() const { return make_pair(&meta_dstManagesComponent, &meta_dstManagesComponent_rev); }
	template <> const ::Uml::CompositionChildRole& ComponentFactory::_type2CCRole< ComponentFactory::CR_LookupKey_child >() const { return meta_LookupKey_child; }
	template <> const ::Uml::CompositionChildRole& ComponentFactory::_type2CCRole< ComponentFactory::CR_FactoryOperation_children >() const { return meta_FactoryOperation_children; }
	template <> const ::Uml::CompositionChildRole& ComponentFactory::_type2CCRole< ComponentFactory::CR_LookupOperation_children >() const { return meta_LookupOperation_children; }

	::Uml::Class ComponentRef::meta;
	::Uml::AssociationRole ComponentRef::meta_referedbySharedComponentReference;
	::Uml::AssociationRole ComponentRef::meta_srcDeploys;
	::Uml::AssociationRole ComponentRef::meta_srcDeploys_rev;
	::Uml::AssociationRole ComponentRef::meta_srcImplements;
	::Uml::AssociationRole ComponentRef::meta_srcImplements_rev;
	::Uml::AssociationRole ComponentRef::meta_dstComponentProperty;
	::Uml::AssociationRole ComponentRef::meta_dstComponentProperty_rev;
	::Uml::AssociationRole ComponentRef::meta_srcPackageInterface;
	::Uml::AssociationRole ComponentRef::meta_srcPackageInterface_rev;
	::Uml::AssociationRole ComponentRef::meta_dstComponentConfigProperty;
	::Uml::AssociationRole ComponentRef::meta_dstComponentConfigProperty_rev;
	::Uml::AssociationRole ComponentRef::meta_dstComponentInfoProperty;
	::Uml::AssociationRole ComponentRef::meta_dstComponentInfoProperty_rev;
	::Uml::AssociationRole ComponentRef::meta_ref;
	::Uml::CompositionParentRole ComponentRef::meta_ComponentAssembly_parent;
	::Uml::CompositionParentRole ComponentRef::meta_Path_parent;
	::Uml::CompositionParentRole ComponentRef::meta_ComponentImplementationContainer_parent;
	::Uml::CompositionParentRole ComponentRef::meta_ComponentContainer_parent;
	::Uml::CompositionParentRole ComponentRef::meta_PackageContainer_parent;
	::Uml::CompositionParentRole ComponentRef::meta_Package_parent;
	::Uml::CompositionParentRole ComponentRef::meta_File_parent;

	template <> const ::Uml::AssociationRole& ComponentRef::_type2ARole< ComponentRef::AR_referedbySharedComponentReference >() const { return meta_referedbySharedComponentReference; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentRef::_type2ACARole< ComponentRef::AR_srcDeploys >() const { return make_pair(&meta_srcDeploys, &meta_srcDeploys_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentRef::_type2ACARole< ComponentRef::AR_srcImplements >() const { return make_pair(&meta_srcImplements, &meta_srcImplements_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentRef::_type2ACARole< ComponentRef::AR_dstComponentProperty >() const { return make_pair(&meta_dstComponentProperty, &meta_dstComponentProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentRef::_type2ACARole< ComponentRef::AR_srcPackageInterface >() const { return make_pair(&meta_srcPackageInterface, &meta_srcPackageInterface_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentRef::_type2ACARole< ComponentRef::AR_dstComponentConfigProperty >() const { return make_pair(&meta_dstComponentConfigProperty, &meta_dstComponentConfigProperty_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentRef::_type2ACARole< ComponentRef::AR_dstComponentInfoProperty >() const { return make_pair(&meta_dstComponentInfoProperty, &meta_dstComponentInfoProperty_rev); }
	template <> const ::Uml::AssociationRole& ComponentRef::_type2ARole< ComponentRef::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& ComponentRef::_type2CPRole< ComponentRef::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentRef::_type2CPRole< ComponentRef::PR_Path_parent >() const { return meta_Path_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentRef::_type2CPRole< ComponentRef::PR_ComponentImplementationContainer_parent >() const { return meta_ComponentImplementationContainer_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentRef::_type2CPRole< ComponentRef::PR_ComponentContainer_parent >() const { return meta_ComponentContainer_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentRef::_type2CPRole< ComponentRef::PR_PackageContainer_parent >() const { return meta_PackageContainer_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentRef::_type2CPRole< ComponentRef::PR_Package_parent >() const { return meta_Package_parent; }
	template <> const ::Uml::CompositionParentRole& ComponentRef::_type2CPRole< ComponentRef::PR_File_parent >() const { return meta_File_parent; }

	::Uml::Class ManagesComponent::meta;
	::Uml::CompositionParentRole ManagesComponent::meta_File_parent;
	::Uml::CompositionParentRole ManagesComponent::meta_Package_parent;
	::Uml::AssociationRole ManagesComponent::meta_dstManagesComponent_end_;
	::Uml::AssociationRole ManagesComponent::meta_srcManagesComponent_end_;

	template <> const ::Uml::CompositionParentRole& ManagesComponent::_type2CPRole< ManagesComponent::PR_File_parent >() const { return meta_File_parent; }
	template <> const ::Uml::CompositionParentRole& ManagesComponent::_type2CPRole< ManagesComponent::PR_Package_parent >() const { return meta_Package_parent; }
	template <> const ::Uml::AssociationRole& ManagesComponent::_type2ARole< ManagesComponent::ACE_dstManagesComponent >() const { return meta_dstManagesComponent_end_; }
	template <> const ::Uml::AssociationRole& ManagesComponent::_type2ARole< ManagesComponent::ACE_srcManagesComponent >() const { return meta_srcManagesComponent_end_; }

	::Uml::Class ProvidedRequestPort::meta;
	::Uml::AssociationRole ProvidedRequestPort::meta_ref;
	::Uml::AssociationRole ProvidedRequestPort::meta_dstFacetDelegate;
	::Uml::AssociationRole ProvidedRequestPort::meta_dstFacetDelegate_rev;
	::Uml::AssociationRole ProvidedRequestPort::meta_srcFacetDelegate;
	::Uml::AssociationRole ProvidedRequestPort::meta_srcFacetDelegate_rev;
	::Uml::AssociationRole ProvidedRequestPort::meta_srcSupportsDelegate;
	::Uml::AssociationRole ProvidedRequestPort::meta_srcSupportsDelegate_rev;
	::Uml::CompositionParentRole ProvidedRequestPort::meta_ComponentAssembly_parent;

	template <> const ::Uml::AssociationRole& ProvidedRequestPort::_type2ARole< ProvidedRequestPort::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ProvidedRequestPort::_type2ACARole< ProvidedRequestPort::AR_dstFacetDelegate >() const { return make_pair(&meta_dstFacetDelegate, &meta_dstFacetDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ProvidedRequestPort::_type2ACARole< ProvidedRequestPort::AR_srcFacetDelegate >() const { return make_pair(&meta_srcFacetDelegate, &meta_srcFacetDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ProvidedRequestPort::_type2ACARole< ProvidedRequestPort::AR_srcSupportsDelegate >() const { return make_pair(&meta_srcSupportsDelegate, &meta_srcSupportsDelegate_rev); }
	template <> const ::Uml::CompositionParentRole& ProvidedRequestPort::_type2CPRole< ProvidedRequestPort::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class InEventPort::meta;
	::Uml::AssociationRole InEventPort::meta_srcdeliverTo;
	::Uml::AssociationRole InEventPort::meta_srcdeliverTo_rev;
	::Uml::AssociationRole InEventPort::meta_ref;
	::Uml::AssociationRole InEventPort::meta_dstEventSinkDelegate;
	::Uml::AssociationRole InEventPort::meta_dstEventSinkDelegate_rev;
	::Uml::AssociationRole InEventPort::meta_srcEventSinkDelegate;
	::Uml::AssociationRole InEventPort::meta_srcEventSinkDelegate_rev;
	::Uml::AssociationRole InEventPort::meta_srcemit;
	::Uml::AssociationRole InEventPort::meta_srcemit_rev;
	::Uml::CompositionParentRole InEventPort::meta_ComponentAssembly_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> InEventPort::_type2ACARole< InEventPort::AR_srcdeliverTo >() const { return make_pair(&meta_srcdeliverTo, &meta_srcdeliverTo_rev); }
	template <> const ::Uml::AssociationRole& InEventPort::_type2ARole< InEventPort::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> InEventPort::_type2ACARole< InEventPort::AR_dstEventSinkDelegate >() const { return make_pair(&meta_dstEventSinkDelegate, &meta_dstEventSinkDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> InEventPort::_type2ACARole< InEventPort::AR_srcEventSinkDelegate >() const { return make_pair(&meta_srcEventSinkDelegate, &meta_srcEventSinkDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> InEventPort::_type2ACARole< InEventPort::AR_srcemit >() const { return make_pair(&meta_srcemit, &meta_srcemit_rev); }
	template <> const ::Uml::CompositionParentRole& InEventPort::_type2CPRole< InEventPort::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class OutEventPort::meta;
	::Uml::Attribute OutEventPort::meta_out_event_port_type;
	::Uml::Attribute OutEventPort::meta_single_destination;
	::Uml::AssociationRole OutEventPort::meta_dstpublish;
	::Uml::AssociationRole OutEventPort::meta_dstpublish_rev;
	::Uml::AssociationRole OutEventPort::meta_dstemit;
	::Uml::AssociationRole OutEventPort::meta_dstemit_rev;
	::Uml::AssociationRole OutEventPort::meta_ref;
	::Uml::AssociationRole OutEventPort::meta_dstEventSourceDelegate;
	::Uml::AssociationRole OutEventPort::meta_dstEventSourceDelegate_rev;
	::Uml::AssociationRole OutEventPort::meta_srcEventSourceDelegate;
	::Uml::AssociationRole OutEventPort::meta_srcEventSourceDelegate_rev;
	::Uml::CompositionParentRole OutEventPort::meta_ComponentAssembly_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OutEventPort::_type2ACARole< OutEventPort::AR_dstpublish >() const { return make_pair(&meta_dstpublish, &meta_dstpublish_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OutEventPort::_type2ACARole< OutEventPort::AR_dstemit >() const { return make_pair(&meta_dstemit, &meta_dstemit_rev); }
	template <> const ::Uml::AssociationRole& OutEventPort::_type2ARole< OutEventPort::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OutEventPort::_type2ACARole< OutEventPort::AR_dstEventSourceDelegate >() const { return make_pair(&meta_dstEventSourceDelegate, &meta_dstEventSourceDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> OutEventPort::_type2ACARole< OutEventPort::AR_srcEventSourceDelegate >() const { return make_pair(&meta_srcEventSourceDelegate, &meta_srcEventSourceDelegate_rev); }
	template <> const ::Uml::CompositionParentRole& OutEventPort::_type2CPRole< OutEventPort::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class RequiredRequestPort::meta;
	::Uml::Attribute RequiredRequestPort::meta_multiple_connections;
	::Uml::AssociationRole RequiredRequestPort::meta_dstinvoke;
	::Uml::AssociationRole RequiredRequestPort::meta_dstinvoke_rev;
	::Uml::AssociationRole RequiredRequestPort::meta_ref;
	::Uml::AssociationRole RequiredRequestPort::meta_dstReceptacleDelegate;
	::Uml::AssociationRole RequiredRequestPort::meta_dstReceptacleDelegate_rev;
	::Uml::AssociationRole RequiredRequestPort::meta_srcReceptacleDelegate;
	::Uml::AssociationRole RequiredRequestPort::meta_srcReceptacleDelegate_rev;
	::Uml::CompositionParentRole RequiredRequestPort::meta_ComponentAssembly_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> RequiredRequestPort::_type2ACARole< RequiredRequestPort::AR_dstinvoke >() const { return make_pair(&meta_dstinvoke, &meta_dstinvoke_rev); }
	template <> const ::Uml::AssociationRole& RequiredRequestPort::_type2ARole< RequiredRequestPort::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> RequiredRequestPort::_type2ACARole< RequiredRequestPort::AR_dstReceptacleDelegate >() const { return make_pair(&meta_dstReceptacleDelegate, &meta_dstReceptacleDelegate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> RequiredRequestPort::_type2ACARole< RequiredRequestPort::AR_srcReceptacleDelegate >() const { return make_pair(&meta_srcReceptacleDelegate, &meta_srcReceptacleDelegate_rev); }
	template <> const ::Uml::CompositionParentRole& RequiredRequestPort::_type2CPRole< RequiredRequestPort::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class Component::meta;
	::Uml::Attribute Component::meta_UUID;
	::Uml::Attribute Component::meta_label;
	::Uml::AssociationRole Component::meta_referedbyCompRef;
	::Uml::AssociationRole Component::meta_dstAssemblyselectRequirement;
	::Uml::AssociationRole Component::meta_dstAssemblyselectRequirement_rev;
	::Uml::AssociationRole Component::meta_dstAssemblyConfigProperty;
	::Uml::AssociationRole Component::meta_dstAssemblyConfigProperty_rev;
	::Uml::AssociationRole Component::meta_referedbyComponentRef;
	::Uml::CompositionChildRole Component::meta_ReadonlyAttribute_children;
	::Uml::CompositionChildRole Component::meta_Port_children;
	::Uml::CompositionChildRole Component::meta_WorkerType_children;
	::Uml::CompositionParentRole Component::meta_ComponentAssembly_parent;

	template <> const ::Uml::AssociationRole& Component::_type2ARole< Component::AR_referedbyCompRef >() const { return meta_referedbyCompRef; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Component::_type2ACARole< Component::AR_dstAssemblyselectRequirement >() const { return make_pair(&meta_dstAssemblyselectRequirement, &meta_dstAssemblyselectRequirement_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Component::_type2ACARole< Component::AR_dstAssemblyConfigProperty >() const { return make_pair(&meta_dstAssemblyConfigProperty, &meta_dstAssemblyConfigProperty_rev); }
	template <> const ::Uml::AssociationRole& Component::_type2ARole< Component::AR_referedbyComponentRef >() const { return meta_referedbyComponentRef; }
	template <> const ::Uml::CompositionChildRole& Component::_type2CCRole< Component::CR_ReadonlyAttribute_children >() const { return meta_ReadonlyAttribute_children; }
	template <> const ::Uml::CompositionChildRole& Component::_type2CCRole< Component::CR_Port_children >() const { return meta_Port_children; }
	template <> const ::Uml::CompositionChildRole& Component::_type2CCRole< Component::CR_WorkerType_children >() const { return meta_WorkerType_children; }
	template <> const ::Uml::CompositionParentRole& Component::_type2CPRole< Component::PR_ComponentAssembly_parent >() const { return meta_ComponentAssembly_parent; }

	::Uml::Class OperationBase::meta;
	::Uml::AssociationRole OperationBase::meta_referedbyOperationRef;
	::Uml::CompositionChildRole OperationBase::meta_InParameter_children;
	::Uml::CompositionParentRole OperationBase::meta_BenchmarkAnalysis_parent;

	template <> const ::Uml::AssociationRole& OperationBase::_type2ARole< OperationBase::AR_referedbyOperationRef >() const { return meta_referedbyOperationRef; }
	template <> const ::Uml::CompositionChildRole& OperationBase::_type2CCRole< OperationBase::CR_InParameter_children >() const { return meta_InParameter_children; }
	template <> const ::Uml::CompositionParentRole& OperationBase::_type2CPRole< OperationBase::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class HasExceptions::meta;
	::Uml::CompositionChildRole HasExceptions::meta_ExceptionRef_children;

	template <> const ::Uml::CompositionChildRole& HasExceptions::_type2CCRole< HasExceptions::CR_ExceptionRef_children >() const { return meta_ExceptionRef_children; }

	::Uml::Class InParameter::meta;
	::Uml::AssociationRole InParameter::meta_ref;
	::Uml::CompositionParentRole InParameter::meta_OperationBase_parent;

	template <> const ::Uml::AssociationRole& InParameter::_type2ARole< InParameter::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& InParameter::_type2CPRole< InParameter::PR_OperationBase_parent >() const { return meta_OperationBase_parent; }

	::Uml::Class InoutParameter::meta;
	::Uml::AssociationRole InoutParameter::meta_ref;
	::Uml::CompositionParentRole InoutParameter::meta_TwowayOperation_parent;

	template <> const ::Uml::AssociationRole& InoutParameter::_type2ARole< InoutParameter::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& InoutParameter::_type2CPRole< InoutParameter::PR_TwowayOperation_parent >() const { return meta_TwowayOperation_parent; }

	::Uml::Class OutParameter::meta;
	::Uml::AssociationRole OutParameter::meta_ref;
	::Uml::CompositionParentRole OutParameter::meta_TwowayOperation_parent;

	template <> const ::Uml::AssociationRole& OutParameter::_type2ARole< OutParameter::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& OutParameter::_type2CPRole< OutParameter::PR_TwowayOperation_parent >() const { return meta_TwowayOperation_parent; }

	::Uml::Class ReturnType::meta;
	::Uml::AssociationRole ReturnType::meta_ref;
	::Uml::CompositionParentRole ReturnType::meta_TwowayOperation_parent;

	template <> const ::Uml::AssociationRole& ReturnType::_type2ARole< ReturnType::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& ReturnType::_type2CPRole< ReturnType::PR_TwowayOperation_parent >() const { return meta_TwowayOperation_parent; }

	::Uml::Class ParameterType::meta;
	::Uml::AssociationRole ParameterType::meta_ref;

	template <> const ::Uml::AssociationRole& ParameterType::_type2ARole< ParameterType::AR_ref >() const { return meta_ref; }

	::Uml::Class OnewayOperation::meta;
	::Uml::CompositionParentRole OnewayOperation::meta_HasOperations_parent;

	template <> const ::Uml::CompositionParentRole& OnewayOperation::_type2CPRole< OnewayOperation::PR_HasOperations_parent >() const { return meta_HasOperations_parent; }

	::Uml::Class LookupOperation::meta;
	::Uml::CompositionParentRole LookupOperation::meta_ComponentFactory_parent;

	template <> const ::Uml::CompositionParentRole& LookupOperation::_type2CPRole< LookupOperation::PR_ComponentFactory_parent >() const { return meta_ComponentFactory_parent; }

	::Uml::Class FactoryOperation::meta;
	::Uml::CompositionParentRole FactoryOperation::meta_ComponentFactory_parent;
	::Uml::CompositionParentRole FactoryOperation::meta_ObjectByValue_parent;

	template <> const ::Uml::CompositionParentRole& FactoryOperation::_type2CPRole< FactoryOperation::PR_ComponentFactory_parent >() const { return meta_ComponentFactory_parent; }
	template <> const ::Uml::CompositionParentRole& FactoryOperation::_type2CPRole< FactoryOperation::PR_ObjectByValue_parent >() const { return meta_ObjectByValue_parent; }

	::Uml::Class TwowayOperation::meta;
	::Uml::CompositionChildRole TwowayOperation::meta_OutParameter_children;
	::Uml::CompositionChildRole TwowayOperation::meta_InoutParameter_children;
	::Uml::CompositionChildRole TwowayOperation::meta_ReturnType_child;
	::Uml::CompositionParentRole TwowayOperation::meta_HasOperations_parent;

	template <> const ::Uml::CompositionChildRole& TwowayOperation::_type2CCRole< TwowayOperation::CR_OutParameter_children >() const { return meta_OutParameter_children; }
	template <> const ::Uml::CompositionChildRole& TwowayOperation::_type2CCRole< TwowayOperation::CR_InoutParameter_children >() const { return meta_InoutParameter_children; }
	template <> const ::Uml::CompositionChildRole& TwowayOperation::_type2CCRole< TwowayOperation::CR_ReturnType_child >() const { return meta_ReturnType_child; }
	template <> const ::Uml::CompositionParentRole& TwowayOperation::_type2CPRole< TwowayOperation::PR_HasOperations_parent >() const { return meta_HasOperations_parent; }

	::Uml::Class Object::meta;
	::Uml::Attribute Object::meta_local;
	::Uml::Attribute Object::meta_abstract;
	::Uml::AssociationRole Object::meta_referedbySupports;

	template <> const ::Uml::AssociationRole& Object::_type2ARole< Object::AR_referedbySupports >() const { return meta_referedbySupports; }

	::Uml::Class Inherits::meta;
	::Uml::AssociationRole Inherits::meta_ref;
	::Uml::CompositionParentRole Inherits::meta_Inheritable_parent;

	template <> const ::Uml::AssociationRole& Inherits::_type2ARole< Inherits::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Inherits::_type2CPRole< Inherits::PR_Inheritable_parent >() const { return meta_Inheritable_parent; }

	::Uml::Class Event::meta;
	::Uml::AssociationRole Event::meta_referedbyEventRef;
	::Uml::AssociationRole Event::meta_referedbyInEventPort;
	::Uml::AssociationRole Event::meta_referedbyOutEventPort;
	::Uml::CompositionParentRole Event::meta_BenchmarkAnalysis_parent;

	template <> const ::Uml::AssociationRole& Event::_type2ARole< Event::AR_referedbyEventRef >() const { return meta_referedbyEventRef; }
	template <> const ::Uml::AssociationRole& Event::_type2ARole< Event::AR_referedbyInEventPort >() const { return meta_referedbyInEventPort; }
	template <> const ::Uml::AssociationRole& Event::_type2ARole< Event::AR_referedbyOutEventPort >() const { return meta_referedbyOutEventPort; }
	template <> const ::Uml::CompositionParentRole& Event::_type2CPRole< Event::PR_BenchmarkAnalysis_parent >() const { return meta_BenchmarkAnalysis_parent; }

	::Uml::Class ValueObject::meta;
	::Uml::AssociationRole ValueObject::meta_referedbyLookupKey;

	template <> const ::Uml::AssociationRole& ValueObject::_type2ARole< ValueObject::AR_referedbyLookupKey >() const { return meta_referedbyLookupKey; }

	::Uml::Class HasOperations::meta;
	::Uml::CompositionChildRole HasOperations::meta_TwowayOperation_children;
	::Uml::CompositionChildRole HasOperations::meta_OnewayOperation_children;
	::Uml::CompositionChildRole HasOperations::meta_Exception_children;
	::Uml::CompositionChildRole HasOperations::meta_Constant_children;
	::Uml::CompositionChildRole HasOperations::meta_NoInheritable_children;

	template <> const ::Uml::CompositionChildRole& HasOperations::_type2CCRole< HasOperations::CR_TwowayOperation_children >() const { return meta_TwowayOperation_children; }
	template <> const ::Uml::CompositionChildRole& HasOperations::_type2CCRole< HasOperations::CR_OnewayOperation_children >() const { return meta_OnewayOperation_children; }
	template <> const ::Uml::CompositionChildRole& HasOperations::_type2CCRole< HasOperations::CR_Exception_children >() const { return meta_Exception_children; }
	template <> const ::Uml::CompositionChildRole& HasOperations::_type2CCRole< HasOperations::CR_Constant_children >() const { return meta_Constant_children; }
	template <> const ::Uml::CompositionChildRole& HasOperations::_type2CCRole< HasOperations::CR_NoInheritable_children >() const { return meta_NoInheritable_children; }

	::Uml::Class SupportsInterfaces::meta;
	::Uml::CompositionChildRole SupportsInterfaces::meta_Supports_children;

	template <> const ::Uml::CompositionChildRole& SupportsInterfaces::_type2CCRole< SupportsInterfaces::CR_Supports_children >() const { return meta_Supports_children; }

	::Uml::Class Supports::meta;
	::Uml::AssociationRole Supports::meta_dstSupportsDelegate;
	::Uml::AssociationRole Supports::meta_dstSupportsDelegate_rev;
	::Uml::AssociationRole Supports::meta_ref;
	::Uml::CompositionParentRole Supports::meta_SupportsInterfaces_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Supports::_type2ACARole< Supports::AR_dstSupportsDelegate >() const { return make_pair(&meta_dstSupportsDelegate, &meta_dstSupportsDelegate_rev); }
	template <> const ::Uml::AssociationRole& Supports::_type2ARole< Supports::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Supports::_type2CPRole< Supports::PR_SupportsInterfaces_parent >() const { return meta_SupportsInterfaces_parent; }

	::Uml::Class Attribute::meta;
	::Uml::CompositionChildRole Attribute::meta_SetException_children;

	template <> const ::Uml::CompositionChildRole& Attribute::_type2CCRole< Attribute::CR_SetException_children >() const { return meta_SetException_children; }

	::Uml::Class LookupKey::meta;
	::Uml::AssociationRole LookupKey::meta_ref;
	::Uml::CompositionParentRole LookupKey::meta_ComponentFactory_parent;

	template <> const ::Uml::AssociationRole& LookupKey::_type2ARole< LookupKey::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& LookupKey::_type2CPRole< LookupKey::PR_ComponentFactory_parent >() const { return meta_ComponentFactory_parent; }

	::Uml::Class SetException::meta;
	::Uml::AssociationRole SetException::meta_ref;
	::Uml::CompositionParentRole SetException::meta_Attribute_parent;

	template <> const ::Uml::AssociationRole& SetException::_type2ARole< SetException::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& SetException::_type2CPRole< SetException::PR_Attribute_parent >() const { return meta_Attribute_parent; }

	::Uml::Class ObjectByValue::meta;
	::Uml::Attribute ObjectByValue::meta_abstract;
	::Uml::CompositionChildRole ObjectByValue::meta_PrivateFlag_children;
	::Uml::CompositionChildRole ObjectByValue::meta_FactoryOperation_children;
	::Uml::CompositionChildRole ObjectByValue::meta_MakeMemberPrivate_children;
	::Uml::CompositionChildRole ObjectByValue::meta_Member_children;

	template <> const ::Uml::CompositionChildRole& ObjectByValue::_type2CCRole< ObjectByValue::CR_PrivateFlag_children >() const { return meta_PrivateFlag_children; }
	template <> const ::Uml::CompositionChildRole& ObjectByValue::_type2CCRole< ObjectByValue::CR_FactoryOperation_children >() const { return meta_FactoryOperation_children; }
	template <> const ::Uml::CompositionChildRole& ObjectByValue::_type2CCRole< ObjectByValue::CR_MakeMemberPrivate_children >() const { return meta_MakeMemberPrivate_children; }
	template <> const ::Uml::CompositionChildRole& ObjectByValue::_type2CCRole< ObjectByValue::CR_Member_children >() const { return meta_Member_children; }

	::Uml::Class GetException::meta;
	::Uml::AssociationRole GetException::meta_ref;
	::Uml::CompositionParentRole GetException::meta_ReadonlyAttribute_parent;

	template <> const ::Uml::AssociationRole& GetException::_type2ARole< GetException::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& GetException::_type2CPRole< GetException::PR_ReadonlyAttribute_parent >() const { return meta_ReadonlyAttribute_parent; }

	::Uml::Class PrivateFlag::meta;
	::Uml::AssociationRole PrivateFlag::meta_srcMakeMemberPrivate;
	::Uml::AssociationRole PrivateFlag::meta_srcMakeMemberPrivate_rev;
	::Uml::CompositionParentRole PrivateFlag::meta_ObjectByValue_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> PrivateFlag::_type2ACARole< PrivateFlag::AR_srcMakeMemberPrivate >() const { return make_pair(&meta_srcMakeMemberPrivate, &meta_srcMakeMemberPrivate_rev); }
	template <> const ::Uml::CompositionParentRole& PrivateFlag::_type2CPRole< PrivateFlag::PR_ObjectByValue_parent >() const { return meta_ObjectByValue_parent; }

	::Uml::Class MakeMemberPrivate::meta;
	::Uml::CompositionParentRole MakeMemberPrivate::meta_ObjectByValue_parent;
	::Uml::AssociationRole MakeMemberPrivate::meta_dstMakeMemberPrivate_end_;
	::Uml::AssociationRole MakeMemberPrivate::meta_srcMakeMemberPrivate_end_;

	template <> const ::Uml::CompositionParentRole& MakeMemberPrivate::_type2CPRole< MakeMemberPrivate::PR_ObjectByValue_parent >() const { return meta_ObjectByValue_parent; }
	template <> const ::Uml::AssociationRole& MakeMemberPrivate::_type2ARole< MakeMemberPrivate::ACE_dstMakeMemberPrivate >() const { return meta_dstMakeMemberPrivate_end_; }
	template <> const ::Uml::AssociationRole& MakeMemberPrivate::_type2ARole< MakeMemberPrivate::ACE_srcMakeMemberPrivate >() const { return meta_srcMakeMemberPrivate_end_; }

	::Uml::Class AttributeMember::meta;
	::Uml::AssociationRole AttributeMember::meta_ref;
	::Uml::CompositionParentRole AttributeMember::meta_ReadonlyAttribute_parent;

	template <> const ::Uml::AssociationRole& AttributeMember::_type2ARole< AttributeMember::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& AttributeMember::_type2CPRole< AttributeMember::PR_ReadonlyAttribute_parent >() const { return meta_ReadonlyAttribute_parent; }

	::Uml::Class Inheritable::meta;
	::Uml::AssociationRole Inheritable::meta_referedbyInherits;
	::Uml::CompositionChildRole Inheritable::meta_ReadonlyAttribute_children;
	::Uml::CompositionChildRole Inheritable::meta_Inherits_children;

	template <> const ::Uml::AssociationRole& Inheritable::_type2ARole< Inheritable::AR_referedbyInherits >() const { return meta_referedbyInherits; }
	template <> const ::Uml::CompositionChildRole& Inheritable::_type2CCRole< Inheritable::CR_ReadonlyAttribute_children >() const { return meta_ReadonlyAttribute_children; }
	template <> const ::Uml::CompositionChildRole& Inheritable::_type2CCRole< Inheritable::CR_Inherits_children >() const { return meta_Inherits_children; }

	::Uml::Class ReadonlyAttribute::meta;
	::Uml::AssociationRole ReadonlyAttribute::meta_srcAttributeDelegate;
	::Uml::AssociationRole ReadonlyAttribute::meta_srcAttributeDelegate_rev;
	::Uml::AssociationRole ReadonlyAttribute::meta_referedbyAttributeMapping;
	::Uml::AssociationRole ReadonlyAttribute::meta_dstAttributeValue;
	::Uml::AssociationRole ReadonlyAttribute::meta_dstAttributeValue_rev;
	::Uml::CompositionChildRole ReadonlyAttribute::meta_AttributeMember_child;
	::Uml::CompositionChildRole ReadonlyAttribute::meta_GetException_children;
	::Uml::CompositionParentRole ReadonlyAttribute::meta_Component_parent;
	::Uml::CompositionParentRole ReadonlyAttribute::meta_Inheritable_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ReadonlyAttribute::_type2ACARole< ReadonlyAttribute::AR_srcAttributeDelegate >() const { return make_pair(&meta_srcAttributeDelegate, &meta_srcAttributeDelegate_rev); }
	template <> const ::Uml::AssociationRole& ReadonlyAttribute::_type2ARole< ReadonlyAttribute::AR_referedbyAttributeMapping >() const { return meta_referedbyAttributeMapping; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ReadonlyAttribute::_type2ACARole< ReadonlyAttribute::AR_dstAttributeValue >() const { return make_pair(&meta_dstAttributeValue, &meta_dstAttributeValue_rev); }
	template <> const ::Uml::CompositionChildRole& ReadonlyAttribute::_type2CCRole< ReadonlyAttribute::CR_AttributeMember_child >() const { return meta_AttributeMember_child; }
	template <> const ::Uml::CompositionChildRole& ReadonlyAttribute::_type2CCRole< ReadonlyAttribute::CR_GetException_children >() const { return meta_GetException_children; }
	template <> const ::Uml::CompositionParentRole& ReadonlyAttribute::_type2CPRole< ReadonlyAttribute::PR_Component_parent >() const { return meta_Component_parent; }
	template <> const ::Uml::CompositionParentRole& ReadonlyAttribute::_type2CPRole< ReadonlyAttribute::PR_Inheritable_parent >() const { return meta_Inheritable_parent; }

	::Uml::Class EnumValue::meta;
	::Uml::CompositionParentRole EnumValue::meta_Enum_parent;

	template <> const ::Uml::CompositionParentRole& EnumValue::_type2CPRole< EnumValue::PR_Enum_parent >() const { return meta_Enum_parent; }

	::Uml::Class Aggregate::meta;
	::Uml::CompositionChildRole Aggregate::meta_Member_children;

	template <> const ::Uml::CompositionChildRole& Aggregate::_type2CCRole< Aggregate::CR_Member_children >() const { return meta_Member_children; }

	::Uml::Class SwitchedAggregate::meta;
	::Uml::CompositionChildRole SwitchedAggregate::meta_Label_children;
	::Uml::CompositionChildRole SwitchedAggregate::meta_LabelConnection_children;
	::Uml::CompositionChildRole SwitchedAggregate::meta_Member_children;
	::Uml::CompositionChildRole SwitchedAggregate::meta_Discriminator_child;

	template <> const ::Uml::CompositionChildRole& SwitchedAggregate::_type2CCRole< SwitchedAggregate::CR_Label_children >() const { return meta_Label_children; }
	template <> const ::Uml::CompositionChildRole& SwitchedAggregate::_type2CCRole< SwitchedAggregate::CR_LabelConnection_children >() const { return meta_LabelConnection_children; }
	template <> const ::Uml::CompositionChildRole& SwitchedAggregate::_type2CCRole< SwitchedAggregate::CR_Member_children >() const { return meta_Member_children; }
	template <> const ::Uml::CompositionChildRole& SwitchedAggregate::_type2CCRole< SwitchedAggregate::CR_Discriminator_child >() const { return meta_Discriminator_child; }

	::Uml::Class Label::meta;
	::Uml::AssociationRole Label::meta_srcLabelConnection;
	::Uml::AssociationRole Label::meta_srcLabelConnection_rev;
	::Uml::CompositionParentRole Label::meta_SwitchedAggregate_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Label::_type2ACARole< Label::AR_srcLabelConnection >() const { return make_pair(&meta_srcLabelConnection, &meta_srcLabelConnection_rev); }
	template <> const ::Uml::CompositionParentRole& Label::_type2CPRole< Label::PR_SwitchedAggregate_parent >() const { return meta_SwitchedAggregate_parent; }

	::Uml::Class LabelConnection::meta;
	::Uml::CompositionParentRole LabelConnection::meta_SwitchedAggregate_parent;
	::Uml::AssociationRole LabelConnection::meta_dstLabelConnection_end_;
	::Uml::AssociationRole LabelConnection::meta_srcLabelConnection_end_;

	template <> const ::Uml::CompositionParentRole& LabelConnection::_type2CPRole< LabelConnection::PR_SwitchedAggregate_parent >() const { return meta_SwitchedAggregate_parent; }
	template <> const ::Uml::AssociationRole& LabelConnection::_type2ARole< LabelConnection::ACE_dstLabelConnection >() const { return meta_dstLabelConnection_end_; }
	template <> const ::Uml::AssociationRole& LabelConnection::_type2ARole< LabelConnection::ACE_srcLabelConnection >() const { return meta_srcLabelConnection_end_; }

	::Uml::Class MemberType::meta;
	::Uml::AssociationRole MemberType::meta_referedbyDataType;
	::Uml::AssociationRole MemberType::meta_referedbyInParameter;
	::Uml::AssociationRole MemberType::meta_referedbyInoutParameter;
	::Uml::AssociationRole MemberType::meta_referedbyOutParameter;
	::Uml::AssociationRole MemberType::meta_referedbyReturnType;
	::Uml::AssociationRole MemberType::meta_referedbyParameterType;
	::Uml::AssociationRole MemberType::meta_referedbyAttributeMember;
	::Uml::AssociationRole MemberType::meta_referedbyAlias;
	::Uml::AssociationRole MemberType::meta_referedbyBoxed;
	::Uml::AssociationRole MemberType::meta_referedbyCollection;
	::Uml::AssociationRole MemberType::meta_referedbyMember;

	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyDataType >() const { return meta_referedbyDataType; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyInParameter >() const { return meta_referedbyInParameter; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyInoutParameter >() const { return meta_referedbyInoutParameter; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyOutParameter >() const { return meta_referedbyOutParameter; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyReturnType >() const { return meta_referedbyReturnType; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyParameterType >() const { return meta_referedbyParameterType; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyAttributeMember >() const { return meta_referedbyAttributeMember; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyAlias >() const { return meta_referedbyAlias; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyBoxed >() const { return meta_referedbyBoxed; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyCollection >() const { return meta_referedbyCollection; }
	template <> const ::Uml::AssociationRole& MemberType::_type2ARole< MemberType::AR_referedbyMember >() const { return meta_referedbyMember; }

	::Uml::Class Discriminator::meta;
	::Uml::AssociationRole Discriminator::meta_ref;
	::Uml::CompositionParentRole Discriminator::meta_SwitchedAggregate_parent;

	template <> const ::Uml::AssociationRole& Discriminator::_type2ARole< Discriminator::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Discriminator::_type2CPRole< Discriminator::PR_SwitchedAggregate_parent >() const { return meta_SwitchedAggregate_parent; }

	::Uml::Class Alias::meta;
	::Uml::AssociationRole Alias::meta_ref;

	template <> const ::Uml::AssociationRole& Alias::_type2ARole< Alias::AR_ref >() const { return meta_ref; }

	::Uml::Class Boxed::meta;
	::Uml::AssociationRole Boxed::meta_ref;

	template <> const ::Uml::AssociationRole& Boxed::_type2ARole< Boxed::AR_ref >() const { return meta_ref; }

	::Uml::Class NoInheritable::meta;
	::Uml::CompositionParentRole NoInheritable::meta_HasOperations_parent;

	template <> const ::Uml::CompositionParentRole& NoInheritable::_type2CPRole< NoInheritable::PR_HasOperations_parent >() const { return meta_HasOperations_parent; }

	::Uml::Class Collection::meta;
	::Uml::Attribute Collection::meta_bound;
	::Uml::AssociationRole Collection::meta_ref;
	::Uml::CompositionParentRole Collection::meta_PredefinedTypes_parent;

	template <> const ::Uml::AssociationRole& Collection::_type2ARole< Collection::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Collection::_type2CPRole< Collection::PR_PredefinedTypes_parent >() const { return meta_PredefinedTypes_parent; }

	::Uml::Class Enum::meta;
	::Uml::CompositionChildRole Enum::meta_EnumValue_children;

	template <> const ::Uml::CompositionChildRole& Enum::_type2CCRole< Enum::CR_EnumValue_children >() const { return meta_EnumValue_children; }

	::Uml::Class Member::meta;
	::Uml::AssociationRole Member::meta_dstMakeMemberPrivate;
	::Uml::AssociationRole Member::meta_dstMakeMemberPrivate_rev;
	::Uml::AssociationRole Member::meta_dstLabelConnection;
	::Uml::AssociationRole Member::meta_dstLabelConnection_rev;
	::Uml::AssociationRole Member::meta_ref;
	::Uml::CompositionParentRole Member::meta_ObjectByValue_parent;
	::Uml::CompositionParentRole Member::meta_Aggregate_parent;
	::Uml::CompositionParentRole Member::meta_SwitchedAggregate_parent;
	::Uml::CompositionParentRole Member::meta_Exception_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Member::_type2ACARole< Member::AR_dstMakeMemberPrivate >() const { return make_pair(&meta_dstMakeMemberPrivate, &meta_dstMakeMemberPrivate_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Member::_type2ACARole< Member::AR_dstLabelConnection >() const { return make_pair(&meta_dstLabelConnection, &meta_dstLabelConnection_rev); }
	template <> const ::Uml::AssociationRole& Member::_type2ARole< Member::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Member::_type2CPRole< Member::PR_ObjectByValue_parent >() const { return meta_ObjectByValue_parent; }
	template <> const ::Uml::CompositionParentRole& Member::_type2CPRole< Member::PR_Aggregate_parent >() const { return meta_Aggregate_parent; }
	template <> const ::Uml::CompositionParentRole& Member::_type2CPRole< Member::PR_SwitchedAggregate_parent >() const { return meta_SwitchedAggregate_parent; }
	template <> const ::Uml::CompositionParentRole& Member::_type2CPRole< Member::PR_Exception_parent >() const { return meta_Exception_parent; }

	::Uml::Class NamedType::meta;
	::Uml::CompositionParentRole NamedType::meta_File_parent;
	::Uml::CompositionParentRole NamedType::meta_Package_parent;

	template <> const ::Uml::CompositionParentRole& NamedType::_type2CPRole< NamedType::PR_File_parent >() const { return meta_File_parent; }
	template <> const ::Uml::CompositionParentRole& NamedType::_type2CPRole< NamedType::PR_Package_parent >() const { return meta_Package_parent; }

	::Uml::Class PredefinedTypes::meta;
	::Uml::Attribute PredefinedTypes::meta_name;
	::Uml::CompositionChildRole PredefinedTypes::meta_Collection_children;
	::Uml::CompositionChildRole PredefinedTypes::meta_PredefinedType_children;
	::Uml::CompositionParentRole PredefinedTypes::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& PredefinedTypes::_type2CCRole< PredefinedTypes::CR_Collection_children >() const { return meta_Collection_children; }
	template <> const ::Uml::CompositionChildRole& PredefinedTypes::_type2CCRole< PredefinedTypes::CR_PredefinedType_children >() const { return meta_PredefinedType_children; }
	template <> const ::Uml::CompositionParentRole& PredefinedTypes::_type2CPRole< PredefinedTypes::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class Byte::meta;

	::Uml::Class Boolean::meta;

	::Uml::Class ShortInteger::meta;

	::Uml::Class LongInteger::meta;

	::Uml::Class RealNumber::meta;

	::Uml::Class String::meta;

	::Uml::Class GenericObject::meta;

	::Uml::Class GenericValueObject::meta;

	::Uml::Class GenericValue::meta;

	::Uml::Class TypeEncoding::meta;

	::Uml::Class TypeKind::meta;

	::Uml::Class PredefinedType::meta;
	::Uml::AssociationRole PredefinedType::meta_referedbyVariable;
	::Uml::CompositionParentRole PredefinedType::meta_PredefinedTypes_parent;

	template <> const ::Uml::AssociationRole& PredefinedType::_type2ARole< PredefinedType::AR_referedbyVariable >() const { return meta_referedbyVariable; }
	template <> const ::Uml::CompositionParentRole& PredefinedType::_type2CPRole< PredefinedType::PR_PredefinedTypes_parent >() const { return meta_PredefinedTypes_parent; }

	::Uml::Class Package::meta;
	::Uml::CompositionChildRole Package::meta_ComponentRef_children;
	::Uml::CompositionChildRole Package::meta_NamedType_children;
	::Uml::CompositionChildRole Package::meta_ManagesComponent_children;
	::Uml::CompositionChildRole Package::meta_Package_children;
	::Uml::CompositionChildRole Package::meta_Exception_children;
	::Uml::CompositionChildRole Package::meta_Constant_children;
	::Uml::CompositionParentRole Package::meta_Package_parent;
	::Uml::CompositionParentRole Package::meta_File_parent;

	template <> const ::Uml::CompositionChildRole& Package::_type2CCRole< Package::CR_ComponentRef_children >() const { return meta_ComponentRef_children; }
	template <> const ::Uml::CompositionChildRole& Package::_type2CCRole< Package::CR_NamedType_children >() const { return meta_NamedType_children; }
	template <> const ::Uml::CompositionChildRole& Package::_type2CCRole< Package::CR_ManagesComponent_children >() const { return meta_ManagesComponent_children; }
	template <> const ::Uml::CompositionChildRole& Package::_type2CCRole< Package::CR_Package_children >() const { return meta_Package_children; }
	template <> const ::Uml::CompositionChildRole& Package::_type2CCRole< Package::CR_Exception_children >() const { return meta_Exception_children; }
	template <> const ::Uml::CompositionChildRole& Package::_type2CCRole< Package::CR_Constant_children >() const { return meta_Constant_children; }
	template <> const ::Uml::CompositionParentRole& Package::_type2CPRole< Package::PR_Package_parent >() const { return meta_Package_parent; }
	template <> const ::Uml::CompositionParentRole& Package::_type2CPRole< Package::PR_File_parent >() const { return meta_File_parent; }

	::Uml::Class File::meta;
	::Uml::Attribute File::meta_path;
	::Uml::AssociationRole File::meta_referedbyFileRef;
	::Uml::CompositionChildRole File::meta_ManagesComponent_children;
	::Uml::CompositionChildRole File::meta_ComponentRef_children;
	::Uml::CompositionChildRole File::meta_Package_children;
	::Uml::CompositionChildRole File::meta_Exception_children;
	::Uml::CompositionChildRole File::meta_FileRef_children;
	::Uml::CompositionChildRole File::meta_Constant_children;
	::Uml::CompositionChildRole File::meta_NamedType_children;
	::Uml::CompositionParentRole File::meta_InterfaceDefinitions_parent;

	template <> const ::Uml::AssociationRole& File::_type2ARole< File::AR_referedbyFileRef >() const { return meta_referedbyFileRef; }
	template <> const ::Uml::CompositionChildRole& File::_type2CCRole< File::CR_ManagesComponent_children >() const { return meta_ManagesComponent_children; }
	template <> const ::Uml::CompositionChildRole& File::_type2CCRole< File::CR_ComponentRef_children >() const { return meta_ComponentRef_children; }
	template <> const ::Uml::CompositionChildRole& File::_type2CCRole< File::CR_Package_children >() const { return meta_Package_children; }
	template <> const ::Uml::CompositionChildRole& File::_type2CCRole< File::CR_Exception_children >() const { return meta_Exception_children; }
	template <> const ::Uml::CompositionChildRole& File::_type2CCRole< File::CR_FileRef_children >() const { return meta_FileRef_children; }
	template <> const ::Uml::CompositionChildRole& File::_type2CCRole< File::CR_Constant_children >() const { return meta_Constant_children; }
	template <> const ::Uml::CompositionChildRole& File::_type2CCRole< File::CR_NamedType_children >() const { return meta_NamedType_children; }
	template <> const ::Uml::CompositionParentRole& File::_type2CPRole< File::PR_InterfaceDefinitions_parent >() const { return meta_InterfaceDefinitions_parent; }

	::Uml::Class Exception::meta;
	::Uml::AssociationRole Exception::meta_referedbySetException;
	::Uml::AssociationRole Exception::meta_referedbyGetException;
	::Uml::AssociationRole Exception::meta_referedbyExceptionRef;
	::Uml::CompositionChildRole Exception::meta_Member_children;
	::Uml::CompositionParentRole Exception::meta_HasOperations_parent;
	::Uml::CompositionParentRole Exception::meta_Package_parent;
	::Uml::CompositionParentRole Exception::meta_File_parent;

	template <> const ::Uml::AssociationRole& Exception::_type2ARole< Exception::AR_referedbySetException >() const { return meta_referedbySetException; }
	template <> const ::Uml::AssociationRole& Exception::_type2ARole< Exception::AR_referedbyGetException >() const { return meta_referedbyGetException; }
	template <> const ::Uml::AssociationRole& Exception::_type2ARole< Exception::AR_referedbyExceptionRef >() const { return meta_referedbyExceptionRef; }
	template <> const ::Uml::CompositionChildRole& Exception::_type2CCRole< Exception::CR_Member_children >() const { return meta_Member_children; }
	template <> const ::Uml::CompositionParentRole& Exception::_type2CPRole< Exception::PR_HasOperations_parent >() const { return meta_HasOperations_parent; }
	template <> const ::Uml::CompositionParentRole& Exception::_type2CPRole< Exception::PR_Package_parent >() const { return meta_Package_parent; }
	template <> const ::Uml::CompositionParentRole& Exception::_type2CPRole< Exception::PR_File_parent >() const { return meta_File_parent; }

	::Uml::Class ExceptionRef::meta;
	::Uml::AssociationRole ExceptionRef::meta_ref;
	::Uml::CompositionParentRole ExceptionRef::meta_HasExceptions_parent;

	template <> const ::Uml::AssociationRole& ExceptionRef::_type2ARole< ExceptionRef::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& ExceptionRef::_type2CPRole< ExceptionRef::PR_HasExceptions_parent >() const { return meta_HasExceptions_parent; }

	::Uml::Class InterfaceDefinitions::meta;
	::Uml::Attribute InterfaceDefinitions::meta_name;
	::Uml::CompositionChildRole InterfaceDefinitions::meta_File_children;
	::Uml::CompositionParentRole InterfaceDefinitions::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& InterfaceDefinitions::_type2CCRole< InterfaceDefinitions::CR_File_children >() const { return meta_File_children; }
	template <> const ::Uml::CompositionParentRole& InterfaceDefinitions::_type2CPRole< InterfaceDefinitions::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class ConstantType::meta;
	::Uml::AssociationRole ConstantType::meta_referedbyDiscriminator;
	::Uml::AssociationRole ConstantType::meta_referedbyConstant;

	template <> const ::Uml::AssociationRole& ConstantType::_type2ARole< ConstantType::AR_referedbyDiscriminator >() const { return meta_referedbyDiscriminator; }
	template <> const ::Uml::AssociationRole& ConstantType::_type2ARole< ConstantType::AR_referedbyConstant >() const { return meta_referedbyConstant; }

	::Uml::Class Constant::meta;
	::Uml::Attribute Constant::meta_value;
	::Uml::AssociationRole Constant::meta_ref;
	::Uml::CompositionParentRole Constant::meta_HasOperations_parent;
	::Uml::CompositionParentRole Constant::meta_Package_parent;
	::Uml::CompositionParentRole Constant::meta_File_parent;

	template <> const ::Uml::AssociationRole& Constant::_type2ARole< Constant::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Constant::_type2CPRole< Constant::PR_HasOperations_parent >() const { return meta_HasOperations_parent; }
	template <> const ::Uml::CompositionParentRole& Constant::_type2CPRole< Constant::PR_Package_parent >() const { return meta_Package_parent; }
	template <> const ::Uml::CompositionParentRole& Constant::_type2CPRole< Constant::PR_File_parent >() const { return meta_File_parent; }

	::Uml::Class FileRef::meta;
	::Uml::AssociationRole FileRef::meta_ref;
	::Uml::CompositionParentRole FileRef::meta_File_parent;
	::Uml::CompositionParentRole FileRef::meta_StubProject_parent;
	::Uml::CompositionParentRole FileRef::meta_ServantProject_parent;

	template <> const ::Uml::AssociationRole& FileRef::_type2ARole< FileRef::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& FileRef::_type2CPRole< FileRef::PR_File_parent >() const { return meta_File_parent; }
	template <> const ::Uml::CompositionParentRole& FileRef::_type2CPRole< FileRef::PR_StubProject_parent >() const { return meta_StubProject_parent; }
	template <> const ::Uml::CompositionParentRole& FileRef::_type2CPRole< FileRef::PR_ServantProject_parent >() const { return meta_ServantProject_parent; }

	::Uml::Class ComponentBuild::meta;
	::Uml::Attribute ComponentBuild::meta_name;
	::Uml::CompositionChildRole ComponentBuild::meta_MPC_children;
	::Uml::CompositionParentRole ComponentBuild::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ComponentBuild::_type2CCRole< ComponentBuild::CR_MPC_children >() const { return meta_MPC_children; }
	template <> const ::Uml::CompositionParentRole& ComponentBuild::_type2CPRole< ComponentBuild::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class Project::meta;
	::Uml::AssociationRole Project::meta_setWorkspace;
	::Uml::CompositionChildRole Project::meta_ExtResourceConn_children;
	::Uml::CompositionChildRole Project::meta_ExternalResources_children;
	::Uml::CompositionChildRole Project::meta_ComponentLib_children;
	::Uml::CompositionChildRole Project::meta_ImplementationArtifact_children;
	::Uml::CompositionParentRole Project::meta_MPC_parent;

	template <> const ::Uml::AssociationRole& Project::_type2ARole< Project::AR_setWorkspace >() const { return meta_setWorkspace; }
	template <> const ::Uml::CompositionChildRole& Project::_type2CCRole< Project::CR_ExtResourceConn_children >() const { return meta_ExtResourceConn_children; }
	template <> const ::Uml::CompositionChildRole& Project::_type2CCRole< Project::CR_ExternalResources_children >() const { return meta_ExternalResources_children; }
	template <> const ::Uml::CompositionChildRole& Project::_type2CCRole< Project::CR_ComponentLib_children >() const { return meta_ComponentLib_children; }
	template <> const ::Uml::CompositionChildRole& Project::_type2CCRole< Project::CR_ImplementationArtifact_children >() const { return meta_ImplementationArtifact_children; }
	template <> const ::Uml::CompositionParentRole& Project::_type2CPRole< Project::PR_MPC_parent >() const { return meta_MPC_parent; }

	::Uml::Class ExternalResources::meta;
	::Uml::AssociationRole ExternalResources::meta_ref;
	::Uml::AssociationRole ExternalResources::meta_srcExtResourceConn;
	::Uml::AssociationRole ExternalResources::meta_srcExtResourceConn_rev;
	::Uml::CompositionParentRole ExternalResources::meta_Project_parent;

	template <> const ::Uml::AssociationRole& ExternalResources::_type2ARole< ExternalResources::AR_ref >() const { return meta_ref; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ExternalResources::_type2ACARole< ExternalResources::AR_srcExtResourceConn >() const { return make_pair(&meta_srcExtResourceConn, &meta_srcExtResourceConn_rev); }
	template <> const ::Uml::CompositionParentRole& ExternalResources::_type2CPRole< ExternalResources::PR_Project_parent >() const { return meta_Project_parent; }

	::Uml::Class ExtResourceConn::meta;
	::Uml::CompositionParentRole ExtResourceConn::meta_Project_parent;
	::Uml::AssociationRole ExtResourceConn::meta_dstExtResourceConn_end_;
	::Uml::AssociationRole ExtResourceConn::meta_srcExtResourceConn_end_;

	template <> const ::Uml::CompositionParentRole& ExtResourceConn::_type2CPRole< ExtResourceConn::PR_Project_parent >() const { return meta_Project_parent; }
	template <> const ::Uml::AssociationRole& ExtResourceConn::_type2ARole< ExtResourceConn::ACE_dstExtResourceConn >() const { return meta_dstExtResourceConn_end_; }
	template <> const ::Uml::AssociationRole& ExtResourceConn::_type2ARole< ExtResourceConn::ACE_srcExtResourceConn >() const { return meta_srcExtResourceConn_end_; }

	::Uml::Class ComponentLib::meta;
	::Uml::Attribute ComponentLib::meta_sharedname;
	::Uml::Attribute ComponentLib::meta_libraryexport;
	::Uml::Attribute ComponentLib::meta_ORBServices;
	::Uml::AssociationRole ComponentLib::meta_dstExtResourceConn;
	::Uml::AssociationRole ComponentLib::meta_dstExtResourceConn_rev;
	::Uml::CompositionParentRole ComponentLib::meta_Project_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ComponentLib::_type2ACARole< ComponentLib::AR_dstExtResourceConn >() const { return make_pair(&meta_dstExtResourceConn, &meta_dstExtResourceConn_rev); }
	template <> const ::Uml::CompositionParentRole& ComponentLib::_type2CPRole< ComponentLib::PR_Project_parent >() const { return meta_Project_parent; }

	::Uml::Class MPC::meta;
	::Uml::CompositionChildRole MPC::meta_Project_children;
	::Uml::CompositionChildRole MPC::meta_Workspaces_children;
	::Uml::CompositionParentRole MPC::meta_ComponentBuild_parent;

	template <> const ::Uml::CompositionChildRole& MPC::_type2CCRole< MPC::CR_Project_children >() const { return meta_Project_children; }
	template <> const ::Uml::CompositionChildRole& MPC::_type2CCRole< MPC::CR_Workspaces_children >() const { return meta_Workspaces_children; }
	template <> const ::Uml::CompositionParentRole& MPC::_type2CPRole< MPC::PR_ComponentBuild_parent >() const { return meta_ComponentBuild_parent; }

	::Uml::Class StubProject::meta;
	::Uml::CompositionChildRole StubProject::meta_FileRef_child;
	::Uml::CompositionChildRole StubProject::meta_ImplementationArtifactReference_child;

	template <> const ::Uml::CompositionChildRole& StubProject::_type2CCRole< StubProject::CR_FileRef_child >() const { return meta_FileRef_child; }
	template <> const ::Uml::CompositionChildRole& StubProject::_type2CCRole< StubProject::CR_ImplementationArtifactReference_child >() const { return meta_ImplementationArtifactReference_child; }

	::Uml::Class ServantProject::meta;
	::Uml::CompositionChildRole ServantProject::meta_FileRef_child;
	::Uml::CompositionChildRole ServantProject::meta_ImplementationArtifactReference_child;

	template <> const ::Uml::CompositionChildRole& ServantProject::_type2CCRole< ServantProject::CR_FileRef_child >() const { return meta_FileRef_child; }
	template <> const ::Uml::CompositionChildRole& ServantProject::_type2CCRole< ServantProject::CR_ImplementationArtifactReference_child >() const { return meta_ImplementationArtifactReference_child; }

	::Uml::Class ExecutorProject::meta;
	::Uml::CompositionChildRole ExecutorProject::meta_ImplementationArtifactReference_child;

	template <> const ::Uml::CompositionChildRole& ExecutorProject::_type2CCRole< ExecutorProject::CR_ImplementationArtifactReference_child >() const { return meta_ImplementationArtifactReference_child; }

	::Uml::Class Workspaces::meta;
	::Uml::AssociationRole Workspaces::meta_members;
	::Uml::CompositionParentRole Workspaces::meta_MPC_parent;

	template <> const ::Uml::AssociationRole& Workspaces::_type2ARole< Workspaces::AR_members >() const { return meta_members; }
	template <> const ::Uml::CompositionParentRole& Workspaces::_type2CPRole< Workspaces::PR_MPC_parent >() const { return meta_MPC_parent; }

	::Uml::Class WorkerLibraries::meta;
	::Uml::Attribute WorkerLibraries::meta_name;
	::Uml::CompositionChildRole WorkerLibraries::meta_WorkerLibrary_children;
	::Uml::CompositionParentRole WorkerLibraries::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& WorkerLibraries::_type2CCRole< WorkerLibraries::CR_WorkerLibrary_children >() const { return meta_WorkerLibrary_children; }
	template <> const ::Uml::CompositionParentRole& WorkerLibraries::_type2CPRole< WorkerLibraries::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class WorkerLibrary::meta;
	::Uml::Attribute WorkerLibrary::meta_Location;
	::Uml::CompositionChildRole WorkerLibrary::meta_WorkerFile_children;
	::Uml::CompositionParentRole WorkerLibrary::meta_WorkerLibraries_parent;

	template <> const ::Uml::CompositionChildRole& WorkerLibrary::_type2CCRole< WorkerLibrary::CR_WorkerFile_children >() const { return meta_WorkerFile_children; }
	template <> const ::Uml::CompositionParentRole& WorkerLibrary::_type2CPRole< WorkerLibrary::PR_WorkerLibraries_parent >() const { return meta_WorkerLibraries_parent; }

	::Uml::Class Worker::meta;
	::Uml::Attribute Worker::meta_Abstract;
	::Uml::AssociationRole Worker::meta_referedbyWorkerType;
	::Uml::CompositionChildRole Worker::meta_Action_children;
	::Uml::CompositionParentRole Worker::meta_WorkerPackageBase_parent;

	template <> const ::Uml::AssociationRole& Worker::_type2ARole< Worker::AR_referedbyWorkerType >() const { return meta_referedbyWorkerType; }
	template <> const ::Uml::CompositionChildRole& Worker::_type2CCRole< Worker::CR_Action_children >() const { return meta_Action_children; }
	template <> const ::Uml::CompositionParentRole& Worker::_type2CPRole< Worker::PR_WorkerPackageBase_parent >() const { return meta_WorkerPackageBase_parent; }

	::Uml::Class WorkerFile::meta;
	::Uml::Attribute WorkerFile::meta_Location;
	::Uml::CompositionChildRole WorkerFile::meta_WorkerPackage_children;
	::Uml::CompositionParentRole WorkerFile::meta_WorkerLibrary_parent;

	template <> const ::Uml::CompositionChildRole& WorkerFile::_type2CCRole< WorkerFile::CR_WorkerPackage_children >() const { return meta_WorkerPackage_children; }
	template <> const ::Uml::CompositionParentRole& WorkerFile::_type2CPRole< WorkerFile::PR_WorkerLibrary_parent >() const { return meta_WorkerLibrary_parent; }

	::Uml::Class WorkerPackage::meta;
	::Uml::CompositionChildRole WorkerPackage::meta_WorkerPackage_children;
	::Uml::CompositionParentRole WorkerPackage::meta_WorkerFile_parent;
	::Uml::CompositionParentRole WorkerPackage::meta_WorkerPackage_parent;

	template <> const ::Uml::CompositionChildRole& WorkerPackage::_type2CCRole< WorkerPackage::CR_WorkerPackage_children >() const { return meta_WorkerPackage_children; }
	template <> const ::Uml::CompositionParentRole& WorkerPackage::_type2CPRole< WorkerPackage::PR_WorkerFile_parent >() const { return meta_WorkerFile_parent; }
	template <> const ::Uml::CompositionParentRole& WorkerPackage::_type2CPRole< WorkerPackage::PR_WorkerPackage_parent >() const { return meta_WorkerPackage_parent; }

	::Uml::Class WorkerType::meta;
	::Uml::AssociationRole WorkerType::meta_ref;
	::Uml::CompositionParentRole WorkerType::meta_Component_parent;

	template <> const ::Uml::AssociationRole& WorkerType::_type2ARole< WorkerType::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& WorkerType::_type2CPRole< WorkerType::PR_Component_parent >() const { return meta_Component_parent; }

	::Uml::Class WorkerPackageBase::meta;
	::Uml::CompositionChildRole WorkerPackageBase::meta_Worker_children;

	template <> const ::Uml::CompositionChildRole& WorkerPackageBase::_type2CCRole< WorkerPackageBase::CR_Worker_children >() const { return meta_Worker_children; }

	::Uml::Class Variable::meta;
	::Uml::Attribute Variable::meta_InitialValue;
	::Uml::AssociationRole Variable::meta_ref;
	::Uml::CompositionParentRole Variable::meta_BehaviorModel_parent;

	template <> const ::Uml::AssociationRole& Variable::_type2ARole< Variable::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Variable::_type2CPRole< Variable::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }

	::Uml::Class BehaviorModel::meta;
	::Uml::CompositionChildRole BehaviorModel::meta_TerminalTransition_children;
	::Uml::CompositionChildRole BehaviorModel::meta_Variable_children;
	::Uml::CompositionChildRole BehaviorModel::meta_Terminal_children;
	::Uml::CompositionChildRole BehaviorModel::meta_TerminalEffect_children;
	::Uml::CompositionChildRole BehaviorModel::meta_StateBase_children;
	::Uml::CompositionChildRole BehaviorModel::meta_BranchTransition_children;
	::Uml::CompositionChildRole BehaviorModel::meta_Transition_children;
	::Uml::CompositionChildRole BehaviorModel::meta_LoopTransition_children;
	::Uml::CompositionChildRole BehaviorModel::meta_Finish_children;
	::Uml::CompositionChildRole BehaviorModel::meta_BehaviorInputAction_children;
	::Uml::CompositionChildRole BehaviorModel::meta_ActionBase_children;
	::Uml::CompositionChildRole BehaviorModel::meta_InputEffect_children;
	::Uml::CompositionChildRole BehaviorModel::meta_Effect_children;
	::Uml::CompositionChildRole BehaviorModel::meta_QueryInputAction_children;

	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_TerminalTransition_children >() const { return meta_TerminalTransition_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_Variable_children >() const { return meta_Variable_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_Terminal_children >() const { return meta_Terminal_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_TerminalEffect_children >() const { return meta_TerminalEffect_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_StateBase_children >() const { return meta_StateBase_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_BranchTransition_children >() const { return meta_BranchTransition_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_Transition_children >() const { return meta_Transition_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_LoopTransition_children >() const { return meta_LoopTransition_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_Finish_children >() const { return meta_Finish_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_BehaviorInputAction_children >() const { return meta_BehaviorInputAction_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_ActionBase_children >() const { return meta_ActionBase_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_InputEffect_children >() const { return meta_InputEffect_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_Effect_children >() const { return meta_Effect_children; }
	template <> const ::Uml::CompositionChildRole& BehaviorModel::_type2CCRole< BehaviorModel::CR_QueryInputAction_children >() const { return meta_QueryInputAction_children; }

	::Uml::Class BehaviorInputAction::meta;
	::Uml::AssociationRole BehaviorInputAction::meta_srcFinish;
	::Uml::AssociationRole BehaviorInputAction::meta_srcFinish_rev;
	::Uml::AssociationRole BehaviorInputAction::meta_dstInputEffect;
	::Uml::AssociationRole BehaviorInputAction::meta_dstInputEffect_rev;
	::Uml::CompositionChildRole BehaviorInputAction::meta_Property_children;
	::Uml::CompositionParentRole BehaviorInputAction::meta_BehaviorModel_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> BehaviorInputAction::_type2ACARole< BehaviorInputAction::AR_srcFinish >() const { return make_pair(&meta_srcFinish, &meta_srcFinish_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> BehaviorInputAction::_type2ACARole< BehaviorInputAction::AR_dstInputEffect >() const { return make_pair(&meta_dstInputEffect, &meta_dstInputEffect_rev); }
	template <> const ::Uml::CompositionChildRole& BehaviorInputAction::_type2CCRole< BehaviorInputAction::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionParentRole& BehaviorInputAction::_type2CPRole< BehaviorInputAction::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }

	::Uml::Class Action::meta;
	::Uml::Attribute Action::meta_LogAction;
	::Uml::Attribute Action::meta_Duration;
	::Uml::CompositionParentRole Action::meta_Worker_parent;

	template <> const ::Uml::CompositionParentRole& Action::_type2CPRole< Action::PR_Worker_parent >() const { return meta_Worker_parent; }

	::Uml::Class OutputAction::meta;

	::Uml::Class Finish::meta;
	::Uml::CompositionParentRole Finish::meta_BehaviorModel_parent;
	::Uml::AssociationRole Finish::meta_dstFinish_end_;
	::Uml::AssociationRole Finish::meta_srcFinish_end_;

	template <> const ::Uml::CompositionParentRole& Finish::_type2CPRole< Finish::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& Finish::_type2ARole< Finish::ACE_dstFinish >() const { return meta_dstFinish_end_; }
	template <> const ::Uml::AssociationRole& Finish::_type2ARole< Finish::ACE_srcFinish >() const { return meta_srcFinish_end_; }

	::Uml::Class QueryAction::meta;

	::Uml::Class InputAction::meta;
	::Uml::AssociationRole InputAction::meta_srcInput;
	::Uml::AssociationRole InputAction::meta_srcInput_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> InputAction::_type2ACARole< InputAction::AR_srcInput >() const { return make_pair(&meta_srcInput, &meta_srcInput_rev); }

	::Uml::Class QueryInputAction::meta;
	::Uml::AssociationRole QueryInputAction::meta_srcQueryInput;
	::Uml::AssociationRole QueryInputAction::meta_srcQueryInput_rev;
	::Uml::CompositionChildRole QueryInputAction::meta_Property_children;
	::Uml::CompositionParentRole QueryInputAction::meta_BehaviorModel_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> QueryInputAction::_type2ACARole< QueryInputAction::AR_srcQueryInput >() const { return make_pair(&meta_srcQueryInput, &meta_srcQueryInput_rev); }
	template <> const ::Uml::CompositionChildRole& QueryInputAction::_type2CCRole< QueryInputAction::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionParentRole& QueryInputAction::_type2CPRole< QueryInputAction::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }

	::Uml::Class MultiInputAction::meta;
	::Uml::AssociationRole MultiInputAction::meta_srcMultiInput;
	::Uml::AssociationRole MultiInputAction::meta_srcMultiInput_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MultiInputAction::_type2ACARole< MultiInputAction::AR_srcMultiInput >() const { return make_pair(&meta_srcMultiInput, &meta_srcMultiInput_rev); }

	::Uml::Class ActionBase::meta;
	::Uml::AssociationRole ActionBase::meta_srcBranchTransition;
	::Uml::AssociationRole ActionBase::meta_srcBranchTransition_rev;
	::Uml::AssociationRole ActionBase::meta_dstEffect;
	::Uml::AssociationRole ActionBase::meta_dstEffect_rev;
	::Uml::AssociationRole ActionBase::meta_srcLoopTransition;
	::Uml::AssociationRole ActionBase::meta_srcLoopTransition_rev;
	::Uml::AssociationRole ActionBase::meta_srcTransition;
	::Uml::AssociationRole ActionBase::meta_srcTransition_rev;
	::Uml::CompositionChildRole ActionBase::meta_Property_children;
	::Uml::CompositionParentRole ActionBase::meta_BehaviorModel_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ActionBase::_type2ACARole< ActionBase::AR_srcBranchTransition >() const { return make_pair(&meta_srcBranchTransition, &meta_srcBranchTransition_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ActionBase::_type2ACARole< ActionBase::AR_dstEffect >() const { return make_pair(&meta_dstEffect, &meta_dstEffect_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ActionBase::_type2ACARole< ActionBase::AR_srcLoopTransition >() const { return make_pair(&meta_srcLoopTransition, &meta_srcLoopTransition_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> ActionBase::_type2ACARole< ActionBase::AR_srcTransition >() const { return make_pair(&meta_srcTransition, &meta_srcTransition_rev); }
	template <> const ::Uml::CompositionChildRole& ActionBase::_type2CCRole< ActionBase::CR_Property_children >() const { return meta_Property_children; }
	template <> const ::Uml::CompositionParentRole& ActionBase::_type2CPRole< ActionBase::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }

	::Uml::Class Environment::meta;
	::Uml::CompositionParentRole Environment::meta_TopLevelBehavior_parent;

	template <> const ::Uml::CompositionParentRole& Environment::_type2CPRole< Environment::PR_TopLevelBehavior_parent >() const { return meta_TopLevelBehavior_parent; }

	::Uml::Class PeriodicEvent::meta;
	::Uml::Attribute PeriodicEvent::meta_Distribution;
	::Uml::Attribute PeriodicEvent::meta_Hertz;
	::Uml::CompositionParentRole PeriodicEvent::meta_TopLevelBehavior_parent;

	template <> const ::Uml::CompositionParentRole& PeriodicEvent::_type2CPRole< PeriodicEvent::PR_TopLevelBehavior_parent >() const { return meta_TopLevelBehavior_parent; }

	::Uml::Class ApplicationTask::meta;
	::Uml::CompositionParentRole ApplicationTask::meta_TopLevelBehavior_parent;

	template <> const ::Uml::CompositionParentRole& ApplicationTask::_type2CPRole< ApplicationTask::PR_TopLevelBehavior_parent >() const { return meta_TopLevelBehavior_parent; }

	::Uml::Class Input::meta;
	::Uml::CompositionParentRole Input::meta_TopLevelBehavior_parent;
	::Uml::AssociationRole Input::meta_dstInput_end_;
	::Uml::AssociationRole Input::meta_srcInput_end_;

	template <> const ::Uml::CompositionParentRole& Input::_type2CPRole< Input::PR_TopLevelBehavior_parent >() const { return meta_TopLevelBehavior_parent; }
	template <> const ::Uml::AssociationRole& Input::_type2ARole< Input::ACE_dstInput >() const { return meta_dstInput_end_; }
	template <> const ::Uml::AssociationRole& Input::_type2ARole< Input::ACE_srcInput >() const { return meta_srcInput_end_; }

	::Uml::Class SingleInputBase::meta;
	::Uml::AssociationRole SingleInputBase::meta_dstInput;
	::Uml::AssociationRole SingleInputBase::meta_dstInput_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> SingleInputBase::_type2ACARole< SingleInputBase::AR_dstInput >() const { return make_pair(&meta_dstInput, &meta_dstInput_rev); }

	::Uml::Class MultiInputBase::meta;
	::Uml::AssociationRole MultiInputBase::meta_dstMultiInput;
	::Uml::AssociationRole MultiInputBase::meta_dstMultiInput_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> MultiInputBase::_type2ACARole< MultiInputBase::AR_dstMultiInput >() const { return make_pair(&meta_dstMultiInput, &meta_dstMultiInput_rev); }

	::Uml::Class MultiOutputBase::meta;

	::Uml::Class SingleOutputBase::meta;

	::Uml::Class MultiInput::meta;
	::Uml::CompositionParentRole MultiInput::meta_TopLevelBehavior_parent;
	::Uml::AssociationRole MultiInput::meta_dstMultiInput_end_;
	::Uml::AssociationRole MultiInput::meta_srcMultiInput_end_;

	template <> const ::Uml::CompositionParentRole& MultiInput::_type2CPRole< MultiInput::PR_TopLevelBehavior_parent >() const { return meta_TopLevelBehavior_parent; }
	template <> const ::Uml::AssociationRole& MultiInput::_type2ARole< MultiInput::ACE_dstMultiInput >() const { return meta_dstMultiInput_end_; }
	template <> const ::Uml::AssociationRole& MultiInput::_type2ARole< MultiInput::ACE_srcMultiInput >() const { return meta_srcMultiInput_end_; }

	::Uml::Class TopLevelBehavior::meta;
	::Uml::CompositionChildRole TopLevelBehavior::meta_Input_children;
	::Uml::CompositionChildRole TopLevelBehavior::meta_MultiInput_children;
	::Uml::CompositionChildRole TopLevelBehavior::meta_QueryInput_children;
	::Uml::CompositionChildRole TopLevelBehavior::meta_PeriodicEvent_children;
	::Uml::CompositionChildRole TopLevelBehavior::meta_ApplicationTask_children;
	::Uml::CompositionChildRole TopLevelBehavior::meta_Environment_child;

	template <> const ::Uml::CompositionChildRole& TopLevelBehavior::_type2CCRole< TopLevelBehavior::CR_Input_children >() const { return meta_Input_children; }
	template <> const ::Uml::CompositionChildRole& TopLevelBehavior::_type2CCRole< TopLevelBehavior::CR_MultiInput_children >() const { return meta_MultiInput_children; }
	template <> const ::Uml::CompositionChildRole& TopLevelBehavior::_type2CCRole< TopLevelBehavior::CR_QueryInput_children >() const { return meta_QueryInput_children; }
	template <> const ::Uml::CompositionChildRole& TopLevelBehavior::_type2CCRole< TopLevelBehavior::CR_PeriodicEvent_children >() const { return meta_PeriodicEvent_children; }
	template <> const ::Uml::CompositionChildRole& TopLevelBehavior::_type2CCRole< TopLevelBehavior::CR_ApplicationTask_children >() const { return meta_ApplicationTask_children; }
	template <> const ::Uml::CompositionChildRole& TopLevelBehavior::_type2CCRole< TopLevelBehavior::CR_Environment_child >() const { return meta_Environment_child; }

	::Uml::Class QueryInput::meta;
	::Uml::CompositionParentRole QueryInput::meta_TopLevelBehavior_parent;
	::Uml::AssociationRole QueryInput::meta_dstQueryInput_end_;
	::Uml::AssociationRole QueryInput::meta_srcQueryInput_end_;

	template <> const ::Uml::CompositionParentRole& QueryInput::_type2CPRole< QueryInput::PR_TopLevelBehavior_parent >() const { return meta_TopLevelBehavior_parent; }
	template <> const ::Uml::AssociationRole& QueryInput::_type2ARole< QueryInput::ACE_dstQueryInput >() const { return meta_dstQueryInput_end_; }
	template <> const ::Uml::AssociationRole& QueryInput::_type2ARole< QueryInput::ACE_srcQueryInput >() const { return meta_srcQueryInput_end_; }

	::Uml::Class QueryInputBase::meta;
	::Uml::AssociationRole QueryInputBase::meta_dstQueryInput;
	::Uml::AssociationRole QueryInputBase::meta_dstQueryInput_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> QueryInputBase::_type2ACARole< QueryInputBase::AR_dstQueryInput >() const { return make_pair(&meta_dstQueryInput, &meta_dstQueryInput_rev); }

	::Uml::Class Transition::meta;
	::Uml::CompositionParentRole Transition::meta_BehaviorModel_parent;
	::Uml::AssociationRole Transition::meta_dstTransition_end_;
	::Uml::AssociationRole Transition::meta_srcTransition_end_;

	template <> const ::Uml::CompositionParentRole& Transition::_type2CPRole< Transition::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& Transition::_type2ARole< Transition::ACE_dstTransition >() const { return meta_dstTransition_end_; }
	template <> const ::Uml::AssociationRole& Transition::_type2ARole< Transition::ACE_srcTransition >() const { return meta_srcTransition_end_; }

	::Uml::Class BranchState::meta;
	::Uml::AssociationRole BranchState::meta_dstBranchTransition;
	::Uml::AssociationRole BranchState::meta_dstBranchTransition_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> BranchState::_type2ACARole< BranchState::AR_dstBranchTransition >() const { return make_pair(&meta_dstBranchTransition, &meta_dstBranchTransition_rev); }

	::Uml::Class BranchTransition::meta;
	::Uml::Attribute BranchTransition::meta_Condition;
	::Uml::CompositionParentRole BranchTransition::meta_BehaviorModel_parent;
	::Uml::AssociationRole BranchTransition::meta_dstBranchTransition_end_;
	::Uml::AssociationRole BranchTransition::meta_srcBranchTransition_end_;

	template <> const ::Uml::CompositionParentRole& BranchTransition::_type2CPRole< BranchTransition::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& BranchTransition::_type2ARole< BranchTransition::ACE_dstBranchTransition >() const { return meta_dstBranchTransition_end_; }
	template <> const ::Uml::AssociationRole& BranchTransition::_type2ARole< BranchTransition::ACE_srcBranchTransition >() const { return meta_srcBranchTransition_end_; }

	::Uml::Class LoopState::meta;
	::Uml::Attribute LoopState::meta_LoopingCondition;
	::Uml::AssociationRole LoopState::meta_dstLoopTransition;
	::Uml::AssociationRole LoopState::meta_dstLoopTransition_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> LoopState::_type2ACARole< LoopState::AR_dstLoopTransition >() const { return make_pair(&meta_dstLoopTransition, &meta_dstLoopTransition_rev); }

	::Uml::Class ForState::meta;
	::Uml::Attribute ForState::meta_IncrementExpr;
	::Uml::Attribute ForState::meta_InitialCondition;

	::Uml::Class DoWhileState::meta;

	::Uml::Class WhileState::meta;

	::Uml::Class LoopTransition::meta;
	::Uml::CompositionParentRole LoopTransition::meta_BehaviorModel_parent;
	::Uml::AssociationRole LoopTransition::meta_dstLoopTransition_end_;
	::Uml::AssociationRole LoopTransition::meta_srcLoopTransition_end_;

	template <> const ::Uml::CompositionParentRole& LoopTransition::_type2CPRole< LoopTransition::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& LoopTransition::_type2ARole< LoopTransition::ACE_dstLoopTransition >() const { return meta_dstLoopTransition_end_; }
	template <> const ::Uml::AssociationRole& LoopTransition::_type2ARole< LoopTransition::ACE_srcLoopTransition >() const { return meta_srcLoopTransition_end_; }

	::Uml::Class State::meta;
	::Uml::AssociationRole State::meta_dstTransition;
	::Uml::AssociationRole State::meta_dstTransition_rev;
	::Uml::AssociationRole State::meta_dstTerminalTransition;
	::Uml::AssociationRole State::meta_dstTerminalTransition_rev;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> State::_type2ACARole< State::AR_dstTransition >() const { return make_pair(&meta_dstTransition, &meta_dstTransition_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> State::_type2ACARole< State::AR_dstTerminalTransition >() const { return make_pair(&meta_dstTerminalTransition, &meta_dstTerminalTransition_rev); }

	::Uml::Class StateBase::meta;
	::Uml::AssociationRole StateBase::meta_dstFinish;
	::Uml::AssociationRole StateBase::meta_dstFinish_rev;
	::Uml::AssociationRole StateBase::meta_srcInputEffect;
	::Uml::AssociationRole StateBase::meta_srcInputEffect_rev;
	::Uml::AssociationRole StateBase::meta_srcEffect;
	::Uml::AssociationRole StateBase::meta_srcEffect_rev;
	::Uml::AssociationRole StateBase::meta_srcTerminalEffect;
	::Uml::AssociationRole StateBase::meta_srcTerminalEffect_rev;
	::Uml::CompositionParentRole StateBase::meta_BehaviorModel_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> StateBase::_type2ACARole< StateBase::AR_dstFinish >() const { return make_pair(&meta_dstFinish, &meta_dstFinish_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> StateBase::_type2ACARole< StateBase::AR_srcInputEffect >() const { return make_pair(&meta_srcInputEffect, &meta_srcInputEffect_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> StateBase::_type2ACARole< StateBase::AR_srcEffect >() const { return make_pair(&meta_srcEffect, &meta_srcEffect_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> StateBase::_type2ACARole< StateBase::AR_srcTerminalEffect >() const { return make_pair(&meta_srcTerminalEffect, &meta_srcTerminalEffect_rev); }
	template <> const ::Uml::CompositionParentRole& StateBase::_type2CPRole< StateBase::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }

	::Uml::Class Terminal::meta;
	::Uml::AssociationRole Terminal::meta_srcTerminalTransition;
	::Uml::AssociationRole Terminal::meta_srcTerminalTransition_rev;
	::Uml::AssociationRole Terminal::meta_dstTerminalEffect;
	::Uml::AssociationRole Terminal::meta_dstTerminalEffect_rev;
	::Uml::CompositionParentRole Terminal::meta_BehaviorModel_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Terminal::_type2ACARole< Terminal::AR_srcTerminalTransition >() const { return make_pair(&meta_srcTerminalTransition, &meta_srcTerminalTransition_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Terminal::_type2ACARole< Terminal::AR_dstTerminalEffect >() const { return make_pair(&meta_dstTerminalEffect, &meta_dstTerminalEffect_rev); }
	template <> const ::Uml::CompositionParentRole& Terminal::_type2CPRole< Terminal::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }

	::Uml::Class TerminalTransition::meta;
	::Uml::CompositionParentRole TerminalTransition::meta_BehaviorModel_parent;
	::Uml::AssociationRole TerminalTransition::meta_srcTerminalTransition_end_;
	::Uml::AssociationRole TerminalTransition::meta_dstTerminalTransition_end_;

	template <> const ::Uml::CompositionParentRole& TerminalTransition::_type2CPRole< TerminalTransition::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& TerminalTransition::_type2ARole< TerminalTransition::ACE_srcTerminalTransition >() const { return meta_srcTerminalTransition_end_; }
	template <> const ::Uml::AssociationRole& TerminalTransition::_type2ARole< TerminalTransition::ACE_dstTerminalTransition >() const { return meta_dstTerminalTransition_end_; }

	::Uml::Class Effect::meta;
	::Uml::CompositionParentRole Effect::meta_BehaviorModel_parent;
	::Uml::AssociationRole Effect::meta_srcEffect_end_;
	::Uml::AssociationRole Effect::meta_dstEffect_end_;

	template <> const ::Uml::CompositionParentRole& Effect::_type2CPRole< Effect::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& Effect::_type2ARole< Effect::ACE_srcEffect >() const { return meta_srcEffect_end_; }
	template <> const ::Uml::AssociationRole& Effect::_type2ARole< Effect::ACE_dstEffect >() const { return meta_dstEffect_end_; }

	::Uml::Class InputEffect::meta;
	::Uml::CompositionParentRole InputEffect::meta_BehaviorModel_parent;
	::Uml::AssociationRole InputEffect::meta_srcInputEffect_end_;
	::Uml::AssociationRole InputEffect::meta_dstInputEffect_end_;

	template <> const ::Uml::CompositionParentRole& InputEffect::_type2CPRole< InputEffect::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& InputEffect::_type2ARole< InputEffect::ACE_srcInputEffect >() const { return meta_srcInputEffect_end_; }
	template <> const ::Uml::AssociationRole& InputEffect::_type2ARole< InputEffect::ACE_dstInputEffect >() const { return meta_dstInputEffect_end_; }

	::Uml::Class TerminalEffect::meta;
	::Uml::CompositionParentRole TerminalEffect::meta_BehaviorModel_parent;
	::Uml::AssociationRole TerminalEffect::meta_dstTerminalEffect_end_;
	::Uml::AssociationRole TerminalEffect::meta_srcTerminalEffect_end_;

	template <> const ::Uml::CompositionParentRole& TerminalEffect::_type2CPRole< TerminalEffect::PR_BehaviorModel_parent >() const { return meta_BehaviorModel_parent; }
	template <> const ::Uml::AssociationRole& TerminalEffect::_type2ARole< TerminalEffect::ACE_dstTerminalEffect >() const { return meta_dstTerminalEffect_end_; }
	template <> const ::Uml::AssociationRole& TerminalEffect::_type2ARole< TerminalEffect::ACE_srcTerminalEffect >() const { return meta_srcTerminalEffect_end_; }

	::Uml::Class EffectBase::meta;
	::Uml::Attribute EffectBase::meta_Postcondition;

	::Uml::Class RootFolder::meta;
	::Uml::Attribute RootFolder::meta_name;
	::Uml::CompositionChildRole RootFolder::meta_PathDiagrams_children;
	::Uml::CompositionChildRole RootFolder::meta_ComponentFactoryImplementations_children;
	::Uml::CompositionChildRole RootFolder::meta_ComponentAnalyses_children;
	::Uml::CompositionChildRole RootFolder::meta_DeploymentPlans_children;
	::Uml::CompositionChildRole RootFolder::meta_ComponentImplementations_children;
	::Uml::CompositionChildRole RootFolder::meta_PackageConfigurations_children;
	::Uml::CompositionChildRole RootFolder::meta_ImplementationArtifacts_children;
	::Uml::CompositionChildRole RootFolder::meta_ComponentTypes_children;
	::Uml::CompositionChildRole RootFolder::meta_TopLevelPackages_children;
	::Uml::CompositionChildRole RootFolder::meta_ComponentPackages_children;
	::Uml::CompositionChildRole RootFolder::meta_Targets_children;
	::Uml::CompositionChildRole RootFolder::meta_PredefinedTypes_children;
	::Uml::CompositionChildRole RootFolder::meta_InterfaceDefinitions_children;
	::Uml::CompositionChildRole RootFolder::meta_ComponentBuild_children;
	::Uml::CompositionChildRole RootFolder::meta_WorkerLibraries_children;
	::Uml::CompositionChildRole RootFolder::meta_RootFolder_children;
	::Uml::CompositionParentRole RootFolder::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_PathDiagrams_children >() const { return meta_PathDiagrams_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ComponentFactoryImplementations_children >() const { return meta_ComponentFactoryImplementations_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ComponentAnalyses_children >() const { return meta_ComponentAnalyses_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_DeploymentPlans_children >() const { return meta_DeploymentPlans_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ComponentImplementations_children >() const { return meta_ComponentImplementations_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_PackageConfigurations_children >() const { return meta_PackageConfigurations_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ImplementationArtifacts_children >() const { return meta_ImplementationArtifacts_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ComponentTypes_children >() const { return meta_ComponentTypes_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_TopLevelPackages_children >() const { return meta_TopLevelPackages_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ComponentPackages_children >() const { return meta_ComponentPackages_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_Targets_children >() const { return meta_Targets_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_PredefinedTypes_children >() const { return meta_PredefinedTypes_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_InterfaceDefinitions_children >() const { return meta_InterfaceDefinitions_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ComponentBuild_children >() const { return meta_ComponentBuild_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_WorkerLibraries_children >() const { return meta_WorkerLibraries_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_RootFolder_children >() const { return meta_RootFolder_children; }
	template <> const ::Uml::CompositionParentRole& RootFolder::_type2CPRole< RootFolder::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class MgaObject::meta;
	::Uml::Attribute MgaObject::meta_position;
	::Uml::Attribute MgaObject::meta_name;

	::Uml::Diagram meta;

	void CreateMeta() {
		// classes, with attributes, constraints and constraint definitions
		Action::meta = ::Uml::Class::Create(meta);
		Action::meta_LogAction = ::Uml::Attribute::Create(Action::meta);
		Action::meta_Duration = ::Uml::Attribute::Create(Action::meta);

		ActionBase::meta = ::Uml::Class::Create(meta);

		Aggregate::meta = ::Uml::Class::Create(meta);

		Alias::meta = ::Uml::Class::Create(meta);

		ApplicationTask::meta = ::Uml::Class::Create(meta);

		ArtifactContainer::meta = ::Uml::Class::Create(meta);

		ArtifactDependency::meta = ::Uml::Class::Create(meta);

		ArtifactDependsOn::meta = ::Uml::Class::Create(meta);

		ArtifactDeployRequirement::meta = ::Uml::Class::Create(meta);

		ArtifactExecParameter::meta = ::Uml::Class::Create(meta);

		ArtifactInfoProperty::meta = ::Uml::Class::Create(meta);

		AssemblyConfigProperty::meta = ::Uml::Class::Create(meta);

		AssemblyDeployRequirement::meta = ::Uml::Class::Create(meta);

		AssemblyselectRequirement::meta = ::Uml::Class::Create(meta);

		Attribute::meta = ::Uml::Class::Create(meta);

		AttributeDelegate::meta = ::Uml::Class::Create(meta);

		AttributeMapping::meta = ::Uml::Class::Create(meta);

		AttributeMappingDelegate::meta = ::Uml::Class::Create(meta);

		AttributeMappingValue::meta = ::Uml::Class::Create(meta);

		AttributeMember::meta = ::Uml::Class::Create(meta);

		AttributeValue::meta = ::Uml::Class::Create(meta);

		Average::meta = ::Uml::Class::Create(meta);

		BehaviorInputAction::meta = ::Uml::Class::Create(meta);

		BehaviorModel::meta = ::Uml::Class::Create(meta);

		BenchmarkAnalysis::meta = ::Uml::Class::Create(meta);

		BenchmarkCharacteristics::meta = ::Uml::Class::Create(meta);

		BenchmarkType::meta = ::Uml::Class::Create(meta);

		Boolean::meta = ::Uml::Class::Create(meta);

		Boxed::meta = ::Uml::Class::Create(meta);

		BranchState::meta = ::Uml::Class::Create(meta);

		BranchTransition::meta = ::Uml::Class::Create(meta);
		BranchTransition::meta_Condition = ::Uml::Attribute::Create(BranchTransition::meta);

		Bridge::meta = ::Uml::Class::Create(meta);
		Bridge::meta_label = ::Uml::Attribute::Create(Bridge::meta);

		BridgeConnection::meta = ::Uml::Class::Create(meta);

		Byte::meta = ::Uml::Class::Create(meta);

		Capability::meta = ::Uml::Class::Create(meta);

		Collection::meta = ::Uml::Class::Create(meta);
		Collection::meta_bound = ::Uml::Attribute::Create(Collection::meta);

		CollocationGroup::meta = ::Uml::Class::Create(meta);

		CollocationGroupMember::meta = ::Uml::Class::Create(meta);

		CommonPortAttrs::meta = ::Uml::Class::Create(meta);
		CommonPortAttrs::meta_exclusiveUser = ::Uml::Attribute::Create(CommonPortAttrs::meta);
		CommonPortAttrs::meta_optional = ::Uml::Attribute::Create(CommonPortAttrs::meta);
		CommonPortAttrs::meta_exclusiveProvider = ::Uml::Attribute::Create(CommonPortAttrs::meta);

		CompRef::meta = ::Uml::Class::Create(meta);

		Component::meta = ::Uml::Class::Create(meta);
		Component::meta_UUID = ::Uml::Attribute::Create(Component::meta);
		Component::meta_label = ::Uml::Attribute::Create(Component::meta);

		ComponentAnalyses::meta = ::Uml::Class::Create(meta);
		ComponentAnalyses::meta_name = ::Uml::Attribute::Create(ComponentAnalyses::meta);

		ComponentAssembly::meta = ::Uml::Class::Create(meta);

		ComponentAssemblyReference::meta = ::Uml::Class::Create(meta);

		ComponentBuild::meta = ::Uml::Class::Create(meta);
		ComponentBuild::meta_name = ::Uml::Attribute::Create(ComponentBuild::meta);

		ComponentConfigProperty::meta = ::Uml::Class::Create(meta);

		ComponentContainer::meta = ::Uml::Class::Create(meta);

		ComponentFactory::meta = ::Uml::Class::Create(meta);

		ComponentFactoryImplementationContainer::meta = ::Uml::Class::Create(meta);

		ComponentFactoryImplementations::meta = ::Uml::Class::Create(meta);
		ComponentFactoryImplementations::meta_name = ::Uml::Attribute::Create(ComponentFactoryImplementations::meta);

		ComponentFactoryInstance::meta = ::Uml::Class::Create(meta);

		ComponentFactoryRef::meta = ::Uml::Class::Create(meta);

		ComponentImplementation::meta = ::Uml::Class::Create(meta);

		ComponentImplementationArtifact::meta = ::Uml::Class::Create(meta);
		ComponentImplementationArtifact::meta_EntryPoint = ::Uml::Attribute::Create(ComponentImplementationArtifact::meta);

		ComponentImplementationContainer::meta = ::Uml::Class::Create(meta);

		ComponentImplementationReference::meta = ::Uml::Class::Create(meta);

		ComponentImplementations::meta = ::Uml::Class::Create(meta);
		ComponentImplementations::meta_name = ::Uml::Attribute::Create(ComponentImplementations::meta);

		ComponentInfoProperty::meta = ::Uml::Class::Create(meta);

		ComponentLib::meta = ::Uml::Class::Create(meta);
		ComponentLib::meta_sharedname = ::Uml::Attribute::Create(ComponentLib::meta);
		ComponentLib::meta_libraryexport = ::Uml::Attribute::Create(ComponentLib::meta);
		ComponentLib::meta_ORBServices = ::Uml::Attribute::Create(ComponentLib::meta);

		ComponentOperation::meta = ::Uml::Class::Create(meta);

		ComponentPackage::meta = ::Uml::Class::Create(meta);
		ComponentPackage::meta_UUID = ::Uml::Attribute::Create(ComponentPackage::meta);
		ComponentPackage::meta_label = ::Uml::Attribute::Create(ComponentPackage::meta);

		ComponentPackageReference::meta = ::Uml::Class::Create(meta);
		ComponentPackageReference::meta_requiredName = ::Uml::Attribute::Create(ComponentPackageReference::meta);
		ComponentPackageReference::meta_requiredUUID = ::Uml::Attribute::Create(ComponentPackageReference::meta);
		ComponentPackageReference::meta_requiredType = ::Uml::Attribute::Create(ComponentPackageReference::meta);

		ComponentPackages::meta = ::Uml::Class::Create(meta);
		ComponentPackages::meta_name = ::Uml::Attribute::Create(ComponentPackages::meta);

		ComponentProperty::meta = ::Uml::Class::Create(meta);

		ComponentPropertyDescription::meta = ::Uml::Class::Create(meta);

		ComponentRef::meta = ::Uml::Class::Create(meta);

		ComponentServantArtifact::meta = ::Uml::Class::Create(meta);
		ComponentServantArtifact::meta_EntryPoint = ::Uml::Attribute::Create(ComponentServantArtifact::meta);

		ComponentTypes::meta = ::Uml::Class::Create(meta);
		ComponentTypes::meta_name = ::Uml::Attribute::Create(ComponentTypes::meta);

		ConfigProperty::meta = ::Uml::Class::Create(meta);

		ConnectedComponent::meta = ::Uml::Class::Create(meta);

		Constant::meta = ::Uml::Class::Create(meta);
		Constant::meta_value = ::Uml::Attribute::Create(Constant::meta);

		ConstantType::meta = ::Uml::Class::Create(meta);

		CriticalPath::meta = ::Uml::Class::Create(meta);

		DataAnalysisBase::meta = ::Uml::Class::Create(meta);

		DataType::meta = ::Uml::Class::Create(meta);

		DeploymentPlan::meta = ::Uml::Class::Create(meta);
		DeploymentPlan::meta_UUID = ::Uml::Attribute::Create(DeploymentPlan::meta);
		DeploymentPlan::meta_label = ::Uml::Attribute::Create(DeploymentPlan::meta);

		DeploymentPlans::meta = ::Uml::Class::Create(meta);
		DeploymentPlans::meta_name = ::Uml::Attribute::Create(DeploymentPlans::meta);

		Deploys::meta = ::Uml::Class::Create(meta);

		Discriminator::meta = ::Uml::Class::Create(meta);

		DisplayNode::meta = ::Uml::Class::Create(meta);

		DoWhileState::meta = ::Uml::Class::Create(meta);

		Domain::meta = ::Uml::Class::Create(meta);
		Domain::meta_label = ::Uml::Attribute::Create(Domain::meta);
		Domain::meta_UUID = ::Uml::Attribute::Create(Domain::meta);

		DstEdge::meta = ::Uml::Class::Create(meta);

		ECBehavior::meta = ::Uml::Class::Create(meta);
		ECBehavior::meta_ConsumerBasedFiltering = ::Uml::Attribute::Create(ECBehavior::meta);
		ECBehavior::meta_SupplierBasedFiltering = ::Uml::Attribute::Create(ECBehavior::meta);
		ECBehavior::meta_DisconnectDanglingConnections = ::Uml::Attribute::Create(ECBehavior::meta);
		ECBehavior::meta_MultithreadedConsumer = ::Uml::Attribute::Create(ECBehavior::meta);
		ECBehavior::meta_DispatchingMultithreadingLevel = ::Uml::Attribute::Create(ECBehavior::meta);
		ECBehavior::meta_MultithreadedSupplier = ::Uml::Attribute::Create(ECBehavior::meta);

		ECRequirements::meta = ::Uml::Class::Create(meta);
		ECRequirements::meta_ConfigureRTQoS = ::Uml::Attribute::Create(ECRequirements::meta);

		ECRole::meta = ::Uml::Class::Create(meta);
		ECRole::meta_rolekind = ::Uml::Attribute::Create(ECRole::meta);
		ECRole::meta_ECFilterType = ::Uml::Attribute::Create(ECRole::meta);

		Edge::meta = ::Uml::Class::Create(meta);

		EdgeProperty::meta = ::Uml::Class::Create(meta);

		Effect::meta = ::Uml::Class::Create(meta);

		EffectBase::meta = ::Uml::Class::Create(meta);
		EffectBase::meta_Postcondition = ::Uml::Attribute::Create(EffectBase::meta);

		Enum::meta = ::Uml::Class::Create(meta);

		EnumValue::meta = ::Uml::Class::Create(meta);

		Environment::meta = ::Uml::Class::Create(meta);

		Event::meta = ::Uml::Class::Create(meta);

		EventRef::meta = ::Uml::Class::Create(meta);

		EventSinkDelegate::meta = ::Uml::Class::Create(meta);

		EventSourceDelegate::meta = ::Uml::Class::Create(meta);

		Exception::meta = ::Uml::Class::Create(meta);

		ExceptionRef::meta = ::Uml::Class::Create(meta);

		ExecutorProject::meta = ::Uml::Class::Create(meta);

		ExtResourceConn::meta = ::Uml::Class::Create(meta);

		ExternalDelegate::meta = ::Uml::Class::Create(meta);

		ExternalPortReference::meta = ::Uml::Class::Create(meta);
		ExternalPortReference::meta_label = ::Uml::Attribute::Create(ExternalPortReference::meta);
		ExternalPortReference::meta_location = ::Uml::Attribute::Create(ExternalPortReference::meta);

		ExternalPortReferenceType::meta = ::Uml::Class::Create(meta);

		ExternalResources::meta = ::Uml::Class::Create(meta);

		FacetDelegate::meta = ::Uml::Class::Create(meta);

		FactoryOperation::meta = ::Uml::Class::Create(meta);

		File::meta = ::Uml::Class::Create(meta);
		File::meta_path = ::Uml::Attribute::Create(File::meta);

		FileRef::meta = ::Uml::Class::Create(meta);

		Finish::meta = ::Uml::Class::Create(meta);

		FixedIterationBenchmarks::meta = ::Uml::Class::Create(meta);
		FixedIterationBenchmarks::meta_benchmarkIterations = ::Uml::Attribute::Create(FixedIterationBenchmarks::meta);

		ForState::meta = ::Uml::Class::Create(meta);
		ForState::meta_IncrementExpr = ::Uml::Attribute::Create(ForState::meta);
		ForState::meta_InitialCondition = ::Uml::Attribute::Create(ForState::meta);

		GenericObject::meta = ::Uml::Class::Create(meta);

		GenericValue::meta = ::Uml::Class::Create(meta);

		GenericValueObject::meta = ::Uml::Class::Create(meta);

		GetException::meta = ::Uml::Class::Create(meta);

		GraphVertex::meta = ::Uml::Class::Create(meta);

		HasExceptions::meta = ::Uml::Class::Create(meta);

		HasOperations::meta = ::Uml::Class::Create(meta);

		Implemenation::meta = ::Uml::Class::Create(meta);
		Implemenation::meta_UUID = ::Uml::Attribute::Create(Implemenation::meta);
		Implemenation::meta_label = ::Uml::Attribute::Create(Implemenation::meta);

		Implementation::meta = ::Uml::Class::Create(meta);

		ImplementationArtifact::meta = ::Uml::Class::Create(meta);
		ImplementationArtifact::meta_configuration = ::Uml::Attribute::Create(ImplementationArtifact::meta);
		ImplementationArtifact::meta_operatingSystem = ::Uml::Attribute::Create(ImplementationArtifact::meta);
		ImplementationArtifact::meta_artifactVersion = ::Uml::Attribute::Create(ImplementationArtifact::meta);
		ImplementationArtifact::meta_architecture = ::Uml::Attribute::Create(ImplementationArtifact::meta);
		ImplementationArtifact::meta_label = ::Uml::Attribute::Create(ImplementationArtifact::meta);
		ImplementationArtifact::meta_UUID = ::Uml::Attribute::Create(ImplementationArtifact::meta);
		ImplementationArtifact::meta_location = ::Uml::Attribute::Create(ImplementationArtifact::meta);

		ImplementationArtifactReference::meta = ::Uml::Class::Create(meta);

		ImplementationArtifacts::meta = ::Uml::Class::Create(meta);
		ImplementationArtifacts::meta_name = ::Uml::Attribute::Create(ImplementationArtifacts::meta);

		ImplementationCapability::meta = ::Uml::Class::Create(meta);

		ImplementationContainer::meta = ::Uml::Class::Create(meta);

		ImplementationDependency::meta = ::Uml::Class::Create(meta);
		ImplementationDependency::meta_requiredType = ::Uml::Attribute::Create(ImplementationDependency::meta);

		ImplementationDependsOn::meta = ::Uml::Class::Create(meta);

		ImplementationRequirement::meta = ::Uml::Class::Create(meta);
		ImplementationRequirement::meta_ResourceUsageKind = ::Uml::Attribute::Create(ImplementationRequirement::meta);
		ImplementationRequirement::meta_componentPort = ::Uml::Attribute::Create(ImplementationRequirement::meta);
		ImplementationRequirement::meta_resourcePort = ::Uml::Attribute::Create(ImplementationRequirement::meta);

		Implements::meta = ::Uml::Class::Create(meta);

		InEventPort::meta = ::Uml::Class::Create(meta);

		InParameter::meta = ::Uml::Class::Create(meta);

		InfoProperty::meta = ::Uml::Class::Create(meta);

		Inheritable::meta = ::Uml::Class::Create(meta);

		Inherits::meta = ::Uml::Class::Create(meta);

		InoutParameter::meta = ::Uml::Class::Create(meta);

		Input::meta = ::Uml::Class::Create(meta);

		InputAction::meta = ::Uml::Class::Create(meta);

		InputEffect::meta = ::Uml::Class::Create(meta);

		InstanceMapping::meta = ::Uml::Class::Create(meta);

		Interconnect::meta = ::Uml::Class::Create(meta);
		Interconnect::meta_label = ::Uml::Attribute::Create(Interconnect::meta);

		InterconnectConnection::meta = ::Uml::Class::Create(meta);

		InterfaceDefinitions::meta = ::Uml::Class::Create(meta);
		InterfaceDefinitions::meta_name = ::Uml::Attribute::Create(InterfaceDefinitions::meta);

		InvokePortBase::meta = ::Uml::Class::Create(meta);

		Jitter::meta = ::Uml::Class::Create(meta);

		Label::meta = ::Uml::Class::Create(meta);

		LabelConnection::meta = ::Uml::Class::Create(meta);

		Latency::meta = ::Uml::Class::Create(meta);

		LongInteger::meta = ::Uml::Class::Create(meta);

		LookupKey::meta = ::Uml::Class::Create(meta);

		LookupOperation::meta = ::Uml::Class::Create(meta);

		LoopState::meta = ::Uml::Class::Create(meta);
		LoopState::meta_LoopingCondition = ::Uml::Attribute::Create(LoopState::meta);

		LoopTransition::meta = ::Uml::Class::Create(meta);

		MPC::meta = ::Uml::Class::Create(meta);

		MakeMemberPrivate::meta = ::Uml::Class::Create(meta);

		Manageable::meta = ::Uml::Class::Create(meta);

		ManagesComponent::meta = ::Uml::Class::Create(meta);

		Maximum::meta = ::Uml::Class::Create(meta);

		Member::meta = ::Uml::Class::Create(meta);

		MemberType::meta = ::Uml::Class::Create(meta);

		MetricConnection::meta = ::Uml::Class::Create(meta);

		MetricsBase::meta = ::Uml::Class::Create(meta);
		MetricsBase::meta_warmup = ::Uml::Attribute::Create(MetricsBase::meta);
		MetricsBase::meta_fileName = ::Uml::Attribute::Create(MetricsBase::meta);
		MetricsBase::meta_iterations = ::Uml::Attribute::Create(MetricsBase::meta);
		MetricsBase::meta_priority = ::Uml::Attribute::Create(MetricsBase::meta);
		MetricsBase::meta_rate = ::Uml::Attribute::Create(MetricsBase::meta);
		MetricsBase::meta_resolution = ::Uml::Attribute::Create(MetricsBase::meta);

		MgaObject::meta = ::Uml::Class::Create(meta);
		MgaObject::meta_position = ::Uml::Attribute::Create(MgaObject::meta);
		MgaObject::meta_name = ::Uml::Attribute::Create(MgaObject::meta);

		Minimum::meta = ::Uml::Class::Create(meta);

		MonolithDeployRequirement::meta = ::Uml::Class::Create(meta);

		MonolithExecParameter::meta = ::Uml::Class::Create(meta);

		MonolithicImplementation::meta = ::Uml::Class::Create(meta);
		MonolithicImplementation::meta_defaultVersion = ::Uml::Attribute::Create(MonolithicImplementation::meta);

		MonolithicImplementationBase::meta = ::Uml::Class::Create(meta);

		MonolithprimaryArtifact::meta = ::Uml::Class::Create(meta);

		MultiInput::meta = ::Uml::Class::Create(meta);

		MultiInputAction::meta = ::Uml::Class::Create(meta);

		MultiInputBase::meta = ::Uml::Class::Create(meta);

		MultiOutputBase::meta = ::Uml::Class::Create(meta);

		MultipleServiceRequests::meta = ::Uml::Class::Create(meta);
		MultipleServiceRequests::meta_simultaneous_service_execution = ::Uml::Attribute::Create(MultipleServiceRequests::meta);
		MultipleServiceRequests::meta_minimum_simultaneous_service_level = ::Uml::Attribute::Create(MultipleServiceRequests::meta);
		MultipleServiceRequests::meta_buffer_service_requests = ::Uml::Attribute::Create(MultipleServiceRequests::meta);
		MultipleServiceRequests::meta_maximum_simultaneous_service_level = ::Uml::Attribute::Create(MultipleServiceRequests::meta);

		NamedType::meta = ::Uml::Class::Create(meta);

		NoInheritable::meta = ::Uml::Class::Create(meta);

		Node::meta = ::Uml::Class::Create(meta);
		Node::meta_operatingSystem = ::Uml::Attribute::Create(Node::meta);
		Node::meta_label = ::Uml::Attribute::Create(Node::meta);
		Node::meta_architecture = ::Uml::Attribute::Create(Node::meta);

		NodeReference::meta = ::Uml::Class::Create(meta);

		Object::meta = ::Uml::Class::Create(meta);
		Object::meta_local = ::Uml::Attribute::Create(Object::meta);
		Object::meta_abstract = ::Uml::Attribute::Create(Object::meta);

		ObjectByValue::meta = ::Uml::Class::Create(meta);
		ObjectByValue::meta_abstract = ::Uml::Attribute::Create(ObjectByValue::meta);

		OnewayOperation::meta = ::Uml::Class::Create(meta);

		OperationBase::meta = ::Uml::Class::Create(meta);

		OperationRef::meta = ::Uml::Class::Create(meta);

		OutEventPort::meta = ::Uml::Class::Create(meta);
		OutEventPort::meta_out_event_port_type = ::Uml::Attribute::Create(OutEventPort::meta);
		OutEventPort::meta_single_destination = ::Uml::Attribute::Create(OutEventPort::meta);

		OutParameter::meta = ::Uml::Class::Create(meta);

		OutputAction::meta = ::Uml::Class::Create(meta);

		Package::meta = ::Uml::Class::Create(meta);

		PackageConfBasePackage::meta = ::Uml::Class::Create(meta);

		PackageConfConfigProperty::meta = ::Uml::Class::Create(meta);

		PackageConfReference::meta = ::Uml::Class::Create(meta);

		PackageConfSelectRequirement::meta = ::Uml::Class::Create(meta);

		PackageConfSpecializedConfig::meta = ::Uml::Class::Create(meta);

		PackageConfigProperty::meta = ::Uml::Class::Create(meta);

		PackageConfiguration::meta = ::Uml::Class::Create(meta);
		PackageConfiguration::meta_UUID = ::Uml::Attribute::Create(PackageConfiguration::meta);
		PackageConfiguration::meta_label = ::Uml::Attribute::Create(PackageConfiguration::meta);

		PackageConfigurationContainer::meta = ::Uml::Class::Create(meta);

		PackageConfigurationReference::meta = ::Uml::Class::Create(meta);

		PackageConfigurations::meta = ::Uml::Class::Create(meta);
		PackageConfigurations::meta_name = ::Uml::Attribute::Create(PackageConfigurations::meta);

		PackageContainer::meta = ::Uml::Class::Create(meta);

		PackageInfoProperty::meta = ::Uml::Class::Create(meta);

		PackageInterface::meta = ::Uml::Class::Create(meta);

		ParameterType::meta = ::Uml::Class::Create(meta);

		Path::meta = ::Uml::Class::Create(meta);

		PathDiagrams::meta = ::Uml::Class::Create(meta);
		PathDiagrams::meta_name = ::Uml::Attribute::Create(PathDiagrams::meta);

		PathProperty::meta = ::Uml::Class::Create(meta);

		PathReference::meta = ::Uml::Class::Create(meta);

		Paths::meta = ::Uml::Class::Create(meta);

		PeriodicBenchmarks::meta = ::Uml::Class::Create(meta);
		PeriodicBenchmarks::meta_timeperiod = ::Uml::Attribute::Create(PeriodicBenchmarks::meta);

		PeriodicEvent::meta = ::Uml::Class::Create(meta);
		PeriodicEvent::meta_Distribution = ::Uml::Attribute::Create(PeriodicEvent::meta);
		PeriodicEvent::meta_Hertz = ::Uml::Attribute::Create(PeriodicEvent::meta);

		Port::meta = ::Uml::Class::Create(meta);

		PredefinedType::meta = ::Uml::Class::Create(meta);

		PredefinedTypes::meta = ::Uml::Class::Create(meta);
		PredefinedTypes::meta_name = ::Uml::Attribute::Create(PredefinedTypes::meta);

		Prefixable::meta = ::Uml::Class::Create(meta);
		Prefixable::meta_PrefixTag = ::Uml::Attribute::Create(Prefixable::meta);

		PrivateFlag::meta = ::Uml::Class::Create(meta);

		Project::meta = ::Uml::Class::Create(meta);

		Property::meta = ::Uml::Class::Create(meta);
		Property::meta_DataValue = ::Uml::Attribute::Create(Property::meta);

		Provideable::meta = ::Uml::Class::Create(meta);

		ProvidedRequestPort::meta = ::Uml::Class::Create(meta);

		PublishConnector::meta = ::Uml::Class::Create(meta);

		QueryAction::meta = ::Uml::Class::Create(meta);

		QueryInput::meta = ::Uml::Class::Create(meta);

		QueryInputAction::meta = ::Uml::Class::Create(meta);

		QueryInputBase::meta = ::Uml::Class::Create(meta);

		RTRequirements::meta = ::Uml::Class::Create(meta);

		ReadonlyAttribute::meta = ::Uml::Class::Create(meta);

		RealNumber::meta = ::Uml::Class::Create(meta);

		ReceptacleDelegate::meta = ::Uml::Class::Create(meta);

		RequiredRequestPort::meta = ::Uml::Class::Create(meta);
		RequiredRequestPort::meta_multiple_connections = ::Uml::Attribute::Create(RequiredRequestPort::meta);

		Requirement::meta = ::Uml::Class::Create(meta);

		RequirementBase::meta = ::Uml::Class::Create(meta);
		RequirementBase::meta_resourceType = ::Uml::Attribute::Create(RequirementBase::meta);

		RequirementSatisfier::meta = ::Uml::Class::Create(meta);
		RequirementSatisfier::meta_resourceType = ::Uml::Attribute::Create(RequirementSatisfier::meta);

		Resource::meta = ::Uml::Class::Create(meta);

		ReturnType::meta = ::Uml::Class::Create(meta);

		RootFolder::meta = ::Uml::Class::Create(meta);
		RootFolder::meta_name = ::Uml::Attribute::Create(RootFolder::meta);

		SatisfierProperty::meta = ::Uml::Class::Create(meta);
		SatisfierProperty::meta_DataValue = ::Uml::Attribute::Create(SatisfierProperty::meta);
		SatisfierProperty::meta_SatisfierPropertyKind = ::Uml::Attribute::Create(SatisfierProperty::meta);
		SatisfierProperty::meta_dynamic = ::Uml::Attribute::Create(SatisfierProperty::meta);

		ServantProject::meta = ::Uml::Class::Create(meta);

		ServiceConsumer::meta = ::Uml::Class::Create(meta);
		ServiceConsumer::meta_prioritize_service_invocations = ::Uml::Attribute::Create(ServiceConsumer::meta);

		ServiceLevels::meta = ::Uml::Class::Create(meta);
		ServiceLevels::meta_varying_service_levels = ::Uml::Attribute::Create(ServiceLevels::meta);

		ServiceProvider::meta = ::Uml::Class::Create(meta);
		ServiceProvider::meta_fixed_prioirty_service_execution = ::Uml::Attribute::Create(ServiceProvider::meta);

		SetException::meta = ::Uml::Class::Create(meta);

		SharedComponentReference::meta = ::Uml::Class::Create(meta);

		SharedResource::meta = ::Uml::Class::Create(meta);

		Shares::meta = ::Uml::Class::Create(meta);

		ShortInteger::meta = ::Uml::Class::Create(meta);

		SingleInputBase::meta = ::Uml::Class::Create(meta);

		SingleOutputBase::meta = ::Uml::Class::Create(meta);

		SrcEdge::meta = ::Uml::Class::Create(meta);

		State::meta = ::Uml::Class::Create(meta);

		StateBase::meta = ::Uml::Class::Create(meta);

		String::meta = ::Uml::Class::Create(meta);

		StubProject::meta = ::Uml::Class::Create(meta);

		Supports::meta = ::Uml::Class::Create(meta);

		SupportsDelegate::meta = ::Uml::Class::Create(meta);

		SupportsInterfaces::meta = ::Uml::Class::Create(meta);

		SwitchedAggregate::meta = ::Uml::Class::Create(meta);

		Taggable::meta = ::Uml::Class::Create(meta);
		Taggable::meta_SpecifyIdTag = ::Uml::Attribute::Create(Taggable::meta);
		Taggable::meta_VersionTag = ::Uml::Attribute::Create(Taggable::meta);

		Targets::meta = ::Uml::Class::Create(meta);
		Targets::meta_name = ::Uml::Attribute::Create(Targets::meta);

		Task::meta = ::Uml::Class::Create(meta);

		TaskSet::meta = ::Uml::Class::Create(meta);
		TaskSet::meta_rate = ::Uml::Attribute::Create(TaskSet::meta);
		TaskSet::meta_priority = ::Uml::Attribute::Create(TaskSet::meta);

		Terminal::meta = ::Uml::Class::Create(meta);

		TerminalEffect::meta = ::Uml::Class::Create(meta);

		TerminalTransition::meta = ::Uml::Class::Create(meta);

		Throughput::meta = ::Uml::Class::Create(meta);

		TimeProbe::meta = ::Uml::Class::Create(meta);

		TimerConnection::meta = ::Uml::Class::Create(meta);

		TimerEventSinkConn::meta = ::Uml::Class::Create(meta);

		TopLevelBehavior::meta = ::Uml::Class::Create(meta);

		TopLevelPackage::meta = ::Uml::Class::Create(meta);

		TopLevelPackageContainer::meta = ::Uml::Class::Create(meta);

		TopLevelPackages::meta = ::Uml::Class::Create(meta);
		TopLevelPackages::meta_name = ::Uml::Attribute::Create(TopLevelPackages::meta);

		Transition::meta = ::Uml::Class::Create(meta);

		TriggerBenchmarks::meta = ::Uml::Class::Create(meta);

		TwowayOperation::meta = ::Uml::Class::Create(meta);

		TypeEncoding::meta = ::Uml::Class::Create(meta);

		TypeKind::meta = ::Uml::Class::Create(meta);

		ValueObject::meta = ::Uml::Class::Create(meta);

		Variable::meta = ::Uml::Class::Create(meta);
		Variable::meta_InitialValue = ::Uml::Attribute::Create(Variable::meta);

		WhileState::meta = ::Uml::Class::Create(meta);

		WorkLoadOperationConnection::meta = ::Uml::Class::Create(meta);

		Worker::meta = ::Uml::Class::Create(meta);
		Worker::meta_Abstract = ::Uml::Attribute::Create(Worker::meta);

		WorkerFile::meta = ::Uml::Class::Create(meta);
		WorkerFile::meta_Location = ::Uml::Attribute::Create(WorkerFile::meta);

		WorkerLibraries::meta = ::Uml::Class::Create(meta);
		WorkerLibraries::meta_name = ::Uml::Attribute::Create(WorkerLibraries::meta);

		WorkerLibrary::meta = ::Uml::Class::Create(meta);
		WorkerLibrary::meta_Location = ::Uml::Attribute::Create(WorkerLibrary::meta);

		WorkerPackage::meta = ::Uml::Class::Create(meta);

		WorkerPackageBase::meta = ::Uml::Class::Create(meta);

		WorkerType::meta = ::Uml::Class::Create(meta);

		WorkloadCharacteristics::meta = ::Uml::Class::Create(meta);

		Workspaces::meta = ::Uml::Class::Create(meta);

		deliverTo::meta = ::Uml::Class::Create(meta);

		emit::meta = ::Uml::Class::Create(meta);

		invoke::meta = ::Uml::Class::Create(meta);

		package::meta = ::Uml::Class::Create(meta);

		publish::meta = ::Uml::Class::Create(meta);

	}

	void InitMeta() {
		// classes, with attributes, constraints and constraint definitions
		::Uml::InitClassProps(Action::meta, "Action", false, "Model", NULL);
		vector<string> Action_LogAction_dva;
		Action_LogAction_dva.push_back("false");
		::Uml::InitAttributeProps(Action::meta_LogAction, "LogAction", "Boolean", false, false, 1, 1, false, "public", Action_LogAction_dva);
		::Uml::InitAttributeProps(Action::meta_Duration, "Duration", "Integer", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ActionBase::meta, "ActionBase", true, "Model", NULL);

		::Uml::InitClassProps(Aggregate::meta, "Aggregate", false, "Model", NULL);

		::Uml::InitClassProps(Alias::meta, "Alias", false, "Reference", NULL);

		::Uml::InitClassProps(ApplicationTask::meta, "ApplicationTask", false, "Atom", NULL);

		::Uml::InitClassProps(ArtifactContainer::meta, "ArtifactContainer", false, "Model", NULL);

		::Uml::InitClassProps(ArtifactDependency::meta, "ArtifactDependency", false, "Connection", NULL);

		::Uml::InitClassProps(ArtifactDependsOn::meta, "ArtifactDependsOn", false, "Connection", NULL);

		::Uml::InitClassProps(ArtifactDeployRequirement::meta, "ArtifactDeployRequirement", false, "Connection", NULL);

		::Uml::InitClassProps(ArtifactExecParameter::meta, "ArtifactExecParameter", false, "Connection", NULL);

		::Uml::InitClassProps(ArtifactInfoProperty::meta, "ArtifactInfoProperty", false, "Connection", NULL);

		::Uml::InitClassProps(AssemblyConfigProperty::meta, "AssemblyConfigProperty", false, "Connection", NULL);

		::Uml::InitClassProps(AssemblyDeployRequirement::meta, "AssemblyDeployRequirement", false, "Connection", NULL);

		::Uml::InitClassProps(AssemblyselectRequirement::meta, "AssemblyselectRequirement", false, "Connection", NULL);

		::Uml::InitClassProps(Attribute::meta, "Attribute", false, "Model", NULL);

		::Uml::InitClassProps(AttributeDelegate::meta, "AttributeDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(AttributeMapping::meta, "AttributeMapping", false, "Reference", NULL);

		::Uml::InitClassProps(AttributeMappingDelegate::meta, "AttributeMappingDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(AttributeMappingValue::meta, "AttributeMappingValue", false, "Connection", NULL);

		::Uml::InitClassProps(AttributeMember::meta, "AttributeMember", false, "Reference", NULL);

		::Uml::InitClassProps(AttributeValue::meta, "AttributeValue", false, "Connection", NULL);

		::Uml::InitClassProps(Average::meta, "Average", false, "Atom", NULL);

		::Uml::InitClassProps(BehaviorInputAction::meta, "BehaviorInputAction", true, "Model", NULL);

		::Uml::InitClassProps(BehaviorModel::meta, "BehaviorModel", true, "Model", NULL);

		::Uml::InitClassProps(BenchmarkAnalysis::meta, "BenchmarkAnalysis", false, "Model", NULL);

		::Uml::InitClassProps(BenchmarkCharacteristics::meta, "BenchmarkCharacteristics", false, "Connection", NULL);

		::Uml::InitClassProps(BenchmarkType::meta, "BenchmarkType", true, "FCO", NULL);

		::Uml::InitClassProps(Boolean::meta, "Boolean", false, "Atom", NULL);

		::Uml::InitClassProps(Boxed::meta, "Boxed", false, "Reference", NULL);

		::Uml::InitClassProps(BranchState::meta, "BranchState", false, "Atom", NULL);

		::Uml::InitClassProps(BranchTransition::meta, "BranchTransition", false, "Connection", NULL);
		::Uml::InitAttributeProps(BranchTransition::meta_Condition, "Condition", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Bridge::meta, "Bridge", false, "Model", NULL);
		::Uml::InitAttributeProps(Bridge::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(BridgeConnection::meta, "BridgeConnection", false, "Connection", NULL);

		::Uml::InitClassProps(Byte::meta, "Byte", false, "Atom", NULL);

		::Uml::InitClassProps(Capability::meta, "Capability", false, "Model", NULL);

		::Uml::InitClassProps(Collection::meta, "Collection", false, "Reference", NULL);
		::Uml::InitAttributeProps(Collection::meta_bound, "bound", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(CollocationGroup::meta, "CollocationGroup", false, "Set", NULL);

		::Uml::InitClassProps(CollocationGroupMember::meta, "CollocationGroupMember", true, "FCO", NULL);

		::Uml::InitClassProps(CommonPortAttrs::meta, "CommonPortAttrs", true, "FCO", NULL);
		vector<string> CommonPortAttrs_exclusiveUser_dva;
		CommonPortAttrs_exclusiveUser_dva.push_back("false");
		::Uml::InitAttributeProps(CommonPortAttrs::meta_exclusiveUser, "exclusiveUser", "Boolean", false, false, 1, 1, false, "public", CommonPortAttrs_exclusiveUser_dva);
		vector<string> CommonPortAttrs_optional_dva;
		CommonPortAttrs_optional_dva.push_back("false");
		::Uml::InitAttributeProps(CommonPortAttrs::meta_optional, "optional", "Boolean", false, false, 1, 1, false, "public", CommonPortAttrs_optional_dva);
		vector<string> CommonPortAttrs_exclusiveProvider_dva;
		CommonPortAttrs_exclusiveProvider_dva.push_back("false");
		::Uml::InitAttributeProps(CommonPortAttrs::meta_exclusiveProvider, "exclusiveProvider", "Boolean", false, false, 1, 1, false, "public", CommonPortAttrs_exclusiveProvider_dva);

		::Uml::InitClassProps(CompRef::meta, "CompRef", false, "Reference", NULL);

		::Uml::InitClassProps(Component::meta, "Component", false, "Model", NULL);
		::Uml::InitAttributeProps(Component::meta_UUID, "UUID", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(Component::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentAnalyses::meta, "ComponentAnalyses", false, "Folder", NULL);
		::Uml::InitAttributeProps(ComponentAnalyses::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentAssembly::meta, "ComponentAssembly", false, "Model", NULL);

		::Uml::InitClassProps(ComponentAssemblyReference::meta, "ComponentAssemblyReference", false, "Reference", NULL);

		::Uml::InitClassProps(ComponentBuild::meta, "ComponentBuild", false, "Folder", NULL);
		::Uml::InitAttributeProps(ComponentBuild::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentConfigProperty::meta, "ComponentConfigProperty", false, "Connection", NULL);

		::Uml::InitClassProps(ComponentContainer::meta, "ComponentContainer", false, "Model", NULL);

		::Uml::InitClassProps(ComponentFactory::meta, "ComponentFactory", false, "Model", NULL);

		::Uml::InitClassProps(ComponentFactoryImplementationContainer::meta, "ComponentFactoryImplementationContainer", false, "Model", NULL);

		::Uml::InitClassProps(ComponentFactoryImplementations::meta, "ComponentFactoryImplementations", false, "Folder", NULL);
		::Uml::InitAttributeProps(ComponentFactoryImplementations::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentFactoryInstance::meta, "ComponentFactoryInstance", false, "Reference", NULL);

		::Uml::InitClassProps(ComponentFactoryRef::meta, "ComponentFactoryRef", false, "Reference", NULL);

		::Uml::InitClassProps(ComponentImplementation::meta, "ComponentImplementation", true, "FCO", NULL);

		::Uml::InitClassProps(ComponentImplementationArtifact::meta, "ComponentImplementationArtifact", false, "Reference", NULL);
		::Uml::InitAttributeProps(ComponentImplementationArtifact::meta_EntryPoint, "EntryPoint", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentImplementationContainer::meta, "ComponentImplementationContainer", false, "Model", NULL);

		::Uml::InitClassProps(ComponentImplementationReference::meta, "ComponentImplementationReference", false, "Reference", NULL);

		::Uml::InitClassProps(ComponentImplementations::meta, "ComponentImplementations", false, "Folder", NULL);
		::Uml::InitAttributeProps(ComponentImplementations::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentInfoProperty::meta, "ComponentInfoProperty", false, "Connection", NULL);

		::Uml::InitClassProps(ComponentLib::meta, "ComponentLib", true, "FCO", NULL);
		::Uml::InitAttributeProps(ComponentLib::meta_sharedname, "sharedname", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ComponentLib::meta_libraryexport, "libraryexport", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ComponentLib::meta_ORBServices, "ORBServices", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentOperation::meta, "ComponentOperation", false, "Connection", NULL);

		::Uml::InitClassProps(ComponentPackage::meta, "ComponentPackage", false, "Atom", NULL);
		::Uml::InitAttributeProps(ComponentPackage::meta_UUID, "UUID", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ComponentPackage::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentPackageReference::meta, "ComponentPackageReference", false, "Reference", NULL);
		::Uml::InitAttributeProps(ComponentPackageReference::meta_requiredName, "requiredName", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ComponentPackageReference::meta_requiredUUID, "requiredUUID", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ComponentPackageReference::meta_requiredType, "requiredType", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentPackages::meta, "ComponentPackages", false, "Folder", NULL);
		::Uml::InitAttributeProps(ComponentPackages::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentProperty::meta, "ComponentProperty", false, "Connection", NULL);

		::Uml::InitClassProps(ComponentPropertyDescription::meta, "ComponentPropertyDescription", false, "Model", NULL);

		::Uml::InitClassProps(ComponentRef::meta, "ComponentRef", false, "Reference", NULL);

		::Uml::InitClassProps(ComponentServantArtifact::meta, "ComponentServantArtifact", false, "Reference", NULL);
		::Uml::InitAttributeProps(ComponentServantArtifact::meta_EntryPoint, "EntryPoint", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ComponentTypes::meta, "ComponentTypes", false, "Folder", NULL);
		::Uml::InitAttributeProps(ComponentTypes::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ConfigProperty::meta, "ConfigProperty", false, "Connection", NULL);

		::Uml::InitClassProps(ConnectedComponent::meta, "ConnectedComponent", false, "Model", NULL);

		::Uml::InitClassProps(Constant::meta, "Constant", false, "Reference", NULL);
		::Uml::InitAttributeProps(Constant::meta_value, "value", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ConstantType::meta, "ConstantType", true, "FCO", NULL);

		::Uml::InitClassProps(CriticalPath::meta, "CriticalPath", false, "Connection", NULL);

		::Uml::InitClassProps(DataAnalysisBase::meta, "DataAnalysisBase", true, "FCO", NULL);

		::Uml::InitClassProps(DataType::meta, "DataType", false, "Reference", NULL);

		::Uml::InitClassProps(DeploymentPlan::meta, "DeploymentPlan", false, "Model", NULL);
		::Uml::InitAttributeProps(DeploymentPlan::meta_UUID, "UUID", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(DeploymentPlan::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(DeploymentPlans::meta, "DeploymentPlans", false, "Folder", NULL);
		::Uml::InitAttributeProps(DeploymentPlans::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Deploys::meta, "Deploys", false, "Connection", NULL);

		::Uml::InitClassProps(Discriminator::meta, "Discriminator", false, "Reference", NULL);

		::Uml::InitClassProps(DisplayNode::meta, "DisplayNode", false, "Atom", NULL);

		::Uml::InitClassProps(DoWhileState::meta, "DoWhileState", false, "Atom", NULL);

		::Uml::InitClassProps(Domain::meta, "Domain", false, "Model", NULL);
		::Uml::InitAttributeProps(Domain::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(Domain::meta_UUID, "UUID", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(DstEdge::meta, "DstEdge", false, "Connection", NULL);

		::Uml::InitClassProps(ECBehavior::meta, "ECBehavior", false, "Atom", NULL);
		vector<string> ECBehavior_ConsumerBasedFiltering_dva;
		ECBehavior_ConsumerBasedFiltering_dva.push_back("true");
		::Uml::InitAttributeProps(ECBehavior::meta_ConsumerBasedFiltering, "ConsumerBasedFiltering", "Boolean", false, false, 1, 1, false, "public", ECBehavior_ConsumerBasedFiltering_dva);
		vector<string> ECBehavior_SupplierBasedFiltering_dva;
		ECBehavior_SupplierBasedFiltering_dva.push_back("true");
		::Uml::InitAttributeProps(ECBehavior::meta_SupplierBasedFiltering, "SupplierBasedFiltering", "Boolean", false, false, 1, 1, false, "public", ECBehavior_SupplierBasedFiltering_dva);
		vector<string> ECBehavior_DisconnectDanglingConnections_dva;
		ECBehavior_DisconnectDanglingConnections_dva.push_back("true");
		::Uml::InitAttributeProps(ECBehavior::meta_DisconnectDanglingConnections, "DisconnectDanglingConnections", "Boolean", false, false, 1, 1, false, "public", ECBehavior_DisconnectDanglingConnections_dva);
		vector<string> ECBehavior_MultithreadedConsumer_dva;
		ECBehavior_MultithreadedConsumer_dva.push_back("false");
		::Uml::InitAttributeProps(ECBehavior::meta_MultithreadedConsumer, "MultithreadedConsumer", "Boolean", false, false, 1, 1, false, "public", ECBehavior_MultithreadedConsumer_dva);
		::Uml::InitAttributeProps(ECBehavior::meta_DispatchingMultithreadingLevel, "DispatchingMultithreadingLevel", "Integer", false, false, 1, 1, false, "public", vector<string>());
		vector<string> ECBehavior_MultithreadedSupplier_dva;
		ECBehavior_MultithreadedSupplier_dva.push_back("false");
		::Uml::InitAttributeProps(ECBehavior::meta_MultithreadedSupplier, "MultithreadedSupplier", "Boolean", false, false, 1, 1, false, "public", ECBehavior_MultithreadedSupplier_dva);

		::Uml::InitClassProps(ECRequirements::meta, "ECRequirements", false, "Model", NULL);
		vector<string> ECRequirements_ConfigureRTQoS_dva;
		ECRequirements_ConfigureRTQoS_dva.push_back("true");
		::Uml::InitAttributeProps(ECRequirements::meta_ConfigureRTQoS, "ConfigureRTQoS", "Boolean", false, false, 1, 1, false, "public", ECRequirements_ConfigureRTQoS_dva);

		::Uml::InitClassProps(ECRole::meta, "ECRole", false, "Atom", NULL);
		vector<string> ECRole_rolekind_dva;
		ECRole_rolekind_dva.push_back("CONSUMER");
		::Uml::InitAttributeProps(ECRole::meta_rolekind, "rolekind", "String", false, false, 1, 1, false, "public", ECRole_rolekind_dva);
		vector<string> ECRole_ECFilterType_dva;
		ECRole_ECFilterType_dva.push_back("DISJUNCTION");
		::Uml::InitAttributeProps(ECRole::meta_ECFilterType, "ECFilterType", "String", false, false, 1, 1, false, "public", ECRole_ECFilterType_dva);

		::Uml::InitClassProps(Edge::meta, "Edge", false, "Atom", NULL);

		::Uml::InitClassProps(EdgeProperty::meta, "EdgeProperty", false, "Connection", NULL);

		::Uml::InitClassProps(Effect::meta, "Effect", false, "Connection", NULL);

		::Uml::InitClassProps(EffectBase::meta, "EffectBase", true, "Connection", NULL);
		::Uml::InitAttributeProps(EffectBase::meta_Postcondition, "Postcondition", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Enum::meta, "Enum", false, "Model", NULL);

		::Uml::InitClassProps(EnumValue::meta, "EnumValue", false, "Atom", NULL);

		::Uml::InitClassProps(Environment::meta, "Environment", false, "Atom", NULL);

		::Uml::InitClassProps(Event::meta, "Event", false, "Model", NULL);

		::Uml::InitClassProps(EventRef::meta, "EventRef", false, "Reference", NULL);

		::Uml::InitClassProps(EventSinkDelegate::meta, "EventSinkDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(EventSourceDelegate::meta, "EventSourceDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(Exception::meta, "Exception", false, "Model", NULL);

		::Uml::InitClassProps(ExceptionRef::meta, "ExceptionRef", false, "Reference", NULL);

		::Uml::InitClassProps(ExecutorProject::meta, "ExecutorProject", false, "Model", NULL);

		::Uml::InitClassProps(ExtResourceConn::meta, "ExtResourceConn", false, "Connection", NULL);

		::Uml::InitClassProps(ExternalDelegate::meta, "ExternalDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(ExternalPortReference::meta, "ExternalPortReference", false, "Reference", NULL);
		::Uml::InitAttributeProps(ExternalPortReference::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ExternalPortReference::meta_location, "location", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ExternalPortReferenceType::meta, "ExternalPortReferenceType", true, "FCO", NULL);

		::Uml::InitClassProps(ExternalResources::meta, "ExternalResources", false, "Reference", NULL);

		::Uml::InitClassProps(FacetDelegate::meta, "FacetDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(FactoryOperation::meta, "FactoryOperation", false, "Model", NULL);

		::Uml::InitClassProps(File::meta, "File", false, "Model", NULL);
		::Uml::InitAttributeProps(File::meta_path, "path", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(FileRef::meta, "FileRef", false, "Reference", NULL);

		::Uml::InitClassProps(Finish::meta, "Finish", false, "Connection", NULL);

		::Uml::InitClassProps(FixedIterationBenchmarks::meta, "FixedIterationBenchmarks", false, "Atom", NULL);
		::Uml::InitAttributeProps(FixedIterationBenchmarks::meta_benchmarkIterations, "benchmarkIterations", "Integer", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ForState::meta, "ForState", false, "Atom", NULL);
		::Uml::InitAttributeProps(ForState::meta_IncrementExpr, "IncrementExpr", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ForState::meta_InitialCondition, "InitialCondition", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(GenericObject::meta, "GenericObject", false, "Atom", NULL);

		::Uml::InitClassProps(GenericValue::meta, "GenericValue", false, "Atom", NULL);

		::Uml::InitClassProps(GenericValueObject::meta, "GenericValueObject", false, "Atom", NULL);

		::Uml::InitClassProps(GetException::meta, "GetException", false, "Reference", NULL);

		::Uml::InitClassProps(GraphVertex::meta, "GraphVertex", true, "FCO", NULL);

		::Uml::InitClassProps(HasExceptions::meta, "HasExceptions", true, "Model", NULL);

		::Uml::InitClassProps(HasOperations::meta, "HasOperations", true, "Model", NULL);

		::Uml::InitClassProps(Implemenation::meta, "Implemenation", true, "FCO", NULL);
		::Uml::InitAttributeProps(Implemenation::meta_UUID, "UUID", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(Implemenation::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Implementation::meta, "Implementation", false, "Connection", NULL);

		::Uml::InitClassProps(ImplementationArtifact::meta, "ImplementationArtifact", false, "Atom", NULL);
		::Uml::InitAttributeProps(ImplementationArtifact::meta_configuration, "configuration", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ImplementationArtifact::meta_operatingSystem, "operatingSystem", "String", false, false, 1, 1, false, "public", vector<string>());
		vector<string> ImplementationArtifact_artifactVersion_dva;
		ImplementationArtifact_artifactVersion_dva.push_back("0.0.0.0");
		::Uml::InitAttributeProps(ImplementationArtifact::meta_artifactVersion, "artifactVersion", "String", false, false, 1, 1, false, "public", ImplementationArtifact_artifactVersion_dva);
		::Uml::InitAttributeProps(ImplementationArtifact::meta_architecture, "architecture", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ImplementationArtifact::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ImplementationArtifact::meta_UUID, "UUID", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ImplementationArtifact::meta_location, "location", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ImplementationArtifactReference::meta, "ImplementationArtifactReference", false, "Reference", NULL);

		::Uml::InitClassProps(ImplementationArtifacts::meta, "ImplementationArtifacts", false, "Folder", NULL);
		::Uml::InitAttributeProps(ImplementationArtifacts::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ImplementationCapability::meta, "ImplementationCapability", false, "Connection", NULL);

		::Uml::InitClassProps(ImplementationContainer::meta, "ImplementationContainer", true, "Model", NULL);

		::Uml::InitClassProps(ImplementationDependency::meta, "ImplementationDependency", false, "Atom", NULL);
		::Uml::InitAttributeProps(ImplementationDependency::meta_requiredType, "requiredType", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(ImplementationDependsOn::meta, "ImplementationDependsOn", false, "Connection", NULL);

		::Uml::InitClassProps(ImplementationRequirement::meta, "ImplementationRequirement", false, "Model", NULL);
		vector<string> ImplementationRequirement_ResourceUsageKind_dva;
		ImplementationRequirement_ResourceUsageKind_dva.push_back("None");
		::Uml::InitAttributeProps(ImplementationRequirement::meta_ResourceUsageKind, "ResourceUsageKind", "String", false, false, 1, 1, false, "public", ImplementationRequirement_ResourceUsageKind_dva);
		::Uml::InitAttributeProps(ImplementationRequirement::meta_componentPort, "componentPort", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(ImplementationRequirement::meta_resourcePort, "resourcePort", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Implements::meta, "Implements", false, "Connection", NULL);

		::Uml::InitClassProps(InEventPort::meta, "InEventPort", false, "Reference", NULL);

		::Uml::InitClassProps(InParameter::meta, "InParameter", false, "Reference", NULL);

		::Uml::InitClassProps(InfoProperty::meta, "InfoProperty", false, "Connection", NULL);

		::Uml::InitClassProps(Inheritable::meta, "Inheritable", true, "Model", NULL);

		::Uml::InitClassProps(Inherits::meta, "Inherits", false, "Reference", NULL);

		::Uml::InitClassProps(InoutParameter::meta, "InoutParameter", false, "Reference", NULL);

		::Uml::InitClassProps(Input::meta, "Input", false, "Connection", NULL);

		::Uml::InitClassProps(InputAction::meta, "InputAction", false, "Model", NULL);

		::Uml::InitClassProps(InputEffect::meta, "InputEffect", false, "Connection", NULL);

		::Uml::InitClassProps(InstanceMapping::meta, "InstanceMapping", false, "Connection", NULL);

		::Uml::InitClassProps(Interconnect::meta, "Interconnect", false, "Model", NULL);
		::Uml::InitAttributeProps(Interconnect::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(InterconnectConnection::meta, "InterconnectConnection", false, "Connection", NULL);

		::Uml::InitClassProps(InterfaceDefinitions::meta, "InterfaceDefinitions", false, "Folder", NULL);
		::Uml::InitAttributeProps(InterfaceDefinitions::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(InvokePortBase::meta, "InvokePortBase", true, "FCO", NULL);

		::Uml::InitClassProps(Jitter::meta, "Jitter", false, "Atom", NULL);

		::Uml::InitClassProps(Label::meta, "Label", false, "Atom", NULL);

		::Uml::InitClassProps(LabelConnection::meta, "LabelConnection", false, "Connection", NULL);

		::Uml::InitClassProps(Latency::meta, "Latency", false, "Model", NULL);

		::Uml::InitClassProps(LongInteger::meta, "LongInteger", false, "Atom", NULL);

		::Uml::InitClassProps(LookupKey::meta, "LookupKey", false, "Reference", NULL);

		::Uml::InitClassProps(LookupOperation::meta, "LookupOperation", false, "Model", NULL);

		::Uml::InitClassProps(LoopState::meta, "LoopState", true, "Atom", NULL);
		::Uml::InitAttributeProps(LoopState::meta_LoopingCondition, "LoopingCondition", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(LoopTransition::meta, "LoopTransition", false, "Connection", NULL);

		::Uml::InitClassProps(MPC::meta, "MPC", false, "Model", NULL);

		::Uml::InitClassProps(MakeMemberPrivate::meta, "MakeMemberPrivate", false, "Connection", NULL);

		::Uml::InitClassProps(Manageable::meta, "Manageable", true, "FCO", NULL);

		::Uml::InitClassProps(ManagesComponent::meta, "ManagesComponent", false, "Connection", NULL);

		::Uml::InitClassProps(Maximum::meta, "Maximum", false, "Atom", NULL);

		::Uml::InitClassProps(Member::meta, "Member", false, "Reference", NULL);

		::Uml::InitClassProps(MemberType::meta, "MemberType", true, "FCO", NULL);

		::Uml::InitClassProps(MetricConnection::meta, "MetricConnection", false, "Connection", NULL);

		::Uml::InitClassProps(MetricsBase::meta, "MetricsBase", true, "Model", NULL);
		::Uml::InitAttributeProps(MetricsBase::meta_warmup, "warmup", "Integer", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(MetricsBase::meta_fileName, "fileName", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(MetricsBase::meta_iterations, "iterations", "Integer", false, false, 1, 1, false, "public", vector<string>());
		vector<string> MetricsBase_priority_dva;
		MetricsBase_priority_dva.push_back("-1");
		::Uml::InitAttributeProps(MetricsBase::meta_priority, "priority", "Integer", false, false, 1, 1, false, "public", MetricsBase_priority_dva);
		vector<string> MetricsBase_rate_dva;
		MetricsBase_rate_dva.push_back("-1");
		::Uml::InitAttributeProps(MetricsBase::meta_rate, "rate", "Integer", false, false, 1, 1, false, "public", MetricsBase_rate_dva);
		vector<string> MetricsBase_resolution_dva;
		MetricsBase_resolution_dva.push_back("microseconds");
		::Uml::InitAttributeProps(MetricsBase::meta_resolution, "resolution", "String", false, false, 1, 1, false, "public", MetricsBase_resolution_dva);

		::Uml::InitClassProps(MgaObject::meta, "MgaObject", true, NULL, NULL);
		::Uml::InitAttributeProps(MgaObject::meta_position, "position", "String", false, false, 0, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(MgaObject::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Minimum::meta, "Minimum", false, "Atom", NULL);

		::Uml::InitClassProps(MonolithDeployRequirement::meta, "MonolithDeployRequirement", false, "Connection", NULL);

		::Uml::InitClassProps(MonolithExecParameter::meta, "MonolithExecParameter", false, "Connection", NULL);

		::Uml::InitClassProps(MonolithicImplementation::meta, "MonolithicImplementation", false, "Atom", NULL);
		vector<string> MonolithicImplementation_defaultVersion_dva;
		MonolithicImplementation_defaultVersion_dva.push_back("0.0.0.0");
		::Uml::InitAttributeProps(MonolithicImplementation::meta_defaultVersion, "defaultVersion", "String", false, false, 1, 1, false, "public", MonolithicImplementation_defaultVersion_dva);

		::Uml::InitClassProps(MonolithicImplementationBase::meta, "MonolithicImplementationBase", true, "FCO", NULL);

		::Uml::InitClassProps(MonolithprimaryArtifact::meta, "MonolithprimaryArtifact", false, "Connection", NULL);

		::Uml::InitClassProps(MultiInput::meta, "MultiInput", false, "Connection", NULL);

		::Uml::InitClassProps(MultiInputAction::meta, "MultiInputAction", false, "Model", NULL);

		::Uml::InitClassProps(MultiInputBase::meta, "MultiInputBase", true, "FCO", NULL);

		::Uml::InitClassProps(MultiOutputBase::meta, "MultiOutputBase", true, "FCO", NULL);

		::Uml::InitClassProps(MultipleServiceRequests::meta, "MultipleServiceRequests", false, "Atom", NULL);
		vector<string> MultipleServiceRequests_simultaneous_service_execution_dva;
		MultipleServiceRequests_simultaneous_service_execution_dva.push_back("true");
		::Uml::InitAttributeProps(MultipleServiceRequests::meta_simultaneous_service_execution, "simultaneous_service_execution", "Boolean", false, false, 1, 1, false, "public", MultipleServiceRequests_simultaneous_service_execution_dva);
		vector<string> MultipleServiceRequests_minimum_simultaneous_service_level_dva;
		MultipleServiceRequests_minimum_simultaneous_service_level_dva.push_back("2");
		::Uml::InitAttributeProps(MultipleServiceRequests::meta_minimum_simultaneous_service_level, "minimum_simultaneous_service_level", "Integer", false, false, 1, 1, false, "public", MultipleServiceRequests_minimum_simultaneous_service_level_dva);
		vector<string> MultipleServiceRequests_buffer_service_requests_dva;
		MultipleServiceRequests_buffer_service_requests_dva.push_back("true");
		::Uml::InitAttributeProps(MultipleServiceRequests::meta_buffer_service_requests, "buffer_service_requests", "Boolean", false, false, 1, 1, false, "public", MultipleServiceRequests_buffer_service_requests_dva);
		vector<string> MultipleServiceRequests_maximum_simultaneous_service_level_dva;
		MultipleServiceRequests_maximum_simultaneous_service_level_dva.push_back("127");
		::Uml::InitAttributeProps(MultipleServiceRequests::meta_maximum_simultaneous_service_level, "maximum_simultaneous_service_level", "Integer", false, false, 1, 1, false, "public", MultipleServiceRequests_maximum_simultaneous_service_level_dva);

		::Uml::InitClassProps(NamedType::meta, "NamedType", true, "FCO", NULL);

		::Uml::InitClassProps(NoInheritable::meta, "NoInheritable", true, "FCO", NULL);

		::Uml::InitClassProps(Node::meta, "Node", false, "Model", NULL);
		::Uml::InitAttributeProps(Node::meta_operatingSystem, "operatingSystem", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(Node::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(Node::meta_architecture, "architecture", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(NodeReference::meta, "NodeReference", false, "Reference", NULL);

		::Uml::InitClassProps(Object::meta, "Object", false, "Model", NULL);
		vector<string> Object_local_dva;
		Object_local_dva.push_back("false");
		::Uml::InitAttributeProps(Object::meta_local, "local", "Boolean", false, false, 1, 1, false, "public", Object_local_dva);
		vector<string> Object_abstract_dva;
		Object_abstract_dva.push_back("false");
		::Uml::InitAttributeProps(Object::meta_abstract, "abstract", "Boolean", false, false, 1, 1, false, "public", Object_abstract_dva);

		::Uml::InitClassProps(ObjectByValue::meta, "ObjectByValue", true, "Model", NULL);
		vector<string> ObjectByValue_abstract_dva;
		ObjectByValue_abstract_dva.push_back("false");
		::Uml::InitAttributeProps(ObjectByValue::meta_abstract, "abstract", "Boolean", false, false, 1, 1, false, "public", ObjectByValue_abstract_dva);

		::Uml::InitClassProps(OnewayOperation::meta, "OnewayOperation", false, "Model", NULL);

		::Uml::InitClassProps(OperationBase::meta, "OperationBase", true, "Model", NULL);

		::Uml::InitClassProps(OperationRef::meta, "OperationRef", false, "Reference", NULL);

		::Uml::InitClassProps(OutEventPort::meta, "OutEventPort", false, "Reference", NULL);
		vector<string> OutEventPort_out_event_port_type_dva;
		OutEventPort_out_event_port_type_dva.push_back("DirectConnect");
		::Uml::InitAttributeProps(OutEventPort::meta_out_event_port_type, "out_event_port_type", "String", false, false, 1, 1, false, "public", OutEventPort_out_event_port_type_dva);
		vector<string> OutEventPort_single_destination_dva;
		OutEventPort_single_destination_dva.push_back("false");
		::Uml::InitAttributeProps(OutEventPort::meta_single_destination, "single_destination", "Boolean", false, false, 1, 1, false, "public", OutEventPort_single_destination_dva);

		::Uml::InitClassProps(OutParameter::meta, "OutParameter", false, "Reference", NULL);

		::Uml::InitClassProps(OutputAction::meta, "OutputAction", false, "Model", NULL);

		::Uml::InitClassProps(Package::meta, "Package", false, "Model", NULL);

		::Uml::InitClassProps(PackageConfBasePackage::meta, "PackageConfBasePackage", false, "Connection", NULL);

		::Uml::InitClassProps(PackageConfConfigProperty::meta, "PackageConfConfigProperty", false, "Connection", NULL);

		::Uml::InitClassProps(PackageConfReference::meta, "PackageConfReference", false, "Connection", NULL);

		::Uml::InitClassProps(PackageConfSelectRequirement::meta, "PackageConfSelectRequirement", false, "Connection", NULL);

		::Uml::InitClassProps(PackageConfSpecializedConfig::meta, "PackageConfSpecializedConfig", false, "Connection", NULL);

		::Uml::InitClassProps(PackageConfigProperty::meta, "PackageConfigProperty", false, "Connection", NULL);

		::Uml::InitClassProps(PackageConfiguration::meta, "PackageConfiguration", false, "Atom", NULL);
		::Uml::InitAttributeProps(PackageConfiguration::meta_UUID, "UUID", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(PackageConfiguration::meta_label, "label", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(PackageConfigurationContainer::meta, "PackageConfigurationContainer", false, "Model", NULL);

		::Uml::InitClassProps(PackageConfigurationReference::meta, "PackageConfigurationReference", false, "Reference", NULL);

		::Uml::InitClassProps(PackageConfigurations::meta, "PackageConfigurations", false, "Folder", NULL);
		::Uml::InitAttributeProps(PackageConfigurations::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(PackageContainer::meta, "PackageContainer", false, "Model", NULL);

		::Uml::InitClassProps(PackageInfoProperty::meta, "PackageInfoProperty", false, "Connection", NULL);

		::Uml::InitClassProps(PackageInterface::meta, "PackageInterface", false, "Connection", NULL);

		::Uml::InitClassProps(ParameterType::meta, "ParameterType", true, "Reference", NULL);

		::Uml::InitClassProps(Path::meta, "Path", false, "Model", NULL);

		::Uml::InitClassProps(PathDiagrams::meta, "PathDiagrams", false, "Folder", NULL);
		::Uml::InitAttributeProps(PathDiagrams::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(PathProperty::meta, "PathProperty", false, "Connection", NULL);

		::Uml::InitClassProps(PathReference::meta, "PathReference", false, "Reference", NULL);

		::Uml::InitClassProps(Paths::meta, "Paths", false, "Model", NULL);

		::Uml::InitClassProps(PeriodicBenchmarks::meta, "PeriodicBenchmarks", false, "Atom", NULL);
		::Uml::InitAttributeProps(PeriodicBenchmarks::meta_timeperiod, "timeperiod", "Integer", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(PeriodicEvent::meta, "PeriodicEvent", false, "Atom", NULL);
		vector<string> PeriodicEvent_Distribution_dva;
		PeriodicEvent_Distribution_dva.push_back("Constant");
		::Uml::InitAttributeProps(PeriodicEvent::meta_Distribution, "Distribution", "String", false, false, 1, 1, false, "public", PeriodicEvent_Distribution_dva);
		vector<string> PeriodicEvent_Hertz_dva;
		PeriodicEvent_Hertz_dva.push_back("10");
		::Uml::InitAttributeProps(PeriodicEvent::meta_Hertz, "Hertz", "String", false, false, 1, 1, false, "public", PeriodicEvent_Hertz_dva);

		::Uml::InitClassProps(Port::meta, "Port", true, "FCO", NULL);

		::Uml::InitClassProps(PredefinedType::meta, "PredefinedType", true, "FCO", NULL);

		::Uml::InitClassProps(PredefinedTypes::meta, "PredefinedTypes", false, "Folder", NULL);
		::Uml::InitAttributeProps(PredefinedTypes::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Prefixable::meta, "Prefixable", true, "Model", NULL);
		::Uml::InitAttributeProps(Prefixable::meta_PrefixTag, "PrefixTag", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(PrivateFlag::meta, "PrivateFlag", false, "Atom", NULL);

		::Uml::InitClassProps(Project::meta, "Project", false, "Model", NULL);

		::Uml::InitClassProps(Property::meta, "Property", false, "Model", NULL);
		::Uml::InitAttributeProps(Property::meta_DataValue, "DataValue", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Provideable::meta, "Provideable", true, "FCO", NULL);

		::Uml::InitClassProps(ProvidedRequestPort::meta, "ProvidedRequestPort", false, "Reference", NULL);

		::Uml::InitClassProps(PublishConnector::meta, "PublishConnector", false, "Atom", NULL);

		::Uml::InitClassProps(QueryAction::meta, "QueryAction", false, "Model", NULL);

		::Uml::InitClassProps(QueryInput::meta, "QueryInput", false, "Connection", NULL);

		::Uml::InitClassProps(QueryInputAction::meta, "QueryInputAction", false, "Model", NULL);

		::Uml::InitClassProps(QueryInputBase::meta, "QueryInputBase", true, "FCO", NULL);

		::Uml::InitClassProps(RTRequirements::meta, "RTRequirements", false, "Model", NULL);

		::Uml::InitClassProps(ReadonlyAttribute::meta, "ReadonlyAttribute", false, "Model", NULL);

		::Uml::InitClassProps(RealNumber::meta, "RealNumber", false, "Atom", NULL);

		::Uml::InitClassProps(ReceptacleDelegate::meta, "ReceptacleDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(RequiredRequestPort::meta, "RequiredRequestPort", false, "Reference", NULL);
		vector<string> RequiredRequestPort_multiple_connections_dva;
		RequiredRequestPort_multiple_connections_dva.push_back("false");
		::Uml::InitAttributeProps(RequiredRequestPort::meta_multiple_connections, "multiple_connections", "Boolean", false, false, 1, 1, false, "public", RequiredRequestPort_multiple_connections_dva);

		::Uml::InitClassProps(Requirement::meta, "Requirement", false, "Model", NULL);

		::Uml::InitClassProps(RequirementBase::meta, "RequirementBase", true, "Model", NULL);
		::Uml::InitAttributeProps(RequirementBase::meta_resourceType, "resourceType", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(RequirementSatisfier::meta, "RequirementSatisfier", true, "Model", NULL);
		::Uml::InitAttributeProps(RequirementSatisfier::meta_resourceType, "resourceType", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Resource::meta, "Resource", false, "Model", NULL);

		::Uml::InitClassProps(ReturnType::meta, "ReturnType", false, "Reference", NULL);

		::Uml::InitClassProps(RootFolder::meta, "RootFolder", false, "Folder", NULL);
		::Uml::InitAttributeProps(RootFolder::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(SatisfierProperty::meta, "SatisfierProperty", false, "Model", NULL);
		::Uml::InitAttributeProps(SatisfierProperty::meta_DataValue, "DataValue", "String", false, false, 1, 1, false, "public", vector<string>());
		vector<string> SatisfierProperty_SatisfierPropertyKind_dva;
		SatisfierProperty_SatisfierPropertyKind_dva.push_back("Quantity");
		::Uml::InitAttributeProps(SatisfierProperty::meta_SatisfierPropertyKind, "SatisfierPropertyKind", "String", false, false, 1, 1, false, "public", SatisfierProperty_SatisfierPropertyKind_dva);
		vector<string> SatisfierProperty_dynamic_dva;
		SatisfierProperty_dynamic_dva.push_back("false");
		::Uml::InitAttributeProps(SatisfierProperty::meta_dynamic, "dynamic", "Boolean", false, false, 1, 1, false, "public", SatisfierProperty_dynamic_dva);

		::Uml::InitClassProps(ServantProject::meta, "ServantProject", false, "Model", NULL);

		::Uml::InitClassProps(ServiceConsumer::meta, "ServiceConsumer", false, "Atom", NULL);
		vector<string> ServiceConsumer_prioritize_service_invocations_dva;
		ServiceConsumer_prioritize_service_invocations_dva.push_back("true");
		::Uml::InitAttributeProps(ServiceConsumer::meta_prioritize_service_invocations, "prioritize_service_invocations", "Boolean", false, false, 1, 1, false, "public", ServiceConsumer_prioritize_service_invocations_dva);

		::Uml::InitClassProps(ServiceLevels::meta, "ServiceLevels", false, "Atom", NULL);
		vector<string> ServiceLevels_varying_service_levels_dva;
		ServiceLevels_varying_service_levels_dva.push_back("true");
		::Uml::InitAttributeProps(ServiceLevels::meta_varying_service_levels, "varying_service_levels", "Boolean", false, false, 1, 1, false, "public", ServiceLevels_varying_service_levels_dva);

		::Uml::InitClassProps(ServiceProvider::meta, "ServiceProvider", false, "Model", NULL);
		vector<string> ServiceProvider_fixed_prioirty_service_execution_dva;
		ServiceProvider_fixed_prioirty_service_execution_dva.push_back("false");
		::Uml::InitAttributeProps(ServiceProvider::meta_fixed_prioirty_service_execution, "fixed_prioirty_service_execution", "Boolean", false, false, 1, 1, false, "public", ServiceProvider_fixed_prioirty_service_execution_dva);

		::Uml::InitClassProps(SetException::meta, "SetException", false, "Reference", NULL);

		::Uml::InitClassProps(SharedComponentReference::meta, "SharedComponentReference", false, "Reference", NULL);

		::Uml::InitClassProps(SharedResource::meta, "SharedResource", false, "Model", NULL);

		::Uml::InitClassProps(Shares::meta, "Shares", false, "Connection", NULL);

		::Uml::InitClassProps(ShortInteger::meta, "ShortInteger", false, "Atom", NULL);

		::Uml::InitClassProps(SingleInputBase::meta, "SingleInputBase", true, "FCO", NULL);

		::Uml::InitClassProps(SingleOutputBase::meta, "SingleOutputBase", true, "FCO", NULL);

		::Uml::InitClassProps(SrcEdge::meta, "SrcEdge", false, "Connection", NULL);

		::Uml::InitClassProps(State::meta, "State", false, "Atom", NULL);

		::Uml::InitClassProps(StateBase::meta, "StateBase", true, "Atom", NULL);

		::Uml::InitClassProps(String::meta, "String", false, "Atom", NULL);

		::Uml::InitClassProps(StubProject::meta, "StubProject", false, "Model", NULL);

		::Uml::InitClassProps(Supports::meta, "Supports", false, "Reference", NULL);

		::Uml::InitClassProps(SupportsDelegate::meta, "SupportsDelegate", false, "Connection", NULL);

		::Uml::InitClassProps(SupportsInterfaces::meta, "SupportsInterfaces", true, "Model", NULL);

		::Uml::InitClassProps(SwitchedAggregate::meta, "SwitchedAggregate", false, "Model", NULL);

		::Uml::InitClassProps(Taggable::meta, "Taggable", true, "FCO", NULL);
		::Uml::InitAttributeProps(Taggable::meta_SpecifyIdTag, "SpecifyIdTag", "String", false, false, 1, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(Taggable::meta_VersionTag, "VersionTag", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Targets::meta, "Targets", false, "Folder", NULL);
		::Uml::InitAttributeProps(Targets::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Task::meta, "Task", false, "Atom", NULL);

		::Uml::InitClassProps(TaskSet::meta, "TaskSet", false, "Set", NULL);
		vector<string> TaskSet_rate_dva;
		TaskSet_rate_dva.push_back("-1");
		::Uml::InitAttributeProps(TaskSet::meta_rate, "rate", "Integer", false, false, 1, 1, false, "public", TaskSet_rate_dva);
		vector<string> TaskSet_priority_dva;
		TaskSet_priority_dva.push_back("-1");
		::Uml::InitAttributeProps(TaskSet::meta_priority, "priority", "Integer", false, false, 1, 1, false, "public", TaskSet_priority_dva);

		::Uml::InitClassProps(Terminal::meta, "Terminal", false, "Atom", NULL);

		::Uml::InitClassProps(TerminalEffect::meta, "TerminalEffect", false, "Connection", NULL);

		::Uml::InitClassProps(TerminalTransition::meta, "TerminalTransition", false, "Connection", NULL);

		::Uml::InitClassProps(Throughput::meta, "Throughput", false, "Model", NULL);

		::Uml::InitClassProps(TimeProbe::meta, "TimeProbe", false, "Atom", NULL);

		::Uml::InitClassProps(TimerConnection::meta, "TimerConnection", false, "Connection", NULL);

		::Uml::InitClassProps(TimerEventSinkConn::meta, "TimerEventSinkConn", false, "Connection", NULL);

		::Uml::InitClassProps(TopLevelBehavior::meta, "TopLevelBehavior", true, "Model", NULL);

		::Uml::InitClassProps(TopLevelPackage::meta, "TopLevelPackage", false, "Atom", NULL);

		::Uml::InitClassProps(TopLevelPackageContainer::meta, "TopLevelPackageContainer", false, "Model", NULL);

		::Uml::InitClassProps(TopLevelPackages::meta, "TopLevelPackages", false, "Folder", NULL);
		::Uml::InitAttributeProps(TopLevelPackages::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Transition::meta, "Transition", false, "Connection", NULL);

		::Uml::InitClassProps(TriggerBenchmarks::meta, "TriggerBenchmarks", false, "Atom", NULL);

		::Uml::InitClassProps(TwowayOperation::meta, "TwowayOperation", false, "Model", NULL);

		::Uml::InitClassProps(TypeEncoding::meta, "TypeEncoding", false, "Atom", NULL);

		::Uml::InitClassProps(TypeKind::meta, "TypeKind", false, "Atom", NULL);

		::Uml::InitClassProps(ValueObject::meta, "ValueObject", false, "Model", NULL);

		::Uml::InitClassProps(Variable::meta, "Variable", false, "Reference", NULL);
		::Uml::InitAttributeProps(Variable::meta_InitialValue, "InitialValue", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(WhileState::meta, "WhileState", false, "Atom", NULL);

		::Uml::InitClassProps(WorkLoadOperationConnection::meta, "WorkLoadOperationConnection", false, "Connection", NULL);

		::Uml::InitClassProps(Worker::meta, "Worker", false, "Model", NULL);
		vector<string> Worker_Abstract_dva;
		Worker_Abstract_dva.push_back("false");
		::Uml::InitAttributeProps(Worker::meta_Abstract, "Abstract", "Boolean", false, false, 1, 1, false, "public", Worker_Abstract_dva);

		::Uml::InitClassProps(WorkerFile::meta, "WorkerFile", false, "Model", NULL);
		::Uml::InitAttributeProps(WorkerFile::meta_Location, "Location", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(WorkerLibraries::meta, "WorkerLibraries", false, "Folder", NULL);
		::Uml::InitAttributeProps(WorkerLibraries::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(WorkerLibrary::meta, "WorkerLibrary", false, "Model", NULL);
		::Uml::InitAttributeProps(WorkerLibrary::meta_Location, "Location", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(WorkerPackage::meta, "WorkerPackage", false, "Model", NULL);

		::Uml::InitClassProps(WorkerPackageBase::meta, "WorkerPackageBase", true, "Model", NULL);

		::Uml::InitClassProps(WorkerType::meta, "WorkerType", false, "Reference", NULL);

		::Uml::InitClassProps(WorkloadCharacteristics::meta, "WorkloadCharacteristics", false, "Connection", NULL);

		::Uml::InitClassProps(Workspaces::meta, "Workspaces", false, "Set", NULL);

		::Uml::InitClassProps(deliverTo::meta, "deliverTo", false, "Connection", NULL);

		::Uml::InitClassProps(emit::meta, "emit", false, "Connection", NULL);

		::Uml::InitClassProps(invoke::meta, "invoke", false, "Connection", NULL);

		::Uml::InitClassProps(package::meta, "package", false, "Connection", NULL);

		::Uml::InitClassProps(publish::meta, "publish", false, "Connection", NULL);

		// associations
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ImplementationArtifact::meta_referedbyComponentServantArtifact = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_referedbyComponentServantArtifact, "referedbyComponentServantArtifact", true, false, 0, -1);
			ComponentServantArtifact::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentServantArtifact::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ImplementationArtifact::meta_referedbyComponentImplemenationArtifact = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_referedbyComponentImplemenationArtifact, "referedbyComponentImplemenationArtifact", true, false, 0, -1);
			ComponentImplementationArtifact::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentImplementationArtifact::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "MonolithExecParameter");
			MonolithicImplementationBase::meta_dstMonolithExecParameter = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MonolithicImplementationBase::meta_dstMonolithExecParameter, "dstMonolithExecParameter", true, false, 0, -1);
			Property::meta_srcMonolithExecParameter = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcMonolithExecParameter, "srcMonolithExecParameter", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "MonolithDeployRequirement");
			MonolithicImplementationBase::meta_dstMonolithDeployRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MonolithicImplementationBase::meta_dstMonolithDeployRequirement, "dstMonolithDeployRequirement", true, false, 0, -1);
			ImplementationRequirement::meta_srcMonolithDeployRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationRequirement::meta_srcMonolithDeployRequirement, "srcMonolithDeployRequirement", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "MonolithprimaryArtifact");
			MonolithicImplementationBase::meta_dstMonolithprimaryArtifact = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MonolithicImplementationBase::meta_dstMonolithprimaryArtifact, "dstMonolithprimaryArtifact", true, false, 0, -1);
			ImplementationArtifactReference::meta_srcMonolithprimaryArtifact = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifactReference::meta_srcMonolithprimaryArtifact, "srcMonolithprimaryArtifact", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "InfoProperty");
			Implemenation::meta_dstInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Implemenation::meta_dstInfoProperty, "dstInfoProperty", true, false, 0, -1);
			Property::meta_srcInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcInfoProperty, "srcInfoProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ConfigProperty");
			Implemenation::meta_dstConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Implemenation::meta_dstConfigProperty, "dstConfigProperty", true, false, 0, -1);
			Property::meta_srcConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcConfigProperty, "srcConfigProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ComponentFactoryInstance::meta_referedbyComponentFactoryRef = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentFactoryInstance::meta_referedbyComponentFactoryRef, "referedbyComponentFactoryRef", true, false, 0, -1);
			ComponentFactoryRef::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentFactoryRef::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ComponentFactoryInstance::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentFactoryInstance::meta_ref, "ref", true, false, 0, 1);
			ComponentFactory::meta_referedbyComponentFactoryInstance = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentFactory::meta_referedbyComponentFactoryInstance, "referedbyComponentFactoryInstance", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ExternalPortReferenceType::meta_referedbyExternalPortReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ExternalPortReferenceType::meta_referedbyExternalPortReference, "referedbyExternalPortReference", true, false, 0, -1);
			ExternalPortReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ExternalPortReference::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ComponentAssembly::meta_referedbyComponentAssemblyReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentAssembly::meta_referedbyComponentAssemblyReference, "referedbyComponentAssemblyReference", true, false, 0, -1);
			ComponentAssemblyReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentAssemblyReference::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "CriticalPath");
			ComponentAssembly::meta_dstCriticalPath = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentAssembly::meta_dstCriticalPath, "dstCriticalPath", true, false, 0, 1);
			PathReference::meta_srcCriticalPath = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PathReference::meta_srcCriticalPath, "srcCriticalPath", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ExternalDelegate");
			ExternalPortReference::meta_dstExternalDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ExternalPortReference::meta_dstExternalDelegate, "dstExternalDelegate", true, false, 0, -1);
			Port::meta_srcExternalDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Port::meta_srcExternalDelegate, "srcExternalDelegate", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Path::meta_referedbyPathReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Path::meta_referedbyPathReference, "referedbyPathReference", true, false, 0, -1);
			PathReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PathReference::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PathProperty");
			Path::meta_dstPathProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Path::meta_dstPathProperty, "dstPathProperty", true, false, 0, -1);
			Property::meta_srcPathProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcPathProperty, "srcPathProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "SrcEdge");
			GraphVertex::meta_srcSrcEdge = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(GraphVertex::meta_srcSrcEdge, "srcSrcEdge", true, false, 0, 1);
			Edge::meta_dstSrcEdge = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Edge::meta_dstSrcEdge, "dstSrcEdge", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "DstEdge");
			GraphVertex::meta_dstDstEdge = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(GraphVertex::meta_dstDstEdge, "dstDstEdge", true, false, 0, 1);
			Edge::meta_srcDstEdge = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Edge::meta_srcDstEdge, "srcDstEdge", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "EdgeProperty");
			Edge::meta_srcPropertyConnector = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Edge::meta_srcPropertyConnector, "srcPropertyConnector", true, false, 0, -1);
			Property::meta_dstPropertyConnector = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_dstPropertyConnector, "dstPropertyConnector", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "TimerEventSinkConn");
			TimeProbe::meta_srcTimerEventSinkConn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(TimeProbe::meta_srcTimerEventSinkConn, "srcTimerEventSinkConn", true, false, 0, 1);
			EventRef::meta_dstTimerEventSinkConn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(EventRef::meta_dstTimerEventSinkConn, "dstTimerEventSinkConn", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "TimerConnection");
			TimeProbe::meta_srcTimerConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(TimeProbe::meta_srcTimerConnection, "srcTimerConnection", true, false, 0, 1);
			OperationRef::meta_dstTimerConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OperationRef::meta_dstTimerConnection, "dstTimerConnection", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "MetricConnection");
			MetricsBase::meta_srcMetricConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MetricsBase::meta_srcMetricConnection, "srcMetricConnection", true, false, 1, 1);
			OperationRef::meta_dstMetricConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OperationRef::meta_dstMetricConnection, "dstMetricConnection", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "WorkloadCharacteristics");
			MetricsBase::meta_dstWorkloadCharacteristics = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MetricsBase::meta_dstWorkloadCharacteristics, "dstWorkloadCharacteristics", true, false, 0, 1);
			TaskSet::meta_srcWorkloadCharacteristics = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(TaskSet::meta_srcWorkloadCharacteristics, "srcWorkloadCharacteristics", true, false, 1, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "BenchmarkCharacteristics");
			MetricsBase::meta_srcBenchmarkCharacteristics = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MetricsBase::meta_srcBenchmarkCharacteristics, "srcBenchmarkCharacteristics", true, false, 0, 1);
			BenchmarkType::meta_dstBenchmarkCharacteristics = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(BenchmarkType::meta_dstBenchmarkCharacteristics, "dstBenchmarkCharacteristics", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ComponentOperation");
			OperationRef::meta_dstComponentOperation = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OperationRef::meta_dstComponentOperation, "dstComponentOperation", true, false, 0, 1);
			CompRef::meta_srcComponentOperation = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(CompRef::meta_srcComponentOperation, "srcComponentOperation", true, false, 1, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "WorkLoadOperationConnection");
			OperationRef::meta_dstWorkLoadOperationConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OperationRef::meta_dstWorkLoadOperationConnection, "dstWorkLoadOperationConnection", true, false, 0, 1);
			Task::meta_srcWorkLoadOperationConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Task::meta_srcWorkLoadOperationConnection, "srcWorkLoadOperationConnection", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			OperationRef::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OperationRef::meta_ref, "ref", true, false, 0, 1);
			OperationBase::meta_referedbyOperationRef = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OperationBase::meta_referedbyOperationRef, "referedbyOperationRef", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			EventRef::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(EventRef::meta_ref, "ref", true, false, 0, 1);
			Event::meta_referedbyEventRef = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Event::meta_referedbyEventRef, "referedbyEventRef", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			TaskSet::meta_members = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(TaskSet::meta_members, "members", true, false, 0, -1);
			Task::meta_setTaskSet = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Task::meta_setTaskSet, "setTaskSet", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			CompRef::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(CompRef::meta_ref, "ref", true, false, 0, 1);
			Component::meta_referedbyCompRef = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Component::meta_referedbyCompRef, "referedbyCompRef", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "InstanceMapping");
			NodeReference::meta_srcInstanceMapping = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(NodeReference::meta_srcInstanceMapping, "srcInstanceMapping", true, false, 0, -1);
			CollocationGroup::meta_dstInstanceMapping = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(CollocationGroup::meta_dstInstanceMapping, "dstInstanceMapping", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			NodeReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(NodeReference::meta_ref, "ref", true, false, 0, 1);
			Node::meta_referedbyNodeReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Node::meta_referedbyNodeReference, "referedbyNodeReference", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "InterconnectConnection");
			Interconnect::meta_srcInterconnectConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Interconnect::meta_srcInterconnectConnection, "srcInterconnectConnection", true, false, 0, -1);
			Node::meta_dstInterconnectConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Node::meta_dstInterconnectConnection, "dstInterconnectConnection", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "BridgeConnection");
			Interconnect::meta_dstBridgeConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Interconnect::meta_dstBridgeConnection, "dstBridgeConnection", true, false, 0, -1);
			Bridge::meta_srcBridgeConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Bridge::meta_srcBridgeConnection, "srcBridgeConnection", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Shares");
			Node::meta_dstShares = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Node::meta_dstShares, "dstShares", true, false, 0, -1);
			SharedResource::meta_srcShares = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(SharedResource::meta_srcShares, "srcShares", true, false, 1, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			CollocationGroup::meta_members = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(CollocationGroup::meta_members, "members", true, false, 0, -1);
			CollocationGroupMember::meta_setCollocationGroup = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(CollocationGroupMember::meta_setCollocationGroup, "setCollocationGroup", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ComponentRef::meta_referedbySharedComponentReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_referedbySharedComponentReference, "referedbySharedComponentReference", true, false, 0, -1);
			SharedComponentReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(SharedComponentReference::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Deploys");
			ComponentFactoryRef::meta_dstDeploys = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentFactoryRef::meta_dstDeploys, "dstDeploys", true, false, 0, -1);
			ComponentRef::meta_srcDeploys = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_srcDeploys, "srcDeploys", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "AssemblyDeployRequirement");
			PublishConnector::meta_dstAssemblyDeployRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PublishConnector::meta_dstAssemblyDeployRequirement, "dstAssemblyDeployRequirement", true, false, 0, -1);
			Requirement::meta_srcAssemblyDeployRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Requirement::meta_srcAssemblyDeployRequirement, "srcAssemblyDeployRequirement", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "deliverTo");
			PublishConnector::meta_dstdeliverTo = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PublishConnector::meta_dstdeliverTo, "dstdeliverTo", true, false, 0, -1);
			InEventPort::meta_srcdeliverTo = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InEventPort::meta_srcdeliverTo, "srcdeliverTo", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "publish");
			PublishConnector::meta_srcpublish = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PublishConnector::meta_srcpublish, "srcpublish", true, false, 0, 1);
			OutEventPort::meta_dstpublish = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OutEventPort::meta_dstpublish, "dstpublish", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "AttributeMappingValue");
			AttributeMapping::meta_dstAttributeMappingValue = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(AttributeMapping::meta_dstAttributeMappingValue, "dstAttributeMappingValue", true, false, 0, 1);
			Property::meta_srcAttributeMappingValue = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcAttributeMappingValue, "srcAttributeMappingValue", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "AttributeDelegate");
			AttributeMapping::meta_dstAttributeDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(AttributeMapping::meta_dstAttributeDelegate, "dstAttributeDelegate", true, false, 0, -1);
			ReadonlyAttribute::meta_srcAttributeDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ReadonlyAttribute::meta_srcAttributeDelegate, "srcAttributeDelegate", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "AttributeMappingDelegate");
			AttributeMapping::meta_dstAttributeMappingDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(AttributeMapping::meta_dstAttributeMappingDelegate, "dstAttributeMappingDelegate", true, false, 0, -1);
			AttributeMapping::meta_srcAttributeMappingDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(AttributeMapping::meta_srcAttributeMappingDelegate, "srcAttributeMappingDelegate", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			AttributeMapping::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(AttributeMapping::meta_ref, "ref", true, false, 0, 1);
			ReadonlyAttribute::meta_referedbyAttributeMapping = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ReadonlyAttribute::meta_referedbyAttributeMapping, "referedbyAttributeMapping", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "invoke");
			InvokePortBase::meta_srcinvoke = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InvokePortBase::meta_srcinvoke, "srcinvoke", true, false, 0, -1);
			RequiredRequestPort::meta_dstinvoke = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(RequiredRequestPort::meta_dstinvoke, "dstinvoke", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ImplementationDependsOn");
			ComponentImplementation::meta_dstImplementationDependsOn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentImplementation::meta_dstImplementationDependsOn, "dstImplementationDependsOn", true, false, 0, -1);
			ImplementationDependency::meta_srcImplementationDependsOn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationDependency::meta_srcImplementationDependsOn, "srcImplementationDependsOn", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ImplementationCapability");
			ComponentImplementation::meta_dstImplementationCapability = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentImplementation::meta_dstImplementationCapability, "dstImplementationCapability", true, false, 0, -1);
			Capability::meta_srcImplementationCapability = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Capability::meta_srcImplementationCapability, "srcImplementationCapability", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Implements");
			ComponentImplementation::meta_dstImplements = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentImplementation::meta_dstImplements, "dstImplements", true, false, 0, 1);
			ComponentRef::meta_srcImplements = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_srcImplements, "srcImplements", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ComponentImplementation::meta_referedbyComponentImplementationReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentImplementation::meta_referedbyComponentImplementationReference, "referedbyComponentImplementationReference", true, false, 0, -1);
			ComponentImplementationReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentImplementationReference::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Implementation");
			ComponentImplementationReference::meta_srcImplementation = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentImplementationReference::meta_srcImplementation, "srcImplementation", true, false, 0, -1);
			ComponentPackage::meta_dstImplementation = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackage::meta_dstImplementation, "dstImplementation", true, false, 1, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageConfSpecializedConfig");
			PackageConfigurationReference::meta_srcPackageConfSpecializedConfig = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfigurationReference::meta_srcPackageConfSpecializedConfig, "srcPackageConfSpecializedConfig", true, false, 0, -1);
			PackageConfiguration::meta_dstPackageConfSpecializedConfig = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfiguration::meta_dstPackageConfSpecializedConfig, "dstPackageConfSpecializedConfig", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			PackageConfigurationReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfigurationReference::meta_ref, "ref", true, false, 0, 1);
			PackageConfiguration::meta_referedbyPackageConfigurationReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfiguration::meta_referedbyPackageConfigurationReference, "referedbyPackageConfigurationReference", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "package");
			PackageConfigurationReference::meta_srcpackage = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfigurationReference::meta_srcpackage, "srcpackage", true, false, 1, 1);
			TopLevelPackage::meta_dstpackage = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(TopLevelPackage::meta_dstpackage, "dstpackage", true, false, 1, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageConfBasePackage");
			PackageConfiguration::meta_dstPackageConfBasePackage = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfiguration::meta_dstPackageConfBasePackage, "dstPackageConfBasePackage", true, false, 0, 1);
			ComponentPackage::meta_srcPackageConfBasePackage = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackage::meta_srcPackageConfBasePackage, "srcPackageConfBasePackage", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageConfReference");
			PackageConfiguration::meta_dstPackageConfReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfiguration::meta_dstPackageConfReference, "dstPackageConfReference", true, false, 0, 1);
			ComponentPackageReference::meta_srcPackageConfReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackageReference::meta_srcPackageConfReference, "srcPackageConfReference", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageConfSelectRequirement");
			PackageConfiguration::meta_dstPackageConfSelectRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfiguration::meta_dstPackageConfSelectRequirement, "dstPackageConfSelectRequirement", true, false, 0, -1);
			Requirement::meta_srcPackageConfSelectRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Requirement::meta_srcPackageConfSelectRequirement, "srcPackageConfSelectRequirement", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageConfConfigProperty");
			PackageConfiguration::meta_dstPackageConfConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PackageConfiguration::meta_dstPackageConfConfigProperty, "dstPackageConfConfigProperty", true, false, 0, -1);
			Property::meta_srcPackageConfConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcPackageConfConfigProperty, "srcPackageConfConfigProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ImplementationArtifactReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifactReference::meta_ref, "ref", true, false, 0, 1);
			ImplementationArtifact::meta_referedbyImplementationArtifactReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_referedbyImplementationArtifactReference, "referedbyImplementationArtifactReference", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ArtifactDependsOn");
			ImplementationArtifactReference::meta_srcArtifactDependsOn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifactReference::meta_srcArtifactDependsOn, "srcArtifactDependsOn", true, false, 0, -1);
			ImplementationArtifact::meta_dstArtifactDependsOn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_dstArtifactDependsOn, "dstArtifactDependsOn", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ArtifactDeployRequirement");
			ImplementationArtifact::meta_dstArtifactDeployRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_dstArtifactDeployRequirement, "dstArtifactDeployRequirement", true, false, 0, -1);
			Requirement::meta_srcArtifactDeployRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Requirement::meta_srcArtifactDeployRequirement, "srcArtifactDeployRequirement", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ArtifactExecParameter");
			ImplementationArtifact::meta_dstArtifactExecParameter = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_dstArtifactExecParameter, "dstArtifactExecParameter", true, false, 0, -1);
			Property::meta_srcArtifactExecParameter = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcArtifactExecParameter, "srcArtifactExecParameter", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ArtifactInfoProperty");
			ImplementationArtifact::meta_dstArtifactInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_dstArtifactInfoProperty, "dstArtifactInfoProperty", true, false, 0, -1);
			Property::meta_srcArtifactInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcArtifactInfoProperty, "srcArtifactInfoProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ArtifactDependency");
			ImplementationArtifact::meta_dstArtifactDependency = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_dstArtifactDependency, "dstArtifactDependency", true, false, 0, -1);
			ImplementationArtifact::meta_srcArtifactDependency = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_srcArtifactDependency, "srcArtifactDependency", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ImplementationArtifact::meta_referedbyExternalResources = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ImplementationArtifact::meta_referedbyExternalResources, "referedbyExternalResources", true, false, 0, -1);
			ExternalResources::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ExternalResources::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ComponentProperty");
			ComponentPropertyDescription::meta_srcComponentProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPropertyDescription::meta_srcComponentProperty, "srcComponentProperty", true, false, 0, -1);
			ComponentRef::meta_dstComponentProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_dstComponentProperty, "dstComponentProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageInterface");
			ComponentPackage::meta_dstPackageInterface = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackage::meta_dstPackageInterface, "dstPackageInterface", true, false, 0, 1);
			ComponentRef::meta_srcPackageInterface = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_srcPackageInterface, "srcPackageInterface", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageConfigProperty");
			ComponentPackage::meta_dstPackageConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackage::meta_dstPackageConfigProperty, "dstPackageConfigProperty", true, false, 0, -1);
			Property::meta_srcPackageConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcPackageConfigProperty, "srcPackageConfigProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "PackageInfoProperty");
			ComponentPackage::meta_dstPackageInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackage::meta_dstPackageInfoProperty, "dstPackageInfoProperty", true, false, 0, -1);
			Property::meta_srcPackageInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcPackageInfoProperty, "srcPackageInfoProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ComponentPackage::meta_referedbyComponentPackageReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackage::meta_referedbyComponentPackageReference, "referedbyComponentPackageReference", true, false, 0, -1);
			ComponentPackageReference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentPackageReference::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "AssemblyselectRequirement");
			Requirement::meta_srcAssemblyselectRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Requirement::meta_srcAssemblyselectRequirement, "srcAssemblyselectRequirement", true, false, 0, -1);
			Component::meta_dstAssemblyselectRequirement = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Component::meta_dstAssemblyselectRequirement, "dstAssemblyselectRequirement", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyDataType = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyDataType, "referedbyDataType", true, false, 0, -1);
			DataType::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(DataType::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ComponentConfigProperty");
			Property::meta_srcComponentConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcComponentConfigProperty, "srcComponentConfigProperty", true, false, 0, -1);
			ComponentRef::meta_dstComponentConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_dstComponentConfigProperty, "dstComponentConfigProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ComponentInfoProperty");
			Property::meta_srcComponentInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcComponentInfoProperty, "srcComponentInfoProperty", true, false, 0, -1);
			ComponentRef::meta_dstComponentInfoProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_dstComponentInfoProperty, "dstComponentInfoProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "AssemblyConfigProperty");
			Property::meta_srcAssemblyConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcAssemblyConfigProperty, "srcAssemblyConfigProperty", true, false, 0, -1);
			Component::meta_dstAssemblyConfigProperty = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Component::meta_dstAssemblyConfigProperty, "dstAssemblyConfigProperty", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "AttributeValue");
			Property::meta_srcAttributeValue = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Property::meta_srcAttributeValue, "srcAttributeValue", true, false, 0, -1);
			ReadonlyAttribute::meta_dstAttributeValue = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ReadonlyAttribute::meta_dstAttributeValue, "dstAttributeValue", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ManagesComponent");
			Manageable::meta_srcManagesComponent = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Manageable::meta_srcManagesComponent, "srcManagesComponent", true, false, 0, -1);
			ComponentFactory::meta_dstManagesComponent = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentFactory::meta_dstManagesComponent, "dstManagesComponent", true, false, 1, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Provideable::meta_referedbyRequiredRequestPort = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Provideable::meta_referedbyRequiredRequestPort, "referedbyRequiredRequestPort", true, false, 0, -1);
			RequiredRequestPort::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(RequiredRequestPort::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Provideable::meta_referedbyProvidedRequestPort = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Provideable::meta_referedbyProvidedRequestPort, "referedbyProvidedRequestPort", true, false, 0, -1);
			ProvidedRequestPort::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ProvidedRequestPort::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ComponentRef::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentRef::meta_ref, "ref", true, false, 0, 1);
			Component::meta_referedbyComponentRef = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Component::meta_referedbyComponentRef, "referedbyComponentRef", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "FacetDelegate");
			ProvidedRequestPort::meta_dstFacetDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ProvidedRequestPort::meta_dstFacetDelegate, "dstFacetDelegate", true, false, 0, -1);
			ProvidedRequestPort::meta_srcFacetDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ProvidedRequestPort::meta_srcFacetDelegate, "srcFacetDelegate", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "SupportsDelegate");
			ProvidedRequestPort::meta_srcSupportsDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ProvidedRequestPort::meta_srcSupportsDelegate, "srcSupportsDelegate", true, false, 0, -1);
			Supports::meta_dstSupportsDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Supports::meta_dstSupportsDelegate, "dstSupportsDelegate", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			InEventPort::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InEventPort::meta_ref, "ref", true, false, 0, 1);
			Event::meta_referedbyInEventPort = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Event::meta_referedbyInEventPort, "referedbyInEventPort", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "EventSinkDelegate");
			InEventPort::meta_dstEventSinkDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InEventPort::meta_dstEventSinkDelegate, "dstEventSinkDelegate", true, false, 0, -1);
			InEventPort::meta_srcEventSinkDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InEventPort::meta_srcEventSinkDelegate, "srcEventSinkDelegate", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "emit");
			InEventPort::meta_srcemit = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InEventPort::meta_srcemit, "srcemit", true, false, 0, -1);
			OutEventPort::meta_dstemit = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OutEventPort::meta_dstemit, "dstemit", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			OutEventPort::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OutEventPort::meta_ref, "ref", true, false, 0, 1);
			Event::meta_referedbyOutEventPort = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Event::meta_referedbyOutEventPort, "referedbyOutEventPort", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "EventSourceDelegate");
			OutEventPort::meta_dstEventSourceDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OutEventPort::meta_dstEventSourceDelegate, "dstEventSourceDelegate", true, false, 0, -1);
			OutEventPort::meta_srcEventSourceDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OutEventPort::meta_srcEventSourceDelegate, "srcEventSourceDelegate", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ReceptacleDelegate");
			RequiredRequestPort::meta_dstReceptacleDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(RequiredRequestPort::meta_dstReceptacleDelegate, "dstReceptacleDelegate", true, false, 0, -1);
			RequiredRequestPort::meta_srcReceptacleDelegate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(RequiredRequestPort::meta_srcReceptacleDelegate, "srcReceptacleDelegate", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyInParameter = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyInParameter, "referedbyInParameter", true, false, 0, -1);
			InParameter::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InParameter::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyInoutParameter = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyInoutParameter, "referedbyInoutParameter", true, false, 0, -1);
			InoutParameter::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InoutParameter::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyOutParameter = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyOutParameter, "referedbyOutParameter", true, false, 0, -1);
			OutParameter::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(OutParameter::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyReturnType = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyReturnType, "referedbyReturnType", true, false, 0, -1);
			ReturnType::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ReturnType::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyParameterType = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyParameterType, "referedbyParameterType", true, false, 0, -1);
			ParameterType::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ParameterType::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Object::meta_referedbySupports = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Object::meta_referedbySupports, "referedbySupports", true, false, 0, -1);
			Supports::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Supports::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Inheritable::meta_referedbyInherits = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Inheritable::meta_referedbyInherits, "referedbyInherits", true, false, 0, -1);
			Inherits::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Inherits::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ValueObject::meta_referedbyLookupKey = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ValueObject::meta_referedbyLookupKey, "referedbyLookupKey", true, false, 0, -1);
			LookupKey::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(LookupKey::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Exception::meta_referedbySetException = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Exception::meta_referedbySetException, "referedbySetException", true, false, 0, -1);
			SetException::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(SetException::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Exception::meta_referedbyGetException = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Exception::meta_referedbyGetException, "referedbyGetException", true, false, 0, -1);
			GetException::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(GetException::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "MakeMemberPrivate");
			PrivateFlag::meta_srcMakeMemberPrivate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PrivateFlag::meta_srcMakeMemberPrivate, "srcMakeMemberPrivate", true, false, 1, 1);
			Member::meta_dstMakeMemberPrivate = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Member::meta_dstMakeMemberPrivate, "dstMakeMemberPrivate", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyAttributeMember = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyAttributeMember, "referedbyAttributeMember", true, false, 0, -1);
			AttributeMember::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(AttributeMember::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "LabelConnection");
			Label::meta_srcLabelConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Label::meta_srcLabelConnection, "srcLabelConnection", true, false, 1, 1);
			Member::meta_dstLabelConnection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Member::meta_dstLabelConnection, "dstLabelConnection", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyAlias = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyAlias, "referedbyAlias", true, false, 0, -1);
			Alias::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Alias::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyBoxed = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyBoxed, "referedbyBoxed", true, false, 0, -1);
			Boxed::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Boxed::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyCollection = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyCollection, "referedbyCollection", true, false, 0, -1);
			Collection::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Collection::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			MemberType::meta_referedbyMember = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MemberType::meta_referedbyMember, "referedbyMember", true, false, 0, -1);
			Member::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Member::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ConstantType::meta_referedbyDiscriminator = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ConstantType::meta_referedbyDiscriminator, "referedbyDiscriminator", true, false, 0, -1);
			Discriminator::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Discriminator::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			PredefinedType::meta_referedbyVariable = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(PredefinedType::meta_referedbyVariable, "referedbyVariable", true, false, 0, -1);
			Variable::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Variable::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			File::meta_referedbyFileRef = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(File::meta_referedbyFileRef, "referedbyFileRef", true, false, 0, -1);
			FileRef::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(FileRef::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Exception::meta_referedbyExceptionRef = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Exception::meta_referedbyExceptionRef, "referedbyExceptionRef", true, false, 0, -1);
			ExceptionRef::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ExceptionRef::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			ConstantType::meta_referedbyConstant = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ConstantType::meta_referedbyConstant, "referedbyConstant", true, false, 0, -1);
			Constant::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Constant::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Workspaces::meta_members = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Workspaces::meta_members, "members", true, false, 0, -1);
			Project::meta_setWorkspace = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Project::meta_setWorkspace, "setWorkspace", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "ExtResourceConn");
			ExternalResources::meta_srcExtResourceConn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ExternalResources::meta_srcExtResourceConn, "srcExtResourceConn", true, false, 0, -1);
			ComponentLib::meta_dstExtResourceConn = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ComponentLib::meta_dstExtResourceConn, "dstExtResourceConn", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			Worker::meta_referedbyWorkerType = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Worker::meta_referedbyWorkerType, "referedbyWorkerType", true, false, 0, -1);
			WorkerType::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(WorkerType::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Finish");
			BehaviorInputAction::meta_srcFinish = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(BehaviorInputAction::meta_srcFinish, "srcFinish", true, false, 0, 1);
			StateBase::meta_dstFinish = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(StateBase::meta_dstFinish, "dstFinish", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "InputEffect");
			BehaviorInputAction::meta_dstInputEffect = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(BehaviorInputAction::meta_dstInputEffect, "dstInputEffect", true, false, 0, 1);
			StateBase::meta_srcInputEffect = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(StateBase::meta_srcInputEffect, "srcInputEffect", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Input");
			InputAction::meta_srcInput = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(InputAction::meta_srcInput, "srcInput", true, false, 0, 1);
			SingleInputBase::meta_dstInput = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(SingleInputBase::meta_dstInput, "dstInput", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "QueryInput");
			QueryInputAction::meta_srcQueryInput = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(QueryInputAction::meta_srcQueryInput, "srcQueryInput", true, false, 0, 1);
			QueryInputBase::meta_dstQueryInput = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(QueryInputBase::meta_dstQueryInput, "dstQueryInput", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "MultiInput");
			MultiInputAction::meta_srcMultiInput = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MultiInputAction::meta_srcMultiInput, "srcMultiInput", true, false, 0, 1);
			MultiInputBase::meta_dstMultiInput = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(MultiInputBase::meta_dstMultiInput, "dstMultiInput", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "BranchTransition");
			ActionBase::meta_srcBranchTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ActionBase::meta_srcBranchTransition, "srcBranchTransition", true, false, 0, 1);
			BranchState::meta_dstBranchTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(BranchState::meta_dstBranchTransition, "dstBranchTransition", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Effect");
			ActionBase::meta_dstEffect = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ActionBase::meta_dstEffect, "dstEffect", true, false, 0, 1);
			StateBase::meta_srcEffect = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(StateBase::meta_srcEffect, "srcEffect", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "LoopTransition");
			ActionBase::meta_srcLoopTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ActionBase::meta_srcLoopTransition, "srcLoopTransition", true, false, 0, 1);
			LoopState::meta_dstLoopTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(LoopState::meta_dstLoopTransition, "dstLoopTransition", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Transition");
			ActionBase::meta_srcTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(ActionBase::meta_srcTransition, "srcTransition", true, false, 0, 1);
			State::meta_dstTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(State::meta_dstTransition, "dstTransition", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "TerminalTransition");
			State::meta_dstTerminalTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(State::meta_dstTerminalTransition, "dstTerminalTransition", true, false, 0, 1);
			Terminal::meta_srcTerminalTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Terminal::meta_srcTerminalTransition, "srcTerminalTransition", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "TerminalEffect");
			StateBase::meta_srcTerminalEffect = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(StateBase::meta_srcTerminalEffect, "srcTerminalEffect", true, false, 0, 1);
			Terminal::meta_dstTerminalEffect = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Terminal::meta_dstTerminalEffect, "dstTerminalEffect", true, false, 0, 1);

		}

		// compositions
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ConfigProperty::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ConfigProperty::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_ConfigProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_ConfigProperty_children, "ConfigProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InfoProperty::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InfoProperty::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_InfoProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_InfoProperty_children, "InfoProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MonolithprimaryArtifact::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MonolithprimaryArtifact::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_MonolithprimaryArtifact_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_MonolithprimaryArtifact_children, "MonolithprimaryArtifact", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MonolithDeployRequirement::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MonolithDeployRequirement::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_MonolithDeployRequirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_MonolithDeployRequirement_children, "MonolithDeployRequirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MonolithExecParameter::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MonolithExecParameter::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_MonolithExecParameter_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_MonolithExecParameter_children, "MonolithExecParameter", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifactReference::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifactReference::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_ImplementationArtifactReference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_ImplementationArtifactReference_children, "ImplementationArtifactReference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationRequirement::meta_ImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationRequirement::meta_ImplementationContainer_parent, "ImplementationContainer_parent", true);
			ImplementationContainer::meta_ImplementationRequirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationContainer::meta_ImplementationRequirement_children, "ImplementationRequirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentFactoryImplementationContainer::meta_ComponentFactoryImplementations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentFactoryImplementationContainer::meta_ComponentFactoryImplementations_parent, "ComponentFactoryImplementations_parent", true);
			ComponentFactoryImplementations::meta_ComponentFactoryImplementationContainer_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentFactoryImplementations::meta_ComponentFactoryImplementationContainer_children, "ComponentFactoryImplementationContainer", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentFactoryInstance::meta_ComponentFactoryImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentFactoryInstance::meta_ComponentFactoryImplementationContainer_parent, "ComponentFactoryImplementationContainer_parent", true);
			ComponentFactoryImplementationContainer::meta_ComponentFactoryInstance_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentFactoryImplementationContainer::meta_ComponentFactoryInstance_children, "ComponentFactoryInstance", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ServiceProvider::meta_RTRequirements_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ServiceProvider::meta_RTRequirements_parent, "RTRequirements_parent", true);
			RTRequirements::meta_ServiceProvider_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RTRequirements::meta_ServiceProvider_child, "ServiceProvider", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ServiceConsumer::meta_RTRequirements_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ServiceConsumer::meta_RTRequirements_parent, "RTRequirements_parent", true);
			RTRequirements::meta_ServiceConsumer_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RTRequirements::meta_ServiceConsumer_child, "ServiceConsumer", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ServiceLevels::meta_ServiceProvider_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ServiceLevels::meta_ServiceProvider_parent, "ServiceProvider_parent", true);
			ServiceProvider::meta_ServiceLevels_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ServiceProvider::meta_ServiceLevels_child, "ServiceLevels", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MultipleServiceRequests::meta_ServiceProvider_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MultipleServiceRequests::meta_ServiceProvider_parent, "ServiceProvider_parent", true);
			ServiceProvider::meta_MultipleServiceRequests_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ServiceProvider::meta_MultipleServiceRequests_child, "MultipleServiceRequests", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ECRole::meta_ECRequirements_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ECRole::meta_ECRequirements_parent, "ECRequirements_parent", true);
			ECRequirements::meta_ECRole_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ECRequirements::meta_ECRole_children, "ECRole", true, 2, 2);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ECBehavior::meta_ECRequirements_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ECBehavior::meta_ECRequirements_parent, "ECRequirements_parent", true);
			ECRequirements::meta_ECBehavior_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ECRequirements::meta_ECBehavior_child, "ECBehavior", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentPackage::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentPackage::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ComponentPackage_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ComponentPackage_children, "ComponentPackage", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentPackageReference::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentPackageReference::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ComponentPackageReference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ComponentPackageReference_children, "ComponentPackageReference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Requirement::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Requirement::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_Requirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_Requirement_children, "Requirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Component::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Component::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_Component_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_Component_children, "Component", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentAssembly::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentAssembly::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ComponentAssembly_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ComponentAssembly_children, "ComponentAssembly", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ProvidedRequestPort::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ProvidedRequestPort::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ProvidedRequestPort_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ProvidedRequestPort_children, "ProvidedRequestPort", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			RequiredRequestPort::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(RequiredRequestPort::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_RequiredRequestPort_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_RequiredRequestPort_children, "RequiredRequestPort", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InEventPort::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InEventPort::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_InEventPort_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_InEventPort_children, "InEventPort", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			OutEventPort::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(OutEventPort::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_OutEventPort_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_OutEventPort_children, "OutEventPort", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			emit::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(emit::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_emit_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_emit_children, "emit", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			EventSourceDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(EventSourceDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_EventSourceDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_EventSourceDelegate_children, "EventSourceDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			EventSinkDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(EventSinkDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_EventSinkDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_EventSinkDelegate_children, "EventSinkDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			deliverTo::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(deliverTo::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_deliverTo_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_deliverTo_children, "deliverTo", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			publish::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(publish::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_publish_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_publish_children, "publish", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AssemblyDeployRequirement::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AssemblyDeployRequirement::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AssemblyDeployRequirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AssemblyDeployRequirement_children, "AssemblyDeployRequirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentAssemblyReference::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentAssemblyReference::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ComponentAssemblyReference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ComponentAssemblyReference_children, "ComponentAssemblyReference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentRef::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentRef::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ComponentRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ComponentRef_children, "ComponentRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AssemblyselectRequirement::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AssemblyselectRequirement::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AssemblyselectRequirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AssemblyselectRequirement_children, "AssemblyselectRequirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AttributeValue::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AttributeValue::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AttributeValue_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AttributeValue_children, "AttributeValue", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AttributeDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AttributeDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AttributeDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AttributeDelegate_children, "AttributeDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AttributeMappingValue::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AttributeMappingValue::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AttributeMappingValue_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AttributeMappingValue_children, "AttributeMappingValue", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AssemblyConfigProperty::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AssemblyConfigProperty::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AssemblyConfigProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AssemblyConfigProperty_children, "AssemblyConfigProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			FacetDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(FacetDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_FacetDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_FacetDelegate_children, "FacetDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			invoke::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(invoke::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_invoke_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_invoke_children, "invoke", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ReceptacleDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ReceptacleDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ReceptacleDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ReceptacleDelegate_children, "ReceptacleDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AttributeMappingDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AttributeMappingDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AttributeMappingDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AttributeMappingDelegate_children, "AttributeMappingDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ExternalDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ExternalDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ExternalDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ExternalDelegate_children, "ExternalDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AttributeMapping::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AttributeMapping::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_AttributeMapping_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_AttributeMapping_children, "AttributeMapping", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PublishConnector::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PublishConnector::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_PublishConnector_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_PublishConnector_children, "PublishConnector", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ExternalPortReference::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ExternalPortReference::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_ExternalPortReference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_ExternalPortReference_children, "ExternalPortReference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			SupportsDelegate::meta_ComponentAssembly_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(SupportsDelegate::meta_ComponentAssembly_parent, "ComponentAssembly_parent", true);
			ComponentAssembly::meta_SupportsDelegate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAssembly::meta_SupportsDelegate_children, "SupportsDelegate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Port::meta_ConnectedComponent_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Port::meta_ConnectedComponent_parent, "ConnectedComponent_parent", true);
			ConnectedComponent::meta_Port_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ConnectedComponent::meta_Port_children, "Port", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DstEdge::meta_ConnectedComponent_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DstEdge::meta_ConnectedComponent_parent, "ConnectedComponent_parent", true);
			ConnectedComponent::meta_DstEdge_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ConnectedComponent::meta_DstEdge_children, "DstEdge", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentRef::meta_Path_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentRef::meta_Path_parent, "Path_parent", true);
			Path::meta_ComponentRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Path::meta_ComponentRef_children, "ComponentRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DstEdge::meta_Path_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DstEdge::meta_Path_parent, "Path_parent", true);
			Path::meta_DstEdge_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Path::meta_DstEdge_children, "DstEdge", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			SrcEdge::meta_Path_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(SrcEdge::meta_Path_parent, "Path_parent", true);
			Path::meta_SrcEdge_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Path::meta_SrcEdge_children, "SrcEdge", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			EdgeProperty::meta_Path_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(EdgeProperty::meta_Path_parent, "Path_parent", true);
			Path::meta_EdgeProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Path::meta_EdgeProperty_children, "EdgeProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Edge::meta_Path_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Edge::meta_Path_parent, "Path_parent", true);
			Path::meta_Edge_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Path::meta_Edge_children, "Edge", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_Path_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_Path_parent, "Path_parent", true);
			Path::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Path::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			GraphVertex::meta_Path_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(GraphVertex::meta_Path_parent, "Path_parent", true);
			Path::meta_GraphVertex_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Path::meta_GraphVertex_children, "GraphVertex", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Paths::meta_PathDiagrams_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Paths::meta_PathDiagrams_parent, "PathDiagrams_parent", true);
			PathDiagrams::meta_Paths_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PathDiagrams::meta_Paths_children, "Paths", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PathProperty::meta_Paths_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PathProperty::meta_Paths_parent, "Paths_parent", true);
			Paths::meta_PathProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Paths::meta_PathProperty_children, "PathProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Path::meta_Paths_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Path::meta_Paths_parent, "Paths_parent", true);
			Paths::meta_Path_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Paths::meta_Path_children, "Path", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_Paths_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_Paths_parent, "Paths_parent", true);
			Paths::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Paths::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BenchmarkAnalysis::meta_ComponentAnalyses_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BenchmarkAnalysis::meta_ComponentAnalyses_parent, "ComponentAnalyses_parent", true);
			ComponentAnalyses::meta_BenchmarkAnalysis_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentAnalyses::meta_BenchmarkAnalysis_children, "BenchmarkAnalysis", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TimerConnection::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TimerConnection::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_TimerConnection_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_TimerConnection_children, "TimerConnection", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			OperationBase::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(OperationBase::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_OperationBase_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_OperationBase_children, "OperationBase", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MetricConnection::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MetricConnection::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_MetricConnection_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_MetricConnection_children, "MetricConnection", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataAnalysisBase::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataAnalysisBase::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_DataAnalysisBase_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_DataAnalysisBase_children, "DataAnalysisBase", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MetricsBase::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MetricsBase::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_MetricsBase_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_MetricsBase_children, "MetricsBase", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TimeProbe::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TimeProbe::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_TimeProbe_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_TimeProbe_children, "TimeProbe", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			OperationRef::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(OperationRef::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_OperationRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_OperationRef_children, "OperationRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			EventRef::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(EventRef::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_EventRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_EventRef_children, "EventRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Event::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Event::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_Event_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_Event_children, "Event", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TimerEventSinkConn::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TimerEventSinkConn::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_TimerEventSinkConn_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_TimerEventSinkConn_children, "TimerEventSinkConn", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TaskSet::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TaskSet::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_TaskSet_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_TaskSet_children, "TaskSet", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Task::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Task::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_Task_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_Task_children, "Task", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkloadCharacteristics::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkloadCharacteristics::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_WorkloadCharacteristics_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_WorkloadCharacteristics_children, "WorkloadCharacteristics", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentOperation::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentOperation::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_ComponentOperation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_ComponentOperation_children, "ComponentOperation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			CompRef::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(CompRef::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_CompRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_CompRef_children, "CompRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkLoadOperationConnection::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkLoadOperationConnection::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_WorkLoadOperationConnection_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_WorkLoadOperationConnection_children, "WorkLoadOperationConnection", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BenchmarkType::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BenchmarkType::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_BenchmarkType_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_BenchmarkType_children, "BenchmarkType", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BenchmarkCharacteristics::meta_BenchmarkAnalysis_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BenchmarkCharacteristics::meta_BenchmarkAnalysis_parent, "BenchmarkAnalysis_parent", true);
			BenchmarkAnalysis::meta_BenchmarkCharacteristics_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BenchmarkAnalysis::meta_BenchmarkCharacteristics_children, "BenchmarkCharacteristics", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataAnalysisBase::meta_MetricsBase_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataAnalysisBase::meta_MetricsBase_parent, "MetricsBase_parent", true);
			MetricsBase::meta_DataAnalysisBase_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(MetricsBase::meta_DataAnalysisBase_children, "DataAnalysisBase", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Resource::meta_Interconnect_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Resource::meta_Interconnect_parent, "Interconnect_parent", true);
			Interconnect::meta_Resource_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Interconnect::meta_Resource_children, "Resource", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Resource::meta_Node_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Resource::meta_Node_parent, "Node_parent", true);
			Node::meta_Resource_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Node::meta_Resource_children, "Resource", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Resource::meta_Bridge_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Resource::meta_Bridge_parent, "Bridge_parent", true);
			Bridge::meta_Resource_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Bridge::meta_Resource_children, "Resource", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DeploymentPlan::meta_DeploymentPlans_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DeploymentPlan::meta_DeploymentPlans_parent, "DeploymentPlans_parent", true);
			DeploymentPlans::meta_DeploymentPlan_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(DeploymentPlans::meta_DeploymentPlan_children, "DeploymentPlan", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InstanceMapping::meta_DeploymentPlan_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InstanceMapping::meta_DeploymentPlan_parent, "DeploymentPlan_parent", true);
			DeploymentPlan::meta_InstanceMapping_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(DeploymentPlan::meta_InstanceMapping_children, "InstanceMapping", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			NodeReference::meta_DeploymentPlan_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(NodeReference::meta_DeploymentPlan_parent, "DeploymentPlan_parent", true);
			DeploymentPlan::meta_NodeReference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(DeploymentPlan::meta_NodeReference_children, "NodeReference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			CollocationGroup::meta_DeploymentPlan_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(CollocationGroup::meta_DeploymentPlan_parent, "DeploymentPlan_parent", true);
			DeploymentPlan::meta_CollocationGroup_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(DeploymentPlan::meta_CollocationGroup_children, "CollocationGroup", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_DeploymentPlan_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_DeploymentPlan_parent, "DeploymentPlan_parent", true);
			DeploymentPlan::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(DeploymentPlan::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Deploys::meta_DeploymentPlan_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Deploys::meta_DeploymentPlan_parent, "DeploymentPlan_parent", true);
			DeploymentPlan::meta_Deploys_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(DeploymentPlan::meta_Deploys_children, "Deploys", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			CollocationGroupMember::meta_DeploymentPlan_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(CollocationGroupMember::meta_DeploymentPlan_parent, "DeploymentPlan_parent", true);
			DeploymentPlan::meta_CollocationGroupMember_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(DeploymentPlan::meta_CollocationGroupMember_children, "CollocationGroupMember", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentImplementationContainer::meta_ComponentImplementations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentImplementationContainer::meta_ComponentImplementations_parent, "ComponentImplementations_parent", true);
			ComponentImplementations::meta_ComponentImplementationContainer_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementations::meta_ComponentImplementationContainer_children, "ComponentImplementationContainer", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Implements::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Implements::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_Implements_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_Implements_child, "Implements", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationDependsOn::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationDependsOn::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_ImplementationDependsOn_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_ImplementationDependsOn_children, "ImplementationDependsOn", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentRef::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentRef::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_ComponentRef_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_ComponentRef_child, "ComponentRef", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationDependency::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationDependency::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_ImplementationDependency_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_ImplementationDependency_children, "ImplementationDependency", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationCapability::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationCapability::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_ImplementationCapability_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_ImplementationCapability_children, "ImplementationCapability", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Capability::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Capability::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_Capability_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_Capability_children, "Capability", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			CriticalPath::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(CriticalPath::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_CriticalPath_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_CriticalPath_children, "CriticalPath", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PathReference::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PathReference::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_PathReference_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_PathReference_child, "PathReference", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentImplementation::meta_ComponentImplementationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentImplementation::meta_ComponentImplementationContainer_parent, "ComponentImplementationContainer_parent", true);
			ComponentImplementationContainer::meta_ComponentImplementation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentImplementationContainer::meta_ComponentImplementation_children, "ComponentImplementation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfigurationContainer::meta_PackageConfigurations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfigurationContainer::meta_PackageConfigurations_parent, "PackageConfigurations_parent", true);
			PackageConfigurations::meta_PackageConfigurationContainer_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurations::meta_PackageConfigurationContainer_children, "PackageConfigurationContainer", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfReference::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfReference::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_PackageConfReference_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_PackageConfReference_child, "PackageConfReference", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfBasePackage::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfBasePackage::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_PackageConfBasePackage_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_PackageConfBasePackage_child, "PackageConfBasePackage", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentPackage::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentPackage::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_ComponentPackage_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_ComponentPackage_child, "ComponentPackage", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentPackageReference::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentPackageReference::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_ComponentPackageReference_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_ComponentPackageReference_child, "ComponentPackageReference", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfConfigProperty::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfConfigProperty::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_PackageConfConfigProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_PackageConfConfigProperty_children, "PackageConfConfigProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_PackageConfSelectRequirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_PackageConfSelectRequirement_children, "PackageConfSelectRequirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Requirement::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Requirement::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_Requirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_Requirement_children, "Requirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child, "PackageConfSpecializedConfig", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfiguration::meta_PackageConfigurationContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfiguration::meta_PackageConfigurationContainer_parent, "PackageConfigurationContainer_parent", true);
			PackageConfigurationContainer::meta_PackageConfiguration_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageConfigurationContainer::meta_PackageConfiguration_children, "PackageConfiguration", true, 1, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ArtifactContainer::meta_ImplementationArtifacts_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ArtifactContainer::meta_ImplementationArtifacts_parent, "ImplementationArtifacts_parent", true);
			ImplementationArtifacts::meta_ArtifactContainer_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ImplementationArtifacts::meta_ArtifactContainer_children, "ArtifactContainer", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifactReference::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifactReference::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_ImplementationArtifactReference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_ImplementationArtifactReference_children, "ImplementationArtifactReference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ArtifactDependsOn::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ArtifactDependsOn::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_ArtifactDependsOn_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_ArtifactDependsOn_children, "ArtifactDependsOn", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ArtifactDeployRequirement::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ArtifactDeployRequirement::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_ArtifactDeployRequirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_ArtifactDeployRequirement_children, "ArtifactDeployRequirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Requirement::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Requirement::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_Requirement_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_Requirement_children, "Requirement", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ArtifactExecParameter::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ArtifactExecParameter::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_ArtifactExecParameter_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_ArtifactExecParameter_children, "ArtifactExecParameter", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ArtifactInfoProperty::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ArtifactInfoProperty::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_ArtifactInfoProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_ArtifactInfoProperty_children, "ArtifactInfoProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifact::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifact::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_ImplementationArtifact_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_ImplementationArtifact_children, "ImplementationArtifact", true, 1, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ArtifactDependency::meta_ArtifactContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ArtifactDependency::meta_ArtifactContainer_parent, "ArtifactContainer_parent", true);
			ArtifactContainer::meta_ArtifactDependency_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ArtifactContainer::meta_ArtifactDependency_children, "ArtifactDependency", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentContainer::meta_ComponentTypes_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentContainer::meta_ComponentTypes_parent, "ComponentTypes_parent", true);
			ComponentTypes::meta_ComponentContainer_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentTypes::meta_ComponentContainer_children, "ComponentContainer", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataType::meta_ComponentPropertyDescription_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataType::meta_ComponentPropertyDescription_parent, "ComponentPropertyDescription_parent", true);
			ComponentPropertyDescription::meta_DataType_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentPropertyDescription::meta_DataType_child, "DataType", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentConfigProperty::meta_ComponentContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentConfigProperty::meta_ComponentContainer_parent, "ComponentContainer_parent", true);
			ComponentContainer::meta_ComponentConfigProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentContainer::meta_ComponentConfigProperty_children, "ComponentConfigProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_ComponentContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_ComponentContainer_parent, "ComponentContainer_parent", true);
			ComponentContainer::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentContainer::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentInfoProperty::meta_ComponentContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentInfoProperty::meta_ComponentContainer_parent, "ComponentContainer_parent", true);
			ComponentContainer::meta_ComponentInfoProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentContainer::meta_ComponentInfoProperty_children, "ComponentInfoProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentProperty::meta_ComponentContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentProperty::meta_ComponentContainer_parent, "ComponentContainer_parent", true);
			ComponentContainer::meta_ComponentProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentContainer::meta_ComponentProperty_children, "ComponentProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentPropertyDescription::meta_ComponentContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentPropertyDescription::meta_ComponentContainer_parent, "ComponentContainer_parent", true);
			ComponentContainer::meta_ComponentPropertyDescription_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentContainer::meta_ComponentPropertyDescription_children, "ComponentPropertyDescription", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentRef::meta_ComponentContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentRef::meta_ComponentContainer_parent, "ComponentContainer_parent", true);
			ComponentContainer::meta_ComponentRef_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentContainer::meta_ComponentRef_child, "ComponentRef", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TopLevelPackage::meta_TopLevelPackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TopLevelPackage::meta_TopLevelPackageContainer_parent, "TopLevelPackageContainer_parent", true);
			TopLevelPackageContainer::meta_TopLevelPackage_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelPackageContainer::meta_TopLevelPackage_child, "TopLevelPackage", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfigurationReference::meta_TopLevelPackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfigurationReference::meta_TopLevelPackageContainer_parent, "TopLevelPackageContainer_parent", true);
			TopLevelPackageContainer::meta_PackageConfigurationReference_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelPackageContainer::meta_PackageConfigurationReference_child, "PackageConfigurationReference", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			package::meta_TopLevelPackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(package::meta_TopLevelPackageContainer_parent, "TopLevelPackageContainer_parent", true);
			TopLevelPackageContainer::meta_package_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelPackageContainer::meta_package_child, "package", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TopLevelPackageContainer::meta_TopLevelPackages_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TopLevelPackageContainer::meta_TopLevelPackages_parent, "TopLevelPackages_parent", true);
			TopLevelPackages::meta_TopLevelPackageContainer_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelPackages::meta_TopLevelPackageContainer_children, "TopLevelPackageContainer", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageContainer::meta_ComponentPackages_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageContainer::meta_ComponentPackages_parent, "ComponentPackages_parent", true);
			ComponentPackages::meta_PackageContainer_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentPackages::meta_PackageContainer_children, "PackageContainer", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Implementation::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Implementation::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_Implementation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_Implementation_children, "Implementation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageInterface::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageInterface::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_PackageInterface_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_PackageInterface_child, "PackageInterface", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentImplementationReference::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentImplementationReference::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_ComponentImplementationReference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_ComponentImplementationReference_children, "ComponentImplementationReference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentRef::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentRef::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_ComponentRef_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_ComponentRef_child, "ComponentRef", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfigProperty::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfigProperty::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_PackageConfigProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_PackageConfigProperty_children, "PackageConfigProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageInfoProperty::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageInfoProperty::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_PackageInfoProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_PackageInfoProperty_children, "PackageInfoProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentPackage::meta_PackageContainer_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentPackage::meta_PackageContainer_parent, "PackageContainer_parent", true);
			PackageContainer::meta_ComponentPackage_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PackageContainer::meta_ComponentPackage_child, "ComponentPackage", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataType::meta_SatisfierProperty_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataType::meta_SatisfierProperty_parent, "SatisfierProperty_parent", true);
			SatisfierProperty::meta_DataType_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(SatisfierProperty::meta_DataType_child, "DataType", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			SatisfierProperty::meta_RequirementSatisfier_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(SatisfierProperty::meta_RequirementSatisfier_parent, "RequirementSatisfier_parent", true);
			RequirementSatisfier::meta_SatisfierProperty_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RequirementSatisfier::meta_SatisfierProperty_children, "SatisfierProperty", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_RequirementBase_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_RequirementBase_parent, "RequirementBase_parent", true);
			RequirementBase::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RequirementBase::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataType::meta_Property_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataType::meta_Property_parent, "Property_parent", true);
			Property::meta_DataType_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Property::meta_DataType_child, "DataType", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Domain::meta_Targets_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Domain::meta_Targets_parent, "Targets_parent", true);
			Targets::meta_Domain_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Targets::meta_Domain_children, "Domain", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Interconnect::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Interconnect::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_Interconnect_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_Interconnect_children, "Interconnect", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InterconnectConnection::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InterconnectConnection::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_InterconnectConnection_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_InterconnectConnection_children, "InterconnectConnection", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Node::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Node::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_Node_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_Node_children, "Node", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BridgeConnection::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BridgeConnection::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_BridgeConnection_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_BridgeConnection_children, "BridgeConnection", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Bridge::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Bridge::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_Bridge_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_Bridge_children, "Bridge", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			SharedResource::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(SharedResource::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_SharedResource_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_SharedResource_children, "SharedResource", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Shares::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Shares::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_Shares_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_Shares_children, "Shares", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_Domain_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_Domain_parent, "Domain_parent", true);
			Domain::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Domain::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			LookupKey::meta_ComponentFactory_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(LookupKey::meta_ComponentFactory_parent, "ComponentFactory_parent", true);
			ComponentFactory::meta_LookupKey_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentFactory::meta_LookupKey_child, "LookupKey", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			FactoryOperation::meta_ComponentFactory_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(FactoryOperation::meta_ComponentFactory_parent, "ComponentFactory_parent", true);
			ComponentFactory::meta_FactoryOperation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentFactory::meta_FactoryOperation_children, "FactoryOperation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			LookupOperation::meta_ComponentFactory_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(LookupOperation::meta_ComponentFactory_parent, "ComponentFactory_parent", true);
			ComponentFactory::meta_LookupOperation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentFactory::meta_LookupOperation_children, "LookupOperation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ReadonlyAttribute::meta_Component_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ReadonlyAttribute::meta_Component_parent, "Component_parent", true);
			Component::meta_ReadonlyAttribute_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Component::meta_ReadonlyAttribute_children, "ReadonlyAttribute", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Port::meta_Component_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Port::meta_Component_parent, "Component_parent", true);
			Component::meta_Port_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Component::meta_Port_children, "Port", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkerType::meta_Component_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkerType::meta_Component_parent, "Component_parent", true);
			Component::meta_WorkerType_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Component::meta_WorkerType_children, "WorkerType", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InParameter::meta_OperationBase_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InParameter::meta_OperationBase_parent, "OperationBase_parent", true);
			OperationBase::meta_InParameter_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(OperationBase::meta_InParameter_children, "InParameter", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ExceptionRef::meta_HasExceptions_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ExceptionRef::meta_HasExceptions_parent, "HasExceptions_parent", true);
			HasExceptions::meta_ExceptionRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(HasExceptions::meta_ExceptionRef_children, "ExceptionRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			OutParameter::meta_TwowayOperation_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(OutParameter::meta_TwowayOperation_parent, "TwowayOperation_parent", true);
			TwowayOperation::meta_OutParameter_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TwowayOperation::meta_OutParameter_children, "OutParameter", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InoutParameter::meta_TwowayOperation_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InoutParameter::meta_TwowayOperation_parent, "TwowayOperation_parent", true);
			TwowayOperation::meta_InoutParameter_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TwowayOperation::meta_InoutParameter_children, "InoutParameter", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ReturnType::meta_TwowayOperation_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ReturnType::meta_TwowayOperation_parent, "TwowayOperation_parent", true);
			TwowayOperation::meta_ReturnType_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TwowayOperation::meta_ReturnType_child, "ReturnType", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TwowayOperation::meta_HasOperations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TwowayOperation::meta_HasOperations_parent, "HasOperations_parent", true);
			HasOperations::meta_TwowayOperation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(HasOperations::meta_TwowayOperation_children, "TwowayOperation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			OnewayOperation::meta_HasOperations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(OnewayOperation::meta_HasOperations_parent, "HasOperations_parent", true);
			HasOperations::meta_OnewayOperation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(HasOperations::meta_OnewayOperation_children, "OnewayOperation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Exception::meta_HasOperations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Exception::meta_HasOperations_parent, "HasOperations_parent", true);
			HasOperations::meta_Exception_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(HasOperations::meta_Exception_children, "Exception", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Constant::meta_HasOperations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Constant::meta_HasOperations_parent, "HasOperations_parent", true);
			HasOperations::meta_Constant_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(HasOperations::meta_Constant_children, "Constant", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			NoInheritable::meta_HasOperations_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(NoInheritable::meta_HasOperations_parent, "HasOperations_parent", true);
			HasOperations::meta_NoInheritable_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(HasOperations::meta_NoInheritable_children, "NoInheritable", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Supports::meta_SupportsInterfaces_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Supports::meta_SupportsInterfaces_parent, "SupportsInterfaces_parent", true);
			SupportsInterfaces::meta_Supports_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(SupportsInterfaces::meta_Supports_children, "Supports", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			SetException::meta_Attribute_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(SetException::meta_Attribute_parent, "Attribute_parent", true);
			Attribute::meta_SetException_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Attribute::meta_SetException_children, "SetException", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PrivateFlag::meta_ObjectByValue_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PrivateFlag::meta_ObjectByValue_parent, "ObjectByValue_parent", true);
			ObjectByValue::meta_PrivateFlag_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ObjectByValue::meta_PrivateFlag_children, "PrivateFlag", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			FactoryOperation::meta_ObjectByValue_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(FactoryOperation::meta_ObjectByValue_parent, "ObjectByValue_parent", true);
			ObjectByValue::meta_FactoryOperation_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ObjectByValue::meta_FactoryOperation_children, "FactoryOperation", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MakeMemberPrivate::meta_ObjectByValue_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MakeMemberPrivate::meta_ObjectByValue_parent, "ObjectByValue_parent", true);
			ObjectByValue::meta_MakeMemberPrivate_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ObjectByValue::meta_MakeMemberPrivate_children, "MakeMemberPrivate", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Member::meta_ObjectByValue_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Member::meta_ObjectByValue_parent, "ObjectByValue_parent", true);
			ObjectByValue::meta_Member_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ObjectByValue::meta_Member_children, "Member", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ReadonlyAttribute::meta_Inheritable_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ReadonlyAttribute::meta_Inheritable_parent, "Inheritable_parent", true);
			Inheritable::meta_ReadonlyAttribute_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Inheritable::meta_ReadonlyAttribute_children, "ReadonlyAttribute", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Inherits::meta_Inheritable_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Inherits::meta_Inheritable_parent, "Inheritable_parent", true);
			Inheritable::meta_Inherits_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Inheritable::meta_Inherits_children, "Inherits", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			AttributeMember::meta_ReadonlyAttribute_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(AttributeMember::meta_ReadonlyAttribute_parent, "ReadonlyAttribute_parent", true);
			ReadonlyAttribute::meta_AttributeMember_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ReadonlyAttribute::meta_AttributeMember_child, "AttributeMember", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			GetException::meta_ReadonlyAttribute_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(GetException::meta_ReadonlyAttribute_parent, "ReadonlyAttribute_parent", true);
			ReadonlyAttribute::meta_GetException_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ReadonlyAttribute::meta_GetException_children, "GetException", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Member::meta_Aggregate_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Member::meta_Aggregate_parent, "Aggregate_parent", true);
			Aggregate::meta_Member_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Aggregate::meta_Member_children, "Member", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Label::meta_SwitchedAggregate_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Label::meta_SwitchedAggregate_parent, "SwitchedAggregate_parent", true);
			SwitchedAggregate::meta_Label_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(SwitchedAggregate::meta_Label_children, "Label", true, 1, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			LabelConnection::meta_SwitchedAggregate_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(LabelConnection::meta_SwitchedAggregate_parent, "SwitchedAggregate_parent", true);
			SwitchedAggregate::meta_LabelConnection_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(SwitchedAggregate::meta_LabelConnection_children, "LabelConnection", true, 1, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Member::meta_SwitchedAggregate_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Member::meta_SwitchedAggregate_parent, "SwitchedAggregate_parent", true);
			SwitchedAggregate::meta_Member_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(SwitchedAggregate::meta_Member_children, "Member", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Discriminator::meta_SwitchedAggregate_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Discriminator::meta_SwitchedAggregate_parent, "SwitchedAggregate_parent", true);
			SwitchedAggregate::meta_Discriminator_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(SwitchedAggregate::meta_Discriminator_child, "Discriminator", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			EnumValue::meta_Enum_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(EnumValue::meta_Enum_parent, "Enum_parent", true);
			Enum::meta_EnumValue_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Enum::meta_EnumValue_children, "EnumValue", true, 1, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Collection::meta_PredefinedTypes_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Collection::meta_PredefinedTypes_parent, "PredefinedTypes_parent", true);
			PredefinedTypes::meta_Collection_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PredefinedTypes::meta_Collection_children, "Collection", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PredefinedType::meta_PredefinedTypes_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PredefinedType::meta_PredefinedTypes_parent, "PredefinedTypes_parent", true);
			PredefinedTypes::meta_PredefinedType_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(PredefinedTypes::meta_PredefinedType_children, "PredefinedType", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentRef::meta_Package_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentRef::meta_Package_parent, "Package_parent", true);
			Package::meta_ComponentRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Package::meta_ComponentRef_children, "ComponentRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			NamedType::meta_Package_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(NamedType::meta_Package_parent, "Package_parent", true);
			Package::meta_NamedType_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Package::meta_NamedType_children, "NamedType", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ManagesComponent::meta_Package_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ManagesComponent::meta_Package_parent, "Package_parent", true);
			Package::meta_ManagesComponent_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Package::meta_ManagesComponent_children, "ManagesComponent", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Package::meta_Package_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Package::meta_Package_parent, "Package_parent", true);
			Package::meta_Package_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Package::meta_Package_children, "Package", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Exception::meta_Package_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Exception::meta_Package_parent, "Package_parent", true);
			Package::meta_Exception_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Package::meta_Exception_children, "Exception", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Constant::meta_Package_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Constant::meta_Package_parent, "Package_parent", true);
			Package::meta_Constant_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Package::meta_Constant_children, "Constant", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ManagesComponent::meta_File_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ManagesComponent::meta_File_parent, "File_parent", true);
			File::meta_ManagesComponent_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(File::meta_ManagesComponent_children, "ManagesComponent", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentRef::meta_File_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentRef::meta_File_parent, "File_parent", true);
			File::meta_ComponentRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(File::meta_ComponentRef_children, "ComponentRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Package::meta_File_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Package::meta_File_parent, "File_parent", true);
			File::meta_Package_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(File::meta_Package_children, "Package", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Exception::meta_File_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Exception::meta_File_parent, "File_parent", true);
			File::meta_Exception_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(File::meta_Exception_children, "Exception", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			FileRef::meta_File_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(FileRef::meta_File_parent, "File_parent", true);
			File::meta_FileRef_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(File::meta_FileRef_children, "FileRef", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Constant::meta_File_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Constant::meta_File_parent, "File_parent", true);
			File::meta_Constant_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(File::meta_Constant_children, "Constant", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			NamedType::meta_File_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(NamedType::meta_File_parent, "File_parent", true);
			File::meta_NamedType_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(File::meta_NamedType_children, "NamedType", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Member::meta_Exception_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Member::meta_Exception_parent, "Exception_parent", true);
			Exception::meta_Member_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Exception::meta_Member_children, "Member", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			File::meta_InterfaceDefinitions_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(File::meta_InterfaceDefinitions_parent, "InterfaceDefinitions_parent", true);
			InterfaceDefinitions::meta_File_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(InterfaceDefinitions::meta_File_children, "File", true, 1, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MPC::meta_ComponentBuild_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MPC::meta_ComponentBuild_parent, "ComponentBuild_parent", true);
			ComponentBuild::meta_MPC_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ComponentBuild::meta_MPC_children, "MPC", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ExtResourceConn::meta_Project_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ExtResourceConn::meta_Project_parent, "Project_parent", true);
			Project::meta_ExtResourceConn_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Project::meta_ExtResourceConn_children, "ExtResourceConn", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ExternalResources::meta_Project_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ExternalResources::meta_Project_parent, "Project_parent", true);
			Project::meta_ExternalResources_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Project::meta_ExternalResources_children, "ExternalResources", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentLib::meta_Project_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentLib::meta_Project_parent, "Project_parent", true);
			Project::meta_ComponentLib_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Project::meta_ComponentLib_children, "ComponentLib", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifact::meta_Project_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifact::meta_Project_parent, "Project_parent", true);
			Project::meta_ImplementationArtifact_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Project::meta_ImplementationArtifact_children, "ImplementationArtifact", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Project::meta_MPC_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Project::meta_MPC_parent, "MPC_parent", true);
			MPC::meta_Project_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(MPC::meta_Project_children, "Project", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Workspaces::meta_MPC_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Workspaces::meta_MPC_parent, "MPC_parent", true);
			MPC::meta_Workspaces_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(MPC::meta_Workspaces_children, "Workspaces", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			FileRef::meta_StubProject_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(FileRef::meta_StubProject_parent, "StubProject_parent", true);
			StubProject::meta_FileRef_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(StubProject::meta_FileRef_child, "FileRef", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifactReference::meta_StubProject_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifactReference::meta_StubProject_parent, "StubProject_parent", true);
			StubProject::meta_ImplementationArtifactReference_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(StubProject::meta_ImplementationArtifactReference_child, "ImplementationArtifactReference", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			FileRef::meta_ServantProject_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(FileRef::meta_ServantProject_parent, "ServantProject_parent", true);
			ServantProject::meta_FileRef_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ServantProject::meta_FileRef_child, "FileRef", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifactReference::meta_ServantProject_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifactReference::meta_ServantProject_parent, "ServantProject_parent", true);
			ServantProject::meta_ImplementationArtifactReference_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ServantProject::meta_ImplementationArtifactReference_child, "ImplementationArtifactReference", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifactReference::meta_ExecutorProject_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifactReference::meta_ExecutorProject_parent, "ExecutorProject_parent", true);
			ExecutorProject::meta_ImplementationArtifactReference_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ExecutorProject::meta_ImplementationArtifactReference_child, "ImplementationArtifactReference", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkerLibrary::meta_WorkerLibraries_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkerLibrary::meta_WorkerLibraries_parent, "WorkerLibraries_parent", true);
			WorkerLibraries::meta_WorkerLibrary_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(WorkerLibraries::meta_WorkerLibrary_children, "WorkerLibrary", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkerFile::meta_WorkerLibrary_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkerFile::meta_WorkerLibrary_parent, "WorkerLibrary_parent", true);
			WorkerLibrary::meta_WorkerFile_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(WorkerLibrary::meta_WorkerFile_children, "WorkerFile", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Action::meta_Worker_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Action::meta_Worker_parent, "Worker_parent", true);
			Worker::meta_Action_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Worker::meta_Action_children, "Action", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkerPackage::meta_WorkerFile_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkerPackage::meta_WorkerFile_parent, "WorkerFile_parent", true);
			WorkerFile::meta_WorkerPackage_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(WorkerFile::meta_WorkerPackage_children, "WorkerPackage", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkerPackage::meta_WorkerPackage_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkerPackage::meta_WorkerPackage_parent, "WorkerPackage_parent", true);
			WorkerPackage::meta_WorkerPackage_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(WorkerPackage::meta_WorkerPackage_children, "WorkerPackage", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Worker::meta_WorkerPackageBase_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Worker::meta_WorkerPackageBase_parent, "WorkerPackageBase_parent", true);
			WorkerPackageBase::meta_Worker_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(WorkerPackageBase::meta_Worker_children, "Worker", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TerminalTransition::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TerminalTransition::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_TerminalTransition_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_TerminalTransition_children, "TerminalTransition", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Variable::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Variable::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_Variable_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_Variable_children, "Variable", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Terminal::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Terminal::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_Terminal_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_Terminal_children, "Terminal", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TerminalEffect::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TerminalEffect::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_TerminalEffect_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_TerminalEffect_children, "TerminalEffect", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			StateBase::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(StateBase::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_StateBase_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_StateBase_children, "StateBase", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BranchTransition::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BranchTransition::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_BranchTransition_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_BranchTransition_children, "BranchTransition", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Transition::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Transition::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_Transition_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_Transition_children, "Transition", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			LoopTransition::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(LoopTransition::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_LoopTransition_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_LoopTransition_children, "LoopTransition", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Finish::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Finish::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_Finish_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_Finish_children, "Finish", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BehaviorInputAction::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BehaviorInputAction::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_BehaviorInputAction_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_BehaviorInputAction_children, "BehaviorInputAction", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ActionBase::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ActionBase::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_ActionBase_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_ActionBase_children, "ActionBase", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InputEffect::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InputEffect::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_InputEffect_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_InputEffect_children, "InputEffect", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Effect::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Effect::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_Effect_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_Effect_children, "Effect", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			QueryInputAction::meta_BehaviorModel_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(QueryInputAction::meta_BehaviorModel_parent, "BehaviorModel_parent", true);
			BehaviorModel::meta_QueryInputAction_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorModel::meta_QueryInputAction_children, "QueryInputAction", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_BehaviorInputAction_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_BehaviorInputAction_parent, "BehaviorInputAction_parent", true);
			BehaviorInputAction::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BehaviorInputAction::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_QueryInputAction_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_QueryInputAction_parent, "QueryInputAction_parent", true);
			QueryInputAction::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(QueryInputAction::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Property::meta_ActionBase_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Property::meta_ActionBase_parent, "ActionBase_parent", true);
			ActionBase::meta_Property_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ActionBase::meta_Property_children, "Property", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Input::meta_TopLevelBehavior_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Input::meta_TopLevelBehavior_parent, "TopLevelBehavior_parent", true);
			TopLevelBehavior::meta_Input_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelBehavior::meta_Input_children, "Input", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			MultiInput::meta_TopLevelBehavior_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(MultiInput::meta_TopLevelBehavior_parent, "TopLevelBehavior_parent", true);
			TopLevelBehavior::meta_MultiInput_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelBehavior::meta_MultiInput_children, "MultiInput", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			QueryInput::meta_TopLevelBehavior_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(QueryInput::meta_TopLevelBehavior_parent, "TopLevelBehavior_parent", true);
			TopLevelBehavior::meta_QueryInput_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelBehavior::meta_QueryInput_children, "QueryInput", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PeriodicEvent::meta_TopLevelBehavior_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PeriodicEvent::meta_TopLevelBehavior_parent, "TopLevelBehavior_parent", true);
			TopLevelBehavior::meta_PeriodicEvent_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelBehavior::meta_PeriodicEvent_children, "PeriodicEvent", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ApplicationTask::meta_TopLevelBehavior_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ApplicationTask::meta_TopLevelBehavior_parent, "TopLevelBehavior_parent", true);
			TopLevelBehavior::meta_ApplicationTask_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelBehavior::meta_ApplicationTask_children, "ApplicationTask", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Environment::meta_TopLevelBehavior_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Environment::meta_TopLevelBehavior_parent, "TopLevelBehavior_parent", true);
			TopLevelBehavior::meta_Environment_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(TopLevelBehavior::meta_Environment_child, "Environment", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PathDiagrams::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PathDiagrams::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_PathDiagrams_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_PathDiagrams_children, "PathDiagrams", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentFactoryImplementations::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentFactoryImplementations::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ComponentFactoryImplementations_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ComponentFactoryImplementations_children, "ComponentFactoryImplementations", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentAnalyses::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentAnalyses::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ComponentAnalyses_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ComponentAnalyses_children, "ComponentAnalyses", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DeploymentPlans::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DeploymentPlans::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_DeploymentPlans_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_DeploymentPlans_children, "DeploymentPlans", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentImplementations::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentImplementations::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ComponentImplementations_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ComponentImplementations_children, "ComponentImplementations", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PackageConfigurations::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PackageConfigurations::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_PackageConfigurations_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_PackageConfigurations_children, "PackageConfigurations", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ImplementationArtifacts::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ImplementationArtifacts::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ImplementationArtifacts_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ImplementationArtifacts_children, "ImplementationArtifacts", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentTypes::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentTypes::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ComponentTypes_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ComponentTypes_children, "ComponentTypes", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			TopLevelPackages::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(TopLevelPackages::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_TopLevelPackages_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_TopLevelPackages_children, "TopLevelPackages", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentPackages::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentPackages::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ComponentPackages_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ComponentPackages_children, "ComponentPackages", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Targets::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Targets::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_Targets_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_Targets_children, "Targets", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			PredefinedTypes::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(PredefinedTypes::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_PredefinedTypes_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_PredefinedTypes_children, "PredefinedTypes", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InterfaceDefinitions::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InterfaceDefinitions::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_InterfaceDefinitions_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_InterfaceDefinitions_children, "InterfaceDefinitions", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ComponentBuild::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ComponentBuild::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ComponentBuild_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ComponentBuild_children, "ComponentBuild", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			WorkerLibraries::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(WorkerLibraries::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_WorkerLibraries_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_WorkerLibraries_children, "WorkerLibraries", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			RootFolder::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(RootFolder::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_RootFolder_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_RootFolder_children, "RootFolder", true, 0, -1);

		}

	}

	void InitMetaLinks() {
		Worker::meta_Action_children.target() = Action::meta;

		ActionBase::meta_srcBranchTransition.target() = BranchState::meta;
		ActionBase::meta_dstEffect.target() = StateBase::meta;
		ActionBase::meta_srcLoopTransition.target() = LoopState::meta;
		ActionBase::meta_srcTransition.target() = State::meta;
		Property::meta_ActionBase_parent.target() = ActionBase::meta;
		BehaviorModel::meta_ActionBase_children.target() = ActionBase::meta;
		ActionBase::meta.subTypes() += Action::meta;
		ActionBase::meta.subTypes() += OutputAction::meta;
		ActionBase::meta.subTypes() += QueryAction::meta;

		Member::meta_Aggregate_parent.target() = Aggregate::meta;

		Alias::meta_ref.target() = MemberType::meta;

		TopLevelBehavior::meta_ApplicationTask_children.target() = ApplicationTask::meta;

		ImplementationArtifactReference::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		ArtifactDependsOn::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		ArtifactDeployRequirement::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		Requirement::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		ArtifactExecParameter::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		ArtifactInfoProperty::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		Property::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		ImplementationArtifact::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		ArtifactDependency::meta_ArtifactContainer_parent.target() = ArtifactContainer::meta;
		ImplementationArtifacts::meta_ArtifactContainer_children.target() = ArtifactContainer::meta;

		ArtifactContainer::meta_ArtifactDependency_children.target() = ArtifactDependency::meta;
		ArtifactDependency::meta.association() = ImplementationArtifact::meta_dstArtifactDependency.parent();
		ArtifactDependency::meta_dstArtifactDependency_end_ = ImplementationArtifact::meta_srcArtifactDependency_rev = ImplementationArtifact::meta_dstArtifactDependency;
		ArtifactDependency::meta_srcArtifactDependency_end_ = ImplementationArtifact::meta_dstArtifactDependency_rev = ImplementationArtifact::meta_srcArtifactDependency;

		ArtifactContainer::meta_ArtifactDependsOn_children.target() = ArtifactDependsOn::meta;
		ArtifactDependsOn::meta.association() = ImplementationArtifactReference::meta_srcArtifactDependsOn.parent();
		ArtifactDependsOn::meta_srcArtifactDependsOn_end_ = ImplementationArtifact::meta_dstArtifactDependsOn_rev = ImplementationArtifactReference::meta_srcArtifactDependsOn;
		ArtifactDependsOn::meta_dstArtifactDependsOn_end_ = ImplementationArtifactReference::meta_srcArtifactDependsOn_rev = ImplementationArtifact::meta_dstArtifactDependsOn;

		ArtifactContainer::meta_ArtifactDeployRequirement_children.target() = ArtifactDeployRequirement::meta;
		ArtifactDeployRequirement::meta.association() = ImplementationArtifact::meta_dstArtifactDeployRequirement.parent();
		ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_ = Requirement::meta_srcArtifactDeployRequirement_rev = ImplementationArtifact::meta_dstArtifactDeployRequirement;
		ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_ = ImplementationArtifact::meta_dstArtifactDeployRequirement_rev = Requirement::meta_srcArtifactDeployRequirement;

		ArtifactContainer::meta_ArtifactExecParameter_children.target() = ArtifactExecParameter::meta;
		ArtifactExecParameter::meta.association() = ImplementationArtifact::meta_dstArtifactExecParameter.parent();
		ArtifactExecParameter::meta_dstArtifactExecParameter_end_ = Property::meta_srcArtifactExecParameter_rev = ImplementationArtifact::meta_dstArtifactExecParameter;
		ArtifactExecParameter::meta_srcArtifactExecParameter_end_ = ImplementationArtifact::meta_dstArtifactExecParameter_rev = Property::meta_srcArtifactExecParameter;

		ArtifactContainer::meta_ArtifactInfoProperty_children.target() = ArtifactInfoProperty::meta;
		ArtifactInfoProperty::meta.association() = ImplementationArtifact::meta_dstArtifactInfoProperty.parent();
		ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_ = Property::meta_srcArtifactInfoProperty_rev = ImplementationArtifact::meta_dstArtifactInfoProperty;
		ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_ = ImplementationArtifact::meta_dstArtifactInfoProperty_rev = Property::meta_srcArtifactInfoProperty;

		ComponentAssembly::meta_AssemblyConfigProperty_children.target() = AssemblyConfigProperty::meta;
		AssemblyConfigProperty::meta.association() = Property::meta_srcAssemblyConfigProperty.parent();
		AssemblyConfigProperty::meta_srcAssemblyConfigProperty_end_ = Component::meta_dstAssemblyConfigProperty_rev = Property::meta_srcAssemblyConfigProperty;
		AssemblyConfigProperty::meta_dstAssemblyConfigProperty_end_ = Property::meta_srcAssemblyConfigProperty_rev = Component::meta_dstAssemblyConfigProperty;

		ComponentAssembly::meta_AssemblyDeployRequirement_children.target() = AssemblyDeployRequirement::meta;
		AssemblyDeployRequirement::meta.association() = PublishConnector::meta_dstAssemblyDeployRequirement.parent();
		AssemblyDeployRequirement::meta_dstAssemblyDeployRequirement_end_ = Requirement::meta_srcAssemblyDeployRequirement_rev = PublishConnector::meta_dstAssemblyDeployRequirement;
		AssemblyDeployRequirement::meta_srcAssemblyDeployRequirement_end_ = PublishConnector::meta_dstAssemblyDeployRequirement_rev = Requirement::meta_srcAssemblyDeployRequirement;

		ComponentAssembly::meta_AssemblyselectRequirement_children.target() = AssemblyselectRequirement::meta;
		AssemblyselectRequirement::meta.association() = Requirement::meta_srcAssemblyselectRequirement.parent();
		AssemblyselectRequirement::meta_srcAssemblyselectRequirement_end_ = Component::meta_dstAssemblyselectRequirement_rev = Requirement::meta_srcAssemblyselectRequirement;
		AssemblyselectRequirement::meta_dstAssemblyselectRequirement_end_ = Requirement::meta_srcAssemblyselectRequirement_rev = Component::meta_dstAssemblyselectRequirement;

		SetException::meta_Attribute_parent.target() = Attribute::meta;

		ComponentAssembly::meta_AttributeDelegate_children.target() = AttributeDelegate::meta;
		AttributeDelegate::meta.association() = AttributeMapping::meta_dstAttributeDelegate.parent();
		AttributeDelegate::meta_dstAttributeDelegate_end_ = ReadonlyAttribute::meta_srcAttributeDelegate_rev = AttributeMapping::meta_dstAttributeDelegate;
		AttributeDelegate::meta_srcAttributeDelegate_end_ = AttributeMapping::meta_dstAttributeDelegate_rev = ReadonlyAttribute::meta_srcAttributeDelegate;

		AttributeMapping::meta_dstAttributeMappingValue.target() = Property::meta;
		AttributeMapping::meta_dstAttributeDelegate.target() = ReadonlyAttribute::meta;
		AttributeMapping::meta_dstAttributeMappingDelegate.target() = AttributeMapping::meta;
		AttributeMapping::meta_srcAttributeMappingDelegate.target() = AttributeMapping::meta;
		AttributeMapping::meta_ref.target() = ReadonlyAttribute::meta;
		ComponentAssembly::meta_AttributeMapping_children.target() = AttributeMapping::meta;

		ComponentAssembly::meta_AttributeMappingDelegate_children.target() = AttributeMappingDelegate::meta;
		AttributeMappingDelegate::meta.association() = AttributeMapping::meta_dstAttributeMappingDelegate.parent();
		AttributeMappingDelegate::meta_dstAttributeMappingDelegate_end_ = AttributeMapping::meta_srcAttributeMappingDelegate_rev = AttributeMapping::meta_dstAttributeMappingDelegate;
		AttributeMappingDelegate::meta_srcAttributeMappingDelegate_end_ = AttributeMapping::meta_dstAttributeMappingDelegate_rev = AttributeMapping::meta_srcAttributeMappingDelegate;

		ComponentAssembly::meta_AttributeMappingValue_children.target() = AttributeMappingValue::meta;
		AttributeMappingValue::meta.association() = AttributeMapping::meta_dstAttributeMappingValue.parent();
		AttributeMappingValue::meta_dstAttributeMappingValue_end_ = Property::meta_srcAttributeMappingValue_rev = AttributeMapping::meta_dstAttributeMappingValue;
		AttributeMappingValue::meta_srcAttributeMappingValue_end_ = AttributeMapping::meta_dstAttributeMappingValue_rev = Property::meta_srcAttributeMappingValue;

		AttributeMember::meta_ref.target() = MemberType::meta;
		ReadonlyAttribute::meta_AttributeMember_child.target() = AttributeMember::meta;

		ComponentAssembly::meta_AttributeValue_children.target() = AttributeValue::meta;
		AttributeValue::meta.association() = Property::meta_srcAttributeValue.parent();
		AttributeValue::meta_srcAttributeValue_end_ = ReadonlyAttribute::meta_dstAttributeValue_rev = Property::meta_srcAttributeValue;
		AttributeValue::meta_dstAttributeValue_end_ = Property::meta_srcAttributeValue_rev = ReadonlyAttribute::meta_dstAttributeValue;

		BehaviorInputAction::meta_srcFinish.target() = StateBase::meta;
		BehaviorInputAction::meta_dstInputEffect.target() = StateBase::meta;
		Property::meta_BehaviorInputAction_parent.target() = BehaviorInputAction::meta;
		BehaviorModel::meta_BehaviorInputAction_children.target() = BehaviorInputAction::meta;
		BehaviorInputAction::meta.subTypes() += InputAction::meta;
		BehaviorInputAction::meta.subTypes() += MultiInputAction::meta;

		TerminalTransition::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		Variable::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		Terminal::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		TerminalEffect::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		StateBase::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		BranchTransition::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		Transition::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		LoopTransition::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		Finish::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		BehaviorInputAction::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		ActionBase::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		InputEffect::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		Effect::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		QueryInputAction::meta_BehaviorModel_parent.target() = BehaviorModel::meta;
		BehaviorModel::meta.subTypes() += TopLevelBehavior::meta;

		TimerConnection::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		OperationBase::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		MetricConnection::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		DataAnalysisBase::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		MetricsBase::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		TimeProbe::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		OperationRef::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		EventRef::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		Event::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		TimerEventSinkConn::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		TaskSet::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		Task::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		WorkloadCharacteristics::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		ComponentOperation::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		CompRef::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		WorkLoadOperationConnection::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		BenchmarkType::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		BenchmarkCharacteristics::meta_BenchmarkAnalysis_parent.target() = BenchmarkAnalysis::meta;
		ComponentAnalyses::meta_BenchmarkAnalysis_children.target() = BenchmarkAnalysis::meta;

		BenchmarkAnalysis::meta_BenchmarkCharacteristics_children.target() = BenchmarkCharacteristics::meta;
		BenchmarkCharacteristics::meta.association() = MetricsBase::meta_srcBenchmarkCharacteristics.parent();
		BenchmarkCharacteristics::meta_srcBenchmarkCharacteristics_end_ = BenchmarkType::meta_dstBenchmarkCharacteristics_rev = MetricsBase::meta_srcBenchmarkCharacteristics;
		BenchmarkCharacteristics::meta_dstBenchmarkCharacteristics_end_ = MetricsBase::meta_srcBenchmarkCharacteristics_rev = BenchmarkType::meta_dstBenchmarkCharacteristics;

		BenchmarkType::meta_dstBenchmarkCharacteristics.target() = MetricsBase::meta;
		BenchmarkAnalysis::meta_BenchmarkType_children.target() = BenchmarkType::meta;
		BenchmarkType::meta.subTypes() += TriggerBenchmarks::meta;
		BenchmarkType::meta.subTypes() += FixedIterationBenchmarks::meta;
		BenchmarkType::meta.subTypes() += PeriodicBenchmarks::meta;

		Boxed::meta_ref.target() = MemberType::meta;

		BranchState::meta_dstBranchTransition.target() = ActionBase::meta;

		BehaviorModel::meta_BranchTransition_children.target() = BranchTransition::meta;
		BranchTransition::meta.association() = ActionBase::meta_srcBranchTransition.parent();
		BranchTransition::meta_srcBranchTransition_end_ = BranchState::meta_dstBranchTransition_rev = ActionBase::meta_srcBranchTransition;
		BranchTransition::meta_dstBranchTransition_end_ = ActionBase::meta_srcBranchTransition_rev = BranchState::meta_dstBranchTransition;

		Bridge::meta_srcBridgeConnection.target() = Interconnect::meta;
		Resource::meta_Bridge_parent.target() = Bridge::meta;
		Domain::meta_Bridge_children.target() = Bridge::meta;

		Domain::meta_BridgeConnection_children.target() = BridgeConnection::meta;
		BridgeConnection::meta.association() = Interconnect::meta_dstBridgeConnection.parent();
		BridgeConnection::meta_dstBridgeConnection_end_ = Bridge::meta_srcBridgeConnection_rev = Interconnect::meta_dstBridgeConnection;
		BridgeConnection::meta_srcBridgeConnection_end_ = Interconnect::meta_dstBridgeConnection_rev = Bridge::meta_srcBridgeConnection;

		Capability::meta_srcImplementationCapability.target() = ComponentImplementation::meta;
		ComponentImplementationContainer::meta_Capability_children.target() = Capability::meta;

		Collection::meta_ref.target() = MemberType::meta;
		PredefinedTypes::meta_Collection_children.target() = Collection::meta;

		CollocationGroup::meta_dstInstanceMapping.target() = NodeReference::meta;
		CollocationGroup::meta_members.target() = CollocationGroupMember::meta;
		DeploymentPlan::meta_CollocationGroup_children.target() = CollocationGroup::meta;

		CollocationGroupMember::meta_setCollocationGroup.target() = CollocationGroup::meta;
		DeploymentPlan::meta_CollocationGroupMember_children.target() = CollocationGroupMember::meta;
		CollocationGroupMember::meta.subTypes() += ComponentAssemblyReference::meta;
		CollocationGroupMember::meta.subTypes() += SharedComponentReference::meta;
		CollocationGroupMember::meta.subTypes() += ComponentFactoryRef::meta;
		CollocationGroupMember::meta.subTypes() += ComponentRef::meta;

		CommonPortAttrs::meta.subTypes() += Port::meta;

		CompRef::meta_srcComponentOperation.target() = OperationRef::meta;
		CompRef::meta_ref.target() = Component::meta;
		BenchmarkAnalysis::meta_CompRef_children.target() = CompRef::meta;

		Component::meta_referedbyCompRef.target() = CompRef::meta;
		Component::meta_dstAssemblyselectRequirement.target() = Requirement::meta;
		Component::meta_dstAssemblyConfigProperty.target() = Property::meta;
		Component::meta_referedbyComponentRef.target() = ComponentRef::meta;
		ReadonlyAttribute::meta_Component_parent.target() = Component::meta;
		Port::meta_Component_parent.target() = Component::meta;
		WorkerType::meta_Component_parent.target() = Component::meta;
		ComponentAssembly::meta_Component_children.target() = Component::meta;

		BenchmarkAnalysis::meta_ComponentAnalyses_parent.target() = ComponentAnalyses::meta;
		RootFolder::meta_ComponentAnalyses_children.target() = ComponentAnalyses::meta;

		ComponentAssembly::meta_referedbyComponentAssemblyReference.target() = ComponentAssemblyReference::meta;
		ComponentAssembly::meta_dstCriticalPath.target() = PathReference::meta;
		Property::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ComponentPackage::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ComponentPackageReference::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		Requirement::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		Component::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ComponentAssembly::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ProvidedRequestPort::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		RequiredRequestPort::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		InEventPort::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		OutEventPort::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		emit::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		EventSourceDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		EventSinkDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		deliverTo::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		publish::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AssemblyDeployRequirement::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ComponentAssemblyReference::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ComponentRef::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AssemblyselectRequirement::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AttributeValue::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AttributeDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AttributeMappingValue::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AssemblyConfigProperty::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		FacetDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		invoke::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ReceptacleDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AttributeMappingDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ExternalDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		AttributeMapping::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		PublishConnector::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ExternalPortReference::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		SupportsDelegate::meta_ComponentAssembly_parent.target() = ComponentAssembly::meta;
		ComponentAssembly::meta_ComponentAssembly_children.target() = ComponentAssembly::meta;

		ComponentAssemblyReference::meta_ref.target() = ComponentAssembly::meta;
		ComponentAssembly::meta_ComponentAssemblyReference_children.target() = ComponentAssemblyReference::meta;

		MPC::meta_ComponentBuild_parent.target() = ComponentBuild::meta;
		RootFolder::meta_ComponentBuild_children.target() = ComponentBuild::meta;

		ComponentContainer::meta_ComponentConfigProperty_children.target() = ComponentConfigProperty::meta;
		ComponentConfigProperty::meta.association() = Property::meta_srcComponentConfigProperty.parent();
		ComponentConfigProperty::meta_srcComponentConfigProperty_end_ = ComponentRef::meta_dstComponentConfigProperty_rev = Property::meta_srcComponentConfigProperty;
		ComponentConfigProperty::meta_dstComponentConfigProperty_end_ = Property::meta_srcComponentConfigProperty_rev = ComponentRef::meta_dstComponentConfigProperty;

		ComponentConfigProperty::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
		Property::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
		ComponentInfoProperty::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
		ComponentProperty::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
		ComponentPropertyDescription::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
		ComponentRef::meta_ComponentContainer_parent.target() = ComponentContainer::meta;
		ComponentTypes::meta_ComponentContainer_children.target() = ComponentContainer::meta;

		ComponentFactory::meta_referedbyComponentFactoryInstance.target() = ComponentFactoryInstance::meta;
		ComponentFactory::meta_dstManagesComponent.target() = Manageable::meta;
		LookupKey::meta_ComponentFactory_parent.target() = ComponentFactory::meta;
		FactoryOperation::meta_ComponentFactory_parent.target() = ComponentFactory::meta;
		LookupOperation::meta_ComponentFactory_parent.target() = ComponentFactory::meta;

		ComponentFactoryInstance::meta_ComponentFactoryImplementationContainer_parent.target() = ComponentFactoryImplementationContainer::meta;
		ComponentFactoryImplementations::meta_ComponentFactoryImplementationContainer_children.target() = ComponentFactoryImplementationContainer::meta;

		ComponentFactoryImplementationContainer::meta_ComponentFactoryImplementations_parent.target() = ComponentFactoryImplementations::meta;
		RootFolder::meta_ComponentFactoryImplementations_children.target() = ComponentFactoryImplementations::meta;

		ComponentFactoryInstance::meta_referedbyComponentFactoryRef.target() = ComponentFactoryRef::meta;
		ComponentFactoryInstance::meta_ref.target() = ComponentFactory::meta;
		ComponentFactoryImplementationContainer::meta_ComponentFactoryInstance_children.target() = ComponentFactoryInstance::meta;

		ComponentFactoryRef::meta_ref.target() = ComponentFactoryInstance::meta;
		ComponentFactoryRef::meta_dstDeploys.target() = ComponentRef::meta;

		ComponentImplementation::meta_dstImplementationDependsOn.target() = ImplementationDependency::meta;
		ComponentImplementation::meta_dstImplementationCapability.target() = Capability::meta;
		ComponentImplementation::meta_dstImplements.target() = ComponentRef::meta;
		ComponentImplementation::meta_referedbyComponentImplementationReference.target() = ComponentImplementationReference::meta;
		ComponentImplementationContainer::meta_ComponentImplementation_children.target() = ComponentImplementation::meta;
		ComponentImplementation::meta.subTypes() += ComponentAssembly::meta;
		ComponentImplementation::meta.subTypes() += MonolithicImplementation::meta;

		ComponentImplementationArtifact::meta_ref.target() = ImplementationArtifact::meta;

		Implements::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		ImplementationDependsOn::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		ComponentRef::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		ImplementationDependency::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		ImplementationCapability::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		Capability::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		CriticalPath::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		PathReference::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		ComponentImplementation::meta_ComponentImplementationContainer_parent.target() = ComponentImplementationContainer::meta;
		ComponentImplementations::meta_ComponentImplementationContainer_children.target() = ComponentImplementationContainer::meta;

		ComponentImplementationReference::meta_ref.target() = ComponentImplementation::meta;
		ComponentImplementationReference::meta_srcImplementation.target() = ComponentPackage::meta;
		PackageContainer::meta_ComponentImplementationReference_children.target() = ComponentImplementationReference::meta;

		ComponentImplementationContainer::meta_ComponentImplementations_parent.target() = ComponentImplementations::meta;
		RootFolder::meta_ComponentImplementations_children.target() = ComponentImplementations::meta;

		ComponentContainer::meta_ComponentInfoProperty_children.target() = ComponentInfoProperty::meta;
		ComponentInfoProperty::meta.association() = Property::meta_srcComponentInfoProperty.parent();
		ComponentInfoProperty::meta_srcComponentInfoProperty_end_ = ComponentRef::meta_dstComponentInfoProperty_rev = Property::meta_srcComponentInfoProperty;
		ComponentInfoProperty::meta_dstComponentInfoProperty_end_ = Property::meta_srcComponentInfoProperty_rev = ComponentRef::meta_dstComponentInfoProperty;

		ComponentLib::meta_dstExtResourceConn.target() = ExternalResources::meta;
		Project::meta_ComponentLib_children.target() = ComponentLib::meta;
		ComponentLib::meta.subTypes() += StubProject::meta;
		ComponentLib::meta.subTypes() += ServantProject::meta;
		ComponentLib::meta.subTypes() += ExecutorProject::meta;

		BenchmarkAnalysis::meta_ComponentOperation_children.target() = ComponentOperation::meta;
		ComponentOperation::meta.association() = OperationRef::meta_dstComponentOperation.parent();
		ComponentOperation::meta_dstComponentOperation_end_ = CompRef::meta_srcComponentOperation_rev = OperationRef::meta_dstComponentOperation;
		ComponentOperation::meta_srcComponentOperation_end_ = OperationRef::meta_dstComponentOperation_rev = CompRef::meta_srcComponentOperation;

		ComponentPackage::meta_dstImplementation.target() = ComponentImplementationReference::meta;
		ComponentPackage::meta_srcPackageConfBasePackage.target() = PackageConfiguration::meta;
		ComponentPackage::meta_dstPackageInterface.target() = ComponentRef::meta;
		ComponentPackage::meta_dstPackageConfigProperty.target() = Property::meta;
		ComponentPackage::meta_dstPackageInfoProperty.target() = Property::meta;
		ComponentPackage::meta_referedbyComponentPackageReference.target() = ComponentPackageReference::meta;
		ComponentAssembly::meta_ComponentPackage_children.target() = ComponentPackage::meta;
		PackageConfigurationContainer::meta_ComponentPackage_child.target() = ComponentPackage::meta;
		PackageContainer::meta_ComponentPackage_child.target() = ComponentPackage::meta;

		ComponentPackageReference::meta_srcPackageConfReference.target() = PackageConfiguration::meta;
		ComponentPackageReference::meta_ref.target() = ComponentPackage::meta;
		ComponentAssembly::meta_ComponentPackageReference_children.target() = ComponentPackageReference::meta;
		PackageConfigurationContainer::meta_ComponentPackageReference_child.target() = ComponentPackageReference::meta;

		PackageContainer::meta_ComponentPackages_parent.target() = ComponentPackages::meta;
		RootFolder::meta_ComponentPackages_children.target() = ComponentPackages::meta;

		ComponentContainer::meta_ComponentProperty_children.target() = ComponentProperty::meta;
		ComponentProperty::meta.association() = ComponentPropertyDescription::meta_srcComponentProperty.parent();
		ComponentProperty::meta_srcComponentProperty_end_ = ComponentRef::meta_dstComponentProperty_rev = ComponentPropertyDescription::meta_srcComponentProperty;
		ComponentProperty::meta_dstComponentProperty_end_ = ComponentPropertyDescription::meta_srcComponentProperty_rev = ComponentRef::meta_dstComponentProperty;

		ComponentPropertyDescription::meta_srcComponentProperty.target() = ComponentRef::meta;
		DataType::meta_ComponentPropertyDescription_parent.target() = ComponentPropertyDescription::meta;
		ComponentContainer::meta_ComponentPropertyDescription_children.target() = ComponentPropertyDescription::meta;

		ComponentRef::meta_referedbySharedComponentReference.target() = SharedComponentReference::meta;
		ComponentRef::meta_srcDeploys.target() = ComponentFactoryRef::meta;
		ComponentRef::meta_srcImplements.target() = ComponentImplementation::meta;
		ComponentRef::meta_dstComponentProperty.target() = ComponentPropertyDescription::meta;
		ComponentRef::meta_srcPackageInterface.target() = ComponentPackage::meta;
		ComponentRef::meta_dstComponentConfigProperty.target() = Property::meta;
		ComponentRef::meta_dstComponentInfoProperty.target() = Property::meta;
		ComponentRef::meta_ref.target() = Component::meta;
		ComponentAssembly::meta_ComponentRef_children.target() = ComponentRef::meta;
		Path::meta_ComponentRef_children.target() = ComponentRef::meta;
		ComponentImplementationContainer::meta_ComponentRef_child.target() = ComponentRef::meta;
		ComponentContainer::meta_ComponentRef_child.target() = ComponentRef::meta;
		PackageContainer::meta_ComponentRef_child.target() = ComponentRef::meta;
		Package::meta_ComponentRef_children.target() = ComponentRef::meta;
		File::meta_ComponentRef_children.target() = ComponentRef::meta;

		ComponentServantArtifact::meta_ref.target() = ImplementationArtifact::meta;

		ComponentContainer::meta_ComponentTypes_parent.target() = ComponentTypes::meta;
		RootFolder::meta_ComponentTypes_children.target() = ComponentTypes::meta;

		ImplementationContainer::meta_ConfigProperty_children.target() = ConfigProperty::meta;
		ConfigProperty::meta.association() = Implemenation::meta_dstConfigProperty.parent();
		ConfigProperty::meta_dstConfigProperty_end_ = Property::meta_srcConfigProperty_rev = Implemenation::meta_dstConfigProperty;
		ConfigProperty::meta_srcConfigProperty_end_ = Implemenation::meta_dstConfigProperty_rev = Property::meta_srcConfigProperty;

		Port::meta_ConnectedComponent_parent.target() = ConnectedComponent::meta;
		DstEdge::meta_ConnectedComponent_parent.target() = ConnectedComponent::meta;

		Constant::meta_ref.target() = ConstantType::meta;
		HasOperations::meta_Constant_children.target() = Constant::meta;
		Package::meta_Constant_children.target() = Constant::meta;
		File::meta_Constant_children.target() = Constant::meta;

		ConstantType::meta_referedbyDiscriminator.target() = Discriminator::meta;
		ConstantType::meta_referedbyConstant.target() = Constant::meta;
		ConstantType::meta.subTypes() += Enum::meta;
		ConstantType::meta.subTypes() += PredefinedType::meta;

		ComponentImplementationContainer::meta_CriticalPath_children.target() = CriticalPath::meta;
		CriticalPath::meta.association() = ComponentAssembly::meta_dstCriticalPath.parent();
		CriticalPath::meta_dstCriticalPath_end_ = PathReference::meta_srcCriticalPath_rev = ComponentAssembly::meta_dstCriticalPath;
		CriticalPath::meta_srcCriticalPath_end_ = ComponentAssembly::meta_dstCriticalPath_rev = PathReference::meta_srcCriticalPath;

		MetricsBase::meta_DataAnalysisBase_children.target() = DataAnalysisBase::meta;
		BenchmarkAnalysis::meta_DataAnalysisBase_children.target() = DataAnalysisBase::meta;
		DataAnalysisBase::meta.subTypes() += Average::meta;
		DataAnalysisBase::meta.subTypes() += Minimum::meta;
		DataAnalysisBase::meta.subTypes() += Maximum::meta;
		DataAnalysisBase::meta.subTypes() += Jitter::meta;

		DataType::meta_ref.target() = MemberType::meta;
		ComponentPropertyDescription::meta_DataType_child.target() = DataType::meta;
		SatisfierProperty::meta_DataType_child.target() = DataType::meta;
		Property::meta_DataType_child.target() = DataType::meta;

		InstanceMapping::meta_DeploymentPlan_parent.target() = DeploymentPlan::meta;
		NodeReference::meta_DeploymentPlan_parent.target() = DeploymentPlan::meta;
		CollocationGroup::meta_DeploymentPlan_parent.target() = DeploymentPlan::meta;
		Property::meta_DeploymentPlan_parent.target() = DeploymentPlan::meta;
		Deploys::meta_DeploymentPlan_parent.target() = DeploymentPlan::meta;
		CollocationGroupMember::meta_DeploymentPlan_parent.target() = DeploymentPlan::meta;
		DeploymentPlans::meta_DeploymentPlan_children.target() = DeploymentPlan::meta;

		DeploymentPlan::meta_DeploymentPlans_parent.target() = DeploymentPlans::meta;
		RootFolder::meta_DeploymentPlans_children.target() = DeploymentPlans::meta;

		DeploymentPlan::meta_Deploys_children.target() = Deploys::meta;
		Deploys::meta.association() = ComponentFactoryRef::meta_dstDeploys.parent();
		Deploys::meta_dstDeploys_end_ = ComponentRef::meta_srcDeploys_rev = ComponentFactoryRef::meta_dstDeploys;
		Deploys::meta_srcDeploys_end_ = ComponentFactoryRef::meta_dstDeploys_rev = ComponentRef::meta_srcDeploys;

		Discriminator::meta_ref.target() = ConstantType::meta;
		SwitchedAggregate::meta_Discriminator_child.target() = Discriminator::meta;

		Interconnect::meta_Domain_parent.target() = Domain::meta;
		InterconnectConnection::meta_Domain_parent.target() = Domain::meta;
		Node::meta_Domain_parent.target() = Domain::meta;
		BridgeConnection::meta_Domain_parent.target() = Domain::meta;
		Bridge::meta_Domain_parent.target() = Domain::meta;
		SharedResource::meta_Domain_parent.target() = Domain::meta;
		Shares::meta_Domain_parent.target() = Domain::meta;
		Property::meta_Domain_parent.target() = Domain::meta;
		Targets::meta_Domain_children.target() = Domain::meta;

		ConnectedComponent::meta_DstEdge_children.target() = DstEdge::meta;
		Path::meta_DstEdge_children.target() = DstEdge::meta;
		DstEdge::meta.association() = GraphVertex::meta_dstDstEdge.parent();
		DstEdge::meta_dstDstEdge_end_ = Edge::meta_srcDstEdge_rev = GraphVertex::meta_dstDstEdge;
		DstEdge::meta_srcDstEdge_end_ = GraphVertex::meta_dstDstEdge_rev = Edge::meta_srcDstEdge;

		ECRequirements::meta_ECBehavior_child.target() = ECBehavior::meta;

		ECRole::meta_ECRequirements_parent.target() = ECRequirements::meta;
		ECBehavior::meta_ECRequirements_parent.target() = ECRequirements::meta;

		ECRequirements::meta_ECRole_children.target() = ECRole::meta;

		Edge::meta_dstSrcEdge.target() = GraphVertex::meta;
		Edge::meta_srcDstEdge.target() = GraphVertex::meta;
		Edge::meta_srcPropertyConnector.target() = Property::meta;
		Path::meta_Edge_children.target() = Edge::meta;

		Path::meta_EdgeProperty_children.target() = EdgeProperty::meta;
		EdgeProperty::meta.association() = Edge::meta_srcPropertyConnector.parent();
		EdgeProperty::meta_srcPropertyConnector_end_ = Property::meta_dstPropertyConnector_rev = Edge::meta_srcPropertyConnector;
		EdgeProperty::meta_dstPropertyConnector_end_ = Edge::meta_srcPropertyConnector_rev = Property::meta_dstPropertyConnector;

		BehaviorModel::meta_Effect_children.target() = Effect::meta;
		Effect::meta.association() = ActionBase::meta_dstEffect.parent();
		Effect::meta_dstEffect_end_ = StateBase::meta_srcEffect_rev = ActionBase::meta_dstEffect;
		Effect::meta_srcEffect_end_ = ActionBase::meta_dstEffect_rev = StateBase::meta_srcEffect;

		EffectBase::meta.subTypes() += Effect::meta;
		EffectBase::meta.subTypes() += InputEffect::meta;
		EffectBase::meta.subTypes() += TerminalEffect::meta;

		EnumValue::meta_Enum_parent.target() = Enum::meta;

		Enum::meta_EnumValue_children.target() = EnumValue::meta;

		TopLevelBehavior::meta_Environment_child.target() = Environment::meta;

		Event::meta_referedbyEventRef.target() = EventRef::meta;
		Event::meta_referedbyInEventPort.target() = InEventPort::meta;
		Event::meta_referedbyOutEventPort.target() = OutEventPort::meta;
		BenchmarkAnalysis::meta_Event_children.target() = Event::meta;

		EventRef::meta_dstTimerEventSinkConn.target() = TimeProbe::meta;
		EventRef::meta_ref.target() = Event::meta;
		BenchmarkAnalysis::meta_EventRef_children.target() = EventRef::meta;

		ComponentAssembly::meta_EventSinkDelegate_children.target() = EventSinkDelegate::meta;
		EventSinkDelegate::meta.association() = InEventPort::meta_dstEventSinkDelegate.parent();
		EventSinkDelegate::meta_dstEventSinkDelegate_end_ = InEventPort::meta_srcEventSinkDelegate_rev = InEventPort::meta_dstEventSinkDelegate;
		EventSinkDelegate::meta_srcEventSinkDelegate_end_ = InEventPort::meta_dstEventSinkDelegate_rev = InEventPort::meta_srcEventSinkDelegate;

		ComponentAssembly::meta_EventSourceDelegate_children.target() = EventSourceDelegate::meta;
		EventSourceDelegate::meta.association() = OutEventPort::meta_dstEventSourceDelegate.parent();
		EventSourceDelegate::meta_dstEventSourceDelegate_end_ = OutEventPort::meta_srcEventSourceDelegate_rev = OutEventPort::meta_dstEventSourceDelegate;
		EventSourceDelegate::meta_srcEventSourceDelegate_end_ = OutEventPort::meta_dstEventSourceDelegate_rev = OutEventPort::meta_srcEventSourceDelegate;

		Exception::meta_referedbySetException.target() = SetException::meta;
		Exception::meta_referedbyGetException.target() = GetException::meta;
		Exception::meta_referedbyExceptionRef.target() = ExceptionRef::meta;
		Member::meta_Exception_parent.target() = Exception::meta;
		HasOperations::meta_Exception_children.target() = Exception::meta;
		Package::meta_Exception_children.target() = Exception::meta;
		File::meta_Exception_children.target() = Exception::meta;

		ExceptionRef::meta_ref.target() = Exception::meta;
		HasExceptions::meta_ExceptionRef_children.target() = ExceptionRef::meta;

		ImplementationArtifactReference::meta_ExecutorProject_parent.target() = ExecutorProject::meta;

		Project::meta_ExtResourceConn_children.target() = ExtResourceConn::meta;
		ExtResourceConn::meta.association() = ExternalResources::meta_srcExtResourceConn.parent();
		ExtResourceConn::meta_srcExtResourceConn_end_ = ComponentLib::meta_dstExtResourceConn_rev = ExternalResources::meta_srcExtResourceConn;
		ExtResourceConn::meta_dstExtResourceConn_end_ = ExternalResources::meta_srcExtResourceConn_rev = ComponentLib::meta_dstExtResourceConn;

		ComponentAssembly::meta_ExternalDelegate_children.target() = ExternalDelegate::meta;
		ExternalDelegate::meta.association() = ExternalPortReference::meta_dstExternalDelegate.parent();
		ExternalDelegate::meta_dstExternalDelegate_end_ = Port::meta_srcExternalDelegate_rev = ExternalPortReference::meta_dstExternalDelegate;
		ExternalDelegate::meta_srcExternalDelegate_end_ = ExternalPortReference::meta_dstExternalDelegate_rev = Port::meta_srcExternalDelegate;

		ExternalPortReference::meta_ref.target() = ExternalPortReferenceType::meta;
		ExternalPortReference::meta_dstExternalDelegate.target() = Port::meta;
		ComponentAssembly::meta_ExternalPortReference_children.target() = ExternalPortReference::meta;

		ExternalPortReferenceType::meta_referedbyExternalPortReference.target() = ExternalPortReference::meta;
		ExternalPortReferenceType::meta.subTypes() += Provideable::meta;
		ExternalPortReferenceType::meta.subTypes() += Event::meta;

		ExternalResources::meta_ref.target() = ImplementationArtifact::meta;
		ExternalResources::meta_srcExtResourceConn.target() = ComponentLib::meta;
		Project::meta_ExternalResources_children.target() = ExternalResources::meta;

		ComponentAssembly::meta_FacetDelegate_children.target() = FacetDelegate::meta;
		FacetDelegate::meta.association() = ProvidedRequestPort::meta_dstFacetDelegate.parent();
		FacetDelegate::meta_dstFacetDelegate_end_ = ProvidedRequestPort::meta_srcFacetDelegate_rev = ProvidedRequestPort::meta_dstFacetDelegate;
		FacetDelegate::meta_srcFacetDelegate_end_ = ProvidedRequestPort::meta_dstFacetDelegate_rev = ProvidedRequestPort::meta_srcFacetDelegate;

		ComponentFactory::meta_FactoryOperation_children.target() = FactoryOperation::meta;
		ObjectByValue::meta_FactoryOperation_children.target() = FactoryOperation::meta;

		File::meta_referedbyFileRef.target() = FileRef::meta;
		ManagesComponent::meta_File_parent.target() = File::meta;
		ComponentRef::meta_File_parent.target() = File::meta;
		Package::meta_File_parent.target() = File::meta;
		Exception::meta_File_parent.target() = File::meta;
		FileRef::meta_File_parent.target() = File::meta;
		Constant::meta_File_parent.target() = File::meta;
		NamedType::meta_File_parent.target() = File::meta;
		InterfaceDefinitions::meta_File_children.target() = File::meta;

		FileRef::meta_ref.target() = File::meta;
		File::meta_FileRef_children.target() = FileRef::meta;
		StubProject::meta_FileRef_child.target() = FileRef::meta;
		ServantProject::meta_FileRef_child.target() = FileRef::meta;

		BehaviorModel::meta_Finish_children.target() = Finish::meta;
		Finish::meta.association() = BehaviorInputAction::meta_srcFinish.parent();
		Finish::meta_srcFinish_end_ = StateBase::meta_dstFinish_rev = BehaviorInputAction::meta_srcFinish;
		Finish::meta_dstFinish_end_ = BehaviorInputAction::meta_srcFinish_rev = StateBase::meta_dstFinish;

		GetException::meta_ref.target() = Exception::meta;
		ReadonlyAttribute::meta_GetException_children.target() = GetException::meta;

		GraphVertex::meta_srcSrcEdge.target() = Edge::meta;
		GraphVertex::meta_dstDstEdge.target() = Edge::meta;
		Path::meta_GraphVertex_children.target() = GraphVertex::meta;
		GraphVertex::meta.subTypes() += ConnectedComponent::meta;
		GraphVertex::meta.subTypes() += DisplayNode::meta;
		GraphVertex::meta.subTypes() += Port::meta;

		ExceptionRef::meta_HasExceptions_parent.target() = HasExceptions::meta;
		HasExceptions::meta.subTypes() += LookupOperation::meta;
		HasExceptions::meta.subTypes() += FactoryOperation::meta;
		HasExceptions::meta.subTypes() += TwowayOperation::meta;

		TwowayOperation::meta_HasOperations_parent.target() = HasOperations::meta;
		OnewayOperation::meta_HasOperations_parent.target() = HasOperations::meta;
		Exception::meta_HasOperations_parent.target() = HasOperations::meta;
		Constant::meta_HasOperations_parent.target() = HasOperations::meta;
		NoInheritable::meta_HasOperations_parent.target() = HasOperations::meta;
		HasOperations::meta.subTypes() += ComponentFactory::meta;
		HasOperations::meta.subTypes() += Object::meta;
		HasOperations::meta.subTypes() += ObjectByValue::meta;

		Implemenation::meta_dstInfoProperty.target() = Property::meta;
		Implemenation::meta_dstConfigProperty.target() = Property::meta;
		Implemenation::meta.subTypes() += MonolithicImplementationBase::meta;
		Implemenation::meta.subTypes() += ComponentImplementation::meta;

		PackageContainer::meta_Implementation_children.target() = Implementation::meta;
		Implementation::meta.association() = ComponentImplementationReference::meta_srcImplementation.parent();
		Implementation::meta_srcImplementation_end_ = ComponentPackage::meta_dstImplementation_rev = ComponentImplementationReference::meta_srcImplementation;
		Implementation::meta_dstImplementation_end_ = ComponentImplementationReference::meta_srcImplementation_rev = ComponentPackage::meta_dstImplementation;

		ImplementationArtifact::meta_referedbyComponentServantArtifact.target() = ComponentServantArtifact::meta;
		ImplementationArtifact::meta_referedbyComponentImplemenationArtifact.target() = ComponentImplementationArtifact::meta;
		ImplementationArtifact::meta_referedbyImplementationArtifactReference.target() = ImplementationArtifactReference::meta;
		ImplementationArtifact::meta_dstArtifactDependsOn.target() = ImplementationArtifactReference::meta;
		ImplementationArtifact::meta_dstArtifactDeployRequirement.target() = Requirement::meta;
		ImplementationArtifact::meta_dstArtifactExecParameter.target() = Property::meta;
		ImplementationArtifact::meta_dstArtifactInfoProperty.target() = Property::meta;
		ImplementationArtifact::meta_dstArtifactDependency.target() = ImplementationArtifact::meta;
		ImplementationArtifact::meta_srcArtifactDependency.target() = ImplementationArtifact::meta;
		ImplementationArtifact::meta_referedbyExternalResources.target() = ExternalResources::meta;
		ArtifactContainer::meta_ImplementationArtifact_children.target() = ImplementationArtifact::meta;
		Project::meta_ImplementationArtifact_children.target() = ImplementationArtifact::meta;

		ImplementationArtifactReference::meta_srcMonolithprimaryArtifact.target() = MonolithicImplementationBase::meta;
		ImplementationArtifactReference::meta_ref.target() = ImplementationArtifact::meta;
		ImplementationArtifactReference::meta_srcArtifactDependsOn.target() = ImplementationArtifact::meta;
		ImplementationContainer::meta_ImplementationArtifactReference_children.target() = ImplementationArtifactReference::meta;
		ArtifactContainer::meta_ImplementationArtifactReference_children.target() = ImplementationArtifactReference::meta;
		StubProject::meta_ImplementationArtifactReference_child.target() = ImplementationArtifactReference::meta;
		ServantProject::meta_ImplementationArtifactReference_child.target() = ImplementationArtifactReference::meta;
		ExecutorProject::meta_ImplementationArtifactReference_child.target() = ImplementationArtifactReference::meta;
		ImplementationArtifactReference::meta.subTypes() += ComponentServantArtifact::meta;
		ImplementationArtifactReference::meta.subTypes() += ComponentImplementationArtifact::meta;

		ArtifactContainer::meta_ImplementationArtifacts_parent.target() = ImplementationArtifacts::meta;
		RootFolder::meta_ImplementationArtifacts_children.target() = ImplementationArtifacts::meta;

		ComponentImplementationContainer::meta_ImplementationCapability_children.target() = ImplementationCapability::meta;
		ImplementationCapability::meta.association() = ComponentImplementation::meta_dstImplementationCapability.parent();
		ImplementationCapability::meta_dstImplementationCapability_end_ = Capability::meta_srcImplementationCapability_rev = ComponentImplementation::meta_dstImplementationCapability;
		ImplementationCapability::meta_srcImplementationCapability_end_ = ComponentImplementation::meta_dstImplementationCapability_rev = Capability::meta_srcImplementationCapability;

		ConfigProperty::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		InfoProperty::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		Property::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		MonolithprimaryArtifact::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		MonolithDeployRequirement::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		MonolithExecParameter::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		ImplementationArtifactReference::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		ImplementationRequirement::meta_ImplementationContainer_parent.target() = ImplementationContainer::meta;
		ImplementationContainer::meta.subTypes() += ComponentFactoryImplementationContainer::meta;
		ImplementationContainer::meta.subTypes() += ComponentImplementationContainer::meta;

		ImplementationDependency::meta_srcImplementationDependsOn.target() = ComponentImplementation::meta;
		ComponentImplementationContainer::meta_ImplementationDependency_children.target() = ImplementationDependency::meta;

		ComponentImplementationContainer::meta_ImplementationDependsOn_children.target() = ImplementationDependsOn::meta;
		ImplementationDependsOn::meta.association() = ComponentImplementation::meta_dstImplementationDependsOn.parent();
		ImplementationDependsOn::meta_dstImplementationDependsOn_end_ = ImplementationDependency::meta_srcImplementationDependsOn_rev = ComponentImplementation::meta_dstImplementationDependsOn;
		ImplementationDependsOn::meta_srcImplementationDependsOn_end_ = ComponentImplementation::meta_dstImplementationDependsOn_rev = ImplementationDependency::meta_srcImplementationDependsOn;

		ImplementationRequirement::meta_srcMonolithDeployRequirement.target() = MonolithicImplementationBase::meta;
		ImplementationContainer::meta_ImplementationRequirement_children.target() = ImplementationRequirement::meta;

		ComponentImplementationContainer::meta_Implements_child.target() = Implements::meta;
		Implements::meta.association() = ComponentImplementation::meta_dstImplements.parent();
		Implements::meta_dstImplements_end_ = ComponentRef::meta_srcImplements_rev = ComponentImplementation::meta_dstImplements;
		Implements::meta_srcImplements_end_ = ComponentImplementation::meta_dstImplements_rev = ComponentRef::meta_srcImplements;

		InEventPort::meta_srcdeliverTo.target() = PublishConnector::meta;
		InEventPort::meta_ref.target() = Event::meta;
		InEventPort::meta_dstEventSinkDelegate.target() = InEventPort::meta;
		InEventPort::meta_srcEventSinkDelegate.target() = InEventPort::meta;
		InEventPort::meta_srcemit.target() = OutEventPort::meta;
		ComponentAssembly::meta_InEventPort_children.target() = InEventPort::meta;

		InParameter::meta_ref.target() = MemberType::meta;
		OperationBase::meta_InParameter_children.target() = InParameter::meta;

		ImplementationContainer::meta_InfoProperty_children.target() = InfoProperty::meta;
		InfoProperty::meta.association() = Implemenation::meta_dstInfoProperty.parent();
		InfoProperty::meta_dstInfoProperty_end_ = Property::meta_srcInfoProperty_rev = Implemenation::meta_dstInfoProperty;
		InfoProperty::meta_srcInfoProperty_end_ = Implemenation::meta_dstInfoProperty_rev = Property::meta_srcInfoProperty;

		Inheritable::meta_referedbyInherits.target() = Inherits::meta;
		ReadonlyAttribute::meta_Inheritable_parent.target() = Inheritable::meta;
		Inherits::meta_Inheritable_parent.target() = Inheritable::meta;
		Inheritable::meta.subTypes() += HasOperations::meta;

		Inherits::meta_ref.target() = Inheritable::meta;
		Inheritable::meta_Inherits_children.target() = Inherits::meta;

		InoutParameter::meta_ref.target() = MemberType::meta;
		TwowayOperation::meta_InoutParameter_children.target() = InoutParameter::meta;

		TopLevelBehavior::meta_Input_children.target() = Input::meta;
		Input::meta.association() = InputAction::meta_srcInput.parent();
		Input::meta_srcInput_end_ = SingleInputBase::meta_dstInput_rev = InputAction::meta_srcInput;
		Input::meta_dstInput_end_ = InputAction::meta_srcInput_rev = SingleInputBase::meta_dstInput;

		InputAction::meta_srcInput.target() = SingleInputBase::meta;

		BehaviorModel::meta_InputEffect_children.target() = InputEffect::meta;
		InputEffect::meta.association() = BehaviorInputAction::meta_dstInputEffect.parent();
		InputEffect::meta_dstInputEffect_end_ = StateBase::meta_srcInputEffect_rev = BehaviorInputAction::meta_dstInputEffect;
		InputEffect::meta_srcInputEffect_end_ = BehaviorInputAction::meta_dstInputEffect_rev = StateBase::meta_srcInputEffect;

		DeploymentPlan::meta_InstanceMapping_children.target() = InstanceMapping::meta;
		InstanceMapping::meta.association() = NodeReference::meta_srcInstanceMapping.parent();
		InstanceMapping::meta_srcInstanceMapping_end_ = CollocationGroup::meta_dstInstanceMapping_rev = NodeReference::meta_srcInstanceMapping;
		InstanceMapping::meta_dstInstanceMapping_end_ = NodeReference::meta_srcInstanceMapping_rev = CollocationGroup::meta_dstInstanceMapping;

		Interconnect::meta_srcInterconnectConnection.target() = Node::meta;
		Interconnect::meta_dstBridgeConnection.target() = Bridge::meta;
		Resource::meta_Interconnect_parent.target() = Interconnect::meta;
		Domain::meta_Interconnect_children.target() = Interconnect::meta;

		Domain::meta_InterconnectConnection_children.target() = InterconnectConnection::meta;
		InterconnectConnection::meta.association() = Interconnect::meta_srcInterconnectConnection.parent();
		InterconnectConnection::meta_srcInterconnectConnection_end_ = Node::meta_dstInterconnectConnection_rev = Interconnect::meta_srcInterconnectConnection;
		InterconnectConnection::meta_dstInterconnectConnection_end_ = Interconnect::meta_srcInterconnectConnection_rev = Node::meta_dstInterconnectConnection;

		File::meta_InterfaceDefinitions_parent.target() = InterfaceDefinitions::meta;
		RootFolder::meta_InterfaceDefinitions_children.target() = InterfaceDefinitions::meta;

		InvokePortBase::meta_srcinvoke.target() = RequiredRequestPort::meta;
		InvokePortBase::meta.subTypes() += ProvidedRequestPort::meta;
		InvokePortBase::meta.subTypes() += Supports::meta;

		Label::meta_srcLabelConnection.target() = Member::meta;
		SwitchedAggregate::meta_Label_children.target() = Label::meta;

		SwitchedAggregate::meta_LabelConnection_children.target() = LabelConnection::meta;
		LabelConnection::meta.association() = Label::meta_srcLabelConnection.parent();
		LabelConnection::meta_srcLabelConnection_end_ = Member::meta_dstLabelConnection_rev = Label::meta_srcLabelConnection;
		LabelConnection::meta_dstLabelConnection_end_ = Label::meta_srcLabelConnection_rev = Member::meta_dstLabelConnection;

		LookupKey::meta_ref.target() = ValueObject::meta;
		ComponentFactory::meta_LookupKey_child.target() = LookupKey::meta;

		ComponentFactory::meta_LookupOperation_children.target() = LookupOperation::meta;

		LoopState::meta_dstLoopTransition.target() = ActionBase::meta;
		LoopState::meta.subTypes() += ForState::meta;
		LoopState::meta.subTypes() += DoWhileState::meta;
		LoopState::meta.subTypes() += WhileState::meta;

		BehaviorModel::meta_LoopTransition_children.target() = LoopTransition::meta;
		LoopTransition::meta.association() = ActionBase::meta_srcLoopTransition.parent();
		LoopTransition::meta_srcLoopTransition_end_ = LoopState::meta_dstLoopTransition_rev = ActionBase::meta_srcLoopTransition;
		LoopTransition::meta_dstLoopTransition_end_ = ActionBase::meta_srcLoopTransition_rev = LoopState::meta_dstLoopTransition;

		Project::meta_MPC_parent.target() = MPC::meta;
		Workspaces::meta_MPC_parent.target() = MPC::meta;
		ComponentBuild::meta_MPC_children.target() = MPC::meta;

		ObjectByValue::meta_MakeMemberPrivate_children.target() = MakeMemberPrivate::meta;
		MakeMemberPrivate::meta.association() = PrivateFlag::meta_srcMakeMemberPrivate.parent();
		MakeMemberPrivate::meta_srcMakeMemberPrivate_end_ = Member::meta_dstMakeMemberPrivate_rev = PrivateFlag::meta_srcMakeMemberPrivate;
		MakeMemberPrivate::meta_dstMakeMemberPrivate_end_ = PrivateFlag::meta_srcMakeMemberPrivate_rev = Member::meta_dstMakeMemberPrivate;

		Manageable::meta_srcManagesComponent.target() = ComponentFactory::meta;
		Manageable::meta.subTypes() += ComponentRef::meta;
		Manageable::meta.subTypes() += Component::meta;

		File::meta_ManagesComponent_children.target() = ManagesComponent::meta;
		Package::meta_ManagesComponent_children.target() = ManagesComponent::meta;
		ManagesComponent::meta.association() = Manageable::meta_srcManagesComponent.parent();
		ManagesComponent::meta_srcManagesComponent_end_ = ComponentFactory::meta_dstManagesComponent_rev = Manageable::meta_srcManagesComponent;
		ManagesComponent::meta_dstManagesComponent_end_ = Manageable::meta_srcManagesComponent_rev = ComponentFactory::meta_dstManagesComponent;

		Member::meta_dstMakeMemberPrivate.target() = PrivateFlag::meta;
		Member::meta_dstLabelConnection.target() = Label::meta;
		Member::meta_ref.target() = MemberType::meta;
		ObjectByValue::meta_Member_children.target() = Member::meta;
		Aggregate::meta_Member_children.target() = Member::meta;
		SwitchedAggregate::meta_Member_children.target() = Member::meta;
		Exception::meta_Member_children.target() = Member::meta;

		MemberType::meta_referedbyDataType.target() = DataType::meta;
		MemberType::meta_referedbyInParameter.target() = InParameter::meta;
		MemberType::meta_referedbyInoutParameter.target() = InoutParameter::meta;
		MemberType::meta_referedbyOutParameter.target() = OutParameter::meta;
		MemberType::meta_referedbyReturnType.target() = ReturnType::meta;
		MemberType::meta_referedbyParameterType.target() = ParameterType::meta;
		MemberType::meta_referedbyAttributeMember.target() = AttributeMember::meta;
		MemberType::meta_referedbyAlias.target() = Alias::meta;
		MemberType::meta_referedbyBoxed.target() = Boxed::meta;
		MemberType::meta_referedbyCollection.target() = Collection::meta;
		MemberType::meta_referedbyMember.target() = Member::meta;
		MemberType::meta.subTypes() += NamedType::meta;
		MemberType::meta.subTypes() += PredefinedType::meta;

		BenchmarkAnalysis::meta_MetricConnection_children.target() = MetricConnection::meta;
		MetricConnection::meta.association() = MetricsBase::meta_srcMetricConnection.parent();
		MetricConnection::meta_srcMetricConnection_end_ = OperationRef::meta_dstMetricConnection_rev = MetricsBase::meta_srcMetricConnection;
		MetricConnection::meta_dstMetricConnection_end_ = MetricsBase::meta_srcMetricConnection_rev = OperationRef::meta_dstMetricConnection;

		MetricsBase::meta_srcMetricConnection.target() = OperationRef::meta;
		MetricsBase::meta_dstWorkloadCharacteristics.target() = TaskSet::meta;
		MetricsBase::meta_srcBenchmarkCharacteristics.target() = BenchmarkType::meta;
		DataAnalysisBase::meta_MetricsBase_parent.target() = MetricsBase::meta;
		BenchmarkAnalysis::meta_MetricsBase_children.target() = MetricsBase::meta;
		MetricsBase::meta.subTypes() += Latency::meta;
		MetricsBase::meta.subTypes() += Throughput::meta;

		MgaObject::meta.subTypes() += InfoProperty::meta;
		MgaObject::meta.subTypes() += ConfigProperty::meta;
		MgaObject::meta.subTypes() += MonolithprimaryArtifact::meta;
		MgaObject::meta.subTypes() += MonolithDeployRequirement::meta;
		MgaObject::meta.subTypes() += MonolithExecParameter::meta;
		MgaObject::meta.subTypes() += ImplementationContainer::meta;
		MgaObject::meta.subTypes() += Implemenation::meta;
		MgaObject::meta.subTypes() += ServiceProvider::meta;
		MgaObject::meta.subTypes() += MultipleServiceRequests::meta;
		MgaObject::meta.subTypes() += ServiceLevels::meta;
		MgaObject::meta.subTypes() += ServiceConsumer::meta;
		MgaObject::meta.subTypes() += ECBehavior::meta;
		MgaObject::meta.subTypes() += ECRole::meta;
		MgaObject::meta.subTypes() += ExternalPortReferenceType::meta;
		MgaObject::meta.subTypes() += ExternalPortReference::meta;
		MgaObject::meta.subTypes() += Path::meta;
		MgaObject::meta.subTypes() += DstEdge::meta;
		MgaObject::meta.subTypes() += GraphVertex::meta;
		MgaObject::meta.subTypes() += SrcEdge::meta;
		MgaObject::meta.subTypes() += EdgeProperty::meta;
		MgaObject::meta.subTypes() += Edge::meta;
		MgaObject::meta.subTypes() += Paths::meta;
		MgaObject::meta.subTypes() += PathProperty::meta;
		MgaObject::meta.subTypes() += PathReference::meta;
		MgaObject::meta.subTypes() += MetricConnection::meta;
		MgaObject::meta.subTypes() += DataAnalysisBase::meta;
		MgaObject::meta.subTypes() += TimeProbe::meta;
		MgaObject::meta.subTypes() += TimerConnection::meta;
		MgaObject::meta.subTypes() += BenchmarkAnalysis::meta;
		MgaObject::meta.subTypes() += MetricsBase::meta;
		MgaObject::meta.subTypes() += OperationRef::meta;
		MgaObject::meta.subTypes() += EventRef::meta;
		MgaObject::meta.subTypes() += TimerEventSinkConn::meta;
		MgaObject::meta.subTypes() += TaskSet::meta;
		MgaObject::meta.subTypes() += Task::meta;
		MgaObject::meta.subTypes() += WorkloadCharacteristics::meta;
		MgaObject::meta.subTypes() += ComponentOperation::meta;
		MgaObject::meta.subTypes() += CompRef::meta;
		MgaObject::meta.subTypes() += WorkLoadOperationConnection::meta;
		MgaObject::meta.subTypes() += BenchmarkType::meta;
		MgaObject::meta.subTypes() += BenchmarkCharacteristics::meta;
		MgaObject::meta.subTypes() += NodeReference::meta;
		MgaObject::meta.subTypes() += Interconnect::meta;
		MgaObject::meta.subTypes() += Node::meta;
		MgaObject::meta.subTypes() += Bridge::meta;
		MgaObject::meta.subTypes() += InstanceMapping::meta;
		MgaObject::meta.subTypes() += CollocationGroup::meta;
		MgaObject::meta.subTypes() += Deploys::meta;
		MgaObject::meta.subTypes() += CollocationGroupMember::meta;
		MgaObject::meta.subTypes() += DeploymentPlan::meta;
		MgaObject::meta.subTypes() += invoke::meta;
		MgaObject::meta.subTypes() += AssemblyselectRequirement::meta;
		MgaObject::meta.subTypes() += AssemblyConfigProperty::meta;
		MgaObject::meta.subTypes() += PublishConnector::meta;
		MgaObject::meta.subTypes() += publish::meta;
		MgaObject::meta.subTypes() += deliverTo::meta;
		MgaObject::meta.subTypes() += AssemblyDeployRequirement::meta;
		MgaObject::meta.subTypes() += emit::meta;
		MgaObject::meta.subTypes() += ReceptacleDelegate::meta;
		MgaObject::meta.subTypes() += FacetDelegate::meta;
		MgaObject::meta.subTypes() += EventSourceDelegate::meta;
		MgaObject::meta.subTypes() += EventSinkDelegate::meta;
		MgaObject::meta.subTypes() += ExternalDelegate::meta;
		MgaObject::meta.subTypes() += AttributeValue::meta;
		MgaObject::meta.subTypes() += AttributeDelegate::meta;
		MgaObject::meta.subTypes() += AttributeMapping::meta;
		MgaObject::meta.subTypes() += AttributeMappingValue::meta;
		MgaObject::meta.subTypes() += AttributeMappingDelegate::meta;
		MgaObject::meta.subTypes() += SupportsDelegate::meta;
		MgaObject::meta.subTypes() += InvokePortBase::meta;
		MgaObject::meta.subTypes() += ImplementationCapability::meta;
		MgaObject::meta.subTypes() += ImplementationDependsOn::meta;
		MgaObject::meta.subTypes() += Implements::meta;
		MgaObject::meta.subTypes() += CriticalPath::meta;
		MgaObject::meta.subTypes() += ComponentImplementationReference::meta;
		MgaObject::meta.subTypes() += PackageConfBasePackage::meta;
		MgaObject::meta.subTypes() += PackageConfReference::meta;
		MgaObject::meta.subTypes() += PackageConfigurationContainer::meta;
		MgaObject::meta.subTypes() += PackageConfConfigProperty::meta;
		MgaObject::meta.subTypes() += PackageConfSelectRequirement::meta;
		MgaObject::meta.subTypes() += PackageConfSpecializedConfig::meta;
		MgaObject::meta.subTypes() += PackageConfigurationReference::meta;
		MgaObject::meta.subTypes() += PackageConfiguration::meta;
		MgaObject::meta.subTypes() += ArtifactDependsOn::meta;
		MgaObject::meta.subTypes() += ArtifactDeployRequirement::meta;
		MgaObject::meta.subTypes() += ArtifactContainer::meta;
		MgaObject::meta.subTypes() += ArtifactExecParameter::meta;
		MgaObject::meta.subTypes() += ArtifactInfoProperty::meta;
		MgaObject::meta.subTypes() += ArtifactDependency::meta;
		MgaObject::meta.subTypes() += ImplementationArtifactReference::meta;
		MgaObject::meta.subTypes() += ImplementationArtifact::meta;
		MgaObject::meta.subTypes() += ComponentPropertyDescription::meta;
		MgaObject::meta.subTypes() += ComponentProperty::meta;
		MgaObject::meta.subTypes() += ComponentContainer::meta;
		MgaObject::meta.subTypes() += ComponentConfigProperty::meta;
		MgaObject::meta.subTypes() += ComponentInfoProperty::meta;
		MgaObject::meta.subTypes() += CommonPortAttrs::meta;
		MgaObject::meta.subTypes() += TopLevelPackageContainer::meta;
		MgaObject::meta.subTypes() += TopLevelPackage::meta;
		MgaObject::meta.subTypes() += package::meta;
		MgaObject::meta.subTypes() += PackageInterface::meta;
		MgaObject::meta.subTypes() += Implementation::meta;
		MgaObject::meta.subTypes() += PackageContainer::meta;
		MgaObject::meta.subTypes() += PackageConfigProperty::meta;
		MgaObject::meta.subTypes() += PackageInfoProperty::meta;
		MgaObject::meta.subTypes() += ComponentPackage::meta;
		MgaObject::meta.subTypes() += ComponentPackageReference::meta;
		MgaObject::meta.subTypes() += DataType::meta;
		MgaObject::meta.subTypes() += SatisfierProperty::meta;
		MgaObject::meta.subTypes() += ImplementationDependency::meta;
		MgaObject::meta.subTypes() += RequirementSatisfier::meta;
		MgaObject::meta.subTypes() += RequirementBase::meta;
		MgaObject::meta.subTypes() += Property::meta;
		MgaObject::meta.subTypes() += Shares::meta;
		MgaObject::meta.subTypes() += InterconnectConnection::meta;
		MgaObject::meta.subTypes() += BridgeConnection::meta;
		MgaObject::meta.subTypes() += Domain::meta;
		MgaObject::meta.subTypes() += Prefixable::meta;
		MgaObject::meta.subTypes() += Taggable::meta;
		MgaObject::meta.subTypes() += Manageable::meta;
		MgaObject::meta.subTypes() += ManagesComponent::meta;
		MgaObject::meta.subTypes() += ReturnType::meta;
		MgaObject::meta.subTypes() += ParameterType::meta;
		MgaObject::meta.subTypes() += Inherits::meta;
		MgaObject::meta.subTypes() += SupportsInterfaces::meta;
		MgaObject::meta.subTypes() += LookupKey::meta;
		MgaObject::meta.subTypes() += SetException::meta;
		MgaObject::meta.subTypes() += GetException::meta;
		MgaObject::meta.subTypes() += PrivateFlag::meta;
		MgaObject::meta.subTypes() += MakeMemberPrivate::meta;
		MgaObject::meta.subTypes() += AttributeMember::meta;
		MgaObject::meta.subTypes() += EnumValue::meta;
		MgaObject::meta.subTypes() += Label::meta;
		MgaObject::meta.subTypes() += LabelConnection::meta;
		MgaObject::meta.subTypes() += MemberType::meta;
		MgaObject::meta.subTypes() += Discriminator::meta;
		MgaObject::meta.subTypes() += Member::meta;
		MgaObject::meta.subTypes() += ExceptionRef::meta;
		MgaObject::meta.subTypes() += ConstantType::meta;
		MgaObject::meta.subTypes() += FileRef::meta;
		MgaObject::meta.subTypes() += Project::meta;
		MgaObject::meta.subTypes() += ExternalResources::meta;
		MgaObject::meta.subTypes() += ExtResourceConn::meta;
		MgaObject::meta.subTypes() += ComponentLib::meta;
		MgaObject::meta.subTypes() += MPC::meta;
		MgaObject::meta.subTypes() += Workspaces::meta;
		MgaObject::meta.subTypes() += WorkerLibrary::meta;
		MgaObject::meta.subTypes() += Worker::meta;
		MgaObject::meta.subTypes() += WorkerType::meta;
		MgaObject::meta.subTypes() += WorkerPackageBase::meta;
		MgaObject::meta.subTypes() += Variable::meta;
		MgaObject::meta.subTypes() += BehaviorModel::meta;
		MgaObject::meta.subTypes() += BehaviorInputAction::meta;
		MgaObject::meta.subTypes() += Finish::meta;
		MgaObject::meta.subTypes() += QueryInputAction::meta;
		MgaObject::meta.subTypes() += ActionBase::meta;
		MgaObject::meta.subTypes() += Input::meta;
		MgaObject::meta.subTypes() += SingleInputBase::meta;
		MgaObject::meta.subTypes() += MultiInputBase::meta;
		MgaObject::meta.subTypes() += MultiOutputBase::meta;
		MgaObject::meta.subTypes() += SingleOutputBase::meta;
		MgaObject::meta.subTypes() += MultiInput::meta;
		MgaObject::meta.subTypes() += QueryInput::meta;
		MgaObject::meta.subTypes() += QueryInputBase::meta;
		MgaObject::meta.subTypes() += Transition::meta;
		MgaObject::meta.subTypes() += BranchTransition::meta;
		MgaObject::meta.subTypes() += LoopTransition::meta;
		MgaObject::meta.subTypes() += StateBase::meta;
		MgaObject::meta.subTypes() += Terminal::meta;
		MgaObject::meta.subTypes() += TerminalTransition::meta;
		MgaObject::meta.subTypes() += EffectBase::meta;

		ImplementationContainer::meta_MonolithDeployRequirement_children.target() = MonolithDeployRequirement::meta;
		MonolithDeployRequirement::meta.association() = MonolithicImplementationBase::meta_dstMonolithDeployRequirement.parent();
		MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_ = ImplementationRequirement::meta_srcMonolithDeployRequirement_rev = MonolithicImplementationBase::meta_dstMonolithDeployRequirement;
		MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_ = MonolithicImplementationBase::meta_dstMonolithDeployRequirement_rev = ImplementationRequirement::meta_srcMonolithDeployRequirement;

		ImplementationContainer::meta_MonolithExecParameter_children.target() = MonolithExecParameter::meta;
		MonolithExecParameter::meta.association() = MonolithicImplementationBase::meta_dstMonolithExecParameter.parent();
		MonolithExecParameter::meta_dstMonolithExecParameter_end_ = Property::meta_srcMonolithExecParameter_rev = MonolithicImplementationBase::meta_dstMonolithExecParameter;
		MonolithExecParameter::meta_srcMonolithExecParameter_end_ = MonolithicImplementationBase::meta_dstMonolithExecParameter_rev = Property::meta_srcMonolithExecParameter;

		MonolithicImplementationBase::meta_dstMonolithExecParameter.target() = Property::meta;
		MonolithicImplementationBase::meta_dstMonolithDeployRequirement.target() = ImplementationRequirement::meta;
		MonolithicImplementationBase::meta_dstMonolithprimaryArtifact.target() = ImplementationArtifactReference::meta;
		MonolithicImplementationBase::meta.subTypes() += ComponentFactoryInstance::meta;
		MonolithicImplementationBase::meta.subTypes() += MonolithicImplementation::meta;

		ImplementationContainer::meta_MonolithprimaryArtifact_children.target() = MonolithprimaryArtifact::meta;
		MonolithprimaryArtifact::meta.association() = MonolithicImplementationBase::meta_dstMonolithprimaryArtifact.parent();
		MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_ = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev = MonolithicImplementationBase::meta_dstMonolithprimaryArtifact;
		MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_ = MonolithicImplementationBase::meta_dstMonolithprimaryArtifact_rev = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;

		TopLevelBehavior::meta_MultiInput_children.target() = MultiInput::meta;
		MultiInput::meta.association() = MultiInputAction::meta_srcMultiInput.parent();
		MultiInput::meta_srcMultiInput_end_ = MultiInputBase::meta_dstMultiInput_rev = MultiInputAction::meta_srcMultiInput;
		MultiInput::meta_dstMultiInput_end_ = MultiInputAction::meta_srcMultiInput_rev = MultiInputBase::meta_dstMultiInput;

		MultiInputAction::meta_srcMultiInput.target() = MultiInputBase::meta;

		MultiInputBase::meta_dstMultiInput.target() = MultiInputAction::meta;
		MultiInputBase::meta.subTypes() += ProvidedRequestPort::meta;
		MultiInputBase::meta.subTypes() += Environment::meta;

		MultiOutputBase::meta.subTypes() += RequiredRequestPort::meta;

		ServiceProvider::meta_MultipleServiceRequests_child.target() = MultipleServiceRequests::meta;

		File::meta_NamedType_children.target() = NamedType::meta;
		Package::meta_NamedType_children.target() = NamedType::meta;
		NamedType::meta.subTypes() += Component::meta;
		NamedType::meta.subTypes() += Inheritable::meta;
		NamedType::meta.subTypes() += Boxed::meta;
		NamedType::meta.subTypes() += NoInheritable::meta;

		HasOperations::meta_NoInheritable_children.target() = NoInheritable::meta;
		NoInheritable::meta.subTypes() += Aggregate::meta;
		NoInheritable::meta.subTypes() += SwitchedAggregate::meta;
		NoInheritable::meta.subTypes() += Alias::meta;
		NoInheritable::meta.subTypes() += Collection::meta;
		NoInheritable::meta.subTypes() += Enum::meta;

		Node::meta_referedbyNodeReference.target() = NodeReference::meta;
		Node::meta_dstInterconnectConnection.target() = Interconnect::meta;
		Node::meta_dstShares.target() = SharedResource::meta;
		Resource::meta_Node_parent.target() = Node::meta;
		Domain::meta_Node_children.target() = Node::meta;

		NodeReference::meta_srcInstanceMapping.target() = CollocationGroup::meta;
		NodeReference::meta_ref.target() = Node::meta;
		DeploymentPlan::meta_NodeReference_children.target() = NodeReference::meta;

		Object::meta_referedbySupports.target() = Supports::meta;

		PrivateFlag::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
		FactoryOperation::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
		MakeMemberPrivate::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
		Member::meta_ObjectByValue_parent.target() = ObjectByValue::meta;
		ObjectByValue::meta.subTypes() += Event::meta;
		ObjectByValue::meta.subTypes() += ValueObject::meta;

		HasOperations::meta_OnewayOperation_children.target() = OnewayOperation::meta;

		OperationBase::meta_referedbyOperationRef.target() = OperationRef::meta;
		InParameter::meta_OperationBase_parent.target() = OperationBase::meta;
		BenchmarkAnalysis::meta_OperationBase_children.target() = OperationBase::meta;
		OperationBase::meta.subTypes() += HasExceptions::meta;
		OperationBase::meta.subTypes() += OnewayOperation::meta;

		OperationRef::meta_dstTimerConnection.target() = TimeProbe::meta;
		OperationRef::meta_dstMetricConnection.target() = MetricsBase::meta;
		OperationRef::meta_dstComponentOperation.target() = CompRef::meta;
		OperationRef::meta_dstWorkLoadOperationConnection.target() = Task::meta;
		OperationRef::meta_ref.target() = OperationBase::meta;
		BenchmarkAnalysis::meta_OperationRef_children.target() = OperationRef::meta;

		OutEventPort::meta_dstpublish.target() = PublishConnector::meta;
		OutEventPort::meta_dstemit.target() = InEventPort::meta;
		OutEventPort::meta_ref.target() = Event::meta;
		OutEventPort::meta_dstEventSourceDelegate.target() = OutEventPort::meta;
		OutEventPort::meta_srcEventSourceDelegate.target() = OutEventPort::meta;
		ComponentAssembly::meta_OutEventPort_children.target() = OutEventPort::meta;

		OutParameter::meta_ref.target() = MemberType::meta;
		TwowayOperation::meta_OutParameter_children.target() = OutParameter::meta;

		ComponentRef::meta_Package_parent.target() = Package::meta;
		NamedType::meta_Package_parent.target() = Package::meta;
		ManagesComponent::meta_Package_parent.target() = Package::meta;
		Package::meta_Package_parent.target() = Package::meta;
		Exception::meta_Package_parent.target() = Package::meta;
		Constant::meta_Package_parent.target() = Package::meta;
		Package::meta_Package_children.target() = Package::meta;
		File::meta_Package_children.target() = Package::meta;

		PackageConfigurationContainer::meta_PackageConfBasePackage_child.target() = PackageConfBasePackage::meta;
		PackageConfBasePackage::meta.association() = PackageConfiguration::meta_dstPackageConfBasePackage.parent();
		PackageConfBasePackage::meta_dstPackageConfBasePackage_end_ = ComponentPackage::meta_srcPackageConfBasePackage_rev = PackageConfiguration::meta_dstPackageConfBasePackage;
		PackageConfBasePackage::meta_srcPackageConfBasePackage_end_ = PackageConfiguration::meta_dstPackageConfBasePackage_rev = ComponentPackage::meta_srcPackageConfBasePackage;

		PackageConfigurationContainer::meta_PackageConfConfigProperty_children.target() = PackageConfConfigProperty::meta;
		PackageConfConfigProperty::meta.association() = PackageConfiguration::meta_dstPackageConfConfigProperty.parent();
		PackageConfConfigProperty::meta_dstPackageConfConfigProperty_end_ = Property::meta_srcPackageConfConfigProperty_rev = PackageConfiguration::meta_dstPackageConfConfigProperty;
		PackageConfConfigProperty::meta_srcPackageConfConfigProperty_end_ = PackageConfiguration::meta_dstPackageConfConfigProperty_rev = Property::meta_srcPackageConfConfigProperty;

		PackageConfigurationContainer::meta_PackageConfReference_child.target() = PackageConfReference::meta;
		PackageConfReference::meta.association() = PackageConfiguration::meta_dstPackageConfReference.parent();
		PackageConfReference::meta_dstPackageConfReference_end_ = ComponentPackageReference::meta_srcPackageConfReference_rev = PackageConfiguration::meta_dstPackageConfReference;
		PackageConfReference::meta_srcPackageConfReference_end_ = PackageConfiguration::meta_dstPackageConfReference_rev = ComponentPackageReference::meta_srcPackageConfReference;

		PackageConfigurationContainer::meta_PackageConfSelectRequirement_children.target() = PackageConfSelectRequirement::meta;
		PackageConfSelectRequirement::meta.association() = PackageConfiguration::meta_dstPackageConfSelectRequirement.parent();
		PackageConfSelectRequirement::meta_dstPackageConfSelectRequirement_end_ = Requirement::meta_srcPackageConfSelectRequirement_rev = PackageConfiguration::meta_dstPackageConfSelectRequirement;
		PackageConfSelectRequirement::meta_srcPackageConfSelectRequirement_end_ = PackageConfiguration::meta_dstPackageConfSelectRequirement_rev = Requirement::meta_srcPackageConfSelectRequirement;

		PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child.target() = PackageConfSpecializedConfig::meta;
		PackageConfSpecializedConfig::meta.association() = PackageConfigurationReference::meta_srcPackageConfSpecializedConfig.parent();
		PackageConfSpecializedConfig::meta_srcPackageConfSpecializedConfig_end_ = PackageConfiguration::meta_dstPackageConfSpecializedConfig_rev = PackageConfigurationReference::meta_srcPackageConfSpecializedConfig;
		PackageConfSpecializedConfig::meta_dstPackageConfSpecializedConfig_end_ = PackageConfigurationReference::meta_srcPackageConfSpecializedConfig_rev = PackageConfiguration::meta_dstPackageConfSpecializedConfig;

		PackageContainer::meta_PackageConfigProperty_children.target() = PackageConfigProperty::meta;
		PackageConfigProperty::meta.association() = ComponentPackage::meta_dstPackageConfigProperty.parent();
		PackageConfigProperty::meta_dstPackageConfigProperty_end_ = Property::meta_srcPackageConfigProperty_rev = ComponentPackage::meta_dstPackageConfigProperty;
		PackageConfigProperty::meta_srcPackageConfigProperty_end_ = ComponentPackage::meta_dstPackageConfigProperty_rev = Property::meta_srcPackageConfigProperty;

		PackageConfiguration::meta_dstPackageConfSpecializedConfig.target() = PackageConfigurationReference::meta;
		PackageConfiguration::meta_referedbyPackageConfigurationReference.target() = PackageConfigurationReference::meta;
		PackageConfiguration::meta_dstPackageConfBasePackage.target() = ComponentPackage::meta;
		PackageConfiguration::meta_dstPackageConfReference.target() = ComponentPackageReference::meta;
		PackageConfiguration::meta_dstPackageConfSelectRequirement.target() = Requirement::meta;
		PackageConfiguration::meta_dstPackageConfConfigProperty.target() = Property::meta;
		PackageConfigurationContainer::meta_PackageConfiguration_children.target() = PackageConfiguration::meta;

		PackageConfReference::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		PackageConfBasePackage::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		ComponentPackage::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		ComponentPackageReference::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		PackageConfConfigProperty::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		Requirement::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		Property::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		PackageConfiguration::meta_PackageConfigurationContainer_parent.target() = PackageConfigurationContainer::meta;
		PackageConfigurations::meta_PackageConfigurationContainer_children.target() = PackageConfigurationContainer::meta;

		PackageConfigurationReference::meta_srcPackageConfSpecializedConfig.target() = PackageConfiguration::meta;
		PackageConfigurationReference::meta_ref.target() = PackageConfiguration::meta;
		PackageConfigurationReference::meta_srcpackage.target() = TopLevelPackage::meta;
		TopLevelPackageContainer::meta_PackageConfigurationReference_child.target() = PackageConfigurationReference::meta;

		PackageConfigurationContainer::meta_PackageConfigurations_parent.target() = PackageConfigurations::meta;
		RootFolder::meta_PackageConfigurations_children.target() = PackageConfigurations::meta;

		Implementation::meta_PackageContainer_parent.target() = PackageContainer::meta;
		PackageInterface::meta_PackageContainer_parent.target() = PackageContainer::meta;
		ComponentImplementationReference::meta_PackageContainer_parent.target() = PackageContainer::meta;
		ComponentRef::meta_PackageContainer_parent.target() = PackageContainer::meta;
		PackageConfigProperty::meta_PackageContainer_parent.target() = PackageContainer::meta;
		Property::meta_PackageContainer_parent.target() = PackageContainer::meta;
		PackageInfoProperty::meta_PackageContainer_parent.target() = PackageContainer::meta;
		ComponentPackage::meta_PackageContainer_parent.target() = PackageContainer::meta;
		ComponentPackages::meta_PackageContainer_children.target() = PackageContainer::meta;

		PackageContainer::meta_PackageInfoProperty_children.target() = PackageInfoProperty::meta;
		PackageInfoProperty::meta.association() = ComponentPackage::meta_dstPackageInfoProperty.parent();
		PackageInfoProperty::meta_dstPackageInfoProperty_end_ = Property::meta_srcPackageInfoProperty_rev = ComponentPackage::meta_dstPackageInfoProperty;
		PackageInfoProperty::meta_srcPackageInfoProperty_end_ = ComponentPackage::meta_dstPackageInfoProperty_rev = Property::meta_srcPackageInfoProperty;

		PackageContainer::meta_PackageInterface_child.target() = PackageInterface::meta;
		PackageInterface::meta.association() = ComponentPackage::meta_dstPackageInterface.parent();
		PackageInterface::meta_dstPackageInterface_end_ = ComponentRef::meta_srcPackageInterface_rev = ComponentPackage::meta_dstPackageInterface;
		PackageInterface::meta_srcPackageInterface_end_ = ComponentPackage::meta_dstPackageInterface_rev = ComponentRef::meta_srcPackageInterface;

		ParameterType::meta_ref.target() = MemberType::meta;
		ParameterType::meta.subTypes() += InParameter::meta;
		ParameterType::meta.subTypes() += InoutParameter::meta;
		ParameterType::meta.subTypes() += OutParameter::meta;

		Path::meta_referedbyPathReference.target() = PathReference::meta;
		Path::meta_dstPathProperty.target() = Property::meta;
		ComponentRef::meta_Path_parent.target() = Path::meta;
		DstEdge::meta_Path_parent.target() = Path::meta;
		SrcEdge::meta_Path_parent.target() = Path::meta;
		EdgeProperty::meta_Path_parent.target() = Path::meta;
		Edge::meta_Path_parent.target() = Path::meta;
		Property::meta_Path_parent.target() = Path::meta;
		GraphVertex::meta_Path_parent.target() = Path::meta;
		Paths::meta_Path_children.target() = Path::meta;

		Paths::meta_PathDiagrams_parent.target() = PathDiagrams::meta;
		RootFolder::meta_PathDiagrams_children.target() = PathDiagrams::meta;

		Paths::meta_PathProperty_children.target() = PathProperty::meta;
		PathProperty::meta.association() = Path::meta_dstPathProperty.parent();
		PathProperty::meta_dstPathProperty_end_ = Property::meta_srcPathProperty_rev = Path::meta_dstPathProperty;
		PathProperty::meta_srcPathProperty_end_ = Path::meta_dstPathProperty_rev = Property::meta_srcPathProperty;

		PathReference::meta_srcCriticalPath.target() = ComponentAssembly::meta;
		PathReference::meta_ref.target() = Path::meta;
		ComponentImplementationContainer::meta_PathReference_child.target() = PathReference::meta;

		PathProperty::meta_Paths_parent.target() = Paths::meta;
		Path::meta_Paths_parent.target() = Paths::meta;
		Property::meta_Paths_parent.target() = Paths::meta;
		PathDiagrams::meta_Paths_children.target() = Paths::meta;

		TopLevelBehavior::meta_PeriodicEvent_children.target() = PeriodicEvent::meta;

		Port::meta_srcExternalDelegate.target() = ExternalPortReference::meta;
		ConnectedComponent::meta_Port_children.target() = Port::meta;
		Component::meta_Port_children.target() = Port::meta;
		Port::meta.subTypes() += ProvidedRequestPort::meta;
		Port::meta.subTypes() += InEventPort::meta;
		Port::meta.subTypes() += OutEventPort::meta;
		Port::meta.subTypes() += RequiredRequestPort::meta;

		PredefinedType::meta_referedbyVariable.target() = Variable::meta;
		PredefinedTypes::meta_PredefinedType_children.target() = PredefinedType::meta;
		PredefinedType::meta.subTypes() += Byte::meta;
		PredefinedType::meta.subTypes() += Boolean::meta;
		PredefinedType::meta.subTypes() += ShortInteger::meta;
		PredefinedType::meta.subTypes() += LongInteger::meta;
		PredefinedType::meta.subTypes() += RealNumber::meta;
		PredefinedType::meta.subTypes() += String::meta;
		PredefinedType::meta.subTypes() += GenericObject::meta;
		PredefinedType::meta.subTypes() += GenericValueObject::meta;
		PredefinedType::meta.subTypes() += GenericValue::meta;
		PredefinedType::meta.subTypes() += TypeEncoding::meta;
		PredefinedType::meta.subTypes() += TypeKind::meta;

		Collection::meta_PredefinedTypes_parent.target() = PredefinedTypes::meta;
		PredefinedType::meta_PredefinedTypes_parent.target() = PredefinedTypes::meta;
		RootFolder::meta_PredefinedTypes_children.target() = PredefinedTypes::meta;

		Prefixable::meta.subTypes() += Object::meta;
		Prefixable::meta.subTypes() += ObjectByValue::meta;
		Prefixable::meta.subTypes() += Package::meta;
		Prefixable::meta.subTypes() += File::meta;

		PrivateFlag::meta_srcMakeMemberPrivate.target() = Member::meta;
		ObjectByValue::meta_PrivateFlag_children.target() = PrivateFlag::meta;

		Project::meta_setWorkspace.target() = Workspaces::meta;
		ExtResourceConn::meta_Project_parent.target() = Project::meta;
		ExternalResources::meta_Project_parent.target() = Project::meta;
		ComponentLib::meta_Project_parent.target() = Project::meta;
		ImplementationArtifact::meta_Project_parent.target() = Project::meta;
		MPC::meta_Project_children.target() = Project::meta;

		Property::meta_srcMonolithExecParameter.target() = MonolithicImplementationBase::meta;
		Property::meta_srcInfoProperty.target() = Implemenation::meta;
		Property::meta_srcConfigProperty.target() = Implemenation::meta;
		Property::meta_srcPathProperty.target() = Path::meta;
		Property::meta_dstPropertyConnector.target() = Edge::meta;
		Property::meta_srcAttributeMappingValue.target() = AttributeMapping::meta;
		Property::meta_srcPackageConfConfigProperty.target() = PackageConfiguration::meta;
		Property::meta_srcArtifactExecParameter.target() = ImplementationArtifact::meta;
		Property::meta_srcArtifactInfoProperty.target() = ImplementationArtifact::meta;
		Property::meta_srcPackageConfigProperty.target() = ComponentPackage::meta;
		Property::meta_srcPackageInfoProperty.target() = ComponentPackage::meta;
		Property::meta_srcComponentConfigProperty.target() = ComponentRef::meta;
		Property::meta_srcComponentInfoProperty.target() = ComponentRef::meta;
		Property::meta_srcAssemblyConfigProperty.target() = Component::meta;
		Property::meta_srcAttributeValue.target() = ReadonlyAttribute::meta;
		DataType::meta_Property_parent.target() = Property::meta;
		ImplementationContainer::meta_Property_children.target() = Property::meta;
		ComponentAssembly::meta_Property_children.target() = Property::meta;
		Path::meta_Property_children.target() = Property::meta;
		Paths::meta_Property_children.target() = Property::meta;
		DeploymentPlan::meta_Property_children.target() = Property::meta;
		PackageConfigurationContainer::meta_Property_children.target() = Property::meta;
		ArtifactContainer::meta_Property_children.target() = Property::meta;
		ComponentContainer::meta_Property_children.target() = Property::meta;
		PackageContainer::meta_Property_children.target() = Property::meta;
		RequirementBase::meta_Property_children.target() = Property::meta;
		Domain::meta_Property_children.target() = Property::meta;
		BehaviorInputAction::meta_Property_children.target() = Property::meta;
		QueryInputAction::meta_Property_children.target() = Property::meta;
		ActionBase::meta_Property_children.target() = Property::meta;

		Provideable::meta_referedbyRequiredRequestPort.target() = RequiredRequestPort::meta;
		Provideable::meta_referedbyProvidedRequestPort.target() = ProvidedRequestPort::meta;
		Provideable::meta.subTypes() += Object::meta;
		Provideable::meta.subTypes() += GenericObject::meta;

		ProvidedRequestPort::meta_ref.target() = Provideable::meta;
		ProvidedRequestPort::meta_dstFacetDelegate.target() = ProvidedRequestPort::meta;
		ProvidedRequestPort::meta_srcFacetDelegate.target() = ProvidedRequestPort::meta;
		ProvidedRequestPort::meta_srcSupportsDelegate.target() = Supports::meta;
		ComponentAssembly::meta_ProvidedRequestPort_children.target() = ProvidedRequestPort::meta;

		PublishConnector::meta_dstAssemblyDeployRequirement.target() = Requirement::meta;
		PublishConnector::meta_dstdeliverTo.target() = InEventPort::meta;
		PublishConnector::meta_srcpublish.target() = OutEventPort::meta;
		ComponentAssembly::meta_PublishConnector_children.target() = PublishConnector::meta;

		TopLevelBehavior::meta_QueryInput_children.target() = QueryInput::meta;
		QueryInput::meta.association() = QueryInputAction::meta_srcQueryInput.parent();
		QueryInput::meta_srcQueryInput_end_ = QueryInputBase::meta_dstQueryInput_rev = QueryInputAction::meta_srcQueryInput;
		QueryInput::meta_dstQueryInput_end_ = QueryInputAction::meta_srcQueryInput_rev = QueryInputBase::meta_dstQueryInput;

		QueryInputAction::meta_srcQueryInput.target() = QueryInputBase::meta;
		Property::meta_QueryInputAction_parent.target() = QueryInputAction::meta;
		BehaviorModel::meta_QueryInputAction_children.target() = QueryInputAction::meta;

		QueryInputBase::meta_dstQueryInput.target() = QueryInputAction::meta;
		QueryInputBase::meta.subTypes() += InEventPort::meta;

		ServiceProvider::meta_RTRequirements_parent.target() = RTRequirements::meta;
		ServiceConsumer::meta_RTRequirements_parent.target() = RTRequirements::meta;

		ReadonlyAttribute::meta_srcAttributeDelegate.target() = AttributeMapping::meta;
		ReadonlyAttribute::meta_referedbyAttributeMapping.target() = AttributeMapping::meta;
		ReadonlyAttribute::meta_dstAttributeValue.target() = Property::meta;
		AttributeMember::meta_ReadonlyAttribute_parent.target() = ReadonlyAttribute::meta;
		GetException::meta_ReadonlyAttribute_parent.target() = ReadonlyAttribute::meta;
		Component::meta_ReadonlyAttribute_children.target() = ReadonlyAttribute::meta;
		Inheritable::meta_ReadonlyAttribute_children.target() = ReadonlyAttribute::meta;
		ReadonlyAttribute::meta.subTypes() += Attribute::meta;

		ComponentAssembly::meta_ReceptacleDelegate_children.target() = ReceptacleDelegate::meta;
		ReceptacleDelegate::meta.association() = RequiredRequestPort::meta_dstReceptacleDelegate.parent();
		ReceptacleDelegate::meta_dstReceptacleDelegate_end_ = RequiredRequestPort::meta_srcReceptacleDelegate_rev = RequiredRequestPort::meta_dstReceptacleDelegate;
		ReceptacleDelegate::meta_srcReceptacleDelegate_end_ = RequiredRequestPort::meta_dstReceptacleDelegate_rev = RequiredRequestPort::meta_srcReceptacleDelegate;

		RequiredRequestPort::meta_dstinvoke.target() = InvokePortBase::meta;
		RequiredRequestPort::meta_ref.target() = Provideable::meta;
		RequiredRequestPort::meta_dstReceptacleDelegate.target() = RequiredRequestPort::meta;
		RequiredRequestPort::meta_srcReceptacleDelegate.target() = RequiredRequestPort::meta;
		ComponentAssembly::meta_RequiredRequestPort_children.target() = RequiredRequestPort::meta;

		Requirement::meta_srcAssemblyDeployRequirement.target() = PublishConnector::meta;
		Requirement::meta_srcPackageConfSelectRequirement.target() = PackageConfiguration::meta;
		Requirement::meta_srcArtifactDeployRequirement.target() = ImplementationArtifact::meta;
		Requirement::meta_srcAssemblyselectRequirement.target() = Component::meta;
		ComponentAssembly::meta_Requirement_children.target() = Requirement::meta;
		PackageConfigurationContainer::meta_Requirement_children.target() = Requirement::meta;
		ArtifactContainer::meta_Requirement_children.target() = Requirement::meta;
		Requirement::meta.subTypes() += RTRequirements::meta;
		Requirement::meta.subTypes() += ECRequirements::meta;

		Property::meta_RequirementBase_parent.target() = RequirementBase::meta;
		RequirementBase::meta.subTypes() += Requirement::meta;
		RequirementBase::meta.subTypes() += ImplementationRequirement::meta;

		SatisfierProperty::meta_RequirementSatisfier_parent.target() = RequirementSatisfier::meta;
		RequirementSatisfier::meta.subTypes() += Resource::meta;
		RequirementSatisfier::meta.subTypes() += SharedResource::meta;
		RequirementSatisfier::meta.subTypes() += Capability::meta;

		Interconnect::meta_Resource_children.target() = Resource::meta;
		Node::meta_Resource_children.target() = Resource::meta;
		Bridge::meta_Resource_children.target() = Resource::meta;

		ReturnType::meta_ref.target() = MemberType::meta;
		TwowayOperation::meta_ReturnType_child.target() = ReturnType::meta;

		PathDiagrams::meta_RootFolder_parent.target() = RootFolder::meta;
		ComponentFactoryImplementations::meta_RootFolder_parent.target() = RootFolder::meta;
		ComponentAnalyses::meta_RootFolder_parent.target() = RootFolder::meta;
		DeploymentPlans::meta_RootFolder_parent.target() = RootFolder::meta;
		ComponentImplementations::meta_RootFolder_parent.target() = RootFolder::meta;
		PackageConfigurations::meta_RootFolder_parent.target() = RootFolder::meta;
		ImplementationArtifacts::meta_RootFolder_parent.target() = RootFolder::meta;
		ComponentTypes::meta_RootFolder_parent.target() = RootFolder::meta;
		TopLevelPackages::meta_RootFolder_parent.target() = RootFolder::meta;
		ComponentPackages::meta_RootFolder_parent.target() = RootFolder::meta;
		Targets::meta_RootFolder_parent.target() = RootFolder::meta;
		PredefinedTypes::meta_RootFolder_parent.target() = RootFolder::meta;
		InterfaceDefinitions::meta_RootFolder_parent.target() = RootFolder::meta;
		ComponentBuild::meta_RootFolder_parent.target() = RootFolder::meta;
		WorkerLibraries::meta_RootFolder_parent.target() = RootFolder::meta;
		RootFolder::meta_RootFolder_parent.target() = RootFolder::meta;
		RootFolder::meta_RootFolder_children.target() = RootFolder::meta;

		DataType::meta_SatisfierProperty_parent.target() = SatisfierProperty::meta;
		RequirementSatisfier::meta_SatisfierProperty_children.target() = SatisfierProperty::meta;

		FileRef::meta_ServantProject_parent.target() = ServantProject::meta;
		ImplementationArtifactReference::meta_ServantProject_parent.target() = ServantProject::meta;

		RTRequirements::meta_ServiceConsumer_child.target() = ServiceConsumer::meta;

		ServiceProvider::meta_ServiceLevels_child.target() = ServiceLevels::meta;

		ServiceLevels::meta_ServiceProvider_parent.target() = ServiceProvider::meta;
		MultipleServiceRequests::meta_ServiceProvider_parent.target() = ServiceProvider::meta;
		RTRequirements::meta_ServiceProvider_child.target() = ServiceProvider::meta;

		SetException::meta_ref.target() = Exception::meta;
		Attribute::meta_SetException_children.target() = SetException::meta;

		SharedComponentReference::meta_ref.target() = ComponentRef::meta;

		SharedResource::meta_srcShares.target() = Node::meta;
		Domain::meta_SharedResource_children.target() = SharedResource::meta;

		Domain::meta_Shares_children.target() = Shares::meta;
		Shares::meta.association() = Node::meta_dstShares.parent();
		Shares::meta_dstShares_end_ = SharedResource::meta_srcShares_rev = Node::meta_dstShares;
		Shares::meta_srcShares_end_ = Node::meta_dstShares_rev = SharedResource::meta_srcShares;

		SingleInputBase::meta_dstInput.target() = InputAction::meta;
		SingleInputBase::meta.subTypes() += InEventPort::meta;
		SingleInputBase::meta.subTypes() += PeriodicEvent::meta;
		SingleInputBase::meta.subTypes() += ApplicationTask::meta;

		SingleOutputBase::meta.subTypes() += OutEventPort::meta;

		Path::meta_SrcEdge_children.target() = SrcEdge::meta;
		SrcEdge::meta.association() = GraphVertex::meta_srcSrcEdge.parent();
		SrcEdge::meta_srcSrcEdge_end_ = Edge::meta_dstSrcEdge_rev = GraphVertex::meta_srcSrcEdge;
		SrcEdge::meta_dstSrcEdge_end_ = GraphVertex::meta_srcSrcEdge_rev = Edge::meta_dstSrcEdge;

		State::meta_dstTransition.target() = ActionBase::meta;
		State::meta_dstTerminalTransition.target() = Terminal::meta;

		StateBase::meta_dstFinish.target() = BehaviorInputAction::meta;
		StateBase::meta_srcInputEffect.target() = BehaviorInputAction::meta;
		StateBase::meta_srcEffect.target() = ActionBase::meta;
		StateBase::meta_srcTerminalEffect.target() = Terminal::meta;
		BehaviorModel::meta_StateBase_children.target() = StateBase::meta;
		StateBase::meta.subTypes() += BranchState::meta;
		StateBase::meta.subTypes() += LoopState::meta;
		StateBase::meta.subTypes() += State::meta;

		FileRef::meta_StubProject_parent.target() = StubProject::meta;
		ImplementationArtifactReference::meta_StubProject_parent.target() = StubProject::meta;

		Supports::meta_dstSupportsDelegate.target() = ProvidedRequestPort::meta;
		Supports::meta_ref.target() = Object::meta;
		SupportsInterfaces::meta_Supports_children.target() = Supports::meta;

		ComponentAssembly::meta_SupportsDelegate_children.target() = SupportsDelegate::meta;
		SupportsDelegate::meta.association() = ProvidedRequestPort::meta_srcSupportsDelegate.parent();
		SupportsDelegate::meta_srcSupportsDelegate_end_ = Supports::meta_dstSupportsDelegate_rev = ProvidedRequestPort::meta_srcSupportsDelegate;
		SupportsDelegate::meta_dstSupportsDelegate_end_ = ProvidedRequestPort::meta_srcSupportsDelegate_rev = Supports::meta_dstSupportsDelegate;

		Supports::meta_SupportsInterfaces_parent.target() = SupportsInterfaces::meta;
		SupportsInterfaces::meta.subTypes() += ComponentFactory::meta;
		SupportsInterfaces::meta.subTypes() += Component::meta;
		SupportsInterfaces::meta.subTypes() += ObjectByValue::meta;

		Label::meta_SwitchedAggregate_parent.target() = SwitchedAggregate::meta;
		LabelConnection::meta_SwitchedAggregate_parent.target() = SwitchedAggregate::meta;
		Member::meta_SwitchedAggregate_parent.target() = SwitchedAggregate::meta;
		Discriminator::meta_SwitchedAggregate_parent.target() = SwitchedAggregate::meta;

		Taggable::meta.subTypes() += Port::meta;
		Taggable::meta.subTypes() += OperationBase::meta;
		Taggable::meta.subTypes() += ReadonlyAttribute::meta;
		Taggable::meta.subTypes() += NamedType::meta;
		Taggable::meta.subTypes() += Package::meta;
		Taggable::meta.subTypes() += Exception::meta;
		Taggable::meta.subTypes() += Constant::meta;

		Domain::meta_Targets_parent.target() = Targets::meta;
		RootFolder::meta_Targets_children.target() = Targets::meta;

		Task::meta_srcWorkLoadOperationConnection.target() = OperationRef::meta;
		Task::meta_setTaskSet.target() = TaskSet::meta;
		BenchmarkAnalysis::meta_Task_children.target() = Task::meta;

		TaskSet::meta_srcWorkloadCharacteristics.target() = MetricsBase::meta;
		TaskSet::meta_members.target() = Task::meta;
		BenchmarkAnalysis::meta_TaskSet_children.target() = TaskSet::meta;

		Terminal::meta_srcTerminalTransition.target() = State::meta;
		Terminal::meta_dstTerminalEffect.target() = StateBase::meta;
		BehaviorModel::meta_Terminal_children.target() = Terminal::meta;

		BehaviorModel::meta_TerminalEffect_children.target() = TerminalEffect::meta;
		TerminalEffect::meta.association() = StateBase::meta_srcTerminalEffect.parent();
		TerminalEffect::meta_srcTerminalEffect_end_ = Terminal::meta_dstTerminalEffect_rev = StateBase::meta_srcTerminalEffect;
		TerminalEffect::meta_dstTerminalEffect_end_ = StateBase::meta_srcTerminalEffect_rev = Terminal::meta_dstTerminalEffect;

		BehaviorModel::meta_TerminalTransition_children.target() = TerminalTransition::meta;
		TerminalTransition::meta.association() = State::meta_dstTerminalTransition.parent();
		TerminalTransition::meta_dstTerminalTransition_end_ = Terminal::meta_srcTerminalTransition_rev = State::meta_dstTerminalTransition;
		TerminalTransition::meta_srcTerminalTransition_end_ = State::meta_dstTerminalTransition_rev = Terminal::meta_srcTerminalTransition;

		TimeProbe::meta_srcTimerEventSinkConn.target() = EventRef::meta;
		TimeProbe::meta_srcTimerConnection.target() = OperationRef::meta;
		BenchmarkAnalysis::meta_TimeProbe_children.target() = TimeProbe::meta;

		BenchmarkAnalysis::meta_TimerConnection_children.target() = TimerConnection::meta;
		TimerConnection::meta.association() = TimeProbe::meta_srcTimerConnection.parent();
		TimerConnection::meta_srcTimerConnection_end_ = OperationRef::meta_dstTimerConnection_rev = TimeProbe::meta_srcTimerConnection;
		TimerConnection::meta_dstTimerConnection_end_ = TimeProbe::meta_srcTimerConnection_rev = OperationRef::meta_dstTimerConnection;

		BenchmarkAnalysis::meta_TimerEventSinkConn_children.target() = TimerEventSinkConn::meta;
		TimerEventSinkConn::meta.association() = TimeProbe::meta_srcTimerEventSinkConn.parent();
		TimerEventSinkConn::meta_srcTimerEventSinkConn_end_ = EventRef::meta_dstTimerEventSinkConn_rev = TimeProbe::meta_srcTimerEventSinkConn;
		TimerEventSinkConn::meta_dstTimerEventSinkConn_end_ = TimeProbe::meta_srcTimerEventSinkConn_rev = EventRef::meta_dstTimerEventSinkConn;

		Input::meta_TopLevelBehavior_parent.target() = TopLevelBehavior::meta;
		MultiInput::meta_TopLevelBehavior_parent.target() = TopLevelBehavior::meta;
		QueryInput::meta_TopLevelBehavior_parent.target() = TopLevelBehavior::meta;
		PeriodicEvent::meta_TopLevelBehavior_parent.target() = TopLevelBehavior::meta;
		ApplicationTask::meta_TopLevelBehavior_parent.target() = TopLevelBehavior::meta;
		Environment::meta_TopLevelBehavior_parent.target() = TopLevelBehavior::meta;
		TopLevelBehavior::meta.subTypes() += Component::meta;

		TopLevelPackage::meta_dstpackage.target() = PackageConfigurationReference::meta;
		TopLevelPackageContainer::meta_TopLevelPackage_child.target() = TopLevelPackage::meta;

		TopLevelPackage::meta_TopLevelPackageContainer_parent.target() = TopLevelPackageContainer::meta;
		PackageConfigurationReference::meta_TopLevelPackageContainer_parent.target() = TopLevelPackageContainer::meta;
		package::meta_TopLevelPackageContainer_parent.target() = TopLevelPackageContainer::meta;
		TopLevelPackages::meta_TopLevelPackageContainer_children.target() = TopLevelPackageContainer::meta;

		TopLevelPackageContainer::meta_TopLevelPackages_parent.target() = TopLevelPackages::meta;
		RootFolder::meta_TopLevelPackages_children.target() = TopLevelPackages::meta;

		BehaviorModel::meta_Transition_children.target() = Transition::meta;
		Transition::meta.association() = ActionBase::meta_srcTransition.parent();
		Transition::meta_srcTransition_end_ = State::meta_dstTransition_rev = ActionBase::meta_srcTransition;
		Transition::meta_dstTransition_end_ = ActionBase::meta_srcTransition_rev = State::meta_dstTransition;

		OutParameter::meta_TwowayOperation_parent.target() = TwowayOperation::meta;
		InoutParameter::meta_TwowayOperation_parent.target() = TwowayOperation::meta;
		ReturnType::meta_TwowayOperation_parent.target() = TwowayOperation::meta;
		HasOperations::meta_TwowayOperation_children.target() = TwowayOperation::meta;

		ValueObject::meta_referedbyLookupKey.target() = LookupKey::meta;

		Variable::meta_ref.target() = PredefinedType::meta;
		BehaviorModel::meta_Variable_children.target() = Variable::meta;

		BenchmarkAnalysis::meta_WorkLoadOperationConnection_children.target() = WorkLoadOperationConnection::meta;
		WorkLoadOperationConnection::meta.association() = OperationRef::meta_dstWorkLoadOperationConnection.parent();
		WorkLoadOperationConnection::meta_dstWorkLoadOperationConnection_end_ = Task::meta_srcWorkLoadOperationConnection_rev = OperationRef::meta_dstWorkLoadOperationConnection;
		WorkLoadOperationConnection::meta_srcWorkLoadOperationConnection_end_ = OperationRef::meta_dstWorkLoadOperationConnection_rev = Task::meta_srcWorkLoadOperationConnection;

		Worker::meta_referedbyWorkerType.target() = WorkerType::meta;
		Action::meta_Worker_parent.target() = Worker::meta;
		WorkerPackageBase::meta_Worker_children.target() = Worker::meta;

		WorkerPackage::meta_WorkerFile_parent.target() = WorkerFile::meta;
		WorkerLibrary::meta_WorkerFile_children.target() = WorkerFile::meta;

		WorkerLibrary::meta_WorkerLibraries_parent.target() = WorkerLibraries::meta;
		RootFolder::meta_WorkerLibraries_children.target() = WorkerLibraries::meta;

		WorkerFile::meta_WorkerLibrary_parent.target() = WorkerLibrary::meta;
		WorkerLibraries::meta_WorkerLibrary_children.target() = WorkerLibrary::meta;

		WorkerPackage::meta_WorkerPackage_parent.target() = WorkerPackage::meta;
		WorkerFile::meta_WorkerPackage_children.target() = WorkerPackage::meta;
		WorkerPackage::meta_WorkerPackage_children.target() = WorkerPackage::meta;

		Worker::meta_WorkerPackageBase_parent.target() = WorkerPackageBase::meta;
		WorkerPackageBase::meta.subTypes() += WorkerFile::meta;
		WorkerPackageBase::meta.subTypes() += WorkerPackage::meta;

		WorkerType::meta_ref.target() = Worker::meta;
		Component::meta_WorkerType_children.target() = WorkerType::meta;

		BenchmarkAnalysis::meta_WorkloadCharacteristics_children.target() = WorkloadCharacteristics::meta;
		WorkloadCharacteristics::meta.association() = MetricsBase::meta_dstWorkloadCharacteristics.parent();
		WorkloadCharacteristics::meta_dstWorkloadCharacteristics_end_ = TaskSet::meta_srcWorkloadCharacteristics_rev = MetricsBase::meta_dstWorkloadCharacteristics;
		WorkloadCharacteristics::meta_srcWorkloadCharacteristics_end_ = MetricsBase::meta_dstWorkloadCharacteristics_rev = TaskSet::meta_srcWorkloadCharacteristics;

		Workspaces::meta_members.target() = Project::meta;
		MPC::meta_Workspaces_children.target() = Workspaces::meta;

		ComponentAssembly::meta_deliverTo_children.target() = deliverTo::meta;
		deliverTo::meta.association() = PublishConnector::meta_dstdeliverTo.parent();
		deliverTo::meta_dstdeliverTo_end_ = InEventPort::meta_srcdeliverTo_rev = PublishConnector::meta_dstdeliverTo;
		deliverTo::meta_srcdeliverTo_end_ = PublishConnector::meta_dstdeliverTo_rev = InEventPort::meta_srcdeliverTo;

		ComponentAssembly::meta_emit_children.target() = emit::meta;
		emit::meta.association() = InEventPort::meta_srcemit.parent();
		emit::meta_srcemit_end_ = OutEventPort::meta_dstemit_rev = InEventPort::meta_srcemit;
		emit::meta_dstemit_end_ = InEventPort::meta_srcemit_rev = OutEventPort::meta_dstemit;

		ComponentAssembly::meta_invoke_children.target() = invoke::meta;
		invoke::meta.association() = InvokePortBase::meta_srcinvoke.parent();
		invoke::meta_srcinvoke_end_ = RequiredRequestPort::meta_dstinvoke_rev = InvokePortBase::meta_srcinvoke;
		invoke::meta_dstinvoke_end_ = InvokePortBase::meta_srcinvoke_rev = RequiredRequestPort::meta_dstinvoke;

		TopLevelPackageContainer::meta_package_child.target() = package::meta;
		package::meta.association() = PackageConfigurationReference::meta_srcpackage.parent();
		package::meta_srcpackage_end_ = TopLevelPackage::meta_dstpackage_rev = PackageConfigurationReference::meta_srcpackage;
		package::meta_dstpackage_end_ = PackageConfigurationReference::meta_srcpackage_rev = TopLevelPackage::meta_dstpackage;

		ComponentAssembly::meta_publish_children.target() = publish::meta;
		publish::meta.association() = PublishConnector::meta_srcpublish.parent();
		publish::meta_srcpublish_end_ = OutEventPort::meta_dstpublish_rev = PublishConnector::meta_srcpublish;
		publish::meta_dstpublish_end_ = PublishConnector::meta_srcpublish_rev = OutEventPort::meta_dstpublish;

	}

	void InitMeta(const ::Uml::Diagram &parent) {
		// classes, with attributes, constraints and constraint definitions
		::Uml::SetClass(Action::meta, parent, "Action");
		::Uml::SetAttribute(Action::meta_LogAction, Action::meta, "LogAction");
		::Uml::SetAttribute(Action::meta_Duration, Action::meta, "Duration");

		::Uml::SetClass(ActionBase::meta, parent, "ActionBase");

		::Uml::SetClass(Aggregate::meta, parent, "Aggregate");

		::Uml::SetClass(Alias::meta, parent, "Alias");

		::Uml::SetClass(ApplicationTask::meta, parent, "ApplicationTask");

		::Uml::SetClass(ArtifactContainer::meta, parent, "ArtifactContainer");

		::Uml::SetClass(ArtifactDependency::meta, parent, "ArtifactDependency");

		::Uml::SetClass(ArtifactDependsOn::meta, parent, "ArtifactDependsOn");

		::Uml::SetClass(ArtifactDeployRequirement::meta, parent, "ArtifactDeployRequirement");

		::Uml::SetClass(ArtifactExecParameter::meta, parent, "ArtifactExecParameter");

		::Uml::SetClass(ArtifactInfoProperty::meta, parent, "ArtifactInfoProperty");

		::Uml::SetClass(AssemblyConfigProperty::meta, parent, "AssemblyConfigProperty");

		::Uml::SetClass(AssemblyDeployRequirement::meta, parent, "AssemblyDeployRequirement");

		::Uml::SetClass(AssemblyselectRequirement::meta, parent, "AssemblyselectRequirement");

		::Uml::SetClass(Attribute::meta, parent, "Attribute");

		::Uml::SetClass(AttributeDelegate::meta, parent, "AttributeDelegate");

		::Uml::SetClass(AttributeMapping::meta, parent, "AttributeMapping");

		::Uml::SetClass(AttributeMappingDelegate::meta, parent, "AttributeMappingDelegate");

		::Uml::SetClass(AttributeMappingValue::meta, parent, "AttributeMappingValue");

		::Uml::SetClass(AttributeMember::meta, parent, "AttributeMember");

		::Uml::SetClass(AttributeValue::meta, parent, "AttributeValue");

		::Uml::SetClass(Average::meta, parent, "Average");

		::Uml::SetClass(BehaviorInputAction::meta, parent, "BehaviorInputAction");

		::Uml::SetClass(BehaviorModel::meta, parent, "BehaviorModel");

		::Uml::SetClass(BenchmarkAnalysis::meta, parent, "BenchmarkAnalysis");

		::Uml::SetClass(BenchmarkCharacteristics::meta, parent, "BenchmarkCharacteristics");

		::Uml::SetClass(BenchmarkType::meta, parent, "BenchmarkType");

		::Uml::SetClass(Boolean::meta, parent, "Boolean");

		::Uml::SetClass(Boxed::meta, parent, "Boxed");

		::Uml::SetClass(BranchState::meta, parent, "BranchState");

		::Uml::SetClass(BranchTransition::meta, parent, "BranchTransition");
		::Uml::SetAttribute(BranchTransition::meta_Condition, BranchTransition::meta, "Condition");

		::Uml::SetClass(Bridge::meta, parent, "Bridge");
		::Uml::SetAttribute(Bridge::meta_label, Bridge::meta, "label");

		::Uml::SetClass(BridgeConnection::meta, parent, "BridgeConnection");

		::Uml::SetClass(Byte::meta, parent, "Byte");

		::Uml::SetClass(Capability::meta, parent, "Capability");

		::Uml::SetClass(Collection::meta, parent, "Collection");
		::Uml::SetAttribute(Collection::meta_bound, Collection::meta, "bound");

		::Uml::SetClass(CollocationGroup::meta, parent, "CollocationGroup");

		::Uml::SetClass(CollocationGroupMember::meta, parent, "CollocationGroupMember");

		::Uml::SetClass(CommonPortAttrs::meta, parent, "CommonPortAttrs");
		::Uml::SetAttribute(CommonPortAttrs::meta_exclusiveUser, CommonPortAttrs::meta, "exclusiveUser");
		::Uml::SetAttribute(CommonPortAttrs::meta_optional, CommonPortAttrs::meta, "optional");
		::Uml::SetAttribute(CommonPortAttrs::meta_exclusiveProvider, CommonPortAttrs::meta, "exclusiveProvider");

		::Uml::SetClass(CompRef::meta, parent, "CompRef");

		::Uml::SetClass(Component::meta, parent, "Component");
		::Uml::SetAttribute(Component::meta_UUID, Component::meta, "UUID");
		::Uml::SetAttribute(Component::meta_label, Component::meta, "label");

		::Uml::SetClass(ComponentAnalyses::meta, parent, "ComponentAnalyses");
		::Uml::SetAttribute(ComponentAnalyses::meta_name, ComponentAnalyses::meta, "name");

		::Uml::SetClass(ComponentAssembly::meta, parent, "ComponentAssembly");

		::Uml::SetClass(ComponentAssemblyReference::meta, parent, "ComponentAssemblyReference");

		::Uml::SetClass(ComponentBuild::meta, parent, "ComponentBuild");
		::Uml::SetAttribute(ComponentBuild::meta_name, ComponentBuild::meta, "name");

		::Uml::SetClass(ComponentConfigProperty::meta, parent, "ComponentConfigProperty");

		::Uml::SetClass(ComponentContainer::meta, parent, "ComponentContainer");

		::Uml::SetClass(ComponentFactory::meta, parent, "ComponentFactory");

		::Uml::SetClass(ComponentFactoryImplementationContainer::meta, parent, "ComponentFactoryImplementationContainer");

		::Uml::SetClass(ComponentFactoryImplementations::meta, parent, "ComponentFactoryImplementations");
		::Uml::SetAttribute(ComponentFactoryImplementations::meta_name, ComponentFactoryImplementations::meta, "name");

		::Uml::SetClass(ComponentFactoryInstance::meta, parent, "ComponentFactoryInstance");

		::Uml::SetClass(ComponentFactoryRef::meta, parent, "ComponentFactoryRef");

		::Uml::SetClass(ComponentImplementation::meta, parent, "ComponentImplementation");

		::Uml::SetClass(ComponentImplementationArtifact::meta, parent, "ComponentImplementationArtifact");
		::Uml::SetAttribute(ComponentImplementationArtifact::meta_EntryPoint, ComponentImplementationArtifact::meta, "EntryPoint");

		::Uml::SetClass(ComponentImplementationContainer::meta, parent, "ComponentImplementationContainer");

		::Uml::SetClass(ComponentImplementationReference::meta, parent, "ComponentImplementationReference");

		::Uml::SetClass(ComponentImplementations::meta, parent, "ComponentImplementations");
		::Uml::SetAttribute(ComponentImplementations::meta_name, ComponentImplementations::meta, "name");

		::Uml::SetClass(ComponentInfoProperty::meta, parent, "ComponentInfoProperty");

		::Uml::SetClass(ComponentLib::meta, parent, "ComponentLib");
		::Uml::SetAttribute(ComponentLib::meta_sharedname, ComponentLib::meta, "sharedname");
		::Uml::SetAttribute(ComponentLib::meta_libraryexport, ComponentLib::meta, "libraryexport");
		::Uml::SetAttribute(ComponentLib::meta_ORBServices, ComponentLib::meta, "ORBServices");

		::Uml::SetClass(ComponentOperation::meta, parent, "ComponentOperation");

		::Uml::SetClass(ComponentPackage::meta, parent, "ComponentPackage");
		::Uml::SetAttribute(ComponentPackage::meta_UUID, ComponentPackage::meta, "UUID");
		::Uml::SetAttribute(ComponentPackage::meta_label, ComponentPackage::meta, "label");

		::Uml::SetClass(ComponentPackageReference::meta, parent, "ComponentPackageReference");
		::Uml::SetAttribute(ComponentPackageReference::meta_requiredName, ComponentPackageReference::meta, "requiredName");
		::Uml::SetAttribute(ComponentPackageReference::meta_requiredUUID, ComponentPackageReference::meta, "requiredUUID");
		::Uml::SetAttribute(ComponentPackageReference::meta_requiredType, ComponentPackageReference::meta, "requiredType");

		::Uml::SetClass(ComponentPackages::meta, parent, "ComponentPackages");
		::Uml::SetAttribute(ComponentPackages::meta_name, ComponentPackages::meta, "name");

		::Uml::SetClass(ComponentProperty::meta, parent, "ComponentProperty");

		::Uml::SetClass(ComponentPropertyDescription::meta, parent, "ComponentPropertyDescription");

		::Uml::SetClass(ComponentRef::meta, parent, "ComponentRef");

		::Uml::SetClass(ComponentServantArtifact::meta, parent, "ComponentServantArtifact");
		::Uml::SetAttribute(ComponentServantArtifact::meta_EntryPoint, ComponentServantArtifact::meta, "EntryPoint");

		::Uml::SetClass(ComponentTypes::meta, parent, "ComponentTypes");
		::Uml::SetAttribute(ComponentTypes::meta_name, ComponentTypes::meta, "name");

		::Uml::SetClass(ConfigProperty::meta, parent, "ConfigProperty");

		::Uml::SetClass(ConnectedComponent::meta, parent, "ConnectedComponent");

		::Uml::SetClass(Constant::meta, parent, "Constant");
		::Uml::SetAttribute(Constant::meta_value, Constant::meta, "value");

		::Uml::SetClass(ConstantType::meta, parent, "ConstantType");

		::Uml::SetClass(CriticalPath::meta, parent, "CriticalPath");

		::Uml::SetClass(DataAnalysisBase::meta, parent, "DataAnalysisBase");

		::Uml::SetClass(DataType::meta, parent, "DataType");

		::Uml::SetClass(DeploymentPlan::meta, parent, "DeploymentPlan");
		::Uml::SetAttribute(DeploymentPlan::meta_UUID, DeploymentPlan::meta, "UUID");
		::Uml::SetAttribute(DeploymentPlan::meta_label, DeploymentPlan::meta, "label");

		::Uml::SetClass(DeploymentPlans::meta, parent, "DeploymentPlans");
		::Uml::SetAttribute(DeploymentPlans::meta_name, DeploymentPlans::meta, "name");

		::Uml::SetClass(Deploys::meta, parent, "Deploys");

		::Uml::SetClass(Discriminator::meta, parent, "Discriminator");

		::Uml::SetClass(DisplayNode::meta, parent, "DisplayNode");

		::Uml::SetClass(DoWhileState::meta, parent, "DoWhileState");

		::Uml::SetClass(Domain::meta, parent, "Domain");
		::Uml::SetAttribute(Domain::meta_label, Domain::meta, "label");
		::Uml::SetAttribute(Domain::meta_UUID, Domain::meta, "UUID");

		::Uml::SetClass(DstEdge::meta, parent, "DstEdge");

		::Uml::SetClass(ECBehavior::meta, parent, "ECBehavior");
		::Uml::SetAttribute(ECBehavior::meta_ConsumerBasedFiltering, ECBehavior::meta, "ConsumerBasedFiltering");
		::Uml::SetAttribute(ECBehavior::meta_SupplierBasedFiltering, ECBehavior::meta, "SupplierBasedFiltering");
		::Uml::SetAttribute(ECBehavior::meta_DisconnectDanglingConnections, ECBehavior::meta, "DisconnectDanglingConnections");
		::Uml::SetAttribute(ECBehavior::meta_MultithreadedConsumer, ECBehavior::meta, "MultithreadedConsumer");
		::Uml::SetAttribute(ECBehavior::meta_DispatchingMultithreadingLevel, ECBehavior::meta, "DispatchingMultithreadingLevel");
		::Uml::SetAttribute(ECBehavior::meta_MultithreadedSupplier, ECBehavior::meta, "MultithreadedSupplier");

		::Uml::SetClass(ECRequirements::meta, parent, "ECRequirements");
		::Uml::SetAttribute(ECRequirements::meta_ConfigureRTQoS, ECRequirements::meta, "ConfigureRTQoS");

		::Uml::SetClass(ECRole::meta, parent, "ECRole");
		::Uml::SetAttribute(ECRole::meta_rolekind, ECRole::meta, "rolekind");
		::Uml::SetAttribute(ECRole::meta_ECFilterType, ECRole::meta, "ECFilterType");

		::Uml::SetClass(Edge::meta, parent, "Edge");

		::Uml::SetClass(EdgeProperty::meta, parent, "EdgeProperty");

		::Uml::SetClass(Effect::meta, parent, "Effect");

		::Uml::SetClass(EffectBase::meta, parent, "EffectBase");
		::Uml::SetAttribute(EffectBase::meta_Postcondition, EffectBase::meta, "Postcondition");

		::Uml::SetClass(Enum::meta, parent, "Enum");

		::Uml::SetClass(EnumValue::meta, parent, "EnumValue");

		::Uml::SetClass(Environment::meta, parent, "Environment");

		::Uml::SetClass(Event::meta, parent, "Event");

		::Uml::SetClass(EventRef::meta, parent, "EventRef");

		::Uml::SetClass(EventSinkDelegate::meta, parent, "EventSinkDelegate");

		::Uml::SetClass(EventSourceDelegate::meta, parent, "EventSourceDelegate");

		::Uml::SetClass(Exception::meta, parent, "Exception");

		::Uml::SetClass(ExceptionRef::meta, parent, "ExceptionRef");

		::Uml::SetClass(ExecutorProject::meta, parent, "ExecutorProject");

		::Uml::SetClass(ExtResourceConn::meta, parent, "ExtResourceConn");

		::Uml::SetClass(ExternalDelegate::meta, parent, "ExternalDelegate");

		::Uml::SetClass(ExternalPortReference::meta, parent, "ExternalPortReference");
		::Uml::SetAttribute(ExternalPortReference::meta_label, ExternalPortReference::meta, "label");
		::Uml::SetAttribute(ExternalPortReference::meta_location, ExternalPortReference::meta, "location");

		::Uml::SetClass(ExternalPortReferenceType::meta, parent, "ExternalPortReferenceType");

		::Uml::SetClass(ExternalResources::meta, parent, "ExternalResources");

		::Uml::SetClass(FacetDelegate::meta, parent, "FacetDelegate");

		::Uml::SetClass(FactoryOperation::meta, parent, "FactoryOperation");

		::Uml::SetClass(File::meta, parent, "File");
		::Uml::SetAttribute(File::meta_path, File::meta, "path");

		::Uml::SetClass(FileRef::meta, parent, "FileRef");

		::Uml::SetClass(Finish::meta, parent, "Finish");

		::Uml::SetClass(FixedIterationBenchmarks::meta, parent, "FixedIterationBenchmarks");
		::Uml::SetAttribute(FixedIterationBenchmarks::meta_benchmarkIterations, FixedIterationBenchmarks::meta, "benchmarkIterations");

		::Uml::SetClass(ForState::meta, parent, "ForState");
		::Uml::SetAttribute(ForState::meta_IncrementExpr, ForState::meta, "IncrementExpr");
		::Uml::SetAttribute(ForState::meta_InitialCondition, ForState::meta, "InitialCondition");

		::Uml::SetClass(GenericObject::meta, parent, "GenericObject");

		::Uml::SetClass(GenericValue::meta, parent, "GenericValue");

		::Uml::SetClass(GenericValueObject::meta, parent, "GenericValueObject");

		::Uml::SetClass(GetException::meta, parent, "GetException");

		::Uml::SetClass(GraphVertex::meta, parent, "GraphVertex");

		::Uml::SetClass(HasExceptions::meta, parent, "HasExceptions");

		::Uml::SetClass(HasOperations::meta, parent, "HasOperations");

		::Uml::SetClass(Implemenation::meta, parent, "Implemenation");
		::Uml::SetAttribute(Implemenation::meta_UUID, Implemenation::meta, "UUID");
		::Uml::SetAttribute(Implemenation::meta_label, Implemenation::meta, "label");

		::Uml::SetClass(Implementation::meta, parent, "Implementation");

		::Uml::SetClass(ImplementationArtifact::meta, parent, "ImplementationArtifact");
		::Uml::SetAttribute(ImplementationArtifact::meta_configuration, ImplementationArtifact::meta, "configuration");
		::Uml::SetAttribute(ImplementationArtifact::meta_operatingSystem, ImplementationArtifact::meta, "operatingSystem");
		::Uml::SetAttribute(ImplementationArtifact::meta_artifactVersion, ImplementationArtifact::meta, "artifactVersion");
		::Uml::SetAttribute(ImplementationArtifact::meta_architecture, ImplementationArtifact::meta, "architecture");
		::Uml::SetAttribute(ImplementationArtifact::meta_label, ImplementationArtifact::meta, "label");
		::Uml::SetAttribute(ImplementationArtifact::meta_UUID, ImplementationArtifact::meta, "UUID");
		::Uml::SetAttribute(ImplementationArtifact::meta_location, ImplementationArtifact::meta, "location");

		::Uml::SetClass(ImplementationArtifactReference::meta, parent, "ImplementationArtifactReference");

		::Uml::SetClass(ImplementationArtifacts::meta, parent, "ImplementationArtifacts");
		::Uml::SetAttribute(ImplementationArtifacts::meta_name, ImplementationArtifacts::meta, "name");

		::Uml::SetClass(ImplementationCapability::meta, parent, "ImplementationCapability");

		::Uml::SetClass(ImplementationContainer::meta, parent, "ImplementationContainer");

		::Uml::SetClass(ImplementationDependency::meta, parent, "ImplementationDependency");
		::Uml::SetAttribute(ImplementationDependency::meta_requiredType, ImplementationDependency::meta, "requiredType");

		::Uml::SetClass(ImplementationDependsOn::meta, parent, "ImplementationDependsOn");

		::Uml::SetClass(ImplementationRequirement::meta, parent, "ImplementationRequirement");
		::Uml::SetAttribute(ImplementationRequirement::meta_ResourceUsageKind, ImplementationRequirement::meta, "ResourceUsageKind");
		::Uml::SetAttribute(ImplementationRequirement::meta_componentPort, ImplementationRequirement::meta, "componentPort");
		::Uml::SetAttribute(ImplementationRequirement::meta_resourcePort, ImplementationRequirement::meta, "resourcePort");

		::Uml::SetClass(Implements::meta, parent, "Implements");

		::Uml::SetClass(InEventPort::meta, parent, "InEventPort");

		::Uml::SetClass(InParameter::meta, parent, "InParameter");

		::Uml::SetClass(InfoProperty::meta, parent, "InfoProperty");

		::Uml::SetClass(Inheritable::meta, parent, "Inheritable");

		::Uml::SetClass(Inherits::meta, parent, "Inherits");

		::Uml::SetClass(InoutParameter::meta, parent, "InoutParameter");

		::Uml::SetClass(Input::meta, parent, "Input");

		::Uml::SetClass(InputAction::meta, parent, "InputAction");

		::Uml::SetClass(InputEffect::meta, parent, "InputEffect");

		::Uml::SetClass(InstanceMapping::meta, parent, "InstanceMapping");

		::Uml::SetClass(Interconnect::meta, parent, "Interconnect");
		::Uml::SetAttribute(Interconnect::meta_label, Interconnect::meta, "label");

		::Uml::SetClass(InterconnectConnection::meta, parent, "InterconnectConnection");

		::Uml::SetClass(InterfaceDefinitions::meta, parent, "InterfaceDefinitions");
		::Uml::SetAttribute(InterfaceDefinitions::meta_name, InterfaceDefinitions::meta, "name");

		::Uml::SetClass(InvokePortBase::meta, parent, "InvokePortBase");

		::Uml::SetClass(Jitter::meta, parent, "Jitter");

		::Uml::SetClass(Label::meta, parent, "Label");

		::Uml::SetClass(LabelConnection::meta, parent, "LabelConnection");

		::Uml::SetClass(Latency::meta, parent, "Latency");

		::Uml::SetClass(LongInteger::meta, parent, "LongInteger");

		::Uml::SetClass(LookupKey::meta, parent, "LookupKey");

		::Uml::SetClass(LookupOperation::meta, parent, "LookupOperation");

		::Uml::SetClass(LoopState::meta, parent, "LoopState");
		::Uml::SetAttribute(LoopState::meta_LoopingCondition, LoopState::meta, "LoopingCondition");

		::Uml::SetClass(LoopTransition::meta, parent, "LoopTransition");

		::Uml::SetClass(MPC::meta, parent, "MPC");

		::Uml::SetClass(MakeMemberPrivate::meta, parent, "MakeMemberPrivate");

		::Uml::SetClass(Manageable::meta, parent, "Manageable");

		::Uml::SetClass(ManagesComponent::meta, parent, "ManagesComponent");

		::Uml::SetClass(Maximum::meta, parent, "Maximum");

		::Uml::SetClass(Member::meta, parent, "Member");

		::Uml::SetClass(MemberType::meta, parent, "MemberType");

		::Uml::SetClass(MetricConnection::meta, parent, "MetricConnection");

		::Uml::SetClass(MetricsBase::meta, parent, "MetricsBase");
		::Uml::SetAttribute(MetricsBase::meta_warmup, MetricsBase::meta, "warmup");
		::Uml::SetAttribute(MetricsBase::meta_fileName, MetricsBase::meta, "fileName");
		::Uml::SetAttribute(MetricsBase::meta_iterations, MetricsBase::meta, "iterations");
		::Uml::SetAttribute(MetricsBase::meta_priority, MetricsBase::meta, "priority");
		::Uml::SetAttribute(MetricsBase::meta_rate, MetricsBase::meta, "rate");
		::Uml::SetAttribute(MetricsBase::meta_resolution, MetricsBase::meta, "resolution");

		::Uml::SetClass(MgaObject::meta, parent, "MgaObject");
		::Uml::SetAttribute(MgaObject::meta_position, MgaObject::meta, "position");
		::Uml::SetAttribute(MgaObject::meta_name, MgaObject::meta, "name");

		::Uml::SetClass(Minimum::meta, parent, "Minimum");

		::Uml::SetClass(MonolithDeployRequirement::meta, parent, "MonolithDeployRequirement");

		::Uml::SetClass(MonolithExecParameter::meta, parent, "MonolithExecParameter");

		::Uml::SetClass(MonolithicImplementation::meta, parent, "MonolithicImplementation");
		::Uml::SetAttribute(MonolithicImplementation::meta_defaultVersion, MonolithicImplementation::meta, "defaultVersion");

		::Uml::SetClass(MonolithicImplementationBase::meta, parent, "MonolithicImplementationBase");

		::Uml::SetClass(MonolithprimaryArtifact::meta, parent, "MonolithprimaryArtifact");

		::Uml::SetClass(MultiInput::meta, parent, "MultiInput");

		::Uml::SetClass(MultiInputAction::meta, parent, "MultiInputAction");

		::Uml::SetClass(MultiInputBase::meta, parent, "MultiInputBase");

		::Uml::SetClass(MultiOutputBase::meta, parent, "MultiOutputBase");

		::Uml::SetClass(MultipleServiceRequests::meta, parent, "MultipleServiceRequests");
		::Uml::SetAttribute(MultipleServiceRequests::meta_simultaneous_service_execution, MultipleServiceRequests::meta, "simultaneous_service_execution");
		::Uml::SetAttribute(MultipleServiceRequests::meta_minimum_simultaneous_service_level, MultipleServiceRequests::meta, "minimum_simultaneous_service_level");
		::Uml::SetAttribute(MultipleServiceRequests::meta_buffer_service_requests, MultipleServiceRequests::meta, "buffer_service_requests");
		::Uml::SetAttribute(MultipleServiceRequests::meta_maximum_simultaneous_service_level, MultipleServiceRequests::meta, "maximum_simultaneous_service_level");

		::Uml::SetClass(NamedType::meta, parent, "NamedType");

		::Uml::SetClass(NoInheritable::meta, parent, "NoInheritable");

		::Uml::SetClass(Node::meta, parent, "Node");
		::Uml::SetAttribute(Node::meta_operatingSystem, Node::meta, "operatingSystem");
		::Uml::SetAttribute(Node::meta_label, Node::meta, "label");
		::Uml::SetAttribute(Node::meta_architecture, Node::meta, "architecture");

		::Uml::SetClass(NodeReference::meta, parent, "NodeReference");

		::Uml::SetClass(Object::meta, parent, "Object");
		::Uml::SetAttribute(Object::meta_local, Object::meta, "local");
		::Uml::SetAttribute(Object::meta_abstract, Object::meta, "abstract");

		::Uml::SetClass(ObjectByValue::meta, parent, "ObjectByValue");
		::Uml::SetAttribute(ObjectByValue::meta_abstract, ObjectByValue::meta, "abstract");

		::Uml::SetClass(OnewayOperation::meta, parent, "OnewayOperation");

		::Uml::SetClass(OperationBase::meta, parent, "OperationBase");

		::Uml::SetClass(OperationRef::meta, parent, "OperationRef");

		::Uml::SetClass(OutEventPort::meta, parent, "OutEventPort");
		::Uml::SetAttribute(OutEventPort::meta_out_event_port_type, OutEventPort::meta, "out_event_port_type");
		::Uml::SetAttribute(OutEventPort::meta_single_destination, OutEventPort::meta, "single_destination");

		::Uml::SetClass(OutParameter::meta, parent, "OutParameter");

		::Uml::SetClass(OutputAction::meta, parent, "OutputAction");

		::Uml::SetClass(Package::meta, parent, "Package");

		::Uml::SetClass(PackageConfBasePackage::meta, parent, "PackageConfBasePackage");

		::Uml::SetClass(PackageConfConfigProperty::meta, parent, "PackageConfConfigProperty");

		::Uml::SetClass(PackageConfReference::meta, parent, "PackageConfReference");

		::Uml::SetClass(PackageConfSelectRequirement::meta, parent, "PackageConfSelectRequirement");

		::Uml::SetClass(PackageConfSpecializedConfig::meta, parent, "PackageConfSpecializedConfig");

		::Uml::SetClass(PackageConfigProperty::meta, parent, "PackageConfigProperty");

		::Uml::SetClass(PackageConfiguration::meta, parent, "PackageConfiguration");
		::Uml::SetAttribute(PackageConfiguration::meta_UUID, PackageConfiguration::meta, "UUID");
		::Uml::SetAttribute(PackageConfiguration::meta_label, PackageConfiguration::meta, "label");

		::Uml::SetClass(PackageConfigurationContainer::meta, parent, "PackageConfigurationContainer");

		::Uml::SetClass(PackageConfigurationReference::meta, parent, "PackageConfigurationReference");

		::Uml::SetClass(PackageConfigurations::meta, parent, "PackageConfigurations");
		::Uml::SetAttribute(PackageConfigurations::meta_name, PackageConfigurations::meta, "name");

		::Uml::SetClass(PackageContainer::meta, parent, "PackageContainer");

		::Uml::SetClass(PackageInfoProperty::meta, parent, "PackageInfoProperty");

		::Uml::SetClass(PackageInterface::meta, parent, "PackageInterface");

		::Uml::SetClass(ParameterType::meta, parent, "ParameterType");

		::Uml::SetClass(Path::meta, parent, "Path");

		::Uml::SetClass(PathDiagrams::meta, parent, "PathDiagrams");
		::Uml::SetAttribute(PathDiagrams::meta_name, PathDiagrams::meta, "name");

		::Uml::SetClass(PathProperty::meta, parent, "PathProperty");

		::Uml::SetClass(PathReference::meta, parent, "PathReference");

		::Uml::SetClass(Paths::meta, parent, "Paths");

		::Uml::SetClass(PeriodicBenchmarks::meta, parent, "PeriodicBenchmarks");
		::Uml::SetAttribute(PeriodicBenchmarks::meta_timeperiod, PeriodicBenchmarks::meta, "timeperiod");

		::Uml::SetClass(PeriodicEvent::meta, parent, "PeriodicEvent");
		::Uml::SetAttribute(PeriodicEvent::meta_Distribution, PeriodicEvent::meta, "Distribution");
		::Uml::SetAttribute(PeriodicEvent::meta_Hertz, PeriodicEvent::meta, "Hertz");

		::Uml::SetClass(Port::meta, parent, "Port");

		::Uml::SetClass(PredefinedType::meta, parent, "PredefinedType");

		::Uml::SetClass(PredefinedTypes::meta, parent, "PredefinedTypes");
		::Uml::SetAttribute(PredefinedTypes::meta_name, PredefinedTypes::meta, "name");

		::Uml::SetClass(Prefixable::meta, parent, "Prefixable");
		::Uml::SetAttribute(Prefixable::meta_PrefixTag, Prefixable::meta, "PrefixTag");

		::Uml::SetClass(PrivateFlag::meta, parent, "PrivateFlag");

		::Uml::SetClass(Project::meta, parent, "Project");

		::Uml::SetClass(Property::meta, parent, "Property");
		::Uml::SetAttribute(Property::meta_DataValue, Property::meta, "DataValue");

		::Uml::SetClass(Provideable::meta, parent, "Provideable");

		::Uml::SetClass(ProvidedRequestPort::meta, parent, "ProvidedRequestPort");

		::Uml::SetClass(PublishConnector::meta, parent, "PublishConnector");

		::Uml::SetClass(QueryAction::meta, parent, "QueryAction");

		::Uml::SetClass(QueryInput::meta, parent, "QueryInput");

		::Uml::SetClass(QueryInputAction::meta, parent, "QueryInputAction");

		::Uml::SetClass(QueryInputBase::meta, parent, "QueryInputBase");

		::Uml::SetClass(RTRequirements::meta, parent, "RTRequirements");

		::Uml::SetClass(ReadonlyAttribute::meta, parent, "ReadonlyAttribute");

		::Uml::SetClass(RealNumber::meta, parent, "RealNumber");

		::Uml::SetClass(ReceptacleDelegate::meta, parent, "ReceptacleDelegate");

		::Uml::SetClass(RequiredRequestPort::meta, parent, "RequiredRequestPort");
		::Uml::SetAttribute(RequiredRequestPort::meta_multiple_connections, RequiredRequestPort::meta, "multiple_connections");

		::Uml::SetClass(Requirement::meta, parent, "Requirement");

		::Uml::SetClass(RequirementBase::meta, parent, "RequirementBase");
		::Uml::SetAttribute(RequirementBase::meta_resourceType, RequirementBase::meta, "resourceType");

		::Uml::SetClass(RequirementSatisfier::meta, parent, "RequirementSatisfier");
		::Uml::SetAttribute(RequirementSatisfier::meta_resourceType, RequirementSatisfier::meta, "resourceType");

		::Uml::SetClass(Resource::meta, parent, "Resource");

		::Uml::SetClass(ReturnType::meta, parent, "ReturnType");

		::Uml::SetClass(RootFolder::meta, parent, "RootFolder");
		::Uml::SetAttribute(RootFolder::meta_name, RootFolder::meta, "name");

		::Uml::SetClass(SatisfierProperty::meta, parent, "SatisfierProperty");
		::Uml::SetAttribute(SatisfierProperty::meta_DataValue, SatisfierProperty::meta, "DataValue");
		::Uml::SetAttribute(SatisfierProperty::meta_SatisfierPropertyKind, SatisfierProperty::meta, "SatisfierPropertyKind");
		::Uml::SetAttribute(SatisfierProperty::meta_dynamic, SatisfierProperty::meta, "dynamic");

		::Uml::SetClass(ServantProject::meta, parent, "ServantProject");

		::Uml::SetClass(ServiceConsumer::meta, parent, "ServiceConsumer");
		::Uml::SetAttribute(ServiceConsumer::meta_prioritize_service_invocations, ServiceConsumer::meta, "prioritize_service_invocations");

		::Uml::SetClass(ServiceLevels::meta, parent, "ServiceLevels");
		::Uml::SetAttribute(ServiceLevels::meta_varying_service_levels, ServiceLevels::meta, "varying_service_levels");

		::Uml::SetClass(ServiceProvider::meta, parent, "ServiceProvider");
		::Uml::SetAttribute(ServiceProvider::meta_fixed_prioirty_service_execution, ServiceProvider::meta, "fixed_prioirty_service_execution");

		::Uml::SetClass(SetException::meta, parent, "SetException");

		::Uml::SetClass(SharedComponentReference::meta, parent, "SharedComponentReference");

		::Uml::SetClass(SharedResource::meta, parent, "SharedResource");

		::Uml::SetClass(Shares::meta, parent, "Shares");

		::Uml::SetClass(ShortInteger::meta, parent, "ShortInteger");

		::Uml::SetClass(SingleInputBase::meta, parent, "SingleInputBase");

		::Uml::SetClass(SingleOutputBase::meta, parent, "SingleOutputBase");

		::Uml::SetClass(SrcEdge::meta, parent, "SrcEdge");

		::Uml::SetClass(State::meta, parent, "State");

		::Uml::SetClass(StateBase::meta, parent, "StateBase");

		::Uml::SetClass(String::meta, parent, "String");

		::Uml::SetClass(StubProject::meta, parent, "StubProject");

		::Uml::SetClass(Supports::meta, parent, "Supports");

		::Uml::SetClass(SupportsDelegate::meta, parent, "SupportsDelegate");

		::Uml::SetClass(SupportsInterfaces::meta, parent, "SupportsInterfaces");

		::Uml::SetClass(SwitchedAggregate::meta, parent, "SwitchedAggregate");

		::Uml::SetClass(Taggable::meta, parent, "Taggable");
		::Uml::SetAttribute(Taggable::meta_SpecifyIdTag, Taggable::meta, "SpecifyIdTag");
		::Uml::SetAttribute(Taggable::meta_VersionTag, Taggable::meta, "VersionTag");

		::Uml::SetClass(Targets::meta, parent, "Targets");
		::Uml::SetAttribute(Targets::meta_name, Targets::meta, "name");

		::Uml::SetClass(Task::meta, parent, "Task");

		::Uml::SetClass(TaskSet::meta, parent, "TaskSet");
		::Uml::SetAttribute(TaskSet::meta_rate, TaskSet::meta, "rate");
		::Uml::SetAttribute(TaskSet::meta_priority, TaskSet::meta, "priority");

		::Uml::SetClass(Terminal::meta, parent, "Terminal");

		::Uml::SetClass(TerminalEffect::meta, parent, "TerminalEffect");

		::Uml::SetClass(TerminalTransition::meta, parent, "TerminalTransition");

		::Uml::SetClass(Throughput::meta, parent, "Throughput");

		::Uml::SetClass(TimeProbe::meta, parent, "TimeProbe");

		::Uml::SetClass(TimerConnection::meta, parent, "TimerConnection");

		::Uml::SetClass(TimerEventSinkConn::meta, parent, "TimerEventSinkConn");

		::Uml::SetClass(TopLevelBehavior::meta, parent, "TopLevelBehavior");

		::Uml::SetClass(TopLevelPackage::meta, parent, "TopLevelPackage");

		::Uml::SetClass(TopLevelPackageContainer::meta, parent, "TopLevelPackageContainer");

		::Uml::SetClass(TopLevelPackages::meta, parent, "TopLevelPackages");
		::Uml::SetAttribute(TopLevelPackages::meta_name, TopLevelPackages::meta, "name");

		::Uml::SetClass(Transition::meta, parent, "Transition");

		::Uml::SetClass(TriggerBenchmarks::meta, parent, "TriggerBenchmarks");

		::Uml::SetClass(TwowayOperation::meta, parent, "TwowayOperation");

		::Uml::SetClass(TypeEncoding::meta, parent, "TypeEncoding");

		::Uml::SetClass(TypeKind::meta, parent, "TypeKind");

		::Uml::SetClass(ValueObject::meta, parent, "ValueObject");

		::Uml::SetClass(Variable::meta, parent, "Variable");
		::Uml::SetAttribute(Variable::meta_InitialValue, Variable::meta, "InitialValue");

		::Uml::SetClass(WhileState::meta, parent, "WhileState");

		::Uml::SetClass(WorkLoadOperationConnection::meta, parent, "WorkLoadOperationConnection");

		::Uml::SetClass(Worker::meta, parent, "Worker");
		::Uml::SetAttribute(Worker::meta_Abstract, Worker::meta, "Abstract");

		::Uml::SetClass(WorkerFile::meta, parent, "WorkerFile");
		::Uml::SetAttribute(WorkerFile::meta_Location, WorkerFile::meta, "Location");

		::Uml::SetClass(WorkerLibraries::meta, parent, "WorkerLibraries");
		::Uml::SetAttribute(WorkerLibraries::meta_name, WorkerLibraries::meta, "name");

		::Uml::SetClass(WorkerLibrary::meta, parent, "WorkerLibrary");
		::Uml::SetAttribute(WorkerLibrary::meta_Location, WorkerLibrary::meta, "Location");

		::Uml::SetClass(WorkerPackage::meta, parent, "WorkerPackage");

		::Uml::SetClass(WorkerPackageBase::meta, parent, "WorkerPackageBase");

		::Uml::SetClass(WorkerType::meta, parent, "WorkerType");

		::Uml::SetClass(WorkloadCharacteristics::meta, parent, "WorkloadCharacteristics");

		::Uml::SetClass(Workspaces::meta, parent, "Workspaces");

		::Uml::SetClass(deliverTo::meta, parent, "deliverTo");

		::Uml::SetClass(emit::meta, parent, "emit");

		::Uml::SetClass(invoke::meta, parent, "invoke");

		::Uml::SetClass(package::meta, parent, "package");

		::Uml::SetClass(publish::meta, parent, "publish");

	}

	void InitMetaLinks(const ::Uml::Diagram &parent) {
		// classes
		::Uml::SetParentRole(Action::meta_Worker_parent, Action::meta, Worker::meta, "", "");

		::Uml::SetAssocRole(ActionBase::meta_srcBranchTransition, ActionBase::meta, BranchState::meta, "dstBranchTransition");
		BranchState::meta_dstBranchTransition_rev = ActionBase::meta_srcBranchTransition;
		::Uml::SetAssocRole(ActionBase::meta_dstEffect, ActionBase::meta, StateBase::meta, "srcEffect");
		StateBase::meta_srcEffect_rev = ActionBase::meta_dstEffect;
		::Uml::SetAssocRole(ActionBase::meta_srcLoopTransition, ActionBase::meta, LoopState::meta, "dstLoopTransition");
		LoopState::meta_dstLoopTransition_rev = ActionBase::meta_srcLoopTransition;
		::Uml::SetAssocRole(ActionBase::meta_srcTransition, ActionBase::meta, State::meta, "dstTransition");
		State::meta_dstTransition_rev = ActionBase::meta_srcTransition;
		::Uml::SetChildRole(ActionBase::meta_Property_children, ActionBase::meta, Property::meta, "", "");
		::Uml::SetParentRole(ActionBase::meta_BehaviorModel_parent, ActionBase::meta, BehaviorModel::meta, "", "");

		::Uml::SetChildRole(Aggregate::meta_Member_children, Aggregate::meta, Member::meta, "", "");

		::Uml::SetAssocRole(Alias::meta_ref, Alias::meta, MemberType::meta, "referedbyAlias");

		::Uml::SetParentRole(ApplicationTask::meta_TopLevelBehavior_parent, ApplicationTask::meta, TopLevelBehavior::meta, "", "");

		::Uml::SetChildRole(ArtifactContainer::meta_ImplementationArtifactReference_children, ArtifactContainer::meta, ImplementationArtifactReference::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_ArtifactDependsOn_children, ArtifactContainer::meta, ArtifactDependsOn::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_ArtifactDeployRequirement_children, ArtifactContainer::meta, ArtifactDeployRequirement::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_Requirement_children, ArtifactContainer::meta, Requirement::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_ArtifactExecParameter_children, ArtifactContainer::meta, ArtifactExecParameter::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_ArtifactInfoProperty_children, ArtifactContainer::meta, ArtifactInfoProperty::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_Property_children, ArtifactContainer::meta, Property::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_ImplementationArtifact_children, ArtifactContainer::meta, ImplementationArtifact::meta, "", "");
		::Uml::SetChildRole(ArtifactContainer::meta_ArtifactDependency_children, ArtifactContainer::meta, ArtifactDependency::meta, "", "");
		::Uml::SetParentRole(ArtifactContainer::meta_ImplementationArtifacts_parent, ArtifactContainer::meta, ImplementationArtifacts::meta, "", "");

		::Uml::SetParentRole(ArtifactDependency::meta_ArtifactContainer_parent, ArtifactDependency::meta, ArtifactContainer::meta, "", "");
		ArtifactDependency::meta_srcArtifactDependency_end_ = ImplementationArtifact::meta_srcArtifactDependency;
		ArtifactDependency::meta_dstArtifactDependency_end_ = ImplementationArtifact::meta_dstArtifactDependency;

		::Uml::SetParentRole(ArtifactDependsOn::meta_ArtifactContainer_parent, ArtifactDependsOn::meta, ArtifactContainer::meta, "", "");
		ArtifactDependsOn::meta_dstArtifactDependsOn_end_ = ImplementationArtifact::meta_dstArtifactDependsOn;
		ArtifactDependsOn::meta_srcArtifactDependsOn_end_ = ImplementationArtifactReference::meta_srcArtifactDependsOn;

		::Uml::SetParentRole(ArtifactDeployRequirement::meta_ArtifactContainer_parent, ArtifactDeployRequirement::meta, ArtifactContainer::meta, "", "");
		ArtifactDeployRequirement::meta_srcArtifactDeployRequirement_end_ = Requirement::meta_srcArtifactDeployRequirement;
		ArtifactDeployRequirement::meta_dstArtifactDeployRequirement_end_ = ImplementationArtifact::meta_dstArtifactDeployRequirement;

		::Uml::SetParentRole(ArtifactExecParameter::meta_ArtifactContainer_parent, ArtifactExecParameter::meta, ArtifactContainer::meta, "", "");
		ArtifactExecParameter::meta_srcArtifactExecParameter_end_ = Property::meta_srcArtifactExecParameter;
		ArtifactExecParameter::meta_dstArtifactExecParameter_end_ = ImplementationArtifact::meta_dstArtifactExecParameter;

		::Uml::SetParentRole(ArtifactInfoProperty::meta_ArtifactContainer_parent, ArtifactInfoProperty::meta, ArtifactContainer::meta, "", "");
		ArtifactInfoProperty::meta_srcArtifactInfoProperty_end_ = Property::meta_srcArtifactInfoProperty;
		ArtifactInfoProperty::meta_dstArtifactInfoProperty_end_ = ImplementationArtifact::meta_dstArtifactInfoProperty;

		::Uml::SetParentRole(AssemblyConfigProperty::meta_ComponentAssembly_parent, AssemblyConfigProperty::meta, ComponentAssembly::meta, "", "");
		AssemblyConfigProperty::meta_dstAssemblyConfigProperty_end_ = Component::meta_dstAssemblyConfigProperty;
		AssemblyConfigProperty::meta_srcAssemblyConfigProperty_end_ = Property::meta_srcAssemblyConfigProperty;

		::Uml::SetParentRole(AssemblyDeployRequirement::meta_ComponentAssembly_parent, AssemblyDeployRequirement::meta, ComponentAssembly::meta, "", "");
		AssemblyDeployRequirement::meta_srcAssemblyDeployRequirement_end_ = Requirement::meta_srcAssemblyDeployRequirement;
		AssemblyDeployRequirement::meta_dstAssemblyDeployRequirement_end_ = PublishConnector::meta_dstAssemblyDeployRequirement;

		::Uml::SetParentRole(AssemblyselectRequirement::meta_ComponentAssembly_parent, AssemblyselectRequirement::meta, ComponentAssembly::meta, "", "");
		AssemblyselectRequirement::meta_dstAssemblyselectRequirement_end_ = Component::meta_dstAssemblyselectRequirement;
		AssemblyselectRequirement::meta_srcAssemblyselectRequirement_end_ = Requirement::meta_srcAssemblyselectRequirement;

		::Uml::SetChildRole(Attribute::meta_SetException_children, Attribute::meta, SetException::meta, "", "");

		::Uml::SetParentRole(AttributeDelegate::meta_ComponentAssembly_parent, AttributeDelegate::meta, ComponentAssembly::meta, "", "");
		AttributeDelegate::meta_srcAttributeDelegate_end_ = ReadonlyAttribute::meta_srcAttributeDelegate;
		AttributeDelegate::meta_dstAttributeDelegate_end_ = AttributeMapping::meta_dstAttributeDelegate;

		::Uml::SetAssocRole(AttributeMapping::meta_dstAttributeMappingValue, AttributeMapping::meta, Property::meta, "srcAttributeMappingValue");
		Property::meta_srcAttributeMappingValue_rev = AttributeMapping::meta_dstAttributeMappingValue;
		::Uml::SetAssocRole(AttributeMapping::meta_dstAttributeDelegate, AttributeMapping::meta, ReadonlyAttribute::meta, "srcAttributeDelegate");
		ReadonlyAttribute::meta_srcAttributeDelegate_rev = AttributeMapping::meta_dstAttributeDelegate;
		::Uml::SetAssocRole(AttributeMapping::meta_dstAttributeMappingDelegate, AttributeMapping::meta, AttributeMapping::meta, "srcAttributeMappingDelegate");
		AttributeMapping::meta_srcAttributeMappingDelegate_rev = AttributeMapping::meta_dstAttributeMappingDelegate;
		::Uml::SetAssocRole(AttributeMapping::meta_srcAttributeMappingDelegate, AttributeMapping::meta, AttributeMapping::meta, "dstAttributeMappingDelegate");
		AttributeMapping::meta_dstAttributeMappingDelegate_rev = AttributeMapping::meta_srcAttributeMappingDelegate;
		::Uml::SetAssocRole(AttributeMapping::meta_ref, AttributeMapping::meta, ReadonlyAttribute::meta, "referedbyAttributeMapping");
		::Uml::SetParentRole(AttributeMapping::meta_ComponentAssembly_parent, AttributeMapping::meta, ComponentAssembly::meta, "", "");

		::Uml::SetParentRole(AttributeMappingDelegate::meta_ComponentAssembly_parent, AttributeMappingDelegate::meta, ComponentAssembly::meta, "", "");
		AttributeMappingDelegate::meta_srcAttributeMappingDelegate_end_ = AttributeMapping::meta_srcAttributeMappingDelegate;
		AttributeMappingDelegate::meta_dstAttributeMappingDelegate_end_ = AttributeMapping::meta_dstAttributeMappingDelegate;

		::Uml::SetParentRole(AttributeMappingValue::meta_ComponentAssembly_parent, AttributeMappingValue::meta, ComponentAssembly::meta, "", "");
		AttributeMappingValue::meta_srcAttributeMappingValue_end_ = Property::meta_srcAttributeMappingValue;
		AttributeMappingValue::meta_dstAttributeMappingValue_end_ = AttributeMapping::meta_dstAttributeMappingValue;

		::Uml::SetAssocRole(AttributeMember::meta_ref, AttributeMember::meta, MemberType::meta, "referedbyAttributeMember");
		::Uml::SetParentRole(AttributeMember::meta_ReadonlyAttribute_parent, AttributeMember::meta, ReadonlyAttribute::meta, "", "");

		::Uml::SetParentRole(AttributeValue::meta_ComponentAssembly_parent, AttributeValue::meta, ComponentAssembly::meta, "", "");
		AttributeValue::meta_dstAttributeValue_end_ = ReadonlyAttribute::meta_dstAttributeValue;
		AttributeValue::meta_srcAttributeValue_end_ = Property::meta_srcAttributeValue;

		::Uml::SetAssocRole(BehaviorInputAction::meta_srcFinish, BehaviorInputAction::meta, StateBase::meta, "dstFinish");
		StateBase::meta_dstFinish_rev = BehaviorInputAction::meta_srcFinish;
		::Uml::SetAssocRole(BehaviorInputAction::meta_dstInputEffect, BehaviorInputAction::meta, StateBase::meta, "srcInputEffect");
		StateBase::meta_srcInputEffect_rev = BehaviorInputAction::meta_dstInputEffect;
		::Uml::SetChildRole(BehaviorInputAction::meta_Property_children, BehaviorInputAction::meta, Property::meta, "", "");
		::Uml::SetParentRole(BehaviorInputAction::meta_BehaviorModel_parent, BehaviorInputAction::meta, BehaviorModel::meta, "", "");

		::Uml::SetChildRole(BehaviorModel::meta_TerminalTransition_children, BehaviorModel::meta, TerminalTransition::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_Variable_children, BehaviorModel::meta, Variable::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_Terminal_children, BehaviorModel::meta, Terminal::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_TerminalEffect_children, BehaviorModel::meta, TerminalEffect::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_StateBase_children, BehaviorModel::meta, StateBase::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_BranchTransition_children, BehaviorModel::meta, BranchTransition::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_Transition_children, BehaviorModel::meta, Transition::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_LoopTransition_children, BehaviorModel::meta, LoopTransition::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_Finish_children, BehaviorModel::meta, Finish::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_BehaviorInputAction_children, BehaviorModel::meta, BehaviorInputAction::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_ActionBase_children, BehaviorModel::meta, ActionBase::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_InputEffect_children, BehaviorModel::meta, InputEffect::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_Effect_children, BehaviorModel::meta, Effect::meta, "", "");
		::Uml::SetChildRole(BehaviorModel::meta_QueryInputAction_children, BehaviorModel::meta, QueryInputAction::meta, "", "");

		::Uml::SetChildRole(BenchmarkAnalysis::meta_TimerConnection_children, BenchmarkAnalysis::meta, TimerConnection::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_OperationBase_children, BenchmarkAnalysis::meta, OperationBase::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_MetricConnection_children, BenchmarkAnalysis::meta, MetricConnection::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_DataAnalysisBase_children, BenchmarkAnalysis::meta, DataAnalysisBase::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_MetricsBase_children, BenchmarkAnalysis::meta, MetricsBase::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_TimeProbe_children, BenchmarkAnalysis::meta, TimeProbe::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_OperationRef_children, BenchmarkAnalysis::meta, OperationRef::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_EventRef_children, BenchmarkAnalysis::meta, EventRef::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_Event_children, BenchmarkAnalysis::meta, Event::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_TimerEventSinkConn_children, BenchmarkAnalysis::meta, TimerEventSinkConn::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_TaskSet_children, BenchmarkAnalysis::meta, TaskSet::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_Task_children, BenchmarkAnalysis::meta, Task::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_WorkloadCharacteristics_children, BenchmarkAnalysis::meta, WorkloadCharacteristics::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_ComponentOperation_children, BenchmarkAnalysis::meta, ComponentOperation::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_CompRef_children, BenchmarkAnalysis::meta, CompRef::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_WorkLoadOperationConnection_children, BenchmarkAnalysis::meta, WorkLoadOperationConnection::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_BenchmarkType_children, BenchmarkAnalysis::meta, BenchmarkType::meta, "", "");
		::Uml::SetChildRole(BenchmarkAnalysis::meta_BenchmarkCharacteristics_children, BenchmarkAnalysis::meta, BenchmarkCharacteristics::meta, "", "");
		::Uml::SetParentRole(BenchmarkAnalysis::meta_ComponentAnalyses_parent, BenchmarkAnalysis::meta, ComponentAnalyses::meta, "", "");

		::Uml::SetParentRole(BenchmarkCharacteristics::meta_BenchmarkAnalysis_parent, BenchmarkCharacteristics::meta, BenchmarkAnalysis::meta, "", "");
		BenchmarkCharacteristics::meta_dstBenchmarkCharacteristics_end_ = BenchmarkType::meta_dstBenchmarkCharacteristics;
		BenchmarkCharacteristics::meta_srcBenchmarkCharacteristics_end_ = MetricsBase::meta_srcBenchmarkCharacteristics;

		::Uml::SetAssocRole(BenchmarkType::meta_dstBenchmarkCharacteristics, BenchmarkType::meta, MetricsBase::meta, "srcBenchmarkCharacteristics");
		MetricsBase::meta_srcBenchmarkCharacteristics_rev = BenchmarkType::meta_dstBenchmarkCharacteristics;
		::Uml::SetParentRole(BenchmarkType::meta_BenchmarkAnalysis_parent, BenchmarkType::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(Boxed::meta_ref, Boxed::meta, MemberType::meta, "referedbyBoxed");

		::Uml::SetAssocRole(BranchState::meta_dstBranchTransition, BranchState::meta, ActionBase::meta, "srcBranchTransition");
		ActionBase::meta_srcBranchTransition_rev = BranchState::meta_dstBranchTransition;

		::Uml::SetParentRole(BranchTransition::meta_BehaviorModel_parent, BranchTransition::meta, BehaviorModel::meta, "", "");
		BranchTransition::meta_dstBranchTransition_end_ = BranchState::meta_dstBranchTransition;
		BranchTransition::meta_srcBranchTransition_end_ = ActionBase::meta_srcBranchTransition;

		::Uml::SetAssocRole(Bridge::meta_srcBridgeConnection, Bridge::meta, Interconnect::meta, "dstBridgeConnection");
		Interconnect::meta_dstBridgeConnection_rev = Bridge::meta_srcBridgeConnection;
		::Uml::SetChildRole(Bridge::meta_Resource_children, Bridge::meta, Resource::meta, "", "");
		::Uml::SetParentRole(Bridge::meta_Domain_parent, Bridge::meta, Domain::meta, "", "");

		::Uml::SetParentRole(BridgeConnection::meta_Domain_parent, BridgeConnection::meta, Domain::meta, "", "");
		BridgeConnection::meta_srcBridgeConnection_end_ = Bridge::meta_srcBridgeConnection;
		BridgeConnection::meta_dstBridgeConnection_end_ = Interconnect::meta_dstBridgeConnection;

		::Uml::SetAssocRole(Capability::meta_srcImplementationCapability, Capability::meta, ComponentImplementation::meta, "dstImplementationCapability");
		ComponentImplementation::meta_dstImplementationCapability_rev = Capability::meta_srcImplementationCapability;
		::Uml::SetParentRole(Capability::meta_ComponentImplementationContainer_parent, Capability::meta, ComponentImplementationContainer::meta, "", "");

		::Uml::SetAssocRole(Collection::meta_ref, Collection::meta, MemberType::meta, "referedbyCollection");
		::Uml::SetParentRole(Collection::meta_PredefinedTypes_parent, Collection::meta, PredefinedTypes::meta, "", "");

		::Uml::SetAssocRole(CollocationGroup::meta_dstInstanceMapping, CollocationGroup::meta, NodeReference::meta, "srcInstanceMapping");
		NodeReference::meta_srcInstanceMapping_rev = CollocationGroup::meta_dstInstanceMapping;
		::Uml::SetAssocRole(CollocationGroup::meta_members, CollocationGroup::meta, CollocationGroupMember::meta, "setCollocationGroup");
		::Uml::SetParentRole(CollocationGroup::meta_DeploymentPlan_parent, CollocationGroup::meta, DeploymentPlan::meta, "", "");

		::Uml::SetAssocRole(CollocationGroupMember::meta_setCollocationGroup, CollocationGroupMember::meta, CollocationGroup::meta, "members");
		::Uml::SetParentRole(CollocationGroupMember::meta_DeploymentPlan_parent, CollocationGroupMember::meta, DeploymentPlan::meta, "", "");

		::Uml::SetAssocRole(CompRef::meta_srcComponentOperation, CompRef::meta, OperationRef::meta, "dstComponentOperation");
		OperationRef::meta_dstComponentOperation_rev = CompRef::meta_srcComponentOperation;
		::Uml::SetAssocRole(CompRef::meta_ref, CompRef::meta, Component::meta, "referedbyCompRef");
		::Uml::SetParentRole(CompRef::meta_BenchmarkAnalysis_parent, CompRef::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(Component::meta_referedbyCompRef, Component::meta, CompRef::meta, "ref");
		::Uml::SetAssocRole(Component::meta_dstAssemblyselectRequirement, Component::meta, Requirement::meta, "srcAssemblyselectRequirement");
		Requirement::meta_srcAssemblyselectRequirement_rev = Component::meta_dstAssemblyselectRequirement;
		::Uml::SetAssocRole(Component::meta_dstAssemblyConfigProperty, Component::meta, Property::meta, "srcAssemblyConfigProperty");
		Property::meta_srcAssemblyConfigProperty_rev = Component::meta_dstAssemblyConfigProperty;
		::Uml::SetAssocRole(Component::meta_referedbyComponentRef, Component::meta, ComponentRef::meta, "ref");
		::Uml::SetChildRole(Component::meta_ReadonlyAttribute_children, Component::meta, ReadonlyAttribute::meta, "", "");
		::Uml::SetChildRole(Component::meta_Port_children, Component::meta, Port::meta, "", "");
		::Uml::SetChildRole(Component::meta_WorkerType_children, Component::meta, WorkerType::meta, "", "");
		::Uml::SetParentRole(Component::meta_ComponentAssembly_parent, Component::meta, ComponentAssembly::meta, "", "");

		::Uml::SetChildRole(ComponentAnalyses::meta_BenchmarkAnalysis_children, ComponentAnalyses::meta, BenchmarkAnalysis::meta, "", "");
		::Uml::SetParentRole(ComponentAnalyses::meta_RootFolder_parent, ComponentAnalyses::meta, RootFolder::meta, "", "");

		::Uml::SetAssocRole(ComponentAssembly::meta_referedbyComponentAssemblyReference, ComponentAssembly::meta, ComponentAssemblyReference::meta, "ref");
		::Uml::SetAssocRole(ComponentAssembly::meta_dstCriticalPath, ComponentAssembly::meta, PathReference::meta, "srcCriticalPath");
		PathReference::meta_srcCriticalPath_rev = ComponentAssembly::meta_dstCriticalPath;
		::Uml::SetChildRole(ComponentAssembly::meta_Property_children, ComponentAssembly::meta, Property::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ComponentPackage_children, ComponentAssembly::meta, ComponentPackage::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ComponentPackageReference_children, ComponentAssembly::meta, ComponentPackageReference::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_Requirement_children, ComponentAssembly::meta, Requirement::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_Component_children, ComponentAssembly::meta, Component::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ComponentAssembly_children, ComponentAssembly::meta, ComponentAssembly::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ProvidedRequestPort_children, ComponentAssembly::meta, ProvidedRequestPort::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_RequiredRequestPort_children, ComponentAssembly::meta, RequiredRequestPort::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_InEventPort_children, ComponentAssembly::meta, InEventPort::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_OutEventPort_children, ComponentAssembly::meta, OutEventPort::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_emit_children, ComponentAssembly::meta, emit::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_EventSourceDelegate_children, ComponentAssembly::meta, EventSourceDelegate::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_EventSinkDelegate_children, ComponentAssembly::meta, EventSinkDelegate::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_deliverTo_children, ComponentAssembly::meta, deliverTo::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_publish_children, ComponentAssembly::meta, publish::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AssemblyDeployRequirement_children, ComponentAssembly::meta, AssemblyDeployRequirement::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ComponentAssemblyReference_children, ComponentAssembly::meta, ComponentAssemblyReference::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ComponentRef_children, ComponentAssembly::meta, ComponentRef::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AssemblyselectRequirement_children, ComponentAssembly::meta, AssemblyselectRequirement::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AttributeValue_children, ComponentAssembly::meta, AttributeValue::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AttributeDelegate_children, ComponentAssembly::meta, AttributeDelegate::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AttributeMappingValue_children, ComponentAssembly::meta, AttributeMappingValue::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AssemblyConfigProperty_children, ComponentAssembly::meta, AssemblyConfigProperty::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_FacetDelegate_children, ComponentAssembly::meta, FacetDelegate::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_invoke_children, ComponentAssembly::meta, invoke::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ReceptacleDelegate_children, ComponentAssembly::meta, ReceptacleDelegate::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AttributeMappingDelegate_children, ComponentAssembly::meta, AttributeMappingDelegate::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ExternalDelegate_children, ComponentAssembly::meta, ExternalDelegate::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_AttributeMapping_children, ComponentAssembly::meta, AttributeMapping::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_PublishConnector_children, ComponentAssembly::meta, PublishConnector::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_ExternalPortReference_children, ComponentAssembly::meta, ExternalPortReference::meta, "", "");
		::Uml::SetChildRole(ComponentAssembly::meta_SupportsDelegate_children, ComponentAssembly::meta, SupportsDelegate::meta, "", "");
		::Uml::SetParentRole(ComponentAssembly::meta_ComponentAssembly_parent, ComponentAssembly::meta, ComponentAssembly::meta, "", "");

		::Uml::SetAssocRole(ComponentAssemblyReference::meta_ref, ComponentAssemblyReference::meta, ComponentAssembly::meta, "referedbyComponentAssemblyReference");
		::Uml::SetParentRole(ComponentAssemblyReference::meta_ComponentAssembly_parent, ComponentAssemblyReference::meta, ComponentAssembly::meta, "", "");

		::Uml::SetChildRole(ComponentBuild::meta_MPC_children, ComponentBuild::meta, MPC::meta, "", "");
		::Uml::SetParentRole(ComponentBuild::meta_RootFolder_parent, ComponentBuild::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(ComponentConfigProperty::meta_ComponentContainer_parent, ComponentConfigProperty::meta, ComponentContainer::meta, "", "");
		ComponentConfigProperty::meta_dstComponentConfigProperty_end_ = ComponentRef::meta_dstComponentConfigProperty;
		ComponentConfigProperty::meta_srcComponentConfigProperty_end_ = Property::meta_srcComponentConfigProperty;

		::Uml::SetChildRole(ComponentContainer::meta_ComponentConfigProperty_children, ComponentContainer::meta, ComponentConfigProperty::meta, "", "");
		::Uml::SetChildRole(ComponentContainer::meta_Property_children, ComponentContainer::meta, Property::meta, "", "");
		::Uml::SetChildRole(ComponentContainer::meta_ComponentInfoProperty_children, ComponentContainer::meta, ComponentInfoProperty::meta, "", "");
		::Uml::SetChildRole(ComponentContainer::meta_ComponentProperty_children, ComponentContainer::meta, ComponentProperty::meta, "", "");
		::Uml::SetChildRole(ComponentContainer::meta_ComponentPropertyDescription_children, ComponentContainer::meta, ComponentPropertyDescription::meta, "", "");
		::Uml::SetChildRole(ComponentContainer::meta_ComponentRef_child, ComponentContainer::meta, ComponentRef::meta, "", "");
		::Uml::SetParentRole(ComponentContainer::meta_ComponentTypes_parent, ComponentContainer::meta, ComponentTypes::meta, "", "");

		::Uml::SetAssocRole(ComponentFactory::meta_referedbyComponentFactoryInstance, ComponentFactory::meta, ComponentFactoryInstance::meta, "ref");
		::Uml::SetAssocRole(ComponentFactory::meta_dstManagesComponent, ComponentFactory::meta, Manageable::meta, "srcManagesComponent");
		Manageable::meta_srcManagesComponent_rev = ComponentFactory::meta_dstManagesComponent;
		::Uml::SetChildRole(ComponentFactory::meta_LookupKey_child, ComponentFactory::meta, LookupKey::meta, "", "");
		::Uml::SetChildRole(ComponentFactory::meta_FactoryOperation_children, ComponentFactory::meta, FactoryOperation::meta, "", "");
		::Uml::SetChildRole(ComponentFactory::meta_LookupOperation_children, ComponentFactory::meta, LookupOperation::meta, "", "");

		::Uml::SetChildRole(ComponentFactoryImplementationContainer::meta_ComponentFactoryInstance_children, ComponentFactoryImplementationContainer::meta, ComponentFactoryInstance::meta, "", "");
		::Uml::SetParentRole(ComponentFactoryImplementationContainer::meta_ComponentFactoryImplementations_parent, ComponentFactoryImplementationContainer::meta, ComponentFactoryImplementations::meta, "", "");

		::Uml::SetChildRole(ComponentFactoryImplementations::meta_ComponentFactoryImplementationContainer_children, ComponentFactoryImplementations::meta, ComponentFactoryImplementationContainer::meta, "", "");
		::Uml::SetParentRole(ComponentFactoryImplementations::meta_RootFolder_parent, ComponentFactoryImplementations::meta, RootFolder::meta, "", "");

		::Uml::SetAssocRole(ComponentFactoryInstance::meta_referedbyComponentFactoryRef, ComponentFactoryInstance::meta, ComponentFactoryRef::meta, "ref");
		::Uml::SetAssocRole(ComponentFactoryInstance::meta_ref, ComponentFactoryInstance::meta, ComponentFactory::meta, "referedbyComponentFactoryInstance");
		::Uml::SetParentRole(ComponentFactoryInstance::meta_ComponentFactoryImplementationContainer_parent, ComponentFactoryInstance::meta, ComponentFactoryImplementationContainer::meta, "", "");

		::Uml::SetAssocRole(ComponentFactoryRef::meta_ref, ComponentFactoryRef::meta, ComponentFactoryInstance::meta, "referedbyComponentFactoryRef");
		::Uml::SetAssocRole(ComponentFactoryRef::meta_dstDeploys, ComponentFactoryRef::meta, ComponentRef::meta, "srcDeploys");
		ComponentRef::meta_srcDeploys_rev = ComponentFactoryRef::meta_dstDeploys;

		::Uml::SetAssocRole(ComponentImplementation::meta_dstImplementationDependsOn, ComponentImplementation::meta, ImplementationDependency::meta, "srcImplementationDependsOn");
		ImplementationDependency::meta_srcImplementationDependsOn_rev = ComponentImplementation::meta_dstImplementationDependsOn;
		::Uml::SetAssocRole(ComponentImplementation::meta_dstImplementationCapability, ComponentImplementation::meta, Capability::meta, "srcImplementationCapability");
		Capability::meta_srcImplementationCapability_rev = ComponentImplementation::meta_dstImplementationCapability;
		::Uml::SetAssocRole(ComponentImplementation::meta_dstImplements, ComponentImplementation::meta, ComponentRef::meta, "srcImplements");
		ComponentRef::meta_srcImplements_rev = ComponentImplementation::meta_dstImplements;
		::Uml::SetAssocRole(ComponentImplementation::meta_referedbyComponentImplementationReference, ComponentImplementation::meta, ComponentImplementationReference::meta, "ref");
		::Uml::SetParentRole(ComponentImplementation::meta_ComponentImplementationContainer_parent, ComponentImplementation::meta, ComponentImplementationContainer::meta, "", "");

		::Uml::SetAssocRole(ComponentImplementationArtifact::meta_ref, ComponentImplementationArtifact::meta, ImplementationArtifact::meta, "referedbyComponentImplemenationArtifact");

		::Uml::SetChildRole(ComponentImplementationContainer::meta_Implements_child, ComponentImplementationContainer::meta, Implements::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_ImplementationDependsOn_children, ComponentImplementationContainer::meta, ImplementationDependsOn::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_ComponentRef_child, ComponentImplementationContainer::meta, ComponentRef::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_ImplementationDependency_children, ComponentImplementationContainer::meta, ImplementationDependency::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_ImplementationCapability_children, ComponentImplementationContainer::meta, ImplementationCapability::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_Capability_children, ComponentImplementationContainer::meta, Capability::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_CriticalPath_children, ComponentImplementationContainer::meta, CriticalPath::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_PathReference_child, ComponentImplementationContainer::meta, PathReference::meta, "", "");
		::Uml::SetChildRole(ComponentImplementationContainer::meta_ComponentImplementation_children, ComponentImplementationContainer::meta, ComponentImplementation::meta, "", "");
		::Uml::SetParentRole(ComponentImplementationContainer::meta_ComponentImplementations_parent, ComponentImplementationContainer::meta, ComponentImplementations::meta, "", "");

		::Uml::SetAssocRole(ComponentImplementationReference::meta_ref, ComponentImplementationReference::meta, ComponentImplementation::meta, "referedbyComponentImplementationReference");
		::Uml::SetAssocRole(ComponentImplementationReference::meta_srcImplementation, ComponentImplementationReference::meta, ComponentPackage::meta, "dstImplementation");
		ComponentPackage::meta_dstImplementation_rev = ComponentImplementationReference::meta_srcImplementation;
		::Uml::SetParentRole(ComponentImplementationReference::meta_PackageContainer_parent, ComponentImplementationReference::meta, PackageContainer::meta, "", "");

		::Uml::SetChildRole(ComponentImplementations::meta_ComponentImplementationContainer_children, ComponentImplementations::meta, ComponentImplementationContainer::meta, "", "");
		::Uml::SetParentRole(ComponentImplementations::meta_RootFolder_parent, ComponentImplementations::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(ComponentInfoProperty::meta_ComponentContainer_parent, ComponentInfoProperty::meta, ComponentContainer::meta, "", "");
		ComponentInfoProperty::meta_dstComponentInfoProperty_end_ = ComponentRef::meta_dstComponentInfoProperty;
		ComponentInfoProperty::meta_srcComponentInfoProperty_end_ = Property::meta_srcComponentInfoProperty;

		::Uml::SetAssocRole(ComponentLib::meta_dstExtResourceConn, ComponentLib::meta, ExternalResources::meta, "srcExtResourceConn");
		ExternalResources::meta_srcExtResourceConn_rev = ComponentLib::meta_dstExtResourceConn;
		::Uml::SetParentRole(ComponentLib::meta_Project_parent, ComponentLib::meta, Project::meta, "", "");

		::Uml::SetParentRole(ComponentOperation::meta_BenchmarkAnalysis_parent, ComponentOperation::meta, BenchmarkAnalysis::meta, "", "");
		ComponentOperation::meta_srcComponentOperation_end_ = CompRef::meta_srcComponentOperation;
		ComponentOperation::meta_dstComponentOperation_end_ = OperationRef::meta_dstComponentOperation;

		::Uml::SetAssocRole(ComponentPackage::meta_dstImplementation, ComponentPackage::meta, ComponentImplementationReference::meta, "srcImplementation");
		ComponentImplementationReference::meta_srcImplementation_rev = ComponentPackage::meta_dstImplementation;
		::Uml::SetAssocRole(ComponentPackage::meta_srcPackageConfBasePackage, ComponentPackage::meta, PackageConfiguration::meta, "dstPackageConfBasePackage");
		PackageConfiguration::meta_dstPackageConfBasePackage_rev = ComponentPackage::meta_srcPackageConfBasePackage;
		::Uml::SetAssocRole(ComponentPackage::meta_dstPackageInterface, ComponentPackage::meta, ComponentRef::meta, "srcPackageInterface");
		ComponentRef::meta_srcPackageInterface_rev = ComponentPackage::meta_dstPackageInterface;
		::Uml::SetAssocRole(ComponentPackage::meta_dstPackageConfigProperty, ComponentPackage::meta, Property::meta, "srcPackageConfigProperty");
		Property::meta_srcPackageConfigProperty_rev = ComponentPackage::meta_dstPackageConfigProperty;
		::Uml::SetAssocRole(ComponentPackage::meta_dstPackageInfoProperty, ComponentPackage::meta, Property::meta, "srcPackageInfoProperty");
		Property::meta_srcPackageInfoProperty_rev = ComponentPackage::meta_dstPackageInfoProperty;
		::Uml::SetAssocRole(ComponentPackage::meta_referedbyComponentPackageReference, ComponentPackage::meta, ComponentPackageReference::meta, "ref");
		::Uml::SetParentRole(ComponentPackage::meta_ComponentAssembly_parent, ComponentPackage::meta, ComponentAssembly::meta, "", "");
		::Uml::SetParentRole(ComponentPackage::meta_PackageConfigurationContainer_parent, ComponentPackage::meta, PackageConfigurationContainer::meta, "", "");
		::Uml::SetParentRole(ComponentPackage::meta_PackageContainer_parent, ComponentPackage::meta, PackageContainer::meta, "", "");

		::Uml::SetAssocRole(ComponentPackageReference::meta_srcPackageConfReference, ComponentPackageReference::meta, PackageConfiguration::meta, "dstPackageConfReference");
		PackageConfiguration::meta_dstPackageConfReference_rev = ComponentPackageReference::meta_srcPackageConfReference;
		::Uml::SetAssocRole(ComponentPackageReference::meta_ref, ComponentPackageReference::meta, ComponentPackage::meta, "referedbyComponentPackageReference");
		::Uml::SetParentRole(ComponentPackageReference::meta_ComponentAssembly_parent, ComponentPackageReference::meta, ComponentAssembly::meta, "", "");
		::Uml::SetParentRole(ComponentPackageReference::meta_PackageConfigurationContainer_parent, ComponentPackageReference::meta, PackageConfigurationContainer::meta, "", "");

		::Uml::SetChildRole(ComponentPackages::meta_PackageContainer_children, ComponentPackages::meta, PackageContainer::meta, "", "");
		::Uml::SetParentRole(ComponentPackages::meta_RootFolder_parent, ComponentPackages::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(ComponentProperty::meta_ComponentContainer_parent, ComponentProperty::meta, ComponentContainer::meta, "", "");
		ComponentProperty::meta_dstComponentProperty_end_ = ComponentRef::meta_dstComponentProperty;
		ComponentProperty::meta_srcComponentProperty_end_ = ComponentPropertyDescription::meta_srcComponentProperty;

		::Uml::SetAssocRole(ComponentPropertyDescription::meta_srcComponentProperty, ComponentPropertyDescription::meta, ComponentRef::meta, "dstComponentProperty");
		ComponentRef::meta_dstComponentProperty_rev = ComponentPropertyDescription::meta_srcComponentProperty;
		::Uml::SetChildRole(ComponentPropertyDescription::meta_DataType_child, ComponentPropertyDescription::meta, DataType::meta, "", "");
		::Uml::SetParentRole(ComponentPropertyDescription::meta_ComponentContainer_parent, ComponentPropertyDescription::meta, ComponentContainer::meta, "", "");

		::Uml::SetAssocRole(ComponentRef::meta_referedbySharedComponentReference, ComponentRef::meta, SharedComponentReference::meta, "ref");
		::Uml::SetAssocRole(ComponentRef::meta_srcDeploys, ComponentRef::meta, ComponentFactoryRef::meta, "dstDeploys");
		ComponentFactoryRef::meta_dstDeploys_rev = ComponentRef::meta_srcDeploys;
		::Uml::SetAssocRole(ComponentRef::meta_srcImplements, ComponentRef::meta, ComponentImplementation::meta, "dstImplements");
		ComponentImplementation::meta_dstImplements_rev = ComponentRef::meta_srcImplements;
		::Uml::SetAssocRole(ComponentRef::meta_dstComponentProperty, ComponentRef::meta, ComponentPropertyDescription::meta, "srcComponentProperty");
		ComponentPropertyDescription::meta_srcComponentProperty_rev = ComponentRef::meta_dstComponentProperty;
		::Uml::SetAssocRole(ComponentRef::meta_srcPackageInterface, ComponentRef::meta, ComponentPackage::meta, "dstPackageInterface");
		ComponentPackage::meta_dstPackageInterface_rev = ComponentRef::meta_srcPackageInterface;
		::Uml::SetAssocRole(ComponentRef::meta_dstComponentConfigProperty, ComponentRef::meta, Property::meta, "srcComponentConfigProperty");
		Property::meta_srcComponentConfigProperty_rev = ComponentRef::meta_dstComponentConfigProperty;
		::Uml::SetAssocRole(ComponentRef::meta_dstComponentInfoProperty, ComponentRef::meta, Property::meta, "srcComponentInfoProperty");
		Property::meta_srcComponentInfoProperty_rev = ComponentRef::meta_dstComponentInfoProperty;
		::Uml::SetAssocRole(ComponentRef::meta_ref, ComponentRef::meta, Component::meta, "referedbyComponentRef");
		::Uml::SetParentRole(ComponentRef::meta_ComponentAssembly_parent, ComponentRef::meta, ComponentAssembly::meta, "", "");
		::Uml::SetParentRole(ComponentRef::meta_Path_parent, ComponentRef::meta, Path::meta, "", "");
		::Uml::SetParentRole(ComponentRef::meta_ComponentImplementationContainer_parent, ComponentRef::meta, ComponentImplementationContainer::meta, "", "");
		::Uml::SetParentRole(ComponentRef::meta_ComponentContainer_parent, ComponentRef::meta, ComponentContainer::meta, "", "");
		::Uml::SetParentRole(ComponentRef::meta_PackageContainer_parent, ComponentRef::meta, PackageContainer::meta, "", "");
		::Uml::SetParentRole(ComponentRef::meta_Package_parent, ComponentRef::meta, Package::meta, "", "");
		::Uml::SetParentRole(ComponentRef::meta_File_parent, ComponentRef::meta, File::meta, "", "");

		::Uml::SetAssocRole(ComponentServantArtifact::meta_ref, ComponentServantArtifact::meta, ImplementationArtifact::meta, "referedbyComponentServantArtifact");

		::Uml::SetChildRole(ComponentTypes::meta_ComponentContainer_children, ComponentTypes::meta, ComponentContainer::meta, "", "");
		::Uml::SetParentRole(ComponentTypes::meta_RootFolder_parent, ComponentTypes::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(ConfigProperty::meta_ImplementationContainer_parent, ConfigProperty::meta, ImplementationContainer::meta, "", "");
		ConfigProperty::meta_srcConfigProperty_end_ = Property::meta_srcConfigProperty;
		ConfigProperty::meta_dstConfigProperty_end_ = Implemenation::meta_dstConfigProperty;

		::Uml::SetChildRole(ConnectedComponent::meta_Port_children, ConnectedComponent::meta, Port::meta, "", "");
		::Uml::SetChildRole(ConnectedComponent::meta_DstEdge_children, ConnectedComponent::meta, DstEdge::meta, "", "");

		::Uml::SetAssocRole(Constant::meta_ref, Constant::meta, ConstantType::meta, "referedbyConstant");
		::Uml::SetParentRole(Constant::meta_HasOperations_parent, Constant::meta, HasOperations::meta, "", "");
		::Uml::SetParentRole(Constant::meta_Package_parent, Constant::meta, Package::meta, "", "");
		::Uml::SetParentRole(Constant::meta_File_parent, Constant::meta, File::meta, "", "");

		::Uml::SetAssocRole(ConstantType::meta_referedbyDiscriminator, ConstantType::meta, Discriminator::meta, "ref");
		::Uml::SetAssocRole(ConstantType::meta_referedbyConstant, ConstantType::meta, Constant::meta, "ref");

		::Uml::SetParentRole(CriticalPath::meta_ComponentImplementationContainer_parent, CriticalPath::meta, ComponentImplementationContainer::meta, "", "");
		CriticalPath::meta_srcCriticalPath_end_ = PathReference::meta_srcCriticalPath;
		CriticalPath::meta_dstCriticalPath_end_ = ComponentAssembly::meta_dstCriticalPath;

		::Uml::SetParentRole(DataAnalysisBase::meta_MetricsBase_parent, DataAnalysisBase::meta, MetricsBase::meta, "", "");
		::Uml::SetParentRole(DataAnalysisBase::meta_BenchmarkAnalysis_parent, DataAnalysisBase::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(DataType::meta_ref, DataType::meta, MemberType::meta, "referedbyDataType");
		::Uml::SetParentRole(DataType::meta_ComponentPropertyDescription_parent, DataType::meta, ComponentPropertyDescription::meta, "", "");
		::Uml::SetParentRole(DataType::meta_SatisfierProperty_parent, DataType::meta, SatisfierProperty::meta, "", "");
		::Uml::SetParentRole(DataType::meta_Property_parent, DataType::meta, Property::meta, "", "");

		::Uml::SetChildRole(DeploymentPlan::meta_InstanceMapping_children, DeploymentPlan::meta, InstanceMapping::meta, "", "");
		::Uml::SetChildRole(DeploymentPlan::meta_NodeReference_children, DeploymentPlan::meta, NodeReference::meta, "", "");
		::Uml::SetChildRole(DeploymentPlan::meta_CollocationGroup_children, DeploymentPlan::meta, CollocationGroup::meta, "", "");
		::Uml::SetChildRole(DeploymentPlan::meta_Property_children, DeploymentPlan::meta, Property::meta, "", "");
		::Uml::SetChildRole(DeploymentPlan::meta_Deploys_children, DeploymentPlan::meta, Deploys::meta, "", "");
		::Uml::SetChildRole(DeploymentPlan::meta_CollocationGroupMember_children, DeploymentPlan::meta, CollocationGroupMember::meta, "", "");
		::Uml::SetParentRole(DeploymentPlan::meta_DeploymentPlans_parent, DeploymentPlan::meta, DeploymentPlans::meta, "", "");

		::Uml::SetChildRole(DeploymentPlans::meta_DeploymentPlan_children, DeploymentPlans::meta, DeploymentPlan::meta, "", "");
		::Uml::SetParentRole(DeploymentPlans::meta_RootFolder_parent, DeploymentPlans::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(Deploys::meta_DeploymentPlan_parent, Deploys::meta, DeploymentPlan::meta, "", "");
		Deploys::meta_srcDeploys_end_ = ComponentRef::meta_srcDeploys;
		Deploys::meta_dstDeploys_end_ = ComponentFactoryRef::meta_dstDeploys;

		::Uml::SetAssocRole(Discriminator::meta_ref, Discriminator::meta, ConstantType::meta, "referedbyDiscriminator");
		::Uml::SetParentRole(Discriminator::meta_SwitchedAggregate_parent, Discriminator::meta, SwitchedAggregate::meta, "", "");

		::Uml::SetChildRole(Domain::meta_Interconnect_children, Domain::meta, Interconnect::meta, "", "");
		::Uml::SetChildRole(Domain::meta_InterconnectConnection_children, Domain::meta, InterconnectConnection::meta, "", "");
		::Uml::SetChildRole(Domain::meta_Node_children, Domain::meta, Node::meta, "", "");
		::Uml::SetChildRole(Domain::meta_BridgeConnection_children, Domain::meta, BridgeConnection::meta, "", "");
		::Uml::SetChildRole(Domain::meta_Bridge_children, Domain::meta, Bridge::meta, "", "");
		::Uml::SetChildRole(Domain::meta_SharedResource_children, Domain::meta, SharedResource::meta, "", "");
		::Uml::SetChildRole(Domain::meta_Shares_children, Domain::meta, Shares::meta, "", "");
		::Uml::SetChildRole(Domain::meta_Property_children, Domain::meta, Property::meta, "", "");
		::Uml::SetParentRole(Domain::meta_Targets_parent, Domain::meta, Targets::meta, "", "");

		::Uml::SetParentRole(DstEdge::meta_ConnectedComponent_parent, DstEdge::meta, ConnectedComponent::meta, "", "");
		::Uml::SetParentRole(DstEdge::meta_Path_parent, DstEdge::meta, Path::meta, "", "");
		DstEdge::meta_srcDstEdge_end_ = Edge::meta_srcDstEdge;
		DstEdge::meta_dstDstEdge_end_ = GraphVertex::meta_dstDstEdge;

		::Uml::SetParentRole(ECBehavior::meta_ECRequirements_parent, ECBehavior::meta, ECRequirements::meta, "", "");

		::Uml::SetChildRole(ECRequirements::meta_ECRole_children, ECRequirements::meta, ECRole::meta, "", "");
		::Uml::SetChildRole(ECRequirements::meta_ECBehavior_child, ECRequirements::meta, ECBehavior::meta, "", "");

		::Uml::SetParentRole(ECRole::meta_ECRequirements_parent, ECRole::meta, ECRequirements::meta, "", "");

		::Uml::SetAssocRole(Edge::meta_dstSrcEdge, Edge::meta, GraphVertex::meta, "srcSrcEdge");
		GraphVertex::meta_srcSrcEdge_rev = Edge::meta_dstSrcEdge;
		::Uml::SetAssocRole(Edge::meta_srcDstEdge, Edge::meta, GraphVertex::meta, "dstDstEdge");
		GraphVertex::meta_dstDstEdge_rev = Edge::meta_srcDstEdge;
		::Uml::SetAssocRole(Edge::meta_srcPropertyConnector, Edge::meta, Property::meta, "dstPropertyConnector");
		Property::meta_dstPropertyConnector_rev = Edge::meta_srcPropertyConnector;
		::Uml::SetParentRole(Edge::meta_Path_parent, Edge::meta, Path::meta, "", "");

		::Uml::SetParentRole(EdgeProperty::meta_Path_parent, EdgeProperty::meta, Path::meta, "", "");
		EdgeProperty::meta_dstPropertyConnector_end_ = Property::meta_dstPropertyConnector;
		EdgeProperty::meta_srcPropertyConnector_end_ = Edge::meta_srcPropertyConnector;

		::Uml::SetParentRole(Effect::meta_BehaviorModel_parent, Effect::meta, BehaviorModel::meta, "", "");
		Effect::meta_srcEffect_end_ = StateBase::meta_srcEffect;
		Effect::meta_dstEffect_end_ = ActionBase::meta_dstEffect;

		::Uml::SetChildRole(Enum::meta_EnumValue_children, Enum::meta, EnumValue::meta, "", "");

		::Uml::SetParentRole(EnumValue::meta_Enum_parent, EnumValue::meta, Enum::meta, "", "");

		::Uml::SetParentRole(Environment::meta_TopLevelBehavior_parent, Environment::meta, TopLevelBehavior::meta, "", "");

		::Uml::SetAssocRole(Event::meta_referedbyEventRef, Event::meta, EventRef::meta, "ref");
		::Uml::SetAssocRole(Event::meta_referedbyInEventPort, Event::meta, InEventPort::meta, "ref");
		::Uml::SetAssocRole(Event::meta_referedbyOutEventPort, Event::meta, OutEventPort::meta, "ref");
		::Uml::SetParentRole(Event::meta_BenchmarkAnalysis_parent, Event::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(EventRef::meta_dstTimerEventSinkConn, EventRef::meta, TimeProbe::meta, "srcTimerEventSinkConn");
		TimeProbe::meta_srcTimerEventSinkConn_rev = EventRef::meta_dstTimerEventSinkConn;
		::Uml::SetAssocRole(EventRef::meta_ref, EventRef::meta, Event::meta, "referedbyEventRef");
		::Uml::SetParentRole(EventRef::meta_BenchmarkAnalysis_parent, EventRef::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetParentRole(EventSinkDelegate::meta_ComponentAssembly_parent, EventSinkDelegate::meta, ComponentAssembly::meta, "", "");
		EventSinkDelegate::meta_srcEventSinkDelegate_end_ = InEventPort::meta_srcEventSinkDelegate;
		EventSinkDelegate::meta_dstEventSinkDelegate_end_ = InEventPort::meta_dstEventSinkDelegate;

		::Uml::SetParentRole(EventSourceDelegate::meta_ComponentAssembly_parent, EventSourceDelegate::meta, ComponentAssembly::meta, "", "");
		EventSourceDelegate::meta_srcEventSourceDelegate_end_ = OutEventPort::meta_srcEventSourceDelegate;
		EventSourceDelegate::meta_dstEventSourceDelegate_end_ = OutEventPort::meta_dstEventSourceDelegate;

		::Uml::SetAssocRole(Exception::meta_referedbySetException, Exception::meta, SetException::meta, "ref");
		::Uml::SetAssocRole(Exception::meta_referedbyGetException, Exception::meta, GetException::meta, "ref");
		::Uml::SetAssocRole(Exception::meta_referedbyExceptionRef, Exception::meta, ExceptionRef::meta, "ref");
		::Uml::SetChildRole(Exception::meta_Member_children, Exception::meta, Member::meta, "", "");
		::Uml::SetParentRole(Exception::meta_HasOperations_parent, Exception::meta, HasOperations::meta, "", "");
		::Uml::SetParentRole(Exception::meta_Package_parent, Exception::meta, Package::meta, "", "");
		::Uml::SetParentRole(Exception::meta_File_parent, Exception::meta, File::meta, "", "");

		::Uml::SetAssocRole(ExceptionRef::meta_ref, ExceptionRef::meta, Exception::meta, "referedbyExceptionRef");
		::Uml::SetParentRole(ExceptionRef::meta_HasExceptions_parent, ExceptionRef::meta, HasExceptions::meta, "", "");

		::Uml::SetChildRole(ExecutorProject::meta_ImplementationArtifactReference_child, ExecutorProject::meta, ImplementationArtifactReference::meta, "", "");

		::Uml::SetParentRole(ExtResourceConn::meta_Project_parent, ExtResourceConn::meta, Project::meta, "", "");
		ExtResourceConn::meta_dstExtResourceConn_end_ = ComponentLib::meta_dstExtResourceConn;
		ExtResourceConn::meta_srcExtResourceConn_end_ = ExternalResources::meta_srcExtResourceConn;

		::Uml::SetParentRole(ExternalDelegate::meta_ComponentAssembly_parent, ExternalDelegate::meta, ComponentAssembly::meta, "", "");
		ExternalDelegate::meta_srcExternalDelegate_end_ = Port::meta_srcExternalDelegate;
		ExternalDelegate::meta_dstExternalDelegate_end_ = ExternalPortReference::meta_dstExternalDelegate;

		::Uml::SetAssocRole(ExternalPortReference::meta_ref, ExternalPortReference::meta, ExternalPortReferenceType::meta, "referedbyExternalPortReference");
		::Uml::SetAssocRole(ExternalPortReference::meta_dstExternalDelegate, ExternalPortReference::meta, Port::meta, "srcExternalDelegate");
		Port::meta_srcExternalDelegate_rev = ExternalPortReference::meta_dstExternalDelegate;
		::Uml::SetParentRole(ExternalPortReference::meta_ComponentAssembly_parent, ExternalPortReference::meta, ComponentAssembly::meta, "", "");

		::Uml::SetAssocRole(ExternalPortReferenceType::meta_referedbyExternalPortReference, ExternalPortReferenceType::meta, ExternalPortReference::meta, "ref");

		::Uml::SetAssocRole(ExternalResources::meta_ref, ExternalResources::meta, ImplementationArtifact::meta, "referedbyExternalResources");
		::Uml::SetAssocRole(ExternalResources::meta_srcExtResourceConn, ExternalResources::meta, ComponentLib::meta, "dstExtResourceConn");
		ComponentLib::meta_dstExtResourceConn_rev = ExternalResources::meta_srcExtResourceConn;
		::Uml::SetParentRole(ExternalResources::meta_Project_parent, ExternalResources::meta, Project::meta, "", "");

		::Uml::SetParentRole(FacetDelegate::meta_ComponentAssembly_parent, FacetDelegate::meta, ComponentAssembly::meta, "", "");
		FacetDelegate::meta_srcFacetDelegate_end_ = ProvidedRequestPort::meta_srcFacetDelegate;
		FacetDelegate::meta_dstFacetDelegate_end_ = ProvidedRequestPort::meta_dstFacetDelegate;

		::Uml::SetParentRole(FactoryOperation::meta_ComponentFactory_parent, FactoryOperation::meta, ComponentFactory::meta, "", "");
		::Uml::SetParentRole(FactoryOperation::meta_ObjectByValue_parent, FactoryOperation::meta, ObjectByValue::meta, "", "");

		::Uml::SetAssocRole(File::meta_referedbyFileRef, File::meta, FileRef::meta, "ref");
		::Uml::SetChildRole(File::meta_ManagesComponent_children, File::meta, ManagesComponent::meta, "", "");
		::Uml::SetChildRole(File::meta_ComponentRef_children, File::meta, ComponentRef::meta, "", "");
		::Uml::SetChildRole(File::meta_Package_children, File::meta, Package::meta, "", "");
		::Uml::SetChildRole(File::meta_Exception_children, File::meta, Exception::meta, "", "");
		::Uml::SetChildRole(File::meta_FileRef_children, File::meta, FileRef::meta, "", "");
		::Uml::SetChildRole(File::meta_Constant_children, File::meta, Constant::meta, "", "");
		::Uml::SetChildRole(File::meta_NamedType_children, File::meta, NamedType::meta, "", "");
		::Uml::SetParentRole(File::meta_InterfaceDefinitions_parent, File::meta, InterfaceDefinitions::meta, "", "");

		::Uml::SetAssocRole(FileRef::meta_ref, FileRef::meta, File::meta, "referedbyFileRef");
		::Uml::SetParentRole(FileRef::meta_File_parent, FileRef::meta, File::meta, "", "");
		::Uml::SetParentRole(FileRef::meta_StubProject_parent, FileRef::meta, StubProject::meta, "", "");
		::Uml::SetParentRole(FileRef::meta_ServantProject_parent, FileRef::meta, ServantProject::meta, "", "");

		::Uml::SetParentRole(Finish::meta_BehaviorModel_parent, Finish::meta, BehaviorModel::meta, "", "");
		Finish::meta_dstFinish_end_ = StateBase::meta_dstFinish;
		Finish::meta_srcFinish_end_ = BehaviorInputAction::meta_srcFinish;

		::Uml::SetAssocRole(GetException::meta_ref, GetException::meta, Exception::meta, "referedbyGetException");
		::Uml::SetParentRole(GetException::meta_ReadonlyAttribute_parent, GetException::meta, ReadonlyAttribute::meta, "", "");

		::Uml::SetAssocRole(GraphVertex::meta_srcSrcEdge, GraphVertex::meta, Edge::meta, "dstSrcEdge");
		Edge::meta_dstSrcEdge_rev = GraphVertex::meta_srcSrcEdge;
		::Uml::SetAssocRole(GraphVertex::meta_dstDstEdge, GraphVertex::meta, Edge::meta, "srcDstEdge");
		Edge::meta_srcDstEdge_rev = GraphVertex::meta_dstDstEdge;
		::Uml::SetParentRole(GraphVertex::meta_Path_parent, GraphVertex::meta, Path::meta, "", "");

		::Uml::SetChildRole(HasExceptions::meta_ExceptionRef_children, HasExceptions::meta, ExceptionRef::meta, "", "");

		::Uml::SetChildRole(HasOperations::meta_TwowayOperation_children, HasOperations::meta, TwowayOperation::meta, "", "");
		::Uml::SetChildRole(HasOperations::meta_OnewayOperation_children, HasOperations::meta, OnewayOperation::meta, "", "");
		::Uml::SetChildRole(HasOperations::meta_Exception_children, HasOperations::meta, Exception::meta, "", "");
		::Uml::SetChildRole(HasOperations::meta_Constant_children, HasOperations::meta, Constant::meta, "", "");
		::Uml::SetChildRole(HasOperations::meta_NoInheritable_children, HasOperations::meta, NoInheritable::meta, "", "");

		::Uml::SetAssocRole(Implemenation::meta_dstInfoProperty, Implemenation::meta, Property::meta, "srcInfoProperty");
		Property::meta_srcInfoProperty_rev = Implemenation::meta_dstInfoProperty;
		::Uml::SetAssocRole(Implemenation::meta_dstConfigProperty, Implemenation::meta, Property::meta, "srcConfigProperty");
		Property::meta_srcConfigProperty_rev = Implemenation::meta_dstConfigProperty;

		::Uml::SetParentRole(Implementation::meta_PackageContainer_parent, Implementation::meta, PackageContainer::meta, "", "");
		Implementation::meta_dstImplementation_end_ = ComponentPackage::meta_dstImplementation;
		Implementation::meta_srcImplementation_end_ = ComponentImplementationReference::meta_srcImplementation;

		::Uml::SetAssocRole(ImplementationArtifact::meta_referedbyComponentServantArtifact, ImplementationArtifact::meta, ComponentServantArtifact::meta, "ref");
		::Uml::SetAssocRole(ImplementationArtifact::meta_referedbyComponentImplemenationArtifact, ImplementationArtifact::meta, ComponentImplementationArtifact::meta, "ref");
		::Uml::SetAssocRole(ImplementationArtifact::meta_referedbyImplementationArtifactReference, ImplementationArtifact::meta, ImplementationArtifactReference::meta, "ref");
		::Uml::SetAssocRole(ImplementationArtifact::meta_dstArtifactDependsOn, ImplementationArtifact::meta, ImplementationArtifactReference::meta, "srcArtifactDependsOn");
		ImplementationArtifactReference::meta_srcArtifactDependsOn_rev = ImplementationArtifact::meta_dstArtifactDependsOn;
		::Uml::SetAssocRole(ImplementationArtifact::meta_dstArtifactDeployRequirement, ImplementationArtifact::meta, Requirement::meta, "srcArtifactDeployRequirement");
		Requirement::meta_srcArtifactDeployRequirement_rev = ImplementationArtifact::meta_dstArtifactDeployRequirement;
		::Uml::SetAssocRole(ImplementationArtifact::meta_dstArtifactExecParameter, ImplementationArtifact::meta, Property::meta, "srcArtifactExecParameter");
		Property::meta_srcArtifactExecParameter_rev = ImplementationArtifact::meta_dstArtifactExecParameter;
		::Uml::SetAssocRole(ImplementationArtifact::meta_dstArtifactInfoProperty, ImplementationArtifact::meta, Property::meta, "srcArtifactInfoProperty");
		Property::meta_srcArtifactInfoProperty_rev = ImplementationArtifact::meta_dstArtifactInfoProperty;
		::Uml::SetAssocRole(ImplementationArtifact::meta_dstArtifactDependency, ImplementationArtifact::meta, ImplementationArtifact::meta, "srcArtifactDependency");
		ImplementationArtifact::meta_srcArtifactDependency_rev = ImplementationArtifact::meta_dstArtifactDependency;
		::Uml::SetAssocRole(ImplementationArtifact::meta_srcArtifactDependency, ImplementationArtifact::meta, ImplementationArtifact::meta, "dstArtifactDependency");
		ImplementationArtifact::meta_dstArtifactDependency_rev = ImplementationArtifact::meta_srcArtifactDependency;
		::Uml::SetAssocRole(ImplementationArtifact::meta_referedbyExternalResources, ImplementationArtifact::meta, ExternalResources::meta, "ref");
		::Uml::SetParentRole(ImplementationArtifact::meta_ArtifactContainer_parent, ImplementationArtifact::meta, ArtifactContainer::meta, "", "");
		::Uml::SetParentRole(ImplementationArtifact::meta_Project_parent, ImplementationArtifact::meta, Project::meta, "", "");

		::Uml::SetAssocRole(ImplementationArtifactReference::meta_srcMonolithprimaryArtifact, ImplementationArtifactReference::meta, MonolithicImplementationBase::meta, "dstMonolithprimaryArtifact");
		MonolithicImplementationBase::meta_dstMonolithprimaryArtifact_rev = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;
		::Uml::SetAssocRole(ImplementationArtifactReference::meta_ref, ImplementationArtifactReference::meta, ImplementationArtifact::meta, "referedbyImplementationArtifactReference");
		::Uml::SetAssocRole(ImplementationArtifactReference::meta_srcArtifactDependsOn, ImplementationArtifactReference::meta, ImplementationArtifact::meta, "dstArtifactDependsOn");
		ImplementationArtifact::meta_dstArtifactDependsOn_rev = ImplementationArtifactReference::meta_srcArtifactDependsOn;
		::Uml::SetParentRole(ImplementationArtifactReference::meta_ImplementationContainer_parent, ImplementationArtifactReference::meta, ImplementationContainer::meta, "", "");
		::Uml::SetParentRole(ImplementationArtifactReference::meta_ArtifactContainer_parent, ImplementationArtifactReference::meta, ArtifactContainer::meta, "", "");
		::Uml::SetParentRole(ImplementationArtifactReference::meta_StubProject_parent, ImplementationArtifactReference::meta, StubProject::meta, "", "");
		::Uml::SetParentRole(ImplementationArtifactReference::meta_ServantProject_parent, ImplementationArtifactReference::meta, ServantProject::meta, "", "");
		::Uml::SetParentRole(ImplementationArtifactReference::meta_ExecutorProject_parent, ImplementationArtifactReference::meta, ExecutorProject::meta, "", "");

		::Uml::SetChildRole(ImplementationArtifacts::meta_ArtifactContainer_children, ImplementationArtifacts::meta, ArtifactContainer::meta, "", "");
		::Uml::SetParentRole(ImplementationArtifacts::meta_RootFolder_parent, ImplementationArtifacts::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(ImplementationCapability::meta_ComponentImplementationContainer_parent, ImplementationCapability::meta, ComponentImplementationContainer::meta, "", "");
		ImplementationCapability::meta_srcImplementationCapability_end_ = Capability::meta_srcImplementationCapability;
		ImplementationCapability::meta_dstImplementationCapability_end_ = ComponentImplementation::meta_dstImplementationCapability;

		::Uml::SetChildRole(ImplementationContainer::meta_ConfigProperty_children, ImplementationContainer::meta, ConfigProperty::meta, "", "");
		::Uml::SetChildRole(ImplementationContainer::meta_InfoProperty_children, ImplementationContainer::meta, InfoProperty::meta, "", "");
		::Uml::SetChildRole(ImplementationContainer::meta_Property_children, ImplementationContainer::meta, Property::meta, "", "");
		::Uml::SetChildRole(ImplementationContainer::meta_MonolithprimaryArtifact_children, ImplementationContainer::meta, MonolithprimaryArtifact::meta, "", "");
		::Uml::SetChildRole(ImplementationContainer::meta_MonolithDeployRequirement_children, ImplementationContainer::meta, MonolithDeployRequirement::meta, "", "");
		::Uml::SetChildRole(ImplementationContainer::meta_MonolithExecParameter_children, ImplementationContainer::meta, MonolithExecParameter::meta, "", "");
		::Uml::SetChildRole(ImplementationContainer::meta_ImplementationArtifactReference_children, ImplementationContainer::meta, ImplementationArtifactReference::meta, "", "");
		::Uml::SetChildRole(ImplementationContainer::meta_ImplementationRequirement_children, ImplementationContainer::meta, ImplementationRequirement::meta, "", "");

		::Uml::SetAssocRole(ImplementationDependency::meta_srcImplementationDependsOn, ImplementationDependency::meta, ComponentImplementation::meta, "dstImplementationDependsOn");
		ComponentImplementation::meta_dstImplementationDependsOn_rev = ImplementationDependency::meta_srcImplementationDependsOn;
		::Uml::SetParentRole(ImplementationDependency::meta_ComponentImplementationContainer_parent, ImplementationDependency::meta, ComponentImplementationContainer::meta, "", "");

		::Uml::SetParentRole(ImplementationDependsOn::meta_ComponentImplementationContainer_parent, ImplementationDependsOn::meta, ComponentImplementationContainer::meta, "", "");
		ImplementationDependsOn::meta_srcImplementationDependsOn_end_ = ImplementationDependency::meta_srcImplementationDependsOn;
		ImplementationDependsOn::meta_dstImplementationDependsOn_end_ = ComponentImplementation::meta_dstImplementationDependsOn;

		::Uml::SetAssocRole(ImplementationRequirement::meta_srcMonolithDeployRequirement, ImplementationRequirement::meta, MonolithicImplementationBase::meta, "dstMonolithDeployRequirement");
		MonolithicImplementationBase::meta_dstMonolithDeployRequirement_rev = ImplementationRequirement::meta_srcMonolithDeployRequirement;
		::Uml::SetParentRole(ImplementationRequirement::meta_ImplementationContainer_parent, ImplementationRequirement::meta, ImplementationContainer::meta, "", "");

		::Uml::SetParentRole(Implements::meta_ComponentImplementationContainer_parent, Implements::meta, ComponentImplementationContainer::meta, "", "");
		Implements::meta_srcImplements_end_ = ComponentRef::meta_srcImplements;
		Implements::meta_dstImplements_end_ = ComponentImplementation::meta_dstImplements;

		::Uml::SetAssocRole(InEventPort::meta_srcdeliverTo, InEventPort::meta, PublishConnector::meta, "dstdeliverTo");
		PublishConnector::meta_dstdeliverTo_rev = InEventPort::meta_srcdeliverTo;
		::Uml::SetAssocRole(InEventPort::meta_ref, InEventPort::meta, Event::meta, "referedbyInEventPort");
		::Uml::SetAssocRole(InEventPort::meta_dstEventSinkDelegate, InEventPort::meta, InEventPort::meta, "srcEventSinkDelegate");
		InEventPort::meta_srcEventSinkDelegate_rev = InEventPort::meta_dstEventSinkDelegate;
		::Uml::SetAssocRole(InEventPort::meta_srcEventSinkDelegate, InEventPort::meta, InEventPort::meta, "dstEventSinkDelegate");
		InEventPort::meta_dstEventSinkDelegate_rev = InEventPort::meta_srcEventSinkDelegate;
		::Uml::SetAssocRole(InEventPort::meta_srcemit, InEventPort::meta, OutEventPort::meta, "dstemit");
		OutEventPort::meta_dstemit_rev = InEventPort::meta_srcemit;
		::Uml::SetParentRole(InEventPort::meta_ComponentAssembly_parent, InEventPort::meta, ComponentAssembly::meta, "", "");

		::Uml::SetAssocRole(InParameter::meta_ref, InParameter::meta, MemberType::meta, "referedbyInParameter");
		::Uml::SetParentRole(InParameter::meta_OperationBase_parent, InParameter::meta, OperationBase::meta, "", "");

		::Uml::SetParentRole(InfoProperty::meta_ImplementationContainer_parent, InfoProperty::meta, ImplementationContainer::meta, "", "");
		InfoProperty::meta_srcInfoProperty_end_ = Property::meta_srcInfoProperty;
		InfoProperty::meta_dstInfoProperty_end_ = Implemenation::meta_dstInfoProperty;

		::Uml::SetAssocRole(Inheritable::meta_referedbyInherits, Inheritable::meta, Inherits::meta, "ref");
		::Uml::SetChildRole(Inheritable::meta_ReadonlyAttribute_children, Inheritable::meta, ReadonlyAttribute::meta, "", "");
		::Uml::SetChildRole(Inheritable::meta_Inherits_children, Inheritable::meta, Inherits::meta, "", "");

		::Uml::SetAssocRole(Inherits::meta_ref, Inherits::meta, Inheritable::meta, "referedbyInherits");
		::Uml::SetParentRole(Inherits::meta_Inheritable_parent, Inherits::meta, Inheritable::meta, "", "");

		::Uml::SetAssocRole(InoutParameter::meta_ref, InoutParameter::meta, MemberType::meta, "referedbyInoutParameter");
		::Uml::SetParentRole(InoutParameter::meta_TwowayOperation_parent, InoutParameter::meta, TwowayOperation::meta, "", "");

		::Uml::SetParentRole(Input::meta_TopLevelBehavior_parent, Input::meta, TopLevelBehavior::meta, "", "");
		Input::meta_dstInput_end_ = SingleInputBase::meta_dstInput;
		Input::meta_srcInput_end_ = InputAction::meta_srcInput;

		::Uml::SetAssocRole(InputAction::meta_srcInput, InputAction::meta, SingleInputBase::meta, "dstInput");
		SingleInputBase::meta_dstInput_rev = InputAction::meta_srcInput;

		::Uml::SetParentRole(InputEffect::meta_BehaviorModel_parent, InputEffect::meta, BehaviorModel::meta, "", "");
		InputEffect::meta_srcInputEffect_end_ = StateBase::meta_srcInputEffect;
		InputEffect::meta_dstInputEffect_end_ = BehaviorInputAction::meta_dstInputEffect;

		::Uml::SetParentRole(InstanceMapping::meta_DeploymentPlan_parent, InstanceMapping::meta, DeploymentPlan::meta, "", "");
		InstanceMapping::meta_dstInstanceMapping_end_ = CollocationGroup::meta_dstInstanceMapping;
		InstanceMapping::meta_srcInstanceMapping_end_ = NodeReference::meta_srcInstanceMapping;

		::Uml::SetAssocRole(Interconnect::meta_srcInterconnectConnection, Interconnect::meta, Node::meta, "dstInterconnectConnection");
		Node::meta_dstInterconnectConnection_rev = Interconnect::meta_srcInterconnectConnection;
		::Uml::SetAssocRole(Interconnect::meta_dstBridgeConnection, Interconnect::meta, Bridge::meta, "srcBridgeConnection");
		Bridge::meta_srcBridgeConnection_rev = Interconnect::meta_dstBridgeConnection;
		::Uml::SetChildRole(Interconnect::meta_Resource_children, Interconnect::meta, Resource::meta, "", "");
		::Uml::SetParentRole(Interconnect::meta_Domain_parent, Interconnect::meta, Domain::meta, "", "");

		::Uml::SetParentRole(InterconnectConnection::meta_Domain_parent, InterconnectConnection::meta, Domain::meta, "", "");
		InterconnectConnection::meta_dstInterconnectConnection_end_ = Node::meta_dstInterconnectConnection;
		InterconnectConnection::meta_srcInterconnectConnection_end_ = Interconnect::meta_srcInterconnectConnection;

		::Uml::SetChildRole(InterfaceDefinitions::meta_File_children, InterfaceDefinitions::meta, File::meta, "", "");
		::Uml::SetParentRole(InterfaceDefinitions::meta_RootFolder_parent, InterfaceDefinitions::meta, RootFolder::meta, "", "");

		::Uml::SetAssocRole(InvokePortBase::meta_srcinvoke, InvokePortBase::meta, RequiredRequestPort::meta, "dstinvoke");
		RequiredRequestPort::meta_dstinvoke_rev = InvokePortBase::meta_srcinvoke;

		::Uml::SetAssocRole(Label::meta_srcLabelConnection, Label::meta, Member::meta, "dstLabelConnection");
		Member::meta_dstLabelConnection_rev = Label::meta_srcLabelConnection;
		::Uml::SetParentRole(Label::meta_SwitchedAggregate_parent, Label::meta, SwitchedAggregate::meta, "", "");

		::Uml::SetParentRole(LabelConnection::meta_SwitchedAggregate_parent, LabelConnection::meta, SwitchedAggregate::meta, "", "");
		LabelConnection::meta_dstLabelConnection_end_ = Member::meta_dstLabelConnection;
		LabelConnection::meta_srcLabelConnection_end_ = Label::meta_srcLabelConnection;

		::Uml::SetAssocRole(LookupKey::meta_ref, LookupKey::meta, ValueObject::meta, "referedbyLookupKey");
		::Uml::SetParentRole(LookupKey::meta_ComponentFactory_parent, LookupKey::meta, ComponentFactory::meta, "", "");

		::Uml::SetParentRole(LookupOperation::meta_ComponentFactory_parent, LookupOperation::meta, ComponentFactory::meta, "", "");

		::Uml::SetAssocRole(LoopState::meta_dstLoopTransition, LoopState::meta, ActionBase::meta, "srcLoopTransition");
		ActionBase::meta_srcLoopTransition_rev = LoopState::meta_dstLoopTransition;

		::Uml::SetParentRole(LoopTransition::meta_BehaviorModel_parent, LoopTransition::meta, BehaviorModel::meta, "", "");
		LoopTransition::meta_dstLoopTransition_end_ = LoopState::meta_dstLoopTransition;
		LoopTransition::meta_srcLoopTransition_end_ = ActionBase::meta_srcLoopTransition;

		::Uml::SetChildRole(MPC::meta_Project_children, MPC::meta, Project::meta, "", "");
		::Uml::SetChildRole(MPC::meta_Workspaces_children, MPC::meta, Workspaces::meta, "", "");
		::Uml::SetParentRole(MPC::meta_ComponentBuild_parent, MPC::meta, ComponentBuild::meta, "", "");

		::Uml::SetParentRole(MakeMemberPrivate::meta_ObjectByValue_parent, MakeMemberPrivate::meta, ObjectByValue::meta, "", "");
		MakeMemberPrivate::meta_dstMakeMemberPrivate_end_ = Member::meta_dstMakeMemberPrivate;
		MakeMemberPrivate::meta_srcMakeMemberPrivate_end_ = PrivateFlag::meta_srcMakeMemberPrivate;

		::Uml::SetAssocRole(Manageable::meta_srcManagesComponent, Manageable::meta, ComponentFactory::meta, "dstManagesComponent");
		ComponentFactory::meta_dstManagesComponent_rev = Manageable::meta_srcManagesComponent;

		::Uml::SetParentRole(ManagesComponent::meta_File_parent, ManagesComponent::meta, File::meta, "", "");
		::Uml::SetParentRole(ManagesComponent::meta_Package_parent, ManagesComponent::meta, Package::meta, "", "");
		ManagesComponent::meta_dstManagesComponent_end_ = ComponentFactory::meta_dstManagesComponent;
		ManagesComponent::meta_srcManagesComponent_end_ = Manageable::meta_srcManagesComponent;

		::Uml::SetAssocRole(Member::meta_dstMakeMemberPrivate, Member::meta, PrivateFlag::meta, "srcMakeMemberPrivate");
		PrivateFlag::meta_srcMakeMemberPrivate_rev = Member::meta_dstMakeMemberPrivate;
		::Uml::SetAssocRole(Member::meta_dstLabelConnection, Member::meta, Label::meta, "srcLabelConnection");
		Label::meta_srcLabelConnection_rev = Member::meta_dstLabelConnection;
		::Uml::SetAssocRole(Member::meta_ref, Member::meta, MemberType::meta, "referedbyMember");
		::Uml::SetParentRole(Member::meta_ObjectByValue_parent, Member::meta, ObjectByValue::meta, "", "");
		::Uml::SetParentRole(Member::meta_Aggregate_parent, Member::meta, Aggregate::meta, "", "");
		::Uml::SetParentRole(Member::meta_SwitchedAggregate_parent, Member::meta, SwitchedAggregate::meta, "", "");
		::Uml::SetParentRole(Member::meta_Exception_parent, Member::meta, Exception::meta, "", "");

		::Uml::SetAssocRole(MemberType::meta_referedbyDataType, MemberType::meta, DataType::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyInParameter, MemberType::meta, InParameter::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyInoutParameter, MemberType::meta, InoutParameter::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyOutParameter, MemberType::meta, OutParameter::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyReturnType, MemberType::meta, ReturnType::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyParameterType, MemberType::meta, ParameterType::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyAttributeMember, MemberType::meta, AttributeMember::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyAlias, MemberType::meta, Alias::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyBoxed, MemberType::meta, Boxed::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyCollection, MemberType::meta, Collection::meta, "ref");
		::Uml::SetAssocRole(MemberType::meta_referedbyMember, MemberType::meta, Member::meta, "ref");

		::Uml::SetParentRole(MetricConnection::meta_BenchmarkAnalysis_parent, MetricConnection::meta, BenchmarkAnalysis::meta, "", "");
		MetricConnection::meta_dstMetricConnection_end_ = OperationRef::meta_dstMetricConnection;
		MetricConnection::meta_srcMetricConnection_end_ = MetricsBase::meta_srcMetricConnection;

		::Uml::SetAssocRole(MetricsBase::meta_srcMetricConnection, MetricsBase::meta, OperationRef::meta, "dstMetricConnection");
		OperationRef::meta_dstMetricConnection_rev = MetricsBase::meta_srcMetricConnection;
		::Uml::SetAssocRole(MetricsBase::meta_dstWorkloadCharacteristics, MetricsBase::meta, TaskSet::meta, "srcWorkloadCharacteristics");
		TaskSet::meta_srcWorkloadCharacteristics_rev = MetricsBase::meta_dstWorkloadCharacteristics;
		::Uml::SetAssocRole(MetricsBase::meta_srcBenchmarkCharacteristics, MetricsBase::meta, BenchmarkType::meta, "dstBenchmarkCharacteristics");
		BenchmarkType::meta_dstBenchmarkCharacteristics_rev = MetricsBase::meta_srcBenchmarkCharacteristics;
		::Uml::SetChildRole(MetricsBase::meta_DataAnalysisBase_children, MetricsBase::meta, DataAnalysisBase::meta, "", "");
		::Uml::SetParentRole(MetricsBase::meta_BenchmarkAnalysis_parent, MetricsBase::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetParentRole(MonolithDeployRequirement::meta_ImplementationContainer_parent, MonolithDeployRequirement::meta, ImplementationContainer::meta, "", "");
		MonolithDeployRequirement::meta_srcMonolithDeployRequirement_end_ = ImplementationRequirement::meta_srcMonolithDeployRequirement;
		MonolithDeployRequirement::meta_dstMonolithDeployRequirement_end_ = MonolithicImplementationBase::meta_dstMonolithDeployRequirement;

		::Uml::SetParentRole(MonolithExecParameter::meta_ImplementationContainer_parent, MonolithExecParameter::meta, ImplementationContainer::meta, "", "");
		MonolithExecParameter::meta_srcMonolithExecParameter_end_ = Property::meta_srcMonolithExecParameter;
		MonolithExecParameter::meta_dstMonolithExecParameter_end_ = MonolithicImplementationBase::meta_dstMonolithExecParameter;

		::Uml::SetAssocRole(MonolithicImplementationBase::meta_dstMonolithExecParameter, MonolithicImplementationBase::meta, Property::meta, "srcMonolithExecParameter");
		Property::meta_srcMonolithExecParameter_rev = MonolithicImplementationBase::meta_dstMonolithExecParameter;
		::Uml::SetAssocRole(MonolithicImplementationBase::meta_dstMonolithDeployRequirement, MonolithicImplementationBase::meta, ImplementationRequirement::meta, "srcMonolithDeployRequirement");
		ImplementationRequirement::meta_srcMonolithDeployRequirement_rev = MonolithicImplementationBase::meta_dstMonolithDeployRequirement;
		::Uml::SetAssocRole(MonolithicImplementationBase::meta_dstMonolithprimaryArtifact, MonolithicImplementationBase::meta, ImplementationArtifactReference::meta, "srcMonolithprimaryArtifact");
		ImplementationArtifactReference::meta_srcMonolithprimaryArtifact_rev = MonolithicImplementationBase::meta_dstMonolithprimaryArtifact;

		::Uml::SetParentRole(MonolithprimaryArtifact::meta_ImplementationContainer_parent, MonolithprimaryArtifact::meta, ImplementationContainer::meta, "", "");
		MonolithprimaryArtifact::meta_srcMonolithprimaryArtifact_end_ = ImplementationArtifactReference::meta_srcMonolithprimaryArtifact;
		MonolithprimaryArtifact::meta_dstMonolithprimaryArtifact_end_ = MonolithicImplementationBase::meta_dstMonolithprimaryArtifact;

		::Uml::SetParentRole(MultiInput::meta_TopLevelBehavior_parent, MultiInput::meta, TopLevelBehavior::meta, "", "");
		MultiInput::meta_dstMultiInput_end_ = MultiInputBase::meta_dstMultiInput;
		MultiInput::meta_srcMultiInput_end_ = MultiInputAction::meta_srcMultiInput;

		::Uml::SetAssocRole(MultiInputAction::meta_srcMultiInput, MultiInputAction::meta, MultiInputBase::meta, "dstMultiInput");
		MultiInputBase::meta_dstMultiInput_rev = MultiInputAction::meta_srcMultiInput;

		::Uml::SetAssocRole(MultiInputBase::meta_dstMultiInput, MultiInputBase::meta, MultiInputAction::meta, "srcMultiInput");
		MultiInputAction::meta_srcMultiInput_rev = MultiInputBase::meta_dstMultiInput;

		::Uml::SetParentRole(MultipleServiceRequests::meta_ServiceProvider_parent, MultipleServiceRequests::meta, ServiceProvider::meta, "", "");

		::Uml::SetParentRole(NamedType::meta_File_parent, NamedType::meta, File::meta, "", "");
		::Uml::SetParentRole(NamedType::meta_Package_parent, NamedType::meta, Package::meta, "", "");

		::Uml::SetParentRole(NoInheritable::meta_HasOperations_parent, NoInheritable::meta, HasOperations::meta, "", "");

		::Uml::SetAssocRole(Node::meta_referedbyNodeReference, Node::meta, NodeReference::meta, "ref");
		::Uml::SetAssocRole(Node::meta_dstInterconnectConnection, Node::meta, Interconnect::meta, "srcInterconnectConnection");
		Interconnect::meta_srcInterconnectConnection_rev = Node::meta_dstInterconnectConnection;
		::Uml::SetAssocRole(Node::meta_dstShares, Node::meta, SharedResource::meta, "srcShares");
		SharedResource::meta_srcShares_rev = Node::meta_dstShares;
		::Uml::SetChildRole(Node::meta_Resource_children, Node::meta, Resource::meta, "", "");
		::Uml::SetParentRole(Node::meta_Domain_parent, Node::meta, Domain::meta, "", "");

		::Uml::SetAssocRole(NodeReference::meta_srcInstanceMapping, NodeReference::meta, CollocationGroup::meta, "dstInstanceMapping");
		CollocationGroup::meta_dstInstanceMapping_rev = NodeReference::meta_srcInstanceMapping;
		::Uml::SetAssocRole(NodeReference::meta_ref, NodeReference::meta, Node::meta, "referedbyNodeReference");
		::Uml::SetParentRole(NodeReference::meta_DeploymentPlan_parent, NodeReference::meta, DeploymentPlan::meta, "", "");

		::Uml::SetAssocRole(Object::meta_referedbySupports, Object::meta, Supports::meta, "ref");

		::Uml::SetChildRole(ObjectByValue::meta_PrivateFlag_children, ObjectByValue::meta, PrivateFlag::meta, "", "");
		::Uml::SetChildRole(ObjectByValue::meta_FactoryOperation_children, ObjectByValue::meta, FactoryOperation::meta, "", "");
		::Uml::SetChildRole(ObjectByValue::meta_MakeMemberPrivate_children, ObjectByValue::meta, MakeMemberPrivate::meta, "", "");
		::Uml::SetChildRole(ObjectByValue::meta_Member_children, ObjectByValue::meta, Member::meta, "", "");

		::Uml::SetParentRole(OnewayOperation::meta_HasOperations_parent, OnewayOperation::meta, HasOperations::meta, "", "");

		::Uml::SetAssocRole(OperationBase::meta_referedbyOperationRef, OperationBase::meta, OperationRef::meta, "ref");
		::Uml::SetChildRole(OperationBase::meta_InParameter_children, OperationBase::meta, InParameter::meta, "", "");
		::Uml::SetParentRole(OperationBase::meta_BenchmarkAnalysis_parent, OperationBase::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(OperationRef::meta_dstTimerConnection, OperationRef::meta, TimeProbe::meta, "srcTimerConnection");
		TimeProbe::meta_srcTimerConnection_rev = OperationRef::meta_dstTimerConnection;
		::Uml::SetAssocRole(OperationRef::meta_dstMetricConnection, OperationRef::meta, MetricsBase::meta, "srcMetricConnection");
		MetricsBase::meta_srcMetricConnection_rev = OperationRef::meta_dstMetricConnection;
		::Uml::SetAssocRole(OperationRef::meta_dstComponentOperation, OperationRef::meta, CompRef::meta, "srcComponentOperation");
		CompRef::meta_srcComponentOperation_rev = OperationRef::meta_dstComponentOperation;
		::Uml::SetAssocRole(OperationRef::meta_dstWorkLoadOperationConnection, OperationRef::meta, Task::meta, "srcWorkLoadOperationConnection");
		Task::meta_srcWorkLoadOperationConnection_rev = OperationRef::meta_dstWorkLoadOperationConnection;
		::Uml::SetAssocRole(OperationRef::meta_ref, OperationRef::meta, OperationBase::meta, "referedbyOperationRef");
		::Uml::SetParentRole(OperationRef::meta_BenchmarkAnalysis_parent, OperationRef::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(OutEventPort::meta_dstpublish, OutEventPort::meta, PublishConnector::meta, "srcpublish");
		PublishConnector::meta_srcpublish_rev = OutEventPort::meta_dstpublish;
		::Uml::SetAssocRole(OutEventPort::meta_dstemit, OutEventPort::meta, InEventPort::meta, "srcemit");
		InEventPort::meta_srcemit_rev = OutEventPort::meta_dstemit;
		::Uml::SetAssocRole(OutEventPort::meta_ref, OutEventPort::meta, Event::meta, "referedbyOutEventPort");
		::Uml::SetAssocRole(OutEventPort::meta_dstEventSourceDelegate, OutEventPort::meta, OutEventPort::meta, "srcEventSourceDelegate");
		OutEventPort::meta_srcEventSourceDelegate_rev = OutEventPort::meta_dstEventSourceDelegate;
		::Uml::SetAssocRole(OutEventPort::meta_srcEventSourceDelegate, OutEventPort::meta, OutEventPort::meta, "dstEventSourceDelegate");
		OutEventPort::meta_dstEventSourceDelegate_rev = OutEventPort::meta_srcEventSourceDelegate;
		::Uml::SetParentRole(OutEventPort::meta_ComponentAssembly_parent, OutEventPort::meta, ComponentAssembly::meta, "", "");

		::Uml::SetAssocRole(OutParameter::meta_ref, OutParameter::meta, MemberType::meta, "referedbyOutParameter");
		::Uml::SetParentRole(OutParameter::meta_TwowayOperation_parent, OutParameter::meta, TwowayOperation::meta, "", "");

		::Uml::SetChildRole(Package::meta_ComponentRef_children, Package::meta, ComponentRef::meta, "", "");
		::Uml::SetChildRole(Package::meta_NamedType_children, Package::meta, NamedType::meta, "", "");
		::Uml::SetChildRole(Package::meta_ManagesComponent_children, Package::meta, ManagesComponent::meta, "", "");
		::Uml::SetChildRole(Package::meta_Package_children, Package::meta, Package::meta, "", "");
		::Uml::SetChildRole(Package::meta_Exception_children, Package::meta, Exception::meta, "", "");
		::Uml::SetChildRole(Package::meta_Constant_children, Package::meta, Constant::meta, "", "");
		::Uml::SetParentRole(Package::meta_Package_parent, Package::meta, Package::meta, "", "");
		::Uml::SetParentRole(Package::meta_File_parent, Package::meta, File::meta, "", "");

		::Uml::SetParentRole(PackageConfBasePackage::meta_PackageConfigurationContainer_parent, PackageConfBasePackage::meta, PackageConfigurationContainer::meta, "", "");
		PackageConfBasePackage::meta_srcPackageConfBasePackage_end_ = ComponentPackage::meta_srcPackageConfBasePackage;
		PackageConfBasePackage::meta_dstPackageConfBasePackage_end_ = PackageConfiguration::meta_dstPackageConfBasePackage;

		::Uml::SetParentRole(PackageConfConfigProperty::meta_PackageConfigurationContainer_parent, PackageConfConfigProperty::meta, PackageConfigurationContainer::meta, "", "");
		PackageConfConfigProperty::meta_srcPackageConfConfigProperty_end_ = Property::meta_srcPackageConfConfigProperty;
		PackageConfConfigProperty::meta_dstPackageConfConfigProperty_end_ = PackageConfiguration::meta_dstPackageConfConfigProperty;

		::Uml::SetParentRole(PackageConfReference::meta_PackageConfigurationContainer_parent, PackageConfReference::meta, PackageConfigurationContainer::meta, "", "");
		PackageConfReference::meta_srcPackageConfReference_end_ = ComponentPackageReference::meta_srcPackageConfReference;
		PackageConfReference::meta_dstPackageConfReference_end_ = PackageConfiguration::meta_dstPackageConfReference;

		::Uml::SetParentRole(PackageConfSelectRequirement::meta_PackageConfigurationContainer_parent, PackageConfSelectRequirement::meta, PackageConfigurationContainer::meta, "", "");
		PackageConfSelectRequirement::meta_srcPackageConfSelectRequirement_end_ = Requirement::meta_srcPackageConfSelectRequirement;
		PackageConfSelectRequirement::meta_dstPackageConfSelectRequirement_end_ = PackageConfiguration::meta_dstPackageConfSelectRequirement;

		::Uml::SetParentRole(PackageConfSpecializedConfig::meta_PackageConfigurationContainer_parent, PackageConfSpecializedConfig::meta, PackageConfigurationContainer::meta, "", "");
		PackageConfSpecializedConfig::meta_dstPackageConfSpecializedConfig_end_ = PackageConfiguration::meta_dstPackageConfSpecializedConfig;
		PackageConfSpecializedConfig::meta_srcPackageConfSpecializedConfig_end_ = PackageConfigurationReference::meta_srcPackageConfSpecializedConfig;

		::Uml::SetParentRole(PackageConfigProperty::meta_PackageContainer_parent, PackageConfigProperty::meta, PackageContainer::meta, "", "");
		PackageConfigProperty::meta_srcPackageConfigProperty_end_ = Property::meta_srcPackageConfigProperty;
		PackageConfigProperty::meta_dstPackageConfigProperty_end_ = ComponentPackage::meta_dstPackageConfigProperty;

		::Uml::SetAssocRole(PackageConfiguration::meta_dstPackageConfSpecializedConfig, PackageConfiguration::meta, PackageConfigurationReference::meta, "srcPackageConfSpecializedConfig");
		PackageConfigurationReference::meta_srcPackageConfSpecializedConfig_rev = PackageConfiguration::meta_dstPackageConfSpecializedConfig;
		::Uml::SetAssocRole(PackageConfiguration::meta_referedbyPackageConfigurationReference, PackageConfiguration::meta, PackageConfigurationReference::meta, "ref");
		::Uml::SetAssocRole(PackageConfiguration::meta_dstPackageConfBasePackage, PackageConfiguration::meta, ComponentPackage::meta, "srcPackageConfBasePackage");
		ComponentPackage::meta_srcPackageConfBasePackage_rev = PackageConfiguration::meta_dstPackageConfBasePackage;
		::Uml::SetAssocRole(PackageConfiguration::meta_dstPackageConfReference, PackageConfiguration::meta, ComponentPackageReference::meta, "srcPackageConfReference");
		ComponentPackageReference::meta_srcPackageConfReference_rev = PackageConfiguration::meta_dstPackageConfReference;
		::Uml::SetAssocRole(PackageConfiguration::meta_dstPackageConfSelectRequirement, PackageConfiguration::meta, Requirement::meta, "srcPackageConfSelectRequirement");
		Requirement::meta_srcPackageConfSelectRequirement_rev = PackageConfiguration::meta_dstPackageConfSelectRequirement;
		::Uml::SetAssocRole(PackageConfiguration::meta_dstPackageConfConfigProperty, PackageConfiguration::meta, Property::meta, "srcPackageConfConfigProperty");
		Property::meta_srcPackageConfConfigProperty_rev = PackageConfiguration::meta_dstPackageConfConfigProperty;
		::Uml::SetParentRole(PackageConfiguration::meta_PackageConfigurationContainer_parent, PackageConfiguration::meta, PackageConfigurationContainer::meta, "", "");

		::Uml::SetChildRole(PackageConfigurationContainer::meta_PackageConfReference_child, PackageConfigurationContainer::meta, PackageConfReference::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_PackageConfBasePackage_child, PackageConfigurationContainer::meta, PackageConfBasePackage::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_ComponentPackage_child, PackageConfigurationContainer::meta, ComponentPackage::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_ComponentPackageReference_child, PackageConfigurationContainer::meta, ComponentPackageReference::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_PackageConfConfigProperty_children, PackageConfigurationContainer::meta, PackageConfConfigProperty::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_PackageConfSelectRequirement_children, PackageConfigurationContainer::meta, PackageConfSelectRequirement::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_Requirement_children, PackageConfigurationContainer::meta, Requirement::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_Property_children, PackageConfigurationContainer::meta, Property::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_PackageConfSpecializedConfig_child, PackageConfigurationContainer::meta, PackageConfSpecializedConfig::meta, "", "");
		::Uml::SetChildRole(PackageConfigurationContainer::meta_PackageConfiguration_children, PackageConfigurationContainer::meta, PackageConfiguration::meta, "", "");
		::Uml::SetParentRole(PackageConfigurationContainer::meta_PackageConfigurations_parent, PackageConfigurationContainer::meta, PackageConfigurations::meta, "", "");

		::Uml::SetAssocRole(PackageConfigurationReference::meta_srcPackageConfSpecializedConfig, PackageConfigurationReference::meta, PackageConfiguration::meta, "dstPackageConfSpecializedConfig");
		PackageConfiguration::meta_dstPackageConfSpecializedConfig_rev = PackageConfigurationReference::meta_srcPackageConfSpecializedConfig;
		::Uml::SetAssocRole(PackageConfigurationReference::meta_ref, PackageConfigurationReference::meta, PackageConfiguration::meta, "referedbyPackageConfigurationReference");
		::Uml::SetAssocRole(PackageConfigurationReference::meta_srcpackage, PackageConfigurationReference::meta, TopLevelPackage::meta, "dstpackage");
		TopLevelPackage::meta_dstpackage_rev = PackageConfigurationReference::meta_srcpackage;
		::Uml::SetParentRole(PackageConfigurationReference::meta_TopLevelPackageContainer_parent, PackageConfigurationReference::meta, TopLevelPackageContainer::meta, "", "");

		::Uml::SetChildRole(PackageConfigurations::meta_PackageConfigurationContainer_children, PackageConfigurations::meta, PackageConfigurationContainer::meta, "", "");
		::Uml::SetParentRole(PackageConfigurations::meta_RootFolder_parent, PackageConfigurations::meta, RootFolder::meta, "", "");

		::Uml::SetChildRole(PackageContainer::meta_Implementation_children, PackageContainer::meta, Implementation::meta, "", "");
		::Uml::SetChildRole(PackageContainer::meta_PackageInterface_child, PackageContainer::meta, PackageInterface::meta, "", "");
		::Uml::SetChildRole(PackageContainer::meta_ComponentImplementationReference_children, PackageContainer::meta, ComponentImplementationReference::meta, "", "");
		::Uml::SetChildRole(PackageContainer::meta_ComponentRef_child, PackageContainer::meta, ComponentRef::meta, "", "");
		::Uml::SetChildRole(PackageContainer::meta_PackageConfigProperty_children, PackageContainer::meta, PackageConfigProperty::meta, "", "");
		::Uml::SetChildRole(PackageContainer::meta_Property_children, PackageContainer::meta, Property::meta, "", "");
		::Uml::SetChildRole(PackageContainer::meta_PackageInfoProperty_children, PackageContainer::meta, PackageInfoProperty::meta, "", "");
		::Uml::SetChildRole(PackageContainer::meta_ComponentPackage_child, PackageContainer::meta, ComponentPackage::meta, "", "");
		::Uml::SetParentRole(PackageContainer::meta_ComponentPackages_parent, PackageContainer::meta, ComponentPackages::meta, "", "");

		::Uml::SetParentRole(PackageInfoProperty::meta_PackageContainer_parent, PackageInfoProperty::meta, PackageContainer::meta, "", "");
		PackageInfoProperty::meta_srcPackageInfoProperty_end_ = Property::meta_srcPackageInfoProperty;
		PackageInfoProperty::meta_dstPackageInfoProperty_end_ = ComponentPackage::meta_dstPackageInfoProperty;

		::Uml::SetParentRole(PackageInterface::meta_PackageContainer_parent, PackageInterface::meta, PackageContainer::meta, "", "");
		PackageInterface::meta_srcPackageInterface_end_ = ComponentRef::meta_srcPackageInterface;
		PackageInterface::meta_dstPackageInterface_end_ = ComponentPackage::meta_dstPackageInterface;

		::Uml::SetAssocRole(ParameterType::meta_ref, ParameterType::meta, MemberType::meta, "referedbyParameterType");

		::Uml::SetAssocRole(Path::meta_referedbyPathReference, Path::meta, PathReference::meta, "ref");
		::Uml::SetAssocRole(Path::meta_dstPathProperty, Path::meta, Property::meta, "srcPathProperty");
		Property::meta_srcPathProperty_rev = Path::meta_dstPathProperty;
		::Uml::SetChildRole(Path::meta_ComponentRef_children, Path::meta, ComponentRef::meta, "", "");
		::Uml::SetChildRole(Path::meta_DstEdge_children, Path::meta, DstEdge::meta, "", "");
		::Uml::SetChildRole(Path::meta_SrcEdge_children, Path::meta, SrcEdge::meta, "", "");
		::Uml::SetChildRole(Path::meta_EdgeProperty_children, Path::meta, EdgeProperty::meta, "", "");
		::Uml::SetChildRole(Path::meta_Edge_children, Path::meta, Edge::meta, "", "");
		::Uml::SetChildRole(Path::meta_Property_children, Path::meta, Property::meta, "", "");
		::Uml::SetChildRole(Path::meta_GraphVertex_children, Path::meta, GraphVertex::meta, "", "");
		::Uml::SetParentRole(Path::meta_Paths_parent, Path::meta, Paths::meta, "", "");

		::Uml::SetChildRole(PathDiagrams::meta_Paths_children, PathDiagrams::meta, Paths::meta, "", "");
		::Uml::SetParentRole(PathDiagrams::meta_RootFolder_parent, PathDiagrams::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(PathProperty::meta_Paths_parent, PathProperty::meta, Paths::meta, "", "");
		PathProperty::meta_srcPathProperty_end_ = Property::meta_srcPathProperty;
		PathProperty::meta_dstPathProperty_end_ = Path::meta_dstPathProperty;

		::Uml::SetAssocRole(PathReference::meta_srcCriticalPath, PathReference::meta, ComponentAssembly::meta, "dstCriticalPath");
		ComponentAssembly::meta_dstCriticalPath_rev = PathReference::meta_srcCriticalPath;
		::Uml::SetAssocRole(PathReference::meta_ref, PathReference::meta, Path::meta, "referedbyPathReference");
		::Uml::SetParentRole(PathReference::meta_ComponentImplementationContainer_parent, PathReference::meta, ComponentImplementationContainer::meta, "", "");

		::Uml::SetChildRole(Paths::meta_PathProperty_children, Paths::meta, PathProperty::meta, "", "");
		::Uml::SetChildRole(Paths::meta_Path_children, Paths::meta, Path::meta, "", "");
		::Uml::SetChildRole(Paths::meta_Property_children, Paths::meta, Property::meta, "", "");
		::Uml::SetParentRole(Paths::meta_PathDiagrams_parent, Paths::meta, PathDiagrams::meta, "", "");

		::Uml::SetParentRole(PeriodicEvent::meta_TopLevelBehavior_parent, PeriodicEvent::meta, TopLevelBehavior::meta, "", "");

		::Uml::SetAssocRole(Port::meta_srcExternalDelegate, Port::meta, ExternalPortReference::meta, "dstExternalDelegate");
		ExternalPortReference::meta_dstExternalDelegate_rev = Port::meta_srcExternalDelegate;
		::Uml::SetParentRole(Port::meta_ConnectedComponent_parent, Port::meta, ConnectedComponent::meta, "", "");
		::Uml::SetParentRole(Port::meta_Component_parent, Port::meta, Component::meta, "", "");

		::Uml::SetAssocRole(PredefinedType::meta_referedbyVariable, PredefinedType::meta, Variable::meta, "ref");
		::Uml::SetParentRole(PredefinedType::meta_PredefinedTypes_parent, PredefinedType::meta, PredefinedTypes::meta, "", "");

		::Uml::SetChildRole(PredefinedTypes::meta_Collection_children, PredefinedTypes::meta, Collection::meta, "", "");
		::Uml::SetChildRole(PredefinedTypes::meta_PredefinedType_children, PredefinedTypes::meta, PredefinedType::meta, "", "");
		::Uml::SetParentRole(PredefinedTypes::meta_RootFolder_parent, PredefinedTypes::meta, RootFolder::meta, "", "");

		::Uml::SetAssocRole(PrivateFlag::meta_srcMakeMemberPrivate, PrivateFlag::meta, Member::meta, "dstMakeMemberPrivate");
		Member::meta_dstMakeMemberPrivate_rev = PrivateFlag::meta_srcMakeMemberPrivate;
		::Uml::SetParentRole(PrivateFlag::meta_ObjectByValue_parent, PrivateFlag::meta, ObjectByValue::meta, "", "");

		::Uml::SetAssocRole(Project::meta_setWorkspace, Project::meta, Workspaces::meta, "members");
		::Uml::SetChildRole(Project::meta_ExtResourceConn_children, Project::meta, ExtResourceConn::meta, "", "");
		::Uml::SetChildRole(Project::meta_ExternalResources_children, Project::meta, ExternalResources::meta, "", "");
		::Uml::SetChildRole(Project::meta_ComponentLib_children, Project::meta, ComponentLib::meta, "", "");
		::Uml::SetChildRole(Project::meta_ImplementationArtifact_children, Project::meta, ImplementationArtifact::meta, "", "");
		::Uml::SetParentRole(Project::meta_MPC_parent, Project::meta, MPC::meta, "", "");

		::Uml::SetAssocRole(Property::meta_srcMonolithExecParameter, Property::meta, MonolithicImplementationBase::meta, "dstMonolithExecParameter");
		MonolithicImplementationBase::meta_dstMonolithExecParameter_rev = Property::meta_srcMonolithExecParameter;
		::Uml::SetAssocRole(Property::meta_srcInfoProperty, Property::meta, Implemenation::meta, "dstInfoProperty");
		Implemenation::meta_dstInfoProperty_rev = Property::meta_srcInfoProperty;
		::Uml::SetAssocRole(Property::meta_srcConfigProperty, Property::meta, Implemenation::meta, "dstConfigProperty");
		Implemenation::meta_dstConfigProperty_rev = Property::meta_srcConfigProperty;
		::Uml::SetAssocRole(Property::meta_srcPathProperty, Property::meta, Path::meta, "dstPathProperty");
		Path::meta_dstPathProperty_rev = Property::meta_srcPathProperty;
		::Uml::SetAssocRole(Property::meta_dstPropertyConnector, Property::meta, Edge::meta, "srcPropertyConnector");
		Edge::meta_srcPropertyConnector_rev = Property::meta_dstPropertyConnector;
		::Uml::SetAssocRole(Property::meta_srcAttributeMappingValue, Property::meta, AttributeMapping::meta, "dstAttributeMappingValue");
		AttributeMapping::meta_dstAttributeMappingValue_rev = Property::meta_srcAttributeMappingValue;
		::Uml::SetAssocRole(Property::meta_srcPackageConfConfigProperty, Property::meta, PackageConfiguration::meta, "dstPackageConfConfigProperty");
		PackageConfiguration::meta_dstPackageConfConfigProperty_rev = Property::meta_srcPackageConfConfigProperty;
		::Uml::SetAssocRole(Property::meta_srcArtifactExecParameter, Property::meta, ImplementationArtifact::meta, "dstArtifactExecParameter");
		ImplementationArtifact::meta_dstArtifactExecParameter_rev = Property::meta_srcArtifactExecParameter;
		::Uml::SetAssocRole(Property::meta_srcArtifactInfoProperty, Property::meta, ImplementationArtifact::meta, "dstArtifactInfoProperty");
		ImplementationArtifact::meta_dstArtifactInfoProperty_rev = Property::meta_srcArtifactInfoProperty;
		::Uml::SetAssocRole(Property::meta_srcPackageConfigProperty, Property::meta, ComponentPackage::meta, "dstPackageConfigProperty");
		ComponentPackage::meta_dstPackageConfigProperty_rev = Property::meta_srcPackageConfigProperty;
		::Uml::SetAssocRole(Property::meta_srcPackageInfoProperty, Property::meta, ComponentPackage::meta, "dstPackageInfoProperty");
		ComponentPackage::meta_dstPackageInfoProperty_rev = Property::meta_srcPackageInfoProperty;
		::Uml::SetAssocRole(Property::meta_srcComponentConfigProperty, Property::meta, ComponentRef::meta, "dstComponentConfigProperty");
		ComponentRef::meta_dstComponentConfigProperty_rev = Property::meta_srcComponentConfigProperty;
		::Uml::SetAssocRole(Property::meta_srcComponentInfoProperty, Property::meta, ComponentRef::meta, "dstComponentInfoProperty");
		ComponentRef::meta_dstComponentInfoProperty_rev = Property::meta_srcComponentInfoProperty;
		::Uml::SetAssocRole(Property::meta_srcAssemblyConfigProperty, Property::meta, Component::meta, "dstAssemblyConfigProperty");
		Component::meta_dstAssemblyConfigProperty_rev = Property::meta_srcAssemblyConfigProperty;
		::Uml::SetAssocRole(Property::meta_srcAttributeValue, Property::meta, ReadonlyAttribute::meta, "dstAttributeValue");
		ReadonlyAttribute::meta_dstAttributeValue_rev = Property::meta_srcAttributeValue;
		::Uml::SetChildRole(Property::meta_DataType_child, Property::meta, DataType::meta, "", "");
		::Uml::SetParentRole(Property::meta_ImplementationContainer_parent, Property::meta, ImplementationContainer::meta, "", "");
		::Uml::SetParentRole(Property::meta_ComponentAssembly_parent, Property::meta, ComponentAssembly::meta, "", "");
		::Uml::SetParentRole(Property::meta_Path_parent, Property::meta, Path::meta, "", "");
		::Uml::SetParentRole(Property::meta_Paths_parent, Property::meta, Paths::meta, "", "");
		::Uml::SetParentRole(Property::meta_DeploymentPlan_parent, Property::meta, DeploymentPlan::meta, "", "");
		::Uml::SetParentRole(Property::meta_PackageConfigurationContainer_parent, Property::meta, PackageConfigurationContainer::meta, "", "");
		::Uml::SetParentRole(Property::meta_ArtifactContainer_parent, Property::meta, ArtifactContainer::meta, "", "");
		::Uml::SetParentRole(Property::meta_ComponentContainer_parent, Property::meta, ComponentContainer::meta, "", "");
		::Uml::SetParentRole(Property::meta_PackageContainer_parent, Property::meta, PackageContainer::meta, "", "");
		::Uml::SetParentRole(Property::meta_RequirementBase_parent, Property::meta, RequirementBase::meta, "", "");
		::Uml::SetParentRole(Property::meta_Domain_parent, Property::meta, Domain::meta, "", "");
		::Uml::SetParentRole(Property::meta_BehaviorInputAction_parent, Property::meta, BehaviorInputAction::meta, "", "");
		::Uml::SetParentRole(Property::meta_QueryInputAction_parent, Property::meta, QueryInputAction::meta, "", "");
		::Uml::SetParentRole(Property::meta_ActionBase_parent, Property::meta, ActionBase::meta, "", "");

		::Uml::SetAssocRole(Provideable::meta_referedbyRequiredRequestPort, Provideable::meta, RequiredRequestPort::meta, "ref");
		::Uml::SetAssocRole(Provideable::meta_referedbyProvidedRequestPort, Provideable::meta, ProvidedRequestPort::meta, "ref");

		::Uml::SetAssocRole(ProvidedRequestPort::meta_ref, ProvidedRequestPort::meta, Provideable::meta, "referedbyProvidedRequestPort");
		::Uml::SetAssocRole(ProvidedRequestPort::meta_dstFacetDelegate, ProvidedRequestPort::meta, ProvidedRequestPort::meta, "srcFacetDelegate");
		ProvidedRequestPort::meta_srcFacetDelegate_rev = ProvidedRequestPort::meta_dstFacetDelegate;
		::Uml::SetAssocRole(ProvidedRequestPort::meta_srcFacetDelegate, ProvidedRequestPort::meta, ProvidedRequestPort::meta, "dstFacetDelegate");
		ProvidedRequestPort::meta_dstFacetDelegate_rev = ProvidedRequestPort::meta_srcFacetDelegate;
		::Uml::SetAssocRole(ProvidedRequestPort::meta_srcSupportsDelegate, ProvidedRequestPort::meta, Supports::meta, "dstSupportsDelegate");
		Supports::meta_dstSupportsDelegate_rev = ProvidedRequestPort::meta_srcSupportsDelegate;
		::Uml::SetParentRole(ProvidedRequestPort::meta_ComponentAssembly_parent, ProvidedRequestPort::meta, ComponentAssembly::meta, "", "");

		::Uml::SetAssocRole(PublishConnector::meta_dstAssemblyDeployRequirement, PublishConnector::meta, Requirement::meta, "srcAssemblyDeployRequirement");
		Requirement::meta_srcAssemblyDeployRequirement_rev = PublishConnector::meta_dstAssemblyDeployRequirement;
		::Uml::SetAssocRole(PublishConnector::meta_dstdeliverTo, PublishConnector::meta, InEventPort::meta, "srcdeliverTo");
		InEventPort::meta_srcdeliverTo_rev = PublishConnector::meta_dstdeliverTo;
		::Uml::SetAssocRole(PublishConnector::meta_srcpublish, PublishConnector::meta, OutEventPort::meta, "dstpublish");
		OutEventPort::meta_dstpublish_rev = PublishConnector::meta_srcpublish;
		::Uml::SetParentRole(PublishConnector::meta_ComponentAssembly_parent, PublishConnector::meta, ComponentAssembly::meta, "", "");

		::Uml::SetParentRole(QueryInput::meta_TopLevelBehavior_parent, QueryInput::meta, TopLevelBehavior::meta, "", "");
		QueryInput::meta_dstQueryInput_end_ = QueryInputBase::meta_dstQueryInput;
		QueryInput::meta_srcQueryInput_end_ = QueryInputAction::meta_srcQueryInput;

		::Uml::SetAssocRole(QueryInputAction::meta_srcQueryInput, QueryInputAction::meta, QueryInputBase::meta, "dstQueryInput");
		QueryInputBase::meta_dstQueryInput_rev = QueryInputAction::meta_srcQueryInput;
		::Uml::SetChildRole(QueryInputAction::meta_Property_children, QueryInputAction::meta, Property::meta, "", "");
		::Uml::SetParentRole(QueryInputAction::meta_BehaviorModel_parent, QueryInputAction::meta, BehaviorModel::meta, "", "");

		::Uml::SetAssocRole(QueryInputBase::meta_dstQueryInput, QueryInputBase::meta, QueryInputAction::meta, "srcQueryInput");
		QueryInputAction::meta_srcQueryInput_rev = QueryInputBase::meta_dstQueryInput;

		::Uml::SetChildRole(RTRequirements::meta_ServiceProvider_child, RTRequirements::meta, ServiceProvider::meta, "", "");
		::Uml::SetChildRole(RTRequirements::meta_ServiceConsumer_child, RTRequirements::meta, ServiceConsumer::meta, "", "");

		::Uml::SetAssocRole(ReadonlyAttribute::meta_srcAttributeDelegate, ReadonlyAttribute::meta, AttributeMapping::meta, "dstAttributeDelegate");
		AttributeMapping::meta_dstAttributeDelegate_rev = ReadonlyAttribute::meta_srcAttributeDelegate;
		::Uml::SetAssocRole(ReadonlyAttribute::meta_referedbyAttributeMapping, ReadonlyAttribute::meta, AttributeMapping::meta, "ref");
		::Uml::SetAssocRole(ReadonlyAttribute::meta_dstAttributeValue, ReadonlyAttribute::meta, Property::meta, "srcAttributeValue");
		Property::meta_srcAttributeValue_rev = ReadonlyAttribute::meta_dstAttributeValue;
		::Uml::SetChildRole(ReadonlyAttribute::meta_AttributeMember_child, ReadonlyAttribute::meta, AttributeMember::meta, "", "");
		::Uml::SetChildRole(ReadonlyAttribute::meta_GetException_children, ReadonlyAttribute::meta, GetException::meta, "", "");
		::Uml::SetParentRole(ReadonlyAttribute::meta_Component_parent, ReadonlyAttribute::meta, Component::meta, "", "");
		::Uml::SetParentRole(ReadonlyAttribute::meta_Inheritable_parent, ReadonlyAttribute::meta, Inheritable::meta, "", "");

		::Uml::SetParentRole(ReceptacleDelegate::meta_ComponentAssembly_parent, ReceptacleDelegate::meta, ComponentAssembly::meta, "", "");
		ReceptacleDelegate::meta_srcReceptacleDelegate_end_ = RequiredRequestPort::meta_srcReceptacleDelegate;
		ReceptacleDelegate::meta_dstReceptacleDelegate_end_ = RequiredRequestPort::meta_dstReceptacleDelegate;

		::Uml::SetAssocRole(RequiredRequestPort::meta_dstinvoke, RequiredRequestPort::meta, InvokePortBase::meta, "srcinvoke");
		InvokePortBase::meta_srcinvoke_rev = RequiredRequestPort::meta_dstinvoke;
		::Uml::SetAssocRole(RequiredRequestPort::meta_ref, RequiredRequestPort::meta, Provideable::meta, "referedbyRequiredRequestPort");
		::Uml::SetAssocRole(RequiredRequestPort::meta_dstReceptacleDelegate, RequiredRequestPort::meta, RequiredRequestPort::meta, "srcReceptacleDelegate");
		RequiredRequestPort::meta_srcReceptacleDelegate_rev = RequiredRequestPort::meta_dstReceptacleDelegate;
		::Uml::SetAssocRole(RequiredRequestPort::meta_srcReceptacleDelegate, RequiredRequestPort::meta, RequiredRequestPort::meta, "dstReceptacleDelegate");
		RequiredRequestPort::meta_dstReceptacleDelegate_rev = RequiredRequestPort::meta_srcReceptacleDelegate;
		::Uml::SetParentRole(RequiredRequestPort::meta_ComponentAssembly_parent, RequiredRequestPort::meta, ComponentAssembly::meta, "", "");

		::Uml::SetAssocRole(Requirement::meta_srcAssemblyDeployRequirement, Requirement::meta, PublishConnector::meta, "dstAssemblyDeployRequirement");
		PublishConnector::meta_dstAssemblyDeployRequirement_rev = Requirement::meta_srcAssemblyDeployRequirement;
		::Uml::SetAssocRole(Requirement::meta_srcPackageConfSelectRequirement, Requirement::meta, PackageConfiguration::meta, "dstPackageConfSelectRequirement");
		PackageConfiguration::meta_dstPackageConfSelectRequirement_rev = Requirement::meta_srcPackageConfSelectRequirement;
		::Uml::SetAssocRole(Requirement::meta_srcArtifactDeployRequirement, Requirement::meta, ImplementationArtifact::meta, "dstArtifactDeployRequirement");
		ImplementationArtifact::meta_dstArtifactDeployRequirement_rev = Requirement::meta_srcArtifactDeployRequirement;
		::Uml::SetAssocRole(Requirement::meta_srcAssemblyselectRequirement, Requirement::meta, Component::meta, "dstAssemblyselectRequirement");
		Component::meta_dstAssemblyselectRequirement_rev = Requirement::meta_srcAssemblyselectRequirement;
		::Uml::SetParentRole(Requirement::meta_ComponentAssembly_parent, Requirement::meta, ComponentAssembly::meta, "", "");
		::Uml::SetParentRole(Requirement::meta_PackageConfigurationContainer_parent, Requirement::meta, PackageConfigurationContainer::meta, "", "");
		::Uml::SetParentRole(Requirement::meta_ArtifactContainer_parent, Requirement::meta, ArtifactContainer::meta, "", "");

		::Uml::SetChildRole(RequirementBase::meta_Property_children, RequirementBase::meta, Property::meta, "", "");

		::Uml::SetChildRole(RequirementSatisfier::meta_SatisfierProperty_children, RequirementSatisfier::meta, SatisfierProperty::meta, "", "");

		::Uml::SetParentRole(Resource::meta_Interconnect_parent, Resource::meta, Interconnect::meta, "", "");
		::Uml::SetParentRole(Resource::meta_Node_parent, Resource::meta, Node::meta, "", "");
		::Uml::SetParentRole(Resource::meta_Bridge_parent, Resource::meta, Bridge::meta, "", "");

		::Uml::SetAssocRole(ReturnType::meta_ref, ReturnType::meta, MemberType::meta, "referedbyReturnType");
		::Uml::SetParentRole(ReturnType::meta_TwowayOperation_parent, ReturnType::meta, TwowayOperation::meta, "", "");

		::Uml::SetChildRole(RootFolder::meta_PathDiagrams_children, RootFolder::meta, PathDiagrams::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ComponentFactoryImplementations_children, RootFolder::meta, ComponentFactoryImplementations::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ComponentAnalyses_children, RootFolder::meta, ComponentAnalyses::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_DeploymentPlans_children, RootFolder::meta, DeploymentPlans::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ComponentImplementations_children, RootFolder::meta, ComponentImplementations::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_PackageConfigurations_children, RootFolder::meta, PackageConfigurations::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ImplementationArtifacts_children, RootFolder::meta, ImplementationArtifacts::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ComponentTypes_children, RootFolder::meta, ComponentTypes::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_TopLevelPackages_children, RootFolder::meta, TopLevelPackages::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ComponentPackages_children, RootFolder::meta, ComponentPackages::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_Targets_children, RootFolder::meta, Targets::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_PredefinedTypes_children, RootFolder::meta, PredefinedTypes::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_InterfaceDefinitions_children, RootFolder::meta, InterfaceDefinitions::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ComponentBuild_children, RootFolder::meta, ComponentBuild::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_WorkerLibraries_children, RootFolder::meta, WorkerLibraries::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_RootFolder_children, RootFolder::meta, RootFolder::meta, "", "");
		::Uml::SetParentRole(RootFolder::meta_RootFolder_parent, RootFolder::meta, RootFolder::meta, "", "");

		::Uml::SetChildRole(SatisfierProperty::meta_DataType_child, SatisfierProperty::meta, DataType::meta, "", "");
		::Uml::SetParentRole(SatisfierProperty::meta_RequirementSatisfier_parent, SatisfierProperty::meta, RequirementSatisfier::meta, "", "");

		::Uml::SetChildRole(ServantProject::meta_FileRef_child, ServantProject::meta, FileRef::meta, "", "");
		::Uml::SetChildRole(ServantProject::meta_ImplementationArtifactReference_child, ServantProject::meta, ImplementationArtifactReference::meta, "", "");

		::Uml::SetParentRole(ServiceConsumer::meta_RTRequirements_parent, ServiceConsumer::meta, RTRequirements::meta, "", "");

		::Uml::SetParentRole(ServiceLevels::meta_ServiceProvider_parent, ServiceLevels::meta, ServiceProvider::meta, "", "");

		::Uml::SetChildRole(ServiceProvider::meta_ServiceLevels_child, ServiceProvider::meta, ServiceLevels::meta, "", "");
		::Uml::SetChildRole(ServiceProvider::meta_MultipleServiceRequests_child, ServiceProvider::meta, MultipleServiceRequests::meta, "", "");
		::Uml::SetParentRole(ServiceProvider::meta_RTRequirements_parent, ServiceProvider::meta, RTRequirements::meta, "", "");

		::Uml::SetAssocRole(SetException::meta_ref, SetException::meta, Exception::meta, "referedbySetException");
		::Uml::SetParentRole(SetException::meta_Attribute_parent, SetException::meta, Attribute::meta, "", "");

		::Uml::SetAssocRole(SharedComponentReference::meta_ref, SharedComponentReference::meta, ComponentRef::meta, "referedbySharedComponentReference");

		::Uml::SetAssocRole(SharedResource::meta_srcShares, SharedResource::meta, Node::meta, "dstShares");
		Node::meta_dstShares_rev = SharedResource::meta_srcShares;
		::Uml::SetParentRole(SharedResource::meta_Domain_parent, SharedResource::meta, Domain::meta, "", "");

		::Uml::SetParentRole(Shares::meta_Domain_parent, Shares::meta, Domain::meta, "", "");
		Shares::meta_srcShares_end_ = SharedResource::meta_srcShares;
		Shares::meta_dstShares_end_ = Node::meta_dstShares;

		::Uml::SetAssocRole(SingleInputBase::meta_dstInput, SingleInputBase::meta, InputAction::meta, "srcInput");
		InputAction::meta_srcInput_rev = SingleInputBase::meta_dstInput;

		::Uml::SetParentRole(SrcEdge::meta_Path_parent, SrcEdge::meta, Path::meta, "", "");
		SrcEdge::meta_dstSrcEdge_end_ = Edge::meta_dstSrcEdge;
		SrcEdge::meta_srcSrcEdge_end_ = GraphVertex::meta_srcSrcEdge;

		::Uml::SetAssocRole(State::meta_dstTransition, State::meta, ActionBase::meta, "srcTransition");
		ActionBase::meta_srcTransition_rev = State::meta_dstTransition;
		::Uml::SetAssocRole(State::meta_dstTerminalTransition, State::meta, Terminal::meta, "srcTerminalTransition");
		Terminal::meta_srcTerminalTransition_rev = State::meta_dstTerminalTransition;

		::Uml::SetAssocRole(StateBase::meta_dstFinish, StateBase::meta, BehaviorInputAction::meta, "srcFinish");
		BehaviorInputAction::meta_srcFinish_rev = StateBase::meta_dstFinish;
		::Uml::SetAssocRole(StateBase::meta_srcInputEffect, StateBase::meta, BehaviorInputAction::meta, "dstInputEffect");
		BehaviorInputAction::meta_dstInputEffect_rev = StateBase::meta_srcInputEffect;
		::Uml::SetAssocRole(StateBase::meta_srcEffect, StateBase::meta, ActionBase::meta, "dstEffect");
		ActionBase::meta_dstEffect_rev = StateBase::meta_srcEffect;
		::Uml::SetAssocRole(StateBase::meta_srcTerminalEffect, StateBase::meta, Terminal::meta, "dstTerminalEffect");
		Terminal::meta_dstTerminalEffect_rev = StateBase::meta_srcTerminalEffect;
		::Uml::SetParentRole(StateBase::meta_BehaviorModel_parent, StateBase::meta, BehaviorModel::meta, "", "");

		::Uml::SetChildRole(StubProject::meta_FileRef_child, StubProject::meta, FileRef::meta, "", "");
		::Uml::SetChildRole(StubProject::meta_ImplementationArtifactReference_child, StubProject::meta, ImplementationArtifactReference::meta, "", "");

		::Uml::SetAssocRole(Supports::meta_dstSupportsDelegate, Supports::meta, ProvidedRequestPort::meta, "srcSupportsDelegate");
		ProvidedRequestPort::meta_srcSupportsDelegate_rev = Supports::meta_dstSupportsDelegate;
		::Uml::SetAssocRole(Supports::meta_ref, Supports::meta, Object::meta, "referedbySupports");
		::Uml::SetParentRole(Supports::meta_SupportsInterfaces_parent, Supports::meta, SupportsInterfaces::meta, "", "");

		::Uml::SetParentRole(SupportsDelegate::meta_ComponentAssembly_parent, SupportsDelegate::meta, ComponentAssembly::meta, "", "");
		SupportsDelegate::meta_dstSupportsDelegate_end_ = Supports::meta_dstSupportsDelegate;
		SupportsDelegate::meta_srcSupportsDelegate_end_ = ProvidedRequestPort::meta_srcSupportsDelegate;

		::Uml::SetChildRole(SupportsInterfaces::meta_Supports_children, SupportsInterfaces::meta, Supports::meta, "", "");

		::Uml::SetChildRole(SwitchedAggregate::meta_Label_children, SwitchedAggregate::meta, Label::meta, "", "");
		::Uml::SetChildRole(SwitchedAggregate::meta_LabelConnection_children, SwitchedAggregate::meta, LabelConnection::meta, "", "");
		::Uml::SetChildRole(SwitchedAggregate::meta_Member_children, SwitchedAggregate::meta, Member::meta, "", "");
		::Uml::SetChildRole(SwitchedAggregate::meta_Discriminator_child, SwitchedAggregate::meta, Discriminator::meta, "", "");

		::Uml::SetChildRole(Targets::meta_Domain_children, Targets::meta, Domain::meta, "", "");
		::Uml::SetParentRole(Targets::meta_RootFolder_parent, Targets::meta, RootFolder::meta, "", "");

		::Uml::SetAssocRole(Task::meta_srcWorkLoadOperationConnection, Task::meta, OperationRef::meta, "dstWorkLoadOperationConnection");
		OperationRef::meta_dstWorkLoadOperationConnection_rev = Task::meta_srcWorkLoadOperationConnection;
		::Uml::SetAssocRole(Task::meta_setTaskSet, Task::meta, TaskSet::meta, "members");
		::Uml::SetParentRole(Task::meta_BenchmarkAnalysis_parent, Task::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(TaskSet::meta_srcWorkloadCharacteristics, TaskSet::meta, MetricsBase::meta, "dstWorkloadCharacteristics");
		MetricsBase::meta_dstWorkloadCharacteristics_rev = TaskSet::meta_srcWorkloadCharacteristics;
		::Uml::SetAssocRole(TaskSet::meta_members, TaskSet::meta, Task::meta, "setTaskSet");
		::Uml::SetParentRole(TaskSet::meta_BenchmarkAnalysis_parent, TaskSet::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetAssocRole(Terminal::meta_srcTerminalTransition, Terminal::meta, State::meta, "dstTerminalTransition");
		State::meta_dstTerminalTransition_rev = Terminal::meta_srcTerminalTransition;
		::Uml::SetAssocRole(Terminal::meta_dstTerminalEffect, Terminal::meta, StateBase::meta, "srcTerminalEffect");
		StateBase::meta_srcTerminalEffect_rev = Terminal::meta_dstTerminalEffect;
		::Uml::SetParentRole(Terminal::meta_BehaviorModel_parent, Terminal::meta, BehaviorModel::meta, "", "");

		::Uml::SetParentRole(TerminalEffect::meta_BehaviorModel_parent, TerminalEffect::meta, BehaviorModel::meta, "", "");
		TerminalEffect::meta_dstTerminalEffect_end_ = Terminal::meta_dstTerminalEffect;
		TerminalEffect::meta_srcTerminalEffect_end_ = StateBase::meta_srcTerminalEffect;

		::Uml::SetParentRole(TerminalTransition::meta_BehaviorModel_parent, TerminalTransition::meta, BehaviorModel::meta, "", "");
		TerminalTransition::meta_srcTerminalTransition_end_ = Terminal::meta_srcTerminalTransition;
		TerminalTransition::meta_dstTerminalTransition_end_ = State::meta_dstTerminalTransition;

		::Uml::SetAssocRole(TimeProbe::meta_srcTimerEventSinkConn, TimeProbe::meta, EventRef::meta, "dstTimerEventSinkConn");
		EventRef::meta_dstTimerEventSinkConn_rev = TimeProbe::meta_srcTimerEventSinkConn;
		::Uml::SetAssocRole(TimeProbe::meta_srcTimerConnection, TimeProbe::meta, OperationRef::meta, "dstTimerConnection");
		OperationRef::meta_dstTimerConnection_rev = TimeProbe::meta_srcTimerConnection;
		::Uml::SetParentRole(TimeProbe::meta_BenchmarkAnalysis_parent, TimeProbe::meta, BenchmarkAnalysis::meta, "", "");

		::Uml::SetParentRole(TimerConnection::meta_BenchmarkAnalysis_parent, TimerConnection::meta, BenchmarkAnalysis::meta, "", "");
		TimerConnection::meta_dstTimerConnection_end_ = OperationRef::meta_dstTimerConnection;
		TimerConnection::meta_srcTimerConnection_end_ = TimeProbe::meta_srcTimerConnection;

		::Uml::SetParentRole(TimerEventSinkConn::meta_BenchmarkAnalysis_parent, TimerEventSinkConn::meta, BenchmarkAnalysis::meta, "", "");
		TimerEventSinkConn::meta_dstTimerEventSinkConn_end_ = EventRef::meta_dstTimerEventSinkConn;
		TimerEventSinkConn::meta_srcTimerEventSinkConn_end_ = TimeProbe::meta_srcTimerEventSinkConn;

		::Uml::SetChildRole(TopLevelBehavior::meta_Input_children, TopLevelBehavior::meta, Input::meta, "", "");
		::Uml::SetChildRole(TopLevelBehavior::meta_MultiInput_children, TopLevelBehavior::meta, MultiInput::meta, "", "");
		::Uml::SetChildRole(TopLevelBehavior::meta_QueryInput_children, TopLevelBehavior::meta, QueryInput::meta, "", "");
		::Uml::SetChildRole(TopLevelBehavior::meta_PeriodicEvent_children, TopLevelBehavior::meta, PeriodicEvent::meta, "", "");
		::Uml::SetChildRole(TopLevelBehavior::meta_ApplicationTask_children, TopLevelBehavior::meta, ApplicationTask::meta, "", "");
		::Uml::SetChildRole(TopLevelBehavior::meta_Environment_child, TopLevelBehavior::meta, Environment::meta, "", "");

		::Uml::SetAssocRole(TopLevelPackage::meta_dstpackage, TopLevelPackage::meta, PackageConfigurationReference::meta, "srcpackage");
		PackageConfigurationReference::meta_srcpackage_rev = TopLevelPackage::meta_dstpackage;
		::Uml::SetParentRole(TopLevelPackage::meta_TopLevelPackageContainer_parent, TopLevelPackage::meta, TopLevelPackageContainer::meta, "", "");

		::Uml::SetChildRole(TopLevelPackageContainer::meta_TopLevelPackage_child, TopLevelPackageContainer::meta, TopLevelPackage::meta, "", "");
		::Uml::SetChildRole(TopLevelPackageContainer::meta_PackageConfigurationReference_child, TopLevelPackageContainer::meta, PackageConfigurationReference::meta, "", "");
		::Uml::SetChildRole(TopLevelPackageContainer::meta_package_child, TopLevelPackageContainer::meta, package::meta, "", "");
		::Uml::SetParentRole(TopLevelPackageContainer::meta_TopLevelPackages_parent, TopLevelPackageContainer::meta, TopLevelPackages::meta, "", "");

		::Uml::SetChildRole(TopLevelPackages::meta_TopLevelPackageContainer_children, TopLevelPackages::meta, TopLevelPackageContainer::meta, "", "");
		::Uml::SetParentRole(TopLevelPackages::meta_RootFolder_parent, TopLevelPackages::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(Transition::meta_BehaviorModel_parent, Transition::meta, BehaviorModel::meta, "", "");
		Transition::meta_dstTransition_end_ = State::meta_dstTransition;
		Transition::meta_srcTransition_end_ = ActionBase::meta_srcTransition;

		::Uml::SetChildRole(TwowayOperation::meta_OutParameter_children, TwowayOperation::meta, OutParameter::meta, "", "");
		::Uml::SetChildRole(TwowayOperation::meta_InoutParameter_children, TwowayOperation::meta, InoutParameter::meta, "", "");
		::Uml::SetChildRole(TwowayOperation::meta_ReturnType_child, TwowayOperation::meta, ReturnType::meta, "", "");
		::Uml::SetParentRole(TwowayOperation::meta_HasOperations_parent, TwowayOperation::meta, HasOperations::meta, "", "");

		::Uml::SetAssocRole(ValueObject::meta_referedbyLookupKey, ValueObject::meta, LookupKey::meta, "ref");

		::Uml::SetAssocRole(Variable::meta_ref, Variable::meta, PredefinedType::meta, "referedbyVariable");
		::Uml::SetParentRole(Variable::meta_BehaviorModel_parent, Variable::meta, BehaviorModel::meta, "", "");

		::Uml::SetParentRole(WorkLoadOperationConnection::meta_BenchmarkAnalysis_parent, WorkLoadOperationConnection::meta, BenchmarkAnalysis::meta, "", "");
		WorkLoadOperationConnection::meta_srcWorkLoadOperationConnection_end_ = Task::meta_srcWorkLoadOperationConnection;
		WorkLoadOperationConnection::meta_dstWorkLoadOperationConnection_end_ = OperationRef::meta_dstWorkLoadOperationConnection;

		::Uml::SetAssocRole(Worker::meta_referedbyWorkerType, Worker::meta, WorkerType::meta, "ref");
		::Uml::SetChildRole(Worker::meta_Action_children, Worker::meta, Action::meta, "", "");
		::Uml::SetParentRole(Worker::meta_WorkerPackageBase_parent, Worker::meta, WorkerPackageBase::meta, "", "");

		::Uml::SetChildRole(WorkerFile::meta_WorkerPackage_children, WorkerFile::meta, WorkerPackage::meta, "", "");
		::Uml::SetParentRole(WorkerFile::meta_WorkerLibrary_parent, WorkerFile::meta, WorkerLibrary::meta, "", "");

		::Uml::SetChildRole(WorkerLibraries::meta_WorkerLibrary_children, WorkerLibraries::meta, WorkerLibrary::meta, "", "");
		::Uml::SetParentRole(WorkerLibraries::meta_RootFolder_parent, WorkerLibraries::meta, RootFolder::meta, "", "");

		::Uml::SetChildRole(WorkerLibrary::meta_WorkerFile_children, WorkerLibrary::meta, WorkerFile::meta, "", "");
		::Uml::SetParentRole(WorkerLibrary::meta_WorkerLibraries_parent, WorkerLibrary::meta, WorkerLibraries::meta, "", "");

		::Uml::SetChildRole(WorkerPackage::meta_WorkerPackage_children, WorkerPackage::meta, WorkerPackage::meta, "", "");
		::Uml::SetParentRole(WorkerPackage::meta_WorkerFile_parent, WorkerPackage::meta, WorkerFile::meta, "", "");
		::Uml::SetParentRole(WorkerPackage::meta_WorkerPackage_parent, WorkerPackage::meta, WorkerPackage::meta, "", "");

		::Uml::SetChildRole(WorkerPackageBase::meta_Worker_children, WorkerPackageBase::meta, Worker::meta, "", "");

		::Uml::SetAssocRole(WorkerType::meta_ref, WorkerType::meta, Worker::meta, "referedbyWorkerType");
		::Uml::SetParentRole(WorkerType::meta_Component_parent, WorkerType::meta, Component::meta, "", "");

		::Uml::SetParentRole(WorkloadCharacteristics::meta_BenchmarkAnalysis_parent, WorkloadCharacteristics::meta, BenchmarkAnalysis::meta, "", "");
		WorkloadCharacteristics::meta_srcWorkloadCharacteristics_end_ = TaskSet::meta_srcWorkloadCharacteristics;
		WorkloadCharacteristics::meta_dstWorkloadCharacteristics_end_ = MetricsBase::meta_dstWorkloadCharacteristics;

		::Uml::SetAssocRole(Workspaces::meta_members, Workspaces::meta, Project::meta, "setWorkspace");
		::Uml::SetParentRole(Workspaces::meta_MPC_parent, Workspaces::meta, MPC::meta, "", "");

		::Uml::SetParentRole(deliverTo::meta_ComponentAssembly_parent, deliverTo::meta, ComponentAssembly::meta, "", "");
		deliverTo::meta_srcdeliverTo_end_ = InEventPort::meta_srcdeliverTo;
		deliverTo::meta_dstdeliverTo_end_ = PublishConnector::meta_dstdeliverTo;

		::Uml::SetParentRole(emit::meta_ComponentAssembly_parent, emit::meta, ComponentAssembly::meta, "", "");
		emit::meta_dstemit_end_ = OutEventPort::meta_dstemit;
		emit::meta_srcemit_end_ = InEventPort::meta_srcemit;

		::Uml::SetParentRole(invoke::meta_ComponentAssembly_parent, invoke::meta, ComponentAssembly::meta, "", "");
		invoke::meta_dstinvoke_end_ = RequiredRequestPort::meta_dstinvoke;
		invoke::meta_srcinvoke_end_ = InvokePortBase::meta_srcinvoke;

		::Uml::SetParentRole(package::meta_TopLevelPackageContainer_parent, package::meta, TopLevelPackageContainer::meta, "", "");
		package::meta_dstpackage_end_ = TopLevelPackage::meta_dstpackage;
		package::meta_srcpackage_end_ = PackageConfigurationReference::meta_srcpackage;

		::Uml::SetParentRole(publish::meta_ComponentAssembly_parent, publish::meta, ComponentAssembly::meta, "", "");
		publish::meta_dstpublish_end_ = OutEventPort::meta_dstpublish;
		publish::meta_srcpublish_end_ = PublishConnector::meta_srcpublish;

	}

	PICML_Export void Initialize()
	{
		static bool first = true;
		if (!first) return;
		first = false;
		::Uml::Initialize();

	
		ASSERT( meta == Udm::null );

		UdmStatic::StaticDataNetwork * meta_dn = new UdmStatic::StaticDataNetwork(::Uml::diagram);
		meta_dn->CreateNew("PICML.mem", "", ::Uml::Diagram::meta, Udm::CHANGES_LOST_DEFAULT);
		meta = ::Uml::Diagram::Cast(meta_dn->GetRootObject());

		::Uml::InitDiagramProps(meta, "PICML", "1.00");


		CreateMeta();
		InitMeta();
		InitMetaLinks();

	}

	PICML_Export void Initialize(const ::Uml::Diagram &dgr)
	{
		
		meta = dgr;

		InitMeta(dgr);
		InitMetaLinks(dgr);

		
		
	}


	PICML_Export Udm::UdmDiagram diagram = { &meta, Initialize };
	static struct _regClass
	{
		_regClass()
		{
			Udm::MetaDepository::StoreDiagram("PICML", diagram);
		}
		~_regClass()
		{
			Udm::MetaDepository::RemoveDiagram("PICML");
		}
	} __regUnUsed;

}

