// -*- C++ -*-
// $Id$

#include "StdAfx.h"
#include "ComponentInstance_Event_Handler.h"

#include "game/Filter.h"
#include "game/Project.h"
#include "game/Reference.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "game/dialogs/Dialog_Display_Strategy.h"
#include "game/modelgen.h"
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
: GAME::Event_Handler_Impl (mask)
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
int ComponentInstance_Event_Handler::handle_object_created (GAME::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // There is now need to continue if we are an instance. This is
  // because the implementatation is already selected.
  GAME::Model component = GAME::Model::_narrow (obj);
  if (component->is_instance ())
    return 0;

  // GAME::create_if_not <Mga_t> (component, "type", type_info, GAME::count (...));
  std::vector <GAME::Reference> typeinfo_set;
  GAME::Reference typeinfo;

  if (0 != component->children ("ComponentInstanceType", typeinfo_set))
  {
    typeinfo = typeinfo_set.front ();

    if (!typeinfo.is_nil () && !typeinfo->refers_to ().is_nil ())
      return 0;
  }
  else
  {
    typeinfo = GAME::Reference_Impl::_create (component, "ComponentInstanceType");
  }

  // Locate all the monolithic implementations in the project.
  GAME::Filter filter (obj->project ());
  filter.kind ("MonolithicImplementation");

  GAME::FCO fco;
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

      dlg.title ("Component Implementation Selector");
      dlg.insert (results);

      if (dlg.DoModal () != IDOK)
        return 0;

      fco = dlg.selection ();
    }
  }

  using GAME::Model;
  using GAME::Reference;

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
handle_lost_child (GAME::Object_in obj)
{
  GAME::FCO fco = GAME::FCO::_narrow (obj);

  if (this->is_importing_ || fco->is_instance ())
    return 0;

  static const std::string meta_ComponentInstanceType ("ComponentInstanceType");
  GAME::Model model = GAME::Model::_narrow (obj);

  std::vector <GAME::Reference> types;

  if (model->children (meta_ComponentInstanceType, types) == 0 ||
      types.front ().is_nil ())
  {
    // Delete all the children in the inferface.
    std::vector <GAME::FCO> children;
    GAME::Meta::Aspect aspect = model->meta ()->aspect ("ComponentInterface");

    model->children (aspect, children);
    std::for_each (children.begin (),
                   children.end (),
                   boost::bind (&GAME::FCO::impl_type::destroy,
                                boost::bind (&GAME::FCO::get, _1)));

    return 0;
  }
  else
    return -1;

  return 0;
}

}
}
