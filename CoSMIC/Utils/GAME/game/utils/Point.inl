// -*- C++ -*-
// $Id$

namespace GAME
{
namespace utils
{
//
// Point
//
GAME_INLINE
Point::Point (void)
{

}

//
// Point
//
GAME_INLINE
Point::Point (int x, int y)
: x_ (x),
  y_ (y)
{

}

//
// Point
//
GAME_INLINE
Point::Point (const Point & pt)
: x_ (pt.x_),
  y_ (pt.y_)
{

}

//
// ~Point
//
inline
Point::~Point (void)
{

}

//
// x_value
//
GAME_INLINE
int Point::x_value (void) const
{
  return this->x_;
}

//
// x_value
//
GAME_INLINE
void Point::x_value (int x)
{
  this->x_ = x;
}

//
// y_value
//
GAME_INLINE
int Point::y_value (void) const
{
  return this->y_;
}

//
// y_value
//
GAME_INLINE
void Point::y_value (int y)
{
  this->y_ = y;
}

//
// shift
//
GAME_INLINE
void Point::shift (int cx, int cy)
{
  this->x_ += cx;
  this->y_ += cy;
}

//
// operator =
//
GAME_INLINE
const Point & Point::operator = (const Point & pt)
{
  this->set (pt.x_, pt.y_);
  return *this;
}

//
// operator ==
//
GAME_INLINE
bool Point::operator == (const Point & pt) const
{
  return (this->x_ == pt.x_ && this->y_ == pt.y_);
}

//
// operator !=
//
GAME_INLINE
bool Point::operator != (const Point & pt) const
{
  return !(*this == pt);
}

//
// set
//
GAME_INLINE
void Point::set (int x, int y)
{
  this->x_ = x;
  this->y_ = y;
}

///////////////////////////////////////////////////////////////////////////////
// Rect

//
// Rect
//
GAME_INLINE
Rect::Rect (void)
: x_ (0),
  y_ (0),
  cx_ (0),
  cy_ (0)
{

}

//
// Rect
//
GAME_INLINE
Rect::Rect (const Rect & r)
: x_ (r.x_),
  y_ (r.y_),
  cx_ (r.cx_),
  cy_ (r.cy_)
{

}

//
// Rect
//
GAME_INLINE
Rect::Rect (int x, int y, int cx, int cy)
: x_ (x),
  y_ (y),
  cx_ (cx),
  cy_ (cy)
{

}

//
// ~Rect
//
GAME_INLINE
Rect::~Rect (void)
{

}

//
// Rect
//
GAME_INLINE
const Rect & Rect::operator = (const Rect & r)
{
  this->x_ = r.x_;
  this->y_ = r.y_;
  this->cx_ = r.cx_;
  this->cy_ = r.cy_;

  return *this;
}

}
}
