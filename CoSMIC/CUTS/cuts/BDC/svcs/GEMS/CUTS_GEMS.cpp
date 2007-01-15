// $Id$

#include "CUTS_GEMS.h"

#if !defined (__CUTS_INLINE__)
#include "CUTS_GEMS.inl"
#endif

#include "cuts/Component_Info.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/System_Metric.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "GEMS/GEMS.h"
#include "ace/Get_Opt.h"
#include "ace/streams.h"

/* undef max () macro before including <limits> */
#if defined (max)
#undef max
#endif

#include <limits>
#include <sstream>

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
: verbose_ (false)
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
  const char * opts = "";

  ACE_Get_Opt get_opt (argc, argv, opts, 0);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("gems", ACE_Get_Opt::ARG_REQUIRED);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "gems") == 0)
        this->gems_string_ = get_opt.opt_arg ();
      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
        this->verbose_ = true;
      else
        ACE_DEBUG ((LM_DEBUG,
                    "--%s is an unknown option; ignoring\n",
                    get_opt.long_option ()));
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
    if (this->init_gems () == -1)
      return -1;

    // Let's build the GEM model in our address space so that
    // we can manage it accordingly.
    if (GEMS::Model_Manager::instance ()->build (this->gems_.in ()) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "failed to build GEMS model\n"),
                         -1);
    }

    return 0;
  }
  catch (const ::CORBA::Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "caught CORBA exception [%s]\n",
                ex._info ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "caught unknown exception\n"));
  }

  return -1;
}

//
// handle_deactivate
//
int CUTS_GEMS_Service::handle_deactivate (void)
{
  // Get the root element for the model and get all its components.
  GEMS::Model * root = GEMS::Model_Manager::instance ()->root ();
  GEMS::Model_Set components = root->children ("component");

  VERBOSE_MESSAGE ((LM_DEBUG,
                    "extracted %d components from GEMS\n",
                    components.size ()));

  // Get the metrics for the system.
  CUTS_System_Metric * metric = this->svc_mgr ()->metrics ();

  for (GEMS::Model_Set::iterator model_iter = components.begin ();
       model_iter != components.end ();
       model_iter ++)
  {
    // Create the instance name from the GME model.
    std::string inst_name =
      (*model_iter)->role ("annotation") +
      "." + (*model_iter)->role ("name");

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "getting metrics for %s\n",
                      inst_name.c_str ()));

    // Get the CUTS id for the component.
    Name_Id_Map::iterator nid_iter = this->cuts_id_.find (inst_name);

    if (nid_iter != this->cuts_id_.end ())
    {
      // Get the metrics for the component.
      CUTS_Component_Metric * com_metric =
        metric->component_metrics (nid_iter->second);

      size_t ports = 0;
      double acc_util = 0.0;
      const CUTS_Port_Metric_Map & pmm = com_metric->port_metrics ();

      for (CUTS_Port_Metric_Map::const_iterator pmm_iter = pmm.begin ();
           pmm_iter != pmm.end ();
           pmm_iter ++)
      {
        CUTS_Sender_Port_Map spm = pmm_iter->second;

        if (!spm.empty ())
        {
          CUTS_Port_Metric * pm = spm.begin ()->second;

          if (!pm->endpoints ().empty ())
          {
            CUTS_Time_Metric * tm = pm->endpoints ().begin ()->second;
            double util = 0.0;

            if (tm != 0)
            {
              /* util = service_rate * TPUT */
              util = tm->avg_time () *
                (tm->count () / metric->get_duration ().msec ());
            }

            VERBOSE_MESSAGE ((LM_DEBUG,
                              "utilization for port %s is %f\n",
                              pmm_iter->first.c_str (),
                              util));

            // Add the calculated utilization and increment
            // the port number count.
            acc_util += util;
            ports ++;
          }
        }
      }

      // Let's print a status message to the users if they
      // request that verbose mode be used for the service.
      double total_util = ports > 0 ? acc_util / ports : 0.0;

      GEMS::Model * cpu_req = 0;
      GEMS::Model_Set reqs = (*model_iter)->children ("requirement");

      // Locate the CPU requirement in the child models.
      for (GEMS::Model_Set::iterator reqs_iter = reqs.begin ();
           reqs_iter != reqs.end ();
           reqs_iter ++)
      {
        if ((*reqs_iter)->role ("name") == "CPU")
        {
          cpu_req = *reqs_iter;
          break;
        }
      }

      if (cpu_req == 0)
      {
        // We need to create a CPU requirement for the model.
        GEMS::Model * cpu_req = GEMS::Model::create (*model_iter, "requirement");
        cpu_req->role ("name", "CPU");
      }

      // Convert the <total_util> to a string value.
      std::ostringstream ostr;
      ostr << total_util;

      cpu_req->role ("value", ostr.str ());

      VERBOSE_MESSAGE ((LM_DEBUG,
                        "CPU for %s is %f\n"
                        "-------------------------------------\n",
                        inst_name.c_str (),
                        total_util));
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "failed to find id for %s\n",
                  inst_name.c_str ()));
    }
  }

  GEMS::Model_Manager::close_singleton ();
  return this->fini_gems ();
}

//
// init_gems
//
int CUTS_GEMS_Service::init_gems (void)
{
  VERBOSE_MESSAGE ((LM_DEBUG, "resolving initial reference to GEMS\n"));

  // Get the ORB and initialize the reference to GEMS.
  ::CORBA::ORB_var orb = this->svc_mgr ()->get_orb ();

  ::CORBA::Object_var obj =
    orb->string_to_object (this->gems_string_.c_str ());

  if (::CORBA::is_nil (obj.in ()))
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                        "failed to resolve reference to GEMS server\n"),
                        -1);
  }

  // Narrow the GEMS model from the object reference.
  VERBOSE_MESSAGE ((LM_DEBUG, "extracting GEMS model from reference\n"));
  this->gems_ = GEMSServer::Model::_narrow (obj.in ());

  if (::CORBA::is_nil (this->gems_.in ()))
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                        "object reference is not a GEMS model\n"),
                        -1);
  }

  VERBOSE_MESSAGE ((LM_DEBUG, "sucessfully connected to GEMS server\n"));
  return 0;
}

//
// handle_component
//
int CUTS_GEMS_Service::
handle_component (const CUTS_Component_Info & info)
{
  // Save the name -> id mapping for CUTS.
  this->cuts_id_.insert (Name_Id_Map::value_type (
                         info.inst_.c_str (),
                         info.uid_));

  return 0;
}

//
// fini_gems
//
int CUTS_GEMS_Service::fini_gems (void)
{
  try
  {
    // Release the CORBA reference to GEMS.
    ::CORBA::release (this->gems_.in ());
    this->gems_ = GEMSServer::Model::_nil ();

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "successfully disconnected from GEMS server\n"));
    return 0;
  }
  catch (const ::CORBA::Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "CORBA exception [%s]\n",
                ex._info ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "caught unknown exception\n"));
  }

  ACE_ERROR ((LM_ERROR,
              "failed to finalize connection to GEM model server\n"));

  return -1;
}
