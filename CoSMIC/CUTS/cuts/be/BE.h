#ifndef _CUTS_BE_H_
#define _CUTS_BE_H_

#include "BE_export.h"

// Forward decl.
class CUTS_BE_Manager_Factory;

#define CUTS_BE_CREATE_MANAGER_FACTORY_FUNC \
  CUTS_BE_create_manager_factory

#define CUTS_BE_CREATE_MANAGER_FACTORY_STR \
  "CUTS_BE_create_manager_factory"

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BE_CREATE_MANAGER_FACTORY_DECLARE(export_macro) \
  extern "C" export_macro CUTS_BE_Manager_Factory * \
  CUTS_BE_CREATE_MANAGER_FACTORY_FUNC (void)

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BE_CREATE_MANAGER_FACTORY_IMPLEMENT(factory_type) \
  CUTS_BE_Manager_Factory * \
  CUTS_BE_CREATE_MANAGER_FACTORY_FUNC (void) \
  { \
    return new factory_type (); \
  }

#endif  // !defined _CUTS_BE_H_
