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
#include <map>


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

class CUTS_Database_Service :
  public CUTS_BDC_Service,
  public CUTS_DB_Service
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
  typedef std::map <long,
                    long> ID_Map;

  // Helper method to parse the command-line arguments.
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

  /// Locking mechanism.
  ACE_RW_Thread_Mutex lock_;

  /// Component registration mapping.
  ID_Map id_map_;

  /// The current test number.
  long test_number_;
};

#if defined (__CUTS_INLINE__)
#include "DBase_Service.inl"
#endif

CUTS_BDC_SERVICE_DECL (DBASE_SVC_Export);

#endif  // !defined _CUTS_DBASE_SERVICE_H_
