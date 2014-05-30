// $Id$ change only for test new branch

#include "Connection_Visitor.h"
#include "game/xml/String.h"

#include "Utils/udm/visit.h"
#include "boost/bind.hpp"
#include <algorithm>

using GAME::Xml::String;

//
// Connection_Visitor
//
Connection_Visitor::
Connection_Visitor (xercesc::DOMDocument * doc,
                    std::vector <xercesc::DOMElement *> & conns,
                    const std::map <PICML::ComponentInstance, xercesc::DOMElement *> & insts)
: doc_ (doc),
  conns_ (conns),
  insts_ (insts),
  endpoint_ (0)
{

}

//
// ~Connection_Visitor
//
Connection_Visitor::~Connection_Visitor (void)
{

}

//
//
//
void Connection_Visitor::
Visit_ComponentInstance (const PICML::ComponentInstance & inst)
{
  std::string s = inst.name ();

  // Visit the event sources.
  CoSMIC::Udm::visit_all <PICML::OutEventPortInstance> (inst, *this);

  // Visit all the receptacles.
  CoSMIC::Udm::visit_all <PICML::RequiredRequestPortInstance> (inst, *this);
}

//
// Visit_OutEventPort
//
void Connection_Visitor::
Visit_OutEventPortInstance (const PICML::OutEventPortInstance & source)
{
  PICML::ComponentInstance inst = source.ComponentInstance_parent ();
  const std::string uuid = std::string ("_") + std::string (inst.UUID ());
  PICML::OutEventPort port = source.ref ();
  const char * kind = port.single_destination () ? "EventEmitter" : "EventPublisher";

  // The endpoint of this connection is part of a deployed
  // instance. We therefore need to create an XML endpoint.
  this->endpoint_ = this->doc_->createElement (String ("internalEndpoint"));
  this->create_simple_content (this->endpoint_, "portName", source.name ());
  this->create_simple_content (this->endpoint_, "provider", "false");
  this->create_simple_content (this->endpoint_, "kind", kind);

  xercesc::DOMElement * ele = this->create_simple_content (this->endpoint_, "instance", "");
  ele->setAttribute (String ("xmi:idref"), String (uuid));

  this->name_ = source.getPath (".", false, true, "name", true);

  std::set <PICML::SendsTo> sends = source.dstSendsTo ();
  for(auto &send :sends)
	  send.Accept(*this);

  // Lastly, visit the delegation connections.
  std::set <PICML::EventSourceDelegate>
    delegates = source.dstEventSourceDelegate ();
  for(auto &delegate :delegates)
	  delegate.Accept(*this);

  // We can release this endpoint now.
  this->endpoint_->release ();
  this->endpoint_ = 0;
}

//
// Visit_RequiredRequestPort
//
void Connection_Visitor::
Visit_RequiredRequestPortInstance (const PICML::RequiredRequestPortInstance & receptacle)
{
  PICML::ComponentInstance inst = receptacle.ComponentInstance_parent ();
  const std::string uuid = std::string ("_") + std::string (inst.UUID ());

  PICML::RequiredRequestPort port = receptacle.ref ();
  const char * kind = port.multiple_connections () ? "MultiplexReceptacle" : "SimplexReceptacle";

  // The endpoint of this connection is part of a deployed
  // instance. We therefore need to create an XML endpoint.
  this->endpoint_ = this->doc_->createElement (String ("internalEndpoint"));
  this->create_simple_content (this->endpoint_, "portName", receptacle.name ());
  this->create_simple_content (this->endpoint_, "provider", "false");
  this->create_simple_content (this->endpoint_, "kind", kind);

  xercesc::DOMElement * ele = this->create_simple_content (this->endpoint_, "instance", "");
  ele->setAttribute (String ("xmi:idref"), String (uuid));

  this->name_ = receptacle.getPath (".", false, true, "name", true);

  // Visit all the connections.
  std::set <PICML::Invoke> invokes = receptacle.dstinvoke ();
  for(auto &invoke :invokes)
	  invoke.Accept(*this);

  // Lastly, visit the delegation connections.
  std::set <PICML::ReceptacleDelegate>
    delegates = receptacle.srcReceptacleDelegate ();
  for(auto &delegate :delegates)
	  delegate.Accept(*this);

  // We can release this endpoint now.
  this->endpoint_->release ();
  this->endpoint_ = 0;
}

