// $Id$

#include "StdAfx.h"
#include "VisitPatron_Component.h"
#include "VisitPatron_Component_Impl.h"
#include "game/mga/utils/Project_Settings.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"

#include "Patron_Only_Visitor.h"

GAME_DECLARE_INTERPRETER (VisitPatron_Component, VisitPatron_Component_Impl);

//
//VisitPatron_Component_Impl
//
VisitPatron_Component_Impl::VisitPatron_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("GAME VisitPatron Generator",
                                    "Library",
                                    "GAME.Interpreter.VisitPatron")
{

}

//
//~VisitPatron_Component_Impl
//
VisitPatron_Component_Impl::~VisitPatron_Component_Impl (void)
{

}

//
//invoke ex
//
int VisitPatron_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
  try
  {
    GAME::Mga::Transaction t (project);

    Patron_Only_Visitor v;
    project.root_folder ()->accept (&v);
  }
  catch (const GAME::Mga::Exception & )
  {

  }

  return 0;
}

