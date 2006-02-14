// -*- C++ -*-

#ifndef _CUTS_TIME_METRIC_H_
#define _CUTS_TIME_METRIC_H_

#include "cuts/config.h"
#include "ace/Time_Value.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Guard_T.h"

//=============================================================================
/**
 * @class CUTS_Time_Metric
 */
//=============================================================================

class CUTS_Export CUTS_Time_Metric
{
  friend const CUTS_Time_Metric & operator + (
    CUTS_Time_Metric & lhs, const CUTS_Time_Metric & rhs);

public:
  /// Constructor.
  CUTS_Time_Metric (void);

  /// Copy constructor.
  CUTS_Time_Metric (const CUTS_Time_Metric & tm);

  /// Destructor.
  ~CUTS_Time_Metric (void);

  /// Number of samples in the timing metric.
  long count (void);

  /// Best execution timing metric.
  long best_time (void);

  /// Worse execution timing metric.
  long worse_time (void);

  /// Average execution timing metric.
  long average_time (void);

  /// Set the execution timing metrics.
  void update (size_t count, long avg, long best, long worse);

  /// Reset all the timing metrics.
  void reset (void);

  const CUTS_Time_Metric & operator = (const CUTS_Time_Metric & tm);

  const CUTS_Time_Metric & operator += (const CUTS_Time_Metric & metric);

private:
  /// Number of samples in the timing metric
  size_t count_;

  /// Best execution timing metric.
  ACE_Time_Value best_time_;

  /// Worse execution timing metric.
  ACE_Time_Value worse_time_;

  /// Average execution timing metric.
  ACE_Time_Value average_time_;

  /// Locking mechanism for sychronization.
  ACE_RW_Thread_Mutex lock_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Time_Metric.inl"
#endif

#endif  // !defined _CUTS_TIME_METRIC_H_
