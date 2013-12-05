// -*- C++ -*-

//=============================================================================
/**
 *  @file       Event_Handler_Base.h
 *
 *  $Id:        Event_Handler_Base.h 2453 2010-08-24 12:00:00Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_EVENT_HANDLER_BASE_H_
#define _PICML_MI_EVENT_HANDLER_BASE_H_

#include "game/mga/component/Object_Event_Handler.h"
#include "game/mga/Model.h"

namespace PICML
{
namespace MI
{

/**
 * @class Event_Handler_Base
 *
 * Contains common objects and implementations
 */
class Event_Handler_Base :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Default constructor.
  Event_Handler_Base (unsigned long mask);

  /// Destructor.
  virtual ~Event_Handler_Base (void);

protected:
  void set_property_type (GAME::Mga::Model_in prop, const GAME::Mga::FCO_in type);
};

}
}

#endif