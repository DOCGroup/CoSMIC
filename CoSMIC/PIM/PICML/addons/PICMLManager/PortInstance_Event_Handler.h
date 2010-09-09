// -*- C++ -*-

//=============================================================================
/**
 *  @file       PortInstance_Event_Handler.h
 *
 *  $Id: PortInstance_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_PORT_INSTANCE_EVENT_HANDLER_H_
#define _PICML_MI_PORT_INSTANCE_EVENT_HANDLER_H_

#include "game/GAME.h"
#include "game/be/Event_Handler_Impl.h"

namespace PICML
{
namespace MI
{

/**
 * @class ExtendedPortInstance_Destroyed_Event_Handler
 *
 * Handles destroyed event for ExtendedPortInstance.
 */
class ExtendedPortInstance_Destroyed_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ExtendedPortInstance_Destroyed_Event_Handler (void);

  /// Destructor.
  virtual ~ExtendedPortInstance_Destroyed_Event_Handler (void);

  virtual int handle_object_destroyed (GAME::Object obj);
};

/**
 * @class MirrorPortInstance_Destroyed_Event_Handler
 *
 * Handles destroyes event for MirrorPortInstance.
 */
class MirrorPortInstance_Destroyed_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  MirrorPortInstance_Destroyed_Event_Handler (void);

  /// Destructor.
  virtual ~MirrorPortInstance_Destroyed_Event_Handler (void);

  virtual int handle_object_destroyed (GAME::Object obj);
};

}
}

#endif