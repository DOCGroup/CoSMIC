// $Id$

#include "StdAfx.h"
#include "ToConnector_Event_Handler.h"

#include "game/Connection.h"
#include "game/Model.h"
#include "game/MetaModel.h"
#include "game/Reference.h"
#include "game/Attribute.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "game/dialogs/Dialog_Display_Strategy.h"

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

  bool get_display_name (const GAME::Object & obj, std::string & display_name)
  {
    GAME::Object parent = obj.parent ();

    if (parent.meta () == "ConnectorObject")
      display_name = obj.name ();
    else
      display_name = parent.name () + "_" + obj.name ();

    return true;
  }
};

//
// ToConnector_Event_Handler
//
ToConnector_Event_Handler::ToConnector_Event_Handler (void)
: is_importing_ (false)
{

}

//
// ~ToConnector_Event_Handler
//
ToConnector_Event_Handler::~ToConnector_Event_Handler (void)
{

}

//
// handle_xml_import_begin
//
int ToConnector_Event_Handler::handle_xml_import_begin (void)
{
  this->is_importing_ = true;
  return 0;
}

//
// handle_xml_import_end
//
int ToConnector_Event_Handler::handle_xml_import_end (void)
{
  this->is_importing_ = false;
  return 0;
}

//
// handle_object_created
//
int ToConnector_Event_Handler::
create_connection (GAME::Object obj,
                   const std::string & port_role,
                   const std::string & connector_role,
                   const std::string & target_port_type)
{
  if (this->is_importing_)
    return 0;

  // Get the source port (i.e., facet). We are going to use its
  // type when look for the receptacle on the target connector.
  GAME::Connection conn = GAME::Connection::_narrow (obj);
  GAME::FCO fco = conn[port_role].target ();
  GAME::Reference port_inst = GAME::Reference::_narrow (fco);

  fco = port_inst.refers_to ();
  if (fco.is_nil ())
    return 0;

  GAME::Reference port = GAME::Reference::_narrow (fco);
  fco = port.refers_to ();

  if (fco.is_nil ())
    return 0;

  GAME::Model target_object = GAME::Model::_narrow (fco);

  // Get the connector instance.
  fco = conn[connector_role].target ();
  GAME::Model connector_inst = GAME::Model::_narrow (fco);

  // Get the connector object for this instance.
  GAME::Model connector;
  if (!this->get_connector_object (connector_inst, connector))
    return 0;

  // Locate the target receptacles that match this object.
  std::vector <GAME::Reference> matching_ports;
  this->get_matching_ports (connector,
                            target_object,
                            target_port_type,
                            matching_ports);

  if (matching_ports.empty ())
    return 0;

  GAME::Reference matching_port;

  if (matching_ports.size () > 1)
  {
    using GAME::Dialogs::Selection_List_Dialog_T;
    using GAME::Reference;

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
  GAME::Model parent = matching_port.parent_model ();
  const std::string metaname = parent.meta ().name ();

  if (metaname == "ConnectorObject")
  {
    conn.name (matching_port.name ());
  }
  else
  {
    conn.name (parent.name ());
    conn.attribute ("InnerName").string_value (matching_port.name ());
  }

  return 0;
}

//
// get_connector_object
//
bool ToConnector_Event_Handler::
get_connector_object (const GAME::Model & inst, GAME::Model & conobj)
{
  using GAME::Connection;
  using GAME::FCO;
  using GAME::Reference;

  // Get the connector implementation reference.
  std::vector <Reference> connector_impls;
  if (1 != inst.children ("ConnectorImplementationType", connector_impls))
    return false;

  FCO connector_impl = connector_impls.front ().refers_to ();
  if (connector_impl.is_nil ())
    return false;

  // Get the connection between the implementation and the connector
  // object. There should be only one connection in this relation.
  std::vector <Connection> conns;
  if (1 != connector_impl.in_connections ("ConnectorImplements", conns))
    return false;

  // Get the reference at the end of the connection.
  FCO fco = conns.front ()[std::string ("dst")].target ();
  Reference ref = Reference::_narrow (fco);
  fco = ref.refers_to ();

  if (fco.is_nil ())
    return false;

  // Convert the object into the model.
  conobj = GAME::Model::_narrow (fco);

  return true;
}

//
// get_matching_ports
//
void ToConnector_Event_Handler::
get_matching_ports (const GAME::Model & connector,
                    const GAME::Model & object,
                    const std::string & type,
                    std::vector <GAME::Reference> & ports)
{
  using GAME::Reference;

  // Get all the receptacles in this connector object. We then need
  // to locate the receptacles that match the target object's type.
  std::vector <Reference> temp;
  if (connector.children (type, temp))
  {
    std::vector <Reference>::iterator
      iter = temp.begin (), iter_end = temp.end ();

    for (; iter != iter_end; ++ iter)
    {
      if (iter->refers_to () == object)
        ports.push_back (*iter);
    }
  }

  // Get all the receptacles in this connector that are within a
  // extended port.
  std::vector <Reference> extended;
  if (connector.children ("ExtendedPort", extended))
    std::for_each (extended.begin (),
                   extended.end (),
                   boost::bind (&ToConnector_Event_Handler::get_matching_inner_ports,
                                this,
                                _1,
                                boost::ref (object),
                                boost::ref (type),
                                boost::ref (ports)));

  std::vector <Reference> mirror;
  if (connector.children ("MirrorPort", mirror))
    std::for_each (mirror.begin (),
                   mirror.end (),
                   boost::bind (&ToConnector_Event_Handler::get_matching_inner_ports,
                                this,
                                _1,
                                boost::ref (object),
                                boost::ref (type),
                                boost::ref (ports)));

  // Now, see if this connector inherits for anything. If so, then
  // we need to visit all of its inherited ports.
  std::vector <Reference> inherits;
  if (connector.children ("ConnectorInherits", inherits))
  {
    std::vector <Reference>::iterator
      iter = inherits.begin (), iter_end = inherits.end ();

    for (; iter != iter_end; ++ iter)
    {
      GAME::Model base_connector = GAME::Model::_narrow (iter->refers_to ());
      this->get_matching_ports (base_connector, object, type, ports);
    }
  }
}

//
// get_matching_inner_ports
//
void ToConnector_Event_Handler::
get_matching_inner_ports (const GAME::Reference & extended,
                          const GAME::Model & object,
                          const std::string & type,
                          std::vector <GAME::Reference> & ports)
{
  using GAME::FCO;
  using GAME::Reference;

  FCO fco = extended.refers_to ();
  if (fco.is_nil ())
    return;

  GAME::Model porttype = GAME::Model::_narrow (fco);
  std::vector <Reference> receptacles;

  if (porttype.children (type, receptacles))
  {
    std::vector <Reference>::iterator
      iter = receptacles.begin (), iter_end = receptacles.end ();

    for (; iter != iter_end; ++ iter)
    {
      if (iter->refers_to () == object)
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
handle_object_created (GAME::Object obj)
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
handle_object_created (GAME::Object obj)
{
  return this->create_connection (obj, "src", "dst", "ProvidedRequestPort");
}

}
}
