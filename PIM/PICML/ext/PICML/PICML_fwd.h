// -*- C++ -*-
// $Id$

#ifndef _PICML_FWD_H_
#define _PICML_FWD_H_

#include "game/mga/Smart_Ptr.h"

namespace PICML
{
  // Forward declarations for RootFolder
  class RootFolder_Impl;
  typedef RootFolder_Impl * RootFolder_in;
  typedef ::GAME::Mga::Smart_Ptr <RootFolder_Impl> RootFolder;

  // Forward declarations for PredefinedTypes
  class PredefinedTypes_Impl;
  typedef PredefinedTypes_Impl * PredefinedTypes_in;
  typedef ::GAME::Mga::Smart_Ptr <PredefinedTypes_Impl> PredefinedTypes;

  // Forward declarations for FixedIterationBenchmarks
  class FixedIterationBenchmarks_Impl;
  typedef FixedIterationBenchmarks_Impl * FixedIterationBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr <FixedIterationBenchmarks_Impl> FixedIterationBenchmarks;

  // Forward declarations for PackageType
  class PackageType_Impl;
  typedef PackageType_Impl * PackageType_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageType_Impl> PackageType;

  // Forward declarations for Interconnect
  class Interconnect_Impl;
  typedef Interconnect_Impl * Interconnect_in;
  typedef ::GAME::Mga::Smart_Ptr <Interconnect_Impl> Interconnect;

  // Forward declarations for ObjectPort
  class ObjectPort_Impl;
  typedef ObjectPort_Impl * ObjectPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ObjectPort_Impl> ObjectPort;

  // Forward declarations for ArtifactInfoProperty
  class ArtifactInfoProperty_Impl;
  typedef ArtifactInfoProperty_Impl * ArtifactInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactInfoProperty_Impl> ArtifactInfoProperty;

  // Forward declarations for ProvidedRequestPortDelegate
  class ProvidedRequestPortDelegate_Impl;
  typedef ProvidedRequestPortDelegate_Impl * ProvidedRequestPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ProvidedRequestPortDelegate_Impl> ProvidedRequestPortDelegate;

  // Forward declarations for PathReference
  class PathReference_Impl;
  typedef PathReference_Impl * PathReference_in;
  typedef ::GAME::Mga::Smart_Ptr <PathReference_Impl> PathReference;

  // Forward declarations for PortType
  class PortType_Impl;
  typedef PortType_Impl * PortType_in;
  typedef ::GAME::Mga::Smart_Ptr <PortType_Impl> PortType;

  // Forward declarations for Capability
  class Capability_Impl;
  typedef Capability_Impl * Capability_in;
  typedef ::GAME::Mga::Smart_Ptr <Capability_Impl> Capability;

  // Forward declarations for FloatNumber
  class FloatNumber_Impl;
  typedef FloatNumber_Impl * FloatNumber_in;
  typedef ::GAME::Mga::Smart_Ptr <FloatNumber_Impl> FloatNumber;

  // Forward declarations for BehaviorModel
  class BehaviorModel_Impl;
  typedef BehaviorModel_Impl * BehaviorModel_in;
  typedef ::GAME::Mga::Smart_Ptr <BehaviorModel_Impl> BehaviorModel;

  // Forward declarations for TemplateParameterValue
  class TemplateParameterValue_Impl;
  typedef TemplateParameterValue_Impl * TemplateParameterValue_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplateParameterValue_Impl> TemplateParameterValue;

  // Forward declarations for Constant
  class Constant_Impl;
  typedef Constant_Impl * Constant_in;
  typedef ::GAME::Mga::Smart_Ptr <Constant_Impl> Constant;

  // Forward declarations for ExtResourceConn
  class ExtResourceConn_Impl;
  typedef ExtResourceConn_Impl * ExtResourceConn_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtResourceConn_Impl> ExtResourceConn;

  // Forward declarations for OutputAction
  class OutputAction_Impl;
  typedef OutputAction_Impl * OutputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <OutputAction_Impl> OutputAction;

  // Forward declarations for SrcEdge
  class SrcEdge_Impl;
  typedef SrcEdge_Impl * SrcEdge_in;
  typedef ::GAME::Mga::Smart_Ptr <SrcEdge_Impl> SrcEdge;

  // Forward declarations for Event
  class Event_Impl;
  typedef Event_Impl * Event_in;
  typedef ::GAME::Mga::Smart_Ptr <Event_Impl> Event;

  // Forward declarations for PackageConfiguration
  class PackageConfiguration_Impl;
  typedef PackageConfiguration_Impl * PackageConfiguration_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfiguration_Impl> PackageConfiguration;

  // Forward declarations for HasOperations
  class HasOperations_Impl;
  typedef HasOperations_Impl * HasOperations_in;
  typedef ::GAME::Mga::Smart_Ptr <HasOperations_Impl> HasOperations;

  // Forward declarations for ComponentImplementationContainer
  class ComponentImplementationContainer_Impl;
  typedef ComponentImplementationContainer_Impl * ComponentImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementationContainer_Impl> ComponentImplementationContainer;

  // Forward declarations for EventSinkDelegate
  class EventSinkDelegate_Impl;
  typedef EventSinkDelegate_Impl * EventSinkDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <EventSinkDelegate_Impl> EventSinkDelegate;

  // Forward declarations for NodeReference
  class NodeReference_Impl;
  typedef NodeReference_Impl * NodeReference_in;
  typedef ::GAME::Mga::Smart_Ptr <NodeReference_Impl> NodeReference;

  // Forward declarations for LoopState
  class LoopState_Impl;
  typedef LoopState_Impl * LoopState_in;
  typedef ::GAME::Mga::Smart_Ptr <LoopState_Impl> LoopState;

  // Forward declarations for Collection
  class Collection_Impl;
  typedef Collection_Impl * Collection_in;
  typedef ::GAME::Mga::Smart_Ptr <Collection_Impl> Collection;

  // Forward declarations for Inherits
  class Inherits_Impl;
  typedef Inherits_Impl * Inherits_in;
  typedef ::GAME::Mga::Smart_Ptr <Inherits_Impl> Inherits;

  // Forward declarations for Byte
  class Byte_Impl;
  typedef Byte_Impl * Byte_in;
  typedef ::GAME::Mga::Smart_Ptr <Byte_Impl> Byte;

  // Forward declarations for Average
  class Average_Impl;
  typedef Average_Impl * Average_in;
  typedef ::GAME::Mga::Smart_Ptr <Average_Impl> Average;

  // Forward declarations for State
  class State_Impl;
  typedef State_Impl * State_in;
  typedef ::GAME::Mga::Smart_Ptr <State_Impl> State;

  // Forward declarations for SendsTo
  class SendsTo_Impl;
  typedef SendsTo_Impl * SendsTo_in;
  typedef ::GAME::Mga::Smart_Ptr <SendsTo_Impl> SendsTo;

  // Forward declarations for ProvidedRequestPortEnd
  class ProvidedRequestPortEnd_Impl;
  typedef ProvidedRequestPortEnd_Impl * ProvidedRequestPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <ProvidedRequestPortEnd_Impl> ProvidedRequestPortEnd;

  // Forward declarations for InterfaceDefinitions
  class InterfaceDefinitions_Impl;
  typedef InterfaceDefinitions_Impl * InterfaceDefinitions_in;
  typedef ::GAME::Mga::Smart_Ptr <InterfaceDefinitions_Impl> InterfaceDefinitions;

  // Forward declarations for OperationRef
  class OperationRef_Impl;
  typedef OperationRef_Impl * OperationRef_in;
  typedef ::GAME::Mga::Smart_Ptr <OperationRef_Impl> OperationRef;

  // Forward declarations for DataValueBase
  class DataValueBase_Impl;
  typedef DataValueBase_Impl * DataValueBase_in;
  typedef ::GAME::Mga::Smart_Ptr <DataValueBase_Impl> DataValueBase;

  // Forward declarations for AttributeValue
  class AttributeValue_Impl;
  typedef AttributeValue_Impl * AttributeValue_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeValue_Impl> AttributeValue;

  // Forward declarations for ConnectorObject
  class ConnectorObject_Impl;
  typedef ConnectorObject_Impl * ConnectorObject_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorObject_Impl> ConnectorObject;

  // Forward declarations for ExtendPortEnd
  class ExtendPortEnd_Impl;
  typedef ExtendPortEnd_Impl * ExtendPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendPortEnd_Impl> ExtendPortEnd;

  // Forward declarations for ConfigProperty
  class ConfigProperty_Impl;
  typedef ConfigProperty_Impl * ConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ConfigProperty_Impl> ConfigProperty;

  // Forward declarations for InterconnectConnection
  class InterconnectConnection_Impl;
  typedef InterconnectConnection_Impl * InterconnectConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <InterconnectConnection_Impl> InterconnectConnection;

  // Forward declarations for WorkloadCharacteristics
  class WorkloadCharacteristics_Impl;
  typedef WorkloadCharacteristics_Impl * WorkloadCharacteristics_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkloadCharacteristics_Impl> WorkloadCharacteristics;

  // Forward declarations for TemplateParameter
  class TemplateParameter_Impl;
  typedef TemplateParameter_Impl * TemplateParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplateParameter_Impl> TemplateParameter;

  // Forward declarations for PackageConfigurationContainer
  class PackageConfigurationContainer_Impl;
  typedef PackageConfigurationContainer_Impl * PackageConfigurationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfigurationContainer_Impl> PackageConfigurationContainer;

  // Forward declarations for AttributeMapping
  class AttributeMapping_Impl;
  typedef AttributeMapping_Impl * AttributeMapping_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeMapping_Impl> AttributeMapping;

  // Forward declarations for SharedResource
  class SharedResource_Impl;
  typedef SharedResource_Impl * SharedResource_in;
  typedef ::GAME::Mga::Smart_Ptr <SharedResource_Impl> SharedResource;

  // Forward declarations for MultiInputBase
  class MultiInputBase_Impl;
  typedef MultiInputBase_Impl * MultiInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiInputBase_Impl> MultiInputBase;

  // Forward declarations for MonolithDeployRequirement
  class MonolithDeployRequirement_Impl;
  typedef MonolithDeployRequirement_Impl * MonolithDeployRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithDeployRequirement_Impl> MonolithDeployRequirement;

