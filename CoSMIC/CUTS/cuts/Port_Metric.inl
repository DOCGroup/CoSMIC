// $Id$

//
// log
//
CUTS_INLINE
const CUTS_Activation_Record_Log & CUTS_Port_Metric::log (void) const
{
  return this->log_;
}

//
// log
//
CUTS_INLINE
CUTS_Activation_Record_Log & CUTS_Port_Metric::log (void)
{
  return this->log_;
}

//
// sender_map
//
CUTS_INLINE
CUTS_Port_Measurement_Map & CUTS_Port_Metric::sender_map (void)
{
  return this->sender_map_;
}

CUTS_INLINE
const CUTS_Port_Measurement_Map & CUTS_Port_Metric::sender_map (void) const
{
  return this->sender_map_;
}
