#ifndef _CUTS_PORT_METRIC_H_
#define _CUTS_PORT_METRIC_H_

#include "cuts/TimeMetric.h"

class CUTS_Export CUTS_Port_Metric
{
public:
  /// Constructor.
  CUTS_Port_Metric (void);

  /// Destructor.
  ~CUTS_Port_Metric (void);

  ///
  CUTS_Time_Metric & time_metric (void);

  ///
  const CUTS_Time_Metric & time_metric (void) const;

private:
  /// Time metrics for the port.
  CUTS_Time_Metric time_metric_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/PortMetric.inl"
#endif

#endif  // !defined _CUTS_PORT_METRIC_H_
