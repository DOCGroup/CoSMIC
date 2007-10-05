// -*- C++ -*-

//=============================================================================
/**
 * @file    Port_Measurement.h
 *
 * $Id$
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_PORT_MEASUREMENT_H_
#define _CUTS_PORT_MEASUREMENT_H_

#include "cuts/Time_Measurement.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/SString.h"
#include "ace/Null_Mutex.h"

// Forward decl.
class CUTS_Metrics_Visitor;

/// Collection of endpoints stored by an unique integer id.
typedef ACE_Hash_Map_Manager <
  size_t, CUTS_Time_Measurement *, ACE_Null_Mutex>
  CUTS_Port_Measurement_Endpoint_Map;

//=============================================================================
/**
 * @class CUTS_Port_Measurement
 *
 * Performance measurements for a port operation of a component.
 */
//=============================================================================

class CUTS_Export CUTS_Port_Measurement : public CUTS_Timestamp_Metric
{
public:
  /// Constructor.
  CUTS_Port_Measurement (void);

  /// Destructor.
  ~CUTS_Port_Measurement (void);

  /**
   * Update the processing time for the port.
   *
   * @param[in]     timing      The new processing time.
   */
  void process_time (const ACE_Time_Value & timing);

  /**
   * Get the processing time for the port. The processing time is considered
   * the time from when the event reaches the application level to when the
   * calling thread returns to the middleware level. Use endpoints () if you
   * want to get the time when an the calling thread sent an event to another
   * component.
   *
   * @return        The processing time for the port.
   */
  const CUTS_Time_Measurement & process_time (void) const;

  /// @overload
  CUTS_Time_Measurement & process_time (void);

  /**
   * Update the queuing time for the port.
   *
   * @param[in]     timing      The new queueing time.
   */
  void queuing_time (const ACE_Time_Value & timing);

  /**
   * Get the queuing time the events in at this port. The queuing time only
   * has meaning when the event sinks are asychronous. If the event sinks
   * are sychronous (i.e., blocking) then the queueing time will ALWAYS be
   * zero.
   *
   * @return        The queueing time for the port.
   */
  const CUTS_Time_Measurement & queuing_time (void) const;

  /**
   * @overload
   */
  CUTS_Time_Measurement & queuing_time (void);

  /**
   * Record an exit point measurement for this port.
   *
   * @param[in]       uid       The target uid.
   * @param[in]       tv        The timing value.
   */
  int record_exitpoint (size_t uid, const ACE_Time_Value & tv);

  /// Reset all the collected data.
  void reset (void);

  /// Get the collection of exit points.
  CUTS_Port_Measurement_Endpoint_Map & endpoints (void);

  /// Get the collection of exit points.
  const CUTS_Port_Measurement_Endpoint_Map & endpoints (void) const;

  /**
   * Get the endpoint by its id. The user has the option of creating
   * the endpoint if it does not exist.
   *
   * @param[in]       eid           The endpoint id.
   * @param[in]       tm            Pointer to the located time measurement.
   * @param[in]       auto_create   Create the measurement if not found.
   */
  int endpoint (size_t eid,
                CUTS_Time_Measurement * & tm,
                bool auto_create = true);

  /**
   * Accept the CUTS_Metrics_Visitor visitor object.
   *
   * @param[in]     visitor     The target visitor object.
   */
  void accept (CUTS_Metrics_Visitor & visitor) const;

  int prepare (CUTS_Port_Measurement & pm);

private:
  /// Time taken to complete the port operation.
  CUTS_Time_Measurement process_time_;

  /// Time taken to begin processing a port operation.
  CUTS_Time_Measurement queuing_time_;

  /// Collection of exit times at each endpoint.
  CUTS_Port_Measurement_Endpoint_Map endpoints_;
};

#if defined (__CUTS_INLINE__)
# include "cuts/Port_Measurement.inl"
#endif

#endif  // !defined _CUTS_PORT_MEASUREMENT_H_
