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

#include "cuts/Host_Table.h"
#include "ace/Auto_Ptr.h"

// Forward decl.
class CUTS_Component_Registry;

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
  CUTS_Testing_Service (CUTS_Component_Registry * registry);

  /// Default destructor.
  virtual ~CUTS_Testing_Service (void);

  /**
   * Get the host table for the testing service.
   *
   * @return Read-only reference to the host table.
   */
  const CUTS_Host_Table & host_table (void) const;

  /**
   * Get the host table for the testing service.
   *
   * @return Reference to the host table.
   */
  CUTS_Host_Table & host_table (void);

  /**
   * Get the component registry.
   *
   * @return Pointer to the registry.
   */
  virtual CUTS_Component_Registry * registry (void) const;

protected:
  /// The mapping of IP-addresses to hostnames.
  CUTS_Host_Table host_table_;

  /// Component registry for the testing service.
  ACE_Auto_Ptr <CUTS_Component_Registry> registry_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Testing_Service.inl"
#endif

#endif  // !defined _CUTS_TESTING_SERVICE_H_
