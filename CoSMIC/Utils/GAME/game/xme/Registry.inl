// -*- C++ -*-
// $Id$

#include "FCO.h"

namespace GME
{
namespace XME
{
//
// Registry
//
GME_INLINE
Registry::Registry (const Registry & r)
: parent_ (r.parent_)
{

}

//
// Registry
//
GME_INLINE
Registry::Registry (FCO & parent)
: parent_ (parent)
{

}

//
// ~Registry
//
GME_INLINE
Registry::~Registry (void)
{

}

//
// operator =
//
GME_INLINE
const Registry & Registry::operator = (const Registry & r)
{
  this->parent_ = r.parent_;
  return *this;
}

//
// owner
//
GME_INLINE
FCO & Registry::owner (void)
{
  return this->parent_;
}

//
// owner
//
GME_INLINE
const FCO & Registry::owner (void) const
{
  return this->parent_;
}

}
}
