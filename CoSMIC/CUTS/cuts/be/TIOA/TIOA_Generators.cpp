// $Id$

#include "TIOA_Generators.h"
#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_Scope_Manager.h"
#include "cuts/be/BE_Preprocessor.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <sstream>

template <typename T>
struct Sorted_By_Name
{
  bool operator () (const T & lhs, const T & rhs)
  {
    std::string name = lhs.name ();
    return name.compare (rhs.name ()) > 0;
  }
};

//
// TIAO_State_ID
//
static std::string TIOA_State_ID (long id)
{
  std::ostringstream ostr;
  ostr << "s_" << id;

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
  env_done_ (false),
  state_count_ (0)
{

}

//
// reset
//
void CUTS_BE_Tioa::reset (void)
{
  this->last_state_id_ = 0;
  this->env_done_ = false;
  this->state_count_ = 0;

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
// CUTS_BE_Prologue_T
//
bool CUTS_BE_Prologue_T <CUTS_BE_Tioa>::
generate (const PICML::ComponentImplementationContainer & container)
{
  std::string name = container.name ();

  CUTS_BE_TIOA ()->outfile_
    << "%% -*- TIOA -*-" << std::endl
    << "%%" << std::endl
    << "%% @file " << name << ".tioa" << std::endl
    << "%%" << std::endl
    << "%% This file was generated by:" << std::endl
    << "%% $Id$" << std::endl
    << "%%" << std::endl
    << "%% Timed I/O Automata (TIOA) file for the " << name << " component. The" << std::endl
    << "%% component is designed to work within the CUTS' TIOA simulation" << std::endl
    << "%% framework. It is STRONGLY advised that you do not make in" << std::endl
    << "%% modifications to this file. If you do make modifications to" << std::endl
    << "%% this file, then you may obtain unknown results." << std::endl
    << "%%" << std::endl
    << std::endl;

  return true;
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
    << "  types Location : Enumeration [nil";

  // Write the state enumeration vocabulary.
  typedef std::vector <PICML::State> State_Set;
  State_Set states = component.State_kind_children ();

  std::for_each (states.begin (),
                 states.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_vocabulary_State, _1));

  // Write the parameters for all the event sinks.
  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set inputs = component.InEventPort_kind_children ();


  CUTS_BE_TIOA ()->outfile_
    << "]" << std::endl
    << "  types Thread_State : Enumeration[nil, blocked, ready, running, complete]" << std::endl;

  if (!inputs.empty ())
  {
    CUTS_BE_TIOA ()->outfile_
      << "  types Port_ID : Enumeration[unknown";

    // Write the parameters for all the event sinks.
    std::for_each (inputs.begin (),
                   inputs.end (),
                   boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                                write_portid_InEventPort, _1));

    CUTS_BE_TIOA ()->outfile_ << "]" << std::endl;
  }

  CUTS_BE_TIOA ()->outfile_
    << "end" << std::endl
    << std::endl
    << "automaton " << name << " (myid : Int, host : Int";

  // Write the parameters for all the event sinks.
  std::for_each (inputs.begin (),
                 inputs.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_param_InEventPort, _1));

  // Write the parameters for all the event sources.
  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set outputs = component.OutEventPort_kind_children ();

  std::for_each (outputs.begin (),
                 outputs.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_param_OutEventPort, _1));

  CUTS_BE_TIOA ()->outfile_
    << ")" << std::endl
    << "  imports " << name << "_vocab" << std::endl
    << std::endl
    << "  signature" << std::endl
    << "    %% input/output connections between components" << std::endl
    << "    input  recv_event (chid : Int)" << std::endl
    << "    output send_event (chid : Int)" << std::endl
    << std::endl
    << "    %% system calls for requesting threads to process events" << std::endl
    << "    input  thr_assign (cid : Int, chid : Int)" << std::endl
    << "    output thr_request (host : Int, cid : Int, chid : Int)" << std::endl
    << "    output thr_release (host : Int)" << std::endl
    << "    " << std::endl;

  // Write the signature for all the internal actions
  typedef std::vector <PICML::Action> Action_Set;
  Action_Set actions = component.Action_kind_children ();

  std::for_each (actions.begin (),
                 actions.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_signature_Action, _1));

  // Write the signature for event handlers.
  std::for_each (inputs.begin (),
                 inputs.end (),
                 boost::bind (&CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
                              write_signature_InEventPort, _1));

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
    << "      evolve d (time) = 1;" << std::endl
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
  CUTS_BE_TIOA ()->outfile_ << ", ";

  if (++ CUTS_BE_TIOA ()->state_count_ % 5 == 0)
  {
    CUTS_BE_TIOA ()->outfile_
      << std::endl
      << "                                ";
  }

  CUTS_BE_TIOA ()->outfile_ << TIOA_State_ID (state.uniqueId ());
}

//
// CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::write_portid_InEventPort
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_portid_InEventPort (const PICML::InEventPort & input)
{
  CUTS_BE_TIOA ()->outfile_ << ", port_" << input.name ();
}

