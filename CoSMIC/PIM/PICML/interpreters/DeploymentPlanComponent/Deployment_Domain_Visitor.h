#ifndef DEPLOYMENT_DOMAIN_VISITOR_H
#define DEPLOYMENT_DOMAIN_VISITOR_H

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
 * @class Deployment_Domain_Visitor
 */
class Deployment_Domain_Visitor : 
  public PICML::Visitor,
  public XML_Document
{
  public:
  /**
   * Initializing constructor.
   */
  Deployment_Domain_Visitor (const std::string & outputPath);

  /// Destructor.
  virtual ~Deployment_Domain_Visitor (void);

  virtual void Visit_DeploymentPlan (const PICML::DeploymentPlan &);
  
  virtual void Visit_NodeReference (const PICML::NodeReference &);
  
  virtual void Visit_PropertyMapping (const PICML::PropertyMapping &);
  
  virtual void Visit_Property (const PICML::Property & );

  virtual void Visit_DataValue (const PICML::DataValue & );

  private:
  /// Initialize the object.
  void init (void);

  void init_document (const std::string & root);

  xercesc::DOMImplementation *  impl_;

  xercesc::DOMDocument * doc_;

  xercesc::DOMLSOutput * output_;

  xercesc::DOMLSSerializer * serializer_;

  std::string outputPath_;

  xercesc::DOMElement * curr_root_;

  xercesc::DOMElement * curr_node_;

  xercesc::DOMElement * curr_resource_;

  xercesc::DOMElement * curr_property_;

  xercesc::DOMElement * curr_value_;

  xercesc::DOMElement * curr_type_;

  xercesc::DOMElement * curr_value_inner_;
};

#endif