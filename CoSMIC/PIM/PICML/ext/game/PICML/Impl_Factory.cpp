// $Id$

#include "stdafx.h"
#include "Impl_Factory.h"

#include "game/mga/Functional_T.h"
#include "game/mga/Exception.h"

#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementations.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "PICML/RealTimeRequirements/ServiceConsumer.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/PathDiagram/PathReference.h"
#include "PICML/PredefinedTypes/UnsignedShortInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongLongInteger.h"
#include "PICML/PredefinedTypes/LongLongInteger.h"
#include "PICML/TargetElements/SharedResource.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/PredefinedTypes/LongDoubleNumber.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/PredefinedTypes/DoubleNumber.h"
#include "PICML/PredefinedTypes/TypeKind.h"
#include "PICML/PredefinedTypes/TypeEncoding.h"
#include "PICML/PredefinedTypes/GenericValue.h"
#include "PICML/PredefinedTypes/GenericValueObject.h"
#include "PICML/PredefinedTypes/GenericObject.h"
#include "PICML/PredefinedTypes/String.h"
#include "PICML/PredefinedTypes/FloatNumber.h"
#include "PICML/PredefinedTypes/LongInteger.h"
#include "PICML/PredefinedTypes/ShortInteger.h"
#include "PICML/PredefinedTypes/Boolean.h"
#include "PICML/PredefinedTypes/Byte.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/EventChannelRequirements/ECBehavior.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInput.h"
#include "PICML/DeploymentPlan/ComponentInstanceRef.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackage.h"
#include "PICML/DeploymentPlan/ComponentFactoryRef.h"
#include "PICML/InheritableTypes/AttributeMember.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "PICML/InheritableTypes/PrivateFlag.h"
#include "PICML/InheritableTypes/GetException.h"
#include "PICML/InheritableTypes/SetException.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InheritableTypes/Supports.h"
#include "PICML/RealTimeRequirements/ServiceLevels.h"
#include "PICML/RealTimeRequirements/MultipleServiceRequests.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/Inherits.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/TargetElements/Resource.h"
#include "PICML/Domain/Targets.h"
#include "PICML/OperationTypes/ReturnType.h"
#include "PICML/OperationTypes/OutParameter.h"
#include "PICML/OperationTypes/InoutParameter.h"
#include "PICML/OperationTypes/InParameter.h"
#include "PICML/OperationTypes/LookupOperation.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/OperationTypes/ExceptionRef.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/PathDiagram/DisplayNode.h"
#include "PICML/OperationTypes/OnewayOperation.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
#include "PICML/DeploymentPlan/DeploymentPlans.h"
#include "PICML/TopLevelPackageDescription/package.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/DeploymentPlan/PropertyMapping.h"
#include "PICML/NamedTypes/Key.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/Variable.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/ComponentBuild/Workspaces.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/ApplicationTask.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/NamedTypes/Discriminator.h"
#include "PICML/ImplementationArtifact/ImplementationArtifacts.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/NamedTypes/LabelConnection.h"
#include "PICML/NamedTypes/Label.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/EnumValue.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/ComponentBuild/ExecutorProject.h"
#include "PICML/ComponentBuild/ServantProject.h"
#include "PICML/ComponentBuild/StubProject.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackages.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/ImplementationArtifact/ArtifactInfoProperty.h"
#include "PICML/ImplementationArtifact/ArtifactExecParameter.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ArtifactDeployRequirement.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"
#include "PICML/Domain/Shares.h"
#include "PICML/ComponentBenchmark/PeriodicBenchmarks.h"
#include "PICML/ComponentBenchmark/FixedIterationBenchmarks.h"
#include "PICML/ComponentBenchmark/TriggerBenchmarks.h"
#include "PICML/Domain/BridgeConnection.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/CompRef.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBuild/MPC.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/Task.h"
#include "PICML/ComponentBenchmark/TaskSet.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/DoWhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/ForState.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/ComponentBenchmark/EventRef.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/ComponentAnalyses.h"
#include "PICML/ComponentBenchmark/Throughput.h"
#include "PICML/ComponentBenchmark/Latency.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"
#include "PICML/Domain/InterconnectConnection.h"
#include "PICML/ComponentBenchmark/Jitter.h"
#include "PICML/ComponentBenchmark/Maximum.h"
#include "PICML/ComponentBenchmark/Minimum.h"
#include "PICML/ComponentBenchmark/Average.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/PackageConfiguration/PackageConfSelectRequirement.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurations.h"
#include "PICML/PackageConfiguration/PackageConfReference.h"
#include "PICML/PackageConfiguration/PackageConfBasePackage.h"
#include "PICML/WorkloadParadigmSheets/WML/Worker.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/Common/SatisfierProperty.h"
#include "PICML/Common/ImplementationDependency.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/Common/Requirement.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/Environment.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/PeriodicEvent.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorImplementationType.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/WhileState.h"
#include "PICML/InterfaceDefinition/NativeValue.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/Common/DataType.h"
#include "PICML/Common/Capability.h"
#include "PICML/InterfaceDefinition/TemplateParameterValue.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/PackageType.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorInherits.h"
#include "PICML/InterfaceDefinition/InterfaceDefinitions.h"
#include "PICML/Common/DataValue.h"
#include "PICML/Common/ComplexTypeReference.h"
#include "PICML/Common/DataValueContainer.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/InterfaceDefinition/FileRef.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackage.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibrary.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssemblyReference.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/WorkerType.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentConfigProperty.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigProperty.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ExternalPort.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/CriticalPath.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ExtendedPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementations.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentProperty.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/OutputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/MirrorPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/OutEventPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorType.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentInfoProperty.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToFacet.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Publish.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/Input.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ConnectorToReceptacle.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementations.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortDelegate.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInput.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Consume.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionType.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/RequestAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryAction.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentPropertyDescription.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentTypes.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeValue.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibraries.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyselectRequirement.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Invoke.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/InEventPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentType/LookupKey.h"
#include "PICML/ComponentParadigmSheets/ComponentType/MirrorPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentInherits.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/RequiredRequestPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstanceType.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ProvidedRequestPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/PathDiagrams.h"
#include "PICML/BehaviorParadigmSheets/Terminals/TerminalTransition.h"
#include "PICML/ImplementationArtifact/ArtifactDependency.h"
#include "PICML/ComponentBuild/ExternalResources.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ComponentBuild.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerFile.h"
#include "PICML/ComponentPackage/PackageInfoProperty.h"
#include "PICML/ComponentPackage/PackageConfigProperty.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/EventChannelRequirements/ECRole.h"
#include "PICML/ComponentPackage/Implementation.h"
#include "PICML/ComponentPackage/PackageInterface.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplements.h"
#include "PICML/ComponentPackage/ComponentPackages.h"
#include "PICML/RealTimeRequirements/ServiceProvider.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"
#include "PICML/ImplementationCommon/InfoProperty.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"
#include "PICML/BehaviorParadigmSheets/Terminals/Terminal.h"
#include "PICML/Domain/Domain.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"

