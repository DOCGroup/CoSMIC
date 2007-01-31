// $Id$

#include "Baseline_Service.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Component_Info.h"
#include "cuts/BDC/BDC_Service_Manager.h"
#include "ace/Get_Opt.h"

#define VERBOSE_MESSAGE(msg) \
  if (this->verbose_) \
  { \
    ACE_DEBUG (msg); \
  }

CUTS_BDC_SERVICE_IMPL (CUTS_Baseline_Service);

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
  return this->parse_args (argc, argv);
}

//
// handle_deactivate
//
int CUTS_Baseline_Service::handle_deactivate (void)
{
  if (this->warmup_count_ == 0)
  {
    // Get the component metrics for the component whose id
    // we stored during its activation.

    CUTS_System_Metric * metrics = this->svc_mgr ()->metrics ();
    CUTS_Component_Metric * component_metric =
      metrics->component_metrics (this->uid_);

    const CUTS_Port_Metric_Map & map = component_metric->port_metrics ();

    for (CUTS_Port_Metric_Map::const_iterator inport = map.begin ();
         inport != map.end ();
         inport ++)
    {
      // Get the sender port of the unknown implemenation type. We
      // are only concerned with this one since we do not know the
      // id of the test component causing the work.

      CUTS_Sender_Port_Map::const_iterator sender =
        inport->second.find (CUTS_UNKNOWN_IMPL);

      CUTS_Endpoint_Metric_Map::const_iterator outport;

      for (outport  = sender->second->endpoints ().begin ();
           outport != sender->second->endpoints ().end ();
           outport ++)
      {
        ACE_DEBUG ((LM_DEBUG,
                    "%s -> %s\n"
                    "  count: %d; avg. time: %f; min time: %d; max time: %d\n",
                    inport->first.c_str (),
                    outport->first.c_str (),
                    outport->second->count (),
                    outport->second->avg_time (),
                    outport->second->best_time (),
                    outport->second->worse_time ()));

        // TODO: write baseline metrics to database
      }
    }
  }
  else
  {
    ACE_ERROR ((LM_WARNING,
                "*** warning [baseline]: deactivating test before "
                "completing warmup\n"));
  }

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
  // Save the id of the component and start the countdown.
  this->uid_ = info.uid_;
  return 0;
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
    this->metrics_ += *this->svc_mgr ()->metrics ();
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
