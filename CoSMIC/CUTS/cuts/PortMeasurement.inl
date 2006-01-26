// $Id$

//=============================================================================
/**
 * CUTS_Operation_Measurement
 */
//=============================================================================

//
// repetitions
//
CUTS_INLINE
size_t CUTS_Operation_Measurement::repetitions (void) const
{
  return this->reps_;
}

//
// time
//
CUTS_INLINE
const CUTS_Time_Measurement & CUTS_Operation_Measurement::time (void) const
{
  return this->time_;
}

//=============================================================================
/**
 * CUTS_Worker_Measurement
 */
//=============================================================================

CUTS_INLINE
const CUTS_Worker_Measurement::Operation_Map &
CUTS_Worker_Measurement::operations (void) const
{
  return this->operations_;
}

CUTS_INLINE
CUTS_Worker_Measurement::Operation_Map &
CUTS_Worker_Measurement::operations (void)
{
  return this->operations_;
}

//
// operator =
//
CUTS_INLINE
const CUTS_Worker_Measurement &
CUTS_Worker_Measurement::operator = (const CUTS_Worker_Measurement & src)
{
  this->operations_ = src.operations_;
  return *this;
}

CUTS_INLINE
void CUTS_Worker_Measurement::record_operation (size_t reps, long opid,
                                                const ACE_Time_Value & tm)
{
  this->operations_[opid](reps, tm);
}

//=============================================================================
/**
 * CUTS_Port_Measurement
 */
//=============================================================================

//
// transit_time
//
CUTS_INLINE
const CUTS_Time_Measurement &CUTS_Port_Measurement::transit_time (void) const
{
  return this->transit_time_;
}

CUTS_INLINE
void CUTS_Port_Measurement::transit_time (const ACE_Time_Value &tv)
{
  this->transit_time_ += tv;
}

//
// process_time
//
CUTS_INLINE
const CUTS_Time_Measurement &CUTS_Port_Measurement::process_time (void) const
{
  return this->process_time_;
}

CUTS_INLINE
void CUTS_Port_Measurement::process_time (const ACE_Time_Value &tv)
{
  this->process_time_ += tv;
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
void CUTS_Port_Measurement::record_entry (size_t reps, long worker, long opid,
                                          const ACE_Time_Value & tm)
{
  this->workers_[worker].record_operation (reps, opid, tm);
}
