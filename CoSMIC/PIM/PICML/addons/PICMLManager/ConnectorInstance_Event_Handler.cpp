// -*- C++ -*-
// $Id$

#include "StdAfx.h"
#include "ConnectorInstance_Event_Handler.h"

#include "game/Filter.h"
#include "game/Project.h"
#include "game/Reference.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "game/dialogs/Dialog_Display_Strategy.h"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;

//
// ConnectorInstance_Event_Handler
//
ConnectorInstance_Event_Handler::ConnectorInstance_Event_Handler (void)
: GAME::Event_Handler_Impl (mask)
{

}

//
// ConnectorInstance_Event_Handler
//
ConnectorInstance_Event_Handler::~ConnectorInstance_Event_Handler (void)
{

}

//
// handle_object_created
//
int ConnectorInstance_Event_Handler::handle_object_created (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  // There is now need to continue if we are an instance. This is
  // because the implementatation is already selected.
  GAME::FCO fco = GAME::FCO::_narrow (obj);
  if (fco.is_instance ())
    return 0;

  // Locate all the monolithic implementations in the project.
  GAME::Filter filter (obj.project ());
  filter.kind ("ConnectorImplementation");

  std::vector <GAME::FCO> results;
  filter.apply (results);

  switch (results.size ())
  {
  case 0:
    return 0;

  case 1:
    fco = results.front ();
    break;

  default:
    {
      using GAME::Atom;
      using GAME::Dialogs::Selection_List_Dialog_T;

      // Display the list to the user so they can select one.
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
      Selection_List_Dialog_T <GAME::FCO> dlg (0, ::AfxGetMainWnd ());

      dlg.title ("Connector Implementation Selector");
      dlg.insert (results);

      if (dlg.DoModal () == IDCANCEL)
        return 0;

      fco = dlg.selection ();
    }
  }

  using GAME::Model;
  using GAME::Reference;

  // Finally, create the component instance's type. Make sure it
  // references the selected FCO, which is a monolithic implementation.
  Model component = Model::_narrow (obj);
  Reference typeref = Reference::_create (component, "ConnectorImplementationType");
  typeref.refers_to (fco);
  typeref.name (fco.name ());

  return 0;
}

}
}
