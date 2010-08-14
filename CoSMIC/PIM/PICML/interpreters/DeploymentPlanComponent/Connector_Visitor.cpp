// $Id$

#include "Connector_Visitor.h"
#include "DeploymentPlanVisitor.h"

#include "Utils/xercesc/XercesString.h"
#include "Utils/udm/visit.h"
#include "Utils/Utils.h"

struct id_sort_t
{
  template <typename T>
  bool operator () (const T & rhs, const T & lhs) const
  {
    return std::string (rhs.name ()) < std::string (lhs.name ());
  }
};

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

  // Clear the map of connector uuids.
  this->connector_uuid_.clear ();
  this->ami4ccm_uuids_.clear ();
}

//
// find_plan_locality
//
bool Connector_Visitor::
find_plan_locality (const PICML::ComponentInstance & inst)
{
  typedef std::map <
    PICML::ComponentInstance,
    PICML::CollocationGroup> mapping_t;

  // Locate the collocation group for this instance.
  const mapping_t & mappings = this->dpv_.mappings ();
  mapping_t::const_iterator iter = mappings.find (inst);

  if (iter == mappings.end ())
    return false;

  this->group_ = iter->second;
  return true;
}

//
// Visit_ExtendedPortInstance
//
void Connector_Visitor::
Visit_ExtendedPortInstance (const PICML::ExtendedPortInstance & port)
{
  // Save the prefix for the ports.
  PICML::ExtendedPort ep = port.ref ();
  this->prefix1_ = ep.name ();
  PICML::PortType pt = ep.ref ();

  this->Visit_ExtendedPortInstanceBase (port, pt);
}