  // Forward declarations for PathProperty
  class PathProperty_Impl;
  typedef PathProperty_Impl * PathProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <PathProperty_Impl> PathProperty;

  // Forward declarations for TimerEventSinkConn
  class TimerEventSinkConn_Impl;
  typedef TimerEventSinkConn_Impl * TimerEventSinkConn_in;
  typedef ::GAME::Mga::Smart_Ptr <TimerEventSinkConn_Impl> TimerEventSinkConn;

  // Forward declarations for Path
  class Path_Impl;
  typedef Path_Impl * Path_in;
  typedef ::GAME::Mga::Smart_Ptr <Path_Impl> Path;

  // Forward declarations for EnumValue
  class EnumValue_Impl;
  typedef EnumValue_Impl * EnumValue_in;
  typedef ::GAME::Mga::Smart_Ptr <EnumValue_Impl> EnumValue;

  // Forward declarations for PortInstance
  class PortInstance_Impl;
  typedef PortInstance_Impl * PortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <PortInstance_Impl> PortInstance;

  // Forward declarations for TerminalEffect
  class TerminalEffect_Impl;
  typedef TerminalEffect_Impl * TerminalEffect_in;
  typedef ::GAME::Mga::Smart_Ptr <TerminalEffect_Impl> TerminalEffect;

  // Forward declarations for AssemblyConfigProperty
  class AssemblyConfigProperty_Impl;
  typedef AssemblyConfigProperty_Impl * AssemblyConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <AssemblyConfigProperty_Impl> AssemblyConfigProperty;

  // Forward declarations for UnsignedLongLongInteger
  class UnsignedLongLongInteger_Impl;
  typedef UnsignedLongLongInteger_Impl * UnsignedLongLongInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <UnsignedLongLongInteger_Impl> UnsignedLongLongInteger;

  // Forward declarations for Char
  class Char_Impl;
  typedef Char_Impl * Char_in;
  typedef ::GAME::Mga::Smart_Ptr <Char_Impl> Char;

  // Forward declarations for Discriminator
  class Discriminator_Impl;
  typedef Discriminator_Impl * Discriminator_in;
  typedef ::GAME::Mga::Smart_Ptr <Discriminator_Impl> Discriminator;

  // Forward declarations for DisplayNode
  class DisplayNode_Impl;
  typedef DisplayNode_Impl * DisplayNode_in;
  typedef ::GAME::Mga::Smart_Ptr <DisplayNode_Impl> DisplayNode;

  // Forward declarations for PackageConfigurationReference
  class PackageConfigurationReference_Impl;
  typedef PackageConfigurationReference_Impl * PackageConfigurationReference_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfigurationReference_Impl> PackageConfigurationReference;

  // Forward declarations for MonolithicImplementationBase
  class MonolithicImplementationBase_Impl;
  typedef MonolithicImplementationBase_Impl * MonolithicImplementationBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithicImplementationBase_Impl> MonolithicImplementationBase;

  // Forward declarations for InEventPortEnd
  class InEventPortEnd_Impl;
  typedef InEventPortEnd_Impl * InEventPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPortEnd_Impl> InEventPortEnd;

  // Forward declarations for Latency
  class Latency_Impl;
  typedef Latency_Impl * Latency_in;
  typedef ::GAME::Mga::Smart_Ptr <Latency_Impl> Latency;

  // Forward declarations for KeyMember
  class KeyMember_Impl;
  typedef KeyMember_Impl * KeyMember_in;
  typedef ::GAME::Mga::Smart_Ptr <KeyMember_Impl> KeyMember;

  // Forward declarations for IntegerType
  class IntegerType_Impl;
  typedef IntegerType_Impl * IntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr <IntegerType_Impl> IntegerType;

  // Forward declarations for WorkerPackageBase
  class WorkerPackageBase_Impl;
  typedef WorkerPackageBase_Impl * WorkerPackageBase_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerPackageBase_Impl> WorkerPackageBase;

  // Forward declarations for SimpleType
  class SimpleType_Impl;
  typedef SimpleType_Impl * SimpleType_in;
  typedef ::GAME::Mga::Smart_Ptr <SimpleType_Impl> SimpleType;

  // Forward declarations for ComponentImplementationReference
  class ComponentImplementationReference_Impl;
  typedef ComponentImplementationReference_Impl * ComponentImplementationReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementationReference_Impl> ComponentImplementationReference;

  // Forward declarations for ArtifactExecParameter
  class ArtifactExecParameter_Impl;
  typedef ArtifactExecParameter_Impl * ArtifactExecParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactExecParameter_Impl> ArtifactExecParameter;

  // Forward declarations for MonolithExecParameter
  class MonolithExecParameter_Impl;
  typedef MonolithExecParameter_Impl * MonolithExecParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithExecParameter_Impl> MonolithExecParameter;

  // Forward declarations for SingleOutputBase
  class SingleOutputBase_Impl;
  typedef SingleOutputBase_Impl * SingleOutputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <SingleOutputBase_Impl> SingleOutputBase;

  // Forward declarations for OperationBase
  class OperationBase_Impl;
  typedef OperationBase_Impl * OperationBase_in;
  typedef ::GAME::Mga::Smart_Ptr <OperationBase_Impl> OperationBase;

  // Forward declarations for PackageConfigProperty
  class PackageConfigProperty_Impl;
  typedef PackageConfigProperty_Impl * PackageConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfigProperty_Impl> PackageConfigProperty;

  // Forward declarations for QueryAction
  class QueryAction_Impl;
  typedef QueryAction_Impl * QueryAction_in;
  typedef ::GAME::Mga::Smart_Ptr <QueryAction_Impl> QueryAction;

  // Forward declarations for GetException
  class GetException_Impl;
  typedef GetException_Impl * GetException_in;
  typedef ::GAME::Mga::Smart_Ptr <GetException_Impl> GetException;

  // Forward declarations for Implementation
  class Implementation_Impl;
  typedef Implementation_Impl * Implementation_in;
  typedef ::GAME::Mga::Smart_Ptr <Implementation_Impl> Implementation;

  // Forward declarations for WideChar
  class WideChar_Impl;
  typedef WideChar_Impl * WideChar_in;
  typedef ::GAME::Mga::Smart_Ptr <WideChar_Impl> WideChar;

  // Forward declarations for Edge
  class Edge_Impl;
  typedef Edge_Impl * Edge_in;
  typedef ::GAME::Mga::Smart_Ptr <Edge_Impl> Edge;

  // Forward declarations for SetException
  class SetException_Impl;
  typedef SetException_Impl * SetException_in;
  typedef ::GAME::Mga::Smart_Ptr <SetException_Impl> SetException;

  // Forward declarations for ExternalResources
  class ExternalResources_Impl;
  typedef ExternalResources_Impl * ExternalResources_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalResources_Impl> ExternalResources;

  // Forward declarations for ServiceLevels
  class ServiceLevels_Impl;
  typedef ServiceLevels_Impl * ServiceLevels_in;
  typedef ::GAME::Mga::Smart_Ptr <ServiceLevels_Impl> ServiceLevels;

  // Forward declarations for FileRef
  class FileRef_Impl;
  typedef FileRef_Impl * FileRef_in;
  typedef ::GAME::Mga::Smart_Ptr <FileRef_Impl> FileRef;

  // Forward declarations for EventSourceDelegate
  class EventSourceDelegate_Impl;
  typedef EventSourceDelegate_Impl * EventSourceDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <EventSourceDelegate_Impl> EventSourceDelegate;

  // Forward declarations for Bridge
  class Bridge_Impl;
  typedef Bridge_Impl * Bridge_in;
  typedef ::GAME::Mga::Smart_Ptr <Bridge_Impl> Bridge;

  // Forward declarations for Deploys
  class Deploys_Impl;
  typedef Deploys_Impl * Deploys_in;
  typedef ::GAME::Mga::Smart_Ptr <Deploys_Impl> Deploys;

  // Forward declarations for ArrayMember
  class ArrayMember_Impl;
  typedef ArrayMember_Impl * ArrayMember_in;
  typedef ::GAME::Mga::Smart_Ptr <ArrayMember_Impl> ArrayMember;

  // Forward declarations for OutParameter
  class OutParameter_Impl;
  typedef OutParameter_Impl * OutParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <OutParameter_Impl> OutParameter;

  // Forward declarations for FloatingPointType
  class FloatingPointType_Impl;
  typedef FloatingPointType_Impl * FloatingPointType_in;
  typedef ::GAME::Mga::Smart_Ptr <FloatingPointType_Impl> FloatingPointType;

  // Forward declarations for Input
  class Input_Impl;
  typedef Input_Impl * Input_in;
  typedef ::GAME::Mga::Smart_Ptr <Input_Impl> Input;

  // Forward declarations for PackageInfoProperty
  class PackageInfoProperty_Impl;
  typedef PackageInfoProperty_Impl * PackageInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageInfoProperty_Impl> PackageInfoProperty;

  // Forward declarations for Action
  class Action_Impl;
  typedef Action_Impl * Action_in;
  typedef ::GAME::Mga::Smart_Ptr <Action_Impl> Action;

  // Forward declarations for NameParameter
  class NameParameter_Impl;
  typedef NameParameter_Impl * NameParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <NameParameter_Impl> NameParameter;

  // Forward declarations for DoubleNumber
  class DoubleNumber_Impl;
  typedef DoubleNumber_Impl * DoubleNumber_in;
  typedef ::GAME::Mga::Smart_Ptr <DoubleNumber_Impl> DoubleNumber;

  // Forward declarations for CompRef
  class CompRef_Impl;
  typedef CompRef_Impl * CompRef_in;
  typedef ::GAME::Mga::Smart_Ptr <CompRef_Impl> CompRef;

  // Forward declarations for DstEdge
  class DstEdge_Impl;
  typedef DstEdge_Impl * DstEdge_in;
  typedef ::GAME::Mga::Smart_Ptr <DstEdge_Impl> DstEdge;

