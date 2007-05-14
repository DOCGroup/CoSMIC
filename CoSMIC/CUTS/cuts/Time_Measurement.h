// -*- C++ -*-

//=============================================================================
/**
 * @file    Time_Measurement.h
 *
 * $Id$
 *
 * This file contains the classes for performing timing operations in CUTS.
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
 * @class CUTS_Time_Measurement
 *
 * Timing operations using collecting timing information. This class
 * contains operations that assist with collecting timing measurements such
 * as the maximum and minimum timing values. Also, this class will accumulate
 * timing values and keep track of the number of timing samples.
 */
//=============================================================================

class CUTS_Export CUTS_Time_Measurement : public CUTS_Timestamp_Metric
{
public:
  /// Constructor.
  CUTS_Time_Measurement (void);

  /// Copy constructor.
  CUTS_Time_Measurement (const CUTS_Time_Measurement & time);

  /// Destructor.
  ~CUTS_Time_Measurement (void);

  /// Reset all the timing values.
  void reset (void);

  /// Increment the timing by specified amount of milliseconds.
  void operator += (const ACE_Time_Value & timing);

  /// Get the minimum time value.
  ACE_Time_Value & minimum (void);
  const ACE_Time_Value & minimum (void) const;

  /// Get the maximum time value.
  ACE_Time_Value & maximum (void);
  const ACE_Time_Value & maximum (void) const;

  /// Get the total time recorded in the timing measurement.
  ACE_Time_Value & total (void);
  const ACE_Time_Value & total (void) const;

  /// Get the number of time measurements.
  size_t count (void) const;

  /// Set the count.
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
