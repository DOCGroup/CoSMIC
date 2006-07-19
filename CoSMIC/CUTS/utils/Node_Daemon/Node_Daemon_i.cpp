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

#define NODE_MANAGER      "NodeManager"

#define MAXHOSTNAME       1024

#define LOCALHOST         "localhost"

namespace CUTS
{
  //
  // Node_Daemon_i
  //
  Node_Daemon_i::Node_Daemon_i (void)
    : event_handler_ (this),
      timer_ (-1)
  {
    // Activate the <event_handler_>.
    bool retval = this->event_handler_.activate ();

    VERBOSE_MESSAGE ((
      LM_DEBUG,
      "%s node daemon event handler\n",
      retval ? "successfully activated" : "failed to activate"));

    // Initialize the contained process manager.
    this->pm_.open (5, this->event_handler_.reactor ());

    this->init ();

    PROCESS_LOG ()->log_file ("cutsnode_d.dat");

    // Activate the cleaning thread.
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "activating cleaning thread\n"));
    ACE_Time_Value interval (300);
    ACE_Time_Value abstime =
      this->timer_queue_.timer_queue ()->gettimeofday () + interval;

    this->timer_ = this->timer_queue_.schedule (this, 0, abstime, interval);

    if (this->timer_ != -1)
    {
      this->timer_queue_.activate ();
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "(%N:%l) failed to activate cleaning thread\n"));
    }
  }

  //
  // ~Node_Daemon_i
  //
  Node_Daemon_i::~Node_Daemon_i (void)
  {
    // Wait for the process manager thread to return and it's
    // event handler. This means waiting for all processes
    // created by this process manager to exit.
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "waiting for %u NodeManager(s) to exit\n",
                      this->pm_.managed ()));
    this->pm_.wait ();

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "deactivating the process listener\n"));
    this->event_handler_.deactivate ();

    // Deactivate the <timer_queue_> and cancel the <timer_>.
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "deactivating the timer queue\n"));
    this->timer_queue_.deactivate ();
    this->timer_queue_.cancel (this->timer_);
  }

  //
  // spawn
  //
  ::CORBA::ULong Node_Daemon_i::spawn (
    const ::CUTS::Node_Details & nodes
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException))
  {
    // Spawn all the node managers specified in <nodes>. We are using
    // a function-scoped locking mechanism to prevent multiple clients
    // from trying to spawn nodes simultaneously.

    static ACE_Thread_Mutex lock;
    ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, lock, 0);

    size_t count = 0;
    size_t max_nodes = nodes.length ();

    for (size_t i = 0; i < max_nodes; i ++)
    {
      const ::CUTS::Node_Detail & detail = nodes[i];

      // Since the port is available, then we have permission to
      // spawn a new process.
      this->p_options_.command_line (
        "%s -ORBEndpoint iiop://%s:%u %s",
        this->node_manager_.c_str (),
        detail.binding.localhost ? LOCALHOST : this->ip_addr_.c_str (),
        detail.binding.port,
        detail.params.in ());

      pid_t pid = this->spawn_i (detail.binding.port,
                                 detail.binding.localhost,
                                 this->p_options_);

      if (pid != ACE_INVALID_PID &&
          pid != 0)
      {
        VERBOSE_MESSAGE ((
          LM_DEBUG,
          "succesfully spawned process: [pid=%u;port=%u;local=%s]\n",
          pid,
          detail.binding.port,
          detail.binding.localhost ? "yes" : "no"));

        if (PROCESS_LOG ()->process_spawn (pid,
                                           detail.binding.port,
                                           detail.binding.localhost))
        {
          VERBOSE_MESSAGE ((
            LM_DEBUG,
            "succesfully logged process: [pid=%u;port=%u;local=%s]\n",
            pid,
            detail.binding.port,
            detail.binding.localhost ? "yes" : "no"));
        }
        else
        {
          ACE_ERROR ((LM_ERROR,
                      "failed to log process: [pid=%u;port=%u;local=%s]\n",
                      pid,
                      detail.binding.port,
                      detail.binding.localhost ? "yes" : "no"));
        }

        ++ count;
      }
      else
      {
        ACE_ERROR ((
          LM_ERROR,
          "failed to spawn node manager with binding %s:%u\n",
          detail.binding.localhost ? LOCALHOST :  this->ip_addr_.c_str (),
          detail.binding.port));
      }
    }

    return count;
  }

  //
  // kill
  //
  ::CORBA::ULong Node_Daemon_i::kill (
    const ::CUTS::Node_Bindings & nodes
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException))
  {
    size_t count = 0;
    size_t max_nodes = nodes.length ();

    for (size_t i = 0; i < max_nodes; i ++)
    {
      const ::CUTS::Node_Binding & binding = nodes[i];

      // Locate the process id depending on the visibility of
      // target the port.
      pid_t pid = 0;
      int found = binding.localhost ?
        this->local_.find (binding.port, pid) :
        this->global_.find (binding.port, pid);

      if (found != -1)
      {
        // Terminate the process and cleanup its resources
        if (this->pm_.terminate (pid) == 0)
        {
          VERBOSE_MESSAGE ((LM_DEBUG,
                            "successfully terminated process with id %u\n",
                            pid));

          this->process_exits (pid);
          ++ count;
        }
        else
        {
          ACE_ERROR ((LM_ERROR,
                      "failed to terminate process with id %u\n",
                      pid));
        }

        // Remove the process from the log as well.
        if (PROCESS_LOG ()->process_exit (pid))
        {
          VERBOSE_MESSAGE ((
            LM_DEBUG,
            "successfully removed process with id %u from log\n",
            pid));
        }
        else
        {
          ACE_ERROR ((LM_DEBUG,
                      "failed to remove process with id %u from log\n",
                      pid));
        }
      }
    }

    return count;
  }

  //
  // is_available
  //
  bool Node_Daemon_i::is_port_available (u_short port,
                                         bool localhost) const
  {
    return
      localhost ?
      this->local_.find (port) == -1 :
      this->global_.find (port) == -1;
  }

  //
  // process_exit
  //
  void Node_Daemon_i::process_exits (pid_t pid)
  {
    VERBOSE_MESSAGE ((LM_DEBUG,
                      "process with id %u has exited\n",
                      pid));

    Process_Map::VALUE entry = 0;

    if (this->proc_map_.find (pid, entry) == 0)
    {
      if (this->global_.unbind (entry) != 0)
        this->local_.unbind (entry);
    }
    else
    {
      // we have to find the process id the long way...
    }
  }

  //
  // spawn_i
  //
  pid_t Node_Daemon_i::spawn_i (u_short port,
                                bool localhost,
                                ACE_Process_Options & p_options)
  {
    // Check the availability of the node binding before
    // continuing w/ the spawnin
    if (!this->is_port_available (port,
                                  localhost))
    {
      ACE_ERROR_RETURN ((
        LM_ERROR,
        "endpoint %s:%u is not available\n",
        localhost ? LOCALHOST : this->ip_addr_.c_str (),
        port),
        ACE_INVALID_PID);
    }

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "spawning node manager (command: %s)\n",
                      p_options.command_line_buf () ));

    pid_t pid = this->pm_.spawn (p_options,
                                 &this->event_handler_);

    // Remove the port from the correct mapping. This is done
    // by mapping the port number to the <pid>.
    if (pid != ACE_INVALID_PID && pid != 0)
    {
      this->bind_pid (pid, port, localhost);
    }

    return pid;
  }

  //
  // init_p_options
  //
  void Node_Daemon_i::init_p_options (void)
  {
    // Initialize the default <p_options_>.
    this->p_options_.process_name (NODE_MANAGER);
    this->p_options_.avoid_zombies (0);
#if defined (ACE_WIN32)
    this->p_options_.creation_flags (CREATE_NEW_PROCESS_GROUP);
#endif

    // We need to set the working directory for the process
    // if it was specified as a command-line option.
    if (!SERVER_OPTIONS ()->init_dir_.empty ())
    {
      VERBOSE_MESSAGE ((LM_DEBUG,
                        "setting working directory to %s\n",
                        SERVER_OPTIONS ()->init_dir_.c_str ()));

      this->p_options_.working_directory (
        SERVER_OPTIONS ()->init_dir_.c_str ());
    }
  }

  //
  // init
  //
  void Node_Daemon_i::init (void)
  {
    // Initalize the IP-address for this node.
    char hostname[MAXHOSTNAME];

    ACE_OS::hostname (hostname, sizeof (hostname));
    ACE_INET_Addr inet_addr ((u_short)0, hostname, AF_ANY);
    this->ip_addr_ = inet_addr.get_host_addr ();

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "created a node deamon on %s\n",
                      this->ip_addr_.c_str ()));

    // Initialize the process options used for all flavors of
    // node managers spawned.
    this->init_p_options ();

    // Initialize the full path of the <node_manager_> for this
    // instance of the node daemon.
    if (!SERVER_OPTIONS ()->node_manager_path ().empty ())
    {
      VERBOSE_MESSAGE ((LM_DEBUG,
                        "using node manager located in %s\n",
                        SERVER_OPTIONS ()->node_manager_path ().c_str ()));

      this->node_manager_ = SERVER_OPTIONS ()->node_manager_path ();
    }

    this->node_manager_ += NODE_MANAGER;
  }

  //
  // recover
  //
  size_t Node_Daemon_i::recover (void)
  {
    size_t count = 0;
    Process_List active_list;
    PROCESS_LOG ()->get_active_processes (active_list);

    Process_List::iterator iter (active_list);

    for (iter; iter.done () != 1; iter.advance ())
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
      ACE_NEW_RETURN (a_process,
                      CUTS_Active_Process (ple->pid ()),
                      count);

      if (a_process == 0)
      {
        ACE_ERROR ((LM_ERROR,
                    "(%N:%l) failed to attach to process %u\n",
                    ple->pid ()));
        continue;
      }

      if (a_process->running ())
      {
        pid_t pid = this->pm_.spawn (a_process,
                                     this->p_options_,
                                     &this->event_handler_);

        // Remove the port from the correct mapping. This is done
        // by mapping the port number to the <pid>.
        if (pid != ACE_INVALID_PID && pid != 0)
        {
          this->bind_pid (ple->pid (),
                          ple->port (),
                          ple->is_localhost ());
        }

        // Increment the number of process recovered.
        ++ count;
      }
      else
      {
        VERBOSE_MESSAGE ((LM_DEBUG,
                          "process with id %u is not active; removing "
                          "it from the log\n",
                          ple->pid ()));

        // Apparent, this entry is not valid b/c the process is
        // actually not running. Therefore, we have a stale entry in
        // the log and need to remove it.
        PROCESS_LOG ()->process_exit (ple->pid ());

        delete a_process;
        a_process = 0;
      }
    }

    return count;
  }

  //
  // bind_pid
  //
  void Node_Daemon_i::bind_pid (pid_t pid, u_short port, bool localhost)
  {
    Process_Map::VALUE entry = 0;

    if (localhost)
      this->local_.bind (port, pid, entry);
    else
      this->global_.bind (port, pid, entry);

    // Map the <pid> to it's entry in either <local_> or <global_>.
    // This helps decrease the complexity of remove the entry from
    // the <local_> or <global_> mapping when <pid> exits.
    if (entry != 0)
      this->proc_map_.bind (pid, entry);
  }

  //
  // clean
  //
  void Node_Daemon_i::clean (void)
  {
    bool retval = PROCESS_LOG ()->clean ();

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "%s the log file\n",
                      retval ? "successfully cleaned" : "failed to clean"));
  }

  //
  // handle_timeout
  //
  int Node_Daemon_i::handle_timeout (const ACE_Time_Value & tv,
                                     const void * act)
  {
    this->clean ();

    ACE_UNUSED_ARG (tv);
    ACE_UNUSED_ARG (act);
    return 0;
  }
}
