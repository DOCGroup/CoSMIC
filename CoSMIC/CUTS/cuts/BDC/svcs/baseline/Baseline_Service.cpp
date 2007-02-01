// $Id$

#include "Baseline_Service.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Component_Info.h"
#include "cuts/Host_Table_Entry.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "cuts/utils/ODBC/ODBC_Connection.h"
#include "cuts/utils/ODBC/ODBC_Query.h"
#include "cuts/utils/ODBC/ODBC_Record.h"
#include "cuts/utils/ODBC/ODBC_Parameter.h"
#include "ace/Get_Opt.h"

// Helper macro for writing verbose messages.
#define VERBOSE_MESSAGE(msg) \
  if (this->verbose_) \
  { \
    ACE_DEBUG (msg); \
  }

// Define the implementation.
CUTS_BDC_SERVICE_IMPL (CUTS_Baseline_Service);

#define MAX_VARCHAR_LENGTH 256

//
// CUTS_Baseline_Service
//
CUTS_Baseline_Service::CUTS_Baseline_Service (void)
: verbose_ (false),
  warmup_count_ (1),
  server_ ("localhost"),
  default_ (false),
  database_id_ (CUTS_UNKNOWN_IMPL)
{

}

//
// ~CUTS_Baseline_Service
//
CUTS_Baseline_Service::~CUTS_Baseline_Service (void)
{

}

//
// init
//
int CUTS_Baseline_Service::init (int argc, ACE_TCHAR * argv[])
{
  // Allocate a new connection.
  ODBC_Connection * conn = 0;
  ACE_NEW_RETURN (conn, ODBC_Connection (), 1);
  this->conn_.reset (conn);

  return this->parse_args (argc, argv);
}

//
// handle_deactivate
//
int CUTS_Baseline_Service::handle_deactivate (void)
{
  if (this->warmup_count_ > 0)
  {
    // Notify the user that the test is stopping before the
    // warmup phase is complete.
    ACE_ERROR_RETURN ((LM_WARNING,
                       "*** warn [baseline]: deactivating test before "
                       "completing warmup\n"),
                       0);
  }


  // Open a connection to the database. We only need to continue
  // if we have established a connection.
  this->conn_->connect (CUTS_USERNAME,
                        CUTS_PASSWORD,
                        this->server_.c_str (),
                        CUTS_DEFAULT_PORT);

  if (this->conn_->is_connected ())
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info: successfully connected to database "
                      "on %s\n",
                      this->server_.c_str ()));

    // Insert statement for the database.
    const char * insert_stmt =
      "INSERT INTO baseline "
      "(instance, host, inport, outport, metric_count, metric_total) "
      "VALUES (?, ?, ?, ?, ?, ?)";

    // Update statement for the database.
    const char * update_stmt =
      "UPDATE baseline SET metric_count = ?, metric_total = ? "
      "WHERE instance = ? AND host = ? AND inport = ? AND outport = ?";

    try
    {
      long count,     /* number of events */
           total;     /* total execution time */

      char inport  [MAX_VARCHAR_LENGTH],    /* name of input port */
           outport [MAX_VARCHAR_LENGTH];    /* name of output port */

      // Create the query.
      ACE_Auto_Ptr <ODBC_Query> insert (
        dynamic_cast <ODBC_Query *> (this->conn_->create_query ()));

      // Create the query.
      ACE_Auto_Ptr <ODBC_Query> update (
        dynamic_cast <ODBC_Query *> (this->conn_->create_query ()));

      // Prepare the insert statement and its parameters.
      insert->prepare (insert_stmt);
      insert->parameter (0)->bind (&this->database_id_);
      insert->parameter (1)->bind (&this->host_id_);
      insert->parameter (2)->bind (inport, 0);
      insert->parameter (3)->bind (outport, 0);
      insert->parameter (4)->bind (&count);
      insert->parameter (5)->bind (&total);

      // Prepare the update statement and its parameters.
      update->prepare (update_stmt);
      update->parameter (0)->bind (&count);
      update->parameter (1)->bind (&total);
      update->parameter (2)->bind (&this->database_id_);
      update->parameter (3)->bind (&this->host_id_);
      update->parameter (4)->bind (inport, 0);
      update->parameter (5)->bind (outport, 0);

      // Get the component metrics for the component whose id
      // we stored during its activation.
      CUTS_Component_Metric * component_metric =
        this->baseline_.component_metrics (this->uid_);

      const CUTS_Port_Metric_Map & map = component_metric->port_metrics ();

      for (CUTS_Port_Metric_Map::const_iterator port = map.begin ();
            port != map.end ();
            port ++)
      {
        // Copy the <inport> to the parameter.
        ACE_OS::strcpy (inport, port->first.c_str ());

        // Get the sender port of the unknown implemenation type. We
        // are only concerned with this one since we do not know the
        // id of the test component causing the work.

        CUTS_Sender_Port_Map::const_iterator sender =
          port->second.find (CUTS_UNKNOWN_IMPL);

        CUTS_Endpoint_Metric_Map::const_iterator endpoint;

        for (endpoint  = sender->second->endpoints ().begin ();
              endpoint != sender->second->endpoints ().end ();
              endpoint ++)
        {
          // Finish updating the remaining parameters.
          ACE_OS::strcpy (outport, endpoint->first.c_str ());
          count = endpoint->second->count ();
          total = endpoint->second->total_time ();

          try
          {
            // Write the record to the database.
            insert->execute_no_record ();
          }
          catch (const CUTS_DB_Exception & ex)
          {
            // We need to update the record if we get a duplicate record
            // exception. This would be signified by the state '23000'.
            if (ex.state () == "23000")
            {
              try
              {
                update->execute_no_record ();
              }
              catch (const CUTS_DB_Exception & ex)
              {
                ACE_ERROR ((LM_ERROR,
                            "*** error [baseline]: %s\n"
                            "*** error [baseline]: failed to update baseline "
                            "metric\n",
                            ex.message ().c_str ()));

              }
            }
          }

          // Notify the user of the collected baseline metrics.
          VERBOSE_MESSAGE ((LM_DEBUG,
                            "*** info [baseline]: %s -> %s ("
                            "count: %d; min: %d; avg: %f; max: %d)\n",
                            inport,
                            outport,
                            count,
                            endpoint->second->best_time (),
                            endpoint->second->avg_time (),
                            endpoint->second->worse_time ()));
        }
      }
    }
    catch (CUTS_DB_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [baseline]: %s\n",
                  ex.message ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [baseline]: "
                  "unknown exception in handle_deactivate\n"));
    }
  }
  else
  {
    // Notify the user that we failed to connect to the
    // specified databsae.
    ACE_ERROR ((LM_ERROR,
                "*** error [baseline]: failed to connect to database "
                "on %s\n",
                this->server_.c_str ()));
  }

  if (this->conn_->is_connected ())
    this->conn_->disconnect ();

  return 0;
}

