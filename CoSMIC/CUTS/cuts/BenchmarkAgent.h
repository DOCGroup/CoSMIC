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
#include <map>
#include <set>
#include <string>

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
  const std::string & parent (void) const;

  /// Set the parent ID of the agent.
  void parent (const std::string &parent);

  /// Register an exit point w/ the agent.
  bool register_exit_point (const std::string & uuid,
                            const std::string & name);

  /// Unregister an exit point w/ the agent.
  void unregister_exit_point (const std::string & uuid);

protected:
  /// Type definition for the collection of port agents.
  typedef std::set <CUTS_Port_Agent *> Port_Agents;

  /// Get the collection of port agents.
  Port_Agents & port_agents (void);

  /// Type definition for mapping exit point UUIDs to names.
  typedef std::map <std::string, std::string> Exit_Points;

  /// Collection of exit points available to the agent.
  Exit_Points exit_points_;

private:
  /// Owner of this object.
  std::string parent_;

  /// Set of port agents managed by this benchmark agent.
  Port_Agents port_agents_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/BenchmarkAgent.inl"
#endif

#endif  // !defined _CUTS_BENCHMARK_AGENT_H_
