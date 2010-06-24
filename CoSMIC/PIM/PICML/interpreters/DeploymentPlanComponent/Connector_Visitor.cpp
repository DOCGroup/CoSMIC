// $Id$

#include "Connector_Visitor.h"
#include "DeploymentPlanVisitor.h"

#include "Utils/xercesc/XercesString.h"
#include "Utils/udm/visit.h"
#include "Utils/Utils.h"

//
// Connector_Visitor
//
Connector_Visitor::
Connector_Visitor (DeploymentPlanVisitor & v, xercesc::DOMDocument * doc)
: dpv_ (v),
  doc_ (doc),
  curr_conn_ (0)
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
  this->comp_inst_ = inst;

  // Locate the plan locality for this instance.
  this->find_plan_locality (inst);

  // Visit the extended ports.
  Udm::visit_all <PICML::ExtendedPortInstance> (inst, *this);
  Udm::visit_all <PICML::MirrorPortInstance> (inst, *this);

  // Visit the standard ports.
  Udm::visit_all <PICML::RequiredRequestPortInstance> (inst, *this);
  Udm::visit_all <PICML::ProvidedRequestPortInstance> (inst, *this);
}

//
// find_plan_locality
//
bool Connector_Visitor::
find_plan_locality (const PICML::ComponentInstance & inst)
{
  std::set <PICML::ComponentInstanceRef> refers = inst.referedbyComponentInstanceRef ();

  std::set <PICML::ComponentInstanceRef>::
    iterator iter = refers.begin (), iter_end = refers.end ();

  for (; iter != iter_end; ++ iter)
  {
    // This reference can be in either 0 or 1 collocation groups. We do
    // not allow a component to appear in more than on collocation group.
    std::set <PICML::CollocationGroup> groups = iter->setCollocationGroup ();

    // Find the group that contains this reference.
    std::set <PICML::CollocationGroup>::iterator
      group_iter = groups.begin (), group_iter_end = groups.end ();

    for (; group_iter != group_iter_end; ++ group_iter)
    {
      typedef DeploymentPlanVisitor::locality_t locality_t;
      PICML::CollocationGroup group = *group_iter;

      locality_t::const_iterator local = this->dpv_.localities ().find (group);

      if (local != this->dpv_.localities ().end ())
      {
        this->group_ = group;
        return true;
      }
    }
  }

  this->group_ = PICML::CollocationGroup ();
  return false;
}

//
// Visit_ExtendedPort
//
void Connector_Visitor::
Visit_ExtendedPortInstance (const PICML::ExtendedPortInstance & port)
{
  // Save the prefix for the ports.
  PICML::ExtendedPort ep = port.ref ();
  this->prefix1_ = ep.name ();
  PICML::PortType pt = ep.ref ();

  // Check if this port type is sending anything to a connector.
  PICML::Publish publish = port.dstPublish ();

  if (publish != Udm::null)
  {
    // Get name of target port, and its connector instance.
    publish.Accept (*this);

    // Now, flatten out the port type.
    this->invert_ = false;
    pt.Accept (*this);
  }

  // We also need to see if this port type is receiving anything 
  // from a connector.
  PICML::Consume consume = port.srcConsume ();

  if (consume != Udm::null)
  {
    // Get name of target port, and its connector instance.
    consume.Accept (*this);

    // Now, flatten out the port type.
    this->invert_ = false;
    pt.Accept (*this);
  }
}

//
// Visit_MirrorPortInstance
//
void Connector_Visitor::
Visit_MirrorPortInstance (const PICML::MirrorPortInstance & port)
{
  PICML::MirrorPort mp = port.ref ();
  this->prefix1_ = mp.name ();
  PICML::PortType pt = mp.ref ();

  // Check if this port type is sending anything to a connector.
  PICML::Publish publish = port.dstPublish ();

  if (publish != Udm::null)
  {
    // Find the target connector.
    publish.Accept (*this);

    // Write all the connections.
    this->invert_ = true;
    pt.Accept (*this);
  }

  PICML::Consume consume = port.srcConsume ();

  if (consume != Udm::null)
  {
    // Find the target connector.
    consume.Accept (*this);

    // Write all the connections.
    this->invert_ = true;
    pt.Accept (*this);
  }
}

//
// Visit_Publish
//
void Connector_Visitor::Visit_Publish (const PICML::Publish & publish)
{
  // Store the name of this connection as the target port.
  this->prefix2_ = publish.name ();

  // Make sure to include this instance in deployment plan.
  PICML::ConnectorInstance inst = publish.dstPublish_end ();
  this->conn_path_ += inst.getPath (".", false, true, "name", true);

  // First, let's check if this connector fragment already exists
  // in the current collocation group.
  std::set <fragment_t> & fragments = this->fragments_[this->group_];
  std::set <fragment_t>::iterator iter = fragments.find (fragment_t (inst, ""));

  if (iter == fragments.end ())
  {
    // Generate a new UUID for this connector fragment.
    std::string target_uuid = Utils::CreateUuid ();
    std::string old_uuid = inst.UUID ();

    inst.UUID () = target_uuid;
    this->conn_uuid_ = "_" + target_uuid;

    // Save the fragment for later usage.
    fragments.insert (fragment_t (inst, target_uuid));

    // Since this is a new fragment, we need to make sure that it
    // is included in the deployment plan.
    this->dpv_.deploy_connector_instance (inst, this->group_);

    // Restore the original UUID.
    inst.UUID () = old_uuid;
  }
  else
  {
    this->conn_uuid_ = "_" + iter->uuid_;
  }
}

