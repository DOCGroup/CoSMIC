// -*- C++ -*-

//=============================================================================
/**
 *  @file       NodeReference_Event_Handler.h
 *
 *  $Id: NodeReference_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_NODE_REFERENCE_EVENT_HANDLER_H_
#define _PICML_MI_NODE_REFERENCE_EVENT_HANDLER_H_

#include "game/GAME.h"
#include "game/be/Event_Handler_Impl.h"

namespace PICML
{
namespace MI
{

/**
 * @class NodeReference_Create_Event_Handler
 *
 * This class creates a NodeReference for the desired object.
 */
class NodeReference_Create_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  NodeReference_Create_Event_Handler (void);

  /// Destructor.
  virtual ~NodeReference_Create_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);
};

}
}

#endif