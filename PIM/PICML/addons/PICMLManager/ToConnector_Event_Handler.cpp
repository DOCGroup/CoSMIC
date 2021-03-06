#include "StdAfx.h"
#include "ToConnector_Event_Handler.h"

#include "game/mga/Connection.h"
#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Reference.h"
#include "game/mga/Attribute.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include "game/mga/dialogs/Dialog_Display_Strategy.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

/**
 * @class Traditional_Port_Display_Stragegy
 *
 * Display strategy for showing the name of the target ports. This
 * will help differentiate from traditional ports on a connectors
 * and in an extended port.
 */
class Traditional_Port_Display_Stragegy :
    public GAME::Dialogs::Dialog_Display_Strategy
{
public:
  //
  // Traditional_Port_Display_Stragegy
  //
  Traditional_Port_Display_Stragegy (void)
  {

  }

  //
  // Traditional_Port_Display_Stragegy
  //
  virtual ~Traditional_Port_Display_Stragegy (void)
  {

  }

  bool get_display_name (const GAME::Mga::Object_in obj, std::string & display_name)
  {
    GAME::Mga::Object parent = obj->parent ();

    if (parent->meta ()->name () == "ConnectorObject")
      display_name = obj->name ();
    else
      display_name = parent->name () + "_" + obj->name ();

    return true;
  }
};

static const unsigned long mask = OBJEVENT_CREATED;

//
// ToConnector_Event_Handler
//
ToConnector_Event_Handler::ToConnector_Event_Handler (void)
: GAME::Mga::Object_Event_Handler (mask)
{

}

//
// ~ToConnector_Event_Handler
//
ToConnector_Event_Handler::~ToConnector_Event_Handler (void)
{

}

//
// handle_object_created
//
int ToConnector_Event_Handler::
create_connection (GAME::Mga::Object_in obj,
                   const std::string & port_role,
                   const std::string & connector_role,
                   const std::string & target_port_type)
{
  if (this->is_importing_)
    return 0;

  // Get the source port (i.e., facet). We are going to use its
  // type when look for the receptacle on the target connector.
  GAME::Mga::Connection conn = GAME::Mga::Connection::_narrow (obj);
  GAME::Mga::FCO fco = conn->connection_point (port_role)->target ();
  GAME::Mga::Reference port_inst = GAME::Mga::Reference::_narrow (fco);

  fco = port_inst->refers_to ();

  if (fco.is_nil ())
    return 0;

  GAME::Mga::Reference port = GAME::Mga::Reference::_narrow (fco);
  fco = port->refers_to ();

  if (fco.is_nil ())
    return 0;

  GAME::Mga::Model target_object = GAME::Mga::Model::_narrow (fco);

  // Get the connector instance.
  fco = conn->connection_point (connector_role)->target ();
  GAME::Mga::Model connector_inst = GAME::Mga::Model::_narrow (fco);

  // Get the connector object for this instance.
  GAME::Mga::Model connector;
  if (!this->get_connector_object (connector_inst, connector))
    return 0;

  // Locate the target receptacles that match this object.
  std::vector <GAME::Mga::Reference> matching_ports;
  this->get_matching_ports (connector,
                            target_object,
                            target_port_type,
                            matching_ports);

  if (matching_ports.empty ())
  {
    // We are not only going to discontinue to operation, but we are
    // not going to allow the connection to happen. This will help us
    // to (1) ensure no invalid models are created and (2) locate
    // any potential bugs in this event handler.
    ::AfxMessageBox ("No mathching ports were located!", MB_ICONEXCLAMATION);
    return -1;
  }

  GAME::Mga::Reference matching_port;

  if (matching_ports.size () > 1)
  {
    using GAME::Dialogs::Selection_List_Dialog_T;
    using GAME::Mga::Reference;

    // Display the set of ports so the modeler can select
    // which one they want to connect with.
    Traditional_Port_Display_Stragegy display;

    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
    Selection_List_Dialog_T <Reference> dlg (&display, ::AfxGetMainWnd ());

    dlg.title ("Connector Port Selector");
    dlg.insert (matching_ports);

    if (dlg.DoModal () != IDOK)
      return 0;

    // Store the selection.
    matching_port = dlg.selection ();
  }
  else
  {
    // The selection is the first one in the list.
    matching_port = matching_ports.front ();
  }

  // Update the connection infomration based on the selected matching
  // port type. If the parent is a connector, then set the name of the
  // connection to the name of the selected receptacle. If the parent
  // is an extended port, then sent the inner name as well.
  GAME::Mga::Model parent = matching_port->parent_model ();
  const std::string metaname = parent->meta ()->name ();

  if (metaname == "ConnectorObject")
  {
    conn->name (matching_port->name ());
  }
  else
  {
    conn->name (parent->name ());
    conn->attribute ("InnerName")->string_value (matching_port->name ());
  }

  return 0;
}

