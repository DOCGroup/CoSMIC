// $Id$

#include "cuts/pir/Method.h"

#if !defined (__CUT_INLINE__)
#include "cuts/pir/Method.inl"
#endif

#include "cuts/pir/Worker_Action.h"
#include "cuts/utils/Functor_T.h"
#include <algorithm>

namespace CUTS_PIR
{
  //
  // Method
  //
  Method::Method (void)
  {

  }

  //
  // ~Method
  //
  Method::~Method (void)
  {
    std::for_each (
      this->actions_.c.begin (),
      this->actions_.c.end (),
      Delete_Element_T <Worker_Actions::container_type::value_type> ());
  }
}
