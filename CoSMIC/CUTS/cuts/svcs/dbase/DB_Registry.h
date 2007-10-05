// -*- C++ -*-

//=============================================================================
/**
 * @file      DB_Service.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_DB_SERVICE_H_
#define _CUTS_DB_SERVICE_H_

#include "DB_export.h"
#include "cuts/Component_Info.h"
#include "cuts/Component_Type.h"

// Forward decl.
class CUTS_DB_Connection;

//=============================================================================
/**
 * @class CUTS_DB_Registry
 *
 * Implements the common database operations that can be used by any
 * object. The main purpose of this class is to provide resuability
 * so that other objects do not have to worry about managing common
 * information (e.g., host, type, and instance data).
 */
//=============================================================================

class CUTS_DB_Export CUTS_DB_Registry
{
public:
  /// Constructor.
  CUTS_DB_Registry (void);

  /// Destructor.
  ~CUTS_DB_Registry (void);

  /**
   * Attach the database registry to an existing connection. This
   * is really the only way to use this object.
   *
   * @param[in]       conn        The target connection.
   */
  void attach (CUTS_DB_Connection * conn);

  /// Detach the registry from the current database connection.
  void detach (void);

  /**
   * Determine if the database object is has a connection.
   *
   * @retval          true        Has a connection.
   * @retval          false       Does not have a connection.
   */
  bool is_attached (void) const;

  /**
   * Register a component.
   *
   * @param[in]       info        The component info to register.
   * @retval          true        Successfully register info.
   * @retval          false       Failed to register info.
   */
  bool register_component (const CUTS_Component_Info & info,
                           long * inst_id = 0);

  /**
   * Register a new component. This will add the component information
   * to the database. If the type information is not present, then it
   * will be added as well. If any of the information is present in the
   * database, nothing will happen. If the current information differs
   * from \a inst and \a type, then it will be updated.
   *
   * @param[in]       inst        Unique instance id.
   * @param[in]       type        The \a inst type.
   * @param[out]      instid      Registration id for \a inst.
   * @retval          true        Successfully registered component.
   * @retval          false       Failed to register a component.
   *
   * @todo Add an overwrite flag to prevent existing data from being
   *       replaced by \a inst and \a type.
   */
  bool register_instance (const char * inst,
                          const char * type,
                          long * instid = 0);

  /**
   * Register a component type. This will add the component's type
   * information to the database, including its port ids.
   *
   * @param[in]       type        The component type.
   */
  bool register_component_type (const CUTS_Component_Type & type);

  /**
   * @overload
   *
   * @param[in]       type        The component type.
   * @param[out]      type_id     Registered type id.
   */
  bool register_component_type (const CUTS_Component_Type & type,
                                long & type_id);


  bool register_component_port (long type_id,
                                const CUTS_Port_Description_Map & port,
                                const char * port_type = 0);

  /**
   * Get the instance id of a component instance. The client does
   * not have to store the instance id. If this is the case, then
   * this method can be used to test for an instance id. The client
   * also has the option of registering the id it is not found.
   *
   * @param[in]       inst        Unique instance name of the component.
   * @param[out]      instid      Registered id for \a inst.
   * @retval          true        Successfully retrieved id.
   * @retval          false       Failed to retrieve id.
   */
  bool get_instance_id (const char * inst, long * instid = 0);

  /**
   * Get the typeid of the component. The typeid is the one
   * stored in the database for the specific component type.
   * It is also the one used to correlate a component instance
   * with a component type.
   *
   * @param[in]       type        Component type.
   * @param[out]      type_id     Output buffer for typeid.
   * @param[in]       auto_reg    Auto-register the type if not found.
   * @retval          true        Successfully retrieved type.
   * @retval          false       Failed to retrieve type.
   */
  bool get_component_typeid (const char * type,
                             long * type_id = 0,
                             bool auto_register = true);

  /**
   * Register an IP-address and hostname w/ the database. If
   * either the IP-address or hostname already exist, then
   * nothing happens.
   *
   * @param[in]       ipaddr        IP-address
   * @param[in]       hostname      Name of the host.
   * @param[out]      hostid        Buffer to receive host id.
   * @retval          true          Registration succeeded.
   * @retval          false         Registration failed.
   */
  bool register_host (const char * ipaddr,
                      const char * hostname,
                      long * hostid = 0);

  /**
   * Get the unique id of a host given its IP-address.
   *
   * @param[in]     ipaddr      IP-adddress
   * @param[out]    hostid      ID of the host.
   * @retval        true        The operation succeeded.
   * @retval        false       The operation failed.
   */
  bool get_hostid_by_ipaddr (const char * ipaddr,
                             long * hostid);

  /**
   * Get the unique id of a host given its hostname.
   *
   * @param[in]     hostname    Name of the host.
   * @param[out]    hostid      ID of the host.
   * @retval        true        The operation succeeded.
   * @retval        false       The operation failed.
   */
  bool get_hostid_by_hostname (const char * hostname, long * hostid);

  /**
   * Get the id of a port.
   *
   * @param[in]     portname    The name of the port.
   * @param[out]    portid      The id of the port.
   * @param[in]     autoreg     Register port if it does not exist.
   */
  bool get_port_id (const char * portname, long * portid, bool autoreg = true);

  bool set_component_type_details (long type_id,
                                   const char * sinks,
                                   const char * sources);

protected:
  bool ports_to_csv (const CUTS_Port_Description_Map & ports,
                     ACE_CString & str);

  /// Pointer the connection for the registry.
  CUTS_DB_Connection * conn_;
};

#if defined (__CUTS_INLINE__)
#include "DB_Registry.inl"
#endif

#endif  // !defined _CUTS_DB_SERVICE_H_
