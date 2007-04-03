// $Id$

#include "cuts/Time_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Time_Metric.inl"
#endif

#include "cuts/System_Metrics_Visitor.h"
#include "ace/Guard_T.h"

//
// CUTS_Time_Metric
//
CUTS_Time_Metric::CUTS_Time_Metric (void)
: count_ (0),
  best_time_ (ACE_Time_Value::zero),
  worse_time_ (ACE_Time_Value::zero),
  total_time_ (ACE_Time_Value::zero)
{

}

//
// CUTS_Time_Metric
//
CUTS_Time_Metric::CUTS_Time_Metric (const CUTS_Time_Metric & tm)
: count_ (tm.count_),
  best_time_ (tm.best_time_),
  worse_time_ (tm.worse_time_),
  total_time_ (tm.total_time_)
{

}

//
// ~CUTS_Time_Metric
//
CUTS_Time_Metric::~CUTS_Time_Metric (void)
{

}

//
// operator =
//
const CUTS_Time_Metric &
CUTS_Time_Metric::operator = (const CUTS_Time_Metric & tm)
{
  this->count_ = tm.count_;
  this->total_time_ = tm.total_time_;
  this->best_time_ = tm.best_time_;
  this->worse_time_ = tm.worse_time_;

  return *this;
}

//
// update
//
void CUTS_Time_Metric::update (size_t count,
                               long total,
                               long best,
                               long worse)
{
  this->count_ = count;
  this->total_time_.msec (total);
  this->best_time_.msec (best);
  this->worse_time_.msec (worse);
}

//
// reset
//
void CUTS_Time_Metric::reset (void)
{
  this->count_ = 0;
  this->best_time_ = ACE_Time_Value::zero;
  this->worse_time_ = ACE_Time_Value::zero;
  this->total_time_ = ACE_Time_Value::zero;
}

//
// operator +
//
const CUTS_Time_Metric operator + (const CUTS_Time_Metric & lhs,
                                   const CUTS_Time_Metric & rhs)
{
  CUTS_Time_Metric time_metric (lhs);
  time_metric += rhs;

  return time_metric;
}

//
// operator +=
//
const CUTS_Time_Metric &
CUTS_Time_Metric::operator += (const CUTS_Time_Metric & rhs)
{
  // We need to sum the source with this object.
  this->count_ += rhs.count_;
  this->total_time_ += rhs.total_time_;

  // Store the best time of the two.
  if (rhs.best_time_ > this->best_time_)
    this->best_time_ = rhs.best_time_;

  // Store the worst time of the two.
  if (rhs.worse_time_ > this->worse_time_)
    this->worse_time_ = rhs.worse_time_;

  return *this;
}

//
// accept
//
void CUTS_Time_Metric::
accept (CUTS_System_Metrics_Visitor & visitor) const
{
  visitor.visit_time_metrics (*this);
}
