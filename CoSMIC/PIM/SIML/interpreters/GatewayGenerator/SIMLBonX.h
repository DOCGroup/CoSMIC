#ifndef SIMLBONX_H
#define SIMLBONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

///BUP
// add your include files/class definitions here
///EUP

namespace SIML { class SIMLVisitor; }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, ComponentAnalysesImpl, ComponentAnalyses ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, ComponentBuildImpl, ComponentBuild ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, ComponentImplementationsImpl, ComponentImplementations ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, ComponentPackagesImpl, ComponentPackages ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, ComponentTypesImpl, ComponentTypes ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, DeploymentPlansImpl, DeploymentPlans ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, ImplementationArtifactsImpl, ImplementationArtifacts ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, InterfaceDefinitionsImpl, InterfaceDefinitions ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, PackageConfigurationsImpl, PackageConfigurations ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, PathDiagramsImpl, PathDiagrams ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, PredefinedTypesImpl, PredefinedTypes ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, TargetsImpl, Targets ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, TopLevelPackagesImpl, TopLevelPackages ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Folder, WorkerLibrariesImpl, WorkerLibraries ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ActionBaseImpl, ActionBase ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, BehaviorModelImpl, BehaviorModel ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, PrefixableImpl, Prefixable ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, SupportsInterfacesImpl, SupportsInterfaces ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, CommonPortAttrsImpl, CommonPortAttrs ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ConstantTypeImpl, ConstantType ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, GraphVertexImpl, GraphVertex ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ManageableImpl, Manageable ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, MemberTypeImpl, MemberType ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, MultiInputBaseImpl, MultiInputBase ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, MultiOutputBaseImpl, MultiOutputBase ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ProvideableImpl, Provideable ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, SingleInputBaseImpl, SingleInputBase ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, SingleOutputBaseImpl, SingleOutputBase ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, TaggableImpl, Taggable ); }
namespace PICML {           DECLARE_BONEXTENSION( ActionBase, ActionImpl, Action ); }
namespace PICML {           DECLARE_BONEXTENSION2( ActionBase, BehaviorModel, CompositeActionImpl, CompositeAction ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, GraphVertex, ConnectedComponentImpl, ConnectedComponent ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, Taggable, ExceptionImpl, Exception ); }
namespace PICML {           DECLARE_BONEXTENSION( Prefixable, FileImpl, File ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION2( BON::Model, Taggable, OperationBaseImpl, OperationBase ); }
namespace PICML {           DECLARE_BONEXTENSION( ActionBase, OutputActionImpl, OutputAction ); }
namespace PICML {           DECLARE_BONEXTENSION2( Prefixable, Taggable, PackageImpl, Package ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, Taggable, ReadonlyAttributeImpl, ReadonlyAttribute ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BehaviorModel, TopLevelBehaviorImpl, TopLevelBehavior ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION2( MemberType, Taggable, NamedTypeImpl, NamedType ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION3( Taggable, CommonPortAttrs, GraphVertex, PortImpl, Port ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION2( ConstantType, MemberType, PredefinedTypeImpl, PredefinedType ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, GraphVertex, DisplayNodeImpl, DisplayNode ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, MultiInputBase, EnvironmentImpl, Environment ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, SingleInputBase, PeriodicEventImpl, PeriodicEvent ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Reference, Manageable, ComponentRefImpl, ComponentRef ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Reference, Taggable, ConstantImpl, Constant ); }
namespace PICML {           DECLARE_BONEXTENSION( ReadonlyAttribute, AttributeImpl, Attribute ); }
namespace PICML {           DECLARE_BONEXTENSION4( NamedType, SupportsInterfaces, Manageable, TopLevelBehavior, ComponentImpl, Component ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( OperationBase, HasExceptionsImpl, HasExceptions ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION2( BON::Model, NamedType, InheritableImpl, Inheritable ); }
namespace PICML {           DECLARE_BONEXTENSION( OperationBase, OnewayOperationImpl, OnewayOperation ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( NamedType, NoInheritableImpl, NoInheritable ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, BooleanImpl, Boolean ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, ByteImpl, Byte ); }
namespace PICML {           DECLARE_BONEXTENSION3( BON::Atom, PredefinedType, Provideable, GenericObjectImpl, GenericObject ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, GenericValueImpl, GenericValue ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, GenericValueObjectImpl, GenericValueObject ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, LongIntegerImpl, LongInteger ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, RealNumberImpl, RealNumber ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, ShortIntegerImpl, ShortInteger ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, StringImpl, String ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, TypeEncodingImpl, TypeEncoding ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, TypeKindImpl, TypeKind ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Reference, NamedType, BoxedImpl, Boxed ); }
namespace PICML {           DECLARE_BONEXTENSION3( BON::Reference, Port, SingleInputBase, InEventPortImpl, InEventPort ); }
namespace PICML {           DECLARE_BONEXTENSION3( BON::Reference, Port, SingleOutputBase, OutEventPortImpl, OutEventPort ); }
namespace PICML {           DECLARE_BONEXTENSION3( BON::Reference, Port, MultiInputBase, ProvidedRequestPortImpl, ProvidedRequestPort ); }
namespace PICML {           DECLARE_BONEXTENSION3( BON::Reference, Port, MultiOutputBase, RequiredRequestPortImpl, RequiredRequestPort ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, NoInheritable, AggregateImpl, Aggregate ); }
namespace PICML {           DECLARE_BONEXTENSION3( BON::Model, ConstantType, NoInheritable, EnumImpl, Enum ); }
namespace PICML {           DECLARE_BONEXTENSION( HasExceptions, FactoryOperationImpl, FactoryOperation ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( Inheritable, HasOperationsImpl, HasOperations ); }
namespace PICML {           DECLARE_BONEXTENSION( HasExceptions, LookupOperationImpl, LookupOperation ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, NoInheritable, SwitchedAggregateImpl, SwitchedAggregate ); }
namespace PICML {           DECLARE_BONEXTENSION( HasExceptions, TwowayOperationImpl, TwowayOperation ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Reference, NoInheritable, AliasImpl, Alias ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Reference, NoInheritable, CollectionImpl, Collection ); }
namespace PICML {           DECLARE_BONEXTENSION2( HasOperations, SupportsInterfaces, ComponentFactoryImpl, ComponentFactory ); }
namespace PICML {           DECLARE_BONEXTENSION3( HasOperations, Provideable, Prefixable, ObjectImpl, Object ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION3( HasOperations, SupportsInterfaces, Prefixable, ObjectByValueImpl, ObjectByValue ); }
namespace PICML {           DECLARE_BONEXTENSION( ObjectByValue, EventImpl, Event ); }
namespace PICML {           DECLARE_BONEXTENSION( ObjectByValue, ValueObjectImpl, ValueObject ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RequirementSatisfierImpl, RequirementSatisfier ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ElementsImpl, Elements ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, Elements, BridgeImpl, Bridge ); }
namespace PICML {           DECLARE_BONEXTENSION( RequirementSatisfier, CapabilityImpl, Capability ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, Elements, InterconnectImpl, Interconnect ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, Elements, NodeImpl, Node ); }
namespace PICML {           DECLARE_BONEXTENSION( RequirementSatisfier, ResourceImpl, Resource ); }
namespace PICML {           DECLARE_BONEXTENSION2( Elements, RequirementSatisfier, SharedResourceImpl, SharedResource ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RequirementBaseImpl, RequirementBase ); }
namespace PICML {           DECLARE_BONEXTENSION( RequirementBase, ImplementationRequirementImpl, ImplementationRequirement ); }
namespace PICML {           DECLARE_BONEXTENSION( RequirementBase, RequirementImpl, Requirement ); }
namespace PICML {           DECLARE_BONEXTENSION( Requirement, ECConfigurationImpl, ECConfiguration ); }
namespace PICML {           DECLARE_BONEXTENSION( Requirement, RTRequirementsImpl, RTRequirements ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( BON::Model, OperationImpl, Operation ); }
namespace WSML {            DECLARE_BONEXTENSION( Operation, NotificationOperationImpl, NotificationOperation ); }
namespace WSML {            DECLARE_BONEXTENSION( Operation, OneWayOperationImpl, OneWayOperation ); }
namespace WSML {            DECLARE_BONEXTENSION( Operation, RequestResponseOperationImpl, RequestResponseOperation ); }
namespace WSML {            DECLARE_BONEXTENSION( Operation, SolicitResponseOperationImpl, SolicitResponseOperation ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ComponentLibImpl, ComponentLib ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, ComponentLib, ExecutorProjectImpl, ExecutorProject ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, ComponentLib, ServantProjectImpl, ServantProject ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, ComponentLib, StubProjectImpl, StubProject ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ECRoleImpl, ECRole ); }
namespace PICML {           DECLARE_BONEXTENSION( ECRole, ECConsumerImpl, ECConsumer ); }
namespace PICML {           DECLARE_BONEXTENSION( ECRole, ECSupplierImpl, ECSupplier ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, MetricsBaseImpl, MetricsBase ); }
namespace PICML {           DECLARE_BONEXTENSION( MetricsBase, LatencyImpl, Latency ); }
namespace PICML {           DECLARE_BONEXTENSION( MetricsBase, ThroughputImpl, Throughput ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Model, WorkerPackageBaseImpl, WorkerPackageBase ); }
namespace PICML {           DECLARE_BONEXTENSION( WorkerPackageBase, WorkerFileImpl, WorkerFile ); }
namespace PICML {           DECLARE_BONEXTENSION( WorkerPackageBase, WorkerPackageImpl, WorkerPackage ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, SchemaReferenceImpl, SchemaReference ); }
namespace WSML {            DECLARE_BONEXTENSION( SchemaReference, SchemaImportImpl, SchemaImport ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ComponentImplementationImpl, ComponentImplementation ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Model, ComponentImplementation, ComponentAssemblyImpl, ComponentAssembly ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, ComponentImplementation, MonolithicImplementationImpl, MonolithicImplementation ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ExtensibilityElementImpl, ExtensibilityElement ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensibleBindingImpl, ExtensibleBinding ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensibleMessageImpl, ExtensibleMessage ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensibleOperationImpl, ExtensibleOperation ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensiblePortImpl, ExtensiblePort ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( ExtensibleMessage, SOAPHeadersImpl, SOAPHeaders ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Atom, ExtensiblePort, SOAPAddressImpl, SOAPAddress ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Atom, ExtensibleBinding, SOAPBindingImpl, SOAPBinding ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Atom, ExtensibleMessage, SOAPBodyImpl, SOAPBody ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Atom, ExtensibleMessage, SOAPFaultImpl, SOAPFault ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Atom, ExtensibleOperation, SOAPOperationImpl, SOAPOperation ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Model, SOAPHeaders, SOAPHeaderImpl, SOAPHeader ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Atom, SOAPHeaders, SOAPHeaderFaultImpl, SOAPHeaderFault ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ReferrableImpl, Referrable ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Model, Referrable, ElementImpl, Element ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Atom, Referrable, AtomicTypeImpl, AtomicType ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, ArtifactContainerImpl, ArtifactContainer ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, BenchmarkAnalysisImpl, BenchmarkAnalysis ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, BindingImpl, Binding ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, BindingOperationImpl, BindingOperation ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, ComponentContainerImpl, ComponentContainer ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, ComponentImplementationContainerImpl, ComponentImplementationContainer ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, ComponentPropertyDescriptionImpl, ComponentPropertyDescription ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, DefinitionsImpl, Definitions ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, DeploymentPlanImpl, DeploymentPlan ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, DocumentationImpl, Documentation ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, DomainImpl, Domain ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, FaultImpl, Fault ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, ImportImpl, Import ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, InputImpl, Input ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, InputActionImpl, InputAction ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, MPCImpl, MPC ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, MessageImpl, Message ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, MessagesImpl, Messages ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, OutputImpl, Output ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, PackageConfigurationContainerImpl, PackageConfigurationContainer ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, PackageContainerImpl, PackageContainer ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, PathImpl, Path ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, PathsImpl, Paths ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, PortImpl, Port ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, PortTypeImpl, PortType ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, ProjectImpl, Project ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, PropertyImpl, Property ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, SatisfierPropertyImpl, SatisfierProperty ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, SchemaImpl, Schema ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, SchemaBuiltinsImpl, SchemaBuiltins ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, ServiceImpl, Service ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, ServiceProviderImpl, ServiceProvider ); }
namespace SIML {            DECLARE_BONEXTENSION( BON::Model, SystemImpl, System ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, TopLevelPackageContainerImpl, TopLevelPackageContainer ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Model, TypesImpl, Types ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, WorkerImpl, Worker ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Model, WorkerLibraryImpl, WorkerLibrary ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, BenchmarkTypeImpl, BenchmarkType ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, FixedIterationBenchmarksImpl, FixedIterationBenchmarks ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, PeriodicBenchmarksImpl, PeriodicBenchmarks ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, TriggerBenchmarksImpl, TriggerBenchmarks ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, DataAnalysisBaseImpl, DataAnalysisBase ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, AverageImpl, Average ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, JitterImpl, Jitter ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, MaximumImpl, Maximum ); }
namespace PICML {           DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, MinimumImpl, Minimum ); }
namespace WSML {            DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, IORefImpl, IORef ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Reference, IORef, InputRefImpl, InputRef ); }
namespace WSML {            DECLARE_BONEXTENSION2( BON::Reference, IORef, OutputRefImpl, OutputRef ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Atom, AttributeImpl, Attribute ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Atom, StateBaseImpl, StateBase ); }
namespace PICML {           DECLARE_BONEXTENSION( StateBase, BranchStateImpl, BranchState ); }
namespace PICML {           DECLARE_BONEXTENSION( StateBase, StateImpl, State ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ComponentPackageImpl, ComponentPackage ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ECBehaviorImpl, ECBehavior ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ECEventFilterConfigurationImpl, ECEventFilterConfiguration ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, EdgeImpl, Edge ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, EnumValueImpl, EnumValue ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ExternalReferenceEndPointImpl, ExternalReferenceEndPoint ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ImplementationArtifactImpl, ImplementationArtifact ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ImplementationDependencyImpl, ImplementationDependency ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, LabelImpl, Label ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, MultipleServiceRequestsImpl, MultipleServiceRequests ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, PackageConfigurationImpl, PackageConfiguration ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, PrivateFlagImpl, PrivateFlag ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, PublishConnectorImpl, PublishConnector ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ServiceConsumerImpl, ServiceConsumer ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, ServiceLevelsImpl, ServiceLevels ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, TaskImpl, Task ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, TimeProbeImpl, TimeProbe ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Atom, TopLevelPackageImpl, TopLevelPackage ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ArtifactDependencyImpl, ArtifactDependency ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ArtifactDependsOnImpl, ArtifactDependsOn ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ArtifactDeployRequirementImpl, ArtifactDeployRequirement ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ArtifactExecParameterImpl, ArtifactExecParameter ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ArtifactInfoPropertyImpl, ArtifactInfoProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, AssemblyConfigPropertyImpl, AssemblyConfigProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, AssemblyDeployRequirementImpl, AssemblyDeployRequirement ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, AssemblyselectRequirementImpl, AssemblyselectRequirement ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, AttributeDelegateImpl, AttributeDelegate ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, AttributeMappingDelegateImpl, AttributeMappingDelegate ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, AttributeMappingValueImpl, AttributeMappingValue ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, AttributeValueImpl, AttributeValue ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, BenchmarkCharacteristicsImpl, BenchmarkCharacteristics ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, BindingPortTypeImpl, BindingPortType ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, BindsOperationImpl, BindsOperation ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, BodyBindingImpl, BodyBinding ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, BodyPartsImpl, BodyParts ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, BranchTransitionImpl, BranchTransition ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, Bridge2InterconnectImpl, Bridge2Interconnect ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ComponentConfigPropertyImpl, ComponentConfigProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ComponentInfoPropertyImpl, ComponentInfoProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ComponentOperationImpl, ComponentOperation ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ComponentPropertyImpl, ComponentProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ConfigPropertyImpl, ConfigProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, Consumer2BehaviorConnectionImpl, Consumer2BehaviorConnection ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, CriticalPathImpl, CriticalPath ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, DstEdgeImpl, DstEdge ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, EdgePropertyImpl, EdgeProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, EffectImpl, Effect ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, EventSinkDelegateImpl, EventSinkDelegate ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, EventSourceDelegateImpl, EventSourceDelegate ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ExtResourceConnImpl, ExtResourceConn ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ExternalDelegateImpl, ExternalDelegate ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, FacetDelegateImpl, FacetDelegate ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, FaultMessageImpl, FaultMessage ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, FinishImpl, Finish ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, HeaderBindingImpl, HeaderBinding ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, HeaderMessageImpl, HeaderMessage ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, HeaderPartImpl, HeaderPart ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ImplementationImpl, Implementation ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ImplementationCapabilityImpl, ImplementationCapability ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ImplementationDependsOnImpl, ImplementationDependsOn ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ImplementsImpl, Implements ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, InfoPropertyImpl, InfoProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, InputImpl, Input ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, InputEffectImpl, InputEffect ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, InputMessageImpl, InputMessage ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, InstanceMappingImpl, InstanceMapping ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, Interconnect2BridgeImpl, Interconnect2Bridge ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, Interconnect2NodeImpl, Interconnect2Node ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, LabelConnectionImpl, LabelConnection ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, MakeMemberPrivateImpl, MakeMemberPrivate ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ManagesComponentImpl, ManagesComponent ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, MetricConnectionImpl, MetricConnection ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, MonolithDeployRequirementImpl, MonolithDeployRequirement ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, MonolithExecParameterImpl, MonolithExecParameter ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, MonolithprimaryArtifactImpl, MonolithprimaryArtifact ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, MultiInputImpl, MultiInput ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, Node2InterconnectImpl, Node2Interconnect ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, OutputMessageImpl, OutputMessage ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageConfBasePackageImpl, PackageConfBasePackage ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageConfConfigPropertyImpl, PackageConfConfigProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageConfReferenceImpl, PackageConfReference ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageConfSelectRequirementImpl, PackageConfSelectRequirement ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageConfSpecializedConfigImpl, PackageConfSpecializedConfig ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageConfigPropertyImpl, PackageConfigProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageInfoPropertyImpl, PackageInfoProperty ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PackageInterfaceImpl, PackageInterface ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, PathPropertyImpl, PathProperty ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, PortBindingImpl, PortBinding ); }
namespace SIML {            DECLARE_BONEXTENSION( BON::Connection, PortProxyImpl, PortProxy ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, ReceptacleDelegateImpl, ReceptacleDelegate ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, RecursiveFilterConnectionImpl, RecursiveFilterConnection ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Connection, SOAPFaultExtensionImpl, SOAPFaultExtension ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, SharesImpl, Shares ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, SrcEdgeImpl, SrcEdge ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, Supplier2FilterConnectionImpl, Supplier2FilterConnection ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, TimerConnectionImpl, TimerConnection ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, TimerEventSinkConnImpl, TimerEventSinkConn ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, TransitionImpl, Transition ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, WorkLoadOperationConnectionImpl, WorkLoadOperationConnection ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, WorkloadCharacteristicsImpl, WorkloadCharacteristics ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, deliverToImpl, deliverTo ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, emitImpl, emit ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, invokeImpl, invoke ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, packageImpl, package ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Connection, publishImpl, publish ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Set, CollocationGroupImpl, CollocationGroup ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Set, TaskSetImpl, TaskSet ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Set, WorkspacesImpl, Workspaces ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, AttributeMappingImpl, AttributeMapping ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, AttributeMemberImpl, AttributeMember ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Reference, BindingRefImpl, BindingRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, CompRefImpl, CompRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, ComponentAssemblyReferenceImpl, ComponentAssemblyReference ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, ComponentImplementationReferenceImpl, ComponentImplementationReference ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, ComponentPackageReferenceImpl, ComponentPackageReference ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, DataTypeImpl, DataType ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, DiscriminatorImpl, Discriminator ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, EventRefImpl, EventRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, ExceptionRefImpl, ExceptionRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, ExternalResourcesImpl, ExternalResources ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Reference, FaultRefImpl, FaultRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, FileRefImpl, FileRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, GetExceptionImpl, GetException ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, ImplementationArtifactReferenceImpl, ImplementationArtifactReference ); }
namespace PICML {           DECLARE_ABSTRACT_BONEXTENSION( BON::Reference, ParameterTypeImpl, ParameterType ); }
namespace PICML {           DECLARE_BONEXTENSION( ParameterType, InParameterImpl, InParameter ); }
namespace PICML {           DECLARE_BONEXTENSION( ParameterType, InoutParameterImpl, InoutParameter ); }
namespace PICML {           DECLARE_BONEXTENSION( ParameterType, OutParameterImpl, OutParameter ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, InheritsImpl, Inherits ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, LookupKeyImpl, LookupKey ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, MemberImpl, Member ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Reference, MessageRefImpl, MessageRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, NodeReferenceImpl, NodeReference ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Reference, OperationRefImpl, OperationRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, OperationRefImpl, OperationRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, PackageConfigurationReferenceImpl, PackageConfigurationReference ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Reference, PartImpl, Part ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Reference, PartRefImpl, PartRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, PathReferenceImpl, PathReference ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, ReturnTypeImpl, ReturnType ); }
namespace WSML {            DECLARE_BONEXTENSION( BON::Reference, ServiceRefImpl, ServiceRef ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, SetExceptionImpl, SetException ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, SharedComponentReferenceImpl, SharedComponentReference ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, SupportsImpl, Supports ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, VariableImpl, Variable ); }
namespace PICML {           DECLARE_BONEXTENSION( BON::Reference, WorkerTypeImpl, WorkerType ); }


#include "SIMLVisitor.h"

namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentAnalysesImpl
//*******************************************************************
class ComponentAnalysesImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::BenchmarkAnalysis>        getBenchmarkAnalysis();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentBuildImpl
//*******************************************************************
class ComponentBuildImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::MPC>            getMPC();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentImplementationsImpl
//*******************************************************************
class ComponentImplementationsImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::ComponentImplementationContainer> getComponentImplementationContainer();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentPackagesImpl
//*******************************************************************
class ComponentPackagesImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::PackageContainer>         getPackageContainer();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentTypesImpl
//*******************************************************************
class ComponentTypesImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::ComponentContainer>       getComponentContainer();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DeploymentPlansImpl
//*******************************************************************
class DeploymentPlansImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::DeploymentPlan> getDeploymentPlan();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationArtifactsImpl
//*******************************************************************
class ImplementationArtifactsImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::ArtifactContainer>        getArtifactContainer();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InterfaceDefinitionsImpl
//*******************************************************************
class InterfaceDefinitionsImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::File>           getFile();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfigurationsImpl
//*******************************************************************
class PackageConfigurationsImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::PackageConfigurationContainer> getPackageConfigurationContainer();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PathDiagramsImpl
//*******************************************************************
class PathDiagramsImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::Paths>          getPaths();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PredefinedTypesImpl
//*******************************************************************
class PredefinedTypesImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::Boolean>        getBoolean();
	virtual std::set<PICML::Byte>           getByte();
	virtual std::set<PICML::GenericObject>  getGenericObject();
	virtual std::set<PICML::GenericValue>   getGenericValue();
	virtual std::set<PICML::GenericValueObject>       getGenericValueObject();
	virtual std::set<PICML::LongInteger>    getLongInteger();
	virtual std::set<PICML::PredefinedType> getPredefinedType();
	virtual std::set<PICML::RealNumber>     getRealNumber();
	virtual std::set<PICML::ShortInteger>   getShortInteger();
	virtual std::set<PICML::String>         getString();
	virtual std::set<PICML::TypeEncoding>   getTypeEncoding();
	virtual std::set<PICML::TypeKind>       getTypeKind();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TargetsImpl
//*******************************************************************
class TargetsImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::Domain>         getDomain();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TopLevelPackagesImpl
//*******************************************************************
class TopLevelPackagesImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::TopLevelPackageContainer> getTopLevelPackageContainer();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkerLibrariesImpl
//*******************************************************************
class WorkerLibrariesImpl :
	  public BON::FolderImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	//
	// kind and subfolder getters
	virtual std::set<PICML::WorkerLibrary>  getWorkerLibrary();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ActionBaseImpl
//*******************************************************************
class ActionBaseImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::BranchState>         getBranchTransitionSrcs();
	virtual std::multiset<PICML::StateBase> getEffectDsts();
	virtual std::set<PICML::BranchTransition>         getInBranchTransitionLinks();
	virtual std::set<PICML::Transition>     getInTransitionLinks();
	virtual std::set<PICML::Effect>         getOutEffectLinks();
	virtual std::multiset<PICML::State>     getTransitionSrcs();
	//
	// kind and role getters
	virtual std::set<PICML::Property>       getProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BehaviorModelImpl
//*******************************************************************
class BehaviorModelImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Action>         getAction();
	virtual std::set<PICML::ActionBase>     getActionBase();
	virtual std::set<PICML::BranchState>    getBranchState();
	virtual std::set<PICML::BranchTransition>         getBranchTransition();
	virtual std::set<PICML::CompositeAction>          getCompositeAction();
	virtual std::set<PICML::Effect>         getEffect();
	virtual std::set<PICML::Finish>         getFinish();
	virtual std::set<PICML::InputAction>    getInputAction();
	virtual std::set<PICML::InputEffect>    getInputEffect();
	virtual std::set<PICML::OutputAction>   getOutputAction();
	virtual std::set<PICML::State>          getState();
	virtual std::set<PICML::StateBase>      getStateBase();
	virtual std::set<PICML::Transition>     getTransition();
	virtual std::set<PICML::Variable>       getVariable();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PrefixableImpl
//*******************************************************************
class PrefixableImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getPrefixTag() ;
	virtual void        setPrefixTag( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SupportsInterfacesImpl
//*******************************************************************
class SupportsInterfacesImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Supports>       getSupports();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   CommonPortAttrsImpl
//*******************************************************************
class CommonPortAttrsImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isexclusiveProvider() ;
	virtual bool        isexclusiveUser() ;
	virtual bool        isoptional() ;
	virtual void        setexclusiveProvider( bool val);
	virtual void        setexclusiveUser( bool val);
	virtual void        setoptional( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ConstantTypeImpl
//*******************************************************************
class ConstantTypeImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   GraphVertexImpl
//*******************************************************************
class GraphVertexImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Edge>      getDstEdgeDsts();
	virtual std::set<PICML::SrcEdge>        getInSrcEdgeLinks();
	virtual std::set<PICML::DstEdge>        getOutDstEdgeLinks();
	virtual std::multiset<PICML::Edge>      getSrcEdgeSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ManageableImpl
//*******************************************************************
class ManageableImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::ManagesComponent>         getInManagesComponentLinks();
	virtual std::multiset<PICML::ComponentFactory>    getManagesComponentSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MemberTypeImpl
//*******************************************************************
class MemberTypeImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MultiInputBaseImpl
//*******************************************************************
class MultiInputBaseImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::InputAction>         getMultiInputDsts();
	virtual std::set<PICML::MultiInput>     getOutMultiInputLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MultiOutputBaseImpl
//*******************************************************************
class MultiOutputBaseImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ProvideableImpl
//*******************************************************************
class ProvideableImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SingleInputBaseImpl
//*******************************************************************
class SingleInputBaseImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::InputAction>         getInputDsts();
	virtual std::set<PICML::Input>          getOutInputLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SingleOutputBaseImpl
//*******************************************************************
class SingleOutputBaseImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TaggableImpl
//*******************************************************************
class TaggableImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getSpecifyIdTag() ;
	virtual std::string getVersionTag() ;
	virtual void        setSpecifyIdTag( const std::string& val);
	virtual void        setVersionTag( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ActionImpl
//*******************************************************************
class ActionImpl :
	  public ActionBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual long        getDuration() ;
	virtual bool        isLogAction() ;
	virtual void        setDuration( const long val);
	virtual void        setLogAction( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   CompositeActionImpl
//*******************************************************************
class CompositeActionImpl :
	  public ActionBaseImpl
	, public BehaviorModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ConnectedComponentImpl
//*******************************************************************
class ConnectedComponentImpl :
	  virtual public BON::ModelImpl
	, public GraphVertexImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::DstEdge>        getDstEdge();
	virtual std::set<PICML::InEventPort>    getInEventPort();
	virtual std::set<PICML::OutEventPort>   getOutEventPort();
	virtual std::set<PICML::Port>           getPort();
	virtual std::set<PICML::ProvidedRequestPort>      getProvidedRequestPort();
	virtual std::set<PICML::RequiredRequestPort>      getRequiredRequestPort();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ExceptionImpl
//*******************************************************************
class ExceptionImpl :
	  virtual public BON::ModelImpl
	, public TaggableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Member>         getMember();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   FileImpl
//*******************************************************************
class FileImpl :
	  public PrefixableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Aggregate>      getAggregate();
	virtual std::set<PICML::Alias>          getAlias();
	virtual std::set<PICML::Boxed>          getBoxed();
	virtual std::set<PICML::Collection>     getCollection();
	virtual std::set<PICML::Component>      getComponent();
	virtual std::set<PICML::ComponentFactory>         getComponentFactory();
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::Constant>       getConstant();
	virtual std::set<PICML::Enum>           getEnum();
	virtual std::set<PICML::Event>          getEvent();
	virtual std::set<PICML::Exception>      getException();
	virtual std::set<PICML::FileRef>        getFileRef();
	virtual std::set<PICML::ManagesComponent>         getManagesComponent();
	virtual std::set<PICML::NamedType>      getNamedType();
	virtual std::set<PICML::Object>         getObject();
	virtual std::set<PICML::Package>        getPackage();
	virtual std::set<PICML::SwitchedAggregate>        getSwitchedAggregate();
	virtual std::set<PICML::ValueObject>    getValueObject();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   OperationBaseImpl
//*******************************************************************
class OperationBaseImpl :
	  virtual public BON::ModelImpl
	, public TaggableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::InParameter>    getInParameter();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   OutputActionImpl
//*******************************************************************
class OutputActionImpl :
	  public ActionBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageImpl
//*******************************************************************
class PackageImpl :
	  public PrefixableImpl
	, public TaggableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Aggregate>      getAggregate();
	virtual std::set<PICML::Alias>          getAlias();
	virtual std::set<PICML::Boxed>          getBoxed();
	virtual std::set<PICML::Collection>     getCollection();
	virtual std::set<PICML::Component>      getComponent();
	virtual std::set<PICML::ComponentFactory>         getComponentFactory();
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::Constant>       getConstant();
	virtual std::set<PICML::Enum>           getEnum();
	virtual std::set<PICML::Event>          getEvent();
	virtual std::set<PICML::Exception>      getException();
	virtual std::set<PICML::ManagesComponent>         getManagesComponent();
	virtual std::set<PICML::NamedType>      getNamedType();
	virtual std::set<PICML::Object>         getObject();
	virtual std::set<PICML::Package>        getPackage();
	virtual std::set<PICML::SwitchedAggregate>        getSwitchedAggregate();
	virtual std::set<PICML::ValueObject>    getValueObject();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ReadonlyAttributeImpl
//*******************************************************************
class ReadonlyAttributeImpl :
	  virtual public BON::ModelImpl
	, public TaggableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getAttributeDelegateSrcs();
	virtual std::multiset<PICML::Property>  getAttributeValueDsts();
	virtual std::set<PICML::AttributeDelegate>        getInAttributeDelegateLinks();
	virtual std::set<PICML::AttributeValue> getOutAttributeValueLinks();
	//
	// kind and role getters
	virtual std::set<PICML::AttributeMember>          getAttributeMember();
	virtual std::set<PICML::GetException>   getGetException();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TopLevelBehaviorImpl
//*******************************************************************
class TopLevelBehaviorImpl :
	  public BehaviorModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Environment>    getEnvironment();
	virtual std::set<PICML::Input>          getInput();
	virtual std::set<PICML::MultiInput>     getMultiInput();
	virtual std::set<PICML::PeriodicEvent>  getPeriodicEvent();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   NamedTypeImpl
//*******************************************************************
class NamedTypeImpl :
	  public MemberTypeImpl
	, public TaggableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PortImpl
//*******************************************************************
class PortImpl :
	  public TaggableImpl
	, public CommonPortAttrsImpl
	, public GraphVertexImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PredefinedTypeImpl
//*******************************************************************
class PredefinedTypeImpl :
	  public ConstantTypeImpl
	, public MemberTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DisplayNodeImpl
//*******************************************************************
class DisplayNodeImpl :
	  virtual public BON::AtomImpl
	, public GraphVertexImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EnvironmentImpl
//*******************************************************************
class EnvironmentImpl :
	  virtual public BON::AtomImpl
	, public MultiInputBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PeriodicEventImpl
//*******************************************************************
class PeriodicEventImpl :
	  virtual public BON::AtomImpl
	, public SingleInputBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getPeriod() ;
	virtual std::string getProbability() ;
	virtual void        setPeriod( const std::string& val);
	virtual void        setProbability( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentRefImpl
//*******************************************************************
class ComponentRefImpl :
	  virtual public BON::ReferenceImpl
	, public ManageableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Property>  getComponentConfigPropertyDsts();
	virtual std::multiset<PICML::Property>  getComponentInfoPropertyDsts();
	virtual std::multiset<PICML::ComponentPropertyDescription> getComponentPropertyDsts();
	virtual std::multiset<PICML::ComponentImplementation> getImplementsSrcs();
	virtual std::set<PICML::Implements>     getInImplementsLinks();
	virtual std::set<PICML::PackageInterface>         getInPackageInterfaceLinks();
	virtual std::set<PICML::ComponentConfigProperty>  getOutComponentConfigPropertyLinks();
	virtual std::set<PICML::ComponentInfoProperty>    getOutComponentInfoPropertyLinks();
	virtual std::set<PICML::ComponentProperty>        getOutComponentPropertyLinks();
	virtual std::multiset<PICML::ComponentPackage>    getPackageInterfaceSrcs();
	//
	// ref getters
	virtual PICML::Component                getComponent();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ConstantImpl
//*******************************************************************
class ConstantImpl :
	  virtual public BON::ReferenceImpl
	, public TaggableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getvalue() ;
	virtual void        setvalue( const std::string& val);
	//
	// ref getters
	virtual PICML::ConstantType             getConstantType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AttributeImpl
//*******************************************************************
class AttributeImpl :
	  public ReadonlyAttributeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::SetException>   getSetException();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentImpl
//*******************************************************************
class ComponentImpl :
	  public NamedTypeImpl
	, public SupportsInterfacesImpl
	, public ManageableImpl
	, public TopLevelBehaviorImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Property>  getAssemblyConfigPropertyDsts();
	virtual std::multiset<PICML::Requirement>         getAssemblyselectRequirementDsts();
	virtual std::multiset<PICML::ExternalReferenceEndPoint> getExternalDelegateDsts();
	virtual std::set<PICML::AssemblyConfigProperty>   getOutAssemblyConfigPropertyLinks();
	virtual std::set<PICML::AssemblyselectRequirement> getOutAssemblyselectRequirementLinks();
	virtual std::set<PICML::ExternalDelegate>         getOutExternalDelegateLinks();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::Attribute>      getAttribute();
	virtual std::set<PICML::InEventPort>    getInEventPort();
	virtual std::set<PICML::OutEventPort>   getOutEventPort();
	virtual std::set<PICML::Port>           getPort();
	virtual std::set<PICML::ProvidedRequestPort>      getProvidedRequestPort();
	virtual std::set<PICML::ReadonlyAttribute>        getReadonlyAttribute();
	virtual std::set<PICML::ReadonlyAttribute>        getReadonlyAttribute(int dummy);
	virtual std::set<PICML::RequiredRequestPort>      getRequiredRequestPort();
	virtual std::set<PICML::WorkerType>     getWorkerType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   HasExceptionsImpl
//*******************************************************************
class HasExceptionsImpl :
	  public OperationBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ExceptionRef>   getExceptionRef();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InheritableImpl
//*******************************************************************
class InheritableImpl :
	  virtual public BON::ModelImpl
	, public NamedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Attribute>      getAttribute();
	virtual std::set<PICML::Inherits>       getInherits();
	virtual std::set<PICML::ReadonlyAttribute>        getReadonlyAttribute();
	virtual std::set<PICML::ReadonlyAttribute>        getReadonlyAttribute(int dummy);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   OnewayOperationImpl
//*******************************************************************
class OnewayOperationImpl :
	  public OperationBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   NoInheritableImpl
//*******************************************************************
class NoInheritableImpl :
	  public NamedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BooleanImpl
//*******************************************************************
class BooleanImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ByteImpl
//*******************************************************************
class ByteImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   GenericObjectImpl
//*******************************************************************
class GenericObjectImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
	, public ProvideableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   GenericValueImpl
//*******************************************************************
class GenericValueImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   GenericValueObjectImpl
//*******************************************************************
class GenericValueObjectImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   LongIntegerImpl
//*******************************************************************
class LongIntegerImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   RealNumberImpl
//*******************************************************************
class RealNumberImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ShortIntegerImpl
//*******************************************************************
class ShortIntegerImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   StringImpl
//*******************************************************************
class StringImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TypeEncodingImpl
//*******************************************************************
class TypeEncodingImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TypeKindImpl
//*******************************************************************
class TypeKindImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BoxedImpl
//*******************************************************************
class BoxedImpl :
	  virtual public BON::ReferenceImpl
	, public NamedTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InEventPortImpl
//*******************************************************************
class InEventPortImpl :
	  virtual public BON::ReferenceImpl
	, public PortImpl
	, public SingleInputBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getEventSinkDelegateDsts();
	virtual std::set<PICML::EventSinkDelegate>        getEventSinkDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getEventSinkDelegateSrcs();
	virtual std::set<PICML::EventSinkDelegate>        getInEventSinkDelegateLinks();
	virtual std::set<PICML::deliverTo>      getIndeliverToLinks();
	virtual std::set<PICML::emit>           getInemitLinks();
	virtual std::set<PICML::EventSinkDelegate>        getOutEventSinkDelegateLinks();
	virtual std::multiset<PICML::PublishConnector>    getdeliverToSrcs();
	virtual std::multiset<BON::ConnectionEnd>         getemitSrcs();
	//
	// ref getters
	virtual PICML::Event                    getEvent();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   OutEventPortImpl
//*******************************************************************
class OutEventPortImpl :
	  virtual public BON::ReferenceImpl
	, public PortImpl
	, public SingleOutputBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		DirectConnect_out_event_port_type_Type,
		RTEventChannel_out_event_port_type_Type
	} out_event_port_type_Type;

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getEventSourceDelegateDsts();
	virtual std::set<PICML::EventSourceDelegate>      getEventSourceDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getEventSourceDelegateSrcs();
	virtual std::set<PICML::EventSourceDelegate>      getInEventSourceDelegateLinks();
	virtual std::set<PICML::EventSourceDelegate>      getOutEventSourceDelegateLinks();
	virtual std::set<PICML::emit>           getOutemitLinks();
	virtual std::set<PICML::publish>        getOutpublishLinks();
	virtual std::multiset<BON::ConnectionEnd>         getemitDsts();
	virtual std::multiset<PICML::PublishConnector>    getpublishDsts();
	//
	// attribute getters and setters
	virtual PICML::OutEventPortImpl::out_event_port_type_Type getout_event_port_type();
	virtual bool        issingle_destination() ;
	virtual void        setout_event_port_type( OutEventPortImpl::out_event_port_type_Type val);
	virtual void        setsingle_destination( bool val);
	//
	// ref getters
	virtual PICML::Event                    getEvent();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ProvidedRequestPortImpl
//*******************************************************************
class ProvidedRequestPortImpl :
	  virtual public BON::ReferenceImpl
	, public PortImpl
	, public MultiInputBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getFacetDelegateDsts();
	virtual std::set<PICML::FacetDelegate>  getFacetDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getFacetDelegateSrcs();
	virtual std::set<PICML::FacetDelegate>  getInFacetDelegateLinks();
	virtual std::set<SIML::PortProxy>       getInPortProxyLinks();
	virtual std::set<PICML::invoke>         getIninvokeLinks();
	virtual std::set<PICML::FacetDelegate>  getOutFacetDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getPortProxySrcs();
	virtual std::multiset<BON::ConnectionEnd>         getinvokeSrcs();
	//
	// ref getters
	virtual PICML::Provideable              getProvideable();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   RequiredRequestPortImpl
//*******************************************************************
class RequiredRequestPortImpl :
	  virtual public BON::ReferenceImpl
	, public PortImpl
	, public MultiOutputBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::ReceptacleDelegate>       getInReceptacleDelegateLinks();
	virtual std::set<PICML::ReceptacleDelegate>       getOutReceptacleDelegateLinks();
	virtual std::set<PICML::invoke>         getOutinvokeLinks();
	virtual std::multiset<BON::ConnectionEnd>         getReceptacleDelegateDsts();
	virtual std::set<PICML::ReceptacleDelegate>       getReceptacleDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getReceptacleDelegateSrcs();
	virtual std::multiset<BON::ConnectionEnd>         getinvokeDsts();
	//
	// attribute getters and setters
	virtual bool        ismultiple_connections() ;
	virtual void        setmultiple_connections( bool val);
	//
	// ref getters
	virtual PICML::Provideable              getProvideable();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AggregateImpl
//*******************************************************************
class AggregateImpl :
	  virtual public BON::ModelImpl
	, public NoInheritableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Member>         getMember();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EnumImpl
//*******************************************************************
class EnumImpl :
	  virtual public BON::ModelImpl
	, public ConstantTypeImpl
	, public NoInheritableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::EnumValue>      getEnumValue();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   FactoryOperationImpl
//*******************************************************************
class FactoryOperationImpl :
	  public HasExceptionsImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   HasOperationsImpl
//*******************************************************************
class HasOperationsImpl :
	  public InheritableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Aggregate>      getAggregate();
	virtual std::set<PICML::Alias>          getAlias();
	virtual std::set<PICML::Collection>     getCollection();
	virtual std::set<PICML::Constant>       getConstant();
	virtual std::set<PICML::Enum>           getEnum();
	virtual std::set<PICML::Exception>      getException();
	virtual std::set<PICML::NoInheritable>  getNoInheritable();
	virtual std::set<PICML::OnewayOperation>          getOnewayOperation();
	virtual std::set<PICML::SwitchedAggregate>        getSwitchedAggregate();
	virtual std::set<PICML::TwowayOperation>          getTwowayOperation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   LookupOperationImpl
//*******************************************************************
class LookupOperationImpl :
	  public HasExceptionsImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SwitchedAggregateImpl
//*******************************************************************
class SwitchedAggregateImpl :
	  virtual public BON::ModelImpl
	, public NoInheritableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Discriminator>  getDiscriminator();
	virtual std::set<PICML::Label>          getLabel();
	virtual std::set<PICML::LabelConnection>          getLabelConnection();
	virtual std::set<PICML::Member>         getMember();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TwowayOperationImpl
//*******************************************************************
class TwowayOperationImpl :
	  public HasExceptionsImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::InoutParameter> getInoutParameter();
	virtual std::set<PICML::OutParameter>   getOutParameter();
	virtual std::set<PICML::ReturnType>     getReturnType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AliasImpl
//*******************************************************************
class AliasImpl :
	  virtual public BON::ReferenceImpl
	, public NoInheritableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   CollectionImpl
//*******************************************************************
class CollectionImpl :
	  virtual public BON::ReferenceImpl
	, public NoInheritableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentFactoryImpl
//*******************************************************************
class ComponentFactoryImpl :
	  public HasOperationsImpl
	, public SupportsInterfacesImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Manageable>          getManagesComponentDsts();
	virtual std::set<PICML::ManagesComponent>         getOutManagesComponentLinks();
	//
	// kind and role getters
	virtual std::set<PICML::FactoryOperation>         getFactoryOperation();
	virtual std::set<PICML::LookupKey>      getLookupKey();
	virtual std::set<PICML::LookupOperation>          getLookupOperation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ObjectImpl
//*******************************************************************
class ObjectImpl :
	  public HasOperationsImpl
	, public ProvideableImpl
	, public PrefixableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isabstract() ;
	virtual bool        islocal() ;
	virtual void        setabstract( bool val);
	virtual void        setlocal( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ObjectByValueImpl
//*******************************************************************
class ObjectByValueImpl :
	  public HasOperationsImpl
	, public SupportsInterfacesImpl
	, public PrefixableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isabstract() ;
	virtual void        setabstract( bool val);
	//
	// kind and role getters
	virtual std::set<PICML::FactoryOperation>         getFactoryOperation();
	virtual std::set<PICML::MakeMemberPrivate>        getMakeMemberPrivate();
	virtual std::set<PICML::Member>         getMember();
	virtual std::set<PICML::PrivateFlag>    getPrivateFlag();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EventImpl
//*******************************************************************
class EventImpl :
	  public ObjectByValueImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ValueObjectImpl
//*******************************************************************
class ValueObjectImpl :
	  public ObjectByValueImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   RequirementSatisfierImpl
//*******************************************************************
class RequirementSatisfierImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getresourceType() ;
	virtual void        setresourceType( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::SatisfierProperty>        getSatisfierProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ElementsImpl
//*******************************************************************
class ElementsImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BridgeImpl
//*******************************************************************
class BridgeImpl :
	  virtual public BON::ModelImpl
	, public ElementsImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Interconnect>        getBridge2InterconnectDsts();
	virtual std::set<PICML::Interconnect2Bridge>      getInInterconnect2BridgeLinks();
	virtual std::multiset<PICML::Interconnect>        getInterconnect2BridgeSrcs();
	virtual std::set<PICML::Bridge2Interconnect>      getOutBridge2InterconnectLinks();
	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::Resource>       getResource();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   CapabilityImpl
//*******************************************************************
class CapabilityImpl :
	  public RequirementSatisfierImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ComponentImplementation> getImplementationCapabilitySrcs();
	virtual std::set<PICML::ImplementationCapability> getInImplementationCapabilityLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InterconnectImpl
//*******************************************************************
class InterconnectImpl :
	  virtual public BON::ModelImpl
	, public ElementsImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Bridge>    getBridge2InterconnectSrcs();
	virtual std::set<PICML::Bridge2Interconnect>      getInBridge2InterconnectLinks();
	virtual std::set<PICML::Node2Interconnect>        getInNode2InterconnectLinks();
	virtual std::multiset<PICML::Bridge>    getInterconnect2BridgeDsts();
	virtual std::multiset<PICML::Node>      getInterconnect2NodeDsts();
	virtual std::multiset<PICML::Node>      getNode2InterconnectSrcs();
	virtual std::set<PICML::Interconnect2Bridge>      getOutInterconnect2BridgeLinks();
	virtual std::set<PICML::Interconnect2Node>        getOutInterconnect2NodeLinks();
	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::Resource>       getResource();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   NodeImpl
//*******************************************************************
class NodeImpl :
	  virtual public BON::ModelImpl
	, public ElementsImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::Interconnect2Node>        getInInterconnect2NodeLinks();
	virtual std::multiset<PICML::Interconnect>        getInterconnect2NodeSrcs();
	virtual std::multiset<PICML::Interconnect>        getNode2InterconnectDsts();
	virtual std::set<PICML::Node2Interconnect>        getOutNode2InterconnectLinks();
	virtual std::set<PICML::Shares>         getOutSharesLinks();
	virtual std::multiset<PICML::SharedResource>      getSharesDsts();
	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::Resource>       getResource();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ResourceImpl
//*******************************************************************
class ResourceImpl :
	  public RequirementSatisfierImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SharedResourceImpl
//*******************************************************************
class SharedResourceImpl :
	  public ElementsImpl
	, public RequirementSatisfierImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::Shares>         getInSharesLinks();
	virtual std::multiset<PICML::Node>      getSharesSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   RequirementBaseImpl
//*******************************************************************
class RequirementBaseImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getresourceType() ;
	virtual void        setresourceType( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::Property>       getProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationRequirementImpl
//*******************************************************************
class ImplementationRequirementImpl :
	  public RequirementBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		None_ResourceUsageKind_Type,
		InstanceUsesResource_ResourceUsageKind_Type,
		ResourceUsesInstance_ResourceUsageKind_Type,
		PortUsesResource_ResourceUsageKind_Type,
		ResourceUsesPort_ResourceUsageKind_Type
	} ResourceUsageKind_Type;

	//
	// connectionEnd getters
	virtual std::set<PICML::MonolithDeployRequirement> getInMonolithDeployRequirementLinks();
	virtual std::multiset<PICML::MonolithicImplementation> getMonolithDeployRequirementSrcs();
	//
	// attribute getters and setters
	virtual PICML::ImplementationRequirementImpl::ResourceUsageKind_Type getResourceUsageKind();
	virtual std::string getcomponentPort() ;
	virtual std::string getresourcePort() ;
	virtual void        setResourceUsageKind( ImplementationRequirementImpl::ResourceUsageKind_Type val);
	virtual void        setcomponentPort( const std::string& val);
	virtual void        setresourcePort( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   RequirementImpl
//*******************************************************************
class RequirementImpl :
	  public RequirementBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ImplementationArtifact> getArtifactDeployRequirementSrcs();
	virtual std::multiset<PICML::PublishConnector>    getAssemblyDeployRequirementSrcs();
	virtual std::multiset<PICML::Component> getAssemblyselectRequirementSrcs();
	virtual std::set<PICML::ArtifactDeployRequirement> getInArtifactDeployRequirementLinks();
	virtual std::set<PICML::AssemblyDeployRequirement> getInAssemblyDeployRequirementLinks();
	virtual std::set<PICML::AssemblyselectRequirement> getInAssemblyselectRequirementLinks();
	virtual std::set<PICML::PackageConfSelectRequirement> getInPackageConfSelectRequirementLinks();
	virtual std::multiset<PICML::PackageConfiguration> getPackageConfSelectRequirementSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ECConfigurationImpl
//*******************************************************************
class ECConfigurationImpl :
	  public RequirementImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Consumer2BehaviorConnection> getConsumer2BehaviorConnection();
	virtual std::set<PICML::ECConsumer>     getECConsumer();
	virtual std::set<PICML::ECRole>         getECRole();
	virtual std::set<PICML::ECSupplier>     getECSupplier();
	virtual std::set<PICML::RecursiveFilterConnection> getRecursiveFilterConnection();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   RTRequirementsImpl
//*******************************************************************
class RTRequirementsImpl :
	  public RequirementImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ServiceConsumer>          getServiceConsumer();
	virtual std::set<PICML::ServiceProvider>          getServiceProvider();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   OperationImpl
//*******************************************************************
class OperationImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::Documentation>   getDocumentation();
	virtual std::set<WSML::FaultMessage>    getFaultMessage();
	virtual std::set<WSML::InputMessage>    getInputMessage();
	virtual std::set<WSML::MessageRef>      getMessageRef();
	virtual std::set<WSML::OutputMessage>   getOutputMessage();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   NotificationOperationImpl
//*******************************************************************
class NotificationOperationImpl :
	  public OperationImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::Output>          getOutput();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   OneWayOperationImpl
//*******************************************************************
class OneWayOperationImpl :
	  public OperationImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::Input>           getInput();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   RequestResponseOperationImpl
//*******************************************************************
class RequestResponseOperationImpl :
	  public OperationImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getparameterOrder() ;
	virtual void        setparameterOrder( const std::string& val);
	//
	// kind and role getters
	virtual std::set<WSML::Fault>           getFault();
	virtual std::set<WSML::Input>           getInput();
	virtual std::set<WSML::Output>          getOutput();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SolicitResponseOperationImpl
//*******************************************************************
class SolicitResponseOperationImpl :
	  public OperationImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getparameterOrder() ;
	virtual void        setparameterOrder( const std::string& val);
	//
	// kind and role getters
	virtual std::set<WSML::Fault>           getFault();
	virtual std::set<WSML::Input>           getInput();
	virtual std::set<WSML::Output>          getOutput();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentLibImpl
//*******************************************************************
class ComponentLibImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ExternalResources>   getExtResourceConnDsts();
	virtual std::set<PICML::ExtResourceConn>          getOutExtResourceConnLinks();
	//
	// attribute getters and setters
	virtual std::string getORBServices() ;
	virtual std::string getlibraryexport() ;
	virtual std::string getsharedname() ;
	virtual void        setORBServices( const std::string& val);
	virtual void        setlibraryexport( const std::string& val);
	virtual void        setsharedname( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ExecutorProjectImpl
//*******************************************************************
class ExecutorProjectImpl :
	  virtual public BON::ModelImpl
	, public ComponentLibImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ImplementationArtifactReference> getImplementationArtifactReference();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ServantProjectImpl
//*******************************************************************
class ServantProjectImpl :
	  virtual public BON::ModelImpl
	, public ComponentLibImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::FileRef>        getFileRef();
	virtual std::set<PICML::ImplementationArtifactReference> getImplementationArtifactReference();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   StubProjectImpl
//*******************************************************************
class StubProjectImpl :
	  virtual public BON::ModelImpl
	, public ComponentLibImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::FileRef>        getFileRef();
	virtual std::set<PICML::ImplementationArtifactReference> getImplementationArtifactReference();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ECRoleImpl
//*******************************************************************
class ECRoleImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isConfigureRTQoS() ;
	virtual void        setConfigureRTQoS( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ECConsumerImpl
//*******************************************************************
class ECConsumerImpl :
	  public ECRoleImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ECBehavior>          getConsumer2BehaviorConnectionDsts();
	virtual std::set<PICML::Consumer2BehaviorConnection> getOutConsumer2BehaviorConnectionLinks();
	//
	// kind and role getters
	virtual std::set<PICML::ECBehavior>     getECBehavior();
	virtual std::set<PICML::ECEventFilterConfiguration> getECEventFilterConfiguration();
	virtual std::set<PICML::RecursiveFilterConnection> getRecursiveFilterConnection();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ECSupplierImpl
//*******************************************************************
class ECSupplierImpl :
	  public ECRoleImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::Supplier2FilterConnection> getOutSupplier2FilterConnectionLinks();
	virtual std::multiset<PICML::ECEventFilterConfiguration> getSupplier2FilterConnectionDsts();
	//
	// kind and role getters
	virtual std::set<PICML::Supplier2FilterConnection> getSupplier2FilterConnection();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MetricsBaseImpl
//*******************************************************************
class MetricsBaseImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		seconds_resolution_Type,
		miliseconds_resolution_Type,
		microseconds_resolution_Type
	} resolution_Type;

	//
	// connectionEnd getters
	virtual std::multiset<PICML::BenchmarkType>       getBenchmarkCharacteristicsSrcs();
	virtual std::set<PICML::BenchmarkCharacteristics> getInBenchmarkCharacteristicsLinks();
	virtual std::set<PICML::MetricConnection>         getInMetricConnectionLinks();
	virtual std::multiset<PICML::OperationRef>        getMetricConnectionSrcs();
	virtual std::set<PICML::WorkloadCharacteristics>  getOutWorkloadCharacteristicsLinks();
	virtual std::multiset<PICML::TaskSet>   getWorkloadCharacteristicsDsts();
	//
	// attribute getters and setters
	virtual std::string getfileName() ;
	virtual long        getiterations() ;
	virtual long        getpriority() ;
	virtual long        getrate() ;
	virtual PICML::MetricsBaseImpl::resolution_Type   getresolution();
	virtual long        getwarmup() ;
	virtual void        setfileName( const std::string& val);
	virtual void        setiterations( const long val);
	virtual void        setpriority( const long val);
	virtual void        setrate( const long val);
	virtual void        setresolution( MetricsBaseImpl::resolution_Type val);
	virtual void        setwarmup( const long val);
	//
	// kind and role getters
	virtual std::set<PICML::Average>        getAverage();
	virtual std::set<PICML::DataAnalysisBase>         getDataAnalysisBase();
	virtual std::set<PICML::Jitter>         getJitter();
	virtual std::set<PICML::Maximum>        getMaximum();
	virtual std::set<PICML::Minimum>        getMinimum();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   LatencyImpl
//*******************************************************************
class LatencyImpl :
	  public MetricsBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ThroughputImpl
//*******************************************************************
class ThroughputImpl :
	  public MetricsBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkerPackageBaseImpl
//*******************************************************************
class WorkerPackageBaseImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Worker>         getWorker();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkerFileImpl
//*******************************************************************
class WorkerFileImpl :
	  public WorkerPackageBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getLocation() ;
	virtual void        setLocation( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::WorkerPackage>  getWorkerPackage();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkerPackageImpl
//*******************************************************************
class WorkerPackageImpl :
	  public WorkerPackageBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::WorkerPackage>  getWorkerPackage();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SchemaReferenceImpl
//*******************************************************************
class SchemaReferenceImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getid() ;
	virtual std::string getschemaLocation() ;
	virtual void        setid( const std::string& val);
	virtual void        setschemaLocation( const std::string& val);
	//
	// kind and role getters
	virtual std::set<WSML::Schema>          getSchema();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SchemaImportImpl
//*******************************************************************
class SchemaImportImpl :
	  public SchemaReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getnamespace() ;
	virtual void        setnamespace( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentImplementationImpl
//*******************************************************************
class ComponentImplementationImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Property>  getConfigPropertyDsts();
	virtual std::multiset<PICML::Capability>          getImplementationCapabilityDsts();
	virtual std::multiset<PICML::ImplementationDependency> getImplementationDependsOnDsts();
	virtual std::multiset<PICML::ComponentRef>        getImplementsDsts();
	virtual std::multiset<PICML::Property>  getInfoPropertyDsts();
	virtual std::set<PICML::ConfigProperty> getOutConfigPropertyLinks();
	virtual std::set<PICML::ImplementationCapability> getOutImplementationCapabilityLinks();
	virtual std::set<PICML::ImplementationDependsOn>  getOutImplementationDependsOnLinks();
	virtual std::set<PICML::Implements>     getOutImplementsLinks();
	virtual std::set<PICML::InfoProperty>   getOutInfoPropertyLinks();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentAssemblyImpl
//*******************************************************************
class ComponentAssemblyImpl :
	  virtual public BON::ModelImpl
	, public ComponentImplementationImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::PathReference>       getCriticalPathDsts();
	virtual std::set<PICML::CriticalPath>   getOutCriticalPathLinks();
	//
	// kind and role getters
	virtual std::set<PICML::AssemblyConfigProperty>   getAssemblyConfigProperty();
	virtual std::set<PICML::AssemblyDeployRequirement> getAssemblyDeployRequirement();
	virtual std::set<PICML::AssemblyselectRequirement> getAssemblyselectRequirement();
	virtual std::set<PICML::AttributeDelegate>        getAttributeDelegate();
	virtual std::set<PICML::AttributeMapping>         getAttributeMapping();
	virtual std::set<PICML::AttributeMappingDelegate> getAttributeMappingDelegate();
	virtual std::set<PICML::AttributeMappingValue>    getAttributeMappingValue();
	virtual std::set<PICML::AttributeValue> getAttributeValue();
	virtual std::set<PICML::Component>      getComponent();
	virtual std::set<PICML::ComponentAssembly>        getComponentAssembly();
	virtual std::set<PICML::ComponentAssemblyReference> getComponentAssemblyReference();
	virtual std::set<PICML::ComponentPackage>         getComponentPackage();
	virtual std::set<PICML::ComponentPackageReference> getComponentPackageReference();
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::ECConfiguration>          getECConfiguration();
	virtual std::set<PICML::EventSinkDelegate>        getEventSinkDelegate();
	virtual std::set<PICML::EventSourceDelegate>      getEventSourceDelegate();
	virtual std::set<PICML::ExternalDelegate>         getExternalDelegate();
	virtual std::set<PICML::ExternalReferenceEndPoint> getExternalReferenceEndPoint();
	virtual std::set<PICML::FacetDelegate>  getFacetDelegate();
	virtual std::set<PICML::InEventPort>    getInEventPort();
	virtual std::set<PICML::OutEventPort>   getOutEventPort();
	virtual std::set<PICML::Property>       getProperty();
	virtual std::set<PICML::ProvidedRequestPort>      getProvidedRequestPort();
	virtual std::set<PICML::PublishConnector>         getPublishConnector();
	virtual std::set<PICML::RTRequirements> getRTRequirements();
	virtual std::set<PICML::ReceptacleDelegate>       getReceptacleDelegate();
	virtual std::set<PICML::RequiredRequestPort>      getRequiredRequestPort();
	virtual std::set<PICML::Requirement>    getRequirement();
	virtual std::set<PICML::Requirement>    getRequirement(int dummy);
	virtual std::set<PICML::deliverTo>      getdeliverTo();
	virtual std::set<PICML::emit>           getemit();
	virtual std::set<PICML::invoke>         getinvoke();
	virtual std::set<PICML::publish>        getpublish();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MonolithicImplementationImpl
//*******************************************************************
class MonolithicImplementationImpl :
	  virtual public BON::AtomImpl
	, public ComponentImplementationImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ImplementationRequirement> getMonolithDeployRequirementDsts();
	virtual std::multiset<PICML::Property>  getMonolithExecParameterDsts();
	virtual std::multiset<PICML::ImplementationArtifactReference> getMonolithprimaryArtifactDsts();
	virtual std::set<PICML::MonolithDeployRequirement> getOutMonolithDeployRequirementLinks();
	virtual std::set<PICML::MonolithExecParameter>    getOutMonolithExecParameterLinks();
	virtual std::set<PICML::MonolithprimaryArtifact>  getOutMonolithprimaryArtifactLinks();
	//
	// attribute getters and setters
	virtual std::string getdefaultVersion() ;
	virtual void        setdefaultVersion( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ExtensibilityElementImpl
//*******************************************************************
class ExtensibilityElementImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isrequired() ;
	virtual void        setrequired( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ExtensibleBindingImpl
//*******************************************************************
class ExtensibleBindingImpl :
	  public ExtensibilityElementImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ExtensibleMessageImpl
//*******************************************************************
class ExtensibleMessageImpl :
	  public ExtensibilityElementImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		literal_use_Type,
		encoded_use_Type
	} use_Type;

	//
	// attribute getters and setters
	virtual std::string getencodingStyle() ;
	virtual std::string getnamespace() ;
	virtual WSML::ExtensibleMessageImpl::use_Type     getuse();
	virtual void        setencodingStyle( const std::string& val);
	virtual void        setnamespace( const std::string& val);
	virtual void        setuse( ExtensibleMessageImpl::use_Type val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ExtensibleOperationImpl
//*******************************************************************
class ExtensibleOperationImpl :
	  public ExtensibilityElementImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ExtensiblePortImpl
//*******************************************************************
class ExtensiblePortImpl :
	  public ExtensibilityElementImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPHeadersImpl
//*******************************************************************
class SOAPHeadersImpl :
	  public ExtensibleMessageImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::IORef>      getHeaderBindingSrcs();
	virtual std::multiset<WSML::MessageRef> getHeaderMessageDsts();
	virtual std::multiset<WSML::PartRef>    getHeaderPartDsts();
	virtual std::set<WSML::HeaderBinding>   getInHeaderBindingLinks();
	virtual std::set<WSML::HeaderMessage>   getOutHeaderMessageLinks();
	virtual std::set<WSML::HeaderPart>      getOutHeaderPartLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPAddressImpl
//*******************************************************************
class SOAPAddressImpl :
	  virtual public BON::AtomImpl
	, public ExtensiblePortImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getlocation() ;
	virtual void        setlocation( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPBindingImpl
//*******************************************************************
class SOAPBindingImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleBindingImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		document_style_Type,
		rpc_style_Type
	} style_Type;

	//
	// attribute getters and setters
	virtual WSML::SOAPBindingImpl::style_Type         getstyle();
	virtual std::string gettransport() ;
	virtual void        setstyle( SOAPBindingImpl::style_Type val);
	virtual void        settransport( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPBodyImpl
//*******************************************************************
class SOAPBodyImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleMessageImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::IORef>      getBodyBindingSrcs();
	virtual std::multiset<WSML::PartRef>    getBodyPartsDsts();
	virtual std::set<WSML::BodyBinding>     getInBodyBindingLinks();
	virtual std::set<WSML::BodyParts>       getOutBodyPartsLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPFaultImpl
//*******************************************************************
class SOAPFaultImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleMessageImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<WSML::SOAPFaultExtension>        getInSOAPFaultExtensionLinks();
	virtual std::multiset<WSML::FaultRef>   getSOAPFaultExtensionSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPOperationImpl
//*******************************************************************
class SOAPOperationImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleOperationImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		document_style_Type,
		rpc_style_Type
	} style_Type;

	//
	// attribute getters and setters
	virtual std::string getsoapAction() ;
	virtual WSML::SOAPOperationImpl::style_Type       getstyle();
	virtual void        setsoapAction( const std::string& val);
	virtual void        setstyle( SOAPOperationImpl::style_Type val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPHeaderImpl
//*******************************************************************
class SOAPHeaderImpl :
	  virtual public BON::ModelImpl
	, public SOAPHeadersImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::SOAPHeaderFault> getSOAPHeaderFault();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPHeaderFaultImpl
//*******************************************************************
class SOAPHeaderFaultImpl :
	  virtual public BON::AtomImpl
	, public SOAPHeadersImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ReferrableImpl
//*******************************************************************
class ReferrableImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ElementImpl
//*******************************************************************
class ElementImpl :
	  virtual public BON::ModelImpl
	, public ReferrableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		local_schemaType_Type,
		element_schemaType_Type,
		attribute_schemaType_Type,
		complexType_schemaType_Type,
		simpleType_schemaType_Type,
		include_schemaType_Type,
		import_schemaType_Type,
		redefine_schemaType_Type,
		any_schemaType_Type,
		anyAttribute_schemaType_Type,
		group_schemaType_Type,
		attributeGroup_schemaType_Type,
		key_schemaType_Type,
		keyref_schemaType_Type,
		unique_schemaType_Type,
		annotation_schemaType_Type,
		documentation_schemaType_Type,
		appinfo_schemaType_Type,
		notation_schemaType_Type
	} schemaType_Type;

	//
	// attribute getters and setters
	virtual long        getOrder() ;
	virtual WSML::ElementImpl::schemaType_Type        getschemaType();
	virtual void        setOrder( const long val);
	virtual void        setschemaType( ElementImpl::schemaType_Type val);
	//
	// kind and role getters
	virtual std::set<WSML::Attribute>       getAttribute();
	virtual std::set<WSML::Element>         getElement();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   AtomicTypeImpl
//*******************************************************************
class AtomicTypeImpl :
	  virtual public BON::AtomImpl
	, public ReferrableImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		string_typeCode_Type,
		boolean_typeCode_Type,
		float_typeCode_Type,
		double_typeCode_Type,
		decimal_typeCode_Type,
		duration_typeCode_Type,
		dateTime_typeCode_Type,
		time_typeCode_Type,
		date_typeCode_Type,
		gYearMonth_typeCode_Type,
		gYear_typeCode_Type,
		gMonthDay_typeCode_Type,
		gDay_typeCode_Type,
		gMonth_typeCode_Type,
		hexBinary_typeCode_Type,
		base64Binary_typeCode_Type,
		anyURI_typeCode_Type,
		QName_typeCode_Type,
		NOTATION_typeCode_Type,
		normalizedString_typeCode_Type,
		token_typeCode_Type,
		language_typeCode_Type,
		IDREFS_typeCode_Type,
		ENTITIES_typeCode_Type,
		NMTOKEN_typeCode_Type,
		NMTOKENS_typeCode_Type,
		name_typeCode_Type,
		NCName_typeCode_Type,
		ID_typeCode_Type,
		IDREF_typeCode_Type,
		ENTITY_typeCode_Type,
		integer_typeCode_Type,
		nonPositiveInteger_typeCode_Type,
		negativeInteger_typeCode_Type,
		long_typeCode_Type,
		int_typeCode_Type,
		short_typeCode_Type,
		byte_typeCode_Type,
		nonNegativeInteger_typeCode_Type,
		unsignedLong_typeCode_Type,
		unsignedInt_typeCode_Type,
		unsignedShort_typeCode_Type,
		unsignedByte_typeCode_Type,
		positiveInteger_typeCode_Type
	} typeCode_Type;

	//
	// attribute getters and setters
	virtual WSML::AtomicTypeImpl::typeCode_Type       gettypeCode();
	virtual void        settypeCode( AtomicTypeImpl::typeCode_Type val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ArtifactContainerImpl
//*******************************************************************
class ArtifactContainerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ArtifactDependency>       getArtifactDependency();
	virtual std::set<PICML::ArtifactDependsOn>        getArtifactDependsOn();
	virtual std::set<PICML::ArtifactDeployRequirement> getArtifactDeployRequirement();
	virtual std::set<PICML::ArtifactExecParameter>    getArtifactExecParameter();
	virtual std::set<PICML::ArtifactInfoProperty>     getArtifactInfoProperty();
	virtual std::set<PICML::ECConfiguration>          getECConfiguration();
	virtual std::set<PICML::ImplementationArtifact>   getImplementationArtifact();
	virtual std::set<PICML::ImplementationArtifactReference> getImplementationArtifactReference();
	virtual std::set<PICML::Property>       getProperty();
	virtual std::set<PICML::RTRequirements> getRTRequirements();
	virtual std::set<PICML::Requirement>    getRequirement();
	virtual std::set<PICML::Requirement>    getRequirement(int dummy);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BenchmarkAnalysisImpl
//*******************************************************************
class BenchmarkAnalysisImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Average>        getAverage();
	virtual std::set<PICML::BenchmarkCharacteristics> getBenchmarkCharacteristics();
	virtual std::set<PICML::BenchmarkType>  getBenchmarkType();
	virtual std::set<PICML::CompRef>        getCompRef();
	virtual std::set<PICML::ComponentOperation>       getComponentOperation();
	virtual std::set<PICML::DataAnalysisBase>         getDataAnalysisBase();
	virtual std::set<PICML::Event>          getEvent();
	virtual std::set<PICML::EventRef>       getEventRef();
	virtual std::set<PICML::FactoryOperation>         getFactoryOperation();
	virtual std::set<PICML::FixedIterationBenchmarks> getFixedIterationBenchmarks();
	virtual std::set<PICML::Jitter>         getJitter();
	virtual std::set<PICML::Latency>        getLatency();
	virtual std::set<PICML::LookupOperation>          getLookupOperation();
	virtual std::set<PICML::Maximum>        getMaximum();
	virtual std::set<PICML::MetricConnection>         getMetricConnection();
	virtual std::set<PICML::MetricsBase>    getMetricsBase();
	virtual std::set<PICML::Minimum>        getMinimum();
	virtual std::set<PICML::OnewayOperation>          getOnewayOperation();
	virtual std::set<PICML::OperationBase>  getOperationBase();
	virtual std::set<PICML::OperationRef>   getOperationRef();
	virtual std::set<PICML::PeriodicBenchmarks>       getPeriodicBenchmarks();
	virtual std::set<PICML::Task>           getTask();
	virtual std::set<PICML::TaskSet>        getTaskSet();
	virtual std::set<PICML::Throughput>     getThroughput();
	virtual std::set<PICML::TimeProbe>      getTimeProbe();
	virtual std::set<PICML::TimerConnection>          getTimerConnection();
	virtual std::set<PICML::TimerEventSinkConn>       getTimerEventSinkConn();
	virtual std::set<PICML::TriggerBenchmarks>        getTriggerBenchmarks();
	virtual std::set<PICML::TwowayOperation>          getTwowayOperation();
	virtual std::set<PICML::WorkLoadOperationConnection> getWorkLoadOperationConnection();
	virtual std::set<PICML::WorkloadCharacteristics>  getWorkloadCharacteristics();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   BindingImpl
//*******************************************************************
class BindingImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::PortType>   getBindingPortTypeDsts();
	virtual std::set<WSML::BindingPortType> getOutBindingPortTypeLinks();
	//
	// kind and role getters
	virtual std::set<WSML::BindingOperation>          getBindingOperation();
	virtual std::set<WSML::BindsOperation>  getBindsOperation();
	virtual std::set<WSML::Documentation>   getDocumentation();
	virtual std::set<WSML::OperationRef>    getOperationRef();
	virtual std::set<WSML::SOAPBinding>     getSOAPBinding();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   BindingOperationImpl
//*******************************************************************
class BindingOperationImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::OperationRef>         getBindsOperationDsts();
	virtual std::set<WSML::BindsOperation>  getOutBindsOperationLinks();
	//
	// kind and role getters
	virtual std::set<WSML::BodyBinding>     getBodyBinding();
	virtual std::set<WSML::BodyParts>       getBodyParts();
	virtual std::set<WSML::Documentation>   getDocumentation();
	virtual std::set<WSML::ExtensibleMessage>         getExtensibleMessage();
	virtual std::set<WSML::FaultRef>        getFaultRef();
	virtual std::set<WSML::HeaderBinding>   getHeaderBinding();
	virtual std::set<WSML::HeaderMessage>   getHeaderMessage();
	virtual std::set<WSML::HeaderPart>      getHeaderPart();
	virtual std::set<WSML::IORef>           getIORef();
	virtual std::set<WSML::InputRef>        getInputRef();
	virtual std::set<WSML::MessageRef>      getMessageRef();
	virtual std::set<WSML::OutputRef>       getOutputRef();
	virtual std::set<WSML::PartRef>         getPartRef();
	virtual std::set<WSML::SOAPBody>        getSOAPBody();
	virtual std::set<WSML::SOAPFault>       getSOAPFault();
	virtual std::set<WSML::SOAPFaultExtension>        getSOAPFaultExtension();
	virtual std::set<WSML::SOAPHeader>      getSOAPHeader();
	virtual std::set<WSML::SOAPHeaderFault> getSOAPHeaderFault();
	virtual std::set<WSML::SOAPOperation>   getSOAPOperation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentContainerImpl
//*******************************************************************
class ComponentContainerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ComponentConfigProperty>  getComponentConfigProperty();
	virtual std::set<PICML::ComponentInfoProperty>    getComponentInfoProperty();
	virtual std::set<PICML::ComponentProperty>        getComponentProperty();
	virtual std::set<PICML::ComponentPropertyDescription> getComponentPropertyDescription();
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::Property>       getProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentImplementationContainerImpl
//*******************************************************************
class ComponentImplementationContainerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Capability>     getCapability();
	virtual std::set<PICML::ComponentAssembly>        getComponentAssembly();
	virtual std::set<PICML::ComponentImplementation>  getComponentImplementation();
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::ConfigProperty> getConfigProperty();
	virtual std::set<PICML::CriticalPath>   getCriticalPath();
	virtual std::set<PICML::ImplementationArtifactReference> getImplementationArtifactReference();
	virtual std::set<PICML::ImplementationCapability> getImplementationCapability();
	virtual std::set<PICML::ImplementationDependency> getImplementationDependency();
	virtual std::set<PICML::ImplementationDependsOn>  getImplementationDependsOn();
	virtual std::set<PICML::ImplementationRequirement> getImplementationRequirement();
	virtual std::set<PICML::Implements>     getImplements();
	virtual std::set<PICML::InfoProperty>   getInfoProperty();
	virtual std::set<PICML::MonolithDeployRequirement> getMonolithDeployRequirement();
	virtual std::set<PICML::MonolithExecParameter>    getMonolithExecParameter();
	virtual std::set<PICML::MonolithicImplementation> getMonolithicImplementation();
	virtual std::set<PICML::MonolithprimaryArtifact>  getMonolithprimaryArtifact();
	virtual std::set<PICML::PathReference>  getPathReference();
	virtual std::set<PICML::Property>       getProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentPropertyDescriptionImpl
//*******************************************************************
class ComponentPropertyDescriptionImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ComponentRef>        getComponentPropertySrcs();
	virtual std::set<PICML::ComponentProperty>        getInComponentPropertyLinks();
	//
	// kind and role getters
	virtual std::set<PICML::DataType>       getDataType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   DefinitionsImpl
//*******************************************************************
class DefinitionsImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string gettargetNamespace() ;
	virtual void        settargetNamespace( const std::string& val);
	//
	// kind and role getters
	virtual std::set<WSML::Attribute>       getAttribute();
	virtual std::set<WSML::Binding>         getBinding();
	virtual std::set<WSML::BindingPortType> getBindingPortType();
	virtual std::set<WSML::Documentation>   getDocumentation();
	virtual std::set<WSML::Import>          getImport();
	virtual std::set<WSML::Messages>        getMessages();
	virtual std::set<WSML::PortType>        getPortType();
	virtual std::set<WSML::Service>         getService();
	virtual std::set<WSML::ServiceRef>      getServiceRef();
	virtual std::set<WSML::Types>           getTypes();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DeploymentPlanImpl
//*******************************************************************
class DeploymentPlanImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::CollocationGroup>         getCollocationGroup();
	virtual std::set<PICML::ComponentAssemblyReference> getComponentAssemblyReference();
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::InstanceMapping>          getInstanceMapping();
	virtual std::set<PICML::NodeReference>  getNodeReference();
	virtual std::set<PICML::Property>       getProperty();
	virtual std::set<PICML::SharedComponentReference> getSharedComponentReference();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   DocumentationImpl
//*******************************************************************
class DocumentationImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getDocText() ;
	virtual bool        isMixed() ;
	virtual void        setDocText( const std::string& val);
	virtual void        setMixed( bool val);
	//
	// kind and role getters
	virtual std::set<WSML::Element>         getElement();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DomainImpl
//*******************************************************************
class DomainImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::Bridge>         getBridge();
	virtual std::set<PICML::Bridge2Interconnect>      getBridge2Interconnect();
	virtual std::set<PICML::Elements>       getElements();
	virtual std::set<PICML::Interconnect>   getInterconnect();
	virtual std::set<PICML::Interconnect2Bridge>      getInterconnect2Bridge();
	virtual std::set<PICML::Interconnect2Node>        getInterconnect2Node();
	virtual std::set<PICML::Node>           getNode();
	virtual std::set<PICML::Node2Interconnect>        getNode2Interconnect();
	virtual std::set<PICML::Property>       getProperty();
	virtual std::set<PICML::SharedResource> getSharedResource();
	virtual std::set<PICML::Shares>         getShares();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   FaultImpl
//*******************************************************************
class FaultImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::MessageRef> getFaultMessageDsts();
	virtual std::set<WSML::FaultMessage>    getOutFaultMessageLinks();
	//
	// kind and role getters
	virtual std::set<WSML::Documentation>   getDocumentation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ImportImpl
//*******************************************************************
class ImportImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getlocation() ;
	virtual std::string getnamespace() ;
	virtual void        setlocation( const std::string& val);
	virtual void        setnamespace( const std::string& val);
	//
	// kind and role getters
	virtual std::set<WSML::Definitions>     getDefinitions();
	virtual std::set<WSML::Documentation>   getDocumentation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   InputImpl
//*******************************************************************
class InputImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::MessageRef> getInputMessageDsts();
	virtual std::set<WSML::InputMessage>    getOutInputMessageLinks();
	//
	// kind and role getters
	virtual std::set<WSML::Documentation>   getDocumentation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InputActionImpl
//*******************************************************************
class InputActionImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::StateBase> getFinishSrcs();
	virtual std::set<PICML::Finish>         getInFinishLinks();
	virtual std::set<PICML::Input>          getInInputLinks();
	virtual std::set<PICML::MultiInput>     getInMultiInputLinks();
	virtual std::multiset<PICML::StateBase> getInputEffectDsts();
	virtual std::multiset<PICML::SingleInputBase>     getInputSrcs();
	virtual std::multiset<PICML::MultiInputBase>      getMultiInputSrcs();
	virtual std::set<PICML::InputEffect>    getOutInputEffectLinks();
	//
	// kind and role getters
	virtual std::set<PICML::Property>       getProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MPCImpl
//*******************************************************************
class MPCImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Project>        getProject();
	virtual std::set<PICML::Workspaces>     getWorkspaces();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   MessageImpl
//*******************************************************************
class MessageImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::Part>            getPart();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   MessagesImpl
//*******************************************************************
class MessagesImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::Message>         getMessage();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   OutputImpl
//*******************************************************************
class OutputImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<WSML::OutputMessage>   getOutOutputMessageLinks();
	virtual std::multiset<WSML::MessageRef> getOutputMessageDsts();
	//
	// kind and role getters
	virtual std::set<WSML::Documentation>   getDocumentation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfigurationContainerImpl
//*******************************************************************
class PackageConfigurationContainerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ComponentPackage>         getComponentPackage();
	virtual std::set<PICML::ComponentPackageReference> getComponentPackageReference();
	virtual std::set<PICML::ECConfiguration>          getECConfiguration();
	virtual std::set<PICML::PackageConfBasePackage>   getPackageConfBasePackage();
	virtual std::set<PICML::PackageConfConfigProperty> getPackageConfConfigProperty();
	virtual std::set<PICML::PackageConfReference>     getPackageConfReference();
	virtual std::set<PICML::PackageConfSelectRequirement> getPackageConfSelectRequirement();
	virtual std::set<PICML::PackageConfSpecializedConfig> getPackageConfSpecializedConfig();
	virtual std::set<PICML::PackageConfiguration>     getPackageConfiguration();
	virtual std::set<PICML::Property>       getProperty();
	virtual std::set<PICML::RTRequirements> getRTRequirements();
	virtual std::set<PICML::Requirement>    getRequirement();
	virtual std::set<PICML::Requirement>    getRequirement(int dummy);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageContainerImpl
//*******************************************************************
class PackageContainerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ComponentImplementationReference> getComponentImplementationReference();
	virtual std::set<PICML::ComponentPackage>         getComponentPackage();
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::Implementation> getImplementation();
	virtual std::set<PICML::PackageConfigProperty>    getPackageConfigProperty();
	virtual std::set<PICML::PackageInfoProperty>      getPackageInfoProperty();
	virtual std::set<PICML::PackageInterface>         getPackageInterface();
	virtual std::set<PICML::Property>       getProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PathImpl
//*******************************************************************
class PathImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::PathProperty>   getOutPathPropertyLinks();
	virtual std::multiset<PICML::Property>  getPathPropertyDsts();
	//
	// kind and role getters
	virtual std::set<PICML::ComponentRef>   getComponentRef();
	virtual std::set<PICML::ConnectedComponent>       getConnectedComponent();
	virtual std::set<PICML::DisplayNode>    getDisplayNode();
	virtual std::set<PICML::DstEdge>        getDstEdge();
	virtual std::set<PICML::Edge>           getEdge();
	virtual std::set<PICML::EdgeProperty>   getEdgeProperty();
	virtual std::set<PICML::GraphVertex>    getGraphVertex();
	virtual std::set<PICML::InEventPort>    getInEventPort();
	virtual std::set<PICML::OutEventPort>   getOutEventPort();
	virtual std::set<PICML::Property>       getProperty();
	virtual std::set<PICML::ProvidedRequestPort>      getProvidedRequestPort();
	virtual std::set<PICML::RequiredRequestPort>      getRequiredRequestPort();
	virtual std::set<PICML::SrcEdge>        getSrcEdge();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PathsImpl
//*******************************************************************
class PathsImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::Path>           getPath();
	virtual std::set<PICML::PathProperty>   getPathProperty();
	virtual std::set<PICML::Property>       getProperty();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   PortImpl
//*******************************************************************
class PortImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<WSML::PortBinding>     getOutPortBindingLinks();
	virtual std::set<SIML::PortProxy>       getOutPortProxyLinks();
	virtual std::multiset<WSML::BindingRef> getPortBindingDsts();
	virtual std::multiset<BON::ConnectionEnd>         getPortProxyDsts();
	//
	// kind and role getters
	virtual std::set<WSML::Documentation>   getDocumentation();
	virtual std::set<WSML::SOAPAddress>     getSOAPAddress();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   PortTypeImpl
//*******************************************************************
class PortTypeImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::Binding>    getBindingPortTypeSrcs();
	virtual std::set<WSML::BindingPortType> getInBindingPortTypeLinks();
	//
	// kind and role getters
	virtual std::set<WSML::Documentation>   getDocumentation();
	virtual std::set<WSML::NotificationOperation>     getNotificationOperation();
	virtual std::set<WSML::OneWayOperation> getOneWayOperation();
	virtual std::set<WSML::Operation>       getOperation();
	virtual std::set<WSML::RequestResponseOperation>  getRequestResponseOperation();
	virtual std::set<WSML::SolicitResponseOperation>  getSolicitResponseOperation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ProjectImpl
//*******************************************************************
class ProjectImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ComponentLib>   getComponentLib();
	virtual std::set<PICML::ExecutorProject>          getExecutorProject();
	virtual std::set<PICML::ExtResourceConn>          getExtResourceConn();
	virtual std::set<PICML::ExternalResources>        getExternalResources();
	virtual std::set<PICML::ImplementationArtifact>   getImplementationArtifact();
	virtual std::set<PICML::ServantProject> getServantProject();
	virtual std::set<PICML::StubProject>    getStubProject();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PropertyImpl
//*******************************************************************
class PropertyImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ImplementationArtifact> getArtifactExecParameterSrcs();
	virtual std::multiset<PICML::ImplementationArtifact> getArtifactInfoPropertySrcs();
	virtual std::multiset<PICML::Component> getAssemblyConfigPropertySrcs();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeMappingValueSrcs();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeValueSrcs();
	virtual std::multiset<PICML::ComponentRef>        getComponentConfigPropertySrcs();
	virtual std::multiset<PICML::ComponentRef>        getComponentInfoPropertySrcs();
	virtual std::multiset<PICML::ComponentImplementation> getConfigPropertySrcs();
	virtual std::multiset<PICML::Edge>      getEdgePropertyDsts();
	virtual std::set<PICML::ArtifactExecParameter>    getInArtifactExecParameterLinks();
	virtual std::set<PICML::ArtifactInfoProperty>     getInArtifactInfoPropertyLinks();
	virtual std::set<PICML::AssemblyConfigProperty>   getInAssemblyConfigPropertyLinks();
	virtual std::set<PICML::AttributeMappingValue>    getInAttributeMappingValueLinks();
	virtual std::set<PICML::AttributeValue> getInAttributeValueLinks();
	virtual std::set<PICML::ComponentConfigProperty>  getInComponentConfigPropertyLinks();
	virtual std::set<PICML::ComponentInfoProperty>    getInComponentInfoPropertyLinks();
	virtual std::set<PICML::ConfigProperty> getInConfigPropertyLinks();
	virtual std::set<PICML::InfoProperty>   getInInfoPropertyLinks();
	virtual std::set<PICML::MonolithExecParameter>    getInMonolithExecParameterLinks();
	virtual std::set<PICML::PackageConfConfigProperty> getInPackageConfConfigPropertyLinks();
	virtual std::set<PICML::PackageConfigProperty>    getInPackageConfigPropertyLinks();
	virtual std::set<PICML::PackageInfoProperty>      getInPackageInfoPropertyLinks();
	virtual std::set<PICML::PathProperty>   getInPathPropertyLinks();
	virtual std::multiset<PICML::ComponentImplementation> getInfoPropertySrcs();
	virtual std::multiset<PICML::MonolithicImplementation> getMonolithExecParameterSrcs();
	virtual std::set<PICML::EdgeProperty>   getOutEdgePropertyLinks();
	virtual std::multiset<PICML::PackageConfiguration> getPackageConfConfigPropertySrcs();
	virtual std::multiset<PICML::ComponentPackage>    getPackageConfigPropertySrcs();
	virtual std::multiset<PICML::ComponentPackage>    getPackageInfoPropertySrcs();
	virtual std::multiset<PICML::Path>      getPathPropertySrcs();
	//
	// attribute getters and setters
	virtual std::string getDataValue() ;
	virtual void        setDataValue( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::DataType>       getDataType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SatisfierPropertyImpl
//*******************************************************************
class SatisfierPropertyImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		Quantity_SatisfierPropertyKind_Type,
		Capacity_SatisfierPropertyKind_Type,
		Minimum_SatisfierPropertyKind_Type,
		Maximum_SatisfierPropertyKind_Type,
		Selection_SatisfierPropertyKind_Type,
		Attribute_SatisfierPropertyKind_Type
	} SatisfierPropertyKind_Type;

	//
	// attribute getters and setters
	virtual std::string getDataValue() ;
	virtual PICML::SatisfierPropertyImpl::SatisfierPropertyKind_Type getSatisfierPropertyKind();
	virtual bool        isdynamic() ;
	virtual void        setDataValue( const std::string& val);
	virtual void        setSatisfierPropertyKind( SatisfierPropertyImpl::SatisfierPropertyKind_Type val);
	virtual void        setdynamic( bool val);
	//
	// kind and role getters
	virtual std::set<PICML::DataType>       getDataType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SchemaImpl
//*******************************************************************
class SchemaImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string gettargetNamespace() ;
	virtual void        settargetNamespace( const std::string& val);
	//
	// kind and role getters
	virtual std::set<WSML::Attribute>       getAttribute();
	virtual std::set<WSML::Element>         getElement();
	virtual std::set<WSML::SchemaImport>    getSchemaImport();
	virtual std::set<WSML::SchemaReference> getSchemaReference();
	virtual std::set<WSML::SchemaReference> getSchemaReference(int dummy);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SchemaBuiltinsImpl
//*******************************************************************
class SchemaBuiltinsImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::AtomicType>      getAtomicType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ServiceImpl
//*******************************************************************
class ServiceImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::BindingRef>      getBindingRef();
	virtual std::set<WSML::Port>            getPort();
	virtual std::set<WSML::PortBinding>     getPortBinding();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ServiceProviderImpl
//*******************************************************************
class ServiceProviderImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isfixed_prioirty_service_execution() ;
	virtual void        setfixed_prioirty_service_execution( bool val);
	//
	// kind and role getters
	virtual std::set<PICML::MultipleServiceRequests>  getMultipleServiceRequests();
	virtual std::set<PICML::ServiceLevels>  getServiceLevels();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace SIML
{
//*******************************************************************
//   C  L  A  S  S   SystemImpl
//*******************************************************************
class SystemImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::ComponentAssemblyReference> getPICMLComponentAssemblyReference();
	virtual std::set<SIML::PortProxy>       getPortProxy();
	virtual std::set<SIML::System>          getSystem();
	virtual std::set<WSML::ServiceRef>      getWSMLServiceRef();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TopLevelPackageContainerImpl
//*******************************************************************
class TopLevelPackageContainerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<PICML::PackageConfigurationReference> getPackageConfigurationReference();
	virtual std::set<PICML::TopLevelPackage>          getTopLevelPackage();
	virtual std::set<PICML::package>        getpackage();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   TypesImpl
//*******************************************************************
class TypesImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<WSML::Documentation>   getDocumentation();
	virtual std::set<WSML::Schema>          getSchema();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkerImpl
//*******************************************************************
class WorkerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isAbstract() ;
	virtual void        setAbstract( bool val);
	//
	// kind and role getters
	virtual std::set<PICML::Action>         getAction();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkerLibraryImpl
//*******************************************************************
class WorkerLibraryImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getLocation() ;
	virtual void        setLocation( const std::string& val);
	//
	// kind and role getters
	virtual std::set<PICML::WorkerFile>     getWorkerFile();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BenchmarkTypeImpl
//*******************************************************************
class BenchmarkTypeImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::MetricsBase>         getBenchmarkCharacteristicsDsts();
	virtual std::set<PICML::BenchmarkCharacteristics> getOutBenchmarkCharacteristicsLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   FixedIterationBenchmarksImpl
//*******************************************************************
class FixedIterationBenchmarksImpl :
	  virtual public BON::AtomImpl
	, public BenchmarkTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual long        getbenchmarkIterations() ;
	virtual void        setbenchmarkIterations( const long val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PeriodicBenchmarksImpl
//*******************************************************************
class PeriodicBenchmarksImpl :
	  virtual public BON::AtomImpl
	, public BenchmarkTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual long        gettimeperiod() ;
	virtual void        settimeperiod( const long val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TriggerBenchmarksImpl
//*******************************************************************
class TriggerBenchmarksImpl :
	  virtual public BON::AtomImpl
	, public BenchmarkTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DataAnalysisBaseImpl
//*******************************************************************
class DataAnalysisBaseImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AverageImpl
//*******************************************************************
class AverageImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   JitterImpl
//*******************************************************************
class JitterImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MaximumImpl
//*******************************************************************
class MaximumImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MinimumImpl
//*******************************************************************
class MinimumImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   IORefImpl
//*******************************************************************
class IORefImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::SOAPBody>   getBodyBindingDsts();
	virtual std::multiset<WSML::SOAPHeaders>          getHeaderBindingDsts();
	virtual std::set<WSML::BodyBinding>     getOutBodyBindingLinks();
	virtual std::set<WSML::HeaderBinding>   getOutHeaderBindingLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   InputRefImpl
//*******************************************************************
class InputRefImpl :
	  virtual public BON::ReferenceImpl
	, public IORefImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual WSML::Input getInput();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   OutputRefImpl
//*******************************************************************
class OutputRefImpl :
	  virtual public BON::ReferenceImpl
	, public IORefImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual WSML::Output                    getOutput();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   AttributeImpl
//*******************************************************************
class AttributeImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getValue() ;
	virtual void        setValue( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   StateBaseImpl
//*******************************************************************
class StateBaseImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ActionBase>          getEffectSrcs();
	virtual std::multiset<PICML::InputAction>         getFinishDsts();
	virtual std::set<PICML::Effect>         getInEffectLinks();
	virtual std::set<PICML::InputEffect>    getInInputEffectLinks();
	virtual std::multiset<PICML::InputAction>         getInputEffectSrcs();
	virtual std::set<PICML::Finish>         getOutFinishLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BranchStateImpl
//*******************************************************************
class BranchStateImpl :
	  public StateBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ActionBase>          getBranchTransitionDsts();
	virtual std::set<PICML::BranchTransition>         getOutBranchTransitionLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   StateImpl
//*******************************************************************
class StateImpl :
	  public StateBaseImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::Transition>     getOutTransitionLinks();
	virtual std::multiset<PICML::ActionBase>          getTransitionDsts();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentPackageImpl
//*******************************************************************
class ComponentPackageImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ComponentImplementationReference> getImplementationDsts();
	virtual std::set<PICML::PackageConfBasePackage>   getInPackageConfBasePackageLinks();
	virtual std::set<PICML::Implementation> getOutImplementationLinks();
	virtual std::set<PICML::PackageConfigProperty>    getOutPackageConfigPropertyLinks();
	virtual std::set<PICML::PackageInfoProperty>      getOutPackageInfoPropertyLinks();
	virtual std::set<PICML::PackageInterface>         getOutPackageInterfaceLinks();
	virtual std::multiset<PICML::PackageConfiguration> getPackageConfBasePackageSrcs();
	virtual std::multiset<PICML::Property>  getPackageConfigPropertyDsts();
	virtual std::multiset<PICML::Property>  getPackageInfoPropertyDsts();
	virtual std::multiset<PICML::ComponentRef>        getPackageInterfaceDsts();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ECBehaviorImpl
//*******************************************************************
class ECBehaviorImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ECConsumer>          getConsumer2BehaviorConnectionSrcs();
	virtual std::set<PICML::Consumer2BehaviorConnection> getInConsumer2BehaviorConnectionLinks();
	//
	// attribute getters and setters
	virtual std::string getDispatchingMultithreadingLevel() ;
	virtual bool        isConsumerBasedFiltering() ;
	virtual bool        isDisconnectDanglingConnections() ;
	virtual bool        isMultithreadedConsumer() ;
	virtual bool        isMultithreadedSupplier() ;
	virtual bool        isSupplierBasedFiltering() ;
	virtual void        setConsumerBasedFiltering( bool val);
	virtual void        setDisconnectDanglingConnections( bool val);
	virtual void        setDispatchingMultithreadingLevel( const std::string& val);
	virtual void        setMultithreadedConsumer( bool val);
	virtual void        setMultithreadedSupplier( bool val);
	virtual void        setSupplierBasedFiltering( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ECEventFilterConfigurationImpl
//*******************************************************************
class ECEventFilterConfigurationImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		GroupOR_ECFilterType_Type,
		LogicalAND_ECFilterType_Type,
		GroupAND_ECFilterType_Type
	} ECFilterType_Type;

	//
	// connectionEnd getters
	virtual std::set<PICML::RecursiveFilterConnection> getInRecursiveFilterConnectionLinks();
	virtual std::set<PICML::Supplier2FilterConnection> getInSupplier2FilterConnectionLinks();
	virtual std::set<PICML::RecursiveFilterConnection> getOutRecursiveFilterConnectionLinks();
	virtual std::multiset<PICML::ECEventFilterConfiguration> getRecursiveFilterConnectionDsts();
	virtual std::set<PICML::RecursiveFilterConnection> getRecursiveFilterConnectionLinks();
	virtual std::multiset<PICML::ECEventFilterConfiguration> getRecursiveFilterConnectionSrcs();
	virtual std::multiset<PICML::ECSupplier>          getSupplier2FilterConnectionSrcs();
	//
	// attribute getters and setters
	virtual PICML::ECEventFilterConfigurationImpl::ECFilterType_Type getECFilterType();
	virtual void        setECFilterType( ECEventFilterConfigurationImpl::ECFilterType_Type val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EdgeImpl
//*******************************************************************
class EdgeImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getDstEdgeSrcs();
	virtual std::multiset<PICML::Property>  getEdgePropertySrcs();
	virtual std::set<PICML::DstEdge>        getInDstEdgeLinks();
	virtual std::set<PICML::EdgeProperty>   getInEdgePropertyLinks();
	virtual std::set<PICML::SrcEdge>        getOutSrcEdgeLinks();
	virtual std::multiset<BON::ConnectionEnd>         getSrcEdgeDsts();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EnumValueImpl
//*******************************************************************
class EnumValueImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ExternalReferenceEndPointImpl
//*******************************************************************
class ExternalReferenceEndPointImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Component> getExternalDelegateSrcs();
	virtual std::set<PICML::ExternalDelegate>         getInExternalDelegateLinks();
	//
	// attribute getters and setters
	virtual std::string getlocation() ;
	virtual void        setlocation( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationArtifactImpl
//*******************************************************************
class ImplementationArtifactImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		x86_architecture_Type,
		x86_64_architecture_Type,
		PowerPC_architecture_Type,
		SPARC_architecture_Type,
		MIPS_architecture_Type,
		HPPA_architecture_Type
	} architecture_Type;
	typedef enum
	{
		Release_configuration_Type,
		Debug_configuration_Type
	} configuration_Type;
	typedef enum
	{
		Linux_operatingSystem_Type,
		Win32_operatingSystem_Type,
		Darwin_operatingSystem_Type,
		Win64_operatingSystem_Type,
		SunOS_operatingSystem_Type,
		VxWorks_operatingSystem_Type,
		FreeBSD_operatingSystem_Type,
		NetBSD_operatingSystem_Type,
		OpenBSD_operatingSystem_Type,
		AIX_operatingSystem_Type,
		BSDi_operatingSystem_Type,
		VMS_operatingSystem_Type,
		Tru64_operatingSystem_Type,
		DigitalUnix_operatingSystem_Type,
		HPUX_operatingSystem_Type,
		IRIX_operatingSystem_Type
	} operatingSystem_Type;

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ImplementationArtifact> getArtifactDependencyDsts();
	virtual std::set<PICML::ArtifactDependency>       getArtifactDependencyLinks();
	virtual std::multiset<PICML::ImplementationArtifact> getArtifactDependencySrcs();
	virtual std::multiset<PICML::ImplementationArtifactReference> getArtifactDependsOnDsts();
	virtual std::multiset<PICML::Requirement>         getArtifactDeployRequirementDsts();
	virtual std::multiset<PICML::Property>  getArtifactExecParameterDsts();
	virtual std::multiset<PICML::Property>  getArtifactInfoPropertyDsts();
	virtual std::set<PICML::ArtifactDependency>       getInArtifactDependencyLinks();
	virtual std::set<PICML::ArtifactDependency>       getOutArtifactDependencyLinks();
	virtual std::set<PICML::ArtifactDependsOn>        getOutArtifactDependsOnLinks();
	virtual std::set<PICML::ArtifactDeployRequirement> getOutArtifactDeployRequirementLinks();
	virtual std::set<PICML::ArtifactExecParameter>    getOutArtifactExecParameterLinks();
	virtual std::set<PICML::ArtifactInfoProperty>     getOutArtifactInfoPropertyLinks();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual PICML::ImplementationArtifactImpl::architecture_Type getarchitecture();
	virtual std::string getartifactVersion() ;
	virtual PICML::ImplementationArtifactImpl::configuration_Type getconfiguration();
	virtual std::string getlabel() ;
	virtual std::string getlocation() ;
	virtual PICML::ImplementationArtifactImpl::operatingSystem_Type getoperatingSystem();
	virtual void        setUUID( const std::string& val);
	virtual void        setarchitecture( ImplementationArtifactImpl::architecture_Type val);
	virtual void        setartifactVersion( const std::string& val);
	virtual void        setconfiguration( ImplementationArtifactImpl::configuration_Type val);
	virtual void        setlabel( const std::string& val);
	virtual void        setlocation( const std::string& val);
	virtual void        setoperatingSystem( ImplementationArtifactImpl::operatingSystem_Type val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationDependencyImpl
//*******************************************************************
class ImplementationDependencyImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ComponentImplementation> getImplementationDependsOnSrcs();
	virtual std::set<PICML::ImplementationDependsOn>  getInImplementationDependsOnLinks();
	//
	// attribute getters and setters
	virtual std::string getrequiredType() ;
	virtual void        setrequiredType( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   LabelImpl
//*******************************************************************
class LabelImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::LabelConnection>          getInLabelConnectionLinks();
	virtual std::multiset<PICML::Member>    getLabelConnectionSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MultipleServiceRequestsImpl
//*******************************************************************
class MultipleServiceRequestsImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual long        getmaximum_simultaneous_service_level() ;
	virtual long        getminimum_simultaneous_service_level() ;
	virtual bool        isbuffer_service_requests() ;
	virtual bool        issimultaneous_service_execution() ;
	virtual void        setbuffer_service_requests( bool val);
	virtual void        setmaximum_simultaneous_service_level( const long val);
	virtual void        setminimum_simultaneous_service_level( const long val);
	virtual void        setsimultaneous_service_execution( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfigurationImpl
//*******************************************************************
class PackageConfigurationImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::PackageConfBasePackage>   getOutPackageConfBasePackageLinks();
	virtual std::set<PICML::PackageConfConfigProperty> getOutPackageConfConfigPropertyLinks();
	virtual std::set<PICML::PackageConfReference>     getOutPackageConfReferenceLinks();
	virtual std::set<PICML::PackageConfSelectRequirement> getOutPackageConfSelectRequirementLinks();
	virtual std::set<PICML::PackageConfSpecializedConfig> getOutPackageConfSpecializedConfigLinks();
	virtual std::multiset<PICML::ComponentPackage>    getPackageConfBasePackageDsts();
	virtual std::multiset<PICML::Property>  getPackageConfConfigPropertyDsts();
	virtual std::multiset<PICML::ComponentPackageReference> getPackageConfReferenceDsts();
	virtual std::multiset<PICML::Requirement>         getPackageConfSelectRequirementDsts();
	virtual std::multiset<PICML::PackageConfigurationReference> getPackageConfSpecializedConfigDsts();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PrivateFlagImpl
//*******************************************************************
class PrivateFlagImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::MakeMemberPrivate>        getInMakeMemberPrivateLinks();
	virtual std::multiset<PICML::Member>    getMakeMemberPrivateSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PublishConnectorImpl
//*******************************************************************
class PublishConnectorImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Requirement>         getAssemblyDeployRequirementDsts();
	virtual std::set<PICML::publish>        getInpublishLinks();
	virtual std::set<PICML::AssemblyDeployRequirement> getOutAssemblyDeployRequirementLinks();
	virtual std::set<PICML::deliverTo>      getOutdeliverToLinks();
	virtual std::multiset<BON::ConnectionEnd>         getdeliverToDsts();
	virtual std::multiset<BON::ConnectionEnd>         getpublishSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ServiceConsumerImpl
//*******************************************************************
class ServiceConsumerImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isprioritize_service_invocations() ;
	virtual void        setprioritize_service_invocations( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ServiceLevelsImpl
//*******************************************************************
class ServiceLevelsImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual bool        isvarying_service_levels() ;
	virtual void        setvarying_service_levels( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TaskImpl
//*******************************************************************
class TaskImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::WorkLoadOperationConnection> getInWorkLoadOperationConnectionLinks();
	virtual std::multiset<PICML::OperationRef>        getWorkLoadOperationConnectionSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TimeProbeImpl
//*******************************************************************
class TimeProbeImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::TimerConnection>          getInTimerConnectionLinks();
	virtual std::set<PICML::TimerEventSinkConn>       getInTimerEventSinkConnLinks();
	virtual std::multiset<PICML::OperationRef>        getTimerConnectionSrcs();
	virtual std::multiset<PICML::EventRef>  getTimerEventSinkConnSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TopLevelPackageImpl
//*******************************************************************
class TopLevelPackageImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::package>        getOutpackageLinks();
	virtual std::multiset<PICML::PackageConfigurationReference> getpackageDsts();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ArtifactDependencyImpl
//*******************************************************************
class ArtifactDependencyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ImplementationArtifact   getDst();
	virtual PICML::ImplementationArtifact   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ArtifactDependsOnImpl
//*******************************************************************
class ArtifactDependsOnImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ImplementationArtifactReference    getDst();
	virtual PICML::ImplementationArtifact   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ArtifactDeployRequirementImpl
//*******************************************************************
class ArtifactDeployRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Requirement              getDst();
	virtual PICML::ImplementationArtifact   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ArtifactExecParameterImpl
//*******************************************************************
class ArtifactExecParameterImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ImplementationArtifact   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ArtifactInfoPropertyImpl
//*******************************************************************
class ArtifactInfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ImplementationArtifact   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AssemblyConfigPropertyImpl
//*******************************************************************
class AssemblyConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::Component                getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AssemblyDeployRequirementImpl
//*******************************************************************
class AssemblyDeployRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Requirement              getDst();
	virtual PICML::PublishConnector         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AssemblyselectRequirementImpl
//*******************************************************************
class AssemblyselectRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Requirement              getDst();
	virtual PICML::Component                getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AttributeDelegateImpl
//*******************************************************************
class AttributeDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AttributeMappingDelegateImpl
//*******************************************************************
class AttributeMappingDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AttributeMappingValueImpl
//*******************************************************************
class AttributeMappingValueImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AttributeValueImpl
//*******************************************************************
class AttributeValueImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BenchmarkCharacteristicsImpl
//*******************************************************************
class BenchmarkCharacteristicsImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::MetricsBase              getDst();
	virtual PICML::BenchmarkType            getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   BindingPortTypeImpl
//*******************************************************************
class BindingPortTypeImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::PortType                  getDst();
	virtual WSML::Binding                   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   BindsOperationImpl
//*******************************************************************
class BindsOperationImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::OperationRef              getDst();
	virtual WSML::BindingOperation          getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   BodyBindingImpl
//*******************************************************************
class BodyBindingImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::SOAPBody                  getDst();
	virtual WSML::IORef getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   BodyPartsImpl
//*******************************************************************
class BodyPartsImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::PartRef                   getDst();
	virtual WSML::SOAPBody                  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   BranchTransitionImpl
//*******************************************************************
class BranchTransitionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getPrecondition() ;
	virtual void        setPrecondition( const std::string& val);
	//
	// connectionEnd getters
	virtual PICML::ActionBase               getDst();
	virtual PICML::BranchState              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   Bridge2InterconnectImpl
//*******************************************************************
class Bridge2InterconnectImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Interconnect             getDst();
	virtual PICML::Bridge                   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentConfigPropertyImpl
//*******************************************************************
class ComponentConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ComponentRef             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentInfoPropertyImpl
//*******************************************************************
class ComponentInfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ComponentRef             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentOperationImpl
//*******************************************************************
class ComponentOperationImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::CompRef                  getDst();
	virtual PICML::OperationRef             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentPropertyImpl
//*******************************************************************
class ComponentPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ComponentPropertyDescription       getDst();
	virtual PICML::ComponentRef             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ConfigPropertyImpl
//*******************************************************************
class ConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ComponentImplementation  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   Consumer2BehaviorConnectionImpl
//*******************************************************************
class Consumer2BehaviorConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ECBehavior               getDst();
	virtual PICML::ECConsumer               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   CriticalPathImpl
//*******************************************************************
class CriticalPathImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::PathReference            getDst();
	virtual PICML::ComponentAssembly        getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DstEdgeImpl
//*******************************************************************
class DstEdgeImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Edge getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EdgePropertyImpl
//*******************************************************************
class EdgePropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Edge getDst();
	virtual PICML::Property                 getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EffectImpl
//*******************************************************************
class EffectImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getPostcondition() ;
	virtual void        setPostcondition( const std::string& val);
	//
	// connectionEnd getters
	virtual PICML::StateBase                getDst();
	virtual PICML::ActionBase               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EventSinkDelegateImpl
//*******************************************************************
class EventSinkDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EventSourceDelegateImpl
//*******************************************************************
class EventSourceDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ExtResourceConnImpl
//*******************************************************************
class ExtResourceConnImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ExternalResources        getDst();
	virtual PICML::ComponentLib             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ExternalDelegateImpl
//*******************************************************************
class ExternalDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ExternalReferenceEndPoint          getDst();
	virtual PICML::Component                getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   FacetDelegateImpl
//*******************************************************************
class FacetDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   FaultMessageImpl
//*******************************************************************
class FaultMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::MessageRef                getDst();
	virtual WSML::Fault getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   FinishImpl
//*******************************************************************
class FinishImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getPostcondition() ;
	virtual void        setPostcondition( const std::string& val);
	//
	// connectionEnd getters
	virtual PICML::InputAction              getDst();
	virtual PICML::StateBase                getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   HeaderBindingImpl
//*******************************************************************
class HeaderBindingImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::SOAPHeaders               getDst();
	virtual WSML::IORef getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   HeaderMessageImpl
//*******************************************************************
class HeaderMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::MessageRef                getDst();
	virtual WSML::SOAPHeaders               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   HeaderPartImpl
//*******************************************************************
class HeaderPartImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::PartRef                   getDst();
	virtual WSML::SOAPHeaders               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationImpl
//*******************************************************************
class ImplementationImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ComponentImplementationReference   getDst();
	virtual PICML::ComponentPackage         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationCapabilityImpl
//*******************************************************************
class ImplementationCapabilityImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Capability               getDst();
	virtual PICML::ComponentImplementation  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationDependsOnImpl
//*******************************************************************
class ImplementationDependsOnImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ImplementationDependency getDst();
	virtual PICML::ComponentImplementation  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementsImpl
//*******************************************************************
class ImplementsImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ComponentRef             getDst();
	virtual PICML::ComponentImplementation  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InfoPropertyImpl
//*******************************************************************
class InfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ComponentImplementation  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InputImpl
//*******************************************************************
class InputImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::InputAction              getDst();
	virtual PICML::SingleInputBase          getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InputEffectImpl
//*******************************************************************
class InputEffectImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getPostcondition() ;
	virtual void        setPostcondition( const std::string& val);
	//
	// connectionEnd getters
	virtual PICML::StateBase                getDst();
	virtual PICML::InputAction              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   InputMessageImpl
//*******************************************************************
class InputMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::MessageRef                getDst();
	virtual WSML::Input getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InstanceMappingImpl
//*******************************************************************
class InstanceMappingImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::NodeReference            getDst();
	virtual PICML::CollocationGroup         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   Interconnect2BridgeImpl
//*******************************************************************
class Interconnect2BridgeImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Bridge                   getDst();
	virtual PICML::Interconnect             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   Interconnect2NodeImpl
//*******************************************************************
class Interconnect2NodeImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Node getDst();
	virtual PICML::Interconnect             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   LabelConnectionImpl
//*******************************************************************
class LabelConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Label                    getDst();
	virtual PICML::Member                   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MakeMemberPrivateImpl
//*******************************************************************
class MakeMemberPrivateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::PrivateFlag              getDst();
	virtual PICML::Member                   getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ManagesComponentImpl
//*******************************************************************
class ManagesComponentImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Manageable               getDst();
	virtual PICML::ComponentFactory         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MetricConnectionImpl
//*******************************************************************
class MetricConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::MetricsBase              getDst();
	virtual PICML::OperationRef             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MonolithDeployRequirementImpl
//*******************************************************************
class MonolithDeployRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ImplementationRequirement          getDst();
	virtual PICML::MonolithicImplementation getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MonolithExecParameterImpl
//*******************************************************************
class MonolithExecParameterImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::MonolithicImplementation getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MonolithprimaryArtifactImpl
//*******************************************************************
class MonolithprimaryArtifactImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ImplementationArtifactReference    getDst();
	virtual PICML::MonolithicImplementation getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MultiInputImpl
//*******************************************************************
class MultiInputImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::InputAction              getDst();
	virtual PICML::MultiInputBase           getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   Node2InterconnectImpl
//*******************************************************************
class Node2InterconnectImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Interconnect             getDst();
	virtual PICML::Node getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   OutputMessageImpl
//*******************************************************************
class OutputMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::MessageRef                getDst();
	virtual WSML::Output                    getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfBasePackageImpl
//*******************************************************************
class PackageConfBasePackageImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ComponentPackage         getDst();
	virtual PICML::PackageConfiguration     getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfConfigPropertyImpl
//*******************************************************************
class PackageConfConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::PackageConfiguration     getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfReferenceImpl
//*******************************************************************
class PackageConfReferenceImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ComponentPackageReference          getDst();
	virtual PICML::PackageConfiguration     getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfSelectRequirementImpl
//*******************************************************************
class PackageConfSelectRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Requirement              getDst();
	virtual PICML::PackageConfiguration     getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfSpecializedConfigImpl
//*******************************************************************
class PackageConfSpecializedConfigImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::PackageConfigurationReference      getDst();
	virtual PICML::PackageConfiguration     getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfigPropertyImpl
//*******************************************************************
class PackageConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ComponentPackage         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageInfoPropertyImpl
//*******************************************************************
class PackageInfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::ComponentPackage         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageInterfaceImpl
//*******************************************************************
class PackageInterfaceImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ComponentRef             getDst();
	virtual PICML::ComponentPackage         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PathPropertyImpl
//*******************************************************************
class PathPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Property                 getDst();
	virtual PICML::Path getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   PortBindingImpl
//*******************************************************************
class PortBindingImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::BindingRef                getDst();
	virtual WSML::Port  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace SIML
{
//*******************************************************************
//   C  L  A  S  S   PortProxyImpl
//*******************************************************************
class PortProxyImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);
	typedef enum
	{
		ASP_NET_mapping_Type,
		gSOAP_mapping_Type
	} mapping_Type;

	//
	// attribute getters and setters
	virtual SIML::PortProxyImpl::mapping_Type         getmapping();
	virtual void        setmapping( PortProxyImpl::mapping_Type val);
	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ReceptacleDelegateImpl
//*******************************************************************
class ReceptacleDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   RecursiveFilterConnectionImpl
//*******************************************************************
class RecursiveFilterConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ECEventFilterConfiguration         getDst();
	virtual PICML::ECEventFilterConfiguration         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   SOAPFaultExtensionImpl
//*******************************************************************
class SOAPFaultExtensionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual WSML::SOAPFault                 getDst();
	virtual WSML::FaultRef                  getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SharesImpl
//*******************************************************************
class SharesImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::SharedResource           getDst();
	virtual PICML::Node getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SrcEdgeImpl
//*******************************************************************
class SrcEdgeImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual PICML::Edge getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   Supplier2FilterConnectionImpl
//*******************************************************************
class Supplier2FilterConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::ECEventFilterConfiguration         getDst();
	virtual PICML::ECSupplier               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TimerConnectionImpl
//*******************************************************************
class TimerConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::TimeProbe                getDst();
	virtual PICML::OperationRef             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TimerEventSinkConnImpl
//*******************************************************************
class TimerEventSinkConnImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::TimeProbe                getDst();
	virtual PICML::EventRef                 getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TransitionImpl
//*******************************************************************
class TransitionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getPrecondition() ;
	virtual void        setPrecondition( const std::string& val);
	//
	// connectionEnd getters
	virtual PICML::ActionBase               getDst();
	virtual PICML::State                    getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkLoadOperationConnectionImpl
//*******************************************************************
class WorkLoadOperationConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::Task getDst();
	virtual PICML::OperationRef             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkloadCharacteristicsImpl
//*******************************************************************
class WorkloadCharacteristicsImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::TaskSet                  getDst();
	virtual PICML::MetricsBase              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   deliverToImpl
//*******************************************************************
class deliverToImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual PICML::PublishConnector         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   emitImpl
//*******************************************************************
class emitImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   invokeImpl
//*******************************************************************
class invokeImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   packageImpl
//*******************************************************************
class packageImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::PackageConfigurationReference      getDst();
	virtual PICML::TopLevelPackage          getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   publishImpl
//*******************************************************************
class publishImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual PICML::PublishConnector         getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   CollocationGroupImpl
//*******************************************************************
class CollocationGroupImpl :
	  virtual public BON::SetImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::NodeReference>       getInstanceMappingDsts();
	virtual std::set<PICML::InstanceMapping>          getOutInstanceMappingLinks();
	//
	// set getters
	virtual std::set<BON::Reference>        getAllMembers();
	virtual std::set<PICML::ComponentAssemblyReference> getComponentAssemblyReferences();
	virtual std::set<PICML::ComponentRef>   getComponentRefs();
	virtual std::set<PICML::SharedComponentReference> getSharedComponentReferences();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   TaskSetImpl
//*******************************************************************
class TaskSetImpl :
	  virtual public BON::SetImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::WorkloadCharacteristics>  getInWorkloadCharacteristicsLinks();
	virtual std::multiset<PICML::MetricsBase>         getWorkloadCharacteristicsSrcs();
	//
	// attribute getters and setters
	virtual long        getpriority() ;
	virtual long        getrate() ;
	virtual void        setpriority( const long val);
	virtual void        setrate( const long val);
	//
	// set getters
	virtual std::set<PICML::Task>           getTasks( int dummy);
	virtual std::set<PICML::Task>           getTasks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkspacesImpl
//*******************************************************************
class WorkspacesImpl :
	  virtual public BON::SetImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// set getters
	virtual std::set<PICML::Project>        getProjects( int dummy);
	virtual std::set<PICML::Project>        getProjects();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AttributeMappingImpl
//*******************************************************************
class AttributeMappingImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getAttributeDelegateDsts();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeMappingDelegateDsts();
	virtual std::set<PICML::AttributeMappingDelegate> getAttributeMappingDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeMappingDelegateSrcs();
	virtual std::multiset<PICML::Property>  getAttributeMappingValueDsts();
	virtual std::set<PICML::AttributeMappingDelegate> getInAttributeMappingDelegateLinks();
	virtual std::set<PICML::AttributeDelegate>        getOutAttributeDelegateLinks();
	virtual std::set<PICML::AttributeMappingDelegate> getOutAttributeMappingDelegateLinks();
	virtual std::set<PICML::AttributeMappingValue>    getOutAttributeMappingValueLinks();
	//
	// ref getters
	virtual PICML::ReadonlyAttribute        getReadonlyAttribute();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   AttributeMemberImpl
//*******************************************************************
class AttributeMemberImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   BindingRefImpl
//*******************************************************************
class BindingRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<WSML::PortBinding>     getInPortBindingLinks();
	virtual std::multiset<WSML::Port>       getPortBindingSrcs();
	//
	// ref getters
	virtual WSML::Binding                   getBinding();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   CompRefImpl
//*******************************************************************
class CompRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::OperationRef>        getComponentOperationSrcs();
	virtual std::set<PICML::ComponentOperation>       getInComponentOperationLinks();
	//
	// ref getters
	virtual PICML::Component                getComponent();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentAssemblyReferenceImpl
//*******************************************************************
class ComponentAssemblyReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::ComponentAssembly        getComponentAssembly();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentImplementationReferenceImpl
//*******************************************************************
class ComponentImplementationReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ComponentPackage>    getImplementationSrcs();
	virtual std::set<PICML::Implementation> getInImplementationLinks();
	//
	// ref getters
	virtual PICML::ComponentImplementation  getComponentImplementation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ComponentPackageReferenceImpl
//*******************************************************************
class ComponentPackageReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::PackageConfReference>     getInPackageConfReferenceLinks();
	virtual std::multiset<PICML::PackageConfiguration> getPackageConfReferenceSrcs();
	//
	// attribute getters and setters
	virtual std::string getrequiredName() ;
	virtual std::string getrequiredType() ;
	virtual std::string getrequiredUUID() ;
	virtual void        setrequiredName( const std::string& val);
	virtual void        setrequiredType( const std::string& val);
	virtual void        setrequiredUUID( const std::string& val);
	//
	// ref getters
	virtual PICML::ComponentPackage         getComponentPackage();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DataTypeImpl
//*******************************************************************
class DataTypeImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::PredefinedType           getPredefinedType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   DiscriminatorImpl
//*******************************************************************
class DiscriminatorImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::ConstantType             getConstantType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   EventRefImpl
//*******************************************************************
class EventRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::TimerEventSinkConn>       getOutTimerEventSinkConnLinks();
	virtual std::multiset<PICML::TimeProbe> getTimerEventSinkConnDsts();
	//
	// ref getters
	virtual PICML::Event                    getEvent();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ExceptionRefImpl
//*******************************************************************
class ExceptionRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::Exception                getException();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ExternalResourcesImpl
//*******************************************************************
class ExternalResourcesImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ComponentLib>        getExtResourceConnSrcs();
	virtual std::set<PICML::ExtResourceConn>          getInExtResourceConnLinks();
	//
	// ref getters
	virtual PICML::ImplementationArtifact   getImplementationArtifact();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   FaultRefImpl
//*******************************************************************
class FaultRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<WSML::SOAPFaultExtension>        getOutSOAPFaultExtensionLinks();
	virtual std::multiset<WSML::SOAPFault>  getSOAPFaultExtensionDsts();
	//
	// ref getters
	virtual WSML::Fault getFault();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   FileRefImpl
//*******************************************************************
class FileRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::File getFile();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   GetExceptionImpl
//*******************************************************************
class GetExceptionImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::Exception                getException();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ImplementationArtifactReferenceImpl
//*******************************************************************
class ImplementationArtifactReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ImplementationArtifact> getArtifactDependsOnSrcs();
	virtual std::set<PICML::ArtifactDependsOn>        getInArtifactDependsOnLinks();
	virtual std::set<PICML::MonolithprimaryArtifact>  getInMonolithprimaryArtifactLinks();
	virtual std::multiset<PICML::MonolithicImplementation> getMonolithprimaryArtifactSrcs();
	//
	// ref getters
	virtual PICML::ImplementationArtifact   getImplementationArtifact();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ParameterTypeImpl
//*******************************************************************
class ParameterTypeImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InParameterImpl
//*******************************************************************
class InParameterImpl :
	  public ParameterTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InoutParameterImpl
//*******************************************************************
class InoutParameterImpl :
	  public ParameterTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   OutParameterImpl
//*******************************************************************
class OutParameterImpl :
	  public ParameterTypeImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   InheritsImpl
//*******************************************************************
class InheritsImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::Inheritable              getInheritable();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   LookupKeyImpl
//*******************************************************************
class LookupKeyImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::ValueObject              getValueObject();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   MemberImpl
//*******************************************************************
class MemberImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::Label>     getLabelConnectionDsts();
	virtual std::multiset<PICML::PrivateFlag>         getMakeMemberPrivateDsts();
	virtual std::set<PICML::LabelConnection>          getOutLabelConnectionLinks();
	virtual std::set<PICML::MakeMemberPrivate>        getOutMakeMemberPrivateLinks();
	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   MessageRefImpl
//*******************************************************************
class MessageRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::Fault>      getFaultMessageSrcs();
	virtual std::multiset<WSML::SOAPHeaders>          getHeaderMessageSrcs();
	virtual std::set<WSML::FaultMessage>    getInFaultMessageLinks();
	virtual std::set<WSML::HeaderMessage>   getInHeaderMessageLinks();
	virtual std::set<WSML::InputMessage>    getInInputMessageLinks();
	virtual std::set<WSML::OutputMessage>   getInOutputMessageLinks();
	virtual std::multiset<WSML::Input>      getInputMessageSrcs();
	virtual std::multiset<WSML::Output>     getOutputMessageSrcs();
	//
	// ref getters
	virtual WSML::Message                   getMessage();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   NodeReferenceImpl
//*******************************************************************
class NodeReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::InstanceMapping>          getInInstanceMappingLinks();
	virtual std::multiset<PICML::CollocationGroup>    getInstanceMappingSrcs();
	//
	// ref getters
	virtual PICML::Node getNode();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   OperationRefImpl
//*******************************************************************
class OperationRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::BindingOperation>     getBindsOperationSrcs();
	virtual std::set<WSML::BindsOperation>  getInBindsOperationLinks();
	//
	// ref getters
	virtual WSML::Operation                 getOperation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   OperationRefImpl
//*******************************************************************
class OperationRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::CompRef>   getComponentOperationDsts();
	virtual std::multiset<PICML::MetricsBase>         getMetricConnectionDsts();
	virtual std::set<PICML::ComponentOperation>       getOutComponentOperationLinks();
	virtual std::set<PICML::MetricConnection>         getOutMetricConnectionLinks();
	virtual std::set<PICML::TimerConnection>          getOutTimerConnectionLinks();
	virtual std::set<PICML::WorkLoadOperationConnection> getOutWorkLoadOperationConnectionLinks();
	virtual std::multiset<PICML::TimeProbe> getTimerConnectionDsts();
	virtual std::multiset<PICML::Task>      getWorkLoadOperationConnectionDsts();
	//
	// ref getters
	virtual PICML::OperationBase            getOperationBase();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PackageConfigurationReferenceImpl
//*******************************************************************
class PackageConfigurationReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<PICML::PackageConfSpecializedConfig> getInPackageConfSpecializedConfigLinks();
	virtual std::set<PICML::package>        getInpackageLinks();
	virtual std::multiset<PICML::PackageConfiguration> getPackageConfSpecializedConfigSrcs();
	virtual std::multiset<PICML::TopLevelPackage>     getpackageSrcs();
	//
	// ref getters
	virtual PICML::PackageConfiguration     getPackageConfiguration();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   PartImpl
//*******************************************************************
class PartImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual WSML::Referrable                getReferrable();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   PartRefImpl
//*******************************************************************
class PartRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<WSML::SOAPBody>   getBodyPartsSrcs();
	virtual std::multiset<WSML::SOAPHeaders>          getHeaderPartSrcs();
	virtual std::set<WSML::BodyParts>       getInBodyPartsLinks();
	virtual std::set<WSML::HeaderPart>      getInHeaderPartLinks();
	//
	// ref getters
	virtual WSML::Part  getPart();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   PathReferenceImpl
//*******************************************************************
class PathReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<PICML::ComponentAssembly>   getCriticalPathSrcs();
	virtual std::set<PICML::CriticalPath>   getInCriticalPathLinks();
	//
	// ref getters
	virtual PICML::Path getPath();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   ReturnTypeImpl
//*******************************************************************
class ReturnTypeImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::MemberType               getMemberType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace WSML
{
//*******************************************************************
//   C  L  A  S  S   ServiceRefImpl
//*******************************************************************
class ServiceRefImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual WSML::Service                   getService();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SetExceptionImpl
//*******************************************************************
class SetExceptionImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::Exception                getException();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SharedComponentReferenceImpl
//*******************************************************************
class SharedComponentReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::ComponentRef             getComponentRef();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   SupportsImpl
//*******************************************************************
class SupportsImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::Object                   getObject();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   VariableImpl
//*******************************************************************
class VariableImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::PredefinedType           getPredefinedType();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace PICML
{
//*******************************************************************
//   C  L  A  S  S   WorkerTypeImpl
//*******************************************************************
class WorkerTypeImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual bool        accept( SIML::SIMLVisitor *pVisitor);

	//
	// ref getters
	virtual PICML::Worker                   getWorker();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


///BUP
// add your additional class definitions here
///EUP

#endif // SIMLBONX_H
