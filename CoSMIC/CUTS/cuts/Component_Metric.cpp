// $Id$

#include "cuts/Component_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Component_Metric.inl"
#endif

#include "cuts/Metrics_Visitor.h"
#include "cuts/Port_Metric.h"

//
// CUTS_Component_Metric
//
CUTS_Component_Metric::CUTS_Component_Metric (void)
{

}

//
// ~CUTS_Component_Metric
//
CUTS_Component_Metric::~CUTS_Component_Metric (void)
{
  CUTS_Port_Metric_Map::ITERATOR iter (this->port_metrics_);

  for ( ; !iter.done (); iter ++)
    delete iter->item ();
}

//
// accept
//
void CUTS_Component_Metric::
accept (CUTS_Metrics_Visitor & visitor) const
{
  visitor.visit_component_metric (*this);
}

//
// port_metric
//
int CUTS_Component_Metric::
port_metric (long pmid, CUTS_Port_Metric * & pm, bool auto_create)
{
  if (this->port_metrics_.find (pmid, pm) == 0)
    return 0;

  if (auto_create)
  {
    // Create a new port metric object.
    CUTS_Port_Metric * temp = 0;
    ACE_NEW_RETURN (temp, CUTS_Port_Metric (), -1);
    ACE_Auto_Ptr <CUTS_Port_Metric> auto_clean (temp);

    // Store the port metric inside the mapping.
    if (this->port_metrics_.bind (pmid, temp) == 0)
    {
      pm = auto_clean.release ();
      return 0;
    }
  }

  return -1;
}
