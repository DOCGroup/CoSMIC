// -*- C++ -*-
// $Id$

namespace GAME
{
//
// Object
//
GAME_INLINE
Object::Object (void)
{

}

//
// Object
//
GAME_INLINE
Object::Object (IMgaObject * object)
: object_ (object)
{

}
//
// Object
//
GAME_INLINE
Object::Object (const Object & obj)
: object_ (obj.object_)
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
// attach
//
GAME_INLINE
void Object::attach (IMgaObject * object)
{
  this->object_.Attach (object);
}

//
// operator ==
//
GAME_INLINE
bool Object::operator == (const Object & obj) const
{
  return this->is_equal_to (obj);
}

//
// operator !=
//
GAME_INLINE
bool Object::operator != (const Object & obj) const
{
  return !this->is_equal_to (obj);
}

//
// impl
//
GAME_INLINE
IMgaObject * Object::impl (void) const
{
  return this->object_.p;
}

//
// is_nil
//
GAME_INLINE
bool Object::is_nil (void) const
{
  return this->object_.p == 0;
}

//
// release
//
GAME_INLINE
void Object::release (void)
{
  this->object_.Release ();
}

//
// operator <
//
GAME_INLINE
bool Object::operator < (const GAME::Object & obj) const
{
  return this->object_.p < obj.object_.p;
}

//
// operator >
//
GAME_INLINE
bool Object::operator > (const GAME::Object & obj) const
{
  return this->object_.p > obj.object_.p;
}

//
// operator bool
//
GAME_INLINE
Object::operator bool (void)
{
  return this->object_.p != 0;
}
}
