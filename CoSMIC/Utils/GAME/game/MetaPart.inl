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

//
// impl
//
GAME_INLINE
IMgaMetaPart * Part::impl (void) const
{
  if (this->part_.p == this->metabase_.p)
    return this->part_.p;

  if (this->part_.p != 0)
    this->part_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->part_));
  return this->part_;
} 

}
}
