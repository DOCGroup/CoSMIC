// $Id$

#include "StdAfx.h"
#include "Template_Module_Instance_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Template_Module_Instance_Handler.inl"
#endif

#include "Scope_Display_Strategy.h"
#include "game/MetaAspect.h"
#include "game/MetaModel.h"
#include "game/Filter.h"
#include "game/Project.h"
#include "game/Reference.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "game/utils/Point.h"
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
  bool operator () (const GAME::FCO & fco) const
  {
    GAME::Model package = GAME::Model::_narrow (fco);
    std::string path = package.path ("/");

    GAME::Meta::Aspect aspect = package.meta ().aspect ("TemplateParameters");

    std::vector <GAME::FCO> parameters;
    return package.children (aspect, parameters) == 0;
  }
};

//
// handle_object_created
//
int Template_Module_Instance_Handler::handle_object_created (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Locate all the packages in the object's project.
  GAME::Filter filter (obj.project ());
  filter.kind ("Package");

  std::vector <GAME::FCO> packages;

  if (0 == filter.apply (packages))
  {
    ::AfxMessageBox ("Project does not contain any packages.", MB_ICONWARNING);
    return -1;
  }

  // From the selected packages, select the packages that are template
  // packages (i.e., have at least one template parameter in the package).
  std::vector <GAME::FCO>::iterator iter = packages.begin ();
  std::vector <GAME::FCO>::iterator iter_end =
    std::remove_if (iter,
                    packages.end (),
                    is_standard_package ());

  // Determine how many elements are template packages. This is
  // necessary since it will determine if we must bail out, auto
  // select the element, or display a dialog.
  size_t count = std::distance (iter, iter_end);
  GAME::FCO template_package;

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
      Selection_List_Dialog_T <GAME::FCO> dialog (&display, ::AfxGetMainWnd ());

      dialog.insert (iter, iter_end);

      if (dialog.DoModal () == IDCANCEL)
        return 0;

      template_package = dialog.selection ();
    }
  }

  // Create the template package type.
  GAME::Model tpi = GAME::Model::_narrow (obj);
  GAME::Reference ref = GAME::Reference::_create (tpi, "PackageType");
  ref.refers_to (template_package);

  // Set the position of the reference.
  using GAME::utils::Point;
  GAME::utils::position ("TemplateParameters", Point (100, 100), ref);

  return 0;
}

}
}