//
// Visit_Publish
//
void Connector_Visitor::Visit_Consume (const PICML::Consume & consume)
{
  // Store the name of this connection as the target port.
  this->prefix2_ = consume.name ();

  // Make sure to include this instance in deployment plan.
  PICML::ConnectorInstance inst = consume.srcConsume_end ();
  this->conn_path_ += inst.getPath (".", false, true, "name", true);

  // Generate a new UUID for this connector fragment.
  std::string new_uuid = Utils::CreateUuid ();
  std::string old_uuid = inst.UUID ();

  inst.UUID () = new_uuid;
  this->conn_uuid_ = "_" + new_uuid;

  this->dpv_.deploy_connector_instance (inst, this->group_); ;

  // Restore the original UUID.
  inst.UUID () = old_uuid;
}

//
// Visit_PortType
//
void Connector_Visitor::Visit_PortType (const PICML::PortType & pt)
{
  Udm::visit_all <PICML::RequiredRequestPort> (pt, *this);
  Udm::visit_all <PICML::ProvidedRequestPort> (pt, *this);
}

//
// Visit_RequiredRequestPort
//
void Connector_Visitor::
Visit_RequiredRequestPort (const PICML::RequiredRequestPort & p)
{
  PICML::Object obj (PICML::Object::Cast (p.ref ()));
  this->start_new_connection (obj);

  std::string uuid = "_" + std::string (this->comp_inst_.UUID ()); 
  this->Visit_RequiredRequestPort_i (uuid,
                                     this->prefix1_, 
                                     p, 
                                     this->portname1_,
                                     this->invert_);

  this->conn_name_ += "::" + this->conn_path_;

  this->Visit_RequiredRequestPort_i (this->conn_uuid_,
                                     this->prefix2_, 
                                     p, 
                                     this->portname2_,
                                     !this->invert_);

  this->end_connection ();
}

//
// Visit_ProvidedRequestPort
//
void Connector_Visitor::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & p)
{
  PICML::Object obj = PICML::Object::Cast (p.ref ());
  this->start_new_connection (obj);

  std::string uuid = "_" + std::string (this->comp_inst_.UUID ());
  this->Visit_ProvidedRequestPort_i (uuid,
                                     this->prefix1_, 
                                     p,
                                     this->portname1_,
                                     this->invert_);

  this->conn_name_ += "::" + this->conn_path_;

  this->Visit_ProvidedRequestPort_i (this->conn_uuid_,
                                     this->prefix2_,
                                     p, 
                                     this->portname2_,
                                     !this->invert_);

  this->end_connection ();
}

//
// Visit_RequiredRequestPort
//
void Connector_Visitor::
Visit_RequiredRequestPort_i (const std::string & inst,
                             const std::string & prefix, 
                             const PICML::RequiredRequestPort & p,
                             std::string & portname,
                             bool invert)
{
  portname = prefix + "_" + std::string (p.name ());
  const char * kind = invert ? "Facet" : "SimplexReceptacle";
  const char * provider = invert ? "true" : "false";

  this->append_endpoint (portname, kind, provider, inst);
}

//
// Visit_ProvidedRequestPort_i
//
void Connector_Visitor::
Visit_ProvidedRequestPort_i (const std::string & inst,
                             const std::string & prefix,
                             const PICML::ProvidedRequestPort & p,
                             std::string & portname,
                             bool invert)
{
  portname = prefix + "_" + std::string (p.name ());

  const char * kind = invert ? "SimplexReceptacle" : "Facet";
  const char * provider = invert ? "false" : "true";

  this->append_endpoint (portname, kind, provider, inst);
}

//
// start_new_connection
//
void Connector_Visitor::
start_new_connection (const PICML::Object & obj)
{
  using xercesc::DOMElement;

  this->curr_conn_ = this->doc_->createElement (L"connection");
  this->name_element_ = this->create_element (this->curr_conn_, "name");
  this->conn_name_ = this->comp_inst_.getPath (".", false, true, "name", true);

  // Determine if the interface is local. If this is the case, then we
  // need to generate a special tag for such object.
  const std::string semantics (obj.InterfaceSemantics ());

  if (semantics == "local")
    this->make_connection_local (this->curr_conn_);
}

//
// append_endpoint
//
void Connector_Visitor::
append_endpoint (const std::string & portname,
                 const std::string & kind,
                 const std::string & provider,
                 const std::string & inst)
{
  using xercesc::DOMElement;

  // Add the portname to the connection name.
  this->conn_name_ += "." + portname;

  DOMElement * ep = this->create_element (this->curr_conn_, "internalEndpoint");
  this->create_simple_content (ep, "portName", portname);
  this->create_simple_content (ep, "provider", provider);
  this->create_simple_content (ep, "kind", kind);

  DOMElement * instance = this->create_element (ep, "instance");
  instance->setAttribute (L"xmi:idref", ::Utils::XStr (inst));
}

//
// end_connection
//
void Connector_Visitor::end_connection (void)
{
  this->name_element_->setTextContent (::Utils::XStr (this->conn_name_));
  this->conns_.push_back (this->curr_conn_);
}

//
// connections
//
const std::vector <xercesc::DOMElement *> & Connector_Visitor::connections (void) const
{
  return this->conns_;
}

//
// make_connection_local
//
void Connector_Visitor::
make_connection_local (xercesc::DOMElement * conn)
{
  xercesc::DOMElement * deployRequirement = this->create_element (conn, "deployRequirement");
  this->create_simple_content (deployRequirement, "name", "edu.dre.vanderbilt.DAnCE.ConnectionType");
  this->create_simple_content (deployRequirement, "resourceType", "Local_Interface");
}
