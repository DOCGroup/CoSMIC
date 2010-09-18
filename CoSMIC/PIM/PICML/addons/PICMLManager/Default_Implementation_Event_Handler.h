// -*- C++ -*-

//=============================================================================
/**
 *  @file       Default_Implementation_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_DEFAULT_IMPLEMENTATION_EVENT_HANDLER_H_
#define _PICML_MI_DEFAULT_IMPLEMENTATION_EVENT_HANDLER_H_

#include <map>
#include <set>
#include "game/be/Event_Handler_Impl.h"
#include "Default_Implementation_Generator.h"

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
  public GAME::Event_Handler_Impl
{
public:
  typedef Default_Implementation_Generator::meta_info_t meta_info_t;

  /// Default constructor.
  Default_Implementation_Event_Handler (void);

  /// Destructor.
  virtual ~Default_Implementation_Event_Handler (void);

  virtual int handle_xml_import_begin (void);

  virtual int handle_object_created (GAME::Object obj);

  int generate_default_implementation (const GAME::Object & obj);

  bool insert (std::string meta, const meta_info_t & info);

private:
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
