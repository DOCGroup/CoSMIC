// -*- C++ -*-
// $Id$

#include "FCO.h"

namespace GAME
{
namespace XME
{
//
// Registry
//
GAME_INLINE
Registry::Registry (const Registry & r)
: parent_ (r.parent_)
{

}

//
// Registry
//
GAME_INLINE
Registry::Registry (Object parent)
: parent_ (parent)
{

}

//
// ~Registry
//
GAME_INLINE
Registry::~Registry (void)
{

}

//
// operator =
//
GAME_INLINE
const Registry & Registry::operator = (const Registry & r)
{
  this->parent_ = r.parent_;
  return *this;
}

//
// owner
//
GAME_INLINE
Object & Registry::owner (void)
{
  return this->parent_;
}

//
// owner
//
GAME_INLINE
const Object & Registry::owner (void) const
{
  return this->parent_;
}

}
}
