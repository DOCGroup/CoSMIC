// $Id$

#include "StdAfx.h"
#include "Property_Manager.h"
#include "Property_Manager_Impl.h"
#include "Property_Manager_Dialog.h"

#include "game/be/Interpreter_T.h"
#include "game/Transaction.h"

#include "boost/bind.hpp"
#include <algorithm>

GAME_DECLARE_INTERPRETER (Property_Manager_Component, PICML_Property_Mangaer_Impl);

//
// PICML_Property_Mangaer_Impl
//
PICML_Property_Mangaer_Impl::PICML_Property_Mangaer_Impl (void)
: GAME::Interpreter_Impl_Base ("Property Manager", "MGA.Interpreter.PropertyManager", "PICML")
{

}

//
// ~PICML_Property_Mangaer_Impl
//
PICML_Property_Mangaer_Impl::~PICML_Property_Mangaer_Impl (void)
{

}

//
// invoke_ex
//
int PICML_Property_Mangaer_Impl::
invoke_ex (GAME::Project & project,
           GAME::FCO & fco,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  try
  {
    if (!selected.empty ())
    {
      std::for_each (selected.begin (),
                     selected.end (),
                     boost::bind (&PICML_Property_Mangaer_Impl::handle_property,
                                  this,
                                  _1));
    }
    else
    {
      ::AfxMessageBox ("Please select one or more Property elements first.", MB_ICONHAND);
    }

    return 0;
  }
  catch (const GAME::Exception &)
  {

  }

  return -1;
}

//
// handle_property
//
void PICML_Property_Mangaer_Impl::handle_property (GAME::FCO fco)
{
  // Start a new transaction for this property.
  GAME::Transaction t (fco.project ());
  GAME::Model prop = GAME::Model::_narrow (fco);

  PICML_Property_Manager_Dialog dlg (prop, ::AfxGetMainWnd ());

  if (dlg.DoModal () == IDOK)
    t.commit ();
}
