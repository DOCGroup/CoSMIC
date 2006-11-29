// $Id$

#include "BDC_Service.h"

#if !defined (__CUTS_INLINE__)
#include "BDC_Service.inl"
#endif

#include "cuts/System_Metric.h"
#include "ace/Event.h"
#include "ace/Guard_T.h"
#include "ace/Time_Value.h"

//
// CUTS_BDC_Service
//
CUTS_BDC_Service::CUTS_BDC_Service (void)
: metrics_ (0),
  active_ (0)
{

}

//
// svc
//
ACE_THR_FUNC_RETURN CUTS_BDC_Service::svc (void * param)
{
  // We need to get the <Svc_Thread_Param> since it contains
  // the calling object for this thread.
  CUTS_BDC_Service::Svc_Thread_Param * svp =
    ACE_reinterpret_cast (CUTS_BDC_Service::Svc_Thread_Param *, param);
  ACE_Auto_Ptr <CUTS_BDC_Service::Svc_Thread_Param> auto_clean (svp);

  // Get the current timestamp for the metrics before we
  // enter the event loop.
  ACE_Time_Value last_time =
    svp->svc_->metrics_->get_timestamp ();

  while (svp->svc_->active_)
  {
    // Wait for notification then signal the service to handle
    // a new set of metrics!!
    if (last_time == svp->svc_->metrics_->get_timestamp ())
    {
      svp->notify_->wait ();
      svp->notify_->reset ();

      // Let's update our value with the latest timestamp.
      last_time = svp->svc_->metrics_->get_timestamp ();
    }

    // Make an upcall to the service object. There is a chance that
    // we are actually got to this point because we aren't *active*
    // anymore. We therefore need to make sure we are *active*
    // before we make an upcall, or else we can have undesireable
    // effects!!
    if (svp->svc_->active_)
      svp->svc_->handle_metrics ();
  }

  return 0;
}

//
// fini
//
int CUTS_BDC_Service::fini (void)
{
  try
  {
    ::CORBA::release (this->orb_.in ());
    this->orb_ = ::CORBA::ORB::_nil ();
  }
  catch (...)
  {

  }
  return 0;
}

