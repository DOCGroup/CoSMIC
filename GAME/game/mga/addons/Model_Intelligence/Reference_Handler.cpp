// $Id$

#include "StdAfx.h"

#include "Reference_Handler.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaReference.h"
#include "game/mga/Atom.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaBase.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

#include "boost/bind.hpp"

//
// Reference_Handler
//
Reference_Handler::Reference_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// ~Reference_Handler
//
Reference_Handler::~Reference_Handler (void)
{

}

//
// handle_object_created
//
int Reference_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // There is no need to continue if the reference is not nil. This can
  // happen if some other addon creates the reference and sets the object
  // it refers to.
  GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (obj);
  GAME::Mga::FCO refers_to = ref->refers_to ();

  if (!refers_to.is_nil ())
    return 0;

  // Finding the metaobjects that ref referes to
  std::vector <GAME::Mga::Meta::FCO> types;
  ref->meta ()->targets (types);

  // Sorting out all the FCOs of metaobject type using a filter
  GAME::Mga::Filter filter (obj->project ());

  std::vector <GAME::Mga::FCO> objs;
  GAME::Mga::FCO select;

  filter.kind (types);
  filter.apply (objs);

  if (1 == objs.size ())
  {
    select = objs.front ();
  }
  else
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    // Create the dialog and pass in the data
    using GAME::Dialogs::Selection_List_Dialog_T;
    Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd ());

    const std::string directions =
      "Please select the target object for the " +
      ref->meta ()->display_name () + " reference object:";

    dlg.title ("Auto Reference Resolver");
    dlg.directions (directions.c_str ());
    dlg.insert (objs);

    if (IDOK != dlg.DoModal ())
      return 0;

    select = dlg.selection ();
  }

  if (!select.is_nil ())
  {
    ref->refers_to (select);
    ref->name (select->name ());
  }

  return 0;
}