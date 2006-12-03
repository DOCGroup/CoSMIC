// $Id$

#include "BE_Execution_Visitor.h"
#include "BE_File_Generator.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <algorithm>
#include <sstream>

//=============================================================================
/**
 * @struct Is_Finish_Connection
 *
 * Functor for determining if a Finish connection belongs to
 * a particular input action.
 */
//=============================================================================

struct Is_Finish_Connection
{
  /**
   * Initializing constructor.
   *
   * @param[in]     src_input       The target input action.
   */
  inline
  Is_Finish_Connection (const PICML::InputAction & src_input)
    : src_input_ (src_input)
  {

  }

  /**
   * Functor method responsible for determining the owner
   * of the finish connection.
   *
   * @param[in]     finish          The next finish connection.
   */
  inline
  bool operator () (const PICML::Finish & finish)
  {
    PICML::InputAction ia =
      PICML::InputAction::Cast (finish.dstFinish_end ());

    return ia == this->src_input_;
  }

  // Source input action we are looking for.
  const PICML::InputAction & src_input_;
};

//=============================================================================
/**
 * @struct Sort_By_Position
 *
 * @brief Help functor to sort objects by their position. The object
 * sorted by this method are in left-to-right ordering. Their y-value
 * is currently ignored when sorting objects.
 */
//=============================================================================

template <typename T>
struct Sort_By_Position
{
  struct Position
  {
    /// X-value of the position.
    long x;

    /// Y-value of the position
    long y;

    /**
     * Extraction operator. This method takes a string and extracts
     * the coordinates from it. The format of the string should be
     * (x, y). If the source string does not have coordinates stored
     * in this format, it will cause unpredictable behavior.
     *
     * @param[in]     str     Source string with the x-,y-coordinates
     */
    void operator <<= (const std::string & str)
    {
      char tmp;

      std::istringstream istr (str);

      istr >> tmp;
      istr >> this->x;
      istr >> tmp;
      istr >> this->y;
    }
  };

  /**
   * Functor operation. This method will compare the determine
   * which object is the furthest most left object of the two.
   */
  bool operator () (const T & lhs, const T & rhs)
  {
    Position pos_lhs;
    pos_lhs <<= lhs.position ();

    Position pos_rhs;
    pos_rhs <<= rhs.position ();

    return pos_lhs.x < pos_rhs.x;
  }
};


//
// CUTS_BE_Execution_Visitor
//
CUTS_BE_Execution_Visitor::
CUTS_BE_Execution_Visitor (const CUTS_BE_File_Generator_Set & generators)
: generators_ (generators),
  ignore_effects_ (false),
  depth_ (0)
{

}

//
// ~CUTS_BE_Execution_Visitor
//
CUTS_BE_Execution_Visitor::
~CUTS_BE_Execution_Visitor (void)
{

}


//
// Visit_Input
//
void CUTS_BE_Execution_Visitor::
Visit_Input (const PICML::Input & input)
{
  PICML::InputAction action =
    PICML::InputAction::Cast (input.dstInput_end ());

  action.Accept (*this);
}

//
// Visit_MultiInput
//
void CUTS_BE_Execution_Visitor::
Visit_MultiInput (const PICML::MultiInput & input)
{
  PICML::InputAction action =
    PICML::InputAction::Cast (input.dstMultiInput_end ());

  action.Accept (*this);
}

