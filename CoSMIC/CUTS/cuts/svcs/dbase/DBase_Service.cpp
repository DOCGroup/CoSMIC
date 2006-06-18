// $Id: DBase_Service.cpp,v 1.1.4.9.2.3 2006/06/11 18:59:25 hillj Exp $

#include "DBase_Service.h"
#include "cuts/utils/ODBC_Stmt.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Time.h"

#include "ace/Guard_T.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/Date_Time.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_time.h"

#include <sstream>

#define MAX_VARCHAR_LENGTH 256

#if !defined (__CUTS_INLINE__)
#include "DBase_Service.inl"
#endif

//
// get_current_time
//
static void get_current_time (SQL_TIMESTAMP_STRUCT & timestamp)
{
  // Get the current date/time and store it in the <timestamp>
  ACE_Date_Time date_time;

  timestamp.month   = static_cast <SQLUSMALLINT> (date_time.month ());
  timestamp.day     = static_cast <SQLUSMALLINT> (date_time.day ());
  timestamp.year    = static_cast <SQLSMALLINT>  (date_time.year ());
  timestamp.hour    = static_cast <SQLUSMALLINT> (date_time.hour ());
  timestamp.minute  = static_cast <SQLUSMALLINT> (date_time.minute ());
  timestamp.second  = static_cast <SQLUSMALLINT> (date_time.second ());
}

//
// operator << (SQL_TIMESTAMP_STRUCT &, ACE_Time_Value &)
//
static void operator << (SQL_TIMESTAMP_STRUCT & ts, const ACE_Time_Value & tv)
{
  // Create a <ACE_Date_Time> object to simplify the conversion
  // process between the two types.
  ACE_Date_Time date_time (tv);

  ts.month   = static_cast <SQLUSMALLINT> (date_time.month ());
  ts.day     = static_cast <SQLUSMALLINT> (date_time.day ());
  ts.year    = static_cast <SQLSMALLINT>  (date_time.year ());
  ts.hour    = static_cast <SQLUSMALLINT> (date_time.hour ());
  ts.minute  = static_cast <SQLUSMALLINT> (date_time.minute ());
  ts.second  = static_cast <SQLUSMALLINT> (date_time.second ());
}

//
// CUTS_Database_Service
//
CUTS_Database_Service::CUTS_Database_Service (void)
: test_number_ (0)
{

}

//
// ~CUTS_Database_Service
//
CUTS_Database_Service::~CUTS_Database_Service (void)
{
  this->disconnect ();
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
  this->disconnect_no_lock ();

  ACE_DEBUG ((LM_INFO,
              "[%M] -%T - connecting to the database on %s\n",
              server));

  this->conn_.connect (username, password, server, port);
  return this->conn_.is_connected ();
}

//
// disconnect
//
void CUTS_Database_Service::disconnect (void)
{
  ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, this->lock_);
  this->stop_current_test_i ();
  this->disconnect_no_lock ();
}

//
// register_component
//
bool CUTS_Database_Service::register_component (long regid,
                                                const char * uuid)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  if (this->conn_.is_connected ())
  {
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());
    long component_id = 0;

    try
    {
      SQLINTEGER _uuid = SQL_NTS;
      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
                            0, 0, (SQLCHAR *)uuid, 0, &_uuid);

      // Prepare the statement to select the component_id of the component
      // with the specified name.
      stmt->prepare (
      "SELECT component_id FROM component_instances WHERE component_name = ?");
      stmt->execute ();

      try
      {
        // Get the component id from the query statement.
        stmt->fetch ();
        stmt->get_data (1,
                        &component_id,
                        sizeof (component_id),
                        0,
                        SQL_C_LONG);
      }
      catch (ODBC_Stmt_Exception &)
      {
        // The component name does not exist. So we have to prepare
        // the statement that will create a new id for the component.
        stmt->prepare (
          "INSERT INTO component_instances (component_name) VALUES (?)");
        stmt->execute ();

        component_id = stmt->last_insert_id ();
      }

      // Insert the {regid => component_id} into the <component_mapping_>.
      this->component_mapping_.insert (
        CUTS_DBase_Svc_Component_Map::value_type (regid, component_id));

      ACE_DEBUG ((LM_DEBUG,
                  "%s has instance id of %u\n",
                  uuid,
                  component_id));

      return true;
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - %s\n",
                  ex.message ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - unknown exception in "
                  "CUTS_Database_Service::register_component\n"));
    }
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - no database connection exist\n"));
  }

  return false;
}

