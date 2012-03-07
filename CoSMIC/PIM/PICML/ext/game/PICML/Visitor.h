// -*- C++ -*-

//============================================================================
/**
 * @file    Visitor.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_VISITOR_H_
#define _PICML_VISITOR_H_

#include "game/mga/Visitor.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  class PICML_Export Visitor : public ::GAME::Mga::Visitor
  {
    protected:
    /// Default constructor.
    Visitor (void);

    public:
    /// Destructor.
    virtual ~Visitor (void);

    /**
     * @name Visit Methods
     */
    ///@{
    virtual void visit_WorkerLibraries (WorkerLibraries_in item);
    virtual void visit_WorkerLibrary (WorkerLibrary_in item);
    virtual void visit_Worker (Worker_in item);
    virtual void visit_WorkerFile (WorkerFile_in item);
    virtual void visit_WorkerPackage (WorkerPackage_in item);
    virtual void visit_Operation (Operation_in item);
    virtual void visit_Variable (Variable_in item);
    virtual void visit_Action (Action_in item);
    virtual void visit_OutputAction (OutputAction_in item);
    virtual void visit_Finish (Finish_in item);
    virtual void visit_QueryAction (QueryAction_in item);
    virtual void visit_QueryInputAction (QueryInputAction_in item);
    virtual void visit_MultiInputAction (MultiInputAction_in item);
    virtual void visit_InputAction (InputAction_in item);
    virtual void visit_RequestAction (RequestAction_in item);
    virtual void visit_ActionType (ActionType_in item);
    virtual void visit_Environment (Environment_in item);
    virtual void visit_PeriodicEvent (PeriodicEvent_in item);
    virtual void visit_ApplicationTask (ApplicationTask_in item);
    virtual void visit_WorkerType (WorkerType_in item);
    virtual void visit_Input (Input_in item);
    virtual void visit_MultiInput (MultiInput_in item);
    virtual void visit_QueryInput (QueryInput_in item);
    virtual void visit_Transition (Transition_in item);
    virtual void visit_State (State_in item);
    virtual void visit_BranchState (BranchState_in item);
    virtual void visit_BranchTransition (BranchTransition_in item);
    virtual void visit_ForState (ForState_in item);
    virtual void visit_DoWhileState (DoWhileState_in item);
    virtual void visit_WhileState (WhileState_in item);
    virtual void visit_LoopTransition (LoopTransition_in item);
    virtual void visit_Terminal (Terminal_in item);
    virtual void visit_TerminalTransition (TerminalTransition_in item);
    virtual void visit_Effect (Effect_in item);
    virtual void visit_InputEffect (InputEffect_in item);
    virtual void visit_TerminalEffect (TerminalEffect_in item);
    virtual void visit_ConnectorObject (ConnectorObject_in item);
    virtual void visit_ConnectorInherits (ConnectorInherits_in item);
    virtual void visit_ConnectorInstance (ConnectorInstance_in item);
    virtual void visit_ConnectorImplementationType (ConnectorImplementationType_in item);
    virtual void visit_ConnectorImplementations (ConnectorImplementations_in item);
    virtual void visit_ConnectorImplementationContainer (ConnectorImplementationContainer_in item);
    virtual void visit_ConnectorImplementation (ConnectorImplementation_in item);
    virtual void visit_ConnectorImplements (ConnectorImplements_in item);
    virtual void visit_ConnectorType (ConnectorType_in item);
    virtual void visit_Component (Component_in item);
    virtual void visit_OutEventPort (OutEventPort_in item);
    virtual void visit_ProvidedRequestPort (ProvidedRequestPort_in item);
    virtual void visit_RequiredRequestPort (RequiredRequestPort_in item);
    virtual void visit_InEventPort (InEventPort_in item);
    virtual void visit_ComponentRef (ComponentRef_in item);
    virtual void visit_ComponentFactory (ComponentFactory_in item);
    virtual void visit_ManagesComponent (ManagesComponent_in item);
    virtual void visit_ExtendedPort (ExtendedPort_in item);
    virtual void visit_PortType (PortType_in item);
    virtual void visit_ComponentInherits (ComponentInherits_in item);
    virtual void visit_MirrorPort (MirrorPort_in item);
    virtual void visit_LookupKey (LookupKey_in item);
    virtual void visit_ComponentTypes (ComponentTypes_in item);
    virtual void visit_ComponentPropertyDescription (ComponentPropertyDescription_in item);
    virtual void visit_ComponentProperty (ComponentProperty_in item);
    virtual void visit_ComponentContainer (ComponentContainer_in item);
    virtual void visit_ComponentConfigProperty (ComponentConfigProperty_in item);
    virtual void visit_ComponentInfoProperty (ComponentInfoProperty_in item);
    virtual void visit_ImplementationCapability (ImplementationCapability_in item);
    virtual void visit_ImplementationDependsOn (ImplementationDependsOn_in item);
    virtual void visit_Implements (Implements_in item);
    virtual void visit_ComponentImplementations (ComponentImplementations_in item);
    virtual void visit_ComponentImplementationReference (ComponentImplementationReference_in item);
    virtual void visit_ComponentImplementationContainer (ComponentImplementationContainer_in item);
    virtual void visit_MonolithicImplementation (MonolithicImplementation_in item);
    virtual void visit_CriticalPath (CriticalPath_in item);
    virtual void visit_ComponentInstance (ComponentInstance_in item);
    virtual void visit_ComponentInstanceType (ComponentInstanceType_in item);
    virtual void visit_AttributeInstance (AttributeInstance_in item);
    virtual void visit_ExtendedPortInstance (ExtendedPortInstance_in item);
    virtual void visit_MirrorPortInstance (MirrorPortInstance_in item);
    virtual void visit_OutEventPortInstance (OutEventPortInstance_in item);
    virtual void visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in item);
    virtual void visit_InEventPortInstance (InEventPortInstance_in item);
    virtual void visit_RequiredRequestPortInstance (RequiredRequestPortInstance_in item);
    virtual void visit_SupportsInstance (SupportsInstance_in item);
    virtual void visit_Invoke (Invoke_in item);
    virtual void visit_AssemblyselectRequirement (AssemblyselectRequirement_in item);
    virtual void visit_AssemblyConfigProperty (AssemblyConfigProperty_in item);
    virtual void visit_SendsTo (SendsTo_in item);
    virtual void visit_ReceptacleDelegate (ReceptacleDelegate_in item);
    virtual void visit_FacetDelegate (FacetDelegate_in item);
    virtual void visit_EventSourceDelegate (EventSourceDelegate_in item);
    virtual void visit_EventSinkDelegate (EventSinkDelegate_in item);
    virtual void visit_ExternalDelegate (ExternalDelegate_in item);
    virtual void visit_AttributeValue (AttributeValue_in item);
    virtual void visit_AttributeDelegate (AttributeDelegate_in item);
    virtual void visit_AttributeMapping (AttributeMapping_in item);
    virtual void visit_AttributeMappingValue (AttributeMappingValue_in item);
    virtual void visit_AttributeMappingDelegate (AttributeMappingDelegate_in item);
    virtual void visit_Publish (Publish_in item);
    virtual void visit_Consume (Consume_in item);
    virtual void visit_InEventPortDelegate (InEventPortDelegate_in item);
    virtual void visit_OutEventPortDelegate (OutEventPortDelegate_in item);
    virtual void visit_RequiredRequestPortDelegate (RequiredRequestPortDelegate_in item);
    virtual void visit_ProvidedRequestPortDelegate (ProvidedRequestPortDelegate_in item);
    virtual void visit_ConnectorToReceptacle (ConnectorToReceptacle_in item);
    virtual void visit_ConnectorToFacet (ConnectorToFacet_in item);
    virtual void visit_MirrorPortDelegate (MirrorPortDelegate_in item);
    virtual void visit_MirrorDelegate (MirrorDelegate_in item);
    virtual void visit_ExtendedPortDelegate (ExtendedPortDelegate_in item);
    virtual void visit_ExtendedDelegate (ExtendedDelegate_in item);
    virtual void visit_ComponentAssembly (ComponentAssembly_in item);
    virtual void visit_ComponentAssemblyReference (ComponentAssemblyReference_in item);
    virtual void visit_ExternalPort (ExternalPort_in item);
    virtual void visit_ComponentBuild (ComponentBuild_in item);
    virtual void visit_Project (Project_in item);
    virtual void visit_ExternalResources (ExternalResources_in item);
    virtual void visit_ExtResourceConn (ExtResourceConn_in item);
    virtual void visit_MPC (MPC_in item);
    virtual void visit_StubProject (StubProject_in item);
    virtual void visit_ServantProject (ServantProject_in item);
    virtual void visit_ExecutorProject (ExecutorProject_in item);
    virtual void visit_Workspaces (Workspaces_in item);
    virtual void visit_Package (Package_in item);
    virtual void visit_File (File_in item);
    virtual void visit_Exception (Exception_in item);
    virtual void visit_FileRef (FileRef_in item);
    virtual void visit_InterfaceDefinitions (InterfaceDefinitions_in item);
    virtual void visit_Constant (Constant_in item);
    virtual void visit_NameParameter (NameParameter_in item);
    virtual void visit_CollectionParameter (CollectionParameter_in item);
    virtual void visit_PackageType (PackageType_in item);
    virtual void visit_TemplatePackageInstance (TemplatePackageInstance_in item);
    virtual void visit_TemplateParameterValue (TemplateParameterValue_in item);
    virtual void visit_TypeParameter (TypeParameter_in item);
    virtual void visit_NativeValue (NativeValue_in item);
    virtual void visit_TemplatePackageAlias (TemplatePackageAlias_in item);
    virtual void visit_TemplateParameterReference (TemplateParameterReference_in item);
    virtual void visit_PredefinedTypes (PredefinedTypes_in item);
    virtual void visit_Byte (Byte_in item);
    virtual void visit_Boolean (Boolean_in item);
    virtual void visit_ShortInteger (ShortInteger_in item);
    virtual void visit_LongInteger (LongInteger_in item);
    virtual void visit_FloatNumber (FloatNumber_in item);
    virtual void visit_String (String_in item);
    virtual void visit_GenericObject (GenericObject_in item);
    virtual void visit_GenericValueObject (GenericValueObject_in item);
    virtual void visit_GenericValue (GenericValue_in item);
    virtual void visit_TypeEncoding (TypeEncoding_in item);
    virtual void visit_TypeKind (TypeKind_in item);
    virtual void visit_DoubleNumber (DoubleNumber_in item);
    virtual void visit_LongDoubleNumber (LongDoubleNumber_in item);
    virtual void visit_LongLongInteger (LongLongInteger_in item);
    virtual void visit_UnsignedLongLongInteger (UnsignedLongLongInteger_in item);
    virtual void visit_UnsignedLongInteger (UnsignedLongInteger_in item);
    virtual void visit_UnsignedShortInteger (UnsignedShortInteger_in item);
    virtual void visit_WideChar (WideChar_in item);
    virtual void visit_WideString (WideString_in item);
    virtual void visit_Char (Char_in item);
    virtual void visit_Enum (Enum_in item);
    virtual void visit_EnumValue (EnumValue_in item);
    virtual void visit_Aggregate (Aggregate_in item);
    virtual void visit_SwitchedAggregate (SwitchedAggregate_in item);
    virtual void visit_Label (Label_in item);
    virtual void visit_LabelConnection (LabelConnection_in item);
    virtual void visit_Discriminator (Discriminator_in item);
    virtual void visit_Collection (Collection_in item);
    virtual void visit_Alias (Alias_in item);
    virtual void visit_Boxed (Boxed_in item);
    virtual void visit_Member (Member_in item);
    virtual void visit_ArrayMember (ArrayMember_in item);
    virtual void visit_KeyMember (KeyMember_in item);
    virtual void visit_Key (Key_in item);
    virtual void visit_Object (Object_in item);
    virtual void visit_Inherits (Inherits_in item);
    virtual void visit_Event (Event_in item);
    virtual void visit_ValueObject (ValueObject_in item);
    virtual void visit_Supports (Supports_in item);
    virtual void visit_ReadonlyAttribute (ReadonlyAttribute_in item);
    virtual void visit_Attribute (Attribute_in item);
    virtual void visit_SetException (SetException_in item);
    virtual void visit_GetException (GetException_in item);
    virtual void visit_PrivateFlag (PrivateFlag_in item);
    virtual void visit_MakeMemberPrivate (MakeMemberPrivate_in item);
    virtual void visit_AttributeMember (AttributeMember_in item);
    virtual void visit_ExceptionRef (ExceptionRef_in item);
    virtual void visit_FactoryOperation (FactoryOperation_in item);
    virtual void visit_LookupOperation (LookupOperation_in item);
    virtual void visit_TwowayOperation (TwowayOperation_in item);
    virtual void visit_OnewayOperation (OnewayOperation_in item);
    virtual void visit_InParameter (InParameter_in item);
    virtual void visit_InoutParameter (InoutParameter_in item);
    virtual void visit_OutParameter (OutParameter_in item);
    virtual void visit_ReturnType (ReturnType_in item);
    virtual void visit_Domain (Domain_in item);
    virtual void visit_Targets (Targets_in item);
    virtual void visit_Shares (Shares_in item);
    virtual void visit_InterconnectConnection (InterconnectConnection_in item);
    virtual void visit_BridgeConnection (BridgeConnection_in item);
    virtual void visit_Requirement (Requirement_in item);
    virtual void visit_ImplementationDependency (ImplementationDependency_in item);
    virtual void visit_SatisfierProperty (SatisfierProperty_in item);
    virtual void visit_Capability (Capability_in item);
    virtual void visit_ImplementationRequirement (ImplementationRequirement_in item);
    virtual void visit_DataType (DataType_in item);
    virtual void visit_DataValueContainer (DataValueContainer_in item);
    virtual void visit_ComplexTypeReference (ComplexTypeReference_in item);
    virtual void visit_DataValue (DataValue_in item);
    virtual void visit_SimpleProperty (SimpleProperty_in item);
    virtual void visit_ComplexProperty (ComplexProperty_in item);
    virtual void visit_ComponentPackages (ComponentPackages_in item);
    virtual void visit_PackageInterface (PackageInterface_in item);
    virtual void visit_Implementation (Implementation_in item);
    virtual void visit_PackageContainer (PackageContainer_in item);
    virtual void visit_PackageConfigProperty (PackageConfigProperty_in item);
    virtual void visit_PackageInfoProperty (PackageInfoProperty_in item);
    virtual void visit_ComponentPackage (ComponentPackage_in item);
    virtual void visit_ComponentPackageReference (ComponentPackageReference_in item);
    virtual void visit_TopLevelPackageContainer (TopLevelPackageContainer_in item);
    virtual void visit_TopLevelPackages (TopLevelPackages_in item);
    virtual void visit_TopLevelPackage (TopLevelPackage_in item);
    virtual void visit_package (package_in item);
    virtual void visit_ImplementationArtifacts (ImplementationArtifacts_in item);
    virtual void visit_ImplementationArtifactReference (ImplementationArtifactReference_in item);
    virtual void visit_ArtifactDependsOn (ArtifactDependsOn_in item);
    virtual void visit_ArtifactDeployRequirement (ArtifactDeployRequirement_in item);
    virtual void visit_ArtifactContainer (ArtifactContainer_in item);
    virtual void visit_ArtifactExecParameter (ArtifactExecParameter_in item);
    virtual void visit_ArtifactInfoProperty (ArtifactInfoProperty_in item);
    virtual void visit_ImplementationArtifact (ImplementationArtifact_in item);
    virtual void visit_ArtifactDependency (ArtifactDependency_in item);
    virtual void visit_PackageConfBasePackage (PackageConfBasePackage_in item);
    virtual void visit_PackageConfReference (PackageConfReference_in item);
    virtual void visit_PackageConfigurationReference (PackageConfigurationReference_in item);
    virtual void visit_PackageConfigurations (PackageConfigurations_in item);
    virtual void visit_PackageConfigurationContainer (PackageConfigurationContainer_in item);
    virtual void visit_PackageConfConfigProperty (PackageConfConfigProperty_in item);
    virtual void visit_PackageConfSelectRequirement (PackageConfSelectRequirement_in item);
    virtual void visit_PackageConfSpecializedConfig (PackageConfSpecializedConfig_in item);
    virtual void visit_PackageConfiguration (PackageConfiguration_in item);
    virtual void visit_DeploymentPlan (DeploymentPlan_in item);
    virtual void visit_InstanceMapping (InstanceMapping_in item);
    virtual void visit_DeploymentPlans (DeploymentPlans_in item);
    virtual void visit_CollocationGroup (CollocationGroup_in item);
    virtual void visit_ComponentFactoryRef (ComponentFactoryRef_in item);
    virtual void visit_Deploys (Deploys_in item);
    virtual void visit_ComponentInstanceRef (ComponentInstanceRef_in item);
    virtual void visit_PropertyMapping (PropertyMapping_in item);
    virtual void visit_CollocationGroupProperty (CollocationGroupProperty_in item);
    virtual void visit_Bridge (Bridge_in item);
    virtual void visit_Interconnect (Interconnect_in item);
    virtual void visit_Node (Node_in item);
    virtual void visit_NodeReference (NodeReference_in item);
    virtual void visit_SharedResource (SharedResource_in item);
    virtual void visit_Resource (Resource_in item);
    virtual void visit_MetricConnection (MetricConnection_in item);
    virtual void visit_Average (Average_in item);
    virtual void visit_Minimum (Minimum_in item);
    virtual void visit_Maximum (Maximum_in item);
    virtual void visit_Jitter (Jitter_in item);
    virtual void visit_TimeProbe (TimeProbe_in item);
    virtual void visit_TimerConnection (TimerConnection_in item);
    virtual void visit_Latency (Latency_in item);
    virtual void visit_Throughput (Throughput_in item);
    virtual void visit_ComponentAnalyses (ComponentAnalyses_in item);
    virtual void visit_BenchmarkAnalysis (BenchmarkAnalysis_in item);
    virtual void visit_OperationRef (OperationRef_in item);
    virtual void visit_EventRef (EventRef_in item);
    virtual void visit_TimerEventSinkConn (TimerEventSinkConn_in item);
    virtual void visit_TaskSet (TaskSet_in item);
    virtual void visit_Task (Task_in item);
    virtual void visit_WorkloadCharacteristics (WorkloadCharacteristics_in item);
    virtual void visit_ComponentOperation (ComponentOperation_in item);
    virtual void visit_CompRef (CompRef_in item);
    virtual void visit_WorkLoadOperationConnection (WorkLoadOperationConnection_in item);
    virtual void visit_TriggerBenchmarks (TriggerBenchmarks_in item);
    virtual void visit_FixedIterationBenchmarks (FixedIterationBenchmarks_in item);
    virtual void visit_PeriodicBenchmarks (PeriodicBenchmarks_in item);
    virtual void visit_BenchmarkCharacteristics (BenchmarkCharacteristics_in item);
    virtual void visit_ConnectedComponent (ConnectedComponent_in item);
    virtual void visit_Path (Path_in item);
    virtual void visit_PathDiagrams (PathDiagrams_in item);
    virtual void visit_DstEdge (DstEdge_in item);
    virtual void visit_SrcEdge (SrcEdge_in item);
    virtual void visit_EdgeProperty (EdgeProperty_in item);
    virtual void visit_Edge (Edge_in item);
    virtual void visit_DisplayNode (DisplayNode_in item);
    virtual void visit_Paths (Paths_in item);
    virtual void visit_PathProperty (PathProperty_in item);
    virtual void visit_PathReference (PathReference_in item);
    virtual void visit_ECBehavior (ECBehavior_in item);
    virtual void visit_ECRequirements (ECRequirements_in item);
    virtual void visit_ECRole (ECRole_in item);
    virtual void visit_RTRequirements (RTRequirements_in item);
    virtual void visit_ServiceProvider (ServiceProvider_in item);
    virtual void visit_MultipleServiceRequests (MultipleServiceRequests_in item);
    virtual void visit_ServiceLevels (ServiceLevels_in item);
    virtual void visit_ServiceConsumer (ServiceConsumer_in item);
    virtual void visit_ComponentFactoryImplementations (ComponentFactoryImplementations_in item);
    virtual void visit_ComponentFactoryImplementationContainer (ComponentFactoryImplementationContainer_in item);
    virtual void visit_ComponentFactoryInstance (ComponentFactoryInstance_in item);
    virtual void visit_ConfigProperty (ConfigProperty_in item);
    virtual void visit_InfoProperty (InfoProperty_in item);
    virtual void visit_MonolithprimaryArtifact (MonolithprimaryArtifact_in item);
    virtual void visit_MonolithDeployRequirement (MonolithDeployRequirement_in item);
    virtual void visit_MonolithExecParameter (MonolithExecParameter_in item);
    virtual void visit_ComponentServantArtifact (ComponentServantArtifact_in item);
    virtual void visit_ComponentImplementationArtifact (ComponentImplementationArtifact_in item);
    ///@}
    private:
    // prevent the following operation(s)
    const Visitor & operator = (const Visitor &);
  };
}

#endif
