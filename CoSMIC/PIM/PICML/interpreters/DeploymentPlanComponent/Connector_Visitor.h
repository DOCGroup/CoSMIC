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
#include "game/xml/Fragment.h"

// Forward decl.
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
  Connector_Visitor (DeploymentPlanVisitor & dpv,
                     std::vector <xercesc::DOMElement *> & conns,
                     xercesc::DOMDocument * doc);

  /// Destructor.
  virtual ~Connector_Visitor (void);

  virtual void Visit_ComponentInstance (const PICML::ComponentInstance &);

  virtual void Visit_ExtendedPortInstance (const PICML::ExtendedPortInstance &);

  virtual void Visit_MirrorPortInstance (const PICML::MirrorPortInstance &);

  virtual void Visit_RequiredRequestPortInstance (const PICML::RequiredRequestPortInstance &);

  virtual void Visit_ProvidedRequestPortInstance (const PICML::ProvidedRequestPortInstance &);

  virtual void Visit_Publish (const PICML::Publish & );

  virtual void Visit_Consume (const PICML::Consume & );

  virtual void Visit_ConnectorToReceptacle (const PICML::ConnectorToReceptacle &);

  virtual void Visit_ConnectorToFacet (const PICML::ConnectorToFacet &);

  virtual void Visit_FacetDelegate (const PICML::FacetDelegate &);
  virtual void Visit_ReceptacleDelegate (const PICML::ReceptacleDelegate &);

  virtual void Visit_PortType (const PICML::PortType & pt);

  virtual void Visit_RequiredRequestPort (const PICML::RequiredRequestPort &);

  virtual void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort &);

private:
  void Visit_ProvidedRequestPortEnd (const PICML::ProvidedRequestPortEnd &);
  void Visit_RequiredRequestPortEnd (const PICML::RequiredRequestPortEnd &);

  bool is_ami4ccm_connector (const PICML::ConnectorInstance & inst);
  bool is_ami4ccm_connector (const PICML::ConnectorObject & obj);

  void Visit_ExtendedPortInstanceBase (
    const PICML::ExtendedPortInstanceBase & base,
    const PICML::PortType & pt);

  void Visit_MirrorPortInstanceBase (
    const PICML::MirrorPortInstanceBase & base,
    const PICML::PortType & pt);

  bool find_plan_locality (const PICML::ComponentInstance & inst);

  void start_new_connection (const PICML::Object & obj);

  void append_endpoint (const std::string & portname,
                        const std::string & kind,
                        const std::string & provider,
                        const std::string & inst);

  void end_connection (void);

  void Visit_RequiredRequestPort_i (const std::string & inst,
                                    const std::string & prefix,
                                    const std::string & port,
                                    bool invert);

  void Visit_ProvidedRequestPort_i (const std::string & inst,
                                    const std::string & prefix,
                                    const std::string & port,
                                    bool invert);

  void deploy_connector_fragment (const PICML::ConnectorInstance & inst);

  void make_connection_local (xercesc::DOMElement * conn);

  DeploymentPlanVisitor & dpv_;

  /// Set of connection gathered.
  std::vector <xercesc::DOMElement *> & conns_;

  /// The target document.
  xercesc::DOMDocument * doc_;

  GAME::Xml::Fragment curr_conn_;

  GAME::Xml::Fragment name_element_;

  std::string connection_name_;

  PICML::CollocationGroup group_;

  PICML::ComponentInstance comp_inst_;

  PICML::RequiredRequestPort receptacle_;
  PICML::ProvidedRequestPort facet_;

  std::string connector_uuid_;
  std::string connector_name_;

  std::string prefix1_;
  std::string prefix2_;
  std::string portname2_;

  bool override_portname2_;

  bool invert_;

  std::map <PICML::ConnectorInstance, std::string> connector_uuids_;

  PICML::ProvidedRequestPortInstance active_facet_;
  PICML::RequiredRequestPortInstance active_receptacle_;

  std::map <PICML::ProvidedRequestPortInstance, std::string> ami4ccm_uuids_;
};

#endif  // !defined _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_
