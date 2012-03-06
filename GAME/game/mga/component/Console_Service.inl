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

//
// error
//
GAME_INLINE
void Console_Service::error (const std::string & message)
{
  this->log (MSG_ERROR, message);
}

//
// info
//
GAME_INLINE
void Console_Service::info (const std::string & message)
{
  this->log (MSG_INFO, message);
}

//
// message
//
GAME_INLINE
void Console_Service::message (const std::string & message)
{
  this->log (MSG_NORMAL, message);
}

//
// warning
//
GAME_INLINE
void Console_Service::warning (const std::string & message)
{
  this->log (MSG_WARNING, message);
}

}
}
