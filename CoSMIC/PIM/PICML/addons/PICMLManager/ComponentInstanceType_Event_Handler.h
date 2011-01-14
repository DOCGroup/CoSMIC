// -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentInstanceType_Event_Handler.h
 *
 *  $Id: ComponentInstanceType_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_COMPONENT_INSTANCE_TYPE_HANDLER_H_
#define _PICML_MI_COMPONENT_INSTANCE_TYPE_HANDLER_H_

#include "game/GAME.h"
#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

/**
 * @class ComponentInstanceType_Event_Handler
 *
 * Handles ComponentInstanceType when a relation is created.
 */
class ComponentInstanceType_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ComponentInstanceType_Event_Handler (void);

  /// Destructor.
  virtual ~ComponentInstanceType_Event_Handler (void);

  virtual int handle_object_relation (GAME::Object_in obj);

  void generate_port_instances (GAME::Model inst,
                                const GAME::Model & component);
};

}
}

#endif
