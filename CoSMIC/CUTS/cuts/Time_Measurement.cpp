// $Id$

#include "cuts/Time_Measurement.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Time_Measurement.inl"
#endif

//
// CUTS_Time_Measurement
//
CUTS_Time_Measurement::
CUTS_Time_Measurement (const CUTS_Time_Measurement &tm)
: count_ (tm.count_),
  sum_ (tm.sum_),
  max_ (tm.max_),
  min_ (tm.min_),
  history_ (tm.history_)
{

}

//
// reset
//
void CUTS_Time_Measurement::reset (void)
{
  // Set all the time values to <zero>.
  this->sum_ = ACE_Time_Value::zero;
  this->max_ = ACE_Time_Value::zero;
  this->min_ = ACE_Time_Value::zero;

  // Reset the <reset_> flag.
  this->count_ = 0;
}

//
// operator +=
//
void CUTS_Time_Measurement::operator += (const ACE_Time_Value & time_value)
{
  // If the <reset_> flag is set, then this is the time value in
  // the timing measurement.
  if (this->count_ != 0)
  {
    // Determine if this is either the <min_> of <max_> value.
    if (time_value > this->max_)
      this->max_ = time_value;
    else if (time_value < this->min_)
      this->min_ = time_value;
  }
  else
  {
    // This is the first time measurement. Therefore, set both the
    // <min_> and <max_> time values to this <time_value>.
    this->max_ = time_value;
    this->min_ = time_value;
  }

  // Accumulate the new time value.
  this->sum_ += time_value;

  // Save the <time_value> in the <history_> table.
  if (this->count_ < this->history_.size ())
    this->history_[this->count_] = time_value;

  // Increment the count.
  this->count_ ++;
}
