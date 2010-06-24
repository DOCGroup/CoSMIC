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

#include <string>
#include "game/FCO.h"
#include "game/utils/Point.h"
#include "Graphics_export.h"

namespace Gdiplus
{
// Forward decl.
class Image;
class Graphics;
};

namespace GAME
{
namespace graphics
{
/**
 * @class Port_Decorator
 *
 * Decorator class for drawing port elements of a model.
 */
class GAME_GRAPHICS_Export Port_Decorator
{
public:
  enum ALIGNMENT
  {
    ALIGNMENT_LEFT,
    ALINGMENT_RIGHT
  };

  /// Default constructor.
  Port_Decorator (const GAME::FCO & port);

  /**
   * Initializing constructor.
   */
  Port_Decorator (const GAME::FCO & port,
                  Gdiplus::Image *, 
                  const std::string & label,
                  const utils::Point & location,
                  ALIGNMENT alignment = ALIGNMENT_LEFT);

  /// Decorator.
  ~Port_Decorator (void);

  bool draw (Gdiplus::Graphics & g);

  void location (const utils::Point & loc);
  const utils::Point & location (void) const;
  
  ALIGNMENT alignment (void) const;
  void alignment (ALIGNMENT align);

  const GAME::FCO & fco (void) const;

  void get_location (long & sx, 
                     long & sy, 
                     long & ex, 
                     long & ey);

private:
  /// FCO associated with the port.
  GAME::FCO port_;

  /// The image to draw for the port.
  Gdiplus::Image * image_;

  /// The label for the port.
  std::string label_;

  /// Location of the port.
  utils::Point location_;

  ALIGNMENT alignment_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Port_Decorator.inl"
#endif

#endif  // !defined _GAME_GRAPHIC_PORT_DECORATOR_H_
