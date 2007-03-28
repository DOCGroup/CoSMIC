// $Id%

#include "BE_Position.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Position.inl"
#endif

#include <sstream>

//
// operator <<
//
bool CUTS_BE_Position::operator << (const PICML::MgaObject & object)
{
  char temp;
  std::istringstream istr (object.position ());

  istr >> temp;
  istr >> this->x_;
  istr >> temp;
  istr >> this->y_;

  return istr.good ();
}

//
// operator >>
//
bool CUTS_BE_Position::operator >> (PICML::MgaObject & object)
{
  std::ostringstream ostr;
  ostr << "(" << this->x_ << "," << this->y_ << ")";
  object.position () = ostr.str ();

  return ostr.good ();
}
