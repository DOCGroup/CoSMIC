// -*- C++ -*-

//=============================================================================
/**
 *  @file         Point.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _COSMIC_UTILS_POINT_H_
#define _COSMIC_UTILS_POINT_H_

#include "Utils_export.h"

namespace Utils
{
/**
 * @class Point
 *
 * Class for manipulating points. A point is an object that
 * has a x- and y-coordinate, or value.
 */
class Utils_Export Point
{
public:
  /// Default constructor
  Point (void);

  /**
   * Initiazing constructor
   *
   * @param[in]     x       The x-value for the point
   * @param[in]     y       The v-yalue for the point
   */
  Point (int x, int y);

  /**
   * Copy constructor
   *
   * @param[in]     pt      The source point.
   */
  Point (const Point & pt);

  /// Destructor.
  ~Point (void);

  /**
   * Get the current x-value of the point
   *
   * @return      The x-value
   */
  int x_value (void) const;

  /**
   * Set the x-value of the point.
   *
   * @param[in]   x       The new x-value
   */
  void x_value (int x);

  /**
   * Get the current y-value of the point
   *
   * @return      The y-value
   */
  int y_value (void) const;

  /**
   * Set the y-value of the point.
   *
   * @param[in]   x       The new x-value
   */
  void y_value (int y);

  /**
   * Change the current location of the point.
   *
   * @param[in]       cx      Shift value for x-coordinate
   * @param[in]       cy      Shift value for y-coordinate
   */
  void shift (int cx, int cy);

  /**
   * Set the value of the point
   *
   * @param[in]     x         New x-coordinate
   * @param[in]     y         New y-coordinate
   */
  void set (int x, int y);

  /**
   * Assignment operator
   *
   * @param[in]       rhs     Source point
   */
  const Point & operator = (const Point & rhs);

  /**
   * Test equality of two points.
   *
   * @param[in]       rhs     Right-hand side of operator
   * @retval          true    Points are equal
   * @retval          false   Points are not equal
   */
  bool operator == (const Point & rhs) const;

  /**
   * Test inequality of two points.
   *
   * @param[in]       rhs     Right-hand side of operator
   * @retval          true    Points are not equal
   * @retval          false   Points are equal
   */
  bool operator != (const Point & rhs) const;

private:
  /// The X-value of the point.
  int x_;

  /// The y-value of the point.
  int y_;
};

}

#include "Point.inl"

#endif
