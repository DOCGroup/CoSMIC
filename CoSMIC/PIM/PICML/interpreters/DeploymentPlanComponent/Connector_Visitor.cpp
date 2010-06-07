// $Id$

#include "Connector_Visitor.h"
#include "DeploymentPlanVisitor.h"

#include "Utils/xercesc/XercesString.h"
#include "boost/bind.hpp"

//
// Connector_Visitor
//
Connector_Visitor::
Connector_Visitor (DeploymentPlanVisitor & v, xercesc::DOMDocument * doc)
: dpv_ (v),
  doc_ (doc)
{

}

//
// ~Connector_Visitor
//
Connector_Visitor::~Connector_Visitor (void)
{

}

//
// Visit_ComponentInstance
//
void Connector_Visitor::
Visit_ComponentInstance (const PICML::ComponentInstance & inst)
{
  std::vector <PICML::ExtendedPort> extended = inst.ExtendedPort_children ();
  std::for_each (extended.begin (),
                 extended.end (),
                 boost::bind (&PICML::ExtendedPort::Accept, 
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ExtendedPort
//
void Connector_Visitor::
Visit_ExtendedPort (const PICML::ExtendedPort & port)
{
  // Check if this port type is sending anything to a connector.
  PICML::Publish publish = port.dstPublish ();

  if (publish != Udm::null)
    publish.Accept (*this);

  // We also need to see if this port type is receiving anything 
  // from a connector.
  PICML::Consume consume = port.srcConsume ();

  if (consume != Udm::null)
    consume.Accept (*this);
}

//
// Visit_Publish
//
void Connector_Visitor::Visit_Publish (const PICML::Publish & publish)
{
  // Create the first endpoint of the connection.

  // Make sure to include this instance in deployment plan.
  PICML::ConnectorInstance inst = publish.dstPublish_end ();
  inst.Accept (this->dpv_);

  // Create the second endpoint of the connection.
}

//
// Visit_Publish
//
void Connector_Visitor::Visit_Consume (const PICML::Consume & consume)
{
  // Create the first endpoint of the connection.

  // Make sure to include this instance in deployment plan.
  PICML::ConnectorInstance inst = consume.srcConsume_end ();
  inst.Accept (this->dpv_);

  // Create the second endpoint of the connection.
}

//
// connections
//
const std::vector <xercesc::DOMElement *> & Connector_Visitor::connections (void) const
{
  return this->conns_;
}

//
// create_connection
//
void Connector_Visitor::
create_connection (const std::string & name, 
                   xercesc::DOMNode * ep1,
                   xercesc::DOMNode * ep2)
{
  // Create the new connection.
  xercesc::DOMElement * conn = this->doc_->createElement (Utils::XStr ("connection"));
  this->create_simple_content (conn, "name", name);

  // Add its endpoints.
  conn->appendChild (ep1);
  conn->appendChild (ep2);

  // Save the connection.
  this->conns_.push_back (conn);
}

