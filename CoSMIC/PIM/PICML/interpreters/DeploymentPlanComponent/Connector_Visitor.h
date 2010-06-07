// -*- C++ -*-

//=============================================================================
/**
 * @file        Connector_Visitor.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_
#define _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_

#include "PICML/PICML.h"
#include "XML_Document.h"

class DeploymentPlanVisitor;

/**
 * @class DeploymentPlanVisitor
 */
class Connector_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  /**
   * Initializing constructor.
   */
  Connector_Visitor (DeploymentPlanVisitor & v, xercesc::DOMDocument * doc);

  /// Destructor.
  virtual ~Connector_Visitor (void);

  virtual void Visit_ComponentInstance (const PICML::ComponentInstance &);

  virtual void Visit_ExtendedPort (const PICML::ExtendedPort &);

  virtual void Visit_Publish (const PICML::Publish & );

  virtual void Visit_Consume (const PICML::Consume & );

  const std::vector <xercesc::DOMElement *> & connections (void) const;

private:
  /// Helper method for creating a connection.
  void create_connection (const std::string & name, 
                          xercesc::DOMNode * e1,
                          xercesc::DOMNode * e2);

  DeploymentPlanVisitor & dpv_;

  /// The target document.
  xercesc::DOMDocument * doc_;
                      
  /// Set of connection gathered.
  std::vector <xercesc::DOMElement *> conns_;

  PICML::ConnectorInstance inst_;

  std::string name_;

  xercesc::DOMElement * endpoint_;
};

#endif  // !defined _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_
