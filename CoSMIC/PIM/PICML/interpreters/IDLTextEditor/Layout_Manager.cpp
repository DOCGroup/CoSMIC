// $Id$

#include "StdAfx.h"
#include "Layout_Manager.h"
#include "game/utils/Point.h"
#include "game/FCO.h"
#include "game/MetaBase.h"

std::set <std::string> Layout_Manager::horizontal_models_;

std::set <std::string> Layout_Manager::vertical_models_;

//
// Layout_Manager
//
Layout_Manager::Layout_Manager (void)
: current_ (0)
{
  this->vertical_models_.insert ("Aggregate");
  this->vertical_models_.insert ("Enum");
  this->vertical_models_.insert ("SwithedAggregate");
  this->vertical_models_.insert ("Event");
  this->vertical_models_.insert ("ValueObject");

  this->horizontal_models_.insert ("OnewayOperation");
  this->horizontal_models_.insert ("TwowayOperation");
  this->horizontal_models_.insert ("FactoryOperation");
}

//
// Layout_Manager
//
Layout_Manager::~Layout_Manager (void)
{

}

void Layout_Manager::handle_open_model (GAME::Object_in)
{
  // Save the current state.
  this->stack_.push (this->current_);

  // Allocate a new object list.
  this->current_ = new object_list ();
}

//
// handle_close_model
//
void Layout_Manager::handle_close_model (GAME::Object_in obj)
{
  // Prepare the current state for deletion.
  std::auto_ptr <object_list> auto_clean (this->current_);
  std::string metaname = obj->meta ()->name ();

  if (this->horizontal_models_.find (metaname) != this->horizontal_models_.end ())
    this->arrange_objects (false);
  else if (this->vertical_models_.find (metaname) != this->vertical_models_.end ())
    this->arrange_objects (true);

  // Restore the previous state.
  if (!this->stack_.empty ())
  {
    this->current_ = this->stack_.top ();
    this->stack_.pop ();
  }
}

//
// handle_new_object
//
void Layout_Manager::handle_new_object (GAME::Object_in obj)
{
  // We need to perserve the order the objects were created
  // since some models require preservation of this property.
  if (this->current_)
    this->current_->push_back (obj);
}

//
// arrange_objects_horizontal
//
void Layout_Manager::arrange_objects (bool vertical)
{
  GAME::FCO fco;
  GAME::utils::Point pt (60, 60);
  int cx = vertical ? 0 : 100;
  int cy = vertical ? 100 : 0;

  for (object_list::const_iterator iter = this->current_->begin (),
       iter_end = this->current_->end (); iter != iter_end; ++ iter)
  {
    // Get the FCO from the object.
    fco = GAME::FCO::_narrow (*iter);

    // Set the position of the object.
    GAME::utils::set_position ("InterfaceDefinition", pt, fco);

    // Move to the next position.
    pt.shift (cx, cy);
  }
}
