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
  const char * Element::uuid (void) const
  {
    return this->uuid_.c_str ();
  }

  CUTS_INLINE
  void Element::uuid (const char * uuid)
  {
    this->uuid_ = uuid;
  }

  //
  // name
  //
  CUTS_INLINE
  const char * Element::name (void) const
  {
    return this->name_.c_str ();
  }

  CUTS_INLINE
  void Element::name (const char * name)
  {
    this->name_ = name;
  }

  //===========================================================================
  /*
   * class Reference_Element
   */
  //===========================================================================

  //
  // reference
  //
  CUTS_INLINE
  Element * Reference_Element::reference (void) const
  {
    return this->reference_;
  }

  CUTS_INLINE
  void Reference_Element::reference (Element * reference)
  {
    this->reference_ = reference;
  }

  //===========================================================================
  /*
   * class Module_Element
   */
  //===========================================================================

  //
  // scope
  //
  CUTS_INLINE
  Module * Module_Element::module (void) const
  {
    return this->module_;
  }
}
