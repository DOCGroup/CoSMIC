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
 * is no overhead is locking. Lastly, it must be explicitly initialized and
 * finalized.
 */
//=============================================================================

class CUTS_Export CUTS_Thread_Activation_Record
{
public:
  /// Initialize the singleton. This should be invoked from the
  /// main thread of control.
  static int init_singleton (void);

  /// Finalize the singleton. This should be invoked from the
  /// main thread of control after all threads are gone.
  static int fini_singleton (void);

  /// Get the activation record for a specific thread.
  static CUTS_Activation_Record * instance (void);

private:
  /// Default constructor.
  CUTS_Thread_Activation_Record (void);

  /// Destructor.
  ~CUTS_Thread_Activation_Record (void);

  /// Singleton instance for thread-specific storage.
  typedef ACE_TSS <CUTS_Activation_Record> Thread_Record;

  /// Singleton instance.
  static Thread_Record * instance_;

  /// Number of threads accessing this object.
  static ACE_Thread_Mutex lock_;

  static size_t count_;

  // prevent the following operations
  CUTS_Thread_Activation_Record (const CUTS_Thread_Activation_Record &);

  const CUTS_Thread_Activation_Record &
    operator = (const CUTS_Thread_Activation_Record &);
};

/// macro to simplify accessing activation record for a thread.
#define CUTS_THR_ACTIVATION_RECORD() \
  CUTS_Thread_Activation_Record::instance ()

#if defined (__CUTS_INLINE__)
#include "Thread_Activation_Record.inl"
#endif

#endif  // !defined _CUTS_THREAD_ACTIVATION_RECORD_H_
