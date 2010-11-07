// $Id$

#include "StdAfx.h"
#include "Output_Action_Handler.h"

#include "game/Model.h"
#include "game/Reference.h"
#include "game/dialogs/Selection_List_Dialog_T.h"

//
// CBML_Output_Action_Handler
//
CBML_Output_Action_Handler::CBML_Output_Action_Handler (void)
: GAME::Event_Handler_Impl (eventmask)
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
int CBML_Output_Action_Handler::handle_object_created (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  // Locate the event sources for this component.
  GAME::Model component = GAME::Model::_narrow (obj.parent ());

  std::vector <GAME::Reference> sources;
  if (0 == component.children ("OutEventPort", sources))
    return 0;

  GAME::Reference source;

  if (1 == sources.size ())
  {
    source = sources.front ();
  }
  else
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    using GAME::Dialogs::Selection_List_Dialog_T;
    Selection_List_Dialog_T <GAME::Reference> dlg (0, ::AfxGetMainWnd ());

    dlg.title ("Target OutEventPort");
    dlg.directions ("Select the target OutEventPort for the OutputAction");
    dlg.insert (sources);

    if (IDOK != dlg.DoModal ())
      return 0;

    source = dlg.selection ();
  }

  if (!source.is_nil ())
    obj.name (source.name ());

  return 0;
}
