// -*- C++ -*-

//=============================================================================
/**
 * @file      Process_Log.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PROCESS_LOG_H_
#define _PROCESS_LOG_H_

#include /**/ "ace/pre.h"

#include "cuts/config.h"
#include "ace/SString.h"
#include "ace/Thread_Mutex.h"
#include "ace/Containers_T.h"
#include "ace/iosfwd.h"

#define PROCESS_LOG_NAME_MAX_LENGTH  256

//=============================================================================
/**
 * @struct Process_Log_Entry
 *
 * Data representation of an in the process log database.
 */
//=============================================================================

struct Process_Log_Entry
{
  /// The active state of the entry.
  bool active_;

  /// Process id for the entry.
  pid_t pid_;

  /// Human readable name of the process.
  char name_[PROCESS_LOG_NAME_MAX_LENGTH];

  /**
   * Test the log entry for equality. Two log entries are equal
   * if both have the same name. We do not care about the process's
   * id.
   *
   * @param[in]       rhs       Right hand side of the operator.
   * @retval          true      The log entries are equal.
   * @retval          false     The log entries are not equal.
   */
  inline bool operator == (const Process_Log_Entry & rhs)
  {
    return ACE_OS::strcmp (this->name_, rhs.name_) == 0;
  }
};

/// Type definition for a listing of processes.
typedef ACE_Unbounded_Set <Process_Log_Entry> Process_List;

//=============================================================================
/**
 * @class Process_Log
 *
 * Logging mechanism for process spawned by a process manager. The
 * Process_Log is responsible for serializing the state of process.
 * In the case of failure/recovery, the process manager can learn
 * about which processes it was managing.
 */
//=============================================================================

class Process_Log
{
public:
  /// Default constructor.
  Process_Log (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     log       Name of the log.
   */
  Process_Log (const char * log);

  /// Destructor
  ~Process_Log (void);

  /**
   * Set the name of the log file.
   *
   * @param[in]     log       Name of the log.
   */
  void log_file (const char * log);

  /**
   * Get the name of the log file.
   *
   * @return      Name of the log file (including path).
   */
  const ACE_CString & log_file (void) const;

  bool process_spawn (const ACE_CString & name, pid_t id);

  bool process_exit (pid_t id);

  bool get_active_processes (Process_List & list);

  bool clean (size_t * active_count = 0);

private:
  static size_t batch_read (std::istream & in,
                            Process_Log_Entry * buffer,
                            size_t bufsize);

  /// Name of the log file.
  ACE_CString log_file_;

  /// Locking mechanism for synchronized access.
  ACE_Thread_Mutex lock_;
};

#if defined (__CUTS_INLINE__)
#include "Process_Log.inl"
#endif

#include /**/ "ace/post.h"

#endif  // _PROCESS_LOG_H_
