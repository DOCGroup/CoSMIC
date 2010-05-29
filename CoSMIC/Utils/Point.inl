// -*- C++ -*-
// $Id$

namespace Utils
{
//
// Point
//
inline
Point::Point (void)
{

}

//
// Point
//
inline
Point::Point (int x, int y)
: x_ (x),
  y_ (y)
{

}

//
// Point
//
inline
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
inline
int Point::x_value (void) const
{
  return this->x_;
}

//
// x_value
//
inline
void Point::x_value (int x)
{
  this->x_ = x;
}

//
// y_value
//
inline
int Point::y_value (void) const
{
  return this->y_;
}

//
// y_value
//
inline
void Point::y_value (int y)
{
  this->y_ = y;
}

//
// shift
//
inline
void Point::shift (int cx, int cy)
{
  this->x_ += cx;
  this->y_ += cy;
}

//
// operator =
//
inline
const Point & Point::operator = (const Point & pt)
{
  this->set (pt.x_, pt.y_);
  return *this;
}

//
// operator ==
//
inline
bool Point::operator == (const Point & pt) const
{
  return (this->x_ == pt.x_ && this->y_ == pt.y_);
}

//
// operator !=
//
inline
bool Point::operator != (const Point & pt) const
{
  return !(*this == pt);
}

//
// set
//
inline
void Point::set (int x, int y)
{
  this->x_ = x;
  this->y_ = y;
}

}
