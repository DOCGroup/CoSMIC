// $Id$

#include "CUTS_exec.h"
#include "ciao/CIAO_common.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Time_Metric.h"
#include "cuts/Time.h"

#include "ace/OS_NS_unistd.h"
#include "ace/TP_Reactor.h"
#include "ace/Log_Msg.h"

#include <iostream>
#include <strstream>

static const int DEFAULT_THREAD_COUNT = 3;

namespace CUTS
{
  //
  // operator << (CUTS_Time_Metric &, const Time_Sample &)
  //
  void operator << (CUTS_Time_Metric & time_metric,
                    const Time_Sample & time_sample)
  {
    // Calculate the average timing metric.
    long average = time_sample.time.total / time_sample.count;

    // Update the timing information.
    time_metric.update (
      time_sample.count,
      average,
      time_sample.time.min,
      time_sample.time.max);
  }

  //
  // operator << (CUTS_Port_Metric &, const Port_Measurement &)
  //
  void operator << (CUTS_Port_Metric & port_metric,
                    const Port_Measurement & port_measurement)
  {
    do
    {
      // Save the transit time.
      ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, port_metric.lock ());
      port_metric.transit_time () << port_measurement.transit_time;
    } while (false);

    // Get all the exit times for this component.
    long length = port_measurement.exit_times.length ();

