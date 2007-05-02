// -*- C++ -*-

//=============================================================================
/**
 * @file      Metric_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_METRICS_VISITOR_H_
#define _CUTS_METRICS_VISITOR_H_

#include "cuts/CUTS_export.h"

// Forward decl.
class CUTS_System_Metric;

// Forward decl.
class CUTS_Component_Metric;

// Forward decl.
class CUTS_Port_Metric;

// Forward decl.
class CUTS_Port_Measurement;

// Forward decl.
class CUTS_Time_Measurement;

//=============================================================================
/**
 * @class CUTS_Metrics_Visitor
 *
 * Visitor object for traversing the various metric/measurement class
 * in the CUTS benchmarking framework.
 */
//=============================================================================

class CUTS_Export CUTS_Metrics_Visitor
{
public:
  /// Constructor.
  CUTS_Metrics_Visitor (void);

  /// Destructor.
  virtual ~CUTS_Metrics_Visitor (void);

  /**
   * Handle visiting a CUTS_System_Metric object.
   *
   * @param[in]     pm      Reference to a CUTS_System_Metric object.
   */
  virtual void visit_system_metric (const CUTS_System_Metric & sm);

  /**
   * Handle visiting a CUTS_Component_Metric object.
   *
   * @param[in]     pm      Reference to a CUTS_Component_Metric object.
   */
  virtual void visit_component_metric (const CUTS_Component_Metric & cm);

  /**
   * Handle visiting a CUTS_Port_Metric object.
   *
   * @param[in]     pm      Reference to a CUTS_Port_Metric object.
   */
  virtual void visit_port_metric (const CUTS_Port_Metric & pm);

  /**
   * Handle visiting a CUTS_Port_Measurement object.
   *
   * @param[in]     pm      Reference to a CUTS_Port_Measurement object.
   */
  virtual void visit_port_measurement (const CUTS_Port_Measurement & pm);

  /**
   * Handle visiting a CUTS_Time_Measurement object.
   *
   * @param[in]     tm      Reference to a CUTS_Time_Measurement object.
   */
  virtual void visit_time_measurement (const CUTS_Time_Measurement & tm);
};

#if defined (__CUTS_INLINE__)
#include "cuts/Metrics_Visitor.inl"
#endif

#endif  // !defined _CUTS_METRICS_VISITOR_H_
