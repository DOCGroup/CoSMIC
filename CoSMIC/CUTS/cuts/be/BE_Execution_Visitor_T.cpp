// $Id$

#include "UDM_Utility_T.h"
#include "BE_algorithm.h"
#include "modelgen.h"

// BOOST headers
#include "boost/bind.hpp"

// UDM headers
#include "Uml.h"

// STL headers
#include <algorithm>
#include <sstream>

//
// CUTS_BE_Execution_Visitor_T
//
template <typename BE_STRATEGY>
CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
CUTS_BE_Execution_Visitor_T (void)
: ignore_effects_ (false),
  depth_ (0)
{

}

//
// ~CUTS_BE_Execution_Visitor_T
//
template <typename BE_STRATEGY>
CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
~CUTS_BE_Execution_Visitor_T (void)
{

}

//
// generate
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
generate (const PICML::SingleInputBase & base)
{
  PICML::Input input = base.dstInput ();

  if (input != Udm::null)
  {
    CUTS_BE::visit <BE_STRATEGY> (input,
      boost::bind (&PICML::Input::Accept, _1, boost::ref (*this)));
  }
}


//
// generate
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
generate (const PICML::MultiInputBase & base)
{
  typedef std::set <PICML::MultiInput> MultiInput_Set;
  MultiInput_Set inputs = base.dstMultiInput ();

  if (!inputs.empty ())
  {
    CUTS_BE::visit <BE_STRATEGY> (inputs,
      boost::bind (&MultiInput_Set::value_type::Accept,
      _1, boost::ref (*this)));
  }
}

//
// Visit_Input
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_Input (const PICML::Input & input)
{
  PICML::InputAction action =
    PICML::InputAction::Cast (input.dstInput_end ());

  CUTS_BE::visit <BE_STRATEGY> (action,
    boost::bind (&PICML::InputAction::Accept, _1, boost::ref (*this)));
}


//
// Visit_MultiInput
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_MultiInput (const PICML::MultiInput & input)
{
  PICML::InputAction action =
    PICML::InputAction::Cast (input.dstMultiInput_end ());

  CUTS_BE::visit <BE_STRATEGY> (action,
    boost::bind (&PICML::InputAction::Accept, _1, boost::ref (*this)));
}

//
// Visit_InputAction
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_InputAction (const PICML::InputAction & action)
{
  // Add the <action> to the top of the stack.
  this->action_stack_.push (action);

  // Visit the effect.
  PICML::InputEffect input_effect = action.dstInputEffect ();

  if (input_effect != Udm::null)
  {
    CUTS_BE::visit <BE_STRATEGY> (input_effect,
      boost::bind (&PICML::InputEffect::Accept, _1, boost::ref (*this)));
  }

  // Remove the <action> from the stack since we have
  // completed its behavior.
  this->action_stack_.pop ();
}

//
// Visit_InputEffect
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_InputEffect (const PICML::InputEffect & effect)
{
  // Write the postcondition for this <effect>.
  std::string postcondition = effect.Postcondition ();

  if (!postcondition.empty ())
    CUTS_BE_Postcondition_T <BE_STRATEGY>::generate (postcondition);

  // Visit the next state in the chain.
  this->Visit_StateBase (effect.dstInputEffect_end ());
}

//
// Visit_Effect
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_Effect (const PICML::Effect & effect)
{
  // Write the postcondition for this <effect>.
  std::string postcondition = effect.Postcondition ();

  if (!postcondition.empty ())
    CUTS_BE_Postcondition_T <BE_STRATEGY>::generate (postcondition);

  // Visit the next state in the chain.
  this->Visit_StateBase (effect.dstEffect_end ());
}

//
// Visit_StateBase
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_StateBase (const PICML::StateBase & base)
{
  if (base.type () == PICML::State::meta)
  {
    PICML::State state = PICML::State::Cast (base);

    CUTS_BE::visit <BE_STRATEGY> (state,
      boost::bind (&PICML::State::Accept, _1, boost::ref (*this)));
  }
  else
  {
    PICML::BranchState branch = PICML::BranchState::Cast (base);

    CUTS_BE::visit <BE_STRATEGY> (branch,
      boost::bind (&PICML::BranchState::Accept, _1, boost::ref (*this)));
  }
}

