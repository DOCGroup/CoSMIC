// $Id$

#include "Node_Daemon_i.h"

#if !defined (__CUTS_INLINE__)
#include "Node_Daemon_i.inl"
#endif

#include "Active_Process.h"
#include "Process_Log.h"
#include "Server_Options.h"
#include "ace/INET_Addr.h"
#include "ace/Null_Mutex.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/Process.h"
#include "ace/Process_Manager.h"
#include "ace/Singleton.h"

#define PROCESS_LOG() \
  ACE_Singleton <Process_Log, ACE_Null_Mutex>::instance ()

//
// CUTS_Node_Daemon_i
//
CUTS_Node_Daemon_i::CUTS_Node_Daemon_i (::CORBA::ORB_ptr orb)
  : event_handler_ (*this),
    timer_ (-1),
    orb_ (::CORBA::ORB::_duplicate (orb))
{
  this->init ();
  this->recover ();
}

//
// ~CUTS_Node_Daemon_i
//
CUTS_Node_Daemon_i::~CUTS_Node_Daemon_i (void)
{
  // @@ We should have a flag specifying how to shutdown,
  // e.g., force|nowait|wait

  // Wait for the process manager thread to return and it's
  // event handler. This means waiting for all processes
  // created by this process manager to exit.
  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info (node daemon): waiting for %u tasks(s) to exit\n",
                    this->pm_.managed ()));
  this->pm_.wait ();

  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info (node daemon): deactivating the process listener\n"));
  this->event_handler_.deactivate ();

  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info (node daemon) : deactivating the timer queue\n"));
  this->timer_queue_.deactivate ();
  this->timer_queue_.cancel (this->timer_);
}

//
// spawn_task
//
CORBA::ULong CUTS_Node_Daemon_i::spawn_task (const CUTS::Node_Task & task)
{
  if (this->process_map_.find (task.name.in ()) == 0)
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (node daemon): '%s' task already exists\n",
                       task.name.in ()),
                       1);
  }

  // Prepare the command line for the task.
  this->p_options_.command_line ("%s %s",
                                 task.execname.in (),
                                 task.arguments.in ());

  // Spawn the new task and register the <event_handler_> as the
  // notifier for process termination.
  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info (node daemon): spawning new process ['%s']\n",
                    this->p_options_.command_line_buf ()));

  pid_t pid = this->pm_.spawn (this->p_options_,
                               &this->event_handler_);

  if (pid != ACE_INVALID_PID && pid != 0)
  {
    int retval = this->process_map_.bind (task.name.in (), pid);

    if (retval == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (node daemon): failed to save spawned task\n"));
    }
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (node daemon): failed to spawn task [%m]\n"));
  }

  return 0;
}

//
// kill
//
CORBA::ULong CUTS_Node_Daemon_i::kill_task (const char * name)
{
  // Locate the pid for the task.
  pid_t pid = 0;
  int retval = this->process_map_.find (name, pid);

  if (retval == 0)
  {
    // Terminate the process.
    retval = this->pm_.terminate (pid);

    if (retval == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (node daemon): failed to terminate %s\n",
                  name));
    }
    else
    {
      // Remove the process from the proces_map_.
      this->unmanage (pid);
    }
  }
  else
  {
    ACE_ERROR ((LM_WARNING,
                "*** warning (node daemon): %s was not found\n",
                name));
  }

  return retval;
}

//
// unmanage
//
void CUTS_Node_Daemon_i::unmanage (pid_t pid)
{
  // Lock down the process map and get an iterator.
  Process_Map::ITERATOR iter (this->process_map_);

  do
  {
    // Prevent the process_map_ from being modified.
    ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, this->process_map_.mutex ());

    for (; !iter.done (); iter ++)
    {
      if (iter->item () == pid)
        break;
    }
  } while (0);

  if (!iter.done ())
    this->process_map_.unbind (iter);
}

