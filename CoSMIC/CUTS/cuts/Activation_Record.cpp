// $Id$

#include "cuts/Activation_Record.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Activation_Record.inl"
#endif

//
// CUTS_Activation_Record
//
CUTS_Activation_Record::CUTS_Activation_Record (void)
: active_ (false),
  owner_ (CUTS_UNKNOWN_IMPL),
  queue_time_ (ACE_Time_Value::zero)
{

}

//
// ~CUTS_Activation_Record
//
CUTS_Activation_Record::~CUTS_Activation_Record (void)
{

}

//
// reset
//
void CUTS_Activation_Record::reset (void)
{
  this->owner_ = CUTS_UNKNOWN_IMPL;
  this->queue_time_ = ACE_Time_Value::zero;
  this->entries_.clear ();
}
