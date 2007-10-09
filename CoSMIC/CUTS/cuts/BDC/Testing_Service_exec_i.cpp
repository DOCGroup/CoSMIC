// $Id$

#include "Testing_Service_exec_i.h"

#if !defined (__CUTS_INLINE__)
#include "Testing_Service_exec_i.inl"
#endif

#include "CCM_Component_Registry.h"
#include "cuts/Component_Type.h"
#include "cuts/CUTS_i.h"

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
  CORBA::Long Testing_Service_exec_i::
  register_component (const CUTS::Component_Registration & creg)
  {
    // Check for a NIL <agent> and print a warning message if there
    // is one. Usually this means there is something wrong w/ the
    // template code that activates the <agent>!!!
    if (::CORBA::is_nil (creg.agent.in ()))
    {
      ACE_ERROR ((LM_WARNING,
                  "[%M] -%T - component %s has <NIL> agent\n",
                  creg.name.in ()));
    }

    // Register the host information about the component. This will
    // return the host table entry for later usage.
    const CUTS_Host_Table_Entry * entry = 0;
    this->registry_.hosts ().bind (creg.host_info.ipaddr.in (),
                                   creg.host_info.hostname.in (),
                                   &entry);

    // Register the type information about the component. This will
    // return the type entry for later usage.
    CUTS_Component_Type * type_info = 0;
    this->register_component_type (creg.component_info, type_info);

    // Create a new registration node for the component.
    CCM_Component_Registry_Node * component = 0;
    ACE_NEW_THROW_EX (component,
                      CUTS::CCM_Component_Registry_Node (creg.agent.in ()),
                      CORBA::NO_MEMORY ());

    // Initialize the registration node.
    component->info_.inst_ = creg.name.in ();
    component->info_.type_ = type_info;
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
  unregister_component (const CUTS::Component_Registration & reg)
  {
    this->registry_.unregister_component (reg.name.in ());
  }

  //
  // register_component_type
  //
  int Testing_Service_exec_i::
  register_component_type (const CUTS::Component_Description & desc,
                           CUTS_Component_Type *& type)
  {
    ACE_CString type_name = desc.type.in ();

    // Check to see if we have already registered this type. If we
    // have then there is no need to create a new entry. That would
    // just be a waste of time.
    if (this->registry_.component_types ().find (type_name, type) == 0)
      return 0;

    ACE_NEW_THROW_EX (type,
                      CUTS_Component_Type,
                      CORBA::NO_MEMORY ());

    ACE_Auto_Ptr <CUTS_Component_Type> auto_clean (type);

    // There could be a chance that another component registered this type
    // before we had a chance to register it. So, we are going to try to
    // bind. If the type already exists, then we just let the auto_clean
    // handle releasing the allocated memory. Otherwise, we need to init
    // the new type.
    int retval  = this->registry_.component_types ().trybind (type_name, type);

    if (retval == 0)
    {
      // Release the auto_clean since map owns the memory.
      auto_clean.release ();

      // Initialize the type information for the component.
      type->name_ = type_name;

      // Save the names of the ports in the type information.
      desc.sinks >>= type->sinks_;
      desc.sources >>= type->sources_;
    }

    return retval != -1;
  }
}
