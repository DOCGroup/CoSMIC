// $Id$

#include "Natural_Lang_Generator.h"

#if !defined (__CUTS_INLINE__)
#include "Natural_Lang_Generator.inl"
#endif

#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_Scope_Manager.h"
#include "cuts/be/BE_Preprocessor.h"
#include "Uml.h"

namespace CUTS_BE
{

//
// open_file
//
bool Natural_Lang_Generator::
open_file (const PICML::ComponentImplementationContainer & container)
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

  if (!this->outfile_.good ())
    this->outfile_.clear ();

  this->outfile_.open (filename.c_str ());
  return this->outfile_.is_open ();
}

//
// close_file
//
void Natural_Lang_Generator::
close_file (const PICML::ComponentImplementationContainer & container)
{
  if (this->outfile_.is_open ())
    this->outfile_.close ();
}

//
// write_impl_begin
//
void Natural_Lang_Generator::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & type)
{
  this->outfile_
    << "implementation: " << monoimpl.name () << std::endl
    << "of type: "
    << CUTS_BE_SCOPE_MANAGER ()->generate_scope (type, "::")
    << type.name () << std::endl
    << "-------------------------------------------------------" << std::endl;
}

//
// write_InEventPort_begin
//
void Natural_Lang_Generator::
write_InEventPort_begin (const PICML::InEventPort & sink)
{
  PICML::Event event = sink.ref ();

  this->outfile_
    << "* upon receipt of '"
    << CUTS_BE_SCOPE_MANAGER ()->generate_scope (event, "::")
    << event.name () << "' event on port '" << sink.name ()
    << "'" << std::endl;
}

//
// write_PeriodicEvent_begin
//
void Natural_Lang_Generator::
write_PeriodicEvent_begin (const PICML::PeriodicEvent & event)
{
  this->outfile_
    << "* every " << event.Period ()
    << " msec with probability of " << event.Probability () << std::endl;
}

//
// write_WorkerAction_begin
//
void Natural_Lang_Generator::
write_WorkerAction_begin (const PICML::Worker & worker,
                          const PICML::Action & action)
{
  PICML::Action action_type = PICML::Action::Cast (action.archetype ());

  // Write the statement about the action.
  this->outfile_
    << "  - execute '" << action_type.name ()
    << "' using '" << action.name () << "'";

  // Determine if we need a 'parameter(s)' line.
  std::vector <PICML::Property> properties = action.Property_children ();

  if (!properties.empty ())
  {
    this->outfile_
      << std::endl
      << "    parameter(s):";
  }
}

//
// write_OutputAction_begin
//
void Natural_Lang_Generator::
write_OutputAction_begin (const PICML::OutputAction & action)
{
  this->outfile_
    << "  - output event on '" << action.name () << "' port";
}

//
// write_action_property
//
void Natural_Lang_Generator::
write_action_property (const PICML::Property & property)
{
  this->outfile_
    << " " << property.name () << " = " << property.DataValue ()
    << ";";
}

//
// write_environment_method_begin
//
void Natural_Lang_Generator::
write_environment_method_begin (const PICML::InputAction & action)
{
  this->outfile_
    << "* during '" << action.name () << "' environment event" << std::endl;
}

//
// write_variables_begin
//
void Natural_Lang_Generator::
write_variables_begin (const PICML::Component & component)
{
  this->outfile_ << "variables:" << std::endl;
}

//
// write_variable
//
void Natural_Lang_Generator::
write_variable (const PICML::Variable & variable)
{
  PICML::PredefinedType type = variable.ref ();

  this->outfile_
    << "  - " << variable.name () << " : " << type.type ().name () << std::endl;
}

//
// write_worker_variable
//
void Natural_Lang_Generator::
write_worker_variable (const PICML::WorkerType & type,
                       const PICML::Worker & worker)
{
  this->outfile_
    << "  - " << type.name () << " : " << worker.name () << std::endl;
}

}
