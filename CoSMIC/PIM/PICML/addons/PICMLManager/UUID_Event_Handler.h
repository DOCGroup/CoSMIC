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

namespace PICML
{
namespace MI
{

/**
 * @class UUID_Event_Handler
 *
 * UUID handlers.
 */
class UUID_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  UUID_Event_Handler ();

  /// Destructor.
  virtual ~UUID_Event_Handler (void);

  virtual int handle_object_created (GAME::Object_in obj);

  virtual int handle_object_attribute (GAME::Object_in obj);
};

}
}

#endif