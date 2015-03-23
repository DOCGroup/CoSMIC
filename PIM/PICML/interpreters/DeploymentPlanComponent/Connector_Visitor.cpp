#include "StdAfx.h"
#include "Connector_Visitor.h"

#include "PIM/PICML/ext/PICML/PICML.h"
#include "PIM/PICML/ext/PICML/Visitor.h"

#include "game/xml/String.h"
#include "game/mga/Utils.h"

#include <sstream>
#include <set>

namespace PICML
{
namespace Deployment
{

using GAME::Xml::Fragment;
using GAME::Xml::String;


/**
 * @class ProvidedRequestPortInstance_Collector
 */
class ProvidedRequestPortInstance_Collector : public Visitor
{
public:
  ProvidedRequestPortInstance_Collector (std::set <ProvidedRequestPortInstance> & ports)
    : ports_ (ports)
  {

  }

  virtual ~ProvidedRequestPortInstance_Collector (void)
  {

  }

  void Visit_ConnectorToFacet (ConnectorToFacet_in ctf)
  {
    ctf->dst_ProvidedRequestPortEnd ()->accept (this);
  }

  void Visit_ProvidedRequestPortDelegate (ProvidedRequestPortDelegate_in inst)
  {
    for (FacetDelegate item  : inst->src_of_FacetDelegate ())
      item->accept (this);
  }

  void Visit_FacetDelegate (FacetDelegate_in fd)
  {
    fd->dst_ProvidedRequestPortEnd ()->accept (this);
  }

  void visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in inst)
  {
    this->ports_.insert (inst);
  }

private:
  std::set <ProvidedRequestPortInstance> & ports_;
};

///////////////////////////////////////////////////////////////////////////////
// Connector_Visitor

Connector_Visitor::
Connector_Visitor (Deployment_Handler * handler, 
                   GAME::Xml::Document document,
                   std::vector <GAME::Xml::Fragment> & conns)
: handler_ (handler),
  document_ (document),
  conns_ (conns)
{

}

Connector_Visitor::~Connector_Visitor (void)
{

}

void Connector_Visitor::Visit_ComponentInstance (ComponentInstance_in inst)
{
  // Save the component instance since this is needed to deploy
  // connector fragments to the document.
  this->comp_inst_ = inst;

  // Visit the extended ports.
  for (ExtendedPortInstance port : inst->get_ExtendedPortInstances ())
    port->accept (this);

  for (MirrorPortInstance port : inst->get_MirrorPortInstances ())
    port->accept (this);

  // Visit the standard ports.
  for (RequiredRequestPortInstance port : inst->get_RequiredRequestPortInstances ())
    port->accept (this);

  for (ProvidedRequestPortInstance port : inst->get_ProvidedRequestPortInstances ())
    port->accept (this);

  // Clear the map of connector uuids.
  if (!this->connector_uuid_.empty ())
    this->connector_uuids_.clear ();
}

void Connector_Visitor::
Visit_ExtendedPortInstance (ExtendedPortInstance_in port)
{
  // Save the prefix for the ports.
  ExtendedPort ep = port->refers_to_ExtendedPort ();
  PortType pt = ep->refers_to_PortType ();

  this->prefix1_ = ep->name ();
  this->Visit_ExtendedPortInstanceBase (port, pt);
}

void Connector_Visitor::
Visit_ExtendedPortInstanceBase (ExtendedPortInstanceBase_in base, PortType_in pt)
{
  // Vist the publish connection for this port if it exist.
  Publish publish = base->src_of_Publish ();

  if (publish)
  {
    // Get name of target port, and its connector instance.
    publish->accept (this);

    // Now, flatten out the port type.
    this->invert_ = false;
    pt->accept (this);
  }

  // We also need to see if this port type is receiving anything
  // from a connector.
  Consume consume = base->dst_of_Consume ();

  if (consume)
  {
    // Get name of target port, and its connector instance.
    consume->accept (this);

    // Now, flatten out the port type.
    this->invert_ = false;
    pt->accept (this);
  }

  // Finally, check if this port is part of a delegation. If so,
  // we need to locate the non-delegated port for this port.
  ExtendedDelegate ed = base->src_of_ExtendedDelegate ();

  if (!ed.is_nil ())
  {
    ExtendedPortDelegate epd = ed->dst_ExtendedPortDelegate ();
    this->Visit_ExtendedPortInstanceBase (epd, pt);
  }
}

void Connector_Visitor::
Visit_MirrorPortInstance (MirrorPortInstance_in port)
{
  MirrorPort mp = port->refers_to_MirrorPort ();
  PortType pt = mp->refers_to_PortType ();

  this->prefix1_ = mp->name ();
  this->Visit_MirrorPortInstanceBase (port, pt);
}

void Connector_Visitor::
Visit_MirrorPortInstanceBase (MirrorPortInstanceBase_in base, PortType_in pt)
{
  // Vist the publish connection for this port if it exist.
  Publish publish = base->src_of_Publish ();
  publish->accept (this);

  // Write all the connections.
  this->invert_ = true;
  pt->accept (this);

  // We also need to see if this port type is receiving anything
  // from a connector.
  Consume consume = base->dst_of_Consume ();
  consume->accept (this);

  // Write all the connections.
  this->invert_ = true;
  pt->accept (this);

  // Finally, check if this port is part of a delegation. If so,
  // we need to locate the non-delegated port for this port.
  MirrorDelegate md = base->src_of_MirrorDelegate ();

  if (!md.is_nil ())
  {
    MirrorPortDelegate mpd = md->dst_MirrorPortDelegate ();
    this->Visit_MirrorPortInstanceBase (mpd, pt);
  }
}

void Connector_Visitor::
Visit_RequiredRequestPortInstance (RequiredRequestPortInstance_in inst)
{
  // The prefix is not included since the name of the port is
  // only thing that matters with this type of connection.
  this->receptacle_ = inst->refers_to_RequiredRequestPort ();
  this->prefix1_.clear ();

  this->active_receptacle_ = inst;
  this->Visit_RequiredRequestPortEnd (inst);
}

void Connector_Visitor::
Visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in inst)
{
  // The prefix is not included since the name of the port is
  // only thing that matters with this type of connection.
  this->facet_ = inst->refers_to_ProvidedRequestPort ();
  this->prefix1_.clear ();

  this->active_facet_ = inst;
  this->Visit_ProvidedRequestPortEnd (inst);
}