//
// handle_activate
//
int CUTS_Baseline_Service::handle_activate (void)
{
  VERBOSE_MESSAGE ((LM_INFO,
                    "*** info [baseline]: "
                    "%d collection(s) in warmup remaining...\n",
                    this->warmup_count_))
  return 0;
}

//
// handle_component
//
int CUTS_Baseline_Service::
handle_component (const CUTS_Component_Info & info)
{
  if (info.inst_ == "Unknown")
    return 0;

  // Save the id of the component and start the countdown.
  this->instance_ = info.inst_;
  this->uid_ = info.uid_;
  int retval = 1;

  try
  {
    // Open a connection to the database. We only need to continue
    // if we have established a connection.
    this->conn_->connect (CUTS_USERNAME,
                          CUTS_PASSWORD,
                          this->server_.c_str (),
                          CUTS_DEFAULT_PORT);

    if (this->conn_->is_connected ())
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [baseline]: successfully connected to "
                        "database on %s\n",
                        this->server_.c_str ()));

      const char * component_stmt =
        "SELECT component_id FROM component_instances "
        "WHERE component_name = ?";

      // Create the query operations and prepare it's statement.
      ACE_Auto_Ptr <ODBC_Query> query (
        dynamic_cast <ODBC_Query *> (this->conn_->create_query ()));

      // Prepare the statement and its parameters.
      char component_name [MAX_VARCHAR_LENGTH];

      query->prepare (component_stmt);
      query->parameter (0)->bind (component_name, 0);
      ACE_OS::strcpy (component_name, info.inst_.c_str ());

      // Execute the query and get the record.
      CUTS_DB_Record * record = query->execute ();

      if (record->count () != 0)
      {
        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [baseline]: located %d record(s) for %s; "
                          "using the first record\n",
                          record->count (),
                          info.inst_.c_str ()));

        // Get the id of the component from the record.
        record->fetch ();
        record->get_data (1, this->database_id_);
        retval = 0;
      }
      else
      {
        // Notify the user that we were not able to locate the
        // specified component in the database.
        ACE_ERROR ((LM_WARNING,
                    "*** warn [baseline]: failed to locate %s in "
                    "database\n",
                    info.inst_.c_str ()));
      }

      // Let's get the id of the component's host. If the host
      // information is not available then we need to treat this
      // as a default baseline test.
      if (!this->default_ && info.host_info_ != 0)
      {
        this->get_host_id (info.host_info_->hostname_.c_str ());
      }
      else
      {
        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [baseline]: treating baseline "
                          "test as default\n"));

        this->get_host_id ("unknown");
      }
    }
    else
    {
      // Notify the user that we were not able to connect to the
      // specfied database.
      ACE_ERROR ((LM_ERROR,
                  "*** error [baseline]: failed to connect to database "
                  "on %s\n",
                  this->server_.c_str ()));
    }
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [baseline]: %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {

  }

  // Disconnect from the database if necesary.
  if (this->conn_->is_connected ())
    this->conn_->disconnect ();

  return retval;
}

