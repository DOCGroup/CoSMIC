// $Id$

//
// CUTS_Timing_Measurement
//
CUTS_INLINE
CUTS_Time_Measurement::CUTS_Time_Measurement (void)
: count_ (0)
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
ACE_Time_Value & CUTS_Time_Measurement::maximum (void)
{
  return this->max_;
}

CUTS_INLINE
const ACE_Time_Value & CUTS_Time_Measurement::maximum (void) const
{
  return this->max_;
}

//
// minimum
//
CUTS_INLINE
ACE_Time_Value & CUTS_Time_Measurement::minimum (void)
{
  return this->min_;
}

CUTS_INLINE
const ACE_Time_Value & CUTS_Time_Measurement::minimum (void) const
{
  return this->min_;
}

//
// total
//
CUTS_INLINE
ACE_Time_Value & CUTS_Time_Measurement::total (void)
{
  return this->total_;
}

CUTS_INLINE
const ACE_Time_Value & CUTS_Time_Measurement::total (void) const
{
  return this->total_;
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
// count
//
CUTS_INLINE
void CUTS_Time_Measurement::count (size_t n)
{
  this->count_ = n;
}
