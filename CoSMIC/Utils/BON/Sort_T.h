// -*- C++ -*-

//=============================================================================
/**
 *  @file         Sort_T.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _COSMIC_BON_UTILS_SORT_H_
#define _COSMIC_BON_UTILS_SORT_H_

#include "Point.h"

namespace BON
{
namespace Utils
{
/**
 * @struct Position_Sorter_T
 *
 * Functor that helps sort BON objects in a STL collection based on
 * their position. The first parameter is the element type. The second
 * parameter is the sort function.
 */
template <typename T, typename SORT>
struct Position_Sorter_T
{
  /**
   * Default constuctor.
   *
   * @param[in]     sorter        The actual sort function
   */
  Position_Sorter_T (void);

  /**
   * Functor that compares the position of two elements
   *
   * @param[in]     lhs           Left-hand side of operator
   * @param[in]     rhs           Right-hand side of operator
   */
  bool operator () (const T & lhs, const T & rhs) const;

private:
  /// The actual sorter for the functor.
  SORT sorter_;
};

}
}

#include "Sort_T.cpp"

#endif  // !defined _COSMIC_BON_UTILS_SORT_H_
