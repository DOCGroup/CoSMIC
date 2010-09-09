// -*- C++ -*-

//=============================================================================
/**
 *  @file       UUID_Event_Handler.h
 *
 *  $Id:        UUID_Event_Handler.h 2453 2010-08-24 12:00:00Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_UUID_EVENT_HANDLER_H_
#define _PICML_MI_UUID_EVENT_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"

#include "Event_Handler_Config.h"

namespace PICML
{
namespace MI
{

/**
 * @class UUID_Event_Handler_Base
 *
 * Base class for UUID handlers.
 */
class UUID_Event_Handler_Base :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  UUID_Event_Handler_Base (objectevent_enum e);

  /// Destructor.
  virtual ~UUID_Event_Handler_Base (void);

  bool get_uuid_i (const GAME::FCO & fco, GAME::Attribute & attr);

protected:
  PICML::MI::Event_Handler_Config * config_;
};

/**
 * @class UUID_Create_Event_Handler
 *
 * This class creates a UUID for the desired object.
 */
class UUID_Create_Event_Handler :
  public PICML::MI::UUID_Event_Handler_Base
{
public:
  /// Default constructor.
  UUID_Create_Event_Handler (void);

  /// Destructor.
  virtual ~UUID_Create_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);
};

/**
 * @class UUID_Verify_Event_Handler
 *
 * This class handles the UUID verification of the desired object.
 */
class UUID_Verify_Event_Handler :
  public PICML::MI::UUID_Event_Handler_Base
{
public:
  /// Default constructor.
  UUID_Verify_Event_Handler (void);

  /// Destructor.
  virtual ~UUID_Verify_Event_Handler (void);

  virtual int handle_object_attribute (GAME::Object obj);
};

}
}

#endif