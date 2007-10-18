// $Id$

#include "DBase_Service.h"

#if !defined (__CUTS_INLINE__)
#include "DBase_Service.inl"
#endif

#include "cuts/Auto_Functor_T.h"
#include "cuts/Component_Info.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Info.h"
#include "cuts/Component_Metric.h"
#include "cuts/Component_Type.h"
#include "cuts/Host_Table_Entry.h"
#include "cuts/Port_Metric.h"
#include "cuts/Time.h"
#include "cuts/Testing_Service.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "cuts/utils/ODBC/ODBC_Connection.h"
#include "cuts/utils/DB_Query.h"
#include "cuts/utils/DB_Record.h"
#include "cuts/utils/DB_Parameter.h"
#include "cuts/utils/ODBC/ODBC_Types.h"

#include "ace/Guard_T.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/Date_Time.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/Get_Opt.h"

#define MAX_VARCHAR_LENGTH 256

CUTS_BDC_SERVICE_IMPL (CUTS_Database_Service);

#define VERBOSE_MESSAGE(msg) \
  if (this->verbose_) \
  { \
    ACE_ERROR (msg); \
  }

#define VERBOSE_MESSAGE_RETURN(msg) \
  if (this->verbose_) \
  { \
    ACE_ERROR_RETURN (msg); \
  }

//
// CUTS_Database_Service
//
CUTS_Database_Service::CUTS_Database_Service (void)
: verbose_ (false),
  server_ (CUTS_DEFAULT_HOSTNAME),
  username_ (CUTS_USERNAME),
  password_ (CUTS_PASSWORD),
  port_ (CUTS_DEFAULT_PORT),
  test_number_ (-1),
  enable_deployment_ (false)
{
  CUTS_DB_Connection * conn = 0;
  ACE_NEW (conn, ODBC_Connection ());
  this->conn_.reset (conn);
}

//
// ~CUTS_Database_Service
//
CUTS_Database_Service::~CUTS_Database_Service (void)
{

}

//
// init
//
int CUTS_Database_Service::init (int argc, ACE_TCHAR * argv [])
{
  if (this->parse_args (argc, argv) != 0)
    return -1;

  this->conn_->connect (this->username_.c_str (),
                        this->password_.c_str (),
                        this->server_.c_str (),
                        this->port_);

  if (this->conn_->is_connected ())
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [archive]: successfully connected to "
                      "database on %s\n",
                      this->server_.c_str ()));

    this->registry_.attach (this->conn_.get ());
    return true;
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: failed to connect to database "
                "[server=%s;username=%s;password=%s;port=%d]\n",
                this->server_.c_str (),
                this->username_.c_str (),
                this->password_.c_str (),
                this->port_));

    return false;
  }
}

//
// fini
//
int CUTS_Database_Service::fini (void)
{
  // Remove the connection from the registry.
  this->registry_.detach ();

  // Disconnect from the database.
  this->conn_->disconnect ();

  return 0;
}

//
// parse_args
//
int CUTS_Database_Service::parse_args (int argc, ACE_TCHAR * argv [])
{
  const char * opts = ACE_TEXT ("s:p:");
  ACE_Get_Opt get_opt (argc, argv, opts, 0);

  get_opt.long_option ("server", 's', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("port", 'p', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("enable-deployment", ACE_Get_Opt::NO_ARG);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "server") == 0)
      {
        this->server_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "port") == 0)
      {
        this->port_ = ACE_OS::atoi (get_opt.opt_arg ());
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
      {
        this->verbose_ = true;
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "enable-deployment") == 0)
      {
        this->enable_deployment_ = true;
      }
      break;

    case 's':
      this->server_ = get_opt.opt_arg ();
      break;

    case 'p':
      this->port_ = ACE_OS::atoi (get_opt.opt_arg ());
      break;

    case '?':
      // unknown option; do nothing
      break;

    case ':':
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [archive]: %c is missing an argument\n",
                         get_opt.opt_opt ()),
                         1);
      break;

    default:
      /* do nothing */;
    }
  }

  return 0;
}

