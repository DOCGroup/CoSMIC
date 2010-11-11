// $Id: Extension_Classes_Component_Impl.cpp 2486 2010-09-08 17:29:09Z hillj $

#include "StdAfx.h"
#include "Extension_Classes_Component.h"
#include "Extension_Classes_Component_Impl.h"

#include "Extension_Classes_Visitor.h"

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

    root.children ("SheetFolder", folders);
    root.children ("ParadigmSheet", paradigm_sheets);

    this->output_.append ("/");
    this->output_.append (project.name ().c_str ());

    mkdir (this->output_.c_str ());

    std::stringstream includes;
    std::stringstream source_files;

    GAME::Extension_Classes_Visitor ecv (this->output_);

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

    std::ofstream out;
    std::string temp;

    this->output_ += "/";
    this->output_ += root.name ();

    temp = this->output_;
    temp += ".mwc";

    out.open (temp.c_str ());

    out << "workspace (" << root.name () << ") {" <<std::endl
        << "  cmdline += -features boost=1,xerces3=1,xsc=1,mfc=1" << std::endl
        << "  cmdline += -include $COSMIC_ROOT/MPC/config" << std::endl << std::endl
        << "  " << root.name () << ".mpc" << std::endl
        << "}";

    out.close ();

    temp = this->output_;
    temp += ".mpc";

    out.open (temp.c_str ());

    out << "project(" << root.name ()
        << "): acelib, cosmic_lib, game_common, game {"
        << std::endl
        << "  sharedname = " << root.name () << std::endl << std::endl
        << "  includes += $(COSMIC_ROOT)/Utils/GAME" << std::endl
        << "  includes += " << ecv.get_includes ().c_str ()
        << std::endl << std::endl
        << "  Source_Files {" << std::endl
        << ecv.get_source_files ().c_str ()
        << "  }" << std::endl
        << "}";

    out.close ();
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
