// $Id$

//
// CUTS_Timing_Measurement
//
CUTS_INLINE
CUTS_Time_Measurement::CUTS_Time_Measurement (size_t history_size)
: count_ (0),
  history_ (history_size)
{

}

//
// ~CUTS_Timing_Measurement
//
CUTS_INLINE
CUTS_Time_Measurement::~CUTS_Time_Measurement (void)
{

}

//
// maximum
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Time_Measurement::maximum (void) const
{
  return this->max_;
}

//
// minimum
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Time_Measurement::minimum (void) const
{
  return this->min_;
}

//
// total
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Time_Measurement::accumulation (void) const
{
  return this->sum_;
}

//
// count
//
CUTS_INLINE
size_t CUTS_Time_Measurement::count (void) const
{
  return this->count_;
}

//
// history
//
CUTS_INLINE
const CUTS_Time_Value_History &
CUTS_Time_Measurement::history (void) const
{
  return this->history_;
}
