// $Id$

//
// lock
//
CUTS_INLINE
ACE_RW_Thread_Mutex & CUTS_Port_Metric::lock (void)
{
  return this->lock_;
}

//
// transit_time
//
CUTS_INLINE
CUTS_Time_Metric & CUTS_Port_Metric::transit_time (void)
{
  return this->transit_time_;
}
