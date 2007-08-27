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

  // Visit all the properties for this input action.
  typedef std::vector <PICML::Property> Property_Set;
  Property_Set props = action.Property_children ();

  CUTS_BE::visit <BE_STRATEGY> (props,
    boost::bind (&Property_Set::value_type::Accept,
    _1, boost::ref (*this)));

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
  if (this->ignore_effects_)
  {
    this->ignore_effects_ = false;
  }
  else
  {
    if (!this->holding_state_.empty () &&
        this->holding_state_.top () == state)
    {
      // We have reached the end of this workflow.
      return;
    }
    else
    {
      // Get all the effects that are connected to this state. We know that
      // if we have more than 1 effect, then we are looking at state where
      // there either some, or all the branches come together (or there is
      // sharing of workload.

      typedef std::set <PICML::Effect> Effect_Set;
      Effect_Set effects = state.srcEffect ();

      if (effects.size () > 1)
      {
        if (!this->branches_.empty ())
        {
          // Ok, we have more than one effect entering this state and
          // we have some branching in effect. This mean this is a joining
          // state for one or more branches.
          size_t remaining = this->branches_.top () - effects.size () + 1;
          this->branches_.top () = remaining;

          if (remaining == 1)
          {
            // We reached end of the line for this branch state.
            this->holding_state_.push (state);
            return;
          }
        }
      }
    }
  }

  // Check for a finishing transition from this state.
  typedef std::set <PICML::Finish> Finish_Set;
  Finish_Set finish_set = state.dstFinish ();

  // Check to see if this state has any finish connections. If it
  // does, then we need to see if any of the finish connections is
  // for the current input action.
  PICML::Finish finish;

  if (Udm::contains (boost::bind (std::equal_to <PICML::InputAction> (),
      this->action_stack_.top (),
      boost::bind (&PICML::Finish::dstFinish_end,
                    _1))) (finish_set, finish))
  {
    return;
  }

  // Visit the transition that connected to this state.
  PICML::Transition transition = state.dstInternalPrecondition ();

  CUTS_BE::visit <BE_STRATEGY> (transition,
    boost::bind (&PICML::Transition::Accept, _1, boost::ref (*this)));
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

  // Save the number of branches we are operating on.
  size_t transition_size = transitions.size ();
  this->branches_.push (transition_size);

  // Signal the backend we are starting a branch state.
  CUTS_BE_Branches_Begin_T <BE_STRATEGY>::generate (transition_size);

  CUTS_BE::visit <BE_STRATEGY> (transitions,
    boost::bind (&PICML::BranchTransition::Accept, _1, boost::ref (*this)));

  // Signal the backend we are starting a branch state.
  CUTS_BE_Branches_End_T <BE_STRATEGY>::generate ();
  this->branches_.pop ();

  // Since we have finished the branching, we can continue generating
  // the remainder of the behavior that occurs after the branching.
  PICML::State jmpstate = this->holding_state_.top ();
  this->holding_state_.pop ();

  this->ignore_effects_ = true;
  jmpstate.Accept (*this);
}

//
// Visit_Transition
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_Transition (const PICML::Transition & transition)
{
  std::string precondition = transition.Precondition ();

  if (!precondition.empty ())
    CUTS_BE_Precondition_T <BE_STRATEGY>::generate (precondition);

  // Get the action connected to the end of the transaction.
  PICML::ActionBase action_base = transition.dstInternalPrecondition_end ();
  this->Visit_ActionBase (action_base);
}

//
// Visit_Transition
//
template <typename BE_STRATEGY>
void CUTS_BE_Execution_Visitor_T <BE_STRATEGY>::
Visit_BranchTransition (const PICML::BranchTransition & transition)
{
  // Signal the backend we are starting a branch.
  CUTS_BE_Branch_Begin_T <BE_STRATEGY>::generate (transition.Precondition ());

  PICML::ActionBase action_base = transition.dstBranchTransition_end ();
  this->Visit_ActionBase (action_base);

  // Signal the backend we are finishing a branch state.
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
