// -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentInstance_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_COMPONENT_INSTANCE_HANDLER_H_
#define _PICML_MI_COMPONENT_INSTANCE_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"

namespace PICML
{
namespace MI
{
/**
 * @class ComponentInstance_Event_Handler
 *
 * Event handler for managing the functionality of a ComponentInstance
 * in PICML.
 */
class ComponentInstance_Event_Handler : public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ComponentInstance_Event_Handler (void);

  /// Destructor.
  virtual ~ComponentInstance_Event_Handler (void);

  virtual int handle_xml_import_begin (void);

  virtual int handle_xml_import_end (void);

  virtual int handle_object_created (GAME::Object obj);

private:
  /// The event handler is importing.
  bool is_importing_;
};

}
}

#endif