  // Forward declarations for StateBase
  class StateBase_Impl;
  typedef StateBase_Impl * StateBase_in;
  typedef ::GAME::Mga::Smart_Ptr <StateBase_Impl> StateBase;

  // Forward declarations for ConnectorToFacet
  class ConnectorToFacet_Impl;
  typedef ConnectorToFacet_Impl * ConnectorToFacet_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorToFacet_Impl> ConnectorToFacet;

  // Forward declarations for ComponentFactory
  class ComponentFactory_Impl;
  typedef ComponentFactory_Impl * ComponentFactory_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactory_Impl> ComponentFactory;

  // Forward declarations for AttributeDelegate
  class AttributeDelegate_Impl;
  typedef AttributeDelegate_Impl * AttributeDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeDelegate_Impl> AttributeDelegate;

  // Forward declarations for Exception
  class Exception_Impl;
  typedef Exception_Impl * Exception_in;
  typedef ::GAME::Mga::Smart_Ptr <Exception_Impl> Exception;

  // Forward declarations for LongInteger
  class LongInteger_Impl;
  typedef LongInteger_Impl * LongInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <LongInteger_Impl> LongInteger;

  // Forward declarations for LongLongInteger
  class LongLongInteger_Impl;
  typedef LongLongInteger_Impl * LongLongInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <LongLongInteger_Impl> LongLongInteger;

  // Forward declarations for GenericValue
  class GenericValue_Impl;
  typedef GenericValue_Impl * GenericValue_in;
  typedef ::GAME::Mga::Smart_Ptr <GenericValue_Impl> GenericValue;

  // Forward declarations for CharType
  class CharType_Impl;
  typedef CharType_Impl * CharType_in;
  typedef ::GAME::Mga::Smart_Ptr <CharType_Impl> CharType;

  // Forward declarations for DoWhileState
  class DoWhileState_Impl;
  typedef DoWhileState_Impl * DoWhileState_in;
  typedef ::GAME::Mga::Smart_Ptr <DoWhileState_Impl> DoWhileState;

  // Forward declarations for QueryInputAction
  class QueryInputAction_Impl;
  typedef QueryInputAction_Impl * QueryInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <QueryInputAction_Impl> QueryInputAction;

  // Forward declarations for DeploymentPlans
  class DeploymentPlans_Impl;
  typedef DeploymentPlans_Impl * DeploymentPlans_in;
  typedef ::GAME::Mga::Smart_Ptr <DeploymentPlans_Impl> DeploymentPlans;

  // Forward declarations for CommonPortAttrs
  class CommonPortAttrs_Impl;
  typedef CommonPortAttrs_Impl * CommonPortAttrs_in;
  typedef ::GAME::Mga::Smart_Ptr <CommonPortAttrs_Impl> CommonPortAttrs;

  // Forward declarations for SupportsInterfaces
  class SupportsInterfaces_Impl;
  typedef SupportsInterfaces_Impl * SupportsInterfaces_in;
  typedef ::GAME::Mga::Smart_Ptr <SupportsInterfaces_Impl> SupportsInterfaces;

  // Forward declarations for ImplementationContainer
  class ImplementationContainer_Impl;
  typedef ImplementationContainer_Impl * ImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationContainer_Impl> ImplementationContainer;

  // Forward declarations for ConnectorInstance
  class ConnectorInstance_Impl;
  typedef ConnectorInstance_Impl * ConnectorInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorInstance_Impl> ConnectorInstance;

  // Forward declarations for ProvidedRequestPort
  class ProvidedRequestPort_Impl;
  typedef ProvidedRequestPort_Impl * ProvidedRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ProvidedRequestPort_Impl> ProvidedRequestPort;

  // Forward declarations for Environment
  class Environment_Impl;
  typedef Environment_Impl * Environment_in;
  typedef ::GAME::Mga::Smart_Ptr <Environment_Impl> Environment;

  // Forward declarations for ImplementationArtifacts
  class ImplementationArtifacts_Impl;
  typedef ImplementationArtifacts_Impl * ImplementationArtifacts_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationArtifacts_Impl> ImplementationArtifacts;

  // Forward declarations for ApplicationTask
  class ApplicationTask_Impl;
  typedef ApplicationTask_Impl * ApplicationTask_in;
  typedef ::GAME::Mga::Smart_Ptr <ApplicationTask_Impl> ApplicationTask;

  // Forward declarations for WhileState
  class WhileState_Impl;
  typedef WhileState_Impl * WhileState_in;
  typedef ::GAME::Mga::Smart_Ptr <WhileState_Impl> WhileState;

  // Forward declarations for LookupKeyType
  class LookupKeyType_Impl;
  typedef LookupKeyType_Impl * LookupKeyType_in;
  typedef ::GAME::Mga::Smart_Ptr <LookupKeyType_Impl> LookupKeyType;

  // Forward declarations for Property
  class Property_Impl;
  typedef Property_Impl * Property_in;
  typedef ::GAME::Mga::Smart_Ptr <Property_Impl> Property;

  // Forward declarations for Operation
  class Operation_Impl;
  typedef Operation_Impl * Operation_in;
  typedef ::GAME::Mga::Smart_Ptr <Operation_Impl> Operation;

  // Forward declarations for ComponentFactoryImplementations
  class ComponentFactoryImplementations_Impl;
  typedef ComponentFactoryImplementations_Impl * ComponentFactoryImplementations_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactoryImplementations_Impl> ComponentFactoryImplementations;

  // Forward declarations for ComponentImplementations
  class ComponentImplementations_Impl;
  typedef ComponentImplementations_Impl * ComponentImplementations_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementations_Impl> ComponentImplementations;

  // Forward declarations for BehaviorInputAction
  class BehaviorInputAction_Impl;
  typedef BehaviorInputAction_Impl * BehaviorInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <BehaviorInputAction_Impl> BehaviorInputAction;

  // Forward declarations for ComponentInstanceType
  class ComponentInstanceType_Impl;
  typedef ComponentInstanceType_Impl * ComponentInstanceType_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInstanceType_Impl> ComponentInstanceType;

  // Forward declarations for Node
  class Node_Impl;
  typedef Node_Impl * Node_in;
  typedef ::GAME::Mga::Smart_Ptr <Node_Impl> Node;

  // Forward declarations for ActionBase
  class ActionBase_Impl;
  typedef ActionBase_Impl * ActionBase_in;
  typedef ::GAME::Mga::Smart_Ptr <ActionBase_Impl> ActionBase;

  // Forward declarations for Taggable
  class Taggable_Impl;
  typedef Taggable_Impl * Taggable_in;
  typedef ::GAME::Mga::Smart_Ptr <Taggable_Impl> Taggable;

  // Forward declarations for MPC
  class MPC_Impl;
  typedef MPC_Impl * MPC_in;
  typedef ::GAME::Mga::Smart_Ptr <MPC_Impl> MPC;

  // Forward declarations for ComponentFactoryRef
  class ComponentFactoryRef_Impl;
  typedef ComponentFactoryRef_Impl * ComponentFactoryRef_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactoryRef_Impl> ComponentFactoryRef;

  // Forward declarations for CollocationGroup
  class CollocationGroup_Impl;
  typedef CollocationGroup_Impl * CollocationGroup_in;
  typedef ::GAME::Mga::Smart_Ptr <CollocationGroup_Impl> CollocationGroup;

  // Forward declarations for AttributeMappingValue
  class AttributeMappingValue_Impl;
  typedef AttributeMappingValue_Impl * AttributeMappingValue_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeMappingValue_Impl> AttributeMappingValue;

  // Forward declarations for Prefixable
  class Prefixable_Impl;
  typedef Prefixable_Impl * Prefixable_in;
  typedef ::GAME::Mga::Smart_Ptr <Prefixable_Impl> Prefixable;

  // Forward declarations for PackageConfSelectRequirement
  class PackageConfSelectRequirement_Impl;
  typedef PackageConfSelectRequirement_Impl * PackageConfSelectRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfSelectRequirement_Impl> PackageConfSelectRequirement;

  // Forward declarations for ComponentOperation
  class ComponentOperation_Impl;
  typedef ComponentOperation_Impl * ComponentOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentOperation_Impl> ComponentOperation;

  // Forward declarations for ComponentFactoryImplementationContainer
  class ComponentFactoryImplementationContainer_Impl;
  typedef ComponentFactoryImplementationContainer_Impl * ComponentFactoryImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactoryImplementationContainer_Impl> ComponentFactoryImplementationContainer;

  // Forward declarations for PackageConfSpecializedConfig
  class PackageConfSpecializedConfig_Impl;
  typedef PackageConfSpecializedConfig_Impl * PackageConfSpecializedConfig_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfSpecializedConfig_Impl> PackageConfSpecializedConfig;

  // Forward declarations for ComponentRef
  class ComponentRef_Impl;
  typedef ComponentRef_Impl * ComponentRef_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentRef_Impl> ComponentRef;

  // Forward declarations for RequiredRequestPort
  class RequiredRequestPort_Impl;
  typedef RequiredRequestPort_Impl * RequiredRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPort_Impl> RequiredRequestPort;

  // Forward declarations for Port
  class Port_Impl;
  typedef Port_Impl * Port_in;
  typedef ::GAME::Mga::Smart_Ptr <Port_Impl> Port;

  // Forward declarations for Requirement
  class Requirement_Impl;
  typedef Requirement_Impl * Requirement_in;
  typedef ::GAME::Mga::Smart_Ptr <Requirement_Impl> Requirement;

  // Forward declarations for Targets
  class Targets_Impl;
  typedef Targets_Impl * Targets_in;
  typedef ::GAME::Mga::Smart_Ptr <Targets_Impl> Targets;

  // Forward declarations for ConnectorImplementations
  class ConnectorImplementations_Impl;
  typedef ConnectorImplementations_Impl * ConnectorImplementations_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplementations_Impl> ConnectorImplementations;

  // Forward declarations for PackageContainer
  class PackageContainer_Impl;
  typedef PackageContainer_Impl * PackageContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageContainer_Impl> PackageContainer;

  // Forward declarations for Label
  class Label_Impl;
  typedef Label_Impl * Label_in;
  typedef ::GAME::Mga::Smart_Ptr <Label_Impl> Label;

