// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "ComponentInstanceRef_Event_Handler.h"

#include "game/GAME.h"

namespace PICML
{
namespace MI
{

//
// ComponentInstanceRef_Event_Handler
//
ComponentInstanceRef_Event_Handler::ComponentInstanceRef_Event_Handler (void)
: Event_Handler_Base (OBJEVENT_SETINCLUDED)
{

}

//
// ~ComponentInstanceRef_Event_Handler
//
ComponentInstanceRef_Event_Handler::~ComponentInstanceRef_Event_Handler (void)
{

}

//
// handle_set_included
//
int ComponentInstanceRef_Event_Handler::
handle_set_included (GAME::Object obj)
{
  return 0;
}

}
}