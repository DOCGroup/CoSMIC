// $Id$

#include "stdafx.h"
#include "mga.h"

#include "Refcountable.h"

#if !defined (__GAME_INLINE__)
#include "Refcountable.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// decrement
//
long Refcountable::decrement (void)
{
  if (this->refcount_ != 0)
    -- this->refcount_;


  // If the reference count has reached 0, then we should just
  // go ahead a delete ourselfs. ;-) Also, we must store the
  // reference count since deleting the object would make the
  // "this->" pointer invalid!!
  long refcount = this->refcount_;

  if (refcount == 0)
    delete this;

  return refcount;
}

}
}