  // Forward declarations for NativeValue
  class NativeValue_Impl;
  typedef NativeValue_Impl * NativeValue_in;
  typedef ::GAME::Mga::Smart_Ptr <NativeValue_Impl> NativeValue;

  // Forward declarations for ExtendedPortDelegate
  class ExtendedPortDelegate_Impl;
  typedef ExtendedPortDelegate_Impl * ExtendedPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortDelegate_Impl> ExtendedPortDelegate;

  // Forward declarations for ComponentPropertyDescription
  class ComponentPropertyDescription_Impl;
  typedef ComponentPropertyDescription_Impl * ComponentPropertyDescription_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentPropertyDescription_Impl> ComponentPropertyDescription;

  // Forward declarations for Workspaces
  class Workspaces_Impl;
  typedef Workspaces_Impl * Workspaces_in;
  typedef ::GAME::Mga::Smart_Ptr <Workspaces_Impl> Workspaces;

  // Forward declarations for RTRequirements
  class RTRequirements_Impl;
  typedef RTRequirements_Impl * RTRequirements_in;
  typedef ::GAME::Mga::Smart_Ptr <RTRequirements_Impl> RTRequirements;

  // Forward declarations for WorkerLibraries
  class WorkerLibraries_Impl;
  typedef WorkerLibraries_Impl * WorkerLibraries_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerLibraries_Impl> WorkerLibraries;

  // Forward declarations for ConnectorImplementationContainer
  class ConnectorImplementationContainer_Impl;
  typedef ConnectorImplementationContainer_Impl * ConnectorImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplementationContainer_Impl> ConnectorImplementationContainer;

  // Forward declarations for Member
  class Member_Impl;
  typedef Member_Impl * Member_in;
  typedef ::GAME::Mga::Smart_Ptr <Member_Impl> Member;

  // Forward declarations for RequiredRequestPortEnd
  class RequiredRequestPortEnd_Impl;
  typedef RequiredRequestPortEnd_Impl * RequiredRequestPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPortEnd_Impl> RequiredRequestPortEnd;

  // Forward declarations for Alias
  class Alias_Impl;
  typedef Alias_Impl * Alias_in;
  typedef ::GAME::Mga::Smart_Ptr <Alias_Impl> Alias;

  // Forward declarations for PeriodicBenchmarks
  class PeriodicBenchmarks_Impl;
  typedef PeriodicBenchmarks_Impl * PeriodicBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr <PeriodicBenchmarks_Impl> PeriodicBenchmarks;

  // Forward declarations for Shares
  class Shares_Impl;
  typedef Shares_Impl * Shares_in;
  typedef ::GAME::Mga::Smart_Ptr <Shares_Impl> Shares;

  // Forward declarations for Maximum
  class Maximum_Impl;
  typedef Maximum_Impl * Maximum_in;
  typedef ::GAME::Mga::Smart_Ptr <Maximum_Impl> Maximum;

  // Forward declarations for ArtifactContainer
  class ArtifactContainer_Impl;
  typedef ArtifactContainer_Impl * ArtifactContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactContainer_Impl> ArtifactContainer;

  // Forward declarations for TemplatePackageInstance
  class TemplatePackageInstance_Impl;
  typedef TemplatePackageInstance_Impl * TemplatePackageInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplatePackageInstance_Impl> TemplatePackageInstance;

  // Forward declarations for Package
  class Package_Impl;
  typedef Package_Impl * Package_in;
  typedef ::GAME::Mga::Smart_Ptr <Package_Impl> Package;

  // Forward declarations for DataType
  class DataType_Impl;
  typedef DataType_Impl * DataType_in;
  typedef ::GAME::Mga::Smart_Ptr <DataType_Impl> DataType;

  // Forward declarations for ComponentAssemblyReference
  class ComponentAssemblyReference_Impl;
  typedef ComponentAssemblyReference_Impl * ComponentAssemblyReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentAssemblyReference_Impl> ComponentAssemblyReference;

  // Forward declarations for TypeKind
  class TypeKind_Impl;
  typedef TypeKind_Impl * TypeKind_in;
  typedef ::GAME::Mga::Smart_Ptr <TypeKind_Impl> TypeKind;

  // Forward declarations for TargetRequiredRequestPort
  class TargetRequiredRequestPort_Impl;
  typedef TargetRequiredRequestPort_Impl * TargetRequiredRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr <TargetRequiredRequestPort_Impl> TargetRequiredRequestPort;

  // Forward declarations for LookupOperation
  class LookupOperation_Impl;
  typedef LookupOperation_Impl * LookupOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <LookupOperation_Impl> LookupOperation;

  // Forward declarations for GraphVertex
  class GraphVertex_Impl;
  typedef GraphVertex_Impl * GraphVertex_in;
  typedef ::GAME::Mga::Smart_Ptr <GraphVertex_Impl> GraphVertex;

  // Forward declarations for TopLevelPackageContainer
  class TopLevelPackageContainer_Impl;
  typedef TopLevelPackageContainer_Impl * TopLevelPackageContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelPackageContainer_Impl> TopLevelPackageContainer;

  // Forward declarations for ComponentInstanceRef
  class ComponentInstanceRef_Impl;
  typedef ComponentInstanceRef_Impl * ComponentInstanceRef_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInstanceRef_Impl> ComponentInstanceRef;

  // Forward declarations for SignedIntegerType
  class SignedIntegerType_Impl;
  typedef SignedIntegerType_Impl * SignedIntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr <SignedIntegerType_Impl> SignedIntegerType;

  // Forward declarations for SupportsInstance
  class SupportsInstance_Impl;
  typedef SupportsInstance_Impl * SupportsInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <SupportsInstance_Impl> SupportsInstance;

  // Forward declarations for ConnectorType
  class ConnectorType_Impl;
  typedef ConnectorType_Impl * ConnectorType_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorType_Impl> ConnectorType;

  // Forward declarations for EffectBase
  class EffectBase_Impl;
  typedef EffectBase_Impl * EffectBase_in;
  typedef ::GAME::Mga::Smart_Ptr <EffectBase_Impl> EffectBase;

  // Forward declarations for ParameterType
  class ParameterType_Impl;
  typedef ParameterType_Impl * ParameterType_in;
  typedef ::GAME::Mga::Smart_Ptr <ParameterType_Impl> ParameterType;

  // Forward declarations for AttributeMember
  class AttributeMember_Impl;
  typedef AttributeMember_Impl * AttributeMember_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeMember_Impl> AttributeMember;

  // Forward declarations for MetricsBase
  class MetricsBase_Impl;
  typedef MetricsBase_Impl * MetricsBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MetricsBase_Impl> MetricsBase;

  // Forward declarations for OutEventPortInstance
  class OutEventPortInstance_Impl;
  typedef OutEventPortInstance_Impl * OutEventPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <OutEventPortInstance_Impl> OutEventPortInstance;

  // Forward declarations for ReceptacleDelegate
  class ReceptacleDelegate_Impl;
  typedef ReceptacleDelegate_Impl * ReceptacleDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ReceptacleDelegate_Impl> ReceptacleDelegate;

  // Forward declarations for BranchState
  class BranchState_Impl;
  typedef BranchState_Impl * BranchState_in;
  typedef ::GAME::Mga::Smart_Ptr <BranchState_Impl> BranchState;

  // Forward declarations for ImplementationRequirement
  class ImplementationRequirement_Impl;
  typedef ImplementationRequirement_Impl * ImplementationRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationRequirement_Impl> ImplementationRequirement;

  // Forward declarations for WorkerLibrary
  class WorkerLibrary_Impl;
  typedef WorkerLibrary_Impl * WorkerLibrary_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerLibrary_Impl> WorkerLibrary;

  // Forward declarations for ComponentTypes
  class ComponentTypes_Impl;
  typedef ComponentTypes_Impl * ComponentTypes_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentTypes_Impl> ComponentTypes;

  // Forward declarations for Minimum
  class Minimum_Impl;
  typedef Minimum_Impl * Minimum_in;
  typedef ::GAME::Mga::Smart_Ptr <Minimum_Impl> Minimum;

  // Forward declarations for File
  class File_Impl;
  typedef File_Impl * File_in;
  typedef ::GAME::Mga::Smart_Ptr <File_Impl> File;

  // Forward declarations for ExtendedPortInstanceBase
  class ExtendedPortInstanceBase_Impl;
  typedef ExtendedPortInstanceBase_Impl * ExtendedPortInstanceBase_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortInstanceBase_Impl> ExtendedPortInstanceBase;

  // Forward declarations for MirrorPortInstanceBase
  class MirrorPortInstanceBase_Impl;
  typedef MirrorPortInstanceBase_Impl * MirrorPortInstanceBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorPortInstanceBase_Impl> MirrorPortInstanceBase;

  // Forward declarations for SingleInputBase
  class SingleInputBase_Impl;
  typedef SingleInputBase_Impl * SingleInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <SingleInputBase_Impl> SingleInputBase;

  // Forward declarations for ConnectedComponent
  class ConnectedComponent_Impl;
  typedef ConnectedComponent_Impl * ConnectedComponent_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectedComponent_Impl> ConnectedComponent;

  // Forward declarations for ECRequirements
  class ECRequirements_Impl;
  typedef ECRequirements_Impl * ECRequirements_in;
  typedef ::GAME::Mga::Smart_Ptr <ECRequirements_Impl> ECRequirements;

  // Forward declarations for UnsignedLongInteger
  class UnsignedLongInteger_Impl;
  typedef UnsignedLongInteger_Impl * UnsignedLongInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <UnsignedLongInteger_Impl> UnsignedLongInteger;

  // Forward declarations for InoutParameter
  class InoutParameter_Impl;
  typedef InoutParameter_Impl * InoutParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <InoutParameter_Impl> InoutParameter;

  // Forward declarations for RequiredRequestPortDelegate
  class RequiredRequestPortDelegate_Impl;
  typedef RequiredRequestPortDelegate_Impl * RequiredRequestPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPortDelegate_Impl> RequiredRequestPortDelegate;

  // Forward declarations for ConnectorImplementation
  class ConnectorImplementation_Impl;
  typedef ConnectorImplementation_Impl * ConnectorImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplementation_Impl> ConnectorImplementation;