//
// Visit_ExtendedPortInstanceBase
//
void Connector_Visitor::
Visit_ExtendedPortInstanceBase (const PICML::ExtendedPortInstanceBase & base,
                                const PICML::PortType & pt)
{
  // Vist the publish connection for this port if it exist.
  PICML::Publish publish = base.dstPublish ();

  if (publish != Udm::null)
  {
    // Get name of target port, and its connector instance.
    publish.Accept (*this);

    // Now, flatten out the port type.
    this->invert_ = false;
    PICML::PortType (pt).Accept (*this);
  }

  // We also need to see if this port type is receiving anything
  // from a connector.
  PICML::Consume consume = base.srcConsume ();

  if (consume != Udm::null)
  {
    // Get name of target port, and its connector instance.
    consume.Accept (*this);

    // Now, flatten out the port type.
    this->invert_ = false;
    PICML::PortType (pt).Accept (*this);
  }

  // Finally, check if this port is part of a delegation. If so,
  // we need to locate the non-delegated port for this port.
  PICML::ExtendedDelegate ed = base.dstExtendedDelegate ();

  if (ed != Udm::null)
  {
    PICML::ComponentAssembly parent = ed.ComponentAssembly_parent ();
    const std::string path (parent.getPath (".", false, true, "name", true));

    PICML::ExtendedPortDelegate epd = ed.dstExtendedDelegate_end ();
    const std::string name (epd.name ());

    this->Visit_ExtendedPortInstanceBase (epd, pt);

    //// Since we are going up the model, we have to get the instance of
    //// the delegate port. This is because the only way a port is delegated
    //// is if it is instantiated in another component assembly.
    //std::set < PICML::ExtendedPortDelegate > instances = epd.Instances ();

    //std::for_each (instances.begin (),
    //               instances.end (),
    //               boost::bind (&Connector_Visitor::Visit_ExtendedPortInstanceBase,
    //                            this,
    //                            _1,
    //                            boost::ref (pt)));
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

  this->Visit_MirrorPortInstanceBase (port, pt);
}

//
// Visit_MirrorPortInstanceBase
//
void Connector_Visitor::
Visit_MirrorPortInstanceBase (const PICML::MirrorPortInstanceBase & base,
                              const PICML::PortType & pt)
{
  // Vist the publish connection for this port if it exist.
  PICML::Publish publish = base.dstPublish ();

  if (publish != Udm::null)
  {
    // Find the target connector.
    publish.Accept (*this);

    // Write all the connections.
    this->invert_ = true;
    PICML::PortType (pt).Accept (*this);
  }

  // We also need to see if this port type is receiving anything
  // from a connector.
  PICML::Consume consume = base.srcConsume ();

  if (consume != Udm::null)
  {
    // Find the target connector.
    consume.Accept (*this);

    // Write all the connections.
    this->invert_ = true;
    PICML::PortType (pt).Accept (*this);
  }

  // Finally, check if this port is part of a delegation. If so,
  // we need to locate the non-delegated port for this port.
  PICML::MirrorDelegate md = base.dstMirrorDelegate ();

  if (md != Udm::null)
  {
    PICML::MirrorPortDelegate mpd = md.dstMirrorDelegate_end ();
    this->Visit_MirrorPortInstanceBase (mpd, pt);

    //// Since we are going up the model, we have to get the instance of
    //// the delegate port. This is because the only way a port is delegated
    //// is if it is instantiated in another component assembly.
    //std::set < PICML::MirrorPortDelegate > instances = mpd.Instances ();

    //std::for_each (instances.begin (),
    //               instances.end (),
    //               boost::bind (&Connector_Visitor::Visit_MirrorPortInstanceBase,
    //                            this,
    //                            _1,
    //                            boost::ref (pt)));
  }
}

//
// Visit_RequiredRequestPortInstance
//
void Connector_Visitor::
Visit_RequiredRequestPortInstance (const PICML::RequiredRequestPortInstance & inst)
{
  // The prefix is not included since the name of the port is
  // only thing that matters with this type of connection.
  this->receptacle_ = inst.ref ();
  this->prefix1_.clear ();

  std::set <PICML::ConnectorToReceptacle> conns = inst.dstConnectorToReceptacle ();
  std::for_each (conns.begin (),
                 conns.end (),
                 boost::bind (&PICML::ConnectorToReceptacle::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ProvidedRequestPortInstance
//
void Connector_Visitor::
Visit_ProvidedRequestPortInstance (const PICML::ProvidedRequestPortInstance & inst)
{
  // The prefix is not included since the name of the port is
  // only thing that matters with this type of connection.
  this->facet_ = inst.ref ();
  this->prefix1_.clear ();

  std::set <PICML::ConnectorToFacet> conns = inst.srcConnectorToFacet ();
  std::for_each (conns.begin (),
                 conns.end (),
                 boost::bind (&PICML::ConnectorToFacet::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ConnectorToReceptacle
//
void Connector_Visitor::
Visit_ConnectorToReceptacle (const PICML::ConnectorToReceptacle & conn)
{
  // Get the connector instance and deploy it. This will also prepare
  // the necessary private variables for creating the connection.
  PICML::ConnectorInstance inst = conn.dstConnectorToReceptacle_end ();

  // We have enough information to generate the connection information
  // for the the receptacle to facet connection.
  PICML::Object obj = PICML::Object::Cast (this->receptacle_.ref ());

  if (this->is_ami4ccm_connector (inst))
  {
    using xercesc::DOMElement;

    // Since the connector is ami4ccm, we need to generate a special
    // connections for it. The number of connections will be determined
    // by the number of facet connections we have coming into this
    // connector instance.
    std::set <PICML::ConnectorToFacet> conns = inst.dstConnectorToFacet ();

    std::set <PICML::ConnectorToFacet>::iterator
      iter = conns.begin (), iter_end = conns.end ();

    for (; iter != iter_end; ++ iter)
    {
      //// Start a new connection.
      //this->start_new_connection (obj);

      this->curr_conn_ = this->doc_->createElement (L"connection");
      this->name_element_ = this->create_element (this->curr_conn_, "name");

      DOMElement * deployRequirement = this->create_element (this->curr_conn_, "deployRequirement");
      this->create_simple_content (deployRequirement, "name", "edu.dre.vanderbilt.DAnCE.ConnectionType");
      this->create_simple_content (deployRequirement, "resourceType", "Local_Interface");

      // Write the endpoint for the facet.
      std::string uuid = "_" + std::string (this->comp_inst_.UUID ());

      const std::string sendc_portname =
        std::string ("sendc_") +
        std::string (this->receptacle_.name ());

      this->append_endpoint (sendc_portname,
                             "SimplexReceptacle",
                             "false",
                             uuid);

      // Get the UUID assigned to the facet connection, which represents
      // the UUID for the target connector fragment.
      std::map <PICML::ConnectorToFacet, std::string>::
        const_iterator result = this->ami4ccm_uuids_.find (*iter);

      if (result == this->ami4ccm_uuids_.end ())
      {
        uuid = ::Utils::CreateUuid ();
        this->ami4ccm_uuids_[*iter] = uuid;
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
      std::string old_uuid = inst.UUID ();
      inst.UUID () = uuid;

      this->dpv_.deploy_connector_fragment (inst, this->group_);

      inst.UUID () = old_uuid;

      // Write the endpoint for the connector's receptacle.
      this->append_endpoint ("ami4ccm_port_ami4ccm_provides",
                             "Facet",
                             "true",
                             "_" + uuid);

      // Overwrite the current connection name.
      this->connection_name_ = conn.getPath (".", false, true, "name", true);


      // End the current connection.
      this->end_connection ();
    }
  }
  else
  {
    // Start a new connection.
    this->start_new_connection (obj);

    // Deploy the connector fragment.
    this->deploy_connector_fragment (inst);

    const std::string name (conn.name ());
    const std::string inner_name (conn.InnerName ());

    if (inner_name.empty ())
    {
      // We are connecting to a facet on the connector.
      this->prefix2_.clear ();
      this->portname2_ = name;
    }
    else
    {
      // We are connecting to a facet in a port type.
      this->prefix2_ = conn.name ();
      this->portname2_ = conn.InnerName ();
    }

    std::string uuid = "_" + std::string (this->comp_inst_.UUID ());
    this->Visit_RequiredRequestPort_i (uuid, "", this->receptacle_.name (), false);

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
Visit_ConnectorToFacet (const PICML::ConnectorToFacet & conn)
{
  // Get the connector instance and deploy it. This will also prepare
  // the necessary private variables for creating the connection.
  PICML::ConnectorInstance inst = conn.srcConnectorToFacet_end ();

  // Start a new connection.
  PICML::Object obj = PICML::Object::Cast (this->facet_.ref ());
  this->start_new_connection (obj);

  if (this->is_ami4ccm_connector (inst))
  {
    // Since the connector is ami4ccm, we need to generate a special
    // connection for it.
    using xercesc::DOMElement;

    this->curr_conn_ = this->doc_->createElement (L"connection");
    this->name_element_ = this->create_element (this->curr_conn_, "name");

    // Write the endpoint for the facet.
    std::string uuid = "_" + std::string (this->comp_inst_.UUID ());
    this->append_endpoint (this->facet_.name (),
                           "Facet",
                           "true",
                           uuid);

    // Get the UUID assigned to the facet connection, which represents
    // the UUID for the target connector fragment.
    std::map <PICML::ConnectorToFacet, std::string>::
      const_iterator result = this->ami4ccm_uuids_.find (conn);

    if (result == this->ami4ccm_uuids_.end ())
    {
      uuid = ::Utils::CreateUuid ();
      this->ami4ccm_uuids_[conn] = uuid;
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
    this->connection_name_ = conn.getPath (".", false, true, "name", true);
  }
  else
  {
    this->deploy_connector_fragment (inst);

    const std::string name (conn.name ());
    const std::string inner_name (conn.InnerName ());

    if (inner_name.empty ())
    {
      // We are connecting to a facet on the connector.
      this->prefix2_.clear ();
      this->portname2_ = name;
    }
    else
    {
      // We are connecting to a facet in a port type.
      this->prefix2_ = conn.name ();
      this->portname2_ = conn.InnerName ();
    }

    std::string uuid = "_" + std::string (this->comp_inst_.UUID ());
    this->Visit_ProvidedRequestPort_i (uuid, "", this->facet_.name (), false);

    this->connection_name_ += "::" + this->connector_name_;

    this->Visit_RequiredRequestPort_i (this->connector_uuid_,
                                       this->prefix2_,
                                       this->portname2_,
                                       false);
  }

  // End the current connection.
  this->end_connection ();
}

//
// is_ami4ccm_connector
//
bool Connector_Visitor::
is_ami4ccm_connector (const PICML::ConnectorInstance & inst)
{
  PICML::ConnectorImplementationType impl_type = inst.ConnectorImplementationType_child ();
  PICML::ConnectorImplementation impl = impl_type.ref ();
  PICML::ConnectorImplements implements = impl.dstConnectorImplements ();

  PICML::ConnectorType type = implements.dstConnectorImplements_end ();
  return this->is_ami4ccm_connector (type.ref ());
}

//
// is_ami4ccm_connector
//
bool Connector_Visitor::
is_ami4ccm_connector (const PICML::ConnectorObject & obj)
{
  const std::string name (obj.name ());

  if (name == "AMI4CCM_Base")
    return true;

  // Get the inherits specification for this connector.
  PICML::ConnectorInherits inherits = obj.ConnectorInherits_child ();
  if (inherits == Udm::null)
    return false;

  // Check if this object is an ami4ccm connector.
  PICML::ConnectorObject conn = inherits.ref ();
  if (conn != Udm::null)
    return this->is_ami4ccm_connector (conn);

  return false;
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
  this->deploy_connector_fragment (inst);
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
  this->deploy_connector_fragment (inst);
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
                                     p.name (),
                                     this->invert_);

  this->connection_name_ += "::" + this->connector_name_;

  this->Visit_RequiredRequestPort_i (this->connector_uuid_,
                                     this->prefix2_,
                                     p.name (),
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
                                     p.name (),
                                     this->invert_);

  this->connection_name_ += "::" + this->connector_name_;

  this->Visit_ProvidedRequestPort_i (this->connector_uuid_,
                                     this->prefix2_,
                                     p.name (),
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
deploy_connector_fragment (const PICML::ConnectorInstance & inst)
{
  // This will force all ports on the same component instance to
  // connector with the ports on the same connector instance.
  std::map <PICML::ConnectorInstance, std::string>::iterator
    result = this->connector_uuids_.find (inst);

  std::string fragment_uuid;

  if (result == this->connector_uuids_.end ())
  {
    // Save the current name/uuid so we can generate a new one.
    const std::string old_uuid (inst.UUID ());
    const std::string old_name (inst.name ());

    PICML::InstanceMapping mapping = this->group_.dstInstanceMapping ();
    PICML::NodeReference noderef = mapping.dstInstanceMapping_end ();
    PICML::Node node = noderef.ref ();

    // Generate a new UUID and name for this connector fragment.
    fragment_uuid = ::Utils::CreateUuid ();
    this->connector_uuids_[inst] = fragment_uuid;

    std::string fragment_name = inst.name ();
    fragment_name += "@" + std::string (node.name ()) + "." + std::string (this->group_.name ());

    this->connector_name_ = inst.getPath (".", false, true, "name", true);
    this->connector_name_ += "@" + std::string (node.name ());
    this->connector_name_ += "." + std::string (this->group_.name ());

    inst.UUID () = fragment_uuid;
    inst.name () = fragment_name;

    // Since this is a new fragment, we need to make sure that it
    // is included in the deployment plan.
    this->dpv_.deploy_connector_fragment (inst, this->group_);

    // Restore the original UUID.
    inst.UUID () = old_uuid;
    inst.name () = old_name;
  }
  else
  {
    fragment_uuid = result->second;
  }

  // Save the UUID for the connector fragment.
  this->connector_uuid_ = "_" + fragment_uuid;
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
  this->connection_name_ = this->comp_inst_.getPath (".", false, true, "name", true);

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
  this->connection_name_ += "." + portname;

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
  this->name_element_->setTextContent (::Utils::XStr (this->connection_name_));
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
