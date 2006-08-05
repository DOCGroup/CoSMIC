#ifndef SIMLBONX_H
#define SIMLBONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

///BUP
// add your include files/class definitions here
///EUP

namespace SIML_BON
{

DECLARE_BONEXTENSION( BON::Folder, ComponentAnalysesImpl, ComponentAnalyses );
DECLARE_BONEXTENSION( BON::Folder, ComponentBuildImpl, ComponentBuild );
DECLARE_BONEXTENSION( BON::Folder, ComponentImplementationsImpl, ComponentImplementations );
DECLARE_BONEXTENSION( BON::Folder, ComponentPackagesImpl, ComponentPackages );
DECLARE_BONEXTENSION( BON::Folder, ComponentTypesImpl, ComponentTypes );
DECLARE_BONEXTENSION( BON::Folder, DeploymentPlansImpl, DeploymentPlans );
DECLARE_BONEXTENSION( BON::Folder, EventChannelConfigImpl, EventChannelConfig );
DECLARE_BONEXTENSION( BON::Folder, FaultToleranceImpl, FaultTolerance );
DECLARE_BONEXTENSION( BON::Folder, ImplementationArtifactsImpl, ImplementationArtifacts );
DECLARE_BONEXTENSION( BON::Folder, InterfaceDefinitionsImpl, InterfaceDefinitions );
DECLARE_BONEXTENSION( BON::Folder, PackageConfigurationsImpl, PackageConfigurations );
DECLARE_BONEXTENSION( BON::Folder, PathDiagramsImpl, PathDiagrams );
DECLARE_BONEXTENSION( BON::Folder, PredefinedTypesImpl, PredefinedTypes );
DECLARE_BONEXTENSION( BON::Folder, QoSModelingImpl, QoSModeling );
DECLARE_BONEXTENSION( BON::Folder, TargetsImpl, Targets );
DECLARE_BONEXTENSION( BON::Folder, TopLevelPackagesImpl, TopLevelPackages );
DECLARE_BONEXTENSION( BON::Folder, WorkerLibrariesImpl, WorkerLibraries );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, PrefixableImpl, Prefixable );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, SupportsInterfacesImpl, SupportsInterfaces );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, CommonPortAttrsImpl, CommonPortAttrs );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ConstantTypeImpl, ConstantType );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, FTMonitorableImpl, FTMonitorable );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, GraphVertexImpl, GraphVertex );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ManageableImpl, Manageable );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, MemberTypeImpl, MemberType );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, MultiInputBaseImpl, MultiInputBase );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ProvideableImpl, Provideable );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, TaggableImpl, Taggable );
DECLARE_BONEXTENSION2( BON::Model, GraphVertex, ConnectedComponentImpl, ConnectedComponent );
DECLARE_BONEXTENSION2( BON::Model, Taggable, ExceptionImpl, Exception );
DECLARE_BONEXTENSION( Prefixable, FileImpl, File );
DECLARE_ABSTRACT_BONEXTENSION2( BON::Model, Taggable, OperationBaseImpl, OperationBase );
DECLARE_BONEXTENSION2( Taggable, Prefixable, PackageImpl, Package );
DECLARE_BONEXTENSION2( BON::Model, Taggable, ReadonlyAttributeImpl, ReadonlyAttribute );
DECLARE_ABSTRACT_BONEXTENSION2( Taggable, MemberType, NamedTypeImpl, NamedType );
DECLARE_ABSTRACT_BONEXTENSION3( CommonPortAttrs, Taggable, GraphVertex, PortImpl, Port );
DECLARE_ABSTRACT_BONEXTENSION2( ConstantType, MemberType, PredefinedTypeImpl, PredefinedType );
DECLARE_BONEXTENSION2( BON::Atom, GraphVertex, DisplayNodeImpl, DisplayNode );
DECLARE_BONEXTENSION2( BON::Atom, MultiInputBase, EnvironmentImpl, Environment );
DECLARE_BONEXTENSION2( BON::Reference, FTMonitorable, ComponentAssemblyReferenceImpl, ComponentAssemblyReference );
DECLARE_BONEXTENSION3( BON::Reference, FTMonitorable, Manageable, ComponentRefImpl, ComponentRef );
DECLARE_BONEXTENSION2( BON::Reference, Taggable, ConstantImpl, Constant );
DECLARE_BONEXTENSION( ReadonlyAttribute, AttributeImpl, Attribute );
DECLARE_BONEXTENSION3( SupportsInterfaces, Manageable, NamedType, ComponentImpl, Component );
DECLARE_ABSTRACT_BONEXTENSION( OperationBase, HasExceptionsImpl, HasExceptions );
DECLARE_ABSTRACT_BONEXTENSION2( BON::Model, NamedType, InheritableImpl, Inheritable );
DECLARE_BONEXTENSION( OperationBase, OnewayOperationImpl, OnewayOperation );
DECLARE_ABSTRACT_BONEXTENSION( NamedType, NoInheritableImpl, NoInheritable );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, BooleanImpl, Boolean );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, ByteImpl, Byte );
DECLARE_BONEXTENSION3( BON::Atom, Provideable, PredefinedType, GenericObjectImpl, GenericObject );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, GenericValueImpl, GenericValue );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, GenericValueObjectImpl, GenericValueObject );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, LongIntegerImpl, LongInteger );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, RealNumberImpl, RealNumber );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, ShortIntegerImpl, ShortInteger );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, StringImpl, String );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, TypeEncodingImpl, TypeEncoding );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, TypeKindImpl, TypeKind );
DECLARE_BONEXTENSION2( BON::Reference, NamedType, BoxedImpl, Boxed );
DECLARE_BONEXTENSION2( BON::Reference, Port, InEventPortImpl, InEventPort );
DECLARE_BONEXTENSION2( BON::Reference, Port, OutEventPortImpl, OutEventPort );
DECLARE_BONEXTENSION3( BON::Reference, MultiInputBase, Port, ProvidedRequestPortImpl, ProvidedRequestPort );
DECLARE_BONEXTENSION2( BON::Reference, Port, RequiredRequestPortImpl, RequiredRequestPort );
DECLARE_BONEXTENSION2( BON::Model, NoInheritable, AggregateImpl, Aggregate );
DECLARE_BONEXTENSION3( BON::Model, ConstantType, NoInheritable, EnumImpl, Enum );
DECLARE_BONEXTENSION( HasExceptions, FactoryOperationImpl, FactoryOperation );
DECLARE_ABSTRACT_BONEXTENSION( Inheritable, HasOperationsImpl, HasOperations );
DECLARE_BONEXTENSION( HasExceptions, LookupOperationImpl, LookupOperation );
DECLARE_BONEXTENSION2( BON::Model, NoInheritable, SwitchedAggregateImpl, SwitchedAggregate );
DECLARE_BONEXTENSION( HasExceptions, TwowayOperationImpl, TwowayOperation );
DECLARE_BONEXTENSION2( BON::Reference, NoInheritable, AliasImpl, Alias );
DECLARE_BONEXTENSION2( BON::Reference, NoInheritable, CollectionImpl, Collection );
DECLARE_BONEXTENSION2( HasOperations, SupportsInterfaces, ComponentFactoryImpl, ComponentFactory );
DECLARE_BONEXTENSION3( HasOperations, Provideable, Prefixable, ObjectImpl, Object );
DECLARE_ABSTRACT_BONEXTENSION3( HasOperations, SupportsInterfaces, Prefixable, ObjectByValueImpl, ObjectByValue );
DECLARE_BONEXTENSION( ObjectByValue, EventImpl, Event );
DECLARE_BONEXTENSION( ObjectByValue, ValueObjectImpl, ValueObject );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RequirementSatisfierImpl, RequirementSatisfier );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ElementsImpl, Elements );
DECLARE_BONEXTENSION2( BON::Model, Elements, BridgeImpl, Bridge );
DECLARE_BONEXTENSION( RequirementSatisfier, CapabilityImpl, Capability );
DECLARE_BONEXTENSION2( BON::Model, Elements, InterconnectImpl, Interconnect );
DECLARE_BONEXTENSION2( BON::Model, Elements, NodeImpl, Node );
DECLARE_BONEXTENSION( RequirementSatisfier, ResourceImpl, Resource );
DECLARE_BONEXTENSION2( Elements, RequirementSatisfier, SharedResourceImpl, SharedResource );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ProxyImpl, Proxy );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RTEC_ProxyImpl, RTEC_Proxy );
DECLARE_ABSTRACT_BONEXTENSION( Proxy, Proxy_ConsumerImpl, Proxy_Consumer );
DECLARE_ABSTRACT_BONEXTENSION( Proxy, Proxy_SupplierImpl, Proxy_Supplier );
DECLARE_BONEXTENSION2( Proxy_Consumer, RTEC_Proxy, RTEC_Proxy_ConsumerImpl, RTEC_Proxy_Consumer );
DECLARE_BONEXTENSION2( Proxy_Supplier, RTEC_Proxy, RTEC_Proxy_SupplierImpl, RTEC_Proxy_Supplier );
DECLARE_BONEXTENSION( BON::Model, QoSCharacteristicImpl, QoSCharacteristic );
DECLARE_BONEXTENSION( QoSCharacteristic, CPUImpl, CPU );
DECLARE_BONEXTENSION( QoSCharacteristic, ConcurrencyImpl, Concurrency );
DECLARE_BONEXTENSION( QoSCharacteristic, ConnectionImpl, Connection );
DECLARE_BONEXTENSION( QoSCharacteristic, ProcessImpl, Process );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RequirementBaseImpl, RequirementBase );
DECLARE_BONEXTENSION( RequirementBase, ImplementationRequirementImpl, ImplementationRequirement );
DECLARE_BONEXTENSION( RequirementBase, RequirementImpl, Requirement );
DECLARE_BONEXTENSION( Requirement, FOU_RequirementImpl, FOU_Requirement );
DECLARE_BONEXTENSION( Requirement, RepGRequirementImpl, RepGRequirement );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, OperationImpl, Operation );
DECLARE_BONEXTENSION( Operation, NotificationOperationImpl, NotificationOperation );
DECLARE_BONEXTENSION( Operation, OneWayOperationImpl, OneWayOperation );
DECLARE_BONEXTENSION( Operation, RequestResponseOperationImpl, RequestResponseOperation );
DECLARE_BONEXTENSION( Operation, SolicitResponseOperationImpl, SolicitResponseOperation );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ActionBaseImpl, ActionBase );
DECLARE_BONEXTENSION( ActionBase, ActionImpl, Action );
DECLARE_BONEXTENSION( Action, CompositeActionImpl, CompositeAction );
DECLARE_BONEXTENSION( Action, OutputActionImpl, OutputAction );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ComponentLibImpl, ComponentLib );
DECLARE_BONEXTENSION2( BON::Model, ComponentLib, ExecutorProjectImpl, ExecutorProject );
DECLARE_BONEXTENSION2( BON::Model, ComponentLib, ServantProjectImpl, ServantProject );
DECLARE_BONEXTENSION2( BON::Model, ComponentLib, StubProjectImpl, StubProject );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, resourceImpl, resource );
DECLARE_BONEXTENSION2( BON::Model, resource, BandedConnectionImpl, BandedConnection );
DECLARE_ABSTRACT_BONEXTENSION( resource, ThreadPoolImpl, ThreadPool );
DECLARE_BONEXTENSION2( BON::Model, ThreadPool, SimpleThreadPoolImpl, SimpleThreadPool );
DECLARE_BONEXTENSION2( BON::Model, ThreadPool, ThreadPoolWithLanesImpl, ThreadPoolWithLanes );
DECLARE_ABSTRACT_BONEXTENSION( ActionBase, InputActionBaseImpl, InputActionBase );
DECLARE_BONEXTENSION( InputActionBase, InputActionImpl, InputAction );
DECLARE_BONEXTENSION( InputActionBase, PeriodicActionImpl, PeriodicAction );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, MetricsBaseImpl, MetricsBase );
DECLARE_BONEXTENSION( MetricsBase, LatencyImpl, Latency );
DECLARE_BONEXTENSION( MetricsBase, ThroughputImpl, Throughput );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, SharedRiskCompositeImpl, SharedRiskComposite );
DECLARE_BONEXTENSION( SharedRiskComposite, NodeGroupImpl, NodeGroup );
DECLARE_BONEXTENSION( SharedRiskComposite, SharedRiskGroupImpl, SharedRiskGroup );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, FTCompositeImpl, FTComposite );
DECLARE_BONEXTENSION( FTComposite, FailOverUnitImpl, FailOverUnit );
DECLARE_BONEXTENSION( BON::Model, SchemaReferenceImpl, SchemaReference );
DECLARE_BONEXTENSION( SchemaReference, SchemaImportImpl, SchemaImport );
DECLARE_BONEXTENSION( BON::Model, WorkerPackageImpl, WorkerPackage );
DECLARE_BONEXTENSION( WorkerPackage, WorkerFileImpl, WorkerFile );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ComponentImplementationImpl, ComponentImplementation );
DECLARE_BONEXTENSION2( BON::Model, ComponentImplementation, ComponentAssemblyImpl, ComponentAssembly );
DECLARE_BONEXTENSION2( BON::Atom, ComponentImplementation, MonolithicImplementationImpl, MonolithicImplementation );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ExtensibilityElementImpl, ExtensibilityElement );
DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensibleBindingImpl, ExtensibleBinding );
DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensibleMessageImpl, ExtensibleMessage );
DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensibleOperationImpl, ExtensibleOperation );
DECLARE_ABSTRACT_BONEXTENSION( ExtensibilityElement, ExtensiblePortImpl, ExtensiblePort );
DECLARE_ABSTRACT_BONEXTENSION( ExtensibleMessage, SOAPHeadersImpl, SOAPHeaders );
DECLARE_BONEXTENSION2( BON::Atom, ExtensiblePort, SOAPAddressImpl, SOAPAddress );
DECLARE_BONEXTENSION2( BON::Atom, ExtensibleBinding, SOAPBindingImpl, SOAPBinding );
DECLARE_BONEXTENSION2( BON::Atom, ExtensibleMessage, SOAPBodyImpl, SOAPBody );
DECLARE_BONEXTENSION2( BON::Atom, ExtensibleMessage, SOAPFaultImpl, SOAPFault );
DECLARE_BONEXTENSION2( BON::Atom, ExtensibleOperation, SOAPOperationImpl, SOAPOperation );
DECLARE_BONEXTENSION2( BON::Model, SOAPHeaders, SOAPHeaderImpl, SOAPHeader );
DECLARE_BONEXTENSION2( BON::Atom, SOAPHeaders, SOAPHeaderFaultImpl, SOAPHeaderFault );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ReferrableImpl, Referrable );
DECLARE_BONEXTENSION2( BON::Model, Referrable, ElementImpl, Element );
DECLARE_BONEXTENSION2( BON::Atom, Referrable, AtomicTypeImpl, AtomicType );
DECLARE_BONEXTENSION( BON::Model, ArtifactContainerImpl, ArtifactContainer );
DECLARE_BONEXTENSION( BON::Model, BenchmarkAnalysisImpl, BenchmarkAnalysis );
DECLARE_BONEXTENSION( BON::Model, BindingImpl, Binding );
DECLARE_BONEXTENSION( BON::Model, BindingOperationImpl, BindingOperation );
DECLARE_BONEXTENSION( BON::Model, ComponentContainerImpl, ComponentContainer );
DECLARE_BONEXTENSION( BON::Model, ComponentImplementationContainerImpl, ComponentImplementationContainer );
DECLARE_BONEXTENSION( BON::Model, ComponentPropertyDescriptionImpl, ComponentPropertyDescription );
DECLARE_BONEXTENSION( BON::Model, DefinitionsImpl, Definitions );
DECLARE_BONEXTENSION( BON::Model, DeploymentPlanImpl, DeploymentPlan );
DECLARE_BONEXTENSION( BON::Model, DocumentationImpl, Documentation );
DECLARE_BONEXTENSION( BON::Model, DomainImpl, Domain );
DECLARE_BONEXTENSION( BON::Model, EventChannelConfigurationImpl, EventChannelConfiguration );
DECLARE_BONEXTENSION( BON::Model, FTRequirementsImpl, FTRequirements );
DECLARE_BONEXTENSION( BON::Model, FaultImpl, Fault );
DECLARE_BONEXTENSION( BON::Model, ImportImpl, Import );
DECLARE_BONEXTENSION( BON::Model, InputImpl, Input );
DECLARE_BONEXTENSION( BON::Model, MPCImpl, MPC );
DECLARE_BONEXTENSION( BON::Model, MessageImpl, Message );
DECLARE_BONEXTENSION( BON::Model, MessagesImpl, Messages );
DECLARE_BONEXTENSION( BON::Model, OutputImpl, Output );
DECLARE_BONEXTENSION( BON::Model, PackageConfigurationContainerImpl, PackageConfigurationContainer );
DECLARE_BONEXTENSION( BON::Model, PackageContainerImpl, PackageContainer );
DECLARE_BONEXTENSION( BON::Model, PathImpl, Path );
DECLARE_BONEXTENSION( BON::Model, PathsImpl, Paths );
DECLARE_BONEXTENSION( BON::Model, PolicySetImpl, PolicySet );
DECLARE_BONEXTENSION( BON::Model, PortImpl, Port );
DECLARE_BONEXTENSION( BON::Model, PortTypeImpl, PortType );
DECLARE_BONEXTENSION( BON::Model, ProjectImpl, Project );
DECLARE_BONEXTENSION( BON::Model, PropertyImpl, Property );
DECLARE_BONEXTENSION( BON::Model, QoSCategoryImpl, QoSCategory );
DECLARE_BONEXTENSION( BON::Model, QoSContextImpl, QoSContext );
DECLARE_BONEXTENSION( BON::Model, QoSValueImpl, QoSValue );
DECLARE_BONEXTENSION( BON::Model, RTConfigurationImpl, RTConfiguration );
DECLARE_BONEXTENSION( BON::Model, RTModelImpl, RTModel );
DECLARE_BONEXTENSION( BON::Model, ResourceContainerImpl, ResourceContainer );
DECLARE_BONEXTENSION( BON::Model, SRGContainerImpl, SRGContainer );
DECLARE_BONEXTENSION( BON::Model, SatisfierPropertyImpl, SatisfierProperty );
DECLARE_BONEXTENSION( BON::Model, SchemaImpl, Schema );
DECLARE_BONEXTENSION( BON::Model, SchemaBuiltinsImpl, SchemaBuiltins );
DECLARE_BONEXTENSION( BON::Model, ServiceImpl, Service );
DECLARE_BONEXTENSION( BON::Model, SystemImpl, System );
DECLARE_BONEXTENSION( BON::Model, TopLevelPackageContainerImpl, TopLevelPackageContainer );
DECLARE_BONEXTENSION( BON::Model, TypesImpl, Types );
DECLARE_BONEXTENSION( BON::Model, WorkerImpl, Worker );
DECLARE_BONEXTENSION( BON::Model, WorkerLibraryImpl, WorkerLibrary );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, BenchmarkTypeImpl, BenchmarkType );
DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, FixedIterationBenchmarksImpl, FixedIterationBenchmarks );
DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, PeriodicBenchmarksImpl, PeriodicBenchmarks );
DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, TriggerBenchmarksImpl, TriggerBenchmarks );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, DataAnalysisBaseImpl, DataAnalysisBase );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, AverageImpl, Average );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, JitterImpl, Jitter );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, MaximumImpl, Maximum );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, MinimumImpl, Minimum );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, IORefImpl, IORef );
DECLARE_BONEXTENSION2( BON::Reference, IORef, InputRefImpl, InputRef );
DECLARE_BONEXTENSION2( BON::Reference, IORef, OutputRefImpl, OutputRef );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, QoSConstraintImpl, QoSConstraint );
DECLARE_BONEXTENSION2( BON::Atom, QoSConstraint, QoSContractImpl, QoSContract );
DECLARE_BONEXTENSION2( BON::Atom, QoSConstraint, QoSOfferedImpl, QoSOffered );
DECLARE_BONEXTENSION2( BON::Atom, QoSConstraint, QoSRequiredImpl, QoSRequired );
DECLARE_BONEXTENSION( BON::Atom, AttributeImpl, Attribute );
DECLARE_BONEXTENSION( BON::Atom, ComponentPackageImpl, ComponentPackage );
DECLARE_ABSTRACT_BONEXTENSION( BON::Atom, RTEC_Filter_GroupImpl, RTEC_Filter_Group );
DECLARE_BONEXTENSION( RTEC_Filter_Group, ConjunctionGroupImpl, ConjunctionGroup );
DECLARE_BONEXTENSION( RTEC_Filter_Group, DisjunctionGroupImpl, DisjunctionGroup );
DECLARE_BONEXTENSION( RTEC_Filter_Group, LogicalANDGroupImpl, LogicalANDGroup );
DECLARE_BONEXTENSION( BON::Atom, ConnectionBandImpl, ConnectionBand );
DECLARE_BONEXTENSION( BON::Atom, EdgeImpl, Edge );
DECLARE_BONEXTENSION( BON::Atom, EnumValueImpl, EnumValue );
DECLARE_BONEXTENSION( BON::Atom, EnvironmentConfImpl, EnvironmentConf );
DECLARE_BONEXTENSION( BON::Atom, ExternalReferenceEndPointImpl, ExternalReferenceEndPoint );
DECLARE_BONEXTENSION( BON::Atom, ImplementationArtifactImpl, ImplementationArtifact );
DECLARE_BONEXTENSION( BON::Atom, ImplementationDependencyImpl, ImplementationDependency );
DECLARE_BONEXTENSION( BON::Atom, LabelImpl, Label );
DECLARE_ABSTRACT_BONEXTENSION( BON::Atom, RT_Info_ParamImpl, RT_Info_Param );
DECLARE_BONEXTENSION( RT_Info_Param, Null_RT_InfoImpl, Null_RT_Info );
DECLARE_BONEXTENSION( RT_Info_Param, RT_InfoImpl, RT_Info );
DECLARE_BONEXTENSION( BON::Atom, PackageConfigurationImpl, PackageConfiguration );
DECLARE_BONEXTENSION( BON::Atom, PriorityModelPolicyImpl, PriorityModelPolicy );
DECLARE_BONEXTENSION( BON::Atom, PrivateFlagImpl, PrivateFlag );
DECLARE_BONEXTENSION( BON::Atom, PublishConnectorImpl, PublishConnector );
DECLARE_BONEXTENSION( BON::Atom, QoSDimensionImpl, QoSDimension );
DECLARE_BONEXTENSION( BON::Atom, QoSDimensionSlotImpl, QoSDimensionSlot );
DECLARE_BONEXTENSION( BON::Atom, QoSParameterImpl, QoSParameter );
DECLARE_BONEXTENSION( BON::Atom, RTEC_Resource_FactoryImpl, RTEC_Resource_Factory );
DECLARE_BONEXTENSION( BON::Atom, StateImpl, State );
DECLARE_BONEXTENSION( BON::Atom, TaskImpl, Task );
DECLARE_BONEXTENSION( BON::Atom, ThreadPoolLaneImpl, ThreadPoolLane );
DECLARE_BONEXTENSION( BON::Atom, TimeProbeImpl, TimeProbe );
DECLARE_BONEXTENSION( BON::Atom, TopLevelPackageImpl, TopLevelPackage );
DECLARE_BONEXTENSION( BON::Connection, ArtifactDependencyImpl, ArtifactDependency );
DECLARE_BONEXTENSION( BON::Connection, ArtifactDependsOnImpl, ArtifactDependsOn );
DECLARE_BONEXTENSION( BON::Connection, ArtifactDeployRequirementImpl, ArtifactDeployRequirement );
DECLARE_BONEXTENSION( BON::Connection, ArtifactExecParameterImpl, ArtifactExecParameter );
DECLARE_BONEXTENSION( BON::Connection, ArtifactInfoPropertyImpl, ArtifactInfoProperty );
DECLARE_BONEXTENSION( BON::Connection, AssemblyConfigPropertyImpl, AssemblyConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, AssemblyDeployRequirementImpl, AssemblyDeployRequirement );
DECLARE_BONEXTENSION( BON::Connection, AssemblyselectRequirementImpl, AssemblyselectRequirement );
DECLARE_BONEXTENSION( BON::Connection, AttributeDelegateImpl, AttributeDelegate );
DECLARE_BONEXTENSION( BON::Connection, AttributeMappingDelegateImpl, AttributeMappingDelegate );
DECLARE_BONEXTENSION( BON::Connection, AttributeMappingValueImpl, AttributeMappingValue );
DECLARE_BONEXTENSION( BON::Connection, AttributeValueImpl, AttributeValue );
DECLARE_BONEXTENSION( BON::Connection, BenchmarkCharacteristicsImpl, BenchmarkCharacteristics );
DECLARE_BONEXTENSION( BON::Connection, BindingPortTypeImpl, BindingPortType );
DECLARE_BONEXTENSION( BON::Connection, BindsOperationImpl, BindsOperation );
DECLARE_BONEXTENSION( BON::Connection, BodyBindingImpl, BodyBinding );
DECLARE_BONEXTENSION( BON::Connection, BodyPartsImpl, BodyParts );
DECLARE_BONEXTENSION( BON::Connection, Bridge2InterconnectImpl, Bridge2Interconnect );
DECLARE_BONEXTENSION( BON::Connection, ComponentConfigPropertyImpl, ComponentConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, ComponentInfoPropertyImpl, ComponentInfoProperty );
DECLARE_BONEXTENSION( BON::Connection, ComponentOperationImpl, ComponentOperation );
DECLARE_BONEXTENSION( BON::Connection, ComponentPropertyImpl, ComponentProperty );
DECLARE_BONEXTENSION( BON::Connection, ConfigPropertyImpl, ConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, CriticalPathImpl, CriticalPath );
DECLARE_BONEXTENSION( BON::Connection, DstEdgeImpl, DstEdge );
DECLARE_BONEXTENSION( BON::Connection, EdgePropertyImpl, EdgeProperty );
DECLARE_BONEXTENSION( BON::Connection, EffectImpl, Effect );
DECLARE_BONEXTENSION( BON::Connection, EventSinkDelegateImpl, EventSinkDelegate );
DECLARE_BONEXTENSION( BON::Connection, EventSourceDelegateImpl, EventSourceDelegate );
DECLARE_BONEXTENSION( BON::Connection, ExtResourceConnImpl, ExtResourceConn );
DECLARE_BONEXTENSION( BON::Connection, ExternalDelegateImpl, ExternalDelegate );
DECLARE_BONEXTENSION( BON::Connection, FacetDelegateImpl, FacetDelegate );
DECLARE_BONEXTENSION( BON::Connection, FaultMessageImpl, FaultMessage );
DECLARE_BONEXTENSION( BON::Connection, FinishImpl, Finish );
DECLARE_BONEXTENSION( BON::Connection, HeaderBindingImpl, HeaderBinding );
DECLARE_BONEXTENSION( BON::Connection, HeaderMessageImpl, HeaderMessage );
DECLARE_BONEXTENSION( BON::Connection, HeaderPartImpl, HeaderPart );
DECLARE_BONEXTENSION( BON::Connection, ImplementationImpl, Implementation );
DECLARE_BONEXTENSION( BON::Connection, ImplementationCapabilityImpl, ImplementationCapability );
DECLARE_BONEXTENSION( BON::Connection, ImplementationDependsOnImpl, ImplementationDependsOn );
DECLARE_BONEXTENSION( BON::Connection, ImplementsImpl, Implements );
DECLARE_BONEXTENSION( BON::Connection, Include_RTEC_Filter_GroupImpl, Include_RTEC_Filter_Group );
DECLARE_BONEXTENSION( BON::Connection, Include_RT_InfoImpl, Include_RT_Info );
DECLARE_BONEXTENSION( BON::Connection, InfoPropertyImpl, InfoProperty );
DECLARE_BONEXTENSION( BON::Connection, InputImpl, Input );
DECLARE_BONEXTENSION( BON::Connection, InputMessageImpl, InputMessage );
DECLARE_BONEXTENSION( BON::Connection, InstanceMappingImpl, InstanceMapping );
DECLARE_BONEXTENSION( BON::Connection, Interconnect2BridgeImpl, Interconnect2Bridge );
DECLARE_BONEXTENSION( BON::Connection, Interconnect2NodeImpl, Interconnect2Node );
DECLARE_BONEXTENSION( BON::Connection, LabelConnectionImpl, LabelConnection );
DECLARE_BONEXTENSION( BON::Connection, MakeMemberPrivateImpl, MakeMemberPrivate );
DECLARE_BONEXTENSION( BON::Connection, ManagesComponentImpl, ManagesComponent );
DECLARE_BONEXTENSION( BON::Connection, MetricConnectionImpl, MetricConnection );
DECLARE_BONEXTENSION( BON::Connection, Monitorable2RepGImpl, Monitorable2RepG );
DECLARE_BONEXTENSION( BON::Connection, MonolithDeployRequirementImpl, MonolithDeployRequirement );
DECLARE_BONEXTENSION( BON::Connection, MonolithExecParameterImpl, MonolithExecParameter );
DECLARE_BONEXTENSION( BON::Connection, MonolithprimaryArtifactImpl, MonolithprimaryArtifact );
DECLARE_BONEXTENSION( BON::Connection, MultiInputImpl, MultiInput );
DECLARE_BONEXTENSION( BON::Connection, Node2InterconnectImpl, Node2Interconnect );
DECLARE_BONEXTENSION( BON::Connection, OutputMessageImpl, OutputMessage );
DECLARE_BONEXTENSION( BON::Connection, PackageConfBasePackageImpl, PackageConfBasePackage );
DECLARE_BONEXTENSION( BON::Connection, PackageConfConfigPropertyImpl, PackageConfConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, PackageConfReferenceImpl, PackageConfReference );
DECLARE_BONEXTENSION( BON::Connection, PackageConfSelectRequirementImpl, PackageConfSelectRequirement );
DECLARE_BONEXTENSION( BON::Connection, PackageConfSpecializedConfigImpl, PackageConfSpecializedConfig );
DECLARE_BONEXTENSION( BON::Connection, PackageConfigPropertyImpl, PackageConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, PackageInfoPropertyImpl, PackageInfoProperty );
DECLARE_BONEXTENSION( BON::Connection, PackageInterfaceImpl, PackageInterface );
DECLARE_BONEXTENSION( BON::Connection, PathPropertyImpl, PathProperty );
DECLARE_BONEXTENSION( BON::Connection, PortBindingImpl, PortBinding );
DECLARE_BONEXTENSION( BON::Connection, QoSDecorationImpl, QoSDecoration );
DECLARE_BONEXTENSION( BON::Connection, QoSDimensionQualifierImpl, QoSDimensionQualifier );
DECLARE_BONEXTENSION( BON::Connection, RTEC_ConnectionImpl, RTEC_Connection );
DECLARE_BONEXTENSION( BON::Connection, ReceptacleDelegateImpl, ReceptacleDelegate );
DECLARE_BONEXTENSION( BON::Connection, ReqConnectionImpl, ReqConnection );
DECLARE_BONEXTENSION( BON::Connection, SOAPFaultExtensionImpl, SOAPFaultExtension );
DECLARE_BONEXTENSION( BON::Connection, SharesImpl, Shares );
DECLARE_BONEXTENSION( BON::Connection, SrcEdgeImpl, SrcEdge );
DECLARE_BONEXTENSION( BON::Connection, TimerConnectionImpl, TimerConnection );
DECLARE_BONEXTENSION( BON::Connection, TimerEventSinkConnImpl, TimerEventSinkConn );
DECLARE_BONEXTENSION( BON::Connection, TransitionImpl, Transition );
DECLARE_BONEXTENSION( BON::Connection, Use_RTEC_FilterImpl, Use_RTEC_Filter );
DECLARE_BONEXTENSION( BON::Connection, Use_RT_InfoImpl, Use_RT_Info );
DECLARE_BONEXTENSION( BON::Connection, WorkLoadOperationConnectionImpl, WorkLoadOperationConnection );
DECLARE_BONEXTENSION( BON::Connection, WorkloadCharacteristicsImpl, WorkloadCharacteristics );
DECLARE_BONEXTENSION( BON::Connection, deliverToImpl, deliverTo );
DECLARE_BONEXTENSION( BON::Connection, emitImpl, emit );
DECLARE_BONEXTENSION( BON::Connection, invokeImpl, invoke );
DECLARE_BONEXTENSION( BON::Connection, packageImpl, package );
DECLARE_BONEXTENSION( BON::Connection, publishImpl, publish );
DECLARE_BONEXTENSION( BON::Set, CollocationGroupImpl, CollocationGroup );
DECLARE_BONEXTENSION( BON::Set, TaskSetImpl, TaskSet );
DECLARE_BONEXTENSION( BON::Set, WorkspacesImpl, Workspaces );
DECLARE_BONEXTENSION( BON::Reference, AttributeMappingImpl, AttributeMapping );
DECLARE_BONEXTENSION( BON::Reference, AttributeMemberImpl, AttributeMember );
DECLARE_BONEXTENSION( BON::Reference, BandedConnectionRefImpl, BandedConnectionRef );
DECLARE_BONEXTENSION( BON::Reference, BindingRefImpl, BindingRef );
DECLARE_BONEXTENSION( BON::Reference, CCMAssemblyImpl, CCMAssembly );
DECLARE_BONEXTENSION( BON::Reference, CompRefImpl, CompRef );
DECLARE_BONEXTENSION( BON::Reference, ComponentImplementationReferenceImpl, ComponentImplementationReference );
DECLARE_BONEXTENSION( BON::Reference, ComponentPackageReferenceImpl, ComponentPackageReference );
DECLARE_BONEXTENSION( BON::Reference, DataTypeImpl, DataType );
DECLARE_BONEXTENSION( BON::Reference, DeploymentPlanRefImpl, DeploymentPlanRef );
DECLARE_BONEXTENSION( BON::Reference, DiscriminatorImpl, Discriminator );
DECLARE_BONEXTENSION( BON::Reference, EventRefImpl, EventRef );
DECLARE_BONEXTENSION( BON::Reference, ExceptionRefImpl, ExceptionRef );
DECLARE_BONEXTENSION( BON::Reference, ExternalResourcesImpl, ExternalResources );
DECLARE_BONEXTENSION( BON::Reference, FaultRefImpl, FaultRef );
DECLARE_BONEXTENSION( BON::Reference, FileRefImpl, FileRef );
DECLARE_BONEXTENSION( BON::Reference, GetExceptionImpl, GetException );
DECLARE_BONEXTENSION( BON::Reference, ImplementationArtifactReferenceImpl, ImplementationArtifactReference );
DECLARE_BONEXTENSION( BON::Reference, InParameterImpl, InParameter );
DECLARE_BONEXTENSION( BON::Reference, InheritsImpl, Inherits );
DECLARE_BONEXTENSION( BON::Reference, InoutParameterImpl, InoutParameter );
DECLARE_BONEXTENSION( BON::Reference, LookupKeyImpl, LookupKey );
DECLARE_BONEXTENSION( BON::Reference, MemberImpl, Member );
DECLARE_BONEXTENSION( BON::Reference, MessageRefImpl, MessageRef );
DECLARE_BONEXTENSION( BON::Reference, NodeRefImpl, NodeRef );
DECLARE_BONEXTENSION( BON::Reference, NodeReferenceImpl, NodeReference );
DECLARE_BONEXTENSION( BON::Reference, OperationRefImpl, OperationRef );
DECLARE_BONEXTENSION( BON::Reference, OperationRefImpl, OperationRef );
DECLARE_BONEXTENSION( BON::Reference, OutParameterImpl, OutParameter );
DECLARE_BONEXTENSION( BON::Reference, PackageConfigurationReferenceImpl, PackageConfigurationReference );
DECLARE_BONEXTENSION( BON::Reference, PartImpl, Part );
DECLARE_BONEXTENSION( BON::Reference, PartRefImpl, PartRef );
DECLARE_BONEXTENSION( BON::Reference, PathReferenceImpl, PathReference );
DECLARE_BONEXTENSION( BON::Reference, PolicySetRefImpl, PolicySetRef );
DECLARE_BONEXTENSION( BON::Reference, QoSCharacteristicRefImpl, QoSCharacteristicRef );
DECLARE_BONEXTENSION( BON::Reference, RTEC_Resource_Factory_ReferenceImpl, RTEC_Resource_Factory_Reference );
DECLARE_BONEXTENSION( BON::Reference, ReturnTypeImpl, ReturnType );
DECLARE_BONEXTENSION( BON::Reference, SRGContainerRefImpl, SRGContainerRef );
DECLARE_BONEXTENSION( BON::Reference, SetExceptionImpl, SetException );
DECLARE_BONEXTENSION( BON::Reference, SharedComponentReferenceImpl, SharedComponentReference );
DECLARE_BONEXTENSION( BON::Reference, SharedResourceRefImpl, SharedResourceRef );
DECLARE_BONEXTENSION( BON::Reference, SupportsImpl, Supports );
DECLARE_BONEXTENSION( BON::Reference, ThreadPoolRefImpl, ThreadPoolRef );
DECLARE_BONEXTENSION( BON::Reference, VariableImpl, Variable );
DECLARE_BONEXTENSION( BON::Reference, WebServiceImpl, WebService );
DECLARE_BONEXTENSION( BON::Reference, WorkerTypeImpl, WorkerType );


