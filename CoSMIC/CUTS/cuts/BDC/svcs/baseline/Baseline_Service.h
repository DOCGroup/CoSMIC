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
#include "cuts/svcs/dbase/DB_Registry.h"
#include "cuts/System_Metric.h"
#include "ace/SString.h"

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
  int handle_metrics (const CUTS_System_Metric & metrics);

private:
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

  /// Instance name of the baseline component.
  ACE_CString instance_;

  /// The connection for the database service.
  ACE_Auto_Ptr <CUTS_DB_Connection> conn_;

  /// The component registry for the database.
  CUTS_DB_Registry registry_;
};

CUTS_BDC_SERVICE_DECL (CUTS_BASELINE_SERVICE_Export);

#endif  // !defined _CUTS_BASELINE_SERVICE_H_
