// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Readonly_Event_Handler
//
Readonly_Event_Handler::
Readonly_Event_Handler (bool destroy_on_close)
: Event_Handler_Impl (0xFFFFFFFF, destroy_on_close),
  enabled_ (OBJEVENT_SELECT)
{

}

//
// Readonly_Event_Handler
//
Readonly_Event_Handler::
Readonly_Event_Handler (unsigned long enabled, bool destroy_on_close)
: Event_Handler_Impl (0xFFFFFFFF, destroy_on_close),
  enabled_ (enabled | OBJEVENT_SELECT)
{

}

//
// Readonly_Event_Handler
//
Readonly_Event_Handler::~Readonly_Event_Handler (void)
{

}

}
}
