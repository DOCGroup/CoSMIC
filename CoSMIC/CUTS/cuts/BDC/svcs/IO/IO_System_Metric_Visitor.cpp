// $Id$

#include "IO_System_Metric_Visitor.h"
#include "cuts/Component_Info.h"
#include "cuts/Component_Type.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Testing_Service.h"
#include "cuts/Time.h"
#include <iostream>

//
// CUTS_IO_System_Metric_Visitor
//
CUTS_IO_System_Metric_Visitor::
CUTS_IO_System_Metric_Visitor (const CUTS_Testing_Service * tsvc)
: tsvc_ (tsvc)
{

}

//
// ~CUTS_IO_System_Metric_Visitor
//
CUTS_IO_System_Metric_Visitor::~CUTS_IO_System_Metric_Visitor (void)
{

}

//
// visit_system_metrics
//
void CUTS_IO_System_Metric_Visitor::
visit_system_metric (const CUTS_System_Metric & metrics)
{
  std::cout
    << "*** Collection Time: "
    << CUTS_string_time (metrics.get_timestamp (), "%m-%d-%Y %H:%M:%S")
    << " ***" << std::endl;

  CUTS_Component_Metric_Map::CONST_ITERATOR iter (metrics.component_metrics ());

  for (iter; !iter.done (); iter ++)
  {
    // Get the information about this component and print its
    // instance name.
    std::cout << "Instance: ";

    if (this->tsvc_->registry ().
        get_component_info (iter->key (), &this->myinfo_) == 0)
    {
      std::cout << this->myinfo_->inst_.c_str () << std::endl;
    }
    else
    {
      std::cout << "<Unknown>" << std::endl;
    }

    // Visit the component metrics.
    iter->item ()->accept (*this);
  }
}

//
// visit_component_metrics
//
void CUTS_IO_System_Metric_Visitor::
visit_component_metric (const CUTS_Component_Metric & metrics)
{
  ACE_CString portname;
  CUTS_Port_Metric_Map::CONST_ITERATOR iter (metrics.port_metrics ());

  for (iter; !iter.done (); iter ++)
  {
    // Print the name of the port.
    this->myinfo_->type_->sinks_.find (iter->key (), portname);
    std::cout << "Port: " << portname.c_str () << std::endl;

    // Visit the CUTS_Port_Metric object.
    iter->item ()->accept (*this);
  }
}

//
// visit_port_metrics
//
void CUTS_IO_System_Metric_Visitor::
visit_port_metric (const CUTS_Port_Metric & metrics)
{
  CUTS_Port_Measurement_Map::
    CONST_ITERATOR sender (metrics.sender_map ().hash_map ());

  const CUTS_Component_Info * sender_info = 0;

  for (sender; !sender.done (); sender ++)
  {
    // Print the name of the sender.
    std::cout << "  Sender: ";

    if (this->tsvc_->registry ().get_component_info (sender->key (),
                                                     &sender_info) == 0)
    {
      std::cout << sender_info->inst_.c_str () << std::endl;
    }
    else
    {
      std::cout << "<Unknown>" << std::endl;
    }

    // Visit the time metrics.
    sender->item ()->accept (*this);
    std::cout << std::endl;
  }
}

//
// visit_port_measurement
//
void CUTS_IO_System_Metric_Visitor::
visit_port_measurement (const CUTS_Port_Measurement & port)
{
  // Write the queue time metrics.
  std::cout << "  Queuing Time ";
  port.queuing_time ().accept (*this);
  std::cout << "  Process Time ";
  port.process_time  ().accept (*this);

  ACE_CString portname;
  CUTS_Port_Measurement_Endpoint_Map::CONST_ITERATOR iter (port.endpoints ());

  for ( ; !iter.done (); iter ++)
  {
    // Write the information about the exitpoint.
    int retval = this->myinfo_->type_->sources_.find (iter->key (), portname);
    std::cout << "    to ";

    if (retval == 0)
      std::cout << portname.c_str ();
    else
      std::cout << "<unknown> (" << iter->key () << ")";

    std::cout << " ";

    // Visit the time measurement.
    iter->item ()->accept (*this);
  }
}

//
// visit_time_measurement
//
void CUTS_IO_System_Metric_Visitor::
visit_time_measurement (const CUTS_Time_Measurement & tm)
{
  double avg_time =
    tm.count () != 0 ? tm.total ().msec () / tm.count () : 0.0;

  std::cout
    << "(best/avg/worst) (msec): "
    << tm.minimum ().msec () << "/"
    << avg_time << "/" << tm.maximum ().msec () << std::endl;
}
