// -*- C++ -*-

//=============================================================================
/**
 * @file      IO_System_Metric_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BDC_IO_SYSTEM_METRIC_VISITOR_H_
#define _CUTS_BDC_IO_SYSTEM_METRIC_VISITOR_H_

#include "cuts/System_Metrics_Visitor.h"

// Forward decl.
class CUTS_Testing_Service;

//=============================================================================
/**
 * @class CUTS_IO_System_Metric_Visitor
 *
 * Visitor for the CUTS I/O BDC service.
 */
//=============================================================================

class CUTS_IO_System_Metric_Visitor :
  public CUTS_System_Metrics_Visitor
{
public:
  /**
   * Initailizing constructor.
   *
   * @param[in]       tsvc        Testing service for the metrics.
   */
  CUTS_IO_System_Metric_Visitor (const CUTS_Testing_Service * tsvc);

  /// Destructor.
  virtual ~CUTS_IO_System_Metric_Visitor (void);

  // Visit the CUTS_System_Metric object.
  void visit_system_metrics (const CUTS_System_Metric & metrics);

  // Visit the CUTS_Component_Metric object.
  void visit_component_metrics (const CUTS_Component_Metric & metrics);

  // Visit the CUTS_Port_Metric object.
  void visit_port_metrics (const CUTS_Port_Metric & metrics);

  // Visit the CUTS_Time_Metric object.
  void visit_time_metrics (const CUTS_Time_Metric & metrics);

private:
  /// Pointer to the testing service database.
  const CUTS_Testing_Service * tsvc_;
};

#endif  // !defined _CUTS_BDC_IO_SYSTEM_METRIC_VISITOR_H_
