// $Id$

#include "gems2picml_App.h"
#include "GEMS.h"
#include "gme/ComponentEx.h"
#include "ace/Get_Opt.h"

// Helper macro for generating verbose messages.
#define VERBOSE_MESSAGE(msg) \
  if (this->options_.verbose_) \
  { \
    ACE_DEBUG (msg); \
  }

//
// gems2picml_App
//
gems2picml_App::gems2picml_App (void)
{

}

//
// ~gems2picml_App
//
gems2picml_App::~gems2picml_App (void)
{
  // Destroy the ORB if it exists.
  if (!::CORBA::is_nil (this->orb_.in ()))
    this->orb_->destroy ();

  // Release the project and finalize GME.
  this->fini_gme_project ();
}

//
// parse_args
//
int gems2picml_App::parse_args (int argc, char * argv [])
{
  const char * opts = ACE_TEXT ("cf:m:no:r:p:");
  ACE_Get_Opt get_opt (argc, argv, opts, 0);

  get_opt.long_option ("folder", 'f', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("model", 'm', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("naming-service", 'n', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("output", 'o', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("param", 'p', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);
  get_opt.long_option ("run", 'r', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("create", 'c', ACE_Get_Opt::NO_ARG);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "output") == 0)
      {
        this->options_.gme_connstr_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "folder") == 0)
      {
        this->options_.target_folder_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "model") == 0)
      {
        this->options_.target_model_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "naming-service") == 0)
      {
        this->options_.use_naming_service_ = true;
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "param") == 0)
      {
        if (this->options_.insert_param (get_opt.opt_arg ()) == -1)
          return -1;
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "run") == 0)
      {
        this->options_.run_component_ = get_opt.opt_arg ();
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "create") == 0)
      {
        this->options_.create_ = true;
      }
      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
      {
        this->options_.verbose_ = true;
      }
      break;

    case 'c':
      this->options_.create_ = true;
      break;

    case 'f':
      this->options_.target_folder_ = get_opt.opt_arg ();
      break;

    case 'm':
      this->options_.target_model_ = get_opt.opt_arg ();
      break;

    case 'o':
      this->options_.gme_connstr_ = get_opt.opt_arg ();
      break;

    case 'n':
      this->options_.use_naming_service_ = true;
      break;

    case 'r':
      this->options_.run_component_ = get_opt.opt_arg ();
      break;

    case 'p':
      if (this->options_.insert_param (get_opt.opt_arg ()) == -1)
        return -1;
      break;

    case '?':
      // unknown option; do nothing
      break;

    case ':':
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [gems2picml]: %c is missing an argument\n",
                         get_opt.opt_opt ()),
                         -1);
      break;

    default:
      /* do nothing */;
    }
  }

  return 0;
}

//
// run
//
int gems2picml_App::run (int argc, char * argv [])
{
  try
  {
    // Initialize the CORBA ORB.
    this->orb_ = ::CORBA::ORB_init (argc, argv);

    // Parse the command-line arguments.
    if (parse_args (argc, argv) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [gems2picml]: failed to parse command "
                         "line argument(s)\n"),
                         1);
    }

    // Verify the user specified a GME target project file.
    if (this->options_.gme_connstr_.empty ())
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [gems2picml]: failed to specify "
                         "GME project file\n"),
                         1);
    }

    // Initialize the GEMS model manager.
    if (this->init_gems () != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [gems2picml]: failed to load GEMS "
                         "model\n"),
                         1);
    }

    // Get all the deployment connections from the GEMS model.
    this->deployments_ = GEMS_MODEL_MANAGER ()->connections ("deployment");

    // Let the user know how many connections we are working with.
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [gems2picml]: extracted %d connection(s) "
                      "from GEMS model\n",
                      this->deployments_.size ()));

    // Initialize the GME project.
    if (this->init_gme_project () != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [gems2picml]: failed to initialize "
                         "GME\n"), 1);
    }

    // Start a new transaction for the conversion. We then need to
    // locate the correct deployment plan.
    this->project_->begin_transaction ();

    GME::Model plan;
    if (this->find_deployment_plan (plan) == 0)
    {
      // Convert the GEMS model to a PICML model.
      if (this->convert_gems_2_picml (plan) == 0)
        this->project_->commit_transaction ();
    }

    // Run the specified GME component, if it was specified.
    if (!this->options_.run_component_.empty ())
      this->run_component ();

    return 0;
  }
  catch (const GME::Failed_Result & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [gems2picml]: GME operation failed [0x%X]\n",
                ex.value ()));

    this->project_->abort_transaction ();
  }
  catch (const ::CORBA::Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [gems2picml]: %s\n",
                ex._info ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [gems2picml]: caught unknown exception\n"));
  }

  return 1;
}

//
// init_gems
//
int gems2picml_App::init_gems (void)
{
  if (this->options_.use_naming_service_)
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [gems2picml]: loading GEMS from naming "
                      "service\n"));

    // Load GEMS from the naming service.
    return
      GEMS_MODEL_MANAGER ()->load_from_naming_service (this->orb_.in ());
  }
  else
  {
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [gems2picml]: loading GEMS model\n"));

    // Load GEMS manually from the ORB.
    return
      GEMS_MODEL_MANAGER ()->load_from_init_ref (this->orb_.in ());
  }
}

//
// init_gme_project
//
int gems2picml_App::init_gme_project (void)
{
  GME::init ();
  this->project_.reset (new GME::Project ());

  VERBOSE_MESSAGE ((LM_INFO,
                    "*** info [gems2picml]: opening GME model %s\n",
                    this->options_.gme_connstr_.c_str ()));

  // Open a new GME project.
  this->project_->open (this->options_.gme_connstr_.c_str ());
  return 0;
}

