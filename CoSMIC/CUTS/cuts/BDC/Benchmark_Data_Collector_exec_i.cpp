// $Id$

#include "Benchmark_Data_Collector_exec_i.h"
#include "BDC_Control_Handle_exec_i.h"
#include "BDC_Service_Manager.h"
#include "BDC_Control_Handle_exec_i.h"
#include "Testing_Service_exec_i.h"
#include "cuts/Log_Msg.h"

namespace CUTS
{
  namespace CIDL_Benchmark_Data_Collector_Impl
  {
    //
    // Benchmark_Data_Collector_exec_i
    //
    Benchmark_Data_Collector_exec_i::Benchmark_Data_Collector_exec_i (void)
    : context_ (0),
      timeout_ (10)   /* default is 10 seconds */
    {
      // Create a new <Testing_Service_Ex_exec_i> object.
      Testing_Service_exec_i * tsvc = 0;

      ACE_NEW_THROW_EX (tsvc,
                        Testing_Service_exec_i (&this->registry_),
                        ::CORBA::NO_MEMORY ());

      this->tsvc_.reset (tsvc);

      // Create a new <BDC_Control_Handle_exec_i> object and store it
      // in the implemenation.
      BDC_Control_Handle_exec_i * handle = 0;

      ACE_NEW_THROW_EX (handle,
                        BDC_Control_Handle_exec_i (
                        &this->task_, CUTS_BDC_SVC_MANAGER ()),
                        ::CORBA::NO_MEMORY ());

      this->controller_.reset (handle);
    }

    //
    // ~Benchmark_Data_Collector_exec_i
    //
    Benchmark_Data_Collector_exec_i::~Benchmark_Data_Collector_exec_i (void)
    {

    }

    //
    // set_session_context
    //
    void Benchmark_Data_Collector_exec_i::set_session_context (
      ::Components::SessionContext_ptr ctx ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {
      this->context_ =
        Benchmark_Data_Collector_Context::_narrow (ctx ACE_ENV_ARG_PARAMETER);

      ACE_CHECK;

      if (this->context_ == 0)
        ACE_THROW (::CORBA::INTERNAL ());

      CORBA::ORB_var orb =
        this->context_->_ciao_the_Container ()->the_ORB ();

      CUTS_BDC_SVC_MANAGER ()->open (orb.in (),
                                     &this->metrics_,
                                     &this->collect_done_);
    }

    //
    // ciao_preactivate
    //
    void Benchmark_Data_Collector_exec_i::ciao_preactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {
      this->registry_.register_handler (CUTS_BDC_SVC_MANAGER ());
      this->registry_.open ();
    }

    //
    // ciao_postactivate
    //
    void Benchmark_Data_Collector_exec_i::ciao_postactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {

    }

    //
    // ccm_activate
    //
    void Benchmark_Data_Collector_exec_i::ccm_activate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {
      ACE_Time_Value delay (this->timeout_);

      if (!this->task_.activate (delay,
                                 delay,
                                 this->tsvc_.get (),
                                 &this->metrics_,
                                 &this->collect_done_))
      {
        CUTS_ERROR (LM_ERROR, "failed to activate data collector\n");
      }
    }

    //
    // ccm_passivate
    //
    void Benchmark_Data_Collector_exec_i::ccm_passivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {
      this->task_.deactivate ();
    }

    //
    // ccm_remove
    //
    void Benchmark_Data_Collector_exec_i::ccm_remove (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Components::CCMException))
    {
      // Unregister the service manager from the <registry_>. Then
      // we can actually close the <CUTS_BDC_SVC_MANAGER>.
      this->registry_.unregister_handler (CUTS_BDC_SVC_MANAGER ());
      CUTS_BDC_SVC_MANAGER ()->close ();

      // Now, lets close the <registry_>.
      this->registry_.close ();
    }

    //
    // timeout
    //
    void Benchmark_Data_Collector_exec_i::timeout (
      ::CORBA::Long tm ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      this->timeout_ = tm;

      // TODO if the object is already active, we need to reshedule
      // the timer to the new timeout value.
    }

    //
    // timeout
    //
    ::CORBA::Long Benchmark_Data_Collector_exec_i::
      timeout (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      return this->timeout_;
    }

    //
    // get_testing_service
    //
    ::CUTS::CCM_Testing_Service_ptr
      Benchmark_Data_Collector_exec_i::
      get_testing_service (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      return ::CUTS::CCM_Testing_Service::_duplicate (this->tsvc_.get ());
    }

    //
    // get_controls
    //
    ::CUTS::CCM_BDC_Control_Handle_ptr
      Benchmark_Data_Collector_exec_i::
      get_controls (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      return ::CUTS::CCM_BDC_Control_Handle::_duplicate (this->controller_.get ());
    }

    //
    // service
    //
    void Benchmark_Data_Collector_exec_i::
      service (const char * svc ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      // Save the service attribute.
      this->svcs_ = svc;
      char * svc_temp = ACE_OS::strdup (svc);

      // Extract the name.
      char * svc_name = svc_temp;

      // Extract the path.
      char * svc_path = ACE_OS::strchr (svc_temp, ' ');
      *svc_path ++ = '\0';

      // Extract the arguments.
      char * svc_args = ACE_OS::strchr (svc_path, ' ');
      *svc_args ++ = '\0';

      if (CUTS_BDC_SVC_MANAGER ()->load_service (svc_name,
                                                 svc_path,
                                                 svc_args) != 0)
      {
        ACE_ERROR ((LM_ERROR,
                    "failed to load service '%s'\n",
                    svc_name));
      }

      delete [] svc_temp;
    }

    //
    // service
    //
    char * Benchmark_Data_Collector_exec_i::
      service (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException))
    {
      ::CORBA::String_var svcs =
        CORBA::string_dup (this->svcs_.c_str ());

      return svcs._retn ();
    }

    //==================================================================
    // Benchmark_Data_Collector_Home_exec_i
    //==================================================================

    Benchmark_Data_Collector_Home_exec_i::Benchmark_Data_Collector_Home_exec_i (void)
    {

    }

    Benchmark_Data_Collector_Home_exec_i::~Benchmark_Data_Collector_Home_exec_i (void)
    {

    }

    ::Components::EnterpriseComponent_ptr
    Benchmark_Data_Collector_Home_exec_i::create (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
                      ::CORBA::SystemException,
                      ::Components::CCMException))
    {
      ::Components::EnterpriseComponent_ptr retval =
        ::Components::EnterpriseComponent::_nil ();

      ACE_NEW_THROW_EX (retval,
                        Benchmark_Data_Collector_exec_i,
                        ::CORBA::NO_MEMORY ());

      ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());

      return retval;
    }

    extern "C" BENCHMARK_DATA_COLLECTOR_EXEC_Export
      ::Components::HomeExecutorBase_ptr
      create_CUTS_Benchmark_Data_Collector_Home_Impl (void)
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