//
// create_new_test
//
bool CUTS_Database_Service::create_new_test (void)
{
  // We get a write guard to the mutex because the <test_number_> is
  // a vital part of preserving data intergity. We do not want any
  // activity taking place while we are making any updates that will
  // affect where metrics are being logged.
  ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex,
                          guard,
                          this->lock_,
                          false);

  if (this->conn_.is_connected ())
  {
    if (this->test_number_ != 0 &&
        !this->stop_current_test_i ())
    {
      ACE_ERROR ((LM_NOTICE,
                  "[%M] -%T - cannot stop current test; "
                  "it must be stopped manually\n"));
    }

    // Create a new <ODBC_Stmt> using the existing connection.
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());

    // Convert the <tm> to a <SQL_TIMESTAMP_STRUCT> type.
    SQL_TIMESTAMP_STRUCT test_time;
    get_current_time (test_time);

    SQLINTEGER _test_time = 0;

    try
    {
      // Create the binding for initializing a test.
      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP,
        SQL_TYPE_TIMESTAMP, 0, 0, &test_time, 0, &_test_time);

      const char * str_stmt =
        "INSERT INTO tests (test_number, start_time, status) "
        "VALUES (NULL, ?, 'active')";

      // Switch to the <cuts> directory.
      stmt->exec_direct ("use cuts");

      ACE_DEBUG ((LM_INFO,
                  "[%M] -%T - creating a new test\n"));

      // Prepare and execute the <str_stmt>.
      stmt->prepare (str_stmt);
      stmt->execute ();

      this->test_number_ = stmt->last_insert_id ();
      return true;
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - %s\n"
                  "[%M] -%T - failed to create new test id\n",
                  ex.message ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - unknown exception in "
                  "CUTS_Database_Service::create_new_test\n"));
    }
  }
  else
  {
    ACE_ERROR ((LM_WARNING,
                "[%M] -%T - no database connection exist\n"));
  }

  return false;
}

//
// disconnect_no_lock
//
void CUTS_Database_Service::disconnect_no_lock (void)
{
  if (this->conn_.is_connected ())
  {
    this->conn_.disconnect ();
  }
}

//
// stop_current_test
//
bool CUTS_Database_Service::stop_current_test (void)
{
  // We get a write guard to the mutex because the <test_number_> is
  // a vital part of preserving data intergity. We do not want any
  // activity taking place while we are making any updates that will
  // affect where metrics are being logged.
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
  if (this->test_number_ != 0 &&
      this->conn_.is_connected ())
  {
    // Create a new <ODBC_Stmt> using the existing connection.
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());

    // Get the <current_time> of the archiving.
    SQL_TIMESTAMP_STRUCT test_time;
    get_current_time (test_time);

    SQLINTEGER _test_time = 0, _test_number = 0;

    try
    {
      const char * str_stmt =
        "UPDATE tests SET stop_time = ?, status = 'inactive' "
        "WHERE (test_number = ?)";

      // Create the binding for initializing a test.
      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP,
        SQL_TYPE_TIMESTAMP, 0, 0, &test_time, 0, &_test_time);

      // Create the binding for initializing a test.
      stmt->bind_parameter (2, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &this->test_number_, 0, &_test_number);

      // Switch to the <cuts> directory.
      stmt->exec_direct ("use cuts");
      stmt->prepare (str_stmt);
      stmt->execute ();

      // Reset the <test_number_>.
      this->test_number_ = 0;
      return true;
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((
        LM_ERROR,
        ACE_TEXT ("[%M] -%T - %s\n")
        ACE_TEXT ("[%M] -%T - failed to insert stop time for test %u\n"),
        ex.message (),
        this->test_number_));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("[%M] -%T - unknown exception in ")
                  ACE_TEXT ("CUTS_Database_Service::stop_current_test_i\n")));
    }
  }
  else
  {
    ACE_ERROR ((LM_WARNING,
                ACE_TEXT ("[%M] -%T - no database connection exist\n")));
  }

  return false;
}

