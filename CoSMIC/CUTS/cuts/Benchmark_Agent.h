// -*- C++ -*-

//=============================================================================
/**
 * @file    Benchmark_Agent.h
 *
 * $Id$
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_BENCHMARK_AGENT_H_
#define _CUTS_BENCHMARK_AGENT_H_

#include "cuts/CUTS_export.h"
#include "ace/SString.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

// Forward decl.
class CUTS_Port_Agent;

/// Type definition for a collection of CUTS_Port_Agent objects.
typedef
  ACE_Hash_Map_Manager <
  void *, size_t, ACE_Null_Mutex>
  CUTS_Port_Agent_Set;

/// Type definition for a collection of endpoint names.
typedef
  ACE_Hash_Map_Manager <
  ACE_CString, size_t, ACE_Null_Mutex>
  CUTS_Endpoint_Map;

//=============================================================================
/**
 * @class CUTS_Benchmark_Agent
 *
 * @brief Class responsible for collecting all performance data.
 */
//=============================================================================

class CUTS_Export CUTS_Benchmark_Agent
{
public:
  /// Constructor.
  CUTS_Benchmark_Agent (void);

  /// Destructor.
  virtual ~CUTS_Benchmark_Agent (void);

  /// Get the parent ID of the agent.
  long parent (void) const;

  /// Set the parent ID of the agent.
  void parent (long parent);

  /// Register a port agent.
  int register_agent (CUTS_Port_Agent * agent, size_t agent_id);

  /// Register an exit point w/ the agent.
  int register_endpoint (const ACE_CString & endpoint,
                         size_t endpoint_id);

  /**
   * Get the collection of port agents.
   *
   * @return      Reference to the registered port agents.
   */
  const CUTS_Port_Agent_Set & port_agents (void) const;

  /// @overload
  CUTS_Port_Agent_Set & port_agents (void);

  /**
   * Get the collection of registered endpoints.
   *
   * @return      Reference to the registered endpoints.
   */
  const CUTS_Endpoint_Map & endpoints (void) const;

  /// @overload
  CUTS_Endpoint_Map & endpoints (void);

protected:
  /// Owner of this object.
  long parent_;

  /// Collection of exit points available to the agent.
  CUTS_Endpoint_Map endpoints_;

  /// Set of port agents managed by this benchmark agent.
  CUTS_Port_Agent_Set port_agents_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Benchmark_Agent.inl"
#endif

#endif  // !defined _CUTS_BENCHMARK_AGENT_H_
