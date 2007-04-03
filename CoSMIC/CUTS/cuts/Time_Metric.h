// -*- C++ -*-

//=============================================================================
/**
 * @file      Time_Metric.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TIME_METRIC_H_
#define _CUTS_TIME_METRIC_H_

#include "cuts/CUTS_export.h"
#include "ace/Time_Value.h"

// Forward decl.
class CUTS_System_Metrics_Visitor;

//=============================================================================
/**
 * @class CUTS_Time_Metric
 *
 * Timing measurement container. This object keeps track of timing data
 * (i.e., worst, average, and best) timing measurements.
 */
//=============================================================================

class CUTS_Export CUTS_Time_Metric
{
public:
  /// Default constructor.
  CUTS_Time_Metric (void);

  /// Copy constructor.
  CUTS_Time_Metric (const CUTS_Time_Metric & tm);

  /// Destructor.
  ~CUTS_Time_Metric (void);

  /// Number of samples in the timing metric.
  long count (void) const;

  /// Best execution timing metric.
  long best_time (void) const;

  /// Worse execution timing metric.
  long worse_time (void) const;

  /// Average execution timing metric.
  long total_time (void) const;

  /// Get the average time for the metrics.
  double avg_time (void) const;

  /// Set the execution timing metrics.
  void update (size_t count, long total, long best, long worse);

  /// Reset all the timing metrics.
  void reset (void);

  /**
   * Assignment operation.
   *
   * @param[in]     tm      Source time metric object.
   * @return        Reference to target object.
   */
  const CUTS_Time_Metric & operator = (const CUTS_Time_Metric & tm);

  /**
   * Self-assigning addition operation.
   *
   * @param[in]     tm      Source time metric object.
   * @return        Reference to target object.
   */
  const CUTS_Time_Metric & operator += (const CUTS_Time_Metric & metric);

  /**
   * Get the timestamp stored in the metrics. This can be used for
   * determine if the metrics are out-of-date.
   *
   * @return    The timestamp as a ACE_Time_Value object.
   */
  const ACE_Time_Value & timestamp (void) const;

  /**
   * Set the timestamp stored in the metrics.
   *
   * @param[in]   timestamp    Timestamp to be applied to metrics.
   */
  void timestamp (const ACE_Time_Value & timestamp);

  /**
   * Accept operation for the visitor pattern.
   *
   * @param[in]     visitor     Reference to the visitor object.
   */
  void accept (CUTS_System_Metrics_Visitor & visitor) const;

private:
  /// Number of samples in the timing metric
  size_t count_;

  /// Best execution timing metric.
  ACE_Time_Value best_time_;

  /// Worse execution timing metric.
  ACE_Time_Value worse_time_;

  /// Total execution timing metric.
  ACE_Time_Value total_time_;

  /// The timestamp of the metrics.
  ACE_Time_Value timestamp_;
};

/**
 * Adds to CUTS_Time_Metric objects.
 *
 * @param[in]     lhs     Left-hand side of the operator
 * @param[in]     rhs     Right-hand side of the operator
 * @return        The sum of both input values.
 */
const CUTS_Time_Metric operator + (const CUTS_Time_Metric & lhs,
                                   const CUTS_Time_Metric & rhs);

#if defined (__CUTS_INLINE__)
#include "cuts/Time_Metric.inl"
#endif

#endif  // !defined _CUTS_TIME_METRIC_H_
