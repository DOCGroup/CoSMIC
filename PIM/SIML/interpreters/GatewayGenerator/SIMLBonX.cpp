#include "stdafx.h"
#include "SIMLBonX.h"
#include "SIMLVisitor.h"


namespace BON
{

IMPLEMENT_BONEXTENSION( PICML::ComponentAnalyses, "PICML::ComponentAnalyses" );
IMPLEMENT_BONEXTENSION( PICML::ComponentBuild, "PICML::ComponentBuild" );
IMPLEMENT_BONEXTENSION( PICML::ComponentImplementations, "PICML::ComponentImplementations" );
IMPLEMENT_BONEXTENSION( PICML::ComponentPackages, "PICML::ComponentPackages" );
IMPLEMENT_BONEXTENSION( PICML::ComponentTypes, "PICML::ComponentTypes" );
IMPLEMENT_BONEXTENSION( PICML::DeploymentPlans, "PICML::DeploymentPlans" );
IMPLEMENT_BONEXTENSION( PICML::ImplementationArtifacts, "PICML::ImplementationArtifacts" );
IMPLEMENT_BONEXTENSION( PICML::InterfaceDefinitions, "PICML::InterfaceDefinitions" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfigurations, "PICML::PackageConfigurations" );
IMPLEMENT_BONEXTENSION( PICML::PathDiagrams, "PICML::PathDiagrams" );
IMPLEMENT_BONEXTENSION( PICML::PredefinedTypes, "PICML::PredefinedTypes" );
IMPLEMENT_BONEXTENSION( PICML::Targets, "PICML::Targets" );
IMPLEMENT_BONEXTENSION( PICML::TopLevelPackages, "PICML::TopLevelPackages" );
IMPLEMENT_BONEXTENSION( PICML::WorkerLibraries, "PICML::WorkerLibraries" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::ActionBase );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::BehaviorModel );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::Prefixable );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::SupportsInterfaces );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::CommonPortAttrs );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::ConstantType );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::GraphVertex );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::Manageable );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::MemberType );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::MultiInputBase );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::MultiOutputBase );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::Provideable );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::SingleInputBase );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::SingleOutputBase );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::Taggable );
IMPLEMENT_BONEXTENSION( PICML::Action, "PICML::Action" );
IMPLEMENT_BONEXTENSION( PICML::CompositeAction, "PICML::CompositeAction" );
IMPLEMENT_BONEXTENSION( PICML::ConnectedComponent, "PICML::ConnectedComponent" );
IMPLEMENT_BONEXTENSION( PICML::Exception, "PICML::Exception" );
IMPLEMENT_BONEXTENSION( PICML::File, "PICML::File" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::OperationBase );
IMPLEMENT_BONEXTENSION( PICML::OutputAction, "PICML::OutputAction" );
IMPLEMENT_BONEXTENSION( PICML::Package, "PICML::Package" );
IMPLEMENT_BONEXTENSION( PICML::ReadonlyAttribute, "PICML::ReadonlyAttribute" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::TopLevelBehavior );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::NamedType );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::Port );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::PredefinedType );
IMPLEMENT_BONEXTENSION( PICML::DisplayNode, "PICML::DisplayNode" );
IMPLEMENT_BONEXTENSION( PICML::Environment, "PICML::Environment" );
IMPLEMENT_BONEXTENSION( PICML::PeriodicEvent, "PICML::PeriodicEvent" );
IMPLEMENT_BONEXTENSION( PICML::ComponentRef, "PICML::ComponentRef" );
IMPLEMENT_BONEXTENSION( PICML::Constant, "PICML::Constant" );
IMPLEMENT_BONEXTENSION( PICML::Attribute, "PICML::Attribute" );
IMPLEMENT_BONEXTENSION( PICML::Component, "PICML::Component" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::HasExceptions );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::Inheritable );
IMPLEMENT_BONEXTENSION( PICML::OnewayOperation, "PICML::OnewayOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::NoInheritable );
IMPLEMENT_BONEXTENSION( PICML::Boolean, "PICML::Boolean" );
IMPLEMENT_BONEXTENSION( PICML::Byte, "PICML::Byte" );
IMPLEMENT_BONEXTENSION( PICML::GenericObject, "PICML::GenericObject" );
IMPLEMENT_BONEXTENSION( PICML::GenericValue, "PICML::GenericValue" );
IMPLEMENT_BONEXTENSION( PICML::GenericValueObject, "PICML::GenericValueObject" );
IMPLEMENT_BONEXTENSION( PICML::LongInteger, "PICML::LongInteger" );
IMPLEMENT_BONEXTENSION( PICML::RealNumber, "PICML::RealNumber" );
IMPLEMENT_BONEXTENSION( PICML::ShortInteger, "PICML::ShortInteger" );
IMPLEMENT_BONEXTENSION( PICML::String, "PICML::String" );
IMPLEMENT_BONEXTENSION( PICML::TypeEncoding, "PICML::TypeEncoding" );
IMPLEMENT_BONEXTENSION( PICML::TypeKind, "PICML::TypeKind" );
IMPLEMENT_BONEXTENSION( PICML::Boxed, "PICML::Boxed" );
IMPLEMENT_BONEXTENSION( PICML::InEventPort, "PICML::InEventPort" );
IMPLEMENT_BONEXTENSION( PICML::OutEventPort, "PICML::OutEventPort" );
IMPLEMENT_BONEXTENSION( PICML::ProvidedRequestPort, "PICML::ProvidedRequestPort" );
IMPLEMENT_BONEXTENSION( PICML::RequiredRequestPort, "PICML::RequiredRequestPort" );
IMPLEMENT_BONEXTENSION( PICML::Aggregate, "PICML::Aggregate" );
IMPLEMENT_BONEXTENSION( PICML::Enum, "PICML::Enum" );
IMPLEMENT_BONEXTENSION( PICML::FactoryOperation, "PICML::FactoryOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::HasOperations );
IMPLEMENT_BONEXTENSION( PICML::LookupOperation, "PICML::LookupOperation" );
IMPLEMENT_BONEXTENSION( PICML::SwitchedAggregate, "PICML::SwitchedAggregate" );
IMPLEMENT_BONEXTENSION( PICML::TwowayOperation, "PICML::TwowayOperation" );
IMPLEMENT_BONEXTENSION( PICML::Alias, "PICML::Alias" );
IMPLEMENT_BONEXTENSION( PICML::Collection, "PICML::Collection" );
IMPLEMENT_BONEXTENSION( PICML::ComponentFactory, "PICML::ComponentFactory" );
IMPLEMENT_BONEXTENSION( PICML::Object, "PICML::Object" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::ObjectByValue );
IMPLEMENT_BONEXTENSION( PICML::Event, "PICML::Event" );
IMPLEMENT_BONEXTENSION( PICML::ValueObject, "PICML::ValueObject" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::RequirementSatisfier );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::Elements );
IMPLEMENT_BONEXTENSION( PICML::Bridge, "PICML::Bridge" );
IMPLEMENT_BONEXTENSION( PICML::Capability, "PICML::Capability" );
IMPLEMENT_BONEXTENSION( PICML::Interconnect, "PICML::Interconnect" );
IMPLEMENT_BONEXTENSION( PICML::Node, "PICML::Node" );
IMPLEMENT_BONEXTENSION( PICML::Resource, "PICML::Resource" );
IMPLEMENT_BONEXTENSION( PICML::SharedResource, "PICML::SharedResource" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::RequirementBase );
IMPLEMENT_BONEXTENSION( PICML::ImplementationRequirement, "PICML::ImplementationRequirement" );
IMPLEMENT_BONEXTENSION( PICML::Requirement, "PICML::Requirement" );
IMPLEMENT_BONEXTENSION( PICML::ECConfiguration, "PICML::ECConfiguration" );
IMPLEMENT_BONEXTENSION( PICML::RTRequirements, "PICML::RTRequirements" );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::Operation );
IMPLEMENT_BONEXTENSION( WSML::NotificationOperation, "WSML::NotificationOperation" );
IMPLEMENT_BONEXTENSION( WSML::OneWayOperation, "WSML::OneWayOperation" );
IMPLEMENT_BONEXTENSION( WSML::RequestResponseOperation, "WSML::RequestResponseOperation" );
IMPLEMENT_BONEXTENSION( WSML::SolicitResponseOperation, "WSML::SolicitResponseOperation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::ComponentLib );
IMPLEMENT_BONEXTENSION( PICML::ExecutorProject, "PICML::ExecutorProject" );
IMPLEMENT_BONEXTENSION( PICML::ServantProject, "PICML::ServantProject" );
IMPLEMENT_BONEXTENSION( PICML::StubProject, "PICML::StubProject" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::ECRole );
IMPLEMENT_BONEXTENSION( PICML::ECConsumer, "PICML::ECConsumer" );
IMPLEMENT_BONEXTENSION( PICML::ECSupplier, "PICML::ECSupplier" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::MetricsBase );
IMPLEMENT_BONEXTENSION( PICML::Latency, "PICML::Latency" );
IMPLEMENT_BONEXTENSION( PICML::Throughput, "PICML::Throughput" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::WorkerPackageBase );
IMPLEMENT_BONEXTENSION( PICML::WorkerFile, "PICML::WorkerFile" );
IMPLEMENT_BONEXTENSION( PICML::WorkerPackage, "PICML::WorkerPackage" );
IMPLEMENT_BONEXTENSION( WSML::SchemaReference, "WSML::SchemaReference" );
IMPLEMENT_BONEXTENSION( WSML::SchemaImport, "WSML::SchemaImport" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::ComponentImplementation );
IMPLEMENT_BONEXTENSION( PICML::ComponentAssembly, "PICML::ComponentAssembly" );
IMPLEMENT_BONEXTENSION( PICML::MonolithicImplementation, "PICML::MonolithicImplementation" );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::ExtensibilityElement );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::ExtensibleBinding );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::ExtensibleMessage );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::ExtensibleOperation );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::ExtensiblePort );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::SOAPHeaders );
IMPLEMENT_BONEXTENSION( WSML::SOAPAddress, "WSML::SOAPAddress" );
IMPLEMENT_BONEXTENSION( WSML::SOAPBinding, "WSML::SOAPBinding" );
IMPLEMENT_BONEXTENSION( WSML::SOAPBody, "WSML::SOAPBody" );
IMPLEMENT_BONEXTENSION( WSML::SOAPFault, "WSML::SOAPFault" );
IMPLEMENT_BONEXTENSION( WSML::SOAPOperation, "WSML::SOAPOperation" );
IMPLEMENT_BONEXTENSION( WSML::SOAPHeader, "WSML::SOAPHeader" );
IMPLEMENT_BONEXTENSION( WSML::SOAPHeaderFault, "WSML::SOAPHeaderFault" );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::Referrable );
IMPLEMENT_BONEXTENSION( WSML::Element, "WSML::Element" );
IMPLEMENT_BONEXTENSION( WSML::AtomicType, "WSML::AtomicType" );
IMPLEMENT_BONEXTENSION( PICML::ArtifactContainer, "PICML::ArtifactContainer" );
IMPLEMENT_BONEXTENSION( PICML::BenchmarkAnalysis, "PICML::BenchmarkAnalysis" );
IMPLEMENT_BONEXTENSION( WSML::Binding, "WSML::Binding" );
IMPLEMENT_BONEXTENSION( WSML::BindingOperation, "WSML::BindingOperation" );
IMPLEMENT_BONEXTENSION( PICML::ComponentContainer, "PICML::ComponentContainer" );
IMPLEMENT_BONEXTENSION( PICML::ComponentImplementationContainer, "PICML::ComponentImplementationContainer" );
IMPLEMENT_BONEXTENSION( PICML::ComponentPropertyDescription, "PICML::ComponentPropertyDescription" );
IMPLEMENT_BONEXTENSION( WSML::Definitions, "WSML::Definitions" );
IMPLEMENT_BONEXTENSION( PICML::DeploymentPlan, "PICML::DeploymentPlan" );
IMPLEMENT_BONEXTENSION( WSML::Documentation, "WSML::Documentation" );
IMPLEMENT_BONEXTENSION( PICML::Domain, "PICML::Domain" );
IMPLEMENT_BONEXTENSION( WSML::Fault, "WSML::Fault" );
IMPLEMENT_BONEXTENSION( WSML::Import, "WSML::Import" );
IMPLEMENT_BONEXTENSION( WSML::Input, "WSML::Input" );
IMPLEMENT_BONEXTENSION( PICML::InputAction, "PICML::InputAction" );
IMPLEMENT_BONEXTENSION( PICML::MPC, "PICML::MPC" );
IMPLEMENT_BONEXTENSION( WSML::Message, "WSML::Message" );
IMPLEMENT_BONEXTENSION( WSML::Messages, "WSML::Messages" );
IMPLEMENT_BONEXTENSION( WSML::Output, "WSML::Output" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfigurationContainer, "PICML::PackageConfigurationContainer" );
IMPLEMENT_BONEXTENSION( PICML::PackageContainer, "PICML::PackageContainer" );
IMPLEMENT_BONEXTENSION( PICML::Path, "PICML::Path" );
IMPLEMENT_BONEXTENSION( PICML::Paths, "PICML::Paths" );
IMPLEMENT_BONEXTENSION( WSML::Port, "WSML::Port" );
IMPLEMENT_BONEXTENSION( WSML::PortType, "WSML::PortType" );
IMPLEMENT_BONEXTENSION( PICML::Project, "PICML::Project" );
IMPLEMENT_BONEXTENSION( PICML::Property, "PICML::Property" );
IMPLEMENT_BONEXTENSION( PICML::SatisfierProperty, "PICML::SatisfierProperty" );
IMPLEMENT_BONEXTENSION( WSML::Schema, "WSML::Schema" );
IMPLEMENT_BONEXTENSION( WSML::SchemaBuiltins, "WSML::SchemaBuiltins" );
IMPLEMENT_BONEXTENSION( WSML::Service, "WSML::Service" );
IMPLEMENT_BONEXTENSION( PICML::ServiceProvider, "PICML::ServiceProvider" );
IMPLEMENT_BONEXTENSION( SIML::System, "SIML::System" );
IMPLEMENT_BONEXTENSION( PICML::TopLevelPackageContainer, "PICML::TopLevelPackageContainer" );
IMPLEMENT_BONEXTENSION( WSML::Types, "WSML::Types" );
IMPLEMENT_BONEXTENSION( PICML::Worker, "PICML::Worker" );
IMPLEMENT_BONEXTENSION( PICML::WorkerLibrary, "PICML::WorkerLibrary" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::BenchmarkType );
IMPLEMENT_BONEXTENSION( PICML::FixedIterationBenchmarks, "PICML::FixedIterationBenchmarks" );
IMPLEMENT_BONEXTENSION( PICML::PeriodicBenchmarks, "PICML::PeriodicBenchmarks" );
IMPLEMENT_BONEXTENSION( PICML::TriggerBenchmarks, "PICML::TriggerBenchmarks" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::DataAnalysisBase );
IMPLEMENT_BONEXTENSION( PICML::Average, "PICML::Average" );
IMPLEMENT_BONEXTENSION( PICML::Jitter, "PICML::Jitter" );
IMPLEMENT_BONEXTENSION( PICML::Maximum, "PICML::Maximum" );
IMPLEMENT_BONEXTENSION( PICML::Minimum, "PICML::Minimum" );
IMPLEMENT_ABSTRACT_BONEXTENSION( WSML::IORef );
IMPLEMENT_BONEXTENSION( WSML::InputRef, "WSML::InputRef" );
IMPLEMENT_BONEXTENSION( WSML::OutputRef, "WSML::OutputRef" );
IMPLEMENT_BONEXTENSION( WSML::Attribute, "WSML::Attribute" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::StateBase );
IMPLEMENT_BONEXTENSION( PICML::BranchState, "PICML::BranchState" );
IMPLEMENT_BONEXTENSION( PICML::State, "PICML::State" );
IMPLEMENT_BONEXTENSION( PICML::ComponentPackage, "PICML::ComponentPackage" );
IMPLEMENT_BONEXTENSION( PICML::ECBehavior, "PICML::ECBehavior" );
IMPLEMENT_BONEXTENSION( PICML::ECEventFilterConfiguration, "PICML::ECEventFilterConfiguration" );
IMPLEMENT_BONEXTENSION( PICML::Edge, "PICML::Edge" );
IMPLEMENT_BONEXTENSION( PICML::EnumValue, "PICML::EnumValue" );
IMPLEMENT_BONEXTENSION( PICML::ExternalReferenceEndPoint, "PICML::ExternalReferenceEndPoint" );
IMPLEMENT_BONEXTENSION( PICML::ImplementationArtifact, "PICML::ImplementationArtifact" );
IMPLEMENT_BONEXTENSION( PICML::ImplementationDependency, "PICML::ImplementationDependency" );
IMPLEMENT_BONEXTENSION( PICML::Label, "PICML::Label" );
IMPLEMENT_BONEXTENSION( PICML::MultipleServiceRequests, "PICML::MultipleServiceRequests" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfiguration, "PICML::PackageConfiguration" );
IMPLEMENT_BONEXTENSION( PICML::PrivateFlag, "PICML::PrivateFlag" );
IMPLEMENT_BONEXTENSION( PICML::PublishConnector, "PICML::PublishConnector" );
IMPLEMENT_BONEXTENSION( PICML::ServiceConsumer, "PICML::ServiceConsumer" );
IMPLEMENT_BONEXTENSION( PICML::ServiceLevels, "PICML::ServiceLevels" );
IMPLEMENT_BONEXTENSION( PICML::Task, "PICML::Task" );
IMPLEMENT_BONEXTENSION( PICML::TimeProbe, "PICML::TimeProbe" );
IMPLEMENT_BONEXTENSION( PICML::TopLevelPackage, "PICML::TopLevelPackage" );
IMPLEMENT_BONEXTENSION( PICML::ArtifactDependency, "PICML::ArtifactDependency" );
IMPLEMENT_BONEXTENSION( PICML::ArtifactDependsOn, "PICML::ArtifactDependsOn" );
IMPLEMENT_BONEXTENSION( PICML::ArtifactDeployRequirement, "PICML::ArtifactDeployRequirement" );
IMPLEMENT_BONEXTENSION( PICML::ArtifactExecParameter, "PICML::ArtifactExecParameter" );
IMPLEMENT_BONEXTENSION( PICML::ArtifactInfoProperty, "PICML::ArtifactInfoProperty" );
IMPLEMENT_BONEXTENSION( PICML::AssemblyConfigProperty, "PICML::AssemblyConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML::AssemblyDeployRequirement, "PICML::AssemblyDeployRequirement" );
IMPLEMENT_BONEXTENSION( PICML::AssemblyselectRequirement, "PICML::AssemblyselectRequirement" );
IMPLEMENT_BONEXTENSION( PICML::AttributeDelegate, "PICML::AttributeDelegate" );
IMPLEMENT_BONEXTENSION( PICML::AttributeMappingDelegate, "PICML::AttributeMappingDelegate" );
IMPLEMENT_BONEXTENSION( PICML::AttributeMappingValue, "PICML::AttributeMappingValue" );
IMPLEMENT_BONEXTENSION( PICML::AttributeValue, "PICML::AttributeValue" );
IMPLEMENT_BONEXTENSION( PICML::BenchmarkCharacteristics, "PICML::BenchmarkCharacteristics" );
IMPLEMENT_BONEXTENSION( WSML::BindingPortType, "WSML::BindingPortType" );
IMPLEMENT_BONEXTENSION( WSML::BindsOperation, "WSML::BindsOperation" );
IMPLEMENT_BONEXTENSION( WSML::BodyBinding, "WSML::BodyBinding" );
IMPLEMENT_BONEXTENSION( WSML::BodyParts, "WSML::BodyParts" );
IMPLEMENT_BONEXTENSION( PICML::BranchTransition, "PICML::BranchTransition" );
IMPLEMENT_BONEXTENSION( PICML::Bridge2Interconnect, "PICML::Bridge2Interconnect" );
IMPLEMENT_BONEXTENSION( PICML::ComponentConfigProperty, "PICML::ComponentConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML::ComponentInfoProperty, "PICML::ComponentInfoProperty" );
IMPLEMENT_BONEXTENSION( PICML::ComponentOperation, "PICML::ComponentOperation" );
IMPLEMENT_BONEXTENSION( PICML::ComponentProperty, "PICML::ComponentProperty" );
IMPLEMENT_BONEXTENSION( PICML::ConfigProperty, "PICML::ConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML::Consumer2BehaviorConnection, "PICML::Consumer2BehaviorConnection" );
IMPLEMENT_BONEXTENSION( PICML::CriticalPath, "PICML::CriticalPath" );
IMPLEMENT_BONEXTENSION( PICML::DstEdge, "PICML::DstEdge" );
IMPLEMENT_BONEXTENSION( PICML::EdgeProperty, "PICML::EdgeProperty" );
IMPLEMENT_BONEXTENSION( PICML::Effect, "PICML::Effect" );
IMPLEMENT_BONEXTENSION( PICML::EventSinkDelegate, "PICML::EventSinkDelegate" );
IMPLEMENT_BONEXTENSION( PICML::EventSourceDelegate, "PICML::EventSourceDelegate" );
IMPLEMENT_BONEXTENSION( PICML::ExtResourceConn, "PICML::ExtResourceConn" );
IMPLEMENT_BONEXTENSION( PICML::ExternalDelegate, "PICML::ExternalDelegate" );
IMPLEMENT_BONEXTENSION( PICML::FacetDelegate, "PICML::FacetDelegate" );
IMPLEMENT_BONEXTENSION( WSML::FaultMessage, "WSML::FaultMessage" );
IMPLEMENT_BONEXTENSION( PICML::Finish, "PICML::Finish" );
IMPLEMENT_BONEXTENSION( WSML::HeaderBinding, "WSML::HeaderBinding" );
IMPLEMENT_BONEXTENSION( WSML::HeaderMessage, "WSML::HeaderMessage" );
IMPLEMENT_BONEXTENSION( WSML::HeaderPart, "WSML::HeaderPart" );
IMPLEMENT_BONEXTENSION( PICML::Implementation, "PICML::Implementation" );
IMPLEMENT_BONEXTENSION( PICML::ImplementationCapability, "PICML::ImplementationCapability" );
IMPLEMENT_BONEXTENSION( PICML::ImplementationDependsOn, "PICML::ImplementationDependsOn" );
IMPLEMENT_BONEXTENSION( PICML::Implements, "PICML::Implements" );
IMPLEMENT_BONEXTENSION( PICML::InfoProperty, "PICML::InfoProperty" );
IMPLEMENT_BONEXTENSION( PICML::Input, "PICML::Input" );
IMPLEMENT_BONEXTENSION( PICML::InputEffect, "PICML::InputEffect" );
IMPLEMENT_BONEXTENSION( WSML::InputMessage, "WSML::InputMessage" );
IMPLEMENT_BONEXTENSION( PICML::InstanceMapping, "PICML::InstanceMapping" );
IMPLEMENT_BONEXTENSION( PICML::Interconnect2Bridge, "PICML::Interconnect2Bridge" );
IMPLEMENT_BONEXTENSION( PICML::Interconnect2Node, "PICML::Interconnect2Node" );
IMPLEMENT_BONEXTENSION( PICML::LabelConnection, "PICML::LabelConnection" );
IMPLEMENT_BONEXTENSION( PICML::MakeMemberPrivate, "PICML::MakeMemberPrivate" );
IMPLEMENT_BONEXTENSION( PICML::ManagesComponent, "PICML::ManagesComponent" );
IMPLEMENT_BONEXTENSION( PICML::MetricConnection, "PICML::MetricConnection" );
IMPLEMENT_BONEXTENSION( PICML::MonolithDeployRequirement, "PICML::MonolithDeployRequirement" );
IMPLEMENT_BONEXTENSION( PICML::MonolithExecParameter, "PICML::MonolithExecParameter" );
IMPLEMENT_BONEXTENSION( PICML::MonolithprimaryArtifact, "PICML::MonolithprimaryArtifact" );
IMPLEMENT_BONEXTENSION( PICML::MultiInput, "PICML::MultiInput" );
IMPLEMENT_BONEXTENSION( PICML::Node2Interconnect, "PICML::Node2Interconnect" );
IMPLEMENT_BONEXTENSION( WSML::OutputMessage, "WSML::OutputMessage" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfBasePackage, "PICML::PackageConfBasePackage" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfConfigProperty, "PICML::PackageConfConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfReference, "PICML::PackageConfReference" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfSelectRequirement, "PICML::PackageConfSelectRequirement" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfSpecializedConfig, "PICML::PackageConfSpecializedConfig" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfigProperty, "PICML::PackageConfigProperty" );
IMPLEMENT_BONEXTENSION( PICML::PackageInfoProperty, "PICML::PackageInfoProperty" );
IMPLEMENT_BONEXTENSION( PICML::PackageInterface, "PICML::PackageInterface" );
IMPLEMENT_BONEXTENSION( PICML::PathProperty, "PICML::PathProperty" );
IMPLEMENT_BONEXTENSION( WSML::PortBinding, "WSML::PortBinding" );
IMPLEMENT_BONEXTENSION( SIML::PortProxy, "SIML::PortProxy" );
IMPLEMENT_BONEXTENSION( PICML::ReceptacleDelegate, "PICML::ReceptacleDelegate" );
IMPLEMENT_BONEXTENSION( PICML::RecursiveFilterConnection, "PICML::RecursiveFilterConnection" );
IMPLEMENT_BONEXTENSION( WSML::SOAPFaultExtension, "WSML::SOAPFaultExtension" );
IMPLEMENT_BONEXTENSION( PICML::Shares, "PICML::Shares" );
IMPLEMENT_BONEXTENSION( PICML::SrcEdge, "PICML::SrcEdge" );
IMPLEMENT_BONEXTENSION( PICML::Supplier2FilterConnection, "PICML::Supplier2FilterConnection" );
IMPLEMENT_BONEXTENSION( PICML::TimerConnection, "PICML::TimerConnection" );
IMPLEMENT_BONEXTENSION( PICML::TimerEventSinkConn, "PICML::TimerEventSinkConn" );
IMPLEMENT_BONEXTENSION( PICML::Transition, "PICML::Transition" );
IMPLEMENT_BONEXTENSION( PICML::WorkLoadOperationConnection, "PICML::WorkLoadOperationConnection" );
IMPLEMENT_BONEXTENSION( PICML::WorkloadCharacteristics, "PICML::WorkloadCharacteristics" );
IMPLEMENT_BONEXTENSION( PICML::deliverTo, "PICML::deliverTo" );
IMPLEMENT_BONEXTENSION( PICML::emit, "PICML::emit" );
IMPLEMENT_BONEXTENSION( PICML::invoke, "PICML::invoke" );
IMPLEMENT_BONEXTENSION( PICML::package, "PICML::package" );
IMPLEMENT_BONEXTENSION( PICML::publish, "PICML::publish" );
IMPLEMENT_BONEXTENSION( PICML::CollocationGroup, "PICML::CollocationGroup" );
IMPLEMENT_BONEXTENSION( PICML::TaskSet, "PICML::TaskSet" );
IMPLEMENT_BONEXTENSION( PICML::Workspaces, "PICML::Workspaces" );
IMPLEMENT_BONEXTENSION( PICML::AttributeMapping, "PICML::AttributeMapping" );
IMPLEMENT_BONEXTENSION( PICML::AttributeMember, "PICML::AttributeMember" );
IMPLEMENT_BONEXTENSION( WSML::BindingRef, "WSML::BindingRef" );
IMPLEMENT_BONEXTENSION( PICML::CompRef, "PICML::CompRef" );
IMPLEMENT_BONEXTENSION( PICML::ComponentAssemblyReference, "PICML::ComponentAssemblyReference" );
IMPLEMENT_BONEXTENSION( PICML::ComponentImplementationReference, "PICML::ComponentImplementationReference" );
IMPLEMENT_BONEXTENSION( PICML::ComponentPackageReference, "PICML::ComponentPackageReference" );
IMPLEMENT_BONEXTENSION( PICML::DataType, "PICML::DataType" );
IMPLEMENT_BONEXTENSION( PICML::Discriminator, "PICML::Discriminator" );
IMPLEMENT_BONEXTENSION( PICML::EventRef, "PICML::EventRef" );
IMPLEMENT_BONEXTENSION( PICML::ExceptionRef, "PICML::ExceptionRef" );
IMPLEMENT_BONEXTENSION( PICML::ExternalResources, "PICML::ExternalResources" );
IMPLEMENT_BONEXTENSION( WSML::FaultRef, "WSML::FaultRef" );
IMPLEMENT_BONEXTENSION( PICML::FileRef, "PICML::FileRef" );
IMPLEMENT_BONEXTENSION( PICML::GetException, "PICML::GetException" );
IMPLEMENT_BONEXTENSION( PICML::ImplementationArtifactReference, "PICML::ImplementationArtifactReference" );
IMPLEMENT_ABSTRACT_BONEXTENSION( PICML::ParameterType );
IMPLEMENT_BONEXTENSION( PICML::InParameter, "PICML::InParameter" );
IMPLEMENT_BONEXTENSION( PICML::InoutParameter, "PICML::InoutParameter" );
IMPLEMENT_BONEXTENSION( PICML::OutParameter, "PICML::OutParameter" );
IMPLEMENT_BONEXTENSION( PICML::Inherits, "PICML::Inherits" );
IMPLEMENT_BONEXTENSION( PICML::LookupKey, "PICML::LookupKey" );
IMPLEMENT_BONEXTENSION( PICML::Member, "PICML::Member" );
IMPLEMENT_BONEXTENSION( WSML::MessageRef, "WSML::MessageRef" );
IMPLEMENT_BONEXTENSION( PICML::NodeReference, "PICML::NodeReference" );
IMPLEMENT_BONEXTENSION( WSML::OperationRef, "WSML::OperationRef" );
IMPLEMENT_BONEXTENSION( PICML::OperationRef, "PICML::OperationRef" );
IMPLEMENT_BONEXTENSION( PICML::PackageConfigurationReference, "PICML::PackageConfigurationReference" );
IMPLEMENT_BONEXTENSION( WSML::Part, "WSML::Part" );
IMPLEMENT_BONEXTENSION( WSML::PartRef, "WSML::PartRef" );
IMPLEMENT_BONEXTENSION( PICML::PathReference, "PICML::PathReference" );
IMPLEMENT_BONEXTENSION( PICML::ReturnType, "PICML::ReturnType" );
IMPLEMENT_BONEXTENSION( WSML::ServiceRef, "WSML::ServiceRef" );
IMPLEMENT_BONEXTENSION( PICML::SetException, "PICML::SetException" );
IMPLEMENT_BONEXTENSION( PICML::SharedComponentReference, "PICML::SharedComponentReference" );
IMPLEMENT_BONEXTENSION( PICML::Supports, "PICML::Supports" );
IMPLEMENT_BONEXTENSION( PICML::Variable, "PICML::Variable" );
IMPLEMENT_BONEXTENSION( PICML::WorkerType, "PICML::WorkerType" );


} // namespace BON

//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentAnalysesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentAnalyses
	bool rv = pVisitor->visitComponentAnalyses( PICML::ComponentAnalyses( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::BenchmarkAnalysis"
//********************************************************************************
std::set<PICML::BenchmarkAnalysis> PICML::ComponentAnalysesImpl::getBenchmarkAnalysis()
{
	std::set<PICML::BenchmarkAnalysis> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::BenchmarkAnalysis");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::BenchmarkAnalysis elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentBuildImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentBuild
	bool rv = pVisitor->visitComponentBuild( PICML::ComponentBuild( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::MPC"
//********************************************************************************
std::set<PICML::MPC> PICML::ComponentBuildImpl::getMPC()
{
	std::set<PICML::MPC> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::MPC");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::MPC elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentImplementationsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentImplementations
	bool rv = pVisitor->visitComponentImplementations( PICML::ComponentImplementations( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::ComponentImplementationContainer"
//********************************************************************************
std::set<PICML::ComponentImplementationContainer> PICML::ComponentImplementationsImpl::getComponentImplementationContainer()
{
	std::set<PICML::ComponentImplementationContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::ComponentImplementationContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::ComponentImplementationContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentPackagesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentPackages
	bool rv = pVisitor->visitComponentPackages( PICML::ComponentPackages( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::PackageContainer"
//********************************************************************************
std::set<PICML::PackageContainer> PICML::ComponentPackagesImpl::getPackageContainer()
{
	std::set<PICML::PackageContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::PackageContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::PackageContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentTypesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentTypes
	bool rv = pVisitor->visitComponentTypes( PICML::ComponentTypes( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::ComponentContainer"
//********************************************************************************
std::set<PICML::ComponentContainer> PICML::ComponentTypesImpl::getComponentContainer()
{
	std::set<PICML::ComponentContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::ComponentContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::ComponentContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DeploymentPlansImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::DeploymentPlans
	bool rv = pVisitor->visitDeploymentPlans( PICML::DeploymentPlans( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::DeploymentPlan"
//********************************************************************************
std::set<PICML::DeploymentPlan> PICML::DeploymentPlansImpl::getDeploymentPlan()
{
	std::set<PICML::DeploymentPlan> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::DeploymentPlan");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::DeploymentPlan elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationArtifactsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ImplementationArtifacts
	bool rv = pVisitor->visitImplementationArtifacts( PICML::ImplementationArtifacts( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::ArtifactContainer"
//********************************************************************************
std::set<PICML::ArtifactContainer> PICML::ImplementationArtifactsImpl::getArtifactContainer()
{
	std::set<PICML::ArtifactContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::ArtifactContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::ArtifactContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InterfaceDefinitionsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InterfaceDefinitions
	bool rv = pVisitor->visitInterfaceDefinitions( PICML::InterfaceDefinitions( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::File"
//********************************************************************************
std::set<PICML::File> PICML::InterfaceDefinitionsImpl::getFile()
{
	std::set<PICML::File> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::File");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::File elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfigurationsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfigurations
	bool rv = pVisitor->visitPackageConfigurations( PICML::PackageConfigurations( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::PackageConfigurationContainer"
//********************************************************************************
std::set<PICML::PackageConfigurationContainer> PICML::PackageConfigurationsImpl::getPackageConfigurationContainer()
{
	std::set<PICML::PackageConfigurationContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::PackageConfigurationContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::PackageConfigurationContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PathDiagramsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PathDiagrams
	bool rv = pVisitor->visitPathDiagrams( PICML::PathDiagrams( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::Paths"
//********************************************************************************
std::set<PICML::Paths> PICML::PathDiagramsImpl::getPaths()
{
	std::set<PICML::Paths> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::Paths");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::Paths elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PredefinedTypesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PredefinedTypes
	bool rv = pVisitor->visitPredefinedTypes( PICML::PredefinedTypes( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::Boolean"
//********************************************************************************
std::set<PICML::Boolean> PICML::PredefinedTypesImpl::getBoolean()
{
	std::set<PICML::Boolean> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::Boolean");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::Boolean elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::Byte"
//********************************************************************************
std::set<PICML::Byte> PICML::PredefinedTypesImpl::getByte()
{
	std::set<PICML::Byte> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::Byte");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::Byte elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::GenericObject"
//********************************************************************************
std::set<PICML::GenericObject> PICML::PredefinedTypesImpl::getGenericObject()
{
	std::set<PICML::GenericObject> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::GenericObject");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::GenericObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::GenericValue"
//********************************************************************************
std::set<PICML::GenericValue> PICML::PredefinedTypesImpl::getGenericValue()
{
	std::set<PICML::GenericValue> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::GenericValue");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::GenericValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::GenericValueObject"
//********************************************************************************
std::set<PICML::GenericValueObject> PICML::PredefinedTypesImpl::getGenericValueObject()
{
	std::set<PICML::GenericValueObject> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::GenericValueObject");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::GenericValueObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::LongInteger"
//********************************************************************************
std::set<PICML::LongInteger> PICML::PredefinedTypesImpl::getLongInteger()
{
	std::set<PICML::LongInteger> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::LongInteger");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::LongInteger elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for kind "PICML::PredefinedType" and its descendants
//********************************************************************************
std::set<PICML::PredefinedType> PICML::PredefinedTypesImpl::getPredefinedType()
{
	std::set<PICML::PredefinedType> res;
	const int len = 11;
	std::set<BON::Object> kinds_vec[ len];
	kinds_vec[0] = FolderImpl::getChildObjects("PICML::Boolean");
	kinds_vec[1] = FolderImpl::getChildObjects("PICML::Byte");
	kinds_vec[2] = FolderImpl::getChildObjects("PICML::GenericObject");
	kinds_vec[3] = FolderImpl::getChildObjects("PICML::GenericValue");
	kinds_vec[4] = FolderImpl::getChildObjects("PICML::GenericValueObject");
	kinds_vec[5] = FolderImpl::getChildObjects("PICML::LongInteger");
	kinds_vec[6] = FolderImpl::getChildObjects("PICML::RealNumber");
	kinds_vec[7] = FolderImpl::getChildObjects("PICML::ShortInteger");
	kinds_vec[8] = FolderImpl::getChildObjects("PICML::String");
	kinds_vec[9] = FolderImpl::getChildObjects("PICML::TypeEncoding");
	kinds_vec[10] = FolderImpl::getChildObjects("PICML::TypeKind");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::Object>::iterator i = kinds_vec[k].begin(); i != kinds_vec[k].end(); ++i)
		{
			PICML::PredefinedType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for kind "PICML::RealNumber"
//********************************************************************************
std::set<PICML::RealNumber> PICML::PredefinedTypesImpl::getRealNumber()
{
	std::set<PICML::RealNumber> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::RealNumber");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::RealNumber elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::ShortInteger"
//********************************************************************************
std::set<PICML::ShortInteger> PICML::PredefinedTypesImpl::getShortInteger()
{
	std::set<PICML::ShortInteger> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::ShortInteger");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::ShortInteger elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::String"
//********************************************************************************
std::set<PICML::String> PICML::PredefinedTypesImpl::getString()
{
	std::set<PICML::String> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::String");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::String elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::TypeEncoding"
//********************************************************************************
std::set<PICML::TypeEncoding> PICML::PredefinedTypesImpl::getTypeEncoding()
{
	std::set<PICML::TypeEncoding> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::TypeEncoding");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::TypeEncoding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for kind "PICML::TypeKind"
//********************************************************************************
std::set<PICML::TypeKind> PICML::PredefinedTypesImpl::getTypeKind()
{
	std::set<PICML::TypeKind> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::TypeKind");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::TypeKind elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TargetsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Targets
	bool rv = pVisitor->visitTargets( PICML::Targets( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::Domain"
//********************************************************************************
std::set<PICML::Domain> PICML::TargetsImpl::getDomain()
{
	std::set<PICML::Domain> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::Domain");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::Domain elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TopLevelPackagesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TopLevelPackages
	bool rv = pVisitor->visitTopLevelPackages( PICML::TopLevelPackages( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::TopLevelPackageContainer"
//********************************************************************************
std::set<PICML::TopLevelPackageContainer> PICML::TopLevelPackagesImpl::getTopLevelPackageContainer()
{
	std::set<PICML::TopLevelPackageContainer> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::TopLevelPackageContainer");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::TopLevelPackageContainer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerLibrariesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkerLibraries
	bool rv = pVisitor->visitWorkerLibraries( PICML::WorkerLibraries( this));
	return rv;
}


//********************************************************************************
// getter for kind "PICML::WorkerLibrary"
//********************************************************************************
std::set<PICML::WorkerLibrary> PICML::WorkerLibrariesImpl::getWorkerLibrary()
{
	std::set<PICML::WorkerLibrary> res;
	std::set<BON::Object> kinds = FolderImpl::getChildObjects("PICML::WorkerLibrary");
	for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
	{
		PICML::WorkerLibrary elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ActionBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ActionBase
	bool rv = pVisitor->visitActionBase( PICML::ActionBase( this));
	return rv;
}


//********************************************************************************
// returns src PICML::BranchStates
//********************************************************************************
std::multiset<PICML::BranchState> PICML::ActionBaseImpl::getBranchTransitionSrcs()
{
	std::multiset<PICML::BranchState> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BranchTransition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::BranchState dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::StateBases
//********************************************************************************
std::multiset<PICML::StateBase> PICML::ActionBaseImpl::getEffectDsts()
{
	std::multiset<PICML::StateBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Effect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::StateBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::BranchTransition> PICML::ActionBaseImpl::getInBranchTransitionLinks()
{
	std::set<PICML::BranchTransition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::BranchTransition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Transition> PICML::ActionBaseImpl::getInTransitionLinks()
{
	std::set<PICML::Transition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Transition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Effect> PICML::ActionBaseImpl::getOutEffectLinks()
{
	std::set<PICML::Effect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Effect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::States
//********************************************************************************
std::multiset<PICML::State> PICML::ActionBaseImpl::getTransitionSrcs()
{
	std::multiset<PICML::State> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Transition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::State dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::ActionBaseImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BehaviorModelImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::BehaviorModel
	bool rv = pVisitor->visitBehaviorModel( PICML::BehaviorModel( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Action" among "PICML::ActionBase"s and its descendants
//********************************************************************************
std::set<PICML::Action> PICML::BehaviorModelImpl::getAction()
{
	std::set<PICML::Action> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Action");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Action elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::ActionBase"s and its descendants
//********************************************************************************
std::set<PICML::ActionBase> PICML::BehaviorModelImpl::getActionBase()
{
	std::set<PICML::ActionBase> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Action");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::CompositeAction");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::OutputAction");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::ActionBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::BranchState" among "PICML::StateBase"s and its descendants
//********************************************************************************
std::set<PICML::BranchState> PICML::BehaviorModelImpl::getBranchState()
{
	std::set<PICML::BranchState> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::BranchState");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::BranchState elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::BranchTransition" among "PICML::BranchTransition"s
//********************************************************************************
std::set<PICML::BranchTransition> PICML::BehaviorModelImpl::getBranchTransition()
{
	std::set<PICML::BranchTransition> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::BranchTransition");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::BranchTransition elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::CompositeAction" among "PICML::ActionBase"s and its descendants
//********************************************************************************
std::set<PICML::CompositeAction> PICML::BehaviorModelImpl::getCompositeAction()
{
	std::set<PICML::CompositeAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::CompositeAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::CompositeAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Effect" among "PICML::Effect"s
//********************************************************************************
std::set<PICML::Effect> PICML::BehaviorModelImpl::getEffect()
{
	std::set<PICML::Effect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Effect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Effect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Finish" among "PICML::Finish"s
//********************************************************************************
std::set<PICML::Finish> PICML::BehaviorModelImpl::getFinish()
{
	std::set<PICML::Finish> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Finish");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Finish elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::InputAction" among "PICML::InputAction"s
//********************************************************************************
std::set<PICML::InputAction> PICML::BehaviorModelImpl::getInputAction()
{
	std::set<PICML::InputAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InputAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InputAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::InputEffect" among "PICML::InputEffect"s
//********************************************************************************
std::set<PICML::InputEffect> PICML::BehaviorModelImpl::getInputEffect()
{
	std::set<PICML::InputEffect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InputEffect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InputEffect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::OutputAction" among "PICML::ActionBase"s and its descendants
//********************************************************************************
std::set<PICML::OutputAction> PICML::BehaviorModelImpl::getOutputAction()
{
	std::set<PICML::OutputAction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OutputAction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OutputAction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::State" among "PICML::StateBase"s and its descendants
//********************************************************************************
std::set<PICML::State> PICML::BehaviorModelImpl::getState()
{
	std::set<PICML::State> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::State");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::State elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::StateBase"s and its descendants
//********************************************************************************
std::set<PICML::StateBase> PICML::BehaviorModelImpl::getStateBase()
{
	std::set<PICML::StateBase> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::BranchState");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::State");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::StateBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::Transition" among "PICML::Transition"s
//********************************************************************************
std::set<PICML::Transition> PICML::BehaviorModelImpl::getTransition()
{
	std::set<PICML::Transition> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Transition");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Transition elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Variable" among "PICML::Variable"s
//********************************************************************************
std::set<PICML::Variable> PICML::BehaviorModelImpl::getVariable()
{
	std::set<PICML::Variable> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Variable");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Variable elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PrefixableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Prefixable
	bool rv = pVisitor->visitPrefixable( PICML::Prefixable( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::PrefixableImpl::getPrefixTag()
{
	return FCOImpl::getAttribute("PrefixTag")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::PrefixableImpl::setPrefixTag( const std::string& val)
{
	FCOImpl::getAttribute("PrefixTag")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SupportsInterfacesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SupportsInterfaces
	bool rv = pVisitor->visitSupportsInterfaces( PICML::SupportsInterfaces( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Supports" among "PICML::Supports"s
//********************************************************************************
std::set<PICML::Supports> PICML::SupportsInterfacesImpl::getSupports()
{
	std::set<PICML::Supports> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Supports");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Supports elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CommonPortAttrsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::CommonPortAttrs
	bool rv = pVisitor->visitCommonPortAttrs( PICML::CommonPortAttrs( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CommonPortAttrsImpl::isexclusiveProvider()
{
	return FCOImpl::getAttribute("exclusiveProvider")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CommonPortAttrsImpl::isexclusiveUser()
{
	return FCOImpl::getAttribute("exclusiveUser")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CommonPortAttrsImpl::isoptional()
{
	return FCOImpl::getAttribute("optional")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::CommonPortAttrsImpl::setexclusiveProvider( bool val)
{
	FCOImpl::getAttribute("exclusiveProvider")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::CommonPortAttrsImpl::setexclusiveUser( bool val)
{
	FCOImpl::getAttribute("exclusiveUser")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::CommonPortAttrsImpl::setoptional( bool val)
{
	FCOImpl::getAttribute("optional")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ConstantTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ConstantType
	bool rv = pVisitor->visitConstantType( PICML::ConstantType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::GraphVertexImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::GraphVertex
	bool rv = pVisitor->visitGraphVertex( PICML::GraphVertex( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Edges
//********************************************************************************
std::multiset<PICML::Edge> PICML::GraphVertexImpl::getDstEdgeDsts()
{
	std::multiset<PICML::Edge> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("DstEdge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Edge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::SrcEdge> PICML::GraphVertexImpl::getInSrcEdgeLinks()
{
	std::set<PICML::SrcEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::SrcEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::DstEdge> PICML::GraphVertexImpl::getOutDstEdgeLinks()
{
	std::set<PICML::DstEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::DstEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::Edges
//********************************************************************************
std::multiset<PICML::Edge> PICML::GraphVertexImpl::getSrcEdgeSrcs()
{
	std::multiset<PICML::Edge> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("SrcEdge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Edge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ManageableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Manageable
	bool rv = pVisitor->visitManageable( PICML::Manageable( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ManagesComponent> PICML::ManageableImpl::getInManagesComponentLinks()
{
	std::set<PICML::ManagesComponent> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ManagesComponent c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::ComponentFactorys
//********************************************************************************
std::multiset<PICML::ComponentFactory> PICML::ManageableImpl::getManagesComponentSrcs()
{
	std::multiset<PICML::ComponentFactory> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ManagesComponent");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentFactory dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MemberTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MemberType
	bool rv = pVisitor->visitMemberType( PICML::MemberType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MultiInputBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MultiInputBase
	bool rv = pVisitor->visitMultiInputBase( PICML::MultiInputBase( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::InputActions
//********************************************************************************
std::multiset<PICML::InputAction> PICML::MultiInputBaseImpl::getMultiInputDsts()
{
	std::multiset<PICML::InputAction> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MultiInput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::InputAction dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MultiInput> PICML::MultiInputBaseImpl::getOutMultiInputLinks()
{
	std::set<PICML::MultiInput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MultiInput c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MultiOutputBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MultiOutputBase
	bool rv = pVisitor->visitMultiOutputBase( PICML::MultiOutputBase( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ProvideableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Provideable
	bool rv = pVisitor->visitProvideable( PICML::Provideable( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SingleInputBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SingleInputBase
	bool rv = pVisitor->visitSingleInputBase( PICML::SingleInputBase( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::InputActions
//********************************************************************************
std::multiset<PICML::InputAction> PICML::SingleInputBaseImpl::getInputDsts()
{
	std::multiset<PICML::InputAction> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Input");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::InputAction dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Input> PICML::SingleInputBaseImpl::getOutInputLinks()
{
	std::set<PICML::Input> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Input c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SingleOutputBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SingleOutputBase
	bool rv = pVisitor->visitSingleOutputBase( PICML::SingleOutputBase( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TaggableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Taggable
	bool rv = pVisitor->visitTaggable( PICML::Taggable( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::TaggableImpl::getSpecifyIdTag()
{
	return FCOImpl::getAttribute("SpecifyIdTag")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::TaggableImpl::getVersionTag()
{
	return FCOImpl::getAttribute("VersionTag")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::TaggableImpl::setSpecifyIdTag( const std::string& val)
{
	FCOImpl::getAttribute("SpecifyIdTag")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::TaggableImpl::setVersionTag( const std::string& val)
{
	FCOImpl::getAttribute("VersionTag")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ActionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Action
	bool rv = pVisitor->visitAction( PICML::Action( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
long PICML::ActionImpl::getDuration()
{
	return FCOImpl::getAttribute("Duration")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ActionImpl::isLogAction()
{
	return FCOImpl::getAttribute("LogAction")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ActionImpl::setDuration( const long val)
{
	FCOImpl::getAttribute("Duration")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ActionImpl::setLogAction( bool val)
{
	FCOImpl::getAttribute("LogAction")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CompositeActionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::CompositeAction
	bool rv = pVisitor->visitCompositeAction( PICML::CompositeAction( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ConnectedComponentImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ConnectedComponent
	bool rv = pVisitor->visitConnectedComponent( PICML::ConnectedComponent( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::DstEdge" among "PICML::DstEdge"s
//********************************************************************************
std::set<PICML::DstEdge> PICML::ConnectedComponentImpl::getDstEdge()
{
	std::set<PICML::DstEdge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::DstEdge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::DstEdge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::InEventPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::InEventPort> PICML::ConnectedComponentImpl::getInEventPort()
{
	std::set<PICML::InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::OutEventPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::OutEventPort> PICML::ConnectedComponentImpl::getOutEventPort()
{
	std::set<PICML::OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::Port> PICML::ConnectedComponentImpl::getPort()
{
	std::set<PICML::Port> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::InEventPort");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::OutEventPort");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::ProvidedRequestPort");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::RequiredRequestPort");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::Port elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::ProvidedRequestPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::ProvidedRequestPort> PICML::ConnectedComponentImpl::getProvidedRequestPort()
{
	std::set<PICML::ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RequiredRequestPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::RequiredRequestPort> PICML::ConnectedComponentImpl::getRequiredRequestPort()
{
	std::set<PICML::RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ExceptionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Exception
	bool rv = pVisitor->visitException( PICML::Exception( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Member" among "PICML::Member"s
//********************************************************************************
std::set<PICML::Member> PICML::ExceptionImpl::getMember()
{
	std::set<PICML::Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::FileImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::File
	bool rv = pVisitor->visitFile( PICML::File( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Aggregate" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Aggregate> PICML::FileImpl::getAggregate()
{
	std::set<PICML::Aggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Aggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Aggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Alias" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Alias> PICML::FileImpl::getAlias()
{
	std::set<PICML::Alias> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Alias");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Alias elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Boxed" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Boxed> PICML::FileImpl::getBoxed()
{
	std::set<PICML::Boxed> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Boxed");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Boxed elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Collection" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Collection> PICML::FileImpl::getCollection()
{
	std::set<PICML::Collection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Collection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Collection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Component" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Component> PICML::FileImpl::getComponent()
{
	std::set<PICML::Component> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Component");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Component elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentFactory" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::ComponentFactory> PICML::FileImpl::getComponentFactory()
{
	std::set<PICML::ComponentFactory> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentFactory");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentFactory elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::FileImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Constant" among "PICML::Constant"s
//********************************************************************************
std::set<PICML::Constant> PICML::FileImpl::getConstant()
{
	std::set<PICML::Constant> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Constant");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Constant elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Enum" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Enum> PICML::FileImpl::getEnum()
{
	std::set<PICML::Enum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Enum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Enum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Event" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Event> PICML::FileImpl::getEvent()
{
	std::set<PICML::Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Exception" among "PICML::Exception"s
//********************************************************************************
std::set<PICML::Exception> PICML::FileImpl::getException()
{
	std::set<PICML::Exception> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Exception");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Exception elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::FileRef" among "PICML::FileRef"s
//********************************************************************************
std::set<PICML::FileRef> PICML::FileImpl::getFileRef()
{
	std::set<PICML::FileRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FileRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FileRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ManagesComponent" among "PICML::ManagesComponent"s
//********************************************************************************
std::set<PICML::ManagesComponent> PICML::FileImpl::getManagesComponent()
{
	std::set<PICML::ManagesComponent> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ManagesComponent");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ManagesComponent elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::NamedType> PICML::FileImpl::getNamedType()
{
	std::set<PICML::NamedType> res;
	const int len = 11;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Aggregate");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::Component");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::ComponentFactory");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::Enum");
	roles_vec[4] = ModelImpl::getChildFCOsAs("PICML::Event");
	roles_vec[5] = ModelImpl::getChildFCOsAs("PICML::Object");
	roles_vec[6] = ModelImpl::getChildFCOsAs("PICML::SwitchedAggregate");
	roles_vec[7] = ModelImpl::getChildFCOsAs("PICML::ValueObject");
	roles_vec[8] = ModelImpl::getChildFCOsAs("PICML::Alias");
	roles_vec[9] = ModelImpl::getChildFCOsAs("PICML::Boxed");
	roles_vec[10] = ModelImpl::getChildFCOsAs("PICML::Collection");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::NamedType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::Object" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Object> PICML::FileImpl::getObject()
{
	std::set<PICML::Object> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Object");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Object elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Package" among "PICML::Package"s
//********************************************************************************
std::set<PICML::Package> PICML::FileImpl::getPackage()
{
	std::set<PICML::Package> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Package");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Package elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::SwitchedAggregate" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::SwitchedAggregate> PICML::FileImpl::getSwitchedAggregate()
{
	std::set<PICML::SwitchedAggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SwitchedAggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SwitchedAggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ValueObject" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::ValueObject> PICML::FileImpl::getValueObject()
{
	std::set<PICML::ValueObject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ValueObject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ValueObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::OperationBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::OperationBase
	bool rv = pVisitor->visitOperationBase( PICML::OperationBase( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::InParameter" among "PICML::InParameter"s
//********************************************************************************
std::set<PICML::InParameter> PICML::OperationBaseImpl::getInParameter()
{
	std::set<PICML::InParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::OutputActionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::OutputAction
	bool rv = pVisitor->visitOutputAction( PICML::OutputAction( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Package
	bool rv = pVisitor->visitPackage( PICML::Package( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Aggregate" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Aggregate> PICML::PackageImpl::getAggregate()
{
	std::set<PICML::Aggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Aggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Aggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Alias" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Alias> PICML::PackageImpl::getAlias()
{
	std::set<PICML::Alias> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Alias");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Alias elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Boxed" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Boxed> PICML::PackageImpl::getBoxed()
{
	std::set<PICML::Boxed> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Boxed");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Boxed elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Collection" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Collection> PICML::PackageImpl::getCollection()
{
	std::set<PICML::Collection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Collection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Collection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Component" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Component> PICML::PackageImpl::getComponent()
{
	std::set<PICML::Component> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Component");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Component elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentFactory" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::ComponentFactory> PICML::PackageImpl::getComponentFactory()
{
	std::set<PICML::ComponentFactory> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentFactory");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentFactory elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::PackageImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Constant" among "PICML::Constant"s
//********************************************************************************
std::set<PICML::Constant> PICML::PackageImpl::getConstant()
{
	std::set<PICML::Constant> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Constant");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Constant elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Enum" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Enum> PICML::PackageImpl::getEnum()
{
	std::set<PICML::Enum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Enum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Enum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Event" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Event> PICML::PackageImpl::getEvent()
{
	std::set<PICML::Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Exception" among "PICML::Exception"s
//********************************************************************************
std::set<PICML::Exception> PICML::PackageImpl::getException()
{
	std::set<PICML::Exception> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Exception");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Exception elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ManagesComponent" among "PICML::ManagesComponent"s
//********************************************************************************
std::set<PICML::ManagesComponent> PICML::PackageImpl::getManagesComponent()
{
	std::set<PICML::ManagesComponent> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ManagesComponent");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ManagesComponent elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::NamedType> PICML::PackageImpl::getNamedType()
{
	std::set<PICML::NamedType> res;
	const int len = 11;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Aggregate");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::Component");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::ComponentFactory");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::Enum");
	roles_vec[4] = ModelImpl::getChildFCOsAs("PICML::Event");
	roles_vec[5] = ModelImpl::getChildFCOsAs("PICML::Object");
	roles_vec[6] = ModelImpl::getChildFCOsAs("PICML::SwitchedAggregate");
	roles_vec[7] = ModelImpl::getChildFCOsAs("PICML::ValueObject");
	roles_vec[8] = ModelImpl::getChildFCOsAs("PICML::Alias");
	roles_vec[9] = ModelImpl::getChildFCOsAs("PICML::Boxed");
	roles_vec[10] = ModelImpl::getChildFCOsAs("PICML::Collection");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::NamedType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::Object" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::Object> PICML::PackageImpl::getObject()
{
	std::set<PICML::Object> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Object");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Object elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Package" among "PICML::Package"s
//********************************************************************************
std::set<PICML::Package> PICML::PackageImpl::getPackage()
{
	std::set<PICML::Package> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Package");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Package elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::SwitchedAggregate" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::SwitchedAggregate> PICML::PackageImpl::getSwitchedAggregate()
{
	std::set<PICML::SwitchedAggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SwitchedAggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SwitchedAggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ValueObject" among "PICML::NamedType"s and its descendants
//********************************************************************************
std::set<PICML::ValueObject> PICML::PackageImpl::getValueObject()
{
	std::set<PICML::ValueObject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ValueObject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ValueObject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ReadonlyAttributeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ReadonlyAttribute
	bool rv = pVisitor->visitReadonlyAttribute( PICML::ReadonlyAttribute( this));
	return rv;
}


//********************************************************************************
// returns src PICML::AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::ReadonlyAttributeImpl::getAttributeDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeDelegate");
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ReadonlyAttributeImpl::getAttributeValueDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AttributeValue");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeDelegate> PICML::ReadonlyAttributeImpl::getInAttributeDelegateLinks()
{
	std::set<PICML::AttributeDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeValue> PICML::ReadonlyAttributeImpl::getOutAttributeValueLinks()
{
	std::set<PICML::AttributeValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "PICML::AttributeMember" among "PICML::AttributeMember"s
//********************************************************************************
std::set<PICML::AttributeMember> PICML::ReadonlyAttributeImpl::getAttributeMember()
{
	std::set<PICML::AttributeMember> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AttributeMember");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AttributeMember elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::GetException" among "PICML::GetException"s
//********************************************************************************
std::set<PICML::GetException> PICML::ReadonlyAttributeImpl::getGetException()
{
	std::set<PICML::GetException> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::GetException");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::GetException elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TopLevelBehaviorImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TopLevelBehavior
	bool rv = pVisitor->visitTopLevelBehavior( PICML::TopLevelBehavior( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Environment" among "PICML::Environment"s
//********************************************************************************
std::set<PICML::Environment> PICML::TopLevelBehaviorImpl::getEnvironment()
{
	std::set<PICML::Environment> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Environment");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Environment elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Input" among "PICML::Input"s
//********************************************************************************
std::set<PICML::Input> PICML::TopLevelBehaviorImpl::getInput()
{
	std::set<PICML::Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::MultiInput" among "PICML::MultiInput"s
//********************************************************************************
std::set<PICML::MultiInput> PICML::TopLevelBehaviorImpl::getMultiInput()
{
	std::set<PICML::MultiInput> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MultiInput");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MultiInput elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PeriodicEvent" among "PICML::PeriodicEvent"s
//********************************************************************************
std::set<PICML::PeriodicEvent> PICML::TopLevelBehaviorImpl::getPeriodicEvent()
{
	std::set<PICML::PeriodicEvent> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PeriodicEvent");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PeriodicEvent elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::NamedTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::NamedType
	bool rv = pVisitor->visitNamedType( PICML::NamedType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PortImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Port
	bool rv = pVisitor->visitPort( PICML::Port( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PredefinedTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PredefinedType
	bool rv = pVisitor->visitPredefinedType( PICML::PredefinedType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DisplayNodeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::DisplayNode
	bool rv = pVisitor->visitDisplayNode( PICML::DisplayNode( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EnvironmentImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Environment
	bool rv = pVisitor->visitEnvironment( PICML::Environment( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PeriodicEventImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PeriodicEvent
	bool rv = pVisitor->visitPeriodicEvent( PICML::PeriodicEvent( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::PeriodicEventImpl::getPeriod()
{
	return FCOImpl::getAttribute("Period")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::PeriodicEventImpl::getProbability()
{
	return FCOImpl::getAttribute("Probability")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::PeriodicEventImpl::setPeriod( const std::string& val)
{
	FCOImpl::getAttribute("Period")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::PeriodicEventImpl::setProbability( const std::string& val)
{
	FCOImpl::getAttribute("Probability")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentRef
	bool rv = pVisitor->visitComponentRef( PICML::ComponentRef( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ComponentRefImpl::getComponentConfigPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ComponentRefImpl::getComponentInfoPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ComponentPropertyDescriptions
//********************************************************************************
std::multiset<PICML::ComponentPropertyDescription> PICML::ComponentRefImpl::getComponentPropertyDsts()
{
	std::multiset<PICML::ComponentPropertyDescription> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ComponentPropertyDescription dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::ComponentImplementations
//********************************************************************************
std::multiset<PICML::ComponentImplementation> PICML::ComponentRefImpl::getImplementsSrcs()
{
	std::multiset<PICML::ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Implements");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Implements> PICML::ComponentRefImpl::getInImplementsLinks()
{
	std::set<PICML::Implements> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Implements c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageInterface> PICML::ComponentRefImpl::getInPackageInterfaceLinks()
{
	std::set<PICML::PackageInterface> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageInterface c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentConfigProperty> PICML::ComponentRefImpl::getOutComponentConfigPropertyLinks()
{
	std::set<PICML::ComponentConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentInfoProperty> PICML::ComponentRefImpl::getOutComponentInfoPropertyLinks()
{
	std::set<PICML::ComponentInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentProperty> PICML::ComponentRefImpl::getOutComponentPropertyLinks()
{
	std::set<PICML::ComponentProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::ComponentPackages
//********************************************************************************
std::multiset<PICML::ComponentPackage> PICML::ComponentRefImpl::getPackageInterfaceSrcs()
{
	std::multiset<PICML::ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageInterface");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::Component PICML::ComponentRefImpl::getComponent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Component(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ConstantImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Constant
	bool rv = pVisitor->visitConstant( PICML::Constant( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ConstantImpl::getvalue()
{
	return FCOImpl::getAttribute("value")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ConstantImpl::setvalue( const std::string& val)
{
	FCOImpl::getAttribute("value")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
PICML::ConstantType PICML::ConstantImpl::getConstantType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ConstantType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AttributeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Attribute
	bool rv = pVisitor->visitAttribute( PICML::Attribute( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::SetException" among "PICML::SetException"s
//********************************************************************************
std::set<PICML::SetException> PICML::AttributeImpl::getSetException()
{
	std::set<PICML::SetException> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SetException");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SetException elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Component
	bool rv = pVisitor->visitComponent( PICML::Component( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ComponentImpl::getAssemblyConfigPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AssemblyConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Requirements
//********************************************************************************
std::multiset<PICML::Requirement> PICML::ComponentImpl::getAssemblyselectRequirementDsts()
{
	std::multiset<PICML::Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AssemblyselectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ExternalReferenceEndPoints
//********************************************************************************
std::multiset<PICML::ExternalReferenceEndPoint> PICML::ComponentImpl::getExternalDelegateDsts()
{
	std::multiset<PICML::ExternalReferenceEndPoint> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ExternalDelegate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ExternalReferenceEndPoint dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AssemblyConfigProperty> PICML::ComponentImpl::getOutAssemblyConfigPropertyLinks()
{
	std::set<PICML::AssemblyConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AssemblyConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AssemblyselectRequirement> PICML::ComponentImpl::getOutAssemblyselectRequirementLinks()
{
	std::set<PICML::AssemblyselectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AssemblyselectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ExternalDelegate> PICML::ComponentImpl::getOutExternalDelegateLinks()
{
	std::set<PICML::ExternalDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ExternalDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentImpl::getUUID()
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::Attribute" among "PICML::ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<PICML::Attribute> PICML::ComponentImpl::getAttribute()
{
	std::set<PICML::Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::InEventPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::InEventPort> PICML::ComponentImpl::getInEventPort()
{
	std::set<PICML::InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::OutEventPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::OutEventPort> PICML::ComponentImpl::getOutEventPort()
{
	std::set<PICML::OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::Port> PICML::ComponentImpl::getPort()
{
	std::set<PICML::Port> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::InEventPort");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::OutEventPort");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::ProvidedRequestPort");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::RequiredRequestPort");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::Port elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::ProvidedRequestPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::ProvidedRequestPort> PICML::ComponentImpl::getProvidedRequestPort()
{
	std::set<PICML::ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ReadonlyAttribute" among "PICML::ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<PICML::ReadonlyAttribute> PICML::ComponentImpl::getReadonlyAttribute()
{
	std::set<PICML::ReadonlyAttribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ReadonlyAttribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ReadonlyAttribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<PICML::ReadonlyAttribute> PICML::ComponentImpl::getReadonlyAttribute(int dummy)
{
	std::set<PICML::ReadonlyAttribute> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Attribute");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::ReadonlyAttribute");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::ReadonlyAttribute elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::RequiredRequestPort" among "PICML::Port"s and its descendants
//********************************************************************************
std::set<PICML::RequiredRequestPort> PICML::ComponentImpl::getRequiredRequestPort()
{
	std::set<PICML::RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::WorkerType" among "PICML::WorkerType"s
//********************************************************************************
std::set<PICML::WorkerType> PICML::ComponentImpl::getWorkerType()
{
	std::set<PICML::WorkerType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::WorkerType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::WorkerType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::HasExceptionsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::HasExceptions
	bool rv = pVisitor->visitHasExceptions( PICML::HasExceptions( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ExceptionRef" among "PICML::ExceptionRef"s
//********************************************************************************
std::set<PICML::ExceptionRef> PICML::HasExceptionsImpl::getExceptionRef()
{
	std::set<PICML::ExceptionRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ExceptionRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ExceptionRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InheritableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Inheritable
	bool rv = pVisitor->visitInheritable( PICML::Inheritable( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Attribute" among "PICML::ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<PICML::Attribute> PICML::InheritableImpl::getAttribute()
{
	std::set<PICML::Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Inherits" among "PICML::Inherits"s
//********************************************************************************
std::set<PICML::Inherits> PICML::InheritableImpl::getInherits()
{
	std::set<PICML::Inherits> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Inherits");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Inherits elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ReadonlyAttribute" among "PICML::ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<PICML::ReadonlyAttribute> PICML::InheritableImpl::getReadonlyAttribute()
{
	std::set<PICML::ReadonlyAttribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ReadonlyAttribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ReadonlyAttribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::ReadonlyAttribute"s and its descendants
//********************************************************************************
std::set<PICML::ReadonlyAttribute> PICML::InheritableImpl::getReadonlyAttribute(int dummy)
{
	std::set<PICML::ReadonlyAttribute> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Attribute");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::ReadonlyAttribute");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::ReadonlyAttribute elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::OnewayOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::OnewayOperation
	bool rv = pVisitor->visitOnewayOperation( PICML::OnewayOperation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::NoInheritableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::NoInheritable
	bool rv = pVisitor->visitNoInheritable( PICML::NoInheritable( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BooleanImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Boolean
	bool rv = pVisitor->visitBoolean( PICML::Boolean( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ByteImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Byte
	bool rv = pVisitor->visitByte( PICML::Byte( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::GenericObjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::GenericObject
	bool rv = pVisitor->visitGenericObject( PICML::GenericObject( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::GenericValueImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::GenericValue
	bool rv = pVisitor->visitGenericValue( PICML::GenericValue( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::GenericValueObjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::GenericValueObject
	bool rv = pVisitor->visitGenericValueObject( PICML::GenericValueObject( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::LongIntegerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::LongInteger
	bool rv = pVisitor->visitLongInteger( PICML::LongInteger( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RealNumberImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::RealNumber
	bool rv = pVisitor->visitRealNumber( PICML::RealNumber( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ShortIntegerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ShortInteger
	bool rv = pVisitor->visitShortInteger( PICML::ShortInteger( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::StringImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::String
	bool rv = pVisitor->visitString( PICML::String( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TypeEncodingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TypeEncoding
	bool rv = pVisitor->visitTypeEncoding( PICML::TypeEncoding( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TypeKindImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TypeKind
	bool rv = pVisitor->visitTypeKind( PICML::TypeKind( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BoxedImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Boxed
	bool rv = pVisitor->visitBoxed( PICML::Boxed( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::BoxedImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InEventPortImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InEventPort
	bool rv = pVisitor->visitInEventPort( PICML::InEventPort( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::InEventPortImpl::getEventSinkDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("EventSinkDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EventSinkDelegate> PICML::InEventPortImpl::getEventSinkDelegateLinks()
{
	std::set<PICML::EventSinkDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EventSinkDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::InEventPortImpl::getEventSinkDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("EventSinkDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EventSinkDelegate> PICML::InEventPortImpl::getInEventSinkDelegateLinks()
{
	std::set<PICML::EventSinkDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EventSinkDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::deliverTo> PICML::InEventPortImpl::getIndeliverToLinks()
{
	std::set<PICML::deliverTo> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::deliverTo c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::emit> PICML::InEventPortImpl::getInemitLinks()
{
	std::set<PICML::emit> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::emit c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EventSinkDelegate> PICML::InEventPortImpl::getOutEventSinkDelegateLinks()
{
	std::set<PICML::EventSinkDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EventSinkDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::PublishConnectors
//********************************************************************************
std::multiset<PICML::PublishConnector> PICML::InEventPortImpl::getdeliverToSrcs()
{
	std::multiset<PICML::PublishConnector> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("deliverTo");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::PublishConnector dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::InEventPortImpl::getemitSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("emit");
}


//********************************************************************************
//
//********************************************************************************
PICML::Event PICML::InEventPortImpl::getEvent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Event(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::OutEventPortImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::OutEventPort
	bool rv = pVisitor->visitOutEventPort( PICML::OutEventPort( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::OutEventPortImpl::getEventSourceDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("EventSourceDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EventSourceDelegate> PICML::OutEventPortImpl::getEventSourceDelegateLinks()
{
	std::set<PICML::EventSourceDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EventSourceDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::OutEventPortImpl::getEventSourceDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("EventSourceDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EventSourceDelegate> PICML::OutEventPortImpl::getInEventSourceDelegateLinks()
{
	std::set<PICML::EventSourceDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EventSourceDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EventSourceDelegate> PICML::OutEventPortImpl::getOutEventSourceDelegateLinks()
{
	std::set<PICML::EventSourceDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EventSourceDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::emit> PICML::OutEventPortImpl::getOutemitLinks()
{
	std::set<PICML::emit> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::emit c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::publish> PICML::OutEventPortImpl::getOutpublishLinks()
{
	std::set<PICML::publish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::publish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::OutEventPortImpl::getemitDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("emit");
}


//********************************************************************************
// returns dst PICML::PublishConnectors
//********************************************************************************
std::multiset<PICML::PublishConnector> PICML::OutEventPortImpl::getpublishDsts()
{
	std::multiset<PICML::PublishConnector> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("publish");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::PublishConnector dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::OutEventPortImpl::out_event_port_type_Type PICML::OutEventPortImpl::getout_event_port_type()
{
	std::string val = FCOImpl::getAttribute("out_event_port_type")->getStringValue();

	if ( val == "DirectConnect") return DirectConnect_out_event_port_type_Type;
	else if ( val == "RTEventChannel") return RTEventChannel_out_event_port_type_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
bool PICML::OutEventPortImpl::issingle_destination()
{
	return FCOImpl::getAttribute("single_destination")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::OutEventPortImpl::setout_event_port_type( OutEventPortImpl::out_event_port_type_Type val)
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
void PICML::OutEventPortImpl::setsingle_destination( bool val)
{
	FCOImpl::getAttribute("single_destination")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
PICML::Event PICML::OutEventPortImpl::getEvent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Event(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ProvidedRequestPortImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ProvidedRequestPort
	bool rv = pVisitor->visitProvidedRequestPort( PICML::ProvidedRequestPort( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ProvidedRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::ProvidedRequestPortImpl::getFacetDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("FacetDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::FacetDelegate> PICML::ProvidedRequestPortImpl::getFacetDelegateLinks()
{
	std::set<PICML::FacetDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::FacetDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::ProvidedRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::ProvidedRequestPortImpl::getFacetDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("FacetDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::FacetDelegate> PICML::ProvidedRequestPortImpl::getInFacetDelegateLinks()
{
	std::set<PICML::FacetDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::FacetDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<SIML::PortProxy> PICML::ProvidedRequestPortImpl::getInPortProxyLinks()
{
	std::set<SIML::PortProxy> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		SIML::PortProxy c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::invoke> PICML::ProvidedRequestPortImpl::getIninvokeLinks()
{
	std::set<PICML::invoke> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::invoke c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::FacetDelegate> PICML::ProvidedRequestPortImpl::getOutFacetDelegateLinks()
{
	std::set<PICML::FacetDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::FacetDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src WSML::Ports and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::ProvidedRequestPortImpl::getPortProxySrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("PortProxy");
}


//********************************************************************************
// returns src PICML::RequiredRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::ProvidedRequestPortImpl::getinvokeSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("invoke");
}


//********************************************************************************
//
//********************************************************************************
PICML::Provideable PICML::ProvidedRequestPortImpl::getProvideable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Provideable(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RequiredRequestPortImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::RequiredRequestPort
	bool rv = pVisitor->visitRequiredRequestPort( PICML::RequiredRequestPort( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ReceptacleDelegate> PICML::RequiredRequestPortImpl::getInReceptacleDelegateLinks()
{
	std::set<PICML::ReceptacleDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ReceptacleDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ReceptacleDelegate> PICML::RequiredRequestPortImpl::getOutReceptacleDelegateLinks()
{
	std::set<PICML::ReceptacleDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ReceptacleDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::invoke> PICML::RequiredRequestPortImpl::getOutinvokeLinks()
{
	std::set<PICML::invoke> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::invoke c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::RequiredRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::RequiredRequestPortImpl::getReceptacleDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("ReceptacleDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ReceptacleDelegate> PICML::RequiredRequestPortImpl::getReceptacleDelegateLinks()
{
	std::set<PICML::ReceptacleDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ReceptacleDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::RequiredRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::RequiredRequestPortImpl::getReceptacleDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("ReceptacleDelegate");
}


//********************************************************************************
// returns dst PICML::ProvidedRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::RequiredRequestPortImpl::getinvokeDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("invoke");
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RequiredRequestPortImpl::ismultiple_connections()
{
	return FCOImpl::getAttribute("multiple_connections")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::RequiredRequestPortImpl::setmultiple_connections( bool val)
{
	FCOImpl::getAttribute("multiple_connections")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
PICML::Provideable PICML::RequiredRequestPortImpl::getProvideable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Provideable(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AggregateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Aggregate
	bool rv = pVisitor->visitAggregate( PICML::Aggregate( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Member" among "PICML::Member"s
//********************************************************************************
std::set<PICML::Member> PICML::AggregateImpl::getMember()
{
	std::set<PICML::Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EnumImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Enum
	bool rv = pVisitor->visitEnum( PICML::Enum( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::EnumValue" among "PICML::EnumValue"s
//********************************************************************************
std::set<PICML::EnumValue> PICML::EnumImpl::getEnumValue()
{
	std::set<PICML::EnumValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::EnumValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::EnumValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::FactoryOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::FactoryOperation
	bool rv = pVisitor->visitFactoryOperation( PICML::FactoryOperation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::HasOperationsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::HasOperations
	bool rv = pVisitor->visitHasOperations( PICML::HasOperations( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Aggregate" among "PICML::NoInheritable"s and its descendants
//********************************************************************************
std::set<PICML::Aggregate> PICML::HasOperationsImpl::getAggregate()
{
	std::set<PICML::Aggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Aggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Aggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Alias" among "PICML::NoInheritable"s and its descendants
//********************************************************************************
std::set<PICML::Alias> PICML::HasOperationsImpl::getAlias()
{
	std::set<PICML::Alias> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Alias");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Alias elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Collection" among "PICML::NoInheritable"s and its descendants
//********************************************************************************
std::set<PICML::Collection> PICML::HasOperationsImpl::getCollection()
{
	std::set<PICML::Collection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Collection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Collection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Constant" among "PICML::Constant"s
//********************************************************************************
std::set<PICML::Constant> PICML::HasOperationsImpl::getConstant()
{
	std::set<PICML::Constant> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Constant");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Constant elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Enum" among "PICML::NoInheritable"s and its descendants
//********************************************************************************
std::set<PICML::Enum> PICML::HasOperationsImpl::getEnum()
{
	std::set<PICML::Enum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Enum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Enum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Exception" among "PICML::Exception"s
//********************************************************************************
std::set<PICML::Exception> PICML::HasOperationsImpl::getException()
{
	std::set<PICML::Exception> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Exception");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Exception elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::NoInheritable"s and its descendants
//********************************************************************************
std::set<PICML::NoInheritable> PICML::HasOperationsImpl::getNoInheritable()
{
	std::set<PICML::NoInheritable> res;
	const int len = 5;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Aggregate");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::Enum");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::SwitchedAggregate");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::Alias");
	roles_vec[4] = ModelImpl::getChildFCOsAs("PICML::Collection");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::NoInheritable elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::OnewayOperation" among "PICML::OnewayOperation"s
//********************************************************************************
std::set<PICML::OnewayOperation> PICML::HasOperationsImpl::getOnewayOperation()
{
	std::set<PICML::OnewayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OnewayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OnewayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::SwitchedAggregate" among "PICML::NoInheritable"s and its descendants
//********************************************************************************
std::set<PICML::SwitchedAggregate> PICML::HasOperationsImpl::getSwitchedAggregate()
{
	std::set<PICML::SwitchedAggregate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SwitchedAggregate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SwitchedAggregate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TwowayOperation" among "PICML::TwowayOperation"s
//********************************************************************************
std::set<PICML::TwowayOperation> PICML::HasOperationsImpl::getTwowayOperation()
{
	std::set<PICML::TwowayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TwowayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TwowayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::LookupOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::LookupOperation
	bool rv = pVisitor->visitLookupOperation( PICML::LookupOperation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SwitchedAggregateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SwitchedAggregate
	bool rv = pVisitor->visitSwitchedAggregate( PICML::SwitchedAggregate( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Discriminator" among "PICML::Discriminator"s
//********************************************************************************
std::set<PICML::Discriminator> PICML::SwitchedAggregateImpl::getDiscriminator()
{
	std::set<PICML::Discriminator> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Discriminator");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Discriminator elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Label" among "PICML::Label"s
//********************************************************************************
std::set<PICML::Label> PICML::SwitchedAggregateImpl::getLabel()
{
	std::set<PICML::Label> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Label");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Label elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::LabelConnection" among "PICML::LabelConnection"s
//********************************************************************************
std::set<PICML::LabelConnection> PICML::SwitchedAggregateImpl::getLabelConnection()
{
	std::set<PICML::LabelConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::LabelConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::LabelConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Member" among "PICML::Member"s
//********************************************************************************
std::set<PICML::Member> PICML::SwitchedAggregateImpl::getMember()
{
	std::set<PICML::Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TwowayOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TwowayOperation
	bool rv = pVisitor->visitTwowayOperation( PICML::TwowayOperation( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::InoutParameter" among "PICML::InoutParameter"s
//********************************************************************************
std::set<PICML::InoutParameter> PICML::TwowayOperationImpl::getInoutParameter()
{
	std::set<PICML::InoutParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InoutParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InoutParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::OutParameter" among "PICML::OutParameter"s
//********************************************************************************
std::set<PICML::OutParameter> PICML::TwowayOperationImpl::getOutParameter()
{
	std::set<PICML::OutParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OutParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OutParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ReturnType" among "PICML::ReturnType"s
//********************************************************************************
std::set<PICML::ReturnType> PICML::TwowayOperationImpl::getReturnType()
{
	std::set<PICML::ReturnType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ReturnType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ReturnType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AliasImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Alias
	bool rv = pVisitor->visitAlias( PICML::Alias( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::AliasImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CollectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Collection
	bool rv = pVisitor->visitCollection( PICML::Collection( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::CollectionImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentFactoryImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentFactory
	bool rv = pVisitor->visitComponentFactory( PICML::ComponentFactory( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Manageables
//********************************************************************************
std::multiset<PICML::Manageable> PICML::ComponentFactoryImpl::getManagesComponentDsts()
{
	std::multiset<PICML::Manageable> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ManagesComponent");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Manageable dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ManagesComponent> PICML::ComponentFactoryImpl::getOutManagesComponentLinks()
{
	std::set<PICML::ManagesComponent> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ManagesComponent c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "PICML::FactoryOperation" among "PICML::FactoryOperation"s
//********************************************************************************
std::set<PICML::FactoryOperation> PICML::ComponentFactoryImpl::getFactoryOperation()
{
	std::set<PICML::FactoryOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FactoryOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FactoryOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::LookupKey" among "PICML::LookupKey"s
//********************************************************************************
std::set<PICML::LookupKey> PICML::ComponentFactoryImpl::getLookupKey()
{
	std::set<PICML::LookupKey> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::LookupKey");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::LookupKey elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::LookupOperation" among "PICML::LookupOperation"s
//********************************************************************************
std::set<PICML::LookupOperation> PICML::ComponentFactoryImpl::getLookupOperation()
{
	std::set<PICML::LookupOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::LookupOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::LookupOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ObjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Object
	bool rv = pVisitor->visitObject( PICML::Object( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ObjectImpl::isabstract()
{
	return FCOImpl::getAttribute("abstract")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ObjectImpl::islocal()
{
	return FCOImpl::getAttribute("local")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ObjectImpl::setabstract( bool val)
{
	FCOImpl::getAttribute("abstract")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ObjectImpl::setlocal( bool val)
{
	FCOImpl::getAttribute("local")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ObjectByValueImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ObjectByValue
	bool rv = pVisitor->visitObjectByValue( PICML::ObjectByValue( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ObjectByValueImpl::isabstract()
{
	return FCOImpl::getAttribute("abstract")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ObjectByValueImpl::setabstract( bool val)
{
	FCOImpl::getAttribute("abstract")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "PICML::FactoryOperation" among "PICML::FactoryOperation"s
//********************************************************************************
std::set<PICML::FactoryOperation> PICML::ObjectByValueImpl::getFactoryOperation()
{
	std::set<PICML::FactoryOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FactoryOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FactoryOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::MakeMemberPrivate" among "PICML::MakeMemberPrivate"s
//********************************************************************************
std::set<PICML::MakeMemberPrivate> PICML::ObjectByValueImpl::getMakeMemberPrivate()
{
	std::set<PICML::MakeMemberPrivate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MakeMemberPrivate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MakeMemberPrivate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Member" among "PICML::Member"s
//********************************************************************************
std::set<PICML::Member> PICML::ObjectByValueImpl::getMember()
{
	std::set<PICML::Member> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Member");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Member elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PrivateFlag" among "PICML::PrivateFlag"s
//********************************************************************************
std::set<PICML::PrivateFlag> PICML::ObjectByValueImpl::getPrivateFlag()
{
	std::set<PICML::PrivateFlag> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PrivateFlag");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PrivateFlag elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EventImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Event
	bool rv = pVisitor->visitEvent( PICML::Event( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ValueObjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ValueObject
	bool rv = pVisitor->visitValueObject( PICML::ValueObject( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RequirementSatisfierImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::RequirementSatisfier
	bool rv = pVisitor->visitRequirementSatisfier( PICML::RequirementSatisfier( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::RequirementSatisfierImpl::getresourceType()
{
	return FCOImpl::getAttribute("resourceType")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::RequirementSatisfierImpl::setresourceType( const std::string& val)
{
	FCOImpl::getAttribute("resourceType")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::SatisfierProperty" among "PICML::SatisfierProperty"s
//********************************************************************************
std::set<PICML::SatisfierProperty> PICML::RequirementSatisfierImpl::getSatisfierProperty()
{
	std::set<PICML::SatisfierProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SatisfierProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SatisfierProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ElementsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Elements
	bool rv = pVisitor->visitElements( PICML::Elements( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BridgeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Bridge
	bool rv = pVisitor->visitBridge( PICML::Bridge( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Interconnects
//********************************************************************************
std::multiset<PICML::Interconnect> PICML::BridgeImpl::getBridge2InterconnectDsts()
{
	std::multiset<PICML::Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Bridge2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Interconnect2Bridge> PICML::BridgeImpl::getInInterconnect2BridgeLinks()
{
	std::set<PICML::Interconnect2Bridge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Interconnect2Bridge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::Interconnects
//********************************************************************************
std::multiset<PICML::Interconnect> PICML::BridgeImpl::getInterconnect2BridgeSrcs()
{
	std::multiset<PICML::Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Interconnect2Bridge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Bridge2Interconnect> PICML::BridgeImpl::getOutBridge2InterconnectLinks()
{
	std::set<PICML::Bridge2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Bridge2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::BridgeImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::BridgeImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::Resource" among "PICML::Resource"s
//********************************************************************************
std::set<PICML::Resource> PICML::BridgeImpl::getResource()
{
	std::set<PICML::Resource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Resource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Resource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CapabilityImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Capability
	bool rv = pVisitor->visitCapability( PICML::Capability( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ComponentImplementations
//********************************************************************************
std::multiset<PICML::ComponentImplementation> PICML::CapabilityImpl::getImplementationCapabilitySrcs()
{
	std::multiset<PICML::ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ImplementationCapability");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ImplementationCapability> PICML::CapabilityImpl::getInImplementationCapabilityLinks()
{
	std::set<PICML::ImplementationCapability> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ImplementationCapability c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InterconnectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Interconnect
	bool rv = pVisitor->visitInterconnect( PICML::Interconnect( this));
	return rv;
}


//********************************************************************************
// returns src PICML::Bridges
//********************************************************************************
std::multiset<PICML::Bridge> PICML::InterconnectImpl::getBridge2InterconnectSrcs()
{
	std::multiset<PICML::Bridge> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Bridge2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Bridge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Bridge2Interconnect> PICML::InterconnectImpl::getInBridge2InterconnectLinks()
{
	std::set<PICML::Bridge2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Bridge2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Node2Interconnect> PICML::InterconnectImpl::getInNode2InterconnectLinks()
{
	std::set<PICML::Node2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Node2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::Bridges
//********************************************************************************
std::multiset<PICML::Bridge> PICML::InterconnectImpl::getInterconnect2BridgeDsts()
{
	std::multiset<PICML::Bridge> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Interconnect2Bridge");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Bridge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Nodes
//********************************************************************************
std::multiset<PICML::Node> PICML::InterconnectImpl::getInterconnect2NodeDsts()
{
	std::multiset<PICML::Node> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Interconnect2Node");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Node dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::Nodes
//********************************************************************************
std::multiset<PICML::Node> PICML::InterconnectImpl::getNode2InterconnectSrcs()
{
	std::multiset<PICML::Node> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Node2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Node dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Interconnect2Bridge> PICML::InterconnectImpl::getOutInterconnect2BridgeLinks()
{
	std::set<PICML::Interconnect2Bridge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Interconnect2Bridge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Interconnect2Node> PICML::InterconnectImpl::getOutInterconnect2NodeLinks()
{
	std::set<PICML::Interconnect2Node> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Interconnect2Node c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::InterconnectImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::InterconnectImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::Resource" among "PICML::Resource"s
//********************************************************************************
std::set<PICML::Resource> PICML::InterconnectImpl::getResource()
{
	std::set<PICML::Resource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Resource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Resource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::NodeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Node
	bool rv = pVisitor->visitNode( PICML::Node( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Interconnect2Node> PICML::NodeImpl::getInInterconnect2NodeLinks()
{
	std::set<PICML::Interconnect2Node> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Interconnect2Node c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::Interconnects
//********************************************************************************
std::multiset<PICML::Interconnect> PICML::NodeImpl::getInterconnect2NodeSrcs()
{
	std::multiset<PICML::Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Interconnect2Node");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Interconnects
//********************************************************************************
std::multiset<PICML::Interconnect> PICML::NodeImpl::getNode2InterconnectDsts()
{
	std::multiset<PICML::Interconnect> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Node2Interconnect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Interconnect dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Node2Interconnect> PICML::NodeImpl::getOutNode2InterconnectLinks()
{
	std::set<PICML::Node2Interconnect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Node2Interconnect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Shares> PICML::NodeImpl::getOutSharesLinks()
{
	std::set<PICML::Shares> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Shares c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::SharedResources
//********************************************************************************
std::multiset<PICML::SharedResource> PICML::NodeImpl::getSharesDsts()
{
	std::multiset<PICML::SharedResource> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Shares");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::SharedResource dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::NodeImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::NodeImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::Resource" among "PICML::Resource"s
//********************************************************************************
std::set<PICML::Resource> PICML::NodeImpl::getResource()
{
	std::set<PICML::Resource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Resource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Resource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ResourceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Resource
	bool rv = pVisitor->visitResource( PICML::Resource( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SharedResourceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SharedResource
	bool rv = pVisitor->visitSharedResource( PICML::SharedResource( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Shares> PICML::SharedResourceImpl::getInSharesLinks()
{
	std::set<PICML::Shares> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Shares c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::Nodes
//********************************************************************************
std::multiset<PICML::Node> PICML::SharedResourceImpl::getSharesSrcs()
{
	std::multiset<PICML::Node> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Shares");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Node dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RequirementBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::RequirementBase
	bool rv = pVisitor->visitRequirementBase( PICML::RequirementBase( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::RequirementBaseImpl::getresourceType()
{
	return FCOImpl::getAttribute("resourceType")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::RequirementBaseImpl::setresourceType( const std::string& val)
{
	FCOImpl::getAttribute("resourceType")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::RequirementBaseImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationRequirementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ImplementationRequirement
	bool rv = pVisitor->visitImplementationRequirement( PICML::ImplementationRequirement( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MonolithDeployRequirement> PICML::ImplementationRequirementImpl::getInMonolithDeployRequirementLinks()
{
	std::set<PICML::MonolithDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MonolithDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::MonolithicImplementations
//********************************************************************************
std::multiset<PICML::MonolithicImplementation> PICML::ImplementationRequirementImpl::getMonolithDeployRequirementSrcs()
{
	std::multiset<PICML::MonolithicImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MonolithDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::MonolithicImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::ImplementationRequirementImpl::ResourceUsageKind_Type PICML::ImplementationRequirementImpl::getResourceUsageKind()
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
std::string PICML::ImplementationRequirementImpl::getcomponentPort()
{
	return FCOImpl::getAttribute("componentPort")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ImplementationRequirementImpl::getresourcePort()
{
	return FCOImpl::getAttribute("resourcePort")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationRequirementImpl::setResourceUsageKind( ImplementationRequirementImpl::ResourceUsageKind_Type val)
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
void PICML::ImplementationRequirementImpl::setcomponentPort( const std::string& val)
{
	FCOImpl::getAttribute("componentPort")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationRequirementImpl::setresourcePort( const std::string& val)
{
	FCOImpl::getAttribute("resourcePort")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RequirementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Requirement
	bool rv = pVisitor->visitRequirement( PICML::Requirement( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ImplementationArtifacts
//********************************************************************************
std::multiset<PICML::ImplementationArtifact> PICML::RequirementImpl::getArtifactDeployRequirementSrcs()
{
	std::multiset<PICML::ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::PublishConnectors
//********************************************************************************
std::multiset<PICML::PublishConnector> PICML::RequirementImpl::getAssemblyDeployRequirementSrcs()
{
	std::multiset<PICML::PublishConnector> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("AssemblyDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::PublishConnector dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::Components
//********************************************************************************
std::multiset<PICML::Component> PICML::RequirementImpl::getAssemblyselectRequirementSrcs()
{
	std::multiset<PICML::Component> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("AssemblyselectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Component dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactDeployRequirement> PICML::RequirementImpl::getInArtifactDeployRequirementLinks()
{
	std::set<PICML::ArtifactDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AssemblyDeployRequirement> PICML::RequirementImpl::getInAssemblyDeployRequirementLinks()
{
	std::set<PICML::AssemblyDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AssemblyDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AssemblyselectRequirement> PICML::RequirementImpl::getInAssemblyselectRequirementLinks()
{
	std::set<PICML::AssemblyselectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AssemblyselectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfSelectRequirement> PICML::RequirementImpl::getInPackageConfSelectRequirementLinks()
{
	std::set<PICML::PackageConfSelectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfSelectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::PackageConfigurations
//********************************************************************************
std::multiset<PICML::PackageConfiguration> PICML::RequirementImpl::getPackageConfSelectRequirementSrcs()
{
	std::multiset<PICML::PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfSelectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECConfigurationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ECConfiguration
	bool rv = pVisitor->visitECConfiguration( PICML::ECConfiguration( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Consumer2BehaviorConnection" among "PICML::Consumer2BehaviorConnection"s
//********************************************************************************
std::set<PICML::Consumer2BehaviorConnection> PICML::ECConfigurationImpl::getConsumer2BehaviorConnection()
{
	std::set<PICML::Consumer2BehaviorConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Consumer2BehaviorConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Consumer2BehaviorConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ECConsumer" among "PICML::ECRole"s and its descendants
//********************************************************************************
std::set<PICML::ECConsumer> PICML::ECConfigurationImpl::getECConsumer()
{
	std::set<PICML::ECConsumer> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ECConsumer");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ECConsumer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::ECRole"s and its descendants
//********************************************************************************
std::set<PICML::ECRole> PICML::ECConfigurationImpl::getECRole()
{
	std::set<PICML::ECRole> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::ECConsumer");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::ECSupplier");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::ECRole elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::ECSupplier" among "PICML::ECRole"s and its descendants
//********************************************************************************
std::set<PICML::ECSupplier> PICML::ECConfigurationImpl::getECSupplier()
{
	std::set<PICML::ECSupplier> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ECSupplier");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ECSupplier elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RecursiveFilterConnection" among "PICML::RecursiveFilterConnection"s
//********************************************************************************
std::set<PICML::RecursiveFilterConnection> PICML::ECConfigurationImpl::getRecursiveFilterConnection()
{
	std::set<PICML::RecursiveFilterConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RecursiveFilterConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RecursiveFilterConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RTRequirementsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::RTRequirements
	bool rv = pVisitor->visitRTRequirements( PICML::RTRequirements( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ServiceConsumer" among "PICML::ServiceConsumer"s
//********************************************************************************
std::set<PICML::ServiceConsumer> PICML::RTRequirementsImpl::getServiceConsumer()
{
	std::set<PICML::ServiceConsumer> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ServiceConsumer");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ServiceConsumer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ServiceProvider" among "PICML::ServiceProvider"s
//********************************************************************************
std::set<PICML::ServiceProvider> PICML::RTRequirementsImpl::getServiceProvider()
{
	std::set<PICML::ServiceProvider> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ServiceProvider");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ServiceProvider elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::OperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Operation
	bool rv = pVisitor->visitOperation( WSML::Operation( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::OperationImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::FaultMessage" among "WSML::FaultMessage"s
//********************************************************************************
std::set<WSML::FaultMessage> WSML::OperationImpl::getFaultMessage()
{
	std::set<WSML::FaultMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::FaultMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::FaultMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::InputMessage" among "WSML::InputMessage"s
//********************************************************************************
std::set<WSML::InputMessage> WSML::OperationImpl::getInputMessage()
{
	std::set<WSML::InputMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::InputMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::InputMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::MessageRef" among "WSML::MessageRef"s
//********************************************************************************
std::set<WSML::MessageRef> WSML::OperationImpl::getMessageRef()
{
	std::set<WSML::MessageRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::MessageRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::MessageRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::OutputMessage" among "WSML::OutputMessage"s
//********************************************************************************
std::set<WSML::OutputMessage> WSML::OperationImpl::getOutputMessage()
{
	std::set<WSML::OutputMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::OutputMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::OutputMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::NotificationOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::NotificationOperation
	bool rv = pVisitor->visitNotificationOperation( WSML::NotificationOperation( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::Output" among "WSML::Output"s
//********************************************************************************
std::set<WSML::Output> WSML::NotificationOperationImpl::getOutput()
{
	std::set<WSML::Output> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Output");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Output elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::OneWayOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::OneWayOperation
	bool rv = pVisitor->visitOneWayOperation( WSML::OneWayOperation( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::Input" among "WSML::Input"s
//********************************************************************************
std::set<WSML::Input> WSML::OneWayOperationImpl::getInput()
{
	std::set<WSML::Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::RequestResponseOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::RequestResponseOperation
	bool rv = pVisitor->visitRequestResponseOperation( WSML::RequestResponseOperation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::RequestResponseOperationImpl::getparameterOrder()
{
	return FCOImpl::getAttribute("parameterOrder")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::RequestResponseOperationImpl::setparameterOrder( const std::string& val)
{
	FCOImpl::getAttribute("parameterOrder")->setStringValue( val);
}


//********************************************************************************
// getter for role "WSML::Fault" among "WSML::Fault"s
//********************************************************************************
std::set<WSML::Fault> WSML::RequestResponseOperationImpl::getFault()
{
	std::set<WSML::Fault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Fault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Fault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Input" among "WSML::Input"s
//********************************************************************************
std::set<WSML::Input> WSML::RequestResponseOperationImpl::getInput()
{
	std::set<WSML::Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Output" among "WSML::Output"s
//********************************************************************************
std::set<WSML::Output> WSML::RequestResponseOperationImpl::getOutput()
{
	std::set<WSML::Output> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Output");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Output elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SolicitResponseOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SolicitResponseOperation
	bool rv = pVisitor->visitSolicitResponseOperation( WSML::SolicitResponseOperation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SolicitResponseOperationImpl::getparameterOrder()
{
	return FCOImpl::getAttribute("parameterOrder")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::SolicitResponseOperationImpl::setparameterOrder( const std::string& val)
{
	FCOImpl::getAttribute("parameterOrder")->setStringValue( val);
}


//********************************************************************************
// getter for role "WSML::Fault" among "WSML::Fault"s
//********************************************************************************
std::set<WSML::Fault> WSML::SolicitResponseOperationImpl::getFault()
{
	std::set<WSML::Fault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Fault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Fault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Input" among "WSML::Input"s
//********************************************************************************
std::set<WSML::Input> WSML::SolicitResponseOperationImpl::getInput()
{
	std::set<WSML::Input> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Input");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Input elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Output" among "WSML::Output"s
//********************************************************************************
std::set<WSML::Output> WSML::SolicitResponseOperationImpl::getOutput()
{
	std::set<WSML::Output> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Output");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Output elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentLibImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentLib
	bool rv = pVisitor->visitComponentLib( PICML::ComponentLib( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ExternalResourcess
//********************************************************************************
std::multiset<PICML::ExternalResources> PICML::ComponentLibImpl::getExtResourceConnDsts()
{
	std::multiset<PICML::ExternalResources> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ExtResourceConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ExternalResources dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ExtResourceConn> PICML::ComponentLibImpl::getOutExtResourceConnLinks()
{
	std::set<PICML::ExtResourceConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ExtResourceConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentLibImpl::getORBServices()
{
	return FCOImpl::getAttribute("ORBServices")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentLibImpl::getlibraryexport()
{
	return FCOImpl::getAttribute("libraryexport")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentLibImpl::getsharedname()
{
	return FCOImpl::getAttribute("sharedname")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentLibImpl::setORBServices( const std::string& val)
{
	FCOImpl::getAttribute("ORBServices")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentLibImpl::setlibraryexport( const std::string& val)
{
	FCOImpl::getAttribute("libraryexport")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentLibImpl::setsharedname( const std::string& val)
{
	FCOImpl::getAttribute("sharedname")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ExecutorProjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ExecutorProject
	bool rv = pVisitor->visitExecutorProject( PICML::ExecutorProject( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ImplementationArtifactReference" among "PICML::ImplementationArtifactReference"s
//********************************************************************************
std::set<PICML::ImplementationArtifactReference> PICML::ExecutorProjectImpl::getImplementationArtifactReference()
{
	std::set<PICML::ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ServantProjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ServantProject
	bool rv = pVisitor->visitServantProject( PICML::ServantProject( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::FileRef" among "PICML::FileRef"s
//********************************************************************************
std::set<PICML::FileRef> PICML::ServantProjectImpl::getFileRef()
{
	std::set<PICML::FileRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FileRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FileRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationArtifactReference" among "PICML::ImplementationArtifactReference"s
//********************************************************************************
std::set<PICML::ImplementationArtifactReference> PICML::ServantProjectImpl::getImplementationArtifactReference()
{
	std::set<PICML::ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::StubProjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::StubProject
	bool rv = pVisitor->visitStubProject( PICML::StubProject( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::FileRef" among "PICML::FileRef"s
//********************************************************************************
std::set<PICML::FileRef> PICML::StubProjectImpl::getFileRef()
{
	std::set<PICML::FileRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FileRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FileRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationArtifactReference" among "PICML::ImplementationArtifactReference"s
//********************************************************************************
std::set<PICML::ImplementationArtifactReference> PICML::StubProjectImpl::getImplementationArtifactReference()
{
	std::set<PICML::ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECRoleImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ECRole
	bool rv = pVisitor->visitECRole( PICML::ECRole( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECRoleImpl::isConfigureRTQoS()
{
	return FCOImpl::getAttribute("ConfigureRTQoS")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECRoleImpl::setConfigureRTQoS( bool val)
{
	FCOImpl::getAttribute("ConfigureRTQoS")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECConsumerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ECConsumer
	bool rv = pVisitor->visitECConsumer( PICML::ECConsumer( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ECBehaviors
//********************************************************************************
std::multiset<PICML::ECBehavior> PICML::ECConsumerImpl::getConsumer2BehaviorConnectionDsts()
{
	std::multiset<PICML::ECBehavior> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Consumer2BehaviorConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ECBehavior dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Consumer2BehaviorConnection> PICML::ECConsumerImpl::getOutConsumer2BehaviorConnectionLinks()
{
	std::set<PICML::Consumer2BehaviorConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Consumer2BehaviorConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "PICML::ECBehavior" among "PICML::ECBehavior"s
//********************************************************************************
std::set<PICML::ECBehavior> PICML::ECConsumerImpl::getECBehavior()
{
	std::set<PICML::ECBehavior> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ECBehavior");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ECBehavior elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ECEventFilterConfiguration" among "PICML::ECEventFilterConfiguration"s
//********************************************************************************
std::set<PICML::ECEventFilterConfiguration> PICML::ECConsumerImpl::getECEventFilterConfiguration()
{
	std::set<PICML::ECEventFilterConfiguration> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ECEventFilterConfiguration");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ECEventFilterConfiguration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RecursiveFilterConnection" among "PICML::RecursiveFilterConnection"s
//********************************************************************************
std::set<PICML::RecursiveFilterConnection> PICML::ECConsumerImpl::getRecursiveFilterConnection()
{
	std::set<PICML::RecursiveFilterConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RecursiveFilterConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RecursiveFilterConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECSupplierImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ECSupplier
	bool rv = pVisitor->visitECSupplier( PICML::ECSupplier( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Supplier2FilterConnection> PICML::ECSupplierImpl::getOutSupplier2FilterConnectionLinks()
{
	std::set<PICML::Supplier2FilterConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Supplier2FilterConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::ECEventFilterConfigurations
//********************************************************************************
std::multiset<PICML::ECEventFilterConfiguration> PICML::ECSupplierImpl::getSupplier2FilterConnectionDsts()
{
	std::multiset<PICML::ECEventFilterConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Supplier2FilterConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ECEventFilterConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Supplier2FilterConnection" among "PICML::Supplier2FilterConnection"s
//********************************************************************************
std::set<PICML::Supplier2FilterConnection> PICML::ECSupplierImpl::getSupplier2FilterConnection()
{
	std::set<PICML::Supplier2FilterConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Supplier2FilterConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Supplier2FilterConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MetricsBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MetricsBase
	bool rv = pVisitor->visitMetricsBase( PICML::MetricsBase( this));
	return rv;
}


//********************************************************************************
// returns src PICML::BenchmarkTypes
//********************************************************************************
std::multiset<PICML::BenchmarkType> PICML::MetricsBaseImpl::getBenchmarkCharacteristicsSrcs()
{
	std::multiset<PICML::BenchmarkType> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BenchmarkCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::BenchmarkType dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::BenchmarkCharacteristics> PICML::MetricsBaseImpl::getInBenchmarkCharacteristicsLinks()
{
	std::set<PICML::BenchmarkCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::BenchmarkCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MetricConnection> PICML::MetricsBaseImpl::getInMetricConnectionLinks()
{
	std::set<PICML::MetricConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MetricConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::OperationRefs
//********************************************************************************
std::multiset<PICML::OperationRef> PICML::MetricsBaseImpl::getMetricConnectionSrcs()
{
	std::multiset<PICML::OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MetricConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::WorkloadCharacteristics> PICML::MetricsBaseImpl::getOutWorkloadCharacteristicsLinks()
{
	std::set<PICML::WorkloadCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::WorkloadCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::TaskSets
//********************************************************************************
std::multiset<PICML::TaskSet> PICML::MetricsBaseImpl::getWorkloadCharacteristicsDsts()
{
	std::multiset<PICML::TaskSet> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("WorkloadCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::TaskSet dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::MetricsBaseImpl::getfileName()
{
	return FCOImpl::getAttribute("fileName")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
long PICML::MetricsBaseImpl::getiterations()
{
	return FCOImpl::getAttribute("iterations")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
long PICML::MetricsBaseImpl::getpriority()
{
	return FCOImpl::getAttribute("priority")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
long PICML::MetricsBaseImpl::getrate()
{
	return FCOImpl::getAttribute("rate")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
PICML::MetricsBaseImpl::resolution_Type PICML::MetricsBaseImpl::getresolution()
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
long PICML::MetricsBaseImpl::getwarmup()
{
	return FCOImpl::getAttribute("warmup")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::MetricsBaseImpl::setfileName( const std::string& val)
{
	FCOImpl::getAttribute("fileName")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::MetricsBaseImpl::setiterations( const long val)
{
	FCOImpl::getAttribute("iterations")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::MetricsBaseImpl::setpriority( const long val)
{
	FCOImpl::getAttribute("priority")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::MetricsBaseImpl::setrate( const long val)
{
	FCOImpl::getAttribute("rate")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::MetricsBaseImpl::setresolution( MetricsBaseImpl::resolution_Type val)
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
void PICML::MetricsBaseImpl::setwarmup( const long val)
{
	FCOImpl::getAttribute("warmup")->setIntegerValue( val);
}


//********************************************************************************
// getter for role "PICML::Average" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Average> PICML::MetricsBaseImpl::getAverage()
{
	std::set<PICML::Average> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Average");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Average elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::DataAnalysisBase> PICML::MetricsBaseImpl::getDataAnalysisBase()
{
	std::set<PICML::DataAnalysisBase> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Average");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::Jitter");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::Maximum");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::Minimum");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::DataAnalysisBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::Jitter" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Jitter> PICML::MetricsBaseImpl::getJitter()
{
	std::set<PICML::Jitter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Jitter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Jitter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Maximum" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Maximum> PICML::MetricsBaseImpl::getMaximum()
{
	std::set<PICML::Maximum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Maximum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Maximum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Minimum" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Minimum> PICML::MetricsBaseImpl::getMinimum()
{
	std::set<PICML::Minimum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Minimum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Minimum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::LatencyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Latency
	bool rv = pVisitor->visitLatency( PICML::Latency( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ThroughputImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Throughput
	bool rv = pVisitor->visitThroughput( PICML::Throughput( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerPackageBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkerPackageBase
	bool rv = pVisitor->visitWorkerPackageBase( PICML::WorkerPackageBase( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Worker" among "PICML::Worker"s
//********************************************************************************
std::set<PICML::Worker> PICML::WorkerPackageBaseImpl::getWorker()
{
	std::set<PICML::Worker> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Worker");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Worker elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerFileImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkerFile
	bool rv = pVisitor->visitWorkerFile( PICML::WorkerFile( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::WorkerFileImpl::getLocation()
{
	return FCOImpl::getAttribute("Location")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::WorkerFileImpl::setLocation( const std::string& val)
{
	FCOImpl::getAttribute("Location")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::WorkerPackage" among "PICML::WorkerPackage"s
//********************************************************************************
std::set<PICML::WorkerPackage> PICML::WorkerFileImpl::getWorkerPackage()
{
	std::set<PICML::WorkerPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::WorkerPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::WorkerPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerPackageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkerPackage
	bool rv = pVisitor->visitWorkerPackage( PICML::WorkerPackage( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::WorkerPackage" among "PICML::WorkerPackage"s
//********************************************************************************
std::set<PICML::WorkerPackage> PICML::WorkerPackageImpl::getWorkerPackage()
{
	std::set<PICML::WorkerPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::WorkerPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::WorkerPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SchemaReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SchemaReference
	bool rv = pVisitor->visitSchemaReference( WSML::SchemaReference( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SchemaReferenceImpl::getid()
{
	return FCOImpl::getAttribute("id")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SchemaReferenceImpl::getschemaLocation()
{
	return FCOImpl::getAttribute("schemaLocation")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::SchemaReferenceImpl::setid( const std::string& val)
{
	FCOImpl::getAttribute("id")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void WSML::SchemaReferenceImpl::setschemaLocation( const std::string& val)
{
	FCOImpl::getAttribute("schemaLocation")->setStringValue( val);
}


//********************************************************************************
// getter for role "WSML::Schema" among "WSML::Schema"s
//********************************************************************************
std::set<WSML::Schema> WSML::SchemaReferenceImpl::getSchema()
{
	std::set<WSML::Schema> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Schema");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Schema elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SchemaImportImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SchemaImport
	bool rv = pVisitor->visitSchemaImport( WSML::SchemaImport( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SchemaImportImpl::getnamespace()
{
	return FCOImpl::getAttribute("namespace")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::SchemaImportImpl::setnamespace( const std::string& val)
{
	FCOImpl::getAttribute("namespace")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentImplementationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentImplementation
	bool rv = pVisitor->visitComponentImplementation( PICML::ComponentImplementation( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ComponentImplementationImpl::getConfigPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Capabilitys
//********************************************************************************
std::multiset<PICML::Capability> PICML::ComponentImplementationImpl::getImplementationCapabilityDsts()
{
	std::multiset<PICML::Capability> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ImplementationCapability");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Capability dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ImplementationDependencys
//********************************************************************************
std::multiset<PICML::ImplementationDependency> PICML::ComponentImplementationImpl::getImplementationDependsOnDsts()
{
	std::multiset<PICML::ImplementationDependency> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ImplementationDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ImplementationDependency dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ComponentRefs
//********************************************************************************
std::multiset<PICML::ComponentRef> PICML::ComponentImplementationImpl::getImplementsDsts()
{
	std::multiset<PICML::ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Implements");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ComponentImplementationImpl::getInfoPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("InfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ConfigProperty> PICML::ComponentImplementationImpl::getOutConfigPropertyLinks()
{
	std::set<PICML::ConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ImplementationCapability> PICML::ComponentImplementationImpl::getOutImplementationCapabilityLinks()
{
	std::set<PICML::ImplementationCapability> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ImplementationCapability c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ImplementationDependsOn> PICML::ComponentImplementationImpl::getOutImplementationDependsOnLinks()
{
	std::set<PICML::ImplementationDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ImplementationDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Implements> PICML::ComponentImplementationImpl::getOutImplementsLinks()
{
	std::set<PICML::Implements> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Implements c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::InfoProperty> PICML::ComponentImplementationImpl::getOutInfoPropertyLinks()
{
	std::set<PICML::InfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::InfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentImplementationImpl::getUUID()
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentImplementationImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentImplementationImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentImplementationImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentAssemblyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentAssembly
	bool rv = pVisitor->visitComponentAssembly( PICML::ComponentAssembly( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::PathReferences
//********************************************************************************
std::multiset<PICML::PathReference> PICML::ComponentAssemblyImpl::getCriticalPathDsts()
{
	std::multiset<PICML::PathReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("CriticalPath");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::PathReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::CriticalPath> PICML::ComponentAssemblyImpl::getOutCriticalPathLinks()
{
	std::set<PICML::CriticalPath> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::CriticalPath c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "PICML::AssemblyConfigProperty" among "PICML::AssemblyConfigProperty"s
//********************************************************************************
std::set<PICML::AssemblyConfigProperty> PICML::ComponentAssemblyImpl::getAssemblyConfigProperty()
{
	std::set<PICML::AssemblyConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AssemblyConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AssemblyConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::AssemblyDeployRequirement" among "PICML::AssemblyDeployRequirement"s
//********************************************************************************
std::set<PICML::AssemblyDeployRequirement> PICML::ComponentAssemblyImpl::getAssemblyDeployRequirement()
{
	std::set<PICML::AssemblyDeployRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AssemblyDeployRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AssemblyDeployRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::AssemblyselectRequirement" among "PICML::AssemblyselectRequirement"s
//********************************************************************************
std::set<PICML::AssemblyselectRequirement> PICML::ComponentAssemblyImpl::getAssemblyselectRequirement()
{
	std::set<PICML::AssemblyselectRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AssemblyselectRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AssemblyselectRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::AttributeDelegate" among "PICML::AttributeDelegate"s
//********************************************************************************
std::set<PICML::AttributeDelegate> PICML::ComponentAssemblyImpl::getAttributeDelegate()
{
	std::set<PICML::AttributeDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AttributeDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AttributeDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::AttributeMapping" among "PICML::AttributeMapping"s
//********************************************************************************
std::set<PICML::AttributeMapping> PICML::ComponentAssemblyImpl::getAttributeMapping()
{
	std::set<PICML::AttributeMapping> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AttributeMapping");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AttributeMapping elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::AttributeMappingDelegate" among "PICML::AttributeMappingDelegate"s
//********************************************************************************
std::set<PICML::AttributeMappingDelegate> PICML::ComponentAssemblyImpl::getAttributeMappingDelegate()
{
	std::set<PICML::AttributeMappingDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AttributeMappingDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AttributeMappingDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::AttributeMappingValue" among "PICML::AttributeMappingValue"s
//********************************************************************************
std::set<PICML::AttributeMappingValue> PICML::ComponentAssemblyImpl::getAttributeMappingValue()
{
	std::set<PICML::AttributeMappingValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AttributeMappingValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AttributeMappingValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::AttributeValue" among "PICML::AttributeValue"s
//********************************************************************************
std::set<PICML::AttributeValue> PICML::ComponentAssemblyImpl::getAttributeValue()
{
	std::set<PICML::AttributeValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::AttributeValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::AttributeValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Component" among "PICML::Component"s
//********************************************************************************
std::set<PICML::Component> PICML::ComponentAssemblyImpl::getComponent()
{
	std::set<PICML::Component> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Component");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Component elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentAssembly" among "PICML::ComponentAssembly"s
//********************************************************************************
std::set<PICML::ComponentAssembly> PICML::ComponentAssemblyImpl::getComponentAssembly()
{
	std::set<PICML::ComponentAssembly> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentAssembly");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentAssembly elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentAssemblyReference" among "PICML::ComponentAssemblyReference"s
//********************************************************************************
std::set<PICML::ComponentAssemblyReference> PICML::ComponentAssemblyImpl::getComponentAssemblyReference()
{
	std::set<PICML::ComponentAssemblyReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentAssemblyReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentAssemblyReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentPackage" among "PICML::ComponentPackage"s
//********************************************************************************
std::set<PICML::ComponentPackage> PICML::ComponentAssemblyImpl::getComponentPackage()
{
	std::set<PICML::ComponentPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentPackageReference" among "PICML::ComponentPackageReference"s
//********************************************************************************
std::set<PICML::ComponentPackageReference> PICML::ComponentAssemblyImpl::getComponentPackageReference()
{
	std::set<PICML::ComponentPackageReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentPackageReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentPackageReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::ComponentAssemblyImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ECConfiguration" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::ECConfiguration> PICML::ComponentAssemblyImpl::getECConfiguration()
{
	std::set<PICML::ECConfiguration> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ECConfiguration");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ECConfiguration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::EventSinkDelegate" among "PICML::EventSinkDelegate"s
//********************************************************************************
std::set<PICML::EventSinkDelegate> PICML::ComponentAssemblyImpl::getEventSinkDelegate()
{
	std::set<PICML::EventSinkDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::EventSinkDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::EventSinkDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::EventSourceDelegate" among "PICML::EventSourceDelegate"s
//********************************************************************************
std::set<PICML::EventSourceDelegate> PICML::ComponentAssemblyImpl::getEventSourceDelegate()
{
	std::set<PICML::EventSourceDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::EventSourceDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::EventSourceDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ExternalDelegate" among "PICML::ExternalDelegate"s
//********************************************************************************
std::set<PICML::ExternalDelegate> PICML::ComponentAssemblyImpl::getExternalDelegate()
{
	std::set<PICML::ExternalDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ExternalDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ExternalDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ExternalReferenceEndPoint" among "PICML::ExternalReferenceEndPoint"s
//********************************************************************************
std::set<PICML::ExternalReferenceEndPoint> PICML::ComponentAssemblyImpl::getExternalReferenceEndPoint()
{
	std::set<PICML::ExternalReferenceEndPoint> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ExternalReferenceEndPoint");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ExternalReferenceEndPoint elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::FacetDelegate" among "PICML::FacetDelegate"s
//********************************************************************************
std::set<PICML::FacetDelegate> PICML::ComponentAssemblyImpl::getFacetDelegate()
{
	std::set<PICML::FacetDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FacetDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FacetDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::InEventPort" among "PICML::InEventPort"s
//********************************************************************************
std::set<PICML::InEventPort> PICML::ComponentAssemblyImpl::getInEventPort()
{
	std::set<PICML::InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::OutEventPort" among "PICML::OutEventPort"s
//********************************************************************************
std::set<PICML::OutEventPort> PICML::ComponentAssemblyImpl::getOutEventPort()
{
	std::set<PICML::OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::ComponentAssemblyImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ProvidedRequestPort" among "PICML::ProvidedRequestPort"s
//********************************************************************************
std::set<PICML::ProvidedRequestPort> PICML::ComponentAssemblyImpl::getProvidedRequestPort()
{
	std::set<PICML::ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PublishConnector" among "PICML::PublishConnector"s
//********************************************************************************
std::set<PICML::PublishConnector> PICML::ComponentAssemblyImpl::getPublishConnector()
{
	std::set<PICML::PublishConnector> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PublishConnector");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PublishConnector elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RTRequirements" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::RTRequirements> PICML::ComponentAssemblyImpl::getRTRequirements()
{
	std::set<PICML::RTRequirements> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RTRequirements");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RTRequirements elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ReceptacleDelegate" among "PICML::ReceptacleDelegate"s
//********************************************************************************
std::set<PICML::ReceptacleDelegate> PICML::ComponentAssemblyImpl::getReceptacleDelegate()
{
	std::set<PICML::ReceptacleDelegate> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ReceptacleDelegate");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ReceptacleDelegate elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RequiredRequestPort" among "PICML::RequiredRequestPort"s
//********************************************************************************
std::set<PICML::RequiredRequestPort> PICML::ComponentAssemblyImpl::getRequiredRequestPort()
{
	std::set<PICML::RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Requirement" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::Requirement> PICML::ComponentAssemblyImpl::getRequirement()
{
	std::set<PICML::Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::Requirement> PICML::ComponentAssemblyImpl::getRequirement(int dummy)
{
	std::set<PICML::Requirement> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::ECConfiguration");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::RTRequirements");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::Requirement");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::deliverTo" among "PICML::deliverTo"s
//********************************************************************************
std::set<PICML::deliverTo> PICML::ComponentAssemblyImpl::getdeliverTo()
{
	std::set<PICML::deliverTo> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::deliverTo");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::deliverTo elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::emit" among "PICML::emit"s
//********************************************************************************
std::set<PICML::emit> PICML::ComponentAssemblyImpl::getemit()
{
	std::set<PICML::emit> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::emit");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::emit elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::invoke" among "PICML::invoke"s
//********************************************************************************
std::set<PICML::invoke> PICML::ComponentAssemblyImpl::getinvoke()
{
	std::set<PICML::invoke> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::invoke");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::invoke elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::publish" among "PICML::publish"s
//********************************************************************************
std::set<PICML::publish> PICML::ComponentAssemblyImpl::getpublish()
{
	std::set<PICML::publish> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::publish");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::publish elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MonolithicImplementationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MonolithicImplementation
	bool rv = pVisitor->visitMonolithicImplementation( PICML::MonolithicImplementation( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ImplementationRequirements
//********************************************************************************
std::multiset<PICML::ImplementationRequirement> PICML::MonolithicImplementationImpl::getMonolithDeployRequirementDsts()
{
	std::multiset<PICML::ImplementationRequirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MonolithDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ImplementationRequirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::MonolithicImplementationImpl::getMonolithExecParameterDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MonolithExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ImplementationArtifactReferences
//********************************************************************************
std::multiset<PICML::ImplementationArtifactReference> PICML::MonolithicImplementationImpl::getMonolithprimaryArtifactDsts()
{
	std::multiset<PICML::ImplementationArtifactReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MonolithprimaryArtifact");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifactReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MonolithDeployRequirement> PICML::MonolithicImplementationImpl::getOutMonolithDeployRequirementLinks()
{
	std::set<PICML::MonolithDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MonolithDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MonolithExecParameter> PICML::MonolithicImplementationImpl::getOutMonolithExecParameterLinks()
{
	std::set<PICML::MonolithExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MonolithExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MonolithprimaryArtifact> PICML::MonolithicImplementationImpl::getOutMonolithprimaryArtifactLinks()
{
	std::set<PICML::MonolithprimaryArtifact> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MonolithprimaryArtifact c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::MonolithicImplementationImpl::getdefaultVersion()
{
	return FCOImpl::getAttribute("defaultVersion")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::MonolithicImplementationImpl::setdefaultVersion( const std::string& val)
{
	FCOImpl::getAttribute("defaultVersion")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ExtensibilityElementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::ExtensibilityElement
	bool rv = pVisitor->visitExtensibilityElement( WSML::ExtensibilityElement( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ExtensibilityElementImpl::isrequired()
{
	return FCOImpl::getAttribute("required")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::ExtensibilityElementImpl::setrequired( bool val)
{
	FCOImpl::getAttribute("required")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ExtensibleBindingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::ExtensibleBinding
	bool rv = pVisitor->visitExtensibleBinding( WSML::ExtensibleBinding( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ExtensibleMessageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::ExtensibleMessage
	bool rv = pVisitor->visitExtensibleMessage( WSML::ExtensibleMessage( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::ExtensibleMessageImpl::getencodingStyle()
{
	return FCOImpl::getAttribute("encodingStyle")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::ExtensibleMessageImpl::getnamespace()
{
	return FCOImpl::getAttribute("namespace")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
WSML::ExtensibleMessageImpl::use_Type WSML::ExtensibleMessageImpl::getuse()
{
	std::string val = FCOImpl::getAttribute("use")->getStringValue();

	if ( val == "literal") return literal_use_Type;
	else if ( val == "encoded") return encoded_use_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void WSML::ExtensibleMessageImpl::setencodingStyle( const std::string& val)
{
	FCOImpl::getAttribute("encodingStyle")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void WSML::ExtensibleMessageImpl::setnamespace( const std::string& val)
{
	FCOImpl::getAttribute("namespace")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void WSML::ExtensibleMessageImpl::setuse( ExtensibleMessageImpl::use_Type val)
{
	std::string str_val = "";

	if ( val == literal_use_Type) str_val = "literal";
	else if ( val == encoded_use_Type) str_val = "encoded";
	else throw("None of the possible items");

	FCOImpl::getAttribute("use")->setStringValue( str_val);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ExtensibleOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::ExtensibleOperation
	bool rv = pVisitor->visitExtensibleOperation( WSML::ExtensibleOperation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ExtensiblePortImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::ExtensiblePort
	bool rv = pVisitor->visitExtensiblePort( WSML::ExtensiblePort( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPHeadersImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPHeaders
	bool rv = pVisitor->visitSOAPHeaders( WSML::SOAPHeaders( this));
	return rv;
}


//********************************************************************************
// returns src WSML::IORefs
//********************************************************************************
std::multiset<WSML::IORef> WSML::SOAPHeadersImpl::getHeaderBindingSrcs()
{
	std::multiset<WSML::IORef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("HeaderBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::IORef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst WSML::MessageRefs
//********************************************************************************
std::multiset<WSML::MessageRef> WSML::SOAPHeadersImpl::getHeaderMessageDsts()
{
	std::multiset<WSML::MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("HeaderMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst WSML::PartRefs
//********************************************************************************
std::multiset<WSML::PartRef> WSML::SOAPHeadersImpl::getHeaderPartDsts()
{
	std::multiset<WSML::PartRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("HeaderPart");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::PartRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::HeaderBinding> WSML::SOAPHeadersImpl::getInHeaderBindingLinks()
{
	std::set<WSML::HeaderBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::HeaderBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::HeaderMessage> WSML::SOAPHeadersImpl::getOutHeaderMessageLinks()
{
	std::set<WSML::HeaderMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::HeaderMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::HeaderPart> WSML::SOAPHeadersImpl::getOutHeaderPartLinks()
{
	std::set<WSML::HeaderPart> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::HeaderPart c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPAddressImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPAddress
	bool rv = pVisitor->visitSOAPAddress( WSML::SOAPAddress( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SOAPAddressImpl::getlocation()
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::SOAPAddressImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPBindingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPBinding
	bool rv = pVisitor->visitSOAPBinding( WSML::SOAPBinding( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
WSML::SOAPBindingImpl::style_Type WSML::SOAPBindingImpl::getstyle()
{
	std::string val = FCOImpl::getAttribute("style")->getStringValue();

	if ( val == "document") return document_style_Type;
	else if ( val == "rpc") return rpc_style_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SOAPBindingImpl::gettransport()
{
	return FCOImpl::getAttribute("transport")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::SOAPBindingImpl::setstyle( SOAPBindingImpl::style_Type val)
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
void WSML::SOAPBindingImpl::settransport( const std::string& val)
{
	FCOImpl::getAttribute("transport")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPBodyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPBody
	bool rv = pVisitor->visitSOAPBody( WSML::SOAPBody( this));
	return rv;
}


//********************************************************************************
// returns src WSML::IORefs
//********************************************************************************
std::multiset<WSML::IORef> WSML::SOAPBodyImpl::getBodyBindingSrcs()
{
	std::multiset<WSML::IORef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BodyBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::IORef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst WSML::PartRefs
//********************************************************************************
std::multiset<WSML::PartRef> WSML::SOAPBodyImpl::getBodyPartsDsts()
{
	std::multiset<WSML::PartRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BodyParts");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::PartRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BodyBinding> WSML::SOAPBodyImpl::getInBodyBindingLinks()
{
	std::set<WSML::BodyBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BodyBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BodyParts> WSML::SOAPBodyImpl::getOutBodyPartsLinks()
{
	std::set<WSML::BodyParts> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BodyParts c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPFaultImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPFault
	bool rv = pVisitor->visitSOAPFault( WSML::SOAPFault( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::SOAPFaultExtension> WSML::SOAPFaultImpl::getInSOAPFaultExtensionLinks()
{
	std::set<WSML::SOAPFaultExtension> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::SOAPFaultExtension c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src WSML::FaultRefs
//********************************************************************************
std::multiset<WSML::FaultRef> WSML::SOAPFaultImpl::getSOAPFaultExtensionSrcs()
{
	std::multiset<WSML::FaultRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("SOAPFaultExtension");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::FaultRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPOperation
	bool rv = pVisitor->visitSOAPOperation( WSML::SOAPOperation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SOAPOperationImpl::getsoapAction()
{
	return FCOImpl::getAttribute("soapAction")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
WSML::SOAPOperationImpl::style_Type WSML::SOAPOperationImpl::getstyle()
{
	std::string val = FCOImpl::getAttribute("style")->getStringValue();

	if ( val == "document") return document_style_Type;
	else if ( val == "rpc") return rpc_style_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void WSML::SOAPOperationImpl::setsoapAction( const std::string& val)
{
	FCOImpl::getAttribute("soapAction")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void WSML::SOAPOperationImpl::setstyle( SOAPOperationImpl::style_Type val)
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
bool WSML::SOAPHeaderImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPHeader
	bool rv = pVisitor->visitSOAPHeader( WSML::SOAPHeader( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::SOAPHeaderFault" among "WSML::SOAPHeaderFault"s
//********************************************************************************
std::set<WSML::SOAPHeaderFault> WSML::SOAPHeaderImpl::getSOAPHeaderFault()
{
	std::set<WSML::SOAPHeaderFault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPHeaderFault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPHeaderFault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPHeaderFaultImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPHeaderFault
	bool rv = pVisitor->visitSOAPHeaderFault( WSML::SOAPHeaderFault( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ReferrableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Referrable
	bool rv = pVisitor->visitReferrable( WSML::Referrable( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ElementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Element
	bool rv = pVisitor->visitElement( WSML::Element( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
long WSML::ElementImpl::getOrder()
{
	return FCOImpl::getAttribute("Order")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
WSML::ElementImpl::schemaType_Type WSML::ElementImpl::getschemaType()
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
void WSML::ElementImpl::setOrder( const long val)
{
	FCOImpl::getAttribute("Order")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void WSML::ElementImpl::setschemaType( ElementImpl::schemaType_Type val)
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
// getter for role "WSML::Attribute" among "WSML::Attribute"s
//********************************************************************************
std::set<WSML::Attribute> WSML::ElementImpl::getAttribute()
{
	std::set<WSML::Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Element" among "WSML::Element"s
//********************************************************************************
std::set<WSML::Element> WSML::ElementImpl::getElement()
{
	std::set<WSML::Element> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Element");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Element elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::AtomicTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::AtomicType
	bool rv = pVisitor->visitAtomicType( WSML::AtomicType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
WSML::AtomicTypeImpl::typeCode_Type WSML::AtomicTypeImpl::gettypeCode()
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
void WSML::AtomicTypeImpl::settypeCode( AtomicTypeImpl::typeCode_Type val)
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
//
//********************************************************************************
bool PICML::ArtifactContainerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ArtifactContainer
	bool rv = pVisitor->visitArtifactContainer( PICML::ArtifactContainer( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ArtifactDependency" among "PICML::ArtifactDependency"s
//********************************************************************************
std::set<PICML::ArtifactDependency> PICML::ArtifactContainerImpl::getArtifactDependency()
{
	std::set<PICML::ArtifactDependency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ArtifactDependency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ArtifactDependency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ArtifactDependsOn" among "PICML::ArtifactDependsOn"s
//********************************************************************************
std::set<PICML::ArtifactDependsOn> PICML::ArtifactContainerImpl::getArtifactDependsOn()
{
	std::set<PICML::ArtifactDependsOn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ArtifactDependsOn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ArtifactDependsOn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ArtifactDeployRequirement" among "PICML::ArtifactDeployRequirement"s
//********************************************************************************
std::set<PICML::ArtifactDeployRequirement> PICML::ArtifactContainerImpl::getArtifactDeployRequirement()
{
	std::set<PICML::ArtifactDeployRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ArtifactDeployRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ArtifactDeployRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ArtifactExecParameter" among "PICML::ArtifactExecParameter"s
//********************************************************************************
std::set<PICML::ArtifactExecParameter> PICML::ArtifactContainerImpl::getArtifactExecParameter()
{
	std::set<PICML::ArtifactExecParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ArtifactExecParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ArtifactExecParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ArtifactInfoProperty" among "PICML::ArtifactInfoProperty"s
//********************************************************************************
std::set<PICML::ArtifactInfoProperty> PICML::ArtifactContainerImpl::getArtifactInfoProperty()
{
	std::set<PICML::ArtifactInfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ArtifactInfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ArtifactInfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ECConfiguration" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::ECConfiguration> PICML::ArtifactContainerImpl::getECConfiguration()
{
	std::set<PICML::ECConfiguration> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ECConfiguration");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ECConfiguration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationArtifact" among "PICML::ImplementationArtifact"s
//********************************************************************************
std::set<PICML::ImplementationArtifact> PICML::ArtifactContainerImpl::getImplementationArtifact()
{
	std::set<PICML::ImplementationArtifact> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationArtifact");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationArtifact elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationArtifactReference" among "PICML::ImplementationArtifactReference"s
//********************************************************************************
std::set<PICML::ImplementationArtifactReference> PICML::ArtifactContainerImpl::getImplementationArtifactReference()
{
	std::set<PICML::ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::ArtifactContainerImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RTRequirements" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::RTRequirements> PICML::ArtifactContainerImpl::getRTRequirements()
{
	std::set<PICML::RTRequirements> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RTRequirements");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RTRequirements elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Requirement" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::Requirement> PICML::ArtifactContainerImpl::getRequirement()
{
	std::set<PICML::Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::Requirement> PICML::ArtifactContainerImpl::getRequirement(int dummy)
{
	std::set<PICML::Requirement> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::ECConfiguration");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::RTRequirements");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::Requirement");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BenchmarkAnalysisImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::BenchmarkAnalysis
	bool rv = pVisitor->visitBenchmarkAnalysis( PICML::BenchmarkAnalysis( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Average" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Average> PICML::BenchmarkAnalysisImpl::getAverage()
{
	std::set<PICML::Average> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Average");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Average elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::BenchmarkCharacteristics" among "PICML::BenchmarkCharacteristics"s
//********************************************************************************
std::set<PICML::BenchmarkCharacteristics> PICML::BenchmarkAnalysisImpl::getBenchmarkCharacteristics()
{
	std::set<PICML::BenchmarkCharacteristics> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::BenchmarkCharacteristics");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::BenchmarkCharacteristics elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::BenchmarkType"s and its descendants
//********************************************************************************
std::set<PICML::BenchmarkType> PICML::BenchmarkAnalysisImpl::getBenchmarkType()
{
	std::set<PICML::BenchmarkType> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::FixedIterationBenchmarks");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::PeriodicBenchmarks");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::TriggerBenchmarks");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::BenchmarkType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::CompRef" among "PICML::CompRef"s
//********************************************************************************
std::set<PICML::CompRef> PICML::BenchmarkAnalysisImpl::getCompRef()
{
	std::set<PICML::CompRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::CompRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::CompRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentOperation" among "PICML::ComponentOperation"s
//********************************************************************************
std::set<PICML::ComponentOperation> PICML::BenchmarkAnalysisImpl::getComponentOperation()
{
	std::set<PICML::ComponentOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::DataAnalysisBase> PICML::BenchmarkAnalysisImpl::getDataAnalysisBase()
{
	std::set<PICML::DataAnalysisBase> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Average");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::Jitter");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::Maximum");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::Minimum");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::DataAnalysisBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::Event" among "PICML::Event"s
//********************************************************************************
std::set<PICML::Event> PICML::BenchmarkAnalysisImpl::getEvent()
{
	std::set<PICML::Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::EventRef" among "PICML::EventRef"s
//********************************************************************************
std::set<PICML::EventRef> PICML::BenchmarkAnalysisImpl::getEventRef()
{
	std::set<PICML::EventRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::EventRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::EventRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::FactoryOperation" among "PICML::OperationBase"s and its descendants
//********************************************************************************
std::set<PICML::FactoryOperation> PICML::BenchmarkAnalysisImpl::getFactoryOperation()
{
	std::set<PICML::FactoryOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FactoryOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FactoryOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::FixedIterationBenchmarks" among "PICML::BenchmarkType"s and its descendants
//********************************************************************************
std::set<PICML::FixedIterationBenchmarks> PICML::BenchmarkAnalysisImpl::getFixedIterationBenchmarks()
{
	std::set<PICML::FixedIterationBenchmarks> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::FixedIterationBenchmarks");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::FixedIterationBenchmarks elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Jitter" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Jitter> PICML::BenchmarkAnalysisImpl::getJitter()
{
	std::set<PICML::Jitter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Jitter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Jitter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Latency" among "PICML::MetricsBase"s and its descendants
//********************************************************************************
std::set<PICML::Latency> PICML::BenchmarkAnalysisImpl::getLatency()
{
	std::set<PICML::Latency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Latency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Latency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::LookupOperation" among "PICML::OperationBase"s and its descendants
//********************************************************************************
std::set<PICML::LookupOperation> PICML::BenchmarkAnalysisImpl::getLookupOperation()
{
	std::set<PICML::LookupOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::LookupOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::LookupOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Maximum" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Maximum> PICML::BenchmarkAnalysisImpl::getMaximum()
{
	std::set<PICML::Maximum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Maximum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Maximum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::MetricConnection" among "PICML::MetricConnection"s
//********************************************************************************
std::set<PICML::MetricConnection> PICML::BenchmarkAnalysisImpl::getMetricConnection()
{
	std::set<PICML::MetricConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MetricConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MetricConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::MetricsBase"s and its descendants
//********************************************************************************
std::set<PICML::MetricsBase> PICML::BenchmarkAnalysisImpl::getMetricsBase()
{
	std::set<PICML::MetricsBase> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Latency");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::Throughput");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::MetricsBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::Minimum" among "PICML::DataAnalysisBase"s and its descendants
//********************************************************************************
std::set<PICML::Minimum> PICML::BenchmarkAnalysisImpl::getMinimum()
{
	std::set<PICML::Minimum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Minimum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Minimum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::OnewayOperation" among "PICML::OperationBase"s and its descendants
//********************************************************************************
std::set<PICML::OnewayOperation> PICML::BenchmarkAnalysisImpl::getOnewayOperation()
{
	std::set<PICML::OnewayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OnewayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OnewayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::OperationBase"s and its descendants
//********************************************************************************
std::set<PICML::OperationBase> PICML::BenchmarkAnalysisImpl::getOperationBase()
{
	std::set<PICML::OperationBase> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::FactoryOperation");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::LookupOperation");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::OnewayOperation");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::TwowayOperation");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::OperationBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::OperationRef" among "PICML::OperationRef"s
//********************************************************************************
std::set<PICML::OperationRef> PICML::BenchmarkAnalysisImpl::getOperationRef()
{
	std::set<PICML::OperationRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OperationRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OperationRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PeriodicBenchmarks" among "PICML::BenchmarkType"s and its descendants
//********************************************************************************
std::set<PICML::PeriodicBenchmarks> PICML::BenchmarkAnalysisImpl::getPeriodicBenchmarks()
{
	std::set<PICML::PeriodicBenchmarks> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PeriodicBenchmarks");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PeriodicBenchmarks elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Task" among "PICML::Task"s
//********************************************************************************
std::set<PICML::Task> PICML::BenchmarkAnalysisImpl::getTask()
{
	std::set<PICML::Task> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Task");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Task elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TaskSet" among "PICML::TaskSet"s
//********************************************************************************
std::set<PICML::TaskSet> PICML::BenchmarkAnalysisImpl::getTaskSet()
{
	std::set<PICML::TaskSet> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TaskSet");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TaskSet elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Throughput" among "PICML::MetricsBase"s and its descendants
//********************************************************************************
std::set<PICML::Throughput> PICML::BenchmarkAnalysisImpl::getThroughput()
{
	std::set<PICML::Throughput> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Throughput");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Throughput elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TimeProbe" among "PICML::TimeProbe"s
//********************************************************************************
std::set<PICML::TimeProbe> PICML::BenchmarkAnalysisImpl::getTimeProbe()
{
	std::set<PICML::TimeProbe> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TimeProbe");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TimeProbe elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TimerConnection" among "PICML::TimerConnection"s
//********************************************************************************
std::set<PICML::TimerConnection> PICML::BenchmarkAnalysisImpl::getTimerConnection()
{
	std::set<PICML::TimerConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TimerConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TimerConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TimerEventSinkConn" among "PICML::TimerEventSinkConn"s
//********************************************************************************
std::set<PICML::TimerEventSinkConn> PICML::BenchmarkAnalysisImpl::getTimerEventSinkConn()
{
	std::set<PICML::TimerEventSinkConn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TimerEventSinkConn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TimerEventSinkConn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TriggerBenchmarks" among "PICML::BenchmarkType"s and its descendants
//********************************************************************************
std::set<PICML::TriggerBenchmarks> PICML::BenchmarkAnalysisImpl::getTriggerBenchmarks()
{
	std::set<PICML::TriggerBenchmarks> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TriggerBenchmarks");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TriggerBenchmarks elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TwowayOperation" among "PICML::OperationBase"s and its descendants
//********************************************************************************
std::set<PICML::TwowayOperation> PICML::BenchmarkAnalysisImpl::getTwowayOperation()
{
	std::set<PICML::TwowayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TwowayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TwowayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::WorkLoadOperationConnection" among "PICML::WorkLoadOperationConnection"s
//********************************************************************************
std::set<PICML::WorkLoadOperationConnection> PICML::BenchmarkAnalysisImpl::getWorkLoadOperationConnection()
{
	std::set<PICML::WorkLoadOperationConnection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::WorkLoadOperationConnection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::WorkLoadOperationConnection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::WorkloadCharacteristics" among "PICML::WorkloadCharacteristics"s
//********************************************************************************
std::set<PICML::WorkloadCharacteristics> PICML::BenchmarkAnalysisImpl::getWorkloadCharacteristics()
{
	std::set<PICML::WorkloadCharacteristics> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::WorkloadCharacteristics");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::WorkloadCharacteristics elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::BindingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Binding
	bool rv = pVisitor->visitBinding( WSML::Binding( this));
	return rv;
}


//********************************************************************************
// returns dst WSML::PortTypes
//********************************************************************************
std::multiset<WSML::PortType> WSML::BindingImpl::getBindingPortTypeDsts()
{
	std::multiset<WSML::PortType> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BindingPortType");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::PortType dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BindingPortType> WSML::BindingImpl::getOutBindingPortTypeLinks()
{
	std::set<WSML::BindingPortType> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BindingPortType c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "WSML::BindingOperation" among "WSML::BindingOperation"s
//********************************************************************************
std::set<WSML::BindingOperation> WSML::BindingImpl::getBindingOperation()
{
	std::set<WSML::BindingOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::BindingOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::BindingOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::BindsOperation" among "WSML::BindsOperation"s
//********************************************************************************
std::set<WSML::BindsOperation> WSML::BindingImpl::getBindsOperation()
{
	std::set<WSML::BindsOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::BindsOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::BindsOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::BindingImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::OperationRef" among "WSML::OperationRef"s
//********************************************************************************
std::set<WSML::OperationRef> WSML::BindingImpl::getOperationRef()
{
	std::set<WSML::OperationRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::OperationRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::OperationRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPBinding" among "WSML::ExtensibleBinding"s
//********************************************************************************
std::set<WSML::SOAPBinding> WSML::BindingImpl::getSOAPBinding()
{
	std::set<WSML::SOAPBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::BindingOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::BindingOperation
	bool rv = pVisitor->visitBindingOperation( WSML::BindingOperation( this));
	return rv;
}


//********************************************************************************
// returns dst WSML::OperationRefs
//********************************************************************************
std::multiset<WSML::OperationRef> WSML::BindingOperationImpl::getBindsOperationDsts()
{
	std::multiset<WSML::OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BindsOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BindsOperation> WSML::BindingOperationImpl::getOutBindsOperationLinks()
{
	std::set<WSML::BindsOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BindsOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "WSML::BodyBinding" among "WSML::BodyBinding"s
//********************************************************************************
std::set<WSML::BodyBinding> WSML::BindingOperationImpl::getBodyBinding()
{
	std::set<WSML::BodyBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::BodyBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::BodyBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::BodyParts" among "WSML::BodyParts"s
//********************************************************************************
std::set<WSML::BodyParts> WSML::BindingOperationImpl::getBodyParts()
{
	std::set<WSML::BodyParts> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::BodyParts");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::BodyParts elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::BindingOperationImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "WSML::" among "WSML::ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<WSML::ExtensibleMessage> WSML::BindingOperationImpl::getExtensibleMessage()
{
	std::set<WSML::ExtensibleMessage> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("WSML::SOAPBody");
	roles_vec[1] = ModelImpl::getChildFCOsAs("WSML::SOAPFault");
	roles_vec[2] = ModelImpl::getChildFCOsAs("WSML::SOAPHeaderFault");
	roles_vec[3] = ModelImpl::getChildFCOsAs("WSML::SOAPHeader");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			WSML::ExtensibleMessage elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "WSML::FaultRef" among "WSML::FaultRef"s
//********************************************************************************
std::set<WSML::FaultRef> WSML::BindingOperationImpl::getFaultRef()
{
	std::set<WSML::FaultRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::FaultRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::FaultRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::HeaderBinding" among "WSML::HeaderBinding"s
//********************************************************************************
std::set<WSML::HeaderBinding> WSML::BindingOperationImpl::getHeaderBinding()
{
	std::set<WSML::HeaderBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::HeaderBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::HeaderBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::HeaderMessage" among "WSML::HeaderMessage"s
//********************************************************************************
std::set<WSML::HeaderMessage> WSML::BindingOperationImpl::getHeaderMessage()
{
	std::set<WSML::HeaderMessage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::HeaderMessage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::HeaderMessage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::HeaderPart" among "WSML::HeaderPart"s
//********************************************************************************
std::set<WSML::HeaderPart> WSML::BindingOperationImpl::getHeaderPart()
{
	std::set<WSML::HeaderPart> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::HeaderPart");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::HeaderPart elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "WSML::" among "WSML::IORef"s and its descendants
//********************************************************************************
std::set<WSML::IORef> WSML::BindingOperationImpl::getIORef()
{
	std::set<WSML::IORef> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("WSML::InputRef");
	roles_vec[1] = ModelImpl::getChildFCOsAs("WSML::OutputRef");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			WSML::IORef elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "WSML::InputRef" among "WSML::IORef"s and its descendants
//********************************************************************************
std::set<WSML::InputRef> WSML::BindingOperationImpl::getInputRef()
{
	std::set<WSML::InputRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::InputRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::InputRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::MessageRef" among "WSML::MessageRef"s
//********************************************************************************
std::set<WSML::MessageRef> WSML::BindingOperationImpl::getMessageRef()
{
	std::set<WSML::MessageRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::MessageRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::MessageRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::OutputRef" among "WSML::IORef"s and its descendants
//********************************************************************************
std::set<WSML::OutputRef> WSML::BindingOperationImpl::getOutputRef()
{
	std::set<WSML::OutputRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::OutputRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::OutputRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::PartRef" among "WSML::PartRef"s
//********************************************************************************
std::set<WSML::PartRef> WSML::BindingOperationImpl::getPartRef()
{
	std::set<WSML::PartRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::PartRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::PartRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPBody" among "WSML::ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<WSML::SOAPBody> WSML::BindingOperationImpl::getSOAPBody()
{
	std::set<WSML::SOAPBody> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPBody");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPBody elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPFault" among "WSML::ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<WSML::SOAPFault> WSML::BindingOperationImpl::getSOAPFault()
{
	std::set<WSML::SOAPFault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPFault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPFault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPFaultExtension" among "WSML::SOAPFaultExtension"s
//********************************************************************************
std::set<WSML::SOAPFaultExtension> WSML::BindingOperationImpl::getSOAPFaultExtension()
{
	std::set<WSML::SOAPFaultExtension> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPFaultExtension");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPFaultExtension elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPHeader" among "WSML::ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<WSML::SOAPHeader> WSML::BindingOperationImpl::getSOAPHeader()
{
	std::set<WSML::SOAPHeader> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPHeader");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPHeader elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPHeaderFault" among "WSML::ExtensibleMessage"s and its descendants
//********************************************************************************
std::set<WSML::SOAPHeaderFault> WSML::BindingOperationImpl::getSOAPHeaderFault()
{
	std::set<WSML::SOAPHeaderFault> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPHeaderFault");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPHeaderFault elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPOperation" among "WSML::ExtensibleOperation"s
//********************************************************************************
std::set<WSML::SOAPOperation> WSML::BindingOperationImpl::getSOAPOperation()
{
	std::set<WSML::SOAPOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentContainerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentContainer
	bool rv = pVisitor->visitComponentContainer( PICML::ComponentContainer( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ComponentConfigProperty" among "PICML::ComponentConfigProperty"s
//********************************************************************************
std::set<PICML::ComponentConfigProperty> PICML::ComponentContainerImpl::getComponentConfigProperty()
{
	std::set<PICML::ComponentConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentInfoProperty" among "PICML::ComponentInfoProperty"s
//********************************************************************************
std::set<PICML::ComponentInfoProperty> PICML::ComponentContainerImpl::getComponentInfoProperty()
{
	std::set<PICML::ComponentInfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentInfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentInfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentProperty" among "PICML::ComponentProperty"s
//********************************************************************************
std::set<PICML::ComponentProperty> PICML::ComponentContainerImpl::getComponentProperty()
{
	std::set<PICML::ComponentProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentPropertyDescription" among "PICML::ComponentPropertyDescription"s
//********************************************************************************
std::set<PICML::ComponentPropertyDescription> PICML::ComponentContainerImpl::getComponentPropertyDescription()
{
	std::set<PICML::ComponentPropertyDescription> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentPropertyDescription");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentPropertyDescription elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::ComponentContainerImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::ComponentContainerImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentImplementationContainerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentImplementationContainer
	bool rv = pVisitor->visitComponentImplementationContainer( PICML::ComponentImplementationContainer( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Capability" among "PICML::Capability"s
//********************************************************************************
std::set<PICML::Capability> PICML::ComponentImplementationContainerImpl::getCapability()
{
	std::set<PICML::Capability> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Capability");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Capability elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentAssembly" among "PICML::ComponentImplementation"s and its descendants
//********************************************************************************
std::set<PICML::ComponentAssembly> PICML::ComponentImplementationContainerImpl::getComponentAssembly()
{
	std::set<PICML::ComponentAssembly> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentAssembly");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentAssembly elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::ComponentImplementation"s and its descendants
//********************************************************************************
std::set<PICML::ComponentImplementation> PICML::ComponentImplementationContainerImpl::getComponentImplementation()
{
	std::set<PICML::ComponentImplementation> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::MonolithicImplementation");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::ComponentAssembly");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::ComponentImplementation elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::ComponentImplementationContainerImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ConfigProperty" among "PICML::ConfigProperty"s
//********************************************************************************
std::set<PICML::ConfigProperty> PICML::ComponentImplementationContainerImpl::getConfigProperty()
{
	std::set<PICML::ConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::CriticalPath" among "PICML::CriticalPath"s
//********************************************************************************
std::set<PICML::CriticalPath> PICML::ComponentImplementationContainerImpl::getCriticalPath()
{
	std::set<PICML::CriticalPath> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::CriticalPath");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::CriticalPath elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationArtifactReference" among "PICML::ImplementationArtifactReference"s
//********************************************************************************
std::set<PICML::ImplementationArtifactReference> PICML::ComponentImplementationContainerImpl::getImplementationArtifactReference()
{
	std::set<PICML::ImplementationArtifactReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationArtifactReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationArtifactReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationCapability" among "PICML::ImplementationCapability"s
//********************************************************************************
std::set<PICML::ImplementationCapability> PICML::ComponentImplementationContainerImpl::getImplementationCapability()
{
	std::set<PICML::ImplementationCapability> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationCapability");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationCapability elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationDependency" among "PICML::ImplementationDependency"s
//********************************************************************************
std::set<PICML::ImplementationDependency> PICML::ComponentImplementationContainerImpl::getImplementationDependency()
{
	std::set<PICML::ImplementationDependency> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationDependency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationDependency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationDependsOn" among "PICML::ImplementationDependsOn"s
//********************************************************************************
std::set<PICML::ImplementationDependsOn> PICML::ComponentImplementationContainerImpl::getImplementationDependsOn()
{
	std::set<PICML::ImplementationDependsOn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationDependsOn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationDependsOn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationRequirement" among "PICML::ImplementationRequirement"s
//********************************************************************************
std::set<PICML::ImplementationRequirement> PICML::ComponentImplementationContainerImpl::getImplementationRequirement()
{
	std::set<PICML::ImplementationRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Implements" among "PICML::Implements"s
//********************************************************************************
std::set<PICML::Implements> PICML::ComponentImplementationContainerImpl::getImplements()
{
	std::set<PICML::Implements> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Implements");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Implements elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::InfoProperty" among "PICML::InfoProperty"s
//********************************************************************************
std::set<PICML::InfoProperty> PICML::ComponentImplementationContainerImpl::getInfoProperty()
{
	std::set<PICML::InfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::MonolithDeployRequirement" among "PICML::MonolithDeployRequirement"s
//********************************************************************************
std::set<PICML::MonolithDeployRequirement> PICML::ComponentImplementationContainerImpl::getMonolithDeployRequirement()
{
	std::set<PICML::MonolithDeployRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MonolithDeployRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MonolithDeployRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::MonolithExecParameter" among "PICML::MonolithExecParameter"s
//********************************************************************************
std::set<PICML::MonolithExecParameter> PICML::ComponentImplementationContainerImpl::getMonolithExecParameter()
{
	std::set<PICML::MonolithExecParameter> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MonolithExecParameter");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MonolithExecParameter elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::MonolithicImplementation" among "PICML::ComponentImplementation"s and its descendants
//********************************************************************************
std::set<PICML::MonolithicImplementation> PICML::ComponentImplementationContainerImpl::getMonolithicImplementation()
{
	std::set<PICML::MonolithicImplementation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MonolithicImplementation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MonolithicImplementation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::MonolithprimaryArtifact" among "PICML::MonolithprimaryArtifact"s
//********************************************************************************
std::set<PICML::MonolithprimaryArtifact> PICML::ComponentImplementationContainerImpl::getMonolithprimaryArtifact()
{
	std::set<PICML::MonolithprimaryArtifact> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MonolithprimaryArtifact");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MonolithprimaryArtifact elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PathReference" among "PICML::PathReference"s
//********************************************************************************
std::set<PICML::PathReference> PICML::ComponentImplementationContainerImpl::getPathReference()
{
	std::set<PICML::PathReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PathReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PathReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::ComponentImplementationContainerImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentPropertyDescriptionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentPropertyDescription
	bool rv = pVisitor->visitComponentPropertyDescription( PICML::ComponentPropertyDescription( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ComponentRefs
//********************************************************************************
std::multiset<PICML::ComponentRef> PICML::ComponentPropertyDescriptionImpl::getComponentPropertySrcs()
{
	std::multiset<PICML::ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentProperty> PICML::ComponentPropertyDescriptionImpl::getInComponentPropertyLinks()
{
	std::set<PICML::ComponentProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "PICML::DataType" among "PICML::DataType"s
//********************************************************************************
std::set<PICML::DataType> PICML::ComponentPropertyDescriptionImpl::getDataType()
{
	std::set<PICML::DataType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::DataType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::DataType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::DefinitionsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Definitions
	bool rv = pVisitor->visitDefinitions( WSML::Definitions( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::DefinitionsImpl::gettargetNamespace()
{
	return FCOImpl::getAttribute("targetNamespace")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::DefinitionsImpl::settargetNamespace( const std::string& val)
{
	FCOImpl::getAttribute("targetNamespace")->setStringValue( val);
}


//********************************************************************************
// getter for role "WSML::Attribute" among "WSML::Attribute"s
//********************************************************************************
std::set<WSML::Attribute> WSML::DefinitionsImpl::getAttribute()
{
	std::set<WSML::Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Binding" among "WSML::Binding"s
//********************************************************************************
std::set<WSML::Binding> WSML::DefinitionsImpl::getBinding()
{
	std::set<WSML::Binding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Binding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Binding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::BindingPortType" among "WSML::BindingPortType"s
//********************************************************************************
std::set<WSML::BindingPortType> WSML::DefinitionsImpl::getBindingPortType()
{
	std::set<WSML::BindingPortType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::BindingPortType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::BindingPortType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::DefinitionsImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Import" among "WSML::Import"s
//********************************************************************************
std::set<WSML::Import> WSML::DefinitionsImpl::getImport()
{
	std::set<WSML::Import> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Import");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Import elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Messages" among "WSML::Messages"s
//********************************************************************************
std::set<WSML::Messages> WSML::DefinitionsImpl::getMessages()
{
	std::set<WSML::Messages> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Messages");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Messages elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::PortType" among "WSML::PortType"s
//********************************************************************************
std::set<WSML::PortType> WSML::DefinitionsImpl::getPortType()
{
	std::set<WSML::PortType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::PortType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::PortType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Service" among "WSML::Service"s
//********************************************************************************
std::set<WSML::Service> WSML::DefinitionsImpl::getService()
{
	std::set<WSML::Service> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Service");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Service elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::ServiceRef" among "WSML::ServiceRef"s
//********************************************************************************
std::set<WSML::ServiceRef> WSML::DefinitionsImpl::getServiceRef()
{
	std::set<WSML::ServiceRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::ServiceRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::ServiceRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Types" among "WSML::Types"s
//********************************************************************************
std::set<WSML::Types> WSML::DefinitionsImpl::getTypes()
{
	std::set<WSML::Types> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Types");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Types elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DeploymentPlanImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::DeploymentPlan
	bool rv = pVisitor->visitDeploymentPlan( PICML::DeploymentPlan( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::DeploymentPlanImpl::getUUID()
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::DeploymentPlanImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::DeploymentPlanImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::DeploymentPlanImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::CollocationGroup" among "PICML::CollocationGroup"s
//********************************************************************************
std::set<PICML::CollocationGroup> PICML::DeploymentPlanImpl::getCollocationGroup()
{
	std::set<PICML::CollocationGroup> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::CollocationGroup");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::CollocationGroup elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentAssemblyReference" among "PICML::ComponentAssemblyReference"s
//********************************************************************************
std::set<PICML::ComponentAssemblyReference> PICML::DeploymentPlanImpl::getComponentAssemblyReference()
{
	std::set<PICML::ComponentAssemblyReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentAssemblyReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentAssemblyReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::DeploymentPlanImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::InstanceMapping" among "PICML::InstanceMapping"s
//********************************************************************************
std::set<PICML::InstanceMapping> PICML::DeploymentPlanImpl::getInstanceMapping()
{
	std::set<PICML::InstanceMapping> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InstanceMapping");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InstanceMapping elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::NodeReference" among "PICML::NodeReference"s
//********************************************************************************
std::set<PICML::NodeReference> PICML::DeploymentPlanImpl::getNodeReference()
{
	std::set<PICML::NodeReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::NodeReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::NodeReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::DeploymentPlanImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::SharedComponentReference" among "PICML::SharedComponentReference"s
//********************************************************************************
std::set<PICML::SharedComponentReference> PICML::DeploymentPlanImpl::getSharedComponentReference()
{
	std::set<PICML::SharedComponentReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SharedComponentReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SharedComponentReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::DocumentationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Documentation
	bool rv = pVisitor->visitDocumentation( WSML::Documentation( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::DocumentationImpl::getDocText()
{
	return FCOImpl::getAttribute("DocText")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
bool WSML::DocumentationImpl::isMixed()
{
	return FCOImpl::getAttribute("Mixed")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::DocumentationImpl::setDocText( const std::string& val)
{
	FCOImpl::getAttribute("DocText")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void WSML::DocumentationImpl::setMixed( bool val)
{
	FCOImpl::getAttribute("Mixed")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "WSML::Element" among "WSML::Element"s
//********************************************************************************
std::set<WSML::Element> WSML::DocumentationImpl::getElement()
{
	std::set<WSML::Element> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Element");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Element elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DomainImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Domain
	bool rv = pVisitor->visitDomain( PICML::Domain( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::DomainImpl::getUUID()
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::DomainImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::DomainImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::DomainImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::Bridge" among "PICML::Elements"s and its descendants
//********************************************************************************
std::set<PICML::Bridge> PICML::DomainImpl::getBridge()
{
	std::set<PICML::Bridge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Bridge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Bridge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Bridge2Interconnect" among "PICML::Bridge2Interconnect"s
//********************************************************************************
std::set<PICML::Bridge2Interconnect> PICML::DomainImpl::getBridge2Interconnect()
{
	std::set<PICML::Bridge2Interconnect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Bridge2Interconnect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Bridge2Interconnect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::Elements"s and its descendants
//********************************************************************************
std::set<PICML::Elements> PICML::DomainImpl::getElements()
{
	std::set<PICML::Elements> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::Bridge");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::Interconnect");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::Node");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::SharedResource");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::Elements elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::Interconnect" among "PICML::Elements"s and its descendants
//********************************************************************************
std::set<PICML::Interconnect> PICML::DomainImpl::getInterconnect()
{
	std::set<PICML::Interconnect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Interconnect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Interconnect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Interconnect2Bridge" among "PICML::Interconnect2Bridge"s
//********************************************************************************
std::set<PICML::Interconnect2Bridge> PICML::DomainImpl::getInterconnect2Bridge()
{
	std::set<PICML::Interconnect2Bridge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Interconnect2Bridge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Interconnect2Bridge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Interconnect2Node" among "PICML::Interconnect2Node"s
//********************************************************************************
std::set<PICML::Interconnect2Node> PICML::DomainImpl::getInterconnect2Node()
{
	std::set<PICML::Interconnect2Node> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Interconnect2Node");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Interconnect2Node elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Node" among "PICML::Elements"s and its descendants
//********************************************************************************
std::set<PICML::Node> PICML::DomainImpl::getNode()
{
	std::set<PICML::Node> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Node");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Node elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Node2Interconnect" among "PICML::Node2Interconnect"s
//********************************************************************************
std::set<PICML::Node2Interconnect> PICML::DomainImpl::getNode2Interconnect()
{
	std::set<PICML::Node2Interconnect> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Node2Interconnect");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Node2Interconnect elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::DomainImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::SharedResource" among "PICML::Elements"s and its descendants
//********************************************************************************
std::set<PICML::SharedResource> PICML::DomainImpl::getSharedResource()
{
	std::set<PICML::SharedResource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SharedResource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SharedResource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Shares" among "PICML::Shares"s
//********************************************************************************
std::set<PICML::Shares> PICML::DomainImpl::getShares()
{
	std::set<PICML::Shares> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Shares");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Shares elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::FaultImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Fault
	bool rv = pVisitor->visitFault( WSML::Fault( this));
	return rv;
}


//********************************************************************************
// returns dst WSML::MessageRefs
//********************************************************************************
std::multiset<WSML::MessageRef> WSML::FaultImpl::getFaultMessageDsts()
{
	std::multiset<WSML::MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("FaultMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::FaultMessage> WSML::FaultImpl::getOutFaultMessageLinks()
{
	std::set<WSML::FaultMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::FaultMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::FaultImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ImportImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Import
	bool rv = pVisitor->visitImport( WSML::Import( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::ImportImpl::getlocation()
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::ImportImpl::getnamespace()
{
	return FCOImpl::getAttribute("namespace")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::ImportImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void WSML::ImportImpl::setnamespace( const std::string& val)
{
	FCOImpl::getAttribute("namespace")->setStringValue( val);
}


//********************************************************************************
// getter for role "WSML::Definitions" among "WSML::Definitions"s
//********************************************************************************
std::set<WSML::Definitions> WSML::ImportImpl::getDefinitions()
{
	std::set<WSML::Definitions> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Definitions");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Definitions elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::ImportImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::InputImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Input
	bool rv = pVisitor->visitInput( WSML::Input( this));
	return rv;
}


//********************************************************************************
// returns dst WSML::MessageRefs
//********************************************************************************
std::multiset<WSML::MessageRef> WSML::InputImpl::getInputMessageDsts()
{
	std::multiset<WSML::MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("InputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::InputMessage> WSML::InputImpl::getOutInputMessageLinks()
{
	std::set<WSML::InputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::InputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::InputImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InputActionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InputAction
	bool rv = pVisitor->visitInputAction( PICML::InputAction( this));
	return rv;
}


//********************************************************************************
// returns src PICML::StateBases
//********************************************************************************
std::multiset<PICML::StateBase> PICML::InputActionImpl::getFinishSrcs()
{
	std::multiset<PICML::StateBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Finish");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::StateBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Finish> PICML::InputActionImpl::getInFinishLinks()
{
	std::set<PICML::Finish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Finish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Input> PICML::InputActionImpl::getInInputLinks()
{
	std::set<PICML::Input> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Input c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MultiInput> PICML::InputActionImpl::getInMultiInputLinks()
{
	std::set<PICML::MultiInput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MultiInput c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::StateBases
//********************************************************************************
std::multiset<PICML::StateBase> PICML::InputActionImpl::getInputEffectDsts()
{
	std::multiset<PICML::StateBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("InputEffect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::StateBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::SingleInputBases
//********************************************************************************
std::multiset<PICML::SingleInputBase> PICML::InputActionImpl::getInputSrcs()
{
	std::multiset<PICML::SingleInputBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Input");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::SingleInputBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::MultiInputBases
//********************************************************************************
std::multiset<PICML::MultiInputBase> PICML::InputActionImpl::getMultiInputSrcs()
{
	std::multiset<PICML::MultiInputBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MultiInput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::MultiInputBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::InputEffect> PICML::InputActionImpl::getOutInputEffectLinks()
{
	std::set<PICML::InputEffect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::InputEffect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::InputActionImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MPCImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MPC
	bool rv = pVisitor->visitMPC( PICML::MPC( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Project" among "PICML::Project"s
//********************************************************************************
std::set<PICML::Project> PICML::MPCImpl::getProject()
{
	std::set<PICML::Project> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Project");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Project elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Workspaces" among "PICML::Workspaces"s
//********************************************************************************
std::set<PICML::Workspaces> PICML::MPCImpl::getWorkspaces()
{
	std::set<PICML::Workspaces> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Workspaces");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Workspaces elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::MessageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Message
	bool rv = pVisitor->visitMessage( WSML::Message( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::Part" among "WSML::Part"s
//********************************************************************************
std::set<WSML::Part> WSML::MessageImpl::getPart()
{
	std::set<WSML::Part> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Part");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Part elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::MessagesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Messages
	bool rv = pVisitor->visitMessages( WSML::Messages( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::Message" among "WSML::Message"s
//********************************************************************************
std::set<WSML::Message> WSML::MessagesImpl::getMessage()
{
	std::set<WSML::Message> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Message");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Message elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::OutputImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Output
	bool rv = pVisitor->visitOutput( WSML::Output( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::OutputMessage> WSML::OutputImpl::getOutOutputMessageLinks()
{
	std::set<WSML::OutputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::OutputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst WSML::MessageRefs
//********************************************************************************
std::multiset<WSML::MessageRef> WSML::OutputImpl::getOutputMessageDsts()
{
	std::multiset<WSML::MessageRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("OutputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::MessageRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::OutputImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfigurationContainerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfigurationContainer
	bool rv = pVisitor->visitPackageConfigurationContainer( PICML::PackageConfigurationContainer( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ComponentPackage" among "PICML::ComponentPackage"s
//********************************************************************************
std::set<PICML::ComponentPackage> PICML::PackageConfigurationContainerImpl::getComponentPackage()
{
	std::set<PICML::ComponentPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentPackageReference" among "PICML::ComponentPackageReference"s
//********************************************************************************
std::set<PICML::ComponentPackageReference> PICML::PackageConfigurationContainerImpl::getComponentPackageReference()
{
	std::set<PICML::ComponentPackageReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentPackageReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentPackageReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ECConfiguration" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::ECConfiguration> PICML::PackageConfigurationContainerImpl::getECConfiguration()
{
	std::set<PICML::ECConfiguration> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ECConfiguration");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ECConfiguration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageConfBasePackage" among "PICML::PackageConfBasePackage"s
//********************************************************************************
std::set<PICML::PackageConfBasePackage> PICML::PackageConfigurationContainerImpl::getPackageConfBasePackage()
{
	std::set<PICML::PackageConfBasePackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfBasePackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfBasePackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageConfConfigProperty" among "PICML::PackageConfConfigProperty"s
//********************************************************************************
std::set<PICML::PackageConfConfigProperty> PICML::PackageConfigurationContainerImpl::getPackageConfConfigProperty()
{
	std::set<PICML::PackageConfConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageConfReference" among "PICML::PackageConfReference"s
//********************************************************************************
std::set<PICML::PackageConfReference> PICML::PackageConfigurationContainerImpl::getPackageConfReference()
{
	std::set<PICML::PackageConfReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageConfSelectRequirement" among "PICML::PackageConfSelectRequirement"s
//********************************************************************************
std::set<PICML::PackageConfSelectRequirement> PICML::PackageConfigurationContainerImpl::getPackageConfSelectRequirement()
{
	std::set<PICML::PackageConfSelectRequirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfSelectRequirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfSelectRequirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageConfSpecializedConfig" among "PICML::PackageConfSpecializedConfig"s
//********************************************************************************
std::set<PICML::PackageConfSpecializedConfig> PICML::PackageConfigurationContainerImpl::getPackageConfSpecializedConfig()
{
	std::set<PICML::PackageConfSpecializedConfig> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfSpecializedConfig");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfSpecializedConfig elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageConfiguration" among "PICML::PackageConfiguration"s
//********************************************************************************
std::set<PICML::PackageConfiguration> PICML::PackageConfigurationContainerImpl::getPackageConfiguration()
{
	std::set<PICML::PackageConfiguration> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfiguration");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfiguration elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::PackageConfigurationContainerImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RTRequirements" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::RTRequirements> PICML::PackageConfigurationContainerImpl::getRTRequirements()
{
	std::set<PICML::RTRequirements> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RTRequirements");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RTRequirements elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Requirement" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::Requirement> PICML::PackageConfigurationContainerImpl::getRequirement()
{
	std::set<PICML::Requirement> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Requirement");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Requirement elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::Requirement"s and its descendants
//********************************************************************************
std::set<PICML::Requirement> PICML::PackageConfigurationContainerImpl::getRequirement(int dummy)
{
	std::set<PICML::Requirement> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::ECConfiguration");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::RTRequirements");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::Requirement");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageContainerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageContainer
	bool rv = pVisitor->visitPackageContainer( PICML::PackageContainer( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ComponentImplementationReference" among "PICML::ComponentImplementationReference"s
//********************************************************************************
std::set<PICML::ComponentImplementationReference> PICML::PackageContainerImpl::getComponentImplementationReference()
{
	std::set<PICML::ComponentImplementationReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentImplementationReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentImplementationReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentPackage" among "PICML::ComponentPackage"s
//********************************************************************************
std::set<PICML::ComponentPackage> PICML::PackageContainerImpl::getComponentPackage()
{
	std::set<PICML::ComponentPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::PackageContainerImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Implementation" among "PICML::Implementation"s
//********************************************************************************
std::set<PICML::Implementation> PICML::PackageContainerImpl::getImplementation()
{
	std::set<PICML::Implementation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Implementation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Implementation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageConfigProperty" among "PICML::PackageConfigProperty"s
//********************************************************************************
std::set<PICML::PackageConfigProperty> PICML::PackageContainerImpl::getPackageConfigProperty()
{
	std::set<PICML::PackageConfigProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfigProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfigProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageInfoProperty" among "PICML::PackageInfoProperty"s
//********************************************************************************
std::set<PICML::PackageInfoProperty> PICML::PackageContainerImpl::getPackageInfoProperty()
{
	std::set<PICML::PackageInfoProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageInfoProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageInfoProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PackageInterface" among "PICML::PackageInterface"s
//********************************************************************************
std::set<PICML::PackageInterface> PICML::PackageContainerImpl::getPackageInterface()
{
	std::set<PICML::PackageInterface> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageInterface");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageInterface elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::PackageContainerImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PathImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Path
	bool rv = pVisitor->visitPath( PICML::Path( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PathProperty> PICML::PathImpl::getOutPathPropertyLinks()
{
	std::set<PICML::PathProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PathProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::PathImpl::getPathPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PathProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ComponentRef" among "PICML::ComponentRef"s
//********************************************************************************
std::set<PICML::ComponentRef> PICML::PathImpl::getComponentRef()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ConnectedComponent" among "PICML::GraphVertex"s and its descendants
//********************************************************************************
std::set<PICML::ConnectedComponent> PICML::PathImpl::getConnectedComponent()
{
	std::set<PICML::ConnectedComponent> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ConnectedComponent");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ConnectedComponent elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::DisplayNode" among "PICML::GraphVertex"s and its descendants
//********************************************************************************
std::set<PICML::DisplayNode> PICML::PathImpl::getDisplayNode()
{
	std::set<PICML::DisplayNode> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::DisplayNode");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::DisplayNode elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::DstEdge" among "PICML::DstEdge"s
//********************************************************************************
std::set<PICML::DstEdge> PICML::PathImpl::getDstEdge()
{
	std::set<PICML::DstEdge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::DstEdge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::DstEdge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Edge" among "PICML::Edge"s
//********************************************************************************
std::set<PICML::Edge> PICML::PathImpl::getEdge()
{
	std::set<PICML::Edge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Edge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Edge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::EdgeProperty" among "PICML::EdgeProperty"s
//********************************************************************************
std::set<PICML::EdgeProperty> PICML::PathImpl::getEdgeProperty()
{
	std::set<PICML::EdgeProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::EdgeProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::EdgeProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::GraphVertex"s and its descendants
//********************************************************************************
std::set<PICML::GraphVertex> PICML::PathImpl::getGraphVertex()
{
	std::set<PICML::GraphVertex> res;
	const int len = 6;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::DisplayNode");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::ConnectedComponent");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::InEventPort");
	roles_vec[3] = ModelImpl::getChildFCOsAs("PICML::OutEventPort");
	roles_vec[4] = ModelImpl::getChildFCOsAs("PICML::ProvidedRequestPort");
	roles_vec[5] = ModelImpl::getChildFCOsAs("PICML::RequiredRequestPort");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::GraphVertex elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::InEventPort" among "PICML::GraphVertex"s and its descendants
//********************************************************************************
std::set<PICML::InEventPort> PICML::PathImpl::getInEventPort()
{
	std::set<PICML::InEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::InEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::InEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::OutEventPort" among "PICML::GraphVertex"s and its descendants
//********************************************************************************
std::set<PICML::OutEventPort> PICML::PathImpl::getOutEventPort()
{
	std::set<PICML::OutEventPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::OutEventPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::OutEventPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::PathImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ProvidedRequestPort" among "PICML::GraphVertex"s and its descendants
//********************************************************************************
std::set<PICML::ProvidedRequestPort> PICML::PathImpl::getProvidedRequestPort()
{
	std::set<PICML::ProvidedRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ProvidedRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ProvidedRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::RequiredRequestPort" among "PICML::GraphVertex"s and its descendants
//********************************************************************************
std::set<PICML::RequiredRequestPort> PICML::PathImpl::getRequiredRequestPort()
{
	std::set<PICML::RequiredRequestPort> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::RequiredRequestPort");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::RequiredRequestPort elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::SrcEdge" among "PICML::SrcEdge"s
//********************************************************************************
std::set<PICML::SrcEdge> PICML::PathImpl::getSrcEdge()
{
	std::set<PICML::SrcEdge> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::SrcEdge");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::SrcEdge elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PathsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Paths
	bool rv = pVisitor->visitPaths( PICML::Paths( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::Path" among "PICML::Path"s
//********************************************************************************
std::set<PICML::Path> PICML::PathsImpl::getPath()
{
	std::set<PICML::Path> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Path");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Path elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::PathProperty" among "PICML::PathProperty"s
//********************************************************************************
std::set<PICML::PathProperty> PICML::PathsImpl::getPathProperty()
{
	std::set<PICML::PathProperty> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PathProperty");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PathProperty elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::Property" among "PICML::Property"s
//********************************************************************************
std::set<PICML::Property> PICML::PathsImpl::getProperty()
{
	std::set<PICML::Property> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Property");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Property elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::PortImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Port
	bool rv = pVisitor->visitPort( WSML::Port( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::PortBinding> WSML::PortImpl::getOutPortBindingLinks()
{
	std::set<WSML::PortBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::PortBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<SIML::PortProxy> WSML::PortImpl::getOutPortProxyLinks()
{
	std::set<SIML::PortProxy> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		SIML::PortProxy c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst WSML::BindingRefs
//********************************************************************************
std::multiset<WSML::BindingRef> WSML::PortImpl::getPortBindingDsts()
{
	std::multiset<WSML::BindingRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PortBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::BindingRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ProvidedRequestPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> WSML::PortImpl::getPortProxyDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("PortProxy");
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::PortImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SOAPAddress" among "WSML::ExtensiblePort"s
//********************************************************************************
std::set<WSML::SOAPAddress> WSML::PortImpl::getSOAPAddress()
{
	std::set<WSML::SOAPAddress> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SOAPAddress");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SOAPAddress elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::PortTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::PortType
	bool rv = pVisitor->visitPortType( WSML::PortType( this));
	return rv;
}


//********************************************************************************
// returns src WSML::Bindings
//********************************************************************************
std::multiset<WSML::Binding> WSML::PortTypeImpl::getBindingPortTypeSrcs()
{
	std::multiset<WSML::Binding> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BindingPortType");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::Binding dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BindingPortType> WSML::PortTypeImpl::getInBindingPortTypeLinks()
{
	std::set<WSML::BindingPortType> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BindingPortType c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::PortTypeImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::NotificationOperation" among "WSML::Operation"s and its descendants
//********************************************************************************
std::set<WSML::NotificationOperation> WSML::PortTypeImpl::getNotificationOperation()
{
	std::set<WSML::NotificationOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::NotificationOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::NotificationOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::OneWayOperation" among "WSML::Operation"s and its descendants
//********************************************************************************
std::set<WSML::OneWayOperation> WSML::PortTypeImpl::getOneWayOperation()
{
	std::set<WSML::OneWayOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::OneWayOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::OneWayOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "WSML::" among "WSML::Operation"s and its descendants
//********************************************************************************
std::set<WSML::Operation> WSML::PortTypeImpl::getOperation()
{
	std::set<WSML::Operation> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("WSML::NotificationOperation");
	roles_vec[1] = ModelImpl::getChildFCOsAs("WSML::OneWayOperation");
	roles_vec[2] = ModelImpl::getChildFCOsAs("WSML::RequestResponseOperation");
	roles_vec[3] = ModelImpl::getChildFCOsAs("WSML::SolicitResponseOperation");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			WSML::Operation elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "WSML::RequestResponseOperation" among "WSML::Operation"s and its descendants
//********************************************************************************
std::set<WSML::RequestResponseOperation> WSML::PortTypeImpl::getRequestResponseOperation()
{
	std::set<WSML::RequestResponseOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::RequestResponseOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::RequestResponseOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SolicitResponseOperation" among "WSML::Operation"s and its descendants
//********************************************************************************
std::set<WSML::SolicitResponseOperation> WSML::PortTypeImpl::getSolicitResponseOperation()
{
	std::set<WSML::SolicitResponseOperation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SolicitResponseOperation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SolicitResponseOperation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ProjectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Project
	bool rv = pVisitor->visitProject( PICML::Project( this));
	return rv;
}


//********************************************************************************
// aggregated getter for role "PICML::" among "PICML::ComponentLib"s and its descendants
//********************************************************************************
std::set<PICML::ComponentLib> PICML::ProjectImpl::getComponentLib()
{
	std::set<PICML::ComponentLib> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("PICML::ExecutorProject");
	roles_vec[1] = ModelImpl::getChildFCOsAs("PICML::ServantProject");
	roles_vec[2] = ModelImpl::getChildFCOsAs("PICML::StubProject");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			PICML::ComponentLib elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "PICML::ExecutorProject" among "PICML::ComponentLib"s and its descendants
//********************************************************************************
std::set<PICML::ExecutorProject> PICML::ProjectImpl::getExecutorProject()
{
	std::set<PICML::ExecutorProject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ExecutorProject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ExecutorProject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ExtResourceConn" among "PICML::ExtResourceConn"s
//********************************************************************************
std::set<PICML::ExtResourceConn> PICML::ProjectImpl::getExtResourceConn()
{
	std::set<PICML::ExtResourceConn> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ExtResourceConn");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ExtResourceConn elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ExternalResources" among "PICML::ExternalResources"s
//********************************************************************************
std::set<PICML::ExternalResources> PICML::ProjectImpl::getExternalResources()
{
	std::set<PICML::ExternalResources> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ExternalResources");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ExternalResources elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ImplementationArtifact" among "PICML::ImplementationArtifact"s
//********************************************************************************
std::set<PICML::ImplementationArtifact> PICML::ProjectImpl::getImplementationArtifact()
{
	std::set<PICML::ImplementationArtifact> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ImplementationArtifact");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ImplementationArtifact elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ServantProject" among "PICML::ComponentLib"s and its descendants
//********************************************************************************
std::set<PICML::ServantProject> PICML::ProjectImpl::getServantProject()
{
	std::set<PICML::ServantProject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ServantProject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ServantProject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::StubProject" among "PICML::ComponentLib"s and its descendants
//********************************************************************************
std::set<PICML::StubProject> PICML::ProjectImpl::getStubProject()
{
	std::set<PICML::StubProject> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::StubProject");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::StubProject elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Property
	bool rv = pVisitor->visitProperty( PICML::Property( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ImplementationArtifacts
//********************************************************************************
std::multiset<PICML::ImplementationArtifact> PICML::PropertyImpl::getArtifactExecParameterSrcs()
{
	std::multiset<PICML::ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::ImplementationArtifacts
//********************************************************************************
std::multiset<PICML::ImplementationArtifact> PICML::PropertyImpl::getArtifactInfoPropertySrcs()
{
	std::multiset<PICML::ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::Components
//********************************************************************************
std::multiset<PICML::Component> PICML::PropertyImpl::getAssemblyConfigPropertySrcs()
{
	std::multiset<PICML::Component> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("AssemblyConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Component dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::PropertyImpl::getAttributeMappingValueSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeMappingValue");
}


//********************************************************************************
// returns src PICML::ReadonlyAttributes and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::PropertyImpl::getAttributeValueSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeValue");
}


//********************************************************************************
// returns src PICML::ComponentRefs
//********************************************************************************
std::multiset<PICML::ComponentRef> PICML::PropertyImpl::getComponentConfigPropertySrcs()
{
	std::multiset<PICML::ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::ComponentRefs
//********************************************************************************
std::multiset<PICML::ComponentRef> PICML::PropertyImpl::getComponentInfoPropertySrcs()
{
	std::multiset<PICML::ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::ComponentImplementations
//********************************************************************************
std::multiset<PICML::ComponentImplementation> PICML::PropertyImpl::getConfigPropertySrcs()
{
	std::multiset<PICML::ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Edges
//********************************************************************************
std::multiset<PICML::Edge> PICML::PropertyImpl::getEdgePropertyDsts()
{
	std::multiset<PICML::Edge> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("EdgeProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Edge dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactExecParameter> PICML::PropertyImpl::getInArtifactExecParameterLinks()
{
	std::set<PICML::ArtifactExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactInfoProperty> PICML::PropertyImpl::getInArtifactInfoPropertyLinks()
{
	std::set<PICML::ArtifactInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AssemblyConfigProperty> PICML::PropertyImpl::getInAssemblyConfigPropertyLinks()
{
	std::set<PICML::AssemblyConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AssemblyConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeMappingValue> PICML::PropertyImpl::getInAttributeMappingValueLinks()
{
	std::set<PICML::AttributeMappingValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeMappingValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeValue> PICML::PropertyImpl::getInAttributeValueLinks()
{
	std::set<PICML::AttributeValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentConfigProperty> PICML::PropertyImpl::getInComponentConfigPropertyLinks()
{
	std::set<PICML::ComponentConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentInfoProperty> PICML::PropertyImpl::getInComponentInfoPropertyLinks()
{
	std::set<PICML::ComponentInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ConfigProperty> PICML::PropertyImpl::getInConfigPropertyLinks()
{
	std::set<PICML::ConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::InfoProperty> PICML::PropertyImpl::getInInfoPropertyLinks()
{
	std::set<PICML::InfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::InfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MonolithExecParameter> PICML::PropertyImpl::getInMonolithExecParameterLinks()
{
	std::set<PICML::MonolithExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MonolithExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfConfigProperty> PICML::PropertyImpl::getInPackageConfConfigPropertyLinks()
{
	std::set<PICML::PackageConfConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfigProperty> PICML::PropertyImpl::getInPackageConfigPropertyLinks()
{
	std::set<PICML::PackageConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageInfoProperty> PICML::PropertyImpl::getInPackageInfoPropertyLinks()
{
	std::set<PICML::PackageInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PathProperty> PICML::PropertyImpl::getInPathPropertyLinks()
{
	std::set<PICML::PathProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PathProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::ComponentImplementations
//********************************************************************************
std::multiset<PICML::ComponentImplementation> PICML::PropertyImpl::getInfoPropertySrcs()
{
	std::multiset<PICML::ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("InfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::MonolithicImplementations
//********************************************************************************
std::multiset<PICML::MonolithicImplementation> PICML::PropertyImpl::getMonolithExecParameterSrcs()
{
	std::multiset<PICML::MonolithicImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MonolithExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::MonolithicImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EdgeProperty> PICML::PropertyImpl::getOutEdgePropertyLinks()
{
	std::set<PICML::EdgeProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EdgeProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::PackageConfigurations
//********************************************************************************
std::multiset<PICML::PackageConfiguration> PICML::PropertyImpl::getPackageConfConfigPropertySrcs()
{
	std::multiset<PICML::PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::ComponentPackages
//********************************************************************************
std::multiset<PICML::ComponentPackage> PICML::PropertyImpl::getPackageConfigPropertySrcs()
{
	std::multiset<PICML::ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::ComponentPackages
//********************************************************************************
std::multiset<PICML::ComponentPackage> PICML::PropertyImpl::getPackageInfoPropertySrcs()
{
	std::multiset<PICML::ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::Paths
//********************************************************************************
std::multiset<PICML::Path> PICML::PropertyImpl::getPathPropertySrcs()
{
	std::multiset<PICML::Path> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PathProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Path dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::PropertyImpl::getDataValue()
{
	return FCOImpl::getAttribute("DataValue")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::PropertyImpl::setDataValue( const std::string& val)
{
	FCOImpl::getAttribute("DataValue")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::DataType" among "PICML::DataType"s
//********************************************************************************
std::set<PICML::DataType> PICML::PropertyImpl::getDataType()
{
	std::set<PICML::DataType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::DataType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::DataType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SatisfierPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SatisfierProperty
	bool rv = pVisitor->visitSatisfierProperty( PICML::SatisfierProperty( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::SatisfierPropertyImpl::getDataValue()
{
	return FCOImpl::getAttribute("DataValue")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
PICML::SatisfierPropertyImpl::SatisfierPropertyKind_Type PICML::SatisfierPropertyImpl::getSatisfierPropertyKind()
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
bool PICML::SatisfierPropertyImpl::isdynamic()
{
	return FCOImpl::getAttribute("dynamic")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::SatisfierPropertyImpl::setDataValue( const std::string& val)
{
	FCOImpl::getAttribute("DataValue")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::SatisfierPropertyImpl::setSatisfierPropertyKind( SatisfierPropertyImpl::SatisfierPropertyKind_Type val)
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
void PICML::SatisfierPropertyImpl::setdynamic( bool val)
{
	FCOImpl::getAttribute("dynamic")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "PICML::DataType" among "PICML::DataType"s
//********************************************************************************
std::set<PICML::DataType> PICML::SatisfierPropertyImpl::getDataType()
{
	std::set<PICML::DataType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::DataType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::DataType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SchemaImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Schema
	bool rv = pVisitor->visitSchema( WSML::Schema( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::SchemaImpl::gettargetNamespace()
{
	return FCOImpl::getAttribute("targetNamespace")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::SchemaImpl::settargetNamespace( const std::string& val)
{
	FCOImpl::getAttribute("targetNamespace")->setStringValue( val);
}


//********************************************************************************
// getter for role "WSML::Attribute" among "WSML::Attribute"s
//********************************************************************************
std::set<WSML::Attribute> WSML::SchemaImpl::getAttribute()
{
	std::set<WSML::Attribute> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Attribute");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Attribute elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Element" among "WSML::Element"s
//********************************************************************************
std::set<WSML::Element> WSML::SchemaImpl::getElement()
{
	std::set<WSML::Element> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Element");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Element elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SchemaImport" among "WSML::SchemaReference"s and its descendants
//********************************************************************************
std::set<WSML::SchemaImport> WSML::SchemaImpl::getSchemaImport()
{
	std::set<WSML::SchemaImport> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SchemaImport");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SchemaImport elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::SchemaReference" among "WSML::SchemaReference"s and its descendants
//********************************************************************************
std::set<WSML::SchemaReference> WSML::SchemaImpl::getSchemaReference()
{
	std::set<WSML::SchemaReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::SchemaReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::SchemaReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "WSML::" among "WSML::SchemaReference"s and its descendants
//********************************************************************************
std::set<WSML::SchemaReference> WSML::SchemaImpl::getSchemaReference(int dummy)
{
	std::set<WSML::SchemaReference> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("WSML::SchemaImport");
	roles_vec[1] = ModelImpl::getChildFCOsAs("WSML::SchemaReference");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			WSML::SchemaReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SchemaBuiltinsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SchemaBuiltins
	bool rv = pVisitor->visitSchemaBuiltins( WSML::SchemaBuiltins( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::AtomicType" among "WSML::AtomicType"s
//********************************************************************************
std::set<WSML::AtomicType> WSML::SchemaBuiltinsImpl::getAtomicType()
{
	std::set<WSML::AtomicType> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::AtomicType");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::AtomicType elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ServiceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Service
	bool rv = pVisitor->visitService( WSML::Service( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::BindingRef" among "WSML::BindingRef"s
//********************************************************************************
std::set<WSML::BindingRef> WSML::ServiceImpl::getBindingRef()
{
	std::set<WSML::BindingRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::BindingRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::BindingRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Port" among "WSML::Port"s
//********************************************************************************
std::set<WSML::Port> WSML::ServiceImpl::getPort()
{
	std::set<WSML::Port> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Port");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Port elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::PortBinding" among "WSML::PortBinding"s
//********************************************************************************
std::set<WSML::PortBinding> WSML::ServiceImpl::getPortBinding()
{
	std::set<WSML::PortBinding> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::PortBinding");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::PortBinding elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ServiceProviderImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ServiceProvider
	bool rv = pVisitor->visitServiceProvider( PICML::ServiceProvider( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ServiceProviderImpl::isfixed_prioirty_service_execution()
{
	return FCOImpl::getAttribute("fixed_prioirty_service_execution")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ServiceProviderImpl::setfixed_prioirty_service_execution( bool val)
{
	FCOImpl::getAttribute("fixed_prioirty_service_execution")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "PICML::MultipleServiceRequests" among "PICML::MultipleServiceRequests"s
//********************************************************************************
std::set<PICML::MultipleServiceRequests> PICML::ServiceProviderImpl::getMultipleServiceRequests()
{
	std::set<PICML::MultipleServiceRequests> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::MultipleServiceRequests");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::MultipleServiceRequests elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::ServiceLevels" among "PICML::ServiceLevels"s
//********************************************************************************
std::set<PICML::ServiceLevels> PICML::ServiceProviderImpl::getServiceLevels()
{
	std::set<PICML::ServiceLevels> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ServiceLevels");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ServiceLevels elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool SIML::SystemImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the SIML::System
	bool rv = pVisitor->visitSystem( SIML::System( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::ComponentAssemblyReference" among "PICML::ComponentAssemblyReference"s
//********************************************************************************
std::set<PICML::ComponentAssemblyReference> SIML::SystemImpl::getPICMLComponentAssemblyReference()
{
	std::set<PICML::ComponentAssemblyReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::ComponentAssemblyReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::ComponentAssemblyReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SIML::PortProxy" among "SIML::PortProxy"s
//********************************************************************************
std::set<SIML::PortProxy> SIML::SystemImpl::getPortProxy()
{
	std::set<SIML::PortProxy> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SIML::PortProxy");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SIML::PortProxy elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SIML::System" among "SIML::System"s
//********************************************************************************
std::set<SIML::System> SIML::SystemImpl::getSystem()
{
	std::set<SIML::System> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("SIML::System");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SIML::System elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::ServiceRef" among "WSML::ServiceRef"s
//********************************************************************************
std::set<WSML::ServiceRef> SIML::SystemImpl::getWSMLServiceRef()
{
	std::set<WSML::ServiceRef> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::ServiceRef");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::ServiceRef elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TopLevelPackageContainerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TopLevelPackageContainer
	bool rv = pVisitor->visitTopLevelPackageContainer( PICML::TopLevelPackageContainer( this));
	return rv;
}


//********************************************************************************
// getter for role "PICML::PackageConfigurationReference" among "PICML::PackageConfigurationReference"s
//********************************************************************************
std::set<PICML::PackageConfigurationReference> PICML::TopLevelPackageContainerImpl::getPackageConfigurationReference()
{
	std::set<PICML::PackageConfigurationReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::PackageConfigurationReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::PackageConfigurationReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::TopLevelPackage" among "PICML::TopLevelPackage"s
//********************************************************************************
std::set<PICML::TopLevelPackage> PICML::TopLevelPackageContainerImpl::getTopLevelPackage()
{
	std::set<PICML::TopLevelPackage> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::TopLevelPackage");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::TopLevelPackage elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "PICML::package" among "PICML::package"s
//********************************************************************************
std::set<PICML::package> PICML::TopLevelPackageContainerImpl::getpackage()
{
	std::set<PICML::package> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::package");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::package elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::TypesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Types
	bool rv = pVisitor->visitTypes( WSML::Types( this));
	return rv;
}


//********************************************************************************
// getter for role "WSML::Documentation" among "WSML::Documentation"s
//********************************************************************************
std::set<WSML::Documentation> WSML::TypesImpl::getDocumentation()
{
	std::set<WSML::Documentation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Documentation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Documentation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "WSML::Schema" among "WSML::Schema"s
//********************************************************************************
std::set<WSML::Schema> WSML::TypesImpl::getSchema()
{
	std::set<WSML::Schema> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("WSML::Schema");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		WSML::Schema elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Worker
	bool rv = pVisitor->visitWorker( PICML::Worker( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerImpl::isAbstract()
{
	return FCOImpl::getAttribute("Abstract")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::WorkerImpl::setAbstract( bool val)
{
	FCOImpl::getAttribute("Abstract")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "PICML::Action" among "PICML::Action"s
//********************************************************************************
std::set<PICML::Action> PICML::WorkerImpl::getAction()
{
	std::set<PICML::Action> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::Action");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::Action elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerLibraryImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkerLibrary
	bool rv = pVisitor->visitWorkerLibrary( PICML::WorkerLibrary( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::WorkerLibraryImpl::getLocation()
{
	return FCOImpl::getAttribute("Location")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::WorkerLibraryImpl::setLocation( const std::string& val)
{
	FCOImpl::getAttribute("Location")->setStringValue( val);
}


//********************************************************************************
// getter for role "PICML::WorkerFile" among "PICML::WorkerFile"s
//********************************************************************************
std::set<PICML::WorkerFile> PICML::WorkerLibraryImpl::getWorkerFile()
{
	std::set<PICML::WorkerFile> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("PICML::WorkerFile");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		PICML::WorkerFile elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BenchmarkTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::BenchmarkType
	bool rv = pVisitor->visitBenchmarkType( PICML::BenchmarkType( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::MetricsBases
//********************************************************************************
std::multiset<PICML::MetricsBase> PICML::BenchmarkTypeImpl::getBenchmarkCharacteristicsDsts()
{
	std::multiset<PICML::MetricsBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BenchmarkCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::MetricsBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::BenchmarkCharacteristics> PICML::BenchmarkTypeImpl::getOutBenchmarkCharacteristicsLinks()
{
	std::set<PICML::BenchmarkCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::BenchmarkCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::FixedIterationBenchmarksImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::FixedIterationBenchmarks
	bool rv = pVisitor->visitFixedIterationBenchmarks( PICML::FixedIterationBenchmarks( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
long PICML::FixedIterationBenchmarksImpl::getbenchmarkIterations()
{
	return FCOImpl::getAttribute("benchmarkIterations")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::FixedIterationBenchmarksImpl::setbenchmarkIterations( const long val)
{
	FCOImpl::getAttribute("benchmarkIterations")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PeriodicBenchmarksImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PeriodicBenchmarks
	bool rv = pVisitor->visitPeriodicBenchmarks( PICML::PeriodicBenchmarks( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
long PICML::PeriodicBenchmarksImpl::gettimeperiod()
{
	return FCOImpl::getAttribute("timeperiod")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::PeriodicBenchmarksImpl::settimeperiod( const long val)
{
	FCOImpl::getAttribute("timeperiod")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TriggerBenchmarksImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TriggerBenchmarks
	bool rv = pVisitor->visitTriggerBenchmarks( PICML::TriggerBenchmarks( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DataAnalysisBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::DataAnalysisBase
	bool rv = pVisitor->visitDataAnalysisBase( PICML::DataAnalysisBase( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AverageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Average
	bool rv = pVisitor->visitAverage( PICML::Average( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::JitterImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Jitter
	bool rv = pVisitor->visitJitter( PICML::Jitter( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MaximumImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Maximum
	bool rv = pVisitor->visitMaximum( PICML::Maximum( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MinimumImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Minimum
	bool rv = pVisitor->visitMinimum( PICML::Minimum( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::IORefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::IORef
	bool rv = pVisitor->visitIORef( WSML::IORef( this));
	return rv;
}


//********************************************************************************
// returns dst WSML::SOAPBodys
//********************************************************************************
std::multiset<WSML::SOAPBody> WSML::IORefImpl::getBodyBindingDsts()
{
	std::multiset<WSML::SOAPBody> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BodyBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::SOAPBody dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst WSML::SOAPHeaderss
//********************************************************************************
std::multiset<WSML::SOAPHeaders> WSML::IORefImpl::getHeaderBindingDsts()
{
	std::multiset<WSML::SOAPHeaders> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("HeaderBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::SOAPHeaders dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BodyBinding> WSML::IORefImpl::getOutBodyBindingLinks()
{
	std::set<WSML::BodyBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BodyBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::HeaderBinding> WSML::IORefImpl::getOutHeaderBindingLinks()
{
	std::set<WSML::HeaderBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::HeaderBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::InputRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::InputRef
	bool rv = pVisitor->visitInputRef( WSML::InputRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
WSML::Input WSML::InputRefImpl::getInput()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Input(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::OutputRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::OutputRef
	bool rv = pVisitor->visitOutputRef( WSML::OutputRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
WSML::Output WSML::OutputRefImpl::getOutput()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Output(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::AttributeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Attribute
	bool rv = pVisitor->visitAttribute( WSML::Attribute( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string WSML::AttributeImpl::getValue()
{
	return FCOImpl::getAttribute("Value")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void WSML::AttributeImpl::setValue( const std::string& val)
{
	FCOImpl::getAttribute("Value")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::StateBaseImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::StateBase
	bool rv = pVisitor->visitStateBase( PICML::StateBase( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ActionBases
//********************************************************************************
std::multiset<PICML::ActionBase> PICML::StateBaseImpl::getEffectSrcs()
{
	std::multiset<PICML::ActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Effect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::InputActions
//********************************************************************************
std::multiset<PICML::InputAction> PICML::StateBaseImpl::getFinishDsts()
{
	std::multiset<PICML::InputAction> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Finish");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::InputAction dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Effect> PICML::StateBaseImpl::getInEffectLinks()
{
	std::set<PICML::Effect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Effect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::InputEffect> PICML::StateBaseImpl::getInInputEffectLinks()
{
	std::set<PICML::InputEffect> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::InputEffect c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::InputActions
//********************************************************************************
std::multiset<PICML::InputAction> PICML::StateBaseImpl::getInputEffectSrcs()
{
	std::multiset<PICML::InputAction> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("InputEffect");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::InputAction dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Finish> PICML::StateBaseImpl::getOutFinishLinks()
{
	std::set<PICML::Finish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Finish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BranchStateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::BranchState
	bool rv = pVisitor->visitBranchState( PICML::BranchState( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ActionBases
//********************************************************************************
std::multiset<PICML::ActionBase> PICML::BranchStateImpl::getBranchTransitionDsts()
{
	std::multiset<PICML::ActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("BranchTransition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::BranchTransition> PICML::BranchStateImpl::getOutBranchTransitionLinks()
{
	std::set<PICML::BranchTransition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::BranchTransition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::StateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::State
	bool rv = pVisitor->visitState( PICML::State( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Transition> PICML::StateImpl::getOutTransitionLinks()
{
	std::set<PICML::Transition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Transition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::ActionBases
//********************************************************************************
std::multiset<PICML::ActionBase> PICML::StateImpl::getTransitionDsts()
{
	std::multiset<PICML::ActionBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Transition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ActionBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentPackageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentPackage
	bool rv = pVisitor->visitComponentPackage( PICML::ComponentPackage( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ComponentImplementationReferences
//********************************************************************************
std::multiset<PICML::ComponentImplementationReference> PICML::ComponentPackageImpl::getImplementationDsts()
{
	std::multiset<PICML::ComponentImplementationReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Implementation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ComponentImplementationReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfBasePackage> PICML::ComponentPackageImpl::getInPackageConfBasePackageLinks()
{
	std::set<PICML::PackageConfBasePackage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfBasePackage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Implementation> PICML::ComponentPackageImpl::getOutImplementationLinks()
{
	std::set<PICML::Implementation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Implementation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfigProperty> PICML::ComponentPackageImpl::getOutPackageConfigPropertyLinks()
{
	std::set<PICML::PackageConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageInfoProperty> PICML::ComponentPackageImpl::getOutPackageInfoPropertyLinks()
{
	std::set<PICML::PackageInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageInterface> PICML::ComponentPackageImpl::getOutPackageInterfaceLinks()
{
	std::set<PICML::PackageInterface> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageInterface c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::PackageConfigurations
//********************************************************************************
std::multiset<PICML::PackageConfiguration> PICML::ComponentPackageImpl::getPackageConfBasePackageSrcs()
{
	std::multiset<PICML::PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfBasePackage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ComponentPackageImpl::getPackageConfigPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ComponentPackageImpl::getPackageInfoPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ComponentRefs
//********************************************************************************
std::multiset<PICML::ComponentRef> PICML::ComponentPackageImpl::getPackageInterfaceDsts()
{
	std::multiset<PICML::ComponentRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageInterface");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ComponentRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentPackageImpl::getUUID()
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentPackageImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentPackageImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentPackageImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECBehaviorImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ECBehavior
	bool rv = pVisitor->visitECBehavior( PICML::ECBehavior( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ECConsumers
//********************************************************************************
std::multiset<PICML::ECConsumer> PICML::ECBehaviorImpl::getConsumer2BehaviorConnectionSrcs()
{
	std::multiset<PICML::ECConsumer> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Consumer2BehaviorConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ECConsumer dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Consumer2BehaviorConnection> PICML::ECBehaviorImpl::getInConsumer2BehaviorConnectionLinks()
{
	std::set<PICML::Consumer2BehaviorConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Consumer2BehaviorConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ECBehaviorImpl::getDispatchingMultithreadingLevel()
{
	return FCOImpl::getAttribute("DispatchingMultithreadingLevel")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECBehaviorImpl::isConsumerBasedFiltering()
{
	return FCOImpl::getAttribute("ConsumerBasedFiltering")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECBehaviorImpl::isDisconnectDanglingConnections()
{
	return FCOImpl::getAttribute("DisconnectDanglingConnections")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECBehaviorImpl::isMultithreadedConsumer()
{
	return FCOImpl::getAttribute("MultithreadedConsumer")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECBehaviorImpl::isMultithreadedSupplier()
{
	return FCOImpl::getAttribute("MultithreadedSupplier")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECBehaviorImpl::isSupplierBasedFiltering()
{
	return FCOImpl::getAttribute("SupplierBasedFiltering")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECBehaviorImpl::setConsumerBasedFiltering( bool val)
{
	FCOImpl::getAttribute("ConsumerBasedFiltering")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECBehaviorImpl::setDisconnectDanglingConnections( bool val)
{
	FCOImpl::getAttribute("DisconnectDanglingConnections")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECBehaviorImpl::setDispatchingMultithreadingLevel( const std::string& val)
{
	FCOImpl::getAttribute("DispatchingMultithreadingLevel")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECBehaviorImpl::setMultithreadedConsumer( bool val)
{
	FCOImpl::getAttribute("MultithreadedConsumer")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECBehaviorImpl::setMultithreadedSupplier( bool val)
{
	FCOImpl::getAttribute("MultithreadedSupplier")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECBehaviorImpl::setSupplierBasedFiltering( bool val)
{
	FCOImpl::getAttribute("SupplierBasedFiltering")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ECEventFilterConfigurationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ECEventFilterConfiguration
	bool rv = pVisitor->visitECEventFilterConfiguration( PICML::ECEventFilterConfiguration( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::RecursiveFilterConnection> PICML::ECEventFilterConfigurationImpl::getInRecursiveFilterConnectionLinks()
{
	std::set<PICML::RecursiveFilterConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::RecursiveFilterConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Supplier2FilterConnection> PICML::ECEventFilterConfigurationImpl::getInSupplier2FilterConnectionLinks()
{
	std::set<PICML::Supplier2FilterConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Supplier2FilterConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::RecursiveFilterConnection> PICML::ECEventFilterConfigurationImpl::getOutRecursiveFilterConnectionLinks()
{
	std::set<PICML::RecursiveFilterConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::RecursiveFilterConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::ECEventFilterConfigurations
//********************************************************************************
std::multiset<PICML::ECEventFilterConfiguration> PICML::ECEventFilterConfigurationImpl::getRecursiveFilterConnectionDsts()
{
	std::multiset<PICML::ECEventFilterConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("RecursiveFilterConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ECEventFilterConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::RecursiveFilterConnection> PICML::ECEventFilterConfigurationImpl::getRecursiveFilterConnectionLinks()
{
	std::set<PICML::RecursiveFilterConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::RecursiveFilterConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::ECEventFilterConfigurations
//********************************************************************************
std::multiset<PICML::ECEventFilterConfiguration> PICML::ECEventFilterConfigurationImpl::getRecursiveFilterConnectionSrcs()
{
	std::multiset<PICML::ECEventFilterConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("RecursiveFilterConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ECEventFilterConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::ECSuppliers
//********************************************************************************
std::multiset<PICML::ECSupplier> PICML::ECEventFilterConfigurationImpl::getSupplier2FilterConnectionSrcs()
{
	std::multiset<PICML::ECSupplier> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Supplier2FilterConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ECSupplier dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::ECEventFilterConfigurationImpl::ECFilterType_Type PICML::ECEventFilterConfigurationImpl::getECFilterType()
{
	std::string val = FCOImpl::getAttribute("ECFilterType")->getStringValue();

	if ( val == "GroupOR") return GroupOR_ECFilterType_Type;
	else if ( val == "LogicalAND") return LogicalAND_ECFilterType_Type;
	else if ( val == "GroupAND") return GroupAND_ECFilterType_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void PICML::ECEventFilterConfigurationImpl::setECFilterType( ECEventFilterConfigurationImpl::ECFilterType_Type val)
{
	std::string str_val = "";

	if ( val == GroupOR_ECFilterType_Type) str_val = "GroupOR";
	else if ( val == LogicalAND_ECFilterType_Type) str_val = "LogicalAND";
	else if ( val == GroupAND_ECFilterType_Type) str_val = "GroupAND";
	else throw("None of the possible items");

	FCOImpl::getAttribute("ECFilterType")->setStringValue( str_val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EdgeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Edge
	bool rv = pVisitor->visitEdge( PICML::Edge( this));
	return rv;
}


//********************************************************************************
// returns src PICML::GraphVertexs and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::EdgeImpl::getDstEdgeSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("DstEdge");
}


//********************************************************************************
// returns src PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::EdgeImpl::getEdgePropertySrcs()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("EdgeProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::DstEdge> PICML::EdgeImpl::getInDstEdgeLinks()
{
	std::set<PICML::DstEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::DstEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::EdgeProperty> PICML::EdgeImpl::getInEdgePropertyLinks()
{
	std::set<PICML::EdgeProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::EdgeProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::SrcEdge> PICML::EdgeImpl::getOutSrcEdgeLinks()
{
	std::set<PICML::SrcEdge> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::SrcEdge c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::GraphVertexs and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::EdgeImpl::getSrcEdgeDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("SrcEdge");
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EnumValueImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::EnumValue
	bool rv = pVisitor->visitEnumValue( PICML::EnumValue( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ExternalReferenceEndPointImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ExternalReferenceEndPoint
	bool rv = pVisitor->visitExternalReferenceEndPoint( PICML::ExternalReferenceEndPoint( this));
	return rv;
}


//********************************************************************************
// returns src PICML::Components
//********************************************************************************
std::multiset<PICML::Component> PICML::ExternalReferenceEndPointImpl::getExternalDelegateSrcs()
{
	std::multiset<PICML::Component> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ExternalDelegate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Component dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ExternalDelegate> PICML::ExternalReferenceEndPointImpl::getInExternalDelegateLinks()
{
	std::set<PICML::ExternalDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ExternalDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ExternalReferenceEndPointImpl::getlocation()
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ExternalReferenceEndPointImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationArtifactImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ImplementationArtifact
	bool rv = pVisitor->visitImplementationArtifact( PICML::ImplementationArtifact( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ImplementationArtifacts
//********************************************************************************
std::multiset<PICML::ImplementationArtifact> PICML::ImplementationArtifactImpl::getArtifactDependencyDsts()
{
	std::multiset<PICML::ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactDependency");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactDependency> PICML::ImplementationArtifactImpl::getArtifactDependencyLinks()
{
	std::set<PICML::ArtifactDependency> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactDependency c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::ImplementationArtifacts
//********************************************************************************
std::multiset<PICML::ImplementationArtifact> PICML::ImplementationArtifactImpl::getArtifactDependencySrcs()
{
	std::multiset<PICML::ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactDependency");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ImplementationArtifactReferences
//********************************************************************************
std::multiset<PICML::ImplementationArtifactReference> PICML::ImplementationArtifactImpl::getArtifactDependsOnDsts()
{
	std::multiset<PICML::ImplementationArtifactReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifactReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Requirements
//********************************************************************************
std::multiset<PICML::Requirement> PICML::ImplementationArtifactImpl::getArtifactDeployRequirementDsts()
{
	std::multiset<PICML::Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ImplementationArtifactImpl::getArtifactExecParameterDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactExecParameter");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::ImplementationArtifactImpl::getArtifactInfoPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ArtifactInfoProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactDependency> PICML::ImplementationArtifactImpl::getInArtifactDependencyLinks()
{
	std::set<PICML::ArtifactDependency> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactDependency c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactDependency> PICML::ImplementationArtifactImpl::getOutArtifactDependencyLinks()
{
	std::set<PICML::ArtifactDependency> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactDependency c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactDependsOn> PICML::ImplementationArtifactImpl::getOutArtifactDependsOnLinks()
{
	std::set<PICML::ArtifactDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactDeployRequirement> PICML::ImplementationArtifactImpl::getOutArtifactDeployRequirementLinks()
{
	std::set<PICML::ArtifactDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactExecParameter> PICML::ImplementationArtifactImpl::getOutArtifactExecParameterLinks()
{
	std::set<PICML::ArtifactExecParameter> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactExecParameter c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactInfoProperty> PICML::ImplementationArtifactImpl::getOutArtifactInfoPropertyLinks()
{
	std::set<PICML::ArtifactInfoProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactInfoProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ImplementationArtifactImpl::getUUID()
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
PICML::ImplementationArtifactImpl::architecture_Type PICML::ImplementationArtifactImpl::getarchitecture()
{
	std::string val = FCOImpl::getAttribute("architecture")->getStringValue();

	if ( val == "x86") return x86_architecture_Type;
	else if ( val == "x86-64") return x86_64_architecture_Type;
	else if ( val == "PowerPC") return PowerPC_architecture_Type;
	else if ( val == "SPARC") return SPARC_architecture_Type;
	else if ( val == "MIPS") return MIPS_architecture_Type;
	else if ( val == "HPPA") return HPPA_architecture_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ImplementationArtifactImpl::getartifactVersion()
{
	return FCOImpl::getAttribute("artifactVersion")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
PICML::ImplementationArtifactImpl::configuration_Type PICML::ImplementationArtifactImpl::getconfiguration()
{
	std::string val = FCOImpl::getAttribute("configuration")->getStringValue();

	if ( val == "Release") return Release_configuration_Type;
	else if ( val == "Debug") return Debug_configuration_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ImplementationArtifactImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ImplementationArtifactImpl::getlocation()
{
	return FCOImpl::getAttribute("location")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
PICML::ImplementationArtifactImpl::operatingSystem_Type PICML::ImplementationArtifactImpl::getoperatingSystem()
{
	std::string val = FCOImpl::getAttribute("operatingSystem")->getStringValue();

	if ( val == "Linux") return Linux_operatingSystem_Type;
	else if ( val == "Win32") return Win32_operatingSystem_Type;
	else if ( val == "Darwin") return Darwin_operatingSystem_Type;
	else if ( val == "Win64") return Win64_operatingSystem_Type;
	else if ( val == "SunOS") return SunOS_operatingSystem_Type;
	else if ( val == "VxWorks") return VxWorks_operatingSystem_Type;
	else if ( val == "FreeBSD") return FreeBSD_operatingSystem_Type;
	else if ( val == "NetBSD") return NetBSD_operatingSystem_Type;
	else if ( val == "OpenBSD") return OpenBSD_operatingSystem_Type;
	else if ( val == "AIX") return AIX_operatingSystem_Type;
	else if ( val == "BSDi") return BSDi_operatingSystem_Type;
	else if ( val == "VMS") return VMS_operatingSystem_Type;
	else if ( val == "Tru64") return Tru64_operatingSystem_Type;
	else if ( val == "DigitalUnix") return DigitalUnix_operatingSystem_Type;
	else if ( val == "HPUX") return HPUX_operatingSystem_Type;
	else if ( val == "IRIX") return IRIX_operatingSystem_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationArtifactImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationArtifactImpl::setarchitecture( ImplementationArtifactImpl::architecture_Type val)
{
	std::string str_val = "";

	if ( val == x86_architecture_Type) str_val = "x86";
	else if ( val == x86_64_architecture_Type) str_val = "x86-64";
	else if ( val == PowerPC_architecture_Type) str_val = "PowerPC";
	else if ( val == SPARC_architecture_Type) str_val = "SPARC";
	else if ( val == MIPS_architecture_Type) str_val = "MIPS";
	else if ( val == HPPA_architecture_Type) str_val = "HPPA";
	else throw("None of the possible items");

	FCOImpl::getAttribute("architecture")->setStringValue( str_val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationArtifactImpl::setartifactVersion( const std::string& val)
{
	FCOImpl::getAttribute("artifactVersion")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationArtifactImpl::setconfiguration( ImplementationArtifactImpl::configuration_Type val)
{
	std::string str_val = "";

	if ( val == Release_configuration_Type) str_val = "Release";
	else if ( val == Debug_configuration_Type) str_val = "Debug";
	else throw("None of the possible items");

	FCOImpl::getAttribute("configuration")->setStringValue( str_val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationArtifactImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationArtifactImpl::setlocation( const std::string& val)
{
	FCOImpl::getAttribute("location")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationArtifactImpl::setoperatingSystem( ImplementationArtifactImpl::operatingSystem_Type val)
{
	std::string str_val = "";

	if ( val == Linux_operatingSystem_Type) str_val = "Linux";
	else if ( val == Win32_operatingSystem_Type) str_val = "Win32";
	else if ( val == Darwin_operatingSystem_Type) str_val = "Darwin";
	else if ( val == Win64_operatingSystem_Type) str_val = "Win64";
	else if ( val == SunOS_operatingSystem_Type) str_val = "SunOS";
	else if ( val == VxWorks_operatingSystem_Type) str_val = "VxWorks";
	else if ( val == FreeBSD_operatingSystem_Type) str_val = "FreeBSD";
	else if ( val == NetBSD_operatingSystem_Type) str_val = "NetBSD";
	else if ( val == OpenBSD_operatingSystem_Type) str_val = "OpenBSD";
	else if ( val == AIX_operatingSystem_Type) str_val = "AIX";
	else if ( val == BSDi_operatingSystem_Type) str_val = "BSDi";
	else if ( val == VMS_operatingSystem_Type) str_val = "VMS";
	else if ( val == Tru64_operatingSystem_Type) str_val = "Tru64";
	else if ( val == DigitalUnix_operatingSystem_Type) str_val = "DigitalUnix";
	else if ( val == HPUX_operatingSystem_Type) str_val = "HPUX";
	else if ( val == IRIX_operatingSystem_Type) str_val = "IRIX";
	else throw("None of the possible items");

	FCOImpl::getAttribute("operatingSystem")->setStringValue( str_val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationDependencyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ImplementationDependency
	bool rv = pVisitor->visitImplementationDependency( PICML::ImplementationDependency( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ComponentImplementations
//********************************************************************************
std::multiset<PICML::ComponentImplementation> PICML::ImplementationDependencyImpl::getImplementationDependsOnSrcs()
{
	std::multiset<PICML::ComponentImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ImplementationDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ImplementationDependsOn> PICML::ImplementationDependencyImpl::getInImplementationDependsOnLinks()
{
	std::set<PICML::ImplementationDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ImplementationDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ImplementationDependencyImpl::getrequiredType()
{
	return FCOImpl::getAttribute("requiredType")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ImplementationDependencyImpl::setrequiredType( const std::string& val)
{
	FCOImpl::getAttribute("requiredType")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::LabelImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Label
	bool rv = pVisitor->visitLabel( PICML::Label( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::LabelConnection> PICML::LabelImpl::getInLabelConnectionLinks()
{
	std::set<PICML::LabelConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::LabelConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::Members
//********************************************************************************
std::multiset<PICML::Member> PICML::LabelImpl::getLabelConnectionSrcs()
{
	std::multiset<PICML::Member> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("LabelConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Member dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MultipleServiceRequestsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MultipleServiceRequests
	bool rv = pVisitor->visitMultipleServiceRequests( PICML::MultipleServiceRequests( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
long PICML::MultipleServiceRequestsImpl::getmaximum_simultaneous_service_level()
{
	return FCOImpl::getAttribute("maximum_simultaneous_service_level")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
long PICML::MultipleServiceRequestsImpl::getminimum_simultaneous_service_level()
{
	return FCOImpl::getAttribute("minimum_simultaneous_service_level")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MultipleServiceRequestsImpl::isbuffer_service_requests()
{
	return FCOImpl::getAttribute("buffer_service_requests")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MultipleServiceRequestsImpl::issimultaneous_service_execution()
{
	return FCOImpl::getAttribute("simultaneous_service_execution")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::MultipleServiceRequestsImpl::setbuffer_service_requests( bool val)
{
	FCOImpl::getAttribute("buffer_service_requests")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::MultipleServiceRequestsImpl::setmaximum_simultaneous_service_level( const long val)
{
	FCOImpl::getAttribute("maximum_simultaneous_service_level")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::MultipleServiceRequestsImpl::setminimum_simultaneous_service_level( const long val)
{
	FCOImpl::getAttribute("minimum_simultaneous_service_level")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::MultipleServiceRequestsImpl::setsimultaneous_service_execution( bool val)
{
	FCOImpl::getAttribute("simultaneous_service_execution")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfigurationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfiguration
	bool rv = pVisitor->visitPackageConfiguration( PICML::PackageConfiguration( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfBasePackage> PICML::PackageConfigurationImpl::getOutPackageConfBasePackageLinks()
{
	std::set<PICML::PackageConfBasePackage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfBasePackage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfConfigProperty> PICML::PackageConfigurationImpl::getOutPackageConfConfigPropertyLinks()
{
	std::set<PICML::PackageConfConfigProperty> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfConfigProperty c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfReference> PICML::PackageConfigurationImpl::getOutPackageConfReferenceLinks()
{
	std::set<PICML::PackageConfReference> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfReference c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfSelectRequirement> PICML::PackageConfigurationImpl::getOutPackageConfSelectRequirementLinks()
{
	std::set<PICML::PackageConfSelectRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfSelectRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfSpecializedConfig> PICML::PackageConfigurationImpl::getOutPackageConfSpecializedConfigLinks()
{
	std::set<PICML::PackageConfSpecializedConfig> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfSpecializedConfig c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::ComponentPackages
//********************************************************************************
std::multiset<PICML::ComponentPackage> PICML::PackageConfigurationImpl::getPackageConfBasePackageDsts()
{
	std::multiset<PICML::ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfBasePackage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::PackageConfigurationImpl::getPackageConfConfigPropertyDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfConfigProperty");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::ComponentPackageReferences
//********************************************************************************
std::multiset<PICML::ComponentPackageReference> PICML::PackageConfigurationImpl::getPackageConfReferenceDsts()
{
	std::multiset<PICML::ComponentPackageReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfReference");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::ComponentPackageReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Requirements
//********************************************************************************
std::multiset<PICML::Requirement> PICML::PackageConfigurationImpl::getPackageConfSelectRequirementDsts()
{
	std::multiset<PICML::Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfSelectRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::PackageConfigurationReferences
//********************************************************************************
std::multiset<PICML::PackageConfigurationReference> PICML::PackageConfigurationImpl::getPackageConfSpecializedConfigDsts()
{
	std::multiset<PICML::PackageConfigurationReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PackageConfSpecializedConfig");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::PackageConfigurationReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::PackageConfigurationImpl::getUUID()
{
	return FCOImpl::getAttribute("UUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::PackageConfigurationImpl::getlabel()
{
	return FCOImpl::getAttribute("label")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::PackageConfigurationImpl::setUUID( const std::string& val)
{
	FCOImpl::getAttribute("UUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::PackageConfigurationImpl::setlabel( const std::string& val)
{
	FCOImpl::getAttribute("label")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PrivateFlagImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PrivateFlag
	bool rv = pVisitor->visitPrivateFlag( PICML::PrivateFlag( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MakeMemberPrivate> PICML::PrivateFlagImpl::getInMakeMemberPrivateLinks()
{
	std::set<PICML::MakeMemberPrivate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MakeMemberPrivate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::Members
//********************************************************************************
std::multiset<PICML::Member> PICML::PrivateFlagImpl::getMakeMemberPrivateSrcs()
{
	std::multiset<PICML::Member> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MakeMemberPrivate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::Member dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PublishConnectorImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PublishConnector
	bool rv = pVisitor->visitPublishConnector( PICML::PublishConnector( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Requirements
//********************************************************************************
std::multiset<PICML::Requirement> PICML::PublishConnectorImpl::getAssemblyDeployRequirementDsts()
{
	std::multiset<PICML::Requirement> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AssemblyDeployRequirement");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Requirement dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::publish> PICML::PublishConnectorImpl::getInpublishLinks()
{
	std::set<PICML::publish> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::publish c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AssemblyDeployRequirement> PICML::PublishConnectorImpl::getOutAssemblyDeployRequirementLinks()
{
	std::set<PICML::AssemblyDeployRequirement> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AssemblyDeployRequirement c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::deliverTo> PICML::PublishConnectorImpl::getOutdeliverToLinks()
{
	std::set<PICML::deliverTo> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::deliverTo c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::InEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::PublishConnectorImpl::getdeliverToDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("deliverTo");
}


//********************************************************************************
// returns src PICML::OutEventPorts and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::PublishConnectorImpl::getpublishSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("publish");
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ServiceConsumerImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ServiceConsumer
	bool rv = pVisitor->visitServiceConsumer( PICML::ServiceConsumer( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ServiceConsumerImpl::isprioritize_service_invocations()
{
	return FCOImpl::getAttribute("prioritize_service_invocations")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ServiceConsumerImpl::setprioritize_service_invocations( bool val)
{
	FCOImpl::getAttribute("prioritize_service_invocations")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ServiceLevelsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ServiceLevels
	bool rv = pVisitor->visitServiceLevels( PICML::ServiceLevels( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ServiceLevelsImpl::isvarying_service_levels()
{
	return FCOImpl::getAttribute("varying_service_levels")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ServiceLevelsImpl::setvarying_service_levels( bool val)
{
	FCOImpl::getAttribute("varying_service_levels")->setBooleanValue( val);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TaskImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Task
	bool rv = pVisitor->visitTask( PICML::Task( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::WorkLoadOperationConnection> PICML::TaskImpl::getInWorkLoadOperationConnectionLinks()
{
	std::set<PICML::WorkLoadOperationConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::WorkLoadOperationConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::OperationRefs
//********************************************************************************
std::multiset<PICML::OperationRef> PICML::TaskImpl::getWorkLoadOperationConnectionSrcs()
{
	std::multiset<PICML::OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("WorkLoadOperationConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TimeProbeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TimeProbe
	bool rv = pVisitor->visitTimeProbe( PICML::TimeProbe( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::TimerConnection> PICML::TimeProbeImpl::getInTimerConnectionLinks()
{
	std::set<PICML::TimerConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::TimerConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::TimerEventSinkConn> PICML::TimeProbeImpl::getInTimerEventSinkConnLinks()
{
	std::set<PICML::TimerEventSinkConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::TimerEventSinkConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::OperationRefs
//********************************************************************************
std::multiset<PICML::OperationRef> PICML::TimeProbeImpl::getTimerConnectionSrcs()
{
	std::multiset<PICML::OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("TimerConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::EventRefs
//********************************************************************************
std::multiset<PICML::EventRef> PICML::TimeProbeImpl::getTimerEventSinkConnSrcs()
{
	std::multiset<PICML::EventRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("TimerEventSinkConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::EventRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TopLevelPackageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TopLevelPackage
	bool rv = pVisitor->visitTopLevelPackage( PICML::TopLevelPackage( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::package> PICML::TopLevelPackageImpl::getOutpackageLinks()
{
	std::set<PICML::package> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::package c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::PackageConfigurationReferences
//********************************************************************************
std::multiset<PICML::PackageConfigurationReference> PICML::TopLevelPackageImpl::getpackageDsts()
{
	std::multiset<PICML::PackageConfigurationReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("package");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::PackageConfigurationReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ArtifactDependencyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ArtifactDependency
	bool rv = pVisitor->visitArtifactDependency( PICML::ArtifactDependency( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ImplementationArtifact
//********************************************************************************
PICML::ImplementationArtifact PICML::ArtifactDependencyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ImplementationArtifact
//********************************************************************************
PICML::ImplementationArtifact PICML::ArtifactDependencyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ArtifactDependsOnImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ArtifactDependsOn
	bool rv = pVisitor->visitArtifactDependsOn( PICML::ArtifactDependsOn( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ImplementationArtifactReference
//********************************************************************************
PICML::ImplementationArtifactReference PICML::ArtifactDependsOnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ImplementationArtifactReference sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifactReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ImplementationArtifact
//********************************************************************************
PICML::ImplementationArtifact PICML::ArtifactDependsOnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ArtifactDeployRequirementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ArtifactDeployRequirement
	bool rv = pVisitor->visitArtifactDeployRequirement( PICML::ArtifactDeployRequirement( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Requirement
//********************************************************************************
PICML::Requirement PICML::ArtifactDeployRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Requirement sp( ce);
	if ( sp)
		return sp;

	PICML::Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ImplementationArtifact
//********************************************************************************
PICML::ImplementationArtifact PICML::ArtifactDeployRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ArtifactExecParameterImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ArtifactExecParameter
	bool rv = pVisitor->visitArtifactExecParameter( PICML::ArtifactExecParameter( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::ArtifactExecParameterImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ImplementationArtifact
//********************************************************************************
PICML::ImplementationArtifact PICML::ArtifactExecParameterImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ArtifactInfoPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ArtifactInfoProperty
	bool rv = pVisitor->visitArtifactInfoProperty( PICML::ArtifactInfoProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::ArtifactInfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ImplementationArtifact
//********************************************************************************
PICML::ImplementationArtifact PICML::ArtifactInfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ImplementationArtifact sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifact empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AssemblyConfigPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AssemblyConfigProperty
	bool rv = pVisitor->visitAssemblyConfigProperty( PICML::AssemblyConfigProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::AssemblyConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Component
//********************************************************************************
PICML::Component PICML::AssemblyConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Component sp( ce);
	if ( sp)
		return sp;

	PICML::Component empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AssemblyDeployRequirementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AssemblyDeployRequirement
	bool rv = pVisitor->visitAssemblyDeployRequirement( PICML::AssemblyDeployRequirement( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Requirement
//********************************************************************************
PICML::Requirement PICML::AssemblyDeployRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Requirement sp( ce);
	if ( sp)
		return sp;

	PICML::Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::PublishConnector
//********************************************************************************
PICML::PublishConnector PICML::AssemblyDeployRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::PublishConnector sp( ce);
	if ( sp)
		return sp;

	PICML::PublishConnector empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AssemblyselectRequirementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AssemblyselectRequirement
	bool rv = pVisitor->visitAssemblyselectRequirement( PICML::AssemblyselectRequirement( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Requirement
//********************************************************************************
PICML::Requirement PICML::AssemblyselectRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Requirement sp( ce);
	if ( sp)
		return sp;

	PICML::Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Component
//********************************************************************************
PICML::Component PICML::AssemblyselectRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Component sp( ce);
	if ( sp)
		return sp;

	PICML::Component empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AttributeDelegateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AttributeDelegate
	bool rv = pVisitor->visitAttributeDelegate( PICML::AttributeDelegate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::AttributeDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::AttributeDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AttributeMappingDelegateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AttributeMappingDelegate
	bool rv = pVisitor->visitAttributeMappingDelegate( PICML::AttributeMappingDelegate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::AttributeMappingDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::AttributeMappingDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AttributeMappingValueImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AttributeMappingValue
	bool rv = pVisitor->visitAttributeMappingValue( PICML::AttributeMappingValue( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::AttributeMappingValueImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::AttributeMappingValueImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AttributeValueImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AttributeValue
	bool rv = pVisitor->visitAttributeValue( PICML::AttributeValue( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::AttributeValueImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::AttributeValueImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BenchmarkCharacteristicsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::BenchmarkCharacteristics
	bool rv = pVisitor->visitBenchmarkCharacteristics( PICML::BenchmarkCharacteristics( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::MetricsBase
//********************************************************************************
PICML::MetricsBase PICML::BenchmarkCharacteristicsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::MetricsBase sp( ce);
	if ( sp)
		return sp;

	PICML::MetricsBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::BenchmarkType
//********************************************************************************
PICML::BenchmarkType PICML::BenchmarkCharacteristicsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::BenchmarkType sp( ce);
	if ( sp)
		return sp;

	PICML::BenchmarkType empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::BindingPortTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::BindingPortType
	bool rv = pVisitor->visitBindingPortType( WSML::BindingPortType( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::PortType
//********************************************************************************
WSML::PortType WSML::BindingPortTypeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::PortType sp( ce);
	if ( sp)
		return sp;

	WSML::PortType empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::Binding
//********************************************************************************
WSML::Binding WSML::BindingPortTypeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::Binding sp( ce);
	if ( sp)
		return sp;

	WSML::Binding empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::BindsOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::BindsOperation
	bool rv = pVisitor->visitBindsOperation( WSML::BindsOperation( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::OperationRef
//********************************************************************************
WSML::OperationRef WSML::BindsOperationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::OperationRef sp( ce);
	if ( sp)
		return sp;

	WSML::OperationRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::BindingOperation
//********************************************************************************
WSML::BindingOperation WSML::BindsOperationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::BindingOperation sp( ce);
	if ( sp)
		return sp;

	WSML::BindingOperation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::BodyBindingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::BodyBinding
	bool rv = pVisitor->visitBodyBinding( WSML::BodyBinding( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::SOAPBody
//********************************************************************************
WSML::SOAPBody WSML::BodyBindingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::SOAPBody sp( ce);
	if ( sp)
		return sp;

	WSML::SOAPBody empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::IORef
//********************************************************************************
WSML::IORef WSML::BodyBindingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::IORef sp( ce);
	if ( sp)
		return sp;

	WSML::IORef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::BodyPartsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::BodyParts
	bool rv = pVisitor->visitBodyParts( WSML::BodyParts( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::PartRef
//********************************************************************************
WSML::PartRef WSML::BodyPartsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::PartRef sp( ce);
	if ( sp)
		return sp;

	WSML::PartRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::SOAPBody
//********************************************************************************
WSML::SOAPBody WSML::BodyPartsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::SOAPBody sp( ce);
	if ( sp)
		return sp;

	WSML::SOAPBody empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::BranchTransitionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::BranchTransition
	bool rv = pVisitor->visitBranchTransition( PICML::BranchTransition( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::BranchTransitionImpl::getPrecondition()
{
	return FCOImpl::getAttribute("Precondition")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::BranchTransitionImpl::setPrecondition( const std::string& val)
{
	FCOImpl::getAttribute("Precondition")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ActionBase
//********************************************************************************
PICML::ActionBase PICML::BranchTransitionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ActionBase sp( ce);
	if ( sp)
		return sp;

	PICML::ActionBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::BranchState
//********************************************************************************
PICML::BranchState PICML::BranchTransitionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::BranchState sp( ce);
	if ( sp)
		return sp;

	PICML::BranchState empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::Bridge2InterconnectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Bridge2Interconnect
	bool rv = pVisitor->visitBridge2Interconnect( PICML::Bridge2Interconnect( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Interconnect
//********************************************************************************
PICML::Interconnect PICML::Bridge2InterconnectImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Interconnect sp( ce);
	if ( sp)
		return sp;

	PICML::Interconnect empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Bridge
//********************************************************************************
PICML::Bridge PICML::Bridge2InterconnectImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Bridge sp( ce);
	if ( sp)
		return sp;

	PICML::Bridge empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentConfigPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentConfigProperty
	bool rv = pVisitor->visitComponentConfigProperty( PICML::ComponentConfigProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::ComponentConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentRef
//********************************************************************************
PICML::ComponentRef PICML::ComponentConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentRef sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentInfoPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentInfoProperty
	bool rv = pVisitor->visitComponentInfoProperty( PICML::ComponentInfoProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::ComponentInfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentRef
//********************************************************************************
PICML::ComponentRef PICML::ComponentInfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentRef sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentOperationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentOperation
	bool rv = pVisitor->visitComponentOperation( PICML::ComponentOperation( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::CompRef
//********************************************************************************
PICML::CompRef PICML::ComponentOperationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::CompRef sp( ce);
	if ( sp)
		return sp;

	PICML::CompRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::OperationRef
//********************************************************************************
PICML::OperationRef PICML::ComponentOperationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::OperationRef sp( ce);
	if ( sp)
		return sp;

	PICML::OperationRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentProperty
	bool rv = pVisitor->visitComponentProperty( PICML::ComponentProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ComponentPropertyDescription
//********************************************************************************
PICML::ComponentPropertyDescription PICML::ComponentPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ComponentPropertyDescription sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentPropertyDescription empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentRef
//********************************************************************************
PICML::ComponentRef PICML::ComponentPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentRef sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ConfigPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ConfigProperty
	bool rv = pVisitor->visitConfigProperty( PICML::ConfigProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::ConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentImplementation
//********************************************************************************
PICML::ComponentImplementation PICML::ConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::Consumer2BehaviorConnectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Consumer2BehaviorConnection
	bool rv = pVisitor->visitConsumer2BehaviorConnection( PICML::Consumer2BehaviorConnection( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ECBehavior
//********************************************************************************
PICML::ECBehavior PICML::Consumer2BehaviorConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ECBehavior sp( ce);
	if ( sp)
		return sp;

	PICML::ECBehavior empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ECConsumer
//********************************************************************************
PICML::ECConsumer PICML::Consumer2BehaviorConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ECConsumer sp( ce);
	if ( sp)
		return sp;

	PICML::ECConsumer empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CriticalPathImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::CriticalPath
	bool rv = pVisitor->visitCriticalPath( PICML::CriticalPath( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::PathReference
//********************************************************************************
PICML::PathReference PICML::CriticalPathImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::PathReference sp( ce);
	if ( sp)
		return sp;

	PICML::PathReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentAssembly
//********************************************************************************
PICML::ComponentAssembly PICML::CriticalPathImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentAssembly sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentAssembly empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DstEdgeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::DstEdge
	bool rv = pVisitor->visitDstEdge( PICML::DstEdge( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Edge
//********************************************************************************
PICML::Edge PICML::DstEdgeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Edge sp( ce);
	if ( sp)
		return sp;

	PICML::Edge empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::DstEdgeImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EdgePropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::EdgeProperty
	bool rv = pVisitor->visitEdgeProperty( PICML::EdgeProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Edge
//********************************************************************************
PICML::Edge PICML::EdgePropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Edge sp( ce);
	if ( sp)
		return sp;

	PICML::Edge empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::EdgePropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EffectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Effect
	bool rv = pVisitor->visitEffect( PICML::Effect( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::EffectImpl::getPostcondition()
{
	return FCOImpl::getAttribute("Postcondition")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::EffectImpl::setPostcondition( const std::string& val)
{
	FCOImpl::getAttribute("Postcondition")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::StateBase
//********************************************************************************
PICML::StateBase PICML::EffectImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::StateBase sp( ce);
	if ( sp)
		return sp;

	PICML::StateBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ActionBase
//********************************************************************************
PICML::ActionBase PICML::EffectImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ActionBase sp( ce);
	if ( sp)
		return sp;

	PICML::ActionBase empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EventSinkDelegateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::EventSinkDelegate
	bool rv = pVisitor->visitEventSinkDelegate( PICML::EventSinkDelegate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::EventSinkDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::EventSinkDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EventSourceDelegateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::EventSourceDelegate
	bool rv = pVisitor->visitEventSourceDelegate( PICML::EventSourceDelegate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::EventSourceDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::EventSourceDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ExtResourceConnImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ExtResourceConn
	bool rv = pVisitor->visitExtResourceConn( PICML::ExtResourceConn( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ExternalResources
//********************************************************************************
PICML::ExternalResources PICML::ExtResourceConnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ExternalResources sp( ce);
	if ( sp)
		return sp;

	PICML::ExternalResources empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentLib
//********************************************************************************
PICML::ComponentLib PICML::ExtResourceConnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentLib sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentLib empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ExternalDelegateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ExternalDelegate
	bool rv = pVisitor->visitExternalDelegate( PICML::ExternalDelegate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ExternalReferenceEndPoint
//********************************************************************************
PICML::ExternalReferenceEndPoint PICML::ExternalDelegateImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ExternalReferenceEndPoint sp( ce);
	if ( sp)
		return sp;

	PICML::ExternalReferenceEndPoint empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Component
//********************************************************************************
PICML::Component PICML::ExternalDelegateImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Component sp( ce);
	if ( sp)
		return sp;

	PICML::Component empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::FacetDelegateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::FacetDelegate
	bool rv = pVisitor->visitFacetDelegate( PICML::FacetDelegate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::FacetDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::FacetDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool WSML::FaultMessageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::FaultMessage
	bool rv = pVisitor->visitFaultMessage( WSML::FaultMessage( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::MessageRef
//********************************************************************************
WSML::MessageRef WSML::FaultMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::MessageRef sp( ce);
	if ( sp)
		return sp;

	WSML::MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::Fault
//********************************************************************************
WSML::Fault WSML::FaultMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::Fault sp( ce);
	if ( sp)
		return sp;

	WSML::Fault empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::FinishImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Finish
	bool rv = pVisitor->visitFinish( PICML::Finish( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::FinishImpl::getPostcondition()
{
	return FCOImpl::getAttribute("Postcondition")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::FinishImpl::setPostcondition( const std::string& val)
{
	FCOImpl::getAttribute("Postcondition")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::InputAction
//********************************************************************************
PICML::InputAction PICML::FinishImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::InputAction sp( ce);
	if ( sp)
		return sp;

	PICML::InputAction empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::StateBase
//********************************************************************************
PICML::StateBase PICML::FinishImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::StateBase sp( ce);
	if ( sp)
		return sp;

	PICML::StateBase empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::HeaderBindingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::HeaderBinding
	bool rv = pVisitor->visitHeaderBinding( WSML::HeaderBinding( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::SOAPHeaders
//********************************************************************************
WSML::SOAPHeaders WSML::HeaderBindingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::SOAPHeaders sp( ce);
	if ( sp)
		return sp;

	WSML::SOAPHeaders empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::IORef
//********************************************************************************
WSML::IORef WSML::HeaderBindingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::IORef sp( ce);
	if ( sp)
		return sp;

	WSML::IORef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::HeaderMessageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::HeaderMessage
	bool rv = pVisitor->visitHeaderMessage( WSML::HeaderMessage( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::MessageRef
//********************************************************************************
WSML::MessageRef WSML::HeaderMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::MessageRef sp( ce);
	if ( sp)
		return sp;

	WSML::MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::SOAPHeaders
//********************************************************************************
WSML::SOAPHeaders WSML::HeaderMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::SOAPHeaders sp( ce);
	if ( sp)
		return sp;

	WSML::SOAPHeaders empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::HeaderPartImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::HeaderPart
	bool rv = pVisitor->visitHeaderPart( WSML::HeaderPart( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::PartRef
//********************************************************************************
WSML::PartRef WSML::HeaderPartImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::PartRef sp( ce);
	if ( sp)
		return sp;

	WSML::PartRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::SOAPHeaders
//********************************************************************************
WSML::SOAPHeaders WSML::HeaderPartImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::SOAPHeaders sp( ce);
	if ( sp)
		return sp;

	WSML::SOAPHeaders empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Implementation
	bool rv = pVisitor->visitImplementation( PICML::Implementation( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ComponentImplementationReference
//********************************************************************************
PICML::ComponentImplementationReference PICML::ImplementationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ComponentImplementationReference sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentImplementationReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentPackage
//********************************************************************************
PICML::ComponentPackage PICML::ImplementationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentPackage sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentPackage empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationCapabilityImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ImplementationCapability
	bool rv = pVisitor->visitImplementationCapability( PICML::ImplementationCapability( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Capability
//********************************************************************************
PICML::Capability PICML::ImplementationCapabilityImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Capability sp( ce);
	if ( sp)
		return sp;

	PICML::Capability empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentImplementation
//********************************************************************************
PICML::ComponentImplementation PICML::ImplementationCapabilityImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationDependsOnImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ImplementationDependsOn
	bool rv = pVisitor->visitImplementationDependsOn( PICML::ImplementationDependsOn( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ImplementationDependency
//********************************************************************************
PICML::ImplementationDependency PICML::ImplementationDependsOnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ImplementationDependency sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationDependency empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentImplementation
//********************************************************************************
PICML::ComponentImplementation PICML::ImplementationDependsOnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Implements
	bool rv = pVisitor->visitImplements( PICML::Implements( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ComponentRef
//********************************************************************************
PICML::ComponentRef PICML::ImplementsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ComponentRef sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentImplementation
//********************************************************************************
PICML::ComponentImplementation PICML::ImplementsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InfoPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InfoProperty
	bool rv = pVisitor->visitInfoProperty( PICML::InfoProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::InfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentImplementation
//********************************************************************************
PICML::ComponentImplementation PICML::InfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InputImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Input
	bool rv = pVisitor->visitInput( PICML::Input( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::InputAction
//********************************************************************************
PICML::InputAction PICML::InputImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::InputAction sp( ce);
	if ( sp)
		return sp;

	PICML::InputAction empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::SingleInputBase
//********************************************************************************
PICML::SingleInputBase PICML::InputImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::SingleInputBase sp( ce);
	if ( sp)
		return sp;

	PICML::SingleInputBase empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InputEffectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InputEffect
	bool rv = pVisitor->visitInputEffect( PICML::InputEffect( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::InputEffectImpl::getPostcondition()
{
	return FCOImpl::getAttribute("Postcondition")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::InputEffectImpl::setPostcondition( const std::string& val)
{
	FCOImpl::getAttribute("Postcondition")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::StateBase
//********************************************************************************
PICML::StateBase PICML::InputEffectImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::StateBase sp( ce);
	if ( sp)
		return sp;

	PICML::StateBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::InputAction
//********************************************************************************
PICML::InputAction PICML::InputEffectImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::InputAction sp( ce);
	if ( sp)
		return sp;

	PICML::InputAction empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::InputMessageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::InputMessage
	bool rv = pVisitor->visitInputMessage( WSML::InputMessage( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::MessageRef
//********************************************************************************
WSML::MessageRef WSML::InputMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::MessageRef sp( ce);
	if ( sp)
		return sp;

	WSML::MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::Input
//********************************************************************************
WSML::Input WSML::InputMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::Input sp( ce);
	if ( sp)
		return sp;

	WSML::Input empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InstanceMappingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InstanceMapping
	bool rv = pVisitor->visitInstanceMapping( PICML::InstanceMapping( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::NodeReference
//********************************************************************************
PICML::NodeReference PICML::InstanceMappingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::NodeReference sp( ce);
	if ( sp)
		return sp;

	PICML::NodeReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::CollocationGroup
//********************************************************************************
PICML::CollocationGroup PICML::InstanceMappingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::CollocationGroup sp( ce);
	if ( sp)
		return sp;

	PICML::CollocationGroup empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::Interconnect2BridgeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Interconnect2Bridge
	bool rv = pVisitor->visitInterconnect2Bridge( PICML::Interconnect2Bridge( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Bridge
//********************************************************************************
PICML::Bridge PICML::Interconnect2BridgeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Bridge sp( ce);
	if ( sp)
		return sp;

	PICML::Bridge empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Interconnect
//********************************************************************************
PICML::Interconnect PICML::Interconnect2BridgeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Interconnect sp( ce);
	if ( sp)
		return sp;

	PICML::Interconnect empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::Interconnect2NodeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Interconnect2Node
	bool rv = pVisitor->visitInterconnect2Node( PICML::Interconnect2Node( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Node
//********************************************************************************
PICML::Node PICML::Interconnect2NodeImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Node sp( ce);
	if ( sp)
		return sp;

	PICML::Node empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Interconnect
//********************************************************************************
PICML::Interconnect PICML::Interconnect2NodeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Interconnect sp( ce);
	if ( sp)
		return sp;

	PICML::Interconnect empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::LabelConnectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::LabelConnection
	bool rv = pVisitor->visitLabelConnection( PICML::LabelConnection( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Label
//********************************************************************************
PICML::Label PICML::LabelConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Label sp( ce);
	if ( sp)
		return sp;

	PICML::Label empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Member
//********************************************************************************
PICML::Member PICML::LabelConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Member sp( ce);
	if ( sp)
		return sp;

	PICML::Member empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MakeMemberPrivateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MakeMemberPrivate
	bool rv = pVisitor->visitMakeMemberPrivate( PICML::MakeMemberPrivate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::PrivateFlag
//********************************************************************************
PICML::PrivateFlag PICML::MakeMemberPrivateImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::PrivateFlag sp( ce);
	if ( sp)
		return sp;

	PICML::PrivateFlag empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Member
//********************************************************************************
PICML::Member PICML::MakeMemberPrivateImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Member sp( ce);
	if ( sp)
		return sp;

	PICML::Member empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ManagesComponentImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ManagesComponent
	bool rv = pVisitor->visitManagesComponent( PICML::ManagesComponent( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Manageable
//********************************************************************************
PICML::Manageable PICML::ManagesComponentImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Manageable sp( ce);
	if ( sp)
		return sp;

	PICML::Manageable empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentFactory
//********************************************************************************
PICML::ComponentFactory PICML::ManagesComponentImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentFactory sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentFactory empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MetricConnectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MetricConnection
	bool rv = pVisitor->visitMetricConnection( PICML::MetricConnection( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::MetricsBase
//********************************************************************************
PICML::MetricsBase PICML::MetricConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::MetricsBase sp( ce);
	if ( sp)
		return sp;

	PICML::MetricsBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::OperationRef
//********************************************************************************
PICML::OperationRef PICML::MetricConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::OperationRef sp( ce);
	if ( sp)
		return sp;

	PICML::OperationRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MonolithDeployRequirementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MonolithDeployRequirement
	bool rv = pVisitor->visitMonolithDeployRequirement( PICML::MonolithDeployRequirement( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ImplementationRequirement
//********************************************************************************
PICML::ImplementationRequirement PICML::MonolithDeployRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ImplementationRequirement sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationRequirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::MonolithicImplementation
//********************************************************************************
PICML::MonolithicImplementation PICML::MonolithDeployRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::MonolithicImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::MonolithicImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MonolithExecParameterImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MonolithExecParameter
	bool rv = pVisitor->visitMonolithExecParameter( PICML::MonolithExecParameter( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::MonolithExecParameterImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::MonolithicImplementation
//********************************************************************************
PICML::MonolithicImplementation PICML::MonolithExecParameterImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::MonolithicImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::MonolithicImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MonolithprimaryArtifactImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MonolithprimaryArtifact
	bool rv = pVisitor->visitMonolithprimaryArtifact( PICML::MonolithprimaryArtifact( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ImplementationArtifactReference
//********************************************************************************
PICML::ImplementationArtifactReference PICML::MonolithprimaryArtifactImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ImplementationArtifactReference sp( ce);
	if ( sp)
		return sp;

	PICML::ImplementationArtifactReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::MonolithicImplementation
//********************************************************************************
PICML::MonolithicImplementation PICML::MonolithprimaryArtifactImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::MonolithicImplementation sp( ce);
	if ( sp)
		return sp;

	PICML::MonolithicImplementation empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MultiInputImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::MultiInput
	bool rv = pVisitor->visitMultiInput( PICML::MultiInput( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::InputAction
//********************************************************************************
PICML::InputAction PICML::MultiInputImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::InputAction sp( ce);
	if ( sp)
		return sp;

	PICML::InputAction empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::MultiInputBase
//********************************************************************************
PICML::MultiInputBase PICML::MultiInputImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::MultiInputBase sp( ce);
	if ( sp)
		return sp;

	PICML::MultiInputBase empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::Node2InterconnectImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Node2Interconnect
	bool rv = pVisitor->visitNode2Interconnect( PICML::Node2Interconnect( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Interconnect
//********************************************************************************
PICML::Interconnect PICML::Node2InterconnectImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Interconnect sp( ce);
	if ( sp)
		return sp;

	PICML::Interconnect empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Node
//********************************************************************************
PICML::Node PICML::Node2InterconnectImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Node sp( ce);
	if ( sp)
		return sp;

	PICML::Node empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::OutputMessageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::OutputMessage
	bool rv = pVisitor->visitOutputMessage( WSML::OutputMessage( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::MessageRef
//********************************************************************************
WSML::MessageRef WSML::OutputMessageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::MessageRef sp( ce);
	if ( sp)
		return sp;

	WSML::MessageRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::Output
//********************************************************************************
WSML::Output WSML::OutputMessageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::Output sp( ce);
	if ( sp)
		return sp;

	WSML::Output empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfBasePackageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfBasePackage
	bool rv = pVisitor->visitPackageConfBasePackage( PICML::PackageConfBasePackage( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ComponentPackage
//********************************************************************************
PICML::ComponentPackage PICML::PackageConfBasePackageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ComponentPackage sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentPackage empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::PackageConfiguration
//********************************************************************************
PICML::PackageConfiguration PICML::PackageConfBasePackageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::PackageConfiguration empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfConfigPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfConfigProperty
	bool rv = pVisitor->visitPackageConfConfigProperty( PICML::PackageConfConfigProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::PackageConfConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::PackageConfiguration
//********************************************************************************
PICML::PackageConfiguration PICML::PackageConfConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::PackageConfiguration empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfReference
	bool rv = pVisitor->visitPackageConfReference( PICML::PackageConfReference( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ComponentPackageReference
//********************************************************************************
PICML::ComponentPackageReference PICML::PackageConfReferenceImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ComponentPackageReference sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentPackageReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::PackageConfiguration
//********************************************************************************
PICML::PackageConfiguration PICML::PackageConfReferenceImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::PackageConfiguration empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfSelectRequirementImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfSelectRequirement
	bool rv = pVisitor->visitPackageConfSelectRequirement( PICML::PackageConfSelectRequirement( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Requirement
//********************************************************************************
PICML::Requirement PICML::PackageConfSelectRequirementImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Requirement sp( ce);
	if ( sp)
		return sp;

	PICML::Requirement empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::PackageConfiguration
//********************************************************************************
PICML::PackageConfiguration PICML::PackageConfSelectRequirementImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::PackageConfiguration empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfSpecializedConfigImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfSpecializedConfig
	bool rv = pVisitor->visitPackageConfSpecializedConfig( PICML::PackageConfSpecializedConfig( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::PackageConfigurationReference
//********************************************************************************
PICML::PackageConfigurationReference PICML::PackageConfSpecializedConfigImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::PackageConfigurationReference sp( ce);
	if ( sp)
		return sp;

	PICML::PackageConfigurationReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::PackageConfiguration
//********************************************************************************
PICML::PackageConfiguration PICML::PackageConfSpecializedConfigImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::PackageConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::PackageConfiguration empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfigPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfigProperty
	bool rv = pVisitor->visitPackageConfigProperty( PICML::PackageConfigProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::PackageConfigPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentPackage
//********************************************************************************
PICML::ComponentPackage PICML::PackageConfigPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentPackage sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentPackage empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageInfoPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageInfoProperty
	bool rv = pVisitor->visitPackageInfoProperty( PICML::PackageInfoProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::PackageInfoPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentPackage
//********************************************************************************
PICML::ComponentPackage PICML::PackageInfoPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentPackage sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentPackage empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageInterfaceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageInterface
	bool rv = pVisitor->visitPackageInterface( PICML::PackageInterface( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ComponentRef
//********************************************************************************
PICML::ComponentRef PICML::PackageInterfaceImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ComponentRef sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ComponentPackage
//********************************************************************************
PICML::ComponentPackage PICML::PackageInterfaceImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ComponentPackage sp( ce);
	if ( sp)
		return sp;

	PICML::ComponentPackage empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PathPropertyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PathProperty
	bool rv = pVisitor->visitPathProperty( PICML::PathProperty( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Property
//********************************************************************************
PICML::Property PICML::PathPropertyImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Property sp( ce);
	if ( sp)
		return sp;

	PICML::Property empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Path
//********************************************************************************
PICML::Path PICML::PathPropertyImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Path sp( ce);
	if ( sp)
		return sp;

	PICML::Path empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::PortBindingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::PortBinding
	bool rv = pVisitor->visitPortBinding( WSML::PortBinding( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::BindingRef
//********************************************************************************
WSML::BindingRef WSML::PortBindingImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::BindingRef sp( ce);
	if ( sp)
		return sp;

	WSML::BindingRef empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::Port
//********************************************************************************
WSML::Port WSML::PortBindingImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::Port sp( ce);
	if ( sp)
		return sp;

	WSML::Port empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool SIML::PortProxyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the SIML::PortProxy
	bool rv = pVisitor->visitPortProxy( SIML::PortProxy( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
SIML::PortProxyImpl::mapping_Type SIML::PortProxyImpl::getmapping()
{
	std::string val = FCOImpl::getAttribute("mapping")->getStringValue();

	if ( val == "ASP_NET") return ASP_NET_mapping_Type;
	else if ( val == "gSOAP") return gSOAP_mapping_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void SIML::PortProxyImpl::setmapping( PortProxyImpl::mapping_Type val)
{
	std::string str_val = "";

	if ( val == ASP_NET_mapping_Type) str_val = "ASP_NET";
	else if ( val == gSOAP_mapping_Type) str_val = "gSOAP";
	else throw("None of the possible items");

	FCOImpl::getAttribute("mapping")->setStringValue( str_val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd SIML::PortProxyImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd SIML::PortProxyImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ReceptacleDelegateImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ReceptacleDelegate
	bool rv = pVisitor->visitReceptacleDelegate( PICML::ReceptacleDelegate( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::ReceptacleDelegateImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::ReceptacleDelegateImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::RecursiveFilterConnectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::RecursiveFilterConnection
	bool rv = pVisitor->visitRecursiveFilterConnection( PICML::RecursiveFilterConnection( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ECEventFilterConfiguration
//********************************************************************************
PICML::ECEventFilterConfiguration PICML::RecursiveFilterConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ECEventFilterConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::ECEventFilterConfiguration empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ECEventFilterConfiguration
//********************************************************************************
PICML::ECEventFilterConfiguration PICML::RecursiveFilterConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ECEventFilterConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::ECEventFilterConfiguration empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool WSML::SOAPFaultExtensionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::SOAPFaultExtension
	bool rv = pVisitor->visitSOAPFaultExtension( WSML::SOAPFaultExtension( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to WSML::SOAPFault
//********************************************************************************
WSML::SOAPFault WSML::SOAPFaultExtensionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	WSML::SOAPFault sp( ce);
	if ( sp)
		return sp;

	WSML::SOAPFault empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to WSML::FaultRef
//********************************************************************************
WSML::FaultRef WSML::SOAPFaultExtensionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	WSML::FaultRef sp( ce);
	if ( sp)
		return sp;

	WSML::FaultRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SharesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Shares
	bool rv = pVisitor->visitShares( PICML::Shares( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::SharedResource
//********************************************************************************
PICML::SharedResource PICML::SharesImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::SharedResource sp( ce);
	if ( sp)
		return sp;

	PICML::SharedResource empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Node
//********************************************************************************
PICML::Node PICML::SharesImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Node sp( ce);
	if ( sp)
		return sp;

	PICML::Node empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SrcEdgeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SrcEdge
	bool rv = pVisitor->visitSrcEdge( PICML::SrcEdge( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::SrcEdgeImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::Edge
//********************************************************************************
PICML::Edge PICML::SrcEdgeImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::Edge sp( ce);
	if ( sp)
		return sp;

	PICML::Edge empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::Supplier2FilterConnectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Supplier2FilterConnection
	bool rv = pVisitor->visitSupplier2FilterConnection( PICML::Supplier2FilterConnection( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ECEventFilterConfiguration
//********************************************************************************
PICML::ECEventFilterConfiguration PICML::Supplier2FilterConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ECEventFilterConfiguration sp( ce);
	if ( sp)
		return sp;

	PICML::ECEventFilterConfiguration empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::ECSupplier
//********************************************************************************
PICML::ECSupplier PICML::Supplier2FilterConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::ECSupplier sp( ce);
	if ( sp)
		return sp;

	PICML::ECSupplier empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TimerConnectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TimerConnection
	bool rv = pVisitor->visitTimerConnection( PICML::TimerConnection( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::TimeProbe
//********************************************************************************
PICML::TimeProbe PICML::TimerConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::TimeProbe sp( ce);
	if ( sp)
		return sp;

	PICML::TimeProbe empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::OperationRef
//********************************************************************************
PICML::OperationRef PICML::TimerConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::OperationRef sp( ce);
	if ( sp)
		return sp;

	PICML::OperationRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TimerEventSinkConnImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TimerEventSinkConn
	bool rv = pVisitor->visitTimerEventSinkConn( PICML::TimerEventSinkConn( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::TimeProbe
//********************************************************************************
PICML::TimeProbe PICML::TimerEventSinkConnImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::TimeProbe sp( ce);
	if ( sp)
		return sp;

	PICML::TimeProbe empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::EventRef
//********************************************************************************
PICML::EventRef PICML::TimerEventSinkConnImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::EventRef sp( ce);
	if ( sp)
		return sp;

	PICML::EventRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TransitionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Transition
	bool rv = pVisitor->visitTransition( PICML::Transition( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::TransitionImpl::getPrecondition()
{
	return FCOImpl::getAttribute("Precondition")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::TransitionImpl::setPrecondition( const std::string& val)
{
	FCOImpl::getAttribute("Precondition")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::ActionBase
//********************************************************************************
PICML::ActionBase PICML::TransitionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::ActionBase sp( ce);
	if ( sp)
		return sp;

	PICML::ActionBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::State
//********************************************************************************
PICML::State PICML::TransitionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::State sp( ce);
	if ( sp)
		return sp;

	PICML::State empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkLoadOperationConnectionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkLoadOperationConnection
	bool rv = pVisitor->visitWorkLoadOperationConnection( PICML::WorkLoadOperationConnection( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::Task
//********************************************************************************
PICML::Task PICML::WorkLoadOperationConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::Task sp( ce);
	if ( sp)
		return sp;

	PICML::Task empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::OperationRef
//********************************************************************************
PICML::OperationRef PICML::WorkLoadOperationConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::OperationRef sp( ce);
	if ( sp)
		return sp;

	PICML::OperationRef empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkloadCharacteristicsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkloadCharacteristics
	bool rv = pVisitor->visitWorkloadCharacteristics( PICML::WorkloadCharacteristics( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::TaskSet
//********************************************************************************
PICML::TaskSet PICML::WorkloadCharacteristicsImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::TaskSet sp( ce);
	if ( sp)
		return sp;

	PICML::TaskSet empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::MetricsBase
//********************************************************************************
PICML::MetricsBase PICML::WorkloadCharacteristicsImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::MetricsBase sp( ce);
	if ( sp)
		return sp;

	PICML::MetricsBase empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::deliverToImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::deliverTo
	bool rv = pVisitor->visitdeliverTo( PICML::deliverTo( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::deliverToImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::PublishConnector
//********************************************************************************
PICML::PublishConnector PICML::deliverToImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::PublishConnector sp( ce);
	if ( sp)
		return sp;

	PICML::PublishConnector empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::emitImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::emit
	bool rv = pVisitor->visitemit( PICML::emit( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::emitImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::emitImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::invokeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::invoke
	bool rv = pVisitor->visitinvoke( PICML::invoke( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::invokeImpl::getDst()
{
	return ConnectionImpl::getDst();
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::invokeImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::packageImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::package
	bool rv = pVisitor->visitpackage( PICML::package( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::PackageConfigurationReference
//********************************************************************************
PICML::PackageConfigurationReference PICML::packageImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::PackageConfigurationReference sp( ce);
	if ( sp)
		return sp;

	PICML::PackageConfigurationReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to PICML::TopLevelPackage
//********************************************************************************
PICML::TopLevelPackage PICML::packageImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	PICML::TopLevelPackage sp( ce);
	if ( sp)
		return sp;

	PICML::TopLevelPackage empty;
	return empty;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::publishImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::publish
	bool rv = pVisitor->visitpublish( PICML::publish( this));
	return rv;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to PICML::PublishConnector
//********************************************************************************
PICML::PublishConnector PICML::publishImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	PICML::PublishConnector sp( ce);
	if ( sp)
		return sp;

	PICML::PublishConnector empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd
//********************************************************************************
BON::ConnectionEnd PICML::publishImpl::getSrc()
{
	return ConnectionImpl::getSrc();
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CollocationGroupImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::CollocationGroup
	bool rv = pVisitor->visitCollocationGroup( PICML::CollocationGroup( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::NodeReferences
//********************************************************************************
std::multiset<PICML::NodeReference> PICML::CollocationGroupImpl::getInstanceMappingDsts()
{
	std::multiset<PICML::NodeReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("InstanceMapping");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::NodeReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::InstanceMapping> PICML::CollocationGroupImpl::getOutInstanceMappingLinks()
{
	std::set<PICML::InstanceMapping> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::InstanceMapping c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// aggregated getter for setmembers
//********************************************************************************
std::set<BON::Reference> PICML::CollocationGroupImpl::getAllMembers()
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
// specialized getter for PICML::ComponentAssemblyReference setmembers
//********************************************************************************
std::set<PICML::ComponentAssemblyReference> PICML::CollocationGroupImpl::getComponentAssemblyReferences()
{
	std::set<PICML::ComponentAssemblyReference> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		PICML::ComponentAssemblyReference r( *elem);
		if ( r && r->getObjectMeta().name() == "PICML::ComponentAssemblyReference")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for PICML::ComponentRef setmembers
//********************************************************************************
std::set<PICML::ComponentRef> PICML::CollocationGroupImpl::getComponentRefs()
{
	std::set<PICML::ComponentRef> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		PICML::ComponentRef r( *elem);
		if ( r && r->getObjectMeta().name() == "PICML::ComponentRef")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for PICML::SharedComponentReference setmembers
//********************************************************************************
std::set<PICML::SharedComponentReference> PICML::CollocationGroupImpl::getSharedComponentReferences()
{
	std::set<PICML::SharedComponentReference> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		PICML::SharedComponentReference r( *elem);
		if ( r && r->getObjectMeta().name() == "PICML::SharedComponentReference")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::TaskSetImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::TaskSet
	bool rv = pVisitor->visitTaskSet( PICML::TaskSet( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::WorkloadCharacteristics> PICML::TaskSetImpl::getInWorkloadCharacteristicsLinks()
{
	std::set<PICML::WorkloadCharacteristics> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::WorkloadCharacteristics c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::MetricsBases
//********************************************************************************
std::multiset<PICML::MetricsBase> PICML::TaskSetImpl::getWorkloadCharacteristicsSrcs()
{
	std::multiset<PICML::MetricsBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("WorkloadCharacteristics");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::MetricsBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
long PICML::TaskSetImpl::getpriority()
{
	return FCOImpl::getAttribute("priority")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
long PICML::TaskSetImpl::getrate()
{
	return FCOImpl::getAttribute("rate")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::TaskSetImpl::setpriority( const long val)
{
	FCOImpl::getAttribute("priority")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::TaskSetImpl::setrate( const long val)
{
	FCOImpl::getAttribute("rate")->setIntegerValue( val);
}


//********************************************************************************
// aggregated getter for setmembers
//********************************************************************************
std::set<PICML::Task> PICML::TaskSetImpl::getTasks( int dummy)
{
	std::set<PICML::Task> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		PICML::Task r( *elem);
		if ( r)
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for PICML::Task setmembers
//********************************************************************************
std::set<PICML::Task> PICML::TaskSetImpl::getTasks()
{
	std::set<PICML::Task> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		PICML::Task r( *elem);
		if ( r && r->getObjectMeta().name() == "PICML::Task")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkspacesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Workspaces
	bool rv = pVisitor->visitWorkspaces( PICML::Workspaces( this));
	return rv;
}


//********************************************************************************
// aggregated getter for setmembers
//********************************************************************************
std::set<PICML::Project> PICML::WorkspacesImpl::getProjects( int dummy)
{
	std::set<PICML::Project> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		PICML::Project r( *elem);
		if ( r)
			res.insert( r);
	}
	return res;
}


//********************************************************************************
// specialized getter for PICML::Project setmembers
//********************************************************************************
std::set<PICML::Project> PICML::WorkspacesImpl::getProjects()
{
	std::set<PICML::Project> res;
	std::set<BON::FCO> elems = BON::SetImpl::getMembers();
	std::set<BON::FCO>::iterator elem = elems.begin();
	for( ; elem != elems.end(); ++elem)
	{
		PICML::Project r( *elem);
		if ( r && r->getObjectMeta().name() == "PICML::Project")
			res.insert( r);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AttributeMappingImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AttributeMapping
	bool rv = pVisitor->visitAttributeMapping( PICML::AttributeMapping( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::ReadonlyAttributes and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::AttributeMappingImpl::getAttributeDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("AttributeDelegate");
}


//********************************************************************************
// returns dst PICML::AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::AttributeMappingImpl::getAttributeMappingDelegateDsts()
{
	return BON::ConnectionEndImpl::getOutConnEnds("AttributeMappingDelegate");
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeMappingDelegate> PICML::AttributeMappingImpl::getAttributeMappingDelegateLinks()
{
	std::set<PICML::AttributeMappingDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeMappingDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::AttributeMappings and referenceports
//********************************************************************************
std::multiset<BON::ConnectionEnd> PICML::AttributeMappingImpl::getAttributeMappingDelegateSrcs()
{
	return BON::ConnectionEndImpl::getInConnEnds("AttributeMappingDelegate");
}


//********************************************************************************
// returns dst PICML::Propertys
//********************************************************************************
std::multiset<PICML::Property> PICML::AttributeMappingImpl::getAttributeMappingValueDsts()
{
	std::multiset<PICML::Property> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("AttributeMappingValue");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Property dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeMappingDelegate> PICML::AttributeMappingImpl::getInAttributeMappingDelegateLinks()
{
	std::set<PICML::AttributeMappingDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeMappingDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeDelegate> PICML::AttributeMappingImpl::getOutAttributeDelegateLinks()
{
	std::set<PICML::AttributeDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeMappingDelegate> PICML::AttributeMappingImpl::getOutAttributeMappingDelegateLinks()
{
	std::set<PICML::AttributeMappingDelegate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeMappingDelegate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::AttributeMappingValue> PICML::AttributeMappingImpl::getOutAttributeMappingValueLinks()
{
	std::set<PICML::AttributeMappingValue> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::AttributeMappingValue c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
PICML::ReadonlyAttribute PICML::AttributeMappingImpl::getReadonlyAttribute()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ReadonlyAttribute(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::AttributeMemberImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::AttributeMember
	bool rv = pVisitor->visitAttributeMember( PICML::AttributeMember( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::AttributeMemberImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::BindingRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::BindingRef
	bool rv = pVisitor->visitBindingRef( WSML::BindingRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::PortBinding> WSML::BindingRefImpl::getInPortBindingLinks()
{
	std::set<WSML::PortBinding> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::PortBinding c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src WSML::Ports
//********************************************************************************
std::multiset<WSML::Port> WSML::BindingRefImpl::getPortBindingSrcs()
{
	std::multiset<WSML::Port> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PortBinding");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::Port dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
WSML::Binding WSML::BindingRefImpl::getBinding()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Binding(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::CompRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::CompRef
	bool rv = pVisitor->visitCompRef( PICML::CompRef( this));
	return rv;
}


//********************************************************************************
// returns src PICML::OperationRefs
//********************************************************************************
std::multiset<PICML::OperationRef> PICML::CompRefImpl::getComponentOperationSrcs()
{
	std::multiset<PICML::OperationRef> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ComponentOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::OperationRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentOperation> PICML::CompRefImpl::getInComponentOperationLinks()
{
	std::set<PICML::ComponentOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
PICML::Component PICML::CompRefImpl::getComponent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Component(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentAssemblyReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentAssemblyReference
	bool rv = pVisitor->visitComponentAssemblyReference( PICML::ComponentAssemblyReference( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::ComponentAssembly PICML::ComponentAssemblyReferenceImpl::getComponentAssembly()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ComponentAssembly(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentImplementationReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentImplementationReference
	bool rv = pVisitor->visitComponentImplementationReference( PICML::ComponentImplementationReference( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ComponentPackages
//********************************************************************************
std::multiset<PICML::ComponentPackage> PICML::ComponentImplementationReferenceImpl::getImplementationSrcs()
{
	std::multiset<PICML::ComponentPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Implementation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::Implementation> PICML::ComponentImplementationReferenceImpl::getInImplementationLinks()
{
	std::set<PICML::Implementation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::Implementation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
PICML::ComponentImplementation PICML::ComponentImplementationReferenceImpl::getComponentImplementation()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ComponentImplementation(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ComponentPackageReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ComponentPackageReference
	bool rv = pVisitor->visitComponentPackageReference( PICML::ComponentPackageReference( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfReference> PICML::ComponentPackageReferenceImpl::getInPackageConfReferenceLinks()
{
	std::set<PICML::PackageConfReference> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfReference c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::PackageConfigurations
//********************************************************************************
std::multiset<PICML::PackageConfiguration> PICML::ComponentPackageReferenceImpl::getPackageConfReferenceSrcs()
{
	std::multiset<PICML::PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfReference");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentPackageReferenceImpl::getrequiredName()
{
	return FCOImpl::getAttribute("requiredName")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentPackageReferenceImpl::getrequiredType()
{
	return FCOImpl::getAttribute("requiredType")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
std::string PICML::ComponentPackageReferenceImpl::getrequiredUUID()
{
	return FCOImpl::getAttribute("requiredUUID")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentPackageReferenceImpl::setrequiredName( const std::string& val)
{
	FCOImpl::getAttribute("requiredName")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentPackageReferenceImpl::setrequiredType( const std::string& val)
{
	FCOImpl::getAttribute("requiredType")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void PICML::ComponentPackageReferenceImpl::setrequiredUUID( const std::string& val)
{
	FCOImpl::getAttribute("requiredUUID")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
PICML::ComponentPackage PICML::ComponentPackageReferenceImpl::getComponentPackage()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ComponentPackage(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DataTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::DataType
	bool rv = pVisitor->visitDataType( PICML::DataType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::PredefinedType PICML::DataTypeImpl::getPredefinedType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::PredefinedType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::DiscriminatorImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Discriminator
	bool rv = pVisitor->visitDiscriminator( PICML::Discriminator( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::ConstantType PICML::DiscriminatorImpl::getConstantType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ConstantType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::EventRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::EventRef
	bool rv = pVisitor->visitEventRef( PICML::EventRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::TimerEventSinkConn> PICML::EventRefImpl::getOutTimerEventSinkConnLinks()
{
	std::set<PICML::TimerEventSinkConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::TimerEventSinkConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::TimeProbes
//********************************************************************************
std::multiset<PICML::TimeProbe> PICML::EventRefImpl::getTimerEventSinkConnDsts()
{
	std::multiset<PICML::TimeProbe> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("TimerEventSinkConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::TimeProbe dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::Event PICML::EventRefImpl::getEvent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Event(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ExceptionRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ExceptionRef
	bool rv = pVisitor->visitExceptionRef( PICML::ExceptionRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::Exception PICML::ExceptionRefImpl::getException()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Exception(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ExternalResourcesImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ExternalResources
	bool rv = pVisitor->visitExternalResources( PICML::ExternalResources( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ComponentLibs
//********************************************************************************
std::multiset<PICML::ComponentLib> PICML::ExternalResourcesImpl::getExtResourceConnSrcs()
{
	std::multiset<PICML::ComponentLib> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ExtResourceConn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentLib dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ExtResourceConn> PICML::ExternalResourcesImpl::getInExtResourceConnLinks()
{
	std::set<PICML::ExtResourceConn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ExtResourceConn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
PICML::ImplementationArtifact PICML::ExternalResourcesImpl::getImplementationArtifact()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ImplementationArtifact(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::FaultRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::FaultRef
	bool rv = pVisitor->visitFaultRef( WSML::FaultRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::SOAPFaultExtension> WSML::FaultRefImpl::getOutSOAPFaultExtensionLinks()
{
	std::set<WSML::SOAPFaultExtension> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::SOAPFaultExtension c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst WSML::SOAPFaults
//********************************************************************************
std::multiset<WSML::SOAPFault> WSML::FaultRefImpl::getSOAPFaultExtensionDsts()
{
	std::multiset<WSML::SOAPFault> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("SOAPFaultExtension");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			WSML::SOAPFault dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
WSML::Fault WSML::FaultRefImpl::getFault()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Fault(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::FileRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::FileRef
	bool rv = pVisitor->visitFileRef( PICML::FileRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::File PICML::FileRefImpl::getFile()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::File(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::GetExceptionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::GetException
	bool rv = pVisitor->visitGetException( PICML::GetException( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::Exception PICML::GetExceptionImpl::getException()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Exception(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ImplementationArtifactReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ImplementationArtifactReference
	bool rv = pVisitor->visitImplementationArtifactReference( PICML::ImplementationArtifactReference( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ImplementationArtifacts
//********************************************************************************
std::multiset<PICML::ImplementationArtifact> PICML::ImplementationArtifactReferenceImpl::getArtifactDependsOnSrcs()
{
	std::multiset<PICML::ImplementationArtifact> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("ArtifactDependsOn");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ImplementationArtifact dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ArtifactDependsOn> PICML::ImplementationArtifactReferenceImpl::getInArtifactDependsOnLinks()
{
	std::set<PICML::ArtifactDependsOn> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ArtifactDependsOn c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MonolithprimaryArtifact> PICML::ImplementationArtifactReferenceImpl::getInMonolithprimaryArtifactLinks()
{
	std::set<PICML::MonolithprimaryArtifact> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MonolithprimaryArtifact c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::MonolithicImplementations
//********************************************************************************
std::multiset<PICML::MonolithicImplementation> PICML::ImplementationArtifactReferenceImpl::getMonolithprimaryArtifactSrcs()
{
	std::multiset<PICML::MonolithicImplementation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MonolithprimaryArtifact");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::MonolithicImplementation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::ImplementationArtifact PICML::ImplementationArtifactReferenceImpl::getImplementationArtifact()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ImplementationArtifact(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ParameterTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ParameterType
	bool rv = pVisitor->visitParameterType( PICML::ParameterType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::ParameterTypeImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InParameterImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InParameter
	bool rv = pVisitor->visitInParameter( PICML::InParameter( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::InParameterImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InoutParameterImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::InoutParameter
	bool rv = pVisitor->visitInoutParameter( PICML::InoutParameter( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::InoutParameterImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::OutParameterImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::OutParameter
	bool rv = pVisitor->visitOutParameter( PICML::OutParameter( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::OutParameterImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::InheritsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Inherits
	bool rv = pVisitor->visitInherits( PICML::Inherits( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::Inheritable PICML::InheritsImpl::getInheritable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Inheritable(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::LookupKeyImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::LookupKey
	bool rv = pVisitor->visitLookupKey( PICML::LookupKey( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::ValueObject PICML::LookupKeyImpl::getValueObject()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ValueObject(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::MemberImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Member
	bool rv = pVisitor->visitMember( PICML::Member( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::Labels
//********************************************************************************
std::multiset<PICML::Label> PICML::MemberImpl::getLabelConnectionDsts()
{
	std::multiset<PICML::Label> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("LabelConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Label dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::PrivateFlags
//********************************************************************************
std::multiset<PICML::PrivateFlag> PICML::MemberImpl::getMakeMemberPrivateDsts()
{
	std::multiset<PICML::PrivateFlag> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MakeMemberPrivate");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::PrivateFlag dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::LabelConnection> PICML::MemberImpl::getOutLabelConnectionLinks()
{
	std::set<PICML::LabelConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::LabelConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MakeMemberPrivate> PICML::MemberImpl::getOutMakeMemberPrivateLinks()
{
	std::set<PICML::MakeMemberPrivate> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MakeMemberPrivate c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::MemberImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::MessageRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::MessageRef
	bool rv = pVisitor->visitMessageRef( WSML::MessageRef( this));
	return rv;
}


//********************************************************************************
// returns src WSML::Faults
//********************************************************************************
std::multiset<WSML::Fault> WSML::MessageRefImpl::getFaultMessageSrcs()
{
	std::multiset<WSML::Fault> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("FaultMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::Fault dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src WSML::SOAPHeaderss
//********************************************************************************
std::multiset<WSML::SOAPHeaders> WSML::MessageRefImpl::getHeaderMessageSrcs()
{
	std::multiset<WSML::SOAPHeaders> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("HeaderMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::SOAPHeaders dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::FaultMessage> WSML::MessageRefImpl::getInFaultMessageLinks()
{
	std::set<WSML::FaultMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::FaultMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::HeaderMessage> WSML::MessageRefImpl::getInHeaderMessageLinks()
{
	std::set<WSML::HeaderMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::HeaderMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::InputMessage> WSML::MessageRefImpl::getInInputMessageLinks()
{
	std::set<WSML::InputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::InputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::OutputMessage> WSML::MessageRefImpl::getInOutputMessageLinks()
{
	std::set<WSML::OutputMessage> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::OutputMessage c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src WSML::Inputs
//********************************************************************************
std::multiset<WSML::Input> WSML::MessageRefImpl::getInputMessageSrcs()
{
	std::multiset<WSML::Input> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("InputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::Input dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src WSML::Outputs
//********************************************************************************
std::multiset<WSML::Output> WSML::MessageRefImpl::getOutputMessageSrcs()
{
	std::multiset<WSML::Output> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("OutputMessage");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::Output dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
WSML::Message WSML::MessageRefImpl::getMessage()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Message(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::NodeReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::NodeReference
	bool rv = pVisitor->visitNodeReference( PICML::NodeReference( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::InstanceMapping> PICML::NodeReferenceImpl::getInInstanceMappingLinks()
{
	std::set<PICML::InstanceMapping> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::InstanceMapping c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::CollocationGroups
//********************************************************************************
std::multiset<PICML::CollocationGroup> PICML::NodeReferenceImpl::getInstanceMappingSrcs()
{
	std::multiset<PICML::CollocationGroup> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("InstanceMapping");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::CollocationGroup dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::Node PICML::NodeReferenceImpl::getNode()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Node(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::OperationRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::OperationRef
	bool rv = pVisitor->visitOperationRef( WSML::OperationRef( this));
	return rv;
}


//********************************************************************************
// returns src WSML::BindingOperations
//********************************************************************************
std::multiset<WSML::BindingOperation> WSML::OperationRefImpl::getBindsOperationSrcs()
{
	std::multiset<WSML::BindingOperation> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BindsOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::BindingOperation dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BindsOperation> WSML::OperationRefImpl::getInBindsOperationLinks()
{
	std::set<WSML::BindsOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BindsOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
WSML::Operation WSML::OperationRefImpl::getOperation()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Operation(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::OperationRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::OperationRef
	bool rv = pVisitor->visitOperationRef( PICML::OperationRef( this));
	return rv;
}


//********************************************************************************
// returns dst PICML::CompRefs
//********************************************************************************
std::multiset<PICML::CompRef> PICML::OperationRefImpl::getComponentOperationDsts()
{
	std::multiset<PICML::CompRef> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("ComponentOperation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::CompRef dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::MetricsBases
//********************************************************************************
std::multiset<PICML::MetricsBase> PICML::OperationRefImpl::getMetricConnectionDsts()
{
	std::multiset<PICML::MetricsBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MetricConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::MetricsBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::ComponentOperation> PICML::OperationRefImpl::getOutComponentOperationLinks()
{
	std::set<PICML::ComponentOperation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::ComponentOperation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::MetricConnection> PICML::OperationRefImpl::getOutMetricConnectionLinks()
{
	std::set<PICML::MetricConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::MetricConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::TimerConnection> PICML::OperationRefImpl::getOutTimerConnectionLinks()
{
	std::set<PICML::TimerConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::TimerConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::WorkLoadOperationConnection> PICML::OperationRefImpl::getOutWorkLoadOperationConnectionLinks()
{
	std::set<PICML::WorkLoadOperationConnection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::WorkLoadOperationConnection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst PICML::TimeProbes
//********************************************************************************
std::multiset<PICML::TimeProbe> PICML::OperationRefImpl::getTimerConnectionDsts()
{
	std::multiset<PICML::TimeProbe> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("TimerConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::TimeProbe dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst PICML::Tasks
//********************************************************************************
std::multiset<PICML::Task> PICML::OperationRefImpl::getWorkLoadOperationConnectionDsts()
{
	std::multiset<PICML::Task> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("WorkLoadOperationConnection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			PICML::Task dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::OperationBase PICML::OperationRefImpl::getOperationBase()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::OperationBase(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PackageConfigurationReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PackageConfigurationReference
	bool rv = pVisitor->visitPackageConfigurationReference( PICML::PackageConfigurationReference( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::PackageConfSpecializedConfig> PICML::PackageConfigurationReferenceImpl::getInPackageConfSpecializedConfigLinks()
{
	std::set<PICML::PackageConfSpecializedConfig> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::PackageConfSpecializedConfig c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::package> PICML::PackageConfigurationReferenceImpl::getInpackageLinks()
{
	std::set<PICML::package> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::package c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src PICML::PackageConfigurations
//********************************************************************************
std::multiset<PICML::PackageConfiguration> PICML::PackageConfigurationReferenceImpl::getPackageConfSpecializedConfigSrcs()
{
	std::multiset<PICML::PackageConfiguration> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PackageConfSpecializedConfig");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::PackageConfiguration dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src PICML::TopLevelPackages
//********************************************************************************
std::multiset<PICML::TopLevelPackage> PICML::PackageConfigurationReferenceImpl::getpackageSrcs()
{
	std::multiset<PICML::TopLevelPackage> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("package");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::TopLevelPackage dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
PICML::PackageConfiguration PICML::PackageConfigurationReferenceImpl::getPackageConfiguration()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::PackageConfiguration(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::PartImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::Part
	bool rv = pVisitor->visitPart( WSML::Part( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
WSML::Referrable WSML::PartImpl::getReferrable()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Referrable(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::PartRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::PartRef
	bool rv = pVisitor->visitPartRef( WSML::PartRef( this));
	return rv;
}


//********************************************************************************
// returns src WSML::SOAPBodys
//********************************************************************************
std::multiset<WSML::SOAPBody> WSML::PartRefImpl::getBodyPartsSrcs()
{
	std::multiset<WSML::SOAPBody> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("BodyParts");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::SOAPBody dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src WSML::SOAPHeaderss
//********************************************************************************
std::multiset<WSML::SOAPHeaders> WSML::PartRefImpl::getHeaderPartSrcs()
{
	std::multiset<WSML::SOAPHeaders> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("HeaderPart");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			WSML::SOAPHeaders dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::BodyParts> WSML::PartRefImpl::getInBodyPartsLinks()
{
	std::set<WSML::BodyParts> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::BodyParts c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<WSML::HeaderPart> WSML::PartRefImpl::getInHeaderPartLinks()
{
	std::set<WSML::HeaderPart> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		WSML::HeaderPart c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
WSML::Part WSML::PartRefImpl::getPart()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Part(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::PathReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::PathReference
	bool rv = pVisitor->visitPathReference( PICML::PathReference( this));
	return rv;
}


//********************************************************************************
// returns src PICML::ComponentAssemblys
//********************************************************************************
std::multiset<PICML::ComponentAssembly> PICML::PathReferenceImpl::getCriticalPathSrcs()
{
	std::multiset<PICML::ComponentAssembly> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("CriticalPath");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			PICML::ComponentAssembly dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<PICML::CriticalPath> PICML::PathReferenceImpl::getInCriticalPathLinks()
{
	std::set<PICML::CriticalPath> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		PICML::CriticalPath c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
PICML::Path PICML::PathReferenceImpl::getPath()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Path(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::ReturnTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::ReturnType
	bool rv = pVisitor->visitReturnType( PICML::ReturnType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::MemberType PICML::ReturnTypeImpl::getMemberType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::MemberType(r);
}


//********************************************************************************
//
//********************************************************************************
bool WSML::ServiceRefImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the WSML::ServiceRef
	bool rv = pVisitor->visitServiceRef( WSML::ServiceRef( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
WSML::Service WSML::ServiceRefImpl::getService()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return WSML::Service(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SetExceptionImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SetException
	bool rv = pVisitor->visitSetException( PICML::SetException( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::Exception PICML::SetExceptionImpl::getException()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Exception(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SharedComponentReferenceImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::SharedComponentReference
	bool rv = pVisitor->visitSharedComponentReference( PICML::SharedComponentReference( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::ComponentRef PICML::SharedComponentReferenceImpl::getComponentRef()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::ComponentRef(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::SupportsImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Supports
	bool rv = pVisitor->visitSupports( PICML::Supports( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::Object PICML::SupportsImpl::getObject()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Object(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::VariableImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::Variable
	bool rv = pVisitor->visitVariable( PICML::Variable( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::PredefinedType PICML::VariableImpl::getPredefinedType()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::PredefinedType(r);
}


//********************************************************************************
//
//********************************************************************************
bool PICML::WorkerTypeImpl::accept( SIML::SIMLVisitor *pVisitor)
{
	// visit the PICML::WorkerType
	bool rv = pVisitor->visitWorkerType( PICML::WorkerType( this));
	return rv;
}


//********************************************************************************
//
//********************************************************************************
PICML::Worker PICML::WorkerTypeImpl::getWorker()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return PICML::Worker(r);
}


