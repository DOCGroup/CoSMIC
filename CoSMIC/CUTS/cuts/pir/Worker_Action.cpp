#include "cuts/pir/Worker_Action.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Worker_Action.inl"
#endif

#include "cuts/pir/Action_Property.h"
#include "cuts/utils/Functor_T.h"
#include <algorithm>

namespace CUTS_PIR
{
  //
  // Worker_Action
  //
  Worker_Action::Worker_Action (const Worker_Type * parent)
    : parent_ (parent),
      log_action_ (false),
      repetitions_ (1)
  {

  }

  //
  // ~Worker_Action
  //
  Worker_Action::~Worker_Action (void)
  {
    std::for_each (
      this->properties_.c.begin (),
      this->properties_.c.end (),
      Delete_Element_T <Properties::container_type::value_type> ());
  }
}
