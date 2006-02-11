// $Id$

#include "CUTS_exec.h"
#include "ciao/CIAO_common.h"
#include "cuts/Time.h"
#include "ace/OS_NS_unistd.h"
#include "ace/TP_Reactor.h"
#include <iostream>
#include <strstream>

static const int DEFAULT_THREAD_COUNT = 3;

namespace CUTS
{
  inline std::ostream & operator << (std::ostream & out, const Time_Info & ti)
  {
    out << "min: " << ti.min << "; max: " << ti.max;
    return out;
  }

  inline std::ostream & operator << (std::ostream & out, const Time_Sample & ts)
  {
    long avg = ts.count == 0 ? 0 : ts.time.total / ts.count;

    out
      << "count: " << ts.count
      << "; avg: " << avg
      << "; " << ts.time;
    return out;
  }

  inline std::ostream & operator << (std::ostream & out, const Exit_Point_Time & ept)
  {
    out
      << "| " << ept.exit_point_ << " -> [" << ept.time_sample_ << "]";
    return out;
  }

  std::ostream & operator << (std::ostream & out, const Exit_Point_Time_Seq & seq)
  {
    out
      << "| Exit Point Times (msec):" << std::endl;

    size_t length = seq.length ();

    for (size_t i = 0; i < length; i ++)
    {
      out << seq[i] << std::endl;
    }

    return out;
  }

  inline std::ostream & operator << (std::ostream & out, const Port_Measurement & port)
  {
    out
      << "| " << port.port << std::endl
      << "| Transit Time (msec): [" << port.transit_time << "]" << std::endl
      << "| Process Time (msec): [" << port.process_time << "]" << std::endl
      << "|" << std::endl
      << port.exit_times;

    return out;
  }

  std::ostream & operator << (std::ostream & out, const Port_Measurement_Seq & ports)
  {
    size_t length = ports.length ();

    for (size_t i = 0; i < length; i ++)
    {
      out << "|" << std::endl << ports[i] << "|" << std::endl;
    }

    return out;
  }

  inline std::ostream & operator << (std::ostream & out, const Benchmark_Data_var & data)
  {
    out
      << "============================================================" << std::endl
      << "| CoWorkEr " << data->owner << std::endl
      << "| " << CUTS_string_time (data->timestamp, "%#c") << std::endl
      << "============================================================" << std::endl
      << data->ports
      << "============================================================" << std::endl;

    return out;
  }

  namespace CIDL_Benchmark_Data_Collector_Impl
  {
    //=========================================================================
    /*
     * Path_Measurement_exec_i implementation
     */
    //=========================================================================

    //
    // Path_Measurement_exec_i
    //
    Path_Measurement_exec_i::Path_Measurement_exec_i (void)
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
    CORBA::Long Path_Measurement_exec_i::bind_to_path (
      const ::CUTS::Path_Sequence & path
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      return 0;
    }

