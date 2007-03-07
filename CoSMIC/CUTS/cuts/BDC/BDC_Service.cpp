// $Id$

#include "BDC_Service.h"

#if !defined (__CUTS_INLINE__)
#include "BDC_Service.inl"
#endif

//
// CUTS_BDC_Service
//
CUTS_BDC_Service::CUTS_BDC_Service (void)
: svc_mgr_ (0),
  active_ (0)
{

}

//
// svc
//
//ACE_THR_FUNC_RETURN CUTS_BDC_Service::svc (void * param)
//{
//  // We need to get the <Svc_Thread_Param> since it contains
//  // the calling object for this thread.
//  CUTS_BDC_Service::Svc_Thread_Param * svp =
//    ACE_reinterpret_cast (CUTS_BDC_Service::Svc_Thread_Param *, param);
//  ACE_Auto_Ptr <CUTS_BDC_Service::Svc_Thread_Param> auto_clean (svp);
//
//  // Get current timestamp for metrics before entering loop.
//  CUTS_System_Metric * metric = svp->svc_->svc_mgr ()->metrics ();
//  ACE_Time_Value last_time = metric->get_timestamp ();
//
//  while (svp->svc_->is_active ())
//  {
//    // Wait for notification then signal the service to handle
//    // a new set of metrics!!
//    if (last_time == metric->get_timestamp ())
//    {
//      svp->notify_->wait ();
//      svp->notify_->reset ();
//
//      // Let's update our value with the latest timestamp.
//      last_time = metric->get_timestamp ();
//    }
//
//    // Make an upcall to the service object. There is a chance that
//    // we are actually got to this point because we aren't *active*
//    // anymore. We therefore need to make sure we are *active*
//    // before we make an upcall, or else we can have undesireable
//    // effects!!
//    if (svp->svc_->is_active ())
//      svp->svc_->handle_metrics ();
//  }
//
//  return 0;
//}
