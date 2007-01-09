// -*- C++ -*-

//=============================================================================
/**
 * @file      Activation_Record_Entry.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ACTIVATION_RECORD_ENTRY_H_
#define _CUTS_ACTIVATION_RECORD_ENTRY_H_

#include "cuts/CUTS_export.h"
#include "ace/Time_Value.h"

//=============================================================================
/**
 * @class CUTS_Activation_Record_Entry
 *
 * Entries for actions in the activation record.
 */
//=============================================================================

class CUTS_Export CUTS_Activation_Record_Entry
{
public:
  /// Default constructor.
  CUTS_Activation_Record_Entry (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       reps          Number of repetitions.
   * @param[in]       worker_id     Id of the worker.
   * @param[in]       action_id     Id of the action.
   * @param[in]       start         Start time of the action.
   * @param[in]       stop          Stop time of the action.
   */
  CUTS_Activation_Record_Entry (size_t reps,
                                long worker_id,
                                long action_id,
                                ACE_Time_Value & start,
                                ACE_Time_Value &stop);

  /**
   * Copy constructor.
   *
   * @param[in]     obj       Source object to copy.
   */
  CUTS_Activation_Record_Entry (
    const CUTS_Activation_Record_Entry & entry);

  /**
   * Assignment operator.
   *
   * @param[in]     entry     Source object to copy.
   */
  const CUTS_Activation_Record_Entry &
    operator = (const CUTS_Activation_Record_Entry & entry);

  /// Number of repetitions.
  size_t reps_;

  /// Id is the worker performing the action.
  long worker_id_;

  /// Id of the action for the \a worker_id_.
  long action_id_;

  /// Start time for the entry.
  ACE_Time_Value start_time_;

  /// Stop time for the entry.
  ACE_Time_Value stop_time_;
};

#endif  // !defined _CUTS_ACTIVATION_RECORD_ENTRY_H_
