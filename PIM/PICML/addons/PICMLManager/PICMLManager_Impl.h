/* -*- C++ -*- */

//=============================================================================
/**
 * @file      PICMLManager_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_IMPL_H_
#define _PICML_MANAGER_IMPL_H_

#include "game/mga/component/Event_Handler.h"
#include "UUID_Event_Handler.h"
#include "Component_Observer_Event_Handler.h"

/**
 * @class PICMLManager_Impl
 *
 * Main event handler implementation for the PICML model intelligence.
 */
class PICMLManager_Impl :
  public GAME::Mga::Top_Level_Event_Handler
{
public:
  /// Constructor.
  PICMLManager_Impl (void);

  /// Destructor.
  virtual ~PICMLManager_Impl (void);

  virtual int initialize (GAME::Mga::Project project);

private:
  /// Collection of all the UUIDs for this project.
  PICML::MI::UUID_Event_Handler::UUID_MANAGER all_uuids_;
  PICML::MI::Component_Observer_Event_Handler component_obs_;
};

#endif // _PICML_MANAGER_IMPL_H_
