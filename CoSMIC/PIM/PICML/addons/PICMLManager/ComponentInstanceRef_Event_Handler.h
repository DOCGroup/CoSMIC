// -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentInstanceRef_Event_Handler.h
 *
 *  $Id: ComponentInstanceRef_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_COMPONENT_INSTANCE_REF_EVENT_HANDLER_H_
#define _PICML_MI_COMPONENT_INSTANCE_REF_EVENT_HANDLER_H_

#include "Event_Handler_Base.h"

namespace PICML
{
namespace MI
{

/**
 * @class ComponentInstanceRef_Event_Handler
 *
 * Adds itself to the cg_members_ in case its included
 * in the set.
 */
class ComponentInstanceRef_Event_Handler :
  public PICML::MI::Event_Handler_Base
{
public:
  /// Default constructor.
  ComponentInstanceRef_Event_Handler (void);

  /// Destructor.
  virtual ~ComponentInstanceRef_Event_Handler (void);

  virtual int handle_set_included (GAME::Object_in obj);
};

}
}

#endif