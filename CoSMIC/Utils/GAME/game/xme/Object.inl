// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GME
{
namespace XME
{
//
// Object
//
GME_INLINE
Object::Object (void)
: obj_ (0),
  type_ (Object_Type::OT_UNKNOWN)
{

}

//
// Object
//
GME_INLINE
Object::Object (xercesc::DOMElement * e, int type)
: obj_ (e),
  type_ (type)
{

}

//
// Object
//
GME_INLINE
Object::Object (xercesc::DOMElement * e, bool validate)
: obj_ (0),
  type_ (Object_Type::OT_UNKNOWN)
{
  this->attach (e, validate);
}

//
// Object
//
GME_INLINE
Object::Object (const Object & obj)
: obj_ (obj.obj_),
  type_ (obj.type_)
{

}

//
// ~Object
//
GME_INLINE
Object::~Object (void)
{

}

//
// ptr
//
GME_INLINE
xercesc::DOMElement * Object::ptr (void) const
{
  return this->obj_;
}

//
// operator =
//
GME_INLINE
const Object & Object::operator = (const Object & obj)
{
  this->obj_ = obj.obj_;
  this->type_ = obj.type_;

  return *this;
}

//
// operator ==
//
GME_INLINE
bool Object::operator == (const Object & rhs) const
{
  return this->obj_ != 0 &&
         this->obj_ != rhs.obj_ &&
         this->obj_->isSameNode (rhs.obj_);
}

//
// operator !=
//
GME_INLINE
bool Object::operator != (const Object & rhs) const
{
  return !(*this == rhs);
}

//
// id
//
GME_INLINE
const XMLCh * Object::id (void) const
{
  return this->obj_->getAttribute (ATTR_ID);
}

//
// name
//
GME_INLINE
const XMLCh * Object::name (void) const
{
  return Utils::get_element_value (this->obj_, ELEMENT_NAME);
}

//
// name
//
GME_INLINE
void Object::name (const ::Utils::XStr & value)
{
  Utils::set_element_value (this->obj_, ELEMENT_NAME, value);
}

//
// is_nil
//
GME_INLINE
bool Object::is_nil (void) const
{
  return this->obj_ == 0;
}

//
// type
//
GME_INLINE
int Object::type (void) const
{
  return this->type_;
}

//
// release
//
GME_INLINE
xercesc::DOMElement * Object::release (void)
{
  xercesc::DOMElement * e = this->obj_;
  this->obj_ = 0;

  return e;
}

//
// hash
//
GME_INLINE
unsigned long Object::hash (void) const
{
  return static_cast <unsigned long> (reinterpret_cast <uintptr_t> (this->obj_));
}

}
}
