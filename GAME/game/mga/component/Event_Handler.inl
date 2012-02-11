// $Id$

#include "Event_Handler_Interface.h"

namespace GAME
{
namespace Mga
{

//
// ~Event_Handler
//
GAME_INLINE
Event_Handler::~Event_Handler (void)
{

}

//
// enable
//
GAME_INLINE
void Event_Handler::enable (bool state)
{
  this->enable_ = state;
}

}
}
