// $Id$

#include "DBase_Service.h"
#include "cuts/Component_Info.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Time.h"

#include "cuts/utils/ODBC/ODBC_Connection.h"
#include "cuts/utils/ODBC/ODBC_Query.h"
#include "cuts/utils/ODBC/ODBC_Record.h"
#include "cuts/utils/ODBC/ODBC_Parameter.h"
#include "cuts/utils/ODBC/ODBC_Types.h"
#include "cuts/Log_Msg.h"

#include "ace/Guard_T.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/Date_Time.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/CORBA_macros.h"
#include "ace/Get_Opt.h"
#include "ace/streams.h"

#include <sstream>

#define MAX_VARCHAR_LENGTH 256

#if !defined (__CUTS_INLINE__)
#include "DBase_Service.inl"
#endif

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
: server_ ("localhost"),
  username_ ("cuts"),
  password_ ("cuts"),
  port_ (3306),
  verbose_ (false),
  test_number_ (0)
{
  // Right now we are binding directly to ODBC. In the future we would
  // like to ask the <CUTS_DB_Manager> for a connection object.
  ODBC_Connection * conn = 0;
  ACE_NEW_THROW_EX (conn, ODBC_Connection (), ACE_bad_alloc ());

  this->conn_.reset (conn);
}

//
// ~CUTS_Database_Service
//
CUTS_Database_Service::~CUTS_Database_Service (void)
{
  this->disconnect ();
}

//
// init
//
int CUTS_Database_Service::init (int argc, ACE_TCHAR * argv [])
{
  if (this->parse_args (argc, argv) != 0)
    return -1;

  VERBOSE_MESSAGE ((LM_DEBUG,
                    "connecting the database [server=%s; username=%s; "
                    "password=%s; port=%d]\n",
                    this->server_.c_str (),
                    this->username_.c_str (),
                    this->password_.c_str (),
                    this->port_));

  this->connect (this->username_.c_str (),
                 this->password_.c_str (),
                 this->server_.c_str (),
                 this->port_);
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
      break;

    case 's':
      ACE_DEBUG ((LM_DEBUG, "setting the server\n"));
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
                         "%c is missing an argument\n",
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
// connect
//
bool CUTS_Database_Service::connect (const char * username,
                                     const char * password,
                                     const char * server,
                                     long port)
{
  ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, false);

  // We need to disconnect from the existing database before
  // we can connect to another one.
  this->disconnect_i ();

  try
  {
    this->conn_->connect (username, password, server, port);
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ("*** failed to create database connection");
  }

  return this->conn_->is_connected ();
}

//
// disconnect
//
void CUTS_Database_Service::disconnect (void)
{
  ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, this->lock_);

  this->stop_current_test_i ();
  this->disconnect_i ();
}

//
// register_component
//
bool CUTS_Database_Service::
register_component (const char * uuid,
                    const char * type,
                    long regid)
{
  // Get the <type_id> for the component. We do not care if the
  // operation succeeds or fails.
  long type_id = 0;
  this->get_component_typeid (type, &type_id, true);

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());
  if (query.get () == 0)
    return false;

  long component_id = 0;

  try
  {
    this->get_instance_id (uuid, &component_id);

    // Prepare a SQL statement.
    const char * query_stmt =
      "SELECT component_id FROM component_instances WHERE component_name = ?";

    query->prepare (query_stmt);
    query->parameter (0)->bind (ACE_const_cast (char *, uuid), 0);

    CUTS_DB_Record * record = query->execute ();

    if (record->count () != 0)
    {
      // Get the id of the component from the record.
      record->fetch ();
      record->get_data (1, component_id);

      // Update the <typeid> for the component just in case.
      query_stmt =
        "UPDATE component_instances SET typeid = ? WHERE component_id = ?";

      query->prepare (query_stmt);
      query->parameter (0)->bind (&type_id);
      query->parameter (1)->bind (&component_id);

      // Execute the query.
      query->execute_no_record ();
    }
    else
    {
      // Create a new id since the component does not exist.
      query_stmt =
        "INSERT INTO component_instances (component_name, typeid) VALUES (?, ?)";

      query->prepare (query_stmt);
      query->parameter (1)->bind (&type_id);

      // Execute the statement and get the LAST_INSERT_ID ().
      query->execute_no_record ();
      component_id = query->last_insert_id ();
    }


    // Insert the {regid => component_id} into the <component_mapping_>.
    this->component_mapping_.insert (
      CUTS_DBase_Svc_Component_Map::value_type (regid, component_id));

    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ("*** failed to register component");
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception in "
                "CUTS_Database_Service::register_component\n"));
  }

  return false;
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

  if (this->test_number_ != 0 && !this->stop_current_test_i ())
    ACE_ERROR ((LM_WARNING, "[%M] -%T - cannot stop current test\n"));

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement for exection.
    const char * str_stmt =
      "INSERT INTO tests (test_number, start_time, status) "
      "VALUES (NULL, NOW(), 'active')";

    // Execute the statement and retrieve the test id, which is
    // the <last_insert_id ()> for the query.
    query->execute_no_record (str_stmt);
    this->test_number_ = query->last_insert_id ();
    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ("*** failed to create new test");
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception in "
                "CUTS_Database_Service::create_new_test\n"));
  }
  return false;
}