  // Forward declarations for BenchmarkType
  class BenchmarkType_Impl;
  typedef BenchmarkType_Impl * BenchmarkType_in;
  typedef ::GAME::Mga::Smart_Ptr <BenchmarkType_Impl> BenchmarkType;

  // Forward declarations for TemplateParameterValueType
  class TemplateParameterValueType_Impl;
  typedef TemplateParameterValueType_Impl * TemplateParameterValueType_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplateParameterValueType_Impl> TemplateParameterValueType;

  // Forward declarations for MultiInput
  class MultiInput_Impl;
  typedef MultiInput_Impl * MultiInput_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiInput_Impl> MultiInput;

  // Forward declarations for Transition
  class Transition_Impl;
  typedef Transition_Impl * Transition_in;
  typedef ::GAME::Mga::Smart_Ptr <Transition_Impl> Transition;

  // Forward declarations for TerminalTransition
  class TerminalTransition_Impl;
  typedef TerminalTransition_Impl * TerminalTransition_in;
  typedef ::GAME::Mga::Smart_Ptr <TerminalTransition_Impl> TerminalTransition;

  // Forward declarations for ComponentLib
  class ComponentLib_Impl;
  typedef ComponentLib_Impl * ComponentLib_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentLib_Impl> ComponentLib;

  // Forward declarations for ExtendedPort
  class ExtendedPort_Impl;
  typedef ExtendedPort_Impl * ExtendedPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPort_Impl> ExtendedPort;

  // Forward declarations for PeriodicEvent
  class PeriodicEvent_Impl;
  typedef PeriodicEvent_Impl * PeriodicEvent_in;
  typedef ::GAME::Mga::Smart_Ptr <PeriodicEvent_Impl> PeriodicEvent;

  // Forward declarations for ImplementationDependency
  class ImplementationDependency_Impl;
  typedef ImplementationDependency_Impl * ImplementationDependency_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationDependency_Impl> ImplementationDependency;

  // Forward declarations for Aggregate
  class Aggregate_Impl;
  typedef Aggregate_Impl * Aggregate_in;
  typedef ::GAME::Mga::Smart_Ptr <Aggregate_Impl> Aggregate;

  // Forward declarations for GenericValueObject
  class GenericValueObject_Impl;
  typedef GenericValueObject_Impl * GenericValueObject_in;
  typedef ::GAME::Mga::Smart_Ptr <GenericValueObject_Impl> GenericValueObject;

  // Forward declarations for AssemblyselectRequirement
  class AssemblyselectRequirement_Impl;
  typedef AssemblyselectRequirement_Impl * AssemblyselectRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <AssemblyselectRequirement_Impl> AssemblyselectRequirement;

  // Forward declarations for ComplexProperty
  class ComplexProperty_Impl;
  typedef ComplexProperty_Impl * ComplexProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ComplexProperty_Impl> ComplexProperty;

  // Forward declarations for ArtifactDependency
  class ArtifactDependency_Impl;
  typedef ArtifactDependency_Impl * ArtifactDependency_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactDependency_Impl> ArtifactDependency;

  // Forward declarations for FactoryOperation
  class FactoryOperation_Impl;
  typedef FactoryOperation_Impl * FactoryOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <FactoryOperation_Impl> FactoryOperation;

  // Forward declarations for UnsignedIntegerType
  class UnsignedIntegerType_Impl;
  typedef UnsignedIntegerType_Impl * UnsignedIntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr <UnsignedIntegerType_Impl> UnsignedIntegerType;

  // Forward declarations for ConnectorToReceptacle
  class ConnectorToReceptacle_Impl;
  typedef ConnectorToReceptacle_Impl * ConnectorToReceptacle_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorToReceptacle_Impl> ConnectorToReceptacle;

  // Forward declarations for EdgeProperty
  class EdgeProperty_Impl;
  typedef EdgeProperty_Impl * EdgeProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <EdgeProperty_Impl> EdgeProperty;

  // Forward declarations for MetricConnection
  class MetricConnection_Impl;
  typedef MetricConnection_Impl * MetricConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <MetricConnection_Impl> MetricConnection;

  // Forward declarations for Implemenation
  class Implemenation_Impl;
  typedef Implemenation_Impl * Implemenation_in;
  typedef ::GAME::Mga::Smart_Ptr <Implemenation_Impl> Implemenation;

  // Forward declarations for WideString
  class WideString_Impl;
  typedef WideString_Impl * WideString_in;
  typedef ::GAME::Mga::Smart_Ptr <WideString_Impl> WideString;

  // Forward declarations for PrivateFlag
  class PrivateFlag_Impl;
  typedef PrivateFlag_Impl * PrivateFlag_in;
  typedef ::GAME::Mga::Smart_Ptr <PrivateFlag_Impl> PrivateFlag;

  // Forward declarations for ProvidedRequestPortInstance
  class ProvidedRequestPortInstance_Impl;
  typedef ProvidedRequestPortInstance_Impl * ProvidedRequestPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ProvidedRequestPortInstance_Impl> ProvidedRequestPortInstance;

  // Forward declarations for ExtendedDelegate
  class ExtendedDelegate_Impl;
  typedef ExtendedDelegate_Impl * ExtendedDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedDelegate_Impl> ExtendedDelegate;

  // Forward declarations for WorkerType
  class WorkerType_Impl;
  typedef WorkerType_Impl * WorkerType_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerType_Impl> WorkerType;

  // Forward declarations for MirrorPort
  class MirrorPort_Impl;
  typedef MirrorPort_Impl * MirrorPort_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorPort_Impl> MirrorPort;

  // Forward declarations for PathDiagrams
  class PathDiagrams_Impl;
  typedef PathDiagrams_Impl * PathDiagrams_in;
  typedef ::GAME::Mga::Smart_Ptr <PathDiagrams_Impl> PathDiagrams;

  // Forward declarations for CriticalPath
  class CriticalPath_Impl;
  typedef CriticalPath_Impl * CriticalPath_in;
  typedef ::GAME::Mga::Smart_Ptr <CriticalPath_Impl> CriticalPath;

  // Forward declarations for StubProject
  class StubProject_Impl;
  typedef StubProject_Impl * StubProject_in;
  typedef ::GAME::Mga::Smart_Ptr <StubProject_Impl> StubProject;

  // Forward declarations for ServantProject
  class ServantProject_Impl;
  typedef ServantProject_Impl * ServantProject_in;
  typedef ::GAME::Mga::Smart_Ptr <ServantProject_Impl> ServantProject;

  // Forward declarations for Throughput
  class Throughput_Impl;
  typedef Throughput_Impl * Throughput_in;
  typedef ::GAME::Mga::Smart_Ptr <Throughput_Impl> Throughput;

  // Forward declarations for ComponentAnalyses
  class ComponentAnalyses_Impl;
  typedef ComponentAnalyses_Impl * ComponentAnalyses_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentAnalyses_Impl> ComponentAnalyses;

  // Forward declarations for Paths
  class Paths_Impl;
  typedef Paths_Impl * Paths_in;
  typedef ::GAME::Mga::Smart_Ptr <Paths_Impl> Paths;

  // Forward declarations for ComponentInherits
  class ComponentInherits_Impl;
  typedef ComponentInherits_Impl * ComponentInherits_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInherits_Impl> ComponentInherits;

  // Forward declarations for WorkerPackage
  class WorkerPackage_Impl;
  typedef WorkerPackage_Impl * WorkerPackage_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerPackage_Impl> WorkerPackage;

  // Forward declarations for Provideable
  class Provideable_Impl;
  typedef Provideable_Impl * Provideable_in;
  typedef ::GAME::Mga::Smart_Ptr <Provideable_Impl> Provideable;

  // Forward declarations for ExternalDelegate
  class ExternalDelegate_Impl;
  typedef ExternalDelegate_Impl * ExternalDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalDelegate_Impl> ExternalDelegate;

  // Forward declarations for TaskSet
  class TaskSet_Impl;
  typedef TaskSet_Impl * TaskSet_in;
  typedef ::GAME::Mga::Smart_Ptr <TaskSet_Impl> TaskSet;

  // Forward declarations for ComponentConfigProperty
  class ComponentConfigProperty_Impl;
  typedef ComponentConfigProperty_Impl * ComponentConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentConfigProperty_Impl> ComponentConfigProperty;

  // Forward declarations for PackageConfBasePackage
  class PackageConfBasePackage_Impl;
  typedef PackageConfBasePackage_Impl * PackageConfBasePackage_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfBasePackage_Impl> PackageConfBasePackage;

  // Forward declarations for InputEffect
  class InputEffect_Impl;
  typedef InputEffect_Impl * InputEffect_in;
  typedef ::GAME::Mga::Smart_Ptr <InputEffect_Impl> InputEffect;

  // Forward declarations for CollocationGroupMember
  class CollocationGroupMember_Impl;
  typedef CollocationGroupMember_Impl * CollocationGroupMember_in;
  typedef ::GAME::Mga::Smart_Ptr <CollocationGroupMember_Impl> CollocationGroupMember;

  // Forward declarations for WorkerFile
  class WorkerFile_Impl;
  typedef WorkerFile_Impl * WorkerFile_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerFile_Impl> WorkerFile;

  // Forward declarations for ForState
  class ForState_Impl;
  typedef ForState_Impl * ForState_in;
  typedef ::GAME::Mga::Smart_Ptr <ForState_Impl> ForState;

  // Forward declarations for PackageConfigurations
  class PackageConfigurations_Impl;
  typedef PackageConfigurations_Impl * PackageConfigurations_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfigurations_Impl> PackageConfigurations;

  // Forward declarations for HasExceptions
  class HasExceptions_Impl;
  typedef HasExceptions_Impl * HasExceptions_in;
  typedef ::GAME::Mga::Smart_Ptr <HasExceptions_Impl> HasExceptions;

  // Forward declarations for TopLevelPackage
  class TopLevelPackage_Impl;
  typedef TopLevelPackage_Impl * TopLevelPackage_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelPackage_Impl> TopLevelPackage;

  // Forward declarations for Enum
  class Enum_Impl;
  typedef Enum_Impl * Enum_in;
  typedef ::GAME::Mga::Smart_Ptr <Enum_Impl> Enum;