//*******************************************************************
//   C  L  A  S  S   ComponentAnalysesImpl
//*******************************************************************
class ComponentAnalysesImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<BenchmarkAnalysis>     getBenchmarkAnalysis();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentBuildImpl
//*******************************************************************
class ComponentBuildImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<MPC>                   getMPC();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentImplementationsImpl
//*******************************************************************
class ComponentImplementationsImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<ComponentImplementationContainer> getComponentImplementationContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentPackagesImpl
//*******************************************************************
class ComponentPackagesImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<PackageContainer>      getPackageContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentTypesImpl
//*******************************************************************
class ComponentTypesImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<ComponentContainer>    getComponentContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DeploymentPlansImpl
//*******************************************************************
class DeploymentPlansImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<DeploymentPlan>        getDeploymentPlan();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EventChannelConfigImpl
//*******************************************************************
class EventChannelConfigImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<EventChannelConfiguration>       getEventChannelConfiguration();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FaultToleranceImpl
//*******************************************************************
class FaultToleranceImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<FTRequirements>        getFTRequirements();
	virtual std::set<SRGContainer>          getSRGContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationArtifactsImpl
//*******************************************************************
class ImplementationArtifactsImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<ArtifactContainer>     getArtifactContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InterfaceDefinitionsImpl
//*******************************************************************
class InterfaceDefinitionsImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<File>                  getFile();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfigurationsImpl
//*******************************************************************
class PackageConfigurationsImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<PackageConfigurationContainer>   getPackageConfigurationContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PathDiagramsImpl
//*******************************************************************
class PathDiagramsImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<Paths>                 getPaths();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PredefinedTypesImpl
//*******************************************************************
class PredefinedTypesImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<Boolean>               getBoolean();
	virtual std::set<Byte>                  getByte();
	virtual std::set<GenericObject>         getGenericObject();
	virtual std::set<GenericValue>          getGenericValue();
	virtual std::set<GenericValueObject>    getGenericValueObject();
	virtual std::set<LongInteger>           getLongInteger();
	virtual std::set<PredefinedType>        getPredefinedType();
	virtual std::set<RealNumber>            getRealNumber();
	virtual std::set<ShortInteger>          getShortInteger();
	virtual std::set<String>                getString();
	virtual std::set<TypeEncoding>          getTypeEncoding();
	virtual std::set<TypeKind>              getTypeKind();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSModelingImpl
