#include "StdAfx.h"
#include "Deployment_Plan_Generator_Impl.h"
#include "Deployment_Plan_Visitor.h"
#include "Deployment_Domain_Visitor.h"

#include "DeploymentPlan_MainDialog.h"

#include "game/mga/component/Interpreter_T.h"
#include "game/mga/utils/Project_Settings.h"
#include "game/mga/Object_Filter.h"

#include "PICML/DeploymentPlan/DeploymentPlan.h"

GAME_DECLARE_INTERPRETER (Deployment_Plan_Generator, Deployment_Plan_Generator_Impl);

//
// Deployment_Plan_Generator_Impl
//
Deployment_Plan_Generator_Impl::Deployment_Plan_Generator_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("DAnCE Deployment Plan Generator",
                                    "MGA.Interpreter.DeploymentPlan",
                                    "PICML")
{

}

//
// ~Deployment_Plan_Generator_Impl
//
Deployment_Plan_Generator_Impl::~Deployment_Plan_Generator_Impl (void)
{

}

//
// invoke_ex
//
int Deployment_Plan_Generator_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
           long flags)
{
  try
  {
    GAME::Mga::Transaction t (project);

    // First, make sure this project contains at least one deployment plan
    // before executing the rest of this interpreter.
    GAME::Mga::Filter filter (project);
    filter.kind (PICML::DeploymentPlan_Impl::metaname);

    std::vector <GAME::Mga::FCO> plans;
    if (0 == filter.apply (plans))
    {
      const char * message =
        "The project has no deployment plans. Please add at least "
        "one deployment plan to the project before invoking this "
        "interpreter.";

      ::AfxMessageBox (message, MB_ICONWARNING);
      return 0;
    }

    // Load the last configuration for this project.
    this->load_configuration (project, this->config_);

    if (this->is_interactive_)
    {
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
      Deployment_Plan_Dialog dlg (this->config_, ::AfxGetMainWnd ());

      if (dlg.DoModal () == IDCANCEL)
        return 0;

      // Save the directory back to the model.
      this->save_configuration (project, this->config_);
    }

    // Generate the deployment plan for either all the plans in the project
    // or the selected objects. The selected objects must be a deployment
    // plan, or the behavior is unknown.
    PICML::Deployment::Deployment_Plan_Visitor dpv (this->config_);
    Deployment_Domain_Visitor domain_visitor (this->config_.output_);

    if (selected.is_empty ())
    {
      project.root_folder ()->accept (&dpv);
      project.root_folder ()->accept (&domain_visitor);
    }
    else
    {
      for (GAME::Mga::FCO selection : selected)
      {
        if (selection->meta ()->name () != PICML::DeploymentPlan::impl_type::metaname)
          continue;

        selection->accept (&dpv);
        selection->accept (&domain_visitor);
      }
    }

    if (this->is_interactive_)
      ::AfxMessageBox ("Successfully generated deployment plan descriptors", MB_ICONINFORMATION);

    // Commit any changes to the model.
    t.commit ();

    return 0;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    if (this->is_interactive_)
      ::AfxMessageBox (ex.message ().c_str ());
  }

  return 0;
}

//
// set_parameter
//
int Deployment_Plan_Generator_Impl::
set_parameter (const std::string & name, const std::string & value)
{
  if (name == "OutputPath")
    this->config_.output_ = value.c_str ();

  return 0;
}

//
// load_configuration
//
void Deployment_Plan_Generator_Impl::
load_configuration (GAME::Mga::Project proj, Configuration & config)
{
  GAME::Mga::Project_Settings settings (proj, "DeploymentPlanGenerator");

  if (config.output_.empty ())
    settings.get_value ("OutputPath", config.output_);

  settings.get_value ("HasLocalityManager", config.has_locality_manager_);
  settings.get_value ("DisableOptimize", config.disable_optimize_);
}

//
// save_configuration
//
void Deployment_Plan_Generator_Impl::
save_configuration (GAME::Mga::Project proj, const Configuration & config)
{
  GAME::Mga::Project_Settings settings (proj, "DeploymentPlanGenerator");

  settings.set_value ("OutputPath", config.output_);
  settings.set_value ("HasLocalityManager", config.has_locality_manager_);
  settings.set_value ("DisableOptimize", config.disable_optimize_);
}
