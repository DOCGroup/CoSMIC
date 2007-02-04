// $Id$

#include "DBase_Service.h"

#include "cuts/Component_Info.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Host_Table_Entry.h"
#include "cuts/Port_Metric.h"
#include "cuts/Time.h"
#include "cuts/Log_Msg.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "cuts/utils/ODBC/ODBC_Connection.h"
#include "cuts/utils/ODBC/ODBC_Query.h"
#include "cuts/utils/ODBC/ODBC_Record.h"
#include "cuts/utils/ODBC/ODBC_Parameter.h"
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
: server_ (CUTS_DEFAULT_HOSTNAME),
  username_ (CUTS_USERNAME),
  password_ (CUTS_PASSWORD),
  port_ (CUTS_DEFAULT_PORT),
  verbose_ (false),
  test_number_ (-1)
{

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

  int is_connected = this->connect (this->username_.c_str (),
                                    this->password_.c_str (),
                                    this->server_.c_str (),
                                    this->port_);
  if (is_connected)
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [archive]: successfully connected to "
                      "database on %s\n",
                      this->server_.c_str ()));
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

  }

  return is_connected ? 0 : -1;
}

//
// fini
//
int CUTS_Database_Service::fini (void)
{
  // Disconnect from the database.
  this->disconnect ();
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

  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());

  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement for exection.
    const char * str_stmt =
      "INSERT INTO tests (start_time, status) VALUES (NOW(), 'active')";

    // Execute the statement and retrieve the test id, which is
    // the <last_insert_id ()> for the query.
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

  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());

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
// archive_system_metrics
//
int CUTS_Database_Service::handle_metrics (void)
{
  ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());

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
    CUTS_System_Metric * metric = this->svc_mgr ()->metrics ();
    ACE_Time_Value timestamp = metric->get_timestamp ();
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

    CUTS_Component_Metric_Map::const_iterator cm_iter;

    for (cm_iter  = metric->component_metrics ().begin ();
         cm_iter != metric->component_metrics ().end ();
         cm_iter ++)
    {
      // Determine if this component has any metrics that correspond
      // with the lastest timestamp for the system metrics. If it does
      // not then why bother going any further.
      if (timestamp != cm_iter->second->timestamp ())
        continue;

      component = this->id_map_[cm_iter->first];

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
          sender = this->id_map_[spm_iter->first];

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
            if (metric->get_timestamp () != em_iter->second->timestamp ())
              continue;

            // Copy the metrics for the process data into the appropriate
            // parameters before we execute the statement.
            query->parameter (7)->bind (dst, 0);

            ACE_OS::strcpy (dst, em_iter->first.c_str ());

            // Store the metrics in their parameters.
            metric_count = em_iter->second->count ();
            best_time = em_iter->second->best_time ();
            worse_time = em_iter->second->worse_time ();
            total_time = em_iter->second->total_time ();

            // Execute the query.
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
  if (info.state_ == 1)
  {
    long inst_id = -1;

    if (this->register_component (info.inst_.c_str (),
                                  info.type_.c_str (),
                                  &inst_id))
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [archive]: successfully registered "
                        "component %s\n",
                        info.inst_.c_str ()));

      // Map the testing environment id to the database id for
      // the component. This will allow us to keep track of it.
      this->id_map_.insert (
        ID_Map::value_type (info.uid_, inst_id));
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [archive]: failed to register component %s\n",
                  info.inst_.c_str ()));
    }
  }

  return 0;
}
