// $Id$

#include "StdAfx.h"
#include "IDL_Generator_Component.h"
#include "IDL_Generator_Component_Impl.h"
#include "IDL_Generator_Visitor.h"

#include "game/mga/component/Interpreter_T.h"
#include "game/mga/utils/Project_Settings.h"

#include "Utils/Utils.h"

GAME_DECLARE_INTERPRETER (IDL_Generator_Component, IDL_Generator_Component_Impl);

//
// Quotas_Integrator_Impl
//
IDL_Generator_Component_Impl::IDL_Generator_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("IDL File Generator",
                                    "MGA.Interpreter.IDLGenerator",
                                    "PICML")
{

}

//
// ~IDL_Generator_Component_Impl
//
IDL_Generator_Component_Impl::~IDL_Generator_Component_Impl (void)
{

}

//
// invoke_ex
//
int IDL_Generator_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO focus,
           GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
           long flags)
{
  GAME::Mga::Readonly_Transaction t (project);

  if (this->is_interactive_ || this->output_.empty ())
  {
    // Select the output directory for the files.
    if (!::Utils::getPath ("Select target output directory...", this->output_))
      return -1;
  }

  // Generate all the IDL files.
  IDL_Generator_Visitor visitor (this->output_);
  PICML::RootFolder root_folder = project.root_folder ();
  root_folder->accept (&visitor);

  if (this->is_interactive_)
    ::AfxMessageBox ("Successfully generated IDL files");

  return 0;
}

//
// set_parameter
//
int IDL_Generator_Component_Impl::
set_parameter (const std::string & name, const std::string & value)
{
  if (name == "OutputPath")
    this->output_ = value;

  return 0;
}