//
// Visit_SendsTo
//
void Connection_Visitor::Visit_SendsTo (const PICML::SendsTo & sends)
{
  PICML::InEventPortEnd sink = sends.dstSendsTo_end ();
  Uml::Class type = sink.type ();

  if (type == PICML::InEventPortInstance::meta)
    PICML::InEventPortInstance::Cast (sink).Accept (*this);
  else if (type == PICML::InEventPortDelegate::meta)
    PICML::InEventPortDelegate::Cast (sink).Accept (*this);
}

//
// Visit_Invoke
//
void Connection_Visitor::Visit_Invoke (const PICML::Invoke & i)
{
  PICML::ProvidedRequestPortEnd port = i.dstinvoke_end ();
  const Uml::Class & type = port.type ();

  if (type == PICML::ProvidedRequestPortInstance::meta)
    PICML::ProvidedRequestPortInstance::Cast (port).Accept (*this);
  else if (type == PICML::SupportsInstance::meta)
    PICML::SupportsInstance::Cast (port).Accept (*this);
  else if (type == PICML::ProvidedRequestPortDelegate::meta)
    PICML::ProvidedRequestPortDelegate::Cast (port).Accept (*this);
}

//
// Visit_InEventPortInstance
//
void Connection_Visitor::
Visit_InEventPortInstance (const PICML::InEventPortInstance & sink)
{
  PICML::ComponentInstance inst = sink.ComponentInstance_parent ();

  if (this->insts_.find (inst) == this->insts_.end ())
    return;

  const std::string uuid = std::string ("_") + std::string (inst.UUID ());
  PICML::InEventPort port = sink.ref ();

  // Create the template endpoint for these connections.
  xercesc::DOMElement * endpoint = this->doc_->createElement (String ("internalEndpoint"));
  this->create_simple_content (endpoint, "portName", port.name ());
  this->create_simple_content (endpoint, "provider", "true");
  this->create_simple_content (endpoint, "kind", "EventConsumer");

  xercesc::DOMElement * ele = this->create_simple_content (endpoint, "instance", "");
  ele->setAttribute (String ("xmi:idref"), String (uuid));

  // Finally, create final connection between the two endpoints.
  std::string connection_name = this->name_;
  connection_name.append ("::");
  connection_name.append (sink.getPath (".", false, true, "name", true));

  this->create_connection (connection_name,
                           this->endpoint_->cloneNode (true),
                           endpoint,
                           false);
}

//
// Visit_ProvidedRequestPort
//
void Connection_Visitor::
Visit_ProvidedRequestPortInstance (const PICML::ProvidedRequestPortInstance & facet)
{
  PICML::ComponentInstance inst = facet.ComponentInstance_parent ();

  if (this->insts_.find (inst) == this->insts_.end ())
    return;

  const std::string uuid = std::string ("_") + std::string (inst.UUID ());

  // Create the endpoint for this port.
  xercesc::DOMElement * endpoint = this->doc_->createElement (String ("internalEndpoint"));
  this->create_simple_content (endpoint, "portName", facet.name ());
  this->create_simple_content (endpoint, "provider", "true");
  this->create_simple_content (endpoint, "kind", "Facet");

  xercesc::DOMElement * ele = this->create_simple_content (endpoint, "instance", "");
  ele->setAttribute (String ("xmi:idref"), String (uuid));

  std::string connection_name = this->name_;
  connection_name.append ("::");
  connection_name.append (facet.getPath (".", false, true, "name", true));

  // Determine if this is a local connection.
  PICML::ProvidedRequestPort port = facet.ref ();
  PICML::Object obj = PICML::Object::Cast (port.ref ());
  const std::string semantics (obj.InterfaceSemantics ());
  bool is_local = semantics == "local" ? true : false;

  // Finally, create final connection between the two endpoints.
  this->create_connection (connection_name,
                           this->endpoint_->cloneNode (true),
                           endpoint,
                           is_local);
}

