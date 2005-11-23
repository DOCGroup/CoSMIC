// $Id$

#include <memory>
#include <stack>
#include "PICML/PICML.h"

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "PICML/XercesString.h"
#include "DeploymentPlan/Plan_Export.h"

namespace PICML
{
  using xercesc::DOMImplementation;
  using xercesc::DOMDocument;
  using xercesc::DOMElement;
  using xercesc::DOMWriter;
  using xercesc::XMLFormatTarget;
  using xercesc::LocalFileFormatTarget;

  class PlanVisitor: public Visitor
  {
  public:
    Plan_Export PlanVisitor (const std::string& outputPath);
    Plan_Export ~PlanVisitor();

    Plan_Export void init();
    Plan_Export void initTarget (const std::string& fileName);
	  Plan_Export void initNodeRefName (const std::string& nodeRefName);
	  Plan_Export std::string retNodeRefName ();
    Plan_Export void initDocument (const std::string& rootName);
    Plan_Export void initRootAttributes();
    Plan_Export void dumpDocument();

    Plan_Export void push();
    Plan_Export void pop();

    Plan_Export DOMElement* createSimpleContent (const std::string& name,
                                                 const std::string& value);

    // Lord Of the Rings..
    Plan_Export virtual void Visit_RootFolder(const RootFolder&);

    // Predefined Types
    Plan_Export virtual void Visit_LongInteger(const LongInteger&);
    Plan_Export virtual void Visit_String(const String&);
    Plan_Export virtual void Visit_Boolean(const Boolean&);
    Plan_Export virtual void Visit_ShortInteger(const ShortInteger&);

    Plan_Export virtual void Visit_GenericValue(const GenericValue&){};
    Plan_Export virtual void Visit_Byte(const Byte&){};
    Plan_Export virtual void Visit_TypeKind(const TypeKind&){};
    Plan_Export virtual void Visit_GenericObject(const GenericObject&){};
    Plan_Export virtual void Visit_RealNumber(const RealNumber&){};
    Plan_Export virtual void Visit_PredefinedTypes(const PredefinedTypes&){};
    Plan_Export virtual void Visit_TypeEncoding(const TypeEncoding&){};
    Plan_Export virtual void Visit_GenericValueObject(const GenericValueObject&){};

    // Implementation Artifact operations

    Plan_Export virtual void Visit_ImplementationArtifacts(const ImplementationArtifacts&);
    Plan_Export virtual void Visit_ArtifactContainer(const ArtifactContainer&);
    Plan_Export virtual void Visit_ImplementationArtifact(const ImplementationArtifact&);
    Plan_Export virtual void Visit_ArtifactDependsOn(const ArtifactDependsOn&);
    Plan_Export virtual void Visit_ImplementationArtifactReference(const ImplementationArtifactReference&);
    Plan_Export virtual void Visit_ArtifactExecParameter(const ArtifactExecParameter&);
    Plan_Export virtual void Visit_Property(const Property&);
    Plan_Export virtual void Visit_DataType(const DataType&);

    Plan_Export virtual void Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&);
    Plan_Export virtual void Visit_ArtifactInfoProperty(const ArtifactInfoProperty&);
    Plan_Export virtual void Visit_ImplementationRequirement(const ImplementationRequirement&);

    // TopLevelPackage operations

    Plan_Export virtual void Visit_TopLevelPackages(const TopLevelPackages&);
    Plan_Export virtual void Visit_TopLevelPackageContainer(const TopLevelPackageContainer&);
    Plan_Export virtual void Visit_TopLevelPackage(const TopLevelPackage&);
    Plan_Export virtual void Visit_package(const package&);
    Plan_Export virtual void Visit_PackageConfigurationReference(const PackageConfigurationReference&);

    // PackageConfiguration operations

