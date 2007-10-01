// $Id$

#include "Calibration_Details.h"

#if !defined (__CUTS_INLINE__)
#include "Calibration_Details.inl"
#endif

#include "ace/Auto_Ptr.h"
#include "ace/CORBA_macros.h"
#include <numeric>
#include <math.h>

//
// ~CUTS_CPU_Calibration_Details
//
CUTS_CPU_Calibration_Details::
~CUTS_CPU_Calibration_Details (void)
{
  CUTS_CPU_Calibration_Details_Log::CONST_ITERATOR iter (this->log_);

  for (iter; !iter.done (); iter ++)
    delete iter->item ();
}

//
// process
//
int CUTS_CPU_Calibration_Details::
process (size_t msec,
         const CUTS_CPU_Calibration_Results & results,
         CUTS_CPU_Calibration_Details_Log_Entry * & entry)
{
  // First, let's try to find the entry in the log.
  int retval = this->log_.find (msec, entry);

  if (retval == -1)
  {
    // Create a new entry for the log
    ACE_NEW_THROW_EX (entry,
                      CUTS_CPU_Calibration_Details_Log_Entry,
                      ACE_bad_alloc ());

    // Try to add the entry to log. If we are not able to add the entry
    // to the log, then we need to release the allocated memory.
    ACE_Auto_Ptr <CUTS_CPU_Calibration_Details_Log_Entry> auto_clean (entry);
    retval = this->log_.bind (msec, entry);

    if (retval == 0)
      auto_clean.release ();
  }

  if (retval == 0)
  {
    // Calculate the average execution time and the average error
    // of the collected execution times.
    CUTS_CPU_Calibration_Results::
      value_type sum = std::accumulate (results.begin (), results.end (), 0);

    entry->average_time_  = (double) sum / (double) results.size ();
    entry->average_error_ = entry->average_time_ - (double) msec;
    entry->percent_error_ = entry->average_error_ / (double) msec;

    // Calculate basic statistics about the results.
    entry->variance_ = this->calculate_variance (msec, results);
    entry->stddev_ = sqrt (entry->variance_);
    entry->stderr_ = entry->stddev_ / sqrt ((double) results.size ());

    // Update the min, max, and sum percentages.
    if (entry->average_error_ < this->min_error_)
      this->min_error_ = entry->average_error_;
    else if (entry->average_error_ > this->max_error_)
      this->max_error_ = entry->average_error_;

    this->percent_error_sum_ += entry->percent_error_;
    ++ this->count_;
  }

  return retval;
}

//
// reset
//
void CUTS_CPU_Calibration_Details::reset (void)
{
  // Reset the values.
  this->max_error_ = 0.0;
  this->min_error_ = 0.0;
  this->percent_error_sum_ = 0.0;
  this->count_ = 0;

  // Delete all the entries in the log.
  CUTS_CPU_Calibration_Details_Log::ITERATOR iter (this->log_);

  for (; !iter.done (); iter ++)
    delete iter->item ();

  this->log_.unbind_all ();
}

//
// calculate_stddev
//
double CUTS_CPU_Calibration_Details::
calculate_variance (size_t msec, const CUTS_CPU_Calibration_Results & results)
{
  double sum = 0.0;
  CUTS_CPU_Calibration_Results::const_iterator iter;

  for (iter = results.begin (); iter != results.end (); iter ++)
    sum += ((double)(*iter - msec) * (double)(*iter - msec));

  return (sum / (double) results.size ());
}
