// $Id$

#include "cuts/IDL_Streams.h"
#include "cuts/Time_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/PortAgent.h"

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
    CUTS_Time_Metric * time_metric =
      port_metric.endpoint (exit_point.exit_point_);

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
void operator >> (const ::CUTS::Time_Sample & time_sample,
                  CUTS_Time_Metric & time_metric)
{
  // Update the timing information.
  time_metric.update (time_sample.count,
                      time_sample.time.total,
                      time_sample.time.min,
                      time_sample.time.max);
}

//===========================================================================
// insertion operations

void operator << (::CUTS::Time_Sample & sample,
                  const CUTS_Time_Measurement & pm)
{
  sample.count = pm.count ();
  sample.time.min = pm.minimum ().msec ();
  sample.time.max = pm.maximum ().msec ();
  sample.time.total = pm.accumulation ().msec ();
}
