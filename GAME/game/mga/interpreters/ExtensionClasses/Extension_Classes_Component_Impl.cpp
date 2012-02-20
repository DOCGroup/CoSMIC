// $Id: Extension_Classes_Component_Impl.cpp 2486 2010-09-08 17:29:09Z alhad $

#include "StdAfx.h"
#include "Extension_Classes_Component.h"
#include "Extension_Classes_Component_Impl.h"

#include "Export_File_Generator.h"
#include "Extension_Classes_Visitor.h"
#include "Fwd_Decl_Generator.h"
#include "Impl_Factory_Generator.h"
#include "Init_Generator.h"
#include "Mpc_File_Generator.h"
#include "Mwc_File_Generator.h"
#include "Pch_File_Generator.h"
#include "Visitor_Generator.h"
#include "Top_Level_File_Generator.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"
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

#define INTERPRETER_NAME        "GAME Extension Class Generator"
#define INTERPRETER_PARADIGM    "MetaGME"
#define INTERPRETER_PROGID      "GAME.Interpreter.ExtensionClasses"

//
// Quotas_Integrator_Impl
//
Extension_Classes_Component_Impl::Extension_Classes_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base (INTERPRETER_NAME,
                                    INTERPRETER_PARADIGM,
                                    INTERPRETER_PROGID)
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
    GAME::Mga::Transaction t (project);

    // Load the project settings for next time.
    this->load_project_settings (project);

    if (this->is_interactive_)
    {
      // Get the output directory for the extension classes.
      bool retval = GAME::Utils::get_path ("Select target output directory...",
                                           this->output_,
                                           this->output_);

      if (!retval)
        return 0;
    }

    const std::string pch_basename = "stdafx";
    GAME::Mga::Folder root = project.root_folder ();

    // Visit all element in the model and generate an extension
    // class for each valid model.
    std::set <GAME::Mga::Object> ext_classes;
    GAME::Mga::Extension_Classes_Visitor ecv (this->output_,
                                              root,
                                              pch_basename,
                                              ext_classes);

    if (selected.empty ())
    {
      // Make sure the output directory has been created.
      root->accept (&ecv);

      // Generate workspace, project, and precompiled header files.
      GAME::Mga::Mwc_File_Generator mwc_gen;
      mwc_gen.generate (this->output_, project);

      GAME::Mga::Mpc_File_Generator mpc_gen;
      mpc_gen.generate (this->output_, project, pch_basename, ext_classes);

      GAME::Mga::Pch_File_Generator pch_gen;
      pch_gen.generate (this->output_, project, pch_basename);

      GAME::Mga::Fwd_Decl_Generator fwd_gen;
      fwd_gen.generate (this->output_, project, ext_classes);

      GAME::Mga::Visitor_Generator visitor_gen;
      visitor_gen.generate (this->output_, project, pch_basename, ext_classes);

      GAME::Mga::Init_Generator init_gen;
      init_gen.generate (this->output_, project, pch_basename);

      GAME::Mga::Impl_Factory_Generator impl_factory_gen;
      impl_factory_gen.generate (this->output_, project, pch_basename, ext_classes);

      GAME::Mga::Top_Level_File_Generator top_level_gen;
      top_level_gen.generate (this->output_, project, ext_classes);

      GAME::Mga::Export_File_Generator export_file_gen;
      export_file_gen.generate (this->output_, project);
    }
    else
    {
      std::for_each (selected.begin (),
                     selected.end (),
                     boost::bind (&GAME::Mga::FCO::impl_type::accept,
                                  boost::bind (&GAME::Mga::FCO::get, _1),
                                  &ecv));
    }

    if (this->is_interactive_)
      ::AfxMessageBox ("Successfully generated extension class files.",
                       MB_OK | MB_ICONINFORMATION);

    // Save the project settings for next time.
    this->save_project_settings (project);
    t.commit ();
  }
  catch (const GAME::Mga::Exception & ex)
  {
    if (this->is_interactive_)
      ::AfxMessageBox (ex.message ().c_str (), MB_OK);
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
  GAME::Mga::Project_Settings settings (proj, "GAME/ExtensionClasses");

  if (this->output_.empty ())
    settings.get_string_value ("OutputPath", this->output_);
}

//
// save_project_settings
//
void Extension_Classes_Component_Impl::
save_project_settings (GAME::Mga::Project proj)
{
  GAME::Mga::Project_Settings settings (proj, "GAME/ExtensionClasses");
  settings.set_string_value ("OutputPath", this->output_);
}
