// $Id$

//
// CUTS_Port_Measurement
//
CUTS_INLINE
CUTS_Port_Measurement::CUTS_Port_Measurement (void)
{

}

//
// queuing_time
//
CUTS_INLINE
const CUTS_Time_Measurement &
CUTS_Port_Measurement::queuing_time (void) const
{
  return this->queuing_time_;
}

//
// queuing_time
//
CUTS_INLINE
CUTS_Time_Measurement & CUTS_Port_Measurement::queuing_time (void)
{
  return this->queuing_time_;
}

//
// queuing_time
//
CUTS_INLINE
void CUTS_Port_Measurement::
queuing_time (const ACE_Time_Value & tv)
{
  this->queuing_time_ += tv;
}

//
// process_time
//
CUTS_INLINE
const CUTS_Time_Measurement &
CUTS_Port_Measurement::process_time (void) const
{
  return this->process_time_;
}

//
// process_time
//
CUTS_INLINE
CUTS_Time_Measurement & CUTS_Port_Measurement::process_time (void)
{
  return this->process_time_;
}

//
// process_time
//
CUTS_INLINE
void CUTS_Port_Measurement::
process_time (const ACE_Time_Value & timing)
{
  this->process_time_ += timing;
}

//
// endpoints
//
CUTS_INLINE
CUTS_Port_Measurement_Endpoint_Map &
CUTS_Port_Measurement::endpoints (void)
{
  return this->endpoints_;
}

//
// endpoints
//
CUTS_INLINE
const CUTS_Port_Measurement_Endpoint_Map &
CUTS_Port_Measurement::endpoints (void) const
{
  return this->endpoints_;
}
