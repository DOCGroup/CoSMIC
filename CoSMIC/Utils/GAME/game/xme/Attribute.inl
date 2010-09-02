// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
//
// Attribute
//
GAME_INLINE
Attribute::Attribute (void)
: attr_ (0),
  value_ (0)
{

}

//
// Attribute
//
GAME_INLINE
Attribute::Attribute (const Attribute & attr)
: attr_ (attr.attr_),
  value_ (attr.value_)
{

}

//
// Attribute
//
GAME_INLINE
Attribute::Attribute (xercesc::DOMElement * attr)
: attr_ (attr),
  value_ (0)
{

}

//
// Attribute
//
GAME_INLINE
Attribute::~Attribute (void)
{

}

//
// _create
//
GAME_INLINE
Attribute Attribute::_create (const FCO & fco, const GAME::Xml::String & name)
{
  return Attribute (fco, name);
}

//
// operator =
//
GAME_INLINE
const Attribute & Attribute::operator = (const Attribute & attr)
{
  this->attr_ = attr.attr_;
  return *this;
}

//
// attach
//
GAME_INLINE
void Attribute::attach (xercesc::DOMElement * attr, bool validate)
{
  this->attr_ = attr;
  this->value_ = 0;
}

}
}
