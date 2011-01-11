// $Id: Extension_Classes_Component_Impl.cpp 2486 2010-09-08 17:29:09Z alhad $

#include "StdAfx.h"
#include "Extension_Classes_Component.h"
#include "Extension_Classes_Component_Impl.h"

#include "Extension_Classes_Visitor.h"
#include "Extension_Classes_Build_Files_Generator.h"

#include "game/be/Interpreter_T.h"

#include "game/utils/Project_Settings.h"
#include "game/Utils.h"

#include "Transaction.h"

#include "game/Atom.h"
#include "game/Model.h"

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
: GAME::Interpreter_Impl_Base ("GAME Extension Class Generator",
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
invoke_ex (GAME::Project project,
           GAME::FCO_in focus,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  GAME::Transaction t (project, TRANSACTION_READ_ONLY);

  if (!::GAME::Utils::get_path ("Select target output directory...", this->output_))
        return 0;

  try
  {
    std::vector <GAME::Folder> folders;
    std::vector <GAME::Model> paradigm_sheets;

    GAME::Folder root = project.root_folder ();

    std::string uc_paradigm_name = root->name ();

    ::GAME::Utils::normalize (uc_paradigm_name);

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
    GAME::Extension_Classes_Visitor ecv (this->output_, uc_paradigm_name);

    // visit all the folders
    std::for_each (folders.begin (),
                   folders.end (),
                   boost::bind (&GAME::Folder::impl_type::accept,
                                boost::bind (&GAME::Folder::get, _1),
                                &ecv));

    // visit all the paradigm sheets
    std::for_each (paradigm_sheets.begin (),
                   paradigm_sheets.end (),
                   boost::bind (&GAME::Model::impl_type::accept,
                                boost::bind (&GAME::Model::get, _1),
                                &ecv));

    // get all the objects in the model needed for processing mpc/mwc
    const std::set <GAME::Object> & objects = ecv.get_objects ();
    GAME::Extension_Classes_Build_Files_Generator generator (root.get (),
                                                             objects,
                                                             output,
                                                             root->name (),
                                                             uc_paradigm_name);

    // generate the mwc, mpc and stdafx files
    generator.generate_mwc_file ();
    generator.generate_mpc_file ();
    generator.generate_stdafx_files ();
  }
  catch (...)
  {
    ::AfxMessageBox ("Exception Caught", MB_OK);
    return -1;
  }

  t.commit ();
  ::AfxMessageBox ("Files generated successfully", MB_OK);

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
