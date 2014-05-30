// $Id$

#include "External_Reference_Visitor.h"

#include "game/xml/String.h"
#include "Utils/udm/visit.h"

#include "boost/bind.hpp"
#include <algorithm>

//
// Visit_Component
//
void PICML_External_Reference_Visitor::
Visit_ComponentInstance (const PICML::ComponentInstance & c)
{
  using namespace PICML;

  CoSMIC::Udm::visit_all <PICML::RequiredRequestPortInstance> (c, *this);
  CoSMIC::Udm::visit_all <PICML::ProvidedRequestPortInstance> (c, *this);
  CoSMIC::Udm::visit_all <PICML::InEventPortInstance> (c, *this);
  CoSMIC::Udm::visit_all <PICML::OutEventPortInstance> (c, *this);
}

//
// Visit_RequiredRequestPort
//
void PICML_External_Reference_Visitor::
Visit_RequiredRequestPortInstance (const PICML::RequiredRequestPortInstance & inst)
{
  // Check if the port has an external connection.
  PICML::RequiredRequestPort port = inst.ref ();
  const char * kind = port.multiple_connections () ? "MultiplexReceptacle" : "SimplexReceptacle";
  std::set <PICML::ExternalDelegate> ed = inst.srcExternalDelegate ();

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              inst,
                              port,
                              kind,
                              false,
                              _1));
}

//
// Visit_ProvidedRequestPort
//
void PICML_External_Reference_Visitor::
Visit_ProvidedRequestPortInstance (const PICML::ProvidedRequestPortInstance & inst)
{
  // Check if the port has an external connection.
  std::set <PICML::ExternalDelegate> ed = inst.srcExternalDelegate ();
  static const char * kind = "Facet";

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              inst,
                              inst.ref (),
                              kind,
                              true,
                              _1));
}

//
// Visit_InEventPort
//
void PICML_External_Reference_Visitor::
Visit_InEventPortInstance (const PICML::InEventPortInstance & inst)
{
  std::set <PICML::ExternalDelegate> ed = inst.srcExternalDelegate ();
  static const char * kind = "EventConsumer";

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              inst,
                              inst.ref (),
                              kind,
                              true,
                              _1));
}

//
// Visit_OutEventPort
//
void PICML_External_Reference_Visitor::
Visit_OutEventPortInstance (const PICML::OutEventPortInstance & inst)
{
  PICML::OutEventPort port = inst.ref ();
  const char * kind = port.single_destination () ? "EventEmitter" : "EventPublisher";
  std::set <PICML::ExternalDelegate> ed = inst.srcExternalDelegate ();

  std::for_each (ed.begin (),
                 ed.end (),
                 boost::bind (&PICML_External_Reference_Visitor::Visit_Port,
                              this,
                              inst,
                              port,
                              kind,
                              false,
                              _1));
}

//
// Visit_Port
//
void PICML_External_Reference_Visitor::
Visit_Port (const PICML::MgaObject & port,
            const PICML::MgaObject & porttype,
            const std::string & provider_type,
            bool provider,
            const PICML::ExternalDelegate & ed)
{
  using namespace xercesc;
  using namespace GAME::Xml;

  // Create the <connection> element.
  DOMElement * conn = this->doc_->createElement (String ("connection"));

  // Set the name of the connection.
  std::string name (port.getPath (".", false, true, "name", true));
  name.append ("::");
  name.append (ed.getPath (".", false, true, "name", true));

  this->create_simple_content (conn, "name", name);

  // Create the <internalEndpoint> part of the connection.
  DOMElement * endpoint = this->create_element (conn, "internalEndpoint");

  // Create the child elements for this element.
  this->create_simple_content (endpoint, "portName", porttype.name ());
  this->create_simple_content (endpoint, "provider", provider ? "true" : "false");
  this->create_simple_content (endpoint, "kind", provider_type);

  // Set the instance for the connection.
  PICML::ComponentInstance parent = PICML::ComponentInstance::Cast (port.GetParent ());
  std::string id = std::string ("_") + std::string (parent.UUID ());

  DOMElement * inst = this->create_element (endpoint, "instance");
  inst->setAttribute (String ("xmi:idref"), String (id));

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
