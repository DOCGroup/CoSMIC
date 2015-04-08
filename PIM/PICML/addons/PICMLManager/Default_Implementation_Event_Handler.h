// -*- C++ -*-

//=============================================================================
/**
 *  @file       Default_Implementation_Event_Handler.h
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_DEFAULT_IMPLEMENTATION_EVENT_HANDLER_H_
#define _PICML_MI_DEFAULT_IMPLEMENTATION_EVENT_HANDLER_H_

#include <map>
#include <set>
#include "game/mga/component/Object_Event_Handler.h"
#include "Default_Implementation_Generator.h"
#include "Implementation_Configuration.h"

#include "PIM/PICML/ext/PICML/ComponentParadigmSheets/ComponentType/Component.h"

namespace PICML
{
namespace MI
{
/**
 * @class Default_Implementation_Event_Handler
 *
 * Event handler that is responsible for generating default implementation
 * for a given object.
 */
class Default_Implementation_Event_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  typedef Default_Implementation_Generator::meta_info_t meta_info_t;

  /// Default constructor.
  Default_Implementation_Event_Handler (void);

  /// Destructor.
  virtual ~Default_Implementation_Event_Handler (void);

  virtual int handle_xml_import_begin (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);

  /**
   * Generate the default implemenation for a component type. This will produce
   * the component implementation model elements, and the component implementation
   * artifacts for the component type.
   *
   * @param[in]         type          The component type
   */
  int generate_default_implementation (PICML::Component_in type);

  bool insert (std::string meta, const meta_info_t & info);

private:
  Implementation_Configuration config_;

  typedef
    std::map <std::string,
              Default_Implementation_Generator::meta_info_t>
              map_t;

  map_t meta_info_;

  /// Imported objects that may need implementations.
  bool generate_on_import_;
};

}
}

#endif  // !defined _PICML_MI_DEFAULT_IMPLEMENTATION_EVENT_HANDLER_H_
