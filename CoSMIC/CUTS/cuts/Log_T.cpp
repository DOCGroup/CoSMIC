// $Id$

#if !defined (__CUTS_INLINE__)
#include "cuts/Log_T.inl"
#endif

#include "ace/Guard_T.h"

//
// CUTS_Log_T
//
template <typename T, typename LOCK>
CUTS_Log_T <T, LOCK>::CUTS_Log_T (const CUTS_Log_T & log)
: ACE_Array_Base <T> (log.used_size ()),
  used_ (log.used_),
  auto_grow_ (log.auto_grow_)
{
  this->copy_log_i (log);
}

//
// next_free_record
//
template <typename T, typename LOCK>
T * CUTS_Log_T <T, LOCK>::next_free_record (void)
{
  if (this->used_ < this->cur_size_)
  {
    // Optimized for the fast path.
    ACE_READ_GUARD_RETURN (LOCK, guard, this->lock_, 0);
    return this->next_free_record_i ();
  }
  else if (this->auto_grow_)
  {
    ACE_WRITE_GUARD_RETURN (LOCK, guard, this->lock_, 0);

    // Double the size of the log and return the next record. We add
    // one to the size just in case the current size is 0.
    this->size ((this->cur_size_ * 2) + 1);
    return this->next_free_record_i ();
  }
  else
  {
    return 0;
  }
}

//
// CUTS_Log_T
//
template <typename T, typename LOCK>
const CUTS_Log_T <T, LOCK> &
CUTS_Log_T <T, LOCK>::operator = (const CUTS_Log_T <T, LOCK> & log)
{
  this->auto_grow_ = log.auto_grow_;
  this->copy_log (log);
  return *this;
}

//
// copy_log
//
template <typename T, typename LOCK>
void CUTS_Log_T <T, LOCK>::copy_log (const CUTS_Log_T & log)
{
  // Set the size of this log.
  this->size (log.used_size ());
  this->copy_log_i (log);
}

//
// copy_log_i
//
template <typename T, typename LOCK>
void CUTS_Log_T <T, LOCK>::copy_log_i (const CUTS_Log_T & log)
{
  // Copy all the entry from the source log.
  const_iterator iter = log.begin ();
  const_iterator iter_stop = iter + this->size ();

  for (; iter != iter_stop; iter ++)
    *this->next_free_record_i () = *iter;
}
