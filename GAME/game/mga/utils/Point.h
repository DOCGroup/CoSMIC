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

#ifndef _GAME_MGA_UTILS_POINT_H_
#define _GAME_MGA_UTILS_POINT_H_

#include <string>
#include "game/mga/GME_fwd.h"
#include "game/config.h"

#include "GAME_Utils_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Point
 *
 * Class for manipulating points. A point is an object that
 * has a x- and y-coordinate, or value.
 */
class GAME_UTILS_Export Point
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

/**
 * @class Rect
 */
class GAME_UTILS_Export Rect
{
public:
  /// Default constructor.
  Rect (void);

  /**
   * Copy constructor.
   *
   * @param[in]       r       Source rectangle.
   */
  Rect (const Rect & r);

  /**
   * Initializing constructor.
   */
  Rect (int x, int y, int cx, int cy);

  /// Destructor.
  ~Rect (void);

  /// Assignment operator
  const Rect & operator = (const Rect & r);

  /// Calculate the rectangle's width.
  long width (void) const;

  /// Calculate the rectangle's height.
  long height (void) const;

  /// Set the rectangle values.
  void set (long x, long y, long cx, long cy);

  /// X-coordinate of the rectangle.
  long x_;

  /// Y-coordinate of the rectangle.
  long y_;

  long cx_;
  long cy_;
};

/**
 * Get the current position of the FCO.
 *
 * @param[in]     aspect        Aspect to retrieve position
 * @param[in]     fco           Source FCO
 * @param[out]    pt            The position of the \a fco
 * @retval        true          Succesfully retrieved position
 * @retval        false         Failed to retrieved position
 */
GAME_UTILS_Export
bool position (const std::string & aspect, const FCO_in fco, Point & pt);

GAME_UTILS_Export
bool get_position (const std::string & aspect, const FCO_in fco, Point & pt);

/**
 * Set the current position of the FCO.
 *
 * @param[in]     aspect        Aspect to retrieve position
 * @param[out]    pt            The position of the \a fco
 * @param[in]     fco           Target FCO
 * @retval        true          Succesfully set position
 * @retval        false         Failed to set position
 */
GAME_UTILS_Export
bool position (const std::string & aspect, const Point & pt, FCO_in fco);

GAME_UTILS_Export
bool set_position (const std::string & aspect, const Point & pt, FCO_in fco);

}
}

#if defined (__GAME_INLINE__)
#include "Point.inl"
#endif

#endif  // !defined _GAME_MGA_UTILS_POINT_H_
