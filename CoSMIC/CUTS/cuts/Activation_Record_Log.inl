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
