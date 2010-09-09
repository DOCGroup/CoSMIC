// -*- C++ -*-

//=============================================================================
/**
 *  @file       Component_Event_Handler.h
 *
 *  $Id: Component_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_COMPONENT_EVENT_HANDLER_H_
#define _PICML_MI_COMPONENT_REFERENCE_EVENT_HANDLER_H_

#include "game/GAME.h"
#include "game/be/Event_Handler_Impl.h"

#include "Event_Handler_Config.h"

namespace PICML
{
namespace MI
{

/**
 * @class Component_Create_Event_Handler
 *
 * This class creates a Component and its desired implementation.
 */
class Component_Create_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  Component_Create_Event_Handler (void);

  /// Destructor.
  virtual ~Component_Create_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);

  PICML::MI::Event_Handler_Config * config_;
};

}
}

#endif