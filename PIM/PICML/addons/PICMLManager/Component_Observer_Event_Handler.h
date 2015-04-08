// -*- C++ -*-

//==============================================================================
/**
 *  @file        Component_Observer_Event_Handler.h
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _PICML_MI_COMPONENT_OBSERVER_EVENT_HANDLER_H_
#define _PICML_MI_COMPONENT_OBSERVER_EVENT_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"
#include "game/mga/MetaBase.h"

#include "PICML/PICML.h"

#include <map>
#include <set>

namespace PICML
{
namespace MI
{

/**
 * @class Component_Observer_Event_Handler
 *
 * Event handler that observes changes in a Component model element,
 * and then reflects those changes in a ComponentInstance model element.
 */
class Component_Observer_Event_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Default constructor.
  Component_Observer_Event_Handler (void);

  /// Destructor.
  virtual ~Component_Observer_Event_Handler (void);

  virtual int handle_project_open (void);
  virtual int handle_xml_import_end (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
  virtual int handle_object_predestroyed (GAME::Mga::Object_in obj);
  virtual int handle_object_properties (GAME::Mga::Object_in obj);

  void insert_all (ComponentInstance_in inst);
  void insert (Component_in comp, ComponentInstance_in inst);

private:
  // Help method that loads all the component instances.
  void load_instances (void);

  // Instantiate the port in the instance.
  void create_inst (GAME::Mga::FCO_in item, ComponentInstance_in inst);

  typedef std::set <ComponentInstance> ComponentInstance_Set;
  typedef std::map <Component, ComponentInstance_Set > Component_Map;

  /// Target component instance.
  Component_Map map_;
};

} // namespace PICML
} // namespace MI

#include "Component_Observer_Event_Handler.inl"

#endif  // _PICML_MI_COMPONENT_OBSERVER_EVENT_HANDLER_H_
