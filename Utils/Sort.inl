// -*- C++ -*-
// $Id$

namespace Utils
{
//
// Sort_T2B::operator ()
//
inline
bool Sort_T2B::
operator () (const Utils::Point & lhs, const Utils::Point & rhs) const
{
  return lhs.y_value () < rhs.y_value ();
}

//
// Sort_L2R::operator ()
//
inline
bool Sort_L2R::
operator () (const Utils::Point & lhs, const Utils::Point & rhs) const
{
  return lhs.x_value () < rhs.x_value ();
}

}
