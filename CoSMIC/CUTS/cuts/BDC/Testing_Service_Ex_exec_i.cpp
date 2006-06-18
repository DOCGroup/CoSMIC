// $Id: Testing_Service_Ex_exec_i.cpp,v 1.1.4.1.2.1 2006/06/15 04:01:10 hillj Exp $

#include "Testing_Service_Ex_exec_i.h"
#include "cuts/svcs/dbase/DBase_Service.h"

namespace CUTS
{
  //
  // Testing_Service_Ex_exec_i
  //
  Testing_Service_Ex_exec_i::Testing_Service_Ex_exec_i (
    CUTS_Database_Service & database_service)
    : database_service_ (database_service)
  {

  }

  //
  // ~Testing_Service_Ex_exec_i
  //
  Testing_Service_Ex_exec_i::~Testing_Service_Ex_exec_i (void)
  {

  }

  //
  // register_component
  //
  ::CORBA::Long
    Testing_Service_Ex_exec_i::register_component (
      const ::CUTS::Component_Registration & creg
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::CUTS::Registration_Failed,
                       ::CUTS::Registration_Limit))
  {
    // Insert the IP-address -> hostname mapping into the database
    // before continuing w/ the registration of the component.
    this->database_service_.register_host (creg.ipaddr,
                                           creg.hostname.in ());

    long regid = Testing_Service_exec_i::register_component (creg);

    if (regid != 0)
    {
      // We need to register the component with the database
      // service since the registration was successful.
      if (this->database_service_.register_component (regid,
                                                      creg.name.in ()))
      {
        ACE_DEBUG ((LM_DEBUG,
                    "[%M] -%T - registerd %s with the database service\n",
                    creg.name.in ()));
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
                    "[%M] -%T - failed to register %s with database\n",
                    creg.name.in ()));
      }
    }

    return regid;
  }
}
