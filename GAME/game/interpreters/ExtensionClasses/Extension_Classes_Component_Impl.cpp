// $Id: Extension_Classes_Component_Impl.cpp 2486 2010-09-08 17:29:09Z hillj $

#include "StdAfx.h"
#include "Extension_Classes_Component.h"
#include "Extension_Classes_Component_Impl.h"

#include "Extension_Classes_Visitor.h"
#include "Extension_Classes_Build_Files_Generator.h"

#include "game/be/Interpreter_T.h"

#include "game/utils/Project_Settings.h"
#include "Utils/Utils.h"

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
invoke_ex (GAME::Project & project,
           GAME::FCO & focus,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  GAME::Transaction t (project, TRANSACTION_READ_ONLY);

  if (!::Utils::getPath ("Select target output directory...", this->output_))
        return 0;

  try
  {
    std::vector <GAME::Folder> folders;
    std::vector <GAME::Model> paradigm_sheets;

    GAME::Folder root = project.root_folder ();

    std::string uc_paradigm_name = root.name ();

    std::transform (uc_paradigm_name.begin (), uc_paradigm_name.end (),
                    uc_paradigm_name.begin (), ::toupper);

    root.children ("SheetFolder", folders);
    root.children ("ParadigmSheet", paradigm_sheets);

    this->output_.append ("\\");
    this->output_.append (project.name ().c_str ());

    mkdir (this->output_.c_str ());

    std::stringstream includes;
    std::stringstream source_files;

    GAME::Extension_Classes_Visitor ecv (this->output_,
                                         uc_paradigm_name);

    // visit all the folders
    std::for_each (folders.begin (),
                   folders.end (),
                   boost::bind (&GAME::Folder::accept,
                                _1,
                                boost::ref (ecv)));

    // visit all the paradigm sheets
    std::for_each (paradigm_sheets.begin (),
                   paradigm_sheets.end (),
                   boost::bind (&GAME::Model::accept,
                                _1,
                                boost::ref (ecv)));

    std::set <GAME::Object> objects;
    ecv.get_objects (objects);

    GAME::Extension_Classes_Build_Files_Generator generator
                                        (root,
                                         objects,
                                         this->output_,
                                         root.name (),
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
