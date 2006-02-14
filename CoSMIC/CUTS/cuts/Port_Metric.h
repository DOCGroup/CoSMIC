#ifndef _CUTS_PORT_METRIC_H_
#define _CUTS_PORT_METRIC_H_

#include "cuts/Time_Metric.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Guard_T.h"
#include <map>
#include <string>

//=============================================================================
/**
 * @class CUTS_Port_Metric
 */
//=============================================================================

class CUTS_Export CUTS_Port_Metric
{
public:
  /// Constructor.
  CUTS_Port_Metric (void);

  /// Destructor.
  ~CUTS_Port_Metric (void);

  /// Get the transit time metrics for the port.
  CUTS_Time_Metric & transit_time (void);

  /// Get the specified endpoint time metrics.
  CUTS_Time_Metric * endpoint (const char * endpoint);

  /// Insert a new endpoint into the port metrics.
  CUTS_Time_Metric * insert_endpoint (const char * endpoint);

  /// Remove a existing endpoing from the port metrics.
  void remove_endpoint (const char * endpoint);

  /// Get the locking mechanism for external usage.
  ACE_RW_Thread_Mutex & lock (void);

private:
  typedef std::map <
    std::string, CUTS_Time_Metric *> End_Point_Metrics;

  /// Time metrics for the port.
  End_Point_Metrics endpoints_;

  /// Locking mechanism for synchronizing thread access.
  ACE_RW_Thread_Mutex lock_;

  CUTS_Time_Metric transit_time_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Port_Metric.inl"
#endif

#endif  // !defined _CUTS_PORT_METRIC_H_
