// $Id$

#include "cuts/Activation_Record.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Activation_Record.inl"
#endif

//
// CUTS_Activation_Record
//
CUTS_Activation_Record::
CUTS_Activation_Record (const CUTS_Activation_Record & rec)
: active_ (rec.active_),
  owner_ (rec.owner_),
  stopwatch_ (rec.stopwatch_),
  queue_time_ (rec.queue_time_)
{
  this->copy_endpoints (rec.endpoints_);
}

//
// operator =
//
const CUTS_Activation_Record &
CUTS_Activation_Record::operator = (const CUTS_Activation_Record & rec)
{
  this->active_ = rec.active_;
  this->owner_ = rec.owner_;

  this->stopwatch_ = rec.stopwatch_;
  this->queue_time_ = rec.queue_time_;
  this->entries_ = rec.entries_;

  this->copy_endpoints (rec.endpoints_);
  return *this;
}

//
// reset
//
void CUTS_Activation_Record::reset (void)
{
  this->owner_ = CUTS_UNKNOWN_IMPL;
  this->queue_time_ = ACE_Time_Value::zero;
}

//
// copy_endpoints
//
void CUTS_Activation_Record::
copy_endpoints (const CUTS_Activation_Record_Endpoints & endpoints)
{
  this->endpoints_.unbind_all ();
  CUTS_Activation_Record_Endpoints::CONST_ITERATOR iter (endpoints);

  for (; !iter.done (); iter ++)
    this->endpoints_.bind (iter->key (), iter->item ());
}

//
// perform_action_i
//
void CUTS_Activation_Record::perform_action_i (size_t uid, size_t type)
{
  // Get the next entry in the log.
  CUTS_Activation_Record_Entry * entry = this->entries_.next_free_record ();

  // Store information about the current action in the entry.
  entry->uid_ = uid;
  entry->type_ = type;
  this->action_timer_.elapsed_time (entry->duration_);
}
