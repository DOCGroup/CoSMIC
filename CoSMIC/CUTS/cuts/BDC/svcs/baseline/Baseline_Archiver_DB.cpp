// $Id$

#include "Baseline_Archiver_DB.h"
#include "cuts/Component_Registry.h"
#include "cuts/Component_Info.h"
#include "cuts/Component_Type.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/utils/DB_Connection.h"
#include "cuts/utils/DB_Query.h"
#include "cuts/utils/DB_Parameter.h"
#include "cuts/utils/DB_Exception.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_string.h"

//
// CUTS_Baseline_Archiver_DB
//
CUTS_Baseline_Archiver_DB::
CUTS_Baseline_Archiver_DB (const CUTS_Component_Registry & registry,
                           CUTS_DB_Connection & conn)
: registry_ (registry),
  info_ (0),
  conn_ (conn),
  query_ (0)
{

}

//
// ~CUTS_Baseline_Archiver_DB
//
CUTS_Baseline_Archiver_DB::~CUTS_Baseline_Archiver_DB (void)
{

}

//
// init
//
bool CUTS_Baseline_Archiver_DB::init (void)
{
  try
  {
    if (this->conn_.is_connected ())
    {
      // Verify the query does not exist. We need to destroy any
      // existence of the previous query.
      if (this->query_ != 0)
        this->query_->destroy ();

      // Create a query that will be used to insert the metrics
      // into the database.
      this->query_ = this->conn_.create_query ();

      // Prepare the insertion SQL statement.
      const char * stmt =
        "CALL cuts.insert_component_baseline_using_hostname (?,?,?,?,?,?,?,?,?)";

      if (this->query_ != 0)
        this->query_->prepare (stmt);

      // Bind the parameters of the query the correct variables.
      this->query_->parameter (0)->bind (this->hostname_, 0);
      this->query_->parameter (1)->bind (this->instance_, 0);
      this->query_->parameter (2)->bind (this->metric_type_, 0);
      this->query_->parameter (3)->bind (this->inport_, 0);
      this->query_->parameter (4)->bind (this->outport_, 0);
      this->query_->parameter (5)->bind (&this->event_count_);
      this->query_->parameter (6)->bind (&this->best_time_);
      this->query_->parameter (7)->bind (&this->worst_time_);
      this->query_->parameter (8)->bind (&this->total_time_);
      return true;
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [baseline]: not connected to database\n"));
    }
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [baseline]: %s\n",
                ex.message ().c_str ()));
  }

  return false;
}

//
// fini
//
void CUTS_Baseline_Archiver_DB::fini (void)
{
  if (this->query_ != 0)
  {
    this->query_->destroy ();
    this->query_ = 0;
  }
}

//
// visit_system_metric
//
void CUTS_Baseline_Archiver_DB::
visit_system_metric (const CUTS_System_Metric & sm)
{
  if (this->init ())
  {
    CUTS_Component_Metric_Map::
      CONST_ITERATOR iter (sm.component_metrics ());

    for (; !iter.done (); iter.advance ())
    {
      // Locate the component's registration info.
      if (this->registry_.get_component_info (iter->key (),
                                              &this->info_) == 0)
      {
        // Copy name of component into query buffer.
        ACE_OS::strncpy (this->instance_,
                         this->info_->inst_.c_str (),
                         sizeof (this->instance_));

        /// @todo Use the real hostname for baseline metrics
        ACE_OS::strncpy (this->hostname_,
                         "unknown",
                         sizeof (this->hostname_));

        if (iter->item ())
          iter->item ()->accept (*this);
      }
    }

    // Finalize the object.
    this->fini ();
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [baseline]: object not initialized\n"));
  }
}

//
// visit_component_metric
//
void CUTS_Baseline_Archiver_DB::
visit_component_metric (const CUTS_Component_Metric & cm)
{
  ACE_CString inport;
  CUTS_Port_Metric_Map::CONST_ITERATOR iter (cm.port_metrics ());

  for ( ; !iter.done (); iter.advance ())
  {
    if (this->info_->type_)
    {
      // Locate the name of this input port.
      if (this->info_->type_->sinks_.find (iter->key (), inport) == 0)
      {
        ACE_OS::strncpy (this->inport_,
                         inport.c_str (),
                         sizeof (this->inport_));
      }
    }

    // Visit the port metric.
    if (iter->item ())
      iter->item ()->accept (*this);
  }
}

//
// visit_port_metric
//
void CUTS_Baseline_Archiver_DB::
visit_port_metric (const CUTS_Port_Metric & pm)
{
  CUTS_Port_Measurement * measure = 0;

  // We are only concerned w/ the port measurements for the
  // unknown sender. All other we just ignore.
  if (pm.sender_map ().hash_map ().find (CUTS_UNKNOWN_IMPL, measure) == 0)
  {
    if (measure != 0)
      measure->accept (*this);
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [baseline]: failed to locate baseline data for "
                "%s port\n",
                this->inport_));
  }
}

//
// visit_port_measurement
//
void CUTS_Baseline_Archiver_DB::
visit_port_measurement (const CUTS_Port_Measurement & pm)
{
  ACE_CString outport;
  CUTS_Port_Measurement_Endpoint_Map::CONST_ITERATOR iter (pm.endpoints ());

  // We are going to NULL this parameter since we are inputing
  // the overall performance metrics for the port.
  this->query_->parameter (4)->null ();

  // Process the overall queueing time for the port.
  ACE_OS::strncpy (this->metric_type_, "queue", sizeof (this->metric_type_));
  pm.queuing_time ().accept (*this);

  // Process the overall service time for the port.
  ACE_OS::strncpy (this->metric_type_, "process", sizeof (this->metric_type_));
  pm.process_time ().accept (*this);

  // We are now visiting all the exit points. This means we are
  // working with 'process' metric types.
  this->query_->parameter (4)->length (0);

  for ( ; !iter.done (); iter.advance ())
  {
    if (this->info_->type_)
    {
      // Locate the name of this input port.
      if (this->info_->type_->sources_.find (iter->key (), outport) == 0)
      {
        // Copy the name of the output port into the query's buffer.
        ACE_OS::strncpy (this->outport_,
                         outport.c_str (),
                         sizeof (this->outport_));
      }
    }

    // Visit the time measurement.
    if (iter->item ())
      iter->item ()->accept (*this);
  }
}

//
// visit_time_measurement
//
void CUTS_Baseline_Archiver_DB::
visit_time_measurement (const CUTS_Time_Measurement & tm)
{
  // Store the timing metrics in the query buffers.
  this->event_count_ = tm.count ();
  this->best_time_ = tm.minimum ().msec ();
  this->worst_time_ = tm.maximum ().msec ();
  this->total_time_ = tm.total ().msec ();

  try
  {
    this->query_->execute_no_record ();
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [baseline]: %s\n",
                ex.message ().c_str ()));
  }
}
