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

#include "cuts/Component_Info.h"

//=============================================================================
/**
 * @class CUTS_Component_Registry_Handler
 *
 * Callback class for the CUTS_Component_Registry object. This class
 * allows objects to register with the CUTS_Component_Registry to
 * receive notification when a component's status changes.
 */
//=============================================================================

class CUTS_Export CUTS_Component_Registry_Handler
{
public:
  /// Destructor.
  virtual ~CUTS_Component_Registry_Handler (void);

  /**
   * Callback method for handling component registration
   * and unregistration.
   *
   * @param[in]       info      Information about the component.
   */
  virtual int handle_component (const CUTS_Component_Info & info);

protected:
  /// Default constructor.
  CUTS_Component_Registry_Handler (void);
};

#if defined (__CUTS_INLINE__)
#include "cuts/Component_Registry_Handler.inl"
#endif

#endif  // !defined _CUTS_COMPONENT_REGISTRY_HANDLER_H_
