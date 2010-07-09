// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Meta
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
Part::Part (IMgaMetaPart * part)
: Base (part)
{

}

//
// Part
//
GAME_INLINE
Part::Part (const Part & part)
: Base (part)
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
const Part & Part::operator = (const Part & role)
{
  Base::attach (role.part_);
  return *this;
}

}
}
