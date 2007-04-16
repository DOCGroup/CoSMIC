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
  min_ (tm.min_)
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
void CUTS_Time_Measurement::operator += (const ACE_Time_Value & timing)
{
  if (this->count_ ++ != 0)
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
  this->sum_ += timing;
}
