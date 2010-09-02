// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GAME
{
namespace XME
{
//
// Object
//
GAME_INLINE
Object::Object (void)
: obj_ (0),
  type_ (Object_Type::OT_UNKNOWN)
{

}

//
// Object
//
GAME_INLINE
Object::Object (xercesc::DOMElement * e, int type)
: obj_ (e),
  type_ (type)
{

}

//
// Object
//
GAME_INLINE
Object::Object (xercesc::DOMElement * e, bool validate)
: obj_ (0),
  type_ (Object_Type::OT_UNKNOWN)
{
  this->attach (e, validate);
}

//
// Object
//
GAME_INLINE
Object::Object (const Object & obj)
: obj_ (obj.obj_),
  type_ (obj.type_)
{

}

//
// ~Object
//
GAME_INLINE
Object::~Object (void)
{

}

//
// ptr
//
GAME_INLINE
xercesc::DOMElement * Object::ptr (void) const
{
  return this->obj_;
}

//
// operator =
//
GAME_INLINE
const Object & Object::operator = (const Object & obj)
{
  this->obj_ = obj.obj_;
  this->type_ = obj.type_;

  return *this;
}

//
// operator ==
//
GAME_INLINE
bool Object::operator == (const Object & rhs) const
{
  return this->obj_ == rhs.obj_ || (0 != this->obj_ && this->obj_->isSameNode (rhs.obj_));
}

//
// operator !=
//
GAME_INLINE
bool Object::operator != (const Object & rhs) const
{
  return !(*this == rhs);
}

//
// id
//
GAME_INLINE
const XMLCh * Object::id (void) const
{
  return this->obj_->getAttribute (ATTR_ID);
}

//
// name
//
GAME_INLINE
const XMLCh * Object::name (void) const
{
  return this->obj_->getFirstChild ()->getTextContent ();
}

//
// name
//
GAME_INLINE
void Object::name (const GAME::Xml::String & value)
{
  this->obj_->getFirstChild ()->setTextContent (value);
}

//
// is_nil
//
GAME_INLINE
bool Object::is_nil (void) const
{
  return this->obj_ == 0;
}

//
// type
//
GAME_INLINE
int Object::type (void) const
{
  return this->type_;
}

//
// release
//
GAME_INLINE
xercesc::DOMElement * Object::release (void)
{
  xercesc::DOMElement * e = this->obj_;
  this->obj_ = 0;

  return e;
}

//
// release
//
GAME_INLINE
const XMLCh * Object::kind (void) const
{
  return this->obj_->getAttribute (ATTR_KIND);
}

//
// hash
//
GAME_INLINE
unsigned long Object::hash (void) const
{
  return static_cast <unsigned long> (reinterpret_cast <uintptr_t> (this->obj_));
}

}
}
