// $Id$

namespace CUTS_PIR
{
  //
  // components
  //
  CUTS_INLINE
  Module::Components & Module::components (void)
  {
    return this->components_;
  }

  CUTS_INLINE
  const Module::Components & Module::components (void) const
  {
    return this->components_;
  }

  //
  // modules
  //
  CUTS_INLINE
  Module::Modules & Module::modules (void)
  {
    return this->modules_;
  }

  CUTS_INLINE
  const Module::Modules & Module::modules (void) const
  {
    return this->modules_;
  }

  //
  // modules
  //
  CUTS_INLINE
  Module::Objects & Module::objects (void)
  {
    return this->objects_;
  }

  CUTS_INLINE
  const Module::Objects & Module::objects (void) const
  {
    return this->objects_;
  }

  //
  // parent
  //
  CUTS_INLINE
  const Module * Module::parent (void) const
  {
    return this->parent_;
  }
}
