// -*- C++ -*-
// $Id$

#include "Attribute.h"
#include "MetaAttribute.h"
#include "MetaFCO.h"

namespace GAME
{
namespace Mga
{

//
// FCO_Impl
//
GAME_INLINE
FCO_Impl::FCO_Impl (void)
{

}

//
// FCO_Impl
//
GAME_INLINE
FCO_Impl::FCO_Impl (IMgaFCO * fco)
//: Object_Impl (fco)
{
  this->object_ = fco;
}

//
// ~FCO_Impl
//
GAME_INLINE
FCO_Impl::~FCO_Impl (void)
{

}

//
// attach
//
GAME_INLINE
void FCO_Impl::attach (IMgaFCO * fco)
{
  Object_Impl::attach (fco);
}

//
// is_subtype
//
GAME_INLINE
bool FCO_Impl::is_subtype (void) const
{
  return this->basetype ().is_nil ();
}


//
// attribute
//
GAME_INLINE
Attribute FCO_Impl::attribute (const std::string & name) const
{
  return this->attribute (this->meta ()->attribute (name));
}

}
}
