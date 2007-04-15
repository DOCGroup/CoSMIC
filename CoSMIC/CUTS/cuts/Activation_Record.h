// -*- C++ -*-

//=============================================================================
/**
 * @file      Activation_Record.h
 *
 * @brief     Defines classes related to activation records used
 *            for logging performance metrics.
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ACTIVATION_RECORD_H_
#define _CUTS_ACTIVATION_RECORD_H_

#include "cuts/Time_Measurement.h"
#include "cuts/Time_Value_History.h"
#include "cuts/Activation_Record_Entry.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/OS_NS_sys_time.h"
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
 * Isolated in-memory storage for performance metrics. Activation records
 * do not require any locking mechnisms when logging the performance because
 * each event in the system is allocated is own record. This is possible
 * since we are assuming the number of active events in determistics and
 * of a small amount.
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
  virtual ~CUTS_Activation_Record (void);

  /**
   * Copy constructor.
   *
   * @param[in]       rec       Source record.
   */
  CUTS_Activation_Record (const CUTS_Activation_Record & rec);

  /**
   * Assignment operator.
   *
   * @param[in]       rec       Source record.
   */
  const CUTS_Activation_Record & operator = (const CUTS_Activation_Record & rec);

  /// Open the record.
  void open (void);

  /**
   * Open the record an set its owner.
   *
   * @param[in]       owner     Owner of the record.
   */
  void open (size_t owner);

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

  ACE_Time_Value & start_time (void);

  /**
   * Get the start time for the activation record. This is the
   * value stored when close () is invoked.
   *
   * @param[in]   Time value (read-only).
   */
  const ACE_Time_Value & stop_time (void) const;

  ACE_Time_Value & stop_time (void);

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

  CUTS_Activation_Record_Endpoints & endpoints (void);

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
  void owner (size_t owner = CUTS_UNKNOWN_IMPL);

  /**
   * Set the queueing time for the record.
   *
   * @param[in]     queue_time      The queuing time.
   */
  void queue_time (const ACE_Time_Value & queue_time);

  /**
   * Get the queueing time for the record.
   *
   * @return        The queueing time for the record.
   */
  const ACE_Time_Value & queue_time (void) const;

  /**
   * Perform the specified action without any logging. The \a action
   * is a functor that defines the method operator ().
   *
   * @param[in]     action          The action to execute.
   */
  template <typename ACTION>
  void perform_action_no_logging (const ACTION & action);

  /**
   * Perform the specified action without any logging. This version
   * of the method has a \a repetitions parameter that allows
   * the action to be executed multiple times before returning.
   *
   * @param[in]     repetitions     Number of repetitions
   * @param[in]     action          The action to execute.
   */
  template <typename ACTION>
  void perform_action_no_logging (size_t repetitions,
                                  const ACTION & action);

  /**
   * Perform the specified action and log its performance. Logging
   * the performance of the action entails recording the amount
   * of time it takes to execute the \a action.
   *
   * @param[in]     action          The action to execute.
   */
  template <typename ACTION>
  void perform_action (const ACTION & action);

  /**
   * Perform the specified action and log its performance. Logging
   * the performance of the action entails recording the amount of
   * time it takes to execute the \a action. This version of the
   * method also has a \a repetitions parameter to specify how many
   * times to execute the \a action.
   *
   * @param[in]     repetitions     Number of times to execute action.
   * @param[in]     action          The action to execute.
   */
  template <typename ACTION>
  void perform_action (size_t repetitions, const ACTION & action);

  /**
   * Log an endpoint to the activation record. This will store the
   * time of completion (TOC) for the endpoint.
   *
   * @param[in]         uid         Unique id for the endpoint.
   */
  void log_endpoint (size_t uid);

  void get_duration (ACE_Time_Value & duration) const;

private:
  /**
   * Helper method to copy the endpoints.
   *
   * @param[in]     endpoints       The source endpoints.
   */
  void copy_endpoints (const CUTS_Activation_Record_Endpoints & endpoints);

  /// Log the timing measurement.
  void log_time_measurement (size_t reps, long worker_id, long action_id);

  /// Active state of the record.
  bool active_;

  /// Owner of the record.
  size_t owner_;

  /// The timing stop watch for the activation record.
  CUTS_Time_Value_Ex stopwatch_;

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
};

//=============================================================================
/**
 * @class CUTS_Cached_Activation_Record
 */
//=============================================================================

class CUTS_Export CUTS_Cached_Activation_Record :
  public CUTS_Activation_Record
{
public:
  /// Default constructor.
  CUTS_Cached_Activation_Record (void);

  /// Destructor.
  virtual ~CUTS_Cached_Activation_Record (void);

  /**
   * Add a new node onto the chain.
   *
   * @param[in]       next        Pointer to the next node.
   */
  void set_next (CUTS_Cached_Activation_Record * next);

  /**
   * Get the next node on the chain.
   *
   * @return          Pointer to the next record.
   */
  CUTS_Cached_Activation_Record * get_next (void);

private:
  /// Pointer to the next record.
  CUTS_Cached_Activation_Record * next_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Activation_Record.inl"
#include "cuts/Activation_Record_T.inl"
#endif

#include "cuts/Activation_Record_T.cpp"

#endif  // !defined _CUTS_ACTIVATION_RECORD_H_
