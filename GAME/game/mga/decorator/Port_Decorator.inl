// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Port_Decorator
//
GAME_INLINE
Port_Decorator::Port_Decorator (const FCO_in port)
: port_ (port)
{

}

//
// Port_Decorator
//
GAME_INLINE
Port_Decorator::
Port_Decorator (const FCO_in port,
                Gdiplus::Image * image,
                const std::string & label,
                const Point & location,
                ALIGNMENT alignment)
: port_ (port),
  image_ (image),
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
void Port_Decorator::location (const Point & loc)
{
  this->location_ = loc;
}

//
// location
//
GAME_INLINE
const Point & Port_Decorator::location (void) const
{
  return this->location_;
}

//
// alignment
//
GAME_INLINE
Port_Decorator::ALIGNMENT Port_Decorator::alignment (void) const
{
  return this->alignment_;
}

//
// alignment
//
GAME_INLINE
void Port_Decorator::alignment (ALIGNMENT align)
{
  this->alignment_ = align;
}

//
// fco
//
GAME_INLINE
FCO Port_Decorator::fco (void) const
{
  return this->port_;
}

}
}
