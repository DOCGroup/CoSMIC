// $Id$

//=============================================================================
/*
 * CUTS_Activation_Record
 */
//=============================================================================

//
// start_time
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Activation_Record::start_time (void) const
{
  return this->start_time_;
}

//
// stop_time
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Activation_Record::stop_time (void) const
{
  return this->stop_time_;
}

//
// close
//
CUTS_INLINE
void CUTS_Activation_Record::close (void)
{
  this->stop_time_ = ACE_OS::gettimeofday ();
  this->active_ = false;
}

//
// entries
//
CUTS_INLINE
const CUTS_Activation_Record::Entries &
CUTS_Activation_Record::entries (void) const
{
  return this->entries_;
}

//
// log_time_measurement
//
CUTS_INLINE
void CUTS_Activation_Record::log_time_measurement (size_t reps,
                                                   long worker_id,
                                                   long action_id)
{
  this->entries_.push (
    Entry (reps, worker_id, action_id,
    this->action_state_time_, this->action_stop_time_));
}

//
// activate
//
CUTS_INLINE
void CUTS_Activation_Record::activate (void)
{
  this->active_ = true;
  this->start_time_ = ACE_OS::gettimeofday ();
}

//
// reset
//
CUTS_INLINE
void CUTS_Activation_Record::reset (void)
{
  this->entries_.c.clear ();
}

//
// exit_points
//
CUTS_INLINE
const CUTS_Activation_Record::Exit_Points &
CUTS_Activation_Record::exit_points (void) const
{
  return this->exit_points_;
}

//
// dispatch_time
//
CUTS_INLINE
void CUTS_Activation_Record::transit_time (
  const ACE_Time_Value & transit_time)
{
  this->transit_time_ = transit_time;
}

CUTS_INLINE
const ACE_Time_Value & CUTS_Activation_Record::transit_time (void) const
{
  return this->transit_time_;
}

//=============================================================================
/*
 * CUTS_Cached_Activation_Record
 */
//=============================================================================

//
// set_next
//
CUTS_INLINE
void CUTS_Cached_Activation_Record::set_next (
  CUTS_Cached_Activation_Record * next)
{
  this->next_ = next;
}

//
// get_next
//
CUTS_INLINE
CUTS_Cached_Activation_Record *
CUTS_Cached_Activation_Record::get_next (void) const
{
  return this->next_;
}