//
// get_connector_object
//
bool ToConnector_Event_Handler::
get_connector_object (const GAME::Mga::Model_in inst, GAME::Mga::Model & conobj)
{
  using GAME::Mga::Connection;
  using GAME::Mga::FCO;
  using GAME::Mga::Reference;

  // Get the connector implementation reference.
  std::vector <Reference> connector_impls;
  if (1 != inst->children ("ConnectorImplementationType", connector_impls))
    return false;

  FCO connector_impl = connector_impls.front ()->refers_to ();
  if (connector_impl.is_nil ())
    return false;

  // Get the connection between the implementation and the connector
  // object. There should be only one connection in this relation.
  std::vector <Connection> conns;
  if (1 != connector_impl->in_connections ("ConnectorImplements", conns))
    return false;

  // Get the reference at the end of the connection.
  FCO fco = conns.front ()->dst ();
  Reference ref = Reference::_narrow (fco);
  fco = ref->refers_to ();

  if (fco.is_nil ())
    return false;

  // Convert the object into the model.
  conobj = GAME::Mga::Model::_narrow (fco);

  return true;
}

//
// get_matching_ports
//
void ToConnector_Event_Handler::
get_matching_ports (const GAME::Mga::Model_in connector,
                    const GAME::Mga::Model_in object,
                    const std::string & type,
                    std::vector <GAME::Mga::Reference> & ports)
{
  using GAME::Mga::Reference;

  // Get all the receptacles in this connector object. We then need
  // to locate the receptacles that match the target object's type.
  std::vector <Reference> temp;
  if (connector->children (type, temp))
  {
    std::vector <Reference>::iterator
      iter = temp.begin (), iter_end = temp.end ();

    for (; iter != iter_end; ++ iter)
    {
      if ((*iter)->refers_to ()->is_equal_to (object))
        ports.push_back (*iter);
    }
  }

  // Get all the receptacles in this connector that are within a
  // extended port.
  std::vector <Reference> extended;
  if (connector->children ("ExtendedPort", extended))
  {
    std::for_each (extended.begin (),
                   extended.end (),
                   boost::bind (&ToConnector_Event_Handler::get_matching_inner_ports,
                                this,
                                _1,
                                object,
                                type,
                                boost::ref (ports)));
  }

  // TODO switch the type of port we are looking for since we are
  // searching in MirrorPort elements.
  const std::string mirror_type =
    type == "RequiredRequestPort" ?
    "ProvidedRequestPort" : "RequiredRequestPort";

  std::vector <Reference> mirror;

  if (connector->children ("MirrorPort", mirror))
  {
    std::for_each (mirror.begin (),
                   mirror.end (),
                   boost::bind (&ToConnector_Event_Handler::get_matching_inner_ports,
                                this,
                                _1,
                                object,
                                mirror_type,
                                boost::ref (ports)));
  }

  // Now, see if this connector inherits for anything. If so, then
  // we need to visit all of its inherited ports.
  std::vector <Reference> inherits;

  if (connector->children ("ConnectorInherits", inherits))
  {
    std::vector <Reference>::iterator
      iter = inherits.begin (), iter_end = inherits.end ();

    for (; iter != iter_end; ++ iter)
    {
      GAME::Mga::Model base_connector = GAME::Mga::Model::_narrow ((*iter)->refers_to ());

      if (!base_connector.is_nil ())
        this->get_matching_ports (base_connector, object, type, ports);
    }
  }
}

//
// get_matching_extended_ports
//
void ToConnector_Event_Handler::
get_matching_extended_ports (const GAME::Mga::Model_in connector,
                             const GAME::Mga::FCO_in porttype,
                             const std::string & metaname,
                             std::vector <GAME::Mga::Reference> & ports)
{
  using GAME::Mga::Reference;

  // Get all the exposed porttypes in this connector that are
  // of the specified metaname (i.e., extended/mirror port).
  std::vector <Reference> temp;

  if (connector->children (metaname, temp))
  {
    // Gather all the exposed ports that match the specified
    // port type.
    std::vector <Reference>::iterator
      iter = temp.begin (), iter_end = temp.end ();

    for (; iter != iter_end; ++ iter)
    {
      if ((*iter)->refers_to ()->is_equal_to (porttype))
        ports.push_back (*iter);
    }
  }

  // Now, go into the base connector(s) and repeat the same process
  // until we can collected all the valid ports.
  std::vector <Reference> inherits;

  if (connector->children ("ConnectorInherits", inherits))
  {
    std::vector <Reference>::iterator
      iter = inherits.begin (), iter_end = inherits.end ();

    for (; iter != iter_end; ++ iter)
    {
      GAME::Mga::Model base_connector = GAME::Mga::Model::_narrow ((*iter)->refers_to ());

      if (!base_connector.is_nil ())
        this->get_matching_extended_ports (base_connector, porttype, metaname, ports);
    }
  }
}

