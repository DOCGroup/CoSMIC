// $Id$

#include "cuts/System_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/System_Metric.inl"
#endif

#include "cuts/Component_Metric.h"
#include "ace/Guard_T.h"

CUTS_System_Metric::CUTS_System_Metric (void)
{

}

CUTS_System_Metric::~CUTS_System_Metric (void)
{

}

//
// insert_component
//
CUTS_Component_Metric *
CUTS_System_Metric::insert_component (const char * name)
{
  // Create a new <CUTS_Component_Metric>.
  CUTS_Component_Metric * metric = 0;
  ACE_NEW_RETURN (metric, CUTS_Component_Metric (), 0);

  std::pair <Component_Metrics::iterator, bool> result;
  do
  {
    ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
    result = this->component_metrics_.insert (
      Component_Metrics::value_type (name, metric));
  } while (false);

  if (!result.second)
  {
    // We failed to insert the <metric>. We therefore must delete
    // the <metric> to reclaim its unused resources.
    delete metric;

    // Since the insertion failed, then the <name> must already be
    // present in the <component_metrics_>.
    metric = result.first->second;
  }

  return metric;
}

//
// component_metrics
//
CUTS_Component_Metric *
CUTS_System_Metric::component_metrics (const char * name)
{
  CUTS_Component_Metric * metric = 0;
  Component_Metrics::iterator result;

  do
  {
    ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
    result = this->component_metrics_.find (name);
  } while (false);

  if (result != this->component_metrics_.end ())
  {
    metric = result->second;
  }
  else
  {
    metric = insert_component (name);
  }

  return metric;
}