//
// disconnect_no_lock
//
void CUTS_Database_Service::disconnect_i (void)
{
  if (this->conn_->is_connected ())
    this->conn_->disconnect ();
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

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());
  if (query.get () == 0)
    return false;

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
    this->test_number_ = 0;
    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ("failed to stop current test");
  }
  catch (...)
  {
    CUTS_ERROR (LM_ERROR,
                "unknown exception in stop_current_test_i ()\n");
  }
  return false;
}

//
// archive_system_metrics
//
int CUTS_Database_Service::handle_metrics (void)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());

  if (query.get () == 0)
    return 0;

  long best_time,
       worse_time,
       total_time,
       metric_count,
       component,
       sender;

  char src[MAX_VARCHAR_LENGTH],
       dst[MAX_VARCHAR_LENGTH],
       metric_type[MAX_VARCHAR_LENGTH];


  try
  {
    // Convert the <timestamp> to a known type.
    ACE_Time_Value timestamp = this->metrics ().get_timestamp ();
    ACE_Date_Time ct (timestamp);
    ODBC_Date_Time datetime (ct);

    // Prepare the statement and bind all the parameters.
    const char * str_stmt =
      "INSERT INTO execution_time (test_number, collection_time, metric_type, "
      "metric_count, component, sender, src, dst, best_time, total_time, "
      "worse_time) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    query->prepare (str_stmt);
    query->parameter (0)->bind (&this->test_number_);
    query->parameter (1)->bind (&datetime);
    query->parameter (2)->bind (metric_type, 0);
    query->parameter (3)->bind (&metric_count);
    query->parameter (4)->bind (&component);
    query->parameter (5)->bind (&sender);
    query->parameter (6)->bind (src, 0);
    query->parameter (7)->bind (dst, 0);
    query->parameter (8)->bind (&best_time);
    query->parameter (9)->bind (&total_time);
    query->parameter (10)->bind (&worse_time);

    //ACE_READ_GUARD (ACE_RW_Thread_Mutex,
    //                metric_lock,
    //                this->metrics ().lock ());

    CUTS_Component_Metric_Map::const_iterator cm_iter;

    for (cm_iter  = this->metrics ().component_metrics ().begin ();
         cm_iter != this->metrics ().component_metrics ().end ();
         cm_iter ++)
    {
      // Determine if this component has any metrics that correspond
      // with the lastest timestamp for the system metrics. If it does
      // not then why bother going any further.
      if (timestamp != cm_iter->second->timestamp ())
        continue;

      component = this->component_mapping_[cm_iter->first];

      ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                             component_lock,
                             cm_iter->second->lock (),
                             0);

      // Iterate over all the ports in the <component_metric>.
      CUTS_Port_Metric_Map::const_iterator pm_iter;

      for (pm_iter  = cm_iter->second->port_metrics ().begin ();
           pm_iter != cm_iter->second->port_metrics ().end ();
           pm_iter ++)
      {
        ACE_OS::strcpy (src, pm_iter->first.c_str ());

        CUTS_Sender_Port_Map::const_iterator spm_iter;

        for (spm_iter  = pm_iter->second.begin ();
             spm_iter != pm_iter->second.end ();
             spm_iter ++)
        {
          // Determine if this port has any metrics that correspond
          // with the lastest timestamp for the system metrics. If it does
          // not then why bother going any further.
          if (timestamp != spm_iter->second->timestamp ())
            continue;

          // Copy the metrics for the process data into the appropriate
          // parameters before we execute the statement.
          sender = this->component_mapping_[spm_iter->first];

          query->parameter (7)->null ();
          metric_count = spm_iter->second->transit_time ().count ();

          ACE_OS::strcpy (metric_type, "queue");

          best_time = spm_iter->second->transit_time ().best_time ();
          worse_time = spm_iter->second->transit_time ().worse_time ();
          total_time = spm_iter->second->transit_time ().total_time ();

          // Execute the "prepared" statement using the parameters
          // we have stored.
          query->execute_no_record ();

          ACE_OS::strcpy (metric_type, "process");

          CUTS_Endpoint_Metric_Map::const_iterator em_iter;

          for (em_iter = spm_iter->second->endpoints ().begin ();
                em_iter != spm_iter->second->endpoints ().end ();
                em_iter ++)
          {
            // Determine if this port has any metrics that correspond
            // with the lastest timestamp for the system metrics. If it
            // does not then why bother going any further.
            if (this->metrics ().get_timestamp () !=
                em_iter->second->timestamp ())
            {
              continue;
            }

            // Copy the metrics for the process data into the appropriate
            // parameters before we execute the statement.
            query->parameter (7)->bind (dst, 0);

            ACE_OS::strcpy (dst, em_iter->first.c_str ());

            // Store the metrics in their parameters.
            metric_count = em_iter->second->count ();
            best_time = em_iter->second->best_time ();
            worse_time = em_iter->second->worse_time ();
            total_time = em_iter->second->total_time ();

            // Execute the "prepared" statement using the parameters
            // we have stored.
            query->execute_no_record ();
          }
        }
      }
    }
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ("failed to log metrics to database");
  }
  catch (...)
  {
    CUTS_ERROR (LM_ERROR,
                "unknown exception in handle_metrics () \n");
  }

  return 0;
}

