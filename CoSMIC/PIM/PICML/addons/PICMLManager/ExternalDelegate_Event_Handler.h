// -*- C++ -*-

//=============================================================================
/**
 *  @file       ExternalDelegate_Event_Handler.h
 *
 *  $Id: ExternalDelegate_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_EXTERNAL_DELEGATE_EVENT_HANDLER_H_
#define _PICML_MI_EXTERNAL_DELEGATE_EVENT_HANDLER_H_

#include "game/GAME.h"
#include "game/be/Event_Handler_Impl.h"

namespace PICML
{
namespace MI
{

/**
 * @class ExternalDelegate_Event_Handler
 *
 * This class creates a ExternalDelegate connection.
 */
class ExternalDelegate_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ExternalDelegate_Event_Handler (void);

  /// Destructor.
  virtual ~ExternalDelegate_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);
};

}
}

#endif