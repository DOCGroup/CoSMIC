// $Id$

#include "cuts/Component_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Component_Metric.inl"
#endif

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
  for (Port_Metric_Map::iterator iter = this->port_metrics_.begin ();
       iter != this->port_metrics_.end ();
       iter ++)
  {
    delete iter->second;
  }
}

//
// insert_port
//
CUTS_Port_Metric * CUTS_Component_Metric::insert_port (const char * port)
{
  // Create a new <CUTS_Port_Metric>.
  CUTS_Port_Metric * metric = 0;
  ACE_NEW_RETURN (metric, CUTS_Port_Metric (), false);

  std::pair <Port_Metric_Map::iterator, bool> result;

  do
  {
    // Insert the new metric into the mapping.
    ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, false);
    result = this->port_metrics_.insert (
      Port_Metric_Map::value_type (port, metric));
  } while (false);

  // If the above operation fails then the <port> already exist
  // in the mapping.
  if (!result.second)
  {
    delete metric;
    metric = result.first->second;
  }

  return metric;
}

//
// remove_port
//
void CUTS_Component_Metric::remove_port (const char * port)
{
  ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, this->lock_);
  this->port_metrics_.erase (port);
}

//
// port_metrics
//
CUTS_Port_Metric * CUTS_Component_Metric::port_metrics (const char * port)
{
  CUTS_Port_Metric * metric = 0;
  Port_Metric_Map::iterator result;

  do
  {
    // Locate the port in the mapping.
    ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
    result = this->port_metrics_.find (port);
  }
  while (false);

  if (result != this->port_metrics_.end ())
  {
    metric = result->second;
  }
  else
  {
    metric = insert_port (port);
  }

  return metric;
}