//
// Visit_ReceptacleDelegate
//
void Connection_Visitor::
Visit_ReceptacleDelegate (const PICML::ReceptacleDelegate & del)
{
  PICML::RequiredRequestPortEnd port = del.srcReceptacleDelegate_end ();
  const Uml::Class & type = port.type ();

  if (type == PICML::RequiredRequestPortInstance::meta)
    PICML::RequiredRequestPortInstance::Cast (port).Accept (*this);
  else if (type == PICML::RequiredRequestPortDelegate::meta)
    PICML::RequiredRequestPortDelegate::Cast (port).Accept (*this);
}

//
// Visit_RequiredRequestPortDelegate
//
void Connection_Visitor::
Visit_RequiredRequestPortDelegate (const PICML::RequiredRequestPortDelegate & facet)
{
  std::set <PICML::Invoke> invokes = facet.dstinvoke ();
  for(auto &invoke :invokes)
	  invoke.Accept(*this);
}

//
// Visit_FacetDelegate
//
void Connection_Visitor::
Visit_FacetDelegate (const PICML::FacetDelegate & del)
{
  PICML::ProvidedRequestPortEnd port = del.dstFacetDelegate_end ();
  const Uml::Class & type = port.type ();

  if (type == PICML::ProvidedRequestPortInstance::meta)
    PICML::ProvidedRequestPortInstance::Cast (port).Accept (*this);
  else if (type == PICML::SupportsInstance::meta)
    PICML::SupportsInstance::Cast (port).Accept (*this);
  else if (type == PICML::ProvidedRequestPortDelegate::meta)
    PICML::ProvidedRequestPortDelegate::Cast (port).Accept (*this);
}

//
// Visit_ProvidedRequestPortDelegate
//
void Connection_Visitor::
Visit_ProvidedRequestPortDelegate (const PICML::ProvidedRequestPortDelegate & facet)
{
  std::set <PICML::FacetDelegate> delegates = facet.dstFacetDelegate ();
  for(auto &delegate :delegates)
	  delegate.Accept(*this);
}

//
// Visit_EventSourceDelegate
//
void Connection_Visitor::
Visit_EventSourceDelegate (const PICML::EventSourceDelegate & del)
{
  PICML::OutEventPortEnd port = del.dstEventSourceDelegate_end ();
  const Uml::Class & type = port.type ();

  if (type == PICML::OutEventPortInstance::meta)
    PICML::OutEventPortInstance::Cast (port).Accept (*this);
  else if (type == PICML::OutEventPortDelegate::meta)
    PICML::OutEventPortDelegate::Cast (port).Accept (*this);
}

//
// Visit_OutEventPortDelegate
//
void Connection_Visitor::
Visit_OutEventPortDelegate (const PICML::OutEventPortDelegate & facet)
{
  std::set <PICML::SendsTo> sends = facet.dstSendsTo();
  for(auto &send :sends)
	  send.Accept(*this);

}

//
// Visit_EventSinkDelegate
//
void Connection_Visitor::
Visit_EventSinkDelegate (const PICML::EventSinkDelegate & del)
{
  PICML::InEventPortEnd port = del.dstEventSinkDelegate_end ();
  const Uml::Class & type = port.type ();

  if (type == PICML::InEventPortInstance::meta)
    PICML::InEventPortInstance::Cast (port).Accept (*this);
  else if (type == PICML::InEventPortDelegate::meta)
    PICML::InEventPortDelegate::Cast (port).Accept (*this);
}

//
// Visit_InEventPortDelegate
//
void Connection_Visitor::
Visit_InEventPortDelegate (const PICML::InEventPortDelegate & facet)
{
  std::set <PICML::EventSinkDelegate> delegates = facet.dstEventSinkDelegate ();
  for(auto &delegate :delegates)
	  delegate.Accept(*this);
 
}

//
// create_connection
//
void Connection_Visitor::
create_connection (const std::string & name,
                   xercesc::DOMNode * ep1,
                   xercesc::DOMNode * ep2,
                   bool is_local)
{
  // Create the new connection.
  xercesc::DOMElement * conn = this->doc_->createElement (String ("connection"));
  this->create_simple_content (conn, "name", name);

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
void Connection_Visitor::make_local_connection (xercesc::DOMElement * conn)
{
  xercesc::DOMElement * deployRequirement = this->create_element (conn, "deployRequirement");
  this->create_simple_content (deployRequirement, "name", "edu.dre.vanderbilt.DAnCE.ConnectionType");
  this->create_simple_content (deployRequirement, "resourceType", "Local_Interface");
}
