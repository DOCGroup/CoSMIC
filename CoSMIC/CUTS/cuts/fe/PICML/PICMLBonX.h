#ifndef PICMLBONX_H
#define PICMLBONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

//
// this dummy template parameter is needed by VC6 to deduct the return type
// VC7 users can modify this macro to a value like "int _dummy = 0"
// TDP standing for TEMPLATE DUMMY PAR
#define TDP int _dummy = 0			// recommended for VC7 users
//#define TDP const T & _dummyComp		// recommended for VC6 users

///BUP
// add your include files/class definitions here
///EUP

namespace PICML_BON
{

DECLARE_BONEXTENSION( BON::Folder, ComponentAnalysesImpl, ComponentAnalyses );
DECLARE_BONEXTENSION( BON::Folder, ComponentBuildImpl, ComponentBuild );
DECLARE_BONEXTENSION( BON::Folder, ComponentImplementationsImpl, ComponentImplementations );
DECLARE_BONEXTENSION( BON::Folder, ComponentPackagesImpl, ComponentPackages );
DECLARE_BONEXTENSION( BON::Folder, ComponentTypesImpl, ComponentTypes );
DECLARE_BONEXTENSION( BON::Folder, DeploymentPlansImpl, DeploymentPlans );
DECLARE_BONEXTENSION( BON::Folder, EventChannelConfigImpl, EventChannelConfig );
DECLARE_BONEXTENSION( BON::Folder, ImplementationArtifactsImpl, ImplementationArtifacts );
DECLARE_BONEXTENSION( BON::Folder, InterfaceDefinitionsImpl, InterfaceDefinitions );
DECLARE_BONEXTENSION( BON::Folder, PackageConfigurationsImpl, PackageConfigurations );
DECLARE_BONEXTENSION( BON::Folder, PathDiagramImpl, PathDiagram );
DECLARE_BONEXTENSION( BON::Folder, PredefinedTypesImpl, PredefinedTypes );
DECLARE_BONEXTENSION( BON::Folder, QoSModelingImpl, QoSModeling );
DECLARE_BONEXTENSION( BON::Folder, TargetsImpl, Targets );
DECLARE_BONEXTENSION( BON::Folder, TopLevelPackagesImpl, TopLevelPackages );
DECLARE_BONEXTENSION( BON::Folder, WorkerLibrariesImpl, WorkerLibraries );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, PrefixableImpl, Prefixable );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, SupportsInterfacesImpl, SupportsInterfaces );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, CommonPortAttrsImpl, CommonPortAttrs );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ConstantTypeImpl, ConstantType );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, GraphVertexImpl, GraphVertex );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, InPortImpl, InPort );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ManageableImpl, Manageable );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, MemberTypeImpl, MemberType );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ProvideableImpl, Provideable );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, TaggableImpl, Taggable );
DECLARE_BONEXTENSION2( BON::Model, GraphVertex, ConnectedComponentImpl, ConnectedComponent );
DECLARE_BONEXTENSION2( BON::Model, Taggable, ExceptionImpl, Exception );
DECLARE_BONEXTENSION( Prefixable, FileImpl, File );
DECLARE_ABSTRACT_BONEXTENSION2( BON::Model, Taggable, OperationBaseImpl, OperationBase );
DECLARE_BONEXTENSION2( Taggable, Prefixable, PackageImpl, Package );
DECLARE_BONEXTENSION2( BON::Model, Taggable, ReadonlyAttributeImpl, ReadonlyAttribute );
DECLARE_ABSTRACT_BONEXTENSION2( Taggable, MemberType, NamedTypeImpl, NamedType );
DECLARE_ABSTRACT_BONEXTENSION3( Taggable, GraphVertex, CommonPortAttrs, PortImpl, Port );
DECLARE_ABSTRACT_BONEXTENSION2( ConstantType, MemberType, PredefinedTypeImpl, PredefinedType );
DECLARE_BONEXTENSION2( BON::Atom, GraphVertex, DisplayNodeImpl, DisplayNode );
DECLARE_BONEXTENSION2( BON::Atom, InPort, EnvironmentImpl, Environment );
DECLARE_BONEXTENSION2( BON::Reference, Manageable, ComponentRefImpl, ComponentRef );
DECLARE_BONEXTENSION2( BON::Reference, Taggable, ConstantImpl, Constant );
DECLARE_BONEXTENSION( ReadonlyAttribute, AttributeImpl, Attribute );
DECLARE_BONEXTENSION3( SupportsInterfaces, Manageable, NamedType, ComponentImpl, Component );
DECLARE_ABSTRACT_BONEXTENSION( OperationBase, HasExceptionsImpl, HasExceptions );
DECLARE_ABSTRACT_BONEXTENSION2( BON::Model, NamedType, InheritableImpl, Inheritable );
DECLARE_BONEXTENSION( OperationBase, OnewayOperationImpl, OnewayOperation );
DECLARE_ABSTRACT_BONEXTENSION( NamedType, NoInheritableImpl, NoInheritable );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, BooleanImpl, Boolean );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, ByteImpl, Byte );
DECLARE_BONEXTENSION3( BON::Atom, PredefinedType, Provideable, GenericObjectImpl, GenericObject );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, GenericValueImpl, GenericValue );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, GenericValueObjectImpl, GenericValueObject );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, LongIntegerImpl, LongInteger );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, RealNumberImpl, RealNumber );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, ShortIntegerImpl, ShortInteger );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, StringImpl, String );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, TypeEncodingImpl, TypeEncoding );
DECLARE_BONEXTENSION2( BON::Atom, PredefinedType, TypeKindImpl, TypeKind );
DECLARE_BONEXTENSION2( BON::Reference, NamedType, BoxedImpl, Boxed );
DECLARE_BONEXTENSION3( BON::Reference, InPort, Port, InEventPortImpl, InEventPort );
DECLARE_BONEXTENSION2( BON::Reference, Port, OutEventPortImpl, OutEventPort );
DECLARE_BONEXTENSION3( BON::Reference, InPort, Port, ProvidedRequestPortImpl, ProvidedRequestPort );
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
DECLARE_BONEXTENSION2( SupportsInterfaces, HasOperations, ComponentFactoryImpl, ComponentFactory );
DECLARE_BONEXTENSION3( HasOperations, Prefixable, Provideable, ObjectImpl, Object );
DECLARE_ABSTRACT_BONEXTENSION3( SupportsInterfaces, HasOperations, Prefixable, ObjectByValueImpl, ObjectByValue );
DECLARE_BONEXTENSION( ObjectByValue, EventImpl, Event );
DECLARE_BONEXTENSION( ObjectByValue, ValueObjectImpl, ValueObject );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ActionBaseImpl, ActionBase );
DECLARE_BONEXTENSION( ActionBase, ActionImpl, Action );
DECLARE_BONEXTENSION( ActionBase, InputActionImpl, InputAction );
DECLARE_BONEXTENSION( ActionBase, OutputActionImpl, OutputAction );
DECLARE_BONEXTENSION( InputAction, PeriodicActionImpl, PeriodicAction );
DECLARE_BONEXTENSION( Action, WorkerActionImpl, WorkerAction );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ProxyImpl, Proxy );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RTEC_ProxyImpl, RTEC_Proxy );
DECLARE_ABSTRACT_BONEXTENSION( Proxy, Proxy_ConsumerImpl, Proxy_Consumer );
DECLARE_ABSTRACT_BONEXTENSION( Proxy, Proxy_SupplierImpl, Proxy_Supplier );
DECLARE_BONEXTENSION2( Proxy_Consumer, RTEC_Proxy, RTEC_Proxy_ConsumerImpl, RTEC_Proxy_Consumer );
DECLARE_BONEXTENSION2( RTEC_Proxy, Proxy_Supplier, RTEC_Proxy_SupplierImpl, RTEC_Proxy_Supplier );
DECLARE_BONEXTENSION( BON::Model, QoSCharacteristicImpl, QoSCharacteristic );
DECLARE_BONEXTENSION( QoSCharacteristic, CPUImpl, CPU );
DECLARE_BONEXTENSION( QoSCharacteristic, ConcurrencyImpl, Concurrency );
DECLARE_BONEXTENSION( QoSCharacteristic, ConnectionImpl, Connection );
DECLARE_BONEXTENSION( QoSCharacteristic, ProcessImpl, Process );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ElementsImpl, Elements );
DECLARE_BONEXTENSION2( BON::Model, Elements, BridgeImpl, Bridge );
DECLARE_BONEXTENSION2( BON::Model, Elements, InterconnectImpl, Interconnect );
DECLARE_BONEXTENSION2( BON::Model, Elements, NodeImpl, Node );
DECLARE_BONEXTENSION2( BON::Model, Elements, SharedResourceImpl, SharedResource );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ComponentLibImpl, ComponentLib );
DECLARE_BONEXTENSION2( BON::Model, ComponentLib, ExecutorProjectImpl, ExecutorProject );
DECLARE_BONEXTENSION2( BON::Model, ComponentLib, ServantProjectImpl, ServantProject );
DECLARE_BONEXTENSION2( BON::Model, ComponentLib, StubProjectImpl, StubProject );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, resourceImpl, resource );
DECLARE_BONEXTENSION2( BON::Model, resource, BandedConnectionImpl, BandedConnection );
DECLARE_ABSTRACT_BONEXTENSION( resource, ThreadPoolImpl, ThreadPool );
DECLARE_BONEXTENSION2( BON::Model, ThreadPool, SimpleThreadPoolImpl, SimpleThreadPool );
DECLARE_BONEXTENSION2( BON::Model, ThreadPool, ThreadPoolWithLanesImpl, ThreadPoolWithLanes );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RequirementBaseImpl, RequirementBase );
DECLARE_BONEXTENSION( RequirementBase, ImplementationRequirementImpl, ImplementationRequirement );
DECLARE_BONEXTENSION( RequirementBase, RequirementImpl, Requirement );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, MetricsBaseImpl, MetricsBase );
DECLARE_BONEXTENSION( MetricsBase, LatencyImpl, Latency );
DECLARE_BONEXTENSION( MetricsBase, ThroughputImpl, Throughput );
DECLARE_ABSTRACT_BONEXTENSION( BON::Model, RequirementSatisfierImpl, RequirementSatisfier );
DECLARE_BONEXTENSION( RequirementSatisfier, CapabilityImpl, Capability );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, ComponentImplementationImpl, ComponentImplementation );
DECLARE_BONEXTENSION2( BON::Model, ComponentImplementation, ComponentAssemblyImpl, ComponentAssembly );
DECLARE_BONEXTENSION2( BON::Atom, ComponentImplementation, MonolithicImplementationImpl, MonolithicImplementation );
DECLARE_BONEXTENSION( BON::Model, ArtifactContainerImpl, ArtifactContainer );
DECLARE_BONEXTENSION( BON::Model, BenchmarkAnalysisImpl, BenchmarkAnalysis );
DECLARE_BONEXTENSION( BON::Model, ComponentContainerImpl, ComponentContainer );
DECLARE_BONEXTENSION( BON::Model, ComponentImplementationContainerImpl, ComponentImplementationContainer );
DECLARE_BONEXTENSION( BON::Model, ComponentPropertyDescriptionImpl, ComponentPropertyDescription );
DECLARE_BONEXTENSION( BON::Model, DeploymentPlanImpl, DeploymentPlan );
DECLARE_BONEXTENSION( BON::Model, DomainImpl, Domain );
DECLARE_BONEXTENSION( BON::Model, EventChannelConfigurationImpl, EventChannelConfiguration );
DECLARE_BONEXTENSION( BON::Model, MPCImpl, MPC );
DECLARE_BONEXTENSION( BON::Model, PackageConfigurationContainerImpl, PackageConfigurationContainer );
DECLARE_BONEXTENSION( BON::Model, PackageContainerImpl, PackageContainer );
DECLARE_BONEXTENSION( BON::Model, PathImpl, Path );
DECLARE_BONEXTENSION( BON::Model, PolicySetImpl, PolicySet );
DECLARE_BONEXTENSION( BON::Model, ProjectImpl, Project );
DECLARE_BONEXTENSION( BON::Model, PropertyImpl, Property );
DECLARE_BONEXTENSION( BON::Model, QoSCategoryImpl, QoSCategory );
DECLARE_BONEXTENSION( BON::Model, QoSContextImpl, QoSContext );
DECLARE_BONEXTENSION( BON::Model, QoSValueImpl, QoSValue );
DECLARE_BONEXTENSION( BON::Model, RTConfigurationImpl, RTConfiguration );
DECLARE_BONEXTENSION( BON::Model, RTModelImpl, RTModel );
DECLARE_BONEXTENSION( BON::Model, ResourceImpl, Resource );
DECLARE_BONEXTENSION( BON::Model, ResourceContainerImpl, ResourceContainer );
DECLARE_BONEXTENSION( BON::Model, SatisfierPropertyImpl, SatisfierProperty );
DECLARE_BONEXTENSION( BON::Model, TopLevelPackageContainerImpl, TopLevelPackageContainer );
DECLARE_BONEXTENSION( BON::Model, WorkerImpl, Worker );
DECLARE_BONEXTENSION( BON::Model, WorkerFileImpl, WorkerFile );
DECLARE_BONEXTENSION( BON::Model, WorkerLibraryImpl, WorkerLibrary );
DECLARE_BONEXTENSION( BON::Model, WorkerPackageImpl, WorkerPackage );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, BenchmarkTypeImpl, BenchmarkType );
DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, FixedIterationBenchmarksImpl, FixedIterationBenchmarks );
DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, PeriodicBenchmarksImpl, PeriodicBenchmarks );
DECLARE_BONEXTENSION2( BON::Atom, BenchmarkType, TriggerBenchmarksImpl, TriggerBenchmarks );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, DataAnalysisBaseImpl, DataAnalysisBase );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, AverageImpl, Average );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, JitterImpl, Jitter );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, MaximumImpl, Maximum );
DECLARE_BONEXTENSION2( BON::Atom, DataAnalysisBase, MinimumImpl, Minimum );
DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, QoSConstraintImpl, QoSConstraint );
DECLARE_BONEXTENSION2( BON::Atom, QoSConstraint, QoSContractImpl, QoSContract );
DECLARE_BONEXTENSION2( BON::Atom, QoSConstraint, QoSOfferedImpl, QoSOffered );
DECLARE_BONEXTENSION2( BON::Atom, QoSConstraint, QoSRequiredImpl, QoSRequired );
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
DECLARE_BONEXTENSION( BON::Connection, Bridge2InterconnectImpl, Bridge2Interconnect );
DECLARE_BONEXTENSION( BON::Connection, ComponentConfigPropertyImpl, ComponentConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, ComponentInfoPropertyImpl, ComponentInfoProperty );
DECLARE_BONEXTENSION( BON::Connection, ComponentOperationImpl, ComponentOperation );
DECLARE_BONEXTENSION( BON::Connection, ComponentPropertyImpl, ComponentProperty );
DECLARE_BONEXTENSION( BON::Connection, ConfigPropertyImpl, ConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, DstEdgeImpl, DstEdge );
DECLARE_BONEXTENSION( BON::Connection, EffectImpl, Effect );
DECLARE_BONEXTENSION( BON::Connection, EventSinkDelegateImpl, EventSinkDelegate );
DECLARE_BONEXTENSION( BON::Connection, EventSourceDelegateImpl, EventSourceDelegate );
DECLARE_BONEXTENSION( BON::Connection, ExtResourceConnImpl, ExtResourceConn );
DECLARE_BONEXTENSION( BON::Connection, ExternalDelegateImpl, ExternalDelegate );
DECLARE_BONEXTENSION( BON::Connection, FacetDelegateImpl, FacetDelegate );
DECLARE_BONEXTENSION( BON::Connection, FinishImpl, Finish );
DECLARE_BONEXTENSION( BON::Connection, ImplementationImpl, Implementation );
DECLARE_BONEXTENSION( BON::Connection, ImplementationCapabilityImpl, ImplementationCapability );
DECLARE_BONEXTENSION( BON::Connection, ImplementationDependsOnImpl, ImplementationDependsOn );
DECLARE_BONEXTENSION( BON::Connection, ImplementsImpl, Implements );
DECLARE_BONEXTENSION( BON::Connection, Include_RTEC_Filter_GroupImpl, Include_RTEC_Filter_Group );
DECLARE_BONEXTENSION( BON::Connection, Include_RT_InfoImpl, Include_RT_Info );
DECLARE_BONEXTENSION( BON::Connection, InfoPropertyImpl, InfoProperty );
DECLARE_BONEXTENSION( BON::Connection, InputImpl, Input );
DECLARE_BONEXTENSION( BON::Connection, InstanceMappingImpl, InstanceMapping );
DECLARE_BONEXTENSION( BON::Connection, Interconnect2BridgeImpl, Interconnect2Bridge );
DECLARE_BONEXTENSION( BON::Connection, Interconnect2NodeImpl, Interconnect2Node );
DECLARE_BONEXTENSION( BON::Connection, LabelConnectionImpl, LabelConnection );
DECLARE_BONEXTENSION( BON::Connection, MakeMemberPrivateImpl, MakeMemberPrivate );
DECLARE_BONEXTENSION( BON::Connection, ManagesComponentImpl, ManagesComponent );
DECLARE_BONEXTENSION( BON::Connection, MetricConnectionImpl, MetricConnection );
DECLARE_BONEXTENSION( BON::Connection, MonolithDeployRequirementImpl, MonolithDeployRequirement );
DECLARE_BONEXTENSION( BON::Connection, MonolithExecParameterImpl, MonolithExecParameter );
DECLARE_BONEXTENSION( BON::Connection, MonolithprimaryArtifactImpl, MonolithprimaryArtifact );
DECLARE_BONEXTENSION( BON::Connection, Node2InterconnectImpl, Node2Interconnect );
DECLARE_BONEXTENSION( BON::Connection, PackageConfBasePackageImpl, PackageConfBasePackage );
DECLARE_BONEXTENSION( BON::Connection, PackageConfConfigPropertyImpl, PackageConfConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, PackageConfReferenceImpl, PackageConfReference );
DECLARE_BONEXTENSION( BON::Connection, PackageConfSelectRequirementImpl, PackageConfSelectRequirement );
DECLARE_BONEXTENSION( BON::Connection, PackageConfSpecializedConfigImpl, PackageConfSpecializedConfig );
DECLARE_BONEXTENSION( BON::Connection, PackageConfigPropertyImpl, PackageConfigProperty );
DECLARE_BONEXTENSION( BON::Connection, PackageInfoPropertyImpl, PackageInfoProperty );
DECLARE_BONEXTENSION( BON::Connection, PackageInterfaceImpl, PackageInterface );
DECLARE_BONEXTENSION( BON::Connection, PropertyConnectorImpl, PropertyConnector );
DECLARE_BONEXTENSION( BON::Connection, QoSDecorationImpl, QoSDecoration );
DECLARE_BONEXTENSION( BON::Connection, QoSDimensionQualifierImpl, QoSDimensionQualifier );
DECLARE_BONEXTENSION( BON::Connection, RTEC_ConnectionImpl, RTEC_Connection );
DECLARE_BONEXTENSION( BON::Connection, ReceptacleDelegateImpl, ReceptacleDelegate );
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
DECLARE_BONEXTENSION( BON::Reference, CompRefImpl, CompRef );
DECLARE_BONEXTENSION( BON::Reference, ComponentAssemblyReferenceImpl, ComponentAssemblyReference );
DECLARE_BONEXTENSION( BON::Reference, ComponentImplementationReferenceImpl, ComponentImplementationReference );
DECLARE_BONEXTENSION( BON::Reference, ComponentPackageReferenceImpl, ComponentPackageReference );
DECLARE_BONEXTENSION( BON::Reference, DataTypeImpl, DataType );
DECLARE_BONEXTENSION( BON::Reference, DiscriminatorImpl, Discriminator );
DECLARE_BONEXTENSION( BON::Reference, EventRefImpl, EventRef );
DECLARE_BONEXTENSION( BON::Reference, ExceptionRefImpl, ExceptionRef );
DECLARE_BONEXTENSION( BON::Reference, ExternalResourcesImpl, ExternalResources );
DECLARE_BONEXTENSION( BON::Reference, FileRefImpl, FileRef );
DECLARE_BONEXTENSION( BON::Reference, GetExceptionImpl, GetException );
DECLARE_BONEXTENSION( BON::Reference, ImplementationArtifactReferenceImpl, ImplementationArtifactReference );
DECLARE_BONEXTENSION( BON::Reference, InParameterImpl, InParameter );
DECLARE_BONEXTENSION( BON::Reference, InheritsImpl, Inherits );
DECLARE_BONEXTENSION( BON::Reference, InoutParameterImpl, InoutParameter );
DECLARE_BONEXTENSION( BON::Reference, LookupKeyImpl, LookupKey );
DECLARE_BONEXTENSION( BON::Reference, MemberImpl, Member );
DECLARE_BONEXTENSION( BON::Reference, NodeReferenceImpl, NodeReference );
DECLARE_BONEXTENSION( BON::Reference, OperationRefImpl, OperationRef );
DECLARE_BONEXTENSION( BON::Reference, OutParameterImpl, OutParameter );
DECLARE_BONEXTENSION( BON::Reference, PackageConfigurationReferenceImpl, PackageConfigurationReference );
DECLARE_BONEXTENSION( BON::Reference, PolicySetRefImpl, PolicySetRef );
DECLARE_BONEXTENSION( BON::Reference, QoSCharacteristicRefImpl, QoSCharacteristicRef );
DECLARE_BONEXTENSION( BON::Reference, RTEC_Resource_Factory_ReferenceImpl, RTEC_Resource_Factory_Reference );
DECLARE_BONEXTENSION( BON::Reference, ReturnTypeImpl, ReturnType );
DECLARE_BONEXTENSION( BON::Reference, SetExceptionImpl, SetException );
DECLARE_BONEXTENSION( BON::Reference, SupportsImpl, Supports );
DECLARE_BONEXTENSION( BON::Reference, ThreadPoolRefImpl, ThreadPoolRef );
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
	//********************************************************************************
	// getter for kind "BenchmarkAnalysis"
	//********************************************************************************
	template <class T>
	std::set<BenchmarkAnalysis, T>		getBenchmarkAnalysis(TDP)
	{
		std::set<BenchmarkAnalysis, T> res;
		std::set<BON::Object> kinds = getChildObjects("BenchmarkAnalysis");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			BenchmarkAnalysis elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "MPC"
	//********************************************************************************
	template <class T>
	std::set<MPC, T>		getMPC(TDP)
	{
		std::set<MPC, T> res;
		std::set<BON::Object> kinds = getChildObjects("MPC");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			MPC elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "ComponentImplementationContainer"
	//********************************************************************************
	template <class T>
	std::set<ComponentImplementationContainer, T>		getComponentImplementationContainer(TDP)
	{
		std::set<ComponentImplementationContainer, T> res;
		std::set<BON::Object> kinds = getChildObjects("ComponentImplementationContainer");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			ComponentImplementationContainer elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "PackageContainer"
	//********************************************************************************
	template <class T>
	std::set<PackageContainer, T>		getPackageContainer(TDP)
	{
		std::set<PackageContainer, T> res;
		std::set<BON::Object> kinds = getChildObjects("PackageContainer");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			PackageContainer elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "ComponentContainer"
	//********************************************************************************
	template <class T>
	std::set<ComponentContainer, T>		getComponentContainer(TDP)
	{
		std::set<ComponentContainer, T> res;
		std::set<BON::Object> kinds = getChildObjects("ComponentContainer");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			ComponentContainer elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "DeploymentPlan"
	//********************************************************************************
	template <class T>
	std::set<DeploymentPlan, T>		getDeploymentPlan(TDP)
	{
		std::set<DeploymentPlan, T> res;
		std::set<BON::Object> kinds = getChildObjects("DeploymentPlan");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			DeploymentPlan elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "EventChannelConfiguration"
	//********************************************************************************
	template <class T>
	std::set<EventChannelConfiguration, T>		getEventChannelConfiguration(TDP)
	{
		std::set<EventChannelConfiguration, T> res;
		std::set<BON::Object> kinds = getChildObjects("EventChannelConfiguration");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			EventChannelConfiguration elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "ArtifactContainer"
	//********************************************************************************
	template <class T>
	std::set<ArtifactContainer, T>		getArtifactContainer(TDP)
	{
		std::set<ArtifactContainer, T> res;
		std::set<BON::Object> kinds = getChildObjects("ArtifactContainer");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			ArtifactContainer elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "File"
	//********************************************************************************
	template <class T>
	std::set<File, T>		getFile(TDP)
	{
		std::set<File, T> res;
		std::set<BON::Object> kinds = getChildObjects("File");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			File elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "PackageConfigurationContainer"
	//********************************************************************************
	template <class T>
	std::set<PackageConfigurationContainer, T>		getPackageConfigurationContainer(TDP)
	{
		std::set<PackageConfigurationContainer, T> res;
		std::set<BON::Object> kinds = getChildObjects("PackageConfigurationContainer");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			PackageConfigurationContainer elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PathDiagramImpl
//*******************************************************************
class PathDiagramImpl :
	  public BON::FolderImpl
{
public:
	//
	// kind and subfolder getters
	//********************************************************************************
	// getter for kind "Path"
	//********************************************************************************
	template <class T>
	std::set<Path, T>		getPath(TDP)
	{
		std::set<Path, T> res;
		std::set<BON::Object> kinds = getChildObjects("Path");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			Path elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "Boolean"
	//********************************************************************************
	template <class T>
	std::set<Boolean, T>		getBoolean(TDP)
	{
		std::set<Boolean, T> res;
		std::set<BON::Object> kinds = getChildObjects("Boolean");
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
	template <class T>
	std::set<Byte, T>		getByte(TDP)
	{
		std::set<Byte, T> res;
		std::set<BON::Object> kinds = getChildObjects("Byte");
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
	template <class T>
	std::set<GenericObject, T>		getGenericObject(TDP)
	{
		std::set<GenericObject, T> res;
		std::set<BON::Object> kinds = getChildObjects("GenericObject");
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
	template <class T>
	std::set<GenericValue, T>		getGenericValue(TDP)
	{
		std::set<GenericValue, T> res;
		std::set<BON::Object> kinds = getChildObjects("GenericValue");
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
	template <class T>
	std::set<GenericValueObject, T>		getGenericValueObject(TDP)
	{
		std::set<GenericValueObject, T> res;
		std::set<BON::Object> kinds = getChildObjects("GenericValueObject");
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
	template <class T>
	std::set<LongInteger, T>		getLongInteger(TDP)
	{
		std::set<LongInteger, T> res;
		std::set<BON::Object> kinds = getChildObjects("LongInteger");
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
	template <class T>
	std::set<PredefinedType, T>		getPredefinedType(TDP)
	{
		std::set<PredefinedType, T> res;
		const int len = 11;
		std::set<BON::Object> kinds_vec[ len];
		kinds_vec[0] = getChildObjects("Boolean");
		kinds_vec[1] = getChildObjects("Byte");
		kinds_vec[2] = getChildObjects("GenericObject");
		kinds_vec[3] = getChildObjects("GenericValue");
		kinds_vec[4] = getChildObjects("GenericValueObject");
		kinds_vec[5] = getChildObjects("LongInteger");
		kinds_vec[6] = getChildObjects("RealNumber");
		kinds_vec[7] = getChildObjects("ShortInteger");
		kinds_vec[8] = getChildObjects("String");
		kinds_vec[9] = getChildObjects("TypeEncoding");
		kinds_vec[10] = getChildObjects("TypeKind");
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
	template <class T>
	std::set<RealNumber, T>		getRealNumber(TDP)
	{
		std::set<RealNumber, T> res;
		std::set<BON::Object> kinds = getChildObjects("RealNumber");
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
	template <class T>
	std::set<ShortInteger, T>		getShortInteger(TDP)
	{
		std::set<ShortInteger, T> res;
		std::set<BON::Object> kinds = getChildObjects("ShortInteger");
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
	template <class T>
	std::set<String, T>		getString(TDP)
	{
		std::set<String, T> res;
		std::set<BON::Object> kinds = getChildObjects("String");
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
	template <class T>
	std::set<TypeEncoding, T>		getTypeEncoding(TDP)
	{
		std::set<TypeEncoding, T> res;
		std::set<BON::Object> kinds = getChildObjects("TypeEncoding");
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
	template <class T>
	std::set<TypeKind, T>		getTypeKind(TDP)
	{
		std::set<TypeKind, T> res;
		std::set<BON::Object> kinds = getChildObjects("TypeKind");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			TypeKind elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "CPU"
	//********************************************************************************
	template <class T>
	std::set<CPU, T>		getCPU(TDP)
	{
		std::set<CPU, T> res;
		std::set<BON::Object> kinds = getChildObjects("CPU");
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
	template <class T>
	std::set<Concurrency, T>		getConcurrency(TDP)
	{
		std::set<Concurrency, T> res;
		std::set<BON::Object> kinds = getChildObjects("Concurrency");
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
	template <class T>
	std::set<Connection, T>		getConnection(TDP)
	{
		std::set<Connection, T> res;
		std::set<BON::Object> kinds = getChildObjects("Connection");
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
	template <class T>
	std::set<Process, T>		getProcess(TDP)
	{
		std::set<Process, T> res;
		std::set<BON::Object> kinds = getChildObjects("Process");
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
	template <class T>
	std::set<QoSCategory, T>		getQoSCategory(TDP)
	{
		std::set<QoSCategory, T> res;
		std::set<BON::Object> kinds = getChildObjects("QoSCategory");
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
	template <class T>
	std::set<QoSCharacteristic, T>		getQoSCharacteristic(TDP)
	{
		std::set<QoSCharacteristic, T> res;
		const int len = 5;
		std::set<BON::Object> kinds_vec[ len];
		kinds_vec[0] = getChildObjects("CPU");
		kinds_vec[1] = getChildObjects("Concurrency");
		kinds_vec[2] = getChildObjects("Connection");
		kinds_vec[3] = getChildObjects("Process");
		kinds_vec[4] = getChildObjects("QoSCharacteristic");
		for( int k = 0; k < len; ++k)
			for( std::set<BON::Object>::iterator i = kinds_vec[k].begin(); i != kinds_vec[k].end(); ++i)
			{
				QoSCharacteristic elem(*i);
				ASSERT(elem);
				res.insert(elem);
			}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "Domain"
	//********************************************************************************
	template <class T>
	std::set<Domain, T>		getDomain(TDP)
	{
		std::set<Domain, T> res;
		std::set<BON::Object> kinds = getChildObjects("Domain");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			Domain elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "TopLevelPackageContainer"
	//********************************************************************************
	template <class T>
	std::set<TopLevelPackageContainer, T>		getTopLevelPackageContainer(TDP)
	{
		std::set<TopLevelPackageContainer, T> res;
		std::set<BON::Object> kinds = getChildObjects("TopLevelPackageContainer");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			TopLevelPackageContainer elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for kind "WorkerLibrary"
	//********************************************************************************
	template <class T>
	std::set<WorkerLibrary, T>		getWorkerLibrary(TDP)
	{
		std::set<WorkerLibrary, T> res;
		std::set<BON::Object> kinds = getChildObjects("WorkerLibrary");
		for( std::set<BON::Object>::iterator i = kinds.begin(); i != kinds.end(); ++i)
		{
			WorkerLibrary elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Supports" among "Supports"s
	//********************************************************************************
	template <class T>
	std::set<Supports, T>		getSupports(TDP)
	{
		std::set<Supports, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Supports");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Supports elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
//   C  L  A  S  S   GraphVertexImpl
//*******************************************************************
class GraphVertexImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst Edges
	//********************************************************************************
	template <class T>
	std::multiset<Edge, T>		getDstEdgeDsts(TDP)
	{
		std::multiset<Edge, T> res;
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
	template <class T>
	std::set<SrcEdge, T>		getInSrcEdgeLinks(TDP)
	{
		std::set<SrcEdge, T> result;
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
	template <class T>
	std::set<DstEdge, T>		getOutDstEdgeLinks(TDP)
	{
		std::set<DstEdge, T> result;
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
	template <class T>
	std::multiset<Edge, T>		getSrcEdgeSrcs(TDP)
	{
		std::multiset<Edge, T> res;
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


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InPortImpl
//*******************************************************************
class InPortImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst InputActions
	//********************************************************************************
	template <class T>
	std::multiset<InputAction, T>		getInputDsts(TDP)
	{
		std::multiset<InputAction, T> res;
		{
			std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Input");
			for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
			{
				InputAction dst( *cit );
				ASSERT(dst);
				res.insert( dst);
			}
		}
		return res;
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<Input, T>		getOutInputLinks(TDP)
	{
		std::set<Input, T> result;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<ManagesComponent, T>		getInManagesComponentLinks(TDP)
	{
		std::set<ManagesComponent, T> result;
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
	template <class T>
	std::multiset<ComponentFactory, T>		getManagesComponentSrcs(TDP)
	{
		std::multiset<ComponentFactory, T> res;
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
	//********************************************************************************
	// getter for role "DstEdge" among "DstEdge"s
	//********************************************************************************
	template <class T>
	std::set<DstEdge, T>		getDstEdge(TDP)
	{
		std::set<DstEdge, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("DstEdge");
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
	template <class T>
	std::set<InEventPort, T>		getInEventPort(TDP)
	{
		std::set<InEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InEventPort");
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
	template <class T>
	std::set<OutEventPort, T>		getOutEventPort(TDP)
	{
		std::set<OutEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OutEventPort");
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
	template <class T>
	std::set<Port, T>		getPort(TDP)
	{
		std::set<Port, T> res;
		const int len = 4;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("InEventPort");
		roles_vec[1] = getChildFCOsAs("OutEventPort");
		roles_vec[2] = getChildFCOsAs("ProvidedRequestPort");
		roles_vec[3] = getChildFCOsAs("RequiredRequestPort");
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
	template <class T>
	std::set<ProvidedRequestPort, T>		getProvidedRequestPort(TDP)
	{
		std::set<ProvidedRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ProvidedRequestPort");
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
	template <class T>
	std::set<RequiredRequestPort, T>		getRequiredRequestPort(TDP)
	{
		std::set<RequiredRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RequiredRequestPort");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			RequiredRequestPort elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Member" among "Member"s
	//********************************************************************************
	template <class T>
	std::set<Member, T>		getMember(TDP)
	{
		std::set<Member, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Member");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Member elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Aggregate" among "NamedType"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Aggregate, T>		getAggregate(TDP)
	{
		std::set<Aggregate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Aggregate");
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
	template <class T>
	std::set<Alias, T>		getAlias(TDP)
	{
		std::set<Alias, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Alias");
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
	template <class T>
	std::set<Boxed, T>		getBoxed(TDP)
	{
		std::set<Boxed, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Boxed");
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
	template <class T>
	std::set<Collection, T>		getCollection(TDP)
	{
		std::set<Collection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Collection");
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
	template <class T>
	std::set<Component, T>		getComponent(TDP)
	{
		std::set<Component, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Component");
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
	template <class T>
	std::set<ComponentFactory, T>		getComponentFactory(TDP)
	{
		std::set<ComponentFactory, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentFactory");
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
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<Constant, T>		getConstant(TDP)
	{
		std::set<Constant, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Constant");
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
	template <class T>
	std::set<Enum, T>		getEnum(TDP)
	{
		std::set<Enum, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Enum");
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
	template <class T>
	std::set<Event, T>		getEvent(TDP)
	{
		std::set<Event, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Event");
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
	template <class T>
	std::set<Exception, T>		getException(TDP)
	{
		std::set<Exception, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Exception");
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
	template <class T>
	std::set<FileRef, T>		getFileRef(TDP)
	{
		std::set<FileRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FileRef");
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
	template <class T>
	std::set<ManagesComponent, T>		getManagesComponent(TDP)
	{
		std::set<ManagesComponent, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ManagesComponent");
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
	template <class T>
	std::set<NamedType, T>		getNamedType(TDP)
	{
		std::set<NamedType, T> res;
		const int len = 11;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Aggregate");
		roles_vec[1] = getChildFCOsAs("Component");
		roles_vec[2] = getChildFCOsAs("ComponentFactory");
		roles_vec[3] = getChildFCOsAs("Enum");
		roles_vec[4] = getChildFCOsAs("Event");
		roles_vec[5] = getChildFCOsAs("Object");
		roles_vec[6] = getChildFCOsAs("SwitchedAggregate");
		roles_vec[7] = getChildFCOsAs("ValueObject");
		roles_vec[8] = getChildFCOsAs("Alias");
		roles_vec[9] = getChildFCOsAs("Boxed");
		roles_vec[10] = getChildFCOsAs("Collection");
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
	template <class T>
	std::set<Object, T>		getObject(TDP)
	{
		std::set<Object, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Object");
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
	template <class T>
	std::set<Package, T>		getPackage(TDP)
	{
		std::set<Package, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Package");
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
	template <class T>
	std::set<SwitchedAggregate, T>		getSwitchedAggregate(TDP)
	{
		std::set<SwitchedAggregate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SwitchedAggregate");
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
	template <class T>
	std::set<ValueObject, T>		getValueObject(TDP)
	{
		std::set<ValueObject, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ValueObject");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ValueObject elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "InParameter" among "InParameter"s
	//********************************************************************************
	template <class T>
	std::set<InParameter, T>		getInParameter(TDP)
	{
		std::set<InParameter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InParameter");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			InParameter elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Aggregate" among "NamedType"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Aggregate, T>		getAggregate(TDP)
	{
		std::set<Aggregate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Aggregate");
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
	template <class T>
	std::set<Alias, T>		getAlias(TDP)
	{
		std::set<Alias, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Alias");
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
	template <class T>
	std::set<Boxed, T>		getBoxed(TDP)
	{
		std::set<Boxed, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Boxed");
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
	template <class T>
	std::set<Collection, T>		getCollection(TDP)
	{
		std::set<Collection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Collection");
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
	template <class T>
	std::set<Component, T>		getComponent(TDP)
	{
		std::set<Component, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Component");
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
	template <class T>
	std::set<ComponentFactory, T>		getComponentFactory(TDP)
	{
		std::set<ComponentFactory, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentFactory");
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
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<Constant, T>		getConstant(TDP)
	{
		std::set<Constant, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Constant");
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
	template <class T>
	std::set<Enum, T>		getEnum(TDP)
	{
		std::set<Enum, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Enum");
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
	template <class T>
	std::set<Event, T>		getEvent(TDP)
	{
		std::set<Event, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Event");
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
	template <class T>
	std::set<Exception, T>		getException(TDP)
	{
		std::set<Exception, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Exception");
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
	template <class T>
	std::set<ManagesComponent, T>		getManagesComponent(TDP)
	{
		std::set<ManagesComponent, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ManagesComponent");
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
	template <class T>
	std::set<NamedType, T>		getNamedType(TDP)
	{
		std::set<NamedType, T> res;
		const int len = 11;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Aggregate");
		roles_vec[1] = getChildFCOsAs("Component");
		roles_vec[2] = getChildFCOsAs("ComponentFactory");
		roles_vec[3] = getChildFCOsAs("Enum");
		roles_vec[4] = getChildFCOsAs("Event");
		roles_vec[5] = getChildFCOsAs("Object");
		roles_vec[6] = getChildFCOsAs("SwitchedAggregate");
		roles_vec[7] = getChildFCOsAs("ValueObject");
		roles_vec[8] = getChildFCOsAs("Alias");
		roles_vec[9] = getChildFCOsAs("Boxed");
		roles_vec[10] = getChildFCOsAs("Collection");
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
	template <class T>
	std::set<Object, T>		getObject(TDP)
	{
		std::set<Object, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Object");
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
	template <class T>
	std::set<Package, T>		getPackage(TDP)
	{
		std::set<Package, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Package");
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
	template <class T>
	std::set<SwitchedAggregate, T>		getSwitchedAggregate(TDP)
	{
		std::set<SwitchedAggregate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SwitchedAggregate");
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
	template <class T>
	std::set<ValueObject, T>		getValueObject(TDP)
	{
		std::set<ValueObject, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ValueObject");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ValueObject elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns src AttributeMappings and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getAttributeDelegateSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("AttributeDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns dst Propertys
	//********************************************************************************
	template <class T>
	std::multiset<Property, T>		getAttributeValueDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::set<AttributeDelegate, T>		getInAttributeDelegateLinks(TDP)
	{
		std::set<AttributeDelegate, T> result;
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
	template <class T>
	std::set<AttributeValue, T>		getOutAttributeValueLinks(TDP)
	{
		std::set<AttributeValue, T> result;
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

	//
	// kind and role getters
	//********************************************************************************
	// getter for role "AttributeMember" among "AttributeMember"s
	//********************************************************************************
	template <class T>
	std::set<AttributeMember, T>		getAttributeMember(TDP)
	{
		std::set<AttributeMember, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AttributeMember");
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
	template <class T>
	std::set<GetException, T>		getGetException(TDP)
	{
		std::set<GetException, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("GetException");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			GetException elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	  public TaggableImpl
	, public GraphVertexImpl
	, public CommonPortAttrsImpl
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
	, public InPortImpl
{
public:


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentRefImpl
//*******************************************************************
class ComponentRefImpl :
	  virtual public BON::ReferenceImpl
	, public ManageableImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst Propertys
	//********************************************************************************
	template <class T>
	std::multiset<Property, T>		getComponentConfigPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<Property, T>		getComponentInfoPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<ComponentPropertyDescription, T>		getComponentPropertyDsts(TDP)
	{
		std::multiset<ComponentPropertyDescription, T> res;
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
	template <class T>
	std::multiset<ComponentImplementation, T>		getImplementsSrcs(TDP)
	{
		std::multiset<ComponentImplementation, T> res;
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
	template <class T>
	std::set<Implements, T>		getInImplementsLinks(TDP)
	{
		std::set<Implements, T> result;
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
	template <class T>
	std::set<PackageInterface, T>		getInPackageInterfaceLinks(TDP)
	{
		std::set<PackageInterface, T> result;
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
	template <class T>
	std::set<ComponentConfigProperty, T>		getOutComponentConfigPropertyLinks(TDP)
	{
		std::set<ComponentConfigProperty, T> result;
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
	template <class T>
	std::set<ComponentInfoProperty, T>		getOutComponentInfoPropertyLinks(TDP)
	{
		std::set<ComponentInfoProperty, T> result;
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
	template <class T>
	std::set<ComponentProperty, T>		getOutComponentPropertyLinks(TDP)
	{
		std::set<ComponentProperty, T> result;
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
	template <class T>
	std::multiset<ComponentPackage, T>		getPackageInterfaceSrcs(TDP)
	{
		std::multiset<ComponentPackage, T> res;
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
	//********************************************************************************
	// getter for role "SetException" among "SetException"s
	//********************************************************************************
	template <class T>
	std::set<SetException, T>		getSetException(TDP)
	{
		std::set<SetException, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SetException");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			SetException elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns dst Propertys
	//********************************************************************************
	template <class T>
	std::multiset<Property, T>		getAssemblyConfigPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<Requirement, T>		getAssemblyselectRequirementDsts(TDP)
	{
		std::multiset<Requirement, T> res;
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
	template <class T>
	std::multiset<ExternalReferenceEndPoint, T>		getExternalDelegateDsts(TDP)
	{
		std::multiset<ExternalReferenceEndPoint, T> res;
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
	template <class T>
	std::set<QoSDecoration, T>		getInQoSDecorationLinks(TDP)
	{
		std::set<QoSDecoration, T> result;
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
	template <class T>
	std::set<AssemblyConfigProperty, T>		getOutAssemblyConfigPropertyLinks(TDP)
	{
		std::set<AssemblyConfigProperty, T> result;
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
	template <class T>
	std::set<AssemblyselectRequirement, T>		getOutAssemblyselectRequirementLinks(TDP)
	{
		std::set<AssemblyselectRequirement, T> result;
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
	template <class T>
	std::set<ExternalDelegate, T>		getOutExternalDelegateLinks(TDP)
	{
		std::set<ExternalDelegate, T> result;
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
	template <class T>
	std::multiset<QoSValue, T>		getQoSDecorationSrcs(TDP)
	{
		std::multiset<QoSValue, T> res;
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

	//
	// attribute getters and setters
	virtual std::string getUUID() ;
	virtual std::string getlabel() ;
	virtual void        setUUID( const std::string& val);
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "Action" among "ActionBase"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Action, T>		getAction(TDP)
	{
		std::set<Action, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Action");
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
	template <class T>
	std::set<ActionBase, T>		getActionBase(TDP)
	{
		std::set<ActionBase, T> res;
		const int len = 5;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Action");
		roles_vec[1] = getChildFCOsAs("InputAction");
		roles_vec[2] = getChildFCOsAs("OutputAction");
		roles_vec[3] = getChildFCOsAs("PeriodicAction");
		roles_vec[4] = getChildFCOsAs("WorkerAction");
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
	template <class T>
	std::set<Attribute, T>		getAttribute(TDP)
	{
		std::set<Attribute, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Attribute");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Attribute elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "Effect" among "Effect"s
	//********************************************************************************
	template <class T>
	std::set<Effect, T>		getEffect(TDP)
	{
		std::set<Effect, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Effect");
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
	template <class T>
	std::set<Environment, T>		getEnvironment(TDP)
	{
		std::set<Environment, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Environment");
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
	template <class T>
	std::set<Finish, T>		getFinish(TDP)
	{
		std::set<Finish, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Finish");
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
	template <class T>
	std::set<InEventPort, T>		getInEventPort(TDP)
	{
		std::set<InEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InEventPort");
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
	template <class T>
	std::set<Input, T>		getInput(TDP)
	{
		std::set<Input, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Input");
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
	template <class T>
	std::set<InputAction, T>		getInputAction(TDP)
	{
		std::set<InputAction, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InputAction");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			InputAction elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "OutEventPort" among "Port"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<OutEventPort, T>		getOutEventPort(TDP)
	{
		std::set<OutEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OutEventPort");
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
	template <class T>
	std::set<OutputAction, T>		getOutputAction(TDP)
	{
		std::set<OutputAction, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OutputAction");
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
	template <class T>
	std::set<PeriodicAction, T>		getPeriodicAction(TDP)
	{
		std::set<PeriodicAction, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PeriodicAction");
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
	template <class T>
	std::set<Port, T>		getPort(TDP)
	{
		std::set<Port, T> res;
		const int len = 4;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("InEventPort");
		roles_vec[1] = getChildFCOsAs("OutEventPort");
		roles_vec[2] = getChildFCOsAs("ProvidedRequestPort");
		roles_vec[3] = getChildFCOsAs("RequiredRequestPort");
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
	template <class T>
	std::set<ProvidedRequestPort, T>		getProvidedRequestPort(TDP)
	{
		std::set<ProvidedRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ProvidedRequestPort");
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
	template <class T>
	std::set<ReadonlyAttribute, T>		getReadonlyAttribute(TDP)
	{
		std::set<ReadonlyAttribute, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ReadonlyAttribute");
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
	template <class T>
	std::set<ReadonlyAttribute, T>		getReadonlyAttribute(int dummy, TDP)
	{
		std::set<ReadonlyAttribute, T> res;
		const int len = 2;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Attribute");
		roles_vec[1] = getChildFCOsAs("ReadonlyAttribute");
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
	template <class T>
	std::set<RequiredRequestPort, T>		getRequiredRequestPort(TDP)
	{
		std::set<RequiredRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RequiredRequestPort");
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
	template <class T>
	std::set<State, T>		getState(TDP)
	{
		std::set<State, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("State");
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
	template <class T>
	std::set<Transition, T>		getTransition(TDP)
	{
		std::set<Transition, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Transition");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Transition elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "WorkerAction" among "ActionBase"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<WorkerAction, T>		getWorkerAction(TDP)
	{
		std::set<WorkerAction, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("WorkerAction");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			WorkerAction elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "WorkerType" among "WorkerType"s
	//********************************************************************************
	template <class T>
	std::set<WorkerType, T>		getWorkerType(TDP)
	{
		std::set<WorkerType, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("WorkerType");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			WorkerType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ExceptionRef" among "ExceptionRef"s
	//********************************************************************************
	template <class T>
	std::set<ExceptionRef, T>		getExceptionRef(TDP)
	{
		std::set<ExceptionRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ExceptionRef");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ExceptionRef elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Attribute" among "ReadonlyAttribute"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Attribute, T>		getAttribute(TDP)
	{
		std::set<Attribute, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Attribute");
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
	template <class T>
	std::set<Inherits, T>		getInherits(TDP)
	{
		std::set<Inherits, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Inherits");
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
	template <class T>
	std::set<ReadonlyAttribute, T>		getReadonlyAttribute(TDP)
	{
		std::set<ReadonlyAttribute, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ReadonlyAttribute");
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
	template <class T>
	std::set<ReadonlyAttribute, T>		getReadonlyAttribute(int dummy, TDP)
	{
		std::set<ReadonlyAttribute, T> res;
		const int len = 2;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Attribute");
		roles_vec[1] = getChildFCOsAs("ReadonlyAttribute");
		for( int k = 0; k < len; ++k)
			for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
			{
				ReadonlyAttribute elem(*i);
				ASSERT(elem);
				res.insert(elem);
			}
		return res;
	}


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
	, public PredefinedTypeImpl
	, public ProvideableImpl
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
	, public InPortImpl
	, public PortImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst InEventPorts and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getEventSinkDelegateDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("EventSinkDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<EventSinkDelegate, T>		getEventSinkDelegateLinks(TDP)
	{
		std::set<EventSinkDelegate, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getEventSinkDelegateSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("EventSinkDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<EventSinkDelegate, T>		getInEventSinkDelegateLinks(TDP)
	{
		std::set<EventSinkDelegate, T> result;
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
	template <class T>
	std::set<Use_RTEC_Filter, T>		getInUse_RTEC_FilterLinks(TDP)
	{
		std::set<Use_RTEC_Filter, T> result;
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
	template <class T>
	std::set<deliverTo, T>		getIndeliverToLinks(TDP)
	{
		std::set<deliverTo, T> result;
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
	template <class T>
	std::set<emit, T>		getInemitLinks(TDP)
	{
		std::set<emit, T> result;
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
	// 
	//********************************************************************************
	template <class T>
	std::set<EventSinkDelegate, T>		getOutEventSinkDelegateLinks(TDP)
	{
		std::set<EventSinkDelegate, T> result;
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
	// returns src RTEC_Filter_Groups
	//********************************************************************************
	template <class T>
	std::multiset<RTEC_Filter_Group, T>		getUse_RTEC_FilterSrcs(TDP)
	{
		std::multiset<RTEC_Filter_Group, T> res;
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
	template <class T>
	std::multiset<PublishConnector, T>		getdeliverToSrcs(TDP)
	{
		std::multiset<PublishConnector, T> res;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getemitSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("emit");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

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
	//********************************************************************************
	// returns dst OutEventPorts and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getEventSourceDelegateDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("EventSourceDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<EventSourceDelegate, T>		getEventSourceDelegateLinks(TDP)
	{
		std::set<EventSourceDelegate, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getEventSourceDelegateSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("EventSourceDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<EventSourceDelegate, T>		getInEventSourceDelegateLinks(TDP)
	{
		std::set<EventSourceDelegate, T> result;
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
	template <class T>
	std::set<EventSourceDelegate, T>		getOutEventSourceDelegateLinks(TDP)
	{
		std::set<EventSourceDelegate, T> result;
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
	template <class T>
	std::set<RTEC_Connection, T>		getOutRTEC_ConnectionLinks(TDP)
	{
		std::set<RTEC_Connection, T> result;
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
	template <class T>
	std::set<emit, T>		getOutemitLinks(TDP)
	{
		std::set<emit, T> result;
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
	template <class T>
	std::set<publish, T>		getOutpublishLinks(TDP)
	{
		std::set<publish, T> result;
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
	template <class T>
	std::multiset<RT_Info_Param, T>		getRTEC_ConnectionDsts(TDP)
	{
		std::multiset<RT_Info_Param, T> res;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getemitDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("emit");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns dst PublishConnectors
	//********************************************************************************
	template <class T>
	std::multiset<PublishConnector, T>		getpublishDsts(TDP)
	{
		std::multiset<PublishConnector, T> res;
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
	, public InPortImpl
	, public PortImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst ProvidedRequestPorts and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getFacetDelegateDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("FacetDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<FacetDelegate, T>		getFacetDelegateLinks(TDP)
	{
		std::set<FacetDelegate, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getFacetDelegateSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("FacetDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<FacetDelegate, T>		getInFacetDelegateLinks(TDP)
	{
		std::set<FacetDelegate, T> result;
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
	template <class T>
	std::set<invoke, T>		getIninvokeLinks(TDP)
	{
		std::set<invoke, T> result;
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
	template <class T>
	std::set<FacetDelegate, T>		getOutFacetDelegateLinks(TDP)
	{
		std::set<FacetDelegate, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getinvokeSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("invoke");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<ReceptacleDelegate, T>		getInReceptacleDelegateLinks(TDP)
	{
		std::set<ReceptacleDelegate, T> result;
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
	template <class T>
	std::set<ReceptacleDelegate, T>		getOutReceptacleDelegateLinks(TDP)
	{
		std::set<ReceptacleDelegate, T> result;
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
	template <class T>
	std::set<invoke, T>		getOutinvokeLinks(TDP)
	{
		std::set<invoke, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getReceptacleDelegateDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("ReceptacleDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<ReceptacleDelegate, T>		getReceptacleDelegateLinks(TDP)
	{
		std::set<ReceptacleDelegate, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getReceptacleDelegateSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("ReceptacleDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns dst ProvidedRequestPorts and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getinvokeDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("invoke");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

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
	//********************************************************************************
	// getter for role "Member" among "Member"s
	//********************************************************************************
	template <class T>
	std::set<Member, T>		getMember(TDP)
	{
		std::set<Member, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Member");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Member elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "EnumValue" among "EnumValue"s
	//********************************************************************************
	template <class T>
	std::set<EnumValue, T>		getEnumValue(TDP)
	{
		std::set<EnumValue, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("EnumValue");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			EnumValue elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Aggregate" among "NoInheritable"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Aggregate, T>		getAggregate(TDP)
	{
		std::set<Aggregate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Aggregate");
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
	template <class T>
	std::set<Alias, T>		getAlias(TDP)
	{
		std::set<Alias, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Alias");
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
	template <class T>
	std::set<Collection, T>		getCollection(TDP)
	{
		std::set<Collection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Collection");
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
	template <class T>
	std::set<Constant, T>		getConstant(TDP)
	{
		std::set<Constant, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Constant");
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
	template <class T>
	std::set<Enum, T>		getEnum(TDP)
	{
		std::set<Enum, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Enum");
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
	template <class T>
	std::set<Exception, T>		getException(TDP)
	{
		std::set<Exception, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Exception");
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
	template <class T>
	std::set<NoInheritable, T>		getNoInheritable(TDP)
	{
		std::set<NoInheritable, T> res;
		const int len = 5;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Aggregate");
		roles_vec[1] = getChildFCOsAs("Enum");
		roles_vec[2] = getChildFCOsAs("SwitchedAggregate");
		roles_vec[3] = getChildFCOsAs("Alias");
		roles_vec[4] = getChildFCOsAs("Collection");
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
	template <class T>
	std::set<OnewayOperation, T>		getOnewayOperation(TDP)
	{
		std::set<OnewayOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OnewayOperation");
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
	template <class T>
	std::set<SwitchedAggregate, T>		getSwitchedAggregate(TDP)
	{
		std::set<SwitchedAggregate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SwitchedAggregate");
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
	template <class T>
	std::set<TwowayOperation, T>		getTwowayOperation(TDP)
	{
		std::set<TwowayOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TwowayOperation");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			TwowayOperation elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Discriminator" among "Discriminator"s
	//********************************************************************************
	template <class T>
	std::set<Discriminator, T>		getDiscriminator(TDP)
	{
		std::set<Discriminator, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Discriminator");
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
	template <class T>
	std::set<Label, T>		getLabel(TDP)
	{
		std::set<Label, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Label");
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
	template <class T>
	std::set<LabelConnection, T>		getLabelConnection(TDP)
	{
		std::set<LabelConnection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("LabelConnection");
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
	template <class T>
	std::set<Member, T>		getMember(TDP)
	{
		std::set<Member, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Member");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Member elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "InoutParameter" among "InoutParameter"s
	//********************************************************************************
	template <class T>
	std::set<InoutParameter, T>		getInoutParameter(TDP)
	{
		std::set<InoutParameter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InoutParameter");
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
	template <class T>
	std::set<OutParameter, T>		getOutParameter(TDP)
	{
		std::set<OutParameter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OutParameter");
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
	template <class T>
	std::set<ReturnType, T>		getReturnType(TDP)
	{
		std::set<ReturnType, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ReturnType");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ReturnType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	  public SupportsInterfacesImpl
	, public HasOperationsImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst Manageables
	//********************************************************************************
	template <class T>
	std::multiset<Manageable, T>		getManagesComponentDsts(TDP)
	{
		std::multiset<Manageable, T> res;
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
	template <class T>
	std::set<ManagesComponent, T>		getOutManagesComponentLinks(TDP)
	{
		std::set<ManagesComponent, T> result;
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

	//
	// kind and role getters
	//********************************************************************************
	// getter for role "FactoryOperation" among "FactoryOperation"s
	//********************************************************************************
	template <class T>
	std::set<FactoryOperation, T>		getFactoryOperation(TDP)
	{
		std::set<FactoryOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FactoryOperation");
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
	template <class T>
	std::set<LookupKey, T>		getLookupKey(TDP)
	{
		std::set<LookupKey, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("LookupKey");
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
	template <class T>
	std::set<LookupOperation, T>		getLookupOperation(TDP)
	{
		std::set<LookupOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("LookupOperation");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			LookupOperation elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ObjectImpl
//*******************************************************************
class ObjectImpl :
	  public HasOperationsImpl
	, public PrefixableImpl
	, public ProvideableImpl
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
	  public SupportsInterfacesImpl
	, public HasOperationsImpl
	, public PrefixableImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isabstract() ;
	virtual void        setabstract( bool val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "FactoryOperation" among "FactoryOperation"s
	//********************************************************************************
	template <class T>
	std::set<FactoryOperation, T>		getFactoryOperation(TDP)
	{
		std::set<FactoryOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FactoryOperation");
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
	template <class T>
	std::set<MakeMemberPrivate, T>		getMakeMemberPrivate(TDP)
	{
		std::set<MakeMemberPrivate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("MakeMemberPrivate");
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
	template <class T>
	std::set<Member, T>		getMember(TDP)
	{
		std::set<Member, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Member");
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
	template <class T>
	std::set<PrivateFlag, T>		getPrivateFlag(TDP)
	{
		std::set<PrivateFlag, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PrivateFlag");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			PrivateFlag elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
//   C  L  A  S  S   ActionBaseImpl
//*******************************************************************
class ActionBaseImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst States
	//********************************************************************************
	template <class T>
	std::multiset<State, T>		getEffectDsts(TDP)
	{
		std::multiset<State, T> res;
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
	template <class T>
	std::set<Transition, T>		getInTransitionLinks(TDP)
	{
		std::set<Transition, T> result;
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
	template <class T>
	std::set<Effect, T>		getOutEffectLinks(TDP)
	{
		std::set<Effect, T> result;
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
	template <class T>
	std::multiset<State, T>		getTransitionSrcs(TDP)
	{
		std::multiset<State, T> res;
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

	//
	// kind and role getters
	//********************************************************************************
	// getter for role "Property" among "Property"s
	//********************************************************************************
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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

	//
	// attribute getters and setters
	virtual long        getRepetitions() ;
	virtual void        setRepetitions( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   InputActionImpl
//*******************************************************************
class InputActionImpl :
	  public ActionBaseImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns src States
	//********************************************************************************
	template <class T>
	std::multiset<State, T>		getFinishSrcs(TDP)
	{
		std::multiset<State, T> res;
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
	template <class T>
	std::set<Finish, T>		getInFinishLinks(TDP)
	{
		std::set<Finish, T> result;
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
	template <class T>
	std::set<Input, T>		getInInputLinks(TDP)
	{
		std::set<Input, T> result;
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
	// returns src InPorts
	//********************************************************************************
	template <class T>
	std::multiset<InPort, T>		getInputSrcs(TDP)
	{
		std::multiset<InPort, T> res;
		{
			std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Input");
			for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
			{
				InPort dst( *cit );
				ASSERT(dst);
				res.insert( dst);
			}
		}
		return res;
	}


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   OutputActionImpl
//*******************************************************************
class OutputActionImpl :
	  public ActionBaseImpl
{
public:

	//
	// attribute getters and setters
	virtual long        getRepetitions() ;
	virtual void        setRepetitions( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   PeriodicActionImpl
//*******************************************************************
class PeriodicActionImpl :
	  public InputActionImpl
{
public:

	//
	// attribute getters and setters
	virtual long        getPeriod() ;
	virtual void        setPeriod( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerActionImpl
//*******************************************************************
class WorkerActionImpl :
	  public ActionImpl
{
public:

	//
	// attribute getters and setters
	virtual bool        isLogAction() ;
	virtual void        setLogAction( bool val);

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
	//********************************************************************************
	// getter for role "Null_RT_Info" among "RT_Info_Param"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Null_RT_Info, T>		getNull_RT_Info(TDP)
	{
		std::set<Null_RT_Info, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Null_RT_Info");
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
	template <class T>
	std::set<RT_Info, T>		getRT_Info(TDP)
	{
		std::set<RT_Info, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RT_Info");
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
	template <class T>
	std::set<RT_Info_Param, T>		getRT_Info_Param(TDP)
	{
		std::set<RT_Info_Param, T> res;
		const int len = 2;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Null_RT_Info");
		roles_vec[1] = getChildFCOsAs("RT_Info");
		for( int k = 0; k < len; ++k)
			for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
			{
				RT_Info_Param elem(*i);
				ASSERT(elem);
				res.insert(elem);
			}
		return res;
	}


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
	//********************************************************************************
	// getter for role "RTEC_Resource_Factory_Reference" among "RTEC_Resource_Factory_Reference"s
	//********************************************************************************
	template <class T>
	std::set<RTEC_Resource_Factory_Reference, T>		getRTEC_Resource_Factory_Reference(TDP)
	{
		std::set<RTEC_Resource_Factory_Reference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RTEC_Resource_Factory_Reference");
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
	template <class T>
	std::set<Use_RT_Info, T>		getUse_RT_Info(TDP)
	{
		std::set<Use_RT_Info, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Use_RT_Info");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Use_RT_Info elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   RTEC_Proxy_SupplierImpl
//*******************************************************************
class RTEC_Proxy_SupplierImpl :
	  public RTEC_ProxyImpl
	, public Proxy_SupplierImpl
{
public:

	//
	// kind and role getters
	//********************************************************************************
	// getter for role "ConjunctionGroup" among "RTEC_Filter_Group"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<ConjunctionGroup, T>		getConjunctionGroup(TDP)
	{
		std::set<ConjunctionGroup, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ConjunctionGroup");
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
	template <class T>
	std::set<DisjunctionGroup, T>		getDisjunctionGroup(TDP)
	{
		std::set<DisjunctionGroup, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("DisjunctionGroup");
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
	template <class T>
	std::set<Include_RTEC_Filter_Group, T>		getInclude_RTEC_Filter_Group(TDP)
	{
		std::set<Include_RTEC_Filter_Group, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Include_RTEC_Filter_Group");
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
	template <class T>
	std::set<Include_RT_Info, T>		getInclude_RT_Info(TDP)
	{
		std::set<Include_RT_Info, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Include_RT_Info");
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
	template <class T>
	std::set<LogicalANDGroup, T>		getLogicalANDGroup(TDP)
	{
		std::set<LogicalANDGroup, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("LogicalANDGroup");
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
	template <class T>
	std::set<RTEC_Filter_Group, T>		getRTEC_Filter_Group(TDP)
	{
		std::set<RTEC_Filter_Group, T> res;
		const int len = 3;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("ConjunctionGroup");
		roles_vec[1] = getChildFCOsAs("DisjunctionGroup");
		roles_vec[2] = getChildFCOsAs("LogicalANDGroup");
		for( int k = 0; k < len; ++k)
			for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
			{
				RTEC_Filter_Group elem(*i);
				ASSERT(elem);
				res.insert(elem);
			}
		return res;
	}


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
	//********************************************************************************
	// getter for role "QoSCharacteristicRef" among "QoSCharacteristicRef"s
	//********************************************************************************
	template <class T>
	std::set<QoSCharacteristicRef, T>		getQoSCharacteristicRef(TDP)
	{
		std::set<QoSCharacteristicRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSCharacteristicRef");
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
	template <class T>
	std::set<QoSDimension, T>		getQoSDimension(TDP)
	{
		std::set<QoSDimension, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSDimension");
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
	template <class T>
	std::set<QoSParameter, T>		getQoSParameter(TDP)
	{
		std::set<QoSParameter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSParameter");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			QoSParameter elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns dst Interconnects
	//********************************************************************************
	template <class T>
	std::multiset<Interconnect, T>		getBridge2InterconnectDsts(TDP)
	{
		std::multiset<Interconnect, T> res;
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
	template <class T>
	std::set<Interconnect2Bridge, T>		getInInterconnect2BridgeLinks(TDP)
	{
		std::set<Interconnect2Bridge, T> result;
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
	template <class T>
	std::multiset<Interconnect, T>		getInterconnect2BridgeSrcs(TDP)
	{
		std::multiset<Interconnect, T> res;
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
	template <class T>
	std::set<Bridge2Interconnect, T>		getOutBridge2InterconnectLinks(TDP)
	{
		std::set<Bridge2Interconnect, T> result;
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

	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "Resource" among "Resource"s
	//********************************************************************************
	template <class T>
	std::set<Resource, T>		getResource(TDP)
	{
		std::set<Resource, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Resource");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Resource elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns src Bridges
	//********************************************************************************
	template <class T>
	std::multiset<Bridge, T>		getBridge2InterconnectSrcs(TDP)
	{
		std::multiset<Bridge, T> res;
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
	template <class T>
	std::set<Bridge2Interconnect, T>		getInBridge2InterconnectLinks(TDP)
	{
		std::set<Bridge2Interconnect, T> result;
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
	template <class T>
	std::set<Node2Interconnect, T>		getInNode2InterconnectLinks(TDP)
	{
		std::set<Node2Interconnect, T> result;
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
	template <class T>
	std::multiset<Bridge, T>		getInterconnect2BridgeDsts(TDP)
	{
		std::multiset<Bridge, T> res;
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
	template <class T>
	std::multiset<Node, T>		getInterconnect2NodeDsts(TDP)
	{
		std::multiset<Node, T> res;
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
	template <class T>
	std::multiset<Node, T>		getNode2InterconnectSrcs(TDP)
	{
		std::multiset<Node, T> res;
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
	template <class T>
	std::set<Interconnect2Bridge, T>		getOutInterconnect2BridgeLinks(TDP)
	{
		std::set<Interconnect2Bridge, T> result;
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
	template <class T>
	std::set<Interconnect2Node, T>		getOutInterconnect2NodeLinks(TDP)
	{
		std::set<Interconnect2Node, T> result;
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

	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "Resource" among "Resource"s
	//********************************************************************************
	template <class T>
	std::set<Resource, T>		getResource(TDP)
	{
		std::set<Resource, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Resource");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Resource elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<Interconnect2Node, T>		getInInterconnect2NodeLinks(TDP)
	{
		std::set<Interconnect2Node, T> result;
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
	template <class T>
	std::multiset<Interconnect, T>		getInterconnect2NodeSrcs(TDP)
	{
		std::multiset<Interconnect, T> res;
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
	template <class T>
	std::multiset<Interconnect, T>		getNode2InterconnectDsts(TDP)
	{
		std::multiset<Interconnect, T> res;
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
	template <class T>
	std::set<Node2Interconnect, T>		getOutNode2InterconnectLinks(TDP)
	{
		std::set<Node2Interconnect, T> result;
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
	template <class T>
	std::set<Shares, T>		getOutSharesLinks(TDP)
	{
		std::set<Shares, T> result;
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
	template <class T>
	std::multiset<SharedResource, T>		getSharesDsts(TDP)
	{
		std::multiset<SharedResource, T> res;
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

	//
	// attribute getters and setters
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "Resource" among "Resource"s
	//********************************************************************************
	template <class T>
	std::set<Resource, T>		getResource(TDP)
	{
		std::set<Resource, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Resource");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Resource elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SharedResourceImpl
//*******************************************************************
class SharedResourceImpl :
	  virtual public BON::ModelImpl
	, public ElementsImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<Shares, T>		getInSharesLinks(TDP)
	{
		std::set<Shares, T> result;
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
	template <class T>
	std::multiset<Node, T>		getSharesSrcs(TDP)
	{
		std::multiset<Node, T> res;
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

	//
	// attribute getters and setters
	virtual std::string getresourceType() ;
	virtual void        setresourceType( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "SatisfierProperty" among "SatisfierProperty"s
	//********************************************************************************
	template <class T>
	std::set<SatisfierProperty, T>		getSatisfierProperty(TDP)
	{
		std::set<SatisfierProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SatisfierProperty");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			SatisfierProperty elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns dst ExternalResourcess
	//********************************************************************************
	template <class T>
	std::multiset<ExternalResources, T>		getExtResourceConnDsts(TDP)
	{
		std::multiset<ExternalResources, T> res;
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
	template <class T>
	std::set<ExtResourceConn, T>		getOutExtResourceConnLinks(TDP)
	{
		std::set<ExtResourceConn, T> result;
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
	//********************************************************************************
	// getter for role "ImplementationArtifactReference" among "ImplementationArtifactReference"s
	//********************************************************************************
	template <class T>
	std::set<ImplementationArtifactReference, T>		getImplementationArtifactReference(TDP)
	{
		std::set<ImplementationArtifactReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationArtifactReference");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ImplementationArtifactReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "FileRef" among "FileRef"s
	//********************************************************************************
	template <class T>
	std::set<FileRef, T>		getFileRef(TDP)
	{
		std::set<FileRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FileRef");
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
	template <class T>
	std::set<ImplementationArtifactReference, T>		getImplementationArtifactReference(TDP)
	{
		std::set<ImplementationArtifactReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationArtifactReference");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ImplementationArtifactReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "FileRef" among "FileRef"s
	//********************************************************************************
	template <class T>
	std::set<FileRef, T>		getFileRef(TDP)
	{
		std::set<FileRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FileRef");
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
	template <class T>
	std::set<ImplementationArtifactReference, T>		getImplementationArtifactReference(TDP)
	{
		std::set<ImplementationArtifactReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationArtifactReference");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ImplementationArtifactReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ConnectionBand" among "ConnectionBand"s
	//********************************************************************************
	template <class T>
	std::set<ConnectionBand, T>		getConnectionBand(TDP)
	{
		std::set<ConnectionBand, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ConnectionBand");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ConnectionBand elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ThreadPoolLane" among "ThreadPoolLane"s
	//********************************************************************************
	template <class T>
	std::set<ThreadPoolLane, T>		getThreadPoolLane(TDP)
	{
		std::set<ThreadPoolLane, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ThreadPoolLane");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ThreadPoolLane elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ThreadPoolLane" among "ThreadPoolLane"s
	//********************************************************************************
	template <class T>
	std::set<ThreadPoolLane, T>		getThreadPoolLane(TDP)
	{
		std::set<ThreadPoolLane, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ThreadPoolLane");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ThreadPoolLane elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Property" among "Property"s
	//********************************************************************************
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<MonolithDeployRequirement, T>		getInMonolithDeployRequirementLinks(TDP)
	{
		std::set<MonolithDeployRequirement, T> result;
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
	template <class T>
	std::multiset<MonolithicImplementation, T>		getMonolithDeployRequirementSrcs(TDP)
	{
		std::multiset<MonolithicImplementation, T> res;
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
	//********************************************************************************
	// returns src ImplementationArtifacts
	//********************************************************************************
	template <class T>
	std::multiset<ImplementationArtifact, T>		getArtifactDeployRequirementSrcs(TDP)
	{
		std::multiset<ImplementationArtifact, T> res;
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
	template <class T>
	std::multiset<PublishConnector, T>		getAssemblyDeployRequirementSrcs(TDP)
	{
		std::multiset<PublishConnector, T> res;
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
	template <class T>
	std::multiset<Component, T>		getAssemblyselectRequirementSrcs(TDP)
	{
		std::multiset<Component, T> res;
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
	template <class T>
	std::set<ArtifactDeployRequirement, T>		getInArtifactDeployRequirementLinks(TDP)
	{
		std::set<ArtifactDeployRequirement, T> result;
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
	template <class T>
	std::set<AssemblyDeployRequirement, T>		getInAssemblyDeployRequirementLinks(TDP)
	{
		std::set<AssemblyDeployRequirement, T> result;
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
	template <class T>
	std::set<AssemblyselectRequirement, T>		getInAssemblyselectRequirementLinks(TDP)
	{
		std::set<AssemblyselectRequirement, T> result;
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
	template <class T>
	std::set<PackageConfSelectRequirement, T>		getInPackageConfSelectRequirementLinks(TDP)
	{
		std::set<PackageConfSelectRequirement, T> result;
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
	template <class T>
	std::multiset<PackageConfiguration, T>		getPackageConfSelectRequirementSrcs(TDP)
	{
		std::multiset<PackageConfiguration, T> res;
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
	//********************************************************************************
	// returns src BenchmarkTypes
	//********************************************************************************
	template <class T>
	std::multiset<BenchmarkType, T>		getBenchmarkCharacteristicsSrcs(TDP)
	{
		std::multiset<BenchmarkType, T> res;
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
	template <class T>
	std::set<BenchmarkCharacteristics, T>		getInBenchmarkCharacteristicsLinks(TDP)
	{
		std::set<BenchmarkCharacteristics, T> result;
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
	template <class T>
	std::set<MetricConnection, T>		getInMetricConnectionLinks(TDP)
	{
		std::set<MetricConnection, T> result;
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
	template <class T>
	std::multiset<OperationRef, T>		getMetricConnectionSrcs(TDP)
	{
		std::multiset<OperationRef, T> res;
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
	template <class T>
	std::set<WorkloadCharacteristics, T>		getOutWorkloadCharacteristicsLinks(TDP)
	{
		std::set<WorkloadCharacteristics, T> result;
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
	template <class T>
	std::multiset<TaskSet, T>		getWorkloadCharacteristicsDsts(TDP)
	{
		std::multiset<TaskSet, T> res;
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
	//********************************************************************************
	// getter for role "Average" among "DataAnalysisBase"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Average, T>		getAverage(TDP)
	{
		std::set<Average, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Average");
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
	template <class T>
	std::set<DataAnalysisBase, T>		getDataAnalysisBase(TDP)
	{
		std::set<DataAnalysisBase, T> res;
		const int len = 4;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Average");
		roles_vec[1] = getChildFCOsAs("Jitter");
		roles_vec[2] = getChildFCOsAs("Maximum");
		roles_vec[3] = getChildFCOsAs("Minimum");
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
	template <class T>
	std::set<Jitter, T>		getJitter(TDP)
	{
		std::set<Jitter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Jitter");
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
	template <class T>
	std::set<Maximum, T>		getMaximum(TDP)
	{
		std::set<Maximum, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Maximum");
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
	template <class T>
	std::set<Minimum, T>		getMinimum(TDP)
	{
		std::set<Minimum, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Minimum");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Minimum elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "SatisfierProperty" among "SatisfierProperty"s
	//********************************************************************************
	template <class T>
	std::set<SatisfierProperty, T>		getSatisfierProperty(TDP)
	{
		std::set<SatisfierProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SatisfierProperty");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			SatisfierProperty elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns src ComponentImplementations
	//********************************************************************************
	template <class T>
	std::multiset<ComponentImplementation, T>		getImplementationCapabilitySrcs(TDP)
	{
		std::multiset<ComponentImplementation, T> res;
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
	template <class T>
	std::set<ImplementationCapability, T>		getInImplementationCapabilityLinks(TDP)
	{
		std::set<ImplementationCapability, T> result;
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
	//********************************************************************************
	// returns dst Propertys
	//********************************************************************************
	template <class T>
	std::multiset<Property, T>		getConfigPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<Capability, T>		getImplementationCapabilityDsts(TDP)
	{
		std::multiset<Capability, T> res;
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
	template <class T>
	std::multiset<ImplementationDependency, T>		getImplementationDependsOnDsts(TDP)
	{
		std::multiset<ImplementationDependency, T> res;
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
	template <class T>
	std::multiset<ComponentRef, T>		getImplementsDsts(TDP)
	{
		std::multiset<ComponentRef, T> res;
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
	template <class T>
	std::multiset<Property, T>		getInfoPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::set<ConfigProperty, T>		getOutConfigPropertyLinks(TDP)
	{
		std::set<ConfigProperty, T> result;
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
	template <class T>
	std::set<ImplementationCapability, T>		getOutImplementationCapabilityLinks(TDP)
	{
		std::set<ImplementationCapability, T> result;
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
	template <class T>
	std::set<ImplementationDependsOn, T>		getOutImplementationDependsOnLinks(TDP)
	{
		std::set<ImplementationDependsOn, T> result;
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
	template <class T>
	std::set<Implements, T>		getOutImplementsLinks(TDP)
	{
		std::set<Implements, T> result;
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
	template <class T>
	std::set<InfoProperty, T>		getOutInfoPropertyLinks(TDP)
	{
		std::set<InfoProperty, T> result;
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
	// kind and role getters
	//********************************************************************************
	// getter for role "AssemblyConfigProperty" among "AssemblyConfigProperty"s
	//********************************************************************************
	template <class T>
	std::set<AssemblyConfigProperty, T>		getAssemblyConfigProperty(TDP)
	{
		std::set<AssemblyConfigProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AssemblyConfigProperty");
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
	template <class T>
	std::set<AssemblyDeployRequirement, T>		getAssemblyDeployRequirement(TDP)
	{
		std::set<AssemblyDeployRequirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AssemblyDeployRequirement");
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
	template <class T>
	std::set<AssemblyselectRequirement, T>		getAssemblyselectRequirement(TDP)
	{
		std::set<AssemblyselectRequirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AssemblyselectRequirement");
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
	template <class T>
	std::set<AttributeDelegate, T>		getAttributeDelegate(TDP)
	{
		std::set<AttributeDelegate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AttributeDelegate");
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
	template <class T>
	std::set<AttributeMapping, T>		getAttributeMapping(TDP)
	{
		std::set<AttributeMapping, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AttributeMapping");
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
	template <class T>
	std::set<AttributeMappingDelegate, T>		getAttributeMappingDelegate(TDP)
	{
		std::set<AttributeMappingDelegate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AttributeMappingDelegate");
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
	template <class T>
	std::set<AttributeMappingValue, T>		getAttributeMappingValue(TDP)
	{
		std::set<AttributeMappingValue, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AttributeMappingValue");
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
	template <class T>
	std::set<AttributeValue, T>		getAttributeValue(TDP)
	{
		std::set<AttributeValue, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("AttributeValue");
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
	template <class T>
	std::set<Component, T>		getComponent(TDP)
	{
		std::set<Component, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Component");
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
	template <class T>
	std::set<ComponentAssembly, T>		getComponentAssembly(TDP)
	{
		std::set<ComponentAssembly, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentAssembly");
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
	template <class T>
	std::set<ComponentAssemblyReference, T>		getComponentAssemblyReference(TDP)
	{
		std::set<ComponentAssemblyReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentAssemblyReference");
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
	template <class T>
	std::set<ComponentPackage, T>		getComponentPackage(TDP)
	{
		std::set<ComponentPackage, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentPackage");
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
	template <class T>
	std::set<ComponentPackageReference, T>		getComponentPackageReference(TDP)
	{
		std::set<ComponentPackageReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentPackageReference");
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
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<EventSinkDelegate, T>		getEventSinkDelegate(TDP)
	{
		std::set<EventSinkDelegate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("EventSinkDelegate");
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
	template <class T>
	std::set<EventSourceDelegate, T>		getEventSourceDelegate(TDP)
	{
		std::set<EventSourceDelegate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("EventSourceDelegate");
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
	template <class T>
	std::set<ExternalDelegate, T>		getExternalDelegate(TDP)
	{
		std::set<ExternalDelegate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ExternalDelegate");
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
	template <class T>
	std::set<ExternalReferenceEndPoint, T>		getExternalReferenceEndPoint(TDP)
	{
		std::set<ExternalReferenceEndPoint, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ExternalReferenceEndPoint");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ExternalReferenceEndPoint elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "FacetDelegate" among "FacetDelegate"s
	//********************************************************************************
	template <class T>
	std::set<FacetDelegate, T>		getFacetDelegate(TDP)
	{
		std::set<FacetDelegate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FacetDelegate");
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
	template <class T>
	std::set<InEventPort, T>		getInEventPort(TDP)
	{
		std::set<InEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InEventPort");
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
	template <class T>
	std::set<OutEventPort, T>		getOutEventPort(TDP)
	{
		std::set<OutEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OutEventPort");
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
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
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
	template <class T>
	std::set<ProvidedRequestPort, T>		getProvidedRequestPort(TDP)
	{
		std::set<ProvidedRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ProvidedRequestPort");
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
	template <class T>
	std::set<PublishConnector, T>		getPublishConnector(TDP)
	{
		std::set<PublishConnector, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PublishConnector");
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
	template <class T>
	std::set<QoSDecoration, T>		getQoSDecoration(TDP)
	{
		std::set<QoSDecoration, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSDecoration");
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
	template <class T>
	std::set<QoSValue, T>		getQoSValue(TDP)
	{
		std::set<QoSValue, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSValue");
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
	template <class T>
	std::set<ReceptacleDelegate, T>		getReceptacleDelegate(TDP)
	{
		std::set<ReceptacleDelegate, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ReceptacleDelegate");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ReceptacleDelegate elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "RequiredRequestPort" among "RequiredRequestPort"s
	//********************************************************************************
	template <class T>
	std::set<RequiredRequestPort, T>		getRequiredRequestPort(TDP)
	{
		std::set<RequiredRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RequiredRequestPort");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			RequiredRequestPort elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "Requirement" among "Requirement"s
	//********************************************************************************
	template <class T>
	std::set<Requirement, T>		getRequirement(TDP)
	{
		std::set<Requirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Requirement");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
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
	template <class T>
	std::set<deliverTo, T>		getdeliverTo(TDP)
	{
		std::set<deliverTo, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("deliverTo");
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
	template <class T>
	std::set<emit, T>		getemit(TDP)
	{
		std::set<emit, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("emit");
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
	template <class T>
	std::set<invoke, T>		getinvoke(TDP)
	{
		std::set<invoke, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("invoke");
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
	template <class T>
	std::set<publish, T>		getpublish(TDP)
	{
		std::set<publish, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("publish");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			publish elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns dst ImplementationRequirements
	//********************************************************************************
	template <class T>
	std::multiset<ImplementationRequirement, T>		getMonolithDeployRequirementDsts(TDP)
	{
		std::multiset<ImplementationRequirement, T> res;
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
	template <class T>
	std::multiset<Property, T>		getMonolithExecParameterDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<ImplementationArtifactReference, T>		getMonolithprimaryArtifactDsts(TDP)
	{
		std::multiset<ImplementationArtifactReference, T> res;
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
	template <class T>
	std::set<MonolithDeployRequirement, T>		getOutMonolithDeployRequirementLinks(TDP)
	{
		std::set<MonolithDeployRequirement, T> result;
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
	template <class T>
	std::set<MonolithExecParameter, T>		getOutMonolithExecParameterLinks(TDP)
	{
		std::set<MonolithExecParameter, T> result;
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
	template <class T>
	std::set<MonolithprimaryArtifact, T>		getOutMonolithprimaryArtifactLinks(TDP)
	{
		std::set<MonolithprimaryArtifact, T> result;
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
	//********************************************************************************
	// getter for role "ArtifactDependency" among "ArtifactDependency"s
	//********************************************************************************
	template <class T>
	std::set<ArtifactDependency, T>		getArtifactDependency(TDP)
	{
		std::set<ArtifactDependency, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ArtifactDependency");
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
	template <class T>
	std::set<ArtifactDependsOn, T>		getArtifactDependsOn(TDP)
	{
		std::set<ArtifactDependsOn, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ArtifactDependsOn");
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
	template <class T>
	std::set<ArtifactDeployRequirement, T>		getArtifactDeployRequirement(TDP)
	{
		std::set<ArtifactDeployRequirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ArtifactDeployRequirement");
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
	template <class T>
	std::set<ArtifactExecParameter, T>		getArtifactExecParameter(TDP)
	{
		std::set<ArtifactExecParameter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ArtifactExecParameter");
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
	template <class T>
	std::set<ArtifactInfoProperty, T>		getArtifactInfoProperty(TDP)
	{
		std::set<ArtifactInfoProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ArtifactInfoProperty");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ArtifactInfoProperty elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "ImplementationArtifact" among "ImplementationArtifact"s
	//********************************************************************************
	template <class T>
	std::set<ImplementationArtifact, T>		getImplementationArtifact(TDP)
	{
		std::set<ImplementationArtifact, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationArtifact");
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
	template <class T>
	std::set<ImplementationArtifactReference, T>		getImplementationArtifactReference(TDP)
	{
		std::set<ImplementationArtifactReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationArtifactReference");
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
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "Requirement" among "Requirement"s
	//********************************************************************************
	template <class T>
	std::set<Requirement, T>		getRequirement(TDP)
	{
		std::set<Requirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Requirement");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Average" among "DataAnalysisBase"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Average, T>		getAverage(TDP)
	{
		std::set<Average, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Average");
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
	template <class T>
	std::set<BenchmarkCharacteristics, T>		getBenchmarkCharacteristics(TDP)
	{
		std::set<BenchmarkCharacteristics, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("BenchmarkCharacteristics");
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
	template <class T>
	std::set<BenchmarkType, T>		getBenchmarkType(TDP)
	{
		std::set<BenchmarkType, T> res;
		const int len = 3;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("FixedIterationBenchmarks");
		roles_vec[1] = getChildFCOsAs("PeriodicBenchmarks");
		roles_vec[2] = getChildFCOsAs("TriggerBenchmarks");
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
	template <class T>
	std::set<CompRef, T>		getCompRef(TDP)
	{
		std::set<CompRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("CompRef");
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
	template <class T>
	std::set<ComponentOperation, T>		getComponentOperation(TDP)
	{
		std::set<ComponentOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentOperation");
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
	template <class T>
	std::set<DataAnalysisBase, T>		getDataAnalysisBase(TDP)
	{
		std::set<DataAnalysisBase, T> res;
		const int len = 4;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Average");
		roles_vec[1] = getChildFCOsAs("Jitter");
		roles_vec[2] = getChildFCOsAs("Maximum");
		roles_vec[3] = getChildFCOsAs("Minimum");
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
	template <class T>
	std::set<Event, T>		getEvent(TDP)
	{
		std::set<Event, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Event");
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
	template <class T>
	std::set<EventRef, T>		getEventRef(TDP)
	{
		std::set<EventRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("EventRef");
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
	template <class T>
	std::set<FactoryOperation, T>		getFactoryOperation(TDP)
	{
		std::set<FactoryOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FactoryOperation");
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
	template <class T>
	std::set<FixedIterationBenchmarks, T>		getFixedIterationBenchmarks(TDP)
	{
		std::set<FixedIterationBenchmarks, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("FixedIterationBenchmarks");
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
	template <class T>
	std::set<Jitter, T>		getJitter(TDP)
	{
		std::set<Jitter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Jitter");
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
	template <class T>
	std::set<Latency, T>		getLatency(TDP)
	{
		std::set<Latency, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Latency");
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
	template <class T>
	std::set<LookupOperation, T>		getLookupOperation(TDP)
	{
		std::set<LookupOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("LookupOperation");
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
	template <class T>
	std::set<Maximum, T>		getMaximum(TDP)
	{
		std::set<Maximum, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Maximum");
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
	template <class T>
	std::set<MetricConnection, T>		getMetricConnection(TDP)
	{
		std::set<MetricConnection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("MetricConnection");
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
	template <class T>
	std::set<MetricsBase, T>		getMetricsBase(TDP)
	{
		std::set<MetricsBase, T> res;
		const int len = 2;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Latency");
		roles_vec[1] = getChildFCOsAs("Throughput");
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
	template <class T>
	std::set<Minimum, T>		getMinimum(TDP)
	{
		std::set<Minimum, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Minimum");
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
	template <class T>
	std::set<OnewayOperation, T>		getOnewayOperation(TDP)
	{
		std::set<OnewayOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OnewayOperation");
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
	template <class T>
	std::set<OperationBase, T>		getOperationBase(TDP)
	{
		std::set<OperationBase, T> res;
		const int len = 4;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("FactoryOperation");
		roles_vec[1] = getChildFCOsAs("LookupOperation");
		roles_vec[2] = getChildFCOsAs("OnewayOperation");
		roles_vec[3] = getChildFCOsAs("TwowayOperation");
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
	template <class T>
	std::set<OperationRef, T>		getOperationRef(TDP)
	{
		std::set<OperationRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OperationRef");
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
	template <class T>
	std::set<PeriodicBenchmarks, T>		getPeriodicBenchmarks(TDP)
	{
		std::set<PeriodicBenchmarks, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PeriodicBenchmarks");
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
	template <class T>
	std::set<Task, T>		getTask(TDP)
	{
		std::set<Task, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Task");
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
	template <class T>
	std::set<TaskSet, T>		getTaskSet(TDP)
	{
		std::set<TaskSet, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TaskSet");
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
	template <class T>
	std::set<Throughput, T>		getThroughput(TDP)
	{
		std::set<Throughput, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Throughput");
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
	template <class T>
	std::set<TimeProbe, T>		getTimeProbe(TDP)
	{
		std::set<TimeProbe, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TimeProbe");
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
	template <class T>
	std::set<TimerConnection, T>		getTimerConnection(TDP)
	{
		std::set<TimerConnection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TimerConnection");
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
	template <class T>
	std::set<TimerEventSinkConn, T>		getTimerEventSinkConn(TDP)
	{
		std::set<TimerEventSinkConn, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TimerEventSinkConn");
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
	template <class T>
	std::set<TriggerBenchmarks, T>		getTriggerBenchmarks(TDP)
	{
		std::set<TriggerBenchmarks, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TriggerBenchmarks");
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
	template <class T>
	std::set<TwowayOperation, T>		getTwowayOperation(TDP)
	{
		std::set<TwowayOperation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TwowayOperation");
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
	template <class T>
	std::set<WorkLoadOperationConnection, T>		getWorkLoadOperationConnection(TDP)
	{
		std::set<WorkLoadOperationConnection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("WorkLoadOperationConnection");
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
	template <class T>
	std::set<WorkloadCharacteristics, T>		getWorkloadCharacteristics(TDP)
	{
		std::set<WorkloadCharacteristics, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("WorkloadCharacteristics");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			WorkloadCharacteristics elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ComponentConfigProperty" among "ComponentConfigProperty"s
	//********************************************************************************
	template <class T>
	std::set<ComponentConfigProperty, T>		getComponentConfigProperty(TDP)
	{
		std::set<ComponentConfigProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentConfigProperty");
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
	template <class T>
	std::set<ComponentInfoProperty, T>		getComponentInfoProperty(TDP)
	{
		std::set<ComponentInfoProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentInfoProperty");
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
	template <class T>
	std::set<ComponentProperty, T>		getComponentProperty(TDP)
	{
		std::set<ComponentProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentProperty");
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
	template <class T>
	std::set<ComponentPropertyDescription, T>		getComponentPropertyDescription(TDP)
	{
		std::set<ComponentPropertyDescription, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentPropertyDescription");
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
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Capability" among "Capability"s
	//********************************************************************************
	template <class T>
	std::set<Capability, T>		getCapability(TDP)
	{
		std::set<Capability, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Capability");
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
	template <class T>
	std::set<ComponentAssembly, T>		getComponentAssembly(TDP)
	{
		std::set<ComponentAssembly, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentAssembly");
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
	template <class T>
	std::set<ComponentImplementation, T>		getComponentImplementation(TDP)
	{
		std::set<ComponentImplementation, T> res;
		const int len = 2;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("MonolithicImplementation");
		roles_vec[1] = getChildFCOsAs("ComponentAssembly");
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
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<ConfigProperty, T>		getConfigProperty(TDP)
	{
		std::set<ConfigProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ConfigProperty");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ConfigProperty elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "ImplementationArtifactReference" among "ImplementationArtifactReference"s
	//********************************************************************************
	template <class T>
	std::set<ImplementationArtifactReference, T>		getImplementationArtifactReference(TDP)
	{
		std::set<ImplementationArtifactReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationArtifactReference");
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
	template <class T>
	std::set<ImplementationCapability, T>		getImplementationCapability(TDP)
	{
		std::set<ImplementationCapability, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationCapability");
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
	template <class T>
	std::set<ImplementationDependency, T>		getImplementationDependency(TDP)
	{
		std::set<ImplementationDependency, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationDependency");
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
	template <class T>
	std::set<ImplementationDependsOn, T>		getImplementationDependsOn(TDP)
	{
		std::set<ImplementationDependsOn, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationDependsOn");
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
	template <class T>
	std::set<ImplementationRequirement, T>		getImplementationRequirement(TDP)
	{
		std::set<ImplementationRequirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationRequirement");
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
	template <class T>
	std::set<Implements, T>		getImplements(TDP)
	{
		std::set<Implements, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Implements");
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
	template <class T>
	std::set<InfoProperty, T>		getInfoProperty(TDP)
	{
		std::set<InfoProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InfoProperty");
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
	template <class T>
	std::set<MonolithDeployRequirement, T>		getMonolithDeployRequirement(TDP)
	{
		std::set<MonolithDeployRequirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("MonolithDeployRequirement");
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
	template <class T>
	std::set<MonolithExecParameter, T>		getMonolithExecParameter(TDP)
	{
		std::set<MonolithExecParameter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("MonolithExecParameter");
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
	template <class T>
	std::set<MonolithicImplementation, T>		getMonolithicImplementation(TDP)
	{
		std::set<MonolithicImplementation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("MonolithicImplementation");
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
	template <class T>
	std::set<MonolithprimaryArtifact, T>		getMonolithprimaryArtifact(TDP)
	{
		std::set<MonolithprimaryArtifact, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("MonolithprimaryArtifact");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			MonolithprimaryArtifact elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "Property" among "Property"s
	//********************************************************************************
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns src ComponentRefs
	//********************************************************************************
	template <class T>
	std::multiset<ComponentRef, T>		getComponentPropertySrcs(TDP)
	{
		std::multiset<ComponentRef, T> res;
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
	template <class T>
	std::set<ComponentProperty, T>		getInComponentPropertyLinks(TDP)
	{
		std::set<ComponentProperty, T> result;
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

	//
	// kind and role getters
	//********************************************************************************
	// getter for role "DataType" among "DataType"s
	//********************************************************************************
	template <class T>
	std::set<DataType, T>		getDataType(TDP)
	{
		std::set<DataType, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("DataType");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			DataType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	virtual std::string getlabel() ;
	virtual void        setlabel( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "CollocationGroup" among "CollocationGroup"s
	//********************************************************************************
	template <class T>
	std::set<CollocationGroup, T>		getCollocationGroup(TDP)
	{
		std::set<CollocationGroup, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("CollocationGroup");
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
	template <class T>
	std::set<ComponentAssemblyReference, T>		getComponentAssemblyReference(TDP)
	{
		std::set<ComponentAssemblyReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentAssemblyReference");
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
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<InstanceMapping, T>		getInstanceMapping(TDP)
	{
		std::set<InstanceMapping, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InstanceMapping");
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
	template <class T>
	std::set<NodeReference, T>		getNodeReference(TDP)
	{
		std::set<NodeReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("NodeReference");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			NodeReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Bridge" among "Elements"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<Bridge, T>		getBridge(TDP)
	{
		std::set<Bridge, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Bridge");
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
	template <class T>
	std::set<Bridge2Interconnect, T>		getBridge2Interconnect(TDP)
	{
		std::set<Bridge2Interconnect, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Bridge2Interconnect");
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
	template <class T>
	std::set<Elements, T>		getElements(TDP)
	{
		std::set<Elements, T> res;
		const int len = 4;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("Bridge");
		roles_vec[1] = getChildFCOsAs("Interconnect");
		roles_vec[2] = getChildFCOsAs("Node");
		roles_vec[3] = getChildFCOsAs("SharedResource");
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
	template <class T>
	std::set<Interconnect, T>		getInterconnect(TDP)
	{
		std::set<Interconnect, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Interconnect");
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
	template <class T>
	std::set<Interconnect2Bridge, T>		getInterconnect2Bridge(TDP)
	{
		std::set<Interconnect2Bridge, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Interconnect2Bridge");
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
	template <class T>
	std::set<Interconnect2Node, T>		getInterconnect2Node(TDP)
	{
		std::set<Interconnect2Node, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Interconnect2Node");
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
	template <class T>
	std::set<Node, T>		getNode(TDP)
	{
		std::set<Node, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Node");
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
	template <class T>
	std::set<Node2Interconnect, T>		getNode2Interconnect(TDP)
	{
		std::set<Node2Interconnect, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Node2Interconnect");
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
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
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
	template <class T>
	std::set<SharedResource, T>		getSharedResource(TDP)
	{
		std::set<SharedResource, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SharedResource");
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
	template <class T>
	std::set<Shares, T>		getShares(TDP)
	{
		std::set<Shares, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Shares");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Shares elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ComponentRef" among "ComponentRef"s
	//********************************************************************************
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<InEventPort, T>		getInEventPort(TDP)
	{
		std::set<InEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InEventPort");
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
	template <class T>
	std::set<OutEventPort, T>		getOutEventPort(TDP)
	{
		std::set<OutEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OutEventPort");
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
	template <class T>
	std::set<Port, T>		getPort(TDP)
	{
		std::set<Port, T> res;
		const int len = 4;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("InEventPort");
		roles_vec[1] = getChildFCOsAs("OutEventPort");
		roles_vec[2] = getChildFCOsAs("ProvidedRequestPort");
		roles_vec[3] = getChildFCOsAs("RequiredRequestPort");
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
	template <class T>
	std::set<ProvidedRequestPort, T>		getProvidedRequestPort(TDP)
	{
		std::set<ProvidedRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ProvidedRequestPort");
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
	template <class T>
	std::set<Proxy, T>		getProxy(TDP)
	{
		std::set<Proxy, T> res;
		const int len = 2;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("RTEC_Proxy_Consumer");
		roles_vec[1] = getChildFCOsAs("RTEC_Proxy_Supplier");
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
	template <class T>
	std::set<RTEC_Connection, T>		getRTEC_Connection(TDP)
	{
		std::set<RTEC_Connection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RTEC_Connection");
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
	template <class T>
	std::set<RTEC_Proxy_Consumer, T>		getRTEC_Proxy_Consumer(TDP)
	{
		std::set<RTEC_Proxy_Consumer, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RTEC_Proxy_Consumer");
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
	template <class T>
	std::set<RTEC_Proxy_Supplier, T>		getRTEC_Proxy_Supplier(TDP)
	{
		std::set<RTEC_Proxy_Supplier, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RTEC_Proxy_Supplier");
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
	template <class T>
	std::set<RTEC_Resource_Factory, T>		getRTEC_Resource_Factory(TDP)
	{
		std::set<RTEC_Resource_Factory, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RTEC_Resource_Factory");
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
	template <class T>
	std::set<RequiredRequestPort, T>		getRequiredRequestPort(TDP)
	{
		std::set<RequiredRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RequiredRequestPort");
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
	template <class T>
	std::set<Use_RTEC_Filter, T>		getUse_RTEC_Filter(TDP)
	{
		std::set<Use_RTEC_Filter, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Use_RTEC_Filter");
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
	template <class T>
	std::set<Use_RT_Info, T>		getUse_RT_Info(TDP)
	{
		std::set<Use_RT_Info, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Use_RT_Info");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Use_RT_Info elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Project" among "Project"s
	//********************************************************************************
	template <class T>
	std::set<Project, T>		getProject(TDP)
	{
		std::set<Project, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Project");
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
	template <class T>
	std::set<Workspaces, T>		getWorkspaces(TDP)
	{
		std::set<Workspaces, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Workspaces");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Workspaces elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ComponentPackage" among "ComponentPackage"s
	//********************************************************************************
	template <class T>
	std::set<ComponentPackage, T>		getComponentPackage(TDP)
	{
		std::set<ComponentPackage, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentPackage");
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
	template <class T>
	std::set<ComponentPackageReference, T>		getComponentPackageReference(TDP)
	{
		std::set<ComponentPackageReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentPackageReference");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ComponentPackageReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "PackageConfBasePackage" among "PackageConfBasePackage"s
	//********************************************************************************
	template <class T>
	std::set<PackageConfBasePackage, T>		getPackageConfBasePackage(TDP)
	{
		std::set<PackageConfBasePackage, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfBasePackage");
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
	template <class T>
	std::set<PackageConfConfigProperty, T>		getPackageConfConfigProperty(TDP)
	{
		std::set<PackageConfConfigProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfConfigProperty");
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
	template <class T>
	std::set<PackageConfReference, T>		getPackageConfReference(TDP)
	{
		std::set<PackageConfReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfReference");
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
	template <class T>
	std::set<PackageConfSelectRequirement, T>		getPackageConfSelectRequirement(TDP)
	{
		std::set<PackageConfSelectRequirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfSelectRequirement");
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
	template <class T>
	std::set<PackageConfSpecializedConfig, T>		getPackageConfSpecializedConfig(TDP)
	{
		std::set<PackageConfSpecializedConfig, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfSpecializedConfig");
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
	template <class T>
	std::set<PackageConfiguration, T>		getPackageConfiguration(TDP)
	{
		std::set<PackageConfiguration, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfiguration");
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
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "Requirement" among "Requirement"s
	//********************************************************************************
	template <class T>
	std::set<Requirement, T>		getRequirement(TDP)
	{
		std::set<Requirement, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Requirement");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Requirement elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "ComponentImplementationReference" among "ComponentImplementationReference"s
	//********************************************************************************
	template <class T>
	std::set<ComponentImplementationReference, T>		getComponentImplementationReference(TDP)
	{
		std::set<ComponentImplementationReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentImplementationReference");
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
	template <class T>
	std::set<ComponentPackage, T>		getComponentPackage(TDP)
	{
		std::set<ComponentPackage, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentPackage");
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
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<Implementation, T>		getImplementation(TDP)
	{
		std::set<Implementation, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Implementation");
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
	template <class T>
	std::set<PackageConfigProperty, T>		getPackageConfigProperty(TDP)
	{
		std::set<PackageConfigProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfigProperty");
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
	template <class T>
	std::set<PackageInfoProperty, T>		getPackageInfoProperty(TDP)
	{
		std::set<PackageInfoProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageInfoProperty");
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
	template <class T>
	std::set<PackageInterface, T>		getPackageInterface(TDP)
	{
		std::set<PackageInterface, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageInterface");
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
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	// kind and role getters
	//********************************************************************************
	// getter for role "ComponentRef" among "ComponentRef"s
	//********************************************************************************
	template <class T>
	std::set<ComponentRef, T>		getComponentRef(TDP)
	{
		std::set<ComponentRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ComponentRef");
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
	template <class T>
	std::set<ConnectedComponent, T>		getConnectedComponent(TDP)
	{
		std::set<ConnectedComponent, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ConnectedComponent");
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
	template <class T>
	std::set<DisplayNode, T>		getDisplayNode(TDP)
	{
		std::set<DisplayNode, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("DisplayNode");
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
	template <class T>
	std::set<DstEdge, T>		getDstEdge(TDP)
	{
		std::set<DstEdge, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("DstEdge");
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
	template <class T>
	std::set<Edge, T>		getEdge(TDP)
	{
		std::set<Edge, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Edge");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Edge elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// aggregated getter for role "" among "GraphVertex"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<GraphVertex, T>		getGraphVertex(TDP)
	{
		std::set<GraphVertex, T> res;
		const int len = 6;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("DisplayNode");
		roles_vec[1] = getChildFCOsAs("ConnectedComponent");
		roles_vec[2] = getChildFCOsAs("InEventPort");
		roles_vec[3] = getChildFCOsAs("OutEventPort");
		roles_vec[4] = getChildFCOsAs("ProvidedRequestPort");
		roles_vec[5] = getChildFCOsAs("RequiredRequestPort");
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
	template <class T>
	std::set<InEventPort, T>		getInEventPort(TDP)
	{
		std::set<InEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("InEventPort");
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
	template <class T>
	std::set<OutEventPort, T>		getOutEventPort(TDP)
	{
		std::set<OutEventPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("OutEventPort");
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
	template <class T>
	std::set<Property, T>		getProperty(TDP)
	{
		std::set<Property, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Property");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Property elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "PropertyConnector" among "PropertyConnector"s
	//********************************************************************************
	template <class T>
	std::set<PropertyConnector, T>		getPropertyConnector(TDP)
	{
		std::set<PropertyConnector, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PropertyConnector");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			PropertyConnector elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}

	//********************************************************************************
	// getter for role "ProvidedRequestPort" among "GraphVertex"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<ProvidedRequestPort, T>		getProvidedRequestPort(TDP)
	{
		std::set<ProvidedRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ProvidedRequestPort");
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
	template <class T>
	std::set<RequiredRequestPort, T>		getRequiredRequestPort(TDP)
	{
		std::set<RequiredRequestPort, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RequiredRequestPort");
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
	template <class T>
	std::set<SrcEdge, T>		getSrcEdge(TDP)
	{
		std::set<SrcEdge, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SrcEdge");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			SrcEdge elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "BandedConnectionRef" among "BandedConnectionRef"s
	//********************************************************************************
	template <class T>
	std::set<BandedConnectionRef, T>		getBandedConnectionRef(TDP)
	{
		std::set<BandedConnectionRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("BandedConnectionRef");
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
	template <class T>
	std::set<PriorityModelPolicy, T>		getPriorityModelPolicy(TDP)
	{
		std::set<PriorityModelPolicy, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PriorityModelPolicy");
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
	template <class T>
	std::set<ThreadPoolRef, T>		getThreadPoolRef(TDP)
	{
		std::set<ThreadPoolRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ThreadPoolRef");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ThreadPoolRef elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// aggregated getter for role "" among "ComponentLib"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<ComponentLib, T>		getComponentLib(TDP)
	{
		std::set<ComponentLib, T> res;
		const int len = 3;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("ExecutorProject");
		roles_vec[1] = getChildFCOsAs("ServantProject");
		roles_vec[2] = getChildFCOsAs("StubProject");
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
	template <class T>
	std::set<ExecutorProject, T>		getExecutorProject(TDP)
	{
		std::set<ExecutorProject, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ExecutorProject");
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
	template <class T>
	std::set<ExtResourceConn, T>		getExtResourceConn(TDP)
	{
		std::set<ExtResourceConn, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ExtResourceConn");
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
	template <class T>
	std::set<ExternalResources, T>		getExternalResources(TDP)
	{
		std::set<ExternalResources, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ExternalResources");
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
	template <class T>
	std::set<ImplementationArtifact, T>		getImplementationArtifact(TDP)
	{
		std::set<ImplementationArtifact, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ImplementationArtifact");
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
	template <class T>
	std::set<ServantProject, T>		getServantProject(TDP)
	{
		std::set<ServantProject, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ServantProject");
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
	template <class T>
	std::set<StubProject, T>		getStubProject(TDP)
	{
		std::set<StubProject, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("StubProject");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			StubProject elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns src ImplementationArtifacts
	//********************************************************************************
	template <class T>
	std::multiset<ImplementationArtifact, T>		getArtifactExecParameterSrcs(TDP)
	{
		std::multiset<ImplementationArtifact, T> res;
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
	template <class T>
	std::multiset<ImplementationArtifact, T>		getArtifactInfoPropertySrcs(TDP)
	{
		std::multiset<ImplementationArtifact, T> res;
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
	template <class T>
	std::multiset<Component, T>		getAssemblyConfigPropertySrcs(TDP)
	{
		std::multiset<Component, T> res;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getAttributeMappingValueSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("AttributeMappingValue");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns src ReadonlyAttributes and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getAttributeValueSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("AttributeValue");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns src ComponentRefs
	//********************************************************************************
	template <class T>
	std::multiset<ComponentRef, T>		getComponentConfigPropertySrcs(TDP)
	{
		std::multiset<ComponentRef, T> res;
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
	template <class T>
	std::multiset<ComponentRef, T>		getComponentInfoPropertySrcs(TDP)
	{
		std::multiset<ComponentRef, T> res;
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
	template <class T>
	std::multiset<ComponentImplementation, T>		getConfigPropertySrcs(TDP)
	{
		std::multiset<ComponentImplementation, T> res;
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
	// 
	//********************************************************************************
	template <class T>
	std::set<ArtifactExecParameter, T>		getInArtifactExecParameterLinks(TDP)
	{
		std::set<ArtifactExecParameter, T> result;
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
	template <class T>
	std::set<ArtifactInfoProperty, T>		getInArtifactInfoPropertyLinks(TDP)
	{
		std::set<ArtifactInfoProperty, T> result;
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
	template <class T>
	std::set<AssemblyConfigProperty, T>		getInAssemblyConfigPropertyLinks(TDP)
	{
		std::set<AssemblyConfigProperty, T> result;
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
	template <class T>
	std::set<AttributeMappingValue, T>		getInAttributeMappingValueLinks(TDP)
	{
		std::set<AttributeMappingValue, T> result;
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
	template <class T>
	std::set<AttributeValue, T>		getInAttributeValueLinks(TDP)
	{
		std::set<AttributeValue, T> result;
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
	template <class T>
	std::set<ComponentConfigProperty, T>		getInComponentConfigPropertyLinks(TDP)
	{
		std::set<ComponentConfigProperty, T> result;
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
	template <class T>
	std::set<ComponentInfoProperty, T>		getInComponentInfoPropertyLinks(TDP)
	{
		std::set<ComponentInfoProperty, T> result;
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
	template <class T>
	std::set<ConfigProperty, T>		getInConfigPropertyLinks(TDP)
	{
		std::set<ConfigProperty, T> result;
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
	template <class T>
	std::set<InfoProperty, T>		getInInfoPropertyLinks(TDP)
	{
		std::set<InfoProperty, T> result;
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
	template <class T>
	std::set<MonolithExecParameter, T>		getInMonolithExecParameterLinks(TDP)
	{
		std::set<MonolithExecParameter, T> result;
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
	template <class T>
	std::set<PackageConfConfigProperty, T>		getInPackageConfConfigPropertyLinks(TDP)
	{
		std::set<PackageConfConfigProperty, T> result;
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
	template <class T>
	std::set<PackageConfigProperty, T>		getInPackageConfigPropertyLinks(TDP)
	{
		std::set<PackageConfigProperty, T> result;
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
	template <class T>
	std::set<PackageInfoProperty, T>		getInPackageInfoPropertyLinks(TDP)
	{
		std::set<PackageInfoProperty, T> result;
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
	// returns src ComponentImplementations
	//********************************************************************************
	template <class T>
	std::multiset<ComponentImplementation, T>		getInfoPropertySrcs(TDP)
	{
		std::multiset<ComponentImplementation, T> res;
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
	template <class T>
	std::multiset<MonolithicImplementation, T>		getMonolithExecParameterSrcs(TDP)
	{
		std::multiset<MonolithicImplementation, T> res;
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
	template <class T>
	std::set<PropertyConnector, T>		getOutPropertyConnectorLinks(TDP)
	{
		std::set<PropertyConnector, T> result;
		std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
		std::set<BON::Connection>::iterator it = conns.begin();
		for( ; it != conns.end(); ++it)
		{
			PropertyConnector c( *it);
			if (c)
				result.insert( c);
		}
		return result;
	}

	//********************************************************************************
	// returns src PackageConfigurations
	//********************************************************************************
	template <class T>
	std::multiset<PackageConfiguration, T>		getPackageConfConfigPropertySrcs(TDP)
	{
		std::multiset<PackageConfiguration, T> res;
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
	template <class T>
	std::multiset<ComponentPackage, T>		getPackageConfigPropertySrcs(TDP)
	{
		std::multiset<ComponentPackage, T> res;
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
	template <class T>
	std::multiset<ComponentPackage, T>		getPackageInfoPropertySrcs(TDP)
	{
		std::multiset<ComponentPackage, T> res;
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
	// returns dst Edges
	//********************************************************************************
	template <class T>
	std::multiset<Edge, T>		getPropertyConnectorDsts(TDP)
	{
		std::multiset<Edge, T> res;
		{
			std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("PropertyConnector");
			for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
			{
				Edge dst( *cit );
				ASSERT(dst);
				res.insert( dst);
			}
		}
		return res;
	}

	//
	// attribute getters and setters
	virtual std::string getDataValue() ;
	virtual void        setDataValue( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "DataType" among "DataType"s
	//********************************************************************************
	template <class T>
	std::set<DataType, T>		getDataType(TDP)
	{
		std::set<DataType, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("DataType");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			DataType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "CPU" among "QoSCharacteristic"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<CPU, T>		getCPU(TDP)
	{
		std::set<CPU, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("CPU");
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
	template <class T>
	std::set<Concurrency, T>		getConcurrency(TDP)
	{
		std::set<Concurrency, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Concurrency");
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
	template <class T>
	std::set<Connection, T>		getConnection(TDP)
	{
		std::set<Connection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Connection");
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
	template <class T>
	std::set<Process, T>		getProcess(TDP)
	{
		std::set<Process, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Process");
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
	template <class T>
	std::set<QoSCharacteristic, T>		getQoSCharacteristic(TDP)
	{
		std::set<QoSCharacteristic, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSCharacteristic");
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
	template <class T>
	std::set<QoSCharacteristic, T>		getQoSCharacteristic(int dummy, TDP)
	{
		std::set<QoSCharacteristic, T> res;
		const int len = 5;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("CPU");
		roles_vec[1] = getChildFCOsAs("Concurrency");
		roles_vec[2] = getChildFCOsAs("Connection");
		roles_vec[3] = getChildFCOsAs("Process");
		roles_vec[4] = getChildFCOsAs("QoSCharacteristic");
		for( int k = 0; k < len; ++k)
			for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
			{
				QoSCharacteristic elem(*i);
				ASSERT(elem);
				res.insert(elem);
			}
		return res;
	}


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
	//********************************************************************************
	// getter for role "CPU" among "QoSCharacteristic"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<CPU, T>		getCPU(TDP)
	{
		std::set<CPU, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("CPU");
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
	template <class T>
	std::set<Concurrency, T>		getConcurrency(TDP)
	{
		std::set<Concurrency, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Concurrency");
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
	template <class T>
	std::set<Connection, T>		getConnection(TDP)
	{
		std::set<Connection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Connection");
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
	template <class T>
	std::set<Process, T>		getProcess(TDP)
	{
		std::set<Process, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Process");
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
	template <class T>
	std::set<QoSCharacteristic, T>		getQoSCharacteristic(TDP)
	{
		std::set<QoSCharacteristic, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSCharacteristic");
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
	template <class T>
	std::set<QoSCharacteristic, T>		getQoSCharacteristic(int dummy, TDP)
	{
		std::set<QoSCharacteristic, T> res;
		const int len = 5;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("CPU");
		roles_vec[1] = getChildFCOsAs("Concurrency");
		roles_vec[2] = getChildFCOsAs("Connection");
		roles_vec[3] = getChildFCOsAs("Process");
		roles_vec[4] = getChildFCOsAs("QoSCharacteristic");
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
	template <class T>
	std::set<QoSConstraint, T>		getQoSConstraint(TDP)
	{
		std::set<QoSConstraint, T> res;
		const int len = 3;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("QoSContract");
		roles_vec[1] = getChildFCOsAs("QoSOffered");
		roles_vec[2] = getChildFCOsAs("QoSRequired");
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
	template <class T>
	std::set<QoSContext, T>		getQoSContext(TDP)
	{
		std::set<QoSContext, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSContext");
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
	template <class T>
	std::set<QoSContract, T>		getQoSContract(TDP)
	{
		std::set<QoSContract, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSContract");
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
	template <class T>
	std::set<QoSOffered, T>		getQoSOffered(TDP)
	{
		std::set<QoSOffered, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSOffered");
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
	template <class T>
	std::set<QoSRequired, T>		getQoSRequired(TDP)
	{
		std::set<QoSRequired, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSRequired");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			QoSRequired elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<QoSDecoration, T>		getOutQoSDecorationLinks(TDP)
	{
		std::set<QoSDecoration, T> result;
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
	template <class T>
	std::multiset<Component, T>		getQoSDecorationDsts(TDP)
	{
		std::multiset<Component, T> res;
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

	//
	// kind and role getters
	//********************************************************************************
	// getter for role "CPU" among "QoSCharacteristic"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<CPU, T>		getCPU(TDP)
	{
		std::set<CPU, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("CPU");
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
	template <class T>
	std::set<Concurrency, T>		getConcurrency(TDP)
	{
		std::set<Concurrency, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Concurrency");
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
	template <class T>
	std::set<Connection, T>		getConnection(TDP)
	{
		std::set<Connection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Connection");
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
	template <class T>
	std::set<Process, T>		getProcess(TDP)
	{
		std::set<Process, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Process");
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
	template <class T>
	std::set<QoSCharacteristic, T>		getQoSCharacteristic(TDP)
	{
		std::set<QoSCharacteristic, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSCharacteristic");
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
	template <class T>
	std::set<QoSCharacteristic, T>		getQoSCharacteristic(int dummy, TDP)
	{
		std::set<QoSCharacteristic, T> res;
		const int len = 5;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("CPU");
		roles_vec[1] = getChildFCOsAs("Concurrency");
		roles_vec[2] = getChildFCOsAs("Connection");
		roles_vec[3] = getChildFCOsAs("Process");
		roles_vec[4] = getChildFCOsAs("QoSCharacteristic");
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
	template <class T>
	std::set<QoSDimensionQualifier, T>		getQoSDimensionQualifier(TDP)
	{
		std::set<QoSDimensionQualifier, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSDimensionQualifier");
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
	template <class T>
	std::set<QoSDimensionSlot, T>		getQoSDimensionSlot(TDP)
	{
		std::set<QoSDimensionSlot, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("QoSDimensionSlot");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			QoSDimensionSlot elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "RTModel" among "RTModel"s
	//********************************************************************************
	template <class T>
	std::set<RTModel, T>		getRTModel(TDP)
	{
		std::set<RTModel, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("RTModel");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			RTModel elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "EnvironmentConf" among "EnvironmentConf"s
	//********************************************************************************
	template <class T>
	std::set<EnvironmentConf, T>		getEnvironmentConf(TDP)
	{
		std::set<EnvironmentConf, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("EnvironmentConf");
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
	template <class T>
	std::set<PolicySet, T>		getPolicySet(TDP)
	{
		std::set<PolicySet, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PolicySet");
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
	template <class T>
	std::set<PolicySetRef, T>		getPolicySetRef(TDP)
	{
		std::set<PolicySetRef, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PolicySetRef");
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
	template <class T>
	std::set<ResourceContainer, T>		getResourceContainer(TDP)
	{
		std::set<ResourceContainer, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ResourceContainer");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			ResourceContainer elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ResourceImpl
//*******************************************************************
class ResourceImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getresourceType() ;
	virtual void        setresourceType( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "SatisfierProperty" among "SatisfierProperty"s
	//********************************************************************************
	template <class T>
	std::set<SatisfierProperty, T>		getSatisfierProperty(TDP)
	{
		std::set<SatisfierProperty, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SatisfierProperty");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			SatisfierProperty elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "BandedConnection" among "resource"s and its descendants
	//********************************************************************************
	template <class T>
	std::set<BandedConnection, T>		getBandedConnection(TDP)
	{
		std::set<BandedConnection, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("BandedConnection");
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
	template <class T>
	std::set<SimpleThreadPool, T>		getSimpleThreadPool(TDP)
	{
		std::set<SimpleThreadPool, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("SimpleThreadPool");
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
	template <class T>
	std::set<ThreadPoolWithLanes, T>		getThreadPoolWithLanes(TDP)
	{
		std::set<ThreadPoolWithLanes, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("ThreadPoolWithLanes");
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
	template <class T>
	std::set<resource, T>		getresource(TDP)
	{
		std::set<resource, T> res;
		const int len = 3;
		std::set<BON::FCO> roles_vec[ len];
		roles_vec[0] = getChildFCOsAs("BandedConnection");
		roles_vec[1] = getChildFCOsAs("SimpleThreadPool");
		roles_vec[2] = getChildFCOsAs("ThreadPoolWithLanes");
		for( int k = 0; k < len; ++k)
			for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
			{
				resource elem(*i);
				ASSERT(elem);
				res.insert(elem);
			}
		return res;
	}


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
	virtual void        setDataValue( const std::string& val);
	virtual void        setSatisfierPropertyKind( SatisfierPropertyImpl::SatisfierPropertyKind_Type val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "DataType" among "DataType"s
	//********************************************************************************
	template <class T>
	std::set<DataType, T>		getDataType(TDP)
	{
		std::set<DataType, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("DataType");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			DataType elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "PackageConfigurationReference" among "PackageConfigurationReference"s
	//********************************************************************************
	template <class T>
	std::set<PackageConfigurationReference, T>		getPackageConfigurationReference(TDP)
	{
		std::set<PackageConfigurationReference, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("PackageConfigurationReference");
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
	template <class T>
	std::set<TopLevelPackage, T>		getTopLevelPackage(TDP)
	{
		std::set<TopLevelPackage, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("TopLevelPackage");
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
	template <class T>
	std::set<package, T>		getpackage(TDP)
	{
		std::set<package, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("package");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			package elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	// kind and role getters
	//********************************************************************************
	// getter for role "WorkerAction" among "WorkerAction"s
	//********************************************************************************
	template <class T>
	std::set<WorkerAction, T>		getWorkerAction(TDP)
	{
		std::set<WorkerAction, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("WorkerAction");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			WorkerAction elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   WorkerFileImpl
//*******************************************************************
class WorkerFileImpl :
	  virtual public BON::ModelImpl
{
public:

	//
	// attribute getters and setters
	virtual std::string getLocation() ;
	virtual void        setLocation( const std::string& val);
	//
	// kind and role getters
	//********************************************************************************
	// getter for role "Worker" among "Worker"s
	//********************************************************************************
	template <class T>
	std::set<Worker, T>		getWorker(TDP)
	{
		std::set<Worker, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Worker");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			Worker elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "WorkerFile" among "WorkerFile"s
	//********************************************************************************
	template <class T>
	std::set<WorkerFile, T>		getWorkerFile(TDP)
	{
		std::set<WorkerFile, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("WorkerFile");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			WorkerFile elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// getter for role "Worker" among "Worker"s
	//********************************************************************************
	template <class T>
	std::set<Worker, T>		getWorker(TDP)
	{
		std::set<Worker, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("Worker");
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
	template <class T>
	std::set<WorkerPackage, T>		getWorkerPackage(TDP)
	{
		std::set<WorkerPackage, T> res;
		std::set<BON::FCO> roles = getChildFCOsAs("WorkerPackage");
		for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
		{
			WorkerPackage elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
		return res;
	}


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
	//********************************************************************************
	// returns dst MetricsBases
	//********************************************************************************
	template <class T>
	std::multiset<MetricsBase, T>		getBenchmarkCharacteristicsDsts(TDP)
	{
		std::multiset<MetricsBase, T> res;
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
	template <class T>
	std::set<BenchmarkCharacteristics, T>		getOutBenchmarkCharacteristicsLinks(TDP)
	{
		std::set<BenchmarkCharacteristics, T> result;
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
//   C  L  A  S  S   ComponentPackageImpl
//*******************************************************************
class ComponentPackageImpl :
	  virtual public BON::AtomImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns dst ComponentImplementationReferences
	//********************************************************************************
	template <class T>
	std::multiset<ComponentImplementationReference, T>		getImplementationDsts(TDP)
	{
		std::multiset<ComponentImplementationReference, T> res;
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
	template <class T>
	std::set<PackageConfBasePackage, T>		getInPackageConfBasePackageLinks(TDP)
	{
		std::set<PackageConfBasePackage, T> result;
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
	template <class T>
	std::set<Implementation, T>		getOutImplementationLinks(TDP)
	{
		std::set<Implementation, T> result;
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
	template <class T>
	std::set<PackageConfigProperty, T>		getOutPackageConfigPropertyLinks(TDP)
	{
		std::set<PackageConfigProperty, T> result;
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
	template <class T>
	std::set<PackageInfoProperty, T>		getOutPackageInfoPropertyLinks(TDP)
	{
		std::set<PackageInfoProperty, T> result;
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
	template <class T>
	std::set<PackageInterface, T>		getOutPackageInterfaceLinks(TDP)
	{
		std::set<PackageInterface, T> result;
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
	template <class T>
	std::multiset<PackageConfiguration, T>		getPackageConfBasePackageSrcs(TDP)
	{
		std::multiset<PackageConfiguration, T> res;
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
	template <class T>
	std::multiset<Property, T>		getPackageConfigPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<Property, T>		getPackageInfoPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<ComponentRef, T>		getPackageInterfaceDsts(TDP)
	{
		std::multiset<ComponentRef, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<Include_RT_Info, T>		getInInclude_RT_InfoLinks(TDP)
	{
		std::set<Include_RT_Info, T> result;
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
	template <class T>
	std::multiset<RTEC_Filter_Group, T>		getInclude_RTEC_Filter_GroupDsts(TDP)
	{
		std::multiset<RTEC_Filter_Group, T> res;
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
	template <class T>
	std::multiset<RTEC_Filter_Group, T>		getInclude_RTEC_Filter_GroupEnds(TDP)
	{
		std::multiset<RTEC_Filter_Group, T> res;
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
	template <class T>
	std::set<Include_RTEC_Filter_Group, T>		getInclude_RTEC_Filter_GroupLinks(TDP)
	{
		std::set<Include_RTEC_Filter_Group, T> result;
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
	template <class T>
	std::multiset<RTEC_Filter_Group, T>		getInclude_RTEC_Filter_GroupSrcs(TDP)
	{
		std::multiset<RTEC_Filter_Group, T> res;
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
	template <class T>
	std::multiset<RT_Info_Param, T>		getInclude_RT_InfoSrcs(TDP)
	{
		std::multiset<RT_Info_Param, T> res;
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
	template <class T>
	std::set<Use_RTEC_Filter, T>		getOutUse_RTEC_FilterLinks(TDP)
	{
		std::set<Use_RTEC_Filter, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getUse_RTEC_FilterDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("Use_RTEC_Filter");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}


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
	//********************************************************************************
	// returns src GraphVertexs and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getDstEdgeSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("DstEdge");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<DstEdge, T>		getInDstEdgeLinks(TDP)
	{
		std::set<DstEdge, T> result;
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
	template <class T>
	std::set<PropertyConnector, T>		getInPropertyConnectorLinks(TDP)
	{
		std::set<PropertyConnector, T> result;
		std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
		std::set<BON::Connection>::iterator it = conns.begin();
		for( ; it != conns.end(); ++it)
		{
			PropertyConnector c( *it);
			if (c)
				result.insert( c);
		}
		return result;
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<SrcEdge, T>		getOutSrcEdgeLinks(TDP)
	{
		std::set<SrcEdge, T> result;
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
	// returns src Propertys
	//********************************************************************************
	template <class T>
	std::multiset<Property, T>		getPropertyConnectorSrcs(TDP)
	{
		std::multiset<Property, T> res;
		{
			std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("PropertyConnector");
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
	// returns dst GraphVertexs and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getSrcEdgeDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("SrcEdge");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}


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
	//********************************************************************************
	// returns src Components
	//********************************************************************************
	template <class T>
	std::multiset<Component, T>		getExternalDelegateSrcs(TDP)
	{
		std::multiset<Component, T> res;
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
	template <class T>
	std::set<ExternalDelegate, T>		getInExternalDelegateLinks(TDP)
	{
		std::set<ExternalDelegate, T> result;
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
	//********************************************************************************
	// returns dst ImplementationArtifacts
	//********************************************************************************
	template <class T>
	std::multiset<ImplementationArtifact, T>		getArtifactDependencyDsts(TDP)
	{
		std::multiset<ImplementationArtifact, T> res;
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
	template <class T>
	std::set<ArtifactDependency, T>		getArtifactDependencyLinks(TDP)
	{
		std::set<ArtifactDependency, T> result;
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
	template <class T>
	std::multiset<ImplementationArtifact, T>		getArtifactDependencySrcs(TDP)
	{
		std::multiset<ImplementationArtifact, T> res;
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
	template <class T>
	std::multiset<ImplementationArtifactReference, T>		getArtifactDependsOnDsts(TDP)
	{
		std::multiset<ImplementationArtifactReference, T> res;
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
	template <class T>
	std::multiset<Requirement, T>		getArtifactDeployRequirementDsts(TDP)
	{
		std::multiset<Requirement, T> res;
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
	template <class T>
	std::multiset<Property, T>		getArtifactExecParameterDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<Property, T>		getArtifactInfoPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::set<ArtifactDependency, T>		getInArtifactDependencyLinks(TDP)
	{
		std::set<ArtifactDependency, T> result;
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
	template <class T>
	std::set<ArtifactDependency, T>		getOutArtifactDependencyLinks(TDP)
	{
		std::set<ArtifactDependency, T> result;
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
	template <class T>
	std::set<ArtifactDependsOn, T>		getOutArtifactDependsOnLinks(TDP)
	{
		std::set<ArtifactDependsOn, T> result;
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
	template <class T>
	std::set<ArtifactDeployRequirement, T>		getOutArtifactDeployRequirementLinks(TDP)
	{
		std::set<ArtifactDeployRequirement, T> result;
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
	template <class T>
	std::set<ArtifactExecParameter, T>		getOutArtifactExecParameterLinks(TDP)
	{
		std::set<ArtifactExecParameter, T> result;
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
	template <class T>
	std::set<ArtifactInfoProperty, T>		getOutArtifactInfoPropertyLinks(TDP)
	{
		std::set<ArtifactInfoProperty, T> result;
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
	//********************************************************************************
	// returns src ComponentImplementations
	//********************************************************************************
	template <class T>
	std::multiset<ComponentImplementation, T>		getImplementationDependsOnSrcs(TDP)
	{
		std::multiset<ComponentImplementation, T> res;
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
	template <class T>
	std::set<ImplementationDependsOn, T>		getInImplementationDependsOnLinks(TDP)
	{
		std::set<ImplementationDependsOn, T> result;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<LabelConnection, T>		getInLabelConnectionLinks(TDP)
	{
		std::set<LabelConnection, T> result;
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
	template <class T>
	std::multiset<Member, T>		getLabelConnectionSrcs(TDP)
	{
		std::multiset<Member, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<RTEC_Connection, T>		getInRTEC_ConnectionLinks(TDP)
	{
		std::set<RTEC_Connection, T> result;
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
	template <class T>
	std::multiset<RTEC_Filter_Group, T>		getInclude_RT_InfoDsts(TDP)
	{
		std::multiset<RTEC_Filter_Group, T> res;
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
	template <class T>
	std::set<Include_RT_Info, T>		getOutInclude_RT_InfoLinks(TDP)
	{
		std::set<Include_RT_Info, T> result;
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
	template <class T>
	std::set<Use_RT_Info, T>		getOutUse_RT_InfoLinks(TDP)
	{
		std::set<Use_RT_Info, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getRTEC_ConnectionSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("RTEC_Connection");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns dst RTEC_Resource_Factory_References
	//********************************************************************************
	template <class T>
	std::multiset<RTEC_Resource_Factory_Reference, T>		getUse_RT_InfoDsts(TDP)
	{
		std::multiset<RTEC_Resource_Factory_Reference, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<PackageConfBasePackage, T>		getOutPackageConfBasePackageLinks(TDP)
	{
		std::set<PackageConfBasePackage, T> result;
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
	template <class T>
	std::set<PackageConfConfigProperty, T>		getOutPackageConfConfigPropertyLinks(TDP)
	{
		std::set<PackageConfConfigProperty, T> result;
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
	template <class T>
	std::set<PackageConfReference, T>		getOutPackageConfReferenceLinks(TDP)
	{
		std::set<PackageConfReference, T> result;
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
	template <class T>
	std::set<PackageConfSelectRequirement, T>		getOutPackageConfSelectRequirementLinks(TDP)
	{
		std::set<PackageConfSelectRequirement, T> result;
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
	template <class T>
	std::set<PackageConfSpecializedConfig, T>		getOutPackageConfSpecializedConfigLinks(TDP)
	{
		std::set<PackageConfSpecializedConfig, T> result;
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
	template <class T>
	std::multiset<ComponentPackage, T>		getPackageConfBasePackageDsts(TDP)
	{
		std::multiset<ComponentPackage, T> res;
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
	template <class T>
	std::multiset<Property, T>		getPackageConfConfigPropertyDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::multiset<ComponentPackageReference, T>		getPackageConfReferenceDsts(TDP)
	{
		std::multiset<ComponentPackageReference, T> res;
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
	template <class T>
	std::multiset<Requirement, T>		getPackageConfSelectRequirementDsts(TDP)
	{
		std::multiset<Requirement, T> res;
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
	template <class T>
	std::multiset<PackageConfigurationReference, T>		getPackageConfSpecializedConfigDsts(TDP)
	{
		std::multiset<PackageConfigurationReference, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<MakeMemberPrivate, T>		getInMakeMemberPrivateLinks(TDP)
	{
		std::set<MakeMemberPrivate, T> result;
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
	template <class T>
	std::multiset<Member, T>		getMakeMemberPrivateSrcs(TDP)
	{
		std::multiset<Member, T> res;
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
	//********************************************************************************
	// returns dst Requirements
	//********************************************************************************
	template <class T>
	std::multiset<Requirement, T>		getAssemblyDeployRequirementDsts(TDP)
	{
		std::multiset<Requirement, T> res;
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
	template <class T>
	std::set<publish, T>		getInpublishLinks(TDP)
	{
		std::set<publish, T> result;
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
	template <class T>
	std::set<AssemblyDeployRequirement, T>		getOutAssemblyDeployRequirementLinks(TDP)
	{
		std::set<AssemblyDeployRequirement, T> result;
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
	template <class T>
	std::set<deliverTo, T>		getOutdeliverToLinks(TDP)
	{
		std::set<deliverTo, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getdeliverToDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("deliverTo");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns src OutEventPorts and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getpublishSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("publish");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}


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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<QoSDimensionQualifier, T>		getInQoSDimensionQualifierLinks(TDP)
	{
		std::set<QoSDimensionQualifier, T> result;
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
	template <class T>
	std::multiset<QoSDimensionSlot, T>		getQoSDimensionQualifierSrcs(TDP)
	{
		std::multiset<QoSDimensionSlot, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<QoSDimensionQualifier, T>		getOutQoSDimensionQualifierLinks(TDP)
	{
		std::set<QoSDimensionQualifier, T> result;
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
	template <class T>
	std::multiset<QoSDimension, T>		getQoSDimensionQualifierDsts(TDP)
	{
		std::multiset<QoSDimension, T> res;
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
	//********************************************************************************
	// returns src ActionBases
	//********************************************************************************
	template <class T>
	std::multiset<ActionBase, T>		getEffectSrcs(TDP)
	{
		std::multiset<ActionBase, T> res;
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
	// returns dst InputActions
	//********************************************************************************
	template <class T>
	std::multiset<InputAction, T>		getFinishDsts(TDP)
	{
		std::multiset<InputAction, T> res;
		{
			std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Finish");
			for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
			{
				InputAction dst( *cit );
				ASSERT(dst);
				res.insert( dst);
			}
		}
		return res;
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<Effect, T>		getInEffectLinks(TDP)
	{
		std::set<Effect, T> result;
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
	template <class T>
	std::set<Finish, T>		getOutFinishLinks(TDP)
	{
		std::set<Finish, T> result;
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
	template <class T>
	std::set<Transition, T>		getOutTransitionLinks(TDP)
	{
		std::set<Transition, T> result;
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
	template <class T>
	std::multiset<ActionBase, T>		getTransitionDsts(TDP)
	{
		std::multiset<ActionBase, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<WorkLoadOperationConnection, T>		getInWorkLoadOperationConnectionLinks(TDP)
	{
		std::set<WorkLoadOperationConnection, T> result;
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
	template <class T>
	std::multiset<OperationRef, T>		getWorkLoadOperationConnectionSrcs(TDP)
	{
		std::multiset<OperationRef, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<TimerConnection, T>		getInTimerConnectionLinks(TDP)
	{
		std::set<TimerConnection, T> result;
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
	template <class T>
	std::set<TimerEventSinkConn, T>		getInTimerEventSinkConnLinks(TDP)
	{
		std::set<TimerEventSinkConn, T> result;
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
	template <class T>
	std::multiset<OperationRef, T>		getTimerConnectionSrcs(TDP)
	{
		std::multiset<OperationRef, T> res;
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
	template <class T>
	std::multiset<EventRef, T>		getTimerEventSinkConnSrcs(TDP)
	{
		std::multiset<EventRef, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<package, T>		getOutpackageLinks(TDP)
	{
		std::set<package, T> result;
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
	template <class T>
	std::multiset<PackageConfigurationReference, T>		getpackageDsts(TDP)
	{
		std::multiset<PackageConfigurationReference, T> res;
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
//   C  L  A  S  S   EffectImpl
//*******************************************************************
class EffectImpl :
	  virtual public BON::ConnectionImpl
{
public:

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
//   C  L  A  S  S   FinishImpl
//*******************************************************************
class FinishImpl :
	  virtual public BON::ConnectionImpl
{
public:

	//
	// connectionEnd getters
	virtual InputAction getDst();
	virtual State       getSrc();

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
	virtual InputAction getDst();
	virtual InPort      getSrc();

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
//   C  L  A  S  S   PropertyConnectorImpl
//*******************************************************************
class PropertyConnectorImpl :
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
	//********************************************************************************
	// returns dst NodeReferences
	//********************************************************************************
	template <class T>
	std::multiset<NodeReference, T>		getInstanceMappingDsts(TDP)
	{
		std::multiset<NodeReference, T> res;
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
	template <class T>
	std::set<InstanceMapping, T>		getOutInstanceMappingLinks(TDP)
	{
		std::set<InstanceMapping, T> result;
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

	//
	// set getters
	//********************************************************************************
	// aggregated getter for setmembers
	//********************************************************************************
	template <class T>
	std::set<BON::Reference>		getAllMembers(TDP)
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
	template <class T>
	std::set<ComponentAssemblyReference>		getComponentAssemblyReferences(TDP)
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
	template <class T>
	std::set<ComponentRef>		getComponentRefs(TDP)
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<WorkloadCharacteristics, T>		getInWorkloadCharacteristicsLinks(TDP)
	{
		std::set<WorkloadCharacteristics, T> result;
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
	template <class T>
	std::multiset<MetricsBase, T>		getWorkloadCharacteristicsSrcs(TDP)
	{
		std::multiset<MetricsBase, T> res;
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

	//
	// attribute getters and setters
	virtual long        getpriority() ;
	virtual long        getrate() ;
	virtual void        setpriority( const long val);
	virtual void        setrate( const long val);
	//
	// set getters
	//********************************************************************************
	// aggregated getter for setmembers
	//********************************************************************************
	template <class T>
	std::set<Task>		getTasks( int dummy, TDP)
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
	template <class T>
	std::set<Task>		getTasks(TDP)
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
	//********************************************************************************
	// aggregated getter for setmembers
	//********************************************************************************
	template <class T>
	std::set<Project>		getProjects( int dummy, TDP)
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
	template <class T>
	std::set<Project>		getProjects(TDP)
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
	//********************************************************************************
	// returns dst ReadonlyAttributes and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getAttributeDelegateDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("AttributeDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns dst AttributeMappings and referenceports
	//********************************************************************************
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getAttributeMappingDelegateDsts(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getOutConnEnds("AttributeMappingDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<AttributeMappingDelegate, T>		getAttributeMappingDelegateLinks(TDP)
	{
		std::set<AttributeMappingDelegate, T> result;
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
	template <class T>
	std::multiset<BON::ConnectionEnd, T>		getAttributeMappingDelegateSrcs(TDP)
	{
		std::multiset<BON::ConnectionEnd> ends = BON::ConnectionEndImpl::getInConnEnds("AttributeMappingDelegate");
		return std::multiset<BON::ConnectionEnd, T>( ends.begin(), ends.end());
	}

	//********************************************************************************
	// returns dst Propertys
	//********************************************************************************
	template <class T>
	std::multiset<Property, T>		getAttributeMappingValueDsts(TDP)
	{
		std::multiset<Property, T> res;
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
	template <class T>
	std::set<AttributeMappingDelegate, T>		getInAttributeMappingDelegateLinks(TDP)
	{
		std::set<AttributeMappingDelegate, T> result;
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
	template <class T>
	std::set<AttributeDelegate, T>		getOutAttributeDelegateLinks(TDP)
	{
		std::set<AttributeDelegate, T> result;
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
	template <class T>
	std::set<AttributeMappingDelegate, T>		getOutAttributeMappingDelegateLinks(TDP)
	{
		std::set<AttributeMappingDelegate, T> result;
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
	template <class T>
	std::set<AttributeMappingValue, T>		getOutAttributeMappingValueLinks(TDP)
	{
		std::set<AttributeMappingValue, T> result;
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
//   C  L  A  S  S   CompRefImpl
//*******************************************************************
class CompRefImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns src OperationRefs
	//********************************************************************************
	template <class T>
	std::multiset<OperationRef, T>		getComponentOperationSrcs(TDP)
	{
		std::multiset<OperationRef, T> res;
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
	template <class T>
	std::set<ComponentOperation, T>		getInComponentOperationLinks(TDP)
	{
		std::set<ComponentOperation, T> result;
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

	//
	// ref getters
	virtual Component   getComponent();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ComponentAssemblyReferenceImpl
//*******************************************************************
class ComponentAssemblyReferenceImpl :
	  virtual public BON::ReferenceImpl
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
//   C  L  A  S  S   ComponentImplementationReferenceImpl
//*******************************************************************
class ComponentImplementationReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:

	//
	// connectionEnd getters
	//********************************************************************************
	// returns src ComponentPackages
	//********************************************************************************
	template <class T>
	std::multiset<ComponentPackage, T>		getImplementationSrcs(TDP)
	{
		std::multiset<ComponentPackage, T> res;
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
	template <class T>
	std::set<Implementation, T>		getInImplementationLinks(TDP)
	{
		std::set<Implementation, T> result;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<PackageConfReference, T>		getInPackageConfReferenceLinks(TDP)
	{
		std::set<PackageConfReference, T> result;
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
	template <class T>
	std::multiset<PackageConfiguration, T>		getPackageConfReferenceSrcs(TDP)
	{
		std::multiset<PackageConfiguration, T> res;
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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<TimerEventSinkConn, T>		getOutTimerEventSinkConnLinks(TDP)
	{
		std::set<TimerEventSinkConn, T> result;
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
	template <class T>
	std::multiset<TimeProbe, T>		getTimerEventSinkConnDsts(TDP)
	{
		std::multiset<TimeProbe, T> res;
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
	//********************************************************************************
	// returns src ComponentLibs
	//********************************************************************************
	template <class T>
	std::multiset<ComponentLib, T>		getExtResourceConnSrcs(TDP)
	{
		std::multiset<ComponentLib, T> res;
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
	template <class T>
	std::set<ExtResourceConn, T>		getInExtResourceConnLinks(TDP)
	{
		std::set<ExtResourceConn, T> result;
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

	//
	// ref getters
	virtual ImplementationArtifact          getImplementationArtifact();

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
	//********************************************************************************
	// returns src ImplementationArtifacts
	//********************************************************************************
	template <class T>
	std::multiset<ImplementationArtifact, T>		getArtifactDependsOnSrcs(TDP)
	{
		std::multiset<ImplementationArtifact, T> res;
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
	template <class T>
	std::set<ArtifactDependsOn, T>		getInArtifactDependsOnLinks(TDP)
	{
		std::set<ArtifactDependsOn, T> result;
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
	template <class T>
	std::set<MonolithprimaryArtifact, T>		getInMonolithprimaryArtifactLinks(TDP)
	{
		std::set<MonolithprimaryArtifact, T> result;
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
	template <class T>
	std::multiset<MonolithicImplementation, T>		getMonolithprimaryArtifactSrcs(TDP)
	{
		std::multiset<MonolithicImplementation, T> res;
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
	//********************************************************************************
	// returns dst Labels
	//********************************************************************************
	template <class T>
	std::multiset<Label, T>		getLabelConnectionDsts(TDP)
	{
		std::multiset<Label, T> res;
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
	template <class T>
	std::multiset<PrivateFlag, T>		getMakeMemberPrivateDsts(TDP)
	{
		std::multiset<PrivateFlag, T> res;
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
	template <class T>
	std::set<LabelConnection, T>		getOutLabelConnectionLinks(TDP)
	{
		std::set<LabelConnection, T> result;
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
	template <class T>
	std::set<MakeMemberPrivate, T>		getOutMakeMemberPrivateLinks(TDP)
	{
		std::set<MakeMemberPrivate, T> result;
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

	//
	// ref getters
	virtual MemberType  getMemberType();

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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<InstanceMapping, T>		getInInstanceMappingLinks(TDP)
	{
		std::set<InstanceMapping, T> result;
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
	template <class T>
	std::multiset<CollocationGroup, T>		getInstanceMappingSrcs(TDP)
	{
		std::multiset<CollocationGroup, T> res;
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
	//********************************************************************************
	// returns dst CompRefs
	//********************************************************************************
	template <class T>
	std::multiset<CompRef, T>		getComponentOperationDsts(TDP)
	{
		std::multiset<CompRef, T> res;
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
	template <class T>
	std::multiset<MetricsBase, T>		getMetricConnectionDsts(TDP)
	{
		std::multiset<MetricsBase, T> res;
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
	template <class T>
	std::set<ComponentOperation, T>		getOutComponentOperationLinks(TDP)
	{
		std::set<ComponentOperation, T> result;
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
	template <class T>
	std::set<MetricConnection, T>		getOutMetricConnectionLinks(TDP)
	{
		std::set<MetricConnection, T> result;
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
	template <class T>
	std::set<TimerConnection, T>		getOutTimerConnectionLinks(TDP)
	{
		std::set<TimerConnection, T> result;
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
	template <class T>
	std::set<WorkLoadOperationConnection, T>		getOutWorkLoadOperationConnectionLinks(TDP)
	{
		std::set<WorkLoadOperationConnection, T> result;
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
	template <class T>
	std::multiset<TimeProbe, T>		getTimerConnectionDsts(TDP)
	{
		std::multiset<TimeProbe, T> res;
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
	template <class T>
	std::multiset<Task, T>		getWorkLoadOperationConnectionDsts(TDP)
	{
		std::multiset<Task, T> res;
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

	//
	// ref getters
	virtual OperationBase                   getOperationBase();

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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<PackageConfSpecializedConfig, T>		getInPackageConfSpecializedConfigLinks(TDP)
	{
		std::set<PackageConfSpecializedConfig, T> result;
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
	template <class T>
	std::set<package, T>		getInpackageLinks(TDP)
	{
		std::set<package, T> result;
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
	template <class T>
	std::multiset<PackageConfiguration, T>		getPackageConfSpecializedConfigSrcs(TDP)
	{
		std::multiset<PackageConfiguration, T> res;
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
	template <class T>
	std::multiset<TopLevelPackage, T>		getpackageSrcs(TDP)
	{
		std::multiset<TopLevelPackage, T> res;
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

	//
	// ref getters
	virtual PackageConfiguration            getPackageConfiguration();

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
	//********************************************************************************
	// 
	//********************************************************************************
	template <class T>
	std::set<Use_RT_Info, T>		getInUse_RT_InfoLinks(TDP)
	{
		std::set<Use_RT_Info, T> result;
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
	template <class T>
	std::multiset<RT_Info_Param, T>		getUse_RT_InfoSrcs(TDP)
	{
		std::multiset<RT_Info_Param, T> res;
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



}; // namespace PICML_BON

///BUP
// add your additional class definitions here
///EUP

#endif // PICMLBONX_H
