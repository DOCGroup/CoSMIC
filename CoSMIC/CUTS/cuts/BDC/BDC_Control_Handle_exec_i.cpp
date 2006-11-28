// $Id$

#include "BDC_Control_Handle_exec_i.h"
#include "BDC_Task.h"
#include "BDC_Service.h"
#include "BDC_Service_Manager.h"
#include "cuts/Log_Msg.h"

namespace CUTS
{
  //
  // BDC_Control_Handle_exec_i
  //
  BDC_Control_Handle_exec_i::
  BDC_Control_Handle_exec_i (BDC_Task * task,
                             CUTS_BDC_Service_Manager * svc_mgr)
  : task_ (task),
    svc_mgr_ (svc_mgr)
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
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    if (this->task_ != 0)
    {
      // Notify the <task_> to begin collection.
      this->task_->collect_data ();

      CUTS_DEBUG (LM_DEBUG,
                  "waiting for data collection to complete\n");

      // Wait for signaling of the <collection_done_> event.
      this->task_->wait_for_collection_done ();

      CUTS_DEBUG (LM_DEBUG,
                  "collection of performance data is complete\n");
    }
    else
    {
      CUTS_ERROR (LM_ERROR,
                  "control handle missing BDC task reference\n");
    }
  }

  //
  // load_services
  //
  ::CORBA::ULong BDC_Control_Handle_exec_i::
    load_services (const CUTS::BDC_Service_Descriptors & svcs
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    size_t success = 0;
    size_t length = svcs.length ();

    for (size_t i = 0; i < length; i ++)
    {
      const CUTS::BDC_Service_Descriptor & svc = svcs[i];

      int retval =
        this->svc_mgr_->load_service (svc.name.in (),
                                      svc.path.in (),
                                      svc.args.in ());

      if (retval == 0)
      {
        ++ success;
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
                    "failed to load service '%s'\n",
                    svc.name.in ()));
      }
    }

    return success;
  }

  //
  // unload_services
  //
  void BDC_Control_Handle_exec_i::
    unload_services (const CUTS::BDC_Service_Names & names
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    size_t length = names.length ();

    for (size_t i = 0; i < length; i ++)
    {
      if (this->svc_mgr_->unload_service (names[i]) != 0)
      {
        ACE_ERROR ((LM_ERROR,
                    "failed to unload service '%s'\n",
                    names[i]));
      }
    }
  }

  //
  // get_service
  //
  CUTS::BDC_Service_ptr BDC_Control_Handle_exec_i::
    get_service (const char * name
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    CUTS_BDC_Service * svc = 0;
    int retval = this->svc_mgr_->get_service (name, svc);

    // @@ Eventually we will want to throw an exception if we can't
    // find the service (i.e., Service_Unavailable or Service_Not_Found).
    return retval == 0 && svc != 0 ?
           svc->get_remote_object () :
           CUTS::BDC_Service::_nil ();
  }

  //
  // list_services
  //
  void BDC_Control_Handle_exec_i::
    list_services (CUTS::BDC_Service_Names_out)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {

  }
}
