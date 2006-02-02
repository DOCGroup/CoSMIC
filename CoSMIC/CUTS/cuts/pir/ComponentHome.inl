namespace CUTS_PIR
{
  CUTS_INLINE
  void Component_Home::manages (Component * component)
  {
    this->manages_ = component;
  }

  CUTS_INLINE
  const Component * Component_Home::manages (void) const
  {
    return this->manages_;
  }

  CUTS_INLINE
  Component * Component_Home::manages (void)
  {
    return this->manages_;
  }
}
