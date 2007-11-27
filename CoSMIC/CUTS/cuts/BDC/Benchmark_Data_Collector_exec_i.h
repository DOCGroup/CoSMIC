// -*- C++ --

#ifndef CIAO_BENCHMARK_DATA_COLLECTOR_EXEC_H
#define CIAO_BENCHMARK_DATA_COLLECTOR_EXEC_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Benchmark_Data_Collector_exec_export.h"
#include "Benchmark_Data_CollectorEC.h"
#include "BDC_Task.h"
#include "cuts/System_Metric.h"
#include "tao/LocalObject.h"
#include "ace/SString.h"

namespace CUTS
{
  // Forward decl.
  class Path_Measurement_exec_i;

  // Forward decl.
  class BDC_Control_Handle_exec_i;

  namespace CIDL_Benchmark_Data_Collector_Impl
  {
    //=========================================================================
    /**
     * @class Benchmark_Data_Collector_exec_i
     *
     * @brief Executor implementation of the Benchmark_Data_Collector
     * component.
     */
    //=========================================================================

    class BENCHMARK_DATA_COLLECTOR_EXEC_Export Benchmark_Data_Collector_exec_i :
      public virtual Benchmark_Data_Collector_Exec,
      public virtual TAO_Local_RefCounted_Object
    {
    public:
      /// Constructor.
      Benchmark_Data_Collector_exec_i (void);

      /// Destructor.
      virtual ~Benchmark_Data_Collector_exec_i (void);

      virtual void set_session_context (
        ::Components::SessionContext::_ptr_type ctx);

      virtual void ciao_preactivate (void);

      virtual void ciao_postactivate (void);

      virtual void ccm_activate (void);

      virtual void ccm_passivate (void);

      virtual void ccm_remove (void);

      virtual ::CUTS::CCM_Testing_Service_ptr
        get_testing_service (void);

      virtual ::CUTS::CCM_BDC_Control_Handle_ptr
        get_controls (void);

      virtual void timeout (::CORBA::Long tm);

      virtual ::CORBA::Long timeout (void);

      virtual void service (const char * svc);

      virtual char * service (void);

      virtual void test_uuid (const char * uuid);

      virtual char * test_uuid (void);

    private:
      /// Pointer to it context.
      ::CUTS::CCM_Benchmark_Data_Collector_Context::_var_type context_;

      /// Testing service object.
      ACE_Auto_Ptr <Testing_Service_exec_i> tsvc_;

      /// Path measurement object.
      ACE_Auto_Ptr <BDC_Control_Handle_exec_i> controller_;

      /// Active object for collecting metrics.
      BDC_Task task_;

      /// Timeout value for the data collection.
      long timeout_;

      /// System metrics database.
      CUTS_System_Metric metrics_;

      /// Listing of all the services.
      ACE_CString svcs_;
    };

    //=========================================================================
    /**
     * @class Benchmark_Data_Collector_Home_exec_i
     *
     * @brief Implemenation of the Benchmark_Data_Collector_Home
     */
    //=========================================================================

    class BENCHMARK_DATA_COLLECTOR_EXEC_Export Benchmark_Data_Collector_Home_exec_i
    : public virtual Benchmark_Data_Collector_Home_Exec,
      public virtual TAO_Local_RefCounted_Object
    {
    public:
      /// Constructor.
      Benchmark_Data_Collector_Home_exec_i (void);

      /// Destructor.
      virtual ~Benchmark_Data_Collector_Home_exec_i (void);

      /**
       * Creation method.
       *
       * @return Newly created Benchmark_Data_Collector component.
       */
      virtual ::Components::EnterpriseComponent_ptr create (void);
    };
  }
}

//=========================================================================
/**
  * Entry point for the Benchmark_Data_Collector executor.
  *
  * @return Reference to the factory object for creating the
  * Benchmark_Data_Collector component.
  */
//=========================================================================

extern "C" BENCHMARK_DATA_COLLECTOR_EXEC_Export
::Components::HomeExecutorBase_ptr
create_CUTS_Benchmark_Data_Collector_Home_Impl (void);

#include /**/ "ace/post.h"

#endif /* CIAO_BENCHMARK_DATA_COLLECTOR_EXEC_H */