//
// create_new_test
//
bool CUTS_Database_Service::create_new_test (void)
{
  ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex,
                          guard,
                          this->lock_,
                          false);

  if (this->test_number_ != -1 && !this->stop_current_test_i ())
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error [archive]: cannot stop current test\n"),
                       false);
  }

  CUTS_Auto_Functor_T <CUTS_DB_Query>
    query (this->conn_->create_query (), &CUTS_DB_Query::destroy);

  try
  {
    // Prepare the statement for exection.
    const char * str_stmt =
      "INSERT INTO tests (start_time, status) VALUES (NOW(), 'active')";

    // Execute the statement and get the last inserted id.
    query->execute_no_record (str_stmt);
    this->test_number_ = query->last_insert_id ();
    return true;
  }
  catch (const CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: %s\n"
                "*** error [archive]: failed to create new test\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: unknown exception caught; "
                "failed to create new test\n"));
  }

  return false;
}

//
// stop_current_test
//
bool CUTS_Database_Service::stop_current_test (void)
{
  ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex,
                          guard,
                          this->lock_,
                          false);

  return this->stop_current_test_i ();
}

//
// stop_current_test_i
//
bool CUTS_Database_Service::stop_current_test_i (void)
{
  if (this->test_number_ == 0)
    return true;

  CUTS_Auto_Functor_T <CUTS_DB_Query>
    query (this->conn_->create_query (), &CUTS_DB_Query::destroy);

  try
  {
    const char * str_stmt =
      "UPDATE tests SET stop_time = NOW(), status = 'inactive' "
      "WHERE (test_number = ?)";

    // Create the binding for initializing a test.
    query->prepare (str_stmt);
    query->parameter (0)->bind (&this->test_number_);

    // Execute the statement and reset the test number.
    query->execute_no_record ();
    this->test_number_ = -1;

    return true;
  }
  catch (const CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: %s\n"
                "*** error [archive]: failed to stop current test\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: caught unknown exception\n"
                "*** error [archive]: failed to stop current test\n"));
  }

  return false;
}

