// -*- C++ -*-
// $Id$

#include "StdAfx.h"
#include "ComponentInstance_Event_Handler.h"

#include "game/mga/Filter.h"
#include "game/mga/Project.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaModel.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include "game/mga/dialogs/Dialog_Display_Strategy.h"
#include "game/mga/modelgen.h"
#include <functional>

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED |
                                  OBJEVENT_LOSTCHILD;

//
// ComponentInstance_Event_Handler
//
ComponentInstance_Event_Handler::ComponentInstance_Event_Handler (void)
: GAME::Mga::Event_Handler_Impl (mask)
{

}

//
// ComponentInstance_Event_Handler
//
ComponentInstance_Event_Handler::~ComponentInstance_Event_Handler (void)
{

}

//
// handle_object_created
//
int ComponentInstance_Event_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // There is now need to continue if we are an instance. This is
  // because the implementatation is already selected.
  GAME::Mga::Model component = GAME::Mga::Model::_narrow (obj);
  if (component->is_instance ())
    return 0;

  // GAME::create_if_not <Mga_t> (component, "type", type_info, GAME::count (...));
  std::vector <GAME::Mga::Reference> typeinfo_set;
  GAME::Mga::Reference typeinfo;

  if (0 != component->children ("ComponentInstanceType", typeinfo_set))
  {
    typeinfo = typeinfo_set.front ();

    if (!typeinfo.is_nil () && !typeinfo->refers_to ().is_nil ())
      return 0;
  }
  else
  {
    typeinfo = GAME::Mga::Reference_Impl::_create (component, "ComponentInstanceType");
  }

  // Locate all the monolithic implementations in the project.
  GAME::Mga::Filter filter (obj->project ());
  filter.kind ("MonolithicImplementation");

  GAME::Mga::FCO fco;
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

      dlg.title ("Component Implementation Selector");
      dlg.insert (results);

      if (dlg.DoModal () != IDOK)
        return 0;

      fco = dlg.selection ();
    }
  }

  using GAME::Mga::Model;
  using GAME::Mga::Reference;

  // Finally, create the component instance's type. Make sure it
  // references the selected FCO, which is a monolithic implementation.
  typeinfo->refers_to (fco);
  typeinfo->name (fco->name ());

  return 0;
}

//
// handle_lost_child
//
int ComponentInstance_Event_Handler::
handle_lost_child (GAME::Mga::Object_in obj)
{
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);

  if (this->is_importing_ || fco->is_instance ())
    return 0;

  static const std::string meta_ComponentInstanceType ("ComponentInstanceType");
  GAME::Mga::Model model = GAME::Mga::Model::_narrow (obj);

  std::vector <GAME::Mga::Reference> types;

  if (model->children (meta_ComponentInstanceType, types) == 0 ||
      types.front ().is_nil ())
  {
    // Delete all the children in the inferface.
    std::vector <GAME::Mga::FCO> children;
    GAME::Mga::Meta::Aspect aspect = model->meta ()->aspect ("ComponentInterface");

    model->children (aspect, children);
    std::for_each (children.begin (),
                   children.end (),
                   boost::bind (&GAME::Mga::FCO::impl_type::destroy,
                                boost::bind (&GAME::Mga::FCO::get, _1)));

    return 0;
  }
  else
    return -1;

  return 0;
}

}
}
