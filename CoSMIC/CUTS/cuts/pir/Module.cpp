#include "cuts/pir/Module.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Module.inl"
#endif

#include "cuts/pir/Component.h"
#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/Object.h"
#include "cuts/pir/Method.h"
#include "cuts/utils/Functor_T.h"
#include <algorithm>

namespace CUTS_PIR
{
  //
  // Module
  //
  Module::Module (const Module * parent)
    : parent_ (parent)
  {

  }

  //
  // Module
  //
  Module::~Module (void)
  {
    std::for_each (
      this->components_.begin (),
      this->components_.end (),
      Delete_Element_T <Components::value_type> ());

    // Delete all the components.
    std::for_each (
      this->modules_.begin (),
      this->modules_.end (),
      Delete_Element_T <Modules::value_type> ());

    // Delete all the objects.
    std::for_each (
      this->objects_.begin (),
      this->objects_.end (),
      Delete_Element_T <Objects::value_type> ());
  }
}
