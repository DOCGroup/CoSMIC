// $Id$

#include "cuts/Activation_Record_Log.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Activation_Record_Log.inl"
#endif

//
// next_free_record
//
CUTS_Activation_Record * CUTS_Activation_Record_Log::next_free_record (void)
{
  // Optimized for the fast path.
  if (this->used_ < this->cur_size_)
  {
    return &(this->array_[this->used_ ++]);
  }
  else if (this->auto_grow_)
  {
    // Double the size of the log and return the next record.
    this->size (this->cur_size_ * 2);
    return &(this->array_[this->used_ ++]);
  }
  else
  {
    return 0;
  }
}
