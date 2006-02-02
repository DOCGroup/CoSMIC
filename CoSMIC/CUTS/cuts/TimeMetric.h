#ifndef _CUTS_TIME_METRIC_H_
#define _CUTS_TIME_METRIC_H_

#include "cuts/config.h"
#include "ace/Time_Value.h"

class CUTS_Time_Metric
{
public:
  CUTS_Time_Metric (void);

  ~CUTS_Time_Metric (void);

  long metrics (void) const;
  long best_time (void) const;
  long worse_time (void) const;
  long average_time (void) const;

  void operator () (size_t n, long avg, long best, long worse);

private:
  size_t metrics_;

  ACE_Time_Value best_time_;

  ACE_Time_Value worse_time_;

  ACE_Time_Value average_time_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/TimeMetric.inl"
#endif

#endif  // !defined _CUTS_TIME_METRIC_H_
