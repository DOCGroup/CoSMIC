// $Id$

#include "Connection_Visitor.h"
#include "Utils/xercesc/XercesString.h"
#include "boost/bind.hpp"
#include <algorithm>

//
// Connection_Visitor
//
Connection_Visitor::
Connection_Visitor (xercesc::DOMDocument * doc,
                    const std::map <PICML::ComponentInstance, xercesc::DOMElement *> & insts)
: doc_ (doc),
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
  // Visit the event sources.
  std::vector <PICML::OutEventPort> sources = inst.OutEventPort_kind_children ();
  std::for_each (sources.begin (),
                 sources.end (),
                 boost::bind (&PICML::OutEventPort::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit the receptacles.
  std::vector <PICML::RequiredRequestPort> receptacles = inst.RequiredRequestPort_kind_children ();
  std::for_each (receptacles.begin (),
                 receptacles.end (),
                 boost::bind (&PICML::RequiredRequestPort::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_OutEventPort
//
void Connection_Visitor::
Visit_OutEventPort (const PICML::OutEventPort & source)
{
  PICML::ComponentInstance inst = source.ComponentInstance_parent ();
  const std::string uuid = std::string ("_") + std::string (inst.UUID ());
  const char * kind = source.single_destination () ? "EventEmitter" : "EventPublisher";

  // The endpoint of this connection is part of a deployed
  // instance. We therefore need to create an XML endpoint.
  this->endpoint_ = this->doc_->createElement (Utils::XStr ("internalEndpoint"));
  this->create_simple_content (this->endpoint_, "portName", source.name ());
  this->create_simple_content (this->endpoint_, "provider", "false");
  this->create_simple_content (this->endpoint_, "kind", kind);

  xercesc::DOMElement * ele = this->create_simple_content (this->endpoint_, "instance", "");
  ele->setAttribute (Utils::XStr ("xmi:idref"), Utils::XStr (uuid)); 

  this->name_ = source.getPath (".", false, true, "name", true);

  std::set <PICML::sendsTo> sends = source.dstsendsTo ();
  std::for_each (sends.begin (),
                 sends.end (),
                 boost::bind (&PICML::sendsTo::Accept,
                              _1,
                              boost::ref (*this)));

  // We can release this endpoint now.
  this->endpoint_->release ();
  this->endpoint_ = 0;  
}

//
// Visit_RequiredRequestPort
//
void Connection_Visitor::
Visit_RequiredRequestPort (const PICML::RequiredRequestPort & receptacle)
{
  PICML::ComponentInstance inst = receptacle.ComponentInstance_parent ();
  const std::string uuid = std::string ("_") + std::string (inst.UUID ());
  const char * kind = receptacle.multiple_connections () ? "MultiplexReceptacle" : "SimplexReceptacle";

  // The endpoint of this connection is part of a deployed
  // instance. We therefore need to create an XML endpoint.
  this->endpoint_ = this->doc_->createElement (Utils::XStr ("internalEndpoint"));
  this->create_simple_content (this->endpoint_, "portName", receptacle.name ());
  this->create_simple_content (this->endpoint_, "provider", "false");
  this->create_simple_content (this->endpoint_, "kind", kind);

  xercesc::DOMElement * ele = this->create_simple_content (this->endpoint_, "instance", "");
  ele->setAttribute (Utils::XStr ("xmi:idref"), Utils::XStr (inst.UUID ())); 

  this->name_ = receptacle.getPath (".", false, true, "name", true);

  // Visit all the connections.
  std::set <PICML::invoke> invokes = receptacle.dstinvoke ();

  std::for_each (invokes.begin (),
                 invokes.end (),
                 boost::bind (&PICML::invoke::Accept,
                              _1,
                              boost::ref (*this)));

  // We can release this endpoint now.
  this->endpoint_->release ();
  this->endpoint_ = 0;  
}

//
// Visit_sendsTo
//
void Connection_Visitor::Visit_sendsTo (const PICML::sendsTo & sends)
{
  PICML::InEventPort sink = sends.dstsendsTo_end ();
  sink.Accept (*this);
}

//
// Visit_invoke
//
void Connection_Visitor::Visit_invoke (const PICML::invoke & i)
{
  PICML::InvokePortBase base = i.dstinvoke_end ();
  const Uml::Class & type = base.type ();

  if (type == PICML::ProvidedRequestPort::meta)
    PICML::ProvidedRequestPort::Cast (base).Accept (*this);
  else if (type == PICML::Supports::meta)
    PICML::Supports::Cast (base).Accept (*this);
}

//
// Visit_InEventPort
//
void Connection_Visitor::
Visit_InEventPort (const PICML::InEventPort & sink)
{
  PICML::ComponentInstance inst = sink.ComponentInstance_parent ();

  if (this->insts_.find (inst) != this->insts_.end ())
  {
    const std::string uuid = std::string ("_") + std::string (inst.UUID ());

    // Create the template endpoint for these connections.
    xercesc::DOMElement * endpoint = this->doc_->createElement (Utils::XStr ("internalEndpoint"));
    this->create_simple_content (endpoint, "portName", sink.name ());
    this->create_simple_content (endpoint, "provider", "true");
    this->create_simple_content (endpoint, "kind", "EventConsumer");

    xercesc::DOMElement * ele = this->create_simple_content (endpoint, "instance", "");
    ele->setAttribute (Utils::XStr ("xmi:idref"), Utils::XStr (uuid)); 

    // Finally, create final connection between the two endpoints.
    std::string connection_name = this->name_;
    connection_name.append ("::");
    connection_name.append (sink.getPath (".", false, true, "name", true));

    this->create_connection (connection_name, 
                             this->endpoint_->cloneNode (true),
                             endpoint);
  }

}

//
// Visit_ProvidedRequestPort
//
void Connection_Visitor::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & facet)
{
  PICML::ComponentInstance inst = facet.ComponentInstance_parent ();

  if (this->insts_.find (inst) != this->insts_.end ())
  {
    const std::string uuid = std::string ("_") + std::string (inst.UUID ());

    // Create the endpoint for this port.
    xercesc::DOMElement * endpoint = this->doc_->createElement (Utils::XStr ("internalEndpoint"));
    this->create_simple_content (endpoint, "portName", facet.name ());
    this->create_simple_content (endpoint, "provider", "true");
    this->create_simple_content (endpoint, "kind", "Facet");

    PICML::ComponentInstance inst = facet.ComponentInstance_parent ();
    xercesc::DOMElement * ele = this->create_simple_content (endpoint, "instance", "");
    ele->setAttribute (Utils::XStr ("xmi:idref"), Utils::XStr (uuid)); 

    // Finally, create final connection between the two endpoints.
    std::string connection_name = this->name_;
    connection_name.append ("::");
    connection_name.append (facet.getPath (".", false, true, "name", true));

    this->create_connection (connection_name, 
                             this->endpoint_->cloneNode (true),
                             endpoint);
  }
}

//
// create_connection
//
void Connection_Visitor::
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

//
// connections
//
const std::vector <xercesc::DOMElement *> & 
Connection_Visitor::connections (void) const
{
  return this->conns_;
}
