// $Id$

#include "Event_Handler_Interface.h"

GAME_INLINE
unsigned long
ACE_Hash <GAME::Mga::Event_Handler_Interface *>::
operator () (const GAME::Mga::Event_Handler_Interface * t) const
{
  return  static_cast <unsigned long> (reinterpret_cast<uintptr_t> (t));
}

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
  this->close ();
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
