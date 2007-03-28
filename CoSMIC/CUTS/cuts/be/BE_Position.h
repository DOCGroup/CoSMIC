// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Position.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_POSITION_H_
#define _CUTS_BE_POSITION_H_

#include "BE_export.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_BE_Position
 *
 * Generic backend object for managing position. This object can
 * insert and extract the position information from GME objects.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Position
{
public:
  /// Default constructor.
  CUTS_BE_Position (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       x       The x-coordinate.
   * @param[in]       y       The y-coordinate.
   */
  CUTS_BE_Position (size_t x, size_t y);

  /**
   * Copy constructor.
   *
   * @param[in]       pos     The source position.
   */
  CUTS_BE_Position (const CUTS_BE_Position & pos);

  /// Destructor.
  ~CUTS_BE_Position (void);

  /**
   * Assignment operator.
   *
   * @param[in]       pos     The source position.
   * @return          Reference to this object.
   */
  const CUTS_BE_Position & operator = (const CUTS_BE_Position & pos);

  /// Get the x-coordinate.
  size_t get_x (void) const;

  /// Set the x-coordinate.
  void set_x (size_t x);

  /// Get the y-coordinate.
  size_t get_y (void) const;

  /// Set the y-coordinate.
  void set_y (size_t y);

  bool operator << (const PICML::MgaObject & object);

  bool operator >> (PICML::MgaObject & object);

  void translate (size_t dx, size_t dy);

private:
  /// The x-coordinate.
  size_t x_;

  /// The y-coordinate.
  size_t y_;
};

#if defined (__CUTS_INLINE__)
#include "BE_Position.inl"
#endif

#endif  // !defined _CUTS_BE_POSITION_H_