//
// archive_system_metrics
//
bool CUTS_Database_Service::archive_system_metrics (
  CUTS_System_Metric & metrics)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  if (this->conn_.is_connected ())
  {
    // Convert the <timestamp> on the <metrics> to a <SQL_TIMESTAMP_STURCT>
    // for logging of the system metrics.
    SQL_TIMESTAMP_STRUCT collection_time;
    collection_time << metrics.timestamp ();

    SQLINTEGER best_time,
               worse_time,
               average_time,
               metric_count,
               component,
               sender;

    SQLCHAR src[MAX_VARCHAR_LENGTH],
            dst[MAX_VARCHAR_LENGTH],
            metric_type[MAX_VARCHAR_LENGTH];

    SQLINTEGER  _test_id = 0,
                _best_time = 0,
                _worse_time = 0,
                _average_time = 0,
                _metric_count = 0,
                _src = SQL_NTS,
                _dst = SQL_NTS,
                _metric_type = SQL_NTS,
                _component = SQL_NTS,
                _sender = SQL_NTS,
                _collection_time = 0;

    // Create a new <stmt> for the data entry.
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());

    try
    {
      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &this->test_number_, 0, &_test_id);

      stmt->bind_parameter (2, SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP,
        SQL_TYPE_TIMESTAMP, 0, 0, &collection_time, 0, &_collection_time);

      stmt->bind_parameter (3, SQL_PARAM_INPUT, SQL_C_CHAR,
        SQL_CHAR, 0, 0, &metric_type, 0, &_metric_type);

      stmt->bind_parameter (4, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &metric_count, 0, &_metric_count);

      stmt->bind_parameter (5, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &component, 0, &_component);

      stmt->bind_parameter (6, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &sender, 0, &_sender);

      stmt->bind_parameter (7, SQL_PARAM_INPUT, SQL_C_CHAR,
        SQL_CHAR, 0, 0, &src, 0, &_src);

      stmt->bind_parameter (8, SQL_PARAM_INPUT, SQL_C_CHAR,
        SQL_CHAR, 0, 0, &dst, 0, &_dst);

      stmt->bind_parameter (9, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &best_time, 0, &_best_time);

      stmt->bind_parameter (10, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &average_time, 0, &_average_time);

      stmt->bind_parameter (11, SQL_PARAM_INPUT, SQL_C_LONG,
        SQL_INTEGER, 0, 0, &worse_time, 0, &_worse_time);

      ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                            metric_lock,
                            metrics.lock (),
                            false);

      const char * METRICS_INSERT_STMT =
        "INSERT INTO execution_time (test_number, collection_time, metric_type, "
        "metric_count, component, sender, src, dst, best_time, average_time, "
        "worse_time) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

      stmt->exec_direct ("use cuts");
      stmt->prepare (METRICS_INSERT_STMT);

      CUTS_Component_Metric_Map::const_iterator cm_iter;

      for (cm_iter  = metrics.component_metrics ().begin ();
           cm_iter != metrics.component_metrics ().end ();
           cm_iter ++)
      {
        // Determine if this component has any metrics that correspond
        // with the lastest timestamp for the system metrics. If it does
        // not then why bother going any further.
        if (metrics.timestamp () != cm_iter->second->timestamp ())
        {
          continue;
        }

        component = this->component_mapping_[cm_iter->first];

        ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                              component_lock,
                              cm_iter->second->lock (),
                              false);

        // Iterate over all the ports in the <component_metric>.
        CUTS_Port_Metric_Map::const_iterator pm_iter;

        for (pm_iter  = cm_iter->second->port_metrics ().begin ();
             pm_iter != cm_iter->second->port_metrics ().end ();
             pm_iter ++)
        {
          ACE_OS::strcpy (reinterpret_cast <char *> (src),
                          pm_iter->first.c_str ());

          CUTS_Sender_Port_Map::const_iterator spm_iter;

          for (spm_iter  = pm_iter->second.begin ();
               spm_iter != pm_iter->second.end ();
               spm_iter ++)
          {
            // Determine if this port has any metrics that correspond
            // with the lastest timestamp for the system metrics. If it does
            // not then why bother going any further.
            if (metrics.timestamp () != spm_iter->second->timestamp ())
            {
              continue;
            }

            // Copy the metrics for the process data into the appropriate
            // parameters before we execute the statement.
            sender = this->component_mapping_[spm_iter->first];

            _dst = SQL_NULL_DATA;
            metric_count = spm_iter->second->transit_time ().count ();

            ACE_OS::strcpy (reinterpret_cast <char *> (metric_type),
                            "transit");

            best_time = spm_iter->second->transit_time ().best_time ();
            worse_time = spm_iter->second->transit_time ().worse_time ();
            average_time = spm_iter->second->transit_time ().average_time ();

            // Execute the "prepared" statement using the parameters
            // we have stored.
            stmt->execute ();

            ACE_OS::strcpy (reinterpret_cast <char *> (metric_type),
                            "process");

            CUTS_Endpoint_Metric_Map::const_iterator em_iter;

            for (em_iter = spm_iter->second->endpoints ().begin ();
                 em_iter != spm_iter->second->endpoints ().end ();
                 em_iter ++)
            {
              // Determine if this port has any metrics that correspond
              // with the lastest timestamp for the system metrics. If it
              // does not then why bother going any further.
              if (metrics.timestamp () != em_iter->second->timestamp ())
              {
                continue;
              }

              // Copy the metrics for the process data into the appropriate
              // parameters before we execute the statement.
              _dst = SQL_NTS;

              ACE_OS::strcpy (reinterpret_cast <char *> (dst),
                              em_iter->first.c_str ());

              // Store the metrics in their parameters.
              metric_count = em_iter->second->count ();
              best_time = em_iter->second->best_time ();
              worse_time = em_iter->second->worse_time ();
              average_time = em_iter->second->average_time ();

              // Execute the "prepared" statement using the parameters
              // we have stored.
              stmt->execute ();
            }
          }
        }
      }

      return true;
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("[%M] -%T - %s\n")
                  ACE_TEXT ("[%M] -%T - failed to archive metrics\n"),
                  ex.message ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("[%M] -%T - unknown exception in ")
                  ACE_TEXT ("CUTS_Database_Service::archive_system_metrics\n")));
    }
  }
  else
  {
    ACE_ERROR ((LM_WARNING,
                ACE_TEXT ("[%M] -%T - no database connection exist; ")
                ACE_TEXT ("failed to archive metrics\n")));
  }

  return false;
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
                         path_id);

  if (this->conn_.is_connected ())
  {
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());

    try
    {
      SQLINTEGER _pathname = SQL_NTS;
      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
                            0, 0, (SQLCHAR *)pathname, 0, &_pathname);

      // Prepare the statement to select the component_id of the component
      // with the specified name.
      stmt->prepare ("SELECT path_id FROM critical_path WHERE path_name = ?");
      stmt->execute ();

      // Get the <path_id> from the query.
      stmt->fetch ();
      stmt->get_data (1, path_id);
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("[%M] -%T - %s\n")
                  ACE_TEXT ("[%M] -%T - failed to locate path id for '%s'\n"),
                  ex.message (),
                  pathname));
    }
  }

  return path_id;
}

