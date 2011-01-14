// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "Component_Event_Handler.h"

#include "Default_Implementation_Generator.h"
#include "Default_Artifact_Generator.h"
#include "Dialogs.h"
#include "Implementation_Configuration.h"
#include "Validation.h"

#include "game/utils/modelgen.h"
#include "game/utils/Point.h"

#include "Utils/Utils.h"

#include "boost/bind.hpp"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include <functional>

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;
//
// Component_Event_Handler
//
Component_Event_Handler::Component_Event_Handler (void)
: GAME::Event_Handler_Impl (mask)
{

}

//
// ~Component_Event_Handler
//
Component_Event_Handler::~Component_Event_Handler (void)
{

}

//
// handle_object_created
//
int Component_Event_Handler::
handle_object_created (GAME::Object_in obj)
{
  return 0;
}

}
}