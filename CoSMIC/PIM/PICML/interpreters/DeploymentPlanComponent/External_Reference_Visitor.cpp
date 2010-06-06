// $Id$

#include "External_Reference_Visitor.h"
#include "Utils/xercesc/XercesString.h"
#include "boost/bind.hpp"
#include <algorithm>

template <typename VISITOR, typename T>
void visit_all (VISITOR & v, T & coll)
{
  std::for_each (coll.begin (),
                 coll.end (),
                 boost::bind (&T::value_type::Accept, _1, boost::ref (v)));
}

//
// Visit_Component
//
void PICML_External_Reference_Visitor::
Visit_ComponentInstance (const PICML::ComponentInstance & c)
{
  using namespace PICML;

  visit_all (*this, std::vector <RequiredRequestPort> (c.RequiredRequestPort_kind_children ()));
  visit_all (*this, std::vector <ProvidedRequestPort> (c.ProvidedRequestPort_kind_children ()));
  visit_all (*this, std::vector <InEventPort> (c.InEventPort_kind_children ()));
  visit_all (*this, std::vector <OutEventPort> (c.OutEventPort_kind_children ()));
}

//
// Visit_RequiredRequestPort
//
void PICML_External_Reference_Visitor::
Visit_RequiredRequestPort (const PICML::RequiredRequestPort & port)
{
  // Check if the port has an external connection.
  const char * kind = port.multiple_connections () ? "MultiplexReceptacle" : "SimplexReceptacle";
  std::set <PICML::ExternalDelegate> ed = port.srcExternalDelegate ();

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              kind,
                              false,
                              _1));
}

//
// Visit_ProvidedRequestPort
//
void PICML_External_Reference_Visitor::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & port)
{
  // Check if the port has an external connection.
  std::set <PICML::ExternalDelegate> ed = port.srcExternalDelegate ();
  static const char * kind = "Facet";

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              kind,
                              true,
                              _1));
}

//
// Visit_InEventPort
//
void PICML_External_Reference_Visitor::
Visit_InEventPort (const PICML::InEventPort & port)
{
  std::set <PICML::ExternalDelegate> ed = port.srcExternalDelegate ();
  static const char * kind = "EventConsumer";

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              kind,
                              true,
                              _1));
}

//
// Visit_OutEventPort
//
void PICML_External_Reference_Visitor::
Visit_OutEventPort (const PICML::OutEventPort & port)
{
  std::set <PICML::ExternalDelegate> ed = port.srcExternalDelegate ();
  const char * kind = port.single_destination () ? "EventEmitter" : "EventPublisher";

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              kind,
                              false,
                              _1));
}

//
// Visit_ExternalPortReference
//
void PICML_External_Reference_Visitor::
Visit_Port (const PICML::Port & port,
            const std::string & provider_type,
            bool provider,
            const PICML::ExternalDelegate & ed)
{
  using namespace xercesc;
  using namespace Utils;

  // Create the <connection> element.
  DOMElement * conn = this->doc_->createElement (Utils::XStr ("connection"));

  // Set the name of the connection.
  std::string name (port.getPath (".", false, true, "name", true));
  name.append ("::");
  name.append (ed.getPath (".", false, true, "name", true));

  this->create_simple_content (conn, "name", name);

  // Create the <internalEndpoint> part of the connection.
  DOMElement * endpoint = this->create_element (conn, "internalEndpoint");

  // Create the child elements for this element.
  this->create_simple_content (endpoint, "portName", port.name ());
  this->create_simple_content (endpoint, "provider", provider ? "true" : "false");
  this->create_simple_content (endpoint, "kind", provider_type);

  // Set the instance for the connection.
  PICML::Component parent = port.Component_parent ();
  std::string id = std::string ("_") + std::string (parent.UUID ());

  DOMElement * inst = this->create_element (endpoint, "instance");
  inst->setAttribute (XStr ("xmi:idref"), XStr (id));

  // Create the <externalReference> element.
  PICML::ExternalPort ex = ed.srcExternalDelegate_end ();
  DOMElement * external = this->create_element (conn, "externalReference");

  // Create the child elements for this element.
  this->create_simple_content (external, "location", ex.location ());
  this->create_simple_content (external, "provider", provider ? "false" : "true");
  this->create_simple_content (external, "portName", ex.name ());
  this->create_simple_content (external, "supportedType", "");

  // Save the connection.
  this->conns_.push_back (conn);
}

//
// connections
//
const std::vector <xercesc::DOMElement *> & 
PICML_External_Reference_Visitor::connections (void) const
{
  return this->conns_;
}
