// $Id$

#include "StdAfx.h"
#include "Template_Module_Instance_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Template_Module_Instance_Handler.inl"
#endif

#include "Scope_Display_Strategy.h"

#include "game/mga/MetaAspect.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Filter.h"
#include "game/mga/Project.h"
#include "game/mga/Reference.h"
#include "game/mga/component/Event_Sink.h"
#include "game/mga/dialogs/Name_Dialog.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include "game/mga/utils/Point.h"

#include "boost/bind.hpp"

#include <algorithm>

namespace PICML
{
namespace MI
{
/**
 * @struct is_standard_package
 *
 * Functor that test if a Package is a standard package. A standard
 * package is one that does not contain any template parameters.
 */
struct is_standard_package
{
  bool operator () (const GAME::Mga::FCO_in fco) const
  {
    GAME::Mga::Model package = GAME::Mga::Model::_narrow (fco);
    std::string path = package->path ("/");

    GAME::Mga::Meta::Aspect aspect = package->meta ()->aspect ("TemplateParameters");

    std::vector <GAME::Mga::FCO> parameters;
    return package->children (aspect, parameters) == 0;
  }
};

static const unsigned long mask = OBJEVENT_CREATED | OBJEVENT_LOSTCHILD;

//
// Template_Module_Instance_Handler
//
Template_Module_Instance_Handler::Template_Module_Instance_Handler (void)
: GAME::Mga::Event_Handler_Impl (mask)
{

}

//
// handle_object_created
//
int Template_Module_Instance_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // First, let's check if there is already a PackageType in this
  // TemplatePackageInstance model element. THere is no need to
  // continue if there is already a PackageType element present!
  GAME::Mga::Model tpi = GAME::Mga::Model::_narrow (obj);
  std::vector <GAME::Mga::Reference> package_types;

  if (0 != tpi->children ("PackageType", package_types))
    return 0;

  // Locate all the packages in the object's project. This is done
  // by creating a filter and applying it to this project.
  GAME::Mga::Filter filter (obj->project ());
  filter.kind ("Package");

  std::vector <GAME::Mga::FCO> packages;
  filter.apply (packages);

  // From the selected packages, select the packages that are template
  // packages (i.e., have at least one template parameter in the package).
  std::vector <GAME::Mga::FCO>::iterator iter = packages.begin ();
  std::vector <GAME::Mga::FCO>::iterator iter_end =
    std::remove_if (iter,
                    packages.end (),
                    is_standard_package ());

  // Determine how many elements are template packages. This is
  // necessary since it will determine if we must bail out, auto
  // select the element, or display a dialog.
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
  size_t count = std::distance (iter, iter_end);
  GAME::Mga::FCO template_package;

  switch (count)
  {
  case 0:
    ::AfxMessageBox ("Project does not contain any template packages.", MB_ICONWARNING);
    return -1;

  case 1:
    template_package = packages.front ();
    break;

  default:
    {
      // Let the user select which template package the want to base
      // the template package instantiation on.
      using GAME::Dialogs::Selection_List_Dialog_T;

      Scope_Display_Strategy display;
      Selection_List_Dialog_T <GAME::Mga::FCO> dialog (&display, ::AfxGetMainWnd ());

      dialog.insert (iter, iter_end);

      if (dialog.DoModal () == IDCANCEL)
        return 0;

      template_package = dialog.selection ();
    }
  }

  // Create the template package type.
  GAME::Mga::Reference ref = GAME::Mga::Reference_Impl::_create (tpi, "PackageType");
  ref->refers_to (template_package);

  // Set the position of the reference.
  GAME::Mga::set_position ("TemplateParameters",
                           GAME::Mga::Point (100, 100),
                           ref);

  return 0;
}

//
// handle_lost_child
//
int Template_Module_Instance_Handler::handle_lost_child (GAME::Mga::Object_in obj)
{
  if (obj->status () != 0)
    return 0;

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
  ::AfxMessageBox ("Must delete parent to delete element.", MB_ICONERROR);

  return -1;
}

}
}
