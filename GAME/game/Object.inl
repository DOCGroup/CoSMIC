// -*- C++ -*-
// $Id$

#include "ace/ACE.h"

namespace GAME
{
//
// Object_Impl
//
GAME_INLINE
Object_Impl::Object_Impl (void)
{

}

//
// Object_Impl
//
GAME_INLINE
Object_Impl::Object_Impl (IMgaObject * object)
: object_ (object)
{

}

//
// ~Object_Impl
//
GAME_INLINE
Object_Impl::~Object_Impl (void)
{

}

//
// attach
//
GAME_INLINE
void Object_Impl::attach (IMgaObject * object)
{
  this->object_.Attach (object);
}

//
// impl
//
GAME_INLINE
IMgaObject * Object_Impl::impl (void) const
{
  return this->object_.p;
}

//
// release
//
GAME_INLINE
void Object_Impl::release (void)
{
  this->object_.Release ();
}

//
// hash
//
GAME_INLINE
unsigned long Object_Impl::hash (void) const
{
  return ACE::hash_pjw (this->id ().c_str ());
}

}
