// $Id$

#include "cuts/Benchmark_Collector_Visitor.h"
#include "cuts/IDL_Streams.h"
#include "cuts/Port_Agent.h"

//
// CUTS_Benchmark_Collector_Visitor
//
CUTS_Benchmark_Collector_Visitor::
CUTS_Benchmark_Collector_Visitor (::CUTS::Benchmark_Data & data)
: data_ (data)
{

}

//
// ~CUTS_Benchmark_Collector_Visitor
//
CUTS_Benchmark_Collector_Visitor::
~CUTS_Benchmark_Collector_Visitor (void)
{

}

//
// visit_benchmark_agent
//
void CUTS_Benchmark_Collector_Visitor::
visit_benchmark_agent (const CUTS_Benchmark_Agent & agent)
{
  this->agent_ = &agent;

  // Set the size of the sequence.
  this->data_.ports.length (agent.port_agents ().size ());

  ::CORBA::ULong index = 0;

  for (CUTS_Port_Agent_Set::const_iterator iter = agent.port_agents ().begin ();
       iter != agent.port_agents ().end ();
       iter ++)
  {
    this->active_pm_ = &this->data_.ports[index ++];

    // Visit the port agent then reset it.
    (*iter)->accept (*this);
    (*iter)->reset ();
  }
}

//
// visit_port_agent
//
void CUTS_Benchmark_Collector_Visitor::
visit_port_agent (const CUTS_Port_Agent & agent)
{
  // Get the current port measurement map.
  const CUTS_Port_Measurement_Map & pmm =
    agent.port_measurement_pool ().current ();

  // Initialize the package with information about the port
  // agent and the number of senders it collected metrics for.
  this->active_pm_->port = ::CORBA::string_dup (agent.name ().c_str ());
  this->active_pm_->measurements.length (pmm.size ());

  CUTS_Port_Measurement_Map::CONST_ITERATOR pmm_iter (pmm.hash_map ());

  ::CORBA::ULong index = 0;

  while (!pmm_iter.done ())
  {
    this->active_mpm_ = &this->active_pm_->measurements[index ++];
    this->active_mpm_->owner = (*pmm_iter).ext_id_;

    (*pmm_iter).int_id_->accept (*this);
    (*pmm_iter).int_id_->reset ();

    pmm_iter.advance ();
  }

  // Copy the endpoints to the data structure.
  this->active_pm_->endpoints.length (this->agent_->endpoints ().size ());

  CUTS_Benchmark_Agent::Endpoint_Map::
    const_iterator ep_begin = this->agent_->endpoints ().begin ();
  CUTS_Benchmark_Agent::Endpoint_Map::
    const_iterator ep_end = this->agent_->endpoints ().end ();

  index = 0;
  for (ep_begin; ep_begin != ep_end; ep_begin ++)
  {
    this->active_pm_->endpoints[index].uid = ep_begin->second;

    this->active_pm_->endpoints[index].name =
      ::CORBA::string_dup (ep_begin->first.c_str ());
  }

  // Copy the metric log into the data structure.
  const CUTS_Activation_Record_Log & log = agent.log ();
  size_t used_size = log.used_size ();

  this->active_pm_->log.length (used_size);
  CUTS_Activation_Record_Log::const_iterator begin = log.begin ();
  CUTS_Activation_Record_Log::const_iterator end = begin + used_size;

  size_t i = 0;

  for (begin; begin < end; begin ++)
  {
    CUTS::Metric_Record & record = this->active_pm_->log[i ++];

    record.sender = begin->owner ();
    record.open_time << begin->start_time ();
    record.close_time << begin->stop_time ();
    record.queue_time << begin->queue_time ();

    CUTS_Activation_Record_Endpoints::
      CONST_ITERATOR endpoints = begin->endpoints ().begin ();

    record.endpoint_times.length (begin->endpoints ().current_size ());

    size_t j = 0;
    while (!endpoints.done ())
    {
      record.endpoint_times[j].uid = endpoints->key ();
      record.endpoint_times[j].exittime << endpoints->item ();

      endpoints.advance ();
      ++ j;
    }
  }
}

//
// visit_port_measurement
//
void CUTS_Benchmark_Collector_Visitor::
visit_port_measurement (const CUTS_Port_Measurement & measurement)
{
  // Collect the process and transit times for the port.
  this->active_mpm_->process_time << measurement.process_time ();
  this->active_mpm_->transit_time << measurement.queuing_time ();

  // Collect the exit times for the port.
  this->active_mpm_->exit_times.length (measurement.exit_points ().size ());

  // Collect the history for the port.
  ::CORBA::ULong index = 0;
  CUTS_Port_Measurement::Exit_Points::const_iterator iter;

  for (iter  = measurement.exit_points ().begin ();
       iter != measurement.exit_points ().end ();
       iter ++)
  {
    ::CUTS::Exit_Point_Time & ept =
      this->active_mpm_->exit_times[index ++];

    ept.exit_point_ =
      ::CORBA::string_dup (this->agent_->endpoint_name (iter->first));

    ept.time_sample_ << iter->second;
  }
}
