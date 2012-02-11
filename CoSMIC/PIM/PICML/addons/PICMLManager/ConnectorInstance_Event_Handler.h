// -*- C++ -*-

//=============================================================================
/**
 *  @file       ConnectorInstance_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_CONNECTOR_INSTANCE_HANDLER_H_
#define _PICML_MI_CONNECTOR_INSTANCE_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"
#include "game/mga/Model.h"

namespace PICML
{
namespace MI
{
/**
 * @class ConnectorInstance_Event_Handler
 *
 * Event handler for managing the functionality of a ComponentInstance
 * in PICML.
 */
class ConnectorInstance_Event_Handler :
  public GAME::Mga::Dynamic_Event_Handler_Impl
{
public:
  /// Default constructor.
  ConnectorInstance_Event_Handler (void);

  /// Destructor.
  virtual ~ConnectorInstance_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

}
}

#endif
