// -*- C++ -*-
// $Id$

namespace GME
{
//
// Object
//
GME_INLINE
Object::Object (void)
{

}

//
// Object
//
GME_INLINE
Object::Object (IMgaObject * object)
: object_ (object)
{

}
//
// Object
//
GME_INLINE
Object::Object (const Object & obj)
: object_ (obj.object_)
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
// attach
//
GME_INLINE
void Object::attach (IMgaObject * object)
{
  this->object_.Attach (object);
}

//
// operator ==
//
GME_INLINE
bool Object::operator == (const Object & obj) const
{
  return this->is_equal_to (obj);
}

//
// operator !=
//
GME_INLINE
bool Object::operator != (const Object & obj) const
{
  return !this->is_equal_to (obj);
}

//
// impl
//
GME_INLINE
IMgaObject * Object::impl (void) const
{
  return this->object_.p;
}

//
// is_nil
//
GME_INLINE
bool Object::is_nil (void) const
{
  return this->object_.p == 0;
}

//
// release
//
GME_INLINE
void Object::release (void)
{
  this->object_.Release ();
}

//
// operator <
//
GME_INLINE
bool Object::operator < (const GME::Object & obj) const
{
  return this->object_.p < obj.object_.p;
}

//
// operator >
//
GME_INLINE
bool Object::operator > (const GME::Object & obj) const
{
  return this->object_.p > obj.object_.p;
}

//
// operator bool
//
GME_INLINE
Object::operator bool (void)
{
  return this->object_.p != 0;
}
}