//
// register_host
//
bool CUTS_Database_Service::register_host (const char * ipaddr,
                                           const char * hostname)
{
  // Before we continue, we should check to see if the host has already
  // been registered. This will prevent any exceptions from occuring
  // because of duplicate data.
  int hostid = 0;

  if (this->get_host_id_by_addr (ipaddr, hostid))
  {
    return true;
  }

  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  if (this->conn_.is_connected ())
  {
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());
    long component_id = 0;

    try
    {
      SQLINTEGER _ipaddr = SQL_NTS,
                 _hostname = SQL_NTS;

      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
                            0, 0, (SQLCHAR *)ipaddr, 0, &_ipaddr);
      stmt->bind_parameter (2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
                            0, 0, (SQLCHAR *)hostname, 0, &_hostname);

      // Prepare the statement to select the component_id of the component
      // with the specified name.
      const char * str_stmt =
        "INSERT INTO ipaddr_host_map (ipaddr, hostname) VALUES (?, ?)";

      stmt->prepare (str_stmt);
      stmt->execute ();
      return true;
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - (%s:%u) %s\n",
                  ex.state ().c_str (),
                  ex.native (),
                  ex.message ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - unknown exception in "
                  "CUTS_Database_Service::register_host\n"));
    }
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - no database connection exist\n"));
  }

  return false;
}

