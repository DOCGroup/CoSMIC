// -*- C++ -*-
// $Id$

//
// CUTS_BE_Type_Map
//
CUTS_INLINE
CUTS_BE_Type_Map::CUTS_BE_Type_Map (void)
{

}

//
// ~CUTS_BE_Type_Map
//
CUTS_INLINE
CUTS_BE_Type_Map::~CUTS_BE_Type_Map (void)
{

}

CUTS_INLINE
std::string CUTS_BE_Type_Map::value (const PICML::PredefinedType & type)
{
  return this->predefined_type_map_[type.type ()];
}

//
// value
//
CUTS_INLINE
std::string CUTS_BE_Type_Map::value (const PICML::NamedType & type)
{
  std::string str =
    "/* named type not supported [" + (std::string) type.name () + "] */";

  return str;
}
