// $Id$

#include "cuts/PortAgent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/PortAgent.inl"
#endif

#include "cuts/Port_Measurement.h"
#include "cuts/Time.h"
#include "ace/Reactor.h"
#include "ace/TP_Reactor.h"
#include "ace/streams.h"
#include "ace/Guard_T.h"

static const int DEFAULT_THREAD_COUNT = 5;

//=============================================================================
/**
 * struct Print_Record_Entry
 */
//=============================================================================

struct Print_Record_Entry
{
  void operator () (const CUTS_Activation_Record::Entry & entry)
  {
    cout
      << "Repetitions : " << entry.reps_ << endl
      << "Worker Type : " << entry.worker_id_ << endl
      << "Action Type : " << entry.action_id_ << endl
      << " Start Time : " << entry.start_time_.msec () << endl
      << "  Stop Time : " << entry.stop_time_.msec () << endl
      << endl;
  }
};

//=============================================================================
/**
 * struct Print_Exit_Point_Entry
 */
//=============================================================================

struct Print_Exit_Point_Entry
{
  void operator () (
    const CUTS_Activation_Record::Exit_Points::value_type & entry)
  {
    cout
      << entry.first << " <-> " << entry.second  << endl;
  }
};

//=============================================================================
/**
 * struct Record_Record_Entry
 */
//=============================================================================

struct Record_Record_Entry
{
  Record_Record_Entry (CUTS_Port_Measurement * port_measurement)
    : port_measurement_ (port_measurement)
  {

  }

  void operator () (const CUTS_Activation_Record::Entry & entry)
  {
    this->port_measurement_->record_entry (
      entry.reps_, entry.worker_id_, entry.action_id_,
      entry.stop_time_ - entry.start_time_);
  }

private:
  Print_Record_Entry print_;

  CUTS_Port_Measurement * port_measurement_;
};

//=============================================================================
/**
 * struct Record_Exit_Point
 */
//=============================================================================

struct Record_Exit_Point
{
  Record_Exit_Point (
    CUTS_Port_Measurement * port_measurement,
    const ACE_Time_Value & start_time)
    : port_measurement_ (port_measurement),
      start_time_ (start_time)
  {

  }

  void operator () (
    const CUTS_Activation_Record::Exit_Points::value_type & entry)
  {
    this->port_measurement_->record_exit_point_time (
      entry.first, (entry.second - this->start_time_));
  }

private:
  Print_Exit_Point_Entry print_;

  /// Pointer to the target port measurement.
  CUTS_Port_Measurement * port_measurement_;

  /// Associated start time for all the exit times.
  const ACE_Time_Value & start_time_;
};

//
// CUTS_Port_Agent
//
CUTS_Port_Agent::CUTS_Port_Agent (void)
: name_ ("unknown"),
  uuid_ ("unknown"),
  active_ (false),
  notify_strategy_ (0),
  port_measurement_ (new CUTS_Port_Measurement ())
{
  initialize ();
}

CUTS_Port_Agent::CUTS_Port_Agent (const char * uuid, const char * name)
: name_ (name),
  uuid_ (uuid),
  active_ (false),
  notify_strategy_ (0),
  port_measurement_ (new CUTS_Port_Measurement ())
{
  initialize ();
}

//
// ~CUTS_Port_Agent
//
CUTS_Port_Agent::~CUTS_Port_Agent (void)
{
  // Delete the <reactor_>.
  delete this->reactor ();
  this->reactor (0);

  // Delete all the <records_>.
  for ( Record_List::iterator iter = this->records_.begin ();
        iter != this->records_.end ();
        iter ++)
  {
    delete *iter;
  }
}

//
// initialize
//
void CUTS_Port_Agent::initialize (void)
{
  // Create a new <ACE_Reactor> for the <ACE_Task_Base>.
  ACE_Reactor * reactor = new ACE_Reactor (new ACE_TP_Reactor (), 1);
  this->reactor (reactor);

  // Create the notification strategy.
  this->notify_strategy_.reset (
    new ACE_Reactor_Notification_Strategy (
    reactor, this, ACE_Event_Handler::READ_MASK));

  // Attach the notification strategy to the <closed_list_>.
  this->closed_list_.notification_strategy (this->notify_strategy_.get ());
}

//
// svc
//
int CUTS_Port_Agent::svc (void)
{
  // Set the owner of the reactor.
  this->reactor ()->owner (ACE_OS::thr_self ());

  // Process all the events.
  while (this->active_)
  {
    this->reactor ()->handle_events ();
  }

  return 0;
}

//
// handle_input
//
int CUTS_Port_Agent::handle_input (ACE_HANDLE fd)
{
  // Get the next activation record from the <closed_list_>.
  CUTS_Activation_Record * record;
  this->closed_list_.dequeue (record);

  // Get the lock for the map.
  do
  {
    ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->lock_, -1);

    // Record the processing time for the activation record.
    this->port_measurement_->transit_time (record->transit_time ());
    this->port_measurement_->process_time (
      record->stop_time () - record->start_time ());

    // Record all the entries in the activation record.
    std::for_each (
      record->entries ().c.begin (),
      record->entries ().c.end (),
      Record_Record_Entry (this->port_measurement_.get ()));

    // Record all the exit points in the activation record.
    std::for_each (
      record->exit_points ().begin (),
      record->exit_points ().end (),
      Record_Exit_Point (this->port_measurement_.get (),
                         record->start_time ()));
  } while (0);

  // Insert the activation record into the <free_list_>.
  record->reset ();
  this->free_list_.enqueue (record);

  return 0;
}

//
// create_activation_record
//
CUTS_Activation_Record * CUTS_Port_Agent::create_activation_record (void)
{
  CUTS_Activation_Record * record;
  if (!this->free_list_.is_empty ())
  {
    // Get a record from the <free_list_>.
    this->free_list_.dequeue (record);
  }
  else
  {
    // Create a new <CUTS_Activation_Record>
    ACE_NEW_RETURN (record, CUTS_Activation_Record, 0);
    this->records_.insert (record);
  }

  return record;
}

//
// activate
//
void CUTS_Port_Agent::activate (void)
{
  if (!this->active_)
  {
    this->active_ = true;

    // Activate the task with default number of threads.
    ACE_Task_Base::activate (THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED,
                             DEFAULT_THREAD_COUNT);
  }
}

//
// deactivate
//
void CUTS_Port_Agent::deactivate (void)
{
  if (this->active_)
  {
    // Signal the reactor to task to stop.
    this->active_ = false;
    this->reactor ()->notify (this);

    // Wait for all the threads to finish.
    wait ();
  }
}

//
// close_activation_record
//
void CUTS_Port_Agent::close_activation_record (CUTS_Activation_Record * record)
{
  // Close the record.
  record->close ();

  // If the port agent is active then we have to process the
  // activation record. If the agent is not active then we
  // can discard its contents.
  if (this->active_)
  {
    this->closed_list_.enqueue (record);
  }
  else
  {
    this->free_list_.enqueue (record);
  }
}

//
// release_measurements
//
const CUTS_Port_Measurement * CUTS_Port_Agent::release_measurements (void)
{
  CUTS_Port_Measurement * pm = 0;

  try
  {
    ACE_NEW_RETURN (pm, CUTS_Port_Measurement, 0);
    CUTS_Port_Measurement * old = 0;

    // Get a lock to the measurements.
    do
    {
      ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->lock_, 0);

      // Get the old and save the new.
      old = this->port_measurement_.release ();
      this->port_measurement_.reset (pm);
    } while (false);

    // Return the old measurements.
    pm = old;
  }
  catch (std::bad_alloc &)
  {

  }
  return pm;
}