  // Forward declarations for Worker
  class Worker_Impl;
  typedef Worker_Impl * Worker_in;
  typedef ::GAME::Mga::Smart_Ptr <Worker_Impl> Worker;

  // Forward declarations for MirrorPortDelegate
  class MirrorPortDelegate_Impl;
  typedef MirrorPortDelegate_Impl * MirrorPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorPortDelegate_Impl> MirrorPortDelegate;

  // Forward declarations for LongDoubleNumber
  class LongDoubleNumber_Impl;
  typedef LongDoubleNumber_Impl * LongDoubleNumber_in;
  typedef ::GAME::Mga::Smart_Ptr <LongDoubleNumber_Impl> LongDoubleNumber;

  // Forward declarations for ServiceConsumer
  class ServiceConsumer_Impl;
  typedef ServiceConsumer_Impl * ServiceConsumer_in;
  typedef ::GAME::Mga::Smart_Ptr <ServiceConsumer_Impl> ServiceConsumer;

  // Forward declarations for ReturnType
  class ReturnType_Impl;
  typedef ReturnType_Impl * ReturnType_in;
  typedef ::GAME::Mga::Smart_Ptr <ReturnType_Impl> ReturnType;

  // Forward declarations for GenericObject
  class GenericObject_Impl;
  typedef GenericObject_Impl * GenericObject_in;
  typedef ::GAME::Mga::Smart_Ptr <GenericObject_Impl> GenericObject;

  // Forward declarations for DeploymentPlan
  class DeploymentPlan_Impl;
  typedef DeploymentPlan_Impl * DeploymentPlan_in;
  typedef ::GAME::Mga::Smart_Ptr <DeploymentPlan_Impl> DeploymentPlan;

  // Forward declarations for CallAction
  class CallAction_Impl;
  typedef CallAction_Impl * CallAction_in;
  typedef ::GAME::Mga::Smart_Ptr <CallAction_Impl> CallAction;

  // Forward declarations for MultipleServiceRequests
  class MultipleServiceRequests_Impl;
  typedef MultipleServiceRequests_Impl * MultipleServiceRequests_in;
  typedef ::GAME::Mga::Smart_Ptr <MultipleServiceRequests_Impl> MultipleServiceRequests;

  // Forward declarations for ServiceProvider
  class ServiceProvider_Impl;
  typedef ServiceProvider_Impl * ServiceProvider_in;
  typedef ::GAME::Mga::Smart_Ptr <ServiceProvider_Impl> ServiceProvider;

  // Forward declarations for LoopTransition
  class LoopTransition_Impl;
  typedef LoopTransition_Impl * LoopTransition_in;
  typedef ::GAME::Mga::Smart_Ptr <LoopTransition_Impl> LoopTransition;

  // Forward declarations for TopLevelPackages
  class TopLevelPackages_Impl;
  typedef TopLevelPackages_Impl * TopLevelPackages_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelPackages_Impl> TopLevelPackages;

  // Forward declarations for MirrorPortInstance
  class MirrorPortInstance_Impl;
  typedef MirrorPortInstance_Impl * MirrorPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorPortInstance_Impl> MirrorPortInstance;

  // Forward declarations for ComponentInstance
  class ComponentInstance_Impl;
  typedef ComponentInstance_Impl * ComponentInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInstance_Impl> ComponentInstance;

  // Forward declarations for Inheritable
  class Inheritable_Impl;
  typedef Inheritable_Impl * Inheritable_in;
  typedef ::GAME::Mga::Smart_Ptr <Inheritable_Impl> Inheritable;

  // Forward declarations for AssemblyConfigPropertyEnd
  class AssemblyConfigPropertyEnd_Impl;
  typedef AssemblyConfigPropertyEnd_Impl * AssemblyConfigPropertyEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <AssemblyConfigPropertyEnd_Impl> AssemblyConfigPropertyEnd;

  // Forward declarations for ComponentInfoProperty
  class ComponentInfoProperty_Impl;
  typedef ComponentInfoProperty_Impl * ComponentInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInfoProperty_Impl> ComponentInfoProperty;

  // Forward declarations for Boolean
  class Boolean_Impl;
  typedef Boolean_Impl * Boolean_in;
  typedef ::GAME::Mga::Smart_Ptr <Boolean_Impl> Boolean;

  // Forward declarations for WorkLoadOperationConnection
  class WorkLoadOperationConnection_Impl;
  typedef WorkLoadOperationConnection_Impl * WorkLoadOperationConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkLoadOperationConnection_Impl> WorkLoadOperationConnection;

  // Forward declarations for TemplatePackageAlias
  class TemplatePackageAlias_Impl;
  typedef TemplatePackageAlias_Impl * TemplatePackageAlias_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplatePackageAlias_Impl> TemplatePackageAlias;

  // Forward declarations for ComponentPackages
  class ComponentPackages_Impl;
  typedef ComponentPackages_Impl * ComponentPackages_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentPackages_Impl> ComponentPackages;

  // Forward declarations for ShortInteger
  class ShortInteger_Impl;
  typedef ShortInteger_Impl * ShortInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <ShortInteger_Impl> ShortInteger;

  // Forward declarations for RequirementSatisfier
  class RequirementSatisfier_Impl;
  typedef RequirementSatisfier_Impl * RequirementSatisfier_in;
  typedef ::GAME::Mga::Smart_Ptr <RequirementSatisfier_Impl> RequirementSatisfier;

  // Forward declarations for TypeEncoding
  class TypeEncoding_Impl;
  typedef TypeEncoding_Impl * TypeEncoding_in;
  typedef ::GAME::Mga::Smart_Ptr <TypeEncoding_Impl> TypeEncoding;

  // Forward declarations for TimeProbe
  class TimeProbe_Impl;
  typedef TimeProbe_Impl * TimeProbe_in;
  typedef ::GAME::Mga::Smart_Ptr <TimeProbe_Impl> TimeProbe;

  // Forward declarations for ExtendedPortInstance
  class ExtendedPortInstance_Impl;
  typedef ExtendedPortInstance_Impl * ExtendedPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortInstance_Impl> ExtendedPortInstance;

  // Forward declarations for MirrorDelegate
  class MirrorDelegate_Impl;
  typedef MirrorDelegate_Impl * MirrorDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorDelegate_Impl> MirrorDelegate;

  // Forward declarations for ExternalPort
  class ExternalPort_Impl;
  typedef ExternalPort_Impl * ExternalPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalPort_Impl> ExternalPort;

  // Forward declarations for ComponentAssembly
  class ComponentAssembly_Impl;
  typedef ComponentAssembly_Impl * ComponentAssembly_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentAssembly_Impl> ComponentAssembly;

  // Forward declarations for LabelConnection
  class LabelConnection_Impl;
  typedef LabelConnection_Impl * LabelConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <LabelConnection_Impl> LabelConnection;

  // Forward declarations for ECBehavior
  class ECBehavior_Impl;
  typedef ECBehavior_Impl * ECBehavior_in;
  typedef ::GAME::Mga::Smart_Ptr <ECBehavior_Impl> ECBehavior;

  // Forward declarations for MultiOutputBase
  class MultiOutputBase_Impl;
  typedef MultiOutputBase_Impl * MultiOutputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiOutputBase_Impl> MultiOutputBase;

  // Forward declarations for ComplexType
  class ComplexType_Impl;
  typedef ComplexType_Impl * ComplexType_in;
  typedef ::GAME::Mga::Smart_Ptr <ComplexType_Impl> ComplexType;

  // Forward declarations for ExtendedPortBase
  class ExtendedPortBase_Impl;
  typedef ExtendedPortBase_Impl * ExtendedPortBase_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortBase_Impl> ExtendedPortBase;

  // Forward declarations for CollocationGroupProperty
  class CollocationGroupProperty_Impl;
  typedef CollocationGroupProperty_Impl * CollocationGroupProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <CollocationGroupProperty_Impl> CollocationGroupProperty;

  // Forward declarations for MultiInputAction
  class MultiInputAction_Impl;
  typedef MultiInputAction_Impl * MultiInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiInputAction_Impl> MultiInputAction;

  // Forward declarations for ComplexTypeReference
  class ComplexTypeReference_Impl;
  typedef ComplexTypeReference_Impl * ComplexTypeReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComplexTypeReference_Impl> ComplexTypeReference;

  // Forward declarations for NoInheritable
  class NoInheritable_Impl;
  typedef NoInheritable_Impl * NoInheritable_in;
  typedef ::GAME::Mga::Smart_Ptr <NoInheritable_Impl> NoInheritable;

  // Forward declarations for LookupKey
  class LookupKey_Impl;
  typedef LookupKey_Impl * LookupKey_in;
  typedef ::GAME::Mga::Smart_Ptr <LookupKey_Impl> LookupKey;

  // Forward declarations for MonolithicImplementation
  class MonolithicImplementation_Impl;
  typedef MonolithicImplementation_Impl * MonolithicImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithicImplementation_Impl> MonolithicImplementation;

  // Forward declarations for ObjectByValue
  class ObjectByValue_Impl;
  typedef ObjectByValue_Impl * ObjectByValue_in;
  typedef ::GAME::Mga::Smart_Ptr <ObjectByValue_Impl> ObjectByValue;

  // Forward declarations for ComponentImplementationArtifact
  class ComponentImplementationArtifact_Impl;
  typedef ComponentImplementationArtifact_Impl * ComponentImplementationArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementationArtifact_Impl> ComponentImplementationArtifact;

  // Forward declarations for Object
  class Object_Impl;
  typedef Object_Impl * Object_in;
  typedef ::GAME::Mga::Smart_Ptr <Object_Impl> Object;

  // Forward declarations for CollectionParameter
  class CollectionParameter_Impl;
  typedef CollectionParameter_Impl * CollectionParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <CollectionParameter_Impl> CollectionParameter;

  // Forward declarations for ExceptionRef
  class ExceptionRef_Impl;
  typedef ExceptionRef_Impl * ExceptionRef_in;
  typedef ::GAME::Mga::Smart_Ptr <ExceptionRef_Impl> ExceptionRef;

