// $Id$

#include "StdAfx.h"
#include "Property_Manager.h"
#include "Property_Manager_Impl.h"
#include "Property_Manager_Dialog.h"

#include "game/mga/component/Interpreter_T.h"
#include "game/mga/Transaction.h"
#include "game/mga/Reference.h"
#include "game/mga/Visitor.h"

#include "boost/bind.hpp"
#include <algorithm>

GAME_DECLARE_INTERPRETER (Property_Manager_Component, PICML_Property_Mangaer_Impl);

/**
 * @class Property_Handler
 */
class Property_Handler : public GAME::Mga::Visitor
{
public:
  Property_Handler (GAME::Mga::Transaction & transaction)
  : transaction_ (transaction)
  {

  }

  virtual void visit_Reference (GAME::Mga::Reference_in ref)
  {
    // Make sure property manager is not used on predefined types.
    GAME::Mga::FCO simple_type = ref->refers_to ();

    if (simple_type->meta ()->name () == "Enum")
    {
      // Show the dialog to the user.
      PICML_Property_Manager_Dialog dlg (ref, ::AfxGetMainWnd ());
      if (dlg.DoModal () == IDOK)
        this->transaction_.commit ();
    }
    else
      ::AfxMessageBox ("Property manager cannot be used on predefined types.", MB_ICONERROR);
  }

  virtual void visit_Model (GAME::Mga::Model_in model)
  {
    // Show the dialog to the user.
    PICML_Property_Manager_Dialog dlg (model, ::AfxGetMainWnd ());
    if (dlg.DoModal () == IDOK)
      this->transaction_.commit ();
  }

private:
  GAME::Mga::Transaction & transaction_;
};

//
// PICML_Property_Mangaer_Impl
//
PICML_Property_Mangaer_Impl::PICML_Property_Mangaer_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("Property Manager",
                                    "MGA.Interpreter.PropertyManager",
                                    "PICML")
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
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in fco,
           GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
           long flags)
{
  try
  {
    GAME::Mga::Transaction t (project);

    if (selected.count ())
    {
      Property_Handler handler (t);

      for (auto item : selected)
        item->accept (&handler);
    }
    else
      ::AfxMessageBox ("Please select one or more Property elements first.", MB_ICONHAND);

    return 0;
  }
  catch (const GAME::Mga::Exception &)
  {

  }

  return -1;
}
