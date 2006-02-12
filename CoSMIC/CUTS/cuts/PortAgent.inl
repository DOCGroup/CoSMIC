// $Id$

//
// name
//
CUTS_INLINE
const char * CUTS_Port_Agent::name (void) const
{
  return this->name_.c_str ();
}

//
// uuid
//
CUTS_INLINE
const char * CUTS_Port_Agent::uuid (void) const
{
  return this->uuid_.c_str ();
}

//
// create_activation_record
//
CUTS_INLINE
CUTS_Activation_Record * CUTS_Port_Agent::create_activation_record (void)
{
  return this->free_list_.remove ();
}

