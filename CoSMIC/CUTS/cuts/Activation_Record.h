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

#include "cuts/Activation_Record_Entry.h"
#include "cuts/Log_T.h"
#include "cuts/Time_Measurement.h"
#include "cuts/Time_Value_History.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/High_Res_Timer.h"
#include "ace/OS_NS_sys_time.h"

/// Type definition for a collection of endpoints
typedef ACE_Hash_Map_Manager <size_t,
                              ACE_Time_Value,
                              ACE_Null_Mutex>
                              CUTS_Activation_Record_Endpoints;

typedef CUTS_Log_T <CUTS_Activation_Record_Entry,
                    ACE_Null_Mutex> CUTS_Activation_Record_Entry_Log;

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

  CUTS_Activation_Record_Entry_Log & entries (void);

  /**
   * @overload
   */
  const CUTS_Activation_Record_Entry_Log & entries (void) const;

  //===========================================================================
  // @@ templates

  /**
   * Perform the specified action without any logging. The \a action
   * is a functor that defines the method operator ().
   *
   * @param[in]     action          The action (functor) to execute.
   */
  template <typename R, typename F, typename T>
  void perform_action_no_logging (R (F::*method) (void), T & obj);

  /**
   * Perform the specified action without any logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   */
  template <typename R, typename F, typename T,
            typename P1, typename A1>
  void perform_action_no_logging (R (F::*method) (P1), T & obj, A1 arg1);

  /**
   * Perform the specified action without any logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2,
            typename A1, typename A2>
  void perform_action_no_logging (R (F::*method) (P1, P2), T & obj,
                                  A1 arg1, A2 arg2);

  /**
   * Perform the specified action without any logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   * @param[in]     arg3            The third argument.
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2, typename P3,
            typename A1, typename A2, typename A3>
  void perform_action_no_logging (R (F::*method) (P1, P2, P3), T & obj,
                                  A1 arg1, A2 arg2, A3 arg3);

  /**
   * Perform the specified action without any logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   * @param[in]     arg3            The third argument.
   * @param[in]     arg4            The fourth argument.
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2, typename P3, typename P4,
            typename A1, typename A2, typename A3, typename A4>
  void perform_action_no_logging (R (F::*method) (P1, P2, P3, P4), T & obj,
                                  A1 arg1, A2 arg2, A3 arg3, A4 arg4);

  /**
   * Perform the specified action without any logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   * @param[in]     arg3            The third argument.
   * @param[in]     arg4            The fourth argument.
   * @param[in]     arg5            The fifth argument.
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2, typename P3, typename P4, typename P5,
            typename A1, typename A2, typename A3, typename A4, typename A5>
  void perform_action_no_logging (R (F::*method) (P1, P2, P3, P4, P5), T & obj,
                                  A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5);

  /**
   * Perform the specified action with logging. The \a action
   * is a functor that defines the method operator ().
   *
   * @param[in]     action          The action (functor) to execute.
   */
  template <typename R, typename F, typename T>
  void perform_action (size_t uid, size_t type,
                       R (F::*method) (void), T & obj);

  /**
   * Perform the specified action with logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   */
  template <typename R, typename F, typename T,
            typename P1, typename A1>
  void perform_action (size_t uid, size_t type,
                       R (F::*method) (P1), T & obj, A1 arg1);

  /**
   * Perform the specified action with logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2,
            typename A1, typename A2>
  void perform_action (size_t uid, size_t type,
                       R (F::*method) (P1, P2), T & obj,
                       A1 arg1, A2 arg2);

  /**
   * Perform the specified action with logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   * @param[in]     arg3            The third argument.
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2, typename P3,
            typename A1, typename A2, typename A3>
  void perform_action (size_t uid, size_t type,
                       R (F::*method) (P1, P2, P3), T & obj,
                       A1 arg1, A2 arg2, A3 arg3);

  /**
   * Perform the specified action with logging. The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   * @param[in]     arg3            The third argument.
   * @param[in]     arg4            The fourth argument.
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2, typename P3, typename P4,
            typename A1, typename A2, typename A3, typename A4>
  void perform_action (size_t uid, size_t type,
                       R (F::*method) (P1, P2, P3, P4), T & obj,
                       A1 arg1, A2 arg2, A3 arg3, A4 arg4);

  /**
   * Perform the specified action with logging . The \a action
   * is a functor that defines the method operator (). The \a action
   * also accepts 1 parameter.
   *
   * @param[in]     action          The action (functor) to execute.
   * @param[in]     arg1            The first argument
   * @param[in]     arg2            The second argument
   * @param[in]     arg3            The third argument.
   * @param[in]     arg4            The fourth argument.
   * @param[in]     arg5            The fifth argument.
   */
  template <typename R, typename F, typename T,
            typename P1, typename P2, typename P3, typename P4, typename P5,
            typename A1, typename A2, typename A3, typename A4, typename A5>
  void perform_action (size_t uid,
                       size_t type, R (F::*method) (P1, P2, P3, P4, P5),
                       T & obj,
                       A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5);

  /**
   * Log an endpoint to the activation record. This will store the
   * time of completion (TOC) for the endpoint.
   *
   * @param[in]         uid         Unique id for the endpoint.
   */
  void log_endpoint (size_t uid);

  /**
   * Get how long the record was open. This is a measure of the
   * processing time for a the recorded workload.
   *
   * @param[out]      duration      How long the record was open.
   */
  void get_duration (ACE_Time_Value & duration) const;

private:
  /**
   * Helper method to copy the endpoints.
   *
   * @param[in]     endpoints       The source endpoints.
   */
  void copy_endpoints (const CUTS_Activation_Record_Endpoints & endpoints);

  void perform_action_i (size_t uid, size_t type);

  /// Active state of the record.
  bool active_;

  /// Owner of the record.
  size_t owner_;

  /// The timing stop watch for the activation record.
  CUTS_Time_Value_Ex stopwatch_;

  /// Queuing time for the event relating to this record.
  ACE_Time_Value queue_time_;

  /// High resolution timer for measuring actions.
  ACE_High_Res_Timer action_timer_;

  /// Collection of exit points
  CUTS_Activation_Record_Endpoints endpoints_;

  /// Action entries in the log.
  CUTS_Activation_Record_Entry_Log entries_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Activation_Record.inl"
#include "cuts/Activation_Record_T.inl"
#endif

#include "cuts/Activation_Record_T.cpp"

#endif  // !defined _CUTS_ACTIVATION_RECORD_H_
