// $Id$

//
// CUTS_Thread_Activation_Record
//
CUTS_INLINE
CUTS_Thread_Activation_Record::
CUTS_Thread_Activation_Record (void)
{

}

//
// ~CUTS_Thread_Activation_Record
//
CUTS_INLINE
CUTS_Thread_Activation_Record::
~CUTS_Thread_Activation_Record (void)
{

}

//
// instance
//
CUTS_INLINE
CUTS_Activation_Record *
CUTS_Thread_Activation_Record::instance (void)
{
  return *CUTS_Thread_Activation_Record::instance_;
}