    Plan_Export virtual void Visit_PackageConfigurations(const PackageConfigurations&);
    Plan_Export virtual void Visit_PackageConfigurationContainer(const PackageConfigurationContainer&);
    Plan_Export virtual void Visit_PackageConfiguration(const PackageConfiguration&);
    Plan_Export virtual void Visit_PackageConfConfigProperty(const PackageConfConfigProperty&);
    Plan_Export virtual void Visit_PackageConfReference(const PackageConfReference&);
    Plan_Export virtual void Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&);
    Plan_Export virtual void Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&);
    Plan_Export virtual void Visit_PackageConfBasePackage(const PackageConfBasePackage&);
    Plan_Export virtual void Visit_ComponentPackageReference(const ComponentPackageReference&);

    //
    Plan_Export virtual void Visit_Requirement(const Requirement&){};
    Plan_Export virtual void Visit_SatisfierProperty(const SatisfierProperty&){};
    Plan_Export virtual void Visit_ImplementationDependency(const ImplementationDependency&){};
    Plan_Export virtual void Visit_Capability(const Capability&){};
    Plan_Export virtual void Visit_AssemblyselectRequirement(const AssemblyselectRequirement&){};
    Plan_Export virtual void Visit_AssemblyConfigProperty(const AssemblyConfigProperty&){};
    Plan_Export virtual void Visit_PublishConnector(const PublishConnector&){};
    Plan_Export virtual void Visit_publish(const publish&){};
    Plan_Export virtual void Visit_deliverTo(const deliverTo&){};
    Plan_Export virtual void Visit_AssemblyDeployRequirement(const AssemblyDeployRequirement&){};
    Plan_Export virtual void Visit_ComponentAssembly(const ComponentAssembly&);
    Plan_Export virtual void Visit_emit(const emit&){};
    Plan_Export virtual void Visit_invoke(const invoke&){};
    Plan_Export virtual void Visit_ComponentPackage(const ComponentPackage&){};
    Plan_Export virtual void Visit_ComponentPackages(const ComponentPackages&){};
    Plan_Export virtual void Visit_Implementation(const Implementation&){};
    Plan_Export virtual void Visit_PackageContainer(const PackageContainer&){};
    Plan_Export virtual void Visit_PackageConfigProperty(const PackageConfigProperty&){};
    Plan_Export virtual void Visit_PackageInfoProperty(const PackageInfoProperty&){};
    Plan_Export virtual void Visit_PackageInterface(const PackageInterface&){};
    Plan_Export virtual void Visit_InfoProperty(const InfoProperty&){};
    Plan_Export virtual void Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact&){};
    Plan_Export virtual void Visit_MonolithDeployRequirement(const MonolithDeployRequirement&){};
    Plan_Export virtual void Visit_ComponentImplementationReference(const ComponentImplementationReference&){};
    Plan_Export virtual void Visit_ConfigProperty(const ConfigProperty&){};
    Plan_Export virtual void Visit_ComponentImplementationContainer(const ComponentImplementationContainer&){};
    Plan_Export virtual void Visit_MonolithicImplementation(const MonolithicImplementation&){};
    Plan_Export virtual void Visit_MonolithExecParameter(const MonolithExecParameter&){};
    Plan_Export virtual void Visit_ImplementationDependsOn(const ImplementationDependsOn&){};
    Plan_Export virtual void Visit_Implements(const Implements&){};
    Plan_Export virtual void Visit_ComponentImplementations(const ComponentImplementations&){};
    Plan_Export virtual void Visit_ImplementationCapability(const ImplementationCapability&){};
    Plan_Export virtual void Visit_ComponentContainer(const ComponentContainer&){};
    Plan_Export virtual void Visit_ComponentPropertyDescription(const ComponentPropertyDescription&){};
    Plan_Export virtual void Visit_ComponentInfoProperty(const ComponentInfoProperty&){};
    Plan_Export virtual void Visit_ComponentProperty(const ComponentProperty&){};
    Plan_Export virtual void Visit_ComponentTypes(const ComponentTypes&){};
    Plan_Export virtual void Visit_ComponentConfigProperty(const ComponentConfigProperty&){};
    Plan_Export virtual void Visit_Resource(const Resource&){};
    Plan_Export virtual void Visit_SharedResource(const SharedResource&){};
    Plan_Export virtual void Visit_NodeReference(const NodeReference&);
    Plan_Export virtual void Visit_Bridge(const Bridge&){};
    Plan_Export virtual void Visit_Node(const Node&){};
    Plan_Export virtual void Visit_Interconnect(const Interconnect&){};
    Plan_Export virtual void Visit_Domain(const Domain&){};
    Plan_Export virtual void Visit_Targets(const Targets&){};
    Plan_Export virtual void Visit_Node2Interconnect(const Node2Interconnect&){};
    Plan_Export virtual void Visit_Bridge2Interconnect(const Bridge2Interconnect&){};
    Plan_Export virtual void Visit_Shares(const Shares&){};
    Plan_Export virtual void Visit_Interconnect2Node(const Interconnect2Node&){};
    Plan_Export virtual void Visit_Interconnect2Bridge(const Interconnect2Bridge&){};
    Plan_Export virtual void Visit_InstanceMapping(const InstanceMapping&);
    Plan_Export virtual void Visit_DeploymentPlan(const DeploymentPlan&);
    Plan_Export virtual void Visit_DeploymentPlans(const DeploymentPlans&);
    Plan_Export virtual void Visit_CollocationGroup(const CollocationGroup&){};
    Plan_Export virtual void Visit_InParameter(const InParameter&){};
    Plan_Export virtual void Visit_TwowayOperation(const TwowayOperation&){};
    Plan_Export virtual void Visit_OnewayOperation(const OnewayOperation&){};
    Plan_Export virtual void Visit_FactoryOperation(const FactoryOperation&){};
    Plan_Export virtual void Visit_LookupOperation(const LookupOperation&){};
    Plan_Export virtual void Visit_InoutParameter(const InoutParameter&){};
    Plan_Export virtual void Visit_OutParameter(const OutParameter&){};
    Plan_Export virtual void Visit_ReturnType(const ReturnType&){};
    Plan_Export virtual void Visit_Exception(const Exception&){};
    Plan_Export virtual void Visit_Package(const Package&){};
    Plan_Export virtual void Visit_File(const File&){};
    Plan_Export virtual void Visit_Constant(const Constant&){};
    Plan_Export virtual void Visit_InterfaceDefinitions(const InterfaceDefinitions&){};
    Plan_Export virtual void Visit_FileRef(const FileRef&){};
    Plan_Export virtual void Visit_ExceptionRef(const ExceptionRef&){};
    Plan_Export virtual void Visit_SwitchedAggregate(const SwitchedAggregate&){};
    Plan_Export virtual void Visit_Member(const Member&){};
    Plan_Export virtual void Visit_Boxed(const Boxed&){};
    Plan_Export virtual void Visit_EnumValue(const EnumValue&){};
    Plan_Export virtual void Visit_Label(const Label&){};
    Plan_Export virtual void Visit_Aggregate(const Aggregate&){};
    Plan_Export virtual void Visit_Alias(const Alias&){};
    Plan_Export virtual void Visit_Collection(const Collection&){};
    Plan_Export virtual void Visit_Discriminator(const Discriminator&){};
    Plan_Export virtual void Visit_Enum(const Enum&){};
    Plan_Export virtual void Visit_LabelConnection(const LabelConnection&){};
    Plan_Export virtual void Visit_SetException(const SetException&){};
    Plan_Export virtual void Visit_LookupKey(const LookupKey&){};
    Plan_Export virtual void Visit_Attribute(const Attribute&){};
    Plan_Export virtual void Visit_ReadonlyAttribute(const ReadonlyAttribute&){};
    Plan_Export virtual void Visit_Supports(const Supports&){};
    Plan_Export virtual void Visit_MakeMemberPrivate(const MakeMemberPrivate&){};
    Plan_Export virtual void Visit_PrivateFlag(const PrivateFlag&){};
    Plan_Export virtual void Visit_GetException(const GetException&){};
    Plan_Export virtual void Visit_Inherits(const Inherits&){};
    Plan_Export virtual void Visit_Object(const Object&){};
    Plan_Export virtual void Visit_ValueObject(const ValueObject&){};
    Plan_Export virtual void Visit_Event(const Event&){};
    Plan_Export virtual void Visit_AttributeMember(const AttributeMember&){};
    Plan_Export virtual void Visit_OutEventPort(const OutEventPort&){};
    Plan_Export virtual void Visit_ProvidedRequestPort(const ProvidedRequestPort&){};
    Plan_Export virtual void Visit_Component(const Component&){};
    Plan_Export virtual void Visit_RequiredRequestPort(const RequiredRequestPort&){};
    Plan_Export virtual void Visit_ManagesComponent(const ManagesComponent&){};
    Plan_Export virtual void Visit_InEventPort(const InEventPort&){};
    Plan_Export virtual void Visit_ComponentRef(const ComponentRef&){};
    Plan_Export virtual void Visit_ComponentFactory(const ComponentFactory&){};
    Plan_Export virtual void Visit_Object(const Udm::Object&){};

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
  };
}
