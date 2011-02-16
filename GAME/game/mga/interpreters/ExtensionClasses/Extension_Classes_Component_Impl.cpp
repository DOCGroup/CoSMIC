// $Id: Extension_Classes_Component_Impl.cpp 2486 2010-09-08 17:29:09Z alhad $

#include "StdAfx.h"
#include "Extension_Classes_Component.h"
#include "Extension_Classes_Component_Impl.h"

#include "Extension_Classes_Visitor.h"
#include "Mpc_File_Generator.h"
#include "Mwc_File_Generator.h"
#include "Pch_File_Generator.h"
#include "Fwd_Decl_Generator.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/be/Interpreter_T.h"
#include "game/mga/utils/Project_Settings.h"

#include "boost/bind.hpp"

#include <direct.h>
#include <algorithm>

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>

GAME_DECLARE_INTERPRETER (Extension_Classes_Component, Extension_Classes_Component_Impl);

//
// Quotas_Integrator_Impl
//
Extension_Classes_Component_Impl::Extension_Classes_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("GAME Extension Class Generator",
                                    "MetaGME",
                                    "GAME.Interpreter.ExtensionClasses")
{

}

//
// ~Extension_Classes_Component_Impl
//
Extension_Classes_Component_Impl::~Extension_Classes_Component_Impl (void)
{

}

//
// invoke_ex
//
int Extension_Classes_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
  try
  {
    // Start a new transaction.
    GAME::Mga::Transaction t_readonly (project);

    // Load the project settings for next time.
    this->save_project_settings (project);

    // Get the output directory for the extension classes.
    bool retval = GAME::Utils::get_path ("Select target output directory...",
                                         this->output_,
                                         this->output_);

    if (!retval)
      return 0;

    GAME::Mga::Folder root = project.root_folder ();
    std::string root_name = root->name ();
    GAME::Utils::normalize (root_name);

    // Transform the name of paradigm sheet to upper case.
    std::string uc_paradigm_name = root_name;
    std::transform (uc_paradigm_name.begin (),
                    uc_paradigm_name.end (),
                    uc_paradigm_name.begin (),
                    &::toupper);

    // Make sure the output directory has been created.
    const std::string pch_basename = "stdafx";
    const std::string source_path = this->output_ + "/" + project.name ();
    GAME::Utils::create_path (source_path);

    // Visit all element in the model and generate an extension
    // class for each valid model.
    std::set <GAME::Mga::Object> ext_classes;
    GAME::Mga::Extension_Classes_Visitor ecv (source_path,
                                              root,
                                              pch_basename,
                                              ext_classes);

    root->accept (&ecv);

    // Generate workspace, project, and precompiled header files.
    GAME::Mga::Mwc_File_Generator mwc_gen;
    mwc_gen.generate (source_path, project);

    GAME::Mga::Mpc_File_Generator mpc_gen;
    mpc_gen.generate (source_path, project, pch_basename, ext_classes);

    GAME::Mga::Pch_File_Generator pch_gen;
    pch_gen.generate (source_path, project, pch_basename);

    GAME::Mga::Fwd_Decl_Generator fwd_gen;
    fwd_gen.generate (source_path, project, ext_classes);

    if (this->is_interactive_)
      ::AfxMessageBox ("Files generated successfully", MB_OK);

    // Save the project settings for next time.
    this->save_project_settings (project);
  }
  catch (const GAME::Mga::Exception & )
  {
    if (this->is_interactive_)
      ::AfxMessageBox ("Caught GME exception", MB_OK);
  }

  return 0;
}

//
// set_parameter
//
int Extension_Classes_Component_Impl::
set_parameter (const std::string & name, const std::string & value)
{
  if (name == "OutputPath")
    this->output_ = value;

  return 0;
}

//
// load_project_settings
//
void Extension_Classes_Component_Impl::
load_project_settings (GAME::Mga::Project proj)
{
  GAME::Mga::Project_Settings settings (proj);
  settings.get_string_value ("GAME/ExtensionClasses/OutputDirectory", this->output_);
}

//
// save_project_settings
//
void Extension_Classes_Component_Impl::
save_project_settings (GAME::Mga::Project proj)
{
  GAME::Mga::Project_Settings settings (proj);
  settings.set_string_value ("GAME/ExtensionClasses/OutputDirectory", this->output_);
}
