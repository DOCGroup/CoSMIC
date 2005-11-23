// $Id$

#include <memory>
#include <stack>
#include <map>
#include "PICML/PICML.h"

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "PICML/XercesString.h"
#include "FlatPlan/FlatPlan_Export.h"

namespace PICML
{
  using xercesc::DOMImplementation;
  using xercesc::DOMDocument;
  using xercesc::DOMElement;
  using xercesc::DOMWriter;
  using xercesc::XMLFormatTarget;
  using xercesc::LocalFileFormatTarget;

  class FlatPlanVisitor: public Visitor
  {
  public:
    FlatPlan_Export FlatPlanVisitor (const std::string& outputPath);
    FlatPlan_Export ~FlatPlanVisitor();

    FlatPlan_Export void init();
    FlatPlan_Export void initTarget (const std::string& fileName);
	FlatPlan_Export void initNodeRefName (const std::string& nodeRefName);
	FlatPlan_Export std::string retNodeRefName ();
	FlatPlan_Export void initcgName (const std::string& cgName);
	FlatPlan_Export std::string retcgName ();
    FlatPlan_Export void initDocument (const std::string& rootName);
    FlatPlan_Export void initRootAttributes();
    FlatPlan_Export void dumpDocument();

    FlatPlan_Export void push();
    FlatPlan_Export void pop();

    FlatPlan_Export DOMElement* createSimpleContent (const std::string& name,
                                                 const std::string& value);

    // Lord Of the Rings..
    FlatPlan_Export virtual void Visit_RootFolder(const RootFolder&);

    // Predefined Types
    FlatPlan_Export virtual void Visit_LongInteger(const LongInteger&);
	FlatPlan_Export virtual void Visit_Byte(const Byte&);
    FlatPlan_Export virtual void Visit_String(const String&);
	FlatPlan_Export virtual void Visit_RealNumber(const RealNumber&);
    FlatPlan_Export virtual void Visit_Boolean(const Boolean&);
    FlatPlan_Export virtual void Visit_ShortInteger(const ShortInteger&);

    FlatPlan_Export virtual void Visit_GenericValue(const GenericValue&){};
    FlatPlan_Export virtual void Visit_TypeKind(const TypeKind&){};
    FlatPlan_Export virtual void Visit_GenericObject(const GenericObject&){};
    FlatPlan_Export virtual void Visit_PredefinedTypes(const PredefinedTypes&){};
    FlatPlan_Export virtual void Visit_TypeEncoding(const TypeEncoding&){};
    FlatPlan_Export virtual void Visit_GenericValueObject(const GenericValueObject&){};

    // Implementation Artifact operations

    FlatPlan_Export virtual void Visit_ImplementationArtifacts(const ImplementationArtifacts&);
    FlatPlan_Export virtual void Visit_ArtifactContainer(const ArtifactContainer&);
    FlatPlan_Export virtual void Visit_ImplementationArtifact(const ImplementationArtifact&);
    FlatPlan_Export virtual void Visit_ArtifactDependsOn(const ArtifactDependsOn&);
    FlatPlan_Export virtual void Visit_ImplementationArtifactReference(const ImplementationArtifactReference&);
    FlatPlan_Export virtual void Visit_ArtifactExecParameter(const ArtifactExecParameter&);
    FlatPlan_Export virtual void Visit_Property(const Property&);
    FlatPlan_Export virtual void Visit_DataType(const DataType&);

    FlatPlan_Export virtual void Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&);
    FlatPlan_Export virtual void Visit_ArtifactInfoProperty(const ArtifactInfoProperty&);
    FlatPlan_Export virtual void Visit_ImplementationRequirement(const ImplementationRequirement&);

    // TopLevelPackage operations

    FlatPlan_Export virtual void Visit_TopLevelPackages(const TopLevelPackages&);
    FlatPlan_Export virtual void Visit_TopLevelPackageContainer(const TopLevelPackageContainer&);
    FlatPlan_Export virtual void Visit_TopLevelPackage(const TopLevelPackage&);
    FlatPlan_Export virtual void Visit_package(const package&);
    FlatPlan_Export virtual void Visit_PackageConfigurationReference(const PackageConfigurationReference&);

    // PackageConfiguration operations

