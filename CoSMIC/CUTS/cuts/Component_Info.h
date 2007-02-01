// -*- C++ -*-

//=============================================================================
/**
 * @file      Component_Info.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COMPONENT_INFO_H_
#define _CUTS_COMPONENT_INFO_H_

#include "cuts/CUTS_export.h"
#include "ace/SString.h"

// Forward decl.
class CUTS_Host_Table_Entry;

//=============================================================================
/**
 * @struct CUTS_Component_Info
 *
 * Collection of information about a component instance. This is
 * mainly used by the Benchmark Data Collecter services that wish
 * to handle component notification events.
 */
//=============================================================================

struct CUTS_Export CUTS_Component_Info
{
  /// Default constructor.
  inline CUTS_Component_Info (void)
    : host_info_ (0) { }

  /// Unique id for the component.
  size_t uid_;

  /// The state of the component.
  int state_;

  /// Instance id for the component.
  ACE_CString inst_;

  /// Component type id.
  ACE_CString type_;

  /// Host information about the component.
  CUTS_Host_Table_Entry * host_info_;
};

#endif  // !defined _CUTS_COMPONENT_INFO_H_
