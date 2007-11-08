// -*- C++ -*-

//=============================================================================
/**
 * @file        Baseline_Archiver_DB.h
 *
 * Database archiver for the baseline metrics.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BASELINE_ARCHIVER_DB_H_
#define _CUTS_BASELINE_ARCHIVER_DB_H_

#include "cuts/Metrics_Visitor.h"
#include "cuts/Auto_Functor_T.h"

// Forward decl.
class CUTS_Component_Registry;

// Forward decl.
struct CUTS_Component_Info;

// Forward decl.
class CUTS_DB_Connection;

// Forward decl.
class CUTS_DB_Query;

//=============================================================================
/**
 * @class CUTS_Baseline_Archiver_DB
 */
//=============================================================================

class CUTS_Baseline_Archiver_DB : public CUTS_Metrics_Visitor
{
public:
  /**
   * Initializing constructor. The \a conn passed into the consturctor
   * must be open. If the connection is not open, then the baseline
   * metrics will not be logged to the database.
   *
   * @param[in]     conn        The target connection.
   */
  CUTS_Baseline_Archiver_DB (const CUTS_Component_Registry & registry,
                             CUTS_DB_Connection & conn);

  /// Destructor.
  virtual ~CUTS_Baseline_Archiver_DB (void);

  void visit_system_metric (const CUTS_System_Metric & sm);

  void visit_component_metric (const CUTS_Component_Metric & cm);

  void visit_port_metric (const CUTS_Port_Metric & pm);

  void visit_port_measurement (const CUTS_Port_Measurement & pm);

  void visit_time_measurement (const CUTS_Time_Measurement & tm);

private:
  /// Try to initialize the object.
  bool init (void);

  /// Finalize the object.
  void fini (void);

  /// Registration information for all the components.
  const CUTS_Component_Registry & registry_;

  /// The information about the component.
  const CUTS_Component_Info * info_;

  /// The target database connection.
  CUTS_DB_Connection & conn_;

  /// The query for inserting metrics.
  CUTS_DB_Query * query_;

  /// Name of the instance being archived.
  char instance_[256];

  /// Name of the instance being archived.
  char metric_type_[10];

  /// The input port for the baseline metric.
  char inport_[256];

  /// The output port for the baseline metric.
  char outport_[256];

  /// Hostname for the baseline metric.
  char hostname_[256];

  /// The event count for the baseline metrics.
  long event_count_;

  /// The best execution time for the baseline.
  long best_time_;

  /// The worst execution time for the baseline.
  long worst_time_;

  /// The total time for the execution time.
  long total_time_;
};
#endif  // !defined _CUTS_BASELINE_ARCHIVER_H_
