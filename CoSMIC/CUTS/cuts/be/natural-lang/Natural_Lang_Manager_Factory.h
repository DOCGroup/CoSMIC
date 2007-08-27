// -*- C++ -*-

//=============================================================================
/**
 * @file        Natural_Language_Manager_Factory.h
 *
 * Defines the manager's factory for the natural language backend
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_NATURAL_LANG_MANAGER_FACTORY_H_
#define _CUTS_BE_NATURAL_LANG_MANAGER_FACTORY_H_

#include "Natural_Lang_export.h"
#include "cuts/be/BE_Manager_Factory.h"

//=============================================================================
/**
 * @class CUTS_BE_Natural_Lang_Manager_Factory
 *
 * Factory that creates the CUTS_BE_Natural_Lang_Manager object.
 */
//=============================================================================

class CUTS_BE_Natural_Lang_Manager_Factory :
  public CUTS_BE_Manager_Factory
{
public:
  /// Default constructor.
  CUTS_BE_Natural_Lang_Manager_Factory (void);

  /// Destructor.
  virtual ~CUTS_BE_Natural_Lang_Manager_Factory (void);

  // Create the manager.
  CUTS_BE_Manager * create_manager (void);

  // Get the name of the manager.
  const char * name (void) const;

  // Get the description of the manager.
  const char * description (void) const;
};

CUTS_BE_CREATE_MANAGER_FACTORY_DECLARE (CUTS_BE_NATURAL_LANG_Export);

#endif  // !defined _CUTS_BE_NATURAL_LANG_MANAGER_FACTORY_H_
