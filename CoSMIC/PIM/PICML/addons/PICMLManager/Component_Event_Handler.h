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
#define _PICML_MI_COMPONENT_EVENT_HANDLER_H_

#include "game/mga/be/Event_Handler_Impl.h"

namespace PICML
{
namespace MI
{

/**
 * @class Component_Event_Handler
 *
 * This class creates a Component and its desired implementation.
 */
class Component_Event_Handler :
  public GAME::Mga::Event_Handler_Impl
{
public:
  /// Default constructor.
  Component_Event_Handler (void);

  /// Destructor.
  virtual ~Component_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

}
}

#endif  // !defined _PICML_MI_COMPONENT_EVENT_HANDLER_H_
