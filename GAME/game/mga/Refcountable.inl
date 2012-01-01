// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
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
GAME_INLINE
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
}