void Connector_Visitor::
Visit_ReceptacleDelegate (ReceptacleDelegate_in rd)
{
  RequiredRequestPortEnd rrpe = rd->src_RequiredRequestPortDelegate ();
  this->Visit_RequiredRequestPortEnd (rrpe);
}

void Connector_Visitor::
Visit_FacetDelegate (FacetDelegate_in fd)
{
  ProvidedRequestPortDelegate prpd = fd->src_ProvidedRequestPortDelegate ();
  const std::string n (prpd->name ());

  this->Visit_ProvidedRequestPortEnd (prpd);
}

void Connector_Visitor::
Visit_RequiredRequestPortEnd (RequiredRequestPortEnd_in end)
{
  for (ConnectorToReceptacle connection : end->src_of_ConnectorToReceptacle ())
    connection->accept (this);

  // We need to visit the receptacle delegates.
  for (ReceptacleDelegate connection : end->dst_of_ReceptacleDelegate ())
    connection->accept (this);
}

void Connector_Visitor::
Visit_ProvidedRequestPortEnd (ProvidedRequestPortEnd_in end)
{
  for (ConnectorToFacet connection : end->dst_of_ConnectorToFacet ())
    connection->accept (this);

  for (FacetDelegate connection : end->dst_of_FacetDelegate ())
    connection->accept (this);
}

