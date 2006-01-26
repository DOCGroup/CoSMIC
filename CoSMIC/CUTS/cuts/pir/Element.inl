// $Id$

namespace CUTS_PIR
{
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

  //
  // scope
  //
  CUTS_INLINE
  Module * Module_Element::module (void) const
  {
    return this->module_;
  }
}
