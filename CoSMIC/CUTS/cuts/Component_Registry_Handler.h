// -*- C++ -*-

//=============================================================================
/**
 * @file      Component_Registry_Handler.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COMPONENT_REGISTRY_HANDLER_H_
#define _CUTS_COMPONENT_REGISTRY_HANDLER_H_

#include "cuts/CUTS_export.h"

// Forward decl.
struct CUTS_Component_Info;

//=============================================================================
/**
 * @class CUTS_Component_Registry_Handler
 */
//=============================================================================

class CUTS_Export CUTS_Component_Registry_Handler
{
public:
  /**
   * Callback method for handling component registration
   * and unregistration.
   *
   * @param[in]       info      Information about the component.
   */
  virtual int handle_component (const CUTS_Component_Info & info) = 0;
};

#endif  // !defined _CUTS_COMPONENT_REGISTRY_HANDLER_H_
