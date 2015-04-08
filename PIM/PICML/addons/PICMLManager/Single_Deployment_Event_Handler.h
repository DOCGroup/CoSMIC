// -*- C++ -*-

//=============================================================================
/**
 * @file      Single_Deployment_Event_Handler.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_SINGLE_DEPLOYMENT_EVENT_HANDLER_H_
#define _PICML_MI_SINGLE_DEPLOYMENT_EVENT_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"

namespace PICML
{
namespace MI
{

/**
 * @class Single_Deployment_Event_Handler
 *
 * Event handler the ensure components are not deployed to more than
 * one CollocationGroup. If a component is already deployed to a
 * CollocationGroup and moved to another one, then it is removed from
 * it previous CollocationGroup.
 */
class Single_Deployment_Event_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Default constructor.
  Single_Deployment_Event_Handler (void);

  /// Destructor.
  virtual ~Single_Deployment_Event_Handler (void);

  virtual int handle_set_included (GAME::Mga::Object_in obj);
  virtual int handle_object_relation (GAME::Mga::Object_in obj);

private:
  /// Recently added object to the collocation group.
  GAME::Mga::FCO fco_;
};

}
}

#endif  // !defined _PICML_MI_SINGLE_DEPLOYMENT_EVENT_HANDLER_H_
