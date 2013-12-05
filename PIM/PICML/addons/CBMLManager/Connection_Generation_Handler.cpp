// $Id$

#include "StdAfx.h"
#include "Connection_Generation_Handler.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/Model.h"
#include "game/mga/utils/Point.h"

#define PREF_AUTOROUTER           "autorouterPref"
#define PREF_AUTOROUTER_ALL       "NEWSnews"

#define OFFSET_Y  0
#define OFFSET_X  50

namespace meta
{
  static const std::string State ("State");
  static const std::string BranchState ("BranchState");
  static const std::string DoWhileState ("DoWhileState");
  static const std::string WhileState ("WhileState");
  static const std::string ForState ("ForState");

  static const std::string Action ("Action");
  static const std::string RequestAction ("RequestAction");
  static const std::string OutputAction ("OutputAction");
  static const std::string QueryAction ("QueryAction");
  static const std::string CallAction ("CallAction");

  static const std::string InputAction ("InputAction");
  static const std::string MultiInputAction ("MultiInputAction");
}

//
// CBML_Connection_Generation_Handler
//
CBML_Connection_Generation_Handler::CBML_Connection_Generation_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{
  this->state_transition_map_.bind ("State", "Transition");
  this->state_transition_map_.bind ("ForState", "LoopTransition");
  this->state_transition_map_.bind ("WhileState", "LoopTransition");
  this->state_transition_map_.bind ("DoWhileState", "LoopTransition");
  this->state_transition_map_.bind ("BranchState", "BranchTransition");
}

//
// CBML_Connection_Generation_Handler
//
CBML_Connection_Generation_Handler::~CBML_Connection_Generation_Handler (void)
{

}

//
// handle_object_created
//
int CBML_Connection_Generation_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);

  // This event handler only works with non-instance elements.
  if (fco->is_instance ())
    return 0;

  const std::string metaname = obj->meta ()->name ();

  if (metaname == meta::Action ||
      metaname == meta::RequestAction ||
      metaname == meta::OutputAction ||
      metaname == meta::QueryAction ||
      metaname == meta::CallAction)
  {
    this->create_state_and_connect (fco, "Effect");
  }
  else if (metaname == meta::InputAction ||
           metaname == meta::MultiInputAction)
  {
    // We need to make sure there is not an active state selected
    // before continuing. This is because we are starting a new
    // workflow in the behavior.
    if (!this->active_state_.is_nil ())
      this->active_state_ = 0;

    this->create_state_and_connect (fco, "InputEffect");
  }
  else if (0 == this->state_transition_map_.find (metaname.c_str ()))
  {
    this->active_state_ = fco;
  }

  return 0;
}

//
// handle_object_destroyed
//
int CBML_Connection_Generation_Handler::
handle_object_destroyed (GAME::Mga::Object_in obj)
{
  if (this->active_state_ == obj)
    this->active_state_ = 0;

  return 0;
}

//
// handle_object_select
//
int CBML_Connection_Generation_Handler::
handle_object_select (GAME::Mga::Object_in obj)
{
  if (0 == this->state_transition_map_.find (obj->meta ()->name ().c_str ()))
    this->active_state_ = GAME::Mga::FCO::_narrow (obj);

  return 0;
}

//
// create_state_and_connect
//
void CBML_Connection_Generation_Handler::
create_state_and_connect (GAME::Mga::FCO_in action, const std::string & effect_type)
{
  // Update the connection routing information.
  GAME::Mga::Point position;
  action->registry_value (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);
  GAME::Mga::Model parent = action->parent_model ();

  if (!this->active_state_.is_nil ())
  {
    // Align newly created action with previous state.
    GAME::Mga::get_position ("Behavior", this->active_state_, position);
    position.shift (OFFSET_X, OFFSET_Y);
    GAME::Mga::set_position ("Behavior", position, action);

    // Create connection between active state and new action.
    std::string transition_metaname;
    GAME::Mga::Meta::FCO metafco = this->active_state_->meta ();

    int retval =
      this->state_transition_map_.find (metafco->name ().c_str (),
                                        transition_metaname);

    if (retval == 0)
    {
      GAME::Mga::Connection transition =
        GAME::Mga::Connection_Impl::_create (parent,
                                             transition_metaname,
                                             this->active_state_,
                                             action);
    }
  }

  // Create the new State element for the action.
  GAME::Mga::Atom state = GAME::Mga::Atom_Impl::_create (parent, "State");
  state->registry_value (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);

  // Create the effect connection from the action to the state.
  GAME::Mga::Connection effect =
    GAME::Mga::Connection_Impl::_create (parent,
                                         effect_type,
                                         action,
                                         state);

  // Use the action's position if there is no active state.
  if (this->active_state_.is_nil ())
    GAME::Mga::get_position ("Behavior", action, position);

  // Align the <state> to the right of the <action>.
  position.shift (OFFSET_X, -OFFSET_Y);
  GAME::Mga::set_position ("Behavior", position, state);
}
