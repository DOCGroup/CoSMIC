#ifndef PACKAGE_VISITOR_H
#define PACKAGE_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include "PICML/PICML.h"
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <boost/graph/adjacency_list.hpp>
#include "Path_Export.h"

namespace PICML
{
  using xercesc::DOMImplementation;
  using xercesc::DOMDocument;
  using xercesc::DOMElement;
  using xercesc::DOMLSSerializer;
  using xercesc::XMLFormatTarget;
  using xercesc::LocalFileFormatTarget;

  struct Component_Port_Vertex
  {
    Component_Port_Vertex (const PICML::MgaObject & a_port, string par_name = "");

    Component_Port_Vertex () {};

    std::string vertex_name_;
 
    Udm::Object the_component_;

    PICML::MgaObject the_port_;

    bool is_drawn;
 
    DisplayNode node_;
 
    std::string display_label_;
  };

  struct Edge_Numbers
  {
    int source_;
    int target_;
  };

  class Path_Export PathVisitor: public Visitor
  {
  public:
    PathVisitor (set<Udm::Object>& selections);
    PathVisitor (Udm::Object port);
    ~PathVisitor ();

    // Lord Of the Rings..
    virtual void Visit_RootFolder(const RootFolder&);

    // Predefined Types
    virtual void Visit_Boolean(const Boolean&);
    virtual void Visit_Byte(const Byte&);
    virtual void Visit_String(const String&);
    virtual void Visit_DoubleNumber(const DoubleNumber&);
    virtual void Visit_FloatNumber(const FloatNumber&);
    virtual void Visit_ShortInteger(const ShortInteger&);
    virtual void Visit_LongInteger(const LongInteger&);

    virtual void Visit_GenericValue(const GenericValue&){};
    virtual void Visit_TypeKind(const TypeKind&){};
    virtual void Visit_GenericObject(const GenericObject&){};
    virtual void Visit_PredefinedTypes(const PredefinedTypes&){};
    virtual void Visit_TypeEncoding(const TypeEncoding&){};
    virtual void Visit_GenericValueObject(const GenericValueObject&){};

    // ImplementationArtifact operations

    virtual void Visit_ImplementationArtifacts(const ImplementationArtifacts&);
    virtual void Visit_ArtifactContainer(const ArtifactContainer&);
    virtual void Visit_ImplementationArtifact(const ImplementationArtifact&);
    virtual void Visit_ArtifactDependsOn(const ArtifactDependsOn&);
    virtual void Visit_ArtifactDependency(const ArtifactDependency&);
    virtual void Visit_ImplementationArtifactReference(const ImplementationArtifactReference&);
    virtual void Visit_ArtifactExecParameter(const ArtifactExecParameter&);
    virtual void Visit_Property(const Property&);
    virtual void Visit_DataValue(const DataValue&);

    virtual void Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&);
    virtual void Visit_ArtifactInfoProperty(const ArtifactInfoProperty&);
    virtual void Visit_ImplementationRequirement(const ImplementationRequirement&);

    // TopLevelPackage operations

    virtual void Visit_TopLevelPackages(const TopLevelPackages&);
    virtual void Visit_TopLevelPackageContainer(const TopLevelPackageContainer&);
    virtual void Visit_TopLevelPackage(const TopLevelPackage&);
    virtual void Visit_package(const package&);
    virtual void Visit_PackageConfigurationReference(const PackageConfigurationReference&);

    // PackageConfiguration operations

