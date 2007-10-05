// $Id$

#include "Baseline_Service.h"
#include "Baseline_Archiver_DB.h"
#include "System_Metric_Accumulator.h"
#include "cuts/Testing_Service.h"
#include "cuts/Host_Table_Entry.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "cuts/utils/ODBC/ODBC_Connection.h"
#include "cuts/utils/ODBC/ODBC_Query.h"
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
  default_ (false)
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

  // Save the connection and attach it to the <registry_>.
  this->conn_.reset (conn);
  this->registry_.attach (conn);

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

      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
        this->verbose_ = true;
      break;

    case 'w':
      this->warmup_count_ = ACE_OS::atoi (get_opt.opt_arg ());
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
  if (this->warmup_count_ == 0)
  {
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
                          "*** info [baseline]: saving metrics to "
                          "datatbase\n"));


        CUTS_Baseline_Archiver_DB
          archiver (this->svc_mgr ()->testing_service ()->registry (),
                    *this->conn_);

        // Archive the baseline metrics.
        this->svc_mgr ()->metrics ()->accept (archiver);

        // Disconnect from the database.
        this->conn_->disconnect ();

        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [baseline]: closed connection to %s\n",
                          this->server_.c_str ()));

        return 0;
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
    catch (CUTS_DB_Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [baseline]: %s\n",
                  ex.message ().c_str ()));
    }
  }
  else
  {
    ACE_DEBUG ((LM_WARNING,
                "*** warning [baseline]: deactivating test before completing "
                "warmup\n"));
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
  if (info.inst_ == "Unknown" ||
      info.state_ != CUTS_Component_Info::STATE_ACTIVATE)
  {
    return 0;
  }

  // Save the id of the component and start the countdown.
  int retval = 1;
  this->instance_ = info.inst_;
  this->uid_ = info.uid_;

  // Open a connection to the database. We only need to continue
  // if we have established a connection.
  try
  {
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

      // Register the component information.
      if (this->registry_.register_component (info))
      {
        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [baseline]: successfully registered %s\n",
                          info.inst_.c_str ()));
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
                    "*** info [baseline]: failed to register %s\n",
                    info.inst_.c_str ()));
      }

      // Let's get the id of the component's host. If the host
      // information is not available then we need to treat this
      // as a default baseline test.
      if (!this->default_ && info.host_info_ != 0)
      {
        // We are going to treat this as default baseline since either
        // the user specified, or we don't know anything about the host.
        if (this->registry_.register_host (info.host_info_->ipaddr_.c_str (),
                                           info.host_info_->hostname_.c_str ()))
        {
          VERBOSE_MESSAGE ((LM_INFO,
                            "*** info [baseline]: successfully registered "
                            "%s [%s]\n",
                            info.host_info_->hostname_.c_str (),
                            info.host_info_->ipaddr_.c_str ()));
        }
        else
        {
          ACE_ERROR ((LM_ERROR,
                      "*** error [baseline]: failed to register %s [%s]\n",
                      info.host_info_->hostname_.c_str (),
                      info.host_info_->ipaddr_.c_str ()));
        }
      }
      else
      {
        // We are going to treat this as default baseline since either
        // the user specified, or we don't know anything about the host.
        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [baseline]: creating default baseline\n"));
      }

      // Disconnect from the database.
      this->conn_->disconnect ();
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
  }
  catch (CUTS_DB_Exception & )
  {
    if (this->conn_->is_connected ())
      this->conn_->disconnect ();
  }

  return 1;
}

//
// handle_metrics
//
int CUTS_Baseline_Service::
handle_metrics (const CUTS_System_Metric & metrics)
{
  if (this->warmup_count_ == 0)
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [baseline]: accumulating metrics\n"));

    // Accumulate the test metrics.
    CUTS_System_Metric_Accumulator accumulator (this->baseline_);
    metrics.accept (accumulator);
  }
  else
  {
    // Update the warmup counter.
    -- this->warmup_count_;

    ACE_DEBUG ((LM_INFO,
                "*** info [baseline]: %d collection(s) in warmup remaining\n",
                this->warmup_count_));
  }

  return 0;
}
