// -*- C++ -*-

//=============================================================================
/**
 * @file      Image_Resource.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_GRAPHICS_BITMAP_RESOURCE_
#define _GAME_MGA_GRAPHICS_BITMAP_RESOURCE_

#include "game/config.h"

#include "Graphics_export.h"

namespace GAME
{
namespace Mga
{
namespace graphics
{

/**
 * @class Image_Resource
 *
 * Utility class for loading an GDI+ Bitmap from a non-bitmap resource
 * that is embedded a module. This code is derived from a class named
 * CGdiPlusBitmap.
 */
class GAME_GRAPHICS_Export Image_Resource
{
public:
  /**
   * Load the resource from the current module.
   */
  static Gdiplus::Image * load (UINT id, LPCTSTR type);

  /**
   * Load the resource from the current module.
   */
  static Gdiplus::Image * load (LPCTSTR name, LPCTSTR type);

  /**
   * Load the resource from the specified module.
   */
  static Gdiplus::Image * load (HMODULE instance,
                                 LPCTSTR name,
                                 LPCTSTR type);
};

}
}
}

#endif  // !defined _GME_GRAPHICS_IMAGE_RESOLVER_H_