    virtual void Visit_PackageConfigurations(const PackageConfigurations&);
    virtual void Visit_PackageConfigurationContainer(const PackageConfigurationContainer&);
    virtual void Visit_PackageConfiguration(const PackageConfiguration&);
    virtual void Visit_PackageConfConfigProperty(const PackageConfConfigProperty&);
    virtual void Visit_PackageConfReference(const PackageConfReference&);
    virtual void Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&);
    virtual void Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&);
    virtual void Visit_PackageConfBasePackage(const PackageConfBasePackage&);
    virtual void Visit_ComponentPackageReference(const ComponentPackageReference&);

    // ComponentPackage operations

    virtual void Visit_ComponentPackages(const ComponentPackages&);
    virtual void Visit_PackageContainer(const PackageContainer&);
    virtual void Visit_ComponentPackage(const ComponentPackage&);
    virtual void Visit_PackageInterface(const PackageInterface&);
    virtual void Visit_PackageConfigProperty(const PackageConfigProperty&);
    virtual void Visit_PackageInfoProperty(const PackageInfoProperty&);
    virtual void Visit_Implementation(const Implementation&);
    virtual void Visit_ComponentImplementationReference(const ComponentImplementationReference&);

    // ComponentInterface operations

    virtual void Visit_ComponentTypes(const ComponentTypes&);
    virtual void Visit_ComponentContainer(const ComponentContainer&);
    virtual void Visit_ComponentRef(const ComponentRef&);
    virtual void Visit_ComponentPropertyDescription(const ComponentPropertyDescription&);
    virtual void Visit_ComponentProperty(const ComponentProperty&);
    virtual void Visit_ComponentInfoProperty(const ComponentInfoProperty&);
    virtual void Visit_ComponentConfigProperty(const ComponentConfigProperty&);
    virtual void Visit_OutEventPort(const OutEventPort&);
    virtual void Visit_ProvidedRequestPort(const ProvidedRequestPort&);
    virtual void Visit_Component(const Component&);
    virtual void Visit_RequiredRequestPort(const RequiredRequestPort&);
    virtual void Visit_InEventPort(const InEventPort&);
    virtual void Visit_Supports(const Supports&);
    virtual void Visit_Object(const Object&);



    // ComponentImplementation operations

    virtual void Visit_ComponentImplementations(const ComponentImplementations&);
    virtual void Visit_ComponentImplementationContainer(const ComponentImplementationContainer&);
    virtual void Visit_MonolithicImplementation(const MonolithicImplementation&);

    virtual void Visit_AssemblyConfigProperty(const AssemblyConfigProperty&);
    virtual void Visit_SendsTo (const PICML::SendsTo & s);
    virtual void Visit_ComponentAssembly(const ComponentAssembly&);
    virtual void Visit_Invoke(const Invoke&);

    virtual void Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact&);
    virtual void Visit_ConfigProperty(const ConfigProperty&);
    virtual void Visit_Implements(const Implements&);

    // Component Attribute related operations
    virtual void Visit_ReadonlyAttribute(const ReadonlyAttribute&);
    virtual void Visit_AttributeValue(const AttributeValue&);
    virtual void Visit_AttributeDelegate(const AttributeDelegate&);
    virtual void Visit_AttributeMapping(const AttributeMapping&);
    virtual void Visit_AttributeMappingValue(const AttributeMappingValue&);
    virtual void Visit_AttributeMappingDelegate(const AttributeMappingDelegate&);



    virtual void Visit_Resource(const Resource&){};
    virtual void Visit_SharedResource(const SharedResource&){};
    virtual void Visit_NodeReference(const NodeReference&){};
    virtual void Visit_Bridge(const Bridge&){};
    virtual void Visit_Node(const Node&){};
    virtual void Visit_Interconnect(const Interconnect&){};
    virtual void Visit_Domain(const Domain&){};
    virtual void Visit_Targets(const Targets&){};
    virtual void Visit_Shares(const Shares&){};
    virtual void Visit_InstanceMapping(const InstanceMapping&){};
    virtual void Visit_DeploymentPlan(const DeploymentPlan&){};
    virtual void Visit_DeploymentPlans(const DeploymentPlans&){};
    virtual void Visit_CollocationGroup(const CollocationGroup&){};
    virtual void Visit_InParameter(const InParameter&){};
    virtual void Visit_TwowayOperation(const TwowayOperation&){};
    virtual void Visit_OnewayOperation(const OnewayOperation&){};
    virtual void Visit_FactoryOperation(const FactoryOperation&){};
    virtual void Visit_LookupOperation(const LookupOperation&){};
    virtual void Visit_InoutParameter(const InoutParameter&){};
    virtual void Visit_OutParameter(const OutParameter&){};
    virtual void Visit_ReturnType(const ReturnType&){};
    virtual void Visit_Exception(const Exception&){};
    virtual void Visit_Package(const Package&){};
    virtual void Visit_File(const File&){};
    virtual void Visit_Constant(const Constant&){};
    virtual void Visit_InterfaceDefinitions(const InterfaceDefinitions&){};
    virtual void Visit_FileRef(const FileRef&){};
    virtual void Visit_ExceptionRef(const ExceptionRef&){};
    virtual void Visit_SwitchedAggregate(const SwitchedAggregate&){};
    virtual void Visit_Member(const Member&){};
    virtual void Visit_Boxed(const Boxed&){};
    virtual void Visit_EnumValue(const EnumValue&){};
    virtual void Visit_Label(const Label&){};
    virtual void Visit_Aggregate(const Aggregate&){};
    virtual void Visit_Alias(const Alias&){};
    virtual void Visit_Collection(const Collection&){};
    virtual void Visit_Discriminator(const Discriminator&){};
    virtual void Visit_Enum(const Enum&){};
    virtual void Visit_LabelConnection(const LabelConnection&){};
    virtual void Visit_SetException(const SetException&){};
    virtual void Visit_LookupKey(const LookupKey&){};
    virtual void Visit_Attribute(const Attribute&){};
    virtual void Visit_MakeMemberPrivate(const MakeMemberPrivate&){};
    virtual void Visit_PrivateFlag(const PrivateFlag&){};
    virtual void Visit_GetException(const GetException&){};
    virtual void Visit_Inherits(const Inherits&){};
    virtual void Visit_ValueObject(const ValueObject&){};
    virtual void Visit_Event(const Event&){};
    virtual void Visit_AttributeMember(const AttributeMember&){};
    virtual void Visit_ManagesComponent(const ManagesComponent&){};
    virtual void Visit_ComponentFactory(const ComponentFactory&){};
    virtual void Visit_Object(const Udm::Object&){};
    virtual void Visit_PathDiagrams(const PathDiagrams&);

    void add_tree_edge (int source , int target);

  private:

    DOMImplementation*  impl_;
    DOMDocument*        doc_;
    DOMElement*         root_;
    DOMElement*         curr_;
    DOMLSSerializer*          serializer_;
    XMLFormatTarget*    target_;
    std::stack<DOMElement*> curr_stack_;

    // Maintain associations between ComponentType and ComponentPackages
    std::map<std::string, std::string> interfaces_;

    // Maintain associations between PublishConnector and event publishers
    std::map<std::string, OutEventPort> publishers_;

    // Maintain associations between PublishConnector and event consumers
    std::multimap<std::string, InEventPort> consumers_;

    // Maintain association between pair<Component, Readonlyattribute> and
    // Property
    std::map<std::pair<std::string, std::string>, Property> attrValues_;

    void init();
    void initTarget (const std::string& fileName);
    void initDocument (const std::string& rootName);
    void initRootAttributes();
    void dumpDocument();

    void push();
    void pop();
    std::string ExtractName (Udm::Object obj);
    DOMElement* createSimpleContent (const std::string& name,
                                     const std::string& value);


    /// Representing a Component Port tuple
    typedef std::map<ComponentInstance, Port> Component_Port;


    void GetReceptacleComponents (const RequiredRequestPort& receptacle,
                                  Component_Port& output);

    void GetFacetComponents (const ProvidedRequestPort& facet,
                             Component_Port& output);

    void GetEventSinkComponents (const InEventPort& consumer,
                                 Component_Port& output);

    void GetEventSourceComponents (const OutEventPort& publisher,
                                   Component_Port& output);

    void GetAttributeComponents (const AttributeMapping& mapping,
                                 std::set<std::pair<std::string, std::string> >& output);

    template <typename T, typename Del, typename DelRet, typename DelEndRet>
    void GetComponents (const T& port,
                        DelRet (T::*srcDel)() const,
                        DelRet (T::*dstDel) () const,
                        DelEndRet (Del::*srcDelEnd)() const,
                        DelEndRet (Del::*dstDelEnd)() const,
                        Component_Port& output,
                        std::set<T>& visited);

    void CreateConnections (const Component_Port& src,
                            const Component_Port& dst);

    void CreateConnection (const ComponentInstance & srcComp,
                           const Port& srcPort,
                           const ComponentInstance & dstComp,
                           const Port& dstPort);
    void CreateAssemblyInstances (std::set<ComponentInstance>& comps);
    void CreateAssemblyConnections (std::vector<ComponentAssembly>& assemblies);
    void CreateAttributeMappings (std::vector<ComponentAssembly>& assemblies);
    void CreatePropertyElement (std::string name, const Property& property);

  void add_the_edges (Component_Port_Vertex start_vertex,
                      Component_Port_Vertex end_vertex);



  //typedef the Graph Object
  // create a typedef for the Graph type
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;
  // The Vertex typedef
  typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
  //typedef boost::graph_traits<Graph>::edge_descriptor edge;
  typedef boost::graph_traits < Graph >::vertices_size_type size_type;

  void CalculatePath (std::vector < size_type >& discover);
  std::set<ComponentInstance> comps;

  //
    // The Graph object
    Graph the_graph_;

    // Maintain associations Component-Port to a id
    // which represents its graph-vertex
    //std::map<int, std::string> graph_vertex_indices_;

    /// Contains the mapping with
    /// key node index , value Component_Vertex
    std::map <int, Component_Port_Vertex> graph_vertex_indices_;

    /// Contains a mapping with
    /// key Component_port , value node index
    std::map<std::string, int> graph_vertex_;

  public:
    // port mappings ....
      std::vector<Edge_Numbers> dfs_edges;

      std::list <Edge_Numbers> all_edges;

      std::vector <Edge_Numbers> forward_edges_;

//  protected:
      ///The list of Paths , stored here
      typedef std::list <int> A_Path;

      A_Path current_path_;

      /// A list of paths
      typedef std::list <A_Path>  PathList;

      /// A Paths variable
      PathList all_the_paths_;

      /// The Start port index , usually 0
      int start_port_;

      /// The end port index , usually 1
      int end_port_;

      /// flag to to indicate , dfs going on in tree with
      /// root as end_port_
      bool searching_end_tree_;

      /// all path calculated , ignore any more path
      bool got_all_path_;

      /// searches previous paths
      void search_node_in_previous_paths (int node);

      /// Extracs the UUID
      std::string extract_uuid (Udm::Object obj);

  protected:

    // mapping of port and number , not used now ...
      std::map <int , Port> port_map_;

      // total number of vertex count ..
      int vertex_count_;

      /// The function which draws the path
      void draw_path (A_Path* a_path);

      /// current path diagram
      Path the_current_path_flow_;


  // The container which contains the sorted vertices
    typedef std::vector< Vertex > container;

    container sorted_vertices;


  };
}

#endif /* PACKAGE_VISITOR_H */