  // Forward declarations for InEventPortDelegate
  class InEventPortDelegate_Impl;
  typedef InEventPortDelegate_Impl * InEventPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPortDelegate_Impl> InEventPortDelegate;

  // Forward declarations for Project
  class Project_Impl;
  typedef Project_Impl * Project_in;
  typedef ::GAME::Mga::Smart_Ptr <Project_Impl> Project;

  // Forward declarations for Boxed
  class Boxed_Impl;
  typedef Boxed_Impl * Boxed_in;
  typedef ::GAME::Mga::Smart_Ptr <Boxed_Impl> Boxed;

  // Forward declarations for ValueObject
  class ValueObject_Impl;
  typedef ValueObject_Impl * ValueObject_in;
  typedef ::GAME::Mga::Smart_Ptr <ValueObject_Impl> ValueObject;

  // Forward declarations for OutEventPort
  class OutEventPort_Impl;
  typedef OutEventPort_Impl * OutEventPort_in;
  typedef ::GAME::Mga::Smart_Ptr <OutEventPort_Impl> OutEventPort;

  // Forward declarations for SimpleProperty
  class SimpleProperty_Impl;
  typedef SimpleProperty_Impl * SimpleProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <SimpleProperty_Impl> SimpleProperty;

  // Forward declarations for ImplementationDependsOn
  class ImplementationDependsOn_Impl;
  typedef ImplementationDependsOn_Impl * ImplementationDependsOn_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationDependsOn_Impl> ImplementationDependsOn;

  // Forward declarations for TwowayOperation
  class TwowayOperation_Impl;
  typedef TwowayOperation_Impl * TwowayOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <TwowayOperation_Impl> TwowayOperation;

  // Forward declarations for DataValueContainer
  class DataValueContainer_Impl;
  typedef DataValueContainer_Impl * DataValueContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <DataValueContainer_Impl> DataValueContainer;

  // Forward declarations for ComponentContainer
  class ComponentContainer_Impl;
  typedef ComponentContainer_Impl * ComponentContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentContainer_Impl> ComponentContainer;

  // Forward declarations for InParameter
  class InParameter_Impl;
  typedef InParameter_Impl * InParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <InParameter_Impl> InParameter;

  // Forward declarations for DataValue
  class DataValue_Impl;
  typedef DataValue_Impl * DataValue_in;
  typedef ::GAME::Mga::Smart_Ptr <DataValue_Impl> DataValue;

  // Forward declarations for DataAnalysisBase
  class DataAnalysisBase_Impl;
  typedef DataAnalysisBase_Impl * DataAnalysisBase_in;
  typedef ::GAME::Mga::Smart_Ptr <DataAnalysisBase_Impl> DataAnalysisBase;

  // Forward declarations for PredefinedType
  class PredefinedType_Impl;
  typedef PredefinedType_Impl * PredefinedType_in;
  typedef ::GAME::Mga::Smart_Ptr <PredefinedType_Impl> PredefinedType;

  // Forward declarations for ManagesComponent
  class ManagesComponent_Impl;
  typedef ManagesComponent_Impl * ManagesComponent_in;
  typedef ::GAME::Mga::Smart_Ptr <ManagesComponent_Impl> ManagesComponent;

  // Forward declarations for ImplementationArtifact
  class ImplementationArtifact_Impl;
  typedef ImplementationArtifact_Impl * ImplementationArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationArtifact_Impl> ImplementationArtifact;

  // Forward declarations for Key
  class Key_Impl;
  typedef Key_Impl * Key_in;
  typedef ::GAME::Mga::Smart_Ptr <Key_Impl> Key;

  // Forward declarations for ComponentImplementation
  class ComponentImplementation_Impl;
  typedef ComponentImplementation_Impl * ComponentImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementation_Impl> ComponentImplementation;

  // Forward declarations for UnsignedShortInteger
  class UnsignedShortInteger_Impl;
  typedef UnsignedShortInteger_Impl * UnsignedShortInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <UnsignedShortInteger_Impl> UnsignedShortInteger;

  // Forward declarations for EventType
  class EventType_Impl;
  typedef EventType_Impl * EventType_in;
  typedef ::GAME::Mga::Smart_Ptr <EventType_Impl> EventType;

  // Forward declarations for Manageable
  class Manageable_Impl;
  typedef Manageable_Impl * Manageable_in;
  typedef ::GAME::Mga::Smart_Ptr <Manageable_Impl> Manageable;

  // Forward declarations for ComponentProperty
  class ComponentProperty_Impl;
  typedef ComponentProperty_Impl * ComponentProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentProperty_Impl> ComponentProperty;

  // Forward declarations for Invoke
  class Invoke_Impl;
  typedef Invoke_Impl * Invoke_in;
  typedef ::GAME::Mga::Smart_Ptr <Invoke_Impl> Invoke;

  // Forward declarations for MakeMemberPrivate
  class MakeMemberPrivate_Impl;
  typedef MakeMemberPrivate_Impl * MakeMemberPrivate_in;
  typedef ::GAME::Mga::Smart_Ptr <MakeMemberPrivate_Impl> MakeMemberPrivate;

  // Forward declarations for PackageInterface
  class PackageInterface_Impl;
  typedef PackageInterface_Impl * PackageInterface_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageInterface_Impl> PackageInterface;

  // Forward declarations for Component
  class Component_Impl;
  typedef Component_Impl * Component_in;
  typedef ::GAME::Mga::Smart_Ptr <Component_Impl> Component;

  // Forward declarations for ImplementationCapability
  class ImplementationCapability_Impl;
  typedef ImplementationCapability_Impl * ImplementationCapability_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationCapability_Impl> ImplementationCapability;

  // Forward declarations for BridgeConnection
  class BridgeConnection_Impl;
  typedef BridgeConnection_Impl * BridgeConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <BridgeConnection_Impl> BridgeConnection;

  // Forward declarations for BenchmarkCharacteristics
  class BenchmarkCharacteristics_Impl;
  typedef BenchmarkCharacteristics_Impl * BenchmarkCharacteristics_in;
  typedef ::GAME::Mga::Smart_Ptr <BenchmarkCharacteristics_Impl> BenchmarkCharacteristics;

  // Forward declarations for TypeParameter
  class TypeParameter_Impl;
  typedef TypeParameter_Impl * TypeParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <TypeParameter_Impl> TypeParameter;

  // Forward declarations for InstanceMapping
  class InstanceMapping_Impl;
  typedef InstanceMapping_Impl * InstanceMapping_in;
  typedef ::GAME::Mga::Smart_Ptr <InstanceMapping_Impl> InstanceMapping;

  // Forward declarations for EventRef
  class EventRef_Impl;
  typedef EventRef_Impl * EventRef_in;
  typedef ::GAME::Mga::Smart_Ptr <EventRef_Impl> EventRef;

  // Forward declarations for Effect
  class Effect_Impl;
  typedef Effect_Impl * Effect_in;
  typedef ::GAME::Mga::Smart_Ptr <Effect_Impl> Effect;

  // Forward declarations for MonolithprimaryArtifact
  class MonolithprimaryArtifact_Impl;
  typedef MonolithprimaryArtifact_Impl * MonolithprimaryArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithprimaryArtifact_Impl> MonolithprimaryArtifact;

  // Forward declarations for TriggerBenchmarks
  class TriggerBenchmarks_Impl;
  typedef TriggerBenchmarks_Impl * TriggerBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr <TriggerBenchmarks_Impl> TriggerBenchmarks;

  // Forward declarations for StringType
  class StringType_Impl;
  typedef StringType_Impl * StringType_in;
  typedef ::GAME::Mga::Smart_Ptr <StringType_Impl> StringType;

  // Forward declarations for InEventPortInstance
  class InEventPortInstance_Impl;
  typedef InEventPortInstance_Impl * InEventPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPortInstance_Impl> InEventPortInstance;

  // Forward declarations for Consume
  class Consume_Impl;
  typedef Consume_Impl * Consume_in;
  typedef ::GAME::Mga::Smart_Ptr <Consume_Impl> Consume;

  // Forward declarations for AttributeMappingDelegate
  class AttributeMappingDelegate_Impl;
  typedef AttributeMappingDelegate_Impl * AttributeMappingDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeMappingDelegate_Impl> AttributeMappingDelegate;

  // Forward declarations for RequirementBase
  class RequirementBase_Impl;
  typedef RequirementBase_Impl * RequirementBase_in;
  typedef ::GAME::Mga::Smart_Ptr <RequirementBase_Impl> RequirementBase;

  // Forward declarations for PropertyMapping
  class PropertyMapping_Impl;
  typedef PropertyMapping_Impl * PropertyMapping_in;
  typedef ::GAME::Mga::Smart_Ptr <PropertyMapping_Impl> PropertyMapping;

  // Forward declarations for FacetDelegate
  class FacetDelegate_Impl;
  typedef FacetDelegate_Impl * FacetDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <FacetDelegate_Impl> FacetDelegate;

  // Forward declarations for AttributeInstance
  class AttributeInstance_Impl;
  typedef AttributeInstance_Impl * AttributeInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeInstance_Impl> AttributeInstance;

  // Forward declarations for ImplementationArtifactReference
  class ImplementationArtifactReference_Impl;
  typedef ImplementationArtifactReference_Impl * ImplementationArtifactReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationArtifactReference_Impl> ImplementationArtifactReference;

  // Forward declarations for InfoProperty
  class InfoProperty_Impl;
  typedef InfoProperty_Impl * InfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <InfoProperty_Impl> InfoProperty;

  // Forward declarations for Finish
  class Finish_Impl;
  typedef Finish_Impl * Finish_in;
  typedef ::GAME::Mga::Smart_Ptr <Finish_Impl> Finish;

  // Forward declarations for Terminal
  class Terminal_Impl;
  typedef Terminal_Impl * Terminal_in;
  typedef ::GAME::Mga::Smart_Ptr <Terminal_Impl> Terminal;

  // Forward declarations for PackageConfReference
  class PackageConfReference_Impl;
  typedef PackageConfReference_Impl * PackageConfReference_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfReference_Impl> PackageConfReference;

