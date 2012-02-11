// -*- C++ -*-

//=============================================================================
/**
 * @file      Package_Type_Handler.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_PACKAGE_TYPE_HANDLER_H_
#define _PICML_MI_PACKAGE_TYPE_HANDLER_H_

#include <map>
#include "game/mga/component/Event_Handler_Impl.h"
#include "game/mga/FCO.h"

namespace PICML
{
namespace MI
{
/**
 * @class Package_Type_Handler
 */
class Package_Type_Handler :
  public GAME::Mga::Dynamic_Event_Handler_Impl
{
public:
  /// Default constructor.
  Package_Type_Handler (void);

  /// Destructor.
  virtual ~Package_Type_Handler (void);

  virtual int handle_object_relation (GAME::Mga::Object_in obj);

private:
  typedef std::map <GAME::Mga::FCO, GAME::Mga::Reference> template_map_t;

  bool select_template_parameter (GAME::Mga::Model_in parent,
                                  const GAME::Mga::FCO_in fco,
                                  template_map_t & mapping);

  bool select_type_parameter (GAME::Mga::Model_in parent,
                              const GAME::Mga::FCO_in fco,
                              template_map_t & mapping);

  bool select_name_parameter (GAME::Mga::Model_in parent,
                              const GAME::Mga::FCO_in fco,
                              template_map_t & mapping);

  bool select_collection_parameter (GAME::Mga::Model_in parent,
                                    const GAME::Mga::FCO_in fco,
                                    template_map_t & mapping);

  void create_template_value_parameter (GAME::Mga::Model parent,
                                        const GAME::Mga::FCO_in param,
                                        const GAME::Mga::FCO_in value,
                                        template_map_t & mapping);

  void instantiate_template_package (const GAME::Mga::Model_in template_package,
                                     GAME::Mga::Model_in tpi,
                                     const template_map_t & mapping);

  void substitute_template_parameters (const GAME::Mga::Model_in tpi,
                                       const template_map_t & mapping);

  void substitute_template_parameter_reference (GAME::Mga::Reference_in ref,
                                                const template_map_t & mapping);

  void finalize_template_package_inst (GAME::Mga::Model_in tpi);
};

}
}

#if defined (__GAME_INLINE__)
#include "Package_Type_Handler.inl"
#endif

#endif
