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
  Connector_Visitor (DeploymentPlanVisitor & v, xercesc::DOMDocument * doc);

  /// Destructor.
  virtual ~Connector_Visitor (void);

  virtual void Visit_ComponentInstance (const PICML::ComponentInstance &);

  virtual void Visit_ExtendedPortInstance (const PICML::ExtendedPortInstance &);

  virtual void Visit_MirrorPortInstance (const PICML::MirrorPortInstance &);

  virtual void Visit_Publish (const PICML::Publish & );

  virtual void Visit_Consume (const PICML::Consume & );

  virtual void Visit_PortType (const PICML::PortType & pt);

  virtual void Visit_RequiredRequestPort (const PICML::RequiredRequestPort &);

  virtual void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort &);

  const std::vector <xercesc::DOMElement *> & connections (void) const;

private:
  struct fragment_t
  {
    fragment_t (const PICML::ConnectorInstance & inst, const std::string & uuid)
      : fragment_ (inst),
        uuid_ (uuid)
    {

    }

    bool operator == (const PICML::ConnectorInstance & inst) const
    {
      return this->fragment_ == inst;
    }

    bool operator < (const fragment_t & f) const
    {
      return this->fragment_ < f.fragment_;
    }

    PICML::ConnectorInstance fragment_;

    std::string uuid_;
  };

  bool find_plan_locality (const PICML::ComponentInstance & inst);

  void start_new_connection (const PICML::Object & obj);

  void append_endpoint (const std::string & portname,
                        const std::string & kind,
                        const std::string & provider,
                        const std::string & inst);

  void end_connection (void);

  void Visit_RequiredRequestPort_i (const std::string & inst,
                                    const std::string & prefix, 
                                    const PICML::RequiredRequestPort & p,
                                    std::string & portname,
                                    bool invert);

  void Visit_ProvidedRequestPort_i (const std::string & inst,
                                    const std::string & prefix,
                                    const PICML::ProvidedRequestPort & p,
                                    std::string & portname,
                                    bool invert);

  void make_connection_local (xercesc::DOMElement * conn);

  DeploymentPlanVisitor & dpv_;

  /// The target document.
  xercesc::DOMDocument * doc_;
                      
  /// Set of connection gathered.
  std::vector <xercesc::DOMElement *> conns_;

  xercesc::DOMElement * curr_conn_;
  xercesc::DOMElement * name_element_;
  std::string conn_name_;

  PICML::CollocationGroup group_;

  std::map <PICML::CollocationGroup, std::set <fragment_t> > fragments_;

  PICML::ComponentInstance comp_inst_;

  std::string conn_uuid_;
  std::string conn_path_;

  std::string prefix1_;
  std::string portname1_;

  std::string prefix2_;
  std::string portname2_;

  bool invert_;
};

#endif  // !defined _PICML_DEPLOYMENT_CONNECTOR_VISITOR_H_
