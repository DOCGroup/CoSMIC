// $Id$

#include "IO_System_Metric_Visitor.h"
#include "cuts/Component_Info.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Testing_Service.h"
#include "cuts/Time_Metric.h"
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
visit_system_metrics (const CUTS_System_Metric & metrics)
{
  std::cout
    << "*** Collection Time: "
    << CUTS_string_time (metrics.get_timestamp (), "%m-%d-%Y %H:%M:%S")
    << " ***" << std::endl;

  CUTS_Component_Metric_Map::const_iterator iter;
  const CUTS_Component_Info * info = 0;

  for (iter  = metrics.component_metrics ().begin ();
       iter != metrics.component_metrics ().end ();
       iter ++)
  {
    // Get the information about this component and print its
    // instance name.
    std::cout << "Instance: ";

    if (this->tsvc_->registry ().
        get_component_info (iter->first, &info) == 0)
    {
      std::cout << info->inst_.c_str () << std::endl;
    }
    else
    {
      std::cout << "<Unknown>" << std::endl;
    }

    // Visit the component metrics.
    iter->second->accept (*this);
  }
}

//
// visit_component_metrics
//
void CUTS_IO_System_Metric_Visitor::
visit_component_metrics (const CUTS_Component_Metric & metrics)
{
  CUTS_Port_Metric_Map::const_iterator iter;

  for (iter  = metrics.port_metrics ().begin ();
       iter != metrics.port_metrics ().end ();
       iter ++)
  {
    // Print the name of the port.
    std::cout
      << "Port: " << iter->first.c_str () << std::endl;

    CUTS_Sender_Port_Map::const_iterator sender;
    const CUTS_Component_Info * info = 0;

    for (sender  = iter->second.begin ();
         sender != iter->second.end ();
         sender ++)
    {
      // Print the name of the sender.
      std::cout << "  Sender: ";

      if (this->tsvc_->registry ().get_component_info (sender->first,
                                                       &info) == 0)
      {
        std::cout << info->inst_.c_str () << std::endl;
      }
      else
      {
        std::cout << "<Unknown>" << std::endl;
      }

      // Visit the time metrics.
      sender->second->accept (*this);
    }
  }

  std::cout << std::endl;
}

//
// visit_port_metrics
//
void CUTS_IO_System_Metric_Visitor::
visit_port_metrics (const CUTS_Port_Metric & metrics)
{
  // Write the queue time metrics.
  std::cout << "  Queuing Time ";
  metrics.transit_time ().accept (*this);

  CUTS_Endpoint_Metric_Map::const_iterator iter;

  for (iter  = metrics.endpoints ().begin ();
       iter != metrics.endpoints ().end ();
       iter ++)
  {
    // Visit the time metrics.
    std::cout << "  to " << iter->first.c_str () << " ";
    iter->second->accept (*this);
  }
}

//
// visit_time_metrics
//
void CUTS_IO_System_Metric_Visitor::
visit_time_metrics (const CUTS_Time_Metric & metrics)
{
  std::cout
    << "(best/avg/worst) (msec): "
    << metrics.best_time () << "/"
    << metrics.avg_time () << "/"
    << metrics.worse_time () << std::endl;
}
