/* -*- C++ -*- */

//=============================================================================
/**
 * @file      CUTS_Node_Daemon_i.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_NODE_DAEMON_I_H_
#define _CUTS_NODE_DAEMON_I_H_

#include "cuts/config.h"
#include "Node_DaemonS.h"
#include "Node_Daemon_Event_Handler.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Process_Manager.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/SString.h"
#include "ace/Timer_Heap.h"
#include "ace/Timer_Queue_Adapters.h"

//===========================================================================
/**
  * @class CUTS_Node_Daemon_i
  *
  * Main implementation of the Task_Manager interface.
  */
//===========================================================================

class CUTS_Node_Daemon_i :
  public virtual POA_CUTS::Task_Manager
{
public:
  /// Friend class.
  friend class Node_Daemon_Event_Handler;

  /// Default contructor.
  CUTS_Node_Daemon_i (::CORBA::ORB_ptr orb);

  /// Destructor.
  virtual ~CUTS_Node_Daemon_i (void);

  /**
   * Spawn a set of node daemons.
   *
   * @param[in]     task      Task to spawn
   * @return        Number of nodes successfully spawned.
   */
  virtual CORBA::ULong spawn_task (const CUTS::Node_Task & task);

  /**
   * Kill a node in the task manager.
   *
   * @param[in]     name      Name of the task.
   */
  virtual CORBA::ULong kill_task (const char * name);

  /// Shutdown the node daemon server.
  virtual void shutdown (void);

  /// Recover as many processes as possible.
  size_t recover (void);

private:
  /// Initialize the class.
  void init (void);

  /// Unmanage the specified process id.
  void unmanage (pid_t pid);

  /// Cleanup the process log.
  void clean (void);

  /// Type definition of mapping ports to processes.
  typedef ACE_Hash_Map_Manager <ACE_CString,
                                pid_t,
                                ACE_RW_Thread_Mutex> Process_Map;

  /// Mapping of task names to their process ids.
  Process_Map process_map_;

  /// Process manager of the daemon used to spawn managers.
  ACE_Process_Manager pm_;

  /// Event handler for the node daemon.
  Node_Daemon_Event_Handler event_handler_;

  /// Common process options used by the daemon.
  ACE_Process_Options p_options_;

  /// The timer queue for the periodic task.
  ACE_Thread_Timer_Queue_Adapter <ACE_Timer_Heap> timer_queue_;

  /// Timeout value for the cleaning thread.
  long timer_;

  /// Locking mechanism for the mappings.
  ACE_RW_Thread_Mutex lock_;

  /// The ORB hosting the node daemon.
  ::CORBA::ORB_var orb_;
};

#if defined (__CUTS_INLINE__)
#include "Node_Daemon_i.inl"
#endif

#endif  /* !defined _CUTS_NODE_DAEMON_I_H_ */
