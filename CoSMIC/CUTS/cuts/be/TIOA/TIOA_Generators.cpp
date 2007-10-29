// $Id$

#include "TIOA_Generators.h"
#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_Scope_Manager.h"
#include "cuts/be/BE_Preprocessor.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <sstream>

//
// TIAO_State_ID
//
static std::string TIOA_State_ID (long id)
{
  std::ostringstream ostr;
  ostr << "st_" << id;

  return ostr.str ();
}

//
// TIOA_Signature
//
static std::string TIOA_Signature (const PICML::Action & action)
{
  const PICML::Action action_type =
    const_cast <PICML::Action &> (action).Archetype ();

  std::ostringstream ostr;
  ostr
    << "int_" << action.uniqueId () << "_"
    << action.name () << "_" << action_type.name ();

  return ostr.str ();
}

//
// CUTS_BE_Tioa
//
CUTS_BE_Tioa::CUTS_BE_Tioa (void)
: last_state_id_ (0),
  env_done_ (false)
{

}

//
// reset
//
void CUTS_BE_Tioa::reset (void)
{
  this->last_state_id_ = 0;
  this->env_done_ = false;

  this->input_events_.clear ();
}

//
// CUTS_BE_File_Open_T
//
bool CUTS_BE_File_Open_T <CUTS_BE_Tioa>::
generate (const PICML::ComponentImplementationContainer & container)
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
    + (std::string) container.name () + ".tioa";

  if (!CUTS_BE_TIOA ()->outfile_.good ())
    CUTS_BE_TIOA ()->outfile_.clear ();

  CUTS_BE_TIOA ()->outfile_.open (filename.c_str ());
  return CUTS_BE_TIOA ()->outfile_.is_open ();
}

//
// CUTS_BE_File_Close_T
//
bool CUTS_BE_File_Close_T <CUTS_BE_Tioa>::
generate (const PICML::ComponentImplementationContainer & container)
{
  if (CUTS_BE_TIOA ()->outfile_.is_open ())
    CUTS_BE_TIOA ()->outfile_.close ();

  return true;
}

//
// CUTS_BE_Component_Impl_Begin_T
//
bool CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
generate (const PICML::MonolithicImplementation & mono,
          const PICML::Component & component)
{
  std::string name = component.name ();

  CUTS_BE_TIOA ()->outfile_
    << "vocabulary " << name << "_vocab" << std::endl
    << "  types " << name << "_states : Enumeration [nil";

  // Write the state enumeration vocabulary.
  typedef std::vector <PICML::State> State_Set;
  State_Set states = component.State_kind_children ();

  std::for_each (states.begin (),
                 states.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_vocabulary_State, _1));

  CUTS_BE_TIOA ()->outfile_
    << "]" << std::endl
    << "end" << std::endl
    << std::endl
    << "automaton " << name << " (host: Int)" << std::endl
    << "  imports " << name << "_vocab" << std::endl
    << std::endl
    << "  signature" << std::endl;

  // Write the signature for all the input ports.
  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set inputs = component.InEventPort_kind_children ();

  std::for_each (inputs.begin (),
                 inputs.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                                write_signature_InEventPort, _1));

  // Write the signature for all the output ports.
  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set outputs = component.OutEventPort_kind_children ();

  std::for_each (outputs.begin (),
                 outputs.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                                write_signature_OutEventPort, _1));

  // Write the signature for all the internal actions
  typedef std::vector <PICML::Action> Action_Set;
  Action_Set actions = component.Action_kind_children ();

  std::for_each (actions.begin (),
                 actions.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_signature_Action, _1));

  // Write the signature for the periodic events.
  typedef std::vector <PICML::PeriodicEvent> Periodic_Set;
  Periodic_Set periodics = component.PeriodicEvent_kind_children ();

  std::for_each (periodics.begin (),
                 periodics.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_signature_PeriodicEvent, _1));

  // Write the signature for the environment inputs.
  PICML::Environment env = component.Environment_child ();

  if (env != Udm::null)
    CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::visit_Environment (env);

  return true;
}

//
// CUTS_BE_Component_Impl_End_T
//
bool CUTS_BE_Component_Impl_End_T <CUTS_BE_Tioa>::
generate (const PICML::MonolithicImplementation & mono,
          const PICML::Component & component)
{
  CUTS_BE_TIOA ()->outfile_
    << std::endl
    << "  trajectories" << std::endl
    << "    trajdef default" << std::endl
    << "      evolve d (clock) = 1;" << std::endl
    << std::endl;

  CUTS_BE_TIOA ()->reset ();
  return true;
}

