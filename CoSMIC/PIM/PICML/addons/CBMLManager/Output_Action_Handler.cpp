// $Id$

#include "StdAfx.h"
#include "Output_Action_Handler.h"

#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

//
// CBML_Output_Action_Handler
//
CBML_Output_Action_Handler::CBML_Output_Action_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// CBML_Output_Action_Handler
//
CBML_Output_Action_Handler::~CBML_Output_Action_Handler (void)
{

}

//
// handle_object_created
//
int CBML_Output_Action_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // Locate the event sources for this component.
  GAME::Mga::Model component = GAME::Mga::Model::_narrow (obj->parent ());

  std::vector <GAME::Mga::Reference> sources;
  if (0 == component->children ("OutEventPort", sources))
    return 0;

  GAME::Mga::Reference source;

  if (1 == sources.size ())
  {
    source = sources.front ();
  }
  else
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    using GAME::Dialogs::Selection_List_Dialog_T;
    Selection_List_Dialog_T <GAME::Mga::Reference> dlg (0, ::AfxGetMainWnd ());

    dlg.title ("Target OutEventPort");
    dlg.directions ("Select the target OutEventPort for the OutputAction");
    dlg.insert (sources);

    if (IDOK != dlg.DoModal ())
      return 0;

    source = dlg.selection ();
  }

  if (!source.is_nil ())
    obj->name (source->name ());

  return 0;
}