    FlatPlan_Export virtual void Visit_PackageConfigurations(const PackageConfigurations&);
    FlatPlan_Export virtual void Visit_PackageConfigurationContainer(const PackageConfigurationContainer&);
    FlatPlan_Export virtual void Visit_PackageConfiguration(const PackageConfiguration&);
    FlatPlan_Export virtual void Visit_PackageConfConfigProperty(const PackageConfConfigProperty&);
    FlatPlan_Export virtual void Visit_PackageConfReference(const PackageConfReference&);
    FlatPlan_Export virtual void Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&);
    FlatPlan_Export virtual void Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&);
    FlatPlan_Export virtual void Visit_PackageConfBasePackage(const PackageConfBasePackage&);
    FlatPlan_Export virtual void Visit_ComponentPackageReference(const ComponentPackageReference&);

    FlatPlan_Export virtual void Visit_ComponentImplementations(const ComponentImplementations&);
	FlatPlan_Export virtual void Visit_ComponentImplementationContainer(const ComponentImplementationContainer&);
    FlatPlan_Export virtual void Visit_MonolithicImplementation(const MonolithicImplementation&);
    FlatPlan_Export virtual void Visit_MonolithExecParameter(const MonolithExecParameter&);
    FlatPlan_Export virtual void Visit_ComponentAssembly(const ComponentAssembly&);
	FlatPlan_Export virtual void update_connections(const ComponentAssembly&);
	FlatPlan_Export virtual void Visit_AssemblyConfigProperty(const AssemblyConfigProperty&);
	FlatPlan_Export virtual void Visit_DeploymentPlan(const DeploymentPlan&);
    FlatPlan_Export virtual void Visit_DeploymentPlans(const DeploymentPlans&);
	FlatPlan_Export virtual void Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact&);
	FlatPlan_Export virtual void Visit_Implements(const Implements&);
	FlatPlan_Export virtual void Visit_ConfigProperty(const ConfigProperty&);
	FlatPlan_Export virtual void Visit_publish(const publish&);
	FlatPlan_Export virtual void Visit_PublishConnector(const PublishConnector&);
    FlatPlan_Export virtual void Visit_deliverTo(const deliverTo&);
    FlatPlan_Export virtual void Visit_emit(const emit&);
    FlatPlan_Export virtual void Visit_invoke(const invoke&);


	//
    FlatPlan_Export virtual void Visit_ComponentPackage(const ComponentPackage&){};
    FlatPlan_Export virtual void Visit_ComponentPackages(const ComponentPackages&){};
    FlatPlan_Export virtual void Visit_Implementation(const Implementation&){};
    FlatPlan_Export virtual void Visit_PackageContainer(const PackageContainer&){};
    FlatPlan_Export virtual void Visit_PackageConfigProperty(const PackageConfigProperty&){};
    FlatPlan_Export virtual void Visit_PackageInfoProperty(const PackageInfoProperty&){};
    FlatPlan_Export virtual void Visit_PackageInterface(const PackageInterface&){};
    FlatPlan_Export virtual void Visit_InfoProperty(const InfoProperty&){};

	//
	FlatPlan_Export virtual void Visit_Requirement(const Requirement&){};
    FlatPlan_Export virtual void Visit_SatisfierProperty(const SatisfierProperty&){};
    FlatPlan_Export virtual void Visit_ImplementationDependency(const ImplementationDependency&){};
    FlatPlan_Export virtual void Visit_Capability(const Capability&){};
    FlatPlan_Export virtual void Visit_AssemblyselectRequirement(const AssemblyselectRequirement&){};
    FlatPlan_Export virtual void Visit_AssemblyDeployRequirement(const AssemblyDeployRequirement&){};
	FlatPlan_Export virtual void Visit_MonolithDeployRequirement(const MonolithDeployRequirement&){};
    FlatPlan_Export virtual void Visit_ComponentImplementationReference(const ComponentImplementationReference&){};
    FlatPlan_Export virtual void Visit_ImplementationDependsOn(const ImplementationDependsOn&){};
    FlatPlan_Export virtual void Visit_ImplementationCapability(const ImplementationCapability&){};
    FlatPlan_Export virtual void Visit_ComponentContainer(const ComponentContainer&){};
    FlatPlan_Export virtual void Visit_ComponentPropertyDescription(const ComponentPropertyDescription&){};
    FlatPlan_Export virtual void Visit_ComponentInfoProperty(const ComponentInfoProperty&){};
    FlatPlan_Export virtual void Visit_ComponentProperty(const ComponentProperty&){};
    FlatPlan_Export virtual void Visit_ComponentTypes(const ComponentTypes&){};
    FlatPlan_Export virtual void Visit_ComponentConfigProperty(const ComponentConfigProperty&){};

	//
	FlatPlan_Export virtual void Visit_Resource(const Resource&){};
    FlatPlan_Export virtual void Visit_SharedResource(const SharedResource&){};
    FlatPlan_Export virtual void Visit_NodeReference(const NodeReference&);
    FlatPlan_Export virtual void Visit_Bridge(const Bridge&){};
    FlatPlan_Export virtual void Visit_Node(const Node&){};
    FlatPlan_Export virtual void Visit_Interconnect(const Interconnect&){};
    FlatPlan_Export virtual void Visit_Domain(const Domain&){};
    FlatPlan_Export virtual void Visit_Targets(const Targets&){};
    FlatPlan_Export virtual void Visit_Node2Interconnect(const Node2Interconnect&){};
    FlatPlan_Export virtual void Visit_Bridge2Interconnect(const Bridge2Interconnect&){};
    FlatPlan_Export virtual void Visit_Shares(const Shares&){};
    FlatPlan_Export virtual void Visit_Interconnect2Node(const Interconnect2Node&){};
    FlatPlan_Export virtual void Visit_Interconnect2Bridge(const Interconnect2Bridge&){};
    FlatPlan_Export virtual void Visit_InstanceMapping(const InstanceMapping&);
    FlatPlan_Export virtual void Visit_CollocationGroup(const CollocationGroup&){};
    FlatPlan_Export virtual void Visit_InParameter(const InParameter&){};
    FlatPlan_Export virtual void Visit_TwowayOperation(const TwowayOperation&){};
    FlatPlan_Export virtual void Visit_OnewayOperation(const OnewayOperation&){};
    FlatPlan_Export virtual void Visit_FactoryOperation(const FactoryOperation&){};
    FlatPlan_Export virtual void Visit_LookupOperation(const LookupOperation&){};
    FlatPlan_Export virtual void Visit_InoutParameter(const InoutParameter&){};
    FlatPlan_Export virtual void Visit_OutParameter(const OutParameter&){};
    FlatPlan_Export virtual void Visit_ReturnType(const ReturnType&){};
    FlatPlan_Export virtual void Visit_Exception(const Exception&){};
    FlatPlan_Export virtual void Visit_Package(const Package&){};
    FlatPlan_Export virtual void Visit_File(const File&){};
    FlatPlan_Export virtual void Visit_Constant(const Constant&){};
    FlatPlan_Export virtual void Visit_InterfaceDefinitions(const InterfaceDefinitions&){};
    FlatPlan_Export virtual void Visit_FileRef(const FileRef&){};
    FlatPlan_Export virtual void Visit_ExceptionRef(const ExceptionRef&){};
    FlatPlan_Export virtual void Visit_SwitchedAggregate(const SwitchedAggregate&){};
    FlatPlan_Export virtual void Visit_Member(const Member&){};
    FlatPlan_Export virtual void Visit_Boxed(const Boxed&){};
    FlatPlan_Export virtual void Visit_EnumValue(const EnumValue&){};
    FlatPlan_Export virtual void Visit_Label(const Label&){};
    FlatPlan_Export virtual void Visit_Aggregate(const Aggregate&){};
    FlatPlan_Export virtual void Visit_Alias(const Alias&){};
    FlatPlan_Export virtual void Visit_Collection(const Collection&){};
    FlatPlan_Export virtual void Visit_Discriminator(const Discriminator&){};
    FlatPlan_Export virtual void Visit_Enum(const Enum&){};
    FlatPlan_Export virtual void Visit_LabelConnection(const LabelConnection&){};
    FlatPlan_Export virtual void Visit_SetException(const SetException&){};
    FlatPlan_Export virtual void Visit_LookupKey(const LookupKey&){};
    FlatPlan_Export virtual void Visit_Attribute(const Attribute&){};
    FlatPlan_Export virtual void Visit_Supports(const Supports&){};
    FlatPlan_Export virtual void Visit_MakeMemberPrivate(const MakeMemberPrivate&){};
    FlatPlan_Export virtual void Visit_PrivateFlag(const PrivateFlag&){};
    FlatPlan_Export virtual void Visit_GetException(const GetException&){};
    FlatPlan_Export virtual void Visit_Inherits(const Inherits&){};
    FlatPlan_Export virtual void Visit_Object(const Object&){};
    FlatPlan_Export virtual void Visit_ValueObject(const ValueObject&){};
    FlatPlan_Export virtual void Visit_Event(const Event&){};
    FlatPlan_Export virtual void Visit_AttributeMember(const AttributeMember&){};
    FlatPlan_Export virtual void Visit_OutEventPort(const OutEventPort&){};
    FlatPlan_Export virtual void Visit_ProvidedRequestPort(const ProvidedRequestPort&){};
    FlatPlan_Export virtual void Visit_Component(const Component&){};
    FlatPlan_Export virtual void Visit_RequiredRequestPort(const RequiredRequestPort&){};
    FlatPlan_Export virtual void Visit_ManagesComponent(const ManagesComponent&){};
    FlatPlan_Export virtual void Visit_InEventPort(const InEventPort&){};
    FlatPlan_Export virtual void Visit_ComponentRef(const ComponentRef&){};
    FlatPlan_Export virtual void Visit_ComponentFactory(const ComponentFactory&){};
    FlatPlan_Export virtual void Visit_Object(const Udm::Object&){};
	FlatPlan_Export void GetReceptacleComponents (const RequiredRequestPort& receptacle,
                                  std::map<Component,std::string>& output);

    FlatPlan_Export void GetFacetComponents (const ProvidedRequestPort& facet,
                             std::map<Component,std::string>& output);

    FlatPlan_Export void GetEventSinkComponents (const InEventPort& consumer,
                                 std::map<Component,std::string>& output);

    FlatPlan_Export void GetEventSourceComponents (const OutEventPort& publisher,
                                   std::map<Component,std::string>& output);

    FlatPlan_Export void GetAttributeComponents (const AttributeMapping& mapping,
                                 std::set<std::pair<std::string, std::string> >& output);

    template <typename T, typename Del, typename DelRet, typename DelEndRet>
      void GetComponents (const T& port,
                          DelRet (T::*srcDel)() const,
                          DelRet (T::*dstDel) () const,
                          DelEndRet (Del::*srcDelEnd)() const,
                          DelEndRet (Del::*dstDelEnd)() const,
                          std::map<Component, std::string>& output,
                          std::set<T>& visited);

    FlatPlan_Export void CreateConnections (const std::map<Component, std::string>& src,
                            const std::map<Component, std::string>& dst,
							const std::string& source_kind,
							const std::string& dest_kind);

    FlatPlan_Export void CreateConnection (const Component& srcComp,
                           const std::string& srcPortName,
                           const Component& dstComp,
                           const std::string& dstPortName,
						   const std::string& source_kind,
						   const std::string& dest_kind);
    FlatPlan_Export void CreateAssemblyInstances (std::set<Component>& comps);
    FlatPlan_Export void CreateAssemblyConnections (std::vector<ComponentAssembly>& assemblies);
    FlatPlan_Export void CreateAttributeMappings (std::vector<ComponentAssembly>& assemblies);
	FlatPlan_Export void CreatePropertyElement (std::string name, const Property& property);
	FlatPlan_Export virtual void Visit_ReadonlyAttribute(const ReadonlyAttribute&);
    FlatPlan_Export virtual void Visit_AttributeValue(const AttributeValue&);
    FlatPlan_Export virtual void Visit_AttributeDelegate(const AttributeDelegate&);
    FlatPlan_Export virtual void Visit_AttributeMapping(const AttributeMapping&);
    FlatPlan_Export virtual void Visit_AttributeMappingValue(const AttributeMappingValue&);
    FlatPlan_Export virtual void Visit_AttributeMappingDelegate(const AttributeMappingDelegate&);
	FlatPlan_Export std::string ExtractName (Udm::Object obj);

  private:

    DOMImplementation*  impl_;
    DOMDocument*        doc_;
    DOMElement*         root_;
    DOMElement*         curr_;
    DOMWriter*          serializer_;
    XMLFormatTarget*    target_;
    std::string         outputPath_;
    std::stack<DOMElement*> curr_stack_;
    std::string         node_ref_name_;
	std::string         cg_name_;
	RootFolder          root_folder_;

	// Maintain associations between PublishConnector and event publishers
    std::map<std::string, OutEventPort> publishers_;
	std::map<std::string, MonolithicImplementation> monoimpls_;

    // Maintain associations between PublishConnector and event consumers
    std::multimap<std::string, InEventPort> consumers_;

	std::map<std::string, std::string> interfaces_;
	std::map<std::pair<std::string, std::string>, Property> attrValues_;
  };
}
