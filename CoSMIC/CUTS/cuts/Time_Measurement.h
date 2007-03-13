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

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif  // ACE_LACKS_PRAGMA_ONCE

#include "cuts/config.h"
#include "cuts/CUTS_export.h"
#include "ace/Containers_T.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_sys_time.h"

/// Type definition for the time measurement history.
typedef ACE_Array <ACE_Time_Value> CUTS_Time_Value_History;

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

class CUTS_Export CUTS_Time_Measurement
{
public:
  /// Constructor.
  CUTS_Time_Measurement (size_t history = 0);

  /// Copy constructor.
  CUTS_Time_Measurement (const CUTS_Time_Measurement & time);

  /// Destructor.
  ~CUTS_Time_Measurement (void);

  /// Reset all the timing values.
  void reset (void);

  /// Increment the timing by specified amount of milliseconds.
  void operator += (const ACE_Time_Value & tv);

  /// Get the minimum time value.
  const ACE_Time_Value & minimum (void) const;

  /// Get the maximum time value.
  const ACE_Time_Value & maximum (void) const;

  /// Get the total time recorded in the timing measurement.
  const ACE_Time_Value & accumulation (void) const;

  /// Get the number of time measurements.
  size_t count (void) const;

  /**
   * Get the history of the collected metrics.
   *
   * @return  The history of the collected metrics.
   */
  const CUTS_Time_Value_History & history (void) const;

private:
  /// Number of timing measurements.
  size_t count_;

  /// Accumulation of time values.
  ACE_Time_Value sum_;

  /// The slowest/maximum time value.
  ACE_Time_Value max_;

  /// The fastest/minimum time value.
  ACE_Time_Value min_;

  /// The history of the time measurements.
  CUTS_Time_Value_History history_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Time_Measurement.inl"
#endif

#endif  // !defined _CUTS_TIME_MEASUREMENT_H_
