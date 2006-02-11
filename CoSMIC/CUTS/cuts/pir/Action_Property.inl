// $Id$

namespace CUTS_PIR
{
  CUTS_INLINE
  void Action_Property::value (std::string & value)
  {
    this->value_ = value;
  }

  CUTS_INLINE
  const std::string & Action_Property::value (void) const
  {
    return this->value_;
  }
}
