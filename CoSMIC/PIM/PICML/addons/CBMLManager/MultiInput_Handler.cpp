// $Id: generate_cpp_class.py 3685 2012-09-26 14:45:04Z dfeiock $

#include "StdAfx.h"
#include "MultiInput_Handler.h"

#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/FCO.h"
#include "game/mga/Connection.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

#if !defined (__GAME_INLINE__)
#include "MultiInput_Handler.inl"
#endif  // !defined __GAME_INLINE__

//
// handle_object_created
//
int CBML_MultiInput_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  const std::string no_op_message = "A MultiInputAction has already been created for all facet operations.";

  GAME::Mga::Connection connection = GAME::Mga::Connection::_narrow (obj);
  GAME::Mga::Reference facet = GAME::Mga::Reference::_narrow (connection->src ());
  GAME::Mga::FCO input_action = connection->dst ();
  GAME::Mga::Model object = GAME::Mga::Model::_narrow (facet->refers_to ());

  // Collect the operations on the Object
  std::vector <GAME::Mga::Object> operations;
  this->get_operations (object, operations);

  // Get all the other MultiInputActions connected to the facet
  std::vector <GAME::Mga::Object> existing_actions;
  this->get_actions (facet, existing_actions);

  // Remove existing actions from the operations
  std::vector <GAME::Mga::Object> targets;
  this->narrow_targets (operations, existing_actions, targets);

  // The name to use for the MultiInputAction
  std::string name;

  if (targets.size () == 0)
  {
    ::AfxMessageBox (no_op_message.c_str (), MB_ICONINFORMATION | MB_OK);
    return 0;
  }
  else if (targets.size () == 1)
    name = targets.front ()->name ();
  else
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    using GAME::Dialogs::Selection_List_Dialog_T;
    Selection_List_Dialog_T <GAME::Mga::Object> dlg (0, ::AfxGetMainWnd ());

    dlg.title ("Target Operation");
    dlg.directions ("Select the target Operation for the MultiInputAction");
    dlg.insert (targets);

    if (IDOK != dlg.DoModal ())
      return 0;

    name = dlg.selection ()->name ();
  }

  if (!name.empty())
    input_action->name (name);

  return 0;
}

//
// get_operations
//
void CBML_MultiInput_Handler::
get_operations (GAME::Mga::Model_in object, std::vector<GAME::Mga::Object> & ops)
{
  // Collect the operations on the Object
  std::vector <GAME::Mga::Object> temp;

  // Children call drops state of the vector, so using temp variable
  object->children("OnewayOperation", temp);
  std::copy (temp.begin (), temp.end (), std::back_inserter (ops));
  object->children("TwowayOperation", temp);
  std::copy (temp.begin (), temp.end (), std::back_inserter (ops));
}

//
// get_actions
//
void CBML_MultiInput_Handler::
get_actions (GAME::Mga::FCO_in facet, std::vector<GAME::Mga::Object> & actions)
{
  // Get all the MultiInput connections
  std::vector <GAME::Mga::Connection> facet_connections;
  size_t connections = facet->in_connections ("MultiInput", facet_connections);
  std::vector <GAME::Mga::Connection>::iterator iter = facet_connections.begin (),
                                                end = facet_connections.end ();

  // Get each MultiInputAction
  for (; iter != end; ++iter)
  {
    actions.push_back ((*iter)->dst ());
  }
}

//
// narrow_targets
//
void CBML_MultiInput_Handler::
narrow_targets(const std::vector<GAME::Mga::Object> & ops,
               const std::vector<GAME::Mga::Object> & actions,
               std::vector<GAME::Mga::Object> & targets)
{
  std::vector<GAME::Mga::Object>::const_iterator iter = ops.begin (),
                                                 end = ops.end (),
                                                 actions_end = actions.end ();

  for (; iter != end; ++iter)
  {
    std::vector<GAME::Mga::Object>::const_iterator actions_iter = actions.begin ();
    bool add = true;

    for (; actions_iter != actions_end; ++actions_iter)
    {
      if ((*actions_iter)->name () == (*iter)->name ())
      {
        add = false;
        break;
      }
    }

    if (add)
      targets.push_back (*iter);
  }
}