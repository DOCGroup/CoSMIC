// -*- C++ -*-

//=============================================================================
/**
 *  @file     Port_Decorator.h
 *
 *  $$d$
 *
 *  @author   James H. Hill
 */
//=============================================================================

#ifndef _GAME_GRAPHIC_PORT_DECORATOR_H_
#define _GAME_GRAPHIC_PORT_DECORATOR_H_

#include "game/mga/FCO.h"
#include "game/mga/utils/Point.h"

#include "Decorator_export.h"

namespace Gdiplus
{
// Forward decl.
class Image;
class Graphics;
};

namespace GAME
{
namespace Mga
{

/**
 * @class Port_Decorator
 *
 * Decorator class for drawing port elements of a model.
 */
class GAME_MGA_DECORATOR_Export Port_Decorator
{
public:
  enum ALIGNMENT
  {
    ALIGNMENT_LEFT,
    ALINGMENT_RIGHT
  };

  /// Default constructor.
  Port_Decorator (const FCO_in port);

  /**
   * Initializing constructor.
   */
  Port_Decorator (const FCO_in port,
                  Gdiplus::Image *,
                  const std::string & label,
                  const Point & location,
                  ALIGNMENT alignment = ALIGNMENT_LEFT);

  /// Decorator.
  ~Port_Decorator (void);

  bool draw (Gdiplus::Graphics * g);

  void location (const Point & loc);

  const Point & location (void) const;

  ALIGNMENT alignment (void) const;
  void alignment (ALIGNMENT align);

  FCO fco (void) const;

  void get_location (long & sx,
                     long & sy,
                     long & ex,
                     long & ey);

private:
  /// FCO associated with the port.
  const FCO port_;

  /// The image to draw for the port.
  Gdiplus::Image * image_;

  /// The label for the port.
  std::string label_;

  /// Location of the port.
  Point location_;

  ALIGNMENT alignment_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Port_Decorator.inl"
#endif

#endif  // !defined _GAME_GRAPHIC_PORT_DECORATOR_H_
