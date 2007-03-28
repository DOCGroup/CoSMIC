// -*- C++ -*-
// $Id$

//
// CUTS_BE_Position
//
CUTS_INLINE
CUTS_BE_Position::CUTS_BE_Position (void)
: x_ (0),
  y_ (0)
{

}

//
// CUTS_BE_Position
//
CUTS_INLINE
CUTS_BE_Position::CUTS_BE_Position (size_t x, size_t y)
: x_ (x),
  y_ (y)
{

}

//
// CUTS_BE_Position
//
CUTS_INLINE
CUTS_BE_Position::CUTS_BE_Position (const CUTS_BE_Position & pos)
: x_ (pos.x_),
  y_ (pos.y_)
{

}

//
// ~CUTS_BE_Position
//
CUTS_INLINE
CUTS_BE_Position::~CUTS_BE_Position (void)
{

}

//
// set_x
//
CUTS_INLINE
void CUTS_BE_Position::set_x (size_t x)
{
  this->x_ = x;
}

//
// set_y
//
CUTS_INLINE
void CUTS_BE_Position::set_y (size_t y)
{
  this->y_ = y;
}

//
// get_x
//
CUTS_INLINE
size_t CUTS_BE_Position::get_x (void) const
{
  return this->x_;
}

//
// get_y
//
CUTS_INLINE
size_t CUTS_BE_Position::get_y (void) const
{
  return this->y_;
}

//
// operator =
//
CUTS_INLINE
const CUTS_BE_Position & CUTS_BE_Position::
operator = (const CUTS_BE_Position & pos)
{
  this->x_ = pos.x_;
  this->y_ = pos.y_;
  return *this;
}

CUTS_INLINE
void CUTS_BE_Position::translate (size_t dx, size_t dy)
{
  this->x_ += dx;
  this->y_ += dy;
}