//
// CUTS_BE_Component_Impl_Begin_T::write_param_InEventPort
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_param_InEventPort (const PICML::InEventPort & input)
{
  CUTS_BE_TIOA ()->outfile_
    << ", chid_" << input.name () << " : Int";
}

//
// CUTS_BE_Component_Impl_Begin_T::write_param_InEventPort
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_param_OutEventPort (const PICML::OutEventPort & output)
{
  CUTS_BE_TIOA ()->outfile_
    << ", chid_" << output.name () << " : Int";
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
// CUTS_BE_Component_Impl_Begin_T::write_signature_InEventPort
//
void CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>::
write_signature_InEventPort (const PICML::InEventPort & input)
{
  std::string name = input.name ();

  CUTS_BE_TIOA ()->outfile_
    << "    internal handle_" << name << std::endl;

  CUTS_BE_TIOA ()->input_events_.insert (name);
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
    << "    input env_" << action.name () << std::endl;
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
    << "    mode : Location := nil;" << std::endl
    << "    time : Real;" << std::endl
    << "    thr_state : Array[Port_ID, Thread_State];" << std::endl
    << "    queue_size : Array[Port_ID, Int];" << std::endl;

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
    << "  transitions" << std::endl
    << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
    << "    % system calls" << std::endl
    << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;

  // We need to create all the transitions for the system calls,
  // which is based on the input ports for the component.

  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set inputs = component.InEventPort_kind_children ();

  std::for_each (inputs.begin (),
                 inputs.end (),
                 boost::bind (&CUTS_BE_Variables_End_T <CUTS_BE_Tioa>::
                              write_system_calls, _1));

  return true;
}

//
// CUTS_BE_Variables_End_T <CUTS_BE_Tioa>::write_system_calls
//
void CUTS_BE_Variables_End_T <CUTS_BE_Tioa>::
write_system_calls (const PICML::InEventPort & input)
{
  std::string name = input.name ();

  CUTS_BE_TIOA ()->outfile_
    << std::endl
    << "    %% event : " << name << std::endl
    << "    output thr_release (hid)" << std::endl
    << "      pre hid = host /\\ thr_state[port_" << name << "] = complete;" << std::endl
    << "      eff thr_state[port_" << name << "] := nil;" << std::endl
    << std::endl
    << "    output thr_request (hid, cid, chid)" << std::endl
    << "      pre hid = host /\\ cid = myid /\\ chid = chid_" << name
    << " /\\ queue_size[port_" << name << "] > 0 /\\ mode = nil;" << std::endl
    << std::endl
    << "    input thr_assign (cid, chid)" << std::endl
    << "      eff if cid = myid /\\ chid = chid_" << name << std::endl
    << "          then thr_state[port_" << name << "] := ready; fi;" << std::endl;
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
    << "mode := " << TIOA_State_ID (CUTS_BE_TIOA ()->last_state_id_)
    << ";" << std::endl
    << std::endl
    << "    internal " << TIOA_Signature (action) << std::endl
    << "      pre mode = "
    << TIOA_State_ID (CUTS_BE_TIOA ()->last_state_id_) << ";" << std::endl
    << "      eff time := time + " << action.Duration () << ";" << std::endl
    << "          ";
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
    << "    input recv_event (chid)" << std::endl
    // 'where' clause goes here...
    << "      eff if chid = chid_" << name << std::endl
    << "          then queue_size[port_" << name
    << "] := succ (queue_size[port_" << name << "]); fi;" << std::endl
    << std::endl
    << "    internal handle_" << name << std::endl
    << "      pre thr_state[port_" << name
    << "] = ready /\\ mode = nil /\\ queue_size[port_"
    << name << "] > 0;" << std::endl
    << "      eff queue_size[port_" << name
    << "] := pred (queue_size[port_" << name << "]);" << std::endl
    << "          ";

  return true;
};

//
// CUTS_BE_InEventPort_End_T
//
bool CUTS_BE_InEventPort_End_T <CUTS_BE_Tioa>::
generate (const PICML::InEventPort & sink)
{

  CUTS_BE_TIOA ()->outfile_ << "mode := nil;" << std::endl;
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
    << "mode := " << last_state << ";" << std::endl
    << std::endl
    << "    output send_event (chid)" << std::endl
    << "      pre mode = " << last_state << " /\\ chid = chid_"
    << action.name () << ";" << std::endl
    << "      eff ";

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
    << "    input env_" << name << std::endl;

  if (!CUTS_BE_TIOA ()->env_done_)
    CUTS_BE_TIOA ()->outfile_ << "      eff ";

  return true;
}

//
// CUTS_BE_Environment_Method_End_T
//
bool CUTS_BE_Environment_Method_End_T <CUTS_BE_Tioa>::
generate (const PICML::InputAction & action)
{
  CUTS_BE_TIOA ()->outfile_ << "mode := nil;" << std::endl;
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
      << "      eff ";
  }

  return true;
}

//
// CUTS_BE_PeriodicEvent_End_T
//
bool CUTS_BE_PeriodicEvent_End_T <CUTS_BE_Tioa>::
generate (const PICML::PeriodicEvent & periodic)
{
  CUTS_BE_TIOA ()->outfile_ << "mode := nil;" << std::endl;
  return true;
}
