// -*- C++ -*-

//=============================================================================
/**
 * @file      ActivationRecord.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ACTIVATION_RECORD_H_
#define _CUTS_ACTIVATION_RECORD_H_

#include "cuts/Time_Measurement.h"
#include "cuts/Activation_Record_Entry.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include <list>

/// Type defintion for a list of entries.
typedef std::list <CUTS_Activation_Record_Entry>
                   CUTS_Activation_Record_Entries;

/// Type definition for a collection of endpoints
typedef ACE_Hash_Map_Manager <size_t,
                              ACE_Time_Value,
                              ACE_Null_Mutex>
                              CUTS_Activation_Record_Endpoints;

//=============================================================================
/**
 * @class CUTS_Activation_Record
 *
 * @brief Isolated in-memory storage for performance metrics.
 *
 * Activation records do not require any locking mechnisms when
 * logging the performance because each event in the system is allocated
 * is own record. This is possible since we are assuming the number of
 * active events in determistics and of a small amount.
 *
 * Actication records work in conjection with worker actions. While
 * a record is active/open, worker actions can be exectued in its context.
 * Also, depending on the method of execution, the performance of the action
 * is logged in a log format. This allows external clients to iterate over
 * the log to see the performance of each individual action, if needed.
 */
//=============================================================================

class CUTS_Export CUTS_Activation_Record
{
public:
  /// Constructor.
  CUTS_Activation_Record (void);

  /// Destructor.
  ~CUTS_Activation_Record (void);

  /// Activate the activation record.
  void open (void);

  /// Close the activation record.
  void close (void);

  /// Rest the activation record.
  void reset (void);

  /**
   * Determine if the record is open.
   *
   * @retval      true        The record is current open.
   * @retval      false       The record is not open.
   */
  bool is_open (void) const;

  /**
   * Get the start time for the activation record. This is the
   * value stored when open () is invoked.
   *
   * @return      Time value (read-only)
   */
  const ACE_Time_Value & start_time (void) const;

  /**
   * Get the start time for the activation record. This is the
   * value stored when close () is invoked.
   *
   * @param[in]   Time value (read-only).
   */
  const ACE_Time_Value & stop_time (void) const;

  /**
   * Get the entries for the record.
   *
   * @return      Entries for the record.
   */
  const CUTS_Activation_Record_Entries & entries (void) const;

  /**
   * Get the collection of endpoints for this record.
   *
   * @return      Endpoints for the record.
   */
  const CUTS_Activation_Record_Endpoints & endpoints (void) const;

  /**
   * Get the owner of the record.
   *
   * @return      Owner of the record.
   */
  size_t owner (void) const;

  /**
   * Set the owner of the record.
   *
   * @param[in]   owner      Owner of the record.
   */
  void owner (size_t);

  void queue_time (const ACE_Time_Value & queue_time);

  const ACE_Time_Value & queue_time (void) const;

  /// Perform the specified action without any logging.
  template <typename ACTION>
  void perform_action_no_logging (const ACTION & action);

  /// Perform the specified action without any logging.
  template <typename ACTION>
  void perform_action_no_logging (size_t repetitions, const ACTION & action);

  /// Perform the specified action and log its performance.
  template <typename ACTION>
  void perform_action (const ACTION & action);

  /// Perform the specified action and log its performance.
  template <typename ACTION>
  void perform_action (size_t repetitions, const ACTION & action);

  /**
   * Log an endpoint to the activation record. This will store the
   * time of completion (TOC) for the endpoint, which is contained
   * as an \a action.
   *
   * @param[in]         uid         Unique id for the endpoint.
   * @param[in]         action      The action/endpoint.
   */
  void log_endpoint (size_t uid);

private:
  /// Log the timing measurement.
  void log_time_measurement (size_t reps, long worker_id, long action_id);

  /// Active state of the record.
  bool active_;

  /// Owner of the record.
  size_t owner_;

  /// The start for the activation record.
  ACE_Time_Value start_time_;

  /// The stop time for the activation record.
  ACE_Time_Value stop_time_;

  /// Start time of the operation.
  ACE_Time_Value action_state_time_;

  /// Stop time of the operation.
  ACE_Time_Value action_stop_time_;

  /// Queuing time for the event relating to this record.
  ACE_Time_Value queue_time_;

  /// Entries in the activation record.
  CUTS_Activation_Record_Entries entries_;

  /// Collection of exit points
  CUTS_Activation_Record_Endpoints endpoints_;

  // prevent the following operations
  CUTS_Activation_Record (const CUTS_Activation_Record &);
  const CUTS_Activation_Record & operator = (const CUTS_Activation_Record &);
};

#if defined (__CUTS_INLINE__)
#include "cuts/Activation_Record.inl"
#include "cuts/Activation_Record_T.inl"
#endif

#include "cuts/Activation_Record_T.cpp"

#endif  // !defined _CUTS_ACTIVATION_RECORD_H_
