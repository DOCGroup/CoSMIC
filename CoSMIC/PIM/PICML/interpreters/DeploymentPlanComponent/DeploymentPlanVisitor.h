// $Id: DeploymentPlanVisitor.h,v 1.1.2.1 2006/03/29 22:54:09 jai Exp $

#ifndef DEPLOYMENTPLAN_VISITOR_H
#define DEPLOYMENTPLAN_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include "PICML/PICML.h"

// Xerces includes
#include "xercesc/util/PlatformUtils.hpp"
#include "xercesc/util/XMLString.hpp"
#include "xercesc/dom/DOM.hpp"
#include "xercesc/framework/LocalFileFormatTarget.hpp"

#include "Utils/UDM/Abstract_Type_Dispatcher_T.h"
#include "XML_Document.h"

#include "DeploymentPlan_Export.h"

/**
 * @class PredefinedType_Dispatcher
 */
class PredefinedType_Dispatcher :
  public UDM_Abstract_Type_Dispatcher_T <PICML::Visitor>
{
public:
  PredefinedType_Dispatcher (void)
  {    
    this->insert <PICML::Boolean> ();

    this->insert <PICML::Byte> ();
    this->insert <PICML::Char> ();
    this->insert <PICML::WideChar> ();

    this->insert <PICML::String> ();
    this->insert <PICML::WideString> ();

    this->insert <PICML::ShortInteger> ();
    this->insert <PICML::LongInteger> ();
    this->insert <PICML::LongLongInteger> ();

    this->insert <PICML::UnsignedShortInteger> ();
    this->insert <PICML::UnsignedLongInteger> ();
    this->insert <PICML::UnsignedLongLongInteger> ();

    this->insert <PICML::FloatNumber> ();
    this->insert <PICML::DoubleNumber> ();
    this->insert <PICML::LongDoubleNumber> ();

    this->insert <PICML::Enum> ();
  }
};

class CollocationGroupMember_Dispatcher :
  public UDM_Abstract_Type_Dispatcher_T <PICML::Visitor>
{
public:
  CollocationGroupMember_Dispatcher (void)
  {
    this->insert <PICML::ComponentInstanceRef> ();
  }
};

/**
 * @class DeploymentPlanVisitor
 */
class DeploymentPlan_Export DeploymentPlanVisitor : 
  public PICML::Visitor,
  public XML_Document
{
public:
  /**
   * Initializing constructor.
   */
  DeploymentPlanVisitor (const std::string & outputPath);

  /// Destructor.
  virtual ~DeploymentPlanVisitor (void);

  virtual void Visit_RootFolder (const PICML::RootFolder &);
  
  virtual void Visit_DeploymentPlans (const PICML::DeploymentPlans &);
  
  virtual void Visit_DeploymentPlan (const PICML::DeploymentPlan &);
  
  virtual void Visit_NodeReference (const PICML::NodeReference &);
  
  virtual void Visit_InstanceMapping (const PICML::InstanceMapping &);
  
  virtual void Visit_CollocationGroup (const PICML::CollocationGroup &);

  virtual void Visit_ComponentInstanceRef (const PICML::ComponentInstanceRef &);

  virtual void Visit_ComponentInstance (const PICML::ComponentInstance &);

  virtual void Visit_ComponentInstanceType (const PICML::ComponentInstanceType &);

  virtual void Visit_MonolithicImplementation (const PICML::MonolithicImplementation &);

  virtual void Visit_MonolithprimaryArtifact (const PICML::MonolithprimaryArtifact & mpa);

  virtual void Visit_ImplementationArtifactReference (const PICML::ImplementationArtifactReference & );

  virtual void Visit_ImplementationArtifact (const PICML::ImplementationArtifact & );

  virtual void Visit_MonolithExecParameter (const PICML::MonolithExecParameter & );

  virtual void Visit_ArtifactDependsOn (const PICML::ArtifactDependsOn & );

  virtual void Visit_Property (const PICML::Property & );

  virtual void Visit_DataType (const PICML::DataType & );

  virtual void Visit_ArtifactExecParameter (const PICML::ArtifactExecParameter & );

  virtual void Visit_ComponentImplementationArtifact (const PICML::ComponentImplementationArtifact & );

  virtual void Visit_ComponentServantArtifact (const PICML::ComponentServantArtifact & );

  virtual void Visit_ConfigProperty (const PICML::ConfigProperty & );

  virtual void Visit_AssemblyConfigProperty (const PICML::AssemblyConfigProperty &);

  virtual void Visit_ComponentAssembly (const PICML::ComponentAssembly & );

  virtual void Visit_AttributeInstance (const PICML::AttributeInstance & );

  virtual void Visit_AttributeValue (const PICML::AttributeValue & );

  virtual void Visit_ConnectorImplementationType (const PICML::ConnectorImplementationType &);

  virtual void Visit_ConnectorImplementation (const PICML::ConnectorImplementation &);

  typedef std::map <PICML::CollocationGroup, xercesc::DOMElement *> locality_t;

  virtual void deploy_connector_fragment (const PICML::ConnectorInstance &,
                                          const PICML::CollocationGroup &);

  const locality_t & localities (void) const;

private:
  void Visit_MonolithicImplementationBase (const PICML::MonolithicImplementationBase & );

  /// Initialize the object.
  void init (void);

  void init_document (const std::string & root);

  void write_artifact_execParameter (const std::string & name,
                                     const std::string & value);

  PredefinedType_Dispatcher datatypes_;

  CollocationGroupMember_Dispatcher cgm_dispatcher_;

  xercesc::DOMImplementation *  impl_;

  xercesc::DOMDocument * doc_;

  xercesc::DOMLSOutput * output_;

  xercesc::DOMLSSerializer * serializer_;

  std::string outputPath_;

  /// The current node for the iteration.
  PICML::Node current_node_;

  /// Collection of instances in the current deployment.
  std::map <PICML::ComponentInstance, xercesc::DOMElement *> insts_;

  std::map <std::string, xercesc::DOMElement *> conn_insts_;

  /// Collection of implementation in the current deployment.
  std::map <PICML::Implemenation, xercesc::DOMElement *> impls_;
  
  /// Collection of artifacts in the current deployment.
  std::map <PICML::ImplementationArtifact, xercesc::DOMElement *> artifacts_;
  
  /// Collection of connections in the current deployment.
  std::vector <xercesc::DOMElement *> conns_;

  /// Collection of plan localities in the current deployment.
  std::map <PICML::CollocationGroup, xercesc::DOMElement *> locality_;

  xercesc::DOMElement * curr_locality_;

  xercesc::DOMElement * curr_instance_;

  xercesc::DOMElement * curr_impl_;

  xercesc::DOMElement * curr_artifact_;

  xercesc::DOMElement * param_parent_;

  xercesc::DOMElement * curr_param_;

  xercesc::DOMElement * curr_value_;

  PICML::ComponentImplementationArtifact impl_artifact_;

  PICML::ComponentServantArtifact svnt_artifact_;

  std::string parameter_type_;
};

#endif /* FLATPLAN_VISITOR_H */
