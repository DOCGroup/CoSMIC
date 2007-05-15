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

#include "cuts/Activation_Record_Log.h"
#include "cuts/Port_Measurement_Map.h"
#include "ace/SString.h"
#include "ace/Containers_T.h"

//=============================================================================
/**
 * @class CUTS_Port_Agent
 *
 * Monitoring object for ports.
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
  void name (const ACE_CString & name);

  /// Get the name of the port agent.
  const ACE_CString & name (void) const;

  /// Activate the port agent.
  virtual void activate (void);

  /// Deactivate the port agent.
  virtual void deactivate (void);

  /**
   * Get the current port measurement map. This will cause the
   * port agent to switch to a new map for metrics collection.
   *
   * @return      Reference to the lastest port measurement map.
   */
  CUTS_Port_Measurement_Map & sender_map (void);

  /// @overload
  const CUTS_Port_Measurement_Map & sender_map (void) const;

  /**
   * Determine the active state of the port agent.
   *
   * @retval      true        The port agent is active.
   * @retval      false       The port agent is not active.
   */
  bool is_active (void) const;

  /**
   * Get a free record from the port agent. The gets the next free
   * record by checking the free list. If the free list is not allowed
   * to grow on-demand, then the port agent will return the default
   * record for the calling thread.
   *
   * @return      Pointer to a free record.
   */
  CUTS_Activation_Record * record_alloc (void);

  /**
   * Free a record allocated by the port agent. The port agent will
   * store the record in the history, if the feature is enabled. It
   * also consolidates the information for a overview of the ports
   * performance metrics.
   *
   * @param[in]       record      Pointer to the old record.
   */
  void record_free (CUTS_Activation_Record * record);

  /// Reset the port agent. This will reset all the history of the
  /// port agent.
  void reset (void);

  CUTS_Activation_Record_Log & log (void);
  const CUTS_Activation_Record_Log & log (void) const;

private:
  void update (const CUTS_Activation_Record * record);

  /// Name of the port.
  ACE_CString name_;

  /// The active state of the port agent.
  bool active_;

  /// Collection of port measurements used by the port agent.
  CUTS_Port_Measurement_Map sender_map_;

  /// Default activation record.
  CUTS_Activation_Record fallback_record_;

  /// Log of activation records.
  CUTS_Activation_Record_Log log_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Port_Agent.inl"
#endif

#endif  // !defined _CUTS_PORT_AGENT_H_
