// -*- C++ -*-

//=============================================================================
/**
 * @file        Connector_Visitor.h
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_
#define _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_

#include "PICML/PICML.h"
#include "PICML/Visitor.h"

#include "game/xml/Document.h"

#include "Deployment_Handler.h"

namespace PICML
{
namespace Deployment
{

/**
 * @class DeploymentPlanVisitor
 */
class Connector_Visitor : public Visitor
{
public:
  /**
   * Initializing constructor.
   */
  Connector_Visitor (Deployment_Handler * handler,
                     GAME::Xml::Document document,
                     std::vector <GAME::Xml::Fragment> & conns);

  /// Destructor.
  virtual ~Connector_Visitor (void);

  virtual void Visit_ComponentInstance (ComponentInstance_in);

  virtual void Visit_ExtendedPortInstance (ExtendedPortInstance_in);

  virtual void Visit_MirrorPortInstance (MirrorPortInstance_in);

  virtual void Visit_RequiredRequestPortInstance (RequiredRequestPortInstance_in);

  virtual void Visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in);

  virtual void Visit_Publish (Publish_in );

  virtual void Visit_Consume (Consume_in );

  virtual void Visit_ConnectorToReceptacle (ConnectorToReceptacle_in);

  virtual void Visit_ConnectorToFacet (ConnectorToFacet_in);

  virtual void Visit_FacetDelegate (FacetDelegate_in);
  virtual void Visit_ReceptacleDelegate (ReceptacleDelegate_in);

  virtual void Visit_PortType (PortType_in pt);

  virtual void Visit_RequiredRequestPort (RequiredRequestPort_in);

  virtual void Visit_ProvidedRequestPort (ProvidedRequestPort_in);

private:
  void Visit_ProvidedRequestPortEnd (ProvidedRequestPortEnd_in);
  void Visit_RequiredRequestPortEnd (RequiredRequestPortEnd_in);

  bool is_ami4ccm_connector (ConnectorInstance_in inst);
  bool is_ami4ccm_connector (ConnectorObject_in obj);

  void Visit_ExtendedPortInstanceBase (
    ExtendedPortInstanceBase_in base,
    PortType_in pt);

  void Visit_MirrorPortInstanceBase (
    MirrorPortInstanceBase_in base,
    PortType_in pt);

  void start_new_connection (Object_in obj);

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

  void deploy_connector_fragment (ConnectorInstance_in inst);

  void make_connection_local (GAME::Xml::Fragment conn);

  Deployment_Handler * handler_;

  GAME::Xml::Document document_;

  std::vector <GAME::Xml::Fragment> & conns_;

  GAME::Xml::Fragment curr_conn_;

  GAME::Xml::Fragment name_element_;

  std::string connection_name_;

  CollocationGroup group_;

  ComponentInstance comp_inst_;

  RequiredRequestPort receptacle_;
  ProvidedRequestPort facet_;

  std::string connector_uuid_;
  std::string connector_name_;

  std::string prefix1_;
  std::string prefix2_;
  std::string portname2_;

  bool override_portname2_;

  bool invert_;

  std::map <ConnectorInstance, std::string> connector_uuids_;

  std::map <ConnectorInstance, size_t> connector_counter_;

  ProvidedRequestPortInstance active_facet_;
  RequiredRequestPortInstance active_receptacle_;

  std::map <ProvidedRequestPortInstance, std::string> ami4ccm_uuids_;
};

}
}

#endif  // !defined _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_
