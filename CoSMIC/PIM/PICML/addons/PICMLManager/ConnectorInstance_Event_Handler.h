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

#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"

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
class ConnectorInstance_Event_Handler : public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ConnectorInstance_Event_Handler (void);

  /// Destructor.
  virtual ~ConnectorInstance_Event_Handler (void);

  virtual int handle_object_created (GAME::Object_in obj);
};

}
}

#endif
