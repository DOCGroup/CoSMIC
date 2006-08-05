#include "stdafx.h"
#include "SIMLBonX.h"


namespace BON
{

IMPLEMENT_BONEXTENSION( SIML_BON::ComponentAnalyses, "ComponentAnalyses" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentBuild, "ComponentBuild" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentImplementations, "ComponentImplementations" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentPackages, "ComponentPackages" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentTypes, "ComponentTypes" );
IMPLEMENT_BONEXTENSION( SIML_BON::DeploymentPlans, "DeploymentPlans" );
IMPLEMENT_BONEXTENSION( SIML_BON::EventChannelConfig, "EventChannelConfig" );
IMPLEMENT_BONEXTENSION( SIML_BON::FaultTolerance, "FaultTolerance" );
IMPLEMENT_BONEXTENSION( SIML_BON::ImplementationArtifacts, "ImplementationArtifacts" );
IMPLEMENT_BONEXTENSION( SIML_BON::InterfaceDefinitions, "InterfaceDefinitions" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfigurations, "PackageConfigurations" );
IMPLEMENT_BONEXTENSION( SIML_BON::PathDiagrams, "PathDiagrams" );
IMPLEMENT_BONEXTENSION( SIML_BON::PredefinedTypes, "PredefinedTypes" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSModeling, "QoSModeling" );
IMPLEMENT_BONEXTENSION( SIML_BON::Targets, "Targets" );
IMPLEMENT_BONEXTENSION( SIML_BON::TopLevelPackages, "TopLevelPackages" );
IMPLEMENT_BONEXTENSION( SIML_BON::WorkerLibraries, "WorkerLibraries" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Prefixable );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::SupportsInterfaces );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::CommonPortAttrs );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ConstantType );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::FTMonitorable );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::GraphVertex );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Manageable );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::MemberType );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::MultiInputBase );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Provideable );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Taggable );
IMPLEMENT_BONEXTENSION( SIML_BON::ConnectedComponent, "ConnectedComponent" );
IMPLEMENT_BONEXTENSION( SIML_BON::Exception, "Exception" );
IMPLEMENT_BONEXTENSION( SIML_BON::File, "File" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::OperationBase );
IMPLEMENT_BONEXTENSION( SIML_BON::Package, "Package" );
IMPLEMENT_BONEXTENSION( SIML_BON::ReadonlyAttribute, "ReadonlyAttribute" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::NamedType );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Port );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::PredefinedType );
IMPLEMENT_BONEXTENSION( SIML_BON::DisplayNode, "DisplayNode" );
IMPLEMENT_BONEXTENSION( SIML_BON::Environment, "Environment" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentAssemblyReference, "ComponentAssemblyReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentRef, "ComponentRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::Constant, "Constant" );
IMPLEMENT_BONEXTENSION( SIML_BON::Attribute, "Attribute" );
IMPLEMENT_BONEXTENSION( SIML_BON::Component, "Component" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::HasExceptions );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Inheritable );
IMPLEMENT_BONEXTENSION( SIML_BON::OnewayOperation, "OnewayOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::NoInheritable );
IMPLEMENT_BONEXTENSION( SIML_BON::Boolean, "Boolean" );
IMPLEMENT_BONEXTENSION( SIML_BON::Byte, "Byte" );
IMPLEMENT_BONEXTENSION( SIML_BON::GenericObject, "GenericObject" );
IMPLEMENT_BONEXTENSION( SIML_BON::GenericValue, "GenericValue" );
IMPLEMENT_BONEXTENSION( SIML_BON::GenericValueObject, "GenericValueObject" );
IMPLEMENT_BONEXTENSION( SIML_BON::LongInteger, "LongInteger" );
IMPLEMENT_BONEXTENSION( SIML_BON::RealNumber, "RealNumber" );
IMPLEMENT_BONEXTENSION( SIML_BON::ShortInteger, "ShortInteger" );
IMPLEMENT_BONEXTENSION( SIML_BON::String, "String" );
IMPLEMENT_BONEXTENSION( SIML_BON::TypeEncoding, "TypeEncoding" );
IMPLEMENT_BONEXTENSION( SIML_BON::TypeKind, "TypeKind" );
IMPLEMENT_BONEXTENSION( SIML_BON::Boxed, "Boxed" );
IMPLEMENT_BONEXTENSION( SIML_BON::InEventPort, "InEventPort" );
IMPLEMENT_BONEXTENSION( SIML_BON::OutEventPort, "OutEventPort" );
IMPLEMENT_BONEXTENSION( SIML_BON::ProvidedRequestPort, "ProvidedRequestPort" );
IMPLEMENT_BONEXTENSION( SIML_BON::RequiredRequestPort, "RequiredRequestPort" );
IMPLEMENT_BONEXTENSION( SIML_BON::Aggregate, "Aggregate" );
IMPLEMENT_BONEXTENSION( SIML_BON::Enum, "Enum" );
IMPLEMENT_BONEXTENSION( SIML_BON::FactoryOperation, "FactoryOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::HasOperations );
IMPLEMENT_BONEXTENSION( SIML_BON::LookupOperation, "LookupOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::SwitchedAggregate, "SwitchedAggregate" );
IMPLEMENT_BONEXTENSION( SIML_BON::TwowayOperation, "TwowayOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::Alias, "Alias" );
IMPLEMENT_BONEXTENSION( SIML_BON::Collection, "Collection" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentFactory, "ComponentFactory" );
IMPLEMENT_BONEXTENSION( SIML_BON::Object, "Object" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ObjectByValue );
IMPLEMENT_BONEXTENSION( SIML_BON::Event, "Event" );
IMPLEMENT_BONEXTENSION( SIML_BON::ValueObject, "ValueObject" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::RequirementSatisfier );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Elements );
IMPLEMENT_BONEXTENSION( SIML_BON::Bridge, "Bridge" );
IMPLEMENT_BONEXTENSION( SIML_BON::Capability, "Capability" );
IMPLEMENT_BONEXTENSION( SIML_BON::Interconnect, "Interconnect" );
IMPLEMENT_BONEXTENSION( SIML_BON::Node, "Node" );
IMPLEMENT_BONEXTENSION( SIML_BON::Resource, "Resource" );
IMPLEMENT_BONEXTENSION( SIML_BON::SharedResource, "SharedResource" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Proxy );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::RTEC_Proxy );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Proxy_Consumer );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Proxy_Supplier );
IMPLEMENT_BONEXTENSION( SIML_BON::RTEC_Proxy_Consumer, "RTEC_Proxy_Consumer" );
IMPLEMENT_BONEXTENSION( SIML_BON::RTEC_Proxy_Supplier, "RTEC_Proxy_Supplier" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSCharacteristic, "QoSCharacteristic" );
IMPLEMENT_BONEXTENSION( SIML_BON::CPU, "CPU" );
IMPLEMENT_BONEXTENSION( SIML_BON::Concurrency, "Concurrency" );
IMPLEMENT_BONEXTENSION( SIML_BON::Connection, "Connection" );
IMPLEMENT_BONEXTENSION( SIML_BON::Process, "Process" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::RequirementBase );
IMPLEMENT_BONEXTENSION( SIML_BON::ImplementationRequirement, "ImplementationRequirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::Requirement, "Requirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::FOU_Requirement, "FOU_Requirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::RepGRequirement, "RepGRequirement" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Operation );
IMPLEMENT_BONEXTENSION( SIML_BON::NotificationOperation, "NotificationOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::OneWayOperation, "OneWayOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::RequestResponseOperation, "RequestResponseOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::SolicitResponseOperation, "SolicitResponseOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ActionBase );
IMPLEMENT_BONEXTENSION( SIML_BON::Action, "Action" );
IMPLEMENT_BONEXTENSION( SIML_BON::CompositeAction, "CompositeAction" );
IMPLEMENT_BONEXTENSION( SIML_BON::OutputAction, "OutputAction" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ComponentLib );
IMPLEMENT_BONEXTENSION( SIML_BON::ExecutorProject, "ExecutorProject" );
IMPLEMENT_BONEXTENSION( SIML_BON::ServantProject, "ServantProject" );
IMPLEMENT_BONEXTENSION( SIML_BON::StubProject, "StubProject" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::resource );
IMPLEMENT_BONEXTENSION( SIML_BON::BandedConnection, "BandedConnection" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ThreadPool );
IMPLEMENT_BONEXTENSION( SIML_BON::SimpleThreadPool, "SimpleThreadPool" );
IMPLEMENT_BONEXTENSION( SIML_BON::ThreadPoolWithLanes, "ThreadPoolWithLanes" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::InputActionBase );
IMPLEMENT_BONEXTENSION( SIML_BON::InputAction, "InputAction" );
IMPLEMENT_BONEXTENSION( SIML_BON::PeriodicAction, "PeriodicAction" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::MetricsBase );
IMPLEMENT_BONEXTENSION( SIML_BON::Latency, "Latency" );
IMPLEMENT_BONEXTENSION( SIML_BON::Throughput, "Throughput" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::SharedRiskComposite );
IMPLEMENT_BONEXTENSION( SIML_BON::NodeGroup, "NodeGroup" );
IMPLEMENT_BONEXTENSION( SIML_BON::SharedRiskGroup, "SharedRiskGroup" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::FTComposite );
IMPLEMENT_BONEXTENSION( SIML_BON::FailOverUnit, "FailOverUnit" );
IMPLEMENT_BONEXTENSION( SIML_BON::SchemaReference, "SchemaReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::SchemaImport, "SchemaImport" );
IMPLEMENT_BONEXTENSION( SIML_BON::WorkerPackage, "WorkerPackage" );
IMPLEMENT_BONEXTENSION( SIML_BON::WorkerFile, "WorkerFile" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ComponentImplementation );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentAssembly, "ComponentAssembly" );
IMPLEMENT_BONEXTENSION( SIML_BON::MonolithicImplementation, "MonolithicImplementation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ExtensibilityElement );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ExtensibleBinding );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ExtensibleMessage );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ExtensibleOperation );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::ExtensiblePort );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::SOAPHeaders );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPAddress, "SOAPAddress" );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPBinding, "SOAPBinding" );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPBody, "SOAPBody" );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPFault, "SOAPFault" );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPOperation, "SOAPOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPHeader, "SOAPHeader" );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPHeaderFault, "SOAPHeaderFault" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::Referrable );
IMPLEMENT_BONEXTENSION( SIML_BON::Element, "Element" );
IMPLEMENT_BONEXTENSION( SIML_BON::AtomicType, "AtomicType" );
IMPLEMENT_BONEXTENSION( SIML_BON::ArtifactContainer, "ArtifactContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::BenchmarkAnalysis, "BenchmarkAnalysis" );
IMPLEMENT_BONEXTENSION( SIML_BON::Binding, "Binding" );
IMPLEMENT_BONEXTENSION( SIML_BON::BindingOperation, "BindingOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentContainer, "ComponentContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentImplementationContainer, "ComponentImplementationContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentPropertyDescription, "ComponentPropertyDescription" );
IMPLEMENT_BONEXTENSION( SIML_BON::Definitions, "Definitions" );
IMPLEMENT_BONEXTENSION( SIML_BON::DeploymentPlan, "DeploymentPlan" );
IMPLEMENT_BONEXTENSION( SIML_BON::Documentation, "Documentation" );
IMPLEMENT_BONEXTENSION( SIML_BON::Domain, "Domain" );
IMPLEMENT_BONEXTENSION( SIML_BON::EventChannelConfiguration, "EventChannelConfiguration" );
IMPLEMENT_BONEXTENSION( SIML_BON::FTRequirements, "FTRequirements" );
IMPLEMENT_BONEXTENSION( SIML_BON::Fault, "Fault" );
IMPLEMENT_BONEXTENSION( SIML_BON::Import, "Import" );
IMPLEMENT_BONEXTENSION( SIML_BON::Input, "Input" );
IMPLEMENT_BONEXTENSION( SIML_BON::MPC, "MPC" );
IMPLEMENT_BONEXTENSION( SIML_BON::Message, "Message" );
IMPLEMENT_BONEXTENSION( SIML_BON::Messages, "Messages" );
IMPLEMENT_BONEXTENSION( SIML_BON::Output, "Output" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfigurationContainer, "PackageConfigurationContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageContainer, "PackageContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::Path, "Path" );
IMPLEMENT_BONEXTENSION( SIML_BON::Paths, "Paths" );
IMPLEMENT_BONEXTENSION( SIML_BON::PolicySet, "PolicySet" );
IMPLEMENT_BONEXTENSION( SIML_BON::Port, "Port" );
IMPLEMENT_BONEXTENSION( SIML_BON::PortType, "PortType" );
IMPLEMENT_BONEXTENSION( SIML_BON::Project, "Project" );
IMPLEMENT_BONEXTENSION( SIML_BON::Property, "Property" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSCategory, "QoSCategory" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSContext, "QoSContext" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSValue, "QoSValue" );
IMPLEMENT_BONEXTENSION( SIML_BON::RTConfiguration, "RTConfiguration" );
IMPLEMENT_BONEXTENSION( SIML_BON::RTModel, "RTModel" );
IMPLEMENT_BONEXTENSION( SIML_BON::ResourceContainer, "ResourceContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::SRGContainer, "SRGContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::SatisfierProperty, "SatisfierProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::Schema, "Schema" );
IMPLEMENT_BONEXTENSION( SIML_BON::SchemaBuiltins, "SchemaBuiltins" );
IMPLEMENT_BONEXTENSION( SIML_BON::Service, "Service" );
IMPLEMENT_BONEXTENSION( SIML_BON::System, "System" );
IMPLEMENT_BONEXTENSION( SIML_BON::TopLevelPackageContainer, "TopLevelPackageContainer" );
IMPLEMENT_BONEXTENSION( SIML_BON::Types, "Types" );
IMPLEMENT_BONEXTENSION( SIML_BON::Worker, "Worker" );
IMPLEMENT_BONEXTENSION( SIML_BON::WorkerLibrary, "WorkerLibrary" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::BenchmarkType );
IMPLEMENT_BONEXTENSION( SIML_BON::FixedIterationBenchmarks, "FixedIterationBenchmarks" );
IMPLEMENT_BONEXTENSION( SIML_BON::PeriodicBenchmarks, "PeriodicBenchmarks" );
IMPLEMENT_BONEXTENSION( SIML_BON::TriggerBenchmarks, "TriggerBenchmarks" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::DataAnalysisBase );
IMPLEMENT_BONEXTENSION( SIML_BON::Average, "Average" );
IMPLEMENT_BONEXTENSION( SIML_BON::Jitter, "Jitter" );
IMPLEMENT_BONEXTENSION( SIML_BON::Maximum, "Maximum" );
IMPLEMENT_BONEXTENSION( SIML_BON::Minimum, "Minimum" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::IORef );
IMPLEMENT_BONEXTENSION( SIML_BON::InputRef, "InputRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::OutputRef, "OutputRef" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::QoSConstraint );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSContract, "QoSContract" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSOffered, "QoSOffered" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSRequired, "QoSRequired" );
IMPLEMENT_BONEXTENSION( SIML_BON::Attribute, "Attribute" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentPackage, "ComponentPackage" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::RTEC_Filter_Group );
IMPLEMENT_BONEXTENSION( SIML_BON::ConjunctionGroup, "ConjunctionGroup" );
IMPLEMENT_BONEXTENSION( SIML_BON::DisjunctionGroup, "DisjunctionGroup" );
IMPLEMENT_BONEXTENSION( SIML_BON::LogicalANDGroup, "LogicalANDGroup" );
IMPLEMENT_BONEXTENSION( SIML_BON::ConnectionBand, "ConnectionBand" );
IMPLEMENT_BONEXTENSION( SIML_BON::Edge, "Edge" );
IMPLEMENT_BONEXTENSION( SIML_BON::EnumValue, "EnumValue" );
IMPLEMENT_BONEXTENSION( SIML_BON::EnvironmentConf, "EnvironmentConf" );
IMPLEMENT_BONEXTENSION( SIML_BON::ExternalReferenceEndPoint, "ExternalReferenceEndPoint" );
IMPLEMENT_BONEXTENSION( SIML_BON::ImplementationArtifact, "ImplementationArtifact" );
IMPLEMENT_BONEXTENSION( SIML_BON::ImplementationDependency, "ImplementationDependency" );
IMPLEMENT_BONEXTENSION( SIML_BON::Label, "Label" );
IMPLEMENT_ABSTRACT_BONEXTENSION( SIML_BON::RT_Info_Param );
IMPLEMENT_BONEXTENSION( SIML_BON::Null_RT_Info, "Null_RT_Info" );
IMPLEMENT_BONEXTENSION( SIML_BON::RT_Info, "RT_Info" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfiguration, "PackageConfiguration" );
IMPLEMENT_BONEXTENSION( SIML_BON::PriorityModelPolicy, "PriorityModelPolicy" );
IMPLEMENT_BONEXTENSION( SIML_BON::PrivateFlag, "PrivateFlag" );
IMPLEMENT_BONEXTENSION( SIML_BON::PublishConnector, "PublishConnector" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSDimension, "QoSDimension" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSDimensionSlot, "QoSDimensionSlot" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSParameter, "QoSParameter" );
IMPLEMENT_BONEXTENSION( SIML_BON::RTEC_Resource_Factory, "RTEC_Resource_Factory" );
IMPLEMENT_BONEXTENSION( SIML_BON::State, "State" );
IMPLEMENT_BONEXTENSION( SIML_BON::Task, "Task" );
IMPLEMENT_BONEXTENSION( SIML_BON::ThreadPoolLane, "ThreadPoolLane" );
IMPLEMENT_BONEXTENSION( SIML_BON::TimeProbe, "TimeProbe" );
IMPLEMENT_BONEXTENSION( SIML_BON::TopLevelPackage, "TopLevelPackage" );
IMPLEMENT_BONEXTENSION( SIML_BON::ArtifactDependency, "ArtifactDependency" );
IMPLEMENT_BONEXTENSION( SIML_BON::ArtifactDependsOn, "ArtifactDependsOn" );
IMPLEMENT_BONEXTENSION( SIML_BON::ArtifactDeployRequirement, "ArtifactDeployRequirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::ArtifactExecParameter, "ArtifactExecParameter" );
IMPLEMENT_BONEXTENSION( SIML_BON::ArtifactInfoProperty, "ArtifactInfoProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::AssemblyConfigProperty, "AssemblyConfigProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::AssemblyDeployRequirement, "AssemblyDeployRequirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::AssemblyselectRequirement, "AssemblyselectRequirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::AttributeDelegate, "AttributeDelegate" );
IMPLEMENT_BONEXTENSION( SIML_BON::AttributeMappingDelegate, "AttributeMappingDelegate" );
IMPLEMENT_BONEXTENSION( SIML_BON::AttributeMappingValue, "AttributeMappingValue" );
IMPLEMENT_BONEXTENSION( SIML_BON::AttributeValue, "AttributeValue" );
IMPLEMENT_BONEXTENSION( SIML_BON::BenchmarkCharacteristics, "BenchmarkCharacteristics" );
IMPLEMENT_BONEXTENSION( SIML_BON::BindingPortType, "BindingPortType" );
IMPLEMENT_BONEXTENSION( SIML_BON::BindsOperation, "BindsOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::BodyBinding, "BodyBinding" );
IMPLEMENT_BONEXTENSION( SIML_BON::BodyParts, "BodyParts" );
IMPLEMENT_BONEXTENSION( SIML_BON::Bridge2Interconnect, "Bridge2Interconnect" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentConfigProperty, "ComponentConfigProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentInfoProperty, "ComponentInfoProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentOperation, "ComponentOperation" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentProperty, "ComponentProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::ConfigProperty, "ConfigProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::CriticalPath, "CriticalPath" );
IMPLEMENT_BONEXTENSION( SIML_BON::DstEdge, "DstEdge" );
IMPLEMENT_BONEXTENSION( SIML_BON::EdgeProperty, "EdgeProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::Effect, "Effect" );
IMPLEMENT_BONEXTENSION( SIML_BON::EventSinkDelegate, "EventSinkDelegate" );
IMPLEMENT_BONEXTENSION( SIML_BON::EventSourceDelegate, "EventSourceDelegate" );
IMPLEMENT_BONEXTENSION( SIML_BON::ExtResourceConn, "ExtResourceConn" );
IMPLEMENT_BONEXTENSION( SIML_BON::ExternalDelegate, "ExternalDelegate" );
IMPLEMENT_BONEXTENSION( SIML_BON::FacetDelegate, "FacetDelegate" );
IMPLEMENT_BONEXTENSION( SIML_BON::FaultMessage, "FaultMessage" );
IMPLEMENT_BONEXTENSION( SIML_BON::Finish, "Finish" );
IMPLEMENT_BONEXTENSION( SIML_BON::HeaderBinding, "HeaderBinding" );
IMPLEMENT_BONEXTENSION( SIML_BON::HeaderMessage, "HeaderMessage" );
IMPLEMENT_BONEXTENSION( SIML_BON::HeaderPart, "HeaderPart" );
IMPLEMENT_BONEXTENSION( SIML_BON::Implementation, "Implementation" );
IMPLEMENT_BONEXTENSION( SIML_BON::ImplementationCapability, "ImplementationCapability" );
IMPLEMENT_BONEXTENSION( SIML_BON::ImplementationDependsOn, "ImplementationDependsOn" );
IMPLEMENT_BONEXTENSION( SIML_BON::Implements, "Implements" );
IMPLEMENT_BONEXTENSION( SIML_BON::Include_RTEC_Filter_Group, "Include_RTEC_Filter_Group" );
IMPLEMENT_BONEXTENSION( SIML_BON::Include_RT_Info, "Include_RT_Info" );
IMPLEMENT_BONEXTENSION( SIML_BON::InfoProperty, "InfoProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::Input, "Input" );
IMPLEMENT_BONEXTENSION( SIML_BON::InputMessage, "InputMessage" );
IMPLEMENT_BONEXTENSION( SIML_BON::InstanceMapping, "InstanceMapping" );
IMPLEMENT_BONEXTENSION( SIML_BON::Interconnect2Bridge, "Interconnect2Bridge" );
IMPLEMENT_BONEXTENSION( SIML_BON::Interconnect2Node, "Interconnect2Node" );
IMPLEMENT_BONEXTENSION( SIML_BON::LabelConnection, "LabelConnection" );
IMPLEMENT_BONEXTENSION( SIML_BON::MakeMemberPrivate, "MakeMemberPrivate" );
IMPLEMENT_BONEXTENSION( SIML_BON::ManagesComponent, "ManagesComponent" );
IMPLEMENT_BONEXTENSION( SIML_BON::MetricConnection, "MetricConnection" );
IMPLEMENT_BONEXTENSION( SIML_BON::Monitorable2RepG, "Monitorable2RepG" );
IMPLEMENT_BONEXTENSION( SIML_BON::MonolithDeployRequirement, "MonolithDeployRequirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::MonolithExecParameter, "MonolithExecParameter" );
IMPLEMENT_BONEXTENSION( SIML_BON::MonolithprimaryArtifact, "MonolithprimaryArtifact" );
IMPLEMENT_BONEXTENSION( SIML_BON::MultiInput, "MultiInput" );
IMPLEMENT_BONEXTENSION( SIML_BON::Node2Interconnect, "Node2Interconnect" );
IMPLEMENT_BONEXTENSION( SIML_BON::OutputMessage, "OutputMessage" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfBasePackage, "PackageConfBasePackage" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfConfigProperty, "PackageConfConfigProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfReference, "PackageConfReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfSelectRequirement, "PackageConfSelectRequirement" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfSpecializedConfig, "PackageConfSpecializedConfig" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfigProperty, "PackageConfigProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageInfoProperty, "PackageInfoProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageInterface, "PackageInterface" );
IMPLEMENT_BONEXTENSION( SIML_BON::PathProperty, "PathProperty" );
IMPLEMENT_BONEXTENSION( SIML_BON::PortBinding, "PortBinding" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSDecoration, "QoSDecoration" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSDimensionQualifier, "QoSDimensionQualifier" );
IMPLEMENT_BONEXTENSION( SIML_BON::RTEC_Connection, "RTEC_Connection" );
IMPLEMENT_BONEXTENSION( SIML_BON::ReceptacleDelegate, "ReceptacleDelegate" );
IMPLEMENT_BONEXTENSION( SIML_BON::ReqConnection, "ReqConnection" );
IMPLEMENT_BONEXTENSION( SIML_BON::SOAPFaultExtension, "SOAPFaultExtension" );
IMPLEMENT_BONEXTENSION( SIML_BON::Shares, "Shares" );
IMPLEMENT_BONEXTENSION( SIML_BON::SrcEdge, "SrcEdge" );
IMPLEMENT_BONEXTENSION( SIML_BON::TimerConnection, "TimerConnection" );
IMPLEMENT_BONEXTENSION( SIML_BON::TimerEventSinkConn, "TimerEventSinkConn" );
IMPLEMENT_BONEXTENSION( SIML_BON::Transition, "Transition" );
IMPLEMENT_BONEXTENSION( SIML_BON::Use_RTEC_Filter, "Use_RTEC_Filter" );
IMPLEMENT_BONEXTENSION( SIML_BON::Use_RT_Info, "Use_RT_Info" );
IMPLEMENT_BONEXTENSION( SIML_BON::WorkLoadOperationConnection, "WorkLoadOperationConnection" );
IMPLEMENT_BONEXTENSION( SIML_BON::WorkloadCharacteristics, "WorkloadCharacteristics" );
IMPLEMENT_BONEXTENSION( SIML_BON::deliverTo, "deliverTo" );
IMPLEMENT_BONEXTENSION( SIML_BON::emit, "emit" );
IMPLEMENT_BONEXTENSION( SIML_BON::invoke, "invoke" );
IMPLEMENT_BONEXTENSION( SIML_BON::package, "package" );
IMPLEMENT_BONEXTENSION( SIML_BON::publish, "publish" );
IMPLEMENT_BONEXTENSION( SIML_BON::CollocationGroup, "CollocationGroup" );
IMPLEMENT_BONEXTENSION( SIML_BON::TaskSet, "TaskSet" );
IMPLEMENT_BONEXTENSION( SIML_BON::Workspaces, "Workspaces" );
IMPLEMENT_BONEXTENSION( SIML_BON::AttributeMapping, "AttributeMapping" );
IMPLEMENT_BONEXTENSION( SIML_BON::AttributeMember, "AttributeMember" );
IMPLEMENT_BONEXTENSION( SIML_BON::BandedConnectionRef, "BandedConnectionRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::BindingRef, "BindingRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::CCMAssembly, "CCMAssembly" );
IMPLEMENT_BONEXTENSION( SIML_BON::CompRef, "CompRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentImplementationReference, "ComponentImplementationReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::ComponentPackageReference, "ComponentPackageReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::DataType, "DataType" );
IMPLEMENT_BONEXTENSION( SIML_BON::DeploymentPlanRef, "DeploymentPlanRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::Discriminator, "Discriminator" );
IMPLEMENT_BONEXTENSION( SIML_BON::EventRef, "EventRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::ExceptionRef, "ExceptionRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::ExternalResources, "ExternalResources" );
IMPLEMENT_BONEXTENSION( SIML_BON::FaultRef, "FaultRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::FileRef, "FileRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::GetException, "GetException" );
IMPLEMENT_BONEXTENSION( SIML_BON::ImplementationArtifactReference, "ImplementationArtifactReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::InParameter, "InParameter" );
IMPLEMENT_BONEXTENSION( SIML_BON::Inherits, "Inherits" );
IMPLEMENT_BONEXTENSION( SIML_BON::InoutParameter, "InoutParameter" );
IMPLEMENT_BONEXTENSION( SIML_BON::LookupKey, "LookupKey" );
IMPLEMENT_BONEXTENSION( SIML_BON::Member, "Member" );
IMPLEMENT_BONEXTENSION( SIML_BON::MessageRef, "MessageRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::NodeRef, "NodeRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::NodeReference, "NodeReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::OperationRef, "OperationRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::OperationRef, "OperationRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::OutParameter, "OutParameter" );
IMPLEMENT_BONEXTENSION( SIML_BON::PackageConfigurationReference, "PackageConfigurationReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::Part, "Part" );
IMPLEMENT_BONEXTENSION( SIML_BON::PartRef, "PartRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::PathReference, "PathReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::PolicySetRef, "PolicySetRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::QoSCharacteristicRef, "QoSCharacteristicRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::RTEC_Resource_Factory_Reference, "RTEC_Resource_Factory_Reference" );
IMPLEMENT_BONEXTENSION( SIML_BON::ReturnType, "ReturnType" );
IMPLEMENT_BONEXTENSION( SIML_BON::SRGContainerRef, "SRGContainerRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::SetException, "SetException" );
IMPLEMENT_BONEXTENSION( SIML_BON::SharedComponentReference, "SharedComponentReference" );
IMPLEMENT_BONEXTENSION( SIML_BON::SharedResourceRef, "SharedResourceRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::Supports, "Supports" );
IMPLEMENT_BONEXTENSION( SIML_BON::ThreadPoolRef, "ThreadPoolRef" );
IMPLEMENT_BONEXTENSION( SIML_BON::Variable, "Variable" );
IMPLEMENT_BONEXTENSION( SIML_BON::WebService, "WebService" );
IMPLEMENT_BONEXTENSION( SIML_BON::WorkerType, "WorkerType" );


}; // end namespace BON

namespace SIML_BON
{
//********************************************************************************
// getter for kind "BenchmarkAnalysis"
//********************************************************************************
std::set<BenchmarkAnalysis> ComponentAnalysesImpl::getBenchmarkAnalysis()
{
	std::set<BenchmarkAnalysis> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("BenchmarkAnalysis");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		BenchmarkAnalysis elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "MPC"
//********************************************************************************
std::set<MPC> ComponentBuildImpl::getMPC()
{
	std::set<MPC> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("MPC");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		MPC elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "ComponentImplementationContainer"
//********************************************************************************
std::set<ComponentImplementationContainer> ComponentImplementationsImpl::getComponentImplementationContainer()
{
	std::set<ComponentImplementationContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("ComponentImplementationContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		ComponentImplementationContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PackageContainer"
//********************************************************************************
std::set<PackageContainer> ComponentPackagesImpl::getPackageContainer()
{
	std::set<PackageContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PackageContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PackageContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "ComponentContainer"
//********************************************************************************
std::set<ComponentContainer> ComponentTypesImpl::getComponentContainer()
{
	std::set<ComponentContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("ComponentContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		ComponentContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "DeploymentPlan"
//********************************************************************************
std::set<DeploymentPlan> DeploymentPlansImpl::getDeploymentPlan()
{
	std::set<DeploymentPlan> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("DeploymentPlan");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		DeploymentPlan elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "EventChannelConfiguration"
//********************************************************************************
std::set<EventChannelConfiguration> EventChannelConfigImpl::getEventChannelConfiguration()
{
	std::set<EventChannelConfiguration> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("EventChannelConfiguration");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		EventChannelConfiguration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "FTRequirements"
//********************************************************************************
std::set<FTRequirements> FaultToleranceImpl::getFTRequirements()
{
	std::set<FTRequirements> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("FTRequirements");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		FTRequirements elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "SRGContainer"
//********************************************************************************
std::set<SRGContainer> FaultToleranceImpl::getSRGContainer()
{
	std::set<SRGContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("SRGContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		SRGContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "ArtifactContainer"
//********************************************************************************
std::set<ArtifactContainer> ImplementationArtifactsImpl::getArtifactContainer()
{
	std::set<ArtifactContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("ArtifactContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		ArtifactContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "File"
//********************************************************************************
std::set<File> InterfaceDefinitionsImpl::getFile()
{
	std::set<File> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("File");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		File elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PackageConfigurationContainer"
//********************************************************************************
std::set<PackageConfigurationContainer> PackageConfigurationsImpl::getPackageConfigurationContainer()
{
	std::set<PackageConfigurationContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PackageConfigurationContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PackageConfigurationContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "Paths"
//********************************************************************************
std::set<Paths> PathDiagramsImpl::getPaths()
{
	std::set<Paths> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("Paths");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		Paths elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "Boolean"
//********************************************************************************
std::set<Boolean> PredefinedTypesImpl::getBoolean()
{
	std::set<Boolean> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("Boolean");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		Boolean elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "Byte"
//********************************************************************************
std::set<Byte> PredefinedTypesImpl::getByte()
{
	std::set<Byte> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("Byte");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		Byte elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "GenericObject"
//********************************************************************************
std::set<GenericObject> PredefinedTypesImpl::getGenericObject()
{
	std::set<GenericObject> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("GenericObject");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		GenericObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "GenericValue"
//********************************************************************************
std::set<GenericValue> PredefinedTypesImpl::getGenericValue()
{
	std::set<GenericValue> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("GenericValue");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		GenericValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "GenericValueObject"
//********************************************************************************
std::set<GenericValueObject> PredefinedTypesImpl::getGenericValueObject()
{
	std::set<GenericValueObject> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("GenericValueObject");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		GenericValueObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "LongInteger"
//********************************************************************************
std::set<LongInteger> PredefinedTypesImpl::getLongInteger()
{
	std::set<LongInteger> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("LongInteger");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		LongInteger elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for kind "PredefinedType" and its descendants
//********************************************************************************
std::set<PredefinedType> PredefinedTypesImpl::getPredefinedType()
{
	std::set<PredefinedType> res;
	const int len = 11;
	std::set<BON::Object> kinds_vec[ len];
	kinds_vec[0] = FolderImpl::getChildObjects("Boolean");
	kinds_vec[1] = FolderImpl::getChildObjects("Byte");
	kinds_vec[2] = FolderImpl::getChildObjects("GenericObject");
	kinds_vec[3] = FolderImpl::getChildObjects("GenericValue");
	kinds_vec[4] = FolderImpl::getChildObjects("GenericValueObject");
	kinds_vec[5] = FolderImpl::getChildObjects("LongInteger");
	kinds_vec[6] = FolderImpl::getChildObjects("RealNumber");
	kinds_vec[7] = FolderImpl::getChildObjects("ShortInteger");
	kinds_vec[8] = FolderImpl::getChildObjects("String");
	kinds_vec[9] = FolderImpl::getChildObjects("TypeEncoding");
	kinds_vec[10] = FolderImpl::getChildObjects("TypeKind");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::Object>::iterator i = kinds_vec[k].begin(); i != kinds_vec[k].end(); ++i)
		{
			PredefinedType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for kind "RealNumber"
//********************************************************************************
std::set<RealNumber> PredefinedTypesImpl::getRealNumber()
{
	std::set<RealNumber> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("RealNumber");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		RealNumber elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "ShortInteger"
//********************************************************************************
std::set<ShortInteger> PredefinedTypesImpl::getShortInteger()
{
	std::set<ShortInteger> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("ShortInteger");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		ShortInteger elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "String"
//********************************************************************************
std::set<String> PredefinedTypesImpl::getString()
{
	std::set<String> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("String");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		String elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "TypeEncoding"
//********************************************************************************
std::set<TypeEncoding> PredefinedTypesImpl::getTypeEncoding()
{
	std::set<TypeEncoding> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("TypeEncoding");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		TypeEncoding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "TypeKind"
//********************************************************************************
std::set<TypeKind> PredefinedTypesImpl::getTypeKind()
{
	std::set<TypeKind> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("TypeKind");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		TypeKind elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "CPU"
//********************************************************************************
std::set<CPU> QoSModelingImpl::getCPU()
{
	std::set<CPU> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("CPU");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		CPU elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "Concurrency"
//********************************************************************************
std::set<Concurrency> QoSModelingImpl::getConcurrency()
{
	std::set<Concurrency> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("Concurrency");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		Concurrency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "Connection"
//********************************************************************************
std::set<Connection> QoSModelingImpl::getConnection()
{
	std::set<Connection> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("Connection");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "Process"
//********************************************************************************
std::set<Process> QoSModelingImpl::getProcess()
{
	std::set<Process> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("Process");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		Process elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "QoSCategory"
//********************************************************************************
std::set<QoSCategory> QoSModelingImpl::getQoSCategory()
{
	std::set<QoSCategory> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("QoSCategory");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		QoSCategory elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for kind "QoSCharacteristic" and its descendants
//********************************************************************************
std::set<QoSCharacteristic> QoSModelingImpl::getQoSCharacteristic()
{
	std::set<QoSCharacteristic> res;
	const int len = 5;
	std::set<BON::Object> kinds_vec[ len];
	kinds_vec[0] = FolderImpl::getChildObjects("CPU");
	kinds_vec[1] = FolderImpl::getChildObjects("Concurrency");
	kinds_vec[2] = FolderImpl::getChildObjects("Connection");
	kinds_vec[3] = FolderImpl::getChildObjects("Process");
	kinds_vec[4] = FolderImpl::getChildObjects("QoSCharacteristic");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::Object>::iterator i = kinds_vec[k].begin(); i != kinds_vec[k].end(); ++i)
		{
			QoSCharacteristic elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for kind "Domain"
//********************************************************************************
std::set<Domain> TargetsImpl::getDomain()
{
	std::set<Domain> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("Domain");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		Domain elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "TopLevelPackageContainer"
//********************************************************************************
std::set<TopLevelPackageContainer> TopLevelPackagesImpl::getTopLevelPackageContainer()
{
	std::set<TopLevelPackageContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("TopLevelPackageContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		TopLevelPackageContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "WorkerLibrary"
//********************************************************************************
std::set<WorkerLibrary> WorkerLibrariesImpl::getWorkerLibrary()
{
	std::set<WorkerLibrary> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("WorkerLibrary");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		WorkerLibrary elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


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
// getter for role "Supports" among "Supports"s
//********************************************************************************
std::set<Supports> SupportsInterfacesImpl::getSupports()
{
	std::set<Supports> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Supports");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Supports elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// returns dst RepGRequirements
//********************************************************************************
std::multiset<RepGRequirement> FTMonitorableImpl::getMonitorable2RepGDsts()
{
	std::multiset<RepGRequirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Monitorable2RepG");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			RepGRequirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Monitorable2RepG> FTMonitorableImpl::getOutMonitorable2RepGLinks()
{
	std::set<Monitorable2RepG> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Monitorable2RepG c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Edges
//********************************************************************************
std::multiset<Edge> GraphVertexImpl::getDstEdgeDsts()
{
	std::multiset<Edge> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("DstEdge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Edge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<SrcEdge> GraphVertexImpl::getInSrcEdgeLinks()
{
	std::set<SrcEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		SrcEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<DstEdge> GraphVertexImpl::getOutDstEdgeLinks()
{
	std::set<DstEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		DstEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Edges
//********************************************************************************
std::multiset<Edge> GraphVertexImpl::getSrcEdgeSrcs()
{
	std::multiset<Edge> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("SrcEdge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Edge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ManagesComponent> ManageableImpl::getInManagesComponentLinks()
{
	std::set<ManagesComponent> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ManagesComponent c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src ComponentFactorys
//********************************************************************************
std::multiset<ComponentFactory> ManageableImpl::getManagesComponentSrcs()
{
	std::multiset<ComponentFactory> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ManagesComponent");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentFactory dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst InputActionBases
//********************************************************************************
std::multiset<InputActionBase> MultiInputBaseImpl::getMultiInputDsts()
{
	std::multiset<InputActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MultiInput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			InputActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MultiInput> MultiInputBaseImpl::getOutMultiInputLinks()
{
	std::set<MultiInput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MultiInput c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// getter for role "DstEdge" among "DstEdge"s
//********************************************************************************
std::set<DstEdge> ConnectedComponentImpl::getDstEdge()
{
	std::set<DstEdge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DstEdge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DstEdge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InEventPort" among "Port"s and its descendants
//********************************************************************************
std::set<InEventPort> ConnectedComponentImpl::getInEventPort()
{
	std::set<InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutEventPort" among "Port"s and its descendants
//********************************************************************************
std::set<OutEventPort> ConnectedComponentImpl::getOutEventPort()
{
	std::set<OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Port"s and its descendants
//********************************************************************************
std::set<Port> ConnectedComponentImpl::getPort()
{
	std::set<Port> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("InEventPort");
	roles_vec[1] = ModelImpl::getChildFCOsAs("OutEventPort");
	roles_vec[2] = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	roles_vec[3] = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Port elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "ProvidedRequestPort" among "Port"s and its descendants
//********************************************************************************
std::set<ProvidedRequestPort> ConnectedComponentImpl::getProvidedRequestPort()
{
	std::set<ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RequiredRequestPort" among "Port"s and its descendants
//********************************************************************************
std::set<RequiredRequestPort> ConnectedComponentImpl::getRequiredRequestPort()
{
	std::set<RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Member" among "Member"s
//********************************************************************************
std::set<Member> ExceptionImpl::getMember()
{
	std::set<Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Aggregate" among "NamedType"s and its descendants
//********************************************************************************
std::set<Aggregate> FileImpl::getAggregate()
{
	std::set<Aggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Aggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Aggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Alias" among "NamedType"s and its descendants
//********************************************************************************
std::set<Alias> FileImpl::getAlias()
{
	std::set<Alias> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Alias");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Alias elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Boxed" among "NamedType"s and its descendants
//********************************************************************************
std::set<Boxed> FileImpl::getBoxed()
{
	std::set<Boxed> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Boxed");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Boxed elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Collection" among "NamedType"s and its descendants
//********************************************************************************
std::set<Collection> FileImpl::getCollection()
{
	std::set<Collection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Collection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Collection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Component" among "NamedType"s and its descendants
//********************************************************************************
std::set<Component> FileImpl::getComponent()
{
	std::set<Component> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Component");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Component elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentFactory" among "NamedType"s and its descendants
//********************************************************************************
std::set<ComponentFactory> FileImpl::getComponentFactory()
{
	std::set<ComponentFactory> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentFactory");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentFactory elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> FileImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Constant" among "Constant"s
//********************************************************************************
std::set<Constant> FileImpl::getConstant()
{
	std::set<Constant> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Constant");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Constant elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Enum" among "NamedType"s and its descendants
//********************************************************************************
std::set<Enum> FileImpl::getEnum()
{
	std::set<Enum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Enum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Enum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Event" among "NamedType"s and its descendants
//********************************************************************************
std::set<Event> FileImpl::getEvent()
{
	std::set<Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Exception" among "Exception"s
//********************************************************************************
std::set<Exception> FileImpl::getException()
{
	std::set<Exception> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Exception");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Exception elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FileRef" among "FileRef"s
//********************************************************************************
std::set<FileRef> FileImpl::getFileRef()
{
	std::set<FileRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FileRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FileRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ManagesComponent" among "ManagesComponent"s
//********************************************************************************
std::set<ManagesComponent> FileImpl::getManagesComponent()
{
	std::set<ManagesComponent> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ManagesComponent");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ManagesComponent elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "NamedType"s and its descendants
//********************************************************************************
std::set<NamedType> FileImpl::getNamedType()
{
	std::set<NamedType> res;
	const int len = 11;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Aggregate");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Component");
	roles_vec[2] = ModelImpl::getChildFCOsAs("ComponentFactory");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Enum");
	roles_vec[4] = ModelImpl::getChildFCOsAs("Event");
	roles_vec[5] = ModelImpl::getChildFCOsAs("Object");
	roles_vec[6] = ModelImpl::getChildFCOsAs("SwitchedAggregate");
	roles_vec[7] = ModelImpl::getChildFCOsAs("ValueObject");
	roles_vec[8] = ModelImpl::getChildFCOsAs("Alias");
	roles_vec[9] = ModelImpl::getChildFCOsAs("Boxed");
	roles_vec[10] = ModelImpl::getChildFCOsAs("Collection");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			NamedType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Object" among "NamedType"s and its descendants
//********************************************************************************
std::set<Object> FileImpl::getObject()
{
	std::set<Object> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Object");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Object elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Package" among "Package"s
//********************************************************************************
std::set<Package> FileImpl::getPackage()
{
	std::set<Package> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Package");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Package elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SwitchedAggregate" among "NamedType"s and its descendants
//********************************************************************************
std::set<SwitchedAggregate> FileImpl::getSwitchedAggregate()
{
	std::set<SwitchedAggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SwitchedAggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SwitchedAggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ValueObject" among "NamedType"s and its descendants
//********************************************************************************
std::set<ValueObject> FileImpl::getValueObject()
{
	std::set<ValueObject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ValueObject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ValueObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InParameter" among "InParameter"s
//********************************************************************************
std::set<InParameter> OperationBaseImpl::getInParameter()
{
	std::set<InParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Aggregate" among "NamedType"s and its descendants
//********************************************************************************
std::set<Aggregate> PackageImpl::getAggregate()
{
	std::set<Aggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Aggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Aggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Alias" among "NamedType"s and its descendants
//********************************************************************************
std::set<Alias> PackageImpl::getAlias()
{
	std::set<Alias> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Alias");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Alias elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Boxed" among "NamedType"s and its descendants
//********************************************************************************
std::set<Boxed> PackageImpl::getBoxed()
{
	std::set<Boxed> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Boxed");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Boxed elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Collection" among "NamedType"s and its descendants
//********************************************************************************
std::set<Collection> PackageImpl::getCollection()
{
	std::set<Collection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Collection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Collection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Component" among "NamedType"s and its descendants
//********************************************************************************
std::set<Component> PackageImpl::getComponent()
{
	std::set<Component> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Component");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Component elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentFactory" among "NamedType"s and its descendants
//********************************************************************************
std::set<ComponentFactory> PackageImpl::getComponentFactory()
{
	std::set<ComponentFactory> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentFactory");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentFactory elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> PackageImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Constant" among "Constant"s
//********************************************************************************
std::set<Constant> PackageImpl::getConstant()
{
	std::set<Constant> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Constant");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Constant elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Enum" among "NamedType"s and its descendants
//********************************************************************************
std::set<Enum> PackageImpl::getEnum()
{
	std::set<Enum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Enum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Enum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Event" among "NamedType"s and its descendants
//********************************************************************************
std::set<Event> PackageImpl::getEvent()
{
	std::set<Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Exception" among "Exception"s
//********************************************************************************
std::set<Exception> PackageImpl::getException()
{
	std::set<Exception> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Exception");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Exception elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ManagesComponent" among "ManagesComponent"s
//********************************************************************************
std::set<ManagesComponent> PackageImpl::getManagesComponent()
{
	std::set<ManagesComponent> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ManagesComponent");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ManagesComponent elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "NamedType"s and its descendants
//********************************************************************************
std::set<NamedType> PackageImpl::getNamedType()
{
	std::set<NamedType> res;
	const int len = 11;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Aggregate");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Component");
	roles_vec[2] = ModelImpl::getChildFCOsAs("ComponentFactory");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Enum");
	roles_vec[4] = ModelImpl::getChildFCOsAs("Event");
	roles_vec[5] = ModelImpl::getChildFCOsAs("Object");
	roles_vec[6] = ModelImpl::getChildFCOsAs("SwitchedAggregate");
	roles_vec[7] = ModelImpl::getChildFCOsAs("ValueObject");
	roles_vec[8] = ModelImpl::getChildFCOsAs("Alias");
	roles_vec[9] = ModelImpl::getChildFCOsAs("Boxed");
	roles_vec[10] = ModelImpl::getChildFCOsAs("Collection");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			NamedType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Object" among "NamedType"s and its descendants
//********************************************************************************
std::set<Object> PackageImpl::getObject()
{
	std::set<Object> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Object");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Object elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Package" among "Package"s
//********************************************************************************
std::set<Package> PackageImpl::getPackage()
{
	std::set<Package> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Package");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Package elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SwitchedAggregate" among "NamedType"s and its descendants
//********************************************************************************
std::set<SwitchedAggregate> PackageImpl::getSwitchedAggregate()
{
	std::set<SwitchedAggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SwitchedAggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SwitchedAggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ValueObject" among "NamedType"s and its descendants
//********************************************************************************
std::set<ValueObject> PackageImpl::getValueObject()
{
	std::set<ValueObject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ValueObject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ValueObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns src AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> ReadonlyAttributeImpl::getAttributeDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeDelegate");
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ReadonlyAttributeImpl::getAttributeValueDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AttributeValue");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeDelegate> ReadonlyAttributeImpl::getInAttributeDelegateLinks()
{
	std::set<AttributeDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeValue> ReadonlyAttributeImpl::getOutAttributeValueLinks()
{
	std::set<AttributeValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "AttributeMember" among "AttributeMember"s
//********************************************************************************
std::set<AttributeMember> ReadonlyAttributeImpl::getAttributeMember()
{
	std::set<AttributeMember> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AttributeMember");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AttributeMember elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "GetException" among "GetException"s
//********************************************************************************
std::set<GetException> ReadonlyAttributeImpl::getGetException()
{
	std::set<GetException> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("GetException");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		GetException elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ComponentRefImpl::getComponentConfigPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ComponentRefImpl::getComponentInfoPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ComponentPropertyDescriptions
//********************************************************************************
std::multiset<ComponentPropertyDescription> ComponentRefImpl::getComponentPropertyDsts()
{
	std::multiset<ComponentPropertyDescription> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ComponentPropertyDescription dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ComponentImplementations
//********************************************************************************
std::multiset<ComponentImplementation> ComponentRefImpl::getImplementsSrcs()
{
	std::multiset<ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Implements");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Implements> ComponentRefImpl::getInImplementsLinks()
{
	std::set<Implements> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Implements c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageInterface> ComponentRefImpl::getInPackageInterfaceLinks()
{
	std::set<PackageInterface> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageInterface c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentConfigProperty> ComponentRefImpl::getOutComponentConfigPropertyLinks()
{
	std::set<ComponentConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentInfoProperty> ComponentRefImpl::getOutComponentInfoPropertyLinks()
{
	std::set<ComponentInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentProperty> ComponentRefImpl::getOutComponentPropertyLinks()
{
	std::set<ComponentProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src ComponentPackages
//********************************************************************************
std::multiset<ComponentPackage> ComponentRefImpl::getPackageInterfaceSrcs()
{
	std::multiset<ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageInterface");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// getter for role "SetException" among "SetException"s
//********************************************************************************
std::set<SetException> AttributeImpl::getSetException()
{
	std::set<SetException> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SetException");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SetException elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ComponentImpl::getAssemblyConfigPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AssemblyConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Requirements
//********************************************************************************
std::multiset<Requirement> ComponentImpl::getAssemblyselectRequirementDsts()
{
	std::multiset<Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AssemblyselectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ExternalReferenceEndPoints
//********************************************************************************
std::multiset<ExternalReferenceEndPoint> ComponentImpl::getExternalDelegateDsts()
{
	std::multiset<ExternalReferenceEndPoint> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ExternalDelegate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ExternalReferenceEndPoint dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<QoSDecoration> ComponentImpl::getInQoSDecorationLinks()
{
	std::set<QoSDecoration> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		QoSDecoration c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AssemblyConfigProperty> ComponentImpl::getOutAssemblyConfigPropertyLinks()
{
	std::set<AssemblyConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AssemblyConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AssemblyselectRequirement> ComponentImpl::getOutAssemblyselectRequirementLinks()
{
	std::set<AssemblyselectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AssemblyselectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ExternalDelegate> ComponentImpl::getOutExternalDelegateLinks()
{
	std::set<ExternalDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ExternalDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src QoSValues
//********************************************************************************
std::multiset<QoSValue> ComponentImpl::getQoSDecorationSrcs()
{
	std::multiset<QoSValue> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("QoSDecoration");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			QoSValue dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// getter for role "Action" among "ActionBase"s and its descendants
//********************************************************************************
std::set<Action> ComponentImpl::getAction()
{
	std::set<Action> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Action");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Action elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "ActionBase"s and its descendants
//********************************************************************************
std::set<ActionBase> ComponentImpl::getActionBase()
{
	std::set<ActionBase> res;
	const int len = 5;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Action");
	roles_vec[1] = ModelImpl::getChildFCOsAs("CompositeAction");
	roles_vec[2] = ModelImpl::getChildFCOsAs("InputAction");
	roles_vec[3] = ModelImpl::getChildFCOsAs("OutputAction");
	roles_vec[4] = ModelImpl::getChildFCOsAs("PeriodicAction");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			ActionBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Attribute" among "ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<Attribute> ComponentImpl::getAttribute()
{
	std::set<Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CompositeAction" among "ActionBase"s and its descendants
//********************************************************************************
std::set<CompositeAction> ComponentImpl::getCompositeAction()
{
	std::set<CompositeAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CompositeAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CompositeAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Effect" among "Effect"s
//********************************************************************************
std::set<Effect> ComponentImpl::getEffect()
{
	std::set<Effect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Effect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Effect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Environment" among "Environment"s
//********************************************************************************
std::set<Environment> ComponentImpl::getEnvironment()
{
	std::set<Environment> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Environment");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Environment elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Finish" among "Finish"s
//********************************************************************************
std::set<Finish> ComponentImpl::getFinish()
{
	std::set<Finish> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Finish");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Finish elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InEventPort" among "Port"s and its descendants
//********************************************************************************
std::set<InEventPort> ComponentImpl::getInEventPort()
{
	std::set<InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Input" among "Input"s
//********************************************************************************
std::set<Input> ComponentImpl::getInput()
{
	std::set<Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InputAction" among "ActionBase"s and its descendants
//********************************************************************************
std::set<InputAction> ComponentImpl::getInputAction()
{
	std::set<InputAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InputAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InputAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MultiInput" among "MultiInput"s
//********************************************************************************
std::set<MultiInput> ComponentImpl::getMultiInput()
{
	std::set<MultiInput> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MultiInput");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MultiInput elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutEventPort" among "Port"s and its descendants
//********************************************************************************
std::set<OutEventPort> ComponentImpl::getOutEventPort()
{
	std::set<OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutputAction" among "ActionBase"s and its descendants
//********************************************************************************
std::set<OutputAction> ComponentImpl::getOutputAction()
{
	std::set<OutputAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutputAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutputAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PeriodicAction" among "ActionBase"s and its descendants
//********************************************************************************
std::set<PeriodicAction> ComponentImpl::getPeriodicAction()
{
	std::set<PeriodicAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PeriodicAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PeriodicAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Port"s and its descendants
//********************************************************************************
std::set<Port> ComponentImpl::getPort()
{
	std::set<Port> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("InEventPort");
	roles_vec[1] = ModelImpl::getChildFCOsAs("OutEventPort");
	roles_vec[2] = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	roles_vec[3] = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Port elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "ProvidedRequestPort" among "Port"s and its descendants
//********************************************************************************
std::set<ProvidedRequestPort> ComponentImpl::getProvidedRequestPort()
{
	std::set<ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ReadonlyAttribute" among "ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<ReadonlyAttribute> ComponentImpl::getReadonlyAttribute()
{
	std::set<ReadonlyAttribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ReadonlyAttribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ReadonlyAttribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<ReadonlyAttribute> ComponentImpl::getReadonlyAttribute(int dummy)
{
	std::set<ReadonlyAttribute> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Attribute");
	roles_vec[1] = ModelImpl::getChildFCOsAs("ReadonlyAttribute");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			ReadonlyAttribute elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "RequiredRequestPort" among "Port"s and its descendants
//********************************************************************************
std::set<RequiredRequestPort> ComponentImpl::getRequiredRequestPort()
{
	std::set<RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "State" among "State"s
//********************************************************************************
std::set<State> ComponentImpl::getState()
{
	std::set<State> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("State");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		State elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Transition" among "Transition"s
//********************************************************************************
std::set<Transition> ComponentImpl::getTransition()
{
	std::set<Transition> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Transition");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Transition elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Variable" among "Variable"s
//********************************************************************************
std::set<Variable> ComponentImpl::getVariable()
{
	std::set<Variable> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Variable");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Variable elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WorkerType" among "WorkerType"s
//********************************************************************************
std::set<WorkerType> ComponentImpl::getWorkerType()
{
	std::set<WorkerType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WorkerType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WorkerType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ExceptionRef" among "ExceptionRef"s
//********************************************************************************
std::set<ExceptionRef> HasExceptionsImpl::getExceptionRef()
{
	std::set<ExceptionRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ExceptionRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ExceptionRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Attribute" among "ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<Attribute> InheritableImpl::getAttribute()
{
	std::set<Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Inherits" among "Inherits"s
//********************************************************************************
std::set<Inherits> InheritableImpl::getInherits()
{
	std::set<Inherits> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Inherits");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Inherits elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ReadonlyAttribute" among "ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<ReadonlyAttribute> InheritableImpl::getReadonlyAttribute()
{
	std::set<ReadonlyAttribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ReadonlyAttribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ReadonlyAttribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<ReadonlyAttribute> InheritableImpl::getReadonlyAttribute(int dummy)
{
	std::set<ReadonlyAttribute> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Attribute");
	roles_vec[1] = ModelImpl::getChildFCOsAs("ReadonlyAttribute");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			ReadonlyAttribute elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
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
// returns dst InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> InEventPortImpl::getEventSinkDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("EventSinkDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<EventSinkDelegate> InEventPortImpl::getEventSinkDelegateLinks()
{
	std::set<EventSinkDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EventSinkDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> InEventPortImpl::getEventSinkDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("EventSinkDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<EventSinkDelegate> InEventPortImpl::getInEventSinkDelegateLinks()
{
	std::set<EventSinkDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EventSinkDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Use_RTEC_Filter> InEventPortImpl::getInUse_RTEC_FilterLinks()
{
	std::set<Use_RTEC_Filter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Use_RTEC_Filter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<deliverTo> InEventPortImpl::getIndeliverToLinks()
{
	std::set<deliverTo> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		deliverTo c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<emit> InEventPortImpl::getInemitLinks()
{
	std::set<emit> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		emit c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst InputActionBases
//********************************************************************************
std::multiset<InputActionBase> InEventPortImpl::getInputDsts()
{
	std::multiset<InputActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Input");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			InputActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<EventSinkDelegate> InEventPortImpl::getOutEventSinkDelegateLinks()
{
	std::set<EventSinkDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EventSinkDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Input> InEventPortImpl::getOutInputLinks()
{
	std::set<Input> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Input c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src RTEC_Filter_Groups
//********************************************************************************
std::multiset<RTEC_Filter_Group> InEventPortImpl::getUse_RTEC_FilterSrcs()
{
	std::multiset<RTEC_Filter_Group> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Use_RTEC_Filter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			RTEC_Filter_Group dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PublishConnectors
//********************************************************************************
std::multiset<PublishConnector> InEventPortImpl::getdeliverToSrcs()
{
	std::multiset<PublishConnector> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("deliverTo");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PublishConnector dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> InEventPortImpl::getemitSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("emit");
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
// returns dst OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> OutEventPortImpl::getEventSourceDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("EventSourceDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<EventSourceDelegate> OutEventPortImpl::getEventSourceDelegateLinks()
{
	std::set<EventSourceDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EventSourceDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> OutEventPortImpl::getEventSourceDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("EventSourceDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<EventSourceDelegate> OutEventPortImpl::getInEventSourceDelegateLinks()
{
	std::set<EventSourceDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EventSourceDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<EventSourceDelegate> OutEventPortImpl::getOutEventSourceDelegateLinks()
{
	std::set<EventSourceDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EventSourceDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<RTEC_Connection> OutEventPortImpl::getOutRTEC_ConnectionLinks()
{
	std::set<RTEC_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		RTEC_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<emit> OutEventPortImpl::getOutemitLinks()
{
	std::set<emit> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		emit c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<publish> OutEventPortImpl::getOutpublishLinks()
{
	std::set<publish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		publish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst RT_Info_Params
//********************************************************************************
std::multiset<RT_Info_Param> OutEventPortImpl::getRTEC_ConnectionDsts()
{
	std::multiset<RT_Info_Param> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("RTEC_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			RT_Info_Param dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> OutEventPortImpl::getemitDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("emit");
}


//********************************************************************************
// returns dst PublishConnectors
//********************************************************************************
std::multiset<PublishConnector> OutEventPortImpl::getpublishDsts()
{
	std::multiset<PublishConnector> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("publish");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PublishConnector dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// returns dst ProvidedRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> ProvidedRequestPortImpl::getFacetDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("FacetDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<FacetDelegate> ProvidedRequestPortImpl::getFacetDelegateLinks()
{
	std::set<FacetDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		FacetDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src ProvidedRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> ProvidedRequestPortImpl::getFacetDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("FacetDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<FacetDelegate> ProvidedRequestPortImpl::getInFacetDelegateLinks()
{
	std::set<FacetDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		FacetDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<invoke> ProvidedRequestPortImpl::getIninvokeLinks()
{
	std::set<invoke> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		invoke c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<FacetDelegate> ProvidedRequestPortImpl::getOutFacetDelegateLinks()
{
	std::set<FacetDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		FacetDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src RequiredRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> ProvidedRequestPortImpl::getinvokeSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("invoke");
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
std::set<ReceptacleDelegate> RequiredRequestPortImpl::getInReceptacleDelegateLinks()
{
	std::set<ReceptacleDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ReceptacleDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ReceptacleDelegate> RequiredRequestPortImpl::getOutReceptacleDelegateLinks()
{
	std::set<ReceptacleDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ReceptacleDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<invoke> RequiredRequestPortImpl::getOutinvokeLinks()
{
	std::set<invoke> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		invoke c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst RequiredRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> RequiredRequestPortImpl::getReceptacleDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("ReceptacleDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<ReceptacleDelegate> RequiredRequestPortImpl::getReceptacleDelegateLinks()
{
	std::set<ReceptacleDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ReceptacleDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src RequiredRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> RequiredRequestPortImpl::getReceptacleDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("ReceptacleDelegate");
}


//********************************************************************************
// returns dst ProvidedRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> RequiredRequestPortImpl::getinvokeDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("invoke");
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
// getter for role "Member" among "Member"s
//********************************************************************************
std::set<Member> AggregateImpl::getMember()
{
	std::set<Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "EnumValue" among "EnumValue"s
//********************************************************************************
std::set<EnumValue> EnumImpl::getEnumValue()
{
	std::set<EnumValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EnumValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		EnumValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Aggregate" among "NoInheritable"s and its descendants
//********************************************************************************
std::set<Aggregate> HasOperationsImpl::getAggregate()
{
	std::set<Aggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Aggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Aggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Alias" among "NoInheritable"s and its descendants
//********************************************************************************
std::set<Alias> HasOperationsImpl::getAlias()
{
	std::set<Alias> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Alias");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Alias elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Collection" among "NoInheritable"s and its descendants
//********************************************************************************
std::set<Collection> HasOperationsImpl::getCollection()
{
	std::set<Collection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Collection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Collection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Constant" among "Constant"s
//********************************************************************************
std::set<Constant> HasOperationsImpl::getConstant()
{
	std::set<Constant> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Constant");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Constant elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Enum" among "NoInheritable"s and its descendants
//********************************************************************************
std::set<Enum> HasOperationsImpl::getEnum()
{
	std::set<Enum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Enum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Enum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Exception" among "Exception"s
//********************************************************************************
std::set<Exception> HasOperationsImpl::getException()
{
	std::set<Exception> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Exception");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Exception elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "NoInheritable"s and its descendants
//********************************************************************************
std::set<NoInheritable> HasOperationsImpl::getNoInheritable()
{
	std::set<NoInheritable> res;
	const int len = 5;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Aggregate");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Enum");
	roles_vec[2] = ModelImpl::getChildFCOsAs("SwitchedAggregate");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Alias");
	roles_vec[4] = ModelImpl::getChildFCOsAs("Collection");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			NoInheritable elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "OnewayOperation" among "OnewayOperation"s
//********************************************************************************
std::set<OnewayOperation> HasOperationsImpl::getOnewayOperation()
{
	std::set<OnewayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OnewayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OnewayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SwitchedAggregate" among "NoInheritable"s and its descendants
//********************************************************************************
std::set<SwitchedAggregate> HasOperationsImpl::getSwitchedAggregate()
{
	std::set<SwitchedAggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SwitchedAggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SwitchedAggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TwowayOperation" among "TwowayOperation"s
//********************************************************************************
std::set<TwowayOperation> HasOperationsImpl::getTwowayOperation()
{
	std::set<TwowayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TwowayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TwowayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Discriminator" among "Discriminator"s
//********************************************************************************
std::set<Discriminator> SwitchedAggregateImpl::getDiscriminator()
{
	std::set<Discriminator> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Discriminator");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Discriminator elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Label" among "Label"s
//********************************************************************************
std::set<Label> SwitchedAggregateImpl::getLabel()
{
	std::set<Label> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Label");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Label elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "LabelConnection" among "LabelConnection"s
//********************************************************************************
std::set<LabelConnection> SwitchedAggregateImpl::getLabelConnection()
{
	std::set<LabelConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("LabelConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		LabelConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Member" among "Member"s
//********************************************************************************
std::set<Member> SwitchedAggregateImpl::getMember()
{
	std::set<Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InoutParameter" among "InoutParameter"s
//********************************************************************************
std::set<InoutParameter> TwowayOperationImpl::getInoutParameter()
{
	std::set<InoutParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InoutParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InoutParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutParameter" among "OutParameter"s
//********************************************************************************
std::set<OutParameter> TwowayOperationImpl::getOutParameter()
{
	std::set<OutParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ReturnType" among "ReturnType"s
//********************************************************************************
std::set<ReturnType> TwowayOperationImpl::getReturnType()
{
	std::set<ReturnType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ReturnType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ReturnType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// returns dst Manageables
//********************************************************************************
std::multiset<Manageable> ComponentFactoryImpl::getManagesComponentDsts()
{
	std::multiset<Manageable> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ManagesComponent");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Manageable dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ManagesComponent> ComponentFactoryImpl::getOutManagesComponentLinks()
{
	std::set<ManagesComponent> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ManagesComponent c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "FactoryOperation" among "FactoryOperation"s
//********************************************************************************
std::set<FactoryOperation> ComponentFactoryImpl::getFactoryOperation()
{
	std::set<FactoryOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FactoryOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FactoryOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "LookupKey" among "LookupKey"s
//********************************************************************************
std::set<LookupKey> ComponentFactoryImpl::getLookupKey()
{
	std::set<LookupKey> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("LookupKey");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		LookupKey elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "LookupOperation" among "LookupOperation"s
//********************************************************************************
std::set<LookupOperation> ComponentFactoryImpl::getLookupOperation()
{
	std::set<LookupOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("LookupOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		LookupOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// getter for role "FactoryOperation" among "FactoryOperation"s
//********************************************************************************
std::set<FactoryOperation> ObjectByValueImpl::getFactoryOperation()
{
	std::set<FactoryOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FactoryOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FactoryOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MakeMemberPrivate" among "MakeMemberPrivate"s
//********************************************************************************
std::set<MakeMemberPrivate> ObjectByValueImpl::getMakeMemberPrivate()
{
	std::set<MakeMemberPrivate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MakeMemberPrivate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MakeMemberPrivate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Member" among "Member"s
//********************************************************************************
std::set<Member> ObjectByValueImpl::getMember()
{
	std::set<Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PrivateFlag" among "PrivateFlag"s
//********************************************************************************
std::set<PrivateFlag> ObjectByValueImpl::getPrivateFlag()
{
	std::set<PrivateFlag> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PrivateFlag");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PrivateFlag elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// getter for role "SatisfierProperty" among "SatisfierProperty"s
//********************************************************************************
std::set<SatisfierProperty> RequirementSatisfierImpl::getSatisfierProperty()
{
	std::set<SatisfierProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SatisfierProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SatisfierProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst Interconnects
//********************************************************************************
std::multiset<Interconnect> BridgeImpl::getBridge2InterconnectDsts()
{
	std::multiset<Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Bridge2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Interconnect2Bridge> BridgeImpl::getInInterconnect2BridgeLinks()
{
	std::set<Interconnect2Bridge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Interconnect2Bridge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Interconnects
//********************************************************************************
std::multiset<Interconnect> BridgeImpl::getInterconnect2BridgeSrcs()
{
	std::multiset<Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Interconnect2Bridge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Bridge2Interconnect> BridgeImpl::getOutBridge2InterconnectLinks()
{
	std::set<Bridge2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Bridge2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// getter for role "Resource" among "Resource"s
//********************************************************************************
std::set<Resource> BridgeImpl::getResource()
{
	std::set<Resource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Resource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Resource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns src ComponentImplementations
//********************************************************************************
std::multiset<ComponentImplementation> CapabilityImpl::getImplementationCapabilitySrcs()
{
	std::multiset<ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ImplementationCapability");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ImplementationCapability> CapabilityImpl::getInImplementationCapabilityLinks()
{
	std::set<ImplementationCapability> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ImplementationCapability c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Bridges
//********************************************************************************
std::multiset<Bridge> InterconnectImpl::getBridge2InterconnectSrcs()
{
	std::multiset<Bridge> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Bridge2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Bridge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Bridge2Interconnect> InterconnectImpl::getInBridge2InterconnectLinks()
{
	std::set<Bridge2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Bridge2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Node2Interconnect> InterconnectImpl::getInNode2InterconnectLinks()
{
	std::set<Node2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Node2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Bridges
//********************************************************************************
std::multiset<Bridge> InterconnectImpl::getInterconnect2BridgeDsts()
{
	std::multiset<Bridge> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Interconnect2Bridge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Bridge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Nodes
//********************************************************************************
std::multiset<Node> InterconnectImpl::getInterconnect2NodeDsts()
{
	std::multiset<Node> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Interconnect2Node");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Node dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Nodes
//********************************************************************************
std::multiset<Node> InterconnectImpl::getNode2InterconnectSrcs()
{
	std::multiset<Node> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Node2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Node dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Interconnect2Bridge> InterconnectImpl::getOutInterconnect2BridgeLinks()
{
	std::set<Interconnect2Bridge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Interconnect2Bridge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Interconnect2Node> InterconnectImpl::getOutInterconnect2NodeLinks()
{
	std::set<Interconnect2Node> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Interconnect2Node c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// getter for role "Resource" among "Resource"s
//********************************************************************************
std::set<Resource> InterconnectImpl::getResource()
{
	std::set<Resource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Resource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Resource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Interconnect2Node> NodeImpl::getInInterconnect2NodeLinks()
{
	std::set<Interconnect2Node> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Interconnect2Node c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Interconnects
//********************************************************************************
std::multiset<Interconnect> NodeImpl::getInterconnect2NodeSrcs()
{
	std::multiset<Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Interconnect2Node");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Interconnects
//********************************************************************************
std::multiset<Interconnect> NodeImpl::getNode2InterconnectDsts()
{
	std::multiset<Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Node2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Node2Interconnect> NodeImpl::getOutNode2InterconnectLinks()
{
	std::set<Node2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Node2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Shares> NodeImpl::getOutSharesLinks()
{
	std::set<Shares> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Shares c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst SharedResources
//********************************************************************************
std::multiset<SharedResource> NodeImpl::getSharesDsts()
{
	std::multiset<SharedResource> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Shares");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			SharedResource dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// getter for role "Resource" among "Resource"s
//********************************************************************************
std::set<Resource> NodeImpl::getResource()
{
	std::set<Resource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Resource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Resource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Shares> SharedResourceImpl::getInSharesLinks()
{
	std::set<Shares> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Shares c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Nodes
//********************************************************************************
std::multiset<Node> SharedResourceImpl::getSharesSrcs()
{
	std::multiset<Node> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Shares");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Node dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "Null_RT_Info" among "RT_Info_Param"s and its descendants
//********************************************************************************
std::set<Null_RT_Info> RTEC_ProxyImpl::getNull_RT_Info()
{
	std::set<Null_RT_Info> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Null_RT_Info");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Null_RT_Info elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RT_Info" among "RT_Info_Param"s and its descendants
//********************************************************************************
std::set<RT_Info> RTEC_ProxyImpl::getRT_Info()
{
	std::set<RT_Info> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RT_Info");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RT_Info elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "RT_Info_Param"s and its descendants
//********************************************************************************
std::set<RT_Info_Param> RTEC_ProxyImpl::getRT_Info_Param()
{
	std::set<RT_Info_Param> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Null_RT_Info");
	roles_vec[1] = ModelImpl::getChildFCOsAs("RT_Info");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			RT_Info_Param elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "RTEC_Resource_Factory_Reference" among "RTEC_Resource_Factory_Reference"s
//********************************************************************************
std::set<RTEC_Resource_Factory_Reference> RTEC_Proxy_ConsumerImpl::getRTEC_Resource_Factory_Reference()
{
	std::set<RTEC_Resource_Factory_Reference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RTEC_Resource_Factory_Reference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RTEC_Resource_Factory_Reference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Use_RT_Info" among "Use_RT_Info"s
//********************************************************************************
std::set<Use_RT_Info> RTEC_Proxy_ConsumerImpl::getUse_RT_Info()
{
	std::set<Use_RT_Info> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Use_RT_Info");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Use_RT_Info elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ConjunctionGroup" among "RTEC_Filter_Group"s and its descendants
//********************************************************************************
std::set<ConjunctionGroup> RTEC_Proxy_SupplierImpl::getConjunctionGroup()
{
	std::set<ConjunctionGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ConjunctionGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ConjunctionGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "DisjunctionGroup" among "RTEC_Filter_Group"s and its descendants
//********************************************************************************
std::set<DisjunctionGroup> RTEC_Proxy_SupplierImpl::getDisjunctionGroup()
{
	std::set<DisjunctionGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DisjunctionGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DisjunctionGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Include_RTEC_Filter_Group" among "Include_RTEC_Filter_Group"s
//********************************************************************************
std::set<Include_RTEC_Filter_Group> RTEC_Proxy_SupplierImpl::getInclude_RTEC_Filter_Group()
{
	std::set<Include_RTEC_Filter_Group> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Include_RTEC_Filter_Group");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Include_RTEC_Filter_Group elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Include_RT_Info" among "Include_RT_Info"s
//********************************************************************************
std::set<Include_RT_Info> RTEC_Proxy_SupplierImpl::getInclude_RT_Info()
{
	std::set<Include_RT_Info> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Include_RT_Info");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Include_RT_Info elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "LogicalANDGroup" among "RTEC_Filter_Group"s and its descendants
//********************************************************************************
std::set<LogicalANDGroup> RTEC_Proxy_SupplierImpl::getLogicalANDGroup()
{
	std::set<LogicalANDGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("LogicalANDGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		LogicalANDGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "RTEC_Filter_Group"s and its descendants
//********************************************************************************
std::set<RTEC_Filter_Group> RTEC_Proxy_SupplierImpl::getRTEC_Filter_Group()
{
	std::set<RTEC_Filter_Group> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("ConjunctionGroup");
	roles_vec[1] = ModelImpl::getChildFCOsAs("DisjunctionGroup");
	roles_vec[2] = ModelImpl::getChildFCOsAs("LogicalANDGroup");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			RTEC_Filter_Group elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
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
// getter for role "QoSCharacteristicRef" among "QoSCharacteristicRef"s
//********************************************************************************
std::set<QoSCharacteristicRef> QoSCharacteristicImpl::getQoSCharacteristicRef()
{
	std::set<QoSCharacteristicRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSCharacteristicRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSCharacteristicRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSDimension" among "QoSDimension"s
//********************************************************************************
std::set<QoSDimension> QoSCharacteristicImpl::getQoSDimension()
{
	std::set<QoSDimension> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSDimension");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSDimension elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSParameter" among "QoSParameter"s
//********************************************************************************
std::set<QoSParameter> QoSCharacteristicImpl::getQoSParameter()
{
	std::set<QoSParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> RequirementBaseImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MonolithDeployRequirement> ImplementationRequirementImpl::getInMonolithDeployRequirementLinks()
{
	std::set<MonolithDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MonolithDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src MonolithicImplementations
//********************************************************************************
std::multiset<MonolithicImplementation> ImplementationRequirementImpl::getMonolithDeployRequirementSrcs()
{
	std::multiset<MonolithicImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MonolithDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			MonolithicImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// returns src ImplementationArtifacts
//********************************************************************************
std::multiset<ImplementationArtifact> RequirementImpl::getArtifactDeployRequirementSrcs()
{
	std::multiset<ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PublishConnectors
//********************************************************************************
std::multiset<PublishConnector> RequirementImpl::getAssemblyDeployRequirementSrcs()
{
	std::multiset<PublishConnector> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("AssemblyDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PublishConnector dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Components
//********************************************************************************
std::multiset<Component> RequirementImpl::getAssemblyselectRequirementSrcs()
{
	std::multiset<Component> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("AssemblyselectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Component dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactDeployRequirement> RequirementImpl::getInArtifactDeployRequirementLinks()
{
	std::set<ArtifactDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AssemblyDeployRequirement> RequirementImpl::getInAssemblyDeployRequirementLinks()
{
	std::set<AssemblyDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AssemblyDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AssemblyselectRequirement> RequirementImpl::getInAssemblyselectRequirementLinks()
{
	std::set<AssemblyselectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AssemblyselectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfSelectRequirement> RequirementImpl::getInPackageConfSelectRequirementLinks()
{
	std::set<PackageConfSelectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfSelectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PackageConfigurations
//********************************************************************************
std::multiset<PackageConfiguration> RequirementImpl::getPackageConfSelectRequirementSrcs()
{
	std::multiset<PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfSelectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ReqConnection> FOU_RequirementImpl::getInReqConnectionLinks()
{
	std::set<ReqConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ReqConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src FTComposites
//********************************************************************************
std::multiset<FTComposite> FOU_RequirementImpl::getReqConnectionSrcs()
{
	std::multiset<FTComposite> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ReqConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			FTComposite dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Monitorable2RepG> RepGRequirementImpl::getInMonitorable2RepGLinks()
{
	std::set<Monitorable2RepG> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Monitorable2RepG c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src FTMonitorables
//********************************************************************************
std::multiset<FTMonitorable> RepGRequirementImpl::getMonitorable2RepGSrcs()
{
	std::multiset<FTMonitorable> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Monitorable2RepG");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			FTMonitorable dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> OperationImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FaultMessage" among "FaultMessage"s
//********************************************************************************
std::set<FaultMessage> OperationImpl::getFaultMessage()
{
	std::set<FaultMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FaultMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FaultMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InputMessage" among "InputMessage"s
//********************************************************************************
std::set<InputMessage> OperationImpl::getInputMessage()
{
	std::set<InputMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InputMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InputMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MessageRef" among "MessageRef"s
//********************************************************************************
std::set<MessageRef> OperationImpl::getMessageRef()
{
	std::set<MessageRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MessageRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MessageRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutputMessage" among "OutputMessage"s
//********************************************************************************
std::set<OutputMessage> OperationImpl::getOutputMessage()
{
	std::set<OutputMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutputMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutputMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Output" among "Output"s
//********************************************************************************
std::set<Output> NotificationOperationImpl::getOutput()
{
	std::set<Output> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Output");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Output elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Input" among "Input"s
//********************************************************************************
std::set<Input> OneWayOperationImpl::getInput()
{
	std::set<Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string RequestResponseOperationImpl::getparameterOrder() 
{
	return FCOImpl::getAttribute("parameterOrder")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void RequestResponseOperationImpl::setparameterOrder( const std::string& val)
{
	FCOImpl::getAttribute("parameterOrder")->setStringValue( val);
}


//********************************************************************************
// getter for role "Fault" among "Fault"s
//********************************************************************************
std::set<Fault> RequestResponseOperationImpl::getFault()
{
	std::set<Fault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Fault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Fault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Input" among "Input"s
//********************************************************************************
std::set<Input> RequestResponseOperationImpl::getInput()
{
	std::set<Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Output" among "Output"s
//********************************************************************************
std::set<Output> RequestResponseOperationImpl::getOutput()
{
	std::set<Output> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Output");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Output elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string SolicitResponseOperationImpl::getparameterOrder() 
{
	return FCOImpl::getAttribute("parameterOrder")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void SolicitResponseOperationImpl::setparameterOrder( const std::string& val)
{
	FCOImpl::getAttribute("parameterOrder")->setStringValue( val);
}


//********************************************************************************
// getter for role "Fault" among "Fault"s
//********************************************************************************
std::set<Fault> SolicitResponseOperationImpl::getFault()
{
	std::set<Fault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Fault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Fault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Input" among "Input"s
//********************************************************************************
std::set<Input> SolicitResponseOperationImpl::getInput()
{
	std::set<Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Output" among "Output"s
//********************************************************************************
std::set<Output> SolicitResponseOperationImpl::getOutput()
{
	std::set<Output> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Output");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Output elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst States
//********************************************************************************
std::multiset<State> ActionBaseImpl::getEffectDsts()
{
	std::multiset<State> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Effect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			State dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Transition> ActionBaseImpl::getInTransitionLinks()
{
	std::set<Transition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Transition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Effect> ActionBaseImpl::getOutEffectLinks()
{
	std::set<Effect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Effect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src States
//********************************************************************************
std::multiset<State> ActionBaseImpl::getTransitionSrcs()
{
	std::multiset<State> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Transition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			State dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
long ActionBaseImpl::getRepetitions() 
{
	return FCOImpl::getAttribute("Repetitions")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
bool ActionBaseImpl::isLogAction() 
{
	return FCOImpl::getAttribute("LogAction")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ActionBaseImpl::setLogAction( bool val)
{
	FCOImpl::getAttribute("LogAction")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ActionBaseImpl::setRepetitions( const long val)
{
	FCOImpl::getAttribute("Repetitions")->setIntegerValue( val);
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> ActionBaseImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Action" among "Action"s and its descendants
//********************************************************************************
std::set<Action> CompositeActionImpl::getAction()
{
	std::set<Action> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Action");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Action elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Action"s and its descendants
//********************************************************************************
std::set<Action> CompositeActionImpl::getAction(int dummy)
{
	std::set<Action> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("CompositeAction");
	roles_vec[1] = ModelImpl::getChildFCOsAs("OutputAction");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Action");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Action elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "CompositeAction" among "Action"s and its descendants
//********************************************************************************
std::set<CompositeAction> CompositeActionImpl::getCompositeAction()
{
	std::set<CompositeAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CompositeAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CompositeAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Effect" among "Effect"s
//********************************************************************************
std::set<Effect> CompositeActionImpl::getEffect()
{
	std::set<Effect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Effect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Effect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Finish" among "Finish"s
//********************************************************************************
std::set<Finish> CompositeActionImpl::getFinish()
{
	std::set<Finish> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Finish");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Finish elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InputAction" among "InputAction"s
//********************************************************************************
std::set<InputAction> CompositeActionImpl::getInputAction()
{
	std::set<InputAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InputAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InputAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutputAction" among "Action"s and its descendants
//********************************************************************************
std::set<OutputAction> CompositeActionImpl::getOutputAction()
{
	std::set<OutputAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutputAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutputAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "State" among "State"s
//********************************************************************************
std::set<State> CompositeActionImpl::getState()
{
	std::set<State> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("State");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		State elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Transition" among "Transition"s
//********************************************************************************
std::set<Transition> CompositeActionImpl::getTransition()
{
	std::set<Transition> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Transition");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Transition elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst ExternalResourcess
//********************************************************************************
std::multiset<ExternalResources> ComponentLibImpl::getExtResourceConnDsts()
{
	std::multiset<ExternalResources> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ExtResourceConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ExternalResources dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ExtResourceConn> ComponentLibImpl::getOutExtResourceConnLinks()
{
	std::set<ExtResourceConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ExtResourceConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// getter for role "ImplementationArtifactReference" among "ImplementationArtifactReference"s
//********************************************************************************
std::set<ImplementationArtifactReference> ExecutorProjectImpl::getImplementationArtifactReference()
{
	std::set<ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FileRef" among "FileRef"s
//********************************************************************************
std::set<FileRef> ServantProjectImpl::getFileRef()
{
	std::set<FileRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FileRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FileRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationArtifactReference" among "ImplementationArtifactReference"s
//********************************************************************************
std::set<ImplementationArtifactReference> ServantProjectImpl::getImplementationArtifactReference()
{
	std::set<ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FileRef" among "FileRef"s
//********************************************************************************
std::set<FileRef> StubProjectImpl::getFileRef()
{
	std::set<FileRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FileRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FileRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationArtifactReference" among "ImplementationArtifactReference"s
//********************************************************************************
std::set<ImplementationArtifactReference> StubProjectImpl::getImplementationArtifactReference()
{
	std::set<ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ConnectionBand" among "ConnectionBand"s
//********************************************************************************
std::set<ConnectionBand> BandedConnectionImpl::getConnectionBand()
{
	std::set<ConnectionBand> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ConnectionBand");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ConnectionBand elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// getter for role "ThreadPoolLane" among "ThreadPoolLane"s
//********************************************************************************
std::set<ThreadPoolLane> SimpleThreadPoolImpl::getThreadPoolLane()
{
	std::set<ThreadPoolLane> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ThreadPoolLane");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ThreadPoolLane elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// getter for role "ThreadPoolLane" among "ThreadPoolLane"s
//********************************************************************************
std::set<ThreadPoolLane> ThreadPoolWithLanesImpl::getThreadPoolLane()
{
	std::set<ThreadPoolLane> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ThreadPoolLane");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ThreadPoolLane elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns src States
//********************************************************************************
std::multiset<State> InputActionBaseImpl::getFinishSrcs()
{
	std::multiset<State> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Finish");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			State dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Finish> InputActionBaseImpl::getInFinishLinks()
{
	std::set<Finish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Finish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Input> InputActionBaseImpl::getInInputLinks()
{
	std::set<Input> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Input c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MultiInput> InputActionBaseImpl::getInMultiInputLinks()
{
	std::set<MultiInput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MultiInput c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src InEventPorts
//********************************************************************************
std::multiset<InEventPort> InputActionBaseImpl::getInputSrcs()
{
	std::multiset<InEventPort> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Input");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			InEventPort dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src MultiInputBases
//********************************************************************************
std::multiset<MultiInputBase> InputActionBaseImpl::getMultiInputSrcs()
{
	std::multiset<MultiInputBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MultiInput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			MultiInputBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> InputActionBaseImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
double PeriodicActionImpl::getProbability() 
{
	return FCOImpl::getAttribute("Probability")->getRealValue();
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
void PeriodicActionImpl::setProbability( const double val)
{
	FCOImpl::getAttribute("Probability")->setRealValue( val);
}


//********************************************************************************
// returns src BenchmarkTypes
//********************************************************************************
std::multiset<BenchmarkType> MetricsBaseImpl::getBenchmarkCharacteristicsSrcs()
{
	std::multiset<BenchmarkType> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BenchmarkCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			BenchmarkType dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BenchmarkCharacteristics> MetricsBaseImpl::getInBenchmarkCharacteristicsLinks()
{
	std::set<BenchmarkCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BenchmarkCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MetricConnection> MetricsBaseImpl::getInMetricConnectionLinks()
{
	std::set<MetricConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MetricConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src OperationRefs
//********************************************************************************
std::multiset<OperationRef> MetricsBaseImpl::getMetricConnectionSrcs()
{
	std::multiset<OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MetricConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<WorkloadCharacteristics> MetricsBaseImpl::getOutWorkloadCharacteristicsLinks()
{
	std::set<WorkloadCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WorkloadCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst TaskSets
//********************************************************************************
std::multiset<TaskSet> MetricsBaseImpl::getWorkloadCharacteristicsDsts()
{
	std::multiset<TaskSet> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("WorkloadCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			TaskSet dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// getter for role "Average" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Average> MetricsBaseImpl::getAverage()
{
	std::set<Average> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Average");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Average elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<DataAnalysisBase> MetricsBaseImpl::getDataAnalysisBase()
{
	std::set<DataAnalysisBase> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Average");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Jitter");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Maximum");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Minimum");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			DataAnalysisBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Jitter" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Jitter> MetricsBaseImpl::getJitter()
{
	std::set<Jitter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Jitter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Jitter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Maximum" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Maximum> MetricsBaseImpl::getMaximum()
{
	std::set<Maximum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Maximum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Maximum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Minimum" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Minimum> MetricsBaseImpl::getMinimum()
{
	std::set<Minimum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Minimum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Minimum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
double SharedRiskCompositeImpl::getMetric() 
{
	return FCOImpl::getAttribute("Metric")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
void SharedRiskCompositeImpl::setMetric( const double val)
{
	FCOImpl::getAttribute("Metric")->setRealValue( val);
}


//********************************************************************************
// getter for role "NodeRef" among "NodeRef"s
//********************************************************************************
std::set<NodeRef> SharedRiskCompositeImpl::getNodeRef()
{
	std::set<NodeRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("NodeRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		NodeRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "NodeGroup" among "SharedRiskComposite"s and its descendants
//********************************************************************************
std::set<NodeGroup> SharedRiskGroupImpl::getNodeGroup()
{
	std::set<NodeGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("NodeGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		NodeGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SharedResourceRef" among "SharedResourceRef"s
//********************************************************************************
std::set<SharedResourceRef> SharedRiskGroupImpl::getSharedResourceRef()
{
	std::set<SharedResourceRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SharedResourceRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SharedResourceRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "SharedRiskComposite"s and its descendants
//********************************************************************************
std::set<SharedRiskComposite> SharedRiskGroupImpl::getSharedRiskComposite()
{
	std::set<SharedRiskComposite> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("NodeGroup");
	roles_vec[1] = ModelImpl::getChildFCOsAs("SharedRiskGroup");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			SharedRiskComposite elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "SharedRiskGroup" among "SharedRiskComposite"s and its descendants
//********************************************************************************
std::set<SharedRiskGroup> SharedRiskGroupImpl::getSharedRiskGroup()
{
	std::set<SharedRiskGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SharedRiskGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SharedRiskGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ReqConnection> FTCompositeImpl::getOutReqConnectionLinks()
{
	std::set<ReqConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ReqConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst FOU_Requirements
//********************************************************************************
std::multiset<FOU_Requirement> FTCompositeImpl::getReqConnectionDsts()
{
	std::multiset<FOU_Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ReqConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			FOU_Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentAssemblyReference" among "FTMonitorable"s and its descendants
//********************************************************************************
std::set<ComponentAssemblyReference> FTCompositeImpl::getComponentAssemblyReference()
{
	std::set<ComponentAssemblyReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentAssemblyReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentAssemblyReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "FTMonitorable"s and its descendants
//********************************************************************************
std::set<ComponentRef> FTCompositeImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "FTMonitorable"s and its descendants
//********************************************************************************
std::set<FTMonitorable> FTCompositeImpl::getFTMonitorable()
{
	std::set<FTMonitorable> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("ComponentAssemblyReference");
	roles_vec[1] = ModelImpl::getChildFCOsAs("ComponentRef");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			FTMonitorable elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Monitorable2RepG" among "Monitorable2RepG"s
//********************************************************************************
std::set<Monitorable2RepG> FTCompositeImpl::getMonitorable2RepG()
{
	std::set<Monitorable2RepG> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Monitorable2RepG");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Monitorable2RepG elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RepGRequirement" among "RepGRequirement"s
//********************************************************************************
std::set<RepGRequirement> FTCompositeImpl::getRepGRequirement()
{
	std::set<RepGRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RepGRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RepGRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string SchemaReferenceImpl::getid() 
{
	return FCOImpl::getAttribute("id")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string SchemaReferenceImpl::getschemaLocation() 
{
	return FCOImpl::getAttribute("schemaLocation")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void SchemaReferenceImpl::setid( const std::string& val)
{
	FCOImpl::getAttribute("id")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void SchemaReferenceImpl::setschemaLocation( const std::string& val)
{
	FCOImpl::getAttribute("schemaLocation")->setStringValue( val);
}


//********************************************************************************
// getter for role "Schema" among "Schema"s
//********************************************************************************
std::set<Schema> SchemaReferenceImpl::getSchema()
{
	std::set<Schema> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Schema");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Schema elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string SchemaImportImpl::getnamespace() 
{
	return FCOImpl::getAttribute("namespace")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void SchemaImportImpl::setnamespace( const std::string& val)
{
	FCOImpl::getAttribute("namespace")->setStringValue( val);
}


//********************************************************************************
// getter for role "Worker" among "Worker"s
//********************************************************************************
std::set<Worker> WorkerPackageImpl::getWorker()
{
	std::set<Worker> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Worker");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Worker elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WorkerPackage" among "WorkerPackage"s
//********************************************************************************
std::set<WorkerPackage> WorkerPackageImpl::getWorkerPackage()
{
	std::set<WorkerPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WorkerPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WorkerPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string WorkerFileImpl::getLocation() 
{
	return FCOImpl::getAttribute("Location")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void WorkerFileImpl::setLocation( const std::string& val)
{
	FCOImpl::getAttribute("Location")->setStringValue( val);
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ComponentImplementationImpl::getConfigPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Capabilitys
//********************************************************************************
std::multiset<Capability> ComponentImplementationImpl::getImplementationCapabilityDsts()
{
	std::multiset<Capability> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ImplementationCapability");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Capability dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ImplementationDependencys
//********************************************************************************
std::multiset<ImplementationDependency> ComponentImplementationImpl::getImplementationDependsOnDsts()
{
	std::multiset<ImplementationDependency> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ImplementationDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ImplementationDependency dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ComponentRefs
//********************************************************************************
std::multiset<ComponentRef> ComponentImplementationImpl::getImplementsDsts()
{
	std::multiset<ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Implements");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ComponentImplementationImpl::getInfoPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("InfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ConfigProperty> ComponentImplementationImpl::getOutConfigPropertyLinks()
{
	std::set<ConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ImplementationCapability> ComponentImplementationImpl::getOutImplementationCapabilityLinks()
{
	std::set<ImplementationCapability> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ImplementationCapability c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ImplementationDependsOn> ComponentImplementationImpl::getOutImplementationDependsOnLinks()
{
	std::set<ImplementationDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ImplementationDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Implements> ComponentImplementationImpl::getOutImplementsLinks()
{
	std::set<Implements> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Implements c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<InfoProperty> ComponentImplementationImpl::getOutInfoPropertyLinks()
{
	std::set<InfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		InfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// returns dst PathReferences
//********************************************************************************
std::multiset<PathReference> ComponentAssemblyImpl::getCriticalPathDsts()
{
	std::multiset<PathReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("CriticalPath");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PathReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<CriticalPath> ComponentAssemblyImpl::getOutCriticalPathLinks()
{
	std::set<CriticalPath> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		CriticalPath c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "AssemblyConfigProperty" among "AssemblyConfigProperty"s
//********************************************************************************
std::set<AssemblyConfigProperty> ComponentAssemblyImpl::getAssemblyConfigProperty()
{
	std::set<AssemblyConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AssemblyConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AssemblyConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "AssemblyDeployRequirement" among "AssemblyDeployRequirement"s
//********************************************************************************
std::set<AssemblyDeployRequirement> ComponentAssemblyImpl::getAssemblyDeployRequirement()
{
	std::set<AssemblyDeployRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AssemblyDeployRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AssemblyDeployRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "AssemblyselectRequirement" among "AssemblyselectRequirement"s
//********************************************************************************
std::set<AssemblyselectRequirement> ComponentAssemblyImpl::getAssemblyselectRequirement()
{
	std::set<AssemblyselectRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AssemblyselectRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AssemblyselectRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "AttributeDelegate" among "AttributeDelegate"s
//********************************************************************************
std::set<AttributeDelegate> ComponentAssemblyImpl::getAttributeDelegate()
{
	std::set<AttributeDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AttributeDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AttributeDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "AttributeMapping" among "AttributeMapping"s
//********************************************************************************
std::set<AttributeMapping> ComponentAssemblyImpl::getAttributeMapping()
{
	std::set<AttributeMapping> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AttributeMapping");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AttributeMapping elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "AttributeMappingDelegate" among "AttributeMappingDelegate"s
//********************************************************************************
std::set<AttributeMappingDelegate> ComponentAssemblyImpl::getAttributeMappingDelegate()
{
	std::set<AttributeMappingDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AttributeMappingDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AttributeMappingDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "AttributeMappingValue" among "AttributeMappingValue"s
//********************************************************************************
std::set<AttributeMappingValue> ComponentAssemblyImpl::getAttributeMappingValue()
{
	std::set<AttributeMappingValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AttributeMappingValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AttributeMappingValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "AttributeValue" among "AttributeValue"s
//********************************************************************************
std::set<AttributeValue> ComponentAssemblyImpl::getAttributeValue()
{
	std::set<AttributeValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AttributeValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AttributeValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Component" among "Component"s
//********************************************************************************
std::set<Component> ComponentAssemblyImpl::getComponent()
{
	std::set<Component> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Component");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Component elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentAssembly" among "ComponentAssembly"s
//********************************************************************************
std::set<ComponentAssembly> ComponentAssemblyImpl::getComponentAssembly()
{
	std::set<ComponentAssembly> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentAssembly");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentAssembly elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentAssemblyReference" among "ComponentAssemblyReference"s
//********************************************************************************
std::set<ComponentAssemblyReference> ComponentAssemblyImpl::getComponentAssemblyReference()
{
	std::set<ComponentAssemblyReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentAssemblyReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentAssemblyReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentPackage" among "ComponentPackage"s
//********************************************************************************
std::set<ComponentPackage> ComponentAssemblyImpl::getComponentPackage()
{
	std::set<ComponentPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentPackageReference" among "ComponentPackageReference"s
//********************************************************************************
std::set<ComponentPackageReference> ComponentAssemblyImpl::getComponentPackageReference()
{
	std::set<ComponentPackageReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentPackageReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentPackageReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> ComponentAssemblyImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "EventSinkDelegate" among "EventSinkDelegate"s
//********************************************************************************
std::set<EventSinkDelegate> ComponentAssemblyImpl::getEventSinkDelegate()
{
	std::set<EventSinkDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EventSinkDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		EventSinkDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "EventSourceDelegate" among "EventSourceDelegate"s
//********************************************************************************
std::set<EventSourceDelegate> ComponentAssemblyImpl::getEventSourceDelegate()
{
	std::set<EventSourceDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EventSourceDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		EventSourceDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ExternalDelegate" among "ExternalDelegate"s
//********************************************************************************
std::set<ExternalDelegate> ComponentAssemblyImpl::getExternalDelegate()
{
	std::set<ExternalDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ExternalDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ExternalDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ExternalReferenceEndPoint" among "ExternalReferenceEndPoint"s
//********************************************************************************
std::set<ExternalReferenceEndPoint> ComponentAssemblyImpl::getExternalReferenceEndPoint()
{
	std::set<ExternalReferenceEndPoint> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ExternalReferenceEndPoint");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ExternalReferenceEndPoint elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FOU_Requirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<FOU_Requirement> ComponentAssemblyImpl::getFOU_Requirement()
{
	std::set<FOU_Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FOU_Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FOU_Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FacetDelegate" among "FacetDelegate"s
//********************************************************************************
std::set<FacetDelegate> ComponentAssemblyImpl::getFacetDelegate()
{
	std::set<FacetDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FacetDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FacetDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InEventPort" among "InEventPort"s
//********************************************************************************
std::set<InEventPort> ComponentAssemblyImpl::getInEventPort()
{
	std::set<InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutEventPort" among "OutEventPort"s
//********************************************************************************
std::set<OutEventPort> ComponentAssemblyImpl::getOutEventPort()
{
	std::set<OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> ComponentAssemblyImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ProvidedRequestPort" among "ProvidedRequestPort"s
//********************************************************************************
std::set<ProvidedRequestPort> ComponentAssemblyImpl::getProvidedRequestPort()
{
	std::set<ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PublishConnector" among "PublishConnector"s
//********************************************************************************
std::set<PublishConnector> ComponentAssemblyImpl::getPublishConnector()
{
	std::set<PublishConnector> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PublishConnector");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PublishConnector elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSDecoration" among "QoSDecoration"s
//********************************************************************************
std::set<QoSDecoration> ComponentAssemblyImpl::getQoSDecoration()
{
	std::set<QoSDecoration> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSDecoration");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSDecoration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSValue" among "QoSValue"s
//********************************************************************************
std::set<QoSValue> ComponentAssemblyImpl::getQoSValue()
{
	std::set<QoSValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ReceptacleDelegate" among "ReceptacleDelegate"s
//********************************************************************************
std::set<ReceptacleDelegate> ComponentAssemblyImpl::getReceptacleDelegate()
{
	std::set<ReceptacleDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ReceptacleDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ReceptacleDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RepGRequirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<RepGRequirement> ComponentAssemblyImpl::getRepGRequirement()
{
	std::set<RepGRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RepGRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RepGRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RequiredRequestPort" among "RequiredRequestPort"s
//********************************************************************************
std::set<RequiredRequestPort> ComponentAssemblyImpl::getRequiredRequestPort()
{
	std::set<RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Requirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<Requirement> ComponentAssemblyImpl::getRequirement()
{
	std::set<Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Requirement"s and its descendants
//********************************************************************************
std::set<Requirement> ComponentAssemblyImpl::getRequirement(int dummy)
{
	std::set<Requirement> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("FOU_Requirement");
	roles_vec[1] = ModelImpl::getChildFCOsAs("RepGRequirement");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Requirement");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "deliverTo" among "deliverTo"s
//********************************************************************************
std::set<deliverTo> ComponentAssemblyImpl::getdeliverTo()
{
	std::set<deliverTo> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("deliverTo");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		deliverTo elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "emit" among "emit"s
//********************************************************************************
std::set<emit> ComponentAssemblyImpl::getemit()
{
	std::set<emit> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("emit");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		emit elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "invoke" among "invoke"s
//********************************************************************************
std::set<invoke> ComponentAssemblyImpl::getinvoke()
{
	std::set<invoke> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("invoke");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		invoke elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "publish" among "publish"s
//********************************************************************************
std::set<publish> ComponentAssemblyImpl::getpublish()
{
	std::set<publish> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("publish");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		publish elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst ImplementationRequirements
//********************************************************************************
std::multiset<ImplementationRequirement> MonolithicImplementationImpl::getMonolithDeployRequirementDsts()
{
	std::multiset<ImplementationRequirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MonolithDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ImplementationRequirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> MonolithicImplementationImpl::getMonolithExecParameterDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MonolithExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ImplementationArtifactReferences
//********************************************************************************
std::multiset<ImplementationArtifactReference> MonolithicImplementationImpl::getMonolithprimaryArtifactDsts()
{
	std::multiset<ImplementationArtifactReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MonolithprimaryArtifact");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ImplementationArtifactReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MonolithDeployRequirement> MonolithicImplementationImpl::getOutMonolithDeployRequirementLinks()
{
	std::set<MonolithDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MonolithDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MonolithExecParameter> MonolithicImplementationImpl::getOutMonolithExecParameterLinks()
{
	std::set<MonolithExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MonolithExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MonolithprimaryArtifact> MonolithicImplementationImpl::getOutMonolithprimaryArtifactLinks()
{
	std::set<MonolithprimaryArtifact> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MonolithprimaryArtifact c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
bool ExtensibilityElementImpl::isrequired() 
{
	return FCOImpl::getAttribute("required")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ExtensibilityElementImpl::setrequired( bool val)
{
	FCOImpl::getAttribute("required")->setBooleanValue( val);
}


//********************************************************************************
// 
//********************************************************************************
std::string ExtensibleMessageImpl::getencodingStyle() 
{
	return FCOImpl::getAttribute("encodingStyle")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ExtensibleMessageImpl::getnamespace() 
{
	return FCOImpl::getAttribute("namespace")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
ExtensibleMessageImpl::use_Type ExtensibleMessageImpl::getuse()
{
	std::string val = FCOImpl::getAttribute("use")->getStringValue();

	if ( val == "literal") return literal_use_Type;
	else if ( val == "encoded") return encoded_use_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void ExtensibleMessageImpl::setencodingStyle( const std::string& val)
{
	FCOImpl::getAttribute("encodingStyle")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ExtensibleMessageImpl::setnamespace( const std::string& val)
{
	FCOImpl::getAttribute("namespace")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ExtensibleMessageImpl::setuse( ExtensibleMessageImpl::use_Type val)
{
	std::string str_val = "";

	if ( val == literal_use_Type) str_val = "literal";
	else if ( val == encoded_use_Type) str_val = "encoded";
	else throw("None of the possible items");

	FCOImpl::getAttribute("use")->setStringValue( str_val);
}


//********************************************************************************
// returns src IORefs
//********************************************************************************
std::multiset<IORef> SOAPHeadersImpl::getHeaderBindingSrcs()
{
	std::multiset<IORef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("HeaderBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			IORef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst MessageRefs
//********************************************************************************
std::multiset<MessageRef> SOAPHeadersImpl::getHeaderMessageDsts()
{
	std::multiset<MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("HeaderMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PartRefs
//********************************************************************************
std::multiset<PartRef> SOAPHeadersImpl::getHeaderPartDsts()
{
	std::multiset<PartRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("HeaderPart");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PartRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<HeaderBinding> SOAPHeadersImpl::getInHeaderBindingLinks()
{
	std::set<HeaderBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		HeaderBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<HeaderMessage> SOAPHeadersImpl::getOutHeaderMessageLinks()
{
	std::set<HeaderMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		HeaderMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<HeaderPart> SOAPHeadersImpl::getOutHeaderPartLinks()
{
	std::set<HeaderPart> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		HeaderPart c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::string SOAPAddressImpl::getlocation() 
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void SOAPAddressImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
SOAPBindingImpl::style_Type SOAPBindingImpl::getstyle()
{
	std::string val = FCOImpl::getAttribute("style")->getStringValue();

	if ( val == "document") return document_style_Type;
	else if ( val == "rpc") return rpc_style_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
std::string SOAPBindingImpl::gettransport() 
{
	return FCOImpl::getAttribute("transport")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void SOAPBindingImpl::setstyle( SOAPBindingImpl::style_Type val)
{
	std::string str_val = "";

	if ( val == document_style_Type) str_val = "document";
	else if ( val == rpc_style_Type) str_val = "rpc";
	else throw("None of the possible items");

	FCOImpl::getAttribute("style")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void SOAPBindingImpl::settransport( const std::string& val)
{
	FCOImpl::getAttribute("transport")->setStringValue( val);
}


//********************************************************************************
// returns src IORefs
//********************************************************************************
std::multiset<IORef> SOAPBodyImpl::getBodyBindingSrcs()
{
	std::multiset<IORef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BodyBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			IORef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PartRefs
//********************************************************************************
std::multiset<PartRef> SOAPBodyImpl::getBodyPartsDsts()
{
	std::multiset<PartRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BodyParts");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PartRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BodyBinding> SOAPBodyImpl::getInBodyBindingLinks()
{
	std::set<BodyBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BodyBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BodyParts> SOAPBodyImpl::getOutBodyPartsLinks()
{
	std::set<BodyParts> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BodyParts c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<SOAPFaultExtension> SOAPFaultImpl::getInSOAPFaultExtensionLinks()
{
	std::set<SOAPFaultExtension> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		SOAPFaultExtension c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src FaultRefs
//********************************************************************************
std::multiset<FaultRef> SOAPFaultImpl::getSOAPFaultExtensionSrcs()
{
	std::multiset<FaultRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("SOAPFaultExtension");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			FaultRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string SOAPOperationImpl::getsoapAction() 
{
	return FCOImpl::getAttribute("soapAction")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
SOAPOperationImpl::style_Type SOAPOperationImpl::getstyle()
{
	std::string val = FCOImpl::getAttribute("style")->getStringValue();

	if ( val == "document") return document_style_Type;
	else if ( val == "rpc") return rpc_style_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void SOAPOperationImpl::setsoapAction( const std::string& val)
{
	FCOImpl::getAttribute("soapAction")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void SOAPOperationImpl::setstyle( SOAPOperationImpl::style_Type val)
{
	std::string str_val = "";

	if ( val == document_style_Type) str_val = "document";
	else if ( val == rpc_style_Type) str_val = "rpc";
	else throw("None of the possible items");

	FCOImpl::getAttribute("style")->setStringValue( str_val);
}


//********************************************************************************
// getter for role "SOAPHeaderFault" among "SOAPHeaderFault"s
//********************************************************************************
std::set<SOAPHeaderFault> SOAPHeaderImpl::getSOAPHeaderFault()
{
	std::set<SOAPHeaderFault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPHeaderFault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPHeaderFault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
long ElementImpl::getOrder() 
{
	return FCOImpl::getAttribute("Order")->getIntegerValue();
}


//********************************************************************************
// 
//********************************************************************************
ElementImpl::schemaType_Type ElementImpl::getschemaType()
{
	std::string val = FCOImpl::getAttribute("schemaType")->getStringValue();

	if ( val == "local") return local_schemaType_Type;
	else if ( val == "element") return element_schemaType_Type;
	else if ( val == "attribute") return attribute_schemaType_Type;
	else if ( val == "complexType") return complexType_schemaType_Type;
	else if ( val == "simpleType") return simpleType_schemaType_Type;
	else if ( val == "include") return include_schemaType_Type;
	else if ( val == "import") return import_schemaType_Type;
	else if ( val == "redefine") return redefine_schemaType_Type;
	else if ( val == "any") return any_schemaType_Type;
	else if ( val == "anyAttribute") return anyAttribute_schemaType_Type;
	else if ( val == "group") return group_schemaType_Type;
	else if ( val == "attributeGroup") return attributeGroup_schemaType_Type;
	else if ( val == "key") return key_schemaType_Type;
	else if ( val == "keyref") return keyref_schemaType_Type;
	else if ( val == "unique") return unique_schemaType_Type;
	else if ( val == "annotation") return annotation_schemaType_Type;
	else if ( val == "documentation") return documentation_schemaType_Type;
	else if ( val == "appinfo") return appinfo_schemaType_Type;
	else if ( val == "notation") return notation_schemaType_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void ElementImpl::setOrder( const long val)
{
	FCOImpl::getAttribute("Order")->setIntegerValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ElementImpl::setschemaType( ElementImpl::schemaType_Type val)
{
	std::string str_val = "";

	if ( val == local_schemaType_Type) str_val = "local";
	else if ( val == element_schemaType_Type) str_val = "element";
	else if ( val == attribute_schemaType_Type) str_val = "attribute";
	else if ( val == complexType_schemaType_Type) str_val = "complexType";
	else if ( val == simpleType_schemaType_Type) str_val = "simpleType";
	else if ( val == include_schemaType_Type) str_val = "include";
	else if ( val == import_schemaType_Type) str_val = "import";
	else if ( val == redefine_schemaType_Type) str_val = "redefine";
	else if ( val == any_schemaType_Type) str_val = "any";
	else if ( val == anyAttribute_schemaType_Type) str_val = "anyAttribute";
	else if ( val == group_schemaType_Type) str_val = "group";
	else if ( val == attributeGroup_schemaType_Type) str_val = "attributeGroup";
	else if ( val == key_schemaType_Type) str_val = "key";
	else if ( val == keyref_schemaType_Type) str_val = "keyref";
	else if ( val == unique_schemaType_Type) str_val = "unique";
	else if ( val == annotation_schemaType_Type) str_val = "annotation";
	else if ( val == documentation_schemaType_Type) str_val = "documentation";
	else if ( val == appinfo_schemaType_Type) str_val = "appinfo";
	else if ( val == notation_schemaType_Type) str_val = "notation";
	else throw("None of the possible items");

	FCOImpl::getAttribute("schemaType")->setStringValue( str_val);
}


//********************************************************************************
// getter for role "Attribute" among "Attribute"s
//********************************************************************************
std::set<Attribute> ElementImpl::getAttribute()
{
	std::set<Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Element" among "Element"s
//********************************************************************************
std::set<Element> ElementImpl::getElement()
{
	std::set<Element> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Element");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Element elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
AtomicTypeImpl::typeCode_Type AtomicTypeImpl::gettypeCode()
{
	std::string val = FCOImpl::getAttribute("typeCode")->getStringValue();

	if ( val == "string") return string_typeCode_Type;
	else if ( val == "boolean") return boolean_typeCode_Type;
	else if ( val == "float") return float_typeCode_Type;
	else if ( val == "double") return double_typeCode_Type;
	else if ( val == "decimal") return decimal_typeCode_Type;
	else if ( val == "duration") return duration_typeCode_Type;
	else if ( val == "dateTime") return dateTime_typeCode_Type;
	else if ( val == "time") return time_typeCode_Type;
	else if ( val == "date") return date_typeCode_Type;
	else if ( val == "gYearMonth") return gYearMonth_typeCode_Type;
	else if ( val == "gYear") return gYear_typeCode_Type;
	else if ( val == "gMonthDay") return gMonthDay_typeCode_Type;
	else if ( val == "gDay") return gDay_typeCode_Type;
	else if ( val == "gMonth") return gMonth_typeCode_Type;
	else if ( val == "hexBinary") return hexBinary_typeCode_Type;
	else if ( val == "base64Binary") return base64Binary_typeCode_Type;
	else if ( val == "anyURI") return anyURI_typeCode_Type;
	else if ( val == "QName") return QName_typeCode_Type;
	else if ( val == "NOTATION") return NOTATION_typeCode_Type;
	else if ( val == "normalizedString") return normalizedString_typeCode_Type;
	else if ( val == "token") return token_typeCode_Type;
	else if ( val == "language") return language_typeCode_Type;
	else if ( val == "IDREFS") return IDREFS_typeCode_Type;
	else if ( val == "ENTITIES") return ENTITIES_typeCode_Type;
	else if ( val == "NMTOKEN") return NMTOKEN_typeCode_Type;
	else if ( val == "NMTOKENS") return NMTOKENS_typeCode_Type;
	else if ( val == "name") return name_typeCode_Type;
	else if ( val == "NCName") return NCName_typeCode_Type;
	else if ( val == "ID") return ID_typeCode_Type;
	else if ( val == "IDREF") return IDREF_typeCode_Type;
	else if ( val == "ENTITY") return ENTITY_typeCode_Type;
	else if ( val == "integer") return integer_typeCode_Type;
	else if ( val == "nonPositiveInteger") return nonPositiveInteger_typeCode_Type;
	else if ( val == "negativeInteger") return negativeInteger_typeCode_Type;
	else if ( val == "long") return long_typeCode_Type;
	else if ( val == "int") return int_typeCode_Type;
	else if ( val == "short") return short_typeCode_Type;
	else if ( val == "byte") return byte_typeCode_Type;
	else if ( val == "nonNegativeInteger") return nonNegativeInteger_typeCode_Type;
	else if ( val == "unsignedLong") return unsignedLong_typeCode_Type;
	else if ( val == "unsignedInt") return unsignedInt_typeCode_Type;
	else if ( val == "unsignedShort") return unsignedShort_typeCode_Type;
	else if ( val == "unsignedByte") return unsignedByte_typeCode_Type;
	else if ( val == "positiveInteger") return positiveInteger_typeCode_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void AtomicTypeImpl::settypeCode( AtomicTypeImpl::typeCode_Type val)
{
	std::string str_val = "";

	if ( val == string_typeCode_Type) str_val = "string";
	else if ( val == boolean_typeCode_Type) str_val = "boolean";
	else if ( val == float_typeCode_Type) str_val = "float";
	else if ( val == double_typeCode_Type) str_val = "double";
	else if ( val == decimal_typeCode_Type) str_val = "decimal";
	else if ( val == duration_typeCode_Type) str_val = "duration";
	else if ( val == dateTime_typeCode_Type) str_val = "dateTime";
	else if ( val == time_typeCode_Type) str_val = "time";
	else if ( val == date_typeCode_Type) str_val = "date";
	else if ( val == gYearMonth_typeCode_Type) str_val = "gYearMonth";
	else if ( val == gYear_typeCode_Type) str_val = "gYear";
	else if ( val == gMonthDay_typeCode_Type) str_val = "gMonthDay";
	else if ( val == gDay_typeCode_Type) str_val = "gDay";
	else if ( val == gMonth_typeCode_Type) str_val = "gMonth";
	else if ( val == hexBinary_typeCode_Type) str_val = "hexBinary";
	else if ( val == base64Binary_typeCode_Type) str_val = "base64Binary";
	else if ( val == anyURI_typeCode_Type) str_val = "anyURI";
	else if ( val == QName_typeCode_Type) str_val = "QName";
	else if ( val == NOTATION_typeCode_Type) str_val = "NOTATION";
	else if ( val == normalizedString_typeCode_Type) str_val = "normalizedString";
	else if ( val == token_typeCode_Type) str_val = "token";
	else if ( val == language_typeCode_Type) str_val = "language";
	else if ( val == IDREFS_typeCode_Type) str_val = "IDREFS";
	else if ( val == ENTITIES_typeCode_Type) str_val = "ENTITIES";
	else if ( val == NMTOKEN_typeCode_Type) str_val = "NMTOKEN";
	else if ( val == NMTOKENS_typeCode_Type) str_val = "NMTOKENS";
	else if ( val == name_typeCode_Type) str_val = "name";
	else if ( val == NCName_typeCode_Type) str_val = "NCName";
	else if ( val == ID_typeCode_Type) str_val = "ID";
	else if ( val == IDREF_typeCode_Type) str_val = "IDREF";
	else if ( val == ENTITY_typeCode_Type) str_val = "ENTITY";
	else if ( val == integer_typeCode_Type) str_val = "integer";
	else if ( val == nonPositiveInteger_typeCode_Type) str_val = "nonPositiveInteger";
	else if ( val == negativeInteger_typeCode_Type) str_val = "negativeInteger";
	else if ( val == long_typeCode_Type) str_val = "long";
	else if ( val == int_typeCode_Type) str_val = "int";
	else if ( val == short_typeCode_Type) str_val = "short";
	else if ( val == byte_typeCode_Type) str_val = "byte";
	else if ( val == nonNegativeInteger_typeCode_Type) str_val = "nonNegativeInteger";
	else if ( val == unsignedLong_typeCode_Type) str_val = "unsignedLong";
	else if ( val == unsignedInt_typeCode_Type) str_val = "unsignedInt";
	else if ( val == unsignedShort_typeCode_Type) str_val = "unsignedShort";
	else if ( val == unsignedByte_typeCode_Type) str_val = "unsignedByte";
	else if ( val == positiveInteger_typeCode_Type) str_val = "positiveInteger";
	else throw("None of the possible items");

	FCOImpl::getAttribute("typeCode")->setStringValue( str_val);
}


//********************************************************************************
// getter for role "ArtifactDependency" among "ArtifactDependency"s
//********************************************************************************
std::set<ArtifactDependency> ArtifactContainerImpl::getArtifactDependency()
{
	std::set<ArtifactDependency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ArtifactDependency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ArtifactDependency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ArtifactDependsOn" among "ArtifactDependsOn"s
//********************************************************************************
std::set<ArtifactDependsOn> ArtifactContainerImpl::getArtifactDependsOn()
{
	std::set<ArtifactDependsOn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ArtifactDependsOn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ArtifactDependsOn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ArtifactDeployRequirement" among "ArtifactDeployRequirement"s
//********************************************************************************
std::set<ArtifactDeployRequirement> ArtifactContainerImpl::getArtifactDeployRequirement()
{
	std::set<ArtifactDeployRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ArtifactDeployRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ArtifactDeployRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ArtifactExecParameter" among "ArtifactExecParameter"s
//********************************************************************************
std::set<ArtifactExecParameter> ArtifactContainerImpl::getArtifactExecParameter()
{
	std::set<ArtifactExecParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ArtifactExecParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ArtifactExecParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ArtifactInfoProperty" among "ArtifactInfoProperty"s
//********************************************************************************
std::set<ArtifactInfoProperty> ArtifactContainerImpl::getArtifactInfoProperty()
{
	std::set<ArtifactInfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ArtifactInfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ArtifactInfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FOU_Requirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<FOU_Requirement> ArtifactContainerImpl::getFOU_Requirement()
{
	std::set<FOU_Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FOU_Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FOU_Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationArtifact" among "ImplementationArtifact"s
//********************************************************************************
std::set<ImplementationArtifact> ArtifactContainerImpl::getImplementationArtifact()
{
	std::set<ImplementationArtifact> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationArtifact");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationArtifact elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationArtifactReference" among "ImplementationArtifactReference"s
//********************************************************************************
std::set<ImplementationArtifactReference> ArtifactContainerImpl::getImplementationArtifactReference()
{
	std::set<ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> ArtifactContainerImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RepGRequirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<RepGRequirement> ArtifactContainerImpl::getRepGRequirement()
{
	std::set<RepGRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RepGRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RepGRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Requirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<Requirement> ArtifactContainerImpl::getRequirement()
{
	std::set<Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Requirement"s and its descendants
//********************************************************************************
std::set<Requirement> ArtifactContainerImpl::getRequirement(int dummy)
{
	std::set<Requirement> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("FOU_Requirement");
	roles_vec[1] = ModelImpl::getChildFCOsAs("RepGRequirement");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Requirement");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Average" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Average> BenchmarkAnalysisImpl::getAverage()
{
	std::set<Average> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Average");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Average elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BenchmarkCharacteristics" among "BenchmarkCharacteristics"s
//********************************************************************************
std::set<BenchmarkCharacteristics> BenchmarkAnalysisImpl::getBenchmarkCharacteristics()
{
	std::set<BenchmarkCharacteristics> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BenchmarkCharacteristics");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BenchmarkCharacteristics elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "BenchmarkType"s and its descendants
//********************************************************************************
std::set<BenchmarkType> BenchmarkAnalysisImpl::getBenchmarkType()
{
	std::set<BenchmarkType> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("FixedIterationBenchmarks");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PeriodicBenchmarks");
	roles_vec[2] = ModelImpl::getChildFCOsAs("TriggerBenchmarks");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			BenchmarkType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "CompRef" among "CompRef"s
//********************************************************************************
std::set<CompRef> BenchmarkAnalysisImpl::getCompRef()
{
	std::set<CompRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CompRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CompRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentOperation" among "ComponentOperation"s
//********************************************************************************
std::set<ComponentOperation> BenchmarkAnalysisImpl::getComponentOperation()
{
	std::set<ComponentOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<DataAnalysisBase> BenchmarkAnalysisImpl::getDataAnalysisBase()
{
	std::set<DataAnalysisBase> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Average");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Jitter");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Maximum");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Minimum");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			DataAnalysisBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Event" among "Event"s
//********************************************************************************
std::set<Event> BenchmarkAnalysisImpl::getEvent()
{
	std::set<Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "EventRef" among "EventRef"s
//********************************************************************************
std::set<EventRef> BenchmarkAnalysisImpl::getEventRef()
{
	std::set<EventRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EventRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		EventRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FactoryOperation" among "OperationBase"s and its descendants
//********************************************************************************
std::set<FactoryOperation> BenchmarkAnalysisImpl::getFactoryOperation()
{
	std::set<FactoryOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FactoryOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FactoryOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FixedIterationBenchmarks" among "BenchmarkType"s and its descendants
//********************************************************************************
std::set<FixedIterationBenchmarks> BenchmarkAnalysisImpl::getFixedIterationBenchmarks()
{
	std::set<FixedIterationBenchmarks> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FixedIterationBenchmarks");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FixedIterationBenchmarks elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Jitter" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Jitter> BenchmarkAnalysisImpl::getJitter()
{
	std::set<Jitter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Jitter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Jitter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Latency" among "MetricsBase"s and its descendants
//********************************************************************************
std::set<Latency> BenchmarkAnalysisImpl::getLatency()
{
	std::set<Latency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Latency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Latency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "LookupOperation" among "OperationBase"s and its descendants
//********************************************************************************
std::set<LookupOperation> BenchmarkAnalysisImpl::getLookupOperation()
{
	std::set<LookupOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("LookupOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		LookupOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Maximum" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Maximum> BenchmarkAnalysisImpl::getMaximum()
{
	std::set<Maximum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Maximum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Maximum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MetricConnection" among "MetricConnection"s
//********************************************************************************
std::set<MetricConnection> BenchmarkAnalysisImpl::getMetricConnection()
{
	std::set<MetricConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MetricConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MetricConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "MetricsBase"s and its descendants
//********************************************************************************
std::set<MetricsBase> BenchmarkAnalysisImpl::getMetricsBase()
{
	std::set<MetricsBase> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Latency");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Throughput");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			MetricsBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Minimum" among "DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<Minimum> BenchmarkAnalysisImpl::getMinimum()
{
	std::set<Minimum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Minimum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Minimum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OnewayOperation" among "OperationBase"s and its descendants
//********************************************************************************
std::set<OnewayOperation> BenchmarkAnalysisImpl::getOnewayOperation()
{
	std::set<OnewayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OnewayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OnewayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "OperationBase"s and its descendants
//********************************************************************************
std::set<OperationBase> BenchmarkAnalysisImpl::getOperationBase()
{
	std::set<OperationBase> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("FactoryOperation");
	roles_vec[1] = ModelImpl::getChildFCOsAs("LookupOperation");
	roles_vec[2] = ModelImpl::getChildFCOsAs("OnewayOperation");
	roles_vec[3] = ModelImpl::getChildFCOsAs("TwowayOperation");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			OperationBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "OperationRef" among "OperationRef"s
//********************************************************************************
std::set<OperationRef> BenchmarkAnalysisImpl::getOperationRef()
{
	std::set<OperationRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OperationRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OperationRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PeriodicBenchmarks" among "BenchmarkType"s and its descendants
//********************************************************************************
std::set<PeriodicBenchmarks> BenchmarkAnalysisImpl::getPeriodicBenchmarks()
{
	std::set<PeriodicBenchmarks> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PeriodicBenchmarks");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PeriodicBenchmarks elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Task" among "Task"s
//********************************************************************************
std::set<Task> BenchmarkAnalysisImpl::getTask()
{
	std::set<Task> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Task");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Task elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TaskSet" among "TaskSet"s
//********************************************************************************
std::set<TaskSet> BenchmarkAnalysisImpl::getTaskSet()
{
	std::set<TaskSet> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TaskSet");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TaskSet elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Throughput" among "MetricsBase"s and its descendants
//********************************************************************************
std::set<Throughput> BenchmarkAnalysisImpl::getThroughput()
{
	std::set<Throughput> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Throughput");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Throughput elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TimeProbe" among "TimeProbe"s
//********************************************************************************
std::set<TimeProbe> BenchmarkAnalysisImpl::getTimeProbe()
{
	std::set<TimeProbe> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TimeProbe");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TimeProbe elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TimerConnection" among "TimerConnection"s
//********************************************************************************
std::set<TimerConnection> BenchmarkAnalysisImpl::getTimerConnection()
{
	std::set<TimerConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TimerConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TimerConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TimerEventSinkConn" among "TimerEventSinkConn"s
//********************************************************************************
std::set<TimerEventSinkConn> BenchmarkAnalysisImpl::getTimerEventSinkConn()
{
	std::set<TimerEventSinkConn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TimerEventSinkConn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TimerEventSinkConn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TriggerBenchmarks" among "BenchmarkType"s and its descendants
//********************************************************************************
std::set<TriggerBenchmarks> BenchmarkAnalysisImpl::getTriggerBenchmarks()
{
	std::set<TriggerBenchmarks> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TriggerBenchmarks");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TriggerBenchmarks elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TwowayOperation" among "OperationBase"s and its descendants
//********************************************************************************
std::set<TwowayOperation> BenchmarkAnalysisImpl::getTwowayOperation()
{
	std::set<TwowayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TwowayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TwowayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WorkLoadOperationConnection" among "WorkLoadOperationConnection"s
//********************************************************************************
std::set<WorkLoadOperationConnection> BenchmarkAnalysisImpl::getWorkLoadOperationConnection()
{
	std::set<WorkLoadOperationConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WorkLoadOperationConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WorkLoadOperationConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WorkloadCharacteristics" among "WorkloadCharacteristics"s
//********************************************************************************
std::set<WorkloadCharacteristics> BenchmarkAnalysisImpl::getWorkloadCharacteristics()
{
	std::set<WorkloadCharacteristics> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WorkloadCharacteristics");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WorkloadCharacteristics elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst PortTypes
//********************************************************************************
std::multiset<PortType> BindingImpl::getBindingPortTypeDsts()
{
	std::multiset<PortType> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BindingPortType");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PortType dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BindingPortType> BindingImpl::getOutBindingPortTypeLinks()
{
	std::set<BindingPortType> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BindingPortType c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "BindingOperation" among "BindingOperation"s
//********************************************************************************
std::set<BindingOperation> BindingImpl::getBindingOperation()
{
	std::set<BindingOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BindingOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BindingOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BindsOperation" among "BindsOperation"s
//********************************************************************************
std::set<BindsOperation> BindingImpl::getBindsOperation()
{
	std::set<BindsOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BindsOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BindsOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> BindingImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OperationRef" among "OperationRef"s
//********************************************************************************
std::set<OperationRef> BindingImpl::getOperationRef()
{
	std::set<OperationRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OperationRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OperationRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPBinding" among "ExtensibleBinding"s
//********************************************************************************
std::set<SOAPBinding> BindingImpl::getSOAPBinding()
{
	std::set<SOAPBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst OperationRefs
//********************************************************************************
std::multiset<OperationRef> BindingOperationImpl::getBindsOperationDsts()
{
	std::multiset<OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BindsOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BindsOperation> BindingOperationImpl::getOutBindsOperationLinks()
{
	std::set<BindsOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BindsOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "BodyBinding" among "BodyBinding"s
//********************************************************************************
std::set<BodyBinding> BindingOperationImpl::getBodyBinding()
{
	std::set<BodyBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BodyBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BodyBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BodyParts" among "BodyParts"s
//********************************************************************************
std::set<BodyParts> BindingOperationImpl::getBodyParts()
{
	std::set<BodyParts> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BodyParts");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BodyParts elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> BindingOperationImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<ExtensibleMessage> BindingOperationImpl::getExtensibleMessage()
{
	std::set<ExtensibleMessage> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("SOAPBody");
	roles_vec[1] = ModelImpl::getChildFCOsAs("SOAPFault");
	roles_vec[2] = ModelImpl::getChildFCOsAs("SOAPHeaderFault");
	roles_vec[3] = ModelImpl::getChildFCOsAs("SOAPHeader");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			ExtensibleMessage elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "FaultRef" among "FaultRef"s
//********************************************************************************
std::set<FaultRef> BindingOperationImpl::getFaultRef()
{
	std::set<FaultRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FaultRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FaultRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "HeaderBinding" among "HeaderBinding"s
//********************************************************************************
std::set<HeaderBinding> BindingOperationImpl::getHeaderBinding()
{
	std::set<HeaderBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("HeaderBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		HeaderBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "HeaderMessage" among "HeaderMessage"s
//********************************************************************************
std::set<HeaderMessage> BindingOperationImpl::getHeaderMessage()
{
	std::set<HeaderMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("HeaderMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		HeaderMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "HeaderPart" among "HeaderPart"s
//********************************************************************************
std::set<HeaderPart> BindingOperationImpl::getHeaderPart()
{
	std::set<HeaderPart> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("HeaderPart");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		HeaderPart elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "IORef"s and its descendants
//********************************************************************************
std::set<IORef> BindingOperationImpl::getIORef()
{
	std::set<IORef> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("InputRef");
	roles_vec[1] = ModelImpl::getChildFCOsAs("OutputRef");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			IORef elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "InputRef" among "IORef"s and its descendants
//********************************************************************************
std::set<InputRef> BindingOperationImpl::getInputRef()
{
	std::set<InputRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InputRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InputRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MessageRef" among "MessageRef"s
//********************************************************************************
std::set<MessageRef> BindingOperationImpl::getMessageRef()
{
	std::set<MessageRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MessageRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MessageRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutputRef" among "IORef"s and its descendants
//********************************************************************************
std::set<OutputRef> BindingOperationImpl::getOutputRef()
{
	std::set<OutputRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutputRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutputRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PartRef" among "PartRef"s
//********************************************************************************
std::set<PartRef> BindingOperationImpl::getPartRef()
{
	std::set<PartRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PartRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PartRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPBody" among "ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<SOAPBody> BindingOperationImpl::getSOAPBody()
{
	std::set<SOAPBody> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPBody");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPBody elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPFault" among "ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<SOAPFault> BindingOperationImpl::getSOAPFault()
{
	std::set<SOAPFault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPFault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPFault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPFaultExtension" among "SOAPFaultExtension"s
//********************************************************************************
std::set<SOAPFaultExtension> BindingOperationImpl::getSOAPFaultExtension()
{
	std::set<SOAPFaultExtension> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPFaultExtension");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPFaultExtension elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPHeader" among "ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<SOAPHeader> BindingOperationImpl::getSOAPHeader()
{
	std::set<SOAPHeader> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPHeader");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPHeader elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPHeaderFault" among "ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<SOAPHeaderFault> BindingOperationImpl::getSOAPHeaderFault()
{
	std::set<SOAPHeaderFault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPHeaderFault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPHeaderFault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPOperation" among "ExtensibleOperation"s
//********************************************************************************
std::set<SOAPOperation> BindingOperationImpl::getSOAPOperation()
{
	std::set<SOAPOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentConfigProperty" among "ComponentConfigProperty"s
//********************************************************************************
std::set<ComponentConfigProperty> ComponentContainerImpl::getComponentConfigProperty()
{
	std::set<ComponentConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentInfoProperty" among "ComponentInfoProperty"s
//********************************************************************************
std::set<ComponentInfoProperty> ComponentContainerImpl::getComponentInfoProperty()
{
	std::set<ComponentInfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentInfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentInfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentProperty" among "ComponentProperty"s
//********************************************************************************
std::set<ComponentProperty> ComponentContainerImpl::getComponentProperty()
{
	std::set<ComponentProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentPropertyDescription" among "ComponentPropertyDescription"s
//********************************************************************************
std::set<ComponentPropertyDescription> ComponentContainerImpl::getComponentPropertyDescription()
{
	std::set<ComponentPropertyDescription> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentPropertyDescription");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentPropertyDescription elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> ComponentContainerImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> ComponentContainerImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Capability" among "Capability"s
//********************************************************************************
std::set<Capability> ComponentImplementationContainerImpl::getCapability()
{
	std::set<Capability> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Capability");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Capability elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentAssembly" among "ComponentImplementation"s and its descendants
//********************************************************************************
std::set<ComponentAssembly> ComponentImplementationContainerImpl::getComponentAssembly()
{
	std::set<ComponentAssembly> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentAssembly");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentAssembly elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "ComponentImplementation"s and its descendants
//********************************************************************************
std::set<ComponentImplementation> ComponentImplementationContainerImpl::getComponentImplementation()
{
	std::set<ComponentImplementation> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("MonolithicImplementation");
	roles_vec[1] = ModelImpl::getChildFCOsAs("ComponentAssembly");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			ComponentImplementation elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> ComponentImplementationContainerImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ConfigProperty" among "ConfigProperty"s
//********************************************************************************
std::set<ConfigProperty> ComponentImplementationContainerImpl::getConfigProperty()
{
	std::set<ConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CriticalPath" among "CriticalPath"s
//********************************************************************************
std::set<CriticalPath> ComponentImplementationContainerImpl::getCriticalPath()
{
	std::set<CriticalPath> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CriticalPath");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CriticalPath elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationArtifactReference" among "ImplementationArtifactReference"s
//********************************************************************************
std::set<ImplementationArtifactReference> ComponentImplementationContainerImpl::getImplementationArtifactReference()
{
	std::set<ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationCapability" among "ImplementationCapability"s
//********************************************************************************
std::set<ImplementationCapability> ComponentImplementationContainerImpl::getImplementationCapability()
{
	std::set<ImplementationCapability> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationCapability");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationCapability elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationDependency" among "ImplementationDependency"s
//********************************************************************************
std::set<ImplementationDependency> ComponentImplementationContainerImpl::getImplementationDependency()
{
	std::set<ImplementationDependency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationDependency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationDependency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationDependsOn" among "ImplementationDependsOn"s
//********************************************************************************
std::set<ImplementationDependsOn> ComponentImplementationContainerImpl::getImplementationDependsOn()
{
	std::set<ImplementationDependsOn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationDependsOn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationDependsOn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationRequirement" among "ImplementationRequirement"s
//********************************************************************************
std::set<ImplementationRequirement> ComponentImplementationContainerImpl::getImplementationRequirement()
{
	std::set<ImplementationRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Implements" among "Implements"s
//********************************************************************************
std::set<Implements> ComponentImplementationContainerImpl::getImplements()
{
	std::set<Implements> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Implements");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Implements elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InfoProperty" among "InfoProperty"s
//********************************************************************************
std::set<InfoProperty> ComponentImplementationContainerImpl::getInfoProperty()
{
	std::set<InfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MonolithDeployRequirement" among "MonolithDeployRequirement"s
//********************************************************************************
std::set<MonolithDeployRequirement> ComponentImplementationContainerImpl::getMonolithDeployRequirement()
{
	std::set<MonolithDeployRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MonolithDeployRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MonolithDeployRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MonolithExecParameter" among "MonolithExecParameter"s
//********************************************************************************
std::set<MonolithExecParameter> ComponentImplementationContainerImpl::getMonolithExecParameter()
{
	std::set<MonolithExecParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MonolithExecParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MonolithExecParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MonolithicImplementation" among "ComponentImplementation"s and its descendants
//********************************************************************************
std::set<MonolithicImplementation> ComponentImplementationContainerImpl::getMonolithicImplementation()
{
	std::set<MonolithicImplementation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MonolithicImplementation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MonolithicImplementation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MonolithprimaryArtifact" among "MonolithprimaryArtifact"s
//********************************************************************************
std::set<MonolithprimaryArtifact> ComponentImplementationContainerImpl::getMonolithprimaryArtifact()
{
	std::set<MonolithprimaryArtifact> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MonolithprimaryArtifact");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		MonolithprimaryArtifact elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PathReference" among "PathReference"s
//********************************************************************************
std::set<PathReference> ComponentImplementationContainerImpl::getPathReference()
{
	std::set<PathReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PathReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PathReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> ComponentImplementationContainerImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns src ComponentRefs
//********************************************************************************
std::multiset<ComponentRef> ComponentPropertyDescriptionImpl::getComponentPropertySrcs()
{
	std::multiset<ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentProperty> ComponentPropertyDescriptionImpl::getInComponentPropertyLinks()
{
	std::set<ComponentProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "DataType" among "DataType"s
//********************************************************************************
std::set<DataType> ComponentPropertyDescriptionImpl::getDataType()
{
	std::set<DataType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DataType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DataType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string DefinitionsImpl::gettargetNamespace() 
{
	return FCOImpl::getAttribute("targetNamespace")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void DefinitionsImpl::settargetNamespace( const std::string& val)
{
	FCOImpl::getAttribute("targetNamespace")->setStringValue( val);
}


//********************************************************************************
// getter for role "Attribute" among "Attribute"s
//********************************************************************************
std::set<Attribute> DefinitionsImpl::getAttribute()
{
	std::set<Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Binding" among "Binding"s
//********************************************************************************
std::set<Binding> DefinitionsImpl::getBinding()
{
	std::set<Binding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Binding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Binding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BindingPortType" among "BindingPortType"s
//********************************************************************************
std::set<BindingPortType> DefinitionsImpl::getBindingPortType()
{
	std::set<BindingPortType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BindingPortType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BindingPortType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> DefinitionsImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Import" among "Import"s
//********************************************************************************
std::set<Import> DefinitionsImpl::getImport()
{
	std::set<Import> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Import");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Import elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Messages" among "Messages"s
//********************************************************************************
std::set<Messages> DefinitionsImpl::getMessages()
{
	std::set<Messages> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Messages");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Messages elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PortType" among "PortType"s
//********************************************************************************
std::set<PortType> DefinitionsImpl::getPortType()
{
	std::set<PortType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PortType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PortType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Service" among "Service"s
//********************************************************************************
std::set<Service> DefinitionsImpl::getService()
{
	std::set<Service> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Service");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Service elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Types" among "Types"s
//********************************************************************************
std::set<Types> DefinitionsImpl::getTypes()
{
	std::set<Types> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Types");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Types elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string DeploymentPlanImpl::getUUID() 
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
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
void DeploymentPlanImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void DeploymentPlanImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// getter for role "CollocationGroup" among "CollocationGroup"s
//********************************************************************************
std::set<CollocationGroup> DeploymentPlanImpl::getCollocationGroup()
{
	std::set<CollocationGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CollocationGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CollocationGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentAssemblyReference" among "ComponentAssemblyReference"s
//********************************************************************************
std::set<ComponentAssemblyReference> DeploymentPlanImpl::getComponentAssemblyReference()
{
	std::set<ComponentAssemblyReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentAssemblyReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentAssemblyReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> DeploymentPlanImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InstanceMapping" among "InstanceMapping"s
//********************************************************************************
std::set<InstanceMapping> DeploymentPlanImpl::getInstanceMapping()
{
	std::set<InstanceMapping> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InstanceMapping");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InstanceMapping elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "NodeReference" among "NodeReference"s
//********************************************************************************
std::set<NodeReference> DeploymentPlanImpl::getNodeReference()
{
	std::set<NodeReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("NodeReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		NodeReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SharedComponentReference" among "SharedComponentReference"s
//********************************************************************************
std::set<SharedComponentReference> DeploymentPlanImpl::getSharedComponentReference()
{
	std::set<SharedComponentReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SharedComponentReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SharedComponentReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string DocumentationImpl::getDocText() 
{
	return FCOImpl::getAttribute("DocText")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
bool DocumentationImpl::isMixed() 
{
	return FCOImpl::getAttribute("Mixed")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void DocumentationImpl::setDocText( const std::string& val)
{
	FCOImpl::getAttribute("DocText")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void DocumentationImpl::setMixed( bool val)
{
	FCOImpl::getAttribute("Mixed")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "Element" among "Element"s
//********************************************************************************
std::set<Element> DocumentationImpl::getElement()
{
	std::set<Element> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Element");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Element elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
// getter for role "Bridge" among "Elements"s and its descendants
//********************************************************************************
std::set<Bridge> DomainImpl::getBridge()
{
	std::set<Bridge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Bridge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Bridge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Bridge2Interconnect" among "Bridge2Interconnect"s
//********************************************************************************
std::set<Bridge2Interconnect> DomainImpl::getBridge2Interconnect()
{
	std::set<Bridge2Interconnect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Bridge2Interconnect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Bridge2Interconnect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Elements"s and its descendants
//********************************************************************************
std::set<Elements> DomainImpl::getElements()
{
	std::set<Elements> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Bridge");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Interconnect");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Node");
	roles_vec[3] = ModelImpl::getChildFCOsAs("SharedResource");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Elements elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Interconnect" among "Elements"s and its descendants
//********************************************************************************
std::set<Interconnect> DomainImpl::getInterconnect()
{
	std::set<Interconnect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Interconnect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Interconnect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Interconnect2Bridge" among "Interconnect2Bridge"s
//********************************************************************************
std::set<Interconnect2Bridge> DomainImpl::getInterconnect2Bridge()
{
	std::set<Interconnect2Bridge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Interconnect2Bridge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Interconnect2Bridge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Interconnect2Node" among "Interconnect2Node"s
//********************************************************************************
std::set<Interconnect2Node> DomainImpl::getInterconnect2Node()
{
	std::set<Interconnect2Node> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Interconnect2Node");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Interconnect2Node elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Node" among "Elements"s and its descendants
//********************************************************************************
std::set<Node> DomainImpl::getNode()
{
	std::set<Node> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Node");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Node elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Node2Interconnect" among "Node2Interconnect"s
//********************************************************************************
std::set<Node2Interconnect> DomainImpl::getNode2Interconnect()
{
	std::set<Node2Interconnect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Node2Interconnect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Node2Interconnect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> DomainImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SharedResource" among "Elements"s and its descendants
//********************************************************************************
std::set<SharedResource> DomainImpl::getSharedResource()
{
	std::set<SharedResource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SharedResource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SharedResource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Shares" among "Shares"s
//********************************************************************************
std::set<Shares> DomainImpl::getShares()
{
	std::set<Shares> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Shares");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Shares elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> EventChannelConfigurationImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "InEventPort" among "Port"s and its descendants
//********************************************************************************
std::set<InEventPort> EventChannelConfigurationImpl::getInEventPort()
{
	std::set<InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutEventPort" among "Port"s and its descendants
//********************************************************************************
std::set<OutEventPort> EventChannelConfigurationImpl::getOutEventPort()
{
	std::set<OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Port"s and its descendants
//********************************************************************************
std::set<Port> EventChannelConfigurationImpl::getPort()
{
	std::set<Port> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("InEventPort");
	roles_vec[1] = ModelImpl::getChildFCOsAs("OutEventPort");
	roles_vec[2] = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	roles_vec[3] = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Port elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "ProvidedRequestPort" among "Port"s and its descendants
//********************************************************************************
std::set<ProvidedRequestPort> EventChannelConfigurationImpl::getProvidedRequestPort()
{
	std::set<ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Proxy"s and its descendants
//********************************************************************************
std::set<Proxy> EventChannelConfigurationImpl::getProxy()
{
	std::set<Proxy> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("RTEC_Proxy_Consumer");
	roles_vec[1] = ModelImpl::getChildFCOsAs("RTEC_Proxy_Supplier");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Proxy elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "RTEC_Connection" among "RTEC_Connection"s
//********************************************************************************
std::set<RTEC_Connection> EventChannelConfigurationImpl::getRTEC_Connection()
{
	std::set<RTEC_Connection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RTEC_Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RTEC_Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RTEC_Proxy_Consumer" among "Proxy"s and its descendants
//********************************************************************************
std::set<RTEC_Proxy_Consumer> EventChannelConfigurationImpl::getRTEC_Proxy_Consumer()
{
	std::set<RTEC_Proxy_Consumer> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RTEC_Proxy_Consumer");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RTEC_Proxy_Consumer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RTEC_Proxy_Supplier" among "Proxy"s and its descendants
//********************************************************************************
std::set<RTEC_Proxy_Supplier> EventChannelConfigurationImpl::getRTEC_Proxy_Supplier()
{
	std::set<RTEC_Proxy_Supplier> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RTEC_Proxy_Supplier");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RTEC_Proxy_Supplier elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RTEC_Resource_Factory" among "RTEC_Resource_Factory"s
//********************************************************************************
std::set<RTEC_Resource_Factory> EventChannelConfigurationImpl::getRTEC_Resource_Factory()
{
	std::set<RTEC_Resource_Factory> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RTEC_Resource_Factory");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RTEC_Resource_Factory elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RequiredRequestPort" among "Port"s and its descendants
//********************************************************************************
std::set<RequiredRequestPort> EventChannelConfigurationImpl::getRequiredRequestPort()
{
	std::set<RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Use_RTEC_Filter" among "Use_RTEC_Filter"s
//********************************************************************************
std::set<Use_RTEC_Filter> EventChannelConfigurationImpl::getUse_RTEC_Filter()
{
	std::set<Use_RTEC_Filter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Use_RTEC_Filter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Use_RTEC_Filter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Use_RT_Info" among "Use_RT_Info"s
//********************************************************************************
std::set<Use_RT_Info> EventChannelConfigurationImpl::getUse_RT_Info()
{
	std::set<Use_RT_Info> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Use_RT_Info");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Use_RT_Info elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "DeploymentPlanRef" among "DeploymentPlanRef"s
//********************************************************************************
std::set<DeploymentPlanRef> FTRequirementsImpl::getDeploymentPlanRef()
{
	std::set<DeploymentPlanRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DeploymentPlanRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DeploymentPlanRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FOU_Requirement" among "FOU_Requirement"s
//********************************************************************************
std::set<FOU_Requirement> FTRequirementsImpl::getFOU_Requirement()
{
	std::set<FOU_Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FOU_Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FOU_Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FailOverUnit" among "FTComposite"s
//********************************************************************************
std::set<FailOverUnit> FTRequirementsImpl::getFailOverUnit()
{
	std::set<FailOverUnit> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FailOverUnit");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FailOverUnit elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ReqConnection" among "ReqConnection"s
//********************************************************************************
std::set<ReqConnection> FTRequirementsImpl::getReqConnection()
{
	std::set<ReqConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ReqConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ReqConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SRGContainerRef" among "SRGContainerRef"s
//********************************************************************************
std::set<SRGContainerRef> FTRequirementsImpl::getSRGContainerRef()
{
	std::set<SRGContainerRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SRGContainerRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SRGContainerRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst MessageRefs
//********************************************************************************
std::multiset<MessageRef> FaultImpl::getFaultMessageDsts()
{
	std::multiset<MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("FaultMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<FaultMessage> FaultImpl::getOutFaultMessageLinks()
{
	std::set<FaultMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		FaultMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> FaultImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string ImportImpl::getlocation() 
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string ImportImpl::getnamespace() 
{
	return FCOImpl::getAttribute("namespace")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void ImportImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void ImportImpl::setnamespace( const std::string& val)
{
	FCOImpl::getAttribute("namespace")->setStringValue( val);
}


//********************************************************************************
// getter for role "Definitions" among "Definitions"s
//********************************************************************************
std::set<Definitions> ImportImpl::getDefinitions()
{
	std::set<Definitions> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Definitions");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Definitions elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> ImportImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst MessageRefs
//********************************************************************************
std::multiset<MessageRef> InputImpl::getInputMessageDsts()
{
	std::multiset<MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("InputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<InputMessage> InputImpl::getOutInputMessageLinks()
{
	std::set<InputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		InputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> InputImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Project" among "Project"s
//********************************************************************************
std::set<Project> MPCImpl::getProject()
{
	std::set<Project> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Project");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Project elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Workspaces" among "Workspaces"s
//********************************************************************************
std::set<Workspaces> MPCImpl::getWorkspaces()
{
	std::set<Workspaces> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Workspaces");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Workspaces elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Part" among "Part"s
//********************************************************************************
std::set<Part> MessageImpl::getPart()
{
	std::set<Part> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Part");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Part elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Message" among "Message"s
//********************************************************************************
std::set<Message> MessagesImpl::getMessage()
{
	std::set<Message> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Message");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Message elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<OutputMessage> OutputImpl::getOutOutputMessageLinks()
{
	std::set<OutputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		OutputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst MessageRefs
//********************************************************************************
std::multiset<MessageRef> OutputImpl::getOutputMessageDsts()
{
	std::multiset<MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("OutputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> OutputImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentPackage" among "ComponentPackage"s
//********************************************************************************
std::set<ComponentPackage> PackageConfigurationContainerImpl::getComponentPackage()
{
	std::set<ComponentPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentPackageReference" among "ComponentPackageReference"s
//********************************************************************************
std::set<ComponentPackageReference> PackageConfigurationContainerImpl::getComponentPackageReference()
{
	std::set<ComponentPackageReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentPackageReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentPackageReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "FOU_Requirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<FOU_Requirement> PackageConfigurationContainerImpl::getFOU_Requirement()
{
	std::set<FOU_Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("FOU_Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		FOU_Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfBasePackage" among "PackageConfBasePackage"s
//********************************************************************************
std::set<PackageConfBasePackage> PackageConfigurationContainerImpl::getPackageConfBasePackage()
{
	std::set<PackageConfBasePackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfBasePackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfBasePackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfConfigProperty" among "PackageConfConfigProperty"s
//********************************************************************************
std::set<PackageConfConfigProperty> PackageConfigurationContainerImpl::getPackageConfConfigProperty()
{
	std::set<PackageConfConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfReference" among "PackageConfReference"s
//********************************************************************************
std::set<PackageConfReference> PackageConfigurationContainerImpl::getPackageConfReference()
{
	std::set<PackageConfReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfSelectRequirement" among "PackageConfSelectRequirement"s
//********************************************************************************
std::set<PackageConfSelectRequirement> PackageConfigurationContainerImpl::getPackageConfSelectRequirement()
{
	std::set<PackageConfSelectRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfSelectRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfSelectRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfSpecializedConfig" among "PackageConfSpecializedConfig"s
//********************************************************************************
std::set<PackageConfSpecializedConfig> PackageConfigurationContainerImpl::getPackageConfSpecializedConfig()
{
	std::set<PackageConfSpecializedConfig> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfSpecializedConfig");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfSpecializedConfig elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfiguration" among "PackageConfiguration"s
//********************************************************************************
std::set<PackageConfiguration> PackageConfigurationContainerImpl::getPackageConfiguration()
{
	std::set<PackageConfiguration> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfiguration");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfiguration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> PackageConfigurationContainerImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RepGRequirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<RepGRequirement> PackageConfigurationContainerImpl::getRepGRequirement()
{
	std::set<RepGRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RepGRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RepGRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Requirement" among "Requirement"s and its descendants
//********************************************************************************
std::set<Requirement> PackageConfigurationContainerImpl::getRequirement()
{
	std::set<Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Requirement"s and its descendants
//********************************************************************************
std::set<Requirement> PackageConfigurationContainerImpl::getRequirement(int dummy)
{
	std::set<Requirement> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("FOU_Requirement");
	roles_vec[1] = ModelImpl::getChildFCOsAs("RepGRequirement");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Requirement");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "ComponentImplementationReference" among "ComponentImplementationReference"s
//********************************************************************************
std::set<ComponentImplementationReference> PackageContainerImpl::getComponentImplementationReference()
{
	std::set<ComponentImplementationReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentImplementationReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentImplementationReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentPackage" among "ComponentPackage"s
//********************************************************************************
std::set<ComponentPackage> PackageContainerImpl::getComponentPackage()
{
	std::set<ComponentPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> PackageContainerImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Implementation" among "Implementation"s
//********************************************************************************
std::set<Implementation> PackageContainerImpl::getImplementation()
{
	std::set<Implementation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Implementation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Implementation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfigProperty" among "PackageConfigProperty"s
//********************************************************************************
std::set<PackageConfigProperty> PackageContainerImpl::getPackageConfigProperty()
{
	std::set<PackageConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageInfoProperty" among "PackageInfoProperty"s
//********************************************************************************
std::set<PackageInfoProperty> PackageContainerImpl::getPackageInfoProperty()
{
	std::set<PackageInfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageInfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageInfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageInterface" among "PackageInterface"s
//********************************************************************************
std::set<PackageInterface> PackageContainerImpl::getPackageInterface()
{
	std::set<PackageInterface> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageInterface");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageInterface elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> PackageContainerImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PathProperty> PathImpl::getOutPathPropertyLinks()
{
	std::set<PathProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PathProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> PathImpl::getPathPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PathProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "ComponentRef" among "ComponentRef"s
//********************************************************************************
std::set<ComponentRef> PathImpl::getComponentRef()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ConnectedComponent" among "GraphVertex"s and its descendants
//********************************************************************************
std::set<ConnectedComponent> PathImpl::getConnectedComponent()
{
	std::set<ConnectedComponent> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ConnectedComponent");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ConnectedComponent elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "DisplayNode" among "GraphVertex"s and its descendants
//********************************************************************************
std::set<DisplayNode> PathImpl::getDisplayNode()
{
	std::set<DisplayNode> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DisplayNode");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DisplayNode elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "DstEdge" among "DstEdge"s
//********************************************************************************
std::set<DstEdge> PathImpl::getDstEdge()
{
	std::set<DstEdge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DstEdge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DstEdge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Edge" among "Edge"s
//********************************************************************************
std::set<Edge> PathImpl::getEdge()
{
	std::set<Edge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Edge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Edge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "EdgeProperty" among "EdgeProperty"s
//********************************************************************************
std::set<EdgeProperty> PathImpl::getEdgeProperty()
{
	std::set<EdgeProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EdgeProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		EdgeProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "GraphVertex"s and its descendants
//********************************************************************************
std::set<GraphVertex> PathImpl::getGraphVertex()
{
	std::set<GraphVertex> res;
	const int len = 6;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("DisplayNode");
	roles_vec[1] = ModelImpl::getChildFCOsAs("ConnectedComponent");
	roles_vec[2] = ModelImpl::getChildFCOsAs("InEventPort");
	roles_vec[3] = ModelImpl::getChildFCOsAs("OutEventPort");
	roles_vec[4] = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	roles_vec[5] = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			GraphVertex elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "InEventPort" among "GraphVertex"s and its descendants
//********************************************************************************
std::set<InEventPort> PathImpl::getInEventPort()
{
	std::set<InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutEventPort" among "GraphVertex"s and its descendants
//********************************************************************************
std::set<OutEventPort> PathImpl::getOutEventPort()
{
	std::set<OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> PathImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ProvidedRequestPort" among "GraphVertex"s and its descendants
//********************************************************************************
std::set<ProvidedRequestPort> PathImpl::getProvidedRequestPort()
{
	std::set<ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RequiredRequestPort" among "GraphVertex"s and its descendants
//********************************************************************************
std::set<RequiredRequestPort> PathImpl::getRequiredRequestPort()
{
	std::set<RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SrcEdge" among "SrcEdge"s
//********************************************************************************
std::set<SrcEdge> PathImpl::getSrcEdge()
{
	std::set<SrcEdge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SrcEdge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SrcEdge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Path" among "Path"s
//********************************************************************************
std::set<Path> PathsImpl::getPath()
{
	std::set<Path> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Path");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Path elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PathProperty" among "PathProperty"s
//********************************************************************************
std::set<PathProperty> PathsImpl::getPathProperty()
{
	std::set<PathProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PathProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PathProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Property" among "Property"s
//********************************************************************************
std::set<Property> PathsImpl::getProperty()
{
	std::set<Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BandedConnectionRef" among "BandedConnectionRef"s
//********************************************************************************
std::set<BandedConnectionRef> PolicySetImpl::getBandedConnectionRef()
{
	std::set<BandedConnectionRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BandedConnectionRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BandedConnectionRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PriorityModelPolicy" among "PriorityModelPolicy"s
//********************************************************************************
std::set<PriorityModelPolicy> PolicySetImpl::getPriorityModelPolicy()
{
	std::set<PriorityModelPolicy> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PriorityModelPolicy");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PriorityModelPolicy elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ThreadPoolRef" among "ThreadPoolRef"s
//********************************************************************************
std::set<ThreadPoolRef> PolicySetImpl::getThreadPoolRef()
{
	std::set<ThreadPoolRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ThreadPoolRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ThreadPoolRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PortBinding> PortImpl::getOutPortBindingLinks()
{
	std::set<PortBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PortBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst BindingRefs
//********************************************************************************
std::multiset<BindingRef> PortImpl::getPortBindingDsts()
{
	std::multiset<BindingRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PortBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			BindingRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> PortImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SOAPAddress" among "ExtensiblePort"s
//********************************************************************************
std::set<SOAPAddress> PortImpl::getSOAPAddress()
{
	std::set<SOAPAddress> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SOAPAddress");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SOAPAddress elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns src Bindings
//********************************************************************************
std::multiset<Binding> PortTypeImpl::getBindingPortTypeSrcs()
{
	std::multiset<Binding> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BindingPortType");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Binding dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BindingPortType> PortTypeImpl::getInBindingPortTypeLinks()
{
	std::set<BindingPortType> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BindingPortType c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> PortTypeImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "NotificationOperation" among "Operation"s and its descendants
//********************************************************************************
std::set<NotificationOperation> PortTypeImpl::getNotificationOperation()
{
	std::set<NotificationOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("NotificationOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		NotificationOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OneWayOperation" among "Operation"s and its descendants
//********************************************************************************
std::set<OneWayOperation> PortTypeImpl::getOneWayOperation()
{
	std::set<OneWayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OneWayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OneWayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Operation"s and its descendants
//********************************************************************************
std::set<Operation> PortTypeImpl::getOperation()
{
	std::set<Operation> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("NotificationOperation");
	roles_vec[1] = ModelImpl::getChildFCOsAs("OneWayOperation");
	roles_vec[2] = ModelImpl::getChildFCOsAs("RequestResponseOperation");
	roles_vec[3] = ModelImpl::getChildFCOsAs("SolicitResponseOperation");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Operation elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "RequestResponseOperation" among "Operation"s and its descendants
//********************************************************************************
std::set<RequestResponseOperation> PortTypeImpl::getRequestResponseOperation()
{
	std::set<RequestResponseOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RequestResponseOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RequestResponseOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SolicitResponseOperation" among "Operation"s and its descendants
//********************************************************************************
std::set<SolicitResponseOperation> PortTypeImpl::getSolicitResponseOperation()
{
	std::set<SolicitResponseOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SolicitResponseOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SolicitResponseOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "ComponentLib"s and its descendants
//********************************************************************************
std::set<ComponentLib> ProjectImpl::getComponentLib()
{
	std::set<ComponentLib> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("ExecutorProject");
	roles_vec[1] = ModelImpl::getChildFCOsAs("ServantProject");
	roles_vec[2] = ModelImpl::getChildFCOsAs("StubProject");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			ComponentLib elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "ExecutorProject" among "ComponentLib"s and its descendants
//********************************************************************************
std::set<ExecutorProject> ProjectImpl::getExecutorProject()
{
	std::set<ExecutorProject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ExecutorProject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ExecutorProject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ExtResourceConn" among "ExtResourceConn"s
//********************************************************************************
std::set<ExtResourceConn> ProjectImpl::getExtResourceConn()
{
	std::set<ExtResourceConn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ExtResourceConn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ExtResourceConn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ExternalResources" among "ExternalResources"s
//********************************************************************************
std::set<ExternalResources> ProjectImpl::getExternalResources()
{
	std::set<ExternalResources> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ExternalResources");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ExternalResources elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ImplementationArtifact" among "ImplementationArtifact"s
//********************************************************************************
std::set<ImplementationArtifact> ProjectImpl::getImplementationArtifact()
{
	std::set<ImplementationArtifact> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ImplementationArtifact");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ImplementationArtifact elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ServantProject" among "ComponentLib"s and its descendants
//********************************************************************************
std::set<ServantProject> ProjectImpl::getServantProject()
{
	std::set<ServantProject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ServantProject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ServantProject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "StubProject" among "ComponentLib"s and its descendants
//********************************************************************************
std::set<StubProject> ProjectImpl::getStubProject()
{
	std::set<StubProject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("StubProject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StubProject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns src ImplementationArtifacts
//********************************************************************************
std::multiset<ImplementationArtifact> PropertyImpl::getArtifactExecParameterSrcs()
{
	std::multiset<ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ImplementationArtifacts
//********************************************************************************
std::multiset<ImplementationArtifact> PropertyImpl::getArtifactInfoPropertySrcs()
{
	std::multiset<ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Components
//********************************************************************************
std::multiset<Component> PropertyImpl::getAssemblyConfigPropertySrcs()
{
	std::multiset<Component> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("AssemblyConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Component dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PropertyImpl::getAttributeMappingValueSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeMappingValue");
}


//********************************************************************************
// returns src ReadonlyAttributes and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PropertyImpl::getAttributeValueSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeValue");
}


//********************************************************************************
// returns src ComponentRefs
//********************************************************************************
std::multiset<ComponentRef> PropertyImpl::getComponentConfigPropertySrcs()
{
	std::multiset<ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ComponentRefs
//********************************************************************************
std::multiset<ComponentRef> PropertyImpl::getComponentInfoPropertySrcs()
{
	std::multiset<ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ComponentImplementations
//********************************************************************************
std::multiset<ComponentImplementation> PropertyImpl::getConfigPropertySrcs()
{
	std::multiset<ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Edges
//********************************************************************************
std::multiset<Edge> PropertyImpl::getEdgePropertyDsts()
{
	std::multiset<Edge> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("EdgeProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Edge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactExecParameter> PropertyImpl::getInArtifactExecParameterLinks()
{
	std::set<ArtifactExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactInfoProperty> PropertyImpl::getInArtifactInfoPropertyLinks()
{
	std::set<ArtifactInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AssemblyConfigProperty> PropertyImpl::getInAssemblyConfigPropertyLinks()
{
	std::set<AssemblyConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AssemblyConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeMappingValue> PropertyImpl::getInAttributeMappingValueLinks()
{
	std::set<AttributeMappingValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeMappingValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeValue> PropertyImpl::getInAttributeValueLinks()
{
	std::set<AttributeValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentConfigProperty> PropertyImpl::getInComponentConfigPropertyLinks()
{
	std::set<ComponentConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentInfoProperty> PropertyImpl::getInComponentInfoPropertyLinks()
{
	std::set<ComponentInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ConfigProperty> PropertyImpl::getInConfigPropertyLinks()
{
	std::set<ConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<InfoProperty> PropertyImpl::getInInfoPropertyLinks()
{
	std::set<InfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		InfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MonolithExecParameter> PropertyImpl::getInMonolithExecParameterLinks()
{
	std::set<MonolithExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MonolithExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfConfigProperty> PropertyImpl::getInPackageConfConfigPropertyLinks()
{
	std::set<PackageConfConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfigProperty> PropertyImpl::getInPackageConfigPropertyLinks()
{
	std::set<PackageConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageInfoProperty> PropertyImpl::getInPackageInfoPropertyLinks()
{
	std::set<PackageInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PathProperty> PropertyImpl::getInPathPropertyLinks()
{
	std::set<PathProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PathProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src ComponentImplementations
//********************************************************************************
std::multiset<ComponentImplementation> PropertyImpl::getInfoPropertySrcs()
{
	std::multiset<ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("InfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src MonolithicImplementations
//********************************************************************************
std::multiset<MonolithicImplementation> PropertyImpl::getMonolithExecParameterSrcs()
{
	std::multiset<MonolithicImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MonolithExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			MonolithicImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<EdgeProperty> PropertyImpl::getOutEdgePropertyLinks()
{
	std::set<EdgeProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EdgeProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PackageConfigurations
//********************************************************************************
std::multiset<PackageConfiguration> PropertyImpl::getPackageConfConfigPropertySrcs()
{
	std::multiset<PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ComponentPackages
//********************************************************************************
std::multiset<ComponentPackage> PropertyImpl::getPackageConfigPropertySrcs()
{
	std::multiset<ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ComponentPackages
//********************************************************************************
std::multiset<ComponentPackage> PropertyImpl::getPackageInfoPropertySrcs()
{
	std::multiset<ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Paths
//********************************************************************************
std::multiset<Path> PropertyImpl::getPathPropertySrcs()
{
	std::multiset<Path> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PathProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Path dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// getter for role "DataType" among "DataType"s
//********************************************************************************
std::set<DataType> PropertyImpl::getDataType()
{
	std::set<DataType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DataType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DataType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CPU" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<CPU> QoSCategoryImpl::getCPU()
{
	std::set<CPU> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CPU");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CPU elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Concurrency" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Concurrency> QoSCategoryImpl::getConcurrency()
{
	std::set<Concurrency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Concurrency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Concurrency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Connection" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Connection> QoSCategoryImpl::getConnection()
{
	std::set<Connection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Process" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Process> QoSCategoryImpl::getProcess()
{
	std::set<Process> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Process");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Process elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSCharacteristic" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<QoSCharacteristic> QoSCategoryImpl::getQoSCharacteristic()
{
	std::set<QoSCharacteristic> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSCharacteristic");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSCharacteristic elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<QoSCharacteristic> QoSCategoryImpl::getQoSCharacteristic(int dummy)
{
	std::set<QoSCharacteristic> res;
	const int len = 5;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("CPU");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Concurrency");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Connection");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Process");
	roles_vec[4] = ModelImpl::getChildFCOsAs("QoSCharacteristic");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			QoSCharacteristic elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
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
// getter for role "CPU" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<CPU> QoSContextImpl::getCPU()
{
	std::set<CPU> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CPU");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CPU elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Concurrency" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Concurrency> QoSContextImpl::getConcurrency()
{
	std::set<Concurrency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Concurrency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Concurrency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Connection" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Connection> QoSContextImpl::getConnection()
{
	std::set<Connection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Process" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Process> QoSContextImpl::getProcess()
{
	std::set<Process> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Process");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Process elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSCharacteristic" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<QoSCharacteristic> QoSContextImpl::getQoSCharacteristic()
{
	std::set<QoSCharacteristic> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSCharacteristic");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSCharacteristic elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<QoSCharacteristic> QoSContextImpl::getQoSCharacteristic(int dummy)
{
	std::set<QoSCharacteristic> res;
	const int len = 5;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("CPU");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Concurrency");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Connection");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Process");
	roles_vec[4] = ModelImpl::getChildFCOsAs("QoSCharacteristic");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			QoSCharacteristic elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "QoSConstraint"s and its descendants
//********************************************************************************
std::set<QoSConstraint> QoSContextImpl::getQoSConstraint()
{
	std::set<QoSConstraint> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("QoSContract");
	roles_vec[1] = ModelImpl::getChildFCOsAs("QoSOffered");
	roles_vec[2] = ModelImpl::getChildFCOsAs("QoSRequired");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			QoSConstraint elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "QoSContext" among "QoSContext"s
//********************************************************************************
std::set<QoSContext> QoSContextImpl::getQoSContext()
{
	std::set<QoSContext> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSContext");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSContext elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSContract" among "QoSConstraint"s and its descendants
//********************************************************************************
std::set<QoSContract> QoSContextImpl::getQoSContract()
{
	std::set<QoSContract> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSContract");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSContract elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSOffered" among "QoSConstraint"s and its descendants
//********************************************************************************
std::set<QoSOffered> QoSContextImpl::getQoSOffered()
{
	std::set<QoSOffered> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSOffered");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSOffered elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSRequired" among "QoSConstraint"s and its descendants
//********************************************************************************
std::set<QoSRequired> QoSContextImpl::getQoSRequired()
{
	std::set<QoSRequired> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSRequired");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSRequired elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<QoSDecoration> QoSValueImpl::getOutQoSDecorationLinks()
{
	std::set<QoSDecoration> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		QoSDecoration c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Components
//********************************************************************************
std::multiset<Component> QoSValueImpl::getQoSDecorationDsts()
{
	std::multiset<Component> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("QoSDecoration");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Component dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "CPU" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<CPU> QoSValueImpl::getCPU()
{
	std::set<CPU> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CPU");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CPU elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Concurrency" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Concurrency> QoSValueImpl::getConcurrency()
{
	std::set<Concurrency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Concurrency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Concurrency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Connection" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Connection> QoSValueImpl::getConnection()
{
	std::set<Connection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Process" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<Process> QoSValueImpl::getProcess()
{
	std::set<Process> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Process");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Process elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSCharacteristic" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<QoSCharacteristic> QoSValueImpl::getQoSCharacteristic()
{
	std::set<QoSCharacteristic> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSCharacteristic");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSCharacteristic elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "QoSCharacteristic"s and its descendants
//********************************************************************************
std::set<QoSCharacteristic> QoSValueImpl::getQoSCharacteristic(int dummy)
{
	std::set<QoSCharacteristic> res;
	const int len = 5;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("CPU");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Concurrency");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Connection");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Process");
	roles_vec[4] = ModelImpl::getChildFCOsAs("QoSCharacteristic");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			QoSCharacteristic elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "QoSDimensionQualifier" among "QoSDimensionQualifier"s
//********************************************************************************
std::set<QoSDimensionQualifier> QoSValueImpl::getQoSDimensionQualifier()
{
	std::set<QoSDimensionQualifier> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSDimensionQualifier");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSDimensionQualifier elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "QoSDimensionSlot" among "QoSDimensionSlot"s
//********************************************************************************
std::set<QoSDimensionSlot> QoSValueImpl::getQoSDimensionSlot()
{
	std::set<QoSDimensionSlot> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("QoSDimensionSlot");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		QoSDimensionSlot elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "RTModel" among "RTModel"s
//********************************************************************************
std::set<RTModel> RTConfigurationImpl::getRTModel()
{
	std::set<RTModel> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("RTModel");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		RTModel elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "EnvironmentConf" among "EnvironmentConf"s
//********************************************************************************
std::set<EnvironmentConf> RTModelImpl::getEnvironmentConf()
{
	std::set<EnvironmentConf> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EnvironmentConf");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		EnvironmentConf elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PolicySet" among "PolicySet"s
//********************************************************************************
std::set<PolicySet> RTModelImpl::getPolicySet()
{
	std::set<PolicySet> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PolicySet");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PolicySet elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PolicySetRef" among "PolicySetRef"s
//********************************************************************************
std::set<PolicySetRef> RTModelImpl::getPolicySetRef()
{
	std::set<PolicySetRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PolicySetRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PolicySetRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ResourceContainer" among "ResourceContainer"s
//********************************************************************************
std::set<ResourceContainer> RTModelImpl::getResourceContainer()
{
	std::set<ResourceContainer> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ResourceContainer");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ResourceContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BandedConnection" among "resource"s and its descendants
//********************************************************************************
std::set<BandedConnection> ResourceContainerImpl::getBandedConnection()
{
	std::set<BandedConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BandedConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BandedConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SimpleThreadPool" among "resource"s and its descendants
//********************************************************************************
std::set<SimpleThreadPool> ResourceContainerImpl::getSimpleThreadPool()
{
	std::set<SimpleThreadPool> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SimpleThreadPool");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SimpleThreadPool elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "ThreadPoolWithLanes" among "resource"s and its descendants
//********************************************************************************
std::set<ThreadPoolWithLanes> ResourceContainerImpl::getThreadPoolWithLanes()
{
	std::set<ThreadPoolWithLanes> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ThreadPoolWithLanes");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ThreadPoolWithLanes elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "resource"s and its descendants
//********************************************************************************
std::set<resource> ResourceContainerImpl::getresource()
{
	std::set<resource> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("BandedConnection");
	roles_vec[1] = ModelImpl::getChildFCOsAs("SimpleThreadPool");
	roles_vec[2] = ModelImpl::getChildFCOsAs("ThreadPoolWithLanes");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			resource elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "NodeGroup" among "SharedRiskComposite"s and its descendants
//********************************************************************************
std::set<NodeGroup> SRGContainerImpl::getNodeGroup()
{
	std::set<NodeGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("NodeGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		NodeGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "SharedRiskComposite"s and its descendants
//********************************************************************************
std::set<SharedRiskComposite> SRGContainerImpl::getSharedRiskComposite()
{
	std::set<SharedRiskComposite> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("NodeGroup");
	roles_vec[1] = ModelImpl::getChildFCOsAs("SharedRiskGroup");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			SharedRiskComposite elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "SharedRiskGroup" among "SharedRiskComposite"s and its descendants
//********************************************************************************
std::set<SharedRiskGroup> SRGContainerImpl::getSharedRiskGroup()
{
	std::set<SharedRiskGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SharedRiskGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SharedRiskGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
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
bool SatisfierPropertyImpl::isdynamic() 
{
	return FCOImpl::getAttribute("dynamic")->getBooleanValue();
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
void SatisfierPropertyImpl::setdynamic( bool val)
{
	FCOImpl::getAttribute("dynamic")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "DataType" among "DataType"s
//********************************************************************************
std::set<DataType> SatisfierPropertyImpl::getDataType()
{
	std::set<DataType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DataType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		DataType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string SchemaImpl::gettargetNamespace() 
{
	return FCOImpl::getAttribute("targetNamespace")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void SchemaImpl::settargetNamespace( const std::string& val)
{
	FCOImpl::getAttribute("targetNamespace")->setStringValue( val);
}


//********************************************************************************
// getter for role "Attribute" among "Attribute"s
//********************************************************************************
std::set<Attribute> SchemaImpl::getAttribute()
{
	std::set<Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Element" among "Element"s
//********************************************************************************
std::set<Element> SchemaImpl::getElement()
{
	std::set<Element> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Element");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Element elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SchemaImport" among "SchemaReference"s and its descendants
//********************************************************************************
std::set<SchemaImport> SchemaImpl::getSchemaImport()
{
	std::set<SchemaImport> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SchemaImport");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SchemaImport elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SchemaReference" among "SchemaReference"s and its descendants
//********************************************************************************
std::set<SchemaReference> SchemaImpl::getSchemaReference()
{
	std::set<SchemaReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SchemaReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SchemaReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "SchemaReference"s and its descendants
//********************************************************************************
std::set<SchemaReference> SchemaImpl::getSchemaReference(int dummy)
{
	std::set<SchemaReference> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("SchemaImport");
	roles_vec[1] = ModelImpl::getChildFCOsAs("SchemaReference");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			SchemaReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "AtomicType" among "AtomicType"s
//********************************************************************************
std::set<AtomicType> SchemaBuiltinsImpl::getAtomicType()
{
	std::set<AtomicType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("AtomicType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		AtomicType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BindingRef" among "BindingRef"s
//********************************************************************************
std::set<BindingRef> ServiceImpl::getBindingRef()
{
	std::set<BindingRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BindingRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		BindingRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Port" among "Port"s
//********************************************************************************
std::set<Port> ServiceImpl::getPort()
{
	std::set<Port> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Port");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Port elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PortBinding" among "PortBinding"s
//********************************************************************************
std::set<PortBinding> ServiceImpl::getPortBinding()
{
	std::set<PortBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PortBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PortBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CCMAssembly" among "CCMAssembly"s
//********************************************************************************
std::set<CCMAssembly> SystemImpl::getCCMAssembly()
{
	std::set<CCMAssembly> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CCMAssembly");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CCMAssembly elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WebService" among "WebService"s
//********************************************************************************
std::set<WebService> SystemImpl::getWebService()
{
	std::set<WebService> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WebService");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WebService elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PackageConfigurationReference" among "PackageConfigurationReference"s
//********************************************************************************
std::set<PackageConfigurationReference> TopLevelPackageContainerImpl::getPackageConfigurationReference()
{
	std::set<PackageConfigurationReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PackageConfigurationReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PackageConfigurationReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "TopLevelPackage" among "TopLevelPackage"s
//********************************************************************************
std::set<TopLevelPackage> TopLevelPackageContainerImpl::getTopLevelPackage()
{
	std::set<TopLevelPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("TopLevelPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		TopLevelPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "package" among "package"s
//********************************************************************************
std::set<package> TopLevelPackageContainerImpl::getpackage()
{
	std::set<package> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("package");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		package elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Documentation" among "Documentation"s
//********************************************************************************
std::set<Documentation> TypesImpl::getDocumentation()
{
	std::set<Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Schema" among "Schema"s
//********************************************************************************
std::set<Schema> TypesImpl::getSchema()
{
	std::set<Schema> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Schema");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Schema elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
bool WorkerImpl::isAbstract() 
{
	return FCOImpl::getAttribute("Abstract")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void WorkerImpl::setAbstract( bool val)
{
	FCOImpl::getAttribute("Abstract")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "Action" among "Action"s and its descendants
//********************************************************************************
std::set<Action> WorkerImpl::getAction()
{
	std::set<Action> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Action");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Action elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "" among "Action"s and its descendants
//********************************************************************************
std::set<Action> WorkerImpl::getAction(int dummy)
{
	std::set<Action> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("CompositeAction");
	roles_vec[1] = ModelImpl::getChildFCOsAs("OutputAction");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Action");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			Action elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "CompositeAction" among "Action"s and its descendants
//********************************************************************************
std::set<CompositeAction> WorkerImpl::getCompositeAction()
{
	std::set<CompositeAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CompositeAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		CompositeAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "OutputAction" among "Action"s and its descendants
//********************************************************************************
std::set<OutputAction> WorkerImpl::getOutputAction()
{
	std::set<OutputAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("OutputAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		OutputAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string WorkerLibraryImpl::getLocation() 
{
	return FCOImpl::getAttribute("Location")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void WorkerLibraryImpl::setLocation( const std::string& val)
{
	FCOImpl::getAttribute("Location")->setStringValue( val);
}


//********************************************************************************
// getter for role "WorkerFile" among "WorkerFile"s
//********************************************************************************
std::set<WorkerFile> WorkerLibraryImpl::getWorkerFile()
{
	std::set<WorkerFile> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WorkerFile");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WorkerFile elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns dst MetricsBases
//********************************************************************************
std::multiset<MetricsBase> BenchmarkTypeImpl::getBenchmarkCharacteristicsDsts()
{
	std::multiset<MetricsBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BenchmarkCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			MetricsBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BenchmarkCharacteristics> BenchmarkTypeImpl::getOutBenchmarkCharacteristicsLinks()
{
	std::set<BenchmarkCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BenchmarkCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// returns dst SOAPBodys
//********************************************************************************
std::multiset<SOAPBody> IORefImpl::getBodyBindingDsts()
{
	std::multiset<SOAPBody> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BodyBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			SOAPBody dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst SOAPHeaderss
//********************************************************************************
std::multiset<SOAPHeaders> IORefImpl::getHeaderBindingDsts()
{
	std::multiset<SOAPHeaders> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("HeaderBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			SOAPHeaders dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BodyBinding> IORefImpl::getOutBodyBindingLinks()
{
	std::set<BodyBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BodyBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<HeaderBinding> IORefImpl::getOutHeaderBindingLinks()
{
	std::set<HeaderBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		HeaderBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
Input InputRefImpl::getInput()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Input(r);
}


//********************************************************************************
// 
//********************************************************************************
Output OutputRefImpl::getOutput()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Output(r);
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
std::string AttributeImpl::getValue() 
{
	return FCOImpl::getAttribute("Value")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void AttributeImpl::setValue( const std::string& val)
{
	FCOImpl::getAttribute("Value")->setStringValue( val);
}


//********************************************************************************
// returns dst ComponentImplementationReferences
//********************************************************************************
std::multiset<ComponentImplementationReference> ComponentPackageImpl::getImplementationDsts()
{
	std::multiset<ComponentImplementationReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Implementation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ComponentImplementationReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfBasePackage> ComponentPackageImpl::getInPackageConfBasePackageLinks()
{
	std::set<PackageConfBasePackage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfBasePackage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Implementation> ComponentPackageImpl::getOutImplementationLinks()
{
	std::set<Implementation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Implementation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfigProperty> ComponentPackageImpl::getOutPackageConfigPropertyLinks()
{
	std::set<PackageConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageInfoProperty> ComponentPackageImpl::getOutPackageInfoPropertyLinks()
{
	std::set<PackageInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageInterface> ComponentPackageImpl::getOutPackageInterfaceLinks()
{
	std::set<PackageInterface> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageInterface c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PackageConfigurations
//********************************************************************************
std::multiset<PackageConfiguration> ComponentPackageImpl::getPackageConfBasePackageSrcs()
{
	std::multiset<PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfBasePackage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ComponentPackageImpl::getPackageConfigPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ComponentPackageImpl::getPackageInfoPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ComponentRefs
//********************************************************************************
std::multiset<ComponentRef> ComponentPackageImpl::getPackageInterfaceDsts()
{
	std::multiset<ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageInterface");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
std::set<Include_RT_Info> RTEC_Filter_GroupImpl::getInInclude_RT_InfoLinks()
{
	std::set<Include_RT_Info> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Include_RT_Info c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst RTEC_Filter_Groups
//********************************************************************************
std::multiset<RTEC_Filter_Group> RTEC_Filter_GroupImpl::getInclude_RTEC_Filter_GroupDsts()
{
	std::multiset<RTEC_Filter_Group> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Include_RTEC_Filter_Group");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			RTEC_Filter_Group dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src and dst RTEC_Filter_Groups
//********************************************************************************
std::multiset<RTEC_Filter_Group> RTEC_Filter_GroupImpl::getInclude_RTEC_Filter_GroupEnds()
{
	std::multiset<RTEC_Filter_Group> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Include_RTEC_Filter_Group");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			RTEC_Filter_Group dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Include_RTEC_Filter_Group");
		for ( std::multiset<BON::ConnectionEnd>::iterator cot = out_ends.begin() ; cot != out_ends.end() ; ++cot )
		{
			RTEC_Filter_Group dst( *cot );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}

//********************************************************************************
// 
//********************************************************************************
std::set<Include_RTEC_Filter_Group> RTEC_Filter_GroupImpl::getInclude_RTEC_Filter_GroupLinks()
{
	std::set<Include_RTEC_Filter_Group> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Include_RTEC_Filter_Group c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src RTEC_Filter_Groups
//********************************************************************************
std::multiset<RTEC_Filter_Group> RTEC_Filter_GroupImpl::getInclude_RTEC_Filter_GroupSrcs()
{
	std::multiset<RTEC_Filter_Group> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Include_RTEC_Filter_Group");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			RTEC_Filter_Group dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src RT_Info_Params
//********************************************************************************
std::multiset<RT_Info_Param> RTEC_Filter_GroupImpl::getInclude_RT_InfoSrcs()
{
	std::multiset<RT_Info_Param> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Include_RT_Info");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			RT_Info_Param dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Use_RTEC_Filter> RTEC_Filter_GroupImpl::getOutUse_RTEC_FilterLinks()
{
	std::set<Use_RTEC_Filter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Use_RTEC_Filter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> RTEC_Filter_GroupImpl::getUse_RTEC_FilterDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("Use_RTEC_Filter");
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
// returns src GraphVertexs and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> EdgeImpl::getDstEdgeSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("DstEdge");
}


//********************************************************************************
// returns src Propertys
//********************************************************************************
std::multiset<Property> EdgeImpl::getEdgePropertySrcs()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("EdgeProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<DstEdge> EdgeImpl::getInDstEdgeLinks()
{
	std::set<DstEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		DstEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<EdgeProperty> EdgeImpl::getInEdgePropertyLinks()
{
	std::set<EdgeProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		EdgeProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<SrcEdge> EdgeImpl::getOutSrcEdgeLinks()
{
	std::set<SrcEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		SrcEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst GraphVertexs and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> EdgeImpl::getSrcEdgeDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("SrcEdge");
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
// returns src Components
//********************************************************************************
std::multiset<Component> ExternalReferenceEndPointImpl::getExternalDelegateSrcs()
{
	std::multiset<Component> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ExternalDelegate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Component dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ExternalDelegate> ExternalReferenceEndPointImpl::getInExternalDelegateLinks()
{
	std::set<ExternalDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ExternalDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// returns dst ImplementationArtifacts
//********************************************************************************
std::multiset<ImplementationArtifact> ImplementationArtifactImpl::getArtifactDependencyDsts()
{
	std::multiset<ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactDependency");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactDependency> ImplementationArtifactImpl::getArtifactDependencyLinks()
{
	std::set<ArtifactDependency> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactDependency c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src ImplementationArtifacts
//********************************************************************************
std::multiset<ImplementationArtifact> ImplementationArtifactImpl::getArtifactDependencySrcs()
{
	std::multiset<ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactDependency");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ImplementationArtifactReferences
//********************************************************************************
std::multiset<ImplementationArtifactReference> ImplementationArtifactImpl::getArtifactDependsOnDsts()
{
	std::multiset<ImplementationArtifactReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ImplementationArtifactReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Requirements
//********************************************************************************
std::multiset<Requirement> ImplementationArtifactImpl::getArtifactDeployRequirementDsts()
{
	std::multiset<Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ImplementationArtifactImpl::getArtifactExecParameterDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> ImplementationArtifactImpl::getArtifactInfoPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactDependency> ImplementationArtifactImpl::getInArtifactDependencyLinks()
{
	std::set<ArtifactDependency> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactDependency c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactDependency> ImplementationArtifactImpl::getOutArtifactDependencyLinks()
{
	std::set<ArtifactDependency> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactDependency c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactDependsOn> ImplementationArtifactImpl::getOutArtifactDependsOnLinks()
{
	std::set<ArtifactDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactDeployRequirement> ImplementationArtifactImpl::getOutArtifactDeployRequirementLinks()
{
	std::set<ArtifactDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactExecParameter> ImplementationArtifactImpl::getOutArtifactExecParameterLinks()
{
	std::set<ArtifactExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactInfoProperty> ImplementationArtifactImpl::getOutArtifactInfoPropertyLinks()
{
	std::set<ArtifactInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// returns src ComponentImplementations
//********************************************************************************
std::multiset<ComponentImplementation> ImplementationDependencyImpl::getImplementationDependsOnSrcs()
{
	std::multiset<ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ImplementationDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ImplementationDependsOn> ImplementationDependencyImpl::getInImplementationDependsOnLinks()
{
	std::set<ImplementationDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ImplementationDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
std::set<LabelConnection> LabelImpl::getInLabelConnectionLinks()
{
	std::set<LabelConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		LabelConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Members
//********************************************************************************
std::multiset<Member> LabelImpl::getLabelConnectionSrcs()
{
	std::multiset<Member> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("LabelConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Member dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<RTEC_Connection> RT_Info_ParamImpl::getInRTEC_ConnectionLinks()
{
	std::set<RTEC_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		RTEC_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst RTEC_Filter_Groups
//********************************************************************************
std::multiset<RTEC_Filter_Group> RT_Info_ParamImpl::getInclude_RT_InfoDsts()
{
	std::multiset<RTEC_Filter_Group> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Include_RT_Info");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			RTEC_Filter_Group dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Include_RT_Info> RT_Info_ParamImpl::getOutInclude_RT_InfoLinks()
{
	std::set<Include_RT_Info> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Include_RT_Info c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Use_RT_Info> RT_Info_ParamImpl::getOutUse_RT_InfoLinks()
{
	std::set<Use_RT_Info> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Use_RT_Info c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> RT_Info_ParamImpl::getRTEC_ConnectionSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("RTEC_Connection");
}


//********************************************************************************
// returns dst RTEC_Resource_Factory_References
//********************************************************************************
std::multiset<RTEC_Resource_Factory_Reference> RT_Info_ParamImpl::getUse_RT_InfoDsts()
{
	std::multiset<RTEC_Resource_Factory_Reference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Use_RT_Info");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			RTEC_Resource_Factory_Reference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
std::set<PackageConfBasePackage> PackageConfigurationImpl::getOutPackageConfBasePackageLinks()
{
	std::set<PackageConfBasePackage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfBasePackage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfConfigProperty> PackageConfigurationImpl::getOutPackageConfConfigPropertyLinks()
{
	std::set<PackageConfConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfReference> PackageConfigurationImpl::getOutPackageConfReferenceLinks()
{
	std::set<PackageConfReference> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfReference c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfSelectRequirement> PackageConfigurationImpl::getOutPackageConfSelectRequirementLinks()
{
	std::set<PackageConfSelectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfSelectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<PackageConfSpecializedConfig> PackageConfigurationImpl::getOutPackageConfSpecializedConfigLinks()
{
	std::set<PackageConfSpecializedConfig> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfSpecializedConfig c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst ComponentPackages
//********************************************************************************
std::multiset<ComponentPackage> PackageConfigurationImpl::getPackageConfBasePackageDsts()
{
	std::multiset<ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfBasePackage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> PackageConfigurationImpl::getPackageConfConfigPropertyDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst ComponentPackageReferences
//********************************************************************************
std::multiset<ComponentPackageReference> PackageConfigurationImpl::getPackageConfReferenceDsts()
{
	std::multiset<ComponentPackageReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfReference");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ComponentPackageReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Requirements
//********************************************************************************
std::multiset<Requirement> PackageConfigurationImpl::getPackageConfSelectRequirementDsts()
{
	std::multiset<Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfSelectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PackageConfigurationReferences
//********************************************************************************
std::multiset<PackageConfigurationReference> PackageConfigurationImpl::getPackageConfSpecializedConfigDsts()
{
	std::multiset<PackageConfigurationReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfSpecializedConfig");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PackageConfigurationReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
std::set<MakeMemberPrivate> PrivateFlagImpl::getInMakeMemberPrivateLinks()
{
	std::set<MakeMemberPrivate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MakeMemberPrivate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Members
//********************************************************************************
std::multiset<Member> PrivateFlagImpl::getMakeMemberPrivateSrcs()
{
	std::multiset<Member> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MakeMemberPrivate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Member dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Requirements
//********************************************************************************
std::multiset<Requirement> PublishConnectorImpl::getAssemblyDeployRequirementDsts()
{
	std::multiset<Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AssemblyDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<publish> PublishConnectorImpl::getInpublishLinks()
{
	std::set<publish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		publish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AssemblyDeployRequirement> PublishConnectorImpl::getOutAssemblyDeployRequirementLinks()
{
	std::set<AssemblyDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AssemblyDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<deliverTo> PublishConnectorImpl::getOutdeliverToLinks()
{
	std::set<deliverTo> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		deliverTo c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PublishConnectorImpl::getdeliverToDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("deliverTo");
}


//********************************************************************************
// returns src OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PublishConnectorImpl::getpublishSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("publish");
}


//********************************************************************************
// 
//********************************************************************************
std::set<QoSDimensionQualifier> QoSDimensionImpl::getInQoSDimensionQualifierLinks()
{
	std::set<QoSDimensionQualifier> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		QoSDimensionQualifier c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src QoSDimensionSlots
//********************************************************************************
std::multiset<QoSDimensionSlot> QoSDimensionImpl::getQoSDimensionQualifierSrcs()
{
	std::multiset<QoSDimensionSlot> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("QoSDimensionQualifier");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			QoSDimensionSlot dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
std::set<QoSDimensionQualifier> QoSDimensionSlotImpl::getOutQoSDimensionQualifierLinks()
{
	std::set<QoSDimensionQualifier> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		QoSDimensionQualifier c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst QoSDimensions
//********************************************************************************
std::multiset<QoSDimension> QoSDimensionSlotImpl::getQoSDimensionQualifierDsts()
{
	std::multiset<QoSDimension> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("QoSDimensionQualifier");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			QoSDimension dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// returns src ActionBases
//********************************************************************************
std::multiset<ActionBase> StateImpl::getEffectSrcs()
{
	std::multiset<ActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Effect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst InputActionBases
//********************************************************************************
std::multiset<InputActionBase> StateImpl::getFinishDsts()
{
	std::multiset<InputActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Finish");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			InputActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Effect> StateImpl::getInEffectLinks()
{
	std::set<Effect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Effect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Finish> StateImpl::getOutFinishLinks()
{
	std::set<Finish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Finish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Transition> StateImpl::getOutTransitionLinks()
{
	std::set<Transition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Transition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst ActionBases
//********************************************************************************
std::multiset<ActionBase> StateImpl::getTransitionDsts()
{
	std::multiset<ActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Transition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<WorkLoadOperationConnection> TaskImpl::getInWorkLoadOperationConnectionLinks()
{
	std::set<WorkLoadOperationConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WorkLoadOperationConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src OperationRefs
//********************************************************************************
std::multiset<OperationRef> TaskImpl::getWorkLoadOperationConnectionSrcs()
{
	std::multiset<OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("WorkLoadOperationConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// 
//********************************************************************************
std::set<TimerConnection> TimeProbeImpl::getInTimerConnectionLinks()
{
	std::set<TimerConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		TimerConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<TimerEventSinkConn> TimeProbeImpl::getInTimerEventSinkConnLinks()
{
	std::set<TimerEventSinkConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		TimerEventSinkConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src OperationRefs
//********************************************************************************
std::multiset<OperationRef> TimeProbeImpl::getTimerConnectionSrcs()
{
	std::multiset<OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("TimerConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src EventRefs
//********************************************************************************
std::multiset<EventRef> TimeProbeImpl::getTimerEventSinkConnSrcs()
{
	std::multiset<EventRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("TimerEventSinkConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			EventRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<package> TopLevelPackageImpl::getOutpackageLinks()
{
	std::set<package> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		package c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PackageConfigurationReferences
//********************************************************************************
std::multiset<PackageConfigurationReference> TopLevelPackageImpl::getpackageDsts()
{
	std::multiset<PackageConfigurationReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("package");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PackageConfigurationReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// getDst() return value is a ConnectionEnd casted to PortType
//********************************************************************************
PortType BindingPortTypeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PortType sp( ce);
	if ( sp)
		return sp;

	PortType empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Binding
//********************************************************************************
Binding BindingPortTypeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Binding sp( ce);
	if ( sp)
		return sp;

	Binding empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to OperationRef
//********************************************************************************
OperationRef BindsOperationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	OperationRef sp( ce);
	if ( sp)
		return sp;

	OperationRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to BindingOperation
//********************************************************************************
BindingOperation BindsOperationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	BindingOperation sp( ce);
	if ( sp)
		return sp;

	BindingOperation empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to SOAPBody
//********************************************************************************
SOAPBody BodyBindingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	SOAPBody sp( ce);
	if ( sp)
		return sp;

	SOAPBody empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to IORef
//********************************************************************************
IORef BodyBindingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	IORef sp( ce);
	if ( sp)
		return sp;

	IORef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PartRef
//********************************************************************************
PartRef BodyPartsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PartRef sp( ce);
	if ( sp)
		return sp;

	PartRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to SOAPBody
//********************************************************************************
SOAPBody BodyPartsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	SOAPBody sp( ce);
	if ( sp)
		return sp;

	SOAPBody empty;
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
// getDst() return value is a ConnectionEnd casted to PathReference
//********************************************************************************
PathReference CriticalPathImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PathReference sp( ce);
	if ( sp)
		return sp;

	PathReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ComponentAssembly
//********************************************************************************
ComponentAssembly CriticalPathImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ComponentAssembly sp( ce);
	if ( sp)
		return sp;

	ComponentAssembly empty;
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
// getDst() return value is a ConnectionEnd casted to Edge
//********************************************************************************
Edge EdgePropertyImpl::getDst()
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
Property EdgePropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// 
//********************************************************************************
std::string EffectImpl::getPostcondition() 
{
	return FCOImpl::getAttribute("Postcondition")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void EffectImpl::setPostcondition( const std::string& val)
{
	FCOImpl::getAttribute("Postcondition")->setStringValue( val);
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
// getDst() return value is a ConnectionEnd casted to MessageRef
//********************************************************************************
MessageRef FaultMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	MessageRef sp( ce);
	if ( sp)
		return sp;

	MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Fault
//********************************************************************************
Fault FaultMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Fault sp( ce);
	if ( sp)
		return sp;

	Fault empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to InputActionBase
//********************************************************************************
InputActionBase FinishImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	InputActionBase sp( ce);
	if ( sp)
		return sp;

	InputActionBase empty;
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
// getDst() return value is a ConnectionEnd casted to SOAPHeaders
//********************************************************************************
SOAPHeaders HeaderBindingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	SOAPHeaders sp( ce);
	if ( sp)
		return sp;

	SOAPHeaders empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to IORef
//********************************************************************************
IORef HeaderBindingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	IORef sp( ce);
	if ( sp)
		return sp;

	IORef empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to MessageRef
//********************************************************************************
MessageRef HeaderMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	MessageRef sp( ce);
	if ( sp)
		return sp;

	MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to SOAPHeaders
//********************************************************************************
SOAPHeaders HeaderMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	SOAPHeaders sp( ce);
	if ( sp)
		return sp;

	SOAPHeaders empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PartRef
//********************************************************************************
PartRef HeaderPartImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PartRef sp( ce);
	if ( sp)
		return sp;

	PartRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to SOAPHeaders
//********************************************************************************
SOAPHeaders HeaderPartImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	SOAPHeaders sp( ce);
	if ( sp)
		return sp;

	SOAPHeaders empty;
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
// getDst() return value is a ConnectionEnd casted to InputActionBase
//********************************************************************************
InputActionBase InputImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	InputActionBase sp( ce);
	if ( sp)
		return sp;

	InputActionBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to InEventPort
//********************************************************************************
InEventPort InputImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	InEventPort sp( ce);
	if ( sp)
		return sp;

	InEventPort empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to MessageRef
//********************************************************************************
MessageRef InputMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	MessageRef sp( ce);
	if ( sp)
		return sp;

	MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Input
//********************************************************************************
Input InputMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Input sp( ce);
	if ( sp)
		return sp;

	Input empty;
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
// getDst() return value is a ConnectionEnd casted to RepGRequirement
//********************************************************************************
RepGRequirement Monitorable2RepGImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	RepGRequirement sp( ce);
	if ( sp)
		return sp;

	RepGRequirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to FTMonitorable
//********************************************************************************
FTMonitorable Monitorable2RepGImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	FTMonitorable sp( ce);
	if ( sp)
		return sp;

	FTMonitorable empty;
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
// getDst() return value is a ConnectionEnd casted to InputActionBase
//********************************************************************************
InputActionBase MultiInputImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	InputActionBase sp( ce);
	if ( sp)
		return sp;

	InputActionBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to MultiInputBase
//********************************************************************************
MultiInputBase MultiInputImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	MultiInputBase sp( ce);
	if ( sp)
		return sp;

	MultiInputBase empty;
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
// getDst() return value is a ConnectionEnd casted to MessageRef
//********************************************************************************
MessageRef OutputMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	MessageRef sp( ce);
	if ( sp)
		return sp;

	MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Output
//********************************************************************************
Output OutputMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Output sp( ce);
	if ( sp)
		return sp;

	Output empty;
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
// getDst() return value is a ConnectionEnd casted to Property
//********************************************************************************
Property PathPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Property sp( ce);
	if ( sp)
		return sp;

	Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Path
//********************************************************************************
Path PathPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Path sp( ce);
	if ( sp)
		return sp;

	Path empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to BindingRef
//********************************************************************************
BindingRef PortBindingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	BindingRef sp( ce);
	if ( sp)
		return sp;

	BindingRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Port
//********************************************************************************
Port PortBindingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Port sp( ce);
	if ( sp)
		return sp;

	Port empty;
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
// getDst() return value is a ConnectionEnd casted to FOU_Requirement
//********************************************************************************
FOU_Requirement ReqConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	FOU_Requirement sp( ce);
	if ( sp)
		return sp;

	FOU_Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to FTComposite
//********************************************************************************
FTComposite ReqConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	FTComposite sp( ce);
	if ( sp)
		return sp;

	FTComposite empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to SOAPFault
//********************************************************************************
SOAPFault SOAPFaultExtensionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	SOAPFault sp( ce);
	if ( sp)
		return sp;

	SOAPFault empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to FaultRef
//********************************************************************************
FaultRef SOAPFaultExtensionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	FaultRef sp( ce);
	if ( sp)
		return sp;

	FaultRef empty;
	return empty;
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
// returns dst NodeReferences
//********************************************************************************
std::multiset<NodeReference> CollocationGroupImpl::getInstanceMappingDsts()
{
	std::multiset<NodeReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("InstanceMapping");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			NodeReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<InstanceMapping> CollocationGroupImpl::getOutInstanceMappingLinks()
{
	std::set<InstanceMapping> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		InstanceMapping c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// aggregated getter for setmembers
//********************************************************************************
std::set<BON::Reference> CollocationGroupImpl::getAllMembers()
{
	std::set<BON::Reference> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		BON::Reference r( *elem);
		if ( r)
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for ComponentAssemblyReference setmembers
//********************************************************************************
std::set<ComponentAssemblyReference> CollocationGroupImpl::getComponentAssemblyReferences()
{
	std::set<ComponentAssemblyReference> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		ComponentAssemblyReference r( *elem);
		if ( r && r->getObjectMeta().name() == "ComponentAssemblyReference")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for ComponentRef setmembers
//********************************************************************************
std::set<ComponentRef> CollocationGroupImpl::getComponentRefs()
{
	std::set<ComponentRef> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		ComponentRef r( *elem);
		if ( r && r->getObjectMeta().name() == "ComponentRef")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for SharedComponentReference setmembers
//********************************************************************************
std::set<SharedComponentReference> CollocationGroupImpl::getSharedComponentReferences()
{
	std::set<SharedComponentReference> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		SharedComponentReference r( *elem);
		if ( r && r->getObjectMeta().name() == "SharedComponentReference")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<WorkloadCharacteristics> TaskSetImpl::getInWorkloadCharacteristicsLinks()
{
	std::set<WorkloadCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WorkloadCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src MetricsBases
//********************************************************************************
std::multiset<MetricsBase> TaskSetImpl::getWorkloadCharacteristicsSrcs()
{
	std::multiset<MetricsBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("WorkloadCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			MetricsBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// aggregated getter for setmembers
//********************************************************************************
std::set<Task> TaskSetImpl::getTasks( int dummy)
{
	std::set<Task> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		Task r( *elem);
		if ( r)
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for Task setmembers
//********************************************************************************
std::set<Task> TaskSetImpl::getTasks()
{
	std::set<Task> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		Task r( *elem);
		if ( r && r->getObjectMeta().name() == "Task")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// aggregated getter for setmembers
//********************************************************************************
std::set<Project> WorkspacesImpl::getProjects( int dummy)
{
	std::set<Project> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		Project r( *elem);
		if ( r)
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for Project setmembers
//********************************************************************************
std::set<Project> WorkspacesImpl::getProjects()
{
	std::set<Project> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		Project r( *elem);
		if ( r && r->getObjectMeta().name() == "Project")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// returns dst ReadonlyAttributes and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> AttributeMappingImpl::getAttributeDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("AttributeDelegate");
}


//********************************************************************************
// returns dst AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> AttributeMappingImpl::getAttributeMappingDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("AttributeMappingDelegate");
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeMappingDelegate> AttributeMappingImpl::getAttributeMappingDelegateLinks()
{
	std::set<AttributeMappingDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeMappingDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> AttributeMappingImpl::getAttributeMappingDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeMappingDelegate");
}


//********************************************************************************
// returns dst Propertys
//********************************************************************************
std::multiset<Property> AttributeMappingImpl::getAttributeMappingValueDsts()
{
	std::multiset<Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AttributeMappingValue");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeMappingDelegate> AttributeMappingImpl::getInAttributeMappingDelegateLinks()
{
	std::set<AttributeMappingDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeMappingDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeDelegate> AttributeMappingImpl::getOutAttributeDelegateLinks()
{
	std::set<AttributeDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeMappingDelegate> AttributeMappingImpl::getOutAttributeMappingDelegateLinks()
{
	std::set<AttributeMappingDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeMappingDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<AttributeMappingValue> AttributeMappingImpl::getOutAttributeMappingValueLinks()
{
	std::set<AttributeMappingValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		AttributeMappingValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
std::set<PortBinding> BindingRefImpl::getInPortBindingLinks()
{
	std::set<PortBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PortBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Ports
//********************************************************************************
std::multiset<Port> BindingRefImpl::getPortBindingSrcs()
{
	std::multiset<Port> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PortBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Port dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
Binding BindingRefImpl::getBinding()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Binding(r);
}


//********************************************************************************
// 
//********************************************************************************
System CCMAssemblyImpl::getSystem()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return System(r);
}


//********************************************************************************
// returns src OperationRefs
//********************************************************************************
std::multiset<OperationRef> CompRefImpl::getComponentOperationSrcs()
{
	std::multiset<OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentOperation> CompRefImpl::getInComponentOperationLinks()
{
	std::set<ComponentOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// returns src ComponentPackages
//********************************************************************************
std::multiset<ComponentPackage> ComponentImplementationReferenceImpl::getImplementationSrcs()
{
	std::multiset<ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Implementation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<Implementation> ComponentImplementationReferenceImpl::getInImplementationLinks()
{
	std::set<Implementation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Implementation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
std::set<PackageConfReference> ComponentPackageReferenceImpl::getInPackageConfReferenceLinks()
{
	std::set<PackageConfReference> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfReference c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PackageConfigurations
//********************************************************************************
std::multiset<PackageConfiguration> ComponentPackageReferenceImpl::getPackageConfReferenceSrcs()
{
	std::multiset<PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfReference");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
DeploymentPlan DeploymentPlanRefImpl::getDeploymentPlan()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return DeploymentPlan(r);
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
std::set<TimerEventSinkConn> EventRefImpl::getOutTimerEventSinkConnLinks()
{
	std::set<TimerEventSinkConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		TimerEventSinkConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst TimeProbes
//********************************************************************************
std::multiset<TimeProbe> EventRefImpl::getTimerEventSinkConnDsts()
{
	std::multiset<TimeProbe> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("TimerEventSinkConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			TimeProbe dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// returns src ComponentLibs
//********************************************************************************
std::multiset<ComponentLib> ExternalResourcesImpl::getExtResourceConnSrcs()
{
	std::multiset<ComponentLib> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ExtResourceConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentLib dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ExtResourceConn> ExternalResourcesImpl::getInExtResourceConnLinks()
{
	std::set<ExtResourceConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ExtResourceConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
std::set<SOAPFaultExtension> FaultRefImpl::getOutSOAPFaultExtensionLinks()
{
	std::set<SOAPFaultExtension> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		SOAPFaultExtension c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst SOAPFaults
//********************************************************************************
std::multiset<SOAPFault> FaultRefImpl::getSOAPFaultExtensionDsts()
{
	std::multiset<SOAPFault> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("SOAPFaultExtension");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			SOAPFault dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
Fault FaultRefImpl::getFault()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Fault(r);
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
// returns src ImplementationArtifacts
//********************************************************************************
std::multiset<ImplementationArtifact> ImplementationArtifactReferenceImpl::getArtifactDependsOnSrcs()
{
	std::multiset<ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ArtifactDependsOn> ImplementationArtifactReferenceImpl::getInArtifactDependsOnLinks()
{
	std::set<ArtifactDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ArtifactDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MonolithprimaryArtifact> ImplementationArtifactReferenceImpl::getInMonolithprimaryArtifactLinks()
{
	std::set<MonolithprimaryArtifact> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MonolithprimaryArtifact c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src MonolithicImplementations
//********************************************************************************
std::multiset<MonolithicImplementation> ImplementationArtifactReferenceImpl::getMonolithprimaryArtifactSrcs()
{
	std::multiset<MonolithicImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MonolithprimaryArtifact");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			MonolithicImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// returns dst Labels
//********************************************************************************
std::multiset<Label> MemberImpl::getLabelConnectionDsts()
{
	std::multiset<Label> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("LabelConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Label dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PrivateFlags
//********************************************************************************
std::multiset<PrivateFlag> MemberImpl::getMakeMemberPrivateDsts()
{
	std::multiset<PrivateFlag> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MakeMemberPrivate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PrivateFlag dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<LabelConnection> MemberImpl::getOutLabelConnectionLinks()
{
	std::set<LabelConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		LabelConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MakeMemberPrivate> MemberImpl::getOutMakeMemberPrivateLinks()
{
	std::set<MakeMemberPrivate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MakeMemberPrivate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
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
// returns src Faults
//********************************************************************************
std::multiset<Fault> MessageRefImpl::getFaultMessageSrcs()
{
	std::multiset<Fault> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("FaultMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Fault dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src SOAPHeaderss
//********************************************************************************
std::multiset<SOAPHeaders> MessageRefImpl::getHeaderMessageSrcs()
{
	std::multiset<SOAPHeaders> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("HeaderMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			SOAPHeaders dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<FaultMessage> MessageRefImpl::getInFaultMessageLinks()
{
	std::set<FaultMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		FaultMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<HeaderMessage> MessageRefImpl::getInHeaderMessageLinks()
{
	std::set<HeaderMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		HeaderMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<InputMessage> MessageRefImpl::getInInputMessageLinks()
{
	std::set<InputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		InputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<OutputMessage> MessageRefImpl::getInOutputMessageLinks()
{
	std::set<OutputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		OutputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Inputs
//********************************************************************************
std::multiset<Input> MessageRefImpl::getInputMessageSrcs()
{
	std::multiset<Input> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("InputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Input dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Outputs
//********************************************************************************
std::multiset<Output> MessageRefImpl::getOutputMessageSrcs()
{
	std::multiset<Output> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("OutputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Output dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
Message MessageRefImpl::getMessage()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Message(r);
}


//********************************************************************************
// 
//********************************************************************************
Node NodeRefImpl::getNode()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Node(r);
}


//********************************************************************************
// 
//********************************************************************************
std::set<InstanceMapping> NodeReferenceImpl::getInInstanceMappingLinks()
{
	std::set<InstanceMapping> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		InstanceMapping c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src CollocationGroups
//********************************************************************************
std::multiset<CollocationGroup> NodeReferenceImpl::getInstanceMappingSrcs()
{
	std::multiset<CollocationGroup> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("InstanceMapping");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			CollocationGroup dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// returns dst CompRefs
//********************************************************************************
std::multiset<CompRef> OperationRefImpl::getComponentOperationDsts()
{
	std::multiset<CompRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			CompRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst MetricsBases
//********************************************************************************
std::multiset<MetricsBase> OperationRefImpl::getMetricConnectionDsts()
{
	std::multiset<MetricsBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MetricConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			MetricsBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ComponentOperation> OperationRefImpl::getOutComponentOperationLinks()
{
	std::set<ComponentOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ComponentOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<MetricConnection> OperationRefImpl::getOutMetricConnectionLinks()
{
	std::set<MetricConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		MetricConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<TimerConnection> OperationRefImpl::getOutTimerConnectionLinks()
{
	std::set<TimerConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		TimerConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<WorkLoadOperationConnection> OperationRefImpl::getOutWorkLoadOperationConnectionLinks()
{
	std::set<WorkLoadOperationConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WorkLoadOperationConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst TimeProbes
//********************************************************************************
std::multiset<TimeProbe> OperationRefImpl::getTimerConnectionDsts()
{
	std::multiset<TimeProbe> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("TimerConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			TimeProbe dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst Tasks
//********************************************************************************
std::multiset<Task> OperationRefImpl::getWorkLoadOperationConnectionDsts()
{
	std::multiset<Task> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("WorkLoadOperationConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Task dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
// returns src BindingOperations
//********************************************************************************
std::multiset<BindingOperation> OperationRefImpl::getBindsOperationSrcs()
{
	std::multiset<BindingOperation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BindsOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			BindingOperation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BindsOperation> OperationRefImpl::getInBindsOperationLinks()
{
	std::set<BindsOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BindsOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
Operation OperationRefImpl::getOperation()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Operation(r);
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
std::set<PackageConfSpecializedConfig> PackageConfigurationReferenceImpl::getInPackageConfSpecializedConfigLinks()
{
	std::set<PackageConfSpecializedConfig> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PackageConfSpecializedConfig c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<package> PackageConfigurationReferenceImpl::getInpackageLinks()
{
	std::set<package> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		package c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PackageConfigurations
//********************************************************************************
std::multiset<PackageConfiguration> PackageConfigurationReferenceImpl::getPackageConfSpecializedConfigSrcs()
{
	std::multiset<PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfSpecializedConfig");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src TopLevelPackages
//********************************************************************************
std::multiset<TopLevelPackage> PackageConfigurationReferenceImpl::getpackageSrcs()
{
	std::multiset<TopLevelPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("package");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			TopLevelPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
Referrable PartImpl::getReferrable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Referrable(r);
}


//********************************************************************************
// returns src SOAPBodys
//********************************************************************************
std::multiset<SOAPBody> PartRefImpl::getBodyPartsSrcs()
{
	std::multiset<SOAPBody> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BodyParts");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			SOAPBody dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src SOAPHeaderss
//********************************************************************************
std::multiset<SOAPHeaders> PartRefImpl::getHeaderPartSrcs()
{
	std::multiset<SOAPHeaders> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("HeaderPart");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			SOAPHeaders dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<BodyParts> PartRefImpl::getInBodyPartsLinks()
{
	std::set<BodyParts> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		BodyParts c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<HeaderPart> PartRefImpl::getInHeaderPartLinks()
{
	std::set<HeaderPart> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		HeaderPart c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
Part PartRefImpl::getPart()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Part(r);
}


//********************************************************************************
// returns src ComponentAssemblys
//********************************************************************************
std::multiset<ComponentAssembly> PathReferenceImpl::getCriticalPathSrcs()
{
	std::multiset<ComponentAssembly> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("CriticalPath");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ComponentAssembly dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<CriticalPath> PathReferenceImpl::getInCriticalPathLinks()
{
	std::set<CriticalPath> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		CriticalPath c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
Path PathReferenceImpl::getPath()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Path(r);
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
std::set<Use_RT_Info> RTEC_Resource_Factory_ReferenceImpl::getInUse_RT_InfoLinks()
{
	std::set<Use_RT_Info> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Use_RT_Info c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src RT_Info_Params
//********************************************************************************
std::multiset<RT_Info_Param> RTEC_Resource_Factory_ReferenceImpl::getUse_RT_InfoSrcs()
{
	std::multiset<RT_Info_Param> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Use_RT_Info");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			RT_Info_Param dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
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
SRGContainer SRGContainerRefImpl::getSRGContainer()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return SRGContainer(r);
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
ComponentRef SharedComponentReferenceImpl::getComponentRef()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return ComponentRef(r);
}


//********************************************************************************
// 
//********************************************************************************
SharedResource SharedResourceRefImpl::getSharedResource()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return SharedResource(r);
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


//********************************************************************************
// 
//********************************************************************************
PredefinedType VariableImpl::getPredefinedType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PredefinedType(r);
}


//********************************************************************************
// 
//********************************************************************************
System WebServiceImpl::getSystem()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return System(r);
}


//********************************************************************************
// 
//********************************************************************************
Worker WorkerTypeImpl::getWorker()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return Worker(r);
}



}; // namespace SIML_BON

