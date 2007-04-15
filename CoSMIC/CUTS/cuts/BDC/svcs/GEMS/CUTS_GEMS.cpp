// $Id$

#include "CUTS_GEMS.h"

#if !defined (__CUTS_INLINE__)
#include "CUTS_GEMS.inl"
#endif

#include "cuts/Component_Info.h"
#include "cuts/Host_Table_Entry.h"
#include "cuts/Port_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/System_Metric.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "cuts/utils/ODBC/ODBC_Query.h"
#include "cuts/utils/ODBC/ODBC_Record.h"
#include "cuts/utils/ODBC/ODBC_Parameter.h"
#include "GEMS/GEMS.h"
#include "ace/Get_Opt.h"

/* undef max () macro before including <limits> */
#if defined (max)
#undef max
#endif

#if defined (min)
#undef min
#endif

#include <limits>
#include <sstream>
#include <cmath>
#include <algorithm>

#define MAX_RESOURCE_VALUE  100
#define MAX_VARCHAR_LENGTH  256

// Declare the service impl.
CUTS_BDC_SERVICE_IMPL (CUTS_GEMS_Service);

//=============================================================================

// Macro for simplifying inclusion of verbose messages.
#define VERBOSE_MESSAGE(msg) \
  if (this->verbose_) \
  { \
    ACE_ERROR (msg); \
  }

// Macro for simplifying inclusion of verbose messages w.
// a return value.
#define VERBOSE_MESSAGE_RETURN(msg, retval) \
  if (this->verbose_) \
  { \
    ACE_ERROR_RETURN (msg, retval); \
  }

//
// CUTS_GEMS_Service
//
CUTS_GEMS_Service::CUTS_GEMS_Service (void)
: verbose_ (false),
  baseline_server_ ("localhost"),
  use_naming_service_ (false)
{

}

//
// ~CUTS_GEMS_Service
//
CUTS_GEMS_Service::~CUTS_GEMS_Service (void)
{

}

//
// init
//
int CUTS_GEMS_Service::init (int argc, ACE_TCHAR * argv [])
{
  return this->parse_args (argc, argv);
}

//
// parse_args
//
int CUTS_GEMS_Service::parse_args (int argc, ACE_TCHAR * argv [])
{
  const char * opts = "nb:r:";

  ACE_Get_Opt get_opt (argc, argv, opts, 0);
  get_opt.long_option ("baseline-server", 'b', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("gems", ACE_Get_Opt::ARG_REQUIRED);

  get_opt.long_option ("fini", ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("init", ACE_Get_Opt::ARG_REQUIRED);

  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "gems") == 0)
        this->gems_string_ = get_opt.opt_arg ();
      else if (ACE_OS::strcmp (get_opt.long_option (), "init") == 0)
        this->init_gems_ = get_opt.opt_arg ();
      else if (ACE_OS::strcmp (get_opt.long_option (), "fini") == 0)
        this->fini_gems_ = get_opt.opt_arg ();
      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
        this->verbose_ = true;
      else
      {
        ACE_DEBUG ((LM_DEBUG,
                    "--%s is an unknown option; ignoring\n",
                    get_opt.long_option ()));
      }
      break;

    case 'n':
      this->use_naming_service_ = true;
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
    }
  }

  return 0;
}

//
// handle_activate
//
int CUTS_GEMS_Service::handle_activate (void)
{
  try
  {
    // Get the ORB.
    ::CORBA::ORB_var orb = this->svc_mgr ()->get_orb ();

    int load_retval;

    if (this->use_naming_service_)
    {
      // Load GEMS using the naming service.
      load_retval =
        GEMS_MODEL_MANAGER ()->load_from_naming_service (orb.in ());
    }
    else
    {
      // Load GEMS using the ORBInitRef.
      load_retval =
        GEMS_MODEL_MANAGER ()->
        load_from_string (orb.in (), this->gems_string_.c_str ());
    }

    // Display the appropriate message to the client.
    if (load_retval == 0)
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [GEMS]: successfully built GEMS model\n"));
    }
    else
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [GEMS]: failed to build GEMS model\n"),
                         -1);
    }

    // Let's extract all the components and populate the node
    // map. We need this so we can push the metrics back into
    // the model.
    if (this->populate_component_map () == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [GEMS]: failed to extract "
                         "component models\n"),
                         -1);
    }

    if (!this->init_gems_.empty ())
    {
      // Apply the changes to the GEMS model and run the constraint solver.
      // We can then close the singleton since we aren't going to perform
      // any more operations on the model.
      if (GEMS_MODEL_MANAGER ()->
          run_constraint_solver (this->init_gems_.c_str ()) == 0)
      {
        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [GEMS]: successfully invoked '%s' "
                          "in GEMS\n",
                          this->init_gems_.c_str ()));
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
                    "*** error [GEMS]: failed to invoke '%s' in GEMS\n",
                    this->init_gems_.c_str ()));
      }
    }

    return 0;
  }
  catch (const ::CORBA::Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [GEMS]: %s\n",
                ex._info ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [GEMS]: caught unknown exception\n"));
  }

  return -1;
}

