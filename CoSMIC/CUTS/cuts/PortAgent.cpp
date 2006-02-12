// $Id$

#include "cuts/PortAgent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/PortAgent.inl"
#endif

#include "cuts/Port_Measurement.h"
#include "cuts/Time.h"
#include "ace/Reactor.h"
#include "ace/TP_Reactor.h"
#include "ace/Guard_T.h"
#include <iostream>

// We only use one thread of control for consolidating the
// data in the activation records. If we introduce more threads
// of control then we are going intefere with the QoS of the
// experiment.
static const int DEFAULT_THREAD_COUNT = 1;

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
  /// Pointer to the target port measurement.
  CUTS_Port_Measurement * port_measurement_;

  /// Associated start time for all the exit times.
  const ACE_Time_Value & start_time_;
};

//=============================================================================
/*
 * CUTS_Port_Agent
 */
//=============================================================================

static const int DEFAULT_FREE_LIST_SIZE = 5;

//
// CUTS_Port_Agent
//
CUTS_Port_Agent::CUTS_Port_Agent (void)
: name_ ("unknown"),
  uuid_ ("unknown"),
  active_ (false),
  notify_strategy_ (0),
  free_list_ (ACE_FREE_LIST_WITH_POOL, DEFAULT_FREE_LIST_SIZE),
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
}

//
// initialize
//
void CUTS_Port_Agent::initialize (void)
{
  // Create a new <ACE_Reactor> for the <ACE_Task_Base>.
  ACE_Reactor * reactor = new ACE_Reactor ();
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
  CUTS_Cached_Activation_Record * record = 0;
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
  this->free_list_.add (record);

  return 0;
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

  // Cast the activation record to its cached version.
  CUTS_Cached_Activation_Record * car =
    dynamic_cast <CUTS_Cached_Activation_Record *> (record);

  if (this->active_)
  {
    // Place the record on the <closed_list_>. This will give
    // notify the sweeper thread to collect its data.
    this->closed_list_.enqueue (car);
  }
  else
  {
    // Reset the record and place it on the <free_list_>.
    record->reset ();
    this->free_list_.add (car);
  }
}

//
// release_measurements
//
const CUTS_Port_Measurement * CUTS_Port_Agent::release_measurements (void)
{
  // Right now this is going to affect the performance of the experiment.
  // Each time we are allocating a new <CUTS_Port_Measurement> and its
  // being deallocated eventually. It would better to have two <CUTS_Port_Measurement>
  // buffers that can be switched between when signaled.
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