// -*- C++ -*-
// $Id$

#include "StdAfx.h"
#include "ComponentInstance_Creator_Event_Handler.h"
#include "Component_Observer_Event_Handler.h"

#include "game/mga/Object_Filter.h"
#include "game/mga/Project.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaModel.h"
#include "game/mga/component/Event_Sink.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include "game/mga/dialogs/Dialog_Display_Strategy.h"
#include "game/mga/modelgen.h"

#include "PICML/PICML.h"

#include <functional>

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED |
                                  OBJEVENT_LOSTCHILD;

//
// ComponentInstance_Creator_Event_Handler
//
ComponentInstance_Creator_Event_Handler::
ComponentInstance_Creator_Event_Handler (Component_Observer_Event_Handler * observer)
: GAME::Mga::Object_Event_Handler (mask),
  observer_ (observer)
{

}

//
// ComponentInstance_Creator_Event_Handler
//
ComponentInstance_Creator_Event_Handler::~ComponentInstance_Creator_Event_Handler (void)
{

}

//
// handle_object_created
//
int ComponentInstance_Creator_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // There is now need to continue if we are an instance. This is
  // because the implementatation is already selected.
  ComponentInstance inst = ComponentInstance::_narrow (obj);

  if (inst->is_instance ())
    return 0;

  ComponentInstanceType inst_type;

  try
  {
    inst_type = inst->get_ComponentInstanceType ();

    if (!inst_type->refers_to ().is_nil ())
      return 0;
  }
  catch (const GAME::Mga::Exception &)
  {
    inst_type = ComponentInstanceType_Impl::_create (inst);
  }

  // Locate all the monolithic implementations in the project.
  using GAME::Mga::Filter;
  using GAME::Mga::Iterator;

  Filter filter (obj->project ());
  filter.kind (MonolithicImplementation_Impl::metaname);
  Iterator <MonolithicImplementation> results = filter.apply <MonolithicImplementation> ();

  MonolithicImplementation impl;

  switch (results.count ())
  {
  case 0:
    ::AfxMessageBox ("Please add at least one monolithic implementation to your project.");
    return -1;

  case 1:
    impl = *results;
    break;

  default:
    {
      using GAME::Mga::Atom;
      using GAME::Dialogs::Selection_List_Dialog_T;

      // Display the list to the user so they can select one.
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
      Selection_List_Dialog_T <MonolithicImplementation> dlg (0, ::AfxGetMainWnd ());

      dlg.title ("Component Implementation Selector");
      dlg.insert (GAME::Mga::make_impl_iter (results),
                  GAME::Mga::make_impl_iter (results.make_end ()));

      if (dlg.DoModal () != IDOK)
        return 0;

      impl = dlg.selection ();
    }
  }

  using GAME::Mga::Model;
  using GAME::Mga::Reference;

  // Finally, create the component instance's type. Make sure it
  // references the selected FCO, which is a monolithic implementation.
  inst_type->refers_to (impl);
  inst_type->name (impl->name ());

  // Create a component instance handler that will manage the
  // state of this model element. The instance handler will need
  // the Component model that is being observed.
  std::vector <PICML::Implements> implements;

  if (1 == impl->src_Implements (implements))
  {
    PICML::ComponentRef c_ref = implements.front ()->dst_ComponentRef ();

    if (!c_ref.is_nil ())
    {
      // Register an observer for this component that will make updates
      // to this component instance each time there is a change to the
      // component interface.
      PICML::Component comp = c_ref->get_Component ();
      this->observer_->insert (comp, inst);
    }
  }



  return 0;
}

//
// handle_lost_child
//
int ComponentInstance_Creator_Event_Handler::handle_lost_child (GAME::Mga::Object_in obj)
{
  return 0;
}

}
}
