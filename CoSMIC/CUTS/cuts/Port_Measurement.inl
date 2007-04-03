// $Id$

//
// CUTS_Port_Measurement
//
CUTS_INLINE
CUTS_Port_Measurement::CUTS_Port_Measurement (void)
{

}

//
// ~CUTS_Port_Measurement
//
CUTS_INLINE
CUTS_Port_Measurement::~CUTS_Port_Measurement (void)
{

}

//
// queuing_time
//
CUTS_INLINE
const CUTS_Time_Measurement &
CUTS_Port_Measurement::queuing_time (void) const
{
  return this->queuing_time_;
}

//
// queuing_time
//
CUTS_INLINE
void CUTS_Port_Measurement::
queuing_time (const ACE_Time_Value & tv)
{
  this->queuing_time_ += tv;
}

//
// process_time
//
CUTS_INLINE
const CUTS_Time_Measurement &
CUTS_Port_Measurement::process_time (void) const
{
  return this->process_time_;
}

//
// process_time
//
CUTS_INLINE
void CUTS_Port_Measurement::
process_time (const ACE_Time_Value & timing)
{
  this->process_time_ += timing;
}

//
// worker_measurements
//
CUTS_INLINE
const CUTS_Port_Measurement::Worker_Map &
CUTS_Port_Measurement::worker_measurements (void) const
{
  return this->workers_;
}

CUTS_INLINE
CUTS_Port_Measurement::Worker_Map &
CUTS_Port_Measurement::worker_measurements (void)
{
  return this->workers_;
}

//
// record_entry
//
CUTS_INLINE
void CUTS_Port_Measurement::
record_entry (size_t reps, long worker, long opid, const ACE_Time_Value & tm)
{
  this->workers_[worker].record_operation (reps, opid, tm);
}

//
// record_exit_time
//
CUTS_INLINE
void CUTS_Port_Measurement::
record_exitpoint (size_t uid, const ACE_Time_Value & tv)
{
  this->exitpoints_[uid] += tv;
}

//
// exit_points
//
CUTS_INLINE
CUTS_Port_Measurement::Exit_Points &
CUTS_Port_Measurement::exit_points (void)
{
  return this->exitpoints_;
}

CUTS_INLINE
const CUTS_Port_Measurement::Exit_Points &
CUTS_Port_Measurement::exit_points (void) const
{
  return this->exitpoints_;
}
