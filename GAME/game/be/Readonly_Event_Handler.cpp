// $Id$

#include "StdAfx.h"
#include "Readonly_Event_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Readonly_Event_Handler.inl"
#endif

namespace GAME
{

//
// handle_object_event
//
int Readonly_Event_Handler::
handle_object_event (Object obj, unsigned long mask)
{
  // Determine if this is an event that we do allow.
  if ((mask & this->enabled_) != 0)
    return 0;

  // Display an error message since we do not support this event.
  ::AfxMessageBox ("This operation is not allowed.", MB_ICONERROR);
  return E_MGA_MUST_ABORT;
}

}
