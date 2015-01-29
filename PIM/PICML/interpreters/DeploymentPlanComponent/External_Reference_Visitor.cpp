#include "StdAfx.h"
#include "External_Reference_Visitor.h"

#include "game/xml/String.h"

namespace PICML
{
namespace Deployment
{

//
// Visit_Component
//
void External_Reference_Visitor::
Visit_ComponentInstance (ComponentInstance_in c)
{
  for (RequiredRequestPortInstance port : c->get_RequiredRequestPortInstances ())
    port->accept (this);

  for (ProvidedRequestPortInstance port : c->get_ProvidedRequestPortInstances ())
    port->accept (this);

  for (InEventPortInstance port : c->get_InEventPortInstances ())
    port->accept (this);

  for (OutEventPortInstance port : c->get_OutEventPortInstances ())
    port->accept (this);
}

//
// Visit_RequiredRequestPort
//
void External_Reference_Visitor::
Visit_RequiredRequestPortInstance (RequiredRequestPortInstance_in inst)
{
  // Check if the port has an external connection.
  RequiredRequestPort port = inst->refers_to ();
  const char * kind = port->multiple_connections () ? "MultiplexReceptacle" : "SimplexReceptacle";

  std::vector <ExternalDelegate> delegates;
  inst->dst_ExternalDelegate (delegates);

  for (ExternalDelegate ed : delegates)
    this->Visit_Port (inst, port, kind, false, ed);
}

//
// Visit_ProvidedRequestPort
//
void External_Reference_Visitor::
Visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in inst)
{
  // Check if the port has an external connection.
  std::vector <ExternalDelegate> delegates;
  inst->dst_ExternalDelegate (delegates);

  for (ExternalDelegate ed : delegates)
    this->Visit_Port (inst, inst->refers_to (), "Facet", true, ed);
}

//
// Visit_InEventPort
//
void External_Reference_Visitor::
Visit_InEventPortInstance (InEventPortInstance_in inst)
{
  std::vector <ExternalDelegate> delegates;
  inst->dst_ExternalDelegate (delegates);

  for (ExternalDelegate ed : delegates)
    this->Visit_Port (inst, inst->refers_to (), "EventConsumer", true, ed);
}

//
// Visit_OutEventPort
//
void External_Reference_Visitor::
Visit_OutEventPortInstance (OutEventPortInstance_in inst)
{
  OutEventPort port = inst->refers_to ();
  const char * kind = port->single_destination () ? "EventEmitter" : "EventPublisher";

  std::vector <ExternalDelegate> delegates;
  inst->dst_ExternalDelegate (delegates);

  for (ExternalDelegate ed : delegates)
    this->Visit_Port (inst, port, kind, false, ed);
}

//
// Visit_Port
//
void External_Reference_Visitor::
Visit_Port (GAME::Mga::FCO_in port,
            GAME::Mga::FCO_in porttype,
            const std::string & provider_type,
            bool provider,
            ExternalDelegate_in ed)
{
  // Create the <connection> element.
  GAME::Xml::Fragment conn = this->document_.create_element ("connection");

  // Set the name of the connection.
  std::string name (port->path (".", false));
  name.append ("::");
  name.append (ed->path (".", false));

  conn.create_simple_content ("name", name);

  // Create the <internalEndpoint> part of the connection.
  GAME::Xml::Fragment endpoint = conn.create_element ("internalEndpoint");

  // Create the child elements for this element.
  endpoint.create_simple_content ("portName", porttype->name ());
  endpoint.create_simple_content ("provider", provider ? "true" : "false");
  endpoint.create_simple_content ("kind", provider_type);

  // Set the instance for the connection.
  ComponentInstance parent = ComponentInstance::_narrow (port->parent ());
  std::string id = "_" + parent->UUID ();

  GAME::Xml::Fragment inst = endpoint.create_element ("instance");
  inst.set_attribute ("xmi:idref", id);

  // Create the <externalReference> element.
  ExternalPort ex = ed->src_ExternalPort ();
  GAME::Xml::Fragment external = conn.create_element ("externalReference");

  // Create the child elements for this element.
  external.create_simple_content ("location", ex->location ());
  external.create_simple_content ("provider", provider ? "false" : "true");
  external.create_simple_content ("portName", ex->name ());
  external.create_simple_content ("supportedType", "");

  // Save the connection.
  this->conns_.push_back (conn);
}

}
}
