// -*- C++ -*-

//=============================================================================
/**
 * @file    Benchmark_Agent.h
 *
 * @brief   Contains the benchmark agent class.
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
#include <map>
#include <set>

// Forward decl.
class CUTS_Port_Agent;

// Forward decl.
class CUTS_Benchmark_Visitor;

/// Type defintion for a collection of CUTS_Port_Agent objects.
typedef std::set <CUTS_Port_Agent *> CUTS_Port_Agent_Set;

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
  bool register_agent (CUTS_Port_Agent * agent);

  /// Unregister a port agent.
  void unregister_agent (CUTS_Port_Agent * agent);

  /// Register an exit point w/ the agent.
  int register_endpoint (const ACE_CString & endpoint,
                         size_t & endpoint_id);

  void accept (CUTS_Benchmark_Visitor & visitor);

  const char * endpoint_name (size_t id) const;

  /// Get the collection of port agents.
  const CUTS_Port_Agent_Set & port_agents (void) const;

protected:
  /// Get the collection of port agents.
  CUTS_Port_Agent_Set & port_agents (void);

  /// Owner of this object.
  long parent_;

  /// Type definition for mapping exit point UUIDs to names.
  typedef std::map <ACE_CString, size_t> Endpoint_Map;

  /// Collection of exit points available to the agent.
  Endpoint_Map endpoints_;

  /// Set of port agents managed by this benchmark agent.
  CUTS_Port_Agent_Set port_agents_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Benchmark_Agent.inl"
#endif

#endif  // !defined _CUTS_BENCHMARK_AGENT_H_
