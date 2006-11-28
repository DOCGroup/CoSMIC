// $Id$

//
// average_time
//
CUTS_INLINE
long CUTS_Time_Metric::total_time (void) const
{
  return this->total_time_.msec ();
}

//
// best_time
//
CUTS_INLINE
long CUTS_Time_Metric::best_time (void) const
{
  return this->best_time_.msec ();
}

//
// worse_time
//
CUTS_INLINE
long CUTS_Time_Metric::worse_time (void) const
{
  return this->worse_time_.msec ();
}

//
// count
//
CUTS_INLINE
long CUTS_Time_Metric::count (void) const
{
  return this->count_;
}

//
// timestamp
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Time_Metric::timestamp (void) const
{
  return this->timestamp_;
}

//
// timestamp
//
CUTS_INLINE
void CUTS_Time_Metric::timestamp (const ACE_Time_Value & timestamp)
{
  this->timestamp_ = timestamp;
}

//
// avg_time
//
CUTS_INLINE
double CUTS_Time_Metric::avg_time (void) const
{
  return this->count_ != 0 ? this->total_time_.msec () / this->count_ : 0.0;
}
