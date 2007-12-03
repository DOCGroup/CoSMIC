// $Id$

#include "cuts/Time_Measurement.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Time_Measurement.inl"
#endif

#include "cuts/Metrics_Visitor.h"
#include "ace/Log_Msg.h"

//
// CUTS_Time_Measurement
//
CUTS_Time_Measurement::
CUTS_Time_Measurement (const CUTS_Time_Measurement &tm)
  : CUTS_Timestamp_Metric (tm),
    count_ (tm.count_),
    total_ (tm.total_),
    max_ (tm.max_),
    min_ (tm.min_)
{

}

//
// reset
//
void CUTS_Time_Measurement::reset (void)
{
  // Set all the time values to <zero>.
  this->total_ = ACE_Time_Value::zero;
  this->max_ = ACE_Time_Value::zero;
  this->min_ = ACE_Time_Value::zero;

  // Reset the <reset_> flag.
  this->count_ = 0;
}

//
// operator +=
//
const CUTS_Time_Measurement &
CUTS_Time_Measurement::operator += (const ACE_Time_Value & timing)
{
  if (this->count_ != 0)
  {
    // Determine if this is either the <min_> of <max_> value.
    if (timing > this->max_)
      this->max_ = timing;
    else if (timing < this->min_)
      this->min_ = timing;
  }
  else
  {
    // This is the first time measurement.
    this->max_ = timing;
    this->min_ = timing;
  }

  // Accumulate the new time value.
  this->total_ += timing;
  ++ this->count_;

  return *this;
}

//
// operator +=
//
const CUTS_Time_Measurement &
CUTS_Time_Measurement::operator += (const CUTS_Time_Measurement & tm)
{
  if (this->count_ != 0)
  {
    // Determine if this is either the <min_> of <max_> value.
    if (tm.max_ > this->max_)
      this->max_ = tm.max_;
    else if (tm.min_ < this->min_)
      this->min_ = tm.min_;
  }
  else
  {
    // This is the first time measurement.
    this->max_ = tm.max_;
    this->min_ = tm.min_;
  }

  // Accumulate the new time value.
  this->total_ += tm.total_;
  this->count_ += tm.count_;

  return *this;
}

//
// operator =
//
const CUTS_Time_Measurement &
CUTS_Time_Measurement::operator = (const CUTS_Time_Measurement & tm)
{
  this->max_ = tm.max_;
  this->min_ = tm.min_;
  this->total_ = tm.total_;
  this->count_ = tm.count_;

  return *this;
}

//
// accept
//
void CUTS_Time_Measurement::
accept (CUTS_Metrics_Visitor & visitor) const
{
  visitor.visit_time_measurement (*this);
}
