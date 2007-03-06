// $Id$

#include "BDC_Service_Manager.h"

#if !defined (__CUTS_INLINE__)
#include "BDC_Service_Manager.inl"
#endif

#include "BDC_Service.h"
#include "cuts/Component_Info.h"
#include "cuts/Log_Msg.h"
#include "ace/CORBA_macros.h"
#include "ace/Dynamic_Service.h"
#include "ace/Event.h"
#include "ace/Service_Types.h"
#include <sstream>

//
// CUTS_BDC_Service_Manager
//
CUTS_BDC_Service_Manager::CUTS_BDC_Service_Manager (void)
: ACE_Service_Gestalt (ACE_Service_Gestalt::MAX_SERVICES, true, true),
  metrics_ (0)
{
  ACE_Thread_Manager * thr_mgr = 0;
  ACE_NEW_THROW_EX (thr_mgr, ACE_Thread_Manager (), ACE_bad_alloc ());

  this->thr_mgr_.reset (thr_mgr);
}

//
// CUTS_BDC_Service_Manager
//
CUTS_BDC_Service_Manager::~CUTS_BDC_Service_Manager (void)
{

}

//
// close
//
int CUTS_BDC_Service_Manager::close (ACE_Time_Value * timeout)
{
  // Create an iterator to the underlying repo so we can
  // iterate over all the loaded services.
  ACE_Service_Repository_Iterator iter (*this->repo_, 0);
  const ACE_Service_Type * svc_type = 0;

  while (iter.next (svc_type) == 1)
  {
    // Extract the <CUTS_BDC_Service> from the service object.
    const ACE_Service_Type_Impl * type = svc_type->type ();

    CUTS_BDC_Service * svc =
      ACE_reinterpret_cast (CUTS_BDC_Service *, type->object ());

    // Signal the service thread to exit and advance to the
    // next service in the repo.

    if (svc != 0)
    {
      svc->active_ = 0;

      if (svc->handle_deactivate () != 0)
      {
        ACE_ERROR ((LM_ERROR,
                    "%s service failed during handle_deactivate ()\n",
                    svc_type->name ()));
      }
    }

    iter.advance ();
  }

  // Wait for all service threads to exit. Then we can close
  // the underlying service manager in ACE.
  this->notify_->signal ();
  int retval = this->thr_mgr_->wait (timeout);

  retval |= ACE_Service_Gestalt::close ();
  return retval;
}

//
// open
//
int CUTS_BDC_Service_Manager::open (::CORBA::ORB_ptr orb,
                                    CUTS_System_Metric * metrics,
                                    CUTS_Testing_Service * tsvc,
                                    ACE_Event * notify)
{
  if (this->is_opened ())
    return 1;

  // Open the underlying service manager, but we do not allow static
  // services or the default services (e.g., svc.conf). We also want
  // to ingore any debug information.
  this->metrics_ = metrics;
  this->tsvc_ = tsvc;
  this->notify_ = notify;
  this->orb_ = ::CORBA::ORB::_duplicate (orb);

  return ACE_Service_Gestalt::open ("CUTS_BDC",
                                    ACE_DEFAULT_LOGGER_KEY,
                                    1, 1, 1);
}

//
// load_service
//
int CUTS_BDC_Service_Manager::
load_service (const char * name,
              const char * path,
              const char * args)
{
  // Create the directive for the ACE service configurator.
  std::ostringstream dir;
  dir
    << "dynamic " << name << " Service_Object * "
    << path << ":_make_CUTS_BDC_Service() active "
    << "\"" << args << "\"";

  // Let the configurator load the service.
  int errs = ACE_Service_Gestalt::process_directive (dir.str ().c_str ());

  if (errs == 0)
  {
    // We need to locate the service that we just loaded.
    CUTS_BDC_Service * svc =
      ACE_Dynamic_Service <CUTS_BDC_Service>::instance (this, name);

    if (svc != 0)
    {
      // Initialize the parent of the service.
      svc->svc_mgr_ = this;

      if (svc->handle_activate () != 0)
      {
        ACE_ERROR ((LM_ERROR,
                    "*** error: %s failed during handle_activate ()\n",
                    name));

        // Increment the number of errors.
        ++ errs;
      }

      if (errs == 0)
      {
        // Set its <active_> flag and start the service thread.
        svc->active_ = 1;

        // Create the service parameter object for the thread.
        CUTS_BDC_Service::Svc_Thread_Param * param = 0;

        ACE_NEW_THROW_EX (param,
                          CUTS_BDC_Service::Svc_Thread_Param,
                          ACE_bad_alloc ());

        param->svc_ = svc;
        param->notify_ = this->notify_;

        ACE_Auto_Ptr <CUTS_BDC_Service::Svc_Thread_Param> auto_clean (param);

        // Spawn a new thread for the service object.
        if (this->thr_mgr_->spawn (CUTS_BDC_Service::svc, param) != -1)
          auto_clean.release ();
        else
          svc->active_ = 0;
      }
    }
    else
      ++ errs;
  }

  // Return the number of errors that occured.
  return errs;
}

//
// unload_service
//
int CUTS_BDC_Service_Manager::
unload_service (const char * name)
{
  // We need to locate this service.
  CUTS_BDC_Service * svc = 0;

  if (this->get_service (name, svc) == 0)
  {
    // Deactivate the service.
    svc->active_ = 0;

    if (svc->handle_deactivate () != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: %s failed during handle_deactivate ()\n",
                  name));
    }

    // Tell the service configurator to unload the service
    std::ostringstream directive;
    directive << "remove " << name;
    ACE_Service_Gestalt::process_directive (directive.str ().c_str ());
  }

  return 0;
}

//
// handle_component
//
int CUTS_BDC_Service_Manager::
handle_component (const CUTS_Component_Info & info)
{
  // Create an iterator to the underlying repo so we can
  // iterate over all the loaded services.
  ACE_Service_Repository_Iterator iter (*this->repo_, 1);
  const ACE_Service_Type * svc_type = 0;

  while (iter.next (svc_type) == 1)
  {
    // Extract the <CUTS_BDC_Service> from the service object.
    const ACE_Service_Type_Impl * type = svc_type->type ();

    CUTS_BDC_Service * svc =
      ACE_reinterpret_cast (CUTS_BDC_Service *, type->object ());

    // Signal the service thread to exit and advance to the
    // next service in the repo.
    if (svc != 0 &&
        svc->handle_component (info) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: %s failed during handle_component ()\n",
                  type->name ()));
    }

    iter.advance ();
  }

  return 0;
}

//
// get_service
//
int CUTS_BDC_Service_Manager::
get_service (const char * name,
             CUTS_BDC_Service * & svc)
{
  svc = ACE_Dynamic_Service <CUTS_BDC_Service>::instance (this, name);
  return svc != 0 ? 0 : -1;
}

//
// get_service_names
//
void CUTS_BDC_Service_Manager::
get_service_names (CUTS_BDC_Service_Names & names)
{
  // Set the size of names.
  names.resize (this->get_service_count (), 0);

  // Create an iterator to the underlying repo so we can
  // iterate over all the loaded services. We do not want
  // to bypass the suspended services in this case.
  ACE_Service_Repository_Iterator iter (*this->repo_, 0);
  const ACE_Service_Type * svc_type = 0;
  size_t i = 0;

  while (iter.next (svc_type) == 1)
  {
    // Extract the <CUTS_BDC_Service> from the service object
    // and store it's name into the <names> object.
    const ACE_Service_Type_Impl * type = svc_type->type ();
    names[i ++] = type->name ();

    // Move to the next service.
    iter.advance ();
  }
}