//
// get_matching_inner_ports
//
void ToConnector_Event_Handler::
get_matching_inner_ports (const GAME::Mga::Reference_in extended,
                          const GAME::Mga::Model_in object,
                          const std::string & type,
                          std::vector <GAME::Mga::Reference> & ports)
{
  using GAME::Mga::FCO;
  using GAME::Mga::Reference;

  FCO fco = extended->refers_to ();

  if (fco.is_nil ())
    return;

  std::vector <Reference> receptacles;
  GAME::Mga::Model porttype = GAME::Mga::Model::_narrow (fco);

  if (porttype->children (type, receptacles))
  {
    std::vector <Reference>::iterator
      iter = receptacles.begin (), iter_end = receptacles.end ();

    for (; iter != iter_end; ++ iter)
    {
      if ((*iter)->refers_to ()->is_equal_to (object))
        ports.push_back (*iter);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// FacetToConnector_Event_Handler

//
// FacetToConnector_Event_Handler
//
FacetToConnector_Event_Handler::FacetToConnector_Event_Handler (void)
{

}

//
// ~FacetToConnector_Event_Handler
//
FacetToConnector_Event_Handler::~FacetToConnector_Event_Handler (void)
{

}

//
// handle_object_created
//
int FacetToConnector_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  return this->create_connection (obj, "dst", "src", "RequiredRequestPort");
}

///////////////////////////////////////////////////////////////////////////////
// ReceptacleToConnector_Event_Handler

//
// ReceptacleToConnector_Event_Handler
//
ReceptacleToConnector_Event_Handler::ReceptacleToConnector_Event_Handler (void)
{

}

//
// ~FacetToConnector_Event_Handler
//
ReceptacleToConnector_Event_Handler::~ReceptacleToConnector_Event_Handler (void)
{

}

//
// handle_object_created
//
int ReceptacleToConnector_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  return this->create_connection (obj, "src", "dst", "ProvidedRequestPort");
}

///////////////////////////////////////////////////////////////////////////////
// PortType_To_Connector_Event_Handler

//
// PortType_To_Connector_Event_Handler
//
PortType_To_Connector_Event_Handler::
PortType_To_Connector_Event_Handler (void)
{

}

//
// ~PortType_To_Connector_Event_Handler
//
PortType_To_Connector_Event_Handler::
~PortType_To_Connector_Event_Handler (void)
{

}

//
// set_connection_name
//
int PortType_To_Connector_Event_Handler::
set_connection_name (const GAME::Mga::Model_in connector,
                     const GAME::Mga::FCO_in portend,
                     GAME::Mga::Connection connection)
{
  if (this->is_importing_)
    return 0;

  using GAME::Mga::Reference;
  using GAME::Mga::Model;

  GAME::Mga::FCO the_portend (portend);
  std::string metaname = portend->meta ()->name ();

  if (metaname == "ExtendedPortDelegate")
  {
    if (!this->get_extended_port_instance (portend, the_portend))
      return 0;
  }
  else if (metaname == "MirrorPortDelegate")
  {
    if (!this->get_mirror_port_instance (portend, the_portend))
      return 0;
  }

  // The port is either an extended or mirror port instance. We need
  // to get the instance's type information (i.e., what it refers to).
  Reference inst = Reference::_narrow (the_portend);
  Reference extended = GAME::Mga::Reference::_narrow (inst->refers_to ());

  if (extended.is_nil ())
    return 0;

  // We can now get the actual port type.
  GAME::Mga::FCO porttype = extended->refers_to ();

  if (porttype.is_nil ())
    return 0;

  // Now that we have the port type, we need to locate either the
  // extended port, or mirror port, on the connector.
  Model connobj;
  if (!this->get_connector_object (connector, connobj))
    return 0;

  // Determine what kind of port type we are looking for. The
  // target port must be the opposite of the port type on the
  // component instance.
  const bool is_extended_port = extended->meta ()->name () == "ExtendedPort" ? true : false;
  metaname = is_extended_port ? "MirrorPort" : "ExtendedPort";

  // Get the target ports for this port type.
  std::vector <Reference> valid_ports;
  this->get_matching_extended_ports (connobj,
                                     porttype,
                                     metaname,
                                     valid_ports);

  GAME::Mga::Reference valid_port;

  switch (valid_ports.size ())
  {
  case 0:
    return 0;

  case 1:
    valid_port = valid_ports.front ();
    break;

  default:
    {
      using GAME::Dialogs::Selection_List_Dialog_T;

      // Since there is more than one element in the set, we
      // need to ask the user to select the correct one.
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
      Selection_List_Dialog_T <Reference> dlg (0, ::AfxGetMainWnd ());

      dlg.insert (valid_ports);
      dlg.title ("Target Port Selector");

      if (dlg.DoModal () != IDOK)
        return 0;

      valid_port = dlg.selection ();
    }
  }

  // We can now set the name of the connection since we have the
  // valid target port on the connector.
  if (!valid_port.is_nil ())
    connection->name (valid_port->name ());

  return 0;
}

//
// get_extended_port_instance
//
bool PortType_To_Connector_Event_Handler::
get_extended_port_instance (const GAME::Mga::FCO_in portend, GAME::Mga::FCO& port_inst)
{
  using GAME::Mga::Connection;
  using GAME::Mga::ConnectionPoints;
  using GAME::Mga::ConnectionPoint;
  using GAME::Mga::FCO;

  // Since we are walking the model from the connector to the
  // target port type, we need to find the connection point where
  // this object is the destination.
  ConnectionPoints points;
  if (0 == portend->in_connection_points (points))
    return false;

  ConnectionPoint point;
  if (!points.find ("dst", point))
    return false;

  // Get the target object. If this object is also a delegate, then
  // we need to continue down the model.
  Connection delegate_conn = point->owner ();
  FCO target = delegate_conn->src ();

  if (target->meta ()->name () == "ExtendedPortDelegate")
    return this->get_extended_port_instance (target, port_inst);

  port_inst = target;
  return true;
}

//
// get_mirror_port_instance
//
bool PortType_To_Connector_Event_Handler::
get_mirror_port_instance (const GAME::Mga::FCO_in portend, GAME::Mga::FCO& port_inst)
{
  using GAME::Mga::Connection;
  using GAME::Mga::ConnectionPoints;
  using GAME::Mga::ConnectionPoint;
  using GAME::Mga::FCO;

  // Since we are walking the model from the connector to the
  // target port type, we need to find the connection point where
  // this object is the destination.
  ConnectionPoints points;
  if (0 == portend->in_connection_points (points))
    return false;

  ConnectionPoint point;
  if (!points.find ("dst", point))
    return false;

  // Get the target object. If this object is also a delegate, then
  // we need to continue down the model.
  Connection delegate_conn = point->owner ();
  FCO target = delegate_conn->src ();

  if (target->meta ()->name () == "MirrorPortDelegate")
    return this->get_mirror_port_instance (target, port_inst);

  port_inst = target;
  return true;
}

///////////////////////////////////////////////////////////////////////////////
// Publish_To_Connector_Event_Handler

//
// Publish_To_Connector_Event_Handler
//
Publish_To_Connector_Event_Handler::
Publish_To_Connector_Event_Handler (void)
{

}

//
// ~Publish_To_Connector_Event_Handler
//
Publish_To_Connector_Event_Handler::
~Publish_To_Connector_Event_Handler (void)
{

}

//
// handle_object_created
//
int Publish_To_Connector_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  using GAME::Mga::Connection;
  using GAME::Mga::Model;

  // Get the connection endpoints.
  Connection publish = Connection::_narrow (obj);
  Model connector_inst = Model::_narrow (publish->dst ());
  GAME::Mga::FCO portend = publish->src ();

  return this->set_connection_name (connector_inst, portend, publish);
}

///////////////////////////////////////////////////////////////////////////////
// Consume_To_Connector_Event_Handler

//
// Consume_To_Connector_Event_Handler
//
Consume_To_Connector_Event_Handler::Consume_To_Connector_Event_Handler (void)
{

}

//
// ~Consume_To_Connector_Event_Handler
//
Consume_To_Connector_Event_Handler::~Consume_To_Connector_Event_Handler (void)
{

}

//
// handle_object_created
//
int Consume_To_Connector_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  using GAME::Mga::Connection;
  using GAME::Mga::Model;

  // This is a publish connection.
  Connection publish = Connection::_narrow (obj);

  // First, let's get the source PortType that wants to connect to
  // the target connector.
  GAME::Mga::FCO port =  publish->dst ();
  Model connector_inst = Model::_narrow (publish->src ());

  return this->set_connection_name (connector_inst, port, publish);
}

}
}
