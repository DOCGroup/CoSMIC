// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
//
// Attribute
//
GME_INLINE
Attribute::Attribute (void)
: attr_ (0),
  value_ (0)
{

}

//
// Attribute
//
GME_INLINE
Attribute::Attribute (const Attribute & attr)
: attr_ (attr.attr_),
  value_ (attr.value_)
{

}

//
// Attribute
//
GME_INLINE
Attribute::Attribute (xercesc::DOMElement * attr)
: attr_ (attr),
  value_ (0)
{

}

//
// Attribute
//
GME_INLINE
Attribute::~Attribute (void)
{

}

//
// _create
//
GME_INLINE
Attribute Attribute::_create (const FCO & fco, const ::Utils::XStr & name)
{
  return Attribute (fco, name);
}

//
// operator =
//
GME_INLINE
const Attribute & Attribute::operator = (const Attribute & attr)
{
  this->attr_ = attr.attr_;
  return *this;
}

//
// attach
//
GME_INLINE
void Attribute::attach (xercesc::DOMElement * attr, bool validate)
{
  this->attr_ = attr;
  this->value_ = 0;
}

}
}
