// -*- C++ -*-

//=============================================================================
/**
 *  @file       Template_Module_Instance_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_TEMPLATE_MODULE_INSTANCE_HANDLER_H_
#define _PICML_MI_TEMPLATE_MODULE_INSTANCE_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"

namespace PICML
{
namespace MI
{
/**
 * @class Template_Module_Instance_Handler
 *
 * Event handler for the TemplateModuleInst
 */
class Template_Module_Instance_Handler : public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  Template_Module_Instance_Handler (void);

  /// Destructor.
  virtual ~Template_Module_Instance_Handler (void);

  virtual int handle_object_created (GAME::Object obj);

  virtual int handle_lost_child (GAME::Object obj);
};

}
}

#if defined (__GAME_INLINE__)
#include "Template_Module_Instance_Handler.inl"
#endif

#endif