//*******************************************************************
class QoSModelingImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<CPU>                   getCPU();
	virtual std::set<Concurrency>           getConcurrency();
	virtual std::set<Connection>            getConnection();
	virtual std::set<Process>               getProcess();
	virtual std::set<QoSCategory>           getQoSCategory();
	virtual std::set<QoSCharacteristic>     getQoSCharacteristic();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TargetsImpl
//*******************************************************************
class TargetsImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<Domain>                getDomain();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TopLevelPackagesImpl
//*******************************************************************
class TopLevelPackagesImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<TopLevelPackageContainer>        getTopLevelPackageContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerLibrariesImpl
//*******************************************************************
class WorkerLibrariesImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	virtual std::set<WorkerLibrary>         getWorkerLibrary();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PrefixableImpl
//*******************************************************************
class PrefixableImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getPrefixTag() ;
	virtual void        setPrefixTag( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SupportsInterfacesImpl
//*******************************************************************
class SupportsInterfacesImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Supports>              getSupports();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CommonPortAttrsImpl
//*******************************************************************
class CommonPortAttrsImpl :
	  virtual public BON::FCOImpl
{
public:

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
};


//*******************************************************************
//   C  L  A  S  S   ConstantTypeImpl
//*******************************************************************
class ConstantTypeImpl :
	  virtual public BON::FCOImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FTMonitorableImpl
//*******************************************************************
class FTMonitorableImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<RepGRequirement>  getMonitorable2RepGDsts();
	virtual std::set<Monitorable2RepG>      getOutMonitorable2RepGLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   GraphVertexImpl
//*******************************************************************
class GraphVertexImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Edge>             getDstEdgeDsts();
	virtual std::set<SrcEdge>               getInSrcEdgeLinks();
	virtual std::set<DstEdge>               getOutDstEdgeLinks();
	virtual std::multiset<Edge>             getSrcEdgeSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ManageableImpl
//*******************************************************************
class ManageableImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<ManagesComponent>      getInManagesComponentLinks();
	virtual std::multiset<ComponentFactory> getManagesComponentSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MemberTypeImpl
//*******************************************************************
class MemberTypeImpl :
	  virtual public BON::FCOImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MultiInputBaseImpl
//*******************************************************************
class MultiInputBaseImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<InputActionBase>  getMultiInputDsts();
	virtual std::set<MultiInput>            getOutMultiInputLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ProvideableImpl
//*******************************************************************
class ProvideableImpl :
	  virtual public BON::FCOImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TaggableImpl
//*******************************************************************
class TaggableImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getSpecifyIdTag() ;
	virtual std::string getVersionTag() ;
	virtual void        setSpecifyIdTag( const std::string& val);
	virtual void        setVersionTag( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConnectedComponentImpl
//*******************************************************************
class ConnectedComponentImpl :
	  virtual public BON::ModelImpl
	, public GraphVertexImpl
{
public:

	//
	// kind and role getters
	virtual std::set<DstEdge>               getDstEdge();
	virtual std::set<InEventPort>           getInEventPort();
	virtual std::set<OutEventPort>          getOutEventPort();
	virtual std::set<Port>                  getPort();
	virtual std::set<ProvidedRequestPort>   getProvidedRequestPort();
	virtual std::set<RequiredRequestPort>   getRequiredRequestPort();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExceptionImpl
//*******************************************************************
class ExceptionImpl :
	  virtual public BON::ModelImpl
	, public TaggableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Member>                getMember();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FileImpl
//*******************************************************************
class FileImpl :
	  public PrefixableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Aggregate>             getAggregate();
	virtual std::set<Alias>                 getAlias();
	virtual std::set<Boxed>                 getBoxed();
	virtual std::set<Collection>            getCollection();
	virtual std::set<Component>             getComponent();
	virtual std::set<ComponentFactory>      getComponentFactory();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<Constant>              getConstant();
	virtual std::set<Enum>                  getEnum();
	virtual std::set<Event>                 getEvent();
	virtual std::set<Exception>             getException();
	virtual std::set<FileRef>               getFileRef();
	virtual std::set<ManagesComponent>      getManagesComponent();
	virtual std::set<NamedType>             getNamedType();
	virtual std::set<Object>                getObject();
	virtual std::set<Package>               getPackage();
	virtual std::set<SwitchedAggregate>     getSwitchedAggregate();
	virtual std::set<ValueObject>           getValueObject();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OperationBaseImpl
//*******************************************************************
class OperationBaseImpl :
	  virtual public BON::ModelImpl
	, public TaggableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<InParameter>           getInParameter();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageImpl
//*******************************************************************
class PackageImpl :
	  public TaggableImpl
	, public PrefixableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Aggregate>             getAggregate();
	virtual std::set<Alias>                 getAlias();
	virtual std::set<Boxed>                 getBoxed();
	virtual std::set<Collection>            getCollection();
	virtual std::set<Component>             getComponent();
	virtual std::set<ComponentFactory>      getComponentFactory();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<Constant>              getConstant();
	virtual std::set<Enum>                  getEnum();
	virtual std::set<Event>                 getEvent();
	virtual std::set<Exception>             getException();
	virtual std::set<ManagesComponent>      getManagesComponent();
	virtual std::set<NamedType>             getNamedType();
	virtual std::set<Object>                getObject();
	virtual std::set<Package>               getPackage();
	virtual std::set<SwitchedAggregate>     getSwitchedAggregate();
	virtual std::set<ValueObject>           getValueObject();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ReadonlyAttributeImpl
//*******************************************************************
class ReadonlyAttributeImpl :
	  virtual public BON::ModelImpl
	, public TaggableImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getAttributeDelegateSrcs();
	virtual std::multiset<Property>         getAttributeValueDsts();
	virtual std::set<AttributeDelegate>     getInAttributeDelegateLinks();
	virtual std::set<AttributeValue>        getOutAttributeValueLinks();
	//
	// kind and role getters
	virtual std::set<AttributeMember>       getAttributeMember();
	virtual std::set<GetException>          getGetException();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NamedTypeImpl
//*******************************************************************
class NamedTypeImpl :
	  public TaggableImpl
	, public MemberTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PortImpl
//*******************************************************************
class PortImpl :
	  public CommonPortAttrsImpl
	, public TaggableImpl
	, public GraphVertexImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PredefinedTypeImpl
//*******************************************************************
class PredefinedTypeImpl :
	  public ConstantTypeImpl
	, public MemberTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DisplayNodeImpl
//*******************************************************************
class DisplayNodeImpl :
	  virtual public BON::AtomImpl
	, public GraphVertexImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EnvironmentImpl
//*******************************************************************
class EnvironmentImpl :
	  virtual public BON::AtomImpl
	, public MultiInputBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentAssemblyReferenceImpl
//*******************************************************************
class ComponentAssemblyReferenceImpl :
	  virtual public BON::ReferenceImpl
	, public FTMonitorableImpl
{
public:

	//
	// ref getters
	virtual ComponentAssembly               getComponentAssembly();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentRefImpl
//*******************************************************************
class ComponentRefImpl :
	  virtual public BON::ReferenceImpl
	, public FTMonitorableImpl
	, public ManageableImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Property>         getComponentConfigPropertyDsts();
	virtual std::multiset<Property>         getComponentInfoPropertyDsts();
	virtual std::multiset<ComponentPropertyDescription> getComponentPropertyDsts();
	virtual std::multiset<ComponentImplementation>    getImplementsSrcs();
	virtual std::set<Implements>            getInImplementsLinks();
	virtual std::set<PackageInterface>      getInPackageInterfaceLinks();
	virtual std::set<ComponentConfigProperty>         getOutComponentConfigPropertyLinks();
	virtual std::set<ComponentInfoProperty> getOutComponentInfoPropertyLinks();
	virtual std::set<ComponentProperty>     getOutComponentPropertyLinks();
	virtual std::multiset<ComponentPackage> getPackageInterfaceSrcs();
	//
	// ref getters
	virtual Component   getComponent();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConstantImpl
//*******************************************************************
class ConstantImpl :
	  virtual public BON::ReferenceImpl
	, public TaggableImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getvalue() ;
	virtual void        setvalue( const std::string& val);
	//
	// ref getters
	virtual ConstantType                    getConstantType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeImpl
//*******************************************************************
class AttributeImpl :
	  public ReadonlyAttributeImpl
{
public:

	//
	// kind and role getters
	virtual std::set<SetException>          getSetException();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentImpl
//*******************************************************************
class ComponentImpl :
	  public SupportsInterfacesImpl
	, public ManageableImpl
	, public NamedTypeImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Property>         getAssemblyConfigPropertyDsts();
	virtual std::multiset<Requirement>      getAssemblyselectRequirementDsts();
	virtual std::multiset<ExternalReferenceEndPoint>  getExternalDelegateDsts();
	virtual std::set<QoSDecoration>         getInQoSDecorationLinks();
	virtual std::set<AssemblyConfigProperty>          getOutAssemblyConfigPropertyLinks();
	virtual std::set<AssemblyselectRequirement>       getOutAssemblyselectRequirementLinks();
	virtual std::set<ExternalDelegate>      getOutExternalDelegateLinks();
	virtual std::multiset<QoSValue>         getQoSDecorationSrcs();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Action>                getAction();
	virtual std::set<ActionBase>            getActionBase();
	virtual std::set<Attribute>             getAttribute();
	virtual std::set<CompositeAction>       getCompositeAction();
	virtual std::set<Effect>                getEffect();
	virtual std::set<Environment>           getEnvironment();
	virtual std::set<Finish>                getFinish();
	virtual std::set<InEventPort>           getInEventPort();
	virtual std::set<Input>                 getInput();
	virtual std::set<InputAction>           getInputAction();
	virtual std::set<MultiInput>            getMultiInput();
	virtual std::set<OutEventPort>          getOutEventPort();
	virtual std::set<OutputAction>          getOutputAction();
	virtual std::set<PeriodicAction>        getPeriodicAction();
	virtual std::set<Port>                  getPort();
	virtual std::set<ProvidedRequestPort>   getProvidedRequestPort();
	virtual std::set<ReadonlyAttribute>     getReadonlyAttribute();
	virtual std::set<ReadonlyAttribute>     getReadonlyAttribute(int dummy);
	virtual std::set<RequiredRequestPort>   getRequiredRequestPort();
	virtual std::set<State>                 getState();
	virtual std::set<Transition>            getTransition();
	virtual std::set<Variable>              getVariable();
	virtual std::set<WorkerType>            getWorkerType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   HasExceptionsImpl
//*******************************************************************
class HasExceptionsImpl :
	  public OperationBaseImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ExceptionRef>          getExceptionRef();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InheritableImpl
//*******************************************************************
class InheritableImpl :
	  virtual public BON::ModelImpl
	, public NamedTypeImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Attribute>             getAttribute();
	virtual std::set<Inherits>              getInherits();
	virtual std::set<ReadonlyAttribute>     getReadonlyAttribute();
	virtual std::set<ReadonlyAttribute>     getReadonlyAttribute(int dummy);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OnewayOperationImpl
//*******************************************************************
class OnewayOperationImpl :
	  public OperationBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NoInheritableImpl
//*******************************************************************
class NoInheritableImpl :
	  public NamedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BooleanImpl
//*******************************************************************
class BooleanImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ByteImpl
//*******************************************************************
class ByteImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   GenericObjectImpl
//*******************************************************************
class GenericObjectImpl :
	  virtual public BON::AtomImpl
	, public ProvideableImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   GenericValueImpl
//*******************************************************************
class GenericValueImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   GenericValueObjectImpl
//*******************************************************************
class GenericValueObjectImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   LongIntegerImpl
//*******************************************************************
class LongIntegerImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RealNumberImpl
//*******************************************************************
class RealNumberImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ShortIntegerImpl
//*******************************************************************
class ShortIntegerImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   StringImpl
//*******************************************************************
class StringImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TypeEncodingImpl
//*******************************************************************
class TypeEncodingImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TypeKindImpl
//*******************************************************************
class TypeKindImpl :
	  virtual public BON::AtomImpl
	, public PredefinedTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BoxedImpl
//*******************************************************************
class BoxedImpl :
	  virtual public BON::ReferenceImpl
	, public NamedTypeImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InEventPortImpl
//*******************************************************************
class InEventPortImpl :
	  virtual public BON::ReferenceImpl
	, public PortImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getEventSinkDelegateDsts();
	virtual std::set<EventSinkDelegate>     getEventSinkDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getEventSinkDelegateSrcs();
	virtual std::set<EventSinkDelegate>     getInEventSinkDelegateLinks();
	virtual std::set<Use_RTEC_Filter>       getInUse_RTEC_FilterLinks();
	virtual std::set<deliverTo>             getIndeliverToLinks();
	virtual std::set<emit>                  getInemitLinks();
	virtual std::multiset<InputActionBase>  getInputDsts();
	virtual std::set<EventSinkDelegate>     getOutEventSinkDelegateLinks();
	virtual std::set<Input>                 getOutInputLinks();
	virtual std::multiset<RTEC_Filter_Group>          getUse_RTEC_FilterSrcs();
	virtual std::multiset<PublishConnector> getdeliverToSrcs();
	virtual std::multiset<BON::ConnectionEnd>         getemitSrcs();
	//
	// ref getters
	virtual Event       getEvent();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OutEventPortImpl
//*******************************************************************
class OutEventPortImpl :
	  virtual public BON::ReferenceImpl
	, public PortImpl
{
public:
	typedef enum
	{
		DirectConnect_out_event_port_type_Type,
		RTEventChannel_out_event_port_type_Type
	} out_event_port_type_Type;

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getEventSourceDelegateDsts();
	virtual std::set<EventSourceDelegate>   getEventSourceDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getEventSourceDelegateSrcs();
	virtual std::set<EventSourceDelegate>   getInEventSourceDelegateLinks();
	virtual std::set<EventSourceDelegate>   getOutEventSourceDelegateLinks();
	virtual std::set<RTEC_Connection>       getOutRTEC_ConnectionLinks();
	virtual std::set<emit>                  getOutemitLinks();
	virtual std::set<publish>               getOutpublishLinks();
	virtual std::multiset<RT_Info_Param>    getRTEC_ConnectionDsts();
	virtual std::multiset<BON::ConnectionEnd>         getemitDsts();
	virtual std::multiset<PublishConnector> getpublishDsts();
	//
	// attribute getters and setters
	virtual OutEventPortImpl::out_event_port_type_Type getout_event_port_type();
	virtual bool        issingle_destination() ;
	virtual void        setout_event_port_type( OutEventPortImpl::out_event_port_type_Type val);
	virtual void        setsingle_destination( bool val);
	//
	// ref getters
	virtual Event       getEvent();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ProvidedRequestPortImpl
//*******************************************************************
class ProvidedRequestPortImpl :
	  virtual public BON::ReferenceImpl
	, public MultiInputBaseImpl
	, public PortImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getFacetDelegateDsts();
	virtual std::set<FacetDelegate>         getFacetDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getFacetDelegateSrcs();
	virtual std::set<FacetDelegate>         getInFacetDelegateLinks();
	virtual std::set<invoke>                getIninvokeLinks();
	virtual std::set<FacetDelegate>         getOutFacetDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getinvokeSrcs();
	//
	// ref getters
	virtual Provideable getProvideable();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RequiredRequestPortImpl
//*******************************************************************
class RequiredRequestPortImpl :
	  virtual public BON::ReferenceImpl
	, public PortImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<ReceptacleDelegate>    getInReceptacleDelegateLinks();
	virtual std::set<ReceptacleDelegate>    getOutReceptacleDelegateLinks();
	virtual std::set<invoke>                getOutinvokeLinks();
	virtual std::multiset<BON::ConnectionEnd>         getReceptacleDelegateDsts();
	virtual std::set<ReceptacleDelegate>    getReceptacleDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getReceptacleDelegateSrcs();
	virtual std::multiset<BON::ConnectionEnd>         getinvokeDsts();
	//
	// attribute getters and setters
	virtual bool        ismultiple_connections() ;
	virtual void        setmultiple_connections( bool val);
	//
	// ref getters
	virtual Provideable getProvideable();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AggregateImpl
//*******************************************************************
class AggregateImpl :
	  virtual public BON::ModelImpl
	, public NoInheritableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Member>                getMember();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EnumImpl
//*******************************************************************
class EnumImpl :
	  virtual public BON::ModelImpl
	, public ConstantTypeImpl
	, public NoInheritableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<EnumValue>             getEnumValue();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FactoryOperationImpl
//*******************************************************************
class FactoryOperationImpl :
	  public HasExceptionsImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   HasOperationsImpl
//*******************************************************************
class HasOperationsImpl :
	  public InheritableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Aggregate>             getAggregate();
	virtual std::set<Alias>                 getAlias();
	virtual std::set<Collection>            getCollection();
	virtual std::set<Constant>              getConstant();
	virtual std::set<Enum>                  getEnum();
	virtual std::set<Exception>             getException();
	virtual std::set<NoInheritable>         getNoInheritable();
	virtual std::set<OnewayOperation>       getOnewayOperation();
	virtual std::set<SwitchedAggregate>     getSwitchedAggregate();
	virtual std::set<TwowayOperation>       getTwowayOperation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   LookupOperationImpl
//*******************************************************************
class LookupOperationImpl :
	  public HasExceptionsImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SwitchedAggregateImpl
//*******************************************************************
class SwitchedAggregateImpl :
	  virtual public BON::ModelImpl
	, public NoInheritableImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Discriminator>         getDiscriminator();
	virtual std::set<Label>                 getLabel();
	virtual std::set<LabelConnection>       getLabelConnection();
	virtual std::set<Member>                getMember();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TwowayOperationImpl
//*******************************************************************
class TwowayOperationImpl :
	  public HasExceptionsImpl
{
public:

	//
	// kind and role getters
	virtual std::set<InoutParameter>        getInoutParameter();
	virtual std::set<OutParameter>          getOutParameter();
	virtual std::set<ReturnType>            getReturnType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AliasImpl
//*******************************************************************
class AliasImpl :
	  virtual public BON::ReferenceImpl
	, public NoInheritableImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CollectionImpl
//*******************************************************************
class CollectionImpl :
	  virtual public BON::ReferenceImpl
	, public NoInheritableImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentFactoryImpl
//*******************************************************************
class ComponentFactoryImpl :
	  public HasOperationsImpl
	, public SupportsInterfacesImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Manageable>       getManagesComponentDsts();
	virtual std::set<ManagesComponent>      getOutManagesComponentLinks();
	//
	// kind and role getters
	virtual std::set<FactoryOperation>      getFactoryOperation();
	virtual std::set<LookupKey>             getLookupKey();
	virtual std::set<LookupOperation>       getLookupOperation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ObjectImpl
//*******************************************************************
class ObjectImpl :
	  public HasOperationsImpl
	, public ProvideableImpl
	, public PrefixableImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isabstract() ;
	virtual bool        islocal() ;
	virtual void        setabstract( bool val);
	virtual void        setlocal( bool val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ObjectByValueImpl
//*******************************************************************
class ObjectByValueImpl :
	  public HasOperationsImpl
	, public SupportsInterfacesImpl
	, public PrefixableImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isabstract() ;
	virtual void        setabstract( bool val);
	//
	// kind and role getters
	virtual std::set<FactoryOperation>      getFactoryOperation();
	virtual std::set<MakeMemberPrivate>     getMakeMemberPrivate();
	virtual std::set<Member>                getMember();
	virtual std::set<PrivateFlag>           getPrivateFlag();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EventImpl
//*******************************************************************
class EventImpl :
	  public ObjectByValueImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ValueObjectImpl
//*******************************************************************
class ValueObjectImpl :
	  public ObjectByValueImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RequirementSatisfierImpl
//*******************************************************************
class RequirementSatisfierImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getresourceType() ;
	virtual void        setresourceType( const std::string& val);
	//
	// kind and role getters
	virtual std::set<SatisfierProperty>     getSatisfierProperty();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ElementsImpl
//*******************************************************************
class ElementsImpl :
	  virtual public BON::FCOImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BridgeImpl
//*******************************************************************
class BridgeImpl :
	  virtual public BON::ModelImpl
	, public ElementsImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Interconnect>     getBridge2InterconnectDsts();
	virtual std::set<Interconnect2Bridge>   getInInterconnect2BridgeLinks();
	virtual std::multiset<Interconnect>     getInterconnect2BridgeSrcs();
	virtual std::set<Bridge2Interconnect>   getOutBridge2InterconnectLinks();
	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Resource>              getResource();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CapabilityImpl
//*******************************************************************
class CapabilityImpl :
	  public RequirementSatisfierImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ComponentImplementation>    getImplementationCapabilitySrcs();
	virtual std::set<ImplementationCapability>        getInImplementationCapabilityLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InterconnectImpl
//*******************************************************************
class InterconnectImpl :
	  virtual public BON::ModelImpl
	, public ElementsImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Bridge>           getBridge2InterconnectSrcs();
	virtual std::set<Bridge2Interconnect>   getInBridge2InterconnectLinks();
	virtual std::set<Node2Interconnect>     getInNode2InterconnectLinks();
	virtual std::multiset<Bridge>           getInterconnect2BridgeDsts();
	virtual std::multiset<Node>             getInterconnect2NodeDsts();
	virtual std::multiset<Node>             getNode2InterconnectSrcs();
	virtual std::set<Interconnect2Bridge>   getOutInterconnect2BridgeLinks();
	virtual std::set<Interconnect2Node>     getOutInterconnect2NodeLinks();
	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Resource>              getResource();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NodeImpl
//*******************************************************************
class NodeImpl :
	  virtual public BON::ModelImpl
	, public ElementsImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<Interconnect2Node>     getInInterconnect2NodeLinks();
	virtual std::multiset<Interconnect>     getInterconnect2NodeSrcs();
	virtual std::multiset<Interconnect>     getNode2InterconnectDsts();
	virtual std::set<Node2Interconnect>     getOutNode2InterconnectLinks();
	virtual std::set<Shares>                getOutSharesLinks();
	virtual std::multiset<SharedResource>   getSharesDsts();
	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Resource>              getResource();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ResourceImpl
//*******************************************************************
class ResourceImpl :
	  public RequirementSatisfierImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SharedResourceImpl
//*******************************************************************
class SharedResourceImpl :
	  public ElementsImpl
	, public RequirementSatisfierImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<Shares>                getInSharesLinks();
	virtual std::multiset<Node>             getSharesSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ProxyImpl
//*******************************************************************
class ProxyImpl :
	  virtual public BON::ModelImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_ProxyImpl
//*******************************************************************
class RTEC_ProxyImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Null_RT_Info>          getNull_RT_Info();
	virtual std::set<RT_Info>               getRT_Info();
	virtual std::set<RT_Info_Param>         getRT_Info_Param();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Proxy_ConsumerImpl
//*******************************************************************
class Proxy_ConsumerImpl :
	  public ProxyImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Proxy_SupplierImpl
//*******************************************************************
class Proxy_SupplierImpl :
	  public ProxyImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_Proxy_ConsumerImpl
//*******************************************************************
class RTEC_Proxy_ConsumerImpl :
	  public Proxy_ConsumerImpl
	, public RTEC_ProxyImpl
{
public:

	//
	// kind and role getters
	virtual std::set<RTEC_Resource_Factory_Reference> getRTEC_Resource_Factory_Reference();
	virtual std::set<Use_RT_Info>           getUse_RT_Info();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_Proxy_SupplierImpl
//*******************************************************************
class RTEC_Proxy_SupplierImpl :
	  public Proxy_SupplierImpl
	, public RTEC_ProxyImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ConjunctionGroup>      getConjunctionGroup();
	virtual std::set<DisjunctionGroup>      getDisjunctionGroup();
	virtual std::set<Include_RTEC_Filter_Group>       getInclude_RTEC_Filter_Group();
	virtual std::set<Include_RT_Info>       getInclude_RT_Info();
	virtual std::set<LogicalANDGroup>       getLogicalANDGroup();
	virtual std::set<RTEC_Filter_Group>     getRTEC_Filter_Group();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSCharacteristicImpl
//*******************************************************************
class QoSCharacteristicImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isisInvariant() ;
	virtual void        setisInvariant( bool val);
	//
	// kind and role getters
	virtual std::set<QoSCharacteristicRef>  getQoSCharacteristicRef();
	virtual std::set<QoSDimension>          getQoSDimension();
	virtual std::set<QoSParameter>          getQoSParameter();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CPUImpl
//*******************************************************************
class CPUImpl :
	  public QoSCharacteristicImpl
{
public:
	typedef enum
	{
		i386_Arch_Type,
		PPC_Arch_Type,
		SPARC_Arch_Type
	} Arch_Type;

	//
	// attribute getters and setters
	virtual CPUImpl::Arch_Type              getArch();
	virtual long        getSMP() ;
	virtual void        setArch( CPUImpl::Arch_Type val);
	virtual void        setSMP( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConcurrencyImpl
//*******************************************************************
class ConcurrencyImpl :
	  public QoSCharacteristicImpl
{
public:

	//
	// attribute getters and setters
	virtual double      getMaxRequests() ;
	virtual void        setMaxRequests( const double val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConnectionImpl
//*******************************************************************
class ConnectionImpl :
	  public QoSCharacteristicImpl
{
public:
	typedef enum
	{
		IPv4_Transport_Type,
		IPv6_Transport_Type
	} Transport_Type;

	//
	// attribute getters and setters
	virtual ConnectionImpl::Transport_Type  getTransport();
	virtual void        setTransport( ConnectionImpl::Transport_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ProcessImpl
//*******************************************************************
class ProcessImpl :
	  public QoSCharacteristicImpl
{
public:
	typedef enum
	{
		FIFO_Scheduling_Type,
		RR_Scheduling_Type,
		OTHER_Scheduling_Type
	} Scheduling_Type;

	//
	// attribute getters and setters
	virtual std::string getProcessPriority() ;
	virtual ProcessImpl::Scheduling_Type    getScheduling();
	virtual void        setProcessPriority( const std::string& val);
	virtual void        setScheduling( ProcessImpl::Scheduling_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RequirementBaseImpl
//*******************************************************************
class RequirementBaseImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getresourceType() ;
	virtual void        setresourceType( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Property>              getProperty();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationRequirementImpl
//*******************************************************************
class ImplementationRequirementImpl :
	  public RequirementBaseImpl
{
public:
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
	virtual std::set<MonolithDeployRequirement>       getInMonolithDeployRequirementLinks();
	virtual std::multiset<MonolithicImplementation>   getMonolithDeployRequirementSrcs();
	//
	// attribute getters and setters
	virtual ImplementationRequirementImpl::ResourceUsageKind_Type getResourceUsageKind();
	virtual std::string getcomponentPort() ;
	virtual std::string getresourcePort() ;
	virtual void        setResourceUsageKind( ImplementationRequirementImpl::ResourceUsageKind_Type val);
	virtual void        setcomponentPort( const std::string& val);
	virtual void        setresourcePort( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RequirementImpl
//*******************************************************************
class RequirementImpl :
	  public RequirementBaseImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ImplementationArtifact>     getArtifactDeployRequirementSrcs();
	virtual std::multiset<PublishConnector> getAssemblyDeployRequirementSrcs();
	virtual std::multiset<Component>        getAssemblyselectRequirementSrcs();
	virtual std::set<ArtifactDeployRequirement>       getInArtifactDeployRequirementLinks();
	virtual std::set<AssemblyDeployRequirement>       getInAssemblyDeployRequirementLinks();
	virtual std::set<AssemblyselectRequirement>       getInAssemblyselectRequirementLinks();
	virtual std::set<PackageConfSelectRequirement>    getInPackageConfSelectRequirementLinks();
	virtual std::multiset<PackageConfiguration>       getPackageConfSelectRequirementSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FOU_RequirementImpl
//*******************************************************************
class FOU_RequirementImpl :
	  public RequirementImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<ReqConnection>         getInReqConnectionLinks();
	virtual std::multiset<FTComposite>      getReqConnectionSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RepGRequirementImpl
//*******************************************************************
class RepGRequirementImpl :
	  public RequirementImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<Monitorable2RepG>      getInMonitorable2RepGLinks();
	virtual std::multiset<FTMonitorable>    getMonitorable2RepGSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OperationImpl
//*******************************************************************
class OperationImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Documentation>         getDocumentation();
	virtual std::set<FaultMessage>          getFaultMessage();
	virtual std::set<InputMessage>          getInputMessage();
	virtual std::set<MessageRef>            getMessageRef();
	virtual std::set<OutputMessage>         getOutputMessage();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NotificationOperationImpl
//*******************************************************************
class NotificationOperationImpl :
	  public OperationImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Output>                getOutput();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OneWayOperationImpl
//*******************************************************************
class OneWayOperationImpl :
	  public OperationImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Input>                 getInput();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RequestResponseOperationImpl
//*******************************************************************
class RequestResponseOperationImpl :
	  public OperationImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getparameterOrder() ;
	virtual void        setparameterOrder( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Fault>                 getFault();
	virtual std::set<Input>                 getInput();
	virtual std::set<Output>                getOutput();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SolicitResponseOperationImpl
//*******************************************************************
class SolicitResponseOperationImpl :
	  public OperationImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getparameterOrder() ;
	virtual void        setparameterOrder( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Fault>                 getFault();
	virtual std::set<Input>                 getInput();
	virtual std::set<Output>                getOutput();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ActionBaseImpl
//*******************************************************************
class ActionBaseImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<State>            getEffectDsts();
	virtual std::set<Transition>            getInTransitionLinks();
	virtual std::set<Effect>                getOutEffectLinks();
	virtual std::multiset<State>            getTransitionSrcs();
	//
	// attribute getters and setters
	virtual long        getRepetitions() ;
	virtual bool        isLogAction() ;
	virtual void        setLogAction( bool val);
	virtual void        setRepetitions( const long val);
	//
	// kind and role getters
	virtual std::set<Property>              getProperty();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ActionImpl
//*******************************************************************
class ActionImpl :
	  public ActionBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CompositeActionImpl
//*******************************************************************
class CompositeActionImpl :
	  public ActionImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Action>                getAction();
	virtual std::set<Action>                getAction(int dummy);
	virtual std::set<CompositeAction>       getCompositeAction();
	virtual std::set<Effect>                getEffect();
	virtual std::set<Finish>                getFinish();
	virtual std::set<InputAction>           getInputAction();
	virtual std::set<OutputAction>          getOutputAction();
	virtual std::set<State>                 getState();
	virtual std::set<Transition>            getTransition();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OutputActionImpl
//*******************************************************************
class OutputActionImpl :
	  public ActionImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentLibImpl
//*******************************************************************
class ComponentLibImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ExternalResources>          getExtResourceConnDsts();
	virtual std::set<ExtResourceConn>       getOutExtResourceConnLinks();
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
};


//*******************************************************************
//   C  L  A  S  S   ExecutorProjectImpl
//*******************************************************************
class ExecutorProjectImpl :
	  virtual public BON::ModelImpl
	, public ComponentLibImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ImplementationArtifactReference> getImplementationArtifactReference();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ServantProjectImpl
//*******************************************************************
class ServantProjectImpl :
	  virtual public BON::ModelImpl
	, public ComponentLibImpl
{
public:

	//
	// kind and role getters
	virtual std::set<FileRef>               getFileRef();
	virtual std::set<ImplementationArtifactReference> getImplementationArtifactReference();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   StubProjectImpl
//*******************************************************************
class StubProjectImpl :
	  virtual public BON::ModelImpl
	, public ComponentLibImpl
{
public:

	//
	// kind and role getters
	virtual std::set<FileRef>               getFileRef();
	virtual std::set<ImplementationArtifactReference> getImplementationArtifactReference();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   resourceImpl
//*******************************************************************
class resourceImpl :
	  virtual public BON::FCOImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BandedConnectionImpl
//*******************************************************************
class BandedConnectionImpl :
	  virtual public BON::ModelImpl
	, public resourceImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ConnectionBand>        getConnectionBand();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ThreadPoolImpl
//*******************************************************************
class ThreadPoolImpl :
	  public resourceImpl
{
public:

	//
	// attribute getters and setters
	virtual long        getmax_buffer_size() ;
	virtual long        getmax_buffered_requests() ;
	virtual long        getstacksize() ;
	virtual bool        isallow_request_buffering() ;
	virtual void        setallow_request_buffering( bool val);
	virtual void        setmax_buffer_size( const long val);
	virtual void        setmax_buffered_requests( const long val);
	virtual void        setstacksize( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SimpleThreadPoolImpl
//*******************************************************************
class SimpleThreadPoolImpl :
	  virtual public BON::ModelImpl
	, public ThreadPoolImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ThreadPoolLane>        getThreadPoolLane();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ThreadPoolWithLanesImpl
//*******************************************************************
class ThreadPoolWithLanesImpl :
	  virtual public BON::ModelImpl
	, public ThreadPoolImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isallow_borrowing() ;
	virtual void        setallow_borrowing( bool val);
	//
	// kind and role getters
	virtual std::set<ThreadPoolLane>        getThreadPoolLane();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InputActionBaseImpl
//*******************************************************************
class InputActionBaseImpl :
	  public ActionBaseImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<State>            getFinishSrcs();
	virtual std::set<Finish>                getInFinishLinks();
	virtual std::set<Input>                 getInInputLinks();
	virtual std::set<MultiInput>            getInMultiInputLinks();
	virtual std::multiset<InEventPort>      getInputSrcs();
	virtual std::multiset<MultiInputBase>   getMultiInputSrcs();
	//
	// kind and role getters
	virtual std::set<Property>              getProperty();

private: // hidden members (interface inherited)
	//
	// hidden attribute getters and setters
	virtual long getRepetitions()  { throw std::string("Interface inherited kind. " + getName() + " doesn't have getRepetitions()  method."); }
	virtual bool isLogAction()  { throw std::string("Interface inherited kind. " + getName() + " doesn't have isLogAction()  method."); }
	virtual void setLogAction( bool val) { throw std::string("Interface inherited kind. " + getName() + " doesn't have setLogAction( bool val) method."); }
	virtual void setRepetitions( const long val) { throw std::string("Interface inherited kind. " + getName() + " doesn't have setRepetitions( const long val) method."); }
	//
	// hidden kind and role getters
	virtual std::set<Property> getProperty() { throw std::string("Interface inherited kind. " + getName() + " doesn't have getProperty() method."); }

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InputActionImpl
//*******************************************************************
class InputActionImpl :
	  public InputActionBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PeriodicActionImpl
//*******************************************************************
class PeriodicActionImpl :
	  public InputActionBaseImpl
{
public:

	//
	// attribute getters and setters
	virtual long        getPeriod() ;
	virtual double      getProbability() ;
	virtual void        setPeriod( const long val);
	virtual void        setProbability( const double val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MetricsBaseImpl
//*******************************************************************
class MetricsBaseImpl :
	  virtual public BON::ModelImpl
{
public:
	typedef enum
	{
		seconds_resolution_Type,
		miliseconds_resolution_Type,
		microseconds_resolution_Type
	} resolution_Type;

	//
	// connectionEnd getters
	virtual std::multiset<BenchmarkType>    getBenchmarkCharacteristicsSrcs();
	virtual std::set<BenchmarkCharacteristics>        getInBenchmarkCharacteristicsLinks();
	virtual std::set<MetricConnection>      getInMetricConnectionLinks();
	virtual std::multiset<OperationRef>     getMetricConnectionSrcs();
	virtual std::set<WorkloadCharacteristics>         getOutWorkloadCharacteristicsLinks();
	virtual std::multiset<TaskSet>          getWorkloadCharacteristicsDsts();
	//
	// attribute getters and setters
	virtual std::string getfileName() ;
	virtual long        getiterations() ;
	virtual long        getpriority() ;
	virtual long        getrate() ;
	virtual MetricsBaseImpl::resolution_Type          getresolution();
	virtual long        getwarmup() ;
	virtual void        setfileName( const std::string& val);
	virtual void        setiterations( const long val);
	virtual void        setpriority( const long val);
	virtual void        setrate( const long val);
	virtual void        setresolution( MetricsBaseImpl::resolution_Type val);
	virtual void        setwarmup( const long val);
	//
	// kind and role getters
	virtual std::set<Average>               getAverage();
	virtual std::set<DataAnalysisBase>      getDataAnalysisBase();
	virtual std::set<Jitter>                getJitter();
	virtual std::set<Maximum>               getMaximum();
	virtual std::set<Minimum>               getMinimum();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   LatencyImpl
//*******************************************************************
class LatencyImpl :
	  public MetricsBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ThroughputImpl
//*******************************************************************
class ThroughputImpl :
	  public MetricsBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SharedRiskCompositeImpl
//*******************************************************************
class SharedRiskCompositeImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual double      getMetric() ;
	virtual void        setMetric( const double val);
	//
	// kind and role getters
	virtual std::set<NodeRef>               getNodeRef();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NodeGroupImpl
//*******************************************************************
class NodeGroupImpl :
	  public SharedRiskCompositeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SharedRiskGroupImpl
//*******************************************************************
class SharedRiskGroupImpl :
	  public SharedRiskCompositeImpl
{
public:

	//
	// kind and role getters
	virtual std::set<NodeGroup>             getNodeGroup();
	virtual std::set<SharedResourceRef>     getSharedResourceRef();
	virtual std::set<SharedRiskComposite>   getSharedRiskComposite();
	virtual std::set<SharedRiskGroup>       getSharedRiskGroup();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FTCompositeImpl
//*******************************************************************
class FTCompositeImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<ReqConnection>         getOutReqConnectionLinks();
	virtual std::multiset<FOU_Requirement>  getReqConnectionDsts();
	//
	// kind and role getters
	virtual std::set<ComponentAssemblyReference>      getComponentAssemblyReference();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<FTMonitorable>         getFTMonitorable();
	virtual std::set<Monitorable2RepG>      getMonitorable2RepG();
	virtual std::set<RepGRequirement>       getRepGRequirement();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FailOverUnitImpl
//*******************************************************************
class FailOverUnitImpl :
	  public FTCompositeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SchemaReferenceImpl
//*******************************************************************
class SchemaReferenceImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getid() ;
	virtual std::string getschemaLocation() ;
	virtual void        setid( const std::string& val);
	virtual void        setschemaLocation( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Schema>                getSchema();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SchemaImportImpl
//*******************************************************************
class SchemaImportImpl :
	  public SchemaReferenceImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getnamespace() ;
	virtual void        setnamespace( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerPackageImpl
//*******************************************************************
class WorkerPackageImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Worker>                getWorker();
	virtual std::set<WorkerPackage>         getWorkerPackage();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerFileImpl
//*******************************************************************
class WorkerFileImpl :
	  virtual public BON::ModelImpl
	, private WorkerPackageImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getLocation() ;
	virtual void        setLocation( const std::string& val);

public: // exposed members (implementation inherited)
	//
	// exposed kind and role getters
	using WorkerPackageImpl::getWorker;
	using WorkerPackageImpl::getWorkerPackage;

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentImplementationImpl
//*******************************************************************
class ComponentImplementationImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Property>         getConfigPropertyDsts();
	virtual std::multiset<Capability>       getImplementationCapabilityDsts();
	virtual std::multiset<ImplementationDependency>   getImplementationDependsOnDsts();
	virtual std::multiset<ComponentRef>     getImplementsDsts();
	virtual std::multiset<Property>         getInfoPropertyDsts();
	virtual std::set<ConfigProperty>        getOutConfigPropertyLinks();
	virtual std::set<ImplementationCapability>        getOutImplementationCapabilityLinks();
	virtual std::set<ImplementationDependsOn>         getOutImplementationDependsOnLinks();
	virtual std::set<Implements>            getOutImplementsLinks();
	virtual std::set<InfoProperty>          getOutInfoPropertyLinks();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentAssemblyImpl
//*******************************************************************
class ComponentAssemblyImpl :
	  virtual public BON::ModelImpl
	, public ComponentImplementationImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<PathReference>    getCriticalPathDsts();
	virtual std::set<CriticalPath>          getOutCriticalPathLinks();
	//
	// kind and role getters
	virtual std::set<AssemblyConfigProperty>          getAssemblyConfigProperty();
	virtual std::set<AssemblyDeployRequirement>       getAssemblyDeployRequirement();
	virtual std::set<AssemblyselectRequirement>       getAssemblyselectRequirement();
	virtual std::set<AttributeDelegate>     getAttributeDelegate();
	virtual std::set<AttributeMapping>      getAttributeMapping();
	virtual std::set<AttributeMappingDelegate>        getAttributeMappingDelegate();
	virtual std::set<AttributeMappingValue> getAttributeMappingValue();
	virtual std::set<AttributeValue>        getAttributeValue();
	virtual std::set<Component>             getComponent();
	virtual std::set<ComponentAssembly>     getComponentAssembly();
	virtual std::set<ComponentAssemblyReference>      getComponentAssemblyReference();
	virtual std::set<ComponentPackage>      getComponentPackage();
	virtual std::set<ComponentPackageReference>       getComponentPackageReference();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<EventSinkDelegate>     getEventSinkDelegate();
	virtual std::set<EventSourceDelegate>   getEventSourceDelegate();
	virtual std::set<ExternalDelegate>      getExternalDelegate();
	virtual std::set<ExternalReferenceEndPoint>       getExternalReferenceEndPoint();
	virtual std::set<FOU_Requirement>       getFOU_Requirement();
	virtual std::set<FacetDelegate>         getFacetDelegate();
	virtual std::set<InEventPort>           getInEventPort();
	virtual std::set<OutEventPort>          getOutEventPort();
	virtual std::set<Property>              getProperty();
	virtual std::set<ProvidedRequestPort>   getProvidedRequestPort();
	virtual std::set<PublishConnector>      getPublishConnector();
	virtual std::set<QoSDecoration>         getQoSDecoration();
	virtual std::set<QoSValue>              getQoSValue();
	virtual std::set<ReceptacleDelegate>    getReceptacleDelegate();
	virtual std::set<RepGRequirement>       getRepGRequirement();
	virtual std::set<RequiredRequestPort>   getRequiredRequestPort();
	virtual std::set<Requirement>           getRequirement();
	virtual std::set<Requirement>           getRequirement(int dummy);
	virtual std::set<deliverTo>             getdeliverTo();
	virtual std::set<emit>                  getemit();
	virtual std::set<invoke>                getinvoke();
	virtual std::set<publish>               getpublish();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MonolithicImplementationImpl
//*******************************************************************
class MonolithicImplementationImpl :
	  virtual public BON::AtomImpl
	, public ComponentImplementationImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ImplementationRequirement>  getMonolithDeployRequirementDsts();
	virtual std::multiset<Property>         getMonolithExecParameterDsts();
	virtual std::multiset<ImplementationArtifactReference> getMonolithprimaryArtifactDsts();
	virtual std::set<MonolithDeployRequirement>       getOutMonolithDeployRequirementLinks();
	virtual std::set<MonolithExecParameter> getOutMonolithExecParameterLinks();
	virtual std::set<MonolithprimaryArtifact>         getOutMonolithprimaryArtifactLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExtensibilityElementImpl
//*******************************************************************
class ExtensibilityElementImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isrequired() ;
	virtual void        setrequired( bool val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExtensibleBindingImpl
//*******************************************************************
class ExtensibleBindingImpl :
	  public ExtensibilityElementImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExtensibleMessageImpl
//*******************************************************************
class ExtensibleMessageImpl :
	  public ExtensibilityElementImpl
{
public:
	typedef enum
	{
		literal_use_Type,
		encoded_use_Type
	} use_Type;

	//
	// attribute getters and setters
	virtual std::string getencodingStyle() ;
	virtual std::string getnamespace() ;
	virtual ExtensibleMessageImpl::use_Type getuse();
	virtual void        setencodingStyle( const std::string& val);
	virtual void        setnamespace( const std::string& val);
	virtual void        setuse( ExtensibleMessageImpl::use_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExtensibleOperationImpl
//*******************************************************************
class ExtensibleOperationImpl :
	  public ExtensibilityElementImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExtensiblePortImpl
//*******************************************************************
class ExtensiblePortImpl :
	  public ExtensibilityElementImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPHeadersImpl
//*******************************************************************
class SOAPHeadersImpl :
	  public ExtensibleMessageImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<IORef>            getHeaderBindingSrcs();
	virtual std::multiset<MessageRef>       getHeaderMessageDsts();
	virtual std::multiset<PartRef>          getHeaderPartDsts();
	virtual std::set<HeaderBinding>         getInHeaderBindingLinks();
	virtual std::set<HeaderMessage>         getOutHeaderMessageLinks();
	virtual std::set<HeaderPart>            getOutHeaderPartLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPAddressImpl
//*******************************************************************
class SOAPAddressImpl :
	  virtual public BON::AtomImpl
	, public ExtensiblePortImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getlocation() ;
	virtual void        setlocation( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPBindingImpl
//*******************************************************************
class SOAPBindingImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleBindingImpl
{
public:
	typedef enum
	{
		document_style_Type,
		rpc_style_Type
	} style_Type;

	//
	// attribute getters and setters
	virtual SOAPBindingImpl::style_Type     getstyle();
	virtual std::string gettransport() ;
	virtual void        setstyle( SOAPBindingImpl::style_Type val);
	virtual void        settransport( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPBodyImpl
//*******************************************************************
class SOAPBodyImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleMessageImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<IORef>            getBodyBindingSrcs();
	virtual std::multiset<PartRef>          getBodyPartsDsts();
	virtual std::set<BodyBinding>           getInBodyBindingLinks();
	virtual std::set<BodyParts>             getOutBodyPartsLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPFaultImpl
//*******************************************************************
class SOAPFaultImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleMessageImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<SOAPFaultExtension>    getInSOAPFaultExtensionLinks();
	virtual std::multiset<FaultRef>         getSOAPFaultExtensionSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPOperationImpl
//*******************************************************************
class SOAPOperationImpl :
	  virtual public BON::AtomImpl
	, public ExtensibleOperationImpl
{
public:
	typedef enum
	{
		document_style_Type,
		rpc_style_Type
	} style_Type;

	//
	// attribute getters and setters
	virtual std::string getsoapAction() ;
	virtual SOAPOperationImpl::style_Type   getstyle();
	virtual void        setsoapAction( const std::string& val);
	virtual void        setstyle( SOAPOperationImpl::style_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPHeaderImpl
//*******************************************************************
class SOAPHeaderImpl :
	  virtual public BON::ModelImpl
	, public SOAPHeadersImpl
{
public:

	//
	// kind and role getters
	virtual std::set<SOAPHeaderFault>       getSOAPHeaderFault();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPHeaderFaultImpl
//*******************************************************************
class SOAPHeaderFaultImpl :
	  virtual public BON::AtomImpl
	, public SOAPHeadersImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ReferrableImpl
//*******************************************************************
class ReferrableImpl :
	  virtual public BON::FCOImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ElementImpl
//*******************************************************************
class ElementImpl :
	  virtual public BON::ModelImpl
	, public ReferrableImpl
{
public:
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
	virtual ElementImpl::schemaType_Type    getschemaType();
	virtual void        setOrder( const long val);
	virtual void        setschemaType( ElementImpl::schemaType_Type val);
	//
	// kind and role getters
	virtual std::set<Attribute>             getAttribute();
	virtual std::set<Element>               getElement();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AtomicTypeImpl
//*******************************************************************
class AtomicTypeImpl :
	  virtual public BON::AtomImpl
	, public ReferrableImpl
{
public:
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
	virtual AtomicTypeImpl::typeCode_Type   gettypeCode();
	virtual void        settypeCode( AtomicTypeImpl::typeCode_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ArtifactContainerImpl
//*******************************************************************
class ArtifactContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ArtifactDependency>    getArtifactDependency();
	virtual std::set<ArtifactDependsOn>     getArtifactDependsOn();
	virtual std::set<ArtifactDeployRequirement>       getArtifactDeployRequirement();
	virtual std::set<ArtifactExecParameter> getArtifactExecParameter();
	virtual std::set<ArtifactInfoProperty>  getArtifactInfoProperty();
	virtual std::set<FOU_Requirement>       getFOU_Requirement();
	virtual std::set<ImplementationArtifact>          getImplementationArtifact();
	virtual std::set<ImplementationArtifactReference> getImplementationArtifactReference();
	virtual std::set<Property>              getProperty();
	virtual std::set<RepGRequirement>       getRepGRequirement();
	virtual std::set<Requirement>           getRequirement();
	virtual std::set<Requirement>           getRequirement(int dummy);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BenchmarkAnalysisImpl
//*******************************************************************
class BenchmarkAnalysisImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Average>               getAverage();
	virtual std::set<BenchmarkCharacteristics>        getBenchmarkCharacteristics();
	virtual std::set<BenchmarkType>         getBenchmarkType();
	virtual std::set<CompRef>               getCompRef();
	virtual std::set<ComponentOperation>    getComponentOperation();
	virtual std::set<DataAnalysisBase>      getDataAnalysisBase();
	virtual std::set<Event>                 getEvent();
	virtual std::set<EventRef>              getEventRef();
	virtual std::set<FactoryOperation>      getFactoryOperation();
	virtual std::set<FixedIterationBenchmarks>        getFixedIterationBenchmarks();
	virtual std::set<Jitter>                getJitter();
	virtual std::set<Latency>               getLatency();
	virtual std::set<LookupOperation>       getLookupOperation();
	virtual std::set<Maximum>               getMaximum();
	virtual std::set<MetricConnection>      getMetricConnection();
	virtual std::set<MetricsBase>           getMetricsBase();
	virtual std::set<Minimum>               getMinimum();
	virtual std::set<OnewayOperation>       getOnewayOperation();
	virtual std::set<OperationBase>         getOperationBase();
	virtual std::set<OperationRef>          getOperationRef();
	virtual std::set<PeriodicBenchmarks>    getPeriodicBenchmarks();
	virtual std::set<Task>                  getTask();
	virtual std::set<TaskSet>               getTaskSet();
	virtual std::set<Throughput>            getThroughput();
	virtual std::set<TimeProbe>             getTimeProbe();
	virtual std::set<TimerConnection>       getTimerConnection();
	virtual std::set<TimerEventSinkConn>    getTimerEventSinkConn();
	virtual std::set<TriggerBenchmarks>     getTriggerBenchmarks();
	virtual std::set<TwowayOperation>       getTwowayOperation();
	virtual std::set<WorkLoadOperationConnection>     getWorkLoadOperationConnection();
	virtual std::set<WorkloadCharacteristics>         getWorkloadCharacteristics();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BindingImpl
//*******************************************************************
class BindingImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<PortType>         getBindingPortTypeDsts();
	virtual std::set<BindingPortType>       getOutBindingPortTypeLinks();
	//
	// kind and role getters
	virtual std::set<BindingOperation>      getBindingOperation();
	virtual std::set<BindsOperation>        getBindsOperation();
	virtual std::set<Documentation>         getDocumentation();
	virtual std::set<OperationRef>          getOperationRef();
	virtual std::set<SOAPBinding>           getSOAPBinding();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BindingOperationImpl
//*******************************************************************
class BindingOperationImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<OperationRef>     getBindsOperationDsts();
	virtual std::set<BindsOperation>        getOutBindsOperationLinks();
	//
	// kind and role getters
	virtual std::set<BodyBinding>           getBodyBinding();
	virtual std::set<BodyParts>             getBodyParts();
	virtual std::set<Documentation>         getDocumentation();
	virtual std::set<ExtensibleMessage>     getExtensibleMessage();
	virtual std::set<FaultRef>              getFaultRef();
	virtual std::set<HeaderBinding>         getHeaderBinding();
	virtual std::set<HeaderMessage>         getHeaderMessage();
	virtual std::set<HeaderPart>            getHeaderPart();
	virtual std::set<IORef>                 getIORef();
	virtual std::set<InputRef>              getInputRef();
	virtual std::set<MessageRef>            getMessageRef();
	virtual std::set<OutputRef>             getOutputRef();
	virtual std::set<PartRef>               getPartRef();
	virtual std::set<SOAPBody>              getSOAPBody();
	virtual std::set<SOAPFault>             getSOAPFault();
	virtual std::set<SOAPFaultExtension>    getSOAPFaultExtension();
	virtual std::set<SOAPHeader>            getSOAPHeader();
	virtual std::set<SOAPHeaderFault>       getSOAPHeaderFault();
	virtual std::set<SOAPOperation>         getSOAPOperation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentContainerImpl
//*******************************************************************
class ComponentContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ComponentConfigProperty>         getComponentConfigProperty();
	virtual std::set<ComponentInfoProperty> getComponentInfoProperty();
	virtual std::set<ComponentProperty>     getComponentProperty();
	virtual std::set<ComponentPropertyDescription>    getComponentPropertyDescription();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<Property>              getProperty();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentImplementationContainerImpl
//*******************************************************************
class ComponentImplementationContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Capability>            getCapability();
	virtual std::set<ComponentAssembly>     getComponentAssembly();
	virtual std::set<ComponentImplementation>         getComponentImplementation();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<ConfigProperty>        getConfigProperty();
	virtual std::set<CriticalPath>          getCriticalPath();
	virtual std::set<ImplementationArtifactReference> getImplementationArtifactReference();
	virtual std::set<ImplementationCapability>        getImplementationCapability();
	virtual std::set<ImplementationDependency>        getImplementationDependency();
	virtual std::set<ImplementationDependsOn>         getImplementationDependsOn();
	virtual std::set<ImplementationRequirement>       getImplementationRequirement();
	virtual std::set<Implements>            getImplements();
	virtual std::set<InfoProperty>          getInfoProperty();
	virtual std::set<MonolithDeployRequirement>       getMonolithDeployRequirement();
	virtual std::set<MonolithExecParameter> getMonolithExecParameter();
	virtual std::set<MonolithicImplementation>        getMonolithicImplementation();
	virtual std::set<MonolithprimaryArtifact>         getMonolithprimaryArtifact();
	virtual std::set<PathReference>         getPathReference();
	virtual std::set<Property>              getProperty();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentPropertyDescriptionImpl
//*******************************************************************
class ComponentPropertyDescriptionImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ComponentRef>     getComponentPropertySrcs();
	virtual std::set<ComponentProperty>     getInComponentPropertyLinks();
	//
	// kind and role getters
	virtual std::set<DataType>              getDataType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DefinitionsImpl
//*******************************************************************
class DefinitionsImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string gettargetNamespace() ;
	virtual void        settargetNamespace( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Attribute>             getAttribute();
	virtual std::set<Binding>               getBinding();
	virtual std::set<BindingPortType>       getBindingPortType();
	virtual std::set<Documentation>         getDocumentation();
	virtual std::set<Import>                getImport();
	virtual std::set<Messages>              getMessages();
	virtual std::set<PortType>              getPortType();
	virtual std::set<Service>               getService();
	virtual std::set<Types>                 getTypes();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DeploymentPlanImpl
//*******************************************************************
class DeploymentPlanImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<CollocationGroup>      getCollocationGroup();
	virtual std::set<ComponentAssemblyReference>      getComponentAssemblyReference();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<InstanceMapping>       getInstanceMapping();
	virtual std::set<NodeReference>         getNodeReference();
	virtual std::set<SharedComponentReference>        getSharedComponentReference();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DocumentationImpl
//*******************************************************************
class DocumentationImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getDocText() ;
	virtual bool        isMixed() ;
	virtual void        setDocText( const std::string& val);
	virtual void        setMixed( bool val);
	//
	// kind and role getters
	virtual std::set<Element>               getElement();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DomainImpl
//*******************************************************************
class DomainImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Bridge>                getBridge();
	virtual std::set<Bridge2Interconnect>   getBridge2Interconnect();
	virtual std::set<Elements>              getElements();
	virtual std::set<Interconnect>          getInterconnect();
	virtual std::set<Interconnect2Bridge>   getInterconnect2Bridge();
	virtual std::set<Interconnect2Node>     getInterconnect2Node();
	virtual std::set<Node>                  getNode();
	virtual std::set<Node2Interconnect>     getNode2Interconnect();
	virtual std::set<Property>              getProperty();
	virtual std::set<SharedResource>        getSharedResource();
	virtual std::set<Shares>                getShares();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EventChannelConfigurationImpl
//*******************************************************************
class EventChannelConfigurationImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<InEventPort>           getInEventPort();
	virtual std::set<OutEventPort>          getOutEventPort();
	virtual std::set<Port>                  getPort();
	virtual std::set<ProvidedRequestPort>   getProvidedRequestPort();
	virtual std::set<Proxy>                 getProxy();
	virtual std::set<RTEC_Connection>       getRTEC_Connection();
	virtual std::set<RTEC_Proxy_Consumer>   getRTEC_Proxy_Consumer();
	virtual std::set<RTEC_Proxy_Supplier>   getRTEC_Proxy_Supplier();
	virtual std::set<RTEC_Resource_Factory> getRTEC_Resource_Factory();
	virtual std::set<RequiredRequestPort>   getRequiredRequestPort();
	virtual std::set<Use_RTEC_Filter>       getUse_RTEC_Filter();
	virtual std::set<Use_RT_Info>           getUse_RT_Info();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FTRequirementsImpl
//*******************************************************************
class FTRequirementsImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<DeploymentPlanRef>     getDeploymentPlanRef();
	virtual std::set<FOU_Requirement>       getFOU_Requirement();
	virtual std::set<FailOverUnit>          getFailOverUnit();
	virtual std::set<ReqConnection>         getReqConnection();
	virtual std::set<SRGContainerRef>       getSRGContainerRef();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FaultImpl
//*******************************************************************
class FaultImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<MessageRef>       getFaultMessageDsts();
	virtual std::set<FaultMessage>          getOutFaultMessageLinks();
	//
	// kind and role getters
	virtual std::set<Documentation>         getDocumentation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImportImpl
//*******************************************************************
class ImportImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getlocation() ;
	virtual std::string getnamespace() ;
	virtual void        setlocation( const std::string& val);
	virtual void        setnamespace( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Definitions>           getDefinitions();
	virtual std::set<Documentation>         getDocumentation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InputImpl
//*******************************************************************
class InputImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<MessageRef>       getInputMessageDsts();
	virtual std::set<InputMessage>          getOutInputMessageLinks();
	//
	// kind and role getters
	virtual std::set<Documentation>         getDocumentation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MPCImpl
//*******************************************************************
class MPCImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Project>               getProject();
	virtual std::set<Workspaces>            getWorkspaces();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MessageImpl
//*******************************************************************
class MessageImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Part>                  getPart();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MessagesImpl
//*******************************************************************
class MessagesImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Message>               getMessage();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OutputImpl
//*******************************************************************
class OutputImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<OutputMessage>         getOutOutputMessageLinks();
	virtual std::multiset<MessageRef>       getOutputMessageDsts();
	//
	// kind and role getters
	virtual std::set<Documentation>         getDocumentation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfigurationContainerImpl
//*******************************************************************
class PackageConfigurationContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ComponentPackage>      getComponentPackage();
	virtual std::set<ComponentPackageReference>       getComponentPackageReference();
	virtual std::set<FOU_Requirement>       getFOU_Requirement();
	virtual std::set<PackageConfBasePackage>          getPackageConfBasePackage();
	virtual std::set<PackageConfConfigProperty>       getPackageConfConfigProperty();
	virtual std::set<PackageConfReference>  getPackageConfReference();
	virtual std::set<PackageConfSelectRequirement>    getPackageConfSelectRequirement();
	virtual std::set<PackageConfSpecializedConfig>    getPackageConfSpecializedConfig();
	virtual std::set<PackageConfiguration>  getPackageConfiguration();
	virtual std::set<Property>              getProperty();
	virtual std::set<RepGRequirement>       getRepGRequirement();
	virtual std::set<Requirement>           getRequirement();
	virtual std::set<Requirement>           getRequirement(int dummy);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageContainerImpl
//*******************************************************************
class PackageContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ComponentImplementationReference> getComponentImplementationReference();
	virtual std::set<ComponentPackage>      getComponentPackage();
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<Implementation>        getImplementation();
	virtual std::set<PackageConfigProperty> getPackageConfigProperty();
	virtual std::set<PackageInfoProperty>   getPackageInfoProperty();
	virtual std::set<PackageInterface>      getPackageInterface();
	virtual std::set<Property>              getProperty();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PathImpl
//*******************************************************************
class PathImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<PathProperty>          getOutPathPropertyLinks();
	virtual std::multiset<Property>         getPathPropertyDsts();
	//
	// kind and role getters
	virtual std::set<ComponentRef>          getComponentRef();
	virtual std::set<ConnectedComponent>    getConnectedComponent();
	virtual std::set<DisplayNode>           getDisplayNode();
	virtual std::set<DstEdge>               getDstEdge();
	virtual std::set<Edge>                  getEdge();
	virtual std::set<EdgeProperty>          getEdgeProperty();
	virtual std::set<GraphVertex>           getGraphVertex();
	virtual std::set<InEventPort>           getInEventPort();
	virtual std::set<OutEventPort>          getOutEventPort();
	virtual std::set<Property>              getProperty();
	virtual std::set<ProvidedRequestPort>   getProvidedRequestPort();
	virtual std::set<RequiredRequestPort>   getRequiredRequestPort();
	virtual std::set<SrcEdge>               getSrcEdge();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PathsImpl
//*******************************************************************
class PathsImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Path>                  getPath();
	virtual std::set<PathProperty>          getPathProperty();
	virtual std::set<Property>              getProperty();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PolicySetImpl
//*******************************************************************
class PolicySetImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<BandedConnectionRef>   getBandedConnectionRef();
	virtual std::set<PriorityModelPolicy>   getPriorityModelPolicy();
	virtual std::set<ThreadPoolRef>         getThreadPoolRef();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PortImpl
//*******************************************************************
class PortImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<PortBinding>           getOutPortBindingLinks();
	virtual std::multiset<BindingRef>       getPortBindingDsts();
	//
	// kind and role getters
	virtual std::set<Documentation>         getDocumentation();
	virtual std::set<SOAPAddress>           getSOAPAddress();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PortTypeImpl
//*******************************************************************
class PortTypeImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Binding>          getBindingPortTypeSrcs();
	virtual std::set<BindingPortType>       getInBindingPortTypeLinks();
	//
	// kind and role getters
	virtual std::set<Documentation>         getDocumentation();
	virtual std::set<NotificationOperation> getNotificationOperation();
	virtual std::set<OneWayOperation>       getOneWayOperation();
	virtual std::set<Operation>             getOperation();
	virtual std::set<RequestResponseOperation>        getRequestResponseOperation();
	virtual std::set<SolicitResponseOperation>        getSolicitResponseOperation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ProjectImpl
//*******************************************************************
class ProjectImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<ComponentLib>          getComponentLib();
	virtual std::set<ExecutorProject>       getExecutorProject();
	virtual std::set<ExtResourceConn>       getExtResourceConn();
	virtual std::set<ExternalResources>     getExternalResources();
	virtual std::set<ImplementationArtifact>          getImplementationArtifact();
	virtual std::set<ServantProject>        getServantProject();
	virtual std::set<StubProject>           getStubProject();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PropertyImpl
//*******************************************************************
class PropertyImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ImplementationArtifact>     getArtifactExecParameterSrcs();
	virtual std::multiset<ImplementationArtifact>     getArtifactInfoPropertySrcs();
	virtual std::multiset<Component>        getAssemblyConfigPropertySrcs();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeMappingValueSrcs();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeValueSrcs();
	virtual std::multiset<ComponentRef>     getComponentConfigPropertySrcs();
	virtual std::multiset<ComponentRef>     getComponentInfoPropertySrcs();
	virtual std::multiset<ComponentImplementation>    getConfigPropertySrcs();
	virtual std::multiset<Edge>             getEdgePropertyDsts();
	virtual std::set<ArtifactExecParameter> getInArtifactExecParameterLinks();
	virtual std::set<ArtifactInfoProperty>  getInArtifactInfoPropertyLinks();
	virtual std::set<AssemblyConfigProperty>          getInAssemblyConfigPropertyLinks();
	virtual std::set<AttributeMappingValue> getInAttributeMappingValueLinks();
	virtual std::set<AttributeValue>        getInAttributeValueLinks();
	virtual std::set<ComponentConfigProperty>         getInComponentConfigPropertyLinks();
	virtual std::set<ComponentInfoProperty> getInComponentInfoPropertyLinks();
	virtual std::set<ConfigProperty>        getInConfigPropertyLinks();
	virtual std::set<InfoProperty>          getInInfoPropertyLinks();
	virtual std::set<MonolithExecParameter> getInMonolithExecParameterLinks();
	virtual std::set<PackageConfConfigProperty>       getInPackageConfConfigPropertyLinks();
	virtual std::set<PackageConfigProperty> getInPackageConfigPropertyLinks();
	virtual std::set<PackageInfoProperty>   getInPackageInfoPropertyLinks();
	virtual std::set<PathProperty>          getInPathPropertyLinks();
	virtual std::multiset<ComponentImplementation>    getInfoPropertySrcs();
	virtual std::multiset<MonolithicImplementation>   getMonolithExecParameterSrcs();
	virtual std::set<EdgeProperty>          getOutEdgePropertyLinks();
	virtual std::multiset<PackageConfiguration>       getPackageConfConfigPropertySrcs();
	virtual std::multiset<ComponentPackage> getPackageConfigPropertySrcs();
	virtual std::multiset<ComponentPackage> getPackageInfoPropertySrcs();
	virtual std::multiset<Path>             getPathPropertySrcs();
	//
	// attribute getters and setters
	virtual std::string getDataValue() ;
	virtual void        setDataValue( const std::string& val);
	//
	// kind and role getters
	virtual std::set<DataType>              getDataType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSCategoryImpl
//*******************************************************************
class QoSCategoryImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<CPU>                   getCPU();
	virtual std::set<Concurrency>           getConcurrency();
	virtual std::set<Connection>            getConnection();
	virtual std::set<Process>               getProcess();
	virtual std::set<QoSCharacteristic>     getQoSCharacteristic();
	virtual std::set<QoSCharacteristic>     getQoSCharacteristic(int dummy);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSContextImpl
//*******************************************************************
class QoSContextImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isisQoSObservation() ;
	virtual void        setisQoSObservation( bool val);
	//
	// kind and role getters
	virtual std::set<CPU>                   getCPU();
	virtual std::set<Concurrency>           getConcurrency();
	virtual std::set<Connection>            getConnection();
	virtual std::set<Process>               getProcess();
	virtual std::set<QoSCharacteristic>     getQoSCharacteristic();
	virtual std::set<QoSCharacteristic>     getQoSCharacteristic(int dummy);
	virtual std::set<QoSConstraint>         getQoSConstraint();
	virtual std::set<QoSContext>            getQoSContext();
	virtual std::set<QoSContract>           getQoSContract();
	virtual std::set<QoSOffered>            getQoSOffered();
	virtual std::set<QoSRequired>           getQoSRequired();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSValueImpl
//*******************************************************************
class QoSValueImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<QoSDecoration>         getOutQoSDecorationLinks();
	virtual std::multiset<Component>        getQoSDecorationDsts();
	//
	// kind and role getters
	virtual std::set<CPU>                   getCPU();
	virtual std::set<Concurrency>           getConcurrency();
	virtual std::set<Connection>            getConnection();
	virtual std::set<Process>               getProcess();
	virtual std::set<QoSCharacteristic>     getQoSCharacteristic();
	virtual std::set<QoSCharacteristic>     getQoSCharacteristic(int dummy);
	virtual std::set<QoSDimensionQualifier> getQoSDimensionQualifier();
	virtual std::set<QoSDimensionSlot>      getQoSDimensionSlot();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTConfigurationImpl
//*******************************************************************
class RTConfigurationImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<RTModel>               getRTModel();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTModelImpl
//*******************************************************************
class RTModelImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<EnvironmentConf>       getEnvironmentConf();
	virtual std::set<PolicySet>             getPolicySet();
	virtual std::set<PolicySetRef>          getPolicySetRef();
	virtual std::set<ResourceContainer>     getResourceContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ResourceContainerImpl
//*******************************************************************
class ResourceContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<BandedConnection>      getBandedConnection();
	virtual std::set<SimpleThreadPool>      getSimpleThreadPool();
	virtual std::set<ThreadPoolWithLanes>   getThreadPoolWithLanes();
	virtual std::set<resource>              getresource();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SRGContainerImpl
//*******************************************************************
class SRGContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<NodeGroup>             getNodeGroup();
	virtual std::set<SharedRiskComposite>   getSharedRiskComposite();
	virtual std::set<SharedRiskGroup>       getSharedRiskGroup();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SatisfierPropertyImpl
//*******************************************************************
class SatisfierPropertyImpl :
	  virtual public BON::ModelImpl
{
public:
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
	virtual SatisfierPropertyImpl::SatisfierPropertyKind_Type getSatisfierPropertyKind();
	virtual bool        isdynamic() ;
	virtual void        setDataValue( const std::string& val);
	virtual void        setSatisfierPropertyKind( SatisfierPropertyImpl::SatisfierPropertyKind_Type val);
	virtual void        setdynamic( bool val);
	//
	// kind and role getters
	virtual std::set<DataType>              getDataType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SchemaImpl
//*******************************************************************
class SchemaImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string gettargetNamespace() ;
	virtual void        settargetNamespace( const std::string& val);
	//
	// kind and role getters
	virtual std::set<Attribute>             getAttribute();
	virtual std::set<Element>               getElement();
	virtual std::set<SchemaImport>          getSchemaImport();
	virtual std::set<SchemaReference>       getSchemaReference();
	virtual std::set<SchemaReference>       getSchemaReference(int dummy);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SchemaBuiltinsImpl
//*******************************************************************
class SchemaBuiltinsImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<AtomicType>            getAtomicType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ServiceImpl
//*******************************************************************
class ServiceImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<BindingRef>            getBindingRef();
	virtual std::set<Port>                  getPort();
	virtual std::set<PortBinding>           getPortBinding();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SystemImpl
//*******************************************************************
class SystemImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<CCMAssembly>           getCCMAssembly();
	virtual std::set<WebService>            getWebService();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TopLevelPackageContainerImpl
//*******************************************************************
class TopLevelPackageContainerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<PackageConfigurationReference>   getPackageConfigurationReference();
	virtual std::set<TopLevelPackage>       getTopLevelPackage();
	virtual std::set<package>               getpackage();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TypesImpl
//*******************************************************************
class TypesImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// kind and role getters
	virtual std::set<Documentation>         getDocumentation();
	virtual std::set<Schema>                getSchema();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerImpl
//*******************************************************************
class WorkerImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isAbstract() ;
	virtual void        setAbstract( bool val);
	//
	// kind and role getters
	virtual std::set<Action>                getAction();
	virtual std::set<Action>                getAction(int dummy);
	virtual std::set<CompositeAction>       getCompositeAction();
	virtual std::set<OutputAction>          getOutputAction();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerLibraryImpl
//*******************************************************************
class WorkerLibraryImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getLocation() ;
	virtual void        setLocation( const std::string& val);
	//
	// kind and role getters
	virtual std::set<WorkerFile>            getWorkerFile();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BenchmarkTypeImpl
//*******************************************************************
class BenchmarkTypeImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<MetricsBase>      getBenchmarkCharacteristicsDsts();
	virtual std::set<BenchmarkCharacteristics>        getOutBenchmarkCharacteristicsLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FixedIterationBenchmarksImpl
//*******************************************************************
class FixedIterationBenchmarksImpl :
	  virtual public BON::AtomImpl
	, public BenchmarkTypeImpl
{
public:

	//
	// attribute getters and setters
	virtual long        getbenchmarkIterations() ;
	virtual void        setbenchmarkIterations( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PeriodicBenchmarksImpl
//*******************************************************************
class PeriodicBenchmarksImpl :
	  virtual public BON::AtomImpl
	, public BenchmarkTypeImpl
{
public:

	//
	// attribute getters and setters
	virtual long        gettimeperiod() ;
	virtual void        settimeperiod( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TriggerBenchmarksImpl
//*******************************************************************
class TriggerBenchmarksImpl :
	  virtual public BON::AtomImpl
	, public BenchmarkTypeImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DataAnalysisBaseImpl
//*******************************************************************
class DataAnalysisBaseImpl :
	  virtual public BON::FCOImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AverageImpl
//*******************************************************************
class AverageImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   JitterImpl
//*******************************************************************
class JitterImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MaximumImpl
//*******************************************************************
class MaximumImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MinimumImpl
//*******************************************************************
class MinimumImpl :
	  virtual public BON::AtomImpl
	, public DataAnalysisBaseImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   IORefImpl
//*******************************************************************
class IORefImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<SOAPBody>         getBodyBindingDsts();
	virtual std::multiset<SOAPHeaders>      getHeaderBindingDsts();
	virtual std::set<BodyBinding>           getOutBodyBindingLinks();
	virtual std::set<HeaderBinding>         getOutHeaderBindingLinks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InputRefImpl
//*******************************************************************
class InputRefImpl :
	  virtual public BON::ReferenceImpl
	, public IORefImpl
{
public:

	//
	// ref getters
	virtual Input       getInput();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OutputRefImpl
//*******************************************************************
class OutputRefImpl :
	  virtual public BON::ReferenceImpl
	, public IORefImpl
{
public:

	//
	// ref getters
	virtual Output      getOutput();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSConstraintImpl
//*******************************************************************
class QoSConstraintImpl :
	  virtual public BON::FCOImpl
{
public:
	typedef enum
	{
		Gaurantee_Qualification_Type,
		BestEffort_Qualification_Type,
		ThresholdBestEffort_Qualification_Type,
		CompulsoryBestEffort_Qualification_Type,
		None_Qualification_Type
	} Qualification_Type;

	//
	// attribute getters and setters
	virtual QoSConstraintImpl::Qualification_Type     getQualification();
	virtual void        setQualification( QoSConstraintImpl::Qualification_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSContractImpl
//*******************************************************************
class QoSContractImpl :
	  virtual public BON::AtomImpl
	, public QoSConstraintImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSOfferedImpl
//*******************************************************************
class QoSOfferedImpl :
	  virtual public BON::AtomImpl
	, public QoSConstraintImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSRequiredImpl
//*******************************************************************
class QoSRequiredImpl :
	  virtual public BON::AtomImpl
	, public QoSConstraintImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeImpl
//*******************************************************************
class AttributeImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getValue() ;
	virtual void        setValue( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentPackageImpl
//*******************************************************************
class ComponentPackageImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ComponentImplementationReference> getImplementationDsts();
	virtual std::set<PackageConfBasePackage>          getInPackageConfBasePackageLinks();
	virtual std::set<Implementation>        getOutImplementationLinks();
	virtual std::set<PackageConfigProperty> getOutPackageConfigPropertyLinks();
	virtual std::set<PackageInfoProperty>   getOutPackageInfoPropertyLinks();
	virtual std::set<PackageInterface>      getOutPackageInterfaceLinks();
	virtual std::multiset<PackageConfiguration>       getPackageConfBasePackageSrcs();
	virtual std::multiset<Property>         getPackageConfigPropertyDsts();
	virtual std::multiset<Property>         getPackageInfoPropertyDsts();
	virtual std::multiset<ComponentRef>     getPackageInterfaceDsts();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_Filter_GroupImpl
//*******************************************************************
class RTEC_Filter_GroupImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<Include_RT_Info>       getInInclude_RT_InfoLinks();
	virtual std::multiset<RTEC_Filter_Group>          getInclude_RTEC_Filter_GroupDsts();
	virtual std::multiset<RTEC_Filter_Group>          getInclude_RTEC_Filter_GroupEnds();
	virtual std::set<Include_RTEC_Filter_Group>       getInclude_RTEC_Filter_GroupLinks();
	virtual std::multiset<RTEC_Filter_Group>          getInclude_RTEC_Filter_GroupSrcs();
	virtual std::multiset<RT_Info_Param>    getInclude_RT_InfoSrcs();
	virtual std::set<Use_RTEC_Filter>       getOutUse_RTEC_FilterLinks();
	virtual std::multiset<BON::ConnectionEnd>         getUse_RTEC_FilterDsts();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConjunctionGroupImpl
//*******************************************************************
class ConjunctionGroupImpl :
	  public RTEC_Filter_GroupImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DisjunctionGroupImpl
//*******************************************************************
class DisjunctionGroupImpl :
	  public RTEC_Filter_GroupImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   LogicalANDGroupImpl
//*******************************************************************
class LogicalANDGroupImpl :
	  public RTEC_Filter_GroupImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConnectionBandImpl
//*******************************************************************
class ConnectionBandImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// attribute getters and setters
	virtual long        gethigh() ;
	virtual long        getlow() ;
	virtual void        sethigh( const long val);
	virtual void        setlow( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EdgeImpl
//*******************************************************************
class EdgeImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getDstEdgeSrcs();
	virtual std::multiset<Property>         getEdgePropertySrcs();
	virtual std::set<DstEdge>               getInDstEdgeLinks();
	virtual std::set<EdgeProperty>          getInEdgePropertyLinks();
	virtual std::set<SrcEdge>               getOutSrcEdgeLinks();
	virtual std::multiset<BON::ConnectionEnd>         getSrcEdgeDsts();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EnumValueImpl
//*******************************************************************
class EnumValueImpl :
	  virtual public BON::AtomImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EnvironmentConfImpl
//*******************************************************************
class EnvironmentConfImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getCmdLineOptions() ;
	virtual std::string getSvcConf() ;
	virtual void        setCmdLineOptions( const std::string& val);
	virtual void        setSvcConf( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExternalReferenceEndPointImpl
//*******************************************************************
class ExternalReferenceEndPointImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Component>        getExternalDelegateSrcs();
	virtual std::set<ExternalDelegate>      getInExternalDelegateLinks();
	//
	// attribute getters and setters
	virtual std::string getlocation() ;
	virtual void        setlocation( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationArtifactImpl
//*******************************************************************
class ImplementationArtifactImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ImplementationArtifact>     getArtifactDependencyDsts();
	virtual std::set<ArtifactDependency>    getArtifactDependencyLinks();
	virtual std::multiset<ImplementationArtifact>     getArtifactDependencySrcs();
	virtual std::multiset<ImplementationArtifactReference> getArtifactDependsOnDsts();
	virtual std::multiset<Requirement>      getArtifactDeployRequirementDsts();
	virtual std::multiset<Property>         getArtifactExecParameterDsts();
	virtual std::multiset<Property>         getArtifactInfoPropertyDsts();
	virtual std::set<ArtifactDependency>    getInArtifactDependencyLinks();
	virtual std::set<ArtifactDependency>    getOutArtifactDependencyLinks();
	virtual std::set<ArtifactDependsOn>     getOutArtifactDependsOnLinks();
	virtual std::set<ArtifactDeployRequirement>       getOutArtifactDeployRequirementLinks();
	virtual std::set<ArtifactExecParameter> getOutArtifactExecParameterLinks();
	virtual std::set<ArtifactInfoProperty>  getOutArtifactInfoPropertyLinks();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getconfiguration() ;
	virtual std::string getlabel() ;
	virtual std::string getlocation() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setconfiguration( const std::string& val);
	virtual void        setlabel( const std::string& val);
	virtual void        setlocation( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationDependencyImpl
//*******************************************************************
class ImplementationDependencyImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ComponentImplementation>    getImplementationDependsOnSrcs();
	virtual std::set<ImplementationDependsOn>         getInImplementationDependsOnLinks();
	//
	// attribute getters and setters
	virtual std::string getrequiredType() ;
	virtual void        setrequiredType( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   LabelImpl
//*******************************************************************
class LabelImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<LabelConnection>       getInLabelConnectionLinks();
	virtual std::multiset<Member>           getLabelConnectionSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RT_Info_ParamImpl
//*******************************************************************
class RT_Info_ParamImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<RTEC_Connection>       getInRTEC_ConnectionLinks();
	virtual std::multiset<RTEC_Filter_Group>          getInclude_RT_InfoDsts();
	virtual std::set<Include_RT_Info>       getOutInclude_RT_InfoLinks();
	virtual std::set<Use_RT_Info>           getOutUse_RT_InfoLinks();
	virtual std::multiset<BON::ConnectionEnd>         getRTEC_ConnectionSrcs();
	virtual std::multiset<RTEC_Resource_Factory_Reference> getUse_RT_InfoDsts();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Null_RT_InfoImpl
//*******************************************************************
class Null_RT_InfoImpl :
	  public RT_Info_ParamImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RT_InfoImpl
//*******************************************************************
class RT_InfoImpl :
	  public RT_Info_ParamImpl
{
public:
	typedef enum
	{
		VERY_LOW_CRITICALITY_criticality_Type,
		LOW_CRITICALITY_criticality_Type,
		MEDIUM_CRITICALITY_criticality_Type,
		HIGH_CRITICALITY_criticality_Type,
		VERY_HIGH_CRITICALITY_criticality_Type
	} criticality_Type;
	typedef enum
	{
		DEPENDENCY_DISABLED_enabled_Type,
		DEPENDENCY_ENABLED_enabled_Type,
		DEPENDENCY_NON_VOLATILE_enabled_Type
	} enabled_Type;
	typedef enum
	{
		VERY_LOW_IMPORTANCE_importance_Type,
		LOW_IMPORTANCE_importance_Type,
		MEDIUM_IMPORTANCE_importance_Type,
		HIGH_IMPORTANCE_importance_Type,
		VERY_HIGH_IMPORTANCE_importance_Type
	} importance_Type;
	typedef enum
	{
		OPERATION_info_type_Type,
		CONJUNCTION_info_type_Type,
		DISJUNCTION_info_type_Type,
		REMOTE_DEPENDANT_info_type_Type
	} info_type_Type;

	//
	// attribute getters and setters
	virtual long        getcached_execution_time() ;
	virtual RT_InfoImpl::criticality_Type   getcriticality();
	virtual RT_InfoImpl::enabled_Type       getenabled();
	virtual std::string getentry_point() ;
	virtual RT_InfoImpl::importance_Type    getimportance();
	virtual RT_InfoImpl::info_type_Type     getinfo_type();
	virtual long        getperiod() ;
	virtual long        getquantum() ;
	virtual long        getthreads() ;
	virtual long        gettypical_execution_time() ;
	virtual long        getworst_case_execution_time() ;
	virtual void        setcached_execution_time( const long val);
	virtual void        setcriticality( RT_InfoImpl::criticality_Type val);
	virtual void        setenabled( RT_InfoImpl::enabled_Type val);
	virtual void        setentry_point( const std::string& val);
	virtual void        setimportance( RT_InfoImpl::importance_Type val);
	virtual void        setinfo_type( RT_InfoImpl::info_type_Type val);
	virtual void        setperiod( const long val);
	virtual void        setquantum( const long val);
	virtual void        setthreads( const long val);
	virtual void        settypical_execution_time( const long val);
	virtual void        setworst_case_execution_time( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfigurationImpl
//*******************************************************************
class PackageConfigurationImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<PackageConfBasePackage>          getOutPackageConfBasePackageLinks();
	virtual std::set<PackageConfConfigProperty>       getOutPackageConfConfigPropertyLinks();
	virtual std::set<PackageConfReference>  getOutPackageConfReferenceLinks();
	virtual std::set<PackageConfSelectRequirement>    getOutPackageConfSelectRequirementLinks();
	virtual std::set<PackageConfSpecializedConfig>    getOutPackageConfSpecializedConfigLinks();
	virtual std::multiset<ComponentPackage> getPackageConfBasePackageDsts();
	virtual std::multiset<Property>         getPackageConfConfigPropertyDsts();
	virtual std::multiset<ComponentPackageReference>  getPackageConfReferenceDsts();
	virtual std::multiset<Requirement>      getPackageConfSelectRequirementDsts();
	virtual std::multiset<PackageConfigurationReference> getPackageConfSpecializedConfigDsts();
	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PriorityModelPolicyImpl
//*******************************************************************
class PriorityModelPolicyImpl :
	  virtual public BON::AtomImpl
{
public:
	typedef enum
	{
		CLIENT_PROPAGATED_PriorityModel_Type,
		SERVER_DECLARED_PriorityModel_Type
	} PriorityModel_Type;

	//
	// attribute getters and setters
	virtual std::string getPriority() ;
	virtual PriorityModelPolicyImpl::PriorityModel_Type getPriorityModel();
	virtual void        setPriority( const std::string& val);
	virtual void        setPriorityModel( PriorityModelPolicyImpl::PriorityModel_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PrivateFlagImpl
//*******************************************************************
class PrivateFlagImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<MakeMemberPrivate>     getInMakeMemberPrivateLinks();
	virtual std::multiset<Member>           getMakeMemberPrivateSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PublishConnectorImpl
//*******************************************************************
class PublishConnectorImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Requirement>      getAssemblyDeployRequirementDsts();
	virtual std::set<publish>               getInpublishLinks();
	virtual std::set<AssemblyDeployRequirement>       getOutAssemblyDeployRequirementLinks();
	virtual std::set<deliverTo>             getOutdeliverToLinks();
	virtual std::multiset<BON::ConnectionEnd>         getdeliverToDsts();
	virtual std::multiset<BON::ConnectionEnd>         getpublishSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSDimensionImpl
//*******************************************************************
class QoSDimensionImpl :
	  virtual public BON::AtomImpl
{
public:
	typedef enum
	{
		Increasing_direction_Type,
		Decreasing_direction_Type,
		Undefined_direction_Type
	} direction_Type;
	typedef enum
	{
		MaxValue_statisticalQualifier_Type,
		MinValue_statisticalQualifier_Type,
		Range_statisticalQualifier_Type,
		Mean_statisticalQualifier_Type,
		Variance_statisticalQualifier_Type,
		StdDev_statisticalQualifier_Type,
		Percentile_statisticalQualifier_Type,
		Frequency_statisticalQualifier_Type,
		Moment_statisticalQualifier_Type,
		Distribution_statisticalQualifier_Type
	} statisticalQualifier_Type;

	//
	// connectionEnd getters
	virtual std::set<QoSDimensionQualifier> getInQoSDimensionQualifierLinks();
	virtual std::multiset<QoSDimensionSlot> getQoSDimensionQualifierSrcs();
	//
	// attribute getters and setters
	virtual QoSDimensionImpl::direction_Type          getdirection();
	virtual QoSDimensionImpl::statisticalQualifier_Type getstatisticalQualifier();
	virtual std::string getunits() ;
	virtual void        setdirection( QoSDimensionImpl::direction_Type val);
	virtual void        setstatisticalQualifier( QoSDimensionImpl::statisticalQualifier_Type val);
	virtual void        setunits( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSDimensionSlotImpl
//*******************************************************************
class QoSDimensionSlotImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<QoSDimensionQualifier> getOutQoSDimensionQualifierLinks();
	virtual std::multiset<QoSDimension>     getQoSDimensionQualifierDsts();
	//
	// attribute getters and setters
	virtual std::string getvalue() ;
	virtual void        setvalue( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSParameterImpl
//*******************************************************************
class QoSParameterImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getvalue() ;
	virtual void        setvalue( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_Resource_FactoryImpl
//*******************************************************************
class RTEC_Resource_FactoryImpl :
	  virtual public BON::AtomImpl
{
public:
	typedef enum
	{
		null__default__ECConsumerControl_Type,
		reactive_ECConsumerControl_Type
	} ECConsumerControl_Type;
	typedef enum
	{
		null_ECConsumerLock_Type,
		thread__default__ECConsumerLock_Type,
		recursive_ECConsumerLock_Type
	} ECConsumerLock_Type;
	typedef enum
	{
		reactive__default__ECDispatching_Type,
		priority_ECDispatching_Type,
		mt_ECDispatching_Type
	} ECDispatching_Type;
	typedef enum
	{
		null_ECFiltering_Type,
		basic__default__ECFiltering_Type,
		prefix_ECFiltering_Type,
		priority_ECFiltering_Type
	} ECFiltering_Type;
	typedef enum
	{
		null__default__ECObserver_Type,
		basic_ECObserver_Type
	} ECObserver_Type;
	typedef enum
	{
		list__default__ECProxyPushConsumerCollectionFlag_Type,
		rb_tree_ECProxyPushConsumerCollectionFlag_Type
	} ECProxyPushConsumerCollectionFlag_Type;
	typedef enum
	{
		copy_on_read_ECProxyPushConsumerCollectionIterator_Type,
		copy_on_write_ECProxyPushConsumerCollectionIterator_Type,
		delayed_ECProxyPushConsumerCollectionIterator_Type,
		immediate__default__ECProxyPushConsumerCollectionIterator_Type
	} ECProxyPushConsumerCollectionIterator_Type;
	typedef enum
	{
		mt__default__ECProxyPushConsumerCollectionSynch_Type,
		st_ECProxyPushConsumerCollectionSynch_Type
	} ECProxyPushConsumerCollectionSynch_Type;
	typedef enum
	{
		list__default__ECProxyPushSupplierCollectionFlag_Type,
		rb_tree_ECProxyPushSupplierCollectionFlag_Type
	} ECProxyPushSupplierCollectionFlag_Type;
	typedef enum
	{
		copy_on_read_ECProxyPushSupplierCollectionIterator_Type,
		copy_on_write_ECProxyPushSupplierCollectionIterator_Type,
		delayed_ECProxyPushSupplierCollectionIterator_Type,
		immediate__default__ECProxyPushSupplierCollectionIterator_Type
	} ECProxyPushSupplierCollectionIterator_Type;
	typedef enum
	{
		mt__default__ECProxyPushSupplierCollectionSynch_Type,
		st_ECProxyPushSupplierCollectionSynch_Type
	} ECProxyPushSupplierCollectionSynch_Type;
	typedef enum
	{
		null__default__ECScheduling_Type,
		priority_ECScheduling_Type
	} ECScheduling_Type;
	typedef enum
	{
		null__default__ECSupplierControl_Type,
		reactive_ECSupplierControl_Type
	} ECSupplierControl_Type;
	typedef enum
	{
		null_ECSupplierFiltering_Type,
		per_supplier__default__ECSupplierFiltering_Type
	} ECSupplierFiltering_Type;
	typedef enum
	{
		null_ECSupplierLock_Type,
		thread__default__ECSupplierLock_Type,
		recursive_ECSupplierLock_Type
	} ECSupplierLock_Type;
	typedef enum
	{
		reactive__default__ECTimeout_Type,
		priority_ECTimeout_Type
	} ECTimeout_Type;

	//
	// attribute getters and setters
	virtual RTEC_Resource_FactoryImpl::ECConsumerControl_Type getECConsumerControl();
	virtual long        getECConsumerControlPeriod() ;
	virtual RTEC_Resource_FactoryImpl::ECConsumerLock_Type getECConsumerLock();
	virtual RTEC_Resource_FactoryImpl::ECDispatching_Type getECDispatching();
	virtual long        getECDispatchingThreads() ;
	virtual RTEC_Resource_FactoryImpl::ECFiltering_Type getECFiltering();
	virtual RTEC_Resource_FactoryImpl::ECObserver_Type getECObserver();
	virtual RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionFlag_Type getECProxyPushConsumerCollectionFlag();
	virtual RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionIterator_Type getECProxyPushConsumerCollectionIterator();
	virtual RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionSynch_Type getECProxyPushConsumerCollectionSynch();
	virtual RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionFlag_Type getECProxyPushSupplierCollectionFlag();
	virtual RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionIterator_Type getECProxyPushSupplierCollectionIterator();
	virtual RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionSynch_Type getECProxyPushSupplierCollectionSynch();
	virtual RTEC_Resource_FactoryImpl::ECScheduling_Type getECScheduling();
	virtual RTEC_Resource_FactoryImpl::ECSupplierControl_Type getECSupplierControl();
	virtual long        getECSupplierControlPeriod() ;
	virtual RTEC_Resource_FactoryImpl::ECSupplierFiltering_Type getECSupplierFiltering();
	virtual RTEC_Resource_FactoryImpl::ECSupplierLock_Type getECSupplierLock();
	virtual RTEC_Resource_FactoryImpl::ECTimeout_Type getECTimeout();
	virtual std::string getECUseORBId() ;
	virtual void        setECConsumerControl( RTEC_Resource_FactoryImpl::ECConsumerControl_Type val);
	virtual void        setECConsumerControlPeriod( const long val);
	virtual void        setECConsumerLock( RTEC_Resource_FactoryImpl::ECConsumerLock_Type val);
	virtual void        setECDispatching( RTEC_Resource_FactoryImpl::ECDispatching_Type val);
	virtual void        setECDispatchingThreads( const long val);
	virtual void        setECFiltering( RTEC_Resource_FactoryImpl::ECFiltering_Type val);
	virtual void        setECObserver( RTEC_Resource_FactoryImpl::ECObserver_Type val);
	virtual void        setECProxyPushConsumerCollectionFlag( RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionFlag_Type val);
	virtual void        setECProxyPushConsumerCollectionIterator( RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionIterator_Type val);
	virtual void        setECProxyPushConsumerCollectionSynch( RTEC_Resource_FactoryImpl::ECProxyPushConsumerCollectionSynch_Type val);
	virtual void        setECProxyPushSupplierCollectionFlag( RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionFlag_Type val);
	virtual void        setECProxyPushSupplierCollectionIterator( RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionIterator_Type val);
	virtual void        setECProxyPushSupplierCollectionSynch( RTEC_Resource_FactoryImpl::ECProxyPushSupplierCollectionSynch_Type val);
	virtual void        setECScheduling( RTEC_Resource_FactoryImpl::ECScheduling_Type val);
	virtual void        setECSupplierControl( RTEC_Resource_FactoryImpl::ECSupplierControl_Type val);
	virtual void        setECSupplierControlPeriod( const long val);
	virtual void        setECSupplierFiltering( RTEC_Resource_FactoryImpl::ECSupplierFiltering_Type val);
	virtual void        setECSupplierLock( RTEC_Resource_FactoryImpl::ECSupplierLock_Type val);
	virtual void        setECTimeout( RTEC_Resource_FactoryImpl::ECTimeout_Type val);
	virtual void        setECUseORBId( const std::string& val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   StateImpl
//*******************************************************************
class StateImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ActionBase>       getEffectSrcs();
	virtual std::multiset<InputActionBase>  getFinishDsts();
	virtual std::set<Effect>                getInEffectLinks();
	virtual std::set<Finish>                getOutFinishLinks();
	virtual std::set<Transition>            getOutTransitionLinks();
	virtual std::multiset<ActionBase>       getTransitionDsts();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TaskImpl
//*******************************************************************
class TaskImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<WorkLoadOperationConnection>     getInWorkLoadOperationConnectionLinks();
	virtual std::multiset<OperationRef>     getWorkLoadOperationConnectionSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ThreadPoolLaneImpl
//*******************************************************************
class ThreadPoolLaneImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// attribute getters and setters
	virtual long        getdynamic_threads() ;
	virtual long        getlane_priority() ;
	virtual long        getstatic_threads() ;
	virtual void        setdynamic_threads( const long val);
	virtual void        setlane_priority( const long val);
	virtual void        setstatic_threads( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TimeProbeImpl
//*******************************************************************
class TimeProbeImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<TimerConnection>       getInTimerConnectionLinks();
	virtual std::set<TimerEventSinkConn>    getInTimerEventSinkConnLinks();
	virtual std::multiset<OperationRef>     getTimerConnectionSrcs();
	virtual std::multiset<EventRef>         getTimerEventSinkConnSrcs();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TopLevelPackageImpl
//*******************************************************************
class TopLevelPackageImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<package>               getOutpackageLinks();
	virtual std::multiset<PackageConfigurationReference> getpackageDsts();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ArtifactDependencyImpl
//*******************************************************************
class ArtifactDependencyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ImplementationArtifact          getDst();
	virtual ImplementationArtifact          getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ArtifactDependsOnImpl
//*******************************************************************
class ArtifactDependsOnImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ImplementationArtifactReference getDst();
	virtual ImplementationArtifact          getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ArtifactDeployRequirementImpl
//*******************************************************************
class ArtifactDeployRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Requirement getDst();
	virtual ImplementationArtifact          getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ArtifactExecParameterImpl
//*******************************************************************
class ArtifactExecParameterImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ImplementationArtifact          getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ArtifactInfoPropertyImpl
//*******************************************************************
class ArtifactInfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ImplementationArtifact          getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AssemblyConfigPropertyImpl
//*******************************************************************
class AssemblyConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual Component   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AssemblyDeployRequirementImpl
//*******************************************************************
class AssemblyDeployRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Requirement getDst();
	virtual PublishConnector                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AssemblyselectRequirementImpl
//*******************************************************************
class AssemblyselectRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Requirement getDst();
	virtual Component   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeDelegateImpl
//*******************************************************************
class AttributeDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeMappingDelegateImpl
//*******************************************************************
class AttributeMappingDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeMappingValueImpl
//*******************************************************************
class AttributeMappingValueImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeValueImpl
//*******************************************************************
class AttributeValueImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BenchmarkCharacteristicsImpl
//*******************************************************************
class BenchmarkCharacteristicsImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual MetricsBase getDst();
	virtual BenchmarkType                   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BindingPortTypeImpl
//*******************************************************************
class BindingPortTypeImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PortType    getDst();
	virtual Binding     getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BindsOperationImpl
//*******************************************************************
class BindsOperationImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual OperationRef                    getDst();
	virtual BindingOperation                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BodyBindingImpl
//*******************************************************************
class BodyBindingImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual SOAPBody    getDst();
	virtual IORef       getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BodyPartsImpl
//*******************************************************************
class BodyPartsImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PartRef     getDst();
	virtual SOAPBody    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Bridge2InterconnectImpl
//*******************************************************************
class Bridge2InterconnectImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Interconnect                    getDst();
	virtual Bridge      getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentConfigPropertyImpl
//*******************************************************************
class ComponentConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ComponentRef                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentInfoPropertyImpl
//*******************************************************************
class ComponentInfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ComponentRef                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentOperationImpl
//*******************************************************************
class ComponentOperationImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual CompRef     getDst();
	virtual OperationRef                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentPropertyImpl
//*******************************************************************
class ComponentPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ComponentPropertyDescription    getDst();
	virtual ComponentRef                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConfigPropertyImpl
//*******************************************************************
class ConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ComponentImplementation         getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CriticalPathImpl
//*******************************************************************
class CriticalPathImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PathReference                   getDst();
	virtual ComponentAssembly               getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DstEdgeImpl
//*******************************************************************
class DstEdgeImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Edge        getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EdgePropertyImpl
//*******************************************************************
class EdgePropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Edge        getDst();
	virtual Property    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EffectImpl
//*******************************************************************
class EffectImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getPostcondition() ;
	virtual void        setPostcondition( const std::string& val);
	//
	// connectionEnd getters
	virtual State       getDst();
	virtual ActionBase  getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EventSinkDelegateImpl
//*******************************************************************
class EventSinkDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EventSourceDelegateImpl
//*******************************************************************
class EventSourceDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExtResourceConnImpl
//*******************************************************************
class ExtResourceConnImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ExternalResources               getDst();
	virtual ComponentLib                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExternalDelegateImpl
//*******************************************************************
class ExternalDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ExternalReferenceEndPoint       getDst();
	virtual Component   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FacetDelegateImpl
//*******************************************************************
class FacetDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FaultMessageImpl
//*******************************************************************
class FaultMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual MessageRef  getDst();
	virtual Fault       getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FinishImpl
//*******************************************************************
class FinishImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual InputActionBase                 getDst();
	virtual State       getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   HeaderBindingImpl
//*******************************************************************
class HeaderBindingImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual SOAPHeaders getDst();
	virtual IORef       getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   HeaderMessageImpl
//*******************************************************************
class HeaderMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual MessageRef  getDst();
	virtual SOAPHeaders getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   HeaderPartImpl
//*******************************************************************
class HeaderPartImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PartRef     getDst();
	virtual SOAPHeaders getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationImpl
//*******************************************************************
class ImplementationImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ComponentImplementationReference          getDst();
	virtual ComponentPackage                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationCapabilityImpl
//*******************************************************************
class ImplementationCapabilityImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Capability  getDst();
	virtual ComponentImplementation         getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationDependsOnImpl
//*******************************************************************
class ImplementationDependsOnImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ImplementationDependency        getDst();
	virtual ComponentImplementation         getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementsImpl
//*******************************************************************
class ImplementsImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ComponentRef                    getDst();
	virtual ComponentImplementation         getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Include_RTEC_Filter_GroupImpl
//*******************************************************************
class Include_RTEC_Filter_GroupImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual RTEC_Filter_Group               getDst();
	virtual RTEC_Filter_Group               getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Include_RT_InfoImpl
//*******************************************************************
class Include_RT_InfoImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual RTEC_Filter_Group               getDst();
	virtual RT_Info_Param                   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InfoPropertyImpl
//*******************************************************************
class InfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ComponentImplementation         getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InputImpl
//*******************************************************************
class InputImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual InputActionBase                 getDst();
	virtual InEventPort getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InputMessageImpl
//*******************************************************************
class InputMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual MessageRef  getDst();
	virtual Input       getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InstanceMappingImpl
//*******************************************************************
class InstanceMappingImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual NodeReference                   getDst();
	virtual CollocationGroup                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Interconnect2BridgeImpl
//*******************************************************************
class Interconnect2BridgeImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Bridge      getDst();
	virtual Interconnect                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Interconnect2NodeImpl
//*******************************************************************
class Interconnect2NodeImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Node        getDst();
	virtual Interconnect                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   LabelConnectionImpl
//*******************************************************************
class LabelConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Label       getDst();
	virtual Member      getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MakeMemberPrivateImpl
//*******************************************************************
class MakeMemberPrivateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PrivateFlag getDst();
	virtual Member      getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ManagesComponentImpl
//*******************************************************************
class ManagesComponentImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Manageable  getDst();
	virtual ComponentFactory                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MetricConnectionImpl
//*******************************************************************
class MetricConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual MetricsBase getDst();
	virtual OperationRef                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Monitorable2RepGImpl
//*******************************************************************
class Monitorable2RepGImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual RepGRequirement                 getDst();
	virtual FTMonitorable                   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MonolithDeployRequirementImpl
//*******************************************************************
class MonolithDeployRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ImplementationRequirement       getDst();
	virtual MonolithicImplementation        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MonolithExecParameterImpl
//*******************************************************************
class MonolithExecParameterImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual MonolithicImplementation        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MonolithprimaryArtifactImpl
//*******************************************************************
class MonolithprimaryArtifactImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ImplementationArtifactReference getDst();
	virtual MonolithicImplementation        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MultiInputImpl
//*******************************************************************
class MultiInputImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual InputActionBase                 getDst();
	virtual MultiInputBase                  getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Node2InterconnectImpl
//*******************************************************************
class Node2InterconnectImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Interconnect                    getDst();
	virtual Node        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OutputMessageImpl
//*******************************************************************
class OutputMessageImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual MessageRef  getDst();
	virtual Output      getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfBasePackageImpl
//*******************************************************************
class PackageConfBasePackageImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ComponentPackage                getDst();
	virtual PackageConfiguration            getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfConfigPropertyImpl
//*******************************************************************
class PackageConfConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual PackageConfiguration            getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfReferenceImpl
//*******************************************************************
class PackageConfReferenceImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ComponentPackageReference       getDst();
	virtual PackageConfiguration            getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfSelectRequirementImpl
//*******************************************************************
class PackageConfSelectRequirementImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Requirement getDst();
	virtual PackageConfiguration            getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfSpecializedConfigImpl
//*******************************************************************
class PackageConfSpecializedConfigImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PackageConfigurationReference   getDst();
	virtual PackageConfiguration            getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfigPropertyImpl
//*******************************************************************
class PackageConfigPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ComponentPackage                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageInfoPropertyImpl
//*******************************************************************
class PackageInfoPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual ComponentPackage                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageInterfaceImpl
//*******************************************************************
class PackageInterfaceImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual ComponentRef                    getDst();
	virtual ComponentPackage                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PathPropertyImpl
//*******************************************************************
class PathPropertyImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Property    getDst();
	virtual Path        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PortBindingImpl
//*******************************************************************
class PortBindingImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BindingRef  getDst();
	virtual Port        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSDecorationImpl
//*******************************************************************
class QoSDecorationImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Component   getDst();
	virtual QoSValue    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSDimensionQualifierImpl
//*******************************************************************
class QoSDimensionQualifierImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual QoSDimension                    getDst();
	virtual QoSDimensionSlot                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_ConnectionImpl
//*******************************************************************
class RTEC_ConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual RT_Info_Param                   getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ReceptacleDelegateImpl
//*******************************************************************
class ReceptacleDelegateImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ReqConnectionImpl
//*******************************************************************
class ReqConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual FOU_Requirement                 getDst();
	virtual FTComposite getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SOAPFaultExtensionImpl
//*******************************************************************
class SOAPFaultExtensionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual SOAPFault   getDst();
	virtual FaultRef    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SharesImpl
//*******************************************************************
class SharesImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual SharedResource                  getDst();
	virtual Node        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SrcEdgeImpl
//*******************************************************************
class SrcEdgeImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual Edge        getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TimerConnectionImpl
//*******************************************************************
class TimerConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual TimeProbe   getDst();
	virtual OperationRef                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TimerEventSinkConnImpl
//*******************************************************************
class TimerEventSinkConnImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual TimeProbe   getDst();
	virtual EventRef    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TransitionImpl
//*******************************************************************
class TransitionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getPrecondition() ;
	virtual void        setPrecondition( const std::string& val);
	//
	// connectionEnd getters
	virtual ActionBase  getDst();
	virtual State       getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Use_RTEC_FilterImpl
//*******************************************************************
class Use_RTEC_FilterImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual RTEC_Filter_Group               getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Use_RT_InfoImpl
//*******************************************************************
class Use_RT_InfoImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual RTEC_Resource_Factory_Reference getDst();
	virtual RT_Info_Param                   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkLoadOperationConnectionImpl
//*******************************************************************
class WorkLoadOperationConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual Task        getDst();
	virtual OperationRef                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkloadCharacteristicsImpl
//*******************************************************************
class WorkloadCharacteristicsImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual TaskSet     getDst();
	virtual MetricsBase getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   deliverToImpl
//*******************************************************************
class deliverToImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual PublishConnector                getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   emitImpl
//*******************************************************************
class emitImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   invokeImpl
//*******************************************************************
class invokeImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual BON::ConnectionEnd              getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   packageImpl
//*******************************************************************
class packageImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PackageConfigurationReference   getDst();
	virtual TopLevelPackage                 getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   publishImpl
//*******************************************************************
class publishImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual PublishConnector                getDst();
	virtual BON::ConnectionEnd              getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CollocationGroupImpl
//*******************************************************************
class CollocationGroupImpl :
	  virtual public BON::SetImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<NodeReference>    getInstanceMappingDsts();
	virtual std::set<InstanceMapping>       getOutInstanceMappingLinks();
	//
	// set getters
	virtual std::set<BON::Reference>        getAllMembers();
	virtual std::set<ComponentAssemblyReference>      getComponentAssemblyReferences();
	virtual std::set<ComponentRef>          getComponentRefs();
	virtual std::set<SharedComponentReference>        getSharedComponentReferences();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   TaskSetImpl
//*******************************************************************
class TaskSetImpl :
	  virtual public BON::SetImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<WorkloadCharacteristics>         getInWorkloadCharacteristicsLinks();
	virtual std::multiset<MetricsBase>      getWorkloadCharacteristicsSrcs();
	//
	// attribute getters and setters
	virtual long        getpriority() ;
	virtual long        getrate() ;
	virtual void        setpriority( const long val);
	virtual void        setrate( const long val);
	//
	// set getters
	virtual std::set<Task>                  getTasks( int dummy);
	virtual std::set<Task>                  getTasks();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkspacesImpl
//*******************************************************************
class WorkspacesImpl :
	  virtual public BON::SetImpl
{
public:

	//
	// set getters
	virtual std::set<Project>               getProjects( int dummy);
	virtual std::set<Project>               getProjects();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeMappingImpl
//*******************************************************************
class AttributeMappingImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<BON::ConnectionEnd>         getAttributeDelegateDsts();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeMappingDelegateDsts();
	virtual std::set<AttributeMappingDelegate>        getAttributeMappingDelegateLinks();
	virtual std::multiset<BON::ConnectionEnd>         getAttributeMappingDelegateSrcs();
	virtual std::multiset<Property>         getAttributeMappingValueDsts();
	virtual std::set<AttributeMappingDelegate>        getInAttributeMappingDelegateLinks();
	virtual std::set<AttributeDelegate>     getOutAttributeDelegateLinks();
	virtual std::set<AttributeMappingDelegate>        getOutAttributeMappingDelegateLinks();
	virtual std::set<AttributeMappingValue> getOutAttributeMappingValueLinks();
	//
	// ref getters
	virtual ReadonlyAttribute               getReadonlyAttribute();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AttributeMemberImpl
//*******************************************************************
class AttributeMemberImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BandedConnectionRefImpl
//*******************************************************************
class BandedConnectionRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual BandedConnection                getBandedConnection();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   BindingRefImpl
//*******************************************************************
class BindingRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<PortBinding>           getInPortBindingLinks();
	virtual std::multiset<Port>             getPortBindingSrcs();
	//
	// ref getters
	virtual Binding     getBinding();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CCMAssemblyImpl
//*******************************************************************
class CCMAssemblyImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual System      getSystem();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   CompRefImpl
//*******************************************************************
class CompRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<OperationRef>     getComponentOperationSrcs();
	virtual std::set<ComponentOperation>    getInComponentOperationLinks();
	//
	// ref getters
	virtual Component   getComponent();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentImplementationReferenceImpl
//*******************************************************************
class ComponentImplementationReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ComponentPackage> getImplementationSrcs();
	virtual std::set<Implementation>        getInImplementationLinks();
	//
	// ref getters
	virtual ComponentImplementation         getComponentImplementation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentPackageReferenceImpl
//*******************************************************************
class ComponentPackageReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<PackageConfReference>  getInPackageConfReferenceLinks();
	virtual std::multiset<PackageConfiguration>       getPackageConfReferenceSrcs();
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
	virtual ComponentPackage                getComponentPackage();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DataTypeImpl
//*******************************************************************
class DataTypeImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual PredefinedType                  getPredefinedType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DeploymentPlanRefImpl
//*******************************************************************
class DeploymentPlanRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual DeploymentPlan                  getDeploymentPlan();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DiscriminatorImpl
//*******************************************************************
class DiscriminatorImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual ConstantType                    getConstantType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EventRefImpl
//*******************************************************************
class EventRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<TimerEventSinkConn>    getOutTimerEventSinkConnLinks();
	virtual std::multiset<TimeProbe>        getTimerEventSinkConnDsts();
	//
	// ref getters
	virtual Event       getEvent();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExceptionRefImpl
//*******************************************************************
class ExceptionRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Exception   getException();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ExternalResourcesImpl
//*******************************************************************
class ExternalResourcesImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ComponentLib>     getExtResourceConnSrcs();
	virtual std::set<ExtResourceConn>       getInExtResourceConnLinks();
	//
	// ref getters
	virtual ImplementationArtifact          getImplementationArtifact();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FaultRefImpl
//*******************************************************************
class FaultRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<SOAPFaultExtension>    getOutSOAPFaultExtensionLinks();
	virtual std::multiset<SOAPFault>        getSOAPFaultExtensionDsts();
	//
	// ref getters
	virtual Fault       getFault();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   FileRefImpl
//*******************************************************************
class FileRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual File        getFile();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   GetExceptionImpl
//*******************************************************************
class GetExceptionImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Exception   getException();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ImplementationArtifactReferenceImpl
//*******************************************************************
class ImplementationArtifactReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ImplementationArtifact>     getArtifactDependsOnSrcs();
	virtual std::set<ArtifactDependsOn>     getInArtifactDependsOnLinks();
	virtual std::set<MonolithprimaryArtifact>         getInMonolithprimaryArtifactLinks();
	virtual std::multiset<MonolithicImplementation>   getMonolithprimaryArtifactSrcs();
	//
	// ref getters
	virtual ImplementationArtifact          getImplementationArtifact();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InParameterImpl
//*******************************************************************
class InParameterImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InheritsImpl
//*******************************************************************
class InheritsImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Inheritable getInheritable();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InoutParameterImpl
//*******************************************************************
class InoutParameterImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   LookupKeyImpl
//*******************************************************************
class LookupKeyImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual ValueObject getValueObject();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MemberImpl
//*******************************************************************
class MemberImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Label>            getLabelConnectionDsts();
	virtual std::multiset<PrivateFlag>      getMakeMemberPrivateDsts();
	virtual std::set<LabelConnection>       getOutLabelConnectionLinks();
	virtual std::set<MakeMemberPrivate>     getOutMakeMemberPrivateLinks();
	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MessageRefImpl
//*******************************************************************
class MessageRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<Fault>            getFaultMessageSrcs();
	virtual std::multiset<SOAPHeaders>      getHeaderMessageSrcs();
	virtual std::set<FaultMessage>          getInFaultMessageLinks();
	virtual std::set<HeaderMessage>         getInHeaderMessageLinks();
	virtual std::set<InputMessage>          getInInputMessageLinks();
	virtual std::set<OutputMessage>         getInOutputMessageLinks();
	virtual std::multiset<Input>            getInputMessageSrcs();
	virtual std::multiset<Output>           getOutputMessageSrcs();
	//
	// ref getters
	virtual Message     getMessage();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NodeRefImpl
//*******************************************************************
class NodeRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Node        getNode();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NodeReferenceImpl
//*******************************************************************
class NodeReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<InstanceMapping>       getInInstanceMappingLinks();
	virtual std::multiset<CollocationGroup> getInstanceMappingSrcs();
	//
	// ref getters
	virtual Node        getNode();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OperationRefImpl
//*******************************************************************
class OperationRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<CompRef>          getComponentOperationDsts();
	virtual std::multiset<MetricsBase>      getMetricConnectionDsts();
	virtual std::set<ComponentOperation>    getOutComponentOperationLinks();
	virtual std::set<MetricConnection>      getOutMetricConnectionLinks();
	virtual std::set<TimerConnection>       getOutTimerConnectionLinks();
	virtual std::set<WorkLoadOperationConnection>     getOutWorkLoadOperationConnectionLinks();
	virtual std::multiset<TimeProbe>        getTimerConnectionDsts();
	virtual std::multiset<Task>             getWorkLoadOperationConnectionDsts();
	//
	// ref getters
	virtual OperationBase                   getOperationBase();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OperationRefImpl
//*******************************************************************
class OperationRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<BindingOperation> getBindsOperationSrcs();
	virtual std::set<BindsOperation>        getInBindsOperationLinks();
	//
	// ref getters
	virtual Operation   getOperation();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OutParameterImpl
//*******************************************************************
class OutParameterImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PackageConfigurationReferenceImpl
//*******************************************************************
class PackageConfigurationReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<PackageConfSpecializedConfig>    getInPackageConfSpecializedConfigLinks();
	virtual std::set<package>               getInpackageLinks();
	virtual std::multiset<PackageConfiguration>       getPackageConfSpecializedConfigSrcs();
	virtual std::multiset<TopLevelPackage>  getpackageSrcs();
	//
	// ref getters
	virtual PackageConfiguration            getPackageConfiguration();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PartImpl
//*******************************************************************
class PartImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Referrable  getReferrable();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PartRefImpl
//*******************************************************************
class PartRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<SOAPBody>         getBodyPartsSrcs();
	virtual std::multiset<SOAPHeaders>      getHeaderPartSrcs();
	virtual std::set<BodyParts>             getInBodyPartsLinks();
	virtual std::set<HeaderPart>            getInHeaderPartLinks();
	//
	// ref getters
	virtual Part        getPart();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PathReferenceImpl
//*******************************************************************
class PathReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<ComponentAssembly>          getCriticalPathSrcs();
	virtual std::set<CriticalPath>          getInCriticalPathLinks();
	//
	// ref getters
	virtual Path        getPath();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PolicySetRefImpl
//*******************************************************************
class PolicySetRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual PolicySet   getPolicySet();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   QoSCharacteristicRefImpl
//*******************************************************************
class QoSCharacteristicRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual QoSCharacteristic               getQoSCharacteristic();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_Resource_Factory_ReferenceImpl
//*******************************************************************
class RTEC_Resource_Factory_ReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<Use_RT_Info>           getInUse_RT_InfoLinks();
	virtual std::multiset<RT_Info_Param>    getUse_RT_InfoSrcs();
	//
	// ref getters
	virtual RTEC_Resource_Factory           getRTEC_Resource_Factory();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ReturnTypeImpl
//*******************************************************************
class ReturnTypeImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual MemberType  getMemberType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SRGContainerRefImpl
//*******************************************************************
class SRGContainerRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual SRGContainer                    getSRGContainer();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SetExceptionImpl
//*******************************************************************
class SetExceptionImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Exception   getException();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SharedComponentReferenceImpl
//*******************************************************************
class SharedComponentReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual ComponentRef                    getComponentRef();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SharedResourceRefImpl
//*******************************************************************
class SharedResourceRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual SharedResource                  getSharedResource();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SupportsImpl
//*******************************************************************
class SupportsImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Object      getObject();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ThreadPoolRefImpl
//*******************************************************************
class ThreadPoolRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual ThreadPool  getThreadPool();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   VariableImpl
//*******************************************************************
class VariableImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual PredefinedType                  getPredefinedType();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WebServiceImpl
//*******************************************************************
class WebServiceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual System      getSystem();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerTypeImpl
//*******************************************************************
class WorkerTypeImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// ref getters
	virtual Worker      getWorker();

	///BUP
	// add your own members here
	///EUP
};



}; // namespace SIML_BON

///BUP
// add your additional class definitions here
///EUP

#endif // SIMLBONX_H
