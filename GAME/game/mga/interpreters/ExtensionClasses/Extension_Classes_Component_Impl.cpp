// $Id: Extension_Classes_Component_Impl.cpp 2486 2010-09-08 17:29:09Z alhad $

#include "StdAfx.h"
#include "Extension_Classes_Component.h"
#include "Extension_Classes_Component_Impl.h"

#include "Extension_Classes_Visitor.h"
#include "Extension_Classes_Build_Files_Generator.h"

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
  GAME::Mga::Transaction t_readonly (project, TRANSACTION_READ_ONLY);

  if (!::GAME::Utils::get_path ("Select target output directory...", this->output_))
        return 0;

  try
  {
    std::vector <GAME::Mga::Folder> folders;
    std::vector <GAME::Mga::Model> paradigm_sheets;

    GAME::Mga::Folder root = project.root_folder ();

    std::string uc_paradigm_name = root->name ();

    GAME::Utils::normalize (uc_paradigm_name);

    // transform the name of paradigm sheet to upper case.
    std::transform (uc_paradigm_name.begin (),
                    uc_paradigm_name.end (),
                    uc_paradigm_name.begin (),
                    & ::toupper);

    // collect all the folders and paradigm sheets within
    // the root folder.
    root->children ("SheetFolder", folders);
    root->children ("ParadigmSheet", paradigm_sheets);

    // set the full path for output directory
    std::string output = this->output_;
    output += ("\\");
    output += project.name ().c_str ();

    GAME::Utils::create_path (output);

    // visitor to traverse the model
    GAME::Mga::Extension_Classes_Visitor ecv (this->output_, uc_paradigm_name);

    // visit all the folders
    std::for_each (folders.begin (),
                   folders.end (),
                   boost::bind (&GAME::Mga::Folder::impl_type::accept,
                                boost::bind (&GAME::Mga::Folder::get, _1),
                                &ecv));

    // visit all the paradigm sheets
    std::for_each (paradigm_sheets.begin (),
                   paradigm_sheets.end (),
                   boost::bind (&GAME::Mga::Model::impl_type::accept,
                                boost::bind (&GAME::Mga::Model::get, _1),
                                &ecv));

    // get all the objects in the model needed for processing mpc/mwc
    using GAME::Mga::Extension_Classes_Build_Files_Generator;
    Extension_Classes_Build_Files_Generator generator (root.get (),
                                                       ecv.get_objects (),
                                                       output,
                                                       root->name (),
                                                       uc_paradigm_name);

    // generate the mwc, mpc and stdafx files
    generator.generate_mwc_file ();
    generator.generate_mpc_file ();
    generator.generate_stdafx_files ();

    if (this->is_interactive_)
      ::AfxMessageBox ("Files generated successfully", MB_OK);
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