  // Forward declarations for NamedType
  class NamedType_Impl;
  typedef NamedType_Impl * NamedType_in;
  typedef ::GAME::Mga::Smart_Ptr <NamedType_Impl> NamedType;

  // Forward declarations for ComponentPackage
  class ComponentPackage_Impl;
  typedef ComponentPackage_Impl * ComponentPackage_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentPackage_Impl> ComponentPackage;

  // Forward declarations for ComponentServantArtifact
  class ComponentServantArtifact_Impl;
  typedef ComponentServantArtifact_Impl * ComponentServantArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentServantArtifact_Impl> ComponentServantArtifact;

  // Forward declarations for PackageConfConfigProperty
  class PackageConfConfigProperty_Impl;
  typedef PackageConfConfigProperty_Impl * PackageConfConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfConfigProperty_Impl> PackageConfConfigProperty;

  // Forward declarations for ConnectorInherits
  class ConnectorInherits_Impl;
  typedef ConnectorInherits_Impl * ConnectorInherits_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorInherits_Impl> ConnectorInherits;

  // Forward declarations for Jitter
  class Jitter_Impl;
  typedef Jitter_Impl * Jitter_in;
  typedef ::GAME::Mga::Smart_Ptr <Jitter_Impl> Jitter;

  // Forward declarations for RequiredRequestPortInstance
  class RequiredRequestPortInstance_Impl;
  typedef RequiredRequestPortInstance_Impl * RequiredRequestPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPortInstance_Impl> RequiredRequestPortInstance;

  // Forward declarations for ConstantType
  class ConstantType_Impl;
  typedef ConstantType_Impl * ConstantType_in;
  typedef ::GAME::Mga::Smart_Ptr <ConstantType_Impl> ConstantType;

  // Forward declarations for ArtifactDeployRequirement
  class ArtifactDeployRequirement_Impl;
  typedef ArtifactDeployRequirement_Impl * ArtifactDeployRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactDeployRequirement_Impl> ArtifactDeployRequirement;

  // Forward declarations for ArtifactDependsOn
  class ArtifactDependsOn_Impl;
  typedef ArtifactDependsOn_Impl * ArtifactDependsOn_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactDependsOn_Impl> ArtifactDependsOn;

  // Forward declarations for TemplateParameterReference
  class TemplateParameterReference_Impl;
  typedef TemplateParameterReference_Impl * TemplateParameterReference_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplateParameterReference_Impl> TemplateParameterReference;

  // Forward declarations for Resource
  class Resource_Impl;
  typedef Resource_Impl * Resource_in;
  typedef ::GAME::Mga::Smart_Ptr <Resource_Impl> Resource;

  // Forward declarations for QueryInput
  class QueryInput_Impl;
  typedef QueryInput_Impl * QueryInput_in;
  typedef ::GAME::Mga::Smart_Ptr <QueryInput_Impl> QueryInput;

  // Forward declarations for TopLevelBehavior
  class TopLevelBehavior_Impl;
  typedef TopLevelBehavior_Impl * TopLevelBehavior_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelBehavior_Impl> TopLevelBehavior;

  // Forward declarations for SwitchedAggregate
  class SwitchedAggregate_Impl;
  typedef SwitchedAggregate_Impl * SwitchedAggregate_in;
  typedef ::GAME::Mga::Smart_Ptr <SwitchedAggregate_Impl> SwitchedAggregate;

  // Forward declarations for Variable
  class Variable_Impl;
  typedef Variable_Impl * Variable_in;
  typedef ::GAME::Mga::Smart_Ptr <Variable_Impl> Variable;

  // Forward declarations for QueryInputBase
  class QueryInputBase_Impl;
  typedef QueryInputBase_Impl * QueryInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <QueryInputBase_Impl> QueryInputBase;

  // Forward declarations for MemberType
  class MemberType_Impl;
  typedef MemberType_Impl * MemberType_in;
  typedef ::GAME::Mga::Smart_Ptr <MemberType_Impl> MemberType;

  // Forward declarations for OutEventPortEnd
  class OutEventPortEnd_Impl;
  typedef OutEventPortEnd_Impl * OutEventPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <OutEventPortEnd_Impl> OutEventPortEnd;

  // Forward declarations for ExternalPortEnd
  class ExternalPortEnd_Impl;
  typedef ExternalPortEnd_Impl * ExternalPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalPortEnd_Impl> ExternalPortEnd;

  // Forward declarations for SatisfierProperty
  class SatisfierProperty_Impl;
  typedef SatisfierProperty_Impl * SatisfierProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <SatisfierProperty_Impl> SatisfierProperty;

  // Forward declarations for Implements
  class Implements_Impl;
  typedef Implements_Impl * Implements_in;
  typedef ::GAME::Mga::Smart_Ptr <Implements_Impl> Implements;

  // Forward declarations for Publish
  class Publish_Impl;
  typedef Publish_Impl * Publish_in;
  typedef ::GAME::Mga::Smart_Ptr <Publish_Impl> Publish;

  // Forward declarations for ECRole
  class ECRole_Impl;
  typedef ECRole_Impl * ECRole_in;
  typedef ::GAME::Mga::Smart_Ptr <ECRole_Impl> ECRole;

  // Forward declarations for ComponentFactoryInstance
  class ComponentFactoryInstance_Impl;
  typedef ComponentFactoryInstance_Impl * ComponentFactoryInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactoryInstance_Impl> ComponentFactoryInstance;

  // Forward declarations for ActionType
  class ActionType_Impl;
  typedef ActionType_Impl * ActionType_in;
  typedef ::GAME::Mga::Smart_Ptr <ActionType_Impl> ActionType;

  // Forward declarations for OutEventPortDelegate
  class OutEventPortDelegate_Impl;
  typedef OutEventPortDelegate_Impl * OutEventPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <OutEventPortDelegate_Impl> OutEventPortDelegate;

  // Forward declarations for package
  class package_Impl;
  typedef package_Impl * package_in;
  typedef ::GAME::Mga::Smart_Ptr <package_Impl> package;

  // Forward declarations for ComponentPackageReference
  class ComponentPackageReference_Impl;
  typedef ComponentPackageReference_Impl * ComponentPackageReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentPackageReference_Impl> ComponentPackageReference;

  // Forward declarations for Domain
  class Domain_Impl;
  typedef Domain_Impl * Domain_in;
  typedef ::GAME::Mga::Smart_Ptr <Domain_Impl> Domain;

  // Forward declarations for TimerConnection
  class TimerConnection_Impl;
  typedef TimerConnection_Impl * TimerConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <TimerConnection_Impl> TimerConnection;

  // Forward declarations for RequestAction
  class RequestAction_Impl;
  typedef RequestAction_Impl * RequestAction_in;
  typedef ::GAME::Mga::Smart_Ptr <RequestAction_Impl> RequestAction;

  // Forward declarations for Supports
  class Supports_Impl;
  typedef Supports_Impl * Supports_in;
  typedef ::GAME::Mga::Smart_Ptr <Supports_Impl> Supports;

  // Forward declarations for String
  class String_Impl;
  typedef String_Impl * String_in;
  typedef ::GAME::Mga::Smart_Ptr <String_Impl> String;

  // Forward declarations for Task
  class Task_Impl;
  typedef Task_Impl * Task_in;
  typedef ::GAME::Mga::Smart_Ptr <Task_Impl> Task;

  // Forward declarations for Attribute
  class Attribute_Impl;
  typedef Attribute_Impl * Attribute_in;
  typedef ::GAME::Mga::Smart_Ptr <Attribute_Impl> Attribute;

  // Forward declarations for ExceptionType
  class ExceptionType_Impl;
  typedef ExceptionType_Impl * ExceptionType_in;
  typedef ::GAME::Mga::Smart_Ptr <ExceptionType_Impl> ExceptionType;

  // Forward declarations for ReadonlyAttribute
  class ReadonlyAttribute_Impl;
  typedef ReadonlyAttribute_Impl * ReadonlyAttribute_in;
  typedef ::GAME::Mga::Smart_Ptr <ReadonlyAttribute_Impl> ReadonlyAttribute;

  // Forward declarations for ComponentBuild
  class ComponentBuild_Impl;
  typedef ComponentBuild_Impl * ComponentBuild_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentBuild_Impl> ComponentBuild;

  // Forward declarations for EventPort
  class EventPort_Impl;
  typedef EventPort_Impl * EventPort_in;
  typedef ::GAME::Mga::Smart_Ptr <EventPort_Impl> EventPort;

  // Forward declarations for InEventPort
  class InEventPort_Impl;
  typedef InEventPort_Impl * InEventPort_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPort_Impl> InEventPort;

  // Forward declarations for OnewayOperation
  class OnewayOperation_Impl;
  typedef OnewayOperation_Impl * OnewayOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <OnewayOperation_Impl> OnewayOperation;

  // Forward declarations for ConnectorImplementationType
  class ConnectorImplementationType_Impl;
  typedef ConnectorImplementationType_Impl * ConnectorImplementationType_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplementationType_Impl> ConnectorImplementationType;

  // Forward declarations for ExecutorProject
  class ExecutorProject_Impl;
  typedef ExecutorProject_Impl * ExecutorProject_in;
  typedef ::GAME::Mga::Smart_Ptr <ExecutorProject_Impl> ExecutorProject;

  // Forward declarations for InputAction
  class InputAction_Impl;
  typedef InputAction_Impl * InputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <InputAction_Impl> InputAction;

  // Forward declarations for BranchTransition
  class BranchTransition_Impl;
  typedef BranchTransition_Impl * BranchTransition_in;
  typedef ::GAME::Mga::Smart_Ptr <BranchTransition_Impl> BranchTransition;

  // Forward declarations for BenchmarkAnalysis
  class BenchmarkAnalysis_Impl;
  typedef BenchmarkAnalysis_Impl * BenchmarkAnalysis_in;
  typedef ::GAME::Mga::Smart_Ptr <BenchmarkAnalysis_Impl> BenchmarkAnalysis;

  // Forward declarations for ConnectorImplements
  class ConnectorImplements_Impl;
  typedef ConnectorImplements_Impl * ConnectorImplements_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplements_Impl> ConnectorImplements;
}

#endif
