// $Id$

//
// owner
//
CUTS_INLINE
size_t CUTS_Activation_Record::owner (void) const
{
  return this->owner_;
}

//
// owner
//
CUTS_INLINE
void CUTS_Activation_Record::owner (size_t owner)
{
  this->owner_ = owner;
}

//
// start_time
//
CUTS_INLINE
const ACE_Time_Value &
CUTS_Activation_Record::start_time (void) const
{
  return this->start_time_;
}

//
// stop_time
//
CUTS_INLINE
const ACE_Time_Value &
CUTS_Activation_Record::stop_time (void) const
{
  return this->stop_time_;
}

//
// entries
//
CUTS_INLINE
const CUTS_Activation_Record_Entries &
CUTS_Activation_Record::entries (void) const
{
  return this->entries_;
}

//
// log_time_measurement
//
CUTS_INLINE
void CUTS_Activation_Record::
log_time_measurement (size_t reps,
                      long worker_id,
                      long action_id)
{
  this->entries_.push_back (
    CUTS_Activation_Record_Entry (reps, worker_id, action_id,
    this->action_state_time_, this->action_stop_time_));
}

//
// exit_points
//
CUTS_INLINE
const CUTS_Activation_Record_Endpoints &
CUTS_Activation_Record::endpoints (void) const
{
  return this->endpoints_;
}

//
// queue_time
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Activation_Record::queue_time (void) const
{
  return this->queue_time_;
}

//
// queue_time
//
CUTS_INLINE
void CUTS_Activation_Record::
queue_time (const ACE_Time_Value & queue_time)
{
  this->queue_time_ = queue_time;
}

//
// is_open
//
CUTS_INLINE
bool CUTS_Activation_Record::is_open (void) const
{
  return this->active_;
}

//
// open
//
CUTS_INLINE
void CUTS_Activation_Record::open (void)
{
  this->active_ = true;
  this->start_time_ = ACE_OS::gettimeofday ();
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
// log_endpoint
//
CUTS_INLINE
void CUTS_Activation_Record::log_endpoint (size_t uid)
{
  this->endpoints_.rebind (uid, ACE_OS::gettimeofday ());
}

