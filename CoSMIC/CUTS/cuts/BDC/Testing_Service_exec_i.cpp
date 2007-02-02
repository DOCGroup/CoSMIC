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
  Testing_Service_exec_i::Testing_Service_exec_i (void)
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

    // Register the host information about the component. This will
    // return the host table entry for later usage.
    const CUTS_Host_Table_Entry * entry = 0;
    this->registry_.hosts ().bind (creg.ipaddr.in (),
                                   creg.hostname.in (),
                                   &entry);

    // Create a new registration node for the component.
    CCM_Component_Registry_Node * component = 0;
    ACE_NEW_THROW_EX (component,
                      CUTS::CCM_Component_Registry_Node (creg.agent.in ()),
                      ::CORBA::NO_MEMORY ());

    // Initialize the registration node.
    component->info_.inst_ = creg.name.in ();
    component->info_.type_ = creg.type.in ();
    component->info_.host_info_ = entry;

    // Place the node inside the <registry_>.
    if (this->registry_.register_component (component) != 0)
    {
      delete component;
      throw CUTS::Registration_Failed ();
    }

    return component->info_.uid_;
  }

  //
  // unregister_component
  //
  void Testing_Service_exec_i::
    unregister_component (const ::CUTS::Component_Registration & creg
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException))
  {
    try
      {
        this->registry_.unregister_component (creg.name.in ());
      }
    catch (const ::CORBA::Exception & ex)
      {

      }
    catch (...)
      {

      }
  }
}
