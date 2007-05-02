// $Id$

#include "cuts/Activation_Record_Log.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Activation_Record_Log.inl"
#endif

#include "ace/Guard_T.h"

//
// next_free_record
//
CUTS_Activation_Record * CUTS_Activation_Record_Log::next_free_record (void)
{
  // Optimized for the fast path.
  if (this->used_ < this->cur_size_)
  {
    ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);

    return this->next_free_record_i ();
  }
  else if (this->auto_grow_)
  {
    ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);

    // Double the size of the log and return the next record.
    this->size (this->cur_size_ * 2);
    return this->next_free_record_i ();
  }
  else
  {
    return 0;
  }
}