//
// get_host_id
//
bool CUTS_Database_Service::get_host_id_by_addr (const char * ipaddr,
                                                 int & hostid)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  if (this->conn_.is_connected ())
  {
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());

    try
    {
      SQLINTEGER _ipaddr = SQL_NTS;

      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
                            0, 0, (SQLCHAR *)ipaddr, 0, &_ipaddr);

      // Prepare the statement to select the component_id of the component
      // with the specified name.
      const char * str_stmt =
        "SELECT hostid FROM ipaddr_host_map WHERE ipaddr = ?";
      stmt->prepare (str_stmt);
      stmt->execute ();

      // Get the results from executing the query. If the query returns
      // nothing then this will throw an exception.
      stmt->fetch ();
      stmt->get_data (1, hostid);
      return true;
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - (%s:%u) %s\n",
                  ex.state ().c_str (),
                  ex.native (),
                  ex.message ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - unknown exception in "
                  "CUTS_Database_Service::register_host\n"));
    }
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - no database connection exist\n"));
  }

  return false;
}

//
// get_host_id
//
bool CUTS_Database_Service::get_host_id_by_name (const char * hostname,
                                                 int & hostid)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                         guard,
                         this->lock_,
                         false);

  if (this->conn_.is_connected ())
  {
    ACE_Auto_Ptr <ODBC_Stmt> stmt (this->conn_.create_statement ());
    long component_id = 0;

    try
    {
      SQLINTEGER _hostname = SQL_NTS;

      stmt->bind_parameter (1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
                            0, 0, (SQLCHAR *)hostname, 0, &_hostname);

      // Prepare the statement to select the component_id of the component
      // with the specified name.
      const char * str_stmt =
        "SELECT hostid FROM ipaddr_host_map WHERE hostname = ?";

      stmt->prepare (str_stmt);
      stmt->execute ();

      // Get the results from executing the query. If the query returns
      // nothing then this will throw an exception.
      stmt->fetch ();
      stmt->get_data (1, hostid);
      return true;
    }
    catch (ODBC_Stmt_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - (%s:%u) %s\n",
                  ex.state ().c_str (),
                  ex.native (),
                  ex.message ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - unknown exception in "
                  "CUTS_Database_Service::register_host\n"));
    }
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - no database connection exist\n"));
  }

  return false;
}
