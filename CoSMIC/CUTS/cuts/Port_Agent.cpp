// $Id$

#include "cuts/Port_Agent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Port_Agent.inl"
#endif

#include "cuts/Activation_Record.h"
#include "cuts/Activation_Record_Entry.h"
#include "cuts/Benchmark_Visitor.h"
#include "cuts/Port_Measurement.h"
#include <algorithm>

//=============================================================================
/**
 * struct Record_Record_Entry
 */
//=============================================================================

struct Record_Record_Entry
{
  inline
  Record_Record_Entry (CUTS_Port_Measurement * port_measurement)
    : port_measurement_ (port_measurement)
  {

  }

  inline
  void operator () (const CUTS_Activation_Record_Entry & entry)
  {
    this->port_measurement_->record_entry (
      entry.reps_,
      entry.worker_id_,
      entry.action_id_,
      entry.stop_time_ - entry.start_time_);
  }

private:
  CUTS_Port_Measurement * port_measurement_;
};

//
// update
//
void CUTS_Port_Agent::
update (const CUTS_Activation_Record * record)
{
  // Locate the measurements for this owner. If we can not
  // find the records then we need to create a new entry for it.
  CUTS_Port_Measurement_Map & pmmap = this->pool_.current ();
  CUTS_Port_Measurement * measurement = pmmap[record->owner ()];

  if (measurement != 0)
  {
    // Get the duration of the record's activity.
    ACE_Time_Value duration;
    record->get_duration (duration);

    measurement->process_time (record->start_time ());
    measurement->queuing_time (record->queue_time ());

    //// Record all the entries in the activation record.
    //std::for_each (record->entries ().begin (),
    //               record->entries ().end (),
    //               Record_Record_Entry (measurement));

    // Transfer the collected endpoints to the port agent.
    CUTS_Activation_Record_Endpoints::CONST_ITERATOR
      iter = record->endpoints ();

    ACE_Time_Value start_time = record->start_time ();

    while (!iter.done ())
    {
      duration = iter->item () - start_time;

      measurement->record_exitpoint (iter->key (), duration);
      iter.advance ();
    }
  }
}

//
// reset
//
void CUTS_Port_Agent::reset (void)
{
  // Move to the port measurement in the pool_.
  this->pool_.advance ();

}

//
// accept
//
void CUTS_Port_Agent::accept (CUTS_Benchmark_Visitor & visitor)
{
  visitor.visit_port_agent (*this);
}

