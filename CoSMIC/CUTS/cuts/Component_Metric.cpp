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

  for (iter; !iter.done (); iter ++)
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
