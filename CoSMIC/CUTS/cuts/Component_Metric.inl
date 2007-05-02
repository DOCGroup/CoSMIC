// $Id$

//
// port_metrics
//
CUTS_INLINE
const CUTS_Port_Metric_Map &
CUTS_Component_Metric::port_metrics (void) const
{
  return this->port_metrics_;
}

//
// port_metrics
//
CUTS_INLINE
CUTS_Port_Metric_Map & CUTS_Component_Metric::port_metrics (void)
{
  return this->port_metrics_;
}
