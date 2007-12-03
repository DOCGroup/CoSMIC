// $Id$

#include "cuts/System_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/System_Metric.inl"
#endif

#include "cuts/Component_Metric.h"
#include "cuts/Metrics_Visitor.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_NS_sys_time.h"

//
// CUTS_System_Metric
//
CUTS_System_Metric::CUTS_System_Metric (void)
{

}

//
// ~CUTS_System_Metric
//
CUTS_System_Metric::~CUTS_System_Metric (void)
{
  CUTS_Component_Metric_Map::ITERATOR iter (this->component_metrics_);

  for ( ; !iter.done (); iter ++)
    delete iter->item ();
}

//
// insert_component_metric
//
int CUTS_System_Metric::
insert_component_metric (long regid, CUTS_Component_Metric * & metric)
{
  // Create new CUTS_Component_Metric and insert it into mapping.
  ACE_NEW_RETURN (metric,
                  CUTS_Component_Metric (),
                  -1);

  ACE_Auto_Ptr <CUTS_Component_Metric> auto_clean (metric);
  int retval = this->component_metrics_.trybind (regid, metric);

  // Check the return value of the operation. If the insertion
  // was successful, then we need to release the auto_ptr. If the
  // insertion failed, then we need to clean up the allocated memory.
  // Otherwise, the entry already existed and we need to return
  // the existing value and release the allocated memory.

  if (retval == 0)
  {
    auto_clean.release ();
  }
  else if (retval == -1)
  {
    metric = 0;
  }

  return retval;
}

//
// remove_component_metric
//
int CUTS_System_Metric::remove_component_metric (long regid)
{
  CUTS_Component_Metric * metric = 0;
  int retval = this->component_metrics_.unbind (regid, metric);

  if (retval == 0 && metric != 0)
    delete metric;

  return retval;
}

//
// component_metric
//
int CUTS_System_Metric::
component_metric (long regid,
                  CUTS_Component_Metric * & metric,
                  bool auto_create)
{
  int retval = this->component_metrics_.find (regid, metric);

  if (retval == -1 && auto_create)
    retval = this->insert_component_metric (regid, metric);

  return retval;
}

//
// accept
//
void CUTS_System_Metric::
accept (CUTS_Metrics_Visitor & visitor) const
{
  visitor.visit_system_metric (*this);
}

//
// timestamp
//
void CUTS_System_Metric::
set_timestamp (const ACE_Time_Value * timestamp)
{
  // Save the previous timestamp before we set the
  // new timestamp value.
  ACE_Time_Value prev_time = this->timestamp_;
  this->timestamp_i (timestamp);

  // Calculate the duration between time values.
  this->duration_ = prev_time - this->timestamp_;
}

//
// init_timestamp
//
void CUTS_System_Metric::
init_timestamp (const ACE_Time_Value * timestamp)
{
  this->timestamp_i (timestamp);
  this->duration_ = ACE_Time_Value::zero;
}

//
// timestamp_i
//
void CUTS_System_Metric::
timestamp_i (const ACE_Time_Value * timestamp)
{
  if (timestamp)
    this->timestamp_ = *timestamp;
  else
    this->timestamp_ = ACE_OS::gettimeofday ();
}