namespace PICML
{
  //
  // Impl_Factory
  //
  Impl_Factory::Impl_Factory (void)
  {
    this->map_.bind ("ComponentFactoryImplementations", &::GAME::Mga::allocate_impl <ComponentFactoryImplementations_Impl>);
    this->map_.bind ("ComponentPackageReference", &::GAME::Mga::allocate_impl <ComponentPackageReference_Impl>);
    this->map_.bind ("PathProperty", &::GAME::Mga::allocate_impl <PathProperty_Impl>);
    this->map_.bind ("ServiceConsumer", &::GAME::Mga::allocate_impl <ServiceConsumer_Impl>);
    this->map_.bind ("Char", &::GAME::Mga::allocate_impl <Char_Impl>);
    this->map_.bind ("WideString", &::GAME::Mga::allocate_impl <WideString_Impl>);
    this->map_.bind ("WideChar", &::GAME::Mga::allocate_impl <WideChar_Impl>);
    this->map_.bind ("Effect", &::GAME::Mga::allocate_impl <Effect_Impl>);
    this->map_.bind ("PathReference", &::GAME::Mga::allocate_impl <PathReference_Impl>);
    this->map_.bind ("UnsignedShortInteger", &::GAME::Mga::allocate_impl <UnsignedShortInteger_Impl>);
    this->map_.bind ("UnsignedLongInteger", &::GAME::Mga::allocate_impl <UnsignedLongInteger_Impl>);
    this->map_.bind ("UnsignedLongLongInteger", &::GAME::Mga::allocate_impl <UnsignedLongLongInteger_Impl>);
    this->map_.bind ("LongLongInteger", &::GAME::Mga::allocate_impl <LongLongInteger_Impl>);
    this->map_.bind ("SharedResource", &::GAME::Mga::allocate_impl <SharedResource_Impl>);
    this->map_.bind ("NodeReference", &::GAME::Mga::allocate_impl <NodeReference_Impl>);
    this->map_.bind ("Node", &::GAME::Mga::allocate_impl <Node_Impl>);
    this->map_.bind ("LongDoubleNumber", &::GAME::Mga::allocate_impl <LongDoubleNumber_Impl>);
    this->map_.bind ("ComponentFactoryInstance", &::GAME::Mga::allocate_impl <ComponentFactoryInstance_Impl>);
    this->map_.bind ("DoubleNumber", &::GAME::Mga::allocate_impl <DoubleNumber_Impl>);
    this->map_.bind ("TypeKind", &::GAME::Mga::allocate_impl <TypeKind_Impl>);
    this->map_.bind ("TypeEncoding", &::GAME::Mga::allocate_impl <TypeEncoding_Impl>);
    this->map_.bind ("GenericValue", &::GAME::Mga::allocate_impl <GenericValue_Impl>);
    this->map_.bind ("GenericValueObject", &::GAME::Mga::allocate_impl <GenericValueObject_Impl>);
    this->map_.bind ("GenericObject", &::GAME::Mga::allocate_impl <GenericObject_Impl>);
    this->map_.bind ("String", &::GAME::Mga::allocate_impl <String_Impl>);
    this->map_.bind ("FloatNumber", &::GAME::Mga::allocate_impl <FloatNumber_Impl>);
    this->map_.bind ("LongInteger", &::GAME::Mga::allocate_impl <LongInteger_Impl>);
    this->map_.bind ("ShortInteger", &::GAME::Mga::allocate_impl <ShortInteger_Impl>);
    this->map_.bind ("Boolean", &::GAME::Mga::allocate_impl <Boolean_Impl>);
    this->map_.bind ("Byte", &::GAME::Mga::allocate_impl <Byte_Impl>);
    this->map_.bind ("TopLevelPackageContainer", &::GAME::Mga::allocate_impl <TopLevelPackageContainer_Impl>);
    this->map_.bind ("PredefinedTypes", &::GAME::Mga::allocate_impl <PredefinedTypes_Impl>);
    this->map_.bind ("ECRequirements", &::GAME::Mga::allocate_impl <ECRequirements_Impl>);
    this->map_.bind ("ECBehavior", &::GAME::Mga::allocate_impl <ECBehavior_Impl>);
    this->map_.bind ("QueryInput", &::GAME::Mga::allocate_impl <QueryInput_Impl>);
    this->map_.bind ("ComponentInstanceRef", &::GAME::Mga::allocate_impl <ComponentInstanceRef_Impl>);
    this->map_.bind ("Deploys", &::GAME::Mga::allocate_impl <Deploys_Impl>);
    this->map_.bind ("TopLevelPackage", &::GAME::Mga::allocate_impl <TopLevelPackage_Impl>);
    this->map_.bind ("ComponentFactoryRef", &::GAME::Mga::allocate_impl <ComponentFactoryRef_Impl>);
    this->map_.bind ("AttributeMember", &::GAME::Mga::allocate_impl <AttributeMember_Impl>);
    this->map_.bind ("MakeMemberPrivate", &::GAME::Mga::allocate_impl <MakeMemberPrivate_Impl>);
    this->map_.bind ("PrivateFlag", &::GAME::Mga::allocate_impl <PrivateFlag_Impl>);
    this->map_.bind ("GetException", &::GAME::Mga::allocate_impl <GetException_Impl>);
    this->map_.bind ("SetException", &::GAME::Mga::allocate_impl <SetException_Impl>);
    this->map_.bind ("ComponentFactoryImplementationContainer", &::GAME::Mga::allocate_impl <ComponentFactoryImplementationContainer_Impl>);
    this->map_.bind ("Attribute", &::GAME::Mga::allocate_impl <Attribute_Impl>);
    this->map_.bind ("ReadonlyAttribute", &::GAME::Mga::allocate_impl <ReadonlyAttribute_Impl>);
    this->map_.bind ("Supports", &::GAME::Mga::allocate_impl <Supports_Impl>);
    this->map_.bind ("ServiceLevels", &::GAME::Mga::allocate_impl <ServiceLevels_Impl>);
    this->map_.bind ("MultipleServiceRequests", &::GAME::Mga::allocate_impl <MultipleServiceRequests_Impl>);
    this->map_.bind ("ValueObject", &::GAME::Mga::allocate_impl <ValueObject_Impl>);
    this->map_.bind ("Event", &::GAME::Mga::allocate_impl <Event_Impl>);
    this->map_.bind ("Inherits", &::GAME::Mga::allocate_impl <Inherits_Impl>);
    this->map_.bind ("Object", &::GAME::Mga::allocate_impl <Object_Impl>);
    this->map_.bind ("RTRequirements", &::GAME::Mga::allocate_impl <RTRequirements_Impl>);
    this->map_.bind ("Resource", &::GAME::Mga::allocate_impl <Resource_Impl>);
    this->map_.bind ("Targets", &::GAME::Mga::allocate_impl <Targets_Impl>);
    this->map_.bind ("ReturnType", &::GAME::Mga::allocate_impl <ReturnType_Impl>);
    this->map_.bind ("OutParameter", &::GAME::Mga::allocate_impl <OutParameter_Impl>);
    this->map_.bind ("InoutParameter", &::GAME::Mga::allocate_impl <InoutParameter_Impl>);
    this->map_.bind ("InParameter", &::GAME::Mga::allocate_impl <InParameter_Impl>);
    this->map_.bind ("LookupOperation", &::GAME::Mga::allocate_impl <LookupOperation_Impl>);
    this->map_.bind ("ConnectorImplementationContainer", &::GAME::Mga::allocate_impl <ConnectorImplementationContainer_Impl>);
    this->map_.bind ("ExceptionRef", &::GAME::Mga::allocate_impl <ExceptionRef_Impl>);
    this->map_.bind ("Paths", &::GAME::Mga::allocate_impl <Paths_Impl>);
    this->map_.bind ("DisplayNode", &::GAME::Mga::allocate_impl <DisplayNode_Impl>);
    this->map_.bind ("OnewayOperation", &::GAME::Mga::allocate_impl <OnewayOperation_Impl>);
    this->map_.bind ("TwowayOperation", &::GAME::Mga::allocate_impl <TwowayOperation_Impl>);
    this->map_.bind ("FactoryOperation", &::GAME::Mga::allocate_impl <FactoryOperation_Impl>);
    this->map_.bind ("CollocationGroup", &::GAME::Mga::allocate_impl <CollocationGroup_Impl>);
    this->map_.bind ("DeploymentPlans", &::GAME::Mga::allocate_impl <DeploymentPlans_Impl>);
    this->map_.bind ("package", &::GAME::Mga::allocate_impl <package_Impl>);
    this->map_.bind ("InstanceMapping", &::GAME::Mga::allocate_impl <InstanceMapping_Impl>);
    this->map_.bind ("DeploymentPlan", &::GAME::Mga::allocate_impl <DeploymentPlan_Impl>);
    this->map_.bind ("PackageConfiguration", &::GAME::Mga::allocate_impl <PackageConfiguration_Impl>);
    this->map_.bind ("ComponentImplementationArtifact", &::GAME::Mga::allocate_impl <ComponentImplementationArtifact_Impl>);
    this->map_.bind ("ComponentServantArtifact", &::GAME::Mga::allocate_impl <ComponentServantArtifact_Impl>);
    this->map_.bind ("ComplexProperty", &::GAME::Mga::allocate_impl <ComplexProperty_Impl>);
    this->map_.bind ("SimpleProperty", &::GAME::Mga::allocate_impl <SimpleProperty_Impl>);
    this->map_.bind ("CollocationGroupProperty", &::GAME::Mga::allocate_impl <CollocationGroupProperty_Impl>);
    this->map_.bind ("PropertyMapping", &::GAME::Mga::allocate_impl <PropertyMapping_Impl>);
    this->map_.bind ("Key", &::GAME::Mga::allocate_impl <Key_Impl>);
    this->map_.bind ("Variable", &::GAME::Mga::allocate_impl <Variable_Impl>);
    this->map_.bind ("KeyMember", &::GAME::Mga::allocate_impl <KeyMember_Impl>);
    this->map_.bind ("Workspaces", &::GAME::Mga::allocate_impl <Workspaces_Impl>);
    this->map_.bind ("ArrayMember", &::GAME::Mga::allocate_impl <ArrayMember_Impl>);
    this->map_.bind ("Edge", &::GAME::Mga::allocate_impl <Edge_Impl>);
    this->map_.bind ("EdgeProperty", &::GAME::Mga::allocate_impl <EdgeProperty_Impl>);
    this->map_.bind ("ApplicationTask", &::GAME::Mga::allocate_impl <ApplicationTask_Impl>);
    this->map_.bind ("SrcEdge", &::GAME::Mga::allocate_impl <SrcEdge_Impl>);
    this->map_.bind ("Boxed", &::GAME::Mga::allocate_impl <Boxed_Impl>);
    this->map_.bind ("Alias", &::GAME::Mga::allocate_impl <Alias_Impl>);
    this->map_.bind ("Collection", &::GAME::Mga::allocate_impl <Collection_Impl>);
    this->map_.bind ("Discriminator", &::GAME::Mga::allocate_impl <Discriminator_Impl>);
    this->map_.bind ("ImplementationArtifacts", &::GAME::Mga::allocate_impl <ImplementationArtifacts_Impl>);
    this->map_.bind ("ImplementationArtifactReference", &::GAME::Mga::allocate_impl <ImplementationArtifactReference_Impl>);
    this->map_.bind ("ImplementationArtifact", &::GAME::Mga::allocate_impl <ImplementationArtifact_Impl>);
    this->map_.bind ("LabelConnection", &::GAME::Mga::allocate_impl <LabelConnection_Impl>);
    this->map_.bind ("Label", &::GAME::Mga::allocate_impl <Label_Impl>);
    this->map_.bind ("SwitchedAggregate", &::GAME::Mga::allocate_impl <SwitchedAggregate_Impl>);
    this->map_.bind ("Aggregate", &::GAME::Mga::allocate_impl <Aggregate_Impl>);
    this->map_.bind ("EnumValue", &::GAME::Mga::allocate_impl <EnumValue_Impl>);
    this->map_.bind ("Enum", &::GAME::Mga::allocate_impl <Enum_Impl>);
    this->map_.bind ("Path", &::GAME::Mga::allocate_impl <Path_Impl>);
    this->map_.bind ("ConnectedComponent", &::GAME::Mga::allocate_impl <ConnectedComponent_Impl>);
    this->map_.bind ("ExecutorProject", &::GAME::Mga::allocate_impl <ExecutorProject_Impl>);
    this->map_.bind ("ServantProject", &::GAME::Mga::allocate_impl <ServantProject_Impl>);
    this->map_.bind ("StubProject", &::GAME::Mga::allocate_impl <StubProject_Impl>);
    this->map_.bind ("TopLevelPackages", &::GAME::Mga::allocate_impl <TopLevelPackages_Impl>);
    this->map_.bind ("Member", &::GAME::Mga::allocate_impl <Member_Impl>);
    this->map_.bind ("ArtifactInfoProperty", &::GAME::Mga::allocate_impl <ArtifactInfoProperty_Impl>);
    this->map_.bind ("ArtifactExecParameter", &::GAME::Mga::allocate_impl <ArtifactExecParameter_Impl>);
    this->map_.bind ("ArtifactContainer", &::GAME::Mga::allocate_impl <ArtifactContainer_Impl>);
    this->map_.bind ("ArtifactDeployRequirement", &::GAME::Mga::allocate_impl <ArtifactDeployRequirement_Impl>);
    this->map_.bind ("ArtifactDependsOn", &::GAME::Mga::allocate_impl <ArtifactDependsOn_Impl>);
    this->map_.bind ("BenchmarkCharacteristics", &::GAME::Mga::allocate_impl <BenchmarkCharacteristics_Impl>);
    this->map_.bind ("Shares", &::GAME::Mga::allocate_impl <Shares_Impl>);
    this->map_.bind ("PeriodicBenchmarks", &::GAME::Mga::allocate_impl <PeriodicBenchmarks_Impl>);
    this->map_.bind ("FixedIterationBenchmarks", &::GAME::Mga::allocate_impl <FixedIterationBenchmarks_Impl>);
    this->map_.bind ("TriggerBenchmarks", &::GAME::Mga::allocate_impl <TriggerBenchmarks_Impl>);
    this->map_.bind ("BridgeConnection", &::GAME::Mga::allocate_impl <BridgeConnection_Impl>);
    this->map_.bind ("WorkLoadOperationConnection", &::GAME::Mga::allocate_impl <WorkLoadOperationConnection_Impl>);
    this->map_.bind ("CompRef", &::GAME::Mga::allocate_impl <CompRef_Impl>);
    this->map_.bind ("ComponentOperation", &::GAME::Mga::allocate_impl <ComponentOperation_Impl>);
    this->map_.bind ("MPC", &::GAME::Mga::allocate_impl <MPC_Impl>);
    this->map_.bind ("ExtResourceConn", &::GAME::Mga::allocate_impl <ExtResourceConn_Impl>);
    this->map_.bind ("WorkloadCharacteristics", &::GAME::Mga::allocate_impl <WorkloadCharacteristics_Impl>);
    this->map_.bind ("Task", &::GAME::Mga::allocate_impl <Task_Impl>);
    this->map_.bind ("TaskSet", &::GAME::Mga::allocate_impl <TaskSet_Impl>);
    this->map_.bind ("DoWhileState", &::GAME::Mga::allocate_impl <DoWhileState_Impl>);
    this->map_.bind ("ForState", &::GAME::Mga::allocate_impl <ForState_Impl>);
    this->map_.bind ("TimerEventSinkConn", &::GAME::Mga::allocate_impl <TimerEventSinkConn_Impl>);
    this->map_.bind ("EventRef", &::GAME::Mga::allocate_impl <EventRef_Impl>);
    this->map_.bind ("OperationRef", &::GAME::Mga::allocate_impl <OperationRef_Impl>);
    this->map_.bind ("BenchmarkAnalysis", &::GAME::Mga::allocate_impl <BenchmarkAnalysis_Impl>);
    this->map_.bind ("ComponentAnalyses", &::GAME::Mga::allocate_impl <ComponentAnalyses_Impl>);
    this->map_.bind ("Throughput", &::GAME::Mga::allocate_impl <Throughput_Impl>);
    this->map_.bind ("Latency", &::GAME::Mga::allocate_impl <Latency_Impl>);
    this->map_.bind ("TimerConnection", &::GAME::Mga::allocate_impl <TimerConnection_Impl>);
    this->map_.bind ("TimeProbe", &::GAME::Mga::allocate_impl <TimeProbe_Impl>);
    this->map_.bind ("InterconnectConnection", &::GAME::Mga::allocate_impl <InterconnectConnection_Impl>);
    this->map_.bind ("Jitter", &::GAME::Mga::allocate_impl <Jitter_Impl>);
    this->map_.bind ("Maximum", &::GAME::Mga::allocate_impl <Maximum_Impl>);
    this->map_.bind ("Minimum", &::GAME::Mga::allocate_impl <Minimum_Impl>);
    this->map_.bind ("Average", &::GAME::Mga::allocate_impl <Average_Impl>);
    this->map_.bind ("MetricConnection", &::GAME::Mga::allocate_impl <MetricConnection_Impl>);
    this->map_.bind ("PackageConfSelectRequirement", &::GAME::Mga::allocate_impl <PackageConfSelectRequirement_Impl>);
    this->map_.bind ("PackageConfConfigProperty", &::GAME::Mga::allocate_impl <PackageConfConfigProperty_Impl>);
    this->map_.bind ("ConnectorImplementation", &::GAME::Mga::allocate_impl <ConnectorImplementation_Impl>);
    this->map_.bind ("PackageConfigurationContainer", &::GAME::Mga::allocate_impl <PackageConfigurationContainer_Impl>);
    this->map_.bind ("PackageConfigurations", &::GAME::Mga::allocate_impl <PackageConfigurations_Impl>);
    this->map_.bind ("PackageConfReference", &::GAME::Mga::allocate_impl <PackageConfReference_Impl>);
    this->map_.bind ("PackageConfBasePackage", &::GAME::Mga::allocate_impl <PackageConfBasePackage_Impl>);
    this->map_.bind ("Worker", &::GAME::Mga::allocate_impl <Worker_Impl>);
    this->map_.bind ("Operation", &::GAME::Mga::allocate_impl <Operation_Impl>);
    this->map_.bind ("PackageConfigurationReference", &::GAME::Mga::allocate_impl <PackageConfigurationReference_Impl>);
    this->map_.bind ("ConnectorInstance", &::GAME::Mga::allocate_impl <ConnectorInstance_Impl>);
    this->map_.bind ("SatisfierProperty", &::GAME::Mga::allocate_impl <SatisfierProperty_Impl>);
    this->map_.bind ("ImplementationDependency", &::GAME::Mga::allocate_impl <ImplementationDependency_Impl>);
    this->map_.bind ("ImplementationRequirement", &::GAME::Mga::allocate_impl <ImplementationRequirement_Impl>);
    this->map_.bind ("Requirement", &::GAME::Mga::allocate_impl <Requirement_Impl>);
    this->map_.bind ("Environment", &::GAME::Mga::allocate_impl <Environment_Impl>);
    this->map_.bind ("State", &::GAME::Mga::allocate_impl <State_Impl>);
    this->map_.bind ("PeriodicEvent", &::GAME::Mga::allocate_impl <PeriodicEvent_Impl>);
    this->map_.bind ("ConnectorImplementationType", &::GAME::Mga::allocate_impl <ConnectorImplementationType_Impl>);
    this->map_.bind ("WhileState", &::GAME::Mga::allocate_impl <WhileState_Impl>);
    this->map_.bind ("NativeValue", &::GAME::Mga::allocate_impl <NativeValue_Impl>);
    this->map_.bind ("TypeParameter", &::GAME::Mga::allocate_impl <TypeParameter_Impl>);
    this->map_.bind ("DataType", &::GAME::Mga::allocate_impl <DataType_Impl>);
    this->map_.bind ("Capability", &::GAME::Mga::allocate_impl <Capability_Impl>);
    this->map_.bind ("TemplateParameterValue", &::GAME::Mga::allocate_impl <TemplateParameterValue_Impl>);
    this->map_.bind ("TemplatePackageInstance", &::GAME::Mga::allocate_impl <TemplatePackageInstance_Impl>);
    this->map_.bind ("PackageType", &::GAME::Mga::allocate_impl <PackageType_Impl>);
    this->map_.bind ("CollectionParameter", &::GAME::Mga::allocate_impl <CollectionParameter_Impl>);
    this->map_.bind ("NameParameter", &::GAME::Mga::allocate_impl <NameParameter_Impl>);
    this->map_.bind ("ConnectorInherits", &::GAME::Mga::allocate_impl <ConnectorInherits_Impl>);
    this->map_.bind ("InterfaceDefinitions", &::GAME::Mga::allocate_impl <InterfaceDefinitions_Impl>);
    this->map_.bind ("DataValue", &::GAME::Mga::allocate_impl <DataValue_Impl>);
    this->map_.bind ("ComplexTypeReference", &::GAME::Mga::allocate_impl <ComplexTypeReference_Impl>);
    this->map_.bind ("DataValueContainer", &::GAME::Mga::allocate_impl <DataValueContainer_Impl>);
    this->map_.bind ("File", &::GAME::Mga::allocate_impl <File_Impl>);
    this->map_.bind ("Package", &::GAME::Mga::allocate_impl <Package_Impl>);
    this->map_.bind ("BranchTransition", &::GAME::Mga::allocate_impl <BranchTransition_Impl>);
    this->map_.bind ("Constant", &::GAME::Mga::allocate_impl <Constant_Impl>);
    this->map_.bind ("FileRef", &::GAME::Mga::allocate_impl <FileRef_Impl>);
    this->map_.bind ("Exception", &::GAME::Mga::allocate_impl <Exception_Impl>);
    this->map_.bind ("WorkerPackage", &::GAME::Mga::allocate_impl <WorkerPackage_Impl>);
    this->map_.bind ("QueryInputAction", &::GAME::Mga::allocate_impl <QueryInputAction_Impl>);
    this->map_.bind ("MultiInputAction", &::GAME::Mga::allocate_impl <MultiInputAction_Impl>);
    this->map_.bind ("InputAction", &::GAME::Mga::allocate_impl <InputAction_Impl>);
    this->map_.bind ("WorkerLibrary", &::GAME::Mga::allocate_impl <WorkerLibrary_Impl>);
    this->map_.bind ("ComponentAssemblyReference", &::GAME::Mga::allocate_impl <ComponentAssemblyReference_Impl>);
    this->map_.bind ("WorkerType", &::GAME::Mga::allocate_impl <WorkerType_Impl>);
    this->map_.bind ("ComponentConfigProperty", &::GAME::Mga::allocate_impl <ComponentConfigProperty_Impl>);
    this->map_.bind ("ComponentAssembly", &::GAME::Mga::allocate_impl <ComponentAssembly_Impl>);
    this->map_.bind ("AssemblyConfigProperty", &::GAME::Mga::allocate_impl <AssemblyConfigProperty_Impl>);
    this->map_.bind ("ExternalPort", &::GAME::Mga::allocate_impl <ExternalPort_Impl>);
    this->map_.bind ("CriticalPath", &::GAME::Mga::allocate_impl <CriticalPath_Impl>);
    this->map_.bind ("MonolithicImplementation", &::GAME::Mga::allocate_impl <MonolithicImplementation_Impl>);
    this->map_.bind ("ComponentImplementationContainer", &::GAME::Mga::allocate_impl <ComponentImplementationContainer_Impl>);
    this->map_.bind ("ComponentInstance", &::GAME::Mga::allocate_impl <ComponentInstance_Impl>);
    this->map_.bind ("ExtendedPortInstance", &::GAME::Mga::allocate_impl <ExtendedPortInstance_Impl>);
    this->map_.bind ("ComponentImplementations", &::GAME::Mga::allocate_impl <ComponentImplementations_Impl>);
    this->map_.bind ("Implements", &::GAME::Mga::allocate_impl <Implements_Impl>);
    this->map_.bind ("ImplementationDependsOn", &::GAME::Mga::allocate_impl <ImplementationDependsOn_Impl>);
    this->map_.bind ("ImplementationCapability", &::GAME::Mga::allocate_impl <ImplementationCapability_Impl>);
    this->map_.bind ("ComponentContainer", &::GAME::Mga::allocate_impl <ComponentContainer_Impl>);
    this->map_.bind ("ComponentProperty", &::GAME::Mga::allocate_impl <ComponentProperty_Impl>);
    this->map_.bind ("Finish", &::GAME::Mga::allocate_impl <Finish_Impl>);
    this->map_.bind ("OutputAction", &::GAME::Mga::allocate_impl <OutputAction_Impl>);
    this->map_.bind ("Action", &::GAME::Mga::allocate_impl <Action_Impl>);
    this->map_.bind ("ReceptacleDelegate", &::GAME::Mga::allocate_impl <ReceptacleDelegate_Impl>);
    this->map_.bind ("ExtendedPortDelegate", &::GAME::Mga::allocate_impl <ExtendedPortDelegate_Impl>);
    this->map_.bind ("MirrorPortInstance", &::GAME::Mga::allocate_impl <MirrorPortInstance_Impl>);
    this->map_.bind ("OutEventPortInstance", &::GAME::Mga::allocate_impl <OutEventPortInstance_Impl>);
    this->map_.bind ("ExtendedDelegate", &::GAME::Mga::allocate_impl <ExtendedDelegate_Impl>);
    this->map_.bind ("ConnectorType", &::GAME::Mga::allocate_impl <ConnectorType_Impl>);
    this->map_.bind ("ComponentInfoProperty", &::GAME::Mga::allocate_impl <ComponentInfoProperty_Impl>);
    this->map_.bind ("ExternalDelegate", &::GAME::Mga::allocate_impl <ExternalDelegate_Impl>);
    this->map_.bind ("AttributeMapping", &::GAME::Mga::allocate_impl <AttributeMapping_Impl>);
    this->map_.bind ("OutEventPortDelegate", &::GAME::Mga::allocate_impl <OutEventPortDelegate_Impl>);
    this->map_.bind ("ConnectorToFacet", &::GAME::Mga::allocate_impl <ConnectorToFacet_Impl>);
    this->map_.bind ("AttributeDelegate", &::GAME::Mga::allocate_impl <AttributeDelegate_Impl>);
    this->map_.bind ("Publish", &::GAME::Mga::allocate_impl <Publish_Impl>);
    this->map_.bind ("Input", &::GAME::Mga::allocate_impl <Input_Impl>);
    this->map_.bind ("EventSourceDelegate", &::GAME::Mga::allocate_impl <EventSourceDelegate_Impl>);
    this->map_.bind ("FacetDelegate", &::GAME::Mga::allocate_impl <FacetDelegate_Impl>);
    this->map_.bind ("MirrorDelegate", &::GAME::Mga::allocate_impl <MirrorDelegate_Impl>);
    this->map_.bind ("ConnectorToReceptacle", &::GAME::Mga::allocate_impl <ConnectorToReceptacle_Impl>);
    this->map_.bind ("ConnectorImplementations", &::GAME::Mga::allocate_impl <ConnectorImplementations_Impl>);
    this->map_.bind ("MirrorPortDelegate", &::GAME::Mga::allocate_impl <MirrorPortDelegate_Impl>);
    this->map_.bind ("MultiInput", &::GAME::Mga::allocate_impl <MultiInput_Impl>);
    this->map_.bind ("ProvidedRequestPortDelegate", &::GAME::Mga::allocate_impl <ProvidedRequestPortDelegate_Impl>);
    this->map_.bind ("RequiredRequestPortDelegate", &::GAME::Mga::allocate_impl <RequiredRequestPortDelegate_Impl>);
    this->map_.bind ("InEventPortDelegate", &::GAME::Mga::allocate_impl <InEventPortDelegate_Impl>);
    this->map_.bind ("Consume", &::GAME::Mga::allocate_impl <Consume_Impl>);
    this->map_.bind ("ActionType", &::GAME::Mga::allocate_impl <ActionType_Impl>);
    this->map_.bind ("RequestAction", &::GAME::Mga::allocate_impl <RequestAction_Impl>);
    this->map_.bind ("QueryAction", &::GAME::Mga::allocate_impl <QueryAction_Impl>);
    this->map_.bind ("AttributeMappingDelegate", &::GAME::Mga::allocate_impl <AttributeMappingDelegate_Impl>);
    this->map_.bind ("ComponentPropertyDescription", &::GAME::Mga::allocate_impl <ComponentPropertyDescription_Impl>);
    this->map_.bind ("ComponentTypes", &::GAME::Mga::allocate_impl <ComponentTypes_Impl>);
    this->map_.bind ("AttributeMappingValue", &::GAME::Mga::allocate_impl <AttributeMappingValue_Impl>);
    this->map_.bind ("LoopTransition", &::GAME::Mga::allocate_impl <LoopTransition_Impl>);
    this->map_.bind ("AttributeValue", &::GAME::Mga::allocate_impl <AttributeValue_Impl>);
    this->map_.bind ("EventSinkDelegate", &::GAME::Mga::allocate_impl <EventSinkDelegate_Impl>);
    this->map_.bind ("WorkerLibraries", &::GAME::Mga::allocate_impl <WorkerLibraries_Impl>);
    this->map_.bind ("SendsTo", &::GAME::Mga::allocate_impl <SendsTo_Impl>);
    this->map_.bind ("AssemblyselectRequirement", &::GAME::Mga::allocate_impl <AssemblyselectRequirement_Impl>);
    this->map_.bind ("Invoke", &::GAME::Mga::allocate_impl <Invoke_Impl>);
    this->map_.bind ("ConnectorObject", &::GAME::Mga::allocate_impl <ConnectorObject_Impl>);
    this->map_.bind ("ComponentImplementationReference", &::GAME::Mga::allocate_impl <ComponentImplementationReference_Impl>);
    this->map_.bind ("SupportsInstance", &::GAME::Mga::allocate_impl <SupportsInstance_Impl>);
    this->map_.bind ("InEventPortInstance", &::GAME::Mga::allocate_impl <InEventPortInstance_Impl>);
    this->map_.bind ("LookupKey", &::GAME::Mga::allocate_impl <LookupKey_Impl>);
    this->map_.bind ("MirrorPort", &::GAME::Mga::allocate_impl <MirrorPort_Impl>);
    this->map_.bind ("ComponentInherits", &::GAME::Mga::allocate_impl <ComponentInherits_Impl>);
    this->map_.bind ("PortType", &::GAME::Mga::allocate_impl <PortType_Impl>);
    this->map_.bind ("ExtendedPort", &::GAME::Mga::allocate_impl <ExtendedPort_Impl>);
    this->map_.bind ("RequiredRequestPortInstance", &::GAME::Mga::allocate_impl <RequiredRequestPortInstance_Impl>);
    this->map_.bind ("ComponentInstanceType", &::GAME::Mga::allocate_impl <ComponentInstanceType_Impl>);
    this->map_.bind ("InEventPort", &::GAME::Mga::allocate_impl <InEventPort_Impl>);
    this->map_.bind ("RequiredRequestPort", &::GAME::Mga::allocate_impl <RequiredRequestPort_Impl>);
    this->map_.bind ("AttributeInstance", &::GAME::Mga::allocate_impl <AttributeInstance_Impl>);
    this->map_.bind ("ProvidedRequestPortInstance", &::GAME::Mga::allocate_impl <ProvidedRequestPortInstance_Impl>);
    this->map_.bind ("ProvidedRequestPort", &::GAME::Mga::allocate_impl <ProvidedRequestPort_Impl>);
    this->map_.bind ("OutEventPort", &::GAME::Mga::allocate_impl <OutEventPort_Impl>);
    this->map_.bind ("Component", &::GAME::Mga::allocate_impl <Component_Impl>);
    this->map_.bind ("ManagesComponent", &::GAME::Mga::allocate_impl <ManagesComponent_Impl>);
    this->map_.bind ("ComponentRef", &::GAME::Mga::allocate_impl <ComponentRef_Impl>);
    this->map_.bind ("ComponentFactory", &::GAME::Mga::allocate_impl <ComponentFactory_Impl>);
    this->map_.bind ("InputEffect", &::GAME::Mga::allocate_impl <InputEffect_Impl>);
    this->map_.bind ("DstEdge", &::GAME::Mga::allocate_impl <DstEdge_Impl>);
    this->map_.bind ("PathDiagrams", &::GAME::Mga::allocate_impl <PathDiagrams_Impl>);
    this->map_.bind ("TerminalTransition", &::GAME::Mga::allocate_impl <TerminalTransition_Impl>);
    this->map_.bind ("ArtifactDependency", &::GAME::Mga::allocate_impl <ArtifactDependency_Impl>);
    this->map_.bind ("ExternalResources", &::GAME::Mga::allocate_impl <ExternalResources_Impl>);
    this->map_.bind ("Project", &::GAME::Mga::allocate_impl <Project_Impl>);
    this->map_.bind ("ComponentBuild", &::GAME::Mga::allocate_impl <ComponentBuild_Impl>);
    this->map_.bind ("WorkerFile", &::GAME::Mga::allocate_impl <WorkerFile_Impl>);
    this->map_.bind ("PackageInfoProperty", &::GAME::Mga::allocate_impl <PackageInfoProperty_Impl>);
    this->map_.bind ("PackageConfigProperty", &::GAME::Mga::allocate_impl <PackageConfigProperty_Impl>);
    this->map_.bind ("PackageContainer", &::GAME::Mga::allocate_impl <PackageContainer_Impl>);
    this->map_.bind ("ECRole", &::GAME::Mga::allocate_impl <ECRole_Impl>);
    this->map_.bind ("Implementation", &::GAME::Mga::allocate_impl <Implementation_Impl>);
    this->map_.bind ("PackageInterface", &::GAME::Mga::allocate_impl <PackageInterface_Impl>);
    this->map_.bind ("ConnectorImplements", &::GAME::Mga::allocate_impl <ConnectorImplements_Impl>);
    this->map_.bind ("ComponentPackages", &::GAME::Mga::allocate_impl <ComponentPackages_Impl>);
    this->map_.bind ("ServiceProvider", &::GAME::Mga::allocate_impl <ServiceProvider_Impl>);
    this->map_.bind ("Interconnect", &::GAME::Mga::allocate_impl <Interconnect_Impl>);
    this->map_.bind ("Bridge", &::GAME::Mga::allocate_impl <Bridge_Impl>);
    this->map_.bind ("ComponentPackage", &::GAME::Mga::allocate_impl <ComponentPackage_Impl>);
    this->map_.bind ("MonolithExecParameter", &::GAME::Mga::allocate_impl <MonolithExecParameter_Impl>);
    this->map_.bind ("MonolithDeployRequirement", &::GAME::Mga::allocate_impl <MonolithDeployRequirement_Impl>);
    this->map_.bind ("TerminalEffect", &::GAME::Mga::allocate_impl <TerminalEffect_Impl>);
    this->map_.bind ("MonolithprimaryArtifact", &::GAME::Mga::allocate_impl <MonolithprimaryArtifact_Impl>);
    this->map_.bind ("InfoProperty", &::GAME::Mga::allocate_impl <InfoProperty_Impl>);
    this->map_.bind ("ConfigProperty", &::GAME::Mga::allocate_impl <ConfigProperty_Impl>);
    this->map_.bind ("Terminal", &::GAME::Mga::allocate_impl <Terminal_Impl>);
    this->map_.bind ("Domain", &::GAME::Mga::allocate_impl <Domain_Impl>);
    this->map_.bind ("PackageConfSpecializedConfig", &::GAME::Mga::allocate_impl <PackageConfSpecializedConfig_Impl>);
    this->map_.bind ("BranchState", &::GAME::Mga::allocate_impl <BranchState_Impl>);
    this->map_.bind ("Transition", &::GAME::Mga::allocate_impl <Transition_Impl>);
  }

  //
  // ~Impl_Factory
  //
  Impl_Factory::~Impl_Factory (void)
  {
  }

  //
  // allocate
  //
  ::GAME::Mga::Object_Impl * Impl_Factory::allocate (IMgaObject * ptr)
  {
    CComPtr <IMgaMetaBase> metabase;
    VERIFY_HRESULT (ptr->get_MetaBase (&metabase));

    CComBSTR bstr;
    VERIFY_HRESULT (metabase->get_Name (&bstr));

    CW2A metaname (bstr);
    FACTORY_METHOD factory_method = 0;
    if (0 != this->map_.find (metaname.m_psz, factory_method))  return 0;

    return factory_method (ptr);
  }
}

