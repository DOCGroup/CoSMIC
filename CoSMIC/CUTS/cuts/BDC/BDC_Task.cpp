// $Id$

#include "BDC_Task.h"

#if !defined (__CUTS_INLINE__)
#include "BDC_Task.inl"
#endif

#include "CCM_Component_Registry.h"
#include "Testing_Service_exec_i.h"
#include "cuts/Component_Metric.h"
#include "cuts/System_Metric_Handler.h"
#include "cuts/performance_i.h"
#include "ace/TP_Reactor.h"
#include "ace/CORBA_macros.h"

namespace CUTS
{
  //
  // BDC_Task
  //
  BDC_Task::BDC_Task (void)
    : metrics_ (0),
      active_ (false),
      timer_ (-1),
      testing_service_ (0),
      count_ (0),
      collect_done_ (0)
  {
    // Create a thread pool reactor.
    ACE_TP_Reactor * tp_reactor = 0;
    ACE_NEW_THROW_EX (tp_reactor,
                      ACE_TP_Reactor (),
                      ACE_bad_alloc ());

    // Setup the auto clean just in case the next allocation fails.
    ACE_Auto_Ptr <ACE_TP_Reactor> auto_clean (tp_reactor);

    ACE_Reactor * reactor = 0;
    ACE_NEW_THROW_EX (reactor,
                      ACE_Reactor (tp_reactor, 1),
                      ACE_bad_alloc ());

    this->reactor (reactor);
    auto_clean.release ();
  }

  //
  // ~BDC_Task
  //
  BDC_Task::~BDC_Task (void)
  {
    delete this->reactor ();
    this->reactor (0);
  }

  //
  // activate
  //
  bool BDC_Task::activate (const ACE_Time_Value & delay,
                           const ACE_Time_Value & interval,
                           Testing_Service_exec_i * tsvc,
                           CUTS_System_Metric * metrics)
  {
    if (this->active_)
      return this->active_;

    // Store the testing service for future reference since
    // we will be requesting its registry at timeout.
    this->testing_service_ = tsvc;
    this->metrics_ = metrics;

    // Schedule the timer for the active object.
    this->timer_ =
      this->reactor ()->schedule_timer (this, 0, delay, interval);

    if (ACE_Task_Base::activate () != -1)
      this->active_ = true;

    return this->active_;
  }

  //
  // deactivate
  //
  void BDC_Task::deactivate (void)
  {
    if (this->active_)
    {
      this->active_ = false;

      // Cancel the current timer for the task.
      if (this->timer_ != -1)
      {
        this->reactor ()->cancel_timer (this->timer_);
        this->timer_ = -1;
      }

      this->msg_queue_->deactivate ();
      this->reactor ()->notify (this);

      // Wait for all threads to exit.
      this->wait ();
    }
  }

  //
  // collect_data
  //
  void BDC_Task::collect_data (void)
  {
    ACE_DEBUG ((LM_ERROR,
                "*** (BDC): collecting performance metrics\n"));

    if (this->testing_service_ == 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** fatal: no testing service present\n"));
    }
    else if (!this->active_)
    {
      ACE_ERROR ((LM_WARNING,
                  "*** warning: collection object not active\n"));
    }
    else if (this->count_ != 0)
    {
      ACE_ERROR ((LM_WARNING,
                  "*** warning: collecting metrics from previous timeout\n"));
    }
    else
    {
      // Update the timestamp for the collected metrics.
      this->metrics_->set_timestamp ();

      // Store the size of the registry and get an iterator to its
      // entries. We store the <count> in both the local variable and
      // the atomic one.
      size_t count = this->testing_service_->registry ().registry_size ();
      this->count_ = count;

      CUTS_Component_Registry::CONST_ITERATOR iter =
        this->testing_service_->registry ().entries ();

      while (!iter.done ())
      {
        try
        {
          // We need to get the benchmark agent from the node.
          CUTS::CCM_Component_Registry_Node * node =
            dynamic_cast < ::CUTS::CCM_Component_Registry_Node * > (iter->int_id_);
          CUTS::Benchmark_Agent_ptr agent = node->benchmark_agent ();

          // Verify this is actual an agent connected to the testing
          // service. If the component was "preregistered" then the
          // agent reference will be NIL until it comes online.
          if (!::CORBA::is_nil (agent))
          {
            this->putq (agent);
            this->reactor ()->notify (this, ACE_Event_Handler::READ_MASK);
          }
          else
            this->decrement_count ();
        }
        catch (std::bad_cast ex)
        {

        }
        catch (...)
        {
          // @todo Implement catch block for std::bad_cast.
          ACE_ERROR ((LM_ERROR,
                      "*** error: %s has an invalid registration\n",
                      iter->ext_id_.c_str ()));
        }

        // Move to the next element.
        iter.advance ();
      }

      // If we never had any components to begin with, then we have to
      // perform the finalization ourselves.
      if (count == 0)
        this->finalize_collection ();
    }
  }

