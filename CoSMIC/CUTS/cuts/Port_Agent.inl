// $Id$

//
// CUTS_Port_Agent
//
CUTS_INLINE
CUTS_Port_Agent::CUTS_Port_Agent (void)
: name_ ("unknown"),
  active_ (false),
  pool_ (2)
{

}

//
// ~CUTS_Port_Agent
//
CUTS_INLINE
CUTS_Port_Agent::~CUTS_Port_Agent (void)
{
  this->deactivate ();
}

//
// name
//
CUTS_INLINE
const ACE_CString & CUTS_Port_Agent::name (void) const
{
  return this->name_;
}

//
// name
//
CUTS_INLINE
void CUTS_Port_Agent::name (const ACE_CString & name)
{
  this->name_ = name;
}

//
// port_measurement_pool
//
CUTS_INLINE
const CUTS_Port_Measurement_Pool &
CUTS_Port_Agent::port_measurement_pool (void) const
{
  return this->pool_;
}

//
// activate
//
CUTS_INLINE
void CUTS_Port_Agent::activate (void)
{
  this->active_ = true;
}

//
// deactivate
//
CUTS_INLINE
void CUTS_Port_Agent::deactivate (void)
{
  this->active_ = false;
}

//
// is_active
//
CUTS_INLINE
bool CUTS_Port_Agent::is_active (void) const
{
  return this->active_;
}

//
// log
//
CUTS_INLINE
const CUTS_Activation_Record_Log & CUTS_Port_Agent::log (void) const
{
  return this->log_;
}

//
// record_alloc
//
CUTS_INLINE
CUTS_Activation_Record * CUTS_Port_Agent::record_alloc (void)
{
  return
    this->log_.free_size () > 0 ?
    this->log_.next_free_record () : &this->fallback_record_;
}

//
// record_free
//
CUTS_INLINE
void CUTS_Port_Agent::record_free (CUTS_Activation_Record * record)
{
  this->update (record);
}