void Connector_Visitor::
Visit_ConnectorToReceptacle (ConnectorToReceptacle_in conn)
{
  // Get the connector instance and deploy it. This will also prepare
  // the necessary private variables for creating the connection.
  ConnectorInstance inst = conn->dst_ConnectorInstance ();

  // We have enough information to generate the connection information
  // for the the receptacle to facet connection.
  Object obj = Object::_narrow (this->receptacle_->refers_to_Provideable ());

  // Start a new connection.
  this->start_new_connection (obj);

  if (this->is_ami4ccm_connector (inst))
  {
    // Since the connector is ami4ccm, we need to generate a special
    // connections for it. The number of connections will be determined
    // by the number of facet connections we have coming into this
    // connector instance.
    std::set <ProvidedRequestPortInstance> facets;
    ProvidedRequestPortInstance_Collector facet_gatherer (facets);

    for (ConnectorToFacet connection : inst->dst_of_ConnectorToReceptacle ())
      conn->accept (this);

    for (ProvidedRequestPortInstance facet : facets)
    {
      this->curr_conn_ = this->document_.create_element ("connection");
      this->name_element_ = this->curr_conn_.append_element ("name");

      Fragment deployRequirement = this->curr_conn_.append_element ("deployRequirement");
      deployRequirement.append_simple_content ("name", "edu.dre.vanderbilt.DAnCE.ConnectionType");
      deployRequirement.append_simple_content ("resourceType", "Local_Interface");

      // Write the endpoint for the facet.
      std::string uuid = "_" + this->comp_inst_->UUID ();
      const std::string sendc_portname = "sendc_" + this->receptacle_->name ();
      this->append_endpoint (sendc_portname, "SimplexReceptacle", "false", uuid);

      // Get the UUID assigned to the facet connection, which represents
      // the UUID for the target connector fragment.
      std::map <ProvidedRequestPortInstance,
                std::string>::const_iterator
                result = this->ami4ccm_uuids_.find (facet);

      if (result == this->ami4ccm_uuids_.end ())
      {
        uuid = GAME::Utils::create_uuid ();
        this->ami4ccm_uuids_[facet] = uuid;
      }
      else
      {
        uuid = result->second;
      }

      // Make sure the connector is on the same group as the current
      // component instance. Unlike with the standard connectors, the
      // ami4ccm connector fragment is not deployed for each host. It
      // is only deployed for the receptacle. We all need to instantiate
      // a connector fragment for each *FacetToConnector* connection
      // that is connected to this connector.
      const std::string old_uuid = inst->UUID ();
      const std::string old_name = inst->name ();

      inst->UUID (uuid);

      // Get the current number of connections for the connector.
      size_t count = this->connector_counter_[inst] + 1;

      std::ostringstream inst_name;
      inst_name << inst->name () << count;
      inst->name (inst_name.str ());

      // Deploy the connector fragment.
      this->handler_->deploy_connector_fragment (inst, this->comp_inst_);

      // Update the counter for this connector instance.
      this->connector_counter_[inst] = count;

      // Restore the UUID and name.
      inst->UUID (old_uuid);
      inst->name (old_name);

      // Write the endpoint for the connector's receptacle.
      this->append_endpoint ("ami4ccm_port_ami4ccm_provides",
                             "Facet",
                             "true",
                             "_" + uuid);

      // Overwrite the current connection name.
      std::ostringstream connection_name;
      connection_name << facet->id ()
                      << "_"
                      << this->active_receptacle_->id ();

      this->connection_name_ = connection_name.str ();

      // End the current connection.
      this->end_connection ();
    }
  }
  else
  {
    // Deploy the connector fragment.
    this->deploy_connector_fragment (inst);

    const std::string name (conn->name ());
    const std::string inner_name (conn->InnerName ());

    if (inner_name.empty ())
    {
      // We are connecting to a facet on the connector.
      this->prefix2_.clear ();
      this->portname2_ = name;
    }
    else
    {
      // We are connecting to a facet in a port type.
      this->prefix2_ = conn->name ();
      this->portname2_ = conn->InnerName ();
    }

    std::string uuid = "_" + std::string (this->comp_inst_->UUID ());
    this->Visit_RequiredRequestPort_i (uuid, "", this->receptacle_->name (), false);

    this->connection_name_ += "::" + this->connector_name_;

    this->Visit_ProvidedRequestPort_i (this->connector_uuid_,
                                       this->prefix2_,
                                       this->portname2_,
                                       false);

    // End the current connection.
    this->end_connection ();
  }
}

