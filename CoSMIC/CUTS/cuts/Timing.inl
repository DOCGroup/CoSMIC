// $Id$

//=============================================================================
/*
 * CUTS_Timing_Measurement
 */
//=============================================================================

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
// average
//
CUTS_INLINE
size_t CUTS_Time_Measurement::count (void) const
{
  return this->count_;
}

//=============================================================================
/*
 * CUTS_Timer
 */
//=============================================================================

CUTS_INLINE
ACE_Time_Value CUTS_Timer::elapsed (void) const
{
  // The checkpoint is the current time minus the stored time
  // when the timer was created.
  return ACE_OS::gettimeofday () -= this->time_;
}

CUTS_INLINE
const ACE_Time_Value & CUTS_Timer::time (void) const
{
  return this->time_;
}
