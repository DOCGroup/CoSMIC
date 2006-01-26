// -*- C++ -*-

//=============================================================================
/**
 * @file    PortMeasurement.h
 *
 * $Id$
 *
 * This file contains the classes measuring performance of port operations
 * of a component.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_PORT_MEASUREMENT_H_
#define _CUTS_PORT_MEASUREMENT_H_

#include "cuts/Timing.h"
#include <map>

//=============================================================================
/**
 * @class CUTS_Operation_Measurement
 *
 * @brief Time measurements for a port operation.
 */
//=============================================================================

class CUTS_Export CUTS_Operation_Measurement
{
public:
  /// Constructor.
  CUTS_Operation_Measurement (void);

  /// Copy constructor.
  CUTS_Operation_Measurement (const CUTS_Operation_Measurement &om);

  /// Destructor.
  ~CUTS_Operation_Measurement (void);

  /// Assignment operator
  const CUTS_Operation_Measurement &operator = (const CUTS_Operation_Measurement &om);

  /// Reset all the measurement data.
  void reset (void);

  /// Collect the timing information for the number of repetitions.
  void operator () (size_t reps, const ACE_Time_Value & tv);

  /// Get the number of repetitions collected.
  size_t repetitions (void) const;

  /// Get the current timing measurements.
  const CUTS_Time_Measurement & time (void) const;

private:
  /// Number of repetitions measured.
  size_t reps_;

  /// Timing data for the operation.
  CUTS_Time_Measurement time_;
};

//=============================================================================
/**
 * @class CUTS_Worker_Measurement
 */
//=============================================================================

class CUTS_Export CUTS_Worker_Measurement
{
public:
  /// Type definition for mapping worker operations to timing measurements.
  typedef std::map <long, CUTS_Operation_Measurement> Operation_Map;

  /// Constructor.
  CUTS_Worker_Measurement (void);

  /// Copy constructor.
  CUTS_Worker_Measurement (const CUTS_Worker_Measurement & src);

  /// Destructor.
  virtual ~CUTS_Worker_Measurement (void);

  /// Record an operation time measurement.
  void record_operation (size_t reps, long opid, const ACE_Time_Value &tm);

  /// Get the collection of operations.
  const Operation_Map & operations (void) const;

  /// Get the collection of operations.
  Operation_Map & operations (void);

  /// Assignment operator.
  const CUTS_Worker_Measurement & operator = (
    const CUTS_Worker_Measurement & src);

private:
  /// Mapping of worker operation to timing measurements.
  Operation_Map operations_;
};

//=============================================================================
/**
 * @class CUTS_Port_Measurement
 *
 * @brief Performance measurements for a port operation of a component.
 */
//=============================================================================

class CUTS_Export CUTS_Port_Measurement
{
public:
  /// Type definition for making operation ids to measurement data.
  typedef std::map <long, CUTS_Worker_Measurement> Worker_Map;

  /// Constructor.
  CUTS_Port_Measurement (void);

  /// Destructor.
  ~CUTS_Port_Measurement (void);

  /// Update the time data for processing an event.
  void process_time (const ACE_Time_Value &tv);

  /// Update the time data for receiving a transmitted event.
  void transit_time (const ACE_Time_Value &tv);

  /// Get the time data for processing an event.
  const CUTS_Time_Measurement & process_time (void) const;

  /// Get the time data for receiving a transitted event.
  const CUTS_Time_Measurement & transit_time (void) const;

  /// Record an entry into the port measurements
  void record_entry ( size_t reps, long worker, long opid,
                      const ACE_Time_Value & tm);

  /// Reset all the collected data.
  void reset (void);

  /// Get the collection of worker measurements.
  const Worker_Map & worker_measurements (void) const;

  /// Get the collection of worker measurements.
  Worker_Map & worker_measurements (void);

private:
  /// Time taken to complete the port operation.
  CUTS_Time_Measurement process_time_;

  /// Time taken to begin processing a port operation.
  CUTS_Time_Measurement transit_time_;

  /// Collection of operation measurement data.
  Worker_Map workers_;
};

#if defined (__CUTS_INLINE__)
# include "cuts/PortMeasurement.inl"
#endif  // defined __CUTS_INLINE__

#endif  // !defined _CUTS_PORT_MEASUREMENT_H_
