#include "StdAfx.h"
#include "DQML_iCCM_Component.h"
#include "DQML_iCCM_Component_Impl.h"
#include "Participant_File.h"

#include "game/mga/utils/Project_Settings.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"

#include <iostream>
//#include "Utils/Utils.h"

GAME_DECLARE_INTERPRETER (DQML_iCCM_Component, DQML_iCCM_Component_Impl);

//
//DQML_iCCM_Component_Impl
//
DQML_iCCM_Component_Impl::DQML_iCCM_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("GAME DQML_iCCM Generator",
                                    "DQML",
                                    "GAME.Interpreter.DQML_iCCM")
{

}

//
//~DQML_iCCM_Component_Impl
//
DQML_iCCM_Component_Impl::~DQML_iCCM_Component_Impl (void)
{

}

//
//invoke ex
//
int DQML_iCCM_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
           long flags)
{
  // Select the target output directory. If no directory is
  // selected, then we need to return control to the client.
  const char * prompt = "Select target output directory for iCCM configurations files:";
  std::string path = project.connstr ();  
  int i = path.find ("=");
  path = path.substr (i + 1 , path.find_last_of ("/\\") - i);
  if ( ! GAME::Utils::get_path (prompt, path, path))
    return 0;

  try
  {
    GAME::Mga::Transaction t_readonly (project, TRANSACTION_READ_ONLY);

    DQML_iCCM::Participant_File_Locator locator (path);
    project.root_folder ()->accept (&locator);

    t_readonly.commit();

    ::AfxMessageBox ("Successfully generated configuration files.", MB_OK);
  }
  catch (const GAME::Mga::Exception & ex)
  {
    ::AfxMessageBox (ex.message ().c_str ());
  }

  return 0;
}