//
// handle_deactivate
//
int CUTS_GEMS_Service::handle_deactivate (void)
{
  // Try to connect to the baseline server to compare the current
  // measurements with the baseline measurements.
  if (!this->connect (CUTS_USERNAME,
                      CUTS_PASSWORD,
                      this->baseline_server_.c_str (),
                      CUTS_DEFAULT_PORT))
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error [GEMS]: failed to connect to %s\n",
                       this->baseline_server_.c_str ()),
                       -1);
  }

  // Get the metrics for the system.
  CUTS_System_Metric * metrics = this->svc_mgr ()->metrics ();

  // Now, we are going to iterate over all the components in the GEMS
  // model and update their resource requirements based on a normalization
  // of the collected metrics.
  for (GEMS_Model_Map::iterator iter = this->component_map_.begin ();
       iter != this->component_map_.end ();
       iter ++)
  {
    // Get the database id of the component.
    long inst_id = 0;

    if (!this->get_instance_id (iter->first.c_str (), &inst_id))
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [GEMS]: failed to locate %s in database; "
                  "skipping...\n",
                  iter->first.c_str ()));
      continue;
    }
    else
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [GEMS]: using component %s with id %d\n",
                        iter->first.c_str (),
                        inst_id));
    }

    // We need to determine which host this component was deployed. This
    // will allow use to get the correct host id from the database.
    ID_String_Map::const_iterator idstr_iter =
      this->host_map_.find (iter->second.first);

    std::string ipaddr =
      idstr_iter != this->host_map_.end () ?
      idstr_iter->second : "0.0.0.0";

    long host_id;

    if (!this->get_hostid_by_ipaddr (ipaddr.c_str (), &host_id))
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [GEMS]: failed to get host id for %s; "
                  "skipping...\n",
                  ipaddr.c_str ()));
      continue;
    }
    else
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [GEMS]: using host %s with id %d\n",
                        ipaddr.c_str (),
                        host_id));
    }

    // Get the baseline metric for this component. Right now, there is a
    // huge assumption that there is only one baseline metric for instance.
    const char * stmt =
      "SELECT inport, outport, (metric_total / metric_count) as metric_avg "
      "FROM baseline WHERE instance = ? and host = ?";

    // Prepare the statement and its parameters for execution.
    ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());
    query->prepare (stmt);

    query->parameter (0)->bind (&inst_id);
    query->parameter (1)->bind (&host_id);

    // Execute the query and the records.
    CUTS_DB_Record * record = query->execute ();

    if (record->count () > 0)
    {
      // Get the information from the retrieved record. We need to this
      // information for lookup in the system metric table.
      double baseline;
      char  inport  [MAX_VARCHAR_LENGTH],
            outport [MAX_VARCHAR_LENGTH];

      record->fetch ();
      record->get_data (1, inport, MAX_VARCHAR_LENGTH);
      record->get_data (2, outport, MAX_VARCHAR_LENGTH);
      record->get_data (3, baseline);

      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [GEMS]: %s on %s from %s to %s has "
                        "baseline of %f\n",
                        iter->first.c_str (),
                        ipaddr.c_str (),
                        inport,
                        outport,
                        baseline));

      // Get the component metrics from the system metrics. The get the
      // port metric for this baseline.
      CUTS_Component_Metric * c_metric =
        metrics->component_metrics (iter->second.first);

      CUTS_Port_Metric * port_metric =
        c_metric->port_metrics (inport, CUTS_UNKNOWN_IMPL);

      // Finally, we need to get the endpoint.
      CUTS_Time_Metric * time_metric = port_metric->endpoint (outport);

      double avg_time = time_metric->avg_time ();
      double percentage = (avg_time - baseline) / (avg_time + baseline);

      VERBOSE_MESSAGE ((LM_DEBUG,
                        "*** info [GEMS]: average time was %f, which is "
                        "%f from baseline\n",
                        avg_time,
                        percentage));

      // If the percentage is less than 0.0, then we need to warn the
      // user. This means the baseline metric is wrong for this component
      // on this host using the specified ports. To solution is to rerun
      // the baseline metrics.
      if (percentage < 0.0)
      {
        // Take absolute value so we don't have a negative change.
        percentage = std::abs (percentage);

        ACE_ERROR ((LM_WARNING,
                    "*** warning [GEMS]: experimental value is less than "
                    "baseline for component %s with inport = %s and outport "
                    "= %s on host %s; please rerun baseline metrics\n",
                    iter->first.c_str (),
                    inport,
                    outport,
                    ipaddr.c_str ()));
      }

      // We are ready to update the GEMS model with the new value
      // for resource requirements.
      GEMS::Model_Set requirements =
        iter->second.second->children ("requirement");

      GEMS::Model_Set::iterator req_iter;

      for (req_iter  = requirements.begin ();
           req_iter != requirements.end ();
           req_iter ++)
      {
        if ((*req_iter)->role ("name") == "CPU")
        {
          // Get the current value for the CPU requirement.
          std::string strval = (*req_iter)->role ("value");
          long old_value;

          // Extract the value from the string.
          std::istringstream istr (strval);
          istr >> old_value;

          // Calculate how much to increase the current value by.
          double tempval =
            old_value + ((MAX_RESOURCE_VALUE - old_value) * percentage);

          long new_value =
            std::min ((long) MAX_RESOURCE_VALUE, static_cast <long> (ceil (tempval)));

          // Convert the value back into a string. We are taking the absolute
          // value just to be safe, however, this shouldn't be necessary. The
          // baseline will always be less than the experimental value. If this
          // is ever the case, then the baseline metric is wrong.
          std::ostringstream ostr;
          ostr << new_value;

          (*req_iter)->role ("value", ostr.str ());

          // Display a nice message to the user.
          VERBOSE_MESSAGE ((LM_DEBUG,
                            "*** info [GEMS]: update model; increasing CPU "
                            "value from %d to %d\n",
                            old_value,
                            new_value));
          break;
        }
      }

      // Verify that we did indeed update the CPU requirement.
      if (req_iter == requirements.end ())
      {
        ACE_ERROR ((LM_ERROR,
                    "*** error [GEMS]: failed to locate CPU requirement "
                    "for %s\n",
                    iter->first.c_str ()));
      }
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [GEMS]: failed locate baseline metric from %s "
                  "on host %s\n",
                  iter->first.c_str (),
                  ipaddr.c_str ()));
    }
  }

  if (!this->fini_gems_.empty ())
  {
    // Apply the changes to the GEMS model and run the constraint solver.
    // We can then close the singleton since we aren't going to perform
    // any more operations on the model.
    if (GEMS_MODEL_MANAGER ()->
        run_constraint_solver (this->fini_gems_.c_str ()) == 0)
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [GEMS]: successfully invoked '%s' "
                        "in GEMS\n",
                        this->fini_gems_.c_str ()));
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [GEMS]: failed to invoke '%s' in GEMS\n",
                  this->fini_gems_.c_str ()));
    }
  }
  else
  {
    // Just apply the changes to the model.
    GEMS_MODEL_MANAGER ()->apply_changes ();
  }

  // Close the model manager.
  GEMS::Model_Manager::close_singleton ();
  return 0;
}

