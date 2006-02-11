#include "cuts/TimeMetric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/TimeMetric.inl"
#endif

//
// CUTS_Time_Metric
//
CUTS_Time_Metric::CUTS_Time_Metric (void)
{

}

//
// ~CUTS_Time_Metric
//
CUTS_Time_Metric::~CUTS_Time_Metric (void)
{

}

//
// operator ()
//
void CUTS_Time_Metric::operator () (size_t n,
                                    long avg,
                                    long best,
                                    long worse)
{
  this->metrics_ = n;
  this->average_time_.msec (avg);
  this->best_time_.msec (best);
  this->worse_time_.msec (worse);
}
