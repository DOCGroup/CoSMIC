// $Id$

#include "Baseline_Service.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Component_Info.h"
#include "cuts/Host_Table_Entry.h"
#include "cuts/Auto_Functor_T.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "cuts/utils/ODBC/ODBC_Connection.h"
#include "cuts/utils/ODBC/ODBC_Query.h"
#include "cuts/utils/ODBC/ODBC_Record.h"
#include "cuts/utils/ODBC/ODBC_Parameter.h"
#include "ace/Auto_Functor.h"
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
  inst_id_ (-1),
  host_id_ (-1),
  min_baseline_ (true)
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
// parse_args
//
int CUTS_Baseline_Service::
parse_args (int argc, ACE_TCHAR * argv [])
{
  const char * opts = "udw:";

  ACE_Get_Opt get_opt (argc, argv, opts, 0);
  get_opt.long_option ("server", ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("warmup-count", 'w', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("default", ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("upper-bound", 'u', ACE_Get_Opt::NO_ARG);

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

      else if (ACE_OS::strcmp (get_opt.long_option (), "default") == 0)
        this->default_ = true;

      else if (ACE_OS::strcmp (get_opt.long_option (), "upper-bound") == 0)
        this->min_baseline_ = false;

      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
        this->verbose_ = true;
      break;

    case 'w':
      this->warmup_count_ = ACE_OS::atoi (get_opt.opt_arg ());
      break;

    case 'u':
      this->min_baseline_ = false;
      break;

    case '?':
      ACE_DEBUG ((LM_NOTICE,
                  "*** notice [baseline]: -%c is unknown option; ignoring\n",
                  get_opt.opt_opt ()));
      break;

    case ':':
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [baseline]: %c is missing an argument\n",
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
// handle_deactivate
//
int CUTS_Baseline_Service::handle_deactivate (void)
{
  if (this->warmup_count_ == 0 &&
      this->inst_id_ != -1 &&
      this->host_id_ != -1)
  {
    // Open a connection to the database. We only need to continue
    // if we have established a connection.
    if (this->connect (CUTS_USERNAME,
                       CUTS_PASSWORD,
                       this->server_.c_str (),
                       CUTS_DEFAULT_PORT))
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [baseline]: successfully connected to "
                        "database on %s\n",
                        this->server_.c_str ()));

      // Insert statement for the database.
      const char * insert_stmt = this->min_baseline_ ?
        "INSERT INTO baseline "
        "(instance, host, inport, outport, min_count, min_total) "
        "VALUES (?, ?, ?, ?, ?, ?)" : "INSERT INTO baseline "
        "(instance, host, inport, outport, max_count, max_total) "
        "VALUES (?, ?, ?, ?, ?, ?)";

      // Update statement for the database.
      const char * update_stmt = this->min_baseline_ ?
        "UPDATE baseline SET min_count = ?, min_total = ? "
        "WHERE instance = ? AND host = ? AND inport = ? AND outport = ?" :
        "UPDATE baseline SET max_count = ?, max_total = ? "
        "WHERE instance = ? AND host = ? AND inport = ? AND outport = ?";

      int retval = 0;
      try
      {
        long count,     /* number of events */
              total;    /* total execution time */

        char inport  [MAX_VARCHAR_LENGTH],    /* name of input port */
              outport [MAX_VARCHAR_LENGTH];   /* name of output port */

        // Create the query. We are using an auto functor since the
        // allocation occurs in another module/address space. Invoking
        // the destructor manually can cause problems. We therefore
        // need to call the release method, but do it automatically.
        ACE_Auto_Ptr <ODBC_Query> insert (this->create_query ());
        ACE_Auto_Ptr <ODBC_Query> update (this->create_query ());

        // Prepare the insert statement and its parameters.
        insert->prepare (insert_stmt);
        insert->parameter (0)->bind (&this->inst_id_);
        insert->parameter (1)->bind (&this->host_id_);
        insert->parameter (2)->bind (inport, 0);
        insert->parameter (3)->bind (outport, 0);
        insert->parameter (4)->bind (&count);
        insert->parameter (5)->bind (&total);

        // Prepare the update statement and its parameters.
        update->prepare (update_stmt);
        update->parameter (0)->bind (&count);
        update->parameter (1)->bind (&total);
        update->parameter (2)->bind (&this->inst_id_);
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

          VERBOSE_MESSAGE ((LM_INFO,
                            "*** info [baseline]: logging baseline metrics "
                            "for %s\n",
                            inport));

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
                  ACE_ERROR ((
                    LM_ERROR,
                    "*** error [baseline]: %s\n"
                    "*** error [baseline]: failed to update baseline "
                    "metric\n",
                    ex.message ().c_str ()));
                }
                catch (...)
                {
                  ACE_ERROR ((
                    LM_ERROR,
                    "*** error [baseline]: caught unknown exception\n"
                    "*** error [baseline]: failed to update baseline "
                    "metric\n",
                    ex.message ().c_str ()));
                }
              }
            }

            // Notify the user of the collected baseline metrics.
            VERBOSE_MESSAGE ((LM_DEBUG,
                              "*** info [baseline]: port %s ("
                              "count: %d; min: %d; avg: %f; max: %d)\n",
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
                    "*** error [baseline]: caught unknown exception\n"));
        retval = 1;
      }

      // This is the success exit point. We are going to disconnect
      // from the database and return a success value.
      this->disconnect ();
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [baseline]: closed connection to %s\n",
                        this->server_.c_str ()));

      return retval;
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
  }
  else
  {
    // Ok, so there was some error and we need to determine which
    // error it was. It could be multiple errors. Either way, we
    // need to display all the possible errors.
    if (this->warmup_count_ != 0)
    {
      ACE_DEBUG ((LM_WARNING,
                  "*** warn [baseline]: deactivating test before completing "
                  "warmup\n"));
    }

    if (this->inst_id_ == -1)
    {
      ACE_DEBUG ((LM_WARNING,
                  "*** warn [baseline]: not saving baseline metrics since "
                  "failed to initialize instance id\n"));
    }

    if (this->host_id_ == -1)
    {
      ACE_DEBUG ((LM_WARNING,
                  "*** warn [baseline]: not saving baseline metrics since "
                  "failed to initialize host id\n"));
    }
  }

  return 1;
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

  // Open a connection to the database. We only need to continue
  // if we have established a connection.
  if (this->connect (CUTS_USERNAME,
                     CUTS_PASSWORD,
                     this->server_.c_str (),
                     CUTS_DEFAULT_PORT))
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [baseline]: successfully connected to "
                      "database on %s\n"
                      "*** info [baseline]: request id of %s\n",
                      this->server_.c_str (),
                      info.inst_.c_str ()));

    // Register the component information.
    if (!this->register_component (info.inst_.c_str (),
                                   info.type_.c_str (),
                                   &this->inst_id_))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [baseline]: failed to get id of %s\n",
                         info.inst_.c_str ()),
                         1);
    }

    // Let's get the id of the component's host. If the host
    // information is not available then we need to treat this
    // as a default baseline test.
    if (!this->default_ && info.host_info_ != 0)
    {
      // We are going to treat this as default baseline since either
      // the user specified, or we don't know anything about the host.
      if (this->register_host (info.host_info_->ipaddr_.c_str (),
                               info.host_info_->hostname_.c_str (),
                               &this->host_id_))
      {
        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [baseline]: host %s has id of %d\n",
                          info.host_info_->ipaddr_.c_str (),
                          this->host_id_));
      }
      else
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                           "*** error [baseline]: failed to get %s "
                           "host id\n",
                           info.host_info_->hostname_.c_str ()),
                           1);
      }
    }
    else
    {
      // We are going to treat this as default baseline since either
      // the user specified, or we don't know anything about the host.
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [baseline]: treating baseline "
                        "test as default\n"));

      if (!this->get_hostid_by_ipaddr ("0.0.0.0",
                                       &this->host_id_))
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                            "*** error [baseline]: failed to get "
                            "default host id\n"),
                            1);
      }
    }

    // Disconnect from the database.
    this->disconnect ();
    return 0;
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

  return 1;
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
