// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{
namespace graphics
{

//
// Stock_Objects
//
GAME_INLINE
Stock_Objects::Stock_Objects (void)
{
  this->init ();
}

//
// ~Stock_Objects
//
GAME_INLINE
Stock_Objects::~Stock_Objects (void)
{

}

//
// label_font
//
GAME_INLINE
const Gdiplus::Font * Stock_Objects::label_font (void) const
{
  return this->label_font_.get ();
}

//
// label_brush
//
GAME_INLINE
const Gdiplus::Brush * Stock_Objects::label_brush (void) const
{
  return this->label_brush_.get ();
}

//
// label_string_format
//
GAME_INLINE
const Gdiplus::StringFormat * Stock_Objects::label_string_format (void) const
{
  return this->label_str_format_.get ();
}

}
}
}
