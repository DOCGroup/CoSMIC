// $Id$

#ifndef CIAO_CUTS_EXEC_H
#define CIAO_CUTS_EXEC_H

#include /**/ "ace/pre.h"

#include "CUTS_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "CUTS_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/Task.h"
#include "ace/Time_Value.h"
#include "ace/Message_Queue_T.h"
#include "ace/Reactor_Notification_Strategy.h"
#include "ace/Event.h"

namespace CUTS
{
  namespace CIDL_Benchmark_Data_Collector_Impl
  {
    // forward declarations
    class Benchmark_Data_Collector_exec_i;

    //=========================================================================
    /**
     * @class Path_Measurement_exec_i
     */
    //=========================================================================

    class CUTS_EXEC_Export Path_Measurement_exec_i :
      public virtual ::CUTS::CCM_Path_Measurment,
      public virtual TAO_Local_RefCounted_Object
    {
    public:
      Path_Measurement_exec_i (void);

      virtual ~Path_Measurement_exec_i (void);

      virtual CORBA::Long bind_to_path (
        const ::CUTS::Path_Sequence & path
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual void unbind_to_path (
          ::CORBA::Long path_id
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual ::CORBA::Long execution_time (
          ::CORBA::Long path_id
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((::CORBA::SystemException));

    private:
      // pointer to shared measurements container
    };

    //=========================================================================
    /**
     * @class BDC_Control_Handle_exec_i
     */
    //=========================================================================

    class CUTS_EXEC_Export BDC_Control_Handle_exec_i :
      public virtual ::CUTS::CCM_BDC_Control_Handle,
      public virtual TAO_Local_RefCounted_Object
    {
    public:
      /// Constructor.
      BDC_Control_Handle_exec_i (Benchmark_Data_Collector_exec_i * bdc_exec);

      /// Destructor.
      virtual ~BDC_Control_Handle_exec_i (void);

      virtual void
        collect_performance_data (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

    private:
      /// Pointer reference to the benchmark data collector.
      Benchmark_Data_Collector_exec_i * bdc_exec_;
    };

    //=========================================================================
    /**
     * @class Benchmark_Data_Collector_exec_i
     */
    //=========================================================================

    class CUTS_EXEC_Export Benchmark_Data_Collector_exec_i
    : public virtual Benchmark_Data_Collector_Exec,
      public virtual TAO_Local_RefCounted_Object,
      public ACE_Task_Base
    {
    public:
      Benchmark_Data_Collector_exec_i (void);

      virtual ~Benchmark_Data_Collector_exec_i (void);

      bool activate (void);

      void deactivate (void);

      bool is_active (void) const;

      void collect_performance_data (void);

      virtual char *
      server_name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      server_name (
        const char *
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::CORBA::Long
      timeout (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
        timeout (
        ::CORBA::Long
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::CUTS::CCM_BDC_Control_Handle_ptr
        get_controls (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual ::CUTS::CCM_Path_Measurment_ptr
        get_online_measurements (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException));

      virtual void
      set_session_context (
        ::Components::SessionContext_ptr ctx
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                        ::CORBA::SystemException,
                        ::Components::CCMException));

      virtual void
      ciao_preactivate (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                        ::CORBA::SystemException,
                        ::Components::CCMException));

      virtual void
      ciao_postactivate (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                        ::CORBA::SystemException,
                        ::Components::CCMException));

      virtual void
      ccm_activate (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                        ::CORBA::SystemException,
                        ::Components::CCMException));

      virtual void
      ccm_passivate (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                        ::CORBA::SystemException,
                        ::Components::CCMException));

      virtual void
      ccm_remove (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                        ::CORBA::SystemException,
                        ::Components::CCMException));

    protected:
      /// Context for this object.
      Benchmark_Data_Collector_Context *context_;

    private:
      /// Callback handle for timeout events.
      int handle_timeout (const ACE_Time_Value & current_time, const void * act);

      /// Callback handle for input events.
      int handle_input (ACE_HANDLE fd);

      /// Service handling routine.
      int svc (void);

      /// Timeout value for collecting data.
      long timeout_;

      /// ID of the timer created by the reactor.
      long timer_;

      /// Current active state of the task.
      bool active_;

      /// The start time for collecting performance metrics.
      ACE_Time_Value collection_start_;

      /// The stop time for collecting performance metrics.
      ACE_Time_Value collection_stop_;

      /// Notification strategy for the <closed_list_>.
      ACE_Auto_Ptr <ACE_Reactor_Notification_Strategy> notify_strategy_;

      /// Collection of free activation records.
      ACE_Message_Queue_Ex <
        ::CUTS::Benchmark_Agent,
        ACE_MT_SYNCH> bma_queue_;

      ACE_Auto_Ptr <BDC_Control_Handle_exec_i> bdc_control_handle_;

      ACE_Thread_Mutex collection_mutex_;

      ACE_Thread_Mutex write_mutex_;
    };

    //=========================================================================
    /**
     * @class Benchmark_Data_Collector_Home_exec_i
     */
    //=========================================================================

    class CUTS_EXEC_Export Benchmark_Data_Collector_Home_exec_i
    : public virtual Benchmark_Data_Collector_Home_Exec,
    public virtual TAO_Local_RefCounted_Object
    {
      public:
      Benchmark_Data_Collector_Home_exec_i (void);
      virtual ~Benchmark_Data_Collector_Home_exec_i (void);

      // Supported or inherited operations.

      // Home operations.

      // Factory and finder operations.

      // Attribute operations.

      // Implicit operations.

      virtual ::Components::EnterpriseComponent_ptr
      create (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
                        ::CORBA::SystemException,
                        ::Components::CCMException));
    };

    extern "C" CUTS_EXEC_Export ::Components::HomeExecutorBase_ptr
    createBenchmark_Data_Collector_Home_Impl (void);
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_CUTS_EXEC_H */