    //
    // unbind_to_path
    //
    void Path_Measurement_exec_i::unbind_to_path (
      ::CORBA::Long path_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {

    }

    //
    // execution_time
    //
    ::CORBA::Long Path_Measurement_exec_i::execution_time (
      ::CORBA::Long path_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      return 0;
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
      this->bdc_exec_->collect_performance_data ();
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
      : context_ (0),
        timeout_ (0),
        timer_ (-1),
        active_ (false)
    {
      // Create a new <reactor_>.
      ACE_Reactor * reactor = new ACE_Reactor (new ACE_TP_Reactor (), 1);
      this->reactor (reactor);

      this->notify_strategy_.reset (
        new ACE_Reactor_Notification_Strategy (
        reactor, this, ACE_Event_Handler::READ_MASK));

      // Attach the notification strategy to the <closed_list_>.
      this->bma_queue_.notification_strategy (this->notify_strategy_.get ());

      // Create the <BDC_Control_Handle>.
      BDC_Control_Handle_exec_i * bdc_control_handle;
      ACE_NEW (bdc_control_handle, BDC_Control_Handle_exec_i (this));

      // Activate the <bdc_control_handle>.
      this->bdc_control_handle_.reset (bdc_control_handle);
    }

    //
    // ~Benchmark_Data_Collector_exec_i
    //
    Benchmark_Data_Collector_exec_i::~Benchmark_Data_Collector_exec_i (void)
    {

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
      return CUTS::CCM_Path_Measurment::_nil ();
    }

    //
    // deactivate
    //
    void Benchmark_Data_Collector_exec_i::deactivate (void)
    {
      if (this->active_)
      {
        // Cancel the timer.
        this->reactor ()->cancel_timer (this->timer_);
        this->timer_ = -1;

        // Notify the reaction. Eventually we will overload the notification
        // method to do more specific operations.
        this->active_ = false;
        this->reactor ()->notify (this);

        // Wait for any running threads to exit.
        this->wait ();
      }
    }

    //
    // svc
    //
    int Benchmark_Data_Collector_exec_i::svc (void)
    {
      std::cerr << "entered Benchmark_Data_Collector_exec_i::svc" << std::endl;
      // If this is the an <ACE_TP_Reactor> implmentation then
      // this is a <noop>. Otherwise, it will set the owner
      // of the <reactor> to the current thread.
      this->reactor ()->owner (ACE_OS::thr_self ());

      while (this->active_)
      {
        this->reactor ()->handle_events ();
      }

      std::cerr << "exiting Benchmark_Data_Collector_exec_i::svc" << std::endl;
      return 0;
    }

    //
    // collect_performance_data
    //
    void Benchmark_Data_Collector_exec_i::collect_performance_data (void)
    {
      if (this->active_)
      {
        // We can only allow one collection at a time.
        if (this->collection_mutex_.tryacquire () == -1)
          return;

        // Get the current time of collection.
        this->collection_start_ = ACE_OS::gettimeofday ();

        // 1. Get all the <Benchmark_Agent> objects connected to me.
        ::CUTS::Benchmark_Data_Collector::benchmark_agentsConnections_var
          bma_connections (this->context_->get_connections_benchmark_agents ());

        // 2. Push the references into a queue to be processed asynchronously.
        size_t length = bma_connections->length ();
        std::cerr << "There are " << length << " CoWorkEr(s) connected to me..." << std::endl;

        for (size_t i = 0; i < length; i ++)
        {
          // Get the <Benchmark_Agent> pointer and release it from the
          // contained _var object reference. The <handle_input> method
          // is responsible for destroying the object.
          this->bma_queue_.enqueue (bma_connections[i].objref._retn ());
        }

        // Wait for the data collection to finish.
        this->collection_stop_ = ACE_OS::gettimeofday ();
      }
    }

    //
    // handle_timeout
    //
    int Benchmark_Data_Collector_exec_i::handle_timeout (
      const ACE_Time_Value & tv,
      const void * act)
    {
      collect_performance_data ();
      return 0;
    }

    //
    // handle_input
    //
    int Benchmark_Data_Collector_exec_i::handle_input (ACE_HANDLE fd)
    {
      std::cerr << "entered Benchmark_Data_Collector_exec_i::handle_input" << std::endl;

      // Get the next <Benchmark_Agent> reference.
      ::CUTS::Benchmark_Agent * agent;
      this->bma_queue_.dequeue (agent);

      // Attach to the object since the method inserting the agent is giving
      // us the responsibility of destroying the object.
      CUTS::Benchmark_Agent_var agent_var (agent);

      if (!::CORBA::is_nil (agent_var.in ()))
      {
        try
        {
          // Get the performance data.
          if (this->active_)
          {
            std::cerr << "[debug]: requesting performance data" << std::endl;
            ::CUTS::Benchmark_Data_var data = agent_var->performance_data ();
            std::cerr << "[debug]: receieved performance data" << std::endl;

            // Buffer the data into an output string.
            std::ostrstream str;
            str << data << std::ends;

            //// Print the buffer to the screen.
            //ACE_GUARD_RETURN (ACE_Thread_Mutex,
            //                  write_guard,
            //                  this->write_mutex_ , 0);

            std::cerr << str.str () << std::endl;
          }
        }
        catch (::CORBA::SystemException & ex)
        {
          std::cerr << ex << std::endl;
        }
        catch (...)
        {
          std::cerr << "*** error: unknown exception occured" << std::endl;
        }
      }
      else
      {
        std::cerr << "[error]: failed to collect the data for agent" << std::endl;
      }

      // Release the mutex since we have collected all the data. This is not
      // a good design choice becuase there may be instances where the queue
      // is always empty because we are printing collect the data as fast as
      // it is being placed in the queue. For testing reasons, I am leaving
      // this here until after I finish the code generation.
      if (this->bma_queue_.is_empty ())
        this->collection_mutex_.release ();

      std::cerr << "exiting Benchmark_Data_Collector_exec_i::handle_input" << std::endl;
      return 0;
    }

    //
    // activate
    //
    bool Benchmark_Data_Collector_exec_i::activate (void)
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

      // Verify the <timer_> was scheduled.
      return this->timer_ != -1;
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
      return this->timeout_;
    }

    void
    Benchmark_Data_Collector_exec_i::timeout (
    ::CORBA::Long timeout
    ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->timeout_ = timeout;
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
      // Your code here.
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
      activate ();
    }

    void
    Benchmark_Data_Collector_exec_i::ccm_passivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      std::cerr << "entered Benchmark_Data_Collector_exec_i::ccm_passivate" << std::endl;
      deactivate ();
      std::cerr << "exiting Benchmark_Data_Collector_exec_i::ccm_passivate" << std::endl;
    }

    void
    Benchmark_Data_Collector_exec_i::ccm_remove (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      delete this->reactor ();
      this->reactor (0);
    }

    //==================================================================
    // Home Executor Implementation Class:   Benchmark_Data_Collector_Home_exec_i
    //==================================================================

    Benchmark_Data_Collector_Home_exec_i::Benchmark_Data_Collector_Home_exec_i (void)
    {
    }

    Benchmark_Data_Collector_Home_exec_i::~Benchmark_Data_Collector_Home_exec_i (void)
    {
    }

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    ::Components::EnterpriseComponent_ptr
    Benchmark_Data_Collector_Home_exec_i::create (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
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