//
// Visit_ConnectorToFacet
//
void Connector_Visitor::
Visit_ConnectorToFacet (ConnectorToFacet_in conn)
{
  // Get the connector instance and deploy it. This will also prepare
  // the necessary private variables for creating the connection.
  ConnectorInstance inst = conn->src_ConnectorInstance ();

  // Start a new connection.
  Object obj = Object::_narrow (this->facet_->refers_to_Provideable ());
  this->start_new_connection (obj);

  if (this->is_ami4ccm_connector (inst))
  {
    using xercesc::DOMElement;

    // Since this is an ami4ccm connector, we need to generate a special
    // connection for it.
    this->curr_conn_ = this->document_.create_element ("connection");
    this->name_element_ = this->curr_conn_.append_element ("name");

    // Write the endpoint for the facet.
    std::string uuid = "_" + std::string (this->comp_inst_->UUID ());
    this->append_endpoint (this->facet_->name (), "Facet", "true", uuid);

    // Get the UUID assigned to the facet connection, which represents
    // the UUID for the target connector fragment.
    std::map <ProvidedRequestPortInstance,
              std::string>::const_iterator
              result = this->ami4ccm_uuids_.find (this->active_facet_);

    if (result == this->ami4ccm_uuids_.end ())
    {
      uuid = GAME::Utils::create_uuid ();
      this->ami4ccm_uuids_[this->active_facet_] = uuid;
    }
    else
    {
      uuid = result->second;
    }

    // Write the endpoint for the connector's receptacle.
    this->append_endpoint ("ami4ccm_port_ami4ccm_uses",
                           "SimplexReceptacle",
                           "false",
                           "_" + uuid);

    // Overwrite the current connection name.
    this->connection_name_ = this->active_facet_->id ();
  }
  else
  {
    this->deploy_connector_fragment (inst);

    const std::string name (conn->name ());
    const std::string inner_name (conn->InnerName ());

    if (inner_name.empty ())
    {
      // We are connecting to a facet on the connector.
      this->prefix2_.clear ();
      this->portname2_ = name;
    }
    else
    {
      // We are connecting to a facet in a port type.
      this->prefix2_ = conn->name ();
      this->portname2_ = conn->InnerName ();
    }

    std::string uuid = "_" + std::string (this->comp_inst_->UUID ());
    this->Visit_ProvidedRequestPort_i (uuid, "", this->facet_->name (), false);

    this->connection_name_ += "::" + this->connector_name_;

    this->Visit_RequiredRequestPort_i (this->connector_uuid_,
                                       this->prefix2_,
                                       this->portname2_,
                                       false);
  }

  // End the current connection.
  this->end_connection ();
}

bool Connector_Visitor::is_ami4ccm_connector (ConnectorInstance_in inst)
{
  ConnectorImplementationType impl_type = inst->get_ConnectorImplementationType ();
  ConnectorImplementation impl = impl_type->refers_to_ConnectorImplementation ();
  ConnectorImplements implements = impl->src_of_ConnectorImplements ();

  ConnectorType type = implements->dst_ConnectorType ();
  return this->is_ami4ccm_connector (type->refers_to_ConnectorObject ());
}

bool Connector_Visitor::is_ami4ccm_connector (ConnectorObject_in obj)
{
  const std::string name (obj->name ());

  if (name == "AMI4CCM_Base")
    return true;

  // Get the inherits specification for this connector.
  ConnectorInherits inherits = obj->get_ConnectorInherits ();

  if (inherits.is_nil ())
    return false;

  // Check if this object is an ami4ccm connector.
  ConnectorObject conn = inherits->refers_to_ConnectorObject ();
  return conn.is_nil () ? false : this->is_ami4ccm_connector (conn);
}

void Connector_Visitor::Visit_Publish (Publish_in publish)
{
  // Store the name of this connection as the target port.
  this->prefix2_ = publish->name ();

  // Make sure to include this instance in deployment plan.
  ConnectorInstance inst = publish->dst_ConnectorInstance ();
  this->deploy_connector_fragment (inst);
}

void Connector_Visitor::Visit_Consume (Consume_in consume)
{
  // Store the name of this connection as the target port.
  this->prefix2_ = consume->name ();

  // Make sure to include this instance in deployment plan.
  ConnectorInstance inst = consume->src_ConnectorInstance ();
  this->deploy_connector_fragment (inst);
}

void Connector_Visitor::Visit_PortType (PortType_in pt)
{
  for (RequiredRequestPort port : pt->get_RequiredRequestPorts ())
    port->accept (this);

  for (ProvidedRequestPort port : pt->get_ProvidedRequestPorts ())
    port->accept (this);
}

void Connector_Visitor::Visit_RequiredRequestPort (RequiredRequestPort_in p)
{
  Object obj = Object::_narrow (p->refers_to_Provideable ());
  this->start_new_connection (obj);

  std::string uuid = "_" + std::string (this->comp_inst_->UUID ());
  this->Visit_RequiredRequestPort_i (uuid,
                                     this->prefix1_,
                                     p->name (),
                                     this->invert_);

  this->connection_name_ += "::" + this->connector_name_;

  this->Visit_RequiredRequestPort_i (this->connector_uuid_,
                                     this->prefix2_,
                                     p->name (),
                                     !this->invert_);

  this->end_connection ();
}