//
// Visit_State
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_State (const PICML::State & state)
{
  // Generate information about the state.
  CUTS_BE_State_T <BE_STRATEGY>::generate (state);

  // Check to see if this state has any finish connections. If it
  // does, then we need to see if any of the finish connections is
  // for the current input action.
  typedef std::set <PICML::Finish> Finish_Set;
  Finish_Set finish_set = state.dstFinish ();

  PICML::Finish finish;

  if (Udm::contains (boost::bind (std::equal_to <PICML::InputAction> (),
      this->action_stack_.top (),
      boost::bind (&PICML::Finish::dstFinish_end,
                    _1))) (finish_set, finish))
  {
    return;
  }

  // Visit the transition that connected to this state.
  PICML::Transition transition = state.dstTransition ();

  if (transition != Udm::null)
  {
    CUTS_BE::visit <BE_STRATEGY> (transition,
      boost::bind (&PICML::Transition::Accept, _1, boost::ref (*this)));
  }
  else
  {
    // Ok, so we are at a terminal transition.
    PICML::TerminalTransition term = state.dstTerminalTransition ();

    CUTS_BE::visit <BE_STRATEGY> (term,
      boost::bind (&PICML::TerminalTransition::Accept, _1, boost::ref (*this)));
  }
}

//
// Visit_BranchState
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_BranchState (const PICML::BranchState & state)
{
  typedef std::set <PICML::BranchTransition> Transition_Set;
  Transition_Set transitions = state.dstBranchTransition ();

  // Signal the backend we are starting a branch state.
  CUTS_BE_Branches_Begin_T <BE_STRATEGY>::generate (transitions.size ());

  CUTS_BE::visit <BE_STRATEGY> (transitions,
    boost::bind (&PICML::BranchTransition::Accept, _1, boost::ref (*this)));

  // Signal the backend we are starting a branch state.
  CUTS_BE_Branches_End_T <BE_STRATEGY>::generate ();

  // Since we have finished the branching, we can continue generating
  // the remainder of the behavior that occurs after the branching.
  if (!this->terminal_state_.empty ())
  {
    PICML::Terminal terminal = this->terminal_state_.top ();
    this->terminal_state_.pop ();

    terminal.Accept (*this);
  }
}

//
// Visit_TerminalTransition
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_TerminalTransition (const PICML::TerminalTransition & transition)
{
  PICML::Terminal terminal = transition.dstTerminalTransition_end ();

  if (this->terminal_state_.empty () ||
      this->terminal_state_.top () != terminal)
  {
    this->terminal_state_.push (terminal);
  }
}

//
// Visit_Terminal
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_Terminal (const PICML::Terminal & terminal)
{
  PICML::TerminalEffect effect = terminal.dstTerminalEffect ();
  effect.Accept (*this);
}

//
// Visit_TerminalEffect
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_TerminalEffect (const PICML::TerminalEffect & effect)
{
  PICML::StateBase state = effect.dstTerminalEffect_end ();
  this->Visit_StateBase (state);
}

//
// Visit_Transition
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_Transition (const PICML::Transition & transition)
{
  PICML::ActionBase action = transition.dstTransition_end ();
  this->Visit_ActionBase (action);
}

//
// Visit_BranchTransition
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_BranchTransition (const PICML::BranchTransition & transition)
{
  std::string condition = transition.Condition ();

  if (!condition.empty ())
  {
    // We first need to write the condition for the branch before
    // we can start writing the actual branch statements.
    CUTS_BE_Branch_Condition_Begin_T <BE_STRATEGY>::generate ();

    if (CUTS_BE_Parse_Precondition_T <BE_STRATEGY>::result_type)
    {
      boost::spirit::parse (condition.c_str (),
                            this->condition_parser_,
                            boost::spirit::space_p);
    }
    else
    {
      CUTS_BE_Precondition_T <BE_STRATEGY>::generate (condition);
    }

    CUTS_BE_Branch_Condition_End_T <BE_STRATEGY>::generate ();
  }

  // We are now ready to write the branch statements.
  CUTS_BE_Branch_Begin_T <BE_STRATEGY>::generate ();

  PICML::ActionBase action = transition.dstBranchTransition_end ();
  this->Visit_ActionBase (action);

  CUTS_BE_Branch_End_T <BE_STRATEGY>::generate ();
}

