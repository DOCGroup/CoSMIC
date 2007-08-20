// -*- C++ -*-

#ifndef _BDC_CONTROL_HANDLE_EXEC_H_
#define _BDC_CONTROL_HANDLE_EXEC_H_

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Benchmark_Data_Collector_exec_export.h"
#include "Benchmark_Data_CollectorEC.h"
#include "tao/LocalObject.h"

// Forward decl.
class CUTS_BDC_Service_Manager;

namespace CUTS
{
  // forward declarations
  class BDC_Task;

  //=========================================================================
  /**
   * @class BDC_Control_Handle_exec_i
   *
   * Implementation of the BDC_Control_Handle interface.
   */
  //=========================================================================

  class BENCHMARK_DATA_COLLECTOR_EXEC_Export BDC_Control_Handle_exec_i :
    public virtual CUTS::CCM_BDC_Control_Handle,
    public virtual TAO_Local_RefCounted_Object
  {
  public:
    /// Constructor.
    BDC_Control_Handle_exec_i (BDC_Task * task,
                               CUTS_BDC_Service_Manager * svc_mgr);

    /// Destructor.
    virtual ~BDC_Control_Handle_exec_i (void);

    /**
     * Force the collection of the performance data from all the component
     * in the system. This is a blocking method and does not return until
     * all components are handled.
     */
    virtual void collect_performance_data (void);

    virtual ::CORBA::ULong
      load_services (const CUTS::BDC_Service_Descriptors & svcs);

    virtual void
      unload_services (const CUTS::BDC_Service_Names & names);

    virtual CUTS::BDC_Service_ptr
      get_service (const char * name);

    virtual void list_services (CUTS::BDC_Service_Names_out);

  private:
    /// Pointer reference to the benchmark data collector.
    BDC_Task * task_;

    /// Pointer to the service manager for the BDC.
    CUTS_BDC_Service_Manager * svc_mgr_;
  };
}

#include /**/ "ace/post.h"

#endif  // !defined _BDC_CONTROL_HANDLE_EXEC_H_
