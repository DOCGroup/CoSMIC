// -*- C++ -*-

//=============================================================================
/**
 * @file      Testing_Service.h
 *
 * $Id: Testing_Service.h,v 1.1.2.1 2006/06/16 00:38:44 hillj Exp $
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TESTING_SERVICE_H_
#define _CUTS_TESTING_SERVICE_H_

#include "cuts/config.h"
#include "cuts/Host_Table.h"
#include "ace/Auto_Ptr.h"

// Forward decl.
class CUTS_Component_Registry;

//=============================================================================
/**
 * @class CUTS_Testing_Service
 *
 * @brief Base container class for testing service objects.
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
   * Get the host table for the testing service. We do not
   * allow modification of the host table outside of this class.
   * Only subclasses are allowed to modify the table.
   *
   * @return Read-only reference to the host table.
   */
  const CUTS_Host_Table & host_table (void) const;

  /**
   * Set the implemenation of the component registry. The client
   * is responsible for deleting the registrt
   *
   * @param[in]     registry      Pointer to the registry.
   */
  void registry (CUTS_Component_Registry * registry);

  /**
   * Get the component registry.
   *
   * @return Read-only pointer to the registry.
   */
  const CUTS_Component_Registry * registry (void) const;

  /**
   * Get the component registry.
   *
   * @return Pointer to the registry.
   */
  CUTS_Component_Registry * registry (void);

private:
  /// The mapping of IP-addresses to hostnames.
  CUTS_Host_Table host_table_;

  /// Component registry for the testing service.
  ACE_Auto_Ptr <CUTS_Component_Registry> registry_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Testing_Service.inl"
#endif

#endif  // !defined _CUTS_TESTING_SERVICE_H_
