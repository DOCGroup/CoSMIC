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
#include "ace/RW_Thread_Mutex.h"
#include "ace/SString.h"

// Forward decl.
struct CUTS_Component_Type;

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
  /// Defines the different states of a component.
  enum Component_State
  {
    /// The component is in the activate state.
    STATE_ACTIVATE    = 0,

    /// The component is in the passivate state.
    STATE_PASSIVATE   = 1
  };

  /// Default constructor.
  inline CUTS_Component_Info (size_t uid)
    : uid_ (uid), host_info_ (0) { }

  /// Unique id for the component.
  const size_t uid_;

  /// The state of the component.
  Component_State state_;

  /// Instance id for the component.
  ACE_CString inst_;

  /// Type information about the component.
  const CUTS_Component_Type * type_;

  /// Host information about the component.
  const CUTS_Host_Table_Entry * host_info_;
};

#endif  // !defined _CUTS_COMPONENT_INFO_H_
