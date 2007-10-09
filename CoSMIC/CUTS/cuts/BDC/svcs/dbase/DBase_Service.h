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

#include "DBase_Service_export.h"
#include "cuts/BDC/BDC_Service.h"
#include "cuts/svcs/dbase/DB_Registry.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Hash_Map_Manager.h"

class ODBC_Query;

//=============================================================================
/**
 * @class CUTS_Database_Service
 *
 * Archiving service for the Benchmark Data Collector. This service
 * will take metrics collected during the experiment and archive
 * them to a database. This allows experiments to preserve the all
 * the metrics for later usage, i.e., viewing in the BMW.
 */
//=============================================================================


class CUTS_Database_Service : public CUTS_BDC_Service
{
public:
  /// Constructor.
  CUTS_Database_Service (void);

  /// Destructor.
  ~CUTS_Database_Service (void);

  // Initialize the service object.
  int init (int argc, ACE_TCHAR * argv []);

  // Finalize the service object.
  int fini (void);

  // Handle activate event.
  int handle_activate (void);

  // Handle deactivate event.
  int handle_deactivate (void);

  // Handle metric notification events.
  int handle_metrics (const CUTS_System_Metric & metrics);

  // Handle the component notification events.
  int handle_component (const CUTS_Component_Info & info);

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
   * Get the current test number.
   *
   * @return The current test number.
   */
  long current_test (void) const;

private:
  // Helper method to parse the command-line arguments.
  int parse_args (int argc, ACE_TCHAR * argv []);

  /**
   * Set the test uuid for the current test.
   *
   * @retval      true      Successfully set the test uuid.
   * @retval      false     Failed to set the test uuid.
   */
  bool set_test_uuid (void);

  /**
   * Stop the current test. This version of the method does
   * not acquire the internal lock.
   *
   * @retval    true      Successfully stoped the current test.
   * @retval    false     Failed to stop the current test.
   */
  bool stop_current_test_i (void);

  /// Set the component uptime in the deployment table.
  void set_component_uptime (const CUTS_Component_Info & info);

  /// Set the component downtime in the deployment table.
  void set_component_downtime (const CUTS_Component_Info & info);

  /// Verbose flag for the service.
  bool verbose_;

  /// Location of the database.
  ACE_CString server_;

  /// Username for the login (default='cuts').
  ACE_CString username_;

  /// Password for the login (default='cuts')
  ACE_CString password_;

  /// Port number for database connection.
  int port_;

  /// Locking mechanism.
  ACE_RW_Thread_Mutex lock_;

  /// The current test number.
  long test_number_;

  /// Determine if we should log the deployment information.
  bool enable_deployment_;

  /// The connection for the database service.
  ACE_Auto_Ptr <CUTS_DB_Connection> conn_;

  /// The registry part of the database.
  CUTS_DB_Registry registry_;
};

#if defined (__CUTS_INLINE__)
#include "DBase_Service.inl"
#endif

CUTS_BDC_SERVICE_DECL (DBASE_SVC_Export);

#endif  // !defined _CUTS_DBASE_SERVICE_H_
