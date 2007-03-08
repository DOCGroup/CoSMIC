// -*- C++ -*-

//=============================================================================
/**
 * @file    BDC_Task.h
 *
 * @brief   Active object for the Benchmark_Data_Collector component.
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BDC_TASK_H_
#define _CUTS_BDC_TASK_H_

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "CCM_Component_Registry.h"
#include "ace/Atomic_Op_T.h"
#include "ace/streams.h"
#include "ace/Task_Ex_T.h"
#include "ace/Manual_Event.h"
#include "ace/Unbounded_Set.h"

// Forward decl.
class CUTS_System_Metric;

// Forward decl.
class CUTS_System_Metric_Handler;

// Forward decl.
class ACE_Time_Value;

// Forward decl.
class ACE_Event;

namespace CUTS
{
  // Forward decl.
  class Testing_Service_exec_i;

  //=========================================================================
  /**
   * @class   BDC_Task
   *
   * @brief   Active object for the Benchmark_Data_Collector.
   *
   * The BDC_Task object is the main logic of the BDC. It is responsible
   * for collecting all the metrics from each of the components in the
   * system. Once metrics are collected, it stores to metrics in a
   * temporary cache for that collection period. The BDC_Task can
   * be configured in a number of ways. For example, you set the number of
   * threads used to collect metrics at activation time. Also, the metics
   * stored in the cache can be dumped to an file on the same node as the
   * Benchmark_Data_Collector in XML format.
   */
  //=========================================================================

  class BDC_Task :
    public ACE_Task_Ex <ACE_MT_SYNCH, ::CUTS::Benchmark_Agent>
  {
  public:
    /// Default constructor.
    BDC_Task (void);

    /// Destructor.
    virtual ~BDC_Task (void);

    /**
     * Activate the task. This will activate all the threads in
     * the BDC_Task. One thread however is responsible for handling
     * the timeout notification and getting all gathering all the
     * agents. The other threads, if applicable, are responsible for
     * collecting the performance metrics from the agents as the
     * thread gathering the agents delegates the work.
     *
     * @param[in]     tsvc      Pointer to the testing service.
     */
    bool activate (const ACE_Time_Value & delay,
                   const ACE_Time_Value & interval,
                   Testing_Service_exec_i * tsvc,
                   CUTS_System_Metric * metric);

    /// Deactivate the task.
    void deactivate (void);

    /**
     * Force the task to collect performance metrics for all to
     * components. This is a non-blocking method. When all the
     * metrics are finished collecting, the collect_done_event ()
     * is signaled.
     */
    void collect_data (void);

    /**
     * Wait for the collection done event.
     *
     * @param[in]     abstime       Absolute timeout value.
     */
    void wait_for_collection_done (const ACE_Time_Value * abstime = 0);

    /**
     * Register a handler for the system metrics. Whenever the
     * metrics are collected, the \a handler will be notified.
     *
     * @retval        0             Successfully registered \a handler.
     * @retval        -1            Failed to register \a handler.
     */
    int register_handler (CUTS_System_Metric_Handler * handler);

    /**
     * Unregister a handler for the system metrics.
     *
     * @retval        0             Successfully unregistered \a handler.
     * @retval        -1            Failed to unregister \a handler.
     */
    int unregister_handler (CUTS_System_Metric_Handler * handler);

  protected:
    /// Storage location for the system metrics.
    CUTS_System_Metric * metrics_;

    /// Input handler for the task.
    virtual int handle_input (ACE_HANDLE);

  private:
    /// Service handler for the task.
    int svc (void);

    /// Timeout handler for the task.
    int handle_timeout (const ACE_Time_Value & curr_time, const void * act);

    /// Helper method to descrement the count.
    size_t decrement_count (void);

    /// Finalize the collection of the metrics.
    void finalize_collection (void);

    /// Flag containing the active state for the task.
    bool active_;

    /// ID of the timer for the timeout.
    long timer_;

    /// Pointer to the testing service that contains the
    /// component registry for the test.
    Testing_Service_exec_i * testing_service_;

    /// Number of components remaining to collect.
    ACE_Atomic_Op <ACE_RW_Thread_Mutex, size_t> count_;

    /// Condition variable for sychronizing with data collection.
    ACE_Manual_Event collect_done_;

    /// Type definition for a collection of registered handlers.
    typedef ACE_Unbounded_Set <
            CUTS_System_Metric_Handler *>
            CUTS_Handler_Set;

    /// Collection of registered handlers.
    CUTS_Handler_Set handles_;
  };
}

#if defined (__CUTS_INLINE__)
#include "BDC_Task.inl"
#endif

#include /**/ "ace/post.h"

#endif  // !defined _CUTS_BDC_TASK_H_
