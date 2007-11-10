// $Id$

#include "Natural_Lang_Generators.h"
#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_Scope_Manager.h"
#include "cuts/be/BE_Preprocessor.h"
#include "Uml.h"

//
// CUTS_BE_File_Open_T
//
bool CUTS_BE_File_Open_T <CUTS_BE_Natural_Lang>::
generate (const PICML::ComponentImplementationContainer & container,
          const PICML::MonolithicImplementation & impl)
{
  // Locate the preprocessing of the implementation. If this is a
  // proxy implementation, then we ignore it. It's going to cause
  // more problems than we would like.
  const CUTS_BE_Impl_Node * node = 0;
  CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), node);

  if (node != 0 && node->is_proxy_)
    return false;

  std::string filename =
    CUTS_BE_OPTIONS ()->output_directory_ + "/"
    + (std::string) container.name () + ".txt";

  if (!CUTS_BE_NATURAL_LANG ()->outfile_.good ())
    CUTS_BE_NATURAL_LANG ()->outfile_.clear ();

  CUTS_BE_NATURAL_LANG ()->outfile_.open (filename.c_str ());
  return CUTS_BE_NATURAL_LANG ()->outfile_.is_open ();
}

//
// CUTS_BE_File_Close_T
//
bool CUTS_BE_File_Close_T <CUTS_BE_Natural_Lang>::
generate (const PICML::ComponentImplementationContainer & container,
          const PICML::MonolithicImplementation & impl)
{
  if (CUTS_BE_NATURAL_LANG ()->outfile_.is_open ())
    CUTS_BE_NATURAL_LANG ()->outfile_.close ();

  return true;
}

//
// CUTS_BE_Component_Impl_Begin_T
//
bool CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Natural_Lang>::
generate (const PICML::MonolithicImplementation & monoimpl,
          const PICML::Component & type)
{
  CUTS_BE_NATURAL_LANG ()->outfile_
    << "implementation: " << monoimpl.name () << std::endl
    << "of type: "
    << CUTS_BE_SCOPE_MANAGER ()->generate_scope (type, "::")
    << type.name () << std::endl
    << "-------------------------------------------------------" << std::endl;

  return true;
}

//
// CUTS_BE_InEventPort_Begin_T
//
bool CUTS_BE_InEventPort_Begin_T <CUTS_BE_Natural_Lang>::
generate (const PICML::InEventPort & sink)
{
  PICML::Event event = sink.ref ();

  CUTS_BE_NATURAL_LANG ()->outfile_
    << "* upon receipt of '"
    << CUTS_BE_SCOPE_MANAGER ()->generate_scope (event, "::")
    << event.name () << "' event on port '" << sink.name ()
    << "'" << std::endl;

  return true;
}

//
// CUTS_BE_PeriodicEvent_Begin_T
//
bool CUTS_BE_PeriodicEvent_Begin_T <CUTS_BE_Natural_Lang>::
generate (const PICML::PeriodicEvent & periodic)
{
  CUTS_BE_NATURAL_LANG ()->outfile_
    << "* every " << periodic.Period ()
    << " msec with probability of " << periodic.Probability () << std::endl;

  return true;
}

//
// CUTS_BE_WorkerAction_Begin_T
//
bool CUTS_BE_WorkerAction_Begin_T <CUTS_BE_Natural_Lang>::
generate (const PICML::Worker & worker, const PICML::Action & action)
{
  PICML::Action action_type = PICML::Action::Cast (action.archetype ());

  // Write the statement about the action.
  CUTS_BE_NATURAL_LANG ()->outfile_
    << "  - execute '" << action_type.name ()
    << "' using '" << action.name () << "'" << std::endl;

  return true;
}

//
// CUTS_BE_OutputAction_Begin_T
//
bool CUTS_BE_OutputAction_Begin_T <CUTS_BE_Natural_Lang>::
generate (const PICML::OutputAction & action)
{
  CUTS_BE_NATURAL_LANG ()->outfile_
    << "  - output event on '" << action.name () << "' port" << std::endl;

  return true;
}

//
// CUTS_BE_Action_Properties_Begin_T
//
bool CUTS_BE_Action_Properties_Begin_T <CUTS_BE_Natural_Lang>::
generate (size_t count)
{
  if (count >  0)
    CUTS_BE_NATURAL_LANG ()->outfile_ << "    parameter(s):";

  return true;
};

//
// CUTS_BE_Action_Property_T
//
bool CUTS_BE_Action_Property_T <CUTS_BE_Natural_Lang>::
generate (const PICML::Property & property)
{
  CUTS_BE_NATURAL_LANG ()->outfile_
    << " " << property.name () << " = " << property.DataValue ()
    << ";";

  return true;
}

//
// CUTS_BE_Action_Properties_Begin_T
//
bool CUTS_BE_Action_Properties_End_T <CUTS_BE_Natural_Lang>::generate (void)
{
  CUTS_BE_NATURAL_LANG ()->outfile_ << std::endl;
  return true;
};

//
// CUTS_BE_Environment_Method_Begin_T
//
bool CUTS_BE_Environment_Method_Begin_T <CUTS_BE_Natural_Lang>::
generate (const PICML::InputAction & action)
{
  CUTS_BE_NATURAL_LANG ()->outfile_
    << "* during '" << action.name () << "' environment event" << std::endl;

  return true;
}

//
// CUTS_BE_Variables_Begin_T
//
bool CUTS_BE_Variables_Begin_T <CUTS_BE_Natural_Lang>::
generate (const PICML::Component & component)
{
  CUTS_BE_NATURAL_LANG ()->outfile_
    << "variables:" << std::endl;

  return true;
}

//
// CUTS_BE_Variable_T
//
bool CUTS_BE_Variable_T <CUTS_BE_Natural_Lang>::
generate (const PICML::Variable & variable)
{
  PICML::PredefinedType type = variable.ref ();

  CUTS_BE_NATURAL_LANG ()->outfile_
    << "  - " << variable.name () << " : "
    << type.type ().name () << std::endl;

  return true;
}

//
// CUTS_BE_Worker_Variable_T
//
bool CUTS_BE_Worker_Variable_T <CUTS_BE_Natural_Lang>::
generate (const PICML::WorkerType & type, const PICML::Worker & worker)
{
  CUTS_BE_NATURAL_LANG ()->outfile_
    << "  - " << type.name () << " : " << worker.name () << std::endl;

  return true;
}
