// $Id$

#include "Event_Handler.h"

namespace GAME
{
namespace Mga
{

//
// ~Event_Sink
//
GAME_INLINE
Event_Sink::~Event_Sink (void)
{

}

//
// enable
//
GAME_INLINE
void Event_Sink::enable (bool state)
{
  this->enable_ = state;
}

}
}
