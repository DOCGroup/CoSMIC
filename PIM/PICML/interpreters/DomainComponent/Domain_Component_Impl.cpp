#include "StdAfx.h"
#include "Domain_Component.h"
#include "Domain_Component_Impl.h"
#include "game/mga/utils/Project_Settings.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"
#include "game/mga/Utils.h"

#include "Domain_Visitor.h"

GAME_DECLARE_INTERPRETER (Domain_Component, Domain_Component_Impl);

//
//Domain_Component_Impl
//
Domain_Component_Impl::Domain_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("PICML Domain Generator",
                                    "PICML",
                                    "PICML.Interpreter.Domain")
{

}

//
//~Domain_Component_Impl
//
Domain_Component_Impl::~Domain_Component_Impl (void)
{

}

//
//invoke ex
//
int Domain_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
           long flags)
{
  std::string output_path;
  if (!GAME::Utils::get_path ("Select an output directory", output_path))
    return 0;

  try
  {
    GAME::Mga::Transaction t (project);

    // Walk the domain, and generate the domain artifacts.
    Domain_Visitor domain_visitor (output_path);
    project.root_folder ()->accept (&domain_visitor);
 
    t.commit ();

    ::AfxMessageBox ("Successfully generated domain descriptor");
  }
  catch (::GAME::Mga::Exception & ex)
  {
    ::AfxMessageBox (ex.message ().c_str ());
  }

  return 0;
}

