// $Id$

#include "CUTS_exec.h"
#include "ciao/CIAO_common.h"
#include "cuts/Time.h"
#include "ace/Reactor.h"
#include "ace/streams.h"
#include "ace/OS_NS_unistd.h"

namespace CUTS
{
  ostream & operator << (ostream & out, const Benchmark_Data_var & data)
  {
    out
      << "============================================================" << endl
      << "| CoWorkEr " << data->owner << endl
      << "| " << CUTS_string_time (data->timestamp, "%#c") << endl
      << "============================================================" << endl
      << "|" << endl
      << "============================================================" << endl;

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
      ACE_Reactor * reactor = new ACE_Reactor ();
      this->reactor (reactor);

      this->notify_strategy_.reset (
        new ACE_Reactor_Notification_Strategy (
        reactor, this, ACE_Event_Handler::READ_MASK));

      // Attach the notification strategy to the <closed_list_>.
      this->bma_queue_.notification_strategy (this->notify_strategy_.get ());
    }

    //
    // ~Benchmark_Data_Collector_exec_i
    //
    Benchmark_Data_Collector_exec_i::~Benchmark_Data_Collector_exec_i (void)
    {

    }

    //
    // collect_performance_data
    //
    void Benchmark_Data_Collector_exec_i::collect_performance_data (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      // Get the current time of collection.
      this->collection_start_ = ACE_OS::gettimeofday ();

      // 1. Get all the <Benchmark_Agent> objects connected to me.
      ::CUTS::Benchmark_Data_Collector::benchmark_agentsConnections_var
        bma_connections (this->context_->get_connections_benchmark_agents ());

      // 2. Push the references into a queue to be processed asynchronously.
      size_t length = bma_connections->length ();
      cerr << "There are " << length << " CoWorkEr(s) connected to me..." << endl;

      for (size_t i = 0; i < length; i ++)
      {
        // Get the <Benchmark_Agent> pointer and release it from the
        // contained _var object reference. The <handle_input> method
        // is responsible for destroying the object.
        this->bma_queue_.enqueue (bma_connections[i].objref._retn ());
      }
    }

    //
    // get_controls
    //
    ::CUTS::CCM_BDC_Control_Handle_ptr
      Benchmark_Data_Collector_exec_i::get_controls (void)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      // Get the <BDC_Control_Handle> interface from this object since
      // we support it directly.
      ::CUTS::CCM_BDC_Control_Handle_var retval =
        ::CUTS::CCM_BDC_Control_Handle::_narrow (this);

      return retval._retn ();
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
      if (is_active ())
      {
        // Cancel the timer.
        this->reactor ()->cancel_timer (this->timer_);
        this->timer_ = -1;

        // Notify the reaction. Eventually we will overload the notification
        // method to do more specific operations.
        this->reactor ()->notify (this);

        // Wait for any running threads to exit.
        wait ();
      }
    }

    //
    // svc
    //
    int Benchmark_Data_Collector_exec_i::svc (void)
    {
      this->reactor ()->owner (ACE_OS::thr_self ());

      while (is_active ())
      {
        this->reactor ()->handle_events ();
      }

      return 0;
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
          ::CUTS::Benchmark_Data_var data (agent_var->performance_data ());

          // Print the data to the client.
          cerr << data << endl;
        }
        catch (::CORBA::SystemException & ex)
        {
          cerr << ex << endl;
        }
        catch (...)
        {
          cerr << "*** error: unknown exception occured" << endl;
        }
      }
      else
      {
        cerr << "failed to collect the data from a Benchmark_Agent" << endl;
      }
      return 0;
    }

    //
    // activate
    //
    bool Benchmark_Data_Collector_exec_i::activate (void)
    {
      // Verify the collector is not already active.
      if (!is_active ())
      {
        // Schedule a timer with the <reactor>.
        ACE_Time_Value interval (this->timeout_);
        this->timer_ = this->reactor ()->schedule_timer (
          this, 0, interval, interval);

        // Activate the task.
        if (ACE_Task_Base::activate () == -1)
        {
          this->reactor ()->cancel_timer (this->timer_);
        }
      }

      // Verify the <timer_> was scheduled.
      return this->timer_ != -1;
    }

    //
    // is_active
    //
    bool Benchmark_Data_Collector_exec_i::is_active (void) const
    {
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
    Benchmark_Data_Collector_exec_i::ciao_postactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      activate ();
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
    Benchmark_Data_Collector_exec_i::ccm_passivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      deactivate ();
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

