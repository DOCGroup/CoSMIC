// $Id$

#include "cuts/Port_Agent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Port_Agent.inl"
#endif

#include "cuts/Activation_Record.h"
#include "cuts/Activation_Record_Entry.h"
#include "cuts/Port_Measurement.h"

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

    measurement->process_time (duration);
    measurement->queuing_time (record->queue_time ());

    // Transfer the collected endpoints to the port agent.
    CUTS_Activation_Record_Endpoints::
      CONST_ITERATOR iter = record->endpoints ();

    ACE_Time_Value start_time = record->start_time ();

    while (!iter.done ())
    {
      duration = iter->item () - start_time;

      measurement->record_exitpoint (iter->key (), duration);
      iter.advance ();
    }
  }
}
