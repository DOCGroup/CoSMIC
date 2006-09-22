// $Id$

#include "BE_Execution_Visitor.h"
#include "BE_File_Generator.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <algorithm>
#include <sstream>

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
// Visit_InputAction
//
void CUTS_BE_Execution_Visitor::
Visit_InputAction (const PICML::InputAction & action)
{
  // Visit all the properties for this input action.
  typedef std::vector <PICML::Property> Property_Set;
  Property_Set props = action.Property_children ();

  std::for_each (props.begin (),
                 props.end (),
                 boost::bind (&Property_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit the effect.
  PICML::Effect effect = action.dstInputEffect ();

  if (effect != Udm::null)
    effect.Accept (*this);
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
  PICML::State state = effect.dstInputEffect_end ();
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
    Effect_Set effects = state.srcInputEffect ();

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
  PICML::Finish finish_conn = state.dstFinish ();

  if (finish_conn != Udm::null)
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
  PICML::Action action =
    PICML::Action::Cast (transition.dstInternalPrecondition_end ());

  std::string _typename = action.type ().name ();

  // We only continue at this point if the action is an instance
  // of a predefined action, or it has more than 1 repetition
  // specified.
  if (action.Repetitions () > 0)
  {
    if (_typename == (std::string)PICML::Action::meta.name ())
    {
      PICML::Action::Cast (action).Accept (*this);
    }
    else if (_typename == (std::string) PICML::CompositeAction::meta.name ())
    {
      PICML::CompositeAction::Cast (action).Accept (*this);
    }
    else if (_typename == (std::string) PICML::OutputAction::meta.name ())
    {
      PICML::OutputAction::Cast (action).Accept (*this);
    }
  }

  // Continue down the chain.
  PICML::Effect effect = action.dstInputEffect ();
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
  PICML::InputAction ia = ca.InputAction_child ();

  if (ia != Udm::null)
    ia.Accept (*this);
}
