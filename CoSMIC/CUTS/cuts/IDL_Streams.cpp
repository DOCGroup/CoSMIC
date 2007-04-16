// $Id$

#include "cuts/IDL_Streams.h"
#include "cuts/Time_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Agent.h"

//===========================================================================
// extraction operations

//
// operator >>
//
void operator >> (const ::CUTS::Benchmark_Data_var & data,
                  CUTS_System_Metric & sys_metrics)
{
  // Get the <CUTS_Component_Metric> for this <data>. If one does not
  // exist it will create a new one, which should be a one time only
  // occurrence. We also update the timestamp for the metrics.
  CUTS_Component_Metric * metric =
    sys_metrics.component_metrics (data->owner);

  metric->timestamp (sys_metrics.get_timestamp ());

  // Get the <ports> and the <length> of the <port> sequence.
  ::CUTS::Port_Measurement_Seq ports = data->ports;
  long length = ports.length ();

  for (long i = 0; i < length; i ++)
  {
    // Get the next <port_measurement> in the collection.
    ::CUTS::Port_Measurement & port_measurement = ports[i];

    long map_length = port_measurement.measurements.length ();

    for (long j = 0; j < map_length; j ++)
    {
      ::CUTS::Mapped_Port_Measurement & mapped_measurement =
        port_measurement.measurements[j];

      CUTS_Port_Metric * port_metric =
        metric->port_metrics (port_measurement.port,
                              mapped_measurement.owner);

      if (port_metric)
      {
        // Set the timestampl for the port metrics and insert the
        // data into the metric.
        port_metric->timestamp (metric->timestamp ());
        mapped_measurement >> (*port_metric);
      }
    }

    // Copy the log from the port measurement structure. Right now, its
    // stored under the CUTS_UNKNOWN_IMPL sender.
    CUTS_Port_Metric * port_metric = metric->port_metrics (port_measurement.port);

    CUTS_Activation_Record_Log & dest_log = port_metric->log ();
    CUTS::Metric_Log & src_log = port_measurement.log;

    size_t length = src_log.length ();
    dest_log.size (length);

    ACE_Time_Value tv;

    for (size_t i = 0; i < length; i ++)
    {
      dest_log[i].owner (src_log[i].sender);
      src_log[i].open_time >> dest_log[i].start_time ();
      src_log[i].close_time >> dest_log[i].stop_time ();

      src_log[i].queue_time >> tv;
      dest_log[i].queue_time (tv);

      size_t endpoint_count = src_log[i].endpoint_times.length ();
      CUTS_Activation_Record_Endpoints & endpoints = dest_log[i].endpoints ();

      for (size_t j = 0; j < endpoint_count; j ++)
      {
        CUTS::Endpoint_Time & endpoint_time = src_log[i].endpoint_times[j];

        endpoint_time.exittime >> tv;
        endpoints.rebind (endpoint_time.uid, tv);
      }
    }

    // Copy the endpoints in the port metrics as well.
    for (::CORBA::ULong i = 0;
         i < port_measurement.endpoints.length ();
         i ++)
    {
      port_metric->endpoint_name (port_measurement.endpoints[i].uid,
                                  port_measurement.endpoints[i].name.in ());
    }
  }
}

//
// operator >>
//
void operator >> (const ::CUTS::Mapped_Port_Measurement & port_measurement,
                  CUTS_Port_Metric & port_metric)
{
  do
  {
    // Save the transit time.
    ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, port_metric.lock ());
    port_measurement.transit_time >> port_metric.transit_time ();
  } while (0);

  // Get all the exit times for this component.
  long length = port_measurement.exit_times.length ();

  for (long i = 0; i < length; i ++)
  {
    // Get the next <exit_point> from the collection.
    const ::CUTS::Exit_Point_Time & exit_point = port_measurement.exit_times[i];

    // Locate the <endpoint> in the <port_metric>.
    CUTS_Time_Metric * time_metric = port_metric.endpoint (exit_point.exit_point_);

    if (time_metric)
    {
      // Update the <timestamp> on the <time_metric> and store
      // the <time_sample_> in the <time_metric>.
      time_metric->timestamp (port_metric.timestamp ());
      exit_point.time_sample_ >> (*time_metric);
    }
  }
}

//
// operator >>
//
void operator >> (const CUTS::Time_Sample & time_sample,
                  CUTS_Time_Metric & time_metric)
{
  CUTS::Time_Info time_info = time_sample.time;

  // Update the timing information.
  ACE_Time_Value min, total, max;

  time_info.total >> total;
  time_info.min >> min;
  time_info.max >> max;

  time_metric.update (time_sample.count, total, min, max);
}

//
// operator >>
//
void CUTS_STUB_Export operator >> (const CUTS::Time_Stamp & timestamp,
                                   ACE_Time_Value & tv)
{
  tv.set (timestamp.sec, timestamp.usec);
}

//===========================================================================
// @@ insertion operations

void operator << (CUTS::Time_Sample & sample, const CUTS_Time_Measurement & pm)
{
  // Save the time meaasurement in the IDL structure.
  sample.count = pm.count ();

  sample.time.min << pm.minimum ();
  sample.time.max << pm.maximum ();
  sample.time.total << pm.accumulation ();
}

void operator << (CUTS::Time_Stamp & timestamp, const ACE_Time_Value & tv)
{
  timestamp.sec = tv.sec ();
  timestamp.usec = tv.usec ();
}
