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
// name
//
CUTS_INLINE
void CUTS_Port_Agent::name (const char * name)
{
  this->name_ = name;
}

//
// port_measurements
//
CUTS_INLINE
CUTS_Port_Measurement_Map &
CUTS_Port_Agent::port_measurements (void)
{
  return this->measurement_pool_.advance ();
}

//
// port_measurements
//
CUTS_INLINE
const CUTS_Port_Measurement_Map &
CUTS_Port_Agent::port_measurements (void) const
{
  return this->measurement_pool_.advance ();
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
