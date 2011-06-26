// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Console_Service
//
GAME_INLINE
Console_Service::Console_Service (void)
{

}

//
// ~Console_Service
//
GAME_INLINE
Console_Service::~Console_Service (void)
{

}

//
// is_initialized
//
GAME_INLINE
bool Console_Service::is_initialized (void) const
{
  return 0 != this->gmeapp_;
}

}
}
