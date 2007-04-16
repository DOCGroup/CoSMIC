#ifndef _CUTS_PORT_METRIC_H_
#define _CUTS_PORT_METRIC_H_

#include "cuts/Time_Metric.h"
#include "cuts/Activation_Record_Log.h"

#include "ace/RW_Thread_Mutex.h"
#include "ace/Guard_T.h"
#include <map>
#include <string>
#include <ostream>

class CUTS_System_Metrics_Visitor;

typedef std::map <
  std::string, CUTS_Time_Metric *> CUTS_Endpoint_Metric_Map;

typedef std::map <long, ACE_CString> CUTS_Endpoint_Name_Map;

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

  /// Get the transit time metrics for the port.
  const CUTS_Time_Metric & transit_time (void) const;

  /// Get the specified endpoint time metrics.
  CUTS_Time_Metric * endpoint (const char * endpoint);

  /// Insert a new endpoint into the port metrics.
  CUTS_Time_Metric * insert_endpoint (const char * endpoint);

  /// Remove a existing endpoing from the port metrics.
  void remove_endpoint (const char * endpoint);

  /// Get the locking mechanism for external usage.
  ACE_RW_Thread_Mutex & lock (void);

  const CUTS_Endpoint_Metric_Map & endpoints (void) const;

  void accept (CUTS_System_Metrics_Visitor & visitor) const;

  const ACE_Time_Value & timestamp (void) const;

  void timestamp (const ACE_Time_Value & timestamp);

  const CUTS_Port_Metric & operator += (const CUTS_Port_Metric & metric);

  const CUTS_Activation_Record_Log & log (void) const;

  CUTS_Activation_Record_Log & log (void);

  void endpoint_name (long id, const ACE_CString & name);

  ACE_CString endpoint_name (long id) const;

private:
  /// Time metrics for the port.
  CUTS_Endpoint_Metric_Map endpoints_;

  /// Locking mechanism for synchronizing thread access.
  ACE_RW_Thread_Mutex lock_;

  CUTS_Time_Metric transit_time_;

  ACE_Time_Value timestamp_;

  CUTS_Activation_Record_Log log_;

  CUTS_Endpoint_Name_Map name_map_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Port_Metric.inl"
#endif

#endif  // !defined _CUTS_PORT_METRIC_H_
