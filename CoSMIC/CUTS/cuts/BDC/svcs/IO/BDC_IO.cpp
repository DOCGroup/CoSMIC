// $Id$

#include "BDC_IO.h"
#include "IO_System_Metric_Visitor.h"
#include "cuts/Component_Info.h"
#include "cuts/Host_Table.h"
#include "cuts/Host_Table_Entry.h"
#include "cuts/System_Metric.h"
#include "cuts/Testing_Service.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include <iostream>

// Define the implementation.
CUTS_BDC_SERVICE_IMPL (CUTS_BDC_IO_Service);

//
// state_str_
//
const char * CUTS_BDC_IO_Service::
state_cstr_[2] = {"ACTIVATED", "PASSIVATED"};

//
// CUTS_BDC_IO_Service
//
CUTS_BDC_IO_Service::CUTS_BDC_IO_Service (void)
{

}

//
// ~CUTS_BDC_IO_Service
//
CUTS_BDC_IO_Service::~CUTS_BDC_IO_Service (void)
{

}

//
// handle_metrics
//
int CUTS_BDC_IO_Service::handle_metrics (void)
{
  // Get the current metrics and testing service.
  CUTS_System_Metric * metrics = this->svc_mgr ()->metrics ();
  CUTS_Testing_Service * tsvc = this->svc_mgr ()->testing_service ();

  CUTS_IO_System_Metric_Visitor visitor (tsvc);
  metrics->accept (visitor);

  return 0;
}

//
// handle_component
//
int CUTS_BDC_IO_Service::
handle_component (const CUTS_Component_Info & info)
{
  std::cout
    << "*** Component Registration ***" << std::endl
    << "Instance  : " << info.inst_.c_str () << std::endl
    << "Unique Id : " << info.uid_ << std::endl
    << "Type Info : " << info.type_.c_str () << std::endl
    << "Location  : " << info.host_info_->hostname_.c_str ()
    << " (" << info.host_info_->ipaddr_.c_str () << ")" << std::endl
    << "State     : "
    << CUTS_BDC_IO_Service::state_cstr_[info.state_] << std::endl
    << std::endl;

  return 0;
}
