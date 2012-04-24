// $Id$

#include "stdafx.h"
#include "Event_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// close
//
void Event_Handler::close (void)
{
  if (this->destroy_on_close_)
    delete this;
}

}
}
