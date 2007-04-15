// $Id$

//
// CUTS_Activation_Record
//
CUTS_INLINE
CUTS_Activation_Record::CUTS_Activation_Record (void)
: active_ (false),
  owner_ (CUTS_UNKNOWN_IMPL)
{

}

//
// ~CUTS_Activation_Record
//
CUTS_INLINE
CUTS_Activation_Record::~CUTS_Activation_Record (void)
{

}

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
  return this->stopwatch_.start_;
}

CUTS_INLINE
ACE_Time_Value &
CUTS_Activation_Record::start_time (void)
{
  return this->stopwatch_.start_;
}

//
// stop_time
//
CUTS_INLINE
const ACE_Time_Value &
CUTS_Activation_Record::stop_time (void) const
{
  return this->stopwatch_.stop_;
}

CUTS_INLINE
ACE_Time_Value &
CUTS_Activation_Record::stop_time (void)
{
  return this->stopwatch_.stop_;
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
log_time_measurement (size_t reps, long worker_id, long action_id)
{
  this->entries_.push_back (
    CUTS_Activation_Record_Entry (reps, worker_id, action_id,
    this->action_state_time_, this->action_stop_time_));
}

//
// endpoints
//
CUTS_INLINE
const CUTS_Activation_Record_Endpoints &
CUTS_Activation_Record::endpoints (void) const
{
  return this->endpoints_;
}

//
// endpoints
//
CUTS_INLINE
CUTS_Activation_Record_Endpoints &
CUTS_Activation_Record::endpoints (void)
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
  this->stopwatch_.start_ = ACE_OS::gettimeofday ();
}

//
// open
//
CUTS_INLINE
void CUTS_Activation_Record::open (size_t owner)
{
  this->owner_ = owner;
  this->open ();
}

//
// close
//
CUTS_INLINE
void CUTS_Activation_Record::close (void)
{
  this->stopwatch_.stop_ = ACE_OS::gettimeofday ();
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

//
// duration
//
CUTS_INLINE
void CUTS_Activation_Record::
get_duration (ACE_Time_Value & duration) const
{
  duration = this->stopwatch_.stop_ - this->stopwatch_.start_;
}

//
// CUTS_Cached_Activation_Record
//
CUTS_INLINE
CUTS_Cached_Activation_Record::CUTS_Cached_Activation_Record (void)
: next_ (0)
{

}

//
// CUTS_Cached_Activation_Record
//
CUTS_INLINE
CUTS_Cached_Activation_Record::~CUTS_Cached_Activation_Record (void)
{

}

//
// get_next
//
CUTS_INLINE
CUTS_Cached_Activation_Record *
CUTS_Cached_Activation_Record::get_next (void)
{
  return this->next_;
}

//
// get_next
//
CUTS_INLINE
void CUTS_Cached_Activation_Record::
set_next (CUTS_Cached_Activation_Record * next)
{
  this->next_ = next;
}

