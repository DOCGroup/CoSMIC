// -*- C++ -*-

//=============================================================================
/**
 * @file    BenchmarkAgent.h
 *
 * $Id$
 *
 * This file contains the BenchmarAgent class. Its requirement is to
 * collected data on a given node and send it to the BenchmarkDataCollector.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_BENCHMARK_AGENT_H_
#define _CUTS_BENCHMARK_AGENT_H_

#include "cuts/config.h"
#include <set>

// forward declarations
class CUTS_Port_Agent;

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

  /// Register a port agent.
  bool register_port_agent (CUTS_Port_Agent * agent);

  /// Unregister a port agent.
  void unregister_port_agent (CUTS_Port_Agent * agent);

  /// Get the parent ID of the agent.
  long parent (void) const;

  /// Set the parent ID of the agent.
  void parent (long parent);

protected:
  /// Type definition for the collection of port agents.
  typedef std::set <CUTS_Port_Agent *> Port_Agents;

  /// Get the collection of port agents.
  Port_Agents & port_agents (void);

private:
  /// Owner of this object.
  long parent_;

  /// Set of port agents managed by this benchmark agent.
  Port_Agents port_agents_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/BenchmarkAgent.inl"
#endif

#endif  // !defined _CUTS_BENCHMARK_AGENT_H_
