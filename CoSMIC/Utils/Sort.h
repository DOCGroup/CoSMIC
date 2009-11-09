// -*- C++ -*-

//=============================================================================
/**
 *  @file         Sort.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _COSMIC_UTILS_SORT_H_
#define _COSMIC_UTILS_SORT_H_

#include "Point.h"

namespace Utils
{
/**
 * @struct Sort_T2B
 *
 * Functor for sorting points from top-to-bottom (T2B). This version
 * of the sort does not take into account the fact that there may be
 * multiple columns. It treats all points as if they are on the same
 * column and only evaluates the verical position (i.e., the y-coordinate).
 */
struct Utils_Export Sort_T2B
{
  bool operator () (const Utils::Point & lhs, const Utils::Point & rhs) const;
};
}

#include "Sort.inl"

#endif  // !defined _COSMIC_UTILS_SORT_H_