//
// CUTS_BE_Component_Impl_Begin_T::write_vocabulary_State
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_vocabulary_State (const PICML::State & state)
{
  CUTS_BE_TIOA ()->outfile_ << ", " << TIOA_State_ID (state.uniqueId ());
}

//
// CUTS_BE_Component_Impl_Begin_T::write_signature_InEventPort
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_signature_InEventPort (const PICML::InEventPort & input)
{
  std::string input_name = input.name ();

  CUTS_BE_TIOA ()->outfile_
    << "    input " << input_name << std::endl
    << "    internal handle_" << input_name << std::endl;

  // Insert the name into the <input_events_>.
  CUTS_BE_TIOA ()->input_events_.insert (input_name);
}

//
// CUTS_BE_Component_Impl_Begin_T::write_signature_OutEventPort
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_signature_OutEventPort (const PICML::OutEventPort & output)
{
  CUTS_BE_TIOA ()->outfile_
    << "    output " << output.name () << std::endl;
}

//
// CUTS_BE_Component_Impl_Begin_T::write_signature_Action
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_signature_Action (const PICML::Action & action)
{
  CUTS_BE_TIOA ()->outfile_
    << "    internal " << TIOA_Signature (action) << std::endl;
}

//
// CUTS_BE_Component_Impl_Begin_T::write_signature_Periodic
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_signature_PeriodicEvent (const PICML::PeriodicEvent & periodic)
{
  PICML::Input input = periodic.dstInput ();

  if (input != Udm::null)
  {
    PICML::InputAction action = input.dstInput_end ();

    CUTS_BE_TIOA ()->outfile_
      << "    input periodic_" << action.name () << std::endl;
  }
}

//
// CUTS_BE_Component_Impl_Begin_T::visit_Environment
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
visit_Environment (const PICML::Environment & env)
{
  typedef std::set <PICML::MultiInput> MultiInput_Set;
  MultiInput_Set inputs = env.dstMultiInput ();

  std::for_each (inputs.begin (),
                 inputs.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              visit_MultiInput, _1));
}

//
// CUTS_BE_Component_Impl_Begin_T::visit_MultiInput
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
visit_MultiInput (const PICML::MultiInput & input)
{
  PICML::InputAction action =
    PICML::InputAction::Cast (input.dstMultiInput_end ());

  CUTS_BE_TIOA ()->outfile_
    << "    input " << action.name () << std::endl;
}

//
// CUTS_BE_Variables_Begin_T
//
bool CUTS_BE_Variables_Begin_T <CUTS_BE_Tioa>::
generate (const PICML::Component & component)
{
  CUTS_BE_TIOA ()->outfile_
    << std::endl
    << "  states" << std::endl
    << "    state : " << component.name () << "_states := nil;" << std::endl
    << "    clock : Int := 0;" << std::endl;

  // Write the queue states for each of the inputs.
  std::for_each (CUTS_BE_TIOA ()->input_events_.begin (),
                 CUTS_BE_TIOA ()->input_events_.end (),
                 boost::bind (&CUTS_BE_Variables_Begin_T <CUTS_BE_Tioa>::
                                write_state_InEventPort, _1));

  return true;
}

//
// CUTS_BE_Variables_End_T
//
bool CUTS_BE_Variables_End_T <CUTS_BE_Tioa>::
generate (const PICML::Component & component)
{
  CUTS_BE_TIOA ()->outfile_
    << std::endl
    << "  transitions";

  return true;
}

//
// write_state_InEventPort
//
void CUTS_BE_Variables_Begin_T <CUTS_BE_Tioa>::
write_state_InEventPort (const std::string & input)
{
  CUTS_BE_TIOA ()->outfile_
    << "    queue_" << input << " : Int := 0;" << std::endl;
}

//
// CUTS_BE_State_T
//
bool CUTS_BE_State_T <CUTS_BE_Tioa>::
generate (const PICML::State & state)
{
  CUTS_BE_TIOA ()->last_state_id_ = state.uniqueId ();
  return true;
}

//
// CUTS_BE_WorkerAction_Begin_T
//
bool CUTS_BE_WorkerAction_Begin_T <CUTS_BE_Tioa>::
generate (const PICML::Worker & worker, const PICML::Action & action)
{
  CUTS_BE_TIOA ()->outfile_
    << "        state := " << TIOA_State_ID (CUTS_BE_TIOA ()->last_state_id_)
    << ";" << std::endl
    << std::endl
    << "    internal " << TIOA_Signature (action) << std::endl
    << "      pre" << std::endl
    << "        state = "
    << TIOA_State_ID (CUTS_BE_TIOA ()->last_state_id_) << ";" << std::endl
    << "      eff" << std::endl
    << "        clock := clock + " << action.Duration () << ";" << std::endl;
  return true;
}

