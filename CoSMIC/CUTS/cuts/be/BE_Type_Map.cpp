// $Id$

#include "BE_Type_Map.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Type_Map.inl"
#endif

//
// value
//
std::string CUTS_BE_Type_Map::value (const PICML::MemberType & type)
{
  try
  {
    PICML::PredefinedType ptype = PICML::PredefinedType::Cast (type);
    return this->value (ptype);
  }
  catch (...)
  {
    PICML::NamedType ntype = PICML::NamedType::Cast (type);
    return this->value (ntype);
  }

  return "";
}
