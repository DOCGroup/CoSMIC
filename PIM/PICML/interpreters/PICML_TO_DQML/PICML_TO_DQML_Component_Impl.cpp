#include "StdAfx.h"
#include "PICML_TO_DQML_Component.h"
#include "PICML_TO_DQML_Component_Impl.h"
#include "game/mga/utils/Project_Settings.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"
#include "game/mga/Mga.h"

#include <iostream>

#include "DQML_Model_Factory.h"
#include "PICML_Model_Visitor.h"

GAME_DECLARE_INTERPRETER (PICML_TO_DQML_Component, PICML_TO_DQML_Component_Impl);

//
//PICML_TO_DQML_Component_Impl
//
PICML_TO_DQML_Component_Impl::PICML_TO_DQML_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("GAME PICML_TO_DQML Generator",
                                    "PICML",
                                    "GAME.Interpreter.PICML_TO_DQML")
{

}

//
//~PICML_TO_DQML_Component_Impl
//
PICML_TO_DQML_Component_Impl::~PICML_TO_DQML_Component_Impl (void)
{

}

//
//invoke ex
//
int PICML_TO_DQML_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
           long flags)
{

  // Select the target output directory. If no directory is
  // selected, then we need to return control to the client.
  const char * prompt = "Select target output directory for DQML file:";
  std::string path = project.connstr ();
  int i = path.find ("=");
  path = path.substr (i + 1 , path.find_last_of ("/\\") - i);
  if ( ! GAME::Utils::get_path (prompt, path, path))
    return 0;

  try
  {
    GAME::Mga::Transaction t_readonly (project, TRANSACTION_READ_ONLY);

    path = "MGA=" + path + "\\" + project.name () + "_DQML.mga";

    PICML_To_DQML::DQML_Model_Factory DQML_mf (path);
    PICML_To_DQML::PICML_Model_Visitor PICML_mv (DQML_mf);

    project.root_folder ()->accept (&PICML_mv);

    DQML_mf.save_And_Close ();
 
    t_readonly.commit();
    ::AfxMessageBox ("Successfully generated DQML Model file.", MB_OK);
  }
  catch (const GAME::Mga::Exception & ex)
  {
    ::AfxMessageBox (ex.message ().c_str ());
  }

  return 0;
}

