// -*- C++ -*-

//=============================================================================
/**
 * @file    Time_Measurement.h
 *
 * Mechanisms for observing and collecting statistics on time values.
 *
 * $Id$
 *
 * @author  James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_TIME_MEASUREMENT_H_
#define _CUTS_TIME_MEASUREMENT_H_

#include "cuts/Timestamp_Metric.h"

// Forward decl.
class CUTS_Metrics_Visitor;

//=============================================================================
/**
 * @ingroup benchmarking
 * @class CUTS_Time_Measurement
 *
 * Timing operations using collecting timing information. This class
 * contains operations that assist with collecting timing measurements such
 * as the maximum and minimum timing values. Also, this class will accumulate
 * timing values and keep track of the number of timing samples.
 *
 * @todo Create an init () method that allows the time values to be
 *       initialized in a single call, instead of in a piecemeal fashion.
 */
//=============================================================================

class CUTS_Export CUTS_Time_Measurement : public CUTS_Timestamp_Metric
{
public:
  /// Constructor.
  CUTS_Time_Measurement (void);

  /**
   * Copy constructor.
   *
   * @param[in]       time      The source object.
   */
  CUTS_Time_Measurement (const CUTS_Time_Measurement & time);

  /// Destructor.
  ~CUTS_Time_Measurement (void);

  /// Reset all the timing values.
  void reset (void);

  /**
   * Add a new time value to the calculations.
   *
   * @param[in]       tv        The source time value.
   */
  const CUTS_Time_Measurement & operator += (const ACE_Time_Value & tv);
  const CUTS_Time_Measurement & operator += (const CUTS_Time_Measurement & tm);

  /// Assignment operator.
  const CUTS_Time_Measurement & operator = (const CUTS_Time_Measurement & tm);

  /**
   * Get the minimum observed time value during this collection
   * period.
   *
   * @return          The minimun time value.
   */
  ACE_Time_Value & minimum (void);

  /**
   * @overload
   */
  const ACE_Time_Value & minimum (void) const;

  /**
   * Get the maximum observed time value during this collection
   * period.
   *
   * @return          The minimun time value.
   */
  ACE_Time_Value & maximum (void);

  /**
   * @overload
   */
  const ACE_Time_Value & maximum (void) const;

  /**
   * Get the total time recorded in the timing measurement. The total time
   * is the summation of all the time values recorded using the
   * operator += (const ACE_Time_Value & tv) method.
   *
   * @return      The total of all time values.
   */
  ACE_Time_Value & total (void);

  /**
   * @overload
   */
  const ACE_Time_Value & total (void) const;

  /**
   * Get the number of time measurements.
   *
   * @return      The number of time measurements.
   */
  size_t count (void) const;

  /**
   * Set the number of time measurements.
   *
   * @param[in]   n     Number of time measurements.
   */
  void count (size_t n);

  /**
   * Accept the visitor object.
   *
   * @param[in]     visitor       The target visitor object.
   */
   void accept (CUTS_Metrics_Visitor & visitor) const;

private:
  /// Number of timing measurements.
  size_t count_;

  /// Accumulation of time values.
  ACE_Time_Value total_;

  /// The slowest/maximum time value.
  ACE_Time_Value max_;

  /// The fastest/minimum time value.
  ACE_Time_Value min_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Time_Measurement.inl"
#endif

#endif  // !defined _CUTS_TIME_MEASUREMENT_H_
