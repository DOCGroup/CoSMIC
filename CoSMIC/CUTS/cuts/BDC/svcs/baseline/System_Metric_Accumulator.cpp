// $Id$

#include "System_Metric_Accumulator.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Port_Measurement.h"

//
// CUTS_System_Metric_Accumulator
//
CUTS_System_Metric_Accumulator::
CUTS_System_Metric_Accumulator (CUTS_System_Metric & dest)
: dest_ (dest)
{

}

//
// ~CUTS_System_Metric_Accumulator
//
CUTS_System_Metric_Accumulator::~CUTS_System_Metric_Accumulator (void)
{

}

//
// visit_system_metric
//
void CUTS_System_Metric_Accumulator::
visit_system_metric (const CUTS_System_Metric & metric)
{
  CUTS_Component_Metric_Map::
    CONST_ITERATOR iter (metric.component_metrics ());

  for (; !iter.done (); iter.advance ())
  {
    // We need to locate the target component metric in the
    // <dest_> system metric object.
    if (this->dest_.component_metric (iter->key (),
                                      this->component_) != -1)
    {
      if (this->component_ != 0)
        iter->item ()->accept (*this);
    }
  }
}

//
// visit_component_metric
//
void CUTS_System_Metric_Accumulator::
visit_component_metric (const CUTS_Component_Metric & metric)
{
  CUTS_Port_Metric_Map::CONST_ITERATOR iter (metric.port_metrics ());

  for (; !iter.done (); iter.advance ())
  {
    // Locate the port metric in the target collection. If it
    // does not exist, we need to create it.
    if (this->component_->port_metric (iter->key (),
                                       this->port_metric_) != -1)
    {
      if (this->port_metric_ != 0)
        iter->item ()->accept (*this);
    }
  }
}

//
// visit_port_metric
//
void CUTS_System_Metric_Accumulator::
visit_port_metric (const CUTS_Port_Metric & port)
{
  CUTS_Port_Measurement_Map::
    CONST_ITERATOR iter (port.sender_map ().hash_map ());

  for (; !iter.done (); iter.advance ())
  {
    if (this->port_metric_->sender_map ().find (iter->key (),
                                                this->port_measure_) == 0)
    {
      if (this->port_measure_ != 0)
        iter->item ()->accept (*this);
    }
  }
}

//
// visit_port_measurement
//
void CUTS_System_Metric_Accumulator::
visit_port_measurement (const CUTS_Port_Measurement & measure)
{
  // Accumulate the overall processing and queuing time.
  this->port_measure_->process_time () += measure.process_time ();
  this->port_measure_->queuing_time () += measure.queuing_time ();

  // Accumulate the timing for each individual endpoint.
  CUTS_Port_Measurement_Endpoint_Map::
    CONST_ITERATOR iter (measure.endpoints ());

  for (; !iter.done (); iter.advance ())
  {
    // Locate the time measurement for the port. We want to
    // create a new one if it doesn't already exist.
    if (this->port_measure_->endpoint (iter->key (), this->timing_) == 0)
    {
      if (this->timing_ != 0)
        iter->item ()->accept (*this);
    }
  }
}

//
// visit_time_measurement
//
void CUTS_System_Metric_Accumulator::
visit_time_measurement (const CUTS_Time_Measurement & tm)
{
  *this->timing_ += tm;
}
