// $Id$

namespace CUTS_PIR
{
  //
  // manages
  //
  CUTS_INLINE
  void Component_Home::manages (const Component * component)
  {
    this->manages_ = component;
  }

  CUTS_INLINE
  const Component * Component_Home::manages (void) const
  {
    return this->manages_;
  }
}
