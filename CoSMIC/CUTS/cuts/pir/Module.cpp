#include "cuts/pir/Module.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Module.inl"
#endif

#include "cuts/pir/Component.h"
#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/Object.h"

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
    // Delete all the components.
    for ( Components::iterator iter = this->components_.begin ();
          iter != this->components_.end ();
          iter ++)
    {
      delete (*iter);
    }

    // Delete all the modules.
    for ( Modules::iterator iter = this->modules_.begin ();
          iter != this->modules_.end ();
          iter ++)
    {
      delete (*iter);
    }

    // Delete all the objects.
    for ( Objects::iterator iter = this->objects_.begin ();
          iter != this->objects_.end ();
          iter ++)
    {
      delete (*iter);
    }
  }
}