//
// Visit_ActionBase
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_ActionBase (const PICML::ActionBase & action_base)
{
  Uml::Class type = action_base.type ();

  // We are placing the order of the action types in fast path
  // order. We know there will be far more <Action> elements
  // than any type.
  if (type == PICML::Action::meta)
  {
    PICML::Action::Cast (action_base).Accept (*this);
  }
  else if (type == PICML::OutputAction::meta)
  {
    PICML::OutputAction::Cast (action_base).Accept (*this);
  }
  else if (type == PICML::CompositeAction::meta)
  {
    PICML::CompositeAction::Cast (action_base).Accept (*this);
  }

  // Continue down the chain.
  PICML::Effect effect = action_base.dstEffect ();
  effect.Accept (*this);
}

//
// Visit_Property
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_Property (const PICML::Property & property)
{
  CUTS_BE_Action_Property_T <BE_STRATEGY>::generate (property);
}

//
// Visit_Action
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_Action (const PICML::Action & action)
{
  // Get action type and it's worker parent. This will help all
  // the generators since they will not have to do this themselves.
  PICML::Action action_type = action;

  while (PICML::Action (action_type.Archetype ()) != Udm::null)
    action_type = action_type.Archetype ();

  // Let's tell the <traits_> to begin generating an action.
  PICML::Worker worker = action_type.Worker_parent ();
  CUTS_BE_WorkerAction_Begin_T <BE_STRATEGY>::generate (worker, action);

  // Generate the parameters for the action.
  typedef std::set <PICML::Property,
                    Sort_By_Position <PICML::Property> > Property_Set;

  Property_Set properties =
    action.Property_kind_children_sorted (Sort_By_Position <PICML::Property> ());

  if (!properties.empty ())
  {
    CUTS_BE_Action_Properties_Begin_T <BE_STRATEGY>::
      generate (properties.size ());

    CUTS_BE::visit <BE_STRATEGY> (properties,
      boost::bind (&Property_Set::value_type::Accept,
      _1, boost::ref (*this)));

    CUTS_BE_Action_Properties_End_T <BE_STRATEGY>::generate ();
  }

  // Let's tell the <traits_> to end generating an action.
  CUTS_BE_Action_End_T <BE_STRATEGY>::generate ();
}

//
// Visit_OutputAction
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_OutputAction (const PICML::OutputAction & action)
{
  CUTS_BE_OutputAction_Begin_T <BE_STRATEGY>::generate (action);

  typedef std::vector <PICML::Property> Property_Set;
  Property_Set properties = action.Property_kind_children ();

  CUTS_BE::visit <BE_STRATEGY> (properties,
    boost::bind (&CUTS_BE_Execution_Visitor_T::Visit_OutputAction_Property,
    boost::ref (*this), _1));

  CUTS_BE_OutputAction_End_T <BE_STRATEGY>::generate (action);
}

//
// Visit_CompositeAction
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_CompositeAction (const PICML::CompositeAction & action)
{
  typedef std::vector <PICML::InputAction> InputAction_Set;
  InputAction_Set actions = action.InputAction_children ();

  if (!actions.empty ())
  {
    // Composite actions are only allowed to have a single input
    // action. Therefore, we only visit the first action in the set.
    CUTS_BE::visit <BE_STRATEGY> (PICML::InputAction::Cast (actions.front ()),
      boost::bind (&PICML::InputAction::Accept, _1, boost::ref (*this)));
  }
}

//
// Visit_OutputAction_Property
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_OutputAction_Property (const PICML::Property & property)
{
  PICML::OutputAction parent =
    PICML::OutputAction::Cast (property.parent ());

  CUTS_BE_OutputAction_Property_T <BE_STRATEGY>::generate (parent, property);
}
