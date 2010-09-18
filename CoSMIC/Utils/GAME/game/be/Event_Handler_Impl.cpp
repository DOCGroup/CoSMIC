// $Id$

#include "stdafx.h"
#include "Event_Handler_Impl.h"

#if !defined (__GAME_INLINE__)
#include "Event_Handler_Impl.inl"
#endif

namespace GAME
{

//
// close
//
void Event_Handler_Impl::close (void)
{
  if (this->destroy_on_close_)
    delete this;
}

}