//
// Visit_ProvidedRequestPort
//
void Connector_Visitor::
Visit_ProvidedRequestPort (ProvidedRequestPort_in p)
{
  Object obj = Object::_narrow (p->refers_to_Provideable ());
  this->start_new_connection (obj);

  std::string uuid = "_" + std::string (this->comp_inst_->UUID ());
  this->Visit_ProvidedRequestPort_i (uuid,
                                     this->prefix1_,
                                     p->name (),
                                     this->invert_);

  this->connection_name_ += "::" + this->connector_name_;

  this->Visit_ProvidedRequestPort_i (this->connector_uuid_,
                                     this->prefix2_,
                                     p->name (),
                                     !this->invert_);

  this->end_connection ();
}

//
// Visit_RequiredRequestPort
//
void Connector_Visitor::
Visit_RequiredRequestPort_i (const std::string & inst,
                             const std::string & prefix,
                             const std::string & port,
                             bool invert)
{
  std::string portname;

  if (!prefix.empty ())
    portname = prefix + "_";

  portname += port;

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
                             const std::string & port,
                             bool invert)
{
  std::string portname;

  if (!prefix.empty ())
    portname = prefix + "_";

  portname += port;

  const char * kind = invert ? "SimplexReceptacle" : "Facet";
  const char * provider = invert ? "false" : "true";

  this->append_endpoint (portname, kind, provider, inst);
}

//
// deploy_connector_fragment
//
void Connector_Visitor::
deploy_connector_fragment (ConnectorInstance_in inst)
{
  std::string fragment_uuid;

  try
  {
    // This will force all ports on the same component instance to
    // connector with the ports on the same connector instance.
    fragment_uuid = this->connector_uuids_.at (inst);
  }
  catch (const std::out_of_range &)
  {
    // Save the current name/uuid so we can generate a new one.
    const std::string old_uuid (inst->UUID ());
    const std::string old_name (inst->name ());

    InstanceMapping mapping = this->group_->src_of_InstanceMapping ();
    NodeReference noderef = mapping->dst_NodeReference ();
    Node node = noderef->refers_to_Node ();

    // Generate a new UUID and name for this connector fragment.
    fragment_uuid = GAME::Utils::create_uuid ();
    this->connector_uuids_.insert (std::make_pair (inst, fragment_uuid));

    std::string fragment_name = inst->name ();
    fragment_name += "@" + node->name () + "." + this->group_->name ();

    this->connector_name_ = inst->path (".", false);
    this->connector_name_ += "@" + node->name ();
    this->connector_name_ += "." + this->group_->name ();

    inst->UUID (fragment_uuid);
    inst->name (fragment_name);

    // Since this is a new fragment, we need to make sure that it
    // is included in the deployment plan.
    this->handler_->deploy_connector_fragment (inst, this->comp_inst_);

    // Restore the original UUID.
    inst->UUID (old_uuid);
    inst->name (old_name);
  }

  // Save the UUID for the connector fragment.
  this->connector_uuid_ = "_" + fragment_uuid;
}

//
// start_new_connection
//
void Connector_Visitor::start_new_connection (Object_in obj)
{
  this->curr_conn_ = this->document_.create_element ("connection");
  this->name_element_ = this->curr_conn_.append_element ("name");
  this->connection_name_ = this->comp_inst_->path (".", false);

  // Determine if the interface is local. If this is the case, then we
  // need to generate a special tag for such object.
  const std::string semantics (obj->InterfaceSemantics ());

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
  // Add the portname to the connection name.
  this->connection_name_ += "." + portname;

  Fragment ep = this->curr_conn_.append_element ("internalEndpoint");
  ep.append_simple_content ("portName", portname);
  ep.append_simple_content ("provider", provider);
  ep.append_simple_content ("kind", kind);

  Fragment instance = ep.append_element ("instance");
  instance.set_attribute ("xmi:idref", inst);
}

//
// end_connection
//
void Connector_Visitor::end_connection (void)
{
  this->name_element_->setTextContent (String (this->connection_name_));
  this->conns_.push_back (this->curr_conn_);
}

//
// make_connection_local
//
void Connector_Visitor::make_connection_local (Fragment conn)
{
  Fragment deployRequirement = conn.append_element ("deployRequirement");
  deployRequirement.append_simple_content ("name", "edu.dre.vanderbilt.DAnCE.ConnectionType");
  deployRequirement.append_simple_content ("resourceType", "Local_Interface");
}

}
}
