// $Id$

//
// get_record
//
CUTS_INLINE
CUTS_Activation_Record *
CUTS_Thread_Activation_Record::get_record (void)
{
  return CUTS_Thread_Activation_Record::tss_;
}

//
// set_record
//
CUTS_INLINE
CUTS_Activation_Record * CUTS_Thread_Activation_Record::
set_record (CUTS_Activation_Record * record)
{
  return CUTS_Thread_Activation_Record::tss_.ts_object (record);
}
