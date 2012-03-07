// $Id$

#include "StdAfx.h"
#include "Deployment_Plan_Generator.h"
#include "Deployment_Plan_Generator_Impl.h"
#include "DeploymentPlan_MainDialog.h"
#include "DeploymentPlanVisitor.h"

#include "game/mga/component/Interpreter_T.h"
#include "game/mga/utils/Project_Settings.h"
#include "game/mga/Filter.h"

#include "Utils/Utils.h"

#include "UdmGme.h"
#include "UdmStatic.h"

GAME_DECLARE_INTERPRETER (Deployment_Plan_Generator, Deployment_Plan_Generator_Impl);

/**
 * @struct insert_udm_t
 */
struct insert_udm_t
{
  insert_udm_t (UdmGme::GmeDataNetwork & network, std::set <Udm::Object> & coll)
    : network_ (network),
      coll_ (coll)
  {

  }

  void operator () (const GAME::Mga::FCO_in fco) const
  {
    this->coll_.insert (this->network_.Gme2Udm (fco->impl ()));
  }

private:
  UdmGme::GmeDataNetwork & network_;

  std::set <Udm::Object> & coll_;
};

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
           std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
  UdmGme::GmeDataNetwork dngBackend (PICML::diagram);

  try
  {
    dngBackend.OpenExisting (project.impl ());

    // First, make sure this project contains at least one deployment plan
    // before executing the rest of this interpreter.
    GAME::Mga::Filter filter (project);
    filter.kind ("DeploymentPlan");

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

    // Opening backend
    DeploymentPlanVisitor dpv (this->config_);

    if (selected.empty ())
    {
      PICML::RootFolder folder = PICML::RootFolder::Cast (dngBackend.GetRootObject ());
      folder.Accept (dpv);
    }
    else
    {
      set <Udm::Object> objects;
      std::for_each (selected.begin (),
                     selected.end (),
                     insert_udm_t (dngBackend, objects));

      set <Udm::Object>::const_iterator
        iter = objects.begin (), iter_end = objects.end ();

      for (; iter != iter_end; ++ iter)
      {
        if (iter->type () != PICML::DeploymentPlan::meta)
          continue;

        PICML::DeploymentPlan plan = PICML::DeploymentPlan::Cast (*iter);
        plan.Accept (dpv);
      }
    }

    if (this->is_interactive_)
      ::AfxMessageBox ("Successfully generated deployment plan descriptors",
                       MB_ICONINFORMATION);

    // Closing backend
    dngBackend.CloseWithUpdate ();
    return 0;
  }
  catch (udm_exception & exc)
  {
    if (this->is_interactive_)
      ::AfxMessageBox (exc.what ());
  }

  dngBackend.CloseNoUpdate ();
  return -1;
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
    settings.get_string_value ("OutputPath", config.output_);

  settings.get_boolean_value ("HasLocalityManager", config.has_locality_manager_);
  settings.get_boolean_value ("DisableOptimize", config.disable_optimize_);
}

//
// save_configuration
//
void Deployment_Plan_Generator_Impl::
save_configuration (GAME::Mga::Project proj, const Configuration & config)
{
  GAME::Mga::Project_Settings settings (proj, "DeploymentPlanGenerator");

  settings.set_string_value ("OutputPath", config.output_);
  settings.set_boolean_value ("HasLocalityManager", config.has_locality_manager_);
  settings.set_boolean_value ("DisableOptimize", config.disable_optimize_);
}
