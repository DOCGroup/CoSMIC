// -*- C++ -*-

//=============================================================================
/**
 * @file      Component_Registry_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COMPONENT_REGISTRY_NODE_H_
#define _CUTS_COMPONENT_REGISTRY_NODE_H_

#include "cuts/Component_Info.h"

//=============================================================================
/**
 * @class CUTS_Component_Registry_Node
 */
//=============================================================================

class CUTS_Export CUTS_Component_Registry_Node
{
public:
  /// Default constructor.
  CUTS_Component_Registry_Node (void);

  /// Destructor.
  virtual ~CUTS_Component_Registry_Node (void);

  /// Information about the component.
  CUTS_Component_Info info_;

  /// Flag that determines if the nede should be deleted.
  bool delete_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Component_Registry_Node.inl"
#endif

#endif  // !defined _CUTS_COMPONENT_REGISTRY_NODE_H_
