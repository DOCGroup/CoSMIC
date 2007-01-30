// -*- C++ -*-

//=============================================================================
/**
 * @file      DBase_Service.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_DBASE_SERVICE_H_
#define _CUTS_DBASE_SERVICE_H_

#include "cuts/BDC/BDC_Service.h"
#include "DBase_Service_export.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Auto_Ptr.h"
#include "ace/SString.h"
#include <map>

// Forward decl.
class ODBC_Connection;

// Forward decl.
class ODBC_Query;

//=============================================================================
/**
 * @class CUTS_Database_Service
 *
 * @brief   Defines the mapping from registration id to component id.
 */
//=============================================================================

typedef std::map <long,
                  long> CUTS_DBase_Svc_Component_Map;

//=============================================================================
/**
 * @class CUTS_Database_Service
 *
 * Database service object for the BDC.
 */
//=============================================================================

class CUTS_Database_Service : public CUTS_BDC_Service
{
public:
  /// Constructor.
  CUTS_Database_Service (void);

  /// Destructor.
  ~CUTS_Database_Service (void);

  /**
   * Initialize the database service.
   *
   * @param[in]       argc        Number of command-line arguments
   * @param[in]       argv        Command-line arguments
   */
  int init (int argc, ACE_TCHAR * argv []);

  /// Finalize the object (i.e., destroy it).
  int fini (void);

  /**
   * Activate the service object. This allows the service object
   * to perform any initial operations on the system metrics.
   */
  int handle_activate (void);

  /**
   * Deactivate the service object. This allows the service object
   * to perform any final operations on the system metrics.
   */
  int handle_deactivate (void);

  /**
   * Signal the service object to handle the new set of data. This
   * method is required by all service objects because it is their
   * only way of processing data collected from the testing
   * environment.
   */
  int handle_metrics (void);

  /**
   * Connect to the database.
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
   * Create a new test.
   *
   * @retval    true      Successfully create a new test.
   * @retval    false     Failed to create a new test.
   */
  bool create_new_test (void);

  /**
   * Stop the current test.
   *
   * @retval    true      Successfully stoped the current test.
   * @retval    false     Failed to stop the current test.
   */
  bool stop_current_test (void);

  /**
   * Register a new component.
   *
   * @param[in]      regid      Registration ID of the component.
   * @param[in]      uuid       UUID of the component.
   * @retval         true       Successfully registered component.
   * @retval         false      Failed to register a component.
   */
  bool register_component (const char * uuid,
                           const char * type,
                           long regid);


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
   * Get the instance id of a component instance. The client
   * does not have to store the instance id. If this is the
   * case, then this method can be used to test for an instance
   * id. The client also has the option of registering the
   * id it is not found.
   */
  bool get_instance_id (const char * uuid,
                        long * id = 0,
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
                      int * hostid = 0);

  /**
   * Get the unique id of a host given it's IP-address. The
   * IP-address can be IPv4 or IPv6.
   *
   * @param[in]     ipaddr      IP-adddress
   * @param[in]     hostname    Name of the host.
   * @param[out]    hostid      ID of the host.
   * @retval        true        The operation succeeded.
   * @retval        false       The operation failed.
   */
  bool get_host_id (const char * ipaddr,
                    const char * hostname,
                    long &hostid);

  /**
   * Get the current test number.
   *
   * @return The current test number.
   */
  long current_test (void) const;

  /**
   * Get the id of a path given its name.
   *
   * @param[in]     pathname      Name of the path.
   * @retval        other         Id of the path.
   * @retval        -1            Path was not found.
   */
  long path_id (const char * pathname);

  bool set_component_uptime (long cid, long hostid);

  bool set_component_downtime (long cid);

  int handle_component (const CUTS_Component_Info & info);

private:
  int parse_args (int argc, ACE_TCHAR * argv []);

  ODBC_Query * create_new_query (void);

  /**
   * Stop the current test. This version of the method does
   * not acquire the internal lock.
   *
   * @retval    true      Successfully stoped the current test.
   * @retval    false     Failed to stop the current test.
   */
  bool stop_current_test_i (void);

  /// Disconnect form the database without acquiring lock.
  void disconnect_i (void);

  /// Location of the database.
  ACE_CString server_;

  /// Username for the login (default='cuts').
  ACE_CString username_;

  /// Password for the login (default='cuts')
  ACE_CString password_;

  /// Verbose flag for the service.
  bool verbose_;

  /// Port number for database connection.
  int port_;

  /// Database connection.
  ACE_Auto_Ptr <ODBC_Connection> conn_;

  /// Locking mechanism.
  ACE_RW_Thread_Mutex lock_;

  /// Component registration mapping.
  CUTS_DBase_Svc_Component_Map component_mapping_;

  /// The current test number.
  long test_number_;
};

#if defined (__CUTS_INLINE__)
#include "DBase_Service.inl"
#endif

CUTS_BDC_SERVICE_DECL (DBASE_SVC_Export);

#endif  // !defined _CUTS_DBASE_SERVICE_H_
