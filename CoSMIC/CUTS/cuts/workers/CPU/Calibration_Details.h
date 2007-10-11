// -*- C++ -*-

//=============================================================================
/**
 * @file      Calibration_Detail.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CPU_WORKER_CALIBRATION_DETAILS_H_
#define _CUTS_CPU_WORKER_CALIBRATION_DETAILS_H_

#include "cuts/config.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Containers_T.h"
#include "ace/Null_Mutex.h"

//=============================================================================
/**
 * @struct CUTS_CPU_Calibration_Details_Log_Entry
 *
 * Entry for CUTS_CPU_Calibration_Details_Log. It contains the average
 * measured execution time and the average error in the measured execution
 * time. The average error can be calculated using the following formula:
 * (average - expected) / expected.
 */
//=============================================================================

struct CUTS_CPU_Calibration_Details_Log_Entry
{
  /// The average execution time.
  double average_time_;

  /// The average error in the measured execution time.
  double average_error_;

  /// The percentage of error.
  double percent_error_;

  /// The variance of the results.
  double variance_;

  /// The standard deviation of the results.
  double stddev_;

  /// The standard error of the results.
  double stderr_;
};

/// Type definition of the log that contains the measured averages for
/// each specified execution time.
typedef
  ACE_Hash_Map_Manager <
  size_t, CUTS_CPU_Calibration_Details_Log_Entry *, ACE_Null_Mutex>
  CUTS_CPU_Calibration_Details_Log;

/// Type definition for the results of a calibration run.
typedef
  ACE_Array <size_t> CUTS_CPU_Calibration_Results;

//=============================================================================
/**
 * @class CUTS_CPU_Calibration_Details
 *
 * Calibration details for the CPU worker. The details include the
 * maximum, minimum, and average error of the measured execution
 * time from the expected executon time over all collected execution
 * times.
 *
 * @todo Store individual metrics for each execution time that is used
 *       to compute the statistical data.
 */
//=============================================================================

class CUTS_CPU_Calibration_Details
{
public:
  /// Default contructor.
  CUTS_CPU_Calibration_Details (void);

  /// Destructor.
  ~CUTS_CPU_Calibration_Details (void);

  /**
   * Process the results of a single run. The processed results
   * are stored in the log for later usage.
   *
   * @param[in]     msec        The expected execution time.
   * @param[in]     results     The measured execution times.
   * @param[out]    entry       Pointer to the log entry.
   */
  int process (size_t msec,
               const CUTS_CPU_Calibration_Results & results,
               CUTS_CPU_Calibration_Details_Log_Entry * & entry);

  /**
   * Get a reference to the log. The client is not allowed to
   * change the contents of the log.
   *
   * @return      Reference to the log.
   */
  const CUTS_CPU_Calibration_Details_Log & log (void) const;

  double min_error (void) const;

  double max_error (void) const;

  double average_percent_error (void) const;

  size_t count (void) const;

  void reset (void);

private:
  /**
   * Calculate the standard deviation of the results. The results
   * are compared against the expected \a msec count.
   *
   * @param[in]     msec          The expected execution time.
   * @param[in]     results       The source measurements.
   * @return        The standard deviation of \a results.
   */
  double calculate_variance (size_t msec,
                             const CUTS_CPU_Calibration_Results & results);

  /// The maximum percentage of error.
  double max_error_;

  /// The mininum pertantage of error.
  double min_error_;

  /// The sum of the percentage error.
  double percent_error_sum_;

  /// Number of items in sum.
  size_t count_;

  /// Log of the measured execution times.
  CUTS_CPU_Calibration_Details_Log log_;
};

#if defined (__CUTS_INLINE__)
#include "Calibration_Details.inl"
#endif

#endif  // !defined _CUTS_CPU_WORKER_CALIBRATION_DETAILS_H_
