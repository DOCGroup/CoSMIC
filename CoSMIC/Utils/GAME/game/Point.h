// -*- C++ -*-

//=============================================================================
/**
 * @file      Point.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_POINT_H_
#define _GME_POINT_H_

#include "GME_export.h"

namespace GME
{
  /**
   * @class Point
   *
   * Simple class for manipulating points.
   */
  class GME_Export Point
  {
  public:
    /// Default constructor.
    Point (void);

    /**
     * Initializing constructor
     *
     * @param[in]     x           X-value
     * @param[in]     y           Y-value
     */
    Point (long x, long y);

    /**
     * Copy constructor
     *
     * @param[in]     pt          Source point
     */
    Point (const Point & pt);

    /**
     * Copy operator
     *
     * @param[in]     pt          Source point
     */
    const Point & operator = (const Point & pt);

    /**
     * Shift the point
     *
     * @param[in]     x_offset    X-shift value
     * @param[in]     y_offset    Y-shift value
     */
    void shift (long x_offset, long y_offset);

    bool operator == (const Point & pt) const;
    bool operator != (const Point & pt) const;

    /// X-value of the point.
    long x_;

    /// Y-value of the point.
    long y_;
  };
}

#if defined (__GME_INLINE___)
#include "Point.inl"
#endif

#endif  // !defined _GME_POINT_H_
