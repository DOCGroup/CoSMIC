// -*- C++ -*-

//=============================================================================
/**
 * @file      Port_Agent.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_PORT_AGENT_H_
#define _CUTS_PORT_AGENT_H_

#include "cuts/Port_Measurement_Pool.h"
#include "ace/SStringfwd.h"
#include "ace/String_Base.h"
#include <map>

// Forward decl.
class CUTS_Activation_Record;

// Forward decl.
class CUTS_Benchmark_Visitor;

//=============================================================================
/**
 * @class CUTS_Port_Agent
 */
//=============================================================================

class CUTS_Export CUTS_Port_Agent
{
public:
  /// Constructor.
  CUTS_Port_Agent (void);

  /// Destructor.
  virtual ~CUTS_Port_Agent (void);

  /// Set the name of the port agent.
  void name (const char * name);

  /// Get the name of the port agent.
  const char * name (void) const;

  /// Activate the port agent.
  virtual void activate (void);

  /// Deactivate the port agent.
  virtual void deactivate (void);

  /**
   * Update the port agent with a new activation record. This
   * method takes the information in the record and consolidates
   * it.
   *
   * @param[in]       record      Pointer to the new record.
   *
   * @todo Add support to keeping a history of the records.
   */
  void update (const CUTS_Activation_Record * record);

  /**
   * Get the current port measurement map. This will cause the
   * port agent to switch to a new map for metrics collection.
   *
   * @return      Reference to the lastest port measurement map.
   */
  CUTS_Port_Measurement_Map & port_measurements (void);

  /**
   * Get the current port measurement map. This will cause the
   * port agent to switch to a new map for metrics collection.
   *
   * @return      Reference to the lastest port measurement map.
   */
  const CUTS_Port_Measurement_Map & port_measurements (void) const;

  /**
   * Determine the active state of the port agent.
   *
   * @retval      true        The port agent is active.
   * @retval      false       The port agent is not active.
   */
  bool is_active (void) const;

  void accept (CUTS_Benchmark_Visitor & visitor);

protected:
  /// Name of the port.
  std::string name_;

  /// The active state of the port agent.
  bool active_;

  /// Collection of port measurements used by the port agent.
  mutable CUTS_Port_Measurement_Pool measurement_pool_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/PortAgent.inl"
#endif

#endif  // !defined _CUTS_PORT_AGENT_H_
