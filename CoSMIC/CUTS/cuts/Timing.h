// -*- C++ -*-

//=============================================================================
/**
 * @file    Timing.h
 *
 * $Id$
 *
 * This file contains the classes for performing timing operations in CUTS.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_TIMING_H_
#define _CUTS_TIMING_H_

#include "cuts/config.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_sys_time.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif  // ACE_LACKS_PRAGMA_ONCE

//=============================================================================
/**
 * @class CUTS_Time_Measurement
 *
 * @brief Timing operations using collecting timing information.
 *
 * This class contains operations that assist with collecting timing
 * measurements such as the maximum and minimum timing values. Also,
 * this class will accumulate timing values and keep track of the number
 * of timing samples.
 */
//=============================================================================

class CUTS_Export CUTS_Time_Measurement
{
public:
  /// Constructor.
  CUTS_Time_Measurement (void);

  /// Copy constructor.
  CUTS_Time_Measurement (const CUTS_Time_Measurement &time);

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

private:
  /// Number of timing measurements.
  size_t count_;

  /// Accumulation of time values.
  ACE_Time_Value sum_;

  /// The slowest/maximum time value.
  ACE_Time_Value max_;

  /// The fastest/minimum time value.
  ACE_Time_Value min_;
};

//=============================================================================
/**
 * @class CUTS_Timer
 *
 * @brief Timing operations using collecting timing information.
 *
 * This class contains operations that assist with collecting timing
 * measurements such as the maximum and minimum timing values. Also,
 * this class will accumulate timing values and keep track of the number
 * of timing samples.
 */
//=============================================================================

class CUTS_Export CUTS_Timer
{
public:
  /// Constructor.
  CUTS_Timer (void);

  /// Destructor.
  ~CUTS_Timer (void);

  /// Get the amount of time elapsed since the timer started.
  ACE_Time_Value elapsed (void) const;

  /// Get the current value of the timer.
  const ACE_Time_Value & time (void) const;

private:
  /// The current timer vulue.
  ACE_Time_Value time_;
};

#if defined (__CUTS_INLINE__)
# include "cuts/Timing.inl"
#endif // defined __CUTS_INLINE__

#endif  // !defined _CUTS_TIMING_H_