    for (long i = 0; i < length; i ++)
    {
      // Get the next <exit_point> from the collection.
      const Exit_Point_Time & exit_point = port_measurement.exit_times[i];

      // Locate the <endpoint> in the <port_metric>.
      CUTS_Time_Metric * time_metric =
        port_metric.endpoint (exit_point.exit_point_);

      if (time_metric)
      {
        // Store the <time_sample_> in the <time_metric>.
        (*time_metric) << exit_point.time_sample_;
      }
    }
  }

  //
  // operator << (CUTS_System_Metric &, const Benchmark_Data_var &)
  //
  void operator << (CUTS_System_Metric & sys_metrics,
                    const Benchmark_Data_var & data)
  {
    // Get the <CUTS_Component_Metric> for this <data>. If one does not
    // exist it will create a new one, which should be a one time only
    // occurrence.
    CUTS_Component_Metric * metric =
      sys_metrics.component_metrics (data->owner);

    // Get the <ports> and the <length> of the <port> sequence.
    Port_Measurement_Seq ports = data->ports;
    long length = ports.length ();

    for (long i = 0; i < length; i ++)
    {
      // Get the next <port_measurement> in the collection.
      Port_Measurement & port_measurement = ports[i];

      // Get the port metric w/ the same <port> name. If one does not
      // exist, it will create a new one, which a one time only
      // creation as long as it isnt destroyed.
      CUTS_Port_Metric * port_metric =
        metric->port_metrics (port_measurement.port);

      if (port_metric)
      {
        // Store the <port_measurements
        (*port_metric) << port_measurement;
      }
    }
  }

  namespace CIDL_Benchmark_Data_Collector_Impl
  {
    //=========================================================================
    /*
     * BDC_Task implementation
     */
    //=========================================================================

    //
    // BDC_Task
    //
    BDC_Task::BDC_Task (void)
      : control_handle_ (0),
        active_ (false),
        timeout_ (0),
        timer_ (-1)
    {
      // Create a new <reactor_>.
      ACE_Reactor * reactor = new ACE_Reactor (new ACE_TP_Reactor (), 1);
      this->reactor (reactor);

      // Allocate a new strategy.
      ACE_Reactor_Notification_Strategy * strategy = 0;

      ACE_NEW (strategy,
              ACE_Reactor_Notification_Strategy (
                reactor, this, ACE_Event_Handler::READ_MASK));

      this->notify_strategy_.reset (strategy);

      // Attach the notification strategy to the <closed_list_>.
      this->bma_queue_.notification_strategy (strategy);
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
    bool BDC_Task::activate (void)
    {
      if (this->timeout_ > 0)
      {
        // Schedule a timer with the <reactor>.
        ACE_Time_Value interval (this->timeout_);
        this->timer_ = this->reactor ()->schedule_timer (
          this, 0, interval, interval);

        // Activate the task.
        this->active_ = true;

        ACE_Task_Base::activate (
          THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED,
          DEFAULT_THREAD_COUNT);
      }

      return this->active_;
    }

    //
    // deactivate
    //
    void BDC_Task::deactivate (void)
    {
      this->active_ = false;

      // Cancel the <timer_>. This prevent any more data collection
      // from happening.
      if (this->timer_ != -1)
      {
        this->reactor ()->cancel_timer (this->timer_);
        this->timer_ = -1;
      }

      // Wait for all the threads to terminate.
      this->reactor ()->notify (this);
      this->wait ();
    }

    //
    // timeout
    //
    long BDC_Task::timeout (void) const
    {
      return this->timeout_;
    }

    void BDC_Task::timeout (long timeout)
    {
      this->timeout_ = timeout;
    }

    //
    // reset_handle
    //
    void BDC_Task::reset_handle (BDC_Control_Handle_exec_i * handle)
    {
      this->control_handle_ = handle;
    }

    //
    // svc
    //
    int BDC_Task::svc (void)
    {
      this->reactor ()->owner (ACE_OS::thr_self ());

      while (this->active_)
      {
        this->reactor ()->handle_events ();
      }

      return 0;
    }

    //
    // handle_timeout
    //
    int BDC_Task::handle_timeout (const ACE_Time_Value & curr_time,
                                  const void * act)
    {
      if (this->control_handle_ && this->active_)
      {
        this->control_handle_->collect_performance_data ();
      }
      return 0;
    }

    //
    // handle_input
    //
    int BDC_Task::handle_input (ACE_HANDLE handle)
    {
      // Get the next <Benchmark_Agent> reference.
      ::CUTS::Benchmark_Agent * temp = 0;
      this->bma_queue_.dequeue (temp);

      // Attach to the object since the method inserting the agent is giving
      // us the responsibility of destroying the object.
      CUTS::Benchmark_Agent_var agent (temp);

      if (!::CORBA::is_nil (agent.in ()) && this->active_)
      {
        try
        {
          // Get the performance data from the <agent>.
          ::CUTS::Benchmark_Data_var data = agent->performance_data ();

          // We only need to cache the performance <data> locally
          // if we have a pointer to the <system_metrics_>.
          if (this->system_metrics_)
          {
            (*this->system_metrics_) << data;
          }
        }
        catch (::CORBA::SystemException & ex)
        {
          std::cout << ex << std::endl;
        }
        catch (...)
        {
          std::cerr << "[error]: unknown exception occured" << std::endl;
        }
      }
      else
      {
        std::cerr << "[error]: failed to collect the data for agent" << std::endl;
      }

      return 0;
    }

    //
    // enqueue_agent
    //
    void BDC_Task::enqueue_agent (::CUTS::Benchmark_Agent_ptr agent)
    {
      if (this->active_)
      {
        this->bma_queue_.enqueue (agent);
      }
    }

    //
    // system_metrics
    //
    void BDC_Task::system_metrics (CUTS_System_Metric * metrics)
    {
      this->system_metrics_  = metrics;
    }

    //=========================================================================
    /*
     * Path_Measurement_exec_i implementation
     */
    //=========================================================================

    //
    // Path_Measurement_exec_i
    //
    Path_Measurement_exec_i::Path_Measurement_exec_i (
      CUTS_System_Metric * system_metrics)
      : system_metrics_ (system_metrics)
    {

    }

    //
    // ~Path_Measurement_exec_i
    //
    Path_Measurement_exec_i::~Path_Measurement_exec_i (void)
    {

    }

    //
    // bind_to_path
    //
    ::CORBA::Long Path_Measurement_exec_i::bind_to_path (
      const ::CUTS::Path_Sequence & path
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::CUTS::Binding_Failed))
    {
      Path_Definition * path_def = 0;

      ACE_NEW_THROW_EX (path_def,
                        Path_Definition (),
                        ::CUTS::Binding_Failed ());

      // This will clean up the memory just in case an exception
      // is thrown before we can insert the <path_def> into the
      // collection of <paths_>.
      ACE_Auto_Ptr <Path_Definition> auto_clean (path_def);

      long length = 0;

      for (long i = 0; i < length; i ++)
      {
        // Get the next path element.
        const Path_Element & element = path[i];

        // Locate the element in the <paths_>.
        CUTS_Component_Metric * component_metric =
          this->system_metrics_->component_metrics (element.UUID);

        // Get the source port metrics.
        CUTS_Port_Metric * port_metric =
          component_metric->port_metrics (element.src);

        // Get the endpoing timing metrics.
        CUTS_Time_Metric * endpoint = port_metric->endpoint (element.dst);

        // Insert the time_metric into the temp store.
        path_def->push (&port_metric->transit_time ());
        path_def->push (endpoint);

        // Insert the newly created <path> into the collection.
        ACE_WRITE_GUARD_THROW_EX (
          ACE_RW_Thread_Mutex,
          guard,
          this->lock_,
          ::CUTS::Binding_Failed ());
      }

      // Insert the <path_def> in the the collection of <paths_>.
      this->paths_.insert (path_def);

      // Since we made it this far we did not throw any exceptions.
      // We can therefore release the memory and not destroy it.
      auto_clean.release ();
      return reinterpret_cast <long> (path_def);
    }

    //
    // unbind_to_path
    //
    void Path_Measurement_exec_i::unbind_to_path (
      ::CORBA::Long path_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, this->lock_);
      this->paths_.erase (reinterpret_cast <Path_Definition *> (path_id));
    }

    //
    // execution_time
    //
    ::CUTS::Time_Info Path_Measurement_exec_i::execution_time (
      ::CORBA::Long path_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::CUTS::ID_Not_Found,
                       ::CUTS::Operation_Failed))
    {
      CUTS_Time_Metric time_metric;
      ::CUTS::Time_Info time_info;

      // Until we have implemented a sophisticated version of the
      // <Path_Registry> we have to protect against invalid id's.
      // Therefore, we have to located the reference in the
      // set the <paths_> to determine is validity.

      Path_Registry::iterator result;

      do {
        ACE_READ_GUARD_THROW_EX (
          ACE_RW_Thread_Mutex,
          guard,
          this->lock_,
          ::CUTS::Operation_Failed ());

        result =
          this->paths_.find (reinterpret_cast <Path_Definition *> (path_id));
      } while (false);

      if (result != this->paths_.end ())
      {
        // Since we found the path. We need to accumulate the
        // timing information along the path.
        Path_Definition::container_type::const_iterator path_iter;

        for (path_iter = (*result)->c.begin ();
            path_iter != (*result)->c.end ();
            path_iter ++)
        {
          time_metric += *(*path_iter);
        }
      }
      else
      {
        throw ::CUTS::ID_Not_Found ();
      }

      // Create a new <Time_Info> for the client to view its path
      // performance.
      time_info.total = time_metric.average_time ();
      time_info.max   = time_metric.worse_time ();
      time_info.min   = time_metric.best_time ();
      return time_info;
    }

    //
    // system_metrics
    //
    void Path_Measurement_exec_i::system_metrics (
      CUTS_System_Metric * system_metrics)
    {
      this->system_metrics_ = system_metrics;
    }

    //=========================================================================
    /*
     * BDC_Control_Handle_exec_i implementation
     */
    //=========================================================================

    //
    // BDC_Control_Handle_exec_i
    //
    BDC_Control_Handle_exec_i::BDC_Control_Handle_exec_i (
      Benchmark_Data_Collector_exec_i * bdc_exec)
      : bdc_exec_ (bdc_exec)
    {

    }

    //
    // ~BDC_Control_Handle_exec_i
    //
    BDC_Control_Handle_exec_i::~BDC_Control_Handle_exec_i (void)
    {

    }

    //
    // collect_performance_data
    //
    void BDC_Control_Handle_exec_i::collect_performance_data (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      this->bdc_exec_->get_agents ();
    }

    //=========================================================================
    /*
     * Benchmark_Data_Collector_exec_i implementation
     */
    //=========================================================================

    //
    // Benchmark_Data_Collector_exec_i
    //
    Benchmark_Data_Collector_exec_i::Benchmark_Data_Collector_exec_i (void)
      : context_ (0)
    {
      // Create the <BDC_Control_Handle>.
      BDC_Control_Handle_exec_i * control_handle;
      ACE_NEW (control_handle, BDC_Control_Handle_exec_i (this));
      this->bdc_control_handle_.reset (control_handle);

      // Get the <control_handle_> to the <task_>. This will allow the
      // task the requeust the <control_handle_> to implicitly invoke
      // the <collect_performance_data> method.
      this->task_.reset_handle (control_handle);

      // Set the <system_metrics_> for the <task_>. This will give the
      // task a location for temporarily storing the collected data.
      this->task_.system_metrics (&this->system_metric_);

      // Create the <Path_Measurement>. We have to give it the location
      // of the <system_metric_> for doing its calculations.
      Path_Measurement_exec_i * path_measurement = 0;
      ACE_NEW (
        path_measurement,
        Path_Measurement_exec_i (&this->system_metric_));

      this->path_measurements_.reset (path_measurement);
    }

    //
    // ~Benchmark_Data_Collector_exec_i
    //
    Benchmark_Data_Collector_exec_i::~Benchmark_Data_Collector_exec_i (void)
    {
      this->task_.system_metrics (0);
    }

    //
    // get_controls
    //
    ::CUTS::CCM_BDC_Control_Handle_ptr
      Benchmark_Data_Collector_exec_i::get_controls (void)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      return ::CUTS::CCM_BDC_Control_Handle::_duplicate (
        this->bdc_control_handle_.get ());
    }

    //
    // get_online_measurements
    //
    ::CUTS::CCM_Path_Measurment_ptr
      Benchmark_Data_Collector_exec_i::get_online_measurements (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      return CUTS::CCM_Path_Measurment::_duplicate (
        this->path_measurements_.get ());;
    }

    //
    // get_agents
    //
    void Benchmark_Data_Collector_exec_i::get_agents (void)
    {
      // 1. Get all the <Benchmark_Agent> objects connected to me.
      ::CUTS::Benchmark_Data_Collector::benchmark_agentsConnections_var
        bma_connections (this->context_->get_connections_benchmark_agents ());

      // 2. Push the references into a queue to be processed asynchronously.
      size_t length = bma_connections->length ();
      std::cout << "There are " << length << " CoWorkEr(s) connected to me..." << std::endl;

      for (size_t i = 0; i < length; i ++)
      {
        // Get the <Benchmark_Agent> pointer and release it from the
        // contained _var object reference. The <handle_input> method
        // is responsible for destroying the object.
        this->task_.enqueue_agent (bma_connections[i].objref._retn ());
      }
    }

    //
    // server_name
    //
    char * Benchmark_Data_Collector_exec_i::server_name (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return 0;
    }

    void Benchmark_Data_Collector_exec_i::server_name (
    const char * server_name
    ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      // Your code here.
    }

    //
    // timeout
    //
    ::CORBA::Long
    Benchmark_Data_Collector_exec_i::timeout (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return this->task_.timeout ();
    }

    void
    Benchmark_Data_Collector_exec_i::timeout (
    ::CORBA::Long timeout
    ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->task_.timeout (timeout);
    }

    //
    // set_session_context
    //
    void
    Benchmark_Data_Collector_exec_i::set_session_context (
      ::Components::SessionContext_ptr ctx
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      this->context_ =
        Benchmark_Data_Collector_Context::_narrow (ctx
        ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      if (this->context_ == 0)
      {
        ACE_THROW (CORBA::INTERNAL ());
      }
    }

    void
    Benchmark_Data_Collector_exec_i::ciao_preactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {

    }

    void
    Benchmark_Data_Collector_exec_i::ccm_activate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {

    }

    void
    Benchmark_Data_Collector_exec_i::ciao_postactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      ACE_DEBUG ((LM_TRACE,
        "entered Benchmark_Data_Collector_exec_i::ciao_postactivate\n"));

      // Explicitly activate the task. In the future, there will be
      // an attribute that specifies if the task should be activated.
      this->task_.activate ();

      ACE_DEBUG ((LM_TRACE,
        "exitting Benchmark_Data_Collector_exec_i::ciao_postactivate\n"));
    }

    void
    Benchmark_Data_Collector_exec_i::ccm_passivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      ACE_DEBUG ((LM_TRACE,
        "entered Benchmark_Data_Collector_exec_i::ccm_passivate\n"));

      // Deactivate the task.
      this->task_.deactivate ();

      ACE_DEBUG ((LM_TRACE,
        "exiting Benchmark_Data_Collector_exec_i::ccm_passivate\n"));
    }

    void
    Benchmark_Data_Collector_exec_i::ccm_remove (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {

    }

    //=========================================================================
    /*
     * Benchmark_Data_Collector_Home_exec_i
     */
    //=========================================================================

    //
    // Benchmark_Data_Collector_Home_exec_i
    //
    Benchmark_Data_Collector_Home_exec_i::Benchmark_Data_Collector_Home_exec_i (void)
    {

    }

    //
    // ~Benchmark_Data_Collector_Home_exec_i
    //
    Benchmark_Data_Collector_Home_exec_i::~Benchmark_Data_Collector_Home_exec_i (void)
    {

    }

    //
    // create
    //
    ::Components::EnterpriseComponent_ptr
    Benchmark_Data_Collector_Home_exec_i::create (
      ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {
      ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

      ACE_NEW_THROW_EX (
        retval,
        Benchmark_Data_Collector_exec_i,
        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());

      return retval;
    }

    //
    // createBenchmark_Data_Collector_Home_Impl
    //
    extern "C" CUTS_EXEC_Export ::Components::HomeExecutorBase_ptr
    createBenchmark_Data_Collector_Home_Impl (void)
    {
      ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

      ACE_NEW_RETURN (
        retval,
        Benchmark_Data_Collector_Home_exec_i,
        ::Components::HomeExecutorBase::_nil ());

      return retval;
    }
  }
}

