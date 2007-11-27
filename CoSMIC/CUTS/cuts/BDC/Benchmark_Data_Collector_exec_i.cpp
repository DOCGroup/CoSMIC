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
                        Testing_Service_exec_i (),
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
    void Benchmark_Data_Collector_exec_i::
    set_session_context (::Components::SessionContext::_ptr_type ctx)
    {
      this->context_ =
        ::CUTS::CCM_Benchmark_Data_Collector_Context::_narrow (ctx);

      if (::CORBA::is_nil (this->context_.in ()))
        throw ::CORBA::INTERNAL ();

      CUTS_BDC_SVC_MANAGER ()->open (&this->metrics_,
                                     this->tsvc_.get ());
    }

    //
    // ciao_preactivate
    //
    void Benchmark_Data_Collector_exec_i::ciao_preactivate (void)
    {
      // Register the service manager with the registry.
      this->tsvc_->registry ().register_handler (CUTS_BDC_SVC_MANAGER ());
      this->tsvc_->registry ().open ();

      // Register the service manager with the task.
      this->task_.register_handler (CUTS_BDC_SVC_MANAGER ());
    }

    //
    // ciao_postactivate
    //
    void Benchmark_Data_Collector_exec_i::ciao_postactivate (void)
    {

    }

    //
    // ccm_activate
    //
    void Benchmark_Data_Collector_exec_i::ccm_activate (void)
    {
      ACE_Time_Value delay (this->timeout_, 0);

      if (!this->task_.activate (delay,
                                 delay,
                                 this->tsvc_.get (),
                                 &this->metrics_))
      {
        ACE_ERROR ((LM_ERROR,
                    "*** error (BDC): failed to activate data collector\n"));
      }
    }

    //
    // ccm_passivate
    //
    void Benchmark_Data_Collector_exec_i::ccm_passivate (void)
    {
      this->task_.deactivate ();
    }

    //
    // ccm_remove
    //
    void Benchmark_Data_Collector_exec_i::ccm_remove (void)
    {
      // Unregister the service manager from the <registry_>. Then
      // we can actually close the <CUTS_BDC_SVC_MANAGER>.
      this->tsvc_->registry ().unregister_handler (CUTS_BDC_SVC_MANAGER ());
      CUTS_BDC_SVC_MANAGER ()->close ();

      // Now, lets close the <registry_>.
      this->tsvc_->registry ().close ();
    }

    //
    // timeout
    //
    void Benchmark_Data_Collector_exec_i::timeout (::CORBA::Long tm)
    {
      this->timeout_ = tm;
    }

    //
    // timeout
    //
    ::CORBA::Long Benchmark_Data_Collector_exec_i::timeout (void)
    {
      return this->timeout_;
    }

    //
    // get_testing_service
    //
    ::CUTS::CCM_Testing_Service_ptr
      Benchmark_Data_Collector_exec_i::get_testing_service (void)
    {
      return ::CUTS::CCM_Testing_Service::_duplicate (this->tsvc_.get ());
    }

    //
    // get_controls
    //
    ::CUTS::CCM_BDC_Control_Handle_ptr
      Benchmark_Data_Collector_exec_i::get_controls (void)
    {
      return ::CUTS::CCM_BDC_Control_Handle::_duplicate (this->controller_.get ());
    }

    //
    // test_uuid
    //
    void Benchmark_Data_Collector_exec_i::test_uuid (const char * uuid)
    {
      CUTS_BDC_SVC_MANAGER ()->set_uuid (uuid);
    }

    //
    // test_uuid
    //
    char * Benchmark_Data_Collector_exec_i::test_uuid (void)
    {
      CORBA::String_var str =
        CORBA::string_dup (CUTS_BDC_SVC_MANAGER ()->get_uuid ().c_str ());

      return str._retn ();
    }

    //
    // service
    //
    void Benchmark_Data_Collector_exec_i::service (const char * svc)
    {
      // Save the service attribute.
      this->svcs_ = svc;

      // Create a tokenizer for separating each service. We need to create
      // a temporary copy of the source string.
      ACE_Auto_String_Free tempstr (ACE_OS::strdup (svc));
      ACE_Tokenizer services_str (tempstr.get ());
      services_str.delimiter_replace (';', 0);

      size_t loaded_svcs = 0, failed_svcs = 0;
      char * svc_next = 0, * svc_name = 0, * svc_path = 0, * svc_args = 0;

      while ((svc_next = services_str.next ()) != 0)
      {
        // Parse the next service to extract its name, path, and
        // command-line arguments. The name and path are not allowed
        // to have spaces right now.
        svc_name = svc_next;

        // Get the path.
        svc_path = ACE_OS::strchr (svc_name, ' ');

        if (svc_path != 0)
          *svc_path ++ = '\0';

        // Get the arguments.
        svc_args = ACE_OS::strchr (svc_path, ' ');

        if (svc_args != 0)
          *svc_args ++ = '\0';

        if (svc_name != 0 && svc_path != 0)
        {
          // Attempt to load the service into the BDC service
          // manager.
          if (CUTS_BDC_SVC_MANAGER ()->load_service (svc_name,
                                                     svc_path,
                                                     svc_args) == 0)
          {
            ++ loaded_svcs;
          }
          else
          {
            ACE_ERROR ((LM_ERROR,
                        "*** error (BDC): failed to load "
                        "service '%s' from %s\n",
                        svc_name,
                        svc_path));

            ++ failed_svcs;
          }
        }
        else
        {
          if (svc_name == 0)
          {
            ACE_ERROR ((LM_ERROR,
                        "*** error (BDC): service is missing name\n"));
          }

          if (svc_path == 0)
          {
            ACE_ERROR ((LM_ERROR,
                        "*** error (BDC): service %s is missing path\n",
                        svc_name));
          }
        }
      }

      // Display a useful message to the
      ACE_DEBUG ((LM_INFO,
                  "*** info (BDC): successfully loaded %u service(s); "
                  "failed to %u service(s)\n",
                  loaded_svcs,
                  failed_svcs));
    }

    //
    // service
    //
    char * Benchmark_Data_Collector_exec_i::service (void)
    {
      ::CORBA::String_var svcs =
        CORBA::string_dup (this->svcs_.c_str ());

      return svcs._retn ();
    }

    //==================================================================
    // Benchmark_Data_Collector_Home_exec_i
    //==================================================================

    //
    // Benchmark_Data_Collector_Home_exec_i
    //
    Benchmark_Data_Collector_Home_exec_i::
      Benchmark_Data_Collector_Home_exec_i (void)
    {

    }

    //
    // ~Benchmark_Data_Collector_Home_exec_i
    //
    Benchmark_Data_Collector_Home_exec_i::
      ~Benchmark_Data_Collector_Home_exec_i (void)
    {

    }

    //
    // create
    //
    ::Components::EnterpriseComponent_ptr
      Benchmark_Data_Collector_Home_exec_i::create (void)
    {
      ::Components::EnterpriseComponent_ptr retval =
        ::Components::EnterpriseComponent::_nil ();

      ACE_NEW_THROW_EX (retval,
                        Benchmark_Data_Collector_exec_i,
                        ::CORBA::NO_MEMORY ());

      return retval;
    }
  }
}

//
// create_CUTS_Benchmark_Data_Collector_Home_Impl
//
::Components::HomeExecutorBase_ptr
create_CUTS_Benchmark_Data_Collector_Home_Impl (void)
{
  ::Components::HomeExecutorBase_ptr retval =
    ::Components::HomeExecutorBase::_nil ();

  ACE_NEW_RETURN (retval,
                  CUTS::CIDL_Benchmark_Data_Collector_Impl::
                  Benchmark_Data_Collector_Home_exec_i,
                  ::Components::HomeExecutorBase::_nil ());

  return retval;
}
