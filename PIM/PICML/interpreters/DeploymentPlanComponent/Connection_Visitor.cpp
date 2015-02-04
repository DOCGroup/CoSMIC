#include "StdAfx.h"

#include "Connection_Visitor.h"
#include "game/xml/String.h"

#include <set>

namespace PICML
{
namespace Deployment
{

using GAME::Xml::String;

Connection_Visitor::
Connection_Visitor (GAME::Xml::Fragment document,
                    std::vector <GAME::Xml::Fragment> & conns,
                    const std::map <ComponentInstance, GAME::Xml::Fragment> & insts)
: document_ (document),
  conns_ (conns),
  insts_ (insts)
{

}

Connection_Visitor::~Connection_Visitor (void)
{

}

void Connection_Visitor::
visit_ComponentInstance (ComponentInstance_in inst)
{
  // Visit the event sources.
  for (OutEventPortInstance port : inst->get_OutEventPortInstances ())
    port->accept (this);

  // Visit all the receptacles.
  for (RequiredRequestPortInstance port : inst->get_RequiredRequestPortInstances ())
    port->accept (this);
}

void Connection_Visitor::
visit_OutEventPortInstance (OutEventPortInstance_in source)
{
  ComponentInstance inst = source->parent_ComponentInstance ();
  const std::string uuid = "_" + inst->UUID ();
  OutEventPort port = source->refers_to ();
  const char * kind = port->single_destination () ? "EventEmitter" : "EventPublisher";
				
  // The endpoint of this connection is part of a deployed
  // instance. We therefore need to create an XML endpoint.
  this->endpoint_ = this->document_.create_element ("internalEndpoint");
  this->endpoint_.create_simple_content ("portName", source->name ());
  this->endpoint_.create_simple_content ("provider", "false");
  this->endpoint_.create_simple_content ("kind", kind);

  GAME::Xml::Fragment instance = this->endpoint_.create_simple_content ("instance", "");
  instance.set_attribute ("xmi:idref", uuid);

  this->name_ = source->path (".", false);

  // Visit the SendTo connections.
  for (SendsTo sends_to : source->src_of_SendsTo ())
    sends_to->accept (this);

  // Visit the delegation connections.
  for (EventSourceDelegate esd : source->src_of_EventSourceDelegate ())
    esd->accept (this);

  // We can release this endpoint now.
  this->endpoint_->release ();
  this->endpoint_ = 0;
}

//
// visit_RequiredRequestPort
//
void Connection_Visitor::
visit_RequiredRequestPortInstance (RequiredRequestPortInstance_in receptacle)
{
  ComponentInstance inst = receptacle->parent_ComponentInstance ();
  const std::string uuid = "_" + inst->UUID ();
  RequiredRequestPort port = receptacle->refers_to ();
  const char * kind = port->multiple_connections () ? "MultiplexReceptacle" : "SimplexReceptacle";

  // The endpoint of this connection is part of a deployed
  // instance. We therefore need to create an XML endpoint.
  this->endpoint_ = this->document_.create_element ("internalEndpoint");
  this->endpoint_.create_simple_content ("portName", receptacle->name ());
  this->endpoint_.create_simple_content ("provider", "false");
  this->endpoint_.create_simple_content ("kind", kind);

  GAME::Xml::Fragment instance = this->endpoint_.create_simple_content ("instance", "");
  instance.set_attribute ("xmi:idref", uuid);

  this->name_ = receptacle->path (".", false);

  // Visit all the connections.
  for (Invoke invoke : receptacle->src_of_Invoke ())
    invoke->accept (this);

  // Lastly, visit the delegation connections.
  for (ReceptacleDelegate deleg : receptacle->dst_of_ReceptacleDelegate ())
    deleg->accept (this);

  // We can release this endpoint now.
  this->endpoint_->release ();
  this->endpoint_ = 0;
}

//
// visit_SendsTo
//
void Connection_Visitor::visit_SendsTo (SendsTo_in sends)
{
  sends->dst_InEventPortEnd ()->accept (this);
}

//
// visit_Invoke
//
void Connection_Visitor::visit_Invoke (Invoke_in i)
{
  i->dst_ProvidedRequestPortEnd ()->accept (this);
}

//
// visit_InEventPortInstance
//
void Connection_Visitor::
visit_InEventPortInstance (InEventPortInstance_in sink)
{
  // Generate the connection information if we are deploying the component
  // that is the owner of this port.
  ComponentInstance inst = sink->parent_ComponentInstance ();
  if (this->insts_.find (inst) == this->insts_.end ())
    return;

  const std::string uuid = "_" + inst->UUID ();
  InEventPort port = sink->refers_to ();

  // Create the template endpoint for these connections.
  GAME::Xml::Fragment endpoint = this->document_.create_element ("internalEndpoint");
  endpoint.create_simple_content ("portName", port->name ());
  endpoint.create_simple_content ("provider", "true");
  endpoint.create_simple_content ("kind", "EventConsumer");

  GAME::Xml::Fragment instance = endpoint.create_simple_content ("instance", "");
  instance.set_attribute ("xmi:idref", uuid);

  // Finally, create final connection between the two endpoints.
  std::string connection_name = this->name_;
  connection_name.append ("::");
  connection_name.append (sink->path (".", false));

  // Create the connection. Make sure we clone the first endpoint so that
  // we are actually adding a "new" fragment for it.
  this->create_connection (connection_name, this->endpoint_.clone (), endpoint, false);
}

//
// visit_ProvidedRequestPort
//
void Connection_Visitor::
visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in facet)
{
  // Generate the connection information if we are deploying the component
  // that is the owner of this port.
  ComponentInstance inst = facet->parent_ComponentInstance ();
  if (this->insts_.find (inst) == this->insts_.end ())
    return;

  const std::string uuid = "_" + inst->UUID ();

  // Create the endpoint for this port.
  GAME::Xml::Fragment endpoint = this->document_.create_element ("internalEndpoint");
  endpoint.create_simple_content ("portName", facet->name ());
  endpoint.create_simple_content ("provider", "true");
  endpoint.create_simple_content ("kind", "Facet");

  GAME::Xml::Fragment instance = endpoint.create_simple_content ("instance", "");
  instance.set_attribute ("xmi:idref", uuid);

  std::string connection_name = this->name_;
  connection_name.append ("::");
  connection_name.append (facet->path (".", false));

  // Determine if this is a local connection.
  ProvidedRequestPort port = facet->refers_to ();
  Object obj = Object::_narrow (port->refers_to ());
  const std::string semantics = obj->InterfaceSemantics ();
  bool is_local = semantics == "local" ? true : false;

  // Create the connection. Make sure we clone the first endpoint so that
  // we are actually adding a "new" fragment for it.
  this->create_connection (connection_name, this->endpoint_.clone (), endpoint, is_local);
}

//
// visit_ReceptacleDelegate
//
void Connection_Visitor::
visit_ReceptacleDelegate (ReceptacleDelegate_in del)
{
  del->dst_RequiredRequestPortEnd ()->accept (this);
}

//
// visit_RequiredRequestPortDelegate
//
void Connection_Visitor::
visit_RequiredRequestPortDelegate (RequiredRequestPortDelegate_in facet)
{
  for (Invoke invoke : facet->src_of_Invoke ())
    invoke->accept (this);
}

//
// visit_FacetDelegate
//
void Connection_Visitor::
visit_FacetDelegate (FacetDelegate_in del)
{
  del->dst_ProvidedRequestPortEnd ()->accept (this);
}

//
// visit_ProvidedRequestPortDelegate
//
void Connection_Visitor::
visit_ProvidedRequestPortDelegate (ProvidedRequestPortDelegate_in facet)
{
  for (FacetDelegate item : facet->dst_of_FacetDelegate ())
    item->accept (this);
}

//
// visit_EventSourceDelegate
//
void Connection_Visitor::
visit_EventSourceDelegate (EventSourceDelegate_in del)
{
  del->src_OutEventPortEnd ()->accept (this);
}

//
// visit_OutEventPortDelegate
//
void Connection_Visitor::
visit_OutEventPortDelegate (OutEventPortDelegate_in facet)
{
  for (SendsTo item : facet->src_of_SendsTo ())
    item->accept (this);
}

//
// visit_EventSinkDelegate
//
void Connection_Visitor::
visit_EventSinkDelegate (EventSinkDelegate_in del)
{
  del->dst_InEventPortEnd ()->accept (this);
}

//
// visit_InEventPortDelegate
//
void Connection_Visitor::
visit_InEventPortDelegate (InEventPortDelegate_in facet)
{
  for (EventSinkDelegate sink : facet->src_of_EventSinkDelegate ())
    sink->accept (this);
}

//
// create_connection
//
void Connection_Visitor::
create_connection (const std::string & name, 
                   GAME::Xml::Fragment ep1, 
                   GAME::Xml::Fragment ep2,
                   bool is_local)
{
  // Create the new connection.
  GAME::Xml::Fragment conn = this->document_.create_element ("connection");
  conn.create_simple_content ("name", name);

  if (is_local)
    this->make_local_connection (conn);

  // Add its endpoints.
  conn->appendChild (ep1);
  conn->appendChild (ep2);

  // Save the connection.
  this->conns_.push_back (conn);
}

//
// make_local_connection
//
void Connection_Visitor::make_local_connection (GAME::Xml::Fragment conn)
{
  GAME::Xml::Fragment deployRequirement = conn.create_element ("deployRequirement");
  deployRequirement.create_simple_content ("name", "edu.dre.vanderbilt.DAnCE.ConnectionType");
  deployRequirement.create_simple_content ("resourceType", "Local_Interface");
}

}
}
