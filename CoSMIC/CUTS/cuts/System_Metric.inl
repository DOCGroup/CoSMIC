// $Id$

//
// component_metrics
//
CUTS_INLINE
const CUTS_Component_Metric_Map &
CUTS_System_Metric::component_metrics (void) const
{
  return this->component_metrics_;
}

//
// get_timestamp
//
CUTS_INLINE
const ACE_Time_Value &
CUTS_System_Metric::get_timestamp (void) const
{
  return this->timestamp_;
}

//
// get_timestamp
//
CUTS_INLINE
const ACE_Time_Value &
CUTS_System_Metric::get_duration (void) const
{
  return this->duration_;
}
