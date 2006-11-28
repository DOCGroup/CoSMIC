// $Id$

#include "BDC_Task.h"

#if !defined (__CUTS_INLINE__)
#include "BDC_Task.inl"
#endif

#include "Testing_Service_exec_i.h"
#include "cuts/Time_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/System_Metric.h"
#include "cuts/IDL_Streams.h"
#include "cuts/Log_Msg.h"
#include "ace/Event.h"
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
    ACE_TP_Reactor * tp_reactor = 0;
    ACE_NEW_THROW_EX (tp_reactor,
                      ACE_TP_Reactor (),
                      ACE_bad_alloc ());

    ACE_Reactor * reactor = 0;
    ACE_NEW_THROW_EX (reactor,
                      ACE_Reactor (tp_reactor, 1),
                      ACE_bad_alloc ());

    this->reactor (reactor);
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
                           CUTS_System_Metric * metrics,
                           ACE_Event * collect_done)
  {
    if (this->active_)
      return this->active_;

    // Store the testing service for future reference since
    // we will be requesting its registry at timeout.
    this->testing_service_ = tsvc;
    this->metrics_ = metrics;
    this->collect_done_ = collect_done;

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
    if (!this->active_)
      return;

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

  //
  // collect_data
  //
  void BDC_Task::collect_data (void)
  {
    if (this->testing_service_ == 0)
    {
      CUTS_ERROR (LM_ERROR, "no testing service present\n");
    }
    else if (!this->active_)
    {
      CUTS_ERROR (LM_WARNING, "collection task not active\n");
    }
    else if (this->count_ != 0)
    {
      CUTS_ERROR (LM_WARNING,
                  "collecting metrics from previous timeout\n");
    }
    else
    {
      // Initialize the timestamp.
      this->metrics_->timestamp (ACE_OS::gettimeofday ());

      // Get all the benchmark agents contained in the testing service.
      CCM_Component_Registry * reg = this->testing_service_->ccm_registry ();
      size_t count = reg->get_benchmark_agents (this, this->count_.value_i ());

      // Apparently there wasn't any components in the registration
      // so we can go ahead and signal the waiting task.
      if (count == 0)
        this->finalize_collection ();
    }
  }

  //
  // svc
  //
  int BDC_Task::svc (void)
  {
    while (this->active_)
      this->reactor ()->handle_events ();

    return 0;
  }

  //
  // finalize_collection
  //
  void BDC_Task::finalize_collection (void)
  {
    CUTS_DEBUG (LM_DEBUG, "notifying services\n");
    this->collect_done_->signal ();
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
        // Get <performance_data> and store it in the cache.
        ::CUTS::Benchmark_Data_var data = agent->collect_performance_data ();
        data >> (*this->metrics_);
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
  // handle_agent
  //
  int BDC_Task::handle_agent (const char * instance,
                              ::CUTS::Benchmark_Agent::_ptr_type agent)
  {
    int retval = 1;

    if (this->active_)
    {
      // Verify this is actual an agent connected to the testing
      // service. If the component was "preregistered" then the
      // agent reference will be NIL until it comes online.
      if (!::CORBA::is_nil (agent))
      {
        this->putq (agent);
        this->reactor ()->notify (this, ACE_Event_Handler::READ_MASK);
      }
      else
      {
        retval = this->decrement_count ();
      }
    }

    return retval;

    ACE_UNUSED_ARG (instance);
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
      this->collect_done_->wait (abstime);
  }
}