//
// handle_component
//
int CUTS_GEMS_Service::
handle_component (const CUTS_Component_Info & info)
{
  // We ingore unknown implemenations
  if (info.inst_ == "Unknown")
    return 0;

  // Let's try and find the component in the GEMS node map.
  GEMS_Model_Map::iterator iter =
    this->component_map_.find (info.inst_.c_str ());

  if (iter != this->component_map_.end ())
  {
    // Save the id in the existing element.
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [GEMS]: caching %s with id %d using "
                      "host info %s (%s)\n",
                      info.inst_.c_str (),
                      info.uid_,
                      info.host_info_->hostname_.c_str (),
                      info.host_info_->ipaddr_.c_str ()));

    iter->second.first = info.uid_;
  }
  else
  {
    // Try to create a new component element.
    VERBOSE_MESSAGE ((LM_WARNING,
                      "*** warning: %s not located in GEMS model, "
                      "creating new component\n",
                      info.inst_.c_str ()));

    // Get the root element and create a new component.
    GEMS::Model * root = GEMS_MODEL_MANAGER ()->root ("");
    GEMS::Model * component = GEMS::Model::create (root, "component");

    if (component == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "failed to create model element for %s\n",
                         info.inst_.c_str ()),
                         -1);
    }

    // Set the name and annotation for the component.
    component->role ("name", info.inst_.c_str ());

    this->component_map_.insert (
      GEMS_Model_Map::value_type (info.inst_.c_str (),
      std::make_pair (info.uid_, component)));

    // Apply the changes to the model. We need to provide another
    // admin method so we don't have to apply changes everytime
    // we create a new element.
    if (GEMS_MODEL_MANAGER ()->apply_changes () == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "failed to add %s to GEMS model\n",
                  info.inst_.c_str ()));
    }
  }

  // We need to store the host information since there currently is
  // no way to query registration information.
  if (info.host_info_)
  {
    this->host_map_.insert (
      ID_String_Map::value_type (info.uid_, info.host_info_->ipaddr_.c_str ()));
  }

  return 0;
}

//
// populate_nodemap
//
int CUTS_GEMS_Service::populate_component_map (void)
{
  // Get all the component models.
  GEMS::Model_Set components =
    GEMS_MODEL_MANAGER ()->models ("component");

  // Iterate over each component and add it to the map when an
  // unknown implementation id. The id will be resolved during
  // the handle_component () event.
  for (GEMS::Model_Set::iterator iter = components.begin ();
       iter != components.end ();
       iter ++)
  {
    this->component_map_.insert (
      GEMS_Model_Map::value_type ((*iter)->role ("name"),
      std::make_pair (CUTS_UNKNOWN_IMPL, *iter)));
  }

  VERBOSE_MESSAGE ((LM_DEBUG,
                    "extracted %d component model(s) from GEMS\n",
                    this->component_map_.size ()));
  return 0;
}
