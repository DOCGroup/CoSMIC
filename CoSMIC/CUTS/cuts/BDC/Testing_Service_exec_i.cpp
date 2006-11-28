// $Id$

#include "Testing_Service_exec_i.h"

#if !defined (__CUTS_INLINE__)
#include "Testing_Service_exec_i.inl"
#endif

#include "CCM_Component_Registry.h"
#include <typeinfo>

namespace CUTS
{
  //
  // Testing_Service_exec_i
  //
  Testing_Service_exec_i::
  Testing_Service_exec_i (CCM_Component_Registry * registry)
  : CUTS_Testing_Service (registry)
  {

  }

  //
  // ~Testing_Service_exec_i
  //
  Testing_Service_exec_i::~Testing_Service_exec_i (void)
  {

  }

  //
  // register_component
  //
  ::CORBA::Long Testing_Service_exec_i::register_component (
    const ::CUTS::Component_Registration & creg
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::CUTS::Registration_Failed,
                     ::CUTS::Registration_Limit))
  {
    // Check for a NIL <agent> and print a warning message if there
    // is one. Usually this means there is something wrong w/ the
    // template code that activates the <agent>!!!
    if (::CORBA::is_nil (creg.agent.in ()))
    {
      ACE_ERROR ((LM_WARNING,
                  "[%M] -%T - component %s has NIL agent\n",
                  creg.name.in ()));
    }

    // Bind the IP-address to the hostname.
    long result = this->host_table().bind(creg.ipaddr.in (),
                                          creg.hostname.in());

    if (result == -1)
    {
      ACE_ERROR ((LM_WARNING,
                  "[%M] -%T - failed to bind %s to %s\n",
                  creg.ipaddr.in (),
                  creg.hostname.in ()));
    }

    // Get the correct implementation of the <registry_>.
    CCM_Component_Registry * registry = this->ccm_registry ();

    if (registry != 0)
    {
      result = registry->register_component (creg.name.in (),
                                             creg.agent.in ());

    }

    // Check the <result> of the registration. If the result is zero,
    // then we know the registration has failed.
    if (result == 0)
    {
      throw Registration_Failed ();
    }

    return result;
  }

  //
  // unregister_component
  //
  void Testing_Service_exec_i::
    unregister_component (const ::CUTS::Component_Registration & creg
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException))
  {
    CCM_Component_Registry * registry = this->ccm_registry ();

    if (registry != 0)
      registry->reset_registration (creg.name.in ());
  }

  //
  // registry
  //
  CCM_Component_Registry * Testing_Service_exec_i::ccm_registry (void) const
  {
    return ACE_dynamic_cast (CCM_Component_Registry *,
                             this->registry_.get ());
  }
}
