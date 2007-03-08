// $Id$

#include "cuts/Component_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Component_Metric.inl"
#endif

#include "cuts/Port_Metric.h"
#include "cuts/System_Metrics_Visitor.h"

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
  CUTS_Port_Metric_Map::iterator pm_iter;

  for (pm_iter = this->port_metrics_.begin ();
       pm_iter != this->port_metrics_.end ();
       pm_iter ++)
  {
    CUTS_Sender_Port_Map::iterator port;

    for ( port = pm_iter->second.begin ();
          port != pm_iter->second.end ();
          port ++)
    {
      delete port->second;
    }
  }
}

//
// port_metrics
//
CUTS_Port_Metric *
CUTS_Component_Metric::port_metrics (const char * port, size_t sender)
{
  /// @note This implementation needs to be modified!!!

  CUTS_Port_Metric * metric = 0;

  // Locate the port in the mapping.
  ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
  CUTS_Sender_Port_Map & port_mapping = this->port_metrics_[port];

  CUTS_Sender_Port_Map::iterator port_iter = port_mapping.find (sender);

  if (port_iter != port_mapping.end ())
  {
    metric = port_iter->second;
  }
  else
  {
    ACE_NEW_RETURN (metric, CUTS_Port_Metric (), 0);

    port_mapping.insert (
      CUTS_Sender_Port_Map::value_type (sender, metric));
  }

  return metric;
}

//
// accept
//
void CUTS_Component_Metric::
accept (CUTS_System_Metrics_Visitor & visitor) const
{
  visitor.visit_component_metrics (*this);
}

//
// operator +=
//
const CUTS_Component_Metric &
CUTS_Component_Metric::operator += (const CUTS_Component_Metric & metric)
{
  CUTS_Port_Metric_Map::const_iterator iter;

  for (iter  = metric.port_metrics ().begin ();
       iter != metric.port_metrics ().end ();
       iter ++)
  {
    CUTS_Sender_Port_Map::const_iterator sender;

    for (sender  = iter->second.begin ();
         sender != iter->second.end ();
         sender ++)
    {
      if (sender->second)
      {
        CUTS_Port_Metric * port_metric =
          this->port_metrics (iter->first.c_str (), sender->first);

        *port_metric += *sender->second;
      }
    }
  }

  return *this;
}
