// -*- C++ -*-

//=====================================================================================
#ifndef _QED_DEPLOYMENT_VISITOR_H_
#define _QED_DEPLOYMENT_VISITOR_H_

#include "PICML/PICML.h"
#include "QED_Deployment_Export.h"

#include "xercesc/util/PlatformUtils.hpp"
#include "xercesc/util/XMLString.hpp"
#include "xercesc/dom/DOM.hpp"
#include "xercesc/framework/LocalFileFormatTarget.hpp"

#include <stack>
#include <deque>

/**
 * @class QED_Deployment_Visitor
 *
 * Visitor that is responsible for generating the deployment
 * configuration file for QED.
 */
class QED_Deployment_Export QED_Deployment_Visitor : 
  public PICML::Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       output      Output path for the document.
   */
  QED_Deployment_Visitor (const std::string & output);

  /// Destructor
  virtual ~QED_Deployment_Visitor (void);

  // Visit the RootFolder element
  virtual void Visit_RootFolder (
    const PICML::RootFolder &);
  
  // Visit the ComponentImplementations element
  virtual void Visit_ComponentImplementations (
    const PICML::ComponentImplementations &);

  virtual void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer & );

  virtual void Visit_ComponentAssembly (
    const PICML::ComponentAssembly & );

  virtual void Visit_Component (
    const PICML::Component &);

  virtual void Visit_Attribute (
    const PICML::Attribute &);

  virtual void Visit_AttributeValue (
    const PICML::AttributeValue &);

  virtual void Visit_Property (
    const PICML::Property &);

  virtual void Visit_ConfigProperty (
    const PICML::ConfigProperty &);

  virtual void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation & impl);

  virtual void Visit_AssemblyConfigProperty (
    const PICML::AssemblyConfigProperty &);

  virtual void Visit_DeploymentPlans (
    const PICML::DeploymentPlans &);

  virtual void Visit_DeploymentPlan (
    const PICML::DeploymentPlan &);

  virtual void Visit_NodeReference (
    const PICML::NodeReference &);

  virtual void Visit_InstanceMapping (
    const PICML::InstanceMapping & mapping);

  virtual void Visit_CollocationGroup (
    const PICML::CollocationGroup &);

  virtual void Visit_Node (
    const PICML::Node & );

  virtual void Visit_Domain (
    const PICML::Domain & );

  virtual void Visit_ComponentRef (
    const PICML::ComponentRef &);

private:
  void Visit_CollocationGroupMember (
    const PICML::CollocationGroupMember &);

  void write_property (const std::map <std::string, 
                                       std::string>::value_type &);

  std::string scope (const std::string & separator) const;

  void serialize_xml_to_file (const std::string & filename);

  /// The output path for the document.
  const std::string & output_;

  /// Currently constructed path.
  std::stack <std::string> path_;

  std::stack <std::string> scope_;

  xercesc::DOMImplementation * impl_;

  xercesc::DOMDocument * doc_;

  xercesc::DOMWriter * serializer_;

  xercesc::XMLFormatTarget * target_;

  std::stack <xercesc::DOMElement *> root_;
  
  std::map <std::string, std::string> default_props_;

  std::string location_;

  std::map <PICML::Component, std::string> instance_names_;
};

#endif  /* _QED_DEPLOYMENT_VISITOR_H_ */
