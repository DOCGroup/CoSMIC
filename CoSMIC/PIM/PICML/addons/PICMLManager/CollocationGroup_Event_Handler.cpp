// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "CollocationGroup_Event_Handler.h"

#include "game/GAME.h"

namespace PICML
{
namespace MI
{

//
// CollocationGroup_Event_Handler
//
CollocationGroup_Event_Handler::CollocationGroup_Event_Handler (void)
: Event_Handler_Base (OBJEVENT_RELATION)
{

}

//
// ~CollocationGroup_Event_Handler
//
CollocationGroup_Event_Handler::~CollocationGroup_Event_Handler (void)
{

}

//
// handle_object_created
//
int CollocationGroup_Event_Handler::
handle_object_relation (GAME::Object obj)
{
  //if (this->config_->cg_member_.is_nil ())
  //  return 0;

  //// Get all sets that contain previously inserted collocation group member.
  //typedef std::vector <GAME::Set> Sets;
  //Sets sets;

  //size_t count = this->config_->cg_member_.in_sets (sets);

  //if (count > 1)
  //{
  //  // Get the updated collocation group.
  //  GAME::Set group = GAME::Set::_narrow (obj);

  //  Sets::iterator
  //    iter = sets.begin (), iter_end = sets.end ();

  //  // Make sure the last object added to this group does not appear
  //  // in any collocation group.
  //  for ( ; iter != iter_end; ++ iter)
  //  {
  //    if (!iter->is_equal_to (group))
  //      iter->remove (this->config_->cg_member_);
  //  }
  //}

  //// Release our reference to this element.
  //this->config_->cg_member_.release ();
  return 0;
}

}
}