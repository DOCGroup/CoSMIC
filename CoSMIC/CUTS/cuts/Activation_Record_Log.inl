// -*- C++ -*-
// $Id$

//
// CUTS_Activation_Record_Log
//
CUTS_INLINE
CUTS_Activation_Record_Log::CUTS_Activation_Record_Log (size_t size)
: ACE_Array_Base <CUTS_Activation_Record> (size),
  used_ (0)
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
// next_free_record
//
CUTS_INLINE
CUTS_Activation_Record * CUTS_Activation_Record_Log::next_free_record (void)
{
  return this->used_ < this->cur_size_ ? &(this->array_[this->used_ ++]) : 0;
}
