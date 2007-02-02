// -*- C++ --

#ifndef CIAO_BENCHMARK_DATA_COLLECTOR_EXEC_H
#define CIAO_BENCHMARK_DATA_COLLECTOR_EXEC_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Benchmark_Data_Collector_exec_export.h"
#include "Benchmark_Data_Collector_svnt.h"
#include "BDC_Task.h"
#include "cuts/System_Metric.h"
#include "tao/LocalObject.h"
#include "ace/Manual_Event.h"
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

      virtual void
        set_session_context (Components::SessionContext_ptr ctx
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Components::CCMException));

      virtual void
        ciao_preactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Components::CCMException));

      virtual void
        ciao_postactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Components::CCMException));

      virtual void ccm_activate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Components::CCMException));

      virtual void
        ccm_passivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Components::CCMException));

      virtual void
        ccm_remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Components::CCMException));

      virtual ::CUTS::CCM_Testing_Service_ptr
        get_testing_service (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual ::CUTS::CCM_BDC_Control_Handle_ptr
        get_controls (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual void
        timeout (::CORBA::Long tm ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual ::CORBA::Long
        timeout (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual void
        service (const char * svc ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual char *
        service (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

    private:
      /// Pointer to it context.
      Benchmark_Data_Collector_Context * context_;

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

      ACE_Manual_Event collect_done_;

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
      virtual ::Components::EnterpriseComponent_ptr
        create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException,
                         ::Components::CCMException));
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
