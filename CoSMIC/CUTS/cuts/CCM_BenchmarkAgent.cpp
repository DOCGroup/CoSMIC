// $Id$

#include "cuts/CCM_BenchmarkAgent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/CCM_BenchmarkAgent.inl"
#endif

#include "cuts/PortAgent.h"
#include "cuts/Port_Measurement.h"
#include "cuts/ActivationRecord.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_time.h"
#include "ace/streams.h"

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

//
// operator <<
//
CUTS_INLINE
void operator << (::CUTS::Time_Info & time_sample,
                   const CUTS_Time_Measurement & time)
{
  time_sample.max = time.maximum ().msec ();
  time_sample.min = time.minimum ().msec ();
  time_sample.total = time.accumulation ().msec ();
}

//
// operator <<
//
CUTS_INLINE
void operator << (::CUTS::Time_Sample & time_sample,
                   const CUTS_Time_Measurement & time)
{
  time_sample.count = time.count ();
  time_sample.time << time;
}


//=============================================================================
/**
 * Collect_Measurement_Base
 */
//=============================================================================

struct Collect_Measurement_Base
{
  //
  // Collect_Measurement_Base
  //
  Collect_Measurement_Base (void)
    : index_ (0)
  {

  }

protected:
  /// The current index of the collection.
  long index_;
};

//=============================================================================
/**
 * Collect_Action_Measurement
 */
//=============================================================================

struct Collect_Action_Measurement :
  public Collect_Measurement_Base
{
  //
  // Collect_Action_Measurement
  //
  Collect_Action_Measurement (::CUTS::Worker_Measurement & worker)
    : worker_ (worker)
  {

  }

  //
  // operator ()
  //
  void operator () (
    const CUTS_Worker_Measurement::Operation_Map::value_type & item)
  {
    ::CUTS::Action_Measurement & action = this->worker_.actions[this->index_ ++];

    // Save the information about action.
    action.type = item.first;
    action.reps = item.second.repetitions ();

    // Package the timing information for the action.
    action.time << item.second.time ();
  }

private:
  /// Destination worker measurement container.
  ::CUTS::Worker_Measurement & worker_;
};

//=============================================================================
/**
 * Collect_Exit_Time_Measurement
 */
//=============================================================================

struct Collect_Exit_Time_Measurement :
  public Collect_Measurement_Base
{
  Collect_Exit_Time_Measurement (::CUTS::Port_Measurement & port)
    : port_ (port)
  {

  }

  void operator () (const CUTS_Port_Measurement::Exit_Points::value_type & value)
  {
    // Get the next <Exit_Point_Time>.
    ::CUTS::Exit_Point_Time & exit_point_time =
      this->port_.exit_times[this->index_ ++];

    // Save the value to the <exit_point_time>.
    exit_point_time.exit_point_ = CORBA::string_dup (value.first.c_str ());
    exit_point_time.time_sample_ << value.second;
  }

private:
  ::CUTS::Port_Measurement & port_;
};

//=============================================================================
/**
 * Collect_Worker_Measurement
 */
//=============================================================================

struct Collect_Worker_Measurement :
  public Collect_Measurement_Base
{
  //
  // Collect_Worker_Measurement
  //
  Collect_Worker_Measurement (::CUTS::Port_Measurement & port)
    : port_ (port)
  {

  }

  //
  // operator ()
  //
  void operator () (
    const CUTS_Port_Measurement::Worker_Map::value_type & item)
  {
    ::CUTS::Worker_Measurement & worker =
      this->port_.workers[this->index_ ++];

    // Save the worker type.
    worker.type = item.first;

    // Gather all the actions for the worker.
    worker.actions.length (item.second.operations ().size ());

    std::for_each ( item.second.operations ().begin (),
                    item.second.operations ().end (),
                    Collect_Action_Measurement (worker));
  }

private:
  /// The destination container.
  ::CUTS::Port_Measurement & port_;
};

//=============================================================================
/**
 * Collect_Worker_Measurement
 */
//=============================================================================

struct Collect_Port_Measurement :
  public Collect_Measurement_Base
{
  //
  // Collect_Port_Measurement
  //
  Collect_Port_Measurement (::CUTS::Benchmark_Data * data)
    : data_ (data)
  {

  }

  //
  // operator ()
  //
  void operator () (CUTS_Port_Agent * agent)
  {
    // Release the port measurements from the port agent.
    ACE_Auto_Ptr <const CUTS_Port_Measurement> port_data (
      agent->release_measurements ());

    // Initialize the infomation about this port.
    ::CUTS::Port_Measurement & port =
      this->data_->ports[this->index_ ++];

    // Save the processing time and the transit time.
    port.port = CORBA::string_dup (agent->uuid ());
    port.transit_time << port_data->transit_time ();
    port.process_time << port_data->process_time ();

    // Set the size of the worker collection.
    port.workers.length (port_data->worker_measurements ().size ());

    // Get information from each of the workers.
    std::for_each ( port_data->worker_measurements ().begin (),
                    port_data->worker_measurements ().end (),
                    Collect_Worker_Measurement (port));

    // Set the size of the exit time sequence.
    port.exit_times.length (port_data->exit_points ().size ());

    std::for_each (port_data->exit_points ().begin (),
                   port_data->exit_points ().end (),
                   Collect_Exit_Time_Measurement (port));
  }

private:
  /// Pointer to the destination buffer.
  ::CUTS::Benchmark_Data * data_;
};

//
// CUTS_CCM_Benchmark_Agent
//
CUTS_CCM_Benchmark_Agent::CUTS_CCM_Benchmark_Agent (void)
{

}

//
// CUTS_CCM_Benchmark_Agent
//
CUTS_CCM_Benchmark_Agent::~CUTS_CCM_Benchmark_Agent (void)
{

}

//
// performance_data
//
::CUTS::Benchmark_Data * CUTS_CCM_Benchmark_Agent::performance_data (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Create a new data collection bundle.
  CUTS::Benchmark_Data_var benchmark_data (new ::CUTS::Benchmark_Data);

  // Initialize the collection bundle with the correct information.
  benchmark_data->ports.length (this->port_agents ().size ());

  // Collect all the measurements from the port agents.
  std::for_each ( this->port_agents ().begin (),
                  this->port_agents ().end (),
                  Collect_Port_Measurement (benchmark_data.ptr ()));

  benchmark_data->owner = CORBA::string_dup (this->parent ().c_str ());
  benchmark_data->timestamp = ACE_OS::time ();

  return benchmark_data._retn ();
}
