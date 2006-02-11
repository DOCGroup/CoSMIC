// $Id$

namespace CUTS_PIR
{
  //===========================================================================
  /*
   * class Element
   */
  //===========================================================================

  //
  // uuid
  //
  CUTS_INLINE
  const std::string & Element::uuid (void) const
  {
    return this->uuid_;
  }

  CUTS_INLINE
  void Element::uuid (std::string & uuid)
  {
    this->uuid_ = uuid;
  }

  //
  // name
  //
  CUTS_INLINE
  const std::string & Element::name (void) const
  {
    return this->name_;
  }

  CUTS_INLINE
  void Element::name (std::string & name)
  {
    this->name_ = name;
  }
}
