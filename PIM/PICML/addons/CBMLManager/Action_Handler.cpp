#include "StdAfx.h"
#include "Action_Handler.h"

#include "game/mga/Reference.h"
#include "game/mga/Model.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

//
// CBML_Action_Handler
//
CBML_Action_Handler::CBML_Action_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// ~CBML_Action_Handler
//
CBML_Action_Handler::~CBML_Action_Handler (void)
{

}


//
// handle_object_created
//
int CBML_Action_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::Model component = GAME::Mga::Model::_narrow (obj->parent ());

  // Locate the worker type. This will be used to determine the
  // action type of the abstract action.
  GAME::Mga::Reference worker_type;
  if (!this->get_worker_type (component, worker_type))
    return 0;

  obj->name (worker_type->name ());

  GAME::Mga::FCO fco = worker_type->refers_to ();
  if (fco.is_nil ())
    return 0;

  GAME::Mga::Model worker = GAME::Mga::Model::_narrow (fco);

  std::vector <GAME::Mga::Model> operations;
  if (0 == worker->children ("Operation", operations))
    return 0;

  GAME::Mga::Model operation;

  if (1 == operations.size ())
  {
    operation = operations.front ();
  }
  else
  {
    using GAME::Dialogs::Selection_List_Dialog_T;

    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
    Selection_List_Dialog_T <GAME::Mga::Model> op_dlg (0, ::AfxGetMainWnd ());

    op_dlg.title ("Workload Generation Operations");
    op_dlg.insert (operations);
    op_dlg.directions ("Select the concrete workload generator operation for\r\n"
                       "this action.");

    if (IDOK != op_dlg.DoModal ())
      return 0;

    operation = op_dlg.selection ();
  }

  GAME::Mga::Model action = GAME::Mga::Model::_narrow (obj);
  GAME::Mga::Reference action_type = GAME::Mga::Reference_Impl::_create (action, "ActionType");

  action_type->name (operation->name ());
  action_type->refers_to (operation);

  return 0;
}

//
// get_worker_type
//
bool CBML_Action_Handler::
get_worker_type (const GAME::Mga::Model_in component, GAME::Mga::Reference & worker_type)
{
  // First, select the worker types in the component model.
  std::vector <GAME::Mga::Reference> worker_types;
  if (0 == component->children ("WorkerType", worker_types))
    return 0;

  using GAME::Dialogs::Selection_List_Dialog_T;
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  switch (worker_types.size ())
  {
  case 0:
    return false;

  case 1:
    worker_type = worker_types.front ();
    break;

  default:
    {
      Selection_List_Dialog_T <GAME::Mga::Reference> dlg (0, ::AfxGetMainWnd ());

      dlg.insert (worker_types);
      dlg.title ("Target Workload Generator");
      dlg.directions ("Select target worker generator for the action. If this is an\r\n"
                      "an abstract action, then press the Cancel button.");

      if (IDOK != dlg.DoModal ())
        return false;

      // Set the name of the action to the target workload generator.
      worker_type = dlg.selection ();
    }
  }

  return true;
}
