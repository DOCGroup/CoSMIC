#include "stdafx.h"
#include "PICMLBonX.h"


namespace BON
{

IMPLEMENT_BONEXTENSION( PICML_BON::ComponentAnalyses, "ComponentAnalyses" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentBuild, "ComponentBuild" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentImplementations, "ComponentImplementations" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentPackages, "ComponentPackages" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentTypes, "ComponentTypes" );
IMPLEMENT_BONEXTENSION( PICML_BON::DeploymentPlans, "DeploymentPlans" );
IMPLEMENT_BONEXTENSION( PICML_BON::EventChannelConfig, "EventChannelConfig" );
IMPLEMENT_BONEXTENSION( PICML_BON::ImplementationArtifacts, "ImplementationArtifacts" );
IMPLEMENT_BONEXTENSION( PICML_BON::InterfaceDefinitions, "InterfaceDefinitions" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfigurations, "PackageConfigurations" );
IMPLEMENT_BONEXTENSION( PICML_BON::PathDiagram, "PathDiagram" );
IMPLEMENT_BONEXTENSION( PICML_BON::PredefinedTypes, "PredefinedTypes" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSModeling, "QoSModeling" );
IMPLEMENT_BONEXTENSION( PICML_BON::Targets, "Targets" );
IMPLEMENT_BONEXTENSION( PICML_BON::TopLevelPackages, "TopLevelPackages" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Prefixable );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::SupportsInterfaces );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::AbstractInPort );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::AbstractOutPort );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::CommonPortAttrs );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::ConstantType );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::GraphVertex );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Manageable );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::MemberType );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Provideable );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Taggable );
IMPLEMENT_BONEXTENSION( PICML_BON::ConnectedComponent, "ConnectedComponent" );
IMPLEMENT_BONEXTENSION( PICML_BON::Exception, "Exception" );
IMPLEMENT_BONEXTENSION( PICML_BON::File, "File" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::OperationBase );
IMPLEMENT_BONEXTENSION( PICML_BON::Package, "Package" );
IMPLEMENT_BONEXTENSION( PICML_BON::ReadonlyAttribute, "ReadonlyAttribute" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::NamedType );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Port );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::PredefinedType );
IMPLEMENT_BONEXTENSION( PICML_BON::DisplayNode, "DisplayNode" );
IMPLEMENT_BONEXTENSION( PICML_BON::POA, "POA" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentRef, "ComponentRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::Constant, "Constant" );
IMPLEMENT_BONEXTENSION( PICML_BON::Attribute, "Attribute" );
IMPLEMENT_BONEXTENSION( PICML_BON::Component, "Component" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::HasExceptions );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Inheritable );
IMPLEMENT_BONEXTENSION( PICML_BON::OnewayOperation, "OnewayOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::NoInheritable );
IMPLEMENT_BONEXTENSION( PICML_BON::Boolean, "Boolean" );
IMPLEMENT_BONEXTENSION( PICML_BON::Byte, "Byte" );
IMPLEMENT_BONEXTENSION( PICML_BON::GenericObject, "GenericObject" );
IMPLEMENT_BONEXTENSION( PICML_BON::GenericValue, "GenericValue" );
IMPLEMENT_BONEXTENSION( PICML_BON::GenericValueObject, "GenericValueObject" );
IMPLEMENT_BONEXTENSION( PICML_BON::LongInteger, "LongInteger" );
IMPLEMENT_BONEXTENSION( PICML_BON::RealNumber, "RealNumber" );
IMPLEMENT_BONEXTENSION( PICML_BON::ShortInteger, "ShortInteger" );
IMPLEMENT_BONEXTENSION( PICML_BON::String, "String" );
IMPLEMENT_BONEXTENSION( PICML_BON::TypeEncoding, "TypeEncoding" );
IMPLEMENT_BONEXTENSION( PICML_BON::TypeKind, "TypeKind" );
IMPLEMENT_BONEXTENSION( PICML_BON::Boxed, "Boxed" );
IMPLEMENT_BONEXTENSION( PICML_BON::InEventPort, "InEventPort" );
IMPLEMENT_BONEXTENSION( PICML_BON::OutEventPort, "OutEventPort" );
IMPLEMENT_BONEXTENSION( PICML_BON::ProvidedRequestPort, "ProvidedRequestPort" );
IMPLEMENT_BONEXTENSION( PICML_BON::RequiredRequestPort, "RequiredRequestPort" );
IMPLEMENT_BONEXTENSION( PICML_BON::Aggregate, "Aggregate" );
IMPLEMENT_BONEXTENSION( PICML_BON::Enum, "Enum" );
IMPLEMENT_BONEXTENSION( PICML_BON::FactoryOperation, "FactoryOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::HasOperations );
IMPLEMENT_BONEXTENSION( PICML_BON::LookupOperation, "LookupOperation" );
IMPLEMENT_BONEXTENSION( PICML_BON::SwitchedAggregate, "SwitchedAggregate" );
IMPLEMENT_BONEXTENSION( PICML_BON::TwowayOperation, "TwowayOperation" );
IMPLEMENT_BONEXTENSION( PICML_BON::Alias, "Alias" );
IMPLEMENT_BONEXTENSION( PICML_BON::Collection, "Collection" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentFactory, "ComponentFactory" );
IMPLEMENT_BONEXTENSION( PICML_BON::Object, "Object" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::ObjectByValue );
IMPLEMENT_BONEXTENSION( PICML_BON::Event, "Event" );
IMPLEMENT_BONEXTENSION( PICML_BON::ValueObject, "ValueObject" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Proxy );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::RTEC_Proxy );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Proxy_Consumer );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Proxy_Supplier );
IMPLEMENT_BONEXTENSION( PICML_BON::RTEC_Proxy_Consumer, "RTEC_Proxy_Consumer" );
IMPLEMENT_BONEXTENSION( PICML_BON::RTEC_Proxy_Supplier, "RTEC_Proxy_Supplier" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::ActionBase );
IMPLEMENT_BONEXTENSION( PICML_BON::Action, "Action" );
IMPLEMENT_BONEXTENSION( PICML_BON::InputAction, "InputAction" );
IMPLEMENT_BONEXTENSION( PICML_BON::OutputAction, "OutputAction" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::PeriodicAction );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSCharacteristic, "QoSCharacteristic" );
IMPLEMENT_BONEXTENSION( PICML_BON::CPU, "CPU" );
IMPLEMENT_BONEXTENSION( PICML_BON::Concurrency, "Concurrency" );
IMPLEMENT_BONEXTENSION( PICML_BON::Connection, "Connection" );
IMPLEMENT_BONEXTENSION( PICML_BON::Process, "Process" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::Elements );
IMPLEMENT_BONEXTENSION( PICML_BON::Bridge, "Bridge" );
IMPLEMENT_BONEXTENSION( PICML_BON::Interconnect, "Interconnect" );
IMPLEMENT_BONEXTENSION( PICML_BON::Node, "Node" );
IMPLEMENT_BONEXTENSION( PICML_BON::SharedResource, "SharedResource" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::ComponentLib );
IMPLEMENT_BONEXTENSION( PICML_BON::ExecutorProject, "ExecutorProject" );
IMPLEMENT_BONEXTENSION( PICML_BON::ServantProject, "ServantProject" );
IMPLEMENT_BONEXTENSION( PICML_BON::StubProject, "StubProject" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::resource );
IMPLEMENT_BONEXTENSION( PICML_BON::BandedConnection, "BandedConnection" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::ThreadPool );
IMPLEMENT_BONEXTENSION( PICML_BON::SimpleThreadPool, "SimpleThreadPool" );
IMPLEMENT_BONEXTENSION( PICML_BON::ThreadPoolWithLanes, "ThreadPoolWithLanes" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::RequirementBase );
IMPLEMENT_BONEXTENSION( PICML_BON::ImplementationRequirement, "ImplementationRequirement" );
IMPLEMENT_BONEXTENSION( PICML_BON::Requirement, "Requirement" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::MetricsBase );
IMPLEMENT_BONEXTENSION( PICML_BON::Latency, "Latency" );
IMPLEMENT_BONEXTENSION( PICML_BON::Throughput, "Throughput" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::RequirementSatisfier );
IMPLEMENT_BONEXTENSION( PICML_BON::Capability, "Capability" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::ComponentImplementation );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentAssembly, "ComponentAssembly" );
IMPLEMENT_BONEXTENSION( PICML_BON::MonolithicImplementation, "MonolithicImplementation" );
IMPLEMENT_BONEXTENSION( PICML_BON::ArtifactContainer, "ArtifactContainer" );
IMPLEMENT_BONEXTENSION( PICML_BON::BenchmarkAnalysis, "BenchmarkAnalysis" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentContainer, "ComponentContainer" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentImplementationContainer, "ComponentImplementationContainer" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentPropertyDescription, "ComponentPropertyDescription" );
IMPLEMENT_BONEXTENSION( PICML_BON::DeploymentPlan, "DeploymentPlan" );
IMPLEMENT_BONEXTENSION( PICML_BON::Domain, "Domain" );
IMPLEMENT_BONEXTENSION( PICML_BON::EventChannelConfiguration, "EventChannelConfiguration" );
IMPLEMENT_BONEXTENSION( PICML_BON::MPC, "MPC" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfigurationContainer, "PackageConfigurationContainer" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageContainer, "PackageContainer" );
IMPLEMENT_BONEXTENSION( PICML_BON::Path, "Path" );
IMPLEMENT_BONEXTENSION( PICML_BON::PolicySet, "PolicySet" );
IMPLEMENT_BONEXTENSION( PICML_BON::Project, "Project" );
IMPLEMENT_BONEXTENSION( PICML_BON::Property, "Property" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSCategory, "QoSCategory" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSContext, "QoSContext" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSValue, "QoSValue" );
IMPLEMENT_BONEXTENSION( PICML_BON::RTConfiguration, "RTConfiguration" );
IMPLEMENT_BONEXTENSION( PICML_BON::RTModel, "RTModel" );
IMPLEMENT_BONEXTENSION( PICML_BON::Resource, "Resource" );
IMPLEMENT_BONEXTENSION( PICML_BON::ResourceContainer, "ResourceContainer" );
IMPLEMENT_BONEXTENSION( PICML_BON::SatisfierProperty, "SatisfierProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::TopLevelPackageContainer, "TopLevelPackageContainer" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::BenchmarkType );
IMPLEMENT_BONEXTENSION( PICML_BON::FixedIterationBenchmarks, "FixedIterationBenchmarks" );
IMPLEMENT_BONEXTENSION( PICML_BON::PeriodicBenchmarks, "PeriodicBenchmarks" );
IMPLEMENT_BONEXTENSION( PICML_BON::TriggerBenchmarks, "TriggerBenchmarks" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::DataAnalysisBase );
IMPLEMENT_BONEXTENSION( PICML_BON::Average, "Average" );
IMPLEMENT_BONEXTENSION( PICML_BON::Jitter, "Jitter" );
IMPLEMENT_BONEXTENSION( PICML_BON::Maximum, "Maximum" );
IMPLEMENT_BONEXTENSION( PICML_BON::Minimum, "Minimum" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::QoSConstraint );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSContract, "QoSContract" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSOffered, "QoSOffered" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSRequired, "QoSRequired" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentPackage, "ComponentPackage" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::RTEC_Filter_Group );
IMPLEMENT_BONEXTENSION( PICML_BON::ConjunctionGroup, "ConjunctionGroup" );
IMPLEMENT_BONEXTENSION( PICML_BON::DisjunctionGroup, "DisjunctionGroup" );
IMPLEMENT_BONEXTENSION( PICML_BON::LogicalANDGroup, "LogicalANDGroup" );
IMPLEMENT_BONEXTENSION( PICML_BON::ConnectionBand, "ConnectionBand" );
IMPLEMENT_BONEXTENSION( PICML_BON::Edge, "Edge" );
IMPLEMENT_BONEXTENSION( PICML_BON::EnumValue, "EnumValue" );
IMPLEMENT_BONEXTENSION( PICML_BON::EnvironmentConf, "EnvironmentConf" );
IMPLEMENT_BONEXTENSION( PICML_BON::ExternalReferenceEndPoint, "ExternalReferenceEndPoint" );
IMPLEMENT_BONEXTENSION( PICML_BON::ImplementationArtifact, "ImplementationArtifact" );
IMPLEMENT_BONEXTENSION( PICML_BON::ImplementationDependency, "ImplementationDependency" );
IMPLEMENT_BONEXTENSION( PICML_BON::Label, "Label" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML_BON::RT_Info_Param );
IMPLEMENT_BONEXTENSION( PICML_BON::Null_RT_Info, "Null_RT_Info" );
IMPLEMENT_BONEXTENSION( PICML_BON::RT_Info, "RT_Info" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfiguration, "PackageConfiguration" );
IMPLEMENT_BONEXTENSION( PICML_BON::PriorityModelPolicy, "PriorityModelPolicy" );
IMPLEMENT_BONEXTENSION( PICML_BON::PrivateFlag, "PrivateFlag" );
IMPLEMENT_BONEXTENSION( PICML_BON::PublishConnector, "PublishConnector" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSDimension, "QoSDimension" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSDimensionSlot, "QoSDimensionSlot" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSParameter, "QoSParameter" );
IMPLEMENT_BONEXTENSION( PICML_BON::RTEC_Resource_Factory, "RTEC_Resource_Factory" );
IMPLEMENT_BONEXTENSION( PICML_BON::State, "State" );
IMPLEMENT_BONEXTENSION( PICML_BON::Task, "Task" );
IMPLEMENT_BONEXTENSION( PICML_BON::ThreadPoolLane, "ThreadPoolLane" );
IMPLEMENT_BONEXTENSION( PICML_BON::TimeProbe, "TimeProbe" );
IMPLEMENT_BONEXTENSION( PICML_BON::TopLevelPackage, "TopLevelPackage" );
IMPLEMENT_BONEXTENSION( PICML_BON::ArtifactDependency, "ArtifactDependency" );
IMPLEMENT_BONEXTENSION( PICML_BON::ArtifactDependsOn, "ArtifactDependsOn" );
IMPLEMENT_BONEXTENSION( PICML_BON::ArtifactDeployRequirement, "ArtifactDeployRequirement" );
IMPLEMENT_BONEXTENSION( PICML_BON::ArtifactExecParameter, "ArtifactExecParameter" );
IMPLEMENT_BONEXTENSION( PICML_BON::ArtifactInfoProperty, "ArtifactInfoProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::AssemblyConfigProperty, "AssemblyConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::AssemblyDeployRequirement, "AssemblyDeployRequirement" );
IMPLEMENT_BONEXTENSION( PICML_BON::AssemblyselectRequirement, "AssemblyselectRequirement" );
IMPLEMENT_BONEXTENSION( PICML_BON::AttributeDelegate, "AttributeDelegate" );
IMPLEMENT_BONEXTENSION( PICML_BON::AttributeMappingDelegate, "AttributeMappingDelegate" );
IMPLEMENT_BONEXTENSION( PICML_BON::AttributeMappingValue, "AttributeMappingValue" );
IMPLEMENT_BONEXTENSION( PICML_BON::AttributeValue, "AttributeValue" );
IMPLEMENT_BONEXTENSION( PICML_BON::BenchmarkCharacteristics, "BenchmarkCharacteristics" );
IMPLEMENT_BONEXTENSION( PICML_BON::Bridge2Interconnect, "Bridge2Interconnect" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentConfigProperty, "ComponentConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentInfoProperty, "ComponentInfoProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentOperation, "ComponentOperation" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentProperty, "ComponentProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::ConfigProperty, "ConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::DstEdge, "DstEdge" );
IMPLEMENT_BONEXTENSION( PICML_BON::Effect, "Effect" );
IMPLEMENT_BONEXTENSION( PICML_BON::EventSinkDelegate, "EventSinkDelegate" );
IMPLEMENT_BONEXTENSION( PICML_BON::EventSourceDelegate, "EventSourceDelegate" );
IMPLEMENT_BONEXTENSION( PICML_BON::ExtResourceConn, "ExtResourceConn" );
IMPLEMENT_BONEXTENSION( PICML_BON::ExternalDelegate, "ExternalDelegate" );
IMPLEMENT_BONEXTENSION( PICML_BON::FacetDelegate, "FacetDelegate" );
IMPLEMENT_BONEXTENSION( PICML_BON::Finish, "Finish" );
IMPLEMENT_BONEXTENSION( PICML_BON::Implementation, "Implementation" );
IMPLEMENT_BONEXTENSION( PICML_BON::ImplementationCapability, "ImplementationCapability" );
IMPLEMENT_BONEXTENSION( PICML_BON::ImplementationDependsOn, "ImplementationDependsOn" );
IMPLEMENT_BONEXTENSION( PICML_BON::Implements, "Implements" );
IMPLEMENT_BONEXTENSION( PICML_BON::Include_RTEC_Filter_Group, "Include_RTEC_Filter_Group" );
IMPLEMENT_BONEXTENSION( PICML_BON::Include_RT_Info, "Include_RT_Info" );
IMPLEMENT_BONEXTENSION( PICML_BON::InfoProperty, "InfoProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::Input, "Input" );
IMPLEMENT_BONEXTENSION( PICML_BON::InstanceMapping, "InstanceMapping" );
IMPLEMENT_BONEXTENSION( PICML_BON::Interconnect2Bridge, "Interconnect2Bridge" );
IMPLEMENT_BONEXTENSION( PICML_BON::Interconnect2Node, "Interconnect2Node" );
IMPLEMENT_BONEXTENSION( PICML_BON::LabelConnection, "LabelConnection" );
IMPLEMENT_BONEXTENSION( PICML_BON::MakeMemberPrivate, "MakeMemberPrivate" );
IMPLEMENT_BONEXTENSION( PICML_BON::ManagesComponent, "ManagesComponent" );
IMPLEMENT_BONEXTENSION( PICML_BON::MetricConnection, "MetricConnection" );
IMPLEMENT_BONEXTENSION( PICML_BON::MonolithDeployRequirement, "MonolithDeployRequirement" );
IMPLEMENT_BONEXTENSION( PICML_BON::MonolithExecParameter, "MonolithExecParameter" );
IMPLEMENT_BONEXTENSION( PICML_BON::MonolithprimaryArtifact, "MonolithprimaryArtifact" );
IMPLEMENT_BONEXTENSION( PICML_BON::Node2Interconnect, "Node2Interconnect" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfBasePackage, "PackageConfBasePackage" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfConfigProperty, "PackageConfConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfReference, "PackageConfReference" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfSelectRequirement, "PackageConfSelectRequirement" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfSpecializedConfig, "PackageConfSpecializedConfig" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfigProperty, "PackageConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageInfoProperty, "PackageInfoProperty" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageInterface, "PackageInterface" );
IMPLEMENT_BONEXTENSION( PICML_BON::PropertyConnector, "PropertyConnector" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSDecoration, "QoSDecoration" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSDimensionQualifier, "QoSDimensionQualifier" );
IMPLEMENT_BONEXTENSION( PICML_BON::RTEC_Connection, "RTEC_Connection" );
IMPLEMENT_BONEXTENSION( PICML_BON::ReceptacleDelegate, "ReceptacleDelegate" );
IMPLEMENT_BONEXTENSION( PICML_BON::Shares, "Shares" );
IMPLEMENT_BONEXTENSION( PICML_BON::SrcEdge, "SrcEdge" );
IMPLEMENT_BONEXTENSION( PICML_BON::TimerConnection, "TimerConnection" );
IMPLEMENT_BONEXTENSION( PICML_BON::TimerEventSinkConn, "TimerEventSinkConn" );
IMPLEMENT_BONEXTENSION( PICML_BON::Transition, "Transition" );
IMPLEMENT_BONEXTENSION( PICML_BON::Use_RTEC_Filter, "Use_RTEC_Filter" );
IMPLEMENT_BONEXTENSION( PICML_BON::Use_RT_Info, "Use_RT_Info" );
IMPLEMENT_BONEXTENSION( PICML_BON::WorkLoadOperationConnection, "WorkLoadOperationConnection" );
IMPLEMENT_BONEXTENSION( PICML_BON::WorkloadCharacteristics, "WorkloadCharacteristics" );
IMPLEMENT_BONEXTENSION( PICML_BON::deliverTo, "deliverTo" );
IMPLEMENT_BONEXTENSION( PICML_BON::emit, "emit" );
IMPLEMENT_BONEXTENSION( PICML_BON::invoke, "invoke" );
IMPLEMENT_BONEXTENSION( PICML_BON::package, "package" );
IMPLEMENT_BONEXTENSION( PICML_BON::publish, "publish" );
IMPLEMENT_BONEXTENSION( PICML_BON::CollocationGroup, "CollocationGroup" );
IMPLEMENT_BONEXTENSION( PICML_BON::TaskSet, "TaskSet" );
IMPLEMENT_BONEXTENSION( PICML_BON::Workspaces, "Workspaces" );
IMPLEMENT_BONEXTENSION( PICML_BON::AttributeMapping, "AttributeMapping" );
IMPLEMENT_BONEXTENSION( PICML_BON::AttributeMember, "AttributeMember" );
IMPLEMENT_BONEXTENSION( PICML_BON::BandedConnectionRef, "BandedConnectionRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::CompRef, "CompRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentAssemblyReference, "ComponentAssemblyReference" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentImplementationReference, "ComponentImplementationReference" );
IMPLEMENT_BONEXTENSION( PICML_BON::ComponentPackageReference, "ComponentPackageReference" );
IMPLEMENT_BONEXTENSION( PICML_BON::DataType, "DataType" );
IMPLEMENT_BONEXTENSION( PICML_BON::Discriminator, "Discriminator" );
IMPLEMENT_BONEXTENSION( PICML_BON::EventRef, "EventRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::ExceptionRef, "ExceptionRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::ExternalResources, "ExternalResources" );
IMPLEMENT_BONEXTENSION( PICML_BON::FileRef, "FileRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::GetException, "GetException" );
IMPLEMENT_BONEXTENSION( PICML_BON::ImplementationArtifactReference, "ImplementationArtifactReference" );
IMPLEMENT_BONEXTENSION( PICML_BON::InParameter, "InParameter" );
IMPLEMENT_BONEXTENSION( PICML_BON::Inherits, "Inherits" );
IMPLEMENT_BONEXTENSION( PICML_BON::InoutParameter, "InoutParameter" );
IMPLEMENT_BONEXTENSION( PICML_BON::LookupKey, "LookupKey" );
IMPLEMENT_BONEXTENSION( PICML_BON::Member, "Member" );
IMPLEMENT_BONEXTENSION( PICML_BON::NodeReference, "NodeReference" );
IMPLEMENT_BONEXTENSION( PICML_BON::OperationRef, "OperationRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::OutParameter, "OutParameter" );
IMPLEMENT_BONEXTENSION( PICML_BON::PackageConfigurationReference, "PackageConfigurationReference" );
IMPLEMENT_BONEXTENSION( PICML_BON::PolicySetRef, "PolicySetRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::QoSCharacteristicRef, "QoSCharacteristicRef" );
IMPLEMENT_BONEXTENSION( PICML_BON::RTEC_Resource_Factory_Reference, "RTEC_Resource_Factory_Reference" );
IMPLEMENT_BONEXTENSION( PICML_BON::ReturnType, "ReturnType" );
IMPLEMENT_BONEXTENSION( PICML_BON::SetException, "SetException" );
IMPLEMENT_BONEXTENSION( PICML_BON::Supports, "Supports" );
IMPLEMENT_BONEXTENSION( PICML_BON::ThreadPoolRef, "ThreadPoolRef" );


}; // end namespace BON

namespace PICML_BON
{
//********************************************************************************
// 
//********************************************************************************
std::string PrefixableImpl::getPrefixTag() 
{
	return FCOImpl::getAttribute("PrefixTag")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void PrefixableImpl::setPrefixTag( const std::string& val)
{
	FCOImpl::getAttribute("PrefixTag")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
bool CommonPortAttrsImpl::isexclusiveProvider() 
{
	return FCOImpl::getAttribute("exclusiveProvider")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
bool CommonPortAttrsImpl::isexclusiveUser() 
{
	return FCOImpl::getAttribute("exclusiveUser")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
bool CommonPortAttrsImpl::isoptional() 
{
	return FCOImpl::getAttribute("optional")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void CommonPortAttrsImpl::setexclusiveProvider( bool val)
{
	FCOImpl::getAttribute("exclusiveProvider")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void CommonPortAttrsImpl::setexclusiveUser( bool val)
{
	FCOImpl::getAttribute("exclusiveUser")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void CommonPortAttrsImpl::setoptional( bool val)
{
	FCOImpl::getAttribute("optional")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string TaggableImpl::getSpecifyIdTag() 
{
	return FCOImpl::getAttribute("SpecifyIdTag")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string TaggableImpl::getVersionTag() 
{
	return FCOImpl::getAttribute("VersionTag")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void TaggableImpl::setSpecifyIdTag( const std::string& val)
{
	FCOImpl::getAttribute("SpecifyIdTag")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void TaggableImpl::setVersionTag( const std::string& val)
{
	FCOImpl::getAttribute("VersionTag")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
Component ComponentRefImpl::getComponent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Component(r);
}


//********************************************************************************
// 
//********************************************************************************
std::string ConstantImpl::getvalue() 
{
	return FCOImpl::getAttribute("value")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ConstantImpl::setvalue( const std::string& val)
{
	FCOImpl::getAttribute("value")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
ConstantType ConstantImpl::getConstantType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ConstantType(r);
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentImpl::getUUID() 
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ComponentImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ComponentImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
MemberType BoxedImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
Event InEventPortImpl::getEvent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Event(r);
}


//********************************************************************************
// 
//********************************************************************************
OutEventPortImpl::out_event_port_type_Type OutEventPortImpl::getout_event_port_type()
{
	std::string val = FCOImpl::getAttribute("out_event_port_type")->getStringValue();

	if ( val == "DirectConnect") return DirectConnect_out_event_port_type_Type;
	else if ( val == "RTEventChannel") return RTEventChannel_out_event_port_type_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
bool OutEventPortImpl::issingle_destination() 
{
	return FCOImpl::getAttribute("single_destination")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void OutEventPortImpl::setout_event_port_type( OutEventPortImpl::out_event_port_type_Type val)
{
	std::string str_val = "";

	if ( val == DirectConnect_out_event_port_type_Type) str_val = "DirectConnect";
	else if ( val == RTEventChannel_out_event_port_type_Type) str_val = "RTEventChannel";
	else throw("None of the possible items");

	FCOImpl::getAttribute("out_event_port_type")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void OutEventPortImpl::setsingle_destination( bool val)
{
	FCOImpl::getAttribute("single_destination")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
Event OutEventPortImpl::getEvent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Event(r);
}


//********************************************************************************
// 
//********************************************************************************
Provideable ProvidedRequestPortImpl::getProvideable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Provideable(r);
}


//********************************************************************************
// 
//********************************************************************************
bool RequiredRequestPortImpl::ismultiple_connections() 
{
	return FCOImpl::getAttribute("multiple_connections")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void RequiredRequestPortImpl::setmultiple_connections( bool val)
{
	FCOImpl::getAttribute("multiple_connections")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
Provideable RequiredRequestPortImpl::getProvideable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Provideable(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType AliasImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType CollectionImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
bool ObjectImpl::isabstract() 
{
	return FCOImpl::getAttribute("abstract")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
bool ObjectImpl::islocal() 
{
	return FCOImpl::getAttribute("local")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ObjectImpl::setabstract( bool val)
{
	FCOImpl::getAttribute("abstract")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ObjectImpl::setlocal( bool val)
{
	FCOImpl::getAttribute("local")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
bool ObjectByValueImpl::isabstract() 
{
	return FCOImpl::getAttribute("abstract")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ObjectByValueImpl::setabstract( bool val)
{
	FCOImpl::getAttribute("abstract")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
bool ActionBaseImpl::isEnabled() 
{
	return FCOImpl::getAttribute("Enabled")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ActionBaseImpl::setEnabled( bool val)
{
	FCOImpl::getAttribute("Enabled")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long ActionImpl::getRepetitions() 
{
	return FCOImpl::getAttribute("Repetitions")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void ActionImpl::setRepetitions( const long val)
{
	FCOImpl::getAttribute("Repetitions")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long OutputActionImpl::getRepetitions() 
{
	return FCOImpl::getAttribute("Repetitions")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void OutputActionImpl::setRepetitions( const long val)
{
	FCOImpl::getAttribute("Repetitions")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long PeriodicActionImpl::getPeriod() 
{
	return FCOImpl::getAttribute("Period")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void PeriodicActionImpl::setPeriod( const long val)
{
	FCOImpl::getAttribute("Period")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
bool QoSCharacteristicImpl::isisInvariant() 
{
	return FCOImpl::getAttribute("isInvariant")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void QoSCharacteristicImpl::setisInvariant( bool val)
{
	FCOImpl::getAttribute("isInvariant")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
CPUImpl::Arch_Type CPUImpl::getArch()
{
	std::string val = FCOImpl::getAttribute("Arch")->getStringValue();

	if ( val == "i386") return i386_Arch_Type;
	else if ( val == "PPC") return PPC_Arch_Type;
	else if ( val == "SPARC") return SPARC_Arch_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
long CPUImpl::getSMP() 
{
	return FCOImpl::getAttribute("SMP")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void CPUImpl::setArch( CPUImpl::Arch_Type val)
{
	std::string str_val = "";

	if ( val == i386_Arch_Type) str_val = "i386";
	else if ( val == PPC_Arch_Type) str_val = "PPC";
	else if ( val == SPARC_Arch_Type) str_val = "SPARC";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Arch")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void CPUImpl::setSMP( const long val)
{
	FCOImpl::getAttribute("SMP")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
double ConcurrencyImpl::getMaxRequests() 
{
	return FCOImpl::getAttribute("MaxRequests")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
void ConcurrencyImpl::setMaxRequests( const double val)
{
	FCOImpl::getAttribute("MaxRequests")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
ConnectionImpl::Transport_Type ConnectionImpl::getTransport()
{
	std::string val = FCOImpl::getAttribute("Transport")->getStringValue();

	if ( val == "IPv4") return IPv4_Transport_Type;
	else if ( val == "IPv6") return IPv6_Transport_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void ConnectionImpl::setTransport( ConnectionImpl::Transport_Type val)
{
	std::string str_val = "";

	if ( val == IPv4_Transport_Type) str_val = "IPv4";
	else if ( val == IPv6_Transport_Type) str_val = "IPv6";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Transport")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ProcessImpl::getProcessPriority() 
{
	return FCOImpl::getAttribute("ProcessPriority")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
ProcessImpl::Scheduling_Type ProcessImpl::getScheduling()
{
	std::string val = FCOImpl::getAttribute("Scheduling")->getStringValue();

	if ( val == "FIFO") return FIFO_Scheduling_Type;
	else if ( val == "RR") return RR_Scheduling_Type;
	else if ( val == "OTHER") return OTHER_Scheduling_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void ProcessImpl::setProcessPriority( const std::string& val)
{
	FCOImpl::getAttribute("ProcessPriority")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ProcessImpl::setScheduling( ProcessImpl::Scheduling_Type val)
{
	std::string str_val = "";

	if ( val == FIFO_Scheduling_Type) str_val = "FIFO";
	else if ( val == RR_Scheduling_Type) str_val = "RR";
	else if ( val == OTHER_Scheduling_Type) str_val = "OTHER";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Scheduling")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
std::string BridgeImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void BridgeImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string InterconnectImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void InterconnectImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string NodeImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void NodeImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string SharedResourceImpl::getresourceType() 
{
	return FCOImpl::getAttribute("resourceType")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void SharedResourceImpl::setresourceType( const std::string& val)
{
	FCOImpl::getAttribute("resourceType")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentLibImpl::getORBServices() 
{
	return FCOImpl::getAttribute("ORBServices")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentLibImpl::getlibraryexport() 
{
	return FCOImpl::getAttribute("libraryexport")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentLibImpl::getsharedname() 
{
	return FCOImpl::getAttribute("sharedname")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ComponentLibImpl::setORBServices( const std::string& val)
{
	FCOImpl::getAttribute("ORBServices")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ComponentLibImpl::setlibraryexport( const std::string& val)
{
	FCOImpl::getAttribute("libraryexport")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ComponentLibImpl::setsharedname( const std::string& val)
{
	FCOImpl::getAttribute("sharedname")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long ThreadPoolImpl::getmax_buffer_size() 
{
	return FCOImpl::getAttribute("max_buffer_size")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long ThreadPoolImpl::getmax_buffered_requests() 
{
	return FCOImpl::getAttribute("max_buffered_requests")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long ThreadPoolImpl::getstacksize() 
{
	return FCOImpl::getAttribute("stacksize")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
bool ThreadPoolImpl::isallow_request_buffering() 
{
	return FCOImpl::getAttribute("allow_request_buffering")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolImpl::setallow_request_buffering( bool val)
{
	FCOImpl::getAttribute("allow_request_buffering")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolImpl::setmax_buffer_size( const long val)
{
	FCOImpl::getAttribute("max_buffer_size")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolImpl::setmax_buffered_requests( const long val)
{
	FCOImpl::getAttribute("max_buffered_requests")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolImpl::setstacksize( const long val)
{
	FCOImpl::getAttribute("stacksize")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
bool ThreadPoolWithLanesImpl::isallow_borrowing() 
{
	return FCOImpl::getAttribute("allow_borrowing")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolWithLanesImpl::setallow_borrowing( bool val)
{
	FCOImpl::getAttribute("allow_borrowing")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string RequirementBaseImpl::getresourceType() 
{
	return FCOImpl::getAttribute("resourceType")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void RequirementBaseImpl::setresourceType( const std::string& val)
{
	FCOImpl::getAttribute("resourceType")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
ImplementationRequirementImpl::ResourceUsageKind_Type ImplementationRequirementImpl::getResourceUsageKind()
{
	std::string val = FCOImpl::getAttribute("ResourceUsageKind")->getStringValue();

	if ( val == "None") return None_ResourceUsageKind_Type;
	else if ( val == "InstanceUsesResource") return InstanceUsesResource_ResourceUsageKind_Type;
	else if ( val == "ResourceUsesInstance") return ResourceUsesInstance_ResourceUsageKind_Type;
	else if ( val == "PortUsesResource") return PortUsesResource_ResourceUsageKind_Type;
	else if ( val == "ResourceUsesPort") return ResourceUsesPort_ResourceUsageKind_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
std::string ImplementationRequirementImpl::getcomponentPort() 
{
	return FCOImpl::getAttribute("componentPort")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ImplementationRequirementImpl::getresourcePort() 
{
	return FCOImpl::getAttribute("resourcePort")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationRequirementImpl::setResourceUsageKind( ImplementationRequirementImpl::ResourceUsageKind_Type val)
{
	std::string str_val = "";

	if ( val == None_ResourceUsageKind_Type) str_val = "None";
	else if ( val == InstanceUsesResource_ResourceUsageKind_Type) str_val = "InstanceUsesResource";
	else if ( val == ResourceUsesInstance_ResourceUsageKind_Type) str_val = "ResourceUsesInstance";
	else if ( val == PortUsesResource_ResourceUsageKind_Type) str_val = "PortUsesResource";
	else if ( val == ResourceUsesPort_ResourceUsageKind_Type) str_val = "ResourceUsesPort";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ResourceUsageKind")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationRequirementImpl::setcomponentPort( const std::string& val)
{
	FCOImpl::getAttribute("componentPort")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationRequirementImpl::setresourcePort( const std::string& val)
{
	FCOImpl::getAttribute("resourcePort")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string MetricsBaseImpl::getfileName() 
{
	return FCOImpl::getAttribute("fileName")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
long MetricsBaseImpl::getiterations() 
{
	return FCOImpl::getAttribute("iterations")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long MetricsBaseImpl::getpriority() 
{
	return FCOImpl::getAttribute("priority")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long MetricsBaseImpl::getrate() 
{
	return FCOImpl::getAttribute("rate")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
MetricsBaseImpl::resolution_Type MetricsBaseImpl::getresolution()
{
	std::string val = FCOImpl::getAttribute("resolution")->getStringValue();

	if ( val == "seconds") return seconds_resolution_Type;
	else if ( val == "miliseconds") return miliseconds_resolution_Type;
	else if ( val == "microseconds") return microseconds_resolution_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
long MetricsBaseImpl::getwarmup() 
{
	return FCOImpl::getAttribute("warmup")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void MetricsBaseImpl::setfileName( const std::string& val)
{
	FCOImpl::getAttribute("fileName")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void MetricsBaseImpl::setiterations( const long val)
{
	FCOImpl::getAttribute("iterations")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void MetricsBaseImpl::setpriority( const long val)
{
	FCOImpl::getAttribute("priority")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void MetricsBaseImpl::setrate( const long val)
{
	FCOImpl::getAttribute("rate")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void MetricsBaseImpl::setresolution( MetricsBaseImpl::resolution_Type val)
{
	std::string str_val = "";

	if ( val == seconds_resolution_Type) str_val = "seconds";
	else if ( val == miliseconds_resolution_Type) str_val = "miliseconds";
	else if ( val == microseconds_resolution_Type) str_val = "microseconds";
	else throw("None of the possible items");

	FCOImpl::getAttribute("resolution")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void MetricsBaseImpl::setwarmup( const long val)
{
	FCOImpl::getAttribute("warmup")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string RequirementSatisfierImpl::getresourceType() 
{
	return FCOImpl::getAttribute("resourceType")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void RequirementSatisfierImpl::setresourceType( const std::string& val)
{
	FCOImpl::getAttribute("resourceType")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentImplementationImpl::getUUID() 
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentImplementationImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ComponentImplementationImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ComponentImplementationImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string DeploymentPlanImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void DeploymentPlanImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string DomainImpl::getUUID() 
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string DomainImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void DomainImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void DomainImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string PropertyImpl::getDataValue() 
{
	return FCOImpl::getAttribute("DataValue")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void PropertyImpl::setDataValue( const std::string& val)
{
	FCOImpl::getAttribute("DataValue")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
bool QoSContextImpl::isisQoSObservation() 
{
	return FCOImpl::getAttribute("isQoSObservation")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void QoSContextImpl::setisQoSObservation( bool val)
{
	FCOImpl::getAttribute("isQoSObservation")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ResourceImpl::getresourceType() 
{
	return FCOImpl::getAttribute("resourceType")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ResourceImpl::setresourceType( const std::string& val)
{
	FCOImpl::getAttribute("resourceType")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string SatisfierPropertyImpl::getDataValue() 
{
	return FCOImpl::getAttribute("DataValue")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
SatisfierPropertyImpl::SatisfierPropertyKind_Type SatisfierPropertyImpl::getSatisfierPropertyKind()
{
	std::string val = FCOImpl::getAttribute("SatisfierPropertyKind")->getStringValue();

	if ( val == "Quantity") return Quantity_SatisfierPropertyKind_Type;
	else if ( val == "Capacity") return Capacity_SatisfierPropertyKind_Type;
	else if ( val == "Minimum") return Minimum_SatisfierPropertyKind_Type;
	else if ( val == "Maximum") return Maximum_SatisfierPropertyKind_Type;
	else if ( val == "Selection") return Selection_SatisfierPropertyKind_Type;
	else if ( val == "Attribute") return Attribute_SatisfierPropertyKind_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void SatisfierPropertyImpl::setDataValue( const std::string& val)
{
	FCOImpl::getAttribute("DataValue")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void SatisfierPropertyImpl::setSatisfierPropertyKind( SatisfierPropertyImpl::SatisfierPropertyKind_Type val)
{
	std::string str_val = "";

	if ( val == Quantity_SatisfierPropertyKind_Type) str_val = "Quantity";
	else if ( val == Capacity_SatisfierPropertyKind_Type) str_val = "Capacity";
	else if ( val == Minimum_SatisfierPropertyKind_Type) str_val = "Minimum";
	else if ( val == Maximum_SatisfierPropertyKind_Type) str_val = "Maximum";
	else if ( val == Selection_SatisfierPropertyKind_Type) str_val = "Selection";
	else if ( val == Attribute_SatisfierPropertyKind_Type) str_val = "Attribute";
	else throw("None of the possible items");

	FCOImpl::getAttribute("SatisfierPropertyKind")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
long FixedIterationBenchmarksImpl::getbenchmarkIterations() 
{
	return FCOImpl::getAttribute("benchmarkIterations")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void FixedIterationBenchmarksImpl::setbenchmarkIterations( const long val)
{
	FCOImpl::getAttribute("benchmarkIterations")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long PeriodicBenchmarksImpl::gettimeperiod() 
{
	return FCOImpl::getAttribute("timeperiod")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void PeriodicBenchmarksImpl::settimeperiod( const long val)
{
	FCOImpl::getAttribute("timeperiod")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
QoSConstraintImpl::Qualification_Type QoSConstraintImpl::getQualification()
{
	std::string val = FCOImpl::getAttribute("Qualification")->getStringValue();

	if ( val == "Gaurantee") return Gaurantee_Qualification_Type;
	else if ( val == "BestEffort") return BestEffort_Qualification_Type;
	else if ( val == "ThresholdBestEffort") return ThresholdBestEffort_Qualification_Type;
	else if ( val == "CompulsoryBestEffort") return CompulsoryBestEffort_Qualification_Type;
	else if ( val == "None") return None_Qualification_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void QoSConstraintImpl::setQualification( QoSConstraintImpl::Qualification_Type val)
{
	std::string str_val = "";

	if ( val == Gaurantee_Qualification_Type) str_val = "Gaurantee";
	else if ( val == BestEffort_Qualification_Type) str_val = "BestEffort";
	else if ( val == ThresholdBestEffort_Qualification_Type) str_val = "ThresholdBestEffort";
	else if ( val == CompulsoryBestEffort_Qualification_Type) str_val = "CompulsoryBestEffort";
	else if ( val == None_Qualification_Type) str_val = "None";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Qualification")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentPackageImpl::getUUID() 
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentPackageImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ComponentPackageImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ComponentPackageImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long ConnectionBandImpl::gethigh() 
{
	return FCOImpl::getAttribute("high")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long ConnectionBandImpl::getlow() 
{
	return FCOImpl::getAttribute("low")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void ConnectionBandImpl::sethigh( const long val)
{
	FCOImpl::getAttribute("high")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ConnectionBandImpl::setlow( const long val)
{
	FCOImpl::getAttribute("low")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string EnvironmentConfImpl::getCmdLineOptions() 
{
	return FCOImpl::getAttribute("CmdLineOptions")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string EnvironmentConfImpl::getSvcConf() 
{
	return FCOImpl::getAttribute("SvcConf")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void EnvironmentConfImpl::setCmdLineOptions( const std::string& val)
{
	FCOImpl::getAttribute("CmdLineOptions")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void EnvironmentConfImpl::setSvcConf( const std::string& val)
{
	FCOImpl::getAttribute("SvcConf")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ExternalReferenceEndPointImpl::getlocation() 
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ExternalReferenceEndPointImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ImplementationArtifactImpl::getUUID() 
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ImplementationArtifactImpl::getconfiguration() 
{
	return FCOImpl::getAttribute("configuration")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ImplementationArtifactImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ImplementationArtifactImpl::getlocation() 
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationArtifactImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationArtifactImpl::setconfiguration( const std::string& val)
{
	FCOImpl::getAttribute("configuration")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationArtifactImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationArtifactImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ImplementationDependencyImpl::getrequiredType() 
{
	return FCOImpl::getAttribute("requiredType")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ImplementationDependencyImpl::setrequiredType( const std::string& val)
{
	FCOImpl::getAttribute("requiredType")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long RT_InfoImpl::getcached_execution_time() 
{
	return FCOImpl::getAttribute("cached_execution_time")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
RT_InfoImpl::criticality_Type RT_InfoImpl::getcriticality()
{
	std::string val = FCOImpl::getAttribute("criticality")->getStringValue();

	if ( val == "VERY_LOW_CRITICALITY") return VERY_LOW_CRITICALITY_criticality_Type;
	else if ( val == "LOW_CRITICALITY") return LOW_CRITICALITY_criticality_Type;
	else if ( val == "MEDIUM_CRITICALITY") return MEDIUM_CRITICALITY_criticality_Type;
	else if ( val == "HIGH_CRITICALITY") return HIGH_CRITICALITY_criticality_Type;
	else if ( val == "VERY_HIGH_CRITICALITY") return VERY_HIGH_CRITICALITY_criticality_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RT_InfoImpl::enabled_Type RT_InfoImpl::getenabled()
{
	std::string val = FCOImpl::getAttribute("enabled")->getStringValue();

	if ( val == "DEPENDENCY_DISABLED") return DEPENDENCY_DISABLED_enabled_Type;
	else if ( val == "DEPENDENCY_ENABLED") return DEPENDENCY_ENABLED_enabled_Type;
	else if ( val == "DEPENDENCY_NON_VOLATILE") return DEPENDENCY_NON_VOLATILE_enabled_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
std::string RT_InfoImpl::getentry_point() 
{
	return FCOImpl::getAttribute("entry_point")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
RT_InfoImpl::importance_Type RT_InfoImpl::getimportance()
{
	std::string val = FCOImpl::getAttribute("importance")->getStringValue();

	if ( val == "VERY_LOW_IMPORTANCE") return VERY_LOW_IMPORTANCE_importance_Type;
	else if ( val == "LOW_IMPORTANCE") return LOW_IMPORTANCE_importance_Type;
	else if ( val == "MEDIUM_IMPORTANCE") return MEDIUM_IMPORTANCE_importance_Type;
	else if ( val == "HIGH_IMPORTANCE") return HIGH_IMPORTANCE_importance_Type;
	else if ( val == "VERY_HIGH_IMPORTANCE") return VERY_HIGH_IMPORTANCE_importance_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RT_InfoImpl::info_type_Type RT_InfoImpl::getinfo_type()
{
	std::string val = FCOImpl::getAttribute("info_type")->getStringValue();

	if ( val == "OPERATION") return OPERATION_info_type_Type;
	else if ( val == "CONJUNCTION") return CONJUNCTION_info_type_Type;
	else if ( val == "DISJUNCTION") return DISJUNCTION_info_type_Type;
	else if ( val == "REMOTE_DEPENDANT") return REMOTE_DEPENDANT_info_type_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
long RT_InfoImpl::getperiod() 
{
	return FCOImpl::getAttribute("period")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long RT_InfoImpl::getquantum() 
{
	return FCOImpl::getAttribute("quantum")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long RT_InfoImpl::getthreads() 
{
	return FCOImpl::getAttribute("threads")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long RT_InfoImpl::gettypical_execution_time() 
{
	return FCOImpl::getAttribute("typical_execution_time")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long RT_InfoImpl::getworst_case_execution_time() 
{
	return FCOImpl::getAttribute("worst_case_execution_time")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setcached_execution_time( const long val)
{
	FCOImpl::getAttribute("cached_execution_time")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setcriticality( RT_InfoImpl::criticality_Type val)
{
	std::string str_val = "";

	if ( val == VERY_LOW_CRITICALITY_criticality_Type) str_val = "VERY_LOW_CRITICALITY";
	else if ( val == LOW_CRITICALITY_criticality_Type) str_val = "LOW_CRITICALITY";
	else if ( val == MEDIUM_CRITICALITY_criticality_Type) str_val = "MEDIUM_CRITICALITY";
	else if ( val == HIGH_CRITICALITY_criticality_Type) str_val = "HIGH_CRITICALITY";
	else if ( val == VERY_HIGH_CRITICALITY_criticality_Type) str_val = "VERY_HIGH_CRITICALITY";
	else throw("None of the possible items");

	FCOImpl::getAttribute("criticality")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setenabled( RT_InfoImpl::enabled_Type val)
{
	std::string str_val = "";

	if ( val == DEPENDENCY_DISABLED_enabled_Type) str_val = "DEPENDENCY_DISABLED";
	else if ( val == DEPENDENCY_ENABLED_enabled_Type) str_val = "DEPENDENCY_ENABLED";
	else if ( val == DEPENDENCY_NON_VOLATILE_enabled_Type) str_val = "DEPENDENCY_NON_VOLATILE";
	else throw("None of the possible items");

	FCOImpl::getAttribute("enabled")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setentry_point( const std::string& val)
{
	FCOImpl::getAttribute("entry_point")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setimportance( RT_InfoImpl::importance_Type val)
{
	std::string str_val = "";

	if ( val == VERY_LOW_IMPORTANCE_importance_Type) str_val = "VERY_LOW_IMPORTANCE";
	else if ( val == LOW_IMPORTANCE_importance_Type) str_val = "LOW_IMPORTANCE";
	else if ( val == MEDIUM_IMPORTANCE_importance_Type) str_val = "MEDIUM_IMPORTANCE";
	else if ( val == HIGH_IMPORTANCE_importance_Type) str_val = "HIGH_IMPORTANCE";
	else if ( val == VERY_HIGH_IMPORTANCE_importance_Type) str_val = "VERY_HIGH_IMPORTANCE";
	else throw("None of the possible items");

	FCOImpl::getAttribute("importance")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setinfo_type( RT_InfoImpl::info_type_Type val)
{
	std::string str_val = "";

	if ( val == OPERATION_info_type_Type) str_val = "OPERATION";
	else if ( val == CONJUNCTION_info_type_Type) str_val = "CONJUNCTION";
	else if ( val == DISJUNCTION_info_type_Type) str_val = "DISJUNCTION";
	else if ( val == REMOTE_DEPENDANT_info_type_Type) str_val = "REMOTE_DEPENDANT";
	else throw("None of the possible items");

	FCOImpl::getAttribute("info_type")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setperiod( const long val)
{
	FCOImpl::getAttribute("period")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setquantum( const long val)
{
	FCOImpl::getAttribute("quantum")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setthreads( const long val)
{
	FCOImpl::getAttribute("threads")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::settypical_execution_time( const long val)
{
	FCOImpl::getAttribute("typical_execution_time")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RT_InfoImpl::setworst_case_execution_time( const long val)
{
	FCOImpl::getAttribute("worst_case_execution_time")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string PackageConfigurationImpl::getUUID() 
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string PackageConfigurationImpl::getlabel() 
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void PackageConfigurationImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void PackageConfigurationImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string PriorityModelPolicyImpl::getPriority() 
{
	return FCOImpl::getAttribute("Priority")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
PriorityModelPolicyImpl::PriorityModel_Type PriorityModelPolicyImpl::getPriorityModel()
{
	std::string val = FCOImpl::getAttribute("PriorityModel")->getStringValue();

	if ( val == "CLIENT_PROPAGATED") return CLIENT_PROPAGATED_PriorityModel_Type;
	else if ( val == "SERVER_DECLARED") return SERVER_DECLARED_PriorityModel_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void PriorityModelPolicyImpl::setPriority( const std::string& val)
{
	FCOImpl::getAttribute("Priority")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void PriorityModelPolicyImpl::setPriorityModel( PriorityModelPolicyImpl::PriorityModel_Type val)
{
	std::string str_val = "";

	if ( val == CLIENT_PROPAGATED_PriorityModel_Type) str_val = "CLIENT_PROPAGATED";
	else if ( val == SERVER_DECLARED_PriorityModel_Type) str_val = "SERVER_DECLARED";
	else throw("None of the possible items");

	FCOImpl::getAttribute("PriorityModel")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
QoSDimensionImpl::direction_Type QoSDimensionImpl::getdirection()
{
	std::string val = FCOImpl::getAttribute("direction")->getStringValue();

	if ( val == "Increasing") return Increasing_direction_Type;
	else if ( val == "Decreasing") return Decreasing_direction_Type;
	else if ( val == "Undefined") return Undefined_direction_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
QoSDimensionImpl::statisticalQualifier_Type QoSDimensionImpl::getstatisticalQualifier()
{
	std::string val = FCOImpl::getAttribute("statisticalQualifier")->getStringValue();

	if ( val == "MaxValue") return MaxValue_statisticalQualifier_Type;
	else if ( val == "MinValue") return MinValue_statisticalQualifier_Type;
	else if ( val == "Range") return Range_statisticalQualifier_Type;
	else if ( val == "Mean") return Mean_statisticalQualifier_Type;
	else if ( val == "Variance") return Variance_statisticalQualifier_Type;
	else if ( val == "StdDev") return StdDev_statisticalQualifier_Type;
	else if ( val == "Percentile") return Percentile_statisticalQualifier_Type;
	else if ( val == "Frequency") return Frequency_statisticalQualifier_Type;
	else if ( val == "Moment") return Moment_statisticalQualifier_Type;
	else if ( val == "Distribution") return Distribution_statisticalQualifier_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
std::string QoSDimensionImpl::getunits() 
{
	return FCOImpl::getAttribute("units")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void QoSDimensionImpl::setdirection( QoSDimensionImpl::direction_Type val)
{
	std::string str_val = "";

	if ( val == Increasing_direction_Type) str_val = "Increasing";
	else if ( val == Decreasing_direction_Type) str_val = "Decreasing";
	else if ( val == Undefined_direction_Type) str_val = "Undefined";
	else throw("None of the possible items");

	FCOImpl::getAttribute("direction")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void QoSDimensionImpl::setstatisticalQualifier( QoSDimensionImpl::statisticalQualifier_Type val)
{
	std::string str_val = "";

	if ( val == MaxValue_statisticalQualifier_Type) str_val = "MaxValue";
	else if ( val == MinValue_statisticalQualifier_Type) str_val = "MinValue";
	else if ( val == Range_statisticalQualifier_Type) str_val = "Range";
	else if ( val == Mean_statisticalQualifier_Type) str_val = "Mean";
	else if ( val == Variance_statisticalQualifier_Type) str_val = "Variance";
	else if ( val == StdDev_statisticalQualifier_Type) str_val = "StdDev";
	else if ( val == Percentile_statisticalQualifier_Type) str_val = "Percentile";
	else if ( val == Frequency_statisticalQualifier_Type) str_val = "Frequency";
	else if ( val == Moment_statisticalQualifier_Type) str_val = "Moment";
	else if ( val == Distribution_statisticalQualifier_Type) str_val = "Distribution";
	else throw("None of the possible items");

	FCOImpl::getAttribute("statisticalQualifier")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void QoSDimensionImpl::setunits( const std::string& val)
{
	FCOImpl::getAttribute("units")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string QoSDimensionSlotImpl::getvalue() 
{
	return FCOImpl::getAttribute("value")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void QoSDimensionSlotImpl::setvalue( const std::string& val)
{
	FCOImpl::getAttribute("value")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string QoSParameterImpl::getvalue() 
{
	return FCOImpl::getAttribute("value")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void QoSParameterImpl::setvalue( const std::string& val)
{
	FCOImpl::getAttribute("value")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECConsumerControl_Type RTEC_Resource_FactoryImpl::getECConsumerControl()
{
	std::string val = FCOImpl::getAttribute("ECConsumerControl")->getStringValue();

	if ( val == "null (default)") return null__default__ECConsumerControl_Type;
	else if ( val == "reactive") return reactive_ECConsumerControl_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
long RTEC_Resource_FactoryImpl::getECConsumerControlPeriod() 
{
	return FCOImpl::getAttribute("ECConsumerControlPeriod")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECConsumerLock_Type RTEC_Resource_FactoryImpl::getECConsumerLock()
{
	std::string val = FCOImpl::getAttribute("ECConsumerLock")->getStringValue();

	if ( val == "null") return null_ECConsumerLock_Type;
	else if ( val == "thread (default)") return thread__default__ECConsumerLock_Type;
	else if ( val == "recursive") return recursive_ECConsumerLock_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECDispatching_Type RTEC_Resource_FactoryImpl::getECDispatching()
{
	std::string val = FCOImpl::getAttribute("ECDispatching")->getStringValue();

	if ( val == "reactive (default)") return reactive__default__ECDispatching_Type;
	else if ( val == "priority") return priority_ECDispatching_Type;
	else if ( val == "mt") return mt_ECDispatching_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
long RTEC_Resource_FactoryImpl::getECDispatchingThreads() 
{
	return FCOImpl::getAttribute("ECDispatchingThreads")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECFiltering_Type RTEC_Resource_FactoryImpl::getECFiltering()
{
	std::string val = FCOImpl::getAttribute("ECFiltering")->getStringValue();

	if ( val == "null") return null_ECFiltering_Type;
	else if ( val == "basic (default)") return basic__default__ECFiltering_Type;
	else if ( val == "prefix") return prefix_ECFiltering_Type;
	else if ( val == "priority") return priority_ECFiltering_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECObserver_Type RTEC_Resource_FactoryImpl::getECObserver()
{
	std::string val = FCOImpl::getAttribute("ECObserver")->getStringValue();

	if ( val == "null (default)") return null__default__ECObserver_Type;
	else if ( val == "basic") return basic_ECObserver_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionFlag_Type RTEC_Resource_FactoryImpl::getECProxyPushConsumerCollectionFlag()
{
	std::string val = FCOImpl::getAttribute("ECProxyPushConsumerCollectionFlag")->getStringValue();

	if ( val == "list (default)") return list__default__ECProxyPushConsumerCollectionFlag_Type;
	else if ( val == "rb_tree") return rb_tree_ECProxyPushConsumerCollectionFlag_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionIterator_Type RTEC_Resource_FactoryImpl::getECProxyPushConsumerCollectionIterator()
{
	std::string val = FCOImpl::getAttribute("ECProxyPushConsumerCollectionIterator")->getStringValue();

	if ( val == "copy_on_read") return copy_on_read_ECProxyPushConsumerCollectionIterator_Type;
	else if ( val == "copy_on_write") return copy_on_write_ECProxyPushConsumerCollectionIterator_Type;
	else if ( val == "delayed") return delayed_ECProxyPushConsumerCollectionIterator_Type;
	else if ( val == "immediate (default)") return immediate__default__ECProxyPushConsumerCollectionIterator_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionSynch_Type RTEC_Resource_FactoryImpl::getECProxyPushConsumerCollectionSynch()
{
	std::string val = FCOImpl::getAttribute("ECProxyPushConsumerCollectionSynch")->getStringValue();

	if ( val == "mt (default)") return mt__default__ECProxyPushConsumerCollectionSynch_Type;
	else if ( val == "st") return st_ECProxyPushConsumerCollectionSynch_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionFlag_Type RTEC_Resource_FactoryImpl::getECProxyPushSupplierCollectionFlag()
{
	std::string val = FCOImpl::getAttribute("ECProxyPushSupplierCollectionFlag")->getStringValue();

	if ( val == "list (default)") return list__default__ECProxyPushSupplierCollectionFlag_Type;
	else if ( val == "rb_tree") return rb_tree_ECProxyPushSupplierCollectionFlag_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionIterator_Type RTEC_Resource_FactoryImpl::getECProxyPushSupplierCollectionIterator()
{
	std::string val = FCOImpl::getAttribute("ECProxyPushSupplierCollectionIterator")->getStringValue();

	if ( val == "copy_on_read") return copy_on_read_ECProxyPushSupplierCollectionIterator_Type;
	else if ( val == "copy_on_write") return copy_on_write_ECProxyPushSupplierCollectionIterator_Type;
	else if ( val == "delayed") return delayed_ECProxyPushSupplierCollectionIterator_Type;
	else if ( val == "immediate (default)") return immediate__default__ECProxyPushSupplierCollectionIterator_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionSynch_Type RTEC_Resource_FactoryImpl::getECProxyPushSupplierCollectionSynch()
{
	std::string val = FCOImpl::getAttribute("ECProxyPushSupplierCollectionSynch")->getStringValue();

	if ( val == "mt (default)") return mt__default__ECProxyPushSupplierCollectionSynch_Type;
	else if ( val == "st") return st_ECProxyPushSupplierCollectionSynch_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECScheduling_Type RTEC_Resource_FactoryImpl::getECScheduling()
{
	std::string val = FCOImpl::getAttribute("ECScheduling")->getStringValue();

	if ( val == "null (default)") return null__default__ECScheduling_Type;
	else if ( val == "priority") return priority_ECScheduling_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECSupplierControl_Type RTEC_Resource_FactoryImpl::getECSupplierControl()
{
	std::string val = FCOImpl::getAttribute("ECSupplierControl")->getStringValue();

	if ( val == "null (default)") return null__default__ECSupplierControl_Type;
	else if ( val == "reactive") return reactive_ECSupplierControl_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
long RTEC_Resource_FactoryImpl::getECSupplierControlPeriod() 
{
	return FCOImpl::getAttribute("ECSupplierControlPeriod")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECSupplierFiltering_Type RTEC_Resource_FactoryImpl::getECSupplierFiltering()
{
	std::string val = FCOImpl::getAttribute("ECSupplierFiltering")->getStringValue();

	if ( val == "null") return null_ECSupplierFiltering_Type;
	else if ( val == "per-supplier (default)") return per_supplier__default__ECSupplierFiltering_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECSupplierLock_Type RTEC_Resource_FactoryImpl::getECSupplierLock()
{
	std::string val = FCOImpl::getAttribute("ECSupplierLock")->getStringValue();

	if ( val == "null") return null_ECSupplierLock_Type;
	else if ( val == "thread (default)") return thread__default__ECSupplierLock_Type;
	else if ( val == "recursive") return recursive_ECSupplierLock_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_FactoryImpl::ECTimeout_Type RTEC_Resource_FactoryImpl::getECTimeout()
{
	std::string val = FCOImpl::getAttribute("ECTimeout")->getStringValue();

	if ( val == "reactive (default)") return reactive__default__ECTimeout_Type;
	else if ( val == "priority") return priority_ECTimeout_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
std::string RTEC_Resource_FactoryImpl::getECUseORBId() 
{
	return FCOImpl::getAttribute("ECUseORBId")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECConsumerControl( RTEC_Resource_FactoryImpl::ECConsumerControl_Type val)
{
	std::string str_val = "";

	if ( val == null__default__ECConsumerControl_Type) str_val = "null (default)";
	else if ( val == reactive_ECConsumerControl_Type) str_val = "reactive";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECConsumerControl")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECConsumerControlPeriod( const long val)
{
	FCOImpl::getAttribute("ECConsumerControlPeriod")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECConsumerLock( RTEC_Resource_FactoryImpl::ECConsumerLock_Type val)
{
	std::string str_val = "";

	if ( val == null_ECConsumerLock_Type) str_val = "null";
	else if ( val == thread__default__ECConsumerLock_Type) str_val = "thread (default)";
	else if ( val == recursive_ECConsumerLock_Type) str_val = "recursive";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECConsumerLock")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECDispatching( RTEC_Resource_FactoryImpl::ECDispatching_Type val)
{
	std::string str_val = "";

	if ( val == reactive__default__ECDispatching_Type) str_val = "reactive (default)";
	else if ( val == priority_ECDispatching_Type) str_val = "priority";
	else if ( val == mt_ECDispatching_Type) str_val = "mt";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECDispatching")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECDispatchingThreads( const long val)
{
	FCOImpl::getAttribute("ECDispatchingThreads")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECFiltering( RTEC_Resource_FactoryImpl::ECFiltering_Type val)
{
	std::string str_val = "";

	if ( val == null_ECFiltering_Type) str_val = "null";
	else if ( val == basic__default__ECFiltering_Type) str_val = "basic (default)";
	else if ( val == prefix_ECFiltering_Type) str_val = "prefix";
	else if ( val == priority_ECFiltering_Type) str_val = "priority";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECFiltering")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECObserver( RTEC_Resource_FactoryImpl::ECObserver_Type val)
{
	std::string str_val = "";

	if ( val == null__default__ECObserver_Type) str_val = "null (default)";
	else if ( val == basic_ECObserver_Type) str_val = "basic";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECObserver")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECProxyPushConsumerCollectionFlag( RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionFlag_Type val)
{
	std::string str_val = "";

	if ( val == list__default__ECProxyPushConsumerCollectionFlag_Type) str_val = "list (default)";
	else if ( val == rb_tree_ECProxyPushConsumerCollectionFlag_Type) str_val = "rb_tree";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECProxyPushConsumerCollectionFlag")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECProxyPushConsumerCollectionIterator( RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionIterator_Type val)
{
	std::string str_val = "";

	if ( val == copy_on_read_ECProxyPushConsumerCollectionIterator_Type) str_val = "copy_on_read";
	else if ( val == copy_on_write_ECProxyPushConsumerCollectionIterator_Type) str_val = "copy_on_write";
	else if ( val == delayed_ECProxyPushConsumerCollectionIterator_Type) str_val = "delayed";
	else if ( val == immediate__default__ECProxyPushConsumerCollectionIterator_Type) str_val = "immediate (default)";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECProxyPushConsumerCollectionIterator")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECProxyPushConsumerCollectionSynch( RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionSynch_Type val)
{
	std::string str_val = "";

	if ( val == mt__default__ECProxyPushConsumerCollectionSynch_Type) str_val = "mt (default)";
	else if ( val == st_ECProxyPushConsumerCollectionSynch_Type) str_val = "st";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECProxyPushConsumerCollectionSynch")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECProxyPushSupplierCollectionFlag( RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionFlag_Type val)
{
	std::string str_val = "";

	if ( val == list__default__ECProxyPushSupplierCollectionFlag_Type) str_val = "list (default)";
	else if ( val == rb_tree_ECProxyPushSupplierCollectionFlag_Type) str_val = "rb_tree";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECProxyPushSupplierCollectionFlag")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECProxyPushSupplierCollectionIterator( RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionIterator_Type val)
{
	std::string str_val = "";

	if ( val == copy_on_read_ECProxyPushSupplierCollectionIterator_Type) str_val = "copy_on_read";
	else if ( val == copy_on_write_ECProxyPushSupplierCollectionIterator_Type) str_val = "copy_on_write";
	else if ( val == delayed_ECProxyPushSupplierCollectionIterator_Type) str_val = "delayed";
	else if ( val == immediate__default__ECProxyPushSupplierCollectionIterator_Type) str_val = "immediate (default)";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECProxyPushSupplierCollectionIterator")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECProxyPushSupplierCollectionSynch( RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionSynch_Type val)
{
	std::string str_val = "";

	if ( val == mt__default__ECProxyPushSupplierCollectionSynch_Type) str_val = "mt (default)";
	else if ( val == st_ECProxyPushSupplierCollectionSynch_Type) str_val = "st";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECProxyPushSupplierCollectionSynch")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECScheduling( RTEC_Resource_FactoryImpl::ECScheduling_Type val)
{
	std::string str_val = "";

	if ( val == null__default__ECScheduling_Type) str_val = "null (default)";
	else if ( val == priority_ECScheduling_Type) str_val = "priority";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECScheduling")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECSupplierControl( RTEC_Resource_FactoryImpl::ECSupplierControl_Type val)
{
	std::string str_val = "";

	if ( val == null__default__ECSupplierControl_Type) str_val = "null (default)";
	else if ( val == reactive_ECSupplierControl_Type) str_val = "reactive";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECSupplierControl")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECSupplierControlPeriod( const long val)
{
	FCOImpl::getAttribute("ECSupplierControlPeriod")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECSupplierFiltering( RTEC_Resource_FactoryImpl::ECSupplierFiltering_Type val)
{
	std::string str_val = "";

	if ( val == null_ECSupplierFiltering_Type) str_val = "null";
	else if ( val == per_supplier__default__ECSupplierFiltering_Type) str_val = "per-supplier (default)";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECSupplierFiltering")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECSupplierLock( RTEC_Resource_FactoryImpl::ECSupplierLock_Type val)
{
	std::string str_val = "";

	if ( val == null_ECSupplierLock_Type) str_val = "null";
	else if ( val == thread__default__ECSupplierLock_Type) str_val = "thread (default)";
	else if ( val == recursive_ECSupplierLock_Type) str_val = "recursive";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECSupplierLock")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECTimeout( RTEC_Resource_FactoryImpl::ECTimeout_Type val)
{
	std::string str_val = "";

	if ( val == reactive__default__ECTimeout_Type) str_val = "reactive (default)";
	else if ( val == priority_ECTimeout_Type) str_val = "priority";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECTimeout")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void RTEC_Resource_FactoryImpl::setECUseORBId( const std::string& val)
{
	FCOImpl::getAttribute("ECUseORBId")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
long ThreadPoolLaneImpl::getdynamic_threads() 
{
	return FCOImpl::getAttribute("dynamic_threads")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long ThreadPoolLaneImpl::getlane_priority() 
{
	return FCOImpl::getAttribute("lane_priority")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long ThreadPoolLaneImpl::getstatic_threads() 
{
	return FCOImpl::getAttribute("static_threads")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolLaneImpl::setdynamic_threads( const long val)
{
	FCOImpl::getAttribute("dynamic_threads")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolLaneImpl::setlane_priority( const long val)
{
	FCOImpl::getAttribute("lane_priority")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ThreadPoolLaneImpl::setstatic_threads( const long val)
{
	FCOImpl::getAttribute("static_threads")->setIntegerValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ImplementationArtifact
//********************************************************************************
ImplementationArtifact ArtifactDependencyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ImplementationArtifact
//********************************************************************************
ImplementationArtifact ArtifactDependencyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ImplementationArtifactReference
//********************************************************************************
ImplementationArtifactReference ArtifactDependsOnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ImplementationArtifactReference sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifactReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ImplementationArtifact
//********************************************************************************
ImplementationArtifact ArtifactDependsOnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Requirement
//********************************************************************************
Requirement ArtifactDeployRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Requirement sp( ce);
	if ( sp)
		return sp;

	Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ImplementationArtifact
//********************************************************************************
ImplementationArtifact ArtifactDeployRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property ArtifactExecParameterImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ImplementationArtifact
//********************************************************************************
ImplementationArtifact ArtifactExecParameterImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property ArtifactInfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ImplementationArtifact
//********************************************************************************
ImplementationArtifact ArtifactInfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property AssemblyConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Component
//********************************************************************************
Component AssemblyConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Component sp( ce);
	if ( sp)
		return sp;

	Component empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Requirement
//********************************************************************************
Requirement AssemblyDeployRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Requirement sp( ce);
	if ( sp)
		return sp;

	Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PublishConnector
//********************************************************************************
PublishConnector AssemblyDeployRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PublishConnector sp( ce);
	if ( sp)
		return sp;

	PublishConnector empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Requirement
//********************************************************************************
Requirement AssemblyselectRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Requirement sp( ce);
	if ( sp)
		return sp;

	Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Component
//********************************************************************************
Component AssemblyselectRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Component sp( ce);
	if ( sp)
		return sp;

	Component empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd AttributeDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd AttributeDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd AttributeMappingDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd AttributeMappingDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property AttributeMappingValueImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd AttributeMappingValueImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property AttributeValueImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd AttributeValueImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to MetricsBase
//********************************************************************************
MetricsBase BenchmarkCharacteristicsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	MetricsBase sp( ce);
	if ( sp)
		return sp;

	MetricsBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to BenchmarkType
//********************************************************************************
BenchmarkType BenchmarkCharacteristicsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	BenchmarkType sp( ce);
	if ( sp)
		return sp;

	BenchmarkType empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Interconnect
//********************************************************************************
Interconnect Bridge2InterconnectImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Interconnect sp( ce);
	if ( sp)
		return sp;

	Interconnect empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Bridge
//********************************************************************************
Bridge Bridge2InterconnectImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Bridge sp( ce);
	if ( sp)
		return sp;

	Bridge empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property ComponentConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentRef
//********************************************************************************
ComponentRef ComponentConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentRef sp( ce);
	if ( sp)
		return sp;

	ComponentRef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property ComponentInfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentRef
//********************************************************************************
ComponentRef ComponentInfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentRef sp( ce);
	if ( sp)
		return sp;

	ComponentRef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to CompRef
//********************************************************************************
CompRef ComponentOperationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	CompRef sp( ce);
	if ( sp)
		return sp;

	CompRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to OperationRef
//********************************************************************************
OperationRef ComponentOperationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	OperationRef sp( ce);
	if ( sp)
		return sp;

	OperationRef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ComponentPropertyDescription
//********************************************************************************
ComponentPropertyDescription ComponentPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ComponentPropertyDescription sp( ce);
	if ( sp)
		return sp;

	ComponentPropertyDescription empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentRef
//********************************************************************************
ComponentRef ComponentPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentRef sp( ce);
	if ( sp)
		return sp;

	ComponentRef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property ConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentImplementation
//********************************************************************************
ComponentImplementation ConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	ComponentImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Edge
//********************************************************************************
Edge DstEdgeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Edge sp( ce);
	if ( sp)
		return sp;

	Edge empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd DstEdgeImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to State
//********************************************************************************
State EffectImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	State sp( ce);
	if ( sp)
		return sp;

	State empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ActionBase
//********************************************************************************
ActionBase EffectImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ActionBase sp( ce);
	if ( sp)
		return sp;

	ActionBase empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd EventSinkDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd EventSinkDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd EventSourceDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd EventSourceDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ExternalResources
//********************************************************************************
ExternalResources ExtResourceConnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ExternalResources sp( ce);
	if ( sp)
		return sp;

	ExternalResources empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentLib
//********************************************************************************
ComponentLib ExtResourceConnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentLib sp( ce);
	if ( sp)
		return sp;

	ComponentLib empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ExternalReferenceEndPoint
//********************************************************************************
ExternalReferenceEndPoint ExternalDelegateImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ExternalReferenceEndPoint sp( ce);
	if ( sp)
		return sp;

	ExternalReferenceEndPoint empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Component
//********************************************************************************
Component ExternalDelegateImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Component sp( ce);
	if ( sp)
		return sp;

	Component empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd FacetDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd FacetDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to InputAction
//********************************************************************************
InputAction FinishImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	InputAction sp( ce);
	if ( sp)
		return sp;

	InputAction empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to State
//********************************************************************************
State FinishImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	State sp( ce);
	if ( sp)
		return sp;

	State empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ComponentImplementationReference
//********************************************************************************
ComponentImplementationReference ImplementationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ComponentImplementationReference sp( ce);
	if ( sp)
		return sp;

	ComponentImplementationReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentPackage
//********************************************************************************
ComponentPackage ImplementationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentPackage sp( ce);
	if ( sp)
		return sp;

	ComponentPackage empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Capability
//********************************************************************************
Capability ImplementationCapabilityImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Capability sp( ce);
	if ( sp)
		return sp;

	Capability empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentImplementation
//********************************************************************************
ComponentImplementation ImplementationCapabilityImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	ComponentImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ImplementationDependency
//********************************************************************************
ImplementationDependency ImplementationDependsOnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ImplementationDependency sp( ce);
	if ( sp)
		return sp;

	ImplementationDependency empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentImplementation
//********************************************************************************
ComponentImplementation ImplementationDependsOnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	ComponentImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ComponentRef
//********************************************************************************
ComponentRef ImplementsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ComponentRef sp( ce);
	if ( sp)
		return sp;

	ComponentRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentImplementation
//********************************************************************************
ComponentImplementation ImplementsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	ComponentImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to RTEC_Filter_Group
//********************************************************************************
RTEC_Filter_Group Include_RTEC_Filter_GroupImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	RTEC_Filter_Group sp( ce);
	if ( sp)
		return sp;

	RTEC_Filter_Group empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to RTEC_Filter_Group
//********************************************************************************
RTEC_Filter_Group Include_RTEC_Filter_GroupImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	RTEC_Filter_Group sp( ce);
	if ( sp)
		return sp;

	RTEC_Filter_Group empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to RTEC_Filter_Group
//********************************************************************************
RTEC_Filter_Group Include_RT_InfoImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	RTEC_Filter_Group sp( ce);
	if ( sp)
		return sp;

	RTEC_Filter_Group empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to RT_Info_Param
//********************************************************************************
RT_Info_Param Include_RT_InfoImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	RT_Info_Param sp( ce);
	if ( sp)
		return sp;

	RT_Info_Param empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property InfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentImplementation
//********************************************************************************
ComponentImplementation InfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	ComponentImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to InputAction
//********************************************************************************
InputAction InputImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	InputAction sp( ce);
	if ( sp)
		return sp;

	InputAction empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to AbstractInPort
//********************************************************************************
AbstractInPort InputImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	AbstractInPort sp( ce);
	if ( sp)
		return sp;

	AbstractInPort empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to NodeReference
//********************************************************************************
NodeReference InstanceMappingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	NodeReference sp( ce);
	if ( sp)
		return sp;

	NodeReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to CollocationGroup
//********************************************************************************
CollocationGroup InstanceMappingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	CollocationGroup sp( ce);
	if ( sp)
		return sp;

	CollocationGroup empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Bridge
//********************************************************************************
Bridge Interconnect2BridgeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Bridge sp( ce);
	if ( sp)
		return sp;

	Bridge empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Interconnect
//********************************************************************************
Interconnect Interconnect2BridgeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Interconnect sp( ce);
	if ( sp)
		return sp;

	Interconnect empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Node
//********************************************************************************
Node Interconnect2NodeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Node sp( ce);
	if ( sp)
		return sp;

	Node empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Interconnect
//********************************************************************************
Interconnect Interconnect2NodeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Interconnect sp( ce);
	if ( sp)
		return sp;

	Interconnect empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Label
//********************************************************************************
Label LabelConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Label sp( ce);
	if ( sp)
		return sp;

	Label empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Member
//********************************************************************************
Member LabelConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Member sp( ce);
	if ( sp)
		return sp;

	Member empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PrivateFlag
//********************************************************************************
PrivateFlag MakeMemberPrivateImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PrivateFlag sp( ce);
	if ( sp)
		return sp;

	PrivateFlag empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Member
//********************************************************************************
Member MakeMemberPrivateImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Member sp( ce);
	if ( sp)
		return sp;

	Member empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Manageable
//********************************************************************************
Manageable ManagesComponentImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Manageable sp( ce);
	if ( sp)
		return sp;

	Manageable empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentFactory
//********************************************************************************
ComponentFactory ManagesComponentImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentFactory sp( ce);
	if ( sp)
		return sp;

	ComponentFactory empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to MetricsBase
//********************************************************************************
MetricsBase MetricConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	MetricsBase sp( ce);
	if ( sp)
		return sp;

	MetricsBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to OperationRef
//********************************************************************************
OperationRef MetricConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	OperationRef sp( ce);
	if ( sp)
		return sp;

	OperationRef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ImplementationRequirement
//********************************************************************************
ImplementationRequirement MonolithDeployRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ImplementationRequirement sp( ce);
	if ( sp)
		return sp;

	ImplementationRequirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to MonolithicImplementation
//********************************************************************************
MonolithicImplementation MonolithDeployRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	MonolithicImplementation sp( ce);
	if ( sp)
		return sp;

	MonolithicImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property MonolithExecParameterImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to MonolithicImplementation
//********************************************************************************
MonolithicImplementation MonolithExecParameterImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	MonolithicImplementation sp( ce);
	if ( sp)
		return sp;

	MonolithicImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ImplementationArtifactReference
//********************************************************************************
ImplementationArtifactReference MonolithprimaryArtifactImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ImplementationArtifactReference sp( ce);
	if ( sp)
		return sp;

	ImplementationArtifactReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to MonolithicImplementation
//********************************************************************************
MonolithicImplementation MonolithprimaryArtifactImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	MonolithicImplementation sp( ce);
	if ( sp)
		return sp;

	MonolithicImplementation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Interconnect
//********************************************************************************
Interconnect Node2InterconnectImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Interconnect sp( ce);
	if ( sp)
		return sp;

	Interconnect empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Node
//********************************************************************************
Node Node2InterconnectImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Node sp( ce);
	if ( sp)
		return sp;

	Node empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ComponentPackage
//********************************************************************************
ComponentPackage PackageConfBasePackageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ComponentPackage sp( ce);
	if ( sp)
		return sp;

	ComponentPackage empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PackageConfiguration
//********************************************************************************
PackageConfiguration PackageConfBasePackageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PackageConfiguration empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property PackageConfConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PackageConfiguration
//********************************************************************************
PackageConfiguration PackageConfConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PackageConfiguration empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ComponentPackageReference
//********************************************************************************
ComponentPackageReference PackageConfReferenceImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ComponentPackageReference sp( ce);
	if ( sp)
		return sp;

	ComponentPackageReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PackageConfiguration
//********************************************************************************
PackageConfiguration PackageConfReferenceImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PackageConfiguration empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Requirement
//********************************************************************************
Requirement PackageConfSelectRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Requirement sp( ce);
	if ( sp)
		return sp;

	Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PackageConfiguration
//********************************************************************************
PackageConfiguration PackageConfSelectRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PackageConfiguration empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PackageConfigurationReference
//********************************************************************************
PackageConfigurationReference PackageConfSpecializedConfigImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PackageConfigurationReference sp( ce);
	if ( sp)
		return sp;

	PackageConfigurationReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PackageConfiguration
//********************************************************************************
PackageConfiguration PackageConfSpecializedConfigImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PackageConfiguration empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property PackageConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentPackage
//********************************************************************************
ComponentPackage PackageConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentPackage sp( ce);
	if ( sp)
		return sp;

	ComponentPackage empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property PackageInfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentPackage
//********************************************************************************
ComponentPackage PackageInfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentPackage sp( ce);
	if ( sp)
		return sp;

	ComponentPackage empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ComponentRef
//********************************************************************************
ComponentRef PackageInterfaceImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ComponentRef sp( ce);
	if ( sp)
		return sp;

	ComponentRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentPackage
//********************************************************************************
ComponentPackage PackageInterfaceImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentPackage sp( ce);
	if ( sp)
		return sp;

	ComponentPackage empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Edge
//********************************************************************************
Edge PropertyConnectorImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Edge sp( ce);
	if ( sp)
		return sp;

	Edge empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property PropertyConnectorImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Component
//********************************************************************************
Component QoSDecorationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Component sp( ce);
	if ( sp)
		return sp;

	Component empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to QoSValue
//********************************************************************************
QoSValue QoSDecorationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	QoSValue sp( ce);
	if ( sp)
		return sp;

	QoSValue empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to QoSDimension
//********************************************************************************
QoSDimension QoSDimensionQualifierImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	QoSDimension sp( ce);
	if ( sp)
		return sp;

	QoSDimension empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to QoSDimensionSlot
//********************************************************************************
QoSDimensionSlot QoSDimensionQualifierImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	QoSDimensionSlot sp( ce);
	if ( sp)
		return sp;

	QoSDimensionSlot empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to RT_Info_Param
//********************************************************************************
RT_Info_Param RTEC_ConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	RT_Info_Param sp( ce);
	if ( sp)
		return sp;

	RT_Info_Param empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd RTEC_ConnectionImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd ReceptacleDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd ReceptacleDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to SharedResource
//********************************************************************************
SharedResource SharesImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	SharedResource sp( ce);
	if ( sp)
		return sp;

	SharedResource empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Node
//********************************************************************************
Node SharesImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Node sp( ce);
	if ( sp)
		return sp;

	Node empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd SrcEdgeImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Edge
//********************************************************************************
Edge SrcEdgeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Edge sp( ce);
	if ( sp)
		return sp;

	Edge empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to TimeProbe
//********************************************************************************
TimeProbe TimerConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	TimeProbe sp( ce);
	if ( sp)
		return sp;

	TimeProbe empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to OperationRef
//********************************************************************************
OperationRef TimerConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	OperationRef sp( ce);
	if ( sp)
		return sp;

	OperationRef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to TimeProbe
//********************************************************************************
TimeProbe TimerEventSinkConnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	TimeProbe sp( ce);
	if ( sp)
		return sp;

	TimeProbe empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to EventRef
//********************************************************************************
EventRef TimerEventSinkConnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	EventRef sp( ce);
	if ( sp)
		return sp;

	EventRef empty;
	return empty;
}


//********************************************************************************
// 
//********************************************************************************
std::string TransitionImpl::getPrecondition() 
{
	return FCOImpl::getAttribute("Precondition")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void TransitionImpl::setPrecondition( const std::string& val)
{
	FCOImpl::getAttribute("Precondition")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ActionBase
//********************************************************************************
ActionBase TransitionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ActionBase sp( ce);
	if ( sp)
		return sp;

	ActionBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to State
//********************************************************************************
State TransitionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	State sp( ce);
	if ( sp)
		return sp;

	State empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd Use_RTEC_FilterImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to RTEC_Filter_Group
//********************************************************************************
RTEC_Filter_Group Use_RTEC_FilterImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	RTEC_Filter_Group sp( ce);
	if ( sp)
		return sp;

	RTEC_Filter_Group empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to RTEC_Resource_Factory_Reference
//********************************************************************************
RTEC_Resource_Factory_Reference Use_RT_InfoImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	RTEC_Resource_Factory_Reference sp( ce);
	if ( sp)
		return sp;

	RTEC_Resource_Factory_Reference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to RT_Info_Param
//********************************************************************************
RT_Info_Param Use_RT_InfoImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	RT_Info_Param sp( ce);
	if ( sp)
		return sp;

	RT_Info_Param empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Task
//********************************************************************************
Task WorkLoadOperationConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Task sp( ce);
	if ( sp)
		return sp;

	Task empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to OperationRef
//********************************************************************************
OperationRef WorkLoadOperationConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	OperationRef sp( ce);
	if ( sp)
		return sp;

	OperationRef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to TaskSet
//********************************************************************************
TaskSet WorkloadCharacteristicsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	TaskSet sp( ce);
	if ( sp)
		return sp;

	TaskSet empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to MetricsBase
//********************************************************************************
MetricsBase WorkloadCharacteristicsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	MetricsBase sp( ce);
	if ( sp)
		return sp;

	MetricsBase empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd deliverToImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PublishConnector
//********************************************************************************
PublishConnector deliverToImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PublishConnector sp( ce);
	if ( sp)
		return sp;

	PublishConnector empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd emitImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd emitImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd invokeImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd invokeImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PackageConfigurationReference
//********************************************************************************
PackageConfigurationReference packageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PackageConfigurationReference sp( ce);
	if ( sp)
		return sp;

	PackageConfigurationReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to TopLevelPackage
//********************************************************************************
TopLevelPackage packageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	TopLevelPackage sp( ce);
	if ( sp)
		return sp;

	TopLevelPackage empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PublishConnector
//********************************************************************************
PublishConnector publishImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PublishConnector sp( ce);
	if ( sp)
		return sp;

	PublishConnector empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd publishImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
// 
//********************************************************************************
long TaskSetImpl::getpriority() 
{
	return FCOImpl::getAttribute("priority")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
long TaskSetImpl::getrate() 
{
	return FCOImpl::getAttribute("rate")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
void TaskSetImpl::setpriority( const long val)
{
	FCOImpl::getAttribute("priority")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void TaskSetImpl::setrate( const long val)
{
	FCOImpl::getAttribute("rate")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
ReadonlyAttribute AttributeMappingImpl::getReadonlyAttribute()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ReadonlyAttribute(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType AttributeMemberImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
BandedConnection BandedConnectionRefImpl::getBandedConnection()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return BandedConnection(r);
}


//********************************************************************************
// 
//********************************************************************************
Component CompRefImpl::getComponent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Component(r);
}


//********************************************************************************
// 
//********************************************************************************
ComponentAssembly ComponentAssemblyReferenceImpl::getComponentAssembly()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ComponentAssembly(r);
}


//********************************************************************************
// 
//********************************************************************************
ComponentImplementation ComponentImplementationReferenceImpl::getComponentImplementation()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ComponentImplementation(r);
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentPackageReferenceImpl::getrequiredName() 
{
	return FCOImpl::getAttribute("requiredName")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentPackageReferenceImpl::getrequiredType() 
{
	return FCOImpl::getAttribute("requiredType")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ComponentPackageReferenceImpl::getrequiredUUID() 
{
	return FCOImpl::getAttribute("requiredUUID")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ComponentPackageReferenceImpl::setrequiredName( const std::string& val)
{
	FCOImpl::getAttribute("requiredName")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ComponentPackageReferenceImpl::setrequiredType( const std::string& val)
{
	FCOImpl::getAttribute("requiredType")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ComponentPackageReferenceImpl::setrequiredUUID( const std::string& val)
{
	FCOImpl::getAttribute("requiredUUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
ComponentPackage ComponentPackageReferenceImpl::getComponentPackage()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ComponentPackage(r);
}


//********************************************************************************
// 
//********************************************************************************
PredefinedType DataTypeImpl::getPredefinedType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PredefinedType(r);
}


//********************************************************************************
// 
//********************************************************************************
ConstantType DiscriminatorImpl::getConstantType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ConstantType(r);
}


//********************************************************************************
// 
//********************************************************************************
Event EventRefImpl::getEvent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Event(r);
}


//********************************************************************************
// 
//********************************************************************************
Exception ExceptionRefImpl::getException()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Exception(r);
}


//********************************************************************************
// 
//********************************************************************************
ImplementationArtifact ExternalResourcesImpl::getImplementationArtifact()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ImplementationArtifact(r);
}


//********************************************************************************
// 
//********************************************************************************
File FileRefImpl::getFile()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return File(r);
}


//********************************************************************************
// 
//********************************************************************************
Exception GetExceptionImpl::getException()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Exception(r);
}


//********************************************************************************
// 
//********************************************************************************
ImplementationArtifact ImplementationArtifactReferenceImpl::getImplementationArtifact()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ImplementationArtifact(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType InParameterImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
Inheritable InheritsImpl::getInheritable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Inheritable(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType InoutParameterImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
ValueObject LookupKeyImpl::getValueObject()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ValueObject(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType MemberImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
Node NodeReferenceImpl::getNode()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Node(r);
}


//********************************************************************************
// 
//********************************************************************************
OperationBase OperationRefImpl::getOperationBase()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return OperationBase(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType OutParameterImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
PackageConfiguration PackageConfigurationReferenceImpl::getPackageConfiguration()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PackageConfiguration(r);
}


//********************************************************************************
// 
//********************************************************************************
PolicySet PolicySetRefImpl::getPolicySet()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PolicySet(r);
}


//********************************************************************************
// 
//********************************************************************************
QoSCharacteristic QoSCharacteristicRefImpl::getQoSCharacteristic()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return QoSCharacteristic(r);
}


//********************************************************************************
// 
//********************************************************************************
RTEC_Resource_Factory RTEC_Resource_Factory_ReferenceImpl::getRTEC_Resource_Factory()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return RTEC_Resource_Factory(r);
}


//********************************************************************************
// 
//********************************************************************************
MemberType ReturnTypeImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return MemberType(r);
}


//********************************************************************************
// 
//********************************************************************************
Exception SetExceptionImpl::getException()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Exception(r);
}


//********************************************************************************
// 
//********************************************************************************
Object SupportsImpl::getObject()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Object(r);
}


//********************************************************************************
// 
//********************************************************************************
ThreadPool ThreadPoolRefImpl::getThreadPool()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ThreadPool(r);
}



}; // namespace PICML_BON

