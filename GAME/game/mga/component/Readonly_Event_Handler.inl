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
: Object_Event_Handler (0xFFFFFFFF, destroy_on_close),
  enabled_ (0)
{
  this->init ();
}

//
// Readonly_Event_Handler
//
Readonly_Event_Handler::
Readonly_Event_Handler (unsigned long enabled, bool destroy_on_close)
: Object_Event_Handler (0xFFFFFFFF, destroy_on_close),
  enabled_ (enabled)
{
  this->init ();
}

//
// Readonly_Event_Handler
//
Readonly_Event_Handler::~Readonly_Event_Handler (void)
{

}

//
// init
//
void Readonly_Event_Handler::init (void)
{
  this->enabled_ |= OBJEVENT_SELECT |
                    OBJEVENT_DESELECT |
                    OBJEVENT_MOUSEOVER |
                    OBJEVENT_OPENMODEL |
                    OBJEVENT_CLOSEMODEL;
}

}
}