//
// handle_metrics
//
int CUTS_Baseline_Service::handle_metrics (void)
{
  if (this->warmup_count_ == 0)
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [baseline]: accumulating metrics...\n"));

    // Accumulate the test metrics.
    this->baseline_ += *this->svc_mgr ()->metrics ();
  }
  else
  {
    // Update the warmup counter.
    -- this->warmup_count_;

    ACE_DEBUG ((LM_INFO,
                "*** info [baseline]: %d collection(s) in warmup remaining...\n",
                this->warmup_count_));
  }

  return 0;
}

//
// parse_args
//
int CUTS_Baseline_Service::
parse_args (int argc, ACE_TCHAR * argv [])
{
  const char * opts = "dw:";

  ACE_Get_Opt get_opt (argc, argv, opts, 0);
  get_opt.long_option ("server", ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("warmup-count", 'w', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("default-baseline", ACE_Get_Opt::NO_ARG);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "warmup-count") == 0)
        this->warmup_count_ = ACE_OS::atoi (get_opt.opt_arg ());

      else if (ACE_OS::strcmp (get_opt.long_option (), "server") == 0)
        this->server_ = get_opt.opt_arg ();

      else if (ACE_OS::strcmp (get_opt.long_option (), "default-baseline") == 0)
        this->default_ = true;

      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
        this->verbose_ = true;
      break;

    case 'w':
        this->warmup_count_ = ACE_OS::atoi (get_opt.opt_arg ());
        break;

    case '?':
      ACE_DEBUG ((LM_DEBUG,
                  "-%c is an unknown option; ignoring\n",
                  get_opt.opt_opt ()));
      break;

    case ':':
      ACE_ERROR_RETURN ((LM_ERROR,
                         "%c is missing an argument\n",
                         get_opt.opt_opt ()),
                         1);
      break;

    default:
      /* do nothing */;
    };
  }

  return 0;
}

//
// get_host_id
//
long CUTS_Baseline_Service::get_host_id (const char * hostname)
{
  try
  {
    const char * stmt =
      "SELECT hostid FROM ipaddr_host_map WHERE hostname = ?";

    // Create the query operations and prepare it's statement.
    ACE_Auto_Ptr <ODBC_Query> query (
      dynamic_cast <ODBC_Query *> (this->conn_->create_query ()));

    // Prepare the statement and it's parameters.
    query->prepare (stmt);
    query->parameter (0)->bind (const_cast <char *> (hostname), 0);

    // Execute the statement and retrieve the record.
    CUTS_DB_Record * record = query->execute ();

    if (record->count () > 0)
    {
      VERBOSE_MESSAGE ((LM_DEBUG,
                        "*** info [baseline]: located %d id(s) for "
                        "host '%s'\n",
                        record->count (),
                        hostname));

      record->fetch ();
      record->get_data (1, this->host_id_);

      VERBOSE_MESSAGE ((LM_DEBUG,
                        "*** info [baseline]: %s has id of %d\n",
                        hostname,
                        this->host_id_));
      return 0;
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: failed to get id of host '%s'\n",
                  hostname));
    }
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error: %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    // Notify the user of the unknown exception.
    ACE_ERROR ((LM_ERROR,
                "*** error [baseline]: unknown exception in get_host_id\n"));
  }

  return -1;
}
