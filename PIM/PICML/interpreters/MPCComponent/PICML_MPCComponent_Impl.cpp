#include "StdAfx.h"
#include "PICML_MPCComponent.h"
#include "PICML_MPCComponent_Impl.h"
#include "game/mga/utils/Project_Settings.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"

#include "MPC_Visitor.h"
#include "Utils/Utils.h"

#include <iostream>

#include "game/mga/component/Console_Service.h"
#include <sstream>

GAME_DECLARE_INTERPRETER (PICML_MPCComponent, PICML_MPCComponent_Impl);

//
//PICML_MPCComponent_Impl
//
PICML_MPCComponent_Impl::PICML_MPCComponent_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("GAME PICML_MPC Generator",
                                    "PICML",
                                    "MGA.Interpreter.MPC")
{

}

//
//~PICML_MPCComponent_Impl
//
PICML_MPCComponent_Impl::~PICML_MPCComponent_Impl (void)
{

}

//
//invoke ex
//
int PICML_MPCComponent_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
           long flags)
{
  GAME::Mga::Readonly_Transaction t (project);

	std::string outputPath;
	std::string message = "Please specify the Output Directory";
	if (! Utils::getPath (message, outputPath))
		return -1;

	bool valid_interpretation = 0;

  if (focus || selected.count ())
  {
    PICML::MPC_Visitor visitor (outputPath);

    for (GAME::Mga::FCO target : selected)
    {
      // dfeiock: FIX - Original code put the selected and focus into a set then interated over them.
      //                Now I am doing selected first then the focus.
      //                not sure if the automatic sorting of the set is required
      if (target->meta ()->name () == PICML::MPC::impl_type::metaname)
      {
        target->accept (&visitor);
        valid_interpretation = 1;
      }
    }

    if (focus && (focus->meta ()->name () == PICML::MPC::impl_type::metaname))
    {
      focus->accept (&visitor);
      valid_interpretation = 1;
    }
  }

	if (!valid_interpretation)
	{
		PICML::RootFolder root_folder = project.root_folder ();

		for (PICML::ComponentBuild component : root_folder->get_ComponentBuild ())
		{
			for (PICML::MPC mpc : component->get_MPCs ())
			{
				PICML::MPC_Visitor visitor (outputPath);
        mpc->accept (&visitor);
				valid_interpretation = 1;
			}
		}
	}

	if (valid_interpretation)
		AfxMessageBox ("MPC Files successfully generated");
	else
		AfxMessageBox ("Interpretation Failure: Either there is no MPC paradigm present and/or \n Selected Object(s) are not MPC definitions");

  return 0;
}

