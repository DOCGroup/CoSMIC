// -*- C++ -*-
// $Id$

#include "Attribute.h"
#include "MetaAttribute.h"
#include "MetaFCO.h"

namespace GAME
{
//
// FCO
//
GAME_INLINE
FCO::FCO (void)
{

}

//
// FCO
//
GAME_INLINE
FCO::FCO (IMgaFCO * fco)
  : Object (fco)
{

}

//
// FCO
//
GAME_INLINE
FCO::FCO (const FCO & fco)
  : Object (fco)
{

}

//
// ~FCO
//
GAME_INLINE
FCO::~FCO (void)
{

}

//
// attach
//
GAME_INLINE
void FCO::attach (IMgaFCO * fco)
{
  Object::attach (fco);
}

//
// is_subtype
//
GAME_INLINE
bool FCO::is_subtype (void) const
{
  return !this->basetype ().is_nil ();
}


//
// attribute
//
GAME_INLINE
Attribute FCO::attribute (const std::string & name) const
{
  return this->attribute (this->meta ().attribute (name));
}
}
