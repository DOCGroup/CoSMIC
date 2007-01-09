// $Id$

#include "Thread_Activation_Record.h"

#if !defined (__CUTS_INLINE__)
#include "Thread_Activation_Record.inl"
#endif

//
// instance_
//
CUTS_Thread_Activation_Record::Thread_Record *
CUTS_Thread_Activation_Record::instance_ = 0;

//
// lock_
//
ACE_Thread_Mutex CUTS_Thread_Activation_Record::lock_;

//
// count_
//
size_t CUTS_Thread_Activation_Record::count_ = 0;

//
// init_singleton
//
int CUTS_Thread_Activation_Record::init_singleton (void)
{
  ACE_GUARD_RETURN (ACE_Thread_Mutex,
                    guard,
                    CUTS_Thread_Activation_Record::lock_,
                    -1);

  // Create the singleton instance if necessary.
  if (CUTS_Thread_Activation_Record::instance_ == 0)
  {
    ACE_NEW_RETURN (CUTS_Thread_Activation_Record::instance_,
                    Thread_Record,
                    -1);
  }

  // Increment the refeence count.
  ++ CUTS_Thread_Activation_Record::count_;
  return 0;
}

//
// fini_singleton
//
int CUTS_Thread_Activation_Record::fini_singleton (void)
{
  ACE_GUARD_RETURN (ACE_Thread_Mutex,
                    guard,
                    CUTS_Thread_Activation_Record::lock_,
                    -1);

  if (CUTS_Thread_Activation_Record::count_ > 0)
  {
    // Decrement the thread count. We only can delete the singleton
    // object once reference count reaches zero.

    if (-- CUTS_Thread_Activation_Record::count_ == 0 &&
        CUTS_Thread_Activation_Record::instance_ != 0)
    {
      delete CUTS_Thread_Activation_Record::instance_;
      CUTS_Thread_Activation_Record::instance_ = 0;
    }
  }

  return 0;
}

