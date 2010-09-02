// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Xml
{

///////////////////////////////////////////////////////////////////////////////
// Xml_Error_Handler

//
// Xml_Error_Handler
//
GAME_INLINE
Xml_Error_Handler::Xml_Error_Handler (void)
: has_errors_ (false)
{

}

//
// ~Xml_Error_Handler
//
GAME_INLINE
Xml_Error_Handler::~Xml_Error_Handler (void)
{

}

//
// reset
//
GAME_INLINE
void Xml_Error_Handler::reset (void)
{
  this->has_errors_ = false;
}

//
// getErrors
//
GAME_INLINE
bool Xml_Error_Handler::has_errors (void) const
{
  return this->has_errors_;
}

///////////////////////////////////////////////////////////////////////////////
// DOM_Error_Handler

//
// DOM_Error_Handler
//
GAME_INLINE
DOM_Error_Handler::DOM_Error_Handler (void)
: has_errors_ (false)
{

}

//
// ~DOM_Error_Handler
//
GAME_INLINE
DOM_Error_Handler::~DOM_Error_Handler (void)
{

}

//
// reset
//
GAME_INLINE
void DOM_Error_Handler::reset (void)
{
  this->has_errors_ = false;
}

//
// has_errors
//
GAME_INLINE
bool DOM_Error_Handler::has_errors (void) const
{
  return this->has_errors_;
}

}
}
