// -*- C++ -*-

//=============================================================================
/**
 *  @file       Template_Module_Instance_Handler.h
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_TEMPLATE_MODULE_INSTANCE_HANDLER_H_
#define _PICML_MI_TEMPLATE_MODULE_INSTANCE_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"
#include "game/mga/Model.h"

namespace PICML
{
namespace MI
{
/**
 * @class Template_Module_Instance_Handler
 *
 * Event handler for the TemplateModuleInst
 */
class Template_Module_Instance_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Default constructor.
  Template_Module_Instance_Handler (void);

  /// Destructor.
  virtual ~Template_Module_Instance_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);

  virtual int handle_lost_child (GAME::Mga::Object_in obj);
};

}
}

#if defined (__GAME_INLINE__)
#include "Template_Module_Instance_Handler.inl"
#endif

#endif
