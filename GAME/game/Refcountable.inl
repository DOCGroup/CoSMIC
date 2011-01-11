// -*- C++ -*-
// $Id$

namespace GAME
{

//
// Refcountable
//
GAME_INLINE
Refcountable::Refcountable (void)
: refcount_ (0)
{

}

//
// Refcountable
//
GAME_INLINE
Refcountable::~Refcountable (void)
{

}

//
// refcount
//
long Refcountable::refcount (void) const
{
  return this->refcount_;
}

//
// decrement
//
GAME_INLINE
long Refcountable::increment (void)
{
  return ++ this->refcount_;
}

}
