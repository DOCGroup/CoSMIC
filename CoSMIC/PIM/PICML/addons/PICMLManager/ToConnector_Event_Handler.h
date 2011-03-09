// -*- C++ -*-

//=============================================================================
/**
 *  @file       ToConnector_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_TO_CONNECTOR_EVENT_HANDLER_H_
#define _PICML_MI_TO_CONNECTOR_EVENT_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"
#include "game/mga/Model.h"

namespace PICML
{
namespace MI
{
/**
 * Implementation of the FacetToConnector event handlers. It's
 * main purpose to the assist the modeler in completing the
 * name of the connection, which represents the target port.
 */
class ToConnector_Event_Handler :
  public GAME::Mga::Event_Handler_Impl
{
public:
  /// Default constructor.
  ToConnector_Event_Handler (void);

  /// Destructor.
  virtual ~ToConnector_Event_Handler (void);

protected:
  int create_connection (GAME::Mga::Object_in obj,
                         const std::string & port_role,
                         const std::string & connector_role,
                         const std::string & target_port_type);

  bool get_connector_object (const GAME::Mga::Model_in inst, GAME::Mga::Model & conobj);

  void get_matching_ports (const GAME::Mga::Model_in connector,
                           const GAME::Mga::Model_in object,
                           const std::string & type,
                           std::vector <GAME::Mga::Reference> & ports);

  void get_matching_inner_ports (const GAME::Mga::Reference_in extended,
                                 const GAME::Mga::Model_in object,
                                 const std::string & type,
                                 std::vector <GAME::Mga::Reference> & ports);

  void get_matching_extended_ports (const GAME::Mga::Model_in connector,
                                    const GAME::Mga::FCO_in porttype,
                                    const std::string & metaname,
                                    std::vector <GAME::Mga::Reference> & ports);
};

/**
 * Implementation of the FacetToConnector event handlers. It's main
 * purpose to the assist the modeler in completing the name of the
 * connection, which represents the target port.
 */
class FacetToConnector_Event_Handler :
  public ToConnector_Event_Handler
{
public:
  /// Default constructor.
  FacetToConnector_Event_Handler (void);

  /// Destructor.
  virtual ~FacetToConnector_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

/**
 * Implementation of the FacetToConnector event handlers. It's main
 * purpose to the assist the modeler in completing the name of the
 * connection, which represents the target port.
 */
class ReceptacleToConnector_Event_Handler :
  public ToConnector_Event_Handler
{
public:
  /// Default constructor.
  ReceptacleToConnector_Event_Handler (void);

  /// Destructor.
  virtual ~ReceptacleToConnector_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

/**
 * @class PortType_To_Connector_Event_Handler
 */
class PortType_To_Connector_Event_Handler :
  public ToConnector_Event_Handler
{
public:
  PortType_To_Connector_Event_Handler (void);

  virtual ~PortType_To_Connector_Event_Handler (void);

protected:
  int set_connection_name (const GAME::Mga::Model_in connector,
                           const GAME::Mga::FCO_in port,
                           GAME::Mga::Connection connection);

  bool get_extended_port_instance (const GAME::Mga::FCO_in portend,
                                   GAME::Mga::FCO& port_inst);

  bool get_mirror_port_instance (const GAME::Mga::FCO_in portend,
                                 GAME::Mga::FCO& port_inst);
};

/**
 * @class Publish_To_Connector_Event_Handler
 *
 * Event handler for the Publish connection between an exposed
 * port type and a ConnectorInstance object.
 */
class Publish_To_Connector_Event_Handler :
  public PortType_To_Connector_Event_Handler
{
public:
  /// Default constructor.
  Publish_To_Connector_Event_Handler (void);

  /// Destructor.
  virtual ~Publish_To_Connector_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

/**
 * @class Consume_To_Connector_Event_Handler
 *
 * Event handler for the Consume connection between an exposed
 * port type and a ConnectorInstance object.
 */
class Consume_To_Connector_Event_Handler :
  public PortType_To_Connector_Event_Handler
{
public:
  /// Default constructor.
  Consume_To_Connector_Event_Handler (void);

  /// Destructor.
  virtual ~Consume_To_Connector_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

}
}

#endif  // !defined _PICML_MI_FACET_TO_CONNECTOR_EVENT_HANDLER_H_