//
// path_id
//
long CUTS_Database_Service::path_id (const char * pathname)
{
  long path_id = -1;

  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    query->prepare ("SELECT path_id FROM critical_path WHERE path_name = ?");
    query->parameter (0)->bind (ACE_const_cast (char *, pathname), 0);

    // Execute the query and get the <path_id> from the query.
    CUTS_DB_Record * record = query->execute ();

    record->fetch ();
    record->get_data (1, path_id);
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ("failed to locate path id for '%s'");
  }

  return path_id;
}

//
// register_host
//
bool CUTS_Database_Service::register_host (const char * ipaddr,
                                           const char * hostname,
                                           int * hostid)
{
  // Before we continue, we should check to see if the host has already
  // been registered. This will prevent any exceptions from occuring
  // because of duplicate data.
  long component_id = 0;

  if (this->get_host_id (ipaddr, hostname, component_id))
  {
    if (hostid != 0)
      *hostid = component_id;

    return true;
  }

  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * str_stmt =
      "INSERT INTO ipaddr_host_map (ipaddr, hostname) VALUES (?, ?)";
    query->prepare (str_stmt);

    // Bind the parameters for the statement then execute the
    // prepared statement.
    query->parameter (0)->bind (ACE_const_cast (char *, ipaddr), 0);
    query->parameter (1)->bind (ACE_const_cast (char *, hostname), 0);
    query->execute ();

    if (hostid != 0)
    {
      *hostid = query->last_insert_id ();
    }

    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ();
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception in "
                "CUTS_Database_Service::register_host\n"));
  }

  return false;
}

//
// get_host_id
//
bool CUTS_Database_Service::get_host_id (const char * ipaddr,
                                         const char * hostname,
                                         long & hostid)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * str_stmt =
      "SELECT hostid FROM ipaddr_host_map WHERE ipaddr = ? OR hostname = ?";

    query->prepare (str_stmt);
    CUTS_DB_Parameter * param = query->parameter (0);

    if (ipaddr != 0)
      param->bind (ACE_const_cast (char *, ipaddr), 0);
    else
      param->null ();

    param = query->parameter (1);
    if (hostname != 0)
      param->bind (ACE_const_cast (char *, hostname), 0);
    else
      param->null ();

    // Get the results from executing the query. If the query returns
    // nothing then this will throw an exception.
    CUTS_DB_Record * record = query->execute ();

    if (record->count () == 0)
      return false;

    record->fetch ();
    record->get_data (1, hostid);
    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ();
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception in "
                "CUTS_Database_Service::register_host\n"));
  }
  return false;
}

