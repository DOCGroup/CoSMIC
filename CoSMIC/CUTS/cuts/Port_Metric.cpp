// $Id$

#include "cuts/Port_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Port_Metric.inl"
#endif

#include "cuts/Metrics_Visitor.h"

//
// CUTS_Port_Metric
//
CUTS_Port_Metric::CUTS_Port_Metric (void)
{

}

//
// ~CUTS_Port_Metric
//
CUTS_Port_Metric::~CUTS_Port_Metric (void)
{

}

//
// accept
//
void CUTS_Port_Metric::
accept (CUTS_Metrics_Visitor & visitor) const
{
  visitor.visit_port_metric (*this);
}
