// $Id$

#include "StdAfx.h"
#include "Action_Handler.h"

#include "game/Reference.h"
#include "game/Model.h"
#include "game/dialogs/Selection_List_Dialog_T.h"

//
// CBML_Action_Handler
//
CBML_Action_Handler::CBML_Action_Handler (void)
: GAME::Event_Handler_Impl (eventmask)
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
int CBML_Action_Handler::handle_object_created (GAME::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Model component = GAME::Model::_narrow (obj->parent ());

  // Locate the worker type. This will be used to determine the
  // action type of the abstract action.
  GAME::Reference worker_type;
  if (!this->get_worker_type (component, worker_type))
    return 0;

  obj->name (worker_type->name ());

  GAME::FCO fco = worker_type->refers_to ();
  if (fco.is_nil ())
    return 0;

  GAME::Model worker = GAME::Model::_narrow (fco);

  std::vector <GAME::Model> operations;
  if (0 == worker->children ("Operation", operations))
    return 0;

  GAME::Model operation;

  if (1 == operations.size ())
  {
    operation = operations.front ();
  }
  else
  {
    using GAME::Dialogs::Selection_List_Dialog_T;

    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
    Selection_List_Dialog_T <GAME::Model> op_dlg (0, ::AfxGetMainWnd ());

    op_dlg.title ("Workload Generation Operations");
    op_dlg.insert (operations);
    op_dlg.directions ("Select the concrete workload generator operation for\r\n"
                       "this action.");

    if (IDOK != op_dlg.DoModal ())
      return 0;

    operation = op_dlg.selection ();
  }

  GAME::Model action = GAME::Model::_narrow (obj);
  GAME::Reference action_type = GAME::Reference_Impl::_create (action, "ActionType");

  action_type->name (operation->name ());
  action_type->refers_to (operation);

  return 0;
}

//
// get_worker_type
//
bool CBML_Action_Handler::
get_worker_type (const GAME::Model_in component, GAME::Reference & worker_type)
{
  // First, select the worker types in the component model.
  std::vector <GAME::Reference> worker_types;
  if (0 == component->children ("WorkerType", worker_types))
    return 0;

  using GAME::Dialogs::Selection_List_Dialog_T;
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  Selection_List_Dialog_T <GAME::Reference> dlg (0, ::AfxGetMainWnd ());

  dlg.insert (worker_types);
  dlg.title ("Target Workload Generator");
  dlg.directions ("Select target worker generator for the action. If this is an\r\n"
                  "an abstract action, then press the Cancel button.");

  if (IDOK != dlg.DoModal ())
    return false;

  // Set the name of the action to the target workload generator.
  worker_type = dlg.selection ();
  return true;
}
