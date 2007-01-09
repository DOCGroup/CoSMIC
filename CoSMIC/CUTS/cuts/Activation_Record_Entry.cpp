// $Id$

#include "cuts/Activation_Record_Entry.h"

//
// CUTS_Activation_Record_Entry
//
CUTS_Activation_Record_Entry::
CUTS_Activation_Record_Entry (void)
: reps_ (0),
  worker_id_ (0),
  action_id_ (0),
  start_time_ (ACE_Time_Value::zero),
  stop_time_ (ACE_Time_Value::zero)
{

}

//
// CUTS_Activation_Record_Entry
//
CUTS_Activation_Record_Entry::
CUTS_Activation_Record_Entry (const CUTS_Activation_Record_Entry & entry)
: reps_ (entry.reps_),
  worker_id_ (entry.worker_id_),
  action_id_ (entry.action_id_),
  start_time_ (entry.start_time_),
  stop_time_ (entry.stop_time_)
{

}

//
// CUTS_Activation_Record_Entry
//
CUTS_Activation_Record_Entry::
CUTS_Activation_Record_Entry (size_t reps,
                              long worker_id,
                              long action_id,
                              ACE_Time_Value & start_time,
                              ACE_Time_Value & stop_time)
: reps_ (reps),
  worker_id_ (worker_id),
  action_id_ (action_id),
  start_time_ (start_time),
  stop_time_ (stop_time)
{

}

//
// operator =
//
const CUTS_Activation_Record_Entry &
CUTS_Activation_Record_Entry::
operator = (const CUTS_Activation_Record_Entry & entry)
{
  this->reps_ = entry.reps_;
  this->worker_id_ = entry.worker_id_;
  this->action_id_ = entry.action_id_;
  this->start_time_ = entry.start_time_;
  this->stop_time_ = entry.stop_time_;

  return *this;
}