//
// handle_metrics
//
int CUTS_Database_Service::
handle_metrics (const CUTS_System_Metric & metrics)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);

  CUTS_Auto_Functor_T <CUTS_DB_Query>
    query (this->conn_->create_query (), &CUTS_DB_Query::destroy);

  long best_time,
       worse_time,
       total_time,
       metric_count;

  char src[MAX_VARCHAR_LENGTH],
       dst[MAX_VARCHAR_LENGTH],
       metric_type[MAX_VARCHAR_LENGTH],
       component[MAX_VARCHAR_LENGTH],
       sender[MAX_VARCHAR_LENGTH];

  try
  {
    // Convert the <timestamp> to a known type.
    ACE_Time_Value timestamp = metrics.get_timestamp ();
    ACE_Date_Time ct (timestamp);

    ODBC_Date_Time datetime (ct);

    // Prepare the statement and bind all the parameters.
    const char * str_stmt =
      "CALL insert_execution_time (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    // Get the component registry for this service.
    const CUTS_Component_Registry & registry =
      this->svc_mgr ()->testing_service ()->registry ();

    query->prepare (str_stmt);
    query->parameter (0)->bind (&this->test_number_);
    query->parameter (1)->bind (&datetime);
    query->parameter (2)->bind (metric_type, 0);
    query->parameter (3)->bind (&metric_count);
    query->parameter (4)->bind (component, 0);
    query->parameter (5)->bind (sender, 0);
    query->parameter (6)->bind (src, 0);
    query->parameter (7)->bind (dst, 0);
    query->parameter (8)->bind (&best_time);
    query->parameter (9)->bind (&total_time);
    query->parameter (10)->bind (&worse_time);

    CUTS_Component_Metric_Map::
      CONST_ITERATOR cm_iter (metrics.component_metrics ());

    ACE_CString portname;
    const CUTS_Component_Info * myinfo = 0,
                              * sender_info = 0;

    for (cm_iter; !cm_iter.done (); cm_iter ++)
    {
      // Determine if this component has any metrics that correspond
      // with the lastest timestamp for the system metrics. If it does
      // not then why bother going any further.
      if (timestamp != cm_iter->item ()->timestamp ())
        continue;

      if (registry.get_component_info (cm_iter->key (), &myinfo) == -1)
        continue;

      // Copy the name of the component into the buffer.
      ACE_OS::strncpy (component, myinfo->inst_.c_str (), MAX_VARCHAR_LENGTH);

      // Iterate over all the ports in the <component_metric>.
      CUTS_Port_Metric_Map::
        CONST_ITERATOR pm_iter (cm_iter->item ()->port_metrics ());

      for (pm_iter; !pm_iter.done (); pm_iter ++)
      {
        // Copy the name of the source port, which is a event source,
        // into its corresponding buffer.
        myinfo->type_->sinks_.find (pm_iter->key (), portname);
        ACE_OS::strncpy (src, portname.c_str (), MAX_VARCHAR_LENGTH);

        CUTS_Port_Measurement_Map::
          CONST_ITERATOR sender_iter (pm_iter->item ()->sender_map ().hash_map ());

        for (sender_iter; !sender_iter.done (); sender_iter ++)
        {
          // Determine if this port has any metrics that correspond
          // with the lastest timestamp for the system metrics. If it does
          // not then why bother going any further.
          if (timestamp != sender_iter->item ()->timestamp ())
            continue;

          // Get the sender's information and copy it into the buffer.
          if (registry.get_component_info (sender_iter->key (),
                                           &sender_info) == 0)
          {
            ACE_OS::strncpy (sender,
                             sender_info->inst_.c_str (),
                             MAX_VARCHAR_LENGTH);
          }
          else
          {
            ACE_OS::strcpy (sender, "Unknown");
          }

          // For the next set of queries we are going to have a <nil>
          // destination. This will mean
          query->parameter (7)->null ();

          // We are going to archive the overall queuing time for the
          // current port.
          ACE_OS::strcpy (metric_type, "queue");
          best_time = sender_iter->item ()->queuing_time ().minimum ().msec ();
          worse_time = sender_iter->item ()->queuing_time ().maximum ().msec ();
          total_time = sender_iter->item ()->queuing_time ().total ().msec ();
          metric_count = sender_iter->item ()->queuing_time ().count ();

          query->execute_no_record ();

          // We are going to archive the overall processing time for the
          // current port.
          ACE_OS::strcpy (metric_type, "process");
          best_time = sender_iter->item ()->process_time ().minimum ().msec ();
          worse_time = sender_iter->item ()->process_time ().maximum ().msec ();
          total_time = sender_iter->item ()->process_time ().total ().msec ();
          metric_count = sender_iter->item ()->process_time ().count ();

          query->execute_no_record ();

          // Now, we can reset the <dst> parameter so we know we are
          // logging metrics specific to a port.
          query->parameter (7)->length (0);

          CUTS_Port_Measurement_Endpoint_Map::
            CONST_ITERATOR em_iter (sender_iter->item ()->endpoints ());

          for (; !em_iter.done (); em_iter ++)
          {
            // Determine if this port has any metrics that corresponds
            // with the lastest timestamp for the system metrics. If it
            // does not then why bother going any further.
            if (timestamp != em_iter->item ()->timestamp ())
              continue;

            // Copy the name of the destination port, which is a event
            // source, into its corresponding buffer.
            myinfo->type_->sources_.find (em_iter->key (), portname);
            ACE_OS::strcpy (dst, portname.c_str ());

            // Store the metrics in their parameters.
            metric_count = em_iter->item ()->count ();
            best_time  = em_iter->item ()->minimum ().msec ();
            worse_time = em_iter->item ()->maximum ().msec ();
            total_time = em_iter->item ()->total ().msec ();

            query->execute_no_record ();
          }
        }
      }
    }

    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [archive]: successfully archived metrics\n"));
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: %s\n"
                "*** error [archive]: aborting archiving operation\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: caught unknown exception\n"
                "*** error [archive]: aborting archiving operation\n"));
  }

  return 0;
}

