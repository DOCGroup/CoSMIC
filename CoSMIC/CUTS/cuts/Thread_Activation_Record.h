// -*- C++ -*-

//=============================================================================
/**
 * @file      Thread_Activation_Record.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_THREAD_ACTIVATION_RECORD_H_
#define _CUTS_THREAD_ACTIVATION_RECORD_H_

#include "cuts/Activation_Record.h"
#include "ace/Thread_Mutex.h"
#include "ace/TSS_T.h"

//=============================================================================
/**
 * @class CUTS_Thread_Activation_Record
 *
 * Stores activation records for each thread. This class can only be used
 * as a pure singleton. It guarantees that any activation record accessed
 * is specific to that thread and not modifiable by other threads. There
 * is no overhead is locking.
 */
//=============================================================================

class CUTS_Export CUTS_Thread_Activation_Record
{
public:
  /**
   * Set the activation record for the calling thread. If there is
   * already a record in the TSS, then it is returned to the caller
   * to do whatever it wants with it.
   *
   * @param[in]     record        Pointer to the record.
   * @return        Pointer to the previously stored record.
   */
  static CUTS_Activation_Record *
    set_record (CUTS_Activation_Record * record);

  /**
   * Get the activation record for the calling thread.
   *
   * @return        Pointer to the activation record.
   */
  static CUTS_Activation_Record * get_record (void);

private:
  /// Singleton instance.
  static ACE_TSS <CUTS_Activation_Record> tss_;

  // prevent the following operations
  CUTS_Thread_Activation_Record (void);
  CUTS_Thread_Activation_Record (const CUTS_Thread_Activation_Record &);
  const CUTS_Thread_Activation_Record &
    operator = (const CUTS_Thread_Activation_Record &);
};

/// macro to simplify accessing activation record for a thread.
#define CUTS_THR_ACTIVATION_RECORD() \
  CUTS_Thread_Activation_Record::get_record ()

#if defined (__CUTS_INLINE__)
#include "Thread_Activation_Record.inl"
#endif

#endif  // !defined _CUTS_THREAD_ACTIVATION_RECORD_H_
