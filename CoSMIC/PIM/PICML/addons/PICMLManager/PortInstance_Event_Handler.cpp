// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "PortInstance_Event_Handler.h"

namespace PICML
{
namespace MI
{

//
// ExtendedPortInstance_Destroyed_Event_Handler
//
ExtendedPortInstance_Destroyed_Event_Handler::ExtendedPortInstance_Destroyed_Event_Handler (void)
: GAME::Event_Handler_Impl (OBJEVENT_DESTROYED)
{

}

//
// ~ExtendedPortInstance_Destroyed_Event_Handler
//
ExtendedPortInstance_Destroyed_Event_Handler::~ExtendedPortInstance_Destroyed_Event_Handler (void)
{

}

//
// handle_object_destroyed
//
int ExtendedPortInstance_Destroyed_Event_Handler::
handle_object_destroyed (GAME::Object obj)
{
  return S_FALSE;
}

//
// MirrorPortInstance_Destroyed_Event_Handler
//
MirrorPortInstance_Destroyed_Event_Handler::MirrorPortInstance_Destroyed_Event_Handler (void)
: GAME::Event_Handler_Impl (OBJEVENT_DESTROYED)
{

}

//
// ~MirrorPortInstance_Destroyed_Event_Handler
//
MirrorPortInstance_Destroyed_Event_Handler::~MirrorPortInstance_Destroyed_Event_Handler (void)
{

}

//
// handle_object_destroyed
//
int MirrorPortInstance_Destroyed_Event_Handler::
handle_object_destroyed (GAME::Object obj)
{
  return S_FALSE;
}

}
}