//
// CUTS_BE_Action_End_T
//
bool CUTS_BE_Action_End_T <CUTS_BE_Tioa>::generate (void)
{
  return true;
}

//
// CUTS_BE_InEventPort_Begin_T
//
bool CUTS_BE_InEventPort_Begin_T <CUTS_BE_Tioa>::
generate (const PICML::InEventPort & sink)
{
  std::string name = sink.name ();

  CUTS_BE_TIOA ()->outfile_
    << std::endl
    << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
    << "    % event input: " << name << std::endl
    << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
    << "    input " << name << std::endl
    // 'where' clause goes here...
    << "      eff" << std::endl
    << "        queue_" << name << " := queue_" << name << " + 1;" << std::endl
    << std::endl
    << "    internal handle_" << name << std::endl
    << "      pre" << std::endl
    << "        queue_" << name << " > 0;" << std::endl
    << "      eff" << std::endl
    << "        queue_" << name << " := queue_" << name << " - 1;" << std::endl;

  return true;
};

//
// CUTS_BE_InEventPort_End_T
//
bool CUTS_BE_InEventPort_End_T <CUTS_BE_Tioa>::
generate (const PICML::InEventPort & sink)
{

  CUTS_BE_TIOA ()->outfile_
    << "        state := nil;" << std::endl;

  return true;
}

//
// CUTS_BE_OutputAction_Begin_T
//
bool CUTS_BE_OutputAction_Begin_T <CUTS_BE_Tioa>::
generate (const PICML::OutputAction & action)
{
  std::string last_state = TIOA_State_ID (CUTS_BE_TIOA ()->last_state_id_);

  CUTS_BE_TIOA ()->outfile_
    << "        state := " << last_state << ";" << std::endl
    << std::endl
    << "    output " << action.name () << std::endl
    << "      pre" << std::endl
    << "        state = " << last_state << ";" << std::endl
    << "      eff" << std::endl;

  return true;
}

//
// CUTS_BE_Environment_End_T
//
bool CUTS_BE_Environment_End_T <CUTS_BE_Tioa>::
generate (const PICML::Component & component)
{
  CUTS_BE_TIOA ()->env_done_ = true;
  return true;
}

//
// CUTS_BE_Environment_Method_Begin_T
//
bool CUTS_BE_Environment_Method_Begin_T <CUTS_BE_Tioa>::
generate (const PICML::InputAction & action)
{
  std::string name = action.name ();

  CUTS_BE_TIOA ()->outfile_
    << std::endl
    << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
    << "    % environment input: " << name << std::endl
    << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
    << "    input " << name << std::endl;

  if (!CUTS_BE_TIOA ()->env_done_)
  {
    CUTS_BE_TIOA ()->outfile_
      // 'where' clause goes here...
      << "      eff" << std::endl;
  }

  return true;
}

//
// CUTS_BE_Environment_Method_End_T
//
bool CUTS_BE_Environment_Method_End_T <CUTS_BE_Tioa>::
generate (const PICML::InputAction & action)
{
  CUTS_BE_TIOA ()->outfile_
    << "        state := nil;" << std::endl;

  return true;
}

//
// CUTS_BE_PeriodicEvent_Begin_T
//
bool CUTS_BE_PeriodicEvent_Begin_T <CUTS_BE_Tioa>::
generate (const PICML::PeriodicEvent & periodic)
{
  PICML::Input input = periodic.dstInput ();

  if (input != Udm::null)
  {
    PICML::InputAction action = input.dstInput_end ();
    std::string name = action.name ();

    CUTS_BE_TIOA ()->outfile_
      << std::endl
      << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
      << "    % periodic input: " << name << std::endl
      << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
      << "    input periodic_" << name << std::endl
      << "      eff" << std::endl;
  }

  return true;
}

//
// CUTS_BE_PeriodicEvent_End_T
//
bool CUTS_BE_PeriodicEvent_End_T <CUTS_BE_Tioa>::
generate (const PICML::PeriodicEvent & periodic)
{
  CUTS_BE_TIOA ()->outfile_
    << "        state := nil;" << std::endl;

  return true;
}
