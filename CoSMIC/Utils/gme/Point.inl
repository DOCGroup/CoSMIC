// $Id$

//
// Point
//
GME_INLINE
GME::Point::Point (void)
: x_ (0),
  y_ (0)
{

}

//
// Point
//
GME_INLINE
GME::Point::Point (long x, long y)
: x_ (x),
  y_ (y)
{

}

//
// Point
//
GME_INLINE
GME::Point::Point (const GME::Point & pt)
: x_ (pt.x_),
  y_ (pt.y_)
{

}

//
// operator =
//
GME_INLINE
const GME::Point & GME::Point::operator = (const GME::Point & pt)
{
  this->x_ = pt.x_;
  this->y_ = pt.y_;

  return *this;
}

//
// operator ==
//
GME_INLINE
bool GME::Point::operator == (const GME::Point & pt) const
{
  return this->x_ == pt.x_ && this->y_ == pt.y_;
}

//
// shift
//
GME_INLINE
void GME::Point::shift (long x_offset, long y_offset)
{
  this->x_ += x_offset;
  this->y_ += y_offset;
}