//
// Visit_InputAction
//
void CUTS_BE_Execution_Visitor::
Visit_InputAction (const PICML::InputAction & action)
{
  // Add the <action> to the top of the stack.
  this->action_stack_.push (action);

  // Visit all the properties for this input action.
  typedef std::vector <PICML::Property> Property_Set;
  Property_Set props = action.Property_children ();

  std::for_each (props.begin (),
                 props.end (),
                 boost::bind (&Property_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit the effect.
  PICML::InputEffect input_effect = action.dstInputEffect ();

  if (input_effect != Udm::null)
    input_effect.Accept (*this);

  // Remove the <action> from the stack since we have
  // completed its behavior.
  this->action_stack_.pop ();
}

//
// Visit_InputEffect
//
void CUTS_BE_Execution_Visitor::
Visit_InputEffect (const PICML::InputEffect & effect)
{
  // Write the postcondition for this <effect>.
  std::string postcondition = effect.Postcondition ();

  if (!postcondition.empty ())
  {
    std::for_each (this->generators_.begin (),
                   this->generators_.end (),
                   boost::bind (&CUTS_BE_File_Generator::write_postcondition,
                                _1,
                                postcondition));
  }

  // Visit the next state in the chain.
  PICML::State state = effect.dstInputEffect_end ();
  state.Accept (*this);
}

//
// Visit_Effect
//
void CUTS_BE_Execution_Visitor::
Visit_Effect (const PICML::Effect & effect)
{
  // Write the postcondition for this <effect>.
  std::string postcondition = effect.Postcondition ();

  if (!postcondition.empty ())
  {
    std::for_each (this->generators_.begin (),
                   this->generators_.end (),
                   boost::bind (&CUTS_BE_File_Generator::write_postcondition,
                                _1,
                                postcondition));
  }

  // Visit the next state in the chain.
  PICML::State state = effect.dstEffect_end ();
  state.Accept (*this);
}

//
// Visit_State
//
void CUTS_BE_Execution_Visitor::
Visit_State (const PICML::State & state)
{
  if (!this->ignore_effects_)
  {
    // Determine if this state is a finishing state for conditional
    // flows. If the state has more than one source, then we can
    // assume that we are ending one or more conditional flows.
    typedef std::set <PICML::Effect> Effect_Set;
    Effect_Set effects = state.srcEffect ();

    if (effects.size () > 1)
    {
      if (this->holding_state_.empty ())
        this->holding_state_.push (state);
      else if (this->holding_state_.top () != state)
        this->holding_state_.push (state);

      return;
    }
  }
  else
    this->ignore_effects_ = false;

  // Check for a finishing transition from this state.
  typedef std::set <PICML::Finish> Finish_Set;
  Finish_Set finish_set = state.dstFinish ();

  // We need to store the current size of the <action_stack_>
  // just in case one of the finish connections in for this
  // particular behavior workflow.
  Finish_Set::iterator finish_iter =
    std::find_if (finish_set.begin (),
                  finish_set.end (),
                  Is_Finish_Connection (this->action_stack_.top ()));

  if (finish_iter != finish_set.end ())
    return;

  // Get all the transitions from this state. If there is more than
  // one transition, then we need to prepare generating flow control
  // in execution path.
  typedef std::set <PICML::Transition> Transition_Set;
  Transition_Set transitions = state.dstInternalPrecondition ();

  size_t transition_count = transitions.size ();

  if (transition_count > 1)
    ++ this->depth_;

  std::for_each (transitions.begin (),
                 transitions.end (),
                 boost::bind (&Transition_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Now that we have visited all the transitions from the
  // state, we can jump to the state were all the branching
  // transitions from this state merge.
  if (transition_count > 1)
  {
    if (this->depth_ -- == this->holding_state_.size ())
    {
      // Get the topmost holding state and jump to it. We need to make
      // sure we tell the holding state to ignore any effect connections
      // since it will cause it to return.
      PICML::State jmp_state = this->holding_state_.top ();

      this->holding_state_.pop ();
      this->ignore_effects_ = true;

      jmp_state.Accept (*this);
    }
  }
}

//
// Visit_Transition
//
void CUTS_BE_Execution_Visitor::
Visit_Transition (const PICML::Transition & transition)
{
  std::string precondition = transition.Precondition ();

  if (!precondition.empty ())
  {
    std::for_each (this->generators_.begin (),
                   this->generators_.end (),
                   boost::bind (&CUTS_BE_File_Generator::write_precondition,
                                _1,
                                precondition));
  }

  // Get the action connected to the end of the transaction.
  PICML::ActionBase action_base = transition.dstInternalPrecondition_end ();
  std::string _typename = action_base.type ().name ();

  // We are placing the order of the action types in fast path
  // order. We know there will be far more <Action> elements
  // than any type.
  if (_typename == (std::string)PICML::Action::meta.name ())
  {
    PICML::Action action = PICML::Action::Cast (action_base);
    long reps = static_cast <long> (action.Repetitions ());

    if (reps > 0)
      PICML::Action::Cast (action).Accept (*this);
  }
  else if (_typename == (std::string) PICML::OutputAction::meta.name ())
  {
    PICML::OutputAction::Cast (action_base).Accept (*this);
  }
  else if (_typename == (std::string) PICML::CompositeAction::meta.name ())
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
void CUTS_BE_Execution_Visitor::
Visit_Property (const PICML::Property & property)
{
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_action_property,
                              _1,
                              property));
}

//
// Visit_Action
//
void CUTS_BE_Execution_Visitor::
Visit_Action (const PICML::Action & action)
{
  // Get action type and it's worker parent. This will help all
  // the generators since they will not have to do this themselves.
  PICML::Action action_type = action;

  while (PICML::Action (action_type.Archetype ()) != Udm::null)
    action_type = action_type.Archetype ();

  PICML::Worker worker = action_type.Worker_parent ();

  // Let's tell the generator to begin generating an action.
  typedef
    void (CUTS_BE_File_Generator::*BE_METHOD)
    (const PICML::Worker &, const PICML::Action &);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_METHOD> (
                              &CUTS_BE_File_Generator::write_action_begin),
                              _1,
                              worker,
                              action));

  // Generate the parameters for the action.
  typedef std::set <PICML::Property,
                    Sort_By_Position <PICML::Property> > Property_Set;

  Property_Set properties =
    action.Property_kind_children_sorted (Sort_By_Position <PICML::Property> ());

  std::for_each (properties.begin (),
                 properties.end (),
                 boost::bind (&Property_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Let's tell the generator to end generating an action.
  typedef
    void (CUTS_BE_File_Generator::*BE_METHOD)
    (const PICML::Worker &, const PICML::Action &);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_action_end,
                              _1));
}

//
// Visit_OutputAction
//
void CUTS_BE_Execution_Visitor::
Visit_OutputAction (const PICML::OutputAction & action)
{
  typedef
    void (CUTS_BE_File_Generator::*BE_METHOD)
    (const PICML::OutputAction &);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (
                    static_cast <BE_METHOD> (
                    &CUTS_BE_File_Generator::write_action_begin),
                    _1,
                    action));


  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_action_end,
                              _1));
}

//
// Visit_CompositeAction
//
void CUTS_BE_Execution_Visitor::
Visit_CompositeAction (const PICML::CompositeAction & ca)
{
  typedef std::vector <PICML::InputAction> InputAction_Set;
  InputAction_Set ia_set = ca.InputAction_kind_children ();

  // There should only be one <InputAction> in a <CompositeAction>
  if (ia_set.size () == 1)
    ia_set.front ().Accept (*this);
}

//
// Visit_Finish
//
void CUTS_BE_Execution_Visitor::
Visit_Finish (const PICML::Finish & finish)
{
  PICML::InputActionBase iab = finish.dstFinish_end ();
  PICML::InputAction ia = PICML::InputAction::Cast (iab);

  if (!this->action_stack_.empty () &&
      ia != this->action_stack_.top ())
  {
    this->action_stack_.pop ();
  }
}
