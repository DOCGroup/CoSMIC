
//
// average_time
//
CUTS_INLINE
long CUTS_Time_Metric::average_time (void) const
{
  return this->average_time_.msec ();
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
