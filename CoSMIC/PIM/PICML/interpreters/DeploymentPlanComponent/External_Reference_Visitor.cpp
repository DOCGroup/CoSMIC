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
Visit_Component (const PICML::Component & c)
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
  std::set <PICML::ExternalDelegate> ed = port.srcExternalDelegate ();

  std::string kind;
  if (port.multiple_connections ())
    kind = "MultiplexReceptacle";
  else
    kind = "SimplexReceptacle";

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              kind,
                              "false",
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

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              std::string ("Facet"),
                              "true",
                              _1));
}

//
// Visit_InEventPort
//
void PICML_External_Reference_Visitor::
Visit_InEventPort (const PICML::InEventPort & port)
{
  std::set <PICML::ExternalDelegate> ed = port.srcExternalDelegate ();

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              std::string ("EventConsumer"),
                              "false",
                              _1));
}

//
// Visit_OutEventPort
//
void PICML_External_Reference_Visitor::
Visit_OutEventPort (const PICML::OutEventPort & port)
{
  std::set <PICML::ExternalDelegate> ed = port.srcExternalDelegate ();

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              port,
                              std::string ("EventProducer"),
                              "true",
                              _1));
}

//
// Visit_ExternalPortReference
//
void PICML_External_Reference_Visitor::
Visit_Port (const PICML::Port & port,
            const std::string & provider_type,
            const std::string & provider,
            const PICML::ExternalDelegate & ed)
{
  using namespace xercesc;
  using namespace Utils;

  // Create the <connection> element.
  DOMElement * conn = this->create_element ("connection");

  // Set the name of the connection.
  std::string name ("external:");
  name += ed.name ();

  this->create_simple_content (conn, "name", name);

  // Create the <internalEndpoint> part of the connection.
  DOMElement * endpoint = this->create_element (conn, "internalEndpoint");

  // Create the child elements for this element.
  this->create_simple_content (endpoint, "portName", port.name ());
  this->create_simple_content (endpoint, "provider", provider);
  this->create_simple_content (endpoint, "kind", provider_type);

  // Set the instance for the connection.
  PICML::Component parent = port.Component_parent ();
  std::string id = std::string ("_") + std::string (parent.UUID ());

  DOMElement * inst = this->create_element (endpoint, "instance");
  inst->setAttribute (XStr ("xmi:idref"), XStr (id));

  // Visit the other end of the connection.
  std::swap (this->curr_, conn);

  // Create the <externalReference> element.
  PICML::ExternalPort ex = ed.srcExternalDelegate_end ();
  DOMElement * external = this->create_element ("externalReference");

  // Create the child elements for this element.
  this->create_simple_content (external, "location", ex.location ());
  this->create_simple_content (external, "provider", provider == "true" ? "false" : "true");
  this->create_simple_content (external, "portName", ex.name ());
  this->create_simple_content (external, "supportedType", "");
  std::swap (this->curr_, conn);
}