//
// fini_gme_project
//
void gems2picml_App::fini_gme_project (void)
{
  if (this->project_.get ())
  {
    this->project_->close ();
    this->project_.reset ();
  }

  GME::fini ();
}

//
// locate_deployment_plan
//
int gems2picml_App::find_deployment_plan (GME::Model & plan)
{
  // Get the root folder.
  GME::Folder root = this->project_->root_folder ();

  // Get all the folders in the <root> folder.
  std::vector <GME::Folder> folders;
  root.folders (folders);

  VERBOSE_MESSAGE ((LM_INFO,
                    "*** info [gems2picml]: locating %s folder\n",
                    this->options_.target_folder_.c_str ()));

  for (std::vector <GME::Folder>::iterator f_iter = folders.begin ();
       f_iter != folders.end ();
       f_iter ++)
  {
    // Determine if this is the correct folder type and, if so,
    // determine if this is the <target_folder_>.
    if (f_iter->meta () == "DeploymentPlans" &&
        f_iter->name () == this->options_.target_folder_)
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [gems2picml]: locating %s model\n",
                        this->options_.target_model_.c_str ()));

      // Get all the deployment plans in the model.
      typedef GME::Collection_T <GME::Model> DeploymentPlan_Set;

      DeploymentPlan_Set deployment_plans;
      f_iter->models ("DeploymentPlan", deployment_plans);

      // Search for one by the name of "SLICE_DeploymentPlan"
      DeploymentPlan_Set::_container_type::iterator m_iter;

      for (m_iter = deployment_plans.items ().begin ();
           m_iter != deployment_plans.items ().end ();
           m_iter ++)
      {
        // Determine if this the the <target_model_>.
        if (m_iter->name () == this->options_.target_model_)
        {
          plan = *m_iter;
          return 0;
        }
      }

      // Ok, we found the folder, but we didn't find <target_model_>. We
      // therefore need to create a new model. However, we only create a
      // new model if we have permission.
      if (m_iter == deployment_plans.items ().end () &&
          this->options_.create_)
      {
        plan = GME::Model::_create ("DeploymentPlan", *f_iter);
        return 0;
      }
    }
  }

  return -1;
}

//
// convert_gems_2_picml
//
int gems2picml_App::
convert_gems_2_picml (GME::Model & deployment)
{
  VERBOSE_MESSAGE ((LM_INFO,
                    "*** info [gems2picml]: converting GEMS model to "
                    "PICML model...\n"));

  // Get all the component references for this deployment.
  typedef GME::Collection_T <GME::Reference> Reference_Set;

  Reference_Set components;
  deployment.references ("ComponentRef", components);

  // We need to create a reverse map of the *real* components
  // to the references.
  std::map <std::string, GME::Reference> component_map;
  Reference_Set::_container_type::iterator iter;

  for (iter  = components.items ().begin ();
       iter != components.items ().end ();
       iter ++)
  {
    std::string name = iter->refers_to ().path (".", false);
    component_map[name] = *iter;
  }

  // Get all the collocation groups. We are going to take
  // the easy way out and remove all the components from each
  // group.

  /// @todo Re-implement algorithm such that we do not have to
  /// empty all the sets before we begin reconfiguring the
  /// deployment.
  typedef GME::Collection_T <GME::Set> Host_Set;

  Host_Set hosts;
  deployment.sets ("CollocationGroup", hosts);

  std::map <std::string, GME::Set> hostmap;
  Host_Set::_container_type::iterator host_iter;

  for (host_iter  = hosts.items ().begin ();
       host_iter != hosts.items ().end ();
       host_iter ++)
  {
    std::string name = host_iter->name ();

    if (name != "Control")
      host_iter->clear ();

    hostmap[name] = *host_iter;
  }

  // Iterate over all the GEMS deployment connections and create
  // the correct one in PICML/GME.
  for (GEMS::Connection_Set::const_iterator iter =
       this->deployments_.begin ();
       iter != this->deployments_.end ();
       iter ++)
  {
    std::string hostname = (*iter)->target ()->role ("name");
    std::string component = (*iter)->source ()->role ("name");

    VERBOSE_MESSAGE ((LM_DEBUG,
                      "*** info [gem2picml]: adding %s to %s\n",
                      component.c_str (),
                      hostname.c_str ()));

    hostmap[hostname].insert (component_map[component]);
  }

  return 0;
}

//
// run_component
//
int gems2picml_App::run_component (void)
{
  // Load the GME component.
  GME::ComponentEx gme_component;
  gme_component.load (this->options_.run_component_);

  // TODO: verify component is an interpreter.
  // TODO: verify component is compatible with project.

  // Initialize the the component.
  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info [gem2picml]: initializing %s\n",
                    this->options_.run_component_.c_str ()));

  gme_component.initialize (*this->project_);

  // Initialize all the parameters for the component.
  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info [gem2picml]: setting %d parameter(s)\n",
                    this->options_.params_.size ()));

  CUTS_G2P_Options::Parameter_List::iterator iter;

  for (iter = this->options_.params_.begin ();
       iter != this->options_.params_.end ();
       iter ++)
  {
    gme_component.parameter (iter->first, iter->second);
  }

  // We can now invoke the component/interpreter. We are need to
  // pass in dummy parameters for to make everyone happy.

  GME::FCO current;
  std::vector <GME::FCO> selected;

  VERBOSE_MESSAGE ((LM_DEBUG,
                    "*** info [gem2picml]: invoking %s\n",
                    this->options_.run_component_.c_str ()));

  gme_component.invoke (*this->project_, current, selected, 0);
  return 0;
}
