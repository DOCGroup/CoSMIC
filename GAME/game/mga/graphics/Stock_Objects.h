// -*- C++ -*-

//=============================================================================
/**
 * @file      Stock_Objects.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_GRAPHICS_STOCK_OBJECTS_H_
#define _GAME_MGA_GRAPHICS_STOCK_OBJECTS_H_

#include <string>
#include <vector>

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "game/config.h"

#include "Graphics_export.h"

namespace GAME
{
namespace Mga
{

namespace graphics
{
/**
 * @class Stock_Objects
 *
 * Utility class that defines the common stock objects to provide a
 * consistent look and feel in decorators.
 */
class GAME_GRAPHICS_Export Stock_Objects
{
public:
  /// Default constructor.
  Stock_Objects (void);

  /// Destructor.
  ~Stock_Objects (void);

  /// Get the label's font.
  const Gdiplus::Font * label_font (void) const;

  /// Get the label's brush.
  const Gdiplus::Brush * label_brush (void) const;

  /// Get the label's string format.
  const Gdiplus::StringFormat * label_string_format (void) const;

private:
  /// Initilize the stock object with the default settings.
  void init (void);

  /// The font for the label.
  std::auto_ptr <Gdiplus::Font> label_font_;

  /// The brush for the label.
  std::auto_ptr <Gdiplus::Brush> label_brush_;

  /// The string format for the label.
  std::auto_ptr <Gdiplus::StringFormat> label_str_format_;
};

/// Type definition of the global image resolver.
typedef ACE_Singleton <Stock_Objects, ACE_Null_Mutex> GLOBAL_STOCK_OBJECTS;

GAME_GRAPHICS_SINGLETON_DECLARE (ACE_Singleton, Stock_Objects, ACE_Null_Mutex);

}
}
}

#if defined (__GAME_INLINE__)
#include "Stock_Objects.inl"
#endif

#endif  // !defined _GME_GRAPHICS_IMAGE_RESOLVER_H_
