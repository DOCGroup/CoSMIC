// $Id$

#include "cuts/Benchmark_Collector_Visitor.h"
#include "cuts/IDL_Streams.h"
#include "cuts/Port_Agent.h"

CUTS_Benchmark_Collector_Visitor::
CUTS_Benchmark_Collector_Visitor (::CUTS::Benchmark_Data & data)
: data_ (data)
{

}

CUTS_Benchmark_Collector_Visitor::
~CUTS_Benchmark_Collector_Visitor (void)
{

}

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
    (*iter)->accept (*this);
  }
}

void CUTS_Benchmark_Collector_Visitor::
visit_port_agent (const CUTS_Port_Agent & agent)
{
  const CUTS_Port_Measurement_Map & pmm = agent.port_measurements ();

  this->active_pm_->port = ::CORBA::string_dup (agent.name ());
  this->active_pm_->measurements.length (pmm.current_size ());

  CUTS_Port_Measurement_Map::const_iterator pmm_iter (pmm);

  ::CORBA::ULong index = 0;

  while (!pmm_iter.done ())
  {
    this->active_mpm_ = &this->active_pm_->measurements[index ++];
    this->active_mpm_->owner = (*pmm_iter).ext_id_;

    (*pmm_iter).int_id_->accept (*this);
    (*pmm_iter).int_id_->reset ();

    pmm_iter.advance ();
  }
}

void CUTS_Benchmark_Collector_Visitor::
visit_port_measurement (const CUTS_Port_Measurement & measurement)
{
  // Collect the process and transit times for the port.
  this->active_mpm_->process_time << measurement.process_time ();
  this->active_mpm_->transit_time << measurement.transit_time ();

  // Collect the exit times for the port.
  this->active_mpm_->exit_times.length (measurement.exit_points ().size ());

  ::CORBA::ULong index = 0;
  CUTS_Port_Measurement::Exit_Points::const_iterator iter;

  for (iter = measurement.exit_points ().begin ();
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
