// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Part
//
GAME_INLINE
Part::Part (void)
{

}

//
// Part
//
GAME_INLINE
Part::Part (IMgaPart * part)
: part_ (part)
{

}

//
// Part
//
GAME_INLINE
Part::Part (const Part & part)
: part_ (part.part_)
{

}

//
// ~Part
//
GAME_INLINE
Part::~Part (void)
{

}

//
// operator =
//
GAME_INLINE
const Part & Part::operator = (const Part & part)
{
  this->part_ = part.part_;
  return *this;
}

//
// impl
//
GAME_INLINE
IMgaPart * Part::impl (void) const
{
  return this->part_.p;
}

//
// is_nil
//
GAME_INLINE
bool Part::is_nil (void) const
{
  return this->part_.p == 0;
}

}
}
