// -*- C++ -*-

//=============================================================================
/**
 * @file        Baseline_Service.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BASELINE_SERVICE_H_
#define _CUTS_BASELINE_SERVICE_H_

#include "Baseline_Service_export.h"
#include "cuts/BDC/BDC_Service.h"
#include "cuts/System_Metric.h"
#include "ace/SString.h"

class ODBC_Connection;

//=============================================================================
/**
 * @class CUTS_Baseline_Service
 *
 * Benchmark data collector service object for collecting baseline
 * metrics of components. This service store the baseline metrics
 * in the CUTS database for use by other services and applications.
 */
//=============================================================================

class CUTS_Baseline_Service : public CUTS_BDC_Service
{
public:
  /// Default constructor.
  CUTS_Baseline_Service (void);

  /// Destructor.
  virtual ~CUTS_Baseline_Service (void);

  int init (int argc, ACE_TCHAR * argv []);

  // Handle the activate event.
  int handle_activate (void);

  // Handle the deactivate event.
  int handle_deactivate (void);

  // Handle the component state event.
  int handle_component (const CUTS_Component_Info & info);

  // Handle the deactivate event.
  int handle_metrics (void);

private:
  /**
   * Register a new component.
   *
   * @param[in]      regid      Registration ID of the component.
   * @param[in]      uuid       UUID of the component.
   * @retval         true       Successfully registered component.
   * @retval         false      Failed to register a component.
   */
  bool register_component (const char * uuid,
                           const char * type);

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

  long get_host_id (const char * hostname);

  /**
   * Helper method for parsing the command-line arguments
   * for the service.
   *
   * @param[in]       argc          Number of arguments.
   * @param[in]       argv          Command-line arguments.
   */
  int parse_args (int argc, ACE_TCHAR * argv []);

  /// Verbose state of the service.
  bool verbose_;

  /// Warmup time for the service.
  size_t warmup_count_;

  /// Location of database containing baseline table.
  ACE_CString server_;

  /// This baseline test is the default.
  bool default_;

  /// Unique id of the monitored instance.
  size_t uid_;

  /// System metrics for accumulating the metrics.
  CUTS_System_Metric baseline_;

  /// ODBC connection object.
  ACE_Auto_Ptr <ODBC_Connection> conn_;

  ACE_CString instance_;

  long database_id_;

  long host_id_;
};

CUTS_BDC_SERVICE_DECL (CUTS_BASELINE_SERVICE_Export);

#endif  // !defined _CUTS_BASELINE_SERVICE_H_
