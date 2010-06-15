// -*- C++ -*-
// $Id$

namespace GAME
{
namespace graphics
{
//
// Port_Decorator
//
GAME_INLINE
Port_Decorator::Port_Decorator (void)
{

}

//
// Port_Decorator
//
GAME_INLINE
Port_Decorator::
Port_Decorator (Gdiplus::Image * image, 
                const std::string & label,
                const utils::Point & location,
                ALIGNMENT alignment)
: image_ (image),
  label_ (label),
  location_ (location),
  alignment_ (alignment)
{

}

//
// ~Port_Decorator
//
GAME_INLINE
Port_Decorator::~Port_Decorator (void)
{

}

//
// location
//
GAME_INLINE
void Port_Decorator::location (const utils::Point & loc)
{
  this->location_ = loc;
}

//
// location
//
GAME_INLINE
const utils::Point & Port_Decorator::location (void) const
{
  return this->location_;
}

//
// alignment
//
Port_Decorator::ALIGNMENT Port_Decorator::alignment (void) const
{
  return this->alignment_;
}

//
// alignment
//
void Port_Decorator::alignment (ALIGNMENT align)
{
  this->alignment_ = align;
}

}
}