//
// set_component_uptime
//
bool CUTS_Database_Service::set_component_uptime (long cid,
                                                  long hostid)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());

  if (query.get () == 0)
    return false;

  try
  {
    CUTS_DBase_Svc_Component_Map::const_iterator iter =
      this->component_mapping_.find (cid);

    cid = iter != this->component_mapping_.end () ? iter->second : 0;

    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * query_stmt =
      "INSERT INTO deployment_table (test_number, instance, hostid, uptime) "
      "VALUES (?, ?, ?, NOW())";

    query->prepare (query_stmt);
    query->parameter (0)->bind (&this->test_number_);
    query->parameter (1)->bind (&cid);
    query->parameter (2)->bind (&hostid);

    // Execute the SQL query.
    query->execute_no_record ();
    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ();
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception in "
                "CUTS_Database_Service::set_component_uptime\n"));
  }
  return false;
}

//
// set_component_downtime
//
bool CUTS_Database_Service::set_component_downtime (long cid)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());
  if (query.get () == 0)
    return false;

  try
  {
    SQLINTEGER _test_number = 0,
                _instance = 0;

    query->parameter (0)->bind (&this->test_number_);
    query->parameter (1)->bind (&cid);

    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * str_stmt =
      "UPDATE deployment_table SET downtime = NOW() "
      "WHERE test_number = ? AND instance = ?";

    query->prepare (str_stmt);
    query->execute_no_record ();
    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ();
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception in "
                "CUTS_Database_Service::set_component_downtime\n"));
  }

  return false;
}

//
// get_component_id
//
bool CUTS_Database_Service::get_instance_id (const char * uuid,
                                             long * dest,
                                             bool auto_register)
{
  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());

  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * query_stmt =
      "SELECT component_id FROM component_instances WHERE component_name = ?";

    query->prepare (query_stmt);
    query->parameter (0)->bind (ACE_const_cast (char *, uuid), 0);

    // Execute the statement and get the returned id.
    CUTS_DB_Record * record = query->execute ();

    // Even if the client doesn't want to store the id, we
    // still have to go thro

    if (dest != 0)
    {
      record->fetch ();
      record->get_data (1, *dest);
      return true;
    }
    else
      return record->count () != 0;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ("failed to get instance id");
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - unknown exception in "
                "CUTS_Database_Service::get_instance_id\n"));
  }

  return false;
}

//
// create_new_query
//
ODBC_Query *
CUTS_Database_Service::create_new_query (void)
{
  if (!this->conn_->is_connected ())
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "[%M] -%T - no database connection exist\n"),
                       0);
  }

  return this->conn_->create_odbc_query ();
}

//
// get_component_type_id
//
bool CUTS_Database_Service::
get_component_typeid (const char * type,
                      long * type_id,
                      bool auto_register)
{
  ACE_Auto_Ptr <ODBC_Query> query (this->create_new_query ());

  if (query.get () == 0)
    return false;

  try
  {
    // Prepare a SQL query for execution.
    const char * query_stmt =
      "SELECT typeid FROM component_types WHERE typename = ?";
    query->prepare (query_stmt);
    query->parameter (0)->bind (ACE_const_cast (char *, type), 0);

    // Execute the query.
    CUTS_DB_Record * record = query->execute ();

    if (record->count () != 0)
    {
      // Extract the data from the record.
      long type_id_;
      record->fetch ();
      record->get_data (1, type_id_);

      // Save the information in the output buffer.
      if (type_id != 0)
        *type_id = type_id_;
    }
    else
    {
      if (auto_register)
      {
        // Insert the <typename> into the database.
        query_stmt = "INSERT INTO component_types (typename) VALUES (?)";
        query->prepare (query_stmt);
        query->execute_no_record ();

        // Get the LAST_INSERT_ID () and store it in <type_id>.
        if (type_id != 0)
          *type_id = query->last_insert_id ();

        return true;
      }
      else
        return false;
    }
    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ex.print ();
  }
  catch (...)
  {
    CUTS_ERROR (LM_ERROR,
                "unknown exception in get_component_type_id ()\n");
  }

  return false;
}

//
// handle_component
//
int CUTS_Database_Service::
handle_component (const CUTS_Component_Info & info)
{
  if (info.state_ == 1)
    this->register_component (info.inst_.c_str (),
                              "Unknown",
                              info.uid_);
  return 0;
}

//
// fini
//
int CUTS_Database_Service::fini (void)
{
  this->disconnect ();
  return CUTS_BDC_Service::fini ();
}

