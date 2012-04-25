// $Id$

#include "StdAfx.h"
#include "Single_Deployment_Event_Handler.h"

#include "game/mga/Set.h"
#include "game/mga/component/Console_Service.h"

namespace PICML
{
namespace MI
{

//
// Single_Deployment_Event_Handler
//
Single_Deployment_Event_Handler::Single_Deployment_Event_Handler (void)
: GAME::Mga::Object_Event_Handler (OBJEVENT_SETINCLUDED | OBJEVENT_RELATION)
{

}

//
// ~Single_Deployment_Event_Handler
//
Single_Deployment_Event_Handler::~Single_Deployment_Event_Handler (void)
{

}

//
// handle_set_included
//
int Single_Deployment_Event_Handler::
handle_set_included (GAME::Mga::Object_in obj)
{
  this->fco_ = GAME::Mga::FCO::_narrow (obj);
  return 0;
}

//
// handle_object_relation
//
int Single_Deployment_Event_Handler::
handle_object_relation (GAME::Mga::Object_in obj)
{
  if (this->fco_.is_nil ())
    return 0;

  // Get the collection of CollocationGroups the FCO is a member.
  std::vector <GAME::Mga::Set> sets;

  if (0 == this->fco_->in_sets (sets))
    return 0;

  std::vector <GAME::Mga::Set>::iterator
    iter = sets.begin (), iter_end = sets.end ();

  for (; iter != iter_end; ++ iter)
  {
    // Remove the recently added object from the other set(s).
    if (!obj->is_equal_to (*iter))
      (*iter)->remove (this->fco_);
  }

  // Reset the FCO reference.
  this->fco_ = 0;

  return 0;
}

}
}
