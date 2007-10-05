// -*- C++ -*-

//=============================================================================
/**
 * @file        System_Metric_Accumulator.h
 *
 * Visitor that accumulates CUTS_System_Metric values
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_SYSTEM_METRIC_ACCUMULATOR_H_
#define _CUTS_SYSTEM_METRIC_ACCUMULATOR_H_

#include "cuts/Metrics_Visitor.h"

//=============================================================================
/**
 * @class CUTS_System_Metric_Accumulator
 */
//=============================================================================

class CUTS_System_Metric_Accumulator :
  public CUTS_Metrics_Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       dest        The destination of results
   */
  explicit CUTS_System_Metric_Accumulator (CUTS_System_Metric & dest);

  /// Destructor.
  virtual ~CUTS_System_Metric_Accumulator (void);

  // Visit the CUTS_System_Metric object.
  virtual void visit_system_metric (const CUTS_System_Metric & metric);

  // Visit the CUTS_Component_Metric object.
  virtual void visit_component_metric (const CUTS_Component_Metric & metric);

  virtual void visit_port_metric (const CUTS_Port_Metric & metric);

  virtual void visit_port_measurement (const CUTS_Port_Measurement & measure);

  virtual void visit_time_measurement (const CUTS_Time_Measurement & tm);

private:
  /// The destination for the accumulated metrics.
  CUTS_System_Metric & dest_;

  /// The target component metrics.
  CUTS_Component_Metric * component_;

  /// The target port metric.
  CUTS_Port_Metric * port_metric_;

  /// The target port measurement.
  CUTS_Port_Measurement * port_measure_;

  /// The target time measurement.
  CUTS_Time_Measurement * timing_;
};

#endif  // !defined _CUTS_SYSTEM_METRIC_ACCUMULATOR_H_