//
// init
//
void CUTS_Node_Daemon_i::init (void)
{
  // Initialize the contained process manager.
  this->pm_.open (ACE_Process_Manager::DEFAULT_SIZE,
                  this->event_handler_.reactor ());

  // Set the process log for the node daemon.
  PROCESS_LOG ()->log_file ("cutsnode_d.dat");

  // Initialize the default <p_options_>.
  this->p_options_.avoid_zombies (0);
  this->p_options_.setgroup (0);

#if defined (ACE_WIN32)
  this->p_options_.creation_flags (CREATE_NEW_PROCESS_GROUP |
                                   CREATE_DEFAULT_ERROR_MODE);
#endif

  // We need to set the working directory for the process
  // if it was specified as a command-line option.
  if (!SERVER_OPTIONS ()->init_dir_.empty ())
  {
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "*** info: setting working directory to %s\n",
                      SERVER_OPTIONS ()->init_dir_.c_str ()));

    this->p_options_.
      working_directory (SERVER_OPTIONS ()->init_dir_.c_str ());
  }

  // We need to activate the event handler. It is responsible for
  // receiving notifications about processes terminating.
  if (!this->event_handler_.activate ())
  {
    ACE_ERROR ((LM_WARNING,
                "*** warning (node daemon): failed to active event "
                "handler; cannot manager spawned processes\n"));
  }

  // Activate the cleaning thread. It is responsible for scrubbing
  // the process log and removing all invalid entries. Right now,
  // it is set for 300 seconds (i.e., 5 minutes).
  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info (node daemon): activating cleaning thread\n"));

  ACE_Time_Value interval (300);
  ACE_Time_Value abstime =
    this->timer_queue_.timer_queue ()->gettimeofday () + interval;

  this->timer_ =
    this->timer_queue_.schedule (&this->event_handler_, 0, abstime, interval);

  if (this->timer_ != -1)
  {
    this->timer_queue_.activate ();
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (node daemon): failed to activate "
                "cleaning thread\n"));
  }
}

//
// recover
//
size_t CUTS_Node_Daemon_i::recover (void)
{
  size_t count = 0;
  Process_List active_list;

  // Get all the active process in the process log.
  PROCESS_LOG ()->get_active_processes (active_list);
  Process_List::ITERATOR iter (active_list);

  while (iter.done () == 0)
  {
    // Get the next process for the <active_list>. We only need
    // to continue if we successfully have gotten an entry.
    Process_Log_Entry * ple = 0;
    iter.next (ple);

    if (ple == 0)
      continue;

    // Create an <Active_Process> entry so we can actually
    // manage this process using our <Process_Manager>.
    CUTS_Active_Process * a_process = 0;
    ACE_NEW_THROW_EX (a_process,
                      CUTS_Active_Process (ple->pid_),
                      CORBA::NO_MEMORY ());

    if (a_process->running ())
    {
      pid_t pid = this->pm_.spawn (a_process,
                                   this->p_options_,
                                   &this->event_handler_);

      if (pid != ACE_INVALID_PID && pid != 0)
      {
        ++ count;
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
                    "*** error (node daemon): failed to recover pid %d\n",
                    ple->pid_));
      }
    }
    else
    {
      VERBOSE_MESSAGE ((LM_DEBUG,
                        "*** info (node daemon): pid %u is not active\n",
                        ple->pid_));

      // Remove the entry from the log and eelete its resources.
      if (PROCESS_LOG ()->process_exit (ple->pid_))
      {
        VERBOSE_MESSAGE ((LM_DEBUG,
                          "*** info (node daemon):  removed pid %u "
                          "from log\n",
                          ple->pid_));
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
                    "*** error (node daemon): failed to remove pid %u "
                    "from log\n",
                    ple->pid_));
      }

      delete a_process;
      a_process = 0;
    }

    // Advance to the next element in the collection.
    iter.advance ();
  }

  return 0;
}

//
// clean
//
void CUTS_Node_Daemon_i::clean (void)
{
  size_t active_count = 0;
  bool retval = PROCESS_LOG ()->clean (&active_count);

  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info (node daemon): %s the log file [active=%u]\n",
                    retval ? "successfully cleaned" : "failed to clean",
                    active_count));
}

//
// shutdown
//
void CUTS_Node_Daemon_i::shutdown (void)
{
  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info: (node daemon): shutting down...\n"));

  this->orb_->shutdown ();
}
