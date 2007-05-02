// -*- C++ -*-
// $Id$

//
// CUTS_Activation_Record_Log
//
CUTS_INLINE
CUTS_Activation_Record_Log::
CUTS_Activation_Record_Log (size_t size, bool auto_grow)
: ACE_Array_Base <CUTS_Activation_Record> (size),
  used_ (0),
  auto_grow_ (auto_grow)
{

}

//
// ~CUTS_Activation_Record_Log
//
CUTS_INLINE
CUTS_Activation_Record_Log::~CUTS_Activation_Record_Log (void)
{

}

//
// free_size
//
CUTS_INLINE
size_t CUTS_Activation_Record_Log::free_size (void) const
{
  return this->cur_size_ - this->used_;
}

//
// used_size
//
CUTS_INLINE
size_t CUTS_Activation_Record_Log::used_size (void) const
{
  return this->used_;
}

//
// reset
//
CUTS_INLINE
void CUTS_Activation_Record_Log::reset (void)
{
  this->used_ = 0;
}

//
// lock
//
CUTS_INLINE
ACE_RW_Thread_Mutex & CUTS_Activation_Record_Log::lock (void)
{
  return this->lock_;
}

//
// next_free_record_i
//
CUTS_INLINE
CUTS_Activation_Record * CUTS_Activation_Record_Log::next_free_record_i (void)
{
  return &(this->array_[this->used_ ++]);
}
