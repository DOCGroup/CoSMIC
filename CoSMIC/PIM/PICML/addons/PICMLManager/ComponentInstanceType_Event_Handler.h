// -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentInstanceType_Event_Handler.h
 *
 *  $Id: ComponentInstanceType_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_COMPONENT_INSTANCE_TYPE_HANDLER_H_
#define _PICML_MI_COMPONENT_INSTANCE_TYPE_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"
#include "PICML/PICML.h"

#include <set>

namespace PICML
{
namespace MI
{

/**
 * @class ComponentInstanceType_Event_Handler
 *
 * Handles ComponentInstanceType when a relation is created.
 */
class ComponentInstanceType_Event_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Default constructor.
  ComponentInstanceType_Event_Handler (void);

  /// Destructor.
  virtual ~ComponentInstanceType_Event_Handler (void);

  virtual int handle_project_open (void);
  virtual int handle_xml_import_end (void);

  virtual int handle_object_relation (GAME::Mga::Object_in obj);
  virtual int handle_object_predestroyed (GAME::Mga::Object_in obj);

private:
  void load_defined_types (void);

  void delete_all_ports (ComponentInstance_in inst);
  void generate_port_instances (ComponentInstance_in inst, Component_in component);

  std::set <ComponentInstanceType> defined_;
};

}
}

#endif