//
// handle_component
//
int CUTS_Database_Service::
handle_component (const CUTS_Component_Info & info)
{
  if (info.state_ == CUTS_Component_Info::STATE_ACTIVATE)
  {
    if (this->registry_.register_component (info, 0))
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [archive]: successfully registered "
                        "component %s\n",
                        info.inst_.c_str ()));
    }
    else
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [archive]: failed to register component %s\n",
                         info.inst_.c_str ()),
                         -1);
    }

    // Set component's uptime in deployment table if allowed.
    if (this->enable_deployment_)
      this->set_component_uptime (info);
  }
  else if (info.state_ == CUTS_Component_Info::STATE_PASSIVATE)
  {
    // Set component's downtime in deployment table if allowed.
    if (this->enable_deployment_)
      this->set_component_downtime (info);
  }

  return 0;
}

//
// handle_activate
//
int CUTS_Database_Service::handle_activate (void)
{
  // Create a new test in the database.
  if (!this->create_new_test ())
    return -1;

  return this->set_test_uuid () ? 0 : -1;
}

//
// set_test_uuid_i
//
bool CUTS_Database_Service::set_test_uuid (void)
{
  try
  {
    // Associate that test with the UUID of the service manager.
    CUTS_Auto_Functor_T <CUTS_DB_Query>
      query (this->conn_->create_query (), &CUTS_DB_Query::destroy);

    // Prepare a SQL query for execution.
    const char * query_stmt =
      "UPDATE tests SET test_uuid = ? WHERE test_number = ?";

    char * uuid = const_cast <char *> (this->svc_mgr ()->get_uuid ().c_str ());

    query->prepare (query_stmt);
    query->parameter (0)->bind (uuid, 0);
    query->parameter (1)->bind (&this->test_number_);

    // Execute the query.
    query->execute_no_record ();

    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: %s\n",
                ex.message ().c_str ()));
  }

  return false;
}

//
// set_component_uptime
//
void CUTS_Database_Service::
set_component_uptime (const CUTS_Component_Info & info)
{
  try
  {
    CUTS_Auto_Functor_T <CUTS_DB_Query>
      query (this->conn_->create_query (), &CUTS_DB_Query::destroy);

    const char * stmt =
      "CALL cuts.set_component_uptime_using_hostname (?,?,?)";

    char hostname[256];
    char instance[256];

    // Prepare the statement and it's parameters.
    query->prepare (stmt);
    query->parameter (0)->bind (&this->test_number_);
    query->parameter (1)->bind (instance, 0);
    query->parameter (2)->bind (hostname, 0);

    // Copy the strings into the parameter buffers.
    ACE_OS::strncpy (hostname,
                     info.host_info_->hostname_.c_str (),
                     sizeof (hostname));

    ACE_OS::strncpy (instance,
                     info.inst_.c_str (),
                     sizeof (instance));

    // Execute the query.
    query->execute_no_record ();

    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [archive]: successfully set uptime "
                      "for <%s> on <%s>\n",
                      instance,
                      hostname))
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: %s\n",
                ex.message ().c_str ()));
  }
}

//
// set_component_downtime
//
void CUTS_Database_Service::
set_component_downtime (const CUTS_Component_Info & info)
{
  try
  {
    CUTS_Auto_Functor_T <CUTS_DB_Query>
      query (this->conn_->create_query (), &CUTS_DB_Query::destroy);

    const char * stmt =
      "CALL cuts.set_component_downtime_using_hostname (?,?,?)";

    char hostname[256];
    char instance[256];

    // Prepare the statement and it's parameters.
    query->prepare (stmt);
    query->parameter (0)->bind (&this->test_number_);
    query->parameter (1)->bind (instance, 0);
    query->parameter (2)->bind (hostname, 0);

    // Copy the strings into the parameter buffers.
    ACE_OS::strncpy (hostname,
                     info.host_info_->hostname_.c_str (),
                     sizeof (hostname));

    ACE_OS::strncpy (instance,
                     info.inst_.c_str (),
                     sizeof (instance));

    // Execute the query.
    query->execute_no_record ();

    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [archive]: successfully set downtime "
                      "for <%s> on <%s>\n",
                      instance,
                      hostname))
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [archive]: %s\n",
                ex.message ().c_str ()));
  }
}
