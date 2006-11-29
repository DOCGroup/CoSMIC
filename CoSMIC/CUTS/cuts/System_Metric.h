// -*- C++ -*-

//=============================================================================
/**
 * @file      System_Metric.h
 *
 * @brief     Defines the CUTS_System_Metric object
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_SYSTEM_METRIC_H_
#define _CUTS_SYSTEM_METRIC_H_

#include "cuts/config.h"
#include "cuts/CUTS_export.h"
#include "ace/Time_Value.h"
#include "ace/RW_Thread_Mutex.h"

#include <map>
#include <string>

// Forward decl.
class CUTS_Component_Metric;

// Forward decl.
class CUTS_System_Metrics_Visitor;

// Typedef.
typedef std::map <long, CUTS_Component_Metric *> CUTS_Component_Metric_Map;

//=============================================================================
/**
 * @class CUTS_System_Metric
 */
//=============================================================================

class CUTS_Export CUTS_System_Metric
{
public:
  /// Constructor.
  CUTS_System_Metric (void);

  /// Destructor.
  ~CUTS_System_Metric (void);

  CUTS_Component_Metric * insert_component (long regid);

  void remove_component (long regid);

  CUTS_Component_Metric * component_metrics (long regid);

  /**
   * Get the metrics of all the component in the system.
   *
   * @return      Reference to a component metric mapping.
   */
  const CUTS_Component_Metric_Map & component_metrics (void) const;

  /**
   * Get the locking mechanism for the object.
   *
   * @return      Reference to the lock for the object.
   */
  ACE_RW_Thread_Mutex & lock (void);

  /**
   * Accept the visitor.
   *
   * @param[in]     visitor     Reference to the visitor.
   */
  void accept (CUTS_System_Metrics_Visitor & visitor);

  /***
   * Initialize the timestamp stored in the metrics database. This
   * is necessary if you want to calculate the duration between
   * collection times.
   *
   * @param[in]     timestamp       Pointer to the timestamp.
   */
  void init_timestamp (const ACE_Time_Value * timestamp = 0);

  /**
   * This method update the timestamp. If the \a timestamp is
   * 0, then the system will get the current time of day. If
   * \a timestamp is not zero, then the metrics will store the
   * specified value.
   *
   * @param[in]     timestamp       Pointer to the timestamp.
   */
  void set_timestamp (const ACE_Time_Value * timestamp = 0);

  /**
   * Get a reference to the current timestamp.
   *
   * @return        Reference to the current timestamp.
   */
  const ACE_Time_Value & get_timestamp (void) const;

  /**
   * Get the elapsed time for the current collection.
   *
   * @return        Reference to the elapsed time.
   */
  const ACE_Time_Value & get_duration (void) const;

private:
  /// Helper method for setting the timestamp accordingly.
  void timestamp_i (const ACE_Time_Value * timestamp = 0);

  /// The current timestamp of the metrics.
  ACE_Time_Value timestamp_;

  /// The duration between metric collections.
  ACE_Time_Value duration_;

  /// Locking mechanism for the object.
  ACE_RW_Thread_Mutex lock_;

  /// Component metrics for the system.
  CUTS_Component_Metric_Map component_metrics_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/System_Metric.inl"
#endif

#endif  // !defined _CUTS_SYSTEM_METRIC_H_
