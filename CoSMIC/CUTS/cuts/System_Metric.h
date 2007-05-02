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

#include "cuts/CUTS_export.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/Time_Value.h"

// Forward decl.
class CUTS_Component_Metric;

// Forward decl.
class CUTS_Metrics_Visitor;

// Type definition for mapping component's to the metrics.
typedef
  ACE_Hash_Map_Manager <
  long, CUTS_Component_Metric *, ACE_Null_Mutex>
  CUTS_Component_Metric_Map;

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

  /**
   * Get the metrics for a component. If the component does not exist,
   * then the caller has the option of creating a metric for the component.
   *
   * @param[in]     regid         Registration id for the component.
   * @param[out]    metric        Metric container for the component.
   * @param[in]     auto_create   Auto creation flag for the metric.
   * @retval        -1            Failed to get component's metrics.
   * @retval        else          Successfully got component's metrics.
   */
  int component_metric (long regid,
                        CUTS_Component_Metric * & metric,
                        bool auto_create = true);

  /**
   * Insert metrics for a component. If the component does not exist,
   * then the caller has the option of creating a metric for the component.
   *
   * @param[in]     regid         Registration id for the component.
   * @param[out]    metric        Metric container for the component.
   * @retval        -1            Failed to get component's metrics.
   * @retval        else          Successfully got component's metrics.
   */
  int insert_component_metric (long regid,
                               CUTS_Component_Metric * & metric);

  /**
   * Remove a component's metrics from the system metrics. Once the
   * metrics have been removed, all existing for that component is
   * lost.
   *
   * @param[in]     regid       Registration id for the component.
   */
  int remove_component_metric (long regid);


  /**
   * Get the metrics of all the component in the system.
   *
   * @return      Reference to a component metric mapping.
   */
  const CUTS_Component_Metric_Map & component_metrics (void) const;

  /**
   * Accept the visitor.
   *
   * @param[in]     visitor     Reference to the visitor.
   */
  void accept (CUTS_Metrics_Visitor & visitor) const;

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

  /// Component metrics for the system.
  CUTS_Component_Metric_Map component_metrics_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/System_Metric.inl"
#endif

#endif  // !defined _CUTS_SYSTEM_METRIC_H_
