// -*- C++ -*-
// $Id$

#include "StdAfx.h"
#include "ConnectorInstance_Event_Handler.h"

#include "game/mga/Filter.h"
#include "game/mga/Project.h"
#include "game/mga/Reference.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include "game/mga/dialogs/Dialog_Display_Strategy.h"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;

//
// ConnectorInstance_Event_Handler
//
ConnectorInstance_Event_Handler::ConnectorInstance_Event_Handler (void)
: GAME::Mga::Object_Event_Handler (mask)
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
int ConnectorInstance_Event_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // There is now need to continue if we are an instance. This is
  // because the implementatation is already selected.
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);
  if (fco->is_instance ())
    return 0;

  // Locate all the monolithic implementations in the project.
  GAME::Mga::Filter filter (obj->project ());
  filter.kind ("ConnectorImplementation");

  std::vector <GAME::Mga::FCO> results;
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
      using GAME::Mga::Atom;
      using GAME::Dialogs::Selection_List_Dialog_T;

      // Display the list to the user so they can select one.
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
      Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd ());

      dlg.title ("Connector Implementation Selector");
      dlg.insert (results);

      if (dlg.DoModal () == IDCANCEL)
        return 0;

      fco = dlg.selection ();
    }
  }

  using GAME::Mga::Model;
  using GAME::Mga::Reference;

  // Finally, create the component instance's type. Make sure it
  // references the selected FCO, which is a monolithic implementation.
  Model component = Model::_narrow (obj);
  Reference typeref = Reference::impl_type::_create (component, "ConnectorImplementationType");
  typeref->refers_to (fco);
  typeref->name (fco->name ());

  return 0;
}

}
}
