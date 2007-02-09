// $Id$

//=============================================================================
/**
 * @file      gems2picml.cpp
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#include "G2P_Options.h"
#include "GEMS/GEMS.h"
#include "GME/gme/GME.h"
#include "ace/Get_Opt.h"

/// Singleton declaration for the options.
#define CUTS_G2P_OPTIONS() \
  ACE_Singleton <CUTS_G2P_Options, \
                 ACE_Null_Mutex>::instance ()

/// Helper macro for generating verbose messages.
#define VERBOSE_MESSAGE(msg) \
  if (CUTS_G2P_OPTIONS ()->verbose_) \
  { \
    ACE_DEBUG (msg); \
  }

//
// parse_args
//
int parse_args (int argc, char * argv [])
{
  const char * opts = ACE_TEXT ("f:m:no:");
  ACE_Get_Opt get_opt (argc, argv, opts, 0);

  get_opt.long_option ("folder", 'f', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("model", 'm', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("output", 'o', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("naming-service", 'n', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("verbose", ACE_Get_Opt::NO_ARG);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 0:
      if (ACE_OS::strcmp (get_opt.long_option (), "output") == 0)
        CUTS_G2P_OPTIONS ()->gme_connstr_ = get_opt.opt_arg ();

      else if (ACE_OS::strcmp (get_opt.long_option (), "folder") == 0)
        CUTS_G2P_OPTIONS ()->target_folder_ = get_opt.long_option ();

      else if (ACE_OS::strcmp (get_opt.long_option (), "model") == 0)
        CUTS_G2P_OPTIONS ()->target_model_ = get_opt.long_option ();

      else if (ACE_OS::strcmp (get_opt.long_option (), "naming-service") == 0)
        CUTS_G2P_OPTIONS ()->use_naming_service_ = true;

      else if (ACE_OS::strcmp (get_opt.long_option (), "verbose") == 0)
        CUTS_G2P_OPTIONS ()->verbose_ = true;

      break;

    case 'f':
      CUTS_G2P_OPTIONS ()->target_model_ = get_opt.opt_arg ();
      break;

    case 'm':
      CUTS_G2P_OPTIONS ()->target_model_ = get_opt.opt_arg ();
      break;

    case 'o':
      CUTS_G2P_OPTIONS ()->gme_connstr_ = get_opt.opt_arg ();
      break;

    case 'n':
      CUTS_G2P_OPTIONS ()->use_naming_service_ = true;
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
// convert_gems_2_picml
//
int convert_gems_2_picml (GME::Model & deployment,
                          const GEMS::Connection_Set & conns)
{
  VERBOSE_MESSAGE ((LM_INFO,
                    "*** info [gems2picml]: converting GEMS model to "
                    "PICML model...\n"));

  // Get all the component references for this deployment.
  std::vector <GME::Reference> components =
    deployment.references ("ComponentRef");

  // We need to create a reverse map of the *real* components
  // to the references.
  std::map <std::string, GME::Reference> component_map;

  for (std::vector <GME::Reference>::iterator iter = components.begin ();
       iter != components.end ();
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
  std::vector <GME::Set> hosts = deployment.sets ("CollocationGroup");
  std::map <std::string, GME::Set> hostmap;

  for (std::vector <GME::Set>::iterator iter = hosts.begin ();
       iter != hosts.end ();
       iter ++)
  {
    std::string name = iter->name ();

    if (name != "Control")
      iter->clear ();

    hostmap[name] = *iter;
  }

  // Iterate over all the GEMS deployment connections and create
  // the correct one in PICML/GME.
  for (GEMS::Connection_Set::const_iterator iter = conns.begin ();
       iter != conns.end ();
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
// main
//
int main (int argc, char * argv [])
{
  try
  {
    // Initialize the ORB.
    ::CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

    if (parse_args (argc, argv) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [gems2picml]: failed to parse command "
                         "line argument(s)\n"),
                         1);
    }

    int load_retval = 0;

    if (CUTS_G2P_OPTIONS ()->use_naming_service_)
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [gems2picml]: loading GEMS from naming "
                        "service\n"));

      // Load GEMS from the naming service.
      load_retval =
        GEMS_MODEL_MANAGER ()->load_from_naming_service (orb.in ());
    }
    else
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info [gems2picml]: loading GEMS model\n"));

      // Load GEMS manually from the ORB.
      load_retval =
        GEMS_MODEL_MANAGER ()->load_from_init_ref (orb.in ());
    }

    if (load_retval == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [gems2picml]: failed to load GEMS model\n"));
    }

    // Get all the deployment connections in the model.
    GEMS::Connection_Set deployments =
      GEMS_MODEL_MANAGER ()->connections ("deployment");

    // Let the user know how many connections we are working with.
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [gems2picml]: extracted %d connection(s) "
                      "from GEMS model\n",
                      deployments.size ()));

    if (CUTS_G2P_OPTIONS ()->gme_connstr_.empty ())
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [gems2picml]: failed to specify "
                         "GME project file\n"),
                         1);
    }

    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [gems2picml]: opening GME model %s\n",
                      CUTS_G2P_OPTIONS ()->gme_connstr_.c_str ()));

    GME::init ();

    // Open a new GME project.
    GME::Project project;
    project.open (CUTS_G2P_OPTIONS ()->gme_connstr_.c_str ());
    project.begin_transaction ();

    // Get the root folder.
    GME::Folder root = project.root_folder ();
    std::vector <GME::Folder> folders = root.folders ();

    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info [gems2picml]: locating %s folder\n",
                      CUTS_G2P_OPTIONS ()->target_folder_.c_str ()));

    // Search for the deployment plan folders.
    bool done = false;

    for (std::vector <GME::Folder>::iterator iter = folders.begin ();
         !done && iter != folders.end ();
         iter ++)
    {
      // Determine if this is the correct folder type and, if so,
      // determine if this is the <target_folder_>.
      if (iter->meta ().name () == "DeploymentPlans" &&
          iter->name () == CUTS_G2P_OPTIONS ()->target_folder_)
      {
        VERBOSE_MESSAGE ((LM_INFO,
                          "*** info [gems2picml]: locating %s model\n",
                          CUTS_G2P_OPTIONS ()->target_model_.c_str ()));

        // Get all the deployment plans in the model.
        std::vector <GME::Model> models = iter->models ("DeploymentPlan");

        // Search for one by the name of "SLICE_DeploymentPlan"
        for (std::vector <GME::Model>::iterator m_iter = models.begin ();
             !done && m_iter != models.end ();
             m_iter ++)
        {
          // Determine if this the the <target_model_>.
          if (m_iter->name () == CUTS_G2P_OPTIONS ()->target_model_)
          {
            convert_gems_2_picml (*m_iter, deployments);
            done = true;
          }
        }
      }
    }

    try
    {
      project.commit_transaction ();
    }
    catch (const GME::Failed_Result & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error [gems2picml]: GEM operation failed [0x%X]\n",
                  ex.value ()));

      project.abort_transaction ();
    }

    // Close the project and destroy the ORB.
    project.close ();
    orb->destroy ();

    return 0;
  }
  catch (const GME::Failed_Result & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error [gems2picml]: GME operation failed [0x%X]\n",
                ex.value ()));
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
