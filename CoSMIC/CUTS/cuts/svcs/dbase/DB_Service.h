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

#include "DB_Service_export.h"
#include "ace/Auto_Ptr.h"

// Forward decl.
class ODBC_Connection;

// Forward decl.
class ODBC_Query;

//=============================================================================
/**
 * @class CUTS_DB_Service
 *
 * Implements the common database operations that can be used by any
 * object. The main purpose of this class is to provide resuability
 * so that other objects do not have to worry about managing common
 * information (e.g., host, type, and instance data).
 */
//=============================================================================

class CUTS_DB_SERVICE_Export CUTS_DB_Service
{
public:
  /// Constructor.
  CUTS_DB_Service (void);

  /// Destructor.
  ~CUTS_DB_Service (void);

  /**
   * Connect to the database. This will establish a connection to the
   * database located on \a server. The connection will be autheticated
   * by \a username and \a password. If there is an existing connection,
   * it will be closed before trying to establish the new connection.
   *
   * @param[in]     username      Username for login
   * @param[in]     password      Password for login
   * @param[in]     server        Server hosting the database.
   * @param[in]     port          Port to use for connecting.
   * @retval        true          Connection succeeded.
   * @retval        false         Connection failed.
   */
  bool connect (const char * username,
                const char * password,
                const char * server,
                long port);

  /// Disconnect from the database service.
  void disconnect (void);

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
  bool register_component (const char * inst,
                           const char * type,
                           long * instid = 0);

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
  bool get_instance_id (const char * inst,
                        long * instid = 0);

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
  bool get_hostid_by_hostname (const char * hostname,
                               long * hostid);

  /**
   * Set the UUID for the current test.
   *
   * @param[in]     test        The target test number.
   * @param[in]     uuid        The UUID for the test.
   * @retval        true        Succeeded to set the UUID.
   * @retval        false       Failed to set the UUID.
   */
  bool set_test_uuid (long test, const char * uuid);

protected:
  ODBC_Query * create_query (void);

  /// Database connection.
  ACE_Auto_Ptr <ODBC_Connection> conn_;
};

#if defined (__CUTS_INLINE__)
#include "DB_Service.inl"
#endif

#endif  // !defined _CUTS_DB_SERVICE_H_