  //
  // svc
  //
  int BDC_Task::svc (void)
  {
    // Initialize the metrics timing values.
    this->metrics_->init_timestamp ();

    // Enter the event loop.
    while (this->active_)
      this->reactor ()->handle_events ();

    return 0;
  }

  //
  // finalize_collection
  //
  void BDC_Task::finalize_collection (void)
  {
    if (this->metrics_ == 0)
      return;

    ACE_DEBUG ((LM_ERROR,
                "*** (BDC): finish collecting performance metrics\n"
                "*** (BDC): notifying each service\n"));

    // Let's iterate over all the registered handlers and notify
    // them that the metrics have been updated.
    CUTS_Handler_Set::ITERATOR iter (this->handles_);

    for ( ; !iter.done (); iter ++)
    {
      CUTS_System_Metric_Handler ** handle = 0;

      if (iter.next (handle) != 0 && handle != 0)
        (*handle)->handle_metrics (*this->metrics_);
    }

    ACE_DEBUG ((LM_INFO,
                "*** info (BDC): finished notifying each service\n"));
  }

  //
  // handle_timeout
  //
  int BDC_Task::handle_timeout (const ACE_Time_Value & curr_time,
                                const void * act)
  {
    this->collect_data ();
    return 0;

    ACE_UNUSED_ARG (curr_time);
    ACE_UNUSED_ARG (act);
  }

  //
  // handle_input
  //
  int BDC_Task::handle_input (ACE_HANDLE)
  {
    // Ok, we failed to activate this object without initializing
    // the <metrics_> properly, then we really need to just stop
    // while we are ahead!!
    if (this->metrics_ == 0)
      return -1;

    // Get the next agent from the message queue.
    ::CUTS::Benchmark_Agent * agent = 0;
    this->getq (agent);

    if (agent != 0)
    {
      try
      {
        // Collect the performance data from the component.
        CUTS::Component_Metric_var data;
        agent->collect_performance_data (data);

        // Locate the metrics for this component in the system metrics.
        CUTS_Component_Metric * metric = 0;
        int retval = this->metrics_->component_metric (data->uid, metric);

        if (retval == 0 && metric != 0)
        {
          // Update the timestamp for the component metrics.
          metric->timestamp (this->metrics_->get_timestamp ());

          // Extract the collected data.
          *data >>= *metric;
        }
      }
      catch (const CORBA::Exception & ex)
      {
        ACE_ERROR ((LM_ERROR,
                    "[%M] -%T - %s\n",
                    ex._info ().c_str ()));
      }
      catch (...)
      {
        ACE_ERROR ((LM_ERROR,
                    "[%M] -%T - unknown exception occured\n"));
      }
    }

    this->decrement_count ();
    return 0;
  }

  //
  // decrement_count
  //
  size_t BDC_Task::decrement_count (void)
  {
    size_t remaining = 0;

    if (this->count_ > 0)
      remaining = -- this->count_;

    if (remaining == 0)
      this->finalize_collection ();

    return remaining;
  }

  //
  // wait_for_collection_done
  //
  void BDC_Task::wait_for_collection_done (const ACE_Time_Value * abstime)
  {
    if (this->active_)
      this->collect_done_.wait (abstime);
  }
}
