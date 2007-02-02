// -*- C++ -*-

//=============================================================================
/**
 * @file      Testing_Service.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TESTING_SERVICE_H_
#define _CUTS_TESTING_SERVICE_H_

#include "cuts/Component_Registry.h"

//=============================================================================
/**
 * @class CUTS_Testing_Service
 *
 * Base container class for testing service objects.
 */
//=============================================================================

class CUTS_Export CUTS_Testing_Service
{
public:
  /// Default constructor.
  CUTS_Testing_Service (void);

  /// Default destructor.
  virtual ~CUTS_Testing_Service (void);

  /**
   * Get the component registry.
   *
   * @return Pointer to the registry.
   */
  CUTS_Component_Registry & registry (void);

  /**
   * Get the component registry.
   *
   * @return Pointer to the registry.
   */
  const CUTS_Component_Registry & registry (void) const;

protected:
  /// Component registry for the testing service.
  CUTS_Component_Registry registry_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Testing_Service.inl"
#endif

#endif  // !defined _CUTS_TESTING_SERVICE_H_
