// $Id$

#include "BDC_Service_Manager.h"

#if !defined (__CUTS_INLINE__)
#include "BDC_Service_Manager.inl"
#endif

#include "BDC_Service.h"
#include "cuts/Component_Info.h"
#include "cuts/Log_Msg.h"
#include "ace/Dynamic_Service.h"
#include "ace/Event.h"
#include "ace/Service_Types.h"
#include "ace/UUID.h"
#include <sstream>

//
// CUTS_BDC_Service_Manager
//
CUTS_BDC_Service_Manager::CUTS_BDC_Service_Manager (void)
: ACE_Service_Gestalt (ACE_Service_Gestalt::MAX_SERVICES, true, true),
  metrics_ (0)
{

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
      reinterpret_cast <CUTS_BDC_Service *> (type->object ());

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

  // Reset the <uuid_> of the service manager.
  this->uuid_.clear ();
  return 0;

  ACE_UNUSED_ARG (timeout);
}

//
// open
//
int CUTS_BDC_Service_Manager::
open (CUTS_System_Metric * metrics,
      CUTS_Testing_Service * tsvc)
{
  if (this->is_opened ())
    return 1;

  // Open the underlying service manager, but we do not allow static
  // services or the default services (e.g., svc.conf). We also want
  // to ingore any debug information.
  this->metrics_ = metrics;
  this->tsvc_ = tsvc;

  if (ACE_Service_Gestalt::open ("CUTS_BDC",
                                 ACE_DEFAULT_LOGGER_KEY,
                                 1, 1, 1) == -1)
  {
    return -1;
  }

  return this->activate ();
}

//
// load_service
//
int CUTS_BDC_Service_Manager::
load_service (const char * name, const char * path,  const char * args)
{
  // Create the directive for the ACE service configurator.
  std::ostringstream dir;
  dir
    << "dynamic " << name << " Service_Object * "
    << path << ":_make_CUTS_BDC_Service() active ";

  if (args != 0)
    dir << "\"" << args << "\"";

  // Let the configurator load the service.
  int error_count =
    ACE_Service_Gestalt::process_directive (dir.str ().c_str ());

  if (error_count == 0)
  {
    const ACE_Service_Type * svc_type = 0;

    // We need to locate the service that we just loaded.
    if (this->find (name, &svc_type) == 0)
      {
        const ACE_Service_Type_Impl * type = svc_type->type ();

        CUTS_BDC_Service * svc =
          reinterpret_cast <CUTS_BDC_Service *> (type->object ());

        if (svc != 0)
          {
            // Initialize the parent of the service. Then try to activate
            // the service.
            svc->svc_mgr_ = this;

            if (svc->handle_activate () != 0)
              {
                ACE_ERROR ((LM_ERROR,
                            "%s service failed during handle_activate ()\n",
                            name));

                ++ error_count;
              }
          }
      }
    else
      {
        ACE_ERROR ((LM_DEBUG,
                    "*** error (BDC): failed to locate service %s "
                    "for initialization\n",
                    name));
      }
  }

  // Return the number of errors that occured.
  return error_count;
}

//
// unload_service
//
int CUTS_BDC_Service_Manager::unload_service (const char * name)
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
      reinterpret_cast <CUTS_BDC_Service *> (type->object ());

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
int CUTS_BDC_Service_Manager::get_service (const char * name,
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

//
// activate
//
int CUTS_BDC_Service_Manager::activate (void)
{
  // Create an iterator to the underlying repo so we can
  // iterate over all the loaded services.
  if (!this->is_opened ())
    return -1;

  if (this->uuid_.is_empty ())
  {
    // Since the <uuid_> is empty, we need to generate one.
    ACE_Utils::UUID uuid;
    ACE_Utils::UUID_GENERATOR::instance ()->generate_UUID (uuid);

    this->uuid_ = *uuid.to_string ();
  }

  // Iterate over every service in the repository.
  ACE_Service_Repository_Iterator iter (*this->repo_, 1);
  const ACE_Service_Type * svc_type = 0;

  while (iter.next (svc_type) == 1)
  {
    // Extract the <CUTS_BDC_Service> from the service object.
    const ACE_Service_Type_Impl * type = svc_type->type ();

    CUTS_BDC_Service * svc =
      reinterpret_cast <CUTS_BDC_Service *> (type->object ());

    if (svc == 0 &&
        svc->handle_activate () != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "%s service failed during handle_activate ()\n",
                  type->name ()));
    }

    iter.advance ();
  }

  return 0;
}

//
// deactivate
//
int CUTS_BDC_Service_Manager::deactivate (void)
{
  // Create an iterator to the underlying repo so we can
  // iterate over all the loaded services.
  if (!this->is_opened ())
    return -1;

  ACE_Service_Repository_Iterator iter (*this->repo_, 1);
  const ACE_Service_Type * svc_type = 0;

  while (iter.next (svc_type) == 1)
  {
    // Extract the <CUTS_BDC_Service> from the service object.
    const ACE_Service_Type_Impl * type = svc_type->type ();

    CUTS_BDC_Service * svc =
      reinterpret_cast <CUTS_BDC_Service *> (type->object ());

    // Signal the service thread to exit and advance to the
    // next service in the repo.
    if (svc != 0 &&
        svc->handle_deactivate () != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: %s failed during handle_deactivate ()\n",
                  type->name ()));
    }

    iter.advance ();
  }

  // Release the current UUID.
  this->uuid_.clear ();
  return 0;
}

//
// deactivate
//
int CUTS_BDC_Service_Manager::
handle_metrics (const CUTS_System_Metric & metrics)
{
  // Create an iterator to the underlying repo so we can
  // iterate over all the loaded services.
  if (!this->is_opened ())
    return -1;

  ACE_Service_Repository_Iterator iter (*this->repo_, 1);
  const ACE_Service_Type * svc_type = 0;

  while (iter.next (svc_type) == 1)
  {
    // Extract the <CUTS_BDC_Service> from the service object.
    const ACE_Service_Type_Impl * type = svc_type->type ();

    CUTS_BDC_Service * svc =
      reinterpret_cast <CUTS_BDC_Service *> (type->object ());

    // Signal the service thread to exit and advance to the
    // next service in the repo.
    if (svc != 0 &&
        svc->handle_metrics (metrics) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: %s failed during handle_metrics ()\n",
                  type->name ()));
    }

    iter.advance ();
  }

  return 0;
